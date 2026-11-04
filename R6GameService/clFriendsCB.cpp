#include "native_addresses.h"
#include "native_records.h"

// RTTI establishes clFriendsCB ownership; method/argument names remain descriptive ABI approximations.
// Virtual allocator-base offsets are retained explicitly; no complete class declaration/layout is invented.

// clFriendsCB: optionally initialize virtual bases, install tables and zero callback words+8..+44.
// Preserve dynamic vbtable access order, receiver EAX/RET4 and zeroed saved-ECX word.
// R6GameService.dll @ 1004b850 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeServiceObjectVtablesAndStorage(
    void *owner,uint initializeVirtualBases)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch1
    mov    DWORD PTR [eax+0x4],0x10077e54
    mov    DWORD PTR [eax+0x4c],0x10077e4c
    mov    DWORD PTR [eax+0x48],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
  Branch1:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clFriendsCBVTable
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+eax*1+0x4],R6GameServiceAddresses::clFriendsCBVTableAdjusted72
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [eax+0x10],ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    DWORD PTR [eax+0x18],ecx
    mov    DWORD PTR [eax+0x1c],ecx
    mov    DWORD PTR [eax+0x20],ecx
    mov    DWORD PTR [eax+0x24],ecx
    mov    DWORD PTR [eax+0x28],ecx
    mov    DWORD PTR [eax+0x2c],ecx
    mov    DWORD PTR [eax+0x30],ecx
    mov    DWORD PTR [eax+0x34],ecx
    mov    DWORD PTR [eax+0x38],ecx
    mov    DWORD PTR [eax+0x3c],ecx
    mov    DWORD PTR [eax+0x40],ecx
    mov    DWORD PTR [eax+0x44],ecx
    pop    ecx
    ret    0x4
  }
}

// clFriendsCB: restore tables from adjusted virtual base+48, install allocator-base table and optionally free owner.
// Only flag BYTE bit0 selects freeing; always return complete owner and RET4, with no local EH guard.
// R6GameService.dll @ 1004b8c0 : complete native control/access order and raw ABI retained.
void *__thiscall DestroyServiceObjectAtAdjustedSubobject(void *secondary,byte deletionFlags)
{
  uint owner = (uint)secondary - 0x48;
  void *fixedBase = (void *)(owner + 0x48);
  using RestoreABI = uint (__fastcall *)(void *);
  ((RestoreABI)R6GameServiceAddresses::RestoreServiceObjectBaseVtables)(fixedBase);
  byte flags = *(byte *)&deletionFlags;
  *(uint *)fixedBase = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  if ((flags & 1) != 0) {
    using FreeABI = uint (__stdcall *)(void *);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)owner);
  }
  return (void *)owner;
}

// clFriendsCB: from adjusted virtual base, load vbptr then restore primary and dynamic secondary tables.
// Read dynamic offset after primary store; retain raw EAX=vbptr and unchanged adjusted ECX.
// R6GameService.dll @ 1004b8f0 : complete native control/access order and raw ABI retained.
uint __fastcall RestoreServiceObjectBaseVtables(void *secondary)
{
  uint owner = (uint)secondary - 0x48;
  uint offsetTable = *(uint *)(owner + 4);
  *(uint *)owner = R6GameServiceAddresses::clFriendsCBVTable;
  uint displacement = *(uint *)(offsetTable + 8);
  *(uint *)(owner + 4 + displacement) = R6GameServiceAddresses::clFriendsCBVTableAdjusted72;
  return offsetTable;
}

// Tail-forward owner+c callback with 3 stack words; NULL returns EAX0/RETc.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b930 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback0c(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    je    Branch3
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch3:
    ret    0xc
  }
}

// Tail-forward owner+14 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback14(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x14]
    test    eax,eax
    je    Branch4
    jmp    eax
  Branch4:
    ret    0x8
  }
}

// Tail-forward owner+1c callback with 1 stack words; NULL returns EAX0/RET4.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b980 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback1c(void *owner,uint arg1)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x1c]
    test    eax,eax
    je    Branch5
    jmp    eax
  Branch5:
    ret    0x4
  }
}

// Tail-forward owner+20 callback with 1 stack words; NULL returns EAX0/RET4.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback20(void *owner,uint arg1)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x20]
    test    eax,eax
    je    Branch6
    jmp    eax
  Branch6:
    ret    0x4
  }
}

// Tail-forward owner+24 callback with 3 stack words; NULL returns EAX0/RETc.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b9a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback24(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x24]
    test    eax,eax
    je    Branch7
    jmp    eax
  Branch7:
    ret    0xc
  }
}

// Tail-forward owner+28 callback with 3 stack words; NULL returns EAX0/RETc.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b9b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback28(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x28]
    test    eax,eax
    je    Branch8
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch8:
    ret    0xc
  }
}

// Tail-forward owner+2c callback with 3 stack words; NULL returns EAX0/RETc.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b9d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback2c(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x2c]
    test    eax,eax
    je    Branch9
    jmp    eax
  Branch9:
    ret    0xc
  }
}

// Tail-forward owner+30 callback with 3 stack words; NULL returns EAX0/RETc.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004b9e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback30(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x30]
    test    eax,eax
    je    Branch10
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch10:
    ret    0xc
  }
}

// Tail-forward owner+34 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004ba00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback34(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x34]
    test    eax,eax
    je    Branch11
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch11:
    ret    0x8
  }
}

// Tail-forward owner+38 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004ba20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback38(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x38]
    test    eax,eax
    je    Branch12
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch12:
    ret    0x8
  }
}

// Tail-forward owner+3c callback with 6 stack words; NULL returns EAX0/RET18.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004ba40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback3c(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4,uint arg5,uint arg6)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x3c]
    test    eax,eax
    je    Branch13
    jmp    eax
  Branch13:
    ret    0x18
  }
}

// Tail-forward owner+40 callback with 5 stack words; NULL returns EAX0/RET14.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004ba50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback40(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4,uint arg5)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x40]
    test    eax,eax
    je    Branch14
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch14:
    ret    0x14
  }
}

// Tail-forward owner+44 callback with 5 stack words; NULL returns EAX0/RET14.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004ba70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclFriendsCBCallback44(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4,uint arg5)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x44]
    test    eax,eax
    je    Branch15
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch15:
    ret    0x14
  }
}

// Native virtual-table prefix: clFriendsCBVTableAdjusted72
// R6GameService.dll data @ 10077e00 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clFriendsCBVTableAdjusted72Record {
  R6GameServiceNative::Address DestroyServiceObjectAtAdjustedSubobject; // +0x00
};
const clFriendsCBVTableAdjusted72Record clFriendsCBVTableAdjusted72 = {
  R6GameServiceAddresses::DestroyServiceObjectAtAdjustedSubobject,
};

// Native virtual-table prefix: clFriendsCBVTable
// R6GameService.dll data @ 10077e0c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clFriendsCBVTableRecord {
  R6GameServiceNative::Address ForwardSharedCallback08; // +0x00
  R6GameServiceNative::Address ForwardclFriendsCBCallback0c; // +0x04
  R6GameServiceNative::Address ForwardSharedCallback10; // +0x08
  R6GameServiceNative::Address ForwardclFriendsCBCallback14; // +0x0c
  R6GameServiceNative::Address ForwardSharedCallback18; // +0x10
  R6GameServiceNative::Address ForwardclFriendsCBCallback1c; // +0x14
  R6GameServiceNative::Address ForwardclFriendsCBCallback20; // +0x18
  R6GameServiceNative::Address ForwardclFriendsCBCallback24; // +0x1c
  R6GameServiceNative::Address ForwardclFriendsCBCallback28; // +0x20
  R6GameServiceNative::Address ForwardclFriendsCBCallback2c; // +0x24
  R6GameServiceNative::Address ForwardclFriendsCBCallback30; // +0x28
  R6GameServiceNative::Address ForwardclFriendsCBCallback34; // +0x2c
  R6GameServiceNative::Address ForwardclFriendsCBCallback38; // +0x30
  R6GameServiceNative::Address ForwardclFriendsCBCallback3c; // +0x34
  R6GameServiceNative::Address ForwardclFriendsCBCallback40; // +0x38
  R6GameServiceNative::Address ForwardclFriendsCBCallback44; // +0x3c
};
const clFriendsCBVTableRecord clFriendsCBVTable = {
  R6GameServiceAddresses::ForwardSharedCallback08,
  R6GameServiceAddresses::ForwardclFriendsCBCallback0c,
  R6GameServiceAddresses::ForwardSharedCallback10,
  R6GameServiceAddresses::ForwardclFriendsCBCallback14,
  R6GameServiceAddresses::ForwardSharedCallback18,
  R6GameServiceAddresses::ForwardclFriendsCBCallback1c,
  R6GameServiceAddresses::ForwardclFriendsCBCallback20,
  R6GameServiceAddresses::ForwardclFriendsCBCallback24,
  R6GameServiceAddresses::ForwardclFriendsCBCallback28,
  R6GameServiceAddresses::ForwardclFriendsCBCallback2c,
  R6GameServiceAddresses::ForwardclFriendsCBCallback30,
  R6GameServiceAddresses::ForwardclFriendsCBCallback34,
  R6GameServiceAddresses::ForwardclFriendsCBCallback38,
  R6GameServiceAddresses::ForwardclFriendsCBCallback3c,
  R6GameServiceAddresses::ForwardclFriendsCBCallback40,
  R6GameServiceAddresses::ForwardclFriendsCBCallback44,
};
