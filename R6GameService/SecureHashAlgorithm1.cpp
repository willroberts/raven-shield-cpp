#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1008114c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo SecureHashAlgorithm1ConstructExceptionHandlerFunctionInfo;

// Identified native class: SecureHashAlgorithm1, COL100797c0/type1008fd58/table10077a8c.
// Allocation-base ancestry is RTTI-backed; no complete original class declaration is invented.

struct SecureHashAlgorithm1ConstructFrame {
  uint constructionFlags; // EntryESP-0x14, optional virtual-base setup bit.
  uint *savedOwner; // EntryESP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Installs the optional virtual-base table and primary table, then resets the native hash state.
// R6GameService.dll @ 10039fc0 : ECX owner, flag stack word, RET4; state1 spans table/reset.
void * __thiscall ConstructSha1Context(void *owner,uint initializeBase)
{
  SecureHashAlgorithm1ConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)SecureHashAlgorithm1ConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  uint baseFlag = initializeBase;
  frame.constructionFlags = 0;
  if (baseFlag != 0) {
    *(uint *)((uint)owner + 4) = 0x10077a90;
    frame.constructionFlags = 1;
  }
  frame.state = 1;
  *(uint *)owner = R6GameServiceAddresses::SecureHashAlgorithm1VTable;
  InitializeSha1State(owner);
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Destroys context storage, tests the original flags afterward and frees only for low bit1.
// R6GameService.dll @ 1003a030 : ECX owner, flags stack word, RET4; full EAX=original owner.
void * __thiscall DeleteSha1Context(void *owner,byte flags)
{
  DestroySha1ContextBase((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Clears the23 context words at+8..+63 and restores the allocation-base table, retaining+4.
// R6GameService.dll @ 1003a050 : ECX owner, plain RET; EAX0/ECX0/EDX owner, EDI preserved.
__declspec(naked) uint __fastcall DestroySha1ContextBase(uint *owner)
{
  __asm {
    mov    edx,ecx
    push   edi
    mov    ecx,0x17
    xor    eax,eax
    lea    edi,[edx+0x8]
    rep stos DWORD PTR es:[edi],eax
    mov    DWORD PTR [edx],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    edi
    ret
  }
}

// Clears context words then installs five SHA1 initial words and both zero bit counters.
// R6GameService.dll @ 1003a070 : ECX owner, plain RET; EAX0/ECX0/EDX owner, ESI/EDI preserved.
__declspec(naked) uint __fastcall InitializeSha1State(void *owner)
{
  __asm {
    mov    edx,ecx
    push   esi
    push   edi
    mov    ecx,0x17
    lea    esi,[edx+0x8]
    xor    eax,eax
    mov    edi,esi
    rep stos DWORD PTR es:[edi],eax
    mov    DWORD PTR [esi],0x67452301
    pop    edi
    mov    DWORD PTR [edx+0xc],0xefcdab89
    mov    DWORD PTR [edx+0x10],0x98badcfe
    mov    DWORD PTR [edx+0x14],0x10325476
    mov    DWORD PTR [edx+0x18],0xc3d2e1f0
    mov    DWORD PTR [edx+0x20],eax
    mov    DWORD PTR [edx+0x1c],eax
    pop    esi
    ret
  }
}

// For optional virtual-base setup, tail-forwards owner+64 to the genuine no-op destructor.
// R6GameService.dll @ 10066b20 : inherited EBP-14 flags/EBP-10 owner; no new frame.
__declspec(naked) void __cdecl CleanupSecureHashAlgorithm1VirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je securehashalgorithm1_virtual_base_done
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x64
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  securehashalgorithm1_virtual_base_done:
    ret
  }
}

// Tail-forwards the saved owner to allocation-base destruction during constructor unwind.
// R6GameService.dll @ 10066b3a : inherited EBP-10 owner, JMP10037840.
__declspec(naked) void __cdecl CleanupSecureHashAlgorithm1AllocationBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the two-state constructor unwind map for SecureHashAlgorithm1.
// R6GameService.dll @ 10066b42 : EAX=1008114c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl SecureHashAlgorithm1ConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SecureHashAlgorithm1ConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Buffers and byte-swaps SHA1 blocks, retaining argument mutation and saved-ECX block-counter reuse.
// R6GameService.dll @ 1003a0b0 : ECX owner, input/count words, RET8; EAX/ECX retain branch-specific residues.
__declspec(naked) uint __thiscall UpdateSha1Context(void *owner,const byte *input,uint byteCount)
{
  __asm {
    push   ecx
    push   ebx
    mov    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    push   ebp
    mov    eax,DWORD PTR [ebx+0x1c]
    push   esi
    push   edi
    lea    edx,[eax+ecx*8]
    cmp    edx,eax
    mov    DWORD PTR [ebx+0x1c],edx
    jae sha1_update_high_counter
    inc    DWORD PTR [ebx+0x20]
  sha1_update_high_counter:
    mov    edi,DWORD PTR [ebx+0x20]
    mov    edx,ecx
    shr    edx,0x1d
    shr    eax,0x3
    add    edi,edx
    and    eax,0x3f
    mov    DWORD PTR [ebx+0x20],edi
    je sha1_check_full_blocks
    mov    esi,DWORD PTR [esp+0x18]
    mov    ebp,0x40
    sub    ebp,eax
    lea    edi,[eax+ebx*1+0x24]
    cmp    ecx,ebp
    jae sha1_complete_partial_block
    mov    eax,ecx
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  sha1_complete_partial_block:
    mov    ecx,ebp
    push   0x40
    mov    edx,ecx
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    lea    esi,[ebx+0x24]
    mov    ecx,ebx
    push   esi
    call   R6GameServiceAddresses::SwapSha1MessageWordsInPlace
    lea    eax,[ebx+0x8]
    push   esi
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::CompressSha1Block
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x1c]
    add    ecx,ebp
    sub    eax,ebp
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0x1c],eax
    mov    ecx,eax
  sha1_check_full_blocks:
    cmp    ecx,0x40
    jb sha1_copy_tail
    mov    eax,DWORD PTR [esp+0x1c]
    lea    ebp,[ebx+0x24]
    shr    eax,0x6
    mov    DWORD PTR [esp+0x10],eax
  sha1_next_full_block:
    mov    esi,DWORD PTR [esp+0x18]
    mov    ecx,0x10
    mov    edi,ebp
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    esi,0x40
    mov    ecx,ebx
    push   esi
    push   ebp
    call   R6GameServiceAddresses::SwapSha1MessageWordsInPlace
    lea    eax,[ebx+0x8]
    push   ebp
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::CompressSha1Block
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x10]
    add    edx,esi
    sub    ecx,esi
    dec    eax
    mov    DWORD PTR [esp+0x18],edx
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x10],eax
    jne sha1_next_full_block
  sha1_copy_tail:
    mov    esi,DWORD PTR [esp+0x18]
    mov    edx,ecx
    lea    edi,[ebx+0x24]
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Pads and compresses the final blocks, writes a big-endian digest, then clears all23 state/counter/buffer words.
// R6GameService.dll @ 1003a1c0 : ECX owner, output word, RET4; EAX0/ECX0; state clears without reinitializing.
__declspec(naked) uint __thiscall FinalizeSha1Context(void *owner,uint *digestOutput)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    ecx,0x3f
    mov    eax,DWORD PTR [esi+0x1c]
    sar    eax,0x3
    and    eax,0x3f
    sub    ecx,eax
    lea    edi,[eax+esi*1+0x24]
    xor    eax,eax
    mov    BYTE PTR [edi],0x80
    inc    edi
    cmp    ecx,0x8
    jge sha1_pad_single_block
    mov    edx,ecx
    push   0x40
    shr    ecx,0x2
    rep stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep stos BYTE PTR es:[edi],al
    lea    edi,[esi+0x24]
    mov    ecx,esi
    push   edi
    call   R6GameServiceAddresses::SwapSha1MessageWordsInPlace
    lea    eax,[esi+0x8]
    push   edi
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::CompressSha1Block
    mov    ecx,0xe
    xor    eax,eax
    rep stos DWORD PTR es:[edi],eax
    jmp sha1_append_bit_count
  sha1_pad_single_block:
    add    ecx,0xfffffff8
    mov    edx,ecx
    shr    ecx,0x2
    rep stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep stos BYTE PTR es:[edi],al
  sha1_append_bit_count:
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    eax,DWORD PTR [esi+0x20]
    lea    ebx,[esi+0x24]
    mov    DWORD PTR [esi+0x60],ecx
    push   0x38
    push   ebx
    mov    ecx,esi
    mov    DWORD PTR [esi+0x5c],eax
    call   R6GameServiceAddresses::SwapSha1MessageWordsInPlace
    lea    edi,[esi+0x8]
    push   ebx
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::CompressSha1Block
    mov    edx,DWORD PTR [esp+0x10]
    push   0x14
    push   edi
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopySha1DigestBytes
    mov    ecx,0x17
    xor    eax,eax
    rep stos DWORD PTR es:[edi],eax
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Native virtual-table prefix: SecureHashAlgorithm1VTable
// R6GameService.dll data @ 10077a8c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct SecureHashAlgorithm1VTableRecord {
  R6GameServiceNative::Address DeleteSha1Context; // +0x00
};
const SecureHashAlgorithm1VTableRecord SecureHashAlgorithm1VTable = {R6GameServiceAddresses::DeleteSha1Context};
