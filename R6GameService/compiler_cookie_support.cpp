#include "native_addresses.h"
#include "native_records.h"

// MSVC compiler startup/check glue from the selected game-service DLL; OS/CRT delivery remains external.

// Build native SEH scope, invoke compiler-error handler(1,0) in state0, then disarm and call ExitProcess(3).
// Scope filter/continuation have separate canonical bodies; returning ExitProcess reaches genuine INT3, no epilog.
// R6GameService.dll @ 10062250 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReportStackCookieFailure(void)
{
  __asm {
    push    0x8
    push    R6GameServiceAddresses::GCompilerCookieScope
    call    R6GameServiceAddresses::__SEH_prolog
    and    DWORD PTR [ebp-0x4],0x0
    push    0x0
    push    0x1
    call    R6GameServiceAddresses::__security_error_handler
    pop    ecx
    pop    ecx
    jmp    Branch1
  Branch1:
    or    DWORD PTR [ebp-0x4],0xffffffff
    push    0x3
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ExitProcessSlot
    int    3
  }
}

// Return constant1 to the compiler-error SEH scope; do not inspect or modify the parent frame.
// R6GameService.dll @ 1006226d : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl FilterCompilerCookieError(void)
{
  __asm {
    xor    eax,eax
    inc    eax
    ret
  }
}

// Restore saved ESP from inherited EBP-18 and fall through to parent62274 state-1/ExitProcess continuation.
// R6GameService.dll @ 10062271 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResumeCompilerCookieFailure(void)
{
  __asm {
    mov    esp,DWORD PTR [ebp-0x18]
  }
}

// Compare full incoming ECX with current module cookie; equal returns unchanged EAX, mismatch tails compiler failure
// path.
// R6GameService.dll @ 10062281 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall __security_check_cookie(uint cookieWord)
{
  __asm {
    cmp    ecx,DWORD PTR ds:R6GameServiceAddresses::GSecurityCookie
    jne    Branch2
    ret
  Branch2:
    jmp    R6GameServiceAddresses::ReportStackCookieFailure
  }
}

// Keep a nonzero/nondefault cookie; otherwise combine native time/ID/tick/counter DWORDs and substitute default only
// for zero.
// API results do not gate scratch reads; preserve exact call/current publication order. Return cookie on skip or
// counter fold on initialization.
// R6GameService.dll @ 100622cf : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ___security_init_cookie(void)
{
  __asm {
    push    ebp
    mov    ebp,esp
    sub    esp,0x10
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    test    eax,eax
    je    Branch3
    cmp    eax,0xbb40e64e
    jne    Branch5
  Branch3:
    push    esi
    lea    eax,[ebp-0x8]
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetSystemTimeAsFileTimeSlot
    mov    esi,DWORD PTR [ebp-0x4]
    xor    esi,DWORD PTR [ebp-0x8]
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot
    xor    esi,eax
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentThreadIdSlot
    xor    esi,eax
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    xor    esi,eax
    lea    eax,[ebp-0x10]
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::KERNEL32_QueryPerformanceCounterSlot
    mov    eax,DWORD PTR [ebp-0xc]
    xor    eax,DWORD PTR [ebp-0x10]
    xor    esi,eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecurityCookie,esi
    jne    Branch4
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecurityCookie,0xbb40e64e
  Branch4:
    pop    esi
  Branch5:
    leave
    ret
  }
}

// Literal one-state compiler-error SEH scope at100783b8.
// R6GameService.dll data @ 100783b8 : native storage identity retained.
const R6GameServiceNative::SehScope GCompilerCookieScope[1] = {
  {-1, R6GameServiceAddresses::FilterCompilerCookieError, R6GameServiceAddresses::ResumeCompilerCookieFailure},
};
