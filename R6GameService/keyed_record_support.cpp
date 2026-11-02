#include "native_addresses.h"
#include "native_records.h"

// Keyed association lifetime, socket/record delivery and shared WORD-key tables; original class identities unresolved.

// Remove all current WORD-key nodes from table+20; cache pre-count30 and recycle current nonzero key if pre-count != removed.
// Recycle inline unless cursor78 equals blockEnd80-2; append helper captures the key before its own callbacks.
// If CURRENT30 is0, remove owner WORD4 from current global945b0, close socket+8, optionally destroy/free current empty global.
// Finally destroy/free cached owner; preserve global reload/late NULL test, ignored statuses, no local EH and raw EAX/RET4.
// R6GameService.dll @ 100600f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveKeyAndRecycleOrDestroy(void *owner,uint keyWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    lea    eax,[esp+0x8]
    push    edi
    mov    edi,DWORD PTR [esi+0x30]
    push    eax
    lea    ecx,[esi+0x20]
    call    R6GameServiceAddresses::RemoveAllNodesForKey
    cmp    edi,eax
    je    Branch3
    mov    dx,WORD PTR [esp+0xc]
    test    dx,dx
    je    Branch3
    mov    edi,DWORD PTR [esi+0x80]
    mov    eax,DWORD PTR [esi+0x78]
    lea    ecx,[esi+0x68]
    sub    edi,0x2
    cmp    eax,edi
    je    Branch2
    test    eax,eax
    je    Branch1
    mov    WORD PTR [eax],dx
  Branch1:
    add    DWORD PTR [ecx+0x10],0x2
    jmp    Branch3
  Branch2:
    lea    edx,[esp+0xc]
    push    edx
    call    R6GameServiceAddresses::AppendWordAndAllocateNextBlock
  Branch3:
    mov    eax,DWORD PTR [esi+0x30]
    test    eax,eax
    jne    Branch6
    mov    ecx,DWORD PTR ds:0x100945b0
    lea    eax,[esi+0x4]
    push    eax
    call    R6GameServiceAddresses::RemoveAllNodesForKey
    lea    ecx,[esi+0x8]
    call    R6GameServiceAddresses::CloseSocketAndReset
    mov    edi,DWORD PTR ds:0x100945b0
    mov    eax,DWORD PTR [edi+0x10]
    test    eax,eax
    jne    Branch5
    test    edi,edi
    je    Branch4
    mov    ecx,edi
    call    R6GameServiceAddresses::DestroyBucketChains
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch4:
    mov    DWORD PTR ds:0x100945b0,0x0
  Branch5:
    mov    ecx,esi
    call    R6GameServiceAddresses::DestroyKeyedRecordStorage
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch6:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Send current record+10 bytes/count14 to address8/WORDc through socket owner+8; WORD load retains incoming EAX upper16.
// Compare returned byte count with CURRENT record14. Mismatch stores current socket error at owner18 and clears only AL.
// Equal count sets only AL1 of returned count; no local EH, status normalization or fixed pre-send length comparison. RET4.
// R6GameService.dll @ 10060610 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendKeyedRecordPayload(void *owner,void *record)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    push    edi
    mov    edi,ecx
    mov    ax,WORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esi+0x14]
    push    eax
    mov    eax,DWORD PTR [esi+0x10]
    lea    ebx,[edi+0x8]
    push    ecx
    push    edx
    push    eax
    mov    ecx,ebx
    call    R6GameServiceAddresses::SendSocketBytesToIPv4
    cmp    eax,DWORD PTR [esi+0x14]
    je    Branch7
    mov    ecx,ebx
    call    R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [edi+0x18],eax
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x4
  Branch7:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x4
  }
}

// Hash INITIAL key WORD by signed bucket-distance/4 then unsigned DIV; zero bucket count reaches native DIV0.
// Delete matching interior nodes before cached original head, unlink BEFORE free, then decrement CURRENT count10.
// Reload original key pointer after interior frees; key WORD and current chain/bucket base remain live. No payload deletion/EH. RET4/count.
// R6GameService.dll @ 100618e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveAllNodesForKey(void *table,const ushort *key)
{
  __asm {
    push    ecx
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    push    edi
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    sub    edi,edx
    xor    eax,eax
    mov    ax,WORD PTR [ecx]
    xor    edx,edx
    sar    edi,0x2
    div    edi
    mov    eax,DWORD PTR [esi+0x4]
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x10],edx
    mov    ebx,DWORD PTR [eax+edx*4]
    test    ebx,ebx
    je    Branch12
    mov    eax,DWORD PTR [ebx]
    mov    edi,ebx
    test    eax,eax
    je    Branch11
  Branch8:
    mov    dx,WORD PTR [eax+0x4]
    cmp    dx,WORD PTR [ecx]
    jne    Branch9
    mov    ecx,DWORD PTR [eax]
    push    eax
    mov    DWORD PTR [edi],ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,DWORD PTR [edi]
    inc    ebp
    dec    ecx
    mov    DWORD PTR [esi+0x10],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    jmp    Branch10
  Branch9:
    mov    edi,eax
    mov    eax,DWORD PTR [eax]
  Branch10:
    test    eax,eax
    jne    Branch8
    mov    edx,DWORD PTR [esp+0x10]
  Branch11:
    mov    ax,WORD PTR [ebx+0x4]
    cmp    ax,WORD PTR [ecx]
    jne    Branch12
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [ebx]
    push    ebx
    mov    DWORD PTR [ecx+edx*4],eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x10]
    inc    ebp
    dec    eax
    mov    DWORD PTR [esi+0x10],eax
  Branch12:
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Free auxiliary94, release WORD storage68, erase pointer range38/release its storage3c, clear key table20/free24.
// Parent entry S: ownerS-28, word descriptorS-24, current subobjectS-20, stateS-4; each cleanup stage has its own map.
// Preserve cursor copies/by-value calls, staged disarm, genuine socket no-op, unchanged fields and raw final EAX.
// R6GameService.dll @ 100602f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyKeyedRecordStorage(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectKeyedRecordDestructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x30],0x0
    mov    eax,DWORD PTR [esi+0x94]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    edi,[esi+0x68]
    mov    DWORD PTR [esp+0x10],edi
    sub    esp,0x10
    lea    ecx,[edi+0x10]
    mov    eax,esp
    mov    DWORD PTR [esp+0x24],esp
    mov    edx,DWORD PTR [ecx]
    sub    esp,0x10
    mov    DWORD PTR [eax],edx
    mov    DWORD PTR [esp+0x34],esp
    mov    edx,DWORD PTR [ecx+0x4]
    mov    BYTE PTR [esp+0x50],0x3
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [eax+0x8],edx
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,esp
    push    edi
    call    R6GameServiceAddresses::CopySegmentedCursor
    call    R6GameServiceAddresses::CopyByValueCursorArgumentsToScratch
    mov    ecx,edi
    mov    BYTE PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::ReleaseSegmentedWordBlocks
    lea    edi,[esi+0x38]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerDeque_PAVclSegmentVTable
    sub    esp,0x10
    lea    edx,[edi+0x14]
    mov    eax,esp
    sub    esp,0x10
    mov    ecx,DWORD PTR [edx]
    lea    ebp,[edi+0x4]
    mov    DWORD PTR [eax],ecx
    push    esp
    mov    ecx,DWORD PTR [edx+0x4]
    mov    BYTE PTR [esp+0x54],0x4
    mov    DWORD PTR [eax+0x4],ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [eax+0x8],ecx
    mov    ecx,ebp
    mov    edx,DWORD PTR [edx+0xc]
    mov    DWORD PTR [eax+0xc],edx
    call    R6GameServiceAddresses::CopyWordsToOutput
    lea    eax,[esp+0x38]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::EraseSegmentedObjectRange
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocks
    lea    edi,[esi+0x20]
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::Clear16BitKeyBuckets
    lea    ecx,[edi+0x4]
    mov    BYTE PTR [esp+0x30],0x0
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    lea    ecx,[esi+0x8]
    mov    DWORD PTR [esp+0x30],0xffffffff
    call    R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    pop    ebp
    add    esp,0x28
    ret
  }
}

// Free cached-next nodes, zero each CURRENT bucket head and finally count10; reload unsigned bucket bound each round.
// Free CURRENT nonnull bucket array4 last, retaining base/end/capacity fields and raw final allocator EAX; no local EH.
// R6GameService.dll @ 10060900 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyBucketChains(void *table)
{
  __asm {
    push    ebx
    push    edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [edi+0x8]
    mov    edx,DWORD PTR [edi+0x4]
    sub    eax,edx
    sar    eax,0x2
    je    Branch16
    push    esi
  Branch13:
    mov    ecx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [ecx+ebx*4]
    test    eax,eax
    je    Branch15
  Branch14:
    mov    esi,DWORD PTR [eax]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    esi,esi
    mov    eax,esi
    jne    Branch14
  Branch15:
    mov    edx,DWORD PTR [edi+0x4]
    inc    ebx
    mov    DWORD PTR [edx+ebx*4-0x4],0x0
    mov    eax,DWORD PTR [edi+0x8]
    sub    eax,DWORD PTR [edi+0x4]
    sar    eax,0x2
    cmp    ebx,eax
    jb    Branch13
    pop    esi
  Branch16:
    mov    DWORD PTR [edi+0x10],0x0
    mov    edi,DWORD PTR [edi+0x4]
    test    edi,edi
    je    Branch17
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch17:
    pop    edi
    pop    ebx
    ret
  }
}

// Tail-forward unchanged receiver/registers/stack and raw return to complete bucket destruction60900.
// R6GameService.dll @ 100602b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardBucketCleanup(void *table)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyBucketChains
  }
}

// Free nodes only, retaining payloads/array; cache each next pointer before free, reload current base/end afterward.
// Zero CURRENT bucket slots and count10, leave other fields, return final signed bucket-distance/4 in EAX. No local EH.
// R6GameService.dll @ 10061190 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall Clear16BitKeyBuckets(void *table)
{
  __asm {
    push    ebx
    push    edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [edi+0x8]
    mov    edx,DWORD PTR [edi+0x4]
    sub    eax,edx
    sar    eax,0x2
    je    Branch21
    push    esi
  Branch18:
    mov    ecx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [ecx+ebx*4]
    test    eax,eax
    je    Branch20
  Branch19:
    mov    esi,DWORD PTR [eax]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    esi,esi
    mov    eax,esi
    jne    Branch19
  Branch20:
    mov    edx,DWORD PTR [edi+0x4]
    inc    ebx
    mov    DWORD PTR [edx+ebx*4-0x4],0x0
    mov    eax,DWORD PTR [edi+0x8]
    sub    eax,DWORD PTR [edi+0x4]
    sar    eax,0x2
    cmp    ebx,eax
    jb    Branch18
    pop    esi
  Branch21:
    mov    DWORD PTR [edi+0x10],0x0
    pop    edi
    pop    ebx
    ret
  }
}

// State0: reload CURRENT saved ownerS-28, add8 and tail-forward to genuine socket no-op.
// R6GameService.dll @ 10069d70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::ForwardToNoOp
  }
}

// State1: reload CURRENT saved ownerS-28, add20 and tail-forward to whole bucket destruction.
// R6GameService.dll @ 10069d7b : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::ForwardBucketCleanup
  }
}

// State2: reload CURRENT saved ownerS-28, add38 and tail-forward to owning pointer-container destruction.
// R6GameService.dll @ 10069d86 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    add    ecx,0x38
    jmp    R6GameServiceAddresses::ForwardClSegmentPointerDequeDestroy
  }
}

// State3: release WORD blocks through CURRENT saved descriptorS-24, then state2.
// R6GameService.dll @ 10069d91 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseSegmentedWordBlocks
  }
}

// State4: preserve NULL while adjusting CURRENT subobjectS-20 by4 into scratchS-30; release raw pointer blocks.
// R6GameService.dll @ 10069d99 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x20],0x0
    je    Branch22
    mov    eax,DWORD PTR [ebp-0x20]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x30],eax
    jmp    Branch23
  Branch22:
    mov    DWORD PTR [ebp-0x30],0x0
  Branch23:
    mov    ecx,DWORD PTR [ebp-0x30]
    jmp    R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocks
  }
}

// State5: reload CURRENT subobjectS-20, add4 and release its first-word allocation, then state0.
// R6GameService.dll @ 10069dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    add    ecx,0x4
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// State6: reload CURRENT subobjectS-20, add10 and tail-forward to genuine no-op, then state5.
// R6GameService.dll @ 10069dcb : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyKeyedRecordStorageUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact seven-state destruction map84888/FuncInfo848c0 and tail-forward to CRT dispatch.
// R6GameService.dll @ 10069dd6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyedRecordDestructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyKeyedRecordStorageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native cleanup map or FuncInfo; preserve staged cleanup transitions.
// R6GameService.dll data @ 10084888 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyKeyedRecordStorageUnwindMap[7] = {
  {-1, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind1},
  {0x0, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind2},
  {0x1, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind3},
  {0x2, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind4},
  {0x1, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind5},
  {0x0, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind6},
  {0x5, R6GameServiceAddresses::DestroyKeyedRecordStorageUnwind7},
};

// Literal native cleanup map or FuncInfo; preserve staged cleanup transitions.
// R6GameService.dll data @ 10084888 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyKeyedRecordStorageExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::DestroyKeyedRecordStorageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Initialize socket/table/pointer and WORD storage, then allocate32-byte auxiliary94; return owner/RET4.
// Optional7833c and member78334/7832c/782ac are offset data; only pointer-container78328 is an identified vptr.
// Initial full flag gates owner0; three later CURRENT argument lowBYTE reads initialize table bytes20..22.
// Entry S: saved ownerS-14/current tableS-10/stateS-4. Exact eight-stage cleanup retains no WORD-storage action at final allocation.
// R6GameService.dll @ 100601a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeKeyedRecord(void *owner,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectAssociationConstructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    DWORD PTR [esp+0x4],0x0
    mov    eax,DWORD PTR [esp+0x18]
    push    esi
    mov    esi,ecx
    test    eax,eax
    push    edi
    mov    DWORD PTR [esp+0x8],esi
    je    Branch24
    mov    DWORD PTR [esi],0x1007833c
  Branch24:
    push    0x1
    lea    ecx,[esi+0x8]
    call    R6GameServiceAddresses::InitializeSocketContext
    lea    edi,[esi+0x20]
    mov    DWORD PTR [esi+0x1c],0x20
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi+0x14],0x10078334
    mov    al,BYTE PTR [esp+0x20]
    mov    cl,BYTE PTR [esp+0x20]
    mov    dl,BYTE PTR [esp+0x20]
    mov    BYTE PTR [edi],al
    lea    eax,[esp+0x20]
    mov    BYTE PTR [edi+0x1],cl
    lea    ecx,[edi+0x4]
    push    eax
    mov    BYTE PTR [esp+0x1c],0x1
    mov    BYTE PTR [edi+0x2],dl
    call    R6GameServiceAddresses::InitializePointerTriplet
    lea    ecx,[esp+0x20]
    push    0x0
    push    ecx
    lea    ecx,[edi+0x10]
    mov    BYTE PTR [esp+0x20],0x2
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push    0x64
    mov    ecx,edi
    mov    BYTE PTR [esp+0x1c],0x3
    call    R6GameServiceAddresses::AppendSelectedBucketSlotsAndResetCount
    mov    DWORD PTR [esi+0x64],0x1007832c
    lea    ecx,[esi+0x3c]
    lea    edx,[esp+0x20]
    push    0x0
    push    edx
    mov    BYTE PTR [esp+0x20],0x5
    call    R6GameServiceAddresses::InitializeSegmentedDwordBuffer
    mov    DWORD PTR [esi+0x38],R6GameServiceAddresses::clPointerDeque_PAVclSegmentVTable
    lea    ecx,[esi+0x68]
    mov    DWORD PTR [ecx+0x28],0x100782ac
    lea    eax,[esp+0x20]
    push    0x0
    push    eax
    mov    BYTE PTR [esp+0x20],0x7
    call    R6GameServiceAddresses::InitializeSegmentedWords
    push    0x20
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x94],eax
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// State0: CURRENT saved ownerS-14 plus8, tail genuine socket no-op; next-1.
// R6GameService.dll @ 10069d10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::ForwardToNoOp
  }
}

// State1: original argument slotS+4 address, tail genuine temporary no-op; next0.
// R6GameService.dll @ 10069d1b : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// State2: CURRENT saved tableS-10 plus4, release first-word allocation; next1.
// R6GameService.dll @ 10069d23 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x4
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// State3: CURRENT saved tableS-10 plus10, tail genuine no-op; next2.
// R6GameService.dll @ 10069d2e : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// State4: CURRENT saved ownerS-14 plus20, whole bucket destruction; next0.
// R6GameService.dll @ 10069d39 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::ForwardBucketCleanup
  }
}

// State5: original argument slotS+4 address, tail genuine temporary no-op; next4.
// R6GameService.dll @ 10069d44 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// State6: CURRENT saved ownerS-14 plus38, complete clPointerDeque<clSegment*> destruction; next4.
// R6GameService.dll @ 10069d4c : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x38
    jmp    R6GameServiceAddresses::ForwardClSegmentPointerDequeDestroy
  }
}

// State7: original argument slotS+4 address, tail genuine temporary no-op; next6. No WORD-storage release.
// R6GameService.dll @ 10069d57 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordUnwind8(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact eight-state association construction map8482c/FuncInfo8486c, then tail CRT dispatch.
// R6GameService.dll @ 10069d5f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectAssociationConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeKeyedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 1008482c : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeKeyedRecordUnwindMap[8] = {
  {-1, R6GameServiceAddresses::InitializeKeyedRecordUnwind1},
  {0x0, R6GameServiceAddresses::InitializeKeyedRecordUnwind2},
  {0x1, R6GameServiceAddresses::InitializeKeyedRecordUnwind3},
  {0x2, R6GameServiceAddresses::InitializeKeyedRecordUnwind4},
  {0x0, R6GameServiceAddresses::InitializeKeyedRecordUnwind5},
  {0x4, R6GameServiceAddresses::InitializeKeyedRecordUnwind6},
  {0x4, R6GameServiceAddresses::InitializeKeyedRecordUnwind7},
  {0x6, R6GameServiceAddresses::InitializeKeyedRecordUnwind8},
};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 1008482c : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeKeyedRecordExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::InitializeKeyedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Copy uninitialized local byteS-19 into three cookie bytes, zero pointer triplet/count, select193 buckets for request100.
// Reserve then insert zero slots; return owner. Saved ownerS-10/stateS-4; exact three-state cleanup preserves native stack data.
// R6GameService.dll @ 10060990 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall InitializeKeyedRecordIndex(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectKeyTableConstructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0x1c],esi
    mov    al,BYTE PTR [esp+0x13]
    mov    cl,BYTE PTR [esp+0x13]
    mov    dl,BYTE PTR [esp+0x13]
    lea    edi,[esi+0x4]
    xor    ebx,ebx
    mov    BYTE PTR [esi],al
    mov    BYTE PTR [esi+0x1],cl
    mov    BYTE PTR [esi+0x2],dl
    mov    DWORD PTR [edi],ebx
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [esp+0x28],ebx
    mov    DWORD PTR [edi+0x8],ebx
    mov    DWORD PTR [esi+0x10],ebx
    mov    eax,DWORD PTR [esp+0x1c]
    push    ebx
    lea    ecx,[esp+0x18]
    push    eax
    push    ecx
    push    R6GameServiceAddresses::GCompilerCookieScope
    push    R6GameServiceAddresses::WideText52
    mov    BYTE PTR [esp+0x3c],0x2
    mov    DWORD PTR [esp+0x28],0x64
    call    R6GameServiceAddresses::LowerBoundUnsignedDwords
    cmp    eax,R6GameServiceAddresses::GCompilerCookieScope
    mov    ebp,0xfffffffb
    je    Branch25
    mov    ebp,DWORD PTR [eax]
  Branch25:
    push    ebp
    mov    ecx,edi
    call    R6GameServiceAddresses::EnsurePointerArrayCapacity
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push    edx
    push    ebp
    push    eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x24],ebx
    call    R6GameServiceAddresses::InsertRepeatedPointerValue
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esi+0x10],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret
  }
}

// Select lower-bound bucket count, ensure at least that capacity, then APPEND that many zero slots and reset node count10.
// Preserve old slots, separate cached insertion end/current end reads, generic in-place branches and rebuild path.
// Raw EAX depends on path: append0, rebuilt final free result, long suffix owner, short suffix bytes; RET4, no local EH.
// R6GameService.dll @ 10060ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendSelectedBucketSlotsAndResetCount(void *owner,uint requestedCount)
{
  __asm {
    sub    esp,0xc
    push    ebx
    push    ebp
    mov    ebp,ecx
    push    esi
    mov    esi,DWORD PTR [esp+0x1c]
    push    edi
    mov    DWORD PTR [esp+0x10],ebp
    mov    edx,R6GameServiceAddresses::WideText52
    mov    ecx,0x1c
  Branch26:
    mov    eax,ecx
    sar    eax,1
    cmp    DWORD PTR [edx+eax*4],esi
    jae    Branch27
    or    edi,0xffffffff
    lea    edx,[edx+eax*4+0x4]
    sub    edi,eax
    add    ecx,edi
    jmp    Branch28
  Branch27:
    mov    ecx,eax
  Branch28:
    test    ecx,ecx
    jg    Branch26
    cmp    edx,R6GameServiceAddresses::GCompilerCookieScope
    mov    edi,0xfffffffb
    je    Branch29
    mov    edi,DWORD PTR [edx]
  Branch29:
    mov    eax,DWORD PTR [ebp+0x4]
    mov    ecx,DWORD PTR [ebp+0xc]
    lea    esi,[ebp+0x4]
    sub    ecx,eax
    sar    ecx,0x2
    cmp    ecx,edi
    jae    Branch32
    mov    ecx,DWORD PTR [esi+0x4]
    mov    ebx,ecx
    sub    ebx,eax
    sar    ebx,0x2
    test    eax,eax
    je    Branch30
    push    ecx
    push    eax
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::ClonePointerArrayAllocation
    mov    edx,DWORD PTR [esi]
    mov    ebp,eax
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    jmp    Branch31
  Branch30:
    lea    eax,[edi*4+0x0]
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
  Branch31:
    lea    ecx,[ebp+ebx*4+0x0]
    lea    edx,[ebp+edi*4+0x0]
    mov    DWORD PTR [esi],ebp
    mov    ebp,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],edx
  Branch32:
    mov    ebx,DWORD PTR [ebp+0x8]
    xor    ecx,ecx
    cmp    edi,ecx
    mov    DWORD PTR [esp+0x18],ecx
    je    Branch39
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
    sar    edx,0x2
    cmp    edx,edi
    jb    Branch38
    mov    ebp,DWORD PTR [esi+0x4]
    sub    eax,ebx
    sar    eax,0x2
    cmp    eax,edi
    mov    DWORD PTR [esp+0x14],eax
    jbe    Branch34
    mov    al,BYTE PTR [esp+0x20]
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x20],al
    mov    eax,ebp
    shl    edi,0x2
    push    ecx
    sub    eax,edi
    push    ebp
    push    ebp
    push    eax
    mov    DWORD PTR [esp+0x24],eax
    call    R6GameServiceAddresses::CopyByteRange
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esp+0x14]
    push    ebp
    add    ecx,edi
    push    edx
    push    ebx
    mov    DWORD PTR [esi+0x4],ecx
    call    R6GameServiceAddresses::MoveByteRangeToEnd
    add    edi,ebx
    cmp    ebx,edi
    je    Branch37
  Branch33:
    mov    DWORD PTR [ebx],0x0
    add    ebx,0x4
    cmp    ebx,edi
    jne    Branch33
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax+0x10],0x0
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch34:
    mov    edx,edi
    sub    edx,eax
    je    Branch35
    mov    ecx,edx
    xor    eax,eax
    mov    edi,ebp
    rep    stos DWORD PTR es:[edi],eax
  Branch35:
    mov    edi,DWORD PTR [esi+0x4]
    lea    ecx,[edx*4+0x0]
    mov    dl,BYTE PTR [esp+0x20]
    add    edi,ecx
    lea    ecx,[esp+0x20]
    mov    eax,edi
    push    ecx
    push    eax
    push    ebp
    push    ebx
    mov    DWORD PTR [esi+0x4],edi
    mov    BYTE PTR [esp+0x30],dl
    call    R6GameServiceAddresses::CopyByteRange
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[edx*4+0x0]
    add    ecx,eax
    cmp    ebx,ebp
    mov    DWORD PTR [esi+0x4],ecx
    je    Branch40
  Branch36:
    mov    DWORD PTR [ebx],0x0
    add    ebx,0x4
    cmp    ebx,ebp
    jne    Branch36
  Branch37:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ecx+0x10],0x0
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch38:
    push    ecx
    lea    edx,[esp+0x24]
    push    edi
    lea    eax,[esp+0x20]
    push    edx
    push    eax
    push    ebx
    mov    ecx,esi
    call    R6GameServiceAddresses::RebuildPointerArrayWithRepeatedValue
    pop    edi
    mov    DWORD PTR [ebp+0x10],0x0
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch39:
    pop    edi
    mov    DWORD PTR [ebp+0x10],ecx
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch40:
    mov    edx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [edx+0x10],0x0
    pop    ebx
    add    esp,0xc
    ret    0x4
  }
}

// State0: parent entryS-1 address to genuine no-op; next-1.
// R6GameService.dll @ 10069e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordIndexUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x1]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// State1: CURRENT saved ownerS-10 plus4 first-word allocation release; next0.
// R6GameService.dll @ 10069e48 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordIndexUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x4
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// State2: CURRENT saved ownerS-10 plus10 genuine no-op; next1.
// R6GameService.dll @ 10069e53 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeKeyedRecordIndexUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact three-state key-table constructor map84950/FuncInfo84968, then tail CRT dispatch.
// R6GameService.dll @ 10069e5e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectKeyTableConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeKeyedRecordIndexExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal key-table construction cleanup map or FuncInfo.
// R6GameService.dll data @ 10084950 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeKeyedRecordIndexUnwindMap[3] = {
  {-1, R6GameServiceAddresses::InitializeKeyedRecordIndexUnwind1},
  {0x0, R6GameServiceAddresses::InitializeKeyedRecordIndexUnwind2},
  {0x1, R6GameServiceAddresses::InitializeKeyedRecordIndexUnwind3},
};

// Literal key-table construction cleanup map or FuncInfo.
// R6GameService.dll data @ 10084950 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeKeyedRecordIndexExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::InitializeKeyedRecordIndexUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// If request exceeds cached bucket count, select deployed prime, allocate/fill buckets and prepend each old node by WORD key.
// Cache old bucket count but reload current old base after each node; leave payloads/keys/node count10 untouched.
// Publish new triplet and swap current old triplet into temporaryS-1c..S-14 BEFORE free; state0 stays armed at normal free.
// Raw EAX: request when first gate skips, lower-bound pointer when selected-count gate skips, zero/free result after swap. RET4.
// R6GameService.dll @ 10061970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall Rehash16BitKeyTable(void *table,uint requestedCount)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectWordKeyRehashEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    mov    eax,DWORD PTR [esp+0x2c]
    push    ebx
    lea    ebx,[ecx+0x4]
    push    ebp
    push    esi
    mov    ebp,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    sub    ebp,esi
    push    edi
    sar    ebp,0x2
    cmp    eax,ebp
    jbe    Branch46
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esp+0x3c]
    xor    edi,edi
    lea    ecx,[esp+0x14]
    push    edi
    push    eax
    push    ecx
    push    R6GameServiceAddresses::GCompilerCookieScope
    push    R6GameServiceAddresses::WideText52
    call    R6GameServiceAddresses::LowerBoundUnsignedDwords
    cmp    eax,R6GameServiceAddresses::GCompilerCookieScope
    mov    esi,0xfffffffb
    je    Branch41
    mov    esi,DWORD PTR [eax]
  Branch41:
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x10],esi
    jbe    Branch46
    lea    edx,[esp+0x3c]
    mov    ecx,ebx
    push    edx
    mov    DWORD PTR [esp+0x1c],edi
    call    R6GameServiceAddresses::ForwardStackWord
    push    eax
    push    esi
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::InitializeDwordBufferWithCapacity
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    eax,[esp+0x18]
    push    eax
    push    esi
    push    ecx
    mov    DWORD PTR [esp+0x40],edi
    call    R6GameServiceAddresses::FillRepeatedDword
    mov    DWORD PTR [esp+0x20],eax
    test    ebp,ebp
    jbe    Branch45
    mov    esi,DWORD PTR [ebx]
  Branch42:
    mov    ecx,DWORD PTR [esi+edi*4]
    test    ecx,ecx
    je    Branch44
  Branch43:
    xor    eax,eax
    xor    edx,edx
    mov    ax,WORD PTR [ecx+0x4]
    div    DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esi+edi*4],eax
    mov    eax,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [eax+edx*4]
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [eax+edx*4],ecx
    mov    esi,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+edi*4]
    test    ecx,ecx
    jne    Branch43
  Branch44:
    inc    edi
    cmp    edi,ebp
    jb    Branch42
  Branch45:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [ebx],ecx
    mov    ecx,DWORD PTR [ebx+0x4]
    mov    DWORD PTR [ebx+0x4],edx
    mov    edx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x20],ecx
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    DWORD PTR [esp+0x1c],eax
    test    eax,eax
    mov    DWORD PTR [ebx+0x8],edx
    mov    DWORD PTR [esp+0x24],ecx
    je    Branch46
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch46:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x4
  }
}

// Scan cached first bucket pointer with current end/base-derived bound; return first nonzero head or NULL plus table.
// Reload result argument late and store node before table; return result pointer/RET4, no node/count mutation.
// R6GameService.dll @ 10060a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall GetFirstNonemptyBucketIterator(void *table,void *result)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x8]
    push    ebx
    push    esi
    push    edi
    mov    edi,DWORD PTR [ecx+0x4]
    xor    eax,eax
    sub    edx,edi
    sar    edx,0x2
    je    Branch48
    mov    esi,edi
    mov    edx,esi
  Branch47:
    cmp    DWORD PTR [edx],0x0
    jne    Branch49
    mov    edi,DWORD PTR [ecx+0x8]
    mov    ebx,DWORD PTR [ecx+0x4]
    sub    edi,ebx
    inc    eax
    sar    edi,0x2
    add    edx,0x4
    cmp    eax,edi
    jb    Branch47
  Branch48:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR [eax],0x0
    mov    DWORD PTR [eax+0x4],ecx
    ret    0x4
  Branch49:
    mov    edx,DWORD PTR [esi+eax*4]
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],edx
    mov    DWORD PTR [eax+0x4],ecx
    pop    ebx
    ret    0x4
  }
}

// Hash current iterator node WORD key, scan strictly later buckets using current base and cached post-hash count.
// Does not follow current node.next or mutate iterator; no empty-table/node guard, return full next head or NULL.
// R6GameService.dll @ 100618a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall FindNextNonemptyBucket(void *iterator)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push    esi
    mov    esi,DWORD PTR [ecx+0x4]
    push    edi
    xor    ecx,ecx
    mov    edi,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    mov    cx,WORD PTR [eax+0x4]
    sub    edi,edx
    sar    edi,0x2
    mov    eax,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    xor    edx,edx
    div    edi
    sub    ecx,DWORD PTR [esi+0x4]
    sar    ecx,0x2
    xor    eax,eax
  Branch50:
    inc    edx
    cmp    edx,ecx
    jae    Branch51
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax+edx*4]
    test    eax,eax
    je    Branch50
  Branch51:
    pop    edi
    pop    esi
    ret
  }
}

// Cache search WORD, unsigned-divide by signed bucket-distance/4, then find first matching chain node.
// Store node/table into late-loaded result and return it/RET8; no empty-table guard, payload read or table mutation.
// R6GameService.dll @ 10061b00 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall FindKeyIterator(void *table,void *result,const ushort *key)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx+0x4]
    push    esi
    push    edi
    mov    si,WORD PTR [eax]
    mov    edi,DWORD PTR [ecx+0x8]
    sub    edi,edx
    mov    eax,esi
    sar    edi,0x2
    and    eax,0xffff
    xor    edx,edx
    div    edi
    mov    eax,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [eax+edx*4]
    test    edx,edx
    je    Branch53
  Branch52:
    cmp    WORD PTR [edx+0x4],si
    je    Branch53
    mov    edx,DWORD PTR [edx]
    test    edx,edx
    jne    Branch52
  Branch53:
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],edx
    mov    DWORD PTR [eax+0x4],ecx
    ret    0x8
  }
}

// Cache search WORD, select bucket by unsigned modulo signed-distance bucket count, walk first key match.
// Return full node pointer or NULL/RET4; no empty-table guard, payload read or node mutation.
// R6GameService.dll @ 10061fe0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall FindKeyNode(void *table,const ushort *key)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    push    esi
    push    edi
    mov    si,WORD PTR [eax]
    mov    edi,DWORD PTR [ecx+0x8]
    sub    edi,edx
    mov    eax,esi
    sar    edi,0x2
    and    eax,0xffff
    xor    edx,edx
    div    edi
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [ecx+edx*4]
    test    eax,eax
    je    Branch55
  Branch54:
    cmp    WORD PTR [eax+0x4],si
    je    Branch55
    mov    eax,DWORD PTR [eax]
    test    eax,eax
    jne    Branch54
  Branch55:
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Allocate12 bytes, clear next0, then reload current record argument and copy WORD key0/DWORD payload4 to node4/8.
// Leave node padding6..7 untouched. The key-subobject NULL test occurs AFTER unconditional next store; no allocation guard. RET4.
// R6GameService.dll @ 10061d10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint * __stdcall AllocateWordKeyNode(const void *record)
{
  __asm {
    push    0xc
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x4]
    mov    DWORD PTR [eax],0x0
    test    ecx,ecx
    je    Branch56
    mov    edx,DWORD PTR [esp+0x4]
    push    esi
    mov    si,WORD PTR [edx]
    mov    WORD PTR [ecx],si
    mov    edx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    pop    esi
  Branch56:
    ret    0x4
  }
}

// Pass parent entryS-1c CELL address to shared first-word release; free CURRENT temporary begin if nonnull.
// R6GameService.dll @ 10069e90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl Rehash16BitKeyTableUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Pass parent entryS-1c CELL address to shared first-word release; free CURRENT temporary begin if nonnull.
// R6GameService.dll @ 10069e98 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl Rehash16BitKeyTableUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Select exact four-state rehash map849b0/FuncInfo849d0, retaining dormant states and both distinct cleanup bodies.
// R6GameService.dll @ 10069ea0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectWordKeyRehashEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::Rehash16BitKeyTableExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal four-state rehash cleanup map or FuncInfo; this native entry arms only state0.
// R6GameService.dll data @ 100849b0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry Rehash16BitKeyTableUnwindMap[4] = {
  {-1, R6GameServiceAddresses::Rehash16BitKeyTableUnwind1},
  {-1, R6GameServiceAddresses::Rehash16BitKeyTableUnwind2},
  {0x1, 0x0},
  {0x1, 0x0},
};

// Literal four-state rehash cleanup map or FuncInfo; this native entry arms only state0.
// R6GameService.dll data @ 100849b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo Rehash16BitKeyTableExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::Rehash16BitKeyTableUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Lazily construct global table, reuse by port when mode lowBYTE!=0 or scan below count7fff when zero; otherwise allocate owner98.
// Populate inner/global WORD-key maps after socket/ID success; ignore insertion flags, retain current returned node payload and port reads.
// Entry S: global allocation/iteratorS-34, flag/keyS-3c, stateS-4; consumed PORT slotS+8 becomes current owner allocation.
// Normal failure reloads current global, tests count before late NULL guard, frees empty global then current new owner. RET20.
// Exact three-state construction guards only free raw allocations/no-op base; they do not replace normal failure cleanup.
// R6GameService.dll @ 1005fdb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall FindOrCreateKeyedRecord(
    uint address,ushort *port,ushort *entryId,uint payloadWord,uint modeWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectFindOrCreateKeyedRecordEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x30
    push    ebp
    push    esi
    mov    DWORD PTR [esp+0x8],0x0
    mov    ecx,DWORD PTR ds:0x100945b0
    push    edi
    xor    edi,edi
    test    ecx,ecx
    jne    Branch59
    push    0x18
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x14],esi
    test    esi,esi
    mov    DWORD PTR [esp+0x44],edi
    je    Branch57
    mov    DWORD PTR [esi+0x14],0x1007831c
    mov    DWORD PTR [esp+0xc],0x1
    mov    ecx,esi
    mov    BYTE PTR [esp+0x44],0x1
    call    R6GameServiceAddresses::InitializeKeyedRecordIndex
    mov    ecx,esi
    jmp    Branch58
  Branch57:
    xor    ecx,ecx
  Branch58:
    test    ecx,ecx
    mov    DWORD PTR [esp+0x44],0xffffffff
    mov    DWORD PTR ds:0x100945b0,ecx
    jne    Branch59
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x30]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x3c
    ret    0x14
  Branch59:
    mov    al,BYTE PTR [esp+0x5c]
    mov    ebp,DWORD PTR [esp+0x50]
    test    al,al
    je    Branch62
    lea    eax,[esp+0x14]
    push    ebp
    push    eax
    call    R6GameServiceAddresses::FindKeyIterator
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x1c],eax
    mov    DWORD PTR [esp+0x20],ecx
  Branch60:
    test    eax,eax
    jne    Branch67
  Branch61:
    push    0x98
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x50],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x44],0x2
    je    Branch65
    push    0x1
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeKeyedRecord
    mov    esi,eax
    jmp    Branch66
  Branch62:
    lea    edx,[esp+0x14]
    push    edx
    call    R6GameServiceAddresses::GetFirstNonemptyBucketIterator
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x18]
    test    eax,eax
    mov    DWORD PTR [esp+0x1c],eax
    mov    DWORD PTR [esp+0x20],ecx
    je    Branch61
  Branch63:
    mov    edx,DWORD PTR [eax+0x8]
    cmp    DWORD PTR [edx+0x30],0x7fff
    jb    Branch60
    mov    eax,DWORD PTR [eax]
    test    eax,eax
    jne    Branch64
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::FindNextNonemptyBucket
  Branch64:
    test    eax,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch63
    jmp    Branch61
  Branch65:
    xor    esi,esi
  Branch66:
    mov    edi,esi
    mov    DWORD PTR [esp+0x44],0xffffffff
    test    esi,esi
    mov    DWORD PTR [esp+0x50],edi
    je    Branch69
    mov    eax,DWORD PTR [esp+0x5c]
    mov    ecx,DWORD PTR [esp+0x4c]
    push    eax
    push    ebp
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::OpenAndBindRecordSocket
    test    al,al
    je    Branch68
    mov    edi,DWORD PTR [esp+0x54]
    mov    ecx,esi
    push    edi
    call    R6GameServiceAddresses::TakeNextAvailableId
    test    al,al
    je    Branch68
    mov    dx,WORD PTR [edi]
    mov    ecx,DWORD PTR [esi+0x30]
    mov    eax,DWORD PTR [esp+0x58]
    lea    edi,[esi+0x20]
    inc    ecx
    mov    WORD PTR [esp+0x14],dx
    push    ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x1c],eax
    call    R6GameServiceAddresses::Rehash16BitKeyTable
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x24]
    push    edx
    push    eax
    mov    ecx,edi
    call    R6GameServiceAddresses::FindOrInsert16BitKeyNode
    mov    cx,WORD PTR [ebp+0x0]
    mov    edi,DWORD PTR ds:0x100945b0
    mov    WORD PTR [esp+0x14],cx
    mov    DWORD PTR [esp+0x18],esi
    mov    edx,DWORD PTR [edi+0x10]
    mov    ecx,edi
    inc    edx
    push    edx
    call    R6GameServiceAddresses::Rehash16BitKeyTable
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x24]
    push    eax
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::FindOrInsert16BitKeyNode
    mov    dx,WORD PTR [ebp+0x0]
    mov    eax,esi
    mov    WORD PTR [esi+0x4],dx
    pop    edi
    pop    esi
    pop    ebp
    mov    ecx,DWORD PTR [esp+0x30]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x3c
    ret    0x14
  Branch67:
    mov    esi,DWORD PTR [esp+0x54]
    mov    ecx,DWORD PTR [eax+0x8]
    push    esi
    call    R6GameServiceAddresses::TakeNextAvailableId
    test    al,al
    je    Branch69
    mov    ax,WORD PTR [esi]
    mov    ecx,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [esp+0x1c]
    mov    WORD PTR [esp+0xc],ax
    mov    DWORD PTR [esp+0x10],ecx
    mov    esi,DWORD PTR [edx+0x8]
    add    esi,0x20
    mov    ecx,esi
    mov    eax,DWORD PTR [esi+0x10]
    inc    eax
    push    eax
    call    R6GameServiceAddresses::Rehash16BitKeyTable
    lea    ecx,[esp+0xc]
    lea    edx,[esp+0x30]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FindOrInsert16BitKeyNode
    pop    edi
    pop    esi
    mov    eax,DWORD PTR [esp+0x14]
    pop    ebp
    mov    eax,DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR [esp+0x30]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x3c
    ret    0x14
  Branch68:
    mov    edi,DWORD PTR [esp+0x50]
  Branch69:
    mov    esi,DWORD PTR ds:0x100945b0
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    jne    Branch71
    test    esi,esi
    je    Branch70
    mov    ecx,esi
    call    R6GameServiceAddresses::DestroyBucketChains
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch70:
    mov    DWORD PTR ds:0x100945b0,0x0
  Branch71:
    test    edi,edi
    je    Branch72
    mov    ecx,edi
    call    R6GameServiceAddresses::DestroyKeyedRecordStorage
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch72:
    mov    ecx,DWORD PTR [esp+0x3c]
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x3c
    ret    0x14
  }
}

// If WORD deque empty, store lowWORD of count30+1 iff unsigned wrapped value<=fffff; do not increment count.
// Otherwise take current first WORD and advance2 or free current block/reload current next slot; no output/key clearing.
// Empty path returns full0/1; recycled path sets only AL1 of new current pointer. RET4, no local EH.
// R6GameService.dll @ 10060050 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TakeNextAvailableId(void *owner,ushort *value)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x84]
    mov    edx,DWORD PTR [esi+0x74]
    mov    ecx,DWORD PTR [esi+0x78]
    sub    eax,edx
    mov    edx,DWORD PTR [esi+0x7c]
    sar    eax,0x2
    dec    eax
    sub    ecx,edx
    mov    edx,DWORD PTR [esi+0x70]
    shl    eax,0x6
    sar    ecx,1
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x68]
    sub    edx,ecx
    sar    edx,1
    add    eax,edx
    je    Branch74
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    mov    cx,WORD PTR [eax]
    mov    WORD PTR [edx],cx
    mov    ecx,DWORD PTR [esi+0x70]
    mov    eax,DWORD PTR [esi+0x68]
    sub    ecx,0x2
    cmp    eax,ecx
    je    Branch73
    add    eax,0x2
    mov    DWORD PTR [esi+0x68],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch73:
    mov    edx,DWORD PTR [esi+0x6c]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x74]
    add    eax,0x4
    mov    DWORD PTR [esi+0x74],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x6c],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x70],eax
    mov    eax,DWORD PTR [esi+0x6c]
    mov    DWORD PTR [esi+0x68],eax
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch74:
    mov    esi,DWORD PTR [esi+0x30]
    inc    esi
    cmp    esi,0xfffff
    jbe    Branch75
    xor    al,al
    pop    esi
    ret    0x4
  Branch75:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    al,0x1
    mov    WORD PTR [ecx],si
    pop    esi
    ret    0x4
  }
}

// Create/configure embedded socket. Zero flag lowBYTE clamps port>=400, retries with ffff->400 wrap until predecessor sentinel.
// Nonzero flag binds once to address0, ignores status, then follows stored-error/close/failure even after successful bind.
// Preserve full physical port words, late field reads, cached port/predecessor and AL-only status; no own EH. RET12.
// R6GameService.dll @ 10060540 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenAndBindRecordSocket(void *owner,uint address,ushort *port,uint flagWord)
{
  __asm {
    push    ecx
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0xc],esi
    lea    ebx,[esi+0x8]
    mov    ecx,ebx
    call    R6GameServiceAddresses::CreateIPv4DatagramSocket
    test    al,al
    je    Branch81
    push    0x1
    mov    ecx,ebx
    call    R6GameServiceAddresses::SetSocketNonblocking
    test    al,al
    je    Branch81
    mov    al,BYTE PTR [esp+0x1c]
    test    al,al
    jne    Branch83
    mov    esi,DWORD PTR [esp+0x18]
    mov    ax,WORD PTR [esi]
    cmp    ax,0x400
    jae    Branch76
    mov    eax,0x400
    jmp    Branch77
  Branch76:
    and    eax,0xffff
  Branch77:
    cmp    ax,0x400
    mov    WORD PTR [esi],ax
    mov    edi,0xffff
    jb    Branch78
    lea    edi,[eax-0x1]
  Branch78:
    mov    ax,WORD PTR [esi]
    mov    ecx,DWORD PTR [esp+0x14]
    push    eax
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::BindIPv4Socket
    test    al,al
    jne    Branch82
    mov    ax,WORD PTR [esi]
    cmp    ax,0xffff
    jne    Branch79
    mov    eax,0x400
    jmp    Branch80
  Branch79:
    and    eax,0xffff
    inc    eax
  Branch80:
    cmp    ax,di
    mov    WORD PTR [esi],ax
    jne    Branch78
    mov    esi,DWORD PTR [esp+0xc]
  Branch81:
    mov    ecx,ebx
    call    R6GameServiceAddresses::GetSocketLastError
    mov    ecx,ebx
    mov    DWORD PTR [esi+0x18],eax
    call    R6GameServiceAddresses::CloseSocketAndReset
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    pop    ecx
    ret    0xc
  Branch82:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0xc
  Branch83:
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,ebx
    mov    ax,WORD PTR [edx]
    push    eax
    push    0x0
    call    R6GameServiceAddresses::BindIPv4Socket
    jmp    Branch81
  }
}

// Cache search WORD/hash/head, return existing first match without replacing payload; otherwise allocate/copy current record.
// New node.next uses cached old head, publication uses CURRENT base and count; output table before node, then one BYTE flag.
// Reload result late, preserve trailing output padding, return result pointer/RET8. No rehash, node NULL guard or local EH.
// R6GameService.dll @ 10061100 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall FindOrInsert16BitKeyNode(void *table,void *result,const void *record)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push    ebx
    push    ebp
    push    esi
    mov    bx,WORD PTR [eax]
    mov    esi,ecx
    mov    eax,ebx
    xor    edx,edx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    ebp,DWORD PTR [esi+0x4]
    sub    ecx,ebp
    and    eax,0xffff
    sar    ecx,0x2
    div    ecx
    push    edi
    mov    ebp,edx
    mov    edx,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [edx+ebp*4]
    test    edi,edi
    mov    ecx,edi
    je    Branch85
  Branch84:
    cmp    WORD PTR [ecx+0x4],bx
    je    Branch86
    mov    ecx,DWORD PTR [ecx]
    test    ecx,ecx
    jne    Branch84
  Branch85:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::AllocateWordKeyNode
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR [esi+0x4]
    pop    edi
    mov    DWORD PTR [ecx+ebp*4],eax
    mov    ecx,DWORD PTR [esi+0x10]
    inc    ecx
    mov    DWORD PTR [esi+0x10],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ecx+0x4],esi
    pop    esi
    mov    DWORD PTR [ecx],eax
    pop    ebp
    mov    BYTE PTR [ecx+0x8],0x1
    mov    eax,ecx
    pop    ebx
    ret    0x8
  Branch86:
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    mov    DWORD PTR [eax+0x4],esi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],ecx
    mov    BYTE PTR [eax+0x8],0x0
    pop    ebx
    ret    0x8
  }
}

// State0: free CURRENT saved global allocationS-34 via shared allocation tail; no container destruction.
// R6GameService.dll @ 10069cd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl FindOrCreateKeyedRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x34]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// State1: if CURRENT flagS-3c bit0 is set, tail no-op on CURRENT global allocationS-34 plus18; then state0.
// R6GameService.dll @ 10069cda : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl FindOrCreateKeyedRecordUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x3c]
    and    eax,0x1
    test    eax,eax
    je    Branch87
    mov    ecx,DWORD PTR [ebp-0x34]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch87:
    ret
  }
}

// State2: free CURRENT rewritten original PORT argument slotS+8; no owner destructor, next-1.
// R6GameService.dll @ 10069cf4 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl FindOrCreateKeyedRecordUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select exact three-state find/create map847f8/FuncInfo84810, then tail CRT dispatch.
// R6GameService.dll @ 10069cfe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectFindOrCreateKeyedRecordEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::FindOrCreateKeyedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal find/create construction cleanup map or FuncInfo.
// R6GameService.dll data @ 100847f8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry FindOrCreateKeyedRecordUnwindMap[3] = {
  {-1, R6GameServiceAddresses::FindOrCreateKeyedRecordUnwind1},
  {0x0, R6GameServiceAddresses::FindOrCreateKeyedRecordUnwind2},
  {-1, R6GameServiceAddresses::FindOrCreateKeyedRecordUnwind3},
};

// Literal find/create construction cleanup map or FuncInfo.
// R6GameService.dll data @ 100847f8 : native storage identity retained.
const R6GameServiceNative::FuncInfo FindOrCreateKeyedRecordExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::FindOrCreateKeyedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Cache requested lowWORD; when unsigned request>=current capacity, free current buffer before publishing capped capacity/malloc.
// Cap at1000, publish literal NULL allocation, clear only AL if above cap; otherwise set only AL1, even on no-growth path. RET4.
// R6GameService.dll @ 100604e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EnsureReceiveBufferCapacity(void *owner,uint requestedWord)
{
  __asm {
    push    ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push    esi
    push    edi
    mov    esi,ecx
    mov    edi,ebx
    and    edi,0xffff
    cmp    edi,DWORD PTR [esi+0x1c]
    jb    Branch89
    mov    eax,DWORD PTR [esi+0x94]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    bx,0x1000
    jbe    Branch88
    push    0x1000
    mov    DWORD PTR [esi+0x1c],0x1000
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x94],eax
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x4
  Branch88:
    push    edi
    mov    DWORD PTR [esi+0x1c],edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x94],eax
  Branch89:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x4
  }
}

// Receive up to1000 positive datagrams, queue only length>=8 with a matching WORD key at current buffer+2.
// Construct28-byte owning byte-record from current buffer/sender, then publish replacement buffer before current node payload slot4 call.
// Preserve NULL record delivery, cached node/length, scratch-flag writes, current buffer/capacity/payload reloads and no local EH.
// Return raw nonpositive receive result or full1000 at iteration limit; no stack arguments.
// R6GameService.dll @ 10060660 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReceiveAndQueueKeyedDatagrams(void *owner)
{
  __asm {
    sub    esp,0x1c
    push    ebx
    push    ebp
    xor    eax,eax
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x14],eax
  Branch90:
    mov    edx,DWORD PTR [esi+0x1c]
    lea    eax,[esp+0x1c]
    push    0x0
    lea    ecx,[esp+0x24]
    push    eax
    mov    eax,DWORD PTR [esi+0x94]
    push    ecx
    push    edx
    push    eax
    lea    ecx,[esi+0x8]
    call    R6GameServiceAddresses::ReceiveFromSocket
    mov    ebx,eax
    test    ebx,ebx
    jle    Branch94
    cmp    ebx,0x8
    jl    Branch93
    mov    ecx,DWORD PTR [esi+0x94]
    lea    eax,[esp+0x18]
    push    eax
    mov    dx,WORD PTR [ecx+0x2]
    lea    ecx,[esi+0x20]
    mov    DWORD PTR [esp+0x1c],edx
    call    R6GameServiceAddresses::FindKeyNode
    mov    ebp,eax
    test    ebp,ebp
    mov    DWORD PTR [esp+0x24],ebp
    je    Branch93
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    test    eax,eax
    je    Branch91
    mov    ebp,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esi+0x94]
    mov    edx,DWORD PTR [esp+0x1c]
    or    ebp,0x1
    mov    DWORD PTR [eax+0x8],edi
    mov    DWORD PTR [esp+0x10],ebp
    mov    ebp,DWORD PTR [esp+0x24]
    mov    DWORD PTR [eax+0x4],0x100782f8
    mov    WORD PTR [eax+0xc],dx
    mov    DWORD PTR [eax+0x10],ecx
    mov    DWORD PTR [eax+0x14],ebx
    mov    DWORD PTR [eax+0x18],ecx
    mov    DWORD PTR [eax],R6GameServiceAddresses::clSegmentVTable
    mov    edi,eax
    jmp    Branch92
  Branch91:
    xor    edi,edi
  Branch92:
    mov    ecx,DWORD PTR [esi+0x1c]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x94],eax
    mov    ecx,DWORD PTR [ebp+0x8]
    push    edi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x4]
  Branch93:
    mov    eax,DWORD PTR [esp+0x14]
    inc    eax
    cmp    eax,0x3e8
    mov    DWORD PTR [esp+0x14],eax
    jl    Branch90
  Branch94:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x1c
    ret
  }
}
