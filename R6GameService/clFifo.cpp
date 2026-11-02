#include "native_addresses.h"
#include "native_records.h"

// Native clFifo: table76c34/COL78e44/type8e334, base clPointerList<clMemoryElement*> at offset0.

// Constructs clFifo with an unchecked12-byte self-linked sentinel, count0 and limit7fffffff.
// Optional allocator table precedes allocation; primary table/count/limit publish only after the sentinel links.
// R6GameService.dll @ 1002ee40 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructCircularList(void *fifo,uint initializeBase)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je     Branch1
    mov    DWORD PTR [esi+0x8],0x10076c4c
  Branch1:
    push   0xc
    mov    DWORD PTR [esi+0x4],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clFifoVTable
    mov    DWORD PTR [esi+0xc],0x0
    mov    DWORD PTR [esi+0x10],0x7fffffff
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Invokes virtual clear first, then resets fifo count+c and returns AL1 with native upper EAX retained.
// R6GameService.dll @ 1002f190 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearBlockQueue(void *fifo)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi]
    call   DWORD PTR [eax+0x4]
    mov    DWORD PTR [esi+0xc],0x0
    mov    al,0x1
    pop    esi
    ret
  }
}

// Appends through the current tail, allocating unchecked0x800-byte payload blocks and12-byte nodes as needed.
// Signed count/limit and chunk comparisons, forward copies, late argument/index/count reloads and raw upper EAX survive.
// R6GameService.dll @ 1002ef40 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendBytesToBlockQueue(void *fifo,int source,uint byteCount)
{
  __asm {
    sub    esp,0xc
    push   ebp
    mov    ebp,ecx
    mov    DWORD PTR [esp+0xc],0x0
    mov    DWORD PTR [esp+0x4],ebp
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp+0x10]
    cmp    eax,ecx
    jle    Branch2
    xor    al,al
    pop    ebp
    add    esp,0xc
    ret    0x8
  Branch2:
    push   ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    test   ebx,ebx
    je     Branch9
    push   esi
    push   edi
    lea    edi,[ebp+0x4]
  Branch3:
    mov    eax,DWORD PTR [edi]
    mov    esi,DWORD PTR [esp+0x24]
    sub    esi,ebx
    cmp    DWORD PTR [eax],eax
    je     Branch5
    mov    ecx,eax
    mov    eax,0x800
    mov    edx,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [edx+0x8]
    mov    edi,DWORD PTR [edx+0x808]
    sub    eax,edi
    cmp    eax,ebx
    jle    Branch4
    mov    eax,ebx
  Branch4:
    mov    ebp,DWORD PTR [esp+0x20]
    mov    ecx,eax
    add    esi,ebp
    mov    ebp,ecx
    lea    edi,[edi+edx*1+0x4]
    sub    ebx,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    add    DWORD PTR [edx+0x808],eax
  Branch5:
    test   ebx,ebx
    je     Branch8
    push   0x80c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    xor    ecx,ecx
    cmp    eax,ecx
    je     Branch6
    mov    DWORD PTR [eax],0x10076c70
    mov    DWORD PTR [eax+0x804],ecx
    mov    DWORD PTR [eax+0x808],ecx
    jmp    Branch7
  Branch6:
    xor    eax,eax
  Branch7:
    mov    DWORD PTR [esp+0x14],eax
    lea    eax,[esp+0x18]
    lea    edi,[ebp+0x4]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0x14]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    jmp    Branch3
  Branch8:
    mov    ebx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
  Branch9:
    mov    eax,DWORD PTR [ebp+0xc]
    add    eax,ebx
    pop    ebx
    mov    DWORD PTR [ebp+0xc],eax
    mov    al,0x1
    pop    ebp
    add    esp,0xc
    ret    0x8
  }
}

// Copies/consumes up to the requested bytes and virtually erases exhausted first nodes.
// Signed count gate; an early empty list still succeeds. Count adjusts by consumed bytes; status replaces AL only.
// R6GameService.dll @ 1002f040 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConsumeBlockQueueBytes(void *fifo,uint byteCount,int destination)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esi+0xc]
    mov    DWORD PTR [esp+0x10],esi
    cmp    edi,eax
    jg     Branch14
    test   edi,edi
    mov    ebx,edi
    je     Branch13
  Branch10:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je     Branch13
    mov    ecx,DWORD PTR [eax]
    sub    edi,ebx
    mov    edx,DWORD PTR [ecx+0x8]
    mov    esi,DWORD PTR [edx+0x804]
    mov    eax,DWORD PTR [edx+0x808]
    sub    eax,esi
    cmp    eax,ebx
    jle    Branch11
    mov    eax,ebx
  Branch11:
    mov    ebp,DWORD PTR [esp+0x20]
    mov    ecx,eax
    add    edi,ebp
    mov    ebp,ecx
    lea    esi,[esi+edx*1+0x4]
    sub    ebx,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,ebp
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ebp,DWORD PTR [edx+0x804]
    mov    esi,DWORD PTR [esp+0x10]
    add    ebp,eax
    mov    DWORD PTR [edx+0x804],ebp
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edx+0x8]
    mov    edx,DWORD PTR [eax+0x804]
    mov    edi,DWORD PTR [eax+0x808]
    cmp    edx,edi
    jne    Branch12
    push   ecx
    mov    ecx,DWORD PTR [ecx]
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR [esi]
    lea    eax,[esp+0x18]
    mov    ecx,esi
    push   eax
    call   DWORD PTR [edx+0x14]
  Branch12:
    mov    edi,DWORD PTR [esp+0x1c]
    test   ebx,ebx
    jne    Branch10
  Branch13:
    mov    eax,DWORD PTR [esi+0xc]
    sub    ebx,edi
    add    eax,ebx
    mov    DWORD PTR [esi+0xc],eax
    mov    al,0x1
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch14:
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Copies the available prefix without consuming it; returns clean EAX1 only when all requested bytes were copied.
// Forward DWORD/tail copies retain late original arguments, next-link and current-head reloads.
// R6GameService.dll @ 1002f120 : native control/access order and raw ABI retained.
__declspec(naked) bool __thiscall CopyBlockQueuePrefix(void *fifo,uint byteCount,int destination)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [ecx+0x4]
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   ebp
    mov    edx,DWORD PTR [eax]
    push   esi
    cmp    edx,eax
    push   edi
    mov    DWORD PTR [esp+0x10],ecx
    je     Branch17
  Branch15:
    test   ebx,ebx
    je     Branch17
    mov    esi,DWORD PTR [edx+0x8]
    mov    edi,DWORD PTR [esp+0x18]
    sub    edi,ebx
    mov    ebp,DWORD PTR [esi+0x804]
    mov    eax,DWORD PTR [esi+0x808]
    sub    eax,ebp
    cmp    eax,ebx
    jle    Branch16
    mov    eax,ebx
  Branch16:
    lea    esi,[esi+ebp*1+0x4]
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    ecx,eax
    add    edi,ebp
    mov    ebp,ecx
    sub    ebx,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,ebp
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edx,DWORD PTR [edx]
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    edx,ecx
    jne    Branch15
  Branch17:
    xor    eax,eax
    pop    edi
    test   ebx,ebx
    pop    esi
    pop    ebp
    sete   al
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Native virtual-table prefix: clFifoVTable
// R6GameService.dll data @ 10076c34 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clFifoVTableRecord {
  R6GameServiceNative::Address DeleteCircularList; // +0x00
  R6GameServiceNative::Address InvokePointerListClearRange; // +0x04
  R6GameServiceNative::Address RemoveFirstBlockFromQueue; // +0x08
  R6GameServiceNative::Address RemoveLastBlockFromQueue; // +0x0c
  R6GameServiceNative::Address EraseOwningPointerListRange; // +0x10
  R6GameServiceNative::Address EraseOwningPointerListNode; // +0x14
};
const clFifoVTableRecord clFifoVTable = {
  R6GameServiceAddresses::DeleteCircularList,
  R6GameServiceAddresses::InvokePointerListClearRange,
  R6GameServiceAddresses::RemoveFirstBlockFromQueue,
  R6GameServiceAddresses::RemoveLastBlockFromQueue,
  R6GameServiceAddresses::EraseOwningPointerListRange,
  R6GameServiceAddresses::EraseOwningPointerListNode,
};
