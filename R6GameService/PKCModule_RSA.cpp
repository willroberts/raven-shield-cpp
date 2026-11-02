#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100810fc : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PKCRSAConstructExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10081120 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PKCRSADestroyExceptionHandlerFunctionInfo;

// Identified native class: PKCModule_RSA, COL10079774/type1008fd3c, primary table10077a58.
struct PKCRSAConstructFrame {
  uint constructionFlags; // EBP-0x14, bit0 records optional virtual-base setup.
  uint *savedOwner; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

struct PKCRSADestroyFrame {
  uint *savedOwner; // EBP-0x10, followed by chain/handler/state at-0x0c/-8/-4.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs the wrapper and its twelve-byte RSA child; null child allocation still returns the wrapper.
// R6GameService.dll @ 10039e20 : ECX owner, mutable virtual-base argument, RET4; EAX=owner.
void * __thiscall ConstructPKCModuleRSA(void *owner,uint initializeBaseWord)
{
  PKCRSAConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PKCRSAConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.constructionFlags = 0;
  frame.savedOwner = (uint *)owner;
  if (initializeBaseWord != 0) {
    *(uint *)((uint)owner + 4) = 0x10077a80;
    frame.constructionFlags = 1;
  }
  *(uint *)((uint)owner + 8) = 0;
  frame.state = 1;
  *(uint *)owner = R6GameServiceAddresses::PKCModule_RSAVTable;
  initializeBaseWord = (uint)AllocateGameServiceBytes(0x0c);
  frame.state = (frame.state & 0xffffff00) | 2;
  void *child = 0;
  if (initializeBaseWord != 0) child = ConstructRSA((void *)initializeBaseWord,1);
  void *previous = frame.previousExceptionList;
  *(void **)((uint)owner + 0x0c) = child;
  ExceptionList = previous;
  return owner;
}

// Deletes the RSA wrapper and optionally frees storage for flags bit0, returning the original receiver.
// R6GameService.dll @ 10039eb0 : ECX owner, flags stack word, RET4; primary table10077a58 slot0.
void * __thiscall DeletePKCModuleRSA(void *owner,byte flags)
{
  DestroyPKCModuleRSA((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Deletes the child when present, clears its slot and restores the allocation base table.
// R6GameService.dll @ 10039ed0 : ECX owner, plain RET; EAX=old FS chain for null child, otherwise delete residue.
uint __fastcall DestroyPKCModuleRSA(uint *owner)
{
  PKCRSADestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PKCRSADestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::PKCModule_RSAVTable;
  void *child = (void *)owner[3];
  frame.state = 0;
  uint result = (uint)frame.previousExceptionList;
  if (child != 0) {
    void **table = *(void ***)child;
    result = ((uint (__thiscall *)(void *,uint))table[0])(child,1);
  }
  void *previous = frame.previousExceptionList;
  owner[3] = 0;
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = previous;
  return result;
}

// Tail-forwards random-state initialization through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f30 : ECX wrapper, 1 stack words retained; target1003daa0 consumes0x4 bytes.
__declspec(naked) uint __thiscall InitializePKCRSARandomState(void *owner,uint *state)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::InitializeRSARandomState
  }
}

// Tail-forwards seed update through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f40 : ECX wrapper, 3 stack words retained; target1003dc60 consumes0xc bytes.
__declspec(naked) uint __thiscall UpdatePKCRSARandomSeed(
    void *owner,uint *state,const byte *seed,uint byteCount)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::UpdateCryptoRandomSeed
  }
}

// Tail-forwards random-state clearing through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f50 : ECX wrapper, 1 stack words retained; target1003dad0 consumes0x4 bytes.
__declspec(naked) uint __thiscall ClearPKCRSARandomState(void *owner,uint *state)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::ClearRSARandomState
  }
}

// Tail-forwards seed-byte requirement query through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f60 : ECX wrapper, 2 stack words retained; target1003dc40 consumes0x8 bytes.
__declspec(naked) uint __thiscall ReadPKCRSASeedBytesNeeded(void *owner,uint *bytesNeeded,const uint *state)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::ReadRSASeedBytesNeeded
  }
}

// Tail-forwards key-record generation through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f70 : ECX wrapper, 4 stack words retained; target1003ceb0 consumes0x10 bytes.
__declspec(naked) uint __thiscall GeneratePKCRSAKeyRecords(
    void *owner,uint *publicRecord,uint *privateRecord,const uint *prototype,uint *state)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::BuildCryptoKeyRecords
  }
}

// Tail-forwards type2 block encoding through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f80 : ECX wrapper, 6 stack words retained; target1003d260 consumes0x18 bytes.
__declspec(naked) uint __thiscall EncodePKCRSAType2Block(
    void *owner,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key,uint *state)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::EncodeType2CryptoBlock
  }
}

// Tail-forwards type1 block encoding through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039f90 : ECX wrapper, 5 stack words retained; target1003d360 consumes0x14 bytes.
__declspec(naked) uint __thiscall EncodePKCRSAType1Block(
    void *owner,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::EncodeType1CryptoBlock
  }
}

// Tail-forwards type1 block decoding through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039fa0 : ECX wrapper, 5 stack words retained; target1003d450 consumes0x14 bytes.
__declspec(naked) uint __thiscall DecodePKCRSAType1Block(
    void *owner,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::DecodeType1CryptoBlock
  }
}

// Tail-forwards type2 block decoding through the owned RSA receiver without guarding a null child.
// R6GameService.dll @ 10039fb0 : ECX wrapper, 5 stack words retained; target1003d530 consumes0x14 bytes.
__declspec(naked) uint __thiscall DecodePKCRSAType2Block(
    void *owner,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key)
{
  __asm {
    mov    ecx,dword ptr [ecx+0xc]
    jmp    R6GameServiceAddresses::DecodeType2CryptoBlock
  }
}

// For an active virtual-base flag, forwards the wrapper end address to the empty cleanup helper.
// R6GameService.dll @ 10066ac0 : inherited EBP flags-0x14/owner-0x10; EAX=flags&1, optional ECX=owner+0x10.
__declspec(naked) void __cdecl CleanupPKCRSABaseContext(void)
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

// Restores the allocation base table during construction unwind.
// R6GameService.dll @ 10066ada : inherited EBP-0x10 receiver, JMP10037840.
__declspec(naked) void __cdecl ResetPKCRSAConstructBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Releases raw child storage saved over the constructor's original virtual-base word.
// R6GameService.dll @ 10066ae2 : inherited EBP+4 allocation word, one-word allocator cleanup.
__declspec(naked) void __cdecl ReleasePKCRSAChildAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the constructor's three-state virtual-base/raw-child-allocation cleanup map.
// R6GameService.dll @ 10066aec : EAX=100810fc, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PKCRSAConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PKCRSAConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Restores the allocation base table when child destruction throws.
// R6GameService.dll @ 10066b00 : inherited EBP-0x10 receiver, JMP10037840.
__declspec(naked) void __cdecl ResetPKCRSADestroyBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the destructor's one-state allocation-base reset map.
// R6GameService.dll @ 10066b08 : EAX=10081120, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PKCRSADestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PKCRSADestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: PKCModule_RSAVTable
// R6GameService.dll data @ 10077a58 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct PKCModule_RSAVTableRecord {
  R6GameServiceNative::Address DeletePKCModuleRSA; // +0x00
  R6GameServiceNative::Address GeneratePKCRSAKeyRecords; // +0x04
  R6GameServiceNative::Address EncodePKCRSAType2Block; // +0x08
  R6GameServiceNative::Address EncodePKCRSAType1Block; // +0x0c
  R6GameServiceNative::Address DecodePKCRSAType1Block; // +0x10
  R6GameServiceNative::Address DecodePKCRSAType2Block; // +0x14
  R6GameServiceNative::Address InitializePKCRSARandomState; // +0x18
  R6GameServiceNative::Address UpdatePKCRSARandomSeed; // +0x1c
  R6GameServiceNative::Address ClearPKCRSARandomState; // +0x20
  R6GameServiceNative::Address ReadPKCRSASeedBytesNeeded; // +0x24
};
const PKCModule_RSAVTableRecord PKCModule_RSAVTable = {
  R6GameServiceAddresses::DeletePKCModuleRSA,
  R6GameServiceAddresses::GeneratePKCRSAKeyRecords,
  R6GameServiceAddresses::EncodePKCRSAType2Block,
  R6GameServiceAddresses::EncodePKCRSAType1Block,
  R6GameServiceAddresses::DecodePKCRSAType1Block,
  R6GameServiceAddresses::DecodePKCRSAType2Block,
  R6GameServiceAddresses::InitializePKCRSARandomState,
  R6GameServiceAddresses::UpdatePKCRSARandomSeed,
  R6GameServiceAddresses::ClearPKCRSARandomState,
  R6GameServiceAddresses::ReadPKCRSASeedBytesNeeded,
};
