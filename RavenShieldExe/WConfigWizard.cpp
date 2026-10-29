#include "native_symbols.hpp"
// Native members: WLabel +2fc, FWindowsBitmap +33c, zeroed word +34c and FString +350.
#include "cpp_exception_metadata.hpp"
// LogoStatic/LogoBitmap/Cancel/Title names follow the corroborating UE2 WConfigWizard declaration.
#include "allocation_support.hpp"
#include "system_directory_support.hpp"
#include "launch_runtime.hpp"

class WConfigWizard;
extern int32_t GUnicodeOS;
extern uint32_t g_startupDialogInstance;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" uint32_t __stdcall LoadIconW(uint32_t instance, const uint16_t *resource);
extern "C" uint32_t __stdcall LoadIconA(uint32_t instance, const char *resource);
extern "C" int32_t __stdcall SendMessageW(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SendMessageA(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SetForegroundWindow(uint32_t window);
using WizardWindowHandle = uint32_t(__thiscall *)(const void *);

// RavenShield.exe data @ 10914808 : g_configWizardVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_configWizardVtable[66] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused),                  // +000 FCommandTarget::Unused
    NativeAddress(NativeEntry_WConfigWizard_ScalarDeletingDestructor), // +004 WConfigWizard::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                           // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                      // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),           // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                      // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigWizard_GetWindowClassName),       // +018 WConfigWizard::GetWindowClassName
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
    NativeAddress(NativeEntry_WConfigWizard_OnInitDialog),             // +094 WConfigWizard::OnInitDialog
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
    NativeAddress(NativeEntry_WWizardDialog_OnClose),                  // +0dc WWizardDialog::OnClose
    NativeAddress(NativeEntry_WWizardDialog_OnDestroy),                // +0e0 WWizardDialog::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                     // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WDialog_DoModal),                        // +0e8 WDialog::DoModal
    NativeAddress(NativeEntry_WDialog_LocalizeText),                   // +0ec WDialog::LocalizeText
    NativeAddress(NativeEntry_WWizardDialog_Advance),                  // +0f0 WWizardDialog::Advance
    NativeAddress(NativeEntry_WWizardDialog_RefreshPage),              // +0f4 WWizardDialog::RefreshPage
    NativeAddress(NativeEntry_WWizardDialog_OnBack),                   // +0f8 WWizardDialog::OnBack
    NativeAddress(NativeEntry_WWizardDialog_OnNext),                   // +0fc WWizardDialog::OnNext
    NativeAddress(NativeEntry_WWizardDialog_OnFinish),                 // +100 WWizardDialog::OnFinish
    NativeAddress(NativeEntry_WWizardDialog_OnCancel),                 // +104 WWizardDialog::OnCancel
};

// RavenShield.exe data @ 109153f4 : g_configWizardClassName
const char16_t g_configWizardClassName[] = u"WConfigWizard";

// RavenShield.exe @ 10901710 : WConfigWizard::WConfigWizard
// Construct the base and owned members, clear Cancel, then initialize system directories with full unwind cleanup.
WConfigWizard::WConfigWizard() : WWizardDialog(), LogoStatic(this, 0x400, nullptr), LogoBitmap(0), Cancel(0), Title()
{
  InitializeSystemDirectories();
} // Native derived vtable 10914808 is selected after base construction and before member construction.

// RavenShield.exe @ 10901680 : WConfigWizard::~WConfigWizard
// Select the derived table and MaybeDestroy the window; automatic members/base also unwind if that call throws.
WConfigWizard::~WConfigWizard() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_configWizardVtable;
  WWindow::MaybeDestroy();
} // Native table 10914808; cleanup order is Title, LogoBitmap, LogoStatic, then WWizardDialog.

// RavenShield.exe @ 10904470 : WConfigWizard::GetWindowClassName
// Format the package-qualified native class name into the caller's unbounded UTF-16 buffer.
void WConfigWizard::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_configWizardClassName));
}

// RavenShield.exe @ 10904490 : WConfigWizard::ScalarDeletingDestructor
// Destroy the dialog, conditionally free its storage for flag bit zero, and return its original address.
WConfigWizard *WConfigWizard::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigWizard::~WConfigWizard();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 109120b0 : UnwindConfigWizardBase
// Destroy the completed WWizardDialog base at the saved parent object pointer.
__declspec(naked) void UnwindConfigWizardBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardDialogDestroy]
  }
}

// RavenShield.exe @ 109120b9 : UnwindConfigWizardLabel
// Destroy the completed label at parent object +2fc.
__declspec(naked) void UnwindConfigWizardLabel()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 2fch
    jmp dword ptr [NativeImport_WLabelDestroy]
  }
}

// RavenShield.exe @ 109120c8 : UnwindConfigWizardBitmap
// Destroy the completed bitmap at parent object +33c.
__declspec(naked) void UnwindConfigWizardBitmap()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 33ch
    jmp dword ptr [NativeImport_FWindowsBitmapDestroy]
  }
}

// RavenShield.exe @ 109120d7 : UnwindConfigWizardTitle
// Destroy the completed title string at parent object +350.
__declspec(naked) void UnwindConfigWizardTitle()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 350h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091855c : g_configWizardLifetimeUnwind
const NativeCppUnwindEntry g_configWizardLifetimeUnwind[4] = {
    {-1, NativeAddress(NativeEntry_UnwindConfigWizardBase)},  // UnwindConfigWizardBase
    {0, NativeAddress(NativeEntry_UnwindConfigWizardLabel)},  // UnwindConfigWizardLabel
    {1, NativeAddress(NativeEntry_UnwindConfigWizardBitmap)}, // UnwindConfigWizardBitmap
    {2, NativeAddress(NativeEntry_UnwindConfigWizardTitle)},  // UnwindConfigWizardTitle
};

// RavenShield.exe data @ 1091857c : g_configWizardLifetimeExceptionInfo
const NativeCppFunctionInfo g_configWizardLifetimeExceptionInfo = {
    0x19930520, 4, NativeAddress(g_configWizardLifetimeUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109120e6 : HandleConfigWizardLifetimeException
// Dispatch the four shared constructor/destructor lifetime states without adding a local catch.
__declspec(naked) void HandleConfigWizardLifetimeException()
{
  __asm {
    mov eax, offset g_configWizardLifetimeExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10914928 : g_configWizardOnInitGuardName
const char16_t g_configWizardOnInitGuardName[] = u"WStartupWizard::OnInitDialog";
// RavenShield.exe data @ 10914964 : g_configWizardLogoPath
extern const char16_t g_configWizardLogoPath[] = u"..\\Help\\Logo.bmp";

// RavenShield.exe @ 109017c0 : WConfigWizard::OnInitDialog
// Initialize the base, set icon/logo/title, then foreground the dialog while preserving independent A/W samples.
void WConfigWizard::OnInitDialog()
{
  try
  {
    WWizardDialog::OnInitDialog();
    if (GUnicodeOS != 0)
    {
      uint32_t icon;
      if (GUnicodeOS != 0)
        icon = LoadIconW(g_startupDialogInstance, reinterpret_cast<const uint16_t *>(0x80u));
      else
        icon = LoadIconA(g_startupDialogInstance, reinterpret_cast<const char *>(0x80u));
      const auto getWindow = *reinterpret_cast<const WizardWindowHandle *>(NativeAddress(NativeImport_HWND));
      const uint32_t window = getWindow(this);
      SendMessageW(window, 0x80, 1, static_cast<int32_t>(icon));
    }
    else
    {
      uint32_t icon;
      if (GUnicodeOS != 0)
        icon = LoadIconW(g_startupDialogInstance, reinterpret_cast<const uint16_t *>(0x80u));
      else
        icon = LoadIconA(g_startupDialogInstance, reinterpret_cast<const char *>(0x80u));
      const auto getWindow = *reinterpret_cast<const WizardWindowHandle *>(NativeAddress(NativeImport_HWND));
      const uint32_t window = getWindow(this);
      SendMessageA(window, 0x80, 1, static_cast<int32_t>(icon));
    }
    LogoBitmap.LoadFile(reinterpret_cast<const uint16_t *>(g_configWizardLogoPath));
    if (GUnicodeOS != 0)
    {
      const uint32_t bitmap = LogoBitmap.GetBitmapHandle();
      const auto getWindow = *reinterpret_cast<const WizardWindowHandle *>(NativeAddress(NativeImport_HWND));
      const uint32_t label = getWindow(&LogoStatic);
      SendMessageW(label, 0x172, 0, static_cast<int32_t>(bitmap));
    }
    else
    {
      const uint32_t bitmap = LogoBitmap.GetBitmapHandle();
      const auto getWindow = *reinterpret_cast<const WizardWindowHandle *>(NativeAddress(NativeImport_HWND));
      const uint32_t label = getWindow(&LogoStatic);
      SendMessageA(label, 0x172, 0, static_cast<int32_t>(bitmap));
    }
    const uint16_t *title = *Title;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
    using SetWindowText = void(__thiscall *)(WConfigWizard *, const uint16_t *);
    const auto setText = *reinterpret_cast<const SetWindowText *>(table + 0x2c);
    setText(this, title);
    const uint32_t window = *reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(this) + 4);
    SetForegroundWindow(window);
  }
  // RavenShield.exe @ 1090197e : RethrowConfigWizardOnInitPointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10901992 : UnwindConfigWizardOnInitFailure
  // Append the native WStartupWizard guard text and rethrow without destroying the wizard's owned members.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configWizardOnInitGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918628 : g_configWizardOnInitUnwind
const NativeCppUnwindEntry g_configWizardOnInitUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918638 : g_configWizardOnInitCatches
const NativeCppCatchHandler g_configWizardOnInitCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x1090197e}, // RethrowConfigWizardOnInitPointer
    {0, 0, 0, 0x10901992},                                               // UnwindConfigWizardOnInitFailure
};

// RavenShield.exe data @ 10918658 : g_configWizardOnInitTryBlocks
const NativeCppTryBlock g_configWizardOnInitTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configWizardOnInitCatches)},
};

// RavenShield.exe data @ 1091866c : g_configWizardOnInitExceptionInfo
const NativeCppFunctionInfo g_configWizardOnInitExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configWizardOnInitUnwind), 1, NativeAddress(g_configWizardOnInitTryBlocks), 0, 0};

// RavenShield.exe @ 109120f0 : HandleConfigWizardOnInitException
// Dispatch the typed/catch-all initialization guard with no local cleanup actions.
__declspec(naked) void HandleConfigWizardOnInitException()
{
  __asm {
    mov eax, offset g_configWizardOnInitExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090c670 : WConfigWizard::InvokeOnNext
// Forward the renderer list's double-click delegate to the owner's virtual OnNext slot without adjusting ECX.
__declspec(naked) void WConfigWizard::InvokeOnNext()
{
  __asm {
    mov eax, [ecx]
    jmp dword ptr [eax+0fch]
  }
}
