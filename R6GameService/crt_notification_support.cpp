#include "native_addresses.h"
#include "native_records.h"

// Native DLL CRT setup and stack protocols; imported CRT/Windows policies remain separate.
// R6GameService.dll data @ 10093d1c : native storage identity retained.
int GCrtAttachCount = 0;
// R6GameService.dll data @ 100945b4 : native storage identity retained.
uint GAdjustFdivSnapshot = 0;
// R6GameService.dll data @ 100945b8 : native storage identity retained.
uint GRawDllNotificationHook = 0;
// R6GameService.dll data @ 100945bc : native storage identity retained.
uint GExitCallbacksEnd = 0;
// R6GameService.dll data @ 100945c0 : native storage identity retained.
uint GExitCallbacksBegin = 0;
// Exact one-record SEH scope; selected .data zero-fill establishes initial state-word zeros above.
// R6GameService.dll data @ 100770b0 : native storage identity retained.
const R6GameServiceNative::SehScope GCrtDllNotificationScope[1] = {
  {-1, R6GameServiceAddresses::FilterCrtDllNotificationException,
  R6GameServiceAddresses::ResumeFailedCrtDllNotification},
};

// Registers a callback through _onexit or the current DLL callback-table pair.
// R6GameService.dll @ 10033a34 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl __onexit(void *callback)
{
  __asm {
    // Only begin==FFFFFFFF selects process _onexit tail. Otherwise pass callback and addresses of begin/end bindings.
    cmp    DWORD PTR [GExitCallbacksBegin],0xffffffff
    jne    Branch1
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__onexitSlot
  Branch1:
    push   offset GExitCallbacksEnd
    push   offset GExitCallbacksBegin
    push   DWORD PTR [esp+0xc]
    call   R6GameServiceAddresses::__dllonexit
    add    esp,0xc
    ret
  }
}

// Maps nonnull callback registration to zero and null registration to minus one, retaining stack scratch effects.
// R6GameService.dll @ 10033a5a : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl _atexit(void (__cdecl *callback)(void))
{
  __asm {
    // NEG/SBB/NEG/DEC maps raw pointer nonzero to0, zero toFFFFFFFF. POP ECX exposes copied callback argument.
    push   DWORD PTR [esp+0x4]
    call   R6GameServiceAddresses::__onexit
    neg    eax
    sbb    eax,eax
    neg    eax
    pop    ecx
    dec    eax
    ret
  }
}

// Probes requested stack storage page by page and resumes the caller with adjusted ESP and preserved ECX.
// R6GameService.dll @ 10033ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __chkstk(void)
{
  __asm {
    // Special EAX-byte-count protocol, not ordinary cdecl: return ESP=entryESP+4-count, ECX preserved, EAX=continuation.
    cmp    eax,0x1000
    jae    Branch2
    neg    eax
    add    eax,esp
    add    eax,0x4
    // Small count probes final DWORD even for count0, before ESP changes. Do not replace with ordinary alloca.
    test   DWORD PTR [eax],eax
    xchg   esp,eax
    mov    eax,DWORD PTR [eax]
    push   eax
    ret
  Branch2:
    // Save ECX, probe descending 0x1000 steps, then final remainder; exact multiples probe their last address twice.
    push   ecx
    lea    ecx,[esp+0x8]
  Branch3:
    sub    ecx,0x1000
    sub    eax,0x1000
    test   DWORD PTR [ecx],eax
    cmp    eax,0x1000
    jae    Branch3
    sub    ecx,eax
    // Final probe precedes changing ESP. Recover saved ECX and original continuation through prior stack pointer.
    mov    eax,esp
    test   DWORD PTR [ecx],eax
    mov    esp,ecx
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    push   eax
    ret
  }
}

// Initializes or tears down native DLL CRT callback state while preserving raw table and notification behavior.
// R6GameService.dll @ 10033aed : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall __CRT_INIT_12(void *module,uint reason,void *reserved)
{
  __asm {
    // Cache reason in EAX; process detach uses signed attachCount<=0 early gate, before adjust-fdiv snapshot.
    mov    eax,DWORD PTR [esp+0x8]
    test   eax,eax
    jne    Branch4
    cmp    DWORD PTR [GCrtAttachCount],eax
    jle    Branch5
    dec    DWORD PTR [GCrtAttachCount]
  Branch4:
    // Every accepted reason dereferences imported _adjust_fdiv slot and stores snapshot, including unknown reasons.
    cmp    eax,0x1
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCR71__adjust_fdivSlot
    mov    ecx,DWORD PTR [ecx]
    mov    DWORD PTR [GAdjustFdivSnapshot],ecx
    jne    Branch7
    push   0x80
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_mallocSlot
    test   eax,eax
    pop    ecx
    mov    [GExitCallbacksBegin],eax
    jne    Branch6
  Branch5:
    xor    eax,eax
    jmp    Branch12
  Branch6:
    // Publish callback allocation before initial zero entry/end. RTC init and atexit result are not checked.
    and    DWORD PTR [eax],0x0
    mov    eax,[GExitCallbacksBegin]
    mov    [GExitCallbacksEnd],eax
    call   R6GameServiceAddresses::__RTC_Initialize
    push   R6GameServiceAddresses::RunCrtTerminationCallbacks
    call   R6GameServiceAddresses::_atexit
    // Reuse pending callback argument word as initializer-end scratch, increment current attach count only after initterm.
    mov    DWORD PTR [esp],0x1008c148
    push   0x1008c000
    call   R6GameServiceAddresses::initterm
    inc    DWORD PTR [GCrtAttachCount]
    pop    ecx
    jmp    Branch10
  Branch7:
    test   eax,eax
    jne    Branch11
    mov    eax,[GExitCallbacksBegin]
    test   eax,eax
    je     Branch11
    jmp    Branch9
  Branch8:
    // Read current end entry; after nonnull callback only, reload current begin into cached EAX for following gate/free.
    mov    ecx,DWORD PTR [GExitCallbacksEnd]
    mov    ecx,DWORD PTR [ecx]
    test   ecx,ecx
    je     Branch9
    call   ecx
    mov    eax,[GExitCallbacksBegin]
  Branch9:
    // Predecrement global end each pass; compare against cached begin as unsigned. End remains stale after free.
    sub    DWORD PTR [GExitCallbacksEnd],0x4
    cmp    DWORD PTR [GExitCallbacksEnd],eax
    jae    Branch8
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    and    DWORD PTR [GExitCallbacksBegin],0x0
  Branch10:
    // Pop outstanding argument into ECX; success EAX1 ignores free/atexit/raw callback residue.
    pop    ecx
  Branch11:
    xor    eax,eax
    inc    eax
  Branch12:
    ret    0xc
  }
}

// Orders the raw notification hook, CRT initialization and DLL callback under the native CRT exception filter.
// R6GameService.dll @ 10033bab : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall entry(void *module,uint reason,void *reserved)
{
  __asm {
    // Actual SEHprolog locals0c/scope770b0; original reason caches ESI, reserved loads later into EBX.
    push   0xc
    push   offset GCrtDllNotificationScope
    call   R6GameServiceAddresses::__SEH_prolog
    xor    eax,eax
    inc    eax
    mov    DWORD PTR [ebp-0x1c],eax
    xor    edi,edi
    mov    DWORD PTR [ebp-0x4],edi
    mov    esi,DWORD PTR [ebp+0xc]
    cmp    esi,edi
    jne    Branch13
    cmp    DWORD PTR [GCrtAttachCount],edi
    je     Branch21
  Branch13:
    cmp    esi,eax
    je     Branch14
    cmp    esi,0x2
    jne    Branch16
  Branch14:
    // Attach reasons1/2: current raw hook, then actual CRTinit, each zero result exits before DllMain.
    mov    eax,[GRawDllNotificationHook]
    cmp    eax,edi
    je     Branch15
    push   DWORD PTR [ebp+0x10]
    push   esi
    push   DWORD PTR [ebp+0x8]
    call   eax
    mov    DWORD PTR [ebp-0x1c],eax
  Branch15:
    cmp    DWORD PTR [ebp-0x1c],edi
    je     Branch21
    push   DWORD PTR [ebp+0x10]
    push   esi
    push   DWORD PTR [ebp+0x8]
    call   R6GameServiceAddresses::__CRT_INIT_12
    mov    DWORD PTR [ebp-0x1c],eax
    cmp    eax,edi
    je     Branch21
  Branch16:
    // Load current reserved and current module only after prereqs; DllMain is actual selected053c0 boundary.
    mov    ebx,DWORD PTR [ebp+0x10]
    push   ebx
    push   esi
    push   DWORD PTR [ebp+0x8]
    call   R6GameServiceAddresses::_DllMain_12
    mov    DWORD PTR [ebp-0x1c],eax
    cmp    esi,0x1
    jne    Branch17
    cmp    eax,edi
    jne    Branch17
    // Failed process attach calls CRT detach rollback; keep DllMain zero as notification result.
    push   ebx
    push   edi
    push   DWORD PTR [ebp+0x8]
    call   R6GameServiceAddresses::__CRT_INIT_12
  Branch17:
    cmp    esi,edi
    je     Branch18
    cmp    esi,0x3
    jne    Branch20
  Branch18:
    // Detach reasons0/3: DllMain first, CRTinit second, current raw hook only if current result remains nonzero.
    push   ebx
    push   esi
    push   DWORD PTR [ebp+0x8]
    call   R6GameServiceAddresses::__CRT_INIT_12
    test   eax,eax
    jne    Branch19
    mov    DWORD PTR [ebp-0x1c],edi
  Branch19:
    cmp    DWORD PTR [ebp-0x1c],edi
    je     Branch20
    mov    eax,[GRawDllNotificationHook]
    cmp    eax,edi
    je     Branch20
    push   ebx
    push   esi
    push   DWORD PTR [ebp+0x8]
    call   eax
    mov    DWORD PTR [ebp-0x1c],eax
  Branch20:
    // Normal success continuation precedes separately canonical filter/handler code; actual epilogue33c87 remains parent.
    or     DWORD PTR [ebp-0x4],0xffffffff
    mov    eax,DWORD PTR [ebp-0x1c]
    jmp    Branch22
  Branch21:
    // Early-failure continuation @10033c81; state-1, EAX0 then actual SEH epilogue/RET0xc.
    or     DWORD PTR [ebp-0x4],0xffffffff
    xor    eax,eax
  Branch22:
    call   R6GameServiceAddresses::__SEH_epilog
    ret    0xc
  }
}

// Forwards the parent exception code and exception pointers to the current CRT exception filter.
// R6GameService.dll @ 10033c6d : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterCrtDllNotificationException(void)
{
  __asm {
    // Inherited EBP: parent-14 is exception pointers, first record word is code; cdecl filter receives both, raw EAX retained.
    mov    eax,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [ecx]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::ForwardCppExceptionFilter
    pop    ecx
    pop    ecx
    ret
  }
}

// Restores the notification parent stack and enters its zero-result epilogue.
// R6GameService.dll @ 10033c7e : complete native control/access order and raw ABI retained.
__declspec(naked) void ResumeFailedCrtDllNotification(void)
{
  __asm {
    // Inherited handler restores parent savedESP then falls into parent failure continuation33c81; no own return.
    mov    esp,DWORD PTR [ebp-0x18]
    // Native fallthrough enters parent continuation33c81; its state/result/epilogue code is canonical above.
  }
}

// Tail-forwards callback registration and the two table bindings to the imported CRT routine.
// R6GameService.dll @ 10033e12 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl __dllonexit(void *callback,void **begin,void **end)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71___dllonexitSlot
  }
}

// Tail-forwards the original initializer range to the current CRT import.
// R6GameService.dll @ 10033e18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl initterm(void (__cdecl **begin)(void),void (__cdecl **end)(void))
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__inittermSlot
  }
}

// Tail-forwards exception code and exception pointers without changing the imported CRT filter policy.
// R6GameService.dll @ 10033ea6 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl ForwardCppExceptionFilter(uint code,void *exceptionPointers)
{
  __asm {
    // Import6b37c is MSVCR71 __CppXcptFilter; no guessed policy or argument rewrite.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71___CppXcptFilterSlot
  }
}

// Known module-handle word is zero in selected PE raw .data, distinct from the virtual-tail CRT state.
// R6GameService.dll data @ 10091bdc : native storage identity retained.
uint GModuleHandle = 0;
// Known read-only boundary words; each routine uses one address as both begin and end, not a nonempty array.
// R6GameService.dll data @ 1007a8b0 : native storage identity retained.
const uint GRtcInitializeBoundary = 0;
// R6GameService.dll data @ 1007a8b8 : native storage identity retained.
const uint GRtcTerminationBoundary = 0;
// R6GameService.dll data @ 100770c0 : native storage identity retained.
const R6GameServiceNative::SehScope GRtcInitializeScope[1] = {
  {-1, R6GameServiceAddresses::FilterRtcInitializeException, R6GameServiceAddresses::ResumeRtcInitializeAfterException},
};
// R6GameService.dll data @ 100770d0 : native storage identity retained.
const R6GameServiceNative::SehScope GRtcTerminationScope[1] = {
  {-1, R6GameServiceAddresses::FilterRtcTerminationException,
  R6GameServiceAddresses::ResumeRtcTerminationAfterException},
};

// Stores the current module handle on every notification and returns one.
// R6GameService.dll @ 100053c0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall _DllMain_12(void *moduleHandle,uint reason,void *reserved)
{
  __asm {
    // Read only moduleHandle; reason/reserved are ignored. Every notification overwrites the same native DWORD.
    mov    eax,DWORD PTR [esp+0x4]
    mov    [GModuleHandle],eax
    mov    eax,0x1
    ret    0xc
  }
}

// Installs the native RTC initialization frame and traverses the selected empty callback range.
// R6GameService.dll @ 10033e1e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl __RTC_Initialize(void)
{
  __asm {
    // Actual SEH prologue/local0c. Native begin/end are both7a8b0, so the initial gate always skips callbacks.
    push   0xc
    push   offset GRtcInitializeScope
    call   R6GameServiceAddresses::__SEH_prolog
    mov    DWORD PTR [ebp-0x1c],offset GRtcInitializeBoundary
  Branch23:
    cmp    DWORD PTR [ebp-0x1c],offset GRtcInitializeBoundary
    jae    Branch25
    // Retain native loop operations even though fixed initial range is empty; state0 only covers a nonnull callback.
    and    DWORD PTR [ebp-0x4],0x0
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [eax]
    test   eax,eax
    je     Branch24
    call   eax
    jmp    Branch24
  Branch24:
    // Native shared continuation @10033e52; separate filter/handler are not duplicated here.
    or     DWORD PTR [ebp-0x4],0xffffffff
    add    DWORD PTR [ebp-0x1c],0x4
    jmp    Branch23
  Branch25:
    // Actual SEH epilogue preserves prolog/callback EAX residue and restores FS/nonvolatile registers.
    call   R6GameServiceAddresses::__SEH_epilog
    ret
  }
}

// Returns the native constant execute-handler result for the RTC initialization scope.
// R6GameService.dll @ 10033e4b : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRtcInitializeException(void)
{
  __asm {
    // Constant EAX1 without inspecting exception data; native filter identity comes from scope770c0.
    xor    eax,eax
    inc    eax
    ret
  }
}

// Restores the RTC initializer parent stack and falls into its shared cursor-advance continuation.
// R6GameService.dll @ 10033e4f : complete native control/access order and raw ABI retained.
__declspec(naked) void ResumeRtcInitializeAfterException(void)
{
  __asm {
    // Native fallthrough enters parent33e52 (state-1, cursor+=4, compare loop); no independently returning body.
    mov    esp,DWORD PTR [ebp-0x18]
  }
}

// Installs the native RTC termination frame and traverses the selected empty callback range.
// R6GameService.dll @ 10033e62 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RunCrtTerminationCallbacks(void)
{
  __asm {
    // Actual SEH prologue/local0c. Native begin/end are both7a8b8; zero boundary contents do not control this gate.
    push   0xc
    push   offset GRtcTerminationScope
    call   R6GameServiceAddresses::__SEH_prolog
    mov    DWORD PTR [ebp-0x1c],offset GRtcTerminationBoundary
  Branch26:
    cmp    DWORD PTR [ebp-0x1c],offset GRtcTerminationBoundary
    jae    Branch28
    // Keep original callback/null/state/control accesses; their presence is not evidence of a nonempty selected range.
    and    DWORD PTR [ebp-0x4],0x0
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [eax]
    test   eax,eax
    je     Branch27
    call   eax
    jmp    Branch27
  Branch27:
    // Native shared continuation @10033e96; parent owns the state/cursor/epilogue once.
    or     DWORD PTR [ebp-0x4],0xffffffff
    add    DWORD PTR [ebp-0x1c],0x4
    jmp    Branch26
  Branch28:
    call   R6GameServiceAddresses::__SEH_epilog
    ret
  }
}

// Returns the native constant execute-handler result for the RTC termination scope.
// R6GameService.dll @ 10033e8f : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRtcTerminationException(void)
{
  __asm {
    // Constant EAX1, independently canonical from the identical initialization filter body.
    xor    eax,eax
    inc    eax
    ret
  }
}

// Restores the RTC terminator parent stack and falls into its shared cursor-advance continuation.
// R6GameService.dll @ 10033e93 : complete native control/access order and raw ABI retained.
__declspec(naked) void ResumeRtcTerminationAfterException(void)
{
  __asm {
    // Native fallthrough enters parent33e96; exact savedESP[parent-18] load retained.
    mov    esp,DWORD PTR [ebp-0x18]
  }
}
