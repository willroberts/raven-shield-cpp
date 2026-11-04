#include "native_addresses.h"
#include "descriptor_fields.h"

// Inferred declaration: virtual uint clData::GetByteCount(), at primary slot +0x14.
// Native descriptor tables establish this dispatch contract; the complete clData declaration remains unresolved.

// Native formatter locals occupy 0x2c bytes above saved ESI/EDI; the general-size path also saves EBX.
struct ClDataBinTextLocals {
  byte padding[3];
  byte rangeTag;
  signed char byteValue;
  byte textTag;
  short wordValue;
  int dwordValue;
  char numberText[32];
};

// Appends signed scalar text for one/two/four-byte values and a virtual byte-count summary for other lengths.
// R6GameService.dll @ 1002b6f0 : ECX binary descriptor, destination stack word, RET 4; EAX=destination.
void * __thiscall AppendClDataBinText(void *object,void *destination)
{
  auto *bytes = reinterpret_cast<R6GameServiceNative::ByteRange *>(static_cast<byte *>(object) + 0x0c);
  ClDataBinTextLocals frame;
  uint length = bytes->end - bytes->begin;
  auto appendLocalTag = [&](char *text,const void *tag) {
    return AppendByteRangeWithLocalTag(
        destination,(undefined1 *)text,(undefined1 *)(text + strlen(text)),tag);
  };
  auto appendTag = [&](char *text,byte *tag) {
    return AppendByteRangePreservingNul(
        destination,(undefined1 *)text,(undefined1 *)(text + strlen(text)),tag);
  };
  if (length == 4) {
    byte *begin = reinterpret_cast<byte *>(bytes->begin);
    MoveByteRange(begin,(void *)((uint)begin + 4),&frame.dwordValue);
    frame.rangeTag = (byte)(uint)destination;
    appendTag((char *)&BinaryValueTextPrefix,&frame.rangeTag);
    sprintf(frame.numberText,&TextSignedDecimalFormat,frame.dwordValue);
    appendLocalTag(frame.numberText,&frame.textTag);
    *(byte *)&destination = *(byte *)&destination;
    return appendTag((char *)&WideTextSpace2,(byte *)&destination);
  }
  if (length == 2) {
    byte *begin = reinterpret_cast<byte *>(bytes->begin);
    MoveByteRange(begin,(void *)((uint)begin + 2),&frame.wordValue);
    appendLocalTag((char *)&BinaryValueTextPrefix,&destination);
    sprintf(frame.numberText,&TextSignedDecimalFormat,(int)frame.wordValue);
    appendLocalTag(frame.numberText,&frame.textTag);
    return appendLocalTag((char *)&WideTextSpace2,&frame.rangeTag);
  }
  if (length == 1) {
    frame.rangeTag = (byte)(uint)destination;
    byte *begin = reinterpret_cast<byte *>(bytes->begin);
    CopyByteRange(begin,(void *)((uint)begin + 1),&frame.byteValue,&frame.rangeTag);
    appendLocalTag((char *)&BinaryValueTextPrefix,&destination);
    sprintf(frame.numberText,&TextSignedDecimalFormat,(int)frame.byteValue);
    appendLocalTag(frame.numberText,&frame.textTag);
    return appendLocalTag((char *)&WideTextSpace2,&frame.rangeTag);
  }
  frame.rangeTag = (byte)(uint)destination;
  appendTag((char *)&BinarySummaryTextPrefix,&frame.rangeTag);
  uint displayedLength = static_cast<clData *>(object)->GetByteCount();
  sprintf(frame.numberText,&UnsignedByteCountFormat,displayedLength);
  appendLocalTag(frame.numberText,&frame.textTag);
  *(byte *)&destination = *(byte *)&destination;
  return appendTag((char *)&BinarySummaryTextSuffix,(byte *)&destination);
}

// Native scalar print slots: byte at +1, word at +2, dword at +4 in an eight-byte local allocation.
struct ClDataBinPrintLocals {
  byte padding;
  signed char byteValue;
  short wordValue;
  int dwordValue;
};

// Prints signed scalar values for one/two/four bytes and a physical byte-count summary otherwise.
// R6GameService.dll @ 1002b9b0 : ECX binary descriptor, no stack arguments; EAX is the printf result.
uint __fastcall PrintClDataBin(void *object)
{
  auto *bytes = reinterpret_cast<R6GameServiceNative::ByteRange *>(static_cast<byte *>(object) + 0x0c);
  ClDataBinPrintLocals frame;
  byte *begin = reinterpret_cast<byte *>(bytes->begin);
  uint length = bytes->end - (uint)begin;
  if (length == 4) {
    memmove(&frame.dwordValue,begin,4);
    return printf((char *)R6GameServiceAddresses::TextBD,frame.dwordValue);
  }
  if (length == 2) {
    memmove(&frame.wordValue,begin,2);
    return printf((char *)R6GameServiceAddresses::TextBD,(int)frame.wordValue);
  }
  if (length == 1) {
    memmove(&frame.byteValue,begin,1);
    return printf((char *)R6GameServiceAddresses::TextBD,(int)frame.byteValue);
  }
  return printf((char *)R6GameServiceAddresses::TextD,(int)length);
}

// Copies the physical byte range when the caller's capacity fits, then reports virtual size and status AL.
// R6GameService.dll @ 1002bb70 : ECX binary descriptor, output/capacity pointer stack words, RET 8.
uint __thiscall CopyClDataBinBytesToBuffer(void *object,void *output,uint *capacityOrByteCount)
{
  auto *bytes = reinterpret_cast<R6GameServiceNative::ByteRange *>(static_cast<byte *>(object) + 0x0c);
  auto *descriptor = static_cast<clData *>(object);
  uint required = descriptor->GetByteCount();
  if (*capacityOrByteCount < required) {
    uint result = descriptor->GetByteCount();
    *capacityOrByteCount = result;
    return result & 0xffffff00;
  }
  uint end = bytes->end;
  uint begin = bytes->begin;
  if (end != begin) memmove(output,(void *)begin,end - begin);
  uint result = descriptor->GetByteCount();
  *capacityOrByteCount = result;
  return (result & 0xffffff00) | 1;
}

// Assigns a source triplet's bytes into the binary object, retaining capacity when it fits.
// R6GameService.dll @ 1002b630 : ECX binary object, source-triplet stack word, RET 4; raw EAX is path-dependent.
uint __thiscall AssignClDataBinByteRange(void *object,uint *sourceTriplet)
{
  uint adjustedDestination = object == nullptr ? 0 : (uint)object + 0x0c;
  if ((uint)sourceTriplet == adjustedDestination) return adjustedDestination;
  uint *destinationTriplet = (uint *)((uint)object + 0x0c);
  if (sourceTriplet == destinationTriplet) return adjustedDestination;
  uint sourceEnd = sourceTriplet[1];
  uint sourceCursor = sourceTriplet[0];
  uint destinationCursor = destinationTriplet[0];
  uint sourceLength = sourceEnd - sourceCursor;
  uint availableBytes = destinationTriplet[2] - destinationCursor;
  if (sourceLength > availableBytes) {
    void *replacement = AllocateAndCopyByteRange(sourceLength,(void *)sourceCursor,(void *)sourceEnd);
    uint result = TailFreeThroughGlobalAllocator((void *)destinationTriplet[0]);
    destinationTriplet[0] = (uint)replacement;
    uint newEnd = destinationTriplet[0] + sourceLength;
    destinationTriplet[2] = (uint)replacement + sourceLength;
    destinationTriplet[1] = newEnd;
    return result;
  }
  uint oldLength = destinationTriplet[1] - destinationCursor;
  if (oldLength < sourceLength) {
    uint prefixEnd = sourceCursor + oldLength;
    if (prefixEnd != sourceCursor) memmove((void *)destinationCursor,(void *)sourceCursor,prefixEnd - sourceCursor);
    destinationCursor = destinationTriplet[1];
    sourceEnd = sourceTriplet[1];
    sourceCursor = destinationCursor - destinationTriplet[0] + sourceTriplet[0];
  }
  uint result = sourceCursor;
  if (sourceEnd != sourceCursor) result = (uint)memmove((void *)destinationCursor,(void *)sourceCursor,sourceEnd - sourceCursor);
  destinationTriplet[1] = destinationTriplet[0] + sourceLength;
  return result;
}

// Destroys the binary descriptor, optionally frees its object storage for flag bit zero, and returns the receiver.
// R6GameService.dll @ 1002ab30 : ECX object, flags stack word, RET 4.
void * __thiscall DeleteClDataBin(void *object,byte flags)
{
  DestroyClDataBin(object);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(object);
  return object;
}

// Publishes binary/base vtables around a nonnull buffer release; leaves the triplet and allocator words unchanged.
// R6GameService.dll @ 1002ab50 : ECX object, no stack arguments; EAX=0 or the allocator's raw release result.
uint __fastcall DestroyClDataBin(void *object)
{
  auto *bytes = reinterpret_cast<R6GameServiceNative::ByteRange *>(static_cast<byte *>(object) + 0x0c);
  *(uint *)object = (uint)&clDataBinPTR_FUN;
  void *buffer = reinterpret_cast<void *>(bytes->begin);
  uint result = (uint)buffer;
  if (buffer != nullptr) result = TailFreeThroughGlobalAllocator(buffer);
  *(uint *)object = (uint)&PTR_LAB;
  return result;
}

// Forward binary descriptor destruction and preserve its full-word cleanup result.
// R6GameService.dll @ 1002ab70 : native tail alias with receiver in ECX and no stack arguments.
uint __fastcall DestroyClDataBinAlias(void *object)
{
  using DestroyABI = uint (__fastcall *)(void *);
  return ((DestroyABI)R6GameServiceAddresses::DestroyClDataBin)(object);
}

// Resets the buffer, copies bytes with repeated growth and returns the advanced source; saved arguments remain live.
// R6GameService.dll @ 1002ba80 : ECX owner, source/count stack words; local names are inferred, RET8.
const byte * __thiscall ReplaceClDataBinBytes(void *value,const byte *source,uint byteCount)
{
  auto *triplet = (R6GameServiceNative::ByteRange *)((uint)value + 0xc);
  uint end = triplet->end;
  uint begin = triplet->begin;
  // The retail self-comparison excludes the old-tail move block.
  end = begin;
  uint count = byteCount;
  triplet->end = end;
  uint cursor = (uint)source;
  uint limit = cursor + count;
  source = (const byte *)cursor;
  uint savedSourceEnd = limit;
  if (cursor == limit) return (const byte *)cursor;
  do {
    end = triplet->end;
    uint capacity = triplet->capacityEnd;
    if (end != capacity) {
      if (end != 0) {
        byte character = *(byte *)cursor;
        *(byte *)end = character;
      }
      ++triplet->end;
    } else {
      uint occupiedBytes = end - triplet->begin;
      byteCount = 1;
      uint *growth = occupiedBytes < 1 ? &byteCount : &occupiedBytes;
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
      uint currentSource = (uint)source;
      uint newEnd = writeAt + 1;
      byte character = *(byte *)currentSource;
      *(byte *)writeAt = character;
      uint releaseBegin = triplet->begin;
      TailFreeThroughGlobalAllocator((void *)releaseBegin);
      cursor = (uint)source;
      limit = savedSourceEnd;
      triplet->begin = replacement;
      triplet->end = newEnd;
      triplet->capacityEnd = replacement + allocationBytes;
    }
    ++cursor;
    source = (const byte *)cursor;
  } while (cursor != limit);
  return (const byte *)cursor;
}
