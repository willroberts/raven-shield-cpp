#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007f7ec : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fad4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListCloneExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fb58 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListAssignmentExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fbd0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListIndentExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fc0c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListStringAppendExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fca8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListAppendExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fd30 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo BoundedIndexedStringExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fe84 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo IndexedTextScalarExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fec0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ExactIndexedBytesExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007ff14 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListSerializationExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007ff58 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataListParseExceptionHandlerFunctionInfo;

// Native clDataList destructor frame and iterator argument copies from EBP-0x30 through EBP-4.
struct ClDataListDestructionFrame {
  uint firstIterator;
  uint endIterator;
  byte savedRegisterSlots[16];
  void *savedObject;
  void *savedInnerList;
  uint iterationResult;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the embedded clData-pointer list and resets the enclosing object to its clData vtable.
// R6GameService.dll @ 100270c0 : ECX object, no stack arguments; returns final allocator EAX.
uint __fastcall DestroyClDataList(void *object)
{
  ClDataListDestructionFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)ClDataListExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedObject = object;
  uint *innerList = (uint *)((byte *)object + 0x0c);
  *(uint *)object = (uint)&clDataListPTR_FUN;
  innerList[0] = (uint)&clDataListPTR_LAB;
  frame.state = 0;
  frame.savedInnerList = innerList;
  innerList[0] = (uint)&clDataListPTR_FUN2;
  frame.endIterator = innerList[1];
  uint *vtable = (uint *)innerList[0];
  frame.state = 1;
  ReadListFirstNodeFromHeadSlot(innerList + 1,&frame.firstIterator);
  typedef uint (__thiscall *ReleaseRange)(void *,uint *,uint,uint);
  ReleaseRange releaseRange = (ReleaseRange)vtable[4];
  releaseRange(innerList,&frame.iterationResult,frame.firstIterator,frame.endIterator);
  uint *node = *(uint **)innerList[1];
  while (node != (uint *)innerList[1]) {
    uint *next = (uint *)node[0];
    TailFreeThroughGlobalAllocator(node);
    node = next;
  }
  uint *sentinel = (uint *)innerList[1];
  sentinel[0] = (uint)sentinel;
  sentinel = (uint *)innerList[1];
  sentinel[1] = (uint)sentinel;
  uint result = TailFreeThroughGlobalAllocator((void *)innerList[1]);
  *(uint *)object = (uint)&PTR_LAB;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Tail-forwards original descriptor receiver/frame to the canonical list destructor without adjustment.
// R6GameService.dll @ 100271b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall DestroyClDataListAlias(void *object)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClDataList
  }
}

// Resets the saved enclosing object to the clData base vtable during destruction unwinding.
// R6GameService.dll @ 10065660 : inherited EBP-0x18 saved object; native tail target.
__declspec(naked) void __cdecl ResetClDataListBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x18]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Releases the embedded list's storage through its head slot, retaining native null forwarding.
// R6GameService.dll @ 10065668 : EBP-0x14 inner list; EBP-0x24 scratch; JMP10059140.
__declspec(naked) void __cdecl ReleaseClDataListStorageOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_list
    mov    eax,dword ptr [ebp-0x14]
    add    eax,4
    mov    dword ptr [ebp-0x24],eax
    jmp    forward_cleanup
  null_list:
    mov    dword ptr [ebp-0x24],0
  forward_cleanup:
    mov    ecx,dword ptr [ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects the complete list destructor's two-state FuncInfo for the shared C++ frame handler.
// R6GameService.dll @ 1006568f : EAX=1007f7ec; inherited-frame exception ABI.
__declspec(naked) void __cdecl ClDataListExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native bounded-reader locals from logical parent EBP-0x28 through EBP-4.
struct BoundedIndexedStringFrame {
  uint zeroScratch;
  uint descriptor[6];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Native scalar/unbounded-reader locals from EBP-0x2c through EBP-4; the tag byte is an unused constructor argument.
struct IndexedTextScalarFrame {
  byte padding[3];
  byte constructorTag;
  uint zeroScratch;
  uint descriptor[6];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Native cleanup views retain allocator EAX while the existing semantic declarations expose void.
typedef uint (__fastcall *IndexedFirstWordFreeStatus)(void *);
typedef uint (__stdcall *IndexedSizedFreeStatus)(void *,uint);

// Copies indexed text, forces the last byte to zero when truncated, and returns fit/retrieval AL with cleanup upper EAX.
// R6GameService.dll @ 1002a190 : ECX source, RET 0xc; capacity zero still accesses destination-1.
uint __thiscall CopyIndexedStringBounded(void *source,char *destination,uint index,uint capacity)
{
  BoundedIndexedStringFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)BoundedIndexedStringExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataStrBaseOffsets;
  frame.descriptor[2] = 1;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.state = 0;
  InitializeEmptyByteString(frame.descriptor + 3);
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 1;
  uint retrievalResult = CopyIndexedTypeOneBytes(source,(int)frame.descriptor,index);
  IndexedFirstWordFreeStatus freeBuffer = (IndexedFirstWordFreeStatus)ReleaseFirstWordBuffer;
  if ((byte)retrievalResult == 0) {
    frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
    frame.state = 3;
    index = (uint)(frame.descriptor + 3);
    frame.state = 4;
    uint cleanupResult = freeBuffer(frame.descriptor + 3);
    ExceptionList = frame.previousExceptionList;
    return cleanupResult & 0xffffff00;
  }
  strncpy(destination,(char *)frame.descriptor[3],capacity);
  char *lastByte = (char *)((uint)destination + capacity - 1);
  byte fits = *lastByte == '\0' ? 1 : 0;
  if (fits == 0) *lastByte = '\0';
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 2;
  uint cleanupResult = freeBuffer(frame.descriptor + 3);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | fits;
}

// Reads indexed text with atoi and writes its 32-bit value only when retrieval succeeds.
// R6GameService.dll @ 1002a290 : ECX source, RET 8; retrieval AL is retained with final allocator upper EAX.
uint __thiscall ReadIndexedInt32(void *source,int *output,uint index)
{
  IndexedTextScalarFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)IndexedTextScalarExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataStrBaseOffsets;
  frame.descriptor[2] = 1;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.descriptor[3] = 0;
  frame.descriptor[4] = 0;
  frame.state = 1;
  StoreFirstWordIgnoringContext(frame.descriptor + 5,(uint)&frame.constructorTag,0);
  uint allocation = (uint)AllocateGameServiceBytes(8);
  frame.descriptor[3] = allocation;
  frame.descriptor[4] = allocation;
  frame.descriptor[5] = allocation + 8;
  *(byte *)allocation = 0;
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 2;
  byte retrieved = (byte)CopyIndexedTypeOneBytes(source,(int)frame.descriptor,index);
  if (retrieved != 0) {
    int parsedValue = atoi((char *)frame.descriptor[3]);
    *output = parsedValue;
  }
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 3;
  index = (uint)(frame.descriptor + 3);
  frame.state = 4;
  IndexedSizedFreeStatus freeBuffer = (IndexedSizedFreeStatus)ReleaseMemoryIgnoringSize;
  uint cleanupResult = freeBuffer((void *)frame.descriptor[3],frame.descriptor[5] - frame.descriptor[3]);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | retrieved;
}

// Reads indexed text with atoi and writes its low word only when retrieval succeeds.
// R6GameService.dll @ 1002a380 : ECX source, RET 8; retrieval AL is retained with final allocator upper EAX.
uint __thiscall ReadIndexedWord(void *source,undefined2 *output,uint index)
{
  IndexedTextScalarFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)IndexedTextScalarExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataStrBaseOffsets;
  frame.descriptor[2] = 1;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.descriptor[3] = 0;
  frame.descriptor[4] = 0;
  frame.state = 1;
  StoreFirstWordIgnoringContext(frame.descriptor + 5,(uint)&frame.constructorTag,0);
  uint allocation = (uint)AllocateGameServiceBytes(8);
  frame.descriptor[3] = allocation;
  frame.descriptor[4] = allocation;
  frame.descriptor[5] = allocation + 8;
  *(byte *)allocation = 0;
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 2;
  byte retrieved = (byte)CopyIndexedTypeOneBytes(source,(int)frame.descriptor,index);
  if (retrieved != 0) {
    int parsedValue = atoi((char *)frame.descriptor[3]);
    *output = (undefined2)parsedValue;
  }
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 3;
  index = (uint)(frame.descriptor + 3);
  frame.state = 4;
  IndexedSizedFreeStatus freeBuffer = (IndexedSizedFreeStatus)ReleaseMemoryIgnoringSize;
  uint cleanupResult = freeBuffer((void *)frame.descriptor[3],frame.descriptor[5] - frame.descriptor[3]);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | retrieved;
}

// Reads indexed text with atoi and writes its low byte only when retrieval succeeds.
// R6GameService.dll @ 1002a480 : ECX source, RET 8; retrieval AL is retained with final allocator upper EAX.
uint __thiscall ReadIndexedByte(void *source,undefined1 *output,uint index)
{
  IndexedTextScalarFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)IndexedTextScalarExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataStrBaseOffsets;
  frame.descriptor[2] = 1;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.descriptor[3] = 0;
  frame.descriptor[4] = 0;
  frame.state = 1;
  StoreFirstWordIgnoringContext(frame.descriptor + 5,(uint)&frame.constructorTag,0);
  uint allocation = (uint)AllocateGameServiceBytes(8);
  frame.descriptor[3] = allocation;
  frame.descriptor[4] = allocation;
  frame.descriptor[5] = allocation + 8;
  *(byte *)allocation = 0;
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 2;
  byte retrieved = (byte)CopyIndexedTypeOneBytes(source,(int)frame.descriptor,index);
  if (retrieved != 0) {
    int parsedValue = atoi((char *)frame.descriptor[3]);
    *output = (undefined1)parsedValue;
  }
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 3;
  index = (uint)(frame.descriptor + 3);
  frame.state = 4;
  IndexedSizedFreeStatus freeBuffer = (IndexedSizedFreeStatus)ReleaseMemoryIgnoringSize;
  uint cleanupResult = freeBuffer((void *)frame.descriptor[3],frame.descriptor[5] - frame.descriptor[3]);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | retrieved;
}

// Copies indexed text through its NUL without a capacity argument; retrieval failure leaves the destination untouched.
// R6GameService.dll @ 1002a0a0 : ECX source, RET 8; raw allocator upper EAX plus saved retrieval AL.
uint __thiscall CopyIndexedClDataString(void *source,int destinationAddress,uint index)
{
  IndexedTextScalarFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)IndexedTextScalarExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataStrBaseOffsets;
  frame.descriptor[2] = 1;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.descriptor[3] = 0;
  frame.descriptor[4] = 0;
  frame.state = 1;
  StoreFirstWordIgnoringContext(frame.descriptor + 5,(uint)&frame.constructorTag,0);
  uint allocation = (uint)AllocateGameServiceBytes(8);
  frame.descriptor[3] = allocation;
  frame.descriptor[4] = allocation;
  frame.descriptor[5] = allocation + 8;
  *(byte *)allocation = 0;
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 2;
  byte retrieved = (byte)CopyIndexedTypeOneBytes(source,(int)frame.descriptor,index);
  char *buffer = (char *)frame.descriptor[3];
  if (retrieved != 0) {
    char *cursor = buffer;
    char *destination = (char *)destinationAddress;
    char character;
    do {
      character = *cursor++;
      *destination++ = character;
    } while (character != '\0');
  }
  frame.descriptor[0] = (uint)&clDataStrPTR_FUN;
  frame.state = 3;
  index = (uint)(frame.descriptor + 3);
  frame.state = 4;
  IndexedSizedFreeStatus freeBuffer = (IndexedSizedFreeStatus)ReleaseMemoryIgnoringSize;
  uint cleanupResult = freeBuffer(buffer,frame.descriptor[5] - (uint)buffer);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | retrieved;
}

// Resets the partially constructed bounded-reader descriptor at parent EBP-0x24.
// R6GameService.dll @ 10065af0 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl ResetBoundedIndexedStringBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the bounded-reader string descriptor at parent EBP-0x24.
// R6GameService.dll @ 10065af8 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl DestroyBoundedIndexedString(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataStrAlias
  }
}

// Resets the bounded-reader descriptor while its successful-copy buffer cleanup unwinds.
// R6GameService.dll @ 10065b00 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl ResetBoundedStringAfterCopy(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the bounded-reader descriptor while retrieval-failure cleanup unwinds.
// R6GameService.dll @ 10065b08 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl ResetBoundedStringAfterFailure(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Adds eight to the pointer saved in original argument 2 and tail-forwards to empty cleanup.
// R6GameService.dll @ 10065b10 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl CleanupBoundedStringSavedContext(void)
{
  __asm {
    mov    ecx,dword ptr [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Installs bounded-reader FuncInfo 0x1007fd30 and tail-transfers to the shared frame handler.
// R6GameService.dll @ 10065b1b : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl BoundedIndexedStringExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::BoundedIndexedStringExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Resets the shared scalar/unbounded-reader descriptor at parent EBP-0x24.
// R6GameService.dll @ 10065b30 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl ResetIndexedTextScalarBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards the local constructor tag at parent EBP-0x29 to empty cleanup.
// R6GameService.dll @ 10065b38 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl CleanupIndexedScalarConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp-0x29]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the shared scalar/unbounded-reader descriptor at parent EBP-0x24.
// R6GameService.dll @ 10065b40 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl DestroyIndexedTextScalar(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataStrAlias
  }
}

// Resets the shared scalar/unbounded-reader descriptor during buffer release.
// R6GameService.dll @ 10065b48 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl ResetIndexedScalarDuringRelease(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Adds eight to the triplet pointer saved in original argument 2 and tail-forwards to empty cleanup.
// R6GameService.dll @ 10065b50 : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl CleanupIndexedScalarSavedContext(void)
{
  __asm {
    mov    ecx,dword ptr [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Installs shared reader FuncInfo 0x1007fe84 and tail-transfers to the common frame handler.
// R6GameService.dll @ 10065b5b : private inherited-frame ABI; native context and tail operands retained.
__declspec(naked) void __cdecl IndexedTextScalarExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::IndexedTextScalarExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native exact-byte reader locals from logical parent EBP-0x2c through EBP-4.
struct ExactIndexedBytesFrame {
  uint zeroScratch;
  uint descriptor[7];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Copies indexed type-two bytes only on equal length, retaining the native AL mask and release upper EAX.
// R6GameService.dll @ 1002a570 : ECX source, destination/count/index stack words, RET 0xc.
uint __thiscall CopyIndexedBytesExact(void *source,void *destination,uint expectedBytes,uint index)
{
  ExactIndexedBytesFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)ExactIndexedBytesExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.zeroScratch = 0;
  frame.descriptor[1] = (uint)&ClDataBinOwnerBaseOffsets;
  frame.descriptor[6] = (uint)&ClDataBinBaseOffsets;
  frame.descriptor[2] = 2;
  frame.descriptor[0] = (uint)&PTR_LAB;
  frame.state = 0;
  InitializeEmptyByteBufferTriplet(frame.descriptor + 3,0);
  frame.descriptor[0] = (uint)&clDataBinPTR_FUN;
  frame.state = 1;
  byte status = (byte)CopyIndexedClDataBin(source,frame.descriptor,index);
  uint buffer = frame.descriptor[3];
  if (status != 0) {
    uint end = frame.descriptor[4];
    uint byteCount = end - buffer;
    status &= expectedBytes == byteCount ? 1 : 0;
    if (status != 0 && end != buffer) {
      memmove(destination,(void *)buffer,byteCount);
      buffer = frame.descriptor[3];
    }
  }
  frame.descriptor[0] = (uint)&clDataBinPTR_FUN;
  frame.state = 2;
  index = (uint)(frame.descriptor + 3);
  frame.state = 3;
  uint cleanupResult = buffer;
  if (buffer != 0) {
    IndexedSizedFreeStatus freeBuffer = (IndexedSizedFreeStatus)ReleaseMemoryIgnoringSize;
    cleanupResult = freeBuffer((void *)buffer,frame.descriptor[5] - buffer);
  }
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | status;
}

// Resets the exact-byte reader descriptor at parent EBP-0x28 while construction unwinds.
// R6GameService.dll @ 10065b70 : inherited parent frame; tail-transfers to the base-vtable reset.
__declspec(naked) void __cdecl ResetExactIndexedBytesBase(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the exact-byte reader descriptor at parent EBP-0x28.
// R6GameService.dll @ 10065b78 : inherited parent frame; tail-transfers to descriptor destruction.
__declspec(naked) void __cdecl DestroyExactIndexedBytes(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the exact-byte descriptor's base vtable if buffer release unwinds.
// R6GameService.dll @ 10065b80 : inherited parent frame; descriptor at EBP-0x28.
__declspec(naked) void __cdecl ResetExactBytesDuringRelease(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Adds eight to the triplet address saved in original argument 3 and tail-forwards to empty cleanup.
// R6GameService.dll @ 10065b88 : inherited parent frame; saved context at EBP+0xc.
__declspec(naked) void __cdecl CleanupExactBytesSavedContext(void)
{
  __asm {
    mov    ecx,dword ptr [ebp+0xc]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects exact-byte reader FuncInfo 0x1007fec0 for the shared C++ exception handler.
// R6GameService.dll @ 10065b93 : inherited parent frame; tail-transfers to 10033906.
__declspec(naked) void __cdecl ExactIndexedBytesExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ExactIndexedBytesExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Retrieves an indexed clDataBin pointer, retrying once through a type-six wrapper after a failed direct cast.
// R6GameService.dll @ 10029f00 : ECX source, output/index stack words, RET 8; early failures leave output untouched.
uint __thiscall GetIndexedClDataBin(void *source,int *output,uint index)
{
  typedef uint (__thiscall *CountMethod)(void *);
  CountMethod getCount = *(CountMethod *)(*(byte **)source + 0x18);
  uint count = getCount(source);
  uint eaxResidue = count;
  if (index >= count) return eaxResidue & 0xffffff00;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)source + 0x10);
    eaxResidue = (uint)sentinel;
    node = (uint *)sentinel[0];
    while (index != 0) {
      node = (uint *)node[0];
      --index;
    }
  } else {
    node = *(uint **)((byte *)source + 0x10);
    eaxResidue = count - index;
    do {
      node = (uint *)node[1];
      --eaxResidue;
    } while (eaxResidue != 0);
  }
  int payload = node[2];
  if (payload == 0) return eaxResidue & 0xffffff00;
  int converted = __RTDynamicCast(payload,0,&clData::RTTI_Type_Descriptor,&clDataBin::RTTI_Type_Descriptor,0);
  *output = converted;
  if (converted != 0) return ((uint)converted & 0xffffff00) | 1;
  if (*(uint *)(payload + 8) != 6) return 0;
  int wrappedPayload = *(int *)(payload + 0x0c);
  converted = __RTDynamicCast(wrappedPayload,0,&clData::RTTI_Type_Descriptor,&clDataBin::RTTI_Type_Descriptor,0);
  *output = converted;
  return converted == 0 ? 0 : ((uint)converted & 0xffffff00) | 1;
}

// Retrieves an indexed clDataList pointer, retrying once through a type-six wrapper after a failed direct cast.
// R6GameService.dll @ 1002a000 : ECX source, output/index stack words, RET 8; early failures leave output untouched.
uint __thiscall GetIndexedClDataList(void *source,int *output,uint index)
{
  typedef uint (__thiscall *CountMethod)(void *);
  CountMethod getCount = *(CountMethod *)(*(byte **)source + 0x18);
  uint count = getCount(source);
  uint eaxResidue = count;
  if (index >= count) return eaxResidue & 0xffffff00;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)source + 0x10);
    eaxResidue = (uint)sentinel;
    node = (uint *)sentinel[0];
    while (index != 0) {
      node = (uint *)node[0];
      --index;
    }
  } else {
    node = *(uint **)((byte *)source + 0x10);
    eaxResidue = count - index;
    do {
      node = (uint *)node[1];
      --eaxResidue;
    } while (eaxResidue != 0);
  }
  int payload = node[2];
  if (payload == 0) return eaxResidue & 0xffffff00;
  int converted = __RTDynamicCast(payload,0,&clData::RTTI_Type_Descriptor,&clDataList::RTTI_Type_Descriptor,0);
  *output = converted;
  if (converted != 0) return ((uint)converted & 0xffffff00) | 1;
  if (*(uint *)(payload + 8) != 6) return 0;
  int wrappedPayload = *(int *)(payload + 0x0c);
  converted = __RTDynamicCast(wrappedPayload,0,&clData::RTTI_Type_Descriptor,&clDataList::RTTI_Type_Descriptor,0);
  *output = converted;
  return converted == 0 ? 0 : ((uint)converted & 0xffffff00) | 1;
}

// Copies an indexed type-1 payload, selecting the nearer end of the clDataList node chain.
// R6GameService.dll @ 10029da0 : ECX source list, destination/index stack words, RET 8; status AL and raw upper EAX.
uint __thiscall CopyIndexedTypeOneBytes(void *source,int destinationAddress,uint index)
{
  typedef uint (__thiscall *CountMethod)(void *);
  CountMethod getCount = *(CountMethod *)(*(byte **)source + 0x18);
  uint count = getCount(source);
  uint eaxResidue = count;
  if (index >= count) return eaxResidue & 0xffffff00;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)source + 0x10);
    eaxResidue = (uint)sentinel;
    node = (uint *)sentinel[0];
    uint remaining = index;
    while (remaining != 0) {
      node = (uint *)node[0];
      --remaining;
    }
  } else {
    node = *(uint **)((byte *)source + 0x10);
    eaxResidue = count - index;
    do {
      node = (uint *)node[1];
      --eaxResidue;
    } while (eaxResidue != 0);
  }
  uint payload = node[2];
  if (payload == 0 || *(uint *)(payload + 8) != 1) return eaxResidue & 0xffffff00;
  uint destination = (uint)destinationAddress;
  if (payload == destination) return (eaxResidue & 0xffffff00) | 1;
  uint sourceTripletAddress = payload + 0x0c;
  uint adjustedDestination = destination == 0 ? 0 : destination + 0x0c;
  if (sourceTripletAddress == adjustedDestination) return (sourceTripletAddress & 0xffffff00) | 1;
  uint *destinationTriplet = destination == 0 ? nullptr : (uint *)(destination + 0x0c);
  if (sourceTripletAddress == (uint)destinationTriplet) return (sourceTripletAddress & 0xffffff00) | 1;
  uint *sourceTriplet = (uint *)sourceTripletAddress;
  uint sourceEnd = sourceTriplet[1];
  uint sourceCursor = sourceTriplet[0];
  uint destinationCursor = destinationTriplet[0];
  while (sourceCursor != sourceEnd && destinationCursor != destinationTriplet[1]) {
    byte value = *(byte *)sourceCursor;
    ++sourceCursor;
    *(byte *)destinationCursor = value;
    ++destinationCursor;
  }
  if (sourceCursor != sourceEnd) {
    *(byte *)&index = *(byte *)&index;
    uint result = (uint)AppendByteRangeWithGrowth(
        destinationTriplet,(undefined1 *)sourceCursor,(undefined1 *)sourceEnd,(uint)&index);
    return (result & 0xffffff00) | 1;
  }
  uint oldEnd = destinationTriplet[1];
  if (destinationCursor == oldEnd) return (sourceCursor & 0xffffff00) | 1;
  memmove((void *)destinationCursor,(void *)oldEnd,1);
  uint newEnd = destinationTriplet[1] + (destinationCursor - oldEnd);
  destinationTriplet[1] = newEnd;
  return (newEnd & 0xffffff00) | 1;
}

// Copies an indexed type-2 payload, selecting the nearer end of the clDataList node chain.
// R6GameService.dll @ 10029e90 : ECX source list, destination/index stack words, RET 8; status AL and raw upper EAX.
uint __thiscall CopyIndexedClDataBin(void *source,void *destination,uint index)
{
  typedef uint (__thiscall *CountMethod)(void *);
  CountMethod getCount = *(CountMethod *)(*(byte **)source + 0x18);
  uint count = getCount(source);
  uint eaxResidue = count;
  if (index >= count) return eaxResidue & 0xffffff00;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)source + 0x10);
    eaxResidue = (uint)sentinel;
    node = (uint *)sentinel[0];
    uint remaining = index;
    while (remaining != 0) {
      node = (uint *)node[0];
      --remaining;
    }
  } else {
    node = *(uint **)((byte *)source + 0x10);
    eaxResidue = count - index;
    do {
      node = (uint *)node[1];
      --eaxResidue;
    } while (eaxResidue != 0);
  }
  uint payload = node[2];
  if (payload == 0 || *(uint *)(payload + 8) != 2) return payload & 0xffffff00;
  uint result = payload;
  if (payload != (uint)destination) result = AssignClDataBinByteRange(destination,(uint *)(payload + 0x0c));
  return (result & 0xffffff00) | 1;
}

// Copies an indexed type-3 payload, selecting the nearer end of the clDataList node chain.
// R6GameService.dll @ 10029fa0 : ECX source list, destination/index stack words, RET 8; status AL and raw upper EAX.
uint __thiscall CopyIndexedClDataList(void *source,void *destination,uint index)
{
  typedef uint (__thiscall *CountMethod)(void *);
  CountMethod getCount = *(CountMethod *)(*(byte **)source + 0x18);
  uint count = getCount(source);
  uint eaxResidue = count;
  if (index >= count) return eaxResidue & 0xffffff00;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)source + 0x10);
    eaxResidue = (uint)sentinel;
    node = (uint *)sentinel[0];
    uint remaining = index;
    while (remaining != 0) {
      node = (uint *)node[0];
      --remaining;
    }
  } else {
    node = *(uint **)((byte *)source + 0x10);
    eaxResidue = count - index;
    do {
      node = (uint *)node[1];
      --eaxResidue;
    } while (eaxResidue != 0);
  }
  void *payload = (void *)node[2];
  if (payload == nullptr || *(uint *)((byte *)payload + 8) != 3) return eaxResidue & 0xffffff00;
  uint result = AssignClDataList(destination,payload);
  return (result & 0xffffff00) | 1;
}

// Returns the indexed clData payload, walking from the nearer end; out-of-range indices return zero.
// R6GameService.dll @ 1002a670 : ECX clDataList, unsigned index stack word, RET 4; EAX=payload.
uint __thiscall GetIndexedPayload(void *list,uint index)
{
  typedef uint (__thiscall *CountElements)(void *);
  uint count = ((CountElements)(*(uint **)list)[6])(list);
  if (index >= count) return 0;
  uint *node;
  if (index < (count >> 1)) {
    uint *sentinel = *(uint **)((byte *)list + 0x10);
    node = (uint *)sentinel[0];
    while (index != 0) {
      node = (uint *)node[0];
      --index;
    }
  } else {
    node = *(uint **)((byte *)list + 0x10);
    uint remaining = count - index;
    do {
      node = (uint *)node[1];
      --remaining;
    } while (remaining != 0);
  }
  return node[2];
}

// Writes a nonnull indexed type-one payload to output; AL reports success and upper EAX retains its pointer bits.
// R6GameService.dll @ 1002a6c0 : ECX clDataList, output/index stack words, RET 8.
uint __thiscall GetIndexedTypeOnePayload(void *list,int *output,uint index)
{
  uint payload = GetIndexedPayload(list,index);
  if (payload == 0 || *(uint *)(payload + 8) != 1) return payload & 0xffffff00;
  *output = (int)payload;
  return (payload & 0xffffff00) | 1;
}

// Normalized entry-frame locals at -0x30 through -4; binary words +3..+5 hold its byte triplet.
struct ClDataListSerializationFrame {
  uint serializer[2];
  uint binary[7];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Serializes via temporaries, reuses the size-pointer argument for copy length, and retains cleanup upper EAX.
// R6GameService.dll @ 1002a700 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall SerializeClDataListToBuffer(
    void *list,void *destination,uint *capacityAndSize)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListSerializationExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push   ebx
    xor    eax,eax
    push   ebp
    push   esi
    // Entry frame: serializer-0x30/-0x2c, binary-0x28..-0x10, FS/handler/state-0x0c/-8/-4.
    mov    DWORD PTR [esp+0xc],eax
    // Cache the original size pointer before its argument word becomes the serialized-length scratch slot.
    mov    esi,DWORD PTR [esp+0x44]
    push   edi
    cmp    esi,eax
    mov    edi,ecx
    je Branch5
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x20],0x2
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x40],eax
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    ebp,R6GameServiceAddresses::clDataBinPTR_FUN
    mov    DWORD PTR [esp+0x18],ebp
    mov    ebx,0x1
    lea    ecx,[esp+0x10]
    push   ebx
    mov    DWORD PTR [esp+0x40],ebx
    call   R6GameServiceAddresses::ConstructClDataSerialize
    // State2 covers the serializer write; only AL controls the following branch.
    lea    eax,[esp+0x18]
    lea    ecx,[esp+0x10]
    push   eax
    push   edi
    mov    BYTE PTR [esp+0x44],0x2
    call   R6GameServiceAddresses::WriteTaggedEntries
    test   al,al
    jne Branch1
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esi],0x0
    mov    BYTE PTR [esp+0x3c],bl
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x3c],0x3
    jmp Branch4
    // Cache output begin/length and load destination late; overwrite original size-pointer argument with length.
  Branch1:
    mov    eax,DWORD PTR [esp+0x28]
    mov    edi,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [esp+0x44]
    sub    eax,edi
    test   ecx,ecx
    mov    DWORD PTR [esp+0x48],eax
    je Branch3
    cmp    DWORD PTR [esi],eax
    jb Branch3
    // Pass the original argument slot as the copy helper size word, not a new local variable.
    lea    edx,[esp+0x48]
    push   edx
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyClDataBinBytesToBuffer
    test   al,al
    lea    ecx,[esp+0x10]
    mov    BYTE PTR [esp+0x3c],bl
    jne Branch2
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x3c],0x5
    jmp Branch4
    // Copy success publishes the possibly modified scratch length through the cached original size pointer.
  Branch2:
    mov    eax,DWORD PTR [esp+0x48]
    mov    DWORD PTR [esi],eax
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x18],ebp
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x3c],0x6
    call   R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    al,bl
    jmp Branch6
    // Size probe writes required count and enters its own release state4.
  Branch3:
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esi],eax
    mov    BYTE PTR [esp+0x3c],bl
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x3c],0x4
  Branch4:
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    // Clear only AL; invalid-size early exit already has EAX0, release paths keep the actual cleanup upper word.
  Branch5:
    xor    al,al
  Branch6:
    mov    ecx,DWORD PTR [esp+0x34]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x8
  }
}

// Copies raw counted input into a temporary binary, parses the list and returns full parser AL with cleanup upper EAX.
// R6GameService.dll @ 1002a880 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall ParseClDataListBytes(void *list,undefined1 *source,int byteCount)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListParseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push   esi
    push   edi
    // Only serializer word0 is cleared before null-source early return; incoming count remains a full word.
    mov    DWORD PTR [esp+0x8],0x0
    mov    edi,DWORD PTR [esp+0x3c]
    test   edi,edi
    mov    esi,ecx
    jne Branch7
    // Null-source AL0 retains incoming previous-FS upper EAX.
    pop    edi
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x8
  Branch7:
    push   ebx
    mov    ebx,0x2
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    // Pass the original source argument address as context while EDI retains the earlier source pointer.
    lea    eax,[esp+0x40]
    lea    ecx,[esp+0x20]
    push   eax
    mov    DWORD PTR [esp+0x3c],0x1
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataBinPTR_FUN
    // Load count after triplet initialization; the setter gets cached source EDI and the late count word.
    mov    ecx,DWORD PTR [esp+0x44]
    mov    DWORD PTR [esp+0x38],ebx
    push   ecx
    push   edi
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::ReplaceClDataBinBytes
    push   0x1
    lea    ecx,[esp+0x10]
    call   R6GameServiceAddresses::ConstructClDataSerialize
    lea    edx,[esp+0x14]
    push   esi
    push   edx
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x40],0x3
    call   R6GameServiceAddresses::ParseTaggedValues
    // Save the parser byte in BL, lower state, reset serializer and release binary while retaining that byte.
    lea    ecx,[esp+0xc]
    mov    bl,al
    mov    BYTE PTR [esp+0x38],0x2
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataBinPTR_FUN
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x38],0x4
    call   R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x30]
    mov    al,bl
    pop    ebx
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x8
  }
}

// Resets the serialization temporary base vtable if triplet construction unwinds.
// R6GameService.dll @ 10065ba0 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationBinaryBase(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the serialization temporary binary during conversion unwinding.
// R6GameService.dll @ 10065ba8 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl DestroySerializationBinary(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the serialization context before unwinding its temporary binary.
// R6GameService.dll @ 10065bb0 : inherited parent EBP; ECX=&[ebp-0x30], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationSerializer(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Resets the serialization binary base vtable if failure-path storage release unwinds.
// R6GameService.dll @ 10065bb8 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationBinaryAfterFailure(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the serialization binary base vtable if failed-copy storage release unwinds.
// R6GameService.dll @ 10065bc0 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationBinaryAfterCopyFailure(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the serialization binary base vtable if successful-copy storage release unwinds.
// R6GameService.dll @ 10065bc8 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationBinaryAfterSuccess(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the serialization binary base vtable if size-probe storage release unwinds.
// R6GameService.dll @ 10065bd0 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetSerializationBinaryAfterSizeProbe(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the parsing temporary base vtable if triplet initialization unwinds.
// R6GameService.dll @ 10065bf0 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetParseBinaryBase(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Passes the original source-argument address to the native empty triplet cleanup.
// R6GameService.dll @ 10065bf8 : inherited parent EBP; ECX=&[ebp+0x4], then tail transfer.
__declspec(naked) void __cdecl CleanupParseTripletContext(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the parsing temporary binary when byte copying or parsing unwinds.
// R6GameService.dll @ 10065c00 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl DestroyParseBinary(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the parsing context before unwinding its temporary binary.
// R6GameService.dll @ 10065c08 : inherited parent EBP; ECX=&[ebp-0x30], then tail transfer.
__declspec(naked) void __cdecl ResetParseSerializer(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Resets the parsing binary base vtable if normal-path storage release unwinds.
// R6GameService.dll @ 10065c10 : inherited parent EBP; ECX=&[ebp-0x28], then tail transfer.
__declspec(naked) void __cdecl ResetParseBinaryAfterRelease(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selects FuncInfo 0x1007ff14 for the shared C++ exception handler.
// R6GameService.dll @ 10065bd8 : inherited parent frame; tail-transfers to 10033906.
__declspec(naked) void __cdecl ClDataListSerializationExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListSerializationExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects FuncInfo 0x1007ff58 for the shared C++ exception handler.
// R6GameService.dll @ 10065c18 : inherited parent frame; tail-transfers to 10033906.
__declspec(naked) void __cdecl ClDataListParseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListParseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Clone frame: flags at EntryESP-0x20, child at-0x1c, owner at-0x18, raw allocation at-0x14, output at-0x10.
// Native tag dispatch table10029234: type1/string,2/binary,3/list,4/two-word scalar,5/word,6/word.
// R6GameService.dll data @ 10029234 : native storage identity retained.
const uint GClDataListCloneTagTargets[6] = {R6GameServiceAddresses::clDataListBranch10,R6GameServiceAddresses::clDataListBranch13,R6GameServiceAddresses::clDataListBranch14,R6GameServiceAddresses::clDataListBranch16,R6GameServiceAddresses::clDataListBranch17,R6GameServiceAddresses::clDataListBranch19};

// Clones supported child tags and appends the saved child, retaining stale-child reuse for unsupported tags.
// R6GameService.dll @ 10028ef0 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void * __thiscall CopyConstructClDataList(
    void *owner,const void *source,uint initializeVirtualBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListCloneExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x8],ebx
    mov    eax,DWORD PTR [esp+0x30]
    push   ebp
    mov    ebp,ecx
    push   esi
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [esp+0x1c],ebp
    je Branch8
    mov    DWORD PTR [ebp+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [ebp+0x14],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x1
    // Construct kind3 and its embedded list; overwrite the incoming flag argument with owner+0x0c.
  Branch8:
    mov    edi,0x3
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [ebp+0x8],edi
    lea    esi,[ebp+0xc]
    push   ebx
    mov    DWORD PTR [esp+0x34],0x1
    mov    DWORD PTR [esp+0x40],esi
    lea    ecx,[esi+0x4]
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    eax,DWORD PTR [esp+0x38]
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_LAB
    // Source head read precedes full-list state3; a fault here leaves the constructed sentinel outside cleanup.
    mov    DWORD PTR [esp+0x18],ebx
    mov    eax,DWORD PTR [eax+0x10]
    mov    DWORD PTR [esp+0x30],edi
    mov    ebx,DWORD PTR [eax]
    cmp    ebx,eax
    je Branch24
    // Tags outside1..6 retain the previous saved child instead of clearing it.
  Branch9:
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    eax,DWORD PTR [ecx+0x8]
    dec    eax
    cmp    eax,0x5
    ja Branch22
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GClDataListCloneTagTargets]
    // Type1: string descriptor, empty string, then append the source byte range.
  Branch10:
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    test   esi,esi
    je Branch18
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [ebx+0x8]
    or     edi,0x8
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataStrBaseOffsets
    mov    DWORD PTR [esp+0x14],edi
    push   0x0
    push   0x1
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0x5
    call   R6GameServiceAddresses::InitializeClDataFields
    lea    edi,[esi+0xc]
    mov    DWORD PTR [esp+0x30],0x6
    mov    ecx,edi
    call   R6GameServiceAddresses::InitializeEmptyByteString
    test   ebp,ebp
    mov    BYTE PTR [esp+0x30],0x7
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrPTR_FUN
    je Branch11
    lea    eax,[ebp+0xc]
    jmp Branch12
  Branch11:
    xor    eax,eax
  Branch12:
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax]
    lea    edx,[esp+0x3c]
    push   edx
    push   ecx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::AppendByteRangeWithLocalGrowthTag
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x18],esi
    jmp Branch22
    // Type2: binary descriptor and range insertion with a native local tag byte.
  Branch13:
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    test   esi,esi
    je Branch18
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [ebx+0x8]
    or     edi,0x10
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],edi
    push   0x0
    push   0x2
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0x9
    call   R6GameServiceAddresses::InitializeClDataFields
    lea    edi,[esi+0xc]
    push   0x0
    mov    ecx,edi
    mov    DWORD PTR [esp+0x34],0xa
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataBinPTR_FUN
    mov    eax,DWORD PTR [ebp+0x10]
    mov    ebp,DWORD PTR [ebp+0xc]
    lea    edx,[esp+0x13]
    mov    BYTE PTR [esp+0x30],0xb
    push   edx
    push   eax
    push   ebp
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::InsertByteRangeWithLocalTag
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x18],esi
    jmp Branch22
    // Type3: recursively copy-construct a new list.
  Branch14:
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x20],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x30],0xc
    je Branch15
    mov    ecx,DWORD PTR [ebx+0x8]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    mov    BYTE PTR [esp+0x30],0x3
    jmp Branch21
  Branch15:
    xor    eax,eax
    mov    BYTE PTR [esp+0x30],0x3
    jmp Branch21
    // Type4: copy the high word at+0x10 before the low word at+0x0c.
  Branch16:
    push   0x14
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    test   esi,esi
    je Branch18
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [ebx+0x8]
    or     edx,0x20
    mov    DWORD PTR [esi+0x4],0x10076b34
    mov    DWORD PTR [esp+0x14],edx
    push   0x0
    push   0x4
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0xe
    call   R6GameServiceAddresses::InitializeClDataFields
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataLongVTable
    mov    edx,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],edx
    mov    eax,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [esp+0x30],0xd
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x18],esi
    jmp Branch22
    // Type5: copy one full word after base initialization.
  Branch17:
    push   0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    test   esi,esi
    je Branch18
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [ebx+0x8]
    or     edx,0x40
    mov    DWORD PTR [esi+0x4],0x10076b10
    mov    DWORD PTR [esp+0x14],edx
    push   0x0
    push   0x5
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0x10
    call   R6GameServiceAddresses::InitializeClDataFields
    mov    ecx,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrRefVTable
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esp+0x30],0xf
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x18],esi
    jmp Branch22
    // Supported allocation failure clears the saved child; unsupported tags do not take this path.
  Branch18:
    xor    esi,esi
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x18],esi
    jmp Branch22
    // Type6: initialize inline without a staged allocation action; retain flag bit7.
  Branch19:
    push   0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    je Branch20
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [ebx+0x8]
    or     dl,0x80
    mov    DWORD PTR [eax+0x4],0x10076aec
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [eax+0x8],0x6
    mov    DWORD PTR [eax],R6GameServiceAddresses::clDataRefVTable
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0xc],edx
    jmp Branch21
  Branch20:
    xor    eax,eax
  Branch21:
    mov    DWORD PTR [esp+0x18],eax
  Branch22:
    mov    eax,DWORD PTR [esp+0x18]
    test   eax,eax
    je Branch23
    // Use a pushed ECX scratch word as the sentinel output slot, then pass output/position/payload slot.
    lea    eax,[esp+0x18]
    lea    esi,[ebp+0x10]
    push   eax
    push   ecx
    push   esp
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0x2c]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    // Reload the source argument/head and current next link only after child work and insertion.
  Branch23:
    mov    edx,DWORD PTR [esp+0x38]
    mov    ebx,DWORD PTR [ebx]
    cmp    ebx,DWORD PTR [edx+0x10]
    jne Branch9
  Branch24:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret    0x8
  }
}

// For flag bit0, tail-forwards saved owner+0x18 to the genuine empty allocation-base cleanup.
// R6GameService.dll @ 10065890 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListCloneVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x1
    test   eax,eax
    je Branch25
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch25:
    ret
  }
}

// Resets the saved outer owner to its clData base table during constructor unwind.
// R6GameService.dll @ 100658aa : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetClDataListCloneBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the saved outer owner list subobject at+0x0c during constructor unwind.
// R6GameService.dll @ 100658b2 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl DestroyClDataListCloneInnerList(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::DestroyClDataPointerList
  }
}

// Releases the staged string-child allocation saved at parent EBP-0x14.
// R6GameService.dll @ 100658bd : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListStringCloneAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit3, tail-forwards staged string child+0x18 to empty allocation-base cleanup.
// R6GameService.dll @ 100658c7 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListStringCloneVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x8
    test   eax,eax
    je Branch26
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch26:
    ret
  }
}

// Resets the staged string child to its clData base table.
// R6GameService.dll @ 100658e1 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetClDataListStringCloneBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Releases the first buffer word at staged child+0x0c during state7 unwind.
// R6GameService.dll @ 100658e9 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListStringCloneBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the staged binary-child allocation saved at parent EBP-0x14.
// R6GameService.dll @ 100658f4 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListBinaryCloneAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit4, tail-forwards staged binary child+0x1c to empty allocation-base cleanup.
// R6GameService.dll @ 100658fe : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListBinaryCloneVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x10
    test   eax,eax
    je Branch27
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch27:
    ret
  }
}

// Resets the staged binary child to its clData base table.
// R6GameService.dll @ 10065918 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetClDataListBinaryCloneBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards the staged binary child triplet at+0x0c to its buffer destructor.
// R6GameService.dll @ 10065920 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListBinaryCloneBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Releases the staged recursive list-child allocation saved at parent EBP-0x14.
// R6GameService.dll @ 1006592b : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListNestedCloneAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the staged type4 child allocation saved at parent EBP-0x14.
// R6GameService.dll @ 10065935 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListScalar4CloneAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit5, tail-forwards staged type4 child+0x14 to empty allocation-base cleanup.
// R6GameService.dll @ 1006593f : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListScalar4CloneVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x20
    test   eax,eax
    je Branch28
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch28:
    ret
  }
}

// Releases the staged type5 child allocation saved at parent EBP-0x14.
// R6GameService.dll @ 10065959 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListScalar5CloneAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit6, tail-forwards staged type5 child+0x10 to empty allocation-base cleanup.
// R6GameService.dll @ 10065963 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListScalar5CloneVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x40
    test   eax,eax
    je Branch29
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch29:
    ret
  }
}

// Selects the seventeen-state outer/list/child clone unwind map.
// R6GameService.dll @ 1006597d : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ClDataListCloneExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListCloneExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys clDataList, reloads delete bit zero after destruction, optionally frees storage, and returns the object.
// R6GameService.dll @ 100270a0 : native accesses, callback ordering and raw register results retained.
__declspec(naked) void * __thiscall DeleteClDataList(void *object,uint deleteFlagWord)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyClDataList
    test   BYTE PTR [esp+0x8],0x1
    je Branch30
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch30:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Native assignment tag targets: string, binary, nested list, two-word scalar, word and inline word.
// R6GameService.dll data @ 1002955c : native storage identity retained.
const uint GClDataListAssignmentTagTargets[6] = {
  R6GameServiceAddresses::clDataListBranch32,R6GameServiceAddresses::clDataListBranch35,R6GameServiceAddresses::clDataListBranch36,R6GameServiceAddresses::clDataListBranch38,R6GameServiceAddresses::clDataListBranch39,R6GameServiceAddresses::clDataListBranch41
};

// Clears the destination and clones supported tags, clearing the saved child after each source entry.
// R6GameService.dll @ 10029250 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) uint __thiscall AssignClDataList(void *destination,const void *source)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListAssignmentExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    push   ebp
    push   esi
    // Frame: flags-0x20, child-0x1c, destination-0x18, allocation-0x14, iterator-0x10, EH-0x0c/-8/-4.
    mov    esi,DWORD PTR [esp+0x34]
    xor    ebp,ebp
    cmp    esi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    // Capture source head/first before the self check and destination clear callback.
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x18],ecx
    mov    ebx,DWORD PTR [eax]
    je Branch47
    // Invoke inner-list slot+4 with destination+0x0c; empty source retains this call EAX.
    mov    edx,DWORD PTR [ecx+0xc]
    add    ecx,0xc
    call   DWORD PTR [edx+0x4]
    cmp    ebx,DWORD PTR [esi+0x10]
    je Branch47
    mov    esi,DWORD PTR [esp+0x14]
    push   edi
    // Tags1..6 construct children; unsupported tags reach insertion with saved ESI already zero.
  Branch31:
    mov    eax,DWORD PTR [ebx+0x8]
    mov    eax,DWORD PTR [eax+0x8]
    dec    eax
    cmp    eax,0x5
    ja Branch45
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GClDataListAssignmentTagTargets]
    // Type1: staged string allocation, clData/empty-string construction, then actual source-range append.
  Branch32:
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x30],ebp
    je Branch40
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [ebx+0x8]
    or     edi,0x1
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataStrBaseOffsets
    mov    DWORD PTR [esp+0x14],edi
    push   0x0
    push   0x1
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0x1
    call   R6GameServiceAddresses::InitializeClDataFields
    lea    edi,[esi+0xc]
    mov    DWORD PTR [esp+0x30],0x2
    mov    ecx,edi
    call   R6GameServiceAddresses::InitializeEmptyByteString
    test   ebp,ebp
    mov    BYTE PTR [esp+0x30],0x3
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrPTR_FUN
    je Branch33
    lea    eax,[ebp+0xc]
    jmp Branch34
  Branch33:
    xor    eax,eax
  Branch34:
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax]
    lea    edx,[esp+0x12]
    push   edx
    push   ecx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::AppendByteRangeWithLocalGrowthTag
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch44
    // Type2: staged binary allocation, clData/empty-triplet construction, then source-range insertion.
  Branch35:
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x30],0x4
    je Branch40
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebp,DWORD PTR [ebx+0x8]
    or     edi,0x2
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],edi
    push   0x0
    push   0x2
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0x5
    call   R6GameServiceAddresses::InitializeClDataFields
    lea    edi,[esi+0xc]
    push   0x0
    mov    ecx,edi
    mov    DWORD PTR [esp+0x34],0x6
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataBinPTR_FUN
    mov    eax,DWORD PTR [ebp+0x10]
    mov    ebp,DWORD PTR [ebp+0xc]
    lea    edx,[esp+0x13]
    mov    BYTE PTR [esp+0x30],0x7
    push   edx
    push   eax
    push   ebp
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::InsertByteRangeWithLocalTag
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch44
    // Type3: use the real recursive copy constructor under state8.
  Branch36:
    push   0x18
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x20],eax
    cmp    eax,ebp
    mov    DWORD PTR [esp+0x30],0x8
    je Branch37
    mov    ecx,DWORD PTR [ebx+0x8]
    push   0x1
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch43
  Branch37:
    xor    eax,eax
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch43
    // Type4: copy source+0x10 before source+0x0c under state10.
  Branch38:
    push   0x14
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x30],0x9
    je Branch40
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [ebx+0x8]
    or     edx,0x4
    mov    DWORD PTR [esi+0x4],0x10076b34
    mov    DWORD PTR [esp+0x14],edx
    push   ebp
    push   0x4
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0xa
    call   R6GameServiceAddresses::InitializeClDataFields
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataLongVTable
    mov    edx,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],edx
    mov    eax,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch44
    // Type5: copy source+0x0c after base initialization under state12.
  Branch39:
    push   0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    cmp    esi,ebp
    mov    DWORD PTR [esp+0x30],0xb
    je Branch40
    mov    edx,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [ebx+0x8]
    or     edx,0x8
    mov    DWORD PTR [esi+0x4],0x10076b10
    mov    DWORD PTR [esp+0x14],edx
    push   ebp
    push   0x5
    mov    ecx,esi
    mov    BYTE PTR [esp+0x38],0xc
    call   R6GameServiceAddresses::InitializeClDataFields
    mov    ecx,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrRefVTable
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch44
  Branch40:
    xor    esi,esi
    mov    DWORD PTR [esp+0x30],0xffffffff
    jmp Branch44
    // Type6: initialize inline, accumulating flag0x10 without a staged child cleanup state.
  Branch41:
    push   0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    cmp    eax,ebp
    je Branch42
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [ebx+0x8]
    or     edx,0x10
    mov    DWORD PTR [eax+0x4],0x10076aec
    mov    DWORD PTR [esp+0x14],edx
    mov    DWORD PTR [eax+0x8],0x6
    mov    DWORD PTR [eax],R6GameServiceAddresses::clDataRefVTable
    mov    edx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0xc],edx
    jmp Branch43
  Branch42:
    xor    eax,eax
  Branch43:
    mov    esi,eax
  Branch44:
    mov    DWORD PTR [esp+0x18],esi
  Branch45:
    xor    ebp,ebp
    cmp    esi,ebp
    je Branch46
    // Use the pushed scratch word as head-copy output, then pass output/position/payload-slot to insertion.
    mov    eax,DWORD PTR [esp+0x1c]
    lea    ecx,[esp+0x18]
    push   ecx
    push   ecx
    lea    esi,[eax+0x10]
    push   esp
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x2c]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    // Reload source argument and sentinel after callbacks; clear the saved child before the next iteration.
  Branch46:
    mov    eax,DWORD PTR [esp+0x38]
    mov    ebx,DWORD PTR [ebx]
    xor    esi,esi
    mov    ecx,DWORD PTR [eax+0x10]
    mov    DWORD PTR [esp+0x18],esi
    cmp    ebx,ecx
    jne Branch31
    pop    edi
  Branch47:
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret    0x4
  }
}

// Appends indentation and bracketed child slot+8 output using one cached child depth, then frees the scratch buffer.
// R6GameService.dll @ 10029580 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall AppendIndentedClDataList(void *list,void *output,uint depthWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListIndentExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    ebx,ecx
    // Frame: space-0x20, tag-0x19, triplet-0x18/-0x14/-0x10, FS/handler/state-0x0c/-8/-4.
    mov    esi,DWORD PTR [esp+0x38]
    lea    ecx,[esp+0x17]
    mov    DWORD PTR [esp+0x2c],0x0
    mov    BYTE PTR [esp+0x10],0x20
    lea    eax,[esi+0x1]
    push   eax
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ConstructByteTripletBuffer
    mov    eax,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x10]
    push   edx
    push   esi
    push   eax
    mov    BYTE PTR [esp+0x38],0x1
    call   R6GameServiceAddresses::FillByteRangeAndReturnEnd
    // Stage filled end and NUL before capturing first; the depth low byte then replaces the space scratch.
    mov    DWORD PTR [esp+0x1c],eax
    mov    BYTE PTR [eax],0x0
    mov    ecx,DWORD PTR [ebx+0x10]
    mov    dl,BYTE PTR [esp+0x38]
    mov    ebp,DWORD PTR [esp+0x34]
    lea    eax,[esp+0x10]
    mov    esi,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x10],dl
    mov    edx,DWORD PTR [esp+0x18]
    push   eax
    push   ecx
    push   edx
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x38],0x3
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
    // Replace only the original output argument low byte before appending the opening literal.
    mov    al,BYTE PTR [esp+0x38]
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x34],al
    push   ecx
    mov    edi,R6GameServiceAddresses::TextOpenBracketLine
    or     ecx,0xffffffff
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextOpenBracketLine
    push   ecx
    push   R6GameServiceAddresses::TextOpenBracketLine
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    cmp    esi,DWORD PTR [ebx+0x10]
    je Branch49
    // Cache depth+2 once after heading append, retaining it across every payload callback.
    mov    edx,DWORD PTR [esp+0x38]
    lea    edi,[edx+0x2]
  Branch48:
    mov    ecx,DWORD PTR [esi+0x8]
    push   edi
    push   ebp
    mov    eax,DWORD PTR [ecx]
    call   DWORD PTR [eax+0x8]
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [ebx+0x10]
    cmp    esi,eax
    jne Branch48
    // Append the original indentation range again, passing the original depth argument address as unused tag.
  Branch49:
    mov    cl,BYTE PTR [esp+0x38]
    mov    eax,DWORD PTR [esp+0x1c]
    lea    edx,[esp+0x38]
    mov    BYTE PTR [esp+0x38],cl
    mov    ecx,DWORD PTR [esp+0x18]
    push   edx
    push   eax
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
    lea    eax,[esp+0x34]
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    push   eax
    or     ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x3c]
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x38],dl
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push   ecx
    push   R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    // Keep state3 active through normal free; return that call EAX and restore the previous FS chain.
    mov    ecx,DWORD PTR [esp+0x18]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x8
  }
}

// Appends indented non-type3 child slot+4 output, reloading depth per child, and returns final scratch-free EAX.
// R6GameService.dll @ 100296d0 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall AppendFilteredIndentedClDataList(void *list,void *output,uint depthWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListIndentExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    ebp,ecx
    mov    esi,DWORD PTR [esp+0x38]
    lea    ecx,[esp+0x17]
    mov    DWORD PTR [esp+0x2c],0x0
    mov    BYTE PTR [esp+0x10],0x20
    lea    eax,[esi+0x1]
    push   eax
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::ConstructByteTripletBuffer
    mov    eax,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x10]
    push   edx
    push   esi
    push   eax
    mov    BYTE PTR [esp+0x38],0x1
    call   R6GameServiceAddresses::FillByteRangeAndReturnEnd
    mov    DWORD PTR [esp+0x1c],eax
    mov    BYTE PTR [eax],0x0
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    dl,BYTE PTR [esp+0x38]
    mov    ebx,DWORD PTR [esp+0x34]
    lea    eax,[esp+0x10]
    mov    esi,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x10],dl
    mov    edx,DWORD PTR [esp+0x18]
    push   eax
    push   ecx
    push   edx
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x38],0x3
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
    // The filtered heading passes the output argument address through its local-tag forwarding wrapper.
    lea    eax,[esp+0x34]
    mov    edi,R6GameServiceAddresses::TextOpenBracketLine
    push   eax
    or     ecx,0xffffffff
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextOpenBracketLine
    push   ecx
    push   R6GameServiceAddresses::TextOpenBracketLine
    mov    ecx,ebx
    call   R6GameServiceAddresses::AppendByteRangeWithLocalTag
    cmp    esi,DWORD PTR [ebp+0x10]
    je Branch52
    // Skip full kind word3; reload depth+2 separately for each included child.
  Branch50:
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    DWORD PTR [ecx+0x8],0x3
    je Branch51
    mov    eax,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [ecx]
    add    eax,0x2
    push   eax
    push   ebx
    call   DWORD PTR [edx+0x4]
  Branch51:
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [ebp+0x10]
    cmp    esi,eax
    jne Branch50
    // The trailing indentation keeps its original temporary range even after child-side mutations.
  Branch52:
    mov    cl,BYTE PTR [esp+0x38]
    mov    eax,DWORD PTR [esp+0x1c]
    lea    edx,[esp+0x38]
    mov    BYTE PTR [esp+0x38],cl
    mov    ecx,DWORD PTR [esp+0x18]
    push   edx
    push   eax
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::AppendByteRangeWithGrowth
    lea    eax,[esp+0x34]
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    push   eax
    or     ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x3c]
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x38],dl
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push   ecx
    push   R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,ebx
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    // Final free is still in state3; no earlier state lowering or invented field clearing occurs.
    mov    ecx,DWORD PTR [esp+0x18]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x8
  }
}

// Prints brackets around payload slot+0x10 output, retaining final printf EAX and callback-sensitive traversal.
// R6GameService.dll @ 100298f0 : complete native accesses, callback order and raw register results retained.
__declspec(naked) uint __thiscall PrintClDataList(void *list)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    push   R6GameServiceAddresses::WideTextOpenBracket
    // Capture first before opening printf; compare it against the current sentinel after printf.
    mov    eax,DWORD PTR [edi+0x10]
    mov    esi,DWORD PTR [eax]
    call   R6GameServiceAddresses::printf
    mov    eax,DWORD PTR [edi+0x10]
    add    esp,0x4
    cmp    esi,eax
    je Branch54
  Branch53:
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,DWORD PTR [ecx]
    call   DWORD PTR [edx+0x10]
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [edi+0x10]
    cmp    esi,eax
    jne Branch53
  Branch54:
    push   R6GameServiceAddresses::WideTextCloseBracket
    call   R6GameServiceAddresses::printf
    add    esp,0x4
    pop    edi
    pop    esi
    ret
  }
}

// Adds full payload slot+0x14 results modulo 32 bits, reloading next and sentinel after each callback.
// R6GameService.dll @ 10029930 : complete native accesses, callback order and raw register results retained.
__declspec(naked) uint __thiscall SumClDataListPayloadResults(void *list)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [edi+0x10]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je Branch56
  Branch55:
    mov    ecx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [ecx]
    call   DWORD PTR [eax+0x14]
    // Keep full callback EAX for modular addition while reloading the next link.
    mov    esi,DWORD PTR [esi]
    add    ebx,eax
    cmp    esi,DWORD PTR [edi+0x10]
    jne Branch55
  Branch56:
    pop    edi
    mov    eax,ebx
    pop    esi
    pop    ebx
    ret
  }
}

// Counts nodes against the initially cached sentinel, returning that sentinel in ECX and EDX.
// R6GameService.dll @ 10029960 : complete native accesses, callback order and raw register results retained.
__declspec(naked) uint __thiscall CountClDataListEntries(void *list)
{
  __asm {
    // Only this method caches the sentinel for the whole traversal.
    mov    edx,DWORD PTR [ecx+0x10]
    xor    eax,eax
    mov    ecx,DWORD PTR [edx]
    cmp    ecx,edx
    je Branch58
  Branch57:
    mov    ecx,DWORD PTR [ecx]
    inc    eax
    cmp    ecx,edx
    jne Branch57
  Branch58:
    ret
  }
}

// Appends bracket delimiters and payload slot+0x0c output, growing only at the native equality capacity gate.
// R6GameService.dll @ 10029820 : complete native accesses, callback order and raw register results retained.
__declspec(naked) byte * __thiscall AppendClDataListToByteString(void *list,uint *outputTriplet)
{
  __asm {
    push   ecx
    push   ebp
    mov    ebp,ecx
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    // Capture the first node before delimiter growth or callbacks can mutate the list.
    mov    eax,DWORD PTR [ebp+0x10]
    push   edi
    mov    edx,DWORD PTR [esi+0x8]
    mov    edi,DWORD PTR [eax]
    mov    eax,DWORD PTR [esi+0x4]
    lea    ecx,[eax+0x1]
    cmp    ecx,edx
    jne Branch60
    mov    edx,DWORD PTR [esi]
    // Growth reuses the original output argument for constant1 and the saved ECX slot for old length.
    mov    DWORD PTR [esp+0x14],0x1
    sub    eax,edx
    lea    ecx,[esp+0x14]
    cmp    eax,0x1
    mov    DWORD PTR [esp+0xc],eax
    jb Branch59
    lea    ecx,[esp+0xc]
  Branch59:
    mov    edx,DWORD PTR [ecx]
    mov    ecx,esi
    add    edx,eax
    push   edx
    call   R6GameServiceAddresses::ReserveByteString
    // Write NUL first, then reload end before writing and advancing past the opening bracket.
  Branch60:
    mov    eax,DWORD PTR [esi+0x4]
    mov    BYTE PTR [eax+0x1],0x0
    mov    ecx,DWORD PTR [esi+0x4]
    mov    BYTE PTR [ecx],0x5b
    mov    ecx,DWORD PTR [esi+0x4]
    inc    ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    eax,DWORD PTR [ebp+0x10]
    cmp    edi,eax
    je Branch62
  Branch61:
    mov    ecx,DWORD PTR [edi+0x8]
    push   esi
    mov    edx,DWORD PTR [ecx]
    call   DWORD PTR [edx+0xc]
    // Reload next through the current node, then reload the owner sentinel after child output.
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [ebp+0x10]
    cmp    edi,eax
    jne Branch61
    // Closing delimiter independently checks equality end+1==capacity and may grow again.
  Branch62:
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[eax+0x1]
    cmp    ecx,edx
    jne Branch64
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x14],0x1
    sub    eax,edx
    lea    ecx,[esp+0x14]
    cmp    eax,0x1
    mov    DWORD PTR [esp+0xc],eax
    jb Branch63
    lea    ecx,[esp+0xc]
  Branch63:
    mov    edx,DWORD PTR [ecx]
    mov    ecx,esi
    add    edx,eax
    push   edx
    call   R6GameServiceAddresses::ReserveByteString
    // Write the closing delimiter after any growth; EAX returns the newly advanced end.
  Branch64:
    mov    eax,DWORD PTR [esi+0x4]
    pop    edi
    mov    BYTE PTR [eax+0x1],0x0
    mov    ecx,DWORD PTR [esi+0x4]
    mov    BYTE PTR [ecx],0x5d
    mov    eax,DWORD PTR [esi+0x4]
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    pop    esi
    pop    ebp
    pop    ecx
    ret    0x4
  }
}

// Releases the staged string-child allocation at parent EBP-0x14.
// R6GameService.dll @ 10065990 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentStringAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit0, tail-forwards staged child+0x18 to empty virtual-base cleanup.
// R6GameService.dll @ 1006599a : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupAssignmentStringVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x1
    test   eax,eax
    je Branch65
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch65:
    ret
  }
}

// Resets the staged string child to its clData base table.
// R6GameService.dll @ 100659b4 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetAssignmentStringBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards staged child+0x0c to first-word buffer release.
// R6GameService.dll @ 100659bc : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentStringBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the staged binary-child allocation at parent EBP-0x14.
// R6GameService.dll @ 100659c7 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentBinaryAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit1, tail-forwards staged child+0x1c to empty virtual-base cleanup.
// R6GameService.dll @ 100659d1 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupAssignmentBinaryVirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x2
    test   eax,eax
    je Branch66
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch66:
    ret
  }
}

// Resets the staged binary child to its clData base table.
// R6GameService.dll @ 100659eb : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetAssignmentBinaryBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards staged child+0x0c to binary triplet destruction.
// R6GameService.dll @ 100659f3 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentBinaryBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Releases the staged recursive list-child allocation at parent EBP-0x14.
// R6GameService.dll @ 100659fe : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentNestedAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the staged type4 allocation at parent EBP-0x14.
// R6GameService.dll @ 10065a08 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentScalar4Allocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit2, tail-forwards staged child+0x14 to empty virtual-base cleanup.
// R6GameService.dll @ 10065a12 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupAssignmentScalar4VirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x4
    test   eax,eax
    je Branch67
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch67:
    ret
  }
}

// Releases the staged type5 allocation at parent EBP-0x14.
// R6GameService.dll @ 10065a2c : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseAssignmentScalar5Allocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For flag bit3, tail-forwards staged child+0x10 to empty virtual-base cleanup.
// R6GameService.dll @ 10065a36 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupAssignmentScalar5VirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x8
    test   eax,eax
    je Branch68
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch68:
    ret
  }
}

// Selects the thirteen-state child-construction unwind map for list assignment.
// R6GameService.dll @ 10065a50 : native register/frame/state accesses and raw ABI retained.
__declspec(naked) void __cdecl ClDataListAssignmentExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListAssignmentExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-forwards parent EBP-0x19 to the genuine empty context cleanup shared by both indented writers.
// R6GameService.dll @ 10065a60 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListIndentContext(void)
{
  __asm {
    lea    ecx,[ebp-0x19]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-forwards parent EBP-0x18 to first-word buffer release during indentation-fill unwind.
// R6GameService.dll @ 10065a68 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListIndentFillBuffer(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Tail-forwards parent EBP-0x18 to buffer release for the shared state2/state3 cleanup action.
// R6GameService.dll @ 10065a70 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListIndentBuffer(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the four-state indentation-context/buffer cleanup map shared by both list writers.
// R6GameService.dll @ 10065a78 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ClDataListIndentExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListIndentExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Constructs a string child and appends a node even for a null child allocation, returning the new node address.
// R6GameService.dll @ 10029980 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall AppendClDataListString(void *list,const char *text)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListStringAppendExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   esi
    push   edi
    // Frame: context-0x19, destination/head-0x18, staged child-0x14, triplet-0x10, EH-0x0c/-8/-4.
    xor    edi,edi
    push   0x18
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x14],edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x10],esi
    cmp    esi,edi
    mov    DWORD PTR [esp+0x20],edi
    je Branch69
    // Inline kind1/clData setup; state2 covers zero begin/end and helper initialization of capacity.
    push   ebx
    push   ebp
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataStrBaseOffsets
    mov    DWORD PTR [esi+0x8],0x1
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    lea    ebx,[esi+0xc]
    lea    eax,[esp+0x13]
    push   edi
    push   eax
    lea    ecx,[ebx+0x8]
    mov    BYTE PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x24],ebx
    mov    DWORD PTR [ebx],edi
    mov    DWORD PTR [ebx+0x4],edi
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    // Load the source argument after helper initialization, scan to NUL, and retain its low-byte self-store.
    mov    ebp,DWORD PTR [esp+0x30]
    or     ecx,0xffffffff
    mov    edi,ebp
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    mov    dl,BYTE PTR [esp+0x30]
    lea    eax,[esp+0x30]
    not    ecx
    dec    ecx
    push   eax
    add    ecx,ebp
    mov    BYTE PTR [esp+0x2c],0x3
    push   ecx
    push   ebp
    mov    ecx,ebx
    mov    BYTE PTR [esp+0x3c],dl
    call   R6GameServiceAddresses::ConstructHeapByteStringRange
    pop    ebp
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataStrPTR_FUN
    pop    ebx
    jmp Branch70
  Branch69:
    xor    esi,esi
    // Replace the original source argument with child, lower state, and reuse saved destination as head-copy output.
  Branch70:
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0x28],esi
    lea    edx,[esp+0xc]
    mov    DWORD PTR [esp+0x20],0xffffffff
    lea    esi,[ecx+0x10]
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x28]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::AllocateListPayloadNode
    // Reload the saved head after node allocation, then load previous and publish all four links.
    mov    esi,DWORD PTR [esp+0xc]
    pop    edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [esp+0x14]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  }
}

// Releases the string-child allocation staged at parent EBP-0x14 during append unwind.
// R6GameService.dll @ 10065a90 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListStringAppendAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Resets the staged append child to its clData base vtable during unwind.
// R6GameService.dll @ 10065a9a : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetClDataListStringAppendBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards parent EBP-0x19 to genuine empty context cleanup during string-child construction.
// R6GameService.dll @ 10065aa2 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListStringAppendContext(void)
{
  __asm {
    lea    ecx,[ebp-0x19]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the buffer through the triplet pointer saved at parent EBP-0x10.
// R6GameService.dll @ 10065aaa : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListStringAppendBuffer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the four-state string-child append allocation/base/context/buffer unwind map.
// R6GameService.dll @ 10065ab2 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ClDataListStringAppendExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListStringAppendExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Constructs a binary child, calls slot+0x1c with full pointer/count words, then appends and returns its node.
// R6GameService.dll @ 10029a80 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall AppendClDataListBinary(void *list,const void *bytes,uint byteCount)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListAppendExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    push   0x1c
    mov    edi,ecx
    mov    DWORD PTR [esp+0x14],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x10],esi
    cmp    esi,ebx
    mov    DWORD PTR [esp+0x1c],ebx
    je Branch71
    // Inline kind2/base tables and empty triplet under state2; context is at EntryESP-0x11.
    mov    eax,0x2
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    mov    BYTE PTR [esp+0x1c],al
    lea    eax,[esp+0xf]
    push   ebx
    push   eax
    lea    ecx,[esi+0x14]
    mov    DWORD PTR [esi+0xc],ebx
    mov    DWORD PTR [esi+0x10],ebx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataBinPTR_FUN
    jmp Branch72
  Branch71:
    xor    esi,esi
    // Load count/source after construction; the vtable read precedes lowering state, so null child faults in state0.
  Branch72:
    mov    eax,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x24]
    mov    edx,DWORD PTR [esi]
    push   eax
    push   ecx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x24],0xffffffff
    call   DWORD PTR [edx+0x1c]
    // Overwrite original count with child and original source with the head-copy result.
    mov    DWORD PTR [esp+0x28],esi
    lea    esi,[edi+0x10]
    lea    edx,[esp+0x24]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x28]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::AllocateListPayloadNode
    // Reload original source slot as saved head after node allocation, then publish links.
    mov    esi,DWORD PTR [esp+0x24]
    pop    edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [esp+0x10]
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x8
  }
}

// Constructs a binary child, assigns source+c when source differs, then appends and returns the new node.
// R6GameService.dll @ 10029b60 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall AppendClDataListBinaryCopy(void *list,const void *sourceValue)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListAppendExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    push   edi
    push   0x1c
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0xc],esi
    test   esi,esi
    mov    DWORD PTR [esp+0x18],0x0
    je Branch73
    mov    eax,0x2
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esi+0x18],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    lea    ecx,[esi+0xc]
    mov    BYTE PTR [esp+0x18],al
    lea    eax,[esp+0xb]
    push   eax
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataBinPTR_FUN
    jmp Branch74
  Branch73:
    xor    esi,esi
    // Lower state before the identity test; null source/child equality skips assignment.
  Branch74:
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x18],0xffffffff
    cmp    eax,esi
    je Branch77
    test   eax,eax
    je Branch75
    add    eax,0xc
    jmp Branch76
  Branch75:
    xor    eax,eax
    // Pass the adjusted source triplet to assignment without adding a null-receiver/source guard.
  Branch76:
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::AssignClDataBinByteRange
    // Overwrite original source with child; reuse staged allocation slot as saved head before linking.
  Branch77:
    mov    DWORD PTR [esp+0x20],esi
    lea    ecx,[esp+0xc]
    lea    esi,[edi+0x10]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x20]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0xc]
    pop    edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Constructs an empty child list, assigns the source, then appends and returns the new owning-list node.
// R6GameService.dll @ 10029c40 : complete native frame/argument accesses and raw register results retained.
__declspec(naked) uint __thiscall AppendClDataListCopy(void *list,const void *sourceList)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataListAppendExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    push   edi
    push   0x18
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0xc],esi
    test   esi,esi
    mov    DWORD PTR [esp+0x18],0x0
    je Branch78
    // Inline kind3/clData initialization; shared state2 covers sentinel construction at child+0x10.
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esi+0x14],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esi+0x8],0x3
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    lea    ecx,[esi+0x10]
    lea    eax,[esp+0xb]
    mov    BYTE PTR [esp+0x18],0x2
    push   eax
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_LAB
    jmp Branch79
  Branch78:
    xor    esi,esi
    // Call assignment even for null child; parent state is lowered before the call and never owns rollback here.
  Branch79:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x18],0xffffffff
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::AssignClDataList
    // Replace original source with child and staged child-0x10 with the copied owner head before node allocation.
    mov    DWORD PTR [esp+0x20],esi
    lea    esi,[edi+0x10]
    lea    edx,[esp+0xc]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x20]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0xc]
    pop    edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Releases the staged allocation shared by binary and copied-list child append construction.
// R6GameService.dll @ 10065ac0 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ReleaseClDataListAppendAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Resets the staged child to clData base for the shared typed-append constructor unwind.
// R6GameService.dll @ 10065aca : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ResetClDataListAppendBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards inherited parent EBP-0x11 to empty context cleanup for all three typed append constructors.
// R6GameService.dll @ 10065ad2 : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl CleanupClDataListAppendContext(void)
{
  __asm {
    lea    ecx,[ebp-0x11]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the three-state constructor cleanup shared by binary, copied-binary and copied-list append.
// R6GameService.dll @ 10065ada : complete native frame/state/argument accesses and raw ABI retained.
__declspec(naked) void __cdecl ClDataListAppendExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataListAppendExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Appends the full payload word through a late-loaded argument slot, returning node EAX and saved-head ECX.
// R6GameService.dll @ 10029d20 : complete native frame/argument accesses and raw register results retained.
__declspec(naked) uint __thiscall AppendClDataListPointer(void *list,uint payloadWord)
{
  __asm {
    // Saved ECX at EntryESP-4 is overwritten by the sentinel output and later POPped back into ECX.
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    lea    esi,[ecx+0x10]
    lea    ecx,[esp+0x4]
    push   ecx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],eax
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0xc]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    mov    esi,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Formats one pointed-to signed 32-bit value in a 32-byte local buffer and returns the string-append node.
// R6GameService.dll @ 10029d60 : complete native frame/argument accesses and raw register results retained.
__declspec(naked) uint __thiscall AppendClDataListSignedDecimal(void *list,const void *valueAddress)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    sub    esp,0x20
    lea    edx,[esp+0x0]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [eax]
    push   ecx
    push   R6GameServiceAddresses::TextSignedDecimalFormat
    push   edx
    call   R6GameServiceAddresses::sprintf
    add    esp,0xc
    // Append the formatted local string through actual29980 and propagate its raw node EAX.
    lea    eax,[esp+0x4]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::AppendClDataListString
    pop    esi
    add    esp,0x20
    ret    0x4
  }
}

// Subtract12 from adjusted clDataList receiver, then tail-transfer to canonical deleting destructor270a0.
// Preserve caller flag/return address and delegate cleanup/return width to target; no own lifetime.
// R6GameService.dll @ 100273d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeleteClDataListFromAdjustedBase(void *receiver)
{
  __asm {
    sub ecx,0xc
    jmp R6GameServiceAddresses::DeleteClDataList
  }
}
