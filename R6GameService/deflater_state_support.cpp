#include "native_addresses.h"

// Shared deflate initialization and lifetime operations. Names and pointer types are descriptive inferences.
// Native stdcall callbacks and explicit offsets preserve current versus cached fields and partial effects.

// Four match thresholds and a native compressor entry per level; field spellings are inferred.
// R6GameService.dll data @ 10075c88 : ten 12-byte records; helpers read halfwords in native order.
struct DeflateLevelConfigurationRecord { ushort good, lazy, nice, chain; uint nativeCompressor; };
static const DeflateLevelConfigurationRecord DeflateLevelConfigurations[10] = {
  {0, 0, 0, 0, R6GameServiceAddresses::CompressStoredDeflate},
  {4, 4, 8, 4, R6GameServiceAddresses::CompressFastDeflate},
  {4, 5, 16, 8, R6GameServiceAddresses::CompressFastDeflate},
  {4, 6, 32, 32, R6GameServiceAddresses::CompressFastDeflate},
  {4, 4, 16, 16, R6GameServiceAddresses::CompressLazyDeflate},
  {8, 16, 32, 32, R6GameServiceAddresses::CompressLazyDeflate},
  {8, 16, 128, 128, R6GameServiceAddresses::CompressLazyDeflate},
  {8, 32, 128, 256, R6GameServiceAddresses::CompressLazyDeflate},
  {32, 128, 258, 1024, R6GameServiceAddresses::CompressLazyDeflate},
  {32, 258, 258, 4096, R6GameServiceAddresses::CompressLazyDeflate},
};

// Forward captured stream/level/version/size with method 8, window 15, memory level 8 and strategy 0.
// R6GameService.dll @ 1001e230 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DeflateInit(void *stream,int level,const char *version,uint streamSize)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    mov    eax,DWORD PTR [esp+0x8]
    push   ecx
    push   0x0
    push   0x8
    push   0xf
    push   0x8
    push   edx
    push   eax
    call   R6GameServiceAddresses::InitializeDeflateStream
    ret    0x10
  }
}

// Validate options, allocate deflate state/buffers, publish current fields and forward reset status.
// R6GameService.dll @ 1001e260 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall InitializeDeflateStream(void *stream,int level,int method,
  int windowBits,int memoryLevel,int strategy,const char *version,uint streamSize)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x1c]
    push   ebx
    push   ebp
    xor    edx,edx
    xor    ebp,ebp
    push   esi
    cmp    eax,edx
    push   edi
    je     Branch9
    mov    ecx,DWORD PTR ds:0x1008c7bc
    mov    al,BYTE PTR [eax]
    cmp    al,BYTE PTR [ecx]
    jne    Branch9
    cmp    DWORD PTR [esp+0x30],0x38
    jne    Branch9
    mov    edi,DWORD PTR [esp+0x14]
    cmp    edi,edx
    jne    Branch2
  Branch1:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffe
    pop    ebx
    ret    0x20
  Branch2:
    mov    eax,DWORD PTR [edi+0x20]
    mov    DWORD PTR [edi+0x18],edx
    cmp    eax,edx
    jne    Branch3
    mov    DWORD PTR [edi+0x20],R6GameServiceAddresses::InflateAllocator
    mov    DWORD PTR [edi+0x28],edx
  Branch3:
    cmp    DWORD PTR [edi+0x24],edx
    jne    Branch4
    mov    DWORD PTR [edi+0x24],R6GameServiceAddresses::InflateFree
  Branch4:
    mov    ecx,DWORD PTR [esp+0x18]
    cmp    ecx,0xffffffff
    jne    Branch5
    mov    DWORD PTR [esp+0x18],0x6
    mov    ecx,DWORD PTR [esp+0x18]
  Branch5:
    mov    ebx,DWORD PTR [esp+0x20]
    cmp    ebx,edx
    jge    Branch6
    mov    ebp,0x1
    neg    ebx
  Branch6:
    mov    eax,DWORD PTR [esp+0x24]
    cmp    eax,0x1
    jl     Branch1
    cmp    eax,0x9
    jg     Branch1
    cmp    DWORD PTR [esp+0x1c],0x8
    jne    Branch1
    cmp    ebx,0x9
    jl     Branch1
    cmp    ebx,0xf
    jg     Branch1
    cmp    ecx,edx
    jl     Branch1
    cmp    ecx,0x9
    jg     Branch1
    mov    eax,DWORD PTR [esp+0x28]
    cmp    eax,edx
    jl     Branch1
    cmp    eax,0x2
    jg     Branch1
    mov    edx,DWORD PTR [edi+0x28]
    push   0x16b8
    push   0x1
    push   edx
    call   DWORD PTR [edi+0x20]
    mov    esi,eax
    test   esi,esi
    jne    Branch7
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffc
    pop    ebx
    ret    0x20
  Branch7:
    mov    DWORD PTR [edi+0x1c],esi
    mov    DWORD PTR [esi+0x18],ebp
    mov    ebp,0x1
    mov    ecx,ebx
    shl    ebp,cl
    mov    DWORD PTR [esi+0x28],ebx
    mov    ebx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esi],edi
    push   0x2
    lea    ecx,[ebx+0x7]
    mov    DWORD PTR [esi+0x48],ecx
    mov    DWORD PTR [esi+0x24],ebp
    lea    eax,[ebp-0x1]
    push   ebp
    mov    DWORD PTR [esi+0x2c],eax
    mov    eax,0x1
    shl    eax,cl
    add    ecx,0x2
    mov    DWORD PTR [esi+0x44],eax
    dec    eax
    mov    DWORD PTR [esi+0x4c],eax
    mov    eax,0xaaaaaaab
    mul    ecx
    shr    edx,1
    mov    DWORD PTR [esi+0x50],edx
    mov    ecx,DWORD PTR [edi+0x28]
    push   ecx
    call   DWORD PTR [edi+0x20]
    mov    edx,DWORD PTR [esi+0x24]
    mov    DWORD PTR [esi+0x30],eax
    mov    eax,DWORD PTR [edi+0x28]
    push   0x2
    push   edx
    push   eax
    call   DWORD PTR [edi+0x20]
    mov    ecx,DWORD PTR [esi+0x44]
    mov    DWORD PTR [esi+0x38],eax
    mov    edx,DWORD PTR [edi+0x28]
    push   0x2
    push   ecx
    push   edx
    call   DWORD PTR [edi+0x20]
    mov    DWORD PTR [esi+0x3c],eax
    lea    ecx,[ebx+0x6]
    mov    eax,0x1
    push   0x4
    shl    eax,cl
    mov    DWORD PTR [esi+0x1694],eax
    push   eax
    mov    eax,DWORD PTR [edi+0x28]
    push   eax
    call   DWORD PTR [edi+0x20]
    mov    ecx,DWORD PTR [esi+0x1694]
    mov    DWORD PTR [esi+0x8],eax
    lea    edx,[ecx*4+0x0]
    mov    DWORD PTR [esi+0xc],edx
    mov    edx,DWORD PTR [esi+0x30]
    test   edx,edx
    je     Branch8
    mov    edx,DWORD PTR [esi+0x38]
    test   edx,edx
    je     Branch8
    mov    edx,DWORD PTR [esi+0x3c]
    test   edx,edx
    je     Branch8
    test   eax,eax
    je     Branch8
    mov    edx,ecx
    push   edi
    shr    edx,1
    mov    BYTE PTR [esi+0x1d],0x8
    lea    edx,[eax+edx*2]
    lea    eax,[eax+ecx*2]
    add    ecx,eax
    mov    DWORD PTR [esi+0x169c],edx
    mov    edx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [esi+0x1690],ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x80],edx
    mov    DWORD PTR [esi+0x7c],ecx
    call   R6GameServiceAddresses::ResetDeflateStream
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x20
  Branch8:
    mov    eax,ds:0x1008c84c
    push   edi
    mov    DWORD PTR [edi+0x18],eax
    call   R6GameServiceAddresses::EndDeflateStream
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffc
    pop    ebx
    ret    0x20
  Branch9:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffa
    pop    ebx
    ret    0x20
  }
}

// Reset stream counters and cached deflate state, then reset code tables and match configuration.
// R6GameService.dll @ 1001e460 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetDeflateStream(void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    xor    ecx,ecx
    cmp    eax,ecx
    push   esi
    je     Branch11
    mov    esi,DWORD PTR [eax+0x1c]
    cmp    esi,ecx
    je     Branch11
    cmp    DWORD PTR [eax+0x20],ecx
    je     Branch11
    cmp    DWORD PTR [eax+0x24],ecx
    je     Branch11
    mov    DWORD PTR [eax+0x14],ecx
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0x18],ecx
    mov    DWORD PTR [eax+0x2c],0x2
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esi+0x14],ecx
    mov    DWORD PTR [esi+0x10],edx
    mov    edx,DWORD PTR [esi+0x18]
    cmp    edx,ecx
    jge    Branch10
    mov    DWORD PTR [esi+0x18],ecx
  Branch10:
    mov    edx,DWORD PTR [esi+0x18]
    push   esi
    neg    edx
    sbb    edx,edx
    and    edx,0x47
    add    edx,0x2a
    mov    DWORD PTR [esi+0x4],edx
    mov    DWORD PTR [eax+0x30],0x1
    mov    DWORD PTR [esi+0x20],ecx
    call   R6GameServiceAddresses::ResetDeflateCodeTables
    push   esi
    call   R6GameServiceAddresses::ResetDeflateMatchState
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch11:
    mov    eax,0xfffffffe
    pop    esi
    ret    0x4
  }
}

// Release current pending/hash/previous/window/state allocations, clear state and report captured status.
// R6GameService.dll @ 1001e850 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall EndDeflateStream(void *stream)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    test   esi,esi
    push   edi
    je     Branch17
    mov    eax,DWORD PTR [esi+0x1c]
    test   eax,eax
    je     Branch17
    mov    edi,DWORD PTR [eax+0x4]
    cmp    edi,0x2a
    je     Branch12
    cmp    edi,0x71
    je     Branch12
    cmp    edi,0x29a
    jne    Branch17
  Branch12:
    mov    eax,DWORD PTR [eax+0x8]
    test   eax,eax
    je     Branch13
    push   eax
    mov    eax,DWORD PTR [esi+0x28]
    push   eax
    call   DWORD PTR [esi+0x24]
  Branch13:
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    eax,DWORD PTR [ecx+0x3c]
    test   eax,eax
    je     Branch14
    mov    edx,DWORD PTR [esi+0x28]
    push   eax
    push   edx
    call   DWORD PTR [esi+0x24]
  Branch14:
    mov    eax,DWORD PTR [esi+0x1c]
    mov    eax,DWORD PTR [eax+0x38]
    test   eax,eax
    je     Branch15
    mov    ecx,DWORD PTR [esi+0x28]
    push   eax
    push   ecx
    call   DWORD PTR [esi+0x24]
  Branch15:
    mov    edx,DWORD PTR [esi+0x1c]
    mov    eax,DWORD PTR [edx+0x30]
    test   eax,eax
    je     Branch16
    push   eax
    mov    eax,DWORD PTR [esi+0x28]
    push   eax
    call   DWORD PTR [esi+0x24]
  Branch16:
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    edx,DWORD PTR [esi+0x28]
    push   ecx
    push   edx
    call   DWORD PTR [esi+0x24]
    xor    eax,eax
    cmp    edi,0x71
    setne  al
    dec    eax
    mov    DWORD PTR [esi+0x1c],0x0
    pop    edi
    and    al,0xfd
    pop    esi
    ret    0x4
  Branch17:
    pop    edi
    mov    eax,0xfffffffe
    pop    esi
    ret    0x4
  }
}

// Clear the current hash-head storage, load level configuration and reset match cursors.
// R6GameService.dll @ 1001e8f0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetDeflateMatchState(void *state)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   ebx
    push   esi
    xor    esi,esi
    mov    eax,DWORD PTR [edx+0x24]
    mov    ecx,DWORD PTR [edx+0x44]
    add    eax,eax
    push   edi
    mov    DWORD PTR [edx+0x34],eax
    mov    eax,DWORD PTR [edx+0x3c]
    mov    WORD PTR [eax+ecx*2-0x2],si
    mov    ecx,DWORD PTR [edx+0x44]
    mov    edi,DWORD PTR [edx+0x3c]
    xor    eax,eax
    lea    ecx,[ecx+ecx*1-0x2]
    mov    ebx,ecx
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,ebx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [edx+0x7c]
    xor    ecx,ecx
    pop    edi
    lea    eax,[eax+eax*2]
    shl    eax,0x2
    mov    cx,WORD PTR [eax+0x10075c8a]
    mov    DWORD PTR [edx+0x78],ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+R6GameServiceAddresses::DeflateLevelConfigurations]
    mov    DWORD PTR [edx+0x84],ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+0x10075c8c]
    mov    DWORD PTR [edx+0x88],ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+0x10075c8e]
    mov    DWORD PTR [edx+0x64],esi
    mov    DWORD PTR [edx+0x54],esi
    mov    DWORD PTR [edx+0x6c],esi
    mov    eax,0x2
    mov    DWORD PTR [edx+0x60],esi
    mov    DWORD PTR [edx+0x40],esi
    pop    esi
    mov    DWORD PTR [edx+0x74],ecx
    mov    DWORD PTR [edx+0x70],eax
    mov    DWORD PTR [edx+0x58],eax
    pop    ebx
    ret    0x4
  }
}

// Set embedded tree descriptors and bit-buffer fields, then tail-forward to shared block reset.
// R6GameService.dll @ 10020460 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetDeflateCodeTables(void *state)
{
  __asm {
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    eax,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],eax
    lea    ecx,[eax+0x8c]
    lea    edx,[eax+0x980]
    mov    DWORD PTR [eax+0xb10],ecx
    lea    ecx,[eax+0xa74]
    mov    DWORD PTR [eax+0xb28],ecx
    xor    ecx,ecx
    mov    DWORD PTR [eax+0xb18],R6GameServiceAddresses::DeflateLiteralTreeDescriptor
    mov    DWORD PTR [eax+0xb1c],edx
    mov    DWORD PTR [eax+0xb24],R6GameServiceAddresses::DeflateDistanceTreeDescriptor
    mov    DWORD PTR [eax+0xb30],R6GameServiceAddresses::DeflateBitLengthTreeDescriptor
    mov    WORD PTR [eax+0x16b0],cx
    mov    DWORD PTR [eax+0x16b4],ecx
    mov    DWORD PTR [eax+0x16ac],0x8
    jmp    R6GameServiceAddresses::ResetDeflateBlockTables
  }
}

// Clear frequency halfwords/counters and seed the end-of-block literal frequency.
// R6GameService.dll @ 100204d0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetDeflateBlockTables(void *state)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   esi
    mov    ecx,0x11e
    xor    esi,esi
    lea    eax,[edx+0x8c]
  Branch18:
    mov    WORD PTR [eax],si
    add    eax,0x4
    dec    ecx
    jne    Branch18
    lea    eax,[edx+0x980]
    mov    ecx,0x1e
  Branch19:
    mov    WORD PTR [eax],si
    add    eax,0x4
    dec    ecx
    jne    Branch19
    lea    eax,[edx+0xa74]
    mov    ecx,0x13
  Branch20:
    mov    WORD PTR [eax],si
    add    eax,0x4
    dec    ecx
    jne    Branch20
    mov    DWORD PTR [edx+0x16a4],esi
    mov    DWORD PTR [edx+0x16a0],esi
    mov    DWORD PTR [edx+0x16a8],esi
    mov    DWORD PTR [edx+0x1698],esi
    mov    WORD PTR [edx+0x48c],0x1
    pop    esi
    ret    0x4
  }
}
