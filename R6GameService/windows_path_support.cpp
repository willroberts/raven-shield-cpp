#include "native_addresses.h"

// Windows path/version helpers, preserving native low-byte results and unchecked current-directory API outcomes.
// R6GameService.dll data @ 1008e798 : native storage identity retained.
uint GWindowsVersionHighBitCache = 0xffffffff;

// Constructs the current directory as a wide string using the cached Windows version flag.
// R6GameService.dll @ 10037130 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ConstructCurrentDirectoryWideString(void *destination)
{
  __asm {
    // Cookie at entryESP-4, rawzeroDWORD entryESP-210, 260-unit buffer entryESP-20c; no local lifetime frame.
    sub    esp,0x210
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    mov    DWORD PTR [esp+0x210],eax
    mov    DWORD PTR [esp+0x4],0x0
    call   R6GameServiceAddresses::GetCachedWindowsVersionHighBit
    test   al,al
    je     Branch1
    // GetCurrentDirectoryA(104,buffer) return ignored, then actual ANSI->wide constructor; destination loads after API.
    lea    eax,[esp+0x8]
    push   eax
    push   0x104
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentDirectoryASlot
    mov    esi,DWORD PTR [esp+0x218]
    lea    ecx,[esp+0x8]
    push   ecx
    push   esi
    call   R6GameServiceAddresses::ConstructWideStringFromAnsi
    add    esp,0x8
    mov    eax,esi
    pop    esi
    mov    ecx,DWORD PTR [esp+0x20c]
    call   R6GameServiceAddresses::__security_check_cookie
    add    esp,0x210
    ret
  Branch1:
    // GetCurrentDirectoryW(104,buffer) return ignored, direct CRT wide constructor, return cached destination despite ctorEAX.
    lea    edx,[esp+0x8]
    push   edx
    push   0x104
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentDirectoryWSlot
    mov    esi,DWORD PTR [esp+0x218]
    lea    eax,[esp+0x8]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2
    mov    ecx,DWORD PTR [esp+0x210]
    mov    eax,esi
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    add    esp,0x210
    ret
  }
}

// Caches whether GetVersion has its high bit set and returns its truth value in AL.
// R6GameService.dll @ 100371d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl GetCachedWindowsVersionHighBit(void)
{
  __asm {
    // Only cacheFFFFFFFF queries GetVersion; unsigned high-bit test becomes0/1. No synchronization.
    mov    eax,[GWindowsVersionHighBitCache]
    cmp    eax,0xffffffff
    jne    Branch2
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetVersionSlot
    cmp    eax,0x80000000
    sbb    eax,eax
    inc    eax
    mov    [GWindowsVersionHighBitCache],eax
  Branch2:
    // For other cached words, normalize AL only, retaining upper24bits; cache itself is not normalized.
    test   eax,eax
    setne  al
    ret
  }
}
