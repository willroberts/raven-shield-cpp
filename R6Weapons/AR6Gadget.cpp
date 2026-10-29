// R6Weapons.dll data @ 100075e8 : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6GadgetClassNameStorage[] = u"AR6Gadget";

// R6Weapons.dll data @ 10007930 : gadgetDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry gadgetDestructorUnwindMap[1] = {
    {.previousState = -1, .cleanup = &UnwindGadgetDestructorBase},
};

// R6Weapons.dll data @ 10007938 : gadgetDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix gadgetDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &gadgetDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10006488 : exported AR6Gadget virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeWeaponVTable AR6Gadget_vftable = {
    .actor =
        {
            .QueryInterface = &ForwardUObjectQueryInterface,
            .AddRef = &ForwardUObjectAddRef,
            .Release = &ForwardUObjectRelease,
            .VectorDeletingDestructor = &AR6Gadget::VectorDeletingDestructor,
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

// R6Weapons.dll data @ 1000da48 : exported AR6Gadget::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6GadgetClassMetadataStorage[0x508] = {};
UClass &AR6Gadget::PrivateStaticClass = *(UClass *)AR6GadgetClassMetadataStorage;

// R6Weapons.dll @ 100019d0 : return the AR6Gadget class object
// Returns the class metadata object at native address 0x1000da48.
UClass *__cdecl AR6Gadget::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 100019e0 : allocate AR6Gadget using its class object and supplied object parameters
// Forwards outer/name/flags and the current GError to StaticAllocateObject; allocationSize is unused.
void *__cdecl AR6Gadget::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10001a10 : destroy AR6Gadget and its AR6Weapons base
// Installs the gadget vtable and runs ConditionalDestroy before base destruction.
// FuncInfo 0x10007938 maps state 0 to base cleanup 0x100054b0, with predecessor -1.
void __thiscall AR6Gadget::~AR6Gadget(AR6Gadget *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchGadgetDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeWeaponVTable **)this = &AR6Gadget_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = -1;
  AR6Weapons::~AR6Weapons((AR6Weapons *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10001a60 : construct AR6Gadget through AR6Weapons
// Constructs the weapon base, installs the gadget vtable, and returns the receiver.
// The decorated export identifies this default constructor as protected.
AR6Gadget *__thiscall AR6Gadget::AR6Gadget(AR6Gadget *this) {
  AR6Weapons::AR6Weapons((AR6Weapons *)this);
  *(const NativeWeaponVTable **)this = &AR6Gadget_vftable;
  return this;
}

// R6Weapons.dll @ 10001a80 : copy-construct AR6Gadget from a const reference
// Copy-constructs the weapon base, installs the gadget vtable, and returns the receiver.
AR6Gadget *__thiscall AR6Gadget::AR6Gadget(AR6Gadget *this, const AR6Gadget *source) {
  AR6Weapons::AR6Weapons((AR6Weapons *)this, (const AR6Weapons *)source);
  *(const NativeWeaponVTable **)this = &AR6Gadget_vftable;
  return this;
}

// R6Weapons.dll @ 10001aa0 : assign AR6Gadget from a const reference and return this
// Assigns the weapon base without changing the vtable or checking for self-assignment.
AR6Gadget *__thiscall AR6Gadget::operator=(AR6Gadget *this, const AR6Gadget * source) {
  AR6Weapons::operator=((AR6Weapons *)this, (const AR6Weapons *)source);
  return this;
}

// R6Weapons.dll @ 10001ac0 : destroy one gadget or a counted gadget array and optionally release its allocation
// Flag 2 selects array destruction; flag 1 releases memory. The array result includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; the vtable points here at +0x0c.
void *__thiscall AR6Gadget::VectorDeletingDestructor(AR6Gadget *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6Gadget *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6Gadget::~AR6Gadget); // AR6Gadget::~AR6Gadget.
    destroyElements(this, 0x62c, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6Gadget::~AR6Gadget(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x62c); // Imported sized overload at IAT 0x1000605c.
  return this;
}

// R6Weapons.dll @ 10003960 : construct AR6Gadget in supplied memory when it is nonnull
// Calls the default constructor only for nonnull memory; the native nonnull path is a tail jump.
void __cdecl AR6Gadget::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6Gadget::AR6Gadget((AR6Gadget *)objectMemory);
}

// R6Weapons.dll @ 100054b0 : destroy the weapon base during AR6Gadget destructor unwinding
// Releases the base if ConditionalDestroy throws (state 0 -> -1).
// parentFrameEBP represents inherited EBP, not a native stack argument; the native call is a tail jump.
void UnwindGadgetDestructorBase(byte *parentFrameEBP) {
  AR6Weapons *weapon = *(AR6Weapons **)(parentFrameEBP - 0x10);
  AR6Weapons::~AR6Weapons(weapon);
}

// R6Weapons.dll @ 100059d0 : initialize AR6Gadget class metadata and register its cleanup
// Caches imported pointers before config lookup; supplies the weapon parent, zero GUID and gadget construction bridge.
void InitializeAR6GadgetClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6Gadget::PrivateStaticClass, (ENativeConstructor)0, 0x62c, 0, &AR6Weapons::PrivateStaticClass,
                 withinClass, classGuid, (const ushort *)(r6GadgetClassNameStorage + 1), GPackage, configName,
                 0x4084004, AR6Gadget::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6GadgetClassMetadata);
}

// R6Weapons.dll @ 10005a50 : initialize the exported gadget class pointer
// Binds autoclassAR6Gadget at 0x1000cb20 to the gadget metadata object.
void InitializeAR6GadgetAutoClass(void) {
  autoclassAR6Gadget = &AR6Gadget::PrivateStaticClass;
}

// R6Weapons.dll @ 10005d10 : destroy AR6Gadget class metadata
// Destroys the registered gadget metadata object; native code tail-jumps to UClass's destructor.
void DestroyAR6GadgetClassMetadata(void) {
  UClass::~UClass(&AR6Gadget::PrivateStaticClass);
}

// R6Weapons.dll @ 100054b8 : dispatch GadgetDestructor exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchGadgetDestructorException(void) {
  __asm {
    mov eax, offset gadgetDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll data @ 1000cb20 : exported class pointer autoclassAR6Gadget
UClass *autoclassAR6Gadget = nullptr;
