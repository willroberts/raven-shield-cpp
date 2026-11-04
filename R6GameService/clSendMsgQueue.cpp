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

namespace {
// Inferred native scratch words and two live Boolean bytes; original argument words also become iterator scratch.
struct SendCompactInsertScratch {
  byte untouched[2];
  byte seenPreceding;
  byte active;
  uint current;
  uint savedOwner;
  uint wrapper;
  uint serializedSize;
  uint position;
};
}

// Serialize cached source into sizeS-8, own buffer through wrapper16; remove FIRST matching active entry.
// Insert after first preceding tuple and before next nonpreceding tuple, or append if none; signed key uses <=.
// ENTRY ESP S: ownerS-10/wrapperS-c/sizeS-8/nodeS-14; keyS+4 and sourceS+8 become iterator/Boolean scratch.
// Count WORD+c decrements after replacement and increments after insertion; no local EH/rollback. AL1/owner upper, RET8.
// R6GameService.dll @ 1005cb00 : inferred scratch view; current source/key, virtual erasure and slot reloads.
uint __thiscall InsertOrReplaceCompactPayloadRecord(void *owner,uint keyWord,void *source)
{
  uint cachedSource = (uint)source;
  uint initialOwner = (uint)owner;
  SendCompactInsertScratch scratch;
  uint sourceTable = *(uint *)cachedSource;
  using SerializeABI = uint (__thiscall *)(void *,uint *);
  scratch.savedOwner = initialOwner;
  uint bytes = (*(SerializeABI *)(sourceTable + 4))((void *)cachedSource,&scratch.serializedSize);
  using AllocateABI = uint (__stdcall *)(uint);
  uint allocated = ((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(16);
  uint wrapper = 0;
  if (allocated != 0) {
    uint size = scratch.serializedSize;
    uint key = keyWord;
    uint flagsWord = (size & 0xffffff00) | *(byte *)(cachedSource + 0xe);
    uint headerWord = (key & 0xffffff00) | *(byte *)(cachedSource + 0xc);
    using ConstructABI = uint (__thiscall *)(void *,uint,uint,uint,void *,uint,uint);
    wrapper = ((ConstructABI)R6GameServiceAddresses::InitializeCompactPayloadRecord)(
        (void *)allocated,headerWord,flagsWord,key,(void *)bytes,size,1);
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
        preceding = currentKey >= oldKey;
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

namespace {
// Inferred contiguous native scratch words at S-0x0c, S-8 and S-4; copying can overwrite their current contents.
struct CompactConcatScratch {
  uint selectedCount;
  uint savedOwner;
  uint allocation;
};

// Copy forward in DWORD/tail groups, caching the saved owner between the two native REP instructions.
inline uint CopyCompactPayloadForward(uint destination,uint source,uint count,const uint *savedOwnerSlot) {
  uint words = count >> 2;
  while (words != 0) {
    uint value = *(const uint *)source;
    *(uint *)destination = value;
    source += 4;
    destination += 4;
    --words;
  }
  uint owner = *savedOwnerSlot;
  uint tail = count & 3;
  while (tail != 0) {
    byte value = *(const byte *)source;
    *(byte *)destination = value;
    ++source;
    ++destination;
    --tail;
  }
  return owner;
}
}

// Select records while signed wrapped cumulative size<limit, accepting current record at zero total even when at/over limit.
// Allocate selected size, then rescan CURRENT list and copy using signed16 selected/counter comparison and live payload sizes.
// Original limit argument becomes copy counter; reload size after each copy and output pointer late. No local EH/NULL guard. RET8.
// R6GameService.dll @ 1005cda0 : inferred scratch view; wrapped sizes and live argument/scratch aliases retained.
void *__thiscall ConcatenateCompactPayloadsThroughLimit(void *owner,int byteLimit,int *copiedByteCount)
{
  CompactConcatScratch scratch;
  uint head = *(uint *)((uint)owner + 4);
  uint node = *(uint *)head;
  uint total = 0;
  uint selected = 0;
  bool stopped = false;
  scratch.savedOwner = (uint)owner;
  scratch.selectedCount = 0;
  if (node == head) {
    *copiedByteCount = 0;
    return nullptr;
  }
  do {
    if (stopped) break;
    uint wrapper = *(uint *)(node + 8);
    uint length = *(uint *)(wrapper + 0xc);
    uint combined = length + total;
    if ((int)combined < byteLimit) {
      total = combined;
      ++selected;
    } else {
      if (total == 0) {
        total = length;
        ++selected;
      }
      stopped = true;
    }
    node = *(uint *)node;
  } while (node != head);
  scratch.selectedCount = selected;
  if (total == 0) {
    *copiedByteCount = 0;
    return nullptr;
  }
  using AllocateABI = void * (__stdcall *)(uint);
  uint allocated = (uint)((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(total);
  uint sizingOwner = scratch.savedOwner;
  scratch.allocation = allocated;
  uint offset = 0;
  head = *(uint *)(sizingOwner + 4);
  byteLimit = 0;
  node = *(uint *)head;
  uint selectedForComparison = selected;
  while (node != head) {
    if ((short)(ushort)byteLimit >= (short)(ushort)selectedForComparison) break;
    uint wrapper = *(uint *)(node + 8);
    uint allocation = scratch.allocation;
    uint length = *(uint *)(wrapper + 0xc);
    uint first = *(uint *)(wrapper + 8);
    uint destination = offset + allocation;
    uint currentOwner = CopyCompactPayloadForward(destination,first,length,&scratch.savedOwner);
    wrapper = *(uint *)(node + 8);
    uint counter = (uint)byteLimit;
    uint next = *(uint *)node;
    uint currentLength = *(uint *)(wrapper + 0xc);
    uint currentHead = *(uint *)(currentOwner + 4);
    offset += currentLength;
    ++counter;
    byteLimit = (int)counter;
    node = next;
    if (node == currentHead) break;
    head = currentHead;
    selectedForComparison = scratch.selectedCount;
  }
  int *output = copiedByteCount;
  uint result = scratch.allocation;
  *output = (int)total;
  return (void *)result;
}

// Cache signed consumed count, accumulate wrapped current payload sizes and erase complete records through current slot14.
// Original consumed argument becomes next-iterator output; decrement CURRENT WORD+c after erase, retain current head stop.
// Overshoot keeps the same node until next signed cumulative gate; return current node upper24/AL1, RET4, no local EH.
// R6GameService.dll @ 1005ce90 : inferred iterator view; current virtual slot, output dereference and WORD decrement.
uint __thiscall DiscardConsumedCompactPayloads(void *owner,int consumedByteCount)
{
  uint base = (uint)owner;
  uint total = 0;
  uint head = *(uint *)(base + 4);
  uint node = *(uint *)head;
  if (node != head) {
    int limit = consumedByteCount;
    do {
      if ((int)total > limit) break;
      uint wrapper = *(uint *)(node + 8);
      total += *(uint *)(wrapper + 0xc);
      if ((int)total <= limit) {
        uint iterator = node;
        uint table = *(uint *)base;
        using EraseABI = uint * (__thiscall *)(void *,uint *,void *);
        EraseABI erase = *(EraseABI *)(table + 0x14);
        uint *returned = erase(owner,(uint *)&consumedByteCount,(void *)iterator);
        node = *returned;
        ushort count = *(ushort *)(base + 0xc);
        *(ushort *)(base + 0xc) = (ushort)(count - 1);
      }
      head = *(uint *)(base + 4);
    } while (node != head);
  }
  return (node & 0xffffff00) | 1;
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
