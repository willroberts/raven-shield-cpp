// R6Weapons.dll label @ 100050c5 : embedded exception entry represented by the parent body
extern NativeCodeLabel arrayUnwindCppExceptionFilter;
// R6Weapons.dll label @ 100050e9 : embedded exception entry represented by the parent body
extern NativeCodeLabel arrayUnwindExceptionHandler;

// R6Weapons.dll data @ 10007688 : array-unwind C++ exception filter scope
// Words: signed enclosing scope (-1), filter entry (zero means finally), handler/finally entry.
const NativeSehScope arrayUnwindScope = {
    .enclosingState = -1,
    .filter = &arrayUnwindCppExceptionFilter,
    .handler = &arrayUnwindExceptionHandler,
};

// R6Weapons.dll data @ 10007698 : array-iterator finally scope
// Words: signed enclosing scope (-1), filter entry (zero means finally), handler/finally entry.
const NativeSehScope arrayDestructorIteratorScope = {
    .enclosingState = -1,
    .filter = 0x00000000,
    .handler = &UnwindArrayDestructorIterator,
};

using ArrayElementDestructor = void(__thiscall *)(void *);

// R6Weapons.dll @ 10005096 : destroy earlier array elements while unwinding a failed destructor
// Uses wrapped 32-bit cursor/count arithmetic; a further C++ exception terminates, while other SEH exceptions search
// on.
void __stdcall __ArrayUnwind(void *elementCursor, uint elementSize, int remainingCount,
                             ArrayElementDestructor destroyElement) {
  // Native filter 0x100050c5 reads the exception pointers from inherited EBP-0x14.
  auto terminateOnCppException = [](EXCEPTION_POINTERS *exceptionPointers) -> int {
    EXCEPTION_POINTERS *exceptionInfo = exceptionPointers;              // Parent temporary EBP-0x1c.
    EXCEPTION_RECORD *exceptionRecord = exceptionInfo->ExceptionRecord; // Parent temporary EBP-0x20.
    if (exceptionRecord->ExceptionCode == 0xe06d7363)
      terminate();        // Native shared filter tail at 0x100050ee.
    int filterResult = 0; // Parent temporary EBP-0x24: EXCEPTION_CONTINUE_SEARCH.
    return filterResult;
  };
  __try {
    for (;;) {
      remainingCount = (int)((uint)remainingCount - 1);
      if (remainingCount < 0)
        break;
      elementCursor = (void *)((uint)elementCursor - elementSize);
      destroyElement(elementCursor);
    }
  } __except (terminateOnCppException(GetExceptionInformation())) {
    // Native 0x100050e9 restores the saved ESP and joins the common epilogue; the filter never selects this handler.
  }
}

// R6Weapons.dll @ 1000513c : destroy remaining earlier elements unless reverse array destruction completed
// References expose parent EBP-0x1c and EBP+8/+0xc/+0x10/+0x14, not native stack arguments to this funclet.
void UnwindArrayDestructorIterator(int &completed, void *&elementCursor, uint &elementSize, int &remainingCount,
                                   ArrayElementDestructor &destroyElement) {
  if (completed == 0)
    __ArrayUnwind(elementCursor, elementSize, remainingCount, destroyElement);
}

// R6Weapons.dll @ 100050f4 : destroy a counted array in reverse order and unwind earlier elements on failure
// Updates the live cursor/count before each thiscall destructor; the finally path skips cleanup after normal
// completion.
void __stdcall _eh_vector_destructor_iterator_(void *elementCursor, uint elementSize, int remainingCount,
                                               ArrayElementDestructor destroyElement) {
  int completed = 0;
  const uint retainedElementSize = elementSize; // Native ESI is retained across destructor calls.
  elementCursor = (void *)((uint)elementCursor + retainedElementSize * (uint)remainingCount);
  __try {
    for (;;) {
      remainingCount = (int)((uint)remainingCount - 1);
      if (remainingCount < 0)
        break;
      elementCursor = (void *)((uint)elementCursor - retainedElementSize);
      destroyElement(elementCursor);
    }
    completed = 1;
  } __finally {
    UnwindArrayDestructorIterator(completed, elementCursor, elementSize, remainingCount, destroyElement);
  }
}
