#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007f7c0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataPointerListExceptionHandlerFunctionInfo;

// Native clPointerList<clData *> frame and iterator argument copies from parent EBP-0x28 through EBP-4.
struct ClDataPointerListDestructionFrame {
  uint firstIterator;
  uint endIteratorOrCleanup;
  byte savedRegisterSlots[12];
  void *savedList;
  uint iterationResult;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs the clData-pointer list with an unchecked sentinel and optional +8 virtual-base table.
// R6GameService.dll @ 10027170 : native accesses, callback ordering and raw register results retained.
__declspec(naked) void * __thiscall ConstructClDataPointerList(void *list,uint initializeVirtualBaseWord)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0xc]
    xor    eax,eax
    cmp    ecx,eax
    // Return ECX is zero; do not install the primary vtable before allocation succeeds.
    mov    DWORD PTR [esp+0x4],eax
    je Branch1
    mov    DWORD PTR [esi+0x8],0x10076aa8
  Branch1:
    push   0xc
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Runs the list's range callback, frees remaining nodes and the sentinel, and returns final allocator EAX.
// R6GameService.dll @ 10026ec0 : ECX list, no stack arguments; native one-state FuncInfo retained.
uint __fastcall DestroyClDataPointerList(void *list)
{
  ClDataPointerListDestructionFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)ClDataPointerListExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedList = list;
  uint *words = (uint *)list;
  words[0] = (uint)&clDataListPTR_FUN2;
  frame.endIteratorOrCleanup = words[1];
  uint *vtable = (uint *)words[0];
  frame.state = 0;
  ReadListFirstNodeFromHeadSlot(words + 1,&frame.firstIterator);
  typedef uint (__thiscall *ReleaseRange)(void *,uint *,uint,uint);
  ReleaseRange releaseRange = (ReleaseRange)vtable[4];
  releaseRange(list,&frame.iterationResult,frame.firstIterator,frame.endIteratorOrCleanup);
  uint *node = *(uint **)words[1];
  while (node != (uint *)words[1]) {
    uint *next = (uint *)node[0];
    TailFreeThroughGlobalAllocator(node);
    node = next;
  }
  uint *sentinel = (uint *)words[1];
  sentinel[0] = (uint)sentinel;
  sentinel = (uint *)words[1];
  sentinel[1] = (uint)sentinel;
  uint result = TailFreeThroughGlobalAllocator((void *)words[1]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Releases the saved list's node/sentinel storage through its +4 head slot while destruction unwinds.
// R6GameService.dll @ 10065620 : inherited EBP-0x14 receiver; EBP-0x24 scratch, including native null forwarding.
__declspec(naked) void __cdecl ReleaseClDataPointerListOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_list
    mov    eax,dword ptr [ebp-0x14]
    add    eax,4
    mov    dword ptr [ebp-0x24],eax
    jmp    forward_cleanup
  null_list:
    mov    dword ptr [ebp-0x24],0
  forward_cleanup:
    mov    ecx,dword ptr [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects the clData-pointer list destructor's one-state FuncInfo for the shared exception handler.
// R6GameService.dll @ 10065647 : EAX=1007f7c0; inherited-frame exception ABI.
__declspec(naked) void __cdecl ClDataPointerListExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataPointerListExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the clData-pointer list, reloads delete bit zero, optionally frees storage, and returns the list.
// R6GameService.dll @ 100271c0 : native accesses, callback ordering and raw register results retained.
__declspec(naked) void * __thiscall DeleteClDataPointerList(void *list,uint deleteFlagWord)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyClDataPointerList
    test   BYTE PTR [esp+0x8],0x1
    je Branch2
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Reinstalls clPointerList<clMemoryElement*> table, erases payload range virtually, then drains nodes/sentinel.
// Current head reloads and one-state exceptional sentinel cleanup retain native retry/leak behavior.
// R6GameService.dll @ 1002ee90 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyCircularList(void *list)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyCircularListSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclMemoryElementVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je     Branch4
  Branch3:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch3
  Branch4:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Runs the shared typed-list destructor, reloads low deletion flag and optionally frees cached list receiver.
// R6GameService.dll @ 1002ef20 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteCircularList(void *list,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyCircularList
    test   BYTE PTR [esp+0x8],0x1
    je     Branch5
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch5:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Shared clMemoryElement*/clParentGroup* body releases payloads, unlinks nodes and publishes cached end.
// Payload traversal reloads next after free; node phase starts from late first and reuses last argument as scratch.
// R6GameService.dll @ 10031f00 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall EraseOwningPointerListRange(
    void *list,uint *out,uint first,uint last)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ebx,ecx
    cmp    esi,edi
    je     Branch8
  Branch6:
    cmp    esi,DWORD PTR [ebx+0x4]
    je     Branch8
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    je     Branch7
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch7:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch6
  Branch8:
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x18]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x18]
    cmp    eax,edi
    je     Branch10
  Branch9:
    mov    ecx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esp+0x1c],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x18]
    cmp    eax,edi
    jne    Branch9
  Branch10:
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Captures sentinel/end and table, reads first link and invokes virtual range erase with native stacked iterators.
// R6GameService.dll @ 10062920 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall InvokePointerListClearRange(void *list)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    push   edi
    push   ecx
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],edx
    mov    edi,DWORD PTR [esi]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push   eax
    call   DWORD PTR [edi+0x10]
    pop    edi
    pop    esi
    pop    ecx
    ret
  }
}

// Forwards current saved owner+4 or NULL to node/sentinel release during typed-list unwind.
// NULL adjustment is retained even though the release target dereferences a NULL context unchecked.
// R6GameService.dll @ 10065ea0 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyCircularListUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je     Branch11
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch12
  Branch11:
    mov    DWORD PTR [ebp-0x24],0x0
  Branch12:
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects the typed-list destructor one-state node/sentinel lifetime map.
// R6GameService.dll @ 10065ec7 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyCircularListSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyCircularListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10080284 : clMemoryElement-pointer list destruction.
const R6GameServiceNative::UnwindEntry DestroyCircularListUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyCircularListUnwind1},
};

// R6GameService.dll data @ 1008028c : clMemoryElement-pointer list destruction.
// R6GameService.dll data @ 10080284 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyCircularListExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyCircularListUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Frees the first payload, then reloads the current head/first node before unlinking and freeing that node.
// Shared owning-pointer-list slot8 leaves the fifo count unchanged and returns raw head/free EAX.
// R6GameService.dll @ 1002f1b0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RemoveFirstBlockFromQueue(void *list)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch14
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [ecx+0x8]
    test   eax,eax
    je     Branch13
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch13:
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [edx]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch14:
    pop    esi
    ret
  }
}

// Frees the last payload, then reloads the current head/predecessor before unlinking and freeing that node.
// Shared slot+c leaves the fifo count unchanged; final ECX is the selected node on the nonempty path.
// R6GameService.dll @ 1002f1e0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RemoveLastBlockFromQueue(void *list)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch16
    mov    eax,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax+0x8]
    test   eax,eax
    je     Branch15
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch15:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    lea    ecx,[esp+0x4]
    call   R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch16:
    pop    esi
    pop    ecx
    ret
  }
}

// Frees a nonsentinel payload, unlinks/frees the cached node and writes its cached successor through late out.
// Shared slot14 skips only sentinel payload release: a sentinel argument itself is still unlinked and freed.
// R6GameService.dll @ 10031ec0 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall EraseOwningPointerListNode(void *list,uint *out,uint node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je     Branch17
    mov    eax,DWORD PTR [edi+0x8]
    test   eax,eax
    je     Branch17
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch17:
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    mov    DWORD PTR [eax],esi
    pop    esi
    ret    0x8
  }
}

// Installs destruction table, virtually clears owning payloads/nodes, then drains residual nodes and frees current sentinel.
// Current head reloads, cached next, dangling head and armed EH through final free remain native.
// R6GameService.dll @ 10031d90 : native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyParsedServiceRecordList(void *list)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectParsedListDestructionLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclParentGroupVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je     Branch19
  Branch18:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch18
  Branch19:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Runs list destruction, tests late low deletion bit, optionally frees owner and returns saved list.
// R6GameService.dll @ 10031e20 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyParsedServiceRecordListObject(void *list,uint deleteFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyParsedServiceRecordList
    test   BYTE PTR [esp+0x8],0x1
    je     Branch20
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch20:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Publishes saved list+4 or NULL in inherited scratch then tail-releases nodes/sentinel without payload retries.
// R6GameService.dll @ 100662e0 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindParsedListStorage(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je     Branch21
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch22
  Branch21:
    mov    DWORD PTR [ebp-0x24],0x0
  Branch22:
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects parsed-list one-state destruction map and tail-transfers to external frame dispatch.
// R6GameService.dll @ 10066307 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectParsedListDestructionLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyParsedServiceRecordListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10080640 : exact lifetime map/info words for the associated native registration/list body.
const R6GameServiceNative::UnwindEntry DestroyParsedServiceRecordListUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindParsedListStorage},
};

// R6GameService.dll data @ 10080648 : exact lifetime map/info words for the associated native registration/list body.
// R6GameService.dll data @ 10080640 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyParsedServiceRecordListExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyParsedServiceRecordListUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll @ 100573c0 : thunk_DestroyEmbeddedListOwnerAndSentinel
// Tail-forwards to DestroyEmbeddedListOwnerAndSentinel.
void __fastcall thunk_DestroyEmbeddedListOwnerAndSentinel(int *receiver)
{
  DestroyEmbeddedListOwnerAndSentinel(receiver);
}

// R6GameService.dll @ 100573d0 : ForwardCompactPointerListDestroy
// Forwards to the shared list cleanup body at 0x10059040; native code uses a tail jump.
void __fastcall ForwardCompactPointerListDestroy(int *receiver)
{
  DestroyCompactPointerList(receiver);
}

// R6GameService.dll @ 100573e0 : thunk_DestroyEmbeddedListAndSentinel
// Forwards to the shared cleanup body at 0x10057410; native code uses a tail jump.
void __fastcall thunk_DestroyEmbeddedListAndSentinel(int *receiver)
{
  DestroyEmbeddedListAndSentinel(receiver);
}

// Destroy game-list container, test CURRENT flagBYTEbit0 afterward, optionally free captured owner and return it.
// R6GameService.dll @ 100573f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyObjectAndMaybeFree(void *owner,byte deleteFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyEmbeddedListOwnerAndSentinel
    test   BYTE PTR [esp+0x8],0x1
    je    Branch23
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch23:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Install typed list vtable, invoke captured +10 callback with stack iterator, then free nodes/current head.
// Keep owner slot and state0 live across frees; EH reclaims CURRENT saved owner+4, without progress rollback.
// R6GameService.dll @ 10057410 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyEmbeddedListAndSentinel(int *receiver)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTypedListDestructorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclRcvElementVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch25
  Branch24:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch24
  Branch25:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// If the list at owner+4 is nonempty, releases its first node's buffer, unlinks the node, and frees it.
// If nonempty, release captured first payload/buffer, then unlink/free CURRENT first node; retain raw EAX.
// R6GameService.dll @ 10058ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyFirstListEntryAndBuffer(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je    Branch27
    mov    ecx,DWORD PTR [eax]
    push   edi
    mov    edi,DWORD PTR [ecx+0x8]
    test   edi,edi
    je    Branch26
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseCompactRecordBuffer
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch26:
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [edx]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch27:
    pop    esi
    ret
  }
}

// Installs the cleanup vtable, invokes its +0x10 callback, frees list nodes and sentinel, then restores the SEH link.
// Install typed list vtable, invoke captured +10 callback with stack iterator, then free nodes/current head.
// Keep owner slot and state0 live across frees; EH reclaims CURRENT saved owner+4, without progress rollback.
// R6GameService.dll @ 10058ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyEmbeddedListOwnerAndSentinel(int *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTypedListDestructorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclGameMessageVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch29
  Branch28:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch28
  Branch29:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// R6GameService.dll @ 10059020 : destroy the list container and optionally free its allocation
void * __thiscall DeleteCompactPointerList(void *this,byte param_1)
{
  DestroyCompactPointerList(this);
  if ((param_1 & 1) != 0) {
    TailFreeThroughGlobalAllocator(this);
  }
  return this;
}

// Install typed list vtable, invoke captured +10 callback with stack iterator, then free nodes/current head.
// Keep owner slot and state0 live across frees; EH reclaims CURRENT saved owner+4, without progress rollback.
// R6GameService.dll @ 10059040 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyCompactPointerList(int *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTypedListDestructorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclSendElementVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch31
  Branch30:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch30
  Branch31:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// R6GameService.dll @ 100590d0 : run the base destructor and optionally free the allocation
void * __thiscall DeleteEmbeddedPointerList(void *this,byte param_1)
{
  DestroyEmbeddedListAndSentinel(this);
  if ((param_1 & 1) != 0) {
    TailFreeThroughGlobalAllocator(this);
  }
  return this;
}

// Tail-forward the original receiver/registers to the proxy-message list destructor; no separate ownership.
// R6GameService.dll @ 10062530 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyCallbackListContainer(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyCallbackListContainer
  }
}

// Destroy first, then test CURRENT deleteWord lowBYTE bit0 before freeing the original receiver. RET4.
// R6GameService.dll @ 10062540 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteCallbackListContainer(void *owner,uint deleteWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyCallbackListContainer
    test    BYTE PTR [esp+0x8],0x1
    je    Branch32
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch32:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore proxy-message-list table, invoke captured typed range erase, drain CURRENT links and free CURRENT head.
// State0 remains armed through normal head free; unwind head cleanup reloads saved owner. Raw allocator EAX.
// R6GameService.dll @ 10062890 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyCallbackListContainer(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProxyMessageListEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclProxyMessageVTable
    push    ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push    edx
    call    DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch34
  Branch33:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch33
  Branch34:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Destroy/free captured first payload, then reload CURRENT head/first, unlink and free that node. Raw head/free EAX.
// R6GameService.dll @ 10062950 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyFirstPayloadListNode(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je    Branch36
    mov    ecx,DWORD PTR [eax]
    push    edi
    mov    edi,DWORD PTR [ecx+0x8]
    test    edi,edi
    je    Branch35
    mov    ecx,edi
    call    R6GameServiceAddresses::DestroyPerNodeLinkedListContainer
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch35:
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [edx]
    push    eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch36:
    pop    esi
    ret
  }
}

// Payload pass stops at CURRENT sentinel; node pass stops only at cached last and may free a sentinel.
// Reload caller first before node pass, reuse caller last as cursor, and reload final output pointer. RETc/no own guard.
// R6GameService.dll @ 10062a20 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ErasePayloadListRange(void *owner,void *outputIterator,void *first,void *last)
{
  __asm {
    push    ebx
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x14]
    push    edi
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    esi,edi
    mov    ebp,ecx
    je    Branch39
  Branch37:
    cmp    esi,DWORD PTR [ebp+0x4]
    je    Branch39
    mov    ebx,DWORD PTR [esi+0x8]
    test    ebx,ebx
    je    Branch38
    mov    ecx,ebx
    call    R6GameServiceAddresses::DestroyPerNodeLinkedListContainer
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch38:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch37
  Branch39:
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x1c]
    push    eax
    call    R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    je    Branch41
  Branch40:
    mov    ecx,DWORD PTR [eax]
    push    eax
    mov    DWORD PTR [esp+0x20],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    jne    Branch40
  Branch41:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Read CURRENT saved owner twice at inherited EBP-14; preserve null or add4 into EBP-24, then release list/head.
// R6GameService.dll @ 10069780 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clPointerListSharedLifetimeUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch42
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch43
  Branch42:
    mov    DWORD PTR [ebp-0x24],0x0
  Branch43:
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select shared one-state typed list destructor FuncInfo; three distinct parent bodies use this same record.
// R6GameService.dll @ 100697a7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTypedListDestructorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clPointerListSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Release nodes/head through CURRENT saved list owner; preserve NULL and exact inherited scratch stores.
// R6GameService.dll @ 1006a010 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindCallbackListStorage(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch44
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch45
  Branch44:
    mov    DWORD PTR [ebp-0x24],0x0
  Branch45:
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Destroy/free captured last payload, then decrement a CURRENT head iterator and unlink/free that node.
// Scratch reuses saved ECX, so nonempty POP ECX returns the freed selected node rather than the entry receiver.
// R6GameService.dll @ 10062990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyLastPayloadListNode(void *owner)
{
  __asm {
    push    ecx
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je    Branch47
    mov    eax,DWORD PTR [eax+0x4]
    push    edi
    mov    edi,DWORD PTR [eax+0x8]
    test    edi,edi
    je    Branch46
    mov    ecx,edi
    call    R6GameServiceAddresses::DestroyPerNodeLinkedListContainer
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch46:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x8]
    call    R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push    eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch47:
    pop    esi
    pop    ecx
    ret
  }
}

// Destroy/free captured payload unless node is entry head; always unlink/free the node, including a sentinel.
// Reload output argument AFTER node free, store saved successor and return that output pointer. RET8/no own guard.
// R6GameService.dll @ 100629e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ErasePayloadListNode(void *owner,void *outputIterator,void *node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je    Branch48
    mov    esi,DWORD PTR [edi+0x8]
    test    esi,esi
    je    Branch48
    mov    ecx,esi
    call    R6GameServiceAddresses::DestroyPerNodeLinkedListContainer
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch48:
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [edi]
    push    edi
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [esi+0x4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    mov    DWORD PTR [eax],esi
    pop    esi
    ret    0x8
  }
}

// Select the exact single-state proxy-message list destructor map and tail CRT dispatch.
// R6GameService.dll @ 1006a037 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxyMessageListEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyCallbackListContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native proxy-message list/payload cleanup records.
// R6GameService.dll data @ 10084b5c : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyCallbackListContainerUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindCallbackListStorage},
};
// R6GameService.dll data @ 10084b64 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyCallbackListContainerExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyCallbackListContainerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal shared typed list destructor one-state cleanup map.
// R6GameService.dll data @ 10084260 : native storage identity retained.
const R6GameServiceNative::UnwindEntry clPointerListSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::clPointerListSharedLifetimeUnwind1},
};

// Literal shared typed list destructor FuncInfo.
// R6GameService.dll data @ 10084260 : native storage identity retained.
const R6GameServiceNative::FuncInfo clPointerListSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::clPointerListSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clPointerList_PAVclMemoryElementVTable
// R6GameService.dll data @ 10076c58 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclMemoryElementVTableRecord {
  R6GameServiceNative::Address DeleteCircularList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address RemoveFirstBlockFromQueue; // +0x08
  R6GameServiceNative::Address RemoveLastBlockFromQueue; // +0x0c
  R6GameServiceNative::Address EraseOwningPointerListRange; // +0x10
  R6GameServiceNative::Address EraseOwningPointerListNode; // +0x14
};
const clPointerList_PAVclMemoryElementVTableRecord clPointerList_PAVclMemoryElementVTable = {
  R6GameServiceAddresses::DeleteCircularList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::RemoveFirstBlockFromQueue,
  R6GameServiceAddresses::RemoveLastBlockFromQueue,
  R6GameServiceAddresses::EraseOwningPointerListRange,
  R6GameServiceAddresses::EraseOwningPointerListNode,
};

// Native virtual-table prefix: clPointerList_PAVclParentGroupVTable
// R6GameService.dll data @ 10076d4c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclParentGroupVTableRecord {
  R6GameServiceNative::Address DestroyParsedServiceRecordListObject; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address RemoveFirstBlockFromQueue; // +0x08
  R6GameServiceNative::Address RemoveLastBlockFromQueue; // +0x0c
  R6GameServiceNative::Address EraseOwningPointerListRange; // +0x10
  R6GameServiceNative::Address EraseOwningPointerListNode; // +0x14
};
const clPointerList_PAVclParentGroupVTableRecord clPointerList_PAVclParentGroupVTable = {
  R6GameServiceAddresses::DestroyParsedServiceRecordListObject,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::RemoveFirstBlockFromQueue,
  R6GameServiceAddresses::RemoveLastBlockFromQueue,
  R6GameServiceAddresses::EraseOwningPointerListRange,
  R6GameServiceAddresses::EraseOwningPointerListNode,
};

// Native virtual-table prefix: clPointerList_PAVclGameMessageVTable
// R6GameService.dll data @ 100780dc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclGameMessageVTableRecord {
  R6GameServiceNative::Address DestroyObjectAndMaybeFree; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstListNode; // +0x08
  R6GameServiceNative::Address PopLastVirtualPayload; // +0x0c
  R6GameServiceNative::Address ReleaseClDataPointerListRange; // +0x10
  R6GameServiceNative::Address DestroyListNodeAndReturnNext; // +0x14
};
const clPointerList_PAVclGameMessageVTableRecord clPointerList_PAVclGameMessageVTable = {
  R6GameServiceAddresses::DestroyObjectAndMaybeFree,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstListNode,
  R6GameServiceAddresses::PopLastVirtualPayload,
  R6GameServiceAddresses::ReleaseClDataPointerListRange,
  R6GameServiceAddresses::DestroyListNodeAndReturnNext,
};

// Native virtual-table prefix: clPointerList_PAVclSendElementVTable
// R6GameService.dll data @ 10078108 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclSendElementVTableRecord {
  R6GameServiceNative::Address DeleteCompactPointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstListEntryAndBuffer; // +0x08
  R6GameServiceNative::Address PopLastBufferedPayload; // +0x0c
  R6GameServiceNative::Address ReleaseListNodesInRange; // +0x10
  R6GameServiceNative::Address EraseCompactBufferNode; // +0x14
};
const clPointerList_PAVclSendElementVTableRecord clPointerList_PAVclSendElementVTable = {
  R6GameServiceAddresses::DeleteCompactPointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstListEntryAndBuffer,
  R6GameServiceAddresses::PopLastBufferedPayload,
  R6GameServiceAddresses::ReleaseListNodesInRange,
  R6GameServiceAddresses::EraseCompactBufferNode,
};

// Native virtual-table prefix: clPointerList_PAVclRcvElementVTable
// R6GameService.dll data @ 10078124 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclRcvElementVTableRecord {
  R6GameServiceNative::Address DeleteEmbeddedPointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstCallbackListEntry; // +0x08
  R6GameServiceNative::Address PopBackCallbackListEntry; // +0x0c
  R6GameServiceNative::Address EraseOwnedPayloadListRange; // +0x10
  R6GameServiceNative::Address EraseCallbackPointerListNode; // +0x14
};
const clPointerList_PAVclRcvElementVTableRecord clPointerList_PAVclRcvElementVTable = {
  R6GameServiceAddresses::DeleteEmbeddedPointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstCallbackListEntry,
  R6GameServiceAddresses::PopBackCallbackListEntry,
  R6GameServiceAddresses::EraseOwnedPayloadListRange,
  R6GameServiceAddresses::EraseCallbackPointerListNode,
};

// Native virtual-table prefix: clPointerList_PAVclProxyMessageVTable
// R6GameService.dll data @ 100783ec : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVclProxyMessageVTableRecord {
  R6GameServiceNative::Address DeleteCallbackListContainer; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstPayloadListNode; // +0x08
  R6GameServiceNative::Address DestroyLastPayloadListNode; // +0x0c
  R6GameServiceNative::Address ErasePayloadListRange; // +0x10
  R6GameServiceNative::Address ErasePayloadListNode; // +0x14
};
const clPointerList_PAVclProxyMessageVTableRecord clPointerList_PAVclProxyMessageVTable = {
  R6GameServiceAddresses::DeleteCallbackListContainer,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstPayloadListNode,
  R6GameServiceAddresses::DestroyLastPayloadListNode,
  R6GameServiceAddresses::ErasePayloadListRange,
  R6GameServiceAddresses::ErasePayloadListNode,
};
