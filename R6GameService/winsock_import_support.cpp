#include "native_addresses.h"

// Selected Winsock import tail; external socket-set behavior remains owned by WS2_32.dll.
// Forwards socket/set words to the current __WSAFDIsSet import and retains its raw int result and stdcall cleanup.
// R6GameService.dll @ 10037334 : WS2_32.dll ordinal151; callers1002db7e/1002dccc push two words.
__declspec(naked) int __stdcall ForwardWSAFDIsSet(SOCKET socket,fd_set *socketSet)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::WS2_32___WSAFDIsSetSlot
  }
}
