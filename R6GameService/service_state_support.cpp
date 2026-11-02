#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10081268 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ServiceStateConstructExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1008129c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ServiceStateDestroyExceptionHandlerFunctionInfo;

// clGLClient owns this service state, but its original concrete class identity remains unassigned.
// Constructor frame: flags at EntryESP-0x18, owner at-0x14, inner allocation at-0x10, FS/handler/state at-c/-8/-4.
// The mutable incoming word at EntryESP+4 holds outer allocations; exact native states govern partial construction.
// Destructor frame: owner at EntryESP-0x10, FS/handler/state at-c/-8/-4; only embedded queues have unwind actions.
// R6GameService.dll data @ 10094584 : native storage identity retained.
extern void *GCurrentServiceState;

// Constructs three embedded queues and staged service children, then publishes the current service pointer.
// R6GameService.dll @ 1003f210 : native ECX/stack boundary and raw register effects retained.
__declspec(naked) void * __thiscall ConstructServiceState(void *owner,uint initializeVirtualBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ServiceStateConstructExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x4],ebx
    mov    eax,DWORD PTR [esp+0x20]
    push   esi
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0xc],esi
    je Branch1
    // The table77d4c is a vbtable [0,0x1ac], not a primary vtable.
    mov    DWORD PTR [esi],0x10077d4c
    mov    DWORD PTR [esp+0x8],0x1
    mov    DWORD PTR [esp+0x1c],ebx
    // Construct queues at+0x168/+0x17c/+0x190 under states0/1/2.
  Branch1:
    push   ebp
    push   edi
    push   0x1
    lea    ecx,[esi+0x168]
    call   R6GameServiceAddresses::ConstructCMsgQueue
    push   0x1
    lea    ecx,[esi+0x17c]
    mov    DWORD PTR [esp+0x28],0x1
    call   R6GameServiceAddresses::ConstructCMsgQueue
    push   0x1
    lea    ecx,[esi+0x190]
    mov    BYTE PTR [esp+0x28],0x2
    call   R6GameServiceAddresses::ConstructCMsgQueue
    // Clear the selected scalars and two 129-byte buffers; other bytes retain their prior contents.
    lea    ecx,[esi+0x4]
    xor    eax,eax
    mov    DWORD PTR [esi+0x14c],ebx
    mov    BYTE PTR [esi+0x148],bl
    mov    BYTE PTR [esi+0x149],bl
    mov    DWORD PTR [ecx],eax
    lea    ebp,[esi+0x46]
    push   0x14
    mov    DWORD PTR [ecx+0x4],eax
    mov    edi,ebp
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ecx+0xc],eax
    mov    ecx,0x20
    rep stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    lea    edi,[esi+0xc7]
    mov    ecx,0x20
    xor    eax,eax
    rep stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // The original argument at EntryESP+4 now holds staged outer allocations.
    mov    DWORD PTR [esp+0x2c],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x24],0x4
    je Branch2
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructCMsgQueue
    jmp Branch3
  Branch2:
    xor    eax,eax
  Branch3:
    push   0x18
    mov    DWORD PTR [esi+0x164],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x2c],edi
    cmp    edi,ebx
    je Branch5
    // First wrapper: clear+4/+8/+0x0c, construct a0x34-byte child and retain padding at+0x15..17.
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [edi],0x10077d44
    or     al,0x2
    mov    DWORD PTR [esp+0x10],eax
    push   0x34
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],ebx
    mov    DWORD PTR [edi+0xc],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x18],eax
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x24],0x7
    je Branch4
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeServiceVtablesAndStorage
    mov    DWORD PTR [edi+0x10],eax
    mov    BYTE PTR [edi+0x14],bl
    mov    DWORD PTR [esp+0x24],0x5
    jmp Branch6
  Branch4:
    xor    eax,eax
    mov    BYTE PTR [edi+0x14],bl
    mov    DWORD PTR [edi+0x10],eax
    mov    DWORD PTR [esp+0x24],0x5
    jmp Branch6
  Branch5:
    xor    edi,edi
  Branch6:
    push   0x18
    mov    DWORD PTR [esi+0x150],edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x2c],edi
    cmp    edi,ebx
    je Branch8
    // Second wrapper: clear only+4/+8; its+0x0c word retains allocation contents.
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [edi],0x10077d3c
    or     al,0x4
    mov    DWORD PTR [esp+0x10],eax
    push   0x50
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x18],eax
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x24],0xa
    je Branch7
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeServiceObjectVtablesAndStorage
    mov    DWORD PTR [edi+0x10],eax
    mov    BYTE PTR [edi+0x14],bl
    mov    DWORD PTR [esp+0x24],0x8
    jmp Branch9
  Branch7:
    xor    eax,eax
    mov    BYTE PTR [edi+0x14],bl
    mov    DWORD PTR [edi+0x10],eax
    mov    DWORD PTR [esp+0x24],0x8
    jmp Branch9
  Branch8:
    xor    edi,edi
  Branch9:
    push   0x34
    mov    DWORD PTR [esi+0x154],edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x2c],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x24],0xb
    je Branch10
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructServiceProtocolDispatcher
    jmp Branch11
  Branch10:
    xor    eax,eax
    // Publish dispatcher before address discovery; its call runs in state3.
  Branch11:
    mov    DWORD PTR [esi+0x158],eax
    push   ebx
    lea    eax,[esi+0xc7]
    push   ebx
    push   eax
    push   ebp
    mov    BYTE PTR [esp+0x34],0x3
    mov    DWORD PTR [esi+0x160],ebx
    call   R6GameServiceAddresses::FindIPv4Interface
    push   0xb8
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x2c],eax
    cmp    eax,ebx
    pop    edi
    mov    BYTE PTR [esp+0x20],0xc
    pop    ebp
    je Branch12
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeServiceRecordCollections
    jmp Branch13
  Branch12:
    xor    eax,eax
    // The final eight-byte callback object has no separate constructor frame.
  Branch13:
    push   0x8
    mov    DWORD PTR [esi+0x15c],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    cmp    eax,ebx
    je Branch14
    mov    DWORD PTR [eax+0x4],0x10077d34
    mov    DWORD PTR [eax],R6GameServiceAddresses::CProxyHandlerVTable
    jmp Branch15
  Branch14:
    xor    eax,eax
    // Publish the current service pointer without resetting it during destruction.
  Branch15:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esi+0x1a8],eax
    mov    DWORD PTR [GCurrentServiceState],esi
    mov    DWORD PTR [esi+0x1a4],ebx
    mov    BYTE PTR [esi+0x14a],bl
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x4
  }
}

// Tail-forwards embedded queue destruction with unchanged receiver, return address and raw result.
// R6GameService.dll @ 1003f490 : native ECX/stack boundary and raw register effects retained.
__declspec(naked) uint __fastcall DestroyServiceQueueThunk(void *queue)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyCMsgQueue
  }
}

// Destroys optional children in native order, clears completed slots and unwinds the three embedded queues.
// R6GameService.dll @ 1003f4a0 : native ECX/stack boundary and raw register effects retained.
__declspec(naked) uint __fastcall DestroyServiceState(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ServiceStateDestroyExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x14c]
    xor    ebx,ebx
    cmp    edi,ebx
    mov    DWORD PTR [esp+0x18],0x2
    je Branch16
    mov    ecx,edi
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x14c],ebx
  Branch16:
    mov    ecx,DWORD PTR [esi+0x164]
    cmp    ecx,ebx
    je Branch17
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [esi+0x164],ebx
  Branch17:
    mov    edi,DWORD PTR [esi+0x150]
    cmp    edi,ebx
    je Branch18
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseServiceTreeRecord
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x150],ebx
  Branch18:
    mov    edi,DWORD PTR [esi+0x154]
    cmp    edi,ebx
    je Branch19
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseServiceTreeRecord
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x154],ebx
  Branch19:
    mov    edi,DWORD PTR [esi+0x158]
    cmp    edi,ebx
    je Branch20
    mov    ecx,edi
    call   R6GameServiceAddresses::DestroyServiceProtocolDispatcher
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x158],ebx
  Branch20:
    mov    ecx,DWORD PTR [esi+0x160]
    cmp    ecx,ebx
    je Branch21
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
    mov    DWORD PTR [esi+0x160],ebx
  Branch21:
    mov    ecx,DWORD PTR [esi+0x1a8]
    cmp    ecx,ebx
    je Branch22
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [esi+0x1a8],ebx
  Branch22:
    mov    edi,DWORD PTR [esi+0x15c]
    cmp    edi,ebx
    je Branch23
    mov    ecx,edi
    call   R6GameServiceAddresses::DestroyServiceSubobject
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x15c],ebx
    // Retire list states before each reverse-order destructor call; EAX remains the last child residue.
  Branch23:
    lea    ecx,[esi+0x190]
    mov    BYTE PTR [esp+0x18],0x1
    call   R6GameServiceAddresses::DestroyCMsgQueue
    lea    ecx,[esi+0x17c]
    mov    BYTE PTR [esp+0x18],bl
    call   R6GameServiceAddresses::DestroyCMsgQueue
    lea    ecx,[esi+0x168]
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   R6GameServiceAddresses::DestroyCMsgQueue
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// For flag bit0, tail-forwards saved owner+0x1ac to the genuine empty virtual-base destructor.
// R6GameService.dll @ 10066bc0 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl CleanupServiceVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test   eax,eax
    je Branch24
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x1ac
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch24:
    ret
  }
}

// Destroys the first embedded queue through the constructor owner saved at parent EBP-0x14.
// R6GameService.dll @ 10066bdd : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroyFirstServiceQueueOnConstructUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x168
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Destroys the second embedded queue through the constructor owner saved at parent EBP-0x14.
// R6GameService.dll @ 10066beb : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroySecondServiceQueueOnConstructUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x17c
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Destroys the third embedded queue through the constructor owner saved at parent EBP-0x14.
// R6GameService.dll @ 10066bf9 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroyThirdServiceQueueOnConstructUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x190
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Frees the current allocation word at inherited EBP+4 for unwind state4.
// R6GameService.dll @ 10066c07 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceAllocationAtState4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Frees the current allocation word at inherited EBP+4 for unwind state5.
// R6GameService.dll @ 10066c11 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceAllocationAtState5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit1, tail-forwards the staged wrapper+0x18 to the genuine empty virtual-base destructor.
// R6GameService.dll @ 10066c1b : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl CleanupServiceWrapperBaseAtState6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x2
    test   eax,eax
    je Branch25
    mov    ecx,DWORD PTR [ebp+0x4]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch25:
    ret
  }
}

// Frees the staged inner allocation saved at parent EBP-0x10.
// R6GameService.dll @ 10066c35 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceInnerAllocationAtState7(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Frees the current allocation word at inherited EBP+4 for unwind state8.
// R6GameService.dll @ 10066c3f : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceAllocationAtState8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit2, tail-forwards the staged wrapper+0x18 to the genuine empty virtual-base destructor.
// R6GameService.dll @ 10066c49 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl CleanupServiceWrapperBaseAtState9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x4
    test   eax,eax
    je Branch26
    mov    ecx,DWORD PTR [ebp+0x4]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch26:
    ret
  }
}

// Frees the staged inner allocation saved at parent EBP-0x10.
// R6GameService.dll @ 10066c63 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceInnerAllocationAtState10(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Frees the current allocation word at inherited EBP+4 for unwind state11.
// R6GameService.dll @ 10066c6d : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceAllocationAtState11(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Frees the current allocation word at inherited EBP+4 for unwind state12.
// R6GameService.dll @ 10066c77 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseServiceAllocationAtState12(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the thirteen-state service-construction unwind map.
// R6GameService.dll @ 10066c81 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ServiceStateConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServiceStateConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the first embedded queue through the destructor owner saved at parent EBP-0x10.
// R6GameService.dll @ 10066c90 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroyFirstServiceQueueOnDestroyUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x168
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Destroys the second embedded queue through the destructor owner saved at parent EBP-0x10.
// R6GameService.dll @ 10066c9e : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroySecondServiceQueueOnDestroyUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x17c
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Destroys the third embedded queue through the destructor owner saved at parent EBP-0x10.
// R6GameService.dll @ 10066cac : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl DestroyThirdServiceQueueOnDestroyUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x190
    jmp    R6GameServiceAddresses::DestroyServiceQueueThunk
  }
}

// Selects the three-state embedded-queue destruction unwind map.
// R6GameService.dll @ 10066cba : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ServiceStateDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServiceStateDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Construct five containers, optional Persistent/Ladder callback owners and fixed defaults in native order.
// Preserve CURRENT argument reuse,18-state guards, NULL allocation gaps and incoming padding; no stronger rollback.
// Entry S: flagsS-18/ownerS-14/contextS-10/stateS-4; full raw initialize word, owner return/RET4.
// R6GameService.dll @ 10041740 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeServiceRecordCollections(void *owner,uint initializeVirtualBase)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectServiceRecordCollectionsEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    mov    DWORD PTR [esp+0x10],edi
    mov    eax,DWORD PTR [esp+0x2c]
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x14],esi
    je    Branch27
    mov    DWORD PTR [esi],0x10077de4
    mov    edi,0x1
  Branch27:
    push    ebp
    lea    ebp,[esi+0x30]
    or    edi,0x2
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [ebp+0x10],0x10077ddc
    mov    DWORD PTR [esp+0x14],edi
    lea    ecx,[ebp+0x4]
    mov    DWORD PTR [esp+0x28],0x1
    mov    DWORD PTR [esp+0x1c],ecx
    call    R6GameServiceAddresses::InitializeTreeSentinel24
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clPointerMap_IPAVCLadderResultsVTable
    lea    ebp,[esi+0x44]
    or    edi,0x8
    mov    DWORD PTR [esp+0x28],0x3
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [ebp+0x10],0x10077dbc
    mov    DWORD PTR [esp+0x14],edi
    lea    ecx,[ebp+0x4]
    mov    BYTE PTR [esp+0x28],0x4
    mov    DWORD PTR [esp+0x1c],ecx
    call    R6GameServiceAddresses::InitializeTreeSentinel24
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clPointerMap_IPAVclDataListVTable
    lea    ecx,[esi+0x58]
    or    edi,0x20
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [ecx+0xc],0x10077d9c
    lea    eax,[esp+0x30]
    lea    edx,[esp+0x13]
    push    eax
    push    edx
    mov    DWORD PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InitializeTreeSentinel
    lea    ecx,[esi+0xa0]
    or    edi,0x40
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [ecx+0x4],0x10077d94
    lea    eax,[esp+0x30]
    mov    DWORD PTR [esp+0x28],0xb
    push    eax
    call    R6GameServiceAddresses::InitializeCircularList36
    lea    ecx,[esi+0xa8]
    or    edi,0x80
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [ecx+0xc],0x10077d8c
    lea    edx,[esp+0x30]
    lea    eax,[esp+0x13]
    push    edx
    push    eax
    mov    DWORD PTR [esp+0x30],0xe
    call    R6GameServiceAddresses::InitializeThirtyByteListStorage
    mov    DWORD PTR [esp+0x28],0xc
    push    0x20
    mov    DWORD PTR [esi+0x28],ebx
    mov    DWORD PTR [esi+0x4],ebx
    mov    DWORD PTR [esi+0x8],ebx
    mov    DWORD PTR [esi+0xc],ebx
    mov    DWORD PTR [esi+0x14],ebx
    mov    DWORD PTR [esi+0x2c],ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x30],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x28],0x10
    pop    ebp
    je    Branch28
    push    0x1
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeExtendedVtableSubobject
    jmp    Branch29
  Branch28:
    xor    eax,eax
  Branch29:
    push    0x14
    mov    DWORD PTR [esi+0x18],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x2c],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x24],0x11
    je    Branch30
    push    0x1
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeVtableSubobject
    jmp    Branch31
  Branch30:
    xor    eax,eax
  Branch31:
    mov    DWORD PTR [esi+0x20],eax
    mov    eax,0x1
    mov    DWORD PTR [esi+0x6c],eax
    mov    DWORD PTR [esi+0x70],eax
    mov    ecx,0x8
    xor    eax,eax
    lea    edi,[esi+0x78]
    mov    BYTE PTR [esi+0x24],bl
    mov    BYTE PTR [esi+0x1c],bl
    mov    DWORD PTR [esi+0x68],ebx
    mov    DWORD PTR [esi+0x74],ebx
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,DWORD PTR [esp+0x1c]
    stos    BYTE PTR es:[edi],al
    mov    DWORD PTR [esi+0x9c],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  }
}

// Tail exact container destructor with unchanged receiver/stack/raw result.
// R6GameService.dll @ 10041930 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardServiceTreeContainerCleanup(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServiceTreeContainer
  }
}

// Tail exact container destructor with unchanged receiver/stack/raw result.
// R6GameService.dll @ 10041940 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardServicePayloadCircularListCleanup(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServicePayloadCircularList
  }
}

// Tail exact container destructor with unchanged receiver/stack/raw result.
// R6GameService.dll @ 10041950 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardServicePayloadTreeCleanup(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServicePayloadTreeContainer
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066e50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test    eax,eax
    je    Branch32
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xb8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch32:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066e6d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x2
    test    eax,eax
    je    Branch33
    mov    ecx,DWORD PTR [ebp+0x4]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch33:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066e87 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x30
    jmp    R6GameServiceAddresses::thunk_DestroyServiceTreeContainer
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066e92 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x8
    test    eax,eax
    je    Branch34
    mov    ecx,DWORD PTR [ebp+0x4]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch34:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066eac : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x44
    jmp    R6GameServiceAddresses::thunk_DestroyServiceTreeContainerVariant
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066eb7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x20
    test    eax,eax
    je    Branch35
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch35:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066ed1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind9(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066ed9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x58
    jmp    R6GameServiceAddresses::ForwardServiceTreeContainerCleanup
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066ee4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind11(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x40
    test    eax,eax
    je    Branch36
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch36:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066efe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind12(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f06 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind13(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa0
    jmp    R6GameServiceAddresses::ForwardServicePayloadCircularListCleanup
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f14 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind14(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x80
    test    eax,eax
    je    Branch37
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch37:
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind15(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind16(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa8
    jmp    R6GameServiceAddresses::ForwardServicePayloadTreeCleanup
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f46 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind17(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Honor exact construction-mask/current context, genuine no-op or raw allocation/container cleanup.
// R6GameService.dll @ 10066f50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeServiceRecordCollectionsUnwind18(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select exact18-state construction FuncInfo, including two genuine NULL actions, and tail CRT dispatch.
// R6GameService.dll @ 10066f5a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceRecordCollectionsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeServiceRecordCollectionsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal construction map/FuncInfo; preserve native predecessor chains and NULL actions2/5.
// R6GameService.dll data @ 1008154c : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeServiceRecordCollectionsUnwindMap[18] = {
  {-1, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind1},
  {0x0, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind2},
  {0x1, 0x0},
  {0x0, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind4},
  {0x3, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind5},
  {0x4, 0x0},
  {0x3, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind7},
  {0x6, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind8},
  {0x7, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind9},
  {0x6, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind10},
  {0x9, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind11},
  {0xa, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind12},
  {0x9, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind13},
  {0xc, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind14},
  {0xd, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind15},
  {0xc, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind16},
  {0xf, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind17},
  {0xf, R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwind18},
};

// Literal construction map/FuncInfo; preserve native predecessor chains and NULL actions2/5.
// R6GameService.dll data @ 100815dc : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeServiceRecordCollectionsExceptionInfo = {
  0x19930520,
  0x12,
  R6GameServiceAddresses::InitializeServiceRecordCollectionsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Release captured owned8/14, conditional adjusted callback18/20 and callback2c, then clear five containers.
// Preserve flag-dependent retained fields, current virtual tables and exact10-state entered cleanup; raw last free EAX.
// Entry S: ownerS-14/currentmemberS-10/stateS-4; map stages avoid retrying values or entered storage cleanup.
// R6GameService.dll @ 10041b30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceSubobject(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectCollectionDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0x10],esi
    mov    edi,DWORD PTR [esi+0x8]
    xor    ebx,ebx
    cmp    edi,ebx
    mov    DWORD PTR [esp+0x20],0x4
    je    Branch38
    mov    ecx,edi
    call    R6GameServiceAddresses::DestroyIndexedRecordCollectionState
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x8],ebx
  Branch38:
    mov    edi,DWORD PTR [esi+0x14]
    cmp    edi,ebx
    je    Branch39
    mov    ecx,edi
    call    R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x14],ebx
  Branch39:
    mov    al,BYTE PTR [esi+0x1c]
    test    al,al
    jne    Branch41
    mov    eax,DWORD PTR [esi+0x18]
    cmp    eax,ebx
    je    Branch40
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch40:
    mov    DWORD PTR [esi+0x18],ebx
  Branch41:
    mov    al,BYTE PTR [esi+0x24]
    test    al,al
    jne    Branch43
    mov    eax,DWORD PTR [esi+0x20]
    cmp    eax,ebx
    je    Branch42
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch42:
    mov    DWORD PTR [esi+0x20],ebx
  Branch43:
    mov    ecx,DWORD PTR [esi+0x2c]
    cmp    ecx,ebx
    je    Branch44
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch44:
    mov    eax,DWORD PTR [esi+0x30]
    lea    edi,[esi+0x30]
    mov    ecx,edi
    call    DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [esi+0x44]
    lea    ebp,[esi+0x44]
    mov    ecx,ebp
    call    DWORD PTR [edx+0x4]
    lea    ebx,[esi+0xa8]
    mov    DWORD PTR [esp+0x14],ebx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x20],0x5
    call    R6GameServiceAddresses::ClearTreePayloadNodes
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x20],0x3
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ebx,[esi+0xa0]
    mov    DWORD PTR [esp+0x14],ebx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x20],0x6
    call    R6GameServiceAddresses::ClearPayloadList
    mov    eax,DWORD PTR [ebx]
    push    0x1
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    add    esi,0x58
    mov    DWORD PTR [esp+0x14],esi
    mov    ecx,esi
    mov    BYTE PTR [esp+0x20],0x7
    call    R6GameServiceAddresses::ClearTreeNodes
    mov    ecx,esi
    mov    BYTE PTR [esp+0x20],0x1
    call    R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    esi,ebp
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerMap_IPAVclDataListVTable
    push    ecx
    mov    ecx,DWORD PTR [esi+0x4]
    lea    ebx,[esi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebp,DWORD PTR [esi]
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x2c],0x8
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,esi
    call    DWORD PTR [ebp+0xc]
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x20],0x0
    call    R6GameServiceAddresses::DestroyServiceSubtreeContainer
    mov    esi,edi
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerMap_IPAVCLadderResultsVTable
    push    ecx
    mov    ecx,DWORD PTR [esi+0x4]
    lea    edi,[esi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [esi]
    mov    ecx,edi
    mov    DWORD PTR [esp+0x2c],0x9
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,esi
    call    DWORD PTR [ebx+0xc]
    mov    ecx,edi
    mov    DWORD PTR [esp+0x20],0xffffffff
    call    R6GameServiceAddresses::ClearOrderedTreeStorage
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066f70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x30
    jmp    R6GameServiceAddresses::thunk_DestroyServiceTreeContainer
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066f7b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x44
    jmp    R6GameServiceAddresses::thunk_DestroyServiceTreeContainerVariant
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066f86 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x58
    jmp    R6GameServiceAddresses::ForwardServiceTreeContainerCleanup
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066f91 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa0
    jmp    R6GameServiceAddresses::ForwardServicePayloadCircularListCleanup
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066f9f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa8
    jmp    R6GameServiceAddresses::ForwardServicePayloadTreeCleanup
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066fad : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066fb5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066fbd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066fc5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x10],0x0
    je    Branch45
    mov    eax,DWORD PTR [ebp-0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x48],eax
    jmp    Branch46
  Branch45:
    mov    DWORD PTR [ebp-0x48],0x0
  Branch46:
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyServiceSubtreeContainer
  }
}

// Destroy exact remaining container or CURRENT entered member storage; preserve NULL/scratch/no-op contexts.
// R6GameService.dll @ 10066fec : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceSubobjectUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x10],0x0
    je    Branch47
    mov    eax,DWORD PTR [ebp-0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch48
  Branch47:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch48:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ClearOrderedTreeStorage
  }
}

// Select exact destruction FuncInfo and tail CRT dispatch; shared selector has one canonical definition.
// R6GameService.dll @ 10067013 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectCollectionDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceSubobjectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destruction map/FuncInfo; preserve entered no-retry/no-op predecessor chains.
// R6GameService.dll data @ 10081664 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyServiceSubobjectUnwindMap[10] = {
  {-1, R6GameServiceAddresses::DestroyServiceSubobjectUnwind1},
  {0x0, R6GameServiceAddresses::DestroyServiceSubobjectUnwind2},
  {0x1, R6GameServiceAddresses::DestroyServiceSubobjectUnwind3},
  {0x2, R6GameServiceAddresses::DestroyServiceSubobjectUnwind4},
  {0x3, R6GameServiceAddresses::DestroyServiceSubobjectUnwind5},
  {0x3, R6GameServiceAddresses::DestroyServiceSubobjectUnwind6},
  {0x2, R6GameServiceAddresses::DestroyServiceSubobjectUnwind7},
  {0x1, R6GameServiceAddresses::DestroyServiceSubobjectUnwind8},
  {0x0, R6GameServiceAddresses::DestroyServiceSubobjectUnwind9},
  {-1, R6GameServiceAddresses::DestroyServiceSubobjectUnwind10},
};

// Literal destruction map/FuncInfo; preserve entered no-retry/no-op predecessor chains.
// R6GameService.dll data @ 100816b4 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceSubobjectExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::DestroyServiceSubobjectUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

uint __fastcall ClearTwoServiceStateWords(void *owner);
uint __thiscall OpenNestedConnectionAndWait(void *owner,const char *endpointText,uint portWord);
uint __thiscall DispatchParsedSelector54(void *owner);
uint __thiscall DispatchParsedSelector55Text(void *owner);
uint __thiscall InstallTransportFieldsIfEmpty(void *owner,uint transportWord,uint queueWord);
// Append string and formatted 32-bit values to the ECX descriptor (RET 4).
uint __thiscall AppendClDataListString(void *destination,const char *text);
uint __thiscall AppendClDataListSignedDecimal(void *destination,const void *value);
uint __fastcall DispatchParsedCallback38(void *owner);
uint __fastcall DispatchParsedCallback3c(void *owner);
uint __fastcall DispatchParsedCallback40(void *owner);
uint __fastcall DispatchParsedCallback80(void *owner);
uint __fastcall DispatchParsedCallback84(void *owner);
uint __fastcall DispatchParsedCallback88(void *owner);
uint __thiscall InitializeTransportRecordIfAbsent(void *recordOwner,void *transport,
    void *requestContext,char *textAtBcSource,char *textAtCcSource,char *textAt14dSource);
uint __fastcall HandleSelector13RecordRemoval(void *dispatcherState);
uint __fastcall ProcessTransportRecordsIfPresent(void *dispatcherState);
undefined4 GetElapsedMilliseconds(void);
uint __thiscall transport_record_support_DispatchRequest18ByKey(void *dispatcherState,undefined4 value,int key,
    char *primaryText,undefined4 flagWord,char *trailingText,undefined4 trailingValue);
uint __thiscall DispatchRequest18ByKey(void *this,undefined4 value,int key,
    char *primaryText,undefined4 flagWord,char *trailingText,undefined4 trailingValue);
uint __thiscall SendTransportRequestPayload(void *transportState,char *requestText,
    uint byteFieldValue,uint wordValue);
uint __thiscall ReplaceServiceTreeNamesFromDelimitedText(void *this,char *inputText);
uint __thiscall AppendClDataListCopy(void *destination,undefined4 *source);
uint __thiscall SendTransportPayload(void *transport,uint opcode,uint mode,
    const void *payload);
uint __thiscall QueueMissingNestedRecordRequest(
    void *owner,const byte *text,uint word0,uint word1);
uint __thiscall ApplyNestedRecordUpdateByTextPair(
    void *owner,const byte *text,uint word0,uint word1);
uint __thiscall SendProxyRequestForOuterRecordKey(void *owner,uint keyWord);
uint __thiscall ResetOuterRecordAndFlushQueuedUpdates(
    void *owner,uint outerRecordKey,uint responseValue);

struct NativeDescriptorArgument24 {
  undefined4 words[6];
};

// Native RET 0x28 consumes four scalar stack arguments and the 24-byte descriptor.
uint __thiscall ApplyIndexedKeyUpdate(void *owner,undefined4 value,int key,undefined4 code,
    undefined4 rawWord4,NativeDescriptorArgument24 descriptor);
uint __thiscall MultiplyAddLimbWordsByWord(void* mathContext,uint* destination,
    const uint* addend,uint multiplier,const uint* multiplicand,uint limbCount);
uint __thiscall MultiplySubtractLimbWordsByWord(void* mathContext,uint* destination,
    const uint* minuend,uint multiplier,const uint* multiplicand,uint limbCount);
uint __thiscall MultiplyWordsToDoubleWord(void* mathContext,uint* result,uint left,uint right);
uint __thiscall EstimateQuotientWordFromTwoWords(void* mathContext,uint* quotient,
    const uint* dividendWords,uint divisor);
uint __thiscall MultiplyLimbArrays(void* mathContext,uint* destination,const uint* left,
    const uint* right,uint limbCount);
uint __thiscall ReduceLimbWordsModulo(void* mathContext,uint* remainder,const uint* dividend,
    uint dividendLimbCount,const uint* divisor,uint divisorLimbCount);
uint __thiscall MultiplyLimbWordsModulo(void* mathContext,uint* destination,const uint* left,
    const uint* right,const uint* modulus,uint limbCount);
uint __thiscall ModularExponentiateLimbWords(void* mathContext,uint* result,const uint* base,
    const uint* exponent,uint exponentLimbCount,const uint* modulus,uint modulusLimbCount);

uint __fastcall clPointerMap_DestroyServiceTreeContainer(int *treeObject);
uint __fastcall DestroyServiceTreeContainerVariant(int *treeObject);
uint __fastcall DestroyServiceTreeContainer(int *tree);
uint __fastcall DestroyServicePayloadCircularList(void *list);
uint __fastcall DestroyServicePayloadTreeContainer(int *tree);

uint __fastcall ReleasePayloadReferenceAt4(void *record);

// Build three descriptors, accept current marker26/27 despite reader status, append late lowWORD/signed value.
// Caller source slot is decimal scratch; word slot becomes raw allocation, disarmed before current-global enqueue.
// R6GameService.dll @ 1003f5e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall QueueMarkedClDataRecord(
    uint unused,uint wordValue,int signedValue,void *sourceClData)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectMarkedRecordBuilderEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x4c
    push   ebx
    push   ebp
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    ebp,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   esi
    mov    DWORD PTR [esp+0xc],eax
    push   edi
    mov    BYTE PTR [esp+0x10],al
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x58],ebp
    mov    DWORD PTR [esp+0x4c],0x3
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x54]
    mov    DWORD PTR [esp+0x68],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    esi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x44],edi
    mov    DWORD PTR [esp+0x50],esi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x6c],0x1
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x30],ebp
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],esi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x48],ebp
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x68],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x38],esi
    mov    ebp,DWORD PTR [esp+0x78]
    lea    eax,[esp+0x10]
    mov    bl,0x5
    push   0x0
    push   eax
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x6c],bl
    call   R6GameServiceAddresses::ReadIndexedByte
    mov    al,BYTE PTR [esp+0x10]
    cmp    al,0x26
    je    Branch49
    cmp    al,0x27
    je    Branch49
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x64],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],esi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    jmp    Branch52
  Branch49:
    lea    ecx,[esp+0x2c]
    push   0x1
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CopyIndexedClDataList
    mov    edx,DWORD PTR [esp+0x70]
    lea    eax,[esp+0x78]
    and    edx,0xffff
    push   eax
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x7c],edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    edx,[esp+0x74]
    lea    ecx,[esp+0x14]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x78]
    and    eax,0xff
    push   ecx
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x7c],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x44]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x70],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x64],0x7
    je    Branch50
    push   0x1
    lea    ecx,[esp+0x48]
    push   0x0
    push   ecx
    push   0xcc
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    jmp    Branch51
  Branch50:
    xor    eax,eax
  Branch51:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCurrentServiceState
    push   eax
    mov    BYTE PTR [esp+0x68],bl
    call   R6GameServiceAddresses::ForwardOptionalServiceQueueItem
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x38],esi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x64],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x20],esi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x9
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],ebx
  Branch52:
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0x10
  }
}

// Construct three descriptors, accept captured lowWORD selector26/27, mutate captured source with late word-low16.
// Reuse selector slot for constant0x66/captured selector; word slot becomes raw allocation, disarmed before queue.
// R6GameService.dll @ 1003f810 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall BuildServiceRecord66(uint wordValue,uint selector,void *sourceClData)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectWordRecordBuildersEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x4c
    push   ebx
    push   ebp
    push   esi
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],esi
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x68],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x6c],0x1
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x30],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x60],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x68],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    mov    esi,DWORD PTR [esp+0x70]
    mov    BYTE PTR [esp+0x64],0x5
    cmp    si,0x26
    je    Branch53
    cmp    si,0x27
    je    Branch53
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x64],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    jmp    Branch56
  Branch53:
    mov    eax,DWORD PTR [esp+0x6c]
    mov    ebx,DWORD PTR [esp+0x74]
    lea    ecx,[esp+0x70]
    and    eax,0xffff
    push   ecx
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x74],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x70]
    lea    ecx,[esp+0x2c]
    push   edx
    mov    DWORD PTR [esp+0x74],0x66
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    push   ebx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x70]
    and    esi,0xffff
    push   eax
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x74],esi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListCopy
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x6c],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x64],0x7
    je    Branch54
    push   0x1
    lea    edx,[esp+0x18]
    push   0x0
    push   edx
    push   0xcc
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    jmp    Branch55
  Branch54:
    xor    eax,eax
  Branch55:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCurrentServiceState
    push   eax
    mov    BYTE PTR [esp+0x68],0x5
    call   R6GameServiceAddresses::ForwardOptionalServiceQueueItem
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x64],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    esi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x44],esi
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x9
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],esi
  Branch56:
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0xc
  }
}

// Construct three descriptors, accept captured lowWORD selector26/27, mutate captured source with late word-low16.
// Reuse selector slot for constant0x5d/captured selector; word slot becomes raw allocation, disarmed before queue.
// R6GameService.dll @ 1003fa30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall BuildServiceRecord5D(uint wordValue,uint selector,void *sourceClData)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectWordRecordBuildersEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x4c
    push   ebx
    push   ebp
    push   esi
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],esi
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x68],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x6c],0x1
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x30],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x60],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x68],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    mov    esi,DWORD PTR [esp+0x70]
    mov    BYTE PTR [esp+0x64],0x5
    cmp    si,0x26
    je    Branch57
    cmp    si,0x27
    je    Branch57
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x64],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    jmp    Branch60
  Branch57:
    mov    eax,DWORD PTR [esp+0x6c]
    mov    ebx,DWORD PTR [esp+0x74]
    lea    ecx,[esp+0x70]
    and    eax,0xffff
    push   ecx
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x74],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x70]
    lea    ecx,[esp+0x2c]
    push   edx
    mov    DWORD PTR [esp+0x74],0x5d
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    push   ebx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x70]
    and    esi,0xffff
    push   eax
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x74],esi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListCopy
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x6c],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x64],0x7
    je    Branch58
    push   0x1
    lea    edx,[esp+0x18]
    push   0x0
    push   edx
    push   0xcc
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    jmp    Branch59
  Branch58:
    xor    eax,eax
  Branch59:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCurrentServiceState
    push   eax
    mov    BYTE PTR [esp+0x68],0x5
    call   R6GameServiceAddresses::ForwardOptionalServiceQueueItem
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x64],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    esi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x44],esi
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x9
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],esi
  Branch60:
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0xc
  }
}

// Construct three descriptors, accept captured lowWORD selector26/27, mutate captured source with late word-low16.
// Reuse selector slot for constant0x4d/captured selector; word slot becomes raw allocation, disarmed before queue.
// R6GameService.dll @ 1003fc50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall BuildServiceRecord4D(uint wordValue,uint selector,void *sourceClData)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectWordRecordBuildersEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x4c
    push   ebx
    push   ebp
    push   esi
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],esi
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x68],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x6c],0x1
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x30],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x60],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x68],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    mov    esi,DWORD PTR [esp+0x70]
    mov    BYTE PTR [esp+0x64],0x5
    cmp    si,0x26
    je    Branch61
    cmp    si,0x27
    je    Branch61
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x64],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    jmp    Branch64
  Branch61:
    mov    eax,DWORD PTR [esp+0x6c]
    mov    ebx,DWORD PTR [esp+0x74]
    lea    ecx,[esp+0x70]
    and    eax,0xffff
    push   ecx
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x74],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x70]
    lea    ecx,[esp+0x2c]
    push   edx
    mov    DWORD PTR [esp+0x74],0x4d
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    push   ebx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x70]
    and    esi,0xffff
    push   eax
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x74],esi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListCopy
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x6c],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x64],0x7
    je    Branch62
    push   0x1
    lea    edx,[esp+0x18]
    push   0x0
    push   edx
    push   0xcc
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    jmp    Branch63
  Branch62:
    xor    eax,eax
  Branch63:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCurrentServiceState
    push   eax
    mov    BYTE PTR [esp+0x68],0x5
    call   R6GameServiceAddresses::ForwardOptionalServiceQueueItem
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x64],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    esi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x44],esi
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x9
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],esi
  Branch64:
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x64],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0xc
  }
}

// Return raw zero for null item; otherwise rewrite argument and tail CURRENT owner+190 queue without an owner guard.
// R6GameService.dll @ 1003fe70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardOptionalServiceQueueItem(void *owner,void *queuedItem)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je    Branch65
    mov    DWORD PTR [esp+0x4],eax
    add    ecx,0x190
    jmp    R6GameServiceAddresses::EnqueueCMsgQueuePayload
  Branch65:
    ret    0x4
  }
}

// Read initialized scalar despite reader AL; exact26/27 selects nested scalar, otherwise return first full word.
// Preserve pre-state2 record access gap, captured record/current payload, reused argument cleanup and saved result.
// R6GameService.dll @ 1003fe90 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall ExtractRecordDispatchCode(void *record)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectDispatchCodeExtractorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    mov    DWORD PTR [esp+0x8],0x0
    push   esi
    mov    DWORD PTR [esp+0xc],0x0
    mov    DWORD PTR [esp+0x8],0x0
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x24]
    push   eax
    mov    DWORD PTR [esp+0x38],0x1
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    mov    esi,DWORD PTR [esp+0x3c]
    lea    ecx,[esp+0xc]
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x3c],0x2
    call   R6GameServiceAddresses::ReadIndexedInt32
    mov    eax,DWORD PTR [esp+0xc]
    cmp    eax,0x26
    jl    Branch66
    cmp    eax,0x27
    jg    Branch66
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    call   R6GameServiceAddresses::CopyIndexedClDataList
    lea    eax,[esp+0x8]
    push   0x0
    push   eax
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::ReadIndexedInt32
    jmp    Branch67
  Branch66:
    mov    DWORD PTR [esp+0x8],eax
  Branch67:
    mov    esi,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x24]
    mov    DWORD PTR [esp+0x10],edx
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],0x5
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x24]
    push   0x1
    push   eax
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
  }
}

// R6GameService.dll @ 1003ffd0: releases a disconnected transport and advances the +0x158 state if needed.
void __thiscall MaintainTransportState(void *this)
{
  void *memory;
  bool stateResult;

  if (*(char *)((int)this + 0x148) != '\0') {
    stateResult = (byte)IsTransportConnected(*(void **)((int)this + 0x14c));
    if (!stateResult) {
      ReplaceSelectionAndDispatchSlot14(*(void **)((int)this + 0x150));
      memory = *(void **)((int)this + 0x14c);
      *(undefined1 *)((int)this + 0x148) = 0;
      if (memory != (void *)0x0) {
        CConnectionDestroyProvider((int)memory);
        TailFreeThroughGlobalAllocator(memory);
      }
      *(undefined4 *)((int)this + 0x14c) = 0;
      ClearTwoServiceStateWords(*(void **)((int)this + 0x150));
      ClearTwoServiceStateWords(*(void **)((int)this + 0x154));
      if (*(char *)((int)this + 0x14a) != '\0') {
        ProcessTransportRecordsIfPresent(*(void **)((int)this + 0x158));
      }
    }
  }
  stateResult = ServicePendingRecordsForDispatcher(*(void **)((int)this + 0x158));
  if ((stateResult) || (*(char *)(*(int *)((int)this + 0x158) + 0x19) == '\0')) {
    return;
  }
  RefreshEnabledServiceCallback(*(void **)((int)this + 0x158));
  return;
}

// R6GameService.dll @ 10040070: drains one selected source until empty or its unsigned time budget is exceeded.
void __thiscall DrainSelectedRecordSource(void *this,int sourceSelector,uint timeBudget)
{
  void *queuedItem;
  uint elapsedDelta;
  uint elapsedTotal;

  // The first sample resets the shared delta timer even when no source is selected.
  GetElapsedMilliseconds();
  elapsedTotal = 0;
  if (sourceSelector == 2) {
    if (*(char *)((int)this + 0x148) != '\0') {
      queuedItem = CConnectionPopCopiedMessage(*(void **)((int)this + 0x14c));
      while (queuedItem != (void *)0x0) {
        RouteTransportRecord(this,queuedItem);
        elapsedDelta = GetElapsedMilliseconds();
        elapsedTotal = elapsedTotal + elapsedDelta;
        if (timeBudget < elapsedTotal) {
          return;
        }
        queuedItem = CConnectionPopCopiedMessage(*(void **)((int)this + 0x14c));
      }
    }
  }
  else if (sourceSelector == 8) {
    if ((*(char *)((int)this + 0x14a) != '\0') &&
       (queuedItem = BuildNextDispatcherRecord(*(void **)((int)this + 0x158)),
        queuedItem != (void *)0x0)) {
      while( true ) {
        QueueAndCheckStateRecord(this,queuedItem);
        elapsedDelta = GetElapsedMilliseconds();
        elapsedTotal = elapsedTotal + elapsedDelta;
        if (timeBudget < elapsedTotal) break;
        queuedItem = BuildNextDispatcherRecord(*(void **)((int)this + 0x158));
        if (queuedItem == (void *)0x0) {
          return;
        }
      }
    }
  }
  else if (((sourceSelector == 0x10) && (*(char *)((int)this + 0x149) != '\0')) &&
          (queuedItem = PopPendingServiceRecord(*(int *)((int)this + 0x15c)),
           queuedItem != (void *)0x0)) {
    while( true ) {
      ParseAndQueueRecord(this,queuedItem);
      elapsedDelta = GetElapsedMilliseconds();
      elapsedTotal = elapsedTotal + elapsedDelta;
      if (timeBudget < elapsedTotal) break;
      queuedItem = PopPendingServiceRecord(*(int *)((int)this + 0x15c));
      if (queuedItem == (void *)0x0) {
        return;
      }
    }
  }
  return;
}

// Route captured record by low opcode or a BYTE decoded into the reused caller slot; preserve caller-slot upper lanes.
// CC/D1 current enables choose queued responses; disabled destinations retain record. Unknown releases payload then allocation.
// Keep captured owner/record, current contexts after enqueue, zero scalar scratch and exact raw EAX/ECX residue; no own EH.
// R6GameService.dll @ 10040180 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RouteTransportRecord(void *owner,void *record)
{
  __asm {
    push   ecx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,ecx
    test   edi,edi
    je    Branch74
    mov    al,BYTE PTR [edi+0x4]
    mov    BYTE PTR [esp+0x10],0x0
    cmp    al,0x26
    mov    DWORD PTR [esp+0x8],0x0
    jb    Branch68
    cmp    al,0x27
    ja    Branch68
    mov    ecx,DWORD PTR [edi+0x8]
    push   0x0
    lea    eax,[esp+0x14]
    push   0x1
    push   eax
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    mov    eax,DWORD PTR [esp+0x10]
  Branch68:
    and    eax,0xff
    dec    eax
    cmp    eax,0xdd
    ja    Branch73
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::GTransportRouteIndices]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::GTransportRouteTargets]
    mov    ecx,DWORD PTR [esi+0x164]
    push   edi
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
    push   edi
    lea    ecx,[esi+0x168]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::ExtractRecordDispatchCode
    and    eax,0xffff
    cmp    eax,0x3
    je    Branch70
    cmp    eax,0x13
    mov    al,BYTE PTR [esi+0x14a]
    je    Branch69
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x17c]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  Branch69:
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x17c]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::HandleSelector13RecordRemoval
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  Branch70:
    mov    al,BYTE PTR [esi+0x14a]
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x17c]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    mov    ecx,DWORD PTR [esi+0x158]
    lea    edx,[esp+0x8]
    lea    eax,[esp+0x10]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ProcessIndexedTextUpdate
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::ExtractRecordDispatchCode
    and    eax,0xffff
    dec    eax
    je    Branch72
    dec    eax
    mov    al,BYTE PTR [esi+0x149]
    je    Branch71
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x190]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  Branch71:
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x190]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    lea    ecx,[esp+0x8]
    lea    edx,[esp+0x10]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x15c]
    push   edx
    call   R6GameServiceAddresses::ApplySelectorTwoServiceResponse
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  Branch72:
    mov    al,BYTE PTR [esi+0x149]
    test   al,al
    je    Branch74
    push   edi
    lea    ecx,[esi+0x190]
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    lea    eax,[esp+0x8]
    lea    ecx,[esp+0x10]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esi+0x15c]
    call   R6GameServiceAddresses::ApplySelectorOneServiceResponse
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  Branch73:
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch74:
    pop    edi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Decode captured nonnull record, enqueue17c, then notify CURRENT context158 only when full decoded DWORD equalsd2.
// Null input retains incoming EAX; enqueue result ignored, late context/raw final return retained; no own EH.
// R6GameService.dll @ 10040430 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueAndCheckStateRecord(void *owner,void *record)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    test   edi,edi
    je    Branch76
    push   edi
    call   R6GameServiceAddresses::ExtractRecordDispatchCode
    cmp    eax,0xd2
    lea    ecx,[esi+0x17c]
    push   edi
    je    Branch75
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    pop    edi
    pop    esi
    ret    0x4
  Branch75:
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::ProcessKeyRecordToken
  Branch76:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Parse captured nonnull record for side effects, then enqueue it at owner190; preserve raw final EAX and null incoming EAX.
// R6GameService.dll @ 10040470 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseAndQueueRecord(void *owner,void *record)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    test   edi,edi
    je    Branch77
    push   edi
    call   R6GameServiceAddresses::ExtractRecordDispatchCode
    lea    ecx,[esi+0x190]
    push   edi
    call   R6GameServiceAddresses::EnqueueCMsgQueuePayload
  Branch77:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Maintain before checking CURRENT enabledBYTE148, drain source2, then dispatch current queue164 with unsigned accumulated time.
// Cache dispatch budget before first item; current contexts/queue bases reload. Selector62 falls through DE then removal.
// Full default selector/captured fallback allocation/raw upperEAX plus AL0/1 retained; no own EH or cleanup retry.
// R6GameService.dll @ 100404c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PollAndDispatchQueuedRecords(void *owner,uint sourceBudgetMs,uint dispatchBudgetMs)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::MaintainTransportState
    mov    al,BYTE PTR [esi+0x148]
    test   al,al
    jne    Branch78
    xor    al,al
    pop    esi
    ret    0x8
  Branch78:
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   ebp
    push   edi
    push   eax
    push   0x2
    mov    ecx,esi
    call   R6GameServiceAddresses::DrainSelectedRecordSource
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    mov    ecx,DWORD PTR [esi+0x164]
    xor    ebx,ebx
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    mov    edi,eax
    test   di,di
    je    Branch82
    mov    ebp,DWORD PTR [esp+0x18]
  Branch79:
    mov    ecx,edi
    and    ecx,0xffff
    lea    eax,[ecx-0x1]
    cmp    eax,0xdd
    ja    Branch80
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::GTransportDispatchIndices]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GTransportDispatchTargets]
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector13AndDispatchSlot00
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector5dAndDispatchSlot04
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector66AndDispatchSlot08
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector4dAndDispatchSlot0c
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelectorB5AndDispatchSlot10
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector01AndDispatchSlot18
    jmp    Branch81
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelector62AndDispatchSlot1c
    mov    ecx,DWORD PTR [esi+0x150]
    call   R6GameServiceAddresses::ParseSelectorDEAndDispatchSlot20
  Branch80:
    mov    ecx,DWORD PTR [esi+0x164]
    push   edi
    call   R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    edi,eax
    test   edi,edi
    je    Branch81
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch81:
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    add    ebx,eax
    cmp    ebx,ebp
    ja    Branch82
    mov    ecx,DWORD PTR [esi+0x164]
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    mov    edi,eax
    test   di,di
    jne    Branch79
  Branch82:
    pop    edi
    pop    ebp
    pop    ebx
    mov    al,0x1
    pop    esi
    ret    0x8
  }
}

// Maintain before CURRENT enabledBYTE148 gate, drain source2, then dispatch embedded queue168 with unsigned accumulated time.
// CURRENT dispatch budget reloads after each item; context154 reloads per dispatch, full selector reaches default removal.
// Preserve captured fallback allocation/raw upperEAX plus AL0/1, current reads and no own lifetime guard.
// R6GameService.dll @ 100408d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PollAndDispatchCallbackQueue(void *owner,uint sourceBudgetMs,uint dispatchBudgetMs)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::MaintainTransportState
    mov    al,BYTE PTR [esi+0x148]
    test   al,al
    jne    Branch83
    xor    al,al
    pop    esi
    ret    0x8
  Branch83:
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   ebp
    push   edi
    push   eax
    push   0x2
    mov    ecx,esi
    call   R6GameServiceAddresses::DrainSelectedRecordSource
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    lea    ebp,[esi+0x168]
    xor    ebx,ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    test   ax,ax
    je    Branch87
  Branch84:
    mov    ecx,eax
    and    ecx,0xffff
    add    ecx,0xfffffff8
    cmp    ecx,0x90
    ja    Branch85
    xor    edx,edx
    mov    dl,BYTE PTR [ecx+R6GameServiceAddresses::GSecondaryDispatchIndices]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GSecondaryDispatchTargets]
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector4e
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector4b
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector4c
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector4f
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector50
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector54
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSelector55Text
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot1c
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot20
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedOwnedBuffer
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot28
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot2c
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot30
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot34
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot38
    jmp    Branch86
    mov    ecx,DWORD PTR [esi+0x154]
    call   R6GameServiceAddresses::DispatchParsedSlot3c
    jmp    Branch86
  Branch85:
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    edi,eax
    test   edi,edi
    je    Branch86
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch86:
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ebx,eax
    ja    Branch87
    mov    ecx,ebp
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    test   ax,ax
    jne    Branch84
  Branch87:
    pop    edi
    pop    ebp
    pop    ebx
    mov    al,0x1
    pop    esi
    ret    0x8
  }
}

// Capture incoming callback word, load object158 and execute its replacement method; retain child upperEAX/AL1, RET4.
// R6GameService.dll @ 10040bb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetTertiaryCallbackPointer(void *owner,void *callback)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [ecx+0x158]
    push   eax
    call   R6GameServiceAddresses::ReplaceServiceCallback
    mov    al,0x1
    ret    0x4
  }
}

// If enabled, maintain/drain selector8 then dispatch AX queue selectors through the native switch under accumulated unsigned time.
// Preserve late owner/budgets/full default selector, captured fallback allocation and2b current-context reset/AL0 exit.
// R6GameService.dll @ 10040bd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ProcessPendingCallbackEvents(void *owner,uint recordDrainBudget,uint callbackBudget)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    al,BYTE PTR [esi+0x14a]
    test   al,al
    jne    Branch88
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x8
  Branch88:
    mov    ecx,esi
    call   R6GameServiceAddresses::MaintainTransportState
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,esi
    push   eax
    push   0x8
    call   R6GameServiceAddresses::DrainSelectedRecordSource
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    lea    ebp,[esi+0x17c]
    xor    ebx,ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    test   ax,ax
    je    Branch92
  Branch89:
    mov    ecx,eax
    and    ecx,0xffff
    add    ecx,0xfffffffa
    cmp    ecx,0x91
    ja    Branch90
    xor    edx,edx
    mov    dl,BYTE PTR [ecx+R6GameServiceAddresses::GCallbackProcessorIndices]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GCallbackProcessorTargets]
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::InvokeState15Callback
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector12
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::RecomputeServiceCallbackState
    mov    eax,DWORD PTR [esi+0x158]
    mov    cl,BYTE PTR [eax+0x19]
    test   cl,cl
    jne    Branch91
    mov    ecx,eax
    mov    BYTE PTR [esi+0x14a],0x0
    call   R6GameServiceAddresses::ResetTransportRecordState
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x8
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector17
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector18
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector0C
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector36Record
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector37
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector35Subrecords
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverServiceState9
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector32Record
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector33IndexedValues
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback38
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback3c
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback40
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector2D
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector0A
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector3D
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector0E
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector2eRecord
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector08
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector39
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector3E
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector1E
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector1F
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::thunk_DispatchSelector20Entries
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector21
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector38BinaryRecord
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector0F
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector97StringFlagRecords
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback80
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback84
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchParsedCallback88
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector40TextValues
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector3fValueAndText
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector41
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector6
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector2A
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector42TextAndBinary
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector6aTextAndPairs
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DeliverSelector45
    jmp    Branch91
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::DispatchSelector47VariantPayload
    jmp    Branch91
  Branch90:
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    edi,eax
    test   edi,edi
    je    Branch91
    mov    ecx,edi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch91:
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x18]
    cmp    ebx,eax
    ja    Branch92
    mov    ecx,ebp
    call   R6GameServiceAddresses::ReadQueuedHeadValue
    test   ax,ax
    jne    Branch89
  Branch92:
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    ret    0x8
  }
}

// Literal two-level callback switch: AX selectors6..97 index the BYTE map, then43 native code targets.
// R6GameService.dll data @ 10040f30 : native storage identity retained.
const uint GCallbackProcessorTargets[43] = {
  R6GameServiceAddresses::GCallbackProcessorTargetsCase1,R6GameServiceAddresses::GCallbackProcessorTargetsCase2,R6GameServiceAddresses::GCallbackProcessorTargetsCase3,R6GameServiceAddresses::GCallbackProcessorTargetsCase4,R6GameServiceAddresses::GCallbackProcessorTargetsCase5,R6GameServiceAddresses::GCallbackProcessorTargetsCase6,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase7,R6GameServiceAddresses::GCallbackProcessorTargetsCase8,R6GameServiceAddresses::GCallbackProcessorTargetsCase9,R6GameServiceAddresses::GCallbackProcessorTargetsCase10,R6GameServiceAddresses::GCallbackProcessorTargetsCase11,R6GameServiceAddresses::GCallbackProcessorTargetsCase12,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase13,R6GameServiceAddresses::GCallbackProcessorTargetsCase14,R6GameServiceAddresses::GCallbackProcessorTargetsCase15,R6GameServiceAddresses::GCallbackProcessorTargetsCase16,R6GameServiceAddresses::GCallbackProcessorTargetsCase17,R6GameServiceAddresses::GCallbackProcessorTargetsCase18,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase19,R6GameServiceAddresses::GCallbackProcessorTargetsCase20,R6GameServiceAddresses::GCallbackProcessorTargetsCase21,R6GameServiceAddresses::GCallbackProcessorTargetsCase22,R6GameServiceAddresses::GCallbackProcessorTargetsCase23,R6GameServiceAddresses::GCallbackProcessorTargetsCase24,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase25,R6GameServiceAddresses::GCallbackProcessorTargetsCase26,R6GameServiceAddresses::GCallbackProcessorTargetsCase27,R6GameServiceAddresses::GCallbackProcessorTargetsCase28,R6GameServiceAddresses::GCallbackProcessorTargetsCase29,R6GameServiceAddresses::GCallbackProcessorTargetsCase30,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase31,R6GameServiceAddresses::GCallbackProcessorTargetsCase32,R6GameServiceAddresses::GCallbackProcessorTargetsCase33,R6GameServiceAddresses::GCallbackProcessorTargetsCase34,R6GameServiceAddresses::GCallbackProcessorTargetsCase35,R6GameServiceAddresses::GCallbackProcessorTargetsCase36,
  R6GameServiceAddresses::GCallbackProcessorTargetsCase37,R6GameServiceAddresses::GCallbackProcessorTargetsCase38,R6GameServiceAddresses::GCallbackProcessorTargetsCase39,R6GameServiceAddresses::GCallbackProcessorTargetsCase40,R6GameServiceAddresses::GCallbackProcessorTargetsCase41,R6GameServiceAddresses::GCallbackProcessorTargetsCase42,
  R6GameServiceAddresses::service_state_supportBranch90
};
// R6GameService.dll data @ 10040fdc : native storage identity retained.
const byte GCallbackProcessorIndices[146] = {
  0x0,0x2a,0x1,0x2,0x3,0x2a,0x4,0x2a,0x5,0x6,0x2a,0x7,0x8,0x2a,0x2a,0x9,
  0x2a,0xa,0xb,0x2a,0x2a,0xc,0x2a,0x2a,0xd,0xe,0xf,0x10,0x2a,0x2a,0x11,0x2a,
  0x2a,0x2a,0x12,0x13,0x14,0x15,0x2a,0x16,0x17,0x2a,0x2a,0x2a,0x18,0x19,0x2a,0x1a,
  0x1b,0x1c,0x1d,0x1e,0x2a,0x1f,0x2a,0x20,0x21,0x22,0x23,0x24,0x25,0x2a,0x2a,0x26,
  0x2a,0x27,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,
  0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,
  0x2a,0x2a,0x2a,0x2a,0x28,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,
  0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,
  0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,0x2a,
  0x2a,0x29
};

// Gate current148/14c, drain captured queue17c, then reset/init/send through independently reloaded dispatcher158.
// Forward three full argument words, store sender AL at14a before clearing1a4, return raw sender EAX; no own EH.
// R6GameService.dll @ 10041070 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PrepareAndSendTransportRequest(
    void *owner,char *requestText,uint byteFieldValue,uint wordValue)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x148]
    test   al,al
    je    Branch93
    mov    eax,DWORD PTR [esi+0x14c]
    test   eax,eax
    je    Branch93
    push   edi
    lea    edi,[esi+0x17c]
    mov    ecx,edi
    call   R6GameServiceAddresses::DrainCMsgQueue
    mov    ecx,DWORD PTR [esi+0x158]
    call   R6GameServiceAddresses::ResetTransportRecordState
    lea    eax,[esi+0xc7]
    lea    ecx,[esi+0x46]
    push   eax
    mov    eax,DWORD PTR [esi+0x14c]
    lea    edx,[esi+0x4]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x158]
    push   edx
    push   edi
    push   eax
    call   R6GameServiceAddresses::InitializeTransportRecordIfAbsent
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x158]
    push   edx
    push   eax
    call   R6GameServiceAddresses::SendTransportRequestPayload
    mov    BYTE PTR [esi+0x14a],al
    mov    DWORD PTR [esi+0x1a4],0x0
    pop    edi
    pop    esi
    ret    0xc
  Branch93:
    xor    al,al
    pop    esi
    ret    0xc
  }
}

// R6GameService.dll @ 10041100 : forward record processing through the object at +0x158
uint __fastcall ProcessTransportRecordsViaOffset158(void *this)
{
  return ProcessTransportRecordsIfPresent(*(void **)((int)this + 0x158));
}

// Read full flag slot, capture CURRENT service158, write flag back, then tail request18 with raw EAX.
// R6GameService.dll @ 10041110 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchRequest18ByKey(void *this,uint value,int key,
    char *primaryText,uint flagWord,char *trailingText,uint trailingValue)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ecx+0x158]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKey
  }
}

// Reset outer base at inherited EBP-24.
// R6GameService.dll @ 10066cd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current outer descriptor at inherited EBP-24.
// R6GameService.dll @ 10066cd8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset middle base at inherited EBP-54.
// R6GameService.dll @ 10066ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current middle descriptor at inherited EBP-54.
// R6GameService.dll @ 10066ce8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset copied-child base at inherited EBP-3c.
// R6GameService.dll @ 10066cf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current copied-child descriptor at inherited EBP-3c.
// R6GameService.dll @ 10066cf8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered middle base at inherited EBP-54; do not retry its member destruction.
// R6GameService.dll @ 10066d00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Free CURRENT raw allocation in reused caller word argument at inherited EBP+8; descriptor cleanup follows.
// R6GameService.dll @ 10066d08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Reset entered copied-child base at inherited EBP-3c.
// R6GameService.dll @ 10066d12 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered middle base at inherited EBP-54.
// R6GameService.dll @ 10066d1a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueMarkedClDataRecordUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact marked-record builder ten-state FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10066d22 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMarkedRecordBuilderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueueMarkedClDataRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset first descriptor base at inherited EBP-3c.
// R6GameService.dll @ 10066d30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current first descriptor at inherited EBP-3c.
// R6GameService.dll @ 10066d38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset outer descriptor base at inherited EBP-54.
// R6GameService.dll @ 10066d40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current outer descriptor at inherited EBP-54.
// R6GameService.dll @ 10066d48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset unused third descriptor base at inherited EBP-24.
// R6GameService.dll @ 10066d50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full current unused descriptor at inherited EBP-24.
// R6GameService.dll @ 10066d58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered outer base at inherited EBP-54.
// R6GameService.dll @ 10066d60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Free CURRENT allocation through reused caller first argument at inherited EBP+4, then unwind three descriptors.
// R6GameService.dll @ 10066d68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Reset entered unused descriptor base at inherited EBP-24.
// R6GameService.dll @ 10066d72 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered outer base at inherited EBP-54.
// R6GameService.dll @ 10066d7a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl service_state_supportSharedLifetimeUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select shared ten-state FuncInfo for exactly three word-record builders and tail CRT dispatch.
// R6GameService.dll @ 10066d82 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectWordRecordBuildersEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::service_state_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset descriptor base at inherited EBP-24.
// R6GameService.dll @ 10066d90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass inherited EBP-31 cookie address to genuine no-op; preserve raw registers.
// R6GameService.dll @ 10066d98 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x31]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy full current descriptor at inherited EBP-24 before entered normal clear.
// R6GameService.dll @ 10066da0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor base at inherited EBP-24 after entered clear/head cleanup.
// R6GameService.dll @ 10066da8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten record argument twice; forward pointer+4 or explicit null for head-only cleanup, scratch EBP-28.
// R6GameService.dll @ 10066db0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch94
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch95
  Branch94:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch95:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Read CURRENT saved header context at inherited EBP-28 and tail genuine no-op; do not free head again.
// R6GameService.dll @ 10066dd7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractRecordDispatchCodeUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact six-state dispatch-code extractor FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10066ddf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDispatchCodeExtractorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ExtractRecordDispatchCodeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal marked-record builder ten-state cleanup map.
// R6GameService.dll data @ 100812b8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry QueueMarkedClDataRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind1},
  {-1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind2},
  {0x1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind3},
  {0x1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind4},
  {0x3, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind5},
  {0x3, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind6},
  {0x1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind7},
  {0x5, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind8},
  {0x3, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind9},
  {0x1, R6GameServiceAddresses::QueueMarkedClDataRecordUnwind10},
};

// Literal marked-record builder FuncInfo.
// R6GameService.dll data @ 10081308 : native storage identity retained.
const R6GameServiceNative::FuncInfo QueueMarkedClDataRecordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::QueueMarkedClDataRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal shared word-record builders cleanup map; third descriptor has a genuine unused lifetime.
// R6GameService.dll data @ 10081324 : native storage identity retained.
const R6GameServiceNative::UnwindEntry service_state_supportSharedLifetimeUnwindMap[10] = {
  {-1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind1},
  {-1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind2},
  {0x1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind3},
  {0x1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind4},
  {0x3, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind5},
  {0x3, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind6},
  {0x1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind7},
  {0x5, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind8},
  {0x3, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind9},
  {0x1, R6GameServiceAddresses::service_state_supportSharedLifetimeUnwind10},
};

// Literal shared word-record builders FuncInfo.
// R6GameService.dll data @ 10081374 : native storage identity retained.
const R6GameServiceNative::FuncInfo service_state_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::service_state_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal extractor cleanup map; construction1 traverses no-op1/base0, entered clear4 frees only current head.
// R6GameService.dll data @ 10081468 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ExtractRecordDispatchCodeUnwindMap[6] = {
  {-1, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind1},
  {0x0, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind2},
  {-1, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind3},
  {-1, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind4},
  {0x3, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind5},
  {0x3, R6GameServiceAddresses::ExtractRecordDispatchCodeUnwind6},
};

// Literal extractor FuncInfo.
// R6GameService.dll data @ 10081498 : native storage identity retained.
const R6GameServiceNative::FuncInfo ExtractRecordDispatchCodeExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::ExtractRecordDispatchCodeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 10040334 : native storage identity retained.
const uint GTransportRouteTargets[5] = {
  R6GameServiceAddresses::GTransportRouteTargetsCase1,R6GameServiceAddresses::GTransportRouteTargetsCase2,R6GameServiceAddresses::GTransportRouteTargetsCase3,R6GameServiceAddresses::GTransportRouteTargetsCase4,R6GameServiceAddresses::service_state_supportBranch73
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 10040348 : native storage identity retained.
const byte GTransportRouteIndices[222] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x1,0x1,0x0,0x1,0x1,0x1,
  0x1,0x4,0x4,0x1,0x1,0x4,0x4,0x1,0x4,0x1,0x1,0x4,0x0,0x4,0x4,0x4,
  0x4,0x0,0x4,0x4,0x1,0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x2,0x4,0x4,0x4,0x4,
  0x3,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x0
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 100405d8 : native storage identity retained.
const uint GTransportDispatchTargets[9] = {
  R6GameServiceAddresses::GTransportDispatchTargetsCase1,R6GameServiceAddresses::GTransportDispatchTargetsCase2,R6GameServiceAddresses::GTransportDispatchTargetsCase3,R6GameServiceAddresses::GTransportDispatchTargetsCase4,R6GameServiceAddresses::GTransportDispatchTargetsCase5,R6GameServiceAddresses::GTransportDispatchTargetsCase6,R6GameServiceAddresses::GTransportDispatchTargetsCase7,R6GameServiceAddresses::GTransportDispatchTargetsCase8,
  R6GameServiceAddresses::service_state_supportBranch80
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 100405fc : native storage identity retained.
const byte GTransportDispatchIndices[222] = {
  0x0,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x1,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x2,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x3,0x8,0x8,0x8,
  0x8,0x4,0x8,0x8,0x8,0x5,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x6,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,
  0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x7
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 10040a68 : native storage identity retained.
const uint GSecondaryDispatchTargets[17] = {
  R6GameServiceAddresses::GSecondaryDispatchTargetsCase1,R6GameServiceAddresses::GSecondaryDispatchTargetsCase2,R6GameServiceAddresses::GSecondaryDispatchTargetsCase3,R6GameServiceAddresses::GSecondaryDispatchTargetsCase4,R6GameServiceAddresses::GSecondaryDispatchTargetsCase5,R6GameServiceAddresses::GSecondaryDispatchTargetsCase6,R6GameServiceAddresses::GSecondaryDispatchTargetsCase7,R6GameServiceAddresses::GSecondaryDispatchTargetsCase8,
  R6GameServiceAddresses::GSecondaryDispatchTargetsCase9,R6GameServiceAddresses::GSecondaryDispatchTargetsCase10,R6GameServiceAddresses::GSecondaryDispatchTargetsCase11,R6GameServiceAddresses::GSecondaryDispatchTargetsCase12,R6GameServiceAddresses::GSecondaryDispatchTargetsCase13,R6GameServiceAddresses::GSecondaryDispatchTargetsCase14,R6GameServiceAddresses::GSecondaryDispatchTargetsCase15,R6GameServiceAddresses::GSecondaryDispatchTargetsCase16,
  R6GameServiceAddresses::service_state_supportBranch85
};

// Native switch table owned by its routing/dispatch parent.
// R6GameService.dll data @ 10040aac : native storage identity retained.
const byte GSecondaryDispatchIndices[145] = {
  0x0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x1,0x2,0x3,0x10,0x4,0x5,0x6,0x7,0x10,0x10,0x8,0x9,0x10,0x10,
  0xa,0x10,0xb,0xc,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xd,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xe,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0xf
};
