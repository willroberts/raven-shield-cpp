#include "native_addresses.h"

// Selected _STL RTTI/catchable-type records identify this class; original declarations are not invented.

// Copies the imported exception base, then256 diagnostic bytes as forward DWORDs and installs the derived table.
// Source pointer caches before the base call; source data reloads after it, and overlap retains native copy order.
// R6GameService.dll @ 100172a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopySTLOutOfRange(void *owner,void *source)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    push   esi
    mov    ebx,ecx
    call   R6GameServiceAddresses::exception_exception
    add    esi,0xc
    lea    edi,[ebx+0xc]
    mov    ecx,0x40
    mov    eax,ebx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    pop    edi
    mov    DWORD PTR [ebx],R6GameServiceAddresses::out_of_range__STLVTable
    pop    esi
    pop    ebx
    ret    0x4
  }
}
