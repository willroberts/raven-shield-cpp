#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080ff4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo HashModuleSHA1ConstructExceptionHandlerFunctionInfo;

// Identified native class: HashModule_SHA1, COL10079654/type1008fc9c, primary table100779d8.
// Byte+8 marks a finalized cache, word+0x0c is the factory selector, cache begins+0x10 and owned context is+0x24.
size_t __cdecl fread(void *buffer,size_t elementSize,size_t elementCount,void *stream);
// R6GameService.dll data @ 1008fcbc : native storage identity retained.
extern const char GHashModuleHexFormat[];

struct HashModuleSHA1ConstructFrame {
  uint constructionFlags; // EBP-0x14, bit0 records optional virtual-base setup.
  uint *savedOwner; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs a wrapper with a 20-byte SHA1 cache; failed context allocation leaves a null slot and returns owner.
// R6GameService.dll @ 10039470 : ECX owner, one mutable virtual-base argument, RET4; EAX=owner.
void * __thiscall ConstructHashModuleSHA1(void *owner,uint initializeBaseWord)
{
  HashModuleSHA1ConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashModuleSHA1ConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.constructionFlags = 0;
  frame.savedOwner = (uint *)owner;
  if (initializeBaseWord != 0) {
    *(uint *)((uint)owner + 4) = 0x100779fc;
    frame.constructionFlags = 1;
  }
  *(uint *)((uint)owner + 0x0c) = 1;
  frame.state = 1;
  *(uint *)owner = R6GameServiceAddresses::HashModule_SHA1VTable;
  *(byte *)((uint)owner + 8) = 0;
  initializeBaseWord = (uint)AllocateGameServiceBytes(0x64);
  frame.state = (frame.state & 0xffffff00) | 2;
  void *context = 0;
  if (initializeBaseWord != 0) context = ConstructSha1Context((void *)initializeBaseWord,1);
  *(void **)((uint)owner + 0x24) = context;
  uint *cache = (uint *)((uint)owner + 0x10);
  for (uint index = 0; index < 5; ++index) cache[index] = 0;
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Destroys the SHA1 wrapper and optionally frees its storage, returning the original receiver.
// R6GameService.dll @ 10039520 : ECX owner, flags stack word, RET4; primary-table deleting slot0.
void * __thiscall DeleteHashModuleSHA1(void *owner,byte flags)
{
  DestroyHashModuleSHA1((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Deletes the child and clears the digest cache; retains the child pointer, validity byte and selector word.
// R6GameService.dll @ 10039540 : ECX owner, plain RET; EAX=old FS chain if null child, otherwise delete residue.
uint __fastcall DestroyHashModuleSHA1(uint *owner)
{
  HashModuleDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashModuleDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::HashModule_SHA1VTable;
  void *context = (void *)owner[9];
  frame.state = 0;
  uint result = (uint)frame.previousExceptionList;
  if (context != 0) {
    void **table = *(void ***)context;
    result = ((uint (__thiscall *)(void *,uint))table[0])(context,1);
  }
  uint *cache = owner + 4;
  for (uint index = 0; index < 5; ++index) cache[index] = 0;
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Resets the owned SHA1 context, clears the finalized byte and cache, and returns the native zero word.
// R6GameService.dll @ 100395b0 : ECX owner, no stack words, plain RET; EAX=0.
uint __fastcall ResetHashModuleSHA1(void *owner)
{
  InitializeSha1State(*(void **)((uint)owner + 0x24));
  *(byte *)((uint)owner + 8) = 0;
  uint *cache = (uint *)((uint)owner + 0x10);
  for (uint index = 0; index < 5; ++index) cache[index] = 0;
  return 0;
}

// Updates the owned context only while the cached digest is not finalized; preserves full native EAX residue.
// R6GameService.dll @ 100395e0 : ECX owner, input/count stack words, RET8; only AL is forced on either branch.
__declspec(naked) uint __thiscall UpdateHashModuleSHA1(void *owner,const byte *input,uint byteCount)
{
  __asm {
    mov    al,byte ptr [ecx+8]
    test   al,al
    jz     update_context
    xor    al,al
    ret    8
  update_context:
    mov    eax,dword ptr [esp+8]
    mov    edx,dword ptr [esp+4]
    mov    ecx,dword ptr [ecx+0x24]
    push   eax
    push   edx
    call   R6GameServiceAddresses::UpdateSha1Context
    mov    al,1
    ret    8
  }
}

// Reads 1024-byte stream blocks directly into the child context, ignoring the wrapper's finalized flag.
// R6GameService.dll @ 10039610 : ECX owner, stream stack word, RET4; EAX=1 after terminal fread returns0.
uint __thiscall HashStreamIntoHashModuleSHA1(void *owner,void *stream)
{
  byte block[0x400];
  void *cachedStream = stream;
  uint bytesRead = (uint)fread(block,1,0x400,cachedStream);
  while (bytesRead != 0) {
    UpdateSha1Context(*(void **)((uint)owner + 0x24),block,bytesRead);
    bytesRead = (uint)fread(block,1,0x400,cachedStream);
  }
  return 1;
}

// Finalizes into the cache once and marks it valid after the child call; subsequent calls clear only AL.
// R6GameService.dll @ 10039670 : ECX owner, no stack words, plain RET; raw helper high EAX bits retained.
__declspec(naked) uint __fastcall FinalizeHashModuleSHA1(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,byte ptr [esi+8]
    test   al,al
    jz     finalize_context
    xor    al,al
    pop    esi
    ret
  finalize_context:
    mov    ecx,dword ptr [esi+0x24]
    lea    eax,[esi+0x10]
    push   eax
    call   R6GameServiceAddresses::FinalizeSha1Context
    mov    al,1
    mov    byte ptr [esi+8],al
    pop    esi
    ret
  }
}

// Copies the finalized 20-byte cache with the native forward store order, retaining overlap and EAX behavior.
// R6GameService.dll @ 100396a0 : ECX owner, output stack word, RET4; blocked branch clears only AL.
__declspec(naked) uint __thiscall CopyHashModuleSHA1Digest(void *owner,uint *output)
{
  __asm {
    mov    al,byte ptr [ecx+8]
    test   al,al
    jnz    copy_cache
    xor    al,al
    ret    4
  copy_cache:
    push   esi
    push   edi
    mov    edi,dword ptr [esp+0xc]
    lea    esi,[ecx+0x10]
    mov    ecx,5
    mov    al,1
    rep movsd
    pop    edi
    pop    esi
    ret    4
  }
}

// Formats a valid cache as 40 lowercase hexadecimal digits via per-byte sprintf calls, including their terminators.
// R6GameService.dll @ 100396d0 : ECX owner, output stack word, RET4; AL is forced after sprintf or a blocked branch.
__declspec(naked) uint __thiscall FormatHashModuleSHA1Digest(void *owner,char *output)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    mov    al,byte ptr [ebx+8]
    test   al,al
    jnz    format_cache
    xor    al,al
    pop    ebx
    ret    4
  format_cache:
    push   esi
    push   edi
    mov    edi,dword ptr [esp+0x10]
    xor    esi,esi
  format_next_byte:
    xor    eax,eax
    mov    al,byte ptr [ebx+esi+0x10]
    push   eax
    push   offset GHashModuleHexFormat
    push   edi
    call   R6GameServiceAddresses::sprintf
    add    esp,0xc
    inc    esi
    add    edi,2
    cmp    esi,0x14
    jl     format_next_byte
    pop    edi
    pop    esi
    mov    al,1
    pop    ebx
    ret    4
  }
}

// Returns the SHA1 digest byte count, excluding any string terminator.
// R6GameService.dll @ 10039710 : receiver unused, no stack words, plain RET; full EAX=20.
uint __fastcall GetHashModuleSHA1DigestLength(void *unusedOwner)
{
  return 20;
}

// Returns the SHA1 hexadecimal character count, excluding any string terminator.
// R6GameService.dll @ 10039720 : receiver unused, no stack words, plain RET; full EAX=40.
uint __fastcall GetHashModuleSHA1HexLength(void *unusedOwner)
{
  return 40;
}

// For active virtual-base setup, forwards the wrapper end address to the empty context cleanup.
// R6GameService.dll @ 100669e0 : inherited EBP flags/owner; EAX=flags&1, optional ECX=owner+0x28.
__declspec(naked) void __cdecl CleanupHashModuleSHA1BaseContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    and    eax,1
    test   eax,eax
    jz     cleanup_done
    mov    ecx,dword ptr [ebp-0x10]
    add    ecx,0x28
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  cleanup_done:
    ret
  }
}

// Restores the allocation base table during SHA1 wrapper construction unwind.
// R6GameService.dll @ 100669fa : inherited parent EBP, no stack words; tail-forwards saved receiver to base reset.
__declspec(naked) void __cdecl ResetHashModuleSHA1BaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Releases raw child storage saved over the constructor's virtual-base argument.
// R6GameService.dll @ 10066a02 : inherited EBP+4 allocation, one-word allocator cleanup, plain RET.
__declspec(naked) void __cdecl ReleaseHashModuleSHA1ContextAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the exact native child-allocation/base cleanup map for wrapper construction.
// R6GameService.dll @ 10066a0c : EAX selects native FuncInfo; inherited-frame tail jump to10033906.
__declspec(naked) void __cdecl HashModuleSHA1ConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HashModuleSHA1ConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: HashModule_SHA1VTable
// R6GameService.dll data @ 100779d8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct HashModule_SHA1VTableRecord {
  R6GameServiceNative::Address DeleteHashModuleSHA1; // +0x00
  R6GameServiceNative::Address ResetHashModuleSHA1; // +0x04
  R6GameServiceNative::Address HashStreamIntoHashModuleSHA1; // +0x08
  R6GameServiceNative::Address UpdateHashModuleSHA1; // +0x0c
  R6GameServiceNative::Address FinalizeHashModuleSHA1; // +0x10
  R6GameServiceNative::Address CopyHashModuleSHA1Digest; // +0x14
  R6GameServiceNative::Address FormatHashModuleSHA1Digest; // +0x18
  R6GameServiceNative::Address GetHashModuleSHA1DigestLength; // +0x1c
  R6GameServiceNative::Address GetHashModuleSHA1HexLength; // +0x20
};
const HashModule_SHA1VTableRecord HashModule_SHA1VTable = {
  R6GameServiceAddresses::DeleteHashModuleSHA1,
  R6GameServiceAddresses::ResetHashModuleSHA1,
  R6GameServiceAddresses::HashStreamIntoHashModuleSHA1,
  R6GameServiceAddresses::UpdateHashModuleSHA1,
  R6GameServiceAddresses::FinalizeHashModuleSHA1,
  R6GameServiceAddresses::CopyHashModuleSHA1Digest,
  R6GameServiceAddresses::FormatHashModuleSHA1Digest,
  R6GameServiceAddresses::GetHashModuleSHA1DigestLength,
  R6GameServiceAddresses::GetHashModuleSHA1HexLength,
};
