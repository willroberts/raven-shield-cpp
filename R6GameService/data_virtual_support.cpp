#include "native_addresses.h"

// Shared native virtual/import dispatch; original wrapper class identities remain unresolved.

// Load nested payload at receiver0c and tail-call its current virtual slot; no null check, frame or argument rewrite.
// Shared by scalar descriptor tables76ad4/76af8/76b1c; concrete owning wrapper class remains unresolved.
// R6GameService.dll @ 1002afa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardDataPayloadVirtual(void *receiver)
{
  __asm {
    mov ecx,DWORD PTR [ecx+0xc]
    mov eax,DWORD PTR [ecx]
    jmp DWORD PTR [eax+0x4]
  }
}

// Load nested payload at receiver0c and tail-call its current virtual slot; no null check, frame or argument rewrite.
// Shared by scalar descriptor tables76ad4/76af8/76b1c; concrete owning wrapper class remains unresolved.
// R6GameService.dll @ 1002afb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall data_virtual_support_ForwardDataPayloadVirtual(void *receiver)
{
  __asm {
    mov ecx,DWORD PTR [ecx+0xc]
    mov eax,DWORD PTR [ecx]
    jmp DWORD PTR [eax+0x8]
  }
}

// Load nested payload at receiver0c and tail-call its current virtual slot; no null check, frame or argument rewrite.
// Shared by scalar descriptor tables76ad4/76af8/76b1c; concrete owning wrapper class remains unresolved.
// R6GameService.dll @ 1002afc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall data_virtual_support_ForwardDataPayloadVirtual2(void *receiver)
{
  __asm {
    mov ecx,DWORD PTR [ecx+0xc]
    mov eax,DWORD PTR [ecx]
    jmp DWORD PTR [eax+0x10]
  }
}

// Load nested payload at receiver0c and tail-call its current virtual slot; no null check, frame or argument rewrite.
// Shared by scalar descriptor tables76ad4/76af8/76b1c; concrete owning wrapper class remains unresolved.
// R6GameService.dll @ 1002afd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall data_virtual_support_ForwardDataPayloadVirtual3(void *receiver)
{
  __asm {
    mov ecx,DWORD PTR [ecx+0xc]
    mov eax,DWORD PTR [ecx]
    jmp DWORD PTR [eax+0xc]
  }
}

// Load nested payload at receiver0c and tail-call its current virtual slot; no null check, frame or argument rewrite.
// Shared by scalar descriptor tables76ad4/76af8/76b1c; concrete owning wrapper class remains unresolved.
// R6GameService.dll @ 1002afe0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall data_virtual_support_ForwardDataPayloadVirtual4(void *receiver)
{
  __asm {
    mov ecx,DWORD PTR [ecx+0xc]
    mov eax,DWORD PTR [ecx]
    jmp DWORD PTR [eax+0x14]
  }
}
