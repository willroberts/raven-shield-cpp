#include "native_addresses.h"
#include "native_records.h"

// RTTI primary783c8/COL7a898 and list783ec/COL7a84c identify clProxyConnection and its proxy-message list.
// Raw entry views retain explicit offsets/ABI; original nonvirtual names, callback return types and full layouts remain unresolved.

// Construct clProxyConnection over the provider base, then byte-string/list members and late text assignment.
// Preserve incoming slot reuse, flags atS-14, eight-state cleanup and unchecked buffer allocation. RET18.
// R6GameService.dll @ 10062340 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeDerivedTransportRecordWithText(
    void *owner,const char *text,uint word74,uint contextWord,uint loggerWord,uint word94,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProxyConstructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    ebp
    push    esi
    xor    esi,esi
    mov    DWORD PTR [esp+0xc],esi
    mov    eax,DWORD PTR [esp+0x38]
    mov    ebp,ecx
    cmp    eax,esi
    push    edi
    mov    DWORD PTR [esp+0x14],ebp
    je    Branch1
    mov    DWORD PTR [ebp+0x4],0x1007840c
    mov    DWORD PTR [esp+0x10],0x1
    mov    DWORD PTR [esp+0x20],esi
  Branch1:
    push    esi
    push    esi
    push    esi
    push    0xb4
    push    0xb
    push    0x8
    push    0x1e
    push    0x22
    mov    ecx,ebp
    call    R6GameServiceAddresses::InitializeTransportRecord
    mov    DWORD PTR [esp+0x20],0x1
    lea    ebx,[ebp+0x68]
    lea    edi,[ebx+0x8]
    lea    eax,[esp+0x3c]
    push    esi
    push    eax
    mov    ecx,edi
    mov    BYTE PTR [esp+0x28],0x2
    mov    DWORD PTR [ebx],esi
    mov    DWORD PTR [ebx+0x4],esi
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push    0x8
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x8]
    mov    DWORD PTR [ebx],eax
    mov    DWORD PTR [ebx+0x4],eax
    mov    DWORD PTR [edi],ecx
    mov    BYTE PTR [eax],0x0
    mov    ecx,DWORD PTR [esp+0x10]
    mov    dx,WORD PTR [esp+0x2c]
    mov    eax,DWORD PTR [esp+0x30]
    lea    edi,[ebp+0x84]
    or    ecx,0x2
    mov    WORD PTR [ebp+0x74],dx
    mov    DWORD PTR [ebp+0x78],esi
    mov    DWORD PTR [ebp+0x7c],eax
    mov    DWORD PTR [ebp+0x80],0x1
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [edi+0x8],0x10078404
    mov    DWORD PTR [esp+0x10],ecx
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [esp+0x30],ecx
    lea    edx,[esp+0x3c]
    mov    DWORD PTR [esp+0x20],0x6
    push    edx
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclProxyMessageVTable
    mov    edx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x34]
    mov    cx,WORD PTR [esp+0x38]
    cmp    edx,esi
    mov    DWORD PTR [esp+0x20],0x7
    mov    DWORD PTR [ebp+0x90],eax
    mov    WORD PTR [ebp+0x94],cx
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clProxyConnectionVTable
    jne    Branch2
    mov    edx,R6GameServiceAddresses::GRegistrationEmptyText
  Branch2:
    mov    edi,edx
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    mov    edi,DWORD PTR [ebx]
    dec    ecx
    mov    esi,ecx
    mov    ecx,DWORD PTR [ebx+0x4]
    add    esi,edx
    sub    ecx,edi
    mov    eax,esi
    mov    DWORD PTR [esp+0x2c],esi
    sub    eax,edx
    cmp    eax,ecx
    ja    Branch5
    test    eax,eax
    je    Branch3
    mov    ecx,eax
    mov    esi,edx
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch3:
    mov    esi,DWORD PTR [ebx]
    mov    edi,DWORD PTR [ebx+0x4]
    add    esi,eax
    cmp    esi,edi
    je    Branch7
    mov    eax,edi
    sub    eax,edi
    inc    eax
    je    Branch4
    push    eax
    push    edi
    push    esi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch4:
    mov    eax,DWORD PTR [ebx+0x4]
    sub    esi,edi
    add    eax,esi
    mov    DWORD PTR [ebx+0x4],eax
    jmp    Branch7
  Branch5:
    test    ecx,ecx
    je    Branch6
    mov    eax,ecx
    mov    esi,edx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    esi,DWORD PTR [esp+0x2c]
  Branch6:
    mov    cl,BYTE PTR [esp+0x2c]
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [esp+0x2c],cl
    mov    ecx,DWORD PTR [ebx+0x4]
    lea    eax,[esp+0x2c]
    sub    ecx,edi
    push    eax
    add    ecx,edx
    push    esi
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
  Branch7:
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x18
  }
}

// Destroy proxy first, then test CURRENT deleteWord lowBYTE bit0 before freeing; return original owner. RET4.
// R6GameService.dll @ 10062510 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteDerivedTransportRecordWithText(void *owner,uint deleteWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyDerivedTransportRecordWithText
    test    BYTE PTR [esp+0x8],0x1
    je    Branch8
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch8:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Reset class/list tables, invoke captured list range target, free CURRENT list head then text buffer and base.
// Four-state map preserves entered head-only/no-op gaps and CURRENT saved contexts; raw base cleanup EAX.
// R6GameService.dll @ 10062560 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyDerivedTransportRecordWithText(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProxyDestructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clProxyConnectionVTable
    mov    DWORD PTR [esp+0x28],0x0
    lea    edi,[esi+0x84]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclProxyMessageVTable
    push    ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    ebx,[edi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebp,DWORD PTR [edi]
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x20]
    mov    ecx,edi
    push    eax
    call    DWORD PTR [ebp+0x10]
    mov    DWORD PTR [esp+0x1c],ebx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x28],0x3
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    ebx,DWORD PTR [ebx]
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x68]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0xffffffff
    call    R6GameServiceAddresses::DestroyTransportRecordMembers
    mov    ecx,DWORD PTR [esp+0x20]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x1c
    ret
  }
}

// Connect via table+4 using text68 and raw owner-upper/WORD74 lane; AL0 formats/logs the current endpoint.
// Success queues66/8/0b descriptor, publishes ready78=1, then enters six-state cleanup. Raw AL result/RET8.
// R6GameService.dll @ 10062610 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectAndSendProxyRequest(void *owner,const char *text0,const char *text1)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProxySenderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x124
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x20],0x0
    push    0x0
    mov    cx,WORD PTR [esi+0x74]
    mov    eax,DWORD PTR [esi+0x68]
    mov    edx,DWORD PTR [esi]
    push    ecx
    push    eax
    mov    ecx,esi
    call    DWORD PTR [edx+0x4]
    test    al,al
    jne    Branch9
    mov    eax,DWORD PTR [esi+0x68]
    xor    edx,edx
    mov    dx,WORD PTR [esi+0x74]
    lea    ecx,[esp+0x28]
    push    edx
    push    eax
    push    R6GameServiceAddresses::TextConnectionToProxySDFailed
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x10
    lea    edx,[esp+0x28]
    mov    ecx,esi
    push    edx
    push    R6GameServiceAddresses::GRegistrationEmptyText
    push    R6GameServiceAddresses::TextPROXY
    push    R6GameServiceAddresses::GRegistrationEmptyText
    push    0x5
    call    R6GameServiceAddresses::ForwardLogRequest
    xor    al,al
    jmp    Branch10
  Branch9:
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x10],0x3
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x18]
    push    eax
    mov    DWORD PTR [esp+0x134],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [esp+0x138]
    mov    DWORD PTR [esp+0x130],0x2
    push    ecx
    lea    ecx,[esp+0xc]
    call    R6GameServiceAddresses::AppendClDataListString
    mov    edx,DWORD PTR [esp+0x13c]
    lea    ecx,[esp+0x8]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListString
    lea    eax,[esp+0x8]
    mov    ecx,esi
    push    eax
    push    0xb
    push    0x8
    push    0x66
    call    R6GameServiceAddresses::QueueCopiedTransportRecord
    mov    DWORD PTR [esi+0x78],0x1
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x130],0x3
    mov    DWORD PTR [esp+0x20],ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x130],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x18]
    mov    DWORD PTR [esp+0x24],edx
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x130],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x18]
    push    0x1
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    al,0x1
  Branch10:
    mov    ecx,DWORD PTR [esp+0x128]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x130
    ret    0x8
  }
}

// Close the provider before clearing ready78; return close-result upper24 with AL1. No own guard.
// R6GameService.dll @ 100627a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CloseProxyAndClearReady(void *owner)
{
  __asm {
    push    esi
    push    R6GameServiceAddresses::TextDisconnecting
    mov    esi,ecx
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    ecx,esi
    call    R6GameServiceAddresses::ShutdownTransportChannels
    mov    DWORD PTR [esi+0x78],0x0
    mov    al,0x1
    pop    esi
    ret
  }
}

// Tail-forward all five log words through CURRENT owner90; NULL logger returns incoming EAX unchanged. RET14.
// R6GameService.dll @ 100627d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardLogRequest(
    void *owner,uint severity,const char *category,const char *source,const char *detail,const char *message)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x90]
    test    ecx,ecx
    je    Branch11
    jmp    R6GameServiceAddresses::WriteServiceLogMessage
  Branch11:
    ret    0x14
  }
}

// Tail-forward three untouched words through CURRENT context7c/table+4; NULL context retains incoming EAX. RETc.
// R6GameService.dll @ 100627f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProxyCallbackSlot4(void *owner,uint word0,uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x7c]
    test    ecx,ecx
    je    Branch12
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x8],edx
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0x4]
  Branch12:
    ret    0xc
  }
}

// Tail-forward three untouched words through CURRENT context7c/table+8; NULL context retains incoming EAX. RETc.
// R6GameService.dll @ 10062810 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProxyCallbackSlot8(void *owner,uint word0,uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x7c]
    test    ecx,ecx
    je    Branch13
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x8],edx
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0x8]
  Branch13:
    ret    0xc
  }
}

// Tail-forward three untouched words through CURRENT context7c/table+c; NULL context retains incoming EAX. RETc.
// R6GameService.dll @ 10062830 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProxyCallbackSlotC(void *owner,uint word0,uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x7c]
    test    ecx,ecx
    je    Branch14
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x8],edx
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0xc]
  Branch14:
    ret    0xc
  }
}

// Forward four words via context7c/table10, then delete captured non-NULL payload1 only after callback return.
// NULL context skips forwarding and deletion; no own guard or return normalization. RET10.
// R6GameService.dll @ 10062850 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProxyCallbackAndDeletePayload(
    void *owner,uint word0,uint word1,uint word2,void *payload)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x7c]
    push    esi
    test    ecx,ecx
    je    Branch15
    mov    esi,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    push    esi
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    call    DWORD PTR [eax+0x10]
    test    esi,esi
    je    Branch15
    mov    eax,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [eax]
  Branch15:
    pop    esi
    ret    0x10
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test    eax,eax
    je    Branch16
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x98
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch16:
    ret
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069edd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyTransportRecordMembers
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069ee5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind3(void)
{
  __asm {
    lea    ecx,[ebp+0x18]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069eed : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x68
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069ef8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x2
    test    eax,eax
    je    Branch17
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch17:
    ret
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f12 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind7(void)
{
  __asm {
    lea    ecx,[ebp+0x18]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f1a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeDerivedTransportRecordWithTextUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x84
    jmp    R6GameServiceAddresses::thunk_DestroyCallbackListContainer
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindDerivedTransportBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::DestroyTransportRecordMembers
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindDerivedTransportTextBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    add    ecx,0x68
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f53 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindDerivedTransportListStorage(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x18],0x0
    je    Branch18
    mov    eax,DWORD PTR [ebp-0x18]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch19
  Branch18:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch19:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f7a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindDerivedTransportNoOp(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x12c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069f9b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x12d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069fa6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x12c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069fb1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x12c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069fbc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x114],0x0
    je    Branch20
    mov    eax,DWORD PTR [ebp-0x114]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x110],eax
    jmp    Branch21
  Branch20:
    mov    DWORD PTR [ebp-0x110],0x0
  Branch21:
    mov    ecx,DWORD PTR [ebp-0x110]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Run the exact inherited native flag/member/context cleanup; preserve no-op and entered no-retry states.
// R6GameService.dll @ 10069ff2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConnectAndSendProxyRequestUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x110]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select the exact native proxy lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10069f28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxyConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the exact native proxy lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10069f82 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxyDestructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyDerivedTransportRecordWithTextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the exact native proxy lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10069ffd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxySenderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConnectAndSendProxyRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084a78 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeDerivedTransportRecordWithTextUnwindMap[8] = {
  {-1, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind1},
  {0x0, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind2},
  {0x1, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind3},
  {0x1, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind4},
  {0x3, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind5},
  {0x4, 0x0},
  {0x5, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind7},
  {0x3, R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwind8},
};

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084a78 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeDerivedTransportRecordWithTextExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::InitializeDerivedTransportRecordWithTextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084ad4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyDerivedTransportRecordWithTextUnwindMap[4] = {
  {-1, R6GameServiceAddresses::UnwindDerivedTransportBase},
  {0x0, R6GameServiceAddresses::UnwindDerivedTransportTextBuffer},
  {0x1, R6GameServiceAddresses::UnwindDerivedTransportListStorage},
  {0x1, R6GameServiceAddresses::UnwindDerivedTransportNoOp},
};

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084ad4 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyDerivedTransportRecordWithTextExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::DestroyDerivedTransportRecordWithTextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084b10 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConnectAndSendProxyRequestUnwindMap[6] = {
  {-1, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind1},
  {0x0, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind2},
  {-1, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind3},
  {-1, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind4},
  {0x3, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind5},
  {0x3, R6GameServiceAddresses::ConnectAndSendProxyRequestUnwind6},
};

// Literal native proxy lifetime map/FuncInfo.
// R6GameService.dll data @ 10084b10 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConnectAndSendProxyRequestExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::ConnectAndSendProxyRequestUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clProxyConnectionVTable
// R6GameService.dll data @ 100783c8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clProxyConnectionVTableRecord {
  R6GameServiceNative::Address DeleteDerivedTransportRecordWithText; // +0x00
  R6GameServiceNative::Address StartTransportChannels; // +0x04
  R6GameServiceNative::Address CloseProxyAndClearReady; // +0x08
  R6GameServiceNative::Address ReceiveRecordWithSourceThunk; // +0x0c
  R6GameServiceNative::Address ForwardProxyCallbackSlot4; // +0x10
  R6GameServiceNative::Address ForwardProxyCallbackSlot8; // +0x14
  R6GameServiceNative::Address ForwardProxyCallbackSlotC; // +0x18
  R6GameServiceNative::Address ForwardProxyCallbackAndDeletePayload; // +0x1c
};
const clProxyConnectionVTableRecord clProxyConnectionVTable = {
  R6GameServiceAddresses::DeleteDerivedTransportRecordWithText,
  R6GameServiceAddresses::StartTransportChannels,
  R6GameServiceAddresses::CloseProxyAndClearReady,
  R6GameServiceAddresses::ReceiveRecordWithSourceThunk,
  R6GameServiceAddresses::ForwardProxyCallbackSlot4,
  R6GameServiceAddresses::ForwardProxyCallbackSlot8,
  R6GameServiceAddresses::ForwardProxyCallbackSlotC,
  R6GameServiceAddresses::ForwardProxyCallbackAndDeletePayload,
};
