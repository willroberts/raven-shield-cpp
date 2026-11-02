#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ec00 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PooledBufferReleaseExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007f818 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo EmptyPooledBufferInitExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007f878 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PooledTripletCopyExceptionHandlerFunctionInfo;

// Returns the caller's constructor-tag address from ECX in EAX without touching memory or stack arguments.
// R6GameService.dll @ 10027b60 : ECX tag address, no stack arguments; MOV EAX,ECX then RET.
void * __fastcall ForwardPooledStringTag(void *tagAddress)
{
  return tagAddress;
}

// Release locals span logical EBP-0x10..-4, retaining the descriptor for capacity-context unwinding.
struct PooledBufferReleaseFrame {
  uint *savedReceiver;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Releases a nonnull buffer to the heap or its pool class without clearing the descriptor's words.
// R6GameService.dll @ 10017330 : ECX descriptor, no stack arguments; EAX=extent, old pool head or heap-release residue.
uint __fastcall ReleasePooledBuffer(undefined4 *bufferDescriptor)
{
  PooledBufferReleaseFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PooledBufferReleaseExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedReceiver = (uint *)bufferDescriptor;
  uint buffer = bufferDescriptor[0];
  uint allocationBytes = bufferDescriptor[2] - buffer;
  frame.state = 0;
  uint result = allocationBytes;
  if (buffer != 0) {
    if (allocationBytes > 0x80) {
      result = FreeThroughGlobalAllocator((void *)buffer);
    } else {
      uint sizeClass = (allocationBytes - 1) >> 3;
      uint *poolHeadSlot = (uint *)((uint)&GByteStringPoolFreeLists + (sizeClass << 2));
      AcquireBufferPoolLock(&GByteStringPoolLock);
      result = *poolHeadSlot;
      *(uint *)buffer = result;
      *poolHeadSlot = buffer;
      GByteStringPoolLock = 0;
    }
  }
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Forwards the saved descriptor's capacity-word address to empty cleanup, retaining incoming EAX.
// R6GameService.dll @ 10064900 : inherited EBP; ECX=[EBP-0x10]+8, JMP10059130.
__declspec(naked) void __cdecl CleanupPooledBufferReleaseContext(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the pooled-buffer release's one-state exception metadata.
// R6GameService.dll @ 1006490b : EAX=1007ec00, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PooledBufferReleaseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PooledBufferReleaseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Allocator locals span logical EBP-0x14..-4; spin work and the arena batch count reuse the first word.
// Tail-dispatches the original count word to the pool through 128 bytes or to the global allocator above it.
// R6GameService.dll @ 10027b70 : byte-count cdecl stack word; target controls EAX and caller cleanup remains unchanged.
__declspec(naked) void * __cdecl AllocateByteStringStorage(uint byteCount)
{
  __asm {
    mov    eax,dword ptr [esp+0x4]
    cmp    eax,0x80
    mov    dword ptr [esp+0x4],eax
    jbe    pooled
    jmp    R6GameServiceAddresses::AllocateTaggedBytesCdecl
  pooled:
    jmp    R6GameServiceAddresses::AllocateSmallByteStringBlock
  }
}

// Initializer locals span logical EBP-0x14..-4; the unused lock context at -0x0d aliases savedReceiver's high byte.
struct EmptyPooledBufferInitFrame {
  uint blockCount;
  uint *savedReceiver;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Initializes an empty string in an eight-byte pooled block, linking any remaining refill blocks into class zero.
// R6GameService.dll @ 100274c0 : ECX triplet, no stack arguments; EAX=receiver, normal state remains1 after unlock.
undefined4 * __fastcall InitializePooledBufferDescriptor(undefined4 *descriptor)
{
  EmptyPooledBufferInitFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)EmptyPooledBufferInitExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedReceiver = descriptor;
  descriptor[0] = 0;
  descriptor[1] = 0;
  descriptor[2] = 0;
  frame.state = 0;
  AcquireBufferPoolLock(&GByteStringPoolLock);
  uint block = (uint)GByteStringPoolFreeLists;
  *(byte *)&frame.state = 1;
  if (block != 0) {
    GByteStringPoolFreeLists = *(undefined4 **)block;
  } else {
    frame.blockCount = 20;
    block = (uint)AllocatePooledBlocks(8,&frame.blockCount);
    uint count = frame.blockCount;
    if (count != 1) {
      uint tail = block + 8;
      GByteStringPoolFreeLists = (undefined4 *)tail;
      uint next = tail + 8;
      uint index = 1;
      while (count - 1 != index) {
        *(uint *)tail = next;
        count = frame.blockCount;
        tail = next;
        ++index;
        next += 8;
      }
      *(uint *)tail = 0;
    }
  }
  uint capacityEnd = block + 8;
  GByteStringPoolLock = 0;
  descriptor[0] = block;
  descriptor[1] = block;
  descriptor[2] = capacityEnd;
  void *previousExceptionList = frame.previousExceptionList;
  *(byte *)block = 0;
  ExceptionList = previousExceptionList;
  return descriptor;
}

// Releases the saved constructing triplet after the initializer's lock cleanup, where applicable.
// R6GameService.dll @ 100656a0 : inherited EBP; MOV ECX,[EBP-0x10], JMP10017330.
__declspec(naked) void __cdecl ReleaseEmptyPooledBufferConstruction(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Forwards the aliased context-byte address to global unlock without dereferencing it or changing EAX.
// R6GameService.dll @ 100656a8 : inherited EBP; LEA ECX,[EBP-0x0d], JMP10017ac0.
__declspec(naked) void __cdecl UnlockEmptyPooledBufferConstruction(void)
{
  __asm {
    lea    ecx,[ebp-0x0d]
    jmp    R6GameServiceAddresses::ReleaseGlobalByteStringPoolLock
  }
}

// Selects the empty pooled-string initializer's two-state exception metadata.
// R6GameService.dll @ 100656b0 : EAX=1007f818, inherited-frame JMP10033906.
__declspec(naked) void __cdecl EmptyPooledBufferInitExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::EmptyPooledBufferInitExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Assign with forward DWORD/byte copies, preserving current end byte on shortening; append the remaining range on growth.
// R6GameService.dll @ 10027000 : complete native operations/raw ABI; descriptive shared string helper name.
__declspec(naked) void * __thiscall AssignPooledByteStringRange(
    void *triplet,const byte *first,const byte *last)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    push   esi
    push   edi
    mov    eax,ebp
    mov    edi,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [ebx+0x4]
    sub    eax,edx
    sub    ecx,edi
    cmp    eax,ecx
    ja     Branch3
    test   eax,eax
    je     Branch1
    mov    ecx,eax
    mov    esi,edx
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch1:
    mov    esi,DWORD PTR [ebx]
    mov    edi,DWORD PTR [ebx+0x4]
    add    esi,eax
    cmp    esi,edi
    je     Branch5
    mov    eax,edi
    sub    eax,edi
    inc    eax
    je     Branch2
    push   eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch2:
    mov    eax,DWORD PTR [ebx+0x4]
    sub    esi,edi
    add    eax,esi
    pop    edi
    mov    DWORD PTR [ebx+0x4],eax
    pop    esi
    mov    eax,ebx
    pop    ebp
    pop    ebx
    ret    0x8
  Branch3:
    test   ecx,ecx
    je     Branch4
    mov    eax,ecx
    mov    esi,edx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch4:
    mov    cl,BYTE PTR [esp+0x18]
    mov    edi,DWORD PTR [ebx]
    mov    BYTE PTR [esp+0x18],cl
    mov    ecx,DWORD PTR [ebx+0x4]
    lea    eax,[esp+0x18]
    sub    ecx,edi
    push   eax
    add    ecx,edx
    push   ebp
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::AppendByteRangeToHeapString
  Branch5:
    pop    edi
    pop    esi
    mov    eax,ebx
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Append tail before first byte in place, or copy into grown pool/heap storage before old release and late publication.
// R6GameService.dll @ 10028630 : complete native operations/raw ABI; descriptive shared string helper name.
__declspec(naked) void * __thiscall AppendByteRangeToHeapString(
    void *triplet,const byte *first,const byte *last,void *unusedTag)
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
    je     Branch15
    mov    ebx,DWORD PTR [esi+0x4]
    mov    edi,DWORD PTR [esi]
    sub    ebx,edi
    mov    edi,ebp
    sub    edi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    cmp    edi,0xfffffffe
    ja     Branch6
    mov    eax,0xfffffffe
    sub    eax,edi
    cmp    ebx,eax
    jbe    Branch7
  Branch6:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    mov    ecx,DWORD PTR [esp+0x1c]
    add    esp,0x4
  Branch7:
    mov    edx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [esi]
    sub    edx,eax
    lea    eax,[edi+ebx*1]
    dec    edx
    cmp    eax,edx
    jbe    Branch13
    cmp    ebx,edi
    mov    DWORD PTR [esp+0x1c],edi
    lea    eax,[esp+0x1c]
    jb     Branch8
    lea    eax,[esp+0x10]
  Branch8:
    mov    ecx,DWORD PTR [eax]
    lea    ebx,[ecx+ebx*1+0x1]
    test   ebx,ebx
    mov    DWORD PTR [esp+0x1c],ebx
    je     Branch10
    cmp    ebx,0x80
    push   ebx
    jbe    Branch9
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    ebp,eax
    jmp    Branch11
  Branch9:
    call   R6GameServiceAddresses::AllocateSmallByteStringBlock
    add    esp,0x4
    mov    ebp,eax
    jmp    Branch11
  Branch10:
    xor    ebp,ebp
  Branch11:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi]
    push   ebp
    push   eax
    push   ecx
    call   R6GameServiceAddresses::MoveByteRange
    mov    edx,DWORD PTR [esp+0x18]
    push   edi
    push   edx
    push   eax
    call   R6GameServiceAddresses::memmove
    mov    ebx,eax
    add    esp,0xc
    add    ebx,edi
    mov    BYTE PTR [ebx],0x0
    mov    eax,DWORD PTR [esi]
    test   eax,eax
    je     Branch12
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
    push   ecx
    push   eax
    call   R6GameServiceAddresses::ReleaseByteAllocation
    add    esp,0x8
  Branch12:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi],ebp
    add    ebp,edx
    mov    DWORD PTR [esi+0x4],ebx
    mov    DWORD PTR [esi+0x8],ebp
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  Branch13:
    lea    eax,[ecx+0x1]
    cmp    ebp,eax
    je     Branch14
    sub    ebp,eax
    push   ebp
    push   eax
    mov    eax,DWORD PTR [esi+0x4]
    inc    eax
    push   eax
    call   R6GameServiceAddresses::memmove
    mov    ecx,DWORD PTR [esp+0x24]
    add    esp,0xc
  Branch14:
    mov    edx,DWORD PTR [esi+0x4]
    mov    BYTE PTR [edi+edx*1],0x0
    mov    eax,DWORD PTR [esi+0x4]
    mov    cl,BYTE PTR [ecx]
    mov    BYTE PTR [eax],cl
    mov    eax,DWORD PTR [esi+0x4]
    add    eax,edi
    mov    DWORD PTR [esi+0x4],eax
  Branch15:
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Triplet-copy locals span logical EBP-0x130..-4; source end, error triplet and saved receiver stay distinct.
struct PooledTripletCopyFrame {
  byte padding[2];
  byte forwardedTag;
  byte errorConstructorTag;
  uint sourceLast;
  uint errorMessage[3];
  uint *savedReceiver;
  byte exceptionStorage[0x10c];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs a NUL-terminated range copy after zeroing the destination; it does not release an old destination buffer.
// R6GameService.dll @ 10027df0 : ECX destination, source-triplet stack word, RET4; EAX=destination.
void * __thiscall ConstructPooledByteStringFromTriplet(void *destination,uint *sourceTriplet)
{
  PooledTripletCopyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PooledTripletCopyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  uint *words = (uint *)destination;
  frame.savedReceiver = words;
  ForwardStackWord((uint)&frame.forwardedTag);
  words[0] = 0;
  words[1] = 0;
  words[2] = 0;
  frame.sourceLast = sourceTriplet[1];
  uint sourceFirst = sourceTriplet[0];
  uint byteCount = frame.sourceLast - sourceFirst;
  frame.state = 0;
  uint allocationBytes = byteCount + 1;
  if (allocationBytes == 0) {
    InitializeEmptyByteBufferTripletWithContext(frame.errorMessage,&frame.errorConstructorTag);
    *(byte *)&frame.state = 1;
    uint remaining = 0xffffffff;
    char *scan = s_basic_string;
    while (remaining != 0) {
      --remaining;
      char character = *scan++;
      if (character == 0) break;
    }
    char *messageEnd = (char *)((uint)s_basic_string + (~remaining - 1));
    InitializeByteStringFromRange(frame.errorMessage,s_basic_string,messageEnd);
    *(byte *)&frame.state = 2;
    ConstructException75c28(frame.exceptionStorage,frame.errorMessage);
    _CxxThrowException(frame.exceptionStorage,(ThrowInfo *)&ByteStringLengthErrorThrowInfo);
  }
  uint buffer = allocationBytes <= 0x80 ? (uint)AllocateSmallByteStringBlock(allocationBytes)
                                        : (uint)AllocateTaggedBytesCdecl(allocationBytes);
  words[2] = buffer + allocationBytes;
  uint sourceLast = frame.sourceLast;
  words[0] = buffer;
  words[1] = buffer;
  uint end = buffer;
  if (sourceLast != sourceFirst) end = (uint)memmove((void *)buffer,(void *)sourceFirst,byteCount) + byteCount;
  void *previousExceptionList = frame.previousExceptionList;
  words[1] = end;
  *(byte *)end = 0;
  ExceptionList = previousExceptionList;
  return destination;
}

// Releases the saved destination triplet if its copy construction unwinds.
// R6GameService.dll @ 100656e0 : inherited EBP; MOV ECX,[EBP-0x11c], JMP10017330.
__declspec(naked) void __cdecl ReleasePooledTripletCopyConstruction(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x11c]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Releases the copy constructor's error-message triplet after its initial setup state.
// R6GameService.dll @ 100656eb : inherited EBP; LEA ECX,[EBP-0x128], JMP10017330.
__declspec(naked) void __cdecl ReleasePooledTripletCopyErrorMessage(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Releases the same error-message triplet for the later native construction state.
// R6GameService.dll @ 100656f6 : inherited EBP; LEA ECX,[EBP-0x128], JMP10017330.
__declspec(naked) void __cdecl ReleasePooledTripletCopyErrorMessageLate(void)
{
  __asm {
    lea    ecx,[ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects the triplet copy constructor's three-state exception metadata.
// R6GameService.dll @ 10065701 : EAX=1007f878, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PooledTripletCopyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PooledTripletCopyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Allocates a pooled or heap range plus terminator, publishes its descriptor and returns the raw copy end.
// Cached length drives allocation/copy; original last argument reload decides the copy gate. No local unwind guard.
// R6GameService.dll @ 10017ad0 : native control/access order and raw ABI retained.
__declspec(naked) char * __thiscall InitializeByteStringFromRange(void *destination,char *first,char *last)
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
    ja     Branch17
    test   ebx,ebx
    jbe    Branch17
    cmp    ebx,0x80
    push   ebx
    jbe    Branch16
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch18
  Branch16:
    call   R6GameServiceAddresses::AllocateSmallByteStringBlock
    add    esp,0x4
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    add    eax,ebx
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch18
  Branch17:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
  Branch18:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi]
    cmp    ecx,ebp
    je     Branch19
    push   edi
    push   ebp
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch19:
    mov    DWORD PTR [esi+0x4],eax
    pop    edi
    pop    esi
    pop    ebp
    mov    BYTE PTR [eax],0x0
    pop    ebx
    ret    0x8
  }
}

// Builds a pooled diagnostic and inline _STL::length_error, then nonreturningly throws with native ThrowInfo7eb8c.
// Both states release only the diagnostic; base/copy order and unreachable trailing pops remain explicit.
// R6GameService.dll @ 10017b50 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ThrowByteStringLengthError(char *message)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ThrowByteStringLengthErrorSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x11c
    push   ebx
    push   ebp
    push   esi
    xor    ebx,ebx
    push   edi
    lea    eax,[esp+0x13]
    push   ebx
    push   eax
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x20],ebx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    ebp,DWORD PTR [esp+0x13c]
    or     ecx,0xffffffff
    mov    edi,ebp
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    DWORD PTR [esp+0x134],ebx
    mov    esi,ecx
    lea    ecx,[esp+0x14]
    add    esi,ebp
    mov    eax,esi
    sub    eax,ebp
    inc    eax
    push   eax
    call   R6GameServiceAddresses::InitializePooledByteString
    mov    ecx,DWORD PTR [esp+0x14]
    push   ecx
    push   esi
    push   ebp
    call   R6GameServiceAddresses::MoveByteRange
    mov    DWORD PTR [esp+0x18],eax
    mov    BYTE PTR [eax],bl
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x134],0x1
    call   R6GameServiceAddresses::exception_exception2
    mov    edx,DWORD PTR [esp+0x14]
    push   0x100
    lea    eax,[esp+0x30]
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::Named_exception__STLVTable
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x12b],bl
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::length_error__STLVTable
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
  }
}

// Releases the partially initialized pooled diagnostic at inherited EBP-124 before exception construction.
// R6GameService.dll @ 100649e0 : native control/access order and raw ABI retained.
__declspec(naked) void ThrowByteStringLengthErrorUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Releases the pooled diagnostic at inherited EBP-124 after message construction; no exception-object action is added.
// R6GameService.dll @ 100649eb : native control/access order and raw ABI retained.
__declspec(naked) void ThrowByteStringLengthErrorUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects the two independent diagnostic-release states for the nonreturning length throw helper.
// R6GameService.dll @ 100649f6 : native control/access order and raw ABI retained.
__declspec(naked) void ThrowByteStringLengthErrorSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ThrowByteStringLengthErrorExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ed9c : native pooled diagnostic lifetime record.
const R6GameServiceNative::UnwindEntry ThrowByteStringLengthErrorUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ThrowByteStringLengthErrorUnwind1},
  {-1, R6GameServiceAddresses::ThrowByteStringLengthErrorUnwind2},
};

// R6GameService.dll data @ 1007edac : native pooled diagnostic lifetime record.
const R6GameServiceNative::FuncInfo ThrowByteStringLengthErrorExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ThrowByteStringLengthErrorUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Clears an owning descriptor, scans its source, obtains pool/heap storage and publishes a terminated copy.
// Late source argument, saved length/receiver/head words, recursive length error and all three states remain explicit.
// R6GameService.dll @ 10017640 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructPooledByteString(void *owner,char *source,void *unusedTag)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::PooledByteStringConstructExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x128
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    xor    edx,edx
    push   edi
    mov    DWORD PTR [esi],edx
    mov    DWORD PTR [esi+0x4],edx
    mov    DWORD PTR [esp+0x1c],esi
    mov    DWORD PTR [esi+0x8],edx
    mov    ebx,DWORD PTR [esp+0x148]
    or     ecx,0xffffffff
    mov    edi,ebx
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    DWORD PTR [esp+0x140],edx
    mov    ebp,ecx
    add    ebp,ebx
    mov    edi,ebp
    sub    edi,ebx
    mov    DWORD PTR [esp+0x18],edi
    inc    edi
    cmp    edi,0xffffffff
    ja     Branch25
    cmp    edi,edx
    jbe    Branch25
    cmp    edi,0x80
    jbe    Branch20
    push   edi
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    jmp    Branch23
  Branch20:
    lea    eax,[edi-0x1]
    shr    eax,0x3
    lea    ecx,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,R6GameServiceAddresses::GByteStringPoolLock
    call   R6GameServiceAddresses::pooled_string_support_AcquireBufferPoolLock
    mov    ecx,DWORD PTR [esp+0x10]
    mov    BYTE PTR [esp+0x140],0x1
    mov    eax,DWORD PTR [ecx]
    test   eax,eax
    mov    DWORD PTR [esp+0x10],eax
    je     Branch21
    mov    edx,DWORD PTR [eax]
    mov    DWORD PTR [ecx],edx
    jmp    Branch22
  Branch21:
    push   edi
    call   R6GameServiceAddresses::AllocatePooledByteStringBlock
    add    esp,0x4
    mov    DWORD PTR [esp+0x10],eax
  Branch22:
    mov    ecx,R6GameServiceAddresses::GByteStringPoolLock
    mov    BYTE PTR [esp+0x140],0x0
    call   R6GameServiceAddresses::ReleaseBufferPoolLock
    mov    eax,DWORD PTR [esp+0x10]
  Branch23:
    lea    ecx,[eax+edi*1]
    cmp    ebp,ebx
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    je     Branch24
    mov    edi,DWORD PTR [esp+0x18]
    push   edi
    push   ebx
    push   eax
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,edi
  Branch24:
    mov    ecx,DWORD PTR [esp+0x138]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x134
    ret    0x8
  Branch25:
    lea    edx,[esp+0x17]
    lea    ecx,[esp+0x20]
    push   edx
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ConstructPooledByteString
    push   eax
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x144],0x2
    call   R6GameServiceAddresses::ConstructException75c28
    lea    eax,[esp+0x2c]
    push   R6GameServiceAddresses::ByteStringLengthErrorThrowInfo
    push   eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Acquires the supplied lock using atomic exchange, arithmetic spinning and capped exponential Sleep backoff.
// Saved ECX doubles as spin scratch; cached API pointers/global limits and raw register residues remain native.
// R6GameService.dll @ 10017790 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall pooled_string_support_AcquireBufferPoolLock(LONG *lockWord)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    ebp,ecx
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    je     Branch27
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount
    mov    eax,ds:0x10093bb4
    xor    esi,esi
    mov    DWORD PTR [esp+0x10],0x11
    test   edi,edi
    jbe    Branch30
    mov    ebx,eax
    shr    ebx,1
  Branch26:
    cmp    esi,ebx
    jb     Branch28
    cmp    DWORD PTR [ebp+0x0],0x0
    jne    Branch28
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    jne    Branch29
    mov    DWORD PTR ds:0x10093bb4,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x3e8
  Branch27:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret
  Branch28:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x10]
    imul   edx,eax
    mov    DWORD PTR [esp+0x10],edx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x10]
    imul   ecx,edx
    mov    DWORD PTR [esp+0x10],ecx
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x10],eax
  Branch29:
    inc    esi
    cmp    esi,edi
    jb     Branch26
  Branch30:
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x1e
    mov    edi,0x6
  Branch31:
    cmp    edi,0x1b
    mov    esi,edi
    jle    Branch32
    mov    esi,0x1b
  Branch32:
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    je     Branch27
    cmp    esi,0x14
    jg     Branch33
    push   0x0
    call   ebx
    inc    edi
    jmp    Branch31
  Branch33:
    lea    ecx,[esi-0x14]
    mov    edx,0x1
    shl    edx,cl
    push   edx
    call   ebx
    inc    edi
    jmp    Branch31
  }
}

// Clears the supplied lock word and retains incoming EAX, with no barrier or stack arguments.
// R6GameService.dll @ 10017880 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseBufferPoolLock(LONG *lockWord)
{
  __asm {
    mov    DWORD PTR [ecx],0x0
    ret
  }
}

// Clears the fixed global pool lock; supplied context and incoming EAX remain unused/unchanged.
// R6GameService.dll @ 10017ac0 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseGlobalByteStringPoolLock(void)
{
  __asm {
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolLock,0x0
    ret
  }
}

// Acquires the pool lock, pops the cached class or refills an eight-byte-rounded batch, then clears the lock.
// Requested-size reload, mutable count/head slots, unchecked class arithmetic and exact one-state guard remain native.
// R6GameService.dll @ 10017c20 : native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl AllocateSmallByteStringBlock(uint byteCount)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SmallByteStringAllocateExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x18]
    push   ebx
    dec    eax
    push   ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    push   esi
    shr    eax,0x3
    push   edi
    push   0x1
    lea    ecx,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    push   R6GameServiceAddresses::GByteStringPoolLock
    mov    DWORD PTR [esp+0x1c],ecx
    call   ebp
    test   eax,eax
    je     Branch41
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount
    mov    eax,ds:0x10093bb4
    xor    esi,esi
    mov    DWORD PTR [esp+0x10],0x11
    test   edi,edi
    jbe    Branch37
    mov    ebx,eax
    shr    ebx,1
  Branch34:
    cmp    esi,ebx
    jb     Branch35
    mov    eax,ds:R6GameServiceAddresses::GByteStringPoolLock
    test   eax,eax
    jne    Branch35
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    jne    Branch36
    mov    DWORD PTR ds:0x10093bb4,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x3e8
    jmp    Branch41
  Branch35:
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x10]
    imul   edx,eax
    mov    DWORD PTR [esp+0x10],edx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x10]
    imul   ecx,edx
    mov    DWORD PTR [esp+0x10],ecx
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x10]
    imul   edx,eax
    mov    DWORD PTR [esp+0x10],edx
  Branch36:
    inc    esi
    cmp    esi,edi
    jb     Branch34
  Branch37:
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x1e
    mov    edi,0x6
  Branch38:
    cmp    edi,0x1b
    mov    esi,edi
    jle    Branch39
    mov    esi,0x1b
  Branch39:
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    je     Branch41
    cmp    esi,0x14
    jg     Branch40
    push   0x0
    call   ebx
    inc    edi
    jmp    Branch38
  Branch40:
    lea    ecx,[esi-0x14]
    mov    edx,0x1
    shl    edx,cl
    push   edx
    call   ebx
    inc    edi
    jmp    Branch38
  Branch41:
    mov    ecx,DWORD PTR [esp+0x14]
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x20],ebp
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebp
    je     Branch42
    mov    edx,DWORD PTR [eax]
    mov    DWORD PTR [ecx],edx
    jmp    Branch45
  Branch42:
    mov    eax,DWORD PTR [esp+0x28]
    lea    ecx,[esp+0x10]
    push   ecx
    mov    DWORD PTR [esp+0x14],0x14
    lea    esi,[eax+0x7]
    and    esi,0xfffffff8
    push   esi
    call   R6GameServiceAddresses::AllocatePooledBlocks
    mov    ebx,DWORD PTR [esp+0x18]
    add    esp,0x8
    cmp    ebx,0x1
    je     Branch45
    lea    edx,[esi-0x1]
    lea    ecx,[eax+esi*1]
    shr    edx,0x3
    mov    edi,0x1
    mov    DWORD PTR [edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists],ecx
    mov    edx,ecx
    add    ecx,esi
    dec    ebx
    cmp    ebx,edi
    je     Branch44
  Branch43:
    mov    DWORD PTR [edx],ecx
    mov    ebx,DWORD PTR [esp+0x10]
    mov    edx,ecx
    inc    edi
    add    ecx,esi
    dec    ebx
    cmp    ebx,edi
    jne    Branch43
  Branch44:
    mov    DWORD PTR [edx],ebp
  Branch45:
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolLock,ebp
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Returns the first rounded block, linking remaining arena blocks into the class free list.
// Preserves partial batches, leftover linking, growth wrapping, failed-allocation scavenging and raw recursive results.
// R6GameService.dll @ 10017ee0 : native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl AllocatePooledByteStringBlock(uint requestedByteCount)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor
    lea    esi,[eax+0x7]
    mov    eax,ds:0x10093bbc
    and    esi,0xfffffff8
    sub    eax,edi
    mov    ebx,0x14
    lea    ecx,[esi+esi*4]
    mov    DWORD PTR [esp+0xc],ebx
    shl    ecx,0x2
    cmp    eax,ecx
    jb     Branch46
    mov    eax,edi
    add    edi,ecx
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,edi
    jmp    Branch54
  Branch46:
    cmp    eax,esi
    jb     Branch47
    xor    edx,edx
    div    esi
    mov    ebx,eax
    mov    eax,edi
    mov    ecx,ebx
    mov    DWORD PTR [esp+0xc],ebx
    imul   ecx,esi
    add    edi,ecx
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,edi
    jmp    Branch53
  Branch47:
    mov    edx,DWORD PTR ds:0x10093bb8
    shr    edx,0x4
    add    edx,0x7
    and    edx,0xfffffff8
    test   eax,eax
    lea    ebx,[edx+ecx*2]
    jbe    Branch48
    dec    eax
    shr    eax,0x3
    mov    ecx,DWORD PTR [eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    lea    eax,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    mov    DWORD PTR [edi],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor
    mov    DWORD PTR [eax],edx
  Branch48:
    push   ebx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
    test   eax,eax
    jne    Branch51
    cmp    esi,0x80
    mov    ecx,esi
    ja     Branch50
  Branch49:
    lea    eax,[ecx-0x1]
    shr    eax,0x3
    lea    edx,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    mov    eax,DWORD PTR [eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    test   eax,eax
    jne    Branch58
    add    ecx,0x8
    cmp    ecx,0x80
    jbe    Branch49
  Branch50:
    push   ebx
    mov    DWORD PTR ds:0x10093bbc,0x0
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
  Branch51:
    mov    ecx,DWORD PTR ds:0x10093bb8
    lea    edx,[esp+0xc]
    add    ecx,ebx
    add    eax,ebx
    mov    DWORD PTR ds:0x10093bb8,ecx
    push   edx
  Branch52:
    push   esi
    mov    ds:0x10093bbc,eax
    call   R6GameServiceAddresses::AllocatePooledBlocks
    mov    ebx,DWORD PTR [esp+0x14]
    add    esp,0x8
  Branch53:
    cmp    ebx,0x1
    je     Branch57
  Branch54:
    lea    edx,[esi-0x1]
    lea    ecx,[eax+esi*1]
    shr    edx,0x3
    mov    edi,0x1
    mov    DWORD PTR [edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists],ecx
    mov    edx,ecx
    add    ecx,esi
    dec    ebx
    cmp    ebx,edi
    je     Branch56
  Branch55:
    mov    DWORD PTR [edx],ecx
    mov    ebx,DWORD PTR [esp+0xc]
    mov    edx,ecx
    inc    edi
    add    ecx,esi
    dec    ebx
    cmp    ebx,edi
    jne    Branch55
  Branch56:
    mov    DWORD PTR [edx],0x0
  Branch57:
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret
  Branch58:
    mov    edi,DWORD PTR [eax]
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
    add    eax,ecx
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [edx],edi
    push   ecx
    jmp    Branch52
  }
}

// Consumes an arena batch, reducing the live count for partial space or growing/scavenging arena storage.
// Count reloads/aliases, unchecked allocations and modulo arithmetic remain native; this helper adds no lock or guard.
// R6GameService.dll @ 10018310 : native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl AllocatePooledBlocks(uint blockSize,uint *count)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR ds:0x10093bbc
    mov    eax,ds:R6GameServiceAddresses::GByteStringPoolArenaCursor
    mov    ecx,DWORD PTR [ebp+0x0]
    sub    edx,eax
    imul   ecx,ebx
    push   esi
    cmp    edx,ecx
    push   edi
    jae    Branch65
    mov    esi,DWORD PTR ds:0x10093bb8
  Branch59:
    cmp    edx,ebx
    jae    Branch67
    shr    esi,0x4
    add    esi,0x7
    and    esi,0xfffffff8
    test   edx,edx
    lea    edi,[esi+ecx*2]
    jbe    Branch60
    dec    edx
    shr    edx,0x3
    lea    ecx,[edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    mov    edx,DWORD PTR [edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    mov    DWORD PTR [eax],edx
    mov    eax,ds:R6GameServiceAddresses::GByteStringPoolArenaCursor
    mov    DWORD PTR [ecx],eax
  Branch60:
    push   edi
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
    test   eax,eax
    jne    Branch63
    cmp    ebx,0x80
    mov    ecx,ebx
    ja     Branch62
  Branch61:
    lea    edx,[ecx-0x1]
    shr    edx,0x3
    mov    eax,DWORD PTR [edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    lea    edx,[edx*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    test   eax,eax
    jne    Branch66
    add    ecx,0x8
    cmp    ecx,0x80
    jbe    Branch61
  Branch62:
    push   edi
    mov    DWORD PTR ds:0x10093bbc,0x0
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
  Branch63:
    mov    esi,DWORD PTR ds:0x10093bb8
    lea    edx,[eax+edi*1]
    add    esi,edi
    mov    DWORD PTR ds:0x10093bb8,esi
  Branch64:
    mov    DWORD PTR ds:0x10093bbc,edx
    mov    ecx,DWORD PTR [ebp+0x0]
    imul   ecx,ebx
    sub    edx,eax
    cmp    edx,ecx
    jb     Branch59
  Branch65:
    mov    edx,eax
    add    eax,ecx
    pop    edi
    pop    esi
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
    pop    ebp
    mov    eax,edx
    pop    ebx
    ret
  Branch66:
    mov    esi,DWORD PTR [eax]
    mov    ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,eax
    mov    DWORD PTR [edx],esi
    mov    esi,DWORD PTR ds:0x10093bb8
    lea    edx,[eax+ecx*1]
    jmp    Branch64
  Branch67:
    mov    eax,edx
    xor    edx,edx
    div    ebx
    pop    edi
    pop    esi
    mov    DWORD PTR [ebp+0x0],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor
    imul   eax,ebx
    mov    edx,ecx
    add    ecx,eax
    pop    ebp
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolArenaCursor,ecx
    mov    eax,edx
    pop    ebx
    ret
  }
}

// Allocates nonzero requested bytes from pool through128 or heap above128 and publishes an empty descriptor.
// Capacity is requested size, not rounded block size; zero invokes the nonreturning length-error helper.
// R6GameService.dll @ 10018440 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializePooledByteString(void *owner,uint byteCount)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    cmp    esi,0xffffffff
    mov    edi,ecx
    ja     Branch69
    test   esi,esi
    jbe    Branch69
    cmp    esi,0x80
    push   esi
    jbe    Branch68
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    mov    DWORD PTR [edi],eax
    mov    DWORD PTR [edi+0x4],eax
    add    eax,esi
    mov    DWORD PTR [edi+0x8],eax
    pop    edi
    pop    esi
    ret    0x4
  Branch68:
    call   R6GameServiceAddresses::AllocateSmallByteStringBlock
    add    esp,0x4
    mov    DWORD PTR [edi],eax
    mov    DWORD PTR [edi+0x4],eax
    add    eax,esi
    mov    DWORD PTR [edi+0x8],eax
    pop    edi
    pop    esi
    ret    0x4
  Branch69:
    push   R6GameServiceAddresses::s_basic_string
    call   R6GameServiceAddresses::ThrowByteStringLengthError
    add    esp,0x4
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Releases the CURRENT saved constructing receiver at inherited EBP-128 through pooled descriptor destruction.
// R6GameService.dll @ 10064950 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPooledStringConstruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x128]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Forwards inherited EBP-15 to the fixed global lock clear, retaining raw EAX.
// R6GameService.dll @ 1006495b : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnlockPooledStringConstruction(void)
{
  __asm {
    lea    ecx,[ebp-0x15]
    jmp    R6GameServiceAddresses::ReleaseGlobalByteStringPoolLock
  }
}

// Releases the pooled diagnostic at inherited EBP-124 before the constructing receiver cleanup.
// R6GameService.dll @ 10064963 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleasePooledStringErrorMessage(void)
{
  __asm {
    lea    ecx,[ebp-0x124]
    jmp    R6GameServiceAddresses::ReleasePooledBuffer
  }
}

// Selects the three-state pooled constructor metadata for the inherited frame.
// R6GameService.dll @ 1006496e : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PooledByteStringConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructPooledByteStringExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Forwards inherited EBP-5 to the fixed global lock clear during a pool refill failure.
// R6GameService.dll @ 10064a00 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnlockSmallByteStringAllocation(void)
{
  __asm {
    lea    ecx,[ebp-0x5]
    jmp    R6GameServiceAddresses::ReleaseGlobalByteStringPoolLock
  }
}

// Selects the small allocator one-state lock-release metadata for the inherited frame.
// R6GameService.dll @ 10064a08 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SmallByteStringAllocateExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateSmallByteStringBlockExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007eca8 : native pool constructor/lock lifetime record.
const R6GameServiceNative::UnwindEntry ConstructPooledByteStringUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyPooledStringConstruction},
  {0x0, R6GameServiceAddresses::UnlockPooledStringConstruction},
  {0x0, R6GameServiceAddresses::ReleasePooledStringErrorMessage},
};

// R6GameService.dll data @ 1007ecc0 : native pool constructor/lock lifetime record.
const R6GameServiceNative::FuncInfo ConstructPooledByteStringExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ConstructPooledByteStringUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007edc8 : native pool constructor/lock lifetime record.
const R6GameServiceNative::UnwindEntry AllocateSmallByteStringBlockUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnlockSmallByteStringAllocation},
};

// R6GameService.dll data @ 1007edd0 : native pool constructor/lock lifetime record.
const R6GameServiceNative::FuncInfo AllocateSmallByteStringBlockExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::AllocateSmallByteStringBlockUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Acquires the supplied lock with adaptive arithmetic spinning and cached Sleep backoff; returns EAX0.
// Lock argument becomes spin-work scratch, exchange target reloads each call, and signed backoff stages wrap.
// R6GameService.dll @ 10017550 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl AcquireBufferPoolLock(uint *lockWord)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    je     Branch71
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount
    mov    eax,ds:0x10093bb4
    xor    esi,esi
    mov    DWORD PTR [esp+0x14],0x11
    test   edi,edi
    jbe    Branch74
    mov    ebx,eax
    shr    ebx,1
  Branch70:
    cmp    esi,ebx
    jb     Branch72
    cmp    DWORD PTR [ebp+0x0],0x0
    jne    Branch72
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    jne    Branch73
    mov    DWORD PTR ds:0x10093bb4,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x3e8
  Branch71:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret
  Branch72:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x14]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x14],eax
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x14]
    imul   edx,eax
    mov    DWORD PTR [esp+0x14],edx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esp+0x14]
    imul   ecx,edx
    mov    DWORD PTR [esp+0x14],ecx
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x14]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x14],eax
  Branch73:
    inc    esi
    cmp    esi,edi
    jb     Branch70
  Branch74:
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x1e
    mov    edi,0x6
  Branch75:
    cmp    edi,0x1b
    mov    esi,edi
    jle    Branch76
    mov    esi,0x1b
  Branch76:
    push   0x1
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    test   eax,eax
    je     Branch71
    cmp    esi,0x14
    jg     Branch77
    push   0x0
    call   ebx
    inc    edi
    jmp    Branch75
  Branch77:
    lea    ecx,[esi-0x14]
    mov    edx,0x1
    shl    edx,cl
    push   edx
    call   ebx
    inc    edi
    jmp    Branch75
  }
}

// Acquires the global lock, links the late block into its cached class head and then clears the lock.
// Size becomes spin scratch; saved ECX becomes head-slot address. API targets and publication order stay native.
// R6GameService.dll @ 10027b90 : native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ReturnSmallByteStringBlock(void *block,uint size)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    push   ebx
    dec    eax
    push   ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    push   esi
    shr    eax,0x3
    push   edi
    push   0x1
    lea    ecx,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    push   R6GameServiceAddresses::GByteStringPoolLock
    mov    DWORD PTR [esp+0x18],ecx
    call   ebp
    test   eax,eax
    je     Branch79
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount
    mov    eax,ds:0x10093bb4
    xor    esi,esi
    mov    DWORD PTR [esp+0x1c],0x11
    test   edi,edi
    jbe    Branch82
    mov    ebx,eax
    shr    ebx,1
  Branch78:
    cmp    esi,ebx
    jb     Branch80
    mov    eax,ds:R6GameServiceAddresses::GByteStringPoolLock
    test   eax,eax
    jne    Branch80
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    jne    Branch81
    mov    DWORD PTR ds:0x10093bb4,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x3e8
  Branch79:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    mov    edx,DWORD PTR [ecx]
    pop    ebp
    mov    DWORD PTR [eax],edx
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR ds:R6GameServiceAddresses::GByteStringPoolLock,0x0
    pop    ebx
    pop    ecx
    ret
  Branch80:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x1c]
    imul   edx,eax
    mov    DWORD PTR [esp+0x1c],edx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x1c]
    imul   ecx,edx
    mov    DWORD PTR [esp+0x1c],ecx
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x1c]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x1c],eax
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x1c]
    imul   edx,eax
    mov    DWORD PTR [esp+0x1c],edx
  Branch81:
    inc    esi
    cmp    esi,edi
    jb     Branch78
  Branch82:
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x1e
    mov    edi,0x6
  Branch83:
    cmp    edi,0x1b
    mov    esi,edi
    jle    Branch84
    mov    esi,0x1b
  Branch84:
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    je     Branch79
    cmp    esi,0x14
    jg     Branch85
    push   0x0
    call   ebx
    inc    edi
    jmp    Branch83
  Branch85:
    lea    ecx,[esi-0x14]
    mov    edx,0x1
    shl    edx,cl
    push   edx
    call   ebx
    inc    edi
    jmp    Branch83
  }
}

// Acquires the global lock with cached exchange/Sleep targets and adaptive spin/backoff, returning the saved context.
// Contended exits reload the saved local; no local guard restores lock or partial publications on interruption.
// R6GameService.dll @ 10027ce0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall AcquireBufferPoolLockWithBackoff(uint context)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    push   esi
    push   edi
    mov    esi,ecx
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    mov    DWORD PTR [esp+0x1c],esi
    call   ebp
    test   eax,eax
    je     Branch94
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount
    mov    eax,ds:0x10093bb4
    xor    esi,esi
    mov    DWORD PTR [esp+0x10],0x11
    test   edi,edi
    jbe    Branch90
    mov    ebx,eax
    shr    ebx,1
  Branch86:
    cmp    esi,ebx
    jb     Branch88
    mov    eax,ds:R6GameServiceAddresses::GByteStringPoolLock
    test   eax,eax
    jne    Branch88
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    jne    Branch89
    mov    DWORD PTR ds:0x10093bb4,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x3e8
  Branch87:
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret
  Branch88:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x10]
    imul   edx,eax
    mov    DWORD PTR [esp+0x10],edx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x10]
    imul   ecx,edx
    mov    DWORD PTR [esp+0x10],ecx
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    imul   eax,ecx
    mov    DWORD PTR [esp+0x10],eax
  Branch89:
    inc    esi
    cmp    esi,edi
    jb     Branch86
  Branch90:
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GPooledByteStringBucketCount,0x1e
    mov    edi,0x6
  Branch91:
    cmp    edi,0x1b
    mov    esi,edi
    jle    Branch92
    mov    esi,0x1b
  Branch92:
    push   0x1
    push   R6GameServiceAddresses::GByteStringPoolLock
    call   ebp
    test   eax,eax
    je     Branch87
    cmp    esi,0x14
    jg     Branch93
    push   0x0
    call   ebx
    inc    edi
    jmp    Branch91
  Branch93:
    lea    ecx,[esi-0x14]
    mov    edx,0x1
    shl    edx,cl
    push   edx
    call   ebx
    inc    edi
    jmp    Branch91
  Branch94:
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret
  }
}

// Returns zero for NULL block, otherwise frees above128 bytes or returns the block through the shared pool helper.
// R6GameService.dll @ 10027460 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReturnBlockToPoolOrAllocator(void *block,uint bytes)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je     Branch96
    mov    ecx,DWORD PTR [esp+0x8]
    cmp    ecx,0x80
    jbe    Branch95
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    ret    0x8
  Branch95:
    push   ecx
    push   eax
    call   R6GameServiceAddresses::ReturnSmallByteStringBlock
    add    esp,0x8
  Branch96:
    ret    0x8
  }
}

// Releases the triplet at owner+c through heap or class head, leaving descriptor words dangling.
// Buffer/extent cache before locking; one-state cleanup only forwards current saved triplet capacity context.
// R6GameService.dll @ 10025f90 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReturnCachedAllocation(int descriptor)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::PoolDescriptorReleaseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    lea    eax,[ecx+0xc]
    push   esi
    mov    DWORD PTR [esp+0x4],eax
    mov    esi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x8]
    sub    eax,esi
    mov    DWORD PTR [esp+0x10],0x0
    test   esi,esi
    je     Branch98
    cmp    eax,0x80
    jbe    Branch97
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    pop    esi
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  Branch97:
    dec    eax
    push   edi
    shr    eax,0x3
    mov    ecx,R6GameServiceAddresses::GByteStringPoolLock
    lea    edi,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    call   R6GameServiceAddresses::pooled_string_support_AcquireBufferPoolLock
    mov    eax,DWORD PTR [edi]
    mov    ecx,R6GameServiceAddresses::GByteStringPoolLock
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [edi],esi
    call   R6GameServiceAddresses::ReleaseBufferPoolLock
    pop    edi
  Branch98:
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Releases the triplet at owner+10 with separate saved lock context and the global release helper.
// Native cached buffer/head, late cleanup receiver, raw return and lack of lock cleanup remain explicit.
// R6GameService.dll @ 10026020 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReturnEmbeddedBuffer(int descriptor)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::PoolDescriptorReleaseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    lea    eax,[ecx+0x10]
    push   esi
    mov    DWORD PTR [esp+0x8],eax
    mov    esi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x8]
    sub    eax,esi
    mov    DWORD PTR [esp+0x14],0x0
    test   esi,esi
    je     Branch100
    cmp    eax,0x80
    jbe    Branch99
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    pop    esi
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  Branch99:
    dec    eax
    push   edi
    shr    eax,0x3
    lea    ecx,[esp+0x8]
    lea    edi,[eax*4+R6GameServiceAddresses::GByteStringPoolFreeLists]
    call   R6GameServiceAddresses::AcquireBufferPoolLockWithBackoff
    mov    eax,DWORD PTR [edi]
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [edi],esi
    call   R6GameServiceAddresses::ReleaseGlobalByteStringPoolLock
    pop    edi
  Branch100:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Releases owner+10 buffer, reloads low deletion flag afterward, optionally frees owner and returns cached owner.
// R6GameService.dll @ 10027cc0 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteEmbeddedBufferDescriptor(void *owner,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ReturnEmbeddedBuffer
    test   BYTE PTR [esp+0x8],0x1
    je     Branch101
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch101:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Frees above128 bytes or tail-forwards original stack words to shared small-block return without a NULL check.
// R6GameService.dll @ 10028760 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ReleaseByteAllocation(void *block,uint bytes)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    cmp    eax,0x80
    jbe    Branch102
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    ret
  Branch102:
    mov    DWORD PTR [esp+0x8],eax
    jmp    R6GameServiceAddresses::ReturnSmallByteStringBlock
  }
}

// Forwards CURRENT saved triplet+8 to empty allocator cleanup, retaining EAX and leaving the pool lock unchanged.
// R6GameService.dll @ 10065500 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CleanupPoolDescriptorCapacityContext(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the shared one-state descriptor-release lifetime map for both parent offsets.
// R6GameService.dll @ 1006550b : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PoolDescriptorReleaseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::pooled_string_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007f658 : shared descriptor-release lifetime.
const R6GameServiceNative::UnwindEntry pooled_string_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::CleanupPoolDescriptorCapacityContext},
};

// R6GameService.dll data @ 1007f660 : shared descriptor-release lifetime.
// R6GameService.dll data @ 1007f658 : native storage identity retained.
const R6GameServiceNative::FuncInfo pooled_string_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::pooled_string_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
