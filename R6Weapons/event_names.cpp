// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006098 : Core.dll ??0FName@@QAE@PBGW4EFindName@@@Z
extern uint nameConstructorImport;

// R6Weapons.dll data @ 10007330 : UTF-16 native text
const char16_t eventNameInitializationContext[] = u"R6WeaponsInit";

// R6Weapons.dll data @ 1000734c : UTF-16 native text
const char16_t setGadgetStaticMeshEventText[] = u"SetGadgetStaticMesh";

// R6Weapons.dll data @ 10007374 : UTF-16 native text
const char16_t nbBulletChangeEventText[] = u"NbBulletChange";

// R6Weapons.dll data @ 10007394 : UTF-16 native text
const char16_t hideAttachmentEventText[] = u"HideAttachment";

// R6Weapons.dll data @ 10007e28 : eventNameInitialization unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry eventNameInitializationUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007e38 : eventNameInitialization typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry eventNameInitializationCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -28,
        .handler = &RethrowEventNameInitializationMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportEventNameInitializationException,
    },
};

// R6Weapons.dll data @ 10007e58 : eventNameInitialization protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry eventNameInitializationTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &eventNameInitializationCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007e6c : eventNameInitialization exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix eventNameInitializationFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &eventNameInitializationUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &eventNameInitializationTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// Exported four-byte event names have zero-initialized storage before native initialization.
// R6Weapons.dll data @ 1000c0d8 : R6WEAPONS_HideAttachment
FName R6WEAPONS_HideAttachment;
// R6Weapons.dll data @ 1000c0e8 : R6WEAPONS_NbBulletChange
FName R6WEAPONS_NbBulletChange;
// R6Weapons.dll data @ 1000c5f8 : R6WEAPONS_SetGadgetStaticMesh
FName R6WEAPONS_SetGadgetStaticMesh;

// R6Weapons.dll @ 10003e90 : initialize exported event names and return incoming ECX
// The parameter/return expose native register flow; no exported source signature establishes the original ABI.
uint __fastcall InitializeR6WeaponsEventNames(uint incomingECX) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchEventNameInitializationException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  using NameConstructor = FName *(__thiscall *)(FName *, const ushort *, EFindName);
  NameConstructor constructName =
      reinterpret_cast<NameConstructor>(nameConstructorImport); // Cached IAT target before state zero.
  uint temporaryNameWord; // One reused native scratch word; no default FName construction occurs.
  guardState = 0;
  FName *constructedName =
      constructName((FName *)&temporaryNameWord, (const ushort *)hideAttachmentEventText, (EFindName)2);
  *(uint *)&R6WEAPONS_HideAttachment = *(const uint *)constructedName;
  constructedName = constructName((FName *)&temporaryNameWord, (const ushort *)nbBulletChangeEventText, (EFindName)2);
  *(uint *)&R6WEAPONS_NbBulletChange = *(const uint *)constructedName;
  constructedName =
      constructName((FName *)&temporaryNameWord, (const ushort *)setGadgetStaticMeshEventText, (EFindName)2);
  const uint gadgetMeshName = *(const uint *)constructedName;
  void *restoredExceptionList = previousExceptionList;
  const uint result = incomingECX;
  *(uint *)&R6WEAPONS_SetGadgetStaticMesh = gadgetMeshName;
  ExceptionList = restoredExceptionList;
  return result;
}

// R6Weapons.dll @ 10003f0e : throw the unsigned-short message pointer caught by event-name initialization
// Copies the parent catch slot to its throw temporary; parentFrameEBP is inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowEventNameInitializationMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x1c);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003f22 : report event-name initialization context and rethrow
// Adds the exact R6WeaponsInit context, then rethrows with two null throw-helper arguments.
__declspec(noreturn) void ReportEventNameInitializationException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)eventNameInitializationContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100056b0 : dispatch event-name initialization exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchEventNameInitializationException(void) {
  __asm {
    mov eax, offset eventNameInitializationFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll data @ 1000cb24 : opaque receiver-storage interval preceding demolition metadata at +4
// These four initial bytes are zero; they do not establish a four-byte class layout or an original type name.
byte eventNameInitializationStorage[4] = {0, 0, 0, 0};

// R6Weapons.dll @ 10005cc0 : initialize event names with the fixed opaque receiver address in ECX
// This final CRT callback tail-jumps to the shared initialization body; its returned receiver value is ignored.
__declspec(naked) void InitializeR6WeaponsEventNameStorage(void) {
  __asm {
    mov ecx, offset eventNameInitializationStorage
    jmp InitializeR6WeaponsEventNames
  }
}
