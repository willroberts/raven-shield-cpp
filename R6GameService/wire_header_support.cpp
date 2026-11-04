#include "native_addresses.h"

// Shared wire-header helpers; original enclosing types unresolved. Six-/seven-byte callers use different field views.

// Zero the native scratch word at entryESP-4, pack WORD0/BYTE2 into bytes1..3 and convert the rewritten argument.
// R6GameService.dll @ 10059790 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderSize24(const byte *header)
{
  const byte *source = header;
  uint packed = 0;
  ushort first = *(const ushort *)source;
  *(ushort *)((byte *)&packed + 1) = first;
  byte last = source[2];
  *((byte *)&packed + 3) = last;
  header = (const byte *)packed;
  using ConvertABI = uint (__stdcall *)(uint);
  return (*(ConvertABI *)R6GameServiceAddresses::WS2_32_ntohlSlot)((uint)header);
}

// Zero-extend header BYTE3 then shift6, returning its top two bits as full EAX/RET4.
// R6GameService.dll @ 100597c0 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderByte3HighBits(const byte *header)
{
  return header[3] >> 6;
}

// Load header BYTE3 into pointer EAX then mask3f, returning full six-bit value/RET4.
// R6GameService.dll @ 100597d0 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderByte3LowBits(const byte *header)
{
  return header[3] & 0x3f;
}

// Replace only AL of header pointer EAX with header BYTE4; retain pointer upper24/RET4.
// R6GameService.dll @ 100597e0 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderByte4(const byte *header)
{
  return (reinterpret_cast<uint>(header) & 0xffffff00) | header[4];
}

// Zero-extend header BYTE5 then shift4, returning its high nibble as full EAX/RET4.
// R6GameService.dll @ 100597f0 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderByte5HighNibble(const byte *header)
{
  return header[5] >> 4;
}

// Load header BYTE5 into pointer EAX then maskf, returning full low-nibble value/RET4.
// R6GameService.dll @ 10059800 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderByte5LowNibble(const byte *header)
{
  return header[5] & 0x0f;
}

// Replace only AX of header pointer EAX with unaligned little-endian WORD5; retain pointer upper16/RET4.
// R6GameService.dll @ 10059810 : complete native control/access order and raw ABI retained.
uint __stdcall ReadHeaderWord5(const byte *header)
{
  return (reinterpret_cast<uint>(header) & 0xffff0000) | *reinterpret_cast<const unsigned short *>(header + 5);
}

// Convert full size through ordinal8, reload CURRENT header argument, reuse original size slot for converted word.
// Cache converted bytes1..2/byte3 before WORD0 then BYTE2 writes; raw EAX has converted byte3 in AL. RET8.
// R6GameService.dll @ 10059820 : complete native control/access order and raw ABI retained.
uint __stdcall WriteHeaderSize24(byte *header,uint valueWord)
{
  using ConvertABI = uint (__stdcall *)(uint);
  uint converted = (*(ConvertABI *)R6GameServiceAddresses::WS2_32_htonlSlot)(valueWord);
  byte *destination = header;
  valueWord = converted;
  ushort first = *(ushort *)((byte *)&valueWord + 1);
  byte last = *((byte *)&valueWord + 3);
  *(ushort *)destination = first;
  destination[2] = last;
  return (converted & 0xffffff00) | last;
}

// Replace BYTE3 upper2 from lowBYTE<<6, preserve lower5 and CLEAR bit5; return cached header pointer/RET8.
// R6GameService.dll @ 10059850 : complete native control/access order and raw ABI retained.
uint __stdcall WriteHeaderByte3HighBits(byte *header,uint valueWord)
{
  header[3] = (header[3] & 0x1f) | static_cast<byte>(valueWord << 6);
  return reinterpret_cast<uint>(header);
}

// OR only supplied mask20 into BYTE3; zero cannot clear an existing bit. Return header pointer/RET8.
// R6GameService.dll @ 10059870 : complete native control/access order and raw ABI retained.
uint __stdcall SetHeaderByte3Bit5(byte *header,uint valueWord)
{
  header[3] |= static_cast<byte>(valueWord & 0x20);
  return reinterpret_cast<uint>(header);
}

// Store the supplied low BYTE at4; inferred void return follows all observed callers. RET8.
// R6GameService.dll @ 10059890 : complete native control/access order and raw ABI retained.
void __stdcall WriteHeaderByte4(byte *header,uint valueWord)
{
  byte *destination = header;
  byte value = *(byte *)&valueWord;
  destination[4] = value;
}

// Combine supplied lowBYTE<<4 with current BYTE5 low nibble; return cached header pointer/RET8.
// R6GameService.dll @ 100598a0 : complete native control/access order and raw ABI retained.
uint __stdcall WriteHeaderByte5HighNibble(byte *header,uint valueWord)
{
  header[5] = (header[5] & 0x0f) | static_cast<byte>(valueWord << 4);
  return reinterpret_cast<uint>(header);
}

// Read BYTE5 twice: second XOR ((first XOR supplied lowBYTE)&f), then store at5. Return header pointer/RET8.
// R6GameService.dll @ 100598c0 : complete native control/access order and raw ABI retained.
uint __stdcall WriteHeaderByte5LowNibble(byte *header,uint valueWord)
{
  byte changedBits = static_cast<byte>((header[5] ^ valueWord) & 0x0f);
  byte current = header[5];
  header[5] = current ^ changedBits;
  return reinterpret_cast<uint>(header);
}

// Store the supplied low WORD unaligned at5/6; inferred void return follows all observed callers. RET8.
// R6GameService.dll @ 100598e0 : complete native control/access order and raw ABI retained.
void __stdcall WriteHeaderWord5(byte *header,uint valueWord)
{
  byte *destination = header;
  ushort value = *(ushort *)&valueWord;
  *(ushort *)(destination + 5) = value;
}

// Reject signed lengths below6 without reading the header; otherwise accept only signed decoded sizes6..3000000.
// Failure keeps entry or printf upper EAX; success replaces only decoded-size AL. No encoded-size<=input-size check.
// R6GameService.dll @ 100598f0 : EAX input view, two native stack words/stdcall RET8; no local ownership.
uint IsEncodedHeaderSizeValid(
    const byte *header,int inputLength,[[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  if (inputLength < 6) return eaxAtEntry & 0xffffff00;
  uint decoded = ReadHeaderSize24(header);
  using PrintABI = int (__cdecl *)(const char *,...);
  if ((int)decoded > 3000000) {
    uint printed = (uint)((PrintABI)R6GameServiceAddresses::printf)(
        (const char *)R6GameServiceAddresses::TextOnALSizeMAXMESSAGESIZE);
    return printed & 0xffffff00;
  }
  if ((int)decoded < 6) {
    uint printed = (uint)((PrintABI)R6GameServiceAddresses::printf)(
        (const char *)R6GameServiceAddresses::TextOnALSizeGSHEADERSIZE);
    return printed & 0xffffff00;
  }
  return (decoded & 0xffffff00) | 1;
}
