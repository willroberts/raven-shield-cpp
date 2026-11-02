#include "native_addresses.h"
#include "native_records.h"

// Identified native class: RSA, COL10079858/type1008fde4, primary table10077ab4.
// Its deleting slot shares1003ce90 with CGSXor; the single canonical body remains in shared_native.cpp.

// Installs the RSA table and optional virtual-base pointer, leaving the third object word untouched.
// R6GameService.dll @ 1003ce60 : ECX owner, flag stack word, RET4; EAX=owner, ECX=0 on normal return.
__declspec(naked) void * __thiscall ConstructRSA(void *owner,uint initializeBase)
{
  __asm {
    push   ecx
    mov    eax,ecx
    mov    ecx,dword ptr [esp+8]
    test   ecx,ecx
    mov    dword ptr [esp+0x0],0
    mov    dword ptr [eax],R6GameServiceAddresses::RSAVTable
    jz     rsa_constructed
    mov    dword ptr [eax+4],0x10077aa8
  rsa_constructed:
    pop    ecx
    ret    4
  }
}

// Sets the seed requirement to256 and clears only the next five words, retaining state words6..9.
// R6GameService.dll @ 1003daa0 : ECX context unused, state stack word, RET4; full EAX=0.
uint __thiscall InitializeRSARandomState(void *unusedContext,uint *state)
{
  state[0] = 0x100;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  state[5] = 0;
  return 0;
}

// Clears all ten words of the caller-supplied random state, preserving the receiver's storage.
// R6GameService.dll @ 1003dad0 : ECX context unused, state stack word, RET4; EAX=0/ECX=0 after REP STOSD.
uint __thiscall ClearRSARandomState(void *unusedContext,uint *state)
{
  for (uint index = 0; index != 10; ++index) state[index] = 0;
  return 0;
}

// Copies the current seed-byte requirement to the supplied output word, retaining the native load/store order.
// R6GameService.dll @ 1003dc40 : ECX context unused, output/state stack words, RET8; full EAX=0.
uint __thiscall ReadRSASeedBytesNeeded(
    void *unusedContext,uint *bytesNeeded,const uint *state)
{
  *bytesNeeded = *state;
  return 0;
}

struct RSAType2EncodeFrame {
  byte unusedPrefix[3];
  byte candidate; // EntryESP-0x81, deliberately uninitialized before random generation.
  byte block[128]; // EntryESP-0x80.
};

struct RSAType1EncodeFrame {
  void *savedReceiver; // EntryESP-0x84.
  byte block[128]; // EntryESP-0x80, unchecked native block capacity.
};

struct RSADecodeFrame {
  uint transformedBytes; // EntryESP-0x84, written by the underlying transform.
  byte block[128]; // EntryESP-0x80.
};

// Builds type2 nonzero-random padding, ignores generator status and returns the public transform's raw EAX.
// R6GameService.dll @ 1003d260 : ECX receiver, six stack words, RET0x18; rejection clears only AL of output address.
uint __thiscall EncodeType2CryptoBlock(void *innerContext,const byte *input,uint inputBytes,
    byte *output,uint *outputBytes,const uint *keyWords,uint *randomState)
{
  RSAType2EncodeFrame frame;
  uint modulusBytes = (keyWords[0] + 7U) >> 3;
  uint result = (uint)output;
  if (output == 0 || *outputBytes != modulusBytes) {
    *outputBytes = modulusBytes;
    return result & 0xffffff00;
  }
  uint copyLength = inputBytes;
  if (copyLength + 11U > modulusBytes) return result & 0xffffff00;
  uint paddingEnd = modulusBytes - copyLength - 1;
  uint paddingIndex = 2;
  frame.block[0] = 0;
  frame.block[1] = 2;
  if (paddingEnd > paddingIndex) {
    do {
      do {
        GenerateCryptoRandomBytes(innerContext,&frame.candidate,1,randomState);
      } while (frame.candidate == 0);
      frame.block[paddingIndex++] = frame.candidate;
    } while (paddingIndex < paddingEnd);
    copyLength = inputBytes; // Native reload follows the generator calls.
  }
  const byte *source = input;
  frame.block[paddingIndex] = 0;
  byte *destination = frame.block + paddingIndex + 1;
  for (uint offset = 0; offset < (copyLength & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  uint *sizeArgument = outputBytes; // Captured before the residual byte copy.
  for (uint offset = copyLength & ~3U; offset < copyLength; ++offset) destination[offset] = source[offset];
  return ApplyRsaPublicKeyTransform(
      innerContext,output,sizeArgument,frame.block,modulusBytes,keyWords);
}

// Builds type1 ff padding with DWORD/byte fills, then forwards the complete padded block to the private transform.
// R6GameService.dll @ 1003d360 : ECX receiver, five stack words, RET0x14; rejection clears only AL of output address.
uint __thiscall EncodeType1CryptoBlock(void *innerContext,const byte *input,uint inputBytes,
    byte *output,uint *outputBytes,const uint *keyWords)
{
  RSAType1EncodeFrame frame;
  uint *sizeArgument = outputBytes;
  uint modulusBytes = (keyWords[0] + 7U) >> 3;
  uint result = (uint)output;
  frame.savedReceiver = innerContext;
  if (output == 0 || *sizeArgument != modulusBytes) {
    *sizeArgument = modulusBytes;
    return result & 0xffffff00;
  }
  uint copyLength = inputBytes;
  if (copyLength + 11U > modulusBytes) return result & 0xffffff00;
  uint paddingEnd = modulusBytes - copyLength - 1;
  uint separatorIndex = 2;
  frame.block[0] = 0;
  frame.block[1] = 1;
  if (paddingEnd > 2) {
    uint paddingBytes = paddingEnd - 2;
    byte *padding = frame.block + 2;
    for (uint offset = 0; offset < (paddingBytes & ~3U); offset += 4) *(uint *)(padding + offset) = 0xffffffff;
    sizeArgument = outputBytes; // Native reload occurs between DWORD and residual ff stores.
    for (uint offset = paddingBytes & ~3U; offset < paddingBytes; ++offset) padding[offset] = 0xff;
    separatorIndex = paddingBytes + 2;
  }
  const byte *source = input;
  frame.block[separatorIndex] = 0;
  byte *destination = frame.block + separatorIndex + 1;
  for (uint offset = 0; offset < (copyLength & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  uint *outputArgument = (uint *)output;
  for (uint offset = copyLength & ~3U; offset < copyLength; ++offset) destination[offset] = source[offset];
  return ApplyRsaPrivateKeyTransform(
      frame.savedReceiver,(byte *)outputArgument,sizeArgument,frame.block,modulusBytes,keyWords);
}

// Decodes type1 padding, publishing the derived output count before checking its minimum padding length.
// R6GameService.dll @ 1003d450 : ECX receiver, five stack words, RET0x14; pointer/index/count EAX residues retained.
uint __thiscall DecodeType1CryptoBlock(void *innerContext,const byte *input,uint inputBytes,
    byte *output,uint *outputBytes,const uint *keyWords)
{
  RSADecodeFrame frame;
  uint result = (uint)keyWords;
  uint *sizeArgument = outputBytes;
  uint modulusBytes = (keyWords[0] + 7U) >> 3;
  byte *destination = output;
  if (destination == 0 || *sizeArgument != modulusBytes) {
    *sizeArgument = modulusBytes;
    return result & 0xffffff00;
  }
  if (inputBytes > modulusBytes) return result & 0xffffff00;
  result = ApplyRsaPublicKeyTransform(
      innerContext,frame.block,&frame.transformedBytes,input,inputBytes,keyWords);
  if ((byte)result == 0 || frame.transformedBytes != modulusBytes) return result & 0xffffff00;
  result = (result & 0xffffff00) | frame.block[0];
  if ((byte)result != 0 || frame.block[1] != 1) return result & 0xffffff00;
  result = 2;
  uint lastIndex = modulusBytes - 1;
  if (lastIndex > result) {
    do {
      if (frame.block[result] != 0xff) break;
      ++result;
    } while (result < lastIndex);
  }
  byte separator = frame.block[result];
  ++result;
  if (separator != 0) return result & 0xffffff00;
  uint payloadBytes = modulusBytes - result;
  *sizeArgument = payloadBytes;
  if (payloadBytes + 11U > modulusBytes) return result & 0xffffff00;
  const byte *source = frame.block + result;
  result = payloadBytes;
  for (uint offset = 0; offset < (payloadBytes & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  result = (result & 0xffffff00) | 1;
  for (uint offset = payloadBytes & ~3U; offset < payloadBytes; ++offset) destination[offset] = source[offset];
  return result;
}

// Decodes type2 padding, requiring at least one payload byte and retaining the count write on short-padding failure.
// R6GameService.dll @ 1003d530 : ECX receiver, five stack words, RET0x14; pointer/index/count EAX residues retained.
uint __thiscall DecodeType2CryptoBlock(void *innerContext,const byte *input,uint inputBytes,
    byte *output,uint *outputBytes,const uint *keyWords)
{
  RSADecodeFrame frame;
  uint result = (uint)keyWords;
  uint *sizeArgument = outputBytes;
  uint modulusBytes = (keyWords[0] + 7U) >> 3;
  byte *destination = output;
  if (destination == 0 || *sizeArgument != modulusBytes) {
    *sizeArgument = modulusBytes;
    return result & 0xffffff00;
  }
  if (inputBytes > modulusBytes) return result & 0xffffff00;
  result = ApplyRsaPrivateKeyTransform(
      innerContext,frame.block,&frame.transformedBytes,input,inputBytes,keyWords);
  if ((byte)result == 0 || frame.transformedBytes != modulusBytes) return result & 0xffffff00;
  result = (result & 0xffffff00) | frame.block[0];
  if ((byte)result != 0) return result & 0xffffff00;
  result = 2;
  if (frame.block[1] != (byte)result) return result & 0xffffff00;
  uint lastIndex = modulusBytes - 1;
  if (lastIndex > result) {
    do {
      if (frame.block[result] == 0) break;
      ++result;
    } while (result < lastIndex);
  }
  ++result;
  if (result >= modulusBytes) return result & 0xffffff00;
  uint payloadBytes = modulusBytes - result;
  *sizeArgument = payloadBytes;
  if (payloadBytes + 11U > modulusBytes) return result & 0xffffff00;
  const byte *source = frame.block + result;
  result = payloadBytes;
  for (uint offset = 0; offset < (payloadBytes & ~3U); offset += 4) {
    *(uint *)(destination + offset) = *(const uint *)(source + offset);
  }
  result = (result & 0xffffff00) | 1;
  for (uint offset = payloadBytes & ~3U; offset < payloadBytes; ++offset) destination[offset] = source[offset];
  return result;
}

struct RSASeedDigestFrame {
  uint digest[4]; // EntryESP-0x90..-0x81.
  NativeStackMD5Frame md5; // Context at entryESP-0x80, then chain/handler/state at-0x0c/-8/-4.
};

// Adds MD5(seed) into the sixteen-byte state counter with carry and saturates the remaining seed-byte requirement.
// R6GameService.dll @ 1003dc60 : ECX context unused, state/seed/count stack words, RET0x0c; full EAX=0.
uint __thiscall UpdateCryptoRandomSeed(void *unusedContext,uint *stateArgument,
    const byte *seedBytes,uint byteCount)
{
  RSASeedDigestFrame frame;
  frame.md5.state = 0xffffffff;
  frame.md5.handler = (void *)RandomStackMD5ExceptionHandler;
  frame.md5.previousExceptionList = ExceptionList;
  ExceptionList = &frame.md5.previousExceptionList;
  ConstructMd5Context(frame.md5.context,1);
  frame.md5.state = 0;
  UpdateMD5(frame.md5.context,seedBytes,byteCount);
  FinalizeMD5(frame.md5.context,frame.digest);
  uint *state = stateArgument; // Native state-argument load follows finalization.
  uint carry = 0;
  byte *digestByte = (byte *)frame.digest + 15;
  byte *counterByte = (byte *)state + 0x13;
  for (uint remaining = 16; remaining != 0; --remaining) {
    uint digestValue = *digestByte;
    uint counterValue = *counterByte;
    carry = digestValue + carry + counterValue;
    *counterByte = (byte)carry;
    carry >>= 8;
    --digestByte;
    --counterByte;
  }
  uint needed = state[0];
  uint consumed = byteCount; // Reloaded after counter addition, retaining argument aliases.
  state[0] = needed < consumed ? 0 : needed - consumed;
  frame.digest[0] = 0;
  frame.md5.state = 0xffffffff;
  frame.digest[1] = 0;
  frame.digest[2] = 0;
  frame.digest[3] = 0;
  DestroyMD5(frame.md5.context);
  ExceptionList = frame.md5.previousExceptionList;
  return 0;
}

struct RSAPublicTransformFrame {
  uint modulus[33]; // EntryESP-0x210.
  uint exponent[33]; // EntryESP-0x18c.
  uint input[33]; // EntryESP-0x108.
  uint result[33]; // EntryESP-0x84, uninitialized until modular exponentiation writes it.
};

// Applies the public exponent using the modulus's significant width for the input comparison and output encoding.
// R6GameService.dll @ 1003dd50 : ECX RSA receiver, five stack words, RET0x14; AL status plus encoder EAX residue.
uint __thiscall ApplyRsaPublicKeyTransform(void *receiver,byte *output,uint *outputBytes,
    const byte *input,uint inputBytes,const uint *keyWords)
{
  RSAPublicTransformFrame frame;
  void *mathContext = (void *)((uint)receiver + 8);
  DecodeBigEndianLimbs(mathContext,frame.input,33,input,inputBytes);
  const uint *key = keyWords; // Native key-argument load follows input decoding.
  DecodeBigEndianLimbs(mathContext,frame.modulus,33,(const byte *)key + 4,128);
  DecodeBigEndianLimbs(mathContext,frame.exponent,33,(const byte *)key + 0x84,128);
  uint modulusLimbs = CountSignificantLimbs(mathContext,frame.modulus,33);
  uint exponentLimbs = CountSignificantLimbs(mathContext,frame.exponent,33);
  uint comparison = (uint)CompareLimbWords(mathContext,frame.input,frame.modulus,modulusLimbs);
  if ((int)comparison >= 0) return comparison & 0xffffff00;
  ModularExponentiateLimbWords(mathContext,frame.result,frame.input,frame.exponent,
      exponentLimbs,frame.modulus,modulusLimbs);
  uint modulusBytes = (key[0] + 7U) >> 3;
  uint *sizeArgument = outputBytes;
  *sizeArgument = modulusBytes;
  byte *outputArgument = output; // Public path loads this argument after publishing the size.
  uint result = EncodeBigEndianLimbs(mathContext,outputArgument,modulusBytes,frame.result,modulusLimbs);
  return (result & 0xffffff00) | 1;
}

struct RSAPrivateTransformFrame {
  uint inputLimbs; // EntryESP-0x634, saved after decoding.
  uint result[33]; // EntryESP-0x630, reused difference/product/recombined output.
  uint primeP[33]; // EntryESP-0x5ac.
  uint resultQ[33]; // EntryESP-0x528, cleared to the modulus width before exponentiation.
  uint input[33]; // EntryESP-0x4a4.
  uint primeQ[33]; // EntryESP-0x420.
  uint resultP[33]; // EntryESP-0x39c.
  uint modulus[33]; // EntryESP-0x318.
  uint inputModP[33]; // EntryESP-0x294.
  uint exponentQ[33]; // EntryESP-0x210.
  uint inputModQ[33]; // EntryESP-0x18c.
  uint exponentP[33]; // EntryESP-0x108.
  uint coefficient[33]; // EntryESP-0x84.
};

// Recombines private CRT residues using the first prime's width for both branches and native in-place arithmetic.
// R6GameService.dll @ 1003de60 : ECX RSA receiver, five stack words, RET0x14; no local exception frame or wiping.
uint __thiscall ApplyRsaPrivateKeyTransform(void *receiver,byte *output,uint *outputBytes,
    const byte *input,uint inputBytes,const uint *keyWords)
{
  RSAPrivateTransformFrame frame;
  void *mathContext = (void *)((uint)receiver + 8);
  DecodeBigEndianLimbs(mathContext,frame.input,33,input,inputBytes);
  const uint *key = keyWords;
  DecodeBigEndianLimbs(mathContext,frame.modulus,33,(const byte *)key + 4,128);
  DecodeBigEndianLimbs(mathContext,frame.primeP,33,(const byte *)key + 0x184,64);
  DecodeBigEndianLimbs(mathContext,frame.primeQ,33,(const byte *)key + 0x1c4,64);
  DecodeBigEndianLimbs(mathContext,frame.exponentP,33,(const byte *)key + 0x204,64);
  DecodeBigEndianLimbs(mathContext,frame.exponentQ,33,(const byte *)key + 0x244,64);
  DecodeBigEndianLimbs(mathContext,frame.coefficient,33,(const byte *)key + 0x284,64);
  uint inputLimbs = CountSignificantLimbs(mathContext,frame.input,33);
  frame.inputLimbs = inputLimbs;
  uint modulusLimbs = CountSignificantLimbs(mathContext,frame.modulus,33);
  uint primeLimbs = CountSignificantLimbs(mathContext,frame.primeP,33);
  uint comparison = (uint)CompareLimbWords(mathContext,frame.input,frame.modulus,modulusLimbs);
  if ((int)comparison >= 0) return comparison & 0xffffff00;
  ReduceLimbWordsModulo(mathContext,frame.inputModP,frame.input,frame.inputLimbs,frame.primeP,primeLimbs);
  ReduceLimbWordsModulo(mathContext,frame.inputModQ,frame.input,frame.inputLimbs,frame.primeQ,primeLimbs);
  ModularExponentiateLimbWords(mathContext,frame.resultP,frame.inputModP,frame.exponentP,
      primeLimbs,frame.primeP,primeLimbs);
  ClearLimbWords(mathContext,frame.resultQ,modulusLimbs);
  ModularExponentiateLimbWords(mathContext,frame.resultQ,frame.inputModQ,frame.exponentQ,
      primeLimbs,frame.primeQ,primeLimbs);
  if (CompareLimbWords(mathContext,frame.resultP,frame.resultQ,primeLimbs) < 0) {
    SubtractLimbWords(mathContext,frame.result,frame.resultQ,frame.resultP,primeLimbs);
    SubtractLimbWords(mathContext,frame.result,frame.primeP,frame.result,primeLimbs);
  } else {
    SubtractLimbWords(mathContext,frame.result,frame.resultP,frame.resultQ,primeLimbs);
  }
  MultiplyLimbWordsModulo(mathContext,frame.result,frame.result,frame.coefficient,frame.primeP,primeLimbs);
  MultiplyLimbArrays(mathContext,frame.result,frame.result,frame.primeQ,primeLimbs);
  AddLimbWords(mathContext,frame.result,frame.result,frame.resultQ,modulusLimbs);
  uint modulusBits = key[0];
  uint *sizeArgument = outputBytes;
  byte *outputArgument = output; // Private path captures this argument before publishing the size.
  uint modulusBytes = (modulusBits + 7U) >> 3;
  *sizeArgument = modulusBytes;
  uint result = EncodeBigEndianLimbs(mathContext,outputArgument,modulusBytes,frame.result,modulusLimbs);
  return (result & 0xffffff00) | 1;
}

struct RSAKeyGenerationFrame {
  byte *publicExponentBytes; // EntryESP-0x63c, saved during output encoding.
  byte *publicModulusBytes; // EntryESP-0x638.
  uint savedLimbCount; // EntryESP-0x634, reloaded after public record encoding.
  uint primeP[33]; // EntryESP-0x630.
  uint primeQ[33]; // EntryESP-0x5ac.
  uint scratchAndOne[33]; // EntryESP-0x528.
  uint publicExponent[33]; // EntryESP-0x4a4.
  uint privateExponent[33]; // EntryESP-0x420.
  uint pMinusOne[33]; // EntryESP-0x39c.
  uint qMinusOne[33]; // EntryESP-0x318.
  uint modulus[33]; // EntryESP-0x294.
  uint exponentP[33]; // EntryESP-0x210.
  uint exponentQ[33]; // EntryESP-0x18c.
  uint totient[33]; // EntryESP-0x108.
  uint coefficient[33]; // EntryESP-0x84.
};

// Builds public/private RSA records, propagating random-fill failures and retaining the native partial-EAX returns.
// R6GameService.dll @ 1003ceb0 : ECX RSA receiver, four stack words, RET0x10; 0x63c-byte unchecked local frame.
uint __thiscall BuildCryptoKeyRecords(void *receiver,uint *publicRecord,uint *privateRecord,
    const uint *prototype,uint *randomState)
{
  uint bitCount = prototype[0];
  RSAKeyGenerationFrame frame;
  if (bitCount < 508 || bitCount > 1024) return bitCount & 0xffffff00;
  uint *stateArgument = randomState;
  uint limbCount = (bitCount + 31U) >> 5;
  frame.savedLimbCount = limbCount;
  uint primeLimbs = (limbCount + 1U) >> 1;
  uint status = FillRandomLimbWords(receiver,frame.primeP,primeLimbs,stateArgument);
  if (status != 0) return status;
  status = FillRandomLimbWords(receiver,frame.primeQ,primeLimbs,stateArgument);
  if (status != 0) return status;
  void *mathContext = (void *)((uint)receiver + 8);
  ClearLimbWords(mathContext,frame.publicExponent,limbCount);
  const uint *prototypeArgument = prototype;
  uint exponentSelector = prototypeArgument[1];
  uint firstPrimeBits = (prototypeArgument[0] + 1U) >> 1;
  frame.publicExponent[0] = exponentSelector != 0 ? 65537 : 3;
  GeneratePrimeCandidate(receiver,frame.primeP,firstPrimeBits,frame.primeP,
      primeLimbs,frame.publicExponent,1);
  prototypeArgument = prototype; // Reloaded between the two candidate searches.
  GeneratePrimeCandidate(receiver,frame.primeQ,prototypeArgument[0] >> 1,frame.primeQ,
      primeLimbs,frame.publicExponent,1);
  if (CompareLimbWords(mathContext,frame.primeP,frame.primeQ,primeLimbs) < 0) {
    CopyLimbWords(mathContext,frame.scratchAndOne,frame.primeP,primeLimbs);
    CopyLimbWords(mathContext,frame.primeP,frame.primeQ,primeLimbs);
    CopyLimbWords(mathContext,frame.primeQ,frame.scratchAndOne,primeLimbs);
  }
  MultiplyLimbArrays(mathContext,frame.modulus,frame.primeP,frame.primeQ,primeLimbs);
  ModularInverseLimbWords(mathContext,frame.coefficient,frame.primeQ,frame.primeP,primeLimbs);
  ClearLimbWords(mathContext,frame.scratchAndOne,limbCount);
  frame.scratchAndOne[0] = 1;
  SubtractLimbWords(mathContext,frame.pMinusOne,frame.primeP,frame.scratchAndOne,primeLimbs);
  SubtractLimbWords(mathContext,frame.qMinusOne,frame.primeQ,frame.scratchAndOne,primeLimbs);
  MultiplyLimbArrays(mathContext,frame.totient,frame.pMinusOne,frame.qMinusOne,primeLimbs);
  ModularInverseLimbWords(mathContext,frame.privateExponent,frame.publicExponent,frame.totient,limbCount);
  ReduceLimbWordsModulo(mathContext,frame.exponentP,frame.privateExponent,
      limbCount,frame.pMinusOne,primeLimbs);
  ReduceLimbWordsModulo(mathContext,frame.exponentQ,frame.privateExponent,
      limbCount,frame.qMinusOne,primeLimbs);
  prototypeArgument = prototype;
  uint *privateArgument = privateRecord;
  uint outputBits = prototypeArgument[0];
  uint *publicArgument = publicRecord; // Both output bases are captured before either header store.
  privateArgument[0] = outputBits;
  publicArgument[0] = outputBits;
  frame.publicModulusBytes = (byte *)publicArgument + 4;
  EncodeBigEndianLimbs(mathContext,frame.publicModulusBytes,128,frame.modulus,limbCount);
  frame.publicExponentBytes = (byte *)publicArgument + 0x84;
  EncodeBigEndianLimbs(mathContext,frame.publicExponentBytes,128,frame.publicExponent,1);
  uint *firstPrivateArgument = privateRecord;
  const uint *modulusSource = (const uint *)frame.publicModulusBytes;
  uint *secondPrivateArgument = privateRecord; // Native captures both copy destinations before the first copy.
  uint outputLimbs = frame.savedLimbCount;
  uint *destination = firstPrivateArgument + 1;
  for (uint count = 32; count != 0; --count) *destination++ = *modulusSource++;
  const uint *exponentSource = (const uint *)frame.publicExponentBytes;
  destination = secondPrivateArgument + 33;
  for (uint count = 32; count != 0; --count) *destination++ = *exponentSource++;
  EncodeBigEndianLimbs(mathContext,(byte *)secondPrivateArgument + 0x104,
      128,frame.privateExponent,outputLimbs);
  privateArgument = privateRecord; // Reloaded once after encoding d; retained across the five CRT fields.
  EncodeBigEndianLimbs(mathContext,(byte *)privateArgument + 0x184,64,frame.primeP,primeLimbs);
  EncodeBigEndianLimbs(mathContext,(byte *)privateArgument + 0x1c4,64,frame.primeQ,primeLimbs);
  EncodeBigEndianLimbs(mathContext,(byte *)privateArgument + 0x204,64,frame.exponentP,primeLimbs);
  EncodeBigEndianLimbs(mathContext,(byte *)privateArgument + 0x244,64,frame.exponentQ,primeLimbs);
  uint result = EncodeBigEndianLimbs(mathContext,(byte *)privateArgument + 0x284,
      64,frame.coefficient,primeLimbs);
  return (result & 0xffffff00) | 1;
}

// Decodes a stack buffer of generated random bytes only on full-EAX zero status, with no buffer-length guard.
// R6GameService.dll @ 1003d600 : ECX RSA receiver, destination/count/state stack words, RET0x0c; full EAX status.
uint __thiscall FillRandomLimbWords(void *receiver,uint *destination,uint limbCount,uint *randomState)
{
  byte randomBytes[128]; // EntryESP-0x80, unwiped on both exits.
  uint count = limbCount;
  uint byteCount = count * 4U;
  uint status = GenerateCryptoRandomBytes(receiver,randomBytes,byteCount,randomState);
  if (status != 0) return status;
  uint *destinationArgument = destination; // Loaded after generation, unlike the cached count and byte count.
  DecodeBigEndianLimbs((void *)((uint)receiver + 8),destinationArgument,count,randomBytes,byteCount);
  return 0;
}

struct RSAPrimeSearchFrame {
  uint candidate[33]; // EntryESP-0x210.
  uint upperRange[33]; // EntryESP-0x18c.
  uint increment[33]; // EntryESP-0x108.
  uint lowerRangeBit[33]; // EntryESP-0x84.
};

// Searches odd candidates with native wrap/retry ordering and copies the accepted limbs to the caller's destination.
// R6GameService.dll @ 1003d660 : ECX RSA receiver, six stack words, RET0x18; EAX=destination+4*cached limb count.
uint __thiscall GeneratePrimeCandidate(void *receiver,uint *destination,uint candidateBitCount,
    const uint *randomCandidate,uint limbCount,const uint *publicExponent,uint exponentLimbCount)
{
  RSAPrimeSearchFrame frame;
  uint bits = candidateBitCount;
  uint count = limbCount;
  void *mathContext = (void *)((uint)receiver + 8);
  SetSingleLimbBit(mathContext,frame.lowerRangeBit,bits - 2U,count);
  SetSingleLimbBit(mathContext,frame.upperRange,bits - 1U,count);
  AddLimbWords(mathContext,frame.upperRange,frame.upperRange,frame.lowerRangeBit,count);
  const uint *randomArgument = randomCandidate;
  ReduceLimbWordsModulo(mathContext,frame.candidate,randomArgument,count,frame.lowerRangeBit,count);
  AddLimbWords(mathContext,frame.candidate,frame.candidate,frame.upperRange,count);
  if (count == 0 || (frame.candidate[0] & 1U) == 0) {
    ClearLimbWords(mathContext,frame.increment,count);
    frame.increment[0] = 1;
    AddLimbWords(mathContext,frame.candidate,frame.candidate,frame.increment,count);
  }
  ClearLimbWords(mathContext,frame.increment,count);
  frame.increment[0] = 2;
  SubtractLimbWords(mathContext,frame.upperRange,frame.upperRange,frame.increment,count);
  AddLimbWords(mathContext,frame.upperRange,frame.upperRange,frame.lowerRangeBit,count);
  uint exponentCount = exponentLimbCount;
  const uint *exponentArgument = publicExponent;
  uint accepted = IsUsablePrimeCandidate(receiver,frame.candidate,count,exponentArgument,exponentCount);
  while (accepted == 0) {
    if (CompareLimbWords(mathContext,frame.candidate,frame.upperRange,count) > 0) {
      SubtractLimbWords(mathContext,frame.candidate,frame.candidate,frame.lowerRangeBit,count);
    }
    AddLimbWords(mathContext,frame.candidate,frame.candidate,frame.increment,count);
    exponentArgument = publicExponent; // Pointer reloads each retry; exponent count stays cached.
    accepted = IsUsablePrimeCandidate(receiver,frame.candidate,count,exponentArgument,exponentCount);
  }
  uint *destinationArgument = destination;
  CopyLimbWords(mathContext,destinationArgument,frame.candidate,count);
  return (uint)destinationArgument + count * 4U; // Native seeds EAX with destination before the copy call.
}

struct RSACandidateAcceptanceFrame {
  uint one[33]; // EntryESP-0x108.
  uint candidateMinusOne[33]; // EntryESP-0x84.
};

// Requires the candidate filters and a unit GCD between candidate-minus-one and the supplied exponent.
// R6GameService.dll @ 1003d840 : ECX RSA receiver, four stack words, RET0x10; full EAX0/1.
uint __thiscall IsUsablePrimeCandidate(void *receiver,const uint *candidate,uint limbCount,
    const uint *publicExponent,uint exponentLimbCount)
{
  RSACandidateAcceptanceFrame frame;
  uint count = limbCount;
  void *mathContext = (void *)((uint)receiver + 8);
  ClearLimbWords(mathContext,frame.one,count);
  const uint *candidateArgument = candidate;
  frame.one[0] = 1;
  SubtractLimbWords(mathContext,frame.candidateMinusOne,candidateArgument,frame.one,count);
  if (PassesPrimeCandidateFilters(receiver,candidateArgument,count) == 0) return 0;
  uint exponentCount = exponentLimbCount;
  const uint *exponentArgument = publicExponent;
  return IsCoprimeWithExponent(receiver,frame.candidateMinusOne,count,exponentArgument,exponentCount) != 0;
}

// Requires a nonzero Fermat result after the small-divisor rejection test returns full EAX zero.
// R6GameService.dll @ 1003d8e0 : ECX RSA receiver, candidate/count stack words, RET8; full EAX0/1.
uint __thiscall PassesPrimeCandidateFilters(void *receiver,const uint *candidate,uint limbCount)
{
  const uint *candidateArgument = candidate;
  uint count = limbCount;
  if (HasSmallPrimeDivisor(receiver,candidateArgument,count) != 0) return 0;
  return PassesBaseTwoFermatTest(receiver,candidateArgument,count) != 0;
}

// R6GameService.dll data @ 1008fdd4 : native storage identity retained.
const uint GRSASmallPrimeDivisors[4] = {3,5,7,11};

// Tests four native divisors, reusing the original count argument word as the divisor/remainder scratch cell.
// R6GameService.dll @ 1003d920 : ECX RSA receiver, candidate/count stack words, RET8; no local allocation, EAX0/1.
uint __thiscall HasSmallPrimeDivisor(void *receiver,const uint *candidate,uint limbCount)
{
  uint count = limbCount;
  const uint *candidateArgument = candidate;
  void *mathContext = (void *)((uint)receiver + 8);
  for (uint offset = 0; offset < 4; ++offset) {
    ClearLimbWords(mathContext,&limbCount,1); // This is the incoming EntryESP+8 argument, not a local scalar.
    limbCount = GRSASmallPrimeDivisors[offset];
    ReduceLimbWordsModulo(mathContext,&limbCount,candidateArgument,count,&limbCount,1);
    uint isZero = AreLimbWordsZero(mathContext,&limbCount,1);
    if (isZero != 0) return 1;
  }
  return 0;
}

struct RSAFermatFrame {
  uint base[33]; // EntryESP-0x108.
  uint residue[33]; // EntryESP-0x84.
};

// Checks 2^candidate modulo candidate against two at the cached limb width, without stronger primality claims.
// R6GameService.dll @ 1003d990 : ECX RSA receiver, candidate/count stack words, RET8; full EAX0/1.
uint __thiscall PassesBaseTwoFermatTest(void *receiver,const uint *candidate,uint limbCount)
{
  RSAFermatFrame frame;
  uint count = limbCount;
  void *mathContext = (void *)((uint)receiver + 8);
  ClearLimbWords(mathContext,frame.base,count);
  const uint *candidateArgument = candidate;
  frame.base[0] = 2;
  ModularExponentiateLimbWords(mathContext,frame.residue,frame.base,candidateArgument,
      count,candidateArgument,count);
  return CompareLimbWords(mathContext,frame.base,frame.residue,count) == 0;
}

struct RSAExponentCoprimalityFrame {
  uint gcd[33]; // EntryESP-0x108.
  uint one[33]; // EntryESP-0x84.
};

// Checks the supplied exponent against candidate-minus-one using a copied exponent and the native in-place GCD.
// R6GameService.dll @ 1003da00 : ECX RSA receiver, four stack words, RET0x10; full EAX0/1.
uint __thiscall IsCoprimeWithExponent(void *receiver,const uint *candidateMinusOne,uint limbCount,
    const uint *exponent,uint exponentLimbCount)
{
  RSAExponentCoprimalityFrame frame;
  uint count = limbCount;
  void *mathContext = (void *)((uint)receiver + 8);
  ClearLimbWords(mathContext,frame.gcd,count);
  uint exponentCount = exponentLimbCount;
  const uint *exponentArgument = exponent;
  CopyLimbWords(mathContext,frame.gcd,exponentArgument,exponentCount);
  const uint *candidateArgument = candidateMinusOne;
  GreatestCommonDivisorLimbWords(mathContext,frame.gcd,candidateArgument,frame.gcd,count);
  ClearLimbWords(mathContext,frame.one,count);
  frame.one[0] = 1;
  return CompareLimbWords(mathContext,frame.gcd,frame.one,count) == 0;
}

// Native virtual-table prefix: RSAVTable
// R6GameService.dll data @ 10077ab4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct RSAVTableRecord {
  R6GameServiceNative::Address DeleteExtallocBaseObject; // +0x00
};
const RSAVTableRecord RSAVTable = {R6GameServiceAddresses::DeleteExtallocBaseObject};
