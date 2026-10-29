#include "native_symbols.hpp"
// Native page members: Owner +40, WUrlButton +44, WLabel +ec; allocation extent 12ch.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include "allocation_support.hpp"
#include "window_delegate.hpp"
#include <new>

class WConfigWizard;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);
extern const char16_t g_launcherStartupPackage[];
extern const uint16_t *__cdecl LocalizeGeneral(const uint16_t *key, const uint16_t *package, const uint16_t *language);

// RavenShield.exe data @ 109171c0 : g_driverPageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_driverPageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageDriver_ScalarDeletingDestructor),     // +004 WConfigPageDriver::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                         // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                    // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),         // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                    // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigPageDriver_GetWindowClassName), // +018 WConfigPageDriver::GetWindowClassName
    NativeAddress(NativeEntry_WWindow_WndProc),                      // +01c WWindow::WndProc
    NativeAddress(NativeEntry_WDialog_CallDefaultProc),              // +020 WDialog::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),      // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                      // +028 WWindow::GetText
    NativeAddress(NativeEntry_WWindow_SetText),                      // +02c WWindow::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                    // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WWindow_OnCopyData),                   // +034 WWindow::OnCopyData
    NativeAddress(NativeEntry_WWindow_OnSetFocus),                   // +038 WWindow::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),                  // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WWindow_OnSize),                       // +040 WWindow::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),          // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                       // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WWindow_OnCommand),                    // +04c WWindow::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),                 // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WWindow_OnActivate),                   // +054 WWindow::OnActivate
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
    NativeAddress(NativeEntry_WWindow_OnPaint),                      // +084 WWindow::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                     // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                   // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),                // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WConfigPageDriver_OnInitDialog),       // +094 WConfigPageDriver::OnInitDialog
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
    NativeAddress(NativeEntry_WWindow_OnFinishSplitterDrag),         // +0d4 WWindow::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WWindow_OnSetCursor),                  // +0d8 WWindow::OnSetCursor
    NativeAddress(NativeEntry_WWindow_OnClose),                      // +0dc WWindow::OnClose
    NativeAddress(NativeEntry_WWindow_OnDestroy),                    // +0e0 WWindow::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                   // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WDialog_DoModal),                      // +0e8 WDialog::DoModal
    NativeAddress(NativeEntry_WDialog_LocalizeText),                 // +0ec WDialog::LocalizeText
    NativeAddress(NativeEntry_WWizardPage_OnCurrent),                // +0f0 WWizardPage::OnCurrent
    NativeAddress(NativeEntry_WConfigPageDriver_GetNext),            // +0f4 WConfigPageDriver::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),              // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WWizardPage_GetNextText),              // +0fc WWizardPage::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),            // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),            // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                  // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                 // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 109171a0 : g_driverDirect3DWebPageKey
const char16_t g_driverDirect3DWebPageKey[] = u"Direct3DWebPage";

// RavenShield.exe data @ 109172d0 : g_driverPageKey
const char16_t g_driverPageKey[] = u"ConfigPageDriver";
// RavenShield.exe data @ 1091735c : g_driverPageClassName
const char16_t g_driverPageClassName[] = u"WConfigPageDriver";

// RavenShield.exe @ 1090c220 : WConfigPageDriver::WConfigPageDriver
// Construct the base and owner, localize the URL button target, then construct the label.
WConfigPageDriver::WConfigPageDriver(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_driverPageKey), 0x7e6, owner), Owner(owner),
      DriverLink(this,
                 LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_driverDirect3DWebPageKey),
                                 reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr),
                 0x459),
      InfoLabel(this, 0x457, nullptr)
{
} // Native primary table 109171c0; completed URL button/base are cleaned if label construction throws.

// RavenShield.exe @ 1090c580 : WConfigPageDriver::GetWindowClassName
// Format this page's native package-qualified class name into the caller's unbounded UTF-16 buffer.
void WConfigPageDriver::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_driverPageClassName));
}

// RavenShield.exe @ 10912910 : UnwindDriverPageConstructionBase
// Destroy the completed WWizardPage base from the constructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDriverPageConstructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912919 : UnwindDriverPageConstructionLink
// Destroy the completed URL button at page +44 when later label construction fails.
__declspec(naked) void UnwindDriverPageConstructionLink()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WUrlButtonDestroy]
  }
}

// RavenShield.exe data @ 10919ddc : g_driverPageConstructionUnwind
const NativeCppUnwindEntry g_driverPageConstructionUnwind[2] = {
    {-1, NativeAddress(NativeEntry_UnwindDriverPageConstructionBase)}, // UnwindDriverPageConstructionBase
    {0, NativeAddress(NativeEntry_UnwindDriverPageConstructionLink)},  // UnwindDriverPageConstructionLink
};

// RavenShield.exe data @ 10919dec : g_driverPageConstructionExceptionInfo
const NativeCppFunctionInfo g_driverPageConstructionExceptionInfo = {
    0x19930520, 2, NativeAddress(g_driverPageConstructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912925 : HandleDriverPageConstructionException
// Dispatch completed-base/link states without cleaning an unfinished control or the outer allocation.
__declspec(naked) void HandleDriverPageConstructionException()
{
  __asm {
    mov eax, offset g_driverPageConstructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090c430 : WConfigPageDriver::~WConfigPageDriver
// Tear down the window before reverse-order automatic control and WWizardPage base destruction.
WConfigPageDriver::~WConfigPageDriver() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_driverPageVtable;
  WWindow::MaybeDestroy();
} // Native primary table 109171c0; member/base cleanup also runs if MaybeDestroy throws.

// RavenShield.exe @ 1090c400 : WConfigPageDriver::ScalarDeletingDestructor
// Destroy the page, free storage only for flag bit zero, and return the saved receiver even after freeing it.
WConfigPageDriver *WConfigPageDriver::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageDriver::~WConfigPageDriver();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 10912930 : UnwindDriverPageDestructionBase
// Destroy the completed base through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDriverPageDestructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912939 : UnwindDriverPageDestructionLink
// Destroy the completed link control at page +44 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDriverPageDestructionLink()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WUrlButtonDestroy]
  }
}

// RavenShield.exe @ 10912945 : UnwindDriverPageDestructionLabel
// Destroy the completed label control at page +ec through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDriverPageDestructionLabel()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 0ech
    jmp dword ptr [NativeImport_WLabelDestroy]
  }
}

// RavenShield.exe data @ 10919e50 : g_driverPageDestructionUnwind
const NativeCppUnwindEntry g_driverPageDestructionUnwind[3] = {
    {-1, NativeAddress(NativeEntry_UnwindDriverPageDestructionBase)}, // UnwindDriverPageDestructionBase
    {0, NativeAddress(NativeEntry_UnwindDriverPageDestructionLink)},  // UnwindDriverPageDestructionLink
    {1, NativeAddress(NativeEntry_UnwindDriverPageDestructionLabel)}, // UnwindDriverPageDestructionLabel
};

// RavenShield.exe data @ 10919e68 : g_driverPageDestructionExceptionInfo
const NativeCppFunctionInfo g_driverPageDestructionExceptionInfo = {
    0x19930520, 3, NativeAddress(g_driverPageDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912954 : HandleDriverPageDestructionException
// Dispatch the 3 completed-control/base states independently of the constructor cleanup map.
__declspec(naked) void HandleDriverPageDestructionException()
{
  __asm {
    mov eax, offset g_driverPageDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FConfigCache;
class WConfigPageDetail;
extern FConfigCache *GConfig;
extern const char16_t g_rendererDirect3DClass[];
extern const char16_t g_configEmptyString[];

// RavenShield.exe data @ 109172f4 : g_driverDescriptionKey
const char16_t g_driverDescriptionKey[] = u"Description";

// RavenShield.exe @ 1090c2d0 : WConfigPageDriver::OnInitDialog
// Initialize the base dialog, copy the configured Direct3D description and update the label only when nonempty.
void WConfigPageDriver::OnInitDialog()
{
  WDialog::OnInitDialog();
  FConfigCache *dispatchConfig = GConfig;
  FConfigCache *receiver = GConfig;
  const uint32_t configTable = *reinterpret_cast<const uint32_t *>(dispatchConfig);
  using GetConfigString =
      const uint16_t *(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *);
  const uint16_t *configured = (*reinterpret_cast<const GetConfigString *>(configTable + 0x14))(
      receiver, reinterpret_cast<const uint16_t *>(g_rendererDirect3DClass),
      reinterpret_cast<const uint16_t *>(g_driverDescriptionKey), nullptr);
  FString description(configured);
  if (description != reinterpret_cast<const uint16_t *>(g_configEmptyString))
  {
    const uint16_t *text = *description;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(&InfoLabel);
    const auto setText = *reinterpret_cast<void(__thiscall **)(WLabel *, const uint16_t *)>(table + 0x2c);
    setText(&InfoLabel, text);
  }
} // Shared string cleanup 10912500/10912509 is canonical in wizard_page_support.cpp.

// RavenShield.exe @ 1090c380 : WConfigPageDriver::GetNext
// Allocate and construct a detail page with the current owner, retaining null allocation and failure cleanup.
WWizardPage *WConfigPageDriver::GetNext()
{
  void *allocation = AllocateExecutableBytes(0x90);
  if (allocation == nullptr) return nullptr;
  try
  {
    return new (allocation) WConfigPageDetail(Owner);
  }
  catch (...)
  {
    FreeExecutableAllocation(allocation);
    throw;
  }
} // Shared allocation cleanup 109128d0/109128db is canonical in wizard_page_support.cpp.
