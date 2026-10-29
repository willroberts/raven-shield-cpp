// R6Abstract.dll data @ 1000d630 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractBullet::PrivateStaticClass;

// R6Abstract.dll data @ 10006340 : AR6AbstractBullet virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const NativeActorVTable AR6AbstractBullet_vftable = {
  .object = {
    .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
    .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
    .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
    .VectorDeletingDestructor = &AR6AbstractBullet::VectorDeletingDestructor, // +0x00c; native 10002a90
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

// R6Abstract.dll data @ 1000ea70 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractBullet = nullptr;

// R6Abstract.dll @ 100029b0 : return the AR6AbstractBullet class object
UClass *__cdecl AR6AbstractBullet::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 100029c0 : allocate AR6AbstractBullet using its class object and supplied object parameters
void *__cdecl AR6AbstractBullet::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                              ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 100029f0 : conditionally shut down the object, then destroy its AActor base
void __thiscall AR6AbstractBullet::~AR6AbstractBullet(AR6AbstractBullet *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleSharedActorDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const NativeActorVTable **>(this) = &AR6AbstractBullet_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  AActor::~AActor(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10002a50 : construct AActor and install the AR6AbstractBullet vtable
AR6AbstractBullet::AR6AbstractBullet() : AActor() {
  // The constructor installs AR6AbstractBullet_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002a70 : copy-construct AR6AbstractBullet from a const reference Copy-constructs through AActor
// and installs the AR6AbstractBullet vtable.
AR6AbstractBullet::AR6AbstractBullet(const AR6AbstractBullet &source) : AActor(source) {
  // The constructor installs AR6AbstractBullet_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002a90 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractBullet::VectorDeletingDestructor(AR6AbstractBullet *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x394, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractBullet::~AR6AbstractBullet);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractBullet::~AR6AbstractBullet();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x394);
  return this;
}

// R6Abstract.dll @ 100031a0 : construct AR6AbstractBullet in supplied memory when it is nonnull
void __cdecl AR6AbstractBullet::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractBullet; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 100044a0 : initialize AR6AbstractBullet class metadata and register its cleanup
void InitializeAR6AbstractBulletClassMetadata(void) {
  UClass *parentClass = (UClass *)AActor_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractBullet::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractBullet::PrivateStaticClass) UClass(EC_NativeConstructor, 0x394, 0x0, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractBullet", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractBulletClassMetadata);
}

// R6Abstract.dll @ 10004530 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractBulletClassMetadata(void) {
  autoclassAR6AbstractBullet = &AR6AbstractBullet::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c20 : destroy AR6AbstractBullet class metadata
void DestroyAR6AbstractBulletClassMetadata(void) {
  AR6AbstractBullet::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}
