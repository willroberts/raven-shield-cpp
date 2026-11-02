#include "native_addresses.h"
#include "native_records.h"

// Control paths share the initialized provider prefix; whole-owner/member declarations remain unresolved.

// Read signed item0 directly into owner+54, ignore reader status, pass diagnostic words to no-op, then send ed reply.
// No local EH/rollback; retain preexisting or partial field write on parse failure and raw sender EAX. RET4.
// R6GameService.dll @ 10057850 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StoreControlValueAndAcknowledge(void *owner,void *payload)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    push    edi
    lea    edi,[esi+0x54]
    push    0x0
    push    edi
    call    R6GameServiceAddresses::ReadIndexedInt32
    mov    eax,DWORD PTR [edi]
    push    eax
    push    R6GameServiceAddresses::TextReadUDPConnectIDD
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    mov    ecx,esi
    call    R6GameServiceAddresses::SendZeroByteControlRecordEd
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Send five full words ed/0/20/address-of-zero-byte/1 through58190; diagnostic is a genuine no-op.
// Zero byte at original entry ESP-1 overlaps saved ECX high byte, so POP ECX restores only original lower24 bits.
// R6GameService.dll @ 10057880 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendZeroByteControlRecordEd(void *owner)
{
  __asm {
    push    ecx
    push    esi
    push    R6GameServiceAddresses::TextSendEVENTUDPCONNECT
    mov    esi,ecx
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    lea    eax,[esp+0x7]
    mov    ecx,esi
    mov    BYTE PTR [esp+0x7],0x0
    push    0x1
    push    eax
    push    0x20
    push    0x0
    push    0xed
    call    R6GameServiceAddresses::CreateAndRoutePayloadRecord
    pop    esi
    pop    ecx
    ret
  }
}

// Build one descriptor, parse selector WORD item0, copy item1, dispatch1/2/3, then clear current list and release head.
// ENTRY ESP S: selectorS-28/descriptorS-24/listS-18/headS-14/stateS-4; payload argS+4 is reused as cleanup-list pointer.
// Preserve cached source/owner, current selector lowWORD, eight-state disarm order and raw cleanup EAX/RET4.
// R6GameService.dll @ 100585b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchProviderControlPayload(void *owner,void *payload)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProviderControlEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    xor    esi,esi
    mov    ebx,0x3
    push    edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    esi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x34],esi
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    esi
    mov    esi,DWORD PTR [esp+0x3c]
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push    eax
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch1
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x38],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::InvokePointerListClearRange
    mov    BYTE PTR [esp+0x30],0x2
    jmp    Branch7
  Branch1:
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch2
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x4
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x38],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x5
    jmp    Branch6
  Branch2:
    mov    eax,DWORD PTR [esp+0xc]
    and    eax,0xffff
    dec    eax
    je    Branch4
    dec    eax
    je    Branch3
    dec    eax
    jne    Branch5
    mov    ecx,edi
    call    R6GameServiceAddresses::ClearProviderReadyFlag
    jmp    Branch5
  Branch3:
    lea    ecx,[esp+0x10]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::HandleTransportBufferControlPayload
    jmp    Branch5
  Branch4:
    lea    edx,[esp+0x10]
    mov    ecx,edi
    push    edx
    call    R6GameServiceAddresses::HandleTransportReadyControlPayload
  Branch5:
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x6
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x38],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x7
  Branch6:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    mov    BYTE PTR [esp+0x30],bl
  Branch7:
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x4
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 10069580 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 10069588 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 10069590 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 10069598 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch8
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch9
  Branch8:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch9:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 100695bf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 100695c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch10
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch11
  Branch10:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch11:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 100695ee : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean exact inherited descriptor or CURRENT rewritten list argument; preserve NULL and saved context stores.
// R6GameService.dll @ 100695f6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchProviderControlPayloadUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch12
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch13
  Branch12:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch13:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact eight-state descriptor cleanup FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 1006961d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProviderControlEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchProviderControlPayloadExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native cleanup map/FuncInfo; list failure does not retry value destruction.
// R6GameService.dll data @ 100840cc : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchProviderControlPayloadUnwindMap[8] = {
  {-1, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind1},
  {-1, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind2},
  {-1, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind3},
  {0x2, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind4},
  {-1, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind5},
  {0x4, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind6},
  {-1, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind7},
  {0x6, R6GameServiceAddresses::DispatchProviderControlPayloadUnwind8},
};

// Literal native cleanup map/FuncInfo; list failure does not retry value destruction.
// R6GameService.dll data @ 100840cc : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchProviderControlPayloadExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::DispatchProviderControlPayloadUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Read two integers and uncapped bytes into stackS-104, capture helper8/c for both query/fill calls, queue updated output size.
// Only first scalar starts0; output-size scratch is uninitialized. Ignore crypto statuses; ready1 precedes raw-buffer free.
// No own EH/NULL repair; cached source/owner and physical260-byte stack extent/RET4/raw failure/free EAX retained.
// R6GameService.dll @ 10058730 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall HandleTransportReadyControlPayload(void *owner,void *payload)
{
  __asm {
    sub    esp,0x110
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0x11c]
    lea    eax,[esp+0xc]
    mov    esi,ecx
    push    0x0
    push    eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x14],0x0
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch14
    lea    ecx,[esp+0x10]
    push    0x1
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch14
    mov    edx,DWORD PTR [esp+0x10]
    push    0x2
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    je    Branch14
    mov    ecx,DWORD PTR [esi+0x4c]
    push    ebx
    lea    edx,[esp+0xc]
    push    ebp
    mov    ebp,DWORD PTR [ecx+0xc]
    mov    ebx,DWORD PTR [ecx+0x8]
    push    edx
    push    0x0
    push    ebp
    lea    eax,[esp+0x28]
    push    ebx
    push    eax
    call    R6GameServiceAddresses::DispatchSharedSlot8
    mov    ecx,DWORD PTR [esp+0x10]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi+0x4c]
    lea    edx,[esp+0x10]
    mov    edi,eax
    push    edx
    push    edi
    push    ebp
    lea    eax,[esp+0x28]
    push    ebx
    push    eax
    call    R6GameServiceAddresses::DispatchSharedSlot8
    mov    ecx,DWORD PTR [esp+0x10]
    push    ecx
    push    edi
    push    0x1
    mov    ecx,esi
    call    R6GameServiceAddresses::QueueProviderControlPayload
    push    edi
    mov    BYTE PTR [esi+0x50],0x1
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    ebp
    pop    ebx
  Branch14:
    pop    edi
    pop    esi
    add    esp,0x110
    ret    0x4
  }
}

// Read integers/heap bytes, query/fill crypto output, replace CURRENT helper buffer, free CURRENT output scratch then cached input.
// ENTRY ESP S: inputlenS-34/scalarS-30/output pairS-2c,S-28/empty descriptorS-24/listS-18/stateS-4.
// Ten-state EH owns only empty descriptor, NEVER either raw buffer. Ready1 follows both frees; source/owner stay cached. RET4.
// R6GameService.dll @ 100587f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall HandleTransportBufferControlPayload(void *owner,void *payload)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectControlBufferEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push    ebx
    push    ebp
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x28],0x3
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::PTR_LAB
    push    edi
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebp,DWORD PTR [esp+0x48]
    lea    eax,[esp+0x14]
    push    edi
    push    eax
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x1c],edi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch15
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,0x2
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],ebx
    mov    DWORD PTR [esp+0x48],ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x40],0x3
    jmp    Branch18
  Branch15:
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch16
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,0x4
    lea    eax,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],ebx
    mov    DWORD PTR [esp+0x48],eax
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x40],0x5
    jmp    Branch18
  Branch16:
    mov    ecx,DWORD PTR [esp+0x10]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x10]
    mov    edi,eax
    push    0x2
    push    edx
    push    edi
    mov    ecx,ebp
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch17
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,0x6
    lea    eax,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],ebx
    mov    DWORD PTR [esp+0x48],eax
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x40],0x7
    jmp    Branch18
  Branch17:
    mov    edx,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x1c]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x4c]
    push    0x0
    push    edx
    push    edi
    call    R6GameServiceAddresses::DispatchSharedSlot14
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x1c]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x4c]
    push    eax
    push    edx
    push    edi
    mov    DWORD PTR [esp+0x28],eax
    call    R6GameServiceAddresses::DispatchSharedSlot14
    mov    ecx,DWORD PTR [esi+0x4c]
    lea    eax,[esp+0x18]
    push    eax
    call    R6GameServiceAddresses::ReplaceSharedByteBuffer
    mov    ecx,DWORD PTR [esp+0x18]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    BYTE PTR [esi+0x50],0x1
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,0x8
    lea    edx,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],ebx
    mov    DWORD PTR [esp+0x48],edx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x40],0x9
  Branch18:
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x40],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x38]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret    0x4
  }
}

// Clear only provider BYTE+50; no stack arguments, preserve incoming EAX and all other fields.
// R6GameService.dll @ 100589d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearProviderReadyFlag(void *owner)
{
  __asm {
    mov    BYTE PTR [ecx+0x50],0x0
    ret
  }
}

// Allocate raw28, forward seven full physical words to payload constructor, disarm before route, then current virtual delete if non-NULL.
// ENTRY ESP S: rawS-10/stateS-4. Save route AL across delete, retain delete upper EAX; NULL is still routed. RET20.
// R6GameService.dll @ 10058190 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CreateAndRoutePayloadRecord(void *owner,uint byte0dWord,uint word18Word,uint byte0eWord,void *payload,uint byteCount)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectPayloadBuilderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebx
    push    esi
    push    edi
    push    0x1c
    mov    edi,ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0xc],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x18],0x0
    je    Branch19
    mov    ecx,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x2c]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esp+0x30]
    push    edx
    mov    edx,DWORD PTR [esp+0x2c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x34]
    push    edx
    mov    edx,DWORD PTR [edi+0x4c]
    push    ecx
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::ConstructPayloadRecord
    mov    esi,eax
    jmp    Branch20
  Branch19:
    xor    esi,esi
  Branch20:
    push    esi
    mov    ecx,edi
    mov    DWORD PTR [esp+0x1c],0xffffffff
    call    R6GameServiceAddresses::RoutePayloadRecordByQueueMode
    test    esi,esi
    mov    bl,al
    je    Branch21
    mov    eax,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [eax]
  Branch21:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    mov    al,bl
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x14
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 10069630 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 10069638 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 10069640 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 10069648 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch22
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x40],eax
    jmp    Branch23
  Branch22:
    mov    DWORD PTR [ebp-0x40],0x0
  Branch23:
    mov    ecx,DWORD PTR [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 1006966f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 10069677 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch24
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x48],eax
    jmp    Branch25
  Branch24:
    mov    DWORD PTR [ebp-0x48],0x0
  Branch25:
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 1006969e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 100696a6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch26
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x50],eax
    jmp    Branch27
  Branch26:
    mov    DWORD PTR [ebp-0x50],0x0
  Branch27:
    mov    ecx,DWORD PTR [ebp-0x50]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 100696cd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Clean map-selected descriptor base/list or CURRENT rewritten argument+4; NULL is forwarded, raw buffers are not owned.
// R6GameService.dll @ 100696d5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleTransportBufferControlPayloadUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch28
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x58],eax
    jmp    Branch29
  Branch28:
    mov    DWORD PTR [ebp-0x58],0x0
  Branch29:
    mov    ecx,DWORD PTR [ebp-0x58]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select ten-state descriptor-only FuncInfo84178 then tail CRT dispatch.
// R6GameService.dll @ 100696fc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectControlBufferEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HandleTransportBufferControlPayloadExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Free CURRENT pending raw record at inherited S-10 for builder58190/router58230/senders57f80/58040/580d0; later queue/deletion work is disarmed.
// R6GameService.dll @ 10069560 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select one-state raw record guard FuncInfo840b0 shared by builder58190/router58230/senders57f80/58040/580d0, then tail CRT dispatch.
// R6GameService.dll @ 1006956a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectPayloadBuilderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::provider_control_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native cleanup map/FuncInfo keeps descriptor ownership separate from raw buffer/record ownership.
// R6GameService.dll data @ 10084128 : native storage identity retained.
const R6GameServiceNative::UnwindEntry HandleTransportBufferControlPayloadUnwindMap[10] = {
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind1},
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind2},
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind3},
  {0x2, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind4},
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind5},
  {0x4, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind6},
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind7},
  {0x6, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind8},
  {-1, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind9},
  {0x8, R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwind10},
};

// Literal native cleanup map/FuncInfo keeps descriptor ownership separate from raw buffer/record ownership.
// R6GameService.dll data @ 10084128 : native storage identity retained.
const R6GameServiceNative::FuncInfo HandleTransportBufferControlPayloadExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::HandleTransportBufferControlPayloadUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native cleanup map/FuncInfo keeps descriptor ownership separate from raw buffer/record ownership.
// R6GameService.dll data @ 100840a8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry provider_control_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind1},
};

// Literal native cleanup map/FuncInfo keeps descriptor ownership separate from raw buffer/record ownership.
// R6GameService.dll data @ 100840a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo provider_control_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Temporarily install current helper in record+8; ordinary mode forwards raw key word, flagged mode replaces first matching queued record.
// Flagged key is opcode/WORD+18/first payload byte; opcodes2/3 also compare bytes1/2. Old payload byte0 is read without short circuit.
// Cache record/head/opcode/first byte as native; reload current erase/append interfaces. Restore context ONLY on normal exit.
// Shared840a8 guard owns pending raw copyS-10 only; erased duplicate and changed context are retained on interrupted operations. RET4/AL.
// R6GameService.dll @ 10058230 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RoutePayloadRecordByQueueMode(void *owner,void *record)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectPayloadBuilderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x2c]
    push    edi
    mov    edi,ecx
    mov    ebp,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x1c],edi
    mov    eax,DWORD PTR [edi+0x4c]
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esi+0x8],eax
    mov    al,BYTE PTR [esi+0xe]
    test    al,0x20
    je    Branch41
    call    R6GameServiceAddresses::CheckTransportWordOrRequest
    test    al,al
    je    Branch42
    mov    eax,DWORD PTR [edi+0x24]
    lea    ebx,[edi+0x24]
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x18],eax
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je    Branch38
    mov    eax,DWORD PTR [esi+0x10]
    mov    bl,BYTE PTR [esi+0xd]
    mov    al,BYTE PTR [eax]
    mov    BYTE PTR [esp+0x30],al
  Branch30:
    mov    eax,DWORD PTR [edi+0x8]
    mov    bp,WORD PTR [esi+0x18]
    mov    cl,BYTE PTR [eax+0xd]
    mov    edx,DWORD PTR [eax+0x10]
    cmp    cl,bl
    sete    cl
    cmp    WORD PTR [eax+0x18],bp
    sete    al
    and    cl,al
    mov    al,BYTE PTR [esp+0x30]
    cmp    BYTE PTR [edx],al
    sete    al
    and    cl,al
    je    Branch35
    cmp    bl,0x3
    je    Branch31
    cmp    bl,0x2
    jne    Branch34
  Branch31:
    mov    ebp,DWORD PTR [esi+0x10]
    mov    al,BYTE PTR [edx+0x1]
    cmp    al,BYTE PTR [ebp+0x1]
    jne    Branch32
    mov    dl,BYTE PTR [edx+0x2]
    mov    al,BYTE PTR [ebp+0x2]
    cmp    dl,al
    jne    Branch32
    mov    eax,0x1
    jmp    Branch33
  Branch32:
    xor    eax,eax
  Branch33:
    and    cl,al
  Branch34:
    test    cl,cl
    jne    Branch36
  Branch35:
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [esp+0x18]
    cmp    edi,eax
    jne    Branch30
    jmp    Branch37
  Branch36:
    push    ecx
    mov    eax,esp
    mov    DWORD PTR [esp+0x34],esp
    mov    DWORD PTR [eax],edi
    mov    eax,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [eax+0x20]
    lea    ecx,[eax+0x20]
    lea    eax,[esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x14]
  Branch37:
    mov    ebx,DWORD PTR [esp+0x10]
    mov    ebp,DWORD PTR [esp+0x14]
  Branch38:
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x1c],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x28],0x0
    je    Branch39
    push    0x1
    push    esi
    mov    ecx,eax
    call    R6GameServiceAddresses::clGameMessageCopyConstruct
    jmp    Branch40
  Branch39:
    xor    eax,eax
  Branch40:
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x28],0xffffffff
    push    ecx
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x34],eax
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x30]
    mov    ecx,ebx
    push    edx
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    edi,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    jmp    Branch43
  Branch41:
    mov    ax,WORD PTR [esi+0x18]
    push    esi
    push    eax
    lea    ecx,[edi+0x2c]
    call    R6GameServiceAddresses::InsertOrReplaceCompactPayloadRecord
    mov    al,0x1
    jmp    Branch43
  Branch42:
    xor    al,al
  Branch43:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esi+0x8],ebp
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x1c
    ret    0x4
  }
}

// Accept when both transport words18/1c are0, or value54 and WORD64 are nonzero; otherwise optionally request current58.
// Request result is ignored; clear only AL on rejection and preserve native upper EAX, no stack args or own cleanup.
// R6GameService.dll @ 100583d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CheckTransportWordOrRequest(void *owner)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x18]
    test    eax,eax
    jne    Branch45
    mov    eax,DWORD PTR [ecx+0x1c]
    test    eax,eax
    jne    Branch45
  Branch44:
    mov    al,0x1
    ret
  Branch45:
    mov    eax,DWORD PTR [ecx+0x54]
    test    eax,eax
    je    Branch46
    cmp    WORD PTR [ecx+0x64],0x0
    jne    Branch44
    mov    eax,DWORD PTR [ecx+0x58]
    push    eax
    call    R6GameServiceAddresses::SendTransportControlRecordWithDecimalValue
  Branch46:
    xor    al,al
    ret
  }
}

// Build A=[2,copy(B)], B=[signed value,signed byteCount,binary bytes], then queue db/8/2/A and release both descriptors.
// ENTRY ESP S: leadingS-40/B S-3c/A S-24/stateS-4; values/bytes/count reload from their original words around appends.
// Seven-state map disarms inner list cleanup before outer clear; cleanup rewrites BYTES argumentS+8 with A list context. RET12/raw EAX.
// R6GameService.dll @ 100589e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueProviderControlPayload(void *owner,uint value,const void *bytes,uint byteCount)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectControlQueueEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    push    esi
    mov    DWORD PTR [esp+0x8],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x28],ebx
    push    eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x4c],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],ebx
    push    0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0xc]
    lea    ecx,[esp+0x28]
    push    eax
    mov    BYTE PTR [esp+0x4c],0x3
    mov    DWORD PTR [esp+0x10],0x2
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x50]
    push    ecx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x58]
    lea    ecx,[esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x54]
    push    eax
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::AppendClDataListBinary
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x28]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x28]
    mov    ecx,esi
    push    eax
    push    0x2
    push    0x8
    push    0xdb
    call    R6GameServiceAddresses::QueueCopiedTransportRecord
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x28],edi
    mov    ebx,0x5
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x54],ecx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x48],0x6
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x48],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Build A=[1,copy(B)], B=[signed value,signed byteCount,binary bytes], then queue db/8/2/A and release both descriptors.
// Separate native body shares exact seven-state map and mutable argument/descriptor frame with589e0; preserve raw cleanup EAX/RET12.
// R6GameService.dll @ 10058b60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueProviderControlPayloadWithLeadingOne(void *owner,uint value,const void *bytes,uint byteCount)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectControlQueueEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    push    esi
    mov    DWORD PTR [esp+0x8],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x28],ebx
    push    eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x4c],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],ebx
    push    0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0xc]
    lea    ecx,[esp+0x28]
    push    eax
    mov    BYTE PTR [esp+0x4c],0x3
    mov    DWORD PTR [esp+0x10],0x1
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x50]
    push    ecx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x58]
    lea    ecx,[esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x54]
    push    eax
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::AppendClDataListBinary
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x28]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x28]
    mov    ecx,esi
    push    eax
    push    0x2
    push    0x8
    push    0xdb
    call    R6GameServiceAddresses::QueueCopiedTransportRecord
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x28],edi
    mov    ebx,0x5
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x54],ecx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x48],0x6
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x48],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069710 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069718 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069720 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069728 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069730 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069738 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply shared two-descriptor cleanup from inherited frame; final head action uses CURRENT rewritten bytes argumentS+8.
// R6GameService.dll @ 10069740 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl provider_control_supportSharedLifetimeUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch47
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x5c],eax
    jmp    Branch48
  Branch47:
    mov    DWORD PTR [ebp-0x5c],0x0
  Branch48:
    mov    ecx,DWORD PTR [ebp-0x5c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select seven-state cleanup FuncInfo84220 shared by589e0 and58b60, then tail CRT dispatch.
// R6GameService.dll @ 10069767 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectControlQueueEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::provider_control_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared queue-builder map/FuncInfo; one canonical record serves both leading-word variants.
// R6GameService.dll data @ 100841e8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry provider_control_supportSharedLifetimeUnwindMap2[7] = {
  {-1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind12},
  {-1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind2},
  {0x1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind3},
  {0x1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind4},
  {0x1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind5},
  {-1, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind6},
  {0x5, R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwind7},
};

// Literal shared queue-builder map/FuncInfo; one canonical record serves both leading-word variants.
// R6GameService.dll data @ 100841e8 : native storage identity retained.
const R6GameServiceNative::FuncInfo provider_control_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::provider_control_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Flush/pump optional stream, decode/drain, emit elapsed-time3a notification, then process datagram queue.
// ENTRY ESP S: sizeS-3c/socketS-38/nodeS-34/prefixed bytesS-30/raw recordS-2c/descriptorS-24/stateS-4.
// Send failure retains current record but still returns AL1; no endpoint discards records. Only pending record storage is guarded.
// Preserve cached versus current fields, raw argument upper bits, reused size/serialization scratch and current virtual erase.
// R6GameService.dll @ 10057980 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall UpdateTransportProvider(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProviderUpdateEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x30
    push    ebx
    push    ebp
    mov    ebp,ecx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x14],ebx
    push    esi
    mov    ecx,DWORD PTR [ebp+0x14]
    push    edi
    cmp    ecx,ebx
    je    Branch51
    mov    al,BYTE PTR [ecx+0x44]
    test    al,al
    jne    Branch49
    xor    al,al
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x3c
    ret
  Branch49:
    call    R6GameServiceAddresses::FlushConnectionSendQueue
    test    al,al
    jne    Branch50
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x3c
    ret
  Branch50:
    mov    ecx,DWORD PTR [ebp+0x14]
    call    R6GameServiceAddresses::PumpConnectionReceiveQueue
    test    al,al
    jne    Branch51
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x3c
    ret
  Branch51:
    mov    ecx,ebp
    call    R6GameServiceAddresses::DecodeQueuedTransportRecords
    test    al,al
    jne    Branch52
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x3c
    ret
  Branch52:
    mov    ecx,ebp
    call    R6GameServiceAddresses::DrainQueuedTransportPayloads
    mov    esi,DWORD PTR [ebp+0x14]
    cmp    esi,ebx
    je    Branch57
    push    ebx
    call    R6GameServiceAddresses::time
    mov    edi,DWORD PTR [esi+0x48]
    mov    ecx,DWORD PTR [ebp+0x8]
    sub    eax,edi
    add    esp,0x4
    cmp    eax,ecx
    jbe    Branch56
    cmp    ecx,ebx
    je    Branch56
    mov    edi,0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],edi
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    push    0x18
    mov    DWORD PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x1c],eax
    test    eax,eax
    mov    BYTE PTR [esp+0x48],0x2
    je    Branch53
    mov    dl,BYTE PTR [ebp+0xd]
    lea    ecx,[esp+0x28]
    push    0x1
    push    ecx
    mov    cl,BYTE PTR [ebp+0xc]
    push    edx
    mov    edx,DWORD PTR [ebp+0x4c]
    push    ecx
    push    0x0
    push    0x3a
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::ConstructClGSMessage
    mov    esi,eax
    jmp    Branch54
  Branch53:
    xor    esi,esi
  Branch54:
    push    esi
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::EnqueueBorrowedRecord
    test    esi,esi
    je    Branch55
    mov    eax,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [eax]
  Branch55:
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],edi
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x48],0xffffffff
  Branch56:
    mov    ecx,DWORD PTR [ebp+0x14]
    mov    eax,DWORD PTR [ecx+0x40]
    test    eax,eax
    je    Branch57
    xor    al,al
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x3c
    ret
  Branch57:
    mov    ecx,DWORD PTR [ebp+0x24]
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x18],eax
    je    Branch65
    jmp    Branch59
  Branch58:
    mov    eax,DWORD PTR [esp+0x18]
  Branch59:
    mov    ecx,DWORD PTR [ebp+0x18]
    test    ecx,ecx
    je    Branch60
    mov    DWORD PTR [esp+0x14],ecx
    jmp    Branch61
  Branch60:
    mov    edx,DWORD PTR [ebp+0x1c]
    mov    DWORD PTR [esp+0x14],edx
  Branch61:
    mov    ecx,DWORD PTR [esp+0x14]
    test    ecx,ecx
    je    Branch64
    mov    ebx,DWORD PTR [eax+0x8]
    mov    eax,DWORD PTR [ebx+0x14]
    mov    DWORD PTR [esp+0x10],eax
    add    eax,0x4
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0x54]
    lea    edi,[eax+0x4]
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [ebx+0x10]
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    push    0x1c
    and    ecx,0x3
    mov    DWORD PTR [esp+0x20],eax
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edi,DWORD PTR [esp+0x14]
    mov    esi,0x4
    add    edi,esi
    mov    DWORD PTR [esp+0x14],edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x20],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x48],esi
    je    Branch62
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x1c]
    push    0x1
    push    ecx
    mov    cl,BYTE PTR [ebx+0xe]
    push    edx
    mov    dl,BYTE PTR [ebx+0xd]
    push    ecx
    mov    cx,WORD PTR [ebx+0x18]
    push    edx
    mov    edx,DWORD PTR [ebp+0x4c]
    push    ecx
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::ConstructPayloadRecord
    mov    esi,eax
    jmp    Branch63
  Branch62:
    xor    esi,esi
  Branch63:
    mov    eax,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x48],0xffffffff
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi]
    lea    eax,[esp+0x10]
    push    eax
    mov    ecx,esi
    call    DWORD PTR [edx+0x4]
    mov    cx,WORD PTR [ebp+0x64]
    mov    edx,DWORD PTR [ebp+0x60]
    mov    edi,eax
    mov    eax,DWORD PTR [esp+0x10]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x18]
    push    edx
    push    eax
    push    edi
    call    R6GameServiceAddresses::SendDatagramToIPv4
    mov    edx,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    mov    bl,al
    call    DWORD PTR [edx]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    bl,bl
    je    Branch65
    mov    eax,DWORD PTR [esp+0x18]
  Branch64:
    mov    esi,DWORD PTR [eax]
    push    ecx
    mov    ecx,esp
    lea    edx,[esp+0x28]
    mov    DWORD PTR [esp+0x24],esp
    push    edx
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [ebp+0x20]
    lea    ecx,[ebp+0x20]
    mov    DWORD PTR [esp+0x20],esi
    call    DWORD PTR [eax+0x14]
    cmp    esi,DWORD PTR [ebp+0x24]
    jne    Branch58
  Branch65:
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x3c
    ret
  }
}

// Reset parent descriptor primary table at S-24.
// R6GameService.dll @ 100694f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateTransportProviderUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy parent descriptor/list at S-24 using its current head.
// R6GameService.dll @ 100694f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateTransportProviderUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Free CURRENT pending tagged-record allocation at S-30; no payload-buffer guard.
// R6GameService.dll @ 10069500 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateTransportProviderUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x30]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Reset parent descriptor after list cleanup was disarmed.
// R6GameService.dll @ 1006950a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateTransportProviderUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Free CURRENT pending payload-record allocation at S-2c; prefixed temporary bytes remain unguarded.
// R6GameService.dll @ 10069512 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UpdateTransportProviderUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x2c]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select five-state timeout-descriptor/pending-record cleanup metadata and tail-dispatch CRT.
// R6GameService.dll @ 1006951c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProviderUpdateEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UpdateTransportProviderExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native update cleanup map/FuncInfo; states0/1/2/3/4 preserve original ownership.
// R6GameService.dll data @ 10083fa0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UpdateTransportProviderUnwindMap[5] = {
  {-1, R6GameServiceAddresses::UpdateTransportProviderUnwind1},
  {-1, R6GameServiceAddresses::UpdateTransportProviderUnwind2},
  {0x1, R6GameServiceAddresses::UpdateTransportProviderUnwind3},
  {-1, R6GameServiceAddresses::UpdateTransportProviderUnwind4},
  {-1, R6GameServiceAddresses::UpdateTransportProviderUnwind5},
};

// Literal native update cleanup map/FuncInfo; states0/1/2/3/4 preserve original ownership.
// R6GameService.dll data @ 10083fa0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UpdateTransportProviderExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::UpdateTransportProviderUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Allocate tagged record, guard pending construction only, insert compact copy at owner+2c, then delete temporary.
// ECX owner; opcode/byte10/byte11/descriptor are four FULL words. Read them and owner+4c after allocation.
// ENTRY ESP S: raw recordS-10/stateS-4. Disarm before compact insertion; force AL1 after insertion or deletion, RET16.
// R6GameService.dll @ 10057f80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueCopiedTransportRecord(
    void *owner,uint opcodeWord,uint byte10Word,uint byte11Word,void *taggedPayloadDescriptor)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectPayloadBuilderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    push    edi
    push    0x18
    mov    edi,ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x8],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je    Branch66
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x24]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esp+0x28]
    push    edx
    mov    edx,DWORD PTR [esp+0x28]
    push    ecx
    mov    ecx,DWORD PTR [edi+0x4c]
    push    0x0
    push    edx
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::ConstructClGSMessage
    mov    esi,eax
    jmp    Branch67
  Branch66:
    xor    esi,esi
  Branch67:
    push    esi
    push    0x0
    lea    ecx,[edi+0x2c]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    call    R6GameServiceAddresses::InsertOrReplaceCompactPayloadRecord
    test    esi,esi
    je    Branch68
    mov    edx,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [edx]
  Branch68:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x10
  }
}

// Construct one list, preserve cdecl no-op args/ECX, append CURRENT signed caller word and queue full6/2/8 fields.
// Ignore queue result; clear then nodes/head release with current split cleanup contexts, retaining raw final EAX.
// R6GameService.dll @ 10057740 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendTransportControlRecordWithDecimalValue(void *owner,int value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectDecimalControlRecordEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push   esi
    mov    DWORD PTR [esp+0x8],0x0
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x20]
    push   eax
    mov    DWORD PTR [esp+0x34],0x1
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR [esp+0x30],0x2
    push   ecx
    push   R6GameServiceAddresses::TextSendUDPConnectIDD
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    lea    edx,[esp+0x38]
    lea    ecx,[esp+0x10]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push   eax
    push   0x8
    push   0x2
    push   0x6
    call   R6GameServiceAddresses::QueueCopiedTransportRecord
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x8],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0xc],edx
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x5
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x20]
    push   0x1
    push   eax
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x28]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x4
  }
}

// R6GameService.dll @ 10058010 : EnqueueBorrowedRecord
// Enqueues a borrowed record with the receiver's +0x4c value, then restores the original record word.
// Native 10058010: RET 4; AL is set to 1 while the insertion call's upper EAX bits survive.
uint __thiscall EnqueueBorrowedRecord(void *receiver,int *record)
{
  int savedWord08 = record[2];
  record[2] = *(int *)((int)receiver + 0x4c);
  uint insertionResult = InsertOrReplaceCompactPayloadRecord((void *)((int)receiver + 0x2c),0,record);
  // There is no unwind handler: an exception from insertion bypasses this restoration.
  record[2] = savedWord08;
  return (insertionResult & 0xffffff00) | 1;
}

// Construct temporary message with late owner header bytes/full retained argument lanes; disarm raw-allocation guard before queue.
// Queue even null constructor/allocation result, then delete nonnull returned record; preserve queue/delete upperEAX and AL1.
// R6GameService.dll @ 10058040 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueRecordUsingStoredHeaderFields(void *owner,uint opcode,void *payload)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectPayloadBuilderEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    push   0x18
    mov    esi,ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x8],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je    Branch69
    mov    ecx,DWORD PTR [esp+0x20]
    mov    dl,BYTE PTR [esi+0xd]
    push   0x1
    push   ecx
    mov    cl,BYTE PTR [esi+0xc]
    push   edx
    mov    edx,DWORD PTR [esp+0x28]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x4c]
    push   0x0
    push   edx
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructClGSMessage
    mov    edi,eax
    jmp    Branch70
  Branch69:
    xor    edi,edi
  Branch70:
    push   edi
    lea    ecx,[esi+0x2c]
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   R6GameServiceAddresses::AppendCompactPayloadRecord
    test   edi,edi
    je    Branch71
    mov    edx,DWORD PTR [edi]
    push   0x1
    mov    ecx,edi
    call   DWORD PTR [edx]
  Branch71:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Register shared raw-allocation guard before gate; disabled AL0 retains previous SEH-link upperEAX.
// Enabled path passes literal to genuine no-op, constructs kind2/full arguments, disarms before insertion and deletes returned record.
// R6GameService.dll @ 100580d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueKind2TransportRecordWhenEnabled(
    void *owner,uint opcode,uint recordByte10,uint recordByte11,void *payload)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectPayloadBuilderEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    mov    edi,ecx
    mov    al,BYTE PTR [edi+0x50]
    test   al,al
    jne    Branch72
    xor    al,al
    pop    edi
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x10
  Branch72:
    push   esi
    push   R6GameServiceAddresses::TextSendingEncryptedMessage
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x8],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je    Branch73
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x24]
    push   0x1
    push   ecx
    mov    ecx,DWORD PTR [esp+0x28]
    push   edx
    mov    edx,DWORD PTR [esp+0x28]
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4c]
    push   0x0
    push   edx
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructClGSEncryptMessage
    mov    esi,eax
    jmp    Branch74
  Branch73:
    xor    esi,esi
  Branch74:
    push   esi
    push   0x0
    lea    ecx,[edi+0x2c]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    call   R6GameServiceAddresses::InsertOrReplaceCompactPayloadRecord
    test   esi,esi
    je    Branch75
    mov    edx,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR [edx]
  Branch75:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    al,0x1
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x10
  }
}

// Return ready immediately or send104-byte table copy and pump/pop/delete until current readyBYTE or unsigned five-second delta.
// Preserve initial unchecked connection read, ignored queue status, updateAL short-circuit, deadline clear and per-route raw upperEAX.
// R6GameService.dll @ 10058500 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall WaitForTransportReady(void *owner)
{
  __asm {
    sub    esp,0x104
    push   esi
    mov    esi,ecx
    push   edi
    mov    al,BYTE PTR [esi+0x50]
    test   al,al
    je    Branch77
  Branch76:
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x104
    ret
  Branch77:
    mov    eax,DWORD PTR [esi+0x14]
    mov    cl,BYTE PTR [eax+0x44]
    test   cl,cl
    je    Branch81
    lea    ecx,[esp+0x8]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x4c]
    call   R6GameServiceAddresses::CopyGlobalWordTablePrefix
    lea    edx,[esp+0x8]
    push   0x104
    push   edx
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::QueueProviderControlPayloadWithLeadingOne
    push   0x0
    call   R6GameServiceAddresses::time
    push   0x0
    mov    edi,eax
    call   R6GameServiceAddresses::time
    sub    eax,edi
    add    esp,0x8
    cmp    eax,0x5
    jae    Branch80
  Branch78:
    mov    ecx,esi
    call   R6GameServiceAddresses::UpdateTransportProvider
    test   al,al
    je    Branch81
    mov    ecx,esi
    call   R6GameServiceAddresses::PopAndDispatchControlRecord
    test   eax,eax
    je    Branch79
    mov    edx,DWORD PTR [eax]
    push   0x1
    mov    ecx,eax
    call   DWORD PTR [edx]
  Branch79:
    mov    al,BYTE PTR [esi+0x50]
    test   al,al
    jne    Branch76
    push   0x0
    call   R6GameServiceAddresses::time
    sub    eax,edi
    add    esp,0x4
    cmp    eax,0x5
    jb    Branch78
  Branch80:
    mov    BYTE PTR [esi+0x50],0x0
  Branch81:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x104
    ret
  }
}

// Reset descriptor construction base at inherited EBP-24.
// R6GameService.dll @ 10069490 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass inherited EBP-2d cookie to genuine no-op, then continue base cleanup.
// R6GameService.dll @ 10069498 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy full CURRENT descriptor at inherited EBP-24.
// R6GameService.dll @ 100694a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered descriptor base at inherited EBP-24, without repeating member clear.
// R6GameService.dll @ 100694a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT member context twice at EBP-2c; adjust nonnull+4 or preserve null into scratch EBP-28 for head cleanup.
// R6GameService.dll @ 100694b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x2c],0x0
    je    Branch82
    mov    eax,DWORD PTR [ebp-0x2c]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch83
  Branch82:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch83:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Pass CURRENT saved header context at inherited EBP-28 to genuine no-op; do not retry head release.
// R6GameService.dll @ 100694d7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportControlRecordWithDecimalValueUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact six-state decimal control-record FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 100694df : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDecimalControlRecordEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

uint __thiscall AppendCompactPayloadRecord(void *owner,void *source);
void * __thiscall ConcatenateCompactPayloadsThroughLimit(void *owner,int byteLimit,int *copiedByteCount);
uint __thiscall DiscardConsumedCompactPayloads(void *owner,int consumedByteCount);
// Append string and formatted 32-bit values to the ECX descriptor (RET 4).
uint __thiscall AppendClDataListString(void *destination,const char *text);
uint __thiscall AppendClDataListSignedDecimal(void *destination,const void *value);
uint __thiscall AppendClDataListBinary(
    void *destination,const void *byteSequence,uint byteCount);
uint __thiscall AppendClDataListCopy(void *destination,undefined4 *source);
void __fastcall DestroyEmbeddedListOwnerAndSentinel(int *receiver);
void __fastcall DestroyCompactPointerList(int *receiver);
void __fastcall DestroyEmbeddedListAndSentinel(int *receiver);
void __thiscall CopyCircularListPayloads(void *context,undefined4 *destinationSentinel,
                                                   undefined4 *sourceFirst,undefined4 *sourceEnd);

struct BufferDescriptor;
void __stdcall CopyGlobalWordTablePrefix(undefined4 *destination);
uint __thiscall ReplaceSharedByteBuffer(
    void *state,const BufferDescriptor *source);
uint __thiscall QueryPeerEndpointAlwaysSuccess(
    void *owner,char *addressTextOut,ushort *portOut);
uint __thiscall QueryLocalEndpointAlwaysSuccess(
    void *owner,uint *addressOut,ushort *portOut);
uint __fastcall DestroyTransportRecordMembers(void *receiver);
uint __fastcall SendZeroByteControlRecordEd(void *receiver);
uint __fastcall UpdateTransportProvider(void *receiver);
int * __stdcall DecodeTransportRecordByHeaderClass(
    byte *inputOrPendingAllocation,uint sizeOrPendingAllocation,uint *decodedValueOut,uint *contextOrTrimmedBuffer);
uint __fastcall DecodeQueuedTransportRecords(int providerAddress);
uint __fastcall DrainQueuedTransportPayloads(uint providerAddress);
uint __thiscall QueueCopiedTransportRecord(
    void *receiver,uint opcode,uint recordByte10,uint recordByte11,
    void *taggedPayloadDescriptor);
uint __thiscall QueueRecordUsingStoredHeaderFields(
    void *receiver,uint opcode,void *taggedPayloadDescriptor);
uint __thiscall QueueKind2TransportRecordWhenEnabled(
    void *receiver,uint opcode,uint recordByte10,uint recordByte11,
    void *taggedPayloadDescriptor);
uint __thiscall RoutePayloadRecordByQueueMode(void *provider,int *record);
uint __thiscall DispatchProviderControlPayload(void *provider,void *payloadDescriptor);
uint __thiscall QueueProviderControlPayload(void *owner,uint value,const void *bytes,uint byteCount);
uint __thiscall QueueProviderControlPayloadWithLeadingOne(void *owner,uint value,const void *bytes,uint byteCount);
void * __thiscall ConstructPayloadRecord(
    void *message,uint context,uint word18,uint byte0d,uint byte0e,void *payload,uint size,uint initializeBaseWord);
bool __thiscall SendDatagramToIPv4(
    void *socketOwner,void *bytes,int byteCount,undefined4 address,undefined4 port);
uint __stdcall IsEncodedHeaderSizeValid(const byte *header,int inputLength);

struct NativeDescriptorArgument24 {
  undefined4 words[6];
};
uint __thiscall QueueTaggedRecord(
    void *owner,uint flags,uint value,uint key,uint opcode,uint byteField,
    NativeDescriptorArgument24 payload);

// Literal decimal control-record six-state cleanup map.
// R6GameService.dll data @ 10083f54 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendTransportControlRecordWithDecimalValueUnwindMap[6] = {
  {-1, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind1},
  {0x0, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind2},
  {-1, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind3},
  {-1, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind4},
  {0x3, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind5},
  {0x3, R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwind6},
};

// Literal decimal control-record FuncInfo.
// R6GameService.dll data @ 10083f84 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendTransportControlRecordWithDecimalValueExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::SendTransportControlRecordWithDecimalValueUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
