#include "native_addresses.h"

// Free operation adapters for registered algorithms; concrete vtables establish roles, not class ownership.
// Named naked bodies preserve partial-register returns, tail jumps, callback reloads and stack aliases.

// Tail-forwards the original stack and raw registers to 10037bc0.
// R6GameService.dll @ 10037350 : stdcall, 4 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall RepeatHashInputThunk(
    void *receiver,const byte *input,uint byteCount,uint repeatCount)
{
  __asm {
    jmp    R6GameServiceAddresses::RepeatHashInput
  }
}

// Tail-forwards the original stack and raw registers to 10037c00.
// R6GameService.dll @ 10037360 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall FinalizeAndCopyHashDigestThunk(void *receiver,byte *output)
{
  __asm {
    jmp    R6GameServiceAddresses::FinalizeAndCopyHashDigest
  }
}

// Tail-forwards the original stack and raw registers to 10037c30.
// R6GameService.dll @ 10037370 : stdcall, 1 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ResetHashAlgorithmThunk(void *receiver)
{
  __asm {
    jmp    R6GameServiceAddresses::ResetHashAlgorithm
  }
}

// Tail-forwards the original stack and raw registers to 10037e10.
// R6GameService.dll @ 100373d0 : stdcall, 3 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall FillPRNGBytesThunk(void *receiver,byte *output,uint byteCount)
{
  __asm {
    jmp    R6GameServiceAddresses::FillPRNGBytes
  }
}

// Tail-forwards the original stack and raw registers to 10038030.
// R6GameService.dll @ 10037410 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall EncodeCryptoBufferThunk(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes)
{
  __asm {
    jmp    R6GameServiceAddresses::EncodeCryptoBuffer
  }
}

// Tail-forwards the original stack and raw registers to 10038060.
// R6GameService.dll @ 10037420 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall DecodeCryptoBufferThunk(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes)
{
  __asm {
    jmp    R6GameServiceAddresses::DecodeCryptoBuffer
  }
}

// Tail-forwards the original stack and raw registers to 10038240.
// R6GameService.dll @ 10037460 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall GeneratePKCKeyRecordsThunk(
    void *receiver,uint *publicRecord,uint *privateRecord,const uint *prototype,uint *state)
{
  __asm {
    jmp    R6GameServiceAddresses::GeneratePKCKeyRecords
  }
}

// Tail-forwards the original stack and raw registers to 10038270.
// R6GameService.dll @ 10037470 : stdcall, 7 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall EncodePKCType2BlockThunk(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key,uint *state)
{
  __asm {
    jmp    R6GameServiceAddresses::EncodePKCType2Block
  }
}

// Tail-forwards the original stack and raw registers to 100382b0.
// R6GameService.dll @ 10037480 : stdcall, 6 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall DecodePKCType2BlockThunk(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key)
{
  __asm {
    jmp    R6GameServiceAddresses::DecodePKCType2Block
  }
}

// Tail-forwards the original stack and raw registers to 100382e0.
// R6GameService.dll @ 10037490 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall InitializePKCRandomStateThunk(void *receiver,uint *state)
{
  __asm {
    jmp    R6GameServiceAddresses::InitializePKCRandomState
  }
}

// Tail-forwards the original stack and raw registers to 10038300.
// R6GameService.dll @ 100374a0 : stdcall, 4 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall UpdatePKCRandomSeedThunk(
    void *receiver,uint *state,const byte *seed,uint byteCount)
{
  __asm {
    jmp    R6GameServiceAddresses::UpdatePKCRandomSeed
  }
}

// Tail-forwards the original stack and raw registers to 10038330.
// R6GameService.dll @ 100374b0 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ClearPKCRandomStateThunk(void *receiver,uint *state)
{
  __asm {
    jmp    R6GameServiceAddresses::ClearPKCRandomState
  }
}

// Calls the seed-byte deficit adapter and returns only the low byte of its status.
// R6GameService.dll @ 100374c0 : stdcall, 3 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ReadPKCSeedBytesNeededLowByte(
    void *receiver,uint *bytesNeeded,const uint *state)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::ReadPKCSeedBytesNeeded
    and    eax,0xff
    ret    0xc
  }
}

// Repeats hash input with cached arguments and a reloaded vtable; forces only AL after all callbacks.
// R6GameService.dll @ 10037bc0 : stdcall, 4 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall RepeatHashInput(
    void *receiver,const byte *input,uint byteCount,uint repeatCount)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    test   esi,esi
    je Branch3
    cmp    BYTE PTR [esi+0x8],0x1
    je Branch3
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    test   edi,edi
    jbe Branch2
    push   ebx
    mov    ebx,DWORD PTR [esp+0x18]
    push   ebp
    mov    ebp,DWORD PTR [esp+0x18]
  Branch1:
    mov    eax,DWORD PTR [esi]
    push   ebx
    push   ebp
    mov    ecx,esi
    call   DWORD PTR [eax+0xc]
    dec    edi
    jne Branch1
    pop    ebp
    pop    ebx
  Branch2:
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x10
  Branch3:
    xor    al,al
    pop    esi
    ret    0x10
  }
}

// Finalizes an unfinalized hash, reloads the output word and vtable, then returns the digest-copy result.
// R6GameService.dll @ 10037c00 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall FinalizeAndCopyHashDigest(void *receiver,byte *output)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    test   esi,esi
    je Branch4
    cmp    BYTE PTR [esi+0x8],0x1
    je Branch4
    mov    eax,DWORD PTR [esi]
    mov    ecx,esi
    call   DWORD PTR [eax+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esi]
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edx+0x14]
    pop    esi
    ret    0x8
  Branch4:
    xor    al,al
    pop    esi
    ret    0x8
  }
}

// Resets a nonnull hash and forces AL to one; a null receiver clears only AL.
// R6GameService.dll @ 10037c30 : stdcall, 1 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ResetHashAlgorithm(void *receiver)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch5
    xor    al,al
    ret    0x4
  Branch5:
    mov    eax,DWORD PTR [ecx]
    call   DWORD PTR [eax+0x4]
    mov    al,0x1
    ret    0x4
  }
}

// Clears output in DWORD/byte phases before reloading the optional PRNG receiver and forwarding the cached span.
// R6GameService.dll @ 10037e10 : stdcall, 3 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall FillPRNGBytes(void *receiver,byte *output,uint byteCount)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    push   ebx
    mov    ecx,edx
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    push   edi
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep stos DWORD PTR es:[edi],eax
    mov    ecx,ebx
    and    ecx,0x3
    rep stos BYTE PTR es:[edi],al
    mov    ecx,DWORD PTR [esp+0x10]
    test   ecx,ecx
    je Branch6
    mov    eax,DWORD PTR [ecx]
    push   edx
    push   esi
    call   DWORD PTR [eax+0xc]
  Branch6:
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Forwards cipher encode arguments through the primary table; null clears only AL.
// R6GameService.dll @ 10038030 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall EncodeCryptoBuffer(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch7
    xor    al,al
    ret    0x14
  Branch7:
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    call   DWORD PTR [eax+0xc]
    ret    0x14
  }
}

// Forwards cipher decode arguments through the primary table; null clears only AL.
// R6GameService.dll @ 10038060 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall DecodeCryptoBuffer(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch8
    xor    al,al
    ret    0x14
  Branch8:
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    call   DWORD PTR [eax+0x10]
    ret    0x14
  }
}

// Forwards key-record generation through slot +4; null clears only AL.
// R6GameService.dll @ 10038240 : stdcall, 5 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall GeneratePKCKeyRecords(
    void *receiver,uint *publicRecord,uint *privateRecord,const uint *prototype,uint *state)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch9
    xor    al,al
    ret    0x14
  Branch9:
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    call   DWORD PTR [eax+0x4]
    ret    0x14
  }
}

// Forwards type2 encoding through slot +8 with all six words; null clears only AL.
// R6GameService.dll @ 10038270 : stdcall, 7 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall EncodePKCType2Block(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key,uint *state)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch10
    xor    al,al
    ret    0x1c
  Branch10:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    call   DWORD PTR [eax+0x8]
    ret    0x1c
  }
}

// Forwards type2 decoding through slot +0x14; null clears only AL.
// R6GameService.dll @ 100382b0 : stdcall, 6 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall DecodePKCType2Block(
    void *receiver,const byte *input,uint inputBytes,byte *output,uint *outputBytes,const uint *key)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch11
    xor    al,al
    ret    0x18
  Branch11:
    mov    edx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x18]
    push   edx
    mov    edx,DWORD PTR [esp+0x18]
    push   edx
    mov    edx,DWORD PTR [esp+0x18]
    push   edx
    mov    edx,DWORD PTR [esp+0x18]
    push   edx
    call   DWORD PTR [eax+0x14]
    ret    0x18
  }
}

// Forwards random-state initialization through slot +0x18; null clears only AL.
// R6GameService.dll @ 100382e0 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall InitializePKCRandomState(void *receiver,uint *state)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch12
    xor    al,al
    ret    0x8
  Branch12:
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x18]
    ret    0x8
  }
}

// Forwards random-state seed input through slot +0x1c; null clears only AL.
// R6GameService.dll @ 10038300 : stdcall, 4 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall UpdatePKCRandomSeed(
    void *receiver,uint *state,const byte *seed,uint byteCount)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch13
    xor    al,al
    ret    0x10
  Branch13:
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    call   DWORD PTR [eax+0x1c]
    ret    0x10
  }
}

// Clears a nonnull random state through slot +0x20 and forces only AL to one.
// R6GameService.dll @ 10038330 : stdcall, 2 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ClearPKCRandomState(void *receiver,uint *state)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch14
    xor    al,al
    ret    0x8
  Branch14:
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x20]
    mov    al,0x1
    ret    0x8
  }
}

// Forwards the seed-byte deficit query through slot +0x24; null clears only AL.
// R6GameService.dll @ 10038350 : stdcall, 3 stack words; raw EAX retained except stated AL/mask.
__declspec(naked) uint __stdcall ReadPKCSeedBytesNeeded(void *receiver,uint *bytesNeeded,const uint *state)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne Branch15
    xor    al,al
    ret    0xc
  Branch15:
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx]
    push   edx
    mov    edx,DWORD PTR [esp+0xc]
    push   edx
    call   DWORD PTR [eax+0x24]
    ret    0xc
  }
}
