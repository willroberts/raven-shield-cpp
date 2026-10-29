#include "native_symbols.hpp"
// Native page members: Owner +40 and four 9c-byte WCoolButtons at +44/+e0/+17c/+218.
#include "cpp_exception_metadata.hpp"
// Button/callback names describe their native bindings; complete page/base declarations remain partial.
#include <cstdint>
#include "allocation_support.hpp"
#include "window_delegate.hpp"
#include <new>
#include <malloc.h>

class WConfigPageSafeMode;
class WConfigWizard;
class WWindow;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 10917448 : g_safeModePageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_safeModePageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageSafeMode_ScalarDeletingDestructor), // +004 WConfigPageSafeMode::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                       // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                  // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),       // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                  // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigPageSafeMode_GetWindowClassName), // +018 WConfigPageSafeMode::GetWindowClassName
    NativeAddress(NativeEntry_WWindow_WndProc),                        // +01c WWindow::WndProc
    NativeAddress(NativeEntry_WDialog_CallDefaultProc),                // +020 WDialog::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),        // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                        // +028 WWindow::GetText
    NativeAddress(NativeEntry_WWindow_SetText),                        // +02c WWindow::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                      // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WWindow_OnCopyData),                     // +034 WWindow::OnCopyData
    NativeAddress(NativeEntry_WWindow_OnSetFocus),                     // +038 WWindow::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),                    // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WWindow_OnSize),                         // +040 WWindow::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),            // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                         // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WWindow_OnCommand),                      // +04c WWindow::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),                   // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WWindow_OnActivate),                     // +054 WWindow::OnActivate
    NativeAddress(NativeEntry_WWindow_OnChar),                         // +058 WWindow::OnChar
    NativeAddress(NativeEntry_WWindow_OnKeyDown),                      // +05c WWindow::OnKeyDown
    NativeAddress(NativeEntry_WWindow_OnCut),                          // +060 WWindow::OnCut
    NativeAddress(NativeEntry_WWindow_OnCopy),                         // +064 WWindow::OnCopy
    NativeAddress(NativeEntry_WWindow_OnPaste),                        // +068 WWindow::OnPaste
    NativeAddress(NativeEntry_WWindow_OnShowWindow),                   // +06c WWindow::OnShowWindow
    NativeAddress(NativeEntry_WWindow_OnUndo),                         // +070 WWindow::OnUndo
    NativeAddress(NativeEntry_WWindow_OnEraseBkgnd),                   // +074 WWindow::OnEraseBkgnd
    NativeAddress(NativeEntry_WWindow_OnVScroll),                      // +078 WWindow::OnVScroll
    NativeAddress(NativeEntry_WWindow_OnHScroll),                      // +07c WWindow::OnHScroll
    NativeAddress(NativeEntry_WWindow_OnKeyUp),                        // +080 WWindow::OnKeyUp
    NativeAddress(NativeEntry_WWindow_OnPaint),                        // +084 WWindow::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                       // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                     // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),                  // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WDialog_OnInitDialog),                   // +094 WDialog::OnInitDialog
    NativeAddress(NativeEntry_WWindow_OnEnterIdle),                    // +098 WWindow::OnEnterIdle
    NativeAddress(NativeEntry_WWindow_OnMouseEnter),                   // +09c WWindow::OnMouseEnter
    NativeAddress(NativeEntry_WWindow_OnMouseLeave),                   // +0a0 WWindow::OnMouseLeave
    NativeAddress(NativeEntry_WWindow_OnMouseHover),                   // +0a4 WWindow::OnMouseHover
    NativeAddress(NativeEntry_WWindow_OnTimer),                        // +0a8 WWindow::OnTimer
    NativeAddress(NativeEntry_WWindow_OnReleaseCapture),               // +0ac WWindow::OnReleaseCapture
    NativeAddress(NativeEntry_WWindow_OnMdiActivate),                  // +0b0 WWindow::OnMdiActivate
    NativeAddress(NativeEntry_WWindow_OnMouseMove),                    // +0b4 WWindow::OnMouseMove
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDown),               // +0b8 WWindow::OnLeftButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDoubleClick),        // +0bc WWindow::OnLeftButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnMiddleButtonDoubleClick),      // +0c0 WWindow::OnMiddleButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDoubleClick),       // +0c4 WWindow::OnRightButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDown),              // +0c8 WWindow::OnRightButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonUp),                 // +0cc WWindow::OnLeftButtonUp
    NativeAddress(NativeEntry_WWindow_OnRightButtonUp),                // +0d0 WWindow::OnRightButtonUp
    NativeAddress(NativeEntry_WWindow_OnFinishSplitterDrag),           // +0d4 WWindow::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WWindow_OnSetCursor),                    // +0d8 WWindow::OnSetCursor
    NativeAddress(NativeEntry_WWindow_OnClose),                        // +0dc WWindow::OnClose
    NativeAddress(NativeEntry_WWindow_OnDestroy),                      // +0e0 WWindow::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                     // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WDialog_DoModal),                        // +0e8 WDialog::DoModal
    NativeAddress(NativeEntry_WDialog_LocalizeText),                   // +0ec WDialog::LocalizeText
    NativeAddress(NativeEntry_WWizardPage_OnCurrent),                  // +0f0 WWizardPage::OnCurrent
    NativeAddress(NativeEntry_WWizardPage_GetNext),                    // +0f4 WWizardPage::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),                // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WConfigPageSafeMode_GetNextText),        // +0fc WConfigPageSafeMode::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),              // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),              // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                    // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                   // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 10917558 : g_safeModePageKey
const char16_t g_safeModePageKey[] = u"ConfigPageSafeMode";
// RavenShield.exe data @ 10917580 : g_safeModePageClassName
const char16_t g_safeModePageClassName[] = u"WConfigPageSafeMode";

// RavenShield.exe @ 1090cbc0 : WConfigPageSafeMode::WConfigPageSafeMode
// Construct the page, store its owner, then bind four cool buttons in order with native delegate values and flags.
WConfigPageSafeMode::WConfigPageSafeMode(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_safeModePageKey), 0x7e4, owner), Owner(owner),
      RunButton(this, 0x454, FDelegate(this, (TDelegate)&WConfigPageSafeMode::Run), 5),
      RendererButton(this, 0x456, FDelegate(this, (TDelegate)&WConfigPageSafeMode::OpenRendererPage), 5),
      SafeOptionsButton(this, 0x455, FDelegate(this, (TDelegate)&WConfigPageSafeMode::OpenSafeOptionsPage), 5),
      WebButton(this, 0x422, FDelegate(this, (TDelegate)&WConfigPageSafeMode::OpenWebPage), 5)
{
} // Native derived table 10917448 is selected after base construction and before Owner/member initialization.

// RavenShield.exe @ 109025c0 : WConfigPageSafeMode::Run
// Call the imported nonvirtual EndDialog method on the owner with argument one.
void WConfigPageSafeMode::Run()
{
  Owner->EndDialog(1);
}

// RavenShield.exe @ 1090cd00 : WConfigPageSafeMode::GetNextText
// Return the genuine native null next-button text pointer without inspecting page state.
const uint16_t *WConfigPageSafeMode::GetNextText()
{
  return nullptr;
}

// RavenShield.exe @ 1090cde0 : WConfigPageSafeMode::GetWindowClassName
// Format the package-qualified native page class name into the caller's unbounded UTF-16 buffer.
void WConfigPageSafeMode::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_safeModePageClassName));
}

// RavenShield.exe @ 109129c0 : UnwindSafeModePageBase
// Destroy the completed WWizardPage base from the constructor's saved parent EBP-20 object pointer.
__declspec(naked) void UnwindSafeModePageBase()
{
  __asm {
    mov ecx, [ebp-20h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 109129c9 : UnwindSafeModePageRunButton
// Destroy the completed first cool button at page +44.
__declspec(naked) void UnwindSafeModePageRunButton()
{
  __asm {
    mov ecx, [ebp-20h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe @ 109129d5 : UnwindSafeModePageRendererButton
// Destroy the completed second cool button at page +e0.
__declspec(naked) void UnwindSafeModePageRendererButton()
{
  __asm {
    mov ecx, [ebp-20h]
    add ecx, 0e0h
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe @ 109129e4 : UnwindSafeModePageSafeOptionsButton
// Destroy the completed third cool button at page +17c if later construction fails.
__declspec(naked) void UnwindSafeModePageSafeOptionsButton()
{
  __asm {
    mov ecx, [ebp-20h]
    add ecx, 17ch
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe data @ 10919f18 : g_safeModePageConstructionUnwind
const NativeCppUnwindEntry g_safeModePageConstructionUnwind[4] = {
    {-1, NativeAddress(NativeEntry_UnwindSafeModePageBase)},             // UnwindSafeModePageBase
    {0, NativeAddress(NativeEntry_UnwindSafeModePageRunButton)},         // UnwindSafeModePageRunButton
    {1, NativeAddress(NativeEntry_UnwindSafeModePageRendererButton)},    // UnwindSafeModePageRendererButton
    {2, NativeAddress(NativeEntry_UnwindSafeModePageSafeOptionsButton)}, // UnwindSafeModePageSafeOptionsButton
};

// RavenShield.exe data @ 10919f38 : g_safeModePageConstructionExceptionInfo
const NativeCppFunctionInfo g_safeModePageConstructionExceptionInfo = {
    0x19930520, 4, NativeAddress(g_safeModePageConstructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109129f3 : HandleSafeModePageConstructionException
// Dispatch four completed-base/control states without a local catch or delegate-temporary destructor.
__declspec(naked) void HandleSafeModePageConstructionException()
{
  __asm {
    mov eax, offset g_safeModePageConstructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090cd40 : WConfigPageSafeMode::~WConfigPageSafeMode
// MaybeDestroy the page, then release controls and base automatically, including when window teardown throws.
WConfigPageSafeMode::~WConfigPageSafeMode() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_safeModePageVtable;
  WWindow::MaybeDestroy();
} // Native table 10917448; cleanup order is Web, Safe Options, Renderer, Run, then WWizardPage.

// RavenShield.exe @ 1090cd10 : WConfigPageSafeMode::ScalarDeletingDestructor
// Destroy the page, free storage only for flag bit zero, and return the original pointer even after freeing it.
WConfigPageSafeMode *WConfigPageSafeMode::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageSafeMode::~WConfigPageSafeMode();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 10912a00 : UnwindSafeModePageDestructionBase
// Destroy the completed base through the destructor's saved parent EBP-10 object pointer.
__declspec(naked) void UnwindSafeModePageDestructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912a09 : UnwindSafeModePageDestructionRunButton
// Destroy the first cool button at page +44 during destructor unwinding.
__declspec(naked) void UnwindSafeModePageDestructionRunButton()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe @ 10912a15 : UnwindSafeModePageDestructionRendererButton
// Destroy the second cool button at page +e0 during destructor unwinding.
__declspec(naked) void UnwindSafeModePageDestructionRendererButton()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 0e0h
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe @ 10912a24 : UnwindSafeModePageDestructionSafeOptionsButton
// Destroy the third cool button at page +17c during destructor unwinding.
__declspec(naked) void UnwindSafeModePageDestructionSafeOptionsButton()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 17ch
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe @ 10912a33 : UnwindSafeModePageDestructionWebButton
// Destroy the fourth cool button at page +218 if MaybeDestroy throws.
__declspec(naked) void UnwindSafeModePageDestructionWebButton()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 218h
    jmp dword ptr [NativeImport_WCoolButtonDestroy]
  }
}

// RavenShield.exe data @ 10919f54 : g_safeModePageDestructionUnwind
const NativeCppUnwindEntry g_safeModePageDestructionUnwind[5] = {
    {-1, NativeAddress(NativeEntry_UnwindSafeModePageDestructionBase)},     // UnwindSafeModePageDestructionBase
    {0, NativeAddress(NativeEntry_UnwindSafeModePageDestructionRunButton)}, // UnwindSafeModePageDestructionRunButton
    {1, NativeAddress(
            NativeEntry_UnwindSafeModePageDestructionRendererButton)}, // UnwindSafeModePageDestructionRendererButton
    {2,
     NativeAddress(
         NativeEntry_UnwindSafeModePageDestructionSafeOptionsButton)}, // UnwindSafeModePageDestructionSafeOptionsButton
    {3, NativeAddress(NativeEntry_UnwindSafeModePageDestructionWebButton)}, // UnwindSafeModePageDestructionWebButton
};

// RavenShield.exe data @ 10919f7c : g_safeModePageDestructionExceptionInfo
const NativeCppFunctionInfo g_safeModePageDestructionExceptionInfo = {
    0x19930520, 5, NativeAddress(g_safeModePageDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912a42 : HandleSafeModePageDestructionException
// Dispatch five completed-control/base states independently of constructor-only cleanup.
__declspec(naked) void HandleSafeModePageDestructionException()
{
  __asm {
    mov eax, offset g_safeModePageDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class WConfigPageSafeOptions;
class WConfigPageRenderer;
extern int32_t GUnicodeOS;
extern const char16_t g_launcherStartupPackage[];
extern const char16_t g_configEmptyString[];
extern const uint16_t *__cdecl appBaseDir();
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *buffer, const uint16_t *text, int32_t size);
extern const uint16_t *__cdecl LocalizeGeneral(const uint16_t *key, const uint16_t *package, const uint16_t *language);
extern "C" uint32_t __stdcall ShellExecuteW(uint32_t window, const uint16_t *operation, const uint16_t *file,
                                            const uint16_t *parameters, const uint16_t *directory, int32_t show);
extern "C" uint32_t __stdcall ShellExecuteA(uint32_t window, const char *operation, const char *file,
                                            const char *parameters, const char *directory, int32_t show);

// RavenShield.exe data @ 10914b44 : g_safeModeOpenOperation
extern const char16_t g_safeModeOpenOperation[] = u"open";
// RavenShield.exe data @ 10914c20 : g_safeModeWebPageKey
const char16_t g_safeModeWebPageKey[] = u"WebPage";

// RavenShield.exe @ 109025e0 : WConfigPageSafeMode::OpenSafeOptionsPage
// Construct a nullable safe-options page, then advance the current owner outside the construction cleanup scope.
void WConfigPageSafeMode::OpenSafeOptionsPage()
{
  void *allocation = AllocateExecutableBytes(0x4e4);
  WWizardPage *page = nullptr;
  if (allocation != nullptr)
  {
    try
    {
      page = new (allocation) WConfigPageSafeOptions(Owner);
    }
    catch (...)
    {
      FreeExecutableAllocation(allocation);
      throw;
    }
  }
  using AdvancePage = void(__thiscall *)(WConfigWizard *, WWizardPage *);
  WConfigWizard *dispatchOwner = Owner;
  WConfigWizard *receiver = Owner;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchOwner);
  const auto advance = *reinterpret_cast<const AdvancePage *>(table + 0xf0);
  advance(receiver, page); // Null is forwarded too; failure here does not free the page.
} // Shared EBP-14 allocation cleanup 109128d0/109128db remains in wizard_page_support.cpp.

// RavenShield.exe @ 1090cb30 : WConfigPageSafeMode::OpenRendererPage
// Construct a nullable renderer page, then advance the current owner after transferring allocation ownership.
void WConfigPageSafeMode::OpenRendererPage()
{
  void *allocation = AllocateExecutableBytes(0x248);
  WWizardPage *page = nullptr;
  if (allocation != nullptr)
  {
    try
    {
      page = new (allocation) WConfigPageRenderer(Owner);
    }
    catch (...)
    {
      FreeExecutableAllocation(allocation);
      throw;
    }
  }
  using AdvancePage = void(__thiscall *)(WConfigWizard *, WWizardPage *);
  WConfigWizard *dispatchOwner = Owner;
  WConfigWizard *receiver = Owner;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchOwner);
  const auto advance = *reinterpret_cast<const AdvancePage *>(table + 0xf0);
  advance(receiver, page); // Owner is sampled again after construction, and no rollback is added around Advance.
} // Shared EBP-14 allocation cleanup 109128d0/109128db remains in wizard_page_support.cpp.

// RavenShield.exe @ 10902670 : WConfigPageSafeMode::OpenWebPage
// Launch the localized web page through the sampled A/W shell API, then close the owner regardless of shell result.
void WConfigPageSafeMode::OpenWebPage()
{
  const auto &getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const WWindow *)>(NativeAddress(NativeImport_HWND));
  if (GUnicodeOS != 0)
  {
    const uint16_t *directory = appBaseDir();
    const uint16_t *file = LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeModeWebPageKey),
                                           reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(this));
    ShellExecuteW(window, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), file,
                  reinterpret_cast<const uint16_t *>(g_configEmptyString), directory, 1);
  }
  else
  {
    char *directoryBuffer = nullptr;
    if (winGetSizeANSI(appBaseDir()) != 0)
    {
      const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(appBaseDir()));
      directoryBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    char *parametersBuffer = nullptr;
    if (winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_configEmptyString)) != 0)
    {
      const uint32_t size =
          static_cast<uint32_t>(winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_configEmptyString)));
      parametersBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    char *fileBuffer = nullptr;
    const uint16_t *fileForProbe =
        LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeModeWebPageKey),
                        reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
    if (winGetSizeANSI(fileForProbe) != 0)
    {
      const uint16_t *fileForSize =
          LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeModeWebPageKey),
                          reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
      const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(fileForSize));
      fileBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    char *operationBuffer = nullptr;
    if (winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation)) != 0)
    {
      const uint32_t size =
          static_cast<uint32_t>(winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation)));
      operationBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    // Native conversions run only after all four parent-frame allocations, resampling dynamic sources each time.
    const int32_t directorySize = winGetSizeANSI(appBaseDir());
    const uint16_t *directorySource = appBaseDir();
    char *directory = winToANSI(directoryBuffer, directorySource, directorySize);
    const int32_t parametersSize = winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_configEmptyString));
    char *parameters =
        winToANSI(parametersBuffer, reinterpret_cast<const uint16_t *>(g_configEmptyString), parametersSize);
    const uint16_t *fileForConversionSize =
        LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeModeWebPageKey),
                        reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
    const int32_t fileSize = winGetSizeANSI(fileForConversionSize);
    const uint16_t *fileSource = LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeModeWebPageKey),
                                                 reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
    char *file = winToANSI(fileBuffer, fileSource, fileSize);
    const int32_t operationSize = winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation));
    char *operation =
        winToANSI(operationBuffer, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), operationSize);
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(this));
    ShellExecuteA(window, operation, file, parameters, directory, 1);
  }
  Owner->EndDialog(0);
} // No native local exception guard, shell-result check or buffer cleanup helper; _alloca storage is frame-owned.
