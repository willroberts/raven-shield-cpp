#include "native_addresses.h"
#include "descriptor_fields.h"
#include "native_records.h"

// Appends spaces and StringRef->{payload} plus newline, retaining the final temporary release's raw EAX.
// R6GameService.dll @ 1002b4e0 : ECX clDataStrRef, destination/indent-count stack words, RET 8.
uint __thiscall AppendClDataStrRefIndentedText(void *object,uint outputWord,uint indentWord)
{
  auto *payloadField = reinterpret_cast<R6GameServiceNative::StringPayload *>(static_cast<byte *>(object) + 0x0c);
  auto scannedEnd = [](char *first) {
    uint remaining = 0xffffffff;
    char *scan = first;
    while (remaining != 0) {
      --remaining;
      char character = *scan++;
      if (character == 0) break;
    }
    return (char *)((uint)first + (~remaining - 1));
  };
  StringIndentFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)StringIndentExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.state = 0;
  frame.spaceOrPayloadTag = 0x20;
  frame.spaces[0] = 0;
  frame.spaces[1] = 0;
  StoreFirstWordIgnoringContext(frame.spaces + 2,(uint)&frame.constructorTag,0);
  uint indentBytes = indentWord;
  *(byte *)&frame.state = 1;
  InitializeHeapByteString(frame.spaces,(int)(indentBytes + 1));
  *(byte *)&frame.state = 2;
  frame.spaces[1] = (uint)FillByteRangeAndReturnEnd(
      (undefined1 *)frame.spaces[0],indentBytes,&frame.spaceOrPayloadTag);
  *(byte *)frame.spaces[1] = 0;
  byte indentTag = *(byte *)&indentWord;
  *(byte *)&indentWord = indentTag;
  void *destination = (void *)outputWord;
  *(byte *)&frame.state = 4;
  AppendByteRangeWithGrowth(
      destination,(undefined1 *)frame.spaces[0],(undefined1 *)frame.spaces[1],(uint)&indentWord);
  byte headerTag = *(byte *)&indentWord;
  *(byte *)&outputWord = headerTag;
  char *header = (char *)R6GameServiceAddresses::TextStringRef;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)header,(undefined1 *)scannedEnd(header),(undefined1 *)&outputWord);
  byte payloadTag = *(byte *)&indentWord;
  char *payload = reinterpret_cast<char *>(payloadField->text);
  frame.spaceOrPayloadTag = payloadTag;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)payload,(undefined1 *)scannedEnd(payload),&frame.spaceOrPayloadTag);
  frame.closingTag = *(byte *)&indentWord;
  char *closing = (char *)R6GameServiceAddresses::TextPunctuation2;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)closing,(undefined1 *)scannedEnd(closing),&frame.closingTag);
  uint result = TailFreeThroughGlobalAllocator((void *)frame.spaces[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Appends the referenced bytes between quotes followed by a space, preserving the native tag-slot reuse.
// R6GameService.dll @ 1002adb0 : ECX clDataStrRef, destination stack word, RET 4; EAX=destination triplet.
void * __thiscall AppendClDataStrRefQuotedText(void *object,uint outputWord)
{
  auto *payloadField = reinterpret_cast<R6GameServiceNative::StringPayload *>(static_cast<byte *>(object) + 0x0c);
  auto scannedEnd = [](char *first) {
    uint remaining = 0xffffffff;
    char *scan = first;
    while (remaining != 0) {
      --remaining;
      char character = *scan++;
      if (character == 0) break;
    }
    return (char *)((uint)first + (~remaining - 1));
  };
  auto *destination = reinterpret_cast<R6GameServiceNative::ByteRange *>(outputWord);
  uint end = destination->end;
  uint capacityEnd = destination->capacityEnd;
  if (end + 1 == capacityEnd) {
    outputWord = 1;
    uint length = end - destination->begin;
    uint growth = length < 1 ? outputWord : length;
    ReserveByteString(destination,growth + length);
  }
  *(byte *)(destination->end + 1) = 0;
  *(byte *)destination->end = '"';
  destination->end = destination->end + 1;
  byte payloadTag = *(byte *)&outputWord;
  char *payload = reinterpret_cast<char *>(payloadField->text);
  *(byte *)&outputWord = payloadTag;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)payload,(undefined1 *)scannedEnd(payload),(undefined1 *)&outputWord);
  char *closing = (char *)R6GameServiceAddresses::TextPunctuation;
  byte closingTag = *(byte *)&outputWord;
  char *closingEnd = scannedEnd(closing);
  return AppendByteRangePreservingNul(
      destination,(undefined1 *)closing,(undefined1 *)closingEnd,&closingTag);
}

// Counts referenced bytes through NUL with the native unsigned 0xffffffff-byte scan limit.
// R6GameService.dll @ 1002ae70 : ECX clDataStrRef, no stack arguments; EAX=byte count excluding NUL.
uint __fastcall GetClDataStrRefTextLength(void *object)
{
  auto *payloadField = reinterpret_cast<R6GameServiceNative::StringPayload *>(static_cast<byte *>(object) + 0x0c);
  char *scan = reinterpret_cast<char *>(payloadField->text);
  uint remaining = 0xffffffff;
  while (remaining != 0) {
    --remaining;
    char character = *scan++;
    if (character == 0) break;
  }
  return ~remaining - 1;
}

// Native virtual-table prefix: clDataStrRefVTable
// R6GameService.dll data @ 10076af8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clDataStrRefVTableRecord {
  R6GameServiceNative::Address DeleteTrivialScalarDescriptor; // +0x00
  R6GameServiceNative::Address AppendClDataStrRefIndentedText; // +0x04
  R6GameServiceNative::Address ForwardToDescriptorSlot04; // +0x08
  R6GameServiceNative::Address AppendClDataStrRefQuotedText; // +0x0c
  R6GameServiceNative::Address PrintQuotedDescriptorString; // +0x10
  R6GameServiceNative::Address GetClDataStrRefTextLength; // +0x14
};
const clDataStrRefVTableRecord clDataStrRefVTable = {
  R6GameServiceAddresses::DeleteTrivialScalarDescriptor,
  R6GameServiceAddresses::AppendClDataStrRefIndentedText,
  R6GameServiceAddresses::ForwardToDescriptorSlot04,
  R6GameServiceAddresses::AppendClDataStrRefQuotedText,
  R6GameServiceAddresses::PrintQuotedDescriptorString,
  R6GameServiceAddresses::GetClDataStrRefTextLength,
};
