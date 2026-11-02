#include "native_addresses.h"
#include "native_records.h"

// CLobbySrvConnectionList: primary78064 -> COL7a0ec(offset0) -> type90354, .?AVCLobbySrvConnectionList@@.
// Constructor52d60 and typed allocation43de0 -> cached receiver+10 -> caller53090 -> producer54900 agree.

// Construct base with flag0, two empty12-byte lists and an168-byte indexed-tree header, then initialize owner fields.
// ENTRY ESP S: construction bitsS-18/savedownerS-14/currentmemberS-10/stateS-4. Initial full flag controls table+8;
// late current flag lowBYTE becomes tree+8, and late context DWORD becomes owner+1d0. RET8/owner EAX.
// Preserve untouched header/padding bytes, two129-byte zero buffers, eleven-state cleanup and no NULL repair.
// R6GameService.dll @ 10052d60 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CLobbySrvConnectionListConstruct(void *owner,uint context,uint initializeVirtualBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLobbyConnectionListCtorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x4],ebx
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    mov    esi,ecx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [esp+0x10],esi
    je     Branch1
    mov    DWORD PTR [esi+0x8],0x1007808c
    mov    DWORD PTR [esp+0xc],0x1
    mov    DWORD PTR [esp+0x20],ebx
  Branch1:
    push   ebx
    mov    ecx,esi
    call   R6GameServiceAddresses::CConnectionListConstruct
    mov    eax,DWORD PTR [esp+0xc]
    lea    edi,[esi+0x9c]
    or     al,0x2
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [edi+0x4],0x10078084
    mov    DWORD PTR [esp+0xc],eax
    lea    eax,[esp+0x2c]
    push   ebx
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],0x3
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edi,[esi+0xa4]
    or     ecx,0x4
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [edi+0x4],0x10078084
    mov    DWORD PTR [esp+0xc],ecx
    lea    ecx,[esp+0x2c]
    push   ebx
    push   ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],0x6
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    mov    eax,DWORD PTR [esp+0xc]
    lea    edi,[esi+0xac]
    or     al,0x8
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [edi+0xc],0x1007807c
    mov    DWORD PTR [esp+0xc],eax
    lea    edx,[esp+0x2c]
    push   ebx
    push   edx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],0x9
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xa8
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [edi],eax
    mov    al,BYTE PTR [esp+0x2c]
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0xa
    mov    DWORD PTR [edi+0x4],ebx
    mov    BYTE PTR [edi+0x8],al
    call   R6GameServiceAddresses::InitializeServiceTreeHeader
    mov    ecx,DWORD PTR [esp+0x28]
    lea    eax,[esi+0xbc]
    xor    edx,edx
    mov    DWORD PTR [esi],R6GameServiceAddresses::CLobbySrvConnectionListVTable
    mov    DWORD PTR [esi+0x1d0],ecx
    mov    BYTE PTR [esi+0x1d8],bl
    mov    DWORD PTR [eax],edx
    mov    ecx,0x20
    lea    edi,[esi+0xcc]
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [eax+0x8],edx
    mov    DWORD PTR [eax+0xc],edx
    xor    eax,eax
    rep    stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    mov    ecx,0x20
    xor    eax,eax
    lea    edi,[esi+0x14d]
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,DWORD PTR [esp+0x18]
    stos   BYTE PTR es:[edi],al
    mov    DWORD PTR [esi+0x1d4],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x8
  }
}

// If construction bit0 is set, tail the saved owner+1dc context to the genuine empty helper.
// R6GameService.dll @ 10068c50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test   eax,eax
    je     Branch2
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x1dc
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch2:
    ret
  }
}

// Destroy the base through CURRENT saved owner from inherited original ENTRY ESP.
// R6GameService.dll @ 10068c6d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::CConnectionListDestroy
  }
}

// If construction bit1 is set, tail CURRENT saved member pointer+8 to the genuine empty helper.
// R6GameService.dll @ 10068c75 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x2
    test   eax,eax
    je     Branch3
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch3:
    ret
  }
}

// Tail the original second-argument address (inherited ENTRY ESP+8) to the genuine empty helper.
// R6GameService.dll @ 10068c8f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind4(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release the list nodes/header at CURRENT saved owner+9c without destroying payloads.
// R6GameService.dll @ 10068c97 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x9c
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// If construction bit2 is set, tail CURRENT saved member pointer+8 to the genuine empty helper.
// R6GameService.dll @ 10068ca5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x4
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Tail the original second-argument address (inherited ENTRY ESP+8) to the genuine empty helper.
// R6GameService.dll @ 10068cbf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind7(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release the list nodes/header at CURRENT saved owner+a4 without destroying payloads.
// R6GameService.dll @ 10068cc7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa4
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// If construction bit3 is set, tail CURRENT saved member pointer+10 to the genuine empty helper.
// R6GameService.dll @ 10068cd5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x8
    test   eax,eax
    je     Branch5
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch5:
    ret
  }
}

// Tail the original second-argument address (inherited ENTRY ESP+8) to the genuine empty helper.
// R6GameService.dll @ 10068cef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind10(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Free CURRENT first word of CURRENT saved member slot; leave the slot dangling.
// R6GameService.dll @ 10068cf7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListConstructUnwind11(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the constructor eleven-state metadata and tail current CRT frame dispatch.
// R6GameService.dll @ 10068cff : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLobbyConnectionListCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CLobbySrvConnectionListConstructExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083708: exact constructor unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry CLobbySrvConnectionListConstructUnwindMap[11] = {
  {-1, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind1},
  {0x0, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind2},
  {0x1, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind3},
  {0x2, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind4},
  {0x1, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind5},
  {0x4, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind6},
  {0x5, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind7},
  {0x4, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind8},
  {0x7, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind9},
  {0x8, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind10},
  {0x9, R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwind11},
};

// R6GameService.dll data @ 10083760: exact constructor unwind map or FuncInfo.
// R6GameService.dll data @ 10083708 : native storage identity retained.
const R6GameServiceNative::FuncInfo CLobbySrvConnectionListConstructExceptionInfo = {
  0x19930520,
  0xb,
  R6GameServiceAddresses::CLobbySrvConnectionListConstructUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroy the class, then test CURRENT deleting flag lowBYTE/bit0; optionally free receiver and return it. RET4.
// R6GameService.dll @ 10052ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CLobbySrvConnectionListDelete(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::CLobbySrvConnectionListDestroy
    test   BYTE PTR [esp+0x8],0x1
    je     Branch6
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch6:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore the class table, clear owned lists and base range, then release indexed tree and list headers before base.
// ENTRY ESP S: saved ownerS-18/current cleanup slotS-10/stateS-4. State3 initially owns tree/lists/base.
// State4 may retry current tree header; states5/6 forward empty context without retrying the respective list.
// Preserve physical three-word virtual range call, current head reloads, dangling slots and final base raw EAX.
// R6GameService.dll @ 10052f00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CLobbySrvConnectionListDestroy(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLobbyConnectionListDestroyEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::CLobbySrvConnectionListVTable
    mov    DWORD PTR [esp+0x20],0x3
    call   R6GameServiceAddresses::ClearOwnedList9c
    mov    ecx,esi
    call   R6GameServiceAddresses::ClearOwnedLista4
    mov    edx,DWORD PTR [esi+0x4]
    push   ecx
    lea    ecx,[esi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],edx
    mov    edi,DWORD PTR [esi]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   DWORD PTR [edi+0x10]
    lea    edi,[esi+0xac]
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x4
    call   R6GameServiceAddresses::ClearIndexedTree
    mov    edi,DWORD PTR [edi]
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    edi,[esi+0xa4]
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x5
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edi,DWORD PTR [edi]
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    ebx,[esi+0x9c]
    mov    DWORD PTR [esp+0x14],ebx
    mov    eax,DWORD PTR [ebx]
    mov    BYTE PTR [esp+0x20],0x6
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je     Branch8
  Branch7:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   0x1
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    edi,DWORD PTR [ebx]
    jne    Branch7
  Branch8:
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [eax+0x4],eax
    mov    ebx,DWORD PTR [ebx]
    push   ebx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,esi
    mov    DWORD PTR [esp+0x20],0xffffffff
    call   R6GameServiceAddresses::CConnectionListDestroy
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x18
    ret
  }
}

// Clear owner+9c: delete optional payload+10 object, free current payload, unlink node and free it; retain head.
// Read payload and links again after callbacks; no rollback or own exception guard.
// R6GameService.dll @ 10053b80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearOwnedList9c(void *owner)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx+0x9c]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch11
    push   edi
  Branch9:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    je     Branch10
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
  Branch10:
    mov    eax,DWORD PTR [esi+0x8]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0x9c]
    mov    esi,edi
    cmp    edi,eax
    jne    Branch9
    pop    edi
  Branch11:
    pop    esi
    pop    ebx
    ret
  }
}

// Clear owner+a4 using the same live payload/deleting-call/unlink/free order; retain head and borrowed fields.
// R6GameService.dll @ 10053bd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearOwnedLista4(void *owner)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx+0xa4]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch14
    push   edi
  Branch12:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    je     Branch13
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
  Branch13:
    mov    eax,DWORD PTR [esi+0x8]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0xa4]
    mov    esi,edi
    cmp    edi,eax
    jne    Branch12
    pop    edi
  Branch14:
    pop    esi
    pop    ebx
    ret
  }
}

// Destroy the base through CURRENT saved owner from inherited original ENTRY ESP.
// R6GameService.dll @ 10068d10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::CConnectionListDestroy
  }
}

// Release remaining nodes/header at CURRENT saved owner+9c without destroying payloads.
// R6GameService.dll @ 10068d18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x9c
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Release remaining nodes/header at CURRENT saved owner+a4 without destroying payloads.
// R6GameService.dll @ 10068d26 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0xa4
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Destroy CURRENT saved owner+ac indexed tree through its genuine forwarding thunk.
// R6GameService.dll @ 10068d34 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0xac
    jmp    R6GameServiceAddresses::thunk_ReleaseIndexedTree
  }
}

// Free CURRENT first word of CURRENT saved cleanup slot; leave that slot dangling.
// R6GameService.dll @ 10068d42 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Tail CURRENT saved cleanup pointer to the empty helper without retrying the a4 list.
// R6GameService.dll @ 10068d4a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail CURRENT saved cleanup pointer to the empty helper without retrying the9c list.
// R6GameService.dll @ 10068d52 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CLobbySrvConnectionListDestroyUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select the class destructor seven-state metadata and tail current CRT dispatch.
// R6GameService.dll @ 10068d5a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLobbyConnectionListDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CLobbySrvConnectionListDestroyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1008377c: exact lifetime unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry CLobbySrvConnectionListDestroyUnwindMap[7] = {
  {-1, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind1},
  {0x0, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind2},
  {0x1, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind3},
  {0x2, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind4},
  {0x2, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind5},
  {0x1, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind6},
  {0x0, R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwind7},
};

// R6GameService.dll data @ 100837b4: exact lifetime unwind map or FuncInfo.
// R6GameService.dll data @ 1008377c : native storage identity retained.
const R6GameServiceNative::FuncInfo CLobbySrvConnectionListDestroyExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::CLobbySrvConnectionListDestroyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Insert a missing signed-key record through two local text/list records and the native hinted tree insertion.
// ENTRY ESP S: first textS-138/headS-b0, second keyS-a4/headS-18, saved cleanup pointerS-140/stateS-4.
// Copy 128 text bytes plus the untouched local 129th byte; reload key/WORD after strncpy, tail after list clone.
// Lists copy borrowed payload words. State3/4 do not retry the respective temporary after release begins.
// Duplicate clears AL only; success sets AL only after both temporary headers are freed. RET12.
// R6GameService.dll @ 10054900 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InsertIndexedTextRecord(void *owner,int key,const char *text,uint recordValue)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectIndexedRecordProducerEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x140
    push   ebx
    push   ebp
    push   esi
    xor    ebx,ebx
    lea    ebp,[ecx+0xac]
    lea    eax,[esp+0x15c]
    push   edi
    mov    DWORD PTR [esp+0x10],ebx
    mov    esi,DWORD PTR [ebp+0x0]
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::FindIndexedTreeKey
    cmp    eax,esi
    je     Branch15
    xor    al,al
    jmp    Branch18
  Branch15:
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [esp+0x10],ebx
    mov    eax,DWORD PTR [ecx+0x8]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    je     Branch17
  Branch16:
    mov    ecx,DWORD PTR [eax+0x10]
    mov    edx,DWORD PTR [esp+0x160]
    cmp    ecx,edx
    jg     Branch17
    push   eax
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ecx,DWORD PTR [ebp+0x0]
    add    esp,0x4
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    jne    Branch16
  Branch17:
    mov    DWORD PTR [esp+0xb0],0x100780a8
    lea    edx,[esp+0x17]
    lea    ecx,[esp+0xac]
    push   edx
    mov    DWORD PTR [esp+0x15c],ebx
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    eax,DWORD PTR [esp+0x164]
    push   0x80
    lea    ecx,[esp+0x28]
    push   eax
    push   ecx
    mov    DWORD PTR [esp+0x164],0x1
    mov    BYTE PTR [esp+0xb4],bl
    call   R6GameServiceAddresses::strncpy
    mov    ax,WORD PTR [esp+0x174]
    mov    edx,DWORD PTR [esp+0x16c]
    mov    ecx,0x20
    lea    esi,[esp+0x30]
    lea    edi,[esp+0xc8]
    mov    WORD PTR [esp+0xb2],ax
    mov    DWORD PTR [esp+0xc0],ebx
    mov    DWORD PTR [esp+0xc4],edx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    add    esp,0xc
    lea    ecx,[esp+0xac]
    movs   BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    WORD PTR [esp+0x13e],ax
    mov    al,BYTE PTR [esp+0xa8]
    push   0x1
    push   ecx
    lea    ecx,[esp+0x14c]
    mov    BYTE PTR [esp+0x148],al
    call   R6GameServiceAddresses::CloneCircularList
    mov    edx,DWORD PTR [esp+0xb4]
    mov    DWORD PTR [esp+0x14c],edx
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   eax
    mov    BYTE PTR [esp+0x15c],0x2
    call   R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0xb8]
    lea    edx,[esp+0x18]
    push   ecx
    push   ecx
    mov    ecx,esp
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    lea    eax,[esp+0x28]
    mov    ecx,ebp
    push   eax
    call   R6GameServiceAddresses::FindOrInsertIndexedTreeNode
    lea    ecx,[esp+0x144]
    mov    DWORD PTR [esp+0x1c],ecx
    lea    ecx,[esp+0x144]
    mov    BYTE PTR [esp+0x158],0x3
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edx,DWORD PTR [esp+0x144]
    push   0x1
    push   edx
    lea    ecx,[esp+0x14c]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    lea    eax,[esp+0xac]
    mov    DWORD PTR [esp+0x1c],eax
    lea    ecx,[esp+0xac]
    mov    DWORD PTR [esp+0x158],0x4
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    ecx,DWORD PTR [esp+0xac]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    al,0x1
  Branch18:
    mov    ecx,DWORD PTR [esp+0x150]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14c
    ret    0xc
  }
}


// Find the signed key, copy 128 text bytes without a trailing-NUL repair, then reload/store the low WORD at node+96.
// Return AL status with native upper residue: current head on miss, CRT high WORD and supplied high byte on success.
// R6GameService.dll @ 10054ba0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall UpdateIndexedRecordText(void *owner,int key,const char *text,uint recordValue)
{
  __asm {
    push   esi
    lea    esi,[ecx+0xac]
    lea    eax,[esp+0x8]
    push   edi
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::FindIndexedTreeKey
    mov    edi,eax
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    jne    Branch19
    pop    edi
    xor    al,al
    pop    esi
    ret    0xc
  Branch19:
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x80
    lea    edx,[edi+0x14]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::strncpy
    mov    ax,WORD PTR [esp+0x20]
    add    esp,0xc
    mov    WORD PTR [edi+0x96],ax
    mov    al,0x1
    pop    edi
    pop    esi
    ret    0xc
  }
}


// Forward the first temporary context from inherited original ENTRY ESP to the genuine empty helper.
// R6GameService.dll @ 10069030 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InsertIndexedTextRecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x145]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Release the first text record list using inherited original ENTRY ESP.
// R6GameService.dll @ 1006903b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InsertIndexedTextRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x138]
    jmp    R6GameServiceAddresses::ReleaseEmbeddedList88
  }
}


// Release the second keyed record list, then continue to state1 first-record cleanup.
// R6GameService.dll @ 10069046 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InsertIndexedTextRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0xa4]
    jmp    R6GameServiceAddresses::ReleaseEmbeddedList8c
  }
}


// Forward the current saved cleanup pointer; do not retry the second temporary list release.
// R6GameService.dll @ 10069051 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InsertIndexedTextRecordUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x140]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Forward the current saved cleanup pointer; do not retry the first temporary list release.
// R6GameService.dll @ 1006905c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InsertIndexedTextRecordUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x140]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Select the indexed-record producer five-state unwind metadata and tail current CRT frame dispatch.
// R6GameService.dll @ 10069067 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedRecordProducerEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InsertIndexedTextRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}


// R6GameService.dll data @ 10083a84: indexed-record producer unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry InsertIndexedTextRecordUnwindMap[5] = {
  {-1, R6GameServiceAddresses::InsertIndexedTextRecordUnwind1},
  {-1, R6GameServiceAddresses::InsertIndexedTextRecordUnwind2},
  {0x1, R6GameServiceAddresses::InsertIndexedTextRecordUnwind3},
  {0x1, R6GameServiceAddresses::InsertIndexedTextRecordUnwind4},
  {-1, R6GameServiceAddresses::InsertIndexedTextRecordUnwind5},
};

// R6GameService.dll data @ 10083aac: indexed-record producer unwind map or FuncInfo.
// R6GameService.dll data @ 10083a84 : native storage identity retained.
const R6GameServiceNative::FuncInfo InsertIndexedTextRecordExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::InsertIndexedTextRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Ensure the signed key exists, then append the value only if absent from its record list; ignore producer AL.
// Cache list end and scan value; append captures head in local ENTRY ESP-4 but reloads that scratch after allocation.
// Allocator reads CURRENT value argument; head previous is read after allocation. Only AL changes on return; RET8.
// No own exception guard: a record created before a failed list-node allocation remains committed.
// R6GameService.dll @ 10053090 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CLobbySrvConnectionListAppendUniqueWord(void *owner,uint recordValue,int mapKey)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    push   eax
    mov    esi,ecx
    call   R6GameServiceAddresses::ContainsIndexedKey
    test   al,al
    jne    Branch20
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x0
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertIndexedTextRecord
  Branch20:
    add    esi,0xac
    lea    edx,[esp+0x10]
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::FindIndexedTreeKey
    cmp    eax,DWORD PTR [esi]
    jne    Branch21
    xor    al,al
    pop    esi
    pop    ecx
    ret    0x8
  Branch21:
    mov    ecx,DWORD PTR [eax+0x9c]
    lea    esi,[eax+0x9c]
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je     Branch23
    mov    edx,DWORD PTR [esp+0xc]
  Branch22:
    cmp    DWORD PTR [eax+0x8],edx
    je     Branch24
    mov    eax,DWORD PTR [eax]
    cmp    eax,ecx
    jne    Branch22
  Branch23:
    lea    eax,[esp+0x4]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0xc]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch24:
    mov    al,0x1
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Remove the first matching value: capture end/value, unlink selected node before free, retain its record and payload.
// Preserve the native saved-record accessor call. Miss clears AL on tree/list head; success sets AL on free residue. RET8.
// R6GameService.dll @ 10053130 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveValueFromKeyList(void *owner,uint recordValue,int mapKey)
{
  __asm {
    push   ecx
    push   esi
    lea    esi,[ecx+0xac]
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::FindIndexedTreeKey
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x4],eax
    cmp    eax,ecx
    je     Branch26
    mov    eax,DWORD PTR [eax+0x9c]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch26
    mov    ecx,DWORD PTR [esp+0xc]
  Branch25:
    cmp    DWORD PTR [esi+0x8],ecx
    je     Branch27
    mov    esi,DWORD PTR [esi]
    cmp    esi,eax
    jne    Branch25
  Branch26:
    xor    al,al
    pop    esi
    pop    ecx
    ret    0x8
  Branch27:
    lea    ecx,[esp+0x4]
    call   R6GameServiceAddresses::GetReferencedStoragePlus10
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [eax+0x4],ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    al,0x1
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Search signed keys using captured head/key, then compare candidate with CURRENT head and replace AL only. RET4.
// R6GameService.dll @ 10053c20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ContainsIndexedKey(void *owner,int key)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0xac]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [edx+0x4]
    mov    esi,edx
    test   eax,eax
    je     Branch31
  Branch28:
    cmp    DWORD PTR [eax+0x10],edi
    jl     Branch29
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch30
  Branch29:
    mov    eax,DWORD PTR [eax+0xc]
  Branch30:
    test   eax,eax
    jne    Branch28
  Branch31:
    cmp    esi,edx
    je     Branch32
    cmp    edi,DWORD PTR [esi+0x10]
    jge    Branch33
  Branch32:
    mov    esi,edx
  Branch33:
    mov    eax,DWORD PTR [ecx+0xac]
    pop    edi
    cmp    esi,eax
    pop    esi
    setne  al
    ret    0x4
  }
}

// Service pending connections until none or notification AL0; capture now, then apply idle/global and per-key timers.
// Preserve physical iterator arguments, second time() on first global idle, x87 mask4100 and strict5/30 cutoffs.
// Reset only state2 records with empty value lists; cache now, read successor links/head after callbacks.
// Idle return uses masked comparison status/AL; active traversal returns final cursor upper bits/AL1. No own EH.
// R6GameService.dll @ 10053190 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ServicePendingRecordsAndExpireIdleKeys(void *owner)
{
  __asm {
    sub    esp,0xc
    push   ebp
    push   edi
    mov    edi,ecx
    call   R6GameServiceAddresses::CConnectionListFindFailingKey
    test   eax,eax
    je     Branch35
  Branch34:
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotifications
    test   al,al
    je     Branch35
    mov    ecx,edi
    call   R6GameServiceAddresses::CConnectionListFindFailingKey
    test   eax,eax
    jne    Branch34
  Branch35:
    push   0x0
    call   R6GameServiceAddresses::time
    mov    ebp,eax
    mov    eax,DWORD PTR [edi+0xb0]
    add    esp,0x4
    test   eax,eax
    jne    Branch37
    mov    eax,DWORD PTR [edi+0xa4]
    lea    ecx,[edi+0xa4]
    lea    edx,[esp+0x10]
    mov    DWORD PTR [esp+0xc],eax
    push   edx
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    cl,BYTE PTR [esp+0xb]
    lea    edx,[esp+0xb]
    mov    BYTE PTR [esp+0xb],cl
    lea    ecx,[esp+0xc]
    push   edx
    push   ecx
    push   eax
    call   R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    test   eax,eax
    jne    Branch37
    mov    eax,DWORD PTR [edi+0x1d4]
    test   eax,eax
    jne    Branch36
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    mov    DWORD PTR [edi+0x1d4],eax
  Branch36:
    mov    edx,DWORD PTR [edi+0x1d4]
    push   edx
    push   ebp
    call   R6GameServiceAddresses::difftime
    fcomp  QWORD PTR ds:R6GameServiceAddresses::NativeDouble5_0
    add    esp,0x8
    fnstsw ax
    and    eax,0x4100
    jne    Branch47
    pop    edi
    xor    al,al
    pop    ebp
    add    esp,0xc
    ret
  Branch37:
    mov    eax,DWORD PTR [edi+0xac]
    push   esi
    mov    DWORD PTR [edi+0x1d4],0x0
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch46
    push   ebx
    mov    bl,BYTE PTR [esp+0x13]
  Branch38:
    cmp    BYTE PTR [esi+0x98],0x2
    jne    Branch40
    mov    eax,DWORD PTR [esi+0x9c]
    lea    ecx,[esp+0x13]
    mov    DWORD PTR [esp+0x14],eax
    lea    edx,[esp+0x14]
    mov    eax,DWORD PTR [eax]
    push   ecx
    mov    DWORD PTR [esp+0x1c],eax
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    mov    BYTE PTR [esp+0x1f],bl
    call   R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    test   eax,eax
    jne    Branch40
    mov    eax,DWORD PTR [esi+0xa4]
    test   eax,eax
    jne    Branch39
    mov    DWORD PTR [esi+0xa4],ebp
    jmp    Branch40
  Branch39:
    push   eax
    push   ebp
    call   R6GameServiceAddresses::difftime
    fcomp  QWORD PTR ds:R6GameServiceAddresses::NativeDouble30_0
    add    esp,0x8
    fnstsw ax
    and    eax,0x4100
    jne    Branch40
    mov    ecx,DWORD PTR [esi+0x10]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ResetIndexedRecordState
  Branch40:
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    test   ecx,ecx
    je     Branch42
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch45
  Branch41:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch41
    jmp    Branch45
  Branch42:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch44
  Branch43:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch43
  Branch44:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch45
    mov    eax,ecx
  Branch45:
    mov    ecx,DWORD PTR [edi+0xac]
    mov    esi,eax
    cmp    eax,ecx
    jne    Branch38
    pop    ebx
  Branch46:
    pop    esi
  Branch47:
    pop    edi
    mov    al,0x1
    pop    ebp
    add    esp,0xc
    ret
  }
}

// Find signed key, clear selected record stateBYTE98/timestampDWORDa4, then call base key removal with live key.
// Miss clears only lookup AL; found returns base raw EAX. Field resets precede base failure; RET4.
// R6GameService.dll @ 10053b40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResetIndexedRecordState(void *owner,int key)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   edi
    lea    eax,[esp+0xc]
    lea    edi,[esi+0xac]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::FindIndexedTreeKey
    cmp    eax,DWORD PTR [edi]
    jne    Branch48
    pop    edi
    xor    al,al
    pop    esi
    ret    0x4
  Branch48:
    xor    ecx,ecx
    mov    BYTE PTR [eax+0x98],cl
    mov    DWORD PTR [eax+0xa4],ecx
    mov    ecx,DWORD PTR [esp+0xc]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CConnectionListQueryKey
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Scan current +9c records for cached key; send each match, delete its CURRENT child and free CURRENT record.
// Forward opcode AL with record-pointer upper bytes and mode DL with live EDX upper bytes; ignore send status.
// Read links after callbacks, unlink/free node, compare CURRENT owner head; preserve raw EAX and RET4. No local EH.
// R6GameService.dll @ 10053670 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveMatchingKeyRecords(void *owner,int key)
{
  __asm {
    push   ebp
    mov    ebp,ecx
    mov    eax,DWORD PTR [ebp+0x9c]
    mov    ecx,DWORD PTR [eax]
    cmp    ecx,eax
    je     Branch52
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   esi
    push   edi
  Branch49:
    mov    esi,ecx
    mov    ecx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [esi+0x8]
    cmp    DWORD PTR [eax+0x4],ebx
    jne    Branch51
    mov    ecx,DWORD PTR [eax+0x10]
    mov    dl,BYTE PTR [eax+0xc]
    mov    al,BYTE PTR [eax+0x8]
    push   ecx
    push   edx
    push   eax
    push   ebx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CConnectionListSendToKey
    mov    ecx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [ecx+0x10]
    test   ecx,ecx
    je     Branch50
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
  Branch50:
    mov    eax,DWORD PTR [esi+0x8]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,edi
  Branch51:
    cmp    ecx,DWORD PTR [ebp+0x9c]
    jne    Branch49
    pop    edi
    pop    esi
    pop    ebx
  Branch52:
    pop    ebp
    ret    0x4
  }
}

// Insert/update current keyed text, then connect only an existing indexed state1 record without a connection.
// A full-zero connection lookup miss leaves port upper EAX zero before MOV AX; preserve all physical words.
// Build two descriptor locals, append name/boolean/text/text/low16 word, send D2, and notify reason10/11 on failure.
// ENTRY ESP S: descriptorsS-3c/S-24, stateS-4; original enabled argument becomes bool then low16 trailing scratch.
// Preserve live key/arguments, cached record/connection, eight-state cleanup and last allocator upper EAX/RET20.
// R6GameService.dll @ 100536e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall UpdateKeyedTextAndNotify(
    void *owner,void *keyObject,const char *inputText,uint recordMode,uint enabledFlag,uint trailingWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLobbyUpdateEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    mov    eax,DWORD PTR [esp+0x44]
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    ebx,ebx
    push   eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],ebx
    call   R6GameServiceAddresses::ContainsIndexedKey
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x58]
    test   al,al
    mov    eax,DWORD PTR [esp+0x54]
    push   ecx
    push   edx
    mov    ecx,esi
    push   eax
    jne    Branch55
    call   R6GameServiceAddresses::InsertIndexedTextRecord
    test   al,al
    jne    Branch56
  Branch53:
    xor    al,al
  Branch54:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch55:
    call   R6GameServiceAddresses::UpdateIndexedRecordText
  Branch56:
    lea    ecx,[esp+0x54]
    lea    ebp,[esi+0xac]
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::FindIndexedTreeKey
    mov    edi,eax
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    edi,eax
    je     Branch53
    mov    edx,DWORD PTR [esp+0x54]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::CConnectionListFindBorrowed
    test   eax,eax
    jne    Branch53
    cmp    BYTE PTR [edi+0x98],0x1
    jne    Branch53
    mov    edx,DWORD PTR [esp+0x54]
    mov    ax,WORD PTR [edi+0x96]
    push   ebx
    push   edx
    push   0x1e
    lea    ecx,[edi+0x14]
    push   0x2
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CConnectionListInsertConfigured
    test   al,al
    jne    Branch57
    mov    BYTE PTR [edi+0x98],al
    mov    eax,DWORD PTR [esp+0x54]
    push   0x10
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::NotifyAndRemoveKeyRecords
    jmp    Branch53
  Branch57:
    mov    ecx,DWORD PTR [esp+0x54]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CConnectionListFindBorrowed
    mov    ebp,eax
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],ebx
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],ebx
    lea    edx,[esi+0xbc]
    lea    ecx,[esp+0x14]
    push   edx
    mov    BYTE PTR [esp+0x50],0x3
    call   R6GameServiceAddresses::AppendClDataListString
    mov    cl,BYTE PTR [esp+0x60]
    xor    eax,eax
    test   cl,cl
    lea    ecx,[esp+0x60]
    setne  al
    push   ecx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x64],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esi+0xcc]
    lea    ecx,[esp+0x14]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListString
    lea    eax,[esi+0x14d]
    lea    ecx,[esp+0x14]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListString
    mov    ecx,DWORD PTR [esp+0x64]
    lea    edx,[esp+0x60]
    and    ecx,0xffff
    push   edx
    mov    DWORD PTR [esp+0x64],ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x14]
    mov    ecx,ebp
    push   eax
    push   0x2
    push   0xd2
    call   R6GameServiceAddresses::SendTransportPayload
    test   al,al
    jne    Branch58
    mov    BYTE PTR [edi+0x98],al
    mov    ecx,DWORD PTR [esp+0x54]
    push   0x11
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::NotifyAndRemoveKeyRecords
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x2c],esi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esp+0x20],ebx
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x5
    call   R6GameServiceAddresses::DestroyClDataPointerList
    jmp    Branch53
  Branch58:
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x2c],esi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esp+0x20],ebx
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x7
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
    jmp    Branch54
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068df0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068df8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the exact temporary descriptor from inherited original ENTRY ESP; base-only states do not retry lists.
// R6GameService.dll @ 10068e28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateKeyedTextAndNotifyUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the lobby update eight-state metadata and tail current CRT dispatch.
// R6GameService.dll @ 10068e30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLobbyUpdateEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UpdateKeyedTextAndNotifyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083860: exact lobby update unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry UpdateKeyedTextAndNotifyUnwindMap[8] = {
  {-1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind1},
  {-1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind2},
  {0x1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind3},
  {0x1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind4},
  {0x1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind5},
  {-1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind6},
  {0x1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind7},
  {-1, R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwind8},
};

// R6GameService.dll data @ 100838a0: exact lobby update unwind map or FuncInfo.
const R6GameServiceNative::FuncInfo UpdateKeyedTextAndNotifyExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::UpdateKeyedTextAndNotifyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Return a record from the first priority queue entry; empty queue falls back to connection-message collection.
// Cache the first payload pair before allocation, then reload its payload for the kind byte and descriptor pointer.
// The full kind word keeps current ECX upper bits; only its low byte is meaningful to the actual constructor.
// ENTRY ESP S: allocationS-10/stateS-4. Disarm before unchecked result+18 store and matching-pair removal.
// R6GameService.dll @ 10053c70 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__fastcall BuildRecordFromQueueHeadOrFallback(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLobbyFallbackEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   edi
    mov    edi,ecx
    lea    ecx,[esp+0x7]
    lea    edx,[esp+0x8]
    mov    eax,DWORD PTR [edi+0xa4]
    push   ecx
    mov    DWORD PTR [esp+0xc],eax
    push   edx
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x14],eax
    mov    al,BYTE PTR [esp+0xf]
    mov    BYTE PTR [esp+0xf],al
    lea    eax,[esp+0x14]
    push   eax
    call   R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    test   eax,eax
    je     Branch61
    mov    ecx,DWORD PTR [edi+0xa4]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [ecx]
    push   0x1c
    mov    eax,DWORD PTR [esi+0x8]
    mov    ebp,DWORD PTR [eax]
    mov    ebx,DWORD PTR [eax+0x4]
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x1c],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x28],0x0
    je     Branch59
    mov    esi,DWORD PTR [esi+0x8]
    push   0x1
    push   0x0
    mov    edx,DWORD PTR [esi+0x10]
    mov    cl,BYTE PTR [esi+0x8]
    push   edx
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    mov    esi,eax
    jmp    Branch60
  Branch59:
    xor    esi,esi
  Branch60:
    push   ebp
    push   ebx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x30],0xffffffff
    mov    DWORD PTR [esi+0x18],ebx
    call   R6GameServiceAddresses::RemoveListRecordsByWordPair
    mov    eax,esi
    pop    esi
    pop    ebp
    pop    ebx
    pop    edi
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret
  Branch61:
    mov    ecx,edi
    call   R6GameServiceAddresses::CConnectionListCollectMessages
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret
  }
}

// Free the current raw allocation saved at original parent ENTRY ESP-10 on constructor failure.
// R6GameService.dll @ 10068e90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl BuildRecordFromQueueHeadOrFallbackUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select the queue fallback allocation guard metadata and tail CRT dispatch.
// R6GameService.dll @ 10068e9a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLobbyFallbackEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::BuildRecordFromQueueHeadOrFallbackExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal lobby fallback allocation unwind map or FuncInfo.
// R6GameService.dll data @ 10083918 : native storage identity retained.
const R6GameServiceNative::UnwindEntry BuildRecordFromQueueHeadOrFallbackUnwindMap[1] = {
  {-1, R6GameServiceAddresses::BuildRecordFromQueueHeadOrFallbackUnwind1},
};

// Literal lobby fallback allocation unwind map or FuncInfo.
// R6GameService.dll data @ 10083918 : native storage identity retained.
const R6GameServiceNative::FuncInfo BuildRecordFromQueueHeadOrFallbackExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::BuildRecordFromQueueHeadOrFallbackUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Queue 0x37 per current linked value, free those links, optionally queue0x12/reset state2, then erase the record.
// Empty post-erase index queues0x2b with the CURRENT key. Notification packets are full words 2/value/key/d1/0,
// plus a24-byte copied descriptor; final empty notification has value/key0 but retains key inside nested payload.
// ENTRY ESP S: iterator S-4c, scratch S-48, descriptors S-24/S-3c, registration S-c, state S-4. RET4/raw EAX.
// Cache found node; reload current list heads/next/key around calls. No rollback after queue/free/reset/erase failure.
// R6GameService.dll @ 10053d50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveIndexedRecordAndQueueNotifications(void *owner,uint key)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLobbyRemovalEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x40
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   0x0
    mov    DWORD PTR [esp+0x10],0x0
    push   0x3
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x40],ebp
    mov    DWORD PTR [esp+0x50],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x58],0x0
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_LAB
    push   0x0
    push   0x3
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x5c],0x1
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x38],esi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x58],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ebp,[edi+0xac]
    lea    eax,[esp+0x5c]
    push   eax
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x58],0x3
    call   R6GameServiceAddresses::FindIndexedTreeKey
    mov    esi,eax
    mov    eax,DWORD PTR [ebp+0x0]
    cmp    esi,eax
    jne    Branch62
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x54],0x1
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x54],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0x4c
    ret    0x4
  Branch62:
    mov    ecx,DWORD PTR [esi+0x9c]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0xc],eax
    mov    ecx,DWORD PTR [esi+0x9c]
    cmp    eax,ecx
    je    Branch64
  Branch63:
    add    eax,0x8
    lea    ecx,[esp+0x34]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x5c]
    lea    ecx,[esp+0x34]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x1c]
    push   eax
    mov    DWORD PTR [esp+0x14],0x37
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x34]
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    edx,[esp+0x34]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x28],esp
    push   0x1
    push   edx
    call   R6GameServiceAddresses::CopyConstructClDataList
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x6c],0x3
    call   R6GameServiceAddresses::GetReferencedStoragePlus8
    mov    ecx,DWORD PTR [esp+0x74]
    mov    edx,DWORD PTR [eax]
    push   0x0
    push   0xd1
    push   ecx
    push   edx
    push   0x2
    mov    ecx,edi
    call   R6GameServiceAddresses::QueueTaggedRecord
    push   ecx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR [esp+0x4c]
    lea    ecx,[esp+0x50]
    lea    ebp,[edx+0x10]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x1c]
    lea    ecx,[esp+0x48]
    push   eax
    call   DWORD PTR [ebp+0x0]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x30]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR [esp+0x34]
    lea    ecx,[esp+0x38]
    lea    ebp,[edx+0x10]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0x30]
    push   eax
    call   DWORD PTR [ebp+0x0]
    mov    ecx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0xc],eax
    mov    ecx,DWORD PTR [esi+0x9c]
    cmp    eax,ecx
    jne    Branch63
  Branch64:
    mov    eax,DWORD PTR [esi+0x9c]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je    Branch66
  Branch65:
    mov    eax,ebp
    mov    ebp,DWORD PTR [ebp+0x0]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    ebp,DWORD PTR [esi+0x9c]
    jne    Branch65
  Branch66:
    mov    eax,DWORD PTR [esi+0x9c]
    mov    ecx,edi
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi+0x9c]
    mov    DWORD PTR [eax+0x4],eax
    mov    edx,DWORD PTR [esp+0x5c]
    push   edx
    call   R6GameServiceAddresses::IndexedRecordHasState2
    test   al,al
    je    Branch67
    lea    eax,[esp+0x5c]
    lea    ecx,[esp+0x34]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x10],0x12
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x34]
    lea    ecx,[esp+0x1c]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    eax,[esp+0x34]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x30],esp
    push   0x1
    push   eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    mov    ecx,DWORD PTR [esp+0x74]
    push   0x0
    push   0xd1
    push   ecx
    push   0x0
    push   0x2
    mov    ecx,edi
    call   R6GameServiceAddresses::QueueTaggedRecord
    mov    edx,DWORD PTR [esp+0x5c]
    mov    ecx,edi
    push   edx
    call   R6GameServiceAddresses::ResetIndexedRecordState
  Branch67:
    push   ecx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR [esp+0x4c]
    lea    ecx,[esp+0x50]
    lea    ebp,[edx+0x10]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0x48]
    push   eax
    call   DWORD PTR [ebp+0x0]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x30]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR [esp+0x34]
    lea    ecx,[esp+0x38]
    lea    ebp,[edx+0x10]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0x30]
    push   eax
    call   DWORD PTR [ebp+0x0]
    push   ecx
    lea    ecx,[edi+0xac]
    mov    eax,esp
    mov    DWORD PTR [eax],esi
    call   R6GameServiceAddresses::EraseIndexedNode
    mov    eax,DWORD PTR [edi+0xb0]
    test   eax,eax
    jne    Branch68
    lea    ecx,[esp+0x5c]
    push   ecx
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x1c]
    push   edx
    mov    DWORD PTR [esp+0x14],0x2b
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x1c]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    edx,[esp+0x34]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x30],esp
    push   0x1
    push   edx
    call   R6GameServiceAddresses::CopyConstructClDataList
    push   0x0
    push   0xd1
    push   0x0
    push   0x0
    push   0x2
    mov    ecx,edi
    call   R6GameServiceAddresses::QueueTaggedRecord
  Branch68:
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    esi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x28],esi
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x54],0x5
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x34],edi
    mov    DWORD PTR [esp+0x40],esi
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x54],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x4c]
    pop    edi
    pop    esi
    mov    al,0x1
    mov    DWORD PTR fs:0x0,ecx
    pop    ebp
    add    esp,0x4c
    ret    0x4
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068eb8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068ec8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068ed0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068ed8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean the descriptor selected by inherited original ENTRY ESP; base-only states do not retry list cleanup.
// R6GameService.dll @ 10068ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveIndexedRecordAndQueueNotificationsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the seven-state record-removal map and tail-forward to CRT exception dispatch.
// R6GameService.dll @ 10068ee8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLobbyRemovalEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native unwind map; preserve states reached during partial construction and cleanup.
// R6GameService.dll data @ 1008393c : native storage identity retained.
const R6GameServiceNative::UnwindEntry RemoveIndexedRecordAndQueueNotificationsUnwindMap[7] = {
  {-1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind1},
  {-1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind2},
  {0x1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind3},
  {0x1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind4},
  {0x3, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind5},
  {0x1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind6},
  {-1, R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwind7},
};

// Literal native FuncInfo; preserve states reached during partial construction and cleanup.
// R6GameService.dll data @ 1008393c : native storage identity retained.
const R6GameServiceNative::FuncInfo RemoveIndexedRecordAndQueueNotificationsExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Physical six-word descriptor argument; this C++ interface name is descriptive.
struct NativeDescriptorArgument24 { undefined4 words[6]; };

// Queue an unmatched-key notification, queue a matched inactive record, or send through its active record.
// Keep incoming descriptor ownership, three local lists, live argument reads, raw send AL and eight-state cleanup.
// R6GameService.dll @ 100542a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ApplyIndexedKeyUpdate(void *owner,uint value,uint key,uint code,
                                               uint modeWord,NativeDescriptorArgument24 descriptor)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectKeyUpdateEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x58
    push    ebx
    push    ebp
    xor    ebx,ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x18],ebx
    push    ebx
    push    0x3
    lea    ecx,[esp+0x58]
    mov    DWORD PTR [esp+0x78],ebx
    mov    DWORD PTR [esp+0x5c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x6c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x60]
    mov    BYTE PTR [esp+0x74],0x1
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x50],ebp
    mov    DWORD PTR [esp+0x5c],edi
    push    ebx
    push    0x3
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x78],0x2
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x74],0x3
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x20],ebp
    mov    DWORD PTR [esp+0x2c],edi
    push    ebx
    push    0x3
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x78],0x4
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x54],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x74],0x5
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x38],ebp
    mov    DWORD PTR [esp+0x44],edi
    mov    eax,DWORD PTR [esp+0x7c]
    mov    ecx,esi
    push    eax
    mov    BYTE PTR [esp+0x74],0x6
    call    R6GameServiceAddresses::ContainsIndexedKey
    test    al,al
    jne    Branch69
    mov    ecx,DWORD PTR [esp+0x7c]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::RemoveListRecordsBySecondWord
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x38]
    push    edx
    mov    DWORD PTR [esp+0x18],0x13
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x78]
    lea    ecx,[esp+0x38]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x80]
    push    ecx
    lea    ecx,[esp+0x54]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x38]
    lea    ecx,[esp+0x50]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x20]
    push    eax
    mov    DWORD PTR [esp+0x18],0x27
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x50]
    push    ecx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    edx,[esp+0x38]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x2c],esp
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    eax,DWORD PTR [esp+0x9c]
    mov    ecx,DWORD PTR [esp+0x94]
    mov    edx,DWORD PTR [esp+0x90]
    push    eax
    push    0xd1
    push    ecx
    push    edx
    push    0x2
    mov    ecx,esi
    call    R6GameServiceAddresses::QueueTaggedRecord
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x70],0x4
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x70],bl
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x88]
    mov    DWORD PTR [esp+0x70],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch73
  Branch69:
    lea    eax,[esp+0x7c]
    lea    ecx,[esp+0x14]
    push    eax
    push    ecx
    lea    ecx,[esi+0xac]
    call    R6GameServiceAddresses::FindIndexedTreeLowerBound
    mov    edx,DWORD PTR [esp+0x7c]
    mov    ecx,esi
    push    edx
    call    R6GameServiceAddresses::CConnectionListFindBorrowed
    test    eax,eax
    jne    Branch71
    mov    eax,DWORD PTR [esp+0x14]
    cmp    BYTE PTR [eax+0x98],bl
    jne    Branch70
    mov    ecx,DWORD PTR [esp+0x7c]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::SendKeyNotificationD1
  Branch70:
    lea    edx,[esp+0x80]
    lea    ecx,[esp+0x20]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x88]
    lea    ecx,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    edx,[esp+0x38]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x30],esp
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    eax,DWORD PTR [esp+0x9c]
    mov    ecx,DWORD PTR [esp+0x94]
    mov    edx,DWORD PTR [esp+0x90]
    push    eax
    push    0xd1
    push    ecx
    push    edx
    push    0x1
    mov    ecx,esi
    call    R6GameServiceAddresses::QueueTaggedRecord
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x70],0x4
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x70],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x88],ebp
    mov    DWORD PTR [esp+0x94],edi
    lea    ecx,[esp+0x94]
    mov    DWORD PTR [esp+0x70],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
    jmp    Branch73
  Branch71:
    mov    edi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [edi+0x9c]
    lea    ecx,[edi+0x9c]
    mov    DWORD PTR [esp+0x18],eax
    lea    eax,[esp+0x1c]
    push    eax
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    cl,BYTE PTR [esp+0x7c]
    lea    edx,[esp+0x13]
    mov    BYTE PTR [esp+0x13],cl
    lea    ecx,[esp+0x18]
    push    edx
    push    ecx
    push    eax
    call    R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    cmp    eax,ebx
    jne    Branch72
    mov    DWORD PTR [edi+0xa4],ebx
  Branch72:
    lea    edx,[esp+0x80]
    lea    ecx,[esp+0x20]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x88]
    lea    ecx,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListCopy
    mov    edx,DWORD PTR [esp+0x84]
    mov    eax,DWORD PTR [esp+0x7c]
    lea    ecx,[esp+0x20]
    push    ecx
    push    edx
    push    0xd1
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::CConnectionListSendToKey
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x84],al
    mov    BYTE PTR [esp+0x70],0x4
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x70],bl
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x88]
    mov    DWORD PTR [esp+0x70],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    al,BYTE PTR [esp+0x84]
  Branch73:
    mov    ecx,DWORD PTR [esp+0x68]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x64
    ret    0x28
  }
}

// Destroy the incoming by-value descriptor at inherited EBP+0x14.
// R6GameService.dll @ 10068f00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x14]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset first local descriptor base at EBP-0x24 after interrupted construction.
// R6GameService.dll @ 10068f08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed first local descriptor at inherited EBP-0x24.
// R6GameService.dll @ 10068f10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset second local descriptor base at EBP-0x54 after interrupted construction.
// R6GameService.dll @ 10068f18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed second local descriptor at inherited EBP-0x54.
// R6GameService.dll @ 10068f20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset third local descriptor base at EBP-0x3c after interrupted construction.
// R6GameService.dll @ 10068f28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed third local descriptor at inherited EBP-0x3c.
// R6GameService.dll @ 10068f30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset incoming descriptor base at EBP+0x14 after entered list destruction; do not retry its list.
// R6GameService.dll @ 10068f38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplyIndexedKeyUpdateUnwind8(void)
{
  __asm {
    lea    ecx,[ebp+0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the eight-state request-consumer lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10068f40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyUpdateEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ApplyIndexedKeyUpdateExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal request-consumer unwind/FuncInfo words.
// R6GameService.dll data @ 10083990 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ApplyIndexedKeyUpdateUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind1},
  {0x0, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind2},
  {0x0, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind3},
  {0x2, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind4},
  {0x2, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind5},
  {0x4, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind6},
  {0x4, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind7},
  {-1, R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwind8},
};

// Literal request-consumer unwind/FuncInfo words.
// R6GameService.dll data @ 100839d0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ApplyIndexedKeyUpdateExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ApplyIndexedKeyUpdateUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Allocate record/clone storage, initialize late-read fields, publish under cached flags and consume incoming list.
// Preserve unguarded record allocation, nullable clone result, captured list heads and rewritten byte-field argument.
// R6GameService.dll @ 10054660 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueTaggedRecord(void *owner,uint flags,uint value,uint key,uint opcode,
                                          uint byteField,NativeDescriptorArgument24 payload)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectQueuedRecordEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    mov    edi,ecx
    xor    ebx,ebx
    push    0x14
    mov    DWORD PTR [esp+0x20],ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    0x18
    mov    DWORD PTR [esp+0x10],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x1c],0x1
    je    Branch74
    lea    ecx,[esp+0x38]
    push    0x1
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::CopyConstructClDataList
    jmp    Branch75
  Branch74:
    xor    eax,eax
  Branch75:
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    BYTE PTR [esp+0x1c],bl
    mov    bl,BYTE PTR [esp+0x24]
    mov    DWORD PTR [edx],ecx
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx+0x4],ecx
    mov    edx,DWORD PTR [esp+0xc]
    mov    cl,BYTE PTR [esp+0x34]
    mov    DWORD PTR [edx+0x10],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x30]
    mov    BYTE PTR [eax+0xc],cl
    mov    eax,DWORD PTR [esp+0xc]
    and    edx,0xff
    test    bl,0x2
    mov    DWORD PTR [eax+0x8],edx
    je    Branch76
    lea    ecx,[esp+0x34]
    lea    esi,[edi+0xa4]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0xc]
    mov    ecx,esi
    push    edx
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch76:
    test    bl,0x1
    je    Branch77
    lea    esi,[edi+0x9c]
    lea    eax,[esp+0x34]
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0xc]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch77:
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x44]
    mov    DWORD PTR [esp+0x1c],0x2
    mov    DWORD PTR [esp+0x34],edx
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::clDataListPTR_FUN2
    push    ecx
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    eax,esp
    push    ecx
    push    esp
    mov    BYTE PTR [esp+0x28],0x3
    mov    DWORD PTR [eax],ecx
    lea    ecx,[esp+0x54]
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    eax,DWORD PTR [esp+0x4c]
    lea    edx,[esp+0x30]
    push    edx
    lea    ecx,[esp+0x50]
    call    DWORD PTR [eax+0x10]
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x1c],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret    0x2c
  }
}

// Build selector/incoming descriptor, send D1 with full mode, then release local/incoming lists while retaining sender AL.
// Preserve rewritten mode-word cleanup context and eight-state lifetimes; upper EAX comes from final release.
// R6GameService.dll @ 100547d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendDescriptorAsD1(void *owner,uint selector,uint modeWord,
                                         NativeDescriptorArgument24 descriptor)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectD1SenderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    ebx
    xor    eax,eax
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0xc],eax
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x30],eax
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0xb]
    lea    ecx,[esp+0x20]
    push    eax
    mov    BYTE PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x30],bl
    push    ecx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x40]
    lea    ecx,[esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListCopy
    mov    ecx,DWORD PTR [esp+0x3c]
    lea    eax,[esp+0x10]
    push    eax
    push    ecx
    push    0xd1
    mov    ecx,esi
    call    R6GameServiceAddresses::CConnectionListBroadcast
    mov    bl,al
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x1c]
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],esi
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_FUN
    lea    eax,[esp+0x4c]
    mov    DWORD PTR [esp+0x30],0x6
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x4c],esi
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x30],0x7
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    mov    al,bl
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x20
  }
}

// Destroy the builder incoming descriptor at inherited EBP+0x18.
// R6GameService.dll @ 10068f50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueTaggedRecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x18]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Free only the raw clone allocation captured at EBP-0x10; the raw record allocation has no guard.
// R6GameService.dll @ 10068f58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueTaggedRecordUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Reset incoming builder descriptor base at EBP+0x18 after entered pointer-list destruction.
// R6GameService.dll @ 10068f62 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueTaggedRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp+0x18]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release the current head slot through rewritten argument EBP+0x14, publishing scratchEBP-0x60; preserve NULL.
// R6GameService.dll @ 10068f6a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl QueueTaggedRecordUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x14],0x0
    je    Branch78
    mov    eax,DWORD PTR [ebp+0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch79
  Branch78:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch79:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Destroy the sender incoming descriptor at inherited EBP+0xc.
// R6GameService.dll @ 10068fa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind1(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset sender local descriptor base at EBP-0x24 after interrupted construction.
// R6GameService.dll @ 10068fa8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forward the inherited cookie byte at EBP-0x29 to the native empty helper.
// R6GameService.dll @ 10068fb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x29]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy the completed sender local descriptor at inherited EBP-0x24.
// R6GameService.dll @ 10068fb8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset sender local base at EBP-0x24 after entered list destruction.
// R6GameService.dll @ 10068fc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release current head slot through rewritten mode argument EBP+8 and publish scratchEBP-0x40; preserve NULL.
// R6GameService.dll @ 10068fc8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch80
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x40],eax
    jmp    Branch81
  Branch80:
    mov    DWORD PTR [ebp-0x40],0x0
  Branch81:
    mov    ecx,DWORD PTR [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset sender incoming base at EBP+0xc after entered list destruction.
// R6GameService.dll @ 10068fef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind7(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release current head slot through rewritten mode argument EBP+8 and publish scratchEBP-0x48; preserve NULL.
// R6GameService.dll @ 10068ff7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendDescriptorAsD1Unwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch82
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x48],eax
    jmp    Branch83
  Branch82:
    mov    DWORD PTR [ebp-0x48],0x0
  Branch83:
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact owned-argument lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10068f91 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectQueuedRecordEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueueTaggedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the exact owned-argument lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 1006901e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectD1SenderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendDescriptorAsD1ExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal queued-record/sender unwind or FuncInfo words.
// R6GameService.dll data @ 100839ec : native storage identity retained.
const R6GameServiceNative::UnwindEntry QueueTaggedRecordUnwindMap[4] = {
  {-1, R6GameServiceAddresses::QueueTaggedRecordUnwind1},
  {0x0, R6GameServiceAddresses::QueueTaggedRecordUnwind2},
  {-1, R6GameServiceAddresses::QueueTaggedRecordUnwind3},
  {0x2, R6GameServiceAddresses::QueueTaggedRecordUnwind4},
};

// Literal queued-record/sender unwind or FuncInfo words.
// R6GameService.dll data @ 10083a0c : native storage identity retained.
const R6GameServiceNative::FuncInfo QueueTaggedRecordExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::QueueTaggedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal queued-record/sender unwind or FuncInfo words.
// R6GameService.dll data @ 10083a28 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendDescriptorAsD1UnwindMap[8] = {
  {-1, R6GameServiceAddresses::SendDescriptorAsD1Unwind1},
  {0x0, R6GameServiceAddresses::SendDescriptorAsD1Unwind2},
  {0x1, R6GameServiceAddresses::SendDescriptorAsD1Unwind3},
  {0x0, R6GameServiceAddresses::SendDescriptorAsD1Unwind4},
  {0x0, R6GameServiceAddresses::SendDescriptorAsD1Unwind5},
  {0x4, R6GameServiceAddresses::SendDescriptorAsD1Unwind6},
  {-1, R6GameServiceAddresses::SendDescriptorAsD1Unwind7},
  {0x6, R6GameServiceAddresses::SendDescriptorAsD1Unwind8},
};

// Literal queued-record/sender unwind or FuncInfo words.
// R6GameService.dll data @ 10083a68 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendDescriptorAsD1ExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::SendDescriptorAsD1UnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Construct three lists before lookup, clear matched tree state, accumulate notifications across live owner9c matches.
// Retain current key/iterator/payload/links, captured second word, EDX upper flag bytes and raw final cleanup return.
// R6GameService.dll @ 10053330 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall NotifyAndRemoveKeyRecords(void *owner,int key,uint notificationValue)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectKeyRecordNotificationEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x58
    push   ebx
    push   ebp
    push   esi
    xor    ebx,ebx
    push   edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   ebx
    mov    DWORD PTR [esp+0x20],ebx
    push   0x3
    lea    ecx,[esp+0x58]
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x5c],ebp
    mov    DWORD PTR [esp+0x6c],edi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   ebx
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x74],ebx
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x50],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x5c],R6GameServiceAddresses::clDataListPTR_LAB
    push   ebx
    push   0x3
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x78],0x1
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x54],edi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   ebx
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x74],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::clDataListPTR_LAB
    push   ebx
    push   0x3
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x78],0x3
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x3c],edi
    call   R6GameServiceAddresses::InitializeClDataFields
    push   ebx
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x74],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x20],ebp
    lea    eax,[esp+0x78]
    lea    ecx,[esp+0x1c]
    lea    edi,[esi+0xac]
    push   eax
    push   ecx
    mov    ecx,edi
    mov    BYTE PTR [esp+0x78],0x5
    call   R6GameServiceAddresses::FindIndexedTreeLowerBound
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    jne    Branch84
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x70],0x1
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x70],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    jmp    Branch90
  Branch84:
    mov    BYTE PTR [eax+0x98],bl
    mov    eax,DWORD PTR [esi+0x9c]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    mov    DWORD PTR [esp+0x10],edi
    je    Branch89
    mov    eax,DWORD PTR [esp+0x78]
  Branch85:
    mov    edx,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR [edx]
    mov    DWORD PTR [esp+0x14],ecx
    mov    edx,DWORD PTR [edi+0x8]
    mov    ebp,DWORD PTR [edx+0x4]
    cmp    ebp,eax
    jne    Branch87
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::RemoveListRecordsBySecondWord
    lea    eax,[esp+0x7c]
    lea    ecx,[esp+0x20]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x14]
    push   ecx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x10]
    lea    edx,[esp+0x18]
    push   ebx
    push   edx
    mov    ecx,DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR [ecx+0x10]
    call   R6GameServiceAddresses::ReadIndexedInt32
    lea    edx,[esp+0x18]
    lea    ecx,[esp+0x50]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0x50]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x1c],0x27
    push   ecx
    lea    ecx,[esp+0x3c]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x50]
    lea    ecx,[esp+0x38]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    sub    esp,0x18
    lea    eax,[esp+0x50]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x34],esp
    push   0x1
    push   eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x88],0x5
    call   R6GameServiceAddresses::GetReferencedStoragePlus8
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x2c]
    mov    dl,BYTE PTR [ecx+0xc]
    mov    ecx,esi
    push   edx
    push   0xd1
    push   ebp
    push   eax
    push   0x2
    call   R6GameServiceAddresses::QueueTaggedRecord
    mov    ebp,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ebp+0x8]
    lea    edi,[ebp+0x8]
    mov    ecx,DWORD PTR [ecx+0x10]
    cmp    ecx,ebx
    je    Branch86
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
  Branch86:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebp+0x4]
    mov    edi,DWORD PTR [ebp+0x0]
    push   ebp
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x78]
    jmp    Branch88
  Branch87:
    mov    edi,DWORD PTR [edi]
  Branch88:
    mov    ecx,DWORD PTR [esi+0x9c]
    mov    DWORD PTR [esp+0x10],edi
    cmp    edi,ecx
    jne    Branch85
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
  Branch89:
    mov    esi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x20],ebp
    mov    DWORD PTR [esp+0x2c],esi
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x70],0x7
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    edi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x38],ebp
    mov    DWORD PTR [esp+0x20],edi
    mov    DWORD PTR [esp+0x44],esi
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x70],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x38],edi
    mov    DWORD PTR [esp+0x50],ebp
    mov    DWORD PTR [esp+0x5c],esi
    lea    ecx,[esp+0x5c]
    mov    DWORD PTR [esp+0x70],0x9
    call   R6GameServiceAddresses::DestroyClDataPointerList
  Branch90:
    mov    ecx,DWORD PTR [esp+0x68]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x64
    ret    0x8
  }
}

// Notification state0 resets base of descriptor at inherited EBP-24.
// R6GameService.dll @ 10068d90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Notification state1 destroys full descriptor at inherited EBP-24.
// R6GameService.dll @ 10068d98 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Notification state2 resets base of descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068da0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Notification state3 destroys full descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068da8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Notification state4 resets base of descriptor at inherited EBP-54.
// R6GameService.dll @ 10068db0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Notification state5 destroys full descriptor at inherited EBP-54.
// R6GameService.dll @ 10068db8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Notification state6 destroys full descriptor through CURRENT saved S-58; normal parent never arms state6.
// R6GameService.dll @ 10068dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x58]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Notification state7 resets base of descriptor at inherited EBP-54.
// R6GameService.dll @ 10068dc8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Notification state8 resets base of descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Notification state9 resets base of descriptor at inherited EBP-24.
// R6GameService.dll @ 10068dd8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl NotifyAndRemoveKeyRecordsUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact ten-state accumulating-notification FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10068de0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyRecordNotificationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::NotifyAndRemoveKeyRecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll @ 10053610 : MarkKeyRecordPending
// Deletes all list entries for an exact key, then marks its tree record pending.
undefined4 __thiscall MarkKeyRecordPending(void *this,int key)
{
  undefined4 returnResidue; // The native EAX residue depends on the search/cleanup path.
  int *treeSentinel = *(int **)((char *)this + 0xac);
  int *candidate = treeSentinel;
  int *node = (int *)treeSentinel[1];

  while (node != 0) {
    if (node[4] < key) {
      node = (int *)node[3];
    }
    else {
      candidate = node;
      node = (int *)node[2];
    }
  }
  if (candidate == treeSentinel || key < candidate[4]) {
    candidate = treeSentinel;
  }
  if (candidate == *(int **)((char *)this + 0xac)) {
    return CONCAT31((int3)((uint)returnResidue >> 8),0);
  }
  RemoveMatchingKeyRecords(this,key);
  *(undefined1 *)((int)this + 0x1d8) = 1;
  *(undefined1 *)((char *)candidate + 0x98) = 2;
  // Only AL is defined by the native status store; upper EAX is path-dependent residue.
  return CONCAT31((int3)((uint)returnResidue >> 8),1);
}

// Find exact key before allocation, build two descriptors using current key, send through CURRENT transport1d0.
// AL-success marks CURRENT saved record+98 before destruction; retain raw upperEAX and distinct cleanup states.
// R6GameService.dll @ 10053970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendKeyNotificationD1(void *owner,int key)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectKeyNotificationSenderEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    lea    eax,[esp+0x54]
    xor    ebp,ebp
    lea    edi,[esi+0xac]
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x14],ebp
    call   R6GameServiceAddresses::FindIndexedTreeKey
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ecx
    jne    Branch91
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  Branch91:
    push   ebx
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    push   ebp
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x54],ebp
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x54],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x58]
    mov    BYTE PTR [esp+0x50],bl
    push   ecx
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   edx
    mov    DWORD PTR [esp+0x14],ebx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x18]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x18]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x1d0]
    push   0x1
    push   0xd1
    call   R6GameServiceAddresses::SendTransportPayload
    test   al,al
    pop    ebx
    jne    Branch92
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x5
    call   R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  Branch92:
    mov    edx,DWORD PTR [esp+0x10]
    mov    BYTE PTR [edx+0x98],0x1
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x7
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  }
}

// Key sender state0 resets base of descriptor at inherited EBP-24.
// R6GameService.dll @ 10068e40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Key sender state1 destroys full descriptor at inherited EBP-24.
// R6GameService.dll @ 10068e48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Key sender state2 resets base of descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068e50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Key sender state3 destroys full descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068e58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Key sender state4 resets base of descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068e60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Key sender state5 resets base of descriptor at inherited EBP-24.
// R6GameService.dll @ 10068e68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Key sender state6 resets base of descriptor at inherited EBP-3c.
// R6GameService.dll @ 10068e70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Key sender state7 resets base of descriptor at inherited EBP-24.
// R6GameService.dll @ 10068e78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendKeyNotificationD1Unwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact eight-state keyed-notification sender FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10068e80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyNotificationSenderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendKeyNotificationD1ExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Cache successor before removal, load current key last, then compare successor to CURRENT owner+ac head.
// Ignore removal status, retain final raw upperEAX/AL1 and no own EH.
// R6GameService.dll @ 10054110 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessIndexedRecordsInKeyOrder(void *owner)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0xac]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je    Branch99
  Branch93:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,esi
    test   eax,eax
    je    Branch95
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    je    Branch98
  Branch94:
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    jne    Branch94
    jmp    Branch98
  Branch95:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch97
  Branch96:
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    je    Branch96
  Branch97:
    cmp    DWORD PTR [esi+0xc],eax
    je    Branch98
    mov    esi,eax
  Branch98:
    mov    eax,DWORD PTR [ecx+0x10]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotifications
    cmp    esi,DWORD PTR [edi+0xac]
    jne    Branch93
  Branch99:
    pop    edi
    mov    al,0x1
    pop    esi
    ret
  }
}

// Find exact signed key using captured header, then compare CURRENT header and BYTEstate2; preserve current-header upperEAX.
// R6GameService.dll @ 10054170 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall IndexedRecordHasState2(void *owner,int key)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [ecx+0xac]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,esi
    test   eax,eax
    je    Branch103
  Branch100:
    cmp    DWORD PTR [eax+0x10],edi
    jl    Branch101
    mov    edx,eax
    mov    eax,DWORD PTR [eax+0x8]
    jmp    Branch102
  Branch101:
    mov    eax,DWORD PTR [eax+0xc]
  Branch102:
    test   eax,eax
    jne    Branch100
  Branch103:
    cmp    edx,esi
    je    Branch104
    cmp    edi,DWORD PTR [edx+0x10]
    jge    Branch105
  Branch104:
    mov    edx,esi
  Branch105:
    mov    eax,DWORD PTR [ecx+0xac]
    pop    edi
    cmp    edx,eax
    pop    esi
    je    Branch106
    cmp    BYTE PTR [edx+0x98],0x2
    jne    Branch106
    mov    al,0x1
    ret    0x4
  Branch106:
    xor    al,al
    ret    0x4
  }
}


// Cache successor only after wrapper free, compare CURRENT head after each step; no own EH, retain raw EAX.
// R6GameService.dll @ 100541d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveListRecordsBySecondWord(void *owner,int secondWord)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx+0xa4]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch111
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    push   edi
  Branch107:
    mov    eax,DWORD PTR [esi+0x8]
    cmp    DWORD PTR [eax+0x4],ebp
    jne    Branch109
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    je    Branch108
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch108:
    mov    ecx,DWORD PTR [esi+0x8]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    esi,edi
    jmp    Branch110
  Branch109:
    mov    esi,DWORD PTR [esi]
  Branch110:
    cmp    esi,DWORD PTR [ebx+0xa4]
    jne    Branch107
    pop    edi
    pop    ebp
  Branch111:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Remove matching pending-list word pairs: capture arg1, reload arg2 per comparison, destroy current payload then unlink node.
// Keep nonmatch cached successor versus post-callback matched reload, current loop head and raw final successor, RET8.
// R6GameService.dll @ 10054230 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveListRecordsByWordPair(void *owner,int secondWord,int firstWord)
{
  __asm {
    push   ebp
    mov    ebp,ecx
    mov    ecx,DWORD PTR [ebp+0xa4]
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je    Branch115
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   esi
    push   edi
  Branch112:
    mov    esi,eax
    mov    eax,DWORD PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    DWORD PTR [ecx+0x4],ebx
    jne    Branch114
    mov    edx,DWORD PTR [esp+0x18]
    mov    edi,DWORD PTR [ecx]
    cmp    edi,edx
    jne    Branch114
    mov    ecx,DWORD PTR [ecx+0x10]
    test   ecx,ecx
    je    Branch113
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch113:
    mov    ecx,DWORD PTR [esi+0x8]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    push   esi
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [edi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,edi
  Branch114:
    cmp    eax,DWORD PTR [ebp+0xa4]
    jne    Branch112
    pop    edi
    pop    esi
    pop    ebx
  Branch115:
    pop    ebp
    ret    0x8
  }
}

// Literal accumulating-notification cleanup map/FuncInfo; state6 is not armed by the normal parent.
// R6GameService.dll data @ 100837f4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry NotifyAndRemoveKeyRecordsUnwindMap[10] = {
  {-1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind1},
  {-1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind2},
  {0x1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind3},
  {0x1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind4},
  {0x3, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind5},
  {0x3, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind6},
  {0x5, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind7},
  {0x3, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind8},
  {0x1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind9},
  {-1, R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwind10},
};

// Literal accumulating-notification FuncInfo.
// R6GameService.dll data @ 10083844 : native storage identity retained.
const R6GameServiceNative::FuncInfo NotifyAndRemoveKeyRecordsExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::NotifyAndRemoveKeyRecordsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal keyed-notification sender cleanup map/FuncInfo.
// R6GameService.dll data @ 100838bc : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendKeyNotificationD1UnwindMap[8] = {
  {-1, R6GameServiceAddresses::SendKeyNotificationD1Unwind1},
  {-1, R6GameServiceAddresses::SendKeyNotificationD1Unwind2},
  {0x1, R6GameServiceAddresses::SendKeyNotificationD1Unwind3},
  {0x1, R6GameServiceAddresses::SendKeyNotificationD1Unwind4},
  {0x1, R6GameServiceAddresses::SendKeyNotificationD1Unwind5},
  {-1, R6GameServiceAddresses::SendKeyNotificationD1Unwind6},
  {0x1, R6GameServiceAddresses::SendKeyNotificationD1Unwind7},
  {-1, R6GameServiceAddresses::SendKeyNotificationD1Unwind8},
};

// Literal keyed-notification sender FuncInfo.
// R6GameService.dll data @ 100838fc : native storage identity retained.
const R6GameServiceNative::FuncInfo SendKeyNotificationD1ExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::SendKeyNotificationD1UnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: CLobbySrvConnectionListVTable
// R6GameService.dll data @ 10078064 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CLobbySrvConnectionListVTableRecord {
  R6GameServiceNative::Address CLobbySrvConnectionListDelete; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address PopConnectionPointerList; // +0x08
  R6GameServiceNative::Address PopBackConnectionPointerList; // +0x0c
  R6GameServiceNative::Address EraseConnectionPointerRange; // +0x10
  R6GameServiceNative::Address EraseConnectionPointerListNode; // +0x14
};
const CLobbySrvConnectionListVTableRecord CLobbySrvConnectionListVTable = {
  R6GameServiceAddresses::CLobbySrvConnectionListDelete,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::PopConnectionPointerList,
  R6GameServiceAddresses::PopBackConnectionPointerList,
  R6GameServiceAddresses::EraseConnectionPointerRange,
  R6GameServiceAddresses::EraseConnectionPointerListNode,
};
