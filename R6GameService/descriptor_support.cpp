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

// Appends bytes and NUL using occupied+max(occupied,added)+1 growth, retaining native reloads and scratch words.
// R6GameService.dll @ 10018560 : complete register/stack/access order and native raw returns retained.
__declspec(naked) void * __thiscall AppendByteRangeWithGrowth(
    void *triplet,void *first,void *last,uint unusedTag)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x14]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    cmp    ecx,ebp
    push   edi
    je Branch6
    // Cache occupied/added lengths; reject unsigned length overflow before reading capacity.
    mov    ebx,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    sub    ebx,edi
    mov    edi,ebp
    sub    edi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    cmp    edi,0xfffffffe
    ja Branch1
    mov    eax,0xfffffffe
    sub    eax,edi
    cmp    ebx,eax
    jbe Branch2
  Branch1:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    mov    ecx,DWORD PTR [esp+0x1c]
    add    esp,0x4
  Branch2:
    mov    edx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [esi]
    sub    edx,eax
    lea    eax,[edi+ebx*1]
    dec    edx
    cmp    eax,edx
    jbe Branch4
    // Reuse the incoming last-pointer slot for added length while EBP retains the actual source end.
    cmp    ebx,edi
    mov    DWORD PTR [esp+0x1c],edi
    lea    eax,[esp+0x1c]
    jb Branch3
    lea    eax,[esp+0x10]
  Branch3:
    mov    ecx,DWORD PTR [eax]
    lea    ebx,[ecx+ebx*1+0x1]
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Reload old begin/end after allocation; the second copy reloads the original first argument.
    mov    ecx,DWORD PTR [esi]
    mov    edi,eax
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    push   eax
    push   ecx
    call   R6GameServiceAddresses::MoveByteRange
    mov    edx,DWORD PTR [esp+0x18]
    push   eax
    push   ebp
    push   edx
    call   R6GameServiceAddresses::MoveByteRange
    mov    ebp,eax
    mov    BYTE PTR [ebp+0x0],0x0
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    // Publish begin, capacity, then end only after the old buffer has been freed.
    mov    DWORD PTR [esi],edi
    add    edi,ebx
    mov    DWORD PTR [esi+0x8],edi
    mov    DWORD PTR [esi+0x4],ebp
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
    // Move bytes after the first before writing NUL and reloading the first byte.
  Branch4:
    lea    eax,[ecx+0x1]
    cmp    ebp,eax
    je Branch5
    mov    ecx,DWORD PTR [esi+0x4]
    sub    ebp,eax
    push   ebp
    inc    ecx
    push   eax
    push   ecx
    call   R6GameServiceAddresses::memmove
    mov    ecx,DWORD PTR [esp+0x24]
    add    esp,0xc
  Branch5:
    mov    edx,DWORD PTR [esi+0x4]
    mov    BYTE PTR [edi+edx*1],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    cl,BYTE PTR [ecx]
    mov    BYTE PTR [eax],cl
    mov    eax,DWORD PTR [esi+0x4]
    add    eax,edi
    mov    DWORD PTR [esi+0x4],eax
  Branch6:
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Optionally installs the +0x0c virtual-base table, then clears three words and returns receiver EAX with zero ECX.
// R6GameService.dll @ 1002a980 : native store order, stack aliases and raw register effects retained.
__declspec(naked) void * __thiscall InitializeEmptyByteBufferTriplet(
    void *triplet,uint initializeVirtualBaseWord)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je Branch7
    mov    DWORD PTR [eax+0xc],0x10076b94
  Branch7:
    mov    DWORD PTR [eax],ecx
    mov    DWORD PTR [eax+0x4],ecx
    mov    DWORD PTR [eax+0x8],ecx
    pop    ecx
    ret    0x4
  }
}

// Clear begin/end then capacity via actual561b0; unused context passed physically, RET4/original triplet EAX.
// R6GameService.dll @ 1002ab00 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeEmptyByteBufferTripletWithContext(void *triplet,uint contextWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    push   0x0
    push   eax
    lea    ecx,[esi+0x8]
    mov    DWORD PTR [esi],0x0
    mov    DWORD PTR [esi+0x4],0x0
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    eax,esi
    pop    esi
    ret    0x4
  }
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

// Appends b, the virtual length in network order and the late-loaded payload range, retaining scratch and raw EAX.
// R6GameService.dll @ 1002c950 : complete native arguments/accesses/growth and raw ABI retained, RET8.
__declspec(naked) uint __stdcall WriteTaggedType2(int *valueNode,undefined1 *outputContext)
{
  __asm {
    // Cache value, initialize failure byte at entry-5, and retain raw extent read plus unreachable >UINT_MAX branch.
    sub    esp,0x8
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    BYTE PTR [esp+0x7],0x0
    mov    eax,DWORD PTR [edi+0x10]
    mov    edx,DWORD PTR [edi+0xc]
    sub    eax,edx
    cmp    eax,0xffffffff
    ja Branch23
    // Call cached value virtual size, then ordinal8; load output argument after both calls and cache encoded length.
    mov    edx,DWORD PTR [edi]
    push   ebx
    push   ebp
    push   esi
    mov    ecx,edi
    call   DWORD PTR [edx+0x14]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonlSlot
    mov    ebp,DWORD PTR [esp+0x20]
    mov    ebx,eax
    mov    DWORD PTR [esp+0x14],ebx
    mov    eax,DWORD PTR [ebp+0x10]
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    esi,[ebp+0xc]
    cmp    eax,ecx
    je Branch9
    test   eax,eax
    je Branch8
    mov    BYTE PTR [eax],0x62
  Branch8:
    inc    DWORD PTR [esi+0x4]
    jmp Branch10
  Branch9:
    push   0x1
    lea    ecx,[esp+0x20]
    push   0x1
    push   ecx
    push   R6GameServiceAddresses::WideTextB3
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch10:
    // Emit four encoded length bytes using original value argument as byte scratch; output/triplet stay cached.
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    eax,ecx
    mov    BYTE PTR [esp+0x1c],bl
    je Branch12
    test   eax,eax
    je Branch11
    mov    BYTE PTR [eax],bl
  Branch11:
    inc    DWORD PTR [esi+0x4]
    jmp Branch13
  Branch12:
    push   0x1
    lea    edx,[esp+0x24]
    push   0x1
    lea    ecx,[esp+0x24]
    push   edx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch13:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    eax,ecx
    mov    BYTE PTR [esp+0x1c],bh
    je Branch15
    test   eax,eax
    je Branch14
    mov    BYTE PTR [eax],bh
  Branch14:
    inc    DWORD PTR [esi+0x4]
    jmp Branch16
  Branch15:
    push   0x1
    lea    edx,[esp+0x24]
    push   0x1
    lea    ecx,[esp+0x24]
    push   edx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch16:
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    mov    cl,BYTE PTR [esp+0x16]
    cmp    eax,edx
    mov    BYTE PTR [esp+0x1c],cl
    je Branch18
    test   eax,eax
    je Branch17
    mov    BYTE PTR [eax],cl
  Branch17:
    inc    DWORD PTR [esi+0x4]
    jmp Branch19
  Branch18:
    push   0x1
    lea    edx,[esp+0x24]
    push   0x1
    lea    ecx,[esp+0x24]
    push   edx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch19:
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    mov    cl,BYTE PTR [esp+0x17]
    cmp    eax,edx
    mov    BYTE PTR [esp+0x1c],cl
    je Branch21
    test   eax,eax
    je Branch20
    mov    BYTE PTR [eax],cl
  Branch20:
    inc    DWORD PTR [esi+0x4]
    jmp Branch22
  Branch21:
    push   0x1
    lea    edx,[esp+0x24]
    push   0x1
    lea    ecx,[esp+0x24]
    push   edx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch22:
    // Reload current source end/begin from cached value after header effects, then current output end for range insertion.
    mov    dl,BYTE PTR [esp+0x1c]
    mov    ecx,DWORD PTR [edi+0x10]
    lea    eax,[esp+0x1c]
    mov    BYTE PTR [esp+0x1c],dl
    mov    edx,DWORD PTR [edi+0xc]
    push   eax
    mov    eax,DWORD PTR [ebp+0x10]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertByteRange
    // Read initialized failure byte before restoring registers; return insertion upper EAX with success AL.
    mov    al,BYTE PTR [esp+0x13]
    pop    esi
    pop    ebp
    pop    ebx
    test   al,al
    sete   al
    pop    edi
    add    esp,0x8
    ret    0x8
  Branch23:
    // Preserve the native unreachable failure exit after unsigned CMP EAX,UINT_MAX.
    mov    al,0x1
    pop    edi
    test   al,al
    sete   al
    add    esp,0x8
    ret    0x8
  }
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

// Moves a half-open range and returns memmove EAX plus the saved count; an empty range returns destination.
// R6GameService.dll @ 10028600 : complete register/stack/access order and native raw returns retained.
__declspec(naked) void * __stdcall MoveByteRange(void *first,void *last,void *destination)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    cmp    esi,eax
    jne Branch24
    mov    eax,DWORD PTR [esp+0x10]
    pop    esi
    ret    0xc
  Branch24:
    sub    esi,eax
    push   esi
    push   eax
    mov    eax,DWORD PTR [esp+0x18]
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,esi
    pop    esi
    ret    0xc
  }
}

// Moves a half-open range with an unused fourth word, returning destination for an empty range.
// R6GameService.dll @ 1002bbf0 : complete register/stack/access order and native raw returns retained.
__declspec(naked) void * __stdcall CopyByteRange(void *first,void *last,void *destination,void *unusedTag)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    cmp    esi,eax
    jne Branch25
    mov    eax,DWORD PTR [esp+0x10]
    pop    esi
    ret    0x10
  Branch25:
    sub    esi,eax
    push   esi
    push   eax
    mov    eax,DWORD PTR [esp+0x18]
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,esi
    pop    esi
    ret    0x10
  }
}

// Inserts by shifting or growing, preserving empty-range EAX and path-specific copy results and publication order.
// R6GameService.dll @ 1002b100 : complete register/stack/access order and native raw returns retained.
__declspec(naked) uint __thiscall InsertByteRange(
    void *buffer,void *position,void *first,void *last,void *unusedTag)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0xc
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x20]
    push   edi
    cmp    ecx,edx
    je Branch31
    // Cache inserted count and available capacity; an empty range bypasses all triplet reads.
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esi+0x8]
    mov    edi,edx
    sub    ebx,eax
    sub    edi,ecx
    cmp    ebx,edi
    mov    DWORD PTR [esp+0x14],edi
    jb Branch28
    mov    ebx,DWORD PTR [esp+0x20]
    sub    eax,ebx
    mov    ebx,DWORD PTR [esi+0x4]
    mov    ebp,eax
    cmp    ebp,edi
    jbe Branch27
    // Duplicate the final inserted-count bytes before shifting the remaining tail.
    mov    al,BYTE PTR [esp+0x20]
    lea    ecx,[esp+0x13]
    mov    ebp,ebx
    push   ecx
    sub    ebp,edi
    push   ebx
    push   ebx
    push   ebp
    mov    BYTE PTR [esp+0x23],al
    call   R6GameServiceAddresses::CopyByteRange
    mov    edx,DWORD PTR [esi+0x4]
    add    edx,edi
    mov    DWORD PTR [esi+0x4],edx
    // Reload position after the duplicate copy; shift only when the signed difference is positive.
    mov    esi,DWORD PTR [esp+0x20]
    sub    ebp,esi
    test   ebp,ebp
    jle Branch26
    push   ebp
    sub    ebx,ebp
    push   esi
    push   ebx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch26:
    mov    edx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    push   edx
    push   eax
    call   R6GameServiceAddresses::MoveByteRange
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x10
    // Split source at tail length and overwrite the original last argument with that split.
  Branch27:
    lea    eax,[ecx+ebp*1]
    push   ebx
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x34],eax
    call   R6GameServiceAddresses::MoveByteRange
    mov    eax,DWORD PTR [esi+0x4]
    sub    edi,ebp
    add    eax,edi
    mov    edi,DWORD PTR [esp+0x20]
    push   eax
    push   ebx
    push   edi
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::MoveByteRange
    mov    ebx,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x24]
    push   edi
    add    ebx,ebp
    push   ecx
    push   edx
    mov    DWORD PTR [esi+0x4],ebx
    call   R6GameServiceAddresses::MoveByteRange
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x10
    // Grow by occupied+max(occupied,inserted), with native unsigned wraparound and no NUL.
  Branch28:
    mov    edx,DWORD PTR [esi]
    lea    ecx,[esp+0x14]
    sub    eax,edx
    cmp    eax,edi
    mov    DWORD PTR [esp+0x18],eax
    jb Branch29
    lea    ecx,[esp+0x18]
  Branch29:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,DWORD PTR [esp+0x20]
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    push   ebp
    push   ebx
    push   eax
    call   R6GameServiceAddresses::MoveByteRange
    mov    ecx,DWORD PTR [esp+0x24]
    push   eax
    mov    eax,DWORD PTR [esp+0x2c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::MoveByteRange
    // Reload current end after both copies; retain the insertion point cached after allocation.
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x20],eax
    cmp    ecx,ebx
    je Branch30
    sub    ecx,ebx
    push   ecx
    push   ebx
    push   eax
    mov    DWORD PTR [esp+0x2c],ecx
    call   R6GameServiceAddresses::memmove
    mov    ecx,DWORD PTR [esp+0x2c]
    add    esp,0xc
    add    eax,ecx
    mov    DWORD PTR [esp+0x20],eax
  Branch30:
    mov    edx,DWORD PTR [esi]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    // Reload the saved new end from the original position slot after free, then publish begin/end/capacity.
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esi],ebp
    add    ebp,edi
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ebp
  Branch31:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x10
  }
}

// Forwards insertion with a local byte tag and position in EAX, retaining the callee's complete return value.
// R6GameService.dll @ 1002b010 : ECX triplet, position/first/last/unused-tag stack words, RET 0x10.
__declspec(naked) uint __thiscall InsertByteRangeWithLocalTag(
    void *buffer,void *insertionPoint,void *first,void *last,undefined1 *unusedTag)
{
  __asm {
    push   ecx
    mov    al,byte ptr [esp+0x10]
    lea    edx,[esp+0x3]
    mov    byte ptr [esp+0x3],al
    mov    eax,dword ptr [esp+0x10]
    push   edx
    mov    edx,dword ptr [esp+0x10]
    push   eax
    mov    eax,dword ptr [esp+0x10]
    push   edx
    push   eax
    call   R6GameServiceAddresses::InsertByteRange
    pop    ecx
    ret    0x10
  }
}

// Appends a type-four scalar on success or short input, committing its cached cursor only after insertion.
// R6GameService.dll @ 1002c260 : complete native frame/argument/access order and raw ABI retained; ECX unused.
__declspec(naked) uint __stdcall ParseWordValue(undefined4 *source,int *cursorAddress,int destination)
{
  __asm {
    // Cache source end and pointed cursor before allocation; the saved ECX word is cleared as scratch, with no EH frame.
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [ecx+0x10]
    push   edi
    mov    edi,DWORD PTR [eax]
    xor    ebp,ebp
    push   0x14
    mov    DWORD PTR [esp+0x14],ebp
    xor    bl,bl
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    cmp    eax,ebp
    je Branch32
    // A short-input object retains uninitialized raw/decoded value words; null allocation is still a possible payload.
    mov    DWORD PTR [eax+0x4],0x10076b34
    mov    DWORD PTR [eax+0x8],0x4
    mov    DWORD PTR [eax],R6GameServiceAddresses::clDataLongVTable
    mov    ebp,eax
  Branch32:
    // Check exact end, one remaining byte and unsigned remaining count; no pointer ordering guard is present.
    cmp    edi,esi
    je Branch33
    lea    edx,[edi+0x1]
    cmp    edx,esi
    je Branch33
    sub    esi,edi
    cmp    esi,0x4
    jb Branch33
    // Read the raw unaligned word, advance the local cursor, then store raw and network-decoded fields through bd90.
    mov    eax,DWORD PTR [edi]
    mov    ecx,ebp
    push   eax
    add    edi,0x4
    call   R6GameServiceAddresses::SetClDataLongEncodedValue
    jmp Branch34
  Branch33:
    mov    bl,0x1
  Branch34:
    // Reuse original source for payload and destination for copied sentinel; append on both success and failure.
    mov    eax,DWORD PTR [esp+0x20]
    lea    ecx,[esp+0x20]
    push   ecx
    mov    DWORD PTR [esp+0x1c],ebp
    lea    esi,[eax+0x10]
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x18]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    // Reload saved sentinel after node allocation, then publish links before committing the cursor.
    mov    esi,DWORD PTR [esp+0x20]
    test   bl,bl
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    // Reload original cursor-address late; return its upper EAX with status AL and pop the cleared ECX scratch word.
    mov    eax,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [eax],edi
    pop    edi
    pop    esi
    pop    ebp
    sete   al
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// String parser constructor locals occupy logical EBP-0x18 through EBP-4.
struct TaggedStringParseFrame {
  uint constructionFlags;
  uint endOrSentinel;
  uint *allocation;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Reads through NUL or cached end and appends even a partial string, preserving cursor and argument-slot scratch.
// R6GameService.dll @ 1002c0c0 : complete native frame/argument/access order and raw ABI retained; ECX unused.
__declspec(naked) uint __stdcall ParseStringValue(undefined4 *source,int *cursorAddress,int destination)
{
  __asm {
    // Register the constructor frame; normalized entry locals are flags-18, cached end/head-14, allocation-10, EH-c/-8/-4.
    push   0xffffffff
    push   R6GameServiceAddresses::TaggedStringParseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   ebp
    xor    ebp,ebp
    push   esi
    mov    DWORD PTR [esp+0xc],ebp
    mov    eax,DWORD PTR [esp+0x28]
    push   edi
    push   0x18
    mov    ebx,DWORD PTR [eax+0x10]
    mov    DWORD PTR [esp+0x18],ebx
    // Cache input end before allocation; retain the original source argument as the constructor tag.
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x18],esi
    cmp    esi,ebp
    je Branch35
    mov    eax,0x1
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataStrBaseOffsets
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    // Construction enters state2 then state3; initial buffer allocation and its unchecked NUL write remain live in state3.
    mov    DWORD PTR [esp+0x24],0x2
    lea    edi,[esi+0xc]
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x24],0x3
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    push   0x8
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    edx,[eax+0x8]
    mov    DWORD PTR [edi],eax
    mov    DWORD PTR [edi+0x4],eax
    mov    DWORD PTR [edi+0x8],edx
    mov    BYTE PTR [eax],0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrPTR_FUN
    mov    ebp,esi
  Branch35:
    // Lower cleanup state before conversion; load cursor-address only after constructing the string.
    test   ebp,ebp
    mov    DWORD PTR [esp+0x24],0xffffffff
    je Branch36
    lea    esi,[ebp+0xc]
    jmp Branch37
  Branch36:
    xor    esi,esi
  Branch37:
    mov    edi,DWORD PTR [esp+0x30]
    mov    eax,DWORD PTR [edi]
    cmp    eax,ebx
    je Branch41
  Branch38:
    // Commit each input byte before checking NUL; BL replaces the low byte of the cached end register.
    mov    bl,BYTE PTR [eax]
    inc    eax
    test   bl,bl
    mov    DWORD PTR [edi],eax
    je Branch43
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[eax+0x1]
    cmp    ecx,edx
    jne Branch40
    // Growth reuses original source/cursor arguments for one/length; the live cursor-address stays in EDI.
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x2c],0x1
    sub    eax,edx
    lea    ecx,[esp+0x2c]
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x30],eax
    jb Branch39
    lea    ecx,[esp+0x30]
  Branch39:
    mov    edx,DWORD PTR [ecx]
    mov    ecx,esi
    add    edx,eax
    push   edx
    call   R6GameServiceAddresses::ReserveByteString
  Branch40:
    // Reload end for each NUL, character and increment access; compare the next cursor with the saved frame bound.
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax+0x1],0x0
    mov    ecx,DWORD PTR [esi+0x4]
    mov    BYTE PTR [ecx],bl
    mov    edx,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esp+0x14]
    inc    edx
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi]
    cmp    eax,ecx
    jne Branch38
  Branch41:
    // Missing NUL still inserts the partial value: original cursor argument holds payload, frame bound becomes sentinel.
    mov    edx,DWORD PTR [esp+0x34]
    lea    eax,[esp+0x14]
    push   eax
    mov    DWORD PTR [esp+0x34],ebp
    lea    esi,[edx+0x10]
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0x30]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    // Only clear AL on missing NUL, retaining node upper EAX and previous-FS ECX.
    xor    al,al
  Branch42:
    mov    ecx,DWORD PTR [esp+0x1c]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0xc
  Branch43:
    // NUL success uses original source argument for payload and original destination argument for saved sentinel.
    mov    edx,DWORD PTR [esp+0x34]
    lea    eax,[esp+0x34]
    push   eax
    mov    DWORD PTR [esp+0x30],ebp
    lea    esi,[edx+0x10]
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0x2c]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    al,0x1
    jmp Branch42
  }
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

// Binary parser locals occupy logical EBP-0x18 through EBP-4; arguments +4/+8 become allocation/prefix slots.
struct TaggedByteBlockParseFrame {
  byte padding[3];
  byte failed;
  uint constructionFlags;
  uint *savedTriplet;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Appends a length-prefixed block or failed partial value, retaining native short-prefix overread and cursor timing.
// R6GameService.dll @ 1002c310 : complete native frame/argument/access order and raw ABI retained; ECX unused.
__declspec(naked) uint __stdcall ParseByteBlockValue(undefined4 *source,int *cursorAddress,int destination)
{
  __asm {
    // Register constructor cleanup; entry locals are failure-15, flags-14, saved triplet-10, EH-c/-8/-4.
    push   0xffffffff
    push   R6GameServiceAddresses::TaggedByteBlockParseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   ebp
    mov    DWORD PTR [esp+0xc],0x0
    mov    ebx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    mov    esi,DWORD PTR [ebx]
    push   edi
    mov    ebp,DWORD PTR [eax+0x10]
    push   0x1c
    mov    BYTE PTR [esp+0x17],0x0
    // Cache cursor address/value and input end before allocation; original source argument becomes saved allocation.
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x2c],edi
    test   edi,edi
    je Branch44
    // Initialize kind2/base/vbase tables and state4, with original cursor argument address as constructor tag.
    mov    DWORD PTR [edi+0x4],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [edi+0x18],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],0x1
    mov    DWORD PTR [edi+0x8],0x2
    mov    DWORD PTR [edi],R6GameServiceAddresses::PTR_LAB
    lea    ecx,[edi+0xc]
    mov    DWORD PTR [esp+0x18],ecx
    lea    edx,[esp+0x30]
    mov    DWORD PTR [esp+0x24],0x4
    push   edx
    call   R6GameServiceAddresses::InitializePointerTriplet
    mov    DWORD PTR [edi],R6GameServiceAddresses::clDataBinPTR_FUN
    jmp Branch45
  Branch44:
    xor    edi,edi
  Branch45:
    // Lower state before parsing; only zero/one remaining byte is rejected before reading the four-byte prefix.
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x24],0xffffffff
    je Branch46
    lea    eax,[esi+0x1]
    cmp    eax,ebp
    je Branch46
    // Read prefix bytes in native order 0,2,1,3 into the original cursor-argument word, including short-prefix overread.
    mov    cl,BYTE PTR [esi]
    mov    esi,eax
    mov    al,BYTE PTR [esi+0x1]
    mov    BYTE PTR [esp+0x30],cl
    mov    dl,BYTE PTR [esi]
    inc    esi
    inc    esi
    mov    BYTE PTR [esp+0x31],dl
    mov    BYTE PTR [esp+0x32],al
    mov    cl,BYTE PTR [esi]
    inc    esi
    mov    BYTE PTR [esp+0x33],cl
    mov    edx,DWORD PTR [esp+0x30]
    // Network decode uses imported ordinal14; retain the unsigned size test and unreachable comparison above UINT_MAX.
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohlSlot
    sub    ebp,esi
    cmp    ebp,eax
    jb Branch46
    cmp    eax,0xffffffff
    ja Branch46
    // Publish payload start before insertion; local cursor advances across the declared bytes before the child call.
    mov    DWORD PTR [ebx],esi
    add    esi,eax
    mov    al,BYTE PTR [esp+0x30]
    lea    ecx,[edi+0xc]
    lea    edx,[esp+0x30]
    mov    BYTE PTR [esp+0x30],al
    mov    eax,DWORD PTR [ebx]
    push   edx
    mov    edx,DWORD PTR [ecx]
    push   esi
    push   eax
    push   edx
    call   R6GameServiceAddresses::InsertByteRange
    jmp Branch47
  Branch46:
    mov    BYTE PTR [esp+0x13],0x1
  Branch47:
    // Append even on failure; source argument holds payload and destination argument holds the copied sentinel.
    mov    eax,DWORD PTR [esp+0x34]
    mov    DWORD PTR [esp+0x2c],edi
    lea    ecx,[esp+0x34]
    lea    edi,[eax+0x10]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x2c]
    mov    ecx,edi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    edi,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    // Load failure and previous FS before final cursor write; only replace AL, retaining node upper EAX.
    mov    al,BYTE PTR [esp+0x13]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [ebx],esi
    pop    edi
    test   al,al
    pop    esi
    pop    ebp
    sete   al
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0xc
  }
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

// Appends s, the current string range and NUL, retaining native scratch aliases and path-specific raw returns.
// R6GameService.dll @ 1002c5e0 : complete native arguments/accesses/growth and raw ABI retained, RET8.
__declspec(naked) uint __stdcall WriteTaggedType1(int valueWord,int outputWord)
{
  __asm {
    // Cache output and triplet before tag append; original value argument loads only after any tag growth.
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [edi+0x10]
    mov    ecx,DWORD PTR [edi+0x14]
    lea    esi,[edi+0xc]
    cmp    eax,ecx
    je Branch49
    test   eax,eax
    je Branch48
    mov    BYTE PTR [eax],0x73
  Branch48:
    inc    DWORD PTR [esi+0x4]
    jmp Branch50
  Branch49:
    push   0x1
    lea    ecx,[esp+0x18]
    push   0x1
    push   ecx
    push   R6GameServiceAddresses::TextSLb3
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
  Branch50:
    // Use original output argument as tag scratch and reload value argument, then source end/begin and current output end.
    mov    dl,BYTE PTR [esp+0x14]
    lea    eax,[esp+0x14]
    push   eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    BYTE PTR [esp+0x18],dl
    mov    ecx,DWORD PTR [eax+0x10]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [edi+0x10]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertByteRange
    // Append NUL after actual range insertion; fitting output returns new-end upper EAX with AL1.
    mov    ebp,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi+0x8]
    cmp    ebp,eax
    je Branch52
    test   ebp,ebp
    je Branch51
    mov    BYTE PTR [ebp+0x0],0x0
  Branch51:
    mov    eax,DWORD PTR [esi+0x4]
    pop    edi
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    pop    esi
    mov    al,0x1
    pop    ebp
    ret    0x8
  Branch52:
    // NUL growth reuses original output/value arguments for one/occupied length, with unchecked allocation.
    mov    edx,DWORD PTR [esi]
    mov    eax,ebp
    sub    eax,edx
    mov    DWORD PTR [esp+0x14],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x14]
    jb Branch53
    lea    ecx,[esp+0x10]
  Branch53:
    mov    edi,DWORD PTR [ecx]
    push   ebx
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    jne Branch54
    mov    eax,ebx
    jmp Branch55
  Branch54:
    sub    ebp,eax
    push   ebp
    push   eax
    push   ebx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebp
  Branch55:
    // Write NUL before releasing old storage; publish begin/capacity/end in that order and retain free upper EAX.
    mov    BYTE PTR [eax],0x0
    mov    ecx,DWORD PTR [esi]
    push   ecx
    lea    ebp,[eax+0x1]
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi],ebx
    add    ebx,edi
    mov    DWORD PTR [esi+0x8],ebx
    pop    ebx
    mov    DWORD PTR [esi+0x4],ebp
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    ret    0x8
  }
}

// Type-five writer locals hold the current growth length and cached source end in an eight-byte allocation.
struct TaggedType5WriteFrame {
  uint occupiedBytes;
  uint sourceEnd;
};

// Appends s and virtual-size-plus-one source bytes, retaining cached source pointer and late byte loads.
// R6GameService.dll @ 1002c6d0 : complete native arguments/accesses/growth and raw ABI retained, RET8.
__declspec(naked) uint __stdcall WriteTaggedType5(int *value,undefined1 *outputWord)
{
  __asm {
    // Cache output triplet; growth uses original output argument as constant-one scratch before source loads.
    mov    eax,DWORD PTR [esp+0x8]
    sub    esp,0x8
    push   ebx
    mov    ebx,DWORD PTR [eax+0x10]
    push   ebp
    push   esi
    lea    esi,[eax+0xc]
    push   edi
    cmp    ebx,DWORD PTR [esi+0x8]
    je Branch57
    test   ebx,ebx
    je Branch56
    mov    BYTE PTR [ebx],0x73
  Branch56:
    inc    DWORD PTR [esi+0x4]
    jmp Branch61
  Branch57:
    mov    edx,DWORD PTR [esi]
    mov    eax,ebx
    sub    eax,edx
    mov    DWORD PTR [esp+0x20],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x20]
    jb Branch58
    lea    ecx,[esp+0x10]
  Branch58:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne Branch59
    mov    eax,ebp
    jmp Branch60
  Branch59:
    sub    ebx,eax
    push   ebx
    push   eax
    push   ebp
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebx
  Branch60:
    // Tag growth writes s, releases the old allocation with its size, then publishes all three new words.
    lea    ecx,[esi+0x8]
    mov    BYTE PTR [eax],0x73
    lea    ebx,[eax+0x1]
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [ecx]
    sub    edx,eax
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    lea    eax,[edi+ebp*1]
    mov    ecx,esi
    push   eax
    push   ebx
    push   ebp
    call   R6GameServiceAddresses::SetThreeWordRecord
  Branch61:
    // Load source argument late, cache source pointer before virtual size call, and include one extra byte.
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [ecx]
    mov    edi,DWORD PTR [ecx+0xc]
    call   DWORD PTR [edx+0x14]
    lea    ebp,[eax+edi*1+0x1]
    // Original output argument becomes current source cursor; frame-4 stores source limit and frame-8 growth length.
    mov    eax,edi
    cmp    eax,ebp
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],eax
    je Branch69
  Branch62:
    mov    ebx,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    ebx,ecx
    je Branch64
    test   ebx,ebx
    je Branch63
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [ebx],cl
  Branch63:
    inc    DWORD PTR [esi+0x4]
    jmp Branch68
  Branch64:
    // Body growth overwrites original value argument with one while retaining cursor and limit in their native slots.
    mov    edx,DWORD PTR [esi]
    mov    eax,ebx
    sub    eax,edx
    mov    DWORD PTR [esp+0x1c],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x1c]
    jb Branch65
    lea    ecx,[esp+0x10]
  Branch65:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne Branch66
    mov    eax,ebp
    jmp Branch67
  Branch66:
    sub    ebx,eax
    push   ebx
    push   eax
    push   ebp
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebx
  Branch67:
    // Load source byte after allocation/copy, release old first-word storage, and restore current cursor/limit.
    mov    edx,DWORD PTR [esp+0x20]
    lea    ebx,[eax+0x1]
    mov    cl,BYTE PTR [edx]
    mov    BYTE PTR [eax],cl
    mov    ecx,esi
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    edx,[edi+ebp*1]
    mov    ecx,esi
    push   edx
    push   ebx
    push   ebp
    call   R6GameServiceAddresses::SetThreeWordRecord
    mov    eax,DWORD PTR [esp+0x20]
    mov    ebp,DWORD PTR [esp+0x14]
  Branch68:
    inc    eax
    cmp    eax,ebp
    mov    DWORD PTR [esp+0x20],eax
    jne Branch62
  Branch69:
    // Return the advanced source cursor upper EAX with AL1, even when virtual size UINT_MAX skipped the copy loop.
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Type-four writer locals: index/header length, constant-one scratch and payload-growth length.
struct TaggedType4WriteFrame {
  uint index;
  uint one;
  uint occupiedBytes;
};

// Appends L and four physical encoded-word bytes with exact growth/index/register effects.
// R6GameService.dll @ 1002c820 : complete native arguments/accesses/growth and raw ABI retained, RET8.
__declspec(naked) uint __stdcall WriteTaggedType4(int valueWord,uint outputWord)
{
  __asm {
    // Cache output triplet; append L or grow before reading the original value argument.
    mov    eax,DWORD PTR [esp+0x8]
    sub    esp,0xc
    push   ebx
    mov    ebx,DWORD PTR [eax+0x10]
    push   ebp
    push   esi
    lea    esi,[eax+0xc]
    push   edi
    cmp    ebx,DWORD PTR [esi+0x8]
    je Branch71
    test   ebx,ebx
    je Branch70
    mov    BYTE PTR [ebx],0x4c
  Branch70:
    inc    DWORD PTR [esi+0x4]
    jmp Branch75
  Branch71:
    mov    edx,DWORD PTR [esi]
    mov    eax,ebx
    sub    eax,edx
    mov    DWORD PTR [esp+0x24],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x10],eax
    lea    ecx,[esp+0x24]
    jb Branch72
    lea    ecx,[esp+0x10]
  Branch72:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne Branch73
    mov    eax,ebp
    jmp Branch74
  Branch73:
    sub    ebx,eax
    push   ebx
    push   eax
    push   ebp
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebx
  Branch74:
    // Fill the L tag, release old first-word storage and publish the replacement triplet.
    push   R6GameServiceAddresses::TextLb
    push   0x1
    push   eax
    call   R6GameServiceAddresses::FillByteRangeAndReturnEnd
    mov    ecx,esi
    mov    ebx,eax
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[edi+ebp*1]
    push   ecx
    push   ebx
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::SetThreeWordRecord
  Branch75:
    // Frame-0xc is the loop index; reload original value for each of four physical bytes at value+0xc.
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x10],ecx
  Branch76:
    mov    edx,DWORD PTR [esp+0x20]
    mov    ebp,DWORD PTR [esi+0x4]
    mov    al,BYTE PTR [edx+ecx*1+0xc]
    mov    edx,DWORD PTR [esi+0x8]
    cmp    ebp,edx
    mov    BYTE PTR [esp+0x24],al
    je Branch78
    test   ebp,ebp
    je Branch77
    mov    BYTE PTR [ebp+0x0],al
  Branch77:
    inc    DWORD PTR [esi+0x4]
    jmp Branch82
  Branch78:
    // Frame-8/-4 hold one/occupied length; original output argument low byte preserves the selected payload byte.
    mov    edx,DWORD PTR [esi]
    mov    eax,ebp
    sub    eax,edx
    mov    DWORD PTR [esp+0x14],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x18],eax
    lea    ecx,[esp+0x14]
    jb Branch79
    lea    ecx,[esp+0x18]
  Branch79:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    jne Branch80
    mov    eax,ebx
    jmp Branch81
  Branch80:
    sub    ebp,eax
    push   ebp
    push   eax
    push   ebx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebp
  Branch81:
    // Reload saved byte after copying, write it before release, then restore loop index and publish new triplet.
    mov    cl,BYTE PTR [esp+0x24]
    lea    ebp,[eax+0x1]
    mov    BYTE PTR [eax],cl
    mov    edx,DWORD PTR [esi]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi],ebx
    add    ebx,edi
    mov    DWORD PTR [esi+0x4],ebp
    mov    DWORD PTR [esi+0x8],ebx
  Branch82:
    // Increment the actual saved index; do not replace it with the decompiler invented incoming-EBX value.
    inc    ecx
    cmp    ecx,0x4
    mov    DWORD PTR [esp+0x10],ecx
    jb Branch76
    // Only replace AL with one; preserve upper EAX from last output-pointer, capacity or release path.
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// Clears three words, allocates eight bytes unchecked, publishes begin/end/capacity, then writes the initial NUL.
// R6GameService.dll @ 1002aca0 : native store order, stack aliases and raw register effects retained.
__declspec(naked) void * __thiscall InitializeEmptyByteString(void *triplet)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   0x8
    mov    DWORD PTR [esi],0x0
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[eax+0x8]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    mov    BYTE PTR [eax],0x0
    mov    eax,esi
    pop    esi
    ret
  }
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

// Appends a range using a local last-low-byte tag, ignoring the incoming third stack word and retaining target EAX.
// R6GameService.dll @ 1002b040 : ECX triplet, first/last/unused-tag stack words, RET 0xc.
__declspec(naked) void * __thiscall AppendByteRangeWithLocalGrowthTag(
    void *triplet,undefined1 *first,undefined1 *last,uint unusedTag)
{
  __asm {
    push   ecx
    mov    al,byte ptr [esp+0xc]
    lea    edx,[esp+0x3]
    mov    byte ptr [esp+0x3],al
    mov    eax,dword ptr [esp+0xc]
    push   edx
    mov    edx,dword ptr [esp+0xc]
    push   eax
    push   edx
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
    pop    ecx
    ret    0xc
  }
}

// Compute cached length+1 modulo32, allocate/publish triplet; reload end argument for copy gate, cached length for move.
// Publish current move-return+length/end, then NUL, RET12/end EAX. Zero allocation throws; no own EH/NULL repair.
// R6GameService.dll @ 1002b0a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructHeapByteStringRange(void *triplet,void *first,int lastWord,void *unusedTag)
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
    ja     Branch83
    test   ebx,ebx
    jbe    Branch83
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch84
  Branch83:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
  Branch84:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi]
    cmp    ecx,ebp
    je     Branch85
    push   edi
    push   ebp
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch85:
    mov    DWORD PTR [esi+0x4],eax
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax],0x0
    pop    ebx
    ret    0xc
  }
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
