#include "native_addresses.h"
#include "native_records.h"

// Six-word critical-section storage and SEH initialization; original helper class identity remains unresolved.
// R6GameService.dll data @ 1006b630 : outer state, filter and handler for initialization.
const R6GameServiceNative::SehScope GAtlCriticalSectionScope[1] = {
  {-1, R6GameServiceAddresses::FilterCriticalSectionInitialization,
  R6GameServiceAddresses::HandleCriticalSectionInitialization},
};

// Clears exactly six words and returns the original storage address; ECX becomes zero and EDX retains storage.
// R6GameService.dll @ 100010c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ClearCriticalSectionStorage(void *storage)
{
  __asm {
    mov    eax,ecx
    xor    ecx,ecx
    mov    edx,eax
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [edx+0x4],ecx
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [edx+0xc],ecx
    mov    DWORD PTR [edx+0x10],ecx
    mov    DWORD PTR [edx+0x14],ecx
    ret
  }
}

// Initializes a critical section under SEH; the separate handler maps caught failures to HRESULTs.
// R6GameService.dll @ 100010e0 : complete native control/access order and raw ABI retained.
__declspec(naked) HRESULT __thiscall InitializeCriticalSectionWithStatus(LPCRITICAL_SECTION criticalSection)
{
  __asm {
    // State0 covers the API call; the physical filter/handler are separate bodies below.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::GAtlCriticalSectionScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x4],esi
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InitializeCriticalSectionSlot
    jmp    Branch1
  Branch1:
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Captures the parent exception code and selects the execute-handler disposition.
// R6GameService.dll @ 10001114 : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterCriticalSectionInitialization(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [ebp-0x1c],edx
    mov    eax,0x1
    ret
  }
}

// Restores saved ESP, maps no-memory to E_OUTOFMEMORY and other failures to E_FAIL, then resumes the parent.
// R6GameService.dll @ 10001124 : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleCriticalSectionInitialization(void)
{
  __asm {
    mov    esp,DWORD PTR [ebp-0x18]
    xor    eax,eax
    cmp    DWORD PTR [ebp-0x1c],0xc0000017
    setne  al
    dec    eax
    and    eax,0x6c009
    add    eax,0x80004005
    mov    esi,eax
    jmp    R6GameServiceAddresses::critical_section_supportBranch1 // Physical fallthrough to the parent epilogue.
  }
}
