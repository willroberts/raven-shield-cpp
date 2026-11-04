#include "native_addresses.h"
#include "native_records.h"

// Inferred guard: an interrupted destruction retries release using the current saved owner and storage fields.
struct SegmentedWordStorageCleanup {
  void *savedOwner;
  bool armed;
  // Keep the retry active through all normal block/map frees, including a failing final map free.
  ~SegmentedWordStorageCleanup() noexcept(false)
  {
    using ReleaseABI = uint (__fastcall *)(void *);
    if (armed) ((ReleaseABI)R6GameServiceAddresses::ReleaseSegmentedWordBlocks)(savedOwner);
  }
};

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
uint __fastcall ForwardSegmentedWordDestroy(void *owner)
{
  using DestroyABI = uint (__fastcall *)(void *);
  return ((DestroyABI)R6GameServiceAddresses::ReleaseSegmentedWordStorage)(owner);
}

// Snapshot finish and perform five literal cursor copies, then gate on current map20 and release active block slots inclusively.
// Cache slot range c..1c+4 before frees; reload each slot payload and CURRENT map20 for final free. Leave all owner fields stale.
// EntryS: saved ownerS-70/stateS-4. State0 stays armed through normal cleanup; unwind repeats current release viaf480.
// R6GameService.dll @ 1005d130 : complete native control/access order and raw ABI retained.
uint __fastcall ReleaseSegmentedWordStorage(void *owner)
{
  SegmentedWordStorageCleanup cleanup = {owner,true};
  uint finish[4];
  finish[0] = *(uint *)((uint)owner + 0x10);
  finish[1] = *(uint *)((uint)owner + 0x14);
  finish[2] = *(uint *)((uint)owner + 0x18);
  finish[3] = *(uint *)((uint)owner + 0x1c);
  uint startCopy[4],finishCopy[4],startAgain[4],finishAgain[4],startLast[4];
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(startCopy,(const uint *)owner);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(finishCopy,finish);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(startAgain,startCopy);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(finishAgain,finishCopy);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(startLast,startAgain);
  uint base = (uint)owner;
  uint result = *(uint *)(base + 0x20);
  if (result != 0) {
    uint slot = *(uint *)(base + 0xc);
    uint end = *(uint *)(base + 0x1c) + 4;
    while (slot < end) {
      TailFreeThroughGlobalAllocator(*(void **)slot);
      slot += 4;
    }
    void *map = *(void **)(base + 0x20);
    result = TailFreeThroughGlobalAllocator(map);
  }
  cleanup.armed = false;
  return result;
}

// Copy four DWORDs forward in native read/store order, preserving partial overlap; return original destination/RET4.
// R6GameService.dll @ 1005ed50 : complete native control/access order and raw ABI retained.
void *__thiscall CopySegmentedCursor(void *destination,const uint *source)
{
  uint *words = (uint *)destination;
  const uint *savedSource = source;
  uint value = savedSource[0];
  words[0] = value;
  value = savedSource[1];
  words[1] = value;
  value = savedSource[2];
  words[2] = value;
  value = savedSource[3];
  words[3] = value;
  return destination;
}

// If current map20 exists, cache unsigned slot range c..1c+4, free each CURRENT slot payload, then CURRENT map20.
// No field clearing or local EH. Empty map returns0; otherwise retain last free EAX.
// R6GameService.dll @ 1005f480 : complete native control/access order and raw ABI retained.
uint __fastcall ReleaseSegmentedWordBlocks(void *owner)
{
  uint base = (uint)owner;
  uint result = *(uint *)(base + 0x20);
  if (result != 0) {
    uint slot = *(uint *)(base + 0xc);
    uint end = *(uint *)(base + 0x1c) + 4;
    while (slot < end) {
      TailFreeThroughGlobalAllocator(*(void **)slot);
      slot += 4;
    }
    void *map = *(void **)(base + 0x20);
    result = TailFreeThroughGlobalAllocator(map);
  }
  return result;
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
// R6GameService.dll data @ 1008458c : native storage identity retained.
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
// R6GameService.dll data @ 10084670 : native storage identity retained.
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
// R6GameService.dll data @ 10084744 : native storage identity retained.
const R6GameServiceNative::TryBlock InitializeSegmentedWordBufferTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::segmented_word_supportGSegmentedWordEH5},
};

// Literal segmented-word lifetime map/handler/try/FuncInfo.
// R6GameService.dll data @ 10084758 : native storage identity retained.
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
uint __thiscall AppendWordAndAllocateNextBlock(void *owner,const ushort *word)
{
  uint base = (uint)owner;
  ushort value = *word;
  uint finishNode = *(uint *)(base + 0x1c);
  uint map = *(uint *)(base + 0x20);
  uint capacity = *(uint *)(base + 0x24);
  uint used = (uint)((int)(finishNode - map) >> 2);
  if (capacity - used < 2) {
    using RecenterABI = uint (__thiscall *)(void *,uint,uint);
    ((RecenterABI)R6GameServiceAddresses::RecenterSegmentedWordBlockMap)(owner,1,0);
  }
  uint block = (uint)AllocateGameServiceBytes(0x80);
  uint node = *(uint *)(base + 0x1c);
  *(uint *)(node + 4) = block;
  uint cursor = *(uint *)(base + 0x10);
  if (cursor != 0) *(ushort *)cursor = value;
  node = *(uint *)(base + 0x1c) + 4;
  *(uint *)(base + 0x1c) = node;
  uint first = *(uint *)node;
  *(uint *)(base + 0x14) = first;
  uint end = first + 0x80;
  *(uint *)(base + 0x18) = end;
  uint current = *(uint *)(base + 0x14);
  *(uint *)(base + 0x10) = current;
  return end;
}

// Append inline when cursor10!=end18-2, returning original cursor; NULL cursor skips input WORD read but still advances.
// At block boundary tail-forward original receiver/key pointer/stack to5f5a0, retaining its raw return. RET4.
// R6GameService.dll @ 1005ed20 : complete native control/access order and raw ABI retained.
uint __thiscall AppendSegmentedWord(void *owner,const ushort *word)
{
  uint base = (uint)owner;
  uint end = *(uint *)(base + 0x18);
  uint cursor = *(uint *)(base + 0x10);
  if (cursor == end - 2) {
    using AppendABI = uint (__thiscall *)(void *,const ushort *);
    return ((AppendABI)R6GameServiceAddresses::AppendWordAndAllocateNextBlock)(owner,word);
  }
  if (cursor != 0) {
    ushort value = *word;
    *(ushort *)cursor = value;
  }
  *(uint *)(base + 0x10) += 2;
  return cursor;
}

// Recenter active slot pointers in the current map when capacity>2*(active+additional); otherwise allocate a larger map.
// Cache active count/required slots; growth reloads flag lowBYTE/additional and current cursor bounds after allocation.
// Memmove retains overlap, free CURRENT old map before publishing new map/capacity; keep logical cursor0/10 unchanged.
// Update node/block bounds and return finish block+128. No local EH, spare-slot clearing or block allocation. RET8.
// R6GameService.dll @ 1005f850 : complete native control/access order and raw ABI retained.
uint __thiscall RecenterSegmentedWordBlockMap(void *owner,uint additionalSlots,uint reserveBeforeWord)
{
  uint base = (uint)owner;
  uint additional = additionalSlots;
  uint finish = *(uint *)(base + 0x1c);
  uint start = *(uint *)(base + 0xc);
  uint active = (uint)((int)(finish - start) >> 2) + 1;
  uint required = active + additional;
  uint capacity = *(uint *)(base + 0x24);
  uint destination;
  using MoveABI = void *(__cdecl *)(void *,const void *,uint);
  if (capacity > required * 2) {
    byte before = *(byte *)&reserveBeforeWord;
    uint centered = (capacity - required) >> 1;
    uint currentAdditional = additionalSlots;
    if (before != 0) centered += currentAdditional;
    uint map = *(uint *)(base + 0x20);
    destination = map + centered * 4;
    if (destination < start) {
      uint end = finish + 4;
      if (end != start) {
        uint bytes = end - start;
        ((MoveABI)R6GameServiceAddresses::memmove)((void *)destination,(const void *)start,bytes);
      }
    } else {
      uint bytes = finish - start + 4;
      if ((int)bytes > 0) {
        uint output = destination + active * 4 - bytes;
        ((MoveABI)R6GameServiceAddresses::memmove)((void *)output,(const void *)start,bytes);
      }
    }
  } else {
    uint requested = additionalSlots;
    uint liveCapacity = *(uint *)(base + 0x24);
    const uint *maximum = liveCapacity >= requested ? (const uint *)(base + 0x24) : &additionalSlots;
    uint increment = *maximum;
    uint newCapacity = capacity + increment + 2;
    uint newMap = (uint)AllocateGameServiceBytes(newCapacity * 4);
    byte before = *(byte *)&reserveBeforeWord;
    uint centered = (newCapacity - required) >> 1;
    uint currentAdditional = additionalSlots;
    if (before != 0) centered += currentAdditional;
    destination = newMap + centered * 4;
    uint currentFinish = *(uint *)(base + 0x1c);
    uint currentStart = *(uint *)(base + 0xc);
    uint end = currentFinish + 4;
    if (end != currentStart) {
      uint bytes = end - currentStart;
      ((MoveABI)R6GameServiceAddresses::memmove)((void *)destination,(const void *)currentStart,bytes);
    }
    void *oldMap = *(void **)(base + 0x20);
    TailFreeThroughGlobalAllocator(oldMap);
    *(uint *)(base + 0x24) = newCapacity;
    *(uint *)(base + 0x20) = newMap;
  }
  *(uint *)(base + 0xc) = destination;
  uint first = *(uint *)destination;
  *(uint *)(base + 4) = first;
  *(uint *)(base + 8) = first + 0x80;
  uint lastNode = destination + active * 4 - 4;
  *(uint *)(base + 0x1c) = lastNode;
  uint last = *(uint *)lastNode;
  *(uint *)(base + 0x14) = last;
  uint end = last + 0x80;
  *(uint *)(base + 0x18) = end;
  return end;
}

// Copy four DWORDs in literal load/store order, including overlaps; return supplied output pointer, RET4.
// R6GameService.dll @ 10060960 : complete native control/access order and raw ABI retained.
void *__thiscall CopyWordsToOutput(void *cursor,void *result)
{
  const uint *source = (const uint *)cursor;
  void *savedResult = result;
  uint *destination = (uint *)savedResult;
  uint value = source[0];
  destination[0] = value;
  value = source[1];
  destination[1] = value;
  value = source[2];
  destination[2] = value;
  value = source[3];
  destination[3] = value;
  return savedResult;
}

// Copy second by-value cursor to local scratch, first into second, then local/current second back into first argument.
// Caller storage remains unchanged; retain four actual copy calls, stack argument writes, raw EAX=entry ESP+4, RET32.
// R6GameService.dll @ 10061ab0 : complete native control/access order and raw ABI retained.
uint __stdcall CopyByValueCursorArgumentsToScratch(SegmentedWordCursor first,SegmentedWordCursor second)
{
  SegmentedWordCursor scratch;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&scratch,(const uint *)&second);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&second,(const uint *)&first);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&first,(const uint *)&scratch);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&first,(const uint *)&second);
  return (uint)&first;
}
