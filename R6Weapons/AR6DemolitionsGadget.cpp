// R6Weapons.dll data @ 1000cb10 : previous normalized demolition-gadget m_bHide bit
uint previousHideFlag = 0;

// R6Weapons.dll data @ 1000cb14 : previous normalized demolition-gadget m_bDetonator bit
uint previousDetonatorFlag = 0;

// R6Weapons.dll data @ 100072b0 : UTF-16 native text
const char16_t demolitionsPreNetReceiveContext[] = u"AR6DemolitionsGadget::PreNetReceive";

// R6Weapons.dll data @ 10007568 : UTF-16 native text
const char16_t demolitionsPostNetReceiveContext[] = u"AR6DemolitionsGadget::PostNetReceive";

// R6Weapons.dll data @ 10007620 : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6DemolitionsGadgetClassNameStorage[] = u"AR6DemolitionsGadget";

// R6Weapons.dll data @ 10007954 : demolitionsDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry demolitionsDestructorUnwindMap[3] = {
    {.previousState = -1, .cleanup = &UnwindDemolitionsDestructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindDemolitionsDestructorBlockClass},
    {.previousState = 0x00000001, .cleanup = &UnwindDemolitionsDestructorDetonatorClass},
};

// R6Weapons.dll data @ 1000796c : demolitionsDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix demolitionsDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000003,
    .unwindMap = &demolitionsDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100079b4 : demolitionsConstructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry demolitionsConstructorUnwindMap[2] = {
    {.previousState = -1, .cleanup = &UnwindDemolitionsConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindDemolitionsConstructorBlockClass},
};

// R6Weapons.dll data @ 100079c4 : demolitionsConstructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix demolitionsConstructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &demolitionsConstructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007d68 : demolitionsPreReceive unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry demolitionsPreReceiveUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007d78 : demolitionsPreReceive typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry demolitionsPreReceiveCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowDemolitionsPreReceiveMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportDemolitionsPreReceiveException,
    },
};

// R6Weapons.dll data @ 10007d98 : demolitionsPreReceive protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry demolitionsPreReceiveTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &demolitionsPreReceiveCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007dac : demolitionsPreReceive exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix demolitionsPreReceiveFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &demolitionsPreReceiveUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &demolitionsPreReceiveTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100080c8 : demolitionsPostReceive unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry demolitionsPostReceiveUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 100080d8 : demolitionsPostReceive typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry demolitionsPostReceiveCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowDemolitionsPostReceiveMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportDemolitionsPostReceiveException,
    },
};

// R6Weapons.dll data @ 100080f8 : demolitionsPostReceive protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry demolitionsPostReceiveTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &demolitionsPostReceiveCatchHandlers,
    },
};

// R6Weapons.dll data @ 1000810c : demolitionsPostReceive exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix demolitionsPostReceiveFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &demolitionsPostReceiveUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &demolitionsPostReceiveTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006620 : exported AR6DemolitionsGadget virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeWeaponVTable AR6DemolitionsGadget_vftable = {
    .actor =
        {
            .QueryInterface = &ForwardUObjectQueryInterface,
            .AddRef = &ForwardUObjectAddRef,
            .Release = &ForwardUObjectRelease,
            .VectorDeletingDestructor = &AR6DemolitionsGadget::VectorDeletingDestructor,
            .ProcessEvent = &ForwardAActorProcessEvent,
            .ProcessDelegate = &ForwardUObjectProcessDelegate,
            .ProcessState = &AR6Weapons::ProcessState,
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
            .IsBlockedBy = &AR6Weapons::IsBlockedBy,
            .GetNetPriority = &ForwardAActorGetNetPriority,
            .WorldLightRadius = &ForwardAActorWorldLightRadius,
            .Tick = &ForwardAActorTick,
            .PostEditMove = &ForwardAActorPostEditMove,
            .PostEditLoad = &ForwardAActorPostEditLoad,
            .PreRaytrace = &ForwardAActorPreRaytrace,
            .PostRaytrace = &ForwardAActorPostRaytrace,
            .Spawned = &ForwardAActorSpawned,
            .PreNetReceive = &AR6DemolitionsGadget::PreNetReceive,
            .PostNetReceive = &AR6DemolitionsGadget::PostNetReceive,
            .PostNetReceiveLocation = &ForwardAActorPostNetReceiveLocation,
            .GetSkin = &ForwardAActorGetSkin,
            .ToLocal = &ForwardAActorToLocal,
            .ToWorld = &ForwardAActorToWorld,
            .LocalToWorld = &ForwardAActorLocalToWorld,
            .WorldToLocal = &ForwardAActorWorldToLocal,
            .UpdateColBox = &ForwardAActorUpdateColBox,
            .PostScriptDestroyed = &ForwardAActorPostScriptDestroyed,
            .ShouldTrace = &ForwardAActorShouldTrace,
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
            .TickAuthoritative = &AR6Weapons::TickAuthoritative,
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
        },
    .GetHeartBeatStatus = &AR6Weapons::GetHeartBeatStatus,
    .ShowWeaponParticles = &AR6Weapons::ShowWeaponParticles,
    .ComputeEffectiveAccuracy = &AR6Weapons::ComputeEffectiveAccuracy,
    .GetMovingModifier = &AR6Weapons::GetMovingModifier,
    .WeaponIsNotFiring = &AR6Weapons::WeaponIsNotFiring,
};

// R6Weapons.dll data @ 1000cb28 : exported AR6DemolitionsGadget::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6DemolitionsGadgetClassMetadataStorage[0x508] = {};
UClass &AR6DemolitionsGadget::PrivateStaticClass = *(UClass *)AR6DemolitionsGadgetClassMetadataStorage;

// R6Weapons.dll @ 10001b30 : dispatch the SetGadgetStaticMesh script event without parameters
// Snapshots the event name before the vtable, then resolves the function and calls the saved ProcessEvent slot.
void __thiscall AR6DemolitionsGadget::eventSetGadgetStaticMesh(AR6DemolitionsGadget *this) {
  FName eventName = R6WEAPONS_SetGadgetStaticMesh;
  const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
  UFunction *function = UObject::FindFunctionChecked((UObject *)this, eventName, 0);
  using EventDispatcher = void(__thiscall *)(AActor *, UFunction *, void *, void *);
  EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
  processEvent((AActor *)this, function, nullptr, nullptr);
}

// R6Weapons.dll @ 10001b60 : dispatch the NbBulletChange script event without parameters
// Snapshots the event name before the vtable, then resolves the function and calls the saved ProcessEvent slot.
void __thiscall AR6DemolitionsGadget::eventNbBulletChange(AR6DemolitionsGadget *this) {
  FName eventName = R6WEAPONS_NbBulletChange;
  const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
  UFunction *function = UObject::FindFunctionChecked((UObject *)this, eventName, 0);
  using EventDispatcher = void(__thiscall *)(AActor *, UFunction *, void *, void *);
  EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
  processEvent((AActor *)this, function, nullptr, nullptr);
}

// R6Weapons.dll @ 10001b90 : return the AR6DemolitionsGadget class object
// Returns the class metadata object at native address 0x1000cb28.
UClass *__cdecl AR6DemolitionsGadget::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10001ba0 : allocate AR6DemolitionsGadget using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6DemolitionsGadget::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                 ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10001bd0 : conditionally destroy the demolition gadget, its two strings and its gadget base
// Destroys the +0x670 and +0x664 strings in reverse order, then calls the gadget destructor.
// FuncInfo 0x1000796c maps states 2 -> 1 -> 0 -> -1 to those strings and the base.
void __thiscall AR6DemolitionsGadget::~AR6DemolitionsGadget(AR6DemolitionsGadget *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchDemolitionsDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeWeaponVTable **)this = &AR6DemolitionsGadget_vftable;
  destructionState = 2;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szDetonatorReticuleClass); // +0x670.
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szReticuleBlockClass); // +0x664.
  destructionState = -1;
  AR6Gadget::~AR6Gadget((AR6Gadget *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10001c50 : construct the weapon base and two no-init demolition-gadget strings
// Native construction calls AR6Weapons directly; its unwind path calls the AR6Gadget destructor.
AR6DemolitionsGadget *__thiscall AR6DemolitionsGadget::AR6DemolitionsGadget(AR6DemolitionsGadget *this) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchDemolitionsConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AR6Weapons::AR6Weapons((AR6Weapons *)this);
  constructionState = 0;
  *(const NativeWeaponVTable **)this = &AR6DemolitionsGadget_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szReticuleBlockClass); // +0x664; preserves storage.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szDetonatorReticuleClass); // +0x670; preserves storage.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10001cb0 : copy-construct the base and reflected members
// Retains the pre-vtable flag snapshot, copies raw vector/name words and constructs two strings.
AR6DemolitionsGadget *__thiscall AR6DemolitionsGadget::AR6DemolitionsGadget(AR6DemolitionsGadget *this,
                                                                            const AR6DemolitionsGadget *source) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchDemolitionsConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((byte *)this + 0x62c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x62c);

  AR6Weapons::AR6Weapons((AR6Weapons *)this, (const AR6Weapons *)source);
  const uint earlyDestinationFlags = *destinationFlags;
  *(const NativeWeaponVTable **)this = &AR6DemolitionsGadget_vftable;
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags;
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bDetonated.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bChargeInPosition.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bCanPlaceCharge.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bInstallingCharge.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bCancelChargeInstallation.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bRaiseWeapon.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bHide.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bDetonator.
  *destinationFlags = copiedFlags;
  this->m_ReticuleConfirm = source->m_ReticuleConfirm;                                     // +0x630.
  this->m_ReticuleBlock = source->m_ReticuleBlock;                                         // +0x634.
  this->m_ReticuleDetonator = source->m_ReticuleDetonator;                                 // +0x638.
  this->m_DetonatorStaticMesh = source->m_DetonatorStaticMesh;                             // +0x63c.
  this->m_DetonatorTexture = source->m_DetonatorTexture;                                   // +0x640.
  this->m_ChargeStaticMesh = source->m_ChargeStaticMesh;                                   // +0x644.
  this->BulletActor = source->BulletActor;                                                 // +0x648.
  *(uint *)&this->m_ChargeAttachPoint = *(const uint *)&source->m_ChargeAttachPoint;       // +0x64c.
  *(uint *)&this->m_DetonatorAttachPoint = *(const uint *)&source->m_DetonatorAttachPoint; // +0x650.
  this->m_pExplosionParticles = source->m_pExplosionParticles;                             // +0x654.
  *(uint *)&this->m_vLocation.X = *(const uint *)&source->m_vLocation.X;                   // +0x658.
  *(uint *)&this->m_vLocation.Y = *(const uint *)&source->m_vLocation.Y;                   // +0x65c.
  *(uint *)&this->m_vLocation.Z = *(const uint *)&source->m_vLocation.Z;                   // +0x660.
  constructionState = 0;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szReticuleBlockClass,
                               (const FStringNoInit *)&source->m_szReticuleBlockClass); // +0x664.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szDetonatorReticuleClass,
                               (const FStringNoInit *)&source->m_szDetonatorReticuleClass); // +0x670.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10001e60 : assign the base and reflected members
// Reads source flags before two destination snapshots, then assigns references, raw values and two strings.
AR6DemolitionsGadget *__thiscall AR6DemolitionsGadget::operator=(AR6DemolitionsGadget *this,
                                                                 const AR6DemolitionsGadget * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x62c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x62c);

  AR6Weapons::operator=((AR6Weapons *)this, (const AR6Weapons *)source);
  const uint firstSourceFlags = *sourceFlags;
  const uint earlyDestinationFlags = *destinationFlags;
  uint copiedFlags = *destinationFlags; // Native performs two reads before the first masked store.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bDetonated.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bChargeInPosition.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bCanPlaceCharge.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bInstallingCharge.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bCancelChargeInstallation.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bRaiseWeapon.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bHide.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bDetonator.
  *destinationFlags = copiedFlags;
  this->m_ReticuleConfirm = source->m_ReticuleConfirm;                                     // +0x630.
  this->m_ReticuleBlock = source->m_ReticuleBlock;                                         // +0x634.
  this->m_ReticuleDetonator = source->m_ReticuleDetonator;                                 // +0x638.
  this->m_DetonatorStaticMesh = source->m_DetonatorStaticMesh;                             // +0x63c.
  this->m_DetonatorTexture = source->m_DetonatorTexture;                                   // +0x640.
  this->m_ChargeStaticMesh = source->m_ChargeStaticMesh;                                   // +0x644.
  this->BulletActor = source->BulletActor;                                                 // +0x648.
  *(uint *)&this->m_ChargeAttachPoint = *(const uint *)&source->m_ChargeAttachPoint;       // +0x64c.
  *(uint *)&this->m_DetonatorAttachPoint = *(const uint *)&source->m_DetonatorAttachPoint; // +0x650.
  this->m_pExplosionParticles = source->m_pExplosionParticles;                             // +0x654.
  *(uint *)&this->m_vLocation.X = *(const uint *)&source->m_vLocation.X;                   // +0x658.
  *(uint *)&this->m_vLocation.Y = *(const uint *)&source->m_vLocation.Y;                   // +0x65c.
  *(uint *)&this->m_vLocation.Z = *(const uint *)&source->m_vLocation.Z;                   // +0x660.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szReticuleBlockClass,
                           (const FStringNoInit *)&source->m_szReticuleBlockClass); // +0x664.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szDetonatorReticuleClass,
                           (const FStringNoInit *)&source->m_szDetonatorReticuleClass); // +0x670.
  return this;
}

// R6Weapons.dll @ 10001fe0 : destroy one demolition gadget or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return points to its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6DemolitionsGadget::VectorDeletingDestructor(AR6DemolitionsGadget *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6DemolitionsGadget *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement = reinterpret_cast<ElementDestructor>(
        &AR6DemolitionsGadget::~AR6DemolitionsGadget); // AR6DemolitionsGadget destructor.
    destroyElements(this, 0x67c, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6DemolitionsGadget::~AR6DemolitionsGadget(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x67c); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll @ 10003970 : construct a demolition gadget in nonnull supplied memory
// The native nonnull path tail-jumps to the default constructor; null returns immediately.
void __cdecl AR6DemolitionsGadget::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6DemolitionsGadget::AR6DemolitionsGadget((AR6DemolitionsGadget *)objectMemory);
}

// R6Weapons.dll @ 10003cd0 : snapshot demolition-gadget ammunition and appearance flags before replication
// Stores ammunition first, then normalized detonator/hide bits from one flags-word load.
void __thiscall AR6DemolitionsGadget::PreNetReceive(AR6DemolitionsGadget *this) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchDemolitionsPreReceiveException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AR6AbstractWeapon::PreNetReceive((AR6AbstractWeapon *)this);
  previousBulletCount = (uint) * (const byte *)&this->m_iNbBulletsInWeapon; // +0x396, zero-extended.
  const uint gadgetFlags = *(const uint *)((const byte *)this + 0x62c);
  previousDetonatorFlag = (gadgetFlags >> 7) & 1; // m_bDetonator.
  previousHideFlag = (gadgetFlags >> 6) & 1;      // m_bHide.
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003d3c : throw the unsigned-short pointer caught by the DemolitionsPreReceive guard
// Copies the parent catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowDemolitionsPreReceiveMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003d50 : report the DemolitionsPreReceive guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportDemolitionsPreReceiveException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)demolitionsPreNetReceiveContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005690 : select the DemolitionsPreReceive exception metadata and tail-transfer to the CRT
// dispatcher Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchDemolitionsPreReceiveException(void) {
  __asm {
    mov eax, offset demolitionsPreReceiveFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004d10 : dispatch demolition-gadget appearance and ammunition changes after replication
// Hide changes take priority over detonator changes; ammunition is read after the appearance event returns.
void __thiscall AR6DemolitionsGadget::PostNetReceive(AR6DemolitionsGadget *this) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchDemolitionsPostReceiveException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AR6AbstractWeapon::PostNetReceive((AR6AbstractWeapon *)this);
  const uint gadgetFlags = *(const uint *)((const byte *)this + 0x62c);
  bool dispatchAppearance = true;
  FName appearanceEvent;
  if (previousHideFlag != ((gadgetFlags >> 6) & 1))
    appearanceEvent = R6WEAPONS_HideAttachment;
  else if (previousDetonatorFlag != ((gadgetFlags >> 7) & 1))
    appearanceEvent = R6WEAPONS_SetGadgetStaticMesh;
  else
    dispatchAppearance = false;
  if (dispatchAppearance) {
    UFunction *function = UObject::FindFunctionChecked((UObject *)this, appearanceEvent, 0);
    using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
    // Native loads this after FindFunctionChecked.
    const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
    EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
    processEvent((UObject *)this, function, nullptr, nullptr);
  }
  const byte bulletCount = *(const byte *)&this->m_iNbBulletsInWeapon; // +0x396, read after the appearance event.
  if (previousBulletCount != (uint)bulletCount) {
    UFunction *function = UObject::FindFunctionChecked((UObject *)this, R6WEAPONS_NbBulletChange, 0);
    using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
    const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
    EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
    processEvent((UObject *)this, function, nullptr, nullptr);
  }
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10004dcc : throw the unsigned-short pointer caught by the DemolitionsPostReceive guard
// Copies the parent catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowDemolitionsPostReceiveMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004de0 : report the DemolitionsPostReceive guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportDemolitionsPostReceiveException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)demolitionsPostNetReceiveContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005720 : select the DemolitionsPostReceive exception metadata and tail-transfer to the CRT
// dispatcher Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchDemolitionsPostReceiveException(void) {
  __asm {
    mov eax, offset demolitionsPostReceiveFuncInfo
    jmp __CxxFrameHandler
  }
}

// These unwind views expose inherited EBP, not a native stack parameter; native cleanup ends in a tail jump.
// R6Weapons.dll @ 100054d0 : destroy the gadget base during demolition-gadget destructor unwinding
// Releases the base after the remaining strings have been destroyed (state 0 -> -1).
void UnwindDemolitionsDestructorBase(byte *parentFrameEBP) {
  AR6Gadget *gadget = *(AR6Gadget **)(parentFrameEBP - 0x10);
  AR6Gadget::~AR6Gadget(gadget);
}

// R6Weapons.dll @ 100054d8 : destroy the reticule-block class string during demolition-gadget destructor unwinding
// Releases the +0x664 string before base destruction (state 1 -> 0).
void UnwindDemolitionsDestructorBlockClass(byte *parentFrameEBP) {
  AR6DemolitionsGadget *gadget = *(AR6DemolitionsGadget **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&gadget->m_szReticuleBlockClass);
}

// R6Weapons.dll @ 100054e7 : destroy the detonator class string during demolition-gadget destructor unwinding
// Releases the +0x670 string if ConditionalDestroy throws (state 2 -> 1).
void UnwindDemolitionsDestructorDetonatorClass(byte *parentFrameEBP) {
  AR6DemolitionsGadget *gadget = *(AR6DemolitionsGadget **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&gadget->m_szDetonatorReticuleClass);
}

// R6Weapons.dll @ 100054f6 : select demolition-gadget destructor exception metadata
// Supplies FuncInfo in EAX and preserves the native dispatcher stack and all other registers.
__declspec(naked) void DispatchDemolitionsDestructorException(void) {
  __asm {
    mov eax, offset demolitionsDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005500 : destroy the gadget base during demolition-gadget constructor unwinding
// Releases the completed base for both default and copy construction (state 0 -> -1).
void UnwindDemolitionsConstructorBase(byte *parentFrameEBP) {
  AR6Gadget *gadget = *(AR6Gadget **)(parentFrameEBP - 0x10);
  AR6Gadget::~AR6Gadget(gadget);
}

// R6Weapons.dll @ 10005508 : destroy the reticule-block class string during demolition-gadget constructor unwinding
// Releases the +0x664 string if construction of the second string throws (state 1 -> 0).
void UnwindDemolitionsConstructorBlockClass(byte *parentFrameEBP) {
  AR6DemolitionsGadget *gadget = *(AR6DemolitionsGadget **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&gadget->m_szReticuleBlockClass);
}

// R6Weapons.dll @ 10005517 : select the shared demolition-gadget default/copy-constructor exception metadata
// Supplies FuncInfo in EAX and preserves the native dispatcher stack and all other registers.
__declspec(naked) void DispatchDemolitionsConstructorException(void) {
  __asm {
    mov eax, offset demolitionsConstructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005d30 : destroy AR6DemolitionsGadget class metadata
// Supplies the registered metadata receiver; native code tail-jumps to imported UClass destruction.
void DestroyAR6DemolitionsGadgetClassMetadata(void) {
  UClass::~UClass(&AR6DemolitionsGadget::PrivateStaticClass);
}

// R6Weapons.dll data @ 1000df54 : exported class pointer autoclassAR6DemolitionsGadget
UClass *autoclassAR6DemolitionsGadget = nullptr;

// R6Weapons.dll @ 10005b70 : bind the exported AR6DemolitionsGadget class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6DemolitionsGadgetAutoClass(void) {
  autoclassAR6DemolitionsGadget = &AR6DemolitionsGadget::PrivateStaticClass;
}

// R6Weapons.dll @ 10005af0 : initialize AR6DemolitionsGadget class metadata and register its destruction
// Caches imported pointers before config lookup; supplies zero class flags/GUID and the local parent metadata address.
void InitializeAR6DemolitionsGadgetClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6DemolitionsGadget::PrivateStaticClass, (ENativeConstructor)0, 0x67c, 0,
                 &AR6Gadget::PrivateStaticClass, withinClass, classGuid,
                 (const ushort *)(r6DemolitionsGadgetClassNameStorage + 1), GPackage, configName, 0x4084004,
                 AR6DemolitionsGadget::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6DemolitionsGadgetClassMetadata);
}
