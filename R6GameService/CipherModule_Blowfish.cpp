#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080d24 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CipherModuleBlowfishConstructExceptionHandlerFunctionInfo;

// Identified native class: CipherModule_Blowfish, COL10079304/type1008e7bc, primary table100778f8.
struct CipherModuleBlowfishConstructFrame {
  uint constructionFlags; // EBP-0x14, bit0 marks optional virtual-base setup.
  void *savedOwner; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the Blowfish module and conditionally releases its storage, returning the original receiver.
// R6GameService.dll @ 100374e0 : ECX receiver, flags stack word, RET4; primary table100778f8 slot0.
void * __thiscall DeleteCipherModuleBlowfish(void *owner,byte flags)
{
  DestroyCipherModuleBlowfish((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Constructs the module's owned Blowfish state and expands the supplied key without checking state allocation failure.
// R6GameService.dll @ 10037500 : ECX receiver, key/length/virtual-base words, RET0x0c; EAX=receiver.
void * __thiscall ConstructCipherModuleBlowfish(
    void *owner,uint keyAddress,uint keyByteCount,uint initializeBaseWord)
{
  CipherModuleBlowfishConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CipherModuleBlowfishConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.constructionFlags = 0;
  frame.savedOwner = owner;
  if (initializeBaseWord != 0) {
    *(uint *)((uint)owner + 4) = 0x1007790c;
    frame.constructionFlags = 1;
  }
  *(uint *)((uint)owner + 8) = 0;
  frame.state = 1;
  *(uint *)owner = R6GameServiceAddresses::CipherModule_BlowfishVTable;
  initializeBaseWord = (uint)AllocateGameServiceBytes(0x2098);
  frame.state = (frame.state & 0xffffff00) | 2;
  void *state = 0;
  if (initializeBaseWord != 0) state = ConstructCBlowFish((void *)initializeBaseWord,1);
  frame.state = (frame.state & 0xffffff00) | 1;
  *(void **)((uint)owner + 0x0c) = state;
  ExpandBlowfishKey(state,keyAddress,keyByteCount);
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Deletes the owned state, clears +0x0c and restores the base table; exception cleanup only resets the table.
// R6GameService.dll @ 100375b0 : ECX receiver, plain RET; EAX=old chain if no state, otherwise virtual-delete residue.
uint __fastcall DestroyCipherModuleBlowfish(uint *owner)
{
  CipherModuleDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CipherModuleDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::CipherModule_BlowfishVTable;
  void *state = (void *)owner[3];
  frame.state = 0;
  uint result = (uint)frame.previousExceptionList;
  if (state != 0) {
    void **table = *(void ***)state;
    result = ((uint (__thiscall *)(void *,uint))table[0])(state,1);
  }
  owner[3] = 0;
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// R6GameService.dll @ 10037610 : SetOwnedBlowfishKey
// Expands the key in the owned state at +0xc and sets only AL to indicate success. Table 100778f8 slot +4.
uint __thiscall SetOwnedBlowfishKey(void *this,uint keyAddress,uint keyByteCount)
{
  uint result = ExpandBlowfishKey(*(void **)((int)this + 0xc),keyAddress,keyByteCount);
  return (result & 0xffffff00) | 1;
}

// Tail-forwards the owned Blowfish state's working-table clear operation, preserving raw EAX.
// R6GameService.dll @ 10037630 : ECX receiver, no stack words; primary table100778f8 slot8.
__declspec(naked) uint __fastcall ClearOwnedBlowfishTables(void *owner)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::ClearBlowfishWorkingTables
  }
}

// R6GameService.dll @ 10037640 : EncodeBlowfishBuffer
// Encrypts zero-padded native-order word pairs and appends the original byte count as a little-endian word.
// Table 100778f8 slot +0xc; the operation name is inferred from the forward-round helper.
uint __thiscall EncodeBlowfishBuffer(void *this,const byte *source,uint sourceByteCount,
                                           byte *destination,uint *destinationByteCount)
{
  // No pointer validation precedes the oversized-input path's output write.
  if (sourceByteCount > 0xffff) {
    *destinationByteCount = 0;
    return (uint)destinationByteCount & 0xffffff00;
  }
  uint remainder = sourceByteCount & 7;
  if (remainder == 0) {
    remainder = 8;
  }
  uint blockByteCount = sourceByteCount - remainder + 8;
  uint requiredByteCount = blockByteCount + 2;
  if (destination == (byte *)0) {
    *destinationByteCount = requiredByteCount;
    return 0;
  }
  if (*destinationByteCount < requiredByteCount) {
    *destinationByteCount = requiredByteCount;
    return requiredByteCount & 0xffffff00;
  }

  // Allocation failure is unchecked. Copies retain REP MOVSD's four-byte groups followed by residual bytes.
  byte *temporary = (byte *)AllocateGameServiceBytes(blockByteCount);
  for (uint offset = 0; offset < (blockByteCount & ~3U); offset += 4) {
    *(uint *)(temporary + offset) = 0;
  }
  for (uint offset = blockByteCount & ~3U; offset < blockByteCount; ++offset) {
    temporary[offset] = 0;
  }
  for (uint offset = 0; offset < (sourceByteCount & ~3U); offset += 4) {
    *(uint *)(temporary + offset) = *(const uint *)(source + offset);
  }
  for (uint offset = sourceByteCount & ~3U; offset < sourceByteCount; ++offset) {
    temporary[offset] = source[offset];
  }
  if (blockByteCount != 0) {
    uint blockCount = ((blockByteCount - 1) >> 3) + 1;
    byte *block = temporary;
    do {
      // Reload the owned state on each native iteration.
      EncryptBlowfishWords(*(void **)((int)this + 0xc),(uint *)block,(uint *)(block + 4));
      block += 8;
    } while (--blockCount != 0);
  }
  *destinationByteCount = requiredByteCount;
  for (uint offset = 0; offset < (blockByteCount & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(uint *)(temporary + offset);
  }
  for (uint offset = blockByteCount & ~3U; offset < blockByteCount; ++offset) {
    destination[offset] = temporary[offset];
  }
  *(ushort *)(destination + blockByteCount) = (ushort)sourceByteCount;

  // Free is a native tail jump through GMalloc+8; preserve its unspecified EAX high bits before setting AL.
  uint allocatorResult = ((uint (__stdcall *)(void *))TailFreeThroughGlobalAllocator)(temporary);
  return (allocatorResult & 0xffffff00) | 1;
}

// R6GameService.dll @ 10037750 : DecodeBlowfishBuffer
// Decrypts native-order word pairs and copies the byte count taken from the unencrypted trailing word.
// Table 100778f8 slot +0x10; the operation name is inferred from the reverse-round helper.
uint __thiscall DecodeBlowfishBuffer(void *this,const byte *source,uint sourceByteCount,
                                           byte *destination,uint *destinationByteCount)
{
  // The trailer is read before output checks; short input and invalid trailers are not rejected.
  uint originalByteCount = *(const ushort *)((uint)source + sourceByteCount - 2);
  if (destination == (byte *)0 || *destinationByteCount < originalByteCount) {
    *destinationByteCount = originalByteCount;
    return originalByteCount & 0xff00;
  }
  uint remainder = (sourceByteCount - 2) & 7;
  if (remainder == 0) {
    remainder = 8;
  }
  uint blockByteCount = sourceByteCount - remainder + 6;
  byte *temporary = (byte *)AllocateGameServiceBytes(blockByteCount);
  for (uint offset = 0; offset < (blockByteCount & ~3U); offset += 4) {
    *(uint *)(temporary + offset) = 0;
  }
  for (uint offset = blockByteCount & ~3U; offset < blockByteCount; ++offset) {
    temporary[offset] = 0;
  }
  for (uint offset = 0; offset < (blockByteCount & ~3U); offset += 4) {
    *(uint *)(temporary + offset) = *(const uint *)(source + offset);
  }
  for (uint offset = blockByteCount & ~3U; offset < blockByteCount; ++offset) {
    temporary[offset] = source[offset];
  }
  if (blockByteCount != 0) {
    uint blockCount = ((blockByteCount - 1) >> 3) + 1;
    byte *block = temporary;
    do {
      DecryptBlowfishWords(*(void **)((int)this + 0xc),(uint *)block,(uint *)(block + 4));
      block += 8;
    } while (--blockCount != 0);
  }
  // The trailer may request more bytes than were allocated; the native copy performs no bound check here.
  *destinationByteCount = originalByteCount;
  for (uint offset = 0; offset < (originalByteCount & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(uint *)(temporary + offset);
  }
  for (uint offset = originalByteCount & ~3U; offset < originalByteCount; ++offset) {
    destination[offset] = temporary[offset];
  }
  uint allocatorResult = ((uint (__stdcall *)(void *))TailFreeThroughGlobalAllocator)(temporary);
  return (allocatorResult & 0xffffff00) | 1;
}

// For an active virtual-base construction flag, forwards the owner's end address to the empty cleanup helper.
// R6GameService.dll @ 10066760 : inherited EBP; EAX=flags&1, optional ECX=owner+0x10, JMP10059130.
__declspec(naked) void __cdecl CleanupCipherModuleBlowfishBaseContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    and    eax,1
    test   eax,eax
    jz     cleanup_done
    mov    ecx,dword ptr [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  cleanup_done:
    ret
  }
}

// Restores the module's allocation base table when construction unwinds through state1.
// R6GameService.dll @ 1006677a : inherited EBP-0x10 receiver, JMP10037840.
__declspec(naked) void __cdecl ResetCipherModuleBlowfishBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Releases raw Blowfish storage saved over the constructor's third argument if state initialization throws.
// R6GameService.dll @ 10066782 : inherited EBP+0x0c allocation word, one-word allocator cleanup.
__declspec(naked) void __cdecl ReleaseCipherModuleBlowfishStateAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0xc]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the three-state construction unwind map; state1 does not destroy a successfully constructed owned state.
// R6GameService.dll @ 1006678c : EAX=10080d24, inherited-frame JMP10033906.
__declspec(naked) void __cdecl CipherModuleBlowfishConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CipherModuleBlowfishConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: CipherModule_BlowfishVTable
// R6GameService.dll data @ 100778f8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CipherModule_BlowfishVTableRecord {
  R6GameServiceNative::Address DeleteCipherModuleBlowfish; // +0x00
  R6GameServiceNative::Address SetOwnedBlowfishKey; // +0x04
  R6GameServiceNative::Address ClearOwnedBlowfishTables; // +0x08
  R6GameServiceNative::Address EncodeBlowfishBuffer; // +0x0c
  R6GameServiceNative::Address DecodeBlowfishBuffer; // +0x10
};
const CipherModule_BlowfishVTableRecord CipherModule_BlowfishVTable = {
  R6GameServiceAddresses::DeleteCipherModuleBlowfish,
  R6GameServiceAddresses::SetOwnedBlowfishKey,
  R6GameServiceAddresses::ClearOwnedBlowfishTables,
  R6GameServiceAddresses::EncodeBlowfishBuffer,
  R6GameServiceAddresses::DecodeBlowfishBuffer,
};
