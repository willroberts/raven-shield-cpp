#include "native_addresses.h"

// ATL library-match ownership retained; offsets describe the selected PE32 object, not a complete class declaration.
// Deletes the critical section unconditionally, then tail-forwards to array storage cleanup.
// R6GameService.dll @ 10037231 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)
{
  __asm {
    push   esi
    mov    esi,ecx
    lea    eax,[esi+0x18]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_DeleteCriticalSectionSlot
    lea    ecx,[esi+0x30]
    pop    esi
    jmp    R6GameServiceAddresses::RemoveAll
  }
}

// Initializes module handles, platform flag, ATL version and GUID; a negative critical-section status sets sticky failure.
// R6GameService.dll @ 10037247 : complete native control/access order and raw ABI retained.
__declspec(naked) CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)
{
  __asm {
    // Relocated image-base/GUID operands; unsigned version gates; GetVersionExA status ignored; padding+d..f untouched.
    push   ebp
    lea    ebp,[esp-0x78]
    sub    esp,0x98
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    mov    DWORD PTR [ebp+0x74],eax
    mov    esi,ecx
    call   R6GameServiceAddresses::ATL__ATL_BASE_MODULE70__ATL_BASE_MODULE70
    mov    eax,R6GameServiceAddresses::ModuleImageBase
    push   0x94
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0x4],eax
    lea    eax,[ebp-0x20]
    push   0x0
    push   eax
    mov    DWORD PTR [esi],0x3c
    mov    BYTE PTR [esi+0xc],0x0
    call   R6GameServiceAddresses::memset
    add    esp,0xc
    lea    eax,[ebp-0x20]
    push   eax
    mov    DWORD PTR [ebp-0x20],0x94
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetVersionExASlot
    cmp    DWORD PTR [ebp-0x10],0x2
    jne    Branch1
    cmp    DWORD PTR [ebp-0x1c],0x5
    jb    Branch3
    jmp    Branch2
  Branch1:
    cmp    DWORD PTR [ebp-0x10],0x1
    jne    Branch3
    cmp    DWORD PTR [ebp-0x1c],0x4
    ja    Branch2
    jne    Branch3
    cmp    DWORD PTR [ebp-0x18],0x0
    jbe    Branch3
  Branch2:
    mov    BYTE PTR [esi+0xc],0x1
  Branch3:
    lea    ecx,[esi+0x18]
    mov    DWORD PTR [esi+0x10],0x710
    mov    DWORD PTR [esi+0x14],0x100778e4
    call   R6GameServiceAddresses::InitializeCriticalSectionWithStatus
    test   eax,eax
    jge    Branch4
    mov    BYTE PTR ds:0x10091528,0x1
  Branch4:
    mov    ecx,DWORD PTR [ebp+0x74]
    mov    eax,esi
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    add    ebp,0x78
    leave
    ret
  }
}

// Constructs the global module, registers cleanup and returns registration status without rollback.
// R6GameService.dll @ 1006abfa : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl InitializeGlobalAtlBaseModule(void)
{
  __asm {
    mov    ecx,0x10094534
    call   R6GameServiceAddresses::ATL_CAtlBaseModule_CAtlBaseModule
    push   R6GameServiceAddresses::DestroyGlobalAtlBaseModule
    call   R6GameServiceAddresses::_atexit
    pop    ecx
    ret
  }
}

// Tail-forwards global module storage to its unconditional destructor.
// R6GameService.dll @ 1006ae0a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyGlobalAtlBaseModule(void)
{
  __asm {
    mov    ecx,0x10094534
    jmp    R6GameServiceAddresses::ATL_CAtlBaseModule__CAtlBaseModule
  }
}
