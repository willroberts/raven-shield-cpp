#include "native_addresses.h"
#include "native_records.h"

// RTTI establishes clLoginCB ownership; method/argument names remain descriptive ABI approximations.
// Virtual allocator-base offsets are retained explicitly; no complete class declaration/layout is invented.

// clLoginCB: optionally initialize virtual bases, install tables and zero callback words+8..+28.
// Preserve dynamic vbtable access order, receiver EAX/RET4 and zeroed saved-ECX word.
// R6GameService.dll @ 1004ba90 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeServiceVtablesAndStorage(void *owner,uint initializeVirtualBases)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch1
    mov    DWORD PTR [eax+0x4],0x10077e98
    mov    DWORD PTR [eax+0x30],0x10077e90
    mov    DWORD PTR [eax+0x2c],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
  Branch1:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clLoginCBVTable
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+eax*1+0x4],R6GameServiceAddresses::clLoginCBVTableAdjusted44
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [eax+0x10],ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    DWORD PTR [eax+0x18],ecx
    mov    DWORD PTR [eax+0x1c],ecx
    mov    DWORD PTR [eax+0x20],ecx
    mov    DWORD PTR [eax+0x24],ecx
    mov    DWORD PTR [eax+0x28],ecx
    pop    ecx
    ret    0x4
  }
}

// clLoginCB: restore tables from adjusted virtual base+2c, install allocator-base table and optionally free owner.
// Only flag BYTE bit0 selects freeing; always return complete owner and RET4, with no local EH guard.
// R6GameService.dll @ 1004baf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall clLoginCB_DestroyServiceObjectAtAdjustedSubobject(
    void *adjustedVirtualBase,byte deletionFlags)
{
  __asm {
    push    esi
    lea    esi,[ecx-0x2c]
    push    edi
    lea    edi,[esi+0x2c]
    mov    ecx,edi
    call    R6GameServiceAddresses::RestoreServiceBaseVtables
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

// clLoginCB: from adjusted virtual base, load vbptr then restore primary and dynamic secondary tables.
// Read dynamic offset after primary store; retain raw EAX=vbptr and unchanged adjusted ECX.
// R6GameService.dll @ 1004bb20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall RestoreServiceBaseVtables(void *adjustedVirtualBase)
{
  __asm {
    mov    eax,DWORD PTR [ecx-0x28]
    mov    DWORD PTR [ecx-0x2c],R6GameServiceAddresses::clLoginCBVTable
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [edx+ecx*1-0x28],R6GameServiceAddresses::clLoginCBVTableAdjusted44
    ret
  }
}

// Tail-forward owner+8 callback with 9 stack words; NULL returns EAX0/RET24.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bb40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback08(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4,uint arg5,uint arg6,uint arg7,uint arg8,uint arg9)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x8]
    test    eax,eax
    je    Branch3
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch3:
    ret    0x24
  }
}

// Tail-forward owner+c callback with 4 stack words; NULL returns EAX0/RET10.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bb60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback0c(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    je    Branch4
    mov    edx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0xc],edx
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch4:
    ret    0x10
  }
}

// Tail-forward owner+10 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bb80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback10(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x10]
    test    eax,eax
    je    Branch5
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch5:
    ret    0x8
  }
}

// Tail-forward owner+14 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bba0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback14(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x14]
    test    eax,eax
    je    Branch6
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch6:
    ret    0x8
  }
}

// Tail-forward owner+1c callback with 0 stack words; NULL returns EAX0/RET0.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bbd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback1c(void *owner)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x1c]
    test    eax,eax
    je    Branch7
    jmp    eax
  Branch7:
    ret
  }
}

// Tail-forward owner+20 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bbe0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback20(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x20]
    test    eax,eax
    je    Branch8
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch8:
    ret    0x8
  }
}

// Tail-forward owner+24 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bc00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback24(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x24]
    test    eax,eax
    je    Branch9
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch9:
    ret    0x8
  }
}

// Tail-forward owner+28 callback with 4 stack words; NULL returns EAX0/RET10.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bc20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardclLoginCBCallback28(
    void *owner,uint arg1,uint arg2,uint arg3,uint arg4)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x28]
    test    eax,eax
    je    Branch10
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch10:
    ret    0x10
  }
}

// Native virtual-table prefix: clLoginCBVTableAdjusted44
// R6GameService.dll data @ 10077e64 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLoginCBVTableAdjusted44Record {
  R6GameServiceNative::Address clLoginCB_DestroyServiceObjectAtAdjustedSubobject; // +0x00
};
const clLoginCBVTableAdjusted44Record clLoginCBVTableAdjusted44 = {
  R6GameServiceAddresses::clLoginCB_DestroyServiceObjectAtAdjustedSubobject,
};

// Native virtual-table prefix: clLoginCBVTable
// R6GameService.dll data @ 10077e6c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLoginCBVTableRecord {
  R6GameServiceNative::Address ForwardclLoginCBCallback08; // +0x00
  R6GameServiceNative::Address ForwardclLoginCBCallback0c; // +0x04
  R6GameServiceNative::Address ForwardclLoginCBCallback10; // +0x08
  R6GameServiceNative::Address ForwardclLoginCBCallback14; // +0x0c
  R6GameServiceNative::Address ForwardSharedCallback18; // +0x10
  R6GameServiceNative::Address ForwardclLoginCBCallback1c; // +0x14
  R6GameServiceNative::Address ForwardclLoginCBCallback20; // +0x18
  R6GameServiceNative::Address ForwardclLoginCBCallback24; // +0x1c
  R6GameServiceNative::Address ForwardclLoginCBCallback28; // +0x20
};
const clLoginCBVTableRecord clLoginCBVTable = {
  R6GameServiceAddresses::ForwardclLoginCBCallback08,
  R6GameServiceAddresses::ForwardclLoginCBCallback0c,
  R6GameServiceAddresses::ForwardclLoginCBCallback10,
  R6GameServiceAddresses::ForwardclLoginCBCallback14,
  R6GameServiceAddresses::ForwardSharedCallback18,
  R6GameServiceAddresses::ForwardclLoginCBCallback1c,
  R6GameServiceAddresses::ForwardclLoginCBCallback20,
  R6GameServiceAddresses::ForwardclLoginCBCallback24,
  R6GameServiceAddresses::ForwardclLoginCBCallback28,
};
