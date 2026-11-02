#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10081178 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MD5ConstructExceptionHandlerFunctionInfo;

// Identified native class: MD5, COL1007980c/type1008fdc0/table10077a9c.
// Allocation-base ancestry is RTTI-backed; no complete original class declaration is invented.

struct MD5ConstructFrame {
  uint constructionFlags; // EntryESP-0x14, optional virtual-base setup bit.
  uint *savedOwner; // EntryESP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Installs the optional virtual-base table and primary table, then resets the native hash state.
// R6GameService.dll @ 1003c010 : ECX owner, flag stack word, RET4; state1 spans table/reset.
void * __thiscall ConstructMd5Context(void *owner,uint initializeBase)
{
  MD5ConstructFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)MD5ConstructExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  uint baseFlag = initializeBase;
  frame.constructionFlags = 0;
  if (baseFlag != 0) {
    *(uint *)((uint)owner + 4) = 0x10077aa0;
    frame.constructionFlags = 1;
  }
  frame.state = 1;
  *(uint *)owner = R6GameServiceAddresses::MD5VTable;
  ResetMd5Context(owner);
  ExceptionList = frame.previousExceptionList;
  return owner;
}

// Destroys context storage, tests the original flags afterward and frees only for low bit1.
// R6GameService.dll @ 1003c080 : ECX owner, flags stack word, RET4; full EAX=original owner.
void * __thiscall DeleteMd5Context(void *owner,byte flags)
{
  DestroyMD5((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Clears block and cached digest, restores the base table and retains chaining state, counters and finalized flag.
// R6GameService.dll @ 1003c0a0 : ECX owner, plain RET; EAX0, ECX owner+60, EDX owner, EDI preserved.
__declspec(naked) uint __fastcall DestroyMD5(uint *owner)
{
  __asm {
    mov    edx,ecx
    push   edi
    mov    ecx,0x10
    xor    eax,eax
    lea    edi,[edx+0x20]
    rep stos DWORD PTR es:[edi],eax
    lea    ecx,[edx+0x60]
    pop    edi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [ecx+0x4],eax
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [edx],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    ret
  }
}

// Resets the flag byte, counters, block, digest and four chaining words, retaining header/padding bytes.
// R6GameService.dll @ 1003c0d0 : ECX owner, plain RET; EAX0, ECX owner+60, EDX owner, EDI preserved.
__declspec(naked) uint __fastcall ResetMd5Context(void *owner)
{
  __asm {
    mov    edx,ecx
    push   edi
    xor    eax,eax
    mov    ecx,0x10
    lea    edi,[edx+0x20]
    mov    BYTE PTR [edx+0x70],al
    mov    DWORD PTR [edx+0x18],eax
    mov    DWORD PTR [edx+0x1c],eax
    rep stos DWORD PTR es:[edi],eax
    lea    ecx,[edx+0x60]
    pop    edi
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [ecx+0x4],eax
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ecx+0xc],eax
    mov    DWORD PTR [edx+0x8],0x67452301
    mov    DWORD PTR [edx+0xc],0xefcdab89
    mov    DWORD PTR [edx+0x10],0x98badcfe
    mov    DWORD PTR [edx+0x14],0x10325476
    ret
  }
}

// For optional virtual-base setup, tail-forwards owner+74 to the genuine no-op destructor.
// R6GameService.dll @ 10066b50 : inherited EBP-14 flags/EBP-10 owner; no new frame.
__declspec(naked) void __cdecl CleanupMD5VirtualBase(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je md5_virtual_base_done
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x74
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  md5_virtual_base_done:
    ret
  }
}

// Tail-forwards the saved owner to allocation-base destruction during constructor unwind.
// R6GameService.dll @ 10066b6a : inherited EBP-10 owner, JMP10037840.
__declspec(naked) void __cdecl CleanupMD5AllocationBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the two-state constructor unwind map for MD5.
// R6GameService.dll @ 10066b72 : EAX=10081178, inherited-frame JMP10033906.
__declspec(naked) void __cdecl MD5ConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MD5ConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Executes MD5's64 steps with native scratch spills, input-argument reuse and seven shared final-round calls.
// EntryESP-50/-4c/-48/-44 hold working A/B/D/C, -40..-4 hold16 words; input argument also becomes scratch.
// R6GameService.dll @ 1003c290 : ECX MD5 owner, input stack word, RET4; EAX=updated fourth state word.
__declspec(naked) uint __thiscall CompressMD5Block(void *owner,const byte *input)
{
  __asm {
    sub    esp,0x50
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    push   0x40
    mov    ecx,DWORD PTR [esi+0xc]
    mov    edx,DWORD PTR [esi+0x10]
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x68]
    mov    DWORD PTR [esp+0x20],edx
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x24]
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x24],eax
    call   R6GameServiceAddresses::DecodeLittleEndianWordGroups
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x18]
    mov    eax,edi
    not    eax
    mov    ecx,ebx
    and    eax,edx
    and    ecx,edi
    mov    ebp,edi
    or     eax,ecx
    mov    ecx,DWORD PTR [esp+0x20]
    add    eax,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    // Round F: sequential message words, rotations7/12/17/22.
    lea    ecx,[ecx+eax*1-0x28955b88]
    mov    eax,ecx
    shr    eax,0x19
    shl    ecx,0x7
    or     eax,ecx
    add    eax,edi
    mov    ecx,eax
    and    ebp,eax
    not    ecx
    and    ecx,ebx
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    add    ecx,ebp
    lea    edx,[edx+ecx*1-0x173848aa]
    mov    ecx,edx
    shr    ecx,0x14
    shl    edx,0xc
    or     ecx,edx
    add    ecx,eax
    mov    edx,ecx
    mov    ebp,ecx
    not    edx
    and    edx,edi
    and    ebp,eax
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    add    edx,ebp
    mov    ebp,ecx
    lea    ebx,[ebx+edx*1+0x242070db]
    mov    edx,ebx
    shr    edx,0xf
    shl    ebx,0x11
    or     edx,ebx
    add    edx,ecx
    mov    ebx,edx
    and    ebp,edx
    not    ebx
    and    ebx,eax
    or     ebx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    add    ebx,ebp
    lea    ebx,[edi+ebx*1-0x3e423112]
    mov    edi,ebx
    shl    edi,0x16
    shr    ebx,0xa
    or     edi,ebx
    add    edi,edx
    mov    DWORD PTR [esp+0x14],edi
    not    edi
    mov    ebp,DWORD PTR [esp+0x14]
    mov    ebx,edx
    and    edi,ecx
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    or     edi,ebx
    add    edi,ebp
    mov    ebx,DWORD PTR [esp+0x14]
    mov    ebp,ebx
    lea    eax,[eax+edi*1-0xa83f051]
    mov    edi,eax
    shr    edi,0x19
    shl    eax,0x7
    or     edi,eax
    add    edi,ebx
    mov    eax,edi
    and    ebp,edi
    not    eax
    and    eax,edx
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    eax,ebp
    lea    ecx,[ecx+eax*1+0x4787c62a]
    mov    eax,ecx
    shr    eax,0x14
    shl    ecx,0xc
    or     eax,ecx
    add    eax,edi
    mov    ecx,eax
    mov    ebp,eax
    not    ecx
    and    ecx,ebx
    and    ebp,edi
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    add    ecx,ebp
    mov    ebp,eax
    lea    edx,[edx+ecx*1-0x57cfb9ed]
    mov    ecx,edx
    shr    ecx,0xf
    shl    edx,0x11
    or     ecx,edx
    add    ecx,eax
    mov    edx,ecx
    and    ebp,ecx
    not    edx
    and    edx,edi
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    edx,ebp
    lea    ebx,[ebx+edx*1-0x2b96aff]
    mov    edx,ebx
    shl    edx,0x16
    shr    ebx,0xa
    or     edx,ebx
    mov    ebx,ecx
    add    edx,ecx
    mov    DWORD PTR [esp+0x14],edx
    mov    ebp,DWORD PTR [esp+0x14]
    not    edx
    and    edx,eax
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    or     edx,ebx
    add    edx,ebp
    mov    ebx,DWORD PTR [esp+0x14]
    mov    ebp,ebx
    lea    edi,[edi+edx*1+0x698098d8]
    mov    edx,edi
    shr    edx,0x19
    shl    edi,0x7
    or     edx,edi
    add    edx,ebx
    mov    edi,edx
    and    ebp,edx
    not    edi
    and    edi,ecx
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    edi,ebp
    lea    eax,[eax+edi*1-0x74bb0851]
    mov    edi,eax
    shr    edi,0x14
    shl    eax,0xc
    or     edi,eax
    add    edi,edx
    mov    eax,edi
    mov    ebp,edi
    not    eax
    and    eax,ebx
    and    ebp,edx
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    add    eax,ebp
    mov    ebp,edi
    lea    ecx,[ecx+eax*1-0xa44f]
    mov    eax,ecx
    shr    eax,0xf
    shl    ecx,0x11
    or     eax,ecx
    add    eax,edi
    mov    ecx,eax
    and    ebp,eax
    not    ecx
    and    ecx,edx
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    add    ecx,ebp
    lea    ebx,[ebx+ecx*1-0x76a32842]
    mov    ecx,ebx
    shl    ecx,0x16
    shr    ebx,0xa
    or     ecx,ebx
    mov    ebx,eax
    add    ecx,eax
    mov    DWORD PTR [esp+0x14],ecx
    mov    ebp,DWORD PTR [esp+0x14]
    not    ecx
    and    ecx,edi
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    or     ecx,ebx
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x14]
    mov    ebx,ebp
    lea    edx,[edx+ecx*1+0x6b901122]
    mov    ecx,edx
    shr    ecx,0x19
    shl    edx,0x7
    or     ecx,edx
    add    ecx,ebp
    mov    edx,ecx
    and    ebx,ecx
    not    edx
    and    edx,eax
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x54]
    add    edx,ebx
    lea    edi,[edi+edx*1-0x2678e6d]
    mov    edx,edi
    shr    edx,0x14
    shl    edi,0xc
    or     edx,edi
    add    edx,ecx
    mov    ebx,edx
    not    ebx
    mov    edi,ebx
    and    edi,ebp
    mov    ebp,edx
    and    ebp,ecx
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x58]
    add    edi,ebp
    lea    eax,[eax+edi*1-0x5986bc72]
    mov    edi,eax
    shr    edi,0xf
    shl    eax,0x11
    or     edi,eax
    add    edi,edx
    mov    eax,edi
    not    eax
    mov    DWORD PTR [esp+0x64],eax
    mov    ebp,edx
    and    eax,ecx
    and    ebp,edi
    and    ebx,edi
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x5c]
    add    eax,ebp
    mov    ebp,DWORD PTR [esp+0x14]
    lea    ebp,[eax+ebp*1+0x49b40821]
    mov    eax,ebp
    shl    eax,0x16
    shr    ebp,0xa
    or     eax,ebp
    mov    ebp,edx
    add    eax,edi
    and    ebp,eax
    or     ebx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    add    ebx,ebp
    mov    ebp,edi
    // Round G: message index(5*i+1)&15, rotations5/9/14/20.
    lea    ecx,[ecx+ebx*1-0x9e1da9e]
    mov    ebx,ecx
    shr    ebx,0x1b
    shl    ecx,0x5
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    add    ebx,eax
    and    ecx,eax
    and    ebp,ebx
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    add    ecx,ebp
    lea    edx,[edx+ecx*1-0x3fbf4cc0]
    mov    ecx,edx
    shr    ecx,0x17
    shl    edx,0x9
    or     ecx,edx
    mov    edx,eax
    add    ecx,ebx
    not    edx
    mov    ebp,ecx
    and    edx,ebx
    and    ebp,eax
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    add    edx,ebp
    lea    edi,[edi+edx*1+0x265e5a51]
    mov    edx,edi
    shr    edx,0x12
    shl    edi,0xe
    or     edx,edi
    mov    edi,ebx
    add    edx,ecx
    not    edi
    mov    ebp,edx
    and    edi,ecx
    and    ebp,ebx
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    add    edi,ebp
    mov    ebp,ecx
    lea    eax,[eax+edi*1-0x16493856]
    mov    edi,eax
    shl    edi,0x14
    shr    eax,0xc
    or     edi,eax
    mov    eax,ecx
    add    edi,edx
    not    eax
    and    eax,edx
    and    ebp,edi
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    eax,ebp
    lea    ebx,[ebx+eax*1-0x29d0efa3]
    mov    eax,ebx
    shr    eax,0x1b
    shl    ebx,0x5
    or     eax,ebx
    add    eax,edi
    mov    DWORD PTR [esp+0x10],eax
    mov    ebp,DWORD PTR [esp+0x10]
    mov    eax,edx
    not    eax
    mov    ebx,edx
    and    eax,edi
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    add    eax,ebp
    lea    ecx,[ecx+eax*1+0x2441453]
    mov    eax,ecx
    shr    eax,0x17
    shl    ecx,0x9
    or     eax,ecx
    mov    ecx,edi
    add    eax,ebx
    not    ecx
    mov    ebp,eax
    and    ecx,ebx
    and    ebp,edi
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x5c]
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    not    ebx
    lea    edx,[edx+ecx*1-0x275e197f]
    and    ebx,eax
    mov    ecx,edx
    shr    ecx,0x12
    shl    edx,0xe
    or     ecx,edx
    add    ecx,eax
    mov    edx,ecx
    and    edx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    or     ebx,edx
    add    ebx,ebp
    lea    edi,[edi+ebx*1-0x182c0438]
    mov    ebx,eax
    mov    edx,edi
    shl    edx,0x14
    shr    edi,0xc
    or     edx,edi
    mov    edi,eax
    add    edx,ecx
    not    edi
    and    edi,ecx
    and    ebx,edx
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebx,[ebx+edi*1+0x21e1cde6]
    mov    edi,ebx
    shr    edi,0x1b
    shl    ebx,0x5
    or     edi,ebx
    mov    ebx,ecx
    add    edi,edx
    mov    DWORD PTR [esp+0x10],edi
    mov    ebp,DWORD PTR [esp+0x10]
    mov    edi,ecx
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x58]
    not    edi
    and    edi,edx
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    add    edi,ebp
    lea    eax,[eax+edi*1-0x3cc8f82a]
    mov    edi,eax
    shr    edi,0x17
    shl    eax,0x9
    or     edi,eax
    mov    eax,edx
    add    edi,ebx
    not    eax
    mov    ebp,edi
    and    eax,ebx
    and    ebp,edx
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    add    eax,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    not    ebx
    lea    ecx,[ecx+eax*1-0xb2af279]
    and    ebx,edi
    mov    eax,ecx
    shr    eax,0x12
    shl    ecx,0xe
    or     eax,ecx
    add    eax,edi
    mov    ecx,eax
    and    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    or     ebx,ecx
    add    ebx,ebp
    lea    edx,[edx+ebx*1+0x455a14ed]
    mov    ebx,edi
    mov    ecx,edx
    shl    ecx,0x14
    shr    edx,0xc
    or     ecx,edx
    mov    edx,edi
    add    ecx,eax
    not    edx
    and    edx,eax
    and    ebx,ecx
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x54]
    add    edx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebx,[ebx+edx*1-0x561c16fb]
    mov    edx,ebx
    shr    edx,0x1b
    shl    ebx,0x5
    or     edx,ebx
    mov    ebx,eax
    add    edx,ecx
    mov    DWORD PTR [esp+0x10],edx
    mov    ebp,DWORD PTR [esp+0x10]
    mov    edx,eax
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    not    edx
    and    edx,ecx
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    add    edx,ebp
    lea    edi,[edi+edx*1-0x3105c08]
    mov    edx,edi
    shr    edx,0x17
    shl    edi,0x9
    or     edx,edi
    mov    edi,ecx
    add    edx,ebx
    not    edi
    mov    ebp,edx
    and    edi,ebx
    and    ebp,ecx
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    edi,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    not    ebx
    lea    eax,[eax+edi*1+0x676f02d9]
    and    ebx,edx
    mov    edi,eax
    shr    edi,0x12
    shl    eax,0xe
    or     edi,eax
    add    edi,edx
    mov    eax,edi
    and    eax,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    or     ebx,eax
    add    ebx,ebp
    lea    ecx,[ecx+ebx*1-0x72d5b376]
    mov    eax,ecx
    shl    eax,0x14
    shr    ecx,0xc
    mov    ebx,DWORD PTR [esp+0x34]
    or     eax,ecx
    mov    ecx,edx
    add    eax,edi
    xor    ecx,edi
    mov    ebp,DWORD PTR [esp+0x40]
    xor    ecx,eax
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    // Round H: message index(3*i+5)&15, rotations4/11/16/23.
    lea    ebx,[ebx+ecx*1-0x5c6be]
    mov    ecx,ebx
    shr    ecx,0x1c
    shl    ebx,0x4
    or     ecx,ebx
    mov    ebx,edi
    add    ecx,eax
    xor    ebx,eax
    xor    ebx,ecx
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    lea    edx,[edx+ebx*1-0x788e097f]
    mov    ebx,edx
    shr    ebx,0x15
    shl    edx,0xb
    or     ebx,edx
    add    ebx,ecx
    mov    edx,ebx
    xor    edx,eax
    xor    edx,ecx
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x58]
    lea    edx,[edi+edx*1+0x6d9d6122]
    mov    edi,edx
    shr    edi,0x10
    shl    edx,0x10
    or     edi,edx
    mov    edx,ebx
    add    edi,ebx
    xor    edx,edi
    mov    DWORD PTR [esp+0x64],edx
    xor    edx,ecx
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    lea    eax,[eax+edx*1-0x21ac7f4]
    mov    edx,eax
    shl    edx,0x17
    shr    eax,0x9
    or     edx,eax
    mov    eax,DWORD PTR [esp+0x64]
    add    edx,edi
    xor    eax,edx
    add    eax,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    lea    ecx,[ecx+eax*1-0x5b4115bc]
    mov    eax,ecx
    shr    eax,0x1c
    shl    ecx,0x4
    or     eax,ecx
    mov    ecx,edi
    add    eax,edx
    xor    ecx,edx
    xor    ecx,eax
    add    ecx,ebp
    lea    ebx,[ebx+ecx*1+0x4bdecfa9]
    mov    ebp,ebx
    shr    ebp,0x15
    shl    ebx,0xb
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    add    ebp,eax
    mov    ecx,ebp
    xor    ecx,edx
    xor    ecx,eax
    add    ecx,ebx
    lea    edi,[edi+ecx*1-0x944b4a0]
    mov    ebx,edi
    shr    ebx,0x10
    shl    edi,0x10
    or     ebx,edi
    mov    edi,ebp
    add    ebx,ebp
    xor    edi,ebx
    mov    ecx,edi
    xor    ecx,eax
    add    ecx,DWORD PTR [esp+0x48]
    lea    edx,[edx+ecx*1-0x41404390]
    mov    ecx,edx
    shl    ecx,0x17
    shr    edx,0x9
    or     ecx,edx
    mov    edx,DWORD PTR [esp+0x54]
    add    ecx,ebx
    xor    edi,ecx
    add    edi,edx
    mov    edx,ebx
    xor    edx,ecx
    lea    edi,[eax+edi*1+0x289b7ec6]
    mov    eax,edi
    shr    eax,0x1c
    shl    edi,0x4
    or     eax,edi
    mov    edi,DWORD PTR [esp+0x20]
    add    eax,ecx
    xor    edx,eax
    add    edx,edi
    lea    ebp,[edx+ebp*1-0x155ed806]
    mov    edx,ebp
    shr    edx,0x15
    shl    ebp,0xb
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    add    edx,eax
    mov    edi,edx
    xor    edi,ecx
    xor    edi,eax
    add    edi,ebp
    lea    ebx,[ebx+edi*1-0x2b10cf7b]
    mov    edi,ebx
    shr    edi,0x10
    shl    ebx,0x10
    or     edi,ebx
    mov    ebx,edx
    add    edi,edx
    xor    ebx,edi
    mov    ebp,ebx
    xor    ebp,eax
    add    ebp,DWORD PTR [esp+0x38]
    lea    ebp,[ecx+ebp*1+0x4881d05]
    mov    ecx,ebp
    shl    ecx,0x17
    shr    ebp,0x9
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    ecx,edi
    xor    ebx,ecx
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    lea    ebx,[eax+ebx*1-0x262b2fc7]
    mov    eax,ebx
    shr    eax,0x1c
    shl    ebx,0x4
    or     eax,ebx
    mov    ebx,edi
    add    eax,ecx
    xor    ebx,ecx
    xor    ebx,eax
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x5c]
    lea    ebx,[edx+ebx*1-0x1924661b]
    mov    edx,ebx
    shr    edx,0x15
    shl    ebx,0xb
    or     edx,ebx
    add    edx,eax
    mov    ebx,edx
    xor    ebx,ecx
    xor    ebx,eax
    add    ebx,ebp
    lea    ebx,[edi+ebx*1+0x1fa27cf8]
    mov    edi,ebx
    shr    edi,0x10
    shl    ebx,0x10
    mov    ebp,DWORD PTR [esp+0x28]
    or     edi,ebx
    add    edi,edx
    mov    ebx,edx
    xor    ebx,edi
    xor    ebx,eax
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    lea    ecx,[ecx+ebx*1-0x3b53a99b]
    mov    ebx,ecx
    shl    ebx,0x17
    shr    ecx,0x9
    or     ebx,ecx
    mov    ecx,edx
    add    ebx,edi
    not    ecx
    or     ecx,ebx
    xor    ecx,edi
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    // Round I: message index(7*i)&15, rotations6/10/15/21.
    lea    eax,[eax+ecx*1-0xbd6ddbc]
    mov    ecx,eax
    shr    ecx,0x1a
    shl    eax,0x6
    or     ecx,eax
    mov    eax,edi
    add    ecx,ebx
    not    eax
    or     eax,ecx
    xor    eax,ebx
    add    eax,ebp
    mov    ebp,DWORD PTR [esp+0x58]
    lea    edx,[edx+eax*1+0x432aff97]
    mov    eax,edx
    shr    eax,0x16
    shl    edx,0xa
    or     eax,edx
    mov    edx,ebx
    add    eax,ecx
    not    edx
    or     edx,eax
    xor    edx,ecx
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    lea    edi,[edi+edx*1-0x546bdc59]
    mov    edx,edi
    shr    edx,0x11
    shl    edi,0xf
    or     edx,edi
    mov    edi,ecx
    add    edx,eax
    not    edi
    or     edi,edx
    xor    edi,eax
    add    edi,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    lea    ebx,[ebx+edi*1-0x36c5fc7]
    mov    edi,ebx
    shl    edi,0x15
    shr    ebx,0xb
    or     edi,ebx
    mov    ebx,eax
    add    edi,edx
    not    ebx
    or     ebx,edi
    xor    ebx,edx
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    lea    ecx,[ecx+ebx*1+0x655b59c3]
    mov    ebx,ecx
    shr    ebx,0x1a
    shl    ecx,0x6
    or     ebx,ecx
    mov    ecx,edx
    add    ebx,edi
    not    ecx
    or     ecx,ebx
    xor    ecx,edi
    add    ecx,ebp
    lea    ecx,[eax+ecx*1-0x70f3336e]
    mov    eax,ecx
    shr    eax,0x16
    shl    ecx,0xa
    mov    ebp,DWORD PTR [esp+0x48]
    or     eax,ecx
    mov    ecx,edi
    add    eax,ebx
    not    ecx
    or     ecx,eax
    mov    DWORD PTR [esp+0x18],eax
    xor    ecx,ebx
    push   0xfe2ce6e0
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    push   0xa
    lea    edx,[edx+ecx*1-0x100b83]
    mov    ecx,edx
    shr    ecx,0x11
    shl    edx,0xf
    or     ecx,edx
    mov    edx,ebx
    add    ecx,eax
    not    edx
    or     edx,ecx
    mov    DWORD PTR [esp+0x24],ecx
    xor    edx,eax
    add    edx,ebp
    not    eax
    lea    edi,[edi+edx*1-0x7a7ba22f]
    mov    edx,edi
    shl    edx,0x15
    shr    edi,0xb
    or     edx,edi
    mov    edi,DWORD PTR [esp+0x48]
    add    edx,ecx
    or     eax,edx
    mov    DWORD PTR [esp+0x1c],edx
    xor    eax,ecx
    add    eax,edi
    lea    eax,[ebx+eax*1+0x6fa87e4f]
    mov    edi,eax
    shr    edi,0x1a
    shl    eax,0x6
    or     edi,eax
    mov    eax,DWORD PTR [esp+0x64]
    push   eax
    add    edi,edx
    push   ecx
    push   edx
    lea    ecx,[esp+0x2c]
    push   edi
    push   ecx
    mov    DWORD PTR [esp+0x2c],edi
    // Shared inverted-OR step; seven such calls finish round I.
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    edx,DWORD PTR [esp+0x38]
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x10]
    push   0xa3014314
    push   0xf
    push   edx
    mov    edx,DWORD PTR [esp+0x24]
    push   eax
    push   ecx
    lea    eax,[esp+0x30]
    push   edx
    push   eax
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    ecx,DWORD PTR [esp+0x54]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x18]
    push   0x4e0811a1
    push   0x15
    push   ecx
    mov    ecx,DWORD PTR [esp+0x28]
    push   edx
    push   eax
    lea    edx,[esp+0x28]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    push   0xf7537e82
    push   0x6
    mov    eax,DWORD PTR [esp+0x38]
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [esp+0x24]
    push   eax
    mov    eax,DWORD PTR [esp+0x20]
    push   ecx
    push   edx
    lea    ecx,[esp+0x24]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    edx,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x14]
    push   0xbd3af235
    push   0xa
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   eax
    push   ecx
    lea    eax,[esp+0x2c]
    push   edx
    push   eax
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
    push   0x2ad7d2bb
    push   0xf
    push   ecx
    mov    ecx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    lea    edx,[esp+0x30]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    eax,DWORD PTR [esp+0x44]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x18]
    push   0xeb86d391
    push   0x15
    push   eax
    mov    eax,DWORD PTR [esp+0x28]
    push   ecx
    push   edx
    lea    ecx,[esp+0x28]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::UpdateInvertedOrDigestWord
    mov    edx,DWORD PTR [esp+0x10]
    mov    ebx,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [esi+0xc]
    add    ebx,edx
    mov    edx,DWORD PTR [esi+0x10]
    add    edi,eax
    mov    eax,DWORD PTR [esi+0x14]
    add    edx,ecx
    mov    DWORD PTR [esi+0x10],edx
    mov    edx,DWORD PTR [esp+0x18]
    add    eax,edx
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esi+0x8],ebx
    mov    DWORD PTR [esi+0x14],eax
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x50
    ret    0x4
  }
}

// Adds bytes with native DWORD/tail copying; a finalized context returns incoming EAX high bits with AL=flag.
// R6GameService.dll @ 1003c120 : ECX MD5 owner, input/count stack words, RET8; active EAX=final tail-byte count.
uint __thiscall UpdateMD5(void *owner,const byte *input,uint byteCount)
{
  uint eaxValue;
  __asm { mov eaxValue,eax } // Capture the native incoming volatile-register residue before loading the flag.
  byte *context = (byte *)owner;
  byte finalized = context[0x70];
  if (finalized != 0) return (eaxValue & 0xffffff00) | finalized;
  uint oldLow = *(uint *)(context + 0x18);
  uint count = byteCount;
  uint newLow = oldLow + count * 8U;
  uint bufferIndex = (oldLow >> 3) & 63;
  *(uint *)(context + 0x18) = newLow;
  if (newLow < count * 8U) ++*(uint *)(context + 0x1c);
  uint high = *(uint *)(context + 0x1c);
  uint firstChunk = 64 - bufferIndex;
  *(uint *)(context + 0x1c) = high + (count >> 29);
  uint processed;
  if (count >= firstChunk) {
    const byte *source = input;
    byte *destination = context + 0x20 + bufferIndex;
    for (uint offset = 0; offset < (firstChunk & ~3U); offset += 4) {
      *(uint *)(destination + offset) = *(const uint *)(source + offset);
    }
    for (uint offset = firstChunk & ~3U; offset < firstChunk; ++offset) destination[offset] = source[offset];
    CompressMD5Block(owner,context + 0x20);
    processed = firstChunk;
    uint blockLast = firstChunk + 63;
    uint bound = byteCount; // Reloaded once after the first compression and retained across subsequent blocks.
    while (blockLast < bound) {
      const byte *inputArgument = input;
      CompressMD5Block(owner,(const byte *)((uint)inputArgument + blockLast - 63));
      blockLast += 64;
      processed += 64;
    }
    count = byteCount; // Tail length reloads the original argument again after the loop.
    bufferIndex = 0;
  } else {
    processed = 0;
  }
  const byte *inputArgument = input;
  uint tailBytes = count - processed;
  const byte *source = (const byte *)((uint)inputArgument + processed);
  byte *destination = context + 0x20 + bufferIndex;
  for (uint offset = 0; offset < (tailBytes & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  for (uint offset = tailBytes & ~3U; offset < tailBytes; ++offset) destination[offset] = source[offset];
  return tailBytes;
}

// R6GameService.dll data @ 1008fd80 : native storage identity retained.
const byte GMD5Padding[64] = {0x80};

// Finalizes once, copies four digest words in order and clears only the first block/cache byte afterward.
// R6GameService.dll @ 1003c1f0 : ECX MD5 owner, output stack word, RET4; active EAX=last copied digest word.
uint __thiscall FinalizeMD5(void *owner,uint *digestOutput)
{
  uint eaxValue;
  __asm { mov eaxValue,eax }
  byte *context = (byte *)owner;
  byte finalized = context[0x70];
  if (finalized != 0) return (eaxValue & 0xffffff00) | finalized;
  uint savedBitCount[2]; // EntryESP-8/-4, no exception registration or clearing on exit.
  CopyFourByteGroupsForward((byte *)savedBitCount,context + 0x18,8);
  uint bufferIndex = (*(uint *)(context + 0x18) >> 3) & 63;
  uint paddingEnd = bufferIndex < 56 ? 56 : 120;
  UpdateMD5(owner,GMD5Padding,paddingEnd - bufferIndex);
  UpdateMD5(owner,(const byte *)savedBitCount,8);
  uint *cachedDigest = (uint *)(context + 0x60);
  CopyFourByteGroupsForward((byte *)cachedDigest,context + 8,16);
  uint *outputArgument = digestOutput;
  context[0x70] = 1;
  uint word = cachedDigest[0];
  outputArgument[0] = word;
  word = cachedDigest[1];
  outputArgument[1] = word;
  word = cachedDigest[2];
  outputArgument[2] = word;
  word = cachedDigest[3];
  outputArgument[3] = word;
  context[0x20] = 0;
  *(byte *)cachedDigest = 0;
  return word;
}

// Native virtual-table prefix: MD5VTable
// R6GameService.dll data @ 10077a9c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct MD5VTableRecord {
  R6GameServiceNative::Address DeleteMd5Context; // +0x00
};
const MD5VTableRecord MD5VTable = {R6GameServiceAddresses::DeleteMd5Context};
