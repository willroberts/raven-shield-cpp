#include "native_addresses.h"
#include "native_records.h"

// RTTI identifies clLobbyCB; method spellings and incomplete layout remain descriptive approximations.

// Optionally install virtual-base tables, then primary/adjusted clLobbyCB vtables and native zero fields.
// Keep original store order, untouched+5c, current offset-table read, saved-slot overwrite and final ECX0; no own EH.
// R6GameService.dll @ 10052780 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeServiceStateBlock(void *owner,uint initializeTables)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch1
    mov    DWORD PTR [eax+0x4],0x10078054
    mov    DWORD PTR [eax+0xbc],0x1007804c
    mov    DWORD PTR [eax+0xb8],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
  Branch1:
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clLobbyCBVTable
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+eax*1+0x4],R6GameServiceAddresses::clLobbyCBVTableAdjusted184
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    DWORD PTR [eax+0x10],ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    DWORD PTR [eax+0x18],ecx
    mov    DWORD PTR [eax+0x1c],ecx
    mov    DWORD PTR [eax+0x20],ecx
    mov    DWORD PTR [eax+0x24],ecx
    mov    DWORD PTR [eax+0x28],ecx
    mov    DWORD PTR [eax+0x30],ecx
    mov    DWORD PTR [eax+0x2c],ecx
    mov    DWORD PTR [eax+0x34],ecx
    mov    DWORD PTR [eax+0x38],ecx
    mov    DWORD PTR [eax+0x40],ecx
    mov    DWORD PTR [eax+0x3c],ecx
    mov    DWORD PTR [eax+0x44],ecx
    mov    DWORD PTR [eax+0x48],ecx
    mov    DWORD PTR [eax+0x4c],ecx
    mov    DWORD PTR [eax+0x50],ecx
    mov    DWORD PTR [eax+0x54],ecx
    mov    DWORD PTR [eax+0x58],ecx
    mov    DWORD PTR [eax+0x60],ecx
    mov    DWORD PTR [eax+0x64],ecx
    mov    DWORD PTR [eax+0x68],ecx
    mov    DWORD PTR [eax+0x6c],ecx
    mov    DWORD PTR [eax+0x70],ecx
    mov    DWORD PTR [eax+0x74],ecx
    mov    DWORD PTR [eax+0x78],ecx
    mov    DWORD PTR [eax+0x7c],ecx
    mov    DWORD PTR [eax+0x80],ecx
    mov    DWORD PTR [eax+0x84],ecx
    mov    DWORD PTR [eax+0x88],ecx
    mov    DWORD PTR [eax+0x8c],ecx
    mov    DWORD PTR [eax+0x90],ecx
    mov    DWORD PTR [eax+0x94],ecx
    mov    DWORD PTR [eax+0x98],ecx
    mov    DWORD PTR [eax+0x9c],ecx
    mov    DWORD PTR [eax+0xa0],ecx
    mov    DWORD PTR [eax+0xa4],ecx
    mov    DWORD PTR [eax+0xa8],ecx
    mov    DWORD PTR [eax+0xac],ecx
    mov    DWORD PTR [eax+0xb0],ecx
    mov    DWORD PTR [eax+0xb4],ecx
    pop    ecx
    ret    0x4
  }
}

// Capture owner=secondary-b8, reset base tables, restore fixed secondary allocator-base vtable, then read late flagBYTE.
// Bit0 frees captured owner; return that owner regardless of free EAX. RET4, no local guard or member destruction.
// R6GameService.dll @ 10052870 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteClLobbyCBFromSecondary(void *secondary,uint deleteFlags)
{
  __asm {
    push    esi
    lea    esi,[ecx-0xb8]
    push    edi
    lea    edi,[esi+0xb8]
    mov    ecx,edi
    call    R6GameServiceAddresses::RestoreBaseSubobjectVtables
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

// Capture offset table atsecondary-b4, reset primary atsecondary-b8, then read captured table+8 for adjusted reset.
// Return the raw captured table pointer in EAX; do not clear members or register a local exception frame.
// R6GameService.dll @ 100528a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RestoreBaseSubobjectVtables(void *secondary)
{
  __asm {
    mov    eax,DWORD PTR [ecx-0xb4]
    mov    DWORD PTR [ecx-0xb8],R6GameServiceAddresses::clLobbyCBVTable
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [edx+ecx*1-0xb4],R6GameServiceAddresses::clLobbyCBVTableAdjusted184
    ret
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100528c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardLobbyCallback(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xc]
    test eax,eax
    je    Branch3
    jmp eax
  Branch3:
    ret 0x4
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100528d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x10]
    test eax,eax
    je    Branch4
    jmp eax
  Branch4:
    ret
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100528e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback2(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x18]
    test eax,eax
    je    Branch5
    mov ecx,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],ecx
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch5:
    ret 0x54
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052900 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback3(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x14]
    test eax,eax
    je    Branch6
    mov ecx,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],ecx
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch6:
    ret 0x3c
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052920 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback4(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x20]
    test eax,eax
    je    Branch7
    mov ecx,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],ecx
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch7:
    ret 0x54
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052940 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback5(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x1c]
    test eax,eax
    je    Branch8
    mov ecx,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],ecx
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch8:
    ret 0x3c
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052960 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback6(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x24]
    test eax,eax
    je    Branch9
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch9:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052980 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback7(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x28]
    test eax,eax
    je    Branch10
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch10:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100529a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback8(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x2c]
    test eax,eax
    je    Branch11
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch11:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100529c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback9(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x30]
    test eax,eax
    je    Branch12
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch12:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 100529e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback10(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x34]
    test eax,eax
    je    Branch13
    mov ecx,DWORD PTR [esp+0x30]
    mov edx,DWORD PTR [esp+0x2c]
    mov DWORD PTR [esp+0x30],ecx
    mov ecx,DWORD PTR [esp+0x20]
    mov DWORD PTR [esp+0x20],ecx
    mov ecx,DWORD PTR [esp+0x10]
    mov DWORD PTR [esp+0x10],ecx
    mov ecx,DWORD PTR [esp+0x8]
    mov DWORD PTR [esp+0x2c],edx
    mov DWORD PTR [esp+0x8],ecx
    jmp eax
  Branch13:
    ret 0x30
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback11(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x38]
    test eax,eax
    je    Branch14
    jmp eax
  Branch14:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback12(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x3c]
    test eax,eax
    je    Branch15
    jmp eax
  Branch15:
    ret 0x8
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback13(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x40]
    test eax,eax
    je    Branch16
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch16:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback14(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x44]
    test eax,eax
    je    Branch17
    jmp eax
  Branch17:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback15(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x48]
    test eax,eax
    je    Branch18
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch18:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052a90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback16(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x4c]
    test eax,eax
    je    Branch19
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch19:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback17(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x50]
    test eax,eax
    je    Branch20
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch20:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback18(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x54]
    test eax,eax
    je    Branch21
    jmp eax
  Branch21:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback19(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x58]
    test eax,eax
    je    Branch22
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch22:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback20(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x5c]
    test eax,eax
    je    Branch23
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch23:
    ret 0x18
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback21(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x60]
    test eax,eax
    je    Branch24
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch24:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback22(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x64]
    test eax,eax
    je    Branch25
    jmp eax
  Branch25:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback23(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x68]
    test eax,eax
    je    Branch26
    jmp eax
  Branch26:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback24(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x6c]
    test eax,eax
    je    Branch27
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch27:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052b80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback25(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x70]
    test eax,eax
    je    Branch28
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch28:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ba0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback26(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x74]
    test eax,eax
    je    Branch29
    mov ecx,DWORD PTR [esp+0x10]
    mov DWORD PTR [esp+0x10],ecx
    jmp eax
  Branch29:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback27(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x78]
    test eax,eax
    je    Branch30
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch30:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052be0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback28(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x7c]
    test eax,eax
    je    Branch31
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch31:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052c00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback29(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x80]
    test eax,eax
    je    Branch32
    mov ecx,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],ecx
    jmp eax
  Branch32:
    ret 0x1c
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052c20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback30(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x84]
    test eax,eax
    je    Branch33
    mov ecx,DWORD PTR [esp+0x10]
    mov DWORD PTR [esp+0x10],ecx
    jmp eax
  Branch33:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052c40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback31(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x88]
    test eax,eax
    je    Branch34
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch34:
    ret 0x10
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052c60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback32(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x8c]
    test eax,eax
    je    Branch35
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch35:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052c80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback33(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x90]
    test eax,eax
    je    Branch36
    mov ecx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],ecx
    jmp eax
  Branch36:
    ret 0x14
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ca0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback34(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x94]
    test eax,eax
    je    Branch37
    jmp eax
  Branch37:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback35(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x98]
    test eax,eax
    je    Branch38
    jmp eax
  Branch38:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052cc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback36(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0x9c]
    test eax,eax
    je    Branch39
    jmp eax
  Branch39:
    ret 0x8
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052cd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback37(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xa0]
    test eax,eax
    je    Branch40
    jmp eax
  Branch40:
    ret 0x4
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback38(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xa4]
    test eax,eax
    je    Branch41
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp eax
  Branch41:
    ret 0x8
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052d00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback39(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xa8]
    test eax,eax
    je    Branch42
    jmp eax
  Branch42:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052d10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback40(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xac]
    test eax,eax
    je    Branch43
    jmp eax
  Branch43:
    ret 0xc
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052d20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback41(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xb0]
    test eax,eax
    je    Branch44
    mov ecx,DWORD PTR [esp+0x8]
    mov DWORD PTR [esp+0x8],ecx
    jmp eax
  Branch44:
    ret 0x8
  }
}

// If current clLobbyCB callback is present, tail-forward with native argument self-accesses and register residue.
// Null callback returns EAX0 with its exact stack pop; callback owns nonnull cleanup/return. Event name unresolved.
// R6GameService.dll @ 10052d40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clLobbyCB_ForwardLobbyCallback42(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [ecx+0xb4]
    test eax,eax
    je    Branch45
    mov edx,DWORD PTR [esp+0x8]
    mov DWORD PTR [esp+0x8],edx
    jmp eax
  Branch45:
    ret 0x14
  }
}

// Native virtual-table prefix: clLobbyCBVTableAdjusted184
// R6GameService.dll data @ 10077f90 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLobbyCBVTableAdjusted184Record {
  R6GameServiceNative::Address DeleteClLobbyCBFromSecondary; // +0x00
};
const clLobbyCBVTableAdjusted184Record clLobbyCBVTableAdjusted184 = {
  R6GameServiceAddresses::DeleteClLobbyCBFromSecondary,
};

// Native virtual-table prefix: clLobbyCBVTable
// R6GameService.dll data @ 10077f9c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clLobbyCBVTableRecord {
  R6GameServiceNative::Address ForwardSharedCallback08; // +0x00
  R6GameServiceNative::Address ForwardLobbyCallback; // +0x04
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback; // +0x08
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback7; // +0x0c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback8; // +0x10
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback9; // +0x14
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback2; // +0x18
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback3; // +0x1c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback4; // +0x20
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback5; // +0x24
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback6; // +0x28
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback12; // +0x2c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback10; // +0x30
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback11; // +0x34
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback13; // +0x38
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback15; // +0x3c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback14; // +0x40
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback16; // +0x44
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback18; // +0x48
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback17; // +0x4c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback19; // +0x50
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback20; // +0x54
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback21; // +0x58
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback22; // +0x5c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback23; // +0x60
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback24; // +0x64
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback25; // +0x68
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback26; // +0x6c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback27; // +0x70
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback28; // +0x74
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback29; // +0x78
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback30; // +0x7c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback31; // +0x80
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback32; // +0x84
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback33; // +0x88
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback34; // +0x8c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback35; // +0x90
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback36; // +0x94
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback37; // +0x98
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback38; // +0x9c
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback39; // +0xa0
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback40; // +0xa4
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback41; // +0xa8
  R6GameServiceNative::Address clLobbyCB_ForwardLobbyCallback42; // +0xac
};
const clLobbyCBVTableRecord clLobbyCBVTable = {
  R6GameServiceAddresses::ForwardSharedCallback08,
  R6GameServiceAddresses::ForwardLobbyCallback,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback7,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback8,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback9,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback2,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback3,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback4,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback5,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback6,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback12,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback10,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback11,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback13,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback15,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback14,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback16,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback18,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback17,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback19,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback20,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback21,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback22,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback23,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback24,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback25,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback26,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback27,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback28,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback29,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback30,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback31,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback32,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback33,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback34,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback35,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback36,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback37,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback38,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback39,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback40,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback41,
  R6GameServiceAddresses::clLobbyCB_ForwardLobbyCallback42,
};
