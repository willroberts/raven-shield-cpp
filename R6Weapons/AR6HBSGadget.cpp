// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006080 : Core.dll ?GRegisterNative@@YAEHABQ8UObject@@AEXAAUFFrame@@QAX@Z@Z
extern uint registerNativeImport;

// R6Weapons.dll data @ 100071f0 : UTF-16 native text
const char16_t heartBeatToggleContext[] = u"AR6HBSGadget::execToggleHeartBeatProperties";

// R6Weapons.dll data @ 100075cc : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6HBSGadgetClassNameStorage[] = u"AR6HBSGadget";

// R6Weapons.dll data @ 10007c48 : heartbeatToggle unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry heartbeatToggleUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007c58 : heartbeatToggle typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry heartbeatToggleCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -28,
        .handler = &RethrowHeartbeatToggleMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportHeartbeatToggleException,
    },
};

// R6Weapons.dll data @ 10007c78 : heartbeatToggle protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry heartbeatToggleTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &heartbeatToggleCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007c8c : heartbeatToggle exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix heartbeatToggleFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &heartbeatToggleUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &heartbeatToggleTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006950 : exported AR6HBSGadget virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeWeaponVTable AR6HBSGadget_vftable = {
    .actor =
        {
            .QueryInterface = &ForwardUObjectQueryInterface,
            .AddRef = &ForwardUObjectAddRef,
            .Release = &ForwardUObjectRelease,
            .VectorDeletingDestructor = &AR6HBSGadget::VectorDeletingDestructor,
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
            .PreNetReceive = &AR6Weapons::PreNetReceive,
            .PostNetReceive = &AR6Weapons::PostNetReceive,
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
    .GetHeartBeatStatus = &AR6HBSGadget::GetHeartBeatStatus,
    .ShowWeaponParticles = &AR6Weapons::ShowWeaponParticles,
    .ComputeEffectiveAccuracy = &AR6Weapons::ComputeEffectiveAccuracy,
    .GetMovingModifier = &AR6Weapons::GetMovingModifier,
    .WeaponIsNotFiring = &AR6Weapons::WeaponIsNotFiring,
};

// R6Weapons.dll data @ 1000d538 : exported AR6HBSGadget::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6HBSGadgetClassMetadataStorage[0x508] = {};
UClass &AR6HBSGadget::PrivateStaticClass = *(UClass *)AR6HBSGadgetClassMetadataStorage;

// R6Weapons.dll @ 10002270 : return the AR6HBSGadget class object
// Returns the class metadata object at native address 0x1000d538.
UClass *__cdecl AR6HBSGadget::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10002280 : allocate AR6HBSGadget using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6HBSGadget::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 100022b0 : destroy the AR6HBSGadget instance and its gadget base
// Runs conditional shutdown with shared gadget-base exception cleanup, then destroys the gadget base.
void __thiscall AR6HBSGadget::~AR6HBSGadget(AR6HBSGadget *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchSharedGadgetCleanupException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeWeaponVTable **)this = &AR6HBSGadget_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = -1;
  AR6Gadget::~AR6Gadget((AR6Gadget *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10002300 : return the gadget heartbeat flag as an integer
// Reads m_bHeartBeatOn at +0x62c, mask 1, and returns exactly zero or one.
int __thiscall AR6HBSGadget::GetHeartBeatStatus(AR6HBSGadget *this) {
  return *(uint *)((byte *)this + 0x62c) & 1;
}

// R6Weapons.dll @ 10002310 : construct weapon state and install the AR6HBSGadget vtable
// Calls the weapon constructor directly; this optimized path adds no gadget call or member stores.
AR6HBSGadget *__thiscall AR6HBSGadget::AR6HBSGadget(AR6HBSGadget *this) {
  AR6Weapons::AR6Weapons((AR6Weapons *)this);
  *(const NativeWeaponVTable **)this = &AR6HBSGadget_vftable;
  return this;
}

// R6Weapons.dll @ 10002330 : copy weapon state, heartbeat bit and shallow sound references
// Snapshots destination flags before installing the HBS vtable, then merges only bit zero from the source.
AR6HBSGadget *__thiscall AR6HBSGadget::AR6HBSGadget(AR6HBSGadget *this, const AR6HBSGadget *source) {
  AR6Weapons::AR6Weapons((AR6Weapons *)this, (const AR6Weapons *)source);
  uint *destinationFlags = (uint *)((byte *)this + 0x62c);
  uint retainedFlags = *destinationFlags;
  *(const NativeWeaponVTable **)this = &AR6HBSGadget_vftable;
  uint sourceFlags = *(const uint *)((const byte *)source + 0x62c);
  *destinationFlags = retainedFlags ^ ((sourceFlags ^ retainedFlags) & 1); // m_bHeartBeatOn.
  this->m_sndActivation = source->m_sndActivation;                         // +0x630, shallow reference.
  this->m_sndDesactivation = source->m_sndDesactivation;                   // +0x634, package spelling retained.
  return this;
}

// R6Weapons.dll @ 10002380 : assign weapon state, heartbeat bit and shallow sound references
// Loads source flags before the destination snapshot and preserves every destination bit except mask 1.
AR6HBSGadget *__thiscall AR6HBSGadget::operator=(AR6HBSGadget *this, const AR6HBSGadget * source) {
  AR6Weapons::operator=((AR6Weapons *)this, (const AR6Weapons *)source);
  const uint sourceFlags = *(const uint *)((const byte *)source + 0x62c);
  uint *destinationFlags = (uint *)((byte *)this + 0x62c);
  const uint retainedFlags = *destinationFlags;
  *destinationFlags = retainedFlags ^ ((sourceFlags ^ retainedFlags) & 1); // m_bHeartBeatOn.
  this->m_sndActivation = source->m_sndActivation;                         // +0x630, shallow reference.
  this->m_sndDesactivation = source->m_sndDesactivation;                   // +0x634, package spelling retained.
  return this;
}

// R6Weapons.dll @ 10003990 : construct AR6HBSGadget in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6HBSGadget::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6HBSGadget::AR6HBSGadget((AR6HBSGadget *)objectMemory);
}

// R6Weapons.dll @ 10003a90 : set level heartbeat mode, clear night/heat vision and advance the material revision
// Evaluates the script bool, handles an optional 0x42 opcode, and preserves three separate level lookups.
void __thiscall AR6HBSGadget::execToggleHeartBeatProperties(AR6HBSGadget *this, FFrame *frame, void *unusedResult) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  int guardState = -1;
  void *previousExceptionList = ExceptionList;
  byte *exceptionHandler = (byte *)&DispatchHeartbeatToggleException;
  ExceptionList = &previousExceptionList;
  int turnItOn = 0; // Four-byte script bool bTurnItOn.
  byte **codeCursor = (byte **)((byte *)frame + 0x0c);
  byte opcode = *(*codeCursor)++;
  ScriptNative *firstNativeTable = (ScriptNative *)GNatives_exref;
  UObject *firstContext = *(UObject **)((byte *)frame + 8);
  guardState = 0;
  firstNativeTable[opcode](firstContext, frame, &turnItOn);
  byte *endCursor = *codeCursor + 1;
  *codeCursor = endCursor;
  if (*endCursor == 0x42) {
    UObject *trailingContext = *(UObject **)((byte *)frame + 8);
    *codeCursor = endCursor + 1;
    ScriptNative *trailingNativeTable = (ScriptNative *)GNatives_exref;
    trailingNativeTable[0x42](trailingContext, frame, nullptr);
  }
  ALevelInfo *levelInfo = ULevel::GetLevelInfo(*(ULevel **)((byte *)this + 0x328)); // Actor::XLevel.
  const uint requestedFlags = (uint)turnItOn;
  uint *heartbeatFlags = (uint *)((byte *)levelInfo + 0x454);
  const uint previousFlags = *heartbeatFlags;
  *heartbeatFlags = previousFlags ^ (((requestedFlags * 4u) ^ previousFlags) & 4u); // m_bHeartBeatOn.
  levelInfo = ULevel::GetLevelInfo(*(ULevel **)((byte *)this + 0x328));
  *(uint *)((byte *)levelInfo + 0x450) &= 0xfeffffff; // Clear m_bNightVisionActive.
  levelInfo = ULevel::GetLevelInfo(*(ULevel **)((byte *)this + 0x328));
  *(uint *)((byte *)levelInfo + 0x450) &= 0xfdffffff; // Clear m_bHeatVisionActive.
  byte *materialRevision = (byte *)GCompileMaterialsRevision_exref;
  *materialRevision = (byte)(*materialRevision + 1);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003b77 : throw the unsigned-short message pointer caught by the HeartbeatToggle guard
// Copies the parent catch slot to its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowHeartbeatToggleMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x1c);
  *(ushort **)(parentFrameEBP - 0x18) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x18,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003b8b : report the HeartbeatToggle guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportHeartbeatToggleException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)heartBeatToggleContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005660 : dispatch the HeartbeatToggle guard using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchHeartbeatToggleException(void) {
  __asm {
    mov eax, offset heartbeatToggleFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005d00 : destroy AR6HBSGadget class metadata
// Supplies the registered metadata receiver; native code tail-jumps to imported UClass destruction.
void DestroyAR6HBSGadgetClassMetadata(void) {
  UClass::~UClass(&AR6HBSGadget::PrivateStaticClass);
}

// R6Weapons.dll @ 100023d0 : destroy one AR6HBSGadget or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6HBSGadget::VectorDeletingDestructor(AR6HBSGadget *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6HBSGadget *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6HBSGadget::~AR6HBSGadget); // AR6HBSGadget destructor.
    destroyElements(this, 0x638, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6HBSGadget::~AR6HBSGadget(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x638); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000e968 : exported class pointer autoclassAR6HBSGadget
UClass *autoclassAR6HBSGadget = nullptr;

// R6Weapons.dll @ 100059c0 : bind the exported AR6HBSGadget class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6HBSGadgetAutoClass(void) {
  autoclassAR6HBSGadget = &AR6HBSGadget::PrivateStaticClass;
}

// R6Weapons.dll @ 10005940 : initialize AR6HBSGadget class metadata and register its destruction
// Caches imported pointers before config lookup; supplies zero class flags/GUID and the local parent metadata address.
void InitializeAR6HBSGadgetClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6HBSGadget::PrivateStaticClass, (ENativeConstructor)0, 0x638, 0, &AR6Gadget::PrivateStaticClass,
                 withinClass, classGuid, (const ushort *)(r6HBSGadgetClassNameStorage + 1), GPackage, configName,
                 0x4084004, AR6HBSGadget::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6HBSGadgetClassMetadata);
}

// R6Weapons.dll data @ 1000c070 : exported single-word script member pointer
// intAR6HBSGadgetexecToggleHeartBeatProperties
NativeImageWord32 intAR6HBSGadgetexecToggleHeartBeatProperties = &AR6HBSGadget::execToggleHeartBeatProperties;
// R6Weapons.dll data @ 1000c5fc : low-byte result of script-native registration
byte heartbeatRegistrationResult = 0;

// R6Weapons.dll @ 10005730 : register script native 0xa8c using the exported member-pointer word
// The registrar receives the word's address (const reference); only its returned AL is stored.
void RegisterHeartbeatScriptNative(void) {
  using RegisterNativeWord = byte(__cdecl *)(int, const NativeImageWord32 *);
  RegisterNativeWord registerNative = reinterpret_cast<RegisterNativeWord>(registerNativeImport);
  heartbeatRegistrationResult = registerNative(0xa8c, &intAR6HBSGadgetexecToggleHeartBeatProperties);
}
