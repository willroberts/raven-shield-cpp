#include "native_addresses.h"

// Shared deflate dynamic-tree and token byte writers. Names and pointer types are descriptive inferences.
// Native low-word accumulation, frame scratch, current payload/count loads and unchecked partial writes are retained.

// Length-minus-three extra-bit bases; final258-length code has no extra bits and an unused base0.
// R6GameService.dll data @ 10076698 : selected 29 uint32 entries.
static const uint DeflateLengthBases[29] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 10,
  12, 14, 16, 20, 24, 28, 32, 40, 48, 56,
  64, 80, 96, 112, 128, 160, 192, 224, 0,
};

// Distance-minus-one extra-bit bases.
// R6GameService.dll data @ 10076710 : selected 30 uint32 entries.
static const uint DeflateDistanceBases[30] = {
  0, 1, 2, 3, 4, 6, 8, 12, 16, 24,
  32, 48, 64, 96, 128, 192, 256, 384, 512, 768,
  1024, 1536, 2048, 3072, 4096, 6144, 8192, 12288, 16384, 24576,
};

// Write dynamic-tree count fields and ordered code lengths, then serialize both current code-length runs.
// R6GameService.dll @ 100210d0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateTreeHeader(void *state,uint literalCount,uint distanceCount,
  int bitLengthCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    add    eax,0xfffffeff
    push   edi
    mov    ecx,DWORD PTR [esi+0x16b4]
    cmp    ecx,0xb
    jle    Branch1
    mov    edx,eax
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    or     WORD PTR [esi+0x16b0],dx
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [esi+0x16b4]
    mov    ebp,DWORD PTR [esi+0x14]
    mov    cl,0x10
    sub    cl,dl
    inc    ebp
    shr    ax,cl
    add    edx,0xfffffff5
    mov    DWORD PTR [esi+0x14],ebp
    mov    DWORD PTR [esi+0x16b4],edx
    mov    WORD PTR [esi+0x16b0],ax
    jmp    Branch2
  Branch1:
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    add    ecx,0x5
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch2:
    mov    ecx,DWORD PTR [esi+0x16b4]
    cmp    ecx,0xb
    jle    Branch3
    mov    edx,DWORD PTR [esp+0x1c]
    lea    eax,[edx-0x1]
    mov    edx,eax
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    or     WORD PTR [esi+0x16b0],dx
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [esi+0x16b4]
    mov    ebp,DWORD PTR [esi+0x14]
    mov    cl,0x10
    sub    cl,dl
    inc    ebp
    shr    ax,cl
    add    edx,0xfffffff5
    mov    DWORD PTR [esi+0x14],ebp
    mov    DWORD PTR [esi+0x16b4],edx
    mov    WORD PTR [esi+0x16b0],ax
    jmp    Branch4
  Branch3:
    mov    eax,DWORD PTR [esp+0x1c]
    dec    eax
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    add    ecx,0x5
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch4:
    mov    ecx,DWORD PTR [esi+0x16b4]
    mov    ebp,DWORD PTR [esp+0x20]
    cmp    ecx,0xc
    lea    eax,[ebp-0x4]
    jle    Branch5
    mov    edx,eax
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    or     WORD PTR [esi+0x16b0],dx
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [esi+0x14]
    mov    bl,BYTE PTR [esi+0x16b1]
    inc    edx
    mov    DWORD PTR [esi+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edx,DWORD PTR [esi+0x16b4]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    ax,cl
    add    edx,0xfffffff4
    mov    DWORD PTR [esi+0x16b4],edx
    mov    WORD PTR [esi+0x16b0],ax
    jmp    Branch6
  Branch5:
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    add    ecx,0x4
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch6:
    xor    edi,edi
    test   ebp,ebp
    jle    Branch10
  Branch7:
    mov    ecx,DWORD PTR [esi+0x16b4]
    xor    eax,eax
    cmp    ecx,0xd
    jle    Branch8
    xor    edx,edx
    mov    dl,BYTE PTR [edi+R6GameServiceAddresses::DeflateBitLengthOrder]
    mov    ax,WORD PTR [esi+edx*4+0xa76]
    mov    edx,eax
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    or     WORD PTR [esi+0x16b0],dx
    mov    edx,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [esi+0x14]
    mov    bl,BYTE PTR [esi+0x16b1]
    inc    edx
    mov    DWORD PTR [esi+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edx,DWORD PTR [esi+0x16b4]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    ax,cl
    add    edx,0xfffffff3
    mov    DWORD PTR [esi+0x16b4],edx
    mov    WORD PTR [esi+0x16b0],ax
    jmp    Branch9
  Branch8:
    mov    al,BYTE PTR [edi+R6GameServiceAddresses::DeflateBitLengthOrder]
    mov    dx,WORD PTR [esi+eax*4+0xa76]
    shl    dx,cl
    or     WORD PTR [esi+0x16b0],dx
    add    ecx,0x3
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch9:
    inc    edi
    cmp    edi,ebp
    jl     Branch7
  Branch10:
    mov    eax,DWORD PTR [esp+0x18]
    lea    ecx,[esi+0x8c]
    dec    eax
    push   eax
    push   ecx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateCodeLengthRuns
    lea    eax,[esi+0x980]
    mov    edx,DWORD PTR [esp+0x1c]
    dec    edx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::WriteDeflateCodeLengthRuns
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x10
  }
}

// Encode length runs through the bit-length tree, preserving native thresholds, sentinel dependence and frame scratch.
// R6GameService.dll @ 10021320 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateCodeLengthRuns(void *state,const void *tree,int maxCode)
{
  __asm {
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    bx,WORD PTR [eax+0x2]
    xor    esi,esi
    test   ebx,ebx
    push   edi
    mov    DWORD PTR [esp+0xc],0xffffffff
    mov    ecx,0x7
    mov    edx,0x4
    jne    Branch11
    mov    ecx,0x8a
    mov    edx,0x3
  Branch11:
    mov    edi,DWORD PTR [esp+0x20]
    test   edi,edi
    jl     Branch37
    add    eax,0x6
    inc    edi
    mov    DWORD PTR [esp+0x20],eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x10],edi
    push   ebp
  Branch12:
    mov    edi,DWORD PTR [esp+0x24]
    mov    ebp,ebx
    xor    ebx,ebx
    inc    esi
    mov    bx,WORD PTR [edi]
    cmp    esi,ecx
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x20],esi
    jge    Branch13
    cmp    ebp,ebx
    je     Branch36
  Branch13:
    cmp    esi,edx
    jge    Branch17
  Branch14:
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    mov    di,WORD PTR [eax+ebp*4+0xa76]
    mov    edx,0x10
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch15
    xor    esi,esi
    mov    si,WORD PTR [eax+ebp*4+0xa74]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    mov    esi,DWORD PTR [esp+0x20]
    jmp    Branch16
  Branch15:
    mov    dx,WORD PTR [eax+ebp*4+0xa74]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch16:
    dec    esi
    mov    DWORD PTR [eax+0x16b4],ecx
    mov    DWORD PTR [esp+0x20],esi
    jne    Branch14
    jmp    Branch33
  Branch17:
    test   ebp,ebp
    je     Branch24
    cmp    ebp,DWORD PTR [esp+0x10]
    je     Branch20
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    mov    di,WORD PTR [eax+ebp*4+0xa76]
    mov    edx,0x10
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch18
    xor    esi,esi
    mov    si,WORD PTR [eax+ebp*4+0xa74]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    mov    esi,DWORD PTR [esp+0x20]
    jmp    Branch19
  Branch18:
    mov    dx,WORD PTR [eax+ebp*4+0xa74]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch19:
    dec    esi
    mov    DWORD PTR [eax+0x16b4],ecx
    mov    DWORD PTR [esp+0x20],esi
  Branch20:
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    mov    di,WORD PTR [eax+0xab6]
    mov    edx,0x10
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch21
    xor    esi,esi
    mov    si,WORD PTR [eax+0xab4]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    mov    esi,DWORD PTR [esp+0x20]
    jmp    Branch22
  Branch21:
    mov    dx,WORD PTR [eax+0xab4]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch22:
    add    esi,0xfffffffd
    cmp    ecx,0xe
    mov    DWORD PTR [eax+0x16b4],ecx
    jle    Branch23
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    add    edx,0xfffffff2
    mov    DWORD PTR [eax+0x16b4],edx
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch33
  Branch23:
    shl    esi,cl
    or     WORD PTR [eax+0x16b0],si
    add    ecx,0x2
    jmp    Branch32
  Branch24:
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    cmp    esi,0xa
    mov    edx,0x10
    jg     Branch28
    mov    di,WORD PTR [eax+0xaba]
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch25
    xor    esi,esi
    mov    si,WORD PTR [eax+0xab8]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    mov    esi,DWORD PTR [esp+0x20]
    jmp    Branch26
  Branch25:
    mov    dx,WORD PTR [eax+0xab8]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch26:
    add    esi,0xfffffffd
    cmp    ecx,0xd
    mov    DWORD PTR [eax+0x16b4],ecx
    jle    Branch27
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    add    edx,0xfffffff3
    mov    DWORD PTR [eax+0x16b4],edx
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch33
  Branch27:
    shl    esi,cl
    or     WORD PTR [eax+0x16b0],si
    add    ecx,0x3
    jmp    Branch32
  Branch28:
    mov    di,WORD PTR [eax+0xabe]
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch29
    xor    esi,esi
    mov    si,WORD PTR [eax+0xabc]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    mov    esi,DWORD PTR [esp+0x20]
    jmp    Branch30
  Branch29:
    mov    dx,WORD PTR [eax+0xabc]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch30:
    add    esi,0xfffffff5
    cmp    ecx,0x9
    mov    DWORD PTR [eax+0x16b4],ecx
    jle    Branch31
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    add    edx,0xfffffff7
    mov    DWORD PTR [eax+0x16b4],edx
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch33
  Branch31:
    shl    esi,cl
    or     WORD PTR [eax+0x16b0],si
    add    ecx,0x7
  Branch32:
    mov    DWORD PTR [eax+0x16b4],ecx
  Branch33:
    mov    ebx,DWORD PTR [esp+0x1c]
    xor    esi,esi
    test   ebx,ebx
    mov    DWORD PTR [esp+0x10],ebp
    jne    Branch34
    mov    ecx,0x8a
    mov    edx,0x3
    jmp    Branch36
  Branch34:
    cmp    ebp,ebx
    jne    Branch35
    mov    ecx,0x6
    mov    edx,0x3
    jmp    Branch36
  Branch35:
    mov    ecx,0x7
    mov    edx,0x4
  Branch36:
    mov    ebp,DWORD PTR [esp+0x24]
    mov    edi,DWORD PTR [esp+0x14]
    add    ebp,0x4
    dec    edi
    mov    DWORD PTR [esp+0x24],ebp
    mov    DWORD PTR [esp+0x14],edi
    jne    Branch12
    pop    ebp
  Branch37:
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret    0xc
  }
}

// Encode current literal/match tokens and end-of-block, reloading tally/payload fields and publishing last EOB width.
// R6GameService.dll @ 10021840 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateTokens(void *state,const void *literalTree,
  const void *distanceTree)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    sub    esp,0x8
    mov    ecx,DWORD PTR [eax+0x1698]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    push   esi
    push   edi
    xor    edi,edi
    test   ecx,ecx
    je     Branch53
  Branch38:
    mov    ecx,DWORD PTR [eax+0x169c]
    mov    edx,DWORD PTR [eax+0x1690]
    xor    ebp,ebp
    mov    bp,WORD PTR [ecx+edi*2]
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+edx*1]
    inc    edi
    mov    esi,ecx
    mov    ecx,DWORD PTR [eax+0x16b4]
    test   ebp,ebp
    mov    DWORD PTR [esp+0x14],edi
    jne    Branch40
    mov    bp,WORD PTR [ebx+esi*4+0x2]
    mov    edx,0x10
    sub    edx,ebp
    cmp    ecx,edx
    jle    Branch39
    xor    edi,edi
    mov    DWORD PTR [esp+0x1c],ebx
    mov    di,WORD PTR [ebx+esi*4]
    mov    edx,edi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    esi,edx
    mov    dl,BYTE PTR [eax+0x16b1]
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esi+ecx*1],dl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    di,cl
    lea    ecx,[edx+ebp*1-0x10]
    mov    WORD PTR [eax+0x16b0],di
    jmp    Branch51
  Branch39:
    mov    dx,WORD PTR [ebx+esi*4]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,ebp
    jmp    Branch51
  Branch40:
    xor    edx,edx
    xor    edi,edi
    mov    dl,BYTE PTR [esi+R6GameServiceAddresses::DeflateLengthCodes]
    mov    DWORD PTR [esp+0x1c],edx
    mov    di,WORD PTR [ebx+edx*4+0x406]
    mov    ebx,0x10
    sub    ebx,edi
    mov    DWORD PTR [esp+0x10],edi
    cmp    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x20]
    jle    Branch41
    xor    edi,edi
    mov    di,WORD PTR [ebx+edx*4+0x404]
    mov    edx,edi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    di,cl
    mov    ecx,DWORD PTR [esp+0x10]
    lea    edx,[edx+ecx*1-0x10]
    mov    DWORD PTR [eax+0x16b4],edx
    mov    edx,DWORD PTR [esp+0x1c]
    mov    WORD PTR [eax+0x16b0],di
    jmp    Branch42
  Branch41:
    mov    bx,WORD PTR [ebx+edx*4+0x404]
    shl    bx,cl
    mov    ecx,DWORD PTR [eax+0x16b4]
    or     WORD PTR [eax+0x16b0],bx
    add    ecx,edi
    mov    DWORD PTR [eax+0x16b4],ecx
  Branch42:
    mov    edi,DWORD PTR [edx*4+R6GameServiceAddresses::DeflateLengthExtraBits]
    test   edi,edi
    je     Branch45
    mov    ecx,DWORD PTR [edx*4+R6GameServiceAddresses::DeflateLengthBases]
    mov    edx,0x10
    sub    esi,ecx
    mov    ecx,DWORD PTR [eax+0x16b4]
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch43
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch44
  Branch43:
    shl    esi,cl
    or     WORD PTR [eax+0x16b0],si
    add    ecx,edi
  Branch44:
    mov    DWORD PTR [eax+0x16b4],ecx
  Branch45:
    dec    ebp
    cmp    ebp,0x100
    jae    Branch46
    xor    edx,edx
    mov    dl,BYTE PTR [ebp+R6GameServiceAddresses::DeflateDistanceCodes]
    jmp    Branch47
  Branch46:
    mov    edx,ebp
    shr    edx,0x7
    xor    ecx,ecx
    mov    cl,BYTE PTR [edx+R6GameServiceAddresses::DeflateDistanceCodes+0x100]
    mov    edx,ecx
  Branch47:
    mov    ebx,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    mov    esi,0x10
    mov    di,WORD PTR [ebx+edx*4+0x2]
    mov    DWORD PTR [esp+0x1c],edx
    sub    esi,edi
    cmp    ecx,esi
    jle    Branch48
    xor    esi,esi
    mov    si,WORD PTR [ebx+edx*4]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ecx,edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    edx,DWORD PTR [esp+0x1c]
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch49
  Branch48:
    mov    si,WORD PTR [ebx+edx*4]
    shl    si,cl
    or     WORD PTR [eax+0x16b0],si
    add    ecx,edi
  Branch49:
    mov    ebx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [eax+0x16b4],ecx
    mov    esi,DWORD PTR [edx*4+R6GameServiceAddresses::DeflateDistanceExtraBits]
    test   esi,esi
    je     Branch52
    mov    ecx,DWORD PTR [edx*4+R6GameServiceAddresses::DeflateDistanceBases]
    mov    edx,0x10
    sub    ebp,ecx
    mov    ecx,DWORD PTR [eax+0x16b4]
    sub    edx,esi
    cmp    ecx,edx
    jle    Branch50
    mov    edx,ebp
    mov    DWORD PTR [esp+0x1c],ebx
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    edi,edx
    mov    dl,BYTE PTR [eax+0x16b1]
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [edi+ecx*1],dl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    bp,cl
    lea    ecx,[edx+esi*1-0x10]
    mov    WORD PTR [eax+0x16b0],bp
    jmp    Branch51
  Branch50:
    shl    ebp,cl
    or     WORD PTR [eax+0x16b0],bp
    add    ecx,esi
  Branch51:
    mov    DWORD PTR [eax+0x16b4],ecx
  Branch52:
    mov    edi,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [eax+0x1698]
    cmp    edi,ecx
    jb     Branch38
  Branch53:
    mov    ecx,DWORD PTR [eax+0x16b4]
    xor    edi,edi
    mov    di,WORD PTR [ebx+0x402]
    mov    edx,0x10
    sub    edx,edi
    cmp    ecx,edx
    jle    Branch54
    xor    esi,esi
    mov    DWORD PTR [esp+0x20],ebx
    mov    si,WORD PTR [ebx+0x400]
    mov    edx,esi
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    mov    DWORD PTR [eax+0x14],edx
    mov    ebp,edx
    mov    dl,BYTE PTR [eax+0x16b1]
    mov    ebx,DWORD PTR [esp+0x20]
    mov    BYTE PTR [ecx+ebp*1],dl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x16b4]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    cl,0x10
    sub    cl,dl
    shr    si,cl
    lea    ecx,[edx+edi*1-0x10]
    mov    WORD PTR [eax+0x16b0],si
    jmp    Branch55
  Branch54:
    mov    dx,WORD PTR [ebx+0x400]
    shl    dx,cl
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,edi
  Branch55:
    mov    DWORD PTR [eax+0x16b4],ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [ebx+0x402]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax+0x16ac],ecx
    pop    ebx
    add    esp,0x8
    ret    0xc
  }
}
