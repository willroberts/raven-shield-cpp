#include "native_addresses.h"

// Forwards destruction of the unchanged receiver through the selected Core FString destructor import.
// R6GameService.dll @ 10001580 : complete native import tail retained.
__declspec(naked) void __thiscall FString::~FString(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}
