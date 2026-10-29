// R6Weapons.dll data @ 10007664 : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6SmokeCloudClassNameStorage[] = u"AR6SmokeCloud";

// R6Weapons.dll data @ 10006df8 : exported AR6SmokeCloud virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeActorVTable AR6SmokeCloud_vftable = {
    .QueryInterface = &ForwardUObjectQueryInterface,
    .AddRef = &ForwardUObjectAddRef,
    .Release = &ForwardUObjectRelease,
    .VectorDeletingDestructor = &AR6SmokeCloud::VectorDeletingDestructor,
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
    .IsBlockedBy = &AR6SmokeCloud::IsBlockedBy,
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
    .ShouldTrace = &AR6SmokeCloud::ShouldTrace,
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

// R6Weapons.dll data @ 1000d030 : exported AR6SmokeCloud::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6SmokeCloudClassMetadataStorage[0x508] = {};
UClass &AR6SmokeCloud::PrivateStaticClass = *(UClass *)AR6SmokeCloudClassMetadataStorage;

// R6Weapons.dll @ 10002dc0 : return the AR6SmokeCloud class object
// Returns the class metadata object at native address 0x1000d030.
UClass *__cdecl AR6SmokeCloud::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10002dd0 : allocate AR6SmokeCloud using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6SmokeCloud::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10002e10 : destroy the smoke cloud and its actor base
// Runs conditional shutdown with actor-base exception cleanup, then destroys the actor base.
void __thiscall AR6SmokeCloud::~AR6SmokeCloud(AR6SmokeCloud *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchSharedActorCleanupException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeActorVTable **)this = &AR6SmokeCloud_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = -1;
  AActor::~AActor((AActor *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10002e70 : return the selected trace-mask bit unless the suppression bit is set
// Mask 0x80000 forces zero; otherwise returns 0 or 0x20000 without reading either object.
int __thiscall AR6SmokeCloud::ShouldTrace(AR6SmokeCloud *this, AActor *unusedActor, ulong traceFlags) {
  if ((traceFlags & 0x80000) != 0)
    return 0;
  return traceFlags & 0x20000;
}

// R6Weapons.dll @ 10002e90 : reject blocking against every supplied actor
// Returns full-width zero without reading either object; the exported receiver and argument are const.
int __thiscall AR6SmokeCloud::IsBlockedBy(const AR6SmokeCloud *this, const AActor *otherActor) {
  return 0;
}

// R6Weapons.dll @ 10002ea0 : construct the actor base and install the smoke-cloud vtable
// Adds no member initialization after the actor constructor returns.
AR6SmokeCloud *__thiscall AR6SmokeCloud::AR6SmokeCloud(AR6SmokeCloud *this) {
  AActor::AActor((AActor *)this);
  *(const NativeActorVTable **)this = &AR6SmokeCloud_vftable;
  return this;
}

// R6Weapons.dll @ 10002ec0 : copy-construct the actor base and five smoke-cloud fields
// Preserves raw floating-point words and the shallow grenade reference in native access order.
AR6SmokeCloud *__thiscall AR6SmokeCloud::AR6SmokeCloud(AR6SmokeCloud *this, const AR6SmokeCloud *source) {
  AActor::AActor((AActor *)this, (const AActor *)source);
  *(const NativeActorVTable **)this = &AR6SmokeCloud_vftable;
  *(uint *)&this->m_fStartTime = *(const uint *)&source->m_fStartTime;         // +0x394.
  *(uint *)&this->m_fExpansionTime = *(const uint *)&source->m_fExpansionTime; // +0x398.
  *(uint *)&this->m_fFinalRadius = *(const uint *)&source->m_fFinalRadius;     // +0x39c.
  *(uint *)&this->m_fCurrentRadius = *(const uint *)&source->m_fCurrentRadius; // +0x3a0.
  this->m_grenade = source->m_grenade;                                         // +0x3a4, shallow reference.
  return this;
}

// R6Weapons.dll @ 10002f20 : assign the actor base and five smoke-cloud fields
// Preserves raw floating-point words and the shallow grenade reference in native access order.
AR6SmokeCloud *__thiscall AR6SmokeCloud::operator=(AR6SmokeCloud *this, const AR6SmokeCloud * source) {
  AActor::operator=((AActor *)this, (const AActor *)source);
  *(uint *)&this->m_fStartTime = *(const uint *)&source->m_fStartTime;         // +0x394.
  *(uint *)&this->m_fExpansionTime = *(const uint *)&source->m_fExpansionTime; // +0x398.
  *(uint *)&this->m_fFinalRadius = *(const uint *)&source->m_fFinalRadius;     // +0x39c.
  *(uint *)&this->m_fCurrentRadius = *(const uint *)&source->m_fCurrentRadius; // +0x3a0.
  this->m_grenade = source->m_grenade;                                         // +0x3a4, shallow reference.
  return this;
}

// R6Weapons.dll @ 100039c0 : construct AR6SmokeCloud in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6SmokeCloud::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6SmokeCloud::AR6SmokeCloud((AR6SmokeCloud *)objectMemory);
}

// R6Weapons.dll @ 10005c20 : initialize AR6SmokeCloud class metadata and register its destruction
// Snapshots imported class/static-constructor pointers before config lookup; supplies a zero GUID and native flags.
void InitializeAR6SmokeCloudClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  UClass *parentClass = (UClass *)AActor_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6SmokeCloud::PrivateStaticClass, (ENativeConstructor)0, 0x3a8, 0, parentClass, withinClass,
                 classGuid, (const ushort *)(r6SmokeCloudClassNameStorage + 1), GPackage, configName, 0x4084004,
                 AR6SmokeCloud::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6SmokeCloudClassMetadata);
}

// R6Weapons.dll @ 10005d50 : destroy AR6SmokeCloud class metadata
// Destroys the metadata object registered by the class initializer; native code tail-jumps to UClass's destructor.
void DestroyAR6SmokeCloudClassMetadata(void) {
  UClass::~UClass(&AR6SmokeCloud::PrivateStaticClass);
}

// R6Weapons.dll @ 10002f80 : destroy one AR6SmokeCloud or a counted array and optionally free its allocation
// Flag 2 selects array mode; flag 1 releases memory. The array return includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; exported vtable +0x0c points here.
void *__thiscall AR6SmokeCloud::VectorDeletingDestructor(AR6SmokeCloud *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6SmokeCloud *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6SmokeCloud::~AR6SmokeCloud); // AR6SmokeCloud destructor.
    destroyElements(this, 0x3a8, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6SmokeCloud::~AR6SmokeCloud(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x3a8); // Sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll data @ 1000cb1c : exported class pointer autoclassAR6SmokeCloud
UClass *autoclassAR6SmokeCloud = nullptr;

// R6Weapons.dll @ 10005cb0 : bind the exported AR6SmokeCloud class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6SmokeCloudAutoClass(void) {
  autoclassAR6SmokeCloud = &AR6SmokeCloud::PrivateStaticClass;
}
