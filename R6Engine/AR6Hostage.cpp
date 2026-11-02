#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 10049d60 : AR6HostageVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Hostage::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6HostageVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055706 : nativeTextR6Hostage
extern const ushort nativeTextR6Hostage[10];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void HostageCtorExceptionHandler(void);
__declspec(naked) void HostageCtorState0Cleanup(void);
__declspec(naked) void HostageDtorExceptionHandler(void);
__declspec(naked) void HostageDtorState0Cleanup(void);
__declspec(naked) void HostageDtorState1Cleanup(void);

// R6Engine.dll data @ 10056a48 : hostageDtorUnwind
// Destruction state one cleans the string, then state zero destroys the Pawn base.
const NativeUnwindEntry hostageDtorUnwind[2] = {
    { -1, ((uint)&HostageDtorState0Cleanup) },
    { 0, ((uint)&HostageDtorState1Cleanup) }
};

// R6Engine.dll data @ 10056a58 : hostageDtorInfo
// Destruction has two cleanup states and no catches.
const NativeFunctionInfoPrefix hostageDtorInfo = { 0x19930520, 0x2, ((uint)&hostageDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10056a74 : hostageCtorUnwind
// Default and copy construction share the Pawn-base cleanup state.
const NativeUnwindEntry hostageCtorUnwind[1] = {
    { -1, ((uint)&HostageCtorState0Cleanup) }
};

// R6Engine.dll data @ 10056a7c : hostageCtorInfo
// Both constructors use this one-state cleanup map, with no catches.
const NativeFunctionInfoPrefix hostageCtorInfo = { 0x19930520, 0x1, ((uint)&hostageCtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10078310 : autoclassAR6Hostage
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Hostage = nullptr;

// R6Engine.dll @ 10004b30 : AR6Hostage::eventGotoProne
// Dispatches GotoProne through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventGotoProne(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GotoProne;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10004b60 : AR6Hostage::eventGotoFoetus
// Dispatches GotoFoetus through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventGotoFoetus(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GotoFoetus;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10004b90 : AR6Hostage::eventGotoKneel
// Dispatches GotoKneel through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventGotoKneel(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GotoKneel;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10004bc0 : AR6Hostage::eventGotoCrouch
// Dispatches GotoCrouch through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventGotoCrouch(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GotoCrouch;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10004bf0 : AR6Hostage::eventGotoStand
// Dispatches GotoStand through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventGotoStand(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GotoStand;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10004c20 : AR6Hostage::eventSetAnimInfo
// Dispatches SetAnimInfo through the current slot of the vtable captured before lookup.
void __thiscall AR6Hostage::eventSetAnimInfo(int ID)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_SetAnimInfo;
    int animationID = ID;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    ID = animationID; // Original incoming slot remains the live event packet.
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &ID, nullptr);
}

// R6Engine.dll @ 10004c90 : AR6Hostage::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Hostage::StaticClass(void)
{
    return &AR6Hostage::PrivateStaticClass; // Selected object at0x10077e08.
}

// R6Engine.dll @ 10004ca0 : AR6Hostage::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6Hostage::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6Hostage::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10004cd0 : AR6Hostage::~AR6Hostage
// Conditionally destroys UObject state, releases the template string, then destroys the Pawn base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6Hostage::~AR6Hostage(AR6Hostage* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class storage.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&HostageDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6HostageVirtualTable);
    guard[3] = 1;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0;
    reinterpret_cast<FStringNoInit*>(&this->m_szUsedTemplate)->FStringNoInit::~FStringNoInit();
    guard[3] = 0xffffffff;
    this->AR6Pawn::~AR6Pawn();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10004d40 : AR6Hostage::AR6Hostage (native default-constructor view)
// Constructs the imported abstract-pawn base, publishes the Hostage vtable and constructs the template string.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6Hostage* __thiscall AR6Hostage::AR6Hostage(AR6Hostage* this)
{
    uint guard[4]; // Exact shared constructor guard; saved receiver is inherited EBP-0x10 during cleanup.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&HostageCtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6AbstractPawn::AR6AbstractPawn(this); // Native bypasses the intermediate Pawn constructor.
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6HostageVirtualTable);
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szUsedTemplate);
    ExceptionList = (void*)guard[1];
    return this; // No extra derived-field initialization or completed-string cleanup state.
}

// R6Engine.dll @ 10004d90 : AR6Hostage::AR6Hostage (native copy-constructor view)
// Copies Pawn state, hostage bytes/flags and raw structured words, then copies the template string.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6Hostage* __thiscall AR6Hostage::AR6Hostage(
    AR6Hostage* this, const AR6Hostage* source)
{
    uint guard[4]; // Same one-state map as default construction; activation is delayed during the flag copies.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&HostageCtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const AR6Hostage* const capturedSource = source;
    const AR6Pawn* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats the saved-receiver store after placing the base argument.
    using CopyPawnBase = AR6Pawn* (__thiscall*)(AR6Pawn*, const AR6Pawn*);
    reinterpret_cast<CopyPawnBase>(&AR6PawnCopyConstructorNativeEntry)(this, baseSourceArgument);
    *(uint*)this = ((uint)&AR6HostageVirtualTable);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)capturedSource;
    for (uint offset = 0xa28; offset < 0xa2e; ++offset) destination[offset] = input[offset];
    uint index = *(const uint*)(input + 0xa30);
    uint firstFlags = *(uint*)(destination + 0xa38); // Captured before m_iIndex and m_iPrisonierTeam publication.
    reinterpret_cast<uint&>(this->m_iIndex) = index;
    reinterpret_cast<uint&>(this->m_iPrisonierTeam) = *(const uint*)(input + 0xa34);
    uint difference = firstFlags ^ *(const uint*)(input + 0xa38);
    uint flags = *(uint*)(destination + 0xa38) ^ (difference & 1U);
    *(uint*)(destination + 0xa38) = flags;
    for (uint mask = 2; mask != 0x20000; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0xa38);
        if (mask == 0x400) guard[3] = 0; // Base cleanup activates after the eleventh source flag read.
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0xa38) = flags; // Seventeen separate stores; retain upper fifteen destination bits.
    }
    // References, names, random-time structures and animation records use forward raw DWORD copies.
    for (uint offset = 0xa3c; offset < 0xad8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    const FStringNoInit* stringArgument = (const FStringNoInit*)(input + 0xad8); // Outgoing word at entryESP-0x1c.
    using CopyString = void (__thiscall*)(FStringNoInit*, const FStringNoInit&);
    CopyString copy = reinterpret_cast<CopyString&>(FStringNoInitCopyConstructorImport);
    copy((FStringNoInit*)(destination + 0xad8), *stringArgument);
    ExceptionList = (void*)guard[1];
    return this; // Native returns original this; no self-assignment shortcut.
}

// R6Engine.dll @ 10005150 : AR6Hostage::operator=
// Copies Pawn state, hostage bytes/flags and raw structured words, then copies the template string.
AR6Hostage& __thiscall AR6Hostage::operator=(const AR6Hostage& sourceObject)
{
    const AR6Hostage* source = &sourceObject;
    const AR6Hostage* const capturedSource = source;
    const AR6Pawn* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    this->AR6Pawn::operator=(*baseSourceArgument);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)capturedSource;
    for (uint offset = 0xa28; offset < 0xa2e; ++offset) destination[offset] = input[offset];
    uint index = *(const uint*)(input + 0xa30);
    uint firstFlags = *(uint*)(destination + 0xa38); // Captured before m_iIndex and m_iPrisonierTeam publication.
    reinterpret_cast<uint&>(this->m_iIndex) = index;
    reinterpret_cast<uint&>(this->m_iPrisonierTeam) = *(const uint*)(input + 0xa34);
    uint difference = firstFlags ^ *(const uint*)(input + 0xa38);
    uint flags = *(uint*)(destination + 0xa38) ^ (difference & 1U);
    *(uint*)(destination + 0xa38) = flags;
    for (uint mask = 2; mask != 0x20000; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0xa38);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0xa38) = flags; // Seventeen separate stores; retain upper fifteen destination bits.
    }
    // References, names, random-time structures and animation records use forward raw DWORD copies.
    for (uint offset = 0xa3c; offset < 0xad8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    const FStringNoInit* stringArgument = (const FStringNoInit*)(input + 0xad8); // Outgoing word at entryESP-0xc.
    reinterpret_cast<FStringNoInit*>(destination + 0xad8)->operator=(*stringArgument);
    return *this; // Native returns original this; no self-assignment shortcut.
}

// R6Engine.dll @ 1000dbe0 : AR6Hostage::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Hostage::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6HostageConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10042fa0 : HostageDtorState0Cleanup
// Destroys the Pawn base through the inherited parent-frame receiver.
__declspec(naked) void HostageDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 10042fa8 : HostageDtorState1Cleanup
// Destroys the template string through the inherited parent-frame receiver.
__declspec(naked) void HostageDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xad8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10042fb7 : HostageDtorExceptionHandler
// Selects parent-specific cleanup metadata and tail-enters the native exception dispatcher.
__declspec(naked) void HostageDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset hostageDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042fd0 : HostageCtorState0Cleanup
// Destroys the Pawn base through the inherited parent-frame receiver.
__declspec(naked) void HostageCtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 10042fd8 : HostageCtorExceptionHandler
// Selects shared constructor cleanup metadata and tail-enters the native exception dispatcher.
__declspec(naked) void HostageCtorExceptionHandler(void)
{
    __asm {
        mov eax,offset hostageCtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10048010 : DestroyAR6HostageClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6HostageClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Hostage::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100460d0 : InitializeAR6HostageClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6HostageClassMetadata(void)
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
    packet.internalConstructor = &AR6Hostage::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6Hostage;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Pawn::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xae4;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6Hostage::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6HostageClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10046150 : PublishAR6HostageAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6HostageAutoClass(void)
{
    autoclassAR6Hostage = &AR6Hostage::PrivateStaticClass;
}

// R6Engine.dll @ 100054d0 : AR6Hostage::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6Hostage::DeletingDestructor(uint flags)
{
    byte deleteFlags = reinterpret_cast<byte&>(flags); // Captured once; native RET4 consumes the full incoming word.
    if ((deleteFlags & 2U) != 0) {
        int count = *(int*)((byte*)this - 4);
        using Destructor = void (__thiscall*)(void*);
        struct ArrayPacketView { // Inferred four-word outgoing packet at entryESP-0x1c.
            void* objects;
            uint stride;
            int count;
            Destructor destroy;
        } packet;
        packet.destroy = (Destructor)&AR6HostageDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xae4;
        packet.objects = this;
        _eh_vector_destructor_iterator_(packet.objects, packet.stride, packet.count, packet.destroy);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            NativeAllocatorVtablePrefix* allocatorVtable = *reinterpret_cast<NativeAllocatorVtablePrefix**>(allocator);
            void* freeArgument = cookie; // Outgoing argument precedes the current virtual target read.
            using Free = void (__thiscall*)(void*, void*);
            Free free = reinterpret_cast<Free&>(allocatorVtable->freeAddress);
            free(allocator, freeArgument);
        }
        return cookie;
    }
    this->AR6Hostage::~AR6Hostage();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xae4;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
