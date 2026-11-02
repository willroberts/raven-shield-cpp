#include "native_addresses.h"

// Native byte/limb conversion and forward-copy helpers; their ECX math-context argument is unused.

// Packs descending input bytes into ascending limbs, discarding excess high bytes and clearing unused limb words.
// R6GameService.dll @ 1003e140 : four stack words, RET0x10; EAX is remaining byte index or0 after trailing-word fill.
uint __thiscall DecodeBigEndianLimbs(void *unusedContext,uint *destination,uint limbCount,
    const byte *input,uint inputBytes)
{
  uint byteIndex = inputBytes - 1;
  uint capacity = limbCount;
  uint limbIndex = 0;
  if (capacity == 0) return byteIndex;
  const byte *inputArgument = input;
  while ((int)byteIndex >= 0) {
    uint limb = 0;
    for (uint shift = 0; shift < 32 && (int)byteIndex >= 0; shift += 8) {
      limb |= (uint)inputArgument[byteIndex] << shift;
      --byteIndex;
    }
    uint *destinationArgument = destination; // Reloaded after each packed limb, before its store.
    destinationArgument[limbIndex++] = limb;
    if (limbIndex >= capacity) return byteIndex;
  }
  if (limbIndex < capacity) {
    uint *remaining = destination + limbIndex;
    for (uint count = capacity - limbIndex; count != 0; --count) *remaining++ = 0;
    return 0;
  }
  return byteIndex;
}

// Writes limbs into descending output bytes and zero-fills the prefix, preserving the native exhausted-index return.
// R6GameService.dll @ 1003e1b0 : four stack words, RET0x10; the bound and limb-source arguments reload per limb.
uint __thiscall EncodeBigEndianLimbs(void *unusedContext,byte *output,uint outputBytes,
    const uint *limbs,uint limbCount)
{
  uint byteIndex = outputBytes - 1;
  uint bound = limbCount;
  uint limbIndex = 0;
  byte *outputArgument = output;
  if (bound != 0) {
    do {
      if ((int)byteIndex < 0) return byteIndex;
      const uint *limbsArgument = limbs;
      uint limb = limbsArgument[limbIndex];
      for (uint shift = 0; shift < 32 && (int)byteIndex >= 0; shift += 8) {
        uint destinationIndex = byteIndex--;
        outputArgument[destinationIndex] = (byte)(limb >> shift);
      }
      bound = limbCount;
      ++limbIndex;
    } while (limbIndex < bound);
  }
  while ((int)byteIndex >= 0) outputArgument[byteIndex--] = 0;
  return byteIndex;
}

// Copies limbs forward; a zero count preserves incoming EAX, otherwise EAX finishes just beyond the destination.
// R6GameService.dll @ 1003e210 : ECX unused, destination/source/count stack words, RET0x0c; ESI preserved.
__declspec(naked) uint __thiscall CopyLimbWords(
    void *unusedContext,uint *destination,const uint *source,uint limbCount)
{
  __asm {
    mov    edx,dword ptr [esp+0xc]
    test   edx,edx
    jbe    limbs_copied
    mov    eax,dword ptr [esp+4]
    mov    ecx,dword ptr [esp+8]
    sub    ecx,eax
    push   esi
  copy_next_limb:
    mov    esi,dword ptr [ecx+eax]
    mov    dword ptr [eax],esi
    add    eax,4
    dec    edx
    jnz    copy_next_limb
    pop    esi
  limbs_copied:
    ret    0xc
  }
}
