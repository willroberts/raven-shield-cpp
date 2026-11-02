#include "native_addresses.h"

// ATL library-match ownership retained; no complete class layout is asserted.
// Clears critical-section storage at +18 and array words at +30/+34/+38, leaving the header untouched.
// R6GameService.dll @ 10037217 : complete native control/access order and raw ABI retained.
__declspec(naked) _ATL_BASE_MODULE70 * __thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(_ATL_BASE_MODULE70 *this)
{
  __asm {
    push   esi
    mov    esi,ecx
    lea    ecx,[esi+0x18]
    call   R6GameServiceAddresses::ClearCriticalSectionStorage
    xor    eax,eax
    mov    DWORD PTR [esi+0x30],eax
    mov    DWORD PTR [esi+0x34],eax
    mov    DWORD PTR [esi+0x38],eax
    mov    eax,esi
    pop    esi
    ret
  }
}
