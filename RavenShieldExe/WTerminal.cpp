#include "native_symbols.hpp"
// Executable tail-forwarding bodies for imported WTerminal behavior.
#include "window_import_support.hpp"

// RavenShield.exe @ 10911afa : WTerminal::Paste
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WTerminal::Paste()
{
  __asm jmp dword ptr [NativeImport_WTerminal_Paste]
}

// RavenShield.exe @ 10911b00 : WTerminal::TypeChar
// Tail-forward the UTF-16 input argument without rewriting its caller-provided stack word.
__declspec(naked) void WTerminal::TypeChar(uint16_t character)
{
  __asm jmp dword ptr [NativeImport_WTerminal_TypeChar]
}

// RavenShield.exe @ 10911b24 : WTerminal::OnSize
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WTerminal::OnSize(uint32_t flags, int32_t width, int32_t height)
{
  __asm jmp dword ptr [NativeImport_WTerminal_OnSize]
}

// RavenShield.exe @ 10911b2a : WTerminal::OnSetFocus
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WTerminal::OnSetFocus(HWND__ *losingFocus)
{
  __asm jmp dword ptr [NativeImport_WTerminal_OnSetFocus]
}
