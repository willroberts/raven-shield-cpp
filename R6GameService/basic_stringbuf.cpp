#include "native_addresses.h"

// Tail the current imported wide string-buffer destructor with original receiver, frame and register effects.
// R6GameService.dll @ 10004300 : complete six-byte current-IAT member tail.
__declspec(naked) void __thiscall
std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,
                    std::allocator<unsigned short>>::~basic_stringbuf(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringbufSlot
  }
}
