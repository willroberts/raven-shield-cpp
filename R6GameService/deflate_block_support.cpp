#include "native_addresses.h"

// Shared deflate block strategies, input/window maintenance and match search. Names and types are inferred.
// Explicit native operations retain hash/table widths, field reloads, forward-copy order and raw stdcall results.

// Distance-minus-one code lookup, including the high-distance table at byte256.
// R6GameService.dll data @ 10076398 : selected 512-byte lookup; descriptive name.
static const byte DeflateDistanceCodes[512] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
  0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
  0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
  0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
  0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
  0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
  0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
  0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
  0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
  0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
  0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
  0x00, 0x00, 0x10, 0x11, 0x12, 0x12, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x15, 0x15, 0x15, 0x15,
  0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
  0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
  0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
  0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b,
  0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
  0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
  0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d,
  0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d,
  0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d,
  0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d,
};

// Match-length-minus-three code lookup used by inline tally operations.
// R6GameService.dll data @ 10076598 : selected 256-byte lookup; descriptive name.
static const byte DeflateLengthCodes[256] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x09, 0x09, 0x0a, 0x0a, 0x0b, 0x0b,
  0x0c, 0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
  0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
  0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15,
  0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
  0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
  0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
  0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
  0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b,
  0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1c,
};

// Copy the pending/output minimum forward, reload current state for updates and reset its cursor when empty.
// R6GameService.dll @ 1001e7d0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DrainDeflatePending(void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [eax+0x1c]
    mov    ecx,DWORD PTR [eax+0x10]
    mov    edx,DWORD PTR [esi+0x14]
    cmp    edx,ecx
    jbe    Branch1
    mov    edx,ecx
  Branch1:
    test   edx,edx
    je     Branch2
    mov    esi,DWORD PTR [esi+0x10]
    mov    ecx,edx
    push   ebx
    mov    ebx,ecx
    push   edi
    mov    edi,DWORD PTR [eax+0xc]
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,ebx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edi,DWORD PTR [eax+0xc]
    mov    ecx,DWORD PTR [eax+0x1c]
    add    edi,edx
    mov    DWORD PTR [eax+0xc],edi
    mov    esi,DWORD PTR [ecx+0x10]
    add    esi,edx
    mov    DWORD PTR [ecx+0x10],esi
    mov    ebx,DWORD PTR [eax+0x14]
    mov    edi,DWORD PTR [eax+0x10]
    mov    ecx,DWORD PTR [eax+0x1c]
    add    ebx,edx
    sub    edi,edx
    mov    DWORD PTR [eax+0x14],ebx
    mov    DWORD PTR [eax+0x10],edi
    mov    esi,DWORD PTR [ecx+0x14]
    pop    edi
    sub    esi,edx
    pop    ebx
    mov    DWORD PTR [ecx+0x14],esi
    mov    eax,DWORD PTR [eax+0x1c]
    mov    ecx,DWORD PTR [eax+0x14]
    test   ecx,ecx
    jne    Branch2
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [eax+0x10],ecx
  Branch2:
    pop    esi
    ret    0x4
  }
}

// Consume lookahead into stored blocks, flush at cached pending/window limits and return native block status.
// R6GameService.dll @ 1001e990 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CompressStoredDeflate(void *state,int flush)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,0xffff
    mov    eax,DWORD PTR [esi+0xc]
    add    eax,0xfffffffb
    cmp    eax,edi
    jae    Branch3
    mov    edi,eax
  Branch3:
    mov    eax,DWORD PTR [esi+0x6c]
    cmp    eax,0x1
    ja     Branch4
    push   esi
    call   R6GameServiceAddresses::FillDeflateWindow
    mov    eax,DWORD PTR [esi+0x6c]
    test   eax,eax
    je     Branch12
  Branch4:
    mov    ecx,DWORD PTR [esi+0x64]
    mov    DWORD PTR [esi+0x6c],0x0
    add    ecx,eax
    mov    DWORD PTR [esi+0x64],ecx
    mov    ecx,DWORD PTR [esi+0x54]
    mov    edx,DWORD PTR [esi+0x64]
    lea    eax,[ecx+edi*1]
    je     Branch5
    cmp    edx,eax
    jb     Branch8
  Branch5:
    sub    edx,eax
    mov    DWORD PTR [esi+0x64],eax
    test   ecx,ecx
    mov    DWORD PTR [esi+0x6c],edx
    jl     Branch6
    mov    edx,DWORD PTR [esi+0x30]
    add    edx,ecx
    jmp    Branch7
  Branch6:
    xor    edx,edx
  Branch7:
    sub    eax,ecx
    push   0x0
    push   eax
    push   edx
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x10]
    test   eax,eax
    je     Branch11
  Branch8:
    mov    ecx,DWORD PTR [esi+0x54]
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x24]
    sub    edx,ecx
    sub    eax,0x106
    cmp    edx,eax
    jb     Branch3
    test   ecx,ecx
    jl     Branch9
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch10
  Branch9:
    xor    eax,eax
  Branch10:
    push   0x0
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esi+0x64]
    push   edx
    mov    DWORD PTR [esi+0x54],ecx
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    jne    Branch3
  Branch11:
    pop    edi
    xor    eax,eax
    pop    esi
    ret    0x8
  Branch12:
    mov    edi,DWORD PTR [esp+0x10]
    test   edi,edi
    je     Branch11
    mov    ecx,DWORD PTR [esi+0x54]
    test   ecx,ecx
    jl     Branch13
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch14
  Branch13:
    xor    eax,eax
  Branch14:
    xor    edx,edx
    cmp    edi,0x4
    sete   dl
    push   edx
    mov    edx,DWORD PTR [esi+0x64]
    sub    edx,ecx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x10]
    test   eax,eax
    jne    Branch15
    xor    eax,eax
    cmp    edi,0x4
    setne  al
    dec    eax
    pop    edi
    and    eax,0x2
    pop    esi
    ret    0x8
  Branch15:
    xor    eax,eax
    cmp    edi,0x4
    sete   al
    pop    edi
    pop    esi
    lea    eax,[eax+eax*1+0x1]
    ret    0x8
  }
}

// Slide window/hash chains when needed, read input into current window and initialize the rolling hash.
// R6GameService.dll @ 1001ead0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall FillDeflateWindow(void *state)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   ebp
    push   esi
    mov    ebp,DWORD PTR [ebx+0x24]
    push   edi
  Branch16:
    mov    eax,DWORD PTR [ebx+0x64]
    mov    edx,DWORD PTR [ebx+0x34]
    mov    ecx,DWORD PTR [ebx+0x6c]
    sub    edx,eax
    sub    edx,ecx
    jne    Branch17
    test   eax,eax
    jne    Branch18
    test   ecx,ecx
    jne    Branch18
    mov    edx,ebp
    jmp    Branch25
  Branch17:
    cmp    edx,0xffffffff
    jne    Branch18
    mov    edx,0xfffffffe
    jmp    Branch25
  Branch18:
    mov    ecx,DWORD PTR [ebx+0x24]
    lea    ecx,[ecx+ebp*1-0x106]
    cmp    eax,ecx
    jb     Branch25
    mov    edi,DWORD PTR [ebx+0x30]
    mov    ecx,ebp
    mov    eax,ecx
    lea    esi,[edi+ebp*1]
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    esi,DWORD PTR [ebx+0x68]
    mov    ecx,DWORD PTR [ebx+0x64]
    mov    eax,DWORD PTR [ebx+0x54]
    sub    esi,ebp
    sub    ecx,ebp
    mov    DWORD PTR [ebx+0x68],esi
    mov    esi,DWORD PTR [ebx+0x44]
    mov    DWORD PTR [ebx+0x64],ecx
    mov    ecx,DWORD PTR [ebx+0x3c]
    sub    eax,ebp
    mov    DWORD PTR [ebx+0x54],eax
    lea    ecx,[ecx+esi*2]
  Branch19:
    sub    ecx,0x2
    xor    eax,eax
    mov    ax,WORD PTR [ecx]
    cmp    eax,ebp
    jb     Branch20
    sub    eax,ebp
    jmp    Branch21
  Branch20:
    xor    eax,eax
  Branch21:
    dec    esi
    mov    WORD PTR [ecx],ax
    jne    Branch19
    mov    eax,DWORD PTR [ebx+0x38]
    mov    esi,ebp
    lea    ecx,[eax+ebp*2]
  Branch22:
    sub    ecx,0x2
    xor    eax,eax
    mov    ax,WORD PTR [ecx]
    cmp    eax,ebp
    jb     Branch23
    sub    eax,ebp
    jmp    Branch24
  Branch23:
    xor    eax,eax
  Branch24:
    dec    esi
    mov    WORD PTR [ecx],ax
    jne    Branch22
    add    edx,ebp
  Branch25:
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [eax+0x4]
    test   ecx,ecx
    je     Branch27
    mov    ecx,DWORD PTR [ebx+0x6c]
    mov    edi,DWORD PTR [ebx+0x30]
    push   edx
    mov    edx,DWORD PTR [ebx+0x64]
    add    ecx,edx
    add    ecx,edi
    push   ecx
    push   eax
    call   R6GameServiceAddresses::ReadDeflateInput
    mov    ecx,DWORD PTR [ebx+0x6c]
    add    ecx,eax
    mov    esi,ecx
    mov    DWORD PTR [ebx+0x6c],ecx
    cmp    esi,0x3
    jb     Branch26
    mov    edx,DWORD PTR [ebx+0x64]
    mov    eax,DWORD PTR [ebx+0x30]
    mov    ecx,DWORD PTR [ebx+0x50]
    lea    edi,[edx+eax*1]
    xor    eax,eax
    mov    al,BYTE PTR [edi]
    mov    DWORD PTR [ebx+0x40],eax
    shl    eax,cl
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+0x1]
    xor    eax,ecx
    mov    ecx,DWORD PTR [ebx+0x4c]
    and    eax,ecx
    mov    DWORD PTR [ebx+0x40],eax
  Branch26:
    cmp    esi,0x106
    jae    Branch27
    mov    edx,DWORD PTR [ebx]
    mov    eax,DWORD PTR [edx+0x4]
    test   eax,eax
    jne    Branch16
  Branch27:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x4
  }
}

// Consume the input/capacity minimum, update optional checksum, copy forward and advance current input totals.
// R6GameService.dll @ 1001ec00 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ReadDeflateInput(void *stream,void *destination,uint capacity)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0xc]
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ebp+0x4]
    mov    ebx,eax
    cmp    ebx,ecx
    jbe    Branch28
    mov    ebx,ecx
  Branch28:
    test   ebx,ebx
    jne    Branch29
    pop    ebp
    xor    eax,eax
    pop    ebx
    ret    0xc
  Branch29:
    sub    eax,ebx
    mov    DWORD PTR [ebp+0x4],eax
    mov    eax,DWORD PTR [ebp+0x1c]
    mov    ecx,DWORD PTR [eax+0x18]
    test   ecx,ecx
    jne    Branch30
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    edx,DWORD PTR [ebp+0x30]
    push   ebx
    push   ecx
    push   edx
    call   R6GameServiceAddresses::Adler32Checksum
    mov    DWORD PTR [ebp+0x30],eax
  Branch30:
    mov    ecx,ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x0]
    mov    eax,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [ebp+0x8]
    add    ecx,ebx
    add    eax,ebx
    pop    edi
    mov    DWORD PTR [ebp+0x0],ecx
    mov    DWORD PTR [ebp+0x8],eax
    pop    esi
    mov    eax,ebx
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Insert rolling hashes, tally immediate matches/literals and flush pending blocks with native return statuses.
// R6GameService.dll @ 1001ec80 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CompressFastDeflate(void *state,int flush)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    push   edi
    xor    ebx,ebx
    xor    edi,edi
  Branch31:
    mov    eax,DWORD PTR [esi+0x6c]
    cmp    eax,0x106
    jae    Branch33
    push   esi
    call   R6GameServiceAddresses::FillDeflateWindow
    mov    eax,DWORD PTR [esi+0x6c]
    cmp    eax,0x106
    jae    Branch32
    cmp    DWORD PTR [esp+0x20],ebx
    je     Branch45
  Branch32:
    cmp    eax,ebx
    je     Branch46
  Branch33:
    cmp    eax,0x3
    jb     Branch34
    mov    eax,DWORD PTR [esi+0x40]
    mov    ecx,DWORD PTR [esi+0x50]
    mov    edx,DWORD PTR [esi+0x64]
    mov    edi,DWORD PTR [esi+0x4c]
    shl    eax,cl
    mov    ecx,DWORD PTR [esi+0x30]
    mov    DWORD PTR [esp+0x1c],ebx
    xor    ebx,ebx
    mov    bl,BYTE PTR [ecx+edx*1+0x2]
    mov    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esi+0x3c]
    and    eax,edi
    xor    edi,edi
    mov    DWORD PTR [esi+0x40],eax
    mov    di,WORD PTR [ecx+eax*2]
    mov    eax,DWORD PTR [esi+0x2c]
    mov    ecx,DWORD PTR [esi+0x38]
    and    eax,edx
    mov    WORD PTR [ecx+eax*2],di
    mov    edx,DWORD PTR [esi+0x40]
    mov    eax,DWORD PTR [esi+0x3c]
    mov    cx,WORD PTR [esi+0x64]
    mov    WORD PTR [eax+edx*2],cx
  Branch34:
    cmp    edi,ebx
    je     Branch35
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x24]
    sub    edx,edi
    sub    eax,0x106
    cmp    edx,eax
    ja     Branch35
    cmp    DWORD PTR [esi+0x80],0x2
    je     Branch35
    push   edi
    push   esi
    call   R6GameServiceAddresses::FindLongestDeflateMatch
    mov    DWORD PTR [esi+0x58],eax
  Branch35:
    mov    eax,DWORD PTR [esi+0x58]
    cmp    eax,0x3
    jb     Branch40
    mov    edx,DWORD PTR [esi+0x1698]
    mov    ebp,DWORD PTR [esi+0x169c]
    mov    cl,al
    mov    ax,WORD PTR [esi+0x64]
    sub    ax,WORD PTR [esi+0x68]
    sub    cl,0x3
    mov    BYTE PTR [esp+0x10],cl
    mov    WORD PTR [ebp+edx*2+0x0],ax
    mov    edx,DWORD PTR [esi+0x1690]
    mov    ebp,DWORD PTR [esi+0x1698]
    add    eax,0xffff
    mov    BYTE PTR [edx+ebp*1],cl
    mov    edx,DWORD PTR [esi+0x1698]
    mov    ecx,DWORD PTR [esp+0x10]
    inc    edx
    mov    DWORD PTR [esi+0x1698],edx
    and    ecx,0xff
    xor    edx,edx
    mov    dl,BYTE PTR [ecx+R6GameServiceAddresses::DeflateLengthCodes]
    inc    WORD PTR [esi+edx*4+0x490]
    cmp    ax,0x100
    lea    ecx,[esi+edx*4+0x490]
    jae    Branch36
    and    eax,0xffff
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::DeflateDistanceCodes]
    mov    eax,ecx
    jmp    Branch37
  Branch36:
    and    eax,0xffff
    shr    eax,0x7
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::DeflateDistanceCodes+0x100]
    mov    eax,edx
  Branch37:
    inc    WORD PTR [esi+eax*4+0x980]
    mov    eax,DWORD PTR [esi+0x1694]
    mov    edx,DWORD PTR [esi+0x1698]
    dec    eax
    xor    ecx,ecx
    cmp    edx,eax
    mov    eax,DWORD PTR [esi+0x58]
    mov    edx,DWORD PTR [esi+0x78]
    sete   cl
    mov    ebp,ecx
    mov    ecx,DWORD PTR [esi+0x6c]
    sub    ecx,eax
    cmp    eax,edx
    mov    DWORD PTR [esi+0x6c],ecx
    ja     Branch39
    cmp    ecx,0x3
    jb     Branch39
    dec    eax
    mov    DWORD PTR [esi+0x58],eax
  Branch38:
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x30]
    mov    edi,DWORD PTR [esi+0x40]
    inc    edx
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x64],edx
    mov    cl,BYTE PTR [edx+eax*1+0x2]
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x50]
    shl    edi,cl
    mov    ecx,DWORD PTR [esi+0x3c]
    xor    eax,edi
    mov    edi,DWORD PTR [esi+0x4c]
    and    eax,edi
    xor    edi,edi
    mov    DWORD PTR [esi+0x40],eax
    mov    di,WORD PTR [ecx+eax*2]
    mov    ecx,DWORD PTR [esi+0x2c]
    mov    eax,DWORD PTR [esi+0x38]
    and    edx,ecx
    mov    WORD PTR [eax+edx*2],di
    mov    ecx,DWORD PTR [esi+0x40]
    mov    edx,DWORD PTR [esi+0x3c]
    mov    ax,WORD PTR [esi+0x64]
    mov    WORD PTR [edx+ecx*2],ax
    mov    eax,DWORD PTR [esi+0x58]
    dec    eax
    mov    DWORD PTR [esi+0x58],eax
    jne    Branch38
    jmp    Branch41
  Branch39:
    mov    ecx,DWORD PTR [esi+0x64]
    mov    edx,DWORD PTR [esi+0x30]
    add    ecx,eax
    xor    eax,eax
    add    edx,ecx
    mov    DWORD PTR [esi+0x64],ecx
    mov    ecx,DWORD PTR [esi+0x50]
    mov    DWORD PTR [esi+0x58],ebx
    mov    al,BYTE PTR [edx]
    mov    DWORD PTR [esi+0x40],eax
    shl    eax,cl
    xor    ecx,ecx
    mov    cl,BYTE PTR [edx+0x1]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esi+0x4c]
    and    eax,ecx
    mov    DWORD PTR [esi+0x40],eax
    jmp    Branch42
  Branch40:
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x30]
    mov    ecx,DWORD PTR [esi+0x1698]
    mov    al,BYTE PTR [edx+eax*1]
    mov    edx,DWORD PTR [esi+0x169c]
    mov    BYTE PTR [esp+0x14],al
    mov    WORD PTR [edx+ecx*2],bx
    mov    ecx,DWORD PTR [esi+0x1690]
    mov    edx,DWORD PTR [esi+0x1698]
    mov    BYTE PTR [ecx+edx*1],al
    mov    eax,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [esi+0x1698]
    and    eax,0xff
    inc    ebp
    xor    edx,edx
    lea    eax,[esi+eax*4+0x8c]
    mov    DWORD PTR [esi+0x1698],ebp
    inc    WORD PTR [eax]
    mov    ecx,DWORD PTR [esi+0x1694]
    mov    ebp,DWORD PTR [esi+0x1698]
    dec    ecx
    cmp    ebp,ecx
    mov    ecx,DWORD PTR [esi+0x6c]
    sete   dl
    dec    ecx
    mov    ebp,edx
    mov    DWORD PTR [esi+0x6c],ecx
  Branch41:
    inc    DWORD PTR [esi+0x64]
  Branch42:
    cmp    ebp,ebx
    je     Branch31
    mov    ecx,DWORD PTR [esi+0x54]
    cmp    ecx,ebx
    jl     Branch43
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch44
  Branch43:
    xor    eax,eax
  Branch44:
    mov    edx,DWORD PTR [esi+0x64]
    push   ebx
    sub    edx,ecx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    edx,DWORD PTR [esi]
    cmp    DWORD PTR [edx+0x10],ebx
    jne    Branch31
  Branch45:
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch46:
    mov    ecx,DWORD PTR [esi+0x54]
    cmp    ecx,ebx
    jl     Branch47
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch48
  Branch47:
    xor    eax,eax
  Branch48:
    mov    edi,DWORD PTR [esp+0x20]
    xor    edx,edx
    cmp    edi,0x4
    sete   dl
    push   edx
    mov    edx,DWORD PTR [esi+0x64]
    sub    edx,ecx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    edx,DWORD PTR [esi]
    cmp    DWORD PTR [edx+0x10],ebx
    jne    Branch49
    mov    esi,edi
    xor    eax,eax
    cmp    esi,0x4
    pop    edi
    setne  al
    dec    eax
    pop    esi
    pop    ebp
    and    eax,0x2
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch49:
    mov    ecx,DWORD PTR [esp+0x20]
    xor    eax,eax
    cmp    ecx,0x4
    pop    edi
    sete   al
    pop    esi
    pop    ebp
    lea    eax,[eax+eax*1+0x1]
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Search bounded previous-position chains with suffix/byte filters, publish improving match position and cap length.
// R6GameService.dll @ 1001efb0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall FindLongestDeflateMatch(void *state,uint candidate)
{
  __asm {
    sub    esp,0x14
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x28]
    mov    esi,DWORD PTR [edi+0x24]
    mov    eax,DWORD PTR [edi+0x74]
    mov    edx,DWORD PTR [edi+0x64]
    mov    ecx,DWORD PTR [edi+0x30]
    mov    ebp,DWORD PTR [edi+0x70]
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [edi+0x88]
    lea    ebx,[esi-0x106]
    add    ecx,edx
    cmp    edx,ebx
    mov    DWORD PTR [esp+0x18],eax
    jbe    Branch50
    sub    edx,esi
    add    edx,0x106
    mov    DWORD PTR [esp+0x1c],edx
    jmp    Branch51
  Branch50:
    mov    DWORD PTR [esp+0x1c],0x0
  Branch51:
    mov    dl,BYTE PTR [ecx+ebp*1-0x1]
    lea    ebx,[ecx+0x102]
    mov    BYTE PTR [esp+0x28],dl
    mov    dl,BYTE PTR [ecx+ebp*1]
    mov    BYTE PTR [esp+0x13],dl
    mov    edx,DWORD PTR [edi+0x84]
    cmp    ebp,edx
    jb     Branch52
    shr    DWORD PTR [esp+0x14],0x2
  Branch52:
    mov    edx,DWORD PTR [edi+0x6c]
    cmp    eax,edx
    mov    DWORD PTR [esp+0x20],edx
    jbe    Branch53
    mov    DWORD PTR [esp+0x18],edx
  Branch53:
    mov    esi,DWORD PTR [esp+0x2c]
  Branch54:
    mov    edx,DWORD PTR [edi+0x30]
    mov    al,BYTE PTR [esp+0x13]
    add    edx,esi
    cmp    BYTE PTR [edx+ebp*1],al
    jne    Branch57
    mov    al,BYTE PTR [esp+0x28]
    cmp    BYTE PTR [edx+ebp*1-0x1],al
    jne    Branch57
    mov    al,BYTE PTR [edx]
    cmp    al,BYTE PTR [ecx]
    jne    Branch57
    mov    al,BYTE PTR [edx+0x1]
    inc    edx
    cmp    al,BYTE PTR [ecx+0x1]
    jne    Branch57
    add    ecx,0x2
    inc    edx
  Branch55:
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    mov    al,BYTE PTR [ecx+0x1]
    inc    ecx
    inc    edx
    cmp    al,BYTE PTR [edx]
    jne    Branch56
    cmp    ecx,ebx
    jb     Branch55
  Branch56:
    mov    edx,ecx
    lea    ecx,[ebx-0x102]
    sub    edx,ebx
    add    edx,0x102
    cmp    edx,ebp
    jle    Branch57
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [edi+0x68],esi
    cmp    edx,eax
    mov    ebp,edx
    jge    Branch58
    mov    al,BYTE PTR [edx+ecx*1-0x1]
    mov    dl,BYTE PTR [edx+ecx*1]
    mov    BYTE PTR [esp+0x28],al
    mov    BYTE PTR [esp+0x13],dl
  Branch57:
    mov    edx,DWORD PTR [edi+0x2c]
    mov    eax,DWORD PTR [edi+0x38]
    and    edx,esi
    xor    esi,esi
    mov    si,WORD PTR [eax+edx*2]
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    esi,eax
    jbe    Branch58
    mov    eax,DWORD PTR [esp+0x14]
    dec    eax
    mov    DWORD PTR [esp+0x14],eax
    jne    Branch54
  Branch58:
    mov    eax,DWORD PTR [esp+0x20]
    cmp    ebp,eax
    ja     Branch59
    mov    eax,ebp
  Branch59:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x14
    ret    0x8
  }
}

// Delay match choice by one position, tally previous matches/literals and preserve native flush/cursor order.
// R6GameService.dll @ 1001f130 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall CompressLazyDeflate(void *state,int flush)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    push   edi
    xor    edi,edi
    mov    ebp,0x2
  Branch60:
    mov    eax,DWORD PTR [esi+0x6c]
    cmp    eax,0x106
    jae    Branch62
    push   esi
    call   R6GameServiceAddresses::FillDeflateWindow
    mov    eax,DWORD PTR [esi+0x6c]
    mov    ebx,DWORD PTR [esp+0x20]
    cmp    eax,0x106
    jae    Branch61
    test   ebx,ebx
    je     Branch74
  Branch61:
    test   eax,eax
    je     Branch80
  Branch62:
    cmp    eax,0x3
    jb     Branch63
    mov    eax,DWORD PTR [esi+0x40]
    mov    ecx,DWORD PTR [esi+0x50]
    mov    edx,DWORD PTR [esi+0x64]
    mov    edi,DWORD PTR [esi+0x4c]
    shl    eax,cl
    mov    ecx,DWORD PTR [esi+0x30]
    xor    ebx,ebx
    mov    bl,BYTE PTR [ecx+edx*1+0x2]
    mov    ecx,DWORD PTR [esi+0x3c]
    xor    eax,ebx
    and    eax,edi
    xor    edi,edi
    mov    DWORD PTR [esi+0x40],eax
    mov    di,WORD PTR [ecx+eax*2]
    mov    eax,DWORD PTR [esi+0x2c]
    mov    ecx,DWORD PTR [esi+0x38]
    and    eax,edx
    mov    WORD PTR [ecx+eax*2],di
    mov    edx,DWORD PTR [esi+0x40]
    mov    eax,DWORD PTR [esi+0x3c]
    mov    cx,WORD PTR [esi+0x64]
    mov    WORD PTR [eax+edx*2],cx
  Branch63:
    mov    edx,DWORD PTR [esi+0x58]
    mov    eax,DWORD PTR [esi+0x68]
    test   edi,edi
    mov    DWORD PTR [esi+0x70],edx
    mov    DWORD PTR [esi+0x5c],eax
    mov    DWORD PTR [esi+0x58],ebp
    je     Branch66
    mov    eax,DWORD PTR [esi+0x78]
    mov    ecx,edx
    cmp    ecx,eax
    jae    Branch66
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x24]
    sub    edx,edi
    sub    eax,0x106
    cmp    edx,eax
    ja     Branch66
    cmp    DWORD PTR [esi+0x80],ebp
    je     Branch64
    push   edi
    push   esi
    call   R6GameServiceAddresses::FindLongestDeflateMatch
    mov    DWORD PTR [esi+0x58],eax
  Branch64:
    mov    eax,DWORD PTR [esi+0x58]
    cmp    eax,0x5
    ja     Branch66
    cmp    DWORD PTR [esi+0x80],0x1
    je     Branch65
    cmp    eax,0x3
    jne    Branch66
    mov    ecx,DWORD PTR [esi+0x64]
    mov    edx,DWORD PTR [esi+0x68]
    sub    ecx,edx
    cmp    ecx,0x1000
    jbe    Branch66
  Branch65:
    mov    DWORD PTR [esi+0x58],ebp
  Branch66:
    mov    eax,DWORD PTR [esi+0x70]
    cmp    eax,0x3
    jb     Branch75
    cmp    DWORD PTR [esi+0x58],eax
    ja     Branch75
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x6c]
    mov    cl,BYTE PTR [esi+0x70]
    mov    ebx,DWORD PTR [esi+0x169c]
    lea    ebp,[edx+eax*1-0x3]
    mov    ax,dx
    sub    ax,WORD PTR [esi+0x5c]
    mov    edx,DWORD PTR [esi+0x1698]
    sub    cl,0x3
    dec    eax
    mov    BYTE PTR [esp+0x1c],cl
    mov    WORD PTR [ebx+edx*2],ax
    mov    edx,DWORD PTR [esi+0x1690]
    mov    ebx,DWORD PTR [esi+0x1698]
    add    eax,0xffff
    mov    BYTE PTR [edx+ebx*1],cl
    mov    edx,DWORD PTR [esi+0x1698]
    mov    ecx,DWORD PTR [esp+0x1c]
    inc    edx
    mov    DWORD PTR [esi+0x1698],edx
    and    ecx,0xff
    xor    edx,edx
    mov    dl,BYTE PTR [ecx+R6GameServiceAddresses::DeflateLengthCodes]
    inc    WORD PTR [esi+edx*4+0x490]
    cmp    ax,0x100
    lea    ecx,[esi+edx*4+0x490]
    jae    Branch67
    and    eax,0xffff
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::DeflateDistanceCodes]
    mov    eax,ecx
    jmp    Branch68
  Branch67:
    and    eax,0xffff
    shr    eax,0x7
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::DeflateDistanceCodes+0x100]
    mov    eax,edx
  Branch68:
    inc    WORD PTR [esi+eax*4+0x980]
    mov    eax,DWORD PTR [esi+0x1694]
    mov    ecx,DWORD PTR [esi+0x1698]
    mov    edx,DWORD PTR [esi+0x6c]
    dec    eax
    xor    ebx,ebx
    cmp    ecx,eax
    mov    eax,DWORD PTR [esi+0x70]
    mov    ecx,0x1
    sete   bl
    sub    ecx,eax
    add    edx,ecx
    add    eax,0xfffffffe
    mov    DWORD PTR [esi+0x6c],edx
    mov    DWORD PTR [esi+0x70],eax
  Branch69:
    mov    ecx,DWORD PTR [esi+0x64]
    inc    ecx
    mov    edx,ecx
    mov    DWORD PTR [esi+0x64],ecx
    cmp    edx,ebp
    ja     Branch70
    mov    eax,DWORD PTR [esi+0x40]
    mov    ecx,DWORD PTR [esi+0x50]
    shl    eax,cl
    mov    ecx,DWORD PTR [esi+0x30]
    mov    edi,DWORD PTR [esi+0x4c]
    mov    DWORD PTR [esp+0x10],ebx
    xor    ebx,ebx
    mov    bl,BYTE PTR [ecx+edx*1+0x2]
    mov    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esi+0x3c]
    and    eax,edi
    xor    edi,edi
    mov    DWORD PTR [esi+0x40],eax
    mov    di,WORD PTR [ecx+eax*2]
    mov    eax,DWORD PTR [esi+0x2c]
    mov    ecx,DWORD PTR [esi+0x38]
    and    eax,edx
    mov    WORD PTR [ecx+eax*2],di
    mov    edx,DWORD PTR [esi+0x40]
    mov    eax,DWORD PTR [esi+0x3c]
    mov    cx,WORD PTR [esi+0x64]
    mov    WORD PTR [eax+edx*2],cx
  Branch70:
    mov    eax,DWORD PTR [esi+0x70]
    dec    eax
    mov    DWORD PTR [esi+0x70],eax
    jne    Branch69
    mov    ecx,DWORD PTR [esi+0x64]
    mov    ebp,0x2
    inc    ecx
    mov    DWORD PTR [esi+0x60],0x0
    test   ebx,ebx
    mov    DWORD PTR [esi+0x58],ebp
    mov    DWORD PTR [esi+0x64],ecx
    je     Branch60
    mov    edx,DWORD PTR [esi+0x54]
    test   edx,edx
    jl     Branch71
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,edx
    jmp    Branch72
  Branch71:
    xor    eax,eax
  Branch72:
    sub    ecx,edx
    push   0x0
    push   ecx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x64]
    push   eax
    mov    DWORD PTR [esi+0x54],edx
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [ecx+0x10]
  Branch73:
    test   eax,eax
    jne    Branch60
  Branch74:
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch75:
    mov    eax,DWORD PTR [esi+0x60]
    test   eax,eax
    je     Branch79
    mov    edx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x30]
    mov    ecx,DWORD PTR [esi+0x1698]
    mov    al,BYTE PTR [edx+eax*1-0x1]
    mov    edx,DWORD PTR [esi+0x169c]
    mov    BYTE PTR [esp+0x14],al
    mov    WORD PTR [edx+ecx*2],0x0
    mov    ecx,DWORD PTR [esi+0x1690]
    mov    edx,DWORD PTR [esi+0x1698]
    mov    BYTE PTR [ecx+edx*1],al
    mov    eax,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esi+0x1698]
    and    eax,0xff
    inc    edx
    lea    eax,[esi+eax*4+0x8c]
    mov    DWORD PTR [esi+0x1698],edx
    inc    WORD PTR [eax]
    mov    ecx,DWORD PTR [esi+0x1694]
    mov    eax,DWORD PTR [esi+0x1698]
    dec    ecx
    cmp    eax,ecx
    jne    Branch78
    mov    ecx,DWORD PTR [esi+0x54]
    test   ecx,ecx
    jl     Branch76
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch77
  Branch76:
    xor    eax,eax
  Branch77:
    mov    edx,DWORD PTR [esi+0x64]
    push   0x0
    sub    edx,ecx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
  Branch78:
    mov    edx,DWORD PTR [esi+0x64]
    mov    ecx,DWORD PTR [esi+0x6c]
    inc    edx
    dec    ecx
    mov    DWORD PTR [esi+0x64],edx
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [esi+0x6c],ecx
    mov    eax,DWORD PTR [edx+0x10]
    jmp    Branch73
  Branch79:
    mov    ecx,DWORD PTR [esi+0x64]
    mov    eax,DWORD PTR [esi+0x6c]
    inc    ecx
    dec    eax
    mov    DWORD PTR [esi+0x60],0x1
    mov    DWORD PTR [esi+0x64],ecx
    mov    DWORD PTR [esi+0x6c],eax
    jmp    Branch60
  Branch80:
    mov    eax,DWORD PTR [esi+0x60]
    test   eax,eax
    je     Branch81
    mov    eax,DWORD PTR [esi+0x64]
    mov    ecx,DWORD PTR [esi+0x30]
    mov    edx,DWORD PTR [esi+0x1698]
    mov    al,BYTE PTR [eax+ecx*1-0x1]
    mov    ecx,DWORD PTR [esi+0x169c]
    mov    BYTE PTR [esp+0x20],al
    mov    WORD PTR [ecx+edx*2],0x0
    mov    edx,DWORD PTR [esi+0x1690]
    mov    ecx,DWORD PTR [esi+0x1698]
    mov    BYTE PTR [edx+ecx*1],al
    mov    eax,DWORD PTR [esi+0x1698]
    mov    edx,DWORD PTR [esp+0x20]
    inc    eax
    and    edx,0xff
    mov    DWORD PTR [esi+0x1698],eax
    inc    WORD PTR [esi+edx*4+0x8c]
    mov    DWORD PTR [esi+0x60],0x0
    lea    eax,[esi+edx*4+0x8c]
  Branch81:
    mov    ecx,DWORD PTR [esi+0x54]
    test   ecx,ecx
    jl     Branch82
    mov    eax,DWORD PTR [esi+0x30]
    add    eax,ecx
    jmp    Branch83
  Branch82:
    xor    eax,eax
  Branch83:
    xor    edx,edx
    cmp    ebx,0x4
    sete   dl
    push   edx
    mov    edx,DWORD PTR [esi+0x64]
    sub    edx,ecx
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::EmitDeflateBlock
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x64]
    push   ecx
    mov    DWORD PTR [esi+0x54],eax
    call   R6GameServiceAddresses::DrainDeflatePending
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x10]
    test   eax,eax
    jne    Branch84
    xor    eax,eax
    cmp    ebx,0x4
    setne  al
    dec    eax
    pop    edi
    and    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch84:
    xor    eax,eax
    cmp    ebx,0x4
    sete   al
    pop    edi
    pop    esi
    pop    ebp
    lea    eax,[eax+eax*1+0x1]
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}
