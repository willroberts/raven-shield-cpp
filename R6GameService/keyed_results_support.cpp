#include "native_addresses.h"
#include "native_records.h"

// Borrowed/owning keyed-result pair helpers; concrete whole-pair class identities remain unresolved.

// Construct borrowed raw-key plus clPlayerResults pair; original output argument becomes tree-slot scratch.
// Inline pair-tree clone has late/cached source distinctions; state0 frees CURRENT header only, not raw key.
// Caller cleans three physical words; original output EAX, primary class table at output4 installed last.
// R6GameService.dll @ 10055f40 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ConstructIndexedRecordCopy(void *output,const char *const *keyRef,const void *results)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::keyed_results_support_SelectKeyedResultsEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    mov    eax,DWORD PTR [esp+0x18]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x20]
    push   ebp
    mov    ecx,DWORD PTR [eax]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x24]
    lea    ebp,[ebx+0x8]
    lea    edx,[esp+0x28]
    lea    esi,[edi+0xc]
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [edi+0x8],0x100780bc
    push   edx
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x28],esi
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
    mov    dl,BYTE PTR [ebp+0x8]
    mov    BYTE PTR [esi+0x8],dl
    mov    edx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [esp+0x1c],ecx
    cmp    DWORD PTR [edx+0x4],ecx
    mov    BYTE PTR [eax],cl
    jne    Branch1
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x4],ecx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    jmp    Branch6
  Branch1:
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    ebx,DWORD PTR [esi]
    push   ebx
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::ordered_tree_support_CloneOrderedTreeSubtree
    mov    DWORD PTR [ebx+0x4],eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch3
  Branch2:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch2
  Branch3:
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [ecx+0xc]
    test   eax,eax
    je     Branch5
  Branch4:
    mov    ecx,eax
    mov    eax,DWORD PTR [ecx+0xc]
    test   eax,eax
    jne    Branch4
  Branch5:
    mov    ebx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx+0xc],ecx
  Branch6:
    mov    eax,DWORD PTR [ebp+0x4]
    lea    ecx,[ebx+0x18]
    mov    DWORD PTR [esi+0x4],eax
    lea    edx,[edi+0x1c]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [edx+0x8],eax
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [edx+0xc],ecx
    mov    edx,DWORD PTR [ebx+0x28]
    mov    DWORD PTR [edi+0x2c],edx
    mov    eax,DWORD PTR [ebx+0x2c]
    mov    DWORD PTR [edi+0x30],eax
    mov    ecx,DWORD PTR [ebx+0x30]
    mov    DWORD PTR [edi+0x34],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edi+0x4],R6GameServiceAddresses::clPlayerResultsVTable
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroy owning-string/clPlayerResults pair: class table+c, tree slot14/count18, clear nodes, free header,
// then free CURRENT string at0. State1 header->state0 string cleanup; slots stay dangling, raw free EAX/RET0.
// R6GameService.dll @ 100415a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceTreeRecord(void *record)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectKeyedResultsEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x8],esi
    lea    edi,[esi+0x14]
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clPlayerResultsVTable
    mov    DWORD PTR [esp+0xc],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x18],0x1
    call   R6GameServiceAddresses::ReleaseNestedServiceLinkedEntries
    mov    ecx,edi
    mov    BYTE PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10069200 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl keyed_results_support_UnwindKeyedResults2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10066e10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl UnwindKeyedResults(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10066e18 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl keyed_results_support_UnwindKeyedResults(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact keyed-result/pair frame map and tail current CRT dispatch.
// R6GameService.dll @ 10069208 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl keyed_results_support_SelectKeyedResultsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructIndexedRecordCopyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact keyed-result/pair frame map and tail current CRT dispatch.
// R6GameService.dll @ 10066e20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyedResultsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceTreeRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}



// R6GameService.dll data @ 10083c64 : exact keyed-result/pair unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry ConstructIndexedRecordCopyUnwindMap[1] = {
  {-1, R6GameServiceAddresses::keyed_results_support_UnwindKeyedResults2},
};

// R6GameService.dll data @ 10083c6c : exact keyed-result/pair unwind map or FuncInfo.
// R6GameService.dll data @ 10083c64 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructIndexedRecordCopyExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ConstructIndexedRecordCopyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 100814fc : exact keyed-result/pair unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry DestroyServiceTreeRecordUnwindMap[2] = {
  {-1, R6GameServiceAddresses::UnwindKeyedResults},
  {0x0, R6GameServiceAddresses::keyed_results_support_UnwindKeyedResults},
};

// R6GameService.dll data @ 1008150c : exact keyed-result/pair unwind map or FuncInfo.
// R6GameService.dll data @ 100814fc : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceTreeRecordExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyServiceTreeRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroy owning string/class pair, then test CURRENT deleting flag low byte before optional cdecl allocator free.
// Whole pair identity unresolved; original receiver EAX/RET4, no own exception registration.
// R6GameService.dll @ 10041580 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DestroyServiceTreeRecordDeletingDestructor(void *pair,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyServiceTreeRecord
    test   BYTE PTR [esp+0x8],0x1
    je     Branch7
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch7:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// If list160 is absent, allocate32-byte container and unchecked80-byte tree head; publish late caller value and owner slot.
// Existing list returns incoming upperEAX/AL0; null first allocation still publishes null and returns AL1.
// The head mode BYTE and full metadata DWORD are separate late reads of value; no own EH/rollback.
// R6GameService.dll @ 10041160 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CreateServiceRecordList(void *owner,uint value)
{
  __asm {
    push   ecx
    push   ebx
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x8],ebx
    cmp    DWORD PTR [edi+0x160],ebx
    je    Branch8
    pop    edi
    xor    al,al
    pop    ebx
    pop    ecx
    ret    0x4
  Branch8:
    push   esi
    push   0x20
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    cmp    esi,ebx
    je    Branch9
    mov    DWORD PTR [esi+0x4],0x10077d64
    push   0x50
    mov    DWORD PTR [esi+0x14],0x10077d5c
    mov    DWORD PTR [esi+0x8],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0x14]
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],ebx
    mov    BYTE PTR [esi+0x10],cl
    mov    BYTE PTR [eax],bl
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edx+0x4],ebx
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esi+0x18],eax
    mov    DWORD PTR [esi+0x1c],ebx
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMatchResultsVTable
    mov    DWORD PTR [edi+0x160],esi
    pop    esi
    pop    edi
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0x4
  Branch9:
    xor    esi,esi
    mov    al,0x1
    mov    DWORD PTR [edi+0x160],esi
    pop    esi
    pop    edi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Update through captured current list160; absent leaves incoming upperEAX/AL0, otherwise child upperEAX/AL1.
// Capture caller words in native order, ignore update status and retain RET0c; no own lifetime guard.
// R6GameService.dll @ 10041200 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall UpdateServiceRecordByKey(void *owner,char *key,uint keyLength,uint value)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x160]
    test   ecx,ecx
    jne    Branch10
    xor    al,al
    ret    0xc
  Branch10:
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    mov    eax,DWORD PTR [esp+0x8]
    push   edx
    push   eax
    call   R6GameServiceAddresses::UpdateStringKeyedRecord
    mov    al,0x1
    ret    0xc
  }
}

// Build a heap descriptor if list160 exists; append CURRENT records, dispatch late arguments/context, then delete captured descriptor.
// Save raw childAL across destruction, retain destructor upperEAX and unchecked head allocation; no own EH/rollback.
// R6GameService.dll @ 10041230 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall BuildAndDispatchStoredRecordRequest(void *owner,uint requestWord,int contextValue)
{
  __asm {
    push   ecx
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [edi+0x160]
    mov    DWORD PTR [esp+0xc],ebx
    cmp    eax,ebx
    jne    Branch12
  Branch11:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    pop    ecx
    ret    0x8
  Branch12:
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    cmp    esi,ebx
    je    Branch11
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esi+0x14],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esi+0x8],0x3
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    push   0xc
    mov    DWORD PTR [esi+0x10],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [edi+0x160]
    push   esi
    call   R6GameServiceAddresses::AppendOrderedRecordsToDescriptor
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    push   esi
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [edi+0x158]
    call   R6GameServiceAddresses::DispatchRequest1e
    mov    edx,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    mov    bl,al
    call   DWORD PTR [edx]
    pop    edi
    mov    al,bl
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Release every stored subtree and record, then destroy the object at +0x160.
// Clear captured list160 tree by right-recursion/left-chain, then delete CURRENT list160 and clear its slot only after return.
// Keep count0 skip, per-store current head reload, saved outer owner, raw final upperEAX/AL1 and no parent cleanup.
// R6GameService.dll @ 100412e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceRecordList(void *owner)
{
  __asm {
    push   ecx
    push   ebx
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x4],ebx
    mov    eax,DWORD PTR [ebx+0x160]
    test   eax,eax
    jne    Branch13
    xor    al,al
    pop    ebx
    pop    ecx
    ret
  Branch13:
    push   edi
    lea    edi,[eax+0x8]
    mov    eax,DWORD PTR [eax+0xc]
    test   eax,eax
    je    Branch16
    mov    eax,DWORD PTR [edi]
    push   esi
    mov    esi,DWORD PTR [eax+0x4]
    test   esi,esi
    je    Branch15
  Branch14:
    mov    ecx,DWORD PTR [esi+0xc]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseServiceTreeSubtree
    mov    ebx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    call   R6GameServiceAddresses::DestroyServiceTreeRecord
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    esi,ebx
    jne    Branch14
    mov    ebx,DWORD PTR [esp+0xc]
  Branch15:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch16:
    mov    ecx,DWORD PTR [ebx+0x160]
    pop    edi
    test   ecx,ecx
    je    Branch17
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch17:
    mov    DWORD PTR [ebx+0x160],0x0
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret
  }
}

// R6GameService.dll @ 100414a0 : DestroyServiceTreeStorageDeletingDestructor
// Destroys the tree-storage subobject and optionally frees its allocation.
void * __thiscall DestroyServiceTreeStorageDeletingDestructor(void *this,byte deleteFlag)
{
  SetServiceTreeStorageVtable(this);
  if ((deleteFlag & 1) != 0) {
    TailFreeThroughGlobalAllocator(this);
  }
  return this;
}

// R6GameService.dll @ 100414c0 : SetServiceTreeStorageVtable
// Installs the tree-storage destructor vtable.
void __fastcall SetServiceTreeStorageVtable(undefined4 *storage)
{
  *storage = &keyed_results_supportPTR_LAB;
  return;
}

// Release the record payload and conditionally notify its stored owner.
// Release captured payload4 and its child, then read CURRENT ownershipBYTE14/owner10 for virtual-base-adjusted delete1.
// Leave slots unchanged and preserve native return/register residue; no own EH or stronger ownership guarantee.
// R6GameService.dll @ 100414f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall ReleaseServiceTreeRecord(void *record)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x4]
    test   esi,esi
    je    Branch18
    mov    ecx,esi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch18:
    mov    al,BYTE PTR [edi+0x14]
    test   al,al
    jne    Branch19
    mov    eax,DWORD PTR [edi+0x10]
    test   eax,eax
    je    Branch19
    mov    ecx,DWORD PTR [eax+0x4]
    push   0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call   DWORD PTR [eax]
  Branch19:
    pop    edi
    pop    esi
    ret
  }
}

// Destroy/free captured cache14, clear only after return, then use CURRENT queue10/full selector and publish pointer.
// No own EH; callback replacement is cleared, and queue/publication failure retains completed prior effects.
// R6GameService.dll @ 10041d70 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ReplaceServiceRecordBySelector(void *owner,uint selector)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x14]
    test   esi,esi
    je    Branch20
    mov    ecx,esi
    call   R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [edi+0x14],0x0
  Branch20:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [edi+0x10]
    push   eax
    call   R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    DWORD PTR [edi+0x14],eax
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Construct outer list before cache read, gate CC/WORD26-or27, copied selector WORD and optional nested scalar AL.
// Preserve current cache/selector/marker/output phases, pre-state1 head leak, disarmed output gap and raw AL/EAX.
// R6GameService.dll @ 10041db0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TryReadServiceRecordTagAndValue(
    void *owner,uint selector,byte *recordTag,int *value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectServiceRecordReaderEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x3c
    push   ebp
    push   esi
    mov    esi,ecx
    push   0x0
    mov    DWORD PTR [esp+0x14],0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],0x0
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],ebp
    mov    eax,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esp+0x4c],0x1
    test   eax,eax
    je    Branch24
    movzx  cx,BYTE PTR [eax+0x4]
    cmp    cx,0xcc
    mov    DWORD PTR [esp+0xc],ecx
    jne    Branch24
    lea    ecx,[esp+0xc]
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch24
    mov    eax,DWORD PTR [esp+0xc]
    cmp    ax,0x26
    je    Branch21
    cmp    ax,0x27
    jne    Branch24
  Branch21:
    mov    eax,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    mov    ecx,DWORD PTR [eax+0x8]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch24
    lea    ecx,[esp+0xa]
    push   0x0
    push   ecx
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch24
    mov    dx,WORD PTR [esp+0xa]
    cmp    dx,WORD PTR [esp+0x54]
    je    Branch22
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],ebp
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x4c],0x2
    call   R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x48
    ret    0xc
  Branch22:
    cmp    WORD PTR [esp+0xc],0x27
    jne    Branch26
    push   0x0
    push   0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x3
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],ebp
    mov    DWORD PTR [esp+0x2c],esi
    lea    eax,[esp+0x2c]
    push   0x1
    push   eax
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x54],0x4
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch23
    lea    ecx,[esp+0x10]
    push   0x0
    push   ecx
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::ReadIndexedInt32
    test   al,al
    jne    Branch25
  Branch23:
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x4c],0x1
    call   R6GameServiceAddresses::DestroyClDataList
  Branch24:
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    pop    esi
    xor    al,al
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x48
    ret    0xc
  Branch25:
    mov    DWORD PTR [esp+0x2c],esi
    mov    DWORD PTR [esp+0x38],ebp
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x5
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
  Branch26:
    mov    edx,DWORD PTR [esp+0x58]
    mov    al,BYTE PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    mov    BYTE PTR [edx],al
    mov    edx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ecx],edx
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x44]
    pop    esi
    mov    al,0x1
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x48
    ret    0xc
  }
}

// Return full zero for missing queue8; otherwise tail current queue to native pop with raw pointer/EAX preserved.
// R6GameService.dll @ 10041fe0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall PopPendingServiceRecord(void *owner)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x8]
    test   ecx,ecx
    je    Branch27
    jmp    R6GameServiceAddresses::PopQueuedRecord
  Branch27:
    xor    eax,eax
    ret
  }
}

// Construct four lists before refresh1/reader; quote queues missing request but returns AL0, plain walks records.
// Preserve retained WORD high lanes, adjacent unbounded text destinations, late helper inputs and raw update AL.
// R6GameService.dll @ 10041ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ApplySelectorOneServiceResponse(void *owner,char *recordTag,int *value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSelectorOneResponseEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x118
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   edi
    mov    DWORD PTR [esp+0x80],edi
    push   0x3
    lea    ecx,[esp+0x68]
    mov    DWORD PTR [esp+0x6c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x7c],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   edi
    lea    ecx,[esp+0x70]
    mov    DWORD PTR [esp+0x134],edi
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x60],ebp
    mov    DWORD PTR [esp+0x6c],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x138],0x1
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x134],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x50]
    mov    BYTE PTR [esp+0x138],0x3
    mov    DWORD PTR [esp+0x54],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x64],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x58]
    mov    BYTE PTR [esp+0x134],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x48],ebp
    mov    DWORD PTR [esp+0x54],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x138],0x5
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x4c],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x134],0x6
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    push   0x1
    mov    ecx,esi
    mov    BYTE PTR [esp+0x134],0x7
    call   R6GameServiceAddresses::ReplaceServiceRecordBySelector
    mov    eax,DWORD PTR [esp+0x13c]
    mov    edi,DWORD PTR [esp+0x138]
    push   eax
    push   edi
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::TryReadServiceRecordTagAndValue
    test   al,al
    jne    Branch29
  Branch28:
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x130],0x5
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x130],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x130],0x1
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x130],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch37
  Branch29:
    mov    edx,DWORD PTR [esi+0x14]
    lea    ecx,[esp+0x60]
    push   0x1
    push   ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch28
    lea    eax,[esp+0x18]
    push   0x1
    push   eax
    lea    ecx,[esp+0x68]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch28
    mov    al,BYTE PTR [edi]
    lea    ecx,[esp+0x80]
    cmp    al,0x27
    jne    Branch34
    push   0x1
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyIndexedClDataString
    test   al,al
    je    Branch28
    lea    edx,[esp+0x14]
    push   0x2
    push   edx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    jne    Branch30
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x130],0x5
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x130],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    jmp    Branch33
  Branch30:
    lea    eax,[esp+0x10]
    push   0x3
    push   eax
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch31
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x14]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x84]
    push   edx
    push   eax
    call   R6GameServiceAddresses::QueueMissingNestedRecordRequest
  Branch31:
    lea    ecx,[esp+0x30]
  Branch32:
    mov    BYTE PTR [esp+0x130],0x5
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x130],0x3
    call   R6GameServiceAddresses::DestroyClDataListAlias
  Branch33:
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x130],0x1
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x130],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataListAlias
    xor    al,al
    jmp    Branch37
  Branch34:
    push   0x0
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyIndexedClDataString
    test   al,al
    je    Branch31
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch31
    lea    eax,[esp+0x10]
    push   0x2
    push   eax
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch31
    lea    ecx,[esp+0x48]
    push   0x3
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch31
    lea    edx,[esp+0x30]
    push   0x0
    push   edx
    lea    ecx,[esp+0x50]
    mov    edi,0x1
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch36
  Branch35:
    lea    eax,[esp+0x78]
    push   0x0
    push   eax
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch31
    lea    ecx,[esp+0xa4]
    push   0x1
    push   ecx
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::CopyIndexedClDataString
    test   al,al
    lea    ecx,[esp+0x30]
    je    Branch32
    lea    edx,[esp+0x7c]
    push   0x2
    push   edx
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch31
    mov    eax,DWORD PTR [esp+0x7c]
    mov    edx,DWORD PTR [esp+0x78]
    lea    ecx,[esp+0xa4]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   edx
    call   R6GameServiceAddresses::EnsureOuterRecordExists
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x14]
    push   eax
    mov    eax,DWORD PTR [esp+0x7c]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x88]
    push   0x0
    push   edx
    push   eax
    call   R6GameServiceAddresses::AddNestedRecordForZeroLookup
    mov    eax,edi
    lea    ecx,[esp+0x30]
    push   eax
    push   ecx
    lea    ecx,[esp+0x50]
    inc    edi
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    jne    Branch35
  Branch36:
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x14]
    push   edx
    lea    ecx,[esp+0x84]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::ApplyNestedRecordUpdateByTextPair
    lea    ecx,[esp+0x30]
    mov    bl,al
    mov    BYTE PTR [esp+0x130],0x5
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x130],0x3
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x130],0x1
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x130],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataListAlias
    mov    al,bl
  Branch37:
    mov    ecx,DWORD PTR [esp+0x128]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x124
    ret    0x8
  }
}

// Build four lists before refresh2/reader, copy two levels, then branch on captured output pointer CURRENT byte.
// Quote flush returns AL0 even after effect; plain forwards sender AL byte, with final cleanup upperEAX retained.
// R6GameService.dll @ 10042430 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ApplySelectorTwoServiceResponse(void *owner,char *recordTag,int *value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSelectorTwoResponseEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x64
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    mov    ebx,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    push   edi
    mov    DWORD PTR [esp+0x14],edi
    push   0x3
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x48],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   edi
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x80],edi
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x84],0x1
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x80],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x64]
    mov    BYTE PTR [esp+0x84],0x3
    mov    DWORD PTR [esp+0x68],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x78],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x6c]
    mov    BYTE PTR [esp+0x80],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x5c],ebp
    mov    DWORD PTR [esp+0x68],edi
    push   0x0
    push   0x3
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x84],0x5
    mov    DWORD PTR [esp+0x50],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x60],ebx
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x80],0x6
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x44],ebp
    mov    DWORD PTR [esp+0x50],edi
    push   0x2
    mov    ecx,esi
    mov    BYTE PTR [esp+0x80],0x7
    call   R6GameServiceAddresses::ReplaceServiceRecordBySelector
    mov    edi,DWORD PTR [esp+0x88]
    mov    ebx,DWORD PTR [esp+0x84]
    push   edi
    push   ebx
    push   0x2
    mov    ecx,esi
    call   R6GameServiceAddresses::TryReadServiceRecordTagAndValue
    test   al,al
    jne    Branch39
  Branch38:
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x7c],0x5
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x5c]
    mov    BYTE PTR [esp+0x7c],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x7c],0x1
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x7c],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch44
  Branch39:
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x2c]
    push   0x1
    push   eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je    Branch38
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    jne    Branch40
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x7c],0x5
    call   R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x5c]
    mov    BYTE PTR [esp+0x7c],0x3
    call   R6GameServiceAddresses::DestroyClDataList
    jmp    Branch42
  Branch40:
    mov    al,BYTE PTR [ebx]
    lea    ecx,[esp+0x14]
    cmp    al,0x27
    lea    eax,[esp+0x10]
    jne    Branch43
    push   0x1
    push   eax
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch41
    mov    ecx,DWORD PTR [edi]
    mov    edx,DWORD PTR [esp+0x10]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   edx
    call   R6GameServiceAddresses::ResetOuterRecordAndFlushQueuedUpdates
  Branch41:
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x7c],0x5
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x5c]
    mov    BYTE PTR [esp+0x7c],0x3
    call   R6GameServiceAddresses::DestroyClDataListAlias
  Branch42:
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x7c],0x1
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x7c],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataListAlias
    xor    al,al
    jmp    Branch44
  Branch43:
    push   0x0
    push   eax
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je    Branch41
    mov    ecx,DWORD PTR [esp+0x10]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::SendProxyRequestForOuterRecordKey
    lea    ecx,[esp+0x44]
    mov    bl,al
    mov    BYTE PTR [esp+0x7c],0x5
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x5c]
    mov    BYTE PTR [esp+0x7c],0x3
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x7c],0x1
    call   R6GameServiceAddresses::DestroyClDataListAlias
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x7c],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataListAlias
    mov    al,bl
  Branch44:
    mov    ecx,DWORD PTR [esp+0x74]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret    0x8
  }
}

// R6GameService.dll @ 10042c40 : ClearTreeNodes
// Frees all nodes in a nonempty tree, retaining and resetting its sentinel.
void __fastcall ClearTreeNodes(int *tree)
{
  if (tree[1] == 0) return;

  int nodeAddress = *(int *)(*tree + 4);
  while (nodeAddress != 0) {
    ordered_tree_support_ReleaseTreeNodes3(tree, *(int *)(nodeAddress + 0xc));
    int nextAddress = *(int *)(nodeAddress + 8);
    TailFreeThroughGlobalAllocator((void *)nodeAddress);
    nodeAddress = nextAddress;
  }
  *(int *)(*tree + 8) = *tree;
  *(uint *)(*tree + 4) = 0;
  *(int *)(*tree + 0xc) = *tree;
  tree[1] = 0;
}

// R6GameService.dll @ 10042c90 : ClearTreePayloadNodes
// Releases each node's embedded payload reference, frees the nodes and resets the retained sentinel.
void __fastcall ClearTreePayloadNodes(int *tree)
{
  if (tree[1] == 0) return;

  int nodeAddress = *(int *)(*tree + 4);
  while (nodeAddress != 0) {
    ReleaseTreePayloadNodes(tree, *(int *)(nodeAddress + 0xc));
    int nextAddress = *(int *)(nodeAddress + 8);
    ReleasePayloadReferenceAt16(nodeAddress + 0x10);
    TailFreeThroughGlobalAllocator((void *)nodeAddress);
    nodeAddress = nextAddress;
  }
  *(int *)(*tree + 8) = *tree;
  *(uint *)(*tree + 4) = 0;
  *(int *)(*tree + 0xc) = *tree;
  tree[1] = 0;
}

// Reset outer descriptor base at inherited EBP-3c.
// R6GameService.dll @ 10067020 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT outer descriptor at inherited EBP-3c.
// R6GameService.dll @ 10067028 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered mismatch outer base at inherited EBP-3c without retrying member destruction.
// R6GameService.dll @ 10067030 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inner construction base at inherited EBP-24 before full outer cleanup.
// R6GameService.dll @ 10067038 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT inner descriptor at inherited EBP-24 before full outer cleanup.
// R6GameService.dll @ 10067040 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset entered inner base at inherited EBP-24 before full outer cleanup; no inner payload retry.
// R6GameService.dll @ 10067048 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl TryReadServiceRecordTagAndValueUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact six-state cached service-record reader FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10067050 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceRecordReaderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TryReadServiceRecordTagAndValueExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset construction base of descriptor at inherited EBP-d4; preserve exact predecessor.
// R6GameService.dll @ 10067060 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0xd4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-d4; preserve exact predecessor.
// R6GameService.dll @ 1006706b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0xd4]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-11c; preserve exact predecessor.
// R6GameService.dll @ 10067076 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x11c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-11c; preserve exact predecessor.
// R6GameService.dll @ 10067081 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x11c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-ec; preserve exact predecessor.
// R6GameService.dll @ 1006708c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0xec]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-ec; preserve exact predecessor.
// R6GameService.dll @ 10067097 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0xec]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-104; preserve exact predecessor.
// R6GameService.dll @ 100670a2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x104]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-104; preserve exact predecessor.
// R6GameService.dll @ 100670ad : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorOneServiceResponseUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x104]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select exact eight-state selector1 response FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 100670b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelectorOneResponseEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ApplySelectorOneServiceResponseExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset construction base of descriptor at inherited EBP-54; retain exact predecessor chain.
// R6GameService.dll @ 100670d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-54; retain exact predecessor chain.
// R6GameService.dll @ 100670d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-6c; retain exact predecessor chain.
// R6GameService.dll @ 100670e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-6c; retain exact predecessor chain.
// R6GameService.dll @ 100670e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-24; retain exact predecessor chain.
// R6GameService.dll @ 100670f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-24; retain exact predecessor chain.
// R6GameService.dll @ 100670f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset construction base of descriptor at inherited EBP-3c; retain exact predecessor chain.
// R6GameService.dll @ 10067100 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full CURRENT descriptor at inherited EBP-3c; retain exact predecessor chain.
// R6GameService.dll @ 10067108 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ApplySelectorTwoServiceResponseUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Select exact four-descriptor/eight-state selector2 response FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10067110 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelectorTwoResponseEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ApplySelectorTwoServiceResponseExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal service-record reader cleanup map.
// R6GameService.dll data @ 10081718 : native storage identity retained.
const R6GameServiceNative::UnwindEntry TryReadServiceRecordTagAndValueUnwindMap[6] = {
  {-1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind1},
  {-1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind2},
  {-1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind3},
  {0x1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind4},
  {0x1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind5},
  {0x1, R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwind6},
};

// Literal service-record reader FuncInfo.
// R6GameService.dll data @ 10081748 : native storage identity retained.
const R6GameServiceNative::FuncInfo TryReadServiceRecordTagAndValueExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::TryReadServiceRecordTagAndValueUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal selector2 response cleanup map; two later descriptors retain genuine unused lifetimes.
// R6GameService.dll data @ 100817c0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ApplySelectorTwoServiceResponseUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind1},
  {-1, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind2},
  {0x1, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind3},
  {0x1, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind4},
  {0x3, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind5},
  {0x3, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind6},
  {0x5, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind7},
  {0x5, R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwind8},
};

// Literal selector2 response FuncInfo.
// R6GameService.dll data @ 10081800 : native storage identity retained.
const R6GameServiceNative::FuncInfo ApplySelectorTwoServiceResponseExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ApplySelectorTwoServiceResponseUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal four-descriptor selector1 cleanup map.
// R6GameService.dll data @ 10081764 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ApplySelectorOneServiceResponseUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind1},
  {-1, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind2},
  {0x1, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind3},
  {0x1, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind4},
  {0x3, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind5},
  {0x3, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind6},
  {0x5, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind7},
  {0x5, R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwind8},
};

// Literal selector1 FuncInfo.
// R6GameService.dll data @ 100817a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ApplySelectorOneServiceResponseExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ApplySelectorOneServiceResponseUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Read flag BYTE before vtable reset77d70, optionally raw-free on bit0, then return original receiver.
// Separate native deleting body from414a0: no call to414c0, no tree cleanup or own EH; RET4.
// R6GameService.dll @ 100414d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeleteServiceTreeStorageInline(void *receiver)
{
  __asm {
    mov al,BYTE PTR [esp+0x4]
    push esi
    mov esi,ecx
    test al,0x1
    mov DWORD PTR [esi],R6GameServiceAddresses::keyed_results_supportPTR_LAB
    je    Branch45
    push esi
    call R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch45:
    mov eax,esi
    pop esi
    ret 0x4
  }
}

// Native virtual-table prefix: CProxyHandlerVTable
// R6GameService.dll data @ 10077d20 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CProxyHandlerVTableRecord {
  R6GameServiceNative::Address DestroyServiceTreeStorageDeletingDestructor; // +0x00
  R6GameServiceNative::Address BuildServiceRecord66; // +0x04
  R6GameServiceNative::Address BuildServiceRecord5D; // +0x08
  R6GameServiceNative::Address BuildServiceRecord4D; // +0x0c
  R6GameServiceNative::Address QueueMarkedClDataRecord; // +0x10
};
const CProxyHandlerVTableRecord CProxyHandlerVTable = {
  R6GameServiceAddresses::DestroyServiceTreeStorageDeletingDestructor,
  R6GameServiceAddresses::BuildServiceRecord66,
  R6GameServiceAddresses::BuildServiceRecord5D,
  R6GameServiceAddresses::BuildServiceRecord4D,
  R6GameServiceAddresses::QueueMarkedClDataRecord,
};
