#include "native_addresses.h"
#include "native_records.h"

// Inferred destruction states keep payload retries separate from storage-only cleanup.
struct ConnectionListDestructionCleanup {
  void *savedOwner;
  void *savedMember;
  void *savedSlot;
  int state;
  // Unwind the active member, then the current saved base; state4 releases base storage without payload retries.
  ~ConnectionListDestructionCleanup() noexcept(false)
  {
    using MethodABI = uint (__fastcall *)(void *);
    switch (state) {
    case 0:
      break;
    case 1:
      ((MethodABI)R6GameServiceAddresses::ForwardCurrentMessageListDestroy)((void *)((uint)savedOwner + 0xc));
      break;
    case 2:
      savedSlot = savedMember == 0 ? 0 : (void *)((uint)savedMember + 4);
      ((MethodABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(savedSlot);
      break;
    case 3: {
      using EmptyABI = void (__fastcall *)(void *);
      ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(savedSlot);
      break;
    }
    case 4: {
      void *slot = savedOwner == 0 ? 0 : (void *)((uint)savedOwner + 4);
      ((MethodABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(slot);
      return;
    }
    default:
      return;
    }
    ((MethodABI)R6GameServiceAddresses::DestroyConnectionPointerList)(savedOwner);
  }
};

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
uint __thiscall CConnectionListQueryKey(void *owner,int key)
{
  uint head = *(uint *)((uint)owner + 4);
  uint node = *(uint *)head;
  if (node == head) return node & 0xffffff00;
  int requested = key;
  do {
    uint payload = *(uint *)(node + 8);
    int current = *(int *)(payload + 8);
    if (current == requested) break;
    if (current > requested) return node & 0xffffff00;
    node = *(uint *)node;
  } while (node != head);
  if (node == head) return node & 0xffffff00;
  uint selected = node;
  uint vtable = *(uint *)owner;
  using EraseABI = uint (__thiscall *)(void *,int *,uint);
  uint result = ((EraseABI)*(uint *)(vtable + 0x14))(owner,&key,selected);
  return (result & 0xffffff00) | 1;
}

// Construct two12-byte circular-list headers, installing base/member tables before the final CConnectionList table.
// Initial full flag controls owner+8 table77f28; other owner bytes and header thirdDWORDs remain untouched.
// ENTRY ESP S: localS-10/stateS-4; sole state0 cleanup is empty and does not release either published header.
// Preserve first-slot clear, second-slot clear timing, FS load before second-header stores, owner EAX and RET4.
// R6GameService.dll @ 1004c730 : complete native control/access order and raw ABI retained.
void *__thiscall CConnectionListConstruct(void *owner,uint initializeVirtualBase)
{
  uint base = (uint)owner;
  uint initialize = initializeVirtualBase;
  if (initialize != 0) *(uint *)(base + 8) = 0x10077f28;
  void *connectionSlot = (void *)(base + 4);
  using StoreABI = void * (__thiscall *)(void *,uint,uint);
  ((StoreABI)R6GameServiceAddresses::StoreFirstWordIgnoringContext)(connectionSlot,(uint)&initializeVirtualBase,0);
  uint connections = (uint)AllocateGameServiceBytes(12);
  *(uint *)connections = connections;
  *(uint *)(connections + 4) = connections;
  *(uint *)connectionSlot = connections;
  *(uint *)base = R6GameServiceAddresses::clPointerList_PAVCConnectionVTable;
  *(uint *)(base + 0x14) = 0x10077f20;
  *(uint *)(base + 0x10) = 0;
  uint messages = (uint)AllocateGameServiceBytes(12);
  *(uint *)messages = messages;
  *(uint *)(messages + 4) = messages;
  *(uint *)(base + 0x10) = messages;
  *(uint *)(base + 0xc) = R6GameServiceAddresses::clPointerList_PAVCCurMessageVTable;
  *(uint *)base = R6GameServiceAddresses::CConnectionListVTable;
  return owner;
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
uint __fastcall CConnectionListDestroy(void *owner)
{
  ConnectionListDestructionCleanup cleanup{owner, 0, 0, -1};
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::CConnectionListVTable;
  uint source = R6GameServiceAddresses::GRegistrationEmptyText;
  uint destination = base + 0x18;
  cleanup.state = 1;
  byte value;
  do {
    value = *(byte *)source;
    *(byte *)destination = value;
    ++source;
    ++destination;
  } while (value != 0);
  void *connectionSlot = (void *)(base + 4);
  uint connectionEnd = *(uint *)connectionSlot;
  uint connectionBegin = connectionEnd;
  uint connectionTable = *(uint *)base;
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(connectionSlot,&connectionBegin);
  // Inferred scratch union: entryESP-0x20 is first range output, then the message slot.
  union { uint connectionResult; void *messageSlot; } scratch;
  ((RangeABI)*(uint *)(connectionTable + 0x10))(
      owner,&scratch.connectionResult,connectionBegin,connectionEnd);
  void *member = (void *)(base + 0xc);
  cleanup.savedMember = member;
  *(uint *)member = R6GameServiceAddresses::clPointerList_PAVCCurMessageVTable;
  uint messageEnd = *(uint *)((uint)member + 4);
  void *messageSlot = (void *)((uint)member + 4);
  uint messageBegin = messageEnd;
  uint messageTable = *(uint *)member;
  cleanup.state = 2;
  scratch.messageSlot = messageSlot;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(messageSlot,&messageBegin);
  uint messageResult;
  ((RangeABI)*(uint *)(messageTable + 0x10))(member,&messageResult,messageBegin,messageEnd);
  void *releaseSlot = scratch.messageSlot;
  cleanup.savedSlot = releaseSlot;
  cleanup.state = 3;
  using MethodABI = uint (__fastcall *)(void *);
  ((MethodABI)R6GameServiceAddresses::ReleaseListNodesRetainHeader)(releaseSlot);
  void *messageHead = *(void **)releaseSlot;
  using FreeSizedABI = uint (__thiscall *)(void *,void *,uint);
  ((FreeSizedABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(releaseSlot,messageHead,1);
  *(uint *)base = R6GameServiceAddresses::clPointerList_PAVCConnectionVTable;
  uint finalEnd = *(uint *)connectionSlot;
  uint finalBegin = finalEnd;
  cleanup.state = 4;
  uint finalTable = *(uint *)base;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(connectionSlot,&finalBegin);
  ((RangeABI)*(uint *)(finalTable + 0x10))(owner,(uint *)&cleanup.savedSlot,finalBegin,finalEnd);
  uint head = *(uint *)connectionSlot;
  uint node = *(uint *)head;
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      TailFreeThroughGlobalAllocator((void *)detached);
    } while (node != *(uint *)connectionSlot);
  }
  head = *(uint *)connectionSlot;
  *(uint *)head = head;
  head = *(uint *)connectionSlot;
  *(uint *)(head + 4) = head;
  head = *(uint *)connectionSlot;
  uint result = TailFreeThroughGlobalAllocator((void *)head);
  cleanup.state = -1;
  return result;
}

// Destroy CConnectionList, then test CURRENT flag lowBYTE/bit0, optionally free original owner and return it. RET4.
// R6GameService.dll @ 1004c700 : complete native control/access order and raw ABI retained.
void *__thiscall CConnectionListDelete(void *owner,uint deletingFlags)
{
  void *savedOwner = owner;
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::CConnectionListDestroy)(savedOwner);
  byte flags = *(byte *)&deletingFlags;
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(savedOwner);
  return savedOwner;
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
// R6GameService.dll @ 1004c960 : ECX receiver, four native stack words, RET16.
uint __thiscall CConnectionListSendToKey(void *owner,int key,uint opcode,uint mode,int payload)
{
  uint borrowed = CConnectionListFindBorrowed(owner,key);
  if (borrowed == 0) return 0;
  uint currentPayload = (uint)payload;
  uint currentMode = mode;
  uint currentOpcode = opcode;
  return SendTransportPayload((void *)borrowed,currentOpcode,currentMode,(const void *)currentPayload,borrowed);
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
uint __thiscall CConnectionListFindBorrowed(void *owner,int key)
{
  uint head = *(uint *)((uint)owner + 4);
  uint node = *(uint *)head;
  if (node == head) return 0;
  int requested = key;
  do {
    uint payload = *(uint *)(node + 8);
    int current = *(int *)(payload + 8);
    if (current == requested) return *(uint *)(node + 8);
    if (current > requested) return 0;
    node = *(uint *)node;
  } while (node != head);
  return 0;
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
