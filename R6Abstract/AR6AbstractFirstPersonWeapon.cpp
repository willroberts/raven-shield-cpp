// R6Abstract.dll data @ 10006fc8 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix firstPersonWeaponDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &firstPersonWeaponDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006fc0 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry firstPersonWeaponDestructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindFirstPersonWeaponDestructionBase},
};

// R6Abstract.dll data @ 100108c8 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractFirstPersonWeapon::PrivateStaticClass;

// R6Abstract.dll data @ 10005d18 : AR6AbstractFirstPersonWeapon virtual dispatch table Entries retain selected PE32
// code addresses; slot comments identify the canonical native bodies.
const NativeActorVTable AR6AbstractFirstPersonWeapon_vftable = {
  .object = {
    .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
    .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
    .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
    .VectorDeletingDestructor = &AR6AbstractFirstPersonWeapon::VectorDeletingDestructor, // +0x00c; native 100021e0
    .ProcessEvent = &ForwardEngineAActorProcessEvent, // +0x010; native 10003ada
    .ProcessDelegate = &ForwardCoreUObjectProcessDelegate, // +0x014; native 10003882
    .ProcessState = &ForwardEngineAActorProcessState, // +0x018; native 10003ad4
    .ProcessRemoteFunction = &ForwardEngineAActorProcessRemoteFunction, // +0x01c; native 10003ace
    .Modify = &ForwardCoreUObjectModify, // +0x020; native 1000387c
    .PostLoad = &ForwardEngineAActorPostLoad, // +0x024; native 10003ac8
    .Destroy = &ForwardEngineAActorDestroy, // +0x028; native 10003ac2
    .Serialize = &ForwardEngineAActorSerialize, // +0x02c; native 10003abc
    .IsPendingKill = &ForwardEngineAActorIsPendingKill, // +0x030; native 10003ab6
    .GotoState = &ForwardCoreUObjectGotoState, // +0x034; native 10003876
    .GotoLabel = &ForwardCoreUObjectGotoLabel, // +0x038; native 10003870
    .InitExecution = &ForwardEngineAActorInitExecution, // +0x03c; native 10003ab0
    .ShutdownAfterError = &ForwardCoreUObjectShutdownAfterError, // +0x040; native 1000386a
    .PostEditChange = &ForwardEngineAActorPostEditChange, // +0x044; native 10003aaa
    .CallFunction = &ForwardCoreUObjectCallFunction, // +0x048; native 10003864
    .ScriptConsoleExec = &ForwardCoreUObjectScriptConsoleExec, // +0x04c; native 1000385e
    .Register = &ForwardCoreUObjectRegister, // +0x050; native 10003858
    .LanguageChange = &ForwardCoreUObjectLanguageChange, // +0x054; native 10003852
    .IsPendingDelete = &ForwardEngineAActorIsPendingDelete, // +0x058; native 10003aa4
    .GetPropertiesSize = &ForwardCoreUObjectGetPropertiesSize, // +0x05c; native 1000384c
    .NetDirty = &ForwardEngineAActorNetDirty, // +0x060; native 10003a9e
  },
  .GetOptimizedRepList = &ForwardEngineAActorGetOptimizedRepList, // +0x064; native 10003a98
  .GetPlayerPawn = &ForwardEngineAActorGetPlayerPawn, // +0x068; native 10003a92
  .GetPawnOrColBoxOwner = &ForwardEngineAActorGetPawnOrColBoxOwner, // +0x06c; native 10003a8c
  .IsBlockedBy = &ForwardEngineAActorIsBlockedBy, // +0x070; native 10003a86
  .GetNetPriority = &ForwardEngineAActorGetNetPriority, // +0x074; native 10003a80
  .WorldLightRadius = &ForwardEngineAActorWorldLightRadius, // +0x078; native 10003a7a
  .Tick = &ForwardEngineAActorTick, // +0x07c; native 10003a74
  .PostEditMove = &ForwardEngineAActorPostEditMove, // +0x080; native 10003a6e
  .PostEditLoad = &ForwardEngineAActorPostEditLoad, // +0x084; native 10003a68
  .PreRaytrace = &ForwardEngineAActorPreRaytrace, // +0x088; native 10003a62
  .PostRaytrace = &ForwardEngineAActorPostRaytrace, // +0x08c; native 10003a5c
  .Spawned = &ForwardEngineAActorSpawned, // +0x090; native 10003a56
  .PreNetReceive = &ForwardEngineAActorPreNetReceive, // +0x094; native 10003a50
  .PostNetReceive = &ForwardEngineAActorPostNetReceive, // +0x098; native 10003a4a
  .PostNetReceiveLocation = &ForwardEngineAActorPostNetReceiveLocation, // +0x09c; native 10003a44
  .GetSkin = &ForwardEngineAActorGetSkin, // +0x0a0; native 10003a3e
  .ToLocal = &ForwardEngineAActorToLocal, // +0x0a4; native 10003a38
  .ToWorld = &ForwardEngineAActorToWorld, // +0x0a8; native 10003a32
  .LocalToWorld = &ForwardEngineAActorLocalToWorld, // +0x0ac; native 10003a2c
  .WorldToLocal = &ForwardEngineAActorWorldToLocal, // +0x0b0; native 10003a26
  .UpdateColBox = &ForwardEngineAActorUpdateColBox, // +0x0b4; native 10003a20
  .PostScriptDestroyed = &ForwardEngineAActorPostScriptDestroyed, // +0x0b8; native 10003a1a
  .ShouldTrace = &ForwardEngineAActorShouldTrace, // +0x0bc; native 10003a14
  .GetPrimitive = &ForwardEngineAActorGetPrimitive, // +0x0c0; native 10003a0e
  .BeginTouch = &ForwardEngineAActorBeginTouch, // +0x0c4; native 10003a08
  .IsMovingBrush = &ForwardEngineAActorIsMovingBrush, // +0x0c8; native 10003a02
  .NotifyBump = &ForwardEngineAActorNotifyBump, // +0x0cc; native 100039fc
  .SetBase = &ForwardEngineAActorSetBase, // +0x0d0; native 100039f6
  .GetViewRotation = &ForwardEngineAActorGetViewRotation, // +0x0d4; native 100039f0
  .NotifyAnimEnd = &ForwardEngineAActorNotifyAnimEnd, // +0x0d8; native 100039ea
  .UpdateAnimation = &ForwardEngineAActorUpdateAnimation, // +0x0dc; native 100039e4
  .StartAnimPoll = &ForwardEngineAActorStartAnimPoll, // +0x0e0; native 100039de
  .CheckAnimFinished = &ForwardEngineAActorCheckAnimFinished, // +0x0e4; native 100039d8
  .UpdateTimers = &ForwardEngineAActorUpdateTimers, // +0x0e8; native 100039d2
  .CheckOwnerUpdated = &ForwardEngineAActorCheckOwnerUpdated, // +0x0ec; native 100039cc
  .TickAuthoritative = &ForwardEngineAActorTickAuthoritative, // +0x0f0; native 100039c6
  .TickSimulated = &ForwardEngineAActorTickSimulated, // +0x0f4; native 100039c0
  .TickSpecial = &ForwardEngineAActorTickSpecial, // +0x0f8; native 100039ba
  .PlayerControlled = &ForwardEngineAActorPlayerControlled, // +0x0fc; native 100039b4
  .IsNetRelevantFor = &ForwardEngineAActorIsNetRelevantFor, // +0x100; native 100039ae
  .RenderEditorInfo = &ForwardEngineAActorRenderEditorInfo, // +0x104; native 100039a8
  .RenderEditorSelected = &ForwardEngineAActorRenderEditorSelected, // +0x108; native 100039a2
  .SetZone = &ForwardEngineAActorSetZone, // +0x10c; native 1000399c
  .SetVolumesFromArray = &ForwardEngineAActorSetVolumesFromArray, // +0x110; native 10003996
  .SetVolumesNoArgs = &ForwardEngineAActorSetVolumesNoArgs, // +0x114; native 10003990
  .PostBeginPlay = &ForwardEngineAActorPostBeginPlay, // +0x118; native 1000398a
  .setPhysics = &ForwardEngineAActorsetPhysics, // +0x11c; native 10003984
  .performPhysics = &ForwardEngineAActorperformPhysics, // +0x120; native 1000397e
  .BoundProjectileVelocity = &ForwardEngineAActorBoundProjectileVelocity, // +0x124; native 10003978
  .processHitWall = &ForwardEngineAActorprocessHitWall, // +0x128; native 10003972
  .processLanded = &ForwardEngineAActorprocessLanded, // +0x12c; native 1000396c
  .physFalling = &ForwardEngineAActorphysFalling, // +0x130; native 10003966
  .FindSlopeRotation = &ForwardEngineAActorFindSlopeRotation, // +0x134; native 10003960
  .SmoothHitWall = &ForwardEngineAActorSmoothHitWall, // +0x138; native 1000395a
  .stepUp = &ForwardEngineAActorstepUp, // +0x13c; native 10003954
  .getKModel = &ForwardEngineAActorgetKModel, // +0x140; native 1000394e
  .physKarma = &ForwardEngineAActorphysKarma, // +0x144; native 10003948
  .preKarmaStep = &ForwardEngineAActorpreKarmaStep, // +0x148; native 10003942
  .postKarmaStep = &ForwardEngineAActorpostKarmaStep, // +0x14c; native 1000393c
  .KMP2DynKarmaInterface = &ForwardEngineAActorKMP2DynKarmaInterface, // +0x150; native 10003936
  .AddMyMarker = &ForwardEngineAActorAddMyMarker, // +0x154; native 10003930
  .AssociatedLevelGeometry = &ForwardEngineAActorAssociatedLevelGeometry, // +0x158; native 1000392a
  .HasAssociatedLevelGeometry = &ForwardEngineAActorHasAssociatedLevelGeometry, // +0x15c; native 10003924
  .PlayAnim = &ForwardEngineAActorPlayAnim, // +0x160; native 1000391e
  .IsRelevantToPawnRadar = &ForwardEngineAActorIsRelevantToPawnRadar, // +0x164; native 10003918
  .IsRelevantToPawnHeatVision = &ForwardEngineAActorIsRelevantToPawnHeatVision, // +0x168; native 10003912
  .IsRelevantToPawnHeartBeat = &ForwardEngineAActorIsRelevantToPawnHeartBeat, // +0x16c; native 1000390c
  .TickThisFrame = &ForwardEngineAActorTickThisFrame, // +0x170; native 10003906
  .CheckForErrors = &ForwardEngineAActorCheckForErrors, // +0x174; native 10003900
  .PrePath = &ForwardEngineAActorPrePath, // +0x178; native 100038fa
  .PostPath = &ForwardEngineAActorPostPath, // +0x17c; native 100038f4
  .GetProjectorBase = &ForwardEngineAActorGetProjectorBase, // +0x180; native 100038ee
};

// R6Abstract.dll data @ 100103b0 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractFirstPersonWeapon = nullptr;

// R6Abstract.dll @ 10001ee0 : return the AR6AbstractFirstPersonWeapon class object
UClass *__cdecl AR6AbstractFirstPersonWeapon::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10001ef0 : allocate AR6AbstractFirstPersonWeapon using its class object and supplied object
// parameters
void *__cdecl AR6AbstractFirstPersonWeapon::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                         ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10001f20 : conditionally shut down the object, then destroy its AR6EngineFirstPersonWeapon base
void __thiscall AR6AbstractFirstPersonWeapon::~AR6AbstractFirstPersonWeapon(AR6AbstractFirstPersonWeapon *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleAR6AbstractFirstPersonWeaponDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const NativeActorVTable **>(this) = &AR6AbstractFirstPersonWeapon_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  AR6EngineFirstPersonWeapon::~AR6EngineFirstPersonWeapon((AR6EngineFirstPersonWeapon *)this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10001f80 : construct AR6EngineFirstPersonWeapon and install the AR6AbstractFirstPersonWeapon vtable
AR6AbstractFirstPersonWeapon::AR6AbstractFirstPersonWeapon() : AR6EngineFirstPersonWeapon() {
  // The constructor installs AR6AbstractFirstPersonWeapon_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10001fa0 : copy-construct the base and reflected members
AR6AbstractFirstPersonWeapon::AR6AbstractFirstPersonWeapon(const AR6AbstractFirstPersonWeapon &source)
    : AR6EngineFirstPersonWeapon(source) {
  // The constructor installs AR6AbstractFirstPersonWeapon_vftable after the base; native EAX returns this.
  uint *destinationFlags = (uint *)((byte *)this + 0x394);
  const uint *sourceFlags = (const uint *)((const byte *)&source + 0x394);
  uint copiedFlags;

  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bWeaponBipodDeployed.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bReloadEmpty.
  *destinationFlags = copiedFlags;
  this->m_smGun = source.m_smGun;                         // +0x398, 4 bytes.
  this->m_smGun2 = source.m_smGun2;                       // +0x39c, 4 bytes.
  this->m_Empty = source.m_Empty;                         // +0x3a0, 4 bytes.
  this->m_Fire = source.m_Fire;                           // +0x3a4, 4 bytes.
  this->m_FireEmpty = source.m_FireEmpty;                 // +0x3a8, 4 bytes.
  this->m_FireLast = source.m_FireLast;                   // +0x3ac, 4 bytes.
  this->m_Neutral = source.m_Neutral;                     // +0x3b0, 4 bytes.
  this->m_Reload = source.m_Reload;                       // +0x3b4, 4 bytes.
  this->m_ReloadEmpty = source.m_ReloadEmpty;             // +0x3b8, 4 bytes.
  this->m_BipodRaise = source.m_BipodRaise;               // +0x3bc, 4 bytes.
  this->m_BipodDeploy = source.m_BipodDeploy;             // +0x3c0, 4 bytes.
  this->m_BipodDiscard = source.m_BipodDiscard;           // +0x3c4, 4 bytes.
  this->m_BipodClose = source.m_BipodClose;               // +0x3c8, 4 bytes.
  this->m_BipodNeutral = source.m_BipodNeutral;           // +0x3cc, 4 bytes.
  this->m_BipodReload = source.m_BipodReload;             // +0x3d0, 4 bytes.
  this->m_BipodReloadEmpty = source.m_BipodReloadEmpty;   // +0x3d4, 4 bytes.
  this->m_WeaponNeutralAnim = source.m_WeaponNeutralAnim; // +0x3d8, 4 bytes.
}

// R6Abstract.dll @ 100020c0 : assign the base and reflected members
AR6AbstractFirstPersonWeapon *__thiscall AR6AbstractFirstPersonWeapon::operator=(
    AR6AbstractFirstPersonWeapon *this, const AR6AbstractFirstPersonWeapon * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x394);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x394);
  uint copiedFlags;

  AR6EngineFirstPersonWeapon::operator=((AR6EngineFirstPersonWeapon *)this, (const AR6EngineFirstPersonWeapon *)source);
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bWeaponBipodDeployed.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bReloadEmpty.
  *destinationFlags = copiedFlags;
  this->m_smGun = source->m_smGun;                         // +0x398, 4 bytes.
  this->m_smGun2 = source->m_smGun2;                       // +0x39c, 4 bytes.
  this->m_Empty = source->m_Empty;                         // +0x3a0, 4 bytes.
  this->m_Fire = source->m_Fire;                           // +0x3a4, 4 bytes.
  this->m_FireEmpty = source->m_FireEmpty;                 // +0x3a8, 4 bytes.
  this->m_FireLast = source->m_FireLast;                   // +0x3ac, 4 bytes.
  this->m_Neutral = source->m_Neutral;                     // +0x3b0, 4 bytes.
  this->m_Reload = source->m_Reload;                       // +0x3b4, 4 bytes.
  this->m_ReloadEmpty = source->m_ReloadEmpty;             // +0x3b8, 4 bytes.
  this->m_BipodRaise = source->m_BipodRaise;               // +0x3bc, 4 bytes.
  this->m_BipodDeploy = source->m_BipodDeploy;             // +0x3c0, 4 bytes.
  this->m_BipodDiscard = source->m_BipodDiscard;           // +0x3c4, 4 bytes.
  this->m_BipodClose = source->m_BipodClose;               // +0x3c8, 4 bytes.
  this->m_BipodNeutral = source->m_BipodNeutral;           // +0x3cc, 4 bytes.
  this->m_BipodReload = source->m_BipodReload;             // +0x3d0, 4 bytes.
  this->m_BipodReloadEmpty = source->m_BipodReloadEmpty;   // +0x3d4, 4 bytes.
  this->m_WeaponNeutralAnim = source->m_WeaponNeutralAnim; // +0x3d8, 4 bytes.
  return this;
}

// R6Abstract.dll @ 100021e0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractFirstPersonWeapon::VectorDeletingDestructor(AR6AbstractFirstPersonWeapon *this,
                                                                        uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(
        this, 0x3dc, elementCount,
        (ArrayElementDestructor)&AR6AbstractFirstPersonWeapon::~AR6AbstractFirstPersonWeapon);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractFirstPersonWeapon::~AR6AbstractFirstPersonWeapon();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x3dc);
  return this;
}

// R6Abstract.dll @ 10003160 : construct AR6AbstractFirstPersonWeapon in supplied memory when it is nonnull
void __cdecl AR6AbstractFirstPersonWeapon::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractFirstPersonWeapon; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10004190 : destroy AR6EngineFirstPersonWeapon during AR6AbstractFirstPersonWeapon destructor unwind
// parentFrame exposes inherited EBP, not a native stack argument.
void UnwindFirstPersonWeaponDestructionBase(const byte *parentFrame) {
  AR6AbstractFirstPersonWeapon *object = *(AR6AbstractFirstPersonWeapon *const *)(parentFrame - 0x10);
  AR6EngineFirstPersonWeapon::~AR6EngineFirstPersonWeapon((AR6EngineFirstPersonWeapon *)object); // Native tail jump.
}

// R6Abstract.dll @ 10004720 : initialize AR6AbstractFirstPersonWeapon class metadata and register its cleanup
void InitializeAR6AbstractFirstPersonWeaponClassMetadata(void) {
  UClass *parentClass = (UClass *)AR6EngineFirstPersonWeapon_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractFirstPersonWeapon::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractFirstPersonWeapon::PrivateStaticClass) UClass(EC_NativeConstructor, 0x3dc, 0x0, parentClass,
      withinClass, FGuid(0, 0, 0, 0), L"R6AbstractFirstPersonWeapon", GPackage, configName, objectFlags,
      classConstructor, classStaticConstructor);
  _atexit(DestroyAR6AbstractFirstPersonWeaponClassMetadata);
}

// R6Abstract.dll @ 100047b0 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractFirstPersonWeaponClassMetadata(void) {
  autoclassAR6AbstractFirstPersonWeapon = &AR6AbstractFirstPersonWeapon::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c60 : destroy AR6AbstractFirstPersonWeapon class metadata
void DestroyAR6AbstractFirstPersonWeaponClassMetadata(void) {
  AR6AbstractFirstPersonWeapon::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004199 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractFirstPersonWeaponDestructionFrame(void) {
  __asm {
    mov eax, offset firstPersonWeaponDestructionMetadata
    jmp __CxxFrameHandler
  }
}
