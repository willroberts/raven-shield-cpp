#include "native_addresses.h"
#include "descriptor_fields.h"
#include "native_records.h"

// R6GameService.dll data @ 1008009c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo LongIndentExceptionHandlerFunctionInfo;

namespace R6GameServiceNative {
// clDataLong +0x10, interpreted signed only by the native text/printf paths.
struct LongSignedValue {
  int value;
};

// clDataLong +0x0c: encoded word followed by ordinal-14's full conversion result.
struct LongValueWords {
  unsigned int encoded;
  unsigned int converted;
};
} // namespace R6GameServiceNative

// Scalar indentation locals span logical EBP-0x40..-4; numberText occupies exactly EBP-0x2c..-0x0d.
struct LongIndentFrame {
  byte spaceOrNumberTag;
  byte padding[5];
  byte closingTag;
  byte constructorTag;
  uint spaces[3];
  char numberText[32];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Prints the converted signed word at +0x10 as " L%d ", retaining printf's signed character count.
// R6GameService.dll @ 1002aeb0 : ECX clDataLong, no stack arguments; primary vtable10076b1c slot0x10.
int __fastcall PrintClDataLong(void *object)
{
  auto *scalar = reinterpret_cast<R6GameServiceNative::LongSignedValue *>(static_cast<byte *>(object) + 0x10);
  return printf((char *)R6GameServiceAddresses::TextLD,scalar->value);
}

// Appends " L", the converted signed decimal value and a space, returning the final append's raw EAX.
// R6GameService.dll @ 1002aed0 : ECX clDataLong, destination stack word, RET4; 32-byte number buffer, no EH frame.
void * __thiscall AppendClDataLongText(void *object,uint outputWord)
{
  auto *scalar = reinterpret_cast<R6GameServiceNative::LongSignedValue *>(static_cast<byte *>(object) + 0x10);
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
  void *destination = (void *)outputWord;
  byte prefixTag = *(byte *)&outputWord;
  char numberText[32];
  char *prefix = (char *)R6GameServiceAddresses::TextL;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)prefix,(undefined1 *)scannedEnd(prefix),&prefixTag);
  sprintf(numberText,(char *)R6GameServiceAddresses::TextSignedDecimalFormat,scalar->value);
  byte numberTag = *(byte *)&outputWord;
  *(byte *)&outputWord = numberTag;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)numberText,(undefined1 *)scannedEnd(numberText),(undefined1 *)&outputWord);
  byte closingTag = *(byte *)&outputWord;
  char *closing = (char *)R6GameServiceAddresses::WideTextSpace2;
  return AppendByteRangePreservingNul(
      destination,(undefined1 *)closing,(undefined1 *)scannedEnd(closing),&closingTag);
}

// Reports the scalar's four-byte serialized size.
// R6GameService.dll @ 1002af90 : MOV EAX,4/RET; clDataLong primary vtable slot0x14, ECX unused.
uint __fastcall GetClDataLongByteSize(void *object)
{
  return 4;
}

// Appends spaces followed by Long->{signed decimal} and newline, then returns the temporary release's raw EAX.
// R6GameService.dll @ 1002bc20 : ECX clDataLong, destination/indent-count stack words, RET8.
uint __thiscall AppendClDataLongIndentedText(void *object,uint outputWord,uint indentWord)
{
  auto *scalar = reinterpret_cast<R6GameServiceNative::LongSignedValue *>(static_cast<byte *>(object) + 0x10);
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
  LongIndentFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)LongIndentExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.state = 0;
  frame.spaceOrNumberTag = 0x20;
  frame.spaces[0] = 0;
  frame.spaces[1] = 0;
  StoreFirstWordIgnoringContext(frame.spaces + 2,(uint)&frame.constructorTag,0);
  uint indentBytes = indentWord;
  *(byte *)&frame.state = 1;
  InitializeHeapByteString(frame.spaces,(int)(indentBytes + 1));
  *(byte *)&frame.state = 2;
  frame.spaces[1] = (uint)FillByteRangeAndReturnEnd(
      (undefined1 *)frame.spaces[0],indentBytes,&frame.spaceOrNumberTag);
  *(byte *)frame.spaces[1] = 0;
  void *destination = (void *)outputWord;
  byte indentTag = *(byte *)&indentWord;
  *(byte *)&indentWord = indentTag;
  *(byte *)&frame.state = 4;
  AppendByteRangeWithGrowth(destination,
      (undefined1 *)frame.spaces[0],(undefined1 *)frame.spaces[1],(uint)&indentWord);
  char *prefix = (char *)R6GameServiceAddresses::TextLong;
  *(byte *)&outputWord = *(byte *)&indentWord;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)prefix,(undefined1 *)scannedEnd(prefix),(undefined1 *)&outputWord);
  sprintf(frame.numberText,(char *)R6GameServiceAddresses::TextSignedDecimalFormat,scalar->value);
  frame.spaceOrNumberTag = *(byte *)&indentWord;
  AppendByteRangePreservingNul(destination,(undefined1 *)frame.numberText,
      (undefined1 *)scannedEnd(frame.numberText),&frame.spaceOrNumberTag);
  frame.closingTag = *(byte *)&indentWord;
  char *closing = (char *)R6GameServiceAddresses::TextPunctuation2;
  AppendByteRangePreservingNul(
      destination,(undefined1 *)closing,(undefined1 *)scannedEnd(closing),&frame.closingTag);
  uint result = TailFreeThroughGlobalAllocator((void *)frame.spaces[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Stores the encoded word at +0x0c and ordinal-14's converted word at +0x10, retaining the conversion's EAX.
// R6GameService.dll @ 1002bd90 : ECX clDataLong, encoded stack word, RET4.
uint __thiscall SetClDataLongEncodedValue(void *object,uint encodedValue)
{
  auto *values = reinterpret_cast<R6GameServiceNative::LongValueWords *>(static_cast<byte *>(object) + 0x0c);
  uint convertedValue = Ordinal_14(encodedValue);
  values->encoded = encodedValue;
  values->converted = convertedValue;
  return convertedValue;
}

// Forwards the constructor tag to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065cc0 : inherited EBP; LEA ECX,[EBP-0x39], JMP10059130.
__declspec(naked) void __cdecl CleanupLongIndentConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp-0x39]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Forwards the temporary capacity-word context to empty cleanup, retaining EAX.
// R6GameService.dll @ 10065cc8 : inherited EBP; LEA ECX,[EBP-0x30], JMP10059130.
__declspec(naked) void __cdecl CleanupLongIndentCapacityContext(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the temporary spaces buffer through its first-word cleanup helper.
// R6GameService.dll @ 10065cd0 : inherited EBP; LEA ECX,[EBP-0x38], JMP10041530.
__declspec(naked) void __cdecl ReleaseLongIndentSpaces(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the same spaces buffer for the later unwind states.
// R6GameService.dll @ 10065cd8 : inherited EBP; LEA ECX,[EBP-0x38], JMP10041530.
__declspec(naked) void __cdecl ReleaseLongIndentSpacesLate(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the scalar indentation parent's five-state unwind metadata.
// R6GameService.dll @ 10065ce0 : EAX=1008009c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl LongIndentExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::LongIndentExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: clDataLongVTable
// R6GameService.dll data @ 10076b1c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clDataLongVTableRecord {
  R6GameServiceNative::Address DeleteTrivialScalarDescriptor; // +0x00
  R6GameServiceNative::Address AppendClDataLongIndentedText; // +0x04
  R6GameServiceNative::Address ForwardToDescriptorSlot04; // +0x08
  R6GameServiceNative::Address AppendClDataLongText; // +0x0c
  R6GameServiceNative::Address PrintClDataLong; // +0x10
  R6GameServiceNative::Address GetClDataLongByteSize; // +0x14
};
const clDataLongVTableRecord clDataLongVTable = {
  R6GameServiceAddresses::DeleteTrivialScalarDescriptor,
  R6GameServiceAddresses::AppendClDataLongIndentedText,
  R6GameServiceAddresses::ForwardToDescriptorSlot04,
  R6GameServiceAddresses::AppendClDataLongText,
  R6GameServiceAddresses::PrintClDataLong,
  R6GameServiceAddresses::GetClDataLongByteSize,
};
