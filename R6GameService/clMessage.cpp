#include "native_addresses.h"
#include "native_records.h"

// Store clMessage base table without changing EAX or any other receiver field; raw uint/RET.
// R6GameService.dll @ 1005c130 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetClMessageVtable(void *message)
{
  __asm {
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clMessageVTable
    ret
  }
}

// Read original lowBYTE flag, install clMessage table, optionally free receiver if bit0 set and return original
// receiver/RET4.
// R6GameService.dll @ 1005c150 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteClMessage(void *message,uint deleteFlags)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    push    esi
    mov    esi,ecx
    test    al,0x1
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMessageVTable
    je    Branch1
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Native virtual-table prefix: clMessageVTable
// R6GameService.dll data @ 100781c4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMessageVTableRecord {
  R6GameServiceNative::Address DeleteClMessage; // +0x00
  R6GameServiceNative::Address _purecall; // +0x04
  R6GameServiceNative::Address shared_native_NoOp; // +0x08
  R6GameServiceNative::Address list_node_support_NoOp; // +0x0c
  R6GameServiceNative::Address _purecall2; // +0x10
  R6GameServiceNative::Address _purecall3; // +0x14
  R6GameServiceNative::Address _purecall4; // +0x18
};
const clMessageVTableRecord clMessageVTable = {
  R6GameServiceAddresses::DeleteClMessage,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::list_node_support_NoOp,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};
