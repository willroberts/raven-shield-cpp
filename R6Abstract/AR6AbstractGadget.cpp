// R6Abstract.dll data @ 1000739c : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gadgetGetOptimizedRepListMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000005,
  .unwindMap = &gadgetGetOptimizedRepListUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &gadgetGetOptimizedRepListTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007388 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry gadgetGetOptimizedRepListTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000003,
    .catchHighState = 0x00000004,
    .handlerCount = 0x00000002,
    .handlers = &gadgetGetOptimizedRepListCatchMap,
  },
};

// R6Abstract.dll data @ 10007368 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry gadgetGetOptimizedRepListCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -28,
    .handler = &ForwardAR6AbstractGadgetGetOptimizedRepListCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportAR6AbstractGadgetGetOptimizedRepListException,
  },
};

// R6Abstract.dll data @ 10007340 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gadgetGetOptimizedRepListUnwindMap[5] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = 0x00000000, .cleanup = &UnwindGadgetWeaponOwnerPropertyInitialization},
  {.previousState = 0x00000000, .cleanup = &UnwindGadgetOwnerCharacterPropertyInitialization},
  {.previousState = 0x00000000, .cleanup = &UnwindGadgetAttachmentNamePropertyInitialization},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10007090 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gadgetConstructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000003,
  .unwindMap = &gadgetConstructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007078 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gadgetConstructionUnwindMap[3] = {
  {.previousState = -1, .cleanup = &UnwindGadgetConstructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindGadgetConstructionNameID},
  {.previousState = 0x00000001, .cleanup = &UnwindGadgetConstructionGadgetName},
};

// R6Abstract.dll data @ 10007028 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gadgetDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000004,
  .unwindMap = &gadgetDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007008 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gadgetDestructionUnwindMap[4] = {
  {.previousState = -1, .cleanup = &UnwindGadgetDestructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindGadgetDestructionNameID},
  {.previousState = 0x00000001, .cleanup = &UnwindGadgetDestructionGadgetName},
  {.previousState = 0x00000002, .cleanup = &UnwindGadgetDestructionGadgetShortName},
};

// R6Abstract.dll data @ 10010ddc : cached reflected m_AttachmentName property
UProperty *attachmentNameProperty = nullptr;
// R6Abstract.dll data @ 10010de0 : cached reflected m_OwnerCharacter property
UProperty *ownerCharacterProperty = nullptr;
// R6Abstract.dll data @ 10010de4 : cached reflected m_WeaponOwner property
UProperty *weaponOwnerProperty = nullptr;
// R6Abstract.dll data @ 10010de8 : lazy-property initialization masks 1, 2 and 4
uint gadgetPropertyInitFlags = 0;

// R6Abstract.dll data @ 100103b8 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractGadget::PrivateStaticClass;

// R6Abstract.dll data @ 10006028 : AR6AbstractGadget virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const NativeActorVTable AR6AbstractGadget_vftable = {
  .object = {
    .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
    .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
    .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
    .VectorDeletingDestructor = &AR6AbstractGadget::VectorDeletingDestructor, // +0x00c; native 100027c0
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
  .GetOptimizedRepList = &AR6AbstractGadget::GetOptimizedRepList, // +0x064; native 10003570
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
};

// R6Abstract.dll data @ 1000d62c : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractGadget = nullptr;

// R6Abstract.dll @ 10002530 : return the AR6AbstractGadget class object
UClass *__cdecl AR6AbstractGadget::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002540 : allocate AR6AbstractGadget using its class object and supplied object parameters
void *__cdecl AR6AbstractGadget::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                              ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10002570 : destroy the object, its string members, and its base
void __thiscall AR6AbstractGadget::~AR6AbstractGadget(AR6AbstractGadget *this) {
  int destructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractGadgetDestructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const NativeActorVTable **>(this) = &AR6AbstractGadget_vftable;
  destructionState = 3;
  UObject::ConditionalDestroy(this);
  destructionState = 2;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_GadgetShortName); // +0x3bc.
  destructionState = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_GadgetName); // +0x3b0.
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_NameID); // +0x3a4.
  destructionState = -1;
  AActor::~AActor(this);
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10002600 : construct AActor and leave all three string subobjects uninitialized
AR6AbstractGadget *__thiscall AR6AbstractGadget::AR6AbstractGadget(AR6AbstractGadget *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int constructionState;

  constructionState = -1;
  exceptionHandler = &HandleAR6AbstractGadgetConstructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AActor::AActor(this);
  constructionState = 0;
  *reinterpret_cast<const NativeActorVTable **>(this) = &AR6AbstractGadget_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_NameID); // +0x3a4; no writes.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_GadgetName); // +0x3b0; no writes.
  constructionState = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_GadgetShortName); // +0x3bc; no writes.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10002680 : copy-construct the base and reflected members
AR6AbstractGadget *__thiscall AR6AbstractGadget::AR6AbstractGadget(AR6AbstractGadget *this,
                                                                   const AR6AbstractGadget *source) {
  int constructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractGadgetConstructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;

  AActor::AActor(this, source);
  *reinterpret_cast<const NativeActorVTable **>(this) = &AR6AbstractGadget_vftable;
  this->m_eGadgetType = source->m_eGadgetType;       // +0x394, 1 byte.
  this->m_WeaponOwner = source->m_WeaponOwner;       // +0x398, 4 bytes.
  this->m_OwnerCharacter = source->m_OwnerCharacter; // +0x39c, 4 bytes.
  constructionState = 0;
  this->m_AttachmentName = source->m_AttachmentName; // +0x3a0, 4 bytes.
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_NameID,
                               (const FStringNoInit *)&source->m_NameID); // +0x3a4.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_GadgetName,
                               (const FStringNoInit *)&source->m_GadgetName); // +0x3b0.
  constructionState = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_GadgetShortName,
                               (const FStringNoInit *)&source->m_GadgetShortName); // +0x3bc.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10002740 : assign the base, byte type, object/name fields, and three strings
AR6AbstractGadget *__thiscall AR6AbstractGadget::operator=(AR6AbstractGadget *this, const AR6AbstractGadget * source) {
  AActor::operator=(this, source);
  this->m_eGadgetType = source->m_eGadgetType;       // +0x394, 1 byte.
  this->m_WeaponOwner = source->m_WeaponOwner;       // +0x398, 4 bytes.
  this->m_OwnerCharacter = source->m_OwnerCharacter; // +0x39c, 4 bytes.
  this->m_AttachmentName = source->m_AttachmentName; // +0x3a0, 4 bytes.
  FStringNoInit::operator=((FStringNoInit *)&this->m_NameID,
                           (const FStringNoInit *)&source->m_NameID); // +0x3a4.
  FStringNoInit::operator=((FStringNoInit *)&this->m_GadgetName,
                           (const FStringNoInit *)&source->m_GadgetName); // +0x3b0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_GadgetShortName,
                           (const FStringNoInit *)&source->m_GadgetShortName); // +0x3bc.
  return this;
}

// R6Abstract.dll @ 100027c0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractGadget::VectorDeletingDestructor(AR6AbstractGadget *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x3c8, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractGadget::~AR6AbstractGadget);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractGadget::~AR6AbstractGadget();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x3c8);
  return this;
}

// R6Abstract.dll @ 10003180 : construct AR6AbstractGadget in supplied memory when it is nonnull
void __cdecl AR6AbstractGadget::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractGadget; // Native tail jump to the constructor.
  return;
}

// Partial recent-state view, beginning at actor +0x398. Matching 1.60 properties establish
// these three four-byte fields; the byte buffer is not asserted to contain a live gadget object.
struct GadgetRecentProperties {
  AR6EngineWeapon *m_WeaponOwner; // +0x398.
  APawn *m_OwnerCharacter; // +0x39c.
  FName m_AttachmentName; // +0x3a0; comparisons retain the raw name word.
};

// R6Abstract.dll @ 10003570 : append changed gadget reference/name descriptors when Role is 4 Returns the advanced
// descriptor cursor in EAX; native stack cleanup is RET 0x14.
int *__thiscall AR6AbstractGadget::GetOptimizedRepList(AR6AbstractGadget *this, uchar *recentState,
                                                       FPropertyRetirement *retirement, int *replicationCursor,
                                                       UPackageMap *packageMap, UActorChannel *channel) {
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractGadgetGetOptimizedRepListFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  replicationCursor =
      AActor::GetOptimizedRepList(this, recentState, retirement, replicationCursor, packageMap, channel);
  if (this->Role == 4) { // Actor +0x2d.
    const auto *recentProperties = reinterpret_cast<const GadgetRecentProperties *>(recentState + 0x398);
    UObject *currentReference = this->m_WeaponOwner; // +0x398.
    UObject *recentReference = recentProperties->m_WeaponOwner;
    bool referenceChanged;
    if (packageMap->CanSerializeObject(currentReference) != 0) {
      referenceChanged = currentReference != recentReference;
    } else {
      channel->bActorMustStayDirty = 1; // +0x8c, four-byte store.
      referenceChanged = recentReference != nullptr;
    }
    if (referenceChanged) {
      if ((gadgetPropertyInitFlags & 1) == 0) {
        gadgetPropertyInitFlags |= 1;
        guardState = 1;
        weaponOwnerProperty = (UProperty *)UObject::StaticFindObjectChecked(
            (UClass *)UProperty_PrivateStaticClass_exref, &AR6AbstractGadget::PrivateStaticClass,
            (const ushort *)L"m_WeaponOwner", 0);
        guardState = 0;
      }
      *replicationCursor++ = weaponOwnerProperty->RepIndex;
    }

    currentReference = this->m_OwnerCharacter; // +0x39c, reloaded after the first lookup/call.
    recentReference = recentProperties->m_OwnerCharacter;
    if (packageMap->CanSerializeObject(currentReference) != 0) {
      referenceChanged = currentReference != recentReference;
    } else {
      channel->bActorMustStayDirty = 1; // +0x8c, four-byte store.
      referenceChanged = recentReference != nullptr;
    }
    if (referenceChanged) {
      if ((gadgetPropertyInitFlags & 2) == 0) {
        gadgetPropertyInitFlags |= 2;
        guardState = 2;
        ownerCharacterProperty = (UProperty *)UObject::StaticFindObjectChecked(
            (UClass *)UProperty_PrivateStaticClass_exref, &AR6AbstractGadget::PrivateStaticClass,
            (const ushort *)L"m_OwnerCharacter", 0);
        guardState = 0;
      }
      *replicationCursor++ = ownerCharacterProperty->RepIndex;
    }

    if (*(uint *)&this->m_AttachmentName != *reinterpret_cast<const uint *>(&recentProperties->m_AttachmentName)) {
      if ((gadgetPropertyInitFlags & 4) == 0) {
        gadgetPropertyInitFlags |= 4;
        guardState = 3;
        attachmentNameProperty = (UProperty *)UObject::StaticFindObjectChecked(
            (UClass *)UProperty_PrivateStaticClass_exref, &AR6AbstractGadget::PrivateStaticClass,
            (const ushort *)L"m_AttachmentName", 0);
      }
      *replicationCursor++ = attachmentNameProperty->RepIndex;
    }
  }
  ExceptionList = previousExceptionList;
  return replicationCursor;
}

// R6Abstract.dll @ 1000374a : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardAR6AbstractGadgetGetOptimizedRepListCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x18);
  *throwValue = *(ushort **)(parentFrame - 0x1c);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 1000375e : report method context before forwarding the active exception
__declspec(noreturn) void ReportAR6AbstractGadgetGetOptimizedRepListException(void) {
  appUnwindf((const ushort *)L"%s", L"AR6AbstractGadget::GetOptimizedRepList");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 100041d0 : destroy AActor during Gadget destructor unwind parentFrame exposes inherited EBP, not a
// native stack argument.
void UnwindGadgetDestructionBase(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  AActor::~AActor(object); // Native tail jump.
}

// R6Abstract.dll @ 100041d9 : destroy NameID during Gadget destructor unwind parentFrame exposes inherited EBP, not a
// native stack argument.
void UnwindGadgetDestructionNameID(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_NameID); // Native tail jump.
}

// R6Abstract.dll @ 100041e8 : destroy GadgetName during Gadget destructor unwind parentFrame exposes inherited EBP, not
// a native stack argument.
void UnwindGadgetDestructionGadgetName(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_GadgetName); // Native tail jump.
}

// R6Abstract.dll @ 100041f7 : destroy GadgetShortName during Gadget destructor unwind parentFrame exposes inherited
// EBP, not a native stack argument.
void UnwindGadgetDestructionGadgetShortName(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_GadgetShortName); // Native tail jump.
}

// R6Abstract.dll @ 10004210 : destroy AActor during either Gadget constructor unwind parentFrame exposes inherited EBP,
// not a native stack argument.
void UnwindGadgetConstructionBase(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  AActor::~AActor(object); // Native tail jump.
}

// R6Abstract.dll @ 10004219 : destroy NameID during either Gadget constructor unwind parentFrame exposes inherited EBP,
// not a native stack argument.
void UnwindGadgetConstructionNameID(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_NameID); // Native tail jump.
}

// R6Abstract.dll @ 10004228 : destroy GadgetName during either Gadget constructor unwind parentFrame exposes inherited
// EBP, not a native stack argument.
void UnwindGadgetConstructionGadgetName(const byte *parentFrame) {
  AR6AbstractGadget *object = *(AR6AbstractGadget *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_GadgetName); // Native tail jump.
}

// R6Abstract.dll @ 10004310 : clear initialization mask 1 so m_WeaponOwner lookup can retry
void UnwindGadgetWeaponOwnerPropertyInitialization(void) {
  gadgetPropertyInitFlags = gadgetPropertyInitFlags & 0xfffffffe;
  return;
}

// R6Abstract.dll @ 1000431e : clear initialization mask 2 so m_OwnerCharacter lookup can retry
void UnwindGadgetOwnerCharacterPropertyInitialization(void) {
  gadgetPropertyInitFlags = gadgetPropertyInitFlags & 0xfffffffd;
  return;
}

// R6Abstract.dll @ 1000432c : clear initialization mask 4 so m_AttachmentName lookup can retry
void UnwindGadgetAttachmentNamePropertyInitialization(void) {
  gadgetPropertyInitFlags = gadgetPropertyInitFlags & 0xfffffffb;
  return;
}

// R6Abstract.dll @ 10004680 : initialize AR6AbstractGadget class metadata and register its cleanup
void InitializeAR6AbstractGadgetClassMetadata(void) {
  UClass *parentClass = (UClass *)AActor_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractGadget::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractGadget::PrivateStaticClass) UClass(EC_NativeConstructor, 0x3c8, 0x800, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractGadget", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractGadgetClassMetadata);
}

// R6Abstract.dll @ 10004710 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractGadgetClassMetadata(void) {
  autoclassAR6AbstractGadget = &AR6AbstractGadget::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c50 : destroy AR6AbstractGadget class metadata
void DestroyAR6AbstractGadgetClassMetadata(void) {
  AR6AbstractGadget::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004206 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractGadgetDestructionFrame(void) {
  __asm {
    mov eax, offset gadgetDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 10004237 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractGadgetConstructionFrame(void) {
  __asm {
    mov eax, offset gadgetConstructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 1000433a : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractGadgetGetOptimizedRepListFrame(void) {
  __asm {
    mov eax, offset gadgetGetOptimizedRepListMetadata
    jmp __CxxFrameHandler
  }
}
