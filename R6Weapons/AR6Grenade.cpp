// R6Weapons.dll data @ 10007180 : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6GrenadeClassNameStorage[] = u"AR6Grenade";

// R6Weapons.dll data @ 10007acc : grenadeDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry grenadeDestructorUnwindMap[1] = {
    {.previousState = -1, .cleanup = &UnwindGrenadeDestructorBase},
};

// R6Weapons.dll data @ 10007ad4 : grenadeDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix grenadeDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &grenadeDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006c70 : exported AR6Grenade virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeActorVTable AR6Grenade_vftable = {
    .QueryInterface = &ForwardUObjectQueryInterface,
    .AddRef = &ForwardUObjectAddRef,
    .Release = &ForwardUObjectRelease,
    .VectorDeletingDestructor = &AR6Grenade::VectorDeletingDestructor,
    .ProcessEvent = &ForwardAActorProcessEvent,
    .ProcessDelegate = &ForwardUObjectProcessDelegate,
    .ProcessState = &ForwardAActorProcessState,
    .ProcessRemoteFunction = &ForwardAActorProcessRemoteFunction,
    .Modify = &ForwardUObjectModify,
    .PostLoad = &ForwardAActorPostLoad,
    .Destroy = &ForwardAActorDestroy,
    .Serialize = &ForwardAActorSerialize,
    .IsPendingKill = &ForwardAActorIsPendingKill,
    .GotoState = &ForwardUObjectGotoState,
    .GotoLabel = &ForwardUObjectGotoLabel,
    .InitExecution = &ForwardAActorInitExecution,
    .ShutdownAfterError = &ForwardUObjectShutdownAfterError,
    .PostEditChange = &ForwardAActorPostEditChange,
    .CallFunction = &ForwardUObjectCallFunction,
    .ScriptConsoleExec = &ForwardUObjectScriptConsoleExec,
    .Register = &ForwardUObjectRegister,
    .LanguageChange = &ForwardUObjectLanguageChange,
    .IsPendingDelete = &ForwardAActorIsPendingDelete,
    .GetPropertiesSize = &ForwardUObjectGetPropertiesSize,
    .NetDirty = &ForwardAActorNetDirty,
    .GetOptimizedRepList = &ForwardAActorGetOptimizedRepList,
    .GetPlayerPawn = &ForwardAActorGetPlayerPawn,
    .GetPawnOrColBoxOwner = &ForwardAActorGetPawnOrColBoxOwner,
    .IsBlockedBy = &AR6Bullet::IsBlockedBy,
    .GetNetPriority = &ForwardAActorGetNetPriority,
    .WorldLightRadius = &ForwardAActorWorldLightRadius,
    .Tick = &ForwardAActorTick,
    .PostEditMove = &ForwardAActorPostEditMove,
    .PostEditLoad = &ForwardAActorPostEditLoad,
    .PreRaytrace = &ForwardAActorPreRaytrace,
    .PostRaytrace = &ForwardAActorPostRaytrace,
    .Spawned = &ForwardAActorSpawned,
    .PreNetReceive = &ForwardAActorPreNetReceive,
    .PostNetReceive = &AR6Grenade::PostNetReceive,
    .PostNetReceiveLocation = &ForwardAActorPostNetReceiveLocation,
    .GetSkin = &ForwardAActorGetSkin,
    .ToLocal = &ForwardAActorToLocal,
    .ToWorld = &ForwardAActorToWorld,
    .LocalToWorld = &ForwardAActorLocalToWorld,
    .WorldToLocal = &ForwardAActorWorldToLocal,
    .UpdateColBox = &ForwardAActorUpdateColBox,
    .PostScriptDestroyed = &ForwardAActorPostScriptDestroyed,
    .ShouldTrace = &AR6Bullet::ShouldTrace,
    .GetPrimitive = &ForwardAActorGetPrimitive,
    .BeginTouch = &ForwardAActorBeginTouch,
    .IsMovingBrush = &ForwardAActorIsMovingBrush,
    .NotifyBump = &ForwardAActorNotifyBump,
    .SetBase = &ForwardAActorSetBase,
    .GetViewRotation = &ForwardAActorGetViewRotation,
    .NotifyAnimEnd = &ForwardAActorNotifyAnimEnd,
    .UpdateAnimation = &ForwardAActorUpdateAnimation,
    .StartAnimPoll = &ForwardAActorStartAnimPoll,
    .CheckAnimFinished = &ForwardAActorCheckAnimFinished,
    .UpdateTimers = &ForwardAActorUpdateTimers,
    .CheckOwnerUpdated = &ForwardAActorCheckOwnerUpdated,
    .TickAuthoritative = &ForwardAActorTickAuthoritative,
    .TickSimulated = &ForwardAActorTickSimulated,
    .TickSpecial = &ForwardAActorTickSpecial,
    .PlayerControlled = &ForwardAActorPlayerControlled,
    .IsNetRelevantFor = &ForwardAActorIsNetRelevantFor,
    .RenderEditorInfo = &ForwardAActorRenderEditorInfo,
    .RenderEditorSelected = &ForwardAActorRenderEditorSelected,
    .SetZone = &ForwardAActorSetZone,
    .SetVolumesFromArray = &ForwardAActorSetVolumesFromArray,
    .SetVolumes = &ForwardAActorSetVolumes,
    .PostBeginPlay = &ForwardAActorPostBeginPlay,
    .setPhysics = &ForwardAActorsetPhysics,
    .performPhysics = &ForwardAActorperformPhysics,
    .BoundProjectileVelocity = &ForwardAActorBoundProjectileVelocity,
    .processHitWall = &ForwardAActorprocessHitWall,
    .processLanded = &ForwardAActorprocessLanded,
    .physFalling = &ForwardAActorphysFalling,
    .FindSlopeRotation = &ForwardAActorFindSlopeRotation,
    .SmoothHitWall = &ForwardAActorSmoothHitWall,
    .stepUp = &ForwardAActorstepUp,
    .getKModel = &ForwardAActorgetKModel,
    .physKarma = &ForwardAActorphysKarma,
    .preKarmaStep = &ForwardAActorpreKarmaStep,
    .postKarmaStep = &ForwardAActorpostKarmaStep,
    .KMP2DynKarmaInterface = &ForwardAActorKMP2DynKarmaInterface,
    .AddMyMarker = &ForwardAActorAddMyMarker,
    .AssociatedLevelGeometry = &ForwardAActorAssociatedLevelGeometry,
    .HasAssociatedLevelGeometry = &ForwardAActorHasAssociatedLevelGeometry,
    .PlayAnim = &ForwardAActorPlayAnim,
    .IsRelevantToPawnRadar = &ForwardAActorIsRelevantToPawnRadar,
    .IsRelevantToPawnHeatVision = &ForwardAActorIsRelevantToPawnHeatVision,
    .IsRelevantToPawnHeartBeat = &ForwardAActorIsRelevantToPawnHeartBeat,
    .TickThisFrame = &ForwardAActorTickThisFrame,
    .CheckForErrors = &ForwardAActorCheckForErrors,
    .PrePath = &ForwardAActorPrePath,
    .PostPath = &ForwardAActorPostPath,
    .GetProjectorBase = &ForwardAActorGetProjectorBase,
};

// R6Weapons.dll data @ 1000c600 : exported AR6Grenade::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6GrenadeClassMetadataStorage[0x508] = {};
UClass &AR6Grenade::PrivateStaticClass = *(UClass *)AR6GrenadeClassMetadataStorage;

// R6Weapons.dll @ 10001150 : update cached physics and stop rotation when replication clears physics
// The base handler runs first; zero physics clears old mode and resets rotation only after a nonzero old mode.
void __thiscall AR6Grenade::PostNetReceive(AR6Grenade *this) {
  AActor::PostNetReceive((AActor *)this);
  const byte currentPhysics = this->Physics;    // Native retains the post-base byte in AL.
  if (currentPhysics == 0) {                    // +0x2c.
    uchar previousPhysics = this->m_eOldPhysic; // +0x3f8.
    this->m_eOldPhysic = 0;
    if (previousPhysics != 0) {
      this->RotationRate.Pitch = 0; // +0x2f0.
      this->RotationRate.Yaw = 0;
      this->RotationRate.Roll = 0;
    }
  } else {
    this->m_eOldPhysic = currentPhysics;
  }
}

// R6Weapons.dll @ 10002900 : return the AR6Grenade class object
// Returns the class metadata object at native address 0x1000c600.
UClass *__cdecl AR6Grenade::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10002910 : allocate AR6Grenade using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6Grenade::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10002940 : destroy the grenade and its bullet base
// Runs conditional shutdown with bullet-base exception cleanup, then destroys the bullet base.
void __thiscall AR6Grenade::~AR6Grenade(AR6Grenade *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchGrenadeDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeActorVTable **)this = &AR6Grenade_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = -1;
  AR6Bullet::~AR6Bullet((AR6Bullet *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10002990 : construct the bullet base and install the grenade vtable
// Adds no member initialization after the bullet constructor returns.
AR6Grenade *__thiscall AR6Grenade::AR6Grenade(AR6Grenade *this) {
  AR6Bullet::AR6Bullet((AR6Bullet *)this);
  *(const NativeActorVTable **)this = &AR6Grenade_vftable;
  return this;
}

// R6Weapons.dll @ 100029b0 : copy-construct the base and reflected members
// Copies three bytes, raw float/damage words and shallow references, preserving the early flag snapshot.
AR6Grenade *__thiscall AR6Grenade::AR6Grenade(AR6Grenade *this, const AR6Grenade *source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x400);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x400);

  AR6Bullet::AR6Bullet((AR6Bullet *)this, (const AR6Bullet *)source);
  *(const NativeActorVTable **)this = &AR6Grenade_vftable;
  *(byte *)&this->m_eOldPhysic = *(const byte *)&source->m_eOldPhysic;                   // +0x3f8.
  *(byte *)&this->m_eExplosionSoundType = *(const byte *)&source->m_eExplosionSoundType; // +0x3f9.
  *(byte *)&this->m_eGrenadeType = *(const byte *)&source->m_eGrenadeType;               // +0x3fa.
  const int fragmentCount = source->m_iNumberOfFragments;                                // +0x3fc.
  const uint earlyDestinationFlags = *destinationFlags;
  this->m_iNumberOfFragments = fragmentCount;
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags;
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bFirstImpact.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bDestroyedByImpact.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fDuration = *(const uint *)&source->m_fDuration;                                     // +0x404.
  *(uint *)&this->m_fShakeRadius = *(const uint *)&source->m_fShakeRadius;                               // +0x408.
  *(uint *)&this->m_fEffectiveOutsideKillRadius = *(const uint *)&source->m_fEffectiveOutsideKillRadius; // +0x40c.
  this->m_sndExplosionSound = source->m_sndExplosionSound;                                               // +0x410.
  this->m_sndExplosionSoundStop = source->m_sndExplosionSoundStop;                                       // +0x414.
  this->m_sndExplodeMetal = source->m_sndExplodeMetal;                                                   // +0x418.
  this->m_sndExplodeWater = source->m_sndExplodeWater;                                                   // +0x41c.
  this->m_sndExplodeAir = source->m_sndExplodeAir;                                                       // +0x420.
  this->m_sndExplodeDirt = source->m_sndExplodeDirt;                                                     // +0x424.
  this->m_ImpactSound = source->m_ImpactSound;                                                           // +0x428.
  this->m_ImpactGroundSound = source->m_ImpactGroundSound;                                               // +0x42c.
  this->m_ImpactWaterSound = source->m_ImpactWaterSound;                                                 // +0x430.
  this->m_sndEarthQuake = source->m_sndEarthQuake;                                                       // +0x434.
  this->m_Weapon = source->m_Weapon;                                                                     // +0x438.
  this->m_pEmmiter = source->m_pEmmiter;                                                                 // +0x43c.
  this->m_pExplosionParticles = source->m_pExplosionParticles;                                           // +0x440.
  this->m_pExplosionParticlesLOW = source->m_pExplosionParticlesLOW;                                     // +0x444.
  this->m_pExplosionLight = source->m_pExplosionLight;                                                   // +0x448.
  this->m_GrenadeDecalClass = source->m_GrenadeDecalClass;                                               // +0x44c.
  *(uint *)&this->m_DmgPercentStand.fHead = *(const uint *)&source->m_DmgPercentStand.fHead;             // +0x450.
  *(uint *)&this->m_DmgPercentStand.fBody = *(const uint *)&source->m_DmgPercentStand.fBody;             // +0x454.
  *(uint *)&this->m_DmgPercentStand.fArms = *(const uint *)&source->m_DmgPercentStand.fArms;             // +0x458.
  *(uint *)&this->m_DmgPercentStand.fLegs = *(const uint *)&source->m_DmgPercentStand.fLegs;             // +0x45c.
  *(uint *)&this->m_DmgPercentCrouch.fHead = *(const uint *)&source->m_DmgPercentCrouch.fHead;           // +0x460.
  *(uint *)&this->m_DmgPercentCrouch.fBody = *(const uint *)&source->m_DmgPercentCrouch.fBody;           // +0x464.
  *(uint *)&this->m_DmgPercentCrouch.fArms = *(const uint *)&source->m_DmgPercentCrouch.fArms;           // +0x468.
  *(uint *)&this->m_DmgPercentCrouch.fLegs = *(const uint *)&source->m_DmgPercentCrouch.fLegs;           // +0x46c.
  *(uint *)&this->m_DmgPercentProne.fHead = *(const uint *)&source->m_DmgPercentProne.fHead;             // +0x470.
  *(uint *)&this->m_DmgPercentProne.fBody = *(const uint *)&source->m_DmgPercentProne.fBody;             // +0x474.
  *(uint *)&this->m_DmgPercentProne.fArms = *(const uint *)&source->m_DmgPercentProne.fArms;             // +0x478.
  *(uint *)&this->m_DmgPercentProne.fLegs = *(const uint *)&source->m_DmgPercentProne.fLegs;             // +0x47c.
  return this;
}

// R6Weapons.dll @ 10002b80 : assign the base and reflected members
// Assigns byte/scalar payloads and two selected flag bits without changing the vtable or adding a guard.
AR6Grenade *__thiscall AR6Grenade::operator=(AR6Grenade *this, const AR6Grenade * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x400);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x400);

  AR6Bullet::operator=((AR6Bullet *)this, (const AR6Bullet *)source);
  *(byte *)&this->m_eOldPhysic = *(const byte *)&source->m_eOldPhysic;                   // +0x3f8.
  *(byte *)&this->m_eExplosionSoundType = *(const byte *)&source->m_eExplosionSoundType; // +0x3f9.
  *(byte *)&this->m_eGrenadeType = *(const byte *)&source->m_eGrenadeType;               // +0x3fa.
  const int fragmentCount = source->m_iNumberOfFragments;                                // +0x3fc.
  const uint earlyDestinationFlags = *destinationFlags;
  this->m_iNumberOfFragments = fragmentCount;
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags;
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bFirstImpact.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bDestroyedByImpact.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fDuration = *(const uint *)&source->m_fDuration;                                     // +0x404.
  *(uint *)&this->m_fShakeRadius = *(const uint *)&source->m_fShakeRadius;                               // +0x408.
  *(uint *)&this->m_fEffectiveOutsideKillRadius = *(const uint *)&source->m_fEffectiveOutsideKillRadius; // +0x40c.
  this->m_sndExplosionSound = source->m_sndExplosionSound;                                               // +0x410.
  this->m_sndExplosionSoundStop = source->m_sndExplosionSoundStop;                                       // +0x414.
  this->m_sndExplodeMetal = source->m_sndExplodeMetal;                                                   // +0x418.
  this->m_sndExplodeWater = source->m_sndExplodeWater;                                                   // +0x41c.
  this->m_sndExplodeAir = source->m_sndExplodeAir;                                                       // +0x420.
  this->m_sndExplodeDirt = source->m_sndExplodeDirt;                                                     // +0x424.
  this->m_ImpactSound = source->m_ImpactSound;                                                           // +0x428.
  this->m_ImpactGroundSound = source->m_ImpactGroundSound;                                               // +0x42c.
  this->m_ImpactWaterSound = source->m_ImpactWaterSound;                                                 // +0x430.
  this->m_sndEarthQuake = source->m_sndEarthQuake;                                                       // +0x434.
  this->m_Weapon = source->m_Weapon;                                                                     // +0x438.
  this->m_pEmmiter = source->m_pEmmiter;                                                                 // +0x43c.
  this->m_pExplosionParticles = source->m_pExplosionParticles;                                           // +0x440.
  this->m_pExplosionParticlesLOW = source->m_pExplosionParticlesLOW;                                     // +0x444.
  this->m_pExplosionLight = source->m_pExplosionLight;                                                   // +0x448.
  this->m_GrenadeDecalClass = source->m_GrenadeDecalClass;                                               // +0x44c.
  *(uint *)&this->m_DmgPercentStand.fHead = *(const uint *)&source->m_DmgPercentStand.fHead;             // +0x450.
  *(uint *)&this->m_DmgPercentStand.fBody = *(const uint *)&source->m_DmgPercentStand.fBody;             // +0x454.
  *(uint *)&this->m_DmgPercentStand.fArms = *(const uint *)&source->m_DmgPercentStand.fArms;             // +0x458.
  *(uint *)&this->m_DmgPercentStand.fLegs = *(const uint *)&source->m_DmgPercentStand.fLegs;             // +0x45c.
  *(uint *)&this->m_DmgPercentCrouch.fHead = *(const uint *)&source->m_DmgPercentCrouch.fHead;           // +0x460.
  *(uint *)&this->m_DmgPercentCrouch.fBody = *(const uint *)&source->m_DmgPercentCrouch.fBody;           // +0x464.
  *(uint *)&this->m_DmgPercentCrouch.fArms = *(const uint *)&source->m_DmgPercentCrouch.fArms;           // +0x468.
  *(uint *)&this->m_DmgPercentCrouch.fLegs = *(const uint *)&source->m_DmgPercentCrouch.fLegs;           // +0x46c.
  *(uint *)&this->m_DmgPercentProne.fHead = *(const uint *)&source->m_DmgPercentProne.fHead;             // +0x470.
  *(uint *)&this->m_DmgPercentProne.fBody = *(const uint *)&source->m_DmgPercentProne.fBody;             // +0x474.
  *(uint *)&this->m_DmgPercentProne.fArms = *(const uint *)&source->m_DmgPercentProne.fArms;             // +0x478.
  *(uint *)&this->m_DmgPercentProne.fLegs = *(const uint *)&source->m_DmgPercentProne.fLegs;             // +0x47c.
  return this;
}

// R6Weapons.dll @ 100039b0 : construct a grenade in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6Grenade::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6Grenade::AR6Grenade((AR6Grenade *)objectMemory);
}

// R6Weapons.dll @ 100055d0 : unwind the bullet base during grenade destruction
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindGrenadeDestructorBase(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  AR6Bullet::~AR6Bullet(bullet);
}

// R6Weapons.dll @ 100055d8 : dispatch grenade destruction exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchGrenadeDestructorException(void) {
  __asm {
    mov eax, offset grenadeDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005ce0 : destroy AR6Grenade class metadata
// Supplies the registered metadata receiver; native code tail-jumps to imported UClass destruction.
void DestroyAR6GrenadeClassMetadata(void) {
  UClass::~UClass(&AR6Grenade::PrivateStaticClass);
}

// R6Weapons.dll @ 10002d50 : destroy one AR6Grenade or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6Grenade::VectorDeletingDestructor(AR6Grenade *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6Grenade *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6Grenade::~AR6Grenade); // AR6Grenade destructor.
    destroyElements(this, 0x480, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6Grenade::~AR6Grenade(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x480); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000c0e0 : exported class pointer autoclassAR6Grenade
UClass *autoclassAR6Grenade = nullptr;

// R6Weapons.dll @ 10005890 : bind the exported AR6Grenade class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6GrenadeAutoClass(void) {
  autoclassAR6Grenade = &AR6Grenade::PrivateStaticClass;
}

// R6Weapons.dll @ 10005810 : initialize AR6Grenade class metadata and register its destruction
// Caches imported pointers before config lookup; supplies zero class flags/GUID and the local parent metadata address.
void InitializeAR6GrenadeClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6Grenade::PrivateStaticClass, (ENativeConstructor)0, 0x480, 0, &AR6Bullet::PrivateStaticClass,
                 withinClass, classGuid, (const ushort *)(r6GrenadeClassNameStorage + 1), GPackage, configName,
                 0x4084004, AR6Grenade::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6GrenadeClassMetadata);
}
