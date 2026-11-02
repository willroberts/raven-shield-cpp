#include "native_addresses.h"
#include "native_records.h"

// Shared heap byte-string operations; descriptor class spelling and full declaration remain unrecovered.

// Captures a bounded source slice, clears/publishes a new owning descriptor and terminates the copied bytes.
// Invalid offset throws _STL::out_of_range before clearing result; size+1 wrap throws _STL::length_error afterward.
// Original argument-slot cleanup, unchecked allocation and exact six-state lifetime remain explicit.
// R6GameService.dll @ 10017040 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyByteStringRange(void *source,void *result,uint offset,uint count)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CopyByteStringRangeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x120
    push   ebx
    push   ebp
    xor    ebp,ebp
    push   esi
    mov    DWORD PTR [esp+0x10],ebp
    mov    eax,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,DWORD PTR [esp+0x140]
    sub    edx,eax
    push   edi
    cmp    ecx,edx
    jbe    Branch1
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x18]
    push   eax
    mov    DWORD PTR [esp+0x13c],ebp
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    edi,R6GameServiceAddresses::s_basic_string
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x138],0x1
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::s_basic_string
    push   ecx
    push   R6GameServiceAddresses::s_basic_string
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::InitializeByteStringFromRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x138],0x2
    push   ecx
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::ConstructException75c10
    lea    edx,[esp+0x24]
    push   0x1007eb9c
    push   edx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::out_of_range__STLVTable
    call   R6GameServiceAddresses::_CxxThrowException
  Branch1:
    mov    esi,DWORD PTR [esp+0x148]
    sub    edx,ecx
    mov    DWORD PTR [esp+0x14],edx
    cmp    edx,esi
    lea    edx,[esp+0x14]
    jb     Branch2
    lea    edx,[esp+0x148]
  Branch2:
    mov    edi,DWORD PTR [edx]
    mov    esi,DWORD PTR [esp+0x140]
    add    edi,eax
    lea    ebx,[eax+ecx*1]
    mov    DWORD PTR [esi],ebp
    mov    DWORD PTR [esi+0x4],ebp
    add    edi,ecx
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,edi
    mov    DWORD PTR [esp+0x138],0x3
    sub    eax,ebx
    lea    ebp,[eax+0x1]
    cmp    ebp,0xffffffff
    ja     Branch3
    test   ebp,ebp
    jbe    Branch3
    push   ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    push   eax
    lea    ecx,[eax+ebp*1]
    push   edi
    push   ebx
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    call   R6GameServiceAddresses::MoveByteRange
    mov    ecx,DWORD PTR [esp+0x130]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x12c
    ret    0xc
  Branch3:
    lea    edx,[esp+0x13]
    lea    ecx,[esp+0x18]
    push   edx
    push   R6GameServiceAddresses::s_basic_string
    mov    BYTE PTR [esp+0x140],0x4
    call   R6GameServiceAddresses::ConstructPooledByteString
    push   eax
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x13c],0x5
    call   R6GameServiceAddresses::ConstructException75c28
    lea    eax,[esp+0x24]
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Clears the destination BEFORE reading source bounds, then allocates/copies/terminates an owning byte string.
// Self-alias therefore constructs empty; allocation/error paths retain the native three-state guard and raw slots.
// R6GameService.dll @ 10017dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructHeapByteString(void *result,uint *source)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ConstructHeapByteStringSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x124
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x144]
    lea    eax,[esp+0x12]
    mov    esi,ecx
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],esi
    call   R6GameServiceAddresses::ForwardStackWord
    xor    ecx,ecx
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    eax,DWORD PTR [edi+0x4]
    mov    ebx,DWORD PTR [edi]
    mov    edi,eax
    mov    DWORD PTR [esp+0x13c],ecx
    sub    edi,ebx
    mov    DWORD PTR [esp+0x14],eax
    lea    ebp,[edi+0x1]
    cmp    ebp,0xffffffff
    ja     Branch5
    cmp    ebp,ecx
    jbe    Branch5
    push   ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+ebp*1]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x8],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    cmp    ecx,ebx
    mov    DWORD PTR [esi+0x4],eax
    je     Branch4
    push   edi
    push   ebx
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch4:
    mov    ecx,DWORD PTR [esp+0x134]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x130
    ret    0x4
  Branch5:
    lea    edx,[esp+0x13]
    lea    ecx,[esp+0x18]
    push   edx
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    edi,R6GameServiceAddresses::s_basic_string
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x13c],0x1
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::s_basic_string
    push   ecx
    push   R6GameServiceAddresses::s_basic_string
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::InitializeByteStringFromRange
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x28]
    push   eax
    mov    BYTE PTR [esp+0x140],0x2
    call   R6GameServiceAddresses::ConstructException75c28
    lea    ecx,[esp+0x28]
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Allocates range-length+1, publishes the descriptor, copies through memmove and returns its terminator address.
// End argument reload after allocation controls whether copying occurs; cached length still drives copy size.
// Wrap calls the nonreturning length throw helper; null storage and partial publication remain unchecked.
// R6GameService.dll @ 100180a0 : complete native control/access order and raw ABI retained.
__declspec(naked) char * __thiscall InitializeStringRange(void *result,void *first,int lastAddress)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    sub    edi,ebp
    mov    esi,ecx
    lea    ebx,[edi+0x1]
    cmp    ebx,0xffffffff
    ja     Branch6
    test   ebx,ebx
    jbe    Branch6
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch7
  Branch6:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
  Branch7:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi]
    cmp    ecx,ebp
    je     Branch8
    push   edi
    push   ebp
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch8:
    mov    DWORD PTR [esi+0x4],eax
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax],0x0
    pop    ebx
    ret    0x8
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x129]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648bb : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648c6 : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648d1 : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648d9 : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x129]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 100648e4 : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 10064a20 : complete native control/access order and raw ABI retained.
__declspec(naked) void ConstructHeapByteStringUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x11c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 10064a2b : complete native control/access order and raw ABI retained.
__declspec(naked) void ConstructHeapByteStringUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Uses the exact inherited-frame address/word to release descriptor storage or invoke genuine empty cleanup.
// R6GameService.dll @ 10064a36 : complete native control/access order and raw ABI retained.
__declspec(naked) void ConstructHeapByteStringUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects the exact byte-string lifetime metadata for the inherited frame.
// R6GameService.dll @ 100648ef : complete native control/access order and raw ABI retained.
__declspec(naked) void CopyByteStringRangeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CopyByteStringRangeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the exact byte-string lifetime metadata for the inherited frame.
// R6GameService.dll @ 10064a41 : complete native control/access order and raw ABI retained.
__declspec(naked) void ConstructHeapByteStringSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructHeapByteStringExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ebac : native heap byte-string lifetime record.
const R6GameServiceNative::UnwindEntry CopyByteStringRangeUnwindMap[6] = {
  {-1, R6GameServiceAddresses::CopyByteStringRangeUnwind1},
  {0x0, R6GameServiceAddresses::CopyByteStringRangeUnwind2},
  {0x0, R6GameServiceAddresses::CopyByteStringRangeUnwind3},
  {-1, R6GameServiceAddresses::CopyByteStringRangeUnwind4},
  {0x3, R6GameServiceAddresses::CopyByteStringRangeUnwind5},
  {0x4, R6GameServiceAddresses::CopyByteStringRangeUnwind6},
};

// R6GameService.dll data @ 1007ebdc : native heap byte-string lifetime record.
const R6GameServiceNative::FuncInfo CopyByteStringRangeExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::CopyByteStringRangeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007edec : native heap byte-string lifetime record.
const R6GameServiceNative::UnwindEntry ConstructHeapByteStringUnwindMap[3] = {
  {-1, R6GameServiceAddresses::ConstructHeapByteStringUnwind1},
  {0x0, R6GameServiceAddresses::ConstructHeapByteStringUnwind2},
  {0x0, R6GameServiceAddresses::ConstructHeapByteStringUnwind3},
};

// R6GameService.dll data @ 1007ee04 : native heap byte-string lifetime record.
const R6GameServiceNative::FuncInfo ConstructHeapByteStringExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ConstructHeapByteStringUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Allocate a nonzero count and publish begin/end/capacity without a character write; return wrapped capacity end.
// R6GameService.dll @ 100184a0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __thiscall InitializeHeapByteString(void *triplet,uint byteCount)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    edi,0xffffffff
    ja     Branch9
    test   edi,edi
    jbe    Branch9
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,edi
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    ret    0x4
  Branch9:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Free the current first-word buffer, then reload the low deleting flag and optionally free cached owner; return owner.
// R6GameService.dll @ 100283c0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) void * __thiscall ReleaseHeapByteStringAndMaybeOwner(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    test   BYTE PTR [esp+0x8],0x1
    je     Branch10
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch10:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}
