#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10081044 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo HashModuleMD5ConstructExceptionHandlerFunctionInfo;

// Identified native class: HashModule_MD5, COL100796a4/type1008fcc4, primary table10077a08.
// Byte+8 marks a finalized cache, word+0x0c is the factory selector, cache begins+0x10 and owned context is+0x20.
size_t __cdecl fread(void *buffer,size_t elementSize,size_t elementCount,void *stream);
extern const char GHashModuleHexFormat[];

struct HashModuleMD5ConstructFrame {
  uint *savedOwner; // EBP-0x14.
  uint unusedConstructionWord; // EBP-0x10, initialized to0 and unused by the selected unwind map.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Constructs a wrapper with a 16-byte MD5 cache; failed context allocation leaves a null slot and returns owner.
// R6GameService.dll @ 10039730 : ECX owner, one mutable virtual-base argument, RET4; EAX=owner.
void * __thiscall ConstructHashModuleMD5(void *owner,uint initializeBaseWord)
{
  HashModuleMD5ConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashModuleMD5ConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  frame.unusedConstructionWord = 0;
  if (initializeBaseWord != 0) {
    *(uint *)((uint)owner + 4) = 0x10077a2c;
  }
  *(uint *)((uint)owner + 0x0c) = 0;
  frame.state = 0;
  *(uint *)owner = R6GameServiceAddresses::HashModule_MD5VTable;
  *(byte *)((uint)owner + 8) = 0;
  initializeBaseWord = (uint)AllocateGameServiceBytes(0x74);
  frame.state = (frame.state & 0xffffff00) | 1;
  void *context = 0;
  if (initializeBaseWord != 0) context = ConstructMd5Context((void *)initializeBaseWord,1);
  *(void **)((uint)owner + 0x20) = context;
  uint *cache = (uint *)((uint)owner + 0x10);
  for (uint index = 0; index < 4; ++index) cache[index] = 0;
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Destroys the MD5 wrapper and optionally frees its storage, returning the original receiver.
// R6GameService.dll @ 100397e0 : ECX owner, flags stack word, RET4; primary-table deleting slot0.
void * __thiscall DeleteHashModuleMD5(void *owner,byte flags)
{
  DestroyHashModuleMD5((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Deletes the child and clears the digest cache; retains the child pointer, validity byte and selector word.
// R6GameService.dll @ 10039800 : ECX owner, plain RET; EAX=old FS chain if null child, otherwise delete residue.
uint __fastcall DestroyHashModuleMD5(uint *owner)
{
  HashModuleDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashModuleDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::HashModule_MD5VTable;
  void *context = (void *)owner[8];
  frame.state = 0;
  uint result = (uint)frame.previousExceptionList;
  if (context != 0) {
    void **table = *(void ***)context;
    result = ((uint (__thiscall *)(void *,uint))table[0])(context,1);
  }
  uint *cache = owner + 4;
  for (uint index = 0; index < 4; ++index) cache[index] = 0;
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Resets the owned MD5 context, clears the finalized byte and cache, and returns the native zero word.
// R6GameService.dll @ 10039860 : ECX owner, no stack words, plain RET; EAX=0.
uint __fastcall ResetHashModuleMD5(void *owner)
{
  ResetMd5Context(*(void **)((uint)owner + 0x20));
  *(byte *)((uint)owner + 8) = 0;
  uint *cache = (uint *)((uint)owner + 0x10);
  for (uint index = 0; index < 4; ++index) cache[index] = 0;
  return 0;
}

// Updates the owned context only while the cached digest is not finalized; preserves full native EAX residue.
// R6GameService.dll @ 10039890 : ECX owner, input/count stack words, RET8; only AL is forced on either branch.
__declspec(naked) uint __thiscall UpdateHashModuleMD5(void *owner,const byte *input,uint byteCount)
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
    mov    ecx,dword ptr [ecx+0x20]
    push   eax
    push   edx
    call   R6GameServiceAddresses::UpdateMD5
    mov    al,1
    ret    8
  }
}

// Reads 1024-byte stream blocks directly into the child context, ignoring the wrapper's finalized flag.
// R6GameService.dll @ 100398c0 : ECX owner, stream stack word, RET4; EAX=1 after terminal fread returns0.
uint __thiscall HashStreamIntoHashModuleMD5(void *owner,void *stream)
{
  byte block[0x400];
  void *cachedStream = stream;
  uint bytesRead = (uint)fread(block,1,0x400,cachedStream);
  while (bytesRead != 0) {
    UpdateMD5(*(void **)((uint)owner + 0x20),(const byte *)block,bytesRead);
    bytesRead = (uint)fread(block,1,0x400,cachedStream);
  }
  return 1;
}

// Finalizes into the cache once and marks it valid after the child call; subsequent calls clear only AL.
// R6GameService.dll @ 10039920 : ECX owner, no stack words, plain RET; raw helper high EAX bits retained.
__declspec(naked) uint __fastcall FinalizeHashModuleMD5(void *owner)
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
    mov    ecx,dword ptr [esi+0x20]
    lea    eax,[esi+0x10]
    push   eax
    call   R6GameServiceAddresses::FinalizeMD5
    mov    al,1
    mov    byte ptr [esi+8],al
    pop    esi
    ret
  }
}

// Copies the finalized 16-byte cache with the native forward store order, retaining overlap and EAX behavior.
// R6GameService.dll @ 10039950 : ECX owner, output stack word, RET4; blocked branch clears only AL.
__declspec(naked) uint __thiscall CopyHashModuleMD5Digest(void *owner,uint *output)
{
  __asm {
    mov    al,byte ptr [ecx+8]
    test   al,al
    jnz    copy_cache
    xor    al,al
    ret    4
  copy_cache:
    mov    eax,dword ptr [esp+4]
    add    ecx,0x10
    mov    edx,dword ptr [ecx]
    mov    dword ptr [eax],edx
    mov    edx,dword ptr [ecx+4]
    mov    dword ptr [eax+4],edx
    mov    edx,dword ptr [ecx+8]
    mov    dword ptr [eax+8],edx
    mov    ecx,dword ptr [ecx+0xc]
    mov    dword ptr [eax+0xc],ecx
    mov    al,1
    ret    4
  }
}

// Formats a valid cache as 32 lowercase hexadecimal digits via per-byte sprintf calls, including their terminators.
// R6GameService.dll @ 10039980 : ECX owner, output stack word, RET4; AL is forced after sprintf or a blocked branch.
__declspec(naked) uint __thiscall FormatHashModuleMD5Digest(void *owner,char *output)
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
    cmp    esi,0x10
    jl     format_next_byte
    pop    edi
    pop    esi
    mov    al,1
    pop    ebx
    ret    4
  }
}

// Returns the MD5 digest byte count, excluding any string terminator.
// R6GameService.dll @ 100397c0 : receiver unused, no stack words, plain RET; full EAX=16.
uint __fastcall GetHashModuleMD5DigestLength(void *unusedOwner)
{
  return 16;
}

// Returns the MD5 hexadecimal character count, excluding any string terminator.
// R6GameService.dll @ 100397d0 : receiver unused, no stack words, plain RET; full EAX=32.
uint __fastcall GetHashModuleMD5HexLength(void *unusedOwner)
{
  return 32;
}

// Restores the allocation base table during MD5 wrapper construction unwind.
// R6GameService.dll @ 10066a20 : inherited parent EBP, no stack words; tail-forwards saved receiver to base reset.
__declspec(naked) void __cdecl ResetHashModuleMD5BaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Releases raw child storage saved over the constructor's virtual-base argument.
// R6GameService.dll @ 10066a28 : inherited EBP+4 allocation, one-word allocator cleanup, plain RET.
__declspec(naked) void __cdecl ReleaseHashModuleMD5ContextAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the exact native child-allocation/base cleanup map for wrapper construction.
// R6GameService.dll @ 10066a32 : EAX selects native FuncInfo; inherited-frame tail jump to10033906.
__declspec(naked) void __cdecl HashModuleMD5ConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HashModuleMD5ConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: HashModule_MD5VTable
// R6GameService.dll data @ 10077a08 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct HashModule_MD5VTableRecord {
  R6GameServiceNative::Address DeleteHashModuleMD5; // +0x00
  R6GameServiceNative::Address ResetHashModuleMD5; // +0x04
  R6GameServiceNative::Address HashStreamIntoHashModuleMD5; // +0x08
  R6GameServiceNative::Address UpdateHashModuleMD5; // +0x0c
  R6GameServiceNative::Address FinalizeHashModuleMD5; // +0x10
  R6GameServiceNative::Address CopyHashModuleMD5Digest; // +0x14
  R6GameServiceNative::Address FormatHashModuleMD5Digest; // +0x18
  R6GameServiceNative::Address GetHashModuleMD5DigestLength; // +0x1c
  R6GameServiceNative::Address GetHashModuleMD5HexLength; // +0x20
};
const HashModule_MD5VTableRecord HashModule_MD5VTable = {
  R6GameServiceAddresses::DeleteHashModuleMD5,
  R6GameServiceAddresses::ResetHashModuleMD5,
  R6GameServiceAddresses::HashStreamIntoHashModuleMD5,
  R6GameServiceAddresses::UpdateHashModuleMD5,
  R6GameServiceAddresses::FinalizeHashModuleMD5,
  R6GameServiceAddresses::CopyHashModuleMD5Digest,
  R6GameServiceAddresses::FormatHashModuleMD5Digest,
  R6GameServiceAddresses::GetHashModuleMD5DigestLength,
  R6GameServiceAddresses::GetHashModuleMD5HexLength,
};
