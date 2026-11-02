#include "native_addresses.h"
#include "native_records.h"

// Public CD-key context callback registration adapters; class-owned callback slots live in CCDKeyProcess.cpp.
// uint results preserve raw EAX; guarded adapters define success only in AL.

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtC8(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtC8
  }
}

// For a nonnull context, stores callback at+c8 then changes only AL to1; null clears only AL without reading callback word.
// R6GameService.dll @ 100235e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetContextCallbackAtC8(void *context,uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch1
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::CCDKeyProcessSetCallback1
    mov    al,0x1
    ret    0x8
  Branch1:
    xor    al,al
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtCC(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtCC
  }
}

// For a nonnull context, stores callback at+cc then changes only AL to1; null clears only AL without reading callback word.
// R6GameService.dll @ 10023600 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetContextCallbackAtCC(void *context,uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch2
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::CCDKeyProcessSetCallback2
    mov    al,0x1
    ret    0x8
  Branch2:
    xor    al,al
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtD0(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtD0
  }
}

// For a nonnull context, stores callback at+d0 then changes only AL to1; null clears only AL without reading callback word.
// R6GameService.dll @ 10023620 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetContextCallbackAtD0(void *context,uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch3
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::CCDKeyProcessSetCallback3
    mov    al,0x1
    ret    0x8
  Branch3:
    xor    al,al
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtD4(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtD4
  }
}

// For a nonnull context, stores callback at+d4 then changes only AL to1; null clears only AL without reading callback word.
// R6GameService.dll @ 10023640 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetContextCallbackAtD4(void *context,uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch4
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::CCDKeyProcessSetCallback4
    mov    al,0x1
    ret    0x8
  Branch4:
    xor    al,al
    ret    0x8
  }
}

// Creates/tracks a context and returns it only when nested status AL is nonzero; failed validation adds no rollback.
// R6GameService.dll @ 10023210 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall CreateValidatedCDKeyContext(uint portWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   eax
    call   R6GameServiceAddresses::AllocateAndTrackContext
    mov    esi,eax
    test   esi,esi
    je     Branch5
    push   esi
    call   R6GameServiceAddresses::ReadCDKeyContextStatus
    test   al,al
    je     Branch5
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch5:
    xor    eax,eax
    pop    esi
    ret    0x4
  }
}

// Calls full registry deletion for NULL context, otherwise tail-forwards original word to registry removal.
// R6GameService.dll @ 10023240 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall RemoveCDKeyContextOrRegistry(uint contextWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    jne    Branch6
    call   R6GameServiceAddresses::DeleteCurrentCDKeyRegistry
    ret    0x4
  Branch6:
    mov    DWORD PTR [esp+0x4],eax
    jmp    R6GameServiceAddresses::ReleaseEmptyCDKeyRegistry
  }
}

// Constructs a context, lazily creates its pointer registry and inserts a missing unsigned pointer pair; preserves native allocation/unwind gaps.
// R6GameService.dll @ 10023300 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall AllocateAndTrackContext(uint portWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectContextFactoryLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   edi
    xor    edi,edi
    push   0xdc
    mov    DWORD PTR [esp+0x14],edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,edi
    mov    DWORD PTR [esp+0x28],edi
    je     Branch7
    mov    ecx,DWORD PTR [esp+0x30]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructCCDKeyProcess
    mov    ebp,eax
    jmp    Branch8
  Branch7:
    xor    ebp,ebp
  Branch8:
    or     ebx,0xffffffff
    cmp    ebp,edi
    mov    DWORD PTR [esp+0x28],ebx
    jne    Branch9
    pop    edi
    pop    ebp
    xor    eax,eax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x4
  Branch9:
    mov    eax,ds:0x10093bf8
    push   esi
    cmp    eax,edi
    jne    Branch12
    push   0x14
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x1c],esi
    cmp    esi,edi
    je     Branch10
    mov    DWORD PTR [esi+0x10],0x100769c0
    mov    DWORD PTR [esp+0x14],0x1
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [esp+0x20],ecx
    lea    edx,[esp+0x34]
    lea    eax,[esp+0x13]
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x34],0x4
    call   R6GameServiceAddresses::InitializeTreeSentinel
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerMap_PAXPAVCCDKeyProcessVTable
    jmp    Branch11
  Branch10:
    xor    esi,esi
  Branch11:
    mov    eax,esi
    mov    DWORD PTR [esp+0x2c],ebx
    mov    ds:0x10093bf8,eax
  Branch12:
    lea    ebx,[eax+0x4]
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x18],ebp
    mov    cl,0x1
    mov    edx,DWORD PTR [ebx]
    mov    edi,edx
    mov    esi,DWORD PTR [edx+0x4]
    test   esi,esi
    je     Branch16
  Branch13:
    mov    ecx,DWORD PTR [esi+0x10]
    mov    edi,esi
    cmp    ebp,ecx
    setb   cl
    test   cl,cl
    je     Branch14
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch15
  Branch14:
    mov    esi,DWORD PTR [esi+0xc]
  Branch15:
    test   esi,esi
    jne    Branch13
  Branch16:
    test   cl,cl
    mov    eax,edi
    je     Branch18
    cmp    edi,DWORD PTR [edx+0x8]
    jne    Branch17
    lea    ecx,[esp+0x14]
    push   0x0
    push   ecx
    push   edi
    lea    edx,[esp+0x2c]
    push   esi
    push   edx
    jmp    Branch19
  Branch17:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
  Branch18:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [eax+0x10]
    cmp    edx,ecx
    jae    Branch20
    lea    edx,[esp+0x14]
    push   0x0
    push   edx
    push   edi
    lea    eax,[esp+0x28]
    push   esi
    push   eax
  Branch19:
    mov    ecx,ebx
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
  Branch20:
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    mov    eax,ebp
    pop    edi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x4
  }
}

// Calls current registry slot8, reloads current registry/count and deletes/clears it only when that word is zero.
// R6GameService.dll @ 10023460 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ReleaseEmptyCDKeyRegistry(uint contextWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:0x10093bf8
    test   ecx,ecx
    je     Branch22
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR ds:0x10093bf8
    mov    eax,DWORD PTR [ecx+0x8]
    test   eax,eax
    jne    Branch22
    test   ecx,ecx
    je     Branch21
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch21:
    mov    DWORD PTR ds:0x10093bf8,0x0
  Branch22:
    ret    0x4
  }
}

// Calls nonnull current registry deleting slot with flag1, then clears global regardless of callback replacement.
// R6GameService.dll @ 100234a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl DeleteCurrentCDKeyRegistry(void)
{
  __asm {
    mov    ecx,DWORD PTR ds:0x10093bf8
    test   ecx,ecx
    je     Branch23
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR ds:0x10093bf8,0x0
  Branch23:
    ret
  }
}

// Reads nested byte+c through context+58, retaining pointer upper EAX; NULL context returns zero with no nested access.
// R6GameService.dll @ 100234c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ReadCDKeyContextStatus(void *context)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je     Branch24
    mov    eax,DWORD PTR [eax+0x58]
    mov    al,BYTE PTR [eax+0xc]
    ret    0x4
  Branch24:
    xor    al,al
    ret    0x4
  }
}

// Releases current pending context allocation from inherited EBP-1c through actual shared free tail.
// R6GameService.dll @ 10064ba0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases current pending registry allocation from inherited EBP-14 through actual shared free tail.
// R6GameService.dll @ 10064baa : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For inherited construction bit1, forwards pending registry+14 to genuine no-op; retains bitmap word.
// R6GameService.dll @ 10064bb4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    test   eax,eax
    je     Branch25
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch25:
    ret
  }
}

// Forwards address of original port argument to genuine no-op.
// R6GameService.dll @ 10064bce : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind5(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects five-state context/registry allocation map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064bd6 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectContextFactoryLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateAndTrackContextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ef08 : native context factory unwind record.
const R6GameServiceNative::UnwindEntry AllocateAndTrackContextUnwindMap[5] = {
  {-1, R6GameServiceAddresses::AllocateAndTrackContextUnwind1},
  {-1, R6GameServiceAddresses::AllocateAndTrackContextUnwind2},
  {0x1, R6GameServiceAddresses::AllocateAndTrackContextUnwind3},
  {0x2, 0x0},
  {0x3, R6GameServiceAddresses::AllocateAndTrackContextUnwind5},
};

// R6GameService.dll data @ 1007ef30 : native context factory unwind record.
// R6GameService.dll data @ 1007ef08 : native storage identity retained.
const R6GameServiceNative::FuncInfo AllocateAndTrackContextExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::AllocateAndTrackContextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023260 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation1(uint word0,uint word1)
{
  __asm {
    jmp    R6GameServiceAddresses::InvokeOptionalCDKeyContextAL
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 10023270 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation2(uint word0,uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x14],eax
    jmp    R6GameServiceAddresses::InvokeOptionalCDKeyContextWord
  }
}

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023280 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_ForwardValueDescriptorThroughContext(uint word0,uint word1,uint word2)
{
  __asm {
    jmp    R6GameServiceAddresses::ForwardValueDescriptorThroughContext
  }
}

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023290 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_ForwardCompoundDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    jmp    R6GameServiceAddresses::ForwardCompoundDescriptorThroughContext
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 100232a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation5(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::DispatchRangeDescriptorThroughContext
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 100232b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation6(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::DispatchRecordThroughContext
  }
}

// For a nonnull context, forwards the remaining words and raw EAX; null clears only AL.
// R6GameService.dll @ 100234e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall InvokeOptionalCDKeyContextAL(uint word0,uint word1)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch26
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::ProcessInputWithinTimeLimit
    ret    0x8
  Branch26:
    xor    al,al
    ret    0x8
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023500 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall InvokeOptionalCDKeyContextWord(uint word0,uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch27
    mov    eax,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    push   eax
    mov    eax,DWORD PTR [esp+0x10]
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   eax
    push   edx
    call   R6GameServiceAddresses::SendDescriptorWithText
    ret    0x14
  Branch27:
    xor    eax,eax
    ret    0x14
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023530 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardValueDescriptorThroughContext(uint word0,uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch28
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::SendDescriptorWithValue
    ret    0xc
  Branch28:
    xor    eax,eax
    ret    0xc
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023550 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardCompoundDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch29
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   eax
    call   R6GameServiceAddresses::SendCompoundDescriptor
    ret    0x10
  Branch29:
    xor    eax,eax
    ret    0x10
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023580 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall DispatchRangeDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch30
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   eax
    call   R6GameServiceAddresses::UppercaseAndDispatchRanges
    ret    0x10
  Branch30:
    xor    eax,eax
    ret    0x10
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 100235b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall DispatchRecordThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch31
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   eax
    call   R6GameServiceAddresses::CopyAndDispatchRecordFields
    ret    0x10
  Branch31:
    xor    eax,eax
    ret    0x10
  }
}
