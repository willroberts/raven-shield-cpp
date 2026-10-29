#include "native_symbols.hpp"
// Native first-time page has an Owner pointer at +40 and a caller allocation extent of 44h.
#include "allocation_support.hpp"

class WConfigWizard;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);

// RavenShield.exe data @ 10917068 : g_firstTimePageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_firstTimePageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageFirstTime_ScalarDeletingDestructor), // +004
                                                                    // WConfigPageFirstTime::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                        // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                   // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),        // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                   // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigPageFirstTime_GetWindowClassName), // +018 WConfigPageFirstTime::GetWindowClassName
    NativeAddress(NativeEntry_WWindow_WndProc),                         // +01c WWindow::WndProc
    NativeAddress(NativeEntry_WDialog_CallDefaultProc),                 // +020 WDialog::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),         // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                         // +028 WWindow::GetText
    NativeAddress(NativeEntry_WWindow_SetText),                         // +02c WWindow::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                       // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WWindow_OnCopyData),                      // +034 WWindow::OnCopyData
    NativeAddress(NativeEntry_WWindow_OnSetFocus),                      // +038 WWindow::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),                     // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WWindow_OnSize),                          // +040 WWindow::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),             // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                          // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WWindow_OnCommand),                       // +04c WWindow::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),                    // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WWindow_OnActivate),                      // +054 WWindow::OnActivate
    NativeAddress(NativeEntry_WWindow_OnChar),                          // +058 WWindow::OnChar
    NativeAddress(NativeEntry_WWindow_OnKeyDown),                       // +05c WWindow::OnKeyDown
    NativeAddress(NativeEntry_WWindow_OnCut),                           // +060 WWindow::OnCut
    NativeAddress(NativeEntry_WWindow_OnCopy),                          // +064 WWindow::OnCopy
    NativeAddress(NativeEntry_WWindow_OnPaste),                         // +068 WWindow::OnPaste
    NativeAddress(NativeEntry_WWindow_OnShowWindow),                    // +06c WWindow::OnShowWindow
    NativeAddress(NativeEntry_WWindow_OnUndo),                          // +070 WWindow::OnUndo
    NativeAddress(NativeEntry_WWindow_OnEraseBkgnd),                    // +074 WWindow::OnEraseBkgnd
    NativeAddress(NativeEntry_WWindow_OnVScroll),                       // +078 WWindow::OnVScroll
    NativeAddress(NativeEntry_WWindow_OnHScroll),                       // +07c WWindow::OnHScroll
    NativeAddress(NativeEntry_WWindow_OnKeyUp),                         // +080 WWindow::OnKeyUp
    NativeAddress(NativeEntry_WWindow_OnPaint),                         // +084 WWindow::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                        // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                      // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),                   // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WDialog_OnInitDialog),                    // +094 WDialog::OnInitDialog
    NativeAddress(NativeEntry_WWindow_OnEnterIdle),                     // +098 WWindow::OnEnterIdle
    NativeAddress(NativeEntry_WWindow_OnMouseEnter),                    // +09c WWindow::OnMouseEnter
    NativeAddress(NativeEntry_WWindow_OnMouseLeave),                    // +0a0 WWindow::OnMouseLeave
    NativeAddress(NativeEntry_WWindow_OnMouseHover),                    // +0a4 WWindow::OnMouseHover
    NativeAddress(NativeEntry_WWindow_OnTimer),                         // +0a8 WWindow::OnTimer
    NativeAddress(NativeEntry_WWindow_OnReleaseCapture),                // +0ac WWindow::OnReleaseCapture
    NativeAddress(NativeEntry_WWindow_OnMdiActivate),                   // +0b0 WWindow::OnMdiActivate
    NativeAddress(NativeEntry_WWindow_OnMouseMove),                     // +0b4 WWindow::OnMouseMove
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDown),                // +0b8 WWindow::OnLeftButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDoubleClick),         // +0bc WWindow::OnLeftButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnMiddleButtonDoubleClick),       // +0c0 WWindow::OnMiddleButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDoubleClick),        // +0c4 WWindow::OnRightButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDown),               // +0c8 WWindow::OnRightButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonUp),                  // +0cc WWindow::OnLeftButtonUp
    NativeAddress(NativeEntry_WWindow_OnRightButtonUp),                 // +0d0 WWindow::OnRightButtonUp
    NativeAddress(NativeEntry_WWindow_OnFinishSplitterDrag),            // +0d4 WWindow::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WWindow_OnSetCursor),                     // +0d8 WWindow::OnSetCursor
    NativeAddress(NativeEntry_WWindow_OnClose),                         // +0dc WWindow::OnClose
    NativeAddress(NativeEntry_WWindow_OnDestroy),                       // +0e0 WWindow::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                      // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WDialog_DoModal),                         // +0e8 WDialog::DoModal
    NativeAddress(NativeEntry_WDialog_LocalizeText),                    // +0ec WDialog::LocalizeText
    NativeAddress(NativeEntry_WWizardPage_OnCurrent),                   // +0f0 WWizardPage::OnCurrent
    NativeAddress(NativeEntry_WConfigPageFirstTime_GetNext),            // +0f4 WConfigPageFirstTime::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),                 // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WConfigPageSafeOptions_GetNextText),      // +0fc WConfigPageSafeOptions::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),               // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),               // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                     // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                    // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 10917178 : g_firstTimePageKey
const char16_t g_firstTimePageKey[] = u"ConfigPageFirstTime";
// RavenShield.exe data @ 1091730c : g_firstTimePageClassName
const char16_t g_firstTimePageClassName[] = u"WConfigPageFirstTime";

// Construct the base and store the owner; inlined in WConfigPageDetail::GetNext at 1090c0f8, no standalone body.
WConfigPageFirstTime::WConfigPageFirstTime(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_firstTimePageKey), 0x7e3, owner), Owner(owner)
{
} // Native primary table 10917068 is selected between base construction and the +40 owner store.

// RavenShield.exe @ 1090c160 : WConfigPageFirstTime::GetNext
// End the owning wizard with result one, then return a genuine null next-page pointer.
WWizardPage *WConfigPageFirstTime::GetNext()
{
  Owner->EndDialog(1);
  return nullptr;
}

// RavenShield.exe @ 1090c4b0 : WConfigPageFirstTime::GetWindowClassName
// Format this page's native package-qualified class name into the caller's unbounded UTF-16 buffer.
void WConfigPageFirstTime::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_firstTimePageClassName));
}

// RavenShield.exe @ 1090c500 : WConfigPageFirstTime::~WConfigPageFirstTime
// Tear down the window before automatic base destruction, including when MaybeDestroy throws.
WConfigPageFirstTime::~WConfigPageFirstTime() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_firstTimePageVtable;
  WWindow::MaybeDestroy();
} // Native table 10917068; shared base-only cleanup 109127d0/109127d9 is in wizard_page_support.cpp.

// RavenShield.exe @ 1090c4d0 : WConfigPageFirstTime::ScalarDeletingDestructor
// Destroy the page, free storage only for flag bit zero, and return the original receiver.
WConfigPageFirstTime *WConfigPageFirstTime::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageFirstTime::~WConfigPageFirstTime();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}
