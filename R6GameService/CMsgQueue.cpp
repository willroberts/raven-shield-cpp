#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10082b0c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CMsgQueueDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10082b50 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CMsgQueueRemoveExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10082b94 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CMsgQueuePeekExceptionHandlerFunctionInfo;

// Identified native class: CMsgQueue, primary table10077ea8/COL10079dd4/type10090094.
// Sentinel pointer is+8 and mutex handle+0x10.

// Initializes the list sentinel and unchecked mutex handle, returning the owner with ECX restored to zero.
// R6GameService.dll @ 1004bc40 : native ECX/stack boundary and raw register effects retained.
__declspec(naked) void * __thiscall ConstructCMsgQueue(void *owner,uint initializeVirtualBaseWord)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je Branch1
    mov    DWORD PTR [esi+0x4],0x10077eb4
  Branch1:
    push   0xc
    mov    DWORD PTR [esi+0xc],0x10077eac
    mov    DWORD PTR [esi+0x8],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    push   0x0
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    push   0x0
    mov    DWORD PTR [esi+0x8],eax
    push   0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::CMsgQueueVTable
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CreateMutexASlot
    mov    DWORD PTR [esi+0x10],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Destroys the queue, frees its storage for flags bit0, and returns the original owner.
// R6GameService.dll @ 1004bca0 : native ECX/stack boundary and raw register effects retained.
void *__thiscall DeleteCMsgQueue(void *owner,uint flags)
{
  void *savedOwner = owner;
  using DestroyABI = uint (__thiscall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyCMsgQueue)(savedOwner);
  if ((flags & 1) != 0) {
    using FreeABI = uint (__stdcall *)(void *);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(savedOwner);
  }
  return savedOwner;
}

namespace {
// Inferred saved receiver/state0 guard for releasing the queue's current node and sentinel storage.
struct CMsgQueueStorageCleanup {
  void *savedOwner;
  bool armed;
  // Release storage without retrying payload deletion or handle closure; keep the owner fields unchanged.
  ~CMsgQueueStorageCleanup() noexcept(false) {
    if (armed) {
      using ReleaseABI = uint (__thiscall *)(void *);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)((void *)((uint)savedOwner + 8));
    }
  }
};
}

// Closes the mutex, releases payloads before nodes, resets/frees the sentinel and retains raw allocator EAX.
// R6GameService.dll @ 1004bcc0 : saved receiver/state0 correspond to native S-10/S-4; cleanup stays armed through free.
uint __fastcall DestroyCMsgQueue(void *owner)
{
  CMsgQueueStorageCleanup cleanup{owner, false};
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::CMsgQueueVTable;
  void *handle = *(void **)(base + 0x10);
  cleanup.armed = true;
  using CloseABI = uint (__stdcall *)(void *);
  (*(CloseABI *)R6GameServiceAddresses::KERNEL32_CloseHandleSlot)(handle);
  uint head = *(uint *)(base + 8);
  uint node = *(uint *)head;
  using ChildABI = void (__thiscall *)(void *);
  using FreeABI = uint (__stdcall *)(void *);
  while (node != head) {
    void *payload = *(void **)(node + 8);
    if (payload != 0) {
      ((ChildABI)R6GameServiceAddresses::DeleteOwnedObjectAtOffset8)(payload);
      ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(payload);
    }
    node = *(uint *)node;
    head = *(uint *)(base + 8);
  }
  head = *(uint *)(base + 8);
  node = *(uint *)head;
  while (node != head) {
    uint released = node;
    node = *(uint *)node;
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)released);
    head = *(uint *)(base + 8);
  }
  head = *(uint *)(base + 8);
  *(uint *)head = head;
  head = *(uint *)(base + 8);
  *(uint *)(head + 4) = head;
  void *sentinel = *(void **)(base + 8);
  uint result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(sentinel);
  cleanup.armed = false;
  return result;
}

// Drains linked payloads only for wait result0, then always returns the raw mutex-release result.
// R6GameService.dll @ 1004bd60 : current links/handle reload after callbacks; no release-on-exception guard.
uint __fastcall DrainCMsgQueue(void *owner)
{
  uint base = (uint)owner;
  void *handle = *(void **)(base + 0x10);
  using WaitABI = uint (__stdcall *)(void *,uint);
  uint waitResult = (*(WaitABI *)R6GameServiceAddresses::KERNEL32_WaitForSingleObjectSlot)(handle,0xffffffff);
  if (waitResult == 0) {
    uint head = *(uint *)(base + 8);
    uint node = *(uint *)head;
    using ChildABI = void (__thiscall *)(void *);
    using FreeABI = uint (__stdcall *)(void *);
    while (node != head) {
      void *payload = *(void **)(node + 8);
      if (payload != 0) {
        ((ChildABI)R6GameServiceAddresses::DeleteOwnedObjectAtOffset8)(payload);
        ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(payload);
      }
      uint previous = *(uint *)(node + 4);
      uint next = *(uint *)node;
      *(uint *)previous = next;
      *(uint *)(next + 4) = previous;
      ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)node);
      head = *(uint *)(base + 8);
      node = next;
    }
  }
  handle = *(void **)(base + 0x10);
  using ReleaseABI = uint (__stdcall *)(void *);
  return (*(ReleaseABI *)R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot)(handle);
}

// Unlinks the first matching record and returns its payload, retaining selector-word scratch and exact cleanup phases.
// R6GameService.dll @ 1004bdc0 : native frame/access/order and raw register boundary retained.
__declspec(naked) uint __thiscall RemoveQueuedRecordBySelector(void *owner,uint selectorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CMsgQueueRemoveExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    push   edi
    push   0xffffffff
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x14],esi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_WaitForSingleObjectSlot
    test   eax,eax
    jne Branch19
    mov    eax,DWORD PTR [esi+0x8]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je Branch18
    // Cache the original low16 selector before its incoming word becomes byte-read scratch.
    mov    bx,WORD PTR [esp+0x44]
  Branch11:
    mov    esi,DWORD PTR [edi+0x8]
    mov    al,BYTE PTR [esi+0x4]
    cmp    al,0xd1
    je Branch12
    cmp    al,0xcc
    jne Branch14
  Branch12:
    lea    ecx,[esp+0xc]
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    ax,WORD PTR [esp+0xc]
    cmp    ax,bx
    je Branch20
    cmp    ax,0x26
    je Branch13
    cmp    ax,0x27
    jne Branch14
    // Clone the payload suffix at index1 into the local descriptor; read the nested selector there.
  Branch13:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,0x1
    or     ecx,eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x40],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push   0x1
    push   edx
    mov    DWORD PTR [esp+0x44],0x2
    call   R6GameServiceAddresses::CopyIndexedClDataList
    lea    eax,[esp+0xe]
    push   0x0
    push   eax
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0xe],bx
    je Branch21
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x3c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x3c],0xffffffff
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
  Branch14:
    mov    al,BYTE PTR [esi+0x4]
    xor    cx,cx
    mov    cl,al
    cmp    cx,bx
    je Branch22
    cmp    al,0x26
    je Branch15
    cmp    al,0x27
    jne Branch17
    // Exact-byte copy targets the original argument; fallback byte retrieval may leave its old low byte intact.
  Branch15:
    mov    ecx,DWORD PTR [esi+0x8]
    push   0x0
    lea    edx,[esp+0x48]
    push   0x1
    push   edx
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne Branch16
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x44]
    push   0x0
    push   eax
    call   R6GameServiceAddresses::ReadIndexedByte
  Branch16:
    movzx  cx,BYTE PTR [esp+0x44]
    cmp    cx,bx
    je Branch20
  Branch17:
    mov    edx,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [edi]
    cmp    edi,DWORD PTR [edx+0x8]
    jne Branch11
    mov    esi,edx
  Branch18:
    mov    edx,DWORD PTR [esi+0x10]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
  Branch19:
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
  Branch20:
    mov    ecx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [eax+0x4],ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [eax+0x10]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
    // Unlink and unlock before destroying the successful nested temporary.
  Branch21:
    mov    ecx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [eax+0x4],ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [edx+0x10]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x3c],0x3
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
  Branch22:
    mov    ecx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [eax+0x4],ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [ecx+0x10]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    mov    ecx,DWORD PTR [esp+0x34]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
  }
}

// Reads the head selector without unlinking, replacing only AX after the branch-specific final child call.
// R6GameService.dll @ 1004c040 : native frame/access/order and raw register boundary retained.
__declspec(naked) uint __fastcall ReadQueuedHeadValue(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CMsgQueuePeekExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    push   0xffffffff
    mov    DWORD PTR [esp+0x18],ebx
    mov    eax,DWORD PTR [edi+0x10]
    push   eax
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x1c],ebx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_WaitForSingleObjectSlot
    test   eax,eax
    jne Branch27
    mov    eax,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR [eax]
    cmp    ecx,eax
    je Branch26
    mov    esi,DWORD PTR [ecx+0x8]
    mov    al,BYTE PTR [esi+0x4]
    cmp    al,0xd1
    je Branch24
    cmp    al,0xcc
    je Branch24
    // Ordinary tags and byte payloads reload after mutex release; only AX is replaced.
    cmp    al,0x26
    je Branch23
    cmp    al,0x27
    je Branch23
    mov    ecx,DWORD PTR [edi+0x10]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    movzx  ax,BYTE PTR [esi+0x4]
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  Branch23:
    mov    ecx,DWORD PTR [esi+0x8]
    push   ebx
    lea    edx,[esp+0x13]
    push   0x1
    push   edx
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    mov    eax,DWORD PTR [edi+0x10]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    movzx  ax,BYTE PTR [esp+0xf]
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  Branch24:
    lea    ecx,[esp+0x10]
    push   ebx
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esp+0x10]
    cmp    ax,0x26
    je Branch25
    cmp    ax,0x27
    je Branch25
    mov    edx,DWORD PTR [edi+0x10]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    mov    ax,WORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
    // Nested word: build a local descriptor, copy index1 and retain the selected value across cleanup.
  Branch25:
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x24],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0xf]
    lea    ecx,[esp+0x2c]
    push   eax
    mov    DWORD PTR [esp+0x40],0x1
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    push   0x1
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x44],0x2
    call   R6GameServiceAddresses::CopyIndexedClDataList
    lea    edx,[esp+0x14]
    push   0x0
    push   edx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [edi+0x10]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    mov    esi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x3c],ebx
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x3c],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x3c],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    // Upper EAX comes from the structural-release child, not the mutex-release call.
    mov    ax,si
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  Branch26:
    mov    edx,DWORD PTR [edi+0x10]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    // Empty/nonzero-wait paths clear only AX, preserving the preceding child upper16 bits.
  Branch27:
    mov    ecx,DWORD PTR [esp+0x34]
    pop    edi
    pop    esi
    xor    ax,ax
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  }
}

// Appends a payload node before the saved sentinel only for wait result0, returning wait or release EAX.
// R6GameService.dll @ 1004c220 : native stack/register accesses and raw return effects retained.
__declspec(naked) uint __thiscall EnqueueCMsgQueuePayload(void *owner,uint payloadWord)
{
  __asm {
    push   ecx
    push   edi
    mov    edi,ecx
    push   0xffffffff
    mov    eax,DWORD PTR [edi+0x10]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_WaitForSingleObjectSlot
    test   eax,eax
    jne Branch28
    push   esi
    lea    ecx,[esp+0x8]
    lea    esi,[edi+0x8]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x10]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [edi+0x10]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_ReleaseMutexSlot
    pop    esi
  Branch28:
    pop    edi
    pop    ecx
    ret    0x4
  }
}

// Tail-forwards saved owner+8 to structural node/sentinel release during destructor unwind.
// R6GameService.dll @ 100680f0 : inherited EBP; native cleanup/selector boundary.
__declspec(naked) void __cdecl ReleaseCMsgQueueNodesOnUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Selects the queue destructor single-state structural-release unwind map.
// R6GameService.dll @ 100680fb : inherited EBP; native cleanup/selector boundary.
__declspec(naked) void __cdecl CMsgQueueDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CMsgQueueDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// For flag bit0, tail-forwards parent EBP-0x10 to the genuine empty allocation-base cleanup.
// R6GameService.dll @ 10068110 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl CleanupQueueRemovalTemporaryBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x2c]
    and    eax,0x1
    test   eax,eax
    je Branch29
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch29:
    ret
  }
}

// Resets the removal descriptor at parent EBP-0x28 during state1 unwind.
// R6GameService.dll @ 10068127 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ResetQueueRemovalTemporaryAtState1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the removal descriptor at parent EBP-0x28 during state2 unwind.
// R6GameService.dll @ 1006812f : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl DestroyQueueRemovalTemporaryAtState2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets the removal descriptor at parent EBP-0x28 during state4 unwind.
// R6GameService.dll @ 10068137 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ResetQueueRemovalTemporaryAtState4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the removal descriptor at parent EBP-0x28 during state3 unwind.
// R6GameService.dll @ 1006813f : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ResetQueueRemovalTemporaryAtState3(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selects the five-state queue-removal temporary unwind map.
// R6GameService.dll @ 10068147 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl CMsgQueueRemoveExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CMsgQueueRemoveExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Resets the head-read descriptor at parent EBP-0x24 during state0 unwind.
// R6GameService.dll @ 10068160 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ResetQueuePeekTemporaryAtState0(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards parent EBP-0x31 to the genuine empty tag cleanup.
// R6GameService.dll @ 10068168 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl CleanupQueuePeekConstructionTag(void)
{
  __asm {
    lea    ecx,[ebp-0x31]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the head-read descriptor at parent EBP-0x24 during state2 unwind.
// R6GameService.dll @ 10068170 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl DestroyQueuePeekTemporaryAtState2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets the head-read descriptor at parent EBP-0x24 during state3 unwind.
// R6GameService.dll @ 10068178 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ResetQueuePeekTemporaryAtState3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Stores saved subobject+4 or zero at parent EBP-0x60, then tail-forwards that context to node release.
// R6GameService.dll @ 10068180 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl ReleaseQueuePeekTemporaryNodesAtState4(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je Branch30
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp Branch31
  Branch30:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch31:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects the five-state head-read temporary unwind map.
// R6GameService.dll @ 100681a7 : native frame/access/order and raw register boundary retained.
__declspec(naked) void __cdecl CMsgQueuePeekExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CMsgQueuePeekExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: CMsgQueueVTable
// R6GameService.dll data @ 10077ea8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CMsgQueueVTableRecord {
  R6GameServiceNative::Address DeleteCMsgQueue; // +0x00
};
const CMsgQueueVTableRecord CMsgQueueVTable = {R6GameServiceAddresses::DeleteCMsgQueue};
