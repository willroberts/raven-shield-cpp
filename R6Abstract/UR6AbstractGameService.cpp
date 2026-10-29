// R6Abstract.dll data @ 100072c4 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gameServiceExecNativeSubmitMatchResultMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &gameServiceExecNativeSubmitMatchResultUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &gameServiceExecNativeSubmitMatchResultTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 100072b0 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry gameServiceExecNativeSubmitMatchResultTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &gameServiceExecNativeSubmitMatchResultCatchMap,
  },
};

// R6Abstract.dll data @ 10007290 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry gameServiceExecNativeSubmitMatchResultCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -24,
    .handler = &ForwardUR6AbstractGameServiceExecNativeSubmitMatchResultCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportUR6AbstractGameServiceExecNativeSubmitMatchResultException,
  },
};

// R6Abstract.dll data @ 10007280 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gameServiceExecNativeSubmitMatchResultUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10007128 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix gameServiceDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &gameServiceDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007118 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry gameServiceDestructionUnwindMap[2] = {
  {.previousState = -1, .cleanup = &UnwindGameServiceDestructionBase},
  {.previousState = 0x00000000, .cleanup = &UnwindGameServiceDestructionUserID},
};

// R6Abstract.dll data @ 1000e060 : zero-initialized exported class object, constructed by CRT startup
UClass UR6AbstractGameService::PrivateStaticClass;

// Slot +0x08c is established by execNativeSubmitMatchResult. Shared target bodies do not
// establish the other slot names; retain those ranges without guessing their class-facing aliases.
struct UR6AbstractGameServiceVTable {
  NativeUObjectVTable object;
  NativeImageWord32 unresolvedBeforeSubmit[10]; // +0x064..+0x088.
  NativeImageWord32 NativeSubmitMatchResult; // +0x08c.
  NativeImageWord32 unresolvedAfterSubmit[25]; // +0x090..+0x0f0.
};

// R6Abstract.dll data @ 10006530 : UR6AbstractGameService virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const UR6AbstractGameServiceVTable UR6AbstractGameService_vftable = {
  .object = {
    .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
    .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
    .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
    .VectorDeletingDestructor = &UR6AbstractGameService::VectorDeletingDestructor, // +0x00c; native 10002f10
    .ProcessEvent = &ForwardCoreUObjectProcessEvent, // +0x010; native 100038d6
    .ProcessDelegate = &ForwardCoreUObjectProcessDelegate, // +0x014; native 10003882
    .ProcessState = &ForwardCoreUObjectProcessState, // +0x018; native 100038d0
    .ProcessRemoteFunction = &ForwardCoreUObjectProcessRemoteFunction, // +0x01c; native 100038ca
    .Modify = &ForwardCoreUObjectModify, // +0x020; native 1000387c
    .PostLoad = &ForwardCoreUObjectPostLoad, // +0x024; native 100038c4
    .Destroy = &ForwardCoreUObjectDestroy, // +0x028; native 100038be
    .Serialize = &ForwardCoreUObjectSerialize, // +0x02c; native 100038b8
    .IsPendingKill = &ForwardCoreUObjectIsPendingKill, // +0x030; native 100038b2
    .GotoState = &ForwardCoreUObjectGotoState, // +0x034; native 10003876
    .GotoLabel = &ForwardCoreUObjectGotoLabel, // +0x038; native 10003870
    .InitExecution = &ForwardCoreUObjectInitExecution, // +0x03c; native 100038ac
    .ShutdownAfterError = &ForwardCoreUObjectShutdownAfterError, // +0x040; native 1000386a
    .PostEditChange = &ForwardCoreUObjectPostEditChange, // +0x044; native 100038a6
    .CallFunction = &ForwardCoreUObjectCallFunction, // +0x048; native 10003864
    .ScriptConsoleExec = &ForwardCoreUObjectScriptConsoleExec, // +0x04c; native 1000385e
    .Register = &ForwardCoreUObjectRegister, // +0x050; native 10003858
    .LanguageChange = &ForwardCoreUObjectLanguageChange, // +0x054; native 10003852
    .IsPendingDelete = &ForwardCoreUObjectIsPendingDelete, // +0x058; native 100038a0
    .GetPropertiesSize = &ForwardCoreUObjectGetPropertiesSize, // +0x05c; native 1000384c
    .NetDirty = &ForwardCoreUObjectNetDirty, // +0x060; native 1000389a
  },
  .unresolvedBeforeSubmit = {
    &UR6AbstractGameService::Created, // +0x064; native 10002d40
    &UR6AbstractGameService::GetGroupID, // +0x068; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x06c; native 10002cf0
    &AR6AbstractCorpse::FirstInit, // +0x070; native 10002d20
    &AR6AbstractCorpse::FirstInit, // +0x074; native 10002d20
    &AR6AbstractCorpse::FirstInit, // +0x078; native 10002d20
    &UR6AbstractGameService::GetGSGameState, // +0x07c; native 10002ce0
    &UR6AbstractGameService::GetGroupID, // +0x080; native 10002cf0
    &AR6AbstractCorpse::FirstInit, // +0x084; native 10002d20
    &UR6AbstractGameService::Created, // +0x088; native 10002d40
  },
  .NativeSubmitMatchResult = &UR6AbstractGameService::Created, // +0x08c; native 10002d40
  .unresolvedAfterSubmit = {
    &UR6AbstractGameService::Created, // +0x090; native 10002d40
    &UR6AbstractGameService::CDKeyDisconnecUser, // +0x094; native 10002d00
    &AR6AbstractCorpse::AddImpulseToBone, // +0x098; native 100028d0
    &UR6AbstractGameService::MasterServerManager, // +0x09c; native 10002d30
    &UR6AbstractGameService::ProcessUbiComJoinServer, // +0x0a0; native 10002d10
    &AR6AbstractCorpse::FirstInit, // +0x0a4; native 10002d20
    &AR6AbstractCorpse::FirstInit, // +0x0a8; native 10002d20
    &AR6AbstractCorpse::FirstInit, // +0x0ac; native 10002d20
    &UR6AbstractGameService::MasterServerManager, // +0x0b0; native 10002d30
    &AR6AbstractCorpse::FirstInit, // +0x0b4; native 10002d20
    &UR6AbstractGameService::Created, // +0x0b8; native 10002d40
    &UR6AbstractGameService::Created, // +0x0bc; native 10002d40
    &UR6AbstractGameService::GetAuthID, // +0x0c0; native 10002d50
    &UR6AbstractGameService::GetGroupID, // +0x0c4; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x0c8; native 10002cf0
    &AR6AbstractCorpse::FirstInit, // +0x0cc; native 10002d20
    &UR6AbstractGameService::GetGSGameState, // +0x0d0; native 10002ce0
    &AR6AbstractCorpse::FirstInit, // +0x0d4; native 10002d20
    &UR6AbstractGameService::GetGroupID, // +0x0d8; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x0dc; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x0e0; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x0e4; native 10002cf0
    &AR6AbstractCorpse::FirstInit, // +0x0e8; native 10002d20
    &UR6AbstractGameService::GetGroupID, // +0x0ec; native 10002cf0
    &UR6AbstractGameService::GetGroupID, // +0x0f0; native 10002cf0
  },
};

// R6Abstract.dll data @ 1000d0cc : exported four-byte native member-function pointer
extern "C" ScriptNativeMethod intUR6AbstractGameServiceexecNativeSubmitMatchResult =
    (ScriptNativeMethod)&UR6AbstractGameService::execNativeSubmitMatchResult;
// R6Abstract.dll data @ 1000db38 : one-byte native-registration result, initially zero
uchar execNativeSubmitMatchResultRegistrationStatus = 0;

// R6Abstract.dll data @ 1000e048 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassUR6AbstractGameService = nullptr;

// R6Abstract.dll @ 10002c40 : return the UR6AbstractGameService class object
UClass *__cdecl UR6AbstractGameService::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002c50 : allocate UR6AbstractGameService using its class object and supplied object parameters
void *__cdecl UR6AbstractGameService::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                   ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10002c80 : destroy the object, its string members, and its base
void __thiscall UR6AbstractGameService::~UR6AbstractGameService(UR6AbstractGameService *this) {
  int destructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleUR6AbstractGameServiceDestructionFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const UR6AbstractGameServiceVTable **>(this) = &UR6AbstractGameService_vftable;
  destructionState = 1;
  UObject::ConditionalDestroy(this);
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szUserID); // +0x34.
  destructionState = -1;
  UObject::~UObject(this);
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 10002ce0 : uchar GetGSGameState(UR6AbstractGameService * this) Returns zero for the abstract
// game-service state accessors.
uchar __thiscall UR6AbstractGameService::GetGSGameState(UR6AbstractGameService *this) {
  return '\0';
}

// R6Abstract.dll @ 10002cf0 : return zero
int __thiscall UR6AbstractGameService::GetGroupID(UR6AbstractGameService *this) {
  return 0;
}

// R6Abstract.dll @ 10002d00 : void CDKeyDisconnecUser(UR6AbstractGameService * this, FString text) Destroys the
// by-value string argument on return.
void __thiscall UR6AbstractGameService::CDKeyDisconnecUser(UR6AbstractGameService *this, FString text) {
  return; // The by-value parameter destroys text once on return.
}

// R6Abstract.dll @ 10002d10 : void ProcessUbiComJoinServer(UR6AbstractGameService * this, int unusedInteger1, int
// unusedInteger2, FString text, float * unusedValues) Destroys the by-value string argument on return.
void __thiscall UR6AbstractGameService::ProcessUbiComJoinServer(UR6AbstractGameService *this, int unusedInteger1,
                                                                int unusedInteger2, FString text, float *unusedValues) {
  return; // The by-value parameter destroys text once on return.
}

// R6Abstract.dll @ 10002d30 : return without action
void __thiscall UR6AbstractGameService::MasterServerManager(UR6AbstractGameService *this,
                                                            AR6AbstractGameInfo *unusedGameInfo,
                                                            ALevelInfo *unusedLevelInfo) {
  return;
}

// R6Abstract.dll @ 10002d40 : return without action
void __thiscall UR6AbstractGameService::Created(UR6AbstractGameService *this) {
  return;
}

// R6Abstract.dll @ 10002d50 : construct the empty authentication string in hidden return storage Reference signature
// exposes the hidden output at entry ESP+4; the unused integer is at ESP+8. Native RET 8.
FString *__thiscall UR6AbstractGameService::GetAuthID(UR6AbstractGameService *this, FString *result, int unusedValue) {
  uint zeroedScratch = 0; // Native zero write to entry ESP-4 before the constructor call.
  ::new (result) FString(L"");
  return result;
}

// R6Abstract.dll @ 10002d80 : construct UObject and leave the user-ID string storage uninitialized
UR6AbstractGameService *__thiscall UR6AbstractGameService::UR6AbstractGameService(UR6AbstractGameService *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int constructionState;

  constructionState = -1;
  exceptionHandler = &HandleSharedUObjectLifetimeFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  UObject::UObject(this);
  constructionState = 0;
  *reinterpret_cast<const UR6AbstractGameServiceVTable **>(this) = &UR6AbstractGameService_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szUserID); // +0x34; no writes.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10002dd0 : copy-construct the base and reflected members
UR6AbstractGameService *__thiscall UR6AbstractGameService::UR6AbstractGameService(
    UR6AbstractGameService *this, const UR6AbstractGameService *source) {
  int constructionState = -1;
  NativeExceptionHandler exceptionHandler = &HandleSharedUObjectLifetimeFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((byte *)this + 0x2c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x2c);
  uint copiedFlags;

  UObject::UObject(this, source);
  *reinterpret_cast<const UR6AbstractGameServiceVTable **>(this) = &UR6AbstractGameService_vftable;
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bServerWaitMatchStartReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bClientWaitMatchStartReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bClientWillSubmitResult.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bWaitSubmitMatchReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bMSClientLobbyDisconnect.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bMSClientRouterDisconnect.
  *destinationFlags = copiedFlags;
  constructionState = 0;
  this->m_LocalPlayerController = source->m_LocalPlayerController; // +0x30, 4 bytes.
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szUserID,
                               (const FStringNoInit *)&source->m_szUserID); // +0x34.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Abstract.dll @ 10002e90 : assign the base, scalar fields, selected flags, and string members
UR6AbstractGameService *__thiscall UR6AbstractGameService::operator=(UR6AbstractGameService *this,
                                                                     const UR6AbstractGameService * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x2c);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x2c);
  uint copiedFlags;

  UObject::operator=(this, source);
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bServerWaitMatchStartReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bClientWaitMatchStartReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bClientWillSubmitResult.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bWaitSubmitMatchReply.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bMSClientLobbyDisconnect.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bMSClientRouterDisconnect.
  *destinationFlags = copiedFlags;
  this->m_LocalPlayerController = source->m_LocalPlayerController; // +0x30, 4 bytes.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szUserID,
                           (const FStringNoInit *)&source->m_szUserID); // +0x34.
  return this;
}

// R6Abstract.dll @ 10002f10 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall UR6AbstractGameService::VectorDeletingDestructor(UR6AbstractGameService *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x40, elementCount,
                                    (ArrayElementDestructor)&UR6AbstractGameService::~UR6AbstractGameService);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->UR6AbstractGameService::~UR6AbstractGameService();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x40);
  return this;
}

// R6Abstract.dll @ 100031c0 : construct UR6AbstractGameService in supplied memory when it is nonnull
void __cdecl UR6AbstractGameService::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) UR6AbstractGameService; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10003420 : execNativeSubmitMatchResult Consumes the terminator, optionally dispatches DebugInfo, and
// calls service slot +0x8c; native ABI is RET 8.
void __thiscall UR6AbstractGameService::execNativeSubmitMatchResult(UR6AbstractGameService *this, FFrame *stack,
                                                                    void *unusedResult) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  byte *&code = stack->Code; // FFrame +0x0c; alias preserves cursor reloads after native calls.
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleUR6AbstractGameServiceExecNativeSubmitMatchResultFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  ++code;
  if (*code == 0x42) { // Selected execDebugInfo opcode.
    ++code;
    reinterpret_cast<ScriptNative *>(GNatives_exref)[0x42](stack->Object, stack, nullptr);
  }
  this->NativeSubmitMatchResult(); // Virtual dispatch on this after bytecode evaluation.
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 1000348b : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardUR6AbstractGameServiceExecNativeSubmitMatchResultCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x14);
  *throwValue = *(ushort **)(parentFrame - 0x18);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 1000349f : report method context before forwarding the active exception
__declspec(noreturn) void ReportUR6AbstractGameServiceExecNativeSubmitMatchResultException(void) {
  appUnwindf((const ushort *)L"%s", L"UR6AbstractGameService::execNativeSubmitMatchResult");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 10004270 : destroy UObject during GameService destructor unwind parentFrame exposes inherited EBP,
// not a native stack argument.
void UnwindGameServiceDestructionBase(const byte *parentFrame) {
  UR6AbstractGameService *object = *(UR6AbstractGameService *const *)(parentFrame - 0x10);
  UObject::~UObject(object); // Native tail jump.
}

// R6Abstract.dll @ 10004279 : destroy UserID during GameService destructor unwind parentFrame exposes inherited EBP,
// not a native stack argument.
void UnwindGameServiceDestructionUserID(const byte *parentFrame) {
  UR6AbstractGameService *object = *(UR6AbstractGameService *const *)(parentFrame - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&object->m_szUserID); // Native tail jump.
}

// R6Abstract.dll @ 10004a30 : initialize UR6AbstractGameService class metadata and register its cleanup
void InitializeUR6AbstractGameServiceClassMetadata(void) {
  UClass *objectClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = UR6AbstractGameService::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&UR6AbstractGameService::PrivateStaticClass) UClass(EC_NativeConstructor, 0x40, 0x4, objectClass, objectClass,
      FGuid(0, 0, 0, 0), L"R6AbstractGameService", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyUR6AbstractGameServiceClassMetadata);
}

// R6Abstract.dll @ 10004ab0 : publish the class object through its exported autoclass pointer
void PublishUR6AbstractGameServiceClassMetadata(void) {
  autoclassUR6AbstractGameService = &UR6AbstractGameService::PrivateStaticClass;
}

// R6Abstract.dll @ 10004cb0 : destroy UR6AbstractGameService class metadata
void DestroyUR6AbstractGameServiceClassMetadata(void) {
  UR6AbstractGameService::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004ae0 : register the exported script-native descriptor and retain the byte result
void RegisterUR6AbstractGameServiceExecNativeSubmitMatchResult(void) {
  execNativeSubmitMatchResultRegistrationStatus =
      GRegisterNative(0x511, intUR6AbstractGameServiceexecNativeSubmitMatchResult);
}

// R6Abstract.dll @ 10004285 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleUR6AbstractGameServiceDestructionFrame(void) {
  __asm {
    mov eax, offset gameServiceDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 100042f0 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleUR6AbstractGameServiceExecNativeSubmitMatchResultFrame(void) {
  __asm {
    mov eax, offset gameServiceExecNativeSubmitMatchResultMetadata
    jmp __CxxFrameHandler
  }
}
