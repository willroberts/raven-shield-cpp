// R6Abstract.dll data @ 1000d624 : exported four-byte event name, initially zero
FName R6ABSTRACT_GetSkill;

// R6Abstract.dll data @ 10006ee8 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix pawnDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &pawnDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006ee0 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry pawnDestructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindPawnDestructionBase},
};

// R6Abstract.dll data @ 1000f998 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractPawn::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractPawnVTable {
  NativeActorVTable actor;
  NativeImageWord32 moveToward; // +0x184.
  NativeImageWord32 HurtByVolume; // +0x188.
  NativeImageWord32 SetPrePivot; // +0x18c.
  NativeImageWord32 CheckForLedges; // +0x190.
  NativeImageWord32 physLadder; // +0x194.
  NativeImageWord32 physicsRotation; // +0x198.
  NativeImageWord32 UpdateMovementAnimation; // +0x19c.
  NativeImageWord32 R6SeePawn; // +0x1a0.
  NativeImageWord32 R6LineOfSightTo; // +0x1a4.
  NativeImageWord32 calcVelocity; // +0x1a8.
};

// R6Abstract.dll data @ 10005678 : AR6AbstractPawn virtual dispatch table Entries retain selected PE32 code addresses;
// slot comments identify the canonical native bodies.
const AR6AbstractPawnVTable AR6AbstractPawn_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractPawn::VectorDeletingDestructor, // +0x00c; native 100018b0
      .ProcessEvent = &ForwardEngineAActorProcessEvent, // +0x010; native 10003ada
      .ProcessDelegate = &ForwardCoreUObjectProcessDelegate, // +0x014; native 10003882
      .ProcessState = &ForwardEngineAActorProcessState, // +0x018; native 10003ad4
      .ProcessRemoteFunction = &ForwardEngineAActorProcessRemoteFunction, // +0x01c; native 10003ace
      .Modify = &ForwardCoreUObjectModify, // +0x020; native 1000387c
      .PostLoad = &ForwardEngineAActorPostLoad, // +0x024; native 10003ac8
      .Destroy = &ForwardEngineAPawnDestroy, // +0x028; native 10003bc4
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
    .GetOptimizedRepList = &ForwardEngineAPawnGetOptimizedRepList, // +0x064; native 10003bbe
    .GetPlayerPawn = &ForwardEngineAPawnGetPlayerPawn, // +0x068; native 10003bb8
    .GetPawnOrColBoxOwner = &ForwardEngineAPawnGetPawnOrColBoxOwner, // +0x06c; native 10003bb2
    .IsBlockedBy = &ForwardEngineAPawnIsBlockedBy, // +0x070; native 10003bac
    .GetNetPriority = &ForwardEngineAPawnGetNetPriority, // +0x074; native 10003ba6
    .WorldLightRadius = &ForwardEngineAActorWorldLightRadius, // +0x078; native 10003a7a
    .Tick = &ForwardEngineAActorTick, // +0x07c; native 10003a74
    .PostEditMove = &ForwardEngineAActorPostEditMove, // +0x080; native 10003a6e
    .PostEditLoad = &ForwardEngineAActorPostEditLoad, // +0x084; native 10003a68
    .PreRaytrace = &ForwardEngineAActorPreRaytrace, // +0x088; native 10003a62
    .PostRaytrace = &ForwardEngineAActorPostRaytrace, // +0x08c; native 10003a5c
    .Spawned = &ForwardEngineAActorSpawned, // +0x090; native 10003a56
    .PreNetReceive = &ForwardEngineAPawnPreNetReceive, // +0x094; native 10003ba0
    .PostNetReceive = &ForwardEngineAPawnPostNetReceive, // +0x098; native 10003b9a
    .PostNetReceiveLocation = &ForwardEngineAPawnPostNetReceiveLocation, // +0x09c; native 10003b94
    .GetSkin = &ForwardEngineAActorGetSkin, // +0x0a0; native 10003a3e
    .ToLocal = &ForwardEngineAActorToLocal, // +0x0a4; native 10003a38
    .ToWorld = &ForwardEngineAActorToWorld, // +0x0a8; native 10003a32
    .LocalToWorld = &ForwardEngineAActorLocalToWorld, // +0x0ac; native 10003a2c
    .WorldToLocal = &ForwardEngineAActorWorldToLocal, // +0x0b0; native 10003a26
    .UpdateColBox = &ForwardEngineAActorUpdateColBox, // +0x0b4; native 10003a20
    .PostScriptDestroyed = &ForwardEngineAActorPostScriptDestroyed, // +0x0b8; native 10003a1a
    .ShouldTrace = &ForwardEngineAPawnShouldTrace, // +0x0bc; native 10003b8e
    .GetPrimitive = &ForwardEngineAActorGetPrimitive, // +0x0c0; native 10003a0e
    .BeginTouch = &ForwardEngineAActorBeginTouch, // +0x0c4; native 10003a08
    .IsMovingBrush = &ForwardEngineAActorIsMovingBrush, // +0x0c8; native 10003a02
    .NotifyBump = &ForwardEngineAPawnNotifyBump, // +0x0cc; native 10003b88
    .SetBase = &ForwardEngineAPawnSetBase, // +0x0d0; native 10003b82
    .GetViewRotation = &ForwardEngineAActorGetViewRotation, // +0x0d4; native 100039f0
    .NotifyAnimEnd = &ForwardEngineAPawnNotifyAnimEnd, // +0x0d8; native 10003b7c
    .UpdateAnimation = &ForwardEngineAActorUpdateAnimation, // +0x0dc; native 100039e4
    .StartAnimPoll = &ForwardEngineAActorStartAnimPoll, // +0x0e0; native 100039de
    .CheckAnimFinished = &ForwardEngineAActorCheckAnimFinished, // +0x0e4; native 100039d8
    .UpdateTimers = &ForwardEngineAActorUpdateTimers, // +0x0e8; native 100039d2
    .CheckOwnerUpdated = &ForwardEngineAPawnCheckOwnerUpdated, // +0x0ec; native 10003b76
    .TickAuthoritative = &ForwardEngineAActorTickAuthoritative, // +0x0f0; native 100039c6
    .TickSimulated = &ForwardEngineAPawnTickSimulated, // +0x0f4; native 10003b70
    .TickSpecial = &ForwardEngineAPawnTickSpecial, // +0x0f8; native 10003b6a
    .PlayerControlled = &ForwardEngineAPawnPlayerControlled, // +0x0fc; native 10003b64
    .IsNetRelevantFor = &ForwardEngineAPawnIsNetRelevantFor, // +0x100; native 10003b5e
    .RenderEditorInfo = &ForwardEngineAActorRenderEditorInfo, // +0x104; native 100039a8
    .RenderEditorSelected = &ForwardEngineAPawnRenderEditorSelected, // +0x108; native 10003b58
    .SetZone = &ForwardEngineAPawnSetZone, // +0x10c; native 10003b52
    .SetVolumesFromArray = &ForwardEngineAActorSetVolumesFromArray, // +0x110; native 10003996
    .SetVolumesNoArgs = &ForwardEngineAActorSetVolumesNoArgs, // +0x114; native 10003990
    .PostBeginPlay = &ForwardEngineAPawnPostBeginPlay, // +0x118; native 10003b4c
    .setPhysics = &ForwardEngineAActorsetPhysics, // +0x11c; native 10003984
    .performPhysics = &ForwardEngineAPawnperformPhysics, // +0x120; native 10003b46
    .BoundProjectileVelocity = &ForwardEngineAActorBoundProjectileVelocity, // +0x124; native 10003978
    .processHitWall = &ForwardEngineAPawnprocessHitWall, // +0x128; native 10003b40
    .processLanded = &ForwardEngineAPawnprocessLanded, // +0x12c; native 10003b3a
    .physFalling = &ForwardEngineAPawnphysFalling, // +0x130; native 10003b34
    .FindSlopeRotation = &ForwardEngineAPawnFindSlopeRotation, // +0x134; native 10003b2e
    .SmoothHitWall = &ForwardEngineAPawnSmoothHitWall, // +0x138; native 10003b28
    .stepUp = &ForwardEngineAPawnstepUp, // +0x13c; native 10003b22
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
    .CheckForErrors = &ForwardEngineAPawnCheckForErrors, // +0x174; native 10003b1c
    .PrePath = &ForwardEngineAActorPrePath, // +0x178; native 100038fa
    .PostPath = &ForwardEngineAActorPostPath, // +0x17c; native 100038f4
    .GetProjectorBase = &ForwardEngineAActorGetProjectorBase, // +0x180; native 100038ee
  },
  .moveToward = &ForwardEngineAPawnmoveToward, // +0x184; native 10003b16
  .HurtByVolume = &ForwardEngineAPawnHurtByVolume, // +0x188; native 10003b10
  .SetPrePivot = &ForwardEngineAPawnSetPrePivot, // +0x18c; native 10003b0a
  .CheckForLedges = &ForwardEngineAPawnCheckForLedges, // +0x190; native 10003b04
  .physLadder = &ForwardEngineAPawnphysLadder, // +0x194; native 10003afe
  .physicsRotation = &ForwardEngineAPawnphysicsRotation, // +0x198; native 10003af8
  .UpdateMovementAnimation = &ForwardEngineAPawnUpdateMovementAnimation, // +0x19c; native 10003af2
  .R6SeePawn = &ForwardEngineAPawnR6SeePawn, // +0x1a0; native 10003aec
  .R6LineOfSightTo = &ForwardEngineAPawnR6LineOfSightTo, // +0x1a4; native 10003ae6
  .calcVelocity = &ForwardEngineAPawncalcVelocity, // +0x1a8; native 10003ae0
};

// R6Abstract.dll data @ 1000d628 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractPawn = nullptr;

// R6Abstract.dll @ 10001720 : float eventGetSkill(AR6AbstractPawn * this, uchar eSkillName) Dispatches GetSkill and
// returns its updated event result.
float __thiscall AR6AbstractPawn::eventGetSkill(AR6AbstractPawn *this, uchar eSkillName) {
  struct {
    uchar eSkillName;
    uchar padding[3];
    float ReturnValue;
  } parameters;
  const NativeUObjectVTable *vtable;
  UFunction *function;

  vtable = *reinterpret_cast<const NativeUObjectVTable *const *>(this);
  parameters.ReturnValue = 0.0f;
  parameters.eSkillName = eSkillName;
  function = UObject::FindFunctionChecked(this, R6ABSTRACT_GetSkill, 0);
  // The virtual dispatcher receives this in ECX and writes the return slot in the parameter buffer.
  using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
  EventDispatcher processEvent = *reinterpret_cast<const EventDispatcher *>(&vtable->ProcessEvent);
  processEvent(this, function, &parameters, nullptr);
  return parameters.ReturnValue;
}

// R6Abstract.dll @ 10001770 : return the AR6AbstractPawn class object
UClass *__cdecl AR6AbstractPawn::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10001780 : allocate AR6AbstractPawn using its class object and supplied object parameters
void *__cdecl AR6AbstractPawn::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 100017b0 : conditionally shut down the object, then destroy its APawn base
void __thiscall AR6AbstractPawn::~AR6AbstractPawn(AR6AbstractPawn *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleAR6AbstractPawnDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractPawnVTable **>(this) = &AR6AbstractPawn_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  APawn::~APawn(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10001810 : construct APawn and install the AR6AbstractPawn vtable
AR6AbstractPawn::AR6AbstractPawn() : APawn() {
  // The constructor installs AR6AbstractPawn_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10001830 Copy-constructs APawn and merges bShowLog (matching-package +0x660, mask 1).
AR6AbstractPawn::AR6AbstractPawn(const AR6AbstractPawn &source) : APawn(source) {
  // The constructor installs AR6AbstractPawn_vftable after the base; native EAX returns this.
  uint sourceBits = *(const uint *)((const byte *)&source + 0x660);
  uint destinationBits = *(uint *)((byte *)this + 0x660);
  *(uint *)((byte *)this + 0x660) = destinationBits ^ ((sourceBits ^ destinationBits) & 1);
}

// R6Abstract.dll @ 10001870 Assigns APawn and merges bShowLog while preserving the other 31 bits at +0x660.
AR6AbstractPawn *__thiscall AR6AbstractPawn::operator=(AR6AbstractPawn *this, const AR6AbstractPawn * source) {
  APawn::operator=(this, source);
  uint sourceBits = *(const uint *)((const byte *)source + 0x660);
  uint destinationBits = *(uint *)((byte *)this + 0x660);
  *(uint *)((byte *)this + 0x660) = destinationBits ^ ((sourceBits ^ destinationBits) & 1);
  return this;
}

// R6Abstract.dll @ 100018b0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractPawn::VectorDeletingDestructor(AR6AbstractPawn *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x664, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractPawn::~AR6AbstractPawn);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractPawn::~AR6AbstractPawn();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x664);
  return this;
}

// R6Abstract.dll @ 10003120 : construct AR6AbstractPawn in supplied memory when it is nonnull
void __cdecl AR6AbstractPawn::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractPawn; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 100040e0 : destroy APawn during Pawn destructor unwind parentFrame exposes inherited EBP, not a
// native stack argument.
void UnwindPawnDestructionBase(const byte *parentFrame) {
  AR6AbstractPawn *object = *(AR6AbstractPawn *const *)(parentFrame - 0x10);
  APawn::~APawn(object); // Native tail jump.
}

// R6Abstract.dll @ 10004360 : initialize AR6AbstractPawn class metadata and register its cleanup
void InitializeAR6AbstractPawnClassMetadata(void) {
  UClass *parentClass = (UClass *)APawn_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractPawn::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractPawn::PrivateStaticClass) UClass(EC_NativeConstructor, 0x664, 0x0, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractPawn", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractPawnClassMetadata);
}

// R6Abstract.dll @ 100043f0 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractPawnClassMetadata(void) {
  autoclassAR6AbstractPawn = &AR6AbstractPawn::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c00 : destroy AR6AbstractPawn class metadata
void DestroyAR6AbstractPawnClassMetadata(void) {
  AR6AbstractPawn::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 100040e9 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractPawnDestructionFrame(void) {
  __asm {
    mov eax, offset pawnDestructionMetadata
    jmp __CxxFrameHandler
  }
}
