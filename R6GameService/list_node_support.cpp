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

// Genuine empty allocator cleanup; preserves registers and returns without accessing the context.
// R6GameService.dll @ 10059130 : native control/access order and raw ABI retained.
__declspec(naked) void __thiscall list_node_support_NoOp(void *context)
{
  __asm {
    ret
  }
}

// Releases nodes using cached successors, resets current sentinel links separately and frees current sentinel.
// Head reloads remain observable through callbacks; the list head stays dangling and raw free EAX survives.
// R6GameService.dll @ 10059140 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseNodesAndSentinel(void *list)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch2
  Branch1:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi]
    jne    Branch1
  Branch2:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    ret
  }
}

// Tail-forwards the receiver to the shared node/sentinel release body.
// R6GameService.dll @ 1004fee0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseNodesAndSentinelThunk(void *list)
{
  __asm {
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Allocates a payload node, reloads position after allocation, links before it and publishes the output slot.
// R6GameService.dll @ 1002aad0 : native control/access order and raw ABI retained.
__declspec(naked) uint * __stdcall InsertPayloadNodeBefore(uint *out,uint *position,uint *payloadSlot)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    push   eax
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax],ecx
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx+0x4],eax
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [ecx],eax
    mov    eax,ecx
    ret    0xc
  }
}

// Allocates a12-byte node and copies the late source word into its payload unless node+8 wraps to NULL.
// A NULL allocation normally writes address8 unchecked; the two link words remain untouched.
// R6GameService.dll @ 1004c280 : native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall AllocateListPayloadNode(uint *payloadSlot)
{
  __asm {
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x8]
    test   ecx,ecx
    je     Branch3
    mov    edx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [edx]
    mov    DWORD PTR [ecx],edx
  Branch3:
    ret    0x4
  }
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

// Zeroes the head cell through shared initializer, allocates12-byte sentinel, self-links and publishes it without NULL guard.
// R6GameService.dll @ 100557d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __thiscall InitializeCircularListSentinel(void *headCell,uint contextWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   0x0
    push   eax
    mov    esi,ecx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Frees nodes using cached successor/current head reload, resets current sentinel links separately and retains its allocation.
// R6GameService.dll @ 10027590 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ReleaseListNodesRetainHeader(void *headCell)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch5
  Branch4:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi]
    jne    Branch4
  Branch5:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax],eax
    mov    edi,DWORD PTR [edi]
    mov    DWORD PTR [edi+0x4],edi
    pop    edi
    pop    esi
    ret
  }
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

// Cache next before releasing node+8 reference (target at node+14), then free node and compare CURRENT head.
// Reload head for EACH final self-link store; no count reset or own guard. Raw EAX is first final head.
// R6GameService.dll @ 10042db0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearPayloadList(int *list)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch9
    push   edi
  Branch8:
    mov    edi,esi
    mov    esi,DWORD PTR [esi]
    lea    ecx,[edi+0x8]
    call   R6GameServiceAddresses::ReleasePayloadReferenceAt12
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [ebx]
    jne    Branch8
    pop    edi
  Branch9:
    mov    eax,DWORD PTR [ebx]
    pop    esi
    mov    DWORD PTR [eax],eax
    mov    ebx,DWORD PTR [ebx]
    mov    DWORD PTR [ebx+0x4],ebx
    pop    ebx
    ret
  }
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
__declspec(naked) void *__thiscall EraseCallbackPointerListNode(void *owner,void *successorOut,uint node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je     Branch16
    mov    esi,DWORD PTR [edi+0x8]
    test   esi,esi
    je     Branch16
    mov    ecx,esi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch16:
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

// First destroy/free cached payloads while reading next after callbacks; then unlink/free the iterator range.
// Cache end, reread current owner head during payload pass, copy CURRENT first argument for node pass.
// Final output pointer is reloaded after all frees; store cached end and return that pointer/RET12. No own guard.
// R6GameService.dll @ 1004cdb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall EraseOwnedPayloadListRange(void *owner,void *endOut,uint first,uint end)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    esi,edi
    mov    ebp,ecx
    je     Branch19
  Branch17:
    cmp    esi,DWORD PTR [ebp+0x4]
    je     Branch19
    mov    ebx,DWORD PTR [esi+0x8]
    test   ebx,ebx
    je     Branch18
    mov    ecx,ebx
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   ebx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch18:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch17
  Branch19:
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x1c]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    je     Branch21
  Branch20:
    mov    ecx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esp+0x20],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    jne    Branch20
  Branch21:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Shared send-element/send-queue slot10: free each current +8 buffer then cached wrapper before unlinking any node.
// First pass stops at cached end or CURRENT head; second restarts from CURRENT original first argument to cached end.
// Reload output after callbacks, write cached end and return output/RET12; preserve alias and partial effects.
// R6GameService.dll @ 10058db0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__thiscall ReleaseListNodesInRange(
    void *owner,uint *endOut,int *beginNode,int *endNode)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    esi,edi
    mov    ebp,ecx
    je     Branch24
  Branch22:
    cmp    esi,DWORD PTR [ebp+0x4]
    je     Branch24
    mov    ebx,DWORD PTR [esi+0x8]
    test   ebx,ebx
    je     Branch23
    mov    ecx,ebx
    call   R6GameServiceAddresses::ReleaseCompactRecordBuffer
    push   ebx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch23:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch22
  Branch24:
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x1c]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    je     Branch26
  Branch25:
    mov    ecx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esp+0x20],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    jne    Branch25
  Branch26:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Shared clData/clGameMessage pointer-list slot10: invoke each payload deleting slot1 before unlinking any node.
// First pass stops at cached end or CURRENT head; restart at CURRENT original first argument for node-only pass.
// Reload output after callbacks, write cached end and return output/RET12; preserve alias and partial effects.
// R6GameService.dll @ 10058f90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__thiscall ReleaseClDataPointerListRange(
    void *owner,uint *endOut,uint *beginNode,uint *endNode)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ebx,ecx
    cmp    esi,edi
    je     Branch29
  Branch27:
    cmp    esi,DWORD PTR [ebx+0x4]
    je     Branch29
    mov    ecx,DWORD PTR [esi+0x8]
    test   ecx,ecx
    je     Branch28
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch28:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch27
  Branch29:
    lea    ecx,[esp+0x14]
    push   ecx
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x18]
    cmp    eax,edi
    je     Branch31
  Branch30:
    mov    edx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esp+0x1c],edx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x18]
    cmp    eax,edi
    jne    Branch30
  Branch31:
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Free a nonnull CURRENT +8 raw buffer, retaining its pointer and raw free EAX; null returns full zero.
// R6GameService.dll @ 1005caa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseCompactRecordBuffer(int record)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x8]
    test   eax,eax
    je     Branch32
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch32:
    ret
  }
}

// Initialize wrapper12: optional78238 offset table, byte4/byte5/WORD6 and owned-message pointer8; return receiver/RET20.
// Full initialization flag; preserve original field/argument load order and zeroed saved-ECX scratch.
// R6GameService.dll @ 1005c710 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeCompactRecordHeader(
    void *record,uint headerWord,uint flagsWord,uint keyWord,void *message,uint initializeSharedWord)
{
  __asm {
    push    ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    test    ecx,ecx
    mov    DWORD PTR [esp+0x0],0x0
    je    Branch33
    mov    DWORD PTR [eax],0x10078238
  Branch33:
    mov    cl,BYTE PTR [esp+0x8]
    mov    dl,BYTE PTR [esp+0xc]
    mov    BYTE PTR [eax+0x4],cl
    mov    cx,WORD PTR [esp+0x10]
    mov    BYTE PTR [eax+0x5],dl
    mov    edx,DWORD PTR [esp+0x14]
    mov    WORD PTR [eax+0x6],cx
    mov    DWORD PTR [eax+0x8],edx
    pop    ecx
    ret    0x14
  }
}

// Initialize wrapper16: optional78264 offset table, byte4/byte5/WORD6, owned raw bytes8/countc; receiver/RET24.
// Full initialization flag; preserve original field/argument load order and zeroed saved-ECX scratch.
// R6GameService.dll @ 1005ca50 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeCompactPayloadRecord(
    void *record,uint headerWord,uint flagsWord,uint keyWord,void *bytes,uint byteCount,uint initializeSharedWord)
{
  __asm {
    push    ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    test    ecx,ecx
    mov    DWORD PTR [esp+0x0],0x0
    je    Branch34
    mov    DWORD PTR [eax],0x10078264
  Branch34:
    mov    cl,BYTE PTR [esp+0x8]
    mov    dl,BYTE PTR [esp+0xc]
    mov    BYTE PTR [eax+0x4],cl
    mov    cx,WORD PTR [esp+0x10]
    mov    BYTE PTR [eax+0x5],dl
    mov    edx,DWORD PTR [esp+0x14]
    mov    WORD PTR [eax+0x6],cx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [eax+0x8],edx
    mov    DWORD PTR [eax+0xc],ecx
    pop    ecx
    ret    0x18
  }
}

// Shared send-buffer list slot14: release current wrapper+8 raw buffer, cached wrapper, then current neighboring node links.
// Sentinel skips payload destruction but still unlinks/frees node. Reload output argument after callbacks, write next/RET8.
// R6GameService.dll @ 10058d70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__thiscall EraseCompactBufferNode(void *owner,uint *nextOut,void *node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je    Branch35
    mov    esi,DWORD PTR [edi+0x8]
    test    esi,esi
    je    Branch35
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseCompactRecordBuffer
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch35:
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
