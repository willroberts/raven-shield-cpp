#include "native_addresses.h"
#include "native_records.h"

// CConnectionList: primary77f08 -> COL79e2c -> type900ac, .?AVCConnectionList@@.

// Walk owner+4 list and test actual transport predicate32150; reload head after each true result.
// First false predicate returns CURRENT payload+8 key; exhaustion returns0. Borrow all nodes/payloads.
// R6GameService.dll @ 1004c930 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CConnectionListFindFailingKey(void *owner)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch2
  Branch1:
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::IsTransportConnected
    test   al,al
    je     Branch3
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [edi+0x4]
    cmp    esi,eax
    jne    Branch1
  Branch2:
    pop    edi
    xor    eax,eax
    pop    esi
    ret
  Branch3:
    mov    eax,DWORD PTR [esi+0x8]
    pop    edi
    pop    esi
    mov    eax,DWORD PTR [eax+0x8]
    ret
  }
}

// Search the owner+4 list in signed key order, stopping at the first greater key; duplicate selection is first match.
// Cache end/key, call CURRENT virtual slot14 with output=&original key and node by value; set AL1 only. RET4.
// A miss clears AL on current cursor; virtual output can overwrite the original key argument.
// R6GameService.dll @ 1004c8e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionListQueryKey(void *owner,int key)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [ecx+0x4]
    push   edi
    mov    eax,DWORD PTR [esi]
    cmp    eax,esi
    je     Branch6
    mov    edi,DWORD PTR [esp+0xc]
  Branch4:
    mov    edx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [edx+0x8]
    cmp    edx,edi
    je     Branch5
    jg     Branch6
    mov    eax,DWORD PTR [eax]
    cmp    eax,esi
    jne    Branch4
  Branch5:
    cmp    eax,esi
    jne    Branch7
  Branch6:
    xor    al,al
    pop    edi
    pop    esi
    ret    0x4
  Branch7:
    push   ecx
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [ecx]
    lea    edx,[esp+0x10]
    push   edx
    call   DWORD PTR [eax+0x14]
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Construct two12-byte circular-list headers, installing base/member tables before the final CConnectionList table.
// Initial full flag controls owner+8 table77f28; other owner bytes and header thirdDWORDs remain untouched.
// ENTRY ESP S: localS-10/stateS-4; sole state0 cleanup is empty and does not release either published header.
// Preserve first-slot clear, second-slot clear timing, FS load before second-header stores, owner EAX and RET4.
// R6GameService.dll @ 1004c730 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CConnectionListConstruct(void *owner,uint initializeVirtualBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectionListCtorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    mov    eax,DWORD PTR [esp+0x14]
    push   esi
    test   eax,eax
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    je     Branch8
    mov    DWORD PTR [esi+0x8],0x10077f28
  Branch8:
    lea    edi,[esi+0x4]
    lea    eax,[esp+0x1c]
    push   0x0
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x1c],0x0
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerList_PAVCConnectionVTable
    mov    DWORD PTR [esi+0x14],0x10077f20
    push   0xc
    mov    DWORD PTR [esi+0x10],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clPointerList_PAVCCurMessageVTable
    mov    DWORD PTR [esi],R6GameServiceAddresses::CConnectionListVTable
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Tail the original flag-argument address from inherited ENTRY ESP+4 to the genuine empty helper.
// R6GameService.dll @ 100682c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListConstructUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select the connection-list constructor one-state metadata and tail current CRT frame dispatch.
// R6GameService.dll @ 100682c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectionListCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CConnectionListConstructExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10082c94: exact connection-list constructor map or FuncInfo.
const R6GameServiceNative::UnwindEntry CConnectionListConstructUnwindMap[1] = {
  {-1, R6GameServiceAddresses::CConnectionListConstructUnwind1},
};

// R6GameService.dll data @ 10082c9c: exact connection-list constructor map or FuncInfo.
// R6GameService.dll data @ 10082c94 : native storage identity retained.
const R6GameServiceNative::FuncInfo CConnectionListConstructExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::CConnectionListConstructUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Clear the connection range, then message range/header, then restore the base table and release connection header.
// ENTRY ESP S: savedownerS-1c/memberS-18/currentheadslotS-10/stateS-4. Keep two-pass ranges and current head reads.
// Preserve copied global text, three-word virtual calls, five-state cleanup, dangling slots and raw allocator EAX.
// R6GameService.dll @ 1004c5e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CConnectionListDestroy(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectionListDestroyEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::CConnectionListVTable
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    lea    edx,[esi+0x18]
    mov    DWORD PTR [esp+0x2c],0x1
    sub    edx,eax
  Branch9:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test   cl,cl
    jne    Branch9
    push   ecx
    mov    ecx,DWORD PTR [esi+0x4]
    lea    edi,[esi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [esi]
    mov    ecx,edi
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   DWORD PTR [ebx+0x10]
    lea    ebx,[esi+0xc]
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [ebx],R6GameServiceAddresses::clPointerList_PAVCCurMessageVTable
    mov    edx,DWORD PTR [ebx+0x4]
    push   ecx
    lea    ecx,[ebx+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],edx
    mov    ebp,DWORD PTR [ebx]
    mov    BYTE PTR [esp+0x38],0x2
    mov    DWORD PTR [esp+0x1c],ecx
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    ecx,[esp+0x24]
    push   ecx
    mov    ecx,ebx
    call   DWORD PTR [ebp+0x10]
    mov    ebx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x20],ebx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x2c],0x3
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edx,DWORD PTR [ebx]
    push   0x1
    push   edx
    mov    ecx,ebx
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerList_PAVCConnectionVTable
    push   ecx
    mov    ecx,DWORD PTR [edi]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [esp+0x38],0x4
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [esi]
    mov    ecx,edi
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x28]
    mov    ecx,esi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch11
  Branch10:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi]
    jne    Branch10
  Branch11:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x20
    ret
  }
}

// Destroy CConnectionList, then test CURRENT flag lowBYTE/bit0, optionally free original owner and return it. RET4.
// R6GameService.dll @ 1004c700 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CConnectionListDelete(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::CConnectionListDestroy
    test   BYTE PTR [esp+0x8],0x1
    je     Branch12
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroy the connection pointer-list base using CURRENT saved owner.
// R6GameService.dll @ 10068240 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListDestroyUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::DestroyConnectionPointerList
  }
}

// Destroy the message pointer-list member at CURRENT saved owner+c through its native thunk.
// R6GameService.dll @ 10068248 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListDestroyUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ForwardCurrentMessageListDestroy
  }
}

// Compute null-preserving current member+4 into parent S-10, then unconditionally release that list.
// R6GameService.dll @ 10068253 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListDestroyUnwind3(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x18],0x0
    je     Branch13
    mov    eax,DWORD PTR [ebp-0x18]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch14
  Branch13:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch14:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Tail CURRENT saved list pointer to the empty helper; do not retry message header release.
// R6GameService.dll @ 1006827a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListDestroyUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Compute null-preserving current owner+4 into parent S-54, then unconditionally release that list.
// R6GameService.dll @ 10068282 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CConnectionListDestroyUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x1c],0x0
    je     Branch15
    mov    eax,DWORD PTR [ebp-0x1c]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x54],eax
    jmp    Branch16
  Branch15:
    mov    DWORD PTR [ebp-0x54],0x0
  Branch16:
    mov    ecx,DWORD PTR [ebp-0x54]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select five-state CConnectionList destruction metadata and tail current CRT dispatch.
// R6GameService.dll @ 100682a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectionListDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CConnectionListDestroyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10082c50: exact list destruction map or FuncInfo.
const R6GameServiceNative::UnwindEntry CConnectionListDestroyUnwindMap[5] = {
  {-1, R6GameServiceAddresses::CConnectionListDestroyUnwind1},
  {0x0, R6GameServiceAddresses::CConnectionListDestroyUnwind2},
  {0x0, R6GameServiceAddresses::CConnectionListDestroyUnwind3},
  {0x0, R6GameServiceAddresses::CConnectionListDestroyUnwind4},
  {-1, R6GameServiceAddresses::CConnectionListDestroyUnwind5},
};

// R6GameService.dll data @ 10082c78: exact list destruction map or FuncInfo.
// R6GameService.dll data @ 10082c50 : native storage identity retained.
const R6GameServiceNative::FuncInfo CConnectionListDestroyExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::CConnectionListDestroyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Reject an existing signed +8 key; otherwise construct a 0x98-byte CConnection and configure its provider.
// Cache original key, retain six physical argument words, and insert after every current equal key on setup success.
// Failed setup destroys/frees the current saved connection; later insertion failures have no enclosing cleanup.
// Reload saved payload and insertion scratch after node allocation; preserve AL-only status and RET24.
// R6GameService.dll @ 1004c810 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionListInsertConfigured(
    void *owner,const char *text,uint port,uint mode,uint providerWord,void *key,uint context)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    push   edi
    call   R6GameServiceAddresses::CConnectionListFindBorrowed
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch22
    push   0x98
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    je     Branch17
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::CConnectionConstruct
    jmp    Branch18
  Branch17:
    xor    eax,eax
  Branch18:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [esp+0x18]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x18]
    push   edi
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    push   edx
    push   ecx
    mov    ecx,eax
    mov    DWORD PTR [esp+0x34],eax
    call   R6GameServiceAddresses::CConnectionReplaceAndStartProvider
    test   al,al
    je     Branch21
    mov    ecx,DWORD PTR [esi+0x4]
    add    esi,0x4
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x20],eax
    je     Branch20
  Branch19:
    mov    edx,DWORD PTR [eax+0x8]
    cmp    edi,DWORD PTR [edx+0x8]
    jl     Branch20
    mov    eax,DWORD PTR [eax]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x20],eax
    jne    Branch19
  Branch20:
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0x18]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x1c]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x18]
    pop    edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    pop    esi
    ret    0x18
  Branch21:
    mov    ecx,DWORD PTR [esp+0x1c]
    test   ecx,ecx
    mov    esi,ecx
    je     Branch22
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch22:
    pop    edi
    xor    al,al
    pop    esi
    ret    0x18
  }
}

// Find the signed +8 key and send through actual transport32170 using three full physical stack words.
// Return the sender raw EAX; a missing key returns zero. RET16, no ownership transfer or local cleanup.
// R6GameService.dll @ 1004c960 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionListSendToKey(void *owner,int key,uint opcode,uint mode,int payload)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::CConnectionListFindBorrowed
    test   eax,eax
    je     Branch23
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   ecx
    mov    ecx,DWORD PTR [esp+0xc]
    push   edx
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::SendTransportPayload
    ret    0x10
  Branch23:
    xor    al,al
    ret    0x10
  }
}

// Send once per connection until AL0; success sets AL1 while retaining the last sender EAX upper bytes.
// Cache payload/mode, reload opcode and saved receiver each iteration, then read current successor/head.
// Empty success retains initial head upper bytes; preserve full argument words, callback effects and RET12.
// R6GameService.dll @ 1004c990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionListBroadcast(void *owner,uint opcode,uint mode,int payload)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [ecx+0x4]
    push   ebx
    push   esi
    push   edi
    mov    esi,DWORD PTR [eax]
    mov    DWORD PTR [esp+0xc],ecx
    cmp    esi,eax
    je     Branch25
    mov    edi,DWORD PTR [esp+0x1c]
    mov    ebx,DWORD PTR [esp+0x18]
  Branch24:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esi+0x8]
    push   edi
    push   ebx
    push   eax
    call   R6GameServiceAddresses::SendTransportPayload
    test   al,al
    je     Branch26
    mov    ecx,DWORD PTR [esp+0xc]
    mov    esi,DWORD PTR [esi]
    cmp    esi,DWORD PTR [ecx+0x4]
    jne    Branch24
  Branch25:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0xc
  Branch26:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Search borrowed owner+4 nodes by signed payload+8 key, stopping at the first greater key.
// Cache initial head and requested key; return first equal payload, otherwise full zero. RET4.
// R6GameService.dll @ 1004cad0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionListFindBorrowed(void *owner,int key)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [esi]
    cmp    eax,esi
    je     Branch28
    mov    edx,DWORD PTR [esp+0x8]
  Branch27:
    mov    ecx,DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR [ecx+0x8]
    cmp    ecx,edx
    je     Branch29
    jg     Branch28
    mov    eax,DWORD PTR [eax]
    cmp    eax,esi
    jne    Branch27
  Branch28:
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch29:
    mov    eax,DWORD PTR [eax+0x8]
    pop    esi
    ret    0x4
  }
}

// Extract at most one message from every current connection and append each copied record to the persistent +10 queue.
// Read current successor/head after each extraction/append; cached append head and payload scratch remain live.
// Count the current queue modulo32; if nonzero allocate/copy its CURRENT first record, then call CURRENT +c slot8.
// Return cached copy even when pop returns another value; NULL output allocation still consumes the first queue record.
// ENTRY ESP S: rawS-10/stateS-4. Shared one-state guard covers copy construction only, not extraction/append/pop.
// R6GameService.dll @ 1004c9e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__fastcall CConnectionListCollectMessages(void *owner)
{
  __asm {
    mov    eax,fs:0x0
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectionAllocationEH
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x4]
    mov    ebx,DWORD PTR [eax]
    cmp    ebx,eax
    je     Branch32
    push   esi
  Branch30:
    mov    ecx,DWORD PTR [ebx+0x8]
    call   R6GameServiceAddresses::CConnectionPopCopiedMessage
    test   eax,eax
    mov    DWORD PTR [esp+0xc],eax
    je     Branch31
    lea    esi,[edi+0x10]
    lea    eax,[esp+0x10]
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0xc]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch31:
    mov    ebx,DWORD PTR [ebx]
    mov    eax,DWORD PTR [edi+0x4]
    cmp    ebx,eax
    jne    Branch30
    pop    esi
  Branch32:
    mov    ecx,DWORD PTR [edi+0x10]
    xor    edx,edx
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je     Branch36
  Branch33:
    mov    eax,DWORD PTR [eax]
    inc    edx
    cmp    eax,ecx
    jne    Branch33
    test   edx,edx
    jbe    Branch36
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],0x0
    je     Branch34
    mov    edx,DWORD PTR [edi+0x10]
    push   0x1
    mov    edx,DWORD PTR [edx]
    mov    ecx,DWORD PTR [edx+0x8]
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructQueuedPayloadRecord
    jmp    Branch35
  Branch34:
    xor    eax,eax
  Branch35:
    mov    edx,DWORD PTR [edi+0xc]
    lea    ecx,[edi+0xc]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    mov    DWORD PTR [esp+0x8],eax
    call   DWORD PTR [edx+0x8]
    mov    eax,DWORD PTR [esp+0x8]
    pop    edi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret
  Branch36:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    xor    eax,eax
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret
  }
}

// Native virtual-table prefix: CConnectionListVTable
// R6GameService.dll data @ 10077f08 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CConnectionListVTableRecord {
  R6GameServiceNative::Address CConnectionListDelete; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address PopConnectionPointerList; // +0x08
  R6GameServiceNative::Address PopBackConnectionPointerList; // +0x0c
  R6GameServiceNative::Address EraseConnectionPointerRange; // +0x10
  R6GameServiceNative::Address EraseConnectionPointerListNode; // +0x14
};
const CConnectionListVTableRecord CConnectionListVTable = {
  R6GameServiceAddresses::CConnectionListDelete,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::PopConnectionPointerList,
  R6GameServiceAddresses::PopBackConnectionPointerList,
  R6GameServiceAddresses::EraseConnectionPointerRange,
  R6GameServiceAddresses::EraseConnectionPointerListNode,
};
