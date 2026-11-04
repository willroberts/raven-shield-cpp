#include "native_addresses.h"
#include "native_records.h"

// Shared twelve-byte non-owning payload list nodes and sentinel helpers.

// Copies the current sentinel first link to the output slot and returns that slot.
// R6GameService.dll @ 100590f0 : native control/access order and raw ABI retained.
uint * __thiscall ReadListFirstNodeFromHeadSlot(void *list,uint *out)
{
  uint head = *static_cast<const uint *>(list);
  uint first = *reinterpret_cast<const uint *>(head);
  *out = first;
  return out;
}

// Clears the list head, allocates a12-byte sentinel and initializes its two links before publishing it.
// The tag argument is unused; allocation NULL is dereferenced unchecked and the payload word remains untouched.
// R6GameService.dll @ 10059110 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializePayloadListHeader(void *list,uint unusedTagPointer)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   0xc
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Genuine empty allocator cleanup; the context is unused and no value is returned.
// R6GameService.dll @ 10059130 : no native memory accesses or calls.
void __thiscall list_node_support_NoOp(void *context)
{
}

// Free nodes using cached successors, then self-link and free the current sentinel; leave the head slot dangling.
// R6GameService.dll @ 10059140 : head is reloaded after callbacks and separately for each sentinel operation.
uint __thiscall ReleaseNodesAndSentinel(void *list)
{
  uint head = *(uint *)list;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *(uint *)list);
  }
  head = *(uint *)list;
  *(uint *)head = head;
  head = *(uint *)list;
  *(uint *)(head + 4) = head;
  head = *(uint *)list;
  return TailFreeThroughGlobalAllocator((void *)head);
}

// Tail-forwards the receiver to the shared node/sentinel release body.
// R6GameService.dll @ 1004fee0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseNodesAndSentinelThunk(void *list)
{
  __asm {
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Allocate a borrowed-payload node, reload its insertion position, link it and finally publish the output slot.
// R6GameService.dll @ 1002aad0 : allocation runs before the position and output arguments are sampled.
uint * __stdcall InsertPayloadNodeBefore(uint *out,uint *position,uint *payloadSlot)
{
  using AllocateABI = void * (__stdcall *)(uint *);
  uint node = (uint)((AllocateABI)R6GameServiceAddresses::AllocateListPayloadNode)(payloadSlot);
  uint *next = position;
  uint previous = *(uint *)((byte *)next + 4);
  *(uint *)node = (uint)next;
  *(uint *)(node + 4) = previous;
  *(uint *)previous = node;
  *(uint *)((byte *)next + 4) = node;
  uint *result = out;
  *result = node;
  return result;
}

// Allocate a twelve-byte node and copy its late source payload unless node+8 wraps to zero; links stay untouched.
// R6GameService.dll @ 1004c280 : a null allocation still writes address 8 without a guard.
void * __stdcall AllocateListPayloadNode(uint *payloadSlot)
{
  uint node = (uint)AllocateGameServiceBytes(0xc);
  uint payload = node + 8;
  if (payload != 0) {
    uint *source = payloadSlot;
    uint value = *source;
    *(uint *)payload = value;
  }
  return (void *)node;
}

// Copies the current head word to the stacked output pointer and returns that output pointer.
// R6GameService.dll @ 10059000 : native control/access order and raw ABI retained.
uint * __thiscall CopyListHeadSlot(void *headSlot,uint *output)
{
  *output = *static_cast<const uint *>(headSlot);
  return output;
}

// Replaces the iterator word with its node predecessor and returns the iterator address.
// R6GameService.dll @ 10059170 : native control/access order and raw ABI retained.
uint * __fastcall RetreatNodeIterator(uint *iterator)
{
  uint node = *iterator;
  *iterator = reinterpret_cast<const uint *>(node)[1];
  return iterator;
}

// Clear the head through the context-ignoring initializer, then allocate, self-link and publish an unchecked sentinel.
// R6GameService.dll @ 100557d0 : inferred physical field views; native load/store order and return width retained.
void * __thiscall InitializeCircularListSentinel(void *headCell,uint contextWord)
{
  StoreFirstWordIgnoringContext(headCell,contextWord,0);
  uint sentinel = (uint)AllocateGameServiceBytes(0xc);
  *(uint *)sentinel = sentinel;
  *(uint *)(sentinel + 4) = sentinel;
  *(uint *)headCell = sentinel;
  return headCell;
}

// Free nodes using cached successors, then separately reload and reset both sentinel links without freeing its storage.
// R6GameService.dll @ 10027590 : inferred physical field views; native load/store order and return width retained.
uint __thiscall ReleaseListNodesRetainHeader(void *headCell)
{
  uint head = *(uint *)headCell;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *(uint *)headCell);
  }
  head = *(uint *)headCell;
  *(uint *)head = head;
  uint currentHead = *(uint *)headCell;
  *(uint *)(currentHead + 4) = currentHead;
  return head;
}

// Clear head, allocate4c-byte sentinel without NULL guard, publish self links then head; RET4/raw receiver EAX.
// Incoming stack word is unread; no own EH/failed-initialization cleanup, remaining sentinel bytes unwritten.
// R6GameService.dll @ 100338e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeCallbackListSentinel(void *receiver,uint word1)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   0x4c
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Snapshot *firstLink/*endLink, follow next words and count modulo32; return without popping arguments.
// All seven native callers pass an unread third category address; variadic raw view is not an original prototype.
// No null/cycle/count bound or owned input; unreachable end can loop forever or fault.
// R6GameService.dll @ 10031f70 : complete native control/access order and raw ABI retained.
uint __cdecl CountCircularListRange(const uint *firstLink,const uint *endLink,...)
{
  uint node = *firstLink;
  uint end = *endLink;
  uint count = 0;
  while (node != end) {
    node = *reinterpret_cast<const uint *>(node);
    ++count;
  }
  return count;
}

// Cache each successor, release the reference at node+8 and free the node; independently reset current sentinel links.
// R6GameService.dll @ 10042db0 : retains sentinel and count; returns the header used for the first final self-link.
uint __fastcall ClearPayloadList(int *list)
{
  uint head = *(uint *)list;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      using ReleaseABI = uint (__fastcall *)(int);
      ((ReleaseABI)R6GameServiceAddresses::ReleasePayloadReferenceAt12)((int)(detached + 8));
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *(uint *)list);
  }
  head = *(uint *)list;
  *(uint *)head = head;
  uint currentHead = *(uint *)list;
  *(uint *)(currentHead + 4) = currentHead;
  return head;
}

// Compute null-preserving CURRENT saved owner+4 into parent S-24, then unconditionally release list nodes/header.
// R6GameService.dll @ 100682e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl list_node_supportSharedLifetimeUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je     Branch10
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch11
  Branch10:
    mov    DWORD PTR [ebp-0x24],0x0
  Branch11:
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the one-state metadata shared by both typed list destructors; tail current CRT dispatch.
// R6GameService.dll @ 10068307 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTypedPointerListDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::list_node_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10082cdc: exact list destruction map or FuncInfo.
const R6GameServiceNative::UnwindEntry list_node_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::list_node_supportSharedLifetimeUnwind1},
};

// R6GameService.dll data @ 10082ce4: exact list destruction map or FuncInfo.
// R6GameService.dll data @ 10082cdc : native storage identity retained.
const R6GameServiceNative::FuncInfo list_node_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::list_node_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Shared primary77eec/78124/78244 slots: CCurMessage and clRcvElement pointer lists, plus clRcvMsgQueue.

// Pop front: destroy/free cached initial payload through shared offset8 cleanup, then remove CURRENT head first node.
// Empty returns head EAX; nonempty returns allocator residue. No own guard or callback repair.
// R6GameService.dll @ 10058e30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyFirstCallbackListEntry(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch13
    mov    ecx,DWORD PTR [eax]
    push   edi
    mov    edi,DWORD PTR [ecx+0x8]
    test   edi,edi
    je     Branch12
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [edx]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch13:
    pop    esi
    ret
  }
}

// Pop back: destroy/free cached initial tail payload through offset8 cleanup, then decrement CURRENT head iterator.
// Unlink/free that current tail; empty returns head EAX, otherwise backend residue. No own guard.
// R6GameService.dll @ 10058e70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PopBackCallbackListEntry(void *owner)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch15
    mov    eax,DWORD PTR [eax+0x4]
    push   edi
    mov    edi,DWORD PTR [eax+0x8]
    test   edi,edi
    je     Branch14
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch14:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x8]
    call   R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch15:
    pop    esi
    pop    ecx
    ret
  }
}

// Erase selected node: cached payload cleanup/free first unless head/null, then read CURRENT links and unlink/free.
// Reload output argument only AFTER node free, store cached successor, return output pointer/RET8. No head repair.
// R6GameService.dll @ 1004cd70 : complete native control/access order and raw ABI retained.
void *__thiscall EraseCallbackPointerListNode(void *owner,void *successorOut,uint node)
{
  uint head = *(uint *)((uint)owner + 4);
  uint savedNode = node;
  if (savedNode != head) {
    void *payload = *(void **)(savedNode + 8);
    if (payload != 0) {
      using DestroyABI = void (__fastcall *)(void *);
      ((DestroyABI)R6GameServiceAddresses::DeleteOwnedObjectAtOffset8)(payload);
      TailFreeThroughGlobalAllocator(payload);
    }
  }
  uint previous = *(uint *)(savedNode + 4);
  uint next = *(uint *)savedNode;
  *(uint *)previous = next;
  *(uint *)(next + 4) = previous;
  TailFreeThroughGlobalAllocator((void *)savedNode);
  void *result = successorOut;
  *(uint *)result = next;
  return result;
}

// First destroy/free cached payloads while reading next after callbacks; then unlink/free the iterator range.
// Cache end, reread current owner head during payload pass, copy CURRENT first argument for node pass.
// Final output pointer is reloaded after all frees; store cached end and return that pointer/RET12. No own guard.
// R6GameService.dll @ 1004cdb0 : complete native control/access order and raw ABI retained.
void *__thiscall EraseOwnedPayloadListRange(void *owner,void *endOut,uint first,uint end)
{
  uint visited = first;
  uint stop = end;
  while (visited != stop) {
    uint head = *(uint *)((uint)owner + 4);
    if (visited == head) break;
    void *payload = *(void **)(visited + 8);
    if (payload != 0) {
      using DestroyABI = void (__fastcall *)(void *);
      ((DestroyABI)R6GameServiceAddresses::DeleteOwnedObjectAtOffset8)(payload);
      TailFreeThroughGlobalAllocator(payload);
    }
    visited = *(uint *)visited;
  }
  using CopyABI = void * (__thiscall *)(void *,const void *);
  ((CopyABI)R6GameServiceAddresses::CopyFirstWord)(&end,&first);
  uint current = end;
  while (current != stop) {
    uint next = *(uint *)current;
    end = next;
    uint previous = *(uint *)(current + 4);
    uint currentNext = *(uint *)current;
    *(uint *)previous = currentNext;
    *(uint *)(currentNext + 4) = previous;
    TailFreeThroughGlobalAllocator((void *)current);
    current = end;
  }
  void *output = endOut;
  *(uint *)output = stop;
  return output;
}

// Destroy payloads before unlinking nodes; restart from the current begin argument and keep the captured end.
// R6GameService.dll @ 10058db0 : end argument becomes the node-pass cursor; current head terminates only payload cleanup.
uint * __thiscall ReleaseListNodesInRange(void *owner,uint *endOut,uint *beginNode,uint *endNode)
{
  byte *visited = (byte *)beginNode;
  byte *stop = (byte *)endNode;
  while (visited != stop) {
    if ((uint)visited == *(uint *)((byte *)owner + 4)) break;
    void *payload = *(void **)(visited + 8);
    if (payload != nullptr) {
      using ReleaseABI = uint (__fastcall *)(int);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseCompactRecordBuffer)((int)payload);
      TailFreeThroughGlobalAllocator(payload);
    }
    visited = *(byte **)visited;
  }
  using CopyABI = void * (__thiscall *)(void *,const void *);
  ((CopyABI)R6GameServiceAddresses::CopyFirstWord)(&endNode,&beginNode);
  byte *current = (byte *)endNode;
  while (current != stop) {
    uint next = *(uint *)current;
    endNode = (uint *)next;
    uint previous = *(uint *)(current + 4);
    uint currentNext = *(uint *)current;
    *(uint *)previous = currentNext;
    *(uint *)(currentNext + 4) = previous;
    TailFreeThroughGlobalAllocator(current);
    current = (byte *)endNode;
  }
  uint *result = endOut;
  *result = (uint)stop;
  return result;
}

// Destroy payloads before unlinking nodes; restart from the current begin argument and keep the captured end.
// R6GameService.dll @ 10058f90 : end argument becomes the node-pass cursor; current head terminates only payload cleanup.
uint * __thiscall ReleaseClDataPointerListRange(void *owner,uint *endOut,uint *beginNode,uint *endNode)
{
  byte *visited = (byte *)beginNode;
  byte *stop = (byte *)endNode;
  while (visited != stop) {
    if ((uint)visited == *(uint *)((byte *)owner + 4)) break;
    void *payload = *(void **)(visited + 8);
    if (payload != nullptr) {
      using DeleteABI = uint (__thiscall *)(void *,uint);
      byte *table = *(byte **)payload;
      (*(DeleteABI *)table)(payload,1);
    }
    visited = *(byte **)visited;
  }
  using CopyABI = void * (__thiscall *)(void *,const void *);
  ((CopyABI)R6GameServiceAddresses::CopyFirstWord)(&endNode,&beginNode);
  byte *current = (byte *)endNode;
  while (current != stop) {
    uint next = *(uint *)current;
    endNode = (uint *)next;
    uint previous = *(uint *)(current + 4);
    uint currentNext = *(uint *)current;
    *(uint *)previous = currentNext;
    *(uint *)(currentNext + 4) = previous;
    TailFreeThroughGlobalAllocator(current);
    current = (byte *)endNode;
  }
  uint *result = endOut;
  *result = (uint)stop;
  return result;
}

// Free the current raw buffer at +8 when nonnull; keep its pointer and return zero or the allocator result.
// R6GameService.dll @ 1005caa0 : inferred physical field views; native load/store order and return width retained.
uint __fastcall ReleaseCompactRecordBuffer(int record)
{
  uint buffer = *(uint *)((uint)record + 8);
  if (buffer != 0) return TailFreeThroughGlobalAllocator((void *)buffer);
  return 0;
}

// Initialize the compact owned-message wrapper using byte/byte/word fields and an optional base-offset table.
// R6GameService.dll @ 1005c710 : inferred physical field views; native load/store order and return width retained.
void * __thiscall InitializeCompactRecordHeader(
    void *record,uint headerWord,uint flagsWord,uint keyWord,void *message,uint initializeSharedWord)
{
  if (initializeSharedWord != 0) *(uint *)record = 0x10078238;
  byte header = (byte)headerWord;
  byte flags = (byte)flagsWord;
  *((byte *)record + 4) = header;
  ushort key = (ushort)keyWord;
  *((byte *)record + 5) = flags;
  void *payload = message;
  *(ushort *)((byte *)record + 6) = key;
  *(void **)((byte *)record + 8) = payload;
  return record;
}

// Initialize the compact raw-payload wrapper, preserving narrow field stores and the late count/pointer reads.
// R6GameService.dll @ 1005ca50 : inferred physical field views; native load/store order and return width retained.
void * __thiscall InitializeCompactPayloadRecord(
    void *record,uint headerWord,uint flagsWord,uint keyWord,void *bytes,uint byteCount,uint initializeSharedWord)
{
  if (initializeSharedWord != 0) *(uint *)record = 0x10078264;
  byte header = (byte)headerWord;
  byte flags = (byte)flagsWord;
  *((byte *)record + 4) = header;
  ushort key = (ushort)keyWord;
  *((byte *)record + 5) = flags;
  void *payload = bytes;
  *(ushort *)((byte *)record + 6) = key;
  uint count = byteCount;
  *(void **)((byte *)record + 8) = payload;
  *(uint *)((byte *)record + 0xc) = count;
  return record;
}

// Release a nonsentinel node's raw buffer and cached wrapper, then unlink/free the node and publish its saved successor.
// R6GameService.dll @ 10058d70 : inferred physical field views; native load/store order and return width retained.
uint * __thiscall EraseCompactBufferNode(void *owner,uint *nextOut,void *node)
{
  uint head = *(uint *)((byte *)owner + 4);
  byte *current = (byte *)node;
  if ((uint)current != head) {
    uint wrapper = *(uint *)(current + 8);
    if (wrapper != 0) {
      using ReleaseABI = uint (__fastcall *)(int);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseCompactRecordBuffer)((int)wrapper);
      TailFreeThroughGlobalAllocator((void *)wrapper);
    }
  }
  uint previous = *(uint *)(current + 4);
  uint next = *(uint *)current;
  *(uint *)previous = next;
  *(uint *)(next + 4) = previous;
  TailFreeThroughGlobalAllocator(current);
  uint *result = nextOut;
  *result = next;
  return result;
}

// Unlink node using current previous/cached next, free node, then reload output argument and store cached
// next/return output.
// No payload deletion or sentinel guard; raw iterator output/RET8.
// R6GameService.dll @ 1005ed80 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall EraseCircularNode(void *result,void *node)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push    esi
    push    eax
    mov    ecx,DWORD PTR [eax+0x4]
    mov    esi,DWORD PTR [eax]
    mov    DWORD PTR [ecx],esi
    mov    DWORD PTR [esi+0x4],ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x8]
    mov    DWORD PTR [eax],esi
    pop    esi
    ret    0x8
  }
}

// Initialize headNULL through561b0, allocate36-byte head, self-link then publish; no NULL guard. RET4.
// R6GameService.dll @ 10042cf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeCircularList36(void *list,uint unusedContext)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    push    0x0
    push    eax
    mov    esi,ecx
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push    0x24
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Cache next node before releasing node+14 reference via42b70, then free current; compare CURRENT head each step.
// Reset CURRENT head links and free head; shared no-op unwind does not retry nodes/head/ref effects.
// R6GameService.dll @ 10041a30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServicePayloadCircularList(void *list)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectCircularReferenceDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x8],edi
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x14],0x0
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch37
    push    ebx
  Branch36:
    mov    ebx,esi
    mov    esi,DWORD PTR [esi]
    lea    ecx,[ebx+0x10]
    call    R6GameServiceAddresses::thunk_ReleasePayloadReferenceAt4
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi]
    jne    Branch36
    pop    ebx
  Branch37:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// If nonempty, release captured tail payload child through5caa0, free payload, then unlink/free CURRENT tail node.
// Reload head after payload free; keep previous-link iterator scratch, raw free EAX/current-node ECX, empty head EAX and no own EH.
// R6GameService.dll @ 10058d20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PopLastBufferedPayload(void *list)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je    Branch39
    mov    eax,DWORD PTR [eax+0x4]
    push   edi
    mov    edi,DWORD PTR [eax+0x8]
    test   edi,edi
    je    Branch38
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseCompactRecordBuffer
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch38:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x8]
    call   R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch39:
    pop    esi
    pop    ecx
    ret
  }
}

// If nonempty, virtually delete captured tail payload with flag1, then unlink/free CURRENT tail node.
// Reload head after virtual callback; preserve independent link stores, raw EAX/current-node ECX and empty head residue; no own EH.
// R6GameService.dll @ 10058f50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PopLastVirtualPayload(void *list)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je    Branch41
    mov    eax,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je    Branch40
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
  Branch40:
    mov    eax,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x4]
    mov    DWORD PTR [esp+0x4],eax
    call   R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch41:
    pop    esi
    pop    ecx
    ret
  }
}
