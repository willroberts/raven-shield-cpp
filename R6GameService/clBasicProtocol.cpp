#include "native_addresses.h"
#include "native_records.h"

// clBasicProtocol: primary78304/COL7a6fc/type90814 establish native class ownership; declarations remain inferred.

// Optionally install offset table78314, clear selected fields, build two12-byte sentinels, then publish primary78304.
// Each head is published only after its links; sentinel payload/other fields stay untouched. No local EH/NULL guard. RET4/owner.
// R6GameService.dll @ 1005fab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeRecordOwnerStorage(void *owner,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0x8]
    push    ebx
    xor    ebx,ebx
    push    esi
    cmp    eax,ebx
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],ebx
    je    Branch1
    mov    DWORD PTR [esi+0x4],0x10078314
  Branch1:
    mov    DWORD PTR [esi+0x8],ebx
    mov    WORD PTR [esi+0x8e],bx
    mov    WORD PTR [esi+0x90],bx
    mov    DWORD PTR [esi+0x94],ebx
    mov    WORD PTR [esi+0x11a],bx
    mov    DWORD PTR [esi+0x120],ebx
    push    0xc
    mov    DWORD PTR [esi+0x128],0x1007830c
    mov    DWORD PTR [esi+0x124],ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x124],eax
    push    0xc
    mov    DWORD PTR [esi+0x130],0x1007830c
    mov    DWORD PTR [esi+0x12c],ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x12c],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clBasicProtocolVTable
    mov    BYTE PTR [esi+0xc],bl
    mov    BYTE PTR [esi+0x98],bl
    mov    eax,esi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Destroy base protocol, then test CURRENT deletion flag bit0 and optionally free cached owner; return owner/RET4.
// R6GameService.dll @ 1005fb50 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clBasicProtocol_DeleteObject(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyRecordOwnerStorage
    test    BYTE PTR [esp+0x8],0x1
    je    Branch2
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

namespace {
// Inferred saved owner/list context and states for the native three-state base-protocol storage lifetime.
struct BasicProtocolStorageCleanup {
  void *savedOwner;
  void *savedListContext;
  int state;
  // Release current node storage without retrying payload destruction; state2 skips the already-entered second list.
  ~BasicProtocolStorageCleanup() noexcept(false) {
    using ReleaseABI = uint (__thiscall *)(void *);
    if (state == 1) {
      void *slot = (void *)((uint)savedOwner + 0x12c);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)(slot);
    } else if (state == 2) {
      using EmptyABI = void (__thiscall *)(void *);
      ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(savedListContext);
    }
    if (state >= 0) {
      void *slot = (void *)((uint)savedOwner + 0x124);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinelThunk)(slot);
    }
  }
};
}

// Install base primary, clear members, release CURRENT12c nodes/head then CURRENT124 nodes/head; retain dangling head fields.
// State1 protects both node lists; state2 disarms second-list retry. Saved owner/context/state map to S-14/S-10/S-4.
// Preserve successor caching, separate head reloads, three-state cleanup and raw final free EAX.
// R6GameService.dll @ 1005fb70 : inferred saved-context guard; no payload retry or owner-field clearing.
uint __fastcall DestroyRecordOwnerStorage(void *owner)
{
  BasicProtocolStorageCleanup cleanup{owner, nullptr, -1};
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::clBasicProtocolVTable;
  cleanup.state = 1;
  using ClearABI = uint (__thiscall *)(void *);
  ((ClearABI)R6GameServiceAddresses::ClearRecordOwnerMembers)(owner);
  uint *headSlot = (uint *)(base + 0x12c);
  cleanup.savedListContext = headSlot;
  uint head = *headSlot;
  cleanup.state = 2;
  uint node = *(uint *)head;
  using ReleaseABI = uint (__thiscall *)(void *,void *,uint);
  while (node != head) {
    uint released = node;
    node = *(uint *)node;
    ((ReleaseABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(headSlot,(void *)released,1);
    head = *headSlot;
  }
  head = *headSlot;
  *(uint *)head = head;
  head = *headSlot;
  *(uint *)(head + 4) = head;
  head = *headSlot;
  ((ReleaseABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(headSlot,(void *)head,1);
  head = *(uint *)(base + 0x124);
  node = *(uint *)head;
  using FreeABI = uint (__stdcall *)(void *);
  while (node != head) {
    uint released = node;
    node = *(uint *)node;
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)released);
    head = *(uint *)(base + 0x124);
  }
  head = *(uint *)(base + 0x124);
  *(uint *)head = head;
  head = *(uint *)(base + 0x124);
  *(uint *)(head + 4) = head;
  void *sentinel = *(void **)(base + 0x124);
  uint result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(sentinel);
  cleanup.state = -1;
  return result;
}

// Delete payloads of CURRENT124 then12c lists, then free12c nodes and124 nodes, resetting current heads separately.
// Release current120 association with physical WORD11c argument retaining124-head upper16, clear120 only AFTER return.
// No own EH; current next/head accesses survive callbacks, fields keep freed payload pointers, AL1 with raw upper EAX.
// R6GameService.dll @ 1005fc70 : inferred list/association views; physical argument width and raw AL result retained.
uint __fastcall ClearRecordOwnerMembers(void *owner)
{
  uint base = (uint)owner;
  uint head = *(uint *)(base + 0x124);
  uint node = *(uint *)head;
  while (node != head) {
    void *object = *(void **)(node + 8);
    if (object != 0) {
      using DeleteABI = void (__thiscall *)(void *,uint);
      DeleteABI destroy = *(DeleteABI *)*(void **)object;
      destroy(object,1);
    }
    node = *(uint *)node;
    head = *(uint *)(base + 0x124);
  }
  head = *(uint *)(base + 0x12c);
  node = *(uint *)head;
  while (node != head) {
    void *object = *(void **)(node + 8);
    if (object != 0) {
      using DeleteABI = void (__thiscall *)(void *,uint);
      DeleteABI destroy = *(DeleteABI *)*(void **)object;
      destroy(object,1);
    }
    node = *(uint *)node;
    head = *(uint *)(base + 0x12c);
  }
  using FreeABI = uint (__stdcall *)(void *);
  head = *(uint *)(base + 0x12c);
  node = *(uint *)head;
  while (node != head) {
    uint released = node;
    node = *(uint *)node;
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)released);
    head = *(uint *)(base + 0x12c);
  }
  head = *(uint *)(base + 0x12c);
  *(uint *)head = head;
  head = *(uint *)(base + 0x12c);
  *(uint *)(head + 4) = head;
  head = *(uint *)(base + 0x124);
  node = *(uint *)head;
  while (node != head) {
    uint released = node;
    node = *(uint *)node;
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)released);
    head = *(uint *)(base + 0x124);
  }
  head = *(uint *)(base + 0x124);
  *(uint *)head = head;
  head = *(uint *)(base + 0x124);
  *(uint *)(head + 4) = head;
  uint result = head;
  void *association = *(void **)(base + 0x120);
  if (association != 0) {
    uint keyWord = (result & 0xffff0000) | *(ushort *)(base + 0x11c);
    using ReleaseABI = uint (__thiscall *)(void *,uint);
    result = ((ReleaseABI)R6GameServiceAddresses::RemoveKeyAndRecycleOrDestroy)(association,keyWord);
    *(uint *)(base + 0x120) = 0;
  }
  return (result & 0xffffff00) | 1;
}

// Primary slot4: capture124 head, allocate node with CURRENT record argument, link before captured head and return node/RET4.
// Saved ECX slot becomes captured head; head/previous link and record input reloads remain observable across allocation.
// R6GameService.dll @ 1005fc30 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendOwnedRecord(void *owner,void *record)
{
  __asm {
    push    ecx
    push    esi
    lea    esi,[ecx+0x124]
    lea    eax,[esp+0x4]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0xc]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Release current124 nodes/sentinel using owner saved at parentS-14; payload deletion is not retried.
// R6GameService.dll @ 10069ca0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyRecordOwnerStorageUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x124
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Release current12c nodes/sentinel using owner saved at parentS-14; then continue state0.
// R6GameService.dll @ 10069cae : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyRecordOwnerStorageUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x12c
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Empty12c base cleanup uses CURRENT parentS-10 context; then continue state0.
// R6GameService.dll @ 10069cbc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyRecordOwnerStorageUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact three-state clBasicProtocol destructor FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069cc4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectBasicProtocolDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyRecordOwnerStorageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destructor cleanup map/FuncInfo; list retry is disarmed before12c normal cleanup.
// R6GameService.dll data @ 100847c4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyRecordOwnerStorageUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyRecordOwnerStorageUnwind1},
  {0x0, R6GameServiceAddresses::DestroyRecordOwnerStorageUnwind2},
  {0x0, R6GameServiceAddresses::DestroyRecordOwnerStorageUnwind3},
};

// Literal destructor cleanup map/FuncInfo; list retry is disarmed before12c normal cleanup.
// R6GameService.dll data @ 100847c4 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyRecordOwnerStorageExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::DestroyRecordOwnerStorageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clBasicProtocolVTable
// R6GameService.dll data @ 10078304 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clBasicProtocolVTableRecord {
  R6GameServiceNative::Address clBasicProtocol_DeleteObject; // +0x00
  R6GameServiceNative::Address AppendOwnedRecord; // +0x04
};
const clBasicProtocolVTableRecord clBasicProtocolVTable = {
  R6GameServiceAddresses::clBasicProtocol_DeleteObject,
  R6GameServiceAddresses::AppendOwnedRecord,
};
