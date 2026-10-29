// R6Abstract.dll data @ 10007264 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix insertionZoneCheckForErrorsMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000003,
  .unwindMap = &insertionZoneCheckForErrorsUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &insertionZoneCheckForErrorsTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007250 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry insertionZoneCheckForErrorsTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000001,
    .catchHighState = 0x00000002,
    .handlerCount = 0x00000002,
    .handlers = &insertionZoneCheckForErrorsCatchMap,
  },
};

// R6Abstract.dll data @ 10007230 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry insertionZoneCheckForErrorsCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -24,
    .handler = &ForwardAR6AbstractInsertionZoneCheckForErrorsCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportAR6AbstractInsertionZoneCheckForErrorsException,
  },
};

// R6Abstract.dll data @ 10007218 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry insertionZoneCheckForErrorsUnwindMap[3] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = 0x00000000, .cleanup = &UnwindInsertionZonePlanningWarning},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10006f0c : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix insertionZoneDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &insertionZoneDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006f04 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry insertionZoneDestructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindInsertionZoneDestructionBase},
};

// R6Abstract.dll data @ 1000db40 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractInsertionZone::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractInsertionZoneVTable {
  NativeActorVTable actor;
  NativeImageWord32 ProscribedPathTo; // +0x184.
  NativeImageWord32 addReachSpecs; // +0x188.
  NativeImageWord32 PostaddReachSpecs; // +0x18c.
  NativeImageWord32 InitForPathFinding; // +0x190.
  NativeImageWord32 SetupForcedPath; // +0x194.
  NativeImageWord32 ClearPaths; // +0x198.
  NativeImageWord32 FindBase; // +0x19c.
  NativeImageWord32 PrunePaths; // +0x1a0.
  NativeImageWord32 IsIdentifiedAs; // +0x1a4.
  NativeImageWord32 ReviewPath; // +0x1a8.
  NativeImageWord32 CheckSymmetry; // +0x1ac.
};

// R6Abstract.dll data @ 10005828 : AR6AbstractInsertionZone virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const AR6AbstractInsertionZoneVTable AR6AbstractInsertionZone_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractInsertionZone::VectorDeletingDestructor, // +0x00c; native 10001a40
      .ProcessEvent = &ForwardEngineAActorProcessEvent, // +0x010; native 10003ada
      .ProcessDelegate = &ForwardCoreUObjectProcessDelegate, // +0x014; native 10003882
      .ProcessState = &ForwardEngineAActorProcessState, // +0x018; native 10003ad4
      .ProcessRemoteFunction = &ForwardEngineAActorProcessRemoteFunction, // +0x01c; native 10003ace
      .Modify = &ForwardCoreUObjectModify, // +0x020; native 1000387c
      .PostLoad = &ForwardEngineAActorPostLoad, // +0x024; native 10003ac8
      .Destroy = &ForwardEngineANavigationPointDestroy, // +0x028; native 10003c1e
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
    .PostEditMove = &ForwardEngineANavigationPointPostEditMove, // +0x080; native 10003c18
    .PostEditLoad = &ForwardEngineAActorPostEditLoad, // +0x084; native 10003a68
    .PreRaytrace = &ForwardEngineAActorPreRaytrace, // +0x088; native 10003a62
    .PostRaytrace = &ForwardEngineAActorPostRaytrace, // +0x08c; native 10003a5c
    .Spawned = &ForwardEngineANavigationPointSpawned, // +0x090; native 10003c12
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
    .SetVolumesFromArray = &ForwardEngineANavigationPointSetVolumes, // +0x110; native 10003c0c
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
    .CheckForErrors = &AR6AbstractInsertionZone::CheckForErrors, // +0x174; native 100032a0
    .PrePath = &ForwardEngineAActorPrePath, // +0x178; native 100038fa
    .PostPath = &ForwardEngineAActorPostPath, // +0x17c; native 100038f4
    .GetProjectorBase = &ForwardEngineAActorGetProjectorBase, // +0x180; native 100038ee
  },
  .ProscribedPathTo = &ForwardEngineANavigationPointProscribedPathTo, // +0x184; native 10003c06
  .addReachSpecs = &ForwardEngineAPlayerStartaddReachSpecs, // +0x188; native 10003c00
  .PostaddReachSpecs = &ForwardEngineANavigationPointPostaddReachSpecs, // +0x18c; native 10003bfa
  .InitForPathFinding = &ForwardEngineANavigationPointInitForPathFinding, // +0x190; native 10003bf4
  .SetupForcedPath = &ForwardEngineANavigationPointSetupForcedPath, // +0x194; native 10003bee
  .ClearPaths = &ForwardEngineANavigationPointClearPaths, // +0x198; native 10003be8
  .FindBase = &ForwardEngineANavigationPointFindBase, // +0x19c; native 10003be2
  .PrunePaths = &ForwardEngineANavigationPointPrunePaths, // +0x1a0; native 10003bdc
  .IsIdentifiedAs = &ForwardEngineANavigationPointIsIdentifiedAs, // +0x1a4; native 10003bd6
  .ReviewPath = &ForwardEngineANavigationPointReviewPath, // +0x1a8; native 10003bd0
  .CheckSymmetry = &ForwardEngineANavigationPointCheckSymmetry, // +0x1ac; native 10003bca
};

// R6Abstract.dll data @ 10010dd0 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractInsertionZone = nullptr;

// R6Abstract.dll @ 10001920 : return the AR6AbstractInsertionZone class object
UClass *__cdecl AR6AbstractInsertionZone::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10001930 : allocate AR6AbstractInsertionZone using its class object and supplied object parameters
void *__cdecl AR6AbstractInsertionZone::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                     ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10001960 : conditionally shut down the object, then destroy its APlayerStart base
void __thiscall AR6AbstractInsertionZone::~AR6AbstractInsertionZone(AR6AbstractInsertionZone *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleAR6AbstractInsertionZoneDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractInsertionZoneVTable **>(this) = &AR6AbstractInsertionZone_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  APlayerStart::~APlayerStart(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 100019c0 : construct APlayerStart and install the AR6AbstractInsertionZone vtable
AR6AbstractInsertionZone::AR6AbstractInsertionZone() : APlayerStart() {
  // The constructor installs AR6AbstractInsertionZone_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 100019e0 Copy-constructs through APlayerStart and copies m_iInsertionNumber at +0x3f0.
AR6AbstractInsertionZone::AR6AbstractInsertionZone(const AR6AbstractInsertionZone &source) : APlayerStart(source) {
  // The constructor installs AR6AbstractInsertionZone_vftable after the base; native EAX returns this.
  this->m_iInsertionNumber = source.m_iInsertionNumber; // +0x3f0, 4 bytes.
}

// R6Abstract.dll @ 10001a10 Assigns through APlayerStart and copies m_iInsertionNumber at +0x3f0.
AR6AbstractInsertionZone *__thiscall AR6AbstractInsertionZone::operator=(AR6AbstractInsertionZone *this,
                                                                         const AR6AbstractInsertionZone * source) {
  APlayerStart::operator=(this, source);
  this->m_iInsertionNumber = source->m_iInsertionNumber; // +0x3f0, 4 bytes.
  return this;
}

// R6Abstract.dll @ 10001a40 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractInsertionZone::VectorDeletingDestructor(AR6AbstractInsertionZone *this,
                                                                    uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x3f4, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractInsertionZone::~AR6AbstractInsertionZone);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractInsertionZone::~AR6AbstractInsertionZone();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x3f4);
  return this;
}

// R6Abstract.dll @ 10003130 : construct AR6AbstractInsertionZone in supplied memory when it is nonnull
void __cdecl AR6AbstractInsertionZone::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractInsertionZone; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 100032a0 : CheckForErrors Reports an unset first planning-floor value after the base navigation
// check.
void __thiscall AR6AbstractInsertionZone::CheckForErrors(AR6AbstractInsertionZone *this) {
  ANavigationPoint::CheckForErrors(this);
  if (this->m_iPlanningFloor_0 == -1) { // Actor +0x70.
    // Owns the string at inherited EBP-0x24; state 1 -> 0 destroys it on unwind as well as scope exit.
    FString message = FString::Printf((const ushort *)L"Planning floor is -1");
    const ushort *messageText = *message;
    FFeedbackContext *feedback = *(FFeedbackContext **)GWarn_exref;
    feedback->MapCheck_Add(1, this, messageText);
  }
}

// R6Abstract.dll @ 10003323 : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardAR6AbstractInsertionZoneCheckForErrorsCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x14);
  *throwValue = *(ushort **)(parentFrame - 0x18);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 10003337 : report method context before forwarding the active exception
__declspec(noreturn) void ReportAR6AbstractInsertionZoneCheckForErrorsException(void) {
  appUnwindf((const ushort *)L"%s", L"AR6AbstractInsertionZone::CheckForErrors");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 100042d0 : exceptional destruction of CheckForErrors' scoped FString message
// Construct-backed entry: EBP-0x24, state 1 -> 0, tail jump to FString::~FString through IAT 100050a0.
extern NativeCodeLabel UnwindInsertionZonePlanningWarning;

// R6Abstract.dll @ 10004100 : destroy APlayerStart during AR6AbstractInsertionZone destructor unwind parentFrame
// exposes inherited EBP, not a native stack argument.
void UnwindInsertionZoneDestructionBase(const byte *parentFrame) {
  AR6AbstractInsertionZone *object = *(AR6AbstractInsertionZone *const *)(parentFrame - 0x10);
  APlayerStart::~APlayerStart(object); // Native tail jump.
}

// R6Abstract.dll @ 10004850 : initialize AR6AbstractInsertionZone class metadata and register its cleanup
void InitializeAR6AbstractInsertionZoneClassMetadata(void) {
  UClass *parentClass = (UClass *)APlayerStart_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractInsertionZone::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractInsertionZone::PrivateStaticClass) UClass(EC_NativeConstructor, 0x3f4, 0x0, parentClass,
      withinClass, FGuid(0, 0, 0, 0), L"R6AbstractInsertionZone", GPackage, configName, objectFlags,
      classConstructor, classStaticConstructor);
  _atexit(DestroyAR6AbstractInsertionZoneClassMetadata);
}

// R6Abstract.dll @ 100048e0 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractInsertionZoneClassMetadata(void) {
  autoclassAR6AbstractInsertionZone = &AR6AbstractInsertionZone::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c80 : destroy AR6AbstractInsertionZone class metadata
void DestroyAR6AbstractInsertionZoneClassMetadata(void) {
  AR6AbstractInsertionZone::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004109 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractInsertionZoneDestructionFrame(void) {
  __asm {
    mov eax, offset insertionZoneDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 100042d9 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractInsertionZoneCheckForErrorsFrame(void) {
  __asm {
    mov eax, offset insertionZoneCheckForErrorsMetadata
    jmp __CxxFrameHandler
  }
}
