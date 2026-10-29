#include "native_symbols.hpp"
// Executable deleting wrapper around the imported configuration-properties destructor.
#include "window_import_support.hpp"
#include "allocation_support.hpp"
#include "exec_hook_support.hpp"

class WConfigProperties;

// RavenShield.exe data @ 109161e0 : g_configPropertiesVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_configPropertiesVtable[65] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigProperties_ScalarDeletingDestructor),     // +004 WConfigProperties::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WWindow_Show),                         // +008 WWindow::Show
    NativeAddress(NativeEntry_WProperties_Serialize),                // +00c WProperties::Serialize
    NativeAddress(NativeEntry_WConfigProperties_GetPackageName),     // +010 WConfigProperties::GetPackageName
    NativeAddress(NativeEntry_WProperties_DoDestroy),                // +014 WProperties::DoDestroy
    NativeAddress(NativeEntry_WConfigProperties_GetWindowClassName), // +018 WConfigProperties::GetWindowClassName
    NativeAddress(NativeEntry_WWindow_WndProc),                      // +01c WWindow::WndProc
    NativeAddress(NativeEntry_WWindow_CallDefaultProc),              // +020 WWindow::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),      // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                      // +028 WWindow::GetText
    NativeAddress(NativeEntry_WWindow_SetText),                      // +02c WWindow::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                    // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WWindow_OnCopyData),                   // +034 WWindow::OnCopyData
    NativeAddress(NativeEntry_WWindow_OnSetFocus),                   // +038 WWindow::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),                  // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WProperties_OnSize),                   // +040 WProperties::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),          // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                       // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WWindow_OnCommand),                    // +04c WWindow::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),                 // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WProperties_OnActivate),               // +054 WProperties::OnActivate
    NativeAddress(NativeEntry_WWindow_OnChar),                       // +058 WWindow::OnChar
    NativeAddress(NativeEntry_WWindow_OnKeyDown),                    // +05c WWindow::OnKeyDown
    NativeAddress(NativeEntry_WWindow_OnCut),                        // +060 WWindow::OnCut
    NativeAddress(NativeEntry_WWindow_OnCopy),                       // +064 WWindow::OnCopy
    NativeAddress(NativeEntry_WWindow_OnPaste),                      // +068 WWindow::OnPaste
    NativeAddress(NativeEntry_WWindow_OnShowWindow),                 // +06c WWindow::OnShowWindow
    NativeAddress(NativeEntry_WWindow_OnUndo),                       // +070 WWindow::OnUndo
    NativeAddress(NativeEntry_WWindow_OnEraseBkgnd),                 // +074 WWindow::OnEraseBkgnd
    NativeAddress(NativeEntry_WWindow_OnVScroll),                    // +078 WWindow::OnVScroll
    NativeAddress(NativeEntry_WWindow_OnHScroll),                    // +07c WWindow::OnHScroll
    NativeAddress(NativeEntry_WWindow_OnKeyUp),                      // +080 WWindow::OnKeyUp
    NativeAddress(NativeEntry_WProperties_OnPaint),                  // +084 WProperties::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                     // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                   // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),                // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WWindow_OnInitDialog),                 // +094 WWindow::OnInitDialog
    NativeAddress(NativeEntry_WWindow_OnEnterIdle),                  // +098 WWindow::OnEnterIdle
    NativeAddress(NativeEntry_WWindow_OnMouseEnter),                 // +09c WWindow::OnMouseEnter
    NativeAddress(NativeEntry_WWindow_OnMouseLeave),                 // +0a0 WWindow::OnMouseLeave
    NativeAddress(NativeEntry_WWindow_OnMouseHover),                 // +0a4 WWindow::OnMouseHover
    NativeAddress(NativeEntry_WWindow_OnTimer),                      // +0a8 WWindow::OnTimer
    NativeAddress(NativeEntry_WWindow_OnReleaseCapture),             // +0ac WWindow::OnReleaseCapture
    NativeAddress(NativeEntry_WWindow_OnMdiActivate),                // +0b0 WWindow::OnMdiActivate
    NativeAddress(NativeEntry_WWindow_OnMouseMove),                  // +0b4 WWindow::OnMouseMove
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDown),             // +0b8 WWindow::OnLeftButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDoubleClick),      // +0bc WWindow::OnLeftButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnMiddleButtonDoubleClick),    // +0c0 WWindow::OnMiddleButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDoubleClick),     // +0c4 WWindow::OnRightButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDown),            // +0c8 WWindow::OnRightButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonUp),               // +0cc WWindow::OnLeftButtonUp
    NativeAddress(NativeEntry_WWindow_OnRightButtonUp),              // +0d0 WWindow::OnRightButtonUp
    NativeAddress(NativeEntry_WProperties_OnFinishSplitterDrag),     // +0d4 WProperties::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WProperties_OnSetCursor),              // +0d8 WProperties::OnSetCursor
    NativeAddress(NativeEntry_WWindow_OnClose),                      // +0dc WWindow::OnClose
    NativeAddress(NativeEntry_WProperties_OnDestroy),                // +0e0 WProperties::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                   // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WConfigProperties_GetRoot),            // +0e8 WConfigProperties::GetRoot
    NativeAddress(NativeEntry_WProperties_GetDividerWidth),          // +0ec WProperties::GetDividerWidth
    NativeAddress(NativeEntry_WProperties_ResizeList),               // +0f0 WProperties::ResizeList
    NativeAddress(NativeEntry_WProperties_SetItemFocus),             // +0f4 WProperties::SetItemFocus
    NativeAddress(NativeEntry_WProperties_ForceRefresh),             // +0f8 WProperties::ForceRefresh
    NativeAddress(NativeEntry_WProperties_BeginSplitterDrag),        // +0fc WProperties::BeginSplitterDrag
    NativeAddress(NativeEntry_WProperties_SetValue),                 // +100 WProperties::SetValue
};

// Source helper for native inlined Exec construction: call the import, then install the executable class table.
// No independent native constructor entry is identified for these operations inside 10908150.
void ConstructExecConfigPropertiesInline(WConfigProperties *storage, uint32_t nameWord, const uint16_t *title)
{
  const auto construct = *reinterpret_cast<void(__thiscall **)(WConfigProperties *, uint32_t, const uint16_t *)>(
      NativeAddress(NativeImport_WConfigPropertiesConstruct));
  construct(storage, nameWord, title);
  *reinterpret_cast<const uint32_t **>(storage) = g_configPropertiesVtable;
}
// RavenShield.exe @ 10908f20 : WConfigProperties::ScalarDeletingDestructor
// Destroy through Window.dll, optionally free with the current Core allocator, then return the original receiver.
WConfigProperties *WConfigProperties::ScalarDeletingDestructor(uint32_t flags)
{
  const auto destroy =
      *reinterpret_cast<void(__thiscall **)(WConfigProperties *)>(NativeAddress(NativeImport_WConfigPropertiesDestroy));
  destroy(this);
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
} // Native RET 4 consumes the flags word; destruction failure bypasses free without a local cleanup guard.

// RavenShield.exe @ 10911a5e : WConfigProperties::GetRoot
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) FTreeItem *WConfigProperties::GetRoot()
{
  __asm jmp dword ptr [NativeImport_WConfigProperties_GetRoot]
}

// RavenShield.exe @ 10911a64 : WConfigProperties::GetWindowClassName
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WConfigProperties::GetWindowClassName(uint16_t *result)
{
  __asm jmp dword ptr [NativeImport_WConfigProperties_GetWindowClassName]
}

// RavenShield.exe @ 10911a6a : WConfigProperties::GetPackageName
// Tail-forward the receiver and arguments, preserving the imported pointer result and ownership.
__declspec(naked) const uint16_t *WConfigProperties::GetPackageName()
{
  __asm jmp dword ptr [NativeImport_WConfigProperties_GetPackageName]
}
