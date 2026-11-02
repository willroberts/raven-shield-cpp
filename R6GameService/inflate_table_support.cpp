#include "native_addresses.h"

// Shared inflater block/table operations; source names/types are inferred.
// Native offsets, argument/local scratch, calling conventions and current/cached publication order remain explicit.

// Allocate temporary symbol storage, build the code-length table and map errors before current-callback release.
// R6GameService.dll @ 100225e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall BuildCodeLengthHuffmanTree(
  const uint *codeLengths,uint *rootBits,const void **tree,void *tableStorage,void *stream)
{
  __asm {
    push   ecx
    push   ebx
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    push   0x4
    push   0x13
    mov    DWORD PTR [esp+0x10],0x0
    mov    eax,DWORD PTR [edi+0x28]
    push   eax
    call   DWORD PTR [edi+0x20]
    mov    ebx,eax
    test   ebx,ebx
    jne    Branch1
    pop    edi
    mov    eax,0xfffffffc
    pop    ebx
    pop    ecx
    ret    0x14
  Branch1:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x18]
    push   ebp
    mov    ebp,DWORD PTR [esp+0x18]
    push   esi
    lea    ecx,[esp+0x10]
    push   ebx
    push   ecx
    mov    ecx,DWORD PTR [esp+0x20]
    push   edx
    push   ebp
    push   eax
    push   0x0
    push   0x0
    push   0x13
    push   0x13
    push   ecx
    call   R6GameServiceAddresses::BuildHuffmanLookupTable
    mov    esi,eax
    cmp    esi,0xfffffffd
    jne    Branch2
    mov    edx,DWORD PTR [edi+0x28]
    push   ebx
    push   edx
    mov    DWORD PTR [edi+0x18],R6GameServiceAddresses::TextOversubscribedDynamicBitLengthsTree
    call   DWORD PTR [edi+0x24]
    mov    eax,esi
    pop    esi
    pop    ebp
    pop    edi
    pop    ebx
    pop    ecx
    ret    0x14
  Branch2:
    cmp    esi,0xfffffffb
    je     Branch3
    cmp    DWORD PTR [ebp+0x0],0x0
    jne    Branch4
  Branch3:
    mov    DWORD PTR [edi+0x18],R6GameServiceAddresses::TextIncompleteDynamicBitLengthsTree
    mov    esi,0xfffffffd
  Branch4:
    mov    edx,DWORD PTR [edi+0x28]
    push   ebx
    push   edx
    call   DWORD PTR [edi+0x24]
    mov    eax,esi
    pop    esi
    pop    ebp
    pop    edi
    pop    ebx
    pop    ecx
    ret    0x14
  }
}

// Build literal and distance trees in one table pool, mapping native status/width failures and releasing work storage.
// R6GameService.dll @ 10022b30 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall BuildDynamicHuffmanTrees(
  uint literalCodeCount,uint distanceCodeCount,const uint *codeLengths,uint *literalRootBits,
  uint *distanceRootBits,const void **literalTree,const void **distanceTree,void *tableStorage,void *stream)
{
  __asm {
    push   ecx
    push   ebx
    mov    ebx,DWORD PTR [esp+0x2c]
    push   ebp
    push   esi
    mov    eax,DWORD PTR [ebx+0x28]
    push   edi
    push   0x4
    push   0x120
    push   eax
    mov    DWORD PTR [esp+0x1c],0x0
    call   DWORD PTR [ebx+0x20]
    mov    edi,eax
    test   edi,edi
    jne    Branch5
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffc
    pop    ebx
    pop    ecx
    ret    0x24
  Branch5:
    mov    edx,DWORD PTR [esp+0x34]
    mov    eax,DWORD PTR [esp+0x24]
    mov    ebp,DWORD PTR [esp+0x18]
    lea    ecx,[esp+0x10]
    push   edi
    push   ecx
    mov    ecx,DWORD PTR [esp+0x34]
    push   edx
    mov    edx,DWORD PTR [esp+0x2c]
    push   eax
    push   ecx
    push   R6GameServiceAddresses::InflateLengthExtraBits
    push   R6GameServiceAddresses::InflateLengthBases
    push   0x101
    push   ebp
    push   edx
    call   R6GameServiceAddresses::BuildHuffmanLookupTable
    mov    esi,eax
    test   esi,esi
    jne    Branch12
    mov    eax,DWORD PTR [esp+0x24]
    cmp    DWORD PTR [eax],0x0
    je     Branch14
    mov    edx,DWORD PTR [esp+0x34]
    mov    eax,DWORD PTR [esp+0x28]
    lea    ecx,[esp+0x10]
    push   edi
    push   ecx
    mov    ecx,DWORD PTR [esp+0x38]
    push   edx
    mov    edx,DWORD PTR [esp+0x28]
    push   eax
    mov    eax,DWORD PTR [esp+0x30]
    push   ecx
    push   R6GameServiceAddresses::InflateDistanceExtraBits
    push   R6GameServiceAddresses::InflateDistanceBases
    push   esi
    lea    ecx,[eax+ebp*4]
    push   edx
    push   ecx
    call   R6GameServiceAddresses::BuildHuffmanLookupTable
    mov    esi,eax
    test   esi,esi
    jne    Branch7
    mov    edx,DWORD PTR [esp+0x28]
    cmp    DWORD PTR [edx],0x0
    jne    Branch6
    cmp    ebp,0x101
    ja     Branch10
  Branch6:
    mov    eax,DWORD PTR [ebx+0x28]
    push   edi
    push   eax
    call   DWORD PTR [ebx+0x24]
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    pop    ecx
    ret    0x24
  Branch7:
    cmp    esi,0xfffffffd
    jne    Branch8
    mov    ecx,DWORD PTR [ebx+0x28]
    push   edi
    push   ecx
    mov    DWORD PTR [ebx+0x18],R6GameServiceAddresses::TextOversubscribedDistanceTree
    call   DWORD PTR [ebx+0x24]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x24
  Branch8:
    cmp    esi,0xfffffffb
    jne    Branch9
    mov    ecx,DWORD PTR [ebx+0x28]
    push   edi
    push   ecx
    mov    DWORD PTR [ebx+0x18],R6GameServiceAddresses::TextIncompleteDistanceTree
    mov    esi,0xfffffffd
    call   DWORD PTR [ebx+0x24]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x24
  Branch9:
    cmp    esi,0xfffffffc
    je     Branch11
  Branch10:
    mov    DWORD PTR [ebx+0x18],R6GameServiceAddresses::TextEmptyDistanceTreeWithLengths
    mov    esi,0xfffffffd
  Branch11:
    mov    ecx,DWORD PTR [ebx+0x28]
    push   edi
    push   ecx
    call   DWORD PTR [ebx+0x24]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x24
  Branch12:
    cmp    esi,0xfffffffd
    jne    Branch13
    mov    edx,DWORD PTR [ebx+0x28]
    push   edi
    push   edx
    mov    DWORD PTR [ebx+0x18],R6GameServiceAddresses::TextOversubscribedLiteralLengthTree
    call   DWORD PTR [ebx+0x24]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x24
  Branch13:
    cmp    esi,0xfffffffc
    je     Branch15
  Branch14:
    mov    DWORD PTR [ebx+0x18],R6GameServiceAddresses::TextIncompleteLiteralLengthTree
    mov    esi,0xfffffffd
  Branch15:
    mov    edx,DWORD PTR [ebx+0x28]
    push   edi
    push   edx
    call   DWORD PTR [ebx+0x24]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x24
  }
}

// Literal/length bases, including two zero entries for invalid codes.
// R6GameService.dll data @ 100767b8
static const uint InflateLengthBases[31] = {
  3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17,
  19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115,
  131, 163, 195, 227, 258, 0, 0,
};

// Literal extra-bit/invalid-code selectors; only low bytes are read by the builder.
// R6GameService.dll data @ 10076838
static const uint InflateLengthExtraBits[31] = {
  0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
  2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
  5, 5, 5, 5, 0, 112, 112,
};

// Distance bases used by the dynamic-tree wrapper.
// R6GameService.dll data @ 100768b8
static const uint InflateDistanceBases[30] = {
  1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49,
  65, 97, 129, 193, 257, 385, 513, 769, 1025, 1537, 2049, 3073,
  4097, 6145, 8193, 12289, 16385, 24577,
};

// Distance extra-bit selectors; only low bytes are read by the builder.
// R6GameService.dll data @ 10076930
static const uint InflateDistanceExtraBits[30] = {
  0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
  5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10,
  11, 11, 12, 12, 13, 13,
};

// Build canonical lookup levels in a caller-owned pool, preserving partial publications and raw record padding.
// R6GameService.dll @ 10022680 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall BuildHuffmanLookupTable(
  const uint *codeLengths,uint count,uint simpleSymbols,const uint *bases,const uint *extraBits,
  void **tree,uint *rootBits,void *tableStorage,uint *used,uint *symbolWork)
{
  __asm {
    sub    esp,0xfc
    push   ebx
    mov    ebx,DWORD PTR [esp+0x104]
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x110]
    xor    ebp,ebp
    push   edi
    mov    DWORD PTR [esp+0x50],ebp
    mov    DWORD PTR [esp+0x54],ebp
    mov    DWORD PTR [esp+0x58],ebp
    mov    DWORD PTR [esp+0x5c],ebp
    mov    DWORD PTR [esp+0x60],ebp
    mov    DWORD PTR [esp+0x64],ebp
    mov    DWORD PTR [esp+0x68],ebp
    mov    DWORD PTR [esp+0x6c],ebp
    mov    DWORD PTR [esp+0x70],ebp
    mov    DWORD PTR [esp+0x74],ebp
    mov    DWORD PTR [esp+0x78],ebp
    mov    DWORD PTR [esp+0x7c],ebp
    mov    DWORD PTR [esp+0x80],ebp
    mov    DWORD PTR [esp+0x84],ebp
    mov    DWORD PTR [esp+0x88],ebp
    mov    DWORD PTR [esp+0x8c],ebp
    mov    ecx,ebx
    mov    edx,esi
  Branch16:
    mov    eax,DWORD PTR [ecx]
    add    ecx,0x4
    mov    edi,DWORD PTR [esp+eax*4+0x50]
    lea    eax,[esp+eax*4+0x50]
    inc    edi
    dec    edx
    mov    DWORD PTR [eax],edi
    jne    Branch16
    mov    eax,DWORD PTR [esp+0x50]
    mov    edx,DWORD PTR [esp+0x128]
    cmp    eax,esi
    jne    Branch18
    mov    ecx,DWORD PTR [esp+0x124]
    mov    DWORD PTR [ecx],ebp
    mov    DWORD PTR [edx],ebp
  Branch17:
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0xfc
    ret    0x28
  Branch18:
    mov    eax,DWORD PTR [edx]
    mov    ecx,0x1
    mov    DWORD PTR [esp+0x10],eax
  Branch19:
    cmp    DWORD PTR [esp+ecx*4+0x50],ebp
    jne    Branch20
    inc    ecx
    cmp    ecx,0xf
    jbe    Branch19
  Branch20:
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x14],ecx
    jae    Branch21
    mov    DWORD PTR [esp+0x10],ecx
    mov    eax,ecx
  Branch21:
    mov    esi,0xf
  Branch22:
    cmp    DWORD PTR [esp+esi*4+0x50],ebp
    jne    Branch23
    dec    esi
    jne    Branch22
  Branch23:
    cmp    eax,esi
    mov    DWORD PTR [esp+0x28],esi
    jbe    Branch24
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,esi
  Branch24:
    mov    DWORD PTR [edx],eax
    mov    edx,0x1
    shl    edx,cl
    cmp    ecx,esi
    jae    Branch26
  Branch25:
    sub    edx,DWORD PTR [esp+ecx*4+0x50]
    js     Branch27
    inc    ecx
    add    edx,edx
    cmp    ecx,esi
    jb     Branch25
  Branch26:
    lea    ecx,[esi*4+0x0]
    mov    DWORD PTR [esp+0x30],ecx
    lea    edi,[esp+ecx*1+0x50]
    mov    ecx,DWORD PTR [esp+ecx*1+0x50]
    sub    edx,ecx
    mov    DWORD PTR [esp+0x4c],edx
    jns    Branch28
  Branch27:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffd
    pop    ebx
    add    esp,0xfc
    ret    0x28
  Branch28:
    add    ecx,edx
    mov    DWORD PTR [esp+0x94],ebp
    mov    DWORD PTR [edi],ecx
    xor    ecx,ecx
    dec    esi
    je     Branch30
    xor    edi,edi
  Branch29:
    add    ecx,DWORD PTR [esp+edi*1+0x54]
    add    edi,0x4
    dec    esi
    mov    DWORD PTR [esp+edi*1+0x94],ecx
    jne    Branch29
  Branch30:
    mov    esi,ebx
    xor    edi,edi
  Branch31:
    mov    ecx,DWORD PTR [esi]
    add    esi,0x4
    cmp    ecx,ebp
    mov    DWORD PTR [esp+0x20],esi
    je     Branch32
    mov    esi,DWORD PTR [esp+ecx*4+0x90]
    mov    ebx,DWORD PTR [esp+0x134]
    lea    ecx,[esp+ecx*4+0x90]
    mov    DWORD PTR [ebx+esi*4],edi
    inc    esi
    mov    DWORD PTR [ecx],esi
    mov    esi,DWORD PTR [esp+0x20]
  Branch32:
    mov    ecx,DWORD PTR [esp+0x114]
    inc    edi
    cmp    edi,ecx
    jb     Branch31
    mov    ecx,DWORD PTR [esp+0x30]
    mov    esi,DWORD PTR [esp+0x28]
    mov    ebx,eax
    xor    edi,edi
    mov    ecx,DWORD PTR [esp+ecx*1+0x90]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x114],ecx
    mov    ecx,DWORD PTR [esp+0x134]
    mov    DWORD PTR [esp+0x20],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    neg    ebx
    cmp    ecx,esi
    mov    DWORD PTR [esp+0x90],ebp
    mov    DWORD PTR [esp+0x18],0xffffffff
    mov    DWORD PTR [esp+0xd0],edi
    mov    DWORD PTR [esp+0x30],edi
    jg     Branch54
    mov    esi,DWORD PTR [esp+0x38]
    lea    edx,[ecx-0x1]
    mov    DWORD PTR [esp+0x40],edx
    lea    edx,[esp+ecx*4+0x50]
    mov    DWORD PTR [esp+0x24],edx
  Branch33:
    mov    edx,DWORD PTR [esp+0x24]
    mov    edx,DWORD PTR [edx]
    test   edx,edx
    mov    DWORD PTR [esp+0x1c],edx
    je     Branch53
  Branch34:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x14]
    dec    ecx
    mov    DWORD PTR [esp+0x1c],ecx
    lea    ecx,[ebx+eax*1]
    cmp    edx,ecx
    jle    Branch42
    mov    DWORD PTR [esp+0x3c],ecx
    mov    ecx,ebx
    sub    ecx,eax
    jmp    Branch36
  Branch35:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x44]
  Branch36:
    mov    ebp,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x28]
    inc    ebp
    add    ebx,eax
    mov    DWORD PTR [esp+0x18],ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    sub    edx,ebx
    add    ecx,eax
    add    ebp,eax
    cmp    edx,eax
    mov    DWORD PTR [esp+0x44],ecx
    mov    DWORD PTR [esp+0x3c],ebp
    jbe    Branch37
    mov    edx,eax
  Branch37:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [esp+0x1c]
    sub    ecx,ebx
    mov    eax,0x1
    shl    eax,cl
    lea    edi,[ebp+0x1]
    cmp    eax,edi
    jbe    Branch39
    or     edi,0xffffffff
    sub    edi,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    add    eax,edi
    cmp    ecx,edx
    jae    Branch39
    inc    ecx
    cmp    ecx,edx
    jae    Branch39
  Branch38:
    mov    edi,DWORD PTR [ebp+0x4]
    add    ebp,0x4
    add    eax,eax
    cmp    eax,edi
    jbe    Branch39
    sub    eax,edi
    inc    ecx
    cmp    ecx,edx
    jb     Branch38
  Branch39:
    mov    eax,DWORD PTR [esp+0x130]
    mov    edi,0x1
    shl    edi,cl
    mov    eax,DWORD PTR [eax]
    lea    edx,[eax+edi*1]
    cmp    edx,0x5a0
    ja     Branch27
    mov    ebp,DWORD PTR [esp+0x12c]
    lea    ebp,[ebp+eax*8+0x0]
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x30],ebp
    lea    eax,[esp+eax*4+0xd0]
    mov    DWORD PTR [esp+0x48],eax
    mov    DWORD PTR [eax],ebp
    mov    eax,DWORD PTR [esp+0x130]
    mov    DWORD PTR [eax],edx
    mov    eax,DWORD PTR [esp+0x18]
    test   eax,eax
    je     Branch40
    mov    esi,DWORD PTR [esp+0x2c]
    mov    BYTE PTR [esp+0x34],cl
    mov    ecx,DWORD PTR [esp+0x44]
    mov    DWORD PTR [esp+eax*4+0x90],esi
    mov    dl,BYTE PTR [esp+0x10]
    mov    eax,esi
    shr    eax,cl
    mov    ecx,DWORD PTR [esp+0x48]
    mov    esi,ebp
    mov    BYTE PTR [esp+0x35],dl
    mov    edx,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [ecx-0x4]
    sub    esi,ecx
    sar    esi,0x3
    sub    esi,eax
    mov    DWORD PTR [ecx+eax*8],edx
    mov    DWORD PTR [ecx+eax*8+0x4],esi
    jmp    Branch41
  Branch40:
    mov    eax,DWORD PTR [esp+0x124]
    mov    DWORD PTR [eax],ebp
  Branch41:
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [esp+0x14]
    cmp    eax,ecx
    jg     Branch35
    mov    ebp,DWORD PTR [esp+0x2c]
  Branch42:
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x134]
    mov    al,dl
    sub    al,bl
    mov    BYTE PTR [esp+0x35],al
    mov    eax,DWORD PTR [esp+0x114]
    lea    ecx,[ecx+eax*4]
    mov    eax,DWORD PTR [esp+0x20]
    cmp    eax,ecx
    jb     Branch43
    mov    BYTE PTR [esp+0x34],0xc0
    jmp    Branch46
  Branch43:
    mov    esi,DWORD PTR [eax]
    mov    ecx,DWORD PTR [esp+0x118]
    cmp    esi,ecx
    jae    Branch44
    cmp    esi,0x100
    sbb    cl,cl
    and    cl,0xa0
    add    cl,0x60
    mov    BYTE PTR [esp+0x34],cl
    jmp    Branch45
  Branch44:
    sub    esi,ecx
    mov    ecx,DWORD PTR [esp+0x120]
    shl    esi,0x2
    mov    cl,BYTE PTR [esi+ecx*1]
    add    cl,0x50
    mov    BYTE PTR [esp+0x34],cl
    mov    ecx,DWORD PTR [esp+0x11c]
    mov    esi,DWORD PTR [esi+ecx*1]
  Branch45:
    add    eax,0x4
    mov    DWORD PTR [esp+0x20],eax
  Branch46:
    mov    ecx,edx
    mov    edx,0x1
    sub    ecx,ebx
    mov    eax,ebp
    shl    edx,cl
    mov    ecx,ebx
    shr    eax,cl
    cmp    eax,edi
    jae    Branch48
    mov    ecx,DWORD PTR [esp+0x30]
    lea    ecx,[ecx+eax*8]
  Branch47:
    mov    ebp,DWORD PTR [esp+0x34]
    mov    DWORD PTR [ecx+0x4],esi
    mov    DWORD PTR [ecx],ebp
    lea    ebp,[edx*8+0x0]
    add    eax,edx
    add    ecx,ebp
    cmp    eax,edi
    jb     Branch47
    mov    ebp,DWORD PTR [esp+0x2c]
  Branch48:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,0x1
    shl    eax,cl
    test   ebp,eax
    je     Branch50
  Branch49:
    xor    ebp,eax
    shr    eax,1
    test   ebp,eax
    jne    Branch49
  Branch50:
    mov    edx,0x1
    mov    ecx,ebx
    shl    edx,cl
    xor    ebp,eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ecx,DWORD PTR [esp+eax*4+0x90]
    dec    edx
    and    edx,ebp
    cmp    edx,ecx
    je     Branch52
  Branch51:
    mov    edx,DWORD PTR [esp+0x10]
    dec    eax
    sub    ebx,edx
    mov    edx,0x1
    mov    ecx,ebx
    shl    edx,cl
    mov    ecx,DWORD PTR [esp+eax*4+0x90]
    dec    edx
    and    edx,ebp
    cmp    edx,ecx
    jne    Branch51
    mov    DWORD PTR [esp+0x18],eax
  Branch52:
    mov    eax,DWORD PTR [esp+0x1c]
    test   eax,eax
    mov    eax,DWORD PTR [esp+0x10]
    jne    Branch34
    mov    ecx,DWORD PTR [esp+0x14]
  Branch53:
    mov    edx,DWORD PTR [esp+0x24]
    inc    ecx
    add    edx,0x4
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,DWORD PTR [esp+0x40]
    inc    edx
    mov    DWORD PTR [esp+0x40],edx
    mov    edx,DWORD PTR [esp+0x28]
    cmp    ecx,edx
    jle    Branch33
    mov    edx,DWORD PTR [esp+0x4c]
  Branch54:
    test   edx,edx
    je     Branch17
    cmp    DWORD PTR [esp+0x28],0x1
    je     Branch17
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffb
    pop    ebx
    add    esp,0xfc
    ret    0x28
  }
}
