#include "native_addresses.h"

// Shared native compression support. Names/types are inferred; explicit fields, frame scratch and raw ABI retained.

// Advance framing, selected compression, flush markers and pending output with native status returns.
// R6GameService.dll @ 1001e4e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DeflateStreamStep(void *stream,int flush)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   ebp
    push   esi
    test   ebx,ebx
    push   edi
    je     Branch23
    mov    esi,DWORD PTR [ebx+0x1c]
    test   esi,esi
    je     Branch23
    mov    ebp,DWORD PTR [esp+0x18]
    cmp    ebp,0x4
    jg     Branch23
    test   ebp,ebp
    jl     Branch23
    mov    eax,DWORD PTR [ebx+0xc]
    test   eax,eax
    je     Branch22
    cmp    DWORD PTR [ebx],0x0
    jne    Branch1
    mov    eax,DWORD PTR [ebx+0x4]
    test   eax,eax
    jne    Branch22
  Branch1:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    eax,0x29a
    jne    Branch2
    cmp    ebp,0x4
    jne    Branch22
  Branch2:
    mov    ecx,DWORD PTR [ebx+0x10]
    test   ecx,ecx
    jne    Branch3
    mov    eax,ds:0x1008c850
    pop    edi
    pop    esi
    mov    DWORD PTR [ebx+0x18],eax
    pop    ebp
    mov    eax,0xfffffffb
    pop    ebx
    ret    0x8
  Branch3:
    mov    ecx,DWORD PTR [esi+0x20]
    cmp    eax,0x2a
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esi+0x20],ebp
    jne    Branch7
    mov    ecx,DWORD PTR [esi+0x28]
    mov    eax,DWORD PTR [esi+0x7c]
    shl    ecx,0xc
    sub    ecx,0x7800
    dec    eax
    sar    eax,1
    cmp    eax,0x3
    jbe    Branch4
    mov    eax,0x3
  Branch4:
    shl    eax,0x6
    or     ecx,eax
    mov    eax,DWORD PTR [esi+0x64]
    test   eax,eax
    je     Branch5
    or     ecx,0x20
  Branch5:
    mov    eax,ecx
    xor    edx,edx
    mov    edi,0x1f
    mov    DWORD PTR [esi+0x4],0x71
    div    edi
    sub    ecx,edx
    add    ecx,edi
    push   ecx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateBigEndianWord
    mov    eax,DWORD PTR [esi+0x64]
    test   eax,eax
    je     Branch6
    xor    edx,edx
    mov    dx,WORD PTR [ebx+0x32]
    push   edx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateBigEndianWord
    mov    eax,DWORD PTR [ebx+0x30]
    and    eax,0xffff
    push   eax
    push   esi
    call   R6GameServiceAddresses::WriteDeflateBigEndianWord
  Branch6:
    mov    DWORD PTR [ebx+0x30],0x1
  Branch7:
    mov    eax,DWORD PTR [esi+0x14]
    test   eax,eax
    je     Branch8
    push   ebx
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    eax,DWORD PTR [ebx+0x10]
    test   eax,eax
    jne    Branch9
    mov    DWORD PTR [esi+0x20],0xffffffff
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch8:
    mov    eax,DWORD PTR [ebx+0x4]
    test   eax,eax
    jne    Branch9
    cmp    ebp,DWORD PTR [esp+0x14]
    jg     Branch9
    cmp    ebp,0x4
    je     Branch9
    mov    ecx,DWORD PTR ds:0x1008c850
    pop    edi
    pop    esi
    mov    DWORD PTR [ebx+0x18],ecx
    pop    ebp
    mov    eax,0xfffffffb
    pop    ebx
    ret    0x8
  Branch9:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [ebx+0x4]
    cmp    eax,0x29a
    jne    Branch10
    test   ecx,ecx
    je     Branch11
    mov    edx,DWORD PTR ds:0x1008c850
    pop    edi
    pop    esi
    mov    DWORD PTR [ebx+0x18],edx
    pop    ebp
    mov    eax,0xfffffffb
    pop    ebx
    ret    0x8
  Branch10:
    test   ecx,ecx
    jne    Branch12
  Branch11:
    mov    ecx,DWORD PTR [esi+0x6c]
    test   ecx,ecx
    jne    Branch12
    test   ebp,ebp
    je     Branch17
    cmp    eax,0x29a
    je     Branch17
  Branch12:
    mov    eax,DWORD PTR [esi+0x7c]
    push   ebp
    push   esi
    lea    eax,[eax+eax*2]
    call   DWORD PTR [eax*4+R6GameServiceAddresses::DeflateLevelConfigurationCompressor]
    cmp    eax,0x2
    je     Branch13
    cmp    eax,0x3
    jne    Branch14
  Branch13:
    mov    DWORD PTR [esi+0x4],0x29a
  Branch14:
    test   eax,eax
    je     Branch20
    cmp    eax,0x2
    je     Branch20
    cmp    eax,0x1
    jne    Branch17
    cmp    ebp,eax
    jne    Branch15
    push   esi
    call   R6GameServiceAddresses::EmitDeflateFlushBits
    jmp    Branch16
  Branch15:
    push   0x0
    push   0x0
    push   0x0
    push   esi
    call   R6GameServiceAddresses::WriteDeflateHeaderBits
    cmp    ebp,0x3
    jne    Branch16
    mov    ecx,DWORD PTR [esi+0x44]
    mov    edx,DWORD PTR [esi+0x3c]
    mov    WORD PTR [edx+ecx*2-0x2],0x0
    mov    eax,DWORD PTR [esi+0x44]
    mov    edi,DWORD PTR [esi+0x3c]
    lea    ecx,[eax+eax*1-0x2]
    xor    eax,eax
    mov    edx,ecx
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,ebp
    rep    stos BYTE PTR es:[edi],al
  Branch16:
    push   ebx
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    eax,DWORD PTR [ebx+0x10]
    test   eax,eax
    jne    Branch17
    mov    DWORD PTR [esi+0x20],0xffffffff
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch17:
    cmp    ebp,0x4
    je     Branch18
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch18:
    mov    eax,DWORD PTR [esi+0x18]
    test   eax,eax
    je     Branch19
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x1
    pop    ebx
    ret    0x8
  Branch19:
    xor    eax,eax
    mov    ax,WORD PTR [ebx+0x32]
    push   eax
    push   esi
    call   R6GameServiceAddresses::WriteDeflateBigEndianWord
    mov    ecx,DWORD PTR [ebx+0x30]
    and    ecx,0xffff
    push   ecx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateBigEndianWord
    push   ebx
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    ecx,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esi+0x18],0xffffffff
    xor    eax,eax
    pop    edi
    test   ecx,ecx
    pop    esi
    pop    ebp
    sete   al
    pop    ebx
    ret    0x8
  Branch20:
    mov    eax,DWORD PTR [ebx+0x10]
    test   eax,eax
    jne    Branch21
    mov    DWORD PTR [esi+0x20],0xffffffff
  Branch21:
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch22:
    mov    edx,DWORD PTR ds:0x1008c844
    mov    DWORD PTR [ebx+0x18],edx
  Branch23:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffe
    pop    ebx
    ret    0x8
  }
}

// Write the low word high byte first, rereading pending base/cursor between bytes.
// R6GameService.dll @ 1001e790 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateBigEndianWord(void *state,uint value)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    mov    esi,DWORD PTR [eax+0x8]
    mov    edi,DWORD PTR [eax+0x14]
    mov    edx,ecx
    shr    edx,0x8
    mov    BYTE PTR [esi+edi*1],dl
    mov    edx,DWORD PTR [eax+0x14]
    mov    esi,DWORD PTR [eax+0x8]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    pop    edi
    mov    BYTE PTR [edx+esi*1],cl
    mov    ecx,DWORD PTR [eax+0x14]
    inc    ecx
    pop    esi
    mov    DWORD PTR [eax+0x14],ecx
    ret    0x8
  }
}
