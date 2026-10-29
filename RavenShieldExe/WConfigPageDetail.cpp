#include "native_symbols.hpp"
// Native page members: Owner +40, WEdit +44; allocation extent 90h.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include "allocation_support.hpp"
#include "window_delegate.hpp"
#include <new>

class WConfigWizard;
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);

// RavenShield.exe data @ 10916b88 : g_detailPageVtable
// Native x86 primary virtual-table words; slot comments identify canonical bodies without inferring class fields.
const uint32_t g_detailPageVtable[68] = {
    NativeAddress(NativeEntry_FCommandTarget_Unused), // +000 FCommandTarget::Unused
    NativeAddress(
        NativeEntry_WConfigPageDetail_ScalarDeletingDestructor),     // +004 WConfigPageDetail::ScalarDeletingDestructor
    NativeAddress(NativeEntry_WDialog_Show),                         // +008 WDialog::Show
    NativeAddress(NativeEntry_WWindow_Serialize),                    // +00c WWindow::Serialize
    NativeAddress(NativeEntry_GetLauncherWindowPackageName),         // +010 GetLauncherWindowPackageName
    NativeAddress(NativeEntry_WWindow_DoDestroy),                    // +014 WWindow::DoDestroy
    NativeAddress(NativeEntry_WConfigPageDetail_GetWindowClassName), // +018 WConfigPageDetail::GetWindowClassName
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
    NativeAddress(NativeEntry_WConfigPageDetail_OnInitDialog),       // +094 WConfigPageDetail::OnInitDialog
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
    NativeAddress(NativeEntry_WConfigPageDetail_GetNext),            // +0f4 WConfigPageDetail::GetNext
    NativeAddress(NativeEntry_WWizardPage_GetBackText),              // +0f8 WWizardPage::GetBackText
    NativeAddress(NativeEntry_WWizardPage_GetNextText),              // +0fc WWizardPage::GetNextText
    NativeAddress(NativeEntry_WWizardPage_GetFinishText),            // +100 WWizardPage::GetFinishText
    NativeAddress(NativeEntry_WWizardPage_GetCancelText),            // +104 WWizardPage::GetCancelText
    NativeAddress(NativeEntry_WWizardPage_GetShow),                  // +108 WWizardPage::GetShow
    NativeAddress(NativeEntry_WWizardPage_OnCancel),                 // +10c WWizardPage::OnCancel
};

// RavenShield.exe data @ 10916c98 : g_detailPageKey
const char16_t g_detailPageKey[] = u"ConfigPageDetail";
// RavenShield.exe data @ 10917338 : g_detailPageClassName
const char16_t g_detailPageClassName[] = u"WConfigPageDetail";

// RavenShield.exe @ 1090b5a0 : WConfigPageDetail::WConfigPageDetail
// Construct the base, store the owner and construct the edit control with a null procedure.
WConfigPageDetail::WConfigPageDetail(WConfigWizard *owner)
    : WWizardPage(reinterpret_cast<const uint16_t *>(g_detailPageKey), 0x7e2, owner), Owner(owner),
      DescriptionEdit(this, 0x44c, nullptr)
{
} // Native primary table 10916b88; only the completed base is cleaned if edit construction throws.

// RavenShield.exe @ 1090c560 : WConfigPageDetail::GetWindowClassName
// Format this page's native package-qualified class name into the caller's unbounded UTF-16 buffer.
void WConfigPageDetail::GetWindowClassName(uint16_t *result)
{
  MakeWindowClassName(result, reinterpret_cast<const uint16_t *>(g_detailPageClassName));
}

// RavenShield.exe @ 1090c1b0 : WConfigPageDetail::~WConfigPageDetail
// Tear down the window before reverse-order automatic control and WWizardPage base destruction.
WConfigPageDetail::~WConfigPageDetail() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_detailPageVtable;
  WWindow::MaybeDestroy();
} // Native primary table 10916b88; member/base cleanup also runs if MaybeDestroy throws.

// RavenShield.exe @ 1090c180 : WConfigPageDetail::ScalarDeletingDestructor
// Destroy the page, free storage only for flag bit zero, and return the saved receiver even after freeing it.
WConfigPageDetail *WConfigPageDetail::ScalarDeletingDestructor(uint32_t flags)
{
  this->WConfigPageDetail::~WConfigPageDetail();
  if ((flags & 1u) != 0) FreeExecutableAllocation(this);
  return this;
}

// RavenShield.exe @ 109128f0 : UnwindDetailPageDestructionBase
// Destroy the completed base through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDetailPageDestructionBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe @ 109128f9 : UnwindDetailPageDestructionEdit
// Destroy the completed edit control at page +44 through the destructor's saved parent EBP-10 receiver.
__declspec(naked) void UnwindDetailPageDestructionEdit()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 44h
    jmp dword ptr [NativeImport_WEditDestroy]
  }
}

// RavenShield.exe data @ 10919db0 : g_detailPageDestructionUnwind
const NativeCppUnwindEntry g_detailPageDestructionUnwind[2] = {
    {-1, NativeAddress(NativeEntry_UnwindDetailPageDestructionBase)}, // UnwindDetailPageDestructionBase
    {0, NativeAddress(NativeEntry_UnwindDetailPageDestructionEdit)},  // UnwindDetailPageDestructionEdit
};

// RavenShield.exe data @ 10919dc0 : g_detailPageDestructionExceptionInfo
const NativeCppFunctionInfo g_detailPageDestructionExceptionInfo = {
    0x19930520, 2, NativeAddress(g_detailPageDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912905 : HandleDetailPageDestructionException
// Dispatch the 2 completed-control/base states independently of the constructor cleanup map.
__declspec(naked) void HandleDetailPageDestructionException()
{
  __asm {
    mov eax, offset g_detailPageDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class WConfigPageFirstTime;

// RavenShield.exe @ 1090c0c0 : WConfigPageDetail::GetNext
// Allocate and construct the first-time page with the owner, freeing storage only if construction fails.
WWizardPage *WConfigPageDetail::GetNext()
{
  void *allocation = AllocateExecutableBytes(0x44);
  if (allocation == nullptr) return nullptr;
  try
  {
    return new (allocation) WConfigPageFirstTime(Owner);
  }
  catch (...)
  {
    FreeExecutableAllocation(allocation);
    throw;
  }
} // Native first-time constructor is inlined here; shared allocation cleanup is in wizard_page_support.cpp.

class FConfigCache;
extern FConfigCache *GConfig;
extern "C" int32_t GIsMMX;
extern "C" int32_t GIsPentiumPro;
extern uint32_t GPhysicalMemory;
extern const char16_t g_launcherStartupPackage[];
extern const char16_t g_rendererEngineSection[];
extern const char16_t g_rendererRenderDeviceKey[];
extern const char16_t g_rendererSoftwareClass[];
extern const char16_t g_rendererDirect3DClass[];
extern const char16_t g_rendererDescriptionFlagsKey[];
extern const char16_t g_configFalseText[];
extern const char16_t g_configSectionBreakFormat[];
extern const uint16_t *__cdecl LocalizeGeneral(const uint16_t *key, const uint16_t *package, const uint16_t *language);

// RavenShield.exe data @ 10916cbc : g_detailResHighKey
const char16_t g_detailResHighKey[] = u"ResHigh";

// RavenShield.exe data @ 10916ccc : g_detailHeight384
const char16_t g_detailHeight384[] = u"384";

// RavenShield.exe data @ 10916cd4 : g_detailWidth512
const char16_t g_detailWidth512[] = u"512";

// RavenShield.exe data @ 10916cdc : g_detailFullscreenColorBitsKey
const char16_t g_detailFullscreenColorBitsKey[] = u"FullscreenColorBits";

// RavenShield.exe data @ 10916d04 : g_detailFullscreenViewportYKey
extern const char16_t g_detailFullscreenViewportYKey[] = u"FullscreenViewportY";

// RavenShield.exe data @ 10916d2c : g_detailFullscreenViewportXKey
extern const char16_t g_detailFullscreenViewportXKey[] = u"FullscreenViewportX";

// RavenShield.exe data @ 10916d54 : g_detailWindowedColorBitsKey
const char16_t g_detailWindowedColorBitsKey[] = u"WindowedColorBits";

// RavenShield.exe data @ 10916d78 : g_detailColorBits16
const char16_t g_detailColorBits16[] = u"16";

// RavenShield.exe data @ 10916d80 : g_detailWindowedViewportYKey
const char16_t g_detailWindowedViewportYKey[] = u"WindowedViewportY";

// RavenShield.exe data @ 10916da4 : g_detailHeight240
extern const char16_t g_detailHeight240[] = u"240";

// RavenShield.exe data @ 10916dac : g_detailWindowedViewportXKey
const char16_t g_detailWindowedViewportXKey[] = u"WindowedViewportX";

// RavenShield.exe data @ 10916dd0 : g_detailWidth320
extern const char16_t g_detailWidth320[] = u"320";

// RavenShield.exe data @ 10916dd8 : g_detailResLowKey
const char16_t g_detailResLowKey[] = u"ResLow";

// RavenShield.exe data @ 10916de8 : g_detailWorldHighKey
const char16_t g_detailWorldHighKey[] = u"WorldHigh";

// RavenShield.exe data @ 10916dfc : g_detailTextureDetailKey
const char16_t g_detailTextureDetailKey[] = u"TextureDetail";

// RavenShield.exe data @ 10916e18 : g_detailWorldLowKey
const char16_t g_detailWorldLowKey[] = u"WorldLow";

// RavenShield.exe data @ 10916e2c : g_detailSkinsHighKey
const char16_t g_detailSkinsHighKey[] = u"SkinsHigh";

// RavenShield.exe data @ 10916e40 : g_detailSkinDetailKey
const char16_t g_detailSkinDetailKey[] = u"SkinDetail";

// RavenShield.exe data @ 10916e58 : g_detailMediumText
const char16_t g_detailMediumText[] = u"Medium";

// RavenShield.exe data @ 10916e68 : g_detailSkinsLowKey
const char16_t g_detailSkinsLowKey[] = u"SkinsLow";

// RavenShield.exe data @ 10916e7c : g_detailSoundHighKey
const char16_t g_detailSoundHighKey[] = u"SoundHigh";

// RavenShield.exe data @ 10916e90 : g_detailLowSoundQualityKey
const char16_t g_detailLowSoundQualityKey[] = u"LowSoundQuality";

// RavenShield.exe data @ 10916eb0 : g_detailNoVoiceTauntsKey
const char16_t g_detailNoVoiceTauntsKey[] = u"bNoVoiceTaunts";

// RavenShield.exe data @ 10916ed0 : g_detailTrueText
const char16_t g_detailTrueText[] = u"true";

// RavenShield.exe data @ 10916edc : g_detailTournamentPlayerSection
const char16_t g_detailTournamentPlayerSection[] = u"Botpack.TournamentPlayer";

// RavenShield.exe data @ 10916f10 : g_detailAnnouncerVolumeKey
const char16_t g_detailAnnouncerVolumeKey[] = u"AnnouncerVolume";

// RavenShield.exe data @ 10916f30 : g_detailLowercaseFalseText
const char16_t g_detailLowercaseFalseText[] = u"false";

// RavenShield.exe data @ 10916f3c : g_detailEffectsChannelsKey
const char16_t g_detailEffectsChannelsKey[] = u"EffectsChannels";

// RavenShield.exe data @ 10916f5c : g_detailChannels8
const char16_t g_detailChannels8[] = u"8";

// RavenShield.exe data @ 10916f60 : g_detailUseFilterKey
const char16_t g_detailUseFilterKey[] = u"UseFilter";

// RavenShield.exe data @ 10916f74 : g_detailUseSpatialKey
const char16_t g_detailUseSpatialKey[] = u"UseSpatial";

// RavenShield.exe data @ 10916f8c : g_detailGalaxyAudioSection
const char16_t g_detailGalaxyAudioSection[] = u"Galaxy.GalaxyAudioSubsystem";

// RavenShield.exe data @ 10916fc4 : g_detailUseReverbKey
const char16_t g_detailUseReverbKey[] = u"UseReverb";

// RavenShield.exe data @ 10916fe4 : g_detailSoundLowKey
const char16_t g_detailSoundLowKey[] = u"SoundLow";

// RavenShield.exe data @ 10916ff8 : g_detailFrameRate28
const char16_t g_detailFrameRate28[] = u"28";

// RavenShield.exe data @ 10917000 : g_detailWindowsClientSection
extern const char16_t g_detailWindowsClientSection[] = u"WinDrv.WindowsClient";

// RavenShield.exe data @ 1091702c : g_detailMinDesiredFrameRateKey
const char16_t g_detailMinDesiredFrameRateKey[] = u"MinDesiredFrameRate";

// RavenShield.exe data @ 10917054 : g_detailFrameRate20
const char16_t g_detailFrameRate20[] = u"20";

// RavenShield.exe data @ 109167d8 : g_detailCpuSecondsThreshold
extern const double g_detailCpuSecondsThreshold = 1.0;
// RavenShield.exe data @ 10917060 : g_detailCpuCycleThreshold
const double g_detailCpuCycleThreshold = 280000000.0;

// RavenShield.exe @ 1090b620 : WConfigPageDetail::OnInitDialog
// Apply native hardware/renderer defaults and describe the chosen sound, skin, world and resolution settings.
void WConfigPageDetail::OnInitDialog()
{
  // Native config calls independently sample the dispatch object before the receiver.
  const auto setString =
      [](const uint16_t *section, const uint16_t *key, const uint16_t *value, const uint16_t *filename)
  {
    FConfigCache *dispatchConfig = GConfig;
    FConfigCache *receiver = GConfig;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
    using SetString =
        void(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *, const uint16_t *);
    (*reinterpret_cast<const SetString *>(table + 0x30))(receiver, section, key, value, filename);
  };
  const auto setBool = [](const uint16_t *section, const uint16_t *key, int32_t value, const uint16_t *filename)
  {
    FConfigCache *dispatchConfig = GConfig;
    FConfigCache *receiver = GConfig;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
    using SetBool = void(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, int32_t, const uint16_t *);
    (*reinterpret_cast<const SetBool *>(table + 0x24))(receiver, section, key, value, filename);
  };
  WDialog::OnInitDialog();
  FString summary;
  int32_t descriptionFlags = 0;
  FConfigCache *dispatchConfig = GConfig;
  FConfigCache *receiver = GConfig;
  uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
  using GetConfigString =
      const uint16_t *(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *);
  const uint16_t *configured = (*reinterpret_cast<const GetConfigString *>(table + 0x14))(
      receiver, reinterpret_cast<const uint16_t *>(g_rendererEngineSection),
      reinterpret_cast<const uint16_t *>(g_rendererRenderDeviceKey), nullptr);
  FString renderer(configured);
  const uint16_t *rendererSection = *renderer;
  dispatchConfig = GConfig;
  receiver = GConfig;
  table = *reinterpret_cast<const uint32_t *>(dispatchConfig);
  using GetConfigInteger =
      int32_t(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, int32_t *, const uint16_t *);
  (*reinterpret_cast<const GetConfigInteger *>(table + 4))(
      receiver, rendererSection, reinterpret_cast<const uint16_t *>(g_rendererDescriptionFlagsKey), &descriptionFlags,
      nullptr);
  int32_t lowFrameRate = renderer == reinterpret_cast<const uint16_t *>(g_rendererSoftwareClass);
  if (lowFrameRate == 0)
  {
    uint16_t cpuStatus;
    __asm {
      mov eax, dword ptr [NativeImport_GSecondsPerCycle] // Core's imported GSecondsPerCycle address.
      fld qword ptr [g_detailCpuCycleThreshold]
      fmul qword ptr [eax]
      fcomp qword ptr [g_detailCpuSecondsThreshold]
      fnstsw ax
      mov cpuStatus, ax
    }
    lowFrameRate = (cpuStatus & 0x4100u) == 0; // Strict ordered greater-than; no binary64 product spill.
  }
  if (lowFrameRate != 0)
  {
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailMinDesiredFrameRateKey),
              reinterpret_cast<const uint16_t *>(g_detailFrameRate20), nullptr);
  }
  else if (renderer == reinterpret_cast<const uint16_t *>(g_rendererDirect3DClass))
  {
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailMinDesiredFrameRateKey),
              reinterpret_cast<const uint16_t *>(g_detailFrameRate28), nullptr);
  }
  if (GIsMMX == 0 || GPhysicalMemory <= 0x02000000u)
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailSoundLowKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
    setString(reinterpret_cast<const uint16_t *>(g_detailGalaxyAudioSection),
              reinterpret_cast<const uint16_t *>(g_detailUseReverbKey),
              reinterpret_cast<const uint16_t *>(g_configFalseText), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailGalaxyAudioSection),
              reinterpret_cast<const uint16_t *>(g_detailUseSpatialKey),
              reinterpret_cast<const uint16_t *>(g_configFalseText), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailGalaxyAudioSection),
              reinterpret_cast<const uint16_t *>(g_detailUseFilterKey),
              reinterpret_cast<const uint16_t *>(g_configFalseText), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailGalaxyAudioSection),
              reinterpret_cast<const uint16_t *>(g_detailEffectsChannelsKey),
              reinterpret_cast<const uint16_t *>(g_detailChannels8), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailTournamentPlayerSection),
              reinterpret_cast<const uint16_t *>(g_detailAnnouncerVolumeKey),
              reinterpret_cast<const uint16_t *>(g_detailLowercaseFalseText), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailTournamentPlayerSection),
              reinterpret_cast<const uint16_t *>(g_detailNoVoiceTauntsKey),
              reinterpret_cast<const uint16_t *>(g_detailTrueText), nullptr);
    setBool(reinterpret_cast<const uint16_t *>(g_detailGalaxyAudioSection),
            reinterpret_cast<const uint16_t *>(g_detailLowSoundQualityKey), 1, nullptr);
  }
  else
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailSoundHighKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
  }
  if (GPhysicalMemory < 0x06000000u || (descriptionFlags & 8) != 0)
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailSkinsLowKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailSkinDetailKey),
              reinterpret_cast<const uint16_t *>(g_detailMediumText), nullptr);
  }
  else
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailSkinsHighKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
  }
  if (GPhysicalMemory < 0x04000000u || (descriptionFlags & 4) != 0)
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailWorldLowKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailTextureDetailKey),
              reinterpret_cast<const uint16_t *>(g_detailMediumText), nullptr);
  }
  else
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailWorldHighKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
  }
  if ((GIsMMX == 0 || GIsPentiumPro == 0) && renderer == reinterpret_cast<const uint16_t *>(g_rendererSoftwareClass))
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailResLowKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedViewportXKey),
              reinterpret_cast<const uint16_t *>(g_detailWidth320), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedViewportYKey),
              reinterpret_cast<const uint16_t *>(g_detailHeight240), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedColorBitsKey),
              reinterpret_cast<const uint16_t *>(g_detailColorBits16), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportXKey),
              reinterpret_cast<const uint16_t *>(g_detailWidth320), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportYKey),
              reinterpret_cast<const uint16_t *>(g_detailHeight240), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenColorBitsKey),
              reinterpret_cast<const uint16_t *>(g_detailColorBits16), nullptr);
  }
  else if (renderer == reinterpret_cast<const uint16_t *>(g_rendererSoftwareClass) || (descriptionFlags & 4) != 0)
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailResLowKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedViewportXKey),
              reinterpret_cast<const uint16_t *>(g_detailWidth512), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedViewportYKey),
              reinterpret_cast<const uint16_t *>(g_detailHeight384), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailWindowedColorBitsKey),
              reinterpret_cast<const uint16_t *>(g_detailColorBits16), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportXKey),
              reinterpret_cast<const uint16_t *>(g_detailWidth512), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportYKey),
              reinterpret_cast<const uint16_t *>(g_detailHeight384), nullptr);
    setString(reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
              reinterpret_cast<const uint16_t *>(g_detailFullscreenColorBitsKey),
              reinterpret_cast<const uint16_t *>(g_detailColorBits16), nullptr);
  }
  else
  {
    summary = summary +
              LocalizeGeneral(reinterpret_cast<const uint16_t *>(g_detailResHighKey),
                              reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr) +
              reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat);
  }
  const uint16_t *text = *summary;
  table = *reinterpret_cast<const uint32_t *>(&DescriptionEdit);
  const auto setText = *reinterpret_cast<void(__thiscall **)(WEdit *, const uint16_t *)>(table + 0x2c);
  setText(&DescriptionEdit, text);
} // Native cleanup releases renderer before summary, including exceptions; config writes are not rolled back.

// RavenShield.exe @ 109127f0 : UnwindDetailInitSummary
// Destroy the completed summary string at parent EBP-28 during initialization unwind.
__declspec(naked) void UnwindDetailInitSummary()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109127f9 : UnwindDetailInitRenderer
// Destroy the completed renderer string at parent EBP-1c during initialization unwind.
__declspec(naked) void UnwindDetailInitRenderer()
{
  __asm {
    lea ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912802 : UnwindDetailInitSoundLowText
// Destroy the completed sound low text string at parent EBP-34 during initialization unwind.
__declspec(naked) void UnwindDetailInitSoundLowText()
{
  __asm {
    lea ecx, [ebp-34h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091280b : UnwindDetailInitSoundLowLine
// Destroy the completed sound low line string at parent EBP-40 during initialization unwind.
__declspec(naked) void UnwindDetailInitSoundLowLine()
{
  __asm {
    lea ecx, [ebp-40h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912814 : UnwindDetailInitSoundHighText
// Destroy the completed sound high text string at parent EBP-4c during initialization unwind.
__declspec(naked) void UnwindDetailInitSoundHighText()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091281d : UnwindDetailInitSoundHighLine
// Destroy the completed sound high line string at parent EBP-58 during initialization unwind.
__declspec(naked) void UnwindDetailInitSoundHighLine()
{
  __asm {
    lea ecx, [ebp-58h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912826 : UnwindDetailInitSkinsLowText
// Destroy the completed skins low text string at parent EBP-64 during initialization unwind.
__declspec(naked) void UnwindDetailInitSkinsLowText()
{
  __asm {
    lea ecx, [ebp-64h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091282f : UnwindDetailInitSkinsLowLine
// Destroy the completed skins low line string at parent EBP-70 during initialization unwind.
__declspec(naked) void UnwindDetailInitSkinsLowLine()
{
  __asm {
    lea ecx, [ebp-70h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912838 : UnwindDetailInitSkinsHighText
// Destroy the completed skins high text string at parent EBP-7c during initialization unwind.
__declspec(naked) void UnwindDetailInitSkinsHighText()
{
  __asm {
    lea ecx, [ebp-7ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912841 : UnwindDetailInitSkinsHighLine
// Destroy the completed skins high line string at parent EBP-88 during initialization unwind.
__declspec(naked) void UnwindDetailInitSkinsHighLine()
{
  __asm {
    lea ecx, [ebp-88h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091284d : UnwindDetailInitWorldLowText
// Destroy the completed world low text string at parent EBP-94 during initialization unwind.
__declspec(naked) void UnwindDetailInitWorldLowText()
{
  __asm {
    lea ecx, [ebp-94h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912859 : UnwindDetailInitWorldLowLine
// Destroy the completed world low line string at parent EBP-a0 during initialization unwind.
__declspec(naked) void UnwindDetailInitWorldLowLine()
{
  __asm {
    lea ecx, [ebp-0a0h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912865 : UnwindDetailInitWorldHighText
// Destroy the completed world high text string at parent EBP-ac during initialization unwind.
__declspec(naked) void UnwindDetailInitWorldHighText()
{
  __asm {
    lea ecx, [ebp-0ach]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912871 : UnwindDetailInitWorldHighLine
// Destroy the completed world high line string at parent EBP-b8 during initialization unwind.
__declspec(naked) void UnwindDetailInitWorldHighLine()
{
  __asm {
    lea ecx, [ebp-0b8h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 1091287d : UnwindDetailInitSoftwareResolutionText
// Destroy the completed software resolution text string at parent EBP-c4 during initialization unwind.
__declspec(naked) void UnwindDetailInitSoftwareResolutionText()
{
  __asm {
    lea ecx, [ebp-0c4h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912889 : UnwindDetailInitSoftwareResolutionLine
// Destroy the completed software resolution line string at parent EBP-d0 during initialization unwind.
__declspec(naked) void UnwindDetailInitSoftwareResolutionLine()
{
  __asm {
    lea ecx, [ebp-0d0h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912895 : UnwindDetailInitFallbackResolutionText
// Destroy the completed fallback resolution text string at parent EBP-dc during initialization unwind.
__declspec(naked) void UnwindDetailInitFallbackResolutionText()
{
  __asm {
    lea ecx, [ebp-0dch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109128a1 : UnwindDetailInitFallbackResolutionLine
// Destroy the completed fallback resolution line string at parent EBP-e8 during initialization unwind.
__declspec(naked) void UnwindDetailInitFallbackResolutionLine()
{
  __asm {
    lea ecx, [ebp-0e8h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109128ad : UnwindDetailInitHighResolutionText
// Destroy the completed high resolution text string at parent EBP-f4 during initialization unwind.
__declspec(naked) void UnwindDetailInitHighResolutionText()
{
  __asm {
    lea ecx, [ebp-0f4h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109128b9 : UnwindDetailInitHighResolutionLine
// Destroy the completed high resolution line string at parent EBP-100 during initialization unwind.
__declspec(naked) void UnwindDetailInitHighResolutionLine()
{
  __asm {
    lea ecx, [ebp-100h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 10919cd0 : g_detailInitUnwind
const NativeCppUnwindEntry g_detailInitUnwind[20] = {
    {-1, NativeAddress(NativeEntry_UnwindDetailInitSummary)},                // UnwindDetailInitSummary
    {0, NativeAddress(NativeEntry_UnwindDetailInitRenderer)},                // UnwindDetailInitRenderer
    {1, NativeAddress(NativeEntry_UnwindDetailInitSoundLowText)},            // UnwindDetailInitSoundLowText
    {2, NativeAddress(NativeEntry_UnwindDetailInitSoundLowLine)},            // UnwindDetailInitSoundLowLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitSoundHighText)},           // UnwindDetailInitSoundHighText
    {4, NativeAddress(NativeEntry_UnwindDetailInitSoundHighLine)},           // UnwindDetailInitSoundHighLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitSkinsLowText)},            // UnwindDetailInitSkinsLowText
    {6, NativeAddress(NativeEntry_UnwindDetailInitSkinsLowLine)},            // UnwindDetailInitSkinsLowLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitSkinsHighText)},           // UnwindDetailInitSkinsHighText
    {8, NativeAddress(NativeEntry_UnwindDetailInitSkinsHighLine)},           // UnwindDetailInitSkinsHighLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitWorldLowText)},            // UnwindDetailInitWorldLowText
    {10, NativeAddress(NativeEntry_UnwindDetailInitWorldLowLine)},           // UnwindDetailInitWorldLowLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitWorldHighText)},           // UnwindDetailInitWorldHighText
    {12, NativeAddress(NativeEntry_UnwindDetailInitWorldHighLine)},          // UnwindDetailInitWorldHighLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitSoftwareResolutionText)},  // UnwindDetailInitSoftwareResolutionText
    {14, NativeAddress(NativeEntry_UnwindDetailInitSoftwareResolutionLine)}, // UnwindDetailInitSoftwareResolutionLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitFallbackResolutionText)},  // UnwindDetailInitFallbackResolutionText
    {16, NativeAddress(NativeEntry_UnwindDetailInitFallbackResolutionLine)}, // UnwindDetailInitFallbackResolutionLine
    {1, NativeAddress(NativeEntry_UnwindDetailInitHighResolutionText)},      // UnwindDetailInitHighResolutionText
    {18, NativeAddress(NativeEntry_UnwindDetailInitHighResolutionLine)},     // UnwindDetailInitHighResolutionLine
};

// RavenShield.exe data @ 10919d70 : g_detailInitExceptionInfo
const NativeCppFunctionInfo g_detailInitExceptionInfo = {0x19930520, 20, NativeAddress(g_detailInitUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109128c5 : HandleDetailInitException
// Dispatch twenty string states and branch-specific concatenation cleanup without a local catch or rollback.
__declspec(naked) void HandleDetailInitException()
{
  __asm {
    mov eax, offset g_detailInitExceptionInfo
    jmp DispatchExecutableCppException
  }
}
