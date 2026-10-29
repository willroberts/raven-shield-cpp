// R6Abstract.dll data @ 10006f80 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix hUDConstructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &hUDConstructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006f78 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry hUDConstructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindHUDConstructionBase},
};

// R6Abstract.dll data @ 10006f5c : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix hUDDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &hUDDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006f4c : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry hUDDestructionUnwindMap[2] = {
  {.previousState = -1, .cleanup = &UnwindHUDDestructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindHUDDestructionStatusDetail},
};

// R6Abstract.dll data @ 1000d118 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractHUD::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractHUDVTable {
  NativeActorVTable actor;
  NativeImageWord32 DrawRadar; // +0x184.
  NativeImageWord32 DrawInGameMap; // +0x188.
  NativeImageWord32 DrawSpecificModeInfo; // +0x18c.
};

// R6Abstract.dll data @ 10005b88 : AR6AbstractHUD virtual dispatch table Entries retain selected PE32 code addresses;
// slot comments identify the canonical native bodies.
const AR6AbstractHUDVTable AR6AbstractHUD_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractHUD::VectorDeletingDestructor, // +0x00c; native 10001e70
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
  },
  .DrawRadar = &ForwardEngineAHUDDrawRadar, // +0x184; native 10003c36
  .DrawInGameMap = &ForwardEngineAHUDDrawInGameMap, // +0x188; native 10003c30
  .DrawSpecificModeInfo = &ForwardEngineAHUDDrawSpecificModeInfo, // +0x18c; native 10003c2a
};

// R6Abstract.dll data @ 10010dd8 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractHUD = nullptr;

// R6Abstract.dll @ 10001c30 : return the AR6AbstractHUD class object
UClass *__cdecl AR6AbstractHUD::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10001c40 : allocate AR6AbstractHUD using its class object and supplied object parameters
void *__cdecl AR6AbstractHUD::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10001c70 : destroy the object, its string members, and its base
void __thiscall AR6AbstractHUD::~AR6AbstractHUD(AR6AbstractHUD *this) {
  int destructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractHUDDestructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractHUDVTable **>(this) = &AR6AbstractHUD_vftable;
  destructionState = 1;
  UObject::ConditionalDestroy(this);
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szStatusDetail); // +0x500.
  destructionState = -1;
  AHUD::~AHUD(this);
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10001ce0 : construct AHUD and leave the status-detail string storage uninitialized
AR6AbstractHUD *__thiscall AR6AbstractHUD::AR6AbstractHUD(AR6AbstractHUD *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int constructionState;

  constructionState = -1;
  exceptionHandler = &HandleAR6AbstractHUDConstructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AHUD::AHUD(this);
  constructionState = 0;
  *reinterpret_cast<const AR6AbstractHUDVTable **>(this) = &AR6AbstractHUD_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szStatusDetail); // +0x500; no writes.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10001d30 : copy-construct the base and reflected members
AR6AbstractHUD *__thiscall AR6AbstractHUD::AR6AbstractHUD(AR6AbstractHUD *this, const AR6AbstractHUD *source) {
  int constructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractHUDConstructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((int)this + 0x4f4);
  const uint *sourceFlags = (const uint *)((int)source + 0x4f4);
  uint copiedFlags;

  AHUD::AHUD(this, source);
  *reinterpret_cast<const AR6AbstractHUDVTable **>(this) = &AR6AbstractHUD_vftable;
  this->m_iCycleHUDLayer = source->m_iCycleHUDLayer; // +0x4f0, 4 bytes.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bToggleHelmet.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bGetRes.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fNewHUDResX = *(const uint *)&source->m_fNewHUDResX; // +0x4f8, 4 bytes.
  *(uint *)&this->m_fNewHUDResY = *(const uint *)&source->m_fNewHUDResY; // +0x4fc, 4 bytes.
  constructionState = 0;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szStatusDetail,
                               (const FStringNoInit *)&source->m_szStatusDetail); // +0x500.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10001df0 : assign the base, scalar fields, selected flags, and string members
AR6AbstractHUD *__thiscall AR6AbstractHUD::operator=(AR6AbstractHUD *this, const AR6AbstractHUD * source) {
  uint *destinationFlags = (uint *)((int)this + 0x4f4);
  const uint *sourceFlags = (const uint *)((int)source + 0x4f4);
  uint copiedFlags;

  AHUD::operator=(this, source);
  this->m_iCycleHUDLayer = source->m_iCycleHUDLayer; // +0x4f0, 4 bytes.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bToggleHelmet.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bGetRes.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fNewHUDResX = *(const uint *)&source->m_fNewHUDResX; // +0x4f8, 4 bytes.
  *(uint *)&this->m_fNewHUDResY = *(const uint *)&source->m_fNewHUDResY; // +0x4fc, 4 bytes.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szStatusDetail,
                           (const FStringNoInit *)&source->m_szStatusDetail); // +0x500.
  return this;
}

// R6Abstract.dll @ 10001e70 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractHUD::VectorDeletingDestructor(AR6AbstractHUD *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x50c, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractHUD::~AR6AbstractHUD);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractHUD::~AR6AbstractHUD();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x50c);
  return this;
}

// R6Abstract.dll @ 10003150 : construct AR6AbstractHUD in supplied memory when it is nonnull
void __cdecl AR6AbstractHUD::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractHUD; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10004140 : destroy AHUD during HUD destructor unwind parentFrame exposes inherited EBP, not a native
// stack argument.
void UnwindHUDDestructionBase(const byte *parentFrame) {
  AR6AbstractHUD *object = *(AR6AbstractHUD *const *)(parentFrame - 0x10);
  AHUD::~AHUD(object); // Native tail jump.
}

// R6Abstract.dll @ 10004149 : destroy the status-detail string during HUD destructor unwind parentFrame exposes
// inherited EBP, not a native stack argument.
void UnwindHUDDestructionStatusDetail(const byte *parentFrame) {
  AR6AbstractHUD *object = *(AR6AbstractHUD *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_szStatusDetail); // Native tail jump.
}

// R6Abstract.dll @ 10004170 : destroy AHUD during either HUD constructor unwind parentFrame exposes inherited EBP, not
// a native stack argument.
void UnwindHUDConstructionBase(const byte *parentFrame) {
  AR6AbstractHUD *object = *(AR6AbstractHUD *const *)(parentFrame - 0x10);
  AHUD::~AHUD(object); // Native tail jump.
}

// R6Abstract.dll @ 10004990 : initialize AR6AbstractHUD class metadata and register its cleanup
void InitializeAR6AbstractHUDClassMetadata(void) {
  UClass *parentClass = (UClass *)AHUD_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractHUD::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractHUD::PrivateStaticClass) UClass(EC_NativeConstructor, 0x50c, 0x0, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractHUD", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractHUDClassMetadata);
}

// R6Abstract.dll @ 10004a20 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractHUDClassMetadata(void) {
  autoclassAR6AbstractHUD = &AR6AbstractHUD::PrivateStaticClass;
}

// R6Abstract.dll @ 10004ca0 : destroy AR6AbstractHUD class metadata
void DestroyAR6AbstractHUDClassMetadata(void) {
  AR6AbstractHUD::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004158 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractHUDDestructionFrame(void) {
  __asm {
    mov eax, offset hUDDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 10004179 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractHUDConstructionFrame(void) {
  __asm {
    mov eax, offset hUDConstructionMetadata
    jmp __CxxFrameHandler
  }
}
