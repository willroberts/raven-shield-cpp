#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10025b0c : auto-class pointer
UClass* autoclassAR6ActionPoint = nullptr;

// R6Game.dll data @ 10025b20 : class metadata storage
// Backing storage for AR6ActionPoint::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6ActionPointClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a000 : native C++ unwind-state transitions
const unsigned int AR6ActionPoint_DestructUnwindMap[2] = {
    0xffffffff, R6GameAddresses::AR6ActionPoint_DestructUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a008 : native C++ exception function descriptor
const unsigned int AR6ActionPoint_DestructExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::AR6ActionPoint_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b284 : native C++ unwind-state transitions
const unsigned int AR6ActionPoint_TransferFileUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b294 : native typed-pointer and catch-all handler pair
const unsigned int AR6ActionPoint_TransferFileCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6ActionPoint_TransferFileCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6ActionPoint_TransferFileCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b2b4 : native C++ try-block ranges
const unsigned int AR6ActionPoint_TransferFileTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6ActionPoint_TransferFileCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b2c8 : native C++ exception function descriptor
const unsigned int AR6ActionPoint_TransferFileExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6ActionPoint_TransferFileUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6ActionPoint_TransferFileTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016b00 : AR6ActionPoint virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6ActionPoint_vftable[97] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6ActionPoint_VectorDeletingDestructor, // +0xc: AR6ActionPoint::VectorDeletingDestructor
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
    R6GameAddresses::ForwardImported_AActor_GetOptimizedRepList, // +0x64: AActor::GetOptimizedRepList
    R6GameAddresses::ForwardImported_AActor_GetPlayerPawn, // +0x68: AActor::GetPlayerPawn
    R6GameAddresses::ForwardImported_AActor_GetPawnOrColBoxOwner, // +0x6c: AActor::GetPawnOrColBoxOwner
    R6GameAddresses::ForwardImported_AActor_IsBlockedBy, // +0x70: AActor::IsBlockedBy
    R6GameAddresses::ForwardImported_AActor_GetNetPriority, // +0x74: AActor::GetNetPriority
    R6GameAddresses::ForwardImported_AActor_WorldLightRadius, // +0x78: AActor::WorldLightRadius
    R6GameAddresses::ForwardImported_AActor_Tick, // +0x7c: AActor::Tick
    R6GameAddresses::ForwardImported_AActor_PostEditMove, // +0x80: AActor::PostEditMove
    R6GameAddresses::ForwardImported_AActor_PostEditLoad, // +0x84: AActor::PostEditLoad
    R6GameAddresses::ForwardImported_AActor_PreRaytrace, // +0x88: AActor::PreRaytrace
    R6GameAddresses::ForwardImported_AActor_PostRaytrace, // +0x8c: AActor::PostRaytrace
    R6GameAddresses::ForwardImported_AActor_Spawned, // +0x90: AActor::Spawned
    R6GameAddresses::ForwardImported_AActor_PreNetReceive, // +0x94: AActor::PreNetReceive
    R6GameAddresses::ForwardImported_AActor_PostNetReceive, // +0x98: AActor::PostNetReceive
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
    R6GameAddresses::ForwardImported_AActor_StartAnimPoll, // +0xe0: AActor::StartAnimPoll
    R6GameAddresses::ForwardImported_AActor_CheckAnimFinished, // +0xe4: AActor::CheckAnimFinished
    R6GameAddresses::ForwardImported_AActor_UpdateTimers, // +0xe8: AActor::UpdateTimers
    R6GameAddresses::ForwardImported_AActor_CheckOwnerUpdated, // +0xec: AActor::CheckOwnerUpdated
    R6GameAddresses::ForwardImported_AActor_TickAuthoritative, // +0xf0: AActor::TickAuthoritative
    R6GameAddresses::ForwardImported_AActor_TickSimulated, // +0xf4: AActor::TickSimulated
    R6GameAddresses::ForwardImported_AActor_TickSpecial, // +0xf8: AActor::TickSpecial
    R6GameAddresses::ForwardImported_AActor_PlayerControlled, // +0xfc: AActor::PlayerControlled
    R6GameAddresses::ForwardImported_AActor_IsNetRelevantFor, // +0x100: AActor::IsNetRelevantFor
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
};

// R6Game.dll @ 10002280 : return the AR6ActionPoint class object
UClass* __cdecl AR6ActionPoint::StaticClass(void)
{
    return (UClass*)AR6ActionPointClassMetadataStorage;
}

// R6Game.dll @ 10002290 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6ActionPoint::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6ActionPointClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100022c0 : conditionally shut down the action point, then destroy its abstract base
void __thiscall AR6ActionPoint::~AR6ActionPoint(AR6ActionPoint* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6ActionPointExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native frame -0x10 saves this; FuncInfo 0x1001a008 maps state 0 to AR6ActionPoint_DestructUnwind.
    *(const uint**)this = AR6ActionPoint_vftable;
    exceptionRegistration.state = 0;
    UObject::ConditionalDestroy((UObject*)this);
    exceptionRegistration.state = -1;
    AR6ActionPointAbstract::~AR6ActionPointAbstract((AR6ActionPointAbstract*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10002320 : construct the abstract action-point base and install the concrete vtable
AR6ActionPoint* __thiscall AR6ActionPoint::AR6ActionPoint(AR6ActionPoint* this)
{
    AR6ActionPointAbstract::AR6ActionPointAbstract((AR6ActionPointAbstract*)this);
    *(const uint**)this = AR6ActionPoint_vftable;
    return this;
}

// R6Game.dll @ 10002340 : copy-construct inherited state and members
// Copies the base, action settings, object references, color and orientation; preserves unnamed flag bits.
AR6ActionPoint * __thiscall AR6ActionPoint::AR6ActionPoint(AR6ActionPoint *this, const AR6ActionPoint *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x3bc);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x3bc);
  uint copiedFlags;

  AR6ActionPointAbstract::AR6ActionPointAbstract((AR6ActionPointAbstract *)this,
      (const AR6ActionPointAbstract *)source);
  *(const uint**)this = AR6ActionPoint_vftable;
  this->m_eMovementMode = source->m_eMovementMode; // +0x3a4.
  this->m_eMovementSpeed = source->m_eMovementSpeed; // +0x3a5.
  this->m_eAction = source->m_eAction; // +0x3a6.
  this->m_eActionType = source->m_eActionType; // +0x3a7.
  this->m_iRainbowTeamName = source->m_iRainbowTeamName; // +0x3a8.
  this->m_iMileStoneNum = source->m_iMileStoneNum; // +0x3ac.
  this->m_iNodeID = source->m_iNodeID; // +0x3b0.
  this->m_iInitialMousePosX = source->m_iInitialMousePosX; // +0x3b4.
  this->m_iInitialMousePosY = source->m_iInitialMousePosY; // +0x3b8.
  // Copy bits 0..3 separately; bits 4..31 retain their destination values.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bActionCompleted.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bActionPointReached.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bDoorInRange.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // bShowLog.
  *destinationFlags = copiedFlags;
  this->m_pCurrentTexture = source->m_pCurrentTexture; // +0x3c0.
  this->m_pSelected = source->m_pSelected; // +0x3c4.
  this->pDoor = source->pDoor; // +0x3c8.
  this->m_pPlanningCtrl = source->m_pPlanningCtrl; // +0x3cc.
  this->m_pMyPathFlag = source->m_pMyPathFlag; // +0x3d0.
  this->m_pActionIcon = source->m_pActionIcon; // +0x3d4.
  this->m_CurrentColor = source->m_CurrentColor; // +0x3d8.
  this->m_vActionDirection.X = source->m_vActionDirection.X; // +0x3dc.
  this->m_vActionDirection.Y = source->m_vActionDirection.Y; // +0x3e0.
  this->m_vActionDirection.Z = source->m_vActionDirection.Z; // +0x3e4.
  this->m_rActionRotation.Pitch = source->m_rActionRotation.Pitch; // +0x3e8.
  this->m_rActionRotation.Yaw = source->m_rActionRotation.Yaw; // +0x3ec.
  this->m_rActionRotation.Roll = source->m_rActionRotation.Roll; // +0x3f0.
  return this;
}

// R6Game.dll @ 100024b0 : assign inherited state and members
// Assigns the base, action settings, object references, color and orientation; preserves unnamed flag bits.
AR6ActionPoint * __thiscall AR6ActionPoint::operator=(AR6ActionPoint *this, const AR6ActionPoint *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x3bc);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x3bc);
  uint copiedFlags;

  AR6ActionPointAbstract::operator=((AR6ActionPointAbstract *)this, (const AR6ActionPointAbstract *)source);
  this->m_eMovementMode = source->m_eMovementMode; // +0x3a4.
  this->m_eMovementSpeed = source->m_eMovementSpeed; // +0x3a5.
  this->m_eAction = source->m_eAction; // +0x3a6.
  this->m_eActionType = source->m_eActionType; // +0x3a7.
  this->m_iRainbowTeamName = source->m_iRainbowTeamName; // +0x3a8.
  this->m_iMileStoneNum = source->m_iMileStoneNum; // +0x3ac.
  this->m_iNodeID = source->m_iNodeID; // +0x3b0.
  this->m_iInitialMousePosX = source->m_iInitialMousePosX; // +0x3b4.
  this->m_iInitialMousePosY = source->m_iInitialMousePosY; // +0x3b8.
  // Copy bits 0..3 separately; bits 4..31 retain their destination values.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bActionCompleted.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bActionPointReached.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bDoorInRange.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // bShowLog.
  *destinationFlags = copiedFlags;
  this->m_pCurrentTexture = source->m_pCurrentTexture; // +0x3c0.
  this->m_pSelected = source->m_pSelected; // +0x3c4.
  this->pDoor = source->pDoor; // +0x3c8.
  this->m_pPlanningCtrl = source->m_pPlanningCtrl; // +0x3cc.
  this->m_pMyPathFlag = source->m_pMyPathFlag; // +0x3d0.
  this->m_pActionIcon = source->m_pActionIcon; // +0x3d4.
  this->m_CurrentColor = source->m_CurrentColor; // +0x3d8.
  this->m_vActionDirection.X = source->m_vActionDirection.X; // +0x3dc.
  this->m_vActionDirection.Y = source->m_vActionDirection.Y; // +0x3e0.
  this->m_vActionDirection.Z = source->m_vActionDirection.Z; // +0x3e4.
  this->m_rActionRotation.Pitch = source->m_rActionRotation.Pitch; // +0x3e8.
  this->m_rActionRotation.Yaw = source->m_rActionRotation.Yaw; // +0x3ec.
  this->m_rActionRotation.Roll = source->m_rActionRotation.Roll; // +0x3f0.
  return this;
}

// R6Game.dll @ 10002620 : destroy one action point or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6ActionPoint::VectorDeletingDestructor(AR6ActionPoint* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x3f4, elementCount,
            (_func_void_void_ptr*)AR6ActionPoint::~AR6ActionPoint);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6ActionPoint::~AR6ActionPoint(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x3f4);
    return this;
}

// R6Game.dll @ 10003e70 : construct an action point in supplied memory when nonnull
void __cdecl AR6ActionPoint::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        AR6ActionPoint::AR6ActionPoint((AR6ActionPoint*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 10007cd0 : face a planar target through the planning sprite's divided-yaw byte
void __thiscall AR6ActionPoint::SetRotationToward(AR6ActionPoint* this, FVector target)
{
    target.X = (float)((long double)target.X - this->Location.X);
    target.Y = (float)((long double)target.Y - this->Location.Y);
    target.Z = (float)((long double)target.Z - this->Location.Z);
    target.Z = 0.0f;
    FVector::Normalize(&target);
    alignas(4) byte basisStorage[48];
    FCoords* basis = (FCoords*)basisStorage;
    basis->Origin = *(const FVector*)ImportedVectorZeroAddress;
    basis->XAxis = target;
    basis->YAxis = FVector(-target.Y, target.X, 0.0f);
    basis->ZAxis = FVector(0.0f, 0.0f, 1.0f);
    alignas(4) byte rotationStorage[12];
    using OrthoRotation = FRotator* (__thiscall *)(const FCoords*, FRotator*);
    OrthoRotation getRotation = *(OrthoRotation*)R6GameImports::Core_FCoords_OrthoRotationSlot;
    FRotator* rotation = getRotation(basis, (FRotator*)rotationStorage);
    this->m_u8SpritePlanningAngle = (byte)(rotation->Yaw / 255); // Signed truncation, then low byte at +0x3f.
}

// R6Game.dll @ 10009360 : TransferFile
// Transfers action settings, orientation, planning floors and color in their file order.
void __thiscall AR6ActionPoint::TransferFile(AR6ActionPoint* this, FArchive* archive)
{
    using SerializeCall = void (__thiscall *)(FArchive*, void*, int);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6ActionPoint_ExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; neither try nor catch state owns local resources.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* initialArchiveVtable = *(byte**)archive;
    exceptionRegistration.state = 0;
    (*(SerializeCall*)(initialArchiveVtable + 4))(archive, &this->m_eMovementMode, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_eMovementSpeed, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_eAction, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_eActionType, 1);
    FArchive::ByteOrderSerialize(archive, &this->m_iMileStoneNum, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_vActionDirection.X, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_vActionDirection.Y, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_vActionDirection.Z, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_rActionRotation.Pitch, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_rActionRotation.Yaw, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_rActionRotation.Roll, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iPlanningFloor_0, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iPlanningFloor_1, 4);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_PlanningColor.R, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_PlanningColor.G, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_PlanningColor.B, 1);
    (*(SerializeCall*)(*(byte**)archive + 4))(archive, &this->m_PlanningColor.A, 1);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000949e : copy and rethrow TransferFile's caught wide-string pointer
__declspec(naked) void AR6ActionPoint_TransferFileCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100094b2 : report TransferFile context and forward the active exception
__declspec(naked) void AR6ActionPoint_TransferFileCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6ActionPoint_TransferFileExceptionContext // L"AR6ActionPoint::TransferFile"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013510 : destroy the saved abstract action-point base if ConditionalDestroy unwinds
__declspec(naked) void AR6ActionPoint_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_AR6ActionPointAbstract_DestructorSlot // AR6ActionPointAbstract destructor.
    }
}

// R6Game.dll @ 10014660 : initialize AR6ActionPoint class metadata and register its cleanup
void InitializeAR6ActionPointClassMetadata(void)
{
    auto staticConstructor = ImportedUObjectStaticConstructorAddress;
    UClass* withinClass = (UClass*)ImportedUObjectClass;
    UClass* parentClass = (UClass*)ImportedAR6ActionPointAbstractClass;
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)AR6ActionPointClassMetadataStorage, 0, 0x3f4, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
        L"R6ActionPoint", GPackage, configName, 0x4084004, AR6ActionPoint::InternalConstructor, staticConstructor);
    _atexit(DestroyAR6ActionPointClassMetadata);
}

// R6Game.dll @ 100150c0 : destroy AR6ActionPoint class metadata
void DestroyAR6ActionPointClassMetadata(void)
{
    UClass::~UClass((UClass*)AR6ActionPointClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 10013f90 : dispatch TransferFile's guard and catch states
__declspec(naked) void AR6ActionPoint_ExceptionHandler(void)
{
    __asm { mov eax, offset AR6ActionPoint_TransferFileExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100146f0 : bind the exported AR6ActionPoint auto-class pointer
void InitializeAR6ActionPointAutoClassPointer(void)
{
    autoclassAR6ActionPoint = (UClass*)AR6ActionPointClassMetadataStorage; // Exported slot 0x10025b0c.
}

// R6Game.dll @ 10013519 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a008
__declspec(naked) void AR6ActionPointExceptionDispatcher(void)
{
    __asm { mov eax, offset AR6ActionPoint_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
