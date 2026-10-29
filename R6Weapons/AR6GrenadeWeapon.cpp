// R6Weapons.dll data @ 100075fc : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6GrenadeWeaponClassNameStorage[] = u"AR6GrenadeWeapon";

// R6Weapons.dll data @ 100067b8 : exported AR6GrenadeWeapon virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeWeaponVTable AR6GrenadeWeapon_vftable = {
    .actor =
        {
            .QueryInterface = &ForwardUObjectQueryInterface,
            .AddRef = &ForwardUObjectAddRef,
            .Release = &ForwardUObjectRelease,
            .VectorDeletingDestructor = &AR6GrenadeWeapon::VectorDeletingDestructor,
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
    .GetHeartBeatStatus = &AR6Weapons::GetHeartBeatStatus,
    .ShowWeaponParticles = &AR6Weapons::ShowWeaponParticles,
    .ComputeEffectiveAccuracy = &AR6Weapons::ComputeEffectiveAccuracy,
    .GetMovingModifier = &AR6Weapons::GetMovingModifier,
    .WeaponIsNotFiring = &AR6Weapons::WeaponIsNotFiring,
};

// R6Weapons.dll data @ 1000e970 : exported AR6GrenadeWeapon::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6GrenadeWeaponClassMetadataStorage[0x508] = {};
UClass &AR6GrenadeWeapon::PrivateStaticClass = *(UClass *)AR6GrenadeWeaponClassMetadataStorage;

// R6Weapons.dll @ 10002050 : return the AR6GrenadeWeapon class object
// Returns the class metadata object at native address 0x1000e970.
UClass *__cdecl AR6GrenadeWeapon::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10002060 : allocate AR6GrenadeWeapon using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6GrenadeWeapon::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10002090 : destroy the AR6GrenadeWeapon instance and its gadget base
// Runs conditional shutdown with shared gadget-base exception cleanup, then destroys the gadget base.
void __thiscall AR6GrenadeWeapon::~AR6GrenadeWeapon(AR6GrenadeWeapon *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchSharedGadgetCleanupException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeWeaponVTable **)this = &AR6GrenadeWeapon_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = -1;
  AR6Gadget::~AR6Gadget((AR6Gadget *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 100020e0 : construct weapon state and install the AR6GrenadeWeapon vtable
// Calls the weapon constructor directly; this optimized path adds no gadget call or member stores.
AR6GrenadeWeapon *__thiscall AR6GrenadeWeapon::AR6GrenadeWeapon(AR6GrenadeWeapon *this) {
  AR6Weapons::AR6Weapons((AR6Weapons *)this);
  *(const NativeWeaponVTable **)this = &AR6GrenadeWeapon_vftable;
  return this;
}

// R6Weapons.dll @ 10002100 : copy-construct the base and reflected members
// Snapshots destination flags before the vtable/throw-mode stores, then merges four source bits.
AR6GrenadeWeapon *__thiscall AR6GrenadeWeapon::AR6GrenadeWeapon(AR6GrenadeWeapon *this,
                                                                const AR6GrenadeWeapon *source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x630);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x630);

  AR6Weapons::AR6Weapons((AR6Weapons *)this, (const AR6Weapons *)source);
  const uint earlyDestinationFlags = *destinationFlags;
  *(const NativeWeaponVTable **)this = &AR6GrenadeWeapon_vftable;
  *(byte *)&this->m_eThrow = *(const byte *)&source->m_eThrow; // +0x62c; padding +0x62d..+0x62f is untouched.
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags;
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bCanThrowGrenade.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bFistPersonAnimFinish.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bPinToRemove.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bReadyToThrow.
  *destinationFlags = copiedFlags;
  return this;
}

// R6Weapons.dll @ 10002180 : assign the base and reflected members
// Copies one throw-mode byte and merges four flags while retaining the native early destination snapshot.
AR6GrenadeWeapon *__thiscall AR6GrenadeWeapon::operator=(AR6GrenadeWeapon *this, const AR6GrenadeWeapon * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x630);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x630);

  AR6Weapons::operator=((AR6Weapons *)this, (const AR6Weapons *)source);
  const byte throwMode = *(const byte *)&source->m_eThrow; // +0x62c, read before destination flags.
  const uint earlyDestinationFlags = *destinationFlags;
  *(byte *)&this->m_eThrow = throwMode;
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags;
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bCanThrowGrenade.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bFistPersonAnimFinish.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bPinToRemove.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bReadyToThrow.
  *destinationFlags = copiedFlags;
  return this;
}

// R6Weapons.dll @ 10003980 : construct AR6GrenadeWeapon in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6GrenadeWeapon::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6GrenadeWeapon::AR6GrenadeWeapon((AR6GrenadeWeapon *)objectMemory);
}

// R6Weapons.dll @ 10005d20 : destroy AR6GrenadeWeapon class metadata
// Supplies the registered metadata receiver; native code tail-jumps to imported UClass destruction.
void DestroyAR6GrenadeWeaponClassMetadata(void) {
  UClass::~UClass(&AR6GrenadeWeapon::PrivateStaticClass);
}

// R6Weapons.dll @ 10002200 : destroy one AR6GrenadeWeapon or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6GrenadeWeapon::VectorDeletingDestructor(AR6GrenadeWeapon *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6GrenadeWeapon *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6GrenadeWeapon::~AR6GrenadeWeapon); // AR6GrenadeWeapon destructor.
    destroyElements(this, 0x634, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6GrenadeWeapon::~AR6GrenadeWeapon(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x634); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000cb18 : exported class pointer autoclassAR6GrenadeWeapon
UClass *autoclassAR6GrenadeWeapon = nullptr;

// R6Weapons.dll @ 10005ae0 : bind the exported AR6GrenadeWeapon class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6GrenadeWeaponAutoClass(void) {
  autoclassAR6GrenadeWeapon = &AR6GrenadeWeapon::PrivateStaticClass;
}

// R6Weapons.dll @ 10005a60 : initialize AR6GrenadeWeapon class metadata and register its destruction
// Caches imported pointers before config lookup; supplies zero class flags/GUID and the local parent metadata address.
void InitializeAR6GrenadeWeaponClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6GrenadeWeapon::PrivateStaticClass, (ENativeConstructor)0, 0x634, 0, &AR6Gadget::PrivateStaticClass,
                 withinClass, classGuid, (const ushort *)(r6GrenadeWeaponClassNameStorage + 1), GPackage, configName,
                 0x4084004, AR6GrenadeWeapon::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6GrenadeWeaponClassMetadata);
}
