// R6Abstract.dll data @ 10006e98 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gameInfoConstructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &gameInfoConstructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006e88 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gameInfoConstructionUnwindMap[2] = {
  {.previousState = -1, .cleanup = &UnwindGameInfoConstructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindGameInfoConstructionVoteInstigator},
};

// R6Abstract.dll data @ 10006e6c : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gameInfoDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000003,
  .unwindMap = &gameInfoDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006e54 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gameInfoDestructionUnwindMap[3] = {
  {.previousState = -1, .cleanup = &UnwindGameInfoDestructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindGameInfoDestructionVoteInstigator},
  {.previousState = 0x00000001, .cleanup = &UnwindGameInfoDestructionActionPlan},
};

// R6Abstract.dll data @ 1000fea8 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractGameInfo::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractGameInfoVTable {
  NativeActorVTable actor;
  NativeImageWord32 InitGameInfoGameService; // +0x184.
  NativeImageWord32 MasterServerManager; // +0x188.
  NativeImageWord32 AbortScoreSubmission; // +0x18c.
};

// R6Abstract.dll data @ 100054e8 : AR6AbstractGameInfo virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const AR6AbstractGameInfoVTable AR6AbstractGameInfo_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractGameInfo::VectorDeletingDestructor, // +0x00c; native 100016b0
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
  .InitGameInfoGameService = &ForwardEngineAGameInfoInitGameInfoGameService, // +0x184; native 100038e8
  .MasterServerManager = &ForwardEngineAGameInfoMasterServerManager, // +0x188; native 100038e2
  .AbortScoreSubmission = &ForwardEngineAGameInfoAbortScoreSubmission, // +0x18c; native 100038dc
};

// R6Abstract.dll data @ 1000d620 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractGameInfo = nullptr;

// R6Abstract.dll @ 100012c0 : return the AR6AbstractGameInfo class object
UClass *__cdecl AR6AbstractGameInfo::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 100012d0 : allocate AR6AbstractGameInfo using its class object and supplied object parameters
void *__cdecl AR6AbstractGameInfo::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10001300 : destroy the object, its string members, and its base
void __thiscall AR6AbstractGameInfo::~AR6AbstractGameInfo(AR6AbstractGameInfo *this) {
  int destructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractGameInfoDestructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractGameInfoVTable **>(this) = &AR6AbstractGameInfo_vftable;
  destructionState = 2;
  UObject::ConditionalDestroy(this);
  destructionState = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szDefaultActionPlan); // +0x518.
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_VoteInstigatorName); // +0x50c.
  destructionState = -1;
  AGameInfo::~AGameInfo(this);
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10001380 : construct the base and leave both string subobjects uninitialized
AR6AbstractGameInfo *__thiscall AR6AbstractGameInfo::AR6AbstractGameInfo(AR6AbstractGameInfo *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int constructionState;

  constructionState = -1;
  exceptionHandler = &HandleAR6AbstractGameInfoConstructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AGameInfo::AGameInfo(this);
  constructionState = 0;
  *reinterpret_cast<const AR6AbstractGameInfoVTable **>(this) = &AR6AbstractGameInfo_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_VoteInstigatorName); // +0x50c; no writes.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szDefaultActionPlan); // +0x518; no writes.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 100013e0 : copy-construct the base and reflected members
AR6AbstractGameInfo *__thiscall AR6AbstractGameInfo::AR6AbstractGameInfo(AR6AbstractGameInfo *this,
                                                                         const AR6AbstractGameInfo *source) {
  int constructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractGameInfoConstructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((int)this + 0x4e4);
  const uint *sourceFlags = (const uint *)((int)source + 0x4e4);
  uint copiedFlags;

  AGameInfo::AGameInfo(this, source);
  *reinterpret_cast<const AR6AbstractGameInfoVTable **>(this) = &AR6AbstractGameInfo_vftable;
  this->m_iNbOfRainbowAIToSpawn = source->m_iNbOfRainbowAIToSpawn; // +0x4d4, 4 bytes.
  this->m_iNbOfTerroristToSpawn = source->m_iNbOfTerroristToSpawn; // +0x4d8, 4 bytes.
  this->m_iDiffLevel = source->m_iDiffLevel;                       // +0x4dc, 4 bytes.
  this->m_fTimerStartTime = source->m_fTimerStartTime;             // +0x4e0, 4 bytes.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bFriendlyFire.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bEndGameIgnoreGamePlayCheck.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bGameOverButAllowDeath.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bTimerStarted.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bInternetSvr.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fEndingTime = *(const uint *)&source->m_fEndingTime;       // +0x4e8, 4 bytes.
  *(uint *)&this->m_fTimeBetRounds = *(const uint *)&source->m_fTimeBetRounds; // +0x4ec, 4 bytes.
  *(uint *)&this->m_fEndVoteTime = *(const uint *)&source->m_fEndVoteTime;     // +0x4f0, 4 bytes.
  this->m_Player = source->m_Player;                                           // +0x4f4, 4 bytes.
  this->m_noiseMgr = source->m_noiseMgr;                                       // +0x4f8, 4 bytes.
  this->m_missionMgr = source->m_missionMgr;                                   // +0x4fc, 4 bytes.
  this->m_PlayerKick = source->m_PlayerKick;                                   // +0x500, 4 bytes.
  this->m_pCurPlayerCtrlMdfSrvInfo = source->m_pCurPlayerCtrlMdfSrvInfo;       // +0x504, 4 bytes.
  constructionState = 0;
  this->m_UdpBeacon = source->m_UdpBeacon; // +0x508, 4 bytes.
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_VoteInstigatorName,
                               (const FStringNoInit *)&source->m_VoteInstigatorName); // +0x50c.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szDefaultActionPlan,
                               (const FStringNoInit *)&source->m_szDefaultActionPlan); // +0x518.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10001560 : assign the base and reflected members
AR6AbstractGameInfo *__thiscall AR6AbstractGameInfo::operator=(AR6AbstractGameInfo *this,
                                                               const AR6AbstractGameInfo * source) {
  uint *destinationFlags = (uint *)((int)this + 0x4e4);
  const uint *sourceFlags = (const uint *)((int)source + 0x4e4);
  uint copiedFlags;

  AGameInfo::operator=(this, source);
  this->m_iNbOfRainbowAIToSpawn = source->m_iNbOfRainbowAIToSpawn; // +0x4d4, 4 bytes.
  this->m_iNbOfTerroristToSpawn = source->m_iNbOfTerroristToSpawn; // +0x4d8, 4 bytes.
  this->m_iDiffLevel = source->m_iDiffLevel;                       // +0x4dc, 4 bytes.
  this->m_fTimerStartTime = source->m_fTimerStartTime;             // +0x4e0, 4 bytes.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bFriendlyFire.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bEndGameIgnoreGamePlayCheck.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bGameOverButAllowDeath.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bTimerStarted.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bInternetSvr.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fEndingTime = *(const uint *)&source->m_fEndingTime;       // +0x4e8, 4 bytes.
  *(uint *)&this->m_fTimeBetRounds = *(const uint *)&source->m_fTimeBetRounds; // +0x4ec, 4 bytes.
  *(uint *)&this->m_fEndVoteTime = *(const uint *)&source->m_fEndVoteTime;     // +0x4f0, 4 bytes.
  this->m_Player = source->m_Player;                                           // +0x4f4, 4 bytes.
  this->m_noiseMgr = source->m_noiseMgr;                                       // +0x4f8, 4 bytes.
  this->m_missionMgr = source->m_missionMgr;                                   // +0x4fc, 4 bytes.
  this->m_PlayerKick = source->m_PlayerKick;                                   // +0x500, 4 bytes.
  this->m_pCurPlayerCtrlMdfSrvInfo = source->m_pCurPlayerCtrlMdfSrvInfo;       // +0x504, 4 bytes.
  this->m_UdpBeacon = source->m_UdpBeacon;                                     // +0x508, 4 bytes.
  FStringNoInit::operator=((FStringNoInit *)&this->m_VoteInstigatorName,
                           (const FStringNoInit *)&source->m_VoteInstigatorName); // +0x50c.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szDefaultActionPlan,
                           (const FStringNoInit *)&source->m_szDefaultActionPlan); // +0x518.
  return this;
}

// R6Abstract.dll @ 100016b0 : destroy one GameInfo or an array, optionally releasing its allocation Compiler-generated
// vector deleting destructor; vtable +0x0c. The source name is descriptive.
void *__thiscall AR6AbstractGameInfo::VectorDeletingDestructor(AR6AbstractGameInfo *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x524, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractGameInfo::~AR6AbstractGameInfo);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      // GMalloc vtable +0x08 receives the allocation including its four-byte array cookie.
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractGameInfo::~AR6AbstractGameInfo();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x524);
  return this;
}

// R6Abstract.dll @ 10003110 : construct AR6AbstractGameInfo in supplied memory when it is nonnull
void __cdecl AR6AbstractGameInfo::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractGameInfo; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10004070 : destroy the base during GameInfo destructor unwind
// parentFrame exposes inherited EBP, not a native stack argument.
void UnwindGameInfoDestructionBase(const byte *parentFrame) {
  AR6AbstractGameInfo *object = *(AR6AbstractGameInfo *const *)(parentFrame - 0x10);
  AGameInfo::~AGameInfo(object); // Native tail jump.
}

// R6Abstract.dll @ 10004079 : destroy the vote-instigator string during GameInfo destructor unwind
void UnwindGameInfoDestructionVoteInstigator(const byte *parentFrame) {
  AR6AbstractGameInfo *object = *(AR6AbstractGameInfo *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_VoteInstigatorName); // +0x50c; native tail jump.
}

// R6Abstract.dll @ 10004088 : destroy the action-plan string during GameInfo destructor unwind
void UnwindGameInfoDestructionActionPlan(const byte *parentFrame) {
  AR6AbstractGameInfo *object = *(AR6AbstractGameInfo *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_szDefaultActionPlan); // +0x518; native tail jump.
}

// R6Abstract.dll @ 100040b0 : destroy the base during either GameInfo constructor unwind
void UnwindGameInfoConstructionBase(const byte *parentFrame) {
  AR6AbstractGameInfo *object = *(AR6AbstractGameInfo *const *)(parentFrame - 0x10);
  AGameInfo::~AGameInfo(object); // Native tail jump.
}

// R6Abstract.dll @ 100040b9 : destroy the first string during either GameInfo constructor unwind
void UnwindGameInfoConstructionVoteInstigator(const byte *parentFrame) {
  AR6AbstractGameInfo *object = *(AR6AbstractGameInfo *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_VoteInstigatorName); // +0x50c; native tail jump.
}

// R6Abstract.dll @ 10004540 : initialize AR6AbstractGameInfo class metadata and register its cleanup
void InitializeAR6AbstractGameInfoClassMetadata(void) {
  UClass *parentClass = (UClass *)AGameInfo_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractGameInfo::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractGameInfo::PrivateStaticClass) UClass(EC_NativeConstructor, 0x524, 0x4, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractGameInfo", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractGameInfoClassMetadata);
}

// R6Abstract.dll @ 100045d0 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractGameInfoClassMetadata(void) {
  autoclassAR6AbstractGameInfo = &AR6AbstractGameInfo::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c30 : destroy AR6AbstractGameInfo class metadata
void DestroyAR6AbstractGameInfoClassMetadata(void) {
  AR6AbstractGameInfo::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004097 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractGameInfoDestructionFrame(void) {
  __asm {
    mov eax, offset gameInfoDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 100040c8 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractGameInfoConstructionFrame(void) {
  __asm {
    mov eax, offset gameInfoConstructionMetadata
    jmp __CxxFrameHandler
  }
}
