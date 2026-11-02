#include "native_addresses.h"
#include "native_records.h"

// clSendMsgQueue: native primary10078270, recovered RTTI identity; full class layout unresolved.

// Optional offset table, clear head, allocate/self-link12-byte sentinel, then publish primary and clear WORD+c.
// Leave sentinel payload and other bytes untouched; allocation NULL is unchecked. Physical DWORD flag/RET4.
// R6GameService.dll @ 1005cab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clSendMsgQueue_InitializeCompactRecordList(void *owner,uint initializeSharedWord)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je     Branch1
    mov    DWORD PTR [esi+0x8],0x10078288
  Branch1:
    push   0xc
    mov    DWORD PTR [esi+0x4],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSendMsgQueueVTable
    mov    WORD PTR [esi+0xc],0x0
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Serialize cached source into sizeS-8, own buffer through wrapper16; remove FIRST matching active entry.
// Insert after first preceding tuple and before next nonpreceding tuple, or append if none; signed key uses <=.
// ENTRY ESP S: ownerS-10/wrapperS-c/sizeS-8/nodeS-14; keyS+4 and sourceS+8 become iterator/Boolean scratch.
// Count WORD+c decrements after replacement and increments after insertion; no local EH/rollback. AL1/owner upper, RET8.
// R6GameService.dll @ 1005cb00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InsertOrReplaceCompactPayloadRecord(void *owner,uint keyWord,void *source)
{
  __asm {
    sub    esp,0x18
    push    ebx
    push    ebp
    mov    ebp,DWORD PTR [esp+0x28]
    push    esi
    push    edi
    mov    edi,ecx
    mov    eax,DWORD PTR [ebp+0x0]
    lea    ecx,[esp+0x20]
    push    ecx
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x1c],edi
    call    DWORD PTR [eax+0x4]
    push    0x10
    mov    esi,eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    test    eax,eax
    je    Branch2
    mov    edx,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x2c]
    push    0x1
    push    edx
    mov    dl,BYTE PTR [ebp+0xe]
    push    esi
    push    ecx
    mov    cl,BYTE PTR [ebp+0xc]
    push    edx
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeCompactPayloadRecord
    jmp    Branch3
  Branch2:
    xor    eax,eax
  Branch3:
    mov    DWORD PTR [esp+0x1c],eax
    mov    al,BYTE PTR [ebp+0xe]
    mov    bl,al
    mov    BYTE PTR [esp+0x30],0x0
    and    bl,0x1f
    test    al,0x20
    mov    eax,DWORD PTR [edi+0x4]
    seta    BYTE PTR [esp+0x13]
    mov    esi,DWORD PTR [eax]
    add    edi,0x4
    cmp    esi,eax
    mov    DWORD PTR [esp+0x14],esi
    je    Branch7
  Branch4:
    mov    al,BYTE PTR [esp+0x30]
    test    al,al
    jne    Branch7
    mov    edi,DWORD PTR [esi+0x8]
    mov    dl,BYTE PTR [ebp+0xc]
    mov    cl,BYTE PTR [edi+0x4]
    mov    al,BYTE PTR [edi+0x5]
    cmp    dl,cl
    mov    dl,al
    sete    cl
    and    dl,0x1f
    cmp    bl,dl
    sete    dl
    and    cl,dl
    mov    dx,WORD PTR [esp+0x2c]
    cmp    dx,WORD PTR [edi+0x6]
    mov    edi,DWORD PTR [esp+0x18]
    sete    dl
    and    cl,dl
    test    al,0x20
    seta    al
    test    al,cl
    je    Branch5
    push    ecx
    mov    ecx,edi
    mov    eax,esp
    mov    DWORD PTR [esp+0x34],esp
    mov    DWORD PTR [eax],esi
    mov    edx,DWORD PTR [edi]
    lea    eax,[esp+0x28]
    push    eax
    call    DWORD PTR [edx+0x14]
    mov    esi,DWORD PTR [eax]
    dec    WORD PTR [edi+0xc]
    mov    BYTE PTR [esp+0x30],0x1
    jmp    Branch6
  Branch5:
    mov    esi,DWORD PTR [esi]
  Branch6:
    mov    ecx,DWORD PTR [edi+0x4]
    lea    eax,[edi+0x4]
    cmp    esi,ecx
    mov    DWORD PTR [esp+0x14],esi
    jne    Branch4
  Branch7:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    BYTE PTR [esp+0x12],0x0
    mov    BYTE PTR [esp+0x30],0x0
    mov    eax,DWORD PTR [ecx+0x4]
    lea    edi,[ecx+0x4]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    mov    DWORD PTR [esp+0x14],ebp
    je    Branch13
  Branch8:
    mov    al,BYTE PTR [esp+0x30]
    test    al,al
    jne    Branch14
    mov    esi,DWORD PTR [ebp+0x8]
    mov    cl,BYTE PTR [esi+0x5]
    mov    al,cl
    and    al,0x1f
    test    cl,0x20
    seta    dl
    cmp    bl,al
    seta    cl
    test    cl,cl
    jne    Branch9
    cmp    bl,al
    jne    Branch9
    mov    al,BYTE PTR [esp+0x13]
    cmp    al,dl
    seta    cl
    test    cl,cl
    jne    Branch9
    cmp    al,dl
    jne    Branch9
    mov    dx,WORD PTR [esp+0x2c]
    cmp    dx,WORD PTR [esi+0x6]
    setge    cl
  Branch9:
    mov    al,BYTE PTR [esp+0x12]
    test    al,al
    je    Branch10
    test    cl,cl
    jne    Branch11
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x24]
    push    eax
    call    R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x1c]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x24]
    mov    BYTE PTR [esp+0x30],0x1
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ebp,DWORD PTR [esp+0x14]
    jmp    Branch12
  Branch10:
    test    cl,cl
    je    Branch12
  Branch11:
    mov    BYTE PTR [esp+0x12],0x1
  Branch12:
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [edi]
    cmp    ebp,eax
    mov    DWORD PTR [esp+0x14],ebp
    jne    Branch8
    mov    al,BYTE PTR [esp+0x30]
    test    al,al
    jne    Branch14
  Branch13:
    lea    edx,[esp+0x2c]
    mov    ecx,edi
    push    edx
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x1c]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch14:
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    inc    WORD PTR [eax+0xc]
    mov    al,0x1
    pop    ebx
    add    esp,0x18
    ret    0x8
  }
}

// Serialize cached source through slot4 into original argumentS+4, then build wrapper16 owning returned bytes/count.
// Append a node even if wrapper malloc returned NULL; recount CURRENT list into WORD+c and return head upper24/AL1, RET4.
// Preserve late source header bytes, cached insertion sentinel/current neighbor reads and no local EH or rollback.
// R6GameService.dll @ 1005cd00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendCompactPayloadRecord(void *owner,void *source)
{
  __asm {
    sub    esp,0x8
    push    ebx
    push    esi
    mov    esi,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    lea    ecx,[esp+0x14]
    push    edi
    mov    eax,DWORD PTR [esi]
    push    ecx
    mov    ecx,esi
    call    DWORD PTR [eax+0x4]
    push    0x10
    mov    edi,eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    test    eax,eax
    je    Branch15
    mov    edx,DWORD PTR [esp+0x18]
    mov    cl,BYTE PTR [esi+0xe]
    push    0x1
    push    edx
    mov    dl,BYTE PTR [esi+0xc]
    push    edi
    push    0x0
    push    ecx
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeCompactPayloadRecord
    jmp    Branch16
  Branch15:
    xor    eax,eax
  Branch16:
    mov    DWORD PTR [esp+0xc],eax
    lea    esi,[ebx+0x4]
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0xc]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    edi,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    esi,DWORD PTR [esi]
    xor    ecx,ecx
    mov    eax,DWORD PTR [esi]
    cmp    eax,esi
    je    Branch18
  Branch17:
    mov    eax,DWORD PTR [eax]
    inc    ecx
    cmp    eax,esi
    jne    Branch17
  Branch18:
    pop    edi
    mov    WORD PTR [ebx+0xc],cx
    pop    esi
    mov    al,0x1
    pop    ebx
    add    esp,0x8
    ret    0x4
  }
}

// Select records while signed wrapped cumulative size<limit, accepting current record at zero total even when at/over limit.
// Allocate selected size, then rescan CURRENT list and copy using signed16 selected/counter comparison and live payload sizes.
// Original limit argument becomes copy counter; reload size after each copy and output pointer late. No local EH/NULL guard. RET8.
// R6GameService.dll @ 1005cda0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConcatenateCompactPayloadsThroughLimit(
    void *owner,int byteLimit,int *copiedByteCount)
{
  __asm {
    sub    esp,0xc
    push    ebx
    mov    ebx,DWORD PTR [ecx+0x4]
    push    ebp
    push    esi
    mov    edx,DWORD PTR [ebx]
    push    edi
    xor    ebp,ebp
    xor    edi,edi
    xor    al,al
    cmp    edx,ebx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x10],edi
    je    Branch27
  Branch19:
    test    al,al
    jne    Branch23
    mov    ecx,DWORD PTR [edx+0x8]
    mov    esi,DWORD PTR [ecx+0xc]
    lea    ecx,[esi+ebp*1]
    cmp    ecx,DWORD PTR [esp+0x20]
    jl    Branch21
    test    ebp,ebp
    jne    Branch20
    mov    ebp,esi
    inc    edi
  Branch20:
    mov    al,0x1
    jmp    Branch22
  Branch21:
    mov    ebp,ecx
    inc    edi
  Branch22:
    mov    edx,DWORD PTR [edx]
    cmp    edx,ebx
    jne    Branch19
  Branch23:
    test    ebp,ebp
    mov    DWORD PTR [esp+0x10],edi
    je    Branch27
    push    ebp
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x18],eax
    xor    ebx,ebx
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esp+0x20],ebx
    mov    edx,DWORD PTR [eax]
    cmp    edx,eax
    je    Branch26
    jmp    Branch25
  Branch24:
    mov    edi,DWORD PTR [esp+0x10]
  Branch25:
    cmp    WORD PTR [esp+0x20],di
    jge    Branch26
    mov    esi,DWORD PTR [edx+0x8]
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esi+0xc]
    mov    esi,DWORD PTR [esi+0x8]
    lea    edi,[ebx+eax*1]
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    mov    eax,DWORD PTR [esp+0x14]
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [edx+0x8]
    mov    esi,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [edx]
    mov    edi,DWORD PTR [ecx+0xc]
    mov    ecx,DWORD PTR [eax+0x4]
    add    ebx,edi
    inc    esi
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x20],esi
    jne    Branch24
  Branch26:
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    mov    DWORD PTR [ecx],ebp
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch27:
    mov    edx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [edx],0x0
    xor    eax,eax
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// Cache signed consumed count, accumulate wrapped current payload sizes and erase complete records through current slot14.
// Original consumed argument becomes next-iterator output; decrement CURRENT WORD+c after erase, retain current head stop.
// Overshoot keeps the same node until next signed cumulative gate; return current node upper24/AL1, RET4, no local EH.
// R6GameService.dll @ 1005ce90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DiscardConsumedCompactPayloads(void *owner,int consumedByteCount)
{
  __asm {
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    xor    edi,edi
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je    Branch30
    mov    ebx,DWORD PTR [esp+0x10]
  Branch28:
    cmp    edi,ebx
    jg    Branch30
    mov    ecx,DWORD PTR [eax+0x8]
    add    edi,DWORD PTR [ecx+0xc]
    cmp    edi,ebx
    jg    Branch29
    push    ecx
    mov    ecx,esp
    mov    DWORD PTR [ecx],eax
    mov    edx,DWORD PTR [esi]
    lea    eax,[esp+0x14]
    mov    ecx,esi
    push    eax
    call    DWORD PTR [edx+0x14]
    mov    eax,DWORD PTR [eax]
    dec    WORD PTR [esi+0xc]
  Branch29:
    cmp    eax,DWORD PTR [esi+0x4]
    jne    Branch28
  Branch30:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x4
  }
}

// Native virtual-table prefix: clSendMsgQueueVTable
// R6GameService.dll data @ 10078270 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSendMsgQueueVTableRecord {
  R6GameServiceNative::Address DeleteCompactPointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstListEntryAndBuffer; // +0x08
  R6GameServiceNative::Address PopLastBufferedPayload; // +0x0c
  R6GameServiceNative::Address ReleaseListNodesInRange; // +0x10
  R6GameServiceNative::Address EraseCompactBufferNode; // +0x14
};
const clSendMsgQueueVTableRecord clSendMsgQueueVTable = {
  R6GameServiceAddresses::DeleteCompactPointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstListEntryAndBuffer,
  R6GameServiceAddresses::PopLastBufferedPayload,
  R6GameServiceAddresses::ReleaseListNodesInRange,
  R6GameServiceAddresses::EraseCompactBufferNode,
};
