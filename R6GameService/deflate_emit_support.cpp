#include "native_addresses.h"

// Shared deflate block selection and bit/stored-byte emission. Source names and pointer types are inferred.
// Native fields/argument scratch, partial writes, helper order, raw EAX and stdcall cleanup remain explicit.

// Append a stored-block header, replace the original EOF word with header flag 1 and tail-forward the same frame.
// R6GameService.dll @ 10020540 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateHeaderBits(void *state,const void *source,uint length,uint eof)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [eax+0x16b4]
    cmp    ecx,0xd
    jle    Branch1
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x18],0x1
    mov    edx,esi
    mov    DWORD PTR [esp+0xc],eax
    shl    edx,cl
    mov    ecx,DWORD PTR [eax+0x8]
    or     WORD PTR [eax+0x16b0],dx
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    ecx,DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [eax+0x8]
    mov    bl,BYTE PTR [eax+0x16b1]
    inc    ecx
    mov    DWORD PTR [eax+0x14],ecx
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x16b4]
    mov    ebx,DWORD PTR [eax+0x14]
    mov    cl,0x10
    sub    cl,dl
    inc    ebx
    shr    si,cl
    add    edx,0xfffffff3
    mov    DWORD PTR [eax+0x14],ebx
    mov    DWORD PTR [eax+0x16b4],edx
    mov    WORD PTR [eax+0x16b0],si
    pop    esi
    pop    ebx
    jmp    R6GameServiceAddresses::WriteDeflateStoredBlock
  Branch1:
    mov    edx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],0x1
    shl    edx,cl
    mov    DWORD PTR [esp+0x4],eax
    or     WORD PTR [eax+0x16b0],dx
    add    ecx,0x3
    mov    DWORD PTR [eax+0x16b4],ecx
    jmp    R6GameServiceAddresses::WriteDeflateStoredBlock
  }
}

// Compare wrapped stored/fixed/dynamic sizes, emit the selected block, reset tally and optionally align final bits.
// R6GameService.dll @ 10020800 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall EmitDeflateBlock(void *state,const void *source,uint length,uint eof)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x14]
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    xor    eax,eax
    push   edi
    mov    ecx,DWORD PTR [esi+0x7c]
    test   ecx,ecx
    jle    Branch3
    cmp    BYTE PTR [esi+0x1c],0x2
    jne    Branch2
    push   esi
    call   R6GameServiceAddresses::ClassifyDeflateData
  Branch2:
    lea    eax,[esi+0xb10]
    push   eax
    push   esi
    call   R6GameServiceAddresses::BuildDeflateHuffmanTree
    lea    ecx,[esi+0xb1c]
    push   ecx
    push   esi
    call   R6GameServiceAddresses::BuildDeflateHuffmanTree
    push   esi
    call   R6GameServiceAddresses::BuildDeflateBitLengthTree
    mov    edx,DWORD PTR [esi+0x16a0]
    mov    ecx,DWORD PTR [esi+0x16a4]
    add    edx,0xa
    add    ecx,0xa
    shr    edx,0x3
    shr    ecx,0x3
    cmp    ecx,edx
    ja     Branch5
    jmp    Branch4
  Branch3:
    lea    ecx,[ebp+0x5]
  Branch4:
    mov    edx,ecx
  Branch5:
    lea    edi,[ebp+0x4]
    cmp    edi,edx
    ja     Branch6
    mov    ebx,DWORD PTR [esp+0x18]
    test   ebx,ebx
    je     Branch6
    mov    edi,DWORD PTR [esp+0x20]
    push   edi
    push   ebp
    push   ebx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateHeaderBits
    jmp    Branch12
  Branch6:
    mov    edi,DWORD PTR [esp+0x20]
    cmp    ecx,edx
    mov    ecx,DWORD PTR [esi+0x16b4]
    jne    Branch8
    cmp    ecx,0xd
    lea    eax,[edi+0x2]
    jle    Branch7
    mov    edx,eax
    push   R6GameServiceAddresses::DeflateFixedDistanceCodes
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x8]
    push   R6GameServiceAddresses::DeflateFixedLiteralCodes
    or     WORD PTR [esi+0x16b0],dx
    mov    edx,DWORD PTR [esi+0x14]
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
    jmp    Branch11
  Branch7:
    shl    eax,cl
    push   R6GameServiceAddresses::DeflateFixedDistanceCodes
    push   R6GameServiceAddresses::DeflateFixedLiteralCodes
    or     WORD PTR [esi+0x16b0],ax
    add    ecx,0x3
    mov    DWORD PTR [esi+0x16b4],ecx
    jmp    Branch11
  Branch8:
    cmp    ecx,0xd
    lea    edx,[edi+0x4]
    jle    Branch9
    mov    ebx,edx
    mov    DWORD PTR [esp+0x20],eax
    shl    ebx,cl
    mov    ecx,DWORD PTR [esi+0x8]
    or     WORD PTR [esi+0x16b0],bx
    mov    ebx,DWORD PTR [esi+0x14]
    mov    al,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+ebx*1],al
    mov    ecx,DWORD PTR [esi+0x14]
    mov    ebx,DWORD PTR [esi+0x8]
    mov    al,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    BYTE PTR [ecx+ebx*1],al
    mov    ebx,DWORD PTR [esi+0x16b4]
    mov    eax,DWORD PTR [esi+0x14]
    mov    cl,0x10
    sub    cl,bl
    inc    eax
    shr    dx,cl
    add    ebx,0xfffffff3
    mov    DWORD PTR [esi+0x14],eax
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esi+0x16b4],ebx
    mov    WORD PTR [esi+0x16b0],dx
    jmp    Branch10
  Branch9:
    shl    edx,cl
    or     WORD PTR [esi+0x16b0],dx
    add    ecx,0x3
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch10:
    mov    ecx,DWORD PTR [esi+0xb14]
    inc    eax
    push   eax
    mov    eax,DWORD PTR [esi+0xb20]
    inc    eax
    inc    ecx
    push   eax
    push   ecx
    push   esi
    call   R6GameServiceAddresses::WriteDeflateTreeHeader
    lea    edx,[esi+0x980]
    lea    eax,[esi+0x8c]
    push   edx
    push   eax
  Branch11:
    push   esi
    call   R6GameServiceAddresses::WriteDeflateTokens
  Branch12:
    push   esi
    call   R6GameServiceAddresses::ResetDeflateBlockTables
    test   edi,edi
    je     Branch13
    push   esi
    call   R6GameServiceAddresses::FlushDeflateBitBuffer
  Branch13:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x10
  }
}

// Classify literal frequencies as text when binary counts do not exceed one quarter of text counts.
// R6GameService.dll @ 10021c50 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ClassifyDeflateData(void *state)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    xor    edi,edi
    xor    edx,edx
    lea    eax,[ebx+0x8c]
    mov    ecx,0x7
  Branch14:
    xor    esi,esi
    mov    si,WORD PTR [eax]
    add    eax,0x4
    add    edx,esi
    dec    ecx
    jne    Branch14
    lea    eax,[ebx+0xa8]
    mov    ecx,0x79
    mov    esi,0x80
    push   ebp
  Branch15:
    xor    ebp,ebp
    mov    bp,WORD PTR [eax]
    add    eax,0x4
    add    edi,ebp
    dec    ecx
    jne    Branch15
    cmp    esi,0x100
    pop    ebp
    jge    Branch17
    mov    eax,0x100
    lea    ecx,[ebx+esi*4+0x8c]
    sub    eax,esi
  Branch16:
    xor    esi,esi
    mov    si,WORD PTR [ecx]
    add    ecx,0x4
    add    edx,esi
    dec    eax
    jne    Branch16
  Branch17:
    shr    edi,0x2
    cmp    edx,edi
    pop    edi
    setbe  al
    mov    BYTE PTR [ebx+0x1c],al
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Reverse low bits with native do-loop/wrapped signed counter behavior and a final logical shift.
// R6GameService.dll @ 10021cd0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ReverseDeflateCodeBits(uint value,int bitCount)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esp+0x4]
    xor    eax,eax
    push   esi
  Branch18:
    mov    esi,ecx
    and    esi,0x1
    or     eax,esi
    shr    ecx,1
    add    eax,eax
    dec    edx
    test   edx,edx
    jg     Branch18
    shr    eax,1
    pop    esi
    ret    0x8
  }
}

// Flush two bytes for count 16 or one for signed count at least 8, retaining any incomplete bit residue.
// R6GameService.dll @ 10021d00 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall FlushWholeDeflateBytes(void *state)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    mov    ecx,DWORD PTR [eax+0x16b4]
    cmp    ecx,0x10
    jne    Branch19
    mov    ecx,DWORD PTR [eax+0x8]
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
    inc    ecx
    pop    ebx
    mov    DWORD PTR [eax+0x14],ecx
    xor    ecx,ecx
    mov    WORD PTR [eax+0x16b0],cx
    mov    DWORD PTR [eax+0x16b4],ecx
    ret    0x4
  Branch19:
    cmp    ecx,0x8
    jl     Branch20
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0x14]
    mov    bl,BYTE PTR [eax+0x16b0]
    mov    BYTE PTR [ecx+edx*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    movzx  cx,BYTE PTR [eax+0x16b1]
    mov    WORD PTR [eax+0x16b0],cx
    mov    ecx,DWORD PTR [eax+0x16b4]
    inc    edx
    add    ecx,0xfffffff8
    mov    DWORD PTR [eax+0x14],edx
    mov    DWORD PTR [eax+0x16b4],ecx
  Branch20:
    pop    ebx
    ret    0x4
  }
}

// Flush one or two pending bytes for positive signed bit count, then clear accumulator and count.
// R6GameService.dll @ 10021d90 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall FlushDeflateBitBuffer(void *state)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    mov    edx,DWORD PTR [eax+0x16b4]
    cmp    edx,0x8
    jle    Branch21
    mov    ecx,DWORD PTR [eax+0x8]
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
    inc    ecx
    pop    ebx
    mov    DWORD PTR [eax+0x14],ecx
    xor    ecx,ecx
    mov    WORD PTR [eax+0x16b0],cx
    mov    DWORD PTR [eax+0x16b4],ecx
    ret    0x4
  Branch21:
    xor    ecx,ecx
    cmp    edx,ecx
    jle    Branch22
    mov    edx,DWORD PTR [eax+0x8]
    mov    bl,BYTE PTR [eax+0x16b0]
    push   esi
    mov    esi,DWORD PTR [eax+0x14]
    mov    BYTE PTR [edx+esi*1],bl
    mov    edx,DWORD PTR [eax+0x14]
    inc    edx
    pop    esi
    mov    DWORD PTR [eax+0x14],edx
  Branch22:
    mov    WORD PTR [eax+0x16b0],cx
    mov    DWORD PTR [eax+0x16b4],ecx
    pop    ebx
    ret    0x4
  }
}

// Align pending bits, optionally append low-16 length/complement and copy the full unsigned byte count forward.
// R6GameService.dll @ 10021e10 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall WriteDeflateStoredBlock(void *state,const void *source,uint length,uint writeHeader)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    push   esi
    call   R6GameServiceAddresses::FlushDeflateBitBuffer
    mov    DWORD PTR [esi+0x16ac],0x8
    mov    eax,DWORD PTR [esp+0x18]
    test   eax,eax
    mov    eax,DWORD PTR [esp+0x14]
    je     Branch23
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [ecx+edx*1],al
    mov    edx,DWORD PTR [esi+0x14]
    mov    edi,DWORD PTR [esi+0x8]
    inc    edx
    mov    DWORD PTR [esi+0x14],edx
    mov    ecx,edx
    xor    edx,edx
    mov    dl,ah
    mov    BYTE PTR [ecx+edi*1],dl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edi,DWORD PTR [esi+0x8]
    mov    dl,al
    inc    ecx
    not    dl
    mov    DWORD PTR [esi+0x14],ecx
    mov    BYTE PTR [ecx+edi*1],dl
    mov    edi,DWORD PTR [esi+0x14]
    mov    ecx,eax
    not    ecx
    xor    edx,edx
    inc    edi
    mov    dl,ch
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esi+0x14],edi
    mov    BYTE PTR [edi+ecx*1],dl
    mov    ecx,DWORD PTR [esi+0x14]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
  Branch23:
    test   eax,eax
    je     Branch25
    mov    ecx,DWORD PTR [esp+0x10]
    push   ebx
  Branch24:
    mov    edx,DWORD PTR [esi+0x14]
    mov    edi,DWORD PTR [esi+0x8]
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [edx+edi*1],bl
    mov    ebx,DWORD PTR [esi+0x14]
    inc    ebx
    inc    ecx
    dec    eax
    mov    DWORD PTR [esi+0x14],ebx
    jne    Branch24
    pop    ebx
  Branch25:
    pop    edi
    pop    esi
    ret    0x10
  }
}

// Emit one or two empty fixed blocks according to current bit residue and the previous EOB width.
// R6GameService.dll @ 100205e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall EmitDeflateFlushBits(void *state)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    mov    eax,0x2
    mov    ecx,DWORD PTR [esi+0x16b4]
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    cmp    ecx,0xd
    jle    Branch26
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esi+0x14]
    mov    al,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],al
    mov    ecx,DWORD PTR [esi+0x14]
    mov    dl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    eax,DWORD PTR [esi+0x14]
    inc    eax
    mov    cl,0x10
    mov    DWORD PTR [esi+0x14],eax
    mov    eax,DWORD PTR [esi+0x16b4]
    sub    cl,al
    mov    edx,0x2
    shr    dx,cl
    add    eax,0xfffffff3
    mov    DWORD PTR [esi+0x16b4],eax
    mov    WORD PTR [esi+0x16b0],dx
    jmp    Branch27
  Branch26:
    add    ecx,0x3
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch27:
    mov    ecx,DWORD PTR [esi+0x16b4]
    cmp    ecx,0x9
    jle    Branch28
    mov    eax,DWORD PTR [esi+0x8]
    xor    edx,edx
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    or     WORD PTR [esi+0x16b0],dx
    mov    dl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    dl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    eax,DWORD PTR [esi+0x14]
    inc    eax
    mov    cl,0x10
    mov    DWORD PTR [esi+0x14],eax
    mov    eax,DWORD PTR [esi+0x16b4]
    sub    cl,al
    xor    edx,edx
    shr    dx,cl
    add    eax,0xfffffff7
    mov    DWORD PTR [esi+0x16b4],eax
    mov    WORD PTR [esi+0x16b0],dx
    jmp    Branch29
  Branch28:
    xor    eax,eax
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    add    ecx,0x7
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch29:
    push   esi
    call   R6GameServiceAddresses::FlushWholeDeflateBytes
    mov    ecx,DWORD PTR [esi+0x16b4]
    mov    edx,DWORD PTR [esi+0x16ac]
    sub    edx,ecx
    add    edx,0xb
    cmp    edx,0x9
    jge    Branch33
    mov    eax,0x2
    shl    eax,cl
    or     WORD PTR [esi+0x16b0],ax
    cmp    ecx,0xd
    jle    Branch30
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esi+0x14]
    mov    al,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [ecx+edx*1],al
    mov    ecx,DWORD PTR [esi+0x14]
    mov    dl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    eax,DWORD PTR [esi+0x14]
    inc    eax
    mov    cl,0x10
    mov    DWORD PTR [esi+0x14],eax
    mov    eax,DWORD PTR [esi+0x16b4]
    sub    cl,al
    mov    edx,0x2
    shr    dx,cl
    add    eax,0xfffffff3
    mov    DWORD PTR [esi+0x16b4],eax
    mov    WORD PTR [esi+0x16b0],dx
    jmp    Branch31
  Branch30:
    add    ecx,0x3
    mov    DWORD PTR [esi+0x16b4],ecx
  Branch31:
    mov    ecx,DWORD PTR [esi+0x16b4]
    cmp    ecx,0x9
    jle    Branch32
    mov    eax,DWORD PTR [esi+0x8]
    xor    edx,edx
    shl    edx,cl
    mov    ecx,DWORD PTR [esi+0x14]
    push   esi
    or     WORD PTR [esi+0x16b0],dx
    mov    dl,BYTE PTR [esi+0x16b0]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    dl,BYTE PTR [esi+0x16b1]
    inc    ecx
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax+ecx*1],dl
    mov    eax,DWORD PTR [esi+0x14]
    inc    eax
    mov    cl,0x10
    mov    DWORD PTR [esi+0x14],eax
    mov    eax,DWORD PTR [esi+0x16b4]
    sub    cl,al
    xor    edx,edx
    shr    dx,cl
    add    eax,0xfffffff7
    mov    DWORD PTR [esi+0x16b4],eax
    mov    WORD PTR [esi+0x16b0],dx
    call   R6GameServiceAddresses::FlushWholeDeflateBytes
    mov    DWORD PTR [esi+0x16ac],0x7
    pop    esi
    ret    0x4
  Branch32:
    xor    eax,eax
    push   esi
    shl    eax,cl
    add    ecx,0x7
    mov    DWORD PTR [esi+0x16b4],ecx
    or     WORD PTR [esi+0x16b0],ax
    call   R6GameServiceAddresses::FlushWholeDeflateBytes
  Branch33:
    mov    DWORD PTR [esi+0x16ac],0x7
    pop    esi
    ret    0x4
  }
}
