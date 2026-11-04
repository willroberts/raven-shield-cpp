#include "native_addresses.h"
#include "native_records.h"

// Physical six-word descriptor argument; this C++ interface name is descriptive.
struct NativeDescriptorArgument24 { undefined4 words[6]; };

// Inferred seven-state guard; each completed action exposes the next current owner/cleanup slot.
struct LobbyConnectionDestructionCleanup {
  void *savedOwner;
  void *savedSlot;
  int state;
  // Retry the active tree/header or drain the remaining list storage, then destroy the current saved base.
  ~LobbyConnectionDestructionCleanup() noexcept(false)
  {
    using MethodABI = uint (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
      case 0:
        state = -1;
        ((MethodABI)R6GameServiceAddresses::CConnectionListDestroy)(savedOwner);
        break;
      case 1:
        state = 0;
        ((MethodABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)((void *)((uint)savedOwner + 0x9c));
        break;
      case 2:
        state = 1;
        ((MethodABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)((void *)((uint)savedOwner + 0xa4));
        break;
      case 3:
        state = 2;
        ((MethodABI)R6GameServiceAddresses::thunk_ReleaseIndexedTree)((void *)((uint)savedOwner + 0xac));
        break;
      case 4:
        state = 2;
        ((MethodABI)R6GameServiceAddresses::ReleaseFirstWordBuffer)(savedSlot);
        break;
      case 5:
      case 6: {
        state = state == 5 ? 1 : 0;
        using EmptyABI = void (__fastcall *)(void *);
        ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(savedSlot);
        break;
      }
      }
    }
  }
};

// CLobbySrvConnectionList: primary78064 -> COL7a0ec(offset0) -> type90354, .?AVCLobbySrvConnectionList@@.
// Constructor52d60 and typed allocation43de0 -> cached receiver+10 -> caller53090 -> producer54900 agree.

// Inferred constructor locals: construction bitsS-18, saved ownerS-14 and current memberS-10.
struct LobbyConnectionConstructionLocals {
  uint bits;
  void *savedOwner;
  void *savedMember;
};

// Releases completed members and the base according to the active construction stage, using current saved slots.
struct LobbyConnectionConstructionCleanup {
  LobbyConnectionConstructionLocals *frame;
  uint *contextWord;
  int state;
  bool armed;
  // Preserve the partial-construction gaps: only states4/7 own full lists, and state10 owns the tree header.
  ~LobbyConnectionConstructionCleanup() noexcept(false)
  {
    if (!armed) return;
    using EmptyABI = void (__fastcall *)(void *);
    using ReleaseABI = uint (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
        case 0:
          state = -1;
          if ((frame->bits & 1) != 0)
            ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)((uint)frame->savedOwner + 0x1dc));
          break;
        case 1:
          state = 0;
          CConnectionListDestroy(frame->savedOwner);
          break;
        case 2:
          state = 1;
          if ((frame->bits & 2) != 0)
            ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)((uint)frame->savedMember + 8));
          break;
        case 3:
          state = 2;
          ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(contextWord);
          break;
        case 4:
          state = 1;
          ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)(
              (void *)((uint)frame->savedOwner + 0x9c));
          break;
        case 5:
          state = 4;
          if ((frame->bits & 4) != 0)
            ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)((uint)frame->savedMember + 8));
          break;
        case 6:
          state = 5;
          ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(contextWord);
          break;
        case 7:
          state = 4;
          ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)(
              (void *)((uint)frame->savedOwner + 0xa4));
          break;
        case 8:
          state = 7;
          if ((frame->bits & 8) != 0)
            ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)((uint)frame->savedMember + 0x10));
          break;
        case 9:
          state = 8;
          ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(contextWord);
          break;
        case 10:
          state = 9;
          ReleaseFirstWordBuffer(frame->savedMember);
          break;
      }
    }
  }
};

// Construct base with flag0, two empty12-byte lists and an168-byte indexed-tree header, then initialize owner fields.
// ENTRY ESP S: construction bitsS-18/savedownerS-14/currentmemberS-10/stateS-4. Initial full flag controls table+8;
// late current flag lowBYTE becomes tree+8, and late context DWORD becomes owner+1d0. RET8/owner EAX.
// Preserve untouched header/padding bytes, two129-byte zero buffers, eleven-state cleanup and no NULL repair.
// R6GameService.dll @ 10052d60 : complete native control/access order and raw ABI retained.
void * __thiscall CLobbySrvConnectionListConstruct(void *owner,uint context,uint initializeVirtualBase)
{
  LobbyConnectionConstructionLocals frame;
  LobbyConnectionConstructionCleanup cleanup{&frame,&initializeVirtualBase,-1,true};
  frame.bits = 0;
  uint initialize = initializeVirtualBase;
  uint base = (uint)owner;
  frame.savedOwner = owner;
  if (initialize != 0) {
    *(uint *)(base + 8) = 0x1007808c;
    frame.bits = 1;
    cleanup.state = 0;
  }
  CConnectionListConstruct(owner,0);
  uint bits = frame.bits;
  uint member = base + 0x9c;
  bits |= 2;
  frame.savedMember = (void *)member;
  *(uint *)(member + 4) = 0x10078084;
  frame.bits = bits;
  cleanup.state = 3;
  StoreFirstWordIgnoringContext((void *)member,(uint)&initializeVirtualBase,0);
  uint head = (uint)AllocateGameServiceBytes(12);
  *(uint *)head = head;
  *(uint *)(head + 4) = head;
  *(uint *)member = head;
  bits = frame.bits;
  member = base + 0xa4;
  bits |= 4;
  frame.savedMember = (void *)member;
  *(uint *)(member + 4) = 0x10078084;
  frame.bits = bits;
  cleanup.state = 6;
  StoreFirstWordIgnoringContext((void *)member,(uint)&initializeVirtualBase,0);
  head = (uint)AllocateGameServiceBytes(12);
  *(uint *)head = head;
  *(uint *)(head + 4) = head;
  *(uint *)member = head;
  bits = frame.bits;
  member = base + 0xac;
  bits |= 8;
  frame.savedMember = (void *)member;
  *(uint *)(member + 0xc) = 0x1007807c;
  frame.bits = bits;
  cleanup.state = 9;
  StoreFirstWordIgnoringContext((void *)member,(uint)&initializeVirtualBase,0);
  head = (uint)AllocateGameServiceBytes(168);
  *(uint *)member = head;
  byte treeFlag = (byte)initializeVirtualBase;
  cleanup.state = 10;
  *(uint *)(member + 4) = 0;
  *(byte *)(member + 8) = treeFlag;
  InitializeServiceTreeHeader((void *)member);
  uint currentContext = context;
  *(uint *)base = R6GameServiceAddresses::CLobbySrvConnectionListVTable;
  *(uint *)(base + 0x1d0) = currentContext;
  *(byte *)(base + 0x1d8) = 0;
  *(uint *)(base + 0xbc) = 0;
  *(uint *)(base + 0xc0) = 0;
  *(uint *)(base + 0xc4) = 0;
  *(uint *)(base + 0xc8) = 0;
  for (uint index = 0; index != 32; ++index) *(uint *)(base + 0xcc + index * 4) = 0;
  *(byte *)(base + 0x14c) = 0;
  for (uint index = 0; index != 32; ++index) *(uint *)(base + 0x14d + index * 4) = 0;
  *(byte *)(base + 0x1cd) = 0;
  *(uint *)(base + 0x1d4) = 0;
  cleanup.armed = false;
  return owner;
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

// R6GameService.dll data @ 10083760 : exact constructor FuncInfo.
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
void *__thiscall CLobbySrvConnectionListDelete(void *owner,uint deletingFlags)
{
  void *savedOwner = owner;
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::CLobbySrvConnectionListDestroy)(savedOwner);
  byte flags = *(byte *)&deletingFlags;
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(savedOwner);
  return savedOwner;
}

// Restore the class table, clear owned lists and base range, then release indexed tree and list headers before base.
// ENTRY ESP S: saved ownerS-18/current cleanup slotS-10/stateS-4. State3 initially owns tree/lists/base.
// State4 may retry current tree header; states5/6 forward empty context without retrying the respective list.
// Preserve physical three-word virtual range call, current head reloads, dangling slots and final base raw EAX.
// R6GameService.dll @ 10052f00 : complete native control/access order and raw ABI retained.
uint __fastcall CLobbySrvConnectionListDestroy(void *owner)
{
  LobbyConnectionDestructionCleanup cleanup{owner, 0, -1};
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::CLobbySrvConnectionListVTable;
  cleanup.state = 3;
  using MethodABI = uint (__fastcall *)(void *);
  ((MethodABI)R6GameServiceAddresses::ClearOwnedList9c)(owner);
  ((MethodABI)R6GameServiceAddresses::ClearOwnedLista4)(owner);
  uint connectionEnd = *(uint *)(base + 4);
  void *connectionSlot = (void *)(base + 4);
  uint connectionBegin = connectionEnd;
  uint table = *(uint *)base;
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(connectionSlot,&connectionBegin);
  uint rangeResult;
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  ((RangeABI)*(uint *)(table + 0x10))(owner,&rangeResult,connectionBegin,connectionEnd);
  void *treeSlot = (void *)(base + 0xac);
  cleanup.savedSlot = treeSlot;
  cleanup.state = 4;
  ((MethodABI)R6GameServiceAddresses::ClearIndexedTree)(treeSlot);
  void *treeHead = *(void **)treeSlot;
  TailFreeThroughGlobalAllocator(treeHead);
  void *listA4Slot = (void *)(base + 0xa4);
  cleanup.savedSlot = listA4Slot;
  cleanup.state = 5;
  ((MethodABI)R6GameServiceAddresses::ReleaseListNodesRetainHeader)(listA4Slot);
  void *listA4Head = *(void **)listA4Slot;
  TailFreeThroughGlobalAllocator(listA4Head);
  void *list9cSlot = (void *)(base + 0x9c);
  cleanup.savedSlot = list9cSlot;
  uint head = *(uint *)list9cSlot;
  cleanup.state = 6;
  uint node = *(uint *)head;
  using ReleaseABI = uint (__thiscall *)(void *,void *,uint);
  if (node != head) {
    do {
      uint detached = node;
      node = *(uint *)node;
      ((ReleaseABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(list9cSlot,(void *)detached,1);
    } while (node != *(uint *)list9cSlot);
  }
  head = *(uint *)list9cSlot;
  *(uint *)head = head;
  head = *(uint *)list9cSlot;
  *(uint *)(head + 4) = head;
  void *list9cHead = *(void **)list9cSlot;
  TailFreeThroughGlobalAllocator(list9cHead);
  cleanup.state = -1;
  return ((MethodABI)R6GameServiceAddresses::CConnectionListDestroy)(owner);
}

// Clear owner+9c: delete optional payload+10 object, free current payload, unlink node and free it; retain head.
// Read payload and links again after callbacks; no rollback or own exception guard.
// R6GameService.dll @ 10053b80 : complete native control/access order and raw ABI retained.
uint __fastcall ClearOwnedList9c(void *owner)
{
  uint *headSlot = (uint *)((uint)owner + 0x9c);
  uint head = *headSlot;
  uint node = *(uint *)head;
  while (node != head) {
    uint payload = *(uint *)(node + 8);
    void *object = *(void **)(payload + 0x10);
    if (object != 0) {
      uint table = *(uint *)object;
      using DeleteABI = void * (__thiscall *)(void *,uint);
      ((DeleteABI)*(uint *)table)(object,1);
    }
    void *currentPayload = *(void **)(node + 8);
    TailFreeThroughGlobalAllocator(currentPayload);
    uint previous = *(uint *)(node + 4);
    uint next = *(uint *)node;
    *(uint *)previous = next;
    *(uint *)(next + 4) = previous;
    TailFreeThroughGlobalAllocator((void *)node);
    head = *headSlot;
    node = next;
  }
  return head;
}

// Clear owner+a4 using the same live payload/deleting-call/unlink/free order; retain head and borrowed fields.
// R6GameService.dll @ 10053bd0 : complete native control/access order and raw ABI retained.
uint __fastcall ClearOwnedLista4(void *owner)
{
  uint *headSlot = (uint *)((uint)owner + 0xa4);
  uint head = *headSlot;
  uint node = *(uint *)head;
  while (node != head) {
    uint payload = *(uint *)(node + 8);
    void *object = *(void **)(payload + 0x10);
    if (object != 0) {
      uint table = *(uint *)object;
      using DeleteABI = void * (__thiscall *)(void *,uint);
      ((DeleteABI)*(uint *)table)(object,1);
    }
    void *currentPayload = *(void **)(node + 8);
    TailFreeThroughGlobalAllocator(currentPayload);
    uint previous = *(uint *)(node + 4);
    uint next = *(uint *)node;
    *(uint *)previous = next;
    *(uint *)(next + 4) = previous;
    TailFreeThroughGlobalAllocator((void *)node);
    head = *headSlot;
    node = next;
  }
  return head;
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

// Finds a signed key using a captured header, then checks the current header and preserves its upper return bits.
// R6GameService.dll @ 10053c20 : ECX owner, signed key word, RET4; field/iterator names are inferred.
uint __thiscall ContainsIndexedKey(void *owner,int key)
{
  uint base = (uint)owner;
  uint capturedHead = *(uint *)(base + 0xac);
  int wanted = key;
  uint node = *(uint *)(capturedHead + 4);
  uint candidate = capturedHead;
  while (node != 0) {
    if (*(int *)(node + 0x10) < wanted) {
      node = *(uint *)(node + 0xc);
    } else {
      candidate = node;
      node = *(uint *)(node + 8);
    }
  }
  if (candidate == capturedHead || wanted < *(int *)(candidate + 0x10)) candidate = capturedHead;
  uint currentHead = *(uint *)(base + 0xac);
  bool found = candidate != currentHead;
  return (currentHead & 0xffffff00u) | (found ? 1u : 0u);
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
uint __thiscall ResetIndexedRecordState(void *owner,int key)
{
  void *tree = (void *)((uint)owner + 0xac);
  using FindABI = uint (__thiscall *)(void *,int *);
  uint record = ((FindABI)R6GameServiceAddresses::FindIndexedTreeKey)(tree,&key);
  uint head = *(uint *)tree;
  if (record == head) return record & 0xffffff00;
  *(byte *)(record + 0x98) = 0;
  *(uint *)(record + 0xa4) = 0;
  int currentKey = key;
  using RemoveABI = uint (__thiscall *)(void *,int);
  return ((RemoveABI)R6GameServiceAddresses::CConnectionListQueryKey)(owner,currentKey);
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

// Inferred physical slots at entry ESP-0x4c/-0x48/-0x44/-0x40, followed by envelope/fields at -0x3c/-0x24.
struct IndexedRemovalLocals {
  uint iterator;
  uint scratch;
  uint rangeOutput;
  uint cloneScratch;
  uint envelope[6];
  uint fields[6];
};

// Retain partial descriptor construction and base-only states after entered destruction; queued packets stay committed.
struct IndexedRemovalCleanup {
  IndexedRemovalLocals *frame;
  int state;
  bool armed;
  // State4's latent saved-pointer action uses current scratch; normal main-body cloning stays at state3.
  ~IndexedRemovalCleanup() noexcept(false)
  {
    if (!armed) return;
    while (state >= 0) {
      switch (state) {
      case 0: case 6:
        state = -1;
        ResetClDataVtable(frame->fields);
        break;
      case 1:
        state = -1;
        DestroyClDataListAlias(frame->fields);
        break;
      case 2: case 5:
        state = 1;
        ResetClDataVtable(frame->envelope);
        break;
      case 3:
        state = 1;
        DestroyClDataListAlias(frame->envelope);
        break;
      case 4:
        state = 3;
        DestroyClDataListAlias((void *)frame->scratch);
        break;
      }
    }
  }
};

// Notify linked values with selector37, release their links, optionally notify/reset state2, then erase the record.
// An empty remaining index queues selector2b with the current key inside its payload; outgoing clones are callee-owned.
// R6GameService.dll @ 10053d50 : complete native control/access order and raw ABI retained.
uint __thiscall RemoveIndexedRecordAndQueueNotifications(void *owner,uint key)
{
  IndexedRemovalLocals frame;
  IndexedRemovalCleanup cleanup{&frame,-1,true};
  uint base = (uint)owner;
  frame.iterator = 0;
  frame.fields[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.fields[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  InitializeClDataFields(frame.fields,3,0);
  cleanup.state = 0;
  ConstructClDataPointerList(frame.fields + 3,0);
  frame.fields[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.fields[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 1;
  frame.envelope[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.envelope[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  InitializeClDataFields(frame.envelope,3,0);
  cleanup.state = 2;
  ConstructClDataPointerList(frame.envelope + 3,0);
  frame.envelope[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.envelope[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  void *tree = (void *)(base + 0xac);
  cleanup.state = 3;
  uint record = FindIndexedTreeKey(tree,(int *)&key);
  uint indexHead = *(uint *)tree;
  if (record == indexHead) {
    cleanup.state = 1;
    DestroyClDataList(frame.envelope);
    cleanup.state = -1;
    uint result = DestroyClDataList(frame.fields);
    cleanup.armed = false;
    return result & 0xffffff00;
  }
  // Native inlined range clearing caches end/virtual slot before obtaining first, then loads the target late.
  auto clearRange = [](uint *descriptor,uint *output) {
    uint end = descriptor[4];
    uint first = end;
    uint slot = descriptor[3] + 0x10;
    ReadListFirstNodeFromHeadSlot(descriptor + 4,&first);
    using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
    ((RangeABI)*(uint *)slot)(descriptor + 3,output,first,end);
  };
  uint head = *(uint *)(record + 0x9c);
  uint cursor = *(uint *)head;
  frame.iterator = cursor;
  uint currentHead = *(uint *)(record + 0x9c);
  if (cursor != currentHead) {
    do {
      AppendClDataListSignedDecimal(frame.fields,(void *)(cursor + 8));
      AppendClDataListSignedDecimal(frame.fields,&key);
      frame.scratch = 0x37;
      AppendClDataListSignedDecimal(frame.envelope,&frame.scratch);
      AppendClDataListCopy(frame.envelope,frame.fields);
      NativeDescriptorArgument24 outgoing;
      frame.scratch = (uint)&outgoing;
      CopyConstructClDataList(&outgoing,frame.envelope,1);
      cleanup.state = 3;
      uint valueStorage = GetReferencedStoragePlus8(&frame.iterator);
      uint currentKey = key;
      uint currentValue = *(uint *)valueStorage;
      QueueTaggedRecord((void *)base,2,currentValue,currentKey,0xd1,0,outgoing);
      clearRange(frame.fields,&frame.rangeOutput);
      clearRange(frame.envelope,&frame.cloneScratch);
      uint current = frame.iterator;
      cursor = *(uint *)current;
      frame.iterator = cursor;
      currentHead = *(uint *)(record + 0x9c);
    } while (cursor != currentHead);
  }
  head = *(uint *)(record + 0x9c);
  cursor = *(uint *)head;
  if (cursor != head) {
    do {
      uint doomed = cursor;
      cursor = *(uint *)cursor;
      TailFreeThroughGlobalAllocator((void *)doomed);
    } while (cursor != *(uint *)(record + 0x9c));
  }
  head = *(uint *)(record + 0x9c);
  *(uint *)head = head;
  head = *(uint *)(record + 0x9c);
  *(uint *)(head + 4) = head;
  if ((byte)IndexedRecordHasState2((void *)base,key) != 0) {
    AppendClDataListSignedDecimal(frame.fields,&key);
    frame.scratch = 0x12;
    AppendClDataListSignedDecimal(frame.envelope,&frame.scratch);
    AppendClDataListCopy(frame.envelope,frame.fields);
    NativeDescriptorArgument24 outgoing;
    frame.cloneScratch = (uint)&outgoing;
    CopyConstructClDataList(&outgoing,frame.envelope,1);
    uint currentKey = key;
    QueueTaggedRecord((void *)base,2,0,currentKey,0xd1,0,outgoing);
    ResetIndexedRecordState((void *)base,key);
  }
  clearRange(frame.fields,&frame.cloneScratch);
  clearRange(frame.envelope,&frame.cloneScratch);
  EraseIndexedNode((void *)(base + 0xac),(char *)record);
  if (*(uint *)(base + 0xb0) == 0) {
    AppendClDataListSignedDecimal(frame.fields,&key);
    frame.scratch = 0x2b;
    AppendClDataListSignedDecimal(frame.envelope,&frame.scratch);
    AppendClDataListCopy(frame.envelope,frame.fields);
    NativeDescriptorArgument24 outgoing;
    frame.cloneScratch = (uint)&outgoing;
    CopyConstructClDataList(&outgoing,frame.envelope,1);
    QueueTaggedRecord((void *)base,2,0,0,0xd1,0,outgoing);
  }
  frame.envelope[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.envelope[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 5;
  DestroyClDataPointerList(frame.envelope + 3);
  frame.envelope[0] = R6GameServiceAddresses::PTR_LAB;
  frame.fields[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.fields[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 6;
  uint result = DestroyClDataPointerList(frame.fields + 3);
  cleanup.armed = false;
  return (result & 0xffffff00) | 1;
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
// R6GameService.dll data @ 10083974 : native storage identity retained.
const R6GameServiceNative::FuncInfo RemoveIndexedRecordAndQueueNotificationsExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotificationsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Inferred physical local slots from entry ESP-0x64 through ESP-0x10; descriptor roles describe their contents.
struct IndexedKeyUpdateLocals {
  byte padding[3];
  byte countTag;
  uint scratch;
  uint endOrClone;
  uint first;
  uint request[6];
  uint fields[6];
  uint command[6];
};

// Retain incoming ownership and each partially constructed list; entered cleanup is never retried.
struct IndexedKeyUpdateCleanup {
  IndexedKeyUpdateLocals *frame;
  uint *incoming;
  int state;
  bool armed;
  // Follow the native eight-state ownership map using current physical descriptor slots.
  ~IndexedKeyUpdateCleanup() noexcept(false)
  {
    if (!armed) return;
    while (state >= 0) {
      switch (state) {
      case 0:
        state = -1;
        DestroyClDataListAlias(incoming);
        break;
      case 1:
        state = 0;
        ResetClDataVtable(frame->command);
        break;
      case 2:
        state = 0;
        DestroyClDataListAlias(frame->command);
        break;
      case 3:
        state = 2;
        ResetClDataVtable(frame->request);
        break;
      case 4:
        state = 2;
        DestroyClDataListAlias(frame->request);
        break;
      case 5:
        state = 4;
        ResetClDataVtable(frame->fields);
        break;
      case 6:
        state = 4;
        DestroyClDataListAlias(frame->fields);
        break;
      case 7:
        state = -1;
        ResetClDataVtable(incoming);
        break;
      }
    }
  }
};

// Queue an unknown key or an inactive known record; otherwise send D1 through its active connection.
// Keep current arguments, callee-owned outgoing clones and final destructor upper EAX with the selected raw AL.
// R6GameService.dll @ 100542a0 : complete native control/access order and raw ABI retained.
uint __thiscall ApplyIndexedKeyUpdate(void *owner,uint value,uint key,uint code,
    uint modeWord,NativeDescriptorArgument24 descriptor)
{
  IndexedKeyUpdateLocals frame;
  IndexedKeyUpdateCleanup cleanup{&frame,descriptor.words,0,true};
  uint base = (uint)owner;
  frame.endOrClone = 0;
  frame.command[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.command[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  InitializeClDataFields(frame.command,3,0);
  cleanup.state = 1;
  ConstructClDataPointerList(frame.command + 3,0);
  frame.command[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.command[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 2;
  frame.request[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.request[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  InitializeClDataFields(frame.request,3,0);
  cleanup.state = 3;
  ConstructClDataPointerList(frame.request + 3,0);
  frame.request[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.request[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 4;
  frame.fields[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.fields[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  InitializeClDataFields(frame.fields,3,0);
  cleanup.state = 5;
  ConstructClDataPointerList(frame.fields + 3,0);
  frame.fields[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.fields[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 6;
  bool unknown = (byte)ContainsIndexedKey((void *)base,key) == 0;
  bool inactive = false;
  if (unknown) {
    RemoveListRecordsBySecondWord((void *)base,key);
    frame.scratch = 0x13;
    AppendClDataListSignedDecimal(frame.fields,&frame.scratch);
    AppendClDataListSignedDecimal(frame.fields,&value);
    AppendClDataListSignedDecimal(frame.command,&code);
    AppendClDataListCopy(frame.command,frame.fields);
    frame.scratch = 0x27;
    AppendClDataListSignedDecimal(frame.request,&frame.scratch);
    AppendClDataListCopy(frame.request,frame.command);
    // Raw outgoing stack storage transfers to QueueTaggedRecord; no caller-side descriptor destructor.
    NativeDescriptorArgument24 outgoing;
    frame.scratch = (uint)&outgoing;
    CopyConstructClDataList(&outgoing,frame.request,1);
    uint currentMode = modeWord;
    uint currentKey = key;
    uint currentValue = value;
    QueueTaggedRecord((void *)base,2,currentValue,currentKey,0xd1,currentMode,outgoing);
  } else {
    FindIndexedTreeLowerBound((void *)(base + 0xac),(int *)&frame.scratch,(int *)&key);
    inactive = CConnectionListFindBorrowed((void *)base,key) == 0;
    if (inactive) {
      if (*(byte *)(frame.scratch + 0x98) == 0) SendKeyNotificationD1((void *)base,key);
      AppendClDataListSignedDecimal(frame.request,&code);
      AppendClDataListCopy(frame.request,descriptor.words);
      NativeDescriptorArgument24 outgoing;
      frame.endOrClone = (uint)&outgoing;
      CopyConstructClDataList(&outgoing,frame.request,1);
      uint currentMode = modeWord;
      uint currentKey = key;
      uint currentValue = value;
      QueueTaggedRecord((void *)base,1,currentValue,currentKey,0xd1,currentMode,outgoing);
    } else {
      uint record = frame.scratch;
      frame.endOrClone = *(uint *)(record + 0x9c);
      uint *first = ReadListFirstNodeFromHeadSlot((void *)(record + 0x9c),&frame.first);
      frame.countTag = (byte)key;
      if (CountCircularListRange(first,&frame.endOrClone,&frame.countTag) == 0) *(uint *)(record + 0xa4) = 0;
      AppendClDataListSignedDecimal(frame.request,&code);
      AppendClDataListCopy(frame.request,descriptor.words);
      uint currentMode = modeWord;
      uint currentKey = key;
      uint sent = CConnectionListSendToKey((void *)base,currentKey,0xd1,currentMode,(int)frame.request);
      *(byte *)&modeWord = (byte)sent;
    }
  }
  cleanup.state = 4;
  DestroyClDataList(frame.fields);
  cleanup.state = 2;
  DestroyClDataList(frame.request);
  cleanup.state = 0;
  DestroyClDataList(frame.command);
  uint result;
  if (inactive) {
    descriptor.words[0] = R6GameServiceAddresses::clDataListPTR_FUN;
    descriptor.words[3] = R6GameServiceAddresses::clDataListPTR_LAB;
    cleanup.state = 7;
    result = DestroyClDataPointerList(descriptor.words + 3);
    result = (result & 0xffffff00) | 1;
  } else {
    cleanup.state = -1;
    result = DestroyClDataList(descriptor.words);
    result = (result & 0xffffff00) | (unknown ? 0 : (byte)modeWord);
  }
  cleanup.armed = false;
  return result;
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

// Inferred logical builder slots: recordS-14, guarded raw cloneS-10 and entered-clear scratchS-60.
struct TaggedRecordQueueLocals {
  uint record;
  uint rawClone;
  uint cleanupHead;
};

// Consume the incoming descriptor, freeing only a pending raw clone on construction failure; the record is unguarded.
struct TaggedRecordQueueCleanup {
  TaggedRecordQueueLocals *frame;
  uint *incoming;
  uint *contextWord;
  int state;
  bool armed;
  // Entered incoming cleanup frees the current rewritten context's head, then resets only the incoming base.
  ~TaggedRecordQueueCleanup() noexcept(false)
  {
    if (!armed) return;
    while (state >= 0) {
      switch (state) {
      case 0:
        state = -1;
        DestroyClDataListAlias(incoming);
        break;
      case 1:
        state = 0;
        ForwardToAllocatorTail((void *)frame->rawClone);
        break;
      case 2:
        state = -1;
        ResetClDataVtable(incoming);
        break;
      case 3:
        state = 2;
        frame->cleanupHead = *contextWord == 0 ? 0 : *contextWord + 4;
        ReleaseNodesAndSentinel((void *)frame->cleanupHead);
        break;
      }
    }
  }
};

// Clone incoming payload into a record, publish the same record under cached mask bits, then consume the incoming list.
// Preserve late fields/current record slot, nullable clone results, retained padding and unguarded record allocation.
// R6GameService.dll @ 10054660 : complete native control/access order and raw ABI retained.
uint __thiscall QueueTaggedRecord(void *owner,uint flags,uint value,uint key,uint opcode,
    uint byteField,NativeDescriptorArgument24 payload)
{
  TaggedRecordQueueLocals frame;
  TaggedRecordQueueCleanup cleanup{&frame,payload.words,&byteField,0,true};
  uint base = (uint)owner;
  frame.record = (uint)AllocateGameServiceBytes(0x14);
  uint allocation = (uint)AllocateGameServiceBytes(0x18);
  frame.rawClone = allocation;
  cleanup.state = 1;
  void *clone = nullptr;
  if (allocation != 0) clone = CopyConstructClDataList((void *)allocation,payload.words,1);
  uint target = frame.record;
  uint currentValue = value;
  cleanup.state = 0;
  byte mask = (byte)flags;
  *(uint *)target = currentValue;
  target = frame.record;
  uint currentKey = key;
  *(uint *)(target + 4) = currentKey;
  target = frame.record;
  byte capturedByte = (byte)byteField;
  *(void **)(target + 0x10) = clone;
  target = frame.record;
  uint currentOpcode = opcode;
  *(byte *)(target + 0xc) = capturedByte;
  target = frame.record;
  currentOpcode &= 0xff;
  *(uint *)(target + 8) = currentOpcode;
  if ((mask & 2) != 0) {
    void *headSlot = (void *)(base + 0xa4);
    CopyListHeadSlot(headSlot,&byteField);
    uint node = (uint)AllocateListPayloadNode((void **)&frame.record);
    uint head = byteField;
    uint previous = *(uint *)(head + 4);
    *(uint *)node = head;
    *(uint *)(node + 4) = previous;
    *(uint *)previous = node;
    *(uint *)(head + 4) = node;
  }
  if ((mask & 1) != 0) {
    void *headSlot = (void *)(base + 0x9c);
    CopyListHeadSlot(headSlot,&byteField);
    uint node = (uint)AllocateListPayloadNode((void **)&frame.record);
    uint head = byteField;
    uint previous = *(uint *)(head + 4);
    *(uint *)node = head;
    *(uint *)(node + 4) = previous;
    *(uint *)previous = node;
    *(uint *)(head + 4) = node;
  }
  payload.words[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 2;
  byteField = (uint)(payload.words + 3);
  payload.words[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  uint pastLast = payload.words[4];
  uint first = pastLast;
  cleanup.state = 3;
  ReadListFirstNodeFromHeadSlot(payload.words + 4,&first);
  uint table = payload.words[3];
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  ((RangeABI)*(uint *)(table + 0x10))(payload.words + 3,&value,first,pastLast);
  cleanup.state = 2;
  uint result = ReleaseNodesAndSentinel(payload.words + 4);
  cleanup.armed = false;
  return result;
}

// Inferred physical cookie/scratch/local descriptor at entry ESP-0x2c/-0x28/-0x24; cleanup heads are logical slots.
struct DescriptorD1Locals {
  byte cookieStorage[4];
  uint unused;
  uint descriptor[6];
  uint localCleanupHead;
  uint incomingCleanupHead;
};

// Preserve incoming ownership, partial local construction and head-only cleanup after entered virtual range clearing.
struct DescriptorD1Cleanup {
  DescriptorD1Locals *frame;
  uint *incoming;
  uint *modeWord;
  int state;
  bool armed;
  // Re-read the rewritten mode context before either entered-clear cleanup; retain native NULL forwarding.
  ~DescriptorD1Cleanup() noexcept(false)
  {
    if (!armed) return;
    using EmptyABI = void (__thiscall *)(void *);
    while (state >= 0) {
      switch (state) {
      case 0:
        state = -1;
        DestroyClDataListAlias(incoming);
        break;
      case 1: case 4:
        state = 0;
        ResetClDataVtable(frame->descriptor);
        break;
      case 2:
        state = 1;
        ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(frame->cookieStorage + 3);
        break;
      case 3:
        state = 0;
        DestroyClDataListAlias(frame->descriptor);
        break;
      case 5:
        state = 4;
        frame->localCleanupHead = *modeWord == 0 ? 0 : *modeWord + 4;
        ReleaseNodesAndSentinel((void *)frame->localCleanupHead);
        break;
      case 6:
        state = -1;
        ResetClDataVtable(incoming);
        break;
      case 7:
        state = 6;
        frame->incomingCleanupHead = *modeWord == 0 ? 0 : *modeWord + 4;
        ReleaseNodesAndSentinel((void *)frame->incomingCleanupHead);
        break;
      }
    }
  }
};

// Broadcast selector/incoming descriptor as D1, then consume both lists while retaining the broadcast's raw AL.
// The mode argument becomes the current cleanup context; incoming primary remains derived after normal release.
// R6GameService.dll @ 100547d0 : complete native control/access order and raw ABI retained.
uint __thiscall SendDescriptorAsD1(void *owner,uint selector,uint modeWord,NativeDescriptorArgument24 descriptor)
{
  DescriptorD1Locals frame;
  DescriptorD1Cleanup cleanup{&frame,descriptor.words,&modeWord,0,true};
  void *savedOwner = owner;
  frame.unused = 0;
  frame.descriptor[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.descriptor[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.descriptor[2] = 3;
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 2;
  InitializePayloadListHeader(frame.descriptor + 4,(uint)(frame.cookieStorage + 3));
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 3;
  AppendClDataListSignedDecimal(frame.descriptor,&selector);
  AppendClDataListCopy(frame.descriptor,descriptor.words);
  uint currentMode = modeWord;
  uint sent = CConnectionListBroadcast(savedOwner,0xd1,currentMode,(int)frame.descriptor);
  byte resultByte = (byte)sent;
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  modeWord = (uint)(frame.descriptor + 3);
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 5;
  InvokePointerListClearRange(frame.descriptor + 3);
  cleanup.state = 4;
  ReleaseNodesAndSentinel(frame.descriptor + 4);
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  descriptor.words[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 6;
  modeWord = (uint)(descriptor.words + 3);
  descriptor.words[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 7;
  InvokePointerListClearRange(descriptor.words + 3);
  cleanup.state = 6;
  uint released = ReleaseNodesAndSentinel(descriptor.words + 4);
  cleanup.armed = false;
  return (released & 0xffffff00) | resultByte;
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

// Inferred key sender locals: opcode scratchS-44, current recordS-40, envelopeS-3c and key payloadS-24.
struct KeyNotificationLocals {
  uint opcode;
  uint record;
  uint envelope[6];
  uint payload[6];
};

// Release only completed descriptor stages; entered member destruction resets its base without retrying its storage.
struct KeyNotificationCleanup {
  KeyNotificationLocals *frame;
  int state;
  bool armed;
  // The second descriptor precedes the first in full cleanup; states5/7 reset only the first descriptor base.
  ~KeyNotificationCleanup() noexcept(false)
  {
    if (!armed) return;
    while (state >= 0) {
      switch (state) {
      case 0: case 5: case 7:
        state = -1;
        ResetClDataVtable(frame->payload);
        break;
      case 1:
        state = -1;
        DestroyClDataListAlias(frame->payload);
        break;
      case 2: case 4: case 6:
        state = 1;
        ResetClDataVtable(frame->envelope);
        break;
      case 3:
        state = 1;
        DestroyClDataListAlias(frame->envelope);
        break;
      }
    }
  }
};

// Send a keyed D1 notification, marking the current saved record+98 after successful send and before local cleanup.
// Missing keys return lookup upper EAX/AL0 without allocation. Key/transport/record reads stay late; names inferred.
// R6GameService.dll @ 10053970 : complete native control/access order and raw ABI retained.
uint __thiscall SendKeyNotificationD1(void *owner,int key)
{
  KeyNotificationLocals frame;
  KeyNotificationCleanup cleanup{&frame,-1,true};
  void *savedOwner = owner;
  void *tree = (byte *)savedOwner + 0xac;
  frame.opcode = 0;
  uint record = FindIndexedTreeKey(tree,&key);
  uint head = *(uint *)tree;
  frame.record = record;
  if (record == head) return record & 0xffffff00u;
  frame.payload[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.payload[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.payload[2] = 3;
  frame.payload[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 0;
  ConstructClDataPointerList(frame.payload + 3,0);
  frame.payload[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.payload[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 1;
  frame.envelope[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.envelope[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.envelope[2] = 3;
  frame.envelope[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 2;
  ConstructClDataPointerList(frame.envelope + 3,0);
  frame.envelope[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.envelope[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 3;
  AppendClDataListSignedDecimal(frame.payload,&key);
  frame.opcode = 3;
  AppendClDataListSignedDecimal(frame.envelope,&frame.opcode);
  uint copied = AppendClDataListCopy(frame.envelope,frame.payload);
  void *currentTransport = *(void **)((byte *)savedOwner + 0x1d0);
  uint sent = SendTransportPayload(currentTransport,0xd1,1,frame.envelope,copied);
  bool success = (byte)sent != 0;
  uint result;
  if (!success) {
    frame.envelope[0] = R6GameServiceAddresses::clDataListPTR_FUN;
    frame.envelope[3] = R6GameServiceAddresses::clDataListPTR_LAB;
    cleanup.state = 4;
    DestroyClDataPointerList(frame.envelope + 3);
    frame.envelope[0] = R6GameServiceAddresses::PTR_LAB;
    frame.payload[0] = R6GameServiceAddresses::clDataListPTR_FUN;
    frame.payload[3] = R6GameServiceAddresses::clDataListPTR_LAB;
    cleanup.state = 5;
    result = DestroyClDataPointerList(frame.payload + 3);
  } else {
    uint currentRecord = frame.record;
    *(byte *)(currentRecord + 0x98) = 1;
    frame.envelope[0] = R6GameServiceAddresses::clDataListPTR_FUN;
    frame.envelope[3] = R6GameServiceAddresses::clDataListPTR_LAB;
    cleanup.state = 6;
    DestroyClDataPointerList(frame.envelope + 3);
    frame.envelope[0] = R6GameServiceAddresses::PTR_LAB;
    frame.payload[0] = R6GameServiceAddresses::clDataListPTR_FUN;
    frame.payload[3] = R6GameServiceAddresses::clDataListPTR_LAB;
    cleanup.state = 7;
    result = DestroyClDataPointerList(frame.payload + 3);
  }
  cleanup.armed = false;
  return (result & 0xffffff00u) | (success ? 1u : 0u);
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

// Computes each successor before removal, loads the old key last and ignores removal status; final AL is always one.
// R6GameService.dll @ 10054110 : ECX owner, no stack words; iterator/field names are inferred.
uint __fastcall ProcessIndexedRecordsInKeyOrder(void *owner)
{
  uint base = (uint)owner;
  uint head = *(uint *)(base + 0xac);
  uint cursor = *(uint *)(head + 8);
  uint result = head;
  using RemoveABI = uint (__thiscall *)(void *,int);
  while (cursor != head) {
    uint previous = cursor;
    uint right = *(uint *)(cursor + 0xc);
    if (right != 0) {
      cursor = right;
      uint left = *(uint *)(cursor + 8);
      while (left != 0) {
        cursor = left;
        left = *(uint *)(cursor + 8);
      }
    } else {
      uint parent = *(uint *)(cursor + 4);
      while (cursor == *(uint *)(parent + 0xc)) {
        cursor = parent;
        parent = *(uint *)(parent + 4);
      }
      if (*(uint *)(cursor + 0xc) != parent) cursor = parent;
    }
    int key = *(int *)(previous + 0x10);
    result = ((RemoveABI)R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotifications)(owner,key);
    head = *(uint *)(base + 0xac);
  }
  return (result & 0xffffff00u) | 1u;
}

// Finds a signed key using a captured header, then checks the current header and preserves its upper return bits.
// R6GameService.dll @ 10054170 : ECX owner, signed key word, RET4; field/iterator names are inferred.
uint __thiscall IndexedRecordHasState2(void *owner,int key)
{
  uint base = (uint)owner;
  uint capturedHead = *(uint *)(base + 0xac);
  int wanted = key;
  uint node = *(uint *)(capturedHead + 4);
  uint candidate = capturedHead;
  while (node != 0) {
    if (*(int *)(node + 0x10) < wanted) {
      node = *(uint *)(node + 0xc);
    } else {
      candidate = node;
      node = *(uint *)(node + 8);
    }
  }
  if (candidate == capturedHead || wanted < *(int *)(candidate + 0x10)) candidate = capturedHead;
  uint currentHead = *(uint *)(base + 0xac);
  bool found = candidate != currentHead && *(byte *)(candidate + 0x98) == 2;
  return (currentHead & 0xffffff00u) | (found ? 1u : 0u);
}


// Remove pending records matching a captured second word; reload payload/links after their respective callbacks.
// Return initial head for an empty list, last unmatched payload, or the last node-free result. No cleanup or rollback.
// R6GameService.dll @ 100541d0 : complete native control/access order and raw ABI retained.
uint __thiscall RemoveListRecordsBySecondWord(void *owner,int secondWord)
{
  uint base = (uint)owner;
  uint head = *(uint *)(base + 0xa4);
  uint node = *(uint *)head;
  uint result = head;
  if (node == head) return result;
  int capturedSecond = secondWord;
  do {
    uint payload = *(uint *)(node + 8);
    result = payload;
    if (*(int *)(payload + 4) == capturedSecond) {
      void *object = *(void **)(payload + 0x10);
      if (object != nullptr) {
        uint table = *(uint *)object;
        using DeleteABI = void * (__thiscall *)(void *,uint);
        ((DeleteABI)*(uint *)table)(object,1);
      }
      void *currentPayload = *(void **)(node + 8);
      TailFreeThroughGlobalAllocator(currentPayload);
      uint previous = *(uint *)(node + 4);
      uint next = *(uint *)node;
      *(uint *)previous = next;
      *(uint *)(next + 4) = previous;
      result = TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    } else {
      node = *(uint *)node;
    }
  } while (node != *(uint *)(base + 0xa4));
  return result;
}

// Remove matching word pairs, capturing the second word but reloading the first word for each candidate match.
// Nonmatches use a pre-comparison successor; matches reload links after callbacks. Return the final cursor, RET8.
// R6GameService.dll @ 10054230 : complete native control/access order and raw ABI retained.
uint __thiscall RemoveListRecordsByWordPair(void *owner,int secondWord,int firstWord)
{
  uint base = (uint)owner;
  uint head = *(uint *)(base + 0xa4);
  uint cursor = *(uint *)head;
  if (cursor == head) return cursor;
  int capturedSecond = secondWord;
  do {
    uint node = cursor;
    cursor = *(uint *)node;
    uint payload = *(uint *)(node + 8);
    if (*(int *)(payload + 4) == capturedSecond) {
      int currentFirst = firstWord;
      int storedFirst = *(int *)payload;
      if (storedFirst == currentFirst) {
        void *object = *(void **)(payload + 0x10);
        if (object != nullptr) {
          uint table = *(uint *)object;
          using DeleteABI = void * (__thiscall *)(void *,uint);
          ((DeleteABI)*(uint *)table)(object,1);
        }
        void *currentPayload = *(void **)(node + 8);
        TailFreeThroughGlobalAllocator(currentPayload);
        uint previous = *(uint *)(node + 4);
        uint next = *(uint *)node;
        *(uint *)previous = next;
        *(uint *)(next + 4) = previous;
        TailFreeThroughGlobalAllocator((void *)node);
        cursor = next;
      }
    }
  } while (cursor != *(uint *)(base + 0xa4));
  return cursor;
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
