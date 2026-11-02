#include "native_addresses.h"
#include "native_records.h"

// Segmented word storage: two16-byte cursors plus map/capacity; whole class identity remains unresolved.

// Clear ten DWORDs, arm two empty-base cleanup states and initialize storage with CURRENT second full argument.
// EntryS: saved ownerS-10/stateS-4. First argument unused. Constructor guards only call no-op at+20/+24; RET8/owner.
// R6GameService.dll @ 1005eda0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeSegmentedWords(void *owner,uint unusedWord,uint count)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSegmentedWordCtorEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    mov    esi,ecx
    xor    eax,eax
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x14],eax
    mov    DWORD PTR [esi+0x18],eax
    mov    DWORD PTR [esi+0x1c],eax
    mov    DWORD PTR [esi+0x20],eax
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esi+0x24],eax
    mov    eax,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x10],0x1
    push    eax
    call    R6GameServiceAddresses::InitializeSegmentedWordBuffer
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Tail-forward original receiver/registers/stack and raw return to segmented-word destruction.
// R6GameService.dll @ 1005d120 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardSegmentedWordDestroy(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::ReleaseSegmentedWordStorage
  }
}

// Snapshot finish and perform five literal cursor copies, then gate on current map20 and release active block slots inclusively.
// Cache slot range c..1c+4 before frees; reload each slot payload and CURRENT map20 for final free. Leave all owner fields stale.
// EntryS: saved ownerS-70/stateS-4. State0 stays armed through normal cleanup; unwind repeats current release viaf480.
// R6GameService.dll @ 1005d130 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseSegmentedWordStorage(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSegmentedWordDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x64
    push    ebx
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x4],ebx
    lea    eax,[ebx+0x10]
    push    ebx
    mov    DWORD PTR [esp+0x74],0x0
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esp+0xc],ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [esp+0x10],edx
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esp+0x14],ecx
    lea    ecx,[esp+0x1c]
    mov    edx,DWORD PTR [eax+0xc]
    mov    DWORD PTR [esp+0x18],edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x8]
    lea    ecx,[esp+0x28]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x18]
    push    ecx
    lea    ecx,[esp+0x3c]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0x48]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x58]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    eax,DWORD PTR [ebx+0x20]
    test    eax,eax
    je    Branch3
    push    esi
    mov    esi,DWORD PTR [ebx+0xc]
    push    edi
    mov    edi,DWORD PTR [ebx+0x1c]
    add    edi,0x4
    cmp    esi,edi
    jae    Branch2
  Branch1:
    mov    ecx,DWORD PTR [esi]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    esi,0x4
    cmp    esi,edi
    jb    Branch1
  Branch2:
    mov    edx,DWORD PTR [ebx+0x20]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
  Branch3:
    mov    ecx,DWORD PTR [esp+0x68]
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret
  }
}

// Copy four DWORDs forward in native read/store order, preserving partial overlap; return original destination/RET4.
// R6GameService.dll @ 1005ed50 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CopySegmentedCursor(void *destination,const uint *source)
{
  __asm {
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0x4]
    push    esi
    mov    edx,eax
    mov    esi,DWORD PTR [ecx]
    mov    DWORD PTR [edx],esi
    mov    esi,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],esi
    mov    esi,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [edx+0x8],esi
    pop    esi
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [edx+0xc],ecx
    ret    0x4
  }
}

// If current map20 exists, cache unsigned slot range c..1c+4, free each CURRENT slot payload, then CURRENT map20.
// No field clearing or local EH. Empty map returns0; otherwise retain last free EAX.
// R6GameService.dll @ 1005f480 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseSegmentedWordBlocks(void *owner)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    mov    eax,DWORD PTR [ebx+0x20]
    test    eax,eax
    je    Branch6
    push    esi
    mov    esi,DWORD PTR [ebx+0xc]
    push    edi
    mov    edi,DWORD PTR [ebx+0x1c]
    add    edi,0x4
    cmp    esi,edi
    jae    Branch5
  Branch4:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    esi,0x4
    cmp    esi,edi
    jb    Branch4
  Branch5:
    mov    ecx,DWORD PTR [ebx+0x20]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
  Branch6:
    pop    ebx
    ret
  }
}

// Allocate max(8,(initialCount>>6)+3) map slots, center count/64+1 blocks, then publish start/finish cursor fields.
// Reload CURRENT map capacity24 after allocation and CURRENT input for finish offset; count controls full32 word arithmetic.
// EBP P=entryS-4: saved ownerP-1c/saved ESPP-10/stateP-4. Catch protects block construction only. RET4/raw current-count low6 bits EAX.
// R6GameService.dll @ 1005f4c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeSegmentedWordBuffer(void *owner,uint count)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSegmentedWordInitEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    mov    edi,DWORD PTR [ebp+0x8]
    shr    edi,0x6
    inc    edi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x1c],esi
    lea    eax,[edi+0x2]
    mov    DWORD PTR [ebp-0x18],0x8
    mov    DWORD PTR [ebp-0x14],eax
    cmp    eax,0x8
    lea    eax,[ebp-0x14]
    ja    Branch7
    lea    eax,[ebp-0x18]
  Branch7:
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x24],eax
    shl    eax,0x2
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi+0x24]
    mov    DWORD PTR [esi+0x20],eax
    sub    ecx,edi
    mov    DWORD PTR [ebp-0x4],0x0
    shr    ecx,1
    lea    ebx,[eax+ecx*4]
    mov    ecx,esi
    lea    edi,[ebx+edi*4]
    push    edi
    push    ebx
    call    R6GameServiceAddresses::AllocateSegmentedWordBlocks
    mov    DWORD PTR [esi+0xc],ebx
    mov    ebx,DWORD PTR [ebx]
    mov    DWORD PTR [esi+0x4],ebx
    add    ebx,0x80
    lea    eax,[edi-0x4]
    mov    DWORD PTR [esi+0x8],ebx
    mov    DWORD PTR [esi+0x1c],eax
    pop    edi
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x14],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x18],eax
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x14]
    and    eax,0x3f
    mov    DWORD PTR [esi],edx
    lea    edx,[ecx+eax*2]
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR [esi+0x10],edx
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Storage-init catch: free CURRENT saved-owner map20, then clear20/24 and rethrow(NULL,NULL); allocated blocks are not released.
// Free runs BEFORE clearing, with inherited parent EBP/contextP-1c and no artificial return after throw.
// R6GameService.dll @ 1005f57e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl segmented_word_supportCatch(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [esi+0x20]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    xor    eax,eax
    push    eax
    push    eax
    mov    DWORD PTR [esi+0x20],eax
    mov    DWORD PTR [esi+0x24],eax
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// For unsigned slot<end, allocate128 bytes into current slot and advance4; preserve NULL allocation results and keep going.
// No local EH/rollback. Empty/reversed range preserves incoming EAX; otherwise return last allocator EAX/RET8.
// R6GameService.dll @ 1005f820 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall AllocateSegmentedWordBlocks(uint *slot,uint *end)
{
  __asm {
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    push    edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    esi,edi
    jae    Branch9
  Branch8:
    push    0x80
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    add    esi,0x4
    cmp    esi,edi
    jb    Branch8
  Branch9:
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Destructor state0 reloads CURRENT saved ownerS-70 and releases CURRENT active blocks/map viaf480; no disarm on normal frees.
// R6GameService.dll @ 10069b60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseSegmentedWordStorageUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x70]
    jmp    R6GameServiceAddresses::ReleaseSegmentedWordBlocks
  }
}

// Constructor state0 calls genuine empty-base cleanup on CURRENT saved ownerS-10 plus20.
// R6GameService.dll @ 10069c20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeSegmentedWordsUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Constructor state1 calls genuine empty-base cleanup on CURRENT saved ownerS-10 plus24, then state0.
// R6GameService.dll @ 10069c2b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeSegmentedWordsUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x24
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact segmented-word lifetime FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069b68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSegmentedWordDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReleaseSegmentedWordStorageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact segmented-word lifetime FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c36 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSegmentedWordCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeSegmentedWordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact segmented-word lifetime FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSegmentedWordInitEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeSegmentedWordBufferExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084584 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReleaseSegmentedWordStorageUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseSegmentedWordStorageUnwind1},
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084584 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReleaseSegmentedWordStorageExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ReleaseSegmentedWordStorageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084660 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeSegmentedWordsUnwindMap[2] = {
  {-1, R6GameServiceAddresses::InitializeSegmentedWordsUnwind1},
  {0x0, R6GameServiceAddresses::InitializeSegmentedWordsUnwind2},
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084660 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeSegmentedWordsExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitializeSegmentedWordsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084724 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeSegmentedWordBufferUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084734 : native storage identity retained.
const R6GameServiceNative::CatchHandler segmented_word_supportGSegmentedWordEH5[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::segmented_word_supportCatch},
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084734 : native storage identity retained.
const R6GameServiceNative::TryBlock InitializeSegmentedWordBufferTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::segmented_word_supportGSegmentedWordEH5},
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084724 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeSegmentedWordBufferExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitializeSegmentedWordBufferUnwindMap,
  0x1,
  R6GameServiceAddresses::InitializeSegmentedWordBufferTryMap,
  0x0,
  0x0,
};

// Capture input WORD, recenter map if fewer than2 remaining slots, allocate128-byte next block and publish CURRENT next node.
// Write captured word through CURRENT last cursor if nonnull, then advance node/reset finish cursor to new block start.
// No local EH or NULL-block guard; return raw new-block-end EAX/RET4, preserving current fields across both callbacks.
// R6GameService.dll @ 1005f5a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendWordAndAllocateNextBlock(void *owner,const ushort *word)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    mov    esi,ecx
    push    edi
    mov    di,WORD PTR [eax]
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    eax,DWORD PTR [esi+0x20]
    mov    edx,DWORD PTR [esi+0x24]
    sub    ecx,eax
    sar    ecx,0x2
    sub    edx,ecx
    cmp    edx,0x2
    jae    Branch10
    push    0x0
    push    0x1
    mov    ecx,esi
    call    R6GameServiceAddresses::RecenterSegmentedWordBlockMap
  Branch10:
    push    0x80
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    je    Branch11
    mov    WORD PTR [eax],di
  Branch11:
    mov    eax,DWORD PTR [esi+0x1c]
    pop    edi
    add    eax,0x4
    mov    DWORD PTR [esi+0x1c],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x14],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x18],eax
    mov    edx,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esi+0x10],edx
    pop    esi
    ret    0x4
  }
}

// Append inline when cursor10!=end18-2, returning original cursor; NULL cursor skips input WORD read but still advances.
// At block boundary tail-forward original receiver/key pointer/stack to5f5a0, retaining its raw return. RET4.
// R6GameService.dll @ 1005ed20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendSegmentedWord(void *owner,const ushort *word)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x18]
    mov    eax,DWORD PTR [ecx+0x10]
    sub    edx,0x2
    cmp    eax,edx
    je    Branch13
    test    eax,eax
    je    Branch12
    mov    edx,DWORD PTR [esp+0x4]
    mov    dx,WORD PTR [edx]
    mov    WORD PTR [eax],dx
  Branch12:
    add    DWORD PTR [ecx+0x10],0x2
    ret    0x4
  Branch13:
    jmp    R6GameServiceAddresses::AppendWordAndAllocateNextBlock
  }
}

// Recenter active slot pointers in the current map when capacity>2*(active+additional); otherwise allocate a larger map.
// Cache active count/required slots; growth reloads flag lowBYTE/additional and current cursor bounds after allocation.
// Memmove retains overlap, free CURRENT old map before publishing new map/capacity; keep logical cursor0/10 unchanged.
// Update node/block bounds and return finish block+128. No local EH, spare-slot clearing or block allocation. RET8.
// R6GameService.dll @ 1005f850 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RecenterSegmentedWordBlockMap(void *owner,uint additionalSlots,uint reserveBeforeWord)
{
  __asm {
    push    ecx
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esp+0x14]
    push    edi
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    ebp,DWORD PTR [esi+0xc]
    mov    ebx,ecx
    sub    ebx,ebp
    sar    ebx,0x2
    inc    ebx
    lea    edi,[ebx+eax*1]
    mov    eax,DWORD PTR [esi+0x24]
    lea    edx,[edi+edi*1]
    cmp    eax,edx
    jbe    Branch15
    mov    dl,BYTE PTR [esp+0x1c]
    sub    eax,edi
    mov    edi,DWORD PTR [esp+0x18]
    shr    eax,1
    neg    dl
    sbb    edx,edx
    and    edx,edi
    add    eax,edx
    mov    edx,DWORD PTR [esi+0x20]
    lea    edi,[edx+eax*4]
    cmp    edi,ebp
    jae    Branch14
    lea    eax,[ecx+0x4]
    cmp    eax,ebp
    je    Branch18
    sub    eax,ebp
    push    eax
    push    ebp
    push    edi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
    jmp    Branch18
  Branch14:
    sub    ecx,ebp
    add    ecx,0x4
    test    ecx,ecx
    jle    Branch18
    lea    eax,[ebx*4+0x0]
    push    ecx
    sub    eax,ecx
    push    ebp
    add    eax,edi
    push    eax
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
    jmp    Branch18
  Branch15:
    mov    edx,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [esi+0x24]
    lea    ecx,[esi+0x24]
    cmp    ebp,edx
    jae    Branch16
    lea    ecx,[esp+0x18]
  Branch16:
    mov    ecx,DWORD PTR [ecx]
    lea    ebp,[eax+ecx*1+0x2]
    lea    edx,[ebp*4+0x0]
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    dl,BYTE PTR [esp+0x1c]
    mov    ecx,ebp
    sub    ecx,edi
    mov    edi,DWORD PTR [esp+0x18]
    shr    ecx,1
    neg    dl
    sbb    edx,edx
    mov    DWORD PTR [esp+0x10],eax
    and    edx,edi
    add    ecx,edx
    lea    edi,[eax+ecx*4]
    mov    eax,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [esi+0xc]
    add    eax,0x4
    cmp    eax,ecx
    je    Branch17
    sub    eax,ecx
    push    eax
    push    ecx
    push    edi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch17:
    mov    eax,DWORD PTR [esi+0x20]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x24],ebp
    mov    DWORD PTR [esi+0x20],ecx
  Branch18:
    mov    DWORD PTR [esi+0xc],edi
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [esi+0x4],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x8],eax
    lea    eax,[edi+ebx*4-0x4]
    mov    DWORD PTR [esi+0x1c],eax
    pop    edi
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x14],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x18],eax
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Copy four DWORDs in literal load/store order, including overlaps; return supplied output pointer, RET4.
// R6GameService.dll @ 10060960 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyWordsToOutput(void *cursor,void *result)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    mov    esi,DWORD PTR [ecx]
    mov    edx,eax
    mov    DWORD PTR [edx],esi
    mov    esi,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [edx+0x4],esi
    mov    esi,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [edx+0x8],esi
    mov    ecx,DWORD PTR [ecx+0xc]
    pop    esi
    mov    DWORD PTR [edx+0xc],ecx
    ret    0x4
  }
}

// Copy second by-value cursor to local scratch, first into second, then local/current second back into first argument.
// Caller storage remains unchanged; retain four actual copy calls, stack argument writes, raw EAX=entry ESP+4, RET32.
// R6GameService.dll @ 10061ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CopyByValueCursorArgumentsToScratch(SegmentedWordCursor first,SegmentedWordCursor second)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x24]
    lea    ecx,[esp+0x0]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x14]
    push    ecx
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x0]
    lea    ecx,[esp+0x14]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x24]
    lea    ecx,[esp+0x14]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    add    esp,0x10
    ret    0x20
  }
}
