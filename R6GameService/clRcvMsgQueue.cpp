#include "native_addresses.h"
#include "native_records.h"

// clRcvMsgQueue: native primary10078244, recovered RTTI identity; full class layout unresolved.

// Optional offset table, clear head, allocate/self-link12-byte sentinel, then publish primary and clear WORD+c.
// Leave sentinel payload and other bytes untouched; allocation NULL is unchecked. Physical DWORD flag/RET4.
// R6GameService.dll @ 1005c760 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeCompactRecordList(void *owner,uint initializeSharedWord)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je     Branch1
    mov    DWORD PTR [esi+0x8],0x1007825c
  Branch1:
    push   0xc
    mov    DWORD PTR [esi+0x4],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clRcvMsgQueueVTable
    mov    WORD PTR [esi+0xc],0x0
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Capture first wrapper payload+8, clear it BEFORE CURRENT virtual erase14, then decrement CURRENT WORD+c modulo16.
// Return cached detached message; erase may change links/count, empty returns0. No local EH or NULL-wrapper guard.
// R6GameService.dll @ 1005ca10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RemoveFirstCompactRecord(void *owner)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,ecx
    push   edi
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch2
    mov    eax,DWORD PTR [eax]
    mov    ecx,DWORD PTR [eax+0x8]
    push   ecx
    mov    edi,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [ecx+0x8],0x0
    mov    ecx,esp
    mov    DWORD PTR [ecx],eax
    mov    edx,DWORD PTR [esi]
    lea    eax,[esp+0xc]
    mov    ecx,esi
    push   eax
    call   DWORD PTR [edx+0x14]
    dec    WORD PTR [esi+0xc]
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ecx
    ret
  Branch2:
    pop    edi
    xor    eax,eax
    pop    esi
    pop    ecx
    ret
  }
}

// Wrap original message in owning record12, capture CURRENT head anchor, append node12, recount current head into WORD+c.
// Physical constructor class/flags words retain allocator EAX/ECX upper bits. NULL wrapper is linked as NULL payload;
// NULL node faults unchecked. No own EH/ownership repair; normal return ALWAYS AL1 with final head-derived upper EAX.
// R6GameService.dll @ 1005c990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AttachCompactRecord(void *owner,uint message)
{
  __asm {
    push    ecx
    push    ebx
    push    esi
    push    0xc
    mov    ebx,ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    test    esi,esi
    je    Branch3
    mov    edx,DWORD PTR [esp+0x10]
    push    0x1
    push    edx
    push    0x0
    mov    al,BYTE PTR [edx+0xe]
    mov    cl,BYTE PTR [edx+0xc]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::InitializeCompactRecordHeader
    jmp    Branch4
  Branch3:
    xor    eax,eax
  Branch4:
    lea    esi,[ebx+0x4]
    lea    edx,[esp+0x10]
    push    edi
    push    edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],eax
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0xc]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    edi,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    esi,DWORD PTR [esi]
    xor    ecx,ecx
    pop    edi
    mov    eax,DWORD PTR [esi]
    cmp    eax,esi
    je    Branch6
  Branch5:
    mov    eax,DWORD PTR [eax]
    inc    ecx
    cmp    eax,esi
    jne    Branch5
  Branch6:
    mov    WORD PTR [ebx+0xc],cx
    pop    esi
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Allocate owning wrapper12, then capture CURRENT source argument; remove FIRST matching active entry.
// Insert after first preceding tuple and before next nonpreceding tuple, or append if none; signed key uses strict <.
// ENTRY ESP S: ownerS-c/wrapperS-8/nodeS-10; sourceS+8 becomes Boolean/iterator scratch.
// Preserve CURRENT key/head/virtual erase and modulo16 count updates; no local EH. AL1/owner upper, RET8.
// R6GameService.dll @ 1005c7b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InsertOrReplaceCompactRecord(void *owner,uint keyWord,void *source)
{
  __asm {
    sub    esp,0x14
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    esi,ecx
    push    0xc
    mov    DWORD PTR [esp+0x1c],esi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,DWORD PTR [esp+0x2c]
    test    eax,eax
    je    Branch7
    mov    ecx,DWORD PTR [esp+0x28]
    mov    dl,BYTE PTR [ebp+0xe]
    push    0x1
    push    ebp
    push    ecx
    mov    cl,BYTE PTR [ebp+0xc]
    push    edx
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeCompactRecordHeader
    jmp    Branch8
  Branch7:
    xor    eax,eax
  Branch8:
    mov    DWORD PTR [esp+0x1c],eax
    mov    al,BYTE PTR [ebp+0xe]
    mov    bl,al
    mov    BYTE PTR [esp+0x2c],0x0
    and    bl,0x1f
    test    al,0x20
    mov    eax,DWORD PTR [esi+0x4]
    seta    BYTE PTR [esp+0x13]
    add    esi,0x4
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    mov    DWORD PTR [esp+0x14],esi
    je    Branch12
  Branch9:
    mov    al,BYTE PTR [esp+0x2c]
    test    al,al
    jne    Branch12
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
    mov    dx,WORD PTR [esp+0x28]
    cmp    dx,WORD PTR [edi+0x6]
    mov    edi,DWORD PTR [esp+0x18]
    sete    dl
    and    cl,dl
    test    al,0x20
    seta    al
    test    al,cl
    je    Branch10
    push    ecx
    mov    ecx,edi
    mov    eax,esp
    mov    DWORD PTR [esp+0x30],esp
    mov    DWORD PTR [eax],esi
    mov    edx,DWORD PTR [edi]
    lea    eax,[esp+0x24]
    push    eax
    call    DWORD PTR [edx+0x14]
    mov    esi,DWORD PTR [eax]
    dec    WORD PTR [edi+0xc]
    mov    BYTE PTR [esp+0x2c],0x1
    jmp    Branch11
  Branch10:
    mov    esi,DWORD PTR [esi]
  Branch11:
    mov    ecx,DWORD PTR [edi+0x4]
    lea    eax,[edi+0x4]
    cmp    esi,ecx
    mov    DWORD PTR [esp+0x14],esi
    jne    Branch9
  Branch12:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    BYTE PTR [esp+0x12],0x0
    mov    BYTE PTR [esp+0x2c],0x0
    mov    eax,DWORD PTR [ecx+0x4]
    lea    edi,[ecx+0x4]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    mov    DWORD PTR [esp+0x14],ebp
    je    Branch17
  Branch13:
    mov    al,BYTE PTR [esp+0x2c]
    test    al,al
    jne    Branch18
    mov    esi,DWORD PTR [ebp+0x8]
    mov    cl,BYTE PTR [esi+0x5]
    mov    al,cl
    and    al,0x1f
    test    cl,0x20
    seta    dl
    cmp    bl,al
    seta    cl
    test    cl,cl
    jne    Branch14
    cmp    bl,al
    jne    Branch14
    mov    al,BYTE PTR [esp+0x13]
    cmp    al,dl
    seta    cl
    test    cl,cl
    jne    Branch14
    cmp    al,dl
    jne    Branch14
    mov    dx,WORD PTR [esp+0x28]
    cmp    dx,WORD PTR [esi+0x6]
    setg    cl
  Branch14:
    mov    al,BYTE PTR [esp+0x12]
    test    al,al
    je    Branch15
    test    cl,cl
    jne    Branch16
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::CopyFirstWord
    lea    ecx,[esp+0x1c]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x20]
    mov    BYTE PTR [esp+0x2c],0x1
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ebp,DWORD PTR [esp+0x14]
    jmp    Branch16
  Branch15:
    test    cl,cl
    je    Branch16
    mov    BYTE PTR [esp+0x12],0x1
  Branch16:
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [edi]
    cmp    ebp,eax
    mov    DWORD PTR [esp+0x14],ebp
    jne    Branch13
    mov    al,BYTE PTR [esp+0x2c]
    test    al,al
    jne    Branch18
  Branch17:
    lea    edx,[esp+0x28]
    mov    ecx,edi
    push    edx
    call    R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x1c]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
  Branch18:
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    inc    WORD PTR [eax+0xc]
    mov    al,0x1
    pop    ebx
    add    esp,0x14
    ret    0x8
  }
}

// Native virtual-table prefix: clRcvMsgQueueVTable
// R6GameService.dll data @ 10078244 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clRcvMsgQueueVTableRecord {
  R6GameServiceNative::Address DeleteEmbeddedPointerList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address DestroyFirstCallbackListEntry; // +0x08
  R6GameServiceNative::Address PopBackCallbackListEntry; // +0x0c
  R6GameServiceNative::Address EraseOwnedPayloadListRange; // +0x10
  R6GameServiceNative::Address EraseCallbackPointerListNode; // +0x14
};
const clRcvMsgQueueVTableRecord clRcvMsgQueueVTable = {
  R6GameServiceAddresses::DeleteEmbeddedPointerList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::DestroyFirstCallbackListEntry,
  R6GameServiceAddresses::PopBackCallbackListEntry,
  R6GameServiceAddresses::EraseOwnedPayloadListRange,
  R6GameServiceAddresses::EraseCallbackPointerListNode,
};
