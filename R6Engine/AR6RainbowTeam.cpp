#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl DestroyAR6RainbowTeamClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004dc88 : AR6RainbowTeamVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6RainbowTeam::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6RainbowTeamVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100556ca : nativeTextR6RainbowTeam
extern const ushort nativeTextR6RainbowTeam[14];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl AR6RainbowTeamDestructionExceptionHandler(void);
__declspec(naked) void __cdecl RainbowTeamDtorState0Cleanup(void);
__declspec(naked) void __cdecl RainbowTeamDtorState1Cleanup(void);

// R6Engine.dll data @ 1005832c : rainbowTeamDtorUnwind
// Retains pending array/base cleanup states, without catches.
const NativeUnwindEntry rainbowTeamDtorUnwind[2] = {
    { -1, ((uint)&RainbowTeamDtorState0Cleanup) },
    { 0, ((uint)&RainbowTeamDtorState1Cleanup) }
};

// R6Engine.dll data @ 1005833c : rainbowTeamDtorInfo
// Retains pending array/base cleanup states, without catches.
const NativeFunctionInfoPrefix rainbowTeamDtorInfo = { 0x19930520, 0x2, ((uint)&rainbowTeamDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1007e950 : autoclassAR6RainbowTeam
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6RainbowTeam = nullptr;

// R6Engine.dll @ 10009c20 : AR6RainbowTeam::eventRequestFormationChange
// Dispatches RequestFormationChange from the live incoming argument slot through the captured table.
void __thiscall AR6RainbowTeam::eventRequestFormationChange(byte eFormation)
{
    FName eventName = R6ENGINE_RequestFormationChange;
    byte inputByte = eFormation;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    eFormation = inputByte; // Upper three bytes of the incoming stack slot remain untouched.
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &eFormation, nullptr);
}

// R6Engine.dll @ 10009c60 : AR6RainbowTeam::eventUpdateTeamFormation
// Dispatches UpdateTeamFormation from the live incoming argument slot through the captured table.
void __thiscall AR6RainbowTeam::eventUpdateTeamFormation(byte eFormation)
{
    FName eventName = R6ENGINE_UpdateTeamFormation;
    byte inputByte = eFormation;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    eFormation = inputByte; // Upper three bytes of the incoming stack slot remain untouched.
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &eFormation, nullptr);
}

// R6Engine.dll @ 10009ca0 : AR6RainbowTeam::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6RainbowTeam::StaticClass(void)
{
    return &AR6RainbowTeam::PrivateStaticClass; // Selected object at0x10080810.
}

// R6Engine.dll @ 10009cb0 : AR6RainbowTeam::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6RainbowTeam::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6RainbowTeam::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10010390 : AR6RainbowTeam::operator=
// Copies team state, pointer references, raw interaction-list records and trailing geometry without retaining objects.
AR6RainbowTeam& __thiscall AR6RainbowTeam::operator=(const AR6RainbowTeam& sourceObject)
{
    const AR6RainbowTeam* source = &sourceObject;
    const AR6RainbowTeam* capturedSource = source;
    const AR6RainbowTeam* baseSourceArgument = capturedSource; // Inferred outgoing word at entryESP-0xc.
    this->AActor::operator=(*baseSourceArgument);
    this->m_bHasGrenade = capturedSource->m_bHasGrenade;
    this->m_eFormation = capturedSource->m_eFormation;
    this->m_eRequestedFormation = capturedSource->m_eRequestedFormation;
    this->m_ePlayerRoomEntry = capturedSource->m_ePlayerRoomEntry;
    this->m_eEntryGrenadeType = capturedSource->m_eEntryGrenadeType;
    this->m_eMovementMode = capturedSource->m_eMovementMode;
    this->m_eMovementSpeed = capturedSource->m_eMovementSpeed;
    this->m_ePlanAction = capturedSource->m_ePlanAction;
    this->m_eNextAPAction = capturedSource->m_eNextAPAction;
    this->m_ePlayerAPAction = capturedSource->m_ePlayerAPAction;
    this->m_eTeamState = capturedSource->m_eTeamState;
    this->m_eBackupTeamState = capturedSource->m_eBackupTeamState;
    this->m_eGoCode = capturedSource->m_eGoCode;
    this->m_eBackupGoCode = capturedSource->m_eBackupGoCode;
    this->m_iMemberCount = capturedSource->m_iMemberCount;
    this->m_iIDVoicesMgr = capturedSource->m_iIDVoicesMgr;
    this->m_iFormationDistance = capturedSource->m_iFormationDistance;
    this->m_iDiagonalDistance = capturedSource->m_iDiagonalDistance;
    this->m_iTeamHealth[0] = capturedSource->m_iTeamHealth[0];
    this->m_iTeamHealth[1] = capturedSource->m_iTeamHealth[1];
    this->m_iTeamHealth[2] = capturedSource->m_iTeamHealth[2];
    this->m_iTeamHealth[3] = capturedSource->m_iTeamHealth[3];
    this->m_iMembersLost = capturedSource->m_iMembersLost;
    this->m_iGrenadeThrower = capturedSource->m_iGrenadeThrower;
    this->m_iIntermLeader = capturedSource->m_iIntermLeader;
    this->m_iSpawnDistance = capturedSource->m_iSpawnDistance;
    this->m_iSpawnDiagDist = capturedSource->m_iSpawnDiagDist;
    this->m_iSpawnDiagOther = capturedSource->m_iSpawnDiagOther;
    this->m_iSubAction = capturedSource->m_iSubAction;
    int rainbowTeamName = capturedSource->m_iRainbowTeamName;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e8);
    uint earlyFlags = *destinationFlags; // Captured before the final two scalar stores.
    this->m_iRainbowTeamName = rainbowTeamName;
    this->m_iTeamAction = capturedSource->m_iTeamAction;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x3e8);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ firstDifference; // Native rereads destination for the first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bPlayerHasFocus.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bPlayerInGhostMode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bTeamIsClimbingLadder.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bTeamIsSeparatedFromLeader.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // m_bGrenadeInProximity.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bGasGrenadeInProximity.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bEntryInProgress.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // m_bDoorOpensTowardTeam.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bDoorOpensClockWise.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // m_bRainbowIsInFrontOfDoor.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800U; // m_bWoundedHostage.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000U; // m_bCAWaitingForZuluGoCode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000U; // m_bPreventUsingTeam.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000U; // m_bSniperReady.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000U; // m_bSkipAction.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000U; // m_bWasSeparatedFromLeader.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000U; // m_bAllTeamsHold.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000U; // m_bTeamIsHoldingPosition.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000U; // m_bSniperHold.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100000U; // m_bTeamIsRegrouping.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200000U; // m_bPlayerRequestedTeamReform.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400000U; // m_bPendingSnipeUntilGoCode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800000U; // m_bTeamIsEngagingEnemy.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000000U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000000U; // bPlanningLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000000U; // m_bFirstTimeInGas.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fEngagingTimer) = reinterpret_cast<const uint&>(capturedSource->m_fEngagingTimer);
    this->m_Team[0] = capturedSource->m_Team[0];
    this->m_Team[1] = capturedSource->m_Team[1];
    this->m_Team[2] = capturedSource->m_Team[2];
    this->m_Team[3] = capturedSource->m_Team[3];
    reinterpret_cast<uint&>(this->Colors) = reinterpret_cast<const uint&>(capturedSource->Colors);
    this->m_PlayerVoicesMgr = capturedSource->m_PlayerVoicesMgr;
    this->m_MemberVoicesMgr = capturedSource->m_MemberVoicesMgr;
    this->m_OtherTeamVoicesMgr = capturedSource->m_OtherTeamVoicesMgr;
    this->m_MultiCommonVoicesMgr = capturedSource->m_MultiCommonVoicesMgr;
    this->m_MultiCoopPlayerVoicesMgr = capturedSource->m_MultiCoopPlayerVoicesMgr;
    this->m_MultiCoopMemberVoicesMgr = capturedSource->m_MultiCoopMemberVoicesMgr;
    this->m_PreRecMsgVoicesMgr = capturedSource->m_PreRecMsgVoicesMgr;
    this->m_TeamLeader = capturedSource->m_TeamLeader;
    this->m_TeamPlanning = capturedSource->m_TeamPlanning;
    this->m_PawnControllingDoor = capturedSource->m_PawnControllingDoor;
    this->m_TeamLadder = capturedSource->m_TeamLadder;
    this->m_Door = capturedSource->m_Door;
    this->m_actionRequested = capturedSource->m_actionRequested;
    this->m_PlanActionPoint = capturedSource->m_PlanActionPoint;
    this->m_BreachingDoor = capturedSource->m_BreachingDoor;
    this->m_LastActionPoint = capturedSource->m_LastActionPoint;
    this->m_SurrenderedTerrorist = capturedSource->m_SurrenderedTerrorist;
    this->m_HostageToRescue = capturedSource->m_HostageToRescue;
    auto lastActionPoint = capturedSource->m_PlayerLastActionPoint;
    const FArray* arraySourceArgument = (const FArray*)&capturedSource->m_InteractiveObjectList;
    this->m_PlayerLastActionPoint = lastActionPoint; // Native places the array argument before this store.
    AssignRecords4((FArray*)&this->m_InteractiveObjectList, arraySourceArgument);
    reinterpret_cast<uint&>(this->m_TeamColour) = reinterpret_cast<const uint&>(capturedSource->m_TeamColour);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Pitch);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Yaw) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Yaw);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Roll);
    reinterpret_cast<uint&>(this->m_vActionLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.X);
    reinterpret_cast<uint&>(this->m_vActionLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.Y);
    reinterpret_cast<uint&>(this->m_vActionLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.Z);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.X);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.Y);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.Z);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_rSnipingDir.Pitch);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Yaw) = reinterpret_cast<const uint&>(capturedSource->m_rSnipingDir.Yaw);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_rSnipingDir.Roll);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.X);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Y);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Z);
    reinterpret_cast<uint&>(this->m_vNoiseSource.X) = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.X);
    reinterpret_cast<uint&>(this->m_vNoiseSource.Y) = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.Y);
    reinterpret_cast<uint&>(this->m_vNoiseSource.Z) = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.Z);
    return *this;
}

// R6Engine.dll @ 10013090 : AR6RainbowTeam::~AR6RainbowTeam
// Conditionally destroys UObject state, then destroys array storage and the base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6RainbowTeam::~AR6RainbowTeam(AR6RainbowTeam* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&AR6RainbowTeamDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    *(uint*)this = ((uint)&AR6RainbowTeamVirtualTable);
    guard[3] = 1;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0;
    DestroyWordArrayStorage((FArray*)&this->m_InteractiveObjectList);
    guard[3] = 0xffffffff;
    this->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10013100 : AR6RainbowTeam::AR6RainbowTeam (native default view)
// Constructs the base and publishes the derived vtable without scalar or array-header initialization.
// Keep the native ABI view: array member no-init declarations remain unresolved.
AR6RainbowTeam* __thiscall AR6RainbowTeam::AR6RainbowTeam(AR6RainbowTeam* this)
{
    AActor::AActor(this);
    *(uint*)this = ((uint)&AR6RainbowTeamVirtualTable);
    return this;
}

// R6Engine.dll @ 10013120 : AR6RainbowTeam::AR6RainbowTeam
// Copies team state, fixed member data, references, interaction storage and trailing geometry.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6RainbowTeam* __thiscall AR6RainbowTeam::AR6RainbowTeam(AR6RainbowTeam* this, const AR6RainbowTeam* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ActorBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const AR6RainbowTeam* capturedSource = source;
    const AR6RainbowTeam* baseSourceArgument = capturedSource; // Inferred outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats saved-this placement after the outgoing argument.
    AActor::AActor(this, baseSourceArgument);
    *(uint*)this = ((uint)&AR6RainbowTeamVirtualTable);
    this->m_bHasGrenade = capturedSource->m_bHasGrenade;
    this->m_eFormation = capturedSource->m_eFormation;
    this->m_eRequestedFormation = capturedSource->m_eRequestedFormation;
    this->m_ePlayerRoomEntry = capturedSource->m_ePlayerRoomEntry;
    this->m_eEntryGrenadeType = capturedSource->m_eEntryGrenadeType;
    this->m_eMovementMode = capturedSource->m_eMovementMode;
    this->m_eMovementSpeed = capturedSource->m_eMovementSpeed;
    this->m_ePlanAction = capturedSource->m_ePlanAction;
    this->m_eNextAPAction = capturedSource->m_eNextAPAction;
    this->m_ePlayerAPAction = capturedSource->m_ePlayerAPAction;
    this->m_eTeamState = capturedSource->m_eTeamState;
    this->m_eBackupTeamState = capturedSource->m_eBackupTeamState;
    this->m_eGoCode = capturedSource->m_eGoCode;
    this->m_eBackupGoCode = capturedSource->m_eBackupGoCode;
    this->m_iMemberCount = capturedSource->m_iMemberCount;
    this->m_iIDVoicesMgr = capturedSource->m_iIDVoicesMgr;
    this->m_iFormationDistance = capturedSource->m_iFormationDistance;
    this->m_iDiagonalDistance = capturedSource->m_iDiagonalDistance;
    this->m_iTeamHealth[0] = capturedSource->m_iTeamHealth[0];
    this->m_iTeamHealth[1] = capturedSource->m_iTeamHealth[1];
    this->m_iTeamHealth[2] = capturedSource->m_iTeamHealth[2];
    this->m_iTeamHealth[3] = capturedSource->m_iTeamHealth[3];
    this->m_iMembersLost = capturedSource->m_iMembersLost;
    this->m_iGrenadeThrower = capturedSource->m_iGrenadeThrower;
    this->m_iIntermLeader = capturedSource->m_iIntermLeader;
    this->m_iSpawnDistance = capturedSource->m_iSpawnDistance;
    this->m_iSpawnDiagDist = capturedSource->m_iSpawnDiagDist;
    this->m_iSpawnDiagOther = capturedSource->m_iSpawnDiagOther;
    this->m_iSubAction = capturedSource->m_iSubAction;
    int rainbowTeamName = capturedSource->m_iRainbowTeamName;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e8);
    uint earlyFlags = *destinationFlags;
    this->m_iRainbowTeamName = rainbowTeamName;
    this->m_iTeamAction = capturedSource->m_iTeamAction;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x3e8);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference;
    guard[3] = 0; // Native activates base cleanup after computing the first merge, before its store.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bPlayerHasFocus.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bPlayerInGhostMode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bTeamIsClimbingLadder.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bTeamIsSeparatedFromLeader.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // m_bGrenadeInProximity.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bGasGrenadeInProximity.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bEntryInProgress.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // m_bDoorOpensTowardTeam.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bDoorOpensClockWise.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // m_bRainbowIsInFrontOfDoor.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800U; // m_bWoundedHostage.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000U; // m_bCAWaitingForZuluGoCode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000U; // m_bPreventUsingTeam.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000U; // m_bSniperReady.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000U; // m_bSkipAction.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000U; // m_bWasSeparatedFromLeader.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000U; // m_bAllTeamsHold.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000U; // m_bTeamIsHoldingPosition.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000U; // m_bSniperHold.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100000U; // m_bTeamIsRegrouping.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200000U; // m_bPlayerRequestedTeamReform.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400000U; // m_bPendingSnipeUntilGoCode.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800000U; // m_bTeamIsEngagingEnemy.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000000U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000000U; // bPlanningLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000000U; // m_bFirstTimeInGas.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fEngagingTimer) = reinterpret_cast<const uint&>(capturedSource->m_fEngagingTimer);
    this->m_Team[0] = capturedSource->m_Team[0];
    this->m_Team[1] = capturedSource->m_Team[1];
    this->m_Team[2] = capturedSource->m_Team[2];
    this->m_Team[3] = capturedSource->m_Team[3];
    reinterpret_cast<uint&>(this->Colors) = reinterpret_cast<const uint&>(capturedSource->Colors);
    this->m_PlayerVoicesMgr = capturedSource->m_PlayerVoicesMgr;
    this->m_MemberVoicesMgr = capturedSource->m_MemberVoicesMgr;
    this->m_OtherTeamVoicesMgr = capturedSource->m_OtherTeamVoicesMgr;
    this->m_MultiCommonVoicesMgr = capturedSource->m_MultiCommonVoicesMgr;
    this->m_MultiCoopPlayerVoicesMgr = capturedSource->m_MultiCoopPlayerVoicesMgr;
    this->m_MultiCoopMemberVoicesMgr = capturedSource->m_MultiCoopMemberVoicesMgr;
    this->m_PreRecMsgVoicesMgr = capturedSource->m_PreRecMsgVoicesMgr;
    this->m_TeamLeader = capturedSource->m_TeamLeader;
    this->m_TeamPlanning = capturedSource->m_TeamPlanning;
    this->m_PawnControllingDoor = capturedSource->m_PawnControllingDoor;
    this->m_TeamLadder = capturedSource->m_TeamLadder;
    this->m_Door = capturedSource->m_Door;
    this->m_actionRequested = capturedSource->m_actionRequested;
    this->m_PlanActionPoint = capturedSource->m_PlanActionPoint;
    this->m_BreachingDoor = capturedSource->m_BreachingDoor;
    this->m_LastActionPoint = capturedSource->m_LastActionPoint;
    this->m_SurrenderedTerrorist = capturedSource->m_SurrenderedTerrorist;
    this->m_HostageToRescue = capturedSource->m_HostageToRescue;
    auto lastActionPoint = capturedSource->m_PlayerLastActionPoint;
    const FArray* arraySourceArgument = (const FArray*)&capturedSource->m_InteractiveObjectList;
    this->m_PlayerLastActionPoint = lastActionPoint; // Native places the array argument before this store.
    CopyConstructRecords4((FArray*)&this->m_InteractiveObjectList, arraySourceArgument);
    reinterpret_cast<uint&>(this->m_TeamColour) = reinterpret_cast<const uint&>(capturedSource->m_TeamColour);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Pitch);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Yaw) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Yaw);
    reinterpret_cast<uint&>(this->m_rTeamDirection.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_rTeamDirection.Roll);
    reinterpret_cast<uint&>(this->m_vActionLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.X);
    reinterpret_cast<uint&>(this->m_vActionLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.Y);
    reinterpret_cast<uint&>(this->m_vActionLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vActionLocation.Z);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.X);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.Y);
    reinterpret_cast<uint&>(this->m_vPlanActionLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPlanActionLocation.Z);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_rSnipingDir.Pitch);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Yaw) = reinterpret_cast<const uint&>(capturedSource->m_rSnipingDir.Yaw);
    reinterpret_cast<uint&>(this->m_rSnipingDir.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_rSnipingDir.Roll);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.X);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Y);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Z);
    reinterpret_cast<uint&>(this->m_vNoiseSource.X) = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.X);
    reinterpret_cast<uint&>(this->m_vNoiseSource.Y) = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.Y);
    uint lastNoiseWord = reinterpret_cast<const uint&>(capturedSource->m_vNoiseSource.Z);
    void* previousExceptionList = (void*)guard[1]; // Native reloads saved FS before the last geometry store.
    reinterpret_cast<uint&>(this->m_vNoiseSource.Z) = lastNoiseWord;
    ExceptionList = previousExceptionList;
    return this;
}

// R6Engine.dll @ 10013ae0 : AR6RainbowTeam::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6RainbowTeam::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6RainbowTeamConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10043980 : RainbowTeamDtorState0Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl RainbowTeamDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043989 : RainbowTeamDtorState1Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl RainbowTeamDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x450
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10045fa0 : InitializeAR6RainbowTeamClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6RainbowTeamClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = AActorPrivateStaticClassImport;
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
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6RainbowTeam::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload saved words after the configuration callback.
    parentClass = captures.parentClass;
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6RainbowTeam;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x4a8;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6RainbowTeam::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6RainbowTeamClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10047ff0 : DestroyAR6RainbowTeamClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6RainbowTeamClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6RainbowTeam::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046030 : PublishAR6RainbowTeamAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6RainbowTeamAutoClass(void)
{
    autoclassAR6RainbowTeam = &AR6RainbowTeam::PrivateStaticClass;
}

// R6Engine.dll @ 10043997 : AR6RainbowTeamDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl AR6RainbowTeamDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowTeamDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10013700 : AR6RainbowTeam::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6RainbowTeam::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6RainbowTeamDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x4a8;
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
    this->AR6RainbowTeam::~AR6RainbowTeam();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x4a8;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
