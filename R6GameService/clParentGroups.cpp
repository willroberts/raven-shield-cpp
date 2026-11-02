#include "native_addresses.h"
#include "native_records.h"

// clParentGroups RTTI and allocation/use flows support these entries; original nonvirtual declarations unresolved.

// Count a captured range, then reload current list to select first unsigned greatest payload+38.
// Destination low BYTE is copied into unread category scratch; all three cdecl count arguments remain.
// Copy chosen payload through31d00; RET4/empty EAX0 or destination upper|AL1. No node release/own guard.
// R6GameService.dll @ 10031e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CopyGreatestParsedServiceRecord(void *list,void *destination)
{
  __asm {
    sub    esp,0xc
    push   esi
    mov    esi,ecx
    mov    cl,BYTE PTR [esp+0x14]
    lea    edx,[esp+0x7]
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [esp+0x7],cl
    mov    DWORD PTR [esp+0x8],eax
    push   edx
    mov    eax,DWORD PTR [eax]
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x10],eax
    lea    eax,[esp+0xc]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::CountCircularListRange
    add    esp,0xc
    test   eax,eax
    jne    Branch1
    xor    al,al
    pop    esi
    add    esp,0xc
    ret    0x4
  Branch1:
    mov    esi,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [eax+0x8]
    mov    eax,DWORD PTR [eax]
    cmp    eax,esi
    je     Branch4
    push   ebx
    push   edi
  Branch2:
    mov    ecx,DWORD PTR [eax+0x8]
    mov    ebx,DWORD PTR [edx+0x38]
    mov    edi,DWORD PTR [ecx+0x38]
    cmp    edi,ebx
    jbe    Branch3
    mov    edx,ecx
  Branch3:
    mov    eax,DWORD PTR [eax]
    cmp    eax,esi
    jne    Branch2
    pop    edi
    pop    ebx
  Branch4:
    mov    ecx,DWORD PTR [esp+0x14]
    push   edx
    call   R6GameServiceAddresses::CopyParsedServiceRecord
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret    0x4
  }
}

// Optionally installs secondary offset table, clears head, allocates unchecked sentinel, then publishes links/head/primary.
// R6GameService.dll @ 10031d50 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructParsedServiceRecordList(void *list,int installVtable)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0xc]
    xor    eax,eax
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x4],eax
    je     Branch5
    mov    DWORD PTR [esi+0x8],0x10076d40
  Branch5:
    push   0xc
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clParentGroupsVTable
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Native virtual-table prefix: clParentGroupsVTable
// R6GameService.dll data @ 10076d28 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clParentGroupsVTableRecord {
  R6GameServiceNative::Address DestroyParsedServiceRecordListObject; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address RemoveFirstBlockFromQueue; // +0x08
  R6GameServiceNative::Address RemoveLastBlockFromQueue; // +0x0c
  R6GameServiceNative::Address EraseOwningPointerListRange; // +0x10
  R6GameServiceNative::Address EraseOwningPointerListNode; // +0x14
};
const clParentGroupsVTableRecord clParentGroupsVTable = {
  R6GameServiceAddresses::DestroyParsedServiceRecordListObject,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::RemoveFirstBlockFromQueue,
  R6GameServiceAddresses::RemoveLastBlockFromQueue,
  R6GameServiceAddresses::EraseOwningPointerListRange,
  R6GameServiceAddresses::EraseOwningPointerListNode,
};
