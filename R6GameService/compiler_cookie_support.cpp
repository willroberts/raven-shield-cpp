#include "native_addresses.h"
#include "native_import_bindings.h"
#include <intrin.h>
#include "native_records.h"

// MSVC compiler startup/check glue from the selected game-service DLL; OS/CRT delivery remains external.

// Reports a cookie mismatch in an SEH scope, then exits with code3; a returned ExitProcess reaches INT3.
// R6GameService.dll @ 10062250 : inferred C++ scope view of compiler glue; filter/continuation remain separate entries.
[[noreturn]] void __cdecl ReportStackCookieFailure(void)
{
  __try {
    R6GameServiceImports::__security_error_handler(1,0);
  } __except(1) {
  }
  using ExitABI = void (__stdcall *)(uint);
  (*(ExitABI *)R6GameServiceAddresses::KERNEL32_ExitProcessSlot)(3);
  __debugbreak();
  __assume(0);
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

// Checks ECX against the module cookie and transfers mismatches to the nonreturning failure reporter.
// The compiler ABI preserves the enclosing function's pending EAX result on a match; it produces no return value.
// R6GameService.dll @ 10062281 : inferred void fastcall view of the compiler helper; complete 32-bit comparison.
void __fastcall __security_check_cookie(uint cookieWord)
{
  if (cookieWord != *(uint *)R6GameServiceAddresses::GSecurityCookie) ReportStackCookieFailure();
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
