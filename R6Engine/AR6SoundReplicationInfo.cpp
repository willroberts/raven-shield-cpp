#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl SoundPreReceiveExceptionHandler(void);
__declspec(naked) void __cdecl SoundTickExceptionHandler(void);
__declspec(naked) void __cdecl SoundPlayWeaponExceptionHandler(void);
int __cdecl CastToAPlayerController(int object);
__declspec(naked) void __cdecl SoundPostReceiveExceptionHandler(void);
__declspec(naked) void __cdecl SoundStopWeaponSoundExceptionHandler(void);
__declspec(naked) void __cdecl SoundLocalWeaponExceptionHandler(void);
__declspec(naked) void __cdecl DestroyAR6SoundReplicationInfoClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// External native storage views; names describe roles rather than recovered original identifiers.
// R6Engine.dll data @ 10075a20 : nativeSoundReceiveWeapon
// Shared pre-receive byte snapshot; no adjacent padding/object fields are invented.
extern byte nativeSoundReceiveWeapon;

// R6Engine.dll data @ 10075a21 : nativeSoundReceiveWeaponSound
// Shared pre-receive byte snapshot; no adjacent padding/object fields are invented.
extern byte nativeSoundReceiveWeaponSound;

// R6Engine.dll data @ 10075a22 : nativeSoundReceivePawnState
// Shared pre-receive byte snapshot; no adjacent padding/object fields are invented.
extern byte nativeSoundReceivePawnState;

// R6Engine.dll data @ 10075f34 : nativeSoundReceiveLocationXWord
// Raw shared pre-receive X snapshot.
extern uint nativeSoundReceiveLocationXWord;

// R6Engine.dll data @ 10075f38 : nativeSoundReceiveLocationYWord
// Raw shared pre-receive Y snapshot.
extern uint nativeSoundReceiveLocationYWord;

// R6Engine.dll data @ 10075f3c : nativeSoundReceiveLocationZWord
// Raw shared pre-receive Z snapshot.
extern uint nativeSoundReceiveLocationZWord;

// R6Engine.dll data @ 1004c148 : AR6SoundReplicationInfoVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6SoundReplicationInfo::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6SoundReplicationInfoVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10053208 : nativeTextAR6SoundReplicationInfoExecPlayLocalWeaponSound
extern const ushort nativeTextAR6SoundReplicationInfoExecPlayLocalWeaponSound[50];

// R6Engine.dll data @ 10053180 : nativeTextAR6SoundReplicationInfoPostNetReceive
extern const ushort nativeTextAR6SoundReplicationInfoPostNetReceive[40];

// R6Engine.dll data @ 100530a8 : nativeTextAR6SoundReplicationInfoPreNetReceive
extern const ushort nativeTextAR6SoundReplicationInfoPreNetReceive[39];

// R6Engine.dll data @ 100530f8 : nativeTextAR6SoundReplicationInfoTickSpecial
extern const ushort nativeTextAR6SoundReplicationInfoTickSpecial[37];

// R6Engine.dll data @ 10053144 : nativeTextAR6WeaponsPlayWeaponSound
extern const ushort nativeTextAR6WeaponsPlayWeaponSound[28];

// R6Engine.dll data @ 100531d0 : nativeTextAR6WeaponsStopWeaponSound
extern const ushort nativeTextAR6WeaponsStopWeaponSound[28];

// R6Engine.dll data @ 1005326e : nativeTextR6SoundReplicationInfo
extern const ushort nativeTextR6SoundReplicationInfo[23];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl SoundLocalWeaponCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundLocalWeaponCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPlayCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPlayCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPostReceiveCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPostReceiveCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPreReceiveCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundPreReceiveCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundStopWeaponSoundCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundStopWeaponSoundCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundTickCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl SoundTickCatchPointer(void);

// R6Engine.dll data @ 1005d16c : soundPlayUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundPlayUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d17c : soundPlayCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundPlayCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&SoundPlayCatchPointer) },
    { 0, 0, 0, ((uint)&SoundPlayCatchContext) }
};

// R6Engine.dll data @ 1005d19c : soundPlayTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundPlayTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundPlayCatchMap) }
};

// R6Engine.dll data @ 1005d1b0 : soundPlayFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundPlayFuncInfo = { 0x19930520, 0x2, ((uint)&soundPlayUnwindMap), 0x1,
    ((uint)&soundPlayTryMap), 0 };

// R6Engine.dll data @ 1005d28c : soundLocalWeaponUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundLocalWeaponUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d29c : soundLocalWeaponCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundLocalWeaponCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&SoundLocalWeaponCatchPointer) },
    { 0, 0, 0, ((uint)&SoundLocalWeaponCatchContext) }
};

// R6Engine.dll data @ 1005d2bc : soundLocalWeaponTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundLocalWeaponTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundLocalWeaponCatchMap) }
};

// R6Engine.dll data @ 1005d2d0 : soundLocalWeaponFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundLocalWeaponFuncInfo = { 0x19930520, 0x2, ((uint)&soundLocalWeaponUnwindMap), 0x1,
    ((uint)&soundLocalWeaponTryMap), 0 };

// R6Engine.dll data @ 1005d22c : soundStopWeaponSoundUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundStopWeaponSoundUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d23c : soundStopWeaponSoundCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundStopWeaponSoundCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SoundStopWeaponSoundCatchPointer) },
    { 0, 0, 0, ((uint)&SoundStopWeaponSoundCatchContext) }
};

// R6Engine.dll data @ 1005d25c : soundStopWeaponSoundTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundStopWeaponSoundTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundStopWeaponSoundCatchMap) }
};

// R6Engine.dll data @ 1005d270 : soundStopWeaponSoundFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundStopWeaponSoundFuncInfo = { 0x19930520, 0x2, ((uint)&soundStopWeaponSoundUnwindMap),
    0x1, ((uint)&soundStopWeaponSoundTryMap), 0 };

// R6Engine.dll data @ 1005d1cc : soundPostReceiveUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundPostReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d1dc : soundPostReceiveCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundPostReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SoundPostReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&SoundPostReceiveCatchContext) }
};

// R6Engine.dll data @ 1005d1fc : soundPostReceiveTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundPostReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundPostReceiveCatchMap) }
};

// R6Engine.dll data @ 1005d210 : soundPostReceiveFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundPostReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&soundPostReceiveUnwindMap), 0x1,
    ((uint)&soundPostReceiveTryMap), 0 };

// R6Engine.dll data @ 1005d10c : soundTickUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundTickUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d11c : soundTickCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundTickCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SoundTickCatchPointer) },
    { 0, 0, 0, ((uint)&SoundTickCatchContext) }
};

// R6Engine.dll data @ 1005d13c : soundTickTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundTickTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundTickCatchMap) }
};

// R6Engine.dll data @ 1005d150 : soundTickFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundTickFuncInfo = { 0x19930520, 0x2, ((uint)&soundTickUnwindMap), 0x1,
    ((uint)&soundTickTryMap), 0 };

// R6Engine.dll data @ 1005d0ac : soundPreReceiveUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry soundPreReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d0bc : soundPreReceiveCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry soundPreReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SoundPreReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&SoundPreReceiveCatchContext) }
};

// R6Engine.dll data @ 1005d0dc : soundPreReceiveTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock soundPreReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&soundPreReceiveCatchMap) }
};

// R6Engine.dll data @ 1005d0f0 : soundPreReceiveFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix soundPreReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&soundPreReceiveUnwindMap), 0x1,
    ((uint)&soundPreReceiveTryMap), 0 };

// R6Engine.dll data @ 10074528 : intAR6SoundReplicationInfoexecPlayLocalWeaponSound
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6SoundReplicationInfoexecPlayLocalWeaponSound =
    (Native)&AR6SoundReplicationInfo::execPlayLocalWeaponSound;

// R6Engine.dll data @ 1007fdbc : AR6SoundReplicationInfoPlayLocalWeaponSoundRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6SoundReplicationInfoPlayLocalWeaponSoundRegistrationResult = 0;

// R6Engine.dll data @ 1007452c : intAR6SoundReplicationInfoexecStopWeaponSound
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6SoundReplicationInfoexecStopWeaponSound = (Native)&AR6SoundReplicationInfo::execStopWeaponSound;

// R6Engine.dll data @ 100802ed : AR6SoundReplicationInfoStopWeaponSoundRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6SoundReplicationInfoStopWeaponSoundRegistrationResult = 0;

// R6Engine.dll data @ 10074530 : intAR6SoundReplicationInfoexecPlayWeaponSound
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6SoundReplicationInfoexecPlayWeaponSound = (Native)&AR6SoundReplicationInfo::execPlayWeaponSound;

// R6Engine.dll data @ 1007d9ee : AR6SoundReplicationInfoPlayWeaponSoundRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6SoundReplicationInfoPlayWeaponSoundRegistrationResult = 0;

// R6Engine.dll data @ 10075f30 : autoclassAR6SoundReplicationInfo
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6SoundReplicationInfo = nullptr;

// R6Engine.dll @ 1000a230 : AR6SoundReplicationInfo::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6SoundReplicationInfo::StaticClass(void)
{
    return &AR6SoundReplicationInfo::PrivateStaticClass; // Selected object at0x10075a28.
}

// R6Engine.dll @ 1000a240 : AR6SoundReplicationInfo::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6SoundReplicationInfo::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6SoundReplicationInfo::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 1000a270 : AR6SoundReplicationInfo::~AR6SoundReplicationInfo
// Conditionally destroys UObject state while retaining base cleanup for an exceptional exit.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6SoundReplicationInfo::~AR6SoundReplicationInfo(AR6SoundReplicationInfo* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ActorBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6SoundReplicationInfoVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 1000a2d0 : AR6SoundReplicationInfo::AR6SoundReplicationInfo (native default view)
// Constructs the AActor base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6SoundReplicationInfoVirtualTable follows base completion.
AR6SoundReplicationInfo::AR6SoundReplicationInfo() : AActor()
{
}

// R6Engine.dll @ 1000a2f0 : AR6SoundReplicationInfo::copy constructor
// Copy-constructs the base, individual flags and raw member values in native order.
AR6SoundReplicationInfo::AR6SoundReplicationInfo(const AR6SoundReplicationInfo& sourceObject) : AActor(sourceObject)
{
    // Publishes AR6SoundReplicationInfoVirtualTable after base copy; native EAX retains original storage.
    const AR6SoundReplicationInfo* source = &sourceObject;
    this->m_CurrentWeapon = source->m_CurrentWeapon;
    this->m_NewWeaponSound = source->m_NewWeaponSound;
    this->m_NewPawnState = source->m_NewPawnState;
    this->m_Material = source->m_Material;
    this->m_pawnState = source->m_pawnState;
    this->m_TeamColor = source->m_TeamColor;
    this->m_GunSoundType = source->m_GunSoundType;
    byte statusOtherTeam = source->m_StatusOtherTeam;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a0);
    uint earlyFlags = *destinationFlags; // Sampled before publishing the last two byte fields.
    this->m_StatusOtherTeam = statusOtherTeam;
    this->m_LastPlayedWeaponSound = source->m_LastPlayedWeaponSound;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3a0);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference; // Native rereads the destination for the first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fClientUpdateFrequency) = reinterpret_cast<const
        uint&>(source->m_fClientUpdateFrequency);
    reinterpret_cast<uint&>(this->m_fClientLastUpdate) = reinterpret_cast<const uint&>(source->m_fClientLastUpdate);
    this->m_pawnOwner = source->m_pawnOwner;
    this->m_PawnRepInfo = source->m_PawnRepInfo;
    reinterpret_cast<uint&>(this->m_Location.X) = reinterpret_cast<const uint&>(source->m_Location.X);
    reinterpret_cast<uint&>(this->m_Location.Y) = reinterpret_cast<const uint&>(source->m_Location.Y);
    reinterpret_cast<uint&>(this->m_Location.Z) = reinterpret_cast<const uint&>(source->m_Location.Z);
}

// R6Engine.dll @ 1000a400 : AR6SoundReplicationInfo::operator=
// Assigns the base, individual flags and raw member values in native order.
AR6SoundReplicationInfo& __thiscall AR6SoundReplicationInfo::operator=(const AR6SoundReplicationInfo& sourceObject)
{
    const AR6SoundReplicationInfo* source = &sourceObject;
    this->AActor::operator=(*source);
    this->m_CurrentWeapon = source->m_CurrentWeapon;
    this->m_NewWeaponSound = source->m_NewWeaponSound;
    this->m_NewPawnState = source->m_NewPawnState;
    this->m_Material = source->m_Material;
    this->m_pawnState = source->m_pawnState;
    this->m_TeamColor = source->m_TeamColor;
    this->m_GunSoundType = source->m_GunSoundType;
    byte statusOtherTeam = source->m_StatusOtherTeam;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a0);
    uint earlyFlags = *destinationFlags; // Sampled before publishing the last two byte fields.
    this->m_StatusOtherTeam = statusOtherTeam;
    this->m_LastPlayedWeaponSound = source->m_LastPlayedWeaponSound;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3a0);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference; // Native rereads the destination for the first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fClientUpdateFrequency) = reinterpret_cast<const
        uint&>(source->m_fClientUpdateFrequency);
    reinterpret_cast<uint&>(this->m_fClientLastUpdate) = reinterpret_cast<const uint&>(source->m_fClientLastUpdate);
    this->m_pawnOwner = source->m_pawnOwner;
    this->m_PawnRepInfo = source->m_PawnRepInfo;
    reinterpret_cast<uint&>(this->m_Location.X) = reinterpret_cast<const uint&>(source->m_Location.X);
    reinterpret_cast<uint&>(this->m_Location.Y) = reinterpret_cast<const uint&>(source->m_Location.Y);
    reinterpret_cast<uint&>(this->m_Location.Z) = reinterpret_cast<const uint&>(source->m_Location.Z);
    return *this; // Ignore base EAX; preserve forward operations even for aliased source storage.
}

// R6Engine.dll @ 1000dfe0 : AR6SoundReplicationInfo::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6SoundReplicationInfo::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6SoundReplicationInfoConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1003a3d0 : AR6SoundReplicationInfo::PreNetReceive
// Runs the base receive hook, then snapshots sound-state bytes and raw replicated-location words in module storage.
void __thiscall AR6SoundReplicationInfo::PreNetReceive(void)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct PreReceiveFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundPreReceiveExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    this->AActor::PreNetReceive();
    byte* object = (byte*)this;
    byte newPawnState = reinterpret_cast<byte&>(this->m_NewPawnState);
    byte newWeaponSound = reinterpret_cast<byte&>(this->m_NewWeaponSound);
    uint* locationWords = (uint*)(object + 0x3b4); // m_Location; copied without floating-point conversion.
    *(byte*)&nativeSoundReceivePawnState = newPawnState;
    uint xWord = locationWords[0];
    reinterpret_cast<uint&>(nativeSoundReceiveLocationXWord) = xWord;
    reinterpret_cast<byte&>(nativeSoundReceiveWeaponSound) = newWeaponSound;
    uint yWord = locationWords[1];
    reinterpret_cast<uint&>(nativeSoundReceiveLocationYWord) = yWord;
    uint zWord = locationWords[2];
    void* previousChain = nativeFrame.previousExceptionList;
    reinterpret_cast<uint&>(nativeSoundReceiveLocationZWord) = zWord;
    byte currentWeapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
    reinterpret_cast<byte&>(nativeSoundReceiveWeapon) = currentWeapon;
    ExceptionList = previousChain;
}

// R6Engine.dll @ 1003a452 : SoundPreReceiveCatchPointer
// Copies the caught text pointer at EBP-18 into the parent's EBP-14 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPreReceiveCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a466 : SoundPreReceiveCatchContext
// Reports the native pre-receive context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPreReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6SoundReplicationInfoPreNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a490 : AR6SoundReplicationInfo::TickSpecial
// Follows the pawn owner and periodically snapshots its location for replication outside standalone mode.
void __thiscall AR6SoundReplicationInfo::TickSpecial(float deltaTime)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct SoundTickFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundTickExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    uint baseDeltaWord = reinterpret_cast<uint&>(deltaTime);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    this->AActor::TickSpecial(reinterpret_cast<const float&>(baseDeltaWord));
    byte* object = (byte*)this;
    byte* pawnOwner = reinterpret_cast<byte*&>(this->m_pawnOwner); // m_pawnOwner, sampled after the base hook.
    if (pawnOwner != nullptr) {
        uint* ownerLocation = (uint*)(pawnOwner + 0x234);
        uint* location = (uint*)(object + 0x234);
        location[0] = ownerLocation[0];
        location[1] = ownerLocation[1];
        location[2] = ownerLocation[2];
        uint* ownerRegion = (uint*)(pawnOwner + 0x228); // Region, including raw padding.
        uint* region = (uint*)(object + 0x228);
        region[0] = ownerRegion[0];
        region[1] = ownerRegion[1];
        region[2] = ownerRegion[2];
        if (reinterpret_cast<byte&>(this->Role) == 4) { // Role == ROLE_Authority.
            byte* level = reinterpret_cast<byte*&>(this->Level);
            if (*(byte*)(level + 0x425) != 0) { // NetMode != NM_Standalone.
                // Descriptive x87 view: FST rounds the field, but FCOMP retains the unspilled sum.
                float10 elapsed = (float10)deltaTime + (float10)this->m_fClientLastUpdate;
                this->m_fClientLastUpdate = (float)elapsed; // m_fClientLastUpdate.
                if (elapsed > (float10)this->m_fClientUpdateFrequency) { // m_fClientUpdateFrequency; unordered skips.
                    uint* replicatedLocation = (uint*)(object + 0x3b4);
                    replicatedLocation[0] = ownerLocation[0];
                    replicatedLocation[1] = ownerLocation[1];
                    replicatedLocation[2] = ownerLocation[2];
                    uint flags = *(uint*)(object + 0xa0) | 0x40000000; // bNetDirty.
                    reinterpret_cast<uint&>(this->m_fClientLastUpdate) = 0;
                    *(uint*)(object + 0xa0) = flags;
                }
            }
        }
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003a581 : SoundTickCatchPointer
// Copies caught text from the parent's EBP-18 slot into its EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl SoundTickCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a595 : SoundTickCatchContext
// Reports the native tick context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundTickCatchContext(void)
{
    __asm {
        push offset nativeTextAR6SoundReplicationInfoTickSpecial
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a5c0 : AR6SoundReplicationInfo::IsNetRelevantFor
// Tests the viewer's sound zone against this actor's zone and the level's audible-zone mask.
int __thiscall AR6SoundReplicationInfo::IsNetRelevantFor(APlayerController* player, AActor* unusedActor,
    uint unusedViewX, uint unusedViewY, uint unusedViewZ)
{
    // Raw words retain the native five-word argument packet; the actor/view-location arguments are unused.
    byte* viewer = (byte*)player;
    byte* viewerPawn = *(byte**)(viewer + 0x3d8);
    byte* viewerZone = viewerPawn != nullptr ? *(byte**)(viewerPawn + 0x228) : *(byte**)(viewer + 0x228);
    byte* object = (byte*)this;
    byte* sourceZone = *(byte**)(object + 0x228); // Region.Zone.
    uint sourceSoundZone = *(byte*)(sourceZone + 0x397); // ZoneInfo::m_SoundZone.
    uint viewerSoundZone = *(byte*)(viewerZone + 0x397);
    if (sourceSoundZone == viewerSoundZone) return 1;
    byte* level = reinterpret_cast<byte*&>(this->Level);
    uint viewerBit = 1u << (viewerSoundZone & 31);
    uint* audibleZoneWords = (uint*)(level + 0x650 + sourceSoundZone * 8); // m_SoundZoneAudibleZones.
    uint lowMask = audibleZoneWords[0];
    uint highBits = (viewerBit & 0x80000000) != 0 ? 0xffffffff : 0; // Native CDQ sign-extends the shifted DWORD.
    uint lowMatch = viewerBit & lowMask;
    uint highMask = audibleZoneWords[1]; // Read even when the low match is nonzero.
    return (lowMatch | (highBits & highMask)) != 0 ? 1 : 0;
}

// R6Engine.dll @ 1003a630 : AR6SoundReplicationInfo::PlayWeaponSound
// Dispatches weapon particles and layered sounds, then records the last sound and initialization flag.
void __thiscall AR6SoundReplicationInfo::PlayWeaponSound(EWeaponSound soundType, uint weaponWord)
{
    // Raw DWORD view of the exported unsigned-char weapon argument; normalization writes the incoming slot.
    // Descriptive frame: controller EBP-14, caught/rethrow EBP-1c/-18, saved ESP EBP-28.
    struct PlayWeaponFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        byte* controller;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundPlayWeaponExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte* object = (byte*)this;
    byte* pawnOwner = reinterpret_cast<byte*&>(this->m_pawnOwner);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (pawnOwner != nullptr) {
        byte* weapon = *(byte**)(pawnOwner + 0x4fc);
        if (weapon != nullptr) {
            using ParticleEvent = void (__thiscall*)(byte*, uint);
            // Preserve the complete incoming call word.
            reinterpret_cast<ParticleEvent&>(AR6EngineWeaponEventShowWeaponParticulesImport)(weapon, (uint)soundType);
        }
    }
    if (reinterpret_cast<byte*&>(this->m_PawnRepInfo) == nullptr) {
        ExceptionList = nativeFrame.previousExceptionList;
        __asm { xor eax,eax }
        return;
    }
    if (reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) == 6 && soundType != (EWeaponSound)10)
        this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)10, weaponWord);
    byte** engineSlot = *(byte***)&EngineGPEngineImport;
    byte* engine = *engineSlot;
    byte* audio = *(byte**)(engine + 0x48);
    if (audio != nullptr) {
        byte* pawnRepInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
        nativeFrame.controller = (byte*)CastToAPlayerController(*(int*)(pawnRepInfo + 0x39c));
        // Descriptive local call views; each call site retains its own vtable/reference read order.
        auto dispatchSound = [&](uint reference, uint* vtable) {
            using AudioCall = void (__thiscall*)(byte*, AR6SoundReplicationInfo*, uint, uint, uint);
            ((AudioCall)vtable[0x84 / 4])(audio, this, reference, 2, 0);
        };
        auto firstLayer = [&](uint offset) {
            uint index = (byte)weaponWord;
            uint* vtable = *(uint**)audio;
            weaponWord = index;
            uint reference = *(uint*)(pawnRepInfo + offset + index * 4);
            dispatchSound(reference, vtable);
        };
        auto laterLayer = [&](byte* currentInfo, uint index, uint offset) {
            uint reference = *(uint*)(currentInfo + offset + index * 4);
            uint* vtable = *(uint**)audio;
            dispatchSound(reference, vtable);
        };
        auto optionalLayerAllowed = [&]() {
            byte* controller = nativeFrame.controller;
            if (controller == nullptr) return false;
            return reinterpret_cast<AController*>(controller)->LocalPlayerController() != 0;
        };
        switch ((uint)soundType) {
        case 2:
        case 4: {
            uint index = (byte)weaponWord;
            uint offset = soundType == (EWeaponSound)2 ? 0x3a0 : 0x3c0;
            uint reference = *(uint*)(pawnRepInfo + offset + index * 4);
            uint* vtable = *(uint**)audio;
            dispatchSound(reference, vtable);
            break;
        }
        case 3:
        case 5: {
            uint secondOffset = soundType == (EWeaponSound)3 ? 0x3b0 : 0x3d0;
            uint thirdOffset = soundType == (EWeaponSound)3 ? 0x430 : 0x440;
            firstLayer(0x3a0);
            byte* currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
            uint index = weaponWord;
            laterLayer(currentInfo, index, secondOffset);
            if (optionalLayerAllowed()) {
                currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
                laterLayer(currentInfo, index, thirdOffset);
            }
            break;
        }
        case 6:
            if (reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) != 6 && (*(byte*)(pawnRepInfo + 0x398) & 2) == 0)
                {
                firstLayer(0x3a0);
                byte* currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
                uint index = weaponWord;
                laterLayer(currentInfo, index, 0x3e0);
                if (optionalLayerAllowed()) {
                    currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
                    laterLayer(currentInfo, index, 0x450);
                }
            }
            break;
        case 7: {
            firstLayer(0x3a0);
            byte* currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
            uint index = weaponWord;
            laterLayer(currentInfo, index, 0x3b0);
            currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
            uint* vtable = *(uint**)audio;
            uint reference = *(uint*)(currentInfo + 0x400 + index * 4);
            dispatchSound(reference, vtable);
            break;
        }
        case 8:
        case 9: {
            uint index = (byte)weaponWord;
            uint* vtable = *(uint**)audio;
            uint offset = soundType == (EWeaponSound)8 ? 0x410 : 0x420;
            uint reference = *(uint*)(pawnRepInfo + offset + index * 4);
            dispatchSound(reference, vtable);
            break;
        }
        case 10:
            if (reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) == 6) {
                firstLayer(0x3f0);
                if (optionalLayerAllowed()) {
                    byte* currentInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
                    uint index = weaponWord;
                    laterLayer(currentInfo, index, 0x460);
                }
            } else {
                uint flags = *(uint*)(object + 0x3a0);
                uint repFlags = *(uint*)(pawnRepInfo + 0x398);
                if (((~(repFlags >> 1) & (flags >> 1)) & 1) != 0) {
                    uint recursiveWeapon = weaponWord;
                    *(uint*)(object + 0x3a0) = flags & ~2u;
                    this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)3, recursiveWeapon);
                }
            }
            break;
        }
    }
    uint flags = *(uint*)(object + 0x3a0);
    byte lastSound = (byte)soundType;
    flags |= 1;
    *(uint*)(object + 0x3a0) = flags;
    reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) = lastSound;
    ExceptionList = nativeFrame.previousExceptionList;
    __asm { mov eax,flags }
}

// R6Engine.dll @ 1003a9f1 : SoundPlayCatchPointer
// Copies the caught text at EBP-1c into the parent's EBP-18 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPlayCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003aa05 : SoundPlayCatchContext
// Reports the native weapon-playback context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPlayCatchContext(void)
{
    __asm {
        push offset nativeTextAR6WeaponsPlayWeaponSound
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003aa50 : AR6SoundReplicationInfo::PostNetReceive
// Decodes changed sound state, applies the local-controller gate, and reconciles replicated location.
void __thiscall AR6SoundReplicationInfo::PostNetReceive(void)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct PostReceiveFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundPostReceiveExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    this->AActor::PostNetReceive();
    byte* object = (byte*)this;
    byte receivedPawnState = reinterpret_cast<byte&>(this->m_NewPawnState);
    if (*(byte*)&nativeSoundReceivePawnState != receivedPawnState) {
        reinterpret_cast<byte&>(this->m_pawnState) = receivedPawnState & 15; // m_pawnState.
        reinterpret_cast<byte&>(this->m_GunSoundType) = receivedPawnState >> 4; // m_GunSoundType.
    }
    byte* pawnRepInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
    if (pawnRepInfo != nullptr) {
        byte* controller = *(byte**)(pawnRepInfo + 0x39c);
        bool suppressReplay = false;
        if (controller != nullptr) {
            UClass* classEntry = reinterpret_cast<UObject*>(controller)->Class;
            UClass* playerControllerClass = APlayerControllerPrivateStaticClassImport;
            while (classEntry != nullptr && classEntry != playerControllerClass)
                classEntry = classEntry->GetSuperClass();
            if (classEntry == playerControllerClass) { // Includes the native null/null class case.
                suppressReplay = reinterpret_cast<AController*>(controller)->LocalPlayerController() != 0;
            }
        }
        if (!suppressReplay) {
            byte currentWeapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
            byte oldWeapon = reinterpret_cast<byte&>(nativeSoundReceiveWeapon);
            if (oldWeapon != currentWeapon && reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) == 6)
                this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)10, oldWeapon);
            byte receivedSound = reinterpret_cast<byte&>(this->m_NewWeaponSound);
            if (reinterpret_cast<byte&>(nativeSoundReceiveWeaponSound) != receivedSound) {
                // Playback may replace or clear it.
                byte* currentPawnRepInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
                if (currentPawnRepInfo != nullptr && (*(byte*)(currentPawnRepInfo + 0x398) & 2) == 0) {
                    uint soundFlags = *(uint*)(object + 0x3a0);
                    uint soundType = receivedSound & 15;
                    if ((soundFlags & 1) == 0 && soundType != 6) {
                        *(uint*)(object + 0x3a0) = soundFlags | 1; // m_bInitialize.
                        reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) = (byte)soundType;
                    } else {
                        *(uint*)(object + 0x3a0) = (((uint)receivedSound >> 3 ^ soundFlags) & 2) ^ soundFlags;
                        byte weapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
                        this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)soundType, weapon);
                    }
                }
            }
        }
    }
    // Descriptive x87 loads: each coordinate and module snapshot are read only if earlier coordinates compare equal.
    uint* replicated = (uint*)(object + 0x3b4);
    auto locationWordChanged = [&](uint* current, uint* previous) {
        float10 received = (float10)*(float*)current;
        float10 saved = (float10)*(float*)previous;
        return saved != received; // FUCOMPP treats unordered as changed and signed zeros as equal.
    };
    if (locationWordChanged(replicated, (uint*)&nativeSoundReceiveLocationXWord) ||
        locationWordChanged(replicated + 1, (uint*)&nativeSoundReceiveLocationYWord) ||
        locationWordChanged(replicated + 2, (uint*)&nativeSoundReceiveLocationZWord)) {
        uint packetX = replicated[0];
        uint* location = (uint*)(object + 0x234);
        uint locationX = replicated[0];
        location[0] = locationX;
        uint locationY = replicated[1];
        uint locationZ = replicated[2];
        location[1] = locationY;
        uint packetY = replicated[1];
        uint packetZ = replicated[2];
        location[2] = locationZ;
        byte* level = reinterpret_cast<byte*&>(this->XLevel); // XLevel; separate from script-facing Level.
        uint* levelVtable = *(uint**)level;
        using UpdateLocation = int (__thiscall*)(byte*, AActor*, uint, uint, uint, uint, uint, uint, uint);
        ((UpdateLocation)levelVtable[0x9c / 4])(level, this, packetX, packetY, packetZ, 0, 0, 0, 0);
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003ac12 : SoundPostReceiveCatchPointer
// Copies the caught text from EBP-18 into the parent's EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPostReceiveCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ac26 : SoundPostReceiveCatchContext
// Reports the native post-receive context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundPostReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6SoundReplicationInfoPostNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ac50 : AR6SoundReplicationInfo::execPlayWeaponSound
// Packs a replicated sound event, applies the local-controller gate, and plays or remembers the requested sound.
void __thiscall AR6SoundReplicationInfo::execPlayWeaponSound(FFrame& stack, void* unusedResult)
{
    // Descriptive local view: native PUSH ECX keeps its lower three bytes; sound is the byte at entry ESP-1.
    uint operandWord = (uint)this;
    byte& sound = *((byte*)&operandWord + 3);
    FFrame* frame = &stack;
    byte* code = frame->Code;
    sound = 0;
    byte token = *code;
    frame->Code = code + 1;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    natives[token](receiver, &stack, &sound);
    byte* afterArgument = frame->Code + 1;
    frame->Code = afterArgument;
    if (*afterArgument == 0x42) {
        UObject* debugReceiver = frame->Object;
        frame->Code = afterArgument + 1;
        ScriptNative* debugNatives = *(ScriptNative**)&CoreGNativesImport;
        debugNatives[0x42](debugReceiver, &stack, nullptr);
    }
    byte* object = (byte*)this;
    // Captured m_PawnRepInfo survives event-byte packing.
    byte* pawnRepInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo);
    if (pawnRepInfo == nullptr) return;
    if (reinterpret_cast<byte&>(this->Role) == 4) {
        byte* level = reinterpret_cast<byte*&>(this->Level);
        if (*(byte*)(level + 0x425) != 0) {
            byte* packedSound = object + 0x395; // m_NewWeaponSound.
            byte sequence = (byte)((*packedSound >> 5) + 1);
            *packedSound = sequence;
            if (sequence > 7) *packedSound = 0;
            if (reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) == 6)
                *packedSound = (byte)((byte)(*packedSound << 1) + 1);
            else
                *packedSound = (byte)(*packedSound << 1);
            byte eventBits = *packedSound;
            byte soundBits = sound;
            // Operand overflow deliberately affects event bits.
            *packedSound = (byte)((byte)(eventBits << 4) + soundBits);
            *(uint*)(object + 0xa0) |= 0x40000000; // bNetDirty.
        }
    }
    byte* controller = *(byte**)(pawnRepInfo + 0x39c);
    if (controller != nullptr) {
        UClass* classEntry = reinterpret_cast<UObject*>(controller)->Class;
        UClass* playerControllerClass = APlayerControllerPrivateStaticClassImport;
        while (classEntry != nullptr && classEntry != playerControllerClass)
            classEntry = classEntry->GetSuperClass();
        if (classEntry == playerControllerClass) { // Includes the native null/null class case.
            if (reinterpret_cast<AController*>(controller)->LocalPlayerController() != 0) return;
        }
    }
    byte* currentLevel = reinterpret_cast<byte*&>(this->Level); // Reload after the controller callback.
    byte netMode = *(byte*)(currentLevel + 0x425);
    if (netMode == 0 || netMode == 2) {
        uint soundWord = sound;
        byte weapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
        this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)soundWord, weapon);
    }
    // Playback can alter the retained evaluator output before this final read.
    reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) = sound;
}

// R6Engine.dll @ 1003ad90 : AR6SoundReplicationInfo::StopWeaponSound
// Suppresses future full-auto replay and stops the current full-auto sound when a pawn replication record exists.
void __thiscall AR6SoundReplicationInfo::StopWeaponSound(void)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct StopWeaponSoundFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundStopWeaponSoundExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte* object = (byte*)this;
    byte* pawnRepInfo = reinterpret_cast<byte*&>(this->m_PawnRepInfo); // m_PawnRepInfo, read while guard state is -1.
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (pawnRepInfo != nullptr) {
        *(uint*)(pawnRepInfo + 0x398) |= 2; // m_bDoNotPlayFullAutoSound; full DWORD read/write.
        if (reinterpret_cast<byte&>(this->m_LastPlayedWeaponSound) == 6) {
            byte weapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
            this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)10, weapon);
        }
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003adf3 : SoundStopWeaponSoundCatchPointer
// Copies the caught text pointer at EBP-18 into the parent's EBP-14 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl SoundStopWeaponSoundCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ae07 : SoundStopWeaponSoundCatchContext
// Reports the native weapon-stop context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundStopWeaponSoundCatchContext(void)
{
    __asm {
        push offset nativeTextAR6WeaponsStopWeaponSound
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ae30 : AR6SoundReplicationInfo::execPlayLocalWeaponSound
// Evaluates a local sound byte and optional DebugInfo, then plays it with the current weapon index.
void __thiscall AR6SoundReplicationInfo::execPlayLocalWeaponSound(FFrame& stack, void* unusedResult)
{
    // Descriptive frame: caught/rethrow EBP-1c/-18, saved ESP EBP-28; sound byte EBP-11.
    struct LocalWeaponFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        uint soundWord; // Only the highest byte is initialized or used.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SoundLocalWeaponExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = &stack;
    byte* code = frame->Code;
    byte& sound = *((byte*)&nativeFrame.soundWord + 3);
    sound = 0;
    byte token = *code;
    frame->Code = code + 1;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    nativeFrame.exceptionState = 0;
    natives[token](receiver, &stack, &sound);
    byte* afterArgument = frame->Code + 1;
    frame->Code = afterArgument;
    if (*afterArgument == 0x42) {
        UObject* debugReceiver = frame->Object;
        frame->Code = afterArgument + 1;
        ScriptNative* debugNatives = *(ScriptNative**)&CoreGNativesImport;
        debugNatives[0x42](debugReceiver, &stack, nullptr);
    }
    uint soundWord = sound; // Captured before the current-weapon read.
    byte weapon = reinterpret_cast<byte&>(this->m_CurrentWeapon);
    this->AR6SoundReplicationInfo::PlayWeaponSound((EWeaponSound)soundWord, weapon);
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003aec7 : SoundLocalWeaponCatchPointer
// Copies the caught text pointer at EBP-1c into the parent's EBP-18 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl SoundLocalWeaponCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003aedb : SoundLocalWeaponCatchContext
// Reports the native local-playback context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl SoundLocalWeaponCatchContext(void)
{
    __asm {
        push offset nativeTextAR6SoundReplicationInfoExecPlayLocalWeaponSound
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003af00 : AR6SoundReplicationInfo::execStopWeaponSound
// Consumes the argument terminator and optional debug record, then stops the weapon sound.
void __thiscall AR6SoundReplicationInfo::execStopWeaponSound(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = &stack.Code;
    ++*codeCursor;
    if (**codeCursor == 0x42) {
        ++*codeCursor;
        UObject* debugReceiver = stack.Object;
        ScriptNative debugInfo = reinterpret_cast<ScriptNative*&>(CoreGNativesImport)[0x42];
        debugInfo(debugReceiver, &stack, nullptr);
    }
    this->AR6SoundReplicationInfo::StopWeaponSound();
}

// R6Engine.dll @ 10045890 : InitializeAR6SoundReplicationInfoClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6SoundReplicationInfoClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AActor object address, captured before config lookup.
    UClass* parentClass = AActorPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6SoundReplicationInfo::PrivateStaticClass, 0, 0x3c0,
        0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6SoundReplicationInfo,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6SoundReplicationInfo::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6SoundReplicationInfoClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10047f30 : DestroyAR6SoundReplicationInfoClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6SoundReplicationInfoClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6SoundReplicationInfo::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045920 : PublishAR6SoundReplicationInfoAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6SoundReplicationInfoAutoClass(void)
{
    autoclassAR6SoundReplicationInfo = &AR6SoundReplicationInfo::PrivateStaticClass;
}

// R6Engine.dll @ 10047c20 : RegisterAR6SoundReplicationInfoPlayLocalWeaponSoundNative
// Registers native index0xbb8 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6SoundReplicationInfoPlayLocalWeaponSoundNative(void)
{
    AR6SoundReplicationInfoPlayLocalWeaponSoundRegistrationResult =
        GRegisterNative(0xbb8,
            intAR6SoundReplicationInfoexecPlayLocalWeaponSound);
}

// R6Engine.dll @ 10047c40 : RegisterAR6SoundReplicationInfoStopWeaponSoundNative
// Registers native index0xaa8 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6SoundReplicationInfoStopWeaponSoundNative(void)
{
    AR6SoundReplicationInfoStopWeaponSoundRegistrationResult =
        GRegisterNative(0xaa8, intAR6SoundReplicationInfoexecStopWeaponSound);
}

// R6Engine.dll @ 10047c60 : RegisterAR6SoundReplicationInfoPlayWeaponSoundNative
// Registers native index0xaa7 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6SoundReplicationInfoPlayWeaponSoundNative(void)
{
    AR6SoundReplicationInfoPlayWeaponSoundRegistrationResult =
        GRegisterNative(0xaa7, intAR6SoundReplicationInfoexecPlayWeaponSound);
}

// R6Engine.dll @ 10044ed0 : SoundPreReceiveExceptionHandler
// Selects the exact pre-receive FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundPreReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset soundPreReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044ee0 : SoundTickExceptionHandler
// Selects the exact sound tick FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundTickExceptionHandler(void)
{
    __asm {
        mov eax,offset soundTickFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f00 : SoundPostReceiveExceptionHandler
// Selects the exact post-receive FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundPostReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset soundPostReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f10 : SoundStopWeaponSoundExceptionHandler
// Selects the exact weapon-stop FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundStopWeaponSoundExceptionHandler(void)
{
    __asm {
        mov eax,offset soundStopWeaponSoundFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f20 : SoundLocalWeaponExceptionHandler
// Selects the exact local-playback FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundLocalWeaponExceptionHandler(void)
{
    __asm {
        mov eax,offset soundLocalWeaponFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044ef0 : SoundPlayWeaponExceptionHandler
// Selects the exact weapon-playback FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl SoundPlayWeaponExceptionHandler(void)
{
    __asm {
        mov eax,offset soundPlayFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000a500 : AR6SoundReplicationInfo::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6SoundReplicationInfo::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6SoundReplicationInfoDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x3c0;
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
    this->AR6SoundReplicationInfo::~AR6SoundReplicationInfo();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x3c0;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
