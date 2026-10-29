#include "native_symbols.hpp"
// Executable deleting wrapper around the imported Window log-window destructor.
#include "window_import_support.hpp"
#include "allocation_support.hpp"
#include "launch_runtime.hpp"
#include "game_entry.hpp"

class WLog;
class FArchive;

// RavenShield.exe data @ 10918100 : g_logWindowVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_logWindowVtable[60] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused),             // +000 FCommandTarget::Unused
    NativeAddress(NativeEntry_WLog_ScalarDeletingDestructor),     // +004 WLog::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WWindow_Show),                      // +008 WWindow::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                 // +00c WWindow::Serialize
    NativeAddress(NativeEntry_WLog_GetPackageName),               // +010 WLog::GetPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                 // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WLog_GetWindowClassName),           // +018 WLog::GetWindowClassName
    NativeAddress(NativeEntry_WLog_WndProc),                      // +01c WLog::WndProc
    NativeAddress(NativeEntry_WWindow_CallDefaultProc),           // +020 WWindow::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),   // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                   // +028 WWindow::GetText
    NativeAddress(NativeEntry_WLog_SetText),                      // +02c WLog::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                 // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WLog_OnCopyData),                   // +034 WLog::OnCopyData
    NativeAddress(NativeEntry_WTerminal_OnSetFocus),              // +038 WTerminal::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),               // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WTerminal_OnSize),                  // +040 WTerminal::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),       // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                    // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WLog_OnCommand),                    // +04c WLog::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),              // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WWindow_OnActivate),                // +054 WWindow::OnActivate
    NativeAddress(NativeEntry_WWindow_OnChar),                    // +058 WWindow::OnChar
    NativeAddress(NativeEntry_WWindow_OnKeyDown),                 // +05c WWindow::OnKeyDown
    NativeAddress(NativeEntry_WWindow_OnCut),                     // +060 WWindow::OnCut
    NativeAddress(NativeEntry_WWindow_OnCopy),                    // +064 WWindow::OnCopy
    NativeAddress(NativeEntry_WWindow_OnPaste),                   // +068 WWindow::OnPaste
    NativeAddress(NativeEntry_WLog_OnShowWindow),                 // +06c WLog::OnShowWindow
    NativeAddress(NativeEntry_WWindow_OnUndo),                    // +070 WWindow::OnUndo
    NativeAddress(NativeEntry_WWindow_OnEraseBkgnd),              // +074 WWindow::OnEraseBkgnd
    NativeAddress(NativeEntry_WWindow_OnVScroll),                 // +078 WWindow::OnVScroll
    NativeAddress(NativeEntry_WWindow_OnHScroll),                 // +07c WWindow::OnHScroll
    NativeAddress(NativeEntry_WWindow_OnKeyUp),                   // +080 WWindow::OnKeyUp
    NativeAddress(NativeEntry_WWindow_OnPaint),                   // +084 WWindow::OnPaint
    NativeAddress(NativeEntry_WLog_OnCreate),                     // +088 WLog::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),             // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WWindow_OnInitDialog),              // +094 WWindow::OnInitDialog
    NativeAddress(NativeEntry_WWindow_OnEnterIdle),               // +098 WWindow::OnEnterIdle
    NativeAddress(NativeEntry_WWindow_OnMouseEnter),              // +09c WWindow::OnMouseEnter
    NativeAddress(NativeEntry_WWindow_OnMouseLeave),              // +0a0 WWindow::OnMouseLeave
    NativeAddress(NativeEntry_WWindow_OnMouseHover),              // +0a4 WWindow::OnMouseHover
    NativeAddress(NativeEntry_WWindow_OnTimer),                   // +0a8 WWindow::OnTimer
    NativeAddress(NativeEntry_WWindow_OnReleaseCapture),          // +0ac WWindow::OnReleaseCapture
    NativeAddress(NativeEntry_WWindow_OnMdiActivate),             // +0b0 WWindow::OnMdiActivate
    NativeAddress(NativeEntry_WWindow_OnMouseMove),               // +0b4 WWindow::OnMouseMove
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDown),          // +0b8 WWindow::OnLeftButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDoubleClick),   // +0bc WWindow::OnLeftButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnMiddleButtonDoubleClick), // +0c0 WWindow::OnMiddleButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDoubleClick),  // +0c4 WWindow::OnRightButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDown),         // +0c8 WWindow::OnRightButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonUp),            // +0cc WWindow::OnLeftButtonUp
    NativeAddress(NativeEntry_WWindow_OnRightButtonUp),           // +0d0 WWindow::OnRightButtonUp
    NativeAddress(NativeEntry_WWindow_OnFinishSplitterDrag),      // +0d4 WWindow::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WWindow_OnSetCursor),               // +0d8 WWindow::OnSetCursor
    NativeAddress(NativeEntry_WLog_OnClose),                      // +0dc WLog::OnClose
    NativeAddress(NativeEntry_WLog_OnDestroy),                    // +0e0 WLog::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WTerminal_TypeChar),                // +0e8 WTerminal::TypeChar
    NativeAddress(NativeEntry_WTerminal_Paste),                   // +0ec WTerminal::Paste
};

// Source helper for native inlined WinMain construction: bind Filename/LogAr, then install the EXE table.
// Native 109112ca..109112f6 has no independent constructor entry beyond the external Window.dll call.
void ConstructLaunchLogInline(WLog *storage, uint32_t nameWord)
{
  const auto construct =
      *reinterpret_cast<void(__thiscall **)(WLog *, const uint16_t *, FArchive **, uint32_t, void *)>(
          NativeAddress(NativeImport_WLogConstruct));
  construct(storage, reinterpret_cast<const uint16_t *>(g_launchFileLogStorage + 8),
            reinterpret_cast<FArchive **>(g_launchFileLogStorage + 4), nameWord, nullptr);
  *reinterpret_cast<const uint32_t **>(storage) = g_logWindowVtable;
}

// RavenShield.exe @ 10911890 : WLog::ScalarDeletingDestructor
// Destroy through Window.dll, optionally free with the current Core allocator, then return the original receiver.
WLog *WLog::ScalarDeletingDestructor(uint32_t flags)
{
  const auto destroy = *reinterpret_cast<void(__thiscall **)(WLog *)>(NativeAddress(NativeImport_WLogDestroy));
  destroy(this);
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
} // Native RET 4 consumes the flags word; destructor failure bypasses deallocation and no local guard is added.

// RavenShield.exe @ 10911b06 : WLog::OnDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::OnDestroy()
{
  __asm jmp dword ptr [NativeImport_WLog_OnDestroy]
}

// RavenShield.exe @ 10911b0c : WLog::OnClose
// Tail-forward the void native close callback; do not adopt the supplementary UE2 UBOOL declaration.
__declspec(naked) void WLog::OnClose()
{
  __asm jmp dword ptr [NativeImport_WLog_OnClose]
}

// RavenShield.exe @ 10911b12 : WLog::OnCreate
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::OnCreate()
{
  __asm jmp dword ptr [NativeImport_WLog_OnCreate]
}

// RavenShield.exe @ 10911b18 : WLog::OnShowWindow
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::OnShowWindow(int32_t show)
{
  __asm jmp dword ptr [NativeImport_WLog_OnShowWindow]
}

// RavenShield.exe @ 10911b1e : WLog::OnCommand
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::OnCommand(int32_t command)
{
  __asm jmp dword ptr [NativeImport_WLog_OnCommand]
}

// RavenShield.exe @ 10911b30 : WLog::OnCopyData
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::OnCopyData(HWND__ *sender, tagCOPYDATASTRUCT *data)
{
  __asm jmp dword ptr [NativeImport_WLog_OnCopyData]
}

// RavenShield.exe @ 10911b36 : WLog::SetText
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::SetText(const uint16_t *text)
{
  __asm jmp dword ptr [NativeImport_WLog_SetText]
}

// RavenShield.exe @ 10911b3c : WLog::WndProc
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WLog::WndProc(uint32_t message, uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WLog_WndProc]
}

// RavenShield.exe @ 10911b42 : WLog::GetWindowClassName
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WLog::GetWindowClassName(uint16_t *result)
{
  __asm jmp dword ptr [NativeImport_WLog_GetWindowClassName]
}

// RavenShield.exe @ 10911b48 : WLog::GetPackageName
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WLog::GetPackageName()
{
  __asm jmp dword ptr [NativeImport_WLog_GetPackageName]
}
