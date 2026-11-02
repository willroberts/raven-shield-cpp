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
__declspec(naked) SegmentedWordCursor * __thiscall EraseSegmentedObjectRange(
    void *owner,SegmentedWordCursor *result,SegmentedWordCursor first,
    SegmentedWordCursor last)
{
  __asm {
    sub    esp,0x64
    mov    eax,DWORD PTR [esp+0x70]
    push    ebx
    mov    ebx,DWORD PTR [esp+0x78]
    push    ebp
    mov    ebp,DWORD PTR [esp+0x84]
    push    esi
    mov    esi,DWORD PTR [esp+0x78]
    push    edi
    mov    edi,DWORD PTR [esp+0x88]
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x58],eax
    je    Branch14
  Branch11:
    mov    ecx,DWORD PTR [esp+0x10]
    lea    eax,[ecx+0x14]
    mov    edx,eax
    mov    eax,DWORD PTR [edx]
    cmp    esi,eax
    mov    ecx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esp+0x38],ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x3c],ecx
    mov    edx,DWORD PTR [edx+0xc]
    mov    DWORD PTR [esp+0x40],edx
    je    Branch14
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch12
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch12:
    add    esi,0x4
    cmp    esi,ebx
    jne    Branch13
    mov    esi,DWORD PTR [edi+0x4]
    add    edi,0x4
    lea    ebx,[esi+0x80]
  Branch13:
    cmp    esi,ebp
    jne    Branch11
  Branch14:
    mov    ecx,DWORD PTR [esp+0x90]
    mov    edx,DWORD PTR [esp+0x94]
    mov    eax,DWORD PTR [esp+0x98]
    mov    DWORD PTR [esp+0x18],ecx
    lea    ecx,[esp+0x7c]
    mov    DWORD PTR [esp+0x14],ebp
    push    ecx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x20],edx
    mov    DWORD PTR [esp+0x24],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [edx+0x4]
    lea    esi,[edx+0x4]
    cmp    eax,ecx
    jne    Branch18
    cmp    ebp,DWORD PTR [esi+0x10]
    jne    Branch18
    mov    edi,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x1c]
    add    edi,0x4
    cmp    edi,eax
    jae    Branch16
    lea    ebx,[esi+0x24]
  Branch15:
    mov    ecx,DWORD PTR [edi]
    push    0x20
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    eax,DWORD PTR [esi+0x1c]
    add    edi,0x4
    cmp    edi,eax
    jb    Branch15
  Branch16:
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x1c]
    cmp    edx,eax
    je    Branch17
    mov    eax,DWORD PTR [esi+0x14]
    push    0x20
    push    eax
    lea    ecx,[esi+0x24]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
  Branch17:
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
    mov    eax,DWORD PTR [esp+0x78]
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
    add    esp,0x64
    ret    0x24
  Branch18:
    lea    eax,[esp+0x24]
    lea    ecx,[esp+0x14]
    push    eax
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    push    esi
    lea    ecx,[esp+0x28]
    mov    ebx,eax
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    lea    edi,[esi+0x10]
    mov    ebp,eax
    push    esi
    mov    ecx,edi
    mov    DWORD PTR [esp+0x90],ebp
    call    R6GameServiceAddresses::MeasureSegmentedDwordCursorDistance
    sub    eax,ebx
    cdq
    sub    eax,edx
    sar    eax,1
    cmp    ebp,eax
    jge    Branch19
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x34],ecx
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x38],edx
    lea    edx,[esp+0x24]
    mov    DWORD PTR [esp+0x40],ecx
    push    edx
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x40],eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    push    esi
    lea    ecx,[esp+0x58]
    call    R6GameServiceAddresses::CopySegmentedCursor
    mov    al,BYTE PTR [esp+0x78]
    lea    ecx,[esp+0x7c]
    push    ecx
    lea    edx,[esp+0x38]
    sub    esp,0x10
    mov    BYTE PTR [esp+0x90],al
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    eax,[esp+0x68]
    mov    ecx,esp
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    edx,[esp+0x88]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0x98]
    push    eax
    call    R6GameServiceAddresses::MoveSegmentedDwordRangeBackward
    mov    ecx,esi
    push    ebx
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x80],edx
    mov    eax,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [esp+0x84],eax
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [esp+0x88],edx
    mov    eax,DWORD PTR [ecx+0xc]
    lea    ecx,[esp+0x80]
    mov    DWORD PTR [esp+0x8c],eax
    call    R6GameServiceAddresses::AdvanceSegmentedDwordCursor
    mov    ebx,DWORD PTR [esp+0x7c]
    mov    ebp,DWORD PTR [esp+0x80]
    mov    ecx,DWORD PTR [esp+0x84]
    sub    esp,0x10
    mov    edi,DWORD PTR [esp+0x98]
    mov    eax,esp
    sub    esp,0x10
    mov    DWORD PTR [eax],ebx
    mov    DWORD PTR [eax+0x4],ebp
    mov    DWORD PTR [eax+0x8],ecx
    mov    ecx,esp
    push    esi
    mov    DWORD PTR [eax+0xc],edi
    call    R6GameServiceAddresses::CopySegmentedCursor
    call    R6GameServiceAddresses::CopyByValueCursorArgumentsToScratch
    mov    edx,DWORD PTR [esi+0xc]
    push    edi
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseSegmentedPointerSlots
    mov    ecx,DWORD PTR [esp+0x84]
    mov    eax,esi
    mov    DWORD PTR [eax],ebx
    mov    DWORD PTR [eax+0x4],ebp
    mov    ebp,DWORD PTR [esp+0x8c]
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],edi
    jmp    Branch20
  Branch19:
    mov    edx,DWORD PTR [esp+0x24]
    sub    esp,0x10
    mov    eax,esp
    sub    esp,0x10
    mov    DWORD PTR [eax],edx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR [eax+0x4],ecx
    mov    edx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [eax+0x8],edx
    mov    ecx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,esp
    push    edi
    call    R6GameServiceAddresses::CopySegmentedCursor
    sub    esp,0x10
    lea    edx,[esp+0x44]
    mov    ecx,esp
    push    edx
    call    R6GameServiceAddresses::CopySegmentedCursor
    lea    eax,[esp+0xbc]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedDwordRange
    lea    ecx,[esp+0x7c]
    push    ebx
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::SubtractSegmentedDwordCursorOffset
    sub    esp,0x10
    mov    edx,edi
    mov    eax,esp
    sub    esp,0x10
    mov    ecx,DWORD PTR [edx]
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [eax+0x4],ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [eax+0x8],ecx
    mov    ecx,esp
    mov    edx,DWORD PTR [edx+0xc]
    mov    DWORD PTR [eax+0xc],edx
    lea    eax,[esp+0x9c]
    push    eax
    call    R6GameServiceAddresses::CopySegmentedCursor
    call    R6GameServiceAddresses::CopyByValueCursorArgumentsToScratch
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    edx,DWORD PTR [esp+0x88]
    add    ecx,0x4
    add    edx,0x4
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseSegmentedPointerSlots
    mov    eax,DWORD PTR [esp+0x7c]
    mov    ecx,DWORD PTR [esp+0x80]
    mov    edx,DWORD PTR [esp+0x84]
    mov    DWORD PTR [edi],eax
    mov    eax,DWORD PTR [esp+0x88]
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    mov    DWORD PTR [edi+0xc],eax
  Branch20:
    mov    edi,DWORD PTR [esp+0x78]
    push    ebp
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::AddSegmentedDwordCursorOffset
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x64
    ret    0x24
  }
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
