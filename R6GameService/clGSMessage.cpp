#include "native_addresses.h"
#include "native_records.h"

int __stdcall FormatWordAsDecimal(uint codeWord,char *output);
uint __stdcall FormatByteLabel(uint codeWord,char *output);

// Inferred serializer locals: sizeS-3c, flags/copyS-38, serializerS-34 and binaryS-2c.
struct GSMessageSerializeLocals {
  uint transformedBytes;
  uint flagsOrCopy;
  uint serializer[2];
  uint binary[7];
  uint binaryBaseContext;
};

// Owns descriptor construction only; header, copied bytes and transformed bytes have no exception cleanup.
struct GSMessageSerializeCleanup {
  GSMessageSerializeLocals *frame;
  int state;
  bool armed;
  // Follow the active descriptor state without retrying an entered normal buffer release.
  ~GSMessageSerializeCleanup() noexcept(false)
  {
    if (!armed) return;
    using ContextABI = void (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
        case 0:
          state = -1;
          if ((frame->flagsOrCopy & 1) != 0)
            ((ContextABI)R6GameServiceAddresses::list_node_support_NoOp)(&frame->binaryBaseContext);
          break;
        case 1:
          state = 0;
          ResetClDataVtable(frame->binary);
          break;
        case 2:
          state = -1;
          DestroyClDataBinAlias(frame->binary);
          break;
        case 3:
          state = 2;
          ResetClDataSerializeVtableAlias(frame->serializer);
          break;
        case 4: case 5:
          state = -1;
          ResetClDataVtable(frame->binary);
          break;
      }
    }
  }
};

// Serialize payload to temporary binary descriptor; build cleared six-byte header and optionally transform payload
// through current slot14 twice.
// Cache original serialized length before allocation, reload current descriptor range for copy, retain current
// transform size after output.
// Size scratch remains uninitialized until written by the codec. Header helper argument high bits are unused.
// Reuse output argument for the result; free header/output/current copy, then release the descriptor.
// Only descriptors have exception cleanup. RET4.
// R6GameService.dll @ 10059b00 : complete native control/access order and raw ABI retained.
void * __thiscall SerializePayloadRecord(void *message,uint *outputSize)
{
  GSMessageSerializeLocals frame;
  GSMessageSerializeCleanup cleanup{&frame,-1,true};
  frame.flagsOrCopy = 0;
  void *savedMessage = message;
  frame.binary[1] = R6GameServiceAddresses::ClDataBinOwnerBaseOffsets;
  frame.binary[6] = R6GameServiceAddresses::ClDataBinBaseOffsets;
  frame.flagsOrCopy = 1;
  frame.binary[0] = R6GameServiceAddresses::PTR_LAB;
  frame.binary[2] = 2;
  cleanup.state = 1;
  InitializeEmptyByteBufferTriplet(frame.binary + 3,0);
  frame.binary[0] = R6GameServiceAddresses::clDataBinPTR_FUN;
  cleanup.state = 2;
  ConstructClDataSerialize(frame.serializer,1);
  uint payload = *(uint *)((byte *)savedMessage + 0x14);
  cleanup.state = 3;
  WriteTaggedEntries(frame.serializer,(int)payload,(undefined1 *)frame.binary);
  uint serializedEnd = frame.binary[4];
  uint serializedBegin = frame.binary[3];
  uint serializedBytes = serializedEnd - serializedBegin;
  byte *header = (byte *)AllocateGameServiceBytes(6);
  *(uint *)header = 0;
  *(ushort *)(header + 4) = 0;
  if (serializedBytes == 0) {
    WriteHeaderSize24(header,6);
    WriteHeaderByte3HighBits(header,*((byte *)savedMessage + 0xc));
    SetHeaderByte3Bit5(header,*((byte *)savedMessage + 0xe));
    WriteHeaderByte4(header,*((byte *)savedMessage + 0xd));
    WriteHeaderByte5HighNibble(header,*((byte *)savedMessage + 0x10));
    WriteHeaderByte5LowNibble(header,*((byte *)savedMessage + 0x11));
    uint *sizeCell = outputSize;
    cleanup.state = 2;
    *sizeCell = 6;
    ResetClDataSerializeVtable(frame.serializer);
    frame.binary[0] = R6GameServiceAddresses::clDataBinPTR_FUN;
    cleanup.state = 4;
    ReleaseNonNullFirstWordBuffer(frame.binary + 3);
    cleanup.armed = false;
    return header;
  }
  byte *copy = (byte *)AllocateGameServiceBytes(serializedBytes);
  uint currentBegin = frame.binary[3];
  uint currentEnd = frame.binary[4];
  frame.flagsOrCopy = (uint)copy;
  if (currentEnd != currentBegin) memmove(copy,(void *)currentBegin,currentEnd - currentBegin);
  using CodecABI = uint (__thiscall *)(void *,const byte *,uint,byte *,uint *);
  uint table = *(uint *)savedMessage;
  (*(CodecABI *)(table + 0x14))(savedMessage,copy,serializedBytes,nullptr,&frame.transformedBytes);
  byte *transformed = (byte *)AllocateGameServiceBytes(frame.transformedBytes);
  byte *currentCopy = (byte *)frame.flagsOrCopy;
  table = *(uint *)savedMessage;
  (*(CodecABI *)(table + 0x14))(savedMessage,currentCopy,serializedBytes,transformed,&frame.transformedBytes);
  uint reportedBytes = frame.transformedBytes;
  uint *sizeCell = outputSize;
  uint totalBytes = reportedBytes + 6;
  *sizeCell = totalBytes;
  WriteHeaderSize24(header,totalBytes);
  WriteHeaderByte3HighBits(header,*((byte *)savedMessage + 0xc));
  SetHeaderByte3Bit5(header,*((byte *)savedMessage + 0xe));
  WriteHeaderByte4(header,*((byte *)savedMessage + 0xd));
  WriteHeaderByte5HighNibble(header,*((byte *)savedMessage + 0x10));
  WriteHeaderByte5LowNibble(header,*((byte *)savedMessage + 0x11));
  byte *packet = (byte *)AllocateGameServiceBytes(*sizeCell);
  byte *out = packet + 6;
  outputSize = (uint *)packet;
  uint firstWord = *(uint *)header;
  *(uint *)packet = firstWord;
  ushort lastWord = *(ushort *)(header + 4);
  *(ushort *)(packet + 4) = lastWord;
  const byte *first = transformed;
  uint copyBytes = frame.transformedBytes;
  uint words = copyBytes >> 2;
  while (words != 0) {
    uint word = *(const uint *)first;
    *(uint *)out = word;
    first += 4;
    out += 4;
    --words;
  }
  uint tailBytes = copyBytes & 3;
  while (tailBytes != 0) {
    byte value = *first;
    *out = value;
    ++first;
    ++out;
    --tailBytes;
  }
  TailFreeThroughGlobalAllocator(header);
  TailFreeThroughGlobalAllocator(transformed);
  void *releaseCopy = (void *)frame.flagsOrCopy;
  TailFreeThroughGlobalAllocator(releaseCopy);
  cleanup.state = 2;
  ResetClDataSerializeVtable(frame.serializer);
  frame.binary[0] = R6GameServiceAddresses::clDataBinPTR_FUN;
  cleanup.state = 5;
  ReleaseNonNullFirstWordBuffer(frame.binary + 3);
  cleanup.armed = false;
  return outputSize;
}

// If inherited flagS-38 bit0 is set, tail empty-base cleanup with addressS-10.
// R6GameService.dll @ 100698b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x38]
    and    eax,0x1
    test    eax,eax
    je    Branch4
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Tail base-vtable reset for inherited binary descriptorS-2c.
// R6GameService.dll @ 100698c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail binary descriptor destruction atS-2c; its current buffer is freed without clearing the member.
// R6GameService.dll @ 100698cf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tail serializer vtable reset for inherited serializerS-34.
// R6GameService.dll @ 100698d7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x34]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Tail base-vtable reset after the entered empty-path buffer release; do not retry that release.
// R6GameService.dll @ 100698df : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail base-vtable reset after the entered transformed-path buffer release; do not retry that release.
// R6GameService.dll @ 100698e7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select six-state descriptor cleanup FuncInfo and tail shared C++ frame dispatch.
// R6GameService.dll @ 100698ef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMessageSerializerEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SerializePayloadRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal descriptor-only cleanup map/FuncInfo for the packet serializer.
// R6GameService.dll data @ 10084398 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SerializePayloadRecordUnwindMap[6] = {
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind1},
  {0x0, R6GameServiceAddresses::SerializePayloadRecordUnwind2},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind3},
  {0x2, R6GameServiceAddresses::SerializePayloadRecordUnwind4},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind5},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind6},
};

// Literal descriptor-only cleanup map/FuncInfo for the packet serializer.
// R6GameService.dll data @ 100843c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo SerializePayloadRecordExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::SerializePayloadRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Read current message8 helper and forward four full words plus literal selector1 to shared slot0c dispatch; raw
// EAX/RET16.
// R6GameService.dll @ 10059d40 : complete native control/access order and raw ABI retained.
uint __thiscall EncodeMessagePayload(void *message,uint word0,uint word1,uint word2,uint word3)
{
  uint last = word3;
  uint third = word2;
  void *helper = *(void **)((byte *)message + 8);
  uint second = word1;
  uint first = word0;
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchThroughSelectedSlot0C)(helper,first,second,third,last,1);
}

// Read current message8 helper and forward four full words plus literal selector1 to shared slot10 dispatch; raw
// EAX/RET16.
// R6GameService.dll @ 10059d70 : complete native control/access order and raw ABI retained.
uint __thiscall DecodeMessagePayload(void *message,uint word0,uint word1,uint word2,uint word3)
{
  uint last = word3;
  uint third = word2;
  void *helper = *(void **)((byte *)message + 8);
  uint second = word1;
  uint first = word0;
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchThroughSelectedSlot10)(helper,first,second,third,last,1);
}

// Inferred decoder locals: sizeS-5c, flagsS-58, pendingS-54, serializerS-50, listS-48 and binaryS-2c.
struct GSMessageDecodeLocals {
  uint decodedBytes;
  uint flags;
  uint pendingList;
  uint serializer[2];
  uint temporaryList[6];
  uint listBaseContext;
  uint binary[7];
  uint binaryBaseContext;
};

// Owns temporary descriptors and only the heap list still under construction; decoded raw bytes are not guarded.
struct GSMessageDecodeCleanup {
  GSMessageDecodeLocals *frame;
  int state;
  // Release the current constructor stage before unwinding earlier descriptors, preserving published payloads.
  ~GSMessageDecodeCleanup() noexcept(false)
  {
    using ContextABI = void (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
        case 0:
          state = -1;
          if ((frame->flags & 1) != 0)
            ((ContextABI)R6GameServiceAddresses::list_node_support_NoOp)(&frame->binaryBaseContext);
          break;
        case 1:
          state = 0;
          ResetClDataVtable(frame->binary);
          break;
        case 2:
          state = -1;
          DestroyClDataBinAlias(frame->binary);
          break;
        case 3:
          state = 2;
          ResetClDataSerializeVtableAlias(frame->serializer);
          break;
        case 4:
          state = 3;
          if ((frame->flags & 2) != 0)
            ((ContextABI)R6GameServiceAddresses::list_node_support_NoOp)(&frame->listBaseContext);
          break;
        case 5:
          state = 4;
          ResetClDataVtable(frame->temporaryList);
          break;
        case 6:
          state = 3;
          DestroyClDataListAlias(frame->temporaryList);
          break;
        case 7:
          state = 6;
          ForwardToAllocatorTail((void *)frame->pendingList);
          break;
        case 8:
          state = 7;
          if ((frame->flags & 4) != 0)
            ((ContextABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)(frame->pendingList + 0x18));
          break;
        case 9:
          state = 8;
          ResetClDataVtable((undefined4 *)frame->pendingList);
          break;
      }
    }
  }
};

// Construct/publish a fresh payload list before unsigned length>=6 and exact encoded-size comparison; retain replaced
// old payload.
// Decode current slot18 twice, ignore status, zero query-sized allocation then use current reported size for
// replacement/parse.
// Reuse original size argument for payload pointer; clean temporary list/serializer/binary descriptor and set only
// final AL/RET8.
// Ten-state construction cleanup owns descriptors and pending list allocation, never the raw decoded byte buffer.
// R6GameService.dll @ 10059da0 : complete native control/access order and raw ABI retained.
uint __thiscall DecodePayloadRecord(void *message,const byte *input,uint inputSizeWord)
{
  GSMessageDecodeLocals frame;
  GSMessageDecodeCleanup cleanup{&frame,-1};
  frame.flags = 0;
  void *savedMessage = message;
  frame.binary[1] = R6GameServiceAddresses::ClDataBinOwnerBaseOffsets;
  frame.binary[6] = R6GameServiceAddresses::ClDataBinBaseOffsets;
  frame.flags = 1;
  cleanup.state = 0;
  InitializeClDataFields(frame.binary,2,0);
  cleanup.state = 1;
  InitializeEmptyByteBufferTriplet(frame.binary + 3,0);
  frame.binary[0] = R6GameServiceAddresses::clDataBinPTR_FUN;
  cleanup.state = 2;
  ConstructClDataSerialize(frame.serializer,1);
  frame.temporaryList[1] = R6GameServiceAddresses::ClDataListBaseOffsets;
  frame.temporaryList[5] = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
  frame.flags = 3;
  cleanup.state = 4;
  InitializeClDataFields(frame.temporaryList,3,0);
  cleanup.state = 5;
  ConstructClDataPointerList(frame.temporaryList + 3,0);
  frame.temporaryList[0] = R6GameServiceAddresses::clDataListPTR_FUN;
  frame.temporaryList[3] = R6GameServiceAddresses::clDataListPTR_LAB;
  uint heapList = (uint)AllocateGameServiceBytes(0x18);
  frame.pendingList = heapList;
  if (heapList != 0) {
    *(uint *)(heapList + 4) = R6GameServiceAddresses::ClDataListBaseOffsets;
    *(uint *)(heapList + 0x14) = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
    frame.flags = 7;
    cleanup.state = 8;
    InitializeClDataFields((void *)heapList,3,0);
    uint inner = heapList + 0xc;
    cleanup.state = 9;
    ConstructClDataPointerList((void *)inner,0);
    *(uint *)heapList = R6GameServiceAddresses::clDataListPTR_FUN;
    *(uint *)inner = R6GameServiceAddresses::clDataListPTR_LAB;
  }
  uint encodedBytes = inputSizeWord;
  cleanup.state = 6;
  *(uint *)((byte *)savedMessage + 0x14) = heapList;
  bool success = false;
  bool parsedPayload = false;
  if (encodedBytes >= 6) {
    const byte *packet = input;
    if (ReadHeaderSize24(packet) == encodedBytes) {
      *((byte *)savedMessage + 0xe) = (byte)ReadHeaderByte3LowBits(packet);
      *((byte *)savedMessage + 0xd) = (byte)ReadHeaderByte4(packet);
      *((byte *)savedMessage + 0x10) = (byte)ReadHeaderByte5HighNibble(packet);
      *((byte *)savedMessage + 0x11) = (byte)ReadHeaderByte5LowNibble(packet);
      uint payloadBytes = encodedBytes - 6;
      if (payloadBytes == 0) {
        success = true;
      } else {
        uint table = *(uint *)savedMessage;
        const byte *payloadInput = packet + 6;
        inputSizeWord = (uint)payloadInput;
        using CodecABI = uint (__thiscall *)(void *,const byte *,uint,byte *,uint *);
        (*(CodecABI *)(table + 0x18))(savedMessage,payloadInput,payloadBytes,nullptr,&frame.decodedBytes);
        byte *decoded = (byte *)AllocateGameServiceBytes(frame.decodedBytes);
        uint zeroBytes = frame.decodedBytes;
        byte *zeroAt = decoded;
        uint words = zeroBytes >> 2;
        while (words != 0) {
          *(uint *)zeroAt = 0;
          zeroAt += 4;
          --words;
        }
        uint tailBytes = zeroBytes & 3;
        const byte *currentInput = (const byte *)inputSizeWord;
        while (tailBytes != 0) {
          *zeroAt = 0;
          ++zeroAt;
          --tailBytes;
        }
        table = *(uint *)savedMessage;
        (*(CodecABI *)(table + 0x18))(savedMessage,currentInput,payloadBytes,decoded,&frame.decodedBytes);
        uint decodedBytes = frame.decodedBytes;
        ReplaceClDataBinBytes(frame.binary,decoded,decodedBytes);
        uint currentPayload = *(uint *)((byte *)savedMessage + 0x14);
        uint parsed = ParseTaggedValues(frame.serializer,frame.binary,(undefined1 *)currentPayload);
        success = (byte)parsed != 0;
        parsedPayload = true;
        TailFreeThroughGlobalAllocator(decoded);
      }
    }
  }
  cleanup.state = 3;
  DestroyClDataList(frame.temporaryList);
  cleanup.state = 2;
  uint result;
  if (success && parsedPayload) {
    ResetClDataSerializeVtableAlias(frame.serializer);
    cleanup.state = -1;
    result = DestroyClDataBinAlias(frame.binary);
  } else {
    ResetClDataSerializeVtable(frame.serializer);
    cleanup.state = -1;
    result = DestroyClDataBin(frame.binary);
  }
  return (result & 0xffffff00u) | (success ? 1u : 0u);
}

// Test inheritedS-58 bit0, tail empty-base cleanup with addressS-10 if constructed.
// R6GameService.dll @ 10069900 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x1
    test    eax,eax
    je    Branch12
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch12:
    ret
  }
}

// Tail base-vtable reset for inherited binary descriptorS-2c.
// R6GameService.dll @ 10069917 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail destruction of inherited binary descriptorS-2c, using its current buffer.
// R6GameService.dll @ 1006991f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tail serializer vtable reset at inheritedS-50 before binary destruction.
// R6GameService.dll @ 10069927 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x50]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Test inheritedS-58 bit1, tail empty-base cleanup with addressS-30 if constructed.
// R6GameService.dll @ 1006992f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x2
    test    eax,eax
    je    Branch13
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch13:
    ret
  }
}

// Tail base-vtable reset for inherited temporary listS-48.
// R6GameService.dll @ 10069946 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail temporary list destruction at inheritedS-48 before serializer/binary cleanup.
// R6GameService.dll @ 1006994e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Free CURRENT pending heap-list pointerS-54; no decoded-byte buffer cleanup is present.
// R6GameService.dll @ 10069956 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x54]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Test inheritedS-58 bit2, tail empty-base cleanup at CURRENT pending list pointerS-54 plus18.
// R6GameService.dll @ 10069960 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x4
    test    eax,eax
    je    Branch14
    mov    ecx,DWORD PTR [ebp-0x54]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch14:
    ret
  }
}

// Reset base vtable through CURRENT pending list pointerS-54 before pending allocation release.
// R6GameService.dll @ 1006997a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact ten-state decoder construction FuncInfo and tail shared C++ frame dispatch.
// R6GameService.dll @ 10069982 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMessageDecoderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DecodePayloadRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native decoder construction cleanup map/FuncInfo.
// R6GameService.dll data @ 100843e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DecodePayloadRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::DecodePayloadRecordUnwind1},
  {0x0, R6GameServiceAddresses::DecodePayloadRecordUnwind2},
  {-1, R6GameServiceAddresses::DecodePayloadRecordUnwind3},
  {0x2, R6GameServiceAddresses::DecodePayloadRecordUnwind4},
  {0x3, R6GameServiceAddresses::DecodePayloadRecordUnwind5},
  {0x4, R6GameServiceAddresses::DecodePayloadRecordUnwind6},
  {0x3, R6GameServiceAddresses::DecodePayloadRecordUnwind7},
  {0x6, R6GameServiceAddresses::DecodePayloadRecordUnwind8},
  {0x7, R6GameServiceAddresses::DecodePayloadRecordUnwind9},
  {0x8, R6GameServiceAddresses::DecodePayloadRecordUnwind10},
};

// Literal native decoder construction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084434 : native storage identity retained.
const R6GameServiceNative::FuncInfo DecodePayloadRecordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::DecodePayloadRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

namespace {
// Inferred constructor guard: only the clone branch owns a pending allocation before publication.
struct GSMessageConstructionCleanup {
  byte *message;
  uint virtualBaseConstructed;
  uint *pendingAllocation;
  int state;
  // Free the current pending clone allocation, restore base identity and finish the optional empty virtual base.
  ~GSMessageConstructionCleanup() noexcept(false) {
    using ResetABI = void (__fastcall *)(void *);
    using FreeABI = void (__stdcall *)(void *);
    if (state == 2) {
      state = 1;
      ((FreeABI)R6GameServiceAddresses::ForwardToAllocatorTail)((void *)*pendingAllocation);
    }
    if (state == 1) {
      state = 0;
      ((ResetABI)R6GameServiceAddresses::ResetClMessageVtable)(message);
    }
    if (state == 0) {
      state = -1;
      if ((virtualBaseConstructed & 1) != 0) {
        ((ResetABI)R6GameServiceAddresses::list_node_support_NoOp)((void *)((uint)message + 0x18));
      }
    }
  }
};
}

// Set metadata, then clone a source list or construct an empty list with native staged allocation ownership.
// R6GameService.dll @ 10059940 : clone allocation reuses the code argument; empty-list failures retain pending storage.
void * __thiscall ConstructClGSMessage(
    void *message,uint contextWord,uint codeOrPendingWord,uint byte0eWord,uint byte10Word,uint byte11Word,
    uint sourceWord,uint initializeBaseWord)
{
  uint initializeBase = initializeBaseWord;
  GSMessageConstructionCleanup cleanup{(byte *)message, 0, &codeOrPendingWord, -1};
  if (initializeBase != 0) {
    *(uint *)((byte *)message + 4) = 0x100781b8;
    cleanup.virtualBaseConstructed = 1;
  }
  uint context = contextWord;
  *(uint *)((byte *)message + 8) = context;
  byte code = (byte)codeOrPendingWord;
  byte field0e = (byte)byte0eWord;
  byte field10 = (byte)byte10Word;
  uint source = sourceWord;
  *((byte *)message + 0xd) = code;
  byte field11 = (byte)byte11Word;
  cleanup.state = 1;
  *(uint *)message = R6GameServiceAddresses::clGSMessageVTable;
  *((byte *)message + 0xc) = 0;
  *((byte *)message + 0xe) = field0e;
  *((byte *)message + 0x10) = field10;
  *((byte *)message + 0x11) = field11;
  uint allocation = (uint)AllocateGameServiceBytes(0x18);
  if (source != 0) {
    codeOrPendingWord = allocation;
    *(byte *)&cleanup.state = 2;
    void *constructed = nullptr;
    if (allocation != 0) {
      using CloneABI = void * (__thiscall *)(void *,void *,uint);
      constructed = ((CloneABI)R6GameServiceAddresses::CopyConstructClDataList)((void *)allocation,(void *)source,1);
    }
    *(void **)((byte *)message + 0x14) = constructed;
  } else {
    uint list = allocation;
    if (list != 0) {
      *(uint *)(list + 4) = R6GameServiceAddresses::ClDataListBaseOffsets;
      *(uint *)(list + 0x14) = R6GameServiceAddresses::ClDataListInnerBaseOffsets;
      *(uint *)(list + 8) = 3;
      *(uint *)list = R6GameServiceAddresses::PTR_LAB;
      *(uint *)(list + 0x10) = 0;
      uint head = (uint)AllocateGameServiceBytes(0xc);
      *(uint *)head = head;
      *(uint *)(head + 4) = head;
      *(uint *)(list + 0x10) = head;
      *(uint *)(list + 0xc) = R6GameServiceAddresses::clDataListPTR_FUN2;
      *(uint *)list = R6GameServiceAddresses::clDataListPTR_FUN;
      *(uint *)(list + 0xc) = R6GameServiceAddresses::clDataListPTR_LAB;
    }
    *(uint *)((byte *)message + 0x14) = list;
  }
  cleanup.state = -1;
  return message;
}

// Destroy owned members, then inspect the current deletion flag and optionally free the cached message allocation.
// R6GameService.dll @ 10059a50 : flag bit 0 controls storage release; returns the original receiver.
void * __thiscall DeleteClGSMessage(void *message,uint deleteFlags)
{
  using DestroyABI = void (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyClGSMessage)(message);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(message);
  return message;
}

// Initialize base message metadata and empty payload fields while preserving subtype bytes and padding.
// R6GameService.dll @ 10059a70 : optional base-offset table at +4; context +8 and owned payload pointer +0x14.
void * __thiscall InitializeClGSMessageFields(void *message,uint contextWord,uint initializeBaseWord)
{
  if (initializeBaseWord != 0) *(uint *)((byte *)message + 4) = 0x100781b8;
  uint context = contextWord;
  *(uint *)message = R6GameServiceAddresses::clGSMessageVTable;
  *(uint *)((byte *)message + 8) = context;
  *((byte *)message + 0xc) = 0;
  *((byte *)message + 0x10) = 0;
  *((byte *)message + 0x11) = 0;
  *(uint *)((byte *)message + 0x14) = 0;
  return message;
}

// Delete the cached payload with flags1 and restore clMessage identity without clearing the payload field.
// Inferred void ABI: both deleting callers overwrite EAX; native residue is child EAX or prior FS on NULL payload.
// Failure resets the current saved cleanup receiver; normal completion restores the original receiver.
// R6GameService.dll @ 10059ab0 : complete native control/access order and raw ABI retained.
void __fastcall DestroyClGSMessage(void *message)
{
  void *cleanupReceiver = message;
  void *savedMessage = message;
  *(uint *)savedMessage = R6GameServiceAddresses::clGSMessageVTable;
  void *payload = *(void **)((byte *)savedMessage + 0x14);
  try {
    if (payload != nullptr) {
      uint table = *(uint *)payload;
      using DeleteABI = uint (__thiscall *)(void *,uint);
      (*(DeleteABI *)table)(payload,1);
    }
  } catch (...) {
    using ResetABI = void (__fastcall *)(void *);
    ((ResetABI)R6GameServiceAddresses::ResetClMessageVtable)(cleanupReceiver);
    throw;
  }
  *(uint *)savedMessage = R6GameServiceAddresses::clMessageVTable;
}

// If inheritedS-14 bit0 is set, tail genuine empty-base cleanup at CURRENT saved receiverS-10 plus18.
// R6GameService.dll @ 10069850 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageVirtualBaseIfConstructed(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test    eax,eax
    je    Branch24
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch24:
    ret
  }
}

// Tail clMessage vtable reset through CURRENT saved constructor receiverS-10.
// R6GameService.dll @ 1006986a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBaseDuringConstruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClMessageVtable
  }
}

// Free CURRENT original code argumentS+8 reused for clone allocation; no reconstructed snapshot or argument frame.
// R6GameService.dll @ 10069872 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl FreeMessagePendingAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select literal three-state construction FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 1006987c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageConstructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructClGSMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail clMessage vtable reset through CURRENT saved destructor receiverS-10; payload deletion is not retried.
// R6GameService.dll @ 10069890 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBaseDuringDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClMessageVtable
  }
}

// Select literal one-state destruction FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 10069898 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageDestructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyClGSMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084340 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructClGSMessageUnwindMap[3] = {
  {-1, R6GameServiceAddresses::CleanupMessageVirtualBaseIfConstructed},
  {0x0, R6GameServiceAddresses::ResetMessageBaseDuringConstruction},
  {0x1, R6GameServiceAddresses::FreeMessagePendingAllocation},
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084358 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructClGSMessageExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ConstructClGSMessageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084374 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyClGSMessageUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ResetMessageBaseDuringDestruction},
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 1008437c : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyClGSMessageExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyClGSMessageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Append current label/payload text: ordinary, top-level26/27 or nestedD1 with optional quoted prefix.
// EntryS: tagsS-a3..a1, listS-a0, scalarS-9c, codeS-98, childS-94, prefixS-90, labelS-80.
// Preserve ignored reader statuses, retained scratch, exact BYTE tag copies/SCAS scans and cached destination.
// Return final append raw EAX/RET4 (native append helpers return destination); no parent EH/rollback.
// R6GameService.dll @ 1005b350 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendDecodedRecordText(void *message,void *destination)
{
  __asm {
    sub    esp,0xa4
    push    ebp
    mov    ebp,ecx
    push    esi
    lea    eax,[esp+0x2c]
    mov    cl,BYTE PTR [ebp+0xd]
    push    edi
    push    eax
    push    ecx
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x18],0x0
    call    R6GameServiceAddresses::FormatByteLabel
    mov    edi,R6GameServiceAddresses::WideTextOpenBracket
    or    ecx,0xffffffff
    xor    eax,eax
    mov    esi,DWORD PTR [esp+0xb4]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    edx,[esp+0xd]
    add    ecx,R6GameServiceAddresses::WideTextOpenBracket
    push    edx
    push    ecx
    push    R6GameServiceAddresses::WideTextOpenBracket
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    eax,[esp+0xf]
    lea    edi,[esp+0x30]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x34]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    ecx,[esp+ecx*1+0x34]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    eax,[esp+0xe]
    mov    edi,R6GameServiceAddresses::TextPunctuation4
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation4
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation4
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    al,BYTE PTR [ebp+0xd]
    cmp    al,0x26
    je    Branch31
    cmp    al,0x27
    je    Branch31
    cmp    al,0xd1
    jne    Branch30
    push    ebx
    lea    ecx,[esp+0x1c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [ebp+0x14]
    xor    bl,bl
    call    R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0x1c],0x0
    mov    ecx,DWORD PTR [ebp+0x14]
    jne    Branch25
    push    0x10
    lea    edx,[esp+0x28]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x18]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
    lea    ecx,[esp+0x1c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    ecx,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::GetIndexedClDataList
    lea    eax,[esp+0x11]
    mov    edi,R6GameServiceAddresses::TextPunctuation6
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation6
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation6
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    ecx,[esp+0x13]
    lea    edi,[esp+0x24]
    push    ecx
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x28]
    lea    edx,[esp+ecx*1+0x28]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    cl,BYTE PTR [esp+0x11]
    mov    edi,R6GameServiceAddresses::TextPunctuation
    mov    BYTE PTR [esp+0x12],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x12]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextPunctuation
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    bl,0x1
    jmp    Branch26
  Branch25:
    lea    eax,[esp+0x14]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
  Branch26:
    mov    edx,DWORD PTR [esp+0x1c]
    lea    ecx,[esp+0x34]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatWordAsDecimal
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    lea    eax,[esp+0x13]
    lea    edi,[esp+0x34]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x15]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x17],dl
    lea    edx,[esp+0x38]
    lea    ecx,[esp+ecx*1+0x38]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x11]
    mov    BYTE PTR [esp+0x11],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    ax,0x26
    je    Branch27
    cmp    ax,0x27
    je    Branch27
    mov    ecx,DWORD PTR [esp+0x14]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
    jmp    Branch28
  Branch27:
    mov    ecx,DWORD PTR [esp+0x14]
    lea    eax,[esp+0x18]
    push    0x0
    push    eax
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    edx,DWORD PTR [esp+0x18]
    lea    ecx,[esp+0x34]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatWordAsDecimal
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x11]
    mov    BYTE PTR [esp+0x11],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    lea    eax,[esp+0x13]
    lea    edi,[esp+0x34]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x15]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x17],dl
    lea    edx,[esp+0x38]
    lea    ecx,[esp+ecx*1+0x38]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    ecx,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x20]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch28
    mov    ecx,DWORD PTR [esp+0x20]
    push    esi
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0xc]
  Branch28:
    test    bl,bl
    pop    ebx
    je    Branch29
    mov    cl,BYTE PTR [esp+0xd]
    mov    edi,R6GameServiceAddresses::TextPunctuation4
    mov    BYTE PTR [esp+0xd],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xd]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextPunctuation4
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation4
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
  Branch29:
    mov    al,BYTE PTR [esp+0xd]
    lea    ecx,[esp+0xd]
    mov    BYTE PTR [esp+0xd],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push    ecx
    push    R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  Branch30:
    mov    ecx,DWORD PTR [ebp+0x14]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
    mov    al,BYTE PTR [esp+0xd]
    lea    ecx,[esp+0xd]
    mov    BYTE PTR [esp+0xd],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextPunctuation8
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextPunctuation8
    push    ecx
    push    R6GameServiceAddresses::WideTextPunctuation8
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  Branch31:
    mov    ecx,DWORD PTR [ebp+0x14]
    push    0x0
    lea    edx,[esp+0x18]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch32
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x18]
    push    0x0
    push    eax
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    cl,BYTE PTR [esp+0x18]
    mov    BYTE PTR [esp+0x14],cl
  Branch32:
    mov    eax,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x30]
    push    edx
    push    eax
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatByteLabel
    lea    ecx,[esp+0xd]
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    edi,[esp+0x30]
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xf]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    lea    eax,[esp+ecx*1+0x34]
    lea    ecx,[esp+0x34]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xe]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch33
    mov    ecx,DWORD PTR [esp+0x10]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
  Branch33:
    lea    eax,[esp+0xd]
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push    ecx
    push    R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  }
}

// Print current message label/payload using ordinary, top26/27 or nestedD1 paths and temporary owning lists.
// EntryS: codeS-d4, zeroed scalarS-d0, reusable listS-cc, main listS-b4, prefixS-9c and labelS-8c.
// Keep unchecked reader/copy statuses, exact state BYTE/full stores and destructor disarm order.
// Return newline printf raw EAX on ordinary path or final list-release raw EAX; exact twelve-state guard. No stack
// arguments.
// R6GameService.dll @ 1005af70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PrintDecodedRecord(void *message)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::PrintedRecordExceptionHandler
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc8
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    xor    ebx,ebx
    lea    eax,[esp+0x54]
    mov    DWORD PTR [esp+0x10],ebx
    mov    cl,BYTE PTR [esi+0xd]
    push    edi
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatByteLabel
    lea    edx,[esp+0x58]
    push    edx
    push    R6GameServiceAddresses::TextS5
    call    R6GameServiceAddresses::printf
    mov    al,BYTE PTR [esi+0xd]
    add    esp,0x8
    cmp    al,0x26
    je    Branch41
    cmp    al,0x27
    je    Branch41
    cmp    al,0xd1
    jne    Branch40
    mov    eax,0x3
    xor    bl,bl
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],eax
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0xe4],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    mov    DWORD PTR [esp+0xe8],0x4
    call    R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0x10],0x0
    jne    Branch34
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xe4],0x5
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    0x10
    lea    ecx,[esp+0x4c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    mov    BYTE PTR [esp+0xec],0x6
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x18]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedWord
    lea    ecx,[esp+0x30]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    lea    edx,[esp+0x48]
    push    edx
    push    R6GameServiceAddresses::TextS4
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    mov    bl,0x1
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xe0],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    BYTE PTR [esp+0xe0],0x4
    jmp    Branch35
  Branch34:
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x30]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataList
  Branch35:
    mov    edx,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x58]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatWordAsDecimal
    lea    eax,[esp+0x58]
    push    eax
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    mov    eax,DWORD PTR [esp+0x18]
    add    esp,0x8
    cmp    ax,0x26
    je    Branch36
    cmp    ax,0x27
    je    Branch36
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::PrintClDataList
    jmp    Branch38
  Branch36:
    push    0x0
    push    0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xe4],0x8
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x14]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0xe8],0x9
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x58]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatWordAsDecimal
    lea    ecx,[esp+0x58]
    push    ecx
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    lea    edx,[esp+0x18]
    lea    ecx,[esp+0x30]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch37
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::PrintClDataList
  Branch37:
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xe0],0xa
    call    R6GameServiceAddresses::DestroyClDataPointerList
  Branch38:
    test    bl,bl
    je    Branch39
    push    R6GameServiceAddresses::TextPunctuation4
    call    R6GameServiceAddresses::printf
    add    esp,0x4
  Branch39:
    push    R6GameServiceAddresses::TextCloseBracketLine
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0xe0],0xb
    lea    ecx,[esp+0x3c]
    jmp    Branch44
  Branch40:
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0x10]
    push    R6GameServiceAddresses::WideTextPunctuation8
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    jmp    Branch45
  Branch41:
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0xe4],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    ebx
    lea    ecx,[esp+0x18]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esp+0xec],0x1
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch42
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x10]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    al,BYTE PTR [esp+0x10]
    mov    BYTE PTR [esp+0x14],al
  Branch42:
    mov    edx,DWORD PTR [esp+0x14]
    lea    ecx,[esp+0x58]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatByteLabel
    lea    eax,[esp+0x58]
    push    eax
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    lea    ecx,[esp+0x18]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch43
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::PrintClDataList
  Branch43:
    push    R6GameServiceAddresses::TextCloseBracketLine
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    mov    DWORD PTR [esp+0xe0],0x2
    lea    ecx,[esp+0x24]
  Branch44:
    call    R6GameServiceAddresses::DestroyClDataPointerList
  Branch45:
    mov    ecx,DWORD PTR [esp+0xd8]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xd4
    ret
  }
}

// Reset base vtable of inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 10069990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetBasePrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 1006999b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699a6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699b1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699bc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList2(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList3(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699d2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList2(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699dd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList4(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList5(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699f3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList6(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699fe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList3(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 10069a09 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList7(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select literal twelve-state print cleanup FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 10069a14 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PrintedRecordExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PrintDecodedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native print-list cleanup map/FuncInfo.
// R6GameService.dll data @ 10084450 : native storage identity retained.
const R6GameServiceNative::UnwindEntry PrintDecodedRecordUnwindMap[12] = {
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList6},
  {-1, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList3},
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList7},
  {-1, R6GameServiceAddresses::ResetBasePrintedRecordList},
  {-1, R6GameServiceAddresses::DestroyPrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList2},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList3},
  {0x4, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList2},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList4},
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList5},
};

// Literal native print-list cleanup map/FuncInfo.
// R6GameService.dll data @ 100844b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo PrintDecodedRecordExceptionInfo = {
  0x19930520,
  0xc,
  R6GameServiceAddresses::PrintDecodedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clGSMessageVTable
// R6GameService.dll data @ 1007819c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGSMessageVTableRecord {
  R6GameServiceNative::Address DeleteClGSMessage; // +0x00
  R6GameServiceNative::Address SerializePayloadRecord; // +0x04
  R6GameServiceNative::Address AppendDecodedRecordText; // +0x08
  R6GameServiceNative::Address PrintDecodedRecord; // +0x0c
  R6GameServiceNative::Address DecodePayloadRecord; // +0x10
  R6GameServiceNative::Address EncodeMessagePayload; // +0x14
  R6GameServiceNative::Address DecodeMessagePayload; // +0x18
};
const clGSMessageVTableRecord clGSMessageVTable = {
  R6GameServiceAddresses::DeleteClGSMessage,
  R6GameServiceAddresses::SerializePayloadRecord,
  R6GameServiceAddresses::AppendDecodedRecordText,
  R6GameServiceAddresses::PrintDecodedRecord,
  R6GameServiceAddresses::DecodePayloadRecord,
  R6GameServiceAddresses::EncodeMessagePayload,
  R6GameServiceAddresses::DecodeMessagePayload,
};
