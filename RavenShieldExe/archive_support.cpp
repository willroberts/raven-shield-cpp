#include "native_symbols.hpp"
// Shared archive bodies retain one definition for multiple class-facing virtual slots.
#include <cstdint>

// RavenShield.exe @ 10906650 : ReadSharedArchiveOffset48
// Return the signed 32-bit value at receiver+48; reader TotalSize and writer Tell share this native body.
int32_t __fastcall ReadSharedArchiveOffset48(const void *archive)
{
  return *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(archive) + 0x48);
}
