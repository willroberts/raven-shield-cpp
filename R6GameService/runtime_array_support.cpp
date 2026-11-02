#include "native_addresses.h"
#include "native_records.h"

// Shared compiler array/SEH runtime bodies; raw frame protocols are retained independently of Windows dispatch.
using ArrayElementDestructor = void (__thiscall *)(void *element);
// Exact one-record scope tables, with descriptive native names.
// R6GameService.dll data @ 10077088 : native storage identity retained.
const R6GameServiceNative::SehScope GArrayUnwindScope[1] = {
  {-1, R6GameServiceAddresses::FilterArrayUnwindException, R6GameServiceAddresses::ResumeArrayUnwindHandler},
};
// R6GameService.dll data @ 10077098 : native storage identity retained.
const R6GameServiceNative::SehScope GArrayDestructorScope[1] = {
  {-1, 0, R6GameServiceAddresses::UnwindArrayDestructorIterator},
};

// Tail-forwards the original SEH frame and register state to the selected _except_handler3 import.
// R6GameService.dll @ 10033900 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ForwardExceptHandler3(void)
{
  __asm {
    // Import6b420 is MSVCR71 _except_handler3. This is a raw register/frame forwarding entry, not a new C handler ABI.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__except_handler3Slot
  }
}

// Tail-forwards the current C++ exception frame, retaining EAX FuncInfo and all incoming stack words.
// R6GameService.dll @ 10033906 : complete native control/access order and raw ABI retained.
__declspec(naked) void __CxxFrameHandler(void)
{
  __asm {
    // Import6b41c is __CxxFrameHandler; preserve selector-supplied EAX and original exception-handler arguments.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71___CxxFrameHandlerSlot
  }
}

// Destroys preceding elements with current parent slots, filtering cleanup C++ exceptions through terminate.
// R6GameService.dll @ 1003390c : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall __ArrayUnwind(void *cursor,uint elementSize,int remainingCount,ArrayElementDestructor destructor)
{
  __asm {
    // Actual SEH prolog consumes local-size14h/scope77088; parent EBP becomes original entryESP-4.
    push   0x14
    push   offset GArrayUnwindScope
    call   R6GameServiceAddresses::__SEH_prolog
    and    DWORD PTR [ebp-0x4],0x0
  Branch1:
    // Decrement current parent count before signed gate; current cursor/stride/callback slots reload each iteration.
    dec    DWORD PTR [ebp+0x10]
    js     Branch2
    mov    ecx,DWORD PTR [ebp+0x8]
    sub    ecx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ebp+0x8],ecx
    call   DWORD PTR [ebp+0x14]
    jmp    Branch1
  Branch2:
    // Lower try level -1 then actual SEH epilog/RET10. Keep raw callback/prolog EAX residue.
    or     DWORD PTR [ebp-0x4],0xffffffff
    call   R6GameServiceAddresses::__SEH_epilog
    ret    0x10
  }
}

// Returns continue-search for other exceptions and terminates on the native C++ exception code.
// R6GameService.dll @ 1003393b : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterArrayUnwindException(void)
{
  __asm {
    // Inherited EBP: parent-14 -> EXCEPTION_POINTERS -> record; scratch-1c/-20 retain actual accesses.
    mov    eax,DWORD PTR [ebp-0x14]
    mov    DWORD PTR [ebp-0x1c],eax
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [ebp-0x20],eax
    mov    eax,DWORD PTR [ebp-0x20]
    cmp    DWORD PTR [eax],0xe06d7363
    je     Branch3
    // Filter result0 means continue search; keep scratch-24 store/reload and raw null faults.
    mov    DWORD PTR [ebp-0x24],0x0
    mov    eax,DWORD PTR [ebp-0x24]
    ret
  Branch3:
    // Filter continuation @10033964, after separate handler3395f; C++ code e06d7363 calls actual terminate thunk.
    call   R6GameServiceAddresses::ForwardTerminate
    int3
  }
}

// Restores the parent saved stack and branches to the array-unwind parent epilogue.
// R6GameService.dll @ 1003395f : complete native control/access order and raw ABI retained.
__declspec(naked) void ResumeArrayUnwindHandler(void)
{
  __asm {
    // This scope-table handler is distinct from the filter; no independent return frame or invented recovery.
    mov    esp,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::runtime_array_supportBranch2
  }
}

// Destroys array elements backward with a cached stride and explicit exceptional remainder cleanup.
// R6GameService.dll @ 1003396a : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall _eh_vector_destructor_iterator_(void *arrayBegin,uint elementSize,int count,ArrayElementDestructor destructor)
{
  __asm {
    // Scope77098 finally339b2; local-1c completion0. Initial cursor advances by modular stride*original count.
    push   0xc
    push   offset GArrayDestructorScope
    call   R6GameServiceAddresses::__SEH_prolog
    and    DWORD PTR [ebp-0x1c],0x0
    mov    esi,DWORD PTR [ebp+0xc]
    mov    eax,esi
    imul   eax,DWORD PTR [ebp+0x10]
    add    DWORD PTR [ebp+0x8],eax
    and    DWORD PTR [ebp-0x4],0x0
  Branch4:
    // Current count decrements each pass, but stride ESI stays cached. Current callback/parent cursor reload.
    dec    DWORD PTR [ebp+0x10]
    js     Branch5
    sub    DWORD PTR [ebp+0x8],esi
    mov    ecx,DWORD PTR [ebp+0x8]
    call   DWORD PTR [ebp+0x14]
    jmp    Branch4
  Branch5:
    // Publish completion1 before state-1 and normal finally call, suppressing remainder cleanup on normal return.
    mov    DWORD PTR [ebp-0x1c],0x1
    or     DWORD PTR [ebp-0x4],0xffffffff
    call   R6GameServiceAddresses::UnwindArrayDestructorIterator
    call   R6GameServiceAddresses::__SEH_epilog
    ret    0x10
  }
}

// Forwards unfinished iterator parent slots to array unwind unless the completion flag is set.
// R6GameService.dll @ 100339b2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindArrayDestructorIterator(void)
{
  __asm {
    // Inherited EBP; exact-zero completion triggers cleanup, any nonzero skips. Forward current four parent slots.
    cmp    DWORD PTR [ebp-0x1c],0x0
    jne    Branch6
    push   DWORD PTR [ebp+0x14]
    push   DWORD PTR [ebp+0x10]
    push   DWORD PTR [ebp+0xc]
    push   DWORD PTR [ebp+0x8]
    call   R6GameServiceAddresses::__ArrayUnwind
  Branch6:
    ret
  }
}

// Tail-forwards exception object and ThrowInfo directly to the selected nonreturning CRT throw import.
// R6GameService.dll @ 10033a16 : complete native control/access order and raw ABI retained.
__declspec(naked) [[noreturn]] void __stdcall _CxxThrowException(void *object,const void *throwInfo)
{
  __asm {
    // Current IAT6b418 owns runtime throw/copy policy; no added argument cleanup or result normalization.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__CxxThrowExceptionSlot
  }
}

// Tail-forwards termination without adding a wrapper frame or altering imported termination policy.
// R6GameService.dll @ 10033dba : complete native control/access order and raw ABI retained.
__declspec(naked) [[noreturn]] void __cdecl ForwardTerminate(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__terminateSlot
  }
}

// Consumes the caller local-size/scope words, installs its SEH frame and resumes at the saved continuation.
// R6GameService.dll @ 10033dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __SEH_prolog(void)
{
  __asm {
    // Special caller protocol, not ordinary cdecl: replace local-size word with old EBP, retain scope/continuation.
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],ebp
    lea    ebp,[esp+0x10]
    sub    esp,eax
    push   ebx
    push   esi
    push   edi
    // Save current stack at parent-18, move scope to parent-8, publish state-1 and chain at parent-10.
    mov    eax,DWORD PTR [ebp-0x8]
    mov    DWORD PTR [ebp-0x18],esp
    push   eax
    mov    eax,DWORD PTR [ebp-0x4]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    DWORD PTR [ebp-0x8],eax
    lea    eax,[ebp-0x10]
    mov    fs:0x0,eax
    ret
  }
}

// Restores the SEH chain and parent registers while carrying the continuation through ECX.
// R6GameService.dll @ 10033dfb : complete native control/access order and raw ABI retained.
__declspec(naked) void __SEH_epilog(void)
{
  __asm {
    // Restore saved FS before popping continuation and nonvolatile registers; LEAVE recovers caller frame.
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    ecx
    pop    edi
    pop    esi
    pop    ebx
    leave
    push   ecx
    ret
  }
}
