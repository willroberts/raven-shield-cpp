// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006080 : Core.dll ?GRegisterNative@@YAEHABQ8UObject@@AEXAAUFFrame@@QAX@Z@Z
extern uint registerNativeImport;

// R6Weapons.dll data @ 100062b8 : UTF-16 native text
const char16_t bulletTraceContext[] = u"AR6Bullet::ShouldTrace";

// R6Weapons.dll data @ 10007108 : UTF-16 native text
const char16_t bulletSurfaceContext[] = u"AR6Bullet::execBulletGoesThroughSurface";

// R6Weapons.dll data @ 1000716c : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6BulletClassNameStorage[] = u"AR6Bullet";

// R6Weapons.dll data @ 100062e8 : unit bias in the bullet range-loss polynomial
const float bulletRangeLossBias = 1.0f;

// R6Weapons.dll data @ 10007158 : default exit-surface search scale
const float bulletExitSearchScaleLimit = 20.0f;

// R6Weapons.dll data @ 1000715c : remaining-energy ceiling before penetration division
const float bulletRemainingEnergyLimit = 5000.0f;

// R6Weapons.dll data @ 10007160 : threshold applied after scaling the surface cosine result
const float bulletSurfaceCosineLimit = 38.0f;

// R6Weapons.dll data @ 10007164 : scale applied to the native appCos result
const float bulletSurfaceCosineScale = 57.295780181884766f;

// R6Weapons.dll data @ 10007168 : spawn-distance conversion before the float32 spill
const float bulletDistanceScale = 0.01f;

// R6Weapons.dll data @ 10007844 : bulletTrace unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry bulletTraceUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007854 : bulletTrace typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry bulletTraceCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowBulletTraceMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportBulletTraceException,
    },
};

// R6Weapons.dll data @ 10007874 : bulletTrace protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry bulletTraceTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &bulletTraceCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007888 : bulletTrace exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix bulletTraceFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &bulletTraceUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &bulletTraceTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007a28 : bulletDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry bulletDestructorUnwindMap[4] = {
    {.previousState = -1, .cleanup = &UnwindBulletDestructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindBulletDestructorAmmoName},
    {.previousState = 0x00000001, .cleanup = &UnwindBulletDestructorAmmoType},
    {.previousState = 0x00000002, .cleanup = &UnwindBulletDestructorBulletType},
};

// R6Weapons.dll data @ 10007a48 : bulletDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix bulletDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000004,
    .unwindMap = &bulletDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007a98 : bulletConstructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry bulletConstructorUnwindMap[3] = {
    {.previousState = -1, .cleanup = &UnwindBulletConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindBulletConstructorAmmoName},
    {.previousState = 0x00000001, .cleanup = &UnwindBulletConstructorAmmoType},
};

// R6Weapons.dll data @ 10007ab0 : bulletConstructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix bulletConstructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000003,
    .unwindMap = &bulletConstructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007b88 : bulletSurface unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry bulletSurfaceUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007b98 : bulletSurface typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry bulletSurfaceCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -168,
        .handler = &RethrowBulletSurfaceMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportBulletSurfaceException,
    },
};

// R6Weapons.dll data @ 10007bb8 : bulletSurface protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry bulletSurfaceTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &bulletSurfaceCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007bcc : bulletSurface exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix bulletSurfaceFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &bulletSurfaceUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &bulletSurfaceTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006ae8 : exported AR6Bullet virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeActorVTable AR6Bullet_vftable = {
    .QueryInterface = &ForwardUObjectQueryInterface,
    .AddRef = &ForwardUObjectAddRef,
    .Release = &ForwardUObjectRelease,
    .VectorDeletingDestructor = &AR6Bullet::VectorDeletingDestructor,
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
    .PostNetReceive = &ForwardAActorPostNetReceive,
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

// R6Weapons.dll data @ 1000c0f0 : exported AR6Bullet::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6BulletClassMetadataStorage[0x508] = {};
UClass &AR6Bullet::PrivateStaticClass = *(UClass *)AR6BulletClassMetadataStorage;

// R6Weapons.dll @ 10001000 : filter blocking actors by level, grenade mode and actor flags before base dispatch
// Keeps the level-info exception, conditional first bBlockActors read and later independent actor-flags read.
int __thiscall AR6Bullet::IsBlockedBy(const AR6Bullet *this, const AActor *otherActor) {
  const byte *actorBytes = (const byte *)otherActor;
  ALevelInfo *levelInfo = ULevel::GetLevelInfo(this->XLevel); // +0x328.
  const bool isLevelInfo = otherActor == (const AActor *)levelInfo;
  if (!isLevelInfo && (*(const uint *)(actorBytes + 0xa8) & 0x2000) == 0)
    return 0;                                                                    // bBlockActors.
  const bool isGrenade = (*(const byte *)((const byte *)this + 0x3a4) & 2) != 0; // m_bIsGrenade.
  const uint actorFlags = *(const uint *)(actorBytes + 0xa8);
  if (isGrenade) {
    if ((actorFlags & 0x2000) != 0)
      return 1; // bBlockActors.
  } else if ((actorFlags & 0x40000) != 0)
    return 0; // m_bBulletGoThrough.
  return AActor::IsBlockedBy((const AActor *)this, otherActor);
}

// R6Weapons.dll @ 10001060 : exclude the instigator from non-grenade traces, otherwise forward to the actor filter
// Reads m_bIsGrenade before state 0; the conditional Instigator read and base call remain inside the guard.
int __thiscall AR6Bullet::ShouldTrace(AR6Bullet *this, AActor *otherActor, ulong traceFlags) {
  void *previousExceptionList = ExceptionList;
  byte *exceptionHandler = (byte *)&DispatchBulletTraceException;
  int exceptionState = -1;
  ExceptionList = &previousExceptionList;
  const bool isGrenade = (*(const byte *)((const byte *)this + 0x3a4) & 2) != 0;
  exceptionState = 0;
  if (!isGrenade && otherActor == (AActor *)this->Instigator) { // +0x148.
    ExceptionList = previousExceptionList;
    return 0;
  }
  const int result = AActor::ShouldTrace((AActor *)this, otherActor, traceFlags);
  ExceptionList = previousExceptionList;
  return result;
}

// R6Weapons.dll @ 100010d2 : throw the unsigned-short message pointer caught by the BulletTrace guard
// Copies the parent catch slot to its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowBulletTraceMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 100010e6 : report the BulletTrace guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportBulletTraceException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)bulletTraceContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005430 : dispatch the BulletTrace guard using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchBulletTraceException(void) {
  __asm {
    mov eax, offset bulletTraceFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10001110 : multiply range by its coefficient, add one, then multiply by range again
// Retains the native operand-read order and extended intermediates without a float32 spill.
float __thiscall AR6Bullet::RangeConversion(AR6Bullet *this, float fRange) {
  const float10 range = (float10)fRange;
  const float10 scaledRange = range * (float10)this->m_fRangeConversionConst; // +0x3ac.
  const float10 adjustedRange = scaledRange + (float10)bulletRangeLossBias;   // Native constant 1.0f.
  const float10 result = adjustedRange * (float10)fRange;
  return result;
}

// R6Weapons.dll @ 10001130 : multiply range by its coefficient, then by range again
// Reads m_fRangeConversionConst between the range operands; no intermediate float32 spill occurs.
float __thiscall AR6Bullet::StunLoss(AR6Bullet *this, float fRange) {
  const float10 range = (float10)fRange;
  const float10 scaledRange = range * (float10)this->m_fRangeConversionConst; // +0x3ac.
  const float10 result = scaledRange * (float10)fRange;
  return result;
}

// R6Weapons.dll @ 10002440 : return the AR6Bullet class object
// Returns the class metadata object at native address 0x1000c0f0.
UClass *__cdecl AR6Bullet::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10002450 : allocate AR6Bullet using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6Bullet::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10002480 : destroy the bullet, its three strings, and its abstract base
// Runs conditional shutdown before destroying strings in reverse construction order and then the base.
void __thiscall AR6Bullet::~AR6Bullet(AR6Bullet *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchBulletDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeActorVTable **)this = &AR6Bullet_vftable;
  destructionState = 3;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = 2;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szBulletType); // +0x3ec.
  destructionState = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szAmmoType); // +0x3e0.
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szAmmoName); // +0x3d4.
  destructionState = -1;
  AR6AbstractBullet::~AR6AbstractBullet((AR6AbstractBullet *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10002510 : construct the abstract bullet base and three no-init strings
// Constructs strings in declaration order; the selected no-init constructor leaves their storage unchanged.
AR6Bullet *__thiscall AR6Bullet::AR6Bullet(AR6Bullet *this) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchBulletConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AR6AbstractBullet::AR6AbstractBullet((AR6AbstractBullet *)this);
  constructionState = 0;
  *(const NativeActorVTable **)this = &AR6Bullet_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szAmmoName); // +0x3d4.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szAmmoType); // +0x3e0.
  constructionState = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szBulletType); // +0x3ec.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10002590 : copy-construct the base and reflected members
// Copies raw scalar/vector words, merges four flag bits from native snapshots and constructs the three strings.
AR6Bullet *__thiscall AR6Bullet::AR6Bullet(AR6Bullet *this, const AR6Bullet *source) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchBulletConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((byte *)this + 0x3a4);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x3a4);

  AR6AbstractBullet::AR6AbstractBullet((AR6AbstractBullet *)this, (const AR6AbstractBullet *)source);
  *(const NativeActorVTable **)this = &AR6Bullet_vftable;
  this->m_iEnergy = source->m_iEnergy;                       // +0x394.
  this->m_iPenetrationFactor = source->m_iPenetrationFactor; // +0x398.
  const int noArmorModifier = source->m_iNoArmorModifier;    // +0x39c.
  const uint earlyDestinationFlags = *destinationFlags;
  this->m_iNoArmorModifier = noArmorModifier;
  this->m_iBulletGroupID = source->m_iBulletGroupID; // +0x3a0.
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags; // Reload follows the two scalar stores and source-flags read.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bBulletIsGone.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bIsGrenade.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bBulletDeactivated.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // bShowLog.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fKillStunTransfer = *(const uint *)&source->m_fKillStunTransfer;         // +0x3a8.
  *(uint *)&this->m_fRangeConversionConst = *(const uint *)&source->m_fRangeConversionConst; // +0x3ac.
  *(uint *)&this->m_fRange = *(const uint *)&source->m_fRange;                               // +0x3b0.
  *(uint *)&this->m_fExplosionRadius = *(const uint *)&source->m_fExplosionRadius;           // +0x3b4.
  *(uint *)&this->m_fKillBlastRadius = *(const uint *)&source->m_fKillBlastRadius;           // +0x3b8.
  *(uint *)&this->m_fExplosionDelay = *(const uint *)&source->m_fExplosionDelay;             // +0x3bc.
  this->m_AffectedActor = source->m_AffectedActor;                                           // +0x3c0.
  this->m_BulletManager = source->m_BulletManager;                                           // +0x3c4.
  *(uint *)&this->m_vSpawnedPosition.X = *(const uint *)&source->m_vSpawnedPosition.X;       // +0x3c8.
  *(uint *)&this->m_vSpawnedPosition.Y = *(const uint *)&source->m_vSpawnedPosition.Y;       // +0x3cc.
  *(uint *)&this->m_vSpawnedPosition.Z = *(const uint *)&source->m_vSpawnedPosition.Z;       // +0x3d0.
  constructionState = 0;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szAmmoName,
                               (const FStringNoInit *)&source->m_szAmmoName); // +0x3d4.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szAmmoType,
                               (const FStringNoInit *)&source->m_szAmmoType); // +0x3e0.
  constructionState = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szBulletType,
                               (const FStringNoInit *)&source->m_szBulletType); // +0x3ec.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10002730 : assign the base and reflected members
// Assigns raw scalar/vector words and three strings while retaining unselected destination flag bits.
AR6Bullet *__thiscall AR6Bullet::operator=(AR6Bullet *this, const AR6Bullet * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x3a4);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x3a4);

  AR6AbstractBullet::operator=((AR6AbstractBullet *)this, (const AR6AbstractBullet *)source);
  this->m_iEnergy = source->m_iEnergy;                       // +0x394.
  this->m_iPenetrationFactor = source->m_iPenetrationFactor; // +0x398.
  const int noArmorModifier = source->m_iNoArmorModifier;    // +0x39c.
  const uint earlyDestinationFlags = *destinationFlags;
  this->m_iNoArmorModifier = noArmorModifier;
  this->m_iBulletGroupID = source->m_iBulletGroupID; // +0x3a0.
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags; // Reload follows the two scalar stores and source-flags read.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bBulletIsGone.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bIsGrenade.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bBulletDeactivated.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // bShowLog.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fKillStunTransfer = *(const uint *)&source->m_fKillStunTransfer;         // +0x3a8.
  *(uint *)&this->m_fRangeConversionConst = *(const uint *)&source->m_fRangeConversionConst; // +0x3ac.
  *(uint *)&this->m_fRange = *(const uint *)&source->m_fRange;                               // +0x3b0.
  *(uint *)&this->m_fExplosionRadius = *(const uint *)&source->m_fExplosionRadius;           // +0x3b4.
  *(uint *)&this->m_fKillBlastRadius = *(const uint *)&source->m_fKillBlastRadius;           // +0x3b8.
  *(uint *)&this->m_fExplosionDelay = *(const uint *)&source->m_fExplosionDelay;             // +0x3bc.
  this->m_AffectedActor = source->m_AffectedActor;                                           // +0x3c0.
  this->m_BulletManager = source->m_BulletManager;                                           // +0x3c4.
  *(uint *)&this->m_vSpawnedPosition.X = *(const uint *)&source->m_vSpawnedPosition.X;       // +0x3c8.
  *(uint *)&this->m_vSpawnedPosition.Y = *(const uint *)&source->m_vSpawnedPosition.Y;       // +0x3cc.
  *(uint *)&this->m_vSpawnedPosition.Z = *(const uint *)&source->m_vSpawnedPosition.Z;       // +0x3d0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szAmmoName,
                           (const FStringNoInit *)&source->m_szAmmoName); // +0x3d4.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szAmmoType,
                           (const FStringNoInit *)&source->m_szAmmoType); // +0x3e0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szBulletType,
                           (const FStringNoInit *)&source->m_szBulletType); // +0x3ec.
  return this;
}

// R6Weapons.dll @ 10003340 : evaluate surface penetration and write entry/exit outputs and energy
// Retains DWORD result codes, live out-reference aliases and two independent level traces.
void __thiscall AR6Bullet::execBulletGoesThroughSurface(AR6Bullet *this, FFrame *stack, void *result) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  using DirtyNotifier = void(__thiscall *)(UObject *, UProperty *);
  byte **codeCursor = (byte **)((byte *)stack + 0x0c);
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchBulletSurfaceException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AActor *TouchedSurface = nullptr;
  byte opcode1 = *(*codeCursor)++;
  ScriptNative *firstNativeTable = (ScriptNative *)GNatives_exref;
  UObject *firstContext = *(UObject **)((byte *)stack + 8);
  guardState = 0;
  firstNativeTable[opcode1](firstContext, stack, &TouchedSurface);
  FVector vHitLocation;
  byte *argumentCursor2 = *codeCursor;
  byte opcode2 = *argumentCursor2;
  UObject *context2 = *(UObject **)((byte *)stack + 8);
  *codeCursor = argumentCursor2 + 1;
  ScriptNative *nativeTable2 = (ScriptNative *)GNatives_exref;
  nativeTable2[opcode2](context2, stack, &vHitLocation);
  FVector vBulletVelocityFallback;
  FVector *vBulletVelocity;
  void **propertyAddressSlot = (void **)GPropAddr_exref;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor3 = *codeCursor;
    byte opcode3 = *argumentCursor3;
    UObject *context3 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor3 + 1;
    ScriptNative *nativeTable3 = (ScriptNative *)GNatives_exref;
    nativeTable3[opcode3](context3, stack, &vBulletVelocityFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    vBulletVelocity = propertyAddress != nullptr ? (FVector *)propertyAddress : &vBulletVelocityFallback;
  }
  FVector vRealHitLocationFallback;
  FVector *vRealHitLocation;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor4 = *codeCursor;
    byte opcode4 = *argumentCursor4;
    UObject *context4 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor4 + 1;
    ScriptNative *nativeTable4 = (ScriptNative *)GNatives_exref;
    nativeTable4[opcode4](context4, stack, &vRealHitLocationFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    vRealHitLocation = propertyAddress != nullptr ? (FVector *)propertyAddress : &vRealHitLocationFallback;
  }
  FVector vexitLocationFallback;
  FVector *vexitLocation;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor5 = *codeCursor;
    byte opcode5 = *argumentCursor5;
    UObject *context5 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor5 + 1;
    ScriptNative *nativeTable5 = (ScriptNative *)GNatives_exref;
    nativeTable5[opcode5](context5, stack, &vexitLocationFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    vexitLocation = propertyAddress != nullptr ? (FVector *)propertyAddress : &vexitLocationFallback;
  }
  FVector vexitNormalFallback;
  FVector *vexitNormal;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor6 = *codeCursor;
    byte opcode6 = *argumentCursor6;
    UObject *context6 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor6 + 1;
    ScriptNative *nativeTable6 = (ScriptNative *)GNatives_exref;
    nativeTable6[opcode6](context6, stack, &vexitNormalFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    vexitNormal = propertyAddress != nullptr ? (FVector *)propertyAddress : &vexitNormalFallback;
  }
  UClass *TouchedEffectsFallback = nullptr;
  UClass **TouchedEffects;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor7 = *codeCursor;
    byte opcode7 = *argumentCursor7;
    UObject *context7 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor7 + 1;
    ScriptNative *nativeTable7 = (ScriptNative *)GNatives_exref;
    nativeTable7[opcode7](context7, stack, &TouchedEffectsFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    TouchedEffects = propertyAddress != nullptr ? (UClass **)propertyAddress : &TouchedEffectsFallback;
  }
  UClass *ExitEffectsFallback = nullptr;
  UClass **ExitEffects;
  {
    *propertyAddressSlot = nullptr;
    byte *argumentCursor8 = *codeCursor;
    byte opcode8 = *argumentCursor8;
    UObject *context8 = *(UObject **)((byte *)stack + 8);
    *codeCursor = argumentCursor8 + 1;
    ScriptNative *nativeTable8 = (ScriptNative *)GNatives_exref;
    nativeTable8[opcode8](context8, stack, &ExitEffectsFallback);
    UObject *propertyObject = *(UObject **)GPropObject_exref;
    if (propertyObject != nullptr) {
      UProperty *changedProperty = *(UProperty **)GProperty_exref;
      DirtyNotifier notifyDirty = *(DirtyNotifier *)(*(uint *)propertyObject + 0x60);
      notifyDirty(propertyObject, changedProperty);
    }
    propertyAddressSlot = (void **)GPropAddr_exref;
    void *propertyAddress = *propertyAddressSlot;
    ExitEffects = propertyAddress != nullptr ? (UClass **)propertyAddress : &ExitEffectsFallback;
  }
  byte *endCursor = *codeCursor + 1;
  *codeCursor = endCursor;
  if (*endCursor == 0x42) {
    UObject *trailingContext = *(UObject **)((byte *)stack + 8);
    *codeCursor = endCursor + 1;
    ScriptNative *trailingNativeTable = (ScriptNative *)GNatives_exref;
    trailingNativeTable[0x42](trailingContext, stack, nullptr);
  }

  uint *resultWord = (uint *)result;
  float10 firstEndZ = (float10)vHitLocation.Z;
  FCheckResult hit(1.0f); // Native 0x30-byte record: zero fields, Time=1, Item=-1.
  *resultWord = 1;        // Script return is ByteProperty; native stores a full DWORD.
  const FVector *firstZeroVector = (const FVector *)FVector0_exref;
  firstEndZ += (float10)vBulletVelocity->Z;
  const float10 firstEndY = (float10)vHitLocation.Y + (float10)vBulletVelocity->Y;
  ULevel *level = this->XLevel;
  const float10 firstEndX = (float10)vHitLocation.X + (float10)vBulletVelocity->X;
  FVector firstEnd;
  firstEnd.X = (float)firstEndX;
  firstEnd.Y = (float)firstEndY;
  firstEnd.Z = (float)firstEndZ;
  using LineTrace =
      int(__thiscall *)(ULevel *, FCheckResult *, AActor *, const FVector *, const FVector *, uint, FVector);
  const uint firstExtentX = *(const uint *)&firstZeroVector->X;
  LineTrace firstTrace = *(LineTrace *)(*(uint *)level + 0xcc);
  const uint firstExtentY = *(const uint *)&firstZeroVector->Y;
  const uint firstExtentZ = *(const uint *)&firstZeroVector->Z;
  FVector firstExtent;
  *(uint *)&firstExtent.X = firstExtentX;
  *(uint *)&firstExtent.Y = firstExtentY;
  *(uint *)&firstExtent.Z = firstExtentZ;
  firstTrace(level, &hit, (AActor *)this, &firstEnd, &vHitLocation, 0x151086, firstExtent);
  do {
    if (hit.Actor != TouchedSurface || hit.Material == nullptr) {
      *resultWord = 0;
      break;
    }
    FVector displacement;
    const float10 displacementZ = (float10)vHitLocation.Z - (float10)this->m_vSpawnedPosition.Z;
    const float10 displacementY = (float10)vHitLocation.Y - (float10)this->m_vSpawnedPosition.Y;
    const float10 displacementX = (float10)vHitLocation.X - (float10)this->m_vSpawnedPosition.X;
    displacement.X = (float)displacementX;
    displacement.Y = (float)displacementY;
    displacement.Z = (float)displacementZ;
    float10 distance = (float10)FVector::Size(&displacement);
    float scaledDistance = (float)distance; // Nonpopping FST; arithmetic keeps the extended Size result.
    const float10 scaledDistanceWide = distance * (float10)bulletDistanceScale;
    *(uint *)&vRealHitLocation->X = *(const uint *)&hit.Location.X;
    scaledDistance = (float)scaledDistanceWide;
    *(uint *)&vRealHitLocation->Y = *(const uint *)&hit.Location.Y;
    *(uint *)&vRealHitLocation->Z = *(const uint *)&hit.Location.Z;
    *TouchedEffects = hit.Material->m_pHitEffect;

    FVector direction;
    const uint directionX = *(const uint *)&vBulletVelocity->X;
    const uint directionY = *(const uint *)&vBulletVelocity->Y;
    const uint directionZ = *(const uint *)&vBulletVelocity->Z;
    *(uint *)&direction.X = directionX;
    *(uint *)&direction.Y = directionY;
    *(uint *)&direction.Z = directionZ;
    FVector::Normalize(&direction);
    float10 dot = (float10)hit.Normal.Z * (float10)direction.Z;
    dot += (float10)hit.Normal.Y * (float10)direction.Y;
    dot += (float10)hit.Normal.X * (float10)direction.X;
    float10 cosine = (float10)appCos((double)dot); // Import is appCos; selected Core executes FCOS.
    double cosineScratch = (double)cosine;         // Nonpopping FST; the following multiply retains ST(0).
    if (cosine * (float10)bulletSurfaceCosineScale > (float10)bulletSurfaceCosineLimit)
      *resultWord = 2;

    int entryPenetration = hit.Material->m_iPenetration;
    if (entryPenetration == 0)
      break;
    const float10 initialEnergy = (float10)this->m_iEnergy; // FILD precedes range/coefficient loads.
    float10 rangeLoss = (float10)scaledDistance * (float10)this->m_fRangeConversionConst;
    rangeLoss += (float10)bulletRangeLossBias;
    rangeLoss *= (float10)scaledDistance;
    float10 remainingEnergy = initialEnergy - rangeLoss;
    if (remainingEnergy > (float10)bulletRemainingEnergyLimit)
      remainingEnergy = (float10)bulletRemainingEnergyLimit;
    float penetrationBudget = (float)(remainingEnergy / (float10)this->m_iPenetrationFactor);
    float entryPenetrationFloat = (float)entryPenetration;
    if (!(penetrationBudget > entryPenetrationFloat))
      break;
    int resistanceFactor = hit.Material->m_iResistanceFactor;
    float10 searchScale = (float10)bulletExitSearchScaleLimit;
    if (resistanceFactor > 99)
      searchScale = ((float10)penetrationBudget - (float10)entryPenetrationFloat) / (float10)resistanceFactor;
    const float10 exitDirectionZ = (float10)direction.Z;
    hit.Material = nullptr;
    const float10 scaledDirectionZ = exitDirectionZ * searchScale;
    ULevel *exitLevel = this->XLevel;
    const FVector *exitZeroVector = (const FVector *)FVector0_exref;
    FVector scaledDirection;
    scaledDirection.Z = (float)scaledDirectionZ;
    scaledDirection.Y = (float)((float10)direction.Y * searchScale);
    scaledDirection.X = (float)((float10)direction.X * searchScale);
    FVector exitStart;
    const float10 exitStartZ = (float10)scaledDirection.Z + (float10)vRealHitLocation->Z;
    const float10 exitStartY = (float10)scaledDirection.Y + (float10)vRealHitLocation->Y;
    const float10 exitStartX = (float10)scaledDirection.X + (float10)vRealHitLocation->X;
    exitStart.X = (float)exitStartX;
    exitStart.Y = (float)exitStartY;
    exitStart.Z = (float)exitStartZ;
    FVector exitEnd;
    const float10 exitEndZ = (float10)direction.Z + (float10)vRealHitLocation->Z;
    const float10 exitEndY = (float10)direction.Y + (float10)vRealHitLocation->Y;
    const float10 exitEndX = (float10)direction.X + (float10)vRealHitLocation->X;
    exitEnd.X = (float)exitEndX;
    exitEnd.Y = (float)exitEndY;
    exitEnd.Z = (float)exitEndZ;
    const uint exitExtentX = *(const uint *)&exitZeroVector->X;
    LineTrace exitTrace = *(LineTrace *)(*(uint *)exitLevel + 0xcc);
    const uint exitExtentY = *(const uint *)&exitZeroVector->Y;
    const uint exitExtentZ = *(const uint *)&exitZeroVector->Z;
    FVector exitExtent;
    *(uint *)&exitExtent.X = exitExtentX;
    *(uint *)&exitExtent.Y = exitExtentY;
    *(uint *)&exitExtent.Z = exitExtentZ;
    int exitTraceResult = exitTrace(exitLevel, &hit, (AActor *)this, &exitEnd, &exitStart, 0x101086, exitExtent);
    if (exitTraceResult != 0 || hit.Material == nullptr)
      break;
    const int candidateExitPenetration = hit.Material->m_iPenetration;
    if (candidateExitPenetration == 0 || candidateExitPenetration >= this->m_iEnergy)
      break;
    *ExitEffects = hit.Material->m_pHitEffect;
    *(uint *)&vexitLocation->X = *(const uint *)&hit.Location.X;
    *(uint *)&vexitLocation->Y = *(const uint *)&hit.Location.Y;
    *(uint *)&vexitLocation->Z = *(const uint *)&hit.Location.Z;
    *(uint *)&vexitNormal->X = *(const uint *)&hit.Normal.X;
    *(uint *)&vexitNormal->Y = *(const uint *)&hit.Normal.Y;
    *(uint *)&vexitNormal->Z = *(const uint *)&hit.Normal.Z;
    int exitPenetration = hit.Material->m_iPenetration;
    int energyCost = entryPenetration < exitPenetration ? exitPenetration : entryPenetration;
    int newEnergy = (int)((uint)this->m_iEnergy - (uint)energyCost);
    if (newEnergy > 5000)
      newEnergy = 5000;
    this->m_iEnergy = newEnergy;
    *resultWord = 3;
  } while (false);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003912 : throw the unsigned-short message pointer caught by the BulletSurface guard
// Copies the parent catch slot to its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowBulletSurfaceMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0xa8);
  *(ushort **)(parentFrameEBP - 0x8c) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x8c,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 1000392f : report the BulletSurface guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportBulletSurfaceException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)bulletSurfaceContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005640 : dispatch the BulletSurface guard using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchBulletSurfaceException(void) {
  __asm {
    mov eax, offset bulletSurfaceFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 100039a0 : construct AR6Bullet in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6Bullet::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6Bullet::AR6Bullet((AR6Bullet *)objectMemory);
}

// R6Weapons.dll @ 10005550 : unwind the abstract bullet base during destructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletDestructorBase(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  AR6AbstractBullet::~AR6AbstractBullet((AR6AbstractBullet *)bullet);
}

// R6Weapons.dll @ 10005559 : unwind the bullet m_szAmmoName string during destructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletDestructorAmmoName(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&bullet->m_szAmmoName);
}

// R6Weapons.dll @ 10005568 : unwind the bullet m_szAmmoType string during destructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletDestructorAmmoType(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&bullet->m_szAmmoType);
}

// R6Weapons.dll @ 10005577 : unwind the bullet m_szBulletType string during destructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletDestructorBulletType(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&bullet->m_szBulletType);
}

// R6Weapons.dll @ 10005590 : unwind the abstract bullet base during constructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletConstructorBase(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  AR6AbstractBullet::~AR6AbstractBullet((AR6AbstractBullet *)bullet);
}

// R6Weapons.dll @ 10005599 : unwind the bullet m_szAmmoName string during constructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletConstructorAmmoName(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&bullet->m_szAmmoName);
}

// R6Weapons.dll @ 100055a8 : unwind the bullet m_szAmmoType string during constructor
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindBulletConstructorAmmoType(byte *parentFrameEBP) {
  AR6Bullet *bullet = *(AR6Bullet **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&bullet->m_szAmmoType);
}

// R6Weapons.dll @ 10005586 : dispatch bullet destructor exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchBulletDestructorException(void) {
  __asm {
    mov eax, offset bulletDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 100055b7 : dispatch bullet constructor exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchBulletConstructorException(void) {
  __asm {
    mov eax, offset bulletConstructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005770 : initialize AR6Bullet class metadata and register its destruction
// Snapshots imported class/static-constructor pointers before config lookup; supplies a zero GUID and native flags.
void InitializeAR6BulletClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  UClass *parentClass = (UClass *)AR6AbstractBullet_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6Bullet::PrivateStaticClass, (ENativeConstructor)0, 0x3f8, 0, parentClass, withinClass, classGuid,
                 (const ushort *)(r6BulletClassNameStorage + 1), GPackage, configName, 0x4084004,
                 AR6Bullet::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6BulletClassMetadata);
}

// R6Weapons.dll @ 10005cd0 : destroy AR6Bullet class metadata
// Destroys the metadata object registered by the class initializer; native code tail-jumps to UClass's destructor.
void DestroyAR6BulletClassMetadata(void) {
  UClass::~UClass(&AR6Bullet::PrivateStaticClass);
}

// R6Weapons.dll @ 10002890 : destroy one AR6Bullet or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6Bullet::VectorDeletingDestructor(AR6Bullet *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6Bullet *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6Bullet::~AR6Bullet); // AR6Bullet destructor.
    destroyElements(this, 0x3f8, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6Bullet::~AR6Bullet(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x3f8); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000c0e4 : exported class pointer autoclassAR6Bullet
UClass *autoclassAR6Bullet = nullptr;

// R6Weapons.dll @ 10005800 : bind the exported AR6Bullet class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6BulletAutoClass(void) {
  autoclassAR6Bullet = &AR6Bullet::PrivateStaticClass;
}

// R6Weapons.dll data @ 1000c074 : exported single-word script member pointer intAR6BulletexecBulletGoesThroughSurface
NativeImageWord32 intAR6BulletexecBulletGoesThroughSurface = &AR6Bullet::execBulletGoesThroughSurface;
// R6Weapons.dll data @ 1000c0dc : low-byte result of script-native registration
byte bulletSurfaceRegistrationResult = 0;

// R6Weapons.dll @ 10005750 : register script native 0x7d1 using the exported member-pointer word
// The registrar receives the word's address (const reference); only its returned AL is stored.
void RegisterBulletSurfaceScriptNative(void) {
  using RegisterNativeWord = byte(__cdecl *)(int, const NativeImageWord32 *);
  RegisterNativeWord registerNative = reinterpret_cast<RegisterNativeWord>(registerNativeImport);
  bulletSurfaceRegistrationResult = registerNative(0x7d1, &intAR6BulletexecBulletGoesThroughSurface);
}
