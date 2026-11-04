#include "native_addresses.h"
#include "native_records.h"

// These bodies share the dispatcher prefix reached through clGLClient field158; original class ownership is unresolved.

// If service10 exists, clone an outgoing six-word descriptor, reload scalar arguments/service and dispatch1e/2.
// Normalize only AL, retain raw upper EAX; POP ECX receives the descriptor address from rewritten saved-ECX scratch.
// R6GameService.dll @ 100447a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchRequest1e(void *dispatcher,uint value,uint key,
                                                        const void *payload)
{
  __asm {
    push    ecx
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    jne    Branch1
    xor    al,al
    pop    esi
    pop    ecx
    ret    0xc
  Branch1:
    mov    eax,DWORD PTR [esp+0x14]
    sub    esp,0x18
    mov    ecx,esp
    mov    DWORD PTR [esp+0x1c],esp
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x24]
    push    0x2
    push    0x1e
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    call    R6GameServiceAddresses::ApplyIndexedKeyUpdate
    test    al,al
    setne    al
    pop    esi
    pop    ecx
    ret    0xc
  }
}

// Refresh selector15, reload argument words, invoke the reader on the saved receiver and normalize only AL.
// R6GameService.dll @ 10044d50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RefreshState15AndRead(void *dispatcher,void *codeOut,void *indexOut)
{
  __asm {
    push    esi
    push    0x15
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x15
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh selector12; absent record clears only AL. Otherwise store its full+18 word, then replace return AL with1.
// Preserve cached word/argument access order and POP ESI before the output store; add no local cleanup or validation.
// R6GameService.dll @ 10044d80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadState12Word(void *dispatcher,void *valueOut)
{
  __asm {
    push    esi
    push    0x12
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    esi,DWORD PTR [esi+0x8]
    test    esi,esi
    jne    Branch2
    xor    al,al
    pop    esi
    ret    0x4
  Branch2:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esi+0x18]
    pop    esi
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    ret    0x4
  }
}

// Destroy/free captured record8, clear its owner slot, then load current queue20/selector and publish popped pointer.
// Retain full selector word, late accesses and callback changes; no wrapper guard or old-record rollback.
// R6GameService.dll @ 100431d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ReplaceCachedRecordBySelector(void *dispatcher,uint selector)
{
  __asm {
    push    esi
    push    edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x8]
    test    esi,esi
    je    Branch3
    mov    ecx,esi
    call    R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [edi+0x8],0x0
  Branch3:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [edi+0x20]
    push    eax
    call    R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    DWORD PTR [edi+0x8],eax
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Copy current D1 item1, publish its code before validating lowWORD id, then accept26 or parse nested27 item0.
// Keep current record reload, cached code output, partial writes, raw cleanup EAX/AL and six-state lifetimes.
// R6GameService.dll @ 10043210 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CheckD1DescriptorAndOptionalIndex(void *dispatcher,uint expectedId,
                                                                         void *codeOut,void *indexOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDescriptorReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebp
    push    esi
    mov    esi,ecx
    push    0x0
    mov    DWORD PTR [esp+0x10],0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebp
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x48],0x1
    test    eax,eax
    je    Branch5
    movzx    cx,BYTE PTR [eax+0x4]
    cmp    cx,0xd1
    mov    DWORD PTR [esp+0xc],ecx
    jne    Branch5
    lea    ecx,[esp+0xc]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    je    Branch5
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch5
    mov    esi,DWORD PTR [esp+0x54]
    mov    cl,BYTE PTR [esp+0xc]
    lea    edx,[esp+0xa]
    push    0x0
    mov    BYTE PTR [esi],cl
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    je    Branch5
    mov    ax,WORD PTR [esp+0xa]
    cmp    ax,WORD PTR [esp+0x50]
    jne    Branch5
    xor    eax,eax
    mov    al,BYTE PTR [esi]
    sub    eax,0x26
    je    Branch8
    dec    eax
    je    Branch4
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebp
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0xc
  Branch4:
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x28],esi
    lea    ecx,[esp+0x28]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x50],0x3
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    lea    ecx,[esp+0x28]
    jne    Branch6
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
  Branch5:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0xc
  Branch6:
    mov    edx,DWORD PTR [esp+0x58]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch7
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esp+0x1c],ebp
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0xc
  Branch7:
    call    R6GameServiceAddresses::DestroyClDataList
  Branch8:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0xc
  }
}

// Reset main descriptor EBP-0x3c to its base table after an interrupted initial construction.
// R6GameService.dll @ 10067290 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed main descriptor at inherited EBP-0x3c through the native full-list tail.
// R6GameService.dll @ 10067298 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the main descriptor base table at EBP-0x3c after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 100672a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested descriptor EBP-0x24 to its base table after interrupted nested construction.
// R6GameService.dll @ 100672a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed nested descriptor at inherited EBP-0x24 through the native full-list tail.
// R6GameService.dll @ 100672b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset main descriptor base table at EBP-0x3c after entered failure-path list destruction; do not retry it.
// R6GameService.dll @ 100672b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CheckD1DescriptorAndOptionalIndexUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the six-state descriptor-reader lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 100672c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDescriptorReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal descriptor-reader unwind/FuncInfo words.
// R6GameService.dll data @ 1008197c : native storage identity retained.
const R6GameServiceNative::UnwindEntry CheckD1DescriptorAndOptionalIndexUnwindMap[6] = {
  {-1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind1},
  {-1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind2},
  {0x1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind3},
  {0x1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind4},
  {-1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind5},
  {-1, R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwind6},
};

// Literal descriptor-reader unwind/FuncInfo words.
// R6GameService.dll data @ 100819ac : native storage identity retained.
const R6GameServiceNative::FuncInfo CheckD1DescriptorAndOptionalIndexExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndexUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Release old callback only when ownership byte18 iszero, using its native virtual-base adjustment/delete1.
// Then reload incoming callback, publish byte18=1/slot14 and replace only return AL with1.
// R6GameService.dll @ 10048490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceServiceCallback(void *dispatcher,void *callback)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x18]
    test    al,al
    jne    Branch9
    mov    eax,DWORD PTR [esi+0x14]
    test    eax,eax
    je    Branch9
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch9:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x18],0x1
    mov    DWORD PTR [esi+0x14],ecx
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Read selector15 into retained two-word scratch; on AL success load current callback14/slot0 and pass both full words.
// Failure clears AL; success sets AL1 over callback upperEAX. No callback/null/output repair or local guard.
// R6GameService.dll @ 100484d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall InvokeState15Callback(void *dispatcher)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::RefreshState15AndRead
    test    al,al
    je    Branch10
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch10:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// If cached service10 has no a4-list links and b0 isNULL, call current callback slot8 then clear enabled byte19.
// Preserve wrapped link count, cached service/head, native return residues and unconditional final AL1.
// R6GameService.dll @ 10048510 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RecomputeServiceCallbackState(void *dispatcher)
{
  __asm {
    push    esi
    push    edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x10]
    test    esi,esi
    je    Branch13
    mov    ecx,DWORD PTR [esi+0xa4]
    xor    edx,edx
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je    Branch12
  Branch11:
    mov    eax,DWORD PTR [eax]
    inc    edx
    cmp    eax,ecx
    jne    Branch11
    test    edx,edx
    jne    Branch13
  Branch12:
    mov    eax,DWORD PTR [esi+0xb0]
    test    eax,eax
    jne    Branch13
    mov    ecx,DWORD PTR [edi+0x14]
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0x8]
    mov    BYTE PTR [edi+0x19],0x0
  Branch13:
    pop    edi
    mov    al,0x1
    pop    esi
    ret
  }
}

// Read selector12 into saved-ECX scratch; deliver its full word through current callback slot4 only when AL/byte19 permit.
// Always set AL1; POP ECX returns the current output scratch, or original receiver if the reader left it unchanged.
// R6GameService.dll @ 10048550 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector12(void *dispatcher)
{
  __asm {
    push    ecx
    lea    eax,[esp+0x0]
    push    esi
    push    eax
    mov    esi,ecx
    call    R6GameServiceAddresses::ReadState12Word
    test    al,al
    je    Branch14
    mov    al,BYTE PTR [esi+0x19]
    test    al,al
    je    Branch14
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [esp+0x4]
    push    eax
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x4]
  Branch14:
    mov    al,0x1
    pop    esi
    pop    ecx
    ret
  }
}

// When byte19 iszero clear only AL; otherwise refresh full selectorfffffffd then execute callback-state recomputation.
// R6GameService.dll @ 10048580 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RefreshEnabledServiceCallback(void *dispatcher)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x19]
    test    al,al
    jne    Branch15
    xor    al,al
    pop    esi
    ret
  Branch15:
    push    0xfffffffd
    mov    ecx,esi
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    ecx,esi
    call    R6GameServiceAddresses::RecomputeServiceCallbackState
    mov    al,0x1
    pop    esi
    ret
  }
}

// Decode state9 into three retained words; pass their full widths through current callback14 slot28.
// Reader AL gates delivery; return reader upperEAX/AL0 or callback upperEAX/AL1.
// R6GameService.dll @ 10049480 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverServiceState9(void *dispatcher)
{
  __asm {
    sub    esp,0xc
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadServiceState9
    test    al,al
    je    Branch16
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    call    DWORD PTR [eax+0x28]
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret
  Branch16:
    xor    al,al
    pop    esi
    add    esp,0xc
    ret
  }
}

// Decode selector0c into retained scalar words and a 36-byte text buffer; dispatch five values through current slot0c.
// Forward the complete marker scratch word, preserve untouched text bytes and normalize only return AL.
// R6GameService.dll @ 100494d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector0C(void *dispatcher)
{
  __asm {
    sub    esp,0x34
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x10]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseCachedSelector0cRecord
    test    al,al
    je    Branch17
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0xc]
    mov    al,0x1
    pop    esi
    add    esp,0x34
    ret
  Branch17:
    xor    al,al
    pop    esi
    add    esp,0x34
    ret
  }
}

// Clear exactly 129 text bytes, decode selector18 and pass full scalar words/text through current callback slot14.
// Leave three trailing storage bytes and marker upper bytes retained; preserve raw upper return and AL0/1.
// R6GameService.dll @ 10049530 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector18(void *dispatcher)
{
  __asm {
    sub    esp,0x94
    xor    eax,eax
    lea    edx,[esp+0x10]
    push    esi
    push    edi
    mov    esi,ecx
    mov    ecx,0x20
    lea    edi,[esp+0x18]
    rep    stos DWORD PTR es:[edi],eax
    stos    BYTE PTR es:[edi],al
    lea    eax,[esp+0xc]
    lea    ecx,[esp+0x14]
    push    eax
    push    ecx
    lea    eax,[esp+0x10]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::DecodeIndexedField18
    test    al,al
    je    Branch18
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x20]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x14]
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x94
    ret
  Branch18:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x94
    ret
  }
}

// Clear exactly 129 text bytes, decode selector17 and pass full scalar words/text through current callback slot10.
// Leave three trailing storage bytes and marker upper bytes retained; preserve raw upper return and AL0/1.
// R6GameService.dll @ 100495b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector17(void *dispatcher)
{
  __asm {
    sub    esp,0x94
    xor    eax,eax
    lea    edx,[esp+0x10]
    push    esi
    push    edi
    mov    esi,ecx
    mov    ecx,0x20
    lea    edi,[esp+0x18]
    rep    stos DWORD PTR es:[edi],eax
    stos    BYTE PTR es:[edi],al
    lea    eax,[esp+0xc]
    lea    ecx,[esp+0x14]
    push    eax
    push    ecx
    lea    eax,[esp+0x10]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::DecodeIndexedField17
    test    al,al
    je    Branch19
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x20]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x10]
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x94
    ret
  Branch19:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x94
    ret
  }
}

// Decode/remove selector37 key, then pass both complete scratch words through current callback14 slot2c.
// Preserve parser partial writes and raw upper return; AL alone reports whether delivery completed.
// R6GameService.dll @ 10049ac0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector37(void *dispatcher)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::RemoveDecodedKeyRecord
    test    al,al
    je    Branch20
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x2c]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch20:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Construct both descriptors before checking service10; refresh9, copy outer/nested item1, publish27 and read ints0/1.
// Preserve late output pointers, partial writes, final cleanup upperEAX/AL and seven distinct lifetime states.
// R6GameService.dll @ 10044ef0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadServiceState9(void *dispatcher,void *codeOut,void *firstOut,void *secondOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectState9ReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    ebp
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    push    edi
    push    0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x18],edi
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    mov    ebx,0x1
    push    0x0
    push    0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x54],ebx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    mov    eax,DWORD PTR [esi+0x10]
    mov    BYTE PTR [esp+0x4c],0x3
    test    eax,eax
    jne    Branch21
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch24
  Branch21:
    push    0x9
    mov    ecx,esi
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x2c]
    push    ebx
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch22
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch24
  Branch22:
    mov    edx,DWORD PTR [esp+0x54]
    lea    eax,[esp+0x14]
    push    ebx
    push    eax
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [edx],0x27
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch23
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch24
  Branch23:
    mov    ecx,DWORD PTR [esp+0x58]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch25
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
  Branch24:
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch27
  Branch25:
    mov    edx,DWORD PTR [esp+0x5c]
    push    ebx
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x4c],bl
    jne    Branch26
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch27
  Branch26:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,bl
  Branch27:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Reset outer descriptor EBP-24 base after interrupted initial construction.
// R6GameService.dll @ 100676e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed outer descriptor at inherited EBP-24 through the native full-list tail.
// R6GameService.dll @ 100676e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested descriptor EBP-3c base after interrupted nested construction.
// R6GameService.dll @ 100676f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed nested descriptor at inherited EBP-3c through the native full-list tail.
// R6GameService.dll @ 100676f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested descriptor EBP-3c after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067700 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer descriptor EBP-24 after entered failed-read pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067708 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer descriptor EBP-24 after entered successful-read pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067710 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadServiceState9Unwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the seven-state state9 descriptor lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067718 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectState9ReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReadServiceState9ExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal state9 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10081eb4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReadServiceState9UnwindMap[7] = {
  {-1, R6GameServiceAddresses::ReadServiceState9Unwind1},
  {-1, R6GameServiceAddresses::ReadServiceState9Unwind2},
  {0x1, R6GameServiceAddresses::ReadServiceState9Unwind3},
  {0x1, R6GameServiceAddresses::ReadServiceState9Unwind4},
  {0x1, R6GameServiceAddresses::ReadServiceState9Unwind5},
  {-1, R6GameServiceAddresses::ReadServiceState9Unwind6},
  {-1, R6GameServiceAddresses::ReadServiceState9Unwind7},
};

// Literal state9 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10081eec : native storage identity retained.
const R6GameServiceNative::FuncInfo ReadServiceState9ExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::ReadServiceState9UnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh0c and decode D1 marker/value; copy item1 twice, then read text1 for27 or int0/text1/int2 otherwise.
// Keep cached marker/first/second pointers, current service10, partial outputs and raw cleanup EAX/AL.
// R6GameService.dll @ 10045ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseCachedSelector0cRecord(void *dispatcher,void *markerOut,void *quotedOut,
                                                                    void *textOut,void *firstOut,void *secondOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector0cReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    edi
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],edi
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],edi
    push    0xc
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch29
    mov    eax,DWORD PTR [esp+0x54]
    mov    edi,DWORD PTR [esp+0x50]
    push    eax
    push    edi
    push    0xc
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    je    Branch29
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x28]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch29
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch29
    cmp    BYTE PTR [edi],0x27
    jne    Branch28
    mov    ecx,DWORD PTR [esp+0x58]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch32
    jmp    Branch29
  Branch28:
    mov    ebx,DWORD PTR [esp+0x5c]
    push    0x0
    push    ebx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x10]
    je    Branch30
    mov    edx,DWORD PTR [esp+0x58]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x10]
    je    Branch30
    mov    edi,DWORD PTR [esp+0x60]
    push    0x2
    push    edi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch31
  Branch29:
    lea    ecx,[esp+0x10]
  Branch30:
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch31:
    mov    eax,DWORD PTR [edi]
    mov    ecx,DWORD PTR [ebx]
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    call    R6GameServiceAddresses::CLobbySrvConnectionListAppendUniqueWord
  Branch32:
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataListAlias
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Reset outer descriptor EBP-24 base after interrupted initial construction.
// R6GameService.dll @ 10067950 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed outer descriptor at inherited EBP-24 through the native full-list tail.
// R6GameService.dll @ 10067958 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested descriptor EBP-3c base after interrupted nested construction.
// R6GameService.dll @ 10067960 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed nested descriptor at inherited EBP-3c through the native full-list tail.
// R6GameService.dll @ 10067968 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select the shared four-state selector0c/0e descriptor lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067970 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector0cReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared selector0c/0e descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 100820cc : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap[4] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind1},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind2},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind3},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind4},
};

// Literal shared selector0c/0e descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 100820ec : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh17/read D1, publish current record18, copy item1 twice; marker26 selects int0/text1, others int1/text2.
// Failed text copy uses literal fallback string and still succeeds; retain partial outputs and raw cleanup EAX/AL.
// R6GameService.dll @ 100450c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DecodeIndexedField17(void *dispatcher,void *markerOut,void *quotedOut,
                                                         void *textOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector17And18ReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    push    0x17
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esp+0x54]
    mov    edi,DWORD PTR [esp+0x50]
    push    eax
    push    edi
    push    0x17
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch33
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    mov    BYTE PTR [esp+0x48],0x4
    jmp    Branch36
  Branch33:
    mov    ecx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [esp+0x60]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x18]
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [eax],edx
    mov    edx,DWORD PTR [esi+0x8]
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch34
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch34:
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch35
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch37
  Branch35:
    mov    al,BYTE PTR [edi]
    xor    ecx,ecx
    mov    edx,DWORD PTR [esp+0x5c]
    cmp    al,0x26
    setne    cl
    mov    esi,ecx
    lea    ecx,[esp+0x10]
    mov    eax,esi
    inc    esi
    push    eax
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch38
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    mov    BYTE PTR [esp+0x48],0x6
  Branch36:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
  Branch37:
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch38:
    push    esi
    mov    esi,DWORD PTR [esp+0x5c]
    push    esi
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch40
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    mov    edx,esi
    sub    edx,eax
  Branch39:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test    cl,cl
    jne    Branch39
  Branch40:
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Refresh18/read D1, publish current record18, copy item1 twice; marker26 selects int0/text1, others int1/text2.
// Failed text copy uses literal fallback string and still succeeds; retain partial outputs and raw cleanup EAX/AL.
// R6GameService.dll @ 100452f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DecodeIndexedField18(void *dispatcher,void *markerOut,void *quotedOut,
                                                         void *textOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector17And18ReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    push    0x18
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esp+0x54]
    mov    edi,DWORD PTR [esp+0x50]
    push    eax
    push    edi
    push    0x18
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch41
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    mov    BYTE PTR [esp+0x48],0x4
    jmp    Branch44
  Branch41:
    mov    ecx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [esp+0x60]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x18]
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [eax],edx
    mov    edx,DWORD PTR [esi+0x8]
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch42
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch42:
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch43
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch45
  Branch43:
    mov    al,BYTE PTR [edi]
    xor    ecx,ecx
    mov    edx,DWORD PTR [esp+0x5c]
    cmp    al,0x26
    setne    cl
    mov    esi,ecx
    lea    ecx,[esp+0x10]
    mov    eax,esi
    inc    esi
    push    eax
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch46
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],ebx
    mov    BYTE PTR [esp+0x48],0x6
  Branch44:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
  Branch45:
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch46:
    push    esi
    mov    esi,DWORD PTR [esp+0x5c]
    push    esi
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch48
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    mov    edx,esi
    sub    edx,eax
  Branch47:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test    cl,cl
    jne    Branch47
  Branch48:
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Reset shared selector17/18 outer descriptor EBP-24 base after interrupted initial construction.
// R6GameService.dll @ 10067730 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy shared selector17/18 completed outer descriptor at inherited EBP-24 through the full-list tail.
// R6GameService.dll @ 10067738 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind22(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared selector17/18 nested descriptor EBP-3c base after interrupted construction.
// R6GameService.dll @ 10067740 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind32(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy shared selector17/18 completed nested descriptor at inherited EBP-3c through the full-list tail.
// R6GameService.dll @ 10067748 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind42(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested EBP-3c after entered pointer-list destruction on D1 failure; do not retry its list.
// R6GameService.dll @ 10067750 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-24 after entered pointer-list destruction on first-copy failure; do not retry its list.
// R6GameService.dll @ 10067758 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-3c after entered pointer-list destruction on integer failure; do not retry its list.
// R6GameService.dll @ 10067760 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-24 after entered pointer-list destruction on success; do not retry its list.
// R6GameService.dll @ 10067768 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the shared eight-state selector17/18 descriptor map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067770 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector17And18ReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared selector17/18 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10081f08 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap2[8] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind12},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind22},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind32},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind42},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind5},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind6},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind7},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind8},
};

// Literal shared selector17/18 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10081f48 : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// If service10 exists, refresh37, publish current record18, copy item1/read int0 and remove using current record18.
// Preserve cached value pointer, late service/cache loads, partial outputs and rewritten cleanup argument/ten-state map.
// R6GameService.dll @ 10045910 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveDecodedKeyRecord(void *dispatcher,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector37ReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    xor    edi,edi
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x10],edi
    cmp    eax,edi
    je    Branch52
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],ebp
    push    0x37
    mov    ecx,esi
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,edi
    jne    Branch49
    mov    DWORD PTR [esp+0x14],ebp
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x2
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch54
  Branch49:
    mov    edx,DWORD PTR [esp+0x40]
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x14]
    push    0x1
    mov    DWORD PTR [edx],ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch50
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebx,0x4
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],edx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x5
    jmp    Branch51
  Branch50:
    push    edi
    mov    edi,DWORD PTR [esp+0x40]
    push    edi
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch53
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebx,0x6
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x7
  Branch51:
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch52:
    xor    al,al
    jmp    Branch54
  Branch53:
    mov    ecx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [edi]
    mov    edx,DWORD PTR [ecx+0x18]
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    push    eax
    call    R6GameServiceAddresses::RemoveValueFromKeyList
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebx,0x8
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x9
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch54:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x8
  }
}

// Reset descriptor EBP-24 base at the inherited selector37 construction/entered-list stage.
// R6GameService.dll @ 10067870 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed selector37 descriptor EBP-24 through the native full-list tail.
// R6GameService.dll @ 10067878 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor EBP-24 base at the inherited selector37 construction/entered-list stage.
// R6GameService.dll @ 10067880 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten argument EBP+8; publish its head-slot adjustment or NULL, then tail release59140.
// R6GameService.dll @ 10067888 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch55
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2c],eax
    jmp    Branch56
  Branch55:
    mov    DWORD PTR [ebp-0x2c],0x0
  Branch56:
    mov    ecx,DWORD PTR [ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 base at the inherited selector37 construction/entered-list stage.
// R6GameService.dll @ 100678af : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten argument EBP+8; publish its head-slot adjustment or NULL, then tail release59140.
// R6GameService.dll @ 100678b7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch57
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch58
  Branch57:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch58:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 base at the inherited selector37 construction/entered-list stage.
// R6GameService.dll @ 100678de : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten argument EBP+8; publish its head-slot adjustment or NULL, then tail release59140.
// R6GameService.dll @ 100678e6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch59
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch60
  Branch59:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch60:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 base at the inherited selector37 construction/entered-list stage.
// R6GameService.dll @ 1006790d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten argument EBP+8; publish its head-slot adjustment or NULL, then tail release59140.
// R6GameService.dll @ 10067915 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl RemoveDecodedKeyRecordUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch61
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch62
  Branch61:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch62:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the ten-state selector37 descriptor lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 1006793c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector37ReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RemoveDecodedKeyRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector37 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10082060 : native storage identity retained.
const R6GameServiceNative::UnwindEntry RemoveDecodedKeyRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind1},
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind2},
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind3},
  {0x2, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind4},
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind5},
  {0x4, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind6},
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind7},
  {0x6, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind8},
  {-1, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind9},
  {0x8, R6GameServiceAddresses::RemoveDecodedKeyRecordUnwind10},
};

// Literal selector37 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 100820b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo RemoveDecodedKeyRecordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::RemoveDecodedKeyRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Parse selector08 into retained four-word scratch and pass full widths through current callback14 slot58.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a030 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector08(void *dispatcher)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector08MarkerAndField
    test    al,al
    je    Branch63
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x58]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch63:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector39 into three retained words and pass full widths through current callback14 slot5c.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a080 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector39(void *dispatcher)
{
  __asm {
    sub    esp,0xc
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector39IndexedFields
    test    al,al
    je    Branch64
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    call    DWORD PTR [eax+0x5c]
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret
  Branch64:
    xor    al,al
    pop    esi
    add    esp,0xc
    ret
  }
}

// Zero only third scratch word, parse selector3e, then deliver three full words through current callback slot60.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a0d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector3E(void *dispatcher)
{
  __asm {
    sub    esp,0xc
    push    esi
    mov    esi,ecx
    lea    eax,[esp+0x4]
    lea    ecx,[esp+0x8]
    push    eax
    lea    edx,[esp+0x10]
    push    ecx
    push    edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0x0
    call    R6GameServiceAddresses::ParseSelector3eIndexedFieldPair
    test    al,al
    je    Branch65
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    call    DWORD PTR [eax+0x60]
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret
  Branch65:
    xor    al,al
    pop    esi
    add    esp,0xc
    ret
  }
}

// Parse selector1f into retained four-word scratch and pass full widths through current callback14 slot64.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a120 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector1F(void *dispatcher)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector1fMarkerAndField
    test    al,al
    je    Branch66
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x64]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch66:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector1e into retained three-word scratch and pass full widths through current callback14 slot68.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a170 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector1E(void *dispatcher)
{
  __asm {
    sub    esp,0xc
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector1eMarkerAndField
    test    al,al
    je    Branch67
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    call    DWORD PTR [eax+0x68]
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret
  Branch67:
    xor    al,al
    pop    esi
    add    esp,0xc
    ret
  }
}

// Parse selector0f into retained four-word scratch and pass full widths through current callback14 slot70.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a1d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector0F(void *dispatcher)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector0fMarkerAndField
    test    al,al
    je    Branch68
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x70]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch68:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector21 into retained four-word scratch and pass full widths through current callback14 slot74.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a220 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector21(void *dispatcher)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector21MarkerAndField
    test    al,al
    je    Branch69
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x74]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch69:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector41 into retained two-word scratch and deliver through current callback14 slot94.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a950 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector41(void *dispatcher)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector41IndexedValue
    test    al,al
    je    Branch70
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x94]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch70:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Zero saved-ECX scratch, read selector6 and deliver its full word through current callback slot98.
// POP ECX restores the scratch output even when delivery is skipped; preserve raw upperEAX and normalize only AL.
// R6GameService.dll @ 1004a990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector6(void *dispatcher)
{
  __asm {
    push    ecx
    lea    eax,[esp+0x0]
    push    esi
    push    eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    call    R6GameServiceAddresses::ReadRefreshedSelector6
    test    al,al
    je    Branch71
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [esp+0x4]
    push    eax
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x98]
    mov    al,0x1
    pop    esi
    pop    ecx
    ret
  Branch71:
    xor    al,al
    pop    esi
    pop    ecx
    ret
  }
}

// Read selector2a into retained two-word scratch and deliver full words through current callback14 slot9c.
// Gate on parser AL; failure clears only AL, successful callback sets AL1 over its raw upperEAX.
// R6GameService.dll @ 1004a9d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector2A(void *dispatcher)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadRefreshedSelector2A
    test    al,al
    je    Branch72
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x9c]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch72:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Refresh full selector6; absent cache clears AL on refresh residue, present cache writes full record18 and sets AL1.
// Restore ESI before the output store; preserve the raw record-word upper return and current output argument.
// R6GameService.dll @ 10048420 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadRefreshedSelector6(void *dispatcher,void *wordOut)
{
  __asm {
    push    esi
    push    0x6
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    esi,DWORD PTR [esi+0x8]
    test    esi,esi
    jne    Branch73
    xor    al,al
    pop    esi
    ret    0x4
  Branch73:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esi+0x18]
    pop    esi
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    ret    0x4
  }
}

// Refresh full selector2a; absent CURRENT cache returns full zero, otherwise reload output pointers and read D1.
// Normalize only AL over delegated upperEAX; no additional guard or output initialization.
// R6GameService.dll @ 10048450 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadRefreshedSelector2A(void *dispatcher,void *markerOut,void *indexOut)
{
  __asm {
    push    esi
    push    0x2a
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch74
    xor    al,al
    pop    esi
    ret    0x8
  Branch74:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x2a
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Tail selector20 dispatcher47170 with incoming registers/stack intact; preserve its entire raw return.
// R6GameService.dll @ 1004a1c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DispatchSelector20Entries(int dispatcher)
{
  __asm {
    jmp    R6GameServiceAddresses::DispatchSelector20Entries
  }
}

// Refresh3b, publish record18, read int0 and text1; later text2/text3 statuses are ignored.
// Preserve partial outputs, late output pointers, raw cleanup return and shared nine-state descriptor lifetimes.
// R6GameService.dll @ 10045ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseCachedSelector3bRecord(void *dispatcher,
                                    void *valueOut,void *recordWordOut, void *thirdOut,void *fourthOut,void *fifthOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedPairReadersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    ebp
    xor    ebx,ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    push    0x3b
    mov    ecx,esi
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch75
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch79
  Branch75:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esi+0x8]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch76
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch79
  Branch76:
    mov    ecx,DWORD PTR [esp+0x3c]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch77
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch79
  Branch77:
    mov    edx,DWORD PTR [esp+0x44]
    push    0x1
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch78
    mov    DWORD PTR [esp+0x14],edi
    mov    ebx,0x5
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch79
  Branch78:
    mov    ecx,DWORD PTR [esp+0x48]
    push    0x2
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    mov    edx,DWORD PTR [esp+0x4c]
    push    0x3
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    mov    DWORD PTR [esp+0x14],edi
    mov    ebx,0x7
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch79:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  }
}

// Refresh3d, publish record18, copy item1, read int0 and bounded text1 with full capacity81.
// Preserve partial outputs, late output pointers, raw cleanup return and shared nine-state descriptor lifetimes.
// R6GameService.dll @ 10046490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector3dIndexedFieldAndBuffer(void *dispatcher,
                                    void *valueOut,void *recordWordOut, void *thirdOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedPairReadersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    ebp
    xor    ebx,ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    push    0x3d
    mov    ecx,esi
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch80
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch84
  Branch80:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esi+0x8]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch81
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch84
  Branch81:
    mov    ecx,DWORD PTR [esp+0x3c]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch82
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch84
  Branch82:
    mov    edx,DWORD PTR [esp+0x44]
    push    0x81
    push    0x1
    push    edx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    mov    DWORD PTR [esp+0x14],edi
    jne    Branch83
    mov    ebx,0x5
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch84
  Branch83:
    mov    ebx,0x7
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch84:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Refresh39, publish current record18, copy item1 and read ints0/1 through current output arguments.
// Preserve partial writes, direct/inline pointer-list cleanup and raw final cleanup upperEAX/AL0 or1.
// R6GameService.dll @ 10046640 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector39IndexedFields(void *dispatcher,
                                    void *valueOut,void *recordWordOut, void *thirdOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedPairReadersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    ebp
    xor    ebx,ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    push    0x39
    mov    ecx,esi
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch85
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch89
  Branch85:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esi+0x8]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch86
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch89
  Branch86:
    mov    ecx,DWORD PTR [esp+0x3c]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch87
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch89
  Branch87:
    mov    edx,DWORD PTR [esp+0x44]
    push    0x1
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    mov    DWORD PTR [esp+0x14],edi
    jne    Branch88
    mov    ebx,0x5
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch89
  Branch88:
    mov    ebx,0x7
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch89:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Refresh3e, publish current record18, copy item1 and read ints0/1 through current output arguments.
// Preserve partial writes, direct/inline pointer-list cleanup and raw final cleanup upperEAX/AL0 or1.
// R6GameService.dll @ 10046bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector3eIndexedFieldPair(void *dispatcher,
                                    void *valueOut,void *recordWordOut, void *thirdOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedPairReadersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    ebp
    xor    ebx,ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    push    0x3e
    mov    ecx,esi
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch90
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch94
  Branch90:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esi+0x8]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch91
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch94
  Branch91:
    mov    ecx,DWORD PTR [esp+0x3c]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch92
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch94
  Branch92:
    mov    edx,DWORD PTR [esp+0x44]
    push    0x1
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    mov    DWORD PTR [esp+0x14],edi
    jne    Branch93
    mov    ebx,0x5
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch94
  Branch93:
    mov    ebx,0x7
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch94:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Refresh41, publish current record18, copy item1/read int0, then inline-clear the descriptor and release its head.
// Keep constructor unarmed until complete, late outputs, rewritten second argument and raw cleanup EAX/AL0 or1.
// R6GameService.dll @ 10048260 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector41IndexedValue(void *dispatcher,
                                    void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector41ReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebx,0x3
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    push    0x41
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x0
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch95
    mov    DWORD PTR [esp+0x10],edi
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x1
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x8
  Branch95:
    mov    edx,DWORD PTR [esp+0x3c]
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x10]
    push    0x1
    mov    DWORD PTR [edx],ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch96
    mov    DWORD PTR [esp+0x10],edi
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x4
    jmp    Branch97
  Branch96:
    mov    eax,DWORD PTR [esp+0x38]
    push    0x0
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch98
    mov    ebx,0x5
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x6
  Branch97:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x8
  Branch98:
    mov    ebx,0x7
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x8
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 100679c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind13(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy the completed inherited descriptor at EBP-24 through native list cleanup.
// R6GameService.dll @ 100679c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind23(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 100679d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind33(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 100679d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind43(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 100679e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind52(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 100679e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind62(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 100679f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind72(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch99
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x30],eax
    jmp    Branch100
  Branch99:
    mov    DWORD PTR [ebp-0x30],0x0
  Branch100:
    mov    ecx,DWORD PTR [ebp-0x30]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 10067a17 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind82(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067a1f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch101
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch102
  Branch101:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch102:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact nine-state inherited descriptor map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067a46 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSharedPairReadersEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Fully destroy the completed inherited descriptor at EBP-24 through native list cleanup.
// R6GameService.dll @ 10067bf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 10067bf8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind3(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch103
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2c],eax
    jmp    Branch104
  Branch103:
    mov    DWORD PTR [ebp-0x2c],0x0
  Branch104:
    mov    ecx,DWORD PTR [ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 10067c27 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067c2f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch105
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch106
  Branch105:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch106:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 10067c56 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067c5e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch107
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch108
  Branch107:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch108:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-24 base at this construction/entered-list stage.
// R6GameService.dll @ 10067c85 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT argument EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067c8d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector41IndexedValueUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch109
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch110
  Branch109:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch110:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact nine-state inherited descriptor map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067cb4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector41ReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector41IndexedValueExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared-pair/selector41 descriptor unwind map or FuncInfo.
// R6GameService.dll data @ 100823a0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap3[9] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind13},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind23},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind33},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind43},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind52},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind62},
  {0x5, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind72},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind82},
  {0x7, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind9},
};

// Literal shared-pair/selector41 descriptor unwind map or FuncInfo.
// R6GameService.dll data @ 100823e8 : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo3 = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap3,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal shared-pair/selector41 descriptor unwind map or FuncInfo.
// R6GameService.dll data @ 1008270c : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector41IndexedValueUnwindMap[9] = {
  {-1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind2},
  {0x1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind3},
  {-1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind4},
  {0x3, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind5},
  {-1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind6},
  {0x5, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind7},
  {-1, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind8},
  {0x7, R6GameServiceAddresses::ParseSelector41IndexedValueUnwind9},
};

// Literal shared-pair/selector41 descriptor unwind map or FuncInfo.
// R6GameService.dll data @ 10082754 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector41IndexedValueExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::ParseSelector41IndexedValueUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh11, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 10045ca0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseCachedSelector11Record(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x11
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch111
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch114
  Branch111:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x11
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch112
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch114
  Branch112:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch113
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch114
  Branch113:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch115
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch114:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch115:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch116
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch116:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Refresh08, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 100469a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector08MarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x8
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch117
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch120
  Branch117:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x8
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch118
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch120
  Branch118:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch119
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch120
  Branch119:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch121
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch120:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch121:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch122
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch122:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Refresh1f, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 10046d70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector1fMarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x1f
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch123
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch126
  Branch123:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x1f
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch124
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch126
  Branch124:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch125
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch126
  Branch125:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch127
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch126:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch127:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch128
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch128:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Refresh1e, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, others int1; reload marker/value arguments after copies and retain raw cleanup EAX/AL.
// R6GameService.dll @ 10046f90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector1eMarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    ebp
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    edi
    push    0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x18],edi
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    push    0x0
    push    0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x54],0x1
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x48],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    push    0x1e
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch129
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch132
  Branch129:
    mov    eax,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x54]
    push    eax
    push    ecx
    push    0x1e
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch130
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch132
  Branch130:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ebx,0x1
    lea    edx,[esp+0x14]
    push    ebx
    mov    ecx,DWORD PTR [eax+0x8]
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch131
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch132
  Branch131:
    lea    ecx,[esp+0x2c]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch133
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
  Branch132:
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch135
  Branch133:
    mov    edx,DWORD PTR [esp+0x54]
    xor    eax,eax
    mov    cl,BYTE PTR [edx]
    cmp    cl,0x26
    lea    ecx,[esp+0x2c]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x4c],bl
    jne    Branch134
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch135
  Branch134:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,bl
  Branch135:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Refresh0f, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 100473e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector0fMarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0xf
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch136
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch139
  Branch136:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0xf
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch137
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch139
  Branch137:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch138
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch139
  Branch138:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch140
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch139:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch140:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch141
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch141:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Refresh21, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 10047600 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector21MarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x21
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch142
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch145
  Branch142:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x21
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch143
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch145
  Branch143:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch144
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch145
  Branch144:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch146
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch145:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch146:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch147
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch147:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Refresh29, publish current record18, read D1 marker/value and copy outer/nested item1.
// Marker26 selects int0, every other byte int1; retain cached marker pointer, late value output and raw cleanup EAX/AL.
// R6GameService.dll @ 10047a90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector29MarkerAndField(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedMarkerReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x34],ebp
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x29
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch148
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch151
  Branch148:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x29
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch149
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch151
  Branch149:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch150
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch151
  Branch150:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch152
    mov    DWORD PTR [esp+0x28],ebp
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
  Branch151:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch152:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    cmp    cl,0x26
    lea    ecx,[esp+0x28]
    setne    al
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],0x1
    jne    Branch153
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  Branch153:
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Reset shared outer descriptor EBP-3c base after interrupted initial construction.
// R6GameService.dll @ 10067ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy the shared completed outer descriptor at inherited EBP-3c.
// R6GameService.dll @ 10067ae8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind24(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared nested descriptor EBP-24 base after interrupted nested construction.
// R6GameService.dll @ 10067af0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind34(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy the shared completed nested descriptor at inherited EBP-24.
// R6GameService.dll @ 10067af8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind44(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested EBP-24 after entered pointer-list destruction on failed nested copy; do not retry its list.
// R6GameService.dll @ 10067b00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind53(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-3c after entered pointer-list destruction on failed int read; do not retry its list.
// R6GameService.dll @ 10067b08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind63(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-3c after entered pointer-list destruction on success; do not retry its list.
// R6GameService.dll @ 10067b10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind73(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the seven-state marker-reader lifetime map shared by all seven registered parents.
// R6GameService.dll @ 10067b18 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSharedMarkerReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo4
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared marker-reader unwind map or FuncInfo.
// R6GameService.dll data @ 100825f4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap4[7] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind14},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind24},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind34},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind44},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind53},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind63},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind73},
};

// Literal shared marker-reader unwind map or FuncInfo.
// R6GameService.dll data @ 1008262c : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo4 = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap4,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh24, publish current record18, read D1/copy item1 twice; marker26 selects int0/text1, others int1/text2.
// Cache marker/text index, load text output after int; preserve partial writes and distinct failed-text cleanup.
// R6GameService.dll @ 10047cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector24MarkerValueAndString(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut,void *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMarkerTextReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x24
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch154
    lea    ecx,[esp+0x28]
    jmp    Branch158
  Branch154:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x24
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch155
    lea    ecx,[esp+0x28]
    jmp    Branch158
  Branch155:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch156
    lea    ecx,[esp+0x28]
    jmp    Branch158
  Branch156:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch157
    lea    ecx,[esp+0x28]
    jmp    Branch158
  Branch157:
    mov    dl,BYTE PTR [edi]
    mov    ecx,DWORD PTR [esp+0x58]
    xor    eax,eax
    cmp    dl,0x26
    setne    al
    push    eax
    mov    esi,eax
    push    ecx
    lea    ecx,[esp+0x30]
    inc    esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    jne    Branch159
  Branch158:
    mov    BYTE PTR [esp+0x48],bl
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch159:
    mov    edx,DWORD PTR [esp+0x60]
    push    esi
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],bl
    jne    Branch160
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch160:
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Refresh28, publish current record18, read D1/copy item1 twice; marker26 selects int0/text1, others int1/text2.
// Cache marker/text index, load text output after int; preserve partial writes and distinct failed-text cleanup.
// R6GameService.dll @ 10047e90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector28MarkerValueAndString(void *dispatcher,void *markerOut,
                                    void *quotedOut,void *valueOut,void *recordWordOut,void *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMarkerTextReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x28
    mov    ecx,esi
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch161
    lea    ecx,[esp+0x28]
    jmp    Branch165
  Branch161:
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x50]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0x28
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch162
    lea    ecx,[esp+0x28]
    jmp    Branch165
  Branch162:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch163
    lea    ecx,[esp+0x28]
    jmp    Branch165
  Branch163:
    lea    edx,[esp+0x28]
    push    0x1
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch164
    lea    ecx,[esp+0x28]
    jmp    Branch165
  Branch164:
    mov    dl,BYTE PTR [edi]
    mov    ecx,DWORD PTR [esp+0x58]
    xor    eax,eax
    cmp    dl,0x26
    setne    al
    push    eax
    mov    esi,eax
    push    ecx
    lea    ecx,[esp+0x30]
    inc    esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x28]
    jne    Branch166
  Branch165:
    mov    BYTE PTR [esp+0x48],bl
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch166:
    mov    edx,DWORD PTR [esp+0x60]
    push    esi
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x48],bl
    jne    Branch167
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch167:
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x48],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Construct descriptor unarmed, refresh3f, publish current record18, copy item1 and read int0/bounded text1 capacity81.
// Keep partial outputs, late pointers, inline cleanup context rewrite and raw final cleanup upperEAX/AL0 or1.
// R6GameService.dll @ 10048070 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector3fValueAndText(void *dispatcher,void *valueOut,
                                    void *recordWordOut,void *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector3fReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    push    edi
    mov    esi,ecx
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    push    0x3f
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x0
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch168
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch168:
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x10]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esi+0x8]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch169
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch169:
    mov    ecx,DWORD PTR [esp+0x38]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch170
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch170:
    mov    edx,DWORD PTR [esp+0x40]
    push    0x81
    push    0x1
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch171
    mov    ebx,0x4
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch171:
    mov    ebx,0x6
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x7
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Fully destroy the completed shared marker/text outer descriptor at inherited EBP-3c.
// R6GameService.dll @ 10067b30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind15(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Fully destroy the shared marker/text nested descriptor at inherited EBP-24, then outer via the map.
// R6GameService.dll @ 10067b38 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind25(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared outer EBP-3c base after entered failed-text pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067b40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind35(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact inherited reader lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067b48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMarkerTextReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo5
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Fully destroy the completed selector3f descriptor at inherited EBP-24.
// R6GameService.dll @ 10067b60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited descriptor EBP-24 base after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067b68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067b70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067b78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor EBP-24 base after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067b80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT rewritten EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067b88 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch172
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x30],eax
    jmp    Branch173
  Branch172:
    mov    DWORD PTR [ebp-0x30],0x0
  Branch173:
    mov    ecx,DWORD PTR [ebp-0x30]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-24 base after entered pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067baf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reload CURRENT rewritten EBP+8, publish adjusted head-slot scratch or NULL, and always tail release59140.
// R6GameService.dll @ 10067bb7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector3fValueAndTextUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch174
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch175
  Branch174:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch175:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact inherited reader lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067bde : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector3fReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector3fValueAndTextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal marker/text or selector3f reader unwind map/FuncInfo.
// R6GameService.dll data @ 10082648 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap5[3] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind15},
  {0x0, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind25},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind35},
};

// Literal marker/text or selector3f reader unwind map/FuncInfo.
// R6GameService.dll data @ 10082660 : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo5 = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap5,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal marker/text or selector3f reader unwind map/FuncInfo.
// R6GameService.dll data @ 100826b0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector3fValueAndTextUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind2},
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind3},
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind4},
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind5},
  {0x4, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind6},
  {-1, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind7},
  {0x6, R6GameServiceAddresses::ParseSelector3fValueAndTextUnwind8},
};

// Literal marker/text or selector3f reader unwind map/FuncInfo.
// R6GameService.dll data @ 100826f0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector3fValueAndTextExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ParseSelector3fValueAndTextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh20, copy item1/read metadata int0, then iterate nested indices until copy AL is false, including zero entries.
// Per entry read text0/WORD1 and invoke current slot6c with live metadata, cached record18, text and full word scratch.
// Preserve once-zeroed word scratch, retained text, index wrap, partial callbacks and raw final cleanup EAX/AL.
// R6GameService.dll @ 10047170 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector20Entries(void *dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector20DispatcherEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    ebp,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    mov    DWORD PTR [esp+0x14],0x0
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x40],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x60],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x64],0x1
    mov    DWORD PTR [esp+0x48],ebp
    mov    DWORD PTR [esp+0x58],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x60],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x20
    mov    ecx,esi
    mov    BYTE PTR [esp+0x60],0x3
    mov    DWORD PTR [esp+0x10],0x0
    mov    edi,0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch176
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch182
  Branch176:
    mov    ebp,DWORD PTR [eax+0x18]
    lea    ecx,[esp+0x24]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch177
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch182
  Branch177:
    lea    edx,[esp+0x10]
    push    0x0
    push    edx
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch178
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch182
  Branch178:
    lea    eax,[esp+0x3c]
    push    0x1
    push    eax
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch180
  Branch179:
    lea    ecx,[esp+0x14]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x44]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch181
    lea    edx,[esp+0xc]
    push    0x1
    push    edx
    lea    ecx,[esp+0x44]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    je    Branch183
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    lea    edx,[esp+0x18]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x18]
    push    ebp
    push    edx
    call    DWORD PTR [eax+0x6c]
    inc    edi
    lea    eax,[esp+0x3c]
    push    edi
    push    eax
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch179
  Branch180:
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x5c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch181:
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x5c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::PTR_LAB
  Branch182:
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x5c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch183:
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x5c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x54]
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  }
}

// Reset selector20 outer descriptor EBP-3c base after interrupted initial construction.
// R6GameService.dll @ 10067a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed selector20 outer descriptor at inherited EBP-3c.
// R6GameService.dll @ 10067a58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset selector20 nested descriptor EBP-24 base after interrupted construction.
// R6GameService.dll @ 10067a60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed selector20 nested descriptor at inherited EBP-24, then outer via the map.
// R6GameService.dll @ 10067a68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset outer EBP-3c after entered normal-completion pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067a70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-24 after entered failed-text pointer-list destruction; continue outer cleanup without retry.
// R6GameService.dll @ 10067a78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-3c after entered failed-WORD pointer-list destruction; do not retry its list.
// R6GameService.dll @ 10067a80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector20EntriesUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact seven-state selector20 dispatcher lifetime map and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067a88 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector20DispatcherEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector20EntriesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector20 dispatcher unwind map or FuncInfo.
// R6GameService.dll data @ 100824ac : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector20EntriesUnwindMap[7] = {
  {-1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind1},
  {-1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind2},
  {0x1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind3},
  {0x1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind4},
  {0x1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind5},
  {-1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind6},
  {-1, R6GameServiceAddresses::DispatchSelector20EntriesUnwind7},
};

// Literal selector20 dispatcher unwind map or FuncInfo.
// R6GameService.dll data @ 100824e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector20EntriesExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::DispatchSelector20EntriesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Dispatch scalar or marker26 named rows; each raw28 row has text[33], WORD count+22 and value pointer+24.
// Preserve marker upper bytes, count truncation/wrap, ignored integer status, partial leaks and exact cleanup stages.
// R6GameService.dll @ 1004ae80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector47VariantPayload(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector47EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x78
    push    ebx
    push    ebp
    push    esi
    xor    ebp,ebp
    push    edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x20],ebp
    push    ebp
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x28],esi
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],edi
    mov    DWORD PTR [esp+0x44],ebx
    push    ebp
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x94],ebp
    mov    DWORD PTR [esp+0x58],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    ebx,0x5
    mov    DWORD PTR [esp+0x4c],0x3
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x4c],edi
    push    0x47
    mov    ecx,esi
    mov    BYTE PTR [esp+0x94],0x1
    mov    BYTE PTR [esp+0x14],0x27
    mov    DWORD PTR [esp+0x24],ebp
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebp
    je    Branch195
    lea    ecx,[esp+0x28]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch194
    lea    edx,[esp+0x20]
    push    ebp
    push    edx
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch194
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::ReadIndexedByte
    test    al,al
    je    Branch194
    lea    ecx,[esp+0x40]
    push    0x2
    push    ecx
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch194
    mov    al,BYTE PTR [esp+0x10]
    mov    DWORD PTR [esp+0x1c],ebp
    cmp    al,0x26
    lea    ecx,[esp+0x40]
    jne    Branch192
    call    R6GameServiceAddresses::CountClDataListEntries
    mov    edi,eax
    mov    DWORD PTR [esp+0x14],edi
    lea    edx,[edi+edi*4]
    shl    edx,0x3
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    test    edi,edi
    mov    DWORD PTR [esp+0x18],eax
    je    Branch189
    lea    esi,[eax+0x22]
  Branch184:
    push    0x0
    push    0x3
    lea    ecx,[esp+0x78]
    mov    DWORD PTR [esp+0x7c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x8c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    or    ebx,0x10
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x80]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x70],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x7c],edi
    push    0x0
    push    0x3
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x64],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x74],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    or    ebx,0x20
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x68]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x58],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x64],edi
    lea    eax,[esp+0x70]
    push    ebp
    push    eax
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x98],0x5
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch187
    push    0x21
    lea    ecx,[esi-0x22]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x7c]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    je    Branch187
    lea    edx,[esp+0x58]
    push    0x1
    push    edx
    lea    ecx,[esp+0x78]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch187
    lea    ecx,[esp+0x58]
    call    R6GameServiceAddresses::CountClDataListEntries
    mov    WORD PTR [esi],ax
    and    eax,0xffff
    shl    eax,0x2
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    xor    edi,edi
    mov    DWORD PTR [esi+0x2],eax
    cmp    WORD PTR [esi],di
    je    Branch186
  Branch185:
    mov    eax,DWORD PTR [esi+0x2]
    push    edi
    lea    ecx,[eax+edi*4]
    push    ecx
    lea    ecx,[esp+0x60]
    call    R6GameServiceAddresses::ReadIndexedInt32
    xor    edx,edx
    inc    edi
    mov    dx,WORD PTR [esi]
    cmp    edi,edx
    jne    Branch185
  Branch186:
    lea    ecx,[esp+0x58]
    mov    BYTE PTR [esp+0x90],0x4
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x70]
    mov    BYTE PTR [esp+0x90],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    eax,DWORD PTR [esp+0x14]
    inc    ebp
    add    esi,0x28
    cmp    ebp,eax
    jne    Branch184
    jmp    Branch188
  Branch187:
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    xor    eax,eax
    lea    ecx,[esp+0x58]
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x14],eax
    mov    BYTE PTR [esp+0x10],0x27
    mov    DWORD PTR [esp+0x1c],0x41
    mov    BYTE PTR [esp+0x90],0x4
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x70]
    mov    BYTE PTR [esp+0x90],0x1
    call    R6GameServiceAddresses::DestroyClDataList
  Branch188:
    mov    edi,DWORD PTR [esp+0x14]
    mov    esi,DWORD PTR [esp+0x24]
  Branch189:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    esi,DWORD PTR [esi+0x14]
    push    edi
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esi]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    DWORD PTR [edx+0xac]
    mov    ebx,DWORD PTR [esp+0x18]
    test    ebx,ebx
    je    Branch193
    test    edi,edi
    je    Branch191
    lea    esi,[ebx+0x24]
  Branch190:
    mov    edx,DWORD PTR [esi]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    esi,0x28
    dec    edi
    jne    Branch190
  Branch191:
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    jmp    Branch193
  Branch192:
    lea    eax,[esp+0x1c]
    push    ebp
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    mov    eax,DWORD PTR [esp+0x1c]
    mov    esi,DWORD PTR [esi+0x14]
    mov    ecx,DWORD PTR [esp+0x10]
    push    ebp
    mov    edx,DWORD PTR [esi]
    push    ebp
    push    eax
    mov    eax,DWORD PTR [esp+0x2c]
    push    ecx
    push    eax
    mov    ecx,esi
    call    DWORD PTR [edx+0xac]
  Branch193:
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x90],0x0
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x90],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
    jmp    Branch196
  Branch194:
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
  Branch195:
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x4c],edi
    mov    DWORD PTR [esp+0x40],esi
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x90],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],esi
    mov    DWORD PTR [esp+0x34],edi
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x90],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
  Branch196:
    mov    ecx,DWORD PTR [esp+0x88]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x84
    ret
  }
}

// Destroy completed outer descriptor EBP-6c; no construction-only base guard before completion.
// R6GameService.dll @ 10068010 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy completed nested descriptor EBP-54, then outer through the map predecessor.
// R6GameService.dll @ 10068018 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy completed row descriptor EBP-24, then nested/outer through state1.
// R6GameService.dll @ 10068020 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy completed row-values descriptor EBP-3c, then row/nested/outer through state4.
// R6GameService.dll @ 10068028 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset outer EBP-6c after entered normal-completion list destruction; native state6.
// R6GameService.dll @ 10068030 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-54 after entered early-failure list destruction, then outer full; native state2.
// R6GameService.dll @ 10068038 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-6c after entered early-failure list destruction; native state3.
// R6GameService.dll @ 10068040 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector47VariantPayloadUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact seven-state outer/nested/row lifetime map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10068048 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector47EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector47VariantPayloadExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector47 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 100829d8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector47VariantPayloadUnwindMap[7] = {
  {-1, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind2},
  {0x0, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind3},
  {-1, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind4},
  {0x1, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind5},
  {0x4, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind6},
  {-1, R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwind7},
};

// Literal selector47 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 10082a10 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector47VariantPayloadExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::DispatchSelector47VariantPayloadUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Dispatch label plus reversed integer pairs until extraction fails, then always emit label/0/0 after label success.
// First scratch is uninitialized, second zeroed once; ignore numeric/callback status and retain exact cleanup stages.
// R6GameService.dll @ 1004ac40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector6aTextAndPairs(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector6aEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    push    0x0
    lea    ecx,[esp+0x4c]
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x54],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x48],0x3
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0x48],ebp
    push    0x0
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x64],0x0
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],edi
    mov    DWORD PTR [esp+0x30],ebp
    push    0x6a
    mov    ecx,esi
    mov    BYTE PTR [esp+0x60],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch197
    mov    DWORD PTR [esp+0x24],edi
    mov    DWORD PTR [esp+0x30],ebp
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x5c],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0x48],ebp
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x5c],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch197:
    lea    ecx,[esp+0x3c]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch198
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x5c],al
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch199
  Branch198:
    lea    edx,[esp+0x14]
    push    0x0
    push    edx
    lea    ecx,[esp+0x44]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch200
    mov    DWORD PTR [esp+0x24],edi
    mov    DWORD PTR [esp+0x30],ebp
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x5c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::PTR_LAB
  Branch199:
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x5c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch200:
    lea    eax,[esp+0x24]
    push    0x1
    push    eax
    lea    ecx,[esp+0x44]
    mov    edi,0x2
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch202
  Branch201:
    lea    ecx,[esp+0xc]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ReadIndexedInt32
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [ecx]
    push    edx
    lea    edx,[esp+0x1c]
    push    edx
    call    DWORD PTR [eax+0xa4]
    mov    eax,edi
    lea    ecx,[esp+0x3c]
    push    eax
    lea    eax,[esp+0x28]
    push    eax
    inc    edi
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch201
  Branch202:
    mov    ecx,DWORD PTR [esi+0x14]
    push    0x0
    lea    eax,[esp+0x18]
    push    0x0
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0xa4]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],ebp
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x5c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x5c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x54]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  }
}

// Destroy completed outer descriptor EBP-24; no initial construction-only guard.
// R6GameService.dll @ 10067fd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy completed nested descriptor EBP-3c, then outer through state0.
// R6GameService.dll @ 10067fd8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested EBP-3c after entered cache-absence list destruction, then outer full; native state2.
// R6GameService.dll @ 10067fe0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-24 after entered cache-absence list destruction; native state3.
// R6GameService.dll @ 10067fe8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-3c after entered failed-label list destruction, then outer full; native state4.
// R6GameService.dll @ 10067ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-3c after entered normal-completion list destruction, then outer full; native state5.
// R6GameService.dll @ 10067ff8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector6aTextAndPairsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact six-state outer/nested lifetime map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10068000 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector6aEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector6aTextAndPairsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector6a descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 1008298c : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector6aTextAndPairsUnwindMap[6] = {
  {-1, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind2},
  {0x0, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind3},
  {-1, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind4},
  {0x0, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind5},
  {0x0, R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwind6},
};

// Literal selector6a descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 100829bc : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector6aTextAndPairsExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::DispatchSelector6aTextAndPairsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Dispatch label and exact binary payload; allocate/zero length+1 only for nonzero raw descriptor length.
// Keep separate descriptor/payload ownership, failed-copy/exception leaks, captured size and native cleanup stages.
// R6GameService.dll @ 1004aa10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector42TextAndBinary(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector42EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push    ebx
    push    ebp
    push    esi
    xor    esi,esi
    push    edi
    mov    ebp,ecx
    push    esi
    push    0x2
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x18],esi
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x5c],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    esi
    lea    ecx,[esp+0x4c]
    mov    DWORD PTR [esp+0x64],esi
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    edi,R6GameServiceAddresses::clDataBinPTR_FUN
    mov    DWORD PTR [esp+0x3c],edi
    push    esi
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x68],0x1
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    esi
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x42
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x64],0x2
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [ebp+0x8]
    cmp    eax,esi
    jne    Branch203
    lea    ecx,[esp+0x24]
    jmp    Branch204
  Branch203:
    lea    ecx,[esp+0x24]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    lea    ecx,[esp+0x24]
    je    Branch204
    lea    edx,[esp+0x14]
    push    esi
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x24]
    jne    Branch205
  Branch204:
    mov    BYTE PTR [esp+0x60],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x3c]
    call    R6GameServiceAddresses::DestroyClDataBin
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch205:
    lea    eax,[esp+0x3c]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    jne    Branch206
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x60],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x60],0xffffffff
    mov    DWORD PTR [esp+0x3c],edi
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch206:
    mov    ebx,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [esp+0x48]
    sub    ebx,eax
    je    Branch208
    lea    edi,[ebx+0x1]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    esi,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,esi
    push    0x1
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    push    ebx
    and    ecx,0x3
    push    esi
    rep    stos BYTE PTR es:[edi],al
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch207
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x60],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::DestroyClDataBin
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  Branch207:
    mov    edi,R6GameServiceAddresses::clDataBinPTR_FUN
  Branch208:
    mov    ebp,DWORD PTR [ebp+0x14]
    push    ebx
    lea    ecx,[esp+0x18]
    push    esi
    mov    eax,DWORD PTR [ebp+0x0]
    push    ecx
    mov    ecx,ebp
    call    DWORD PTR [eax+0xa0]
    test    esi,esi
    je    Branch209
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch209:
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x60],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x60],0xffffffff
    mov    DWORD PTR [esp+0x3c],edi
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x58]
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret
  }
}

// Reset binary descriptor EBP-28 during initial triplet construction; native state0.
// R6GameService.dll @ 10067fa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector42TextAndBinaryUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed binary descriptor EBP-28, conditionally release its current first word; native state1.
// R6GameService.dll @ 10067fa8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector42TextAndBinaryUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Fully destroy completed list EBP-40, then binary descriptor through state1; native state2.
// R6GameService.dll @ 10067fb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector42TextAndBinaryUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset list EBP-40 after entered failed exact-copy list destruction, then binary full; native state3.
// R6GameService.dll @ 10067fb8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector42TextAndBinaryUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact four-state binary/list lifetime map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10067fc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector42EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector42TextAndBinaryExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector42 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 10082950 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector42TextAndBinaryUnwindMap[4] = {
  {-1, R6GameServiceAddresses::DispatchSelector42TextAndBinaryUnwind1},
  {-1, R6GameServiceAddresses::DispatchSelector42TextAndBinaryUnwind2},
  {0x1, R6GameServiceAddresses::DispatchSelector42TextAndBinaryUnwind3},
  {0x1, R6GameServiceAddresses::DispatchSelector42TextAndBinaryUnwind4},
};

// Literal selector42 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 10082970 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector42TextAndBinaryExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::DispatchSelector42TextAndBinaryUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Deliver selector40 text entries with live integer/current callback and record18 captured before integer extraction.
// Ignore marker/list statuses, compare full WORD40, reuse once-zeroed text and preserve nine-state inline cleanup.
// R6GameService.dll @ 1004a6e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector40TextValues(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector40EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    push    ebp
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x14],edi
    push    edi
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    xor    eax,eax
    push    0x40
    mov    DWORD PTR [esp+0x20],eax
    mov    ecx,esi
    mov    DWORD PTR [esp+0x24],eax
    mov    DWORD PTR [esp+0x50],edi
    mov    DWORD PTR [esp+0x28],eax
    mov    DWORD PTR [esp+0x2c],eax
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,edi
    jne    Branch210
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebx,0x1
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x4c],0x2
    jmp    Branch212
  Branch210:
    mov    ecx,DWORD PTR [eax+0x8]
    lea    edx,[esp+0x12]
    push    edi
    push    edx
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x2c]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    WORD PTR [esp+0x12],0x40
    je    Branch211
    mov    DWORD PTR [esp+0x2c],ebp
    lea    edx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    mov    DWORD PTR [esp+0x18],edx
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x4c],0x4
    jmp    Branch212
  Branch211:
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x14]
    push    edi
    push    ecx
    mov    ebp,DWORD PTR [eax+0x18]
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch213
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x5
    lea    edx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    mov    DWORD PTR [esp+0x18],edx
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x4c],0x6
  Branch212:
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret
  Branch213:
    lea    eax,[esp+0x1c]
    push    0x1
    push    eax
    lea    ecx,[esp+0x34]
    mov    edi,0x2
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch215
  Branch214:
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [ecx]
    push    ebp
    push    eax
    call    DWORD PTR [edx+0x8c]
    mov    eax,edi
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    lea    ecx,[esp+0x34]
    inc    edi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch214
  Branch215:
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x7
    lea    edx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    mov    DWORD PTR [esp+0x18],edx
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret
  }
}

// Destroy completed descriptor EBP-24; native state0, initial construction unarmed.
// R6GameService.dll @ 10067ed0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor EBP-24 after entered cache-absence clear/head cleanup; native state1.
// R6GameService.dll @ 10067ed8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail current cleanup context EBP-38 plus4 orNULL to header release via scratch EBP-50; state2.
// R6GameService.dll @ 10067ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind3(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x38],0x0
    je    Branch216
    mov    eax,DWORD PTR [ebp-0x38]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x50],eax
    jmp    Branch217
  Branch216:
    mov    DWORD PTR [ebp-0x50],0x0
  Branch217:
    mov    ecx,DWORD PTR [ebp-0x50]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 after entered marker-mismatch clear/head cleanup; native state3.
// R6GameService.dll @ 10067f07 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail current cleanup context EBP-38 plus4 orNULL to header release via scratch EBP-58; state4.
// R6GameService.dll @ 10067f0f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x38],0x0
    je    Branch218
    mov    eax,DWORD PTR [ebp-0x38]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x58],eax
    jmp    Branch219
  Branch218:
    mov    DWORD PTR [ebp-0x58],0x0
  Branch219:
    mov    ecx,DWORD PTR [ebp-0x58]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 after entered integer-failure clear/head cleanup; native state5.
// R6GameService.dll @ 10067f36 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail current cleanup context EBP-38 plus4 orNULL to header release via scratch EBP-60; state6.
// R6GameService.dll @ 10067f3e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x38],0x0
    je    Branch220
    mov    eax,DWORD PTR [ebp-0x38]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch221
  Branch220:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch221:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset descriptor EBP-24 after entered normal-completion clear/head cleanup; native state7.
// R6GameService.dll @ 10067f65 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail current cleanup context EBP-38 plus4 orNULL to header release via scratch EBP-68; state8.
// R6GameService.dll @ 10067f6d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector40TextValuesUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x38],0x0
    je    Branch222
    mov    eax,DWORD PTR [ebp-0x38]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x68],eax
    jmp    Branch223
  Branch222:
    mov    DWORD PTR [ebp-0x68],0x0
  Branch223:
    mov    ecx,DWORD PTR [ebp-0x68]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact nine-state descriptor/entered-clear/header map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10067f94 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector40EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector40TextValuesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector40 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 100828ec : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector40TextValuesUnwindMap[9] = {
  {-1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind1},
  {-1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind2},
  {0x1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind3},
  {-1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind4},
  {0x3, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind5},
  {-1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind6},
  {0x5, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind7},
  {-1, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind8},
  {0x7, R6GameServiceAddresses::DispatchSelector40TextValuesUnwind9},
};

// Literal selector40 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 10082934 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector40TextValuesExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::DispatchSelector40TextValuesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Deliver selector97 entry text and BYTE-normalized flag as a full retained stack word; iterate until copy AL false.
// Ignore initial marker/list status, compare full WORD97, retain live stack inputs and distinct text/byte cleanup.
// R6GameService.dll @ 1004a340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector97StringFlagRecords(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector97EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x64
    push    ebx
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    mov    DWORD PTR [esp+0x1c],ebx
    push    0x3
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x38],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x80],ebx
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x50],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x44]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x97
    mov    ecx,esi
    mov    BYTE PTR [esp+0x7c],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    jne    Branch224
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x78],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch230
  Branch224:
    lea    ecx,[esp+0xe]
    push    ebx
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x1c]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    WORD PTR [esp+0xe],0x97
    je    Branch225
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x78],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch230
  Branch225:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x18]
    push    ebx
    push    eax
    mov    edx,DWORD PTR [ecx+0x18]
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x1c],edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch226
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x78],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch230
  Branch226:
    lea    ecx,[esp+0x34]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x24]
    mov    edi,0x2
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    al,bl
    je    Branch228
  Branch227:
    lea    edx,[esp+0x4c]
    push    ebx
    push    edx
    lea    ecx,[esp+0x3c]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch229
    lea    eax,[esp+0xd]
    push    0x1
    push    eax
    lea    ecx,[esp+0x3c]
    call    R6GameServiceAddresses::ReadIndexedByte
    test    al,al
    je    Branch231
    cmp    BYTE PTR [esp+0xd],bl
    setne    cl
    mov    BYTE PTR [esp+0x10],cl
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x50]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x24]
    push    eax
    call    DWORD PTR [edx+0x7c]
    mov    eax,edi
    lea    ecx,[esp+0x34]
    push    eax
    push    ecx
    lea    ecx,[esp+0x24]
    inc    edi
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    al,bl
    jne    Branch227
  Branch228:
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x78],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x78],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret
  Branch229:
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x78],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::PTR_LAB
  Branch230:
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x78],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret
  Branch231:
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x78],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x78],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x70]
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret
  }
}

// Destroy completed outer descriptor EBP-60; native state0, initial construction unarmed.
// R6GameService.dll @ 10067e90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector97StringFlagRecordsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy completed nested descriptor EBP-48, then outer state0; native state1.
// R6GameService.dll @ 10067e98 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector97StringFlagRecordsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset outer EBP-60 after entered normal-completion pointer-list destruction; native state4.
// R6GameService.dll @ 10067ea0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector97StringFlagRecordsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset nested EBP-48 after entered failed-text pointer-list destruction, then outer full; native state2.
// R6GameService.dll @ 10067ea8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector97StringFlagRecordsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-60 after entered failed-byte pointer-list destruction; native state3.
// R6GameService.dll @ 10067eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector97StringFlagRecordsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select the exact five-state outer/nested lifetime map and tail the Windows frame dispatcher.
// R6GameService.dll @ 10067eb8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector97EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector97StringFlagRecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector97 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 100828a8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector97StringFlagRecordsUnwindMap[5] = {
  {-1, R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwind2},
  {0x0, R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwind3},
  {-1, R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwind4},
  {-1, R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwind5},
};

// Literal selector97 descriptor unwind and FuncInfo words.
// R6GameService.dll data @ 100828d0 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector97StringFlagRecordsExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::DispatchSelector97StringFlagRecordsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Query size, zero optional size+1 payload, extract fields and deliver using the ORIGINAL size captured in EBX.
// Forward full initially-zero small DWORD, preserve raw return residues/free paths and lack of a wrapper EH guard.
// R6GameService.dll @ 1004a270 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector38BinaryRecord(void *dispatcherState)
{
  __asm {
    sub    esp,0x118
    push    ebx
    push    ebp
    push    esi
    lea    eax,[esp+0xc]
    xor    esi,esi
    push    eax
    mov    ebp,ecx
    mov    DWORD PTR [esp+0x14],esi
    call    R6GameServiceAddresses::TryGetType38IndexedBinaryLength
    test    al,al
    je    Branch235
    mov    ebx,DWORD PTR [esp+0xc]
    cmp    ebx,esi
    je    Branch232
    push    edi
    lea    edi,[ebx+0x1]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    esi,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    pop    edi
  Branch232:
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x1c]
    push    eax
    lea    edx,[esp+0xa4]
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    push    eax
    lea    ecx,[esp+0x24]
    push    esi
    lea    edx,[esp+0x2c]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::ExtractCachedBinaryRecordFields
    test    al,al
    je    Branch234
    mov    edx,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    edx
    lea    edx,[esp+0x20]
    mov    eax,DWORD PTR [ecx]
    push    edx
    lea    edx,[esp+0xa8]
    push    edx
    mov    edx,DWORD PTR [esp+0x20]
    push    ebx
    push    esi
    push    edx
    mov    edx,DWORD PTR [esp+0x30]
    push    edx
    call    DWORD PTR [eax+0x78]
    test    esi,esi
    je    Branch233
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch233:
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0x118
    ret
  Branch234:
    test    esi,esi
    je    Branch235
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch235:
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x118
    ret
  }
}

// Refresh selector38, clone list/bin, publish raw end-begin before cleanup and retain ten physical cleanup stages.
// R6GameService.dll @ 100438a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TryGetType38IndexedBinaryLength(void *owner,int *byteLengthOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector38QueryEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    0x0
    push    0x2
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x50],0x0
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x54],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],ebp
    push    0x38
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    esi,DWORD PTR [esi+0x8]
    test    esi,esi
    jne    Branch236
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],ebp
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x4c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x4c],0x5
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  Branch236:
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch237
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],ebp
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x4c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x4c],0x7
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  Branch237:
    lea    ecx,[esp+0x28]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    jne    Branch238
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x4c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBin
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  Branch238:
    mov    edx,DWORD PTR [esp+0x38]
    mov    eax,DWORD PTR [esp+0x34]
    sub    edx,eax
    mov    eax,DWORD PTR [esp+0x54]
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [eax],edx
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x4c],0x8
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x4c],0x9
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x44]
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x4
  }
}

// Publish numeric/record, copy caller-requested bytes without end check, then WORD/text outputs; retain partial writes.
// Preserve the unused second list lifetime, incoming argument cookie address and six-state descriptor cleanup.
// R6GameService.dll @ 10047820 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ExtractCachedBinaryRecordFields(
    void *owner,int *numericOut,uint *recordOut,void *bytesOut,int *lengthIn,
    char *textFirst,char *textSecond,ushort *smallOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector38ExtractEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x50
    push    esi
    mov    esi,ecx
    push    0x0
    push    0x2
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0xc],0x0
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x58],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x60],0x0
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataBinPTR_FUN
    push    0x0
    push    0x3
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x64],0x1
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x60],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x60],0x4
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [esp+0x5c],0x5
    test    eax,eax
    jne    Branch240
  Branch239:
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x5c],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x8]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::DestroyClDataBin
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x50]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x1c
  Branch240:
    lea    ecx,[esp+0x8]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch239
    mov    edx,DWORD PTR [esp+0x64]
    push    0x0
    push    edx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch239
    lea    eax,[esp+0x38]
    push    0x1
    push    eax
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    je    Branch239
    mov    ecx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [esp+0x68]
    mov    edx,DWORD PTR [ecx+0x18]
    mov    ecx,DWORD PTR [esp+0x70]
    mov    DWORD PTR [eax],edx
    mov    eax,DWORD PTR [ecx]
    test    eax,eax
    je    Branch241
    mov    dl,BYTE PTR [esp+0x64]
    mov    ecx,DWORD PTR [esp+0x44]
    mov    BYTE PTR [esp+0x64],dl
    lea    edx,[esp+0x64]
    push    edx
    mov    edx,DWORD PTR [esp+0x70]
    add    eax,ecx
    push    edx
    push    eax
    push    ecx
    call    R6GameServiceAddresses::CopyByteRange
  Branch241:
    mov    eax,DWORD PTR [esp+0x7c]
    push    0x2
    push    eax
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch242
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x5c],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch245
  Branch242:
    mov    ecx,DWORD PTR [esp+0x74]
    push    0x3
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch243
    mov    BYTE PTR [esp+0x5c],0x3
    lea    ecx,[esp+0x20]
    jmp    Branch244
  Branch243:
    mov    edx,DWORD PTR [esp+0x78]
    push    0x4
    push    edx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x5c],0x3
    jne    Branch246
  Branch244:
    call    R6GameServiceAddresses::DestroyClDataListAlias
  Branch245:
    lea    ecx,[esp+0x8]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x5c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBinAlias
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x50]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x1c
  Branch246:
    call    R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x8]
    mov    BYTE PTR [esp+0x5c],0x1
    call    R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x5c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBinAlias
    mov    ecx,DWORD PTR [esp+0x54]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x1c
  }
}

// Reset binary EBP-28 during empty-triplet construction; native query state0.
// R6GameService.dll @ 10067410 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed binary EBP-28; native query state1.
// R6GameService.dll @ 10067418 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Reset list EBP-40 during construction, then binary full; native query state2.
// R6GameService.dll @ 10067420 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed list EBP-40, then binary full; native query state3.
// R6GameService.dll @ 10067428 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered cache-absence list EBP-40, then binary full; native query state4.
// R6GameService.dll @ 10067430 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered cache-absence binary EBP-28 after conditional release; native query state5.
// R6GameService.dll @ 10067438 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered root-copy-failure list EBP-40, then binary full; native query state6.
// R6GameService.dll @ 10067440 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered root-copy-failure binary EBP-28 after conditional release; native query state7.
// R6GameService.dll @ 10067448 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered normal-completion list EBP-40, then binary full; native query state8.
// R6GameService.dll @ 10067450 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset entered normal-completion binary EBP-28 after conditional release; native query state9.
// R6GameService.dll @ 10067458 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryGetType38IndexedBinaryLengthUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset binary EBP-28 during empty-triplet construction; native extractor state0.
// R6GameService.dll @ 10067aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed binary EBP-28; native extractor state1.
// R6GameService.dll @ 10067aa8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Reset outer list EBP-58 during construction, then binary full; native extractor state2.
// R6GameService.dll @ 10067ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x58]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed outer list EBP-58, then binary full; native extractor state3.
// R6GameService.dll @ 10067ab8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x58]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset unused nested list EBP-40 during construction, then outer/binary full; native extractor state4.
// R6GameService.dll @ 10067ac0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Fully destroy completed unused nested list EBP-40, then outer/binary full; native extractor state5.
// R6GameService.dll @ 10067ac8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ExtractCachedBinaryRecordFieldsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select the ten-state query binary/list/entered-release lifetime map and tail the Windows dispatcher.
// R6GameService.dll @ 10067460 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector38QueryEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TryGetType38IndexedBinaryLengthExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the six-state extractor binary/two-list lifetime map and tail the Windows dispatcher.
// R6GameService.dll @ 10067ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector38ExtractEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector38 query/extractor unwind and FuncInfo words.
// R6GameService.dll data @ 10081ac4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry TryGetType38IndexedBinaryLengthUnwindMap[10] = {
  {-1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind1},
  {-1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind2},
  {0x1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind3},
  {0x1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind4},
  {0x1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind5},
  {-1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind6},
  {0x1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind7},
  {-1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind8},
  {0x1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind9},
  {-1, R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwind10},
};

// Literal selector38 query/extractor unwind and FuncInfo words.
// R6GameService.dll data @ 10081b14 : native storage identity retained.
const R6GameServiceNative::FuncInfo TryGetType38IndexedBinaryLengthExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::TryGetType38IndexedBinaryLengthUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal selector38 query/extractor unwind and FuncInfo words.
// R6GameService.dll data @ 100825a8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ExtractCachedBinaryRecordFieldsUnwindMap[6] = {
  {-1, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind1},
  {-1, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind2},
  {0x1, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind3},
  {0x1, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind4},
  {0x3, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind5},
  {0x3, R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwind6},
};

// Literal selector38 query/extractor unwind and FuncInfo words.
// R6GameService.dll data @ 100825d8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ExtractCachedBinaryRecordFieldsExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::ExtractCachedBinaryRecordFieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Parse selector29 and forward full marker DWORD, two scalars and record18 in parser order to current callback80.
// Marker upper24 bits retain incoming stack bytes; parser/callback upper EAX survives AL0/1. No local EH frame.
// R6GameService.dll @ 1004a5c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback80(void *owner)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector29MarkerAndField
    test    al,al
    je    Branch247
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x80]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch247:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector24 and forward full marker DWORD, two scalars, record18 and uninitialized16-byte text to callback84.
// Marker upper24 bits/text tails remain untouched; load current callback14 after parsing, retain upper EAX/AL0/1.
// R6GameService.dll @ 1004a620 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback84(void *owner)
{
  __asm {
    sub    esp,0x20
    lea    eax,[esp+0x10]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector24MarkerValueAndString
    test    al,al
    je    Branch248
    lea    eax,[esp+0x14]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x84]
    mov    al,0x1
    pop    esi
    add    esp,0x20
    ret
  Branch248:
    xor    al,al
    pop    esi
    add    esp,0x20
    ret
  }
}

// Parse selector28 and forward full marker DWORD, two scalars, record18 and uninitialized16-byte text to callback88.
// Marker upper24 bits/text tails remain untouched; load current callback14 after parsing, retain upper EAX/AL0/1.
// R6GameService.dll @ 1004a680 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback88(void *owner)
{
  __asm {
    sub    esp,0x20
    lea    eax,[esp+0x10]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector28MarkerValueAndString
    test    al,al
    je    Branch249
    lea    eax,[esp+0x14]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x88]
    mov    al,0x1
    pop    esi
    add    esp,0x20
    ret
  Branch249:
    xor    al,al
    pop    esi
    add    esp,0x20
    ret
  }
}

// Zero only129 bytes of132-byte text, parse selector3f and send numeric/record/text to current callback90.
// Retain three incoming tail bytes and parser/callback upper EAX with AL0/1; no local EH or callback NULL guard.
// R6GameService.dll @ 1004a8e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector3fValueAndText(void *owner)
{
  __asm {
    sub    esp,0x8c
    xor    eax,eax
    lea    edx,[esp+0x0]
    push    esi
    push    edi
    mov    esi,ecx
    mov    ecx,0x20
    lea    edi,[esp+0x10]
    rep    stos DWORD PTR es:[edi],eax
    stos    BYTE PTR es:[edi],al
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0xc]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector3fValueAndText
    test    al,al
    je    Branch250
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    DWORD PTR [eax+0x90]
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x8c
    ret
  Branch250:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x8c
    ret
  }
}

// Refresh2e; borrow nested lists, gate full WORD26/27 and deliver full marker/scalars/live record18 to callback54.
// Code26 caches virtual length, allocates length+1, copies the later live range and appends NUL at cached length.
// Code27 uses NULL payload/zero length; both free captured payload evenNULL after callback. No local EH/NULL guard.
// R6GameService.dll @ 10049ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector2eRecord(void *transport)
{
  __asm {
    sub    esp,0x18
    push    ebx
    push    esi
    push    edi
    push    0x2e
    mov    ebx,ecx
    xor    esi,esi
    xor    edi,edi
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [ebx+0x8]
    test    eax,eax
    jne    Branch251
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    add    esp,0x18
    ret
  Branch251:
    lea    ecx,[esp+0x1c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch252
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch252:
    mov    eax,DWORD PTR [ebx+0x8]
    lea    edx,[esp+0x20]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    jne    Branch253
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch253:
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esp+0x28]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    jne    Branch254
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch254:
    mov    eax,DWORD PTR [esp+0x1c]
    and    eax,0xffff
    sub    eax,0x26
    je    Branch257
    dec    eax
    je    Branch255
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    add    esp,0x18
    ret
  Branch255:
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edx,[esp+0x18]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch256
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch256:
    mov    ecx,DWORD PTR [esp+0xc]
    lea    eax,[esp+0x14]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch261
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch257:
    lea    ecx,[esp+0x14]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x20],0x0
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch258
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch258:
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::GetIndexedClDataBin
    test    al,al
    jne    Branch259
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x18
    ret
  Branch259:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0x14]
    mov    edi,eax
    lea    ecx,[edi+0x1]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x10]
    mov    esi,eax
    mov    eax,DWORD PTR [ecx+0x10]
    mov    ecx,DWORD PTR [ecx+0xc]
    cmp    eax,ecx
    je    Branch260
    sub    eax,ecx
    push    eax
    push    ecx
    push    esi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch260:
    mov    BYTE PTR [edi+esi*1],0x0
  Branch261:
    mov    eax,DWORD PTR [ebx+0x8]
    mov    ecx,DWORD PTR [ebx+0x14]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    edi
    push    esi
    push    eax
    mov    eax,DWORD PTR [esp+0x30]
    push    eax
    call    DWORD PTR [edx+0x54]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    add    esp,0x18
    ret
  }
}

// Refresh2d; borrow nested lists and gate full WORD26/27, then deliver full marker/two scalars/current record18.
// Code26 sets first scalar0 and reads second at0; code27 reads0/1. Current callback44/raw upperEAX/AL0/1; no local EH.
// R6GameService.dll @ 10049c40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector2D(int param_1)
{
  __asm {
    sub    esp,0x14
    push    esi
    push    0x2d
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch265
    lea    ecx,[esp+0x10]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    je    Branch265
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x14]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch265
    lea    ecx,[esp+0x4]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch265
    mov    eax,DWORD PTR [esp+0x10]
    and    eax,0xffff
    sub    eax,0x26
    je    Branch263
    dec    eax
    je    Branch262
    xor    al,al
    pop    esi
    add    esp,0x14
    ret
  Branch262:
    mov    ecx,DWORD PTR [esp+0x4]
    lea    edx,[esp+0xc]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch265
    lea    eax,[esp+0x8]
    push    0x1
    push    eax
    jmp    Branch264
  Branch263:
    lea    ecx,[esp+0x8]
    push    0x0
    mov    DWORD PTR [esp+0x10],0x0
    push    ecx
  Branch264:
    mov    ecx,DWORD PTR [esp+0xc]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch266
  Branch265:
    xor    al,al
    pop    esi
    add    esp,0x14
    ret
  Branch266:
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x44]
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret
  }
}

// Refresh45; borrow list1, bounded-copy text0 into untouched16-byte scratch and read WORD1 into untouched DWORD.
// Current callbacka8 receives text/full DWORD with retained upper16; raw helper false or callback upperEAX/AL1.
// R6GameService.dll @ 10049d20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeliverSelector45(int param_1)
{
  __asm {
    sub    esp,0x18
    push    esi
    push    0x45
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch267
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  Branch267:
    lea    ecx,[esp+0x4]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    jne    Branch268
    pop    esi
    add    esp,0x18
    ret
  Branch268:
    mov    ecx,DWORD PTR [esp+0x4]
    push    0x10
    lea    edx,[esp+0x10]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch269
    pop    esi
    add    esp,0x18
    ret
  Branch269:
    mov    ecx,DWORD PTR [esp+0x4]
    lea    eax,[esp+0x8]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch270
    pop    esi
    add    esp,0x18
    ret
  Branch270:
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    lea    eax,[esp+0x10]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0xa8]
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  }
}

// Parse selector11 and deliver full marker DWORD/two scalars/record18 in parser order to current callback38.
// Marker BYTE write retains incoming upper24; all scratch uninitialized, raw parser/callback upperEAX with AL0/1.
// R6GameService.dll @ 10049b00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback38(void *owner)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseCachedSelector11Record
    test    al,al
    je    Branch271
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x38]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch271:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Parse selector1b and forward marker DWORD/scalar/16-byte text/scalar/record18 to current callback3c.
// Scratch/text start uninitialized; marker upper24/text tails and raw parser/callback upperEAX with AL0/1 retained.
// R6GameService.dll @ 10049b50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback3c(void *owner)
{
  __asm {
    sub    esp,0x20
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x10]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector1bIndexedStringAndFields
    test    al,al
    je    Branch272
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x3c]
    mov    al,0x1
    pop    esi
    add    esp,0x20
    ret
  Branch272:
    xor    al,al
    pop    esi
    add    esp,0x20
    ret
  }
}

// Clear129 bytes of first132-byte text, then129 of second; leave each three-byte tail and16-byte field untouched.
// Parse3b and deliver scalar/record18/field/firstText/secondText to current callback40; preserve raw upperEAX/AL0/1.
// R6GameService.dll @ 10049bb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchParsedCallback40(void *owner)
{
  __asm {
    sub    esp,0x120
    xor    eax,eax
    lea    edx,[esp+0x8]
    push    esi
    push    edi
    mov    esi,ecx
    mov    ecx,0x20
    lea    edi,[esp+0xa4]
    rep    stos DWORD PTR es:[edi],eax
    stos    BYTE PTR es:[edi],al
    mov    ecx,0x20
    xor    eax,eax
    lea    edi,[esp+0x20]
    rep    stos DWORD PTR es:[edi],eax
    stos    BYTE PTR es:[edi],al
    lea    eax,[esp+0x20]
    lea    ecx,[esp+0xa4]
    push    eax
    push    ecx
    lea    eax,[esp+0x10]
    push    edx
    lea    ecx,[esp+0x18]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseCachedSelector3bRecord
    test    al,al
    je    Branch273
    lea    eax,[esp+0x20]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    lea    eax,[esp+0xa8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    call    DWORD PTR [edx+0x40]
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x120
    ret
  Branch273:
    pop    edi
    xor    al,al
    pop    esi
    add    esp,0x120
    ret
  }
}

// Parse selector3d into two raw scalar words and untouched1028-byte text, then invoke current callback48.
// Parser bounds text copy to129 bytes; wrapper does not initialize it. Retain parser/callback upperEAX with AL0/1.
// R6GameService.dll @ 10049e10 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 __fastcall DeliverSelector3D(void *owner)
{
  __asm {
    sub    esp,0x40c
    lea    eax,[esp+0x8]
    lea    edx,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector3dIndexedFieldAndBuffer
    test    al,al
    je    Branch274
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0xc]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0xc]
    push    edx
    call    DWORD PTR [eax+0x48]
    mov    al,0x1
    pop    esi
    add    esp,0x40c
    ret
  Branch274:
    xor    al,al
    pop    esi
    add    esp,0x40c
    ret
  }
}

// Parse selector0a and forward marker DWORD/scalar/16-byte text/scalar/record18 to current callback4c.
// Scratch/text start uninitialized; marker upper24/text tails and raw parser/callback upperEAX with AL0/1 retained.
// R6GameService.dll @ 10049db0 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 __fastcall DeliverSelector0A(void *owner)
{
  __asm {
    sub    esp,0x20
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x10]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector0aIndexedFieldsAndString
    test    al,al
    je    Branch275
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x20]
    push    eax
    call    DWORD PTR [edx+0x4c]
    mov    al,0x1
    pop    esi
    add    esp,0x20
    ret
  Branch275:
    xor    al,al
    pop    esi
    add    esp,0x20
    ret
  }
}

// Parse selector0e into five untouched words and forward all five in parser order to current callback50.
// Marker BYTE write keeps upper24; a parser-unwritten final word stays incoming. Raw upperEAX with AL0/1 retained.
// R6GameService.dll @ 10049e60 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 __fastcall DeliverSelector0E(void *owner)
{
  __asm {
    sub    esp,0x14
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x18]
    push    edx
    lea    ecx,[esp+0x20]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector0eMarkerAndFields
    test    al,al
    je    Branch276
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    eax
    mov    eax,DWORD PTR [esp+0x24]
    push    eax
    call    DWORD PTR [edx+0x50]
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret
  Branch276:
    xor    al,al
    pop    esi
    add    esp,0x14
    ret
  }
}

// Refresh1b/D1; cache marker pointer, publish record18 after outer copy, copy nested and select marker26 index.
// Uncapped text0/1 then integer1/2; cache index across calls and retain late output pointers/partial writes.
// Exact five-state cleanup: final integer false leaves outer table44; other normal paths leave64. Raw cleanup EAX/AL.
// R6GameService.dll @ 10046090 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector1bIndexedStringAndFields(void *dispatcher,char *markerOut,
    int *quotedOut,void *textOut,int *valueOut,uint *recordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMarkerTextVariantsEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    esi
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x1b
    mov    ecx,esi
    mov    BYTE PTR [esp+0x48],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch277
    lea    ecx,[esp+0x24]
    jmp    Branch281
  Branch277:
    mov    eax,DWORD PTR [esp+0x50]
    mov    edi,DWORD PTR [esp+0x4c]
    push    eax
    push    edi
    push    0x1b
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch278
    lea    ecx,[esp+0x24]
    jmp    Branch281
  Branch278:
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch279
    lea    ecx,[esp+0x24]
    jmp    Branch281
  Branch279:
    mov    eax,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x1
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x28]
    mov    DWORD PTR [edx],ecx
    push    eax
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch280
    lea    ecx,[esp+0x24]
    jmp    Branch281
  Branch280:
    mov    dl,BYTE PTR [edi]
    xor    ecx,ecx
    cmp    dl,0x26
    mov    edx,DWORD PTR [esp+0x54]
    setne    cl
    mov    esi,ecx
    lea    ecx,[esp+0x24]
    push    esi
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x24]
    jne    Branch282
  Branch281:
    mov    BYTE PTR [esp+0x44],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch282:
    mov    eax,DWORD PTR [esp+0x58]
    inc    esi
    push    esi
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x44],0x1
    jne    Branch283
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x44],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch283:
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x3c]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Refresh0a/D1; publish current record18 after outer copy, copy nested and cache index selected by marker26.
// Integer at index0/1 then uncapped text1/2, reloading output pointers at each read; preserve partial outputs/aliases.
// Exact shared five-state cleanup: final text false leaves outer table44; other normal paths leave64. Raw EAX/AL.
// R6GameService.dll @ 10046290 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector0aIndexedFieldsAndString(void *dispatcher,char *markerOut,
    int *quotedOut,void *textOut,int *valueOut,uint *recordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMarkerTextVariantsEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    esi
    push    edi
    mov    esi,ecx
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    0x0
    push    0x3
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x48],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],edi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    push    0xa
    mov    ecx,esi
    mov    BYTE PTR [esp+0x48],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch284
    lea    ecx,[esp+0x24]
    jmp    Branch288
  Branch284:
    mov    eax,DWORD PTR [esp+0x50]
    mov    edi,DWORD PTR [esp+0x4c]
    push    eax
    push    edi
    push    0xa
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    jne    Branch285
    lea    ecx,[esp+0x24]
    jmp    Branch288
  Branch285:
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch286
    lea    ecx,[esp+0x24]
    jmp    Branch288
  Branch286:
    mov    eax,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x1
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x28]
    mov    DWORD PTR [edx],ecx
    push    eax
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch287
    lea    ecx,[esp+0x24]
    jmp    Branch288
  Branch287:
    mov    dl,BYTE PTR [edi]
    xor    ecx,ecx
    cmp    dl,0x26
    mov    edx,DWORD PTR [esp+0x58]
    setne    cl
    mov    esi,ecx
    lea    ecx,[esp+0x24]
    push    esi
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0x24]
    jne    Branch289
  Branch288:
    mov    BYTE PTR [esp+0x44],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch289:
    mov    eax,DWORD PTR [esp+0x54]
    inc    esi
    push    esi
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x44],0x1
    jne    Branch290
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x44],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch290:
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x3c]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Refresh0e/publish record18 before D1. Marker27 writes integer1 through valueOut and leaves lastOut untouched.
// Other markers read integer0 into valueOut then1 into late lastOut; preserve cached marker pointer/partial writes.
// Reuse canonical four-state0c/0e cleanup map820cc, destroy nested then outer and retain cleanup upperEAX/AL0/1.
// R6GameService.dll @ 100467f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector0eMarkerAndFields(void *dispatcher,char *markerOut,
    int *quotedOut,int *valueOut,uint *recordOut,int *lastOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector0cReaderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    push    edi
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x48],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],edi
    push    0x0
    push    0x3
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],edi
    push    0xe
    mov    ecx,esi
    mov    BYTE PTR [esp+0x48],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch293
    mov    ecx,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [eax+0x18]
    mov    edi,DWORD PTR [esp+0x4c]
    push    edx
    mov    DWORD PTR [ecx],eax
    push    edi
    push    0xe
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    je    Branch293
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x24]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch293
    lea    edx,[esp+0xc]
    push    0x1
    push    edx
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch293
    cmp    BYTE PTR [edi],0x27
    jne    Branch291
    mov    eax,DWORD PTR [esp+0x54]
    push    0x1
    push    eax
    lea    ecx,[esp+0x14]
    jmp    Branch292
  Branch291:
    mov    ecx,DWORD PTR [esp+0x54]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    lea    ecx,[esp+0xc]
    je    Branch294
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x1
    push    edx
  Branch292:
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch295
  Branch293:
    lea    ecx,[esp+0xc]
  Branch294:
    mov    BYTE PTR [esp+0x44],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  Branch295:
    lea    ecx,[esp+0xc]
    mov    BYTE PTR [esp+0x44],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x44],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x3c]
    pop    edi
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x14
  }
}

// Reset outer EBP-3c base after initial construction failure.
// R6GameService.dll @ 10067980 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind16(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed outer EBP-3c list through native full-list tail.
// R6GameService.dll @ 10067988 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind26(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset nested EBP-24 base after nested construction failure.
// R6GameService.dll @ 10067990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind36(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed nested EBP-24 list, then continue predecessor outer cleanup.
// R6GameService.dll @ 10067998 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind45(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset outer EBP-3c base after entered final pointer-list destruction; do not retry list cleanup.
// R6GameService.dll @ 100679a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind54(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select literal shared1b/0a five-state FuncInfo821e8/map821c0 and tail existing runtime dispatcher.
// R6GameService.dll @ 100679a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMarkerTextVariantsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo6
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared1b/0a unwind predecessor/action words and FuncInfo.
// R6GameService.dll data @ 100821c0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap6[5] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind16},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind26},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind36},
  {0x1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind45},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind54},
};

// Literal shared1b/0a FuncInfo: five states, no catches/try blocks.
// R6GameService.dll data @ 100821e8 : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo6 = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap6,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Zero cached shortOut WORD, read type/copy list ignoring statuses; type35 reads integer0 to third output,1 to first.
// Copy nested item2/read WORD0 ignoring statuses; retain cached short pointer, late integer pointers/partial writes.
// Exact eight-state cleanup/late cache check: missing cache leaves outer44, other normal paths64. Cleanup upperEAX/AL.
// R6GameService.dll @ 10043440 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TryReadType35DescriptorFields(void *dispatcherState,int *firstIntegerOut,
    undefined2 *shortOut,int *secondIntegerOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectType35DescriptorEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push    ebx
    xor    eax,eax
    push    ebp
    mov    ebx,0x3
    push    esi
    mov    DWORD PTR [esp+0xc],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    mov    BYTE PTR [esp+0x4c],bl
    mov    ebx,DWORD PTR [esp+0x58]
    lea    eax,[esp+0x10]
    push    0x0
    mov    WORD PTR [ebx],0x0
    mov    ecx,DWORD PTR [esi+0x8]
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x2c]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch296
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch298
  Branch296:
    cmp    WORD PTR [esp+0x10],0x35
    je    Branch297
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch298
  Branch297:
    mov    ecx,DWORD PTR [esp+0x5c]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::ReadIndexedInt32
    mov    edx,DWORD PTR [esp+0x54]
    push    0x1
    push    edx
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::ReadIndexedInt32
    lea    eax,[esp+0x14]
    push    0x2
    push    eax
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    push    0x0
    push    ebx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    al,0x1
  Branch298:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Read type/copy list ignoring statuses; type36 reads WORD0 into initially-zero DWORD and returns it in AX.
// Initial cache payload dereference precedes state1; preserve cleanup upper16 and inline clear/current inherited head.
// Eight-state map distinguishes missing/type mismatch/success; normal descriptor remains44, no new NULL/status guard.
// R6GameService.dll @ 10043620 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReadType36DescriptorShort(void *dispatcherState)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectType36DescriptorEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    ebx
    mov    ebx,0x3
    push    esi
    mov    DWORD PTR [esp+0xc],0x0
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x3c],0x0
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],edi
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0xe]
    push    0x0
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x40],0x1
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch299
    mov    DWORD PTR [esp+0x18],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],0x2
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x38],bl
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x38],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    ax,ax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch299:
    cmp    WORD PTR [esp+0xe],0x36
    je    Branch300
    mov    DWORD PTR [esp+0x18],edi
    mov    ebx,0x4
    lea    edx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x38],0x5
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x38],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    ax,ax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch300:
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    esi,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x18],edi
    mov    ebx,0x6
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x38],0x7
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x38],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x30]
    mov    ax,si
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  }
}

// Copy binary item10 from STACK source into temporary descriptor; AL false returns0, true returns raw end-begin.
// Conditionally free current begin on either path; exact five-state cookie/bin/entered-free cleanup. ECX unused; RET4.
// R6GameService.dll @ 100437c0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall CopyIndexedClDataBinaryAndGetLength(void *source)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectBinaryLengthEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    esi
    mov    esi,0x2
    mov    DWORD PTR [esp+0x8],0x0
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x18]
    push    eax
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::InitializePointerTriplet
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataBinPTR_FUN
    lea    ecx,[esp+0xc]
    push    0xa
    push    ecx
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esp+0x38],esi
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataBinPTR_FUN
    jne    Branch301
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    xor    eax,eax
    pop    esi
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x4
  Branch301:
    mov    esi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x18]
    sub    esi,eax
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x28]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x4
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100672d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed inherited list at its exact EBP-relative address, then continue predecessor cleanup.
// R6GameService.dll @ 100672d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100672e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed inherited list at its exact EBP-relative address, then continue predecessor cleanup.
// R6GameService.dll @ 100672e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100672f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100672f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 10067300 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 10067308 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadType35DescriptorFieldsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100673d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyIndexedClDataBinaryAndGetLengthUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Visit inherited cookie EBP-2d via genuine no-op; continue predecessor binary-base reset.
// R6GameService.dll @ 100673d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyIndexedClDataBinaryAndGetLengthUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy completed inherited binary EBP-28 through full native alias; do not replace with raw free.
// R6GameService.dll @ 100673e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyIndexedClDataBinaryAndGetLengthUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100673e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyIndexedClDataBinaryAndGetLengthUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 100673f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CopyIndexedClDataBinaryAndGetLengthUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 10067320 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed inherited list at its exact EBP-relative address, then continue predecessor cleanup.
// R6GameService.dll @ 10067328 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 10067330 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context-28 plus4, preserving NULL forwarding and native scratch stores.
// R6GameService.dll @ 10067338 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch302
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch303
  Branch302:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch303:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 1006735f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context-28 plus4, preserving NULL forwarding and native scratch stores.
// R6GameService.dll @ 10067367 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch304
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch305
  Branch304:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch305:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset exact inherited descriptor base after construction or entered cleanup; do not retry owned cleanup.
// R6GameService.dll @ 1006738e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context-28 plus4, preserving NULL forwarding and native scratch stores.
// R6GameService.dll @ 10067396 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadType36DescriptorShortUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch306
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x4c],eax
    jmp    Branch307
  Branch306:
    mov    DWORD PTR [ebp-0x4c],0x0
  Branch307:
    mov    ecx,DWORD PTR [ebp-0x4c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact descriptor-helper FuncInfo/unwind map and tail existing runtime dispatcher.
// R6GameService.dll @ 10067310 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectType35DescriptorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TryReadType35DescriptorFieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact descriptor-helper FuncInfo/unwind map and tail existing runtime dispatcher.
// R6GameService.dll @ 100673bd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectType36DescriptorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReadType36DescriptorShortExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact descriptor-helper FuncInfo/unwind map and tail existing runtime dispatcher.
// R6GameService.dll @ 100673f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectBinaryLengthEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 100819c8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry TryReadType35DescriptorFieldsUnwindMap[8] = {
  {-1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind1},
  {-1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind2},
  {0x1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind3},
  {0x1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind4},
  {0x1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind5},
  {-1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind6},
  {0x1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind7},
  {0x1, R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwind8},
};

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 10081a08 : native storage identity retained.
const R6GameServiceNative::FuncInfo TryReadType35DescriptorFieldsExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::TryReadType35DescriptorFieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 10081a24 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReadType36DescriptorShortUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ReadType36DescriptorShortUnwind1},
  {-1, R6GameServiceAddresses::ReadType36DescriptorShortUnwind2},
  {-1, R6GameServiceAddresses::ReadType36DescriptorShortUnwind3},
  {0x2, R6GameServiceAddresses::ReadType36DescriptorShortUnwind4},
  {-1, R6GameServiceAddresses::ReadType36DescriptorShortUnwind5},
  {0x4, R6GameServiceAddresses::ReadType36DescriptorShortUnwind6},
  {-1, R6GameServiceAddresses::ReadType36DescriptorShortUnwind7},
  {0x6, R6GameServiceAddresses::ReadType36DescriptorShortUnwind8},
};

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 10081a64 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReadType36DescriptorShortExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ReadType36DescriptorShortUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 10081a80 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CopyIndexedClDataBinaryAndGetLengthUnwindMap[5] = {
  {-1, R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwind1},
  {0x0, R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwind2},
  {-1, R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwind3},
  {-1, R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwind4},
  {-1, R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwind5},
};

// Literal native descriptor-helper unwind/FuncInfo words.
// R6GameService.dll data @ 10081aa8 : native storage identity retained.
const R6GameServiceNative::FuncInfo CopyIndexedClDataBinaryAndGetLengthExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLengthUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh36/read marker/copy list ignoring statuses; full WORD36 means processed AL1 even if extraction/filter fails.
// Cache binary size/payload in EBX/EBP; zero size+1 only for nonzero size, choose basic1c/extended18 by helper AX.
// Forward full scalar DWORDs/untouched text, current callback14; free captured payload normally, never via list EH map.
// R6GameService.dll @ 100485b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector36Record(void *dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector36EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x2c0
    push    ebx
    push    ebp
    xor    ebp,ebp
    push    esi
    mov    DWORD PTR [esp+0x44],ebp
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push    ebp
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x2dc],ebp
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],edi
    push    0x36
    mov    ecx,esi
    mov    DWORD PTR [esp+0x2dc],0x1
    mov    DWORD PTR [esp+0x14],ebp
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x3e]
    push    ebp
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x14]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    DWORD PTR [esi+0x8],ebp
    jne    Branch308
    mov    DWORD PTR [esp+0x14],edi
    mov    ebx,0x2
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x2d8],ebx
    mov    DWORD PTR [esp+0x4c],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x2d8],0x3
    jmp    Branch309
  Branch308:
    cmp    WORD PTR [esp+0x3e],0x36
    je    Branch310
    mov    DWORD PTR [esp+0x14],edi
    mov    ebx,0x4
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0x2d8],ebx
    mov    DWORD PTR [esp+0x4c],edx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x2d8],0x5
  Branch309:
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x2d8],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    xor    al,al
    jmp    Branch315
  Branch310:
    lea    eax,[esp+0x14]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLength
    mov    ebx,eax
    cmp    ebx,ebp
    je    Branch311
    lea    edi,[ebx+0x1]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    ebp,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,ebp
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
  Branch311:
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadType36DescriptorShort
    test    ax,ax
    jne    Branch312
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x5c]
    push    eax
    lea    edx,[esp+0x64]
    push    ecx
    push    edx
    push    ebx
    lea    eax,[esp+0xf0]
    push    ebp
    lea    ecx,[esp+0x158]
    push    eax
    lea    edx,[esp+0x7c]
    push    ecx
    lea    eax,[esp+0x60]
    push    edx
    lea    ecx,[esp+0x60]
    push    eax
    lea    edx,[esp+0x5c]
    push    ecx
    lea    eax,[esp+0x54]
    push    edx
    lea    ecx,[esp+0x5c]
    push    eax
    lea    edx,[esp+0xa4]
    push    ecx
    lea    eax,[esp+0x68]
    push    edx
    lea    ecx,[esp+0x4c]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::SubmitBasicServiceRequest
    test    al,al
    je    Branch313
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    mov    eax,DWORD PTR [esp+0x68]
    push    eax
    push    ebx
    lea    eax,[esp+0xf0]
    push    ebp
    push    eax
    lea    eax,[esp+0x15c]
    push    eax
    lea    eax,[esp+0x80]
    push    eax
    mov    eax,DWORD PTR [esp+0x64]
    push    eax
    mov    eax,DWORD PTR [esp+0x64]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    mov    eax,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    lea    eax,[esp+0xa8]
    push    eax
    mov    eax,DWORD PTR [esp+0x6c]
    push    eax
    call    DWORD PTR [edx+0x1c]
    jmp    Branch313
  Branch312:
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0x24c]
    push    ecx
    lea    eax,[esp+0x1cc]
    push    edx
    lea    ecx,[esp+0x5c]
    push    eax
    lea    edx,[esp+0x5c]
    push    ecx
    lea    eax,[esp+0x68]
    push    edx
    lea    ecx,[esp+0x5c]
    push    eax
    push    ecx
    push    ebx
    lea    edx,[esp+0xb8]
    push    ebp
    lea    eax,[esp+0xe0]
    push    edx
    lea    ecx,[esp+0x108]
    push    eax
    lea    edx,[esp+0x170]
    push    ecx
    lea    eax,[esp+0x94]
    push    edx
    lea    ecx,[esp+0x78]
    push    eax
    lea    edx,[esp+0x78]
    push    ecx
    lea    eax,[esp+0x74]
    push    edx
    lea    ecx,[esp+0x6c]
    push    eax
    lea    edx,[esp+0x74]
    push    ecx
    lea    eax,[esp+0xbc]
    push    edx
    lea    ecx,[esp+0x80]
    push    eax
    lea    edx,[esp+0x64]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::SubmitExtendedServiceRequest
    test    al,al
    je    Branch313
    lea    eax,[esp+0xe0]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::PassesOptionalServiceTreeNameFilter
    test    al,al
    je    Branch313
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    lea    eax,[esp+0x250]
    push    eax
    lea    eax,[esp+0x1d0]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    mov    eax,DWORD PTR [esp+0x6c]
    push    eax
    mov    eax,DWORD PTR [esp+0x60]
    push    eax
    push    ebx
    lea    eax,[esp+0xb8]
    push    ebp
    push    eax
    lea    eax,[esp+0xe4]
    push    eax
    lea    eax,[esp+0x10c]
    push    eax
    lea    eax,[esp+0x174]
    push    eax
    lea    eax,[esp+0x98]
    push    eax
    mov    eax,DWORD PTR [esp+0x7c]
    push    eax
    mov    eax,DWORD PTR [esp+0x7c]
    push    eax
    mov    eax,DWORD PTR [esp+0x78]
    push    eax
    mov    eax,DWORD PTR [esp+0x70]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x78]
    push    eax
    lea    eax,[esp+0xc0]
    push    eax
    mov    eax,DWORD PTR [esp+0x84]
    push    eax
    call    DWORD PTR [edx+0x18]
  Branch313:
    test    ebp,ebp
    je    Branch314
    push    ebp
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch314:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x6
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x2d8],ebx
    mov    DWORD PTR [esp+0x4c],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x2d8],0x7
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x2d8],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
  Branch315:
    mov    ecx,DWORD PTR [esp+0x2d0]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2cc
    ret
  }
}

// Reset inherited descriptor EBP-2c8 base after construction or entered inline cleanup; do not retry list cleanup.
// R6GameService.dll @ 10067cc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x2c8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed inherited descriptor EBP-2c8 through native full-list tail; raw payload is not owned here.
// R6GameService.dll @ 10067ccb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c8]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited descriptor EBP-2c8 base after construction or entered inline cleanup; do not retry list cleanup.
// R6GameService.dll @ 10067cd6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2c8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context EBP-290 plus4, retaining NULL forwarding and exact scratch stores.
// R6GameService.dll @ 10067ce1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x290],0x0
    je    Branch316
    mov    eax,DWORD PTR [ebp-0x290]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2f4],eax
    jmp    Branch317
  Branch316:
    mov    DWORD PTR [ebp-0x2f4],0x0
  Branch317:
    mov    ecx,DWORD PTR [ebp-0x2f4]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-2c8 base after construction or entered inline cleanup; do not retry list cleanup.
// R6GameService.dll @ 10067d17 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x2c8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context EBP-290 plus4, retaining NULL forwarding and exact scratch stores.
// R6GameService.dll @ 10067d22 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x290],0x0
    je    Branch318
    mov    eax,DWORD PTR [ebp-0x290]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2fc],eax
    jmp    Branch319
  Branch318:
    mov    DWORD PTR [ebp-0x2fc],0x0
  Branch319:
    mov    ecx,DWORD PTR [ebp-0x2fc]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset inherited descriptor EBP-2c8 base after construction or entered inline cleanup; do not retry list cleanup.
// R6GameService.dll @ 10067d58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x2c8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head via CURRENT inherited context EBP-290 plus4, retaining NULL forwarding and exact scratch stores.
// R6GameService.dll @ 10067d63 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector36RecordUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x290],0x0
    je    Branch320
    mov    eax,DWORD PTR [ebp-0x290]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x304],eax
    jmp    Branch321
  Branch320:
    mov    DWORD PTR [ebp-0x304],0x0
  Branch321:
    mov    ecx,DWORD PTR [ebp-0x304]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select literal eight-state selector36 FuncInfo827b0/map82770 and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067d99 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector36EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector36RecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector36 list unwind/FuncInfo words; no raw payload cleanup entry.
// R6GameService.dll data @ 10082770 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector36RecordUnwindMap[8] = {
  {-1, R6GameServiceAddresses::DispatchSelector36RecordUnwind1},
  {-1, R6GameServiceAddresses::DispatchSelector36RecordUnwind2},
  {-1, R6GameServiceAddresses::DispatchSelector36RecordUnwind3},
  {0x2, R6GameServiceAddresses::DispatchSelector36RecordUnwind4},
  {-1, R6GameServiceAddresses::DispatchSelector36RecordUnwind5},
  {0x4, R6GameServiceAddresses::DispatchSelector36RecordUnwind6},
  {-1, R6GameServiceAddresses::DispatchSelector36RecordUnwind7},
  {0x6, R6GameServiceAddresses::DispatchSelector36RecordUnwind8},
};

// Literal selector36 list unwind/FuncInfo words; no raw payload cleanup entry.
// R6GameService.dll data @ 100827b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector36RecordExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::DispatchSelector36RecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Read fields0..19 in order, skipping exact binary10 only when incoming size0; each destination/count is loaded late.
// WORD0/6, bounded text1/7/8/9 at33/16/132/99, numeric2..5/11..15, then uncapped text16..19.
// Preserve partial outputs/raw failure EAX; only final AL is normalized. No local EH/rollback. STACK source; RET58.
// R6GameService.dll @ 10043ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall TryCopyTwentyIndexedClDataFields(void *parserContext,undefined2 *field0Out,
    char *field1Out,int *field2Out,int *field3Out,int *field4Out,int *field5Out,undefined2 *field6Out,char *field7Out,
    char *field8Out,char *field9Out,int field16Out,int field17Out,void *field10Out,size_t field10ByteCount,
    int *field12Out,int *field13Out,int *field14Out,int *field15Out,int field18Out,int field19Out,int *field11Out)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    push    0x0
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch322
    pop    esi
    ret    0x58
  Branch322:
    mov    ecx,DWORD PTR [esp+0x10]
    push    0x21
    push    0x1
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch323
    pop    esi
    ret    0x58
  Branch323:
    mov    edx,DWORD PTR [esp+0x14]
    push    0x2
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch324
    pop    esi
    ret    0x58
  Branch324:
    mov    eax,DWORD PTR [esp+0x18]
    push    0x3
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch325
    pop    esi
    ret    0x58
  Branch325:
    mov    ecx,DWORD PTR [esp+0x1c]
    push    0x4
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch326
    pop    esi
    ret    0x58
  Branch326:
    mov    edx,DWORD PTR [esp+0x20]
    push    0x5
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch327
    pop    esi
    ret    0x58
  Branch327:
    mov    eax,DWORD PTR [esp+0x24]
    push    0x6
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch328
    pop    esi
    ret    0x58
  Branch328:
    mov    ecx,DWORD PTR [esp+0x28]
    push    0x10
    push    0x7
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch329
    pop    esi
    ret    0x58
  Branch329:
    mov    edx,DWORD PTR [esp+0x2c]
    push    0x84
    push    0x8
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch330
    pop    esi
    ret    0x58
  Branch330:
    mov    eax,DWORD PTR [esp+0x30]
    push    0x63
    push    0x9
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch331
    pop    esi
    ret    0x58
  Branch331:
    mov    eax,DWORD PTR [esp+0x40]
    test    eax,eax
    je    Branch332
    mov    ecx,DWORD PTR [esp+0x3c]
    push    0xa
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch332
    pop    esi
    ret    0x58
  Branch332:
    mov    edx,DWORD PTR [esp+0x5c]
    push    0xb
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch333
    pop    esi
    ret    0x58
  Branch333:
    mov    eax,DWORD PTR [esp+0x44]
    push    0xc
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch334
    pop    esi
    ret    0x58
  Branch334:
    mov    ecx,DWORD PTR [esp+0x48]
    push    0xd
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch335
    pop    esi
    ret    0x58
  Branch335:
    mov    edx,DWORD PTR [esp+0x4c]
    push    0xe
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch336
    pop    esi
    ret    0x58
  Branch336:
    mov    eax,DWORD PTR [esp+0x50]
    push    0xf
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch337
    pop    esi
    ret    0x58
  Branch337:
    mov    ecx,DWORD PTR [esp+0x34]
    push    0x10
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch338
    pop    esi
    ret    0x58
  Branch338:
    mov    edx,DWORD PTR [esp+0x38]
    push    0x11
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch339
    pop    esi
    ret    0x58
  Branch339:
    mov    eax,DWORD PTR [esp+0x54]
    push    0x12
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch340
    pop    esi
    ret    0x58
  Branch340:
    mov    ecx,DWORD PTR [esp+0x58]
    push    0x13
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    setne    al
    pop    esi
    ret    0x58
  }
}

// Read fields0..13 in order; WORD0/6, bounded text1/7/8/9 at33/16/132/99, numeric2..5/11..13.
// Skip exact binary10 only on size0, load pointers/count late and keep partial outputs/raw failure EAX.
// Normalize only final AL; no local EH/rollback. Source is a STACK argument, ECX unused; RET40.
// R6GameService.dll @ 10043c90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall TryCopyFourteenIndexedClDataFields(void *parserContext,undefined2 *field0Out,
    char *field1Out,int *field2Out,int *field3Out,int *field4Out,int *field5Out,undefined2 *field6Out,char *field7Out,
    char *field8Out,char *field9Out,void *field10Out,size_t field10ByteCount,int *field12Out,int *field13Out,
    int *field11Out)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    push    0x0
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch341
    pop    esi
    ret    0x40
  Branch341:
    mov    ecx,DWORD PTR [esp+0x10]
    push    0x21
    push    0x1
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch342
    pop    esi
    ret    0x40
  Branch342:
    mov    edx,DWORD PTR [esp+0x14]
    push    0x2
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch343
    pop    esi
    ret    0x40
  Branch343:
    mov    eax,DWORD PTR [esp+0x18]
    push    0x3
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch344
    pop    esi
    ret    0x40
  Branch344:
    mov    ecx,DWORD PTR [esp+0x1c]
    push    0x4
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch345
    pop    esi
    ret    0x40
  Branch345:
    mov    edx,DWORD PTR [esp+0x20]
    push    0x5
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch346
    pop    esi
    ret    0x40
  Branch346:
    mov    eax,DWORD PTR [esp+0x24]
    push    0x6
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch347
    pop    esi
    ret    0x40
  Branch347:
    mov    ecx,DWORD PTR [esp+0x28]
    push    0x10
    push    0x7
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch348
    pop    esi
    ret    0x40
  Branch348:
    mov    edx,DWORD PTR [esp+0x2c]
    push    0x84
    push    0x8
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch349
    pop    esi
    ret    0x40
  Branch349:
    mov    eax,DWORD PTR [esp+0x30]
    push    0x63
    push    0x9
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch350
    pop    esi
    ret    0x40
  Branch350:
    mov    eax,DWORD PTR [esp+0x38]
    test    eax,eax
    je    Branch351
    mov    ecx,DWORD PTR [esp+0x34]
    push    0xa
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch351
    pop    esi
    ret    0x40
  Branch351:
    mov    edx,DWORD PTR [esp+0x44]
    push    0xb
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch352
    pop    esi
    ret    0x40
  Branch352:
    mov    eax,DWORD PTR [esp+0x3c]
    push    0xc
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch353
    pop    esi
    ret    0x40
  Branch353:
    mov    ecx,DWORD PTR [esp+0x40]
    push    0xd
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    setne    al
    pop    esi
    ret    0x40
  }
}

// If service10 exists, forward sixteen STACK words to basic reader; cache field2/3 pointers before that call.
// On success reload their values/current service10 and update key; ignore update status, return its upperEAX/AL1.
// Reader false returns raw EAX; absent service returns0. No local EH/rollback. RET40.
// R6GameService.dll @ 10044db0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SubmitBasicServiceRequest(void *dispatcher,void *param_1,undefined2 *param_2,char *param_3,
    int *param_4,int *param_5,int *param_6,int *param_7,undefined2 *param_8,char *param_9,char *param_10,char *param_11,
    void *param_12,size_t param_13,int *param_14,int *param_15,int *param_16)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    jne    Branch354
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x40
  Branch354:
    mov    eax,DWORD PTR [esp+0x4c]
    mov    ecx,DWORD PTR [esp+0x48]
    mov    edx,DWORD PTR [esp+0x44]
    push    eax
    mov    eax,DWORD PTR [esp+0x44]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x44]
    mov    edi,DWORD PTR [esp+0x28]
    push    edx
    mov    edx,DWORD PTR [esp+0x44]
    mov    ebx,DWORD PTR [esp+0x28]
    push    eax
    mov    eax,DWORD PTR [esp+0x44]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x44]
    push    edx
    mov    edx,DWORD PTR [esp+0x44]
    push    eax
    mov    eax,DWORD PTR [esp+0x44]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x44]
    push    edx
    mov    edx,DWORD PTR [esp+0x3c]
    push    eax
    mov    eax,DWORD PTR [esp+0x3c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x3c]
    push    edi
    push    ebx
    push    edx
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::TryCopyFourteenIndexedClDataFields
    test    al,al
    jne    Branch355
    pop    edi
    pop    esi
    pop    ebx
    ret    0x40
  Branch355:
    mov    edx,DWORD PTR [edi]
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    push    eax
    call    R6GameServiceAddresses::CLobbySrvConnectionListAppendUniqueWord
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x40
  }
}

// If service10 exists, forward twenty-two STACK words to extended reader; cache field2/3 pointers before call.
// On success load captured pointed values/current service10, update key and retain update upperEAX with AL1.
// Reader false returns raw EAX; absent service returns0. No local EH/rollback. RET58.
// R6GameService.dll @ 10044e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SubmitExtendedServiceRequest(void *dispatcher,void *param_1,undefined2 *param_2,char *param_3,
    int *param_4,int *param_5,int *param_6,int *param_7,undefined2 *param_8,char *param_9,char *param_10,char *param_11,
    int param_12,int param_13,void *param_14,size_t param_15,int *param_16,int *param_17,int *param_18,int *param_19,
    int param_20,int param_21,int *param_22)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    jne    Branch356
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x58
  Branch356:
    mov    eax,DWORD PTR [esp+0x64]
    mov    ecx,DWORD PTR [esp+0x60]
    mov    edx,DWORD PTR [esp+0x5c]
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x5c]
    push    edx
    mov    edx,DWORD PTR [esp+0x5c]
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x5c]
    push    edx
    mov    edx,DWORD PTR [esp+0x5c]
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edi,DWORD PTR [esp+0x40]
    push    edx
    mov    edx,DWORD PTR [esp+0x5c]
    mov    ebx,DWORD PTR [esp+0x40]
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x5c]
    push    edx
    mov    edx,DWORD PTR [esp+0x5c]
    push    eax
    mov    eax,DWORD PTR [esp+0x5c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x5c]
    push    edx
    mov    edx,DWORD PTR [esp+0x54]
    push    eax
    mov    eax,DWORD PTR [esp+0x54]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x54]
    push    edi
    push    ebx
    push    edx
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::TryCopyTwentyIndexedClDataFields
    test    al,al
    jne    Branch357
    pop    edi
    pop    esi
    pop    ebx
    ret    0x58
  Branch357:
    mov    edx,DWORD PTR [edi]
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    push    eax
    call    R6GameServiceAddresses::CLobbySrvConnectionListAppendUniqueWord
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x58
  }
}

// Cache old record18 before refresh35; flags40/100/low-byte80 select independent single/repeated/named-value paths.
// Basic extraction failure falls through to extended; full scratch words/text tails and current callback remain native.
// Preserve raw heap arithmetic, iterator wrap, partial outputs and exact eight-state cleanup; raw heaps lack EH guards.
// R6GameService.dll @ 10048970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector35Subrecords(void *dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector35EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x380
    push    ebx
    push    ebp
    push    esi
    xor    ebx,ebx
    push    edi
    mov    ebp,ecx
    mov    edi,R6GameServiceAddresses::ClDataListBaseOffsets
    mov    esi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    ebx
    push    0x3
    lea    ecx,[esp+0xa0]
    mov    DWORD PTR [esp+0xf0],ebx
    mov    DWORD PTR [esp+0xa4],edi
    mov    DWORD PTR [esp+0xb4],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0xa8]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x98],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0xa4],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0x88]
    mov    DWORD PTR [esp+0x3a0],ebx
    mov    DWORD PTR [esp+0x8c],edi
    mov    DWORD PTR [esp+0x9c],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x90]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x80],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x8c],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0xd4]
    mov    DWORD PTR [esp+0xd8],edi
    mov    DWORD PTR [esp+0xe8],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0xdc]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0xcc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0xd8],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x3
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x4c],edi
    mov    DWORD PTR [esp+0x5c],esi
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x50]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::clDataListPTR_LAB
    push    ebx
    push    0x2
    lea    ecx,[esp+0xb8]
    xor    esi,esi
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0xbc],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0xd0],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0xc0]
    mov    BYTE PTR [esp+0x39c],0x4
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0xb0],R6GameServiceAddresses::clDataBinPTR_FUN
    mov    eax,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esp+0xec],ebx
    push    0x35
    mov    BYTE PTR [esp+0x39c],0x5
    mov    ecx,DWORD PTR [eax+0x18]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [ebp+0x8]
    cmp    eax,ebx
    jne    Branch359
  Branch358:
    lea    ecx,[esp+0xb0]
    call    R6GameServiceAddresses::DestroyClDataBin
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x398],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xcc]
    mov    BYTE PTR [esp+0x398],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x80]
    mov    BYTE PTR [esp+0x398],0x0
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch381
  Branch359:
    mov    ecx,DWORD PTR [eax+0x8]
    lea    edx,[esp+0x72]
    push    ebx
    push    edx
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    ecx,DWORD PTR [ebp+0x8]
    lea    eax,[esp+0x98]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    WORD PTR [esp+0x72],0x35
    jne    Branch358
    lea    edx,[esp+0x3c]
    lea    eax,[esp+0x26]
    push    edx
    lea    ecx,[esp+0x60]
    push    eax
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::TryReadType35DescriptorFields
    test    BYTE PTR [esp+0x5c],0x40
    je    Branch363
    lea    edx,[esp+0x80]
    push    0x2
    push    edx
    lea    ecx,[esp+0xa0]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch363
    lea    eax,[esp+0x80]
    mov    ecx,ebp
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLength
    mov    ebx,eax
    test    ebx,ebx
    je    Branch360
    lea    edi,[ebx+0x1]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    esi,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
  Branch360:
    cmp    WORD PTR [esp+0x26],0x0
    jne    Branch361
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x78]
    push    eax
    lea    edx,[esp+0x80]
    push    ecx
    push    edx
    push    ebx
    lea    eax,[esp+0x18c]
    push    esi
    lea    ecx,[esp+0x218]
    push    eax
    lea    edx,[esp+0x114]
    push    ecx
    lea    eax,[esp+0x4c]
    push    edx
    lea    ecx,[esp+0x3c]
    push    eax
    lea    edx,[esp+0x4c]
    push    ecx
    lea    eax,[esp+0x3c]
    push    edx
    lea    ecx,[esp+0x68]
    push    eax
    lea    edx,[esp+0x140]
    push    ecx
    lea    eax,[esp+0x56]
    push    edx
    lea    ecx,[esp+0xb8]
    push    eax
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::SubmitBasicServiceRequest
    test    al,al
    je    Branch361
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x7c]
    push    eax
    mov    eax,DWORD PTR [esp+0x84]
    push    eax
    push    ebx
    lea    eax,[esp+0x18c]
    push    esi
    push    eax
    lea    eax,[esp+0x21c]
    push    eax
    lea    eax,[esp+0x118]
    push    eax
    mov    eax,DWORD PTR [esp+0x50]
    push    eax
    mov    eax,DWORD PTR [esp+0x40]
    push    eax
    mov    eax,DWORD PTR [esp+0x50]
    push    eax
    mov    eax,DWORD PTR [esp+0x40]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x6c]
    push    eax
    lea    eax,[esp+0x144]
    push    eax
    mov    eax,DWORD PTR [esp+0x5a]
    push    eax
    call    DWORD PTR [edx+0x24]
    jmp    Branch362
  Branch361:
    lea    ecx,[esp+0x18]
    lea    edx,[esp+0x30c]
    push    ecx
    lea    eax,[esp+0x28c]
    push    edx
    lea    ecx,[esp+0x68]
    push    eax
    lea    edx,[esp+0x74]
    push    ecx
    lea    eax,[esp+0x7c]
    push    edx
    lea    ecx,[esp+0x88]
    push    eax
    push    ecx
    push    ebx
    lea    edx,[esp+0x154]
    push    esi
    lea    eax,[esp+0x17c]
    push    edx
    lea    ecx,[esp+0x1a4]
    push    eax
    lea    edx,[esp+0x230]
    push    ecx
    lea    eax,[esp+0x12c]
    push    edx
    lea    ecx,[esp+0x64]
    push    eax
    lea    edx,[esp+0x54]
    push    ecx
    lea    eax,[esp+0x64]
    push    edx
    lea    ecx,[esp+0x54]
    push    eax
    lea    edx,[esp+0x80]
    push    ecx
    lea    eax,[esp+0x158]
    push    edx
    lea    ecx,[esp+0x6e]
    push    eax
    lea    edx,[esp+0xd0]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::SubmitExtendedServiceRequest
    test    al,al
    je    Branch362
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    edx
    lea    edx,[esp+0x310]
    push    edx
    lea    edx,[esp+0x290]
    push    edx
    mov    edx,DWORD PTR [esp+0x6c]
    push    edx
    mov    edx,DWORD PTR [esp+0x78]
    push    edx
    mov    edx,DWORD PTR [esp+0x80]
    push    edx
    mov    edx,DWORD PTR [esp+0x8c]
    push    edx
    push    ebx
    lea    edx,[esp+0x154]
    push    esi
    push    edx
    lea    edx,[esp+0x180]
    push    edx
    lea    edx,[esp+0x1a8]
    push    edx
    lea    edx,[esp+0x234]
    push    edx
    lea    edx,[esp+0x130]
    push    edx
    mov    edx,DWORD PTR [esp+0x68]
    push    edx
    mov    edx,DWORD PTR [esp+0x58]
    push    edx
    mov    edx,DWORD PTR [esp+0x68]
    push    edx
    mov    edx,DWORD PTR [esp+0x58]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x84]
    push    edx
    lea    edx,[esp+0x15c]
    push    edx
    mov    edx,DWORD PTR [esp+0x72]
    push    edx
    call    DWORD PTR [eax+0x20]
  Branch362:
    test    esi,esi
    je    Branch363
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    xor    esi,esi
  Branch363:
    mov    eax,DWORD PTR [esp+0x5c]
    test    ah,0x1
    je    Branch369
    lea    eax,[esp+0x34]
    push    0x3
    push    eax
    lea    ecx,[esp+0xa0]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch369
    lea    ecx,[esp+0x40]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    DWORD PTR [esp+0x40],0x1
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch369
  Branch364:
    lea    edx,[esp+0x40]
    mov    ecx,ebp
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataBinaryAndGetLength
    mov    ebx,eax
    test    ebx,ebx
    je    Branch365
    lea    edi,[ebx+0x1]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    esi,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
  Branch365:
    lea    eax,[esp+0x26]
    push    0x0
    push    eax
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0x26],0x0
    jne    Branch366
    lea    ecx,[esp+0x18]
    lea    edx,[esp+0x78]
    push    ecx
    lea    eax,[esp+0x80]
    push    edx
    push    eax
    push    ebx
    lea    ecx,[esp+0x18c]
    push    esi
    lea    edx,[esp+0x218]
    push    ecx
    lea    eax,[esp+0x114]
    push    edx
    lea    ecx,[esp+0x4c]
    push    eax
    lea    edx,[esp+0x3c]
    push    ecx
    lea    eax,[esp+0x4c]
    push    edx
    lea    ecx,[esp+0x3c]
    push    eax
    lea    edx,[esp+0x90]
    push    ecx
    lea    eax,[esp+0x140]
    push    edx
    lea    ecx,[esp+0x56]
    push    eax
    lea    edx,[esp+0x78]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::SubmitBasicServiceRequest
    test    al,al
    je    Branch366
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0x7c]
    push    edx
    mov    edx,DWORD PTR [esp+0x84]
    push    edx
    push    ebx
    lea    edx,[esp+0x18c]
    push    esi
    push    edx
    lea    edx,[esp+0x21c]
    push    edx
    lea    edx,[esp+0x118]
    push    edx
    mov    edx,DWORD PTR [esp+0x50]
    push    edx
    mov    edx,DWORD PTR [esp+0x40]
    push    edx
    mov    edx,DWORD PTR [esp+0x50]
    push    edx
    mov    edx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x94]
    push    edx
    lea    edx,[esp+0x144]
    push    edx
    mov    edx,DWORD PTR [esp+0x5a]
    push    edx
    call    DWORD PTR [eax+0x1c]
    jmp    Branch367
  Branch366:
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x30c]
    push    eax
    lea    edx,[esp+0x28c]
    push    ecx
    lea    eax,[esp+0x68]
    push    edx
    lea    ecx,[esp+0x74]
    push    eax
    lea    edx,[esp+0x7c]
    push    ecx
    lea    eax,[esp+0x88]
    push    edx
    push    eax
    push    ebx
    lea    ecx,[esp+0x154]
    push    esi
    lea    edx,[esp+0x17c]
    push    ecx
    lea    eax,[esp+0x1a4]
    push    edx
    lea    ecx,[esp+0x230]
    push    eax
    lea    edx,[esp+0x12c]
    push    ecx
    lea    eax,[esp+0x64]
    push    edx
    lea    ecx,[esp+0x54]
    push    eax
    lea    edx,[esp+0x64]
    push    ecx
    lea    eax,[esp+0x54]
    push    edx
    lea    ecx,[esp+0xa8]
    push    eax
    lea    edx,[esp+0x158]
    push    ecx
    lea    eax,[esp+0x6e]
    push    edx
    lea    ecx,[esp+0x90]
    push    eax
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::SubmitExtendedServiceRequest
    test    al,al
    je    Branch367
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    eax
    lea    eax,[esp+0x310]
    push    eax
    lea    eax,[esp+0x290]
    push    eax
    mov    eax,DWORD PTR [esp+0x6c]
    push    eax
    mov    eax,DWORD PTR [esp+0x78]
    push    eax
    mov    eax,DWORD PTR [esp+0x80]
    push    eax
    mov    eax,DWORD PTR [esp+0x8c]
    push    eax
    push    ebx
    lea    eax,[esp+0x154]
    push    esi
    push    eax
    lea    eax,[esp+0x180]
    push    eax
    lea    eax,[esp+0x1a8]
    push    eax
    lea    eax,[esp+0x234]
    push    eax
    lea    eax,[esp+0x130]
    push    eax
    mov    eax,DWORD PTR [esp+0x68]
    push    eax
    mov    eax,DWORD PTR [esp+0x58]
    push    eax
    mov    eax,DWORD PTR [esp+0x68]
    push    eax
    mov    eax,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0xac]
    push    eax
    lea    eax,[esp+0x15c]
    push    eax
    mov    eax,DWORD PTR [esp+0x72]
    push    eax
    call    DWORD PTR [edx+0x18]
  Branch367:
    test    esi,esi
    je    Branch368
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    xor    esi,esi
  Branch368:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    eax,ecx
    inc    ecx
    mov    DWORD PTR [esp+0x38],ecx
    lea    ecx,[esp+0x40]
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esp+0x3c]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch364
  Branch369:
    mov    al,BYTE PTR [esp+0x5c]
    test    al,al
    jns    Branch378
    lea    edx,[esp+0xcc]
    push    0x4
    push    edx
    lea    ecx,[esp+0xa0]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch378
    lea    eax,[esp+0x40]
    push    0x0
    push    eax
    lea    ecx,[esp+0xd4]
    mov    DWORD PTR [esp+0x40],0x1
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch378
  Branch370:
    lea    ecx,[esp+0x1e0]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch358
    lea    edx,[esp+0x2f]
    push    0x1
    push    edx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::ReadIndexedByte
    test    al,al
    je    Branch358
    mov    bl,BYTE PTR [esp+0x2f]
    lea    ecx,[esp+0x288]
    test    bl,bl
    push    0x2
    push    ecx
    setne    al
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0xf0],al
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch358
    lea    edx,[esp+0x30c]
    push    0x3
    push    edx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch358
    lea    eax,[esp+0xb0]
    push    0x4
    push    eax
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    je    Branch358
    mov    esi,DWORD PTR [esp+0xc0]
    mov    eax,DWORD PTR [esp+0xbc]
    sub    esi,eax
    mov    DWORD PTR [esp+0xf4],esi
    je    Branch371
    lea    ecx,[esi+0x1]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0xc0]
    mov    ebx,eax
    mov    eax,DWORD PTR [esp+0xbc]
    push    ebx
    push    edx
    push    eax
    mov    DWORD PTR [esp+0x64],ebx
    call    R6GameServiceAddresses::MoveByteRange
    mov    BYTE PTR [ebx+esi*1],0x0
    jmp    Branch372
  Branch371:
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x58],ebx
  Branch372:
    lea    ecx,[esp+0x34]
    push    0x5
    push    ecx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch358
    lea    edx,[esp+0xe4]
    push    0x6
    push    edx
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    jne    Branch373
    mov    DWORD PTR [esp+0xe4],0xffff
  Branch373:
    lea    eax,[esp+0xec]
    push    0x7
    push    eax
    lea    ecx,[esp+0x48]
    call    R6GameServiceAddresses::ReadIndexedWord
    test    al,al
    je    Branch380
    mov    ecx,DWORD PTR [esp+0x34]
    lea    edx,[esp+0x10c]
    add    ecx,0x10
    push    edx
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0xf4],eax
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    cl,BYTE PTR [esp+0x13]
    lea    edx,[esp+0x13]
    mov    BYTE PTR [esp+0x13],cl
    lea    ecx,[esp+0xf0]
    push    edx
    push    ecx
    push    eax
    call    R6GameServiceAddresses::CountCircularListRange
    lea    eax,[eax*4+0x4]
    add    esp,0xc
    xor    esi,esi
    mov    edi,0x1
    test    eax,eax
    je    Branch377
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x3c]
    mov    esi,eax
    push    0x0
    lea    eax,[esi+0x4]
    mov    DWORD PTR [esi],edx
    mov    ecx,DWORD PTR [esp+0x38]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch376
    lea    eax,[esi+0x4]
    jmp    Branch375
  Branch374:
    mov    eax,DWORD PTR [esp+0xf8]
  Branch375:
    inc    edi
    add    eax,0x4
    mov    DWORD PTR [esp+0xf8],eax
    lea    ecx,[edi-0x1]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x38]
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch374
  Branch376:
    mov    ebx,DWORD PTR [esp+0x58]
  Branch377:
    mov    eax,DWORD PTR [esp+0xec]
    mov    ecx,DWORD PTR [ebp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0xf8]
    push    0x0
    push    eax
    mov    eax,DWORD PTR [esp+0xf0]
    push    ebx
    push    eax
    lea    eax,[esp+0x320]
    push    eax
    lea    eax,[esp+0x2a0]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [esp+0x30]
    push    eax
    mov    eax,DWORD PTR [esp+0x108]
    push    edi
    push    esi
    push    eax
    lea    eax,[esp+0x20c]
    push    eax
    call    DWORD PTR [edx+0x30]
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x38]
    mov    eax,ecx
    inc    ecx
    mov    DWORD PTR [esp+0x38],ecx
    lea    ecx,[esp+0x40]
    push    eax
    push    ecx
    lea    ecx,[esp+0xd4]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch370
  Branch378:
    lea    ecx,[esp+0xbc]
    mov    BYTE PTR [esp+0x398],0x3
    mov    DWORD PTR [esp+0xb0],R6GameServiceAddresses::clDataBinPTR_FUN
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0xb0],R6GameServiceAddresses::PTR_LAB
    mov    BYTE PTR [esp+0x398],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xcc]
    mov    BYTE PTR [esp+0x398],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x80]
    mov    BYTE PTR [esp+0x398],0x0
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x98],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0xa4],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0xa4]
    mov    DWORD PTR [esp+0x398],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
  Branch379:
    mov    ecx,DWORD PTR [esp+0x390]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x38c
    ret
  Branch380:
    lea    ecx,[esp+0xbc]
    mov    BYTE PTR [esp+0x398],0x3
    mov    DWORD PTR [esp+0xb0],R6GameServiceAddresses::clDataBinPTR_FUN
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    esi,R6GameServiceAddresses::PTR_LAB
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0xb0],esi
    mov    BYTE PTR [esp+0x398],0x2
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0xcc]
    mov    BYTE PTR [esp+0x398],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x80],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x8c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x8c]
    mov    BYTE PTR [esp+0x398],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x80],esi
  Branch381:
    lea    ecx,[esp+0x98]
    mov    DWORD PTR [esp+0x398],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch379
  }
}

// Destroy inherited outer descriptor EBP-304 after completed first construction.
// R6GameService.dll @ 10067db0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x304]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy inherited single-record descriptor EBP-31c then predecessor outer scope.
// R6GameService.dll @ 10067dbb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x31c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy inherited row-source descriptor EBP-2d0 then predecessor single/outer scopes.
// R6GameService.dll @ 10067dc6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2d0]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy inherited child descriptor EBP-35c then predecessor row-source/single/outer scopes.
// R6GameService.dll @ 10067dd1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x35c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited binary EBP-2ec base after triplet construction failure, then descriptor scopes.
// R6GameService.dll @ 10067ddc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x2ec]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited binary EBP-2ec fully, then descriptor scopes; preserve entered-failure retry behavior.
// R6GameService.dll @ 10067de7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x2ec]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Reset inherited outer EBP-304 base after entered successful pointer-list cleanup; do not retry.
// R6GameService.dll @ 10067df2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x304]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited single-record EBP-31c base after entered WORD7-failure cleanup, then outer scope.
// R6GameService.dll @ 10067dfd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector35SubrecordsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x31c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select literal selector35 eight-state FuncInfo8280c/map827cc and tail the existing runtime dispatcher.
// R6GameService.dll @ 10067e08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector35EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector35SubrecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector35 descriptor unwind/FuncInfo words; raw payload/array ownership is absent.
// R6GameService.dll data @ 100827cc : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector35SubrecordsUnwindMap[8] = {
  {-1, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind2},
  {0x1, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind3},
  {0x2, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind4},
  {0x3, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind5},
  {0x3, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind6},
  {0x0, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind7},
  {-1, R6GameServiceAddresses::DispatchSelector35SubrecordsUnwind8},
};

// Literal selector35 descriptor unwind/FuncInfo words; raw payload/array ownership is absent.
// R6GameService.dll data @ 1008280c : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector35SubrecordsExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::DispatchSelector35SubrecordsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh32/capture record18, ignore marker/list status, gate full WORD32 and parse text/BYTE/int/text/text/binary.
// Copy raw binary with cached length/live range and cookie BYTE; callback30 receives all twelve native arguments.
// Boolean AL retains upper24 from address of numeric scratch; WORD6 status ignored. Raw payload has no EH owner.
// R6GameService.dll @ 10049630 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector32Record(int dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector32EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x170
    push    esi
    mov    esi,ecx
    push    0x0
    mov    DWORD PTR [esp+0x24],0x0
    push    0x3
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x0
    push    0x2
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x184],0x0
    mov    DWORD PTR [esp+0x2c],0x0
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x180],0x1
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    push    0x32
    mov    ecx,esi
    mov    BYTE PTR [esp+0x180],0x2
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch382
    mov    ecx,DWORD PTR [eax+0x18]
    lea    edx,[esp+0x6]
    mov    DWORD PTR [esp+0x44],ecx
    mov    ecx,DWORD PTR [eax+0x8]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x8]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    cmp    WORD PTR [esp+0x6],0x32
    jne    Branch382
    lea    edx,[esp+0x48]
    push    0x0
    push    edx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch382
    lea    eax,[esp+0x4]
    push    0x1
    push    eax
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::ReadIndexedByte
    test    al,al
    je    Branch382
    lea    ecx,[esp+0x20]
    push    0x2
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch382
    lea    edx,[esp+0xf0]
    push    0x3
    push    edx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch382
    lea    eax,[esp+0x6c]
    push    0x4
    push    eax
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch382
    lea    ecx,[esp+0x28]
    push    0x5
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::CopyIndexedClDataBin
    test    al,al
    jne    Branch383
  Branch382:
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::DestroyClDataBin
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x17c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x170]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x17c
    ret
  Branch383:
    mov    eax,DWORD PTR [esp+0x34]
    push    ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    push    edi
    sub    ebp,eax
    je    Branch384
    lea    edx,[ebp+0x1]
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x40]
    mov    edi,eax
    mov    al,BYTE PTR [esp+0xc]
    lea    ecx,[esp+0xd]
    mov    BYTE PTR [esp+0xd],al
    mov    eax,DWORD PTR [esp+0x3c]
    push    ecx
    push    edi
    push    edx
    push    eax
    call    R6GameServiceAddresses::CopyByteRange
    mov    BYTE PTR [edi+ebp*1],0x0
    jmp    Branch385
  Branch384:
    xor    edi,edi
  Branch385:
    lea    ecx,[esp+0x2c]
    push    0x6
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esp+0x2c]
    mov    ecx,DWORD PTR [esi+0x14]
    push    eax
    push    0x1
    push    ebp
    push    edi
    lea    eax,[esp+0x84]
    push    0xffff
    push    eax
    lea    eax,[esp+0x110]
    push    eax
    mov    eax,DWORD PTR [esp+0x68]
    push    eax
    lea    eax,[esp+0x48]
    push    0x1
    push    eax
    mov    al,BYTE PTR [esp+0x34]
    mov    edx,DWORD PTR [ecx]
    test    al,al
    setne    al
    push    eax
    lea    eax,[esp+0x7c]
    push    eax
    call    DWORD PTR [edx+0x30]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::DestroyClDataBin
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x184],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x17c]
    pop    edi
    pop    ebp
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x17c
    ret
  }
}

// Refresh33/capture record18, copy list1/read text0 capacity33, then emit each integer starting at1 to callback34.
// Reuse numeric scratch initialized once to zero, retained text, current receiver and cached record.
// An initial numeric read returning false still succeeds.
// Preserve unused second-list lifetime,32-bit index wrap, raw cleanup EAX/AL and six-state entered cleanup.
// R6GameService.dll @ 100498b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchSelector33IndexedValues(int dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSelector33EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x58
    push    ebx
    push    ebp
    push    esi
    xor    ebp,ebp
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    push    ebp
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],0x3
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x38],edi
    push    ebp
    push    0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x78],ebp
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebp
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x20],edi
    push    0x33
    mov    ecx,esi
    mov    BYTE PTR [esp+0x74],0x1
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebp
    jne    Branch386
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x38],edi
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x70],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x58]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x64
    ret
  Branch386:
    mov    ebp,DWORD PTR [eax+0x18]
    lea    ecx,[esp+0x2c]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch387
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x70],al
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch388
  Branch387:
    push    0x21
    lea    edx,[esp+0x48]
    push    0x0
    push    edx
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch389
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],edi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
  Branch388:
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x70],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x58]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x64
    ret
  Branch389:
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    lea    ecx,[esp+0x34]
    mov    edi,0x2
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch391
  Branch390:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esi+0x14]
    push    ebp
    push    eax
    mov    edx,DWORD PTR [ecx]
    lea    eax,[esp+0x4c]
    push    eax
    call    DWORD PTR [edx+0x34]
    mov    eax,edi
    lea    ecx,[esp+0x10]
    push    eax
    push    ecx
    lea    ecx,[esp+0x34]
    inc    edi
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch390
  Branch391:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x70],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x70],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x68]
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x64
    ret
  }
}

// Destroy inherited selector32 list EBP-178 after completed construction.
// R6GameService.dll @ 10067e20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector32RecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x178]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited selector32 binary EBP-158 base after triplet construction failure, then list predecessor0.
// R6GameService.dll @ 10067e2b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector32RecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x158]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited selector32 binary EBP-158 fully, then list predecessor0; raw payload is not owned.
// R6GameService.dll @ 10067e36 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector32RecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x158]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Destroy inherited selector33 outer list EBP-48.
// R6GameService.dll @ 10067e50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy inherited selector33 unused spare list EBP-60, then outer predecessor0.
// R6GameService.dll @ 10067e58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset unused spare EBP-60 base after entered missing-cache pointer-list cleanup, then outer predecessor0.
// R6GameService.dll @ 10067e60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset outer EBP-48 base after entered missing-cache outer pointer-list cleanup; do not retry.
// R6GameService.dll @ 10067e68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset unused spare EBP-60 base after entered text-failure pointer-list cleanup, then outer predecessor0.
// R6GameService.dll @ 10067e70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset unused spare EBP-60 base after entered successful pointer-list cleanup, then outer predecessor0.
// R6GameService.dll @ 10067e78 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DispatchSelector33IndexedValuesUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact selector32/33 descriptor FuncInfo/unwind map and tail existing runtime dispatch.
// R6GameService.dll @ 10067e41 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector32EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector32RecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact selector32/33 descriptor FuncInfo/unwind map and tail existing runtime dispatch.
// R6GameService.dll @ 10067e80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector33EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchSelector33IndexedValuesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal selector32/33 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10082828 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector32RecordUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DispatchSelector32RecordUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector32RecordUnwind2},
  {0x0, R6GameServiceAddresses::DispatchSelector32RecordUnwind3},
};

// Literal selector32/33 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 10082840 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector32RecordExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::DispatchSelector32RecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal selector32/33 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 1008285c : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchSelector33IndexedValuesUnwindMap[6] = {
  {-1, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind1},
  {0x0, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind2},
  {0x0, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind3},
  {-1, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind4},
  {0x0, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind5},
  {0x0, R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwind6},
};

// Literal selector32/33 descriptor unwind/FuncInfo words.
// R6GameService.dll data @ 1008288c : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchSelector33IndexedValuesExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::DispatchSelector33IndexedValuesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Guard service10, append value to temporary list and transfer six-word clone to request8/mode2 consumer.
// Reload current service/arguments after clone; cleanup supplies upperEAX/AL0 or1. Retain rewritten key argument.
// R6GameService.dll @ 100443d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSerializedRequest8(void *dispatcher,uint value,uint key)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRequests8_22EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    esi
    mov    esi,ecx
    xor    eax,eax
    mov    ecx,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x4],eax
    cmp    ecx,eax
    je    Branch393
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x10],0x3
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x2c],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x8]
    push    eax
    mov    DWORD PTR [esp+0x2c],0x1
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    sub    esp,0x18
    lea    edx,[esp+0x20]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x1c],esp
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    eax,DWORD PTR [esp+0x4c]
    mov    ecx,DWORD PTR [esp+0x48]
    push    0x2
    push    0x8
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    call    R6GameServiceAddresses::ApplyIndexedKeyUpdate
    test    al,al
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    je    Branch392
    lea    edx,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x2
    mov    DWORD PTR [esp+0x34],edx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x3
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x8
  Branch392:
    lea    eax,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x4
    mov    DWORD PTR [esp+0x34],eax
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x5
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x4
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch393:
    mov    ecx,DWORD PTR [esp+0x20]
    xor    al,al
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x8
  }
}

// Guard service10, append value to temporary list and transfer six-word clone to request22/mode2 consumer.
// Reload current service/arguments after clone; cleanup supplies upperEAX/AL0 or1. Retain rewritten key argument.
// R6GameService.dll @ 100447f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSerializedRequest22(void *dispatcher,uint value,uint key)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRequests8_22EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    esi
    mov    esi,ecx
    xor    eax,eax
    mov    ecx,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x4],eax
    cmp    ecx,eax
    je    Branch395
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x10],0x3
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x2c],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x8]
    push    eax
    mov    DWORD PTR [esp+0x2c],0x1
    call    R6GameServiceAddresses::AppendClDataListSignedDecimal
    sub    esp,0x18
    lea    edx,[esp+0x20]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x1c],esp
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    eax,DWORD PTR [esp+0x4c]
    mov    ecx,DWORD PTR [esp+0x48]
    push    0x2
    push    0x22
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    call    R6GameServiceAddresses::ApplyIndexedKeyUpdate
    test    al,al
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    je    Branch394
    lea    edx,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x2
    mov    DWORD PTR [esp+0x34],edx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x3
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x8
  Branch394:
    lea    eax,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x4
    mov    DWORD PTR [esp+0x34],eax
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x5
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x4
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch395:
    mov    ecx,DWORD PTR [esp+0x20]
    xor    al,al
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x8
  }
}

// Reset request8/22 descriptor EBP-24 base after header construction failure.
// R6GameService.dll @ 10067610 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind17(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy request8/22 completed descriptor EBP-24; no predecessor.
// R6GameService.dll @ 10067618 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind27(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset request8/22 descriptor EBP-24 base after entered successful head release.
// R6GameService.dll @ 10067620 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind37(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT rewritten argument EBP+8 plus4; store EBP-38, then predecessor2 base reset.
// R6GameService.dll @ 10067628 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind46(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch396
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch397
  Branch396:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch397:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset request8/22 descriptor EBP-24 base after entered failed head release.
// R6GameService.dll @ 1006764f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind55(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT rewritten argument EBP+8 plus4; store EBP-40, then predecessor4 base reset.
// R6GameService.dll @ 10067657 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind64(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch398
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x40],eax
    jmp    Branch399
  Branch398:
    mov    DWORD PTR [ebp-0x40],0x0
  Branch399:
    mov    ecx,DWORD PTR [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select shared request8/22 eight-state FuncInfo81da4/map81d64, including two null-action states.
// R6GameService.dll @ 1006767e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRequests8_22EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo7
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Load dispatcher from owner+158 and tail-forward two stack words; preserve complete raw EAX and callee RET8.
// R6GameService.dll @ 10041130 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardRequest8ViaOffset158(void *owner,uint value,uint key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x158]
    jmp    R6GameServiceAddresses::SendSerializedRequest8
  }
}

// Load dispatcher from owner+158 and tail-forward two stack words; preserve complete raw EAX and callee RET8.
// R6GameService.dll @ 10041370 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchSelector22ThroughOptionalChannel(void *owner,uint value,uint key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x158]
    jmp    R6GameServiceAddresses::SendSerializedRequest22
  }
}

// Literal request8/22 shared cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081d64 : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap7[8] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind17},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind27},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind37},
  {0x2, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind46},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind55},
  {0x4, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind64},
  {-1, 0x0},
  {0x6, 0x0},
};

// Literal request8/22 shared cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081da4 : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo7 = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap7,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Inferred physical locals: cookieS-2d, outgoing-slot scratchS-2c, head scratchS-28 and descriptorS-24.
struct CommonRequestLocals {
  byte cookieStorage[4];
  uint cloneScratch;
  uint headScratch;
  uint descriptor[6];
};

// Raw six-word outgoing ABI record. The consumer owns this slot; it has no additional caller-side destructor.
struct CommonRequestTransfer {
  uint words[6];
};

// Release the current descriptor stage; entered clear/free stages preserve the native lack of retries.
struct CommonRequestCleanup {
  CommonRequestLocals *frame;
  uint *keyWord;
  int state;
  bool armed;
  // Base, cookie, full-list, entered-clear and entered-free actions use the current saved argument/scratch.
  ~CommonRequestCleanup() noexcept(false)
  {
    if (!armed) return;
    using EmptyABI = void (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
      case 0: case 3:
        state = -1;
        ResetClDataVtable(frame->descriptor);
        break;
      case 1:
        state = 0;
        ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(frame->cookieStorage + 3);
        break;
      case 2:
        state = -1;
        DestroyClDataListAlias(frame->descriptor);
        break;
      case 4:
        state = 3;
        frame->headScratch = *keyWord == 0 ? 0 : *keyWord + 4;
        ReleaseNodesAndSentinel((void *)frame->headScratch);
        break;
      case 5:
        state = 3;
        ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)frame->headScratch);
        break;
      }
    }
  }
};

// Append a decimal value, transfer a six-word clone to request2c/mode2, then release the local descriptor.
// Consumer owns the outgoing slot. Reload service/scalars after cloning; ignore append/clone status; retain exact AL.
// Inferred local frame preserves the untouched cookie, rewritten key argument and six native lifetime states.
// R6GameService.dll @ 10044520 : complete native control/access order and raw ABI retained.
uint __thiscall SendSerializedRequest2c(void *dispatcher,uint value,uint key)
{
  CommonRequestLocals frame;
  CommonRequestCleanup cleanup{&frame,&key,-1,true};
  void *savedDispatcher = dispatcher;
  frame.cloneScratch = 0;
  uint service = *(uint *)((byte *)savedDispatcher + 0x10);
  if (service == 0) return 0;
  frame.descriptor[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.descriptor[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.descriptor[2] = 3;
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 1;
  InitializeCircularListSentinel(frame.descriptor + 4,(uint)(frame.cookieStorage + 3));
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 2;
  AppendClDataListSignedDecimal(frame.descriptor,&value);
  CommonRequestTransfer outgoing;
  frame.cloneScratch = (uint)&outgoing;
  CopyConstructClDataList(&outgoing,frame.descriptor,1);
  uint currentKey = key;
  uint currentValue = value;
  void *currentService = *(void **)((byte *)savedDispatcher + 0x10);
  using ConsumeABI = uint (__thiscall *)(void *,uint,uint,uint,uint,CommonRequestTransfer);
  uint consumed = ((ConsumeABI)R6GameServiceAddresses::ApplyIndexedKeyUpdate)(
      currentService,currentValue,currentKey,0x2c,2,outgoing);
  byte resultByte = (byte)consumed;
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 3;
  key = (uint)(frame.descriptor + 3);
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 4;
  InvokePointerListClearRange(frame.descriptor + 3);
  frame.headScratch = (uint)(frame.descriptor + 4);
  cleanup.state = 5;
  ReleaseListNodesRetainHeader(frame.descriptor + 4);
  void *currentHead = (void *)frame.descriptor[4];
  uint released = ReleaseMemoryIgnoringSize(currentHead,1);
  cleanup.armed = false;
  return (released & 0xffffff00u) | resultByte;
}

// Append a decimal value, transfer a six-word clone to request46/mode2, then release the local descriptor.
// Consumer owns the outgoing slot. Reload service/scalars after cloning; ignore append/clone status; retain exact AL.
// Inferred local frame preserves the untouched cookie, rewritten key argument and six native lifetime states.
// R6GameService.dll @ 10044660 : complete native control/access order and raw ABI retained.
uint __thiscall SendSerializedRequest46(void *dispatcher,uint value,uint key)
{
  CommonRequestLocals frame;
  CommonRequestCleanup cleanup{&frame,&key,-1,true};
  void *savedDispatcher = dispatcher;
  frame.cloneScratch = 0;
  uint service = *(uint *)((byte *)savedDispatcher + 0x10);
  if (service == 0) return 0;
  frame.descriptor[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.descriptor[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.descriptor[2] = 3;
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 1;
  InitializeCircularListSentinel(frame.descriptor + 4,(uint)(frame.cookieStorage + 3));
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 2;
  AppendClDataListSignedDecimal(frame.descriptor,&value);
  CommonRequestTransfer outgoing;
  frame.cloneScratch = (uint)&outgoing;
  CopyConstructClDataList(&outgoing,frame.descriptor,1);
  uint currentKey = key;
  uint currentValue = value;
  void *currentService = *(void **)((byte *)savedDispatcher + 0x10);
  using ConsumeABI = uint (__thiscall *)(void *,uint,uint,uint,uint,CommonRequestTransfer);
  uint consumed = ((ConsumeABI)R6GameServiceAddresses::ApplyIndexedKeyUpdate)(
      currentService,currentValue,currentKey,0x46,2,outgoing);
  byte resultByte = (byte)consumed;
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 3;
  key = (uint)(frame.descriptor + 3);
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 4;
  InvokePointerListClearRange(frame.descriptor + 3);
  frame.headScratch = (uint)(frame.descriptor + 4);
  cleanup.state = 5;
  ReleaseListNodesRetainHeader(frame.descriptor + 4);
  void *currentHead = (void *)frame.descriptor[4];
  uint released = ReleaseMemoryIgnoringSize(currentHead,1);
  cleanup.armed = false;
  return (released & 0xffffff00u) | resultByte;
}

// Append two decimal values, transfer a six-word clone to request9/mode2, then release the local descriptor.
// Consumer owns the outgoing slot. Reload service/scalars after cloning; ignore append/clone status; retain exact AL.
// Inferred local frame preserves the untouched cookie, rewritten key argument and six native lifetime states.
// R6GameService.dll @ 10044940 : complete native control/access order and raw ABI retained.
uint __thiscall SendSerializedRequest9(void *dispatcher,uint value,uint key,uint extraValue)
{
  CommonRequestLocals frame;
  CommonRequestCleanup cleanup{&frame,&key,-1,true};
  void *savedDispatcher = dispatcher;
  frame.cloneScratch = 0;
  uint service = *(uint *)((byte *)savedDispatcher + 0x10);
  if (service == 0) return 0;
  frame.descriptor[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.descriptor[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.descriptor[2] = 3;
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 1;
  InitializeCircularListSentinel(frame.descriptor + 4,(uint)(frame.cookieStorage + 3));
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 2;
  AppendClDataListSignedDecimal(frame.descriptor,&value);
  AppendClDataListSignedDecimal(frame.descriptor,&extraValue);
  CommonRequestTransfer outgoing;
  frame.cloneScratch = (uint)&outgoing;
  CopyConstructClDataList(&outgoing,frame.descriptor,1);
  uint currentKey = key;
  uint currentValue = value;
  void *currentService = *(void **)((byte *)savedDispatcher + 0x10);
  using ConsumeABI = uint (__thiscall *)(void *,uint,uint,uint,uint,CommonRequestTransfer);
  uint consumed = ((ConsumeABI)R6GameServiceAddresses::ApplyIndexedKeyUpdate)(
      currentService,currentValue,currentKey,0x9,2,outgoing);
  byte resultByte = (byte)consumed;
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 3;
  key = (uint)(frame.descriptor + 3);
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 4;
  InvokePointerListClearRange(frame.descriptor + 3);
  frame.headScratch = (uint)(frame.descriptor + 4);
  cleanup.state = 5;
  ReleaseListNodesRetainHeader(frame.descriptor + 4);
  void *currentHead = (void *)frame.descriptor[4];
  uint released = ReleaseMemoryIgnoringSize(currentHead,1);
  cleanup.armed = false;
  return (released & 0xffffff00u) | resultByte;
}

// Append a decimal value, transfer a six-word clone to request2e/mode2, then release the local descriptor.
// Consumer owns the outgoing slot. Reload service/scalars after cloning; ignore append/clone status; retain exact AL.
// Inferred local frame preserves the untouched cookie, rewritten key argument and six native lifetime states.
// R6GameService.dll @ 10044a80 : complete native control/access order and raw ABI retained.
uint __thiscall SendSerializedRequest2e(void *dispatcher,uint value,uint key)
{
  CommonRequestLocals frame;
  CommonRequestCleanup cleanup{&frame,&key,-1,true};
  void *savedDispatcher = dispatcher;
  frame.cloneScratch = 0;
  uint service = *(uint *)((byte *)savedDispatcher + 0x10);
  if (service == 0) return 0;
  frame.descriptor[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.descriptor[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.descriptor[2] = 3;
  frame.descriptor[0] = R6GameServiceAddresses::PTR_LAB;
  cleanup.state = 1;
  InitializeCircularListSentinel(frame.descriptor + 4,(uint)(frame.cookieStorage + 3));
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  cleanup.state = 2;
  AppendClDataListSignedDecimal(frame.descriptor,&value);
  CommonRequestTransfer outgoing;
  frame.cloneScratch = (uint)&outgoing;
  CopyConstructClDataList(&outgoing,frame.descriptor,1);
  uint currentKey = key;
  uint currentValue = value;
  void *currentService = *(void **)((byte *)savedDispatcher + 0x10);
  using ConsumeABI = uint (__thiscall *)(void *,uint,uint,uint,uint,CommonRequestTransfer);
  uint consumed = ((ConsumeABI)R6GameServiceAddresses::ApplyIndexedKeyUpdate)(
      currentService,currentValue,currentKey,0x2e,2,outgoing);
  byte resultByte = (byte)consumed;
  frame.descriptor[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  cleanup.state = 3;
  key = (uint)(frame.descriptor + 3);
  frame.descriptor[3] = R6GameServiceAddresses::clDataListPTR_FUN2;
  cleanup.state = 4;
  InvokePointerListClearRange(frame.descriptor + 3);
  frame.headScratch = (uint)(frame.descriptor + 4);
  cleanup.state = 5;
  ReleaseListNodesRetainHeader(frame.descriptor + 4);
  void *currentHead = (void *)frame.descriptor[4];
  uint released = ReleaseMemoryIgnoringSize(currentHead,1);
  cleanup.armed = false;
  return (released & 0xffffff00u) | resultByte;
}

// Reset common request descriptor EBP-24 base after header constructor failure.
// R6GameService.dll @ 100675b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind18(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass cookie EBP-2d to genuine no-op59130, then predecessor0 descriptor base reset.
// R6GameService.dll @ 100675b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind28(void)
{
  __asm {
    lea    ecx,[ebp-0x2d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy completed common request descriptor EBP-24 fully; no predecessor.
// R6GameService.dll @ 100675c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind38(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor EBP-24 base after entered pointer-list/header cleanup.
// R6GameService.dll @ 100675c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind47(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT rewritten EBP+8 plus4, store EBP-28, then predecessor3 base reset.
// R6GameService.dll @ 100675d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind56(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch404
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch405
  Branch404:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch405:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Load saved head-context EBP-28 into ECX and tail genuine no-op59130; then predecessor3 without retry.
// R6GameService.dll @ 100675f7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl request_state_supportSharedLifetimeUnwind65(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select shared requests2c/46/9/2e six-state FuncInfo81cfc/map81ccc and tail CRT dispatch.
// R6GameService.dll @ 100675ff : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectCommonRequestsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::request_state_supportSharedLifetimeExceptionInfo8
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Load dispatcher POINTER from owner+158 and tail-forward scalar arguments; preserve raw upperEAX/exact AL.
// R6GameService.dll @ 10041140 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardRequest2cViaOffset158(void *owner,uint value,uint key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x158]
    jmp    R6GameServiceAddresses::SendSerializedRequest2c
  }
}

// Load dispatcher POINTER from owner+158 and tail-forward scalar arguments; preserve raw upperEAX/exact AL.
// R6GameService.dll @ 10041150 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardRequest46ViaOffset158(void *owner,uint value,uint key)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x158]
    jmp    R6GameServiceAddresses::SendSerializedRequest46
  }
}

// Forward full scalar words through owner+0x158 and return the raw serializer result; parameter names are inferred.
// R6GameService.dll @ 10041380 : complete native control/access order and raw ABI retained.
uint __thiscall DispatchSelector9ThroughOptionalChannel(void *owner,uint value,uint key,uint extraValue)
{
  void *dispatcher = *(void **)((uint)owner + 0x158);
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::SendSerializedRequest9)(dispatcher,value,key,extraValue);
}

// Forward full scalar words through owner+0x158 and return the raw serializer result; parameter names are inferred.
// R6GameService.dll @ 10041390 : complete native control/access order and raw ABI retained.
uint __thiscall DispatchSelector2eThroughOptionalChannel(void *owner,uint value,uint key)
{
  void *dispatcher = *(void **)((uint)owner + 0x158);
  using DispatchABI = uint (__thiscall *)(void *,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::SendSerializedRequest2e)(dispatcher,value,key);
}

// Literal shared request2c/46/9/2e cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081ccc : native storage identity retained.
const R6GameServiceNative::UnwindEntry request_state_supportSharedLifetimeUnwindMap8[6] = {
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind18},
  {0x0, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind28},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind38},
  {-1, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind47},
  {0x3, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind56},
  {0x3, R6GameServiceAddresses::request_state_supportSharedLifetimeUnwind65},
};

// Literal shared request2c/46/9/2e cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081cfc : native storage identity retained.
const R6GameServiceNative::FuncInfo request_state_supportSharedLifetimeExceptionInfo8 = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::request_state_supportSharedLifetimeUnwindMap8,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Guard service10, construct outer list/binary, replace byteCount bytes and append binary copy without status gates.
// Clone six words by value, overwrite count argument with clone address and send request2a/mode2 via current service.
// Disarm binary before conditional buffer free, then entered outer list cleanup; final cleanup upperEAX/AL0 or1.
// R6GameService.dll @ 10044bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendBinaryRequest2a(void *dispatcher,const byte *bytes,uint byteCount)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRequest2aEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    xor    ebp,ebp
    mov    eax,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esp+0xc],ebp
    cmp    eax,ebp
    je    Branch407
    mov    esi,R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],esi
    push    ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x50],ebp
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x28],esi
    push    ebp
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    ebp,R6GameServiceAddresses::clDataBinPTR_FUN
    mov    DWORD PTR [esp+0x28],ebp
    mov    eax,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x54]
    push    eax
    push    ecx
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x54],0x3
    call    R6GameServiceAddresses::ReplaceClDataBinBytes
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AppendClDataListBinaryCopy
    sub    esp,0x18
    lea    eax,[esp+0x28]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x70],esp
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    ecx,DWORD PTR [edi+0x10]
    push    0x2
    push    0x2a
    call    R6GameServiceAddresses::SendDescriptorAsD1
    test    al,al
    mov    DWORD PTR [esp+0x28],ebp
    je    Branch406
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x4c],0x4
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    DWORD PTR [esp+0x28],esi
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x4c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0x44]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0x44
    ret    0x8
  Branch406:
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x4c],0x6
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    DWORD PTR [esp+0x28],esi
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x4c],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
  Branch407:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    xor    al,al
    mov    DWORD PTR fs:0x0,ecx
    pop    ebp
    add    esp,0x44
    ret    0x8
  }
}

// Load dispatcher POINTER owner+158 and tail-forward byte pointer/count; retain complete cleanup upperEAX/AL.
// R6GameService.dll @ 100413a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchSelector2aThroughOptionalChannel(
    void *owner,const byte *bytes,uint byteCount)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x158]
    jmp    R6GameServiceAddresses::SendBinaryRequest2a
  }
}

// Reset request2a outer descriptor EBP-40 base after list construction failure.
// R6GameService.dll @ 10067690 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy request2a completed outer descriptor EBP-40 fully; no predecessor.
// R6GameService.dll @ 10067698 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset request2a binary EBP-28 base after triplet construction failure; then full outer predecessor1.
// R6GameService.dll @ 100676a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy request2a binary EBP-28 fully; then full outer predecessor1.
// R6GameService.dll @ 100676a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Reset request2a binary EBP-28 base after entered successful raw buffer release; then full outer predecessor1.
// R6GameService.dll @ 100676b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset request2a outer EBP-40 base after entered successful pointer-list destruction; no retry.
// R6GameService.dll @ 100676b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset request2a binary EBP-28 base after entered failed-send raw buffer release; then full outer predecessor1.
// R6GameService.dll @ 100676c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset request2a outer EBP-40 base after entered failed-send pointer-list destruction; no retry.
// R6GameService.dll @ 100676c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendBinaryRequest2aUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select request2a eight-state FuncInfo81e98/map81e58, preserving distinct success/failure cleanup states.
// R6GameService.dll @ 100676d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRequest2aEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendBinaryRequest2aExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal request2a cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081e58 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendBinaryRequest2aUnwindMap[8] = {
  {-1, R6GameServiceAddresses::SendBinaryRequest2aUnwind1},
  {-1, R6GameServiceAddresses::SendBinaryRequest2aUnwind2},
  {0x1, R6GameServiceAddresses::SendBinaryRequest2aUnwind3},
  {0x1, R6GameServiceAddresses::SendBinaryRequest2aUnwind4},
  {0x1, R6GameServiceAddresses::SendBinaryRequest2aUnwind5},
  {-1, R6GameServiceAddresses::SendBinaryRequest2aUnwind6},
  {0x1, R6GameServiceAddresses::SendBinaryRequest2aUnwind7},
  {-1, R6GameServiceAddresses::SendBinaryRequest2aUnwind8},
};

// Literal request2a cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081e98 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendBinaryRequest2aExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::SendBinaryRequest2aUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh d2, ignore list-copy status, then read current tag26/27 to mark pending or remove key records.
// Unknown tags still succeed; set dispatcher+19 only after pending call. Preserve raw cleanup upperEAX/AL.
// Retain distinct nine-state read-failure/entered-clear/head cleanup and CURRENT saved local context.
// R6GameService.dll @ 10045520 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessKeyRecordToken(void *dispatcher)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectKeyRecordTokenEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    push    0xd2
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],edi
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    cmp    DWORD PTR [esi+0x8],edi
    je    Branch410
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    edi
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x3c],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],edi
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x18]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x40],0x1
    call    R6GameServiceAddresses::CopyIndexedClDataList
    mov    edx,DWORD PTR [esi+0x8]
    xor    eax,eax
    mov    al,BYTE PTR [edx+0x4]
    sub    eax,0x26
    je    Branch412
    dec    eax
    jne    Branch414
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch408
    mov    DWORD PTR [esp+0x18],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x38],0x4
    jmp    Branch409
  Branch408:
    lea    edx,[esp+0xc]
    push    0x1
    push    edx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch411
    mov    DWORD PTR [esp+0x18],edi
    mov    ebx,0x5
    lea    eax,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x38],0x6
  Branch409:
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x38],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch410:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch411:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    call    R6GameServiceAddresses::NotifyAndRemoveKeyRecords
    jmp    Branch414
  Branch412:
    lea    eax,[esp+0xc]
    push    0x0
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch413
    mov    DWORD PTR [esp+0x18],edi
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch413:
    mov    ecx,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    call    R6GameServiceAddresses::MarkKeyRecordPending
    mov    BYTE PTR [esi+0x19],0x1
  Branch414:
    mov    DWORD PTR [esp+0x18],edi
    mov    ebx,0x7
    lea    edx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x38],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x38],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  }
}

// Build two lists, refresh3 and gate D1 reader/list1/nested list1; capture output pointers after refresh.
// Delimiter27 removes; other bytes parse integer0/uncapped text1/integer2 and update current service10.
// Forward full callee-ECX upper24/BYTE1a and integer-result upper16/WORD1c; final cleanup supplies upperEAX.
// R6GameService.dll @ 10045720 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ProcessIndexedTextUpdate(void *dispatcher,byte *delimiterOut,uint *keyOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectIndexedTextUpdateEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xbc
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push    edi
    mov    DWORD PTR [esp+0x2c],edi
    push    0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x48],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0xd4],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],edi
    push    0x0
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0xd8],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0xd4],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],edi
    push    0x3
    mov    ecx,esi
    mov    BYTE PTR [esp+0xd4],0x3
    call    R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    edi,DWORD PTR [esp+0xdc]
    mov    ebx,DWORD PTR [esp+0xd8]
    push    edi
    push    ebx
    push    0x3
    mov    ecx,esi
    call    R6GameServiceAddresses::CheckD1DescriptorAndOptionalIndex
    test    al,al
    je    Branch416
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x2c]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch416
    lea    edx,[esp+0x10]
    push    0x1
    push    edx
    lea    ecx,[esp+0x34]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch416
    mov    al,BYTE PTR [ebx]
    lea    ecx,[esp+0x10]
    cmp    al,0x27
    lea    eax,[esp+0xc]
    jne    Branch415
    push    0x1
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch416
    mov    ecx,DWORD PTR [edi]
    mov    edx,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    call    R6GameServiceAddresses::NotifyAndRemoveKeyRecords
    jmp    Branch419
  Branch415:
    push    0x0
    push    eax
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    je    Branch416
    lea    ecx,[esp+0x44]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x10]
    je    Branch417
    lea    edx,[esp+0x28]
    push    0x2
    push    edx
    call    R6GameServiceAddresses::ReadIndexedInt32
    test    al,al
    jne    Branch418
  Branch416:
    lea    ecx,[esp+0x10]
  Branch417:
    mov    BYTE PTR [esp+0xd0],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0xd0],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch420
  Branch418:
    mov    ax,WORD PTR [esi+0x1c]
    mov    cl,BYTE PTR [esi+0x1a]
    mov    edx,DWORD PTR [esp+0x28]
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esp+0x14]
    lea    eax,[esp+0x4c]
    push    edx
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    call    R6GameServiceAddresses::UpdateKeyedTextAndNotify
  Branch419:
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0xd0],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0xd0],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    al,0x1
  Branch420:
    mov    ecx,DWORD PTR [esp+0xc8]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xc8
    ret    0x8
  }
}

// Reset token outer descriptor EBP-24 base after constructor failure.
// R6GameService.dll @ 10067780 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy token completed outer descriptor EBP-24 fully; no predecessor.
// R6GameService.dll @ 10067788 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset token descriptor EBP-24 base after entered first removal-read failure head release.
// R6GameService.dll @ 10067790 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release token CURRENT local context EBP-28 plus4 via scratchEBP-34; predecessor3 base reset.
// R6GameService.dll @ 10067798 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch421
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch422
  Branch421:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch422:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset token descriptor EBP-24 base after entered second removal-read failure head release.
// R6GameService.dll @ 100677bf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release token CURRENT local context EBP-28 plus4 via scratchEBP-3c; predecessor5 base reset.
// R6GameService.dll @ 100677c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch423
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch424
  Branch423:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch424:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset token descriptor EBP-24 base after entered pending-read failure pointer-list destruction.
// R6GameService.dll @ 100677ee : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset token descriptor EBP-24 base after entered successful head release.
// R6GameService.dll @ 100677f6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release token CURRENT local context EBP-28 plus4 via scratchEBP-44; predecessor7 base reset.
// R6GameService.dll @ 100677fe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessKeyRecordTokenUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x28],0x0
    je    Branch425
    mov    eax,DWORD PTR [ebp-0x28]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch426
  Branch425:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch426:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset text-update outer EBP-a8 base after construction failure.
// R6GameService.dll @ 10067830 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessIndexedTextUpdateUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy text-update outer EBP-a8 fully.
// R6GameService.dll @ 1006783b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessIndexedTextUpdateUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset text-update nested EBP-c4 base after construction failure, then outer predecessor1.
// R6GameService.dll @ 10067846 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessIndexedTextUpdateUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy text-update nested EBP-c4 fully, then outer predecessor1.
// R6GameService.dll @ 10067851 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ProcessIndexedTextUpdateUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select token nine-state FuncInfo82008/map81fc0.
// R6GameService.dll @ 10067825 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyRecordTokenEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessKeyRecordTokenExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select indexed-text four-state FuncInfo82044/map82024.
// R6GameService.dll @ 1006785c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectIndexedTextUpdateEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessIndexedTextUpdateExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal token/text parent cleanup map/FuncInfo words.
// R6GameService.dll data @ 10081fc0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessKeyRecordTokenUnwindMap[9] = {
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind1},
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind2},
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind3},
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind4},
  {0x3, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind5},
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind6},
  {0x5, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind7},
  {-1, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind8},
  {0x7, R6GameServiceAddresses::ProcessKeyRecordTokenUnwind9},
};

// Literal token/text parent cleanup map/FuncInfo words.
// R6GameService.dll data @ 10082008 : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessKeyRecordTokenExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::ProcessKeyRecordTokenUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal token/text parent cleanup map/FuncInfo words.
// R6GameService.dll data @ 10082024 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessIndexedTextUpdateUnwindMap[4] = {
  {-1, R6GameServiceAddresses::ProcessIndexedTextUpdateUnwind1},
  {-1, R6GameServiceAddresses::ProcessIndexedTextUpdateUnwind2},
  {0x1, R6GameServiceAddresses::ProcessIndexedTextUpdateUnwind3},
  {0x1, R6GameServiceAddresses::ProcessIndexedTextUpdateUnwind4},
};

// Literal token/text parent cleanup map/FuncInfo words.
// R6GameService.dll data @ 10082044 : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessIndexedTextUpdateExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ProcessIndexedTextUpdateUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
