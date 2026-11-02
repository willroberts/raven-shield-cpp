#include "native_addresses.h"
#include "native_records.h"

// RTTI establishes clLadderQueryCB ownership; method and argument names are descriptive ABI approximations.
// Keep dynamic virtual-base offsets explicit; no complete class declaration or layout is invented.

// clLadderQueryCB: optionally initialize virtual bases, always install current dynamic tables and zero +8.
// Read vbptr before primary store, offset afterward; preserve raw alias/overwrite order, EAX owner/ECX0/RET4.
// R6GameService.dll @ 1004fd50 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeVtableSubobject(void *owner,uint initializeVirtualBases)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch1
    mov    DWORD PTR [eax+0x4],0x10077f48
    mov    DWORD PTR [eax+0x10],0x10077f40
    mov    DWORD PTR [eax+0xc],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
  Branch1:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clLadderQueryCBVTable
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+eax*1+0x4],R6GameServiceAddresses::clLadderQueryCBVTableAdjusted12
    mov    DWORD PTR [eax+0x8],ecx
    pop    ecx
    ret    0x4
  }
}

// Restore clLadderQueryCB through adjusted receiver+c, restore allocator table, free complete owner if low bit1.
// Load flag after restoration; return complete owner despite free EAX, with no own EH. RET4.
// R6GameService.dll @ 1004fda0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteclLadderQueryCB(void *adjustedReceiver,uint deleteFlags)
{
  __asm {
    push    esi
    lea    esi,[ecx-0xc]
    push    edi
    lea    edi,[esi+0xc]
    mov    ecx,edi
    call    R6GameServiceAddresses::RestoreVtableSubobject
    mov    al,BYTE PTR [esp+0xc]
    mov    DWORD PTR [edi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    test    al,0x1
    je    Branch2
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Restore clLadderQueryCB primary at receiver-c, then dynamic secondary; raw EAX=loaded vbptr.
// R6GameService.dll @ 1004fdd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RestoreVtableSubobject(void *adjustedReceiver)
{
  __asm {
    mov    eax,DWORD PTR [ecx-0x8]
    mov    DWORD PTR [ecx-0xc],R6GameServiceAddresses::clLadderQueryCBVTable
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [edx+ecx*1-0x8],R6GameServiceAddresses::clLadderQueryCBVTableAdjusted12
    ret
  }
}

// If member+8 exists, load first word into ECX, rewrite its same stack slot and tail target with all3 words.
// NULL target returns EAX0/RETc without reading arguments; preserve original tail stack/raw return.
// R6GameService.dll @ 1004fdf0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLadderQueryCBCallback08(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x8]
    test    eax,eax
    je    Branch3
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch3:
    ret    0xc
  }
}

// Native virtual-table prefix: clLadderQueryCBVTableAdjusted12
// R6GameService.dll data @ 10077f34 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLadderQueryCBVTableAdjusted12Record {
  R6GameServiceNative::Address DeleteclLadderQueryCB; // +0x00
};
const clLadderQueryCBVTableAdjusted12Record clLadderQueryCBVTableAdjusted12 = {
  R6GameServiceAddresses::DeleteclLadderQueryCB,
};

// Native virtual-table prefix: clLadderQueryCBVTable
// R6GameService.dll data @ 10077f3c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLadderQueryCBVTableRecord {
  R6GameServiceNative::Address ForwardclLadderQueryCBCallback08; // +0x00
};
const clLadderQueryCBVTableRecord clLadderQueryCBVTable = {R6GameServiceAddresses::ForwardclLadderQueryCBCallback08};
