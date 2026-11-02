#include "native_addresses.h"
#include "native_records.h"

// Indexed fixed-field record/list helpers; original record and surrounding tree class identities remain unresolved.

// Release the record list at+8c, then test CURRENT flag lowBYTE/bit0 and optionally CDECL-free the original record.
// Record may be a tree payload at node+10; caller flag0 keeps the outer node allocation. RET4/original record EAX.
// R6GameService.dll @ 10055300 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DestroyEmbeddedListAndMaybeNode(void *record,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ReleaseEmbeddedList8c
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Free list nodes through cached successors, reset each CURRENT head link and free CURRENT head; payload words borrowed.
// Record+8c head slot remains dangling; no own EH or payload destruction. Raw allocator EAX.
// R6GameService.dll @ 10054b50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseEmbeddedList8c(int recordAddress)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x8c]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch3
  Branch2:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi+0x8c]
    jne    Branch2
  Branch3:
    mov    eax,DWORD PTR [edi+0x8c]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi+0x8c]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi+0x8c]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    ret
  }
}

// Allocate168-byte tree node; construct record at+10 from live source loaded AFTER allocation.
// Copy key,129 bytes, WORD86/BYTE88, own a new list atnode9c containing shallow copied payload words; tail94 copied last.
// Preserve field gaps, unused node links, raw NULL/wrap behavior and true EBP frame; incoming ECX unused/RET4.
// Map releases current saved list only after state2; associated catch releases current saved raw allocation and rethrows.
// R6GameService.dll @ 100556a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__stdcall AllocateIndexedRecordAndCopyList(const void *sourceRecord)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectIndexedListNodeEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x1c],0x0
    mov    DWORD PTR [ebp-0x10],esp
    push   0xa8
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x10]
    mov    DWORD PTR [ebp-0x14],eax
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x20],ecx
    mov    DWORD PTR [ebp-0x24],ecx
    test   ecx,ecx
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch4
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebx]
    add    ebx,0x4
    mov    DWORD PTR [ecx],eax
    lea    eax,[ecx+0x4]
    mov    ecx,0x20
    mov    esi,ebx
    mov    edi,eax
    mov    DWORD PTR [ebp-0x1c],eax
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    movs   BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    cx,WORD PTR [ebx+0x82]
    lea    esi,[eax+0x88]
    mov    WORD PTR [eax+0x82],cx
    mov    dl,BYTE PTR [ebx+0x84]
    mov    BYTE PTR [eax+0x84],dl
    lea    edi,[ebx+0x88]
    lea    eax,[ebp+0xb]
    mov    ecx,edi
    push   eax
    mov    DWORD PTR [ebp-0x28],esi
    mov    DWORD PTR [esi+0x4],0x100780a8
    call   R6GameServiceAddresses::ForwardStackWord
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],0x2
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[ebp-0x30]
    mov    ecx,edi
    push   edx
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyCircularListPayloads
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    edx,DWORD PTR [ebx+0x90]
    mov    DWORD PTR [eax+0x90],edx
    mov    eax,DWORD PTR [ebp-0x14]
  Branch4:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Free CURRENT saved raw node at inherited real parent EBP-14, then rethrow through the current CRT import.
// Normally nonreturning; no local epilogue or ownership retry is added.
// R6GameService.dll @ 100557b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl indexed_record_supportCatch(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Append new12-byte nodes holding the same source payload DWORDs, with current post-allocation payload and previous link.
// Cache source end, read next source link after publication; stack iterator copies preserve native alias/access order.
// No own guard or payload ownership; RET12/raw helper or last-node EAX.
// R6GameService.dll @ 10055800 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CopyCircularListPayloads(
    void *context,undefined4 *destinationSentinel,undefined4 *sourceFirst,undefined4 *sourceEnd)
{
  __asm {
    push   ebx
    push   ebp
    lea    eax,[esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    push   eax
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::CopyFirstWord
    mov    ebp,DWORD PTR [esp+0x18]
    cmp    esi,ebp
    je     Branch6
    push   edi
  Branch5:
    lea    ecx,[esp+0x18]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::CopyFirstWord
    lea    edx,[esi+0x8]
    mov    ecx,ebx
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    edi,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    esi,DWORD PTR [esi]
    cmp    esi,ebp
    jne    Branch5
    pop    edi
  Branch6:
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Pass both saved record-subobject words at real parent EBP-20/-24 to genuine empty cleanup, then discard both words.
// R6GameService.dll @ 100690a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AllocateIndexedRecordAndCopyListUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x24]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Release current saved list-head slot at real parent EBP-28; borrowed payload DWORDs are not destroyed.
// R6GameService.dll @ 100690b1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AllocateIndexedRecordAndCopyListUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact four-state indexed-record construction/catch metadata and tail current CRT dispatch.
// R6GameService.dll @ 100690b9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedListNodeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateIndexedRecordAndCopyListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083aec : literal indexed-record unwind/handler/try/FuncInfo record.
const R6GameServiceNative::UnwindEntry AllocateIndexedRecordAndCopyListUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::AllocateIndexedRecordAndCopyListUnwind2},
  {0x1, R6GameServiceAddresses::AllocateIndexedRecordAndCopyListUnwind3},
  {-1, 0x0},
};

// R6GameService.dll data @ 10083b0c : literal indexed-record unwind/handler/try/FuncInfo record.
const R6GameServiceNative::CatchHandler indexed_record_supportGIndexedListNodeEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::indexed_record_supportCatch},
};

// R6GameService.dll data @ 10083b1c : literal indexed-record unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10083b0c : native storage identity retained.
const R6GameServiceNative::TryBlock AllocateIndexedRecordAndCopyListTryMap[1] = {
  {0x0, 0x2, 0x3, 0x1, R6GameServiceAddresses::indexed_record_supportGIndexedListNodeEH},
};

// R6GameService.dll data @ 10083b30 : literal indexed-record unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10083aec : native storage identity retained.
const R6GameServiceNative::FuncInfo AllocateIndexedRecordAndCopyListExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::AllocateIndexedRecordAndCopyListUnwindMap,
  0x1,
  R6GameServiceAddresses::AllocateIndexedRecordAndCopyListTryMap,
  0x0,
  0x0,
};

// Construct new circular list nodes with borrowed payload DWORDs; optional full-word flag installs table+4 before allocation.
// Cache source pointer before allocation, read source head afterward, then cache source end/destination head.
// Original source argument becomes destination-head scratch; ENTRY ESP saves receiver-10/state-4.
// State0 cleanup follows CURRENT saved receiver/head; no old-list release or NULL repair. RET8/receiver EAX.
// R6GameService.dll @ 10054c10 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CloneCircularList(void *list,int *sourceList,int installVtable)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectIndexedListCloneEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0xc],ebx
    mov    eax,DWORD PTR [esp+0x28]
    push   edi
    mov    edi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x14],edi
    je     Branch7
    mov    DWORD PTR [edi+0x4],0x100780a8
  Branch7:
    mov    esi,DWORD PTR [esp+0x28]
    lea    eax,[esp+0x2c]
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::ForwardStackWord
    push   0xc
    mov    DWORD PTR [edi],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,DWORD PTR [esi]
    lea    ecx,[esp+0x28]
    mov    esi,DWORD PTR [ebx]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0xc]
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    cmp    esi,ebx
    je     Branch9
    push   ebp
  Branch8:
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esi+0x8]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    ebp,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [ebp+0x4]
    lea    ecx,[ebp+0x4]
    mov    DWORD PTR [eax],ebp
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    esi,DWORD PTR [esi]
    cmp    esi,ebx
    jne    Branch8
    pop    ebp
  Branch9:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x8
  }
}

// Detach/rebalance the requested indexed node, release its copied list and node, then decrement CURRENT count modulo32.
// Initial head supplies root/extrema cell addresses; failures retain detached graph and prior count. RET4/count EAX.
// R6GameService.dll @ 10054ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EraseIndexedNode(void *tree,char *node)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   edi
    mov    eax,DWORD PTR [esi]
    lea    ecx,[eax+0xc]
    lea    edx,[eax+0x8]
    push   ecx
    add    eax,0x4
    push   edx
    push   eax
    mov    eax,DWORD PTR [esp+0x18]
    push   eax
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    mov    edi,eax
    add    esp,0x10
    lea    ecx,[edi+0x10]
    call   R6GameServiceAddresses::ReleaseEmbeddedList8c
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    pop    edi
    dec    eax
    mov    DWORD PTR [esi+0x4],eax
    pop    esi
    ret    0x4
  }
}

// Nonzero count gates right-first node/list release, then resets each CURRENT head link and clears count; retain header.
// Next-left read after right recursion is cached across list/node frees. Count0 returns0 without traversing.
// Nonzero path returns head used by final right-link store, not allocator residue; no own guard.
// R6GameService.dll @ 10054d20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearIndexedTree(int *tree)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    je     Branch12
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch11
    push   ebx
  Branch10:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseIndexedSubtree
    mov    ebx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleaseEmbeddedList8c
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch10
    pop    ebx
  Branch11:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch12:
    pop    edi
    ret
  }
}

// Release right subtree, cache current left, free borrowed-payload list nodes/header atnode9c, then outer node; iterate left.
// Context only forwards recursively, no head/count reset or own guard. RET4/null incoming EAX or last-free residue.
// R6GameService.dll @ 10054d80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseIndexedSubtree(void *context,uint node)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test   esi,esi
    je     Branch14
    push   edi
  Branch13:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ReleaseIndexedSubtree
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::ReleaseEmbeddedList8c
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   edi,edi
    mov    esi,edi
    jne    Branch13
    pop    edi
  Branch14:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Release nodes/current header through saved receiver at inherited original ENTRY ESP-10.
// R6GameService.dll @ 10069080 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CloneCircularListUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact one-state circular-list construction metadata and tail current CRT dispatch.
// R6GameService.dll @ 10069088 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedListCloneEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CloneCircularListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083ac8 : literal circular-list construction unwind map/FuncInfo.
const R6GameServiceNative::UnwindEntry CloneCircularListUnwindMap[1] = {
  {-1, R6GameServiceAddresses::CloneCircularListUnwind1},
};

// R6GameService.dll data @ 10083ad0 : literal circular-list construction unwind map/FuncInfo.
// R6GameService.dll data @ 10083ac8 : native storage identity retained.
const R6GameServiceNative::FuncInfo CloneCircularListExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::CloneCircularListUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Release nodes and current sentinel at object+88, retaining borrowed payloads and the dangling owner slot.
// Cache each next node across free; reload current head separately for comparisons, resets and final free.
// R6GameService.dll @ 10054b00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseEmbeddedList88(int objectAddress)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x88]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch16
  Branch15:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi+0x88]
    jne    Branch15
  Branch16:
    mov    eax,DWORD PTR [edi+0x88]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi+0x88]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi+0x88]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    ret
  }
}

// Load the referenced address and add eight modulo32; no NULL check.
// R6GameService.dll @ 10054bf0 : complete native control/access order and raw ABI retained.
uint __fastcall GetReferencedStoragePlus8(const uint *slot)
{
  return *slot + 8;
}

// Load the referenced address and add sixteen modulo32; no NULL check.
// R6GameService.dll @ 10054c00 : complete native control/access order and raw ABI retained.
uint __fastcall GetReferencedStoragePlus10(const uint *slot)
{
  return *slot + 0x10;
}

// Tail-forward the indexed tree receiver to its full destructor.
// R6GameService.dll @ 10052ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_ReleaseIndexedTree(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::ReleaseIndexedTree
  }
}

// Destroy right subtrees first, then current record list/node, iterating left; nonzero count gates the traversal.
// Separate current-head resets precede count0; always free CURRENT header, leaving the owner slot dangling.
// ENTRY ESP S: saved treeS-10/stateS-4. State0 retries current header only; no node retry/count normalization.
// R6GameService.dll @ 10053000 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseIndexedTree(void *tree)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectIndexedTreeDestroyEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch19
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch18
    push   ebx
  Branch17:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseIndexedSubtree
    mov    ebx,DWORD PTR [esi+0x8]
    push   0x0
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::DestroyEmbeddedListAndMaybeNode
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch17
    pop    ebx
  Branch18:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch19:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Free CURRENT first word of CURRENT saved tree slot from inherited original ENTRY ESP.
// R6GameService.dll @ 10068d70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseIndexedTreeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the indexed-tree destructor one-state map and tail current CRT dispatch.
// R6GameService.dll @ 10068d78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedTreeDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReleaseIndexedTreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 100837d0: exact lifetime unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry ReleaseIndexedTreeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseIndexedTreeUnwind1},
};

// R6GameService.dll data @ 100837d8: exact lifetime unwind map or FuncInfo.
// R6GameService.dll data @ 100837d0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReleaseIndexedTreeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ReleaseIndexedTreeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Run four cleanup passes, drain CURRENT record tree20/head, then lists18 and10 with exact six-state lifetimes.
// Entry S: ownerS-14/currentmemberS-10/stateS-4; preserve entered head/no-op cleanup and raw final free EAX.
// R6GameService.dll @ 1004fef0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyIndexedRecordCollectionState(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectNestedOwnerDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    esi
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x8],edi
    mov    DWORD PTR [esp+0x18],0x2
    call    R6GameServiceAddresses::ClearNestedRecordsAndLists
    lea    esi,[edi+0x20]
    mov    DWORD PTR [esp+0xc],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [esp+0x18],0x3
    test    eax,eax
    je    Branch20
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseOuterRecordNodes
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch20:
    mov    ecx,esi
    mov    BYTE PTR [esp+0x18],0x1
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    esi,[edi+0x18]
    mov    DWORD PTR [esp+0xc],esi
    mov    ecx,esi
    mov    BYTE PTR [esp+0x18],0x4
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    esi,DWORD PTR [esi]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    edi,0x10
    mov    DWORD PTR [esp+0xc],edi
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x18],0x5
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch22
  Branch21:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push    0x1
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    esi,DWORD PTR [edi]
    jne    Branch21
  Branch22:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Call reset-state pass, keyed outer removal, queue10 clear, then tail queue18 clear; ignore intermediate results.
// Preserve captured owner/ordered calls and full raw final tail result; no own guard.
// R6GameService.dll @ 100517a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearNestedRecordsAndLists(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::ResetStateTwoForAllOuterRecords
    mov    ecx,esi
    call    R6GameServiceAddresses::ClearOuterRecordCollection
    mov    ecx,esi
    call    R6GameServiceAddresses::ClearQueuedRecords10
    mov    ecx,esi
    pop    esi
    jmp    R6GameServiceAddresses::ClearQueuedRecords18
  }
}

// Tail exact nested-record tree destruction with unchanged receiver/stack/raw result.
// R6GameService.dll @ 1004ffd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyNestedRecordTree(void *tree)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyNestedRecordTree
  }
}

// Drain CURRENT nonempty record tree, releasing embedded record+90 trees, then reset head/count and free head.
// Shared one-state guard frees CURRENT saved head only after interruption; no record/node cleanup retry.
// R6GameService.dll @ 1004ffe0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyNestedRecordTree(void *tree)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTreeDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch25
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch24
    push    ebx
  Branch23:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseOuterRecordNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x0
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::DestroyOuterRecordAndMaybeFree
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch23
    pop    ebx
  Branch24:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch25:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy record tree at+90, not a list: recurse right/free/iterate left, reset CURRENT head/count, free head.
// Preserve shared head-only guard/current context and raw final free EAX; no owner allocation free.
// R6GameService.dll @ 10050560 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyRecordTreeAtOffset90(void *record)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTreeDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    lea    edi,[ecx+0x90]
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch28
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch27
    push    ebx
  Branch26:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x1
    push    esi
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch26
    pop    ebx
  Branch27:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch28:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy record+90 tree, read CURRENT low delete flag bit0, optionally CDECL-free it, return original record. RET4.
// R6GameService.dll @ 10052020 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyOuterRecordAndMaybeFree(void *record,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyRecordTreeAtOffset90
    test    BYTE PTR [esp+0x8],0x1
    je    Branch29
    push    esi
    call    R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch29:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Recurse right+c, cache left8 BEFORE embedded record+90 destruction, free node, then follow cached left. RET4.
// Retain inherited ECX forwarding and raw last result; no parent guard or value-tree retry.
// R6GameService.dll @ 10051aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseOuterRecordNodes(void *tree,int nodeAddress)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    ebx,ecx
    test    esi,esi
    je    Branch31
    push    edi
  Branch30:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push    eax
    call    R6GameServiceAddresses::ReleaseOuterRecordNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::DestroyRecordTreeAtOffset90
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    edi,edi
    mov    esi,edi
    jne    Branch30
    pop    edi
  Branch31:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Clear queue+18: delete payload record+4 target if nonNULL, reload/free payload, then read/unlink/free node.
// Reload CURRENT head for termination; retain next/current links, raw return and partial effects. No own guard.
// R6GameService.dll @ 10051410 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearQueuedRecords18(void *owner)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    esi
    mov    eax,DWORD PTR [ebx+0x18]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch34
    push    edi
  Branch32:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x4]
    test    ecx,ecx
    je    Branch33
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch33:
    mov    eax,DWORD PTR [esi+0x8]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push    esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0x18]
    mov    esi,edi
    cmp    edi,eax
    jne    Branch32
    pop    edi
  Branch34:
    pop    esi
    pop    ebx
    ret
  }
}

// Clear queue+10: delete payload record+4 target if nonNULL, reload/free payload, then read/unlink/free node.
// Reload CURRENT head for termination; retain next/current links, raw return and partial effects. No own guard.
// R6GameService.dll @ 10051460 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearQueuedRecords10(void *owner)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    esi
    mov    eax,DWORD PTR [ebx+0x10]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch37
    push    edi
  Branch35:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x4]
    test    ecx,ecx
    je    Branch36
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch36:
    mov    eax,DWORD PTR [esi+0x8]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push    esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0x10]
    mov    esi,edi
    cmp    edi,eax
    jne    Branch35
    pop    edi
  Branch37:
    pop    esi
    pop    ebx
    ret
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689cb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689d6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::thunk_DestroyNestedRecordTree
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689e1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689e9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy exact remaining owner member or CURRENT entered head/no-op context; no stronger retry.
// R6GameService.dll @ 100689f1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyIndexedRecordCollectionStateUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release CURRENT saved tree first word; shared record-tree guard does not retry nodes.
// R6GameService.dll @ 10068c30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl indexed_record_supportSharedLifetimeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact destruction FuncInfo and tail CRT dispatch; keep shared selector canonical once.
// R6GameService.dll @ 100689f9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectNestedOwnerDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyIndexedRecordCollectionStateExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact destruction FuncInfo and tail CRT dispatch; keep shared selector canonical once.
// R6GameService.dll @ 10068c38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRecordTreeDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::indexed_record_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destruction map/FuncInfo; entered list no-ops and tree head-only actions retain native gaps.
// R6GameService.dll data @ 10083364 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyIndexedRecordCollectionStateUnwindMap[6] = {
  {-1, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind1},
  {0x0, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind2},
  {0x1, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind3},
  {0x1, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind4},
  {0x0, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind5},
  {-1, R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwind6},
};

// Literal destruction map/FuncInfo; entered list no-ops and tree head-only actions retain native gaps.
// R6GameService.dll data @ 10083394 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyIndexedRecordCollectionStateExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::DestroyIndexedRecordCollectionStateUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal destruction map/FuncInfo; entered list no-ops and tree head-only actions retain native gaps.
// R6GameService.dll data @ 100836e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry indexed_record_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::indexed_record_supportSharedLifetimeUnwind1},
};

// Literal destruction map/FuncInfo; entered list no-ops and tree head-only actions retain native gaps.
// R6GameService.dll data @ 100836ec : native storage identity retained.
const R6GameServiceNative::FuncInfo indexed_record_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::indexed_record_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

uint __thiscall ValidateParserSelectorAndOptionalWord(
    void *owner,uint expectedSelector,char *markerOut,void *wordOut);
uint __thiscall RefreshSelector66Values(void *owner,char *markerOut,void *wordOut);
uint __thiscall RefreshSelector4dValues(void *owner,char *markerOut,void *wordOut);
uint __thiscall RefreshSelector01Values(void *owner,char *markerOut,void *wordOut);
uint __thiscall RefreshSelector62Values(void *owner,char *markerOut,void *wordOut);
uint __thiscall ParseSelector5aOwnedBytes(void *owner,char *textOut,void **bufferOut,uint *countOut);
uint __thiscall ParseSelector5bFields(void *owner,char *delimiterOut,uint *fourBytesOut,char *textOut);
uint __thiscall DispatchParsedOwnedBuffer(void *owner);
uint __thiscall DispatchParsedSlot28(void *owner);
uint __thiscall ParseSelector65Strings(void *owner,char *firstOut,char *secondOut,char *thirdOut);
uint __thiscall ParseSelector58Fields(void *owner,char *delimiterOut,uint *fourBytesOut,char *textOut);
uint __thiscall ReplaceRecordBySelector(void *owner,uint selector);
uint __stdcall CopyTerminatedBytesForward(char *destination,const char *source);
uint __thiscall ReadTransportSelectorRecord(void *owner,uint selector,byte *delimiterOut,void *fourBytesOut);
uint __thiscall ParseSelector4e(void *owner,byte *delimiterOut,void *fourBytesOut);
uint __thiscall ParseSelector4bText(void *owner,byte *delimiterOut,void *fourBytesOut,char *textOut);
uint __thiscall ParseSelector4cText(void *owner,byte *delimiterOut,void *fourBytesOut,char *textOut);

// Connects the selected proxy and sends the two supplied text fields (RET 8).
uint __thiscall ConnectAndSendProxyRequest(void *owner,const char *text0,const char *text1);

// Append string and formatted 32-bit values to the ECX descriptor (RET 4).
uint __thiscall AppendClDataListString(void *destination,const char *text);
uint __thiscall AppendClDataListSignedDecimal(void *destination,const void *value);
uint __thiscall QueueMissingNestedRecordRequest(
    void *owner,const byte *text,uint word0,uint word1);
uint __thiscall ReleaseOuterRecordNodes(void *receiver,int nodeAddress);
void * __stdcall AllocateTreeNodeWithCopiedPayload(const undefined2 *sourceKeyAndPayload);
undefined1 * __thiscall CloneOrderedTreeSubtree(
    void *destinationTree,undefined1 *sourceRoot,undefined4 parentNode);
int * __fastcall InitializeTreeOwnerStorage(int *ownerWords);
uint __fastcall ClearTreeOwnerStorage(int *ownerWords);
void * __thiscall CopyRecordStateAndNestedTree(void *destination,undefined4 *source);
int * __thiscall FindOrderedTreeNodeByU16Key(
    void *treeOwner,int *outputNode,ushort *key);
uint __fastcall WaitForTransportReady(void *provider);
void * __thiscall InitializeDerivedTransportRecordWithText(
    void *owner,const char *text,uint word74,uint contextWord,uint loggerWord,uint word94,uint initializeBaseWord);

// Scan captured outer/inner headers in key order; compare full NUL byte strings at+12, then WORD36/38.
// Reload query pointer per candidate; first match zero-extends outer key. Miss clears AX only. RETc/no own guard.
// R6GameService.dll @ 10050070 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FindOuterRecordWordByNestedTextPair(
    void *owner,const byte *text,uint word0,uint word1)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [ecx+0x20]
    push    ebx
    push    ebp
    push    esi
    mov    ebp,DWORD PTR [edx+0x8]
    push    edi
    cmp    ebp,edx
    mov    DWORD PTR [esp+0x10],edx
    je    Branch56
  Branch38:
    mov    ebx,DWORD PTR [ebp+0xa0]
    mov    edi,DWORD PTR [ebx+0x8]
    cmp    edi,ebx
    je    Branch50
  Branch39:
    mov    esi,DWORD PTR [esp+0x18]
    lea    ecx,[edi+0x12]
  Branch40:
    mov    dl,BYTE PTR [ecx]
    mov    al,dl
    cmp    dl,BYTE PTR [esi]
    jne    Branch42
    test    al,al
    je    Branch41
    mov    al,BYTE PTR [ecx+0x1]
    mov    dl,al
    cmp    al,BYTE PTR [esi+0x1]
    jne    Branch42
    add    ecx,0x2
    add    esi,0x2
    test    dl,dl
    jne    Branch40
  Branch41:
    xor    eax,eax
    jmp    Branch43
  Branch42:
    sbb    eax,eax
    sbb    eax,0xffffffff
  Branch43:
    test    eax,eax
    jne    Branch44
    mov    cx,WORD PTR [esp+0x1c]
    cmp    WORD PTR [edi+0x36],cx
    jne    Branch44
    mov    dx,WORD PTR [esp+0x20]
    cmp    WORD PTR [edi+0x38],dx
    je    Branch57
  Branch44:
    mov    ecx,DWORD PTR [edi+0xc]
    mov    eax,edi
    test    ecx,ecx
    je    Branch46
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch49
  Branch45:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch45
    jmp    Branch49
  Branch46:
    mov    ecx,DWORD PTR [edi+0x4]
    cmp    edi,DWORD PTR [ecx+0xc]
    jne    Branch48
  Branch47:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch47
  Branch48:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch49
    mov    eax,ecx
  Branch49:
    cmp    eax,ebx
    mov    edi,eax
    jne    Branch39
    mov    edx,DWORD PTR [esp+0x10]
  Branch50:
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    eax,ebp
    test    ecx,ecx
    je    Branch52
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch55
  Branch51:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch51
    jmp    Branch55
  Branch52:
    mov    ecx,DWORD PTR [ebp+0x4]
    cmp    ebp,DWORD PTR [ecx+0xc]
    jne    Branch54
  Branch53:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch53
  Branch54:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch55
    mov    eax,ecx
  Branch55:
    cmp    eax,edx
    mov    ebp,eax
    jne    Branch38
  Branch56:
    pop    edi
    pop    esi
    pop    ebp
    xor    ax,ax
    pop    ebx
    pop    ecx
    ret    0xc
  Branch57:
    mov    ax,WORD PTR [ebp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Lookup outer lowU16 key, capture inner header/query pointer, then scan full NUL strings and late WORD36/38.
// AX is logical key/zero; raw uint view retains outer-node, current-inner-node or head upper16. RET10/no own guard.
// R6GameService.dll @ 10050190 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall FindNestedRecordWordByTextPair(
    void *owner,uint outerKeyWord,const byte *text,uint word0,uint word1)
{
  __asm {
    push    ebx
    push    ebp
    push    esi
    lea    esi,[ecx+0x20]
    lea    eax,[esp+0x10]
    push    edi
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    cmp    eax,DWORD PTR [esi]
    je    Branch69
    mov    ebp,DWORD PTR [eax+0xa0]
    mov    edi,DWORD PTR [ebp+0x8]
    cmp    edi,ebp
    je    Branch69
    mov    ebx,DWORD PTR [esp+0x18]
  Branch58:
    mov    esi,ebx
    lea    ecx,[edi+0x12]
  Branch59:
    mov    al,BYTE PTR [ecx]
    mov    dl,al
    cmp    al,BYTE PTR [esi]
    jne    Branch61
    test    dl,dl
    je    Branch60
    mov    al,BYTE PTR [ecx+0x1]
    mov    dl,al
    cmp    al,BYTE PTR [esi+0x1]
    jne    Branch61
    add    ecx,0x2
    add    esi,0x2
    test    dl,dl
    jne    Branch59
  Branch60:
    xor    ecx,ecx
    jmp    Branch62
  Branch61:
    sbb    ecx,ecx
    sbb    ecx,0xffffffff
  Branch62:
    test    ecx,ecx
    jne    Branch63
    mov    cx,WORD PTR [esp+0x1c]
    cmp    WORD PTR [edi+0x36],cx
    jne    Branch63
    mov    dx,WORD PTR [esp+0x20]
    cmp    WORD PTR [edi+0x38],dx
    je    Branch70
  Branch63:
    mov    ecx,DWORD PTR [edi+0xc]
    mov    eax,edi
    test    ecx,ecx
    je    Branch65
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch68
  Branch64:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch64
    jmp    Branch68
  Branch65:
    mov    ecx,DWORD PTR [edi+0x4]
    cmp    edi,DWORD PTR [ecx+0xc]
    jne    Branch67
  Branch66:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch66
  Branch67:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch68
    mov    eax,ecx
  Branch68:
    cmp    eax,ebp
    mov    edi,eax
    jne    Branch58
  Branch69:
    pop    edi
    pop    esi
    pop    ebp
    xor    ax,ax
    pop    ebx
    ret    0x10
  Branch70:
    mov    ax,WORD PTR [edi+0x10]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x10
  }
}

// Ensure lowU16 outer key, constructing two temporary record/tree views and a152-byte proxy on a miss.
// Capture lookup head/text/value at native times; copy128 text bytes, preserve gaps and five-state cleanup.
// Final result sets AL1 only; raw allocation/proxy and entered cleanup gaps remain. RETc; original record type unresolved.
// R6GameService.dll @ 10050260 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EnsureOuterRecordExists(
    void *owner,uint keyWord,const char *text,uint valueWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOuterRecordCreationEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x154
    push    ebx
    push    ebp
    push    esi
    xor    ebx,ebx
    lea    esi,[ecx+0x20]
    lea    eax,[esp+0x170]
    push    edi
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x10],ebx
    mov    edi,DWORD PTR [esi]
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    cmp    eax,edi
    jne    Branch77
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x10],ebx
    mov    eax,DWORD PTR [ecx+0x8]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    je    Branch72
  Branch71:
    mov    cx,WORD PTR [eax+0x10]
    cmp    cx,WORD PTR [esp+0x174]
    ja    Branch72
    push    eax
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ecx,DWORD PTR [esi]
    add    esp,0x4
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    jne    Branch71
  Branch72:
    lea    ecx,[esp+0xac]
    mov    DWORD PTR [esp+0xb8],0x10077f84
    call    R6GameServiceAddresses::InitializeTreeOwnerStorage
    mov    edi,DWORD PTR [esp+0x178]
    push    0x80
    lea    edx,[esp+0x24]
    push    edi
    push    edx
    mov    DWORD PTR [esp+0x178],ebx
    call    R6GameServiceAddresses::strncpy
    mov    ebp,DWORD PTR [esp+0x188]
    add    esp,0xc
    mov    WORD PTR [esp+0xa2],bp
    mov    BYTE PTR [esp+0xa4],bl
    push    0x98
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x18],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x16c],0x1
    je    Branch73
    mov    ecx,DWORD PTR [esp+0x174]
    mov    edx,DWORD PTR [esp+0x14]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0xc]
    push    ebx
    push    ecx
    push    ebp
    push    edi
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeDerivedTransportRecordWithText
    jmp    Branch74
  Branch73:
    xor    eax,eax
  Branch74:
    mov    DWORD PTR [esp+0xa8],eax
    mov    eax,DWORD PTR [esp+0xb0]
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x16c],bl
    je    Branch75
    mov    edx,DWORD PTR [esp+0xac]
    lea    ecx,[esp+0xac]
    mov    eax,DWORD PTR [edx+0x4]
    push    eax
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    eax,DWORD PTR [esp+0xac]
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esp+0xac]
    mov    DWORD PTR [ecx+0x4],ebx
    mov    eax,DWORD PTR [esp+0xac]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esp+0xb0],ebx
  Branch75:
    mov    dx,WORD PTR [esp+0x174]
    lea    eax,[esp+0x20]
    push    eax
    lea    ecx,[esp+0xc8]
    mov    WORD PTR [esp+0xc4],dx
    call    R6GameServiceAddresses::CopyRecordStateAndNestedTree
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x16c],0x2
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyFirstWord
    lea    edx,[esp+0xc0]
    lea    eax,[esp+0x18]
    push    edx
    push    ecx
    mov    ecx,esp
    push    eax
    call    R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x24]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::InsertOrFindOrderedTreeNodeByU16Key
    lea    edx,[esp+0x150]
    mov    DWORD PTR [esp+0x14],edx
    lea    ecx,[esp+0x150]
    mov    BYTE PTR [esp+0x16c],0x3
    call    R6GameServiceAddresses::ClearTreeOwnerStorage
    lea    ecx,[esp+0x150]
    mov    BYTE PTR [esp+0x16c],bl
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    eax,[esp+0xac]
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esp+0xb0]
    mov    DWORD PTR [esp+0x16c],0x4
    cmp    eax,ebx
    je    Branch76
    mov    ecx,DWORD PTR [esp+0xac]
    mov    edx,DWORD PTR [ecx+0x4]
    lea    ecx,[esp+0xac]
    push    edx
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    eax,DWORD PTR [esp+0xac]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esp+0xac]
    mov    DWORD PTR [eax+0x4],ebx
    mov    eax,DWORD PTR [esp+0xac]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esp+0xb0],ebx
  Branch76:
    lea    ecx,[esp+0xac]
    mov    DWORD PTR [esp+0x16c],0xffffffff
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
  Branch77:
    mov    ecx,DWORD PTR [esp+0x164]
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x160
    ret    0xc
  }
}

// Destroy tree8c, not a list: nonzero count90 drains nodes, resets CURRENT head/count, then always frees head.
// Count0 skips live nodes; shared entered guard frees CURRENT head only, without retry. Raw final allocator EAX.
// R6GameService.dll @ 100504d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyRecordTreeAtOffset8c(void *record)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTreeDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    lea    edi,[ecx+0x8c]
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch80
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch79
    push    ebx
  Branch78:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x1
    push    esi
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch78
    pop    ebx
  Branch79:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch80:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Lookup lowU16 key; release callback, then CURRENT inner tree if count nonzero, unlink and destroy returned node.
// Clear callback AFTER virtual call; reload outer count AFTER free/decrement. AL0 on miss, AL1 on success. RET4.
// R6GameService.dll @ 100505f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DeleteOuterRecordByKey(void *owner,uint keyWord)
{
  __asm {
    push    ecx
    push    ebx
    lea    ebx,[ecx+0x20]
    lea    eax,[esp+0xc]
    push    ebp
    push    eax
    mov    ecx,ebx
    mov    DWORD PTR [esp+0xc],ebx
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    mov    ebp,eax
    mov    eax,DWORD PTR [ebx]
    cmp    ebp,eax
    jne    Branch81
    pop    ebp
    xor    al,al
    pop    ebx
    pop    ecx
    ret    0x4
  Branch81:
    mov    ecx,DWORD PTR [ebp+0x9c]
    test    ecx,ecx
    je    Branch82
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
    mov    DWORD PTR [ebp+0x9c],0x0
  Branch82:
    mov    eax,DWORD PTR [ebp+0xa4]
    push    esi
    push    edi
    lea    edi,[ebp+0xa0]
    test    eax,eax
    je    Branch85
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch84
  Branch83:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x1
    push    esi
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch83
    mov    ebx,DWORD PTR [esp+0x10]
  Branch84:
    mov    eax,DWORD PTR [edi]
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],ecx
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],ecx
  Branch85:
    mov    eax,DWORD PTR [ebx]
    lea    ecx,[eax+0xc]
    lea    edx,[eax+0x8]
    push    ecx
    add    eax,0x4
    push    edx
    push    eax
    push    ebp
    call    R6GameServiceAddresses::RemoveOrderedTreeNode
    mov    esi,eax
    add    esp,0x10
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::DestroyRecordTreeAtOffset90
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0x4]
    pop    edi
    dec    eax
    pop    esi
    mov    DWORD PTR [ebx+0x4],eax
    pop    ebp
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Cache successor BEFORE keyed deletion; preserve full raw key lanes and ignore per-record status.
// CURRENT nonzero count triggers residual record-tree cleanup/reset; AL1 retains final count/head upper EAX.
// R6GameService.dll @ 100506c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearOuterRecordCollection(void *owner)
{
  __asm {
    push    ebx
    push    esi
    push    edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x20]
    lea    ebx,[edi+0x20]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je    Branch92
  Branch86:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,esi
    test    eax,eax
    je    Branch88
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch91
  Branch87:
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch87
    jmp    Branch91
  Branch88:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch90
  Branch89:
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    je    Branch89
  Branch90:
    cmp    DWORD PTR [esi+0xc],eax
    je    Branch91
    mov    esi,eax
  Branch91:
    mov    ax,WORD PTR [ecx+0x10]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::DeleteOuterRecordByKey
    cmp    esi,DWORD PTR [ebx]
    jne    Branch86
  Branch92:
    mov    eax,DWORD PTR [ebx+0x4]
    test    eax,eax
    je    Branch95
    mov    ecx,DWORD PTR [ebx]
    mov    esi,DWORD PTR [ecx+0x4]
    test    esi,esi
    je    Branch94
  Branch93:
    mov    edx,DWORD PTR [esi+0xc]
    mov    ecx,ebx
    push    edx
    call    R6GameServiceAddresses::ReleaseOuterRecordNodes
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::DestroyRecordTreeAtOffset90
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    edi,edi
    mov    esi,edi
    jne    Branch93
  Branch94:
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [eax+0x4],0x0
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [ebx+0x4],0x0
  Branch95:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret
  }
}

// Require outer key and zero AX text-pair lookup, then increment owner WORD4 before copying/allocating.
// Copy32 text bytes; preserve stack gaps, 42-byte payload copy, generated-key collisions and AL-only status.
// Native insert paths reuse caller text/word1 slots; no own EH or rollback. RET14; original record type unresolved.
// R6GameService.dll @ 10050770 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AddNestedRecordForZeroLookup(
    void *owner,uint outerKeyWord,const byte *text,uint unusedWord,uint word0,uint word1)
{
  __asm {
    sub    esp,0x60
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    lea    eax,[esp+0x70]
    lea    edi,[esi+0x20]
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [esp+0xc],eax
    cmp    eax,ecx
    jne    Branch96
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    add    esp,0x60
    ret    0x14
  Branch96:
    mov    edi,DWORD PTR [esp+0x80]
    mov    ebp,DWORD PTR [esp+0x7c]
    mov    ecx,DWORD PTR [esp+0x74]
    mov    edx,DWORD PTR [esp+0x70]
    push    edi
    push    ebp
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FindNestedRecordWordByTextPair
    test    ax,ax
    je    Branch97
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    add    esp,0x60
    ret    0x14
  Branch97:
    mov    eax,DWORD PTR [esp+0x74]
    inc    WORD PTR [esi+0x4]
    push    ebx
    mov    bx,WORD PTR [esi+0x4]
    push    0x20
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    call    R6GameServiceAddresses::strncpy
    mov    WORD PTR [esp+0x4a],di
    mov    ecx,0xa
    lea    esi,[esp+0x24]
    lea    edi,[esp+0x52]
    mov    WORD PTR [esp+0x48],bp
    mov    BYTE PTR [esp+0x4c],0x0
    mov    WORD PTR [esp+0x50],bx
    mov    edx,DWORD PTR [esp+0x1c]
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    lea    ebp,[edx+0xa0]
    add    esp,0xc
    movs    WORD PTR es:[edi],WORD PTR ds:[esi]
    mov    edx,DWORD PTR [ebp+0x0]
    mov    cl,0x1
    mov    edi,edx
    mov    esi,DWORD PTR [edx+0x4]
    test    esi,esi
    je    Branch101
  Branch98:
    cmp    bx,WORD PTR [esi+0x10]
    mov    edi,esi
    setb    cl
    test    cl,cl
    je    Branch99
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch100
  Branch99:
    mov    esi,DWORD PTR [esi+0xc]
  Branch100:
    test    esi,esi
    jne    Branch98
  Branch101:
    mov    eax,edi
    test    cl,cl
    mov    DWORD PTR [esp+0x84],eax
    je    Branch106
    cmp    edi,DWORD PTR [edx+0x8]
    jne    Branch105
    cmp    edi,edx
    je    Branch102
    test    esi,esi
    jne    Branch102
    cmp    bx,WORD PTR [edi+0x10]
    jb    Branch102
    lea    eax,[esp+0x44]
    mov    ecx,ebp
    push    eax
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    edi,DWORD PTR [ecx+0xc]
    jne    Branch104
    mov    DWORD PTR [ecx+0xc],eax
    jmp    Branch104
  Branch102:
    lea    ecx,[esp+0x44]
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::AllocateTreeNodeWithCopiedPayload
    mov    DWORD PTR [edi+0x8],eax
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    edi,ecx
    jne    Branch103
    mov    DWORD PTR [ecx+0x4],eax
    mov    edx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [edx+0xc],eax
    jmp    Branch104
  Branch103:
    cmp    edi,DWORD PTR [ecx+0x8]
    jne    Branch104
    mov    DWORD PTR [ecx+0x8],eax
  Branch104:
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x4],edi
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,0x4
    push    ecx
    push    eax
    call    R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    pop    ebx
    pop    edi
    mov    DWORD PTR [ebp+0x4],eax
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x60
    ret    0x14
  Branch105:
    push    edi
    call    R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x84],eax
  Branch106:
    mov    dx,WORD PTR [eax+0x10]
    cmp    dx,WORD PTR [esp+0x44]
    jae    Branch107
    lea    eax,[esp+0x44]
    push    0x0
    push    eax
    push    edi
    lea    ecx,[esp+0x84]
    push    esi
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::InsertTreeNodeAndRebalance
    pop    ebx
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x60
    ret    0x14
  Branch107:
    lea    edx,[esp+0x78]
    lea    eax,[esp+0x84]
    push    edx
    push    eax
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x80],0x0
    call    R6GameServiceAddresses::ConstructWordBytePair
    pop    ebx
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    add    esp,0x60
    ret    0x14
  }
}

// Resolve lowWORD outer/inner keys against CURRENT headers; set nested flagBYTE3a to1 only when both found.
// Return pointer upper24 with AL-only success/failure, without touching counts or payload fields. RET8/no own EH.
// R6GameService.dll @ 10050950 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall MarkNestedRecordFlag(void *owner,uint outerKeyWord,uint innerKeyWord)
{
  __asm {
    push    esi
    lea    esi,[ecx+0x20]
    lea    eax,[esp+0x8]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    cmp    eax,DWORD PTR [esi]
    jne    Branch108
    xor    al,al
    pop    esi
    ret    0x8
  Branch108:
    lea    ecx,[esp+0xc]
    lea    esi,[eax+0xa0]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    cmp    eax,DWORD PTR [esi]
    jne    Branch109
    xor    al,al
    pop    esi
    ret    0x8
  Branch109:
    mov    BYTE PTR [eax+0x3a],0x1
    mov    al,0x1
    pop    esi
    ret    0x8
  }
}

// Remove every nested node; queue c9/text/zero-extended WORD36/38 under cc only for current flagBYTE1/node3a!=0.
// S: recordS-48/ownerS-44/scratchS-40/descriptorsS-3c/-24/stateS-4. Six-state cleanup retains entered gaps.
// Compute successor after descriptor cleanup, unlink CURRENT tree, free, then decrement count; AL-only status. RET8.
// R6GameService.dll @ 10050990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveNestedRecordsByOuterKey(void *owner,uint keyWord,uint queueFlagWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectNestedNotificationEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x40
    push    esi
    push    edi
    mov    edi,ecx
    lea    eax,[esp+0x58]
    push    eax
    mov    DWORD PTR [esp+0x14],edi
    lea    esi,[edi+0x20]
    mov    DWORD PTR [esp+0xc],0x0
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0xc],eax
    cmp    eax,ecx
    jne    Branch110
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x4c
    ret    0x8
  Branch110:
    mov    eax,DWORD PTR [eax+0xa0]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je    Branch114
    push    ebx
    push    ebp
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    jmp    Branch112
  Branch111:
    mov    edi,DWORD PTR [esp+0x18]
  Branch112:
    cmp    BYTE PTR [esp+0x64],0x1
    jne    Branch113
    mov    al,BYTE PTR [esi+0x3a]
    test    al,al
    je    Branch113
    mov    ecx,DWORD PTR [esp+0x10]
    push    0x0
    or    ecx,0x1
    push    0x3
    mov    DWORD PTR [esp+0x18],ecx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x5c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x2c],ebp
    mov    eax,DWORD PTR [esp+0x10]
    push    0x0
    or    al,0x2
    push    0x3
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x60],0x1
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x54],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],eax
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x5c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x44],ebp
    lea    ecx,[esi+0x12]
    mov    BYTE PTR [esp+0x58],0x3
    push    ecx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::AppendClDataListString
    xor    edx,edx
    lea    eax,[esp+0x1c]
    mov    dx,WORD PTR [esi+0x36]
    push    eax
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x20],edx
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    xor    ecx,ecx
    lea    edx,[esp+0x1c]
    mov    cx,WORD PTR [esi+0x38]
    push    edx
    mov    DWORD PTR [esp+0x20],ecx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x1c]
    lea    ecx,[esp+0x38]
    push    eax
    mov    DWORD PTR [esp+0x20],0xc9
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x20]
    push    ecx
    lea    ecx,[esp+0x3c]
    call    R6GameServiceAddresses::AppendClDataListCopy
    mov    eax,DWORD PTR [esp+0x60]
    lea    edx,[esp+0x38]
    push    edx
    push    0xcc
    push    eax
    push    0x2
    mov    ecx,edi
    call    R6GameServiceAddresses::AppendQueuedRecord
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x44],ebp
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x58],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    edi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x38],edi
    mov    DWORD PTR [esp+0x2c],ebp
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x58],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x58],0xffffffff
    mov    DWORD PTR [esp+0x20],edi
  Branch113:
    push    esi
    mov    DWORD PTR [esp+0x20],esi
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    add    esp,0x4
    lea    ecx,[esp+0x14]
    mov    esi,eax
    call    R6GameServiceAddresses::GetReferencedStoragePlus10
    mov    edi,eax
    mov    eax,DWORD PTR [edi+0x90]
    add    edi,0x90
    lea    ecx,[eax+0xc]
    lea    edx,[eax+0x8]
    push    ecx
    add    eax,0x4
    push    edx
    push    eax
    mov    eax,DWORD PTR [esp+0x28]
    push    eax
    call    R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [edi+0x4]
    dec    ecx
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    cmp    esi,DWORD PTR [ecx+0xa0]
    jne    Branch111
    pop    ebp
    pop    ebx
  Branch114:
    mov    ecx,DWORD PTR [esp+0x48]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x4c
    ret    0x8
  }
}

// Resolve first matching outer key; state0 sends cc/1/[2,[key]], then publish state1 before descriptor cleanup.
// Reload text/WORD args, store selected inner key at+b0 and mark it; CURRENT state2 queues cc/[26,[4d,[key]]].
// Preserve ten-state descriptor cleanup, partial effects and raw AL-only result. RETc; record types unresolved.
// R6GameService.dll @ 10050be0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ApplyNestedRecordUpdateByTextPair(
    void *owner,const byte *text,uint word0,uint word1)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTextUpdateEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x80
    push    ebx
    mov    ebx,DWORD PTR [esp+0x98]
    push    ebp
    mov    ebp,DWORD PTR [esp+0x98]
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0xa8]
    mov    esi,ecx
    push    edi
    push    ebx
    push    ebp
    mov    DWORD PTR [esp+0x20],0x0
    call    R6GameServiceAddresses::FindOuterRecordWordByNestedTextPair
    test    ax,ax
    mov    DWORD PTR [esp+0x10],eax
    jne    Branch115
    push    edi
    push    ebx
    push    ebp
    mov    ecx,esi
    call    R6GameServiceAddresses::QueueMissingNestedRecordRequest
    xor    al,al
    jmp    Branch120
  Branch115:
    lea    ebx,[esi+0x20]
    lea    eax,[esp+0x10]
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    mov    edi,eax
    mov    eax,DWORD PTR [ebx]
    cmp    edi,eax
    jne    Branch116
    xor    al,al
    jmp    Branch120
  Branch116:
    mov    al,BYTE PTR [edi+0x98]
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    test    al,al
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    jne    Branch118
    push    0x0
    push    0x3
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x9c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],ebp
    push    0x0
    push    0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0xa0],0x1
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x9c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x24],ebp
    mov    ecx,DWORD PTR [esp+0x10]
    lea    edx,[esp+0x14]
    and    ecx,0xffff
    push    edx
    mov    DWORD PTR [esp+0x18],ecx
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x9c],0x3
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x18]
    push    eax
    mov    DWORD PTR [esp+0x18],0x2
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x30]
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::AppendClDataListCopy
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push    edx
    push    0x1
    push    0xcc
    call    R6GameServiceAddresses::SendTransportPayload
    test    al,al
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x98],0x1
    jne    Branch117
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch120
  Branch117:
    mov    BYTE PTR [edi+0x98],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
  Branch118:
    mov    eax,DWORD PTR [esp+0xa8]
    mov    ecx,DWORD PTR [esp+0xa4]
    mov    edx,DWORD PTR [esp+0xa0]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    ecx
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::FindNestedRecordWordByTextPair
    mov    WORD PTR [edi+0xb0],ax
    mov    edx,DWORD PTR [esp+0x10]
    mov    cx,ax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::MarkNestedRecordFlag
    cmp    BYTE PTR [edi+0x98],0x2
    jne    Branch119
    mov    edi,R6GameServiceAddresses::ClDataListBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x80]
    mov    DWORD PTR [esp+0x84],edi
    mov    DWORD PTR [esp+0x94],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x88]
    mov    DWORD PTR [esp+0x9c],0x4
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x78],ebx
    mov    DWORD PTR [esp+0x84],ebp
    push    0x0
    push    0x3
    lea    ecx,[esp+0x68]
    mov    DWORD PTR [esp+0xa0],0x5
    mov    DWORD PTR [esp+0x6c],edi
    mov    DWORD PTR [esp+0x7c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x70]
    mov    BYTE PTR [esp+0x9c],0x6
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x60],ebx
    mov    DWORD PTR [esp+0x6c],ebp
    push    0x0
    push    0x3
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0xa0],0x7
    mov    DWORD PTR [esp+0x54],edi
    mov    DWORD PTR [esp+0x64],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x58]
    mov    BYTE PTR [esp+0x9c],0x8
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x54],ebp
    mov    eax,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x14]
    and    eax,0xffff
    push    ecx
    lea    ecx,[esp+0x7c]
    mov    BYTE PTR [esp+0x9c],0x9
    mov    DWORD PTR [esp+0x18],eax
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x60]
    push    edx
    mov    DWORD PTR [esp+0x18],0x4d
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x78]
    lea    ecx,[esp+0x60]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x14],0x26
    push    ecx
    lea    ecx,[esp+0x4c]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x60]
    lea    ecx,[esp+0x48]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListCopy
    mov    ecx,DWORD PTR [esp+0x10]
    lea    eax,[esp+0x48]
    push    eax
    push    0xcc
    push    ecx
    push    0x2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendQueuedRecord
    mov    BYTE PTR [esp+0x98],0x7
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x60]
    mov    BYTE PTR [esp+0x98],0x5
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x78]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
  Branch119:
    mov    al,0x1
  Branch120:
    mov    ecx,DWORD PTR [esp+0x90]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x8c
    ret    0xc
  }
}

// Search captured header by cached U16 key, then compare candidate against CURRENT owner20 head.
// Miss retains current head upper24/AL0; hit forwards owner30/40 text pointers to CURRENT node9c proxy. RET4/no own EH.
// R6GameService.dll @ 10050f90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendProxyRequestForOuterRecordKey(void *owner,uint keyWord)
{
  __asm {
    push    esi
    mov    esi,DWORD PTR [ecx+0x20]
    push    edi
    mov    di,WORD PTR [esp+0xc]
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,esi
    test    eax,eax
    je    Branch124
  Branch121:
    cmp    WORD PTR [eax+0x10],di
    jb    Branch122
    mov    edx,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch123
  Branch122:
    mov    eax,DWORD PTR [eax+0xc]
  Branch123:
    test    eax,eax
    jne    Branch121
  Branch124:
    cmp    edx,esi
    je    Branch125
    cmp    di,WORD PTR [edx+0x10]
    jae    Branch126
  Branch125:
    mov    edx,esi
  Branch126:
    mov    eax,DWORD PTR [ecx+0x20]
    pop    edi
    cmp    edx,eax
    pop    esi
    jne    Branch127
    xor    al,al
    ret    0x4
  Branch127:
    lea    eax,[ecx+0x40]
    add    ecx,0x30
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [edx+0x9c]
    call    R6GameServiceAddresses::ConnectAndSendProxyRequest
    ret    0x4
  }
}

// Construct three descriptors, resolve outer key and clear state98 BEFORE processing matching list18 records.
// Remove list10 matches, accumulate response/value/27 descriptors, queue list10, then delete CURRENT list18 record/node.
// Preserve cached/reloaded key lanes, late links/count-independent scan and seven-state cleanup. Raw AL result/RET8.
// R6GameService.dll @ 10050ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResetOuterRecordAndFlushQueuedUpdates(
    void *owner,uint keyWord,uint responseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectQueuedResponseEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x50
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    mov    DWORD PTR [esp+0x14],0x0
    push    0x3
    lea    ecx,[esp+0x4c]
    mov    DWORD PTR [esp+0x50],ebp
    mov    DWORD PTR [esp+0x60],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x54]
    mov    DWORD PTR [esp+0x68],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x50],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x6c],0x1
    mov    DWORD PTR [esp+0x38],ebp
    mov    DWORD PTR [esp+0x48],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x68],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x20],ebp
    mov    DWORD PTR [esp+0x30],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x4
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x6c]
    lea    ecx,[esp+0xc]
    lea    esi,[edi+0x20]
    push    eax
    push    ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x6c],0x5
    call    R6GameServiceAddresses::FindOrderedTreeNodeByU16Key
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0xc]
    cmp    eax,esi
    jne    Branch128
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x64],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x64],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x50]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x8
  Branch128:
    mov    BYTE PTR [eax+0x98],0x0
    mov    eax,DWORD PTR [edi+0x18]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch133
    mov    eax,DWORD PTR [esp+0x6c]
  Branch129:
    mov    edx,DWORD PTR [esi+0x8]
    mov    bp,WORD PTR [edx]
    cmp    bp,ax
    jne    Branch131
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::RemoveQueuedRecordsByKey
    lea    eax,[esp+0x70]
    lea    ecx,[esp+0x14]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x10]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [edx+0x4]
    call    R6GameServiceAddresses::ReadIndexedInt32
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x44]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x14]
    push    ecx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    edx,[esp+0xc]
    lea    ecx,[esp+0x2c]
    push    edx
    mov    DWORD PTR [esp+0x10],0x27
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x44]
    lea    ecx,[esp+0x2c]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x2c]
    push    ecx
    push    0xcc
    push    ebp
    push    0x2
    mov    ecx,edi
    call    R6GameServiceAddresses::AppendQueuedRecord
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [edx+0x4]
    test    ecx,ecx
    je    Branch130
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch130:
    mov    ecx,DWORD PTR [esi+0x8]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebp,DWORD PTR [esi]
    push    esi
    mov    DWORD PTR [eax],ebp
    mov    DWORD PTR [ebp+0x4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x6c]
    mov    esi,ebp
    jmp    Branch132
  Branch131:
    mov    esi,DWORD PTR [esi]
  Branch132:
    cmp    esi,DWORD PTR [edi+0x18]
    jne    Branch129
  Branch133:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    BYTE PTR [esp+0x64],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x8
  }
}

// Queue cc/key0/mask2 payload c8/text/zero-extended WORD pair; append/queue statuses are ignored.
// Reuse caller text slot for numeric scratch and CURRENT cleanup context; seven-state guards retain entered gaps.
// Final head release remains under base-only state5; AL1/raw upper EAX. RETc; original record layout unresolved.
// R6GameService.dll @ 10051270 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueMissingNestedRecordRequest(
    void *owner,const byte *text,uint word0,uint word1)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMissingRecordRequestEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0xc],eax
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],ebx
    push    eax
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x4c],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x28],ebx
    push    0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    eax,DWORD PTR [esp+0x50]
    lea    ecx,[esp+0x10]
    push    eax
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::AppendClDataListString
    mov    ecx,DWORD PTR [esp+0x54]
    lea    edx,[esp+0x50]
    and    ecx,0xffff
    push    edx
    mov    DWORD PTR [esp+0x54],ecx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    lea    ecx,[esp+0x50]
    and    eax,0xffff
    push    ecx
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x54],eax
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x50]
    lea    ecx,[esp+0x28]
    push    edx
    mov    DWORD PTR [esp+0x54],0xc8
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x28]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x28]
    push    ecx
    push    0xcc
    push    0x0
    push    0x2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendQueuedRecord
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],ebx
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x5
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x50],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x48],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Allocate record8 and cloned descriptor24; disarm raw descriptor guard before publishing key/selector/payload.
// Bit2 appends list10, bit1 list18 using one shared record; preserve captured mask and mutable argument/head slots.
// Zero mask leaves record unqueued; return raw selector/payload residue or last node pointer. RET10.
// R6GameService.dll @ 100514b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendQueuedRecord(
    void *owner,uint listMaskWord,uint keyWord,uint selectorWord,int descriptorAddress)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordQueueAllocationEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    push    0x8
    mov    edi,ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    0x18
    mov    DWORD PTR [esp+0x10],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x1c],0x0
    je    Branch134
    mov    ecx,DWORD PTR [esp+0x30]
    push    0x1
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::CopyConstructClDataList
    jmp    Branch135
  Branch134:
    xor    eax,eax
  Branch135:
    mov    edx,DWORD PTR [esp+0xc]
    mov    cx,WORD PTR [esp+0x28]
    mov    bl,BYTE PTR [esp+0x24]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    mov    WORD PTR [edx],cx
    mov    edx,DWORD PTR [esp+0xc]
    test    bl,0x2
    mov    DWORD PTR [edx+0x4],eax
    mov    ecx,DWORD PTR [esp+0xc]
    mov    ax,WORD PTR [esp+0x2c]
    mov    WORD PTR [ecx+0x2],ax
    je    Branch136
    lea    esi,[edi+0x10]
    lea    edx,[esp+0x28]
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0xc]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch136:
    test    bl,0x1
    je    Branch137
    lea    ecx,[esp+0x2c]
    lea    esi,[edi+0x18]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0xc]
    mov    ecx,esi
    push    edx
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch137:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x10
  }
}

// Cache key lowWORD once; remove matching list10 entries, delete payload, then reload/free current record.
// Read links after record free, unlink/free node, follow cached next and compare CURRENT head. Raw last EAX/RET4.
// R6GameService.dll @ 100515b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveQueuedRecordsByKey(void *owner,uint keyWord)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    esi
    mov    eax,DWORD PTR [ebx+0x10]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch142
    push    ebp
    mov    bp,WORD PTR [esp+0x10]
    push    edi
  Branch138:
    mov    eax,DWORD PTR [esi+0x8]
    cmp    WORD PTR [eax],bp
    jne    Branch140
    mov    ecx,DWORD PTR [eax+0x4]
    test    ecx,ecx
    je    Branch139
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch139:
    mov    ecx,DWORD PTR [esi+0x8]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push    esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    esi,edi
    jmp    Branch141
  Branch140:
    mov    esi,DWORD PTR [esi]
  Branch141:
    cmp    esi,DWORD PTR [ebx+0x10]
    jne    Branch138
    pop    edi
    pop    ebp
  Branch142:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Count initial list10 range, reload current first, allocate tagged output and consume original even on outputNULL.
// SelectorBYTE replaces record-pointer lowBYTE in full kind word; disarm output guard BEFORE old payload deletion.
// Reload/free record and late links, unlink/free node; return constructor result orNULL. Preserve count scratch reads.
// R6GameService.dll @ 10051610 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall PopQueuedRecord(int receiver)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordQueueAllocationEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x7]
    lea    edx,[esp+0x8]
    mov    eax,DWORD PTR [esi+0x10]
    push    ecx
    mov    DWORD PTR [esp+0xc],eax
    push    edx
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x14],eax
    mov    al,BYTE PTR [esp+0xf]
    mov    BYTE PTR [esp+0xf],al
    lea    eax,[esp+0x14]
    push    eax
    call    R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    test    eax,eax
    je    Branch146
    mov    ecx,DWORD PTR [esi+0x10]
    push    edi
    push    0x1c
    mov    esi,DWORD PTR [ecx]
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x1c],0x0
    je    Branch143
    mov    edx,DWORD PTR [esi+0x8]
    push    0x1
    push    0x0
    mov    ecx,DWORD PTR [edx+0x4]
    mov    dl,BYTE PTR [edx+0x2]
    push    ecx
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::ConstructQueuedPayloadRecord
    mov    edi,eax
    jmp    Branch144
  Branch143:
    xor    edi,edi
  Branch144:
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    mov    ecx,DWORD PTR [eax+0x4]
    test    ecx,ecx
    je    Branch145
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch145:
    mov    eax,DWORD PTR [esi+0x8]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi]
    push    esi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [eax+0x4],ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,edi
    pop    edi
    pop    esi
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret
  Branch146:
    mov    ecx,DWORD PTR [esp+0x10]
    xor    eax,eax
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret
  }
}

// Lookup lowU16 key; return CURRENT head unless state2, then notify with CURRENT full stack key/flag1.
// Reload callback+9c, call slot8 without NULL check, clear state98 AFTER return; preserve callback EAX. RET4.
// R6GameService.dll @ 100516f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResetKeyedState2(void *owner,uint keyWord)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    push    esi
    push    edi
    lea    edi,[ebx+0x20]
    lea    eax,[esp+0x10]
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::ordered_tree_support_FindOrderedTreeNodeByU16Key
    mov    esi,eax
    mov    eax,DWORD PTR [edi]
    cmp    esi,eax
    je    Branch147
    cmp    BYTE PTR [esi+0x98],0x2
    jne    Branch147
    mov    ecx,DWORD PTR [esp+0x10]
    push    0x1
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::RemoveNestedRecordsByOuterKey
    mov    ecx,DWORD PTR [esi+0x9c]
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x8]
    mov    BYTE PTR [esi+0x98],0x0
  Branch147:
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Reset each outer record in unsigned key order; compute successor AFTER callback effects.
// MOV AX preserves raw key upper lanes from head/previous successor; compare CURRENT header, return raw last EAX.
// R6GameService.dll @ 10051740 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetStateTwoForAllOuterRecords(void *owner)
{
  __asm {
    push    esi
    push    edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x20]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je    Branch154
  Branch148:
    mov    ax,WORD PTR [esi+0x10]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::ResetKeyedState2
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    test    ecx,ecx
    je    Branch150
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch153
  Branch149:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch149
    jmp    Branch153
  Branch150:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch152
  Branch151:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch151
  Branch152:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch153
    mov    eax,ecx
  Branch153:
    mov    ecx,DWORD PTR [edi+0x20]
    mov    esi,eax
    cmp    eax,ecx
    jne    Branch148
  Branch154:
    pop    edi
    pop    esi
    ret
  }
}

// Copy fixed bytes with native gaps, clone tree8c/colors/payload, copy late count and trailing WORD; RET4/receiver.
// S: CURRENT treeS-10/no-op localS-11/stateS-4. Nonempty path reloads source argument only for trailing WORD9c.
// R6GameService.dll @ 100517c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyRecordStateAndNestedTree(void *destination,undefined4 *source)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRecordTreeCopyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    push    ebp
    push    esi
    mov    ebp,ecx
    push    edi
    mov    ecx,0x20
    mov    esi,ebx
    mov    edi,ebp
    mov    DWORD PTR [esp+0x14],0x0
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    movs    BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ax,WORD PTR [ebx+0x82]
    lea    edi,[ebx+0x8c]
    mov    WORD PTR [ebp+0x82],ax
    mov    cl,BYTE PTR [ebx+0x84]
    mov    BYTE PTR [ebp+0x84],cl
    mov    edx,DWORD PTR [ebx+0x88]
    lea    esi,[ebp+0x8c]
    lea    eax,[esp+0x13]
    mov    DWORD PTR [ebp+0x88],edx
    push    eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x18],esi
    mov    DWORD PTR [esi+0xc],0x10077f84
    call    R6GameServiceAddresses::ForwardStackWord
    push    0x0
    push    eax
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push    0x3c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    xor    ecx,ecx
    mov    BYTE PTR [esp+0x20],0x2
    mov    DWORD PTR [esi+0x4],ecx
    mov    dl,BYTE PTR [edi+0x8]
    mov    BYTE PTR [esi+0x8],dl
    mov    edx,DWORD PTR [edi]
    cmp    DWORD PTR [edx+0x4],ecx
    mov    BYTE PTR [eax],cl
    jne    Branch155
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],ecx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    jmp    Branch160
  Branch155:
    mov    ecx,DWORD PTR [edi]
    mov    ebx,DWORD PTR [esi]
    push    ebx
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,esi
    push    edx
    call    R6GameServiceAddresses::CloneOrderedTreeSubtree
    mov    DWORD PTR [ebx+0x4],eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    je    Branch157
  Branch156:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test    ecx,ecx
    jne    Branch156
  Branch157:
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    je    Branch159
  Branch158:
    mov    ecx,eax
    mov    eax,DWORD PTR [ecx+0xc]
    test    eax,eax
    jne    Branch158
  Branch159:
    mov    ebx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [edx+0xc],ecx
  Branch160:
    mov    eax,DWORD PTR [edi+0x4]
    pop    edi
    mov    DWORD PTR [esi+0x4],eax
    mov    cx,WORD PTR [ebx+0x9c]
    mov    WORD PTR [ebp+0x9c],cx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Destroy the original temporary record tree at frame-c4; its proxy pointer is not owned by this cleanup.
// R6GameService.dll @ 10068a10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EnsureOuterRecordExistsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x150]
    jmp    R6GameServiceAddresses::DestroyRecordTreeAtOffset8c
  }
}

// Free the CURRENT raw proxy allocation saved at frame-158; do not run child destruction.
// R6GameService.dll @ 10068a1b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EnsureOuterRecordExistsUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x158]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Destroy the copied key-prefixed record tree at frame-20.
// R6GameService.dll @ 10068a28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EnsureOuterRecordExistsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::DestroyRecordTreeAtOffset90
  }
}

// Free the head referenced by CURRENT saved cleanup context after entering copied-tree clear.
// R6GameService.dll @ 10068a33 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EnsureOuterRecordExistsUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x15c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Free the head referenced by CURRENT saved cleanup context after entering original-tree clear.
// R6GameService.dll @ 10068a3e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EnsureOuterRecordExistsUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x15c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Reset first descriptor primary table only; no list retry.
// R6GameService.dll @ 10068a60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy first complete descriptor and its list values/nodes/head.
// R6GameService.dll @ 10068a68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset second descriptor primary table only, then predecessor state1 cleans the first.
// R6GameService.dll @ 10068a70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy second complete descriptor, then predecessor state1 cleans the first.
// R6GameService.dll @ 10068a78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset second descriptor after entered list destruction; do not retry it, then clean the first.
// R6GameService.dll @ 10068a80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset first descriptor after entered list destruction; do not retry values/nodes/head.
// R6GameService.dll @ 10068a88 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveNestedRecordsByOuterKeyUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset the inherited descriptor base table only; do not retry list cleanup.
// R6GameService.dll @ 10068aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the complete inherited descriptor and its owned list.
// R6GameService.dll @ 10068aa8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the inherited descriptor base table only; do not retry list cleanup.
// R6GameService.dll @ 10068ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x84]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the complete inherited descriptor and its owned list.
// R6GameService.dll @ 10068abb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x84]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the inherited descriptor base table only; do not retry list cleanup.
// R6GameService.dll @ 10068ac6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the complete inherited descriptor and its owned list.
// R6GameService.dll @ 10068ace : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the inherited descriptor base table only; do not retry list cleanup.
// R6GameService.dll @ 10068ad6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the complete inherited descriptor and its owned list.
// R6GameService.dll @ 10068ade : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the inherited descriptor base table only; do not retry list cleanup.
// R6GameService.dll @ 10068ae6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the complete inherited descriptor and its owned list.
// R6GameService.dll @ 10068aee : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyNestedRecordUpdateByTextPairUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select exact ten-state descriptor cleanup FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10068af6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRecordTextUpdateEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetOuterRecordAndFlushQueuedUpdatesUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact seven-state descriptor lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10068b38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectQueuedResponseEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact inherited descriptor base/full-list or CURRENT saved head context selected by the native state.
// R6GameService.dll @ 10068b80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMissingNestedRecordRequestUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch161
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x68],eax
    jmp    Branch162
  Branch161:
    mov    DWORD PTR [ebp-0x68],0x0
  Branch162:
    mov    ecx,DWORD PTR [ebp-0x68]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact seven-state descriptor lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10068ba7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMissingRecordRequestEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueueMissingNestedRecordRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Free CURRENT parent raw allocation at inheritedEBP-10; shared append/pop guard retries no published object.
// R6GameService.dll @ 10068bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl indexed_record_supportSharedLifetimeUnwind12(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}


// Select shared single-state raw-allocation cleanup FuncInfo for append/pop and tail CRT dispatch.
// R6GameService.dll @ 10068bca : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRecordQueueAllocationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::indexed_record_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native shared raw queue-allocation cleanup map/FuncInfo.
// R6GameService.dll data @ 100835e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry indexed_record_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::indexed_record_supportSharedLifetimeUnwind12},
};

// Literal native shared raw queue-allocation cleanup map/FuncInfo.
// R6GameService.dll data @ 100835e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo indexed_record_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::indexed_record_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Select the five-state outer record construction map and tail CRT dispatch.
// R6GameService.dll @ 10068a49 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOuterRecordCreationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::EnsureOuterRecordExistsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native outer-record construction map and FuncInfo.
// R6GameService.dll data @ 100833d4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry EnsureOuterRecordExistsUnwindMap[5] = {
  {-1, R6GameServiceAddresses::EnsureOuterRecordExistsUnwind1},
  {0, R6GameServiceAddresses::EnsureOuterRecordExistsUnwind2},
  {0, R6GameServiceAddresses::EnsureOuterRecordExistsUnwind3},
  {0, R6GameServiceAddresses::EnsureOuterRecordExistsUnwind4},
  {-1, R6GameServiceAddresses::EnsureOuterRecordExistsUnwind5},
};
// R6GameService.dll data @ 100833fc : native storage identity retained.
const R6GameServiceNative::FuncInfo EnsureOuterRecordExistsExceptionInfo = {
  0x19930520,
  5,
  R6GameServiceAddresses::EnsureOuterRecordExistsUnwindMap,
  0,
  0,
  0,
  0,
};

// Literal ten-state text-update descriptor cleanup map and FuncInfo.
// R6GameService.dll data @ 100834ac : native storage identity retained.
const R6GameServiceNative::UnwindEntry ApplyNestedRecordUpdateByTextPairUnwindMap[10] = {
  {-1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind1},
  {-1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind2},
  {0x1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind3},
  {0x1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind4},
  {-1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind5},
  {-1, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind6},
  {0x5, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind7},
  {0x5, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind8},
  {0x7, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind9},
  {0x7, R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwind10},
};
// R6GameService.dll data @ 100834fc : native storage identity retained.
const R6GameServiceNative::FuncInfo ApplyNestedRecordUpdateByTextPairExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPairUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal queued-response and missing-record descriptor cleanup maps/FuncInfo.
// R6GameService.dll data @ 10083518 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ResetOuterRecordAndFlushQueuedUpdatesUnwindMap[7] = {
  {-1, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind1},
  {-1, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind2},
  {0x1, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind3},
  {0x1, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind4},
  {0x3, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind5},
  {0x3, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind6},
  {0x3, R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwind7},
};
// R6GameService.dll data @ 10083550 : native storage identity retained.
const R6GameServiceNative::FuncInfo ResetOuterRecordAndFlushQueuedUpdatesExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdatesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1008356c : native storage identity retained.
const R6GameServiceNative::UnwindEntry QueueMissingNestedRecordRequestUnwindMap[7] = {
  {-1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind1},
  {-1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind2},
  {0x1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind3},
  {0x1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind4},
  {0x1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind5},
  {-1, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind6},
  {0x5, R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwind7},
};
// R6GameService.dll data @ 100835a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo QueueMissingNestedRecordRequestExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::QueueMissingNestedRecordRequestUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Forward address of inherited no-op localEBP-11 to genuine no-effect target; free nothing.
// R6GameService.dll @ 10068be0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyRecordStateAndNestedTreeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x11]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Free CURRENT saved tree first word at inheritedEBP-10; do not retry copied nodes.
// R6GameService.dll @ 10068be8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyRecordStateAndNestedTreeUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact six-state descriptor FuncInfo and tail CRT dispatch; one native parent registration.
// R6GameService.dll @ 10068a90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectNestedNotificationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native six-state descriptor cleanup map/FuncInfo.
// R6GameService.dll data @ 10083460 : native storage identity retained.
const R6GameServiceNative::UnwindEntry RemoveNestedRecordsByOuterKeyUnwindMap[6] = {
  {-1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind1},
  {-1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind2},
  {0x1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind3},
  {0x1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind4},
  {0x1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind5},
  {-1, R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwind6},
};

// Literal native six-state descriptor cleanup map/FuncInfo.
// R6GameService.dll data @ 10083490 : native storage identity retained.
const R6GameServiceNative::FuncInfo RemoveNestedRecordsByOuterKeyExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::RemoveNestedRecordsByOuterKeyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Select exact three-state no-op/head-only copy FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10068bf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRecordTreeCopyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CopyRecordStateAndNestedTreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 10083608 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CopyRecordStateAndNestedTreeUnwindMap[3] = {
  {-1, R6GameServiceAddresses::CopyRecordStateAndNestedTreeUnwind1},
  {0x0, R6GameServiceAddresses::CopyRecordStateAndNestedTreeUnwind2},
  {-1, R6GameServiceAddresses::CopyRecordStateAndNestedTreeUnwind2},
};

// Literal native copy cleanup/catch metadata.
// R6GameService.dll data @ 10083608 : native storage identity retained.
const R6GameServiceNative::FuncInfo CopyRecordStateAndNestedTreeExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::CopyRecordStateAndNestedTreeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
