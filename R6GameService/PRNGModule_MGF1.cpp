#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100810a4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MGF1ConstructExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 100810c8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MGF1DestroyExceptionHandlerFunctionInfo;

// Identified native class: PRNGModule_MGF1, COL1007970c/type1008fd00, primary table10077a38.
// +0x0c child hash; +0x10 counter; +0x14/+0x18 seed/length; +0x1c/+0x20 output/capacity; +0x24/+0x28 cursor/remaining.
struct MGF1ConstructFrame {
  uint constructionFlags; // EBP-0x14, bit0 records optional virtual-base setup.
  uint *savedOwner; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

struct MGF1DestroyFrame {
  uint *savedOwner; // EBP-0x10, followed by chain/handler/state at-0x0c/-8/-4.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the MGF1 module and optionally frees storage for flags bit0, returning the original receiver.
// R6GameService.dll @ 100399c0 : ECX owner, flags stack word, RET4; primary table10077a38 slot0.
void * __thiscall DeletePRNGModuleMGF1(void *owner,byte flags)
{
  DestroyPRNGModuleMGF1((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Selects MD5/SHA1, allocates500 digests of output storage and copies the seed; other selectors retain child bits.
// R6GameService.dll @ 100399e0 : ECX owner, four stack words, RET0x10; EAX=owner, argument4 becomes raw child storage.
void * __thiscall ConstructPRNGModuleMGF1(
    void *owner,uint digestKind,const byte *seed,uint seedByteCount,uint initializeBaseWord)
{
  MGF1ConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)MGF1ConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.constructionFlags = 0;
  frame.savedOwner = (uint *)owner;
  if (initializeBaseWord != 0) {
    *(uint *)((uint)owner + 4) = 0x10077a4c;
    frame.constructionFlags = 1;
  }
  uint *words = (uint *)owner;
  words[2] = 0;
  uint selector = digestKind;
  frame.state = 1;
  for (uint index = 4; index <= 10; ++index) words[index] = 0;
  words[0] = R6GameServiceAddresses::PRNGModule_MGF1VTable;
  if (selector == 0 || selector == 1) {
    initializeBaseWord = (uint)AllocateGameServiceBytes(selector == 0 ? 0x24 : 0x28);
    frame.state = (frame.state & 0xffffff00) | (selector == 0 ? 2 : 3);
    void *child = 0;
    if (initializeBaseWord != 0) {
      if (selector == 0) child = ConstructHashModuleMD5((void *)initializeBaseWord,1);
      else child = ConstructHashModuleSHA1((void *)initializeBaseWord,1);
    }
    frame.state = (frame.state & 0xffffff00) | 1;
    words[3] = (uint)child;
  }
  // No child null/selector guard: unsupported selectors use the preexisting +0x0c word.
  void *child = (void *)words[3];
  void **table = *(void ***)child;
  uint digestLength = ((uint (__thiscall *)(void *))table[7])(child);
  uint outputByteCount = digestLength * 500U;
  words[8] = outputByteCount;
  uint output = (uint)AllocateGameServiceBytes(outputByteCount);
  words[7] = output;
  ReplaceMGF1Seed(owner,seed,seedByteCount);
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Deletes the child, output and seed in that order, clearing each nonnull slot only after its release returns.
// R6GameService.dll @ 10039ae0 : ECX owner, plain RET; EAX=0 for null final seed, otherwise seed-free residue.
uint __fastcall DestroyPRNGModuleMGF1(uint *owner)
{
  MGF1DestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)MGF1DestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::PRNGModule_MGF1VTable;
  void *child = (void *)owner[3];
  frame.state = 0;
  if (child != 0) {
    void **table = *(void ***)child;
    ((uint (__thiscall *)(void *,uint))table[0])(child,1);
    owner[3] = 0;
  }
  uint output = owner[7];
  if (output != 0) {
    TailFreeThroughGlobalAllocator((void *)output);
    owner[7] = 0;
  }
  uint result = owner[5];
  if (result != 0) {
    result = ((uint (__stdcall *)(void *))TailFreeThroughGlobalAllocator)((void *)result);
    owner[5] = 0;
  }
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Replaces the seed copy and clears remaining output; retains the counter and cursor and returns the copied byte count.
// R6GameService.dll @ 10039b60 : ECX owner, source/count stack words, RET8; EAX=count, allocation failure unchecked.
uint __thiscall ReplaceMGF1Seed(void *owner,const byte *source,uint byteCount)
{
  uint *words = (uint *)owner;
  uint previousSeed = words[5];
  if (previousSeed != 0) {
    TailFreeThroughGlobalAllocator((void *)previousSeed);
    words[5] = 0;
  }
  uint copyLength = byteCount;
  byte *destination = (byte *)AllocateGameServiceBytes(copyLength);
  const byte *input = source;
  words[5] = (uint)destination;
  for (uint offset = 0; offset < (copyLength & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(input + offset);
  }
  for (uint offset = copyLength & ~3U; offset < copyLength; ++offset) destination[offset] = input[offset];
  words[6] = copyLength;
  words[10] = 0;
  return copyLength;
}

// Reduces the next virtual byte to its parity bit using a zero high word; returns the helper's full EAX.
// R6GameService.dll @ 10039bb0 : ECX owner, no stack words, plain RET; primary table10077a38 slot4.
uint __fastcall NextMGF1ParityBit(uint *owner)
{
  void **table = *(void ***)owner;
  uint value = ((uint (__thiscall *)(void *))table[2])(owner);
  return ComputeUnsigned64Parity(value & 255,0);
}

// Refills when empty, decrements remaining before reading the cursor byte, then publishes the incremented cursor.
// R6GameService.dll @ 10039bd0 : ECX owner, plain RET; EAX=decremented count high24 bits plus the byte in AL.
uint __fastcall NextMGF1Byte(uint *owner)
{
  if (owner[10] == 0) RefillMGF1Output(owner);
  uint remaining = owner[10] - 1;
  uint nextCursor = owner[9] + 1;
  owner[10] = remaining;
  byte value = *(byte *)(nextCursor - 1);
  owner[9] = nextCursor;
  return (remaining & 0xffffff00) | value;
}

// Reads bytes through freshly reloaded virtual slot8 each iteration, retaining incoming EAX for a zero request.
// R6GameService.dll @ 10039c00 : ECX owner, destination/unsigned-count stack words, RET8; otherwise last byte-call EAX.
__declspec(naked) uint __thiscall ReadMGF1Bytes(void *owner,byte *destination,uint byteCount)
{
  __asm {
    push   ebx
    mov    ebx,dword ptr [esp+0xc]
    push   esi
    mov    esi,dword ptr [esp+0xc]
    push   edi
    mov    edi,ecx
    test   ebx,ebx
    jbe    read_done
  read_next_byte:
    mov    eax,dword ptr [edi]
    mov    ecx,edi
    call   dword ptr [eax+8]
    mov    byte ptr [esi],al
    inc    esi
    dec    ebx
    jnz    read_next_byte
  read_done:
    pop    edi
    pop    esi
    pop    ebx
    ret    8
  }
}

// Samples an inclusive unsigned interval by masked bytes and rejection; subtraction and addition wrap at64 bits.
// Locals at entryESP-0x0c/-8/-4 are mask bits and uninitialized candidate words; upper-low argument becomes byte count.
// R6GameService.dll @ 10039c30 : ECX owner, upper-low/high and lower-low/high words, RET0x10; EDX:EAX=result.
__declspec(naked) ulonglong __thiscall SelectMGF1ValueInRange(
    void *owner,uint upperLowWord,uint upperHighWord,uint lowerLowWord,uint lowerHighWord)
{
  __asm {
    mov    eax,dword ptr [esp+0x4]
    sub    esp,0xc
    mov    edx,dword ptr [esp+0x14]
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,dword ptr [esp+0x20]
    cmp    eax,ecx
    jne    different_bounds
    cmp    edx,dword ptr [esp+0x24]
    je     range_done
  different_bounds:
    mov    esi,dword ptr [esp+0x24]
    sub    eax,ecx
    sbb    edx,esi
    push   ebx
    mov    esi,edx
    push   ebp
    mov    ebx,eax
    push   esi
    push   ebx
    call   R6GameServiceAddresses::CountUnsigned64Bytes
    push   esi
    push   ebx
    mov    dword ptr [esp+0x28],eax
    call   R6GameServiceAddresses::CountUnsigned64Bits
    mov    ecx,dword ptr [esp+0x20]
    mov    ebp,eax
    mov    eax,dword ptr [edi]
    lea    edx,[esp+0x14]
    push   ecx
    push   edx
    mov    ecx,edi
    mov    dword ptr [esp+0x18],ebp
    call   dword ptr [eax+0xc]
    mov    eax,dword ptr [esp+0x18]
    mov    ecx,dword ptr [esp+0x14]
    push   ebp
    push   eax
    push   ecx
    call   R6GameServiceAddresses::MaskUnsigned64WithNativeShift
    cmp    edx,esi
    mov    dword ptr [esp+0x14],eax
    mov    dword ptr [esp+0x18],edx
    jb     accept_candidate
    ja     reject_candidate
    cmp    eax,ebx
    jbe    accept_candidate
    jmp    reject_candidate
  reload_mask_bits:
    mov    ebp,dword ptr [esp+0x10]
  reject_candidate:
    mov    edx,dword ptr [edi]
    push   ebp
    mov    ecx,edi
    call   dword ptr [edx+0x8]
    mov    ecx,dword ptr [esp+0x18]
    mov    ebp,dword ptr [esp+0x1c]
    shld   ebp,ecx,0x8
    and    eax,0xff
    cdq
    shl    ecx,0x8
    or     edx,ebp
    or     eax,ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::MaskUnsigned64WithNativeShift
    cmp    edx,esi
    mov    dword ptr [esp+0x14],eax
    mov    dword ptr [esp+0x18],edx
    ja     reload_mask_bits
    jb     accept_candidate
    cmp    eax,ebx
    ja     reload_mask_bits
  accept_candidate:
    mov    esi,dword ptr [esp+0x28]
    mov    ecx,dword ptr [esp+0x2c]
    add    eax,esi
    pop    ebp
    adc    edx,ecx
    pop    ebx
  range_done:
    pop    edi
    pop    esi
    add    esp,0xc
    ret    0x10
  }
}

// Refills with hashes of seed||BE32(counter), resetting the child per digest and retaining native aliases.
// R6GameService.dll @ 10039d00 : ECX owner, no stack words, plain RET; EAX=output base reloaded after temporary frees.
uint __fastcall RefillMGF1Output(uint *owner)
{
  typedef uint (__thiscall *GetLength)(void *);
  typedef uint (__thiscall *Update)(void *,const byte *,uint);
  typedef uint (__thiscall *NoArguments)(void *);
  typedef uint (__thiscall *CopyDigest)(void *,byte *);
  void *child = (void *)owner[3];
  void **table = *(void ***)child;
  uint digestLength = ((GetLength)table[7])(child);
  uint outputBase = owner[7];
  owner[9] = outputBase;
  byte *counterBytes = (byte *)AllocateGameServiceBytes(4);
  byte *digestBytes = (byte *)AllocateGameServiceBytes(digestLength);
  uint scratchCapacity = owner[6] + 4;
  byte *inputWithCounter = (byte *)AllocateGameServiceBytes(scratchCapacity);
  uint copyLength = owner[6];
  if (copyLength != 0) {
    const byte *seed = (const byte *)owner[5];
    for (uint offset = 0; offset < (copyLength & ~3U); offset += 4) {
      *(uint *)(inputWithCounter + offset) = *(const uint *)(seed + offset);
    }
    for (uint offset = copyLength & ~3U; offset < copyLength; ++offset) inputWithCounter[offset] = seed[offset];
  }
  uint capacity = owner[8];
  uint base = owner[7];
  uint cursor = owner[9];
  uint end = capacity + base;
  if (cursor < end) {
    do {
      uint counter = owner[4];
      owner[4] = counter + 1;
      WriteUnsigned64BigEndian(counter,0,(undefined4 *)counterBytes,4);
      uint counterOffset = owner[6];
      *(uint *)(inputWithCounter + counterOffset) = *(uint *)counterBytes;
      uint updateLength = owner[6];
      child = (void *)owner[3];
      updateLength += 4;
      table = *(void ***)child;
      ((Update)table[3])(child,inputWithCounter,updateLength);
      child = (void *)owner[3];
      table = *(void ***)child;
      ((NoArguments)table[4])(child);
      child = (void *)owner[3];
      table = *(void ***)child;
      ((CopyDigest)table[5])(child,digestBytes);
      child = (void *)owner[3];
      table = *(void ***)child;
      ((NoArguments)table[1])(child);
      byte *destination = (byte *)owner[9];
      for (uint offset = 0; offset < (digestLength & ~3U); offset += 4) {
        *(uint *)(destination + offset) = *(uint *)(digestBytes + offset);
      }
      for (uint offset = digestLength & ~3U; offset < digestLength; ++offset) destination[offset] = digestBytes[offset];
      uint reloadedCursor = owner[9];
      capacity = owner[8];
      base = owner[7];
      cursor = reloadedCursor + digestLength;
      end = capacity + base;
      owner[9] = cursor;
    } while (cursor < end);
  }
  // Native free order is allocation order; exceptions leave remaining temporaries and published fields as they stand.
  TailFreeThroughGlobalAllocator(counterBytes);
  TailFreeThroughGlobalAllocator(digestBytes);
  TailFreeThroughGlobalAllocator(inputWithCounter);
  base = owner[7];
  capacity = owner[8];
  owner[9] = base;
  owner[10] = capacity;
  return base;
}

// For an active virtual-base flag, forwards the owner's end address to the empty context cleanup helper.
// R6GameService.dll @ 10066a60 : inherited EBP; flags at-0x14, owner at-0x10, optional ECX=owner+0x2c.
__declspec(naked) void __cdecl CleanupMGF1BaseContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    and    eax,1
    test   eax,eax
    jz     cleanup_done
    mov    ecx,dword ptr [ebp-0x10]
    add    ecx,0x2c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  cleanup_done:
    ret
  }
}

// Restores the owner's allocation base table during construction unwind.
// R6GameService.dll @ 10066a7a : inherited EBP-0x10 owner, JMP10037840.
__declspec(naked) void __cdecl ResetMGF1ConstructBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Releases raw SHA1 wrapper storage saved over the constructor's fourth argument when child construction throws.
// R6GameService.dll @ 10066a82 : inherited EBP+0x10 allocation word, one-word allocator cleanup.
__declspec(naked) void __cdecl ReleaseMGF1SHA1ChildAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases raw MD5 wrapper storage saved over the constructor's fourth argument when child construction throws.
// R6GameService.dll @ 10066a8c : inherited EBP+0x10 allocation word, one-word allocator cleanup.
__declspec(naked) void __cdecl ReleaseMGF1MD5ChildAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the four-state virtual-base/child-allocation construction unwind map.
// R6GameService.dll @ 10066a96 : EAX=100810a4, inherited-frame JMP10033906.
__declspec(naked) void __cdecl MGF1ConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MGF1ConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Restores the allocation base table if child or buffer release throws during destruction.
// R6GameService.dll @ 10066aa0 : inherited EBP-0x10 owner, JMP10037840.
__declspec(naked) void __cdecl ResetMGF1DestroyBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the destructor's one-state allocation-base reset map.
// R6GameService.dll @ 10066aa8 : EAX=100810c8, inherited-frame JMP10033906.
__declspec(naked) void __cdecl MGF1DestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MGF1DestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: PRNGModule_MGF1VTable
// R6GameService.dll data @ 10077a38 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct PRNGModule_MGF1VTableRecord {
  R6GameServiceNative::Address DeletePRNGModuleMGF1; // +0x00
  R6GameServiceNative::Address NextMGF1ParityBit; // +0x04
  R6GameServiceNative::Address NextMGF1Byte; // +0x08
  R6GameServiceNative::Address ReadMGF1Bytes; // +0x0c
  R6GameServiceNative::Address SelectMGF1ValueInRange; // +0x10
};
const PRNGModule_MGF1VTableRecord PRNGModule_MGF1VTable = {
  R6GameServiceAddresses::DeletePRNGModuleMGF1,
  R6GameServiceAddresses::NextMGF1ParityBit,
  R6GameServiceAddresses::NextMGF1Byte,
  R6GameServiceAddresses::ReadMGF1Bytes,
  R6GameServiceAddresses::SelectMGF1ValueInRange,
};
