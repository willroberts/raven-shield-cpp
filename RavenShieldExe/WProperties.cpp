#include "native_symbols.hpp"
// Executable forwarding body for the imported properties-window refresh method.
#include "window_import_support.hpp"
class WProperties;

// RavenShield.exe @ 10911a82 : WProperties::ForceRefresh
// Tail-forward the receiver to the imported properties refresh implementation without arguments or local effects.
__declspec(naked) void WProperties::ForceRefresh()
{
  __asm jmp dword ptr [NativeImport_WProperties_ForceRefresh]
}

// RavenShield.exe @ 10911a76 : WProperties::SetValue
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::SetValue(const uint16_t *value)
{
  __asm jmp dword ptr [NativeImport_WProperties_SetValue]
}

// RavenShield.exe @ 10911a7c : WProperties::BeginSplitterDrag
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::BeginSplitterDrag()
{
  __asm jmp dword ptr [NativeImport_WProperties_BeginSplitterDrag]
}

// RavenShield.exe @ 10911a88 : WProperties::SetItemFocus
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::SetItemFocus(int32_t focus)
{
  __asm jmp dword ptr [NativeImport_WProperties_SetItemFocus]
}

// RavenShield.exe @ 10911a8e : WProperties::ResizeList
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::ResizeList()
{
  __asm jmp dword ptr [NativeImport_WProperties_ResizeList]
}

// RavenShield.exe @ 10911a94 : WProperties::GetDividerWidth
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WProperties::GetDividerWidth()
{
  __asm jmp dword ptr [NativeImport_WProperties_GetDividerWidth]
}

// RavenShield.exe @ 10911aa0 : WProperties::OnDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::OnDestroy()
{
  __asm jmp dword ptr [NativeImport_WProperties_OnDestroy]
}

// RavenShield.exe @ 10911aa6 : WProperties::OnSetCursor
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WProperties::OnSetCursor()
{
  __asm jmp dword ptr [NativeImport_WProperties_OnSetCursor]
}

// RavenShield.exe @ 10911aac : WProperties::OnFinishSplitterDrag
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::OnFinishSplitterDrag(WDragInterceptor *drag, int32_t success)
{
  __asm jmp dword ptr [NativeImport_WProperties_OnFinishSplitterDrag]
}

// RavenShield.exe @ 10911ab8 : WProperties::OnPaint
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::OnPaint()
{
  __asm jmp dword ptr [NativeImport_WProperties_OnPaint]
}

// RavenShield.exe @ 10911abe : WProperties::OnActivate
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::OnActivate(int32_t active)
{
  __asm jmp dword ptr [NativeImport_WProperties_OnActivate]
}

// RavenShield.exe @ 10911ac4 : WProperties::OnSize
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::OnSize(uint32_t flags, int32_t width, int32_t height)
{
  __asm jmp dword ptr [NativeImport_WProperties_OnSize]
}

// RavenShield.exe @ 10911ad6 : WProperties::DoDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WProperties::DoDestroy()
{
  __asm jmp dword ptr [NativeImport_WProperties_DoDestroy]
}

// RavenShield.exe @ 10911ae2 : WProperties::Serialize
// Tail-forward the archive reference without adding local serialization or changing the receiver.
__declspec(naked) void WProperties::Serialize(FArchive &archive)
{
  __asm jmp dword ptr [NativeImport_WProperties_Serialize]
}
