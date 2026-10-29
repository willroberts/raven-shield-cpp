#include "native_symbols.hpp"
// Native page: Owner +40 and eight WButton controls at +44/+d8/+16c/+200/+294/+328/+3bc/+450.
#include "cpp_exception_metadata.hpp"
// Option names identify native resource IDs; policy meanings remain separately reviewed.
#include "container_support.hpp"
#include "allocation_support.hpp"
#include "window_delegate.hpp"
#include "system_directory_support.hpp"
#include <malloc.h>

class WConfigWizard;
class WWindow;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);

// RavenShield.exe data @ 10914998 : g_safeOptionsPageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_safeOptionsPageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageSafeOptions_ScalarDeletingDestructor), // +004
  // WConfigPageSafeOptions::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                 // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),            // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName), // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),            // +014 WWindow::DoDestroy
    NativeAddress(
        NativeEntry_WConfigPageSafeOptions_GetWindowClassName),     // +018 WConfigPageSafeOptions::GetWindowClassName
    NativeAddress(NativeEntry_WWindow_WndProc),                     // +01c WWindow::WndProc
    NativeAddress(NativeEntry_WDialog_CallDefaultProc),             // +020 WDialog::CallDefaultProc
    NativeAddress(NativeEntry_WWindow_InterceptControlCommand),     // +024 WWindow::InterceptControlCommand
    NativeAddress(NativeEntry_WWindow_GetText),                     // +028 WWindow::GetText
    NativeAddress(NativeEntry_WWindow_SetText),                     // +02c WWindow::SetText
    NativeAddress(NativeEntry_WWindow_GetLength),                   // +030 WWindow::GetLength
    NativeAddress(NativeEntry_WWindow_OnCopyData),                  // +034 WWindow::OnCopyData
    NativeAddress(NativeEntry_WWindow_OnSetFocus),                  // +038 WWindow::OnSetFocus
    NativeAddress(NativeEntry_WWindow_OnKillFocus),                 // +03c WWindow::OnKillFocus
    NativeAddress(NativeEntry_WWindow_OnSize),                      // +040 WWindow::OnSize
    NativeAddress(NativeEntry_WWindow_OnWindowPosChanging),         // +044 WWindow::OnWindowPosChanging
    NativeAddress(NativeEntry_WWindow_OnMove),                      // +048 WWindow::OnMove
    NativeAddress(NativeEntry_WWindow_OnCommand),                   // +04c WWindow::OnCommand
    NativeAddress(NativeEntry_WWindow_OnSysCommand),                // +050 WWindow::OnSysCommand
    NativeAddress(NativeEntry_WWindow_OnActivate),                  // +054 WWindow::OnActivate
    NativeAddress(NativeEntry_WWindow_OnChar),                      // +058 WWindow::OnChar
    NativeAddress(NativeEntry_WWindow_OnKeyDown),                   // +05c WWindow::OnKeyDown
    NativeAddress(NativeEntry_WWindow_OnCut),                       // +060 WWindow::OnCut
    NativeAddress(NativeEntry_WWindow_OnCopy),                      // +064 WWindow::OnCopy
    NativeAddress(NativeEntry_WWindow_OnPaste),                     // +068 WWindow::OnPaste
    NativeAddress(NativeEntry_WWindow_OnShowWindow),                // +06c WWindow::OnShowWindow
    NativeAddress(NativeEntry_WWindow_OnUndo),                      // +070 WWindow::OnUndo
    NativeAddress(NativeEntry_WWindow_OnEraseBkgnd),                // +074 WWindow::OnEraseBkgnd
    NativeAddress(NativeEntry_WWindow_OnVScroll),                   // +078 WWindow::OnVScroll
    NativeAddress(NativeEntry_WWindow_OnHScroll),                   // +07c WWindow::OnHScroll
    NativeAddress(NativeEntry_WWindow_OnKeyUp),                     // +080 WWindow::OnKeyUp
    NativeAddress(NativeEntry_WWindow_OnPaint),                     // +084 WWindow::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                    // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                  // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),               // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WConfigPageSafeOptions_OnInitDialog), // +094 WConfigPageSafeOptions::OnInitDialog
    NativeAddress(NativeEntry_WWindow_OnEnterIdle),                 // +098 WWindow::OnEnterIdle
    NativeAddress(NativeEntry_WWindow_OnMouseEnter),                // +09c WWindow::OnMouseEnter
    NativeAddress(NativeEntry_WWindow_OnMouseLeave),                // +0a0 WWindow::OnMouseLeave
    NativeAddress(NativeEntry_WWindow_OnMouseHover),                // +0a4 WWindow::OnMouseHover
    NativeAddress(NativeEntry_WWindow_OnTimer),                     // +0a8 WWindow::OnTimer
    NativeAddress(NativeEntry_WWindow_OnReleaseCapture),            // +0ac WWindow::OnReleaseCapture
    NativeAddress(NativeEntry_WWindow_OnMdiActivate),               // +0b0 WWindow::OnMdiActivate
    NativeAddress(NativeEntry_WWindow_OnMouseMove),                 // +0b4 WWindow::OnMouseMove
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDown),            // +0b8 WWindow::OnLeftButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonDoubleClick),     // +0bc WWindow::OnLeftButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnMiddleButtonDoubleClick),   // +0c0 WWindow::OnMiddleButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDoubleClick),    // +0c4 WWindow::OnRightButtonDoubleClick
    NativeAddress(NativeEntry_WWindow_OnRightButtonDown),           // +0c8 WWindow::OnRightButtonDown
    NativeAddress(NativeEntry_WWindow_OnLeftButtonUp),              // +0cc WWindow::OnLeftButtonUp
    NativeAddress(NativeEntry_WWindow_OnRightButtonUp),             // +0d0 WWindow::OnRightButtonUp
    NativeAddress(NativeEntry_WWindow_OnFinishSplitterDrag),        // +0d4 WWindow::OnFinishSplitterDrag
    NativeAddress(NativeEntry_WWindow_OnSetCursor),                 // +0d8 WWindow::OnSetCursor
    NativeAddress(NativeEntry_WWindow_OnClose),                     // +0dc WWindow::OnClose
    NativeAddress(NativeEntry_WWindow_OnDestroy),                   // +0e0 WWindow::OnDestroy
    NativeAddress(NativeEntry_WWindow_MyDrawEdge),                  // +0e4 WWindow::MyDrawEdge
    NativeAddress(NativeEntry_WDialog_DoModal),                     // +0e8 WDialog::DoModal
    NativeAddress(NativeEntry_WDialog_LocalizeText),                // +0ec WDialog::LocalizeText
    NativeAddress(NativeEntry_WWizardPage_OnCurrent),               // +0f0 WWizardPage::OnCurrent
    NativeAddress(NativeEntry_WConfigPageSafeOptions_GetNext),      // +0f4 WConfigPageSafeOptions::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),             // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WConfigPageSafeOptions_GetNextText),  // +0fc WConfigPageSafeOptions::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),           // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),           // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                 // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 10914aa8 : g_safeOptionsPageKey
const char16_t g_safeOptionsPageKey[] = u"ConfigPageSafeOptions";
// RavenShield.exe data @ 10915410 : g_safeOptionsClassName
const char16_t g_safeOptionsClassName[] = u"WConfigPageSafeOptions";

// RavenShield.exe @ 10901a30 : WConfigPageSafeOptions::WConfigPageSafeOptions
// Construct the base and eight controls in native order, each with a null-target/null-method delegate and procedure.
WConfigPageSafeOptions::WConfigPageSafeOptions(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_safeOptionsPageKey), 0x7e5, owner), Owner(owner),
      Option454(this, 0x454, FDelegate(nullptr, nullptr), nullptr),
      Option455(this, 0x455, FDelegate(nullptr, nullptr), nullptr),
      Option456(this, 0x456, FDelegate(nullptr, nullptr), nullptr),
      Option458(this, 0x458, FDelegate(nullptr, nullptr), nullptr),
      Option457(this, 0x457, FDelegate(nullptr, nullptr), nullptr),
      Option459(this, 0x459, FDelegate(nullptr, nullptr), nullptr),
      Option45a(this, 0x45a, FDelegate(nullptr, nullptr), nullptr),
      Option45b(this, 0x45b, FDelegate(nullptr, nullptr), nullptr)
{
} // Native primary table 10914998; caller allocation extent 4e4h. Constructor cleanup covers base and seven controls.

// RavenShield.exe @ 109044c0 : WConfigPageSafeOptions::GetWindowClassName
// Format the native package-qualified safe-options class name into the caller's unbounded UTF-16 buffer.
void WConfigPageSafeOptions::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_safeOptionsClassName));
}

// RavenShield.exe @ 10912100 : UnwindSafeOptionsConstructionBase
// Destroy the completed Base through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionBase()
{
  __asm {
    mov ecx, [ebp-30h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912109 : UnwindSafeOptionsConstructionOption454
// Destroy the completed Option454 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption454()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912115 : UnwindSafeOptionsConstructionOption455
// Destroy the completed Option455 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption455()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 0d8h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912124 : UnwindSafeOptionsConstructionOption456
// Destroy the completed Option456 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption456()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 16ch
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912133 : UnwindSafeOptionsConstructionOption458
// Destroy the completed Option458 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption458()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 200h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912142 : UnwindSafeOptionsConstructionOption457
// Destroy the completed Option457 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption457()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 294h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912151 : UnwindSafeOptionsConstructionOption459
// Destroy the completed Option459 through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption459()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 328h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912160 : UnwindSafeOptionsConstructionOption45a
// Destroy the completed Option45a through the constructor's saved parent EBP-30 receiver.
__declspec(naked) void UnwindSafeOptionsConstructionOption45a()
{
  __asm {
    mov ecx, [ebp-30h]
    add ecx, 3bch
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe data @ 10918688 : g_safeOptionsConstructionUnwind
const NativeCppUnwindEntry g_safeOptionsConstructionUnwind[8] = {
    {-1, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionBase)},     // UnwindSafeOptionsConstructionBase
    {0, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption454)}, // UnwindSafeOptionsConstructionOption454
    {1, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption455)}, // UnwindSafeOptionsConstructionOption455
    {2, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption456)}, // UnwindSafeOptionsConstructionOption456
    {3, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption458)}, // UnwindSafeOptionsConstructionOption458
    {4, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption457)}, // UnwindSafeOptionsConstructionOption457
    {5, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption459)}, // UnwindSafeOptionsConstructionOption459
    {6, NativeAddress(NativeEntry_UnwindSafeOptionsConstructionOption45a)}, // UnwindSafeOptionsConstructionOption45a
};

// RavenShield.exe data @ 109186c8 : g_safeOptionsConstructionExceptionInfo
const NativeCppFunctionInfo g_safeOptionsConstructionExceptionInfo = {
    0x19930520, 8, NativeAddress(g_safeOptionsConstructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 1091216f : HandleSafeOptionsConstructionException
// Dispatch eight completed-base/control states without cleaning an unfinished eighth control or the outer allocation.
__declspec(naked) void HandleSafeOptionsConstructionException()
{
  __asm {
    mov eax, offset g_safeOptionsConstructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10904540 : WConfigPageSafeOptions::~WConfigPageSafeOptions
// Tear down the window before automatically destroying all eight controls in reverse order and then the base.
WConfigPageSafeOptions::~WConfigPageSafeOptions() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_safeOptionsPageVtable;
  WWindow::MaybeDestroy();
} // Native table 10914998; the completed-object map includes the eighth control unlike construction cleanup.

// RavenShield.exe @ 10904510 : WConfigPageSafeOptions::ScalarDeletingDestructor
// Destroy the page, conditionally free for flag bit zero, and return the original receiver.
WConfigPageSafeOptions *WConfigPageSafeOptions::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageSafeOptions::~WConfigPageSafeOptions();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 109122a0 : UnwindSafeOptionsDestructionBase
// Destroy the completed Base through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 109122a9 : UnwindSafeOptionsDestructionOption454
// Destroy the completed Option454 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption454()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 109122b5 : UnwindSafeOptionsDestructionOption455
// Destroy the completed Option455 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption455()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 0d8h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 109122c4 : UnwindSafeOptionsDestructionOption456
// Destroy the completed Option456 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption456()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 16ch
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 109122d3 : UnwindSafeOptionsDestructionOption458
// Destroy the completed Option458 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption458()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 200h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 109122e2 : UnwindSafeOptionsDestructionOption457
// Destroy the completed Option457 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption457()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 294h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 109122f1 : UnwindSafeOptionsDestructionOption459
// Destroy the completed Option459 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption459()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 328h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912300 : UnwindSafeOptionsDestructionOption45a
// Destroy the completed Option45a through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption45a()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 3bch
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 1091230f : UnwindSafeOptionsDestructionOption45b
// Destroy the completed Option45b through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindSafeOptionsDestructionOption45b()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 450h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe data @ 10918cf0 : g_safeOptionsDestructionUnwind
const NativeCppUnwindEntry g_safeOptionsDestructionUnwind[9] = {
    {-1, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionBase)},     // UnwindSafeOptionsDestructionBase
    {0, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption454)}, // UnwindSafeOptionsDestructionOption454
    {1, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption455)}, // UnwindSafeOptionsDestructionOption455
    {2, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption456)}, // UnwindSafeOptionsDestructionOption456
    {3, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption458)}, // UnwindSafeOptionsDestructionOption458
    {4, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption457)}, // UnwindSafeOptionsDestructionOption457
    {5, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption459)}, // UnwindSafeOptionsDestructionOption459
    {6, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption45a)}, // UnwindSafeOptionsDestructionOption45a
    {7, NativeAddress(NativeEntry_UnwindSafeOptionsDestructionOption45b)}, // UnwindSafeOptionsDestructionOption45b
};

// RavenShield.exe data @ 10918d38 : g_safeOptionsDestructionExceptionInfo
const NativeCppFunctionInfo g_safeOptionsDestructionExceptionInfo = {
    0x19930520, 9, NativeAddress(g_safeOptionsDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 1091231e : HandleSafeOptionsDestructionException
// Dispatch nine completed-base/control states without retrying a throwing control destructor.
__declspec(naked) void HandleSafeOptionsDestructionException()
{
  __asm {
    mov eax, offset g_safeOptionsDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FFileManager;
extern FFileManager *GFileManager;
extern int32_t GUnicodeOS;
extern const char16_t g_launcherStartupPackage[];
extern const char16_t g_safeModeOpenOperation[];
extern const char16_t g_configIniExtension[];
extern const uint16_t *__cdecl appBaseDir();
extern const uint16_t *__cdecl appPackage();
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *buffer, const uint16_t *text, int32_t size);
extern const uint16_t *__cdecl LocalizeGeneral(const uint16_t *key, const uint16_t *package, const uint16_t *language);
extern "C" int32_t __stdcall SendMessageW(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SendMessageA(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" uint32_t __stdcall ShellExecuteW(uint32_t window, const uint16_t *operation, const uint16_t *file,
                                            const uint16_t *parameters, const uint16_t *directory, int32_t show);
extern "C" uint32_t __stdcall ShellExecuteA(uint32_t window, const char *operation, const char *file,
                                            const char *parameters, const char *directory, int32_t show);

// RavenShield.exe data @ 10914b3c : g_safeOptionsRunKey
extern const char16_t g_safeOptionsRunKey[] = u"Run";

// RavenShield.exe data @ 10914b5c : g_safeOptionsNoJoystickSwitch
const char16_t g_safeOptionsNoJoystickSwitch[] = u" -nojoy";

// RavenShield.exe data @ 10914b6c : g_safeOptionsNoCpuExtensionsSwitches
const char16_t g_safeOptionsNoCpuExtensionsSwitches[] = u" -nommx -nokni -nok6";

// RavenShield.exe data @ 10914b98 : g_safeOptionsDefaultResolutionSwitch
const char16_t g_safeOptionsDefaultResolutionSwitch[] = u" -defaultres";

// RavenShield.exe data @ 10914bb4 : g_safeOptionsNoHardwareDirectDrawSwitches
const char16_t g_safeOptionsNoHardwareDirectDrawSwitches[] = u" -nohard -noddraw";

// RavenShield.exe data @ 10914bd8 : g_safeOptionsNoHardwareSwitch
const char16_t g_safeOptionsNoHardwareSwitch[] = u" -nohard";

// RavenShield.exe data @ 10914bec : g_safeOptionsNo3DSoundSwitch
const char16_t g_safeOptionsNo3DSoundSwitch[] = u" -no3dsound";

// RavenShield.exe data @ 10914c04 : g_safeOptionsNoSoundSwitch
const char16_t g_safeOptionsNoSoundSwitch[] = u" -nosound";

// RavenShield.exe @ 10901c30 : WConfigPageSafeOptions::OnInitDialog
// Initialize the base, then check all controls except Option459 with a fresh A/W sample for every message.
void WConfigPageSafeOptions::OnInitDialog()
{
  WDialog::OnInitDialog();
  const auto &getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const WWindow *)>(NativeAddress(NativeImport_HWND));
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option454));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option454));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option456));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option456));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option458));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option458));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option457));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option457));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option459));
    SendMessageW(window, 0xf1, 0, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option459));
    SendMessageA(window, 0xf1, 0, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45a));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45a));
    SendMessageA(window, 0xf1, 1, 0);
  }
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45b));
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45b));
    SendMessageA(window, 0xf1, 1, 0);
  }
}

// RavenShield.exe @ 10901ee0 : WConfigPageSafeOptions::GetNextText
// Return the localized Run text for this page's next button.
const uint16_t *WConfigPageSafeOptions::GetNextText()
{
  return LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_safeOptionsRunKey),
                         reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
}

// RavenShield.exe @ 10901f00 : WConfigPageSafeOptions::GetNext
// Build native launch switches, optionally delete the package INI, relaunch the module and end the wizard.
WWizardPage *WConfigPageSafeOptions::GetNext()
{
  FString commandLine;
  const auto &getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const WWindow *)>(NativeAddress(NativeImport_HWND));
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option454));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option454));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNoSoundSwitch);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNo3DSoundSwitch);
  }
  // Native re-reads Option455 for each of the following switches; other checked controls are not substituted.
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNoHardwareSwitch);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNoHardwareDirectDrawSwitches);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option455));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsDefaultResolutionSwitch);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45a));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45a));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNoCpuExtensionsSwitches);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45b));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option45b));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1) commandLine += reinterpret_cast<const uint16_t *>(g_safeOptionsNoJoystickSwitch);
  }
  {
    int32_t checked;
    if (GUnicodeOS != 0)
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option459));
      checked = SendMessageW(window, 0xf0, 0, 0);
    }
    else
    {
      const uint32_t window = getWindow(reinterpret_cast<const WWindow *>(&Option459));
      checked = SendMessageA(window, 0xf0, 0, 0);
    }
    if (checked == 1)
    {
      FString packageName(appPackage());
      FString iniName = packageName + reinterpret_cast<const uint16_t *>(g_configIniExtension);
      const uint16_t *filename = *iniName;
      using FileDelete = int32_t(__thiscall *)(FFileManager *, const uint16_t *, int32_t, int32_t);
      FFileManager *receiver = GFileManager;
      FFileManager *dispatchManager = GFileManager;
      const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchManager);
      const auto remove = *reinterpret_cast<const FileDelete *>(table + 0x10);
      remove(receiver, filename, 0, 0);
    }
  }
  if (GUnicodeOS != 0)
  {
    const uint16_t *directory = appBaseDir();
    const uint16_t *parameters = *commandLine;
    ShellExecuteW(0, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), g_moduleFilename, parameters,
                  directory, 1);
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
    if (winGetSizeANSI(*commandLine) != 0)
    {
      const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(*commandLine));
      parametersBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    char *fileBuffer = nullptr;
    if (winGetSizeANSI(g_moduleFilename) != 0)
    {
      const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(g_moduleFilename));
      fileBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    char *operationBuffer = nullptr;
    if (winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation)) != 0)
    {
      const uint32_t size =
          static_cast<uint32_t>(winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation)));
      operationBuffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
    }
    const int32_t directorySize = winGetSizeANSI(appBaseDir());
    const uint16_t *directorySource = appBaseDir();
    char *directory = winToANSI(directoryBuffer, directorySource, directorySize);
    const int32_t parametersSize = winGetSizeANSI(*commandLine);
    const uint16_t *parametersSource = *commandLine;
    char *parameters = winToANSI(parametersBuffer, parametersSource, parametersSize);
    const int32_t fileSize = winGetSizeANSI(g_moduleFilename);
    char *file = winToANSI(fileBuffer, g_moduleFilename, fileSize);
    const int32_t operationSize = winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation));
    char *operation =
        winToANSI(operationBuffer, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), operationSize);
    ShellExecuteA(0, operation, file, parameters, directory, 1);
  }
  Owner->EndDialog(0); // Native ignores both file deletion and shell results, keeping commandLine alive here.
  return nullptr;
} // Normal/unwind cleanup destroys commandLine; nested package/INI strings have already been released.

// RavenShield.exe @ 10912180 : UnwindSafeOptionsNextCommandLine
// Destroy the completed CommandLine string at parent EBP-18 during launch exception cleanup.
__declspec(naked) void UnwindSafeOptionsNextCommandLine()
{
  __asm {
    lea ecx, [ebp-18h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912189 : UnwindSafeOptionsNextPackageName
// Destroy the completed PackageName string at parent EBP-24 during launch exception cleanup.
__declspec(naked) void UnwindSafeOptionsNextPackageName()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912192 : UnwindSafeOptionsNextIniName
// Destroy the completed IniName string at parent EBP-30 during launch exception cleanup.
__declspec(naked) void UnwindSafeOptionsNextIniName()
{
  __asm {
    lea ecx, [ebp-30h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 109186e4 : g_safeOptionsNextUnwind
const NativeCppUnwindEntry g_safeOptionsNextUnwind[3] = {
    {-1, NativeAddress(NativeEntry_UnwindSafeOptionsNextCommandLine)}, // UnwindSafeOptionsNextCommandLine
    {0, NativeAddress(NativeEntry_UnwindSafeOptionsNextPackageName)},  // UnwindSafeOptionsNextPackageName
    {1, NativeAddress(NativeEntry_UnwindSafeOptionsNextIniName)},      // UnwindSafeOptionsNextIniName
};

// RavenShield.exe data @ 109186fc : g_safeOptionsNextExceptionInfo
const NativeCppFunctionInfo g_safeOptionsNextExceptionInfo = {
    0x19930520, 3, NativeAddress(g_safeOptionsNextUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 1091219b : HandleSafeOptionsNextException
// Dispatch command-line and nested package/INI string cleanup without rolling back deletion or launch effects.
__declspec(naked) void HandleSafeOptionsNextException()
{
  __asm {
    mov eax, offset g_safeOptionsNextExceptionInfo
    jmp DispatchExecutableCppException
  }
}
