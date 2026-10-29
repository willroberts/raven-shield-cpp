// R6Abstract.dll data @ 100073fc : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix eviLPatchServiceExecGetStateMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &eviLPatchServiceExecGetStateUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &eviLPatchServiceExecGetStateTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 100073e8 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry eviLPatchServiceExecGetStateTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &eviLPatchServiceExecGetStateCatchMap,
  },
};

// R6Abstract.dll data @ 100073c8 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry eviLPatchServiceExecGetStateCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -24,
    .handler = &ForwardUR6AbstractEviLPatchServiceExecGetStateCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportUR6AbstractEviLPatchServiceExecGetStateException,
  },
};

// R6Abstract.dll data @ 100073b8 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry eviLPatchServiceExecGetStateUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10010df0 : shared state-query callback, installed by SetFunctionPtr
ulong(__cdecl *getPatchStateCallback)(void) = nullptr;

// R6Abstract.dll data @ 10010df8 : zero-initialized exported class object, constructed by CRT startup
UClass UR6AbstractEviLPatchService::PrivateStaticClass;

// R6Abstract.dll data @ 100064c8 : UR6AbstractEviLPatchService virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const NativeUObjectVTable UR6AbstractEviLPatchService_vftable = {
  .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
  .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
  .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
  .VectorDeletingDestructor = &UR6AbstractEviLPatchService::VectorDeletingDestructor, // +0x00c; native 10002be0
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
};

// R6Abstract.dll data @ 1000d0c8 : exported four-byte native member-function pointer
extern "C" ScriptNativeMethod intUR6AbstractEviLPatchServiceexecGetState =
    (ScriptNativeMethod)&UR6AbstractEviLPatchService::execGetState;
// R6Abstract.dll data @ 1000e058 : one-byte native-registration result, initially zero
uchar execGetStateRegistrationStatus = 0;

// R6Abstract.dll data @ 10011300 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassUR6AbstractEviLPatchService = nullptr;

// R6Abstract.dll @ 10002b00 : return the UR6AbstractEviLPatchService class object
UClass *__cdecl UR6AbstractEviLPatchService::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002b10 : allocate UR6AbstractEviLPatchService using its class object and supplied object
// parameters
void *__cdecl UR6AbstractEviLPatchService::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                        ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10002b40 : conditionally shut down the object, then destroy its UObject base
void __thiscall UR6AbstractEviLPatchService::~UR6AbstractEviLPatchService(UR6AbstractEviLPatchService *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleSharedUObjectLifetimeFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const NativeUObjectVTable **>(this) = &UR6AbstractEviLPatchService_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  UObject::~UObject(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10002ba0 : construct UObject and install the UR6AbstractEviLPatchService vtable
UR6AbstractEviLPatchService::UR6AbstractEviLPatchService() : UObject() {
  // The constructor installs UR6AbstractEviLPatchService_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002bc0 : copy-construct from a const reference Copy-constructs through UObject and installs the
// UR6AbstractEviLPatchService vtable.
UR6AbstractEviLPatchService::UR6AbstractEviLPatchService(const UR6AbstractEviLPatchService &source) : UObject(source) {
  // The constructor installs UR6AbstractEviLPatchService_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10002be0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall UR6AbstractEviLPatchService::VectorDeletingDestructor(UR6AbstractEviLPatchService *this,
                                                                       uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x2c, elementCount,
                                    (ArrayElementDestructor)&UR6AbstractEviLPatchService::~UR6AbstractEviLPatchService);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->UR6AbstractEviLPatchService::~UR6AbstractEviLPatchService();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x2c);
  return this;
}

// R6Abstract.dll @ 100031b0 : construct UR6AbstractEviLPatchService in supplied memory when it is nonnull
void __cdecl UR6AbstractEviLPatchService::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) UR6AbstractEviLPatchService; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 10003780 : execGetState Consumes the terminator, optionally dispatches DebugInfo, and writes the
// callback result or zero. The package declares Byte, but native code writes four bytes to the result slot; preserve
// that width and RET 8.
void __thiscall UR6AbstractEviLPatchService::execGetState(UR6AbstractEviLPatchService *this, FFrame *stack,
                                                          void *result) {
  using ScriptNative = void(__thiscall *)(UObject *, FFrame *, void *);
  byte *&code = stack->Code; // FFrame +0x0c; alias preserves cursor reloads after native calls.
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleUR6AbstractEviLPatchServiceExecGetStateFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  ++code;
  if (*code == 0x42) { // Selected execDebugInfo opcode.
    ++code;
    reinterpret_cast<ScriptNative *>(GNatives_exref)[0x42](stack->Object, stack, nullptr);
  }
  using PatchStateCallback = ulong(__cdecl *)(void);
  PatchStateCallback getState = (PatchStateCallback)getPatchStateCallback;
  ulong callbackState = getState == nullptr ? 0 : getState();
  *(ulong *)result = callbackState; // Native write width is four bytes.
  ExceptionList = previousExceptionList;
}

// R6Abstract.dll @ 100037ef : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardUR6AbstractEviLPatchServiceExecGetStateCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x14);
  *throwValue = *(ushort **)(parentFrame - 0x18);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 10003803 : report method context before forwarding the active exception
__declspec(noreturn) void ReportUR6AbstractEviLPatchServiceExecGetStateException(void) {
  appUnwindf((const ushort *)L"%s", L"UR6AbstractEviLPatchService::execGetState");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 10003840 : store the cdecl state-query callback shared by patch-service instances
void __thiscall UR6AbstractEviLPatchService::SetFunctionPtr(UR6AbstractEviLPatchService *this,
                                                            ulong(__cdecl *callback)(void)) {
  getPatchStateCallback = callback;
  return;
}

// R6Abstract.dll @ 10004b70 : initialize UR6AbstractEviLPatchService class metadata and register its cleanup
void InitializeUR6AbstractEviLPatchServiceClassMetadata(void) {
  UClass *objectClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = UR6AbstractEviLPatchService::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&UR6AbstractEviLPatchService::PrivateStaticClass) UClass(EC_NativeConstructor, 0x2c, 0x0, objectClass,
      objectClass, FGuid(0, 0, 0, 0), L"R6AbstractEviLPatchService", GPackage, configName, objectFlags,
      classConstructor, classStaticConstructor);
  _atexit(DestroyUR6AbstractEviLPatchServiceClassMetadata);
}

// R6Abstract.dll @ 10004bf0 : publish the class object through its exported autoclass pointer
void PublishUR6AbstractEviLPatchServiceClassMetadata(void) {
  autoclassUR6AbstractEviLPatchService = &UR6AbstractEviLPatchService::PrivateStaticClass;
}

// R6Abstract.dll @ 10004cc0 : destroy UR6AbstractEviLPatchService class metadata
void DestroyUR6AbstractEviLPatchServiceClassMetadata(void) {
  UR6AbstractEviLPatchService::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}

// R6Abstract.dll @ 10004ac0 : register the exported script-native descriptor and retain the byte result
void RegisterUR6AbstractEviLPatchServiceExecGetState(void) {
  execGetStateRegistrationStatus = GRegisterNative(-1, intUR6AbstractEviLPatchServiceexecGetState);
}

// R6Abstract.dll @ 10004350 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleUR6AbstractEviLPatchServiceExecGetStateFrame(void) {
  __asm {
    mov eax, offset eviLPatchServiceExecGetStateMetadata
    jmp __CxxFrameHandler
  }
}
