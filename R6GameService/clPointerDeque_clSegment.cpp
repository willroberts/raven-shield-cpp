#include "native_addresses.h"
#include "native_records.h"

// RTTI: vptr78328 -> COL7a7b0 -> type91338 .?AV?$clPointerDeque@PAVclSegment@@@@.
// Known specialization clPointerDeque<clSegment*>; member spellings remain descriptive.

// Forward unchanged receiver/stack/registers and raw return to clPointerDeque<clSegment*> destruction60750.
// R6GameService.dll @ 100602c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardClSegmentPointerDequeDestroy(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClSegmentPointerDeque
  }
}

// Destroy clPointerDeque<clSegment*>, then free cached owner iff CURRENT flags lowBYTE bit0 is set.
// Reload flag after destruction; return original owner, RET4. No added container-free guard.
// R6GameService.dll @ 100602d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteClSegmentPointerDeque(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyClSegmentPointerDeque
    test    BYTE PTR [esp+0x8],0x1
    je    Branch1
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// clPointerDeque<clSegment*> destructor: install vptr78328, delete each current nonnull segment with flag1.
// Cache original finish sentinel, reload CURRENT finish for an extra stop, and advance four-byte cursors across128-byte blocks.
// Erase consumed range through base612c0, then snapshot cursors and free raw blocks/current map without clearing fields.
// Parent entry S: ownerS-74/raw descriptorS-70/stateS-4. State0 protects element/erase phase; state1 protects raw frees.
// R6GameService.dll @ 10060750 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyClSegmentPointerDeque(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectClSegmentPointerDequeEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x6c
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clPointerDeque_PAVclSegmentVTable
    lea    eax,[ecx+0x14]
    lea    edi,[ecx+0x4]
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x2c]
    mov    ebx,DWORD PTR [eax]
    push    ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x88],0x0
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esp+0x28],edx
    mov    eax,DWORD PTR [eax+0xc]
    mov    DWORD PTR [esp+0x2c],eax
    call    R6GameServiceAddresses::CopyWordsToOutput
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esp+0x30]
    mov    eax,DWORD PTR [esp+0x34]
    mov    ebp,DWORD PTR [esp+0x38]
    cmp    esi,ebx
    mov    DWORD PTR [esp+0x40],edx
    mov    DWORD PTR [esp+0x44],eax
    je    Branch5
  Branch2:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    cmp    esi,eax
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x50],edx
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x54],edx
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [esp+0x58],ecx
    je    Branch5
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch3
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch3:
    mov    eax,DWORD PTR [esp+0x44]
    add    esi,0x4
    cmp    esi,eax
    jne    Branch4
    mov    esi,DWORD PTR [ebp+0x4]
    add    ebp,0x4
    lea    eax,[esi+0x80]
    mov    DWORD PTR [esp+0x44],eax
  Branch4:
    cmp    esi,ebx
    jne    Branch2
  Branch5:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [esp+0x24]
    sub    esp,0x10
    mov    eax,esp
    sub    esp,0x10
    mov    DWORD PTR [eax],ebx
    mov    DWORD PTR [eax+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR [eax+0x8],edx
    mov    DWORD PTR [eax+0xc],ecx
    lea    edx,[esp+0x4c]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x7c]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::EraseSegmentedDwordRange
    mov    esi,edi
    mov    DWORD PTR [esp+0x18],esi
    lea    ecx,[esi+0x10]
    push    esi
    mov    DWORD PTR [esp+0x88],0x1
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x30],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x34],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x38],edx
    mov    eax,DWORD PTR [ecx+0xc]
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x3c],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x2c]
    push    ecx
    lea    ecx,[esp+0x40]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x4c]
    lea    ecx,[esp+0x1c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x3c]
    lea    ecx,[esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x1c]
    push    ecx
    lea    ecx,[esp+0x70]
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    eax,DWORD PTR [esi+0x20]
    test    eax,eax
    je    Branch8
    mov    ebx,DWORD PTR [esi+0x1c]
    mov    edi,DWORD PTR [esi+0xc]
    add    ebx,0x4
    cmp    edi,ebx
    jae    Branch7
  Branch6:
    mov    edx,DWORD PTR [edi]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    edi,0x4
    cmp    edi,ebx
    jb    Branch6
  Branch7:
    mov    eax,DWORD PTR [esi+0x20]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch8:
    mov    ecx,DWORD PTR [esp+0x7c]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x78
    ret
  }
}

// State0: NULL-preserving CURRENT saved ownerS-74 plus4 into descriptorS-70, then release raw storage60410.
// R6GameService.dll @ 10069e00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyClSegmentPointerDequeUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x74],0x0
    je    Branch9
    mov    eax,DWORD PTR [ebp-0x74]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x70],eax
    jmp    Branch10
  Branch9:
    mov    DWORD PTR [ebp-0x70],0x0
  Branch10:
    mov    ecx,DWORD PTR [ebp-0x70]
    jmp    R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocks
  }
}

// State1: release current raw blocks/map through CURRENT saved descriptorS-70 and shared5f480; no payload retry.
// R6GameService.dll @ 10069e27 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DestroyClSegmentPointerDequeUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x70]
    jmp    R6GameServiceAddresses::ReleaseSegmentedWordBlocks
  }
}

// Select exact two-state clPointerDeque<clSegment*> destruction map84900/FuncInfo84910 and tail CRT dispatch.
// R6GameService.dll @ 10069e2f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectClSegmentPointerDequeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyClSegmentPointerDequeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native destructor cleanup map or FuncInfo.
// R6GameService.dll data @ 10084900 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyClSegmentPointerDequeUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyClSegmentPointerDequeUnwind1},
  {-1, R6GameServiceAddresses::DestroyClSegmentPointerDequeUnwind2},
};

// Literal native destructor cleanup map or FuncInfo.
// R6GameService.dll data @ 10084900 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyClSegmentPointerDequeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyClSegmentPointerDequeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// clPointerDeque<clSegment*> owning erase: delete current nonnull segments with flag1, stopping at cached/live finish.
// Shift shorter surviving side, release discarded blocks, publish adjusted boundary and return begin+original prefix.
// Whole-range clear retains first block/map, resets finish to current begin and returns that cursor. No local EH; RET36.
// R6GameService.dll @ 10060ab0 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__thiscall EraseSegmentedObjectRange(
    void *owner,SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last)
{
  uint base = (uint)owner;
  uint *firstWords = (uint *)&first;
  uint *lastWords = (uint *)&last;
  uint initialBlock = firstWords[1];
  uint blockEnd = firstWords[2];
  uint terminal = lastWords[0];
  uint current = firstWords[0];
  uint node = firstWords[3];
  while (current != terminal) {
    uint finishCurrent = *(uint *)(base + 0x14);
    uint finishBlock = *(uint *)(base + 0x18);
    uint finishEnd = *(uint *)(base + 0x1c);
    uint finishNode = *(uint *)(base + 0x20);
    if (current == finishCurrent) break;
    void *object = *(void **)current;
    if (object != 0) {
      using DeleteABI = void *(__thiscall *)(void *,uint);
      uint table = *(uint *)object;
      (*(DeleteABI *)table)(object,1);
    }
    current += 4;
    if (current == blockEnd) {
      current = *(uint *)(node + 4);
      node += 4;
      blockEnd = current + 0x80;
    }
  }
  SegmentedWordCursor lastSnapshot,firstSnapshot;
  uint *lastView = (uint *)&lastSnapshot;
  uint lastBlock = lastWords[1];
  uint lastEnd = lastWords[2];
  uint lastNode = lastWords[3];
  lastView[1] = lastBlock;
  lastView[0] = terminal;
  lastView[2] = lastEnd;
  lastView[3] = lastNode;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&firstSnapshot,firstWords);
  uint *firstView = (uint *)&firstSnapshot;
  uint descriptor = base + 4;
  if (firstView[0] == *(uint *)descriptor && terminal == *(uint *)(descriptor + 0x10)) {
    uint slot = *(uint *)(descriptor + 0xc) + 4;
    uint finishNode = *(uint *)(descriptor + 0x1c);
    using FreeABI = uint (__stdcall *)(void *,uint);
    if (slot < finishNode) {
      do {
        void *block = *(void **)slot;
        ((FreeABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(block,0x20);
        finishNode = *(uint *)(descriptor + 0x1c);
        slot += 4;
      } while (slot < finishNode);
    }
    uint beginNode = *(uint *)(descriptor + 0xc);
    finishNode = *(uint *)(descriptor + 0x1c);
    if (beginNode != finishNode) {
      void *block = *(void **)(descriptor + 0x14);
      ((FreeABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(block,0x20);
    }
    uint value = *(uint *)descriptor;
    *(uint *)(descriptor + 0x10) = value;
    value = *(uint *)(descriptor + 4);
    *(uint *)(descriptor + 0x14) = value;
    value = *(uint *)(descriptor + 8);
    *(uint *)(descriptor + 0x18) = value;
    uint returnCurrent = *(uint *)descriptor;
    value = *(uint *)(descriptor + 0xc);
    *(uint *)(descriptor + 0x1c) = value;
    SegmentedWordCursor *savedResult = result;
    uint *out = (uint *)savedResult;
    out[0] = returnCurrent;
    value = *(uint *)(descriptor + 4);
    out[1] = value;
    value = *(uint *)(descriptor + 8);
    out[2] = value;
    value = *(uint *)(descriptor + 0xc);
    out[3] = value;
    return savedResult;
  }
  using DistanceABI = int (__thiscall *)(const uint *,const uint *);
  uint erased = (uint)((DistanceABI)R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance)(lastView,firstView);
  uint prefix = (uint)((DistanceABI)R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance)(
      firstView,(const uint *)descriptor);
  uint finishDescriptor = descriptor + 0x10;
  lastWords[0] = prefix;
  uint total = (uint)((DistanceABI)R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance)(
      (const uint *)finishDescriptor,(const uint *)descriptor);
  int half = (int)(total - erased) / 2;
  using AdvanceABI = uint (__thiscall *)(uint *,int);
  using ScratchABI = uint (__stdcall *)(SegmentedWordCursor,SegmentedWordCursor);
  using ReleaseABI = void (__stdcall *)(uint *,uint *);
  if ((int)prefix < half) {
    SegmentedWordCursor rangeEnd,prefixLast,prefixBegin;
    uint *endView = (uint *)&rangeEnd;
    endView[0] = lastView[0];
    endView[1] = lastView[1];
    endView[3] = lastView[3];
    endView[2] = lastView[2];
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&prefixLast,firstView);
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&prefixBegin,(const uint *)descriptor);
    byte tag = *(byte *)&result;
    *(byte *)&first = tag;
    SegmentedWordCursor moveDestination,moveLast,moveFirst,ignored;
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&moveDestination,(const uint *)&rangeEnd);
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&moveLast,(const uint *)&prefixLast);
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&moveFirst,(const uint *)&prefixBegin);
    using BackwardABI = SegmentedWordCursor *(__stdcall *)(
        SegmentedWordCursor *,SegmentedWordCursor,SegmentedWordCursor,SegmentedWordCursor,uint);
    ((BackwardABI)R6GameServiceAddresses::MoveSegmentedDwordRangeBackward)(
        &ignored,moveFirst,moveLast,moveDestination,(uint)&first);
    firstWords[0] = *(uint *)descriptor;
    firstWords[1] = *(uint *)(descriptor + 4);
    firstWords[2] = *(uint *)(descriptor + 8);
    firstWords[3] = *(uint *)(descriptor + 0xc);
    ((AdvanceABI)R6GameServiceAddresses::AdvanceSegmentedDwordCursor)(firstWords,(int)erased);
    uint newCurrent = firstWords[0];
    uint newBlock = firstWords[1];
    uint newEnd = firstWords[2];
    uint newNode = firstWords[3];
    SegmentedWordCursor scratchLast,scratchFirst;
    uint *scratchView = (uint *)&scratchLast;
    scratchView[0] = newCurrent;
    scratchView[1] = newBlock;
    scratchView[2] = newEnd;
    scratchView[3] = newNode;
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&scratchFirst,(const uint *)descriptor);
    ((ScratchABI)R6GameServiceAddresses::CopyByValueCursorArgumentsToScratch)(scratchFirst,scratchLast);
    uint oldNode = *(uint *)(descriptor + 0xc);
    ((ReleaseABI)R6GameServiceAddresses::ReleaseSegmentedPointerSlots)((uint *)oldNode,(uint *)newNode);
    newEnd = firstWords[2];
    *(uint *)descriptor = newCurrent;
    *(uint *)(descriptor + 4) = newBlock;
    prefix = lastWords[0];
    *(uint *)(descriptor + 8) = newEnd;
    *(uint *)(descriptor + 0xc) = newNode;
  } else {
    SegmentedWordCursor moveDestination,moveLast,moveFirst;
    uint *moveView = (uint *)&moveDestination;
    moveView[0] = firstView[0];
    moveView[1] = firstView[1];
    moveView[2] = firstView[2];
    moveView[3] = firstView[3];
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&moveLast,(const uint *)finishDescriptor);
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&moveFirst,lastView);
    using ForwardABI = SegmentedWordCursor *(__stdcall *)(
        SegmentedWordCursor *,SegmentedWordCursor,SegmentedWordCursor,SegmentedWordCursor);
    ((ForwardABI)R6GameServiceAddresses::CopySegmentedDwordRange)(&last,moveFirst,moveLast,moveDestination);
    using SubtractABI = SegmentedWordCursor *(__thiscall *)(const uint *,SegmentedWordCursor *,int);
    ((SubtractABI)R6GameServiceAddresses::SubtractSegmentedDwordCursorOffset)(
        (const uint *)finishDescriptor,&first,(int)erased);
    SegmentedWordCursor scratchLast,scratchFirst;
    uint *scratchView = (uint *)&scratchLast;
    scratchView[0] = *(uint *)finishDescriptor;
    scratchView[1] = *(uint *)(finishDescriptor + 4);
    scratchView[2] = *(uint *)(finishDescriptor + 8);
    scratchView[3] = *(uint *)(finishDescriptor + 0xc);
    ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&scratchFirst,firstWords);
    ((ScratchABI)R6GameServiceAddresses::CopyByValueCursorArgumentsToScratch)(scratchFirst,scratchLast);
    uint stopNode = *(uint *)(descriptor + 0x1c);
    uint firstNode = firstWords[3];
    stopNode += 4;
    firstNode += 4;
    ((ReleaseABI)R6GameServiceAddresses::ReleaseSegmentedPointerSlots)((uint *)firstNode,(uint *)stopNode);
    uint newCurrent = firstWords[0];
    uint newBlock = firstWords[1];
    uint newEnd = firstWords[2];
    *(uint *)finishDescriptor = newCurrent;
    uint newNode = firstWords[3];
    *(uint *)(finishDescriptor + 4) = newBlock;
    *(uint *)(finishDescriptor + 8) = newEnd;
    *(uint *)(finishDescriptor + 0xc) = newNode;
  }
  SegmentedWordCursor *savedResult = result;
  using AddABI = SegmentedWordCursor *(__thiscall *)(const uint *,SegmentedWordCursor *,int);
  ((AddABI)R6GameServiceAddresses::AddSegmentedDwordCursorOffset)(
      (const uint *)descriptor,savedResult,(int)prefix);
  return savedResult;
}

// Native virtual-table prefix: clPointerDeque_PAVclSegmentVTable
// R6GameService.dll data @ 10078328 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerDeque_PAVclSegmentVTableRecord {
  R6GameServiceNative::Address DeleteClSegmentPointerDeque; // +0x00
};
const clPointerDeque_PAVclSegmentVTableRecord clPointerDeque_PAVclSegmentVTable = {
  R6GameServiceAddresses::DeleteClSegmentPointerDeque,
};
