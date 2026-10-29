#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10025b08 : auto-class pointer
UClass* autoclassAR6SoundVolume = nullptr;

// R6Game.dll data @ 10027978 : class metadata storage
// Backing storage for AR6SoundVolume::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6SoundVolumeClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a6f8 : native C++ unwind-state transitions
const unsigned int AR6SoundVolume_DestructUnwindMap[6] = {
    0xffffffff, R6GameAddresses::AR6SoundVolume_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6SoundVolume_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6SoundVolume_DestructUnwind2, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001a710 : native C++ exception function descriptor
const unsigned int AR6SoundVolume_DestructExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::AR6SoundVolume_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a9a4 : native C++ unwind-state transitions
const unsigned int AR6SoundVolume_CopyConstructUnwindMap[4] = {
    0xffffffff, R6GameAddresses::AR6SoundVolume_CopyConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6SoundVolume_CopyConstructUnwind1, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a9b4 : native C++ exception function descriptor
const unsigned int AR6SoundVolume_CopyConstructExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6SoundVolume_CopyConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017210 : AR6SoundVolume virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6SoundVolume_vftable[99] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6SoundVolume_VectorDeletingDestructor, // +0xc: AR6SoundVolume::VectorDeletingDestructor
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

// R6Game.dll @ 10001950 : return the AR6SoundVolume class object
UClass* __cdecl AR6SoundVolume::StaticClass(void)
{
    return (UClass*)AR6SoundVolumeClassMetadataStorage;
}

// R6Game.dll @ 10001960 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6SoundVolume::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6SoundVolumeClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100045a0 : destroy owned resources and inherited state
// Runs conditional shutdown, destroys owned members in reverse order, and destroys the base.
void __thiscall AR6SoundVolume::~AR6SoundVolume(AR6SoundVolume *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6SoundVolumeDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6SoundVolume_vftable;
  // Native EBP-0x10 saves this; the map destroys exit array, entry array and base in reverse order.
  exceptionRegistration.state = 2;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 1;
  DestroyFourByteFArray((FArray *)&this->m_ExitSound); // +0x41c.
  *(byte*)&exceptionRegistration.state = 0;
  DestroyFourByteFArray((FArray *)&this->m_EntrySound); // +0x410.
  exceptionRegistration.state = -1;
  AVolume::~AVolume((AVolume *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10005d50 : construct through AVolume and install the SoundVolume vtable
AR6SoundVolume* __thiscall AR6SoundVolume::AR6SoundVolume(AR6SoundVolume* this)
{
  AVolume::AVolume((AVolume*)this);
  *(const uint**)this = AR6SoundVolume_vftable;
  return this;
}

// R6Game.dll @ 10005d70 : copy-construct inherited state and members
// Copy-constructs inherited state, member values, and owned resources.
AR6SoundVolume * __thiscall AR6SoundVolume::AR6SoundVolume(AR6SoundVolume *this, const AR6SoundVolume *source)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6SoundVolumeCopyExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);

  AVolume::AVolume((AVolume *)this, (const AVolume *)source);
  *(const uint**)this = AR6SoundVolume_vftable;
  // Native EBP-0x10 saves this; state 0 protects the base, state 1 also protects the entry array.
  byte copiedSoundSlot = source->m_eSoundSlot; // Native reads this byte before state zero.
  exceptionRegistration.state = 0;
  this->m_eSoundSlot = copiedSoundSlot; // +0x40c; the write is protected.
  ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_EntrySound, (const FArray *)&source->m_EntrySound);
  *(byte*)&exceptionRegistration.state = 1;
  ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_ExitSound, (const FArray *)&source->m_ExitSound);
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10006e10 : construct SoundVolume in supplied nonnull memory
void __cdecl AR6SoundVolume::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6SoundVolume::AR6SoundVolume((AR6SoundVolume*)objectMemory);
}

// R6Game.dll @ 10013670 : destroy the volume base while unwinding the sound-volume destructor
__declspec(naked) void AR6SoundVolume_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_AVolume_DestructorSlot // AVolume destructor.
    }
}

// R6Game.dll @ 10013679 : destroy m_EntrySound while unwinding the sound-volume destructor
__declspec(naked) void AR6SoundVolume_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x410 // m_EntrySound.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013687 : destroy m_ExitSound while unwinding the sound-volume destructor
__declspec(naked) void AR6SoundVolume_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x41c // m_ExitSound.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 100139b0 : destroy the volume base while unwinding the sound-volume copy constructor
__declspec(naked) void AR6SoundVolume_CopyConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_AVolume_DestructorSlot // AVolume destructor.
    }
}

// R6Game.dll @ 100139b9 : destroy m_EntrySound while unwinding the sound-volume copy constructor
__declspec(naked) void AR6SoundVolume_CopyConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x410 // m_EntrySound.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10014aa0 : initialize sound-volume class metadata and register its cleanup
void InitializeAR6SoundVolumeClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  UClass* parentClass = (UClass*)ImportedAVolumeClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6SoundVolumeClassMetadataStorage, 0, 0x428, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
      L"R6SoundVolume", GPackage, configName, 0x4084004, AR6SoundVolume::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6SoundVolumeClassMetadata);
}

// R6Game.dll @ 10015130 : destroy SoundVolume class metadata
void DestroyAR6SoundVolumeClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6SoundVolumeClassMetadataStorage);
}

// R6Game.dll @ 10013695 : dispatch AR6SoundVolumeDestructor exception states
__declspec(naked) void AR6SoundVolumeDestructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6SoundVolume_DestructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100139c7 : dispatch AR6SoundVolumeCopy exception states
__declspec(naked) void AR6SoundVolumeCopyExceptionHandler(void)
{
  __asm { mov eax, offset AR6SoundVolume_CopyConstructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014b30 : bind the exported SoundVolume auto-class pointer to its metadata
void InitializeAR6SoundVolumeAutoClassPointer(void)
{
  autoclassAR6SoundVolume = (UClass*)AR6SoundVolumeClassMetadataStorage;
}

// R6Game.dll @ 10004670 : destroy one sound volume or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6SoundVolume::VectorDeletingDestructor(AR6SoundVolume* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x428, elementCount,
            (_func_void_void_ptr*)AR6SoundVolume::~AR6SoundVolume);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6SoundVolume::~AR6SoundVolume(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x428);
    return this;
}
