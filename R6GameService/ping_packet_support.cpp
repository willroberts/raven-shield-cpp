#include "native_addresses.h"

// Offset-based ping packet helpers; original function names and declarations are unavailable.

// Folds a wrapped DWORD sum of little-endian words and an odd byte, then returns its full complement.
// R6GameService.dll @ 10013cb0 : cdecl uint(const void*,int); negative counts still consume one byte.
uint __cdecl PingChecksum(const void *data,int byteCount)
{
  const byte *cursor = (const byte *)data;
  uint sum = 0;
  if (byteCount > 1) {
    uint words = ((uint)byteCount - 2) / 2 + 1;
    byteCount -= words * 2;
    do {
      sum += *(const ushort *)cursor;
      cursor += 2;
    } while (--words != 0);
  }
  if (byteCount != 0)
    sum += *cursor;
  uint folded = (sum >> 16) + (sum & 0xffff);
  return ~((folded >> 16) + folded);
}

// Writes an echo request, fills E bytes, copies the unchecked NUL payload and checksums existing header bytes.
// R6GameService.dll @ 10013d10 : cdecl void(void*,int,const char*); checksum bytes are not cleared first.
void __cdecl BuildPingPacket(void *packet,int byteCount,const char *payload)
{
  byte *bytes = (byte *)packet;
  bytes[0] = 8;
  bytes[1] = 0;
  using ProcessIdABI = uint (__stdcall *)(void);
  *(ushort *)(bytes + 4) = (ushort)(*(ProcessIdABI *)R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot)();
  uint &sequence = *(uint *)0x10093b68;
  uint currentSequence = sequence;
  *(ushort *)(bytes + 6) = (ushort)currentSequence;
  sequence = currentSequence + 1;
  using TickCountABI = uint (__stdcall *)(void);
  *(uint *)(bytes + 8) = (*(TickCountABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
  uint fillBytes = (uint)byteCount - 12;
  byte *fill = bytes + 12;
  for (uint words = fillBytes >> 2; words != 0; --words, fill += 4)
    *(uint *)fill = 0x45454545;
  for (uint tail = fillBytes & 3; tail != 0; --tail)
    *fill++ = 0x45;
  byte *destination = bytes + 12;
  byte character;
  do {
    character = *(const byte *)payload++;
    *destination++ = character;
  } while (character != 0);
  *(ushort *)(bytes + 2) = (ushort)PingChecksum(packet,byteCount);
}

// Returns elapsed ticks for an echo reply with the current process ID, or 1000; length and sender are ignored.
// R6GameService.dll @ 10013d90 : cdecl uint(const byte*,int,const void*); no sequence or checksum validation.
uint __cdecl ReadPingReply(const byte *packet,int receiveResult,const void *sender)
{
  const byte *echo = packet + ((packet[0] & 15) * 4);
  if (echo[0] != 0)
    return 1000;
  using ProcessIdABI = uint (__stdcall *)(void);
  uint processId = (*(ProcessIdABI *)R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot)();
  if (*(const ushort *)(echo + 4) != (ushort)processId)
    return 1000;
  using TickCountABI = uint (__stdcall *)(void);
  uint now = (*(TickCountABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
  return now - *(const uint *)(echo + 8);
}
