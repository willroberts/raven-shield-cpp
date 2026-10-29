#include "native_symbols.hpp"
// Shared runtime bodies keep one definition even when several unrelated class vtables refer to them.
#include <cstdint>

// RavenShield.exe @ 109041b0 : IgnoreSharedVirtualArgument
// Ignore the ECX receiver and one stack word, preserve EAX and return while discarding the four-byte argument.
__declspec(naked) void __stdcall IgnoreSharedVirtualArgument(uint32_t ignoredArgument)
{
  __asm ret 4
}
