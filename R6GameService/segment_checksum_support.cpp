#include "native_addresses.h"

// Shared segment checksum view; original class/member ownership remains unresolved.

// Cache count14 and seed destination18; write low seedWORD, then reload count14 for signed parity and pointer10 for reads.
// Sum signed leading byte if odd, then unsigned WORDs using cached signed SAR1 count; fold twice/complement full EAX.
// Return full32 checksum/RET4; only seed is written, with no final checksum store, pointer equality assumption or local EH.
// R6GameService.dll @ 1005dfc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ComputeSeededRecordChecksum(void *record,uint seedWord)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x14]
    push    esi
    mov    esi,DWORD PTR [ecx+0x18]
    push    edi
    mov    di,WORD PTR [esp+0xc]
    xor    eax,eax
    mov    WORD PTR [esi],di
    mov    esi,DWORD PTR [ecx+0x14]
    sar    edx,1
    and    esi,0x80000001
    jns    Branch1
    dec    esi
    or    esi,0xfffffffe
    inc    esi
  Branch1:
    mov    ecx,DWORD PTR [ecx+0x10]
    je    Branch2
    movsx    eax,BYTE PTR [ecx]
    inc    ecx
  Branch2:
    test    edx,edx
    jle    Branch4
  Branch3:
    xor    esi,esi
    mov    si,WORD PTR [ecx]
    add    ecx,0x2
    add    eax,esi
    dec    edx
    jne    Branch3
  Branch4:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    pop    edi
    mov    eax,ecx
    pop    esi
    shr    eax,0x10
    add    eax,ecx
    not    eax
    ret    0x4
  }
}
