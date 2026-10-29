#include "native_symbols.hpp"
// Executable tail-forwarding bodies for imported FCommandTarget behavior.
#include "window_import_support.hpp"

// RavenShield.exe @ 10911a22 : FCommandTarget::Unused
// Tail-forward the imported command-target slot; the executable body itself is not a local no-op.
__declspec(naked) void FCommandTarget::Unused()
{
  __asm jmp dword ptr [NativeImport_FCommandTarget_Unused]
}
