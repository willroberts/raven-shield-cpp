#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10083ddc : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo TransportRecordDecodeExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10083ffc : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo QueuedTransportDecodeExceptionHandlerFunctionInfo;

// Standalone decoder exception registration from parent EBP-0xc through EBP-4.
struct TransportRecordDecodeFrame {
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Decodes an owned input buffer by header class; class one removes its first payload word into decodedValueOut.
// R6GameService.dll @ 10057000 : stdcall, four stack words, RET 0x10; parse failure leaves the input allocated.
int * __stdcall DecodeTransportRecordByHeaderClass(
    byte *inputOrPendingAllocation,uint sizeOrPendingAllocation,uint *decodedValueOut,uint *contextOrTrimmedBuffer)
{
  TransportRecordDecodeFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)TransportRecordDecodeExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  byte *inputBytes = inputOrPendingAllocation;
  uint byteCount = sizeOrPendingAllocation;
  uint valid = IsEncodedHeaderSizeValid(inputBytes,byteCount,(uint)frame.previousExceptionList);
  if ((byte)valid == 0) {
    TailFreeThroughGlobalAllocator(inputBytes);
    ExceptionList = frame.previousExceptionList;
    return nullptr;
  }
  typedef uint (__thiscall *ParseRecord)(void *,void *,uint);
  typedef uint (__thiscall *DeleteRecord)(void *,uint);
  int *record = nullptr;
  byte recordClass = ReadHeaderByte3HighBits(inputBytes);
  if (recordClass == 0) {
    void *allocation = AllocateGameServiceBytes(0x18);
    inputOrPendingAllocation = (byte *)allocation;
    frame.state = 0;
    if (allocation != nullptr) {
      record = (int *)InitializeClGSMessageFields(allocation,(uint)contextOrTrimmedBuffer,1);
    }
    ParseRecord parse = *(ParseRecord *)(*(byte **)record + 0x10);
    frame.state = 0xffffffff;
    uint parsed = parse(record,inputBytes,byteCount);
    if ((byte)parsed == 0) {
      DeleteRecord destroy = *(DeleteRecord *)*(void **)record;
      destroy(record,1);
      ExceptionList = frame.previousExceptionList;
      return nullptr;
    }
  } else if (recordClass == 1) {
    void *allocation = AllocateGameServiceBytes(0x1c);
    sizeOrPendingAllocation = (uint)allocation;
    frame.state = 2;
    if (allocation != nullptr) {
      record = (int *)InitializeClGameMessageFields(allocation,(uint)contextOrTrimmedBuffer,1);
    }
    ParseRecord parse = *(ParseRecord *)(*(byte **)record + 0x10);
    frame.state = 0xffffffff;
    uint parsed = parse(record,inputBytes,byteCount);
    if ((byte)parsed == 0) {
      DeleteRecord destroy = *(DeleteRecord *)*(void **)record;
      destroy(record,1);
      ExceptionList = frame.previousExceptionList;
      return nullptr;
    }
    uint remainingBytes = (uint)record[5] - 4;
    *decodedValueOut = *(uint *)record[4];
    byte *replacement = (byte *)AllocateGameServiceBytes(remainingBytes);
    contextOrTrimmedBuffer = (uint *)replacement;
    const byte *source = (byte *)record[4] + 4;
    byte *destination = replacement;
    for (uint words = remainingBytes >> 2; words != 0; --words) {
      *(uint *)destination = *(const uint *)source;
      source += 4;
      destination += 4;
    }
    for (uint bytes = remainingBytes & 3; bytes != 0; --bytes) *destination++ = *source++;
    TailFreeThroughGlobalAllocator((void *)record[4]);
    record[5] = remainingBytes;
    record[4] = (int)contextOrTrimmedBuffer;
  } else if (recordClass == 2) {
    void *allocation = AllocateGameServiceBytes(0x18);
    inputOrPendingAllocation = (byte *)allocation;
    frame.state = 1;
    if (allocation != nullptr) {
      record = (int *)InitializeClGSEncryptMessageFields(allocation,(uint)contextOrTrimmedBuffer,1);
    }
    ParseRecord parse = *(ParseRecord *)(*(byte **)record + 0x10);
    frame.state = 0xffffffff;
    uint parsed = parse(record,inputBytes,byteCount);
    if ((byte)parsed == 0) {
      DeleteRecord destroy = *(DeleteRecord *)*(void **)record;
      destroy(record,1);
      ExceptionList = frame.previousExceptionList;
      return nullptr;
    }
  } else {
    typedef void (__cdecl *UnusedDiagnostic)(const char *);
    ((UnusedDiagnostic)list_node_support_NoOp)((char *)R6GameServiceAddresses::TextWrongUDPMessageProperty);
  }
  TailFreeThroughGlobalAllocator(inputBytes);
  ExceptionList = frame.previousExceptionList;
  return record;
}

// Queued-decoder local/EH region from parent EBP-0x24 through EBP-4.
struct QueuedTransportDecodeFrame {
  uint prefixByteCount;
  uint classWord;
  void *savedProvider;
  void *pendingRecordAllocation;
  byte headerPrefix[7];
  byte padding;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Consumes complete queued packets, parses class-selected records and inserts them into provider+0x3c.
// R6GameService.dll @ 10057c70 : ECX provider, no stack arguments; AL status with native upper EAX retained.
uint __fastcall DecodeQueuedTransportRecords(int providerAddress)
{
  QueuedTransportDecodeFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)QueuedTransportDecodeExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedProvider = (void *)providerAddress;
  frame.prefixByteCount = 0;
  uint availableOrPrefixBytes = 0;
  typedef uint (__thiscall *PeekQueueStatus)(void *,uint,int);
  PeekQueueStatus peekQueue = (PeekQueueStatus)CopyBlockQueuePrefix;
  typedef uint (__thiscall *ParseRecord)(void *,void *,uint);
  typedef uint (__thiscall *DeleteRecord)(void *,uint);
  typedef void (__cdecl *UnusedDiagnostic)(const char *);
  UnusedDiagnostic diagnostic = (UnusedDiagnostic)list_node_support_NoOp;
  for (;;) {
    uint connection = *(uint *)(providerAddress + 0x14);
    if (connection != 0) {
      availableOrPrefixBytes = *(uint *)(connection + 0x14);
      frame.prefixByteCount = availableOrPrefixBytes;
    }
    if (availableOrPrefixBytes < 6) {
      ExceptionList = frame.previousExceptionList;
      return (connection & 0xffffff00) | 1;
    }
    if (availableOrPrefixBytes > 7) {
      availableOrPrefixBytes = 7;
      frame.prefixByteCount = 7;
    }
    if (connection != 0) {
      uint copied = peekQueue((void *)(connection + 8),availableOrPrefixBytes,(int)frame.headerPrefix);
      if ((byte)copied == 0) {
        ExceptionList = frame.previousExceptionList;
        return (copied & 0xffffff00) | 1;
      }
    }
    uint packetByteCount = ReadHeaderSize24(frame.headerPrefix);
    uint valid = IsEncodedHeaderSizeValid(frame.headerPrefix,availableOrPrefixBytes,(uint)frame.headerPrefix);
    if ((byte)valid == 0) {
      diagnostic((char *)R6GameServiceAddresses::TextTheMessageFormatIsNotCorrect);
      ExceptionList = frame.previousExceptionList;
      return valid & 0xffffff00;
    }
    connection = *(uint *)(providerAddress + 0x14);
    if (connection != 0 && *(int *)(connection + 0x14) < (int)packetByteCount) {
      ExceptionList = frame.previousExceptionList;
      return (connection & 0xffffff00) | 1;
    }
    void *packet = AllocateGameServiceBytes(packetByteCount);
    connection = *(uint *)(providerAddress + 0x14);
    if (connection != 0) {
      uint consumed = ConsumeBlockQueueBytes((void *)(connection + 8),packetByteCount,(int)packet);
      if ((byte)consumed == 0) {
        diagnostic((char *)R6GameServiceAddresses::TextErrorCouldNotReadTheFifo);
        uint result = TailFreeThroughGlobalAllocator(packet);
        ExceptionList = frame.previousExceptionList;
        return result & 0xffffff00;
      }
    }
    *(byte *)&frame.classWord = ReadHeaderByte3HighBits((byte *)packet);
    byte recordClass = (byte)frame.classWord;
    int *record = nullptr;
    if (recordClass == 0) {
      frame.pendingRecordAllocation = AllocateGameServiceBytes(0x18);
      frame.state = 0;
      if (frame.pendingRecordAllocation != nullptr) {
        record = (int *)InitializeClGSMessageFields(
            frame.pendingRecordAllocation,*(uint *)(providerAddress + 0x4c),1);
      }
    } else if (recordClass == 1) {
      frame.pendingRecordAllocation = AllocateGameServiceBytes(0x1c);
      frame.state = 1;
      if (frame.pendingRecordAllocation != nullptr) {
        record = (int *)InitializeClGameMessageFields(
            frame.pendingRecordAllocation,*(uint *)(providerAddress + 0x4c),1);
      }
    } else if (recordClass == 2) {
      frame.pendingRecordAllocation = AllocateGameServiceBytes(0x18);
      frame.state = 2;
      if (frame.pendingRecordAllocation != nullptr) {
        record = (int *)InitializeClGSEncryptMessageFields(
            frame.pendingRecordAllocation,*(uint *)(providerAddress + 0x4c),1);
      }
    } else {
      uint result = TailFreeThroughGlobalAllocator(packet);
      ExceptionList = frame.previousExceptionList;
      return result & 0xffffff00;
    }
    ParseRecord parse = *(ParseRecord *)(*(byte **)record + 0x10);
    frame.state = 0xffffffff;
    uint parsed = parse(record,packet,packetByteCount);
    if ((byte)parsed == 0) {
      diagnostic((char *)R6GameServiceAddresses::TextErrorDecodingMessage);
      TailFreeThroughGlobalAllocator(packet);
      DeleteRecord destroy = *(DeleteRecord *)*(void **)record;
      uint result = destroy(record,1);
      ExceptionList = frame.previousExceptionList;
      return result & 0xffffff00;
    }
    if (recordClass == 2) diagnostic((char *)R6GameServiceAddresses::TextReadEncryptedMessage);
    providerAddress = (int)frame.savedProvider;
    InsertOrReplaceCompactRecord((void *)(providerAddress + 0x3c),0,(undefined1 *)record);
    TailFreeThroughGlobalAllocator(packet);
    availableOrPrefixBytes = frame.prefixByteCount;
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 100692d0 : [ebp+0x4]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeStandaloneEncryptedRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 100692da : [ebp+0x8]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeStandaloneGameRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 100692e4 : [ebp+0x4]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeStandaloneGSRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 10069530 : [ebp-0x18]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeQueuedEncryptedRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 1006953a : [ebp-0x18]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeQueuedGameRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the pending class-selected record allocation from the inherited parent frame.
// R6GameService.dll @ 10069544 : [ebp-0x18]; CALL10014d00 then RET.
__declspec(naked) void __cdecl FreeQueuedGSRecordOnUnwind(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the decoder's three-state allocation FuncInfo for the shared C++ frame handler.
// R6GameService.dll @ 100692ee : EAX=10083ddc; inherited-frame exception ABI.
__declspec(naked) void __cdecl TransportRecordDecodeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::TransportRecordDecodeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the decoder's three-state allocation FuncInfo for the shared C++ frame handler.
// R6GameService.dll @ 1006954e : EAX=10083ffc; inherited-frame exception ABI.
__declspec(naked) void __cdecl QueuedTransportDecodeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueuedTransportDecodeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
