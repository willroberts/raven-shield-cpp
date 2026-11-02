#include "native_addresses.h"
#include "native_records.h"

// Native CHttpDownload: primary table10075bec/COL100785f4/type1008c504.
// Allocator-base vbtable selectors10075bf0/10075bf8 and request tree+8 are explicit; no complete layout is asserted.

// Destroys CHttpDownload, then tests the current low deletion bit before freeing and returning its owner.
// R6GameService.dll @ 10016500 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyOrderedTreeWrapperAndMaybeFree(void *owner,uint deletionFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyOrderedTreeWrapperContents
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Clears requests, conditionally frees leftover tree nodes, then frees the live header and restores the base table.
// State1 guards tree then base; state2 guards header then base; state3 runs the empty action then base.
// Header/count slots remain dangling after release; allocator EAX survives the final base-table write.
// R6GameService.dll @ 10016520 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyOrderedTreeWrapperContents(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x8],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::CHttpDownloadVTable
    mov    DWORD PTR [esp+0x18],0x1
    call   R6GameServiceAddresses::ClearRequestTree
    lea    esi,[edi+0x8]
    mov    DWORD PTR [esp+0xc],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [esp+0x18],0x2
    test   eax,eax
    je     Branch2
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::FreeOrderedTreeNodes
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch2:
    mov    eax,DWORD PTR [esi]
    push   0x1
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [esp+0x20],0x3
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [edi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Restores the allocator-override base table on the saved complete owner at frame-0x14.
// R6GameService.dll @ 100647d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyOrderedTreeWrapperContentsUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Tail-destroys the embedded request tree at saved owner+8 without repeating request-value destruction.
// R6GameService.dll @ 100647d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyOrderedTreeWrapperContentsUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsThunk
  }
}

// Releases the live request-tree header through the saved slot at frame-0x10.
// R6GameService.dll @ 100647e3 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyOrderedTreeWrapperContentsUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Loads the saved tree slot into ECX and tail-calls the genuine empty cleanup body, retaining raw EAX.
// R6GameService.dll @ 100647eb : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyOrderedTreeWrapperContentsUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// R6GameService.dll data @ 1007ea64 : native HTTP lifetime records.
const R6GameServiceNative::UnwindEntry QueueHttpRequestUnwindMap[1] = {
  {-1, R6GameServiceAddresses::QueueHttpRequestUnwind1},
};
// R6GameService.dll data @ 1007ea6c : native HTTP lifetime records.
const R6GameServiceNative::FuncInfo QueueHttpRequestExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::QueueHttpRequestUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007ea04 : native HTTP lifetime records.
const R6GameServiceNative::UnwindEntry DestroyOrderedTreeWrapperContentsUnwindMap[4] = {
  {-1, R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsUnwind1},
  {0x0, R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsUnwind2},
  {0x0, R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsUnwind3},
  {0x0, R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsUnwind4},
};
// R6GameService.dll data @ 1007ea24 : native HTTP lifetime records.
const R6GameServiceNative::FuncInfo DestroyOrderedTreeWrapperContentsExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Installs allocator-base selectors, allocates an unchecked request-tree header and clears the request sequence.
// R6GameService.dll @ 10016490 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructCHttpDownload(void *owner,uint installVirtualBase)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    xor    ebx,ebx
    push   esi
    cmp    eax,ebx
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],ebx
    je     Branch3
    mov    DWORD PTR [esi+0x4],0x10075bf8
  Branch3:
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    push   0x18
    mov    DWORD PTR [esi+0x14],0x10075bf0
    mov    DWORD PTR [esi+0x8],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x10]
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],ebx
    mov    BYTE PTR [esi+0x10],cl
    mov    BYTE PTR [eax],bl
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edx+0x4],ebx
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::CHttpDownloadVTable
    mov    DWORD PTR [esi+0x18],ebx
    mov    eax,esi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Advances a wrapping sequence, constructs/inserts a request, and optionally pumps it synchronously until state6.
// Counter publishes before allocation; null records still enter the map, and only the current low option byte pumps.
// R6GameService.dll @ 10016660 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueHttpRequest(
    void *owner,char *remotePath,char *localPath,uint optionWord,uint callback,uint callbackWord)
{
  __asm {
    mov    eax,fs:0x0
    push   0xffffffff
    push   R6GameServiceAddresses::QueueHttpRequestSelectExceptionInfo
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x28]
    xor    ebp,ebp
    push   edi
    cmp    esi,ebp
    mov    edi,ecx
    jne    Branch4
    xor    eax,eax
    jmp    Branch16
  Branch4:
    mov    ebx,DWORD PTR [edi+0x18]
    push   0xa84
    inc    ebx
    mov    DWORD PTR [edi+0x18],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ebp
    mov    DWORD PTR [esp+0x20],ebp
    je     Branch5
    mov    ecx,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [esp+0x34]
    push   0x1
    push   ebp
    push   ebp
    push   esi
    push   ebp
    push   ecx
    mov    ecx,DWORD PTR [esp+0x40]
    push   ebp
    push   edx
    mov    edx,DWORD PTR [esp+0x50]
    push   ecx
    push   edx
    push   0x2
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeHttpRequestRecord
    mov    ebp,eax
  Branch5:
    mov    edx,DWORD PTR [edi+0x8]
    lea    esi,[edi+0x8]
    mov    DWORD PTR [esp+0x20],0xffffffff
    mov    eax,DWORD PTR [edx+0x8]
    cmp    eax,edx
    mov    DWORD PTR [esp+0x2c],eax
    je     Branch12
  Branch6:
    cmp    DWORD PTR [eax+0x10],ebx
    ja     Branch12
    mov    ecx,DWORD PTR [eax+0xc]
    test   ecx,ecx
    je     Branch8
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch11
  Branch7:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch7
    jmp    Branch11
  Branch8:
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    jne    Branch10
  Branch9:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch9
  Branch10:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch11
    mov    eax,ecx
  Branch11:
    cmp    eax,edx
    mov    DWORD PTR [esp+0x2c],eax
    jne    Branch6
  Branch12:
    lea    eax,[esp+0x2c]
    lea    ecx,[esp+0x38]
    push   eax
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x18],ebp
    call   R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x38]
    push   ecx
    push   ecx
    mov    ecx,esp
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    lea    eax,[esp+0x3c]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::FindOrInsertUnsignedTreeNodeNearHint
    mov    al,BYTE PTR [esp+0x30]
    test   al,al
    je     Branch15
    mov    eax,DWORD PTR [ebp+0x1b4]
    mov    esi,0x6
    cmp    eax,esi
    je     Branch14
  Branch13:
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::AdvanceHttpRequestState
    cmp    DWORD PTR [ebp+0x1b4],esi
    jne    Branch13
  Branch14:
    mov    ecx,edi
    call   R6GameServiceAddresses::RemoveCompletedRequestsFromTree
  Branch15:
    mov    eax,ebx
  Branch16:
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret    0x14
  }
}

// Frees the unfinished request allocation saved at virtual frame-0x14.
// R6GameService.dll @ 10064820 : complete native control/access order and raw ABI retained.
__declspec(naked) void QueueHttpRequestUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the single-state request-allocation guard.
// R6GameService.dll @ 1006482a : complete native control/access order and raw ABI retained.
__declspec(naked) void QueueHttpRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueueHttpRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the four-state CHttpDownload destructor guard.
// R6GameService.dll @ 100647f3 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyOrderedTreeWrapperContentsSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyOrderedTreeWrapperContentsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Looks up a request, optionally prepares its output file, then dispatches the current state0..5.
// Callbacks can change the state selected after file failure; non-200 header results still unconditionally enter5.
// State5 may report completion twice; only missing keys return AL0, and native upper EAX is retained.
// R6GameService.dll @ 100167b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AdvanceHttpRequestState(void *owner,uint requestId)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    lea    eax,[esp+0xc]
    push   eax
    lea    esi,[edi+0x8]
    mov    ecx,esi
    call   R6GameServiceAddresses::OrderedTreeFind
    cmp    eax,DWORD PTR [esi]
    jne    Branch17
    pop    edi
    xor    al,al
    pop    esi
    ret    0x4
  Branch17:
    mov    esi,DWORD PTR [eax+0x14]
    push   ebx
    mov    ebx,0x6
    mov    eax,DWORD PTR [esi+0x1b0]
    cmp    eax,0x2
    je     Branch18
    cmp    eax,0x3
    jne    Branch19
  Branch18:
    mov    al,BYTE PTR [esi+0x194]
    test   al,al
    jne    Branch19
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestOpenOutput
    test   al,al
    jne    Branch19
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x0
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    mov    edx,DWORD PTR [esp+0x10]
    push   0xc
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
  Branch19:
    mov    eax,DWORD PTR [esi+0x1b4]
    cmp    eax,0x5
    ja     Branch28
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GHttpRequestStateTargets]
    mov    eax,DWORD PTR [esp+0x10]
    push   0x0
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    lea    ecx,[esi+0xc]
    lea    edx,[esi+0x1c5]
    push   ecx
    push   edx
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseHttpUrlIntoRequestFields
    test   al,al
    je     Branch20
    mov    DWORD PTR [esi+0x1b4],0x1
    mov    eax,DWORD PTR [esp+0x10]
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch20:
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x3
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestOpenTcp
    test   al,al
    je     Branch21
    mov    DWORD PTR [esi+0x1b4],0x2
    mov    edx,DWORD PTR [esp+0x10]
    push   0x2
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch21:
    push   R6GameServiceAddresses::TextLibgshttpErrorConnectFailed
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,esi
    push   0x5
    push   eax
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestSubmitGet
    test   al,al
    je     Branch22
    mov    DWORD PTR [esi+0x1b4],0x3
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x3
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch22:
    push   R6GameServiceAddresses::TextLibgshttpErrorSendingRequestFailed
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    edx,DWORD PTR [esp+0x10]
    mov    ecx,esi
    push   0x5
    push   edx
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestAccumulateHeader
    test   al,al
    je     Branch28
    mov    DWORD PTR [esi+0x1b4],0x4
    mov    eax,DWORD PTR [esp+0x10]
    push   0x4
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestParseHeader
    test   al,al
    je     Branch26
    mov    eax,DWORD PTR [esi+0xa4c]
    cmp    eax,0xc8
    je     Branch25
    cmp    eax,0x12b
    jle    Branch23
    cmp    eax,0x190
    jge    Branch23
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esi+0x1b4],ebx
    call   R6GameServiceAddresses::MapHttpStatusToRequestError
    mov    ecx,DWORD PTR [esp+0x10]
    push   eax
    push   ecx
    jmp    Branch24
  Branch23:
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esi+0x1b4],ebx
    call   R6GameServiceAddresses::MapHttpStatusToRequestError
    mov    edx,DWORD PTR [esp+0x10]
    push   eax
    push   edx
  Branch24:
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
  Branch25:
    pop    ebx
    mov    DWORD PTR [esi+0x1b4],0x5
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch26:
    push   R6GameServiceAddresses::TextLibgshttpErrorReadingHeadersFailure
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,esi
    push   ebx
    push   eax
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x5
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestAcceptBodyChunk
    test   al,al
    jne    Branch27
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    edx,DWORD PTR [esp+0x10]
    push   0x0
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
  Branch27:
    mov    eax,DWORD PTR [esi+0xa48]
    cmp    eax,0xffffffff
    je     Branch28
    cmp    DWORD PTR [esi+0xa64],eax
    jl     Branch28
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    eax,DWORD PTR [esp+0x10]
    push   0x5
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestDeliverData
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x0
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestNotifyCompletion
  Branch28:
    pop    ebx
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Removes state6 requests using a successor captured before close/deletion, then frees each detached node.
// State is read before the redundant null check; close may replace the node value before virtual deletion.
// R6GameService.dll @ 10016dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RemoveCompletedRequestsFromTree(void *owner)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   edi
    mov    eax,DWORD PTR [ebx+0x8]
    mov    edi,DWORD PTR [eax+0x8]
    cmp    edi,eax
    je     Branch32
    push   esi
  Branch29:
    push   edi
    mov    esi,edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ecx,DWORD PTR [esi+0x14]
    mov    edi,eax
    add    esp,0x4
    cmp    DWORD PTR [ecx+0x1b4],0x6
    jne    Branch31
    test   ecx,ecx
    je     Branch30
    call   R6GameServiceAddresses::CHttpRequestCloseTcp
    mov    ecx,DWORD PTR [esi+0x14]
    test   ecx,ecx
    je     Branch30
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch30:
    mov    eax,DWORD PTR [ebx+0x8]
    lea    ecx,[eax+0xc]
    lea    edx,[eax+0x8]
    push   ecx
    add    eax,0x4
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    dec    DWORD PTR [ebx+0xc]
  Branch31:
    cmp    edi,DWORD PTR [ebx+0x8]
    jne    Branch29
    pop    esi
  Branch32:
    pop    edi
    pop    ebx
    ret
  }
}

// Captures each successor, closes/deletes any current request value, then removes and frees every tree node.
// Value reload after close, live header/count loads and raw final allocator or header EAX remain ordered.
// R6GameService.dll @ 10016e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearRequestTree(void *owner)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx+0x8]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch40
    push   edi
  Branch33:
    mov    eax,DWORD PTR [esi+0xc]
    mov    edi,esi
    test   eax,eax
    je     Branch35
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    je     Branch38
  Branch34:
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    jne    Branch34
    jmp    Branch38
  Branch35:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch37
  Branch36:
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    je     Branch36
  Branch37:
    cmp    DWORD PTR [esi+0xc],eax
    je     Branch38
    mov    esi,eax
  Branch38:
    mov    ecx,DWORD PTR [edi+0x14]
    test   ecx,ecx
    je     Branch39
    call   R6GameServiceAddresses::CHttpRequestCloseTcp
    mov    ecx,DWORD PTR [edi+0x14]
    test   ecx,ecx
    je     Branch39
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch39:
    mov    eax,DWORD PTR [ebx+0x8]
    lea    ecx,[eax+0xc]
    lea    edx,[eax+0x8]
    push   ecx
    add    eax,0x4
    push   edx
    push   eax
    push   edi
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [ebx+0xc]
    dec    ecx
    mov    DWORD PTR [ebx+0xc],ecx
    mov    eax,DWORD PTR [ebx+0x8]
    cmp    esi,eax
    jne    Branch33
    pop    edi
  Branch40:
    pop    esi
    pop    ebx
    ret
  }
}

// R6GameService.dll data @ 10016a68 : native HTTP dispatch table.
const uint GHttpRequestStateTargets[6] = {
  R6GameServiceAddresses::GHttpRequestStateTargetsCase1,R6GameServiceAddresses::GHttpRequestStateTargetsCase2,R6GameServiceAddresses::GHttpRequestStateTargetsCase3,R6GameServiceAddresses::GHttpRequestStateTargetsCase4,R6GameServiceAddresses::GHttpRequestStateTargetsCase5,R6GameServiceAddresses::GHttpRequestStateTargetsCase6
};

// Native virtual-table prefix: CHttpDownloadVTable
// R6GameService.dll data @ 10075bec : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CHttpDownloadVTableRecord {
  R6GameServiceNative::Address DestroyOrderedTreeWrapperAndMaybeFree; // +0x00
};
const CHttpDownloadVTableRecord CHttpDownloadVTable = {R6GameServiceAddresses::DestroyOrderedTreeWrapperAndMaybeFree};
