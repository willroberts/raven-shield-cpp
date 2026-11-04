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

// Create the self-linked sentinel before publishing clData pointer-list identity; leave its payload untouched.
// R6GameService.dll @ 10027170 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall ConstructClDataPointerList(void *list,uint initializeVirtualBaseWord)
{
  if (initializeVirtualBaseWord != 0) *(uint *)((byte *)list + 8) = 0x10076aa8;
  *(uint *)((byte *)list + 4) = 0;
  uint sentinel = (uint)AllocateGameServiceBytes(0xc);
  *(uint *)sentinel = sentinel;
  *(uint *)(sentinel + 4) = sentinel;
  *(uint *)((byte *)list + 4) = sentinel;
  *(uint *)list = R6GameServiceAddresses::clDataListPTR_FUN2;
  return list;
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

namespace {
// Inferred one-state guard for typed pointer-list storage, independent of payload ownership.
struct TypedPointerListStorageCleanup {
  void *savedList;
  bool armed;
  // Drain the current nodes and sentinel without retrying payload release, preserving null-adjusted contexts.
  ~TypedPointerListStorageCleanup() noexcept(false) {
    if (armed) {
      void *headSlot = savedList == nullptr ? nullptr : (byte *)savedList + 4;
      using ReleaseABI = uint (__thiscall *)(void *);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(headSlot);
    }
  }
};
}

// Virtually release the payload range, then drain remaining nodes and the current sentinel without repairing the owner.
// R6GameService.dll @ 1002ee90 : storage cleanup stays armed through final free; native EAX retains allocator residue.
uint __fastcall DestroyCircularList(void *list)
{
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  TypedPointerListStorageCleanup cleanup{list, false};
  *(uint *)list = R6GameServiceAddresses::clPointerList_PAVclMemoryElementVTable;
  uint end = *(uint *)((byte *)list + 4);
  uint *headSlot = (uint *)((byte *)list + 4);
  uint begin = end;
  byte *table = *(byte **)list;
  cleanup.armed = true;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(headSlot,&begin);
  uint resultWord;
  (*(RangeABI *)(table + 0x10))(list,&resultWord,begin,end);
  uint head = *headSlot;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *headSlot);
  }
  head = *headSlot;
  *(uint *)head = head;
  head = *headSlot;
  *(uint *)(head + 4) = head;
  head = *headSlot;
  uint result = TailFreeThroughGlobalAllocator((void *)head);
  cleanup.armed = false;
  return result;
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

// Free payloads before unlinking nodes; restart from the current first argument and use last as node-pass scratch.
// R6GameService.dll @ 10031f00 : cached end bounds both passes; only payload traversal stops at the current sentinel.
uint * __thiscall EraseOwningPointerListRange(void *list,uint *out,uint first,uint last)
{
  uint cursor = first;
  uint stop = last;
  while (cursor != stop) {
    if (cursor == *(uint *)((byte *)list + 4)) break;
    uint payload = *(uint *)(cursor + 8);
    if (payload != 0) TailFreeThroughGlobalAllocator((void *)payload);
    cursor = *(uint *)cursor;
  }
  using CopyABI = void * (__thiscall *)(void *,const void *);
  ((CopyABI)R6GameServiceAddresses::CopyFirstWord)(&last,&first);
  uint current = last;
  while (current != stop) {
    uint next = *(uint *)current;
    last = next;
    uint previous = *(uint *)(current + 4);
    uint currentNext = *(uint *)current;
    *(uint *)previous = currentNext;
    *(uint *)(currentNext + 4) = previous;
    TailFreeThroughGlobalAllocator((void *)current);
    current = last;
  }
  uint *result = out;
  *result = stop;
  return result;
}

// Invoke the captured virtual range eraser with the current first node and cached sentinel, forwarding its raw result.
// R6GameService.dll @ 10062920 : native iterator output reuses the saved entry-ECX word.
uint __fastcall InvokePointerListClearRange(void *list)
{
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  uint resultWord = (uint)list;
  uint end = *(uint *)((byte *)list + 4);
  void *headSlot = (byte *)list + 4;
  uint begin = (uint)headSlot;
  byte *table = *(byte **)list;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(headSlot,&begin);
  return (uint)(*(RangeABI *)(table + 0x10))(list,&resultWord,begin,end);
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

// Free a nonsentinel payload, unlink/free the cached node and publish its successor through the late output.
// R6GameService.dll @ 10031ec0 : sentinel input still unlinks/frees the node; the list count is untouched.
uint * __thiscall EraseOwningPointerListNode(void *list,uint *out,uint node)
{
  uint head = *(uint *)((byte *)list + 4);
  uint current = node;
  if (current != head) {
    uint payload = *(uint *)(current + 8);
    if (payload != 0) TailFreeThroughGlobalAllocator((void *)payload);
  }
  uint previous = *(uint *)(current + 4);
  uint next = *(uint *)current;
  *(uint *)previous = next;
  *(uint *)(next + 4) = previous;
  TailFreeThroughGlobalAllocator((void *)current);
  uint *result = out;
  *result = next;
  return result;
}

// Virtually release the payload range, then drain remaining nodes and the current sentinel without repairing the owner.
// R6GameService.dll @ 10031d90 : storage cleanup stays armed through final free; native EAX retains allocator residue.
void __fastcall DestroyParsedServiceRecordList(void *list)
{
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  TypedPointerListStorageCleanup cleanup{list, false};
  *(uint *)list = R6GameServiceAddresses::clPointerList_PAVclParentGroupVTable;
  uint end = *(uint *)((byte *)list + 4);
  uint *headSlot = (uint *)((byte *)list + 4);
  uint begin = end;
  byte *table = *(byte **)list;
  cleanup.armed = true;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(headSlot,&begin);
  uint resultWord;
  (*(RangeABI *)(table + 0x10))(list,&resultWord,begin,end);
  uint head = *headSlot;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *headSlot);
  }
  head = *headSlot;
  *(uint *)head = head;
  head = *headSlot;
  *(uint *)(head + 4) = head;
  head = *headSlot;
  TailFreeThroughGlobalAllocator((void *)head);
  cleanup.armed = false;
}

// Destroy the list before sampling the current deletion flag, optionally free its allocation and return the receiver.
// R6GameService.dll @ 10031e20 : only bit 0 controls storage release; full flags word remains the physical argument.
void * __thiscall DestroyParsedServiceRecordListObject(void *list,uint deleteFlags)
{
  using DestroyABI = void (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyParsedServiceRecordList)(list);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(list);
  return list;
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
void *__thiscall ErasePayloadListRange(void *owner,void *outputIterator,void *first,void *last)
{
  uint current = (uint)first;
  uint terminal = (uint)last;
  uint base = (uint)owner;
  while (current != terminal) {
    if (current == *(uint *)(base + 4)) break;
    void *payload = *(void **)(current + 8);
    if (payload != 0) {
      using DestroyABI = uint (__fastcall *)(void *);
      ((DestroyABI)R6GameServiceAddresses::DestroyPerNodeLinkedListContainer)(payload);
      TailFreeThroughGlobalAllocator(payload);
    }
    current = *(uint *)current;
  }
  using CopyABI = uint *(__thiscall *)(uint *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopyFirstWord)((uint *)&last,(const uint *)&first);
  current = (uint)last;
  while (current != terminal) {
    uint next = *(uint *)current;
    last = (void *)next;
    uint previous = *(uint *)(current + 4);
    uint reloadedNext = *(uint *)current;
    *(uint *)previous = reloadedNext;
    *(uint *)(reloadedNext + 4) = previous;
    TailFreeThroughGlobalAllocator((void *)current);
    current = (uint)last;
  }
  void *result = outputIterator;
  *(uint *)result = terminal;
  return result;
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
