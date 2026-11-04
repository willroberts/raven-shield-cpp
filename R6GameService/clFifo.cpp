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

namespace {
// Copy forward in native DWORD/tail order, retaining overlap effects and wrapped PE32 cursor arithmetic.
inline void CopyFifoBytesForward(uint destination,uint source,uint count) {
  uint words = count >> 2;
  while (words != 0) {
    uint value = *(const uint *)source;
    *(uint *)destination = value;
    source += 4;
    destination += 4;
    --words;
  }
  uint tail = count & 3;
  while (tail != 0) {
    byte value = *(const byte *)source;
    *(byte *)destination = value;
    ++source;
    ++destination;
    --tail;
  }
}
}

// Clear through the current virtual slot, then reset the byte count and replace only the callback result's low byte.
// R6GameService.dll @ 1002f190 : callback exceptions leave the old count intact.
uint __fastcall ClearBlockQueue(void *fifo)
{
  using ClearABI = uint (__thiscall *)(void *);
  byte *table = *(byte **)fifo;
  uint result = (*(ClearABI *)(table + 4))(fifo);
  *(uint *)((byte *)fifo + 0xc) = 0;
  return (result & 0xffffff00) | 1;
}

// Fill the current tail and append borrowed-payload nodes as needed; preserve signed limits and late argument reloads.
// R6GameService.dll @ 1002ef40 : inferred block indices +0x804/+0x808; count publication follows all copies.
uint __thiscall AppendBytesToBlockQueue(void *fifo,int source,uint byteCount)
{
  uint count = *(uint *)((byte *)fifo + 0xc);
  uint limit = *(uint *)((byte *)fifo + 0x10);
  if ((int)count > (int)limit) return count & 0xffffff00;
  uint remaining = byteCount;
  if (remaining != 0) {
    for (;;) {
      uint head = *(uint *)((byte *)fifo + 4);
      uint offset = byteCount - remaining;
      if (*(uint *)head != head) {
        uint last = *(uint *)(head + 4);
        uint block = *(uint *)(last + 8);
        uint writeIndex = *(uint *)(block + 0x808);
        uint chunk = 0x800 - writeIndex;
        if ((int)chunk > (int)remaining) chunk = remaining;
        uint first = (uint)source + offset;
        uint destination = block + writeIndex + 4;
        remaining -= chunk;
        CopyFifoBytesForward(destination,first,chunk);
        *(uint *)(block + 0x808) += chunk;
      }
      if (remaining == 0) {
        remaining = byteCount;
        break;
      }
      uint block = (uint)AllocateGameServiceBytes(0x80c);
      if (block != 0) {
        *(uint *)block = 0x10076c70;
        *(uint *)(block + 0x804) = 0;
        *(uint *)(block + 0x808) = 0;
      }
      using HeadABI = uint * (__thiscall *)(void *,uint *);
      using AllocateNodeABI = void * (__stdcall *)(uint *);
      void *headSlot = (byte *)fifo + 4;
      uint position;
      ((HeadABI)R6GameServiceAddresses::CopyListHeadSlot)(headSlot,&position);
      uint node = (uint)((AllocateNodeABI)R6GameServiceAddresses::AllocateListPayloadNode)(&block);
      uint next = position;
      uint previous = *(uint *)(next + 4);
      *(uint *)node = next;
      *(uint *)(node + 4) = previous;
      *(uint *)previous = node;
      *(uint *)(next + 4) = node;
    }
  }
  uint updated = *(uint *)((byte *)fifo + 0xc) + remaining;
  *(uint *)((byte *)fifo + 0xc) = updated;
  return (updated & 0xffffff00) | 1;
}

// Copy and consume available blocks, virtually erase exhausted nodes and subtract only the bytes physically consumed.
// R6GameService.dll @ 1002f040 : signed admission gate; an unexpectedly empty list still returns low-byte success.
uint __thiscall ConsumeBlockQueueBytes(void *fifo,uint byteCount,int destination)
{
  uint requested = byteCount;
  uint count = *(uint *)((byte *)fifo + 0xc);
  if ((int)requested > (int)count) return count & 0xffffff00;
  uint remaining = requested;
  if (remaining != 0) {
    for (;;) {
      uint head = *(uint *)((byte *)fifo + 4);
      if (*(uint *)head == head) break;
      uint firstNode = *(uint *)head;
      uint offset = requested - remaining;
      uint block = *(uint *)(firstNode + 8);
      uint readIndex = *(uint *)(block + 0x804);
      uint chunk = *(uint *)(block + 0x808) - readIndex;
      if ((int)chunk > (int)remaining) chunk = remaining;
      uint target = (uint)destination + offset;
      uint first = block + readIndex + 4;
      remaining -= chunk;
      CopyFifoBytesForward(target,first,chunk);
      uint newReadIndex = *(uint *)(block + 0x804) + chunk;
      *(uint *)(block + 0x804) = newReadIndex;
      head = *(uint *)((byte *)fifo + 4);
      firstNode = *(uint *)head;
      block = *(uint *)(firstNode + 8);
      readIndex = *(uint *)(block + 0x804);
      uint writeIndex = *(uint *)(block + 0x808);
      if (readIndex == writeIndex) {
        uint node = *(uint *)head;
        byte *table = *(byte **)fifo;
        uint next;
        using EraseABI = uint * (__thiscall *)(void *,uint *,uint);
        (*(EraseABI *)(table + 0x14))(fifo,&next,node);
      }
      requested = byteCount;
      if (remaining == 0) break;
    }
  }
  uint countBeforeUpdate = *(uint *)((byte *)fifo + 0xc);
  uint adjustment = remaining - requested;
  uint updated = countBeforeUpdate + adjustment;
  *(uint *)((byte *)fifo + 0xc) = updated;
  return (updated & 0xffffff00) | 1;
}

// Copy the available prefix without consuming it; the return is true only if every requested byte was copied.
// R6GameService.dll @ 1002f120 : forward DWORD/tail copies, signed chunk selection and live next/head reloads.
bool __thiscall CopyBlockQueuePrefix(void *fifo,uint byteCount,int destination)
{
  uint head = *(uint *)((byte *)fifo + 4);
  uint remaining = byteCount;
  uint node = *(uint *)head;
  while (node != head && remaining != 0) {
    uint block = *(uint *)(node + 8);
    uint offset = byteCount - remaining;
    uint readIndex = *(uint *)(block + 0x804);
    uint chunk = *(uint *)(block + 0x808) - readIndex;
    if ((int)chunk > (int)remaining) chunk = remaining;
    uint first = block + readIndex + 4;
    uint target = (uint)destination + offset;
    remaining -= chunk;
    CopyFifoBytesForward(target,first,chunk);
    node = *(uint *)node;
    head = *(uint *)((byte *)fifo + 4);
  }
  return remaining == 0;
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
