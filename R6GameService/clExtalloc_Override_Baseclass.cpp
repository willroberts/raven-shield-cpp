#include "native_addresses.h"
#include "native_records.h"

// Identified allocation base class: native COL100784c8/type1008c3c4 names clExtalloc_Override_Baseclass.

// Restores the allocation base table without releasing storage or changing EAX.
// R6GameService.dll @ 10037840 : ECX receiver, no stack words, plain RET; incoming EAX preserved.
__declspec(naked) uint __fastcall DestroyExtallocOverrideBase(uint *owner)
{
  __asm {
    mov    dword ptr [ecx],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    ret
  }
}

// Restores the allocator base table and frees its owner when the already-captured low deletion bit is set.
// R6GameService.dll @ 10016230 : primary75bdc slot0; incoming flag byte loads before table write, EAX owner/RET4.
__declspec(naked) void * __thiscall DeleteExtallocOverrideBase(void *owner,uint deletionFlags)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    test   al,0x1
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Native virtual-table prefix: clExtalloc_Override_BaseclassVTable
// R6GameService.dll data @ 10075bdc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clExtalloc_Override_BaseclassVTableRecord {
  R6GameServiceNative::Address DeleteExtallocOverrideBase; // +0x00
};
const clExtalloc_Override_BaseclassVTableRecord clExtalloc_Override_BaseclassVTable = {
  R6GameServiceAddresses::DeleteExtallocOverrideBase,
};
