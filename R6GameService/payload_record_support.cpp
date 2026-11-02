#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10082bc0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PayloadRecordConstructExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10082bec : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PayloadRecordCopyExceptionHandlerFunctionInfo;

// Tagged queue-payload records: kind byte+4, owned payload+8, state words+0x0c/+0x10/+0x14 and context+0x18.
// Original record classes are unassigned; offset tables10077ebc/10076d64=[0,1c] do not prove a common class.
// Constructor frames save flags at EntryESP-0x14, owner at-0x10 and FS/handler/state at-c/-8/-4.
// The +8 deleting helper remains shared/unassigned; matching field offsets do not prove unique class ownership.

// Constructs a tagged record with a cloned payload, zero state words and a late-loaded context word.
// R6GameService.dll @ 1004c2a0 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void * __thiscall ConstructQueuedPayloadRecord(
    void *owner,uint kindWord,
    const void *payloadSource,uint contextWord,uint initializeVirtualBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::PayloadRecordConstructExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    cmp    eax,edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],edi
    je Branch1
    mov    DWORD PTR [esi],0x10077ebc
    mov    DWORD PTR [esp+0x8],0x1
  Branch1:
    mov    al,BYTE PTR [esp+0x20]
    push   0x18
    mov    BYTE PTR [esi+0x4],al
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Reuse the original full kind word as allocation scratch before entering state1.
    mov    DWORD PTR [esp+0x20],eax
    cmp    eax,edi
    mov    DWORD PTR [esp+0x18],0x1
    je Branch2
    mov    ecx,DWORD PTR [esp+0x24]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    jmp Branch3
  Branch2:
    xor    eax,eax
    // Load the supplied context word after cloning, then publish the child and zero the three state words.
  Branch3:
    mov    edx,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esi+0x10],edi
    mov    DWORD PTR [esi+0x14],edi
    mov    DWORD PTR [esi+0x18],edx
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x10
  }
}

// Clones the source payload and then copies trailing words in native read/write order, including overlap effects.
// R6GameService.dll @ 1004c340 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void * __thiscall CopyConstructQueuedPayloadRecord(
    void *owner,
    const void *source,uint initializeVirtualBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::PayloadRecordCopyExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    DWORD PTR [esp+0x0],0x0
    mov    eax,DWORD PTR [esp+0x1c]
    push   esi
    mov    esi,ecx
    test   eax,eax
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    je Branch4
    mov    DWORD PTR [esi],0x10077ebc
    mov    DWORD PTR [esp+0x8],0x1
  Branch4:
    mov    edi,DWORD PTR [esp+0x20]
    push   0x18
    mov    al,BYTE PTR [edi+0x4]
    mov    BYTE PTR [esi+0x4],al
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // The original flag word now holds the raw allocation; source EDI remains cached.
    mov    DWORD PTR [esp+0x24],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x18],0x1
    je Branch5
    mov    ecx,DWORD PTR [edi+0x8]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    jmp Branch6
  Branch5:
    xor    eax,eax
    // Publish the cloned child before reading and copying the four trailing source words.
  Branch6:
    mov    DWORD PTR [esi+0x8],eax
    mov    edx,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi+0xc],edx
    mov    eax,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],eax
    mov    ecx,DWORD PTR [edi+0x14]
    mov    DWORD PTR [esi+0x14],ecx
    mov    edx,DWORD PTR [edi+0x18]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x18],edx
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x8
  }
}

// Invokes the child deleting slot with flags1 when +8 is nonnull, retaining the pointer and raw child EAX.
// R6GameService.dll @ 1005c750 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) uint __thiscall DeleteOwnedObjectAtOffset8(void *owner)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x8]
    test   ecx,ecx
    je Branch7
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch7:
    ret
  }
}

// For saved flag bit0, tail-forwards owner+0x1c to the genuine empty allocation-base destructor.
// R6GameService.dll @ 100681c0 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl CleanupPayloadRecordVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je Branch8
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch8:
    ret
  }
}

// Frees the staged payload allocation stored in the original kind argument at parent EBP+4.
// R6GameService.dll @ 100681da : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl ReleasePayloadRecordConstructorAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the record constructor two-state staged-payload unwind map.
// R6GameService.dll @ 100681e4 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl PayloadRecordConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PayloadRecordConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// For saved flag bit0, tail-forwards owner+0x1c to the genuine empty allocation-base destructor.
// R6GameService.dll @ 100681f0 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl CleanupPayloadRecordCopyVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je Branch9
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch9:
    ret
  }
}

// Frees the staged payload allocation stored in the original flag argument at parent EBP+8.
// R6GameService.dll @ 1006820a : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl ReleasePayloadRecordCopyAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the record copy-constructor two-state staged-payload unwind map.
// R6GameService.dll @ 10068214 : native frame/word accesses, calling convention and raw registers retained.
__declspec(naked) void __cdecl PayloadRecordCopyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PayloadRecordCopyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Optional offset table76d64(0,1c), kind low BYTE4, then allocate18 and clone actual clDataList28ef0(source,1).
// Original kind word becomes allocation scratch; arm state1 after allocation, evenNULL, through later stores.
// Publish clone8, clearc/10/14, store late context18; RET16/owner EAX. Flags/state/owner use entry ESP frame.
// Failure frees only current staged raw block, then genuine empty base cleanup; no invented cloned-child dtor.
// R6GameService.dll @ 10031f90 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructClonedPayloadWrapper(
    void *owner,uint kindWord,const void *source,uint contextWord,uint initializeBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectWrappedPayloadEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    cmp    eax,edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],edi
    je     Branch10
    mov    DWORD PTR [esi],0x10076d64
    mov    DWORD PTR [esp+0x8],0x1
  Branch10:
    mov    al,BYTE PTR [esp+0x20]
    push   0x18
    mov    BYTE PTR [esi+0x4],al
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x20],eax
    cmp    eax,edi
    mov    DWORD PTR [esp+0x18],0x1
    je     Branch11
    mov    ecx,DWORD PTR [esp+0x24]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    jmp    Branch12
  Branch11:
    xor    eax,eax
  Branch12:
    mov    edx,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esi+0x10],edi
    mov    DWORD PTR [esi+0x14],edi
    mov    DWORD PTR [esi+0x18],edx
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x10
  }
}

// If current parent entryESP-14 flags bit0 is set, tail empty cleanup on saved owner(entryESP-10)+1c.
// R6GameService.dll @ 10066320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ConstructClonedPayloadWrapperUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch13
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch13:
    ret
  }
}

// Reload current allocation from parent entryESP+4 (original kind word) and release via14d00/current allocator.
// R6GameService.dll @ 1006633a : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ConstructClonedPayloadWrapperUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select the wrapper two-state staged-allocation/conditional-base map and tail-enter CRT dispatch.
// R6GameService.dll @ 10066344 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectWrappedPayloadEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructClonedPayloadWrapperExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native wrapper unwind words; state1->0 frees allocation, state0->-1 runs conditional empty base.
// R6GameService.dll data @ 10080688 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructClonedPayloadWrapperUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ConstructClonedPayloadWrapperUnwind1},
  {0x0, R6GameServiceAddresses::ConstructClonedPayloadWrapperUnwind2},
};

// Native wrapper info words; state1->0 frees allocation, state0->-1 runs conditional empty base.
// R6GameService.dll data @ 10080688 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructClonedPayloadWrapperExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ConstructClonedPayloadWrapperUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
