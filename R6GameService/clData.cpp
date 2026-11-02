#include "native_addresses.h"

// Installs the optional virtual-base table, clData base vtable and value word, returning receiver EAX and zero ECX.
// R6GameService.dll @ 10026e70 : native store order, stack aliases and raw register effects retained.
__declspec(naked) void * __thiscall InitializeClDataFields(
    void *object,uint valueWord,uint initializeVirtualBaseWord)
{
  __asm {
    push   ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0xc]
    test   ecx,ecx
    mov    DWORD PTR [esp+0x0],0x0
    je Branch1
    mov    DWORD PTR [eax+0x4],0x10076a98
  Branch1:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [eax],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [eax+0x8],ecx
    pop    ecx
    ret    0x8
  }
}

// Resets the receiver to the clData base vtable without touching any value, buffer or incoming EAX.
// R6GameService.dll @ 1002ae90 : ECX object, no stack arguments; MOV[ECX],10076a64/RET.
__declspec(naked) uint __fastcall ResetClDataVtable(undefined4 *objectWords)
{
  __asm {
    mov    dword ptr [ecx],R6GameServiceAddresses::PTR_LAB
    ret
  }
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
