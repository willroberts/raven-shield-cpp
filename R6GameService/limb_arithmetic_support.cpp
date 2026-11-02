#include "native_addresses.h"

// Native limb arithmetic helpers; concrete class ownership remains unassigned.

// Clears words forward; a zero count retains incoming EAX and never reads destination.
// R6GameService.dll @ 1003e240 : destination/count stack words, RET8; EDX retained for the bit-setting caller.
__declspec(naked) uint __thiscall ClearLimbWords(void *unusedContext,uint *destination,uint limbCount)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    test   ecx,ecx
    jbe limbs_cleared
    push   edi
    mov    edi,DWORD PTR [esp+0x8]
    xor    eax,eax
    rep stos DWORD PTR es:[edi],eax
    pop    edi
  limbs_cleared:
    ret    0x8
  }
}

// Clears the cached destination, then reloads the bit index and sets it only below the wrapped bit capacity.
// R6GameService.dll @ 1003e260 : destination/index/count stack words, RET0x0c; EAX=index or index/32.
__declspec(naked) uint __thiscall SetSingleLimbBit(
    void *unusedContext,uint *destination,uint bitIndex,uint limbCount)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edx
    push   esi
    call   R6GameServiceAddresses::ClearLimbWords
    mov    eax,DWORD PTR [esp+0xc]
    shl    edx,0x5
    cmp    eax,edx
    jae single_bit_complete
    mov    ecx,eax
    mov    edx,0x1
    and    ecx,0x1f
    shl    edx,cl
    shr    eax,0x5
    mov    DWORD PTR [esi+eax*4],edx
  single_bit_complete:
    pop    esi
    ret    0xc
  }
}

// Adds left+carry before loading right, preserving the native carry-overflow shortcut and forward overlap order.
// R6GameService.dll @ 1003e2a0 : ECX ignored, destination/left/right/count stack words, RET0x10; full EAX carry0/1.
uint __thiscall AddLimbWords(void *unusedContext,uint *destination,const uint *left,
    const uint *right,uint limbCount)
{
  uint count = limbCount;
  uint carry = 0;
  uint *output = destination;
  const uint *leftWord = left;
  const uint *rightWord = right;
  while (count != 0) {
    uint partial = *leftWord + carry;
    uint value;
    if (partial < carry) {
      value = *rightWord; // Left+carry wrapped; the incoming carry remains1.
    } else {
      uint rightValue = *rightWord;
      value = partial + rightValue;
      carry = value < rightValue;
    }
    *output = value;
    ++rightWord;
    ++leftWord;
    ++output;
    --count;
  }
  return carry;
}

// Subtracts borrow before reading right and preserves the native underflow shortcut and final borrow word.
// R6GameService.dll @ 1003e2f0 : ECX ignored, destination/left/right/count stack words, RET0x10; full EAX borrow0/1.
uint __thiscall SubtractLimbWords(void *unusedContext,uint *destination,const uint *left,
    const uint *right,uint limbCount)
{
  uint count = limbCount;
  uint borrow = 0;
  uint *output = destination;
  const uint *leftWord = left;
  const uint *rightWord = right;
  while (count != 0) {
    uint partial = *leftWord - borrow;
    uint value;
    if (partial > ~borrow) {
      value = ~*rightWord; // Left-borrow wrapped; the incoming borrow remains1.
    } else {
      uint rightValue = *rightWord;
      value = partial - rightValue;
      borrow = ~rightValue < value;
    }
    *output = value;
    ++rightWord;
    ++leftWord;
    ++output;
    --count;
  }
  return borrow;
}

// Shifts low limbs forward; the incoming shift word becomes a mutable loop count and the saved ECX word holds32-shift.
// R6GameService.dll @ 1003e410 : four stack words, RET0x10; EAX=high carry, ECX restored from EntryESP-4.
__declspec(naked) uint __thiscall ShiftLimbWordsLeft(
    void *unusedContext,uint *destination,const uint *source,uint shift,uint limbCount)
{
  __asm {
    push   ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    cmp    edi,0x20
    jb left_shift_valid
    xor    eax,eax
    pop    edi
    pop    ecx
    ret    0x10
  left_shift_valid:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,0x20
    sub    eax,edi
    mov    DWORD PTR [esp+0x4],eax
    xor    eax,eax
    test   ecx,ecx
    jbe left_shift_complete
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x20],ecx
    sub    ebx,esi
  left_shift_next_word:
    mov    edx,DWORD PTR [ebx+esi*1]
    mov    ecx,edi
    mov    ebp,edx
    shl    ebp,cl
    or     ebp,eax
    test   edi,edi
    mov    DWORD PTR [esi],ebp
    je left_shift_zero_carry
    mov    ecx,DWORD PTR [esp+0x10]
    shr    edx,cl
    mov    eax,edx
    jmp left_shift_advance
  left_shift_zero_carry:
    xor    eax,eax
  left_shift_advance:
    mov    ecx,DWORD PTR [esp+0x20]
    add    esi,0x4
    dec    ecx
    mov    DWORD PTR [esp+0x20],ecx
    jne left_shift_next_word
    pop    esi
    pop    ebp
    pop    ebx
  left_shift_complete:
    pop    edi
    pop    ecx
    ret    0x10
  }
}

// Shifts high limbs backward after a signed count-1 guard, reusing the incoming shift word as the loop count.
// R6GameService.dll @ 1003e480 : four stack words, RET0x10; EAX=low carry, saved-ECX slot holds32-shift.
__declspec(naked) uint __thiscall ShiftLimbWordsRight(
    void *unusedContext,uint *destination,const uint *source,uint shift,uint limbCount)
{
  __asm {
    push   ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    cmp    edi,0x20
    jb right_shift_valid
    xor    eax,eax
    pop    edi
    pop    ecx
    ret    0x10
  right_shift_valid:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,0x20
    sub    eax,edi
    mov    DWORD PTR [esp+0x4],eax
    xor    eax,eax
    dec    ecx
    test   ecx,ecx
    jl right_shift_complete
    mov    edx,DWORD PTR [esp+0xc]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    push   esi
    lea    esi,[edx+ecx*4]
    sub    ebx,edx
    inc    ecx
    mov    DWORD PTR [esp+0x20],ecx
  right_shift_next_word:
    mov    edx,DWORD PTR [ebx+esi*1]
    mov    ecx,edi
    mov    ebp,edx
    shr    ebp,cl
    or     ebp,eax
    test   edi,edi
    mov    DWORD PTR [esi],ebp
    je right_shift_zero_carry
    mov    ecx,DWORD PTR [esp+0x10]
    shl    edx,cl
    mov    eax,edx
    jmp right_shift_advance
  right_shift_zero_carry:
    xor    eax,eax
  right_shift_advance:
    mov    ecx,DWORD PTR [esp+0x20]
    sub    esi,0x4
    dec    ecx
    mov    DWORD PTR [esp+0x20],ecx
    jne right_shift_next_word
    pop    esi
    pop    ebp
    pop    ebx
  right_shift_complete:
    pop    edi
    pop    ecx
    ret    0x10
  }
}

struct LimbMultiplicationFrame {
  uint leftRemaining; // EntryESP-0x114, reused as the mutable product-loop count.
  uint rightSignificant; // EntryESP-0x110.
  uint productCount; // EntryESP-0x10c, saved wrapped2*limbCount.
  uint product[66]; // EntryESP-0x108, cleared only to the requested product width.
};

// Accumulates shifted word products into contiguous scratch, then copies the requested product words forward.
// R6GameService.dll @ 1003e350 : four stack words, RET0x10; raw CopyLimbWords EAX, no guard or scratch wiping.
uint __thiscall MultiplyLimbArrays(void *mathContext,uint *destination,const uint *left,
    const uint *right,uint limbCount)
{
  LimbMultiplicationFrame frame;
  uint count = limbCount;
  uint outputCount = count * 2U;
  frame.productCount = outputCount;
  ClearLimbWords(mathContext,frame.product,outputCount);
  const uint *leftArgument = left;
  uint leftCount = CountSignificantLimbs(mathContext,leftArgument,count);
  const uint *rightArgument = right;
  frame.leftRemaining = leftCount;
  uint rightCount = CountSignificantLimbs(mathContext,rightArgument,count);
  frame.rightSignificant = rightCount;
  uint eaxBeforeCopy = rightCount;
  if (frame.leftRemaining != 0) {
    uint *shiftedProduct = frame.product;
    uint *carryWord = frame.product + rightCount;
    do {
      uint rightWidth = frame.rightSignificant;
      rightArgument = right; // The right input argument reloads for every word product.
      uint multiplier = *leftArgument;
      uint carry = MultiplyAddLimbWordsByWord(mathContext,shiftedProduct,shiftedProduct,
          multiplier,rightArgument,rightWidth);
      uint oldCarryWord = *carryWord;
      ++shiftedProduct;
      *carryWord = oldCarryWord + carry;
      ++carryWord;
      ++leftArgument;
      --frame.leftRemaining;
    } while (frame.leftRemaining != 0);
    outputCount = frame.productCount;
    eaxBeforeCopy = 0;
  }
  uint *destinationArgument = destination;
  uint copyResult = CopyLimbWords(mathContext,destinationArgument,frame.product,outputCount);
  return outputCount == 0 ? eaxBeforeCopy : copyResult;
}

struct LimbDivisionFrame {
  uint quotientEstimate; // EntryESP-0x1a4.
  uint normalizedTop; // EntryESP-0x1a0.
  uint positionsRemaining; // EntryESP-0x19c.
  uint quotientOffset; // EntryESP-0x198, byte difference from normalizedDividend to quotient.
  uint normalizationShift; // EntryESP-0x194.
  uint normalizedDivisor[33]; // EntryESP-0x190.
  uint normalizedDividend[67]; // EntryESP-0x10c, including the shifted dividend's carry word.
};

// Divides normalized limb windows, corrects quotient estimates upward, then clears and denormalizes the remainder.
// R6GameService.dll @ 1003e4f0 : six stack words, RET0x18; EAX0 for zero divisor, otherwise raw right-shift carry.
uint __thiscall DivideLimbArrays(void *mathContext,uint *quotient,uint *remainder,
    const uint *dividend,uint dividendLimbCount,const uint *divisor,uint divisorLimbCount)
{
  LimbDivisionFrame frame;
  const uint *divisorArgument = divisor;
  uint divisorCount = CountSignificantLimbs(mathContext,divisorArgument,divisorLimbCount);
  if (divisorCount == 0) return 0;
  uint topBits = BitLength(mathContext,divisorArgument[divisorCount - 1]);
  uint normalization = 32U - topBits;
  frame.normalizationShift = normalization;
  ClearLimbWords(mathContext,frame.normalizedDividend,divisorCount);
  uint dividendCount = dividendLimbCount;
  const uint *dividendArgument = dividend;
  uint carry = ShiftLimbWordsLeft(mathContext,frame.normalizedDividend,
      dividendArgument,normalization,dividendCount);
  divisorArgument = divisor; // Reloaded after shifting the dividend, before storing its carry.
  frame.normalizedDividend[dividendCount] = carry;
  ShiftLimbWordsLeft(mathContext,frame.normalizedDivisor,divisorArgument,normalization,divisorCount);
  uint normalizedTop = frame.normalizedDivisor[divisorCount - 1];
  uint *quotientArgument = quotient;
  frame.normalizedTop = normalizedTop;
  ClearLimbWords(mathContext,quotientArgument,dividendCount);
  uint position = dividendCount - divisorCount;
  if ((int)position >= 0) {
    uint *window = (uint *)((uint)frame.normalizedDividend + position * 4U);
    uint *highWord = (uint *)((uint)frame.normalizedDividend + (position + divisorCount) * 4U);
    frame.quotientOffset = (uint)quotientArgument - (uint)frame.normalizedDividend; // Clear preserves native EDX.
    frame.positionsRemaining = position + 1;
    do {
      uint top = frame.normalizedTop;
      if (top == 0xffffffff) {
        frame.quotientEstimate = *highWord;
      } else {
        EstimateQuotientWordFromTwoWords(mathContext,&frame.quotientEstimate,highWord - 1,top + 1);
      }
      uint estimate = frame.quotientEstimate;
      uint borrow = MultiplySubtractLimbWordsByWord(mathContext,window,window,
          estimate,frame.normalizedDivisor,divisorCount);
      for (;;) {
        uint high = *highWord - borrow;
        *highWord = high;
        if (high == 0 && CompareLimbWords(mathContext,window,frame.normalizedDivisor,divisorCount) < 0) {
          break;
        }
        ++frame.quotientEstimate;
        borrow = SubtractLimbWords(mathContext,window,window,frame.normalizedDivisor,divisorCount);
      }
      uint quotientOffset = frame.quotientOffset;
      uint quotientWord = frame.quotientEstimate;
      --highWord;
      *(uint *)(quotientOffset + (uint)window) = quotientWord;
      --window;
      --frame.positionsRemaining;
    } while (frame.positionsRemaining != 0);
    normalization = frame.normalizationShift; // Reloaded only after the quotient loop ran.
  }
  uint remainderCount = divisorLimbCount;
  uint *remainderArgument = remainder;
  ClearLimbWords(mathContext,remainderArgument,remainderCount);
  return ShiftLimbWordsRight(mathContext,remainderArgument,
      frame.normalizedDividend,normalization,divisorCount); // The clear's EDX destination survives into this call.
}

// Supplies an unchecked66-word quotient scratch buffer and forwards the division's full native EAX.
// R6GameService.dll @ 1003e690 : five stack words, RET0x14; no initialization or wiping outside the division helper.
uint __thiscall ReduceLimbWordsModulo(void *mathContext,uint *remainder,const uint *dividend,
    uint dividendLimbCount,const uint *divisor,uint divisorLimbCount)
{
  uint divisorCount = divisorLimbCount;
  const uint *divisorArgument = divisor;
  uint quotientWords[66]; // EntryESP-0x108.
  uint dividendCount = dividendLimbCount;
  const uint *dividendArgument = dividend;
  uint *remainderArgument = remainder;
  return DivideLimbArrays(mathContext,quotientWords,remainderArgument,
      dividendArgument,dividendCount,divisorArgument,divisorCount);
}

// Multiplies into unchecked66-word scratch, reloads output/modulus arguments, then forwards the modular reduction EAX.
// R6GameService.dll @ 1003e6d0 : five stack words, RET0x14; original limb width cached across multiplication.
uint __thiscall MultiplyLimbWordsModulo(void *mathContext,uint *destination,const uint *left,
    const uint *right,const uint *modulus,uint limbCount)
{
  const uint *rightArgument = right;
  uint productWords[66]; // EntryESP-0x108.
  uint count = limbCount;
  const uint *leftArgument = left;
  MultiplyLimbArrays(mathContext,productWords,leftArgument,rightArgument,count);
  const uint *modulusArgument = modulus;
  uint *destinationArgument = destination;
  return ReduceLimbWordsModulo(mathContext,destinationArgument,productWords,
      count * 2U,modulusArgument,count);
}

// Counts bits through the highest set bit, returning zero for a zero word.
// R6GameService.dll @ 1003ed20 : ECX ignored on entry, value stack word, RET4; EAX0..32 and ECX0 on return.
uint __thiscall BitLength(void *unusedContext,uint value)
{
  uint remaining = value;
  uint bitCount = 0;
  while (remaining != 0 && bitCount < 32) {
    ++bitCount;
    remaining >>= 1;
  }
  return bitCount;
}

struct LimbWordProductFrame {
  void *savedContext; // EntryESP-0x0c in both multiply-add/subtract parents.
  uint product[2]; // EntryESP-8/-4, written in phases by the scalar multiply helper.
};

// Adds a word product using two destination stores per limb and argument-word offset/count reuse.
// R6GameService.dll @ 1003ebd0 : five stack words, RET0x14; full carry EAX, multiplier0 leaves destination untouched.
uint __thiscall MultiplyAddLimbWordsByWord(void *mathContext,uint *destination,
    const uint *addend,uint multiplier,const uint *multiplicand,uint limbCount)
{
  LimbWordProductFrame frame;
  frame.savedContext = mathContext;
  if (multiplier == 0) return 0;
  uint remaining = limbCount;
  uint carry = 0;
  if (remaining == 0) return 0;
  const uint *inputArgument = addend;
  const uint *multiplicandArgument = multiplicand;
  uint *output = destination;
  uint multiplicandOffset = (uint)multiplicandArgument - (uint)inputArgument;
  destination = (uint *)((uint)inputArgument - (uint)output); // Native EntryESP+4 now holds a byte offset.
  limbCount = remaining; // Native EntryESP+0x14 is the mutable loop count.
  do {
    uint multiplierArgument = multiplier;
    const uint *inputWord = (const uint *)((uint)destination + (uint)output);
    const uint *multiplicandWord = (const uint *)((uint)inputWord + multiplicandOffset);
    uint factor = *multiplicandWord;
    MultiplyWordsToDoubleWord(frame.savedContext,frame.product,multiplierArgument,factor);
    uint partial = *inputWord + carry;
    *output = partial;
    uint reloaded = *output;
    uint lowProduct = frame.product[0]; // Loaded after the first store, retaining product-frame aliases.
    uint firstCarry = partial < carry;
    uint result = reloaded + lowProduct;
    *output = result;
    carry = firstCarry;
    if (result < lowProduct) ++carry;
    uint highProduct = frame.product[1]; // Loaded after the second store.
    remaining = limbCount;
    carry += highProduct;
    ++output;
    limbCount = remaining - 1;
  } while (limbCount != 0);
  return carry;
}

// Subtracts a word product using two observable stores and late product/count loads for each destination limb.
// R6GameService.dll @ 1003ec70 : five stack words, RET0x14; full borrow EAX, multiplier0 leaves destination untouched.
uint __thiscall MultiplySubtractLimbWordsByWord(void *mathContext,uint *destination,
    const uint *minuend,uint multiplier,const uint *multiplicand,uint limbCount)
{
  LimbWordProductFrame frame;
  frame.savedContext = mathContext;
  if (multiplier == 0) return 0;
  uint remaining = limbCount;
  uint borrow = 0;
  if (remaining == 0) return 0;
  const uint *inputArgument = minuend;
  const uint *multiplicandArgument = multiplicand;
  uint *output = destination;
  uint multiplicandOffset = (uint)multiplicandArgument - (uint)inputArgument;
  destination = (uint *)((uint)inputArgument - (uint)output);
  limbCount = remaining;
  do {
    uint multiplierArgument = multiplier;
    const uint *inputWord = (const uint *)((uint)destination + (uint)output);
    const uint *multiplicandWord = (const uint *)((uint)inputWord + multiplicandOffset);
    uint factor = *multiplicandWord;
    MultiplyWordsToDoubleWord(frame.savedContext,frame.product,multiplierArgument,factor);
    uint partial = *inputWord - borrow;
    uint firstBorrow = ~borrow < partial;
    *output = partial;
    uint lowProduct = frame.product[0];
    uint reloaded = *output;
    uint result = reloaded - lowProduct;
    borrow = firstBorrow;
    *output = result;
    if (result > ~lowProduct) ++borrow;
    uint highProduct = frame.product[1];
    remaining = limbCount;
    borrow += highProduct;
    ++output;
    limbCount = remaining - 1;
  } while (limbCount != 0);
  return borrow;
}

// Forms an unsigned product from16-bit partial products, preserving every native low/high correction store.
// R6GameService.dll @ 1003ed40 : ECX unused, result/left/right stack words, RET0x0c; EAX=cross sum>>16.
uint __thiscall MultiplyWordsToDoubleWord(void *unusedContext,uint *result,uint left,uint right)
{
  uint leftHigh = left >> 16;
  uint leftLow = left & 0xffff;
  uint rightHigh = right >> 16;
  uint rightLow = right & 0xffff;
  uint lowProduct = leftLow * rightLow;
  uint rightLowCross = rightLow * leftHigh;
  uint leftLowCross = leftLow * rightHigh;
  uint *output = result;
  uint highProduct = rightHigh * leftHigh;
  uint crossSum = leftLowCross + rightLowCross;
  output[0] = lowProduct;
  output[1] = highProduct;
  if (crossSum < rightLowCross) {
    highProduct += 0x10000;
    output[1] = highProduct;
  }
  uint shiftedCross = crossSum << 16;
  uint lowWord = lowProduct + shiftedCross;
  output[0] = lowWord;
  if (lowWord < shiftedCross) ++output[1];
  uint highWord = output[1];
  uint upperCross = crossSum >> 16;
  output[1] = highWord + upperCross;
  return upperCross;
}

struct LimbQuotientFrame {
  uint upperProduct; // EntryESP-8.
  uint divisorHigh; // EntryESP-4, low16 bits tested again before the lower quotient estimate.
};

// Computes two corrected quotient halves, retaining argument-word reuse and the native zero-divisor loop behavior.
// R6GameService.dll @ 1003edc0 : three stack words, RET0x0c; full EAX=late-loaded quotient destination pointer.
uint __thiscall EstimateQuotientWordFromTwoWords(void *unusedContext,uint *quotient,
    const uint *dividendWords,uint divisor)
{
  LimbQuotientFrame frame;
  const uint *input = dividendWords;
  uint divisorArgument = divisor;
  uint remainderHigh = input[1];
  uint remainderLow = input[0];
  uint divisorHigh = divisorArgument >> 16;
  frame.divisorHigh = divisorHigh;
  uint upper = divisorHigh == 0xffff ? remainderHigh >> 16 : remainderHigh / (divisorHigh + 1);
  dividendWords = (const uint *)upper; // Native EntryESP+8 is now the upper quotient estimate, not an input pointer.
  uint divisorLow = divisorArgument & 0xffff;
  uint maskedUpper = upper & 0xffff;
  uint product = divisorLow * maskedUpper;
  frame.upperProduct = maskedUpper * divisorHigh;
  uint shifted = product << 16;
  remainderLow -= shifted;
  if (remainderLow > ~shifted) --remainderHigh;
  remainderHigh -= (product >> 16) + frame.upperProduct;
  while (remainderHigh > divisorHigh ||
      (remainderHigh == divisorHigh && remainderLow >= (divisorLow << 16))) {
    shifted = divisorLow << 16;
    remainderLow -= shifted;
    if (remainderLow > ~shifted) --remainderHigh;
    remainderHigh -= divisorHigh;
    dividendWords = (const uint *)((uint)dividendWords + 1);
  }
  uint lower;
  if ((frame.divisorHigh & 0xffff) == 0xffff) {
    lower = remainderHigh;
  } else {
    uint numerator = (remainderLow >> 16) + (remainderHigh << 16);
    lower = numerator / (divisorHigh + 1);
  }
  uint maskedLower = lower & 0xffff;
  uint lowProduct = divisorLow * maskedLower;
  uint highProduct = maskedLower * divisorHigh;
  remainderLow -= lowProduct;
  if (remainderLow > ~lowProduct) --remainderHigh;
  shifted = highProduct << 16;
  remainderLow -= shifted;
  if (remainderLow > ~shifted) --remainderHigh;
  remainderHigh -= highProduct >> 16;
  for (;;) {
    uint currentDivisor = divisor; // Reloaded from the original divisor argument on every correction.
    if (remainderHigh == 0 && remainderLow < currentDivisor) break;
    remainderLow -= currentDivisor;
    if (remainderLow > ~currentDivisor) --remainderHigh;
    ++lower;
  }
  uint upperHalf = (uint)dividendWords & 0xffff;
  uint result = (upperHalf << 16) + (lower & 0xffff);
  uint *destinationArgument = quotient; // Native pointer load is after both correction loops.
  *destinationArgument = result;
  return (uint)destinationArgument;
}

// Compares cached left/right limbs once each, descending from the signed wrapped last index.
// R6GameService.dll @ 1003eb30 : ECX ignored, left/right/count stack words, RET0x0c; full EAX=-1/0/1.
int __thiscall CompareLimbWords(void *unusedContext,const uint *left,const uint *right,uint limbCount)
{
  uint index = limbCount - 1;
  if ((int)index < 0) return 0;
  const uint *rightArgument = right;
  const uint *leftArgument = left;
  do {
    uint leftWord = leftArgument[index];
    uint rightWord = rightArgument[index];
    if (leftWord > rightWord) return 1;
    if (leftWord < rightWord) return -1;
    --index;
  } while ((int)index >= 0);
  return 0;
}

// Tests cached-width limbs in ascending order and treats an empty range as zero.
// R6GameService.dll @ 1003eb80 : ECX ignored, limbs/count stack words, RET8; full EAX0/1.
uint __thiscall AreLimbWordsZero(void *unusedContext,const uint *limbs,uint limbCount)
{
  uint count = limbCount;
  if (count == 0) return 1;
  const uint *input = limbs;
  for (uint index = 0; index < count; ++index) {
    if (input[index] != 0) return 0;
  }
  return 1;
}

// Skips high zero limbs with a signed wrapped index, retaining the original width when that index starts negative.
// R6GameService.dll @ 1003ebb0 : ECX ignored, limbs/count stack words, RET8; full EAX width, no buffer read on skip.
uint __thiscall CountSignificantLimbs(void *unusedContext,const uint *limbs,uint limbCount)
{
  uint index = limbCount - 1;
  if ((int)index < 0) return index + 1;
  const uint *input = limbs;
  while (input[index] == 0) {
    --index;
    if ((int)index < 0) break;
  }
  return index + 1;
}

struct LimbExponentiationFrame {
  uint windowsRemaining; // EntryESP-0x21c.
  uint currentLimb; // EntryESP-0x218.
  uint highestLimb; // EntryESP-0x214.
  uint accumulator[33]; // EntryESP-0x210.
  uint power1[33]; // EntryESP-0x18c, not reduced before the first window multiply.
  uint power2[33]; // EntryESP-0x108.
  uint power3[33]; // EntryESP-0x84.
};

// Raises by two-bit windows after precomputing three powers; zero exponent copies the unreduced accumulator value1.
// R6GameService.dll @ 1003e730 : six stack words, RET0x18; raw final-copy EAX, no modulus or width validation.
uint __thiscall ModularExponentiateLimbWords(void *mathContext,uint *result,const uint *base,
    const uint *exponent,uint exponentLimbCount,const uint *modulus,uint modulusLimbCount)
{
  LimbExponentiationFrame frame;
  const uint *baseArgument = base;
  uint count = modulusLimbCount;
  CopyLimbWords(mathContext,frame.power1,baseArgument,count);
  const uint *modulusArgument = modulus; // Loaded after the base copy, then cached across every modular product.
  MultiplyLimbWordsModulo(mathContext,frame.power2,frame.power1,baseArgument,modulusArgument,count);
  MultiplyLimbWordsModulo(mathContext,frame.power3,frame.power2,baseArgument,modulusArgument,count);
  ClearLimbWords(mathContext,frame.accumulator,count);
  uint exponentCount = exponentLimbCount;
  const uint *exponentArgument = exponent;
  frame.accumulator[0] = 1;
  uint significant = CountSignificantLimbs(mathContext,exponentArgument,exponentCount);
  uint highest = significant - 1;
  uint current = highest;
  frame.highestLimb = highest;
  frame.currentLimb = current;
  if ((int)current >= 0) {
    do {
      exponentArgument = exponent; // Original exponent pointer reloads per limb, after precomputation.
      uint word = exponentArgument[current];
      uint bitsRemaining = 32;
      if (current == highest && (word & 0xc0000000) == 0) {
        do {
          word <<= 2;
          bitsRemaining -= 2;
        } while ((word & 0xc0000000) == 0); // A zero top word retains the native endless leading-window scan.
      }
      if (bitsRemaining != 0) {
        frame.windowsRemaining = ((bitsRemaining - 1) >> 1) + 1;
        do {
          MultiplyLimbWordsModulo(mathContext,frame.accumulator,frame.accumulator,
              frame.accumulator,modulusArgument,count);
          MultiplyLimbWordsModulo(mathContext,frame.accumulator,frame.accumulator,
              frame.accumulator,modulusArgument,count);
          uint window = word >> 30;
          if (window != 0) {
            const uint *power = (const uint *)((uint)frame.accumulator + window * 33U * 4U);
            MultiplyLimbWordsModulo(mathContext,frame.accumulator,frame.accumulator,power,
                modulusArgument,count);
          }
          uint windows = frame.windowsRemaining;
          word <<= 2;
          frame.windowsRemaining = windows - 1;
        } while (frame.windowsRemaining != 0);
        current = frame.currentLimb;
        highest = frame.highestLimb;
      }
      --current;
      frame.currentLimb = current;
    } while ((int)current >= 0);
  }
  uint *destinationArgument = result;
  uint copied = CopyLimbWords(mathContext,destinationArgument,frame.accumulator,count);
  return count == 0 ? (uint)destinationArgument : copied; // Empty native copy retains the destination in EAX.
}

struct LimbInverseFrame {
  uint previousCoefficient[33]; // EntryESP-0x4a4.
  uint currentRemainder[33]; // EntryESP-0x420.
  uint currentCoefficient[33]; // EntryESP-0x39c.
  uint previousRemainder[33]; // EntryESP-0x318.
  uint nextCoefficient[33]; // EntryESP-0x294.
  uint divisionRemainder[33]; // EntryESP-0x210.
  uint quotient[33]; // EntryESP-0x18c.
  uint product[66]; // EntryESP-0x108, only its low count words contribute to the coefficient sum.
};

// Builds a signed Euclidean coefficient and adjusts it once by the cached modulus, without testing for a unit GCD.
// R6GameService.dll @ 1003e8b0 : four stack words, RET0x10; raw subtract/copy EAX, unchecked coefficient truncation.
uint __thiscall ModularInverseLimbWords(void *mathContext,uint *result,const uint *value,
    const uint *modulus,uint limbCount)
{
  LimbInverseFrame frame;
  uint count = limbCount;
  ClearLimbWords(mathContext,frame.previousCoefficient,count);
  int sign = 1;
  frame.previousCoefficient[0] = 1;
  ClearLimbWords(mathContext,frame.currentCoefficient,count);
  const uint *valueArgument = value;
  CopyLimbWords(mathContext,frame.previousRemainder,valueArgument,count);
  const uint *modulusArgument = modulus; // Cached after copying value, including for the final negative adjustment.
  CopyLimbWords(mathContext,frame.currentRemainder,modulusArgument,count);
  uint isZero = AreLimbWordsZero(mathContext,frame.currentRemainder,count);
  while (isZero == 0) {
    DivideLimbArrays(mathContext,frame.quotient,frame.divisionRemainder,
        frame.previousRemainder,count,frame.currentRemainder,count);
    MultiplyLimbArrays(mathContext,frame.product,frame.quotient,frame.currentCoefficient,count);
    AddLimbWords(mathContext,frame.nextCoefficient,frame.previousCoefficient,frame.product,count);
    CopyLimbWords(mathContext,frame.previousCoefficient,frame.currentCoefficient,count);
    CopyLimbWords(mathContext,frame.currentCoefficient,frame.nextCoefficient,count);
    CopyLimbWords(mathContext,frame.previousRemainder,frame.currentRemainder,count);
    CopyLimbWords(mathContext,frame.currentRemainder,frame.divisionRemainder,count);
    sign = -sign;
    isZero = AreLimbWordsZero(mathContext,frame.currentRemainder,count);
  }
  uint *destinationArgument = result;
  if (sign < 0) {
    return SubtractLimbWords(mathContext,destinationArgument,modulusArgument,frame.previousCoefficient,count);
  }
  uint copied = CopyLimbWords(mathContext,destinationArgument,frame.previousCoefficient,count);
  return count == 0 ? (uint)frame.previousCoefficient : copied; // Empty copy retains the scratch address in EAX.
}

struct LimbGCDFrame {
  uint rightRemainder[33]; // EntryESP-0x18c.
  uint leftRemainder[33]; // EntryESP-0x108.
  uint nextRemainder[33]; // EntryESP-0x84.
};

// Applies Euclid's remainder sequence using ordered forward copies, then returns the final copy's native EAX.
// R6GameService.dll @ 1003ea60 : four stack words, RET0x10; zero width leaves output untouched and returns full1.
uint __thiscall GreatestCommonDivisorLimbWords(void *mathContext,uint *result,const uint *left,
    const uint *right,uint limbCount)
{
  const uint *leftArgument = left;
  LimbGCDFrame frame;
  uint count = limbCount;
  CopyLimbWords(mathContext,frame.leftRemainder,leftArgument,count);
  const uint *rightArgument = right;
  CopyLimbWords(mathContext,frame.rightRemainder,rightArgument,count);
  uint isZero = AreLimbWordsZero(mathContext,frame.rightRemainder,count);
  while (isZero == 0) {
    ReduceLimbWordsModulo(mathContext,frame.nextRemainder,frame.leftRemainder,
        count,frame.rightRemainder,count);
    CopyLimbWords(mathContext,frame.leftRemainder,frame.rightRemainder,count);
    CopyLimbWords(mathContext,frame.rightRemainder,frame.nextRemainder,count);
    isZero = AreLimbWordsZero(mathContext,frame.rightRemainder,count);
  }
  uint *destinationArgument = result;
  uint copied = CopyLimbWords(mathContext,destinationArgument,frame.leftRemainder,count);
  return count == 0 ? 1 : copied;
}
