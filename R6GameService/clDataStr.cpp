#include "native_addresses.h"
#include "descriptor_fields.h"

// Destroys clDataStr, optionally frees its object storage for flag bit zero, and returns the saved receiver.
// R6GameService.dll @ 1002ac50 : ECX object, flags stack word, RET 4.
void * __thiscall DeleteClDataStr(void *object,byte flags)
{
  DestroyClDataStr(object);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(object);
  return object;
}

// Publishes string/base vtables around an unconditional buffer release, retaining the release's raw EAX.
// R6GameService.dll @ 1002ac70 : ECX object, no stack arguments; the buffer triplet remains unchanged.
uint __fastcall DestroyClDataStr(void *object)
{
  auto *payloadField = reinterpret_cast<R6GameServiceNative::StringPayload *>(static_cast<byte *>(object) + 0x0c);
  *(uint *)object = (uint)&clDataStrPTR_FUN;
  uint result = TailFreeThroughGlobalAllocator(reinterpret_cast<void *>(payloadField->text));
  *(uint *)object = (uint)&PTR_LAB;
  return result;
}

// Tail-forwards string destruction with the same receiver, stack and raw return register.
// R6GameService.dll @ 1002ac90 : ECX object, no stack arguments; JMP1002ac70.
__declspec(naked) uint __fastcall DestroyClDataStrAlias(void *object)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClDataStr
  }
}

// Appends the stored NUL-terminated bytes between quotes followed by a space, returning the destination triplet.
// R6GameService.dll @ 1002aba0 : ECX string descriptor, destination stack word, RET 4.
void * __thiscall AppendClDataStrQuotedText(void *object,uint outputWord)
{
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
  void *appended = AppendDescriptorCString(destination,(int)object);
  byte localTag = *(byte *)&outputWord;
  *(byte *)&outputWord = localTag;
  char *closingText = (char *)R6GameServiceAddresses::TextPunctuation;
  return AppendByteRangePreservingNul(
      appended,(undefined1 *)closingText,(undefined1 *)(closingText + strlen(closingText)),(undefined1 *)&outputWord);
}

// Appends spaces and String->{payload} plus newline, then returns the temporary buffer release's raw EAX.
// R6GameService.dll @ 1002b370 : ECX clDataStr, destination/indent-count stack words, RET 8.
uint __thiscall AppendClDataStrIndentedText(void *object,uint outputWord,uint indentWord)
{
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
  char *header = (char *)R6GameServiceAddresses::TextString;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)header,(undefined1 *)scannedEnd(header),(undefined1 *)&outputWord);
  void *appended = AppendDescriptorCString(destination,(uint)object);
  frame.spaceOrPayloadTag = *(byte *)&indentWord;
  char *closing = (char *)R6GameServiceAddresses::TextPunctuation2;
  AppendByteRangePreservingNul(
      appended,(undefined1 *)closing,(undefined1 *)scannedEnd(closing),&frame.spaceOrPayloadTag);
  uint result = TailFreeThroughGlobalAllocator((void *)frame.spaces[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}
