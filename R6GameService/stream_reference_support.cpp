#include "native_addresses.h"

// Shared second-word accessor and fixed log-reference tails; no concrete owner class is inferred.

// Returns the second DWORD addressed by ECX without assigning a concrete owner class.
// R6GameService.dll @ 10014040 : complete native control/access order and raw ABI retained.
uint __fastcall ReadSecondWord(const void *owner)
{
  return static_cast<const uint *>(owner)[1];
}

// Tail-reads the second word of the directory-access logging reference slot.
// R6GameService.dll @ 10035dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl GetDirectoryAccessTestLogStream(void)
{
  __asm {
    // ECX reference93d20, tail shared14040 -> current stream word93d24.
    mov    ecx,0x10093d20
    jmp    R6GameServiceAddresses::ReadSecondWord
  }
}

// Tail-reads the second word of the service logging reference slot.
// R6GameService.dll @ 10036e30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl GetServiceLogStream(void)
{
  __asm {
    // ECX reference9452c, tail shared14040 -> current stream word94530, not reference first word.
    mov    ecx,0x1009452c
    jmp    R6GameServiceAddresses::ReadSecondWord
  }
}

// Tail-reads the first word of the directory logging reference slot.
// R6GameService.dll @ 10035db0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl GetDirectoryLogFirstWord(void)
{
  __asm {
    // ECX reference93d20, raw tail370e0 reads current word93d20; second-word tail35dc0 remains separate.
    mov    ecx,0x10093d20
    jmp    R6GameServiceAddresses::ReadFirstWord
  }
}

// Stores the current imported wide output and error stream addresses in native load/store order.
// R6GameService.dll @ 100370c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall InitializeWideStreamReferences(void *references)
{
  __asm {
    // Cache receiverEAX; load/store wcout first, then load CURRENT wcerr slot. Aliasing imports can affect the second load.
    mov    eax,ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_wcoutSlot
    mov    DWORD PTR [eax],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_wcerrSlot
    mov    DWORD PTR [eax+0x4],edx
    ret
  }
}

// Returns the first DWORD addressed by ECX.
// R6GameService.dll @ 100370e0 : complete native control/access order and raw ABI retained.
uint __fastcall ReadFirstWord(const void *owner)
{
  return *static_cast<const uint *>(owner);
}
