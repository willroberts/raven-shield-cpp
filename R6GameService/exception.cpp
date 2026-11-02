#include "native_addresses.h"

// Tail-forwards the ECX exception destination and original source argument to the imported copy constructor.
// R6GameService.dll @ 10033a22 : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall exception::exception(const exception &source)
{
  __asm {
    // Current IAT6b410 is exception::exception(const exception&); stack source/ECX destination pass unchanged.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__ConstructexceptionSlot2
  }
}

// Forwards the ECX global exception destination to its imported default constructor.
// R6GameService.dll @ 10033ca2 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) __thiscall exception::exception(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__ConstructexceptionSlot
  }
}

// Forwards the ECX global exception object directly to its imported destructor.
// R6GameService.dll @ 10033ca8 : complete six-byte native current-IAT tail, no wrapper frame.
__declspec(naked) __thiscall exception::~exception(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__DestroyexceptionSlot
  }
}
