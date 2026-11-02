#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007f844 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo TimestampedDescriptorPairExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007f8d8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo TimestampedNodeConstructExceptionHandlerFunctionInfo;

// Native field view: two-byte type/interval/port words retain their untouched two-byte padding.
struct TimestampedDescriptorFields {
  ushort descriptorType;
  byte typePadding[2];
  uint timestamp;
  ushort interval;
  byte intervalPadding[2];
  uint addressBytes[3];
  ushort endpointPort;
  byte portPadding[2];
};

struct TimestampedDescriptorPair {
  uint recordId;
  TimestampedDescriptorFields fields;
};

// Pair-construction locals span logical EBP-0x134..-4, including a distinct copy tag and pointer-derived tag.
struct TimestampedDescriptorPairFrame {
  byte copyTag;
  byte forwardedTag;
  byte pointerTag;
  byte errorMessageTag;
  uint sourceFirst;
  uint sourceLast;
  uint *savedTriplet;
  uint errorMessage[3];
  byte exceptionStorage[0x10c];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs an ID/fields pair with a separately allocated address copy, preserving the scalar fields' padding.
// R6GameService.dll @ 10027a00 : cdecl destination/ID-slot/fields stack words; EAX=destination.
uint * __cdecl ConstructTimestampedDescriptorPair(
    uint *destination,const uint *recordId,const TimestampedDescriptorFields *fields)
{
  TimestampedDescriptorPairFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)TimestampedDescriptorPairExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  destination[0] = *recordId;
  *(ushort *)(destination + 1) = fields->descriptorType;
  destination[2] = fields->timestamp;
  ushort interval = fields->interval;
  frame.sourceLast = 0;
  *(ushort *)(destination + 3) = interval;
  uint *triplet = destination + 4;
  frame.savedTriplet = triplet;
  ForwardStackWord((uint)&frame.forwardedTag);
  triplet[0] = 0;
  triplet[1] = 0;
  triplet[2] = 0;
  frame.sourceLast = fields->addressBytes[1];
  frame.sourceFirst = fields->addressBytes[0];
  frame.state = 0;
  uint allocationBytes = frame.sourceLast - frame.sourceFirst + 1;
  if (allocationBytes == 0) {
    void *tag = ForwardPooledStringTag(&frame.errorMessageTag);
    void *message = ConstructPooledByteString(frame.errorMessage,s_basic_string,(byte *)tag);
    *(byte *)&frame.state = 1;
    ConstructException75c28(frame.exceptionStorage,(undefined4 *)message);
    _CxxThrowException(frame.exceptionStorage,(ThrowInfo *)&ByteStringLengthErrorThrowInfo);
  }
  uint buffer = (uint)AllocateByteStringStorage(allocationBytes);
  triplet[0] = buffer;
  uint capacityEnd = buffer + allocationBytes;
  triplet[1] = buffer;
  triplet[2] = capacityEnd;
  uint sourceLast = frame.sourceLast;
  uint pointerTagAddress = (uint)&frame.pointerTag;
  byte selectedTag;
  __asm {
    mov    ecx,capacityEnd
    push   allocationBytes
    push   buffer
    call   R6GameServiceAddresses::ReturnZero
    add    esp,0x8
    push   eax
    push   sourceLast
    call   R6GameServiceAddresses::ReturnZero
    add    esp,0x4
    push   eax
    push   pointerTagAddress
    call   R6GameServiceAddresses::StoreArgumentLowByteAtAddress
    call   R6GameServiceAddresses::SelectContextHighByteIntoAL
    mov    selectedTag,al
  }
  frame.copyTag = selectedTag;
  uint end = (uint)CopyByteRange(
      (void *)frame.sourceFirst,(void *)frame.sourceLast,(void *)buffer,&frame.copyTag);
  triplet[1] = end;
  *(byte *)end = 0;
  ushort endpointPort = fields->endpointPort;
  void *previousExceptionList = frame.previousExceptionList;
  *(ushort *)(destination + 7) = endpointPort;
  ExceptionList = previousExceptionList;
  return destination;
}

// Releases the saved constructing pair's address triplet.
// R6GameService.dll @ 100656c0 : inherited EBP; MOV ECX,[EBP-0x128], JMP10017330.
__declspec(naked) void __cdecl ReleaseTimestampedPairConstruction(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Releases the pair constructor's error-message triplet before the constructing pair's cleanup.
// R6GameService.dll @ 100656cb : inherited EBP; LEA ECX,[EBP-0x124], JMP10017330.
__declspec(naked) void __cdecl ReleaseTimestampedPairErrorMessage(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects the pair constructor's two-state exception metadata.
// R6GameService.dll @ 100656d6 : EAX=1007f844, inherited-frame JMP10033906.
__declspec(naked) void __cdecl TimestampedDescriptorPairExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TimestampedDescriptorPairExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Node-construction locals span EBP-0x24..-4; savedUnwindStack points below the three saved general registers.
struct TimestampedNodeConstructFrame {
  uint *savedTriplet;
  uint payloadContext;
  uint savedPayloadContext;
  uint allocation;
  byte padding[3];
  byte forwardedTag;
  uint savedUnwindStack;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Allocates a 0x30-byte tree node and constructs its timestamped payload at +0x10; leaves tree links/color untouched.
// R6GameService.dll @ 10028440 : source-record stack word, stdcall RET4; tests adjusted payload, not allocation null.
void * __stdcall AllocateTimestampedDescriptorTreeNode(uint *sourceRecord)
{
  TimestampedNodeConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)TimestampedNodeConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedUnwindStack = (uint)&frame - 0x0c;
  uint allocation = (uint)AllocateGameServiceBytes(0x30);
  uint payload = allocation + 0x10;
  frame.allocation = allocation;
  frame.state = 0;
  frame.savedPayloadContext = payload;
  frame.payloadContext = payload;
  *(byte *)&frame.state = 1;
  if (payload != 0) {
    const uint *source = sourceRecord;
    uint *triplet = (uint *)(payload + 0x10);
    frame.savedTriplet = triplet;
    *(uint *)payload = source[0];
    *(ushort *)(payload + 4) = *(const ushort *)(source + 1);
    *(uint *)(payload + 8) = source[2];
    ushort interval = *(const ushort *)(source + 3);
    *(ushort *)(payload + 0x0c) = interval;
    uint forwardedTag = ForwardStackWord((uint)&frame.forwardedTag);
    triplet[0] = 0;
    triplet[1] = 0;
    StoreFirstWordIgnoringContext(triplet + 2,forwardedTag,0);
    byte *sourceArgumentTag = (byte *)&sourceRecord + 3;
    byte tag = *sourceArgumentTag;
    uint sourceLast = source[5];
    uint sourceFirst = source[4];
    *sourceArgumentTag = tag;
    *(byte *)&frame.state = 2;
    ConstructByteStringRange(triplet,(void *)sourceFirst,(void *)sourceLast,sourceArgumentTag);
    *(ushort *)(payload + 0x1c) = *(const ushort *)(source + 7);
  }
  ExceptionList = frame.previousExceptionList;
  return (void *)allocation;
}

// Forwards both saved payload-context words to empty cleanup and leaves the loaded first word in EAX.
// R6GameService.dll @ 10065710 : inherited EBP; PUSH[EBP-0x1c], PUSH[EBP-0x20], CALL59130, caller pop8/RET.
__declspec(naked) void __cdecl CleanupTimestampedNodePayloadContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x1c]
    push   eax
    mov    ecx,dword ptr [ebp-0x20]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Releases the saved payload triplet before the node-construction catch frees its object storage.
// R6GameService.dll @ 10065721 : inherited EBP; MOV ECX,[EBP-0x24], JMP10017330.
__declspec(naked) void __cdecl ReleaseTimestampedNodeConstructedTriplet(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Frees the saved node allocation and rethrows the current exception after constructor-state unwinding.
// R6GameService.dll @ 10028505 : inherited EBP; CALL6390 with [EBP-0x18], then _CxxThrowException(0,0).
__declspec(naked) void __cdecl RethrowTimestampedNodeConstruction(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x18]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push   0
    push   0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the node constructor's four-state unwind map and catch-all allocation-release handler.
// R6GameService.dll @ 10065729 : EAX=1007f8d8, inherited-frame JMP10033906.
__declspec(naked) void __cdecl TimestampedNodeConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TimestampedNodeConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finds an unsigned record ID or inserts a copied timestamped node; output contains node word plus one-byte inserted flag.
// R6GameService.dll @ 10027600 : ECX tree header/count, output/record stack words, RET8; EAX=output, no local EH frame.
int * __thiscall FindOrInsertUnsignedKeyTreeEntry(void *tree,int *output,uint *record)
{
  uint initialHeader = *(uint *)tree;
  uint parent = initialHeader;
  uint searchNode = *(uint *)(initialHeader + 4);
  bool wentLeft = true;
  if (searchNode != 0) {
    uint searchKey = record[0];
    do {
      parent = searchNode;
      wentLeft = searchKey < *(uint *)(parent + 0x10);
      searchNode = *(uint *)(parent + (wentLeft ? 8 : 0x0c));
    } while (searchNode != 0);
  }
  bool insertLeft;
  if (wentLeft && parent == *(uint *)(initialHeader + 8)) {
    insertLeft = parent == initialHeader || searchNode != 0 || record[0] < *(uint *)(parent + 0x10);
  } else {
    uint candidate = wentLeft ? (uint)OrderedTreePredecessor((int)parent) : parent;
    uint insertionKey = record[0];
    if (*(uint *)(candidate + 0x10) >= insertionKey) {
      output[0] = candidate;
      *(byte *)(output + 1) = 0;
      return output;
    }
    insertLeft = parent == *(uint *)tree || searchNode != 0 || insertionKey < *(uint *)(parent + 0x10);
  }
  uint node = (uint)AllocateTimestampedDescriptorTreeNode(record);
  if (insertLeft) {
    *(uint *)(parent + 8) = node;
    uint header = *(uint *)tree;
    if (parent == header) {
      *(uint *)(header + 4) = node;
      header = *(uint *)tree;
      *(uint *)(header + 0x0c) = node;
    } else if (parent == *(uint *)(header + 8)) {
      *(uint *)(header + 8) = node;
    }
  } else {
    *(uint *)(parent + 0x0c) = node;
    uint header = *(uint *)tree;
    if (parent == *(uint *)(header + 0x0c)) *(uint *)(header + 0x0c) = node;
  }
  *(uint *)(node + 4) = parent;
  *(uint *)(node + 8) = 0;
  *(uint *)(node + 0x0c) = 0;
  uint header = *(uint *)tree;
  RebalanceOrderedTreeAfterInsertion((char *)node,(int *)(header + 4));
  ((uint *)tree)[1] = ((uint *)tree)[1] + 1;
  output[0] = node;
  *(byte *)(output + 1) = 1;
  return output;
}
