#include "native_addresses.h"

// Shared inflater state lifetimes; descriptive names/field roles are inferred, with native offsets retained.

// Reset stream counters/message, derive mode0/7 from cached state flag and reset the current nested decode state.
// R6GameService.dll @ 1001dc30 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetInflaterState(void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    xor    edx,edx
    cmp    eax,edx
    je     Branch1
    mov    ecx,DWORD PTR [eax+0x1c]
    cmp    ecx,edx
    je     Branch1
    push   esi
    mov    DWORD PTR [eax+0x14],edx
    mov    DWORD PTR [eax+0x8],edx
    mov    DWORD PTR [eax+0x18],edx
    mov    esi,DWORD PTR [ecx+0xc]
    push   edx
    neg    esi
    sbb    esi,esi
    push   eax
    and    esi,0x7
    mov    DWORD PTR [ecx],esi
    mov    eax,DWORD PTR [eax+0x1c]
    mov    ecx,DWORD PTR [eax+0x14]
    push   ecx
    call   R6GameServiceAddresses::ResetInflaterDecodeState
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch1:
    mov    eax,0xfffffffe
    ret    0x4
  }
}

// Release nested decode state, reload current state/context/free callback, then clear state only after final free.
// R6GameService.dll @ 1001dc80 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ReleaseInflaterState(void *stream)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    test   esi,esi
    je     Branch3
    mov    eax,DWORD PTR [esi+0x1c]
    test   eax,eax
    je     Branch3
    mov    ecx,DWORD PTR [esi+0x24]
    test   ecx,ecx
    je     Branch3
    mov    eax,DWORD PTR [eax+0x14]
    test   eax,eax
    je     Branch2
    push   esi
    push   eax
    call   R6GameServiceAddresses::DestroyInflaterDecodeState
  Branch2:
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [esi+0x28]
    push   eax
    push   ecx
    call   DWORD PTR [esi+0x24]
    mov    DWORD PTR [esi+0x1c],0x0
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch3:
    mov    eax,0xfffffffe
    pop    esi
    ret    0x4
  }
}

// Save optional checksum, perform current mode cleanup, reset window fields and invoke optional checksum callback.
// R6GameService.dll @ 1001f560 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall ResetInflaterDecodeState(void *state,void *stream,uint *previousChecksum)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [esi+0x3c]
    mov    DWORD PTR [eax],ecx
  Branch4:
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [esp+0x10]
    cmp    eax,0x4
    je     Branch5
    cmp    eax,0x5
    jne    Branch6
  Branch5:
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [edi+0x28]
    push   edx
    push   eax
    call   DWORD PTR [edi+0x24]
  Branch6:
    cmp    DWORD PTR [esi],0x6
    jne    Branch7
    mov    ecx,DWORD PTR [esi+0x4]
    push   edi
    push   ecx
    call   R6GameServiceAddresses::FreeInflaterAllocation
  Branch7:
    mov    eax,DWORD PTR [esi+0x28]
    mov    DWORD PTR [esi],0x0
    mov    DWORD PTR [esi+0x34],eax
    mov    DWORD PTR [esi+0x30],eax
    mov    eax,DWORD PTR [esi+0x38]
    mov    DWORD PTR [esi+0x1c],0x0
    test   eax,eax
    mov    DWORD PTR [esi+0x20],0x0
    je     Branch8
    push   0x0
    push   0x0
    push   0x0
    call   eax
    mov    DWORD PTR [esi+0x3c],eax
    mov    DWORD PTR [edi+0x30],eax
  Branch8:
    pop    edi
    pop    esi
    ret    0xc
  }
}

// Reset decode state, then free current window, tables and cached state with current callback/context each time.
// R6GameService.dll @ 100202b0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DestroyInflaterDecodeState(void *state,void *stream)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ResetInflaterDecodeState
    mov    eax,DWORD PTR [edi+0x28]
    mov    ecx,DWORD PTR [esi+0x28]
    push   eax
    push   ecx
    call   DWORD PTR [esi+0x24]
    mov    edx,DWORD PTR [edi+0x24]
    mov    eax,DWORD PTR [esi+0x28]
    push   edx
    push   eax
    call   DWORD PTR [esi+0x24]
    mov    ecx,DWORD PTR [esi+0x28]
    push   edi
    push   ecx
    call   DWORD PTR [esi+0x24]
    pop    edi
    xor    eax,eax
    pop    esi
    ret    0x8
  }
}

// Forward allocation and current opaque context to the current stream free callback, retaining raw EAX.
// R6GameService.dll @ 100225c0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall FreeInflaterAllocation(void *allocation,void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax+0x28]
    push   ecx
    call   DWORD PTR [eax+0x24]
    ret    0x8
  }
}

// Allocate state, 8-by-0x5a0 tables and window through current callbacks; clean NULL partial results, then reset.
// R6GameService.dll @ 1001f5e0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) void * __stdcall CreateInflaterDecodeState(
    void *stream,uint checksumFunction,uint windowSize)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    push   0x40
    push   0x1
    mov    eax,DWORD PTR [edi+0x28]
    push   eax
    call   DWORD PTR [edi+0x20]
    mov    esi,eax
    test   esi,esi
    jne    Branch9
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  Branch9:
    mov    ecx,DWORD PTR [edi+0x28]
    push   0x5a0
    push   0x8
    push   ecx
    call   DWORD PTR [edi+0x20]
    test   eax,eax
    mov    DWORD PTR [esi+0x24],eax
    jne    Branch10
    mov    edx,DWORD PTR [edi+0x28]
    push   esi
    push   edx
    call   DWORD PTR [edi+0x24]
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0xc
  Branch10:
    mov    ebx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [edi+0x28]
    push   ebx
    push   0x1
    push   eax
    call   DWORD PTR [edi+0x20]
    test   eax,eax
    mov    DWORD PTR [esi+0x28],eax
    jne    Branch11
    mov    ecx,DWORD PTR [esi+0x24]
    mov    edx,DWORD PTR [edi+0x28]
    push   ecx
    push   edx
    call   DWORD PTR [edi+0x24]
    mov    eax,DWORD PTR [edi+0x28]
    push   esi
    push   eax
    call   DWORD PTR [edi+0x24]
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0xc
  Branch11:
    mov    ecx,DWORD PTR [esp+0x14]
    push   0x0
    add    eax,ebx
    push   edi
    push   esi
    mov    DWORD PTR [esi+0x2c],eax
    mov    DWORD PTR [esi+0x38],ecx
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::ResetInflaterDecodeState
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Validate first version byte/size, install callbacks, allocate current stream/decode state and reset on success.
// R6GameService.dll @ 1001dcd0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall InflateInit2(void *stream,int windowBits,const char *version,uint streamSize)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    xor    edi,edi
    cmp    eax,edi
    je     Branch19
    mov    al,BYTE PTR [eax]
    mov    cl,BYTE PTR ds:R6GameServiceAddresses::Text114
    cmp    al,cl
    jne    Branch19
    cmp    DWORD PTR [esp+0x18],0x38
    jne    Branch19
    mov    esi,DWORD PTR [esp+0xc]
    cmp    esi,edi
    jne    Branch12
    pop    edi
    mov    eax,0xfffffffe
    pop    esi
    ret    0x10
  Branch12:
    mov    eax,DWORD PTR [esi+0x20]
    mov    DWORD PTR [esi+0x18],edi
    cmp    eax,edi
    jne    Branch13
    mov    DWORD PTR [esi+0x20],R6GameServiceAddresses::InflateAllocator
    mov    DWORD PTR [esi+0x28],edi
  Branch13:
    cmp    DWORD PTR [esi+0x24],edi
    jne    Branch14
    mov    DWORD PTR [esi+0x24],R6GameServiceAddresses::InflateFree
  Branch14:
    mov    ecx,DWORD PTR [esi+0x28]
    push   0x18
    push   0x1
    push   ecx
    call   DWORD PTR [esi+0x20]
    cmp    eax,edi
    mov    DWORD PTR [esi+0x1c],eax
    jne    Branch15
    pop    edi
    mov    eax,0xfffffffc
    pop    esi
    ret    0x10
  Branch15:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax+0x14],edi
    mov    edx,DWORD PTR [esi+0x1c]
    cmp    ecx,edi
    mov    DWORD PTR [edx+0xc],edi
    jge    Branch16
    mov    eax,DWORD PTR [esi+0x1c]
    neg    ecx
    mov    DWORD PTR [eax+0xc],0x1
  Branch16:
    cmp    ecx,0x8
    jl     Branch18
    cmp    ecx,0xf
    jg     Branch18
    mov    edx,DWORD PTR [esi+0x1c]
    mov    eax,0x1
    shl    eax,cl
    mov    DWORD PTR [edx+0x10],ecx
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    edx,DWORD PTR [ecx+0xc]
    neg    edx
    sbb    edx,edx
    push   eax
    not    edx
    and    edx,R6GameServiceAddresses::Adler32Checksum
    push   edx
    push   esi
    call   R6GameServiceAddresses::CreateInflaterDecodeState
    mov    ecx,DWORD PTR [esi+0x1c]
    push   esi
    mov    DWORD PTR [ecx+0x14],eax
    mov    edx,DWORD PTR [esi+0x1c]
    cmp    DWORD PTR [edx+0x14],edi
    jne    Branch17
    call   R6GameServiceAddresses::ReleaseInflaterState
    pop    edi
    mov    eax,0xfffffffc
    pop    esi
    ret    0x10
  Branch17:
    call   R6GameServiceAddresses::ResetInflaterState
    pop    edi
    xor    eax,eax
    pop    esi
    ret    0x10
  Branch18:
    push   esi
    call   R6GameServiceAddresses::ReleaseInflaterState
    pop    edi
    mov    eax,0xfffffffe
    pop    esi
    ret    0x10
  Branch19:
    pop    edi
    mov    eax,0xfffffffa
    pop    esi
    ret    0x10
  }
}

// Forward captured stream/version/size with window bits 15, preserving child status and separate RET 0xc.
// R6GameService.dll @ 1001dde0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall InflateInit(void *stream,const char *version,uint streamSize)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    push   ecx
    push   0xf
    push   edx
    call   R6GameServiceAddresses::InflateInit2
    ret    0xc
  }
}

// Allocate code state, capture late width/table arguments and publish only native mode/root/table fields.
// R6GameService.dll @ 10021ea0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) void * __stdcall AllocateHuffmanCodes(uint literalBits,uint distanceBits,
  const void *literalTable,const void *distanceTable,void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x14]
    push   0x1c
    push   0x1
    mov    ecx,DWORD PTR [eax+0x28]
    push   ecx
    call   DWORD PTR [eax+0x20]
    test   eax,eax
    je     Branch20
    mov    dl,BYTE PTR [esp+0x4]
    mov    cl,BYTE PTR [esp+0x8]
    mov    BYTE PTR [eax+0x10],dl
    mov    edx,DWORD PTR [esp+0xc]
    mov    BYTE PTR [eax+0x11],cl
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],0x0
    mov    DWORD PTR [eax+0x14],edx
    mov    DWORD PTR [eax+0x18],ecx
  Branch20:
    ret    0x14
  }
}
