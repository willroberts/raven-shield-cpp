#include "native_addresses.h"
#include "native_records.h"

// Inferred cleanup guard: a failed destruction releases the current header without retrying node traversal.
struct ServiceRecordTreeStorageCleanup {
  void *savedTree;
  bool armed;
  // Read the saved tree's current first word even if the normal header release failed.
  ~ServiceRecordTreeStorageCleanup() noexcept(false)
  {
    if (armed) {
      using ReleaseABI = uint (__fastcall *)(void *);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseFirstWordBuffer)(savedTree);
    }
  }
};

// clMatchResults identity: primary77d58 -> COL79b34 -> type8fe34; original member spellings inferred.

// Reset destination, append two signed summary fields, then one copied nested descriptor for each ordered record.
// Reuse one local clDataList; each clPlayerResults child resets it before serializing its label/scalars/values.
// Cache owner/output, read successor and current owner head after each copy; keys and child status are not output.
// ENTRY ESP S: temporary S-24/memberS-18/head slotS-14; original argument becomes member scratch.
// Preserve three physical range arguments, four-state cleanup, final state2/dangling head and RET4/output EAX.
// R6GameService.dll @ 10055ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendOrderedRecordsToDescriptor(void *owner,void *destination)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectMatchResultsAppendEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push   ebp
    push   esi
    push   edi
    mov    DWORD PTR [esp+0xc],0x0
    mov    edi,DWORD PTR [esp+0x38]
    mov    ebp,ecx
    test   edi,edi
    jne    Branch1
    xor    eax,eax
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0x28
    ret    0x4
  Branch1:
    mov    eax,DWORD PTR [edi+0xc]
    lea    ecx,[edi+0xc]
    call   DWORD PTR [eax+0x4]
    lea    ecx,[ebp+0x18]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[ebp+0x1c]
    mov    ecx,edi
    push   edx
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
    mov    eax,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esp+0x30],0x1
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch8
  Branch2:
    lea    eax,[esp+0x10]
    lea    ecx,[esi+0x1c]
    push   eax
    call   R6GameServiceAddresses::AppendIndexedValuesToDescriptor
    lea    ecx,[esp+0x10]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    test   ecx,ecx
    je     Branch4
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    je     Branch7
  Branch3:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    test   ecx,ecx
    jne    Branch3
    jmp    Branch7
  Branch4:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch6
  Branch5:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch5
  Branch6:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch7
    mov    eax,ecx
  Branch7:
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    esi,eax
    cmp    eax,ecx
    jne    Branch2
  Branch8:
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x38],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    push   ecx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,esp
    push   ecx
    push   esp
    mov    BYTE PTR [esp+0x3c],0x3
    mov    DWORD PTR [eax],ecx
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    eax,DWORD PTR [esp+0x24]
    lea    edx,[esp+0x14]
    push   edx
    lea    ecx,[esp+0x28]
    call   DWORD PTR [eax+0x10]
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x28]
    mov    eax,edi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebp
    add    esp,0x28
    ret    0x4
  }
}

// Apply the exact enclosing-serializer temporary cleanup from inherited original ENTRY ESP.
// R6GameService.dll @ 10069170 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendOrderedRecordsToDescriptorUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply the exact enclosing-serializer temporary cleanup from inherited original ENTRY ESP.
// R6GameService.dll @ 10069178 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendOrderedRecordsToDescriptorUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Apply the exact enclosing-serializer temporary cleanup from inherited original ENTRY ESP.
// R6GameService.dll @ 10069180 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendOrderedRecordsToDescriptorUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Apply the exact enclosing-serializer temporary cleanup from inherited original ENTRY ESP.
// R6GameService.dll @ 10069188 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendOrderedRecordsToDescriptorUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je     Branch9
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x5c],eax
    jmp    Branch10
  Branch9:
    mov    DWORD PTR [ebp-0x5c],0x0
  Branch10:
    mov    ecx,DWORD PTR [ebp-0x5c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select clMatchResults serializer four-state metadata and tail current CRT dispatch.
// R6GameService.dll @ 100691af : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMatchResultsAppendEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AppendOrderedRecordsToDescriptorExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal clMatchResults serializer unwind map or FuncInfo.
// R6GameService.dll data @ 10083bec : native storage identity retained.
const R6GameServiceNative::UnwindEntry AppendOrderedRecordsToDescriptorUnwindMap[4] = {
  {-1, R6GameServiceAddresses::AppendOrderedRecordsToDescriptorUnwind1},
  {-1, R6GameServiceAddresses::AppendOrderedRecordsToDescriptorUnwind2},
  {-1, R6GameServiceAddresses::AppendOrderedRecordsToDescriptorUnwind3},
  {0x2, R6GameServiceAddresses::AppendOrderedRecordsToDescriptorUnwind4},
};

// Literal clMatchResults serializer unwind map or FuncInfo.
// R6GameService.dll data @ 10083bec : native storage identity retained.
const R6GameServiceNative::FuncInfo AppendOrderedRecordsToDescriptorExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::AppendOrderedRecordsToDescriptorUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Scan cached key text, construct/search/free temporary descriptor, then use cached node/head comparison.
// Missing path builds borrowed-key/class pair, owning-string/class pair, inserts, destroys locals and strncpy16
// into selected node34 WITHOUT clamp; label source/index/value args remain live. RET12/raw updater EAX.
// Exact eleven-state frame uses original ENTRY ESP, not conventional EBP; no cleanup retry outside armed map.
// R6GameService.dll @ 10055860 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall UpdateStringKeyedRecord(void *owner,char *keyText,uint indexWord,uint valueWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::clMatchResults_SelectKeyedResultsEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xbc
    push   ebx
    push   esi
    push   edi
    mov    ebx,ecx
    mov    esi,DWORD PTR [esp+0xd8]
    lea    eax,[esp+0xe]
    push   eax
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0xd4],0x0
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    edi,esi
    or     ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0xe]
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0xf]
    add    ecx,esi
    push   eax
    push   ecx
    push   esi
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0xdc],0x1
    mov    BYTE PTR [esp+0x1b],dl
    call   R6GameServiceAddresses::ConstructHeapByteStringRange
    lea    ecx,[esp+0x10]
    lea    esi,[ebx+0x8]
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0xd4],0x2
    call   R6GameServiceAddresses::FindServiceTreeNodeByByteString
    mov    ecx,DWORD PTR [esi]
    mov    edi,eax
    cmp    edi,ecx
    setne  bl
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0xd0],0x3
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    test   bl,bl
    mov    DWORD PTR [esp+0xd0],0xffffffff
    je     Branch11
    mov    edx,DWORD PTR [esp+0xe0]
    mov    eax,DWORD PTR [esp+0xdc]
    push   edx
    push   eax
    lea    ecx,[edi+0x1c]
    jmp    Branch12
  Branch11:
    push   0x1
    lea    ecx,[esp+0x60]
    call   R6GameServiceAddresses::InitializeIndexedValueCollection
    lea    ecx,[esp+0xd8]
    push   eax
    lea    edx,[esp+0x94]
    mov    ebx,0x4
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0xdc],ebx
    call   R6GameServiceAddresses::ConstructIndexedRecordCopy
    add    esp,0xc
    mov    edi,eax
    mov    ecx,DWORD PTR [edi]
    lea    eax,[esp+0xe]
    push   eax
    push   ecx
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xd8],0x6
    call   R6GameServiceAddresses::ConstructHeapByteStringFromCString
    add    edi,ebx
    push   0x1
    push   edi
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0xd8],0x8
    call   R6GameServiceAddresses::AssignIndexedRecord
    lea    edx,[esp+0x1c]
    lea    eax,[esp+0x10]
    push   edx
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [esp+0xd8],0x9
    call   R6GameServiceAddresses::InsertOrFindByteDescriptorNode
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xd0],0xa
    call   R6GameServiceAddresses::DestroyServiceLinkedRecordContainer
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0xd0],0x5
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x94]
    mov    BYTE PTR [esp+0xd0],bl
    call   R6GameServiceAddresses::DestroyServiceLinkedRecordContainer
    lea    ecx,[esp+0x64]
    mov    DWORD PTR [esp+0xd0],0xffffffff
    mov    DWORD PTR [esp+0x5c],R6GameServiceAddresses::clPlayerResultsVTable
    call   R6GameServiceAddresses::ForwardIndexedCollectionDestroy
    mov    edx,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xd8]
    push   0x10
    add    edx,0x34
    push   ecx
    push   edx
    call   R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0xec]
    mov    ecx,DWORD PTR [esp+0xe8]
    mov    edx,DWORD PTR [esp+0x1c]
    add    esp,0xc
    push   eax
    push   ecx
    lea    ecx,[edx+0x1c]
  Branch12:
    call   R6GameServiceAddresses::RecordIndexedWordValue
    mov    ecx,DWORD PTR [esp+0xc8]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xc8
    ret    0xc
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 100690d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults(void)
{
  __asm {
    lea    ecx,[ebp-0xc6]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 100690db : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults2(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 100690e6 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults3(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 100690f1 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults4(void)
{
  __asm {
    lea    ecx,[ebp-0xbc]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 100690fc : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults5(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    R6GameServiceAddresses::ForwardDestroyServiceLinkedRecordContainer
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10069104 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults6(void)
{
  __asm {
    lea    ecx,[ebp-0x44]
    jmp    R6GameServiceAddresses::DestroyOwnedList
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 1006910c : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults7(void)
{
  __asm {
    lea    ecx,[ebp-0xc6]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10069117 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults8(void)
{
  __asm {
    lea    ecx,[ebp-0xb8]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 10069122 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults9(void)
{
  __asm {
    lea    ecx,[ebp-0xb8]
    jmp    R6GameServiceAddresses::DestroyServiceTreeRecord
  }
}


// Apply exact inherited ENTRY ESP local-address/current-slot cleanup for associated keyed-result/pair state.
// R6GameService.dll @ 1006912d : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl clMatchResults_UnwindKeyedResults10(void)
{
  __asm {
    lea    ecx,[ebp-0xb8]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}


// Select exact keyed-result/pair frame map and tail current CRT dispatch.
// R6GameService.dll @ 10069138 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clMatchResults_SelectKeyedResultsEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UpdateStringKeyedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}


// R6GameService.dll data @ 10083b4c : exact keyed-result/pair unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry UpdateStringKeyedRecordUnwindMap[11] = {
  {-1, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults},
  {0x0, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults2},
  {0x0, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults3},
  {0x0, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults4},
  {-1, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults5},
  {0x4, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults6},
  {0x5, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults7},
  {0x6, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults8},
  {0x5, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults8},
  {0x5, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults9},
  {0x5, R6GameServiceAddresses::clMatchResults_UnwindKeyedResults10},
};

// R6GameService.dll data @ 10083ba4 : exact keyed-result/pair unwind map or FuncInfo.
// R6GameService.dll data @ 10083b4c : native storage identity retained.
const R6GameServiceNative::FuncInfo UpdateStringKeyedRecordExceptionInfo = {
  0x19930520,
  0xb,
  R6GameServiceAddresses::UpdateStringKeyedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroy clMatchResults, then test CURRENT deleting flag low byte/bit0 before freeing the original receiver.
// No own cleanup registration; destruction/free failures retain native partial effects. RET4/owner EAX.
// R6GameService.dll @ 100413e0 : complete native control/access order and raw ABI retained.
void *__thiscall DeleteOptionalChannelTree(void *owner,uint deletingFlags)
{
  void *savedOwner = owner;
  using DestroyABI = uint (__fastcall *)(undefined4 *);
  ((DestroyABI)R6GameServiceAddresses::DestroyServiceRecordTree)((undefined4 *)savedOwner);
  byte flags = *(byte *)&deletingFlags;
  if ((flags & 1) != 0) {
    using FreeABI = uint (__stdcall *)(void *);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(savedOwner);
  }
  return savedOwner;
}

// Destroy clMatchResults owned byte-key records right-first; count gates traversal, not the number of released nodes.
// Cache next left after right recursion but before pair destruction; release class header/string/pair node in order.
// Reset each CURRENT head link separately, then count; always free CURRENT head, leaving its slot dangling.
// ENTRY ESP frame saves tree slot at-10/state0; shared cleanup can repeat current header free after failure.
// Raw final allocator EAX; original summary fields retained.
// R6GameService.dll @ 10041400 : complete native control/access order and raw ABI retained.
uint __fastcall DestroyServiceRecordTree(undefined4 *owner)
{
  ServiceRecordTreeStorageCleanup cleanup{0, false};
  void *tree = (void *)((uint)owner + 8);
  *(uint *)owner = R6GameServiceAddresses::clMatchResultsVTable;
  cleanup.savedTree = tree;
  uint count = *(uint *)((uint)tree + 4);
  cleanup.armed = true;
  using SubtreeABI = void (__thiscall *)(void *,uint);
  using PairABI = void * (__thiscall *)(void *,uint);
  using ReleaseABI = uint (__thiscall *)(void *,void *,uint);
  using FreeABI = uint (__stdcall *)(void *);
  if (count != 0) {
    uint head = *(uint *)tree;
    uint node = *(uint *)(head + 4);
    while (node != 0) {
      uint right = *(uint *)(node + 0xc);
      ((SubtreeABI)R6GameServiceAddresses::ReleaseServiceTreeSubtree)(tree,right);
      uint left = *(uint *)(node + 8);
      ((PairABI)R6GameServiceAddresses::DestroyServiceTreeRecordDeletingDestructor)((void *)(node + 0x10),0);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(tree,(void *)node,1);
      node = left;
    }
    head = *(uint *)tree;
    *(uint *)(head + 8) = head;
    uint rootHead = *(uint *)tree;
    *(uint *)(rootHead + 4) = 0;
    head = *(uint *)tree;
    *(uint *)(head + 0xc) = head;
    *(uint *)((uint)tree + 4) = 0;
  }
  void *head = *(void **)tree;
  uint result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(head);
  cleanup.armed = false;
  return result;
}

// Native virtual-table prefix: clMatchResultsVTable
// R6GameService.dll data @ 10077d58 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMatchResultsVTableRecord {
  R6GameServiceNative::Address DeleteOptionalChannelTree; // +0x00
};
const clMatchResultsVTableRecord clMatchResultsVTable = {R6GameServiceAddresses::DeleteOptionalChannelTree};
