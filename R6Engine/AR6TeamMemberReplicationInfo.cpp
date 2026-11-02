#include "native_exported_data.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl TeamRelevantExceptionHandler(void);
__declspec(naked) void __cdecl TeamNetRelevantExceptionHandler(void);
__declspec(naked) void __cdecl TeamTickExceptionHandler(void);
__declspec(naked) void __cdecl DestroyAR6TeamMemberReplicationInfoClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// Address-only private labels retain their canonical body and inherited register/stack contracts.
// These labels are never invoked with ordinary C++ call syntax and add no implementations.
// R6Engine.dll code alias @ 1003c867 : within canonical body 1003c862
__declspec(naked) void TeamTickReportContextNativeEntry(void);
// R6Engine.dll code alias @ 1003c879 : within canonical body 1003c862
__declspec(naked) void TeamTickRethrowNativeEntry(void);

AR6PlayerController* __cdecl CastToAR6PlayerController(UObject* object);

AR6RainbowAI* __cdecl CastToAR6RainbowAI(UObject* object);

// R6Engine.dll data @ 1004bfc0 : AR6TeamMemberReplicationInfoVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6TeamMemberReplicationInfo::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6TeamMemberReplicationInfoVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10053730 : nativeTextAR6TeamMemberReplicationInfoIsNetRelevantFor
extern const ushort nativeTextAR6TeamMemberReplicationInfoIsNetRelevantFor[47];

// R6Engine.dll data @ 100536c0 : nativeTextAR6TeamMemberReplicationInfoIsRelevantToTeamMember
extern const ushort nativeTextAR6TeamMemberReplicationInfoIsRelevantToTeamMember[53];

// R6Engine.dll data @ 10053790 : nativeTextAR6TeamMemberReplicationInfoTickSpecial
extern const ushort nativeTextAR6TeamMemberReplicationInfoTickSpecial[42];

// R6Engine.dll data @ 100537e8 : nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdate
extern const ushort nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdate[56];

// R6Engine.dll data @ 10053858 : nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdateWeapon
extern const ushort nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdateWeapon[62];

// R6Engine.dll data @ 10053900 : nativeTextDIFFUSEKIT
extern const ushort nativeTextDIFFUSEKIT[11];

// R6Engine.dll data @ 100538e4 : nativeTextELECTRONICKIT
extern const ushort nativeTextELECTRONICKIT[14];

// R6Engine.dll data @ 100538d4 : nativeTextGASMASK
extern const ushort nativeTextGASMASK[8];

// R6Engine.dll data @ 10053918 : nativeTextLOCKPICKKIT
extern const ushort nativeTextLOCKPICKKIT[12];

// R6Engine.dll data @ 100539c2 : nativeTextR6TeamMemberReplicationInfo
extern const ushort nativeTextR6TeamMemberReplicationInfo[28];

// R6Engine.dll data @ 10053994 : nativeTextRGMFreeBackupAdvMode
extern const ushort nativeTextRGMFreeBackupAdvMode[22];

// R6Engine.dll data @ 10053930 : nativeTextRGMIntruderAdvMode
extern const ushort nativeTextRGMIntruderAdvMode[20];

// R6Engine.dll data @ 10053958 : nativeTextRGMVirusUploadAdvMode
extern const ushort nativeTextRGMVirusUploadAdvMode[23];

// R6Engine.dll data @ 10053988 : nativeTextSI
extern const ushort nativeTextSI[5];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl TeamMemberConstructionExceptionHandler(void);
__declspec(naked) void __cdecl TeamMemberCtorState0Cleanup(void);
__declspec(naked) void __cdecl TeamMemberCtorState1Cleanup(void);
__declspec(naked) void __cdecl TeamMemberCtorState2Cleanup(void);
__declspec(naked) void __cdecl TeamMemberCtorState3Cleanup(void);
__declspec(naked) void __cdecl TeamMemberCtorState4Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDestructionExceptionHandler(void);
__declspec(naked) void __cdecl TeamMemberDtorState0Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDtorState1Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDtorState2Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDtorState3Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDtorState4Cleanup(void);
__declspec(naked) void __cdecl TeamMemberDtorState5Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamNetRelevantCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamNetRelevantCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamRelevantCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamRelevantCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickCatchPointer(void);
__declspec(naked) void __cdecl TeamTickState10Cleanup(void);
__declspec(naked) void __cdecl TeamTickState11Cleanup(void);
__declspec(naked) void __cdecl TeamTickState12Cleanup(void);
__declspec(naked) void __cdecl TeamTickState2Cleanup(void);
__declspec(naked) void __cdecl TeamTickState3Cleanup(void);
__declspec(naked) void __cdecl TeamTickState4Cleanup(void);
__declspec(naked) void __cdecl TeamTickState5Cleanup(void);
__declspec(naked) void __cdecl TeamTickState6Cleanup(void);
__declspec(naked) void __cdecl TeamTickState9Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry0CatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry0CatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry2CatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry2CatchPointer(void);

// R6Engine.dll data @ 1005d61c : teamTickUnwindMap
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeUnwindEntry teamTickUnwindMap[17] = {
    { -1, 0 },
    { 0, 0 },
    { 0x1, ((uint)&TeamTickState2Cleanup) },
    { 0x2, ((uint)&TeamTickState3Cleanup) },
    { 0x3, ((uint)&TeamTickState4Cleanup) },
    { 0x2, ((uint)&TeamTickState5Cleanup) },
    { 0x5, ((uint)&TeamTickState6Cleanup) },
    { 0, 0 },
    { 0, 0 },
    { 0x8, ((uint)&TeamTickState9Cleanup) },
    { 0x9, ((uint)&TeamTickState10Cleanup) },
    { 0x8, ((uint)&TeamTickState11Cleanup) },
    { 0xb, ((uint)&TeamTickState12Cleanup) },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d6a4 : teamTickClientCatchMap
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeCatchEntry teamTickClientCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -80, ((uint)&TeamTickTry0CatchPointer) },
    { 0, 0, 0, ((uint)&TeamTickTry0CatchContext) }
};

// R6Engine.dll data @ 1005d6c4 : teamTickWeaponCatchMap
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeCatchEntry teamTickWeaponCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -80, ((uint)&TeamTickCatchPointer) },
    { 0, 0, 0, ((uint)&TeamTickCatchContext) }
};

// R6Engine.dll data @ 1005d6e4 : teamTickOuterCatchMap
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeCatchEntry teamTickOuterCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -88, ((uint)&TeamTickTry2CatchPointer) },
    { 0, 0, 0, ((uint)&TeamTickTry2CatchContext) }
};

// R6Engine.dll data @ 1005d704 : teamTickTryMap
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeTryBlock teamTickTryMap[3] = {
    { 0x1, 0x6, 0x7, 0x2, ((uint)&teamTickClientCatchMap) },
    { 0x8, 0xc, 0xd, 0x2, ((uint)&teamTickWeaponCatchMap) },
    { 0, 0xf, 0x10, 0x2, ((uint)&teamTickOuterCatchMap) }
};

// R6Engine.dll data @ 1005d740 : teamTickFuncInfo
// Retains the tick's exact seventeen unwind states and three nested catch regions.
const NativeFunctionInfoPrefix teamTickFuncInfo = { 0x19930520, 0x11, ((uint)&teamTickUnwindMap), 0x3,
    ((uint)&teamTickTryMap), 0 };

// R6Engine.dll data @ 1005d55c : teamRelevantUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry teamRelevantUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d56c : teamRelevantCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry teamRelevantCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TeamRelevantCatchPointer) },
    { 0, 0, 0, ((uint)&TeamRelevantCatchContext) }
};

// R6Engine.dll data @ 1005d58c : teamRelevantTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock teamRelevantTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&teamRelevantCatchMap) }
};

// R6Engine.dll data @ 1005d5a0 : teamRelevantFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix teamRelevantFuncInfo = { 0x19930520, 0x2, ((uint)&teamRelevantUnwindMap), 0x1,
    ((uint)&teamRelevantTryMap), 0 };

// R6Engine.dll data @ 1005d5bc : teamNetRelevantUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry teamNetRelevantUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d5cc : teamNetRelevantCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry teamNetRelevantCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TeamNetRelevantCatchPointer) },
    { 0, 0, 0, ((uint)&TeamNetRelevantCatchContext) }
};

// R6Engine.dll data @ 1005d5ec : teamNetRelevantTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock teamNetRelevantTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&teamNetRelevantCatchMap) }
};

// R6Engine.dll data @ 1005d600 : teamNetRelevantFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix teamNetRelevantFuncInfo = { 0x19930520, 0x2, ((uint)&teamNetRelevantUnwindMap), 0x1,
    ((uint)&teamNetRelevantTryMap), 0 };

// R6Engine.dll data @ 10056f58 : teamMemberDtorUnwind
// Destruction states retain pending strings and the AActor base.
const NativeUnwindEntry teamMemberDtorUnwind[6] = {
    { -1, ((uint)&TeamMemberDtorState0Cleanup) },
    { 0, ((uint)&TeamMemberDtorState1Cleanup) },
    { 0x1, ((uint)&TeamMemberDtorState2Cleanup) },
    { 0x2, ((uint)&TeamMemberDtorState3Cleanup) },
    { 0x3, ((uint)&TeamMemberDtorState4Cleanup) },
    { 0x4, ((uint)&TeamMemberDtorState5Cleanup) }
};

// R6Engine.dll data @ 10056f88 : teamMemberDtorInfo
// Destruction has six cleanup states and no catches.
const NativeFunctionInfoPrefix teamMemberDtorInfo = { 0x19930520, 0x6, ((uint)&teamMemberDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10056fe8 : teamMemberCtorUnwind
// Construction retains only completed strings and the AActor base.
const NativeUnwindEntry teamMemberCtorUnwind[5] = {
    { -1, ((uint)&TeamMemberCtorState0Cleanup) },
    { 0, ((uint)&TeamMemberCtorState1Cleanup) },
    { 0x1, ((uint)&TeamMemberCtorState2Cleanup) },
    { 0x2, ((uint)&TeamMemberCtorState3Cleanup) },
    { 0x3, ((uint)&TeamMemberCtorState4Cleanup) }
};

// R6Engine.dll data @ 10057010 : teamMemberCtorInfo
// Both constructors share five cleanup states and no catches.
const NativeFunctionInfoPrefix teamMemberCtorInfo = { 0x19930520, 0x5, ((uint)&teamMemberCtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10076448 : autoclassAR6TeamMemberReplicationInfo
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6TeamMemberReplicationInfo = nullptr;

// R6Engine.dll @ 10009ce0 : AR6TeamMemberReplicationInfo::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6TeamMemberReplicationInfo::StaticClass(void)
{
    return &AR6TeamMemberReplicationInfo::PrivateStaticClass; // Selected object at0x10075f40.
}

// R6Engine.dll @ 10009cf0 : AR6TeamMemberReplicationInfo::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6TeamMemberReplicationInfo::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6TeamMemberReplicationInfo::PrivateStaticClass, outer, objectName,
        objectFlags, nullptr, (FOutputDevice*)error, nullptr, 0);
        // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10009d20 : AR6TeamMemberReplicationInfo::~AR6TeamMemberReplicationInfo
// Conditionally destroys UObject state, then destroys five strings in reverse order and the AActor base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6TeamMemberReplicationInfo::~AR6TeamMemberReplicationInfo(AR6TeamMemberReplicationInfo* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TeamMemberDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6TeamMemberReplicationInfoVirtualTable);
    guard[3] = 5;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 4;
    reinterpret_cast<FStringNoInit*>(&this->m_SecondaryGadget)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 3;
    reinterpret_cast<FStringNoInit*>(&this->m_PrimaryGadget)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 2;
    reinterpret_cast<FStringNoInit*>(&this->m_SecondaryWeapon)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 1;
    reinterpret_cast<FStringNoInit*>(&this->m_PrimaryWeapon)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 0;
    reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->FStringNoInit::~FStringNoInit();
    guard[3] = 0xffffffff;
    this->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10009dd0 : AR6TeamMemberReplicationInfo::AR6TeamMemberReplicationInfo (native default view)
// Constructs the base and five no-init strings without initializing the replication scalars.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6TeamMemberReplicationInfo* __thiscall AR6TeamMemberReplicationInfo::AR6TeamMemberReplicationInfo(
    AR6TeamMemberReplicationInfo* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TeamMemberConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AActor::AActor(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6TeamMemberReplicationInfoVirtualTable);
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_CharacterName);
    *(byte*)&guard[3] = 1;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_PrimaryWeapon);
    *(byte*)&guard[3] = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_SecondaryWeapon);
    *(byte*)&guard[3] = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_PrimaryGadget);
    *(byte*)&guard[3] = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_SecondaryGadget);
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10009e70 : AR6TeamMemberReplicationInfo::AR6TeamMemberReplicationInfo (native copy view)
// Copy-constructs replication scalars, individual flags, raw location words and five strings in order.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6TeamMemberReplicationInfo* __thiscall AR6TeamMemberReplicationInfo::AR6TeamMemberReplicationInfo(
    AR6TeamMemberReplicationInfo* this, const AR6TeamMemberReplicationInfo* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TeamMemberConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AActor::AActor(this, source);
    *(uint*)this = ((uint)&AR6TeamMemberReplicationInfoVirtualTable);
    this->m_RotationYaw = source->m_RotationYaw;
    this->m_BlinkCounter = source->m_BlinkCounter;
    this->m_iTeamPosition = source->m_iTeamPosition;
    this->m_eHealth = source->m_eHealth;
    this->m_BlinkCounterOld = source->m_BlinkCounterOld;
    uint teamWord = reinterpret_cast<const uint&>(source->m_iTeam);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a4);
    uint earlyFlags = *destinationFlags; // Captured before the team words are stored.
    reinterpret_cast<uint&>(this->m_iTeam) = teamWord;
    this->m_iTeamId = source->m_iTeamId;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3a4);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ firstDifference; // Native rereads destination for this first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fLastCommunicationTime) = reinterpret_cast<const
        uint&>(source->m_fLastCommunicationTime);
    reinterpret_cast<uint&>(this->m_fClientUpdateFrequency) = reinterpret_cast<const
        uint&>(source->m_fClientUpdateFrequency);
    reinterpret_cast<uint&>(this->m_fClientLastUpdate) = reinterpret_cast<const uint&>(source->m_fClientLastUpdate);
    reinterpret_cast<uint&>(this->m_fCompteurFrameDetection) = reinterpret_cast<const
        uint&>(source->m_fCompteurFrameDetection);
    reinterpret_cast<uint&>(this->m_Location.X) = reinterpret_cast<const uint&>(source->m_Location.X);
    reinterpret_cast<uint&>(this->m_Location.Y) = reinterpret_cast<const uint&>(source->m_Location.Y);
    reinterpret_cast<uint&>(this->m_Location.Z) = reinterpret_cast<const uint&>(source->m_Location.Z);
    guard[3] = 0;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_CharacterName,
        (const FStringNoInit*)&source->m_CharacterName);
    *(byte*)&guard[3] = 1;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_PrimaryWeapon,
        (const FStringNoInit*)&source->m_PrimaryWeapon);
    *(byte*)&guard[3] = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_SecondaryWeapon,
        (const FStringNoInit*)&source->m_SecondaryWeapon);
    *(byte*)&guard[3] = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_PrimaryGadget,
        (const FStringNoInit*)&source->m_PrimaryGadget);
    *(byte*)&guard[3] = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_SecondaryGadget,
        (const FStringNoInit*)&source->m_SecondaryGadget);
    ExceptionList = (void*)guard[1];
    return this; // Ignore base/string return words; no self-assignment shortcut.
}

// R6Engine.dll @ 1000a040 : AR6TeamMemberReplicationInfo::operator=
// Assigns replication scalars, individual flags, raw location words and five strings in order.
AR6TeamMemberReplicationInfo& __thiscall AR6TeamMemberReplicationInfo::operator=(
    const AR6TeamMemberReplicationInfo& sourceObject)
{
    const AR6TeamMemberReplicationInfo* source = &sourceObject;
    this->AActor::operator=(*source);
    this->m_RotationYaw = source->m_RotationYaw;
    this->m_BlinkCounter = source->m_BlinkCounter;
    this->m_iTeamPosition = source->m_iTeamPosition;
    this->m_eHealth = source->m_eHealth;
    this->m_BlinkCounterOld = source->m_BlinkCounterOld;
    uint teamWord = reinterpret_cast<const uint&>(source->m_iTeam);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a4);
    uint earlyFlags = *destinationFlags; // Captured before the team words are stored.
    reinterpret_cast<uint&>(this->m_iTeam) = teamWord;
    this->m_iTeamId = source->m_iTeamId;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3a4);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ firstDifference; // Native rereads destination for this first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U;
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fLastCommunicationTime) = reinterpret_cast<const
        uint&>(source->m_fLastCommunicationTime);
    reinterpret_cast<uint&>(this->m_fClientUpdateFrequency) = reinterpret_cast<const
        uint&>(source->m_fClientUpdateFrequency);
    reinterpret_cast<uint&>(this->m_fClientLastUpdate) = reinterpret_cast<const uint&>(source->m_fClientLastUpdate);
    reinterpret_cast<uint&>(this->m_fCompteurFrameDetection) = reinterpret_cast<const
        uint&>(source->m_fCompteurFrameDetection);
    reinterpret_cast<uint&>(this->m_Location.X) = reinterpret_cast<const uint&>(source->m_Location.X);
    reinterpret_cast<uint&>(this->m_Location.Y) = reinterpret_cast<const uint&>(source->m_Location.Y);
    reinterpret_cast<uint&>(this->m_Location.Z) = reinterpret_cast<const uint&>(source->m_Location.Z);
    reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_CharacterName));
    reinterpret_cast<FStringNoInit*>(&this->m_PrimaryWeapon)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_PrimaryWeapon));
    reinterpret_cast<FStringNoInit*>(&this->m_SecondaryWeapon)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_SecondaryWeapon));
    reinterpret_cast<FStringNoInit*>(&this->m_PrimaryGadget)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_PrimaryGadget));
    reinterpret_cast<FStringNoInit*>(&this->m_SecondaryGadget)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_SecondaryGadget));
    return *this; // Ignore base/string return words; no self-assignment shortcut.
}

// R6Engine.dll @ 1000dfd0 : AR6TeamMemberReplicationInfo::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6TeamMemberReplicationInfo::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6TeamMemberReplicationInfoConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1003bef0 : AR6TeamMemberReplicationInfo::IsRelevantToTeamMember
// Requires a controlled pawn and normalizes the instigator's native friendship test to zero or one.
int __thiscall AR6TeamMemberReplicationInfo::IsRelevantToTeamMember(APawn* pawn)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct RelevancyFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TeamRelevantExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    APawn* candidate = pawn;
    APawn* instigator = this->Instigator; // Instigator is captured even for a null candidate.
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    int result = 0;
    if (candidate != nullptr && candidate->Controller != nullptr) {
        result = instigator->APawn::IsFriend(candidate) != 0 ? 1 : 0;
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return result;
}

// R6Engine.dll @ 1003bf52 : TeamRelevantCatchPointer
// Copies the caught text from EBP-18 into the parent's EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TeamRelevantCatchPointer(void)
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

// R6Engine.dll @ 1003bf66 : TeamRelevantCatchContext
// Reports the native relevancy context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl TeamRelevantCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TeamMemberReplicationInfoIsRelevantToTeamMember
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003bfa0 : AR6TeamMemberReplicationInfo::IsNetRelevantFor
// Tests the controller pawn, or the second pawn-view result from its current view target.
int __thiscall AR6TeamMemberReplicationInfo::IsNetRelevantFor(APlayerController* player, AActor* unusedActor,
    uint unusedViewX, uint unusedViewY, uint unusedViewZ)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct RelevancyFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TeamNetRelevantExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    APawn* pawn = player->Pawn;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    int result = 0;
    if (pawn != nullptr) {
        result = this->AR6TeamMemberReplicationInfo::IsRelevantToTeamMember(pawn);
    } else {
        AActor* viewTarget = player->ViewTarget;
        if (viewTarget != nullptr) {
            if (viewTarget->GetPlayerPawn() != nullptr) {
                viewTarget = player->ViewTarget;
                pawn = viewTarget->GetPlayerPawn(); // A second call, not the first returned pointer.
                result = this->AR6TeamMemberReplicationInfo::IsRelevantToTeamMember(pawn);
            }
        }
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return result;
}

// R6Engine.dll @ 1003c012 : TeamNetRelevantCatchPointer
// Copies the caught text from EBP-18 into the parent's EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TeamNetRelevantCatchPointer(void)
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

// R6Engine.dll @ 1003c026 : TeamNetRelevantCatchContext
// Reports the native relevancy context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl TeamNetRelevantCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TeamMemberReplicationInfoIsNetRelevantFor
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003c060 : AR6TeamMemberReplicationInfo::TickSpecial
// Refreshes the instigator's team, name and equipment snapshot, then maintains the communication blink timer.
void __thiscall AR6TeamMemberReplicationInfo::TickSpecial(float deltaTime)
{
    // Descriptive 32-bit frame/header views; the format region's extent is inferred from adjacent native slots.
    struct TeamTickFrame {
        uint savedEDI, savedESI, savedEBX;
        ushort formatBuffer[32]; // EBP-98..-59; appSprintf retains its native unchecked writes.
        uint outerCaught, clientRethrow, innerCaught, weaponRethrow, outerRethrow;
        uint temporaryB[3], temporaryA[3], name[3]; // EBP-44/-38/-2c: raw twelve-byte FString headers.
        byte* rainbowAI;
        uint primaryPresent, secondaryPresent, liveMask;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TeamTickExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    uint baseDeltaWord = reinterpret_cast<uint&>(deltaTime);
    uint liveMask = 0;
    nativeFrame.savedEsp = &nativeFrame.savedEDI; // EBP-a4.
    nativeFrame.liveMask = liveMask;
    nativeFrame.exceptionState = 0;
    nativeFrame.rainbowAI = nullptr;
    nativeFrame.primaryPresent = 0;
    nativeFrame.secondaryPresent = 0;
    this->AActor::TickSpecial(reinterpret_cast<const float&>(baseDeltaWord));
    byte* object = (byte*)this;
    byte* level = reinterpret_cast<byte*&>(this->Level);
    byte netMode = *(byte*)(level + 0x425);
    if (netMode == 2 || netMode == 1) {
        // FST32 spills the accumulator without replacing the extended value used by FCOMP.
        float10 elapsed = (float10)deltaTime + (float10)this->m_fClientLastUpdate;
        this->m_fClientLastUpdate = (float)elapsed;
        if (elapsed > (float10)this->m_fClientUpdateFrequency) {
            byte* instigator = reinterpret_cast<byte*&>(this->Instigator);
            *(byte*)&nativeFrame.exceptionState = 1;
            if (instigator == nullptr) {
                ExceptionList = nativeFrame.previousExceptionList;
                return;
            }
            byte* classEntry = *(byte**)(instigator + 0x24);
            while (classEntry != nullptr && classEntry != (byte*)&AR6Rainbow::PrivateStaticClass)
                classEntry = *(byte**)(classEntry + 0x2c);
            if (classEntry == nullptr) {
                ExceptionList = nativeFrame.previousExceptionList;
                return;
            }
            // Descriptive local call views retain current imports and returned constructor buffers.
            auto copyString = [&](uint* destination, const uint* source) {
                return reinterpret_cast<uint*>(::new (reinterpret_cast<void*>(destination)) FString(
                    *reinterpret_cast<const FString*>(source)));
            };
            auto emptyString = [&](uint* destination) {
                return reinterpret_cast<uint*>(::new (reinterpret_cast<void*>(destination)) FString);
            };
            auto destroyString = [&](uint* string) {
                reinterpret_cast<FString*>(string)->FString::~FString();
            };
            auto assignName = [&](const uint* source) {
                reinterpret_cast<FString*>(nativeFrame.name)->operator=(*reinterpret_cast<const FString*>(source));
            };
            auto assignString = [&](uint* destination, const uint* source) {
                reinterpret_cast<FStringNoInit*>(destination)->operator=(*reinterpret_cast<const FString*>(source));
            };
            auto assignText = [&](uint* destination, const ushort* source) {
                reinterpret_cast<FStringNoInit*>(destination)->operator=(source);
            };
            auto modeMatches = [&](const ushort* mode) {
                byte* currentLevel = reinterpret_cast<byte*&>(this->Level);
                byte* game = *(byte**)(currentLevel + 0x4cc);
                return reinterpret_cast<const FString*>(game + 0x4b0)->operator==(mode);
            };
            uint* position = (uint*)(instigator + 0x234);
            *(uint*)(object + 0x3b8) = position[0];
            *(uint*)(object + 0x3bc) = position[1];
            *(uint*)(object + 0x3c0) = position[2];
            reinterpret_cast<byte&>(this->m_RotationYaw) = (byte)(*(int*)(instigator + 0x244) >> 8); // m_RotationYaw.
            reinterpret_cast<uint&>(this->m_iTeam) = *(uint*)(instigator + 0x3b0); // m_iTeam.
            // Pawn m_iID low byte -> m_iTeamPosition.
            reinterpret_cast<byte&>(this->m_iTeamPosition) = *(byte*)(instigator + 0x68c);
            byte* replicationInfo = *(byte**)(instigator + 0x518);
            const uint* initialName = replicationInfo != nullptr ? (uint*)(replicationInfo + 0x408) :
                (uint*)(instigator + 0x630);
            copyString(nativeFrame.name, initialName);
            byte teamPosition = reinterpret_cast<byte&>(this->m_iTeamPosition);
            *(byte*)&nativeFrame.exceptionState = 2;
            if (teamPosition == 0) {
                assignString((uint*)(object + 0x3c4), nativeFrame.name);
            } else {
                int freeBackup = modeMatches(nativeTextRGMFreeBackupAdvMode);
                AController* controller = reinterpret_cast<APawn*>(instigator)->Controller;
                if (freeBackup != 0) {
                    if (controller != nullptr) {
                        nativeFrame.rainbowAI = (byte*)CastToAR6RainbowAI(controller);
                        byte* pawn = *(byte**)(nativeFrame.rainbowAI + 0x3d8); // No null-cast guard.
                        uint* returned;
                        if (pawn != nullptr) {
                            returned = copyString(nativeFrame.temporaryA, (const uint*)(pawn + 0x630));
                            *(byte*)&nativeFrame.exceptionState = 3;
                            liveMask |= 1;
                        } else {
                            returned = emptyString(nativeFrame.temporaryB);
                            nativeFrame.exceptionState = 4;
                            liveMask |= 2;
                        }
                        nativeFrame.liveMask = liveMask;
                        assignName(returned);
                        nativeFrame.exceptionState = 3;
                        if ((liveMask & 2) != 0) {
                            liveMask &= ~2u;
                            nativeFrame.liveMask = liveMask;
                            destroyString(nativeFrame.temporaryB);
                        }
                        nativeFrame.exceptionState = 2;
                        if ((liveMask & 1) != 0) {
                            liveMask &= ~1u;
                            nativeFrame.liveMask = liveMask;
                            destroyString(nativeFrame.temporaryA);
                        }
                    }
                    const ushort* nameText = reinterpret_cast<const FString*>(nativeFrame.name)->operator*();
                    appSprintf(nativeFrame.formatBuffer, unwindStringFormat, nameText);
                    assignText((uint*)(object + 0x3c4), nativeFrame.formatBuffer);
                } else {
                    if (controller != nullptr) {
                        nativeFrame.rainbowAI = (byte*)CastToAR6RainbowAI(controller);
                        byte* manager = nativeFrame.rainbowAI != nullptr ?
                            *(byte**)(nativeFrame.rainbowAI + 0x59c) : nullptr;
                        byte* teamPawn = manager != nullptr ? *(byte**)(manager + 0x3f0) : nullptr;
                        byte* pawnInfo = teamPawn != nullptr ? *(byte**)(teamPawn + 0x518) : nullptr;
                        if (pawnInfo != nullptr) {
                            assignName((uint*)(pawnInfo + 0x408));
                        } else {
                            byte* pawn = *(byte**)(nativeFrame.rainbowAI + 0x3d8); // Native null-AI read.
                            uint* returned;
                            if (pawn != nullptr) {
                                returned = copyString(nativeFrame.temporaryB, (const uint*)(pawn + 0x630));
                                *(byte*)&nativeFrame.exceptionState = 5;
                                liveMask |= 4;
                            } else {
                                returned = emptyString(nativeFrame.temporaryA);
                                nativeFrame.exceptionState = 6;
                                liveMask |= 8;
                            }
                            nativeFrame.liveMask = liveMask;
                            assignName(returned);
                            nativeFrame.exceptionState = 5;
                            if ((liveMask & 8) != 0) {
                                liveMask &= ~8u;
                                nativeFrame.liveMask = liveMask;
                                destroyString(nativeFrame.temporaryA);
                            }
                            nativeFrame.exceptionState = 2;
                            if ((liveMask & 4) != 0) {
                                liveMask &= ~4u;
                                nativeFrame.liveMask = liveMask;
                                destroyString(nativeFrame.temporaryB);
                            }
                        }
                    }
                    const ushort* nameText = reinterpret_cast<const FString*>(nativeFrame.name)->operator*();
                    uint currentPosition = reinterpret_cast<byte&>(this->m_iTeamPosition);
                    appSprintf(nativeFrame.formatBuffer, nativeTextSI, nameText, currentPosition);
                    assignText((uint*)(object + 0x3c4), nativeFrame.formatBuffer);
                }
            }
            reinterpret_cast<byte&>(this->m_eHealth) = *(byte*)(instigator + 0x3a2); // m_eHealth.
            byte* currentInfo = *(byte**)(instigator + 0x518);
            uint pilot = currentInfo != nullptr ? (*(uint*)(currentInfo + 0x3ec) >> 9) & 1 : 0;
            uint flags = *(uint*)(object + 0x3a4);
            flags ^= ((pilot << 2) ^ flags) & 4;
            *(uint*)(object + 0x3a4) = flags;
            uint dataFlags = *(uint*)(instigator + 0xa50);
            flags ^= ((dataFlags << 4) ^ flags) & 0x10;
            *(uint*)(object + 0x3a4) = flags;
            if (*(byte**)(instigator + 0x4ec) != nullptr && modeMatches(nativeTextRGMVirusUploadAdvMode) != 0) {
                byte* currentController = *(byte**)(instigator + 0x4ec);
                reinterpret_cast<uint&>(this->m_fCompteurFrameDetection) = *(uint*)(currentController + 0x844);
            }
            if (modeMatches(nativeTextRGMIntruderAdvMode) != 0) {
                uint intruder = *(uint*)(instigator + 0xa50);
                uint currentFlags = *(uint*)(object + 0x3a4);
                currentFlags ^= ((intruder << 2) ^ currentFlags) & 8;
                *(uint*)(object + 0x3a4) = currentFlags;
            }
            uint actorFlags = *(uint*)(object + 0xa0) | 0x40000000;
            reinterpret_cast<uint&>(this->m_fClientLastUpdate) = 0;
            *(uint*)(object + 0xa0) = actorFlags;
            *(byte*)&nativeFrame.exceptionState = 1;
            destroyString(nativeFrame.name);
            byte* primaryWeapon = *(byte**)(instigator + 0x504);
            nativeFrame.exceptionState = 0;
            *(byte*)&nativeFrame.exceptionState = 8;
            uint* primaryText;
            if (primaryWeapon != nullptr) {
                primaryText = copyString(nativeFrame.temporaryB, (const uint*)(primaryWeapon + 0x488));
                *(byte*)&nativeFrame.exceptionState = 9;
                liveMask |= 0x10;
            } else {
                primaryText = emptyString(nativeFrame.temporaryA);
                nativeFrame.exceptionState = 10;
                liveMask |= 0x20;
            }
            nativeFrame.liveMask = liveMask;
            assignString((uint*)(object + 0x3d0), primaryText);
            nativeFrame.exceptionState = 9;
            if ((liveMask & 0x20) != 0) {
                liveMask &= ~0x20u;
                nativeFrame.liveMask = liveMask;
                destroyString(nativeFrame.temporaryA);
            }
            nativeFrame.exceptionState = 8;
            if ((liveMask & 0x10) != 0) {
                liveMask &= ~0x10u;
                nativeFrame.liveMask = liveMask;
                destroyString(nativeFrame.temporaryB);
            }
            byte* secondaryWeapon = *(byte**)(instigator + 0x508);
            uint* secondaryText;
            if (secondaryWeapon != nullptr) {
                secondaryText = copyString(nativeFrame.temporaryB, (const uint*)(secondaryWeapon + 0x488));
                *(byte*)&nativeFrame.exceptionState = 11;
                liveMask |= 0x40;
            } else {
                secondaryText = emptyString(nativeFrame.temporaryA);
                nativeFrame.exceptionState = 12;
                liveMask |= 0x80;
            }
            nativeFrame.liveMask = liveMask;
            assignString((uint*)(object + 0x3dc), secondaryText);
            nativeFrame.exceptionState = 11;
            if ((liveMask & 0x80) != 0) {
                liveMask &= ~0x80u;
                nativeFrame.liveMask = liveMask;
                destroyString(nativeFrame.temporaryA);
            }
            nativeFrame.exceptionState = 8;
            if ((liveMask & 0x40) != 0) destroyString(nativeFrame.temporaryB); // Native leaves this mask bit set.
            for (uint slot = 0; slot != 2; ++slot) {
                // Descriptive factoring of two ordered gadget blocks; neither clears a pre-existing empty bit.
                byte* gadget = *(byte**)(instigator + (slot == 0 ? 0x50c : 0x510));
                if (gadget != nullptr) {
                    if (*(byte*)(gadget + 0x396) == 0) { // m_iNbBulletsInWeapon.
                        *(uint*)(object + 0x3a4) |= slot == 0 ? 1 : 2;
                    } else {
                        reinterpret_cast<FStringNoInit*>(object + (slot == 0 ? 0x3e8 : 0x3f4))->operator=(
                            *reinterpret_cast<const FStringNoInit*>(gadget + 0x488));
                    }
                    (slot == 0 ? nativeFrame.primaryPresent : nativeFrame.secondaryPresent) = 1;
                }
            }
            auto addKit = [&](const ushort* label) {
                if (nativeFrame.primaryPresent == 0) {
                    assignText((uint*)(object + 0x3e8), label);
                    nativeFrame.primaryPresent = 1;
                } else if (nativeFrame.secondaryPresent == 0) {
                    assignText((uint*)(object + 0x3f4), label);
                    nativeFrame.secondaryPresent = 1;
                }
            };
            if ((*(byte*)(instigator + 0xa50) & 8) != 0) addKit(nativeTextLOCKPICKKIT);
            if ((*(byte*)(instigator + 0xa50) & 0x10) != 0) addKit(nativeTextDIFFUSEKIT);
            if ((*(byte*)(instigator + 0xa50) & 0x20) != 0) addKit(nativeTextELECTRONICKIT);
            bool primaryGasMask = false;
            if ((*(uint*)(instigator + 0x3e4) & 0x20000) != 0) {
                if (nativeFrame.primaryPresent == 0) {
                    assignText((uint*)(object + 0x3e8), nativeTextGASMASK);
                    primaryGasMask = true; // Native skips the primary empty-flag write without setting primaryPresent.
                } else if (nativeFrame.secondaryPresent == 0) {
                    assignText((uint*)(object + 0x3f4), nativeTextGASMASK);
                    nativeFrame.secondaryPresent = 1;
                }
            }
            if (!primaryGasMask && nativeFrame.primaryPresent == 0) *(uint*)(object + 0x3a4) |= 1;
            if (nativeFrame.secondaryPresent == 0) *(uint*)(object + 0x3a4) |= 2;
            if (reinterpret_cast<uint&>(this->m_iTeamId) == 0xffffffff) {
                AController* controller = reinterpret_cast<APawn*>(instigator)->Controller;
                if (controller != nullptr) {
                    if (nativeFrame.rainbowAI != nullptr) {
                        reinterpret_cast<uint&>(this->m_iTeamId) = *(uint*)(nativeFrame.rainbowAI + 0x59c);
                        ExceptionList = nativeFrame.previousExceptionList;
                        return;
                    }
                    byte* playerController = (byte*)CastToAR6PlayerController(controller);
                    if (playerController != nullptr) {
                        reinterpret_cast<uint&>(this->m_iTeamId) = *(uint*)(playerController + 0x8ac);
                        ExceptionList = nativeFrame.previousExceptionList;
                        return;
                    }
                }
            }
        }
    }
    byte blinkCounter = reinterpret_cast<byte&>(this->m_BlinkCounter);
    if (blinkCounter != reinterpret_cast<byte&>(this->m_BlinkCounterOld)) {
        reinterpret_cast<byte&>(this->m_BlinkCounterOld) = blinkCounter;
        reinterpret_cast<uint&>(this->m_fLastCommunicationTime) = 0x40b00000; // Restart at5.5f.
    } else {
        float10 timer = (float10)this->m_fLastCommunicationTime;
        float10 zero = (float10)nativeFloatZero;
        if (timer > zero) {
            float10 remaining = (float10)this->m_fLastCommunicationTime - (float10)deltaTime;
            float10 cutoff = (float10)nativeFloatZero;
            bool expiredOrUnordered = !(remaining >= cutoff); // Native FCOM C0 includes unordered.
            this->m_fLastCommunicationTime = (float)remaining;
            if (expiredOrUnordered) remaining = (float10)nativeFloatZero;
            void* previousChain = nativeFrame.previousExceptionList;
            this->m_fLastCommunicationTime = (float)remaining;
            ExceptionList = previousChain;
            return;
        }
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003c78d : TeamTickCatchPointer
// Copies caught text from EBP-50 into the inherited EBP-4c rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x50]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x4c]
        mov dword ptr [ebp-0x4c],ecx
        push edx
        jmp TeamTickRethrowNativeEntry
    }
}

// R6Engine.dll @ 1003c7ab : TeamTickTry0CatchPointer
// Copies caught text from EBP-50 into the inherited EBP-54 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry0CatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x50]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x54]
        mov dword ptr [ebp-0x54],eax
        push ecx
        jmp TeamTickRethrowNativeEntry
    }
}

// R6Engine.dll @ 1003c84e : TeamTickTry2CatchPointer
// Copies caught text from EBP-58 into the inherited EBP-48 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry2CatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x58]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x48]
        push eax
        mov dword ptr [ebp-0x48],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100432f0 : TeamMemberDtorState0Cleanup
// Destroys the saved AActor base through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 100432f9 : TeamMemberDtorState1Cleanup
// Destroys saved m_CharacterName through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043308 : TeamMemberDtorState2Cleanup
// Destroys saved m_PrimaryWeapon through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3d0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043317 : TeamMemberDtorState3Cleanup
// Destroys saved m_SecondaryWeapon through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3dc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043326 : TeamMemberDtorState4Cleanup
// Destroys saved m_PrimaryGadget through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3e8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043335 : TeamMemberDtorState5Cleanup
// Destroys saved m_SecondaryGadget through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDtorState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3f4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043350 : TeamMemberCtorState0Cleanup
// Destroys the saved AActor base through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberCtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043359 : TeamMemberCtorState1Cleanup
// Destroys saved m_CharacterName through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberCtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043368 : TeamMemberCtorState2Cleanup
// Destroys saved m_PrimaryWeapon through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberCtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3d0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043377 : TeamMemberCtorState3Cleanup
// Destroys saved m_SecondaryWeapon through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberCtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3dc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043386 : TeamMemberCtorState4Cleanup
// Destroys saved m_PrimaryGadget through the inherited dispatcher frame.
__declspec(naked) void __cdecl TeamMemberCtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3e8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10044fe0 : TeamTickState2Cleanup
// Destroys the tick's active name string at parent EBP-2c through the current FString destructor.
__declspec(naked) void __cdecl TeamTickState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044fe9 : TeamTickState3Cleanup
// Clears lifetime bit01 at parent EBP-14 before destroying the string at EBP-38.
__declspec(naked) void __cdecl TeamTickState3Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x1
        je done
        and dword ptr [ebp-0x14],0xfffffffe
        lea ecx,[ebp-0x38]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 10045003 : TeamTickState4Cleanup
// Clears lifetime bit02 at parent EBP-14 before destroying the string at EBP-44.
__declspec(naked) void __cdecl TeamTickState4Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x2
        je done
        and dword ptr [ebp-0x14],0xfffffffd
        lea ecx,[ebp-0x44]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 1004501d : TeamTickState5Cleanup
// Clears lifetime bit04 at parent EBP-14 before destroying the string at EBP-44.
__declspec(naked) void __cdecl TeamTickState5Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x4
        je done
        and dword ptr [ebp-0x14],0xfffffffb
        lea ecx,[ebp-0x44]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 10045037 : TeamTickState6Cleanup
// Clears lifetime bit08 at parent EBP-14 before destroying the string at EBP-38.
__declspec(naked) void __cdecl TeamTickState6Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x8
        je done
        and dword ptr [ebp-0x14],0xfffffff7
        lea ecx,[ebp-0x38]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 10045051 : TeamTickState9Cleanup
// Clears lifetime bit10 at parent EBP-14 before destroying the string at EBP-44.
__declspec(naked) void __cdecl TeamTickState9Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x10
        je done
        and dword ptr [ebp-0x14],0xffffffef
        lea ecx,[ebp-0x44]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 1004506b : TeamTickState10Cleanup
// Clears lifetime bit20 at parent EBP-14 before destroying the string at EBP-38.
__declspec(naked) void __cdecl TeamTickState10Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x20
        je done
        and dword ptr [ebp-0x14],0xffffffdf
        lea ecx,[ebp-0x38]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 10045085 : TeamTickState11Cleanup
// Clears lifetime bit40 at parent EBP-14 before destroying the string at EBP-44.
__declspec(naked) void __cdecl TeamTickState11Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x40
        je done
        and dword ptr [ebp-0x14],0xffffffbf
        lea ecx,[ebp-0x44]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 1004509f : TeamTickState12Cleanup
// Clears lifetime bit80 at parent EBP-14 before destroying the string at EBP-38.
__declspec(naked) void __cdecl TeamTickState12Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x80
        je done
        and byte ptr [ebp-0x14],0x7f
        lea ecx,[ebp-0x38]
        jmp dword ptr [FStringDestructorImport]
    done:
        ret
    }
}

// R6Engine.dll @ 1003c7a1 : TeamTickCatchContext
// Selects the weapon update diagnostic and enters the shared report/throw suffix at3c867.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdateWeapon
        jmp TeamTickReportContextNativeEntry
    }
}

// R6Engine.dll @ 1003c7bf : TeamTickTry0CatchContext
// Selects the client update diagnostic and enters the shared report/throw suffix at3c867.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry0CatchContext(void)
{
    __asm {
        push offset nativeTextAR6TeamMemberReplicationInfoTickSpecialClientUpdate
        jmp TeamTickReportContextNativeEntry
    }
}

// R6Engine.dll @ 1003c862 : TeamTickTry2CatchContext
// Reports the outer tick context; its report and throw suffixes at3c867/3c879 also serve nested catches.
__declspec(naked) __declspec(noreturn) void __cdecl TeamTickTry2CatchContext(void)
{
    __asm {
        push offset nativeTextAR6TeamMemberReplicationInfoTickSpecial
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045930 : InitializeAR6TeamMemberReplicationInfoClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6TeamMemberReplicationInfoClassMetadata(void)
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
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6TeamMemberReplicationInfo::PrivateStaticClass, 0,
        0x400, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6TeamMemberReplicationInfo,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6TeamMemberReplicationInfo::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6TeamMemberReplicationInfoClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10047f40 : DestroyAR6TeamMemberReplicationInfoClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6TeamMemberReplicationInfoClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6TeamMemberReplicationInfo::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100459c0 : PublishAR6TeamMemberReplicationInfoAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6TeamMemberReplicationInfoAutoClass(void)
{
    autoclassAR6TeamMemberReplicationInfo = &AR6TeamMemberReplicationInfo::PrivateStaticClass;
}

// R6Engine.dll @ 10043344 : TeamMemberDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl TeamMemberDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset teamMemberDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043395 : TeamMemberConstructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl TeamMemberConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset teamMemberCtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044fc0 : TeamRelevantExceptionHandler
// Selects the exact relevancy FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl TeamRelevantExceptionHandler(void)
{
    __asm {
        mov eax,offset teamRelevantFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044fd0 : TeamNetRelevantExceptionHandler
// Selects the exact relevancy FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl TeamNetRelevantExceptionHandler(void)
{
    __asm {
        mov eax,offset teamNetRelevantFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100450bb : TeamTickExceptionHandler
// Selects the exact tick FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl TeamTickExceptionHandler(void)
{
    __asm {
        mov eax,offset teamTickFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000a1c0 : AR6TeamMemberReplicationInfo::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6TeamMemberReplicationInfo::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6TeamMemberReplicationInfoDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x400;
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
    this->AR6TeamMemberReplicationInfo::~AR6TeamMemberReplicationInfo();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x400;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll @ 1002ba70 : return the object if its class chain contains AR6PlayerController
AR6PlayerController* __cdecl CastToAR6PlayerController(UObject* object)
{
    if (object == nullptr)
        return nullptr;
    UClass* classCursor = object->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6PlayerController::PrivateStaticClass)
            return static_cast<AR6PlayerController*>(object);
        classCursor = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(classCursor) + 0x2c);
    }
    return nullptr;
}

// R6Engine.dll @ 1002baa0 : return the object if its class chain contains AR6RainbowAI
AR6RainbowAI* __cdecl CastToAR6RainbowAI(UObject* object)
{
    if (object == nullptr)
        return nullptr;
    UClass* classCursor = object->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6RainbowAI::PrivateStaticClass)
            return static_cast<AR6RainbowAI*>(object);
        classCursor = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(classCursor) + 0x2c);
    }
    return nullptr;
}
