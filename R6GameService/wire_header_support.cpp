#include "native_addresses.h"

// Shared wire-header helpers; original enclosing types unresolved. Six-/seven-byte callers use different field views.

// Clear released scratchS-4, pack WORD header0/BYTE2 into bytes1..3, rewrite original argument, then tail ordinal14.
// RET4.
// R6GameService.dll @ 10059790 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReadHeaderSize24(const byte *header)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esp+0x0],0x0
    add    esp,0x4
    mov    cx,WORD PTR [eax]
    mov    WORD PTR [esp-0x3],cx
    mov    dl,BYTE PTR [eax+0x2]
    mov    BYTE PTR [esp-0x1],dl
    mov    eax,DWORD PTR [esp-0x4]
    mov    DWORD PTR [esp+0x4],eax
    jmp    DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohlSlot
  }
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
__declspec(naked) uint __stdcall WriteHeaderSize24(byte *header,uint valueWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonlSlot
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x8],eax
    mov    dx,WORD PTR [esp+0x9]
    mov    al,BYTE PTR [esp+0xb]
    mov    WORD PTR [ecx],dx
    mov    BYTE PTR [ecx+0x2],al
    ret    0x8
  }
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

// Store supplied lowBYTE at4; replace only entry AL with that BYTE and retain entry EAX upper24/RET8.
// R6GameService.dll @ 10059890 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall WriteHeaderByte4(byte *header,uint valueWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    al,BYTE PTR [esp+0x8]
    mov    BYTE PTR [ecx+0x4],al
    ret    0x8
  }
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

// Store supplied lowWORD unaligned at5/6; return entry EAX upper16 with supplied AX/RET8.
// R6GameService.dll @ 100598e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall WriteHeaderWord5(byte *header,uint valueWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    mov    ax,WORD PTR [esp+0x8]
    mov    WORD PTR [ecx+0x5],ax
    ret    0x8
  }
}

// Signed input length<6 clears only entry AL, no header read. Otherwise decode size and accept signed6..3000000.
// Out-of-range prints one fixed literal and clears only printf AL; success sets only decoded-size AL1. RET8.
// R6GameService.dll @ 100598f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall IsEncodedHeaderSizeValid(const byte *header,int inputLength)
{
  __asm {
    cmp    DWORD PTR [esp+0x8],0x6
    jge    Branch1
    xor    al,al
    ret    0x8
  Branch1:
    mov    eax,DWORD PTR [esp+0x4]
    push    eax
    call    R6GameServiceAddresses::ReadHeaderSize24
    cmp    eax,0x2dc6c0
    jle    Branch2
    push    R6GameServiceAddresses::TextOnALSizeMAXMESSAGESIZE
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    xor    al,al
    ret    0x8
  Branch2:
    cmp    eax,0x6
    jge    Branch3
    push    R6GameServiceAddresses::TextOnALSizeGSHEADERSIZE
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    xor    al,al
    ret    0x8
  Branch3:
    mov    al,0x1
    ret    0x8
  }
}
