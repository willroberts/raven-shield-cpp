#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 100246d0 : class metadata storage
// Backing storage for AR6WaterVolume::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6WaterVolumeClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10025b18 : auto-class pointer
UClass* autoclassAR6WaterVolume = nullptr;

// R6Game.dll data @ 100173a0 : AR6WaterVolume virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6WaterVolume_vftable[99] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6WaterVolume_VectorDeletingDestructor, // +0xc: AR6WaterVolume::VectorDeletingDestructor
    R6GameAddresses::ForwardImported_AActor_ProcessEvent, // +0x10: AActor::ProcessEvent
    R6GameAddresses::ForwardImported_UObject_ProcessDelegate, // +0x14: UObject::ProcessDelegate
    R6GameAddresses::ForwardImported_AActor_ProcessState, // +0x18: AActor::ProcessState
    R6GameAddresses::ForwardImported_AActor_ProcessRemoteFunction, // +0x1c: AActor::ProcessRemoteFunction
    R6GameAddresses::ForwardImported_UObject_Modify, // +0x20: UObject::Modify
    R6GameAddresses::ForwardImported_ABrush_PostLoad, // +0x24: ABrush::PostLoad
    R6GameAddresses::ForwardImported_AActor_Destroy, // +0x28: AActor::Destroy
    R6GameAddresses::ForwardImported_AActor_Serialize, // +0x2c: AActor::Serialize
    R6GameAddresses::ForwardImported_AActor_IsPendingKill, // +0x30: AActor::IsPendingKill
    R6GameAddresses::ForwardImported_UObject_GotoState, // +0x34: UObject::GotoState
    R6GameAddresses::ForwardImported_UObject_GotoLabel, // +0x38: UObject::GotoLabel
    R6GameAddresses::ForwardImported_AActor_InitExecution, // +0x3c: AActor::InitExecution
    R6GameAddresses::ForwardImported_UObject_ShutdownAfterError, // +0x40: UObject::ShutdownAfterError
    R6GameAddresses::ForwardImported_ABrush_PostEditChange, // +0x44: ABrush::PostEditChange
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
    R6GameAddresses::ForwardImported_ABrush_ToLocal, // +0xa4: ABrush::ToLocal
    R6GameAddresses::ForwardImported_ABrush_ToWorld, // +0xa8: ABrush::ToWorld
    R6GameAddresses::ForwardImported_AActor_LocalToWorld, // +0xac: AActor::LocalToWorld
    R6GameAddresses::ForwardImported_AActor_WorldToLocal, // +0xb0: AActor::WorldToLocal
    R6GameAddresses::ForwardImported_AActor_UpdateColBox, // +0xb4: AActor::UpdateColBox
    R6GameAddresses::ForwardImported_AActor_PostScriptDestroyed, // +0xb8: AActor::PostScriptDestroyed
    R6GameAddresses::ForwardImported_AVolume_ShouldTrace, // +0xbc: AVolume::ShouldTrace
    R6GameAddresses::ForwardImported_ABrush_GetPrimitive, // +0xc0: ABrush::GetPrimitive
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
    R6GameAddresses::ForwardImported_AVolume_SetVolumesFromList, // +0x110: AVolume::SetVolumes
    R6GameAddresses::ForwardImported_AVolume_SetVolumes, // +0x114: AVolume::SetVolumes
    R6GameAddresses::ForwardImported_AVolume_PostBeginPlay, // +0x118: AVolume::PostBeginPlay
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
    R6GameAddresses::ForwardImported_ABrush_CheckForErrors, // +0x174: ABrush::CheckForErrors
    R6GameAddresses::ForwardImported_AActor_PrePath, // +0x178: AActor::PrePath
    R6GameAddresses::ForwardImported_AActor_PostPath, // +0x17c: AActor::PostPath
    R6GameAddresses::ForwardImported_AActor_GetProjectorBase, // +0x180: AActor::GetProjectorBase
    R6GameAddresses::ForwardImported_ABrush_CopyPosRotScaleFrom, // +0x184: ABrush::CopyPosRotScaleFrom
    R6GameAddresses::ForwardImported_ABrush_InitPosRotScale, // +0x188: ABrush::InitPosRotScale
};

// R6Game.dll @ 10001990 : return the AR6WaterVolume class object
UClass* __cdecl AR6WaterVolume::StaticClass(void)
{
    return (UClass*)AR6WaterVolumeClassMetadataStorage;
}

// R6Game.dll @ 100019a0 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6WaterVolume::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6WaterVolumeClassMetadataStorage, outer, objectName, objectFlags, nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100046e0 : conditionally shut down the water volume and destroy its sound-volume base
void __thiscall AR6WaterVolume::~AR6WaterVolume(AR6WaterVolume* this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&SoundVolumeDerivedDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6WaterVolume_vftable;
  // Native EBP-0x10 saves this; state-zero cleanup is shared with InstructionSoundVolume.
  exceptionRegistration.state = 0;
  UObject::ConditionalDestroy((UObject*)this);
  exceptionRegistration.state = -1;
  AR6SoundVolume::~AR6SoundVolume((AR6SoundVolume*)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10005e00 : construct through AVolume and install the water-volume vtable
AR6WaterVolume* __thiscall AR6WaterVolume::AR6WaterVolume(AR6WaterVolume* this)
{
  AVolume::AVolume((AVolume*)this);
  *(const uint**)this = AR6WaterVolume_vftable;
  return this;
}

// R6Game.dll @ 10005e20 : copy the sound-volume base and install the water-volume vtable
AR6WaterVolume* __thiscall AR6WaterVolume::AR6WaterVolume(AR6WaterVolume* this, const AR6WaterVolume* source)
{
  AR6SoundVolume::AR6SoundVolume((AR6SoundVolume*)this, (const AR6SoundVolume*)source);
  *(const uint**)this = AR6WaterVolume_vftable;
  return this;
}

// R6Game.dll @ 10006e20 : construct a water volume in supplied nonnull memory
void __cdecl AR6WaterVolume::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6WaterVolume::AR6WaterVolume((AR6WaterVolume*)objectMemory);
}

// R6Game.dll @ 10015150 : destroy water-volume class metadata
void DestroyAR6WaterVolumeClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6WaterVolumeClassMetadataStorage);
}

// R6Game.dll @ 10004730 : destroy one water volume or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6WaterVolume::VectorDeletingDestructor(AR6WaterVolume* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x428, elementCount,
            (_func_void_void_ptr*)AR6WaterVolume::~AR6WaterVolume);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6WaterVolume::~AR6WaterVolume(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x428);
    return this;
}

// R6Game.dll @ 10014bd0 : initialize water-volume class metadata and register its cleanup
void InitializeAR6WaterVolumeClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6WaterVolumeClassMetadataStorage, 0, 0x428, 0, (UClass*)AR6SoundVolumeClassMetadataStorage,
      withinClass, FGuid(0, 0, 0, 0), L"R6WaterVolume", GPackage, configName, 0x4084004,
      AR6WaterVolume::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6WaterVolumeClassMetadata);
}

// R6Game.dll @ 10014c50 : bind the exported water-volume auto-class pointer to its metadata
void InitializeAR6WaterVolumeAutoClassPointer(void)
{
  autoclassAR6WaterVolume = (UClass*)AR6WaterVolumeClassMetadataStorage; // Slot 0x10025b18.
}
