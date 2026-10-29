#include "native_symbols.hpp"
// Executable tail-forwarding bodies for imported WWizardPage behavior.
#include "window_import_support.hpp"

// RavenShield.exe @ 10911a28 : WWizardPage::OnCancel
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardPage::OnCancel()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_OnCancel]
}

// RavenShield.exe @ 10911a2e : WWizardPage::GetShow
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWizardPage::GetShow()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetShow]
}

// RavenShield.exe @ 10911a34 : WWizardPage::GetCancelText
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WWizardPage::GetCancelText()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetCancelText]
}

// RavenShield.exe @ 10911a3a : WWizardPage::GetFinishText
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WWizardPage::GetFinishText()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetFinishText]
}

// RavenShield.exe @ 10911a40 : WWizardPage::GetBackText
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WWizardPage::GetBackText()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetBackText]
}

// RavenShield.exe @ 10911a46 : WWizardPage::OnCurrent
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardPage::OnCurrent()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_OnCurrent]
}

// RavenShield.exe @ 10911aee : WWizardPage::GetNextText
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WWizardPage::GetNextText()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetNextText]
}

// RavenShield.exe @ 10911af4 : WWizardPage::GetNext
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) WWizardPage *WWizardPage::GetNext()
{
  __asm jmp dword ptr [NativeImport_WWizardPage_GetNext]
}
