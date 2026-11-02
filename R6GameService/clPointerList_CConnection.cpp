#include "native_addresses.h"
#include "native_records.h"

// clPointerList<CConnection*> primary77ed0/COL79f64; CConnectionList77f08 inherits the same slot14 body.

// Erase one node: skip payload cleanup for CURRENT head or null payload, otherwise destroy cached payload then free it.
// Read CURRENT previous/next AFTER payload cleanup, unlink before node free; output successor only AFTER free.
// Reload output argument after allocator, write through it and return it in EAX/RET8. No head guard for node unlink.
// R6GameService.dll @ 1004cc20 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall EraseConnectionPointerListNode(void *owner,void *successorOut,uint node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je     Branch1
    mov    esi,DWORD PTR [edi+0x8]
    test   esi,esi
    je     Branch1
    mov    ecx,esi
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    mov    DWORD PTR [eax],esi
    pop    esi
    ret    0x8
  }
}

// Pop the last connection: destroy/free initially captured tail payload, then reread CURRENT head/tail to unlink/free.
// An empty list returns its head EAX; otherwise return final allocator residue. No own guard or payload/link repair.
// R6GameService.dll @ 1004cbd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PopBackConnectionPointerList(void *owner)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch3
    mov    eax,DWORD PTR [eax+0x4]
    push   edi
    mov    edi,DWORD PTR [eax+0x8]
    test   edi,edi
    je     Branch2
    mov    ecx,edi
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x8]
    call   R6GameServiceAddresses::RetreatNodeIterator
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch3:
    pop    esi
    pop    ecx
    ret
  }
}

// Restore typed list table, erase physical three-word range, then release residual nodes/current header.
// ENTRY ESP S: savedownerS-14/stateS-4. State0 generic cleanup may retry the remaining nodes/header.
// R6GameService.dll @ 1004cb00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyConnectionPointerList(void *owner)
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
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVCConnectionVTable
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
    je     Branch5
  Branch4:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi]
    jne    Branch4
  Branch5:
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

// First destroy/free cached payloads while reading next after callbacks; then unlink/free the iterator range.
// Cache end, reread current owner head during payload pass, copy CURRENT first argument for node pass.
// Final output pointer is reloaded after all frees; store cached end and return that pointer/RET12. No own guard.
// R6GameService.dll @ 1004cc60 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall EraseConnectionPointerRange(void *owner,void *endOut,uint first,uint end)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    esi,edi
    mov    ebp,ecx
    je     Branch8
  Branch6:
    cmp    esi,DWORD PTR [ebp+0x4]
    je     Branch8
    mov    ebx,DWORD PTR [esi+0x8]
    test   ebx,ebx
    je     Branch7
    mov    ecx,ebx
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   ebx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch7:
    mov    esi,DWORD PTR [esi]
    cmp    esi,edi
    jne    Branch6
  Branch8:
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x1c]
    push   eax
    call   R6GameServiceAddresses::CopyFirstWord
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    je     Branch10
  Branch9:
    mov    ecx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esp+0x20],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,edi
    jne    Branch9
  Branch10:
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Destroy the typed list, then test CURRENT deleting flag lowBYTE/bit0; optionally free original owner.
// Preserve full physical DWORD argument, original receiver EAX and RET4.
// R6GameService.dll @ 1004c7d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteConnectionPointerList(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyConnectionPointerList
    test   BYTE PTR [esp+0x8],0x1
    je     Branch11
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch11:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Pop front: cache initial first payload, destroy/free it, then reread CURRENT head/first and unlink/free that node.
// Empty returns head EAX; nonempty returns allocator residue. No allocation, own guard or payload/node repair.
// R6GameService.dll @ 1004cb90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PopConnectionPointerList(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch13
    mov    ecx,DWORD PTR [eax]
    push   edi
    mov    edi,DWORD PTR [ecx+0x8]
    test   edi,edi
    je     Branch12
    mov    ecx,edi
    call   R6GameServiceAddresses::CConnectionDestroyProvider
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [edx]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
  Branch13:
    pop    esi
    ret
  }
}

// Native virtual-table prefix: clPointerList_PAVCConnectionVTable
// R6GameService.dll data @ 10077ed0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerList_PAVCConnectionVTableRecord {
  R6GameServiceNative::Address DeleteConnectionPointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address PopConnectionPointerList; // +0x08
  R6GameServiceNative::Address PopBackConnectionPointerList; // +0x0c
  R6GameServiceNative::Address EraseConnectionPointerRange; // +0x10
  R6GameServiceNative::Address EraseConnectionPointerListNode; // +0x14
};
const clPointerList_PAVCConnectionVTableRecord clPointerList_PAVCConnectionVTable = {
  R6GameServiceAddresses::DeleteConnectionPointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::PopConnectionPointerList,
  R6GameServiceAddresses::PopBackConnectionPointerList,
  R6GameServiceAddresses::EraseConnectionPointerRange,
  R6GameServiceAddresses::EraseConnectionPointerListNode,
};
