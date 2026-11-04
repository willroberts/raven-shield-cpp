#include "native_addresses.h"

// Descriptive names for native full32 checksum storage; selected PE .data zero-fill establishes initial zeros.
// R6GameService.dll data @ 10093d28 : native storage identity retained.
uint GReflectedChecksumTable[256] = {};
// R6GameService.dll data @ 10094128 : native storage identity retained.
uint GForwardChecksumTable[256] = {};
// R6GameService.dll data @ 10094528 : native storage identity retained.
byte GForwardChecksumReady = 0;
// R6GameService.dll data @ 10094529 : native storage identity retained.
byte GReflectedChecksumReady = 0;

// Inferred guard for the completed local vector; a throwing normal free leaves its storage eligible for cleanup again.
struct CollectedChecksumVectorCleanup {
  uint *vector;
  bool armed;
  ~CollectedChecksumVectorCleanup() noexcept(false) {
    if (armed) ReleaseAndResetStorageAt04((int)vector);
  }
};

// Checksums the builder returned vector, frees separately owned local storage and preserves the computed word.
// R6GameService.dll @ 10034a30 : local storage cleanup is armed only after the builder returns.
uint __cdecl ComputeCollectedStringsChecksum()
{
  uint localVector[4];
  using BuildABI = void *(__cdecl *)(void *);
  void *built = ((BuildABI)R6GameServiceAddresses::BuildByteVectorFromCollectedStrings)(localVector);
  CollectedChecksumVectorCleanup cleanup{localVector, true};
  uint computed = checksum_support_UpdateChecksumFromBuffer(built);
  void *localBegin = (void *)localVector[1];
  if (localBegin != 0) FreeThroughGlobalAllocator(localBegin);
  cleanup.armed = false;
  return computed;
}

// Appends the collected checksum most-significant byte first, retaining native argument-slot byte scratch.
// R6GameService.dll @ 10034a90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendCollectedStringsChecksumBytes(void *byteVector)
{
  __asm {
    // Compute checksum before loading vector argument; preserve full word in EDI and duplicate local entryESP-4.
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::ComputeCollectedStringsChecksum
    mov    esi,DWORD PTR [esp+0x18]
    mov    edi,eax
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x18
    test   eax,eax
    mov    DWORD PTR [esp+0x10],edi
    mov    BYTE PTR [esp+0xf],bl
    jne    Branch2
    xor    edx,edx
    jmp    Branch3
  Branch2:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch3:
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch4
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch5
  Branch4:
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0xf]
    push   ecx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch5:
    // Bytes2/3/4 overwrite low byte of original argument word at entryESP+4; cached ESI remains receiver.
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x10
    test   eax,eax
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch6
    xor    edx,edx
    jmp    Branch7
  Branch6:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch7:
    test   eax,eax
    je     Branch8
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch8
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch9
  Branch8:
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch9:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x8
    test   eax,eax
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch10
    xor    edx,edx
    jmp    Branch11
  Branch10:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch11:
    test   eax,eax
    je     Branch12
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch12
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch13
  Branch12:
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x18]
    push   ecx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch13:
    // Final byte reloads saved checksum local, not EDI low byte; each append reloads current vector fields.
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    mov    bl,BYTE PTR [esp+0x10]
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch14
    xor    edx,edx
    jmp    Branch15
  Branch14:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,ecx
  Branch15:
    test   ecx,ecx
    je     Branch16
    mov    eax,DWORD PTR [esi+0xc]
    sub    eax,ecx
    cmp    edx,eax
    jae    Branch16
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  Branch16:
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  }
}

// Updates full32 reflected state, publishing the shifted intermediate before loading each table word.
// R6GameService.dll @ 100365d0 : complete native control/access order and raw ABI retained.
void __thiscall UpdateReflectedTableChecksum(uint *state,const byte *begin,const byte *end)
{
  uint cursor = (uint)begin;
  const uint limit = (uint)end;
  while (cursor < limit) {
    byte value = *(const byte *)cursor;
    byte lowState = *(const byte *)state;
    uint shifted = *state >> 8;
    byte index = value ^ lowState;
    *state = shifted;
    // The intermediate store precedes the table read, including when state aliases that table.
    uint tableWord = GReflectedChecksumTable[index];
    ++cursor;
    *state = tableWord ^ shifted;
  }
}

// Updates full32 forward state with polynomial-table words and intermediate-before-lookup publication.
// R6GameService.dll @ 10036610 : complete native control/access order and raw ABI retained.
void __thiscall UpdateForwardChecksumState(uint *state,const byte *begin,const byte *end)
{
  uint cursor = (uint)begin;
  const uint limit = (uint)end;
  while (cursor < limit) {
    uint current = *state;
    byte value = *(const byte *)cursor;
    byte index = (byte)(current >> 24) ^ value;
    uint shifted = current << 8;
    *state = shifted;
    uint tableWord = GForwardChecksumTable[index];
    ++cursor;
    *state = tableWord ^ shifted;
  }
}

// Lazily builds 256 full32 forward checksum words using native polynomial0x1021.
// R6GameService.dll @ 10036650 : complete native control/access order and raw ABI retained.
void __cdecl InitializeForwardChecksumTable()
{
  if (GForwardChecksumReady != 0) return;
  for (uint index = 0; index < 256; ++index) {
    uint remainder = 0;
    for (byte mask = 0x80; mask != 0; mask >>= 1) {
      if ((index & mask) != 0) remainder ^= 0x80000000;
      bool high = (remainder & 0x80000000) != 0;
      remainder <<= 1;
      if (high) remainder ^= 0x1021;
    }
    GForwardChecksumTable[index] = remainder;
  }
  GForwardChecksumReady = 1;
}

// Lazily builds reflected full32 checksum words from native polynomial0x1025 and reversed byte indices.
// R6GameService.dll @ 100366a0 : complete native control/access order and raw ABI retained.
void __cdecl InitializeReflectedChecksumTable()
{
  if (GReflectedChecksumReady != 0) return;
  for (uint index = 0; index < 256; ++index) {
    uint remainder = 0;
    for (byte mask = 0x80; mask != 0; mask >>= 1) {
      if ((index & mask) != 0) remainder ^= 0x80000000;
      bool high = (remainder & 0x80000000) != 0;
      remainder <<= 1;
      if (high) remainder ^= 0x1025;
    }
    uint reversed = 0;
    for (uint bit = 0; bit < 32; ++bit) {
      if ((remainder & 1) != 0) reversed |= 1u << (31 - bit);
      remainder >>= 1;
    }
    byte reversedIndex = 0;
    uint sourceIndex = index;
    for (uint bit = 0; bit < 8; ++bit) {
      if ((sourceIndex & 1) != 0) reversedIndex |= (byte)(0x80 >> bit);
      sourceIndex >>= 1;
    }
    GReflectedChecksumTable[reversedIndex] = reversed;
  }
  GReflectedChecksumReady = 1;
}

// Initializes forward state to0xffff, updates the live byte range and stores/returns the destination.
// R6GameService.dll @ 10036770 : thiscall destination, one vector word, RET4; returns the saved destination.
uint *__thiscall UpdateChecksumFromBuffer(uint *destination,const void *byteVector)
{
  uint *output = destination;
  uint state = 0xffff;
  InitializeForwardChecksumTable();
  uint vector = (uint)byteVector;
  uint begin = *(uint *)(vector + 4);
  uint length = begin == 0 ? 0 : *(uint *)(vector + 8) - begin;
  UpdateForwardChecksumState(&state,(const byte *)begin,(const byte *)(begin + length));
  uint computed = state;
  *output = computed;
  return output;
}

// Initializes reflected state to0xffffffff, updates the unsigned byte range and returns it without final XOR.
// R6GameService.dll @ 100367b0 : one cdecl vector word; returns the full32 reflected state.
uint __cdecl checksum_support_UpdateChecksumFromBuffer(const void *byteVector)
{
  uint sourceBits = 0xffffffff;
  uint reversed = 0;
  for (uint bit = 0; bit < 32; ++bit) {
    if ((sourceBits & 1) != 0) reversed |= 1u << (31 - bit);
    sourceBits >>= 1;
  }
  uint state = reversed;
  InitializeReflectedChecksumTable();
  uint vector = (uint)byteVector;
  uint begin = *(uint *)(vector + 4);
  uint length = begin == 0 ? 0 : *(uint *)(vector + 8) - begin;
  UpdateReflectedTableChecksum(&state,(const byte *)begin,(const byte *)(begin + length));
  return state;
}
