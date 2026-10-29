#include "native_symbols.hpp"
// Native members: Owner +40, WListBox +44, WButtons +d0/+164, WLabel +1f8, state word +238 and array +23c.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include "allocation_support.hpp"
#include "window_delegate.hpp"
#include "launch_runtime.hpp"
#include "system_directory_support.hpp"
#include <new>
#include <malloc.h>

class WConfigPageRenderer;
class WLabel;
class WConfigWizard;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);

// RavenShield.exe data @ 10916970 : g_rendererPageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_rendererPageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageRenderer_ScalarDeletingDestructor), // +004 WConfigPageRenderer::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                       // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                  // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),       // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                  // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigPageRenderer_GetWindowClassName), // +018 WConfigPageRenderer::GetWindowClassName
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
    NativeAddress(NativeEntry_WConfigPageRenderer_OnPaint),            // +084 WConfigPageRenderer::OnPaint
    NativeAddress(NativeEntry_WWindow_OnCreate),                       // +088 WWindow::OnCreate
    NativeAddress(NativeEntry_WWindow_OnDrawItem),                     // +08c WWindow::OnDrawItem
    NativeAddress(NativeEntry_WWindow_OnMeasureItem),                  // +090 WWindow::OnMeasureItem
    NativeAddress(NativeEntry_WConfigPageRenderer_OnInitDialog),       // +094 WConfigPageRenderer::OnInitDialog
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
    NativeAddress(NativeEntry_WConfigPageRenderer_OnCurrent),          // +0f0 WConfigPageRenderer::OnCurrent
    NativeAddress(NativeEntry_WConfigPageRenderer_GetNext),            // +0f4 WConfigPageRenderer::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),                // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WWizardPage_GetNextText),                // +0fc WWizardPage::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),              // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),              // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                    // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                   // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 10916a80 : g_rendererPageKey
const char16_t g_rendererPageKey[] = u"ConfigPageRenderer";
// RavenShield.exe data @ 10916af4 : g_rendererPageClassName
const char16_t g_rendererPageClassName[] = u"WConfigPageRenderer";

// RavenShield.exe @ 1090b230 : WConfigPageRenderer::WConfigPageRenderer
// Construct controls in native order, bind both buttons to one callback, zero state and initialize registry records.
WConfigPageRenderer::WConfigPageRenderer(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_rendererPageKey), 0x7e1, owner), Owner(owner),
      DriverList(this, 0x44f, nullptr),
      Choice455(this, 0x455, FDelegate(this, (TDelegate)&WConfigPageRenderer::RefreshDrivers), nullptr),
      Choice456(this, 0x456, FDelegate(this, (TDelegate)&WConfigPageRenderer::RefreshDrivers), nullptr),
      InfoLabel(this, 0x450, nullptr), NativeState238(0), DriverRecords()
{
} // Native table 10916970 precedes member initialization; DriverRecords is TArray<FRegistryObjectInfo>.

// RavenShield.exe @ 1090b3e0 : WConfigPageRenderer::GetWindowClassName
// Format the package-qualified native renderer-page name into the caller's unbounded UTF-16 buffer.
void WConfigPageRenderer::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_rendererPageClassName));
}

// RavenShield.exe @ 10912730 : UnwindRendererPageConstructionBase
// Destroy the completed WWizardPage base from the constructor's saved parent EBP-18 object pointer.
__declspec(naked) void UnwindRendererPageConstructionBase()
{
  __asm {
    mov ecx, [ebp-18h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912739 : UnwindRendererPageConstructionList
// Destroy the completed list box at renderer page +44.
__declspec(naked) void UnwindRendererPageConstructionList()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WListBoxDestroy]
  }
}

// RavenShield.exe @ 10912745 : UnwindRendererPageConstructionChoice455
// Destroy the first completed button at renderer page +d0.
__declspec(naked) void UnwindRendererPageConstructionChoice455()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 0d0h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912754 : UnwindRendererPageConstructionChoice456
// Destroy the second completed button at renderer page +164.
__declspec(naked) void UnwindRendererPageConstructionChoice456()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 164h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912763 : UnwindRendererPageConstructionLabel
// Destroy the completed label at renderer page +1f8 if registry-array construction fails.
__declspec(naked) void UnwindRendererPageConstructionLabel()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 1f8h
    jmp dword ptr [NativeImport_WLabelDestroy]
  }
}

// RavenShield.exe data @ 10919bc4 : g_rendererPageConstructionUnwind
const NativeCppUnwindEntry g_rendererPageConstructionUnwind[5] = {
    {-1, NativeAddress(NativeEntry_UnwindRendererPageConstructionBase)},     // UnwindRendererPageConstructionBase
    {0, NativeAddress(NativeEntry_UnwindRendererPageConstructionList)},      // UnwindRendererPageConstructionList
    {1, NativeAddress(NativeEntry_UnwindRendererPageConstructionChoice455)}, // UnwindRendererPageConstructionChoice455
    {2, NativeAddress(NativeEntry_UnwindRendererPageConstructionChoice456)}, // UnwindRendererPageConstructionChoice456
    {3, NativeAddress(NativeEntry_UnwindRendererPageConstructionLabel)},     // UnwindRendererPageConstructionLabel
};

// RavenShield.exe data @ 10919bec : g_rendererPageConstructionExceptionInfo
const NativeCppFunctionInfo g_rendererPageConstructionExceptionInfo = {
    0x19930520, 5, NativeAddress(g_rendererPageConstructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912772 : HandleRendererPageConstructionException
// Dispatch five completed-base/control states without a local catch or premature registry-array cleanup.
__declspec(naked) void HandleRendererPageConstructionException()
{
  __asm {
    mov eax, offset g_rendererPageConstructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090c6b0 : WConfigPageRenderer::~WConfigPageRenderer
// Tear down the window before automatic reverse-order registry, control and base destruction.
WConfigPageRenderer::~WConfigPageRenderer() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_rendererPageVtable;
  WWindow::MaybeDestroy();
} // Native table 10916970; DriverRecords, InfoLabel, Choice456, Choice455, DriverList, then WWizardPage.

// RavenShield.exe @ 1090c680 : WConfigPageRenderer::ScalarDeletingDestructor
// Destroy the page, optionally free storage for flag bit zero, and return the original receiver.
WConfigPageRenderer *WConfigPageRenderer::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageRenderer::~WConfigPageRenderer();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 10912960 : UnwindRendererPageDestructionBase
// Destroy the base through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 10912969 : UnwindRendererPageDestructionList
// Destroy the list box at +44 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionList()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WListBoxDestroy]
  }
}

// RavenShield.exe @ 10912975 : UnwindRendererPageDestructionChoice455
// Destroy the first button at +d0 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionChoice455()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 0d0h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912984 : UnwindRendererPageDestructionChoice456
// Destroy the second button at +164 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionChoice456()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 164h
    jmp dword ptr [NativeImport_WButtonDestroy]
  }
}

// RavenShield.exe @ 10912993 : UnwindRendererPageDestructionLabel
// Destroy the label at +1f8 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionLabel()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 1f8h
    jmp dword ptr [NativeImport_WLabelDestroy]
  }
}

// RavenShield.exe @ 109129a2 : UnwindRendererPageDestructionRecords
// Destroy the registry array at +23c through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindRendererPageDestructionRecords()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 23ch
    jmp NativeEntry_TArray_FRegistryObjectInfo_DestroyTArray // Canonical TArray<FRegistryObjectInfo> destructor.
  }
}

// RavenShield.exe data @ 10919ea8 : g_rendererPageDestructionUnwind
const NativeCppUnwindEntry g_rendererPageDestructionUnwind[6] = {
    {-1, NativeAddress(NativeEntry_UnwindRendererPageDestructionBase)},     // UnwindRendererPageDestructionBase
    {0, NativeAddress(NativeEntry_UnwindRendererPageDestructionList)},      // UnwindRendererPageDestructionList
    {1, NativeAddress(NativeEntry_UnwindRendererPageDestructionChoice455)}, // UnwindRendererPageDestructionChoice455
    {2, NativeAddress(NativeEntry_UnwindRendererPageDestructionChoice456)}, // UnwindRendererPageDestructionChoice456
    {3, NativeAddress(NativeEntry_UnwindRendererPageDestructionLabel)},     // UnwindRendererPageDestructionLabel
    {4, NativeAddress(NativeEntry_UnwindRendererPageDestructionRecords)},   // UnwindRendererPageDestructionRecords
};

// RavenShield.exe data @ 10919ed8 : g_rendererPageDestructionExceptionInfo
const NativeCppFunctionInfo g_rendererPageDestructionExceptionInfo = {
    0x19930520, 6, NativeAddress(g_rendererPageDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109129b0 : HandleRendererPageDestructionException
// Dispatch six completed-member/base cleanup states without a local catch.
__declspec(naked) void HandleRendererPageDestructionException()
{
  __asm {
    mov eax, offset g_rendererPageDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern const char16_t g_configEmptyString[];
extern const char16_t g_fileManagerCurrentDirectoryName[];
extern const uint16_t *__cdecl Localize(const uint16_t *section, const uint16_t *key, const uint16_t *package,
                                        const uint16_t *language, int32_t optional, int32_t unknownFlag6);
extern void __cdecl appUnwindf(const uint16_t *format, ...);

// RavenShield.exe data @ 10916178 : g_rendererClassCaptionKey
const char16_t g_rendererClassCaptionKey[] = u"ClassCaption";
// RavenShield.exe data @ 109161a0 : g_rendererDescriptionsSection
const char16_t g_rendererDescriptionsSection[] = u"Descriptions";
// RavenShield.exe data @ 10914910 : g_launcherStartupPackage
extern const char16_t g_launcherStartupPackage[] = u"Startup";
// RavenShield.exe data @ 10916aa8 : g_rendererOnCurrentGuardName
const char16_t g_rendererOnCurrentGuardName[] = u"WFilerPageInstallProgress::OnCurrent";

// RavenShield.exe @ 10907c50 : WConfigPageRenderer::GetSelectedDriver
// Resolve the first localized caption match to a registry class path, constructing the caller's hidden result.
FString *WConfigPageRenderer::GetSelectedDriver(FString *result)
{
  if (DriverList.GetCurrent() >= 0)
  {
    const int32_t current = DriverList.GetCurrent(); // The native repeats this query before GetString.
    FString selectedCaption = DriverList.GetString(current);
    for (TArray<FRegistryObjectInfo>::TIterator record(DriverRecords); record; ++record)
    {
      FString classPath((*record).Object); // Native object path +0.
      FString packageName;
      FString className;
      FString unused; // Constructed and destroyed in the native despite having no subsequent reads.
      int32_t split;
      {
        FString separator(reinterpret_cast<const uint16_t *>(g_fileManagerCurrentDirectoryName));
        split = classPath.Split(separator, &packageName, &className, 0);
      }
      if (split != 0)
      {
        const uint16_t *package = *packageName;
        const uint16_t *section = *className;
        const uint16_t *caption =
            Localize(section, reinterpret_cast<const uint16_t *>(g_rendererClassCaptionKey), package, nullptr, 0, 0);
        if (selectedCaption == caption)
        {
          new (result) FString(classPath);
          return result; // Native marks result bit zero; no unwind state destroys this result on local cleanup failure.
        }
      }
    }
  }
  new (result) FString(reinterpret_cast<const uint16_t *>(g_configEmptyString));
  return result;
}

// RavenShield.exe @ 109080b0 : WConfigPageRenderer::OnSelectionChange
// Localize the selected class path's optional Startup description and dispatch label SetText virtually.
void WConfigPageRenderer::OnSelectionChange()
{
  alignas(4) uint8_t storage[12];
  FString *selected = GetSelectedDriver(reinterpret_cast<FString *>(storage));
  try
  {
    const uint16_t *text = Localize(reinterpret_cast<const uint16_t *>(g_rendererDescriptionsSection), **selected,
                                    reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr, 1, 0);
    const uint32_t table = *reinterpret_cast<const uint32_t *>(&InfoLabel);
    using SetLabelText = void(__thiscall *)(WLabel *, const uint16_t *);
    const auto setText = *reinterpret_cast<const SetLabelText *>(table + 0x2c);
    setText(&InfoLabel, text);
  }
  catch (...)
  {
    selected->~FString();
    throw;
  }
  selected->~FString(); // State is already -1, so a normal destructor failure does not destroy this string twice.
}

// RavenShield.exe @ 1090b360 : WConfigPageRenderer::OnCurrent
// Preserve the native empty activation body and its pointer/catch-all guard without adding page work.
void WConfigPageRenderer::OnCurrent()
{
  try
  {
  }
  // RavenShield.exe @ 1090b38e : RethrowRendererOnCurrentPointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090b3a2 : UnwindRendererOnCurrentFailure
  // Append the foreign native guard text and rethrow without adding member destruction.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_rendererOnCurrentGuardName));
    throw;
  }
}

// RavenShield.exe @ 109124c0 : UnwindRendererCaption
// Destroy the selected list caption at parent EBP-18 during exception cleanup.
__declspec(naked) void UnwindRendererCaption()
{
  __asm {
    lea ecx, [ebp-18h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109124c9 : UnwindRendererClassPath
// Destroy the registry class path at parent EBP-2c during exception cleanup.
__declspec(naked) void UnwindRendererClassPath()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109124d2 : UnwindRendererPackage
// Destroy the split package name at parent EBP-38 during exception cleanup.
__declspec(naked) void UnwindRendererPackage()
{
  __asm {
    lea ecx, [ebp-38h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109124db : UnwindRendererClass
// Destroy the split class name at parent EBP-50 during exception cleanup.
__declspec(naked) void UnwindRendererClass()
{
  __asm {
    lea ecx, [ebp-50h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109124e4 : UnwindRendererUnused
// Destroy the unused native string at parent EBP-44 during exception cleanup.
__declspec(naked) void UnwindRendererUnused()
{
  __asm {
    lea ecx, [ebp-44h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109124ed : UnwindRendererSeparator
// Destroy the temporary split separator at parent EBP-60 during exception cleanup.
__declspec(naked) void UnwindRendererSeparator()
{
  __asm {
    lea ecx, [ebp-60h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 10919554 : g_rendererSelectionUnwind
const NativeCppUnwindEntry g_rendererSelectionUnwind[6] = {
    {-1, NativeAddress(NativeEntry_UnwindRendererCaption)},  // UnwindRendererCaption
    {0, NativeAddress(NativeEntry_UnwindRendererClassPath)}, // UnwindRendererClassPath
    {1, NativeAddress(NativeEntry_UnwindRendererPackage)},   // UnwindRendererPackage
    {2, NativeAddress(NativeEntry_UnwindRendererClass)},     // UnwindRendererClass
    {3, NativeAddress(NativeEntry_UnwindRendererUnused)},    // UnwindRendererUnused
    {4, NativeAddress(NativeEntry_UnwindRendererSeparator)}, // UnwindRendererSeparator
};

// RavenShield.exe data @ 10919584 : g_rendererSelectionExceptionInfo
const NativeCppFunctionInfo g_rendererSelectionExceptionInfo = {
    0x19930520, 6, NativeAddress(g_rendererSelectionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109124f6 : HandleRendererSelectionException
// Dispatch six nested string states without a local catch or result cleanup.
__declspec(naked) void HandleRendererSelectionException()
{
  __asm {
    mov eax, offset g_rendererSelectionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10919c08 : g_rendererOnCurrentUnwind
const NativeCppUnwindEntry g_rendererOnCurrentUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919c18 : g_rendererOnCurrentCatches
const NativeCppCatchHandler g_rendererOnCurrentCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x1090b38e}, // RethrowRendererOnCurrentPointer
    {0, 0, 0, 0x1090b3a2},                                               // UnwindRendererOnCurrentFailure
};

// RavenShield.exe data @ 10919c38 : g_rendererOnCurrentTryBlocks
const NativeCppTryBlock g_rendererOnCurrentTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_rendererOnCurrentCatches)},
};

// RavenShield.exe data @ 10919c4c : g_rendererOnCurrentExceptionInfo
const NativeCppFunctionInfo g_rendererOnCurrentExceptionInfo = {
    0x19930520, 2, NativeAddress(g_rendererOnCurrentUnwind), 1, NativeAddress(g_rendererOnCurrentTryBlocks), 0, 0};

// RavenShield.exe @ 10912780 : HandleRendererOnCurrentException
// Dispatch the empty activation method's pointer/catch-all guard.
__declspec(naked) void HandleRendererOnCurrentException()
{
  __asm {
    mov eax, offset g_rendererOnCurrentExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FConfigCache;
class FFileManager;
class UClass;
class URenderDevice;
class UObject;
extern FConfigCache *GConfig;
extern FFileManager *GFileManager;
extern int32_t GUnicodeOS;
extern "C" int32_t __stdcall SendMessageW(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SendMessageA(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);

// RavenShield.exe data @ 10916914 : g_rendererSoftwareClass
extern const char16_t g_rendererSoftwareClass[] = u"SoftDrv.SoftwareRenderDevice";
// RavenShield.exe data @ 10916950 : g_rendererProbePathFormat
const char16_t g_rendererProbePathFormat[] = u"%s\\%s";
// RavenShield.exe data @ 1091695c : g_rendererDescriptionFlagsKey
extern const char16_t g_rendererDescriptionFlagsKey[] = u"DescFlags";

// RavenShield.exe @ 1090acf0 : WConfigPageRenderer::RefreshDrivers
// Rebuild available renderer captions, prefer later equal-ranked entries, then publish the selected description.
void WConfigPageRenderer::RefreshDrivers()
{
  const auto fileSize = [](const uint16_t *filename)
  {
    FFileManager *dispatchManager = GFileManager;
    FFileManager *receiver = GFileManager;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchManager);
    using QueryFileSize = int32_t(__thiscall *)(FFileManager *, const uint16_t *);
    return (*reinterpret_cast<const QueryFileSize *>(table + 0x0c))(receiver, filename);
  };
  DriverList.Empty();
  int32_t checked;
  const auto &getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const WWindow *)>(NativeAddress(NativeImport_HWND));
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(&Choice456);
    checked = SendMessageW(window, 0xf0, 0, 0);
  }
  else
  {
    const uint32_t window = getWindow(&Choice456);
    checked = SendMessageA(window, 0xf0, 0, 0);
  }
  const uint32_t showAll = checked == 1 ? 1u : 0u;
  int32_t bestPriority = 0;
  FString bestCaption;
  DriverRecords.Empty(0);
  UClass *renderDeviceType = URenderDevice::StaticClass();
  UClass *classType = UClass::StaticClass();
  UObject::GetRegistryObjects(DriverRecords, classType, renderDeviceType, 0);
  for (TArray<FRegistryObjectInfo>::TIterator record(DriverRecords); record; ++record)
  {
    FString classPath((*record).Object); // Native record +0.
    FString packageName;
    FString className;
    FString caption;
    int32_t split;
    {
      FString separator(reinterpret_cast<const uint16_t *>(g_fileManagerCurrentDirectoryName));
      split = classPath.Split(separator, &packageName, &className, 0);
    }
    if (split != 0)
    {
      uint32_t visible = showAll;
      int32_t priority = 0;
      int32_t descriptionFlags = 0;
      const uint16_t *section = *classPath;
      FConfigCache *dispatchConfig = GConfig;
      FConfigCache *receiver = GConfig;
      const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
      using QueryInteger =
          int32_t(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, int32_t *, const uint16_t *);
      (*reinterpret_cast<const QueryInteger *>(table + 4))(
          receiver, section, reinterpret_cast<const uint16_t *>(g_rendererDescriptionFlagsKey), &descriptionFlags,
          nullptr);
      // Native ignores the query result.
      // Native +30 is a probe filename. Keep the first path alive through the conditional second probe.
      bool detected = false;
      if ((*record).Autodetect != reinterpret_cast<const uint16_t *>(g_configEmptyString))
      {
        FString systemPath = FString::Printf(reinterpret_cast<const uint16_t *>(g_rendererProbePathFormat),
                                             g_systemDirectory, *(*record).Autodetect);
        const uint16_t *systemFile = *systemPath;
        if (fileSize(systemFile) >= 0)
        {
          detected = true;
        }
        else
        {
          FString windowsPath = FString::Printf(reinterpret_cast<const uint16_t *>(g_rendererProbePathFormat),
                                                g_windowsDirectory, *(*record).Autodetect);
          const uint16_t *windowsFile = *windowsPath;
          detected = fileSize(windowsFile) >= 0;
        }
      } // Path cleanup precedes ranking; both virtual receivers are acquired after formatting/dereferencing.
      if (detected)
      {
        priority = 3;
        visible = 3;
      }
      else if ((descriptionFlags & 1) != 0)
      {
        priority = 2;
        visible = 2;
      }
      else if (classPath == reinterpret_cast<const uint16_t *>(g_rendererSoftwareClass))
      {
        priority = 1;
        visible = 1;
      }
      if (visible != 0)
      {
        const uint16_t *package = *packageName;
        const uint16_t *classSection = *className;
        const uint16_t *localized = Localize(
            classSection, reinterpret_cast<const uint16_t *>(g_rendererClassCaptionKey), package, nullptr, 0, 0);
        FString &assigned = (caption = localized);
        DriverList.AddString(*assigned);
        if (priority >= bestPriority)
        {
          bestCaption = caption;
          bestPriority = priority;
        }
      }
    }
  }
  if (bestCaption != reinterpret_cast<const uint16_t *>(g_configEmptyString))
  {
    const uint16_t *text = *bestCaption;
    const int32_t index = DriverList.FindStringChecked(text);
    DriverList.SetCurrent(index, 1);
  }
  OnSelectionChange(); // Runs even for an empty list; bestCaption is still alive through this call.
}

// RavenShield.exe @ 10912680 : UnwindRendererRefreshBestCaption
// Destroy the best caption at parent EBP-18 during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshBestCaption()
{
  __asm {
    lea ecx, [ebp-18h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912689 : UnwindRendererRefreshClassPath
// Destroy the registry class path at parent EBP-34 during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshClassPath()
{
  __asm {
    lea ecx, [ebp-34h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912692 : UnwindRendererRefreshPackage
// Destroy the split package at parent EBP-40 during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshPackage()
{
  __asm {
    lea ecx, [ebp-40h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091269b : UnwindRendererRefreshClass
// Destroy the split class name at parent EBP-58 during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshClass()
{
  __asm {
    lea ecx, [ebp-58h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109126a4 : UnwindRendererRefreshCaption
// Destroy the localized caption at parent EBP-4c during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshCaption()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109126ad : UnwindRendererRefreshSeparator
// Destroy the temporary split separator at parent EBP-74 during refresh exception cleanup.
__declspec(naked) void UnwindRendererRefreshSeparator()
{
  __asm {
    lea ecx, [ebp-74h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109126b6 : UnwindRendererRefreshSystemProbe
// Clear the parent EBP-94 construction bit before conditionally destroying the path at EBP-84.
__declspec(naked) void UnwindRendererRefreshSystemProbe()
{
  __asm {
    mov eax, [ebp-94h]
    and eax, 1
    jz systemProbeDone
    and dword ptr [ebp-94h], 0fffffffeh
    lea ecx, [ebp-84h]
    jmp dword ptr [NativeImport_FStringDestroy]
  systemProbeDone:
    ret
  }
}

// RavenShield.exe @ 109126d9 : UnwindRendererRefreshWindowsProbe
// Clear the parent EBP-94 construction bit before conditionally destroying the path at EBP-90.
__declspec(naked) void UnwindRendererRefreshWindowsProbe()
{
  __asm {
    mov eax, [ebp-94h]
    and eax, 2
    jz windowsProbeDone
    and dword ptr [ebp-94h], 0fffffffdh
    lea ecx, [ebp-90h]
    jmp dword ptr [NativeImport_FStringDestroy]
  windowsProbeDone:
    ret
  }
}

// RavenShield.exe data @ 10919b44 : g_rendererRefreshUnwind
const NativeCppUnwindEntry g_rendererRefreshUnwind[8] = {
    {-1, NativeAddress(NativeEntry_UnwindRendererRefreshBestCaption)}, // UnwindRendererRefreshBestCaption
    {0, NativeAddress(NativeEntry_UnwindRendererRefreshClassPath)},    // UnwindRendererRefreshClassPath
    {1, NativeAddress(NativeEntry_UnwindRendererRefreshPackage)},      // UnwindRendererRefreshPackage
    {2, NativeAddress(NativeEntry_UnwindRendererRefreshClass)},        // UnwindRendererRefreshClass
    {3, NativeAddress(NativeEntry_UnwindRendererRefreshCaption)},      // UnwindRendererRefreshCaption
    {4, NativeAddress(NativeEntry_UnwindRendererRefreshSeparator)},    // UnwindRendererRefreshSeparator
    {4, NativeAddress(NativeEntry_UnwindRendererRefreshSystemProbe)},  // UnwindRendererRefreshSystemProbe
    {6, NativeAddress(NativeEntry_UnwindRendererRefreshWindowsProbe)}, // UnwindRendererRefreshWindowsProbe
};

// RavenShield.exe data @ 10919b84 : g_rendererRefreshExceptionInfo
const NativeCppFunctionInfo g_rendererRefreshExceptionInfo = {
    0x19930520, 8, NativeAddress(g_rendererRefreshUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109126fc : HandleRendererRefreshException
// Dispatch eight string states, including two conditional paths whose bits clear before destruction.
__declspec(naked) void HandleRendererRefreshException()
{
  __asm {
    mov eax, offset g_rendererRefreshExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern const uint16_t *__cdecl LocalizeGeneral(const uint16_t *key, const uint16_t *package, const uint16_t *language);

// RavenShield.exe data @ 10917380 : g_rendererDetectingKey
const char16_t g_rendererDetectingKey[] = u"Detecting";

// RavenShield.exe @ 1090c5a0 : WConfigPageRenderer::OnInitDialog
// Initialize the dialog, check the first choice, bind list callbacks and append the localized detecting caption.
void WConfigPageRenderer::OnInitDialog()
{
  WDialog::OnInitDialog();
  const auto getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const void *)>(NativeAddress(NativeImport_HWND));
  if (GUnicodeOS != 0)
  {
    const uint32_t window = getWindow(&Choice455);
    SendMessageW(window, 0xf1, 1, 0);
  }
  else
  {
    const uint32_t window = getWindow(&Choice455);
    SendMessageA(window, 0xf1, 1, 0);
  }
  DriverList.SelectionChangeDelegate = FDelegate(this, (TDelegate)&WConfigPageRenderer::OnSelectionChange);
  DriverList.DoubleClickDelegate = FDelegate(Owner, (TDelegate)&WConfigWizard::InvokeOnNext);
  const uint16_t *detecting = LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_rendererDetectingKey),
                                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
  DriverList.AddString(detecting); // No native refresh call, list clear, initial selection or local exception guard.
}

class WConfigPageDetail;
class WConfigPageDriver;

// RavenShield.exe data @ 10916b1c : g_rendererDirect3DClass
extern const char16_t g_rendererDirect3DClass[] = u"D3DDrv.D3DRenderDevice";
// RavenShield.exe data @ 10916b4c : g_rendererEngineSection
extern const char16_t g_rendererEngineSection[] = u"Engine.Engine";
// RavenShield.exe data @ 10916b68 : g_rendererRenderDeviceKey
extern const char16_t g_rendererRenderDeviceKey[] = u"RenderDevice";

// RavenShield.exe @ 1090b400 : WConfigPageRenderer::GetNext
// Requery the selected class for config publication and page choice, then construct a nullable next page.
WWizardPage *WConfigPageRenderer::GetNext()
{
  int32_t hasSelection;
  {
    alignas(4) uint8_t storage[12];
    FString *selection = GetSelectedDriver(reinterpret_cast<FString *>(storage));
    try
    {
      hasSelection = *selection != reinterpret_cast<const uint16_t *>(g_configEmptyString);
    }
    catch (...)
    {
      selection->~FString();
      throw;
    }
    selection->~FString();
  }
  if (hasSelection != 0)
  {
    alignas(4) uint8_t storage[12];
    FString *selection = GetSelectedDriver(reinterpret_cast<FString *>(storage));
    try
    {
      const uint16_t *value = **selection;
      FConfigCache *receiver = GConfig;
      FConfigCache *dispatchConfig = GConfig;
      const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
      using SetConfigString =
          void(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *, const uint16_t *);
      (*reinterpret_cast<const SetConfigString *>(table + 0x30))(
          receiver, reinterpret_cast<const uint16_t *>(g_rendererEngineSection),
          reinterpret_cast<const uint16_t *>(g_rendererRenderDeviceKey), value, nullptr);
    }
    catch (...)
    {
      selection->~FString();
      throw;
    }
    selection->~FString();
  }
  int32_t direct3D;
  {
    alignas(4) uint8_t storage[12];
    FString *selection = GetSelectedDriver(reinterpret_cast<FString *>(storage));
    try
    {
      direct3D = *selection == reinterpret_cast<const uint16_t *>(g_rendererDirect3DClass);
    }
    catch (...)
    {
      selection->~FString();
      throw;
    }
    selection->~FString();
  }
  if (direct3D != 0)
  {
    void *allocation = AllocateExecutableBytes(0x12c);
    if (allocation == nullptr) return nullptr;
    try
    {
      return new (allocation) WConfigPageDriver(Owner);
    }
    catch (...)
    {
      FreeExecutableAllocation(allocation);
      throw;
    }
  }
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
}

// RavenShield.exe @ 10912790 : UnwindRendererNextNonemptyTest
// Destroy the first selection result at parent EBP-1c during GetNext exception cleanup.
__declspec(naked) void UnwindRendererNextNonemptyTest()
{
  __asm {
    lea ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912799 : UnwindRendererNextConfigValue
// Destroy the config-value selection result at parent EBP-28 during GetNext exception cleanup.
__declspec(naked) void UnwindRendererNextConfigValue()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109127a2 : UnwindRendererNextDirect3DTest
// Destroy the page-choice selection result at parent EBP-38 during GetNext exception cleanup.
__declspec(naked) void UnwindRendererNextDirect3DTest()
{
  __asm {
    lea ecx, [ebp-38h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109127ab : UnwindRendererNextDriverAllocation
// Free the saved parent EBP-40 allocation if the page constructor throws after its own member cleanup.
__declspec(naked) void UnwindRendererNextDriverAllocation()
{
  __asm {
    mov eax, [ebp-40h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe @ 109127b6 : UnwindRendererNextDetailAllocation
// Free the saved parent EBP-48 allocation if the page constructor throws after its own member cleanup.
__declspec(naked) void UnwindRendererNextDetailAllocation()
{
  __asm {
    mov eax, [ebp-48h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 10919c68 : g_rendererNextUnwind
const NativeCppUnwindEntry g_rendererNextUnwind[5] = {
    {-1, NativeAddress(NativeEntry_UnwindRendererNextNonemptyTest)},     // UnwindRendererNextNonemptyTest
    {-1, NativeAddress(NativeEntry_UnwindRendererNextConfigValue)},      // UnwindRendererNextConfigValue
    {-1, NativeAddress(NativeEntry_UnwindRendererNextDirect3DTest)},     // UnwindRendererNextDirect3DTest
    {-1, NativeAddress(NativeEntry_UnwindRendererNextDriverAllocation)}, // UnwindRendererNextDriverAllocation
    {-1, NativeAddress(NativeEntry_UnwindRendererNextDetailAllocation)}, // UnwindRendererNextDetailAllocation
};

// RavenShield.exe data @ 10919c90 : g_rendererNextExceptionInfo
const NativeCppFunctionInfo g_rendererNextExceptionInfo = {0x19930520, 5, NativeAddress(g_rendererNextUnwind), 0, 0,
                                                           0,          0};

// RavenShield.exe @ 109127c1 : HandleRendererNextException
// Dispatch five independent string/allocation states without a native local catch or config rollback.
__declspec(naked) void HandleRendererNextException()
{
  __asm {
    mov eax, offset g_rendererNextExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern const char16_t g_safeModeOpenOperation[];
extern const uint16_t *__cdecl appBaseDir();
extern const uint16_t *__cdecl appCmdLine();
extern int32_t __cdecl ParseParam(const uint16_t *commandLine, const uint16_t *parameter);
extern int32_t __cdecl Parse(const uint16_t *stream, const uint16_t *match, uint16_t *value, int32_t maxLength);
extern uint16_t *__cdecl appStrcat(uint16_t *destination, const uint16_t *source);
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *buffer, const uint16_t *text, int32_t size);
extern "C" int32_t __stdcall UpdateWindow(uint32_t window);
extern "C" void __stdcall Sleep(uint32_t milliseconds);
extern "C" uint32_t __stdcall ShellExecuteW(uint32_t window, const uint16_t *operation, const uint16_t *file,
                                            const uint16_t *parameters, const uint16_t *directory, int32_t show);
extern "C" uint32_t __stdcall ShellExecuteA(uint32_t window, const char *operation, const char *file,
                                            const char *parameters, const char *directory, int32_t show);

// RavenShield.exe data @ 10917394 : g_rendererDetectionIniAppend
const char16_t g_rendererDetectionIniAppend[] = u" INI=";
// RavenShield.exe data @ 109173a0 : g_rendererDetectionIniKey
const char16_t g_rendererDetectionIniKey[] = u"INI=";
// RavenShield.exe data @ 109173b0 : g_rendererDetectionCommand
const char16_t g_rendererDetectionCommand[] = u"testrendev=D3DDrv.D3DRenderDevice log=Detected.log";
// RavenShield.exe data @ 10917418 : g_rendererDetectionFile
extern const char16_t g_rendererDetectionFile[] = u"Detected.ini";
// RavenShield.exe data @ 10917434 : g_rendererNoDetectSwitch
const char16_t g_rendererNoDetectSwitch[] = u"nodetect";

// RavenShield.exe @ 1090c760 : WConfigPageRenderer::OnPaint
// On a zero old paint counter, flush config, optionally run renderer detection and poll its marker, then refresh.
void WConfigPageRenderer::OnPaint()
{
  const auto fileSize = [](const uint16_t *filename)
  {
    FFileManager *dispatchManager = GFileManager;
    FFileManager *receiver = GFileManager;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchManager);
    using QuerySize = int32_t(__thiscall *)(FFileManager *, const uint16_t *);
    return (*reinterpret_cast<const QuerySize *>(table + 0x0c))(receiver, filename);
  };
  struct
  {
    uint16_t parameters[256];
    uint16_t ini[256];
  } buffers; // Native EBP-400/-200 adjacency and parent-frame lifetime, with no initialization before detection.
  const uint32_t previous = static_cast<uint32_t>(NativeState238);
  NativeState238 = static_cast<int32_t>(static_cast<uint32_t>(NativeState238) + 1u);
  if (previous != 0) return; // Increment precedes reentrant UpdateWindow; preserve wrapping rather than a bool latch.
  const auto getWindow =
      *reinterpret_cast<const uint32_t(__thiscall **)(const void *)>(NativeAddress(NativeImport_HWND));
  const uint32_t window = getWindow(this);
  UpdateWindow(window);
  FConfigCache *dispatchConfig = GConfig;
  FConfigCache *receiver = GConfig;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
  using FlushConfig = void(__thiscall *)(FConfigCache *, int32_t, const uint16_t *);
  (*reinterpret_cast<const FlushConfig *>(table + 0x34))(receiver, 1, nullptr);
  const uint16_t *commandLine = appCmdLine();
  if (ParseParam(commandLine, reinterpret_cast<const uint16_t *>(g_rendererNoDetectSwitch)) == 0)
  {
    FFileManager *dispatchManager = GFileManager;
    FFileManager *managerReceiver = GFileManager;
    const uint32_t managerTable = *reinterpret_cast<const uint32_t *>(dispatchManager);
    using DeleteFile = int32_t(__thiscall *)(FFileManager *, const uint16_t *, int32_t, int32_t);
    (*reinterpret_cast<const DeleteFile *>(managerTable + 0x10))(
        managerReceiver, reinterpret_cast<const uint16_t *>(g_rendererDetectionFile), 0, 0);
    for (uint32_t i = 0; i < 51; ++i) buffers.parameters[i] = g_rendererDetectionCommand[i];
    for (uint32_t i = 51; i < 256; ++i) buffers.parameters[i] = 0;
    buffers.ini[0] = static_cast<uint16_t>(g_configEmptyString[0]);
    for (uint32_t i = 1; i < 256; ++i) buffers.ini[i] = 0;
    const uint16_t *currentCommandLine = appCmdLine();
    if (Parse(currentCommandLine, reinterpret_cast<const uint16_t *>(g_rendererDetectionIniKey), buffers.ini, 256) != 0)
    {
      appStrcat(buffers.parameters, reinterpret_cast<const uint16_t *>(g_rendererDetectionIniAppend));
      appStrcat(buffers.parameters, buffers.ini);
    }
    if (GUnicodeOS != 0)
    {
      const uint16_t *directory = appBaseDir();
      ShellExecuteW(0, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), g_moduleFilename,
                    buffers.parameters, directory, 1);
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
      if (winGetSizeANSI(buffers.parameters) != 0)
      {
        const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(buffers.parameters));
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
      const int32_t parametersSize = winGetSizeANSI(buffers.parameters);
      char *parameters = winToANSI(parametersBuffer, buffers.parameters, parametersSize);
      const int32_t fileSize = winGetSizeANSI(g_moduleFilename);
      char *file = winToANSI(fileBuffer, g_moduleFilename, fileSize);
      const int32_t operationSize = winGetSizeANSI(reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation));
      char *operation =
          winToANSI(operationBuffer, reinterpret_cast<const uint16_t *>(g_safeModeOpenOperation), operationSize);
      ShellExecuteA(0, operation, file, parameters, directory, 1);
    }
    int32_t remaining = 30000;
    while (remaining > 0 && fileSize(reinterpret_cast<const uint16_t *>(g_rendererDetectionFile)) < 0)
    {
      Sleep(100);
      remaining -= 100;
    }
  }
  RefreshDrivers(); // Runs after timeout, detection success, shell failure, or the nodetect bypass.
} // No native base OnPaint call, local exception guard, process handle wait, message pump or counter rollback.
