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

// Tail-forwards binary descriptor destruction with the same receiver, stack and raw EAX result.
// R6GameService.dll @ 1002ab70 : ECX object, no stack arguments; JMP1002ab50.
__declspec(naked) uint __fastcall DestroyClDataBinAlias(void *object)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClDataBin
  }
}

// Resets end to begin, replaces bytes with repeated capacity growth, and returns the advanced source word.
// R6GameService.dll @ 1002ba80 : complete native accesses, scratch/argument order and raw register results.
__declspec(naked) const byte * __thiscall ReplaceClDataBinBytes(void *value,const byte *source,uint byteCount)
{
  __asm {
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    push   edi
    mov    eax,DWORD PTR [esi+0x10]
    mov    ecx,DWORD PTR [esi+0xc]
    // The self-compare makes the following old-tail copy block unreachable; retain its native identity.
    cmp    eax,eax
    jne Branch1
    mov    eax,ecx
    jmp Branch2
  Branch1:
    mov    edi,eax
    sub    edi,eax
    push   edi
    push   eax
    push   ecx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
    // Read count, reset end, then load source; cache source end at EntryESP-4 and occupied length at-8.
  Branch2:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi+0x10],eax
    mov    eax,DWORD PTR [esp+0x14]
    add    ecx,eax
    mov    DWORD PTR [esp+0x14],eax
    cmp    eax,ecx
    mov    DWORD PTR [esp+0xc],ecx
    je Branch10
    push   ebx
    push   ebp
  Branch3:
    mov    ebp,DWORD PTR [esi+0x10]
    mov    edx,DWORD PTR [esi+0x14]
    cmp    ebp,edx
    je Branch5
    // A null nonfull end skips even the source-byte read but still increments the current end field.
    test   ebp,ebp
    je Branch4
    mov    dl,BYTE PTR [eax]
    mov    BYTE PTR [ebp+0x0],dl
  Branch4:
    inc    DWORD PTR [esi+0x10]
    jmp Branch9
  Branch5:
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,ebp
    sub    eax,edx
    // Reuse original count as constant1 and select occupied+max(occupied,1) with unsigned wraparound.
    mov    DWORD PTR [esp+0x20],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x20]
    jb Branch6
    lea    ecx,[esp+0x10]
  Branch6:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    // Reload current begin after allocation while retaining the old end cached before allocation.
    mov    eax,DWORD PTR [esi+0xc]
    cmp    ebp,eax
    jne Branch7
    mov    eax,ebx
    jmp Branch8
  Branch7:
    sub    ebp,eax
    push   ebp
    push   eax
    push   ebx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebp
    // Reload the original source argument after copying, write one byte, then reload current begin to free it.
  Branch8:
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    ebp,[eax+0x1]
    mov    dl,BYTE PTR [ecx]
    mov    BYTE PTR [eax],dl
    mov    eax,DWORD PTR [esi+0xc]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    // Reload source iterator and saved end after free; publish begin/end/capacity before advancing source.
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esi+0xc],ebx
    add    ebx,edi
    mov    DWORD PTR [esi+0x10],ebp
    mov    DWORD PTR [esi+0x14],ebx
  Branch9:
    inc    eax
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x1c],eax
    jne Branch3
    pop    ebp
    pop    ebx
  Branch10:
    pop    edi
    pop    esi
    add    esp,0x8
    ret    0x8
  }
}
