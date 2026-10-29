#include "native_symbols.hpp"
// Executable tail-forwarding bodies for imported WDialog behavior.
#include "window_import_support.hpp"

// RavenShield.exe @ 109118d8 : WDialog::LocalizeText
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WDialog::LocalizeText(const uint16_t *section, const uint16_t *package)
{
  __asm jmp dword ptr [NativeImport_WDialog_LocalizeText]
}

// RavenShield.exe @ 109118de : WDialog::DoModal
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WDialog::DoModal(HINSTANCE__ *instance)
{
  __asm jmp dword ptr [NativeImport_WDialog_DoModal]
}

// RavenShield.exe @ 10911a04 : WDialog::CallDefaultProc
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WDialog::CallDefaultProc(uint32_t message, uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WDialog_CallDefaultProc]
}

// RavenShield.exe @ 10911a1c : WDialog::Show
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WDialog::Show(int32_t show)
{
  __asm jmp dword ptr [NativeImport_WDialog_Show]
}

// RavenShield.exe @ 10911a58 : WDialog::OnInitDialog
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WDialog::OnInitDialog()
{
  __asm jmp dword ptr [NativeImport_WDialog_OnInitDialog]
}
