#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100800e8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataSerializeListParseExceptionHandlerFunctionInfo;

// Forward the receiver to clDataSerialize's vtable-only cleanup.
// R6GameService.dll @ 1002a870 : native tail alias; no stack arguments or source return value.
void __fastcall ResetClDataSerializeVtableAlias(void *object)
{
  using ResetABI = void (__fastcall *)(void *);
  ((ResetABI)R6GameServiceAddresses::ResetClDataSerializeVtable)(object);
}

// Native signed-tag remap for L..s and the five parser handler targets, including the default path.
// R6GameService.dll data @ 1002bed0 : native storage identity retained.
const byte GTaggedParseTagRemap[40] = {
  0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3
};
// R6GameService.dll data @ 1002bebc : native storage identity retained.
const uint GTaggedParseTargets[5] = {R6GameServiceAddresses::clDataSerializeBranch4,R6GameServiceAddresses::clDataSerializeBranch2,R6GameServiceAddresses::clDataSerializeBranch5,R6GameServiceAddresses::clDataSerializeBranch3,R6GameServiceAddresses::clDataSerializeBranch7};
// R6GameService.dll data @ 1002c5c8 : native storage identity retained.
const uint GTaggedWriteTargets[6] = {R6GameServiceAddresses::clDataSerializeBranch29,R6GameServiceAddresses::clDataSerializeBranch32,R6GameServiceAddresses::clDataSerializeBranch23,R6GameServiceAddresses::clDataSerializeBranch31,R6GameServiceAddresses::clDataSerializeBranch30,R6GameServiceAddresses::clDataSerializeBranch33};

// Clears destination and parses tags through cached end/cursor argument words, retaining partial inserts and status.
// R6GameService.dll @ 1002be10 : complete native dispatch/argument/access order and raw ABI retained.
uint __thiscall ParseTaggedValues(void *parserContext,undefined4 *source,undefined1 *destination)
{
  uint savedDestination = (uint)destination;
  uint context = (uint)parserContext;
  uint table = *(uint *)(savedDestination + 0xc);
  using ClearABI = void (__thiscall *)(void *);
  (*(ClearABI *)(table + 4))((void *)(savedDestination + 0xc));
  undefined4 *sourceObject = source;
  uint cursor = *(uint *)((uint)sourceObject + 0xc);
  uint end = *(uint *)((uint)sourceObject + 0x10);
  destination = (undefined1 *)cursor;
  source = (undefined4 *)end;
  uint result = cursor;
  bool failed = false;
  using ParseABI = uint (__thiscall *)(void *,undefined4 *,int *,int);
  while (result != (uint)source) {
    byte tag = *(byte *)result;
    ++result;
    destination = (undefined1 *)result;
    result = (uint)((int)(signed char)tag - 0x4c);
    if (result > 0x27) {
      failed = true;
      break;
    }
    byte handler = GTaggedParseTagRemap[result];
    uint target;
    switch (handler) {
      case 0: target = R6GameServiceAddresses::ParseWordValue; break;
      case 1: target = R6GameServiceAddresses::ParseListValue; break;
      case 2: target = R6GameServiceAddresses::ParseByteBlockValue; break;
      case 3: target = R6GameServiceAddresses::ParseStringValue; break;
      default: failed = true; break;
    }
    if (failed) break;
    result = ((ParseABI)target)((void *)context,sourceObject,(int *)&destination,(int)savedDestination);
    failed = (byte)result == 0;
    if (failed) break;
    result = (uint)destination;
  }
  return (result & 0xffffff00u) | (failed ? 0u : 1u);
}

// Native nested-list dispatch for L..s, including closing bracket and default targets.
// R6GameService.dll data @ 1002c08c : native storage identity retained.
const byte GNestedParseTagRemap[40] = {
  0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,5,2,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4
};
// R6GameService.dll data @ 1002c074 : native storage identity retained.
const uint GNestedParseTargets[6] = {R6GameServiceAddresses::clDataSerializeBranch15,R6GameServiceAddresses::clDataSerializeBranch13,R6GameServiceAddresses::clDataSerializeBranch19,R6GameServiceAddresses::clDataSerializeBranch16,R6GameServiceAddresses::clDataSerializeBranch14,R6GameServiceAddresses::clDataSerializeBranch18};

// Parses a nested list, accepting end without ], and always appends the child after success or tag/child failure.
// R6GameService.dll @ 1002bf00 : ECX context, three stack words; construction cleanup and local names are inferred.
uint __thiscall ParseListValue(void *parserContext,undefined4 *source,int *cursorAddress,int destination)
{
  void *context = parserContext;
  uint sourceEnd = *(uint *)((uint)source + 0x10);
  byte failed = 0;
  uint child = (uint)AllocateGameServiceBytes(0x18);
  uint savedChild = child;
  int *sharedCursor;
  if (child != 0) {
    *(uint *)(child + 4) = R6GameServiceAddresses::ClDataListBaseOffsets;
    *(uint *)(child + 0x14) = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
    *(uint *)(child + 8) = 3;
    *(uint *)child = R6GameServiceAddresses::PTR_LAB;
    uint inner = child + 0xc;
    uint headSlot = inner + 4;
    byte constructorTag;
    // Native state5 owns the child here; its tag/context cleanup actions are empty.
    try {
      InitializeCircularListSentinel((void *)headSlot,(uint)&constructorTag);
      *(uint *)inner = R6GameServiceAddresses::clDataListPTR_FUN2;
      *(uint *)child = R6GameServiceAddresses::clDataListPTR_FUN;
      *(uint *)inner = R6GameServiceAddresses::clDataListPTR_LAB;
      sharedCursor = cursorAddress;
    } catch (...) {
      ResetClDataVtable((undefined4 *)savedChild);
      ForwardToAllocatorTail((void *)savedChild);
      throw;
    }
  } else {
    sharedCursor = cursorAddress;
  }
  using ParseABI = uint (__thiscall *)(void *,undefined4 *,int *,int);
  for (;;) {
    uint cursor = (uint)*sharedCursor;
    if (cursor == sourceEnd) break;
    byte tag = *(byte *)cursor;
    ++cursor;
    *sharedCursor = (int)cursor;
    uint tagIndex = (uint)((int)(signed char)tag - 0x4c);
    if (tagIndex > 0x27) {
      failed = 1;
      break;
    }
    byte handler = GNestedParseTagRemap[tagIndex];
    uint target;
    switch (handler) {
    case 0: target = R6GameServiceAddresses::ParseWordValue; break;
    case 1: target = R6GameServiceAddresses::ParseListValue; break;
    case 2: target = 0; break;
    case 3: target = R6GameServiceAddresses::ParseByteBlockValue; break;
    case 4: target = R6GameServiceAddresses::ParseStringValue; break;
    default: failed = 1; target = 0; break;
    }
    if (target == 0) break;
    uint result = ((ParseABI)target)(context,source,sharedCursor,(int)child);
    failed = (byte)result == 0;
    if (failed != 0) break;
  }
  uint savedDestination = (uint)destination;
  source = (undefined4 *)child;
  uint headSlot = savedDestination + 0x10;
  CopyListHeadSlot((void *)headSlot,(uint *)&cursorAddress);
  uint node = (uint)AllocateListPayloadNode((uint *)&source);
  uint head = (uint)cursorAddress;
  uint previous = *(uint *)(head + 4);
  *(uint *)node = head;
  *(uint *)(node + 4) = previous;
  *(uint *)previous = node;
  *(uint *)(head + 4) = node;
  return (node & 0xffffff00u) | (failed == 0 ? 1u : 0u);
}

// Reads both cursor fields, resets end to begin and forwards the writer result. Native self-comparison excludes moving.
// R6GameService.dll @ 1002c470 : complete native dispatch/argument/access order and raw ABI retained.
uint __thiscall WriteTaggedEntries(void *serializer,int sourceList,undefined1 *output)
{
  uint savedOutput = (uint)output;
  void *context = serializer;
  uint end = *(uint *)(savedOutput + 0x10);
  uint begin = *(uint *)(savedOutput + 0xc);
  end = begin;
  *(uint *)(savedOutput + 0x10) = end;
  using WriteABI = uint (__thiscall *)(void *,int,undefined1 *);
  return ((WriteABI)R6GameServiceAddresses::WriteTaggedEntryList)(context,sourceList,(undefined1 *)savedOutput);
}

// Writes a sentinel list, closes nested brackets after child failure, then reads next before testing that failure.
// R6GameService.dll @ 1002c4b0 : ECX context, two stack words; scratch/context names are inferred.
uint __thiscall WriteTaggedEntryList(void *serializer,int sourceList,undefined1 *output)
{
  uint sentinel = *(uint *)((uint)sourceList + 0x10);
  void *savedContext = serializer;
  byte failed = 0;
  uint node = *(uint *)sentinel;
  uint savedSentinel = sentinel;
  uint result = sentinel;
  void *context = serializer;
  byte closingTag;
  using WriteABI = uint (__thiscall *)(void *,uint,undefined1 *);
  while (node != result) {
    uint value = *(uint *)(node + 8);
    result = *(uint *)(value + 8) - 1;
    if (result > 5) {
      failed = 1;
      break;
    }
    if (result == 2) {
      uint savedOutput = (uint)output;
      uint end = *(uint *)(savedOutput + 0x10);
      uint capacity = *(uint *)(savedOutput + 0x14);
      auto *triplet = (R6GameServiceNative::ByteRange *)(savedOutput + 0xc);
      if (end != capacity) {
        if (end != 0) *(byte *)end = '[';
        ++triplet->end;
      } else {
        GrowByteBufferAndInsertRepeatedBytes(triplet,(void *)end,
            (undefined1 *)R6GameServiceAddresses::TextSLb,(uint)&sourceList,1,1);
        context = savedContext;
      }
      uint child = WriteTaggedEntryList(context,(int)value,(undefined1 *)savedOutput);
      capacity = triplet->capacityEnd;
      failed = (byte)child == 0;
      result = triplet->end;
      if (result != capacity) {
        if (result != 0) *(byte *)result = ']';
        ++triplet->end;
      } else {
        result = GrowByteBufferAndInsertRepeatedBytes(triplet,(void *)result,
            (undefined1 *)R6GameServiceAddresses::TextSLb2,(uint)&closingTag,1,1);
      }
    } else {
      uint target;
      switch (result) {
      case 0: target = R6GameServiceAddresses::WriteTaggedType1; break;
      case 1: target = R6GameServiceAddresses::WriteTaggedType2; break;
      case 3: target = R6GameServiceAddresses::WriteTaggedType4; break;
      case 4: target = R6GameServiceAddresses::WriteTaggedType5; break;
      case 5: target = R6GameServiceAddresses::WriteTaggedValueByType; break;
      }
      undefined1 *childOutput = output;
      if (result == 5) value = *(uint *)(value + 0xc);
      result = ((WriteABI)target)(context,value,childOutput);
      failed = (byte)result == 0;
    }
    node = *(uint *)node;
    if (failed != 0) break;
    context = savedContext;
    result = savedSentinel;
  }
  return (result & 0xffffff00u) | (failed == 0 ? 1u : 0u);
}

// Releases the child allocation saved while constructing a nested list.
// R6GameService.dll @ 10065cf0 : inherited parent EBP; saved allocation at EBP-0x14.
__declspec(naked) void __cdecl ReleaseNestedListAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards child+0x18 to empty cleanup only when construction flag bit zero is set.
// R6GameService.dll @ 10065cfa : inherited parent EBP; flags at -0x20, child at -0x14.
__declspec(naked) void __cdecl CleanupNestedListContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x20]
    and    eax,1
    test   eax,eax
    je     noContext
    mov    ecx,dword ptr [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  noContext:
    ret
  }
}

// Restores the saved nested-list allocation's clData base vtable.
// R6GameService.dll @ 10065d14 : inherited parent EBP; saved child at EBP-0x14.
__declspec(naked) void __cdecl ResetNestedListBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forwards the local constructor tag address to empty cleanup, retaining incoming EAX.
// R6GameService.dll @ 10065d1c : inherited parent EBP; constructor tag at EBP-0x21.
__declspec(naked) void __cdecl CleanupNestedListConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp-0x21]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the nested-list parser's FuncInfo 0x100800e8 for the shared C++ exception handler.
// R6GameService.dll @ 10065d24 : inherited parent frame; tail-transfers to 10033906.
__declspec(naked) void __cdecl ClDataSerializeListParseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataSerializeListParseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native six-kind dispatch targets, including type-six reference recursion.
// R6GameService.dll data @ 1002cc90 : native storage identity retained.
const uint GTaggedValueTargets[6] = {R6GameServiceAddresses::GTaggedValueTargetsCase1,R6GameServiceAddresses::GTaggedValueTargetsCase2,R6GameServiceAddresses::GTaggedValueTargetsCase3,R6GameServiceAddresses::GTaggedValueTargetsCase4,R6GameServiceAddresses::GTaggedValueTargetsCase5,R6GameServiceAddresses::GTaggedValueTargetsCase6};

// Writes one tagged payload; nested failure still closes its cached output, preserving the native full return word.
// R6GameService.dll @ 1002cac0 : ECX context, two stack words; saved arguments and growth locals are inferred.
uint __thiscall WriteTaggedValueByType(void *serializer,int *payload,undefined1 *output)
{
  uint value = (uint)payload;
  uint kindIndex = *(uint *)(value + 8) - 1;
  void *savedContext = serializer;
  void *context = serializer;
  if (kindIndex > 5) return value & 0xffffff00u;
  using WriteABI = uint (__thiscall *)(void *,uint,undefined1 *);
  if (kindIndex != 2) {
    uint target;
    switch (kindIndex) {
    case 0: target = R6GameServiceAddresses::WriteTaggedType1; break;
    case 1: target = R6GameServiceAddresses::WriteTaggedType2; break;
    case 3: target = R6GameServiceAddresses::WriteTaggedType4; break;
    case 4: target = R6GameServiceAddresses::WriteTaggedType5; break;
    case 5: target = R6GameServiceAddresses::WriteTaggedValueByType; break;
    }
    undefined1 *childOutput = output;
    if (kindIndex == 5) value = *(uint *)(value + 0xc);
    return ((WriteABI)target)(context,value,childOutput);
  }
  uint outputObject = (uint)output;
  uint end = *(uint *)(outputObject + 0x10);
  auto *triplet = (R6GameServiceNative::ByteRange *)(outputObject + 0xc);
  uint capacity = *(uint *)(outputObject + 0x14);
  if (end != capacity) {
    if (end != 0) *(byte *)end = '[';
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
    uint newEnd = (uint)FillByteRangeAndReturnEnd((undefined1 *)writeAt,1,
        (undefined1 *)R6GameServiceAddresses::TextSLb);
    ReleaseFirstWordBuffer(triplet);
    SetThreeWordRecord(triplet,replacement,newEnd,replacement + allocationBytes);
    value = (uint)payload;
    context = savedContext;
  }
  uint result = WriteTaggedEntryList(context,(int)value,output);
  end = triplet->end;
  capacity = triplet->capacityEnd;
  *(byte *)&output = (byte)result;
  if (end != capacity) {
    if (end != 0) *(byte *)end = ']';
    uint newEnd = triplet->end + 1;
    triplet->end = newEnd;
    return result;
  }
  uint occupiedBytes = end - triplet->begin;
  payload = (int *)1;
  savedContext = (void *)occupiedBytes;
  uint *growth = occupiedBytes < 1 ? (uint *)&payload : (uint *)&savedContext;
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
      (undefined1 *)R6GameServiceAddresses::TextSLb2);
  ReleaseFirstWordBuffer(triplet);
  result = SetThreeWordRecord(triplet,replacement,newEnd,replacement + allocationBytes);
  return (result & 0xffffff00u) | *(byte *)&output;
}

// Installs the primary table and optional secondary table, returning the saved receiver.
// R6GameService.dll @ 1002bdb0 : complete native frame/access order, calling convention and raw ABI retained.
void *__thiscall ConstructClDataSerialize(void *object,int initializeSecondaryTable)
{
  void *owner = object;
  int initialize = initializeSecondaryTable;
  *(uint *)owner = R6GameServiceAddresses::clDataSerializeVTable;
  if (initialize != 0) *(uint *)((uint)owner + 4) = 0x10076ba4;
  return owner;
}

// Resets the serializer table and conditionally frees storage for flag bit zero, returning the saved receiver.
// R6GameService.dll @ 1002bde0 : complete native frame/access order, calling convention and raw ABI retained.
void *__thiscall DeleteClDataSerialize(void *object,byte flags)
{
  void *owner = object;
  ResetClDataSerializeVtable(owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Restore clDataSerialize identity without touching the descriptor or owned bytes.
// R6GameService.dll @ 1002be00 : void cleanup with receiver in ECX and no stack arguments.
void __fastcall ResetClDataSerializeVtable(void *object)
{
  *(uint *)object = R6GameServiceAddresses::clDataSerializeVTable;
}

// Native virtual-table prefix: clDataSerializeVTable
// R6GameService.dll data @ 10076bb0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clDataSerializeVTableRecord {
  R6GameServiceNative::Address DeleteClDataSerialize; // +0x00
};
const clDataSerializeVTableRecord clDataSerializeVTable = {R6GameServiceAddresses::DeleteClDataSerialize};
