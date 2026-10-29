// R6Abstract.dll data @ 10010dd4 : exported four-byte event name, initially zero
FName R6ABSTRACT_SpawnSelectedGadget;

// R6Abstract.dll data @ 10006fec : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix weaponDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &weaponDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006fe4 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry weaponDestructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindWeaponDestructionBase},
};

// R6Abstract.dll data @ 1000d108 : shared gadget-class snapshot captured by PreNetReceive
UClass *previousWeaponGadgetClass = nullptr;
// R6Abstract.dll data @ 1000d10c : shared owner snapshot captured by PreNetReceive
AActor *previousWeaponOwner = nullptr;

// R6Abstract.dll data @ 1000ef80 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractWeapon::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractWeaponVTable {
  NativeActorVTable actor;
  NativeImageWord32 GetHeartBeatStatus; // +0x184.
};

// R6Abstract.dll data @ 10005ea0 : AR6AbstractWeapon virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const AR6AbstractWeaponVTable AR6AbstractWeapon_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractWeapon::VectorDeletingDestructor, // +0x00c; native 100024c0
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
    .PreNetReceive = &AR6AbstractWeapon::PreNetReceive, // +0x094; native 10003360
    .PostNetReceive = &AR6AbstractWeapon::PostNetReceive, // +0x098; native 10003390
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
  .GetHeartBeatStatus = &ForwardEngineAR6EngineWeaponGetHeartBeatStatus, // +0x184; native 10003c3c
};

// R6Abstract.dll data @ 1000fea0 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractWeapon = nullptr;

// R6Abstract.dll @ 10002250 : void eventSpawnSelectedGadget(AR6AbstractWeapon * this) Dispatches SpawnSelectedGadget
// through ProcessEvent with no argument or result buffer.
void __thiscall AR6AbstractWeapon::eventSpawnSelectedGadget(AR6AbstractWeapon *this) {
  const NativeUObjectVTable *vtable;
  UFunction *function;

  vtable = *reinterpret_cast<const NativeUObjectVTable *const *>(this);
  function = UObject::FindFunctionChecked(this, R6ABSTRACT_SpawnSelectedGadget, 0);
  // The virtual dispatcher receives this in ECX.
  using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
  EventDispatcher processEvent = *reinterpret_cast<const EventDispatcher *>(&vtable->ProcessEvent);
  processEvent(this, function, nullptr, nullptr);
  return;
}

// R6Abstract.dll @ 10002280 : return the AR6AbstractWeapon class object
UClass *__cdecl AR6AbstractWeapon::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002290 : allocate AR6AbstractWeapon using its class object and supplied object parameters
void *__cdecl AR6AbstractWeapon::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                              ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 100022c0 : conditionally shut down the object, then destroy its AR6EngineWeapon base
void __thiscall AR6AbstractWeapon::~AR6AbstractWeapon(AR6AbstractWeapon *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleAR6AbstractWeaponDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractWeaponVTable **>(this) = &AR6AbstractWeapon_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  AR6EngineWeapon::~AR6EngineWeapon(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10002320 : construct AR6EngineWeapon and install the AR6AbstractWeapon vtable
AR6AbstractWeapon::AR6AbstractWeapon() : AR6EngineWeapon() {
  // The constructor installs AR6AbstractWeapon_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002340 : copy-construct the base and reflected members
AR6AbstractWeapon::AR6AbstractWeapon(const AR6AbstractWeapon &source) : AR6EngineWeapon(source) {
  // The constructor installs AR6AbstractWeapon_vftable after the base; native EAX returns this.
  uint *destinationFlags = (uint *)((byte *)this + 0x4dc);
  const uint *sourceFlags = (const uint *)((const byte *)&source + 0x4dc);
  uint copiedFlags;

  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bHiddenWhenNotInUse.
  *destinationFlags = copiedFlags;
  this->m_SelectedWeaponGadget = source.m_SelectedWeaponGadget; // +0x4e0, 4 bytes.
  this->m_ScopeGadget = source.m_ScopeGadget;                   // +0x4e4, 4 bytes.
  this->m_BipodGadget = source.m_BipodGadget;                   // +0x4e8, 4 bytes.
  this->m_MuzzleGadget = source.m_MuzzleGadget;                 // +0x4ec, 4 bytes.
  this->m_MagazineGadget = source.m_MagazineGadget;             // +0x4f0, 4 bytes.
  this->m_FPHands = source.m_FPHands;                           // +0x4f4, 4 bytes.
  this->m_FPWeapon = source.m_FPWeapon;                         // +0x4f8, 4 bytes.
  this->m_FPGadget = source.m_FPGadget;                         // +0x4fc, 4 bytes.
  this->m_WeaponGadgetClass = source.m_WeaponGadgetClass;       // +0x500, 4 bytes.
  this->m_pFPHandsClass = source.m_pFPHandsClass;               // +0x504, 4 bytes.
  this->m_pFPWeaponClass = source.m_pFPWeaponClass;             // +0x508, 4 bytes.
}

// R6Abstract.dll @ 10002400 : assign the base and reflected members
AR6AbstractWeapon *__thiscall AR6AbstractWeapon::operator=(AR6AbstractWeapon *this, const AR6AbstractWeapon * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x4dc);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x4dc);
  uint copiedFlags;

  AR6EngineWeapon::operator=(this, source);
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bHiddenWhenNotInUse.
  *destinationFlags = copiedFlags;
  this->m_SelectedWeaponGadget = source->m_SelectedWeaponGadget; // +0x4e0, 4 bytes.
  this->m_ScopeGadget = source->m_ScopeGadget;                   // +0x4e4, 4 bytes.
  this->m_BipodGadget = source->m_BipodGadget;                   // +0x4e8, 4 bytes.
  this->m_MuzzleGadget = source->m_MuzzleGadget;                 // +0x4ec, 4 bytes.
  this->m_MagazineGadget = source->m_MagazineGadget;             // +0x4f0, 4 bytes.
  this->m_FPHands = source->m_FPHands;                           // +0x4f4, 4 bytes.
  this->m_FPWeapon = source->m_FPWeapon;                         // +0x4f8, 4 bytes.
  this->m_FPGadget = source->m_FPGadget;                         // +0x4fc, 4 bytes.
  this->m_WeaponGadgetClass = source->m_WeaponGadgetClass;       // +0x500, 4 bytes.
  this->m_pFPHandsClass = source->m_pFPHandsClass;               // +0x504, 4 bytes.
  this->m_pFPWeaponClass = source->m_pFPWeaponClass;             // +0x508, 4 bytes.
  return this;
}

// R6Abstract.dll @ 100024c0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractWeapon::VectorDeletingDestructor(AR6AbstractWeapon *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x50c, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractWeapon::~AR6AbstractWeapon);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractWeapon::~AR6AbstractWeapon();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x50c);
  return this;
}

// R6Abstract.dll @ 10003170 : construct AR6AbstractWeapon in supplied memory when it is nonnull
void __cdecl AR6AbstractWeapon::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractWeapon; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10003360 : PreNetReceive Saves the owner and gadget class before receiving replicated changes.
void __thiscall AR6AbstractWeapon::PreNetReceive(AR6AbstractWeapon *this) {
  AActor::PreNetReceive(this);
  AActor *ownerAfterBase = this->Owner;                     // +0x140.
  UClass *gadgetClassAfterBase = this->m_WeaponGadgetClass; // +0x500.
  previousWeaponOwner = ownerAfterBase;
  previousWeaponGadgetClass = gadgetClassAfterBase;
}

// R6Abstract.dll @ 10003390 : PostNetReceive Updates attachment and gadget state when their replicated values change.
void __thiscall AR6AbstractWeapon::PostNetReceive(AR6AbstractWeapon *this) {
  AActor::PostNetReceive(this);
  AActor *ownerBeforeCheck = this->Owner;
  if (ownerBeforeCheck != nullptr) {
    APawn *ownerPawn = ownerBeforeCheck->GetPlayerPawn();
    if (ownerPawn != nullptr && this->Owner != previousWeaponOwner) {
      AR6EngineWeapon::eventUpdateWeaponAttachment(this);
    }
  }
  if (previousWeaponGadgetClass != this->m_WeaponGadgetClass) {
    const auto *weaponVtable = *reinterpret_cast<const NativeUObjectVTable *const *>(this);
    UFunction *spawnSelectedGadget = UObject::FindFunctionChecked(this, R6ABSTRACT_SpawnSelectedGadget, 0);
    using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
    EventDispatcher dispatch = *reinterpret_cast<const EventDispatcher *>(&weaponVtable->ProcessEvent);
    dispatch(this, spawnSelectedGadget, nullptr, nullptr);
  }
}

// R6Abstract.dll @ 100041b0 : destroy AR6EngineWeapon during Weapon destructor unwind parentFrame exposes inherited
// EBP, not a native stack argument.
void UnwindWeaponDestructionBase(const byte *parentFrame) {
  AR6AbstractWeapon *object = *(AR6AbstractWeapon *const *)(parentFrame - 0x10);
  AR6EngineWeapon::~AR6EngineWeapon(object); // Native tail jump.
}

// R6Abstract.dll @ 10004400 : initialize AR6AbstractWeapon class metadata and register its cleanup
void InitializeAR6AbstractWeaponClassMetadata(void) {
  UClass *parentClass = (UClass *)AR6EngineWeapon_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractWeapon::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractWeapon::PrivateStaticClass) UClass(EC_NativeConstructor, 0x50c, 0x0, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractWeapon", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractWeaponClassMetadata);
}

// R6Abstract.dll @ 10004490 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractWeaponClassMetadata(void) {
  autoclassAR6AbstractWeapon = &AR6AbstractWeapon::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c10 : destroy AR6AbstractWeapon class metadata
void DestroyAR6AbstractWeaponClassMetadata(void) {
  AR6AbstractWeapon::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 100041b9 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractWeaponDestructionFrame(void) {
  __asm {
    mov eax, offset weaponDestructionMetadata
    jmp __CxxFrameHandler
  }
}
