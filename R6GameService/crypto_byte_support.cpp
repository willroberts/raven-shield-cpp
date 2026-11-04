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

// XORs input first, fills a WORD sentinel matrix diagonally, then compacts occupied cells row-major and frees it.
// float10/sqrt denote live x87 FSQRT under the inherited control word; the signed64 cast denotes imported _ftol.
// Neither operation adds a spill/stack operand; masked invalid conversion retains the CRT indefinite result.
// R6GameService.dll @ 10039230 : thiscall RET8; raw final allocator EAX, no local allocation guard.
uint __thiscall EncodeMaskedSquareTransposition(void *unusedContext,byte *buffer,int byteCount)
{
  int initialCount = byteCount;
  byte *initialBuffer = buffer;
  XorBytesWithIndexMask(initialBuffer,initialCount);
  float10 root = sqrt((float10)byteCount);
  uint side = (uint)(longlong)root;
  if ((int)(side * side) < initialCount) ++side;
  uint allocationBytes = side * side * 2;
  uint matrix = (uint)AllocateGameServiceBytes(allocationBytes);
  uint cursor = matrix;
  uint words = allocationBytes >> 2;
  while (words != 0) {
    *(uint *)cursor = 0xffffffff;
    cursor += 4;
    --words;
  }
  uint tail = allocationBytes & 3;
  while (tail != 0) {
    *(byte *)cursor = 0xff;
    ++cursor;
    --tail;
  }
  uint row = 0,column = 0,index = 0;
  if (initialCount > 0) {
    do {
      if ((int)column >= (int)side) {
        column = row + 2;
        row = side - 1;
      } else if ((int)row < 0) {
        row = column;
        column = 0;
      }
      uint offset = row * side;
      uint currentBuffer = (uint)buffer;
      ushort value = *(byte *)(currentBuffer + index);
      offset += column;
      --row;
      ++column;
      ++index;
      *(ushort *)(matrix + offset * 2) = value;
      int currentCount = byteCount;
      if ((int)index >= currentCount) break;
    } while (true);
  }
  uint outputIndex = 0;
  if ((int)side > 0) {
    byteCount = (int)matrix; // The original count argument becomes the current row pointer.
    uint remainingRows = side; // The native saved-ECX slot becomes the row counter.
    do {
      uint cell = (uint)byteCount;
      uint remainingColumns = side;
      do {
        if (*(ushort *)cell != 0xffff) {
          uint currentBuffer = (uint)buffer;
          byte value = *(byte *)cell;
          *(byte *)(currentBuffer + outputIndex) = value;
          ++outputIndex;
        }
        cell += 2;
        --remainingColumns;
      } while (remainingColumns != 0);
      uint nextRow = (uint)byteCount + side * 2;
      --remainingRows;
      byteCount = (int)nextRow;
    } while (remainingRows != 0);
  }
  using FreeABI = uint (__stdcall *)(void *);
  return ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)matrix);
}

// Marks diagonal occupancy, consumes row-major input into occupied cells, emits diagonally, then XORs and frees.
// The duplicated x87 root survives imported _ftol; only an ordered truncated-width < root comparison increments it.
// R6GameService.dll @ 10039310 : thiscall RET8; raw final allocator EAX, unchecked temporary and original pointers.
uint __thiscall DecodeMaskedSquareTransposition(void *unusedContext,byte *buffer,int byteCount)
{
  struct { // Inferred three native local words at entry ESP-0x0c/-0x08/-0x04.
    uint consumed;
    uint rowOffset;
    void *savedContext;
  } frame;
  float10 root = sqrt((float10)byteCount);
  frame.savedContext = unusedContext;
  uint side = (uint)(longlong)root;
  frame.rowOffset = side;
  if ((float10)(int)frame.rowOffset < root) ++side;
  uint allocationBytes = side * side;
  uint matrix = (uint)AllocateGameServiceBytes(allocationBytes);
  uint cursor = matrix;
  uint words = allocationBytes >> 2;
  while (words != 0) {
    *(uint *)cursor = 0;
    cursor += 4;
    --words;
  }
  int count = byteCount; // Loaded after DWORD clearing and before the trailing byte stores.
  uint tail = allocationBytes & 3;
  while (tail != 0) {
    *(byte *)cursor = 0;
    ++cursor;
    --tail;
  }
  uint row = 0,column = 0;
  if (count > 0) {
    uint remaining = (uint)count;
    do {
      if ((int)column >= (int)side) {
        column = row + 2;
        row = side - 1;
      } else if ((int)row < 0) {
        row = column;
        column = 0;
      }
      uint offset = row * side + column;
      --row;
      ++column;
      --remaining;
      *(byte *)(matrix + offset) = 1;
    } while (remaining != 0);
  }
  uint retainedBuffer = (uint)buffer;
  frame.consumed = 0;
  if (count > 0) {
    frame.rowOffset = 0;
    column = 0;
    do {
      if ((int)column >= (int)side) {
        frame.rowOffset += side;
        column = 0;
      }
      uint cell = frame.rowOffset + column + matrix;
      if (*(byte *)cell != 0) {
        uint inputIndex = frame.consumed;
        retainedBuffer = (uint)buffer;
        byte value = *(byte *)(retainedBuffer + inputIndex);
        *(byte *)cell = value;
        frame.consumed = inputIndex + 1;
      }
      ++column;
    } while ((int)frame.consumed < count);
    retainedBuffer = (uint)buffer;
  }
  row = 0;
  column = 0;
  uint outputIndex = 0;
  if (count > 0) {
    do {
      if ((int)column >= (int)side) {
        column = row + 2;
        row = side - 1;
      } else if ((int)row < 0) {
        row = column;
        column = 0;
      }
      uint offset = row * side + column;
      --row;
      ++column;
      ++outputIndex;
      byte value = *(byte *)(matrix + offset);
      *(byte *)(retainedBuffer + outputIndex - 1) = value;
      count = byteCount;
    } while ((int)outputIndex < count);
  }
  XorBytesWithIndexMask((byte *)retainedBuffer,count);
  using FreeABI = uint (__stdcall *)(void *);
  return ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)matrix);
}

// XOR positive signed lengths with the low byte of index-0x77; cache the input pointer and count before writing.
// R6GameService.dll @ 10039440 : nonpositive counts access no buffer; native EAX is zero/count residue.
void __stdcall XorBytesWithIndexMask(byte *buffer,int byteCount)
{
  int count = byteCount;
  uint index = 0;
  if (count <= 0) return;
  uint first = (uint)buffer;
  do {
    byte value = *(byte *)(first + index);
    byte mask = (byte)(index - 0x77);
    *(byte *)(first + index) = value ^ mask;
    ++index;
  } while ((int)index < count);
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
