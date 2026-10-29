#include "native_symbols.hpp"
// Executable tail-forwarding bodies for imported WWizardDialog behavior.
#include "window_import_support.hpp"

// RavenShield.exe @ 109118b4 : WWizardDialog::OnCancel
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::OnCancel()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnCancel]
}

// RavenShield.exe @ 109118ba : WWizardDialog::OnFinish
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::OnFinish()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnFinish]
}

// RavenShield.exe @ 109118c0 : WWizardDialog::OnNext
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::OnNext()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnNext]
}

// RavenShield.exe @ 109118c6 : WWizardDialog::OnBack
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::OnBack()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnBack]
}

// RavenShield.exe @ 109118cc : WWizardDialog::RefreshPage
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::RefreshPage()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_RefreshPage]
}

// RavenShield.exe @ 109118d2 : WWizardDialog::Advance
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::Advance(WWizardPage *page)
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_Advance]
}

// RavenShield.exe @ 109118ea : WWizardDialog::OnDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWizardDialog::OnDestroy()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnDestroy]
}

// RavenShield.exe @ 109118f0 : WWizardDialog::OnClose
// Tail-forward the void native close callback; do not adopt the supplementary UE2 UBOOL declaration.
__declspec(naked) void WWizardDialog::OnClose()
{
  __asm jmp dword ptr [NativeImport_WWizardDialog_OnClose]
}
