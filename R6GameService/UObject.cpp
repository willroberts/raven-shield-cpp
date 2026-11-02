#include "native_addresses.h"

// Tail the current Core ProcessEvent import with original receiver and all three full argument words.
// R6GameService.dll @ 100149f8 : complete six-byte current-IAT member tail.
__declspec(naked) void __thiscall UObject::ProcessEvent(UFunction *function,void *parameters,void *result)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ProcessEventSlot
  }
}
