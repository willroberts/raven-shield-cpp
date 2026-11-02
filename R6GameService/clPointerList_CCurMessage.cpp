#include "native_addresses.h"
#include "native_records.h"

// clPointerList<CCurMessage*> primary77eec/COL79ec8; shared destruction metadata remains in list_node_support.cpp.

// Restore typed list table, erase physical three-word range, then release residual nodes/current header.
// ENTRY ESP S: savedownerS-14/stateS-4. State0 generic cleanup may retry the remaining nodes/header.
// R6GameService.dll @ 1004cce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyCurrentMessagePointerList(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTypedPointerListDestroyEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVCCurMessageVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,edi
    push   edx
    call   DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je     Branch2
  Branch1:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch1
  Branch2:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Tail-forward the message pointer-list receiver without changing its physical ABI.
// R6GameService.dll @ 1004c720 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardCurrentMessageListDestroy(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyCurrentMessagePointerList
  }
}

// Destroy the typed list, then test CURRENT deleting flag lowBYTE/bit0; optionally free original owner.
// Preserve full physical DWORD argument, original receiver EAX and RET4.
// R6GameService.dll @ 1004c7f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteCurrentMessagePointerList(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyCurrentMessagePointerList
    test   BYTE PTR [esp+0x8],0x1
    je     Branch3
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Native virtual-table prefix: clPointerList_PAVCCurMessageVTable
// R6GameService.dll data @ 10077eec : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVCCurMessageVTableRecord {
  R6GameServiceNative::Address DeleteCurrentMessagePointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstCallbackListEntry; // +0x08
  R6GameServiceNative::Address PopBackCallbackListEntry; // +0x0c
  R6GameServiceNative::Address EraseOwnedPayloadListRange; // +0x10
  R6GameServiceNative::Address EraseCallbackPointerListNode; // +0x14
};
const clPointerList_PAVCCurMessageVTableRecord clPointerList_PAVCCurMessageVTable = {
  R6GameServiceAddresses::DeleteCurrentMessagePointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstCallbackListEntry,
  R6GameServiceAddresses::PopBackCallbackListEntry,
  R6GameServiceAddresses::EraseOwnedPayloadListRange,
  R6GameServiceAddresses::EraseCallbackPointerListNode,
};
