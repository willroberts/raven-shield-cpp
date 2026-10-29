#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10024134 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6InstructionSoundVolume::execUseSound.
unsigned int intAR6InstructionSoundVolumeexecUseSound = R6GameAddresses::AR6InstructionSoundVolume_execUseSound;

// R6Game.dll data @ 10025b1c : auto-class pointer
UClass* autoclassAR6InstructionSoundVolume = nullptr;

// R6Game.dll data @ 10026538 : class metadata storage
// Backing storage for AR6InstructionSoundVolume::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6InstructionSoundVolumeClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10027e84 : native registration result byte
unsigned char AR6InstructionSoundVolumeexecUseSoundRegistrationResult = 0;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001ad54 : native C++ unwind-state transitions
const unsigned int AR6InstructionSoundVolume_execUseSoundUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001ad64 : native typed-pointer and catch-all handler pair
const unsigned int AR6InstructionSoundVolume_execUseSoundCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6InstructionSoundVolume_execUseSoundCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6InstructionSoundVolume_execUseSoundCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001ad84 : native C++ try-block ranges
const unsigned int AR6InstructionSoundVolume_execUseSoundTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6InstructionSoundVolume_execUseSoundCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001ad98 : native C++ exception function descriptor
const unsigned int AR6InstructionSoundVolume_execUseSoundExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6InstructionSoundVolume_execUseSoundUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6InstructionSoundVolume_execUseSoundTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017530 : AR6InstructionSoundVolume virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6InstructionSoundVolume_vftable[99] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6InstructionSoundVolume_VectorDeletingDestructor, // +0xc: AR6InstructionSoundVolume::VectorDeletingDestructor
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

// R6Game.dll @ 100019d0 : return the AR6InstructionSoundVolume class object
UClass* __cdecl AR6InstructionSoundVolume::StaticClass(void)
{
    return (UClass*)AR6InstructionSoundVolumeClassMetadataStorage;
}

// R6Game.dll @ 100019e0 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6InstructionSoundVolume::operator_new(
    uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6InstructionSoundVolumeClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100047a0 : conditionally shut down the instruction volume and destroy its sound-volume base
void __thiscall AR6InstructionSoundVolume::~AR6InstructionSoundVolume(AR6InstructionSoundVolume* this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&SoundVolumeDerivedDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6InstructionSoundVolume_vftable;
  // Native EBP-0x10 saves this for the cleanup shared with WaterVolume.
  exceptionRegistration.state = 0;
  UObject::ConditionalDestroy((UObject*)this);
  exceptionRegistration.state = -1;
  AR6SoundVolume::~AR6SoundVolume((AR6SoundVolume*)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100047f0 : assign inherited state and members
// Assigns the volume base, sound arrays and instruction fields; preserves upper 31 derived flag bits.
AR6InstructionSoundVolume * __thiscall AR6InstructionSoundVolume::operator=(AR6InstructionSoundVolume *this,
    const AR6InstructionSoundVolume *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x43c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x43c);
  uint copiedFlags;

  AVolume::operator=((AVolume *)this, (const AVolume *)source);
  this->m_eSoundSlot = source->m_eSoundSlot; // +0x40c.
  AssignFourByteFArray((FArray *)&this->m_EntrySound, (const FArray *)&source->m_EntrySound);
  AssignFourByteFArray((FArray *)&this->m_ExitSound, (const FArray *)&source->m_ExitSound);
  this->m_iBoxNumber = source->m_iBoxNumber; // +0x428.
  this->m_iSoundIndex = source->m_iSoundIndex; // +0x42c.
  this->m_iHudStep = source->m_iHudStep; // +0x430.
  this->m_IDHudStep = source->m_IDHudStep; // +0x434.
  this->m_fTimerStep = source->m_fTimerStep; // +0x438.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bSoundIsPlaying.
  *destinationFlags = copiedFlags;
  this->m_fTime = source->m_fTime; // +0x440.
  this->m_fTimerSound = source->m_fTimerSound; // +0x444.
  this->m_fTimeHud = source->m_fTimeHud; // +0x448.
  this->m_sndIntructionSoundStop = source->m_sndIntructionSoundStop; // +0x44c.
  this->m_TrainingMgr = source->m_TrainingMgr; // +0x450.
  return this;
}

// R6Game.dll @ 10005e40 : construct through AVolume and install the InstructionSoundVolume vtable
AR6InstructionSoundVolume* __thiscall AR6InstructionSoundVolume::AR6InstructionSoundVolume(
    AR6InstructionSoundVolume* this)
{
  AVolume::AVolume((AVolume*)this);
  *(const uint**)this = AR6InstructionSoundVolume_vftable;
  return this;
}

// R6Game.dll @ 10005e60 : copy-construct inherited state and members
// Copies the sound-volume base and instruction fields; preserves upper 31 derived flag bits.
AR6InstructionSoundVolume* __thiscall AR6InstructionSoundVolume::AR6InstructionSoundVolume(
    AR6InstructionSoundVolume* this, const AR6InstructionSoundVolume* source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x43c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x43c);
  uint copiedFlags;

  AR6SoundVolume::AR6SoundVolume((AR6SoundVolume *)this, (const AR6SoundVolume *)source);
  *(const uint**)this = AR6InstructionSoundVolume_vftable;
  this->m_iBoxNumber = source->m_iBoxNumber; // +0x428.
  this->m_iSoundIndex = source->m_iSoundIndex; // +0x42c.
  this->m_iHudStep = source->m_iHudStep; // +0x430.
  this->m_IDHudStep = source->m_IDHudStep; // +0x434.
  this->m_fTimerStep = source->m_fTimerStep; // +0x438.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bSoundIsPlaying.
  *destinationFlags = copiedFlags;
  this->m_fTime = source->m_fTime; // +0x440.
  this->m_fTimerSound = source->m_fTimerSound; // +0x444.
  this->m_fTimeHud = source->m_fTimeHud; // +0x448.
  this->m_sndIntructionSoundStop = source->m_sndIntructionSoundStop; // +0x44c.
  this->m_TrainingMgr = source->m_TrainingMgr; // +0x450.
  return this;
}

// R6Game.dll @ 10006e30 : construct InstructionSoundVolume in supplied nonnull memory
void __cdecl AR6InstructionSoundVolume::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6InstructionSoundVolume::AR6InstructionSoundVolume((AR6InstructionSoundVolume*)objectMemory);
}

// R6Game.dll @ 10006e80 : return whether the engine has an audio subsystem
void __thiscall AR6InstructionSoundVolume::execUseSound(AR6InstructionSoundVolume* this, FFrame* stack, void* result)
{
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&InstructionSoundUseSoundExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  byte** codeCursor = (byte**)((byte*)stack + 0xc);
  byte* nextCode = (byte*)((uint)*codeCursor + 1U);
  *codeCursor = nextCode;
  bool hasDebugInfo = *nextCode == 0x42;
  // Native saves ESP at EBP-0x10 and enters state 0 only after advancing and testing the bytecode.
  exceptionRegistration.state = 0;
  if (hasDebugInfo) {
    UObject* debugContext = *(UObject**)((byte*)stack + 8);
    *codeCursor = (byte*)((uint)nextCode + 1U);
    ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
    debugNativeTable[0x42](debugContext, stack, nullptr);
  }
  UEngine* engine = *(UEngine**)Importedg_pEngineAddress;
  bool hasAudio = engine->Audio != nullptr; // Audio +0x48; the volume receiver is unused.
  uint previousExceptionAddress = exceptionRegistration.previousAddress;
  *(uint*)result = (uint)hasAudio;
  __writefsdword(0, previousExceptionAddress);
}

// R6Game.dll @ 10006ef5 : rethrow UseSound's caught four-byte value
__declspec(naked) void AR6InstructionSoundVolume_execUseSoundCatchPointer(void)
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

// R6Game.dll @ 10015140 : destroy InstructionSoundVolume class metadata
void DestroyAR6InstructionSoundVolumeClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6InstructionSoundVolumeClassMetadataStorage);
}

// R6Game.dll @ 10006f09 : report UseSound context and rethrow the active exception
__declspec(naked) void AR6InstructionSoundVolume_execUseSoundCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6InstructionSoundVolume_execUseSoundExceptionContext // L"AR6InstructionSoundVolume::execUseSound"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014b40 : initialize instruction-sound-volume class metadata and register its cleanup
void InitializeAR6InstructionSoundVolumeClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6InstructionSoundVolumeClassMetadataStorage, 0, 0x454, 0, (UClass*)AR6SoundVolumeClassMetadataStorage,
      withinClass, FGuid(0, 0, 0, 0), L"R6InstructionSoundVolume", GPackage, configName, 0x4084004,
      AR6InstructionSoundVolume::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6InstructionSoundVolumeClassMetadata);
}

// R6Game.dll @ 10013d90 : dispatch InstructionSoundUseSound exception states
__declspec(naked) void InstructionSoundUseSoundExceptionHandler(void)
{
  __asm { mov eax, offset AR6InstructionSoundVolume_execUseSoundExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014bc0 : bind the exported InstructionSoundVolume auto-class pointer to its metadata
void InitializeAR6InstructionSoundVolumeAutoClassPointer(void)
{
  autoclassAR6InstructionSoundVolume = (UClass*)AR6InstructionSoundVolumeClassMetadataStorage;
}

// R6Game.dll @ 100048d0 : destroy one instruction sound volume or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6InstructionSoundVolume::VectorDeletingDestructor(
    AR6InstructionSoundVolume* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x454, elementCount,
            (_func_void_void_ptr*)AR6InstructionSoundVolume::~AR6InstructionSoundVolume);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6InstructionSoundVolume::~AR6InstructionSoundVolume(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x454);
    return this;
}

// R6Game.dll @ 10014e20 : register AR6InstructionSoundVolume::execUseSound at native index 2732
void InitializeAR6InstructionSoundVolumeNativeUseSound(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6InstructionSoundVolumeexecUseSound;
    byte& nativeRegistrationResult = AR6InstructionSoundVolumeexecUseSoundRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2732, nativeExecPointerWord);
}
