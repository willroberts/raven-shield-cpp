#include "native_addresses.h"
#include "native_records.h"

// Inferred guard: an interrupted destruction retries release using the current saved owner and storage fields.
struct SegmentedDwordBufferCleanup {
  void *savedOwner;
  bool armed;
  // Keep the retry active through all normal block/map frees, including a failing final map free.
  ~SegmentedDwordBufferCleanup() noexcept(false)
  {
    using ReleaseABI = uint (__fastcall *)(void *);
    if (armed) ((ReleaseABI)R6GameServiceAddresses::ReleaseSegmentedWordBlocks)(savedOwner);
  }
};

// Snapshot finish/copy cursors, then release inclusive active blocks and CURRENT map20 without clearing fields.
// Cache slot bounds but reload slot payloads/map; state0 stays armed through normal frees. OwnerS-70/stateS-4.
// Empty map returns0; otherwise preserve final allocator EAX. Cleanup69de0 shares raw block release5f480.
// R6GameService.dll @ 10060410 : complete native control/access order and raw ABI retained.
uint __fastcall ReleaseSegmentedDwordBufferBlocks(void *owner)
{
  SegmentedDwordBufferCleanup cleanup = {owner,true};
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

// State0: reload CURRENT saved raw pointer descriptorS-70 and release current blocks/map through5f480.
// R6GameService.dll @ 10069de0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ReleaseSegmentedDwordBufferBlocksUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x70]
    jmp    R6GameServiceAddresses::ReleaseSegmentedWordBlocks
  }
}

// Select exact one-state raw block release map848dc/FuncInfo848e4 and tail-forward to CRT dispatch.
// R6GameService.dll @ 10069de8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSegmentedPointerReleaseEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocksExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native cleanup map or FuncInfo; preserve staged cleanup transitions.
// R6GameService.dll data @ 100848dc : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReleaseSegmentedDwordBufferBlocksUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocksUnwind1},
};

// Literal native cleanup map or FuncInfo; preserve staged cleanup transitions.
// R6GameService.dll data @ 100848e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReleaseSegmentedDwordBufferBlocksExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ReleaseSegmentedDwordBufferBlocksUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Erase raw DWORD range without element deletion; signed prefix < trunc((size-erased)/2) selects backward prefix move.
// Otherwise move suffix forward. Free abandoned blocks BEFORE publishing current adjusted cursor; keep map allocation.
// Whole-range clear releases all but first block and resets finish to current begin. Hidden cursor output/RET36, no local EH.
// R6GameService.dll @ 100612c0 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __thiscall EraseSegmentedDwordRange(
    void *owner,SegmentedWordCursor *result,SegmentedWordCursor first,
    SegmentedWordCursor last)
{
  __asm {
    sub    esp,0x34
    push    ebx
    push    ebp
    mov    ebp,DWORD PTR [esp+0x44]
    push    esi
    mov    esi,ecx
    push    edi
    cmp    ebp,DWORD PTR [esi]
    jne    Branch7
    mov    eax,DWORD PTR [esp+0x5c]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jne    Branch7
    mov    edi,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x1c]
    add    edi,0x4
    cmp    edi,eax
    jae    Branch5
    lea    ebx,[esi+0x24]
  Branch4:
    mov    ecx,DWORD PTR [edi]
    push    0x20
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    eax,DWORD PTR [esi+0x1c]
    add    edi,0x4
    cmp    edi,eax
    jb    Branch4
  Branch5:
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x1c]
    cmp    edx,eax
    je    Branch6
    mov    eax,DWORD PTR [esi+0x14]
    push    0x20
    push    eax
    lea    ecx,[esi+0x24]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
  Branch6:
    mov    ecx,esi
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esi+0x10],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esi+0x14],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esi+0x18],edx
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [esi+0x1c],eax
    mov    eax,DWORD PTR [esp+0x48]
    mov    ecx,eax
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ecx+0x8],edx
    mov    edx,DWORD PTR [esi+0xc]
    mov    DWORD PTR [ecx+0xc],edx
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x34
    ret    0x24
  Branch7:
    lea    eax,[esp+0x4c]
    lea    ecx,[esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    push    esi
    lea    ecx,[esp+0x50]
    mov    ebx,eax
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    lea    edi,[esi+0x10]
    push    esi
    mov    ecx,edi
    mov    DWORD PTR [esp+0x14],eax
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    mov    ecx,DWORD PTR [esp+0x10]
    sub    eax,ebx
    cdq
    sub    eax,edx
    sar    eax,1
    cmp    ecx,eax
    jge    Branch10
    mov    ecx,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [esp+0x60]
    mov    eax,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esp+0x68]
    mov    DWORD PTR [esp+0x18],edx
    lea    edx,[esp+0x4c]
    mov    DWORD PTR [esp+0x20],ecx
    push    edx
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esp+0x20],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    push    esi
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    al,BYTE PTR [esp+0x48]
    lea    ecx,[esp+0x4c]
    push    ecx
    lea    edx,[esp+0x18]
    sub    esp,0x10
    mov    BYTE PTR [esp+0x60],al
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    eax,[esp+0x80]
    mov    ecx,esp
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    edx,[esp+0x58]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x68]
    push    eax
    call    R6GameServiceAddresses::MoveSegmentedDwordRangeBackward
    mov    ecx,esi
    push    ebx
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x50],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x54],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x58],edx
    mov    eax,DWORD PTR [ecx+0xc]
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x5c],eax
    call    R6GameServiceAddresses::AdvanceSegmentedDwordCursor
    mov    ecx,DWORD PTR [esp+0x50]
    mov    ebp,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x54]
    mov    ebx,DWORD PTR [esp+0x58]
    mov    DWORD PTR [esp+0x60],ecx
    push    esi
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x60],ebp
    mov    DWORD PTR [esp+0x68],edx
    mov    DWORD PTR [esp+0x6c],ebx
    call    R6GameServiceAddresses::CopySegmentedCursor
    push    0x0
    lea    eax,[esp+0x60]
    sub    esp,0x10
    mov    ecx,esp
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    edx,[esp+0x48]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    call    R6GameServiceAddresses::segmented_pointer_support_CopyByValueCursorArgumentsToScratch
    mov    edi,DWORD PTR [esi+0xc]
    cmp    edi,ebx
    jae    Branch9
  Branch8:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    edi,0x4
    cmp    edi,ebx
    jb    Branch8
  Branch9:
    mov    edx,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [esp+0x54]
    mov    ecx,esi
    mov    DWORD PTR [ecx],ebp
    mov    DWORD PTR [ecx+0x4],edx
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ecx+0xc],ebx
    jmp    Branch13
  Branch10:
    mov    ecx,DWORD PTR [esp+0x50]
    mov    edx,DWORD PTR [esp+0x54]
    mov    eax,DWORD PTR [esp+0x58]
    mov    DWORD PTR [esp+0x18],ecx
    push    edi
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x20],edx
    mov    DWORD PTR [esp+0x24],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x5c]
    push    ecx
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    dl,BYTE PTR [esp+0x48]
    lea    eax,[esp+0x4c]
    push    eax
    mov    BYTE PTR [esp+0x50],dl
    sub    esp,0x10
    lea    edx,[esp+0x28]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    eax,[esp+0x48]
    mov    ecx,esp
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    edx,[esp+0x68]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x90]
    push    eax
    call    R6GameServiceAddresses::MoveSegmentedDwordRangeForward
    mov    ecx,edi
    neg    ebx
    mov    edx,DWORD PTR [ecx]
    push    ebx
    mov    DWORD PTR [esp+0x50],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x54],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x58],edx
    mov    eax,DWORD PTR [ecx+0xc]
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x5c],eax
    call    R6GameServiceAddresses::AdvanceSegmentedDwordCursor
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [esp+0x54]
    mov    DWORD PTR [esp+0x5c],ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x60],edx
    mov    DWORD PTR [esp+0x64],eax
    mov    ebp,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x68],ebp
    mov    DWORD PTR [esp+0x14],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x18],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x1c],edx
    mov    eax,DWORD PTR [ecx+0xc]
    lea    ecx,[esp+0x5c]
    push    ecx
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x24],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x5c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x24]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x5c]
    push    ecx
    lea    ecx,[esp+0x38]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x24]
    lea    ecx,[esp+0x5c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    ebx,DWORD PTR [esi+0x1c]
    add    ebp,0x4
    add    ebx,0x4
    cmp    ebp,ebx
    jae    Branch12
  Branch11:
    mov    eax,DWORD PTR [ebp+0x0]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    ebp,0x4
    cmp    ebp,ebx
    jb    Branch11
  Branch12:
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [esp+0x54]
    mov    DWORD PTR [edi],ecx
    mov    ecx,DWORD PTR [esp+0x58]
    mov    DWORD PTR [edi+0x4],edx
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [edi+0xc],ecx
  Branch13:
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x50],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x4c],edx
    mov    edx,DWORD PTR [esi+0xc]
    mov    DWORD PTR [esp+0x54],ecx
    push    eax
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x5c],edx
    call    R6GameServiceAddresses::AdvanceSegmentedDwordCursor
    mov    eax,DWORD PTR [esp+0x48]
    mov    edx,DWORD PTR [esp+0x4c]
    mov    ecx,eax
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esp+0x44]
    pop    ebx
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [esp+0x44]
    mov    DWORD PTR [ecx+0x8],edx
    mov    edx,DWORD PTR [esp+0x48]
    mov    DWORD PTR [ecx+0xc],edx
    add    esp,0x34
    ret    0x24
  }
}

// Return signed32 distance:32*(node difference/4)+(current-first)/4+(other.end-other.current)/4-32; SAR/modulo32. RET4.
// R6GameService.dll @ 10060ea0 : complete native control/access order and raw ABI retained.
int __thiscall MeasureSegmentedDwordCursorDistance(const uint *cursor,const uint *other)
{
  uint node = cursor[3];
  uint otherNode = other[3];
  uint first = cursor[1];
  uint nodeDistance = node - otherNode;
  uint current = cursor[0];
  uint otherEnd = other[2];
  uint currentDistance = current - first;
  uint blocks = (uint)((int)nodeDistance >> 2) << 5;
  uint partial = (uint)((int)currentDistance >> 2);
  uint distance = blocks + partial;
  uint otherCurrent = other[0];
  uint tailDistance = otherEnd - otherCurrent;
  uint tail = (uint)((int)tailDistance >> 2);
  return (int)(distance + tail - 32);
}

// Add signed element offset, selecting adjacent32-DWORD blocks by signed floor division when outside current block.
// Cache all input fields before output stores, including overlap; return result pointer, RET8.
// R6GameService.dll @ 10061c10 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__thiscall AddSegmentedDwordCursorOffset(
    const uint *cursor,SegmentedWordCursor *result,int offset)
{
  uint current = cursor[0];
  uint first = cursor[1];
  uint delta = (uint)offset;
  uint node = cursor[3];
  uint end = cursor[2];
  uint relative = (uint)((int)(current - first) >> 2) + delta;
  int position = (int)relative;
  uint next;
  if (position >= 0 && position < 32) {
    next = current + delta * 4;
  } else {
    int blockOffset = position > 0 ? position / 32 : (position + 1) / 32 - 1;
    uint selectedNode = node + (uint)blockOffset * 4;
    first = *(uint *)selectedNode;
    node = selectedNode;
    uint within = relative - (uint)blockOffset * 32;
    end = first + 0x80;
    next = first + within * 4;
  }
  SegmentedWordCursor *savedResult = result;
  uint *out = (uint *)savedResult;
  out[0] = next;
  out[1] = first;
  out[2] = end;
  out[3] = node;
  return savedResult;
}

// Subtract signed offset modulo32, then select32-DWORD block by signed floor division; cache inputs before output.
// Return result pointer, RET8; no map bounds validation.
// R6GameService.dll @ 10061c80 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__thiscall SubtractSegmentedDwordCursorOffset(
    const uint *cursor,SegmentedWordCursor *result,int offset)
{
  uint first = cursor[1];
  uint delta = 0 - (uint)offset;
  uint end = cursor[2];
  uint node = cursor[3];
  uint current = cursor[0];
  uint relative = (uint)((int)(current - first) >> 2) + delta;
  int position = (int)relative;
  uint next;
  if (position >= 0 && position < 32) {
    next = current + delta * 4;
  } else {
    int blockOffset = position > 0 ? position / 32 : (position + 1) / 32 - 1;
    uint selectedNode = node + (uint)blockOffset * 4;
    first = *(uint *)selectedNode;
    node = selectedNode;
    uint within = relative - (uint)blockOffset * 32;
    end = first + 0x80;
    next = first + within * 4;
  }
  SegmentedWordCursor *savedResult = result;
  uint *out = (uint *)savedResult;
  out[0] = next;
  out[1] = first;
  out[2] = end;
  out[3] = node;
  return savedResult;
}

// Advance current cursor by signed elements; crossing a block publishes node, reloads its block and rebuilds bounds.
// Within block EAX is new current pointer; across blocks EAX is loaded block base, while current is stored through EDX. RET4.
// R6GameService.dll @ 10061d70 : complete native control/access order and raw ABI retained.
uint __thiscall AdvanceSegmentedDwordCursor(uint *cursor,int offset)
{
  uint current = cursor[0];
  uint first = cursor[1];
  uint distance = current - first;
  uint delta = (uint)offset;
  uint relative = (uint)((int)distance >> 2) + delta;
  int position = (int)relative;
  if (position >= 0 && position < 32) {
    uint next = current + delta * 4;
    cursor[0] = next;
    return next;
  }
  int blockOffset = position > 0 ? position / 32 : (position + 1) / 32 - 1;
  uint node = cursor[3];
  uint selectedNode = node + (uint)blockOffset * 4;
  cursor[3] = selectedNode;
  uint block = *(uint *)selectedNode;
  cursor[1] = block;
  uint within = relative - (uint)blockOffset * 32;
  uint reloaded = cursor[1];
  cursor[2] = block + 0x80;
  uint next = reloaded + within * 4;
  cursor[0] = next;
  return reloaded;
}

// Unsigned slot-address traversal frees each CURRENT payload in cached [first,last); no map/field clearing.
// The two direct retail callers overwrite EAX before use; two physical pointer words are consumed with RET8.
// R6GameService.dll @ 10061e80 : inferred void interface; all retail callers discard allocator return residue.
void __stdcall ReleaseSegmentedPointerSlots(uint *first,uint *last)
{
  uint current = (uint)first;
  uint end = (uint)last;
  while (current < end) {
    void *payload = *(void **)current;
    TailFreeThroughGlobalAllocator(payload);
    current += 4;
  }
}

// Rotate by-value cursor copies, then copy positive signed distance DWORDs forward with literal source-before-store order.
// Reload next map entries at32-DWORD boundaries; return advanced destination cursor/RET52. No ownership transfer or EH.
// R6GameService.dll @ 10061eb0 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__stdcall CopySegmentedDwordRange(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destination)
{
  SegmentedWordCursor savedDestination,savedLast,savedFirst;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedDestination,(const uint *)&destination);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedLast,(const uint *)&last);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedFirst,(const uint *)&first);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&destination,(const uint *)&savedDestination);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&first,(const uint *)&savedLast);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&last,(const uint *)&savedFirst);
  uint *sourceWords = (uint *)&last;
  const uint *boundaryWords = (const uint *)&first;
  uint *destinationWords = (uint *)&destination;
  uint sourceCurrent = sourceWords[0];
  uint lastNode = boundaryWords[3];
  uint firstNode = sourceWords[3];
  uint sourceEnd = sourceWords[2];
  uint boundaryCurrent = boundaryWords[0];
  uint nodeDistance = lastNode - firstNode;
  uint tailDistance = sourceEnd - sourceCurrent;
  uint blocks = (uint)((int)nodeDistance >> 2) << 5;
  uint tail = (uint)((int)tailDistance >> 2);
  uint distance = blocks + tail;
  uint boundaryFirst = boundaryWords[1];
  uint headDistance = boundaryCurrent - boundaryFirst;
  int remaining = (int)(distance + (uint)((int)headDistance >> 2) - 32);
  uint destinationCurrent = destinationWords[0];
  uint destinationFirst;
  if (remaining > 0) {
    do {
      uint value = *(uint *)sourceCurrent;
      *(uint *)destinationCurrent = value;
      sourceCurrent = sourceWords[0];
      uint end = sourceWords[2];
      sourceCurrent += 4;
      sourceWords[0] = sourceCurrent;
      if (sourceCurrent == end) {
        uint node = sourceWords[3] + 4;
        sourceWords[3] = node;
        uint block = *(uint *)node;
        sourceWords[1] = block;
        sourceCurrent = block;
        sourceWords[0] = sourceCurrent;
        sourceWords[2] = block + 0x80;
      }
      destinationCurrent = destinationWords[0];
      end = destinationWords[2];
      destinationCurrent += 4;
      destinationWords[0] = destinationCurrent;
      if (destinationCurrent == end) {
        uint node = destinationWords[3] + 4;
        destinationWords[3] = node;
        uint block = *(uint *)node;
        destinationWords[1] = block;
        destinationWords[2] = block + 0x80;
        destinationCurrent = block;
        destinationWords[0] = destinationCurrent;
        destinationFirst = block;
      } else {
        destinationFirst = destinationWords[1];
      }
      --remaining;
    } while (remaining != 0);
  } else {
    destinationFirst = destinationWords[1];
  }
  SegmentedWordCursor *savedResult = result;
  uint *out = (uint *)savedResult;
  out[0] = destinationCurrent;
  uint destinationNode = destinationWords[3];
  out[1] = destinationFirst;
  uint destinationEnd = destinationWords[2];
  out[2] = destinationEnd;
  out[3] = destinationNode;
  return savedResult;
}

// Copy second by-value cursor into local scratch and first into consumed second argument; first stays unchanged.
// Trailing full word is unread; raw EAX=entry ESP+0x14, RET36. Caller objects remain unchanged.
// R6GameService.dll @ 10062020 : complete native control/access order and raw ABI retained.
uint __stdcall segmented_pointer_support_CopyByValueCursorArgumentsToScratch(
    SegmentedWordCursor first,SegmentedWordCursor second,uint unusedWord)
{
  SegmentedWordCursor scratch;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&scratch,(const uint *)&second);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&second,(const uint *)&first);
  return (uint)&second;
}

// Copy positive signed [first,last) distance backward, predecrementing source/destination across32-DWORD blocks.
// Keep ordered loads/stores for overlap; publish advanced destination output cursor, raw output pointer/RET56. Extra word unread.
// R6GameService.dll @ 10062050 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__stdcall MoveSegmentedDwordRangeBackward(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destinationEnd,uint unusedWord)
{
  SegmentedWordCursor savedDestination;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedDestination,(const uint *)&destinationEnd);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&destinationEnd,(const uint *)&last);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&last,(const uint *)&first);
  uint *sourceWords = (uint *)&destinationEnd;
  const uint *firstWords = (const uint *)&last;
  uint *destinationWords = (uint *)&savedDestination;
  uint lastNode = sourceWords[3];
  uint firstNode = firstWords[3];
  uint firstEnd = firstWords[2];
  uint nodeDistance = lastNode - firstNode;
  uint firstCurrent = firstWords[0];
  uint sourceFirst = sourceWords[1];
  uint blocks = (uint)((int)nodeDistance >> 2) << 5;
  uint tailDistance = firstEnd - firstCurrent;
  uint distance = blocks + (uint)((int)tailDistance >> 2);
  uint sourceCurrent = sourceWords[0];
  uint headDistance = sourceCurrent - sourceFirst;
  int remaining = (int)(distance + (uint)((int)headDistance >> 2) - 32);
  if (remaining > 0) {
    do {
      if (sourceCurrent == sourceWords[1]) {
        uint node = sourceWords[3] - 4;
        sourceWords[3] = node;
        uint block = *(uint *)node;
        sourceWords[1] = block;
        sourceCurrent = block + 0x80;
        sourceWords[2] = sourceCurrent;
      }
      uint destinationCurrent = destinationWords[0];
      uint destinationFirst = destinationWords[1];
      sourceCurrent -= 4;
      sourceWords[0] = sourceCurrent;
      if (destinationCurrent == destinationFirst) {
        uint node = destinationWords[3] - 4;
        destinationWords[3] = node;
        uint block = *(uint *)node;
        destinationWords[1] = block;
        destinationCurrent = block + 0x80;
        destinationWords[2] = destinationCurrent;
      }
      destinationCurrent -= 4;
      --remaining;
      destinationWords[0] = destinationCurrent;
      uint value = *(uint *)sourceCurrent;
      *(uint *)destinationCurrent = value;
      if (remaining != 0) sourceCurrent = sourceWords[0];
    } while (remaining != 0);
  }
  SegmentedWordCursor *savedResult = result;
  uint *out = (uint *)savedResult;
  uint value = destinationWords[0];
  out[0] = value;
  value = destinationWords[1];
  out[1] = value;
  value = destinationWords[2];
  out[2] = value;
  value = destinationWords[3];
  out[3] = value;
  return savedResult;
}

// Copy positive signed [first,last) distance forward, advancing source/destination across32-DWORD blocks.
// Preserve by-value rotation and literal overlap order, output advanced cursor, raw output pointer/RET56. Extra word unread.
// R6GameService.dll @ 10062140 : complete native control/access order and raw ABI retained.
SegmentedWordCursor *__stdcall MoveSegmentedDwordRangeForward(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destination,uint unusedWord)
{
  SegmentedWordCursor savedDestination,savedLast;
  using CopyABI = void *(__thiscall *)(void *,const uint *);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedDestination,(const uint *)&destination);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&savedLast,(const uint *)&last);
  ((CopyABI)R6GameServiceAddresses::CopySegmentedCursor)(&destination,(const uint *)&first);
  uint *sourceWords = (uint *)&destination;
  const uint *boundaryWords = (const uint *)&savedLast;
  uint *destinationWords = (uint *)&savedDestination;
  uint sourceCurrent = sourceWords[0];
  uint lastNode = boundaryWords[3];
  uint firstNode = sourceWords[3];
  uint sourceEnd = sourceWords[2];
  uint boundaryCurrent = boundaryWords[0];
  uint nodeDistance = lastNode - firstNode;
  uint tailDistance = sourceEnd - sourceCurrent;
  uint blocks = (uint)((int)nodeDistance >> 2) << 5;
  uint tail = (uint)((int)tailDistance >> 2);
  uint distance = blocks + tail;
  uint boundaryFirst = boundaryWords[1];
  uint headDistance = boundaryCurrent - boundaryFirst;
  int remaining = (int)(distance + (uint)((int)headDistance >> 2) - 32);
  uint destinationCurrent = destinationWords[0];
  uint destinationFirst;
  if (remaining > 0) {
    do {
      uint value = *(uint *)sourceCurrent;
      *(uint *)destinationCurrent = value;
      sourceCurrent = sourceWords[0];
      uint end = sourceWords[2];
      sourceCurrent += 4;
      sourceWords[0] = sourceCurrent;
      if (sourceCurrent == end) {
        uint node = sourceWords[3] + 4;
        sourceWords[3] = node;
        uint block = *(uint *)node;
        sourceWords[1] = block;
        sourceCurrent = block;
        sourceWords[0] = sourceCurrent;
        sourceWords[2] = block + 0x80;
      }
      destinationCurrent = destinationWords[0];
      end = destinationWords[2];
      destinationCurrent += 4;
      destinationWords[0] = destinationCurrent;
      if (destinationCurrent == end) {
        uint node = destinationWords[3] + 4;
        destinationWords[3] = node;
        uint block = *(uint *)node;
        destinationWords[1] = block;
        destinationWords[2] = block + 0x80;
        destinationCurrent = block;
        destinationWords[0] = destinationCurrent;
        destinationFirst = block;
      } else {
        destinationFirst = destinationWords[1];
      }
      --remaining;
    } while (remaining != 0);
  } else {
    destinationFirst = destinationWords[1];
  }
  SegmentedWordCursor *savedResult = result;
  uint *out = (uint *)savedResult;
  out[0] = destinationCurrent;
  uint destinationNode = destinationWords[3];
  out[1] = destinationFirst;
  uint destinationEnd = destinationWords[2];
  out[2] = destinationEnd;
  out[3] = destinationNode;
  return savedResult;
}

// Clear ten DWORD descriptor fields and initialize count/32 storage; first full argument is unread.
// Saved ownerS-10/stateS-4; the two armed empty-base guards at owner20/24 are genuine no-ops. Return owner/RET8.
// R6GameService.dll @ 10060e30 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeSegmentedDwordBuffer(
    void *owner,uint unusedAllocatorWord,uint initialCount)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDwordStorageConstructionEH
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
    call    R6GameServiceAddresses::InitializeSegmentedDwordBufferStorage
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Allocate centered map/max(8,(initial count>>5)+3) and count/32+1 blocks of128 bytes; leave spare storage untouched.
// Reload capacity after map malloc and CURRENT count low5 after block allocations; raw EAX is that low5 value/RET4.
// Parent EBP P=entryS-4: ownerP-1c/stateP-4; catch releases current map only, preserving already allocated blocks.
// R6GameService.dll @ 100611e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeSegmentedDwordBufferStorage(void *owner,uint initialCount)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDwordStorageInitializationEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    mov    edi,DWORD PTR [ebp+0x8]
    shr    edi,0x5
    inc    edi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x1c],esi
    lea    eax,[edi+0x2]
    mov    DWORD PTR [ebp-0x18],0x8
    mov    DWORD PTR [ebp-0x14],eax
    cmp    eax,0x8
    lea    eax,[ebp-0x14]
    ja    Branch44
    lea    eax,[ebp-0x18]
  Branch44:
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
    and    eax,0x1f
    mov    DWORD PTR [esi],edx
    lea    edx,[ecx+eax*4]
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

// Cache saved ownerP-1c, free its CURRENT map20, then clear20/24 and rethrow (NULL,NULL).
// No block rollback or return after the native nonreturning rethrow; clear cached owner even if saved context changes.
// R6GameService.dll @ 1006129e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl segmented_pointer_supportCatch(void)
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

// Reload CURRENT saved constructor ownerS-10, add20 and tail genuine empty-base no-op.
// R6GameService.dll @ 10069e70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeSegmentedDwordBufferUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Reload CURRENT saved constructor ownerS-10, add24 and tail genuine empty-base no-op.
// R6GameService.dll @ 10069e7b : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeSegmentedDwordBufferUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x24
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact two-state empty-base construction map84984/FuncInfo84994, then tail CRT dispatch.
// R6GameService.dll @ 10069e86 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDwordStorageConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeSegmentedDwordBufferExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact no-action unwind map849ec, catch849fc/try84a0c and FuncInfo84a20, then tail CRT dispatch.
// R6GameService.dll @ 10069eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDwordStorageInitializationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeSegmentedDwordBufferStorageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 10084984 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeSegmentedDwordBufferUnwindMap[2] = {
  {-1, R6GameServiceAddresses::InitializeSegmentedDwordBufferUnwind1},
  {0x0, R6GameServiceAddresses::InitializeSegmentedDwordBufferUnwind2},
};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 10084984 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeSegmentedDwordBufferExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitializeSegmentedDwordBufferUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 100849ec : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeSegmentedDwordBufferStorageUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 100849fc : native storage identity retained.
const R6GameServiceNative::CatchHandler segmented_pointer_supportGAssociationConstructionEH4[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::segmented_pointer_supportCatch},
};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 100849fc : native storage identity retained.
const R6GameServiceNative::TryBlock InitializeSegmentedDwordBufferStorageTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::segmented_pointer_supportGAssociationConstructionEH4},
};

// Literal native construction unwind, catch/try or FuncInfo record.
// R6GameService.dll data @ 100849ec : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeSegmentedDwordBufferStorageExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitializeSegmentedDwordBufferStorageUnwindMap,
  0x1,
  R6GameServiceAddresses::InitializeSegmentedDwordBufferStorageTryMap,
  0x0,
  0x0,
};
