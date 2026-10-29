// R6Abstract.dll data @ 1000e04c : exported four-byte event name, initially zero
FName R6ABSTRACT_R6MakeNoise;

// R6Abstract.dll data @ 1000ea78 : zero-initialized exported class object, constructed by CRT startup
UClass UR6AbstractNoiseMgr::PrivateStaticClass;

// R6Abstract.dll data @ 10006628 : UR6AbstractNoiseMgr virtual dispatch table
// Symbolic entries retain the selected PE32 targets; slot comments preserve their native identities.
const NativeUObjectVTable UR6AbstractNoiseMgr_vftable = {
  .QueryInterface = &ForwardCoreUObjectQueryInterface, // +0x000; native 10003894
  .AddRef = &ForwardCoreUObjectAddRef, // +0x004; native 1000388e
  .Release = &ForwardCoreUObjectRelease, // +0x008; native 10003888
  .VectorDeletingDestructor = &UR6AbstractNoiseMgr::VectorDeletingDestructor, // +0x00c; native 100030b0
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

// R6Abstract.dll data @ 1000e054 : exported class pointer, initially null before CRT startup
extern "C" UClass *autoclassUR6AbstractNoiseMgr = nullptr;

// R6Abstract.dll @ 10002f70 : void eventR6MakeNoise(UR6AbstractNoiseMgr * this, uchar eType, AActor * Source)
// Dispatches R6MakeNoise with eType at buffer +0 and Source at +4; untouched padding and RET 8 match native layout.
void __thiscall UR6AbstractNoiseMgr::eventR6MakeNoise(UR6AbstractNoiseMgr *this, uchar eType, AActor *Source) {
  struct {
    uchar eType;
    uchar paddingAfter_eType[3];
    AActor *Source;
  } parameters;
  const NativeUObjectVTable *vtable;
  UFunction *function;

  vtable = *reinterpret_cast<const NativeUObjectVTable *const *>(this);
  parameters.eType = eType;
  parameters.Source = Source;
  function = UObject::FindFunctionChecked(this, R6ABSTRACT_R6MakeNoise, 0);
  // The virtual dispatcher receives this in ECX.
  using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
  EventDispatcher processEvent = *reinterpret_cast<const EventDispatcher *>(&vtable->ProcessEvent);
  processEvent(this, function, &parameters, nullptr);
  return;
}

// R6Abstract.dll @ 10002fb0 : return the UR6AbstractNoiseMgr class object
UClass *__cdecl UR6AbstractNoiseMgr::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Abstract.dll @ 10002fc0 : allocate UR6AbstractNoiseMgr using its class object and supplied object parameters
void *__cdecl UR6AbstractNoiseMgr::operator_new(uint allocationSize, UObject *outer, FName objectName,
                                                ulong objectFlags) {
  // allocationSize is unused; allocation follows the class metadata size.
  FOutputDeviceError *error = *(FOutputDeviceError **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, 0, error, 0, 0);
}

// R6Abstract.dll @ 10002ff0 : conditionally shut down the object, then destroy its UObject base
void __thiscall UR6AbstractNoiseMgr::~UR6AbstractNoiseMgr(UR6AbstractNoiseMgr *this) {
  void *previousExceptionList;
  NativeExceptionHandler exceptionHandler;
  int destructionState = -1;

  exceptionHandler = &HandleSharedUObjectLifetimeFrame;
  previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *reinterpret_cast<const NativeUObjectVTable **>(this) = &UR6AbstractNoiseMgr_vftable;
  destructionState = 0;
  UObject::ConditionalDestroy(this);
  destructionState = -1;
  UObject::~UObject(this);
  ExceptionList = previousExceptionList;
  return;
}

// R6Abstract.dll @ 10003050 : construct UObject and install the UR6AbstractNoiseMgr vtable
UR6AbstractNoiseMgr::UR6AbstractNoiseMgr() : UObject() {
  // The constructor installs UR6AbstractNoiseMgr_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 10003070 : copy-construct from a const reference Copy-constructs through UObject and installs the
// UR6AbstractNoiseMgr vtable.
UR6AbstractNoiseMgr::UR6AbstractNoiseMgr(const UR6AbstractNoiseMgr &source) : UObject(source) {
  // The constructor installs UR6AbstractNoiseMgr_vftable after the base; native EAX returns this.
}

// R6Abstract.dll @ 100030b0 : destroy one object or an array and optionally release the allocation Compiler-generated
// vector deleting destructor at vtable +0x0c; source name is descriptive.
void *__thiscall UR6AbstractNoiseMgr::VectorDeletingDestructor(UR6AbstractNoiseMgr *this, uint deletionFlags) {
  if ((deletionFlags & 2) != 0) {
    byte *allocation = (byte *)this - 4;
    int elementCount = *(int *)allocation;
    _eh_vector_destructor_iterator_(this, 0x2c, elementCount,
                                    (ArrayElementDestructor)&UR6AbstractNoiseMgr::~UR6AbstractNoiseMgr);
    if ((deletionFlags & 1) != 0) {
      FMalloc *allocator = *(FMalloc **)GMalloc_exref;
      allocator->Free(allocation);
    }
    return allocation;
  }
  this->UR6AbstractNoiseMgr::~UR6AbstractNoiseMgr();
  if ((deletionFlags & 1) != 0)
    UObject::operator_delete(this, 0x2c);
  return this;
}

// R6Abstract.dll @ 100031d0 : construct UR6AbstractNoiseMgr in supplied memory when it is nonnull
void __cdecl UR6AbstractNoiseMgr::InternalConstructor(void *objectMemory) {
  if (objectMemory == nullptr) {
    return;
  }
  new (static_cast<EInternal *>(objectMemory)) UR6AbstractNoiseMgr; // Native tail jump to the constructor.
  return;
}

// R6Abstract.dll @ 100047c0 : initialize UR6AbstractNoiseMgr class metadata and register its cleanup
void InitializeUR6AbstractNoiseMgrClassMetadata(void) {
  UClass *objectClass = (UClass *)UObject_PrivateStaticClass_exref;
  void(__cdecl * classConstructor)(void *) = UR6AbstractNoiseMgr::InternalConstructor;
  void (UObject::*classStaticConstructor)() = &UObject::StaticConstructor;
  uint objectFlags = 0x4084004;
  const ushort *configName = UObject::StaticConfigName();
  ::new (&UR6AbstractNoiseMgr::PrivateStaticClass) UClass(EC_NativeConstructor, 0x2c, 0x0, objectClass, objectClass,
      FGuid(0, 0, 0, 0), L"R6AbstractNoiseMgr", GPackage, configName, objectFlags, classConstructor,
      classStaticConstructor);
  _atexit(DestroyUR6AbstractNoiseMgrClassMetadata);
}

// R6Abstract.dll @ 10004840 : publish the class object through its exported autoclass pointer
void PublishUR6AbstractNoiseMgrClassMetadata(void) {
  autoclassUR6AbstractNoiseMgr = &UR6AbstractNoiseMgr::PrivateStaticClass;
}

// R6Abstract.dll @ 10004c70 : destroy UR6AbstractNoiseMgr class metadata
void DestroyUR6AbstractNoiseMgrClassMetadata(void) {
  UR6AbstractNoiseMgr::PrivateStaticClass.UClass::~UClass(); // Native tail jump.
}
