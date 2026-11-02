#include "native_addresses.h"

// Native byte-order and digest-step helpers; concrete original class ownership remains unassigned.

// Copies four bytes forward per group, rounding nonmultiple counts upward and retaining native byte-at-a-time overlap.
// R6GameService.dll @ 1003cc30 : destination/source/count stack words, RET0x0c; nonzero EAX=destination+copied+1.
uint __stdcall CopyFourByteGroupsForward(byte *destination,const byte *source,uint byteCount)
{
  uint eaxValue;
  __asm { mov eaxValue,eax }
  uint count = byteCount;
  if (count == 0) return eaxValue;
  byte *output = destination;
  const byte *input = source;
  uint copied = 0;
  do {
    byte value = input[0];
    output[0] = value;
    value = input[1];
    output[1] = value;
    value = input[2];
    output[2] = value;
    value = input[3];
    output[3] = value;
    input += 4;
    output += 4;
    copied += 4;
  } while (copied < count);
  return (uint)output + 1;
}

// Decodes four-byte little-endian groups, reading bytes3/1/2/0 before each word store and rounding counts upward.
// R6GameService.dll @ 1003cc80 : destination/source/count stack words, RET0x0c; nonzero EAX=source+copied+2.
uint __stdcall DecodeLittleEndianWordGroups(uint *destination,const byte *source,uint byteCount)
{
  uint eaxValue;
  __asm { mov eaxValue,eax }
  uint count = byteCount;
  if (count == 0) return eaxValue;
  const byte *input = source;
  uint *output = destination;
  uint copied = 0;
  do {
    uint highByte = input[3];
    uint byte1 = input[1];
    uint byte2 = input[2];
    uint value = (highByte << 16) | (byte2 << 8) | byte1;
    uint byte0 = input[0];
    *output++ = (value << 8) | byte0;
    input += 4;
    copied += 4;
  } while (copied < count);
  return (uint)input + 2;
}

// Applies the inverted-OR MD5 step and returns the uncombined left-shifted sum retained in native EAX.
// R6GameService.dll @ 1003ccd0 : seven stack words, RET0x1c; x86 masks both shift counts to five bits.
uint __stdcall UpdateInvertedOrDigestWord(uint *accumulator,uint nextWord,uint thirdWord,uint fourthWord,
    uint messageWord,uint rotation,uint additiveConstant)
{
  uint fourth = fourthWord;
  uint next = nextWord;
  uint third = thirdWord;
  uint *output = accumulator;
  uint previous = *output;
  uint boolean = (~fourth | next) ^ third;
  uint constant = additiveConstant;
  uint message = messageWord;
  uint sum = boolean + previous + message + constant;
  uint shift = rotation;
  uint highPart = sum >> ((32U - shift) & 31);
  uint leftPart = sum << (shift & 31);
  *output = (highPart | leftPart) + next;
  return leftPart;
}

// Swaps complete words in place, ignores trailing bytes and retains incoming EAX for sub-word counts.
// R6GameService.dll @ 1003bf80 : ECX unused, words/count words, RET8; active EAX=last swapped word maskedffff0000.
__declspec(naked) uint __thiscall SwapSha1MessageWordsInPlace(
    void *unusedContext,uint *words,uint byteCount)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    shr    esi,0x2
    je sha1_swap_complete
    mov    edx,DWORD PTR [esp+0x8]
  sha1_swap_next_word:
    mov    eax,DWORD PTR [edx]
    add    edx,0x4
    mov    ecx,eax
    shl    ecx,0x8
    shr    eax,0x8
    xor    eax,ecx
    and    eax,0xff00ff
    xor    eax,ecx
    mov    ecx,eax
    shr    ecx,0x10
    shl    eax,0x10
    or     ecx,eax
    dec    esi
    mov    DWORD PTR [edx-0x4],ecx
    jne sha1_swap_next_word
  sha1_swap_complete:
    pop    esi
    ret    0x8
  }
}

// Reads bytes forward and writes each group backward, retaining native overlap effects and rounded group counts.
// R6GameService.dll @ 1003bfc0 : ECX unused, three stack words, RET0x0c; active EAX=destination+copied+2.
__declspec(naked) uint __thiscall CopySha1DigestBytes(
    void *unusedContext,byte *destination,const byte *source,uint byteCount)
{
  __asm {
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    test   edi,edi
    jbe sha1_copy_complete
    mov    edx,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,0xfffffffe
    add    ecx,0x2
    lea    eax,[edx+0x2]
    sub    esi,edx
  sha1_copy_next_group:
    mov    dl,BYTE PTR [ecx-0x2]
    add    ecx,0x4
    mov    BYTE PTR [eax+0x1],dl
    mov    dl,BYTE PTR [ecx-0x5]
    mov    BYTE PTR [eax],dl
    mov    dl,BYTE PTR [ecx-0x4]
    mov    BYTE PTR [eax-0x1],dl
    mov    dl,BYTE PTR [ecx-0x3]
    mov    BYTE PTR [eax-0x2],dl
    add    eax,0x4
    lea    edx,[esi+eax*1]
    cmp    edx,edi
    jb sha1_copy_next_group
    pop    esi
  sha1_copy_complete:
    pop    edi
    ret    0xc
  }
}

// XORs input first, fills a signed-sqrt-sized WORD sentinel matrix diagonally, then compacts row-major and frees it.
// Original buffer/count words reload during traversal; count slot becomes row pointer, saved ECX becomes row counter.
// R6GameService.dll @ 10039230 : native control/access order and raw ABI retained.
__declspec(naked) void __thiscall EncodeMaskedSquareTransposition(void* unusedContext,byte* buffer,int byteCount)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x10]
    push   ebp
    push   esi
    push   edi
    push   ebx
    push   eax
    call   R6GameServiceAddresses::XorBytesWithIndexMask
    fild   DWORD PTR [esp+0x1c]
    fsqrt
    call   R6GameServiceAddresses::ftol
    mov    esi,eax
    mov    ecx,esi
    imul   ecx,esi
    cmp    ecx,ebx
    jge    Branch1
    inc    esi
  Branch1:
    mov    eax,esi
    imul   eax,esi
    lea    edi,[eax+eax*1]
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    ebp,eax
    mov    edx,ecx
    or     eax,0xffffffff
    mov    edi,ebp
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    xor    edx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    xor    eax,eax
    xor    ecx,ecx
    test   ebx,ebx
    jle    Branch5
  Branch2:
    cmp    ecx,esi
    jl     Branch3
    lea    ecx,[eax+0x2]
    lea    eax,[esi-0x1]
    jmp    Branch4
  Branch3:
    test   eax,eax
    jge    Branch4
    mov    eax,ecx
    xor    ecx,ecx
  Branch4:
    mov    ebx,eax
    mov    edi,DWORD PTR [esp+0x18]
    imul   ebx,esi
    movzx  di,BYTE PTR [edx+edi*1]
    add    ebx,ecx
    dec    eax
    inc    ecx
    inc    edx
    mov    WORD PTR [ebp+ebx*2+0x0],di
    mov    edi,DWORD PTR [esp+0x1c]
    cmp    edx,edi
    jl     Branch2
  Branch5:
    xor    edi,edi
    test   esi,esi
    jle    Branch9
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x10],esi
  Branch6:
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,esi
  Branch7:
    cmp    WORD PTR [eax],0xffff
    je     Branch8
    mov    ebx,DWORD PTR [esp+0x18]
    mov    dl,BYTE PTR [eax]
    mov    BYTE PTR [edi+ebx*1],dl
    inc    edi
  Branch8:
    add    eax,0x2
    dec    ecx
    jne    Branch7
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    eax,[esi+esi*1]
    add    ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    dec    eax
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x10],eax
    jne    Branch6
  Branch9:
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Builds diagonal occupancy bytes, consumes row-major input into occupied cells, emits diagonally, then XORs and frees.
// Native x87 comparison/rounding, cached versus reloaded arguments and byte access order remain explicit.
// R6GameService.dll @ 10039310 : native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DecodeMaskedSquareTransposition(void* unusedContext,byte* buffer,int byteCount)
{
  __asm {
    sub    esp,0xc
    fild   DWORD PTR [esp+0x14]
    push   ebx
    push   ebp
    push   esi
    push   edi
    fsqrt
    mov    DWORD PTR [esp+0x18],ecx
    fld    st(0)
    call   R6GameServiceAddresses::ftol
    mov    esi,eax
    mov    DWORD PTR [esp+0x14],esi
    fild   DWORD PTR [esp+0x14]
    fcompp
    fnstsw ax
    test   ah,0x5
    jp     Branch10
    inc    esi
  Branch10:
    mov    edi,esi
    imul   edi,esi
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,edi
    mov    ebp,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,ebp
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    mov    edx,DWORD PTR [esp+0x24]
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    xor    eax,eax
    xor    ecx,ecx
    test   edx,edx
    jle    Branch14
    mov    edi,edx
  Branch11:
    cmp    ecx,esi
    jl     Branch12
    lea    ecx,[eax+0x2]
    lea    eax,[esi-0x1]
    jmp    Branch13
  Branch12:
    test   eax,eax
    jge    Branch13
    mov    eax,ecx
    xor    ecx,ecx
  Branch13:
    mov    ebx,eax
    imul   ebx,esi
    add    ebx,ecx
    dec    eax
    inc    ecx
    dec    edi
    mov    BYTE PTR [ebx+ebp*1],0x1
    jne    Branch11
  Branch14:
    mov    ebx,DWORD PTR [esp+0x20]
    xor    eax,eax
    cmp    edx,eax
    mov    DWORD PTR [esp+0x10],eax
    jle    Branch18
    mov    DWORD PTR [esp+0x14],eax
  Branch15:
    cmp    eax,esi
    jl     Branch16
    mov    eax,DWORD PTR [esp+0x14]
    add    eax,esi
    mov    DWORD PTR [esp+0x14],eax
    xor    eax,eax
  Branch16:
    mov    ecx,DWORD PTR [esp+0x14]
    add    ecx,eax
    add    ecx,ebp
    cmp    BYTE PTR [ecx],0x0
    je     Branch17
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebx,DWORD PTR [esp+0x20]
    mov    bl,BYTE PTR [edi+ebx*1]
    mov    BYTE PTR [ecx],bl
    mov    ecx,edi
    inc    ecx
    mov    DWORD PTR [esp+0x10],ecx
  Branch17:
    mov    ecx,DWORD PTR [esp+0x10]
    inc    eax
    cmp    ecx,edx
    jl     Branch15
    mov    ebx,DWORD PTR [esp+0x20]
  Branch18:
    xor    eax,eax
    xor    ecx,ecx
    xor    edi,edi
    test   edx,edx
    jle    Branch22
  Branch19:
    cmp    ecx,esi
    jl     Branch20
    lea    ecx,[eax+0x2]
    lea    eax,[esi-0x1]
    jmp    Branch21
  Branch20:
    test   eax,eax
    jge    Branch21
    mov    eax,ecx
    xor    ecx,ecx
  Branch21:
    mov    edx,eax
    imul   edx,esi
    add    edx,ecx
    dec    eax
    inc    ecx
    inc    edi
    mov    dl,BYTE PTR [edx+ebp*1]
    mov    BYTE PTR [edi+ebx*1-0x1],dl
    mov    edx,DWORD PTR [esp+0x24]
    cmp    edi,edx
    jl     Branch19
  Branch22:
    mov    ecx,DWORD PTR [esp+0x18]
    push   edx
    push   ebx
    call   R6GameServiceAddresses::XorBytesWithIndexMask
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// XORs each byte with low8(index-0x77) for positive signed count; returns count EAX or zero, no pointer guard.
// R6GameService.dll @ 10039440 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall XorBytesWithIndexMask(byte* buffer,int byteCount)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    xor    eax,eax
    test   esi,esi
    jle    Branch24
    mov    ecx,DWORD PTR [esp+0x8]
    push   ebx
  Branch23:
    mov    bl,BYTE PTR [eax+ecx*1]
    mov    dl,al
    sub    dl,0x77
    xor    bl,dl
    mov    BYTE PTR [eax+ecx*1],bl
    inc    eax
    cmp    eax,esi
    jl     Branch23
    pop    ebx
  Branch24:
    pop    esi
    ret    0x8
  }
}

// Folds both input words through actual logical-shift helper and returns parity bit; raw register effects retained.
// R6GameService.dll @ 1003cd20 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ComputeUnsigned64Parity(uint lowWord,uint highWord)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,0x20
  Branch25:
    mov    eax,esi
    mov    edx,edi
    mov    ecx,ebx
    call   R6GameServiceAddresses::__aullshr
    xor    esi,eax
    xor    edi,edx
    shr    ebx,1
    jne    Branch25
    mov    eax,esi
    pop    edi
    pop    esi
    and    eax,0x1
    pop    ebx
    ret    0x8
  }
}

// Tests descending whole-byte shifts of cached input words and returns minimum byte width, zero for zero.
// R6GameService.dll @ 1003cd50 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall CountUnsigned64Bytes(uint lowWord,uint highWord)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,0x8
    mov    esi,0x38
  Branch26:
    mov    eax,ebp
    mov    edx,ebx
    mov    ecx,esi
    call   R6GameServiceAddresses::__aullshr
    or     eax,edx
    jne    Branch27
    sub    esi,0x8
    dec    edi
    cmp    esi,0xfffffff8
    jne    Branch26
  Branch27:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Bisects nonzero shift boundary, caching low word and reloading original high stack word on every iteration.
// R6GameService.dll @ 1003cd90 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CountUnsigned64Bits(uint lowWord,uint highWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    push   ebp
    mov    ebp,DWORD PTR [esp+0x8]
    mov    eax,ebp
    or     eax,ecx
    jne    Branch28
    xor    eax,eax
    pop    ebp
    ret    0x8
    // R6GameService.dll @ 1003cda5 : internal nonzero branch, not an independent callable body.
  Branch28:
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    mov    edi,0x40
  Branch29:
    mov    edx,DWORD PTR [esp+0x18]
    lea    esi,[edi+ebx*1]
    shr    esi,1
    mov    eax,ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::__aullshr
    or     eax,edx
    je     Branch30
    mov    ebx,esi
    jmp    Branch31
  Branch30:
    mov    edi,esi
  Branch31:
    mov    ecx,edi
    sub    ecx,ebx
    cmp    ecx,0x1
    ja     Branch29
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    pop    ebp
    ret    0x8
  }
}

// Below64 uses five-bit SHL then DEC/CDQ mask, discarding high input; counts64+ retain both words.
// R6GameService.dll @ 1003cde0 : native control/access order and raw ABI retained.
__declspec(naked) ulonglong __stdcall MaskUnsigned64WithNativeShift(uint lowWord,uint highWord,uint bitCount)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0xc]
    cmp    ecx,0x40
    jae    Branch32
    mov    eax,0x1
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x4]
    dec    eax
    cdq
    and    eax,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    and    edx,ecx
    ret    0xc
  Branch32:
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    ret    0xc
  }
}

// Zeroes cached destination/count before reloading input words, then emits low bytes backwards until width or value ends.
// R6GameService.dll @ 1003ce10 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall WriteUnsigned64BigEndian(uint lowWord,uint highWord,undefined4 *destinationWords,uint byteCount)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x10]
    push   ebx
    mov    ecx,edx
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    push   edi
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,ebx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    jb     Branch34
    mov    eax,DWORD PTR [esp+0x10]
    ja     Branch33
    test   eax,eax
    jbe    Branch34
  Branch33:
    test   edx,edx
    jbe    Branch34
    dec    edx
    mov    BYTE PTR [esi+edx*1],al
    shrd   eax,ecx,0x8
    shr    ecx,0x8
    jne    Branch33
    test   eax,eax
    ja     Branch33
  Branch34:
    pop    edi
    pop    esi
    pop    ebx
    ret    0x10
  }
}
