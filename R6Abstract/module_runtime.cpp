// Descriptive aliases for existing four-byte PE32 IAT slots, not additional globals or provider signatures.
// R6Abstract.dll import @ 100053cc : MSVCR71.dll __CxxFrameHandler
extern void *crtCxxFrameHandlerImport;
// R6Abstract.dll import @ 100053d0 : MSVCR71.dll _CxxThrowException
extern void *crtCxxThrowExceptionImport;
// R6Abstract.dll import @ 100053d8 : MSVCR71.dll ?terminate@@YAXXZ
extern void *crtTerminateImport;
// R6Abstract.dll import @ 100053dc : MSVCR71.dll _except_handler3
extern void *crtExceptHandlerImport;
// R6Abstract.dll import @ 100053e0 : MSVCR71.dll __dllonexit
extern void *crtDllOnExitImport;
// R6Abstract.dll import @ 100053ec : MSVCR71.dll _initterm
extern void *crtInitTermImport;
// R6Abstract.dll import @ 100053f8 : MSVCR71.dll __CppXcptFilter
extern void *crtCppExceptionFilterImport;

// Named labels identify embedded exception code already represented by the parent __except blocks.
// They are not separate functions, storage objects or additional native bodies.
struct NativeCodeLabel;
// R6Abstract.dll label @ 10003cd5 : embedded exception entry
extern NativeCodeLabel arrayUnwindCppExceptionFilter;
// R6Abstract.dll label @ 10003cf9 : embedded exception entry
extern NativeCodeLabel arrayUnwindExceptionHandler;
// R6Abstract.dll label @ 10003f1c : embedded exception entry
extern NativeCodeLabel dllCrtEntryExceptionFilter;
// R6Abstract.dll label @ 10003f2d : embedded exception entry
extern NativeCodeLabel dllCrtEntryExceptionHandler;
// R6Abstract.dll label @ 10003fd7 : embedded exception entry
extern NativeCodeLabel runtimeInitializerExceptionFilter;
// R6Abstract.dll label @ 10003fdb : embedded exception entry
extern NativeCodeLabel runtimeInitializerExceptionHandler;
// R6Abstract.dll label @ 1000401b : embedded exception entry
extern NativeCodeLabel runtimeTerminatorExceptionFilter;
// R6Abstract.dll label @ 1000401f : embedded exception entry
extern NativeCodeLabel runtimeTerminatorExceptionHandler;

using RuntimeCallback = void(__cdecl *)(void);
// R6Abstract.dll boundary @ 10006cd4 : empty CRT callback range; begin equals end
extern RuntimeCallback runtimeInitializerBoundary[];
// R6Abstract.dll boundary @ 10006cdc : empty CRT callback range; begin equals end
extern RuntimeCallback runtimeTerminatorBoundary[];

// R6Abstract.dll data @ 10007324 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix eventNameInitializationMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000002,
  .unwindMap = &eventNameInitializationUnwindMap,
  .tryCount = 0x00000001,
  .tryMap = &eventNameInitializationTryMap,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 10007310 : C++ try entries: low/high/catch-high states, handler count/map
const NativeCxxTryEntry eventNameInitializationTryMap[1] = {
  {
    .lowState = 0x00000000,
    .highState = 0x00000000,
    .catchHighState = 0x00000001,
    .handlerCount = 0x00000002,
    .handlers = &eventNameInitializationCatchMap,
  },
};

// R6Abstract.dll data @ 100072f0 : C++ catch entries: attributes, type descriptor, frame displacement, handler code
const NativeCxxCatchEntry eventNameInitializationCatchMap[2] = {
  {
    .attributes = 0x00000000,
    .typeDescriptor = &wideStringPointerTypeDescriptor,
    .frameDisplacement = -28,
    .handler = &ForwardR6AbstractEventNameInitializationCaughtWideString,
  },
  {
    .attributes = 0x00000000,
    .typeDescriptor = 0x00000000,
    .frameDisplacement = 0x00000000,
    .handler = &ReportR6AbstractEventNameInitializationException,
  },
};

// R6Abstract.dll data @ 100072e0 : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry eventNameInitializationUnwindMap[2] = {
  {.previousState = -1, .cleanup = 0x00000000},
  {.previousState = -1, .cleanup = 0x00000000},
};

// R6Abstract.dll data @ 10006bc8 : SEH scope: enclosing state, filter, handler/finally entry
const NativeSehScope runtimeTerminatorScope = {
  .enclosingState = -1,
  .filter = &runtimeTerminatorExceptionFilter,
  .handler = &runtimeTerminatorExceptionHandler,
};

// R6Abstract.dll data @ 10006bb8 : SEH scope: enclosing state, filter, handler/finally entry
const NativeSehScope runtimeInitializerScope = {
  .enclosingState = -1,
  .filter = &runtimeInitializerExceptionFilter,
  .handler = &runtimeInitializerExceptionHandler,
};

// R6Abstract.dll data @ 10006ba8 : SEH scope: enclosing state, filter, handler/finally entry
const NativeSehScope dllCrtEntryScope = {
  .enclosingState = -1,
  .filter = &dllCrtEntryExceptionFilter,
  .handler = &dllCrtEntryExceptionHandler,
};

// R6Abstract.dll data @ 10006b98 : SEH scope: enclosing state, filter, handler/finally entry
const NativeSehScope arrayDestructorIteratorScope = {
  .enclosingState = -1,
  .filter = 0x00000000,
  .handler = &UnwindArrayDestructorIterator,
};

// R6Abstract.dll data @ 10006b88 : SEH scope: enclosing state, filter, handler/finally entry
const NativeSehScope arrayUnwindScope = {
  .enclosingState = -1,
  .filter = &arrayUnwindCppExceptionFilter,
  .handler = &arrayUnwindExceptionHandler,
};

using ArrayElementDestructor = void(__thiscall *)(void *);

// R6Abstract.dll @ 100012a0 : release a memory block through the global allocator
void __cdecl FreeThroughGlobalAllocator(void *memory) {
  FMalloc *allocator = *(FMalloc **)GMalloc_exref;
  allocator->Free(memory);
}

// R6Abstract.dll @ 10003400 : store the module handle and report successful DLL notification
int __stdcall _DllMain_12(void *moduleHandle, uint reason, void *reserved) {
  r6AbstractModuleHandle = moduleHandle;
  return 1;
}

// R6Abstract.dll @ 100034c0 : initialize exported event names and return the incoming ECX word
uint __fastcall InitializeR6AbstractEventNames(uint incomingECX) {
  uint temporaryNameWord; // Single uninitialized FName storage word at native
                          // EBP-0x18.
  FName *temporaryName = (FName *)&temporaryNameWord;
  int guardState = -1;
  NativeExceptionHandler exceptionHandler = &HandleR6AbstractEventNameInitializationFrame;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  FName *constructedName = FName::FName(temporaryName, (const ushort *)L"R6MakeNoise", 2);
  *(uint *)&R6ABSTRACT_R6MakeNoise = *(uint *)constructedName;
  constructedName = FName::FName(temporaryName, (const ushort *)L"GetSkill", 2);
  *(uint *)&R6ABSTRACT_GetSkill = *(uint *)constructedName;
  constructedName = FName::FName(temporaryName, (const ushort *)L"SpawnSelectedGadget", 2);
  *(uint *)&R6ABSTRACT_SpawnSelectedGadget = *(uint *)constructedName;
  ExceptionList = previousExceptionList;
  return incomingECX;
}

// R6Abstract.dll @ 1000353e : forward the caught wide-string pointer through the typed throw helper parentFrame exposes
// inherited EBP, not a native stack argument.
__declspec(noreturn) void ForwardR6AbstractEventNameInitializationCaughtWideString(byte *parentFrame) {
  ushort **throwValue = (ushort **)(parentFrame - 0x14);
  *throwValue = *(ushort **)(parentFrame - 0x1c);
  _CxxThrowException(throwValue, (ThrowInfo *)&wideStringPointerThrowInfo);
}

// R6Abstract.dll @ 10003552 : report method context before forwarding the active exception
__declspec(noreturn) void ReportR6AbstractEventNameInitializationException(void) {
  appUnwindf((const ushort *)L"%s", L"R6AbstractInit");
  _CxxThrowException(nullptr, nullptr);
}

// R6Abstract.dll @ 10003c8e : forward the current C++ exception frame without changing registers or stack
__declspec(naked) void __CxxFrameHandler(void) {
  __asm {
    jmp dword ptr [crtCxxFrameHandlerImport]
  }
}

// R6Abstract.dll @ 10003ca0 : forward exception object/type arguments unchanged to the imported throw routine
__declspec(naked) __declspec(noreturn) void _CxxThrowException(void *exceptionObject, ThrowInfo *throwInfo) {
  __asm {
    jmp dword ptr [crtCxxThrowExceptionImport]
  }
}

// R6Abstract.dll @ 10003ca6 : destroy preceding array elements and terminate on a second C++ exception
void __stdcall __ArrayUnwind(void *elementCursor, uint elementSize, int remainingCount,
                             ArrayElementDestructor destroyElement) {
  __try {
    while (true) {
      remainingCount = (int)((uint)remainingCount - 1);
      if (remainingCount < 0)
        break;
      elementCursor = (void *)((uint)elementCursor - elementSize);
      destroyElement(elementCursor); // Native callback receiver is ECX.
    }
  }
  // Filter 0x10003cd5: other SEH codes continue searching; the C++ code invokes terminate at 0x10003cfe.
  __except (GetExceptionCode() == 0xe06d7363 ? (terminate(), 0) : 0) {
    // Native handler 0x10003cf9 restores ESP and resumes the normal epilogue if selected.
  }
}

// R6Abstract.dll @ 10003d04 : destroy array elements backward and unwind remaining elements on failure
void __stdcall _eh_vector_destructor_iterator_(void *elementCursor, uint elementSize, int remainingCount,
                                               ArrayElementDestructor destroyElement) {
  int completed = 0; // Native parent EBP-0x1c.
  elementCursor = (void *)((uint)elementCursor + elementSize * (uint)remainingCount);
  __try {
    while (true) {
      remainingCount = (int)((uint)remainingCount - 1);
      if (remainingCount < 0)
        break;
      elementCursor = (void *)((uint)elementCursor - elementSize);
      destroyElement(elementCursor); // Native callback receiver is ECX.
    }
    completed = 1;
  } __finally {
    UnwindArrayDestructorIterator(completed, elementCursor, elementSize, remainingCount, destroyElement);
  }
}

// R6Abstract.dll @ 10003d4c : unwind the remaining array only when destruction has not completed Parameters expose
// inherited parent fields: -0x1c, +8, +0xc, +0x10, +0x14; no native arguments are added.
void UnwindArrayDestructorIterator(int completed, void *elementCursor, uint elementSize, int remainingCount,
                                   ArrayElementDestructor destroyElement) {
  if (completed == 0)
    __ArrayUnwind(elementCursor, elementSize, remainingCount, destroyElement);
}

// R6Abstract.dll @ 10003d64 : register an exit callback using the selected CRT table
_onexit_t __cdecl __onexit(_onexit_t callback) {
  if ((uint)exitCallbacksBegin == 0xffffffff) {
    return _onexit(callback);
  }
  return __dllonexit(callback, (_onexit_t **)&exitCallbacksBegin, (_onexit_t **)&exitCallbacksEnd);
}

// R6Abstract.dll @ 10003d8a : register an exit callback and report zero on success
int __cdecl _atexit(void(__cdecl *callback)(void)) {
  _onexit_t registeredCallback = __onexit((_onexit_t)callback);
  return registeredCallback != nullptr ? 0 : -1;
}

// R6Abstract.dll @ 10003d9c : initialize or tear down the DLL CRT callback state for the notification
int __stdcall __CRT_INIT_12(void *unusedModuleHandle, uint reason, void *unusedReserved) {
  using ExitCallback = void(__cdecl *)(void);
  if (reason == 0) {
    if (crtAttachCount <= 0) {
      return 0;
    }
    --crtAttachCount;
  }
  adjustFdivSnapshot = *(uint *)_adjust_fdiv_exref;
  if (reason == 1) {
    exitCallbacksBegin = (ExitCallback *)malloc(0x80);
    if (exitCallbacksBegin == nullptr) {
      return 0;
    }
    *((ExitCallback *)exitCallbacksBegin) = nullptr;
    exitCallbacksEnd = exitCallbacksBegin;
    __RTC_Initialize();
    _atexit(RunCrtTerminationCallbacks);
    initterm(crtInitializers, crtInitializers + 33);
    crtAttachCount = (int)((uint)crtAttachCount + 1);
  } else if (reason == 0 && exitCallbacksBegin != nullptr) {
    ExitCallback *tableBase = (ExitCallback *)exitCallbacksBegin;
    for (;;) {
      exitCallbacksEnd = (ExitCallback *)((uint)exitCallbacksEnd - 4);
      if ((uint)exitCallbacksEnd < (uint)tableBase) {
        break;
      }
      ExitCallback callback = *((ExitCallback *)exitCallbacksEnd);
      if (callback != nullptr) {
        callback();
        tableBase = (ExitCallback *)exitCallbacksBegin;
      }
    }
    free(tableBase);
    exitCallbacksBegin = nullptr;
  }
  return 1;
}

// R6Abstract.dll @ 10003e5a : order the raw hook, CRT notifications, and DLL callback under the CRT exception filter
int __stdcall DllCrtEntry(void *moduleHandle, uint reason, void *reserved) {
  using NotificationHook = int(__stdcall *)(void *, uint, void *);
  int notificationResult = 1;
  __try {
    if (reason == 0 && crtAttachCount == 0) {
      return 0;
    }
    if (reason == 1 || reason == 2) {
      NotificationHook rawHook = (NotificationHook)rawDllNotificationHook;
      if (rawHook != nullptr) {
        notificationResult = rawHook(moduleHandle, reason, reserved);
      }
      if (notificationResult == 0) {
        return 0;
      }
      notificationResult = __CRT_INIT_12(moduleHandle, reason, reserved);
      if (notificationResult == 0) {
        return 0;
      }
    }
    notificationResult = _DllMain_12(moduleHandle, reason, reserved);
    if (reason == 1 && notificationResult == 0) {
      __CRT_INIT_12(moduleHandle, 0, reserved);
    }
    if (reason == 0 || reason == 3) {
      if (__CRT_INIT_12(moduleHandle, reason, reserved) == 0) {
        notificationResult = 0;
      }
      if (notificationResult != 0) {
        NotificationHook rawHook = (NotificationHook)rawDllNotificationHook;
        if (rawHook != nullptr) {
          notificationResult = rawHook(moduleHandle, reason, reserved);
        }
      }
    }
    return notificationResult;
  } __except (__CppXcptFilter(GetExceptionCode(), GetExceptionInformation())) {
    return 0;
  }
}

// R6Abstract.dll @ 10003f44 : terminate through the imported CRT routine without changing its incoming state
__declspec(naked) __declspec(noreturn) void __cdecl terminate(void) {
  __asm {
    jmp dword ptr [crtTerminateImport]
  }
}

// R6Abstract.dll @ 10003f4c : Installs the caller's SEH record and saves its frame and nonvolatile registers.
__declspec(naked) void __SEH_prolog(void) {
  __asm {
    push offset ForwardSehExceptionHandler // Local thunk to imported _except_handler3.
    mov eax,fs:[0]
    push eax
    mov eax,dword ptr [esp+0x10]
    mov dword ptr [esp+0x10],ebp
    lea ebp,[esp+0x10]
    sub esp,eax
    push ebx
    push esi
    push edi
    mov eax,dword ptr [ebp-0x8]
    mov dword ptr [ebp-0x18],esp
    push eax
    mov eax,dword ptr [ebp-0x4]
    mov dword ptr [ebp-0x4],0xffffffff
    mov dword ptr [ebp-0x8],eax
    lea eax,[ebp-0x10]
    mov fs:[0],eax
    ret
  }
}

// R6Abstract.dll @ 10003f87 : Restores the enclosing SEH chain, saved registers, frame, and continuation.
__declspec(naked) void __SEH_epilog(void) {
  __asm {
    mov ecx,dword ptr [ebp-0x10]
    mov dword ptr fs:[0],ecx
    pop ecx
    pop edi
    pop esi
    pop ebx
    leave
    push ecx
    ret
  }
}

// R6Abstract.dll @ 10003f98 : forward the SEH record to imported _except_handler3 with registers/stack unchanged
__declspec(naked) void ForwardSehExceptionHandler(void) {
  __asm {
    jmp dword ptr [crtExceptHandlerImport]
  }
}

// R6Abstract.dll @ 10003f9e : forward the callback and mutable table bounds to imported __dllonexit
__declspec(naked) _onexit_t __cdecl __dllonexit(_onexit_t callback, _onexit_t **begin, _onexit_t **end) {
  __asm {
    jmp dword ptr [crtDllOnExitImport]
  }
}

// R6Abstract.dll @ 10003fa4 : forward the initializer callback range to imported _initterm
__declspec(naked) void __cdecl initterm(void(__cdecl **begin)(void), void(__cdecl **end)(void)) {
  __asm {
    jmp dword ptr [crtInitTermImport]
  }
}

// R6Abstract.dll @ 10003faa : visit the selected empty runtime-initializer range, handling callback exceptions
void __RTC_Initialize(void) {
  using RuntimeCallback = void(__cdecl *)(void);
  for (RuntimeCallback *callbackCursor = runtimeInitializerBoundary;
       (uint)callbackCursor < (uint)runtimeInitializerBoundary;
       callbackCursor = (RuntimeCallback *)((uint)callbackCursor + 4)) {
    __try {
      if (*callbackCursor != nullptr)
        (*callbackCursor)();
    } __except (1) {
      // Filter 0x10003fd7 selects handler 0x10003fdb, then iteration resumes at the next word.
    }
  }
}

// R6Abstract.dll @ 10003fee : visit the selected empty runtime-termination range, handling callback exceptions
void RunCrtTerminationCallbacks(void) {
  using RuntimeCallback = void(__cdecl *)(void);
  for (RuntimeCallback *callbackCursor = runtimeTerminatorBoundary;
       (uint)callbackCursor < (uint)runtimeTerminatorBoundary;
       callbackCursor = (RuntimeCallback *)((uint)callbackCursor + 4)) {
    __try {
      if (*callbackCursor != nullptr)
        (*callbackCursor)();
    } __except (1) {
      // Filter 0x1000401b selects handler 0x1000401f, then iteration resumes at the next word.
    }
  }
}

// R6Abstract.dll @ 10004032 : forward the exception code and pointers to the imported CRT entry filter
__declspec(naked) int __cdecl __CppXcptFilter(ulong exceptionCode, _EXCEPTION_POINTERS *exceptionPointers) {
  __asm {
    jmp dword ptr [crtCppExceptionFilterImport]
  }
}

// R6Abstract.dll @ 10004b60 : initialize event names with the fixed startup ECX word
// The relocated address lies in zero-filled .data; its storage role and original identity remain unresolved.
// The callee only saves and returns this word, so no object declaration or receiver type is supported.
// See notes/R6Abstract/final-semantic-review.md for the remaining address question.
uint __cdecl InitializeR6AbstractEventNamesAtStartup(void) {
  return InitializeR6AbstractEventNames(0x1000f990); // Native tail jump; the incoming word is returned unchanged.
}

// R6Abstract.dll @ 10004300 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleR6AbstractEventNameInitializationFrame(void) {
  __asm {
    mov eax, offset eventNameInitializationMetadata
    jmp __CxxFrameHandler
  }
}
