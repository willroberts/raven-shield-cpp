#include "native_addresses.h"
#include "native_records.h"

// Inferred two-state guard releases pending embedded list storage, then resets the descriptor base.
struct ProxyMessageDestructionCleanup {
  void *savedDescriptor;
  void *savedList;
  int state;
  // Entered list cleanup is not retried; base-table reset uses the current saved descriptor.
  ~ProxyMessageDestructionCleanup() noexcept(false)
  {
    using MethodABI = uint (__fastcall *)(void *);
    using ResetABI = void (__fastcall *)(void *);
    if (state == 1) {
      state = 0;
      void *slot = savedList == 0 ? 0 : (void *)((uint)savedList + 4);
      ((MethodABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(slot);
    }
    if (state == 0) {
      state = -1;
      ((ResetABI)R6GameServiceAddresses::ResetClDataVtable)(savedDescriptor);
    }
  }
};

// clProxyMessage payload role follows proxy-message-list RTTI and all four typed destruction callers.
// The original destructor spelling/layout remains inferred; only embedded descriptor8 and its actual operations are represented.

// Destroy embedded descriptor at+8 via captured generic range, CURRENT links/head, then reset only its base table.
// Preserve prefix bytes, outer allocation and state1 head-only/state0 base-only cleanup. Raw final free EAX.
// R6GameService.dll @ 10062aa0 : complete native control/access order and raw ABI retained.
uint __fastcall DestroyPerNodeLinkedListContainer(void *owner)
{
  uint descriptor = (uint)owner + 8;
  ProxyMessageDestructionCleanup cleanup;
  cleanup.savedDescriptor = (void *)descriptor;
  cleanup.state = -1;
  uint list = descriptor + 0xc;
  *(uint *)descriptor = R6GameServiceAddresses::clDataListPTR_FUN;
  *(uint *)list = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 0;
  cleanup.savedList = (void *)list;
  *(uint *)list = R6GameServiceAddresses::clDataListPTR_FUN2;
  uint end = *(uint *)(list + 4);
  void *headSlot = (void *)(list + 4);
  uint begin = end;
  uint table = *(uint *)list;
  cleanup.state = 1;
  using FirstABI = uint *(__thiscall *)(void *,uint *);
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(headSlot,&begin);
  uint ignored;
  using RangeABI = uint *(__thiscall *)(void *,uint *,uint,uint);
  (*(RangeABI *)(table + 0x10))((void *)list,&ignored,begin,end);
  cleanup.state = 0;
  using MethodABI = uint (__fastcall *)(void *);
  ((MethodABI)R6GameServiceAddresses::ReleaseListNodesRetainHeader)(headSlot);
  void *head = *(void **)headSlot;
  uint result = TailFreeThroughGlobalAllocator(head);
  *(uint *)descriptor = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = -1;
  return result;
}

// Reset only the embedded descriptor base at CURRENT saved descriptor pointer; do not retry list release.
// R6GameService.dll @ 1006a050 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPerNodeLinkedListContainerUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release nodes/head through CURRENT saved embedded list interface, preserving NULL/context scratch.
// R6GameService.dll @ 1006a058 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPerNodeLinkedListContainerUnwind2(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch1
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x1c],eax
    jmp    Branch2
  Branch1:
    mov    DWORD PTR [ebp-0x1c],0x0
  Branch2:
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact two-state embedded descriptor cleanup map and tail CRT dispatch.
// R6GameService.dll @ 1006a07f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxyMessageEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyPerNodeLinkedListContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native proxy-message list/payload cleanup records.
// R6GameService.dll data @ 10084b80 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyPerNodeLinkedListContainerUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwind1},
  {0x0, R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwind2},
};
// R6GameService.dll data @ 10084b90 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyPerNodeLinkedListContainerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
