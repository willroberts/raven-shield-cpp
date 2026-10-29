// R6Abstract.dll data @ 10006e38 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix corpseExecFirstInitMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &corpseExecFirstInitUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &corpseExecFirstInitTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006e24 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry corpseExecFirstInitTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &corpseExecFirstInitCatchMap,
  },
};

// R6Abstract.dll data @ 10006e04 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry corpseExecFirstInitCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -28,
    .handler = &ForwardAR6AbstractCorpseExecFirstInitCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportAR6AbstractCorpseExecFirstInitException,
  },
};

// R6Abstract.dll data @ 10006df4 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry corpseExecFirstInitUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10006dd8 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix corpseExecRenderBonesMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &corpseExecRenderBonesUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &corpseExecRenderBonesTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006dc4 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry corpseExecRenderBonesTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &corpseExecRenderBonesCatchMap,
  },
};

// R6Abstract.dll data @ 10006da4 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry corpseExecRenderBonesCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -28,
    .handler = &ForwardAR6AbstractCorpseExecRenderBonesCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportAR6AbstractCorpseExecRenderBonesException,
  },
};

// R6Abstract.dll data @ 10006d94 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry corpseExecRenderBonesUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10006d78 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix corpseExecAddImpulseToBoneMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &corpseExecAddImpulseToBoneUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &corpseExecAddImpulseToBoneTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10006d64 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry corpseExecAddImpulseToBoneTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &corpseExecAddImpulseToBoneCatchMap,
  },
};

// R6Abstract.dll data @ 10006d44 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry corpseExecAddImpulseToBoneCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -28,
    .handler = &ForwardAR6AbstractCorpseExecAddImpulseToBoneCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportAR6AbstractCorpseExecAddImpulseToBoneException,
  },
};

// R6Abstract.dll data @ 10006d34 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry corpseExecAddImpulseToBoneUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 1000f488 : zero-initialized exported class object, constructed by CRT startup
UClass AR6AbstractCorpse::PrivateStaticClass;

// Native table extension; the prefix is embedded storage, not an inferred C++ base class.
struct AR6AbstractCorpseVTable {
  NativeActorVTable actor;
  NativeImageWord32 FirstInit; // +0x184.
  NativeImageWord32 RenderBones; // +0x188.
  NativeImageWord32 AddImpulseToBone; // +0x18c.
};

// R6Abstract.dll data @ 100061b0 : AR6AbstractCorpse virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const AR6AbstractCorpseVTable AR6AbstractCorpse_vftable = {
  .actor = {
    .object = {
      .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
      .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
      .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
      .VectorDeletingDestructor = &AR6AbstractCorpse::VectorDeletingDestructor, // +0x00c; native 10002940
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
  .FirstInit = &AR6AbstractCorpse::FirstInit, // +0x184; native 10002d20
  .RenderBones = &AR6AbstractCorpse::FirstInit, // +0x188; native 10002d20
  .AddImpulseToBone = &AR6AbstractCorpse::AddImpulseToBone, // +0x18c; native 100028d0
};

// R6Abstract.dll data @ 1000d0d8 : exported four-byte native member-function pointer
extern "C" ScriptNativeMethod intAR6AbstractCorpseexecRenderBones =
    (ScriptNativeMethod)&AR6AbstractCorpse::execRenderBones;
// R6Abstract.dll data @ 1000ea74 : one-byte native-registration result, initially zero
uchar execRenderBonesRegistrationStatus = 0;

// R6Abstract.dll data @ 1000d0d4 : exported four-byte native member-function pointer
extern "C" ScriptNativeMethod intAR6AbstractCorpseexecFirstInit = (ScriptNativeMethod)&AR6AbstractCorpse::execFirstInit;
// R6Abstract.dll data @ 1000e059 : one-byte native-registration result, initially zero
uchar execFirstInitRegistrationStatus = 0;

// R6Abstract.dll data @ 1000d0d0 : exported four-byte native member-function pointer
extern "C" ScriptNativeMethod intAR6AbstractCorpseexecAddImpulseToBone =
    (ScriptNativeMethod)&AR6AbstractCorpse::execAddImpulseToBone;
// R6Abstract.dll data @ 100108c0 : one-byte native-registration result, initially zero
uchar execAddImpulseToBoneRegistrationStatus = 0;

// R6Abstract.dll data @ 1000e05c : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassAR6AbstractCorpse = nullptr;

// R6Abstract.dll @ 10001000 : execAddImpulseToBone Evaluates two bytecode arguments and optional DebugInfo, then
// invokes slot +0x18c with an int and by-value FVector. Native stack cleanup is RET 8; the delegated impulse body is
// represented separately.
void __thiscall AR6AbstractCorpse::execAddImpulseToBone(AR6AbstractCorpse *this, FFrame *stack, void *unusedResult) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  byte *&code = stack->Code; // FFrame +0x0c; alias preserves cursor reloads after native calls.
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractCorpseExecAddImpulseToBoneFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  int iTracedBone = 0;
  FVector vMomentum;
  byte opcode1 = *code++;
  reinterpret_cast<ScriptNative *>(GNatives_exref)[opcode1](stack->Object, stack, &iTracedBone);
  byte opcode2 = *code++;
  reinterpret_cast<ScriptNative *>(GNatives_exref)[opcode2](stack->Object, stack, &vMomentum);
  ++code;
  if (*code == 0x42) { // Selected execDebugInfo opcode.
    ++code;
    reinterpret_cast<ScriptNative *>(GNatives_exref)[0x42](stack->Object, stack, nullptr);
  }
  this->AddImpulseToBone(iTracedBone, vMomentum); // Virtual dispatch; receiver is this, not stack->Object.
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 100010c3 : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardAR6AbstractCorpseExecAddImpulseToBoneCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x18);
  *throwValue = *(ushort **)(parentFrame - 0x1c);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 100010d7 : report method context before forwarding the active exception
__declspec(noreturn) void ReportAR6AbstractCorpseExecAddImpulseToBoneException(void) {
  appUnwindf((const ushort *)L"%s", L"AR6AbstractCorpse::execAddImpulseToBone");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 10001100 : execRenderBones Evaluates the canvas and dispatches corpse bone rendering.
void __thiscall AR6AbstractCorpse::execRenderBones(AR6AbstractCorpse *this, FFrame *stack, void *unusedResult) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  byte *&code = stack->Code; // FFrame +0x0c; alias preserves cursor reloads after native calls.
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractCorpseExecRenderBonesFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  UCanvas *canvas = nullptr;
  byte opcode1 = *code++;
  reinterpret_cast<ScriptNative *>(GNatives_exref)[opcode1](stack->Object, stack, &canvas);
  ++code;
  if (*code == 0x42) { // Selected execDebugInfo opcode.
    ++code;
    reinterpret_cast<ScriptNative *>(GNatives_exref)[0x42](stack->Object, stack, nullptr);
  }
  this->RenderBones(canvas); // Virtual dispatch; receiver is this, not stack->Object.
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10001193 : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardAR6AbstractCorpseExecRenderBonesCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x18);
  *throwValue = *(ushort **)(parentFrame - 0x1c);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 100011a7 : report method context before forwarding the active exception
__declspec(noreturn) void ReportAR6AbstractCorpseExecRenderBonesException(void) {
  appUnwindf((const ushort *)L"%s", L"AR6AbstractCorpse::execRenderBones");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 100011d0 : execFirstInit Evaluates the owning pawn and dispatches corpse initialization.
void __thiscall AR6AbstractCorpse::execFirstInit(AR6AbstractCorpse *this, FFrame *stack, void *unusedResult) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  byte *&code = stack->Code; // FFrame +0x0c; alias preserves cursor reloads after native calls.
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleAR6AbstractCorpseExecFirstInitFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AR6AbstractPawn *pawnOwner = nullptr;
  byte opcode1 = *code++;
  reinterpret_cast<ScriptNative *>(GNatives_exref)[opcode1](stack->Object, stack, &pawnOwner);
  ++code;
  if (*code == 0x42) { // Selected execDebugInfo opcode.
    ++code;
    reinterpret_cast<ScriptNative *>(GNatives_exref)[0x42](stack->Object, stack, nullptr);
  }
  this->FirstInit(pawnOwner); // Virtual dispatch; receiver is this, not stack->Object.
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10001263 : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardAR6AbstractCorpseExecFirstInitCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x18);
  *throwValue = *(ushort **)(parentFrame - 0x1c);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 10001277 : report method context before forwarding the active exception
__declspec(noreturn) void ReportAR6AbstractCorpseExecFirstInitException(void) {
  appUnwindf((const ushort *)L"%s", L"AR6AbstractCorpse::execFirstInit");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 10002830 : return the AR6AbstractCorpse class object
UClass *__cdecl AR6AbstractCorpse::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002840 : allocate AR6AbstractCorpse using its class object and supplied object parameters
void *__cdecl AR6AbstractCorpse::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                              ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10002870 : conditionally shut down the object, then destroy its AActor base
void __thiscall AR6AbstractCorpse::~AR6AbstractCorpse(AR6AbstractCorpse *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleSharedActorDestructionFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const AR6AbstractCorpseVTable **>(this) = &AR6AbstractCorpse_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  AActor::~AActor(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 100028e0 : construct AActor and install the AR6AbstractCorpse vtable
AR6AbstractCorpse::AR6AbstractCorpse() : AActor() {
  // The constructor installs AR6AbstractCorpse_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002900 : copy-construct AR6AbstractCorpse from a const reference Copy-constructs through AActor
// and installs the AR6AbstractCorpse vtable.
AR6AbstractCorpse::AR6AbstractCorpse(const AR6AbstractCorpse &source) : AActor(source) {
  // The constructor installs AR6AbstractCorpse_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002940 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall AR6AbstractCorpse::VectorDeletingDestructor(AR6AbstractCorpse *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x394, elementCount,
                                    (ArrayElementDestructor)&AR6AbstractCorpse::~AR6AbstractCorpse);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->AR6AbstractCorpse::~AR6AbstractCorpse();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x394);
  return this;
}

// R6Abstract.dll @ 10003190 : construct AR6AbstractCorpse in supplied memory when it is nonnull
void __cdecl AR6AbstractCorpse::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) AR6AbstractCorpse; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 100045e0 : initialize AR6AbstractCorpse class metadata and register its cleanup
void InitializeAR6AbstractCorpseClassMetadata(void) {
  UClass *parentClass = (UClass *)AActor_PrivateStaticClass_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = AR6AbstractCorpse::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&AR6AbstractCorpse::PrivateStaticClass) UClass(EC_NativeConstructor, 0x394, 0x0, parentClass, withinClass,
      FGuid(0, 0, 0, 0), L"R6AbstractCorpse", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyAR6AbstractCorpseClassMetadata);
}

// R6Abstract.dll @ 10004670 : publish the class object through its exported autoclass pointer
void PublishAR6AbstractCorpseClassMetadata(void) {
  autoclassAR6AbstractCorpse = &AR6AbstractCorpse::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c40 : destroy AR6AbstractCorpse class metadata
void DestroyAR6AbstractCorpseClassMetadata(void) {
  AR6AbstractCorpse::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004b00 : register the exported script-native descriptor and retain the byte result
void RegisterAR6AbstractCorpseExecAddImpulseToBone(void) {
  execAddImpulseToBoneRegistrationStatus = GRegisterNative(0x70c, intAR6AbstractCorpseexecAddImpulseToBone);
}

// R6Abstract.dll @ 10004b20 : register the exported script-native descriptor and retain the byte result
void RegisterAR6AbstractCorpseExecFirstInit(void) {
  execFirstInitRegistrationStatus = GRegisterNative(0x70b, intAR6AbstractCorpseexecFirstInit);
}

// R6Abstract.dll @ 10004b40 : register the exported script-native descriptor and retain the byte result
void RegisterAR6AbstractCorpseExecRenderBones(void) {
  execRenderBonesRegistrationStatus = GRegisterNative(0x70a, intAR6AbstractCorpseexecRenderBones);
}

// R6Abstract.dll @ 10004040 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractCorpseExecAddImpulseToBoneFrame(void) {
  __asm {
    mov eax, offset corpseExecAddImpulseToBoneMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 10004050 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractCorpseExecRenderBonesFrame(void) {
  __asm {
    mov eax, offset corpseExecRenderBonesMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 10004060 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleAR6AbstractCorpseExecFirstInitFrame(void) {
  __asm {
    mov eax, offset corpseExecFirstInitMetadata
    jmp __CxxFrameHandler
  }
}
