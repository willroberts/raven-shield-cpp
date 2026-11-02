#include "native_addresses.h"

// ATL library-match ownership retained; array words are storage pointer, count and capacity.
// Frees the original backing allocation when nonnull, then clears current array words without unloading individual handles.
// R6GameService.dll @ 100371fa : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ATL::CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_>::RemoveAll(CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_> *this)
{
  __asm {
    // Free may mutate the owner: clear its current pointer only on the original nonnull branch.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi]
    test   eax,eax
    je    Branch1
    push   eax
    call   R6GameServiceAddresses::free
    and    DWORD PTR [esi],0x0
    pop    ecx
  Branch1:
    and    DWORD PTR [esi+0x4],0x0
    and    DWORD PTR [esi+0x8],0x0
    pop    esi
    ret
  }
}
