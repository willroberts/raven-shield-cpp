#include "native_addresses.h"
#include "descriptor_fields.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ffd0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ByteStringReserveExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080014 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo StringIndentExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080124 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo TaggedStringParseExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080168 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo TaggedByteBlockParseExceptionHandlerFunctionInfo;


// Appends a byte range using an end-pointer-derived local tag, ignoring the caller's third stack word.
// R6GameService.dll @ 1002b070 : ECX destination, begin/end/unused-tag stack words, RET 0xc; EAX=destination.
void * __thiscall AppendByteRangeWithLocalTag(
    void *destination,undefined1 *begin,undefined1 *end,const void *unusedTag)
{
  undefined1 localTag = (byte)(uint)end;
  return AppendByteRangePreservingNul(destination,begin,end,&localTag);
}

// Appends a half-open byte range and NUL, growing by max(old length, appended length)+old length+1 when needed.
// R6GameService.dll @ 1002b280 : ECX three-pointer string, begin/end/unused-tag stack words, RET 0xc.
void * __thiscall AppendByteRangePreservingNul(
    void *destination,undefined1 *begin,undefined1 *end,undefined1 *unusedTag)
{
  if (begin == end) return destination;
  auto *triplet = reinterpret_cast<R6GameServiceNative::ByteRange *>(destination);
  uint oldLength = triplet->end - triplet->begin;
  uint appendedBytes = (uint)end - (uint)begin;
  if (appendedBytes > 0xfffffffe || oldLength > 0xfffffffe - appendedBytes) {
    ThrowByteStringLengthError(s_basic_string);
  }
  uint requiredLength = oldLength + appendedBytes;
  uint capacityWithoutNul = triplet->capacityEnd - triplet->begin - 1;
  if (requiredLength > capacityWithoutNul) {
    uint largerLength = oldLength < appendedBytes ? appendedBytes : oldLength;
    uint allocationBytes = largerLength + oldLength + 1;
    void *replacement = AllocateGameServiceBytes(allocationBytes);
    void *appendAt = MoveByteRange((void *)triplet->begin,(void *)triplet->end,replacement);
    uint copiedRange = (uint)memmove(appendAt,begin,appendedBytes);
    uint newEnd = copiedRange + appendedBytes;
    *(byte *)newEnd = 0;
    TailFreeThroughGlobalAllocator((void *)triplet->begin);
    triplet->begin = (uint)replacement;
    triplet->end = newEnd;
    triplet->capacityEnd = (uint)replacement + allocationBytes;
    return destination;
  }
  undefined1 *sourceRest = (undefined1 *)((uint)begin + 1);
  if (end != sourceRest) {
    memmove((void *)(triplet->end + 1),sourceRest,(uint)end - (uint)sourceRest);
  }
  *(byte *)(triplet->end + appendedBytes) = 0;
  *(byte *)triplet->end = *begin;
  triplet->end += appendedBytes;
  return destination;
}

// Returns the descriptor's end-minus-begin byte count, shared by binary and string vtables.
// R6GameService.dll @ 1002ac40 : ECX descriptor; EAX=[ECX+10]-[ECX+c], plain RET.
uint __fastcall GetDescriptorByteCount(void *descriptor)
{
  auto *bytes = reinterpret_cast<R6GameServiceNative::ByteRange *>(static_cast<byte *>(descriptor) + 0x0c);
  return bytes->end - bytes->begin;
}

// Tail-forwards to the receiver's virtual slot +4, preserving its native argument and result registers.
// R6GameService.dll @ 1002aea0 : ECX receiver, two forwarded stack words; EAX loaded with its vtable before the jump.
__declspec(naked) uint __thiscall ForwardToDescriptorSlot04(
    void *descriptor,uint stackWord0,uint stackWord1)
{
  __asm {
    mov    eax,dword ptr [ecx]
    jmp    dword ptr [eax+4]
  }
}

// Appends a range and NUL, growing by occupied+max(occupied,added)+1 or copying the first byte after the tail.
// R6GameService.dll @ 10018560 : ECX triplet, three stack words; cached lengths and scratch aliases are inferred.
void * __thiscall AppendByteRangeWithGrowth(void *triplet,void *first,void *last,uint unusedTag)
{
  uint sourceEnd = (uint)last;
  auto *owner = (R6GameServiceNative::ByteRange *)triplet;
  uint sourceBegin = (uint)first;
  if (sourceBegin == sourceEnd) return owner;
  uint oldEnd = owner->end;
  uint oldBegin = owner->begin;
  uint occupiedBytes = oldEnd - oldBegin;
  uint addedBytes = sourceEnd - sourceBegin;
  uint savedOccupiedBytes = occupiedBytes;
  if (addedBytes > 0xfffffffeu || occupiedBytes > 0xfffffffeu - addedBytes) {
    ThrowByteStringLengthError(s_basic_string);
    sourceBegin = (uint)first;
  }
  uint capacityWithoutNul = owner->capacityEnd - owner->begin - 1;
  uint requiredBytes = occupiedBytes + addedBytes;
  if (requiredBytes > capacityWithoutNul) {
    last = (void *)addedBytes;
    uint *growth = occupiedBytes < addedBytes ? (uint *)&last : &savedOccupiedBytes;
    uint allocationBytes = *growth + occupiedBytes + 1;
    uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
    uint currentBegin = owner->begin;
    uint currentEnd = owner->end;
    uint writeAt = (uint)MoveByteRange((void *)currentBegin,(void *)currentEnd,(void *)replacement);
    uint currentFirst = (uint)first;
    uint newEnd = (uint)MoveByteRange((void *)currentFirst,(void *)sourceEnd,(void *)writeAt);
    *(byte *)newEnd = 0;
    uint releaseBegin = owner->begin;
    TailFreeThroughGlobalAllocator((void *)releaseBegin);
    owner->begin = replacement;
    owner->capacityEnd = replacement + allocationBytes;
    owner->end = newEnd;
    return owner;
  }
  uint afterFirst = sourceBegin + 1;
  if (sourceEnd != afterFirst) {
    uint destination = owner->end + 1;
    uint copyBytes = sourceEnd - afterFirst;
    using MoveABI = void * (__cdecl *)(void *,const void *,uint);
    ((MoveABI)R6GameServiceAddresses::memmove)((void *)destination,(void *)afterFirst,copyBytes);
    sourceBegin = (uint)first;
  }
  uint currentEnd = owner->end;
  *(byte *)(addedBytes + currentEnd) = 0;
  currentEnd = owner->end;
  byte firstByte = *(byte *)sourceBegin;
  *(byte *)currentEnd = firstByte;
  uint newEnd = owner->end + addedBytes;
  owner->end = newEnd;
  return owner;
}

// Optionally publish the virtual-base table, then clear begin/end/capacity in order.
// R6GameService.dll @ 1002a980 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall InitializeEmptyByteBufferTriplet(void *triplet,uint initializeVirtualBaseWord)
{
  if (initializeVirtualBaseWord != 0) *(uint *)((byte *)triplet + 0xc) = 0x10076b94;
  *(uint *)triplet = 0;
  *(uint *)((byte *)triplet + 4) = 0;
  *(uint *)((byte *)triplet + 8) = 0;
  return triplet;
}

// Clear begin/end and forward the unused context while clearing capacity through the canonical store helper.
// R6GameService.dll @ 1002ab00 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall InitializeEmptyByteBufferTripletWithContext(void *triplet,uint contextWord)
{
  *(uint *)triplet = 0;
  *(uint *)((byte *)triplet + 4) = 0;
  StoreFirstWordIgnoringContext((byte *)triplet + 8,contextWord,0);
  return triplet;
}

// Fills a destination range, reloading the source byte each iteration, and returns the advanced destination.
// R6GameService.dll @ 1002b260 : destination/count/source-byte stack words, RET 0xc; EAX=end; count is unsigned.
undefined1 * __stdcall FillByteRangeAndReturnEnd(undefined1 *destination,uint count,undefined1 *sourceByte)
{
  while (count != 0) {
    *destination = *sourceByte;
    destination = (undefined1 *)((uint)destination + 1);
    --count;
  }
  return destination;
}

// Native type-two writer locals from entry ESP-8 through ESP-1; its first argument word becomes byte scratch.
struct TaggedTypeTwoWriteLocals {
  byte padding[3];
  byte failed;
  uint encodedLength;
};

// Appends b, a network-order virtual size and the late-loaded payload; success changes only the insertion result's AL.
// R6GameService.dll @ 1002c950 : stdcall two physical words; scratch/helper names are inferred.
uint __stdcall WriteTaggedType2(int *valueNode,undefined1 *outputContext)
{
  int *source = valueNode;
  TaggedTypeTwoWriteLocals scratch;
  scratch.failed = 0;
  uint initialEnd = *(uint *)((uint)source + 0x10);
  uint initialBegin = *(uint *)((uint)source + 0xc);
  uint rawSpan = initialEnd - initialBegin;
  // The retail unsigned JA after CMP UINT_MAX cannot take this failure exit.
  if (rawSpan > 0xffffffffu) return rawSpan & 0xffffff00u;
  uint vtable = *(uint *)source;
  using SizeABI = uint (__thiscall *)(void *);
  uint size = (*(SizeABI *)(vtable + 0x14))(source);
  using ConvertABI = uint (__stdcall *)(uint);
  uint converted = (*(ConvertABI *)R6GameServiceAddresses::WS2_32_htonlSlot)(size);
  uint output = (uint)outputContext;
  uint encoded = converted;
  scratch.encodedLength = encoded;
  uint end = *(uint *)(output + 0x10);
  uint capacity = *(uint *)(output + 0x14);
  auto *triplet = (R6GameServiceNative::ByteRange *)(output + 0xc);
  if (end != capacity) {
    if (end != 0) *(byte *)end = 'b';
    ++triplet->end;
  } else {
    GrowByteBufferAndInsertRepeatedBytes(triplet,(void *)end,
        (undefined1 *)R6GameServiceAddresses::WideTextB3,(uint)&valueNode,1,1);
  }
  // Append an already-selected length byte using the original value argument as the native byte scratch.
  auto appendLengthByte = [&](uint position,uint capacityEnd,byte selected) {
    *(byte *)&valueNode = selected;
    if (position != capacityEnd) {
      if (position != 0) *(byte *)position = selected;
      ++triplet->end;
    } else {
      GrowByteBufferAndInsertRepeatedBytes(triplet,(void *)position,
          (undefined1 *)&valueNode,(uint)&outputContext,1,1);
    }
  };
  end = triplet->end;
  capacity = triplet->capacityEnd;
  appendLengthByte(end,capacity,(byte)encoded);
  end = triplet->end;
  capacity = triplet->capacityEnd;
  appendLengthByte(end,capacity,(byte)(encoded >> 8));
  end = triplet->end;
  capacity = triplet->capacityEnd;
  byte thirdByte = *((byte *)&scratch.encodedLength + 2);
  appendLengthByte(end,capacity,thirdByte);
  end = triplet->end;
  capacity = triplet->capacityEnd;
  byte fourthByte = *((byte *)&scratch.encodedLength + 3);
  appendLengthByte(end,capacity,fourthByte);
  byte savedTag = *(byte *)&valueNode;
  uint sourceEnd = *(uint *)((uint)source + 0x10);
  *(byte *)&valueNode = savedTag;
  uint sourceBegin = *(uint *)((uint)source + 0xc);
  uint insertionPoint = *(uint *)(output + 0x10);
  uint result = InsertByteRange(
      triplet,(void *)insertionPoint,(void *)sourceBegin,(void *)sourceEnd,&valueNode,insertionPoint);
  return (result & 0xffffff00u) | (scratch.failed == 0 ? 1u : 0u);
}

// Allocates occupied+max(occupied,count), inserts repeated bytes and optionally copies the old tail.
// R6GameService.dll @ 1002ccb0 : ECX triplet, position/byte/unused-tag/count/skip-tail stack words, RET 0x14.
uint __thiscall GrowByteBufferAndInsertRepeatedBytes(
    void *buffer,void *insertionPoint,undefined1 *sourceByte,uint unusedTag,uint repeatCount,char skipTail)
{
  auto *triplet = reinterpret_cast<R6GameServiceNative::ByteRange *>(buffer);
  uint occupiedBytes = triplet->end - triplet->begin;
  uint growthBytes = occupiedBytes < repeatCount ? repeatCount : occupiedBytes;
  uint allocationBytes = occupiedBytes + growthBytes;
  undefined1 *replacement = (undefined1 *)AllocateGameServiceBytes(allocationBytes);
  uint currentBegin = triplet->begin;
  undefined1 *writeAt = replacement;
  if ((uint)insertionPoint != currentBegin) {
    uint prefixBytes = (uint)insertionPoint - currentBegin;
    writeAt = (undefined1 *)((uint)memmove(replacement,(void *)currentBegin,prefixBytes) + prefixBytes);
  }
  uint remaining = repeatCount;
  while (remaining != 0) {
    writeAt = (undefined1 *)((uint)writeAt + 1);
    --remaining;
    byte value = *sourceByte;
    *(byte *)((uint)writeAt - 1) = value;
  }
  undefined1 *newEnd = writeAt;
  if (skipTail == 0) {
    uint currentEnd = triplet->end;
    if (currentEnd != (uint)insertionPoint) {
      uint tailBytes = currentEnd - (uint)insertionPoint;
      newEnd = (undefined1 *)((uint)memmove(writeAt,insertionPoint,tailBytes) + tailBytes);
    }
  }
  uint cleanupResult = TailFreeThroughGlobalAllocator((void *)triplet->begin);
  triplet->begin = (uint)replacement;
  triplet->capacityEnd = (uint)replacement + allocationBytes;
  triplet->end = (uint)newEnd;
  return cleanupResult;
}

// Stores three words, loading the second before any store and the third after the first store, then returns the third.
// R6GameService.dll @ 1002cd70 : ECX record, three stack words, RET 0xc; EAX=third loaded word.
uint __thiscall SetThreeWordRecord(void *record,uint first,uint second,uint third)
{
  uint secondBeforeStore = second;
  *(uint *)record = first;
  uint thirdAfterFirstStore = third;
  *(uint *)((byte *)record + 4) = secondBeforeStore;
  *(uint *)((byte *)record + 8) = thirdAfterFirstStore;
  return thirdAfterFirstStore;
}

// Move the wrapped half-open range and return the provider result plus its size; skip the provider for an empty range.
// R6GameService.dll @ 10028600 : selected PE32 operations; helper/type names remain descriptive.
void * __stdcall MoveByteRange(void *first,void *last,void *destination)
{
  if (last == first) return destination;
  uint byteCount = (uint)last - (uint)first;
  using MoveABI = void * (__cdecl *)(void *,const void *,uint);
  void *copied = ((MoveABI)R6GameServiceAddresses::memmove)(destination,first,byteCount);
  return (void *)((uint)copied + byteCount);
}

// Move the wrapped half-open range and return the provider result plus its size; skip the provider for an empty range.
// R6GameService.dll @ 1002bbf0 : selected PE32 operations; helper/type names remain descriptive.
void * __stdcall CopyByteRange(void *first,void *last,void *destination,void *unusedTag)
{
  if (last == first) return destination;
  uint byteCount = (uint)last - (uint)first;
  using MoveABI = void * (__cdecl *)(void *,const void *,uint);
  void *copied = ((MoveABI)R6GameServiceAddresses::memmove)(destination,first,byteCount);
  return (void *)((uint)copied + byteCount);
}

// Insert bytes by shifting a long/short suffix or growing, retaining live fields/formals and allocator return pointers.
// Empty input skips triplet fields and returns incoming EAX. Native locals: entryESP-c padding/tag/count/occupied.
// R6GameService.dll @ 1002b100 : ECX/EAX register view, four native stack words/RET16; no allocation guard.
uint InsertByteRange(
    [[r6abi::register_input("ecx")]] void *buffer,void *position,void *first,void *last,void *unusedTag,
    [[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  struct { // Inferred twelve-byte native scratch; tag is the last byte of the untouched first word.
    byte padding[3];
    byte constructorTag;
    uint insertedCount;
    uint occupiedBytes;
  } frame;
  void *sourceLast = last;
  void *sourceFirst = first;
  if (sourceFirst == sourceLast) return eaxAtEntry;
  uint base = (uint)buffer;
  uint initialEnd = *(uint *)(base + 4);
  uint capacityEnd = *(uint *)(base + 8);
  uint spare = capacityEnd - initialEnd;
  uint inserted = (uint)sourceLast - (uint)sourceFirst;
  frame.insertedCount = inserted;
  using MoveABI = void * (__cdecl *)(void *,const void *,uint);
  if (spare >= inserted) {
    uint initialPosition = (uint)position;
    uint suffix = initialEnd - initialPosition;
    uint oldEnd = *(uint *)(base + 4);
    if (suffix > inserted) {
      byte tag = *(byte *)&position;
      uint duplicateStart = oldEnd - inserted;
      frame.constructorTag = tag;
      CopyByteRange((void *)duplicateStart,(void *)oldEnd,(void *)oldEnd,&frame.constructorTag);
      uint end = *(uint *)(base + 4) + inserted;
      *(uint *)(base + 4) = end;
      uint retainedPosition = (uint)position;
      uint shiftBytes = duplicateStart - retainedPosition;
      if ((int)shiftBytes > 0) {
        uint destination = oldEnd - shiftBytes;
        ((MoveABI)R6GameServiceAddresses::memmove)((void *)destination,(void *)retainedPosition,shiftBytes);
      }
      void *currentLast = last;
      void *currentFirst = first;
      return (uint)MoveByteRange(currentFirst,currentLast,(void *)retainedPosition);
    }
    uint split = (uint)sourceFirst + suffix;
    last = (void *)split; // Original range-end argument becomes the source split before the first copy.
    MoveByteRange((void *)split,sourceLast,(void *)oldEnd);
    uint end = *(uint *)(base + 4);
    uint excess = inserted - suffix;
    end += excess;
    uint retainedPosition = (uint)position;
    *(uint *)(base + 4) = end;
    MoveByteRange((void *)retainedPosition,(void *)oldEnd,(void *)end);
    uint extendedEnd = *(uint *)(base + 4) + suffix;
    void *currentSplit = last;
    void *currentFirst = first;
    *(uint *)(base + 4) = extendedEnd;
    return (uint)MoveByteRange(currentFirst,currentSplit,(void *)retainedPosition);
  }
  uint begin = *(uint *)base;
  uint occupied = initialEnd - begin;
  frame.occupiedBytes = occupied;
  uint *growthSource = &frame.insertedCount;
  if (occupied >= inserted) growthSource = &frame.occupiedBytes;
  uint allocationBytes = *growthSource + occupied;
  uint allocation = (uint)AllocateGameServiceBytes(allocationBytes);
  uint retainedPosition = (uint)position;
  uint oldBegin = *(uint *)base;
  uint prefixEnd = (uint)MoveByteRange((void *)oldBegin,(void *)retainedPosition,(void *)allocation);
  void *currentFirst = first;
  void *currentLast = last;
  uint newEnd = (uint)MoveByteRange(currentFirst,currentLast,(void *)prefixEnd);
  uint currentEnd = *(uint *)(base + 4);
  position = (void *)newEnd;
  if (currentEnd != retainedPosition) {
    uint tailBytes = currentEnd - retainedPosition;
    position = (void *)tailBytes; // Position word is scratch while memmove owns its cached destination argument.
    void *moved = ((MoveABI)R6GameServiceAddresses::memmove)((void *)newEnd,(void *)retainedPosition,tailBytes);
    uint currentTail = (uint)position;
    position = (void *)((uint)moved + currentTail);
  }
  void *currentBegin = *(void **)base;
  TailFreeThroughGlobalAllocator(currentBegin);
  uint finalEnd = (uint)position;
  *(uint *)base = allocation;
  uint newCapacityEnd = allocation + allocationBytes;
  *(uint *)(base + 4) = finalEnd;
  *(uint *)(base + 8) = newCapacityEnd;
  return finalEnd;
}

// Forward with a tag in the high byte of saved ECX; native POP restores that modified volatile word on normal return.
// The target's empty path receives insertionPoint in EAX, independently of this wrapper's incoming EAX.
// R6GameService.dll @ 1002b010 : ECX triplet, four native stack words/RET16; annotated local is return ECX.
uint __thiscall InsertByteRangeWithLocalTag(
    void *buffer,void *insertionPoint,void *first,void *last,undefined1 *unusedTag)
{
  [[r6abi::register_output("ecx")]] uint savedEcx = (uint)buffer;
  byte tag = *(byte *)&last;
  byte *tagAddress = (byte *)&savedEcx + 3;
  *tagAddress = tag;
  void *currentLast = last;
  void *currentFirst = first;
  void *currentPosition = insertionPoint;
  return InsertByteRange(buffer,currentPosition,currentFirst,currentLast,tagAddress,(uint)currentPosition);
}

// Appends a type-four scalar on success or short input, committing its cached cursor only after insertion.
// R6GameService.dll @ 1002c260 : complete native frame/argument/access order and raw ABI retained; ECX unused.
uint __stdcall ParseWordValue(undefined4 *source,int *cursorAddress,int destination)
{
  uint *initialCursorAddress = (uint *)cursorAddress;
  uint sourceObject = (uint)source;
  uint end = *(uint *)(sourceObject + 0x10);
  uint cursor = *initialCursorAddress;
  uint payload = (uint)AllocateGameServiceBytes(0x14);
  if (payload != 0) {
    *(uint *)(payload + 4) = 0x10076b34;
    *(uint *)(payload + 8) = 4;
    *(uint *)payload = R6GameServiceAddresses::clDataLongVTable;
  }
  bool failed = cursor == end || cursor + 1 == end || end - cursor < 4;
  if (!failed) {
    uint encoded = *(uint *)cursor;
    cursor += 4;
    SetClDataLongEncodedValue((void *)payload,encoded);
  }
  uint savedDestination = (uint)destination;
  source = (undefined4 *)payload;
  uint headSlot = savedDestination + 0x10;
  CopyListHeadSlot((void *)headSlot,(uint *)&destination);
  uint node = (uint)AllocateListPayloadNode((uint *)&source);
  uint sentinel = (uint)destination;
  uint previous = *(uint *)(sentinel + 4);
  *(uint *)node = sentinel;
  *(uint *)(node + 4) = previous;
  *(uint *)previous = node;
  *(uint *)(sentinel + 4) = node;
  uint *outputCursorAddress = (uint *)cursorAddress;
  *outputCursorAddress = cursor;
  return ((uint)outputCursorAddress & 0xffffff00u) | (failed ? 0u : 1u);
}

// Parses through NUL or cached end and appends even a partial string, retaining path-specific argument scratch.
// R6GameService.dll @ 1002c0c0 : stdcall three words; construction scope and local names are inferred.
uint __stdcall ParseStringValue(undefined4 *source,int *cursorAddress,int destination)
{
  uint inputEnd = *(uint *)((uint)source + 0x10);
  uint endOrSentinel = inputEnd;
  uint payload = 0;
  uint allocation = (uint)AllocateGameServiceBytes(0x18);
  uint savedAllocation = allocation;
  if (allocation != 0) {
    *(uint *)(allocation + 4) = R6GameServiceAddresses::ClDataStrBaseOffsets;
    *(uint *)(allocation + 8) = 1;
    *(uint *)allocation = R6GameServiceAddresses::PTR_LAB;
    uint triplet = allocation + 0xc;
    // Native state3 owns the object through initial NUL/table publication; tag/context cleanup actions are empty.
    try {
      InitializeEmptyByteBufferTripletWithContext((void *)triplet,(uint)&source);
      uint buffer = (uint)AllocateGameServiceBytes(8);
      *(uint *)triplet = buffer;
      *(uint *)(triplet + 4) = buffer;
      *(uint *)(triplet + 8) = buffer + 8;
      *(byte *)buffer = 0;
      *(uint *)allocation = R6GameServiceAddresses::clDataStrPTR_FUN;
      payload = allocation;
    } catch (...) {
      ResetClDataVtable((undefined4 *)savedAllocation);
      ForwardToAllocatorTail((void *)savedAllocation);
      throw;
    }
  }
  uint triplet = payload != 0 ? payload + 0xc : 0;
  int *sharedCursor = cursorAddress;
  uint cursor = (uint)*sharedCursor;
  bool terminated = false;
  if (cursor != inputEnd) {
    for (;;) {
      byte character = *(byte *)cursor;
      ++cursor;
      *sharedCursor = (int)cursor;
      if (character == 0) {
        terminated = true;
        break;
      }
      uint end = *(uint *)(triplet + 4);
      uint capacity = *(uint *)(triplet + 8);
      if (end + 1 == capacity) {
        source = (undefined4 *)1;
        uint occupiedBytes = end - *(uint *)triplet;
        cursorAddress = (int *)occupiedBytes;
        uint *growth = occupiedBytes < 1 ? (uint *)&source : (uint *)&cursorAddress;
        uint requestedBytes = *growth + occupiedBytes;
        ReserveByteString((void *)triplet,requestedBytes);
      }
      end = *(uint *)(triplet + 4);
      *(byte *)(end + 1) = 0;
      end = *(uint *)(triplet + 4);
      *(byte *)end = character;
      end = *(uint *)(triplet + 4);
      uint savedBound = endOrSentinel;
      ++end;
      *(uint *)(triplet + 4) = end;
      cursor = (uint)*sharedCursor;
      if (cursor == savedBound) break;
    }
  }
  uint node;
  uint head;
  uint savedDestination = (uint)destination;
  uint headSlot = savedDestination + 0x10;
  if (terminated) {
    source = (undefined4 *)payload;
    CopyListHeadSlot((void *)headSlot,(uint *)&destination);
    node = (uint)AllocateListPayloadNode((uint *)&source);
    head = (uint)destination;
  } else {
    cursorAddress = (int *)payload;
    CopyListHeadSlot((void *)headSlot,&endOrSentinel);
    node = (uint)AllocateListPayloadNode((uint *)&cursorAddress);
    head = endOrSentinel;
  }
  uint previous = *(uint *)(head + 4);
  *(uint *)node = head;
  *(uint *)(node + 4) = previous;
  *(uint *)previous = node;
  *(uint *)(head + 4) = node;
  return (node & 0xffffff00u) | (terminated ? 1u : 0u);
}

// Releases the string allocation saved at parent EBP-0x10 during constructor unwinding.
// R6GameService.dll @ 10065d30 : inherited EBP, allocation stack argument to CALL10014d00, then RET.
__declspec(naked) void __cdecl ReleaseTaggedStringAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards allocation+0x18 to empty cleanup only when the parent's construction flag bit zero is set.
// R6GameService.dll @ 10065d3a : inherited EBP; flags at -0x18, allocation at -0x10.
__declspec(naked) void __cdecl CleanupTaggedStringContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x18]
    and    eax,1
    test   eax,eax
    je     noContext
    mov    ecx,dword ptr [ebp-0x10]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  noContext:
    ret
  }
}

// Restores the constructing string allocation's clData base vtable.
// R6GameService.dll @ 10065d54 : inherited EBP; saved allocation at -0x10, JMP1002ae90.
__declspec(naked) void __cdecl ResetTaggedStringBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forwards the string parser's original source-argument address to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065d5c : inherited EBP; LEA ECX,[EBP+4], JMP10059130.
__declspec(naked) void __cdecl CleanupTaggedStringConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the string parser's four-state FuncInfo for the shared C++ exception handler.
// R6GameService.dll @ 10065d64 : MOV EAX,10080124, JMP10033906.
__declspec(naked) void __cdecl TaggedStringParseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TaggedStringParseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Parses a network-length block, retaining two/three-byte prefix overread and insertion before final cursor commit.
// R6GameService.dll @ 1002c310 : stdcall three words; construction cleanup and scratch names are inferred.
uint __stdcall ParseByteBlockValue(undefined4 *source,int *cursorAddress,int destination)
{
  int *sharedCursor = cursorAddress;
  uint cursor = (uint)*sharedCursor;
  uint inputEnd = *(uint *)((uint)source + 0x10);
  byte failed = 0;
  uint payload = (uint)AllocateGameServiceBytes(0x1c);
  source = (undefined4 *)payload;
  if (payload != 0) {
    *(uint *)(payload + 4) = R6GameServiceAddresses::ClDataBinOwnerBaseOffsets;
    *(uint *)(payload + 0x18) = R6GameServiceAddresses::ClDataBinBaseOffsets;
    *(uint *)(payload + 8) = 2;
    *(uint *)payload = R6GameServiceAddresses::PTR_LAB;
    uint triplet = payload + 0xc;
    // Native state4 owns the object only during triplet/table initialization; its tag/context actions are empty.
    try {
      InitializePointerTriplet((void *)triplet,&cursorAddress);
      *(uint *)payload = R6GameServiceAddresses::clDataBinPTR_FUN;
    } catch (...) {
      ResetClDataVtable(source);
      ForwardToAllocatorTail(source);
      throw;
    }
  }
  if (cursor == inputEnd || cursor + 1 == inputEnd) {
    failed = 1;
  } else {
    byte firstByte = *(byte *)cursor;
    cursor += 1;
    byte thirdByte = *(byte *)(cursor + 1);
    *(byte *)&cursorAddress = firstByte;
    byte secondByte = *(byte *)cursor;
    cursor += 2;
    *((byte *)&cursorAddress + 1) = secondByte;
    *((byte *)&cursorAddress + 2) = thirdByte;
    byte fourthByte = *(byte *)cursor;
    ++cursor;
    *((byte *)&cursorAddress + 3) = fourthByte;
    using ConvertABI = uint (__stdcall *)(uint);
    uint declaredBytes = (*(ConvertABI *)R6GameServiceAddresses::WS2_32_ntohlSlot)((uint)cursorAddress);
    uint remaining = inputEnd - cursor;
    if (remaining < declaredBytes || declaredBytes > 0xffffffffu) {
      failed = 1;
    } else {
      *sharedCursor = (int)cursor;
      cursor += declaredBytes;
      byte savedTag = *(byte *)&cursorAddress;
      uint triplet = payload + 0xc;
      *(byte *)&cursorAddress = savedTag;
      uint first = (uint)*sharedCursor;
      uint insertionPoint = *(uint *)triplet;
      InsertByteRange((void *)triplet,(void *)insertionPoint,(void *)first,(void *)cursor,&cursorAddress,first);
    }
  }
  uint savedDestination = (uint)destination;
  source = (undefined4 *)payload;
  uint headSlot = savedDestination + 0x10;
  CopyListHeadSlot((void *)headSlot,(uint *)&destination);
  uint node = (uint)AllocateListPayloadNode((uint *)&source);
  uint head = (uint)destination;
  uint previous = *(uint *)(head + 4);
  *(uint *)node = head;
  *(uint *)(node + 4) = previous;
  *(uint *)previous = node;
  *(uint *)(head + 4) = node;
  byte finalFailure = failed;
  uint result = node & 0xffffff00u;
  *sharedCursor = (int)cursor;
  return result | (finalFailure == 0 ? 1u : 0u);
}

// Releases the binary allocation saved at parent EBP+4 during constructor unwinding.
// R6GameService.dll @ 10065d70 : inherited EBP, allocation stack argument to CALL10014d00, then RET.
__declspec(naked) void __cdecl ReleaseTaggedByteBlockAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards allocation+0x1c to empty cleanup only when the parent's construction flag bit zero is set.
// R6GameService.dll @ 10065d7a : inherited EBP; flags at -0x14, allocation at +4.
__declspec(naked) void __cdecl CleanupTaggedByteBlockContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    and    eax,1
    test   eax,eax
    je     noContext
    mov    ecx,dword ptr [ebp+0x4]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  noContext:
    ret
  }
}

// Restores the constructing binary allocation's clData base vtable.
// R6GameService.dll @ 10065d94 : inherited EBP; saved allocation at +4, JMP1002ae90.
__declspec(naked) void __cdecl ResetTaggedByteBlockBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp+0x4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forwards the binary parser's original cursor-argument address to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065d9c : inherited EBP; LEA ECX,[EBP+8], JMP10059130.
__declspec(naked) void __cdecl CleanupTaggedByteBlockConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the binary parser's five-state FuncInfo for the shared C++ exception handler.
// R6GameService.dll @ 10065da4 : MOV EAX,10080168, JMP10033906.
__declspec(naked) void __cdecl TaggedByteBlockParseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TaggedByteBlockParseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Appends s, the current string range and NUL; scratch argument aliases and growth publication order are retained.
// R6GameService.dll @ 1002c5e0 : stdcall two physical words; success replaces only AL.
uint __stdcall WriteTaggedType1(int valueWord,int outputWord)
{
  uint output = (uint)outputWord;
  auto *triplet = (R6GameServiceNative::ByteRange *)(output + 0xc);
  uint end = triplet->end;
  uint capacity = triplet->capacityEnd;
  if (end != capacity) {
    if (end != 0) *(byte *)end = 's';
    ++triplet->end;
  } else {
    GrowByteBufferAndInsertRepeatedBytes(triplet,(void *)end,
        (undefined1 *)R6GameServiceAddresses::TextSLb3,(uint)&outputWord,1,1);
  }
  byte savedTag = *(byte *)&outputWord;
  uint source = (uint)valueWord;
  *(byte *)&outputWord = savedTag;
  uint sourceEnd = *(uint *)(source + 0x10);
  uint sourceBegin = *(uint *)(source + 0xc);
  uint insertionPoint = *(uint *)(output + 0x10);
  InsertByteRange(
      triplet,(void *)insertionPoint,(void *)sourceBegin,(void *)sourceEnd,&outputWord,insertionPoint);
  end = triplet->end;
  capacity = triplet->capacityEnd;
  if (end != capacity) {
    if (end != 0) *(byte *)end = 0;
    uint newEnd = triplet->end + 1;
    triplet->end = newEnd;
    return (newEnd & 0xffffff00u) | 1u;
  }
  uint occupiedBytes = end - triplet->begin;
  outputWord = 1;
  valueWord = (int)occupiedBytes;
  uint *growth = occupiedBytes < 1 ? (uint *)&outputWord : (uint *)&valueWord;
  uint allocationBytes = *growth + occupiedBytes;
  uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
  uint currentBegin = triplet->begin;
  uint writeAt = replacement;
  if (end != currentBegin) {
    uint copyBytes = end - currentBegin;
    using MoveABI = void * (__cdecl *)(void *,const void *,uint);
    writeAt = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
        (void *)replacement,(void *)currentBegin,copyBytes) + copyBytes;
  }
  *(byte *)writeAt = 0;
  uint oldBegin = triplet->begin;
  uint newEnd = writeAt + 1;
  uint result = TailFreeThroughGlobalAllocator((void *)oldBegin);
  triplet->begin = replacement;
  triplet->capacityEnd = replacement + allocationBytes;
  triplet->end = newEnd;
  return (result & 0xffffff00u) | 1u;
}

// Appends s and virtual-size-plus-one bytes, retaining the source pointer cached before the size callback.
// R6GameService.dll @ 1002c6d0 : stdcall two physical words; cursor/limit/growth names are inferred.
uint __stdcall WriteTaggedType5(int *value,undefined1 *outputWord)
{
  uint end = *(uint *)((uint)outputWord + 0x10);
  auto *triplet = (R6GameServiceNative::ByteRange *)((uint)outputWord + 0xc);
  if (end != triplet->capacityEnd) {
    if (end != 0) *(byte *)end = 's';
    ++triplet->end;
  } else {
    uint occupiedBytes = end - triplet->begin;
    outputWord = (undefined1 *)1;
    uint *growth = occupiedBytes < 1 ? (uint *)&outputWord : &occupiedBytes;
    uint allocationBytes = *growth + occupiedBytes;
    uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
    uint currentBegin = triplet->begin;
    uint writeAt = replacement;
    if (end != currentBegin) {
      uint copyBytes = end - currentBegin;
      using MoveABI = void * (__cdecl *)(void *,const void *,uint);
      writeAt = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
          (void *)replacement,(void *)currentBegin,copyBytes) + copyBytes;
    }
    *(byte *)writeAt = 's';
    uint newEnd = writeAt + 1;
    uint oldBegin = triplet->begin;
    uint oldAllocationBytes = triplet->capacityEnd - oldBegin;
    ReleaseMemoryIgnoringSize((void *)oldBegin,oldAllocationBytes);
    SetThreeWordRecord(triplet,replacement,newEnd,replacement + allocationBytes);
  }
  int *source = value;
  uint vtable = *(uint *)source;
  uint sourceBegin = *(uint *)((uint)source + 0xc);
  using SizeABI = uint (__thiscall *)(void *);
  uint size = (*(SizeABI *)(vtable + 0x14))(source);
  uint limit = sourceBegin + size + 1;
  uint sourceEnd = limit;
  uint cursor = sourceBegin;
  outputWord = (undefined1 *)cursor;
  while (cursor != limit) {
    end = triplet->end;
    uint capacity = triplet->capacityEnd;
    if (end != capacity) {
      if (end != 0) *(byte *)end = *(byte *)cursor;
      ++triplet->end;
    } else {
      uint occupiedBytes = end - triplet->begin;
      value = (int *)1;
      uint *growth = occupiedBytes < 1 ? (uint *)&value : &occupiedBytes;
      uint allocationBytes = *growth + occupiedBytes;
      uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
      uint currentBegin = triplet->begin;
      uint writeAt = replacement;
      if (end != currentBegin) {
        uint copyBytes = end - currentBegin;
        using MoveABI = void * (__cdecl *)(void *,const void *,uint);
        writeAt = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
            (void *)replacement,(void *)currentBegin,copyBytes) + copyBytes;
      }
      uint currentSource = (uint)outputWord;
      uint newEnd = writeAt + 1;
      byte sourceByte = *(byte *)currentSource;
      *(byte *)writeAt = sourceByte;
      ReleaseFirstWordBuffer(triplet);
      SetThreeWordRecord(triplet,replacement,newEnd,replacement + allocationBytes);
      cursor = (uint)outputWord;
      limit = sourceEnd;
    }
    ++cursor;
    outputWord = (undefined1 *)cursor;
  }
  return (cursor & 0xffffff00u) | 1u;
}

// Appends L and four encoded bytes, reloading the value each time and preserving path-specific upper return bits.
// R6GameService.dll @ 1002c820 : stdcall two physical words; local index/growth names are inferred.
uint __stdcall WriteTaggedType4(int valueWord,uint outputWord)
{
  uint result = outputWord;
  uint end = *(uint *)(outputWord + 0x10);
  auto *triplet = (R6GameServiceNative::ByteRange *)(outputWord + 0xc);
  if (end != triplet->capacityEnd) {
    if (end != 0) *(byte *)end = 'L';
    ++triplet->end;
  } else {
    uint occupiedBytes = end - triplet->begin;
    outputWord = 1;
    uint *growth = occupiedBytes < 1 ? &outputWord : &occupiedBytes;
    uint allocationBytes = *growth + occupiedBytes;
    uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
    uint currentBegin = triplet->begin;
    uint writeAt = replacement;
    if (end != currentBegin) {
      uint copyBytes = end - currentBegin;
      using MoveABI = void * (__cdecl *)(void *,const void *,uint);
      writeAt = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
          (void *)replacement,(void *)currentBegin,copyBytes) + copyBytes;
    }
    uint newEnd = (uint)FillByteRangeAndReturnEnd((undefined1 *)writeAt,1,
        (undefined1 *)R6GameServiceAddresses::TextLb);
    ReleaseFirstWordBuffer(triplet);
    result = SetThreeWordRecord(triplet,replacement,newEnd,replacement + allocationBytes);
  }
  uint index = 0;
  uint currentIndex = 0;
  do {
    uint source = (uint)valueWord;
    end = triplet->end;
    byte encodedByte = *(byte *)(source + currentIndex + 0xc);
    result = (result & 0xffffff00u) | encodedByte;
    uint capacity = triplet->capacityEnd;
    *(byte *)&outputWord = encodedByte;
    if (end != capacity) {
      if (end != 0) *(byte *)end = encodedByte;
      ++triplet->end;
    } else {
      uint occupiedBytes = end - triplet->begin;
      uint one = 1;
      uint *growth = occupiedBytes < 1 ? &one : &occupiedBytes;
      uint allocationBytes = *growth + occupiedBytes;
      uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
      uint currentBegin = triplet->begin;
      uint writeAt = replacement;
      if (end != currentBegin) {
        uint copyBytes = end - currentBegin;
        using MoveABI = void * (__cdecl *)(void *,const void *,uint);
        writeAt = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
            (void *)replacement,(void *)currentBegin,copyBytes) + copyBytes;
      }
      byte savedByte = *(byte *)&outputWord;
      uint newEnd = writeAt + 1;
      *(byte *)writeAt = savedByte;
      uint oldBegin = triplet->begin;
      result = TailFreeThroughGlobalAllocator((void *)oldBegin);
      currentIndex = index;
      triplet->begin = replacement;
      triplet->end = newEnd;
      triplet->capacityEnd = replacement + allocationBytes;
    }
    ++currentIndex;
    index = currentIndex;
  } while (currentIndex < 4);
  return (result & 0xffffff00u) | 1u;
}

// Clear the triplet, allocate eight bytes unchecked and publish all three fields before writing the initial NUL.
// R6GameService.dll @ 1002aca0 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall InitializeEmptyByteString(void *triplet)
{
  *(uint *)triplet = 0;
  *(uint *)((byte *)triplet + 4) = 0;
  *(uint *)((byte *)triplet + 8) = 0;
  uint allocation = (uint)AllocateGameServiceBytes(8);
  *(uint *)triplet = allocation;
  *(uint *)((byte *)triplet + 4) = allocation;
  *(uint *)((byte *)triplet + 8) = allocation + 8;
  *(byte *)allocation = 0;
  return triplet;
}

// Prints the NUL-terminated pointer at descriptor+0x0c as a quoted string followed by a space.
// R6GameService.dll @ 1002ab80 : shared clDataStr/clDataStrRef vtable body, ECX descriptor; raw printf EAX.
uint __fastcall PrintQuotedDescriptorString(void *descriptor)
{
  return printf((char *)R6GameServiceAddresses::TextS2,*(char **)((byte *)descriptor + 0x0c));
}

// Selects the shared string/string-reference indentation methods' five-state exception metadata.
// R6GameService.dll @ 10065cb0 : EAX=10080014, inherited-frame tail transfer to10033906.
__declspec(naked) void __cdecl StringIndentExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::StringIndentExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reserve locals span logical EBP-0x130..-4; the exception storage is a native 0x110-byte region.
struct ByteStringReserveFrame {
  uint copiedBytes;
  byte padding[3];
  byte constructorTag;
  uint messageString[3];
  byte exceptionStorage[0x110];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Reallocates to max(current length, requested)+1, retaining unchecked wrap, NUL and raw release EAX.
// R6GameService.dll @ 1002acd0 : ECX triplet, requested-capacity stack word, RET 4.
uint __thiscall ReserveByteString(void *triplet,uint requestedCapacity)
{
  ByteStringReserveFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)ByteStringReserveExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  if (requestedCapacity > 0xfffffffe) {
    void *message = ConstructPooledByteString(
        frame.messageString,s_basic_string,&frame.constructorTag);
    frame.state = 0;
    ConstructException75c28(frame.exceptionStorage,(undefined4 *)message);
    _CxxThrowException(frame.exceptionStorage,(ThrowInfo *)&ByteStringLengthErrorThrowInfo);
  }
  uint *words = (uint *)triplet;
  frame.copiedBytes = words[1] - words[0];
  uint allocationBytes = (requestedCapacity < frame.copiedBytes ? frame.copiedBytes : requestedCapacity) + 1;
  byte *replacement = (byte *)AllocateGameServiceBytes(allocationBytes);
  uint currentEnd = words[1];
  uint currentBegin = words[0];
  byte *writeAt = replacement;
  if (currentEnd != currentBegin) {
    frame.copiedBytes = currentEnd - currentBegin;
    void *copied = memmove(replacement,(void *)currentBegin,frame.copiedBytes);
    writeAt = (byte *)((uint)copied + frame.copiedBytes);
  }
  *writeAt = 0;
  uint result = TailFreeThroughGlobalAllocator((void *)words[0]);
  void *previousExceptionList = frame.previousExceptionList;
  words[0] = (uint)replacement;
  words[1] = (uint)writeAt;
  words[2] = (uint)replacement + allocationBytes;
  ExceptionList = previousExceptionList;
  return result;
}

// Releases the pooled message string constructed for reserve's length-error throw.
// R6GameService.dll @ 10065c70 : inherited EBP; ECX=EBP-0x128, JMP10017330.
__declspec(naked) void __cdecl ReleaseReserveErrorMessage(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects reserve's three-state exception metadata for the shared C++ frame handler.
// R6GameService.dll @ 10065c7b : EAX=1007ffd0, inherited-frame JMP10033906.
__declspec(naked) void __cdecl ByteStringReserveExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ByteStringReserveExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Appends the NUL-terminated pointer at descriptor+0x0c and returns the original destination, ignoring append EAX.
// R6GameService.dll @ 1002b4a0 : ECX unused, destination/descriptor stack words, RET 8.
void * __stdcall AppendDescriptorCString(void *destination,uint descriptorWord)
{
  byte tag = *(byte *)&descriptorWord;
  char *first = *(char **)(descriptorWord + 0x0c);
  *(byte *)&descriptorWord = tag;
  uint remaining = 0xffffffff;
  char *scan = first;
  while (remaining != 0) {
    --remaining;
    char character = *scan++;
    if (character == 0) break;
  }
  char *last = (char *)((uint)first + (~remaining - 1));
  AppendByteRangePreservingNul(destination,(undefined1 *)first,(undefined1 *)last,(undefined1 *)&descriptorWord);
  return destination;
}

// Shared indentation locals span logical EBP-0x20..-4, including separate borrowed-string closing/tag slots.
struct StringIndentFrame {
  byte spaceOrPayloadTag;
  byte padding[5];
  byte closingTag;
  byte constructorTag;
  uint spaces[3];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Forwards the indentation frame's constructor-tag address to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065c90 : inherited EBP; LEA ECX,[EBP-0x19], JMP10059130.
__declspec(naked) void __cdecl CleanupIndentConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp-0x19]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Forwards the indentation triplet's capacity-word address to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065c98 : inherited EBP; LEA ECX,[EBP-0x10], JMP10059130.
__declspec(naked) void __cdecl CleanupIndentCapacityContext(void)
{
  __asm {
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the first word of the indentation frame's temporary triplet through its native helper.
// R6GameService.dll @ 10065ca0 : inherited EBP; LEA ECX,[EBP-0x18], JMP10041530.
__declspec(naked) void __cdecl ReleaseIndentSpaces(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the same temporary triplet for the later native indentation unwind states.
// R6GameService.dll @ 10065ca8 : inherited EBP; LEA ECX,[EBP-0x18], JMP10041530.
__declspec(naked) void __cdecl ReleaseIndentSpacesLate(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Appends a range using a local last-low-byte tag, ignoring the caller's third word and forwarding the full result.
// R6GameService.dll @ 1002b040 : ECX triplet, first/last/unused-tag stack words, RET 0xc.
void * __thiscall AppendByteRangeWithLocalGrowthTag(
    void *triplet,undefined1 *first,undefined1 *last,uint unusedTag)
{
  byte localTag = (byte)(uint)last;
  return AppendByteRangeWithGrowth(triplet,first,last,(uint)&localTag);
}

// Allocates length+1, publishes storage before copying, then writes NUL; a wrapped zero size takes the length error.
// R6GameService.dll @ 1002b0a0 : ECX triplet, first/last/unused-tag stack words; EAX=new end, RET 0xc.
void * __thiscall ConstructHeapByteStringRange(void *triplet,void *first,int lastWord,void *unusedTag)
{
  uint sourceBegin = (uint)first;
  uint copiedBytes = (uint)lastWord - sourceBegin;
  auto *owner = (R6GameServiceNative::ByteRange *)triplet;
  uint allocationBytes = copiedBytes + 1;
  if (allocationBytes != 0) {
    uint replacement = (uint)AllocateGameServiceBytes(allocationBytes);
    owner->begin = replacement;
    owner->end = replacement;
    owner->capacityEnd = replacement + allocationBytes;
  } else {
    ThrowByteStringLengthError(s_basic_string);
  }
  uint currentLast = (uint)lastWord;
  uint result = owner->begin;
  if (currentLast != sourceBegin) {
    using MoveABI = void * (__cdecl *)(void *,const void *,uint);
    result = (uint)((MoveABI)R6GameServiceAddresses::memmove)(
        (void *)result,(void *)sourceBegin,copiedBytes) + copiedBytes;
  }
  owner->end = result;
  *(byte *)result = 0;
  return (void *)result;
}

// Overwrites occupied bytes from begin, then shrinks by copying the old end byte or grows with the remaining input.
// Forward overlap, live end reloads, original first-word tag access and current-end publication remain native.
// R6GameService.dll @ 100184e0 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall AppendByteRange(void *triplet,void *first,void *last,uint unusedStackWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    cmp    eax,ecx
    mov    esi,DWORD PTR [edi]
    je     Branch88
  Branch86:
    cmp    esi,DWORD PTR [edi+0x4]
    je     Branch87
    mov    dl,BYTE PTR [eax]
    inc    eax
    mov    BYTE PTR [esi],dl
    inc    esi
    cmp    eax,ecx
    jne    Branch86
    jmp    Branch88
  Branch87:
    cmp    eax,ecx
    jne    Branch90
  Branch88:
    mov    ebx,DWORD PTR [edi+0x4]
    cmp    esi,ebx
    je     Branch91
    mov    eax,ebx
    sub    eax,ebx
    inc    eax
    je     Branch89
    push   eax
    push   ebx
    push   esi
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch89:
    mov    eax,DWORD PTR [edi+0x4]
    sub    esi,ebx
    add    eax,esi
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  Branch90:
    mov    dl,BYTE PTR [esp+0x10]
    mov    BYTE PTR [esp+0x10],dl
    lea    edx,[esp+0x10]
    push   edx
    push   ecx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
  Branch91:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Clears pointer triplet then allocates any nonzero size; zero constructs and throws native named length_error.
// Saved receiver, cached size, staged diagnostic ownership, uninitialized tag bytes and original RET8 remain explicit.
// R6GameService.dll @ 1002a9b0 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructByteTripletBuffer(void *triplet,uint unusedWord,uint byteCount)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTripletBufferLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x120
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ebx,ebx
    push   edi
    mov    DWORD PTR [esp+0x1c],esi
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],ebx
    mov    DWORD PTR [esi+0x8],ebx
    mov    edi,DWORD PTR [esp+0x140]
    mov    DWORD PTR [esp+0x134],ebx
    cmp    edi,0xffffffff
    ja     Branch92
    cmp    edi,ebx
    jbe    Branch92
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x12c]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,edi
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x12c
    ret    0x8
  Branch92:
    lea    eax,[esp+0xe]
    push   ebx
    push   eax
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x13c],0x1
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x1c],ebx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    edi,R6GameServiceAddresses::s_basic_string
    or     ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0xe]
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0xf]
    add    ecx,R6GameServiceAddresses::s_basic_string
    push   eax
    push   ecx
    push   R6GameServiceAddresses::s_basic_string
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x140],0x2
    mov    BYTE PTR [esp+0x1b],dl
    call   R6GameServiceAddresses::ConstructByteStringRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x134],0x3
    call   R6GameServiceAddresses::exception_exception2
    mov    ecx,DWORD PTR [esp+0x10]
    push   0x100
    lea    edx,[esp+0x30]
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::Named_exception__STLVTable
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    lea    eax,[esp+0x20]
    mov    BYTE PTR [esp+0x12b],bl
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::length_error__STLVTable
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Clears three pointer words in order, returning receiver EAX and zero ECX; ignores one callee-popped stack word.
// R6GameService.dll @ 1002cd60 : native control/access order and raw ABI retained.
void * __thiscall InitializePointerTriplet(void *triplet,void *unusedByte)
{
  auto *words = static_cast<uint *>(triplet);
  words[0] = 0;
  words[1] = 0;
  words[2] = 0;
  return triplet;
}

// Allocates range length plus NUL from small pool or heap, publishes descriptor then copies and terminates.
// Cached length and late last argument gate, unchecked NULL allocation and raw memmove-derived end remain native.
// R6GameService.dll @ 10028790 : native control/access order and raw ABI retained.
__declspec(naked) byte * __thiscall ConstructByteStringRange(void *triplet,void *first,void *last,void *unusedTag)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    sub    edi,ebp
    mov    esi,ecx
    lea    ebx,[edi+0x1]
    cmp    ebx,0xffffffff
    ja     Branch94
    test   ebx,ebx
    jbe    Branch94
    cmp    ebx,0x80
    push   ebx
    jbe    Branch93
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch95
  Branch93:
    call   R6GameServiceAddresses::AllocateSmallByteStringBlock
    add    esp,0x4
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch95
  Branch94:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
  Branch95:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi]
    cmp    ecx,ebp
    je     Branch96
    push   edi
    push   ebp
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch96:
    mov    DWORD PTR [esi+0x4],eax
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax],0x0
    pop    ebx
    ret    0xc
  }
}

// Forwards saved receiver+8 to native no-op without releasing its published allocation.
// R6GameService.dll @ 10065c30 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindTripletAllocatorContext(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x11c]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Forwards inherited local tag byte address to native no-op.
// R6GameService.dll @ 10065c3e : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindTripletDiagnosticTag(void)
{
  __asm {
    lea    ecx,[ebp-0x12a]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases partially constructed diagnostic triplet through actual shared pooled/heap release.
// R6GameService.dll @ 10065c49 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindTripletPartialDiagnostic(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Releases completed diagnostic triplet through actual shared pooled/heap release.
// R6GameService.dll @ 10065c54 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindTripletCompleteDiagnostic(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects five-state triplet construction FuncInfo and tails to external Windows frame dispatch.
// R6GameService.dll @ 10065c5f : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTripletBufferLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructByteTripletBufferExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ff74 : exact triplet-buffer construction lifetime words.
const R6GameServiceNative::UnwindEntry ConstructByteTripletBufferUnwindMap[5] = {
  {-1, R6GameServiceAddresses::UnwindTripletAllocatorContext},
  {0x0, R6GameServiceAddresses::UnwindTripletDiagnosticTag},
  {0x1, R6GameServiceAddresses::UnwindTripletPartialDiagnostic},
  {0x1, R6GameServiceAddresses::UnwindTripletCompleteDiagnostic},
  {0x1, 0x0},
};

// R6GameService.dll data @ 1007ff9c : exact triplet-buffer construction lifetime words.
// R6GameService.dll data @ 1007ff74 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructByteTripletBufferExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::ConstructByteTripletBufferUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Construct a fresh heap string from cached NUL-terminated input; previous destination storage is not released.
// Clears the triplet before scanning, publishes allocation before memmove, then writes returned end and NUL.
// ENTRY ESP frame: saved destination-128, pooled diagnostic-124, length_error object-118, state-4.
// Physical unused context word and RET8 retained. Length-error branch and four mapped actions are literal;
// ordinary REPNE cannot yield the size-zero case, but the native branch and throw path remain represented.
// R6GameService.dll @ 10055c60 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructHeapByteStringFromCString(
    void *destination,char *text,void *unusedContext)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCStringConstructorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x124
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    xor    edx,edx
    push   edi
    mov    DWORD PTR [esi],edx
    mov    DWORD PTR [esi+0x4],edx
    mov    DWORD PTR [esp+0x18],esi
    mov    DWORD PTR [esi+0x8],edx
    mov    ebp,DWORD PTR [esp+0x144]
    or     ecx,0xffffffff
    mov    edi,ebp
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    DWORD PTR [esp+0x13c],edx
    mov    edi,ecx
    add    edi,ebp
    mov    ebx,edi
    sub    ebx,ebp
    mov    DWORD PTR [esp+0x14],ebx
    inc    ebx
    cmp    ebx,0xffffffff
    ja     Branch98
    cmp    ebx,edx
    jbe    Branch98
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+ebx*1]
    cmp    edi,ebp
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    je     Branch97
    mov    edi,DWORD PTR [esp+0x14]
    push   edi
    push   ebp
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch97:
    mov    ecx,DWORD PTR [esp+0x134]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x130
    ret    0x8
  Branch98:
    lea    edx,[esp+0x13]
    lea    ecx,[esp+0x1c]
    push   edx
    mov    BYTE PTR [esp+0x140],0x1
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    edi,R6GameServiceAddresses::s_basic_string
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x13c],0x2
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::s_basic_string
    push   ecx
    push   R6GameServiceAddresses::s_basic_string
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::InitializeByteStringFromRange
    lea    eax,[esp+0x1c]
    lea    ecx,[esp+0x28]
    push   eax
    mov    BYTE PTR [esp+0x140],0x3
    call   R6GameServiceAddresses::ConstructException75c10
    lea    ecx,[esp+0x28]
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   ecx
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::length_error__STLVTable
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Release the current first word of the saved destination in the parent ENTRY ESP frame.
// R6GameService.dll @ 100691c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructHeapByteStringFromCStringUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x128]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Forward the parent local context to its genuine empty cleanup.
// R6GameService.dll @ 100691cb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructHeapByteStringFromCStringUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x12d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release the current pooled diagnostic descriptor, then continue at parent state one.
// R6GameService.dll @ 100691d6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructHeapByteStringFromCStringUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Release the same pooled diagnostic from the completed-construction state, skipping state two.
// R6GameService.dll @ 100691e1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructHeapByteStringFromCStringUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Select the four-state C-string constructor metadata and tail current CRT dispatch.
// R6GameService.dll @ 100691ec : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectCStringConstructorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructHeapByteStringFromCStringExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal C-string constructor unwind map or FuncInfo; previous states and action addresses retained.
// R6GameService.dll data @ 10083c28 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructHeapByteStringFromCStringUnwindMap[4] = {
  {-1, R6GameServiceAddresses::ConstructHeapByteStringFromCStringUnwind1},
  {0x0, R6GameServiceAddresses::ConstructHeapByteStringFromCStringUnwind2},
  {0x1, R6GameServiceAddresses::ConstructHeapByteStringFromCStringUnwind3},
  {0x1, R6GameServiceAddresses::ConstructHeapByteStringFromCStringUnwind4},
};

// Literal C-string constructor unwind map or FuncInfo; previous states and action addresses retained.
// R6GameService.dll data @ 10083c28 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructHeapByteStringFromCStringExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ConstructHeapByteStringFromCStringUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
