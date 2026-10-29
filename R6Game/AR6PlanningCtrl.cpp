#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 1001807c : BSP vertical trace half-length
const float PlanningBspTraceHalfLength = 65535.0f;

// R6Game.dll data @ 100180b0 : mesh/terrain vertical trace half-length
const float PlanningVerticalTraceHalfLength = 10000.0f;

// R6Game.dll data @ 10018108 : click-picking pick-ray scale
const float PlanningPickRayLength = 100000.0f;

// R6Game.dll data @ 1001810c : click-picking screen Y center
const float PlanningScreenCenterY = 240.0f;

// R6Game.dll data @ 10018110 : click-picking screen X center
const float PlanningScreenCenterX = 320.0f;

// R6Game.dll data @ 10018114 : click-picking FOV projection factor
const float PlanningClickFovScale = 0.06666667014360428f;

// R6Game.dll data @ 10024138 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6PlanningCtrl::execGetClickResult.
unsigned int intAR6PlanningCtrlexecGetClickResult = R6GameAddresses::AR6PlanningCtrl_execGetClickResult;

// R6Game.dll data @ 1002413c : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6PlanningCtrl::execGetXYPoint.
unsigned int intAR6PlanningCtrlexecGetXYPoint = R6GameAddresses::AR6PlanningCtrl_execGetXYPoint;

// R6Game.dll data @ 10024140 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6PlanningCtrl::execPlanningTrace.
unsigned int intAR6PlanningCtrlexecPlanningTrace = R6GameAddresses::AR6PlanningCtrl_execPlanningTrace;

// R6Game.dll data @ 10024bd8 : native registration result byte
unsigned char AR6PlanningCtrlexecGetXYPointRegistrationResult = 0;

// R6Game.dll data @ 100250e9 : native registration result byte
unsigned char AR6PlanningCtrlexecGetClickResultRegistrationResult = 0;

// R6Game.dll data @ 10026028 : auto-class pointer
UClass* autoclassAR6PlanningCtrl = nullptr;

// R6Game.dll data @ 1002602e : native registration result byte
unsigned char AR6PlanningCtrlexecPlanningTraceRegistrationResult = 0;

// R6Game.dll data @ 10027458 : class metadata storage
// Backing storage for AR6PlanningCtrl::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6PlanningCtrlClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 10019fdc : native C++ unwind-state transitions
const unsigned int AR6PlanningCtrl_DestructUnwindMap[2] = {
    0xffffffff, R6GameAddresses::AR6PlanningCtrl_DestructUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 10019fe4 : native C++ exception function descriptor
const unsigned int AR6PlanningCtrl_DestructExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::AR6PlanningCtrl_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b0e4 : native C++ unwind-state transitions
const unsigned int AR6PlanningCtrl_execPlanningTraceUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b0f4 : native typed-pointer and catch-all handler pair
const unsigned int AR6PlanningCtrl_execPlanningTraceCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6PlanningCtrl_execPlanningTraceCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6PlanningCtrl_execPlanningTraceCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b114 : native C++ try-block ranges
const unsigned int AR6PlanningCtrl_execPlanningTraceTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6PlanningCtrl_execPlanningTraceCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b128 : native C++ exception function descriptor
const unsigned int AR6PlanningCtrl_execPlanningTraceExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6PlanningCtrl_execPlanningTraceUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6PlanningCtrl_execPlanningTraceTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b144 : native C++ unwind-state transitions
const unsigned int AR6PlanningCtrl_execGetXYPointUnwindMap[8] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6PlanningCtrl_execGetXYPointUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6PlanningCtrl_execGetXYPointUnwind2, // State 2: previous state, cleanup action.
    0xffffffff, 0x0, // State 3: previous state, cleanup action.
};

// R6Game.dll data @ 1001b164 : native typed-pointer and catch-all handler pair
const unsigned int AR6PlanningCtrl_execGetXYPointCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff94, R6GameAddresses::AR6PlanningCtrl_execGetXYPointCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6PlanningCtrl_execGetXYPointCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b184 : native C++ try-block ranges
const unsigned int AR6PlanningCtrl_execGetXYPointTryMap[5] = {
    0x0, 0x2, 0x3, 0x2, R6GameAddresses::AR6PlanningCtrl_execGetXYPointCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b198 : native C++ exception function descriptor
const unsigned int AR6PlanningCtrl_execGetXYPointExceptionInfo[7] = {
    0x19930520, 0x4, R6GameAddresses::AR6PlanningCtrl_execGetXYPointUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6PlanningCtrl_execGetXYPointTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b1b4 : native C++ unwind-state transitions
const unsigned int AR6PlanningCtrl_execGetClickResultUnwindMap[8] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6PlanningCtrl_execGetClickResultUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6PlanningCtrl_execGetClickResultUnwind2, // State 2: previous state, cleanup action.
    0xffffffff, 0x0, // State 3: previous state, cleanup action.
};

// R6Game.dll data @ 1001b1d4 : native typed-pointer and catch-all handler pair
const unsigned int AR6PlanningCtrl_execGetClickResultCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff38, R6GameAddresses::AR6PlanningCtrl_execGetClickResultCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6PlanningCtrl_execGetClickResultCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b1f4 : native C++ try-block ranges
const unsigned int AR6PlanningCtrl_execGetClickResultTryMap[5] = {
    0x0, 0x2, 0x3, 0x2, R6GameAddresses::AR6PlanningCtrl_execGetClickResultCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b208 : native C++ exception function descriptor
const unsigned int AR6PlanningCtrl_execGetClickResultExceptionInfo[7] = {
    0x19930520, 0x4, R6GameAddresses::AR6PlanningCtrl_execGetClickResultUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6PlanningCtrl_execGetClickResultTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016958 : AR6PlanningCtrl virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6PlanningCtrl_vftable[105] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6PlanningCtrl_VectorDeletingDestructor, // +0xc: AR6PlanningCtrl::VectorDeletingDestructor
    R6GameAddresses::ForwardImported_AActor_ProcessEvent, // +0x10: AActor::ProcessEvent
    R6GameAddresses::ForwardImported_UObject_ProcessDelegate, // +0x14: UObject::ProcessDelegate
    R6GameAddresses::ForwardImported_AActor_ProcessState, // +0x18: AActor::ProcessState
    R6GameAddresses::ForwardImported_AActor_ProcessRemoteFunction, // +0x1c: AActor::ProcessRemoteFunction
    R6GameAddresses::ForwardImported_UObject_Modify, // +0x20: UObject::Modify
    R6GameAddresses::ForwardImported_AActor_PostLoad, // +0x24: AActor::PostLoad
    R6GameAddresses::ForwardImported_AActor_Destroy, // +0x28: AActor::Destroy
    R6GameAddresses::ForwardImported_AActor_Serialize, // +0x2c: AActor::Serialize
    R6GameAddresses::ForwardImported_AActor_IsPendingKill, // +0x30: AActor::IsPendingKill
    R6GameAddresses::ForwardImported_UObject_GotoState, // +0x34: UObject::GotoState
    R6GameAddresses::ForwardImported_UObject_GotoLabel, // +0x38: UObject::GotoLabel
    R6GameAddresses::ForwardImported_AActor_InitExecution, // +0x3c: AActor::InitExecution
    R6GameAddresses::ForwardImported_UObject_ShutdownAfterError, // +0x40: UObject::ShutdownAfterError
    R6GameAddresses::ForwardImported_AActor_PostEditChange, // +0x44: AActor::PostEditChange
    R6GameAddresses::ForwardImported_UObject_CallFunction, // +0x48: UObject::CallFunction
    R6GameAddresses::ForwardImported_UObject_ScriptConsoleExec, // +0x4c: UObject::ScriptConsoleExec
    R6GameAddresses::ForwardImported_UObject_Register, // +0x50: UObject::Register
    R6GameAddresses::ForwardImported_UObject_LanguageChange, // +0x54: UObject::LanguageChange
    R6GameAddresses::ForwardImported_AActor_IsPendingDelete, // +0x58: AActor::IsPendingDelete
    R6GameAddresses::ForwardImported_UObject_GetPropertiesSize, // +0x5c: UObject::GetPropertiesSize
    R6GameAddresses::ForwardImported_AActor_NetDirty, // +0x60: AActor::NetDirty
    R6GameAddresses::ForwardImported_APlayerController_GetOptimizedRepList, // +0x64: APlayerController::GetOptimizedRepList
    R6GameAddresses::ForwardImported_AActor_GetPlayerPawn, // +0x68: AActor::GetPlayerPawn
    R6GameAddresses::ForwardImported_AActor_GetPawnOrColBoxOwner, // +0x6c: AActor::GetPawnOrColBoxOwner
    R6GameAddresses::ForwardImported_AActor_IsBlockedBy, // +0x70: AActor::IsBlockedBy
    R6GameAddresses::ForwardImported_AActor_GetNetPriority, // +0x74: AActor::GetNetPriority
    R6GameAddresses::ForwardImported_AActor_WorldLightRadius, // +0x78: AActor::WorldLightRadius
    R6GameAddresses::ForwardImported_APlayerController_Tick, // +0x7c: APlayerController::Tick
    R6GameAddresses::ForwardImported_AActor_PostEditMove, // +0x80: AActor::PostEditMove
    R6GameAddresses::ForwardImported_AActor_PostEditLoad, // +0x84: AActor::PostEditLoad
    R6GameAddresses::ForwardImported_AActor_PreRaytrace, // +0x88: AActor::PreRaytrace
    R6GameAddresses::ForwardImported_AActor_PostRaytrace, // +0x8c: AActor::PostRaytrace
    R6GameAddresses::ForwardImported_AActor_Spawned, // +0x90: AActor::Spawned
    R6GameAddresses::ForwardImported_APlayerController_PreNetReceive, // +0x94: APlayerController::PreNetReceive
    R6GameAddresses::ForwardImported_APlayerController_PostNetReceive, // +0x98: APlayerController::PostNetReceive
    R6GameAddresses::ForwardImported_AActor_PostNetReceiveLocation, // +0x9c: AActor::PostNetReceiveLocation
    R6GameAddresses::ForwardImported_AActor_GetSkin, // +0xa0: AActor::GetSkin
    R6GameAddresses::ForwardImported_AActor_ToLocal, // +0xa4: AActor::ToLocal
    R6GameAddresses::ForwardImported_AActor_ToWorld, // +0xa8: AActor::ToWorld
    R6GameAddresses::ForwardImported_AActor_LocalToWorld, // +0xac: AActor::LocalToWorld
    R6GameAddresses::ForwardImported_AActor_WorldToLocal, // +0xb0: AActor::WorldToLocal
    R6GameAddresses::ForwardImported_AActor_UpdateColBox, // +0xb4: AActor::UpdateColBox
    R6GameAddresses::ForwardImported_AActor_PostScriptDestroyed, // +0xb8: AActor::PostScriptDestroyed
    R6GameAddresses::ForwardImported_AActor_ShouldTrace, // +0xbc: AActor::ShouldTrace
    R6GameAddresses::ForwardImported_AActor_GetPrimitive, // +0xc0: AActor::GetPrimitive
    R6GameAddresses::ForwardImported_AActor_BeginTouch, // +0xc4: AActor::BeginTouch
    R6GameAddresses::ForwardImported_AActor_IsMovingBrush, // +0xc8: AActor::IsMovingBrush
    R6GameAddresses::ForwardImported_AActor_NotifyBump, // +0xcc: AActor::NotifyBump
    R6GameAddresses::ForwardImported_AActor_SetBase, // +0xd0: AActor::SetBase
    R6GameAddresses::ForwardImported_AActor_GetViewRotation, // +0xd4: AActor::GetViewRotation
    R6GameAddresses::ForwardImported_AActor_NotifyAnimEnd, // +0xd8: AActor::NotifyAnimEnd
    R6GameAddresses::ForwardImported_AActor_UpdateAnimation, // +0xdc: AActor::UpdateAnimation
    R6GameAddresses::ForwardImported_AController_StartAnimPoll, // +0xe0: AController::StartAnimPoll
    R6GameAddresses::ForwardImported_AController_CheckAnimFinished, // +0xe4: AController::CheckAnimFinished
    R6GameAddresses::ForwardImported_AActor_UpdateTimers, // +0xe8: AActor::UpdateTimers
    R6GameAddresses::ForwardImported_AActor_CheckOwnerUpdated, // +0xec: AActor::CheckOwnerUpdated
    R6GameAddresses::ForwardImported_AActor_TickAuthoritative, // +0xf0: AActor::TickAuthoritative
    R6GameAddresses::ForwardImported_AActor_TickSimulated, // +0xf4: AActor::TickSimulated
    R6GameAddresses::ForwardImported_AActor_TickSpecial, // +0xf8: AActor::TickSpecial
    R6GameAddresses::ForwardImported_AActor_PlayerControlled, // +0xfc: AActor::PlayerControlled
    R6GameAddresses::ForwardImported_APlayerController_IsNetRelevantFor, // +0x100: APlayerController::IsNetRelevantFor
    R6GameAddresses::ForwardImported_AActor_RenderEditorInfo, // +0x104: AActor::RenderEditorInfo
    R6GameAddresses::ForwardImported_AActor_RenderEditorSelected, // +0x108: AActor::RenderEditorSelected
    R6GameAddresses::ForwardImported_AActor_SetZone, // +0x10c: AActor::SetZone
    R6GameAddresses::ForwardImported_AActor_SetVolumesFromList, // +0x110: AActor::SetVolumes
    R6GameAddresses::ForwardImported_AActor_SetVolumes, // +0x114: AActor::SetVolumes
    R6GameAddresses::ForwardImported_AActor_PostBeginPlay, // +0x118: AActor::PostBeginPlay
    R6GameAddresses::ForwardImported_AActor_setPhysics, // +0x11c: AActor::setPhysics
    R6GameAddresses::ForwardImported_AActor_performPhysics, // +0x120: AActor::performPhysics
    R6GameAddresses::ForwardImported_AActor_BoundProjectileVelocity, // +0x124: AActor::BoundProjectileVelocity
    R6GameAddresses::ForwardImported_AActor_processHitWall, // +0x128: AActor::processHitWall
    R6GameAddresses::ForwardImported_AActor_processLanded, // +0x12c: AActor::processLanded
    R6GameAddresses::ForwardImported_AActor_physFalling, // +0x130: AActor::physFalling
    R6GameAddresses::ForwardImported_AActor_FindSlopeRotation, // +0x134: AActor::FindSlopeRotation
    R6GameAddresses::ForwardImported_AActor_SmoothHitWall, // +0x138: AActor::SmoothHitWall
    R6GameAddresses::ForwardImported_AActor_stepUp, // +0x13c: AActor::stepUp
    R6GameAddresses::ForwardImported_AActor_getKModel, // +0x140: AActor::getKModel
    R6GameAddresses::ForwardImported_AActor_physKarma, // +0x144: AActor::physKarma
    R6GameAddresses::ForwardImported_AActor_preKarmaStep, // +0x148: AActor::preKarmaStep
    R6GameAddresses::ForwardImported_AActor_postKarmaStep, // +0x14c: AActor::postKarmaStep
    R6GameAddresses::ForwardImported_AActor_KMP2DynKarmaInterface, // +0x150: AActor::KMP2DynKarmaInterface
    R6GameAddresses::ForwardImported_AActor_AddMyMarker, // +0x154: AActor::AddMyMarker
    R6GameAddresses::ForwardImported_AActor_AssociatedLevelGeometry, // +0x158: AActor::AssociatedLevelGeometry
    R6GameAddresses::ForwardImported_AActor_HasAssociatedLevelGeometry, // +0x15c: AActor::HasAssociatedLevelGeometry
    R6GameAddresses::ForwardImported_AActor_PlayAnim, // +0x160: AActor::PlayAnim
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnRadar, // +0x164: AActor::IsRelevantToPawnRadar
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnHeatVision, // +0x168: AActor::IsRelevantToPawnHeatVision
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnHeartBeat, // +0x16c: AActor::IsRelevantToPawnHeartBeat
    R6GameAddresses::ForwardImported_AActor_TickThisFrame, // +0x170: AActor::TickThisFrame
    R6GameAddresses::ForwardImported_AActor_CheckForErrors, // +0x174: AActor::CheckForErrors
    R6GameAddresses::ForwardImported_AActor_PrePath, // +0x178: AActor::PrePath
    R6GameAddresses::ForwardImported_AActor_PostPath, // +0x17c: AActor::PostPath
    R6GameAddresses::ForwardImported_AActor_GetProjectorBase, // +0x180: AActor::GetProjectorBase
    R6GameAddresses::ForwardImported_AController_CanHear, // +0x184: AController::CanHear
    R6GameAddresses::ForwardImported_APlayerController_CheckHearSound, // +0x188: APlayerController::CheckHearSound
    R6GameAddresses::ForwardImported_APlayerController_GetViewTarget, // +0x18c: APlayerController::GetViewTarget
    R6GameAddresses::ForwardImported_AController_AcceptNearbyPath, // +0x190: AController::AcceptNearbyPath
    R6GameAddresses::ForwardImported_AController_AdjustFromWall, // +0x194: AController::AdjustFromWall
    R6GameAddresses::ForwardImported_AController_SetAdjustLocation, // +0x198: AController::SetAdjustLocation
    R6GameAddresses::ForwardImported_APlayerController_LocalPlayerController, // +0x19c: APlayerController::LocalPlayerController
    R6GameAddresses::ForwardImported_AController_GetTeamManager, // +0x1a0: AController::GetTeamManager
};

// R6Game.dll @ 10001a10 : return the AR6PlanningCtrl class object
UClass* __cdecl AR6PlanningCtrl::StaticClass(void)
{
    return (UClass*)AR6PlanningCtrlClassMetadataStorage;
}

// R6Game.dll @ 10001a20 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6PlanningCtrl::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6PlanningCtrlClassMetadataStorage, outer, objectName, objectFlags, nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10001a50 : conditionally shut down the object, then destroy its PlayerController base
void __thiscall AR6PlanningCtrl::~AR6PlanningCtrl(AR6PlanningCtrl* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6PlanningCtrlExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native frame -0x10 saves this; FuncInfo 0x10019fe4 maps state 0 to AR6PlanningCtrl_DestructUnwind.
    *(const uint**)this = AR6PlanningCtrl_vftable;
    exceptionRegistration.state = 0;
    UObject::ConditionalDestroy((UObject*)this);
    exceptionRegistration.state = -1;
    APlayerController::~APlayerController((APlayerController*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10001ab0 : construct the PlayerController base and install the planning-controller vtable
AR6PlanningCtrl* __thiscall AR6PlanningCtrl::AR6PlanningCtrl(AR6PlanningCtrl* this)
{
    APlayerController::APlayerController((APlayerController*)this);
    *(const uint**)this = AR6PlanningCtrl_vftable;
    return this;
}

// R6Game.dll @ 10001ad0 : copy-construct inherited state and members
// Copies the base, view/camera state and object references; preserves unnamed bits at +0x800.
AR6PlanningCtrl * __thiscall AR6PlanningCtrl::AR6PlanningCtrl(AR6PlanningCtrl *this, const AR6PlanningCtrl *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x800);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x800);
  uint copiedFlags;

  APlayerController::APlayerController((APlayerController *)this, (const APlayerController *)source);
  *(const uint**)this = AR6PlanningCtrl_vftable;
  this->m_iCurrentTeam = source->m_iCurrentTeam; // +0x7e8.
  this->m_3DWindowPositionX = source->m_3DWindowPositionX; // +0x7ec.
  this->m_3DWindowPositionY = source->m_3DWindowPositionY; // +0x7f0.
  this->m_3DWindowPositionW = source->m_3DWindowPositionW; // +0x7f4.
  this->m_3DWindowPositionH = source->m_3DWindowPositionH; // +0x7f8.
  this->m_iLevelDisplay = source->m_iLevelDisplay; // +0x7fc.
  // Copy bits 0..10 separately; bits 11..31 keep their destination values.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bRender3DView.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bMove3DView.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bActionPointSelected.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bCanMoveFirstPoint.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bClickToFindLocation.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bClickedOnRange.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bSetSnipeDirection.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bPlayMode.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bLockCamera.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200; // bShowLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bFirstTick.
  *destinationFlags = copiedFlags;
  this->m_fLastMouseX = source->m_fLastMouseX; // +0x804.
  this->m_fLastMouseY = source->m_fLastMouseY; // +0x808.
  this->m_fZoom = source->m_fZoom; // +0x80c.
  this->m_fZoomDelta = source->m_fZoomDelta; // +0x810.
  this->m_fZoomRate = source->m_fZoomRate; // +0x814.
  this->m_fZoomMin = source->m_fZoomMin; // +0x818.
  this->m_fZoomMax = source->m_fZoomMax; // +0x81c.
  this->m_fZoomFactor = source->m_fZoomFactor; // +0x820.
  this->m_fCameraAngle = source->m_fCameraAngle; // +0x824.
  this->m_fAngleRate = source->m_fAngleRate; // +0x828.
  this->m_fAngleMax = source->m_fAngleMax; // +0x82c.
  this->m_fRotateDelta = source->m_fRotateDelta; // +0x830.
  this->m_fRotateRate = source->m_fRotateRate; // +0x834.
  this->m_fCamRate = source->m_fCamRate; // +0x838.
  this->m_fCastingHeight = source->m_fCastingHeight; // +0x83c.
  this->m_fDebugRangeScale = source->m_fDebugRangeScale; // +0x840.
  this->m_pTeamInfo[0] = source->m_pTeamInfo[0]; // +0x844.
  this->m_pTeamInfo[1] = source->m_pTeamInfo[1]; // +0x848.
  this->m_pTeamInfo[2] = source->m_pTeamInfo[2]; // +0x84c.
  this->m_pFileManager = source->m_pFileManager; // +0x850.
  this->m_pCameraDirIcon = source->m_pCameraDirIcon; // +0x854.
  this->m_pOldHitActor = source->m_pOldHitActor; // +0x858.
  for (uint iconIndex = 0; iconIndex < 12; ++iconIndex)
    this->m_pIconTex[iconIndex] = source->m_pIconTex[iconIndex]; // +0x85c..+0x888, forward copy.
  this->m_CamSpot = source->m_CamSpot; // +0x88c.
  this->m_PlanningBadClickSnd = source->m_PlanningBadClickSnd; // +0x890.
  this->m_PlanningGoodClickSnd = source->m_PlanningGoodClickSnd; // +0x894.
  this->m_PlanningRemoveSnd = source->m_PlanningRemoveSnd; // +0x898.
  this->m_vCurrentCameraPos.X = source->m_vCurrentCameraPos.X; // +0x89c.
  this->m_vCurrentCameraPos.Y = source->m_vCurrentCameraPos.Y; // +0x8a0.
  this->m_vCurrentCameraPos.Z = source->m_vCurrentCameraPos.Z; // +0x8a4.
  this->m_vCamPos.X = source->m_vCamPos.X; // +0x8a8.
  this->m_vCamPos.Y = source->m_vCamPos.Y; // +0x8ac.
  this->m_vCamPos.Z = source->m_vCamPos.Z; // +0x8b0.
  this->m_vCamPosNoRot.X = source->m_vCamPosNoRot.X; // +0x8b4.
  this->m_vCamPosNoRot.Y = source->m_vCamPosNoRot.Y; // +0x8b8.
  this->m_vCamPosNoRot.Z = source->m_vCamPosNoRot.Z; // +0x8bc.
  this->m_vCamDesiredPos.X = source->m_vCamDesiredPos.X; // +0x8c0.
  this->m_vCamDesiredPos.Y = source->m_vCamDesiredPos.Y; // +0x8c4.
  this->m_vCamDesiredPos.Z = source->m_vCamDesiredPos.Z; // +0x8c8.
  this->m_rCamRot.Pitch = source->m_rCamRot.Pitch; // +0x8cc.
  this->m_rCamRot.Yaw = source->m_rCamRot.Yaw; // +0x8d0.
  this->m_rCamRot.Roll = source->m_rCamRot.Roll; // +0x8d4.
  this->m_vCamDelta.X = source->m_vCamDelta.X; // +0x8d8.
  this->m_vCamDelta.Y = source->m_vCamDelta.Y; // +0x8dc.
  this->m_vCamDelta.Z = source->m_vCamDelta.Z; // +0x8e0.
  this->m_vMinLocation.X = source->m_vMinLocation.X; // +0x8e4.
  this->m_vMinLocation.Y = source->m_vMinLocation.Y; // +0x8e8.
  this->m_vMinLocation.Z = source->m_vMinLocation.Z; // +0x8ec.
  this->m_vMaxLocation.X = source->m_vMaxLocation.X; // +0x8f0.
  this->m_vMaxLocation.Y = source->m_vMaxLocation.Y; // +0x8f4.
  this->m_vMaxLocation.Z = source->m_vMaxLocation.Z; // +0x8f8.
  return this;
}

// R6Game.dll @ 10001e50 : assign inherited state and members
// Assigns the base, view/camera state and object references; preserves unnamed bits at +0x800.
AR6PlanningCtrl * __thiscall AR6PlanningCtrl::operator=(AR6PlanningCtrl *this, const AR6PlanningCtrl *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x800);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x800);
  uint copiedFlags;

  APlayerController::operator=((APlayerController *)this, (const APlayerController *)source);
  this->m_iCurrentTeam = source->m_iCurrentTeam; // +0x7e8.
  this->m_3DWindowPositionX = source->m_3DWindowPositionX; // +0x7ec.
  this->m_3DWindowPositionY = source->m_3DWindowPositionY; // +0x7f0.
  this->m_3DWindowPositionW = source->m_3DWindowPositionW; // +0x7f4.
  this->m_3DWindowPositionH = source->m_3DWindowPositionH; // +0x7f8.
  this->m_iLevelDisplay = source->m_iLevelDisplay; // +0x7fc.
  // Copy bits 0..10 separately; bits 11..31 keep their destination values.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bRender3DView.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bMove3DView.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bActionPointSelected.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bCanMoveFirstPoint.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bClickToFindLocation.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bClickedOnRange.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bSetSnipeDirection.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bPlayMode.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bLockCamera.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200; // bShowLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bFirstTick.
  *destinationFlags = copiedFlags;
  this->m_fLastMouseX = source->m_fLastMouseX; // +0x804.
  this->m_fLastMouseY = source->m_fLastMouseY; // +0x808.
  this->m_fZoom = source->m_fZoom; // +0x80c.
  this->m_fZoomDelta = source->m_fZoomDelta; // +0x810.
  this->m_fZoomRate = source->m_fZoomRate; // +0x814.
  this->m_fZoomMin = source->m_fZoomMin; // +0x818.
  this->m_fZoomMax = source->m_fZoomMax; // +0x81c.
  this->m_fZoomFactor = source->m_fZoomFactor; // +0x820.
  this->m_fCameraAngle = source->m_fCameraAngle; // +0x824.
  this->m_fAngleRate = source->m_fAngleRate; // +0x828.
  this->m_fAngleMax = source->m_fAngleMax; // +0x82c.
  this->m_fRotateDelta = source->m_fRotateDelta; // +0x830.
  this->m_fRotateRate = source->m_fRotateRate; // +0x834.
  this->m_fCamRate = source->m_fCamRate; // +0x838.
  this->m_fCastingHeight = source->m_fCastingHeight; // +0x83c.
  this->m_fDebugRangeScale = source->m_fDebugRangeScale; // +0x840.
  this->m_pTeamInfo[0] = source->m_pTeamInfo[0]; // +0x844.
  this->m_pTeamInfo[1] = source->m_pTeamInfo[1]; // +0x848.
  this->m_pTeamInfo[2] = source->m_pTeamInfo[2]; // +0x84c.
  this->m_pFileManager = source->m_pFileManager; // +0x850.
  this->m_pCameraDirIcon = source->m_pCameraDirIcon; // +0x854.
  this->m_pOldHitActor = source->m_pOldHitActor; // +0x858.
  for (uint iconIndex = 0; iconIndex < 12; ++iconIndex)
    this->m_pIconTex[iconIndex] = source->m_pIconTex[iconIndex]; // +0x85c..+0x888, forward copy.
  this->m_CamSpot = source->m_CamSpot; // +0x88c.
  this->m_PlanningBadClickSnd = source->m_PlanningBadClickSnd; // +0x890.
  this->m_PlanningGoodClickSnd = source->m_PlanningGoodClickSnd; // +0x894.
  this->m_PlanningRemoveSnd = source->m_PlanningRemoveSnd; // +0x898.
  this->m_vCurrentCameraPos.X = source->m_vCurrentCameraPos.X; // +0x89c.
  this->m_vCurrentCameraPos.Y = source->m_vCurrentCameraPos.Y; // +0x8a0.
  this->m_vCurrentCameraPos.Z = source->m_vCurrentCameraPos.Z; // +0x8a4.
  this->m_vCamPos.X = source->m_vCamPos.X; // +0x8a8.
  this->m_vCamPos.Y = source->m_vCamPos.Y; // +0x8ac.
  this->m_vCamPos.Z = source->m_vCamPos.Z; // +0x8b0.
  this->m_vCamPosNoRot.X = source->m_vCamPosNoRot.X; // +0x8b4.
  this->m_vCamPosNoRot.Y = source->m_vCamPosNoRot.Y; // +0x8b8.
  this->m_vCamPosNoRot.Z = source->m_vCamPosNoRot.Z; // +0x8bc.
  this->m_vCamDesiredPos.X = source->m_vCamDesiredPos.X; // +0x8c0.
  this->m_vCamDesiredPos.Y = source->m_vCamDesiredPos.Y; // +0x8c4.
  this->m_vCamDesiredPos.Z = source->m_vCamDesiredPos.Z; // +0x8c8.
  this->m_rCamRot.Pitch = source->m_rCamRot.Pitch; // +0x8cc.
  this->m_rCamRot.Yaw = source->m_rCamRot.Yaw; // +0x8d0.
  this->m_rCamRot.Roll = source->m_rCamRot.Roll; // +0x8d4.
  this->m_vCamDelta.X = source->m_vCamDelta.X; // +0x8d8.
  this->m_vCamDelta.Y = source->m_vCamDelta.Y; // +0x8dc.
  this->m_vCamDelta.Z = source->m_vCamDelta.Z; // +0x8e0.
  this->m_vMinLocation.X = source->m_vMinLocation.X; // +0x8e4.
  this->m_vMinLocation.Y = source->m_vMinLocation.Y; // +0x8e8.
  this->m_vMinLocation.Z = source->m_vMinLocation.Z; // +0x8ec.
  this->m_vMaxLocation.X = source->m_vMaxLocation.X; // +0x8f0.
  this->m_vMaxLocation.Y = source->m_vMaxLocation.Y; // +0x8f4.
  this->m_vMaxLocation.Z = source->m_vMaxLocation.Z; // +0x8f8.
  return this;
}

// R6Game.dll @ 100021d0 : destroy one planning controller or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6PlanningCtrl::VectorDeletingDestructor(AR6PlanningCtrl* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x8fc, elementCount,
            (_func_void_void_ptr*)AR6PlanningCtrl::~AR6PlanningCtrl);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6PlanningCtrl::~AR6PlanningCtrl(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x8fc);
    return this;
}

// R6Game.dll @ 10003e60 : construct a planning controller in supplied memory when nonnull
void __cdecl AR6PlanningCtrl::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        AR6PlanningCtrl::AR6PlanningCtrl((AR6PlanningCtrl*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 100080a0 : execPlanningTrace
// Calls the level line check with the evaluated planning vectors and returns its DWORD result.
void __thiscall AR6PlanningCtrl::execPlanningTrace(AR6PlanningCtrl* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6PlanningCtrl_PlanningTraceExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; both states have no local cleanup actions.
    __writefsdword(0, (uint)&exceptionRegistration);
    FVector vTraceEnd;
    byte* endCode = *codeCursor;
    byte endOpcode = *endCode;
    *codeCursor = (byte*)((uint)endCode + 1U);
    ScriptNative* endNativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* endContext = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    endNativeTable[endOpcode](endContext, stack, &vTraceEnd);
    FVector vTraceStart;
    byte* startCode = *codeCursor;
    byte startOpcode = *startCode;
    UObject* startContext = *(UObject**)((byte*)stack + 8);
    *codeCursor = (byte*)((uint)startCode + 1U);
    ScriptNative* startNativeTable = (ScriptNative*)ImportedGNativesAddress;
    startNativeTable[startOpcode](startContext, stack, &vTraceStart);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, stack, nullptr);
    }
    APawn* pawn = this->Pawn;
    alignas(4) byte hitStorage[48];
    FCheckResult* hit = (FCheckResult*)hitStorage;
    const FVector* extentSource = (const FVector*)ImportedVectorZeroAddress;
    *(uint*)((byte*)hit + 0x2c) = 0; // Only this hit word is initialized before the call.
    uint extentX = *(const uint*)&extentSource->X;
    ULevel* level = pawn->XLevel;
    byte* levelVtable = *(byte**)level;
    uint extentY = *(const uint*)&extentSource->Y;
    uint extentZ = *(const uint*)&extentSource->Z;
    FVector extent;
    *(uint*)&extent.X = extentX;
    *(uint*)&extent.Y = extentY;
    *(uint*)&extent.Z = extentZ;
    using LineTrace = int (__thiscall *)(ULevel*, FCheckResult*, AActor*, const FVector*,
        const FVector*, uint, FVector);
    LineTrace trace = *(LineTrace*)(levelVtable + 0xcc);
    // The native call passes the second evaluated vector before the first.
    uint traceResult = (uint)trace(level, hit, (AActor*)pawn, &vTraceStart, &vTraceEnd, 0x84, extent);
    *(uint*)result = traceResult;
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10008185 : rethrow PlanningTrace's caught UTF-16 pointer value
__declspec(naked) void AR6PlanningCtrl_execPlanningTraceCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10008199 : report PlanningTrace context and rethrow the active exception
__declspec(naked) void AR6PlanningCtrl_execPlanningTraceCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6PlanningCtrl_execPlanningTraceExceptionContext // L"AR6PlanningCtrl::execPlanningTrace"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100081c0 : execGetXYPoint
// Projects planning-screen coordinates onto the horizontal plane at the requested height.
void __thiscall AR6PlanningCtrl::execGetXYPoint(AR6PlanningCtrl* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6PlanningCtrl_GetXYPointExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native scene/canvas storage is at frame -0x24c/-0xef4; saved ESP is at -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* xCode = *codeCursor;
    float X = 0.0f;
    byte xOpcode = *xCode;
    *codeCursor = (byte*)((uint)xCode + 1U);
    ScriptNative* xNativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* xContext = *(UObject**)((byte*)executionStack + 8);
    exceptionRegistration.state = 0;
    xNativeTable[xOpcode](xContext, executionStack, &X);
    byte* yCode = *codeCursor;
    UObject* yContext = *(UObject**)((byte*)executionStack + 8);
    float& Y = *(float*)&stack; // The retained frame frees its incoming DWORD for the Y output.
    Y = 0.0f;
    byte yOpcode = *yCode;
    *codeCursor = (byte*)((uint)yCode + 1U);
    ScriptNative* yNativeTable = (ScriptNative*)ImportedGNativesAddress;
    yNativeTable[yOpcode](yContext, executionStack, &Y);
    byte* heightCode = *codeCursor;
    UObject* heightContext = *(UObject**)((byte*)executionStack + 8);
    float Height = 0.0f;
    byte heightOpcode = *heightCode;
    *codeCursor = (byte*)((uint)heightCode + 1U);
    ScriptNative* heightNativeTable = (ScriptNative*)ImportedGNativesAddress;
    heightNativeTable[heightOpcode](heightContext, executionStack, &Height);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, executionStack, nullptr);
    }
    alignas(4) byte sceneStorage[0x1e0], canvasStorage[0xca8];
    FCameraSceneNode* scene = (FCameraSceneNode*)sceneStorage;
    FCanvasUtil* canvas = (FCanvasUtil*)canvasStorage;
    float cameraFOV;
    *(uint*)&cameraFOV = *(uint*)&this->FovAngle;
    UViewport* sceneViewport = (UViewport*)this->Player;
    FRotator cameraRotation;
    cameraRotation.Pitch = this->m_rCamRot.Pitch;
    cameraRotation.Yaw = this->m_rCamRot.Yaw;
    cameraRotation.Roll = this->m_rCamRot.Roll;
    FVector* cameraPosition = &this->m_vCurrentCameraPos;
    FVector cameraLocation;
    *(uint*)&cameraLocation.X = *(uint*)&cameraPosition->X;
    *(uint*)&cameraLocation.Y = *(uint*)&cameraPosition->Y;
    *(uint*)&cameraLocation.Z = *(uint*)&cameraPosition->Z;
    FCameraSceneNode::FCameraSceneNode(scene, sceneViewport, sceneViewport->Actor,
        cameraLocation, cameraRotation, cameraFOV);
    UViewport* canvasViewport = (UViewport*)this->Player;
    FRenderInterface* renderInterfaceAt164 = *(FRenderInterface**)((byte*)canvasViewport + 0x164);
    *(byte*)&exceptionRegistration.state = 1;
    FCanvasUtil::FCanvasUtil(canvas, canvasViewport, renderInterfaceAt164, 1, 0);
    uint screenX = *(uint*)&X, screenY = *(uint*)&Y;
    FPlane screenInput;
    *(uint*)&screenInput.X = screenX;
    *(byte*)&exceptionRegistration.state = 2;
    *(uint*)&screenInput.Y = screenY;
    *(uint*)&screenInput.Z = 0;
    *(uint*)&screenInput.W = 0x3f800000;
    const float* canvasMatrixAt54 = (const float*)((byte*)canvas + 0x54);
    float transformed[4];
    const float* inputComponents = (const float*)&screenInput;
    // Preserve the eight-register x87 schedule and all four float spills, including transformed W.
    __asm {
        mov esi,inputComponents
        mov edx,canvasMatrixAt54
        lea edi,transformed
        fld dword ptr [esi]
        fmul dword ptr [edx]
        fld dword ptr [esi]
        fmul dword ptr [edx+0x4]
        fld dword ptr [esi]
        fmul dword ptr [edx+0x8]
        fld dword ptr [esi]
        fmul dword ptr [edx+0xc]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x10]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x14]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x18]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x1c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x20]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x24]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x28]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x2c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x30]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x34]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x38]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x3c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fxch st(3)
        fstp dword ptr [edi]
        fxch st(1)
        fstp dword ptr [edi+0x4]
        fstp dword ptr [edi+0x8]
        fstp dword ptr [edi+0xc]
    }
    uint originY = *(uint*)((byte*)scene + 0x194);
    uint originX = *(uint*)((byte*)scene + 0x190);
    uint originZ = *(uint*)((byte*)scene + 0x198);
    FVector viewOrigin;
    *(uint*)&viewOrigin.X = originX;
    *(uint*)&viewOrigin.Z = originZ;
    FPlane deprojectInput;
    *(uint*)&deprojectInput.X = *(uint*)&transformed[0];
    *(uint*)&viewOrigin.Y = originY;
    *(uint*)&deprojectInput.Y = *(uint*)&transformed[1];
    *(uint*)&deprojectInput.Z = *(uint*)&transformed[2];
    *(uint*)&deprojectInput.W = 0x3f800000;
    FVector deprojectStorage;
    using DeprojectCall = FVector* (__thiscall *)(FSceneNode*, FVector*, FPlane);
    DeprojectCall deproject = *(DeprojectCall*)R6GameImports::Engine_FSceneNode_DeprojectSlot;
    FVector* deprojected = deproject((FSceneNode*)scene, &deprojectStorage, deprojectInput);
    FVector direction;
    // Load Z/Y/X differences before spilling X/Y/Z, preserving aliases and x87 precision boundaries.
    __asm {
        mov eax,deprojected
        lea edx,viewOrigin
        lea ecx,direction
        fld dword ptr [eax+0x8]
        fsub dword ptr [edx+0x8]
        fld dword ptr [eax+0x4]
        fsub dword ptr [edx+0x4]
        fld dword ptr [eax]
        fsub dword ptr [edx]
        fstp dword ptr [ecx]
        fstp dword ptr [ecx+0x4]
        fstp dword ptr [ecx+0x8]
    }
    FVector::Normalize(&direction);
    FVector rayEnd, planePoint, planeNormal;
    // Retain Z/Y/X sums, the intervening raw Height capture, and X/Y/Z spills before plane setup.
    __asm {
        lea edx,direction
        mov ecx,cameraPosition
        lea esi,rayEnd
        lea edi,planePoint
        fld dword ptr [edx+0x8]
        fadd dword ptr [ecx+0x8]
        mov eax,Height
        fld dword ptr [edx+0x4]
        fadd dword ptr [ecx+0x4]
        fld dword ptr [edx]
        fadd dword ptr [ecx]
        mov dword ptr [edi+0x8],eax
        fstp dword ptr [esi]
        fstp dword ptr [esi+0x4]
        fstp dword ptr [esi+0x8]
        lea eax,planeNormal
        mov dword ptr [eax],0x0
        mov dword ptr [eax+0x4],0x0
        mov dword ptr [eax+0x8],0x3f800000
        mov dword ptr [edi],0x0
        mov dword ptr [edi+0x4],0x0
    }
    FVector intersectionStorage;
    FVector* intersection = IntersectLineWithPlane(&intersectionStorage, cameraPosition,
        &rayEnd, &planePoint, &planeNormal);
    uint resultX = *(uint*)&intersection->X;
    FVector* output = (FVector*)result;
    *(uint*)&output->X = resultX;
    uint resultY = *(uint*)&intersection->Y;
    *(uint*)&output->Y = resultY;
    uint resultZ = *(uint*)&intersection->Z;
    *(uint*)&output->Z = resultZ;
    *(byte*)&exceptionRegistration.state = 1;
    FCanvasUtil::~FCanvasUtil(canvas);
    *(byte*)&exceptionRegistration.state = 0;
    FCameraSceneNode::~FCameraSceneNode(scene);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100084bf : rethrow execGetXYPoint's caught UTF-16 pointer value
__declspec(naked) void AR6PlanningCtrl_execGetXYPointCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x6c]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x48]
        push edx
        mov dword ptr [ebp-0x48],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100084d3 : report execGetXYPoint context and rethrow the active exception
__declspec(naked) void AR6PlanningCtrl_execGetXYPointCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6PlanningCtrl_execGetXYPointExceptionContext // L"AR6PlanningCtrl::execGetXYPoint"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100084f0 : execGetClickResult
// Resolves planning-screen hit proxies into actor, surface or terrain hits and floor-change requests.
void __thiscall AR6PlanningCtrl::execGetClickResult(AR6PlanningCtrl* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using NetDirtyCall = void (__thiscall *)(UObject*, UProperty*);
    using DrawCall = void (__thiscall *)(UEngine*, UViewport*, int, byte*, int*);
    using ProxyIsACall = int (__thiscall *)(void*, const ushort*);
    using ProxyActorCall = AActor* (__thiscall *)(void*);
    using MeshLineCheckCall = int (__thiscall *)(UStaticMesh*, FCheckResult*, AActor*, FVector, FVector,
        FVector, uint, uint);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6PlanningCtrl_GetClickResultExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native prologue probes 0x1fa0 bytes after linking; scene/canvas are at frame -0x308/-0x1fb0.
    __writefsdword(0, (uint)&exceptionRegistration);
    AR6PlanningCtrl* controller; // Native retained receiver at frame -0x14.
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* xCode = *codeCursor;
    float X = 0.0f;
    byte xOpcode = *xCode;
    *codeCursor = (byte*)((uint)xCode + 1U);
    ScriptNative* xNativeTable = (ScriptNative*)ImportedGNativesAddress;
    controller = this;
    UObject* xContext = *(UObject**)((byte*)executionStack + 8);
    exceptionRegistration.state = 0;
    xNativeTable[xOpcode](xContext, executionStack, &X);
    byte* yCode = *codeCursor;
    UObject* yContext = *(UObject**)((byte*)executionStack + 8);
    float& Y = *(float*)&stack; // Incoming frame DWORD is reused after its pointer is retained.
    Y = 0.0f;
    byte yOpcode = *yCode;
    *codeCursor = (byte*)((uint)yCode + 1U);
    ScriptNative* yNativeTable = (ScriptNative*)ImportedGNativesAddress;
    yNativeTable[yOpcode](yContext, executionStack, &Y);
    alignas(4) byte locationFallback[12];
    *(void**)ImportedGPropAddrAddress = nullptr;
    byte* locationCode = *codeCursor;
    byte locationOpcode = *locationCode;
    UObject* locationContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)locationCode + 1U);
    ScriptNative* locationNativeTable = (ScriptNative*)ImportedGNativesAddress;
    locationNativeTable[locationOpcode](locationContext, executionStack, locationFallback);
    UObject* dirtyObject = *(UObject**)ImportedGPropObjectAddress;
    if (dirtyObject != nullptr) {
        UProperty* dirtyProperty = *(UProperty**)ImportedGPropertyAddress;
        byte* dirtyVtable = *(byte**)dirtyObject;
        (*(NetDirtyCall*)(dirtyVtable + 0x60))(dirtyObject, dirtyProperty);
    }
    void** propertyAddressCell = (void**)ImportedGPropAddrAddress;
    FVector* HitLocation = (FVector*)*propertyAddressCell;
    if (HitLocation == nullptr)
        HitLocation = (FVector*)locationFallback;
    AActor* actorFallback = nullptr;
    *propertyAddressCell = nullptr;
    byte* actorCode = *codeCursor;
    byte actorOpcode = *actorCode;
    UObject* actorContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)actorCode + 1U);
    ScriptNative* actorNativeTable = (ScriptNative*)ImportedGNativesAddress;
    actorNativeTable[actorOpcode](actorContext, executionStack, &actorFallback);
    dirtyObject = *(UObject**)ImportedGPropObjectAddress;
    if (dirtyObject != nullptr) {
        UProperty* dirtyProperty = *(UProperty**)ImportedGPropertyAddress;
        byte* dirtyVtable = *(byte**)dirtyObject;
        (*(NetDirtyCall*)(dirtyVtable + 0x60))(dirtyObject, dirtyProperty);
    }
    propertyAddressCell = (void**)ImportedGPropAddrAddress;
    AActor** HitActor = (AActor**)*propertyAddressCell;
    if (HitActor == nullptr)
        HitActor = &actorFallback;
    int levelFallback = 0;
    *propertyAddressCell = nullptr;
    byte* levelCode = *codeCursor;
    byte levelOpcode = *levelCode;
    UObject* levelContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)levelCode + 1U);
    ScriptNative* levelNativeTable = (ScriptNative*)ImportedGNativesAddress;
    levelNativeTable[levelOpcode](levelContext, executionStack, &levelFallback);
    dirtyObject = *(UObject**)ImportedGPropObjectAddress;
    if (dirtyObject != nullptr) {
        UProperty* dirtyProperty = *(UProperty**)ImportedGPropertyAddress;
        byte* dirtyVtable = *(byte**)dirtyObject;
        (*(NetDirtyCall*)(dirtyVtable + 0x60))(dirtyObject, dirtyProperty);
    }
    int* iChangeLevelTo = *(int**)ImportedGPropAddrAddress;
    if (iChangeLevelTo == nullptr)
        iChangeLevelTo = &levelFallback;
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, executionStack, nullptr);
    }
    uint* initialResult = (uint*)result;
    AR6PlanningCtrl* cameraController = controller;
    *iChangeLevelTo = -1;
    FVector* cameraPosition = &cameraController->m_vCurrentCameraPos;
    *initialResult = 0;
    alignas(4) byte sceneStorage[0x1e0], canvasStorage[0xca8];
    FCameraSceneNode* scene = (FCameraSceneNode*)sceneStorage;
    FCanvasUtil* canvas = (FCanvasUtil*)canvasStorage;
    UViewport* sceneViewport = (UViewport*)cameraController->Player;
    FRotator cameraRotation;
    cameraRotation.Pitch = cameraController->m_rCamRot.Pitch;
    cameraRotation.Yaw = cameraController->m_rCamRot.Yaw;
    cameraRotation.Roll = cameraController->m_rCamRot.Roll;
    FVector cameraLocation;
    *(uint*)&cameraLocation.X = *(uint*)&cameraPosition->X;
    *(uint*)&cameraLocation.Y = *(uint*)&cameraPosition->Y;
    *(uint*)&cameraLocation.Z = *(uint*)&cameraPosition->Z;
    FCameraSceneNode::FCameraSceneNode(scene, sceneViewport, sceneViewport->Actor,
        cameraLocation, cameraRotation, 15.0f);
    UViewport* canvasViewport = (UViewport*)controller->Player;
    FRenderInterface* renderInterfaceAt164 = *(FRenderInterface**)((byte*)canvasViewport + 0x164);
    *(byte*)&exceptionRegistration.state = 1;
    FCanvasUtil::FCanvasUtil(canvas, canvasViewport, renderInterfaceAt164, 1, 0);
    const float* fovSource = &controller->FovAngle;
    FPlane screenInput;
    float fovScale;
    __asm {
        mov eax,fovSource
        fld dword ptr [eax]
        fmul dword ptr PlanningClickFovScale
    }
    *(byte*)&exceptionRegistration.state = 2;
    // Screen Z precedes the scale spill; both centered products remain extended until X/Y stores.
    __asm {
        lea edx,screenInput
        mov dword ptr [edx+0x8],0x0
        fstp dword ptr fovScale
        mov dword ptr [edx+0xc],0x3f800000
        fld dword ptr X
        fsub dword ptr PlanningScreenCenterX
        fmul dword ptr fovScale
        fadd dword ptr PlanningScreenCenterX
        fld dword ptr Y
        fsub dword ptr PlanningScreenCenterY
        fmul dword ptr fovScale
        fadd dword ptr PlanningScreenCenterY
        fxch st(1)
        fstp dword ptr [edx]
        fstp dword ptr [edx+0x4]
    }
    const float* canvasMatrixAt54 = (const float*)((byte*)canvas + 0x54);
    const float* inputComponents = (const float*)&screenInput;
    float transformed[4];
    __asm {
        mov esi,inputComponents
        mov edx,canvasMatrixAt54
        lea edi,transformed
        fld dword ptr [esi]
        fmul dword ptr [edx]
        fld dword ptr [esi]
        fmul dword ptr [edx+0x4]
        fld dword ptr [esi]
        fmul dword ptr [edx+0x8]
        fld dword ptr [esi]
        fmul dword ptr [edx+0xc]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x10]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x14]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x18]
        fld dword ptr [esi+0x4]
        fmul dword ptr [edx+0x1c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x20]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x24]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x28]
        fld dword ptr [esi+0x8]
        fmul dword ptr [edx+0x2c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x30]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x34]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x38]
        fld dword ptr [esi+0xc]
        fmul dword ptr [edx+0x3c]
        fxch st(3)
        faddp st(7),st
        faddp st(4),st
        faddp st(4),st
        faddp st(1),st
        fxch st(3)
        fstp dword ptr [edi]
        fxch st(1)
        fstp dword ptr [edi+0x4]
        fstp dword ptr [edi+0x8]
        fstp dword ptr [edi+0xc]
    }
    uint originY = *(uint*)((byte*)scene + 0x194);
    uint originX = *(uint*)((byte*)scene + 0x190);
    uint originZ = *(uint*)((byte*)scene + 0x198);
    FVector viewOrigin;
    *(uint*)&viewOrigin.Y = originY;
    *(uint*)&viewOrigin.X = originX;
    *(uint*)&viewOrigin.Z = originZ;
    FPlane deprojectInput;
    *(uint*)&deprojectInput.X = *(uint*)&transformed[0];
    *(uint*)&deprojectInput.Y = *(uint*)&transformed[1];
    *(uint*)&deprojectInput.Z = *(uint*)&transformed[2];
    *(uint*)&deprojectInput.W = 0x3f800000;
    FVector deprojectStorage;
    using DeprojectCall = FVector* (__thiscall *)(FSceneNode*, FVector*, FPlane);
    DeprojectCall deproject = *(DeprojectCall*)R6GameImports::Engine_FSceneNode_DeprojectSlot;
    FVector* deprojected = deproject((FSceneNode*)scene, &deprojectStorage, deprojectInput);
    FVector direction;
    __asm {
        mov eax,deprojected
        lea edx,viewOrigin
        lea ecx,direction
        fld dword ptr [eax+0x8]
        fsub dword ptr [edx+0x8]
        fld dword ptr [eax+0x4]
        fsub dword ptr [edx+0x4]
        fld dword ptr [eax]
        fsub dword ptr [edx]
        fstp dword ptr [ecx]
        fstp dword ptr [ecx+0x4]
        fstp dword ptr [ecx+0x8]
    }
    FVector::Normalize(&direction);
    float scaledY;
    FVector rayEnd, planeNormal;
    __asm {
        lea edx,direction
        fld dword ptr [edx+0x8]
    }
    const FVector* planeOrigin = (const FVector*)ImportedVectorZeroAddress;
    // Y/X products spill before addition; Z remains extended until its camera-position sum.
    __asm {
        lea edx,direction
        mov ebx,cameraPosition
        lea esi,rayEnd
        lea edi,planeNormal
        fmul dword ptr PlanningPickRayLength
        fld dword ptr [edx+0x4]
        fmul dword ptr PlanningPickRayLength
        fstp dword ptr scaledY
        fld dword ptr [edx]
        fmul dword ptr PlanningPickRayLength
        mov dword ptr [edi],0x0
        mov dword ptr [edi+0x4],0x0
        fstp dword ptr [esi]
        mov dword ptr [edi+0x8],0x3f800000
        fadd dword ptr [ebx+0x8]
        fld dword ptr scaledY
        fadd dword ptr [ebx+0x4]
        fld dword ptr [esi]
        fadd dword ptr [ebx]
        fstp dword ptr [esi]
        fstp dword ptr [esi+0x4]
        fstp dword ptr [esi+0x8]
    }
    FVector planePoint;
    IntersectLineWithPlane(&planePoint, cameraPosition, &rayEnd, planeOrigin, &planeNormal);
    AR6PlanningCtrl* rectangleController = controller;
    UViewport* rectangleViewport;
    int viewportSize;
    uint convertedCoordinate;
    __asm {
        fld dword ptr X
        mov eax,rectangleController
        mov esi,dword ptr [eax+0x5b4]
        mov rectangleViewport,esi
        mov ebx,dword ptr [esi+0xa4]
        mov viewportSize,ebx
        call ConvertX87ToSigned64
        mov convertedCoordinate,eax
    }
    int rectangleEdge = (int)(convertedCoordinate - 2U);
    if (rectangleEdge < 0)
        rectangleEdge = 0;
    else if (rectangleEdge >= viewportSize)
        rectangleEdge = viewportSize;
    *(int*)((byte*)rectangleViewport + 0x174) = rectangleEdge;
    __asm {
        fld dword ptr Y
        mov eax,rectangleController
        mov esi,dword ptr [eax+0x5b4]
        mov rectangleViewport,esi
        mov ebx,dword ptr [esi+0xa8]
        mov viewportSize,ebx
        call ConvertX87ToSigned64
        mov convertedCoordinate,eax
    }
    rectangleEdge = (int)(convertedCoordinate - 2U);
    if (rectangleEdge < 0)
        rectangleEdge = 0;
    else if (rectangleEdge >= viewportSize)
        rectangleEdge = viewportSize;
    *(int*)((byte*)rectangleViewport + 0x178) = rectangleEdge;
    __asm {
        fld dword ptr X
        mov eax,rectangleController
        mov esi,dword ptr [eax+0x5b4]
        mov rectangleViewport,esi
        mov ebx,dword ptr [esi+0xa4]
        mov viewportSize,ebx
        call ConvertX87ToSigned64
        mov convertedCoordinate,eax
    }
    rectangleEdge = (int)(convertedCoordinate + 3U);
    if (rectangleEdge < 0)
        rectangleEdge = 0;
    else if (rectangleEdge >= viewportSize)
        rectangleEdge = viewportSize;
    *(int*)((byte*)rectangleViewport + 0x17c) =
        (int)((uint)rectangleEdge - *(uint*)((byte*)rectangleViewport + 0x174));
    __asm {
        fld dword ptr Y
        mov eax,rectangleController
        mov esi,dword ptr [eax+0x5b4]
        mov rectangleViewport,esi
        mov ebx,dword ptr [esi+0xa8]
        mov viewportSize,ebx
        call ConvertX87ToSigned64
        mov convertedCoordinate,eax
    }
    rectangleEdge = (int)(convertedCoordinate + 3U);
    if (rectangleEdge < 0)
        rectangleEdge = 0;
    else if (rectangleEdge >= viewportSize)
        rectangleEdge = viewportSize;
    *(int*)((byte*)rectangleViewport + 0x180) =
        (int)((uint)rectangleEdge - *(uint*)((byte*)rectangleViewport + 0x178));
    alignas(4) byte hitBuffer[1024];
    APawn* drawPawn = rectangleController->Pawn;
    int remainingBytes = 1024;
    ULevel* drawLevel = drawPawn->XLevel;
    UViewport* drawViewport = (UViewport*)rectangleController->Player;
    byte* hitCursor = hitBuffer;
    UEngine* engineAt44 = *(UEngine**)((byte*)drawLevel + 0x44);
    DrawCall draw = *(DrawCall*)(*(byte**)engineAt44 + 0x8c);
    draw(engineAt44, drawViewport, 0, hitBuffer, &remainingBytes);
    void* previousProxy = nullptr;
    for (;;) {
        int bytesBeforeRecord = remainingBytes;
        if (bytesBeforeRecord <= 0)
            break;
        void* proxy = hitCursor;
        uint serializedSize = *(uint*)((byte*)proxy + 4);
        hitCursor = (byte*)((uint)hitCursor + serializedSize);
        uint bytesAfterRecord = (uint)bytesBeforeRecord - serializedSize;
        void* previousLink = previousProxy;
        remainingBytes = (int)bytesAfterRecord;
        byte* actorProxyVtable = *(byte**)proxy;
        *(void**)((byte*)proxy + 4) = previousLink;
        previousProxy = proxy;
        // Fetches the current actor through the proxy's live virtual table on every call.
        auto proxyActor = [proxy]() -> AActor* {
            return (*(ProxyActorCall*)(*(byte**)proxy + 0xc))(proxy);
        };
        ProxyIsACall proxyIsA = *(ProxyIsACall*)(actorProxyVtable + 4);
        if (proxyIsA(proxy, (const ushort*)L"HActor") != 0) {
            AR6PlanningCtrl* actorController = controller;
            if (actorController->bShowLog)
                FOutputDevice::Logf(*(FOutputDevice**)ImportedGLogAddress, (ushort*)L"Hit An Actor!");
            AActor* currentActor = proxyActor();
            AActor** actorOutput = HitActor;
            *actorOutput = currentActor;
            UClass* classCursor = *(UClass**)((byte*)currentActor + 0x24);
            UClass* staticMeshActorClass = *(UClass**)R6GameImports::Engine_AStaticMeshActor_PrivateStaticClassSlot;
            while (classCursor != nullptr && classCursor != staticMeshActorClass)
                classCursor = *(UClass**)((byte*)classCursor + 0x2c);
            if (classCursor == staticMeshActorClass && (*actorOutput)->m_bIsWalkable) {
                if (actorController->bShowLog)
                    FOutputDevice::Logf(*(FOutputDevice**)ImportedGLogAddress, (ushort*)L"Hit An Static Mesh!");
                alignas(4) byte meshHit[48];
                byte* meshActorVtable = *(byte**)proxy;
                *(uint*)(meshHit + 0x2c) = 0; // Only this hit word is initialized.
                AActor* meshOwner = (*(ProxyActorCall*)(meshActorVtable + 0xc))(proxy);
                FVector traceStart, traceEnd;
                float traceXSpill, traceZSpill;
                const FVector* tracePoint = &planePoint;
                __asm {
                    mov edx,tracePoint
                    fld dword ptr [edx+0x8]
                    fadd dword ptr PlanningVerticalTraceHalfLength
                }
                UStaticMesh* mesh = meshOwner->StaticMesh;
                __asm {
                    mov edx,tracePoint
                    fld dword ptr [edx+0x4]
                }
                byte* traceActorVtable = *(byte**)proxy;
                // X spills to both endpoints; Y is duplicated on x87 while plus-Z stays extended.
                __asm {
                    mov edx,tracePoint
                    lea esi,traceStart
                    lea edi,traceEnd
                    fld st(0)
                    fld dword ptr [edx]
                    fst dword ptr traceXSpill
                    mov ecx,dword ptr traceXSpill
                    fstp dword ptr [esi]
                    mov dword ptr [edi],ecx
                    fstp dword ptr [esi+0x4]
                    fxch st(1)
                    fstp dword ptr [esi+0x8]
                    fld dword ptr [edx+0x8]
                    fsub dword ptr PlanningVerticalTraceHalfLength
                    fstp dword ptr traceZSpill
                    mov ecx,dword ptr traceZSpill
                    fstp dword ptr [edi+0x4]
                    mov dword ptr [edi+0x8],ecx
                }
                AActor* traceActor = (*(ProxyActorCall*)(traceActorVtable + 0xc))(proxy);
                const FVector* extentSource = (const FVector*)ImportedVectorZeroAddress;
                uint extentX = *(uint*)&extentSource->X;
                FVector meshExtent;
                *(uint*)&meshExtent.X = extentX;
                uint extentY = *(uint*)&extentSource->Y;
                uint extentZ = *(uint*)&extentSource->Z;
                *(uint*)&meshExtent.Y = extentY;
                *(uint*)&meshExtent.Z = extentZ;
                uint startX = *(uint*)&traceStart.X;
                byte* meshVtable = *(byte**)mesh;
                FVector traceStartArgument, traceEndArgument;
                *(uint*)&traceStartArgument.X = startX;
                *(uint*)&traceStartArgument.Y = *(uint*)&traceStart.Y;
                *(uint*)&traceStartArgument.Z = *(uint*)&traceStart.Z;
                *(uint*)&traceEndArgument.X = *(uint*)&traceEnd.X;
                *(uint*)&traceEndArgument.Y = *(uint*)&traceEnd.Y;
                *(uint*)&traceEndArgument.Z = *(uint*)&traceEnd.Z;
                MeshLineCheckCall meshLineCheck = *(MeshLineCheckCall*)(meshVtable + 0x68);
                meshLineCheck(mesh, (FCheckResult*)meshHit, traceActor, traceEndArgument,
                    traceStartArgument, meshExtent, 0, 4);
                uint hitX = *(uint*)(meshHit + 8);
                FVector* meshLocationOutput = HitLocation;
                uint hitY = *(uint*)(meshHit + 0xc);
                *(uint*)&meshLocationOutput->X = hitX;
                uint hitZ = *(uint*)(meshHit + 0x10);
                *(uint*)&meshLocationOutput->Y = hitY;
                *(uint*)&meshLocationOutput->Z = hitZ;
                AActor* floorActor = proxyActor();
                int primaryFloor = floorActor->m_iPlanningFloor_0;
                AR6PlanningCtrl* floorController = controller;
                if (primaryFloor == floorController->m_iLevelDisplay) {
                    AActor* secondaryActor = proxyActor();
                    int secondaryFloor = secondaryActor->m_iPlanningFloor_1;
                    int* floorOutput = iChangeLevelTo;
                    *floorOutput = secondaryFloor;
                    AActor* firstFloorActor = proxyActor();
                    AActor* secondFloorActor = proxyActor();
                    bool requestedUp = false;
                    if (firstFloorActor->m_iPlanningFloor_0 < secondFloorActor->m_iPlanningFloor_1) {
                        AActor* oldComparison = proxyActor();
                        if (floorController->m_pOldHitActor != oldComparison) {
                            floorController->m_bLevelUp = 1;
                            floorController->m_bGoLevelUp = 1;
                            requestedUp = true;
                        }
                    }
                    if (!requestedUp) {
                        firstFloorActor = proxyActor();
                        secondFloorActor = proxyActor();
                        if (firstFloorActor->m_iPlanningFloor_0 > secondFloorActor->m_iPlanningFloor_1) {
                            AActor* oldComparison = proxyActor();
                            if (floorController->m_pOldHitActor != oldComparison) {
                                floorController->m_bLevelDown = 1;
                                floorController->m_bGoLevelDown = 1;
                            }
                        }
                    }
                } else {
                    floorActor = proxyActor();
                    if (floorActor->m_iPlanningFloor_0 != floorController->m_iLevelDisplay) {
                        AActor* primaryActor = proxyActor();
                        int changedFloor = primaryActor->m_iPlanningFloor_0;
                        int* floorOutput = iChangeLevelTo;
                        *floorOutput = changedFloor;
                        floorActor = proxyActor();
                        bool requestedUp = false;
                        if (floorActor->m_iPlanningFloor_0 > floorController->m_iLevelDisplay) {
                            AActor* oldComparison = proxyActor();
                            if (floorController->m_pOldHitActor != oldComparison) {
                                floorController->m_bLevelUp = 1;
                                floorController->m_bGoLevelUp = 1;
                                requestedUp = true;
                            }
                        }
                        if (!requestedUp) {
                            AActor* oldComparison = proxyActor();
                            if (floorController->m_pOldHitActor != oldComparison) {
                                floorController->m_bLevelDown = 1;
                                floorController->m_bGoLevelDown = 1;
                            }
                        }
                    }
                }
                ALevelInfo* levelInfo = ULevel::GetLevelInfo(floorController->Pawn->XLevel);
                AActor* comparisonActor = proxyActor();
                if ((AActor*)levelInfo == comparisonActor) {
                    uint* successResult = (uint*)result;
                    floorController->m_pOldHitActor = nullptr;
                    *successResult = 1;
                    continue;
                }
                AActor* oldHitActor = proxyActor();
                floorController->m_pOldHitActor = oldHitActor;
            }
            *(uint*)result = 1;
            continue;
        }
        proxyIsA = *(ProxyIsACall*)(*(byte**)proxy + 4);
        if (proxyIsA(proxy, (const ushort*)L"HBspSurf") != 0) {
            AR6PlanningCtrl* bspLogController = controller;
            if (bspLogController->bShowLog)
                FOutputDevice::Logf(*(FOutputDevice**)ImportedGLogAddress, (ushort*)L"Hit BSP surf");
            int surfaceIndex = *(int*)((byte*)proxy + 0xc);
            AR6PlanningCtrl* surfaceLookupController = controller;
            uint surfaceOffset = (uint)surfaceIndex * 0x5cU;
            UModel* modelAt90 = *(UModel**)((byte*)surfaceLookupController->Pawn->XLevel + 0x90);
            byte* surfaceDataAt9c = *(byte**)((byte*)modelAt90 + 0x9c);
            byte* surface = (byte*)((uint)surfaceDataAt9c + surfaceOffset);
            if (*(byte*)(surface + 0x58) != 1)
                continue;
            AR6PlanningCtrl* surfaceController = controller;
            int surfaceFloor = *(int*)(surface + 0x48);
            if (surfaceFloor != surfaceController->m_iLevelDisplay)
                continue;
            AR6PlanningCtrl* bspResultController = surfaceController;
            bspResultController->m_pOldHitActor = nullptr;
            alignas(4) byte surfaceHits[64][48];
            for (int hitIndex = 0; hitIndex < 64; ++hitIndex)
                *(uint*)(surfaceHits[hitIndex] + 0x2c) = 0;
            int hitCount = 0, checkIndex = 0;
            for (;;) {
                if (checkIndex >= *(int*)(surface + 0x24))
                    break;
                FVector traceStart, traceEnd;
                float traceXSpill, traceZSpill;
                const FVector* tracePoint = &planePoint;
                __asm {
                    mov eax,tracePoint
                    fld dword ptr [eax+0x8]
                }
                AR6PlanningCtrl* traceController = controller;
                __asm {
                    mov eax,tracePoint
                    lea esi,traceStart
                    lea edi,traceEnd
                    fadd dword ptr PlanningBspTraceHalfLength
                    fld dword ptr [eax+0x4]
                    fld st(0)
                    fld dword ptr [eax]
                    fst dword ptr traceXSpill
                    mov edx,dword ptr traceXSpill
                    fstp dword ptr [esi]
                    mov dword ptr [edi],edx
                }
                APawn* tracePawn = traceController->Pawn;
                __asm {
                    mov eax,tracePoint
                    lea esi,traceStart
                    lea edi,traceEnd
                    fstp dword ptr [esi+0x4]
                    fxch st(1)
                    fstp dword ptr [esi+0x8]
                    fld dword ptr [eax+0x8]
                    fsub dword ptr PlanningBspTraceHalfLength
                    fstp dword ptr traceZSpill
                    mov edx,dword ptr traceZSpill
                    mov dword ptr [edi+0x8],edx
                    fstp dword ptr [edi+0x4]
                }
                ULevel* traceLevel = tracePawn->XLevel;
                FVector traceStartArgument, traceEndArgument;
                *(uint*)&traceStartArgument.X = *(uint*)&traceStart.X;
                *(uint*)&traceStartArgument.Y = *(uint*)&traceStart.Y;
                *(uint*)&traceStartArgument.Z = *(uint*)&traceStart.Z;
                *(uint*)&traceEndArgument.X = *(uint*)&traceEnd.X;
                *(uint*)&traceEndArgument.Y = *(uint*)&traceEnd.Y;
                *(uint*)&traceEndArgument.Z = *(uint*)&traceEnd.Z;
                int* nodeIndices = *(int**)(surface + 0x20);
                int nodeIndex = nodeIndices[checkIndex];
                FCheckResult* checkHit = (FCheckResult*)((uint)surfaceHits + (uint)hitCount * 48U);
                modelAt90 = *(UModel**)((byte*)traceLevel + 0x90);
                int checkResult = UModel::R6LineCheck(modelAt90, checkHit, nodeIndex,
                    traceEndArgument, traceStartArgument);
                if (checkResult == 1)
                    hitCount = (int)((uint)hitCount + 1U);
                bspResultController = controller;
                checkIndex = (int)((uint)checkIndex + 1U);
            }
            if (hitCount == 0) {
                *(uint*)result = 0;
                break;
            }
            FVector highestHit;
            *(uint*)&highestHit.X = 0;
            *(uint*)&highestHit.Y = 0;
            *(uint*)&highestHit.Z = 0xc77fff00;
            for (int hitIndex = 0; hitIndex < hitCount; ++hitIndex) {
                FVector* candidate = (FVector*)((uint)surfaceHits + (uint)hitIndex * 48U + 8U);
                ushort candidateStatus;
                // Compare candidate Z first; unordered, equal and lower candidates retain the current hit.
                __asm {
                    mov eax,candidate
                    lea edx,highestHit
                    fld dword ptr [eax+0x8]
                    fcomp dword ptr [edx+0x8]
                    fnstsw ax
                    mov candidateStatus,ax
                }
                if ((candidateStatus & 0x4100) == 0) {
                    uint candidateX = *(uint*)&candidate->X;
                    *(uint*)&highestHit.X = candidateX;
                    uint candidateY = *(uint*)&candidate->Y;
                    uint candidateZ = *(uint*)&candidate->Z;
                    *(uint*)&highestHit.Y = candidateY;
                    *(uint*)&highestHit.Z = candidateZ;
                }
            }
            if (bspResultController->bShowLog) {
                __asm {
                    lea eax,highestHit
                    fld dword ptr [eax+0x8]
                }
                FOutputDevice* hitLog = *(FOutputDevice**)ImportedGLogAddress;
                double logX, logY, logZ;
                __asm {
                    lea eax,highestHit
                    fstp qword ptr logZ
                    fld dword ptr [eax+0x4]
                    fstp qword ptr logY
                    fld dword ptr [eax]
                    fstp qword ptr logX
                }
                FOutputDevice::Logf(hitLog, (ushort*)L"%i - X:%f Y:%f Z:%f", hitCount, logX, logY, logZ);
                bspResultController = controller;
            }
            uint highestX = *(uint*)&highestHit.X;
            FVector* surfaceLocationOutput = HitLocation;
            *(uint*)&surfaceLocationOutput->X = highestX;
            *(uint*)&surfaceLocationOutput->Y = *(uint*)&highestHit.Y;
            *(uint*)&surfaceLocationOutput->Z = *(uint*)&highestHit.Z;
            if (*(byte*)(surface + 0x50) == 0) {
                int displayedFloor = bspResultController->m_iLevelDisplay;
                if (*(int*)(surface + 0x48) == displayedFloor) {
                    int nextFloor = *(int*)(surface + 0x4c);
                    int* floorOutput = iChangeLevelTo;
                    *floorOutput = nextFloor;
                    int primaryFloor = *(int*)(surface + 0x48);
                    int secondaryFloor = *(int*)(surface + 0x4c);
                    if (primaryFloor < secondaryFloor) {
                        uint* successResult = (uint*)result;
                        bspResultController->m_bLevelUp = 1;
                        bspResultController->m_bGoLevelUp = 1;
                        *successResult = 1;
                        continue;
                    } else if (primaryFloor > secondaryFloor) {
                        bspResultController->m_bLevelDown = 1;
                        bspResultController->m_bGoLevelDown = 1;
                    }
                } else if (*(int*)(surface + 0x4c) == displayedFloor) {
                    int primaryFloor = *(int*)(surface + 0x48);
                    int* floorOutput = iChangeLevelTo;
                    *floorOutput = primaryFloor;
                    primaryFloor = *(int*)(surface + 0x48);
                    if (primaryFloor > *(int*)(surface + 0x4c)) {
                        uint* successResult = (uint*)result;
                        bspResultController->m_bLevelUp = 1;
                        bspResultController->m_bGoLevelUp = 1;
                        *successResult = 1;
                        continue;
                    } else {
                        bspResultController->m_bLevelDown = 1;
                        bspResultController->m_bGoLevelDown = 1;
                    }
                }
            }
            *(uint*)result = 1;
            continue;
        }
        proxyIsA = *(ProxyIsACall*)(*(byte**)proxy + 4);
        if (proxyIsA(proxy, (const ushort*)L"HTerrain") == 0)
            continue;
        AR6PlanningCtrl* terrainController = controller;
        if (terrainController->bShowLog)
            FOutputDevice::Logf(*(FOutputDevice**)ImportedGLogAddress, (ushort*)L"Hit Terrain");
        alignas(4) byte terrainHit[48];
        FVector traceStart, traceEnd;
        float traceXSpill, traceZSpill;
        const FVector* tracePoint = &planePoint;
        __asm {
            mov eax,tracePoint
            fld dword ptr [eax+0x8]
        }
        byte* terrainActorVtable = *(byte**)proxy;
        __asm {
            fadd dword ptr PlanningVerticalTraceHalfLength
        }
        *(uint*)(terrainHit + 0x2c) = 0;
        __asm {
            mov eax,tracePoint
            lea esi,traceStart
            lea edi,traceEnd
            fld dword ptr [eax+0x4]
            fld st(0)
            fld dword ptr [eax]
            fst dword ptr traceXSpill
            mov ecx,dword ptr traceXSpill
            fstp dword ptr [esi]
            mov dword ptr [edi],ecx
            fstp dword ptr [esi+0x4]
            fxch st(1)
            fstp dword ptr [esi+0x8]
            fld dword ptr [eax+0x8]
            fsub dword ptr PlanningVerticalTraceHalfLength
            fstp dword ptr traceZSpill
            mov ecx,dword ptr traceZSpill
            mov dword ptr [edi+0x8],ecx
            fstp dword ptr [edi+0x4]
        }
        ATerrainInfo* terrain = (ATerrainInfo*)(*(ProxyActorCall*)(terrainActorVtable + 0xc))(proxy);
        const FVector* extentSource = (const FVector*)ImportedVectorZeroAddress;
        uint extentX = *(uint*)&extentSource->X;
        FVector terrainExtent;
        *(uint*)&terrainExtent.X = extentX;
        uint extentY = *(uint*)&extentSource->Y;
        uint extentZ = *(uint*)&extentSource->Z;
        *(uint*)&terrainExtent.Y = extentY;
        *(uint*)&terrainExtent.Z = extentZ;
        FVector traceStartArgument, traceEndArgument;
        *(uint*)&traceStartArgument.X = *(uint*)&traceStart.X;
        *(uint*)&traceStartArgument.Y = *(uint*)&traceStart.Y;
        *(uint*)&traceStartArgument.Z = *(uint*)&traceStart.Z;
        *(uint*)&traceEndArgument.X = *(uint*)&traceEnd.X;
        *(uint*)&traceEndArgument.Y = *(uint*)&traceEnd.Y;
        *(uint*)&traceEndArgument.Z = *(uint*)&traceEnd.Z;
        if (ATerrainInfo::LineCheck(terrain, (FCheckResult*)terrainHit, traceEndArgument, traceStartArgument,
            terrainExtent, 4) != 0)
            continue;
        UViewport* terrainViewport = (UViewport*)terrainController->Player;
        if (terrainViewport == nullptr)
            continue;
        UClass* classCursor = *(UClass**)((byte*)terrainViewport + 0x24);
        UClass* viewportClass = *(UClass**)R6GameImports::Engine_UViewport_PrivateStaticClassSlot;
        while (classCursor != nullptr && classCursor != viewportClass)
            classCursor = *(UClass**)((byte*)classCursor + 0x2c);
        if (classCursor != viewportClass || terrainViewport == nullptr)
            continue;
        int viewportFloorAt1f4 = *(int*)((byte*)terrainViewport + 0x1f4);
        int& terrainItem = *(int*)(terrainHit + 0x28);
        int acceptedItem = terrainItem;
        if (acceptedItem != viewportFloorAt1f4 && acceptedItem != (int)((uint)viewportFloorAt1f4 - 1U) &&
            acceptedItem != (int)((uint)viewportFloorAt1f4 + 1U))
            continue;
        int* terrainFloorOutput = iChangeLevelTo;
        FVector* terrainLocationOutput = HitLocation;
        terrainController->m_pOldHitActor = nullptr;
        *terrainFloorOutput = acceptedItem;
        uint hitX = *(uint*)(terrainHit + 8), hitY = *(uint*)(terrainHit + 0xc);
        *(uint*)&terrainLocationOutput->X = hitX;
        uint hitZ = *(uint*)(terrainHit + 0x10);
        *(uint*)&terrainLocationOutput->Y = hitY;
        *(uint*)&terrainLocationOutput->Z = hitZ;
        AActor* terrainActor = proxyActor();
        AActor** terrainActorOutput = HitActor;
        uint* terrainResultOutput = (uint*)result;
        *terrainActorOutput = terrainActor;
        int itemAfterGetter = terrainItem;
        *terrainResultOutput = 1;
        viewportFloorAt1f4 = *(int*)((byte*)terrainViewport + 0x1f4);
        if (viewportFloorAt1f4 < itemAfterGetter) {
            terrainController->m_bLevelUp = 1;
            terrainController->m_bGoLevelUp = 1;
        } else if (viewportFloorAt1f4 > itemAfterGetter) {
            terrainController->m_bLevelDown = 1;
            terrainController->m_bGoLevelDown = 1;
        }
    }
    *(byte*)&exceptionRegistration.state = 1;
    FCanvasUtil::~FCanvasUtil(canvas);
    *(byte*)&exceptionRegistration.state = 0;
    FCameraSceneNode::~FCameraSceneNode(scene);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10009164 : rethrow execGetClickResult's caught UTF-16 pointer value
__declspec(naked) void AR6PlanningCtrl_execGetClickResultCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xc8]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x88]
        push ecx
        mov dword ptr [ebp-0x88],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10009181 : report execGetClickResult context and rethrow the active exception
__declspec(naked) void AR6PlanningCtrl_execGetClickResultCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6PlanningCtrl_execGetClickResultExceptionContext // L"AR6PlanningCtrl::execGetClickResult"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100134f0 : destroy the saved PlayerController base if ConditionalDestroy unwinds
__declspec(naked) void AR6PlanningCtrl_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_APlayerController_DestructorSlot // APlayerController destructor.
    }
}

// R6Game.dll @ 10013f20 : destroy the GetXYPoint camera while unwinding
__declspec(naked) void AR6PlanningCtrl_execGetXYPointUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x24c]
        jmp dword ptr ds:R6GameAddresses::Engine_FCameraSceneNode_DestructorSlot // FCameraSceneNode destructor.
    }
}

// R6Game.dll @ 10013f2c : destroy the GetXYPoint canvas while unwinding
__declspec(naked) void AR6PlanningCtrl_execGetXYPointUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0xef4]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 10013f50 : destroy the GetClickResult camera while unwinding
__declspec(naked) void AR6PlanningCtrl_execGetClickResultUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x308]
        jmp dword ptr ds:R6GameAddresses::Engine_FCameraSceneNode_DestructorSlot // FCameraSceneNode destructor.
    }
}

// R6Game.dll @ 10013f5c : destroy the GetClickResult canvas while unwinding
__declspec(naked) void AR6PlanningCtrl_execGetClickResultUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x1fb0]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 10014700 : initialize planning-controller class metadata and register its cleanup
void InitializeAR6PlanningCtrlClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  UClass* parentClass = (UClass*)ImportedAPlayerControllerClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6PlanningCtrlClassMetadataStorage, 0, 0x8fc, 4, parentClass, withinClass, FGuid(0, 0, 0, 0),
      L"R6PlanningCtrl", GPackage, configName, 0x4084004, AR6PlanningCtrl::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6PlanningCtrlClassMetadata);
}

// R6Game.dll @ 100150d0 : destroy planning-controller class metadata
void DestroyAR6PlanningCtrlClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6PlanningCtrlClassMetadataStorage);
}

// R6Game.dll @ 10014790 : bind the exported planning-controller auto-class pointer to its metadata
void InitializeAR6PlanningCtrlAutoClassPointer(void)
{
  autoclassAR6PlanningCtrl = (UClass*)AR6PlanningCtrlClassMetadataStorage; // Exported slot at 0x10026028.
}

// R6Game.dll @ 10013f10 : dispatch PlanningTrace's guard and catch states
__declspec(naked) void AR6PlanningCtrl_PlanningTraceExceptionHandler(void)
{
  __asm { mov eax, offset AR6PlanningCtrl_execPlanningTraceExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013f38 : dispatch GetXYPoint's camera, canvas and catch states
__declspec(naked) void AR6PlanningCtrl_GetXYPointExceptionHandler(void)
{
  __asm { mov eax, offset AR6PlanningCtrl_execGetXYPointExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013f68 : dispatch GetClickResult's camera, canvas and catch states
__declspec(naked) void AR6PlanningCtrl_GetClickResultExceptionHandler(void)
{
  __asm { mov eax, offset AR6PlanningCtrl_execGetClickResultExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014e40 : register AR6PlanningCtrl::execGetClickResult at native index 2013
void InitializeAR6PlanningCtrlNativeGetClickResult(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6PlanningCtrlexecGetClickResult;
    byte& nativeRegistrationResult = AR6PlanningCtrlexecGetClickResultRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2013, nativeExecPointerWord);
}

// R6Game.dll @ 10014e60 : register AR6PlanningCtrl::execGetXYPoint at native index 2016
void InitializeAR6PlanningCtrlNativeGetXYPoint(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6PlanningCtrlexecGetXYPoint;
    byte& nativeRegistrationResult = AR6PlanningCtrlexecGetXYPointRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2016, nativeExecPointerWord);
}

// R6Game.dll @ 10014e80 : register AR6PlanningCtrl::execPlanningTrace at native index 2017
void InitializeAR6PlanningCtrlNativePlanningTrace(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6PlanningCtrlexecPlanningTrace;
    byte& nativeRegistrationResult = AR6PlanningCtrlexecPlanningTraceRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2017, nativeExecPointerWord);
}

// R6Game.dll @ 100134f9 : dispatch native C++ cleanup and catch states through FuncInfo 0x10019fe4
__declspec(naked) void AR6PlanningCtrlExceptionDispatcher(void)
{
    __asm { mov eax, offset AR6PlanningCtrl_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
