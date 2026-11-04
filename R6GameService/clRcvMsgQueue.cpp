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

namespace {
// Inferred native scratch words and two live Boolean bytes; original argument words also become iterator scratch.
struct ReceiveCompactInsertScratch {
  byte untouched[2];
  byte seenPreceding;
  byte active;
  uint current;
  uint savedOwner;
  uint wrapper;
  uint position;
};
}

// Allocate owning wrapper12, then capture CURRENT source argument; remove FIRST matching active entry.
// Insert after first preceding tuple and before next nonpreceding tuple, or append if none; signed key uses strict <.
// ENTRY ESP S: ownerS-c/wrapperS-8/nodeS-10; sourceS+8 becomes Boolean/iterator scratch.
// Preserve CURRENT key/head/virtual erase and modulo16 count updates; no local EH. AL1/owner upper, RET8.
// R6GameService.dll @ 1005c7b0 : inferred scratch view; current source/key, virtual erasure and slot reloads.
uint __thiscall InsertOrReplaceCompactRecord(void *owner,uint keyWord,void *source)
{
  uint initialOwner = (uint)owner;
  ReceiveCompactInsertScratch scratch;
  scratch.savedOwner = initialOwner;
  using AllocateABI = uint (__stdcall *)(uint);
  uint allocated = ((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(12);
  uint cachedSource = (uint)source;
  uint wrapper = 0;
  if (allocated != 0) {
    uint key = keyWord;
    byte flags = *(byte *)(cachedSource + 0xe);
    uint headerWord = (key & 0xffffff00) | *(byte *)(cachedSource + 0xc);
    // The initializer consumes only the flags BYTE; the allocator's upper EDX residue is unused.
    using ConstructABI = uint (__thiscall *)(void *,uint,byte,uint,void *,uint);
    wrapper = ((ConstructABI)R6GameServiceAddresses::InitializeCompactRecordHeader)(
        (void *)allocated,headerWord,flags,key,(void *)cachedSource,1);
  }
  scratch.wrapper = wrapper;
  byte incomingFlags = *(byte *)(cachedSource + 0xe);
  *(byte *)&source = 0;
  byte priority = incomingFlags & 0x1f;
  uint head = *(uint *)(initialOwner + 4);
  scratch.active = (incomingFlags & 0x20) != 0;
  uint current = *(uint *)head;
  scratch.current = current;
  while (current != head) {
    if (*(byte *)&source != 0) break;
    uint oldWrapper = *(uint *)(current + 8);
    byte wantedClass = *(byte *)(cachedSource + 0xc);
    byte oldClass = *(byte *)(oldWrapper + 4);
    byte oldFlags = *(byte *)(oldWrapper + 5);
    bool matches = wantedClass == oldClass;
    byte oldPriority = oldFlags & 0x1f;
    matches &= priority == oldPriority;
    ushort currentKey = *(ushort *)&keyWord;
    ushort oldKey = *(ushort *)(oldWrapper + 6);
    uint listOwner = scratch.savedOwner;
    matches &= currentKey == oldKey;
    bool oldActive = (oldFlags & 0x20) != 0;
    if (oldActive && matches) {
      uint iterator = current;
      source = &iterator;
      uint table = *(uint *)listOwner;
      using EraseABI = uint * (__thiscall *)(void *,uint *,void *);
      EraseABI erase = *(EraseABI *)(table + 0x14);
      uint *returned = erase((void *)listOwner,&scratch.position,(void *)iterator);
      current = *returned;
      ushort count = *(ushort *)(listOwner + 0xc);
      *(ushort *)(listOwner + 0xc) = (ushort)(count - 1);
      *(byte *)&source = 1;
    } else {
      current = *(uint *)current;
    }
    head = *(uint *)(listOwner + 4);
    scratch.current = current;
  }
  uint listOwner = scratch.savedOwner;
  scratch.seenPreceding = 0;
  *(byte *)&source = 0;
  head = *(uint *)(listOwner + 4);
  uint *headSlot = (uint *)(listOwner + 4);
  current = *(uint *)head;
  scratch.current = current;
  using CopyABI = uint * (__thiscall *)(uint *,const uint *);
  using AllocateNodeABI = uint (__thiscall *)(void *,const uint *);
  while (current != head) {
    if (*(byte *)&source != 0) break;
    uint oldWrapper = *(uint *)(current + 8);
    byte oldFlags = *(byte *)(oldWrapper + 5);
    byte oldPriority = oldFlags & 0x1f;
    byte oldActive = (oldFlags & 0x20) != 0;
    bool preceding = priority > oldPriority;
    if (!preceding && priority == oldPriority) {
      byte active = scratch.active;
      preceding = active > oldActive;
      if (!preceding && active == oldActive) {
        short currentKey = *(short *)&keyWord;
        short oldKey = *(short *)(oldWrapper + 6);
        preceding = currentKey > oldKey;
      }
    }
    byte seenPreceding = scratch.seenPreceding;
    if (seenPreceding != 0) {
      if (!preceding) {
        ((CopyABI)R6GameServiceAddresses::CopyFirstWord)(&scratch.position,&scratch.current);
        uint node = ((AllocateNodeABI)R6GameServiceAddresses::AllocateListPayloadNode)(headSlot,&scratch.wrapper);
        uint position = scratch.position;
        *(byte *)&source = 1;
        uint previous = *(uint *)(position + 4);
        *(uint *)node = position;
        *(uint *)(node + 4) = previous;
        *(uint *)previous = node;
        *(uint *)(position + 4) = node;
        current = scratch.current;
      } else {
        scratch.seenPreceding = 1;
      }
    } else if (preceding) {
      scratch.seenPreceding = 1;
    }
    current = *(uint *)current;
    head = *headSlot;
    scratch.current = current;
  }
  if (*(byte *)&source == 0) {
    using HeadABI = uint * (__thiscall *)(void *,uint *);
    ((HeadABI)R6GameServiceAddresses::CopyListHeadSlot)(headSlot,&keyWord);
    uint node = ((AllocateNodeABI)R6GameServiceAddresses::AllocateListPayloadNode)(headSlot,&scratch.wrapper);
    uint position = keyWord;
    uint previous = *(uint *)(position + 4);
    *(uint *)node = position;
    *(uint *)(node + 4) = previous;
    *(uint *)previous = node;
    *(uint *)(position + 4) = node;
  }
  uint result = scratch.savedOwner;
  ushort count = *(ushort *)(result + 0xc);
  *(ushort *)(result + 0xc) = (ushort)(count + 1);
  return (result & 0xffffff00) | 1;
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
