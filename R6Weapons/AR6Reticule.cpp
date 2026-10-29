// R6Weapons.dll data @ 100072f8 : UTF-16 native text
const char16_t reticuleUpdateContext[] = u"AR6Reticule::UpdateReticule";

// R6Weapons.dll data @ 1000764c : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6ReticuleClassNameStorage[] = u"AR6Reticule";

// R6Weapons.dll data @ 10007b14 : reticuleDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry reticuleDestructorUnwindMap[2] = {
    {.previousState = -1, .cleanup = &UnwindReticuleDestructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindReticuleDestructorCharacterName},
};

// R6Weapons.dll data @ 10007b24 : reticuleDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix reticuleDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &reticuleDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007dc8 : reticuleUpdate unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry reticuleUpdateUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007dd8 : reticuleUpdate typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry reticuleUpdateCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowReticuleUpdateMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportReticuleUpdateException,
    },
};

// R6Weapons.dll data @ 10007df8 : reticuleUpdate protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry reticuleUpdateTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &reticuleUpdateCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007e0c : reticuleUpdate exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix reticuleUpdateFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &reticuleUpdateUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &reticuleUpdateTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006f80 : exported AR6Reticule virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeActorVTable AR6Reticule_vftable = {
    .QueryInterface = &ForwardUObjectQueryInterface,
    .AddRef = &ForwardUObjectAddRef,
    .Release = &ForwardUObjectRelease,
    .VectorDeletingDestructor = &AR6Reticule::VectorDeletingDestructor,
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
    .IsBlockedBy = &ForwardAActorIsBlockedBy,
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

// R6Weapons.dll data @ 1000df58 : exported AR6Reticule::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6ReticuleClassMetadataStorage[0x508] = {};
UClass &AR6Reticule::PrivateStaticClass = *(UClass *)AR6ReticuleClassMetadataStorage;

// R6Weapons.dll @ 10002ff0 : return the AR6Reticule class object
// Returns the class metadata object at native address 0x1000df58.
UClass *__cdecl AR6Reticule::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10003000 : allocate AR6Reticule using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6Reticule::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10003030 : destroy the reticule, its character-name string and its actor base
// Runs conditional shutdown before destroying the character-name string and then the actor base.
void __thiscall AR6Reticule::~AR6Reticule(AR6Reticule *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchReticuleDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeActorVTable **)this = &AR6Reticule_vftable;
  destructionState = 1;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_CharacterName); // +0x3b8.
  destructionState = -1;
  AActor::~AActor((AActor *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 100030a0 : construct the actor base and no-init character-name string
// Installs the reticule vtable after base construction; the no-init string call leaves storage unchanged.
AR6Reticule *__thiscall AR6Reticule::AR6Reticule(AR6Reticule *this) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchSharedActorCleanupException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AActor::AActor((AActor *)this);
  constructionState = 0;
  *(const NativeActorVTable **)this = &AR6Reticule_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_CharacterName); // +0x3b8.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 100030f0 : copy-construct the base and reflected members
// Retains the pre-vtable flag snapshot, copies raw values and constructs the character-name string.
AR6Reticule *__thiscall AR6Reticule::AR6Reticule(AR6Reticule *this, const AR6Reticule *source) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchSharedActorCleanupException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((byte *)this + 0x39c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x39c);

  AActor::AActor((AActor *)this, (const AActor *)source);
  const uint earlyDestinationFlags = *destinationFlags; // Native read precedes the vtable store.
  *(const NativeActorVTable **)this = &AR6Reticule_vftable;
  this->m_iNonFunctionnalX = source->m_iNonFunctionnalX; // +0x394.
  this->m_iNonFunctionnalY = source->m_iNonFunctionnalY; // +0x398.
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags; // The first difference uses the earlier snapshot, not this reload.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bIdentifyCharacter.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bAimingAtFriendly.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bShowNames.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fAccuracy = *(const uint *)&source->m_fAccuracy;               // +0x3a0.
  *(uint *)&this->m_fZoomScale = *(const uint *)&source->m_fZoomScale;             // +0x3a4.
  *(uint *)&this->m_fReticuleOffsetX = *(const uint *)&source->m_fReticuleOffsetX; // +0x3a8.
  *(uint *)&this->m_fReticuleOffsetY = *(const uint *)&source->m_fReticuleOffsetY; // +0x3ac.
  this->m_SmallFont_14pt = source->m_SmallFont_14pt;                               // +0x3b0.
  *(uint *)&this->m_color = *(const uint *)&source->m_color;                       // +0x3b4.
  constructionState = 0;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_CharacterName,
                               (const FStringNoInit *)&source->m_CharacterName); // +0x3b8.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10003200 : assign the base and reflected members
// Retains the early flag snapshot, copies raw values and assigns the character-name string.
AR6Reticule *__thiscall AR6Reticule::operator=(AR6Reticule *this, const AR6Reticule * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x39c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x39c);

  AActor::operator=((AActor *)this, (const AActor *)source);
  const int nonFunctionalX = source->m_iNonFunctionnalX; // +0x394, loaded before destination flags.
  const uint earlyDestinationFlags = *destinationFlags;
  this->m_iNonFunctionnalX = nonFunctionalX;
  this->m_iNonFunctionnalY = source->m_iNonFunctionnalY; // +0x398.
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags; // The first difference uses the earlier snapshot, not this reload.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bIdentifyCharacter.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bAimingAtFriendly.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bShowNames.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fAccuracy = *(const uint *)&source->m_fAccuracy;               // +0x3a0.
  *(uint *)&this->m_fZoomScale = *(const uint *)&source->m_fZoomScale;             // +0x3a4.
  *(uint *)&this->m_fReticuleOffsetX = *(const uint *)&source->m_fReticuleOffsetX; // +0x3a8.
  *(uint *)&this->m_fReticuleOffsetY = *(const uint *)&source->m_fReticuleOffsetY; // +0x3ac.
  this->m_SmallFont_14pt = source->m_SmallFont_14pt;                               // +0x3b0.
  *(uint *)&this->m_color = *(const uint *)&source->m_color;                       // +0x3b4.
  FStringNoInit::operator=((FStringNoInit *)&this->m_CharacterName,
                           (const FStringNoInit *)&source->m_CharacterName); // +0x3b8.
  return this;
}

// R6Weapons.dll @ 100039d0 : construct a reticule in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6Reticule::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6Reticule::AR6Reticule((AR6Reticule *)objectMemory);
}

// R6Weapons.dll @ 10003d70 : update zoom-scaled accuracy and controller reticule offsets
// Leaves the reticule unchanged unless a controller, pawn and equipped EngineWeapon are present.
void __thiscall AR6Reticule::UpdateReticule(AR6Reticule *this, AR6PlayerController *playerController,
                                            float accuracyValue) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchReticuleUpdateException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  if (playerController != nullptr) {
    APawn *pawn = playerController->Pawn;                   // +0x3d8, loaded once for the equipment gate.
    if (pawn != nullptr && pawn->EngineWeapon != nullptr) { // EngineWeapon at +0x4fc.
      AR6PlayerController *defaultController =
          (AR6PlayerController *)UClass::GetDefaultActor((UClass *)AR6PlayerController_PrivateStaticClass_exref);
      const float10 comparedFov = (float10)playerController->FovAngle; // +0x3b0, read before the default FOV word.
      const uint defaultFovBits = *(const uint *)&defaultController->DesiredFOV; // +0x560, raw word snapshot.
      const float &defaultFov = *(const float *)&defaultFovBits;
      // FUCOMPP treats signed zeros as equal and unordered operands as unequal; sniper mode is read only if unequal.
      if ((float10)defaultFov == comparedFov || (*(const byte *)((const byte *)playerController + 0x838) & 4) != 0)
        this->m_fZoomScale = 1.0f;
      else
        this->m_fZoomScale = (float)((float10)defaultFov / (float10)playerController->FovAngle); // Reloads live FOV.
      this->m_fAccuracy = (float)((float10)accuracyValue * (float10)this->m_fZoomScale);     // Reloads stored scale.
      *(uint *)&this->m_fReticuleOffsetX = *(const uint *)&playerController->m_fCurrRetPosX; // +0x874 -> +0x3a8.
      *(uint *)&this->m_fReticuleOffsetY = *(const uint *)&playerController->m_fCurrRetPosY; // +0x878 -> +0x3ac.
    }
  }
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003e3e : throw the caught unsigned-short message pointer from the parent guard frame
// Copies the pointer into the throw temporary; parentFrameEBP is inherited EBP, not a native stack argument.
__declspec(noreturn) void RethrowReticuleUpdateMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003e52 : report UpdateReticule context and rethrow the active exception
// Adds the method name for the catch-all guard; two null throw-helper arguments request a rethrow.
__declspec(noreturn) void ReportReticuleUpdateException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)reticuleUpdateContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100055f0 : unwind the actor base during reticule destruction
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindReticuleDestructorBase(byte *parentFrameEBP) {
  AActor *actor = *(AActor **)(parentFrameEBP - 0x10);
  AActor::~AActor(actor);
}

// R6Weapons.dll @ 100055f9 : unwind the character-name string during reticule destruction
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindReticuleDestructorCharacterName(byte *parentFrameEBP) {
  AR6Reticule *reticule = *(AR6Reticule **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&reticule->m_CharacterName); // +0x3b8.
}

// R6Weapons.dll @ 10005608 : dispatch reticule destruction exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchReticuleDestructorException(void) {
  __asm {
    mov eax, offset reticuleDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 100056a0 : select UpdateReticule exception metadata and tail-transfer to the C++ dispatcher
// Supplies FuncInfo in EAX while preserving the native exception-dispatch stack and all other registers.
__declspec(naked) void DispatchReticuleUpdateException(void) {
  __asm {
    mov eax, offset reticuleUpdateFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005b80 : initialize AR6Reticule class metadata and register its destruction
// Snapshots imported class/static-constructor pointers before config lookup; supplies a zero GUID and native flags.
void InitializeAR6ReticuleClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  UClass *parentClass = (UClass *)AActor_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6Reticule::PrivateStaticClass, (ENativeConstructor)0, 0x3c4, 4, parentClass, withinClass, classGuid,
                 (const ushort *)(r6ReticuleClassNameStorage + 1), GPackage, configName, 0x4084004,
                 AR6Reticule::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6ReticuleClassMetadata);
}

// R6Weapons.dll @ 10005d40 : destroy AR6Reticule class metadata
// Destroys the metadata object registered by the class initializer; native code tail-jumps to UClass's destructor.
void DestroyAR6ReticuleClassMetadata(void) {
  UClass::~UClass(&AR6Reticule::PrivateStaticClass);
}

// R6Weapons.dll @ 100032d0 : destroy one AR6Reticule or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6Reticule::VectorDeletingDestructor(AR6Reticule *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6Reticule *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6Reticule::~AR6Reticule); // AR6Reticule destructor.
    destroyElements(this, 0x3c4, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6Reticule::~AR6Reticule(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x3c4); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000da40 : exported class pointer autoclassAR6Reticule
UClass *autoclassAR6Reticule = nullptr;

// R6Weapons.dll @ 10005c10 : bind the exported AR6Reticule class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6ReticuleAutoClass(void) {
  autoclassAR6Reticule = &AR6Reticule::PrivateStaticClass;
}
