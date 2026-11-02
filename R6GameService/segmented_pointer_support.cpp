#include "native_addresses.h"
#include "native_records.h"

// Snapshot finish/copy cursors, then release inclusive active blocks and CURRENT map20 without clearing fields.
// Cache slot bounds but reload slot payloads/map; state0 stays armed through normal frees. OwnerS-70/stateS-4.
// Empty map returns0; otherwise preserve final allocator EAX. Cleanup69de0 shares raw block release5f480.
// R6GameService.dll @ 10060410 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseSegmentedDwordBufferBlocks(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSegmentedPointerReleaseEH
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
// R6GameService.dll data @ 100848dc : native storage identity retained.
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
__declspec(naked) int __thiscall MeasureSegmentedDwordCursorDistance(const uint *cursor,const uint *other)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [ecx+0xc]
    push    esi
    push    edi
    mov    esi,DWORD PTR [eax+0xc]
    mov    edi,DWORD PTR [ecx+0x4]
    sub    edx,esi
    mov    esi,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [eax+0x8]
    sub    esi,edi
    sar    edx,0x2
    shl    edx,0x5
    sar    esi,0x2
    add    edx,esi
    mov    esi,DWORD PTR [eax]
    sub    ecx,esi
    pop    edi
    sar    ecx,0x2
    pop    esi
    lea    eax,[edx+ecx*1-0x20]
    ret    0x4
  }
}

// Add signed element offset, selecting adjacent32-DWORD blocks by signed floor division when outside current block.
// Cache all input fields before output stores, including overlap; return result pointer, RET8.
// R6GameService.dll @ 10061c10 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __thiscall AddSegmentedDwordCursorOffset(
    const uint *cursor,SegmentedWordCursor *result,int offset)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx+0x4]
    push    ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push    esi
    mov    esi,DWORD PTR [ecx+0xc]
    push    edi
    mov    edi,DWORD PTR [ecx+0x8]
    mov    ecx,eax
    sub    ecx,edx
    sar    ecx,0x2
    add    ecx,ebx
    js    Branch14
    cmp    ecx,0x20
    jge    Branch14
    lea    ecx,[eax+ebx*4]
    jmp    Branch17
  Branch14:
    test    ecx,ecx
    jle    Branch15
    mov    eax,ecx
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    jmp    Branch16
  Branch15:
    lea    eax,[ecx+0x1]
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    dec    eax
  Branch16:
    mov    edx,DWORD PTR [esi+eax*4]
    lea    esi,[esi+eax*4]
    shl    eax,0x5
    sub    ecx,eax
    lea    edi,[edx+0x80]
    lea    ecx,[edx+ecx*4]
  Branch17:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ebx,eax
    mov    DWORD PTR [ebx],ecx
    mov    DWORD PTR [ebx+0x4],edx
    mov    DWORD PTR [ebx+0x8],edi
    pop    edi
    mov    DWORD PTR [ebx+0xc],esi
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Subtract signed offset modulo32, then select32-DWORD block by signed floor division; cache inputs before output.
// Return result pointer, RET8; no map bounds validation.
// R6GameService.dll @ 10061c80 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __thiscall SubtractSegmentedDwordCursorOffset(
    const uint *cursor,SegmentedWordCursor *result,int offset)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [esp+0x8]
    push    ebx
    mov    ebx,DWORD PTR [ecx+0x8]
    push    esi
    mov    esi,DWORD PTR [ecx+0xc]
    push    edi
    mov    edi,DWORD PTR [ecx]
    mov    ecx,edi
    sub    ecx,edx
    neg    eax
    sar    ecx,0x2
    add    ecx,eax
    js    Branch18
    cmp    ecx,0x20
    jge    Branch18
    lea    ecx,[edi+eax*4]
    jmp    Branch21
  Branch18:
    test    ecx,ecx
    jle    Branch19
    mov    eax,ecx
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    jmp    Branch20
  Branch19:
    lea    eax,[ecx+0x1]
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    dec    eax
  Branch20:
    mov    edx,DWORD PTR [esi+eax*4]
    lea    esi,[esi+eax*4]
    shl    eax,0x5
    sub    ecx,eax
    lea    ebx,[edx+0x80]
    lea    ecx,[edx+ecx*4]
  Branch21:
    mov    eax,DWORD PTR [esp+0x10]
    mov    edi,eax
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [edi+0x4],edx
    mov    DWORD PTR [edi+0x8],ebx
    mov    DWORD PTR [edi+0xc],esi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Advance current cursor by signed elements; crossing a block publishes node, reloads its block and rebuilds bounds.
// Within block EAX is new current pointer; across blocks EAX is loaded block base, while current is stored through EDX. RET4.
// R6GameService.dll @ 10061d70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AdvanceSegmentedDwordCursor(uint *cursor,int offset)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx+0x4]
    push    esi
    mov    esi,eax
    sub    esi,edx
    mov    edx,DWORD PTR [esp+0x8]
    sar    esi,0x2
    add    esi,edx
    js    Branch22
    cmp    esi,0x20
    jge    Branch22
    lea    eax,[eax+edx*4]
    pop    esi
    mov    DWORD PTR [ecx],eax
    ret    0x4
  Branch22:
    test    esi,esi
    jle    Branch23
    mov    eax,esi
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    jmp    Branch24
  Branch23:
    lea    eax,[esi+0x1]
    cdq
    and    edx,0x1f
    add    eax,edx
    sar    eax,0x5
    dec    eax
  Branch24:
    mov    edx,DWORD PTR [ecx+0xc]
    lea    edx,[edx+eax*4]
    mov    DWORD PTR [ecx+0xc],edx
    mov    edx,DWORD PTR [edx]
    shl    eax,0x5
    mov    DWORD PTR [ecx+0x4],edx
    sub    esi,eax
    mov    eax,DWORD PTR [ecx+0x4]
    add    edx,0x80
    mov    DWORD PTR [ecx+0x8],edx
    lea    edx,[eax+esi*4]
    pop    esi
    mov    DWORD PTR [ecx],edx
    ret    0x4
  }
}

// Unsigned slot-address traversal frees each CURRENT payload in cached [first,last); no map/field clearing.
// Empty range retains incoming EAX; nonempty returns final allocator EAX, RET8.
// R6GameService.dll @ 10061e80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReleaseSegmentedPointerSlots(uint *first,uint *last)
{
  __asm {
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    push    edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    esi,edi
    jae    Branch26
  Branch25:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    add    esi,0x4
    cmp    esi,edi
    jb    Branch25
  Branch26:
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Rotate by-value cursor copies, then copy positive signed distance DWORDs forward with literal source-before-store order.
// Reload next map entries at32-DWORD boundaries; return advanced destination cursor/RET52. No ownership transfer or EH.
// R6GameService.dll @ 10061eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __stdcall CopySegmentedDwordRange(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destination)
{
  __asm {
    sub    esp,0x30
    lea    eax,[esp+0x58]
    lea    ecx,[esp+0x0]
    push    esi
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x4c]
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x3c]
    lea    ecx,[esp+0x24]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x4]
    lea    ecx,[esp+0x5c]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x14]
    push    ecx
    lea    ecx,[esp+0x40]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x24]
    lea    ecx,[esp+0x4c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    esi,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [esp+0x48]
    mov    ecx,DWORD PTR [esp+0x58]
    sub    eax,ecx
    mov    ecx,DWORD PTR [esp+0x54]
    mov    edx,DWORD PTR [esp+0x3c]
    sub    ecx,esi
    sar    eax,0x2
    shl    eax,0x5
    sar    ecx,0x2
    add    eax,ecx
    mov    ecx,DWORD PTR [esp+0x40]
    sub    edx,ecx
    sar    edx,0x2
    lea    eax,[eax+edx*1-0x20]
    mov    edx,DWORD PTR [esp+0x5c]
    test    eax,eax
    jle    Branch31
    push    edi
    mov    edi,eax
  Branch27:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [edx],eax
    mov    esi,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [esp+0x58]
    add    esi,0x4
    cmp    esi,eax
    mov    DWORD PTR [esp+0x50],esi
    jne    Branch28
    mov    ecx,DWORD PTR [esp+0x5c]
    lea    eax,[ecx+0x4]
    mov    DWORD PTR [esp+0x5c],eax
    mov    eax,DWORD PTR [eax]
    mov    esi,eax
    mov    DWORD PTR [esp+0x54],eax
    lea    edx,[eax+0x80]
    mov    DWORD PTR [esp+0x50],esi
    mov    DWORD PTR [esp+0x58],edx
  Branch28:
    mov    edx,DWORD PTR [esp+0x60]
    mov    eax,DWORD PTR [esp+0x68]
    add    edx,0x4
    cmp    edx,eax
    mov    DWORD PTR [esp+0x60],edx
    jne    Branch29
    mov    eax,DWORD PTR [esp+0x6c]
    add    eax,0x4
    mov    DWORD PTR [esp+0x6c],eax
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x64],ecx
    lea    edx,[ecx+0x80]
    mov    DWORD PTR [esp+0x68],edx
    mov    edx,ecx
    mov    DWORD PTR [esp+0x60],edx
    jmp    Branch30
  Branch29:
    mov    ecx,DWORD PTR [esp+0x64]
  Branch30:
    dec    edi
    jne    Branch27
    pop    edi
    jmp    Branch32
  Branch31:
    mov    ecx,DWORD PTR [esp+0x60]
  Branch32:
    mov    eax,DWORD PTR [esp+0x38]
    mov    esi,eax
    mov    DWORD PTR [esi],edx
    mov    edx,DWORD PTR [esp+0x68]
    mov    DWORD PTR [esi+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],edx
    pop    esi
    add    esp,0x30
    ret    0x34
  }
}

// Copy second by-value cursor into local scratch and first into consumed second argument; first stays unchanged.
// Trailing full word is unread; raw EAX=entry ESP+0x14, RET36. Caller objects remain unchanged.
// R6GameService.dll @ 10062020 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall segmented_pointer_support_CopyByValueCursorArgumentsToScratch(
    SegmentedWordCursor first,SegmentedWordCursor second,uint unusedWord)
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
    add    esp,0x10
    ret    0x24
  }
}

// Copy positive signed [first,last) distance backward, predecrementing source/destination across32-DWORD blocks.
// Keep ordered loads/stores for overlap; publish advanced destination output cursor, raw output pointer/RET56. Extra word unread.
// R6GameService.dll @ 10062050 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __stdcall MoveSegmentedDwordRangeBackward(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destinationEnd,uint unusedWord)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x0]
    push    esi
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x2c]
    push    ecx
    lea    ecx,[esp+0x40]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x1c]
    lea    ecx,[esp+0x2c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    eax,DWORD PTR [esp+0x48]
    mov    edx,DWORD PTR [esp+0x38]
    mov    ecx,DWORD PTR [esp+0x34]
    sub    eax,edx
    mov    edx,DWORD PTR [esp+0x2c]
    mov    esi,DWORD PTR [esp+0x40]
    sar    eax,0x2
    sub    ecx,edx
    shl    eax,0x5
    sar    ecx,0x2
    add    eax,ecx
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    edx,ecx
    sub    edx,esi
    sar    edx,0x2
    lea    eax,[eax+edx*1-0x20]
    test    eax,eax
    jle    Branch37
    mov    edx,eax
    jmp    Branch34
  Branch33:
    mov    ecx,DWORD PTR [esp+0x3c]
  Branch34:
    cmp    ecx,DWORD PTR [esp+0x40]
    jne    Branch35
    mov    eax,DWORD PTR [esp+0x48]
    add    eax,0xfffffffc
    mov    DWORD PTR [esp+0x48],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x40],eax
    lea    ecx,[eax+0x80]
    mov    DWORD PTR [esp+0x44],ecx
  Branch35:
    mov    eax,DWORD PTR [esp+0x4]
    mov    esi,DWORD PTR [esp+0x8]
    sub    ecx,0x4
    cmp    eax,esi
    mov    DWORD PTR [esp+0x3c],ecx
    jne    Branch36
    mov    eax,DWORD PTR [esp+0x10]
    add    eax,0xfffffffc
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x8],eax
    add    eax,0x80
    mov    DWORD PTR [esp+0xc],eax
  Branch36:
    sub    eax,0x4
    dec    edx
    mov    DWORD PTR [esp+0x4],eax
    mov    ecx,DWORD PTR [ecx]
    mov    DWORD PTR [eax],ecx
    jne    Branch33
  Branch37:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,eax
    pop    esi
    mov    DWORD PTR [edx],ecx
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [edx+0x8],ecx
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [edx+0xc],ecx
    add    esp,0x10
    ret    0x38
  }
}

// Copy positive signed [first,last) distance forward, advancing source/destination across32-DWORD blocks.
// Preserve by-value rotation and literal overlap order, output advanced cursor, raw output pointer/RET56. Extra word unread.
// R6GameService.dll @ 10062140 : complete native control/access order and raw ABI retained.
__declspec(naked) SegmentedWordCursor * __stdcall MoveSegmentedDwordRangeForward(
    SegmentedWordCursor *result,SegmentedWordCursor first,SegmentedWordCursor last,
    SegmentedWordCursor destination,uint unusedWord)
{
  __asm {
    sub    esp,0x20
    lea    eax,[esp+0x48]
    lea    ecx,[esp+0x0]
    push    esi
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    ecx,[esp+0x3c]
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    edx,[esp+0x2c]
    lea    ecx,[esp+0x4c]
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    esi,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x58]
    sub    eax,ecx
    mov    ecx,DWORD PTR [esp+0x54]
    mov    edx,DWORD PTR [esp+0x14]
    sub    ecx,esi
    sar    eax,0x2
    shl    eax,0x5
    sar    ecx,0x2
    add    eax,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    sub    edx,ecx
    sar    edx,0x2
    lea    eax,[eax+edx*1-0x20]
    mov    edx,DWORD PTR [esp+0x4]
    test    eax,eax
    jle    Branch42
    push    edi
    mov    edi,eax
  Branch38:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [edx],eax
    mov    esi,DWORD PTR [esp+0x50]
    mov    eax,DWORD PTR [esp+0x58]
    add    esi,0x4
    cmp    esi,eax
    mov    DWORD PTR [esp+0x50],esi
    jne    Branch39
    mov    ecx,DWORD PTR [esp+0x5c]
    lea    eax,[ecx+0x4]
    mov    DWORD PTR [esp+0x5c],eax
    mov    eax,DWORD PTR [eax]
    mov    esi,eax
    mov    DWORD PTR [esp+0x54],eax
    lea    edx,[eax+0x80]
    mov    DWORD PTR [esp+0x50],esi
    mov    DWORD PTR [esp+0x58],edx
  Branch39:
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0x10]
    add    edx,0x4
    cmp    edx,eax
    mov    DWORD PTR [esp+0x8],edx
    jne    Branch40
    mov    eax,DWORD PTR [esp+0x14]
    add    eax,0x4
    mov    DWORD PTR [esp+0x14],eax
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esp+0xc],ecx
    lea    edx,[ecx+0x80]
    mov    DWORD PTR [esp+0x10],edx
    mov    edx,ecx
    mov    DWORD PTR [esp+0x8],edx
    jmp    Branch41
  Branch40:
    mov    ecx,DWORD PTR [esp+0xc]
  Branch41:
    dec    edi
    jne    Branch38
    pop    edi
    jmp    Branch43
  Branch42:
    mov    ecx,DWORD PTR [esp+0x8]
  Branch43:
    mov    eax,DWORD PTR [esp+0x28]
    mov    esi,eax
    mov    DWORD PTR [esi],edx
    mov    edx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x4],ecx
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],edx
    pop    esi
    add    esp,0x20
    ret    0x38
  }
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
