#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10027960 : auto-class pointer
UClass* autoclassAR6MultiPlayerGameInfo = nullptr;

// R6Game.dll data @ 10028390 : class metadata storage
// Backing storage for AR6MultiPlayerGameInfo::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6MultiPlayerGameInfoClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a980 : native C++ unwind-state transitions
const unsigned int AR6MultiPlayerGameInfo_DestructUnwindMap[2] = {
    0xffffffff, R6GameAddresses::AR6MultiPlayerGameInfo_DestructUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a988 : native C++ exception function descriptor
const unsigned int AR6MultiPlayerGameInfo_DestructExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::AR6MultiPlayerGameInfo_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017920 : AR6MultiPlayerGameInfo virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6MultiPlayerGameInfo_vftable[100] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6MultiPlayerGameInfo_VectorDeletingDestructor, // +0xc: AR6MultiPlayerGameInfo::VectorDeletingDestructor
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
    R6GameAddresses::AR6GameInfo_PostBeginPlay, // +0x118: PostBeginPlay
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
    R6GameAddresses::AR6GameInfo_InitGameInfoGameService, // +0x184: InitGameInfoGameService
    R6GameAddresses::AR6GameInfo_MasterServerManager, // +0x188: AR6GameInfo::MasterServerManager
    R6GameAddresses::AR6GameInfo_AbortScoreSubmission, // +0x18c: AbortScoreSubmission
};

// R6Game.dll @ 10001900 : return the AR6MultiPlayerGameInfo class object
UClass* __cdecl AR6MultiPlayerGameInfo::StaticClass(void)
{
    return (UClass*)AR6MultiPlayerGameInfoClassMetadataStorage;
}

// R6Game.dll @ 10001910 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6MultiPlayerGameInfo::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6MultiPlayerGameInfoClassMetadataStorage, outer, objectName, objectFlags, nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10004540 : assign inherited state and members
// Assigns the base, one flag, two times and two object references; preserves upper 31 derived flag bits.
AR6MultiPlayerGameInfo * __thiscall AR6MultiPlayerGameInfo::operator=(AR6MultiPlayerGameInfo *this,
    const AR6MultiPlayerGameInfo *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x66c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x66c);
  uint copiedFlags;

  AR6GameInfo::operator=((AR6GameInfo *)this, (const AR6GameInfo *)source);
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_TeamSelectionLocked.
  *destinationFlags = copiedFlags;
  this->m_fNextCheckPlayerReadyTime = source->m_fNextCheckPlayerReadyTime; // +0x670.
  this->m_fLastUpdateTime = source->m_fLastUpdateTime; // +0x674.
  this->m_missionObjTimer = source->m_missionObjTimer; // +0x678.
  this->m_sndSoundTimeFailure = source->m_sndSoundTimeFailure; // +0x67c.
  return this;
}

// R6Game.dll @ 10005c20 : conditionally shut down the object and destroy its game-info base
void __thiscall AR6MultiPlayerGameInfo::~AR6MultiPlayerGameInfo(AR6MultiPlayerGameInfo* this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6MultiPlayerGameInfoDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6MultiPlayerGameInfo_vftable;
  // Native EBP-0x10 saves this for state-zero base destruction if ConditionalDestroy throws.
  exceptionRegistration.state = 0;
  UObject::ConditionalDestroy((UObject*)this);
  exceptionRegistration.state = -1;
  AR6GameInfo::~AR6GameInfo((AR6GameInfo*)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10005c70 : copy-construct inherited state and members
// Copies the base, one flag, two times and two object references; preserves upper 31 derived flag bits.
AR6MultiPlayerGameInfo * __thiscall AR6MultiPlayerGameInfo::AR6MultiPlayerGameInfo(AR6MultiPlayerGameInfo *this,
    const AR6MultiPlayerGameInfo *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x66c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x66c);
  uint copiedFlags;

  AR6GameInfo::AR6GameInfo((AR6GameInfo *)this, (const AR6GameInfo *)source);
  *(const uint**)this = AR6MultiPlayerGameInfo_vftable;
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_TeamSelectionLocked.
  *destinationFlags = copiedFlags;
  this->m_fNextCheckPlayerReadyTime = source->m_fNextCheckPlayerReadyTime; // +0x670.
  this->m_fLastUpdateTime = source->m_fLastUpdateTime; // +0x674.
  this->m_missionObjTimer = source->m_missionObjTimer; // +0x678.
  this->m_sndSoundTimeFailure = source->m_sndSoundTimeFailure; // +0x67c.
  return this;
}

// R6Game.dll @ 10006df0 : construct the game-info base and install the multiplayer vtable
AR6MultiPlayerGameInfo* __thiscall AR6MultiPlayerGameInfo::AR6MultiPlayerGameInfo(AR6MultiPlayerGameInfo* this)
{
  AR6GameInfo::AR6GameInfo((AR6GameInfo*)this);
  *(const uint**)this = AR6MultiPlayerGameInfo_vftable;
  return this;
}

// R6Game.dll @ 10006e70 : construct multiplayer game info in supplied nonnull memory
void __cdecl AR6MultiPlayerGameInfo::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6MultiPlayerGameInfo::AR6MultiPlayerGameInfo((AR6MultiPlayerGameInfo*)objectMemory);
}

// R6Game.dll @ 10013990 : destroy the base while unwinding the multiplayer destructor
__declspec(naked) void AR6MultiPlayerGameInfo_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp R6GameAddresses::AR6GameInfo_Destruct // ~AR6GameInfo.
    }
}

// R6Game.dll @ 10015170 : destroy multiplayer game-info class metadata
void DestroyAR6MultiPlayerGameInfoClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6MultiPlayerGameInfoClassMetadataStorage);
}

// R6Game.dll @ 10005ce0 : destroy one multiplayer game-info object or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6MultiPlayerGameInfo::VectorDeletingDestructor(AR6MultiPlayerGameInfo* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x680, elementCount,
            (_func_void_void_ptr*)AR6MultiPlayerGameInfo::~AR6MultiPlayerGameInfo);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6MultiPlayerGameInfo::~AR6MultiPlayerGameInfo(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x680);
    return this;
}

// R6Game.dll @ 10013998 : dispatch the multiplayer destructor's base cleanup state
__declspec(naked) void AR6MultiPlayerGameInfoDestructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6MultiPlayerGameInfo_DestructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014cf0 : initialize multiplayer game-info class metadata and register its cleanup
void InitializeAR6MultiPlayerGameInfoClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6MultiPlayerGameInfoClassMetadataStorage, 0, 0x680, 4, (UClass*)AR6GameInfoClassMetadataStorage,
      withinClass, FGuid(0, 0, 0, 0), L"R6MultiPlayerGameInfo", GPackage, configName, 0x4084004,
      AR6MultiPlayerGameInfo::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6MultiPlayerGameInfoClassMetadata);
}

// R6Game.dll @ 10014d70 : bind the exported multiplayer auto-class pointer to its metadata
void InitializeAR6MultiPlayerGameInfoAutoClassPointer(void)
{
  autoclassAR6MultiPlayerGameInfo = (UClass*)AR6MultiPlayerGameInfoClassMetadataStorage; // Slot 0x10027960.
}
