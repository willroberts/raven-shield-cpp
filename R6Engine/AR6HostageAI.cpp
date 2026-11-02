#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004cde8 : AR6HostageAIVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6HostageAI::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6HostageAIVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100556ea : nativeTextR6HostageAI
extern const ushort nativeTextR6HostageAI[12];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void HostageAIBaseArrayExceptionHandler(void);
__declspec(naked) void HostageAIBaseArrayState0Cleanup(void);
__declspec(naked) void HostageAIBaseArrayState1Cleanup(void);

// R6Engine.dll data @ 10057fd8 : hostageAIBaseArrayUnwind
// State1 destroys the array then transitions to state0 base cleanup; state0 then terminates at-1.
const NativeUnwindEntry hostageAIBaseArrayUnwind[2] = {
    { -1, ((uint)&HostageAIBaseArrayState0Cleanup) },
    { 0, ((uint)&HostageAIBaseArrayState1Cleanup) }
};

// R6Engine.dll data @ 10057fe8 : hostageAIBaseArrayInfo
// Exact destructor metadata, two cleanup states and no typed/context catches.
const NativeFunctionInfoPrefix hostageAIBaseArrayInfo = { 0x19930520, 0x2, ((uint)&hostageAIBaseArrayUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10081c5c : autoclassAR6HostageAI
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6HostageAI = nullptr;

// R6Engine.dll @ 100083b0 : AR6HostageAI::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6HostageAI::StaticClass(void)
{
    return &AR6HostageAI::PrivateStaticClass; // Selected object at0x1007ca98.
}

// R6Engine.dll @ 100083c0 : AR6HostageAI::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6HostageAI::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    uint flagsWord = reinterpret_cast<uint&>(objectFlags);
    FName capturedName = objectName;
    struct AllocatePacketView { // Inferred eight-word outgoing packet at entryESP-0x20.
        UClass* classObject;
        UObject* outer;
        FName objectName;
        uint objectFlags;
        UObject* templateObject;
        FOutputDevice* error;
        UObject* extraObject;
        int finalZero;
    } packet;
    packet.finalZero = 0;
    packet.extraObject = nullptr;
    packet.error = (FOutputDevice*)error;
    UObject* capturedOuter = outer; // Read after the first three outgoing words have been placed.
    packet.templateObject = nullptr;
    packet.objectFlags = flagsWord;
    packet.objectName = capturedName;
    packet.outer = capturedOuter;
    packet.classObject = &AR6HostageAI::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000f5f0 : AR6HostageAI::operator=
// Assigns base, packed flags, cover-node storage and raw threat/order/sound records in native order.
AR6HostageAI& __thiscall AR6HostageAI::operator=(const AR6HostageAI& sourceObject)
{
    const AR6HostageAI* source = &sourceObject;
    const AR6HostageAI* capturedSource = source;
    const AR6HostageAI* baseSourceArgument = capturedSource; // Inferred outgoing word at entryESP-0x14.
    this->AR6AIController::operator=(*baseSourceArgument);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)capturedSource;
    // Native leaves padding bytes56d..56f untouched.
    reinterpret_cast<byte&>(this->m_eTransitionPosition) = input[0x56c];
    for (uint offset = 0x570; offset < 0x5bc; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint word = *(const uint*)(input + 0x5bc);
    uint firstFlags = *(uint*)(destination + 0x5c4);
    reinterpret_cast<uint&>(this->m_iDbgRoll) = word;
    reinterpret_cast<uint&>(this->m_iRandomNumber) = *(const uint*)(input + 0x5c0);
    uint difference = firstFlags ^ *(const uint*)(input + 0x5c4);
    uint flags = *(uint*)(destination + 0x5c4) ^ (difference & 1U);
    *(uint*)(destination + 0x5c4) = flags;
    for (uint mask = 2; mask <= 0x2000; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x5c4);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x5c4) = flags; // Fourteen separate publications; retain higher eighteen bits.
    }
    for (uint offset = 0x5c8; offset < 0x610; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    const FArray* arraySourceArgument = (const FArray*)(input + 0x610); // Reuses entryESP-0x14 after the store.
    AssignRecords4((FArray*)(destination + 0x610), arraySourceArgument);
    for (uint offset = 0x61c; offset < 0x628; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    auto moveWords = [](byte* outputWords, const byte* inputWords, uint countWords) {
        __asm { // Inline view of native REP MOVSD groups; preserves the actual incoming direction flag.
            push esi
            push edi
            mov esi,inputWords
            mov edi,outputWords
            mov ecx,countWords
            rep movsd
            pop edi
            pop esi
        }
    };
    moveWords(destination + 0x628, input + 0x628, 9); // m_threatInfo raw36 bytes.
    for (uint offset = 0x64c; offset < 0x658; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    for (uint offset = 0x658; offset < 0x680; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset); // Assignment uses unrolled forward words here.
    for (uint offset = 0x680; offset < 0x6c8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    for (uint offset = 0x6c8; offset < 0x728; offset += 8) {
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
        *(uint*)(destination + offset + 4) = *(const uint*)(input + offset + 4);
    }
    return *this; // Native has no self-assignment shortcut or local cleanup guard.
}

// R6Engine.dll @ 100118b0 : AR6HostageAI::~AR6HostageAI
// Conditionally destroys UObject state, releases the cover-node array, then destroys the AI-controller base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6HostageAI::~AR6HostageAI(AR6HostageAI* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not additional class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&HostageAIBaseArrayExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6HostageAIVirtualTable);
    guard[3] = 1; // Unwind covers array first, then base.
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0; // Native byte store disables only the array cleanup before normal array destruction.
    DestroyWordArrayStorage(reinterpret_cast<FArray*>(&this->m_pListOfCoverNodes));
    guard[3] = 0xffffffff;
    this->AR6AIController::~AR6AIController();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10011910 : AR6HostageAI::AR6HostageAI (native default-constructor view)
// Constructs the imported AI base and installs the derived vtable; derived storage is left untouched.
// The emitted call targets AAIController; the intermediate C++ initializer structure remains unresolved.
AR6HostageAI* __thiscall AR6HostageAI::AR6HostageAI(AR6HostageAI* this)
{
    using BaseConstructor = AAIController* (__thiscall*)(AAIController*);
    reinterpret_cast<BaseConstructor&>(AAIControllerDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6HostageAIVirtualTable);
    return this;
}

// R6Engine.dll @ 10011930 : AR6HostageAI::AR6HostageAI (native copy-constructor view)
// Copy-constructs the base and cover-node array while retaining exact raw copies and delayed base-cleanup activation.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6HostageAI* __thiscall AR6HostageAI::AR6HostageAI(AR6HostageAI* this, const AR6HostageAI* source)
{
    uint guard[4]; // Exact shared5800c compiler guard; same saved-this stack view as RainbowAI.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&AiControllerBaseExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const AR6HostageAI* capturedSource = source;
    const AR6HostageAI* baseSourceArgument = capturedSource; // Inferred outgoing word at entryESP-0x24.
    guard[0] = (uint)this; // Native repeats saved-this placement after the outgoing source argument.
    AR6AIController::AR6AIController(this, baseSourceArgument);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)capturedSource;
    *(uint*)destination = ((uint)&AR6HostageAIVirtualTable);
    destination[0x56c] = input[0x56c]; // Native leaves padding bytes56d..56f untouched.
    for (uint offset = 0x570; offset < 0x5bc; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint word = *(const uint*)(input + 0x5bc);
    uint firstFlags = *(uint*)(destination + 0x5c4);
    *(uint*)(destination + 0x5bc) = word;
    *(uint*)(destination + 0x5c0) = *(const uint*)(input + 0x5c0);
    uint difference = firstFlags ^ *(const uint*)(input + 0x5c4);
    uint flags = *(uint*)(destination + 0x5c4) ^ (difference & 1U);
    *(uint*)(destination + 0x5c4) = flags;
    for (uint mask = 2; mask <= 0x2000; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x5c4);
        if (mask == 0x10) guard[3] = 0; // Native activates base cleanup AFTER reading the fifth source bit word.
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x5c4) = flags; // Fourteen separate publications; retain higher eighteen bits.
    }
    for (uint offset = 0x5c8; offset < 0x60c; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint lastBeforeArray = *(const uint*)(input + 0x60c);
    const FArray* arraySourceArgument = (const FArray*)(input + 0x610); // Reuses entryESP-0x24 before the store.
    *(uint*)(destination + 0x60c) = lastBeforeArray;
    CopyConstructRecords4((FArray*)(destination + 0x610), arraySourceArgument);
    for (uint offset = 0x61c; offset < 0x628; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    auto moveWords = [](byte* outputWords, const byte* inputWords, uint countWords) {
        __asm { // Inline view of native REP MOVSD groups; preserves the actual incoming direction flag.
            push esi
            push edi
            mov esi,inputWords
            mov edi,outputWords
            mov ecx,countWords
            rep movsd
            pop edi
            pop esi
        }
    };
    moveWords(destination + 0x628, input + 0x628, 9); // m_threatInfo raw36 bytes.
    for (uint offset = 0x64c; offset < 0x658; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    moveWords(destination + 0x658, input + 0x658, 10); // Two order-info records, twenty bytes each.
    for (uint offset = 0x680; offset < 0x6c8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    moveWords(destination + 0x6c8, input + 0x6c8, 24); // Twelve eight-byte sound records.
    ExceptionList = (void*)guard[1]; // State0 remains active; no completed cover-array cleanup is added to this map.
    return this;
}

// R6Engine.dll @ 10011dc0 : AR6HostageAI::DeletingDestructor
// Destroys scalar or cookie-counted array storage and conditionally releases it using the native low-byte flags.
void* __thiscall AR6HostageAI::DeletingDestructor(uint flags)
{
    byte deleteFlags = (byte)flags;
    if ((deleteFlags & 2) != 0) {
        byte* cookie = (byte*)this - 4;
        uint count = *(uint*)cookie;
        using DestroyArray = void (__stdcall*)(void*, uint, uint, void (__thiscall*)(AR6HostageAI*));
        (*(DestroyArray)((uint)&_eh_vector_destructor_iterator_))(this, 0x728, count,
            (void (__thiscall*)(AR6HostageAI*))((uint)&AR6HostageAIDestructorNativeEntry));
        if ((deleteFlags & 1) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    this->AR6HostageAI::~AR6HostageAI();
    if ((deleteFlags & 1) != 0) {
        UObject::operator delete(this, 0x728);
    }
    return this;
}

// R6Engine.dll @ 10013a50 : AR6HostageAI::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6HostageAI::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6HostageAIConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10043680 : HostageAIBaseArrayState0Cleanup
// Destroys the saved AI-controller base during unwinding.
__declspec(naked) void HostageAIBaseArrayState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6AIControllerDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043688 : HostageAIBaseArrayState1Cleanup
// Tail-destroys the saved HostageAI cover-node array during unwinding.
__declspec(naked) void HostageAIBaseArrayState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x610
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10048000 : DestroyAR6HostageAIClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6HostageAIClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6HostageAI::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046040 : InitializeAR6HostageAIClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6HostageAIClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred saved within-class word at entryESP-4.
        UClass* withinClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x50.
        int nativeConstructorTag;
        uint classSize;
        uint classFlags;
        UClass* parentClass;
        UClass* withinClass;
        uint guidWords[4];
        const ushort* className;
        const ushort* packageName;
        const ushort* configName;
        uint objectFlags;
        void (__cdecl* internalConstructor)(void*);
        union { // entryESP-0x18 is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6HostageAI::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6HostageAI;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6AIController::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x728;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6HostageAI::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6HostageAIClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100460c0 : PublishAR6HostageAIAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6HostageAIAutoClass(void)
{
    autoclassAR6HostageAI = &AR6HostageAI::PrivateStaticClass;
}

// R6Engine.dll @ 10043696 : HostageAIBaseArrayExceptionHandler
// Supplies the HostageAI destructor's array/base cleanup map to the inherited dispatcher frame.
__declspec(naked) void HostageAIBaseArrayExceptionHandler(void)
{
    __asm {
        mov eax,offset hostageAIBaseArrayInfo
        jmp __CxxFrameHandler
    }
}
