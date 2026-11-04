#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100808e0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ByteVectorCopyExceptionHandlerFunctionInfo;

// Shared raw byte-vector/storage helpers; prefix+0 and original template ownership remain opaque.

// Releases current storage at owner+4, then clears begin/end/capacity while retaining the opaque prefix.
// R6GameService.dll @ 100340c0 : complete native control/access order and raw ABI retained.
void __fastcall ReleaseAndResetStorageAt04(int ownerAddress)
{
  uint owner = (uint)ownerAddress;
  void *storage = *(void **)(owner + 4);
  if (storage != 0) FreeThroughGlobalAllocator(storage);
  *(uint *)(owner + 4) = 0;
  *(uint *)(owner + 8) = 0;
  *(uint *)(owner + 0xc) = 0;
}

// Moves a raw byte range through memmove and returns its raw result plus the cached modular byte count.
// R6GameService.dll @ 100340f0 : complete native control/access order and raw ABI retained.
void *__thiscall MoveRangeAndReturnEnd(void *unusedVector,void *sourceBegin,void *sourceEnd,void *destination)
{
  uint count = (uint)sourceEnd - (uint)sourceBegin;
  using MoveABI = void *(__cdecl *)(void *,const void *,uint);
  void *moved = (*(MoveABI *)R6GameServiceAddresses::MSVCR71_memmoveSlot)(destination,sourceBegin,count);
  return (void *)((uint)moved + count);
}

// Copies bytes forward while testing each current destination for null and returns the advanced raw cursor.
// R6GameService.dll @ 10034120 : complete native control/access order and raw ABI retained.
byte * __cdecl CopyByteRangeAndReturnEnd(
    byte *sourceBegin,byte *sourceEnd,byte *destination,uint unusedCallerWord4,uint unusedCallerWord5)
{
  uint output = reinterpret_cast<uint>(destination);
  while (sourceBegin != sourceEnd) {
    if (output != 0) *reinterpret_cast<byte *>(output) = *sourceBegin;
    ++output;
    ++sourceBegin;
  }
  return reinterpret_cast<byte *>(output);
}

// Pops four trailing bytes into a big-endian word, retaining native end publications and argument-slot scratch writes.
// R6GameService.dll @ 10034550 : cdecl owner word becomes length scratch; cached owner and begin stay fixed.
uint __cdecl PopTrailingBigEndianDword(void *vector)
{
  uint owner = (uint)vector;
  uint begin = *(uint *)(owner + 4);
  if (begin == 0) return 0;
  uint end = *(uint *)(owner + 8);
  uint length = end - begin;
  if (length < 4) return 0;
  uint output = *(byte *)(end - 1);
  if (length != 0) *(uint *)(owner + 8) = end - 1;
  end = *(uint *)(owner + 8);
  output |= (uint)*(byte *)(end - 1) << 8;
  length = end - begin;
  vector = (void *)length;
  if (length != 0) *(uint *)(owner + 8) = end - 1;
  end = *(uint *)(owner + 8);
  output |= (uint)*(byte *)(end - 1) << 16;
  length = end - begin;
  vector = (void *)length;
  if (length != 0) *(uint *)(owner + 8) = end - 1;
  end = *(uint *)(owner + 8);
  output |= (uint)*(byte *)(end - 1) << 24;
  length = end - begin;
  vector = (void *)length;
  if (length != 0) *(uint *)(owner + 8) = end - 1;
  return output;
}

// Constructs a byte-vector copy with cached allocation size, late source reloads and native partial-publication timing.
// R6GameService.dll @ 10034610 : complete native control/access order and raw ABI retained.
void *__thiscall CopyByteVector(void *destination,const void *sourceVector)
{
  uint owner = (uint)destination;
  uint source = (uint)sourceVector;
  uint begin = *(uint *)(source + 4);
  uint count = begin == 0 ? 0 : *(uint *)(source + 8) - begin;
  *(uint *)(owner + 4) = 0;
  *(uint *)(owner + 8) = 0;
  *(uint *)(owner + 0xc) = 0;
  if (count != 0) {
    if (count > 0xffffffffu) ThrowVectorLengthException();
    uint allocation = (uint)AllocateTaggedBytesCdecl(count);
    uint ignoredSource = (uint)sourceVector;
    *(uint *)(owner + 4) = allocation;
    *(uint *)(owner + 8) = allocation;
    *(uint *)(owner + 0xc) = allocation + count;
    uint sourceEnd = *(uint *)(source + 8);
    uint sourceBegin = *(uint *)(source + 4);
    try {
      byte *end = CopyByteRangeAndReturnEnd((byte *)sourceBegin,(byte *)sourceEnd,(byte *)allocation,
                                          owner,ignoredSource);
      *(uint *)(owner + 8) = (uint)end;
    } catch (...) {
      ReleaseAndResetStorageAt04((int)owner);
      throw;
    }
  }
  return (void *)owner;
}

// Releases and resets the saved failed copy destination, then forwards the active exception without returning.
// R6GameService.dll @ 100346ab : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseFailedByteVectorCopy(void)
{
  __asm {
    // Catchall inherited EBP: reload saved destination, perform actual340c0 cleanup, noreturn33a16(0,0).
    mov    ecx,DWORD PTR [ebp-0x14]
    call   R6GameServiceAddresses::ReleaseAndResetStorageAt04
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects copy-constructor metadata with its manual cleanup catchall and null unwind actions.
// R6GameService.dll @ 10066470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ByteVectorCopyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ByteVectorCopyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reloads the fill byte for each forward store in a raw half-open range and returns its end.
// R6GameService.dll @ 10034080 : complete native control/access order and raw ABI retained.
byte * __cdecl FillByteRange(byte *first,byte *last,const byte *fillByte)
{
  while (first != last) {
    *first++ = *fillByte;
  }
  return first;
}

// Reloads a supplied byte for each counted store and returns destination plus count modulo32.
// R6GameService.dll @ 10034360 : complete native control/access order and raw ABI retained.
byte *__thiscall FillRepeatedByte(void *unusedVector,byte *destination,uint count,const byte *fillByte)
{
  uint output = (uint)destination;
  uint result = output + count;
  uint remaining = count;
  if (remaining != 0) {
    const byte *value = fillByte;
    do {
      byte fill = *value;
      *(byte *)output = fill;
      ++output;
    } while (--remaining != 0);
  }
  return (byte *)result;
}

// Inserts a cached byte, growing by half or shifting the tail in place; count becomes allocation scratch on growth.
// R6GameService.dll @ 10034390 : complete native control/access order and raw ABI retained.
void __thiscall InsertRepeatedByte(void *vector,byte *position,uint count,const byte *fillByteAddress)
{
  uint owner = (uint)vector;
  byte fill = *fillByteAddress;
  uint begin = *(uint *)(owner + 4);
  *(byte *)&fillByteAddress = fill;
  uint capacity = begin == 0 ? 0 : *(uint *)(owner + 0xc) - begin;
  uint insertionCount = count;
  if (insertionCount == 0) return;
  uint size = begin == 0 ? 0 : *(uint *)(owner + 8) - begin;
  if (insertionCount > 0xffffffffu - size) ThrowVectorLengthException();
  size = begin == 0 ? 0 : *(uint *)(owner + 8) - begin;
  uint required = size + insertionCount;
  using MoveABI = void *(__cdecl *)(void *,const void *,uint);
  if (capacity < required) {
    uint half = capacity >> 1;
    capacity = capacity > 0xffffffffu - half ? 0 : capacity + half;
    size = begin == 0 ? 0 : *(uint *)(owner + 8) - begin;
    required = size + insertionCount;
    if (capacity < required) {
      size = begin == 0 ? 0 : *(uint *)(owner + 8) - begin;
      capacity = size + insertionCount;
    }
    uint allocation = (uint)AllocateTaggedBytesCdecl(capacity);
    uint selectedPosition = (uint)position;
    uint currentBegin = *(uint *)(owner + 4);
    uint prefix = selectedPosition - currentBegin;
    count = allocation;
    void *moved = (*(MoveABI *)R6GameServiceAddresses::MSVCR71_memmoveSlot)(
        (void *)allocation,(void *)currentBegin,prefix);
    byte *suffixDestination = FillRepeatedByte(vector,(byte *)((uint)moved + prefix),insertionCount,
                                               (const byte *)&fillByteAddress);
    uint suffixSize = *(uint *)(owner + 8) - selectedPosition;
    (*(MoveABI *)R6GameServiceAddresses::MSVCR71_memmoveSlot)(
        suffixDestination,(void *)selectedPosition,suffixSize);
    currentBegin = *(uint *)(owner + 4);
    size = currentBegin == 0 ? 0 : *(uint *)(owner + 8) - currentBegin;
    uint newSize = insertionCount + size;
    if (currentBegin != 0) FreeThroughGlobalAllocator((void *)currentBegin);
    uint savedAllocation = count;
    *(uint *)(owner + 0xc) = savedAllocation + capacity;
    *(uint *)(owner + 8) = savedAllocation + newSize;
    *(uint *)(owner + 4) = savedAllocation;
    return;
  }
  uint oldEnd = *(uint *)(owner + 8);
  uint selectedPosition = (uint)position;
  uint tail = oldEnd - selectedPosition;
  if (tail < insertionCount) {
    MoveRangeAndReturnEnd(vector,(void *)selectedPosition,(void *)oldEnd,
                         (void *)(selectedPosition + insertionCount));
    uint currentEnd = *(uint *)(owner + 8);
    uint beyondEnd = selectedPosition - currentEnd + insertionCount;
    FillRepeatedByte(vector,(byte *)currentEnd,beyondEnd,(const byte *)&fillByteAddress);
    currentEnd = *(uint *)(owner + 8) + insertionCount;
    *(uint *)(owner + 8) = currentEnd;
    FillByteRange((byte *)selectedPosition,(byte *)(currentEnd - insertionCount),(const byte *)&fillByteAddress);
    return;
  }
  void *movedEnd = MoveRangeAndReturnEnd(vector,(void *)(oldEnd - insertionCount),(void *)oldEnd,(void *)oldEnd);
  *(uint *)(owner + 8) = (uint)movedEnd;
  uint remainingTail = oldEnd - selectedPosition - insertionCount;
  (*(MoveABI *)R6GameServiceAddresses::MSVCR71_memmoveSlot)(
      (void *)(oldEnd - remainingTail),(void *)selectedPosition,remainingTail);
  FillByteRange((byte *)selectedPosition,(byte *)(selectedPosition + insertionCount),(const byte *)&fillByteAddress);
}

// Initializes byte storage, allocates a nonzero count and reloads the supplied byte for every fill store.
// R6GameService.dll @ 10035f60 : complete native control/access order and raw ABI retained.
void __thiscall InitializeFilledByteVector(void *vector,uint count,const byte *fillByte)
{
  uint owner = (uint)vector;
  uint size = count;
  *(uint *)(owner + 4) = 0;
  *(uint *)(owner + 8) = 0;
  *(uint *)(owner + 0xc) = 0;
  if (size == 0) return;
  if (size > 0xffffffffu) ThrowVectorLengthException();
  uint allocation = (uint)AllocateTaggedBytesCdecl(size);
  *(uint *)(owner + 0xc) = allocation + size;
  *(uint *)(owner + 4) = allocation;
  *(uint *)(owner + 8) = allocation;
  uint output = allocation;
  const byte *value = fillByte;
  uint remaining = size;
  do {
    byte fill = *value;
    *(byte *)output = fill;
    ++output;
  } while (--remaining != 0);
  *(uint *)(owner + 8) = allocation + size;
}
