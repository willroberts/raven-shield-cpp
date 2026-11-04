#include "native_addresses.h"

// Optionally publish the virtual-base table, then install clData identity and the supplied value word.
// R6GameService.dll @ 10026e70 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall InitializeClDataFields(void *object,uint valueWord,uint initializeVirtualBaseWord)
{
  if (initializeVirtualBaseWord != 0) *(uint *)((byte *)object + 4) = 0x10076a98;
  uint value = valueWord;
  *(uint *)object = R6GameServiceAddresses::PTR_LAB;
  *(uint *)((byte *)object + 8) = value;
  return object;
}

// Restore the clData base identity without changing its value word; native EAX is incidental, not a return value.
// R6GameService.dll @ 1002ae90 : inferred void cleanup with receiver in ECX and no stack arguments.
void __fastcall ResetClDataVtable(undefined4 *objectWords)
{
  *objectWords = R6GameServiceAddresses::PTR_LAB;
}

// Resets the clData vtable, optionally frees the object using the saved low flag bit, and returns its address.
// R6GameService.dll @ 10026ea0 : native store order, stack aliases and raw register effects retained.
__declspec(naked) void * __thiscall DeleteClData(void *object,uint deleteFlagWord)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    test   al,0x1
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    je Branch2
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}
