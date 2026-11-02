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

// Install base primary, clear members, release CURRENT12c nodes/head then CURRENT124 nodes/head; retain dangling head fields.
// ENTRY ESP S: saved ownerS-14/list contextS-10/stateS-4. State1 protects both node lists; state2 disarms12c retry.
// Preserve successor caching, separate head reloads, three-state cleanup and raw final free EAX.
// R6GameService.dll @ 1005fb70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyRecordOwnerStorage(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectBasicProtocolDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    mov    ebx,ecx
    push    esi
    push    edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [ebx],R6GameServiceAddresses::clBasicProtocolVTable
    mov    DWORD PTR [esp+0x1c],0x1
    call    R6GameServiceAddresses::ClearRecordOwnerMembers
    lea    esi,[ebx+0x12c]
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,DWORD PTR [esi]
    mov    BYTE PTR [esp+0x1c],0x2
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch4
  Branch3:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push    0x1
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    edi,DWORD PTR [esi]
    jne    Branch3
  Branch4:
    mov    eax,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    eax,DWORD PTR [ebx+0x124]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je    Branch6
  Branch5:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [ebx+0x124]
    jne    Branch5
  Branch6:
    mov    eax,DWORD PTR [ebx+0x124]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [ebx+0x124]
    mov    DWORD PTR [eax+0x4],eax
    mov    ecx,DWORD PTR [ebx+0x124]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Delete payloads of CURRENT124 then12c lists, then free12c nodes and124 nodes, resetting current heads separately.
// Release current120 association with physical WORD11c argument retaining124-head upper16, clear120 only AFTER return.
// No own EH; current next/head accesses survive callbacks, fields keep freed payload pointers, AL1 with raw upper EAX.
// R6GameService.dll @ 1005fc70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearRecordOwnerMembers(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    push    edi
    mov    eax,DWORD PTR [esi+0x124]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch9
  Branch7:
    mov    ecx,DWORD PTR [edi+0x8]
    test    ecx,ecx
    je    Branch8
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch8:
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [esi+0x124]
    cmp    edi,eax
    jne    Branch7
  Branch9:
    mov    eax,DWORD PTR [esi+0x12c]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch12
  Branch10:
    mov    ecx,DWORD PTR [edi+0x8]
    test    ecx,ecx
    je    Branch11
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch11:
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [esi+0x12c]
    cmp    edi,eax
    jne    Branch10
  Branch12:
    mov    eax,DWORD PTR [esi+0x12c]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch14
  Branch13:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi+0x12c]
    jne    Branch13
  Branch14:
    mov    eax,DWORD PTR [esi+0x12c]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi+0x12c]
    mov    DWORD PTR [eax+0x4],eax
    mov    eax,DWORD PTR [esi+0x124]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch16
  Branch15:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi+0x124]
    jne    Branch15
  Branch16:
    mov    eax,DWORD PTR [esi+0x124]
    mov    DWORD PTR [eax],eax
    mov    eax,DWORD PTR [esi+0x124]
    mov    DWORD PTR [eax+0x4],eax
    mov    ecx,DWORD PTR [esi+0x120]
    test    ecx,ecx
    je    Branch17
    mov    ax,WORD PTR [esi+0x11c]
    push    eax
    call    R6GameServiceAddresses::RemoveKeyAndRecycleOrDestroy
    mov    DWORD PTR [esi+0x120],0x0
  Branch17:
    pop    edi
    mov    al,0x1
    pop    esi
    ret
  }
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
