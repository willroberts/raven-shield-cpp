#include "native_addresses.h"

// Shared native compression support. Names/types are inferred; explicit fields, frame scratch and raw ABI retained.

// Compute Adler sums in 5,552-byte batches; NULL returns 1 and non-NULL empty input retains its seed.
// R6GameService.dll @ 100202f0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall Adler32Checksum(uint checksum,const void *data,uint length)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    ecx,edi
    and    ecx,0xffff
    shr    edi,0x10
    test   esi,esi
    jne    Branch1
    pop    edi
    mov    eax,0x1
    pop    esi
    ret    0xc
  Branch1:
    push   ebx
    mov    ebx,DWORD PTR [esp+0x18]
    test   ebx,ebx
    jbe    Branch8
    push   ebp
  Branch2:
    cmp    ebx,0x15b0
    mov    eax,ebx
    jb     Branch3
    mov    eax,0x15b0
  Branch3:
    sub    ebx,eax
    cmp    eax,0x10
    jl     Branch5
    mov    ebp,eax
    shr    ebp,0x4
    mov    edx,ebp
    neg    edx
    shl    edx,0x4
    add    eax,edx
  Branch4:
    xor    edx,edx
    mov    dl,BYTE PTR [esi]
    add    esi,0x10
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xf]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xe]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xd]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xc]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xb]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0xa]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x9]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x8]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x7]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x6]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x5]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x4]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x3]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x2]
    add    edi,ecx
    add    ecx,edx
    xor    edx,edx
    mov    dl,BYTE PTR [esi-0x1]
    add    edi,ecx
    add    ecx,edx
    add    edi,ecx
    dec    ebp
    jne    Branch4
  Branch5:
    test   eax,eax
    je     Branch7
  Branch6:
    xor    edx,edx
    mov    dl,BYTE PTR [esi]
    add    ecx,edx
    inc    esi
    add    edi,ecx
    dec    eax
    jne    Branch6
  Branch7:
    mov    eax,ecx
    xor    edx,edx
    mov    ecx,0xfff1
    div    ecx
    mov    eax,edi
    mov    edi,0xfff1
    mov    ecx,edx
    xor    edx,edx
    div    edi
    test   ebx,ebx
    mov    edi,edx
    ja     Branch2
    pop    ebp
  Branch8:
    mov    eax,edi
    pop    ebx
    shl    eax,0x10
    pop    edi
    or     eax,ecx
    pop    esi
    ret    0xc
  }
}
