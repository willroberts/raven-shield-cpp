#include "native_addresses.h"
#include "native_records.h"

// Shared twelve-byte owned records and ring/vector resize helpers; whole-container and record class names unresolved.

// Reject initial lowWORD>7ffe; otherwise clear five WORDs, delete old records and publish returned begin as end.
// Reload CURRENT full count after deletion, store lowWORD/+doubledWORD and fill twice-lowWORD slots in place or reallocate.
// ENTRY ESP S: fillS-24/inner fillS-18/cached old endS-28/cookieS-29/stateS-4; caller countS+4 is reused as scratch.
// Preserve magic signed division, current vector fields, temporary disarm order, raw upper EAX/AL1 and RET4; no vector rollback.
// R6GameService.dll @ 1005eeb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResizeOwnedRecordArray(void *owner,uint requestedWord)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectArrayResizeEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    cmp    WORD PTR [esp+0x30],0x7ffe
    push    edi
    mov    edi,ecx
    jbe    Branch1
    xor    al,al
    pop    edi
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  Branch1:
    push    ebx
    push    ebp
    mov    dl,BYTE PTR [esp+0x3c]
    push    esi
    xor    ecx,ecx
    lea    esi,[edi+0x10]
    mov    WORD PTR [edi+0x4],cx
    mov    WORD PTR [edi+0x6],cx
    mov    WORD PTR [edi+0x8],cx
    mov    WORD PTR [edi+0xa],cx
    mov    WORD PTR [edi+0xc],cx
    mov    ebp,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x4]
    push    ecx
    lea    ecx,[esp+0x17]
    mov    BYTE PTR [esp+0x17],dl
    push    ecx
    push    ebp
    push    eax
    push    eax
    call    R6GameServiceAddresses::AssignOwnedRecordsForward
    mov    ebx,eax
    mov    eax,DWORD PTR [esi+0x4]
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x14],eax
    mov    ebp,ebx
    je    Branch3
  Branch2:
    push    0x0
    mov    ecx,ebp
    call    R6GameServiceAddresses::DeleteOwnedObjectRecord
    mov    eax,DWORD PTR [esp+0x14]
    add    ebp,0xc
    cmp    ebp,eax
    jne    Branch2
  Branch3:
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esi+0x4],ebx
    xor    ebx,ebx
    mov    WORD PTR [edi+0x4],cx
    lea    eax,[ecx+ecx*1]
    mov    DWORD PTR [esp+0x18],ebx
    mov    WORD PTR [edi+0x6],ax
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x20],ebx
    mov    edi,DWORD PTR [edi+0x14]
    and    eax,0xffff
    mov    DWORD PTR [esp+0x38],ebx
    mov    ecx,eax
    je    Branch8
    mov    ebp,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,ebp
    mov    eax,0x2aaaaaab
    imul    edx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    cmp    edx,ecx
    jb    Branch6
    mov    edx,ebx
    mov    eax,ebx
    mov    DWORD PTR [esp+0x24],ebx
    mov    DWORD PTR [esp+0x28],edx
    mov    DWORD PTR [esp+0x2c],eax
    sub    ebp,edi
    mov    eax,0x2aaaaaab
    imul    ebp
    sar    edx,1
    mov    eax,edx
    mov    ebp,DWORD PTR [esi+0x4]
    shr    eax,0x1f
    add    edx,eax
    mov    BYTE PTR [esp+0x38],0x1
    mov    ebx,edx
    cmp    ebx,ecx
    jbe    Branch4
    lea    ebx,[ecx+ecx*2]
    lea    ecx,[esp+0x40]
    shl    ebx,0x2
    mov    eax,ebp
    push    ecx
    sub    eax,ebx
    push    ebp
    push    ebp
    push    eax
    mov    DWORD PTR [esp+0x24],eax
    call    R6GameServiceAddresses::CopyRawRecordRange
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    dl,BYTE PTR [esp+0x40]
    add    eax,ebx
    mov    DWORD PTR [esi+0x4],eax
    lea    eax,[esp+0x40]
    push    0x0
    push    eax
    push    ebp
    push    ecx
    push    edi
    mov    BYTE PTR [esp+0x54],dl
    call    R6GameServiceAddresses::AssignOwnedRecordsBackward
    lea    edx,[esp+0x24]
    add    ebx,edi
    push    edx
    push    ebx
    jmp    Branch5
  Branch4:
    lea    eax,[esp+0x24]
    sub    ecx,ebx
    push    eax
    push    ecx
    push    ebp
    mov    DWORD PTR [esp+0x4c],ecx
    call    R6GameServiceAddresses::ForwardRepeatedRecordFill
    mov    eax,DWORD PTR [esp+0x40]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[eax+eax*2]
    shl    ecx,0x2
    add    edx,ecx
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,edx
    lea    edx,[esp+0x40]
    push    edx
    push    eax
    push    ebp
    push    edi
    call    R6GameServiceAddresses::CopyRawRecordRange
    lea    eax,[ebx+ebx*2]
    mov    ebx,DWORD PTR [esi+0x4]
    shl    eax,0x2
    lea    ecx,[esp+0x24]
    add    ebx,eax
    push    ecx
    mov    DWORD PTR [esi+0x4],ebx
    push    ebp
  Branch5:
    push    edi
    call    R6GameServiceAddresses::AssignOwnedRecordFill
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x38],0x0
    call    R6GameServiceAddresses::DestroyOwnedRecordObject
    jmp    Branch7
  Branch6:
    push    0x0
    lea    edx,[esp+0x44]
    push    ecx
    lea    eax,[esp+0x20]
    push    edx
    push    eax
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::ReallocateAndInsertOwnedRecords
  Branch7:
    mov    ebx,DWORD PTR [esp+0x18]
  Branch8:
    test    ebx,ebx
    mov    DWORD PTR [esp+0x38],0xffffffff
    je    Branch9
    mov    edx,DWORD PTR [ebx]
    push    0x1
    mov    ecx,ebx
    call    DWORD PTR [edx]
  Branch9:
    mov    ecx,DWORD PTR [esp+0x30]
    pop    esi
    pop    ebp
    pop    ebx
    mov    al,0x1
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  }
}

// Same initial lowWORD guard and old-record clearing, then insert twice CURRENT lowWORD count through f280.
// Divide CURRENT WORDc+WORD4 by CURRENT WORD6 and store remainder atWORDa; accepted0 can reach native DIV0.
// ENTRY ESP S: fillS-18/saved returned beginS-1c/cached old endS-20/cookieS-21/stateS-4.
// Keep one-state fill guard armed through division; disarm before fill deletion. Raw quotient/delete upper EAX with AL1, RET4.
// R6GameService.dll @ 1005f0b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResetOwnedRecordRing(void *owner,uint requestedWord)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRingResetEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    cmp    WORD PTR [esp+0x28],0x7ffe
    push    esi
    mov    esi,ecx
    jbe    Branch10
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret    0x4
  Branch10:
    push    ebx
    push    ebp
    mov    cl,BYTE PTR [esp+0x34]
    push    edi
    xor    ebx,ebx
    lea    edi,[esi+0x10]
    mov    WORD PTR [esi+0x4],bx
    mov    WORD PTR [esi+0x6],bx
    mov    WORD PTR [esi+0x8],bx
    mov    WORD PTR [esi+0xa],bx
    mov    WORD PTR [esi+0xc],bx
    mov    ebp,DWORD PTR [edi]
    mov    eax,DWORD PTR [edi+0x4]
    lea    edx,[esp+0x13]
    push    ebx
    push    edx
    push    ebp
    push    eax
    push    eax
    mov    BYTE PTR [esp+0x27],cl
    call    R6GameServiceAddresses::AssignOwnedRecordsForward
    mov    ecx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x18],eax
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x14],ecx
    mov    ebp,eax
    je    Branch12
  Branch11:
    push    ebx
    mov    ecx,ebp
    call    R6GameServiceAddresses::DeleteOwnedObjectRecord
    mov    eax,DWORD PTR [esp+0x14]
    add    ebp,0xc
    cmp    ebp,eax
    jne    Branch11
    mov    eax,DWORD PTR [esp+0x18]
  Branch12:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR [edi+0x4],eax
    mov    WORD PTR [esi+0x4],cx
    mov    DWORD PTR [esp+0x1c],ebx
    lea    eax,[ecx+ecx*1]
    mov    DWORD PTR [esp+0x20],ebx
    mov    WORD PTR [esi+0x6],ax
    mov    DWORD PTR [esp+0x24],ebx
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x1c]
    and    eax,0xffff
    push    edx
    push    eax
    push    ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x3c],ebx
    call    R6GameServiceAddresses::InsertRepeatedOwnedRecords
    xor    eax,eax
    xor    ecx,ecx
    mov    ax,WORD PTR [esi+0xc]
    mov    cx,WORD PTR [esi+0x4]
    add    eax,ecx
    xor    ecx,ecx
    mov    cx,WORD PTR [esi+0x6]
    xor    edx,edx
    div    ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    pop    edi
    cmp    ecx,ebx
    pop    ebp
    mov    DWORD PTR [esp+0x28],0xffffffff
    pop    ebx
    mov    WORD PTR [esi+0xa],dx
    je    Branch13
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch13:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret    0x4
  }
}

// Delete CURRENT record DWORD0 object through CURRENT primary slot0/full1; NULL preserves incoming EAX.
// No field clearing or record storage release; receiver in ECX, no stack arguments.
// R6GameService.dll @ 1005ee10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyOwnedRecordObject(void *record)
{
  __asm {
    mov    ecx,DWORD PTR [ecx]
    test    ecx,ecx
    je    Branch14
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch14:
    ret
  }
}

// Delete CURRENT DWORD0 object, then inspect CURRENT flag bit0 and optionally CDECL-free cached record storage.
// Keep record words stale, return original receiver and RET4; no local EH or pending outer-storage guard.
// R6GameService.dll @ 1005fa80 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteOwnedObjectRecord(void *record,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch15
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch15:
    test    BYTE PTR [esp+0x8],0x1
    je    Branch16
    push    esi
    call    R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch16:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Forward-assign signed(sourceEnd-sourceBegin)/12 records, deleting each CURRENT destination object before source reads.
// Nonpositive count returns original destination; no ownership clearing/copy guard. Five full words/RET20.
// R6GameService.dll @ 1005f980 : complete native control/access order and raw ABI retained.
__declspec(naked) int *__stdcall AssignOwnedRecordsForward(
    const int *sourceBegin,const int *sourceEnd,int *destination,uint unusedTag,uint unusedWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    push    edi
    mov    edi,DWORD PTR [esp+0x8]
    mov    eax,0x2aaaaaab
    sub    ecx,edi
    imul    ecx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    test    edx,edx
    jle    Branch19
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    ebx,edx
  Branch17:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch18
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch18:
    mov    eax,DWORD PTR [edi]
    add    edi,0xc
    mov    DWORD PTR [esi],eax
    mov    ecx,DWORD PTR [edi-0x8]
    mov    DWORD PTR [esi+0x4],ecx
    mov    edx,DWORD PTR [edi-0x4]
    mov    DWORD PTR [esi+0x8],edx
    add    esi,0xc
    dec    ebx
    jne    Branch17
    mov    eax,esi
    pop    esi
    pop    ebx
    pop    edi
    ret    0x14
  Branch19:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    ret    0x14
  }
}

// Clean CURRENT outer fill at inherited S-24; preserve raw NULL EAX.
// R6GameService.dll @ 10069c40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResizeOwnedRecordArrayUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Clean CURRENT inner fill at inherited S-18, then outer state0.
// R6GameService.dll @ 10069c48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResizeOwnedRecordArrayUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Clean CURRENT ring/reset or insertion snapshot at inherited S-18.
// R6GameService.dll @ 10069c60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Select exact native fill-record cleanup FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectArrayResizeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ResizeOwnedRecordArrayExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select shared ring-reset/insertion fill cleanup FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRingResetEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::owned_record_array_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846b0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ResizeOwnedRecordArrayUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ResizeOwnedRecordArrayUnwind1},
  {0x0, R6GameServiceAddresses::ResizeOwnedRecordArrayUnwind2},
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ResizeOwnedRecordArrayExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ResizeOwnedRecordArrayUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846dc : native storage identity retained.
const R6GameServiceNative::UnwindEntry owned_record_array_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwind1},
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846dc : native storage identity retained.
const R6GameServiceNative::FuncInfo owned_record_array_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Insert full unsigned count: count0 skips storage access; otherwise choose current capacity or growth.
// In-place snapshots all three fill words, then shifts/assigns records with destination deletion; finally deletes snapshot object.
// ENTRY ESP S: snapshotS-18/stateS-4; original position/fill argument slots become cursor/count/cookie scratch.
// Preserve native forward/backward assignment, current end reloads and shared69c68 fill guard; RET12/raw EAX.
// R6GameService.dll @ 1005f280 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InsertRepeatedOwnedRecords(
    void *container,void *position,uint count,const uint *fillRecord)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectRingResetEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x24]
    push    edi
    test    ecx,ecx
    je    Branch30
    mov    edi,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,edi
    mov    eax,0x2aaaaaab
    imul    edx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    cmp    edx,ecx
    jb    Branch29
    mov    edx,DWORD PTR [esp+0x2c]
    push    ebx
    push    ebp
    mov    eax,DWORD PTR [edx]
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esp+0x14],eax
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x18],edx
    mov    eax,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [esp+0x24],0x0
    sub    edi,eax
    mov    eax,0x2aaaaaab
    imul    edi
    sar    edx,1
    mov    eax,edx
    mov    edi,DWORD PTR [esi+0x4]
    shr    eax,0x1f
    add    edx,eax
    mov    ebx,edx
    cmp    ebx,ecx
    jbe    Branch25
    lea    ebx,[ecx+ecx*2]
    lea    ecx,[esp+0x34]
    shl    ebx,0x2
    mov    ebp,edi
    push    ecx
    sub    ebp,ebx
    push    edi
    push    edi
    push    ebp
    call    R6GameServiceAddresses::CopyRawRecordRange
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,ebp
    add    eax,ebx
    mov    DWORD PTR [esi+0x4],eax
    mov    esi,DWORD PTR [esp+0x2c]
    sub    ecx,esi
    mov    eax,0x2aaaaaab
    imul    ecx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    test    edx,edx
    jle    Branch22
    add    ebp,0x8
    mov    DWORD PTR [esp+0x2c],edx
  Branch20:
    mov    ecx,DWORD PTR [edi-0xc]
    sub    edi,0xc
    sub    ebp,0xc
    test    ecx,ecx
    je    Branch21
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch21:
    mov    eax,DWORD PTR [ebp-0x8]
    mov    DWORD PTR [edi],eax
    mov    ecx,DWORD PTR [ebp-0x4]
    mov    eax,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edi+0x4],ecx
    mov    edx,DWORD PTR [ebp+0x0]
    dec    eax
    mov    DWORD PTR [edi+0x8],edx
    mov    DWORD PTR [esp+0x2c],eax
    jne    Branch20
  Branch22:
    add    ebx,esi
    cmp    esi,ebx
    je    Branch28
  Branch23:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch24
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch24:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x4],edx
    mov    DWORD PTR [esi+0x8],eax
    add    esi,0xc
    cmp    esi,ebx
    jne    Branch23
    jmp    Branch28
  Branch25:
    mov    dl,BYTE PTR [esp+0x2c]
    mov    ebp,ecx
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x10]
    sub    ebp,ebx
    push    eax
    push    ecx
    push    ebp
    push    edi
    mov    BYTE PTR [esp+0x44],dl
    call    R6GameServiceAddresses::ConstructRepeatedRawRecords
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[ebp+ebp*2+0x0]
    mov    ebp,DWORD PTR [esp+0x2c]
    lea    ecx,[esp+0x2c]
    shl    edx,0x2
    add    eax,edx
    push    ecx
    push    eax
    push    edi
    push    ebp
    mov    DWORD PTR [esi+0x4],eax
    call    R6GameServiceAddresses::CopyRawRecordRange
    mov    ecx,DWORD PTR [esi+0x4]
    lea    edx,[ebx+ebx*2]
    shl    edx,0x2
    add    ecx,edx
    cmp    ebp,edi
    mov    DWORD PTR [esi+0x4],ecx
    mov    esi,ebp
    je    Branch28
  Branch26:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch27
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch27:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x4],edx
    mov    DWORD PTR [esi+0x8],eax
    add    esi,0xc
    cmp    esi,edi
    jne    Branch26
  Branch28:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    ebp
    test    ecx,ecx
    mov    DWORD PTR [esp+0x20],0xffffffff
    pop    ebx
    je    Branch30
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
    pop    edi
    pop    esi
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0xc
  Branch29:
    mov    edx,DWORD PTR [esp+0x24]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esp+0x34]
    lea    eax,[esp+0x2c]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ReallocateAndInsertOwnedRecords
  Branch30:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0xc
  }
}

// Allocate12*(oldSize+max(oldSize,count)) modulo32, copy prefix, construct fill and optionally copy CURRENT suffix.
// Only lowBYTE of current suppressSuffixWord controls suffix copy. Single fill skips stores if destination NULL.
// EBP frame P=entryS-4: raw newP-18/completed endP-14/saved ESPP-10/stateP-4; catch protects only construction state0.
// Disarm BEFORE deleting old payloads/freeing CURRENT old allocation, then publish new begin/end/capacity. RET20/capacity EAX.
// R6GameService.dll @ 1005f610 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReallocateAndInsertOwnedRecords(
    void *container,void *position,const uint *fillRecord,void *unusedTag,uint count,uint suppressSuffixWord)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOwnedRecordGrowthEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push    ebx
    push    esi
    mov    esi,ecx
    mov    ebx,DWORD PTR [ebp+0x14]
    push    edi
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi]
    sub    ecx,eax
    mov    eax,0x2aaaaaab
    imul    ecx
    sar    edx,1
    mov    eax,edx
    mov    DWORD PTR [ebp-0x10],esp
    shr    eax,0x1f
    add    edx,eax
    lea    eax,[ebp+0x14]
    cmp    edx,ebx
    mov    DWORD PTR [ebp-0x18],edx
    jb    Branch31
    lea    eax,[ebp-0x18]
  Branch31:
    mov    edi,DWORD PTR [eax]
    add    edi,edx
    lea    ecx,[edi+edi*2]
    shl    ecx,0x2
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi]
    lea    edx,[ebp+0x17]
    push    edx
    mov    DWORD PTR [ebp-0x18],eax
    mov    DWORD PTR [ebp-0x14],eax
    push    eax
    mov    eax,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0x0
    push    eax
    push    ecx
    call    R6GameServiceAddresses::CopyRawRecordRange
    cmp    ebx,0x1
    mov    DWORD PTR [ebp-0x14],eax
    jne    Branch33
    test    eax,eax
    je    Branch32
    mov    edx,DWORD PTR [ebp+0xc]
    mov    ecx,eax
    mov    ebx,DWORD PTR [edx]
    mov    DWORD PTR [ecx],ebx
    mov    ebx,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],ebx
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0x8],edx
  Branch32:
    add    eax,0xc
    mov    DWORD PTR [ebp-0x14],eax
    jmp    Branch34
  Branch33:
    mov    edx,DWORD PTR [ebp+0xc]
    lea    ecx,[ebp+0x17]
    push    ecx
    push    edx
    push    ebx
    push    eax
    call    R6GameServiceAddresses::ConstructRepeatedRawRecords
    mov    DWORD PTR [ebp-0x14],eax
  Branch34:
    mov    cl,BYTE PTR [ebp+0x18]
    test    cl,cl
    jne    Branch35
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[ebp+0x1b]
    push    ecx
    push    eax
    mov    eax,DWORD PTR [ebp+0x8]
    push    edx
    push    eax
    call    R6GameServiceAddresses::CopyRawRecordRange
    mov    DWORD PTR [ebp-0x14],eax
  Branch35:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esi]
    cmp    ebx,eax
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    DWORD PTR [ebp+0x14],eax
    je    Branch38
  Branch36:
    mov    ecx,DWORD PTR [ebx]
    test    ecx,ecx
    je    Branch37
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
    mov    eax,DWORD PTR [ebp+0x14]
  Branch37:
    add    ebx,0xc
    cmp    ebx,eax
    jne    Branch36
  Branch38:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebp-0x18]
    mov    ecx,DWORD PTR [ebp-0x14]
    lea    edx,[edi+edi*2]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],ecx
    mov    ecx,DWORD PTR [ebp-0xc]
    lea    eax,[eax+edx*4]
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x14
  }
}

// Growth catch: cache completed new range from CURRENT parentP-18/P-14, delete its nonnull objects, free cached begin.
// Rethrow through CxxThrowException(NULL,NULL); no old-vector rollback or artificial return. Inherited parent EBP.
// R6GameService.dll @ 1005f737 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportCatch(void)
{
  __asm {
    mov    ebx,DWORD PTR [ebp-0x18]
    mov    edi,DWORD PTR [ebp-0x14]
    cmp    ebx,edi
    mov    esi,ebx
    je    Branch41
  Branch39:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch40
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch40:
    add    esi,0xc
    cmp    esi,edi
    jne    Branch39
  Branch41:
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    0x0
    push    0x0
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// Copy three DWORDs per record forward to uninitialized storage; test current destination for NULL on EACH iteration.
// No payload deletion, source clearing or tag read; return advanced destination/RET16. Overlap propagates native writes.
// R6GameService.dll @ 1005f770 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__stdcall CopyRawRecordRange(uint *source,uint *sourceEnd,uint *destination,const void *unusedTag)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0xc]
    cmp    ecx,edx
    je    Branch44
    push    ebx
    push    esi
    push    edi
  Branch42:
    test    eax,eax
    je    Branch43
    mov    esi,ecx
    mov    edi,eax
    mov    ebx,DWORD PTR [esi]
    mov    DWORD PTR [edi],ebx
    mov    ebx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [edi+0x4],ebx
    mov    esi,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edi+0x8],esi
  Branch43:
    add    ecx,0xc
    add    eax,0xc
    cmp    ecx,edx
    jne    Branch42
    pop    edi
    pop    esi
    pop    ebx
  Branch44:
    ret    0x10
  }
}

// Repeat unsigned count records, reloading all value words per nonnull destination iteration.
// Count0 skips value/destination access; no ownership deletion or tag read. Return advanced destination/RET16.
// R6GameService.dll @ 1005f9e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__stdcall ConstructRepeatedRawRecords(uint *destination,uint count,const uint *value,const void *unusedTag)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0x4]
    test    ecx,ecx
    jbe    Branch47
    mov    edx,DWORD PTR [esp+0xc]
    push    ebx
    push    esi
    push    edi
  Branch45:
    test    eax,eax
    je    Branch46
    mov    esi,edx
    mov    edi,eax
    mov    ebx,DWORD PTR [esi]
    mov    DWORD PTR [edi],ebx
    mov    ebx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [edi+0x4],ebx
    mov    esi,DWORD PTR [esi+0x8]
    mov    DWORD PTR [edi+0x8],esi
  Branch46:
    add    eax,0xc
    dec    ecx
    jne    Branch45
    pop    edi
    pop    esi
    pop    ebx
  Branch47:
    ret    0x10
  }
}

// Select growth two-state/no-action map plus catch-all construction handler, then tail CRT dispatch.
// R6GameService.dll @ 10069c90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOwnedRecordGrowthEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084774 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReallocateAndInsertOwnedRecordsUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084784 : native storage identity retained.
const R6GameServiceNative::CatchHandler owned_record_array_supportGOwnedRecordGrowthEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::owned_record_array_supportCatch},
};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084784 : native storage identity retained.
const R6GameServiceNative::TryBlock ReallocateAndInsertOwnedRecordsTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::owned_record_array_supportGOwnedRecordGrowthEH},
};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084774 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReallocateAndInsertOwnedRecordsExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsUnwindMap,
  0x1,
  R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsTryMap,
  0x0,
  0x0,
};

// Assign fill forward: delete each CURRENT destination object, THEN reload three words through cached value pointer.
// Empty range preserves incoming EAX; nonempty returns last copied third word. No local EH/source clearing; RET12.
// R6GameService.dll @ 1005f7b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall AssignOwnedRecordFill(uint *destination,uint *end,const uint *value)
{
  __asm {
    push    ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    cmp    esi,ebx
    je    Branch50
    push    edi
    mov    edi,DWORD PTR [esp+0x18]
  Branch48:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch49
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch49:
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [esi],ecx
    mov    edx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi+0x8]
    mov    DWORD PTR [esi+0x8],eax
    add    esi,0xc
    cmp    esi,ebx
    jne    Branch48
    pop    edi
  Branch50:
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Forward full count/value to raw fill with tagS-1 holding value POINTER low byte; tag is unread by callee.
// POP ECX restores original low24 bits with high byte replaced by pointer lowBYTE. Return raw fill end/RET12.
// R6GameService.dll @ 1005f7f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__stdcall ForwardRepeatedRecordFill(uint *destination,uint count,const uint *value)
{
  __asm {
    push    ecx
    mov    al,BYTE PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x3]
    mov    BYTE PTR [esp+0x3],al
    mov    eax,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esp+0xc]
    push    edx
    push    eax
    push    ecx
    call    R6GameServiceAddresses::ConstructRepeatedRawRecords
    pop    ecx
    ret    0xc
  }
}

// Assign records backward using signed(sourceEnd-sourceBegin)/12 truncated toward0; delete current destination object first.
// Read source words only after delete; nonpositive count skips storage. Return retreated destination/RET20; extra words unread.
// R6GameService.dll @ 1005fa20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint *__stdcall AssignOwnedRecordsBackward(
    const uint *sourceBegin,const uint *sourceEnd,uint *destinationEnd,uint unusedTag,uint unusedSelector)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    ecx,edi
    sub    ecx,eax
    mov    eax,0x2aaaaaab
    imul    ecx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    test    edx,edx
    jle    Branch53
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    ebx,edx
  Branch51:
    mov    ecx,DWORD PTR [esi-0xc]
    sub    esi,0xc
    sub    edi,0xc
    test    ecx,ecx
    je    Branch52
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch52:
    mov    eax,DWORD PTR [edi]
    dec    ebx
    mov    DWORD PTR [esi],eax
    mov    ecx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],ecx
    mov    edx,DWORD PTR [edi+0x8]
    mov    DWORD PTR [esi+0x8],edx
    jne    Branch51
    mov    eax,esi
    pop    esi
    pop    ebx
    pop    edi
    ret    0x14
  Branch53:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    ret    0x14
  }
}

// Cache initial begin/end, delete nonnull record objects forward, then free CURRENT begin; leave vector fields stale.
// ENTRY ESP S: saved vectorS-10/stateS-4. Shared state0 release stays armed THROUGH normal free; raw EAX retained.
// R6GameService.dll @ 1005ecb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyOwnedRecordVector(void *vector)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOwnedRecordVectorDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebx
    mov    ebx,ecx
    push    esi
    push    edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    edi,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    cmp    esi,edi
    mov    DWORD PTR [esp+0x18],0x0
    je    Branch56
  Branch54:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch55
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch55:
    add    esi,0xc
    cmp    esi,edi
    jne    Branch54
  Branch56:
    mov    eax,DWORD PTR [ebx]
    pop    edi
    pop    esi
    pop    ebx
    test    eax,eax
    je    Branch57
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch57:
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Same payload/storage lifetime for vector at owner+10, calling shared record cleanup for every slot.
// Save adjusted vector at S-10 for shared EH. NULL begin skips free without normalizing current EAX; no field clearing.
// R6GameService.dll @ 1005ee50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyEmbeddedOwnedRecords(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOwnedRecordVectorDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebx
    lea    ebx,[ecx+0x10]
    push    esi
    push    edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    edi,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    cmp    esi,edi
    mov    DWORD PTR [esp+0x18],0x0
    je    Branch59
  Branch58:
    mov    ecx,esi
    call    R6GameServiceAddresses::DestroyOwnedRecordObject
    add    esi,0xc
    cmp    esi,edi
    jne    Branch58
  Branch59:
    mov    ebx,DWORD PTR [ebx]
    test    ebx,ebx
    je    Branch60
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch60:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Shared allocation helper: load CURRENT context DWORD0, free it if nonnull, preserve field and raw free EAX; NULL returns0.
// R6GameService.dll @ 10061aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseNonNullFirstWordBuffer(void *context)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    test    eax,eax
    je    Branch61
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch61:
    ret
  }
}

// Shared standalone/embedded-vector state0 cleanup: free CURRENT first word through CURRENT saved contextS-10.
// Payload deletion is not retried; normal final free has not disarmed this state.
// R6GameService.dll @ 10069c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportSharedLifetimeUnwind12(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Select exact shared standalone/embedded vector storage-release map and tail-dispatch CRT.
// R6GameService.dll @ 10069c08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOwnedRecordVectorDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::owned_record_array_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared vector storage-cleanup map/FuncInfo.
// R6GameService.dll data @ 10084618 : native storage identity retained.
const R6GameServiceNative::UnwindEntry owned_record_array_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwind12},
};

// Literal shared vector storage-cleanup map/FuncInfo.
// R6GameService.dll data @ 10084618 : native storage identity retained.
const R6GameServiceNative::FuncInfo owned_record_array_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Tail-forward original ECX/registers/stack to embedded-vector destruction, retaining its raw EAX.
// R6GameService.dll @ 1005d110 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyEmbeddedOwnedRecords(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyEmbeddedOwnedRecords
  }
}

// Test lowWORD index in current unsigned circular oldest+c/tail+a range, using modulus6 on the wrapped high portion.
// Return cached oldest/entry upper EAX with only AL status changed; RET4, no cursor/count effects.
// R6GameService.dll @ 1005f1d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall IsOwnerRecordIndexAccepted(void *ring,uint indexWord)
{
  __asm {
    mov    ax,WORD PTR [ecx+0xc]
    mov    dx,WORD PTR [ecx+0xa]
    cmp    ax,dx
    push    esi
    ja    Branch62
    mov    cx,WORD PTR [esp+0x8]
    cmp    cx,ax
    jb    Branch65
    cmp    cx,dx
    jmp    Branch64
  Branch62:
    mov    si,WORD PTR [esp+0x8]
    cmp    si,dx
    jae    Branch63
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch63:
    cmp    si,ax
    jb    Branch65
    cmp    si,WORD PTR [ecx+0x6]
  Branch64:
    jae    Branch65
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch65:
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Publish current oldest slot payload to supplied output before NULL test; empty returns slot upper24/AL0 unchanged
// cursors.
// Nonnull clears slot, advances current oldest and tail modulo cached WORD6, stores oldest before second divide,
// returns quotient/AL1.
// Keep slot ancillary words/count untouched, modulo16 increments, output alias effects and RET4; no local EH.
// R6GameService.dll @ 1005f220 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PopOwnedRingRecord(void *ring,void **result)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x10]
    xor    eax,eax
    mov    ax,WORD PTR [ecx+0xc]
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    lea    eax,[eax+eax*2]
    lea    eax,[edx+eax*4]
    mov    edx,DWORD PTR [eax]
    test    edx,edx
    mov    DWORD PTR [esi],edx
    jne    Branch66
    xor    al,al
    pop    esi
    ret    0x4
  Branch66:
    mov    DWORD PTR [eax],0x0
    mov    ax,WORD PTR [ecx+0xc]
    xor    esi,esi
    inc    ax
    mov    si,WORD PTR [ecx+0x6]
    and    eax,0xffff
    cdq
    idiv    esi
    mov    ax,WORD PTR [ecx+0xa]
    inc    ax
    and    eax,0xffff
    mov    WORD PTR [ecx+0xc],dx
    cdq
    idiv    esi
    mov    al,0x1
    pop    esi
    mov    WORD PTR [ecx+0xa],dx
    ret    0x4
  }
}

// Delete current old payload if nonnull, then reload original replacement argument; store zero4, new0, zero8 in
// native order.
// Preserve raw entry EAX when no old payload or deleting result otherwise; no local EH/rollback, RET4.
// R6GameService.dll @ 1005ee20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceOwnedRecordObject(void *record,uint replacementWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch67
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch67:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x8],0x0
    pop    esi
    ret    0x4
  }
}
