#include "native_addresses.h"
#include "native_records.h"

// RTTI establishes clPersistentCB ownership; method and argument names are descriptive ABI approximations.
// Keep dynamic virtual-base offsets explicit; no complete class declaration or layout is invented.

// clPersistentCB: optionally initialize virtual bases, always install current dynamic tables and zero +8..+14.
// Read vbptr before primary store, offset afterward; preserve raw alias/overwrite order, EAX owner/ECX0/RET4.
// R6GameService.dll @ 1004fe10 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeExtendedVtableSubobject(void *owner,uint initializeVirtualBases)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch1
    mov    DWORD PTR [eax+0x4],0x10077f78
    mov    DWORD PTR [eax+0x1c],0x10077f70
    mov    DWORD PTR [eax+0x18],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
  Branch1:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clPersistentCBVTable
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+eax*1+0x4],R6GameServiceAddresses::clPersistentCBVTableAdjusted24
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [eax+0x10],ecx
    mov    DWORD PTR [eax+0x14],ecx
    pop    ecx
    ret    0x4
  }
}

// Restore clPersistentCB through adjusted receiver+18, restore allocator table, free complete owner if low bit1.
// Load flag after restoration; return complete owner despite free EAX, with no own EH. RET4.
// R6GameService.dll @ 1004fe60 : complete native control/access order and raw ABI retained.
void *__thiscall DeleteclPersistentCB(void *secondary,uint deletionFlags)
{
  uint owner = (uint)secondary - 0x18;
  void *fixedBase = (void *)(owner + 0x18);
  using RestoreABI = uint (__fastcall *)(void *);
  ((RestoreABI)R6GameServiceAddresses::RestoreExtendedVtableSubobject)(fixedBase);
  byte flags = *(byte *)&deletionFlags;
  *(uint *)fixedBase = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  if ((flags & 1) != 0) {
    using FreeABI = uint (__stdcall *)(void *);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)owner);
  }
  return (void *)owner;
}

// Restore clPersistentCB primary at receiver-18, then dynamic secondary; raw EAX=loaded vbptr.
// R6GameService.dll @ 1004fe90 : complete native control/access order and raw ABI retained.
uint __fastcall RestoreExtendedVtableSubobject(void *secondary)
{
  uint owner = (uint)secondary - 0x18;
  uint offsetTable = *(uint *)(owner + 4);
  *(uint *)owner = R6GameServiceAddresses::clPersistentCBVTable;
  uint displacement = *(uint *)(offsetTable + 8);
  *(uint *)(owner + 4 + displacement) = R6GameServiceAddresses::clPersistentCBVTableAdjusted24;
  return offsetTable;
}

// Tail optional member+c with unchanged ECX/stack; NULL target returns EAX0 without arguments.
// R6GameService.dll @ 1004feb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclPersistentCBCallback0c(void *owner)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    je    Branch3
    jmp    eax
  Branch3:
    ret
  }
}

// If member+14 exists, load first word into ECX, rewrite its same stack slot and tail target with all5 words.
// NULL target returns EAX0/RET14 without reading arguments; preserve original tail stack/raw return.
// R6GameService.dll @ 1004fec0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclPersistentCBCallback14(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4,uint arg5)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x14]
    test    eax,eax
    je    Branch4
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch4:
    ret    0x14
  }
}

// Native virtual-table prefix: clPersistentCBVTableAdjusted24
// R6GameService.dll data @ 10077f58 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPersistentCBVTableAdjusted24Record {
  R6GameServiceNative::Address DeleteclPersistentCB; // +0x00
};
const clPersistentCBVTableAdjusted24Record clPersistentCBVTableAdjusted24 = {
  R6GameServiceAddresses::DeleteclPersistentCB,
};

// Native virtual-table prefix: clPersistentCBVTable
// R6GameService.dll data @ 10077f60 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPersistentCBVTableRecord {
  R6GameServiceNative::Address ForwardSharedCallback08; // +0x00
  R6GameServiceNative::Address ForwardclPersistentCBCallback0c; // +0x04
  R6GameServiceNative::Address ForwardclPersistentCBCallback14; // +0x08
  R6GameServiceNative::Address ForwardSharedCallback10; // +0x0c
};
const clPersistentCBVTableRecord clPersistentCBVTable = {
  R6GameServiceAddresses::ForwardSharedCallback08,
  R6GameServiceAddresses::ForwardclPersistentCBCallback0c,
  R6GameServiceAddresses::ForwardclPersistentCBCallback14,
  R6GameServiceAddresses::ForwardSharedCallback10,
};
