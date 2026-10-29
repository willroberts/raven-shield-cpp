// R6Weapons.dll label @ 100053c7 : embedded exception entry represented by the parent body
extern NativeCodeLabel runtimeInitializerExceptionFilter;
// R6Weapons.dll label @ 100053cb : embedded exception entry represented by the parent body
extern NativeCodeLabel runtimeInitializerExceptionHandler;
// R6Weapons.dll label @ 1000540b : embedded exception entry represented by the parent body
extern NativeCodeLabel runtimeTerminatorExceptionFilter;
// R6Weapons.dll label @ 1000540f : embedded exception entry represented by the parent body
extern NativeCodeLabel runtimeTerminatorExceptionHandler;

// R6Weapons.dll data @ 100077e4 : shared begin/end boundary of the empty runtime initializer range
// The native walker compares this address with itself; no callable slot is implied by the zero word.
const uint runtimeInitializerBoundary = 0;

// R6Weapons.dll data @ 100077ec : shared begin/end boundary of the empty runtime terminator range
// The native walker compares this address with itself; no callable slot is implied by the zero word.
const uint runtimeTerminatorBoundary = 0;

// R6Weapons.dll data @ 100076b8 : runtime initializer callback scope
// Words: signed enclosing scope (-1), filter entry (zero means finally), handler/finally entry.
const NativeSehScope runtimeInitializerScope = {
    .enclosingState = -1,
    .filter = &runtimeInitializerExceptionFilter,
    .handler = &runtimeInitializerExceptionHandler,
};

// R6Weapons.dll data @ 100076c8 : runtime terminator callback scope
// Words: signed enclosing scope (-1), filter entry (zero means finally), handler/finally entry.
const NativeSehScope runtimeTerminatorScope = {
    .enclosingState = -1,
    .filter = &runtimeTerminatorExceptionFilter,
    .handler = &runtimeTerminatorExceptionHandler,
};

// R6Weapons.dll @ 1000539a : visit the empty CRT callback range under its native SEH frame
// Installs/restores SEH even on the immediate empty exit; a callback exception would advance to the next slot.
__declspec(naked) void __RTC_Initialize(void) {
  __asm {
    push 0x0c
    push offset runtimeInitializerScope
    call __SEH_prolog
    mov dword ptr [ebp-0x1c], offset runtimeInitializerBoundary // Callback cursor.
  nextCallback:
    cmp dword ptr [ebp-0x1c], offset runtimeInitializerBoundary
    jae restoreFrame
    and dword ptr [ebp-0x4], 0 // Activate scope for the load and callback.
    mov eax, dword ptr [ebp-0x1c]
    mov eax, dword ptr [eax]
    test eax, eax
    je advanceCallback
    call eax
    jmp advanceCallback
  callbackFilter:
    xor eax, eax
    inc eax
    ret
  callbackHandler:
    mov esp, dword ptr [ebp-0x18]
  advanceCallback:
    or dword ptr [ebp-0x4], 0xffffffff
    add dword ptr [ebp-0x1c], 4
    jmp nextCallback
  restoreFrame:
    call __SEH_epilog
    ret
  }
}

// R6Weapons.dll @ 100053de : visit the empty CRT callback range under its native SEH frame
// Installs/restores SEH even on the immediate empty exit; a callback exception would advance to the next slot.
__declspec(naked) void RunCrtTerminationCallbacks(void) {
  __asm {
    push 0x0c
    push offset runtimeTerminatorScope
    call __SEH_prolog
    mov dword ptr [ebp-0x1c], offset runtimeTerminatorBoundary // Callback cursor.
  nextCallback:
    cmp dword ptr [ebp-0x1c], offset runtimeTerminatorBoundary
    jae restoreFrame
    and dword ptr [ebp-0x4], 0 // Activate scope for the load and callback.
    mov eax, dword ptr [ebp-0x1c]
    mov eax, dword ptr [eax]
    test eax, eax
    je advanceCallback
    call eax
    jmp advanceCallback
  callbackFilter:
    xor eax, eax
    inc eax
    ret
  callbackHandler:
    mov esp, dword ptr [ebp-0x18]
  advanceCallback:
    or dword ptr [ebp-0x4], 0xffffffff
    add dword ptr [ebp-0x1c], 4
    jmp nextCallback
  restoreFrame:
    call __SEH_epilog
    ret
  }
}
