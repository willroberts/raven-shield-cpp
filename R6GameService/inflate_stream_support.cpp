#include "native_addresses.h"

// Shared inflater framing and circular output operations; source names/types are inferred.
// Explicit offsets, current/cached fields, original argument scratch and raw stdcall ABI remain native.

// Native outer-inflate state dispatch targets 0..13; descriptive table name.
// R6GameService.dll data @ 1001e1f8 : fourteen code pointers in .text, not additional function bodies.
static const uint InflateStateTargets[14] = {
  R6GameServiceAddresses::inflate_stream_supportBranch2, R6GameServiceAddresses::inflate_stream_supportBranch5, R6GameServiceAddresses::inflate_stream_supportBranch16, R6GameServiceAddresses::inflate_stream_supportBranch19, R6GameServiceAddresses::inflate_stream_supportBranch21,
  R6GameServiceAddresses::inflate_stream_supportBranch23, R6GameServiceAddresses::inflate_stream_supportBranch25, R6GameServiceAddresses::inflate_stream_supportBranch7, R6GameServiceAddresses::inflate_stream_supportBranch11, R6GameServiceAddresses::inflate_stream_supportBranch12,
  R6GameServiceAddresses::inflate_stream_supportBranch13, R6GameServiceAddresses::inflate_stream_supportBranch14, R6GameServiceAddresses::inflate_stream_supportBranch28, R6GameServiceAddresses::inflate_stream_supportBranch29,
};

// Read headers, dictionary IDs and trailers around block decoding, preserving progress states and argument scratch.
// R6GameService.dll @ 1001de00 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall InflateStream(void *stream,int flush)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    test   esi,esi
    push   edi
    je     Branch26
    mov    eax,DWORD PTR [esi+0x1c]
    test   eax,eax
    je     Branch26
    cmp    DWORD PTR [esi],0x0
    je     Branch26
    mov    edx,DWORD PTR [esp+0x18]
    xor    ebx,ebx
    cmp    edx,0x4
    mov    edi,0xfffffffb
    setne  bl
    dec    ebx
    mov    ebp,0x5
    and    ebx,0xfffffffb
    mov    DWORD PTR [esp+0x18],ebx
  Branch1:
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [eax]
    cmp    ecx,0xd
    ja     Branch26
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::InflateStateTargets]
  Branch2:
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    je     Branch17
    dec    ecx
    xor    edx,edx
    mov    DWORD PTR [esi+0x4],ecx
    mov    ecx,DWORD PTR [esi+0x8]
    inc    ecx
    mov    edi,ebx
    mov    DWORD PTR [esi+0x8],ecx
    mov    ecx,DWORD PTR [esi]
    mov    dl,BYTE PTR [ecx]
    mov    DWORD PTR [eax+0x4],edx
    mov    eax,DWORD PTR [esi+0x1c]
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    and    ecx,0xf
    inc    edx
    cmp    cl,0x8
    mov    DWORD PTR [esi],edx
    je     Branch3
    mov    DWORD PTR [eax],0xd
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextUnknownCompressionMethod
    mov    DWORD PTR [edx+0x4],ebp
    jmp    Branch1
  Branch3:
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [eax+0x10]
    shr    ecx,0x4
    add    ecx,0x8
    cmp    ecx,edx
    jbe    Branch4
    mov    DWORD PTR [eax],0xd
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextInvalidWindowSize
    mov    DWORD PTR [edx+0x4],ebp
    jmp    Branch1
  Branch4:
    mov    DWORD PTR [eax],0x1
  Branch5:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch17
    dec    eax
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x8]
    inc    eax
    mov    edi,ebx
    mov    ebx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [esi]
    xor    edx,edx
    mov    ebp,0x1f
    mov    cl,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [ebx+0x4]
    shl    eax,0x8
    add    eax,ecx
    div    ebp
    mov    ebp,0x5
    test   edx,edx
    je     Branch6
    mov    DWORD PTR [ebx],0xd
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextIncorrectHeaderCheck
    mov    DWORD PTR [eax+0x4],ebp
    jmp    Branch1
  Branch6:
    test   cl,0x20
    jne    Branch15
    mov    DWORD PTR [ebx],0x7
    mov    ebx,DWORD PTR [esp+0x18]
    jmp    Branch1
  Branch7:
    mov    ecx,DWORD PTR [eax+0x14]
    push   edi
    push   esi
    push   ecx
    call   R6GameServiceAddresses::DecodeDeflateBlocks
    mov    edi,eax
    cmp    edi,0xfffffffd
    jne    Branch8
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [edx],0xd
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [eax+0x4],0x0
    jmp    Branch1
  Branch8:
    test   edi,edi
    jne    Branch9
    mov    edi,ebx
  Branch9:
    cmp    edi,0x1
    jne    Branch17
    mov    eax,DWORD PTR [esi+0x1c]
    mov    edi,ebx
    mov    edx,DWORD PTR [eax+0x14]
    lea    ecx,[eax+0x4]
    push   ecx
    push   esi
    push   edx
    call   R6GameServiceAddresses::ResetInflaterDecodeState
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    je     Branch10
    mov    DWORD PTR [eax],0xc
    jmp    Branch1
  Branch10:
    mov    DWORD PTR [eax],0x8
  Branch11:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch17
    dec    eax
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x8]
    inc    eax
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    edi,ebx
    mov    cl,BYTE PTR [eax]
    shl    ecx,0x18
    mov    DWORD PTR [edx+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [eax],0x9
  Branch12:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch17
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi]
    dec    eax
    inc    edx
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x1c]
    xor    edx,edx
    mov    dl,BYTE PTR [ecx]
    mov    edi,ebx
    mov    ecx,DWORD PTR [eax+0x8]
    shl    edx,0x10
    add    ecx,edx
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [eax],0xa
  Branch13:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch17
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi]
    dec    eax
    inc    edx
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x1c]
    xor    edx,edx
    mov    dl,BYTE PTR [ecx]
    mov    edi,ebx
    mov    ecx,DWORD PTR [eax+0x8]
    shl    edx,0x8
    add    ecx,edx
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [eax],0xb
  Branch14:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch17
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi]
    dec    eax
    inc    edx
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x8],edx
    xor    edx,edx
    mov    dl,BYTE PTR [ecx]
    mov    ecx,DWORD PTR [eax+0x8]
    add    ecx,edx
    mov    edi,ebx
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [eax+0x8]
    cmp    ecx,edx
    je     Branch27
    mov    DWORD PTR [eax],0xd
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextIncorrectDataCheck
    mov    DWORD PTR [edx+0x4],ebp
    jmp    Branch1
  Branch15:
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [eax],0x2
  Branch16:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch18
  Branch17:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  Branch18:
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi]
    dec    eax
    inc    edx
    mov    DWORD PTR [esi+0x8],edx
    xor    edx,edx
    mov    DWORD PTR [esi+0x4],eax
    mov    dl,BYTE PTR [ecx]
    mov    eax,DWORD PTR [esi+0x1c]
    mov    edi,ebx
    shl    edx,0x18
    mov    DWORD PTR [eax+0x8],edx
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esi+0x1c]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [ecx],0x3
  Branch19:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch20
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  Branch20:
    mov    edx,DWORD PTR [esi]
    dec    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x8]
    inc    eax
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    cl,BYTE PTR [edx]
    mov    edi,ebx
    mov    edx,DWORD PTR [eax+0x8]
    shl    ecx,0x10
    add    edx,ecx
    mov    DWORD PTR [eax+0x8],edx
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x1c]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [edx],0x4
  Branch21:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch22
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  Branch22:
    mov    ecx,DWORD PTR [esi]
    dec    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x8]
    inc    eax
    xor    edx,edx
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    dl,BYTE PTR [ecx]
    mov    edi,ebx
    mov    ecx,DWORD PTR [eax+0x8]
    shl    edx,0x8
    add    ecx,edx
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [eax],ebp
  Branch23:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch24
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  Branch24:
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi]
    dec    eax
    inc    edx
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x8],edx
    xor    edx,edx
    mov    dl,BYTE PTR [ecx]
    mov    ecx,DWORD PTR [eax+0x8]
    add    ecx,edx
    pop    edi
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esi+0x30],ecx
    pop    esi
    mov    DWORD PTR [eax],0x6
    pop    ebp
    mov    eax,0x2
    pop    ebx
    ret    0x8
  Branch25:
    mov    edx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [edx],0xd
    mov    eax,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextNeedDictionary
    mov    DWORD PTR [eax+0x4],0x0
  Branch26:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffe
    pop    ebx
    ret    0x8
  Branch27:
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [ecx],0xc
  Branch28:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x1
    pop    ebx
    ret    0x8
  Branch29:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffd
    pop    ebx
    ret    0x8
  }
}

// Commit circular-window segments; update counters/checksum before copies, then publish final cursors.
// R6GameService.dll @ 10022ce0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CommitInflaterOutput(void *state,void *stream,uint status)
{
  __asm {
    push   ecx
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [ebx+0x34]
    push   edi
    mov    edi,DWORD PTR [ebx+0x30]
    mov    eax,DWORD PTR [esi+0xc]
    cmp    edi,ebp
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x18],edi
    jbe    Branch30
    mov    ebp,DWORD PTR [ebx+0x2c]
  Branch30:
    mov    eax,DWORD PTR [esi+0x10]
    sub    ebp,edi
    cmp    ebp,eax
    jbe    Branch31
    mov    ebp,eax
  Branch31:
    test   ebp,ebp
    je     Branch32
    cmp    DWORD PTR [esp+0x20],0xfffffffb
    jne    Branch32
    mov    DWORD PTR [esp+0x20],0x0
  Branch32:
    mov    edx,DWORD PTR [esi+0x14]
    sub    eax,ebp
    add    edx,ebp
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x14],edx
    mov    eax,DWORD PTR [ebx+0x38]
    test   eax,eax
    je     Branch33
    mov    ecx,DWORD PTR [ebx+0x3c]
    push   ebp
    push   edi
    push   ecx
    call   eax
    mov    DWORD PTR [ebx+0x3c],eax
    mov    DWORD PTR [esi+0x30],eax
  Branch33:
    mov    ecx,ebp
    mov    esi,edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,edx
    and    ecx,0x3
    add    eax,ebp
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edi,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ebx+0x2c]
    add    edi,ebp
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch38
    mov    eax,DWORD PTR [ebx+0x34]
    mov    esi,DWORD PTR [ebx+0x28]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x18],esi
    jne    Branch34
    mov    DWORD PTR [ebx+0x34],esi
  Branch34:
    mov    edi,DWORD PTR [esp+0x1c]
    mov    ebp,DWORD PTR [ebx+0x34]
    sub    ebp,esi
    mov    eax,DWORD PTR [edi+0x10]
    cmp    ebp,eax
    jbe    Branch35
    mov    ebp,eax
  Branch35:
    test   ebp,ebp
    je     Branch36
    cmp    DWORD PTR [esp+0x20],0xfffffffb
    jne    Branch36
    mov    DWORD PTR [esp+0x20],0x0
  Branch36:
    mov    edx,DWORD PTR [edi+0x14]
    sub    eax,ebp
    add    edx,ebp
    mov    DWORD PTR [edi+0x10],eax
    mov    DWORD PTR [edi+0x14],edx
    mov    eax,DWORD PTR [ebx+0x38]
    test   eax,eax
    je     Branch37
    mov    ecx,DWORD PTR [ebx+0x3c]
    push   ebp
    push   esi
    push   ecx
    call   eax
    mov    DWORD PTR [ebx+0x3c],eax
    mov    DWORD PTR [edi+0x30],eax
  Branch37:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,ebp
    mov    edx,ecx
    mov    edi,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    add    eax,ebp
    mov    ecx,edx
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,DWORD PTR [esp+0x18]
    and    ecx,0x3
    add    eax,ebp
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    DWORD PTR [esp+0x18],eax
  Branch38:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    mov    DWORD PTR [ecx+0xc],edx
    mov    DWORD PTR [ebx+0x30],eax
    mov    eax,DWORD PTR [esp+0x18]
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}
