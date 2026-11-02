#include "native_addresses.h"

// Shared inflater block/table operations; source names/types are inferred.
// Native offsets, argument/local scratch, calling conventions and current/cached publication order remain explicit.

// Internal dispatch targets, not additional function bodies.
// R6GameService.dll data @ 1002026c
static const uint InflateBlockTargets[10] = {
  R6GameServiceAddresses::inflate_block_supportBranch4, R6GameServiceAddresses::inflate_block_supportBranch10, R6GameServiceAddresses::inflate_block_supportBranch13, R6GameServiceAddresses::inflate_block_supportBranch26, R6GameServiceAddresses::inflate_block_supportBranch29,
  R6GameServiceAddresses::inflate_block_supportBranch37, R6GameServiceAddresses::inflate_block_supportBranch52, R6GameServiceAddresses::inflate_block_supportBranch74, R6GameServiceAddresses::inflate_block_supportBranch78, R6GameServiceAddresses::inflate_block_supportBranch80,
};

// Internal dispatch targets, not additional function bodies.
// R6GameService.dll data @ 10020294
static const uint DeflateBlockTypeTargets[4] = {
  R6GameServiceAddresses::inflate_block_supportBranch7, R6GameServiceAddresses::inflate_block_supportBranch8, R6GameServiceAddresses::inflate_block_supportBranch9, R6GameServiceAddresses::inflate_block_supportBranch58,
};

// Code-length alphabet permutation used for dynamic headers.
// R6GameService.dll data @ 10075d00
static const uint InflateCodeLengthOrder[19] = {
  16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15
};

// Decode stored, fixed and dynamic blocks through resumable header, table, payload and drain states.
// R6GameService.dll @ 1001f680 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DecodeDeflateBlocks(void *state,void *stream,uint status)
{
  __asm {
    sub    esp,0x34
    mov    eax,DWORD PTR [esp+0x3c]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    push   ebp
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [ebx+0x20]
    mov    ebp,DWORD PTR [ebx+0x1c]
    mov    DWORD PTR [esp+0x8],ecx
    mov    ecx,DWORD PTR [ebx+0x34]
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,DWORD PTR [ebx+0x30]
    push   esi
    cmp    ecx,eax
    push   edi
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [esp+0x48],ecx
    jae    Branch1
    sub    eax,ecx
    dec    eax
    jmp    Branch2
  Branch1:
    mov    eax,DWORD PTR [ebx+0x2c]
    sub    eax,ecx
  Branch2:
    mov    DWORD PTR [esp+0x1c],eax
  Branch3:
    mov    eax,DWORD PTR [ebx]
    cmp    eax,0x9
    ja     Branch81
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::InflateBlockTargets]
  Branch4:
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [esp+0x18]
    cmp    ebp,0x3
    jae    Branch6
    mov    eax,DWORD PTR [esp+0x14]
  Branch5:
    test   eax,eax
    je     Branch56
    xor    ecx,ecx
    dec    eax
    mov    cl,BYTE PTR [edi]
    mov    DWORD PTR [esp+0x50],0x0
    mov    edx,ecx
    mov    ecx,ebp
    shl    edx,cl
    add    ebp,0x8
    mov    DWORD PTR [esp+0x14],eax
    or     esi,edx
    inc    edi
    cmp    ebp,0x3
    mov    DWORD PTR [esp+0x18],esi
    mov    DWORD PTR [esp+0x10],edi
    jb     Branch5
  Branch6:
    mov    eax,esi
    and    eax,0x7
    mov    ecx,eax
    shr    eax,1
    and    ecx,0x1
    cmp    eax,0x3
    mov    DWORD PTR [ebx+0x18],ecx
    ja     Branch3
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::DeflateBlockTypeTargets]
  Branch7:
    sub    ebp,0x3
    mov    DWORD PTR [ebx],0x1
    mov    ecx,ebp
    and    ecx,0x7
    shr    esi,0x3
    shr    esi,cl
    sub    ebp,ecx
    mov    DWORD PTR [esp+0x18],esi
    jmp    Branch3
  Branch8:
    mov    edx,DWORD PTR [esp+0x4c]
    lea    eax,[esp+0x24]
    push   edx
    lea    ecx,[esp+0x2c]
    push   eax
    lea    edx,[esp+0x34]
    push   ecx
    lea    eax,[esp+0x3c]
    push   edx
    push   eax
    call   R6GameServiceAddresses::GetFixedHuffmanTables
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [esp+0x28]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x30]
    push   edx
    mov    edx,DWORD PTR [esp+0x38]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AllocateHuffmanCodes
    test   eax,eax
    mov    DWORD PTR [ebx+0x4],eax
    je     Branch57
    shr    esi,0x3
    mov    DWORD PTR [esp+0x18],esi
    sub    ebp,0x3
    mov    DWORD PTR [ebx],0x6
    jmp    Branch3
  Branch9:
    shr    esi,0x3
    mov    DWORD PTR [esp+0x18],esi
    sub    ebp,0x3
    mov    DWORD PTR [ebx],0x3
    jmp    Branch3
  Branch10:
    mov    eax,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x14]
    mov    esi,DWORD PTR [esp+0x18]
    cmp    ebp,0x20
    jae    Branch12
  Branch11:
    xor    edx,edx
    cmp    edi,edx
    je     Branch59
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x50],edx
    mov    cl,BYTE PTR [eax]
    dec    edi
    mov    edx,ecx
    mov    ecx,ebp
    shl    edx,cl
    add    ebp,0x8
    mov    DWORD PTR [esp+0x14],edi
    or     esi,edx
    inc    eax
    cmp    ebp,0x20
    mov    DWORD PTR [esp+0x10],eax
    jb     Branch11
  Branch12:
    mov    edx,esi
    mov    ecx,esi
    not    edx
    and    ecx,0xffff
    shr    edx,0x10
    cmp    edx,ecx
    jne    Branch60
    xor    ebp,ebp
    mov    eax,ecx
    cmp    eax,ebp
    mov    DWORD PTR [ebx+0x4],ecx
    mov    DWORD PTR [esp+0x18],ebp
    je     Branch25
    mov    eax,0x2
    mov    DWORD PTR [ebx],eax
    jmp    Branch3
  Branch13:
    mov    edi,DWORD PTR [esp+0x14]
    test   edi,edi
    je     Branch61
    mov    ecx,DWORD PTR [esp+0x1c]
    test   ecx,ecx
    jne    Branch22
    mov    ecx,DWORD PTR [ebx+0x2c]
    mov    edx,DWORD PTR [esp+0x48]
    cmp    edx,ecx
    jne    Branch16
    mov    eax,DWORD PTR [ebx+0x30]
    mov    esi,DWORD PTR [ebx+0x28]
    cmp    eax,esi
    je     Branch16
    mov    edx,esi
    cmp    edx,eax
    mov    DWORD PTR [esp+0x48],edx
    jae    Branch14
    sub    eax,edx
    dec    eax
    mov    ecx,eax
    jmp    Branch15
  Branch14:
    sub    ecx,edx
  Branch15:
    test   ecx,ecx
    mov    DWORD PTR [esp+0x1c],ecx
    jne    Branch22
  Branch16:
    mov    eax,DWORD PTR [esp+0x50]
    mov    edi,DWORD PTR [esp+0x4c]
    push   eax
    push   edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    mov    edx,DWORD PTR [ebx+0x34]
    mov    esi,DWORD PTR [ebx+0x30]
    cmp    edx,esi
    mov    DWORD PTR [esp+0x50],eax
    mov    DWORD PTR [esp+0x48],edx
    jae    Branch17
    mov    ecx,esi
    sub    ecx,edx
    dec    ecx
    jmp    Branch18
  Branch17:
    mov    ecx,DWORD PTR [ebx+0x2c]
    sub    ecx,edx
  Branch18:
    mov    eax,DWORD PTR [ebx+0x2c]
    mov    DWORD PTR [esp+0x1c],ecx
    cmp    edx,eax
    mov    DWORD PTR [esp+0x20],eax
    jne    Branch21
    mov    eax,DWORD PTR [ebx+0x28]
    cmp    esi,eax
    je     Branch21
    mov    edx,eax
    cmp    edx,esi
    mov    DWORD PTR [esp+0x48],edx
    jae    Branch19
    sub    esi,edx
    dec    esi
    mov    ecx,esi
    jmp    Branch20
  Branch19:
    mov    ecx,DWORD PTR [esp+0x20]
    sub    ecx,edx
  Branch20:
    mov    DWORD PTR [esp+0x1c],ecx
  Branch21:
    test   ecx,ecx
    je     Branch62
    mov    edi,DWORD PTR [esp+0x14]
  Branch22:
    mov    eax,DWORD PTR [ebx+0x4]
    mov    DWORD PTR [esp+0x50],0x0
    cmp    eax,edi
    jbe    Branch23
    mov    eax,edi
  Branch23:
    cmp    eax,ecx
    jbe    Branch24
    mov    eax,ecx
  Branch24:
    mov    esi,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x48]
    mov    ecx,eax
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    mov    edx,DWORD PTR [esp+0x1c]
    and    ecx,0x3
    sub    edx,eax
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x14]
    mov    esi,DWORD PTR [esp+0x48]
    add    ecx,eax
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,DWORD PTR [ebx+0x4]
    sub    edi,eax
    add    esi,eax
    sub    ecx,eax
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x48],esi
    mov    DWORD PTR [esp+0x1c],edx
    mov    DWORD PTR [ebx+0x4],ecx
    jne    Branch3
  Branch25:
    mov    eax,DWORD PTR [ebx+0x18]
    neg    eax
    sbb    eax,eax
    and    eax,0x7
    mov    DWORD PTR [ebx],eax
    jmp    Branch3
  Branch26:
    mov    edi,DWORD PTR [esp+0x18]
    cmp    ebp,0xe
    jae    Branch28
    mov    esi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
  Branch27:
    test   esi,esi
    je     Branch63
    xor    ecx,ecx
    dec    esi
    mov    cl,BYTE PTR [eax]
    mov    DWORD PTR [esp+0x50],0x0
    mov    edx,ecx
    mov    ecx,ebp
    shl    edx,cl
    add    ebp,0x8
    mov    DWORD PTR [esp+0x14],esi
    or     edi,edx
    inc    eax
    cmp    ebp,0xe
    mov    DWORD PTR [esp+0x10],eax
    jb     Branch27
  Branch28:
    mov    eax,edi
    and    eax,0x3fff
    mov    ecx,eax
    mov    DWORD PTR [ebx+0x4],eax
    and    ecx,0x1f
    cmp    ecx,0x1d
    ja     Branch65
    shr    eax,0x5
    and    eax,0x1f
    cmp    eax,0x1d
    ja     Branch65
    mov    esi,DWORD PTR [esp+0x4c]
    lea    eax,[eax+ecx*1+0x102]
    push   0x4
    push   eax
    mov    ecx,DWORD PTR [esi+0x28]
    push   ecx
    call   DWORD PTR [esi+0x20]
    test   eax,eax
    mov    DWORD PTR [ebx+0xc],eax
    je     Branch64
    shr    edi,0xe
    sub    ebp,0xe
    mov    DWORD PTR [ebx+0x8],0x0
    mov    DWORD PTR [ebx],0x4
    jmp    Branch30
  Branch29:
    mov    edi,DWORD PTR [esp+0x18]
    mov    esi,DWORD PTR [esp+0x4c]
  Branch30:
    mov    edx,DWORD PTR [ebx+0x4]
    mov    eax,DWORD PTR [ebx+0x8]
    shr    edx,0xa
    add    edx,0x4
    cmp    eax,edx
    jae    Branch34
  Branch31:
    cmp    ebp,0x3
    jae    Branch33
    mov    eax,DWORD PTR [esp+0x10]
  Branch32:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch68
    mov    edx,ecx
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax]
    dec    edx
    mov    DWORD PTR [esp+0x14],edx
    mov    edx,ecx
    mov    ecx,ebp
    add    ebp,0x8
    shl    edx,cl
    mov    DWORD PTR [esp+0x50],0x0
    or     edi,edx
    inc    eax
    cmp    ebp,0x3
    mov    DWORD PTR [esp+0x10],eax
    jb     Branch32
  Branch33:
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    eax,edi
    and    eax,0x7
    sub    ebp,0x3
    mov    edx,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateCodeLengthOrder]
    mov    ecx,DWORD PTR [ebx+0xc]
    shr    edi,0x3
    mov    DWORD PTR [ecx+edx*4],eax
    mov    edx,DWORD PTR [ebx+0x8]
    inc    edx
    mov    DWORD PTR [ebx+0x8],edx
    mov    eax,edx
    mov    edx,DWORD PTR [ebx+0x4]
    shr    edx,0xa
    add    edx,0x4
    cmp    eax,edx
    jb     Branch31
  Branch34:
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    eax,0x13
    cmp    ecx,eax
    jae    Branch36
  Branch35:
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    edx,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateCodeLengthOrder]
    mov    ecx,DWORD PTR [ebx+0xc]
    mov    DWORD PTR [ecx+edx*4],0x0
    mov    edx,DWORD PTR [ebx+0x8]
    inc    edx
    mov    ecx,edx
    mov    DWORD PTR [ebx+0x8],edx
    cmp    ecx,eax
    jb     Branch35
  Branch36:
    mov    edx,DWORD PTR [ebx+0x24]
    push   esi
    lea    ecx,[ebx+0x14]
    lea    eax,[ebx+0x10]
    push   edx
    mov    edx,DWORD PTR [ebx+0xc]
    push   ecx
    push   eax
    push   edx
    mov    DWORD PTR [eax],0x7
    call   R6GameServiceAddresses::BuildCodeLengthHuffmanTree
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch66
    mov    DWORD PTR [ebx+0x8],eax
    mov    DWORD PTR [ebx],0x5
    jmp    Branch38
  Branch37:
    mov    edi,DWORD PTR [esp+0x18]
    mov    esi,DWORD PTR [esp+0x4c]
  Branch38:
    mov    ecx,DWORD PTR [ebx+0x4]
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,ecx
    and    ecx,0x1f
    shr    edx,0x5
    and    edx,0x1f
    lea    ecx,[edx+ecx*1+0x102]
    mov    edx,DWORD PTR [ebx+0x8]
    cmp    edx,ecx
    jae    Branch51
    jmp    Branch40
  Branch39:
    mov    eax,DWORD PTR [esp+0x10]
  Branch40:
    mov    ecx,DWORD PTR [ebx+0x10]
    cmp    ebp,ecx
    jae    Branch42
  Branch41:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch68
    mov    edx,ecx
    mov    ecx,ebp
    dec    edx
    add    ebp,0x8
    mov    DWORD PTR [esp+0x14],edx
    xor    edx,edx
    mov    dl,BYTE PTR [eax]
    mov    DWORD PTR [esp+0x50],0x0
    shl    edx,cl
    mov    ecx,DWORD PTR [ebx+0x10]
    or     edi,edx
    inc    eax
    cmp    ebp,ecx
    mov    DWORD PTR [esp+0x10],eax
    jb     Branch41
  Branch42:
    mov    ecx,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    edx,DWORD PTR [ebx+0x14]
    and    ecx,edi
    lea    edx,[edx+ecx*8]
    xor    ecx,ecx
    mov    cl,BYTE PTR [edx+0x1]
    mov    edx,DWORD PTR [edx+0x4]
    cmp    edx,0x10
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x38],edx
    jae    Branch43
    mov    eax,DWORD PTR [ebx+0x8]
    sub    ebp,ecx
    shr    edi,cl
    mov    ecx,DWORD PTR [ebx+0xc]
    mov    DWORD PTR [ecx+eax*4],edx
    mov    eax,DWORD PTR [ebx+0x8]
    inc    eax
    mov    DWORD PTR [ebx+0x8],eax
    jmp    Branch50
  Branch43:
    cmp    edx,0x12
    jne    Branch44
    mov    DWORD PTR [esp+0x20],0x7
    jmp    Branch45
  Branch44:
    lea    ecx,[edx-0xe]
    mov    DWORD PTR [esp+0x20],ecx
  Branch45:
    xor    ecx,ecx
    cmp    edx,0x12
    mov    edx,DWORD PTR [esp+0x20]
    sete   cl
    lea    ecx,[ecx*8+0x3]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    add    ecx,edx
    cmp    ebp,ecx
    mov    DWORD PTR [esp+0x34],ecx
    jae    Branch47
  Branch46:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch68
    mov    edx,ecx
    mov    ecx,ebp
    dec    edx
    add    ebp,0x8
    mov    DWORD PTR [esp+0x14],edx
    xor    edx,edx
    mov    dl,BYTE PTR [eax]
    mov    DWORD PTR [esp+0x50],0x0
    shl    edx,cl
    mov    ecx,DWORD PTR [esp+0x34]
    or     edi,edx
    inc    eax
    cmp    ebp,ecx
    mov    DWORD PTR [esp+0x10],eax
    jb     Branch46
  Branch47:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x18]
    shr    edi,cl
    mov    ecx,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateLowBitMasks]
    and    eax,edi
    add    edx,eax
    mov    eax,DWORD PTR [ebx+0x4]
    mov    DWORD PTR [esp+0x18],edx
    mov    edx,DWORD PTR [esp+0x1c]
    shr    edi,cl
    add    ecx,edx
    mov    edx,eax
    shr    edx,0x5
    and    edx,0x1f
    and    eax,0x1f
    sub    ebp,ecx
    mov    ecx,DWORD PTR [ebx+0x8]
    lea    eax,[edx+eax*1+0x102]
    mov    edx,DWORD PTR [esp+0x18]
    add    edx,ecx
    cmp    edx,eax
    ja     Branch69
    cmp    DWORD PTR [esp+0x38],0x10
    jne    Branch48
    cmp    ecx,0x1
    jb     Branch69
    mov    eax,DWORD PTR [ebx+0xc]
    mov    eax,DWORD PTR [eax+ecx*4-0x4]
    jmp    Branch49
  Branch48:
    xor    eax,eax
  Branch49:
    mov    edx,DWORD PTR [ebx+0xc]
    inc    ecx
    mov    DWORD PTR [edx+ecx*4-0x4],eax
    mov    edx,DWORD PTR [esp+0x18]
    dec    edx
    mov    DWORD PTR [esp+0x18],edx
    jne    Branch49
    mov    DWORD PTR [ebx+0x8],ecx
  Branch50:
    mov    eax,DWORD PTR [ebx+0x4]
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    edx,eax
    and    eax,0x1f
    shr    edx,0x5
    and    edx,0x1f
    lea    eax,[edx+eax*1+0x102]
    cmp    ecx,eax
    jb     Branch39
  Branch51:
    mov    ecx,DWORD PTR [ebx+0x24]
    mov    eax,DWORD PTR [ebx+0x4]
    push   esi
    push   ecx
    lea    edx,[esp+0x44]
    lea    ecx,[esp+0x48]
    push   edx
    push   ecx
    lea    edx,[esp+0x30]
    lea    ecx,[esp+0x28]
    push   edx
    mov    edx,DWORD PTR [ebx+0xc]
    push   ecx
    mov    ecx,eax
    shr    ecx,0x5
    and    ecx,0x1f
    and    eax,0x1f
    inc    ecx
    push   edx
    add    eax,0x101
    push   ecx
    push   eax
    mov    DWORD PTR [ebx+0x14],0x0
    mov    DWORD PTR [esp+0x3c],0x9
    mov    DWORD PTR [esp+0x44],0x6
    call   R6GameServiceAddresses::BuildDynamicHuffmanTrees
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch70
    mov    edx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [esp+0x40]
    mov    ecx,DWORD PTR [esp+0x20]
    push   esi
    push   edx
    mov    edx,DWORD PTR [esp+0x20]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AllocateHuffmanCodes
    test   eax,eax
    je     Branch72
    mov    DWORD PTR [ebx+0x4],eax
    mov    eax,DWORD PTR [ebx+0xc]
    mov    ecx,DWORD PTR [esi+0x28]
    push   eax
    push   ecx
    call   DWORD PTR [esi+0x24]
    mov    DWORD PTR [ebx],0x6
    jmp    Branch53
  Branch52:
    mov    edi,DWORD PTR [esp+0x18]
    mov    esi,DWORD PTR [esp+0x4c]
  Branch53:
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    edi,DWORD PTR [esi]
    mov    ecx,eax
    mov    DWORD PTR [esi+0x4],edx
    mov    edx,DWORD PTR [esi+0x8]
    sub    ecx,edi
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x50]
    add    edx,ecx
    mov    DWORD PTR [esi+0x8],edx
    mov    edx,DWORD PTR [esp+0x48]
    push   eax
    push   esi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::InflateHuffmanCodes
    cmp    eax,0x1
    jne    Branch76
    mov    ecx,DWORD PTR [ebx+0x4]
    push   esi
    push   ecx
    mov    DWORD PTR [esp+0x58],0x0
    call   R6GameServiceAddresses::FreeInflaterAllocation
    mov    eax,DWORD PTR [ebx+0x20]
    mov    ecx,DWORD PTR [ebx+0x34]
    mov    edi,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x4]
    mov    ebp,DWORD PTR [ebx+0x1c]
    mov    DWORD PTR [esp+0x18],eax
    mov    eax,DWORD PTR [ebx+0x30]
    mov    DWORD PTR [esp+0x10],edi
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [esp+0x48],ecx
    jae    Branch54
    sub    eax,ecx
    dec    eax
    jmp    Branch55
  Branch54:
    mov    eax,DWORD PTR [ebx+0x2c]
    sub    eax,ecx
  Branch55:
    mov    DWORD PTR [esp+0x1c],eax
    mov    eax,DWORD PTR [ebx+0x18]
    test   eax,eax
    jne    Branch73
    mov    DWORD PTR [ebx],0x0
    jmp    Branch3
  Branch56:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx+0x20],esi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ecx,edi
    mov    ebp,DWORD PTR [eax]
    mov    esi,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [esp+0x48]
    sub    ecx,ebp
    add    esi,ecx
    mov    ecx,DWORD PTR [esp+0x50]
    push   ecx
    push   eax
    mov    DWORD PTR [eax+0x4],0x0
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [eax],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch57:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],esi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [eax]
    mov    esi,DWORD PTR [eax+0x8]
    mov    ecx,edi
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [esp+0x48]
    sub    ecx,ebp
    add    esi,ecx
    push   0xfffffffc
    push   eax
    mov    DWORD PTR [eax+0x8],esi
    mov    DWORD PTR [eax],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch58:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx],0x9
    add    ebp,0xfffffffd
    shr    esi,0x3
    mov    DWORD PTR [eax+0x18],R6GameServiceAddresses::TextInvalidBlockType
    mov    DWORD PTR [ebx+0x20],esi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [eax]
    mov    edx,edi
    mov    DWORD PTR [eax+0x4],ecx
    sub    edx,ebp
    mov    DWORD PTR [eax],edi
    push   0xfffffffd
    jmp    Branch84
  Branch59:
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx+0x20],esi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [ecx]
    mov    edi,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,eax
    sub    edx,ebp
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esp+0x48]
    add    edi,edx
    mov    edx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [ecx+0x8],edi
    push   edx
    push   ecx
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch60:
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx],0x9
    mov    edx,eax
    push   0xfffffffd
    mov    DWORD PTR [ecx+0x18],R6GameServiceAddresses::TextInvalidStoredBlockLengths
    mov    DWORD PTR [ebx+0x20],esi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [ecx]
    mov    DWORD PTR [ecx+0x4],edi
    mov    edi,DWORD PTR [ecx+0x8]
    sub    edx,ebp
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esp+0x4c]
    add    edi,edx
    push   ecx
    mov    DWORD PTR [ecx+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch61:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx+0x20],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [eax]
    mov    edi,DWORD PTR [eax+0x8]
    mov    edx,ecx
    sub    edx,ebp
    mov    DWORD PTR [eax+0x4],0x0
    add    edi,edx
    mov    edx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [eax+0x8],edi
    mov    DWORD PTR [eax],ecx
    push   edx
    jmp    Branch85
  Branch62:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    esi,DWORD PTR [edi]
    mov    ebp,DWORD PTR [edi+0x8]
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,eax
    mov    DWORD PTR [edi],eax
    sub    ecx,esi
    add    ebp,ecx
    mov    DWORD PTR [edi+0x8],ebp
    mov    DWORD PTR [ebx+0x34],edx
    mov    edx,DWORD PTR [esp+0x50]
    push   edx
    push   edi
    push   ebx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch63:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [eax]
    mov    edi,DWORD PTR [eax+0x8]
    mov    edx,ecx
    mov    DWORD PTR [eax+0x4],0x0
    sub    edx,ebp
    mov    DWORD PTR [eax],ecx
    add    edi,edx
    mov    edx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [eax+0x8],edi
    push   edx
    jmp    Branch85
  Branch64:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x48]
    mov    ecx,eax
    push   0xfffffffc
    sub    ecx,ebp
    push   esi
    add    edi,ecx
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch65:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx],0x9
    push   0xfffffffd
    mov    DWORD PTR [eax+0x18],R6GameServiceAddresses::TextTooManyLengthOrDistanceSymbols
    mov    DWORD PTR [ebx+0x20],edi
    jmp    Branch82
  Branch66:
    cmp    DWORD PTR [esp+0x1c],0xfffffffd
    jne    Branch67
    mov    edx,DWORD PTR [ebx+0xc]
    mov    eax,DWORD PTR [esi+0x28]
    push   edx
    push   eax
    call   DWORD PTR [esi+0x24]
    mov    DWORD PTR [ebx],0x9
  Branch67:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,eax
    mov    DWORD PTR [esi+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    sub    edx,ebp
    add    edi,edx
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x48]
    push   ecx
    push   esi
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch68:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x48]
    sub    edx,ebp
    add    edi,edx
    push   ecx
    push   esi
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch69:
    mov    edx,DWORD PTR [ebx+0xc]
    mov    eax,DWORD PTR [esi+0x28]
    push   edx
    push   eax
    call   DWORD PTR [esi+0x24]
    mov    DWORD PTR [ebx],0x9
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::TextInvalidBitLengthRepeat
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x48]
    sub    edx,ebp
    add    edi,edx
    push   0xfffffffd
    push   esi
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch70:
    cmp    DWORD PTR [esp+0x1c],0xfffffffd
    jne    Branch71
    mov    ecx,DWORD PTR [ebx+0xc]
    mov    edx,DWORD PTR [esi+0x28]
    push   ecx
    push   edx
    call   DWORD PTR [esi+0x24]
    mov    DWORD PTR [ebx],0x9
  Branch71:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x48]
    mov    ecx,eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x1c]
    sub    ecx,ebp
    add    edi,ecx
    push   eax
    push   esi
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch72:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],edi
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi]
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,eax
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esp+0x48]
    sub    edx,ebp
    add    edi,edx
    push   0xfffffffc
    push   esi
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],eax
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch73:
    mov    DWORD PTR [ebx],0x7
    jmp    Branch75
  Branch74:
    mov    ecx,DWORD PTR [esp+0x48]
    mov    esi,DWORD PTR [esp+0x4c]
    mov    edi,DWORD PTR [esp+0x10]
  Branch75:
    mov    DWORD PTR [ebx+0x34],ecx
    mov    ecx,DWORD PTR [esp+0x50]
    push   ecx
    push   esi
    push   ebx
    call   R6GameServiceAddresses::CommitInflaterOutput
    mov    ecx,DWORD PTR [ebx+0x34]
    mov    edx,DWORD PTR [ebx+0x30]
    cmp    edx,ecx
    je     Branch77
    mov    edx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    DWORD PTR [ebx+0x20],edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [esi]
    mov    DWORD PTR [esi+0x4],edx
    mov    edx,edi
    mov    DWORD PTR [esi],edi
    sub    edx,ebp
    mov    ebp,DWORD PTR [esi+0x8]
    add    ebp,edx
    mov    DWORD PTR [esi+0x8],ebp
    mov    DWORD PTR [ebx+0x34],ecx
  Branch76:
    push   eax
    push   esi
    push   ebx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch77:
    mov    DWORD PTR [ebx],0x8
    jmp    Branch79
  Branch78:
    mov    ecx,DWORD PTR [esp+0x48]
    mov    esi,DWORD PTR [esp+0x4c]
    mov    edi,DWORD PTR [esp+0x10]
  Branch79:
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],eax
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    ebp,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esi+0x4],edx
    mov    edx,DWORD PTR [esi]
    mov    eax,edi
    sub    eax,edx
    push   0x1
    add    ebp,eax
    push   esi
    mov    DWORD PTR [esi+0x8],ebp
    mov    DWORD PTR [esi],edi
    push   ebx
    mov    DWORD PTR [ebx+0x34],ecx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  Branch80:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx+0x20],ecx
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    DWORD PTR [eax+0x4],edx
    push   0xfffffffd
    jmp    Branch83
  Branch81:
    mov    edx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx+0x20],edx
    push   0xfffffffe
  Branch82:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [ebx+0x1c],ebp
    mov    DWORD PTR [eax+0x4],ecx
  Branch83:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [eax]
    mov    edx,ecx
    mov    DWORD PTR [eax],ecx
    sub    edx,edi
  Branch84:
    add    DWORD PTR [eax+0x8],edx
  Branch85:
    mov    ecx,DWORD PTR [esp+0x4c]
    push   eax
    push   ebx
    mov    DWORD PTR [ebx+0x34],ecx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0xc
  }
}
