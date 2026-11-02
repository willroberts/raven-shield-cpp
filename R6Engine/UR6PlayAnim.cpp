#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyUR6PlayAnimClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004c350 : UR6PlayAnimVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: UR6PlayAnim::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix UR6PlayAnimVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055e76 : nativeTextR6PlayAnim
extern const ushort nativeTextR6PlayAnim[11];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl PlayAnimDestructionExceptionHandler(void);
__declspec(naked) void __cdecl PlayAnimDtorState0Cleanup(void);
__declspec(naked) void __cdecl PlayAnimDtorState1Cleanup(void);

// R6Engine.dll data @ 10057074 : playAnimDtorUnwind
// Retains the exact pending base/member cleanup states, without catches.
const NativeUnwindEntry playAnimDtorUnwind[2] = {
    { -1, ((uint)&PlayAnimDtorState0Cleanup) },
    { 0, ((uint)&PlayAnimDtorState1Cleanup) }
};

// R6Engine.dll data @ 10057084 : playAnimDtorInfo
// Retains the exact pending base/member cleanup states, without catches.
const NativeFunctionInfoPrefix playAnimDtorInfo = { 0x19930520, 0x2, ((uint)&playAnimDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 100844e4 : autoclassUR6PlayAnim
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassUR6PlayAnim = nullptr;

// R6Engine.dll @ 1000a810 : UR6PlayAnim::eventAnimFinished
// Dispatches AnimFinished through the captured table with preplaced null parameter/result words.
void __thiscall UR6PlayAnim::eventAnimFinished(void)
{
    FName eventName = R6ENGINE_AnimFinished;
    struct EventPacketView { // Inferred words at entryESP-0x18..-0xc, reused across lookup and dispatch.
        FName eventName;
        union { int lookupSuper; UFunction* function; };
        void* parameters;
        void* result;
    } packet;
    packet.result = nullptr;
    packet.parameters = nullptr;
    packet.lookupSuper = 0;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    packet.eventName = eventName;
    packet.function = this->UObject::FindFunctionChecked(
        reinterpret_cast<const FName&>(packet.eventName), packet.lookupSuper);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, packet.function, packet.parameters, packet.result);
}

// R6Engine.dll @ 1000a840 : UR6PlayAnim::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl UR6PlayAnim::StaticClass(void)
{
    return &UR6PlayAnim::PrivateStaticClass; // Selected object at0x100830c0.
}

// R6Engine.dll @ 1000a850 : UR6PlayAnim::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl UR6PlayAnim::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &UR6PlayAnim::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000a880 : UR6PlayAnim::~UR6PlayAnim
// Conditionally destroys UObject state, then destroys the mesh tag and UObject base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall UR6PlayAnim::~UR6PlayAnim(UR6PlayAnim* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&PlayAnimDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    *(uint*)this = ((uint)&UR6PlayAnimVirtualTable);
    guard[3] = 1;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0;
    reinterpret_cast<FStringNoInit*>(&this->m_StaticMeshTag)->FStringNoInit::~FStringNoInit();
    guard[3] = 0xffffffff;
    this->UObject::~UObject();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 1000a8e0 : UR6PlayAnim::UR6PlayAnim (native default view)
// Constructs UObject and the no-init mesh tag, leaving other animation fields untouched.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
UR6PlayAnim* __thiscall UR6PlayAnim::UR6PlayAnim(UR6PlayAnim* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ObjectBaseConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    UObject::UObject(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&UR6PlayAnimVirtualTable);
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_StaticMeshTag);
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 1000a930 : UR6PlayAnim::copy constructor
// Copy-constructs animation scalars, individual flags, references and the mesh tag in order.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
UR6PlayAnim* __thiscall UR6PlayAnim::UR6PlayAnim(UR6PlayAnim* this, const UR6PlayAnim* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ObjectBaseConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const UR6PlayAnim* capturedSource = source;
    const UR6PlayAnim* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats saved-this placement after the outgoing argument.
    UObject::UObject(this, baseSourceArgument);
    *(uint*)this = ((uint)&UR6PlayAnimVirtualTable);
    this->m_MaxPlayTime = capturedSource->m_MaxPlayTime;
    int playedTime = capturedSource->m_PlayedTime;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x38);
    uint earlyFlags = *destinationFlags; // Sampled before the played-time and frame stores.
    this->m_PlayedTime = playedTime;
    this->m_iFrameNumber = capturedSource->m_iFrameNumber;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x38);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 4U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_Rate) = reinterpret_cast<const uint&>(capturedSource->m_Rate);
    reinterpret_cast<uint&>(this->m_TweenTime) = reinterpret_cast<const uint&>(capturedSource->m_TweenTime);
    reinterpret_cast<uint&>(this->m_fBeginPct) = reinterpret_cast<const uint&>(capturedSource->m_fBeginPct);
    reinterpret_cast<uint&>(this->m_fEndPct) = reinterpret_cast<const uint&>(capturedSource->m_fEndPct);
    this->m_AttachActor = capturedSource->m_AttachActor;
    reinterpret_cast<uint&>(this->m_Sequence) = reinterpret_cast<const uint&>(capturedSource->m_Sequence);
    uint pawnTagWord = reinterpret_cast<const uint&>(capturedSource->m_PawnTag);
    const FStringNoInit* stringSourceArgument = (const FStringNoInit*)&capturedSource->m_StaticMeshTag;
    guard[3] = 0; // Native places the string argument before state0 and the final pawn-tag store.
    reinterpret_cast<uint&>(this->m_PawnTag) = pawnTagWord;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_StaticMeshTag, stringSourceArgument);
    ExceptionList = (void*)guard[1];
    return this; // Base and string return values do not replace the original receiver.
}

// R6Engine.dll @ 1000a9f0 : UR6PlayAnim::operator=
// Assigns animation scalars, individual flags, references and the mesh tag in order.
UR6PlayAnim& __thiscall UR6PlayAnim::operator=(const UR6PlayAnim& sourceObject)
{
    const UR6PlayAnim* source = &sourceObject;
    const UR6PlayAnim* capturedSource = source;
    const UR6PlayAnim* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    UObject::operator=(*baseSourceArgument);
    this->m_MaxPlayTime = capturedSource->m_MaxPlayTime;
    int playedTime = capturedSource->m_PlayedTime;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x38);
    uint earlyFlags = *destinationFlags; // Sampled before the played-time and frame stores.
    this->m_PlayedTime = playedTime;
    this->m_iFrameNumber = capturedSource->m_iFrameNumber;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x38);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 4U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_Rate) = reinterpret_cast<const uint&>(capturedSource->m_Rate);
    reinterpret_cast<uint&>(this->m_TweenTime) = reinterpret_cast<const uint&>(capturedSource->m_TweenTime);
    reinterpret_cast<uint&>(this->m_fBeginPct) = reinterpret_cast<const uint&>(capturedSource->m_fBeginPct);
    reinterpret_cast<uint&>(this->m_fEndPct) = reinterpret_cast<const uint&>(capturedSource->m_fEndPct);
    this->m_AttachActor = capturedSource->m_AttachActor;
    reinterpret_cast<uint&>(this->m_Sequence) = reinterpret_cast<const uint&>(capturedSource->m_Sequence);
    uint pawnTagWord = reinterpret_cast<const uint&>(capturedSource->m_PawnTag);
    const FStringNoInit* stringSourceArgument = (const FStringNoInit*)&capturedSource->m_StaticMeshTag;
    reinterpret_cast<uint&>(this->m_PawnTag) = pawnTagWord; // Native places the string argument before this store.
    reinterpret_cast<FStringNoInit*>(&this->m_StaticMeshTag)->operator=(*stringSourceArgument);
    return *this; // Base and string return values do not replace the original receiver.
}

// R6Engine.dll @ 1000e000 : UR6PlayAnim::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl UR6PlayAnim::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp UR6PlayAnimConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100433a0 : PlayAnimDtorState0Cleanup
// Destroys the saved UObject base through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayAnimDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UObjectDestructorImport]
    }
}

// R6Engine.dll @ 100433a9 : PlayAnimDtorState1Cleanup
// Destroys the saved mesh tag through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayAnimDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x58
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10047e60 : InitializeUR6PlayAnimClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeUR6PlayAnimClassMetadata(void)
{
    UClass* objectClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred local words at entryESP-8 and entryESP-4.
        UClass* withinClass;
        UClass* parentClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x54.
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
        union { // entryESP-0x1c is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    captures.withinClass = objectClass;
    captures.parentClass = objectClass; // Separate saved words initially receive the same captured UObject class.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &UR6PlayAnim::InternalConstructor;
    packet.objectFlags = 0x04084004;
    const ushort* configName = UObject::StaticConfigName();
    UClass* withinClass = captures.withinClass;
    packet.configName = configName;
    UClass* parentClass = captures.parentClass; // Native reloads this saved word after placing the config result.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6PlayAnim;
    packet.withinClass = withinClass;
    packet.guidWords[0] = 0;
    packet.parentClass = parentClass;
    packet.guidWords[1] = 0;
    packet.classFlags = 0;
    packet.guidWords[2] = 0;
    packet.classSize = 0x64;
    packet.guidWords[3] = 0;
    packet.nativeConstructorTag = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&UR6PlayAnim::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyUR6PlayAnimClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10048200 : DestroyUR6PlayAnimClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyUR6PlayAnimClassMetadata(void)
{
    __asm {
        mov ecx,offset UR6PlayAnim::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047ee0 : PublishUR6PlayAnimAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishUR6PlayAnimAutoClass(void)
{
    autoclassUR6PlayAnim = &UR6PlayAnim::PrivateStaticClass;
}

// R6Engine.dll @ 100433b5 : PlayAnimDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl PlayAnimDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset playAnimDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000aa80 : UR6PlayAnim::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall UR6PlayAnim::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&UR6PlayAnimDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x64;
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
    this->UR6PlayAnim::~UR6PlayAnim();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x64;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
