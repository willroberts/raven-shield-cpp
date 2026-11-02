#include "native_addresses.h"
#include "native_records.h"

// clPlayerResults name is recovered from primary table77d88/COL79bac; original member spellings inferred.

// Destroy clPlayerResults first, then read CURRENT flag lowBYTE/bit0 to optionally free original owner.
// RET4/owner EAX; no own guard or allocation retry.
// R6GameService.dll @ 10041610 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyServiceLinkedRecordContainerDeletingDestructor(void *owner,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyServiceLinkedRecordContainer
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Install clPlayerResults table77d88, use tree slot+8/count+c; nonzero count drains nodes, resets live header/count.
// Free CURRENT header without clearing slot; state0 stays armed through final free. Raw allocator EAX/RET0.
// Inherited cleanup frame is original entryESP, saved tree slot at-10; repeated free after failure remains possible.
// R6GameService.dll @ 10041630 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceLinkedRecordContainer(undefined4 *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCollectionEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   edi
    lea    edi,[ecx+0x8]
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clPlayerResultsVTable
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test   eax,eax
    je     Branch4
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je     Branch3
    push   ebx
  Branch2:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseLinkedNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push   0x1
    push   esi
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch2
    pop    ebx
  Branch3:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch4:
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Copy-construct clPlayerResults: optional base table4, internal offset table14, allocate/publish unchecked head.
// Arm state0 after cached source flag/head read; clone pairs, derive extrema via current destination head.
// Source/count slot cached, scalar source reloaded from argument only on nonempty path; sequential late18..30 copy.
// Primary77d88 last; RET8/owner EAX. Shared state0 frees CURRENT head only; no old-state destruction or rollback.
// R6GameService.dll @ 10056070 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall AssignIndexedRecord(void *owner,const void *source,uint initializeBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ordered_tree_support_SelectCollectionEH2
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    mov    DWORD PTR [esp+0x0],0x0
    mov    eax,DWORD PTR [esp+0x18]
    push   ebx
    push   ebp
    push   esi
    push   edi
    test   eax,eax
    mov    ebx,ecx
    je     Branch5
    mov    DWORD PTR [ebx+0x4],0x100780bc
  Branch5:
    mov    ebp,DWORD PTR [esp+0x24]
    lea    esi,[ebx+0x8]
    lea    eax,[esp+0x28]
    mov    DWORD PTR [esp+0x10],esi
    lea    edi,[ebp+0x8]
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esi+0xc],0x100780b4
    call   R6GameServiceAddresses::ForwardStackWord
    push   0x0
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    dl,BYTE PTR [edi+0x8]
    mov    BYTE PTR [esi+0x8],dl
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x1c],ecx
    cmp    DWORD PTR [edx+0x4],ecx
    mov    BYTE PTR [eax],cl
    jne    Branch6
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],ecx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    jmp    Branch11
  Branch6:
    mov    ecx,DWORD PTR [edi]
    mov    ebp,DWORD PTR [esi]
    push   ebp
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtree
    mov    DWORD PTR [ebp+0x4],eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch8
  Branch7:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch7
  Branch8:
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    test   eax,eax
    je     Branch10
  Branch9:
    mov    ecx,eax
    mov    eax,DWORD PTR [ecx+0xc]
    test   eax,eax
    jne    Branch9
  Branch10:
    mov    ebp,DWORD PTR [esp+0x24]
    mov    DWORD PTR [edx+0xc],ecx
  Branch11:
    mov    eax,DWORD PTR [edi+0x4]
    lea    ecx,[ebp+0x18]
    mov    DWORD PTR [esi+0x4],eax
    lea    edx,[ebx+0x18]
    mov    eax,DWORD PTR [ecx]
    pop    edi
    mov    DWORD PTR [edx],eax
    pop    esi
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [edx+0x8],eax
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [edx+0xc],ecx
    mov    edx,DWORD PTR [ebp+0x28]
    mov    DWORD PTR [ebx+0x28],edx
    mov    eax,DWORD PTR [ebp+0x2c]
    mov    DWORD PTR [ebx+0x2c],eax
    mov    ecx,DWORD PTR [ebp+0x30]
    mov    DWORD PTR [ebx+0x30],ecx
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [ebx],R6GameServiceAddresses::clPlayerResultsVTable
    mov    eax,ebx
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Construct empty clPlayerResults, testing full initial flag but storing CURRENT low byte after allocation.
// Head unchecked, live default text copied through NUL at18 without bound, count words28/2c clear before copy,30 after.
// Offset tables4/14 and primary77d88 retained; padding/head bytes untouched; RET4/owner/current scratch ECX, no own EH.
// R6GameService.dll @ 10056410 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeIndexedValueCollection(void *owner,uint initializeBase)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    xor    ebx,ebx
    push   esi
    cmp    eax,ebx
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],ebx
    je     Branch12
    mov    DWORD PTR [esi+0x4],0x100780bc
  Branch12:
    push   0x18
    mov    DWORD PTR [esi+0x14],0x100780b4
    mov    DWORD PTR [esi+0x8],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x10]
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],ebx
    mov    BYTE PTR [esi+0x10],cl
    mov    BYTE PTR [eax],bl
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edx+0x4],ebx
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esi+0x18]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    mov    DWORD PTR [esi+0x28],ebx
    mov    DWORD PTR [esi+0x2c],ebx
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPlayerResultsVTable
    sub    edx,eax
  Branch13:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    cmp    cl,bl
    jne    Branch13
    mov    DWORD PTR [esi+0x30],ebx
    mov    eax,esi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Update unsigned max28/first-seen low-five-bit counter2c/bitmap30 BEFORE tree search/allocation.
// Cached initial key/value pair feeds insert; duplicate path re-reads original key/value arguments and may retry.
// No own EH or owned temporary; raw insertion/stack-pair/node EAX residues retained, RET8; names descriptive.
// R6GameService.dll @ 10056490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RecordIndexedWordValue(void *owner,uint key,uint value)
{
  __asm {
    sub    esp,0x20
    mov    edx,ecx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [edx+0x28]
    push   ebx
    push   ebp
    push   esi
    cmp    ecx,eax
    push   edi
    jbe    Branch14
    mov    DWORD PTR [edx+0x28],ecx
  Branch14:
    mov    eax,DWORD PTR [edx+0x30]
    mov    esi,0x1
    shl    esi,cl
    test   esi,eax
    jne    Branch15
    inc    DWORD PTR [edx+0x2c]
  Branch15:
    or     eax,esi
    lea    ebx,[edx+0x8]
    mov    DWORD PTR [edx+0x30],eax
    mov    eax,DWORD PTR [esp+0x38]
    mov    ebp,DWORD PTR [ebx]
    mov    DWORD PTR [esp+0x20],ecx
    mov    DWORD PTR [esp+0x24],eax
    mov    edi,ebp
    mov    esi,DWORD PTR [ebp+0x4]
    mov    dl,0x1
    test   esi,esi
    je     Branch19
  Branch16:
    mov    edx,DWORD PTR [esi+0x10]
    mov    edi,esi
    cmp    ecx,edx
    setb   dl
    test   dl,dl
    je     Branch17
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch18
  Branch17:
    mov    esi,DWORD PTR [esi+0xc]
  Branch18:
    test   esi,esi
    jne    Branch16
  Branch19:
    mov    eax,edi
    test   dl,dl
    mov    DWORD PTR [esp+0x14],eax
    je     Branch21
    cmp    edi,DWORD PTR [ebp+0x8]
    jne    Branch20
    lea    ecx,[esp+0x20]
    push   0x0
    push   ecx
    push   edi
    lea    edx,[esp+0x28]
    push   esi
    push   edx
    mov    ecx,ebx
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x20
    ret    0x8
  Branch20:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],eax
  Branch21:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [eax+0x10]
    cmp    edx,ecx
    jae    Branch22
    lea    edx,[esp+0x12]
    lea    eax,[esp+0x20]
    push   edx
    push   0x0
    push   eax
    push   edi
    lea    ecx,[esp+0x28]
    push   esi
    push   ecx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x2a],0x1
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    jmp    Branch23
  Branch22:
    lea    edx,[esp+0x13]
    mov    BYTE PTR [esp+0x13],0x0
    push   edx
    lea    eax,[esp+0x18]
  Branch23:
    lea    ecx,[esp+0x2c]
    push   eax
    call   R6GameServiceAddresses::ConstructWordBytePair
    mov    al,BYTE PTR [esp+0x2c]
    test   al,al
    jne    Branch26
    lea    ecx,[esp+0x34]
    lea    edx,[esp+0x14]
    push   ecx
    push   edx
    mov    ecx,ebx
    call   R6GameServiceAddresses::FindUnsignedTreeLowerBound
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [ebx]
    cmp    eax,ecx
    mov    ecx,DWORD PTR [esp+0x34]
    je     Branch24
    cmp    ecx,DWORD PTR [eax+0x10]
    jae    Branch25
  Branch24:
    lea    eax,[esp+0x14]
    mov    DWORD PTR [esp+0x28],ecx
    push   eax
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x0
    call   R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x28]
    lea    edx,[esp+0x18]
    push   ecx
    push   ecx
    mov    ecx,esp
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    lea    eax,[esp+0x24]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::FindOrInsertUnsignedTreeNodeNearHint
    mov    eax,DWORD PTR [esp+0x1c]
  Branch25:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR [eax+0x14],ecx
  Branch26:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x20
    ret    0x8
  }
}

// Reset the destination member list, then append label, three signed decimals and a nested list of ordered values.
// clPlayerResults receiver is supported by node+1c callers and its existing tree/label/scalar layout.
// ENTRY ESP S: temporary clDataList S-24/member S-18/head slot S-14, state S-4; RET4/cached destination EAX.
// Successor links and owner head reload after each append. Original destination argument becomes member scratch
// before range cleanup; state3 releases current scratch+4 storage, state2 only resets the clData base table.
// R6GameService.dll @ 100565f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendIndexedValuesToDescriptor(void *owner,void *destination)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectPlayerResultsAppendEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push   ebp
    mov    DWORD PTR [esp+0x4],0x0
    mov    ebp,DWORD PTR [esp+0x30]
    push   esi
    push   edi
    mov    edi,ecx
    test   ebp,ebp
    jne    Branch27
    xor    eax,eax
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0x28
    ret    0x4
  Branch27:
    mov    eax,DWORD PTR [ebp+0xc]
    lea    ecx,[ebp+0xc]
    call   DWORD PTR [eax+0x4]
    lea    ecx,[edi+0x18]
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendClDataListString
    lea    edx,[edi+0x28]
    mov    ecx,ebp
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[edi+0x2c]
    mov    ecx,ebp
    push   eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[edi+0x30]
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x0
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    eax,DWORD PTR [edi+0x8]
    mov    DWORD PTR [esp+0x30],0x1
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch34
  Branch28:
    lea    edx,[esi+0x14]
    lea    ecx,[esp+0x10]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    test   ecx,ecx
    je     Branch30
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch33
  Branch29:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch29
    jmp    Branch33
  Branch30:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch32
  Branch31:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch31
  Branch32:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch33
    mov    eax,ecx
  Branch33:
    mov    ecx,DWORD PTR [edi+0x8]
    mov    esi,eax
    cmp    eax,ecx
    jne    Branch28
  Branch34:
    lea    eax,[esp+0x10]
    mov    ecx,ebp
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x38],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    edx,DWORD PTR [esp+0x20]
    push   ecx
    mov    eax,esp
    push   ecx
    push   esp
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x3c],0x3
    mov    DWORD PTR [eax],edx
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    edx,DWORD PTR [esp+0x24]
    lea    eax,[esp+0x14]
    push   eax
    lea    ecx,[esp+0x28]
    call   DWORD PTR [edx+0x10]
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    mov    eax,ebp
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebp
    add    esp,0x28
    ret    0x4
  }
}

// Reset the incomplete temporary clDataList base at parent ENTRY ESP-24.
// R6GameService.dll @ 10069280 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendIndexedValuesToDescriptorUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed temporary clDataList at parent ENTRY ESP-24 through its actual alias.
// R6GameService.dll @ 10069288 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendIndexedValuesToDescriptorUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the temporary base after normal member destruction, without retrying its storage cleanup.
// R6GameService.dll @ 10069290 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendIndexedValuesToDescriptorUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release storage through current overwritten argument+4; preserve native null forwarding and frame scratch-5c.
// R6GameService.dll @ 10069298 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendIndexedValuesToDescriptorUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je     Branch35
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x5c],eax
    jmp    Branch36
  Branch35:
    mov    DWORD PTR [ebp-0x5c],0x0
  Branch36:
    mov    ecx,DWORD PTR [ebp-0x5c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the descriptor-appender four-state metadata and tail current CRT dispatch.
// R6GameService.dll @ 100692bf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectPlayerResultsAppendEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AppendIndexedValuesToDescriptorExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal descriptor-appender unwind map or FuncInfo; previous states and action addresses retained.
// R6GameService.dll data @ 10083d88 : native storage identity retained.
const R6GameServiceNative::UnwindEntry AppendIndexedValuesToDescriptorUnwindMap[4] = {
  {-1, R6GameServiceAddresses::AppendIndexedValuesToDescriptorUnwind1},
  {-1, R6GameServiceAddresses::AppendIndexedValuesToDescriptorUnwind2},
  {-1, R6GameServiceAddresses::AppendIndexedValuesToDescriptorUnwind3},
  {0x2, R6GameServiceAddresses::AppendIndexedValuesToDescriptorUnwind4},
};

// Literal descriptor-appender unwind map or FuncInfo; previous states and action addresses retained.
// R6GameService.dll data @ 10083d88 : native storage identity retained.
const R6GameServiceNative::FuncInfo AppendIndexedValuesToDescriptorExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::AppendIndexedValuesToDescriptorUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clPlayerResultsVTable
// R6GameService.dll data @ 10077d88 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPlayerResultsVTableRecord {
  R6GameServiceNative::Address DestroyServiceLinkedRecordContainerDeletingDestructor; // +0x00
};
const clPlayerResultsVTableRecord clPlayerResultsVTable = {
  R6GameServiceAddresses::DestroyServiceLinkedRecordContainerDeletingDestructor,
};
