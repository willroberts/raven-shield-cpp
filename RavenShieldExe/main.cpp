#include "native_symbols.hpp"
// Original game WinMain: instance forwarding, Core/window setup, engine handoff and native shutdown.
#include "cpp_exception_metadata.hpp"
#include "game_entry.hpp"
#include "object_support.hpp"
#include "container_support.hpp"
#include "launch_runtime.hpp"
#include <windows.h>
#include <malloc.h>

class FConfigCache;
class FConfigCacheIni;
class FOutputDevice;
class FOutputDeviceError;
class FOutputDeviceWindowsError;
class FFeedbackContext;
class FFileManager;
class FMalloc;
class WLog;
class WWindow;
class FExec;
class UViewport;
extern WLog *GLogWindow;
extern FFileManager *GFileManager;
extern FConfigCache *GConfig;
extern int32_t GIsStarted, GIsGuarded, GIsClient, GIsServer, GIsEditor, GIsScriptable, GLazyLoad;
extern int32_t GIsRequestingExit, GUnicodeOS;
extern uint32_t g_startupDialogInstance;
extern "C" uint16_t GPackage[64];
extern const uint16_t *__cdecl appPackage();
extern const uint16_t *__cdecl appCmdLine();
extern uint16_t *__cdecl appStrcpy(uint16_t *destination, const uint16_t *source);
extern const uint16_t *__cdecl appStrfind(const uint16_t *text, const uint16_t *match);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern int32_t __cdecl ParseParam(const uint16_t *text, const uint16_t *parameter);
extern int32_t __cdecl Parse(const uint16_t *text, const uint16_t *match, FString &result);
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *destination, const uint16_t *text, int32_t count);
extern void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base);
extern void __cdecl InitializeStartupDialog(const uint16_t *filename);
extern void __cdecl RequestStartupDialogQuit();
extern void __cdecl appPreExit();
extern void __cdecl appExit();
extern const char16_t g_configWizardLogoPath[];
extern const char16_t g_safeOptionsRunKey[];
extern const char16_t g_detailWidth320[];
extern const char16_t g_detailHeight240[];
extern const char16_t g_detailFullscreenViewportYKey[];
extern const char16_t g_detailFullscreenViewportXKey[];
extern const char16_t g_detailWindowsClientSection[];

// RavenShield.exe data @ 10917688 : g_winMainRunningIni
extern const char16_t g_winMainRunningIni[] = u"Running.ini";

// RavenShield.exe data @ 109176c0 : g_winMainChangeVideo
extern const char16_t g_winMainChangeVideo[] = u"changevideo";
// RavenShield.exe data @ 10917fdc : g_winMainExitKey
const char16_t g_winMainExitKey[] = u"Exit";
// RavenShield.exe data @ 10917fe8 : g_winMainGoToGameCommand
const char16_t g_winMainGoToGameCommand[] = u"GOTOGAME";
// RavenShield.exe data @ 10917ffc : g_winMainExecPrefix
const char16_t g_winMainExecPrefix[] = u"exec ";
// RavenShield.exe data @ 10918008 : g_winMainExecKey
const char16_t g_winMainExecKey[] = u"EXEC=";
// RavenShield.exe data @ 10918014 : g_winMainHeight1200
const char16_t g_winMainHeight1200[] = u"1200";
// RavenShield.exe data @ 10918020 : g_winMainWidth1600
const char16_t g_winMainWidth1600[] = u"1600";
// RavenShield.exe data @ 1091802c : g_winMainSize1600x1200
const char16_t g_winMainSize1600x1200[] = u"1600x1200";
// RavenShield.exe data @ 10918040 : g_winMainSize1280x1024
const char16_t g_winMainSize1280x1024[] = u"1280x1024";
// RavenShield.exe data @ 10918054 : g_winMainHeight960
const char16_t g_winMainHeight960[] = u"960";
// RavenShield.exe data @ 1091805c : g_winMainWidth1280
const char16_t g_winMainWidth1280[] = u"1280";
// RavenShield.exe data @ 10918068 : g_winMainSize1280x960
const char16_t g_winMainSize1280x960[] = u"1280x960";
// RavenShield.exe data @ 1091807c : g_winMainHeight768
const char16_t g_winMainHeight768[] = u"768";
// RavenShield.exe data @ 10918084 : g_winMainWidth1024
const char16_t g_winMainWidth1024[] = u"1024";
// RavenShield.exe data @ 10918090 : g_winMainSize1024x768
const char16_t g_winMainSize1024x768[] = u"1024x768";
// RavenShield.exe data @ 109180a4 : g_winMainHeight600
const char16_t g_winMainHeight600[] = u"600";
// RavenShield.exe data @ 109180ac : g_winMainWidth800
const char16_t g_winMainWidth800[] = u"800";
// RavenShield.exe data @ 109180b4 : g_winMainSize800x600
const char16_t g_winMainSize800x600[] = u"800x600";
// RavenShield.exe data @ 109180c4 : g_winMainHeight480
const char16_t g_winMainHeight480[] = u"480";
// RavenShield.exe data @ 109180cc : g_winMainWidth640
const char16_t g_winMainWidth640[] = u"640";
// RavenShield.exe data @ 109180d4 : g_winMainSize640x480
const char16_t g_winMainSize640x480[] = u"640x480";
// RavenShield.exe data @ 109180e4 : g_winMainSize320x240
const char16_t g_winMainSize320x240[] = u"320x240";
// RavenShield.exe data @ 109180f4 : g_winMainStartKey
const char16_t g_winMainStartKey[] = u"Start";
// RavenShield.exe data @ 109181f0 : g_winMainLogName
const char16_t g_winMainLogName[] = u"GameLog";
// RavenShield.exe data @ 10918200 : g_winMainSplashServerParameter
const char16_t g_winMainSplashServerParameter[] = u"server";
// RavenShield.exe data @ 10918210 : g_winMainLogoSuffix
const char16_t g_winMainLogoSuffix[] = u"Logo.bmp";
// RavenShield.exe data @ 10918224 : g_winMainHelpDirectory
const char16_t g_winMainHelpDirectory[] = u"..\\Help";
// RavenShield.exe data @ 10918234 : g_winMainLogParameter
const char16_t g_winMainLogParameter[] = u"LOG";
// RavenShield.exe data @ 1091823c : g_winMainLazyParameter
const char16_t g_winMainLazyParameter[] = u"LAZY";
// RavenShield.exe data @ 10918248 : g_winMainServerParameter
const char16_t g_winMainServerParameter[] = u"SERVER";
// RavenShield.exe data @ 10918258 : g_winMainBrowserProperty
const char16_t g_winMainBrowserProperty[] = u"IsBrowser";
// RavenShield.exe data @ 1091826c : g_winMainLogClass
const char16_t g_winMainLogClass[] = u"WLog";
// RavenShield.exe data @ 10918278 : g_winMainTestRenderDevice
const char16_t g_winMainTestRenderDevice[] = u"TestRenDev";
// RavenShield.exe data @ 10918290 : g_winMainNewWindow
const char16_t g_winMainNewWindow[] = u"NewWindow";

// RavenShield.exe @ 10910ed0 : GameWinMain
// Forward to an existing browser or initialize Core/windows, apply launch options, run the engine and shut down.
int32_t __stdcall GameWinMain(uint32_t instance, uint32_t previousInstance, char *commandLine, int32_t showWindow)
{
  GIsStarted = 1;
  int32_t result = 0;
  g_startupDialogInstance = instance;
  const uint16_t *wideCommandLine = reinterpret_cast<const uint16_t *>(GetCommandLineW());
  const uint16_t *browserProperty = reinterpret_cast<const uint16_t *>(g_winMainBrowserProperty);
  appStrcpy(GPackage, appPackage());
  // The native body ignores the other three WinMain arguments and uses the full OS-wide command line.
  if (!appStrfind(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainNewWindow)) &&
      !appStrfind(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainChangeVideo)) &&
      !appStrfind(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainTestRenderDevice)))
  {
    uint16_t windowClass[256]; // Inferred native stack capacity; the shared formatter imposes no bound.
    MakeWindowClassName(windowClass, reinterpret_cast<const uint16_t *>(g_winMainLogClass));
    HWND window = nullptr;
    for (;;)
    {
      if (GUnicodeOS)
      {
        window = FindWindowExW(window, nullptr, reinterpret_cast<const wchar_t *>(windowClass), nullptr);
      }
      else
      {
        char *classBuffer = nullptr;
        if (winGetSizeANSI(windowClass) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(windowClass)) + 7u) & 0xfffffff8u;
          bytes = (bytes + 3u) & 0xfffffffcu;
          classBuffer = static_cast<char *>(_alloca(bytes));
        }
        const int32_t classBufferCount = winGetSizeANSI(windowClass);
        const char *classBufferText = winToANSI(classBuffer, windowClass, classBufferCount);
        window = FindWindowExA(window, nullptr, classBufferText, nullptr);
      }
      if (!window) break;
      HANDLE browser;
      if (GUnicodeOS)
      {
        browser = GetPropW(window, reinterpret_cast<const wchar_t *>(browserProperty));
      }
      else
      {
        char *browserBuffer = nullptr;
        if (winGetSizeANSI(browserProperty) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(browserProperty)) + 7u) & 0xfffffff8u;
          bytes = (bytes + 3u) & 0xfffffffcu;
          browserBuffer = static_cast<char *>(_alloca(bytes));
        }
        const int32_t browserBufferCount = winGetSizeANSI(browserProperty);
        const char *browserBufferText = winToANSI(browserBuffer, browserProperty, browserBufferCount);
        browser = GetPropA(window, browserBufferText);
      }
      if (!browser) continue; // Native next search uses this window as parent, not child-after.
      const uint16_t *arguments = wideCommandLine;
      while (*arguments && *arguments != 0x20) ++arguments;
      if (*arguments == 0x20) ++arguments; // No quote parsing, tab handling or repeated-space trimming.
      const uint32_t messageSlot = *reinterpret_cast<const uint32_t *>(NativeAddress(NativeImport_WindowMessageOpen));
      COPYDATASTRUCT copy;
      copy.dwData = *reinterpret_cast<const uint32_t *>(messageSlot);
      copy.cbData = static_cast<uint32_t>(appStrlen(arguments)) * 4u + 4u; // Native count, despite UTF-16 data.
      copy.lpData = const_cast<uint16_t *>(arguments);
      DWORD_PTR reply; // Native overwrites the now-unused instance/command-line stack slot.
      SendMessageTimeoutW(window, 0x4a, 0, reinterpret_cast<LPARAM>(&copy), 3, 30000, &reply);
      GIsStarted = 0;
      return 0;
    }
  }
  GIsGuarded = 1;
  try
  {
    GIsClient = 1;
    const auto initialize = *reinterpret_cast<void(__cdecl **)(
        const uint16_t *, const uint16_t *, FMalloc *, FOutputDevice *, FOutputDeviceError *, FFeedbackContext *,
        FFileManager *, FConfigCache *(__cdecl *)(), int32_t)>(NativeAddress(NativeImport_appInit));
    initialize(GPackage, wideCommandLine, reinterpret_cast<FMalloc *>(g_launchAllocatorStorage),
               reinterpret_cast<FOutputDevice *>(g_launchFileLogStorage),
               reinterpret_cast<FOutputDeviceError *>(g_launchErrorStorage),
               reinterpret_cast<FFeedbackContext *>(g_launchFeedbackStorage),
               reinterpret_cast<FFileManager *>(g_launchFileManagerStorage), FConfigCacheIni::Factory, 1);
    GIsServer = 1;
    GIsClient = ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainServerParameter)) == 0 ? 1 : 0;
    GIsEditor = 0;
    GIsScriptable = 1;
    GLazyLoad =
        !GIsClient || ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainLazyParameter)) != 0 ? 1 : 0;
    const int32_t showLog = ParseParam(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainLogParameter));
    FString logo = FString(reinterpret_cast<const uint16_t *>(g_winMainHelpDirectory)) * GPackage +
                   reinterpret_cast<const uint16_t *>(g_winMainLogoSuffix);
    const uint16_t *logoName = *logo;
    FFileManager *manager = GFileManager;
    const uint32_t fileTable = *reinterpret_cast<const uint32_t *>(manager);
    const auto fileSize = *reinterpret_cast<int32_t(__thiscall **)(FFileManager *, const uint16_t *)>(fileTable + 0xc);
    if (fileSize(manager, logoName) < 0) logo = reinterpret_cast<const uint16_t *>(g_configWizardLogoPath);
    appStrcpy(GPackage, appPackage());
    if (!showLog && !ParseParam(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainSplashServerParameter)) &&
        !appStrfind(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainTestRenderDevice)))
      InitializeStartupDialog(*logo);
    const auto initWindowing = *reinterpret_cast<void(__cdecl **)()>(NativeAddress(NativeImport_InitWindowing));
    initWindowing();
    auto *storage = static_cast<WLog *>(AllocateExecutableBytes(0x2b4));
    WLog *log = nullptr;
    try
    {
      if (storage)
      {
        uint32_t nameWord;
        const auto constructName = *reinterpret_cast<void(__thiscall **)(uint32_t *, const uint16_t *, int32_t)>(
            NativeAddress(NativeImport_FNameConstructText));
        constructName(&nameWord, reinterpret_cast<const uint16_t *>(g_winMainLogName), 1);
        ConstructLaunchLogInline(storage, nameWord);
        log = storage;
      }
    }
    catch (...)
    {
      FreeExecutableAllocation(storage);
      throw;
    }
    GLogWindow = log;
    const auto openLog =
        *reinterpret_cast<void(__thiscall **)(WLog *, int32_t, int32_t)>(NativeAddress(NativeImport_WLog_OpenWindow));
    openLog(GLogWindow, showLog, 0); // Native continues here after a null allocation.
    // Bind slots so each native call reads its target after preceding callbacks.
    const auto &localize =
        *reinterpret_cast<const uint16_t *(__cdecl **)(const uint16_t *, const uint16_t *, const uint16_t *)>(
            NativeAddress(NativeImport_LocalizeGeneralWide));
    const auto &logText = *reinterpret_cast<void(__thiscall **)(FOutputDevice *, int32_t,
                                                                const uint16_t *)>(
        NativeAddress(NativeImport_FOutputDeviceLogEvent)); // EName occupies the native signed 32-bit event word.
    const uint16_t *start = localize(reinterpret_cast<const uint16_t *>(g_winMainStartKey), GPackage, nullptr);
    logText(reinterpret_cast<FOutputDevice *>(reinterpret_cast<uint32_t>(GLogWindow) + 0x3cu), 0x314, start);
    const auto &getWindow = *reinterpret_cast<HWND(__thiscall **)(const WWindow *)>(NativeAddress(NativeImport_HWND));
    if (GIsClient)
    {
      if (GUnicodeOS)
      {
        SetPropW(getWindow(reinterpret_cast<const WWindow *>(GLogWindow)),
                 reinterpret_cast<const wchar_t *>(browserProperty), reinterpret_cast<HANDLE>(1));
      }
      else
      {
        char *setBrowserBuffer = nullptr;
        if (winGetSizeANSI(browserProperty) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(browserProperty)) + 7u) & 0xfffffff8u;
          bytes = (bytes + 3u) & 0xfffffffcu;
          setBrowserBuffer = static_cast<char *>(_alloca(bytes));
        }
        const int32_t setBrowserBufferCount = winGetSizeANSI(browserProperty);
        const char *setBrowserBufferText = winToANSI(setBrowserBuffer, browserProperty, setBrowserBufferCount);
        HWND window = getWindow(reinterpret_cast<const WWindow *>(GLogWindow));
        SetPropA(window, setBrowserBufferText, reinterpret_cast<HANDLE>(1));
      }
    }
    FString width;
    FString height;
    int32_t sizeSelected = 0;
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize320x240)))
    {
      width = reinterpret_cast<const uint16_t *>(g_detailWidth320);
      height = reinterpret_cast<const uint16_t *>(g_detailHeight240);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize640x480)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth640);
      height = reinterpret_cast<const uint16_t *>(g_winMainHeight480);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize800x600)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth800);
      height = reinterpret_cast<const uint16_t *>(g_winMainHeight600);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize1024x768)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth1024);
      height = reinterpret_cast<const uint16_t *>(g_winMainHeight768);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize1280x960)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth1280);
      height = reinterpret_cast<const uint16_t *>(g_winMainHeight960);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize1280x1024)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth1280);
      height = reinterpret_cast<const uint16_t *>(g_winMainWidth1024);
      sizeSelected = 1;
    }
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainSize1600x1200)))
    {
      width = reinterpret_cast<const uint16_t *>(g_winMainWidth1600);
      height = reinterpret_cast<const uint16_t *>(g_winMainHeight1200);
      sizeSelected = 1;
    }
    if (sizeSelected)
    {
      const uint16_t *x = *width;
      FConfigCache *config = GConfig;
      uint32_t table = *reinterpret_cast<const uint32_t *>(config);
      auto setString = *reinterpret_cast<void(__thiscall **)(FConfigCache *, const uint16_t *, const uint16_t *,
                                                             const uint16_t *, const uint16_t *)>(table + 0x30);
      setString(config, reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
                reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportXKey), x, nullptr);
      const uint16_t *y = *height;
      config = GConfig;
      table = *reinterpret_cast<const uint32_t *>(config);
      setString = *reinterpret_cast<void(__thiscall **)(FConfigCache *, const uint16_t *, const uint16_t *,
                                                        const uint16_t *, const uint16_t *)>(table + 0x30);
      setString(config, reinterpret_cast<const uint16_t *>(g_detailWindowsClientSection),
                reinterpret_cast<const uint16_t *>(g_detailFullscreenViewportYKey), y, nullptr);
    }
    UEngine *engine = InitEngine();
    if (engine)
    {
      const uint16_t *running = localize(reinterpret_cast<const uint16_t *>(g_safeOptionsRunKey), GPackage, nullptr);
      logText(reinterpret_cast<FOutputDevice *>(reinterpret_cast<uint32_t>(GLogWindow) + 0x3cu), 0x314, running);
      RequestStartupDialogQuit();
      FString execCommand;
      if (Parse(wideCommandLine, reinterpret_cast<const uint16_t *>(g_winMainExecKey), execCommand))
      {
        execCommand = FString(reinterpret_cast<const uint16_t *>(g_winMainExecPrefix)) + execCommand;
        auto *client = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44);
        if (client && reinterpret_cast<FArray *>(client + 0x30)->Num())
        {
          client = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44);
          UViewport *viewport = **reinterpret_cast<UViewport ***>(client + 0x30);
          if (viewport)
          {
            WLog *outputWindow = GLogWindow;
            FOutputDevice *output =
                outputWindow ? reinterpret_cast<FOutputDevice *>(reinterpret_cast<uint32_t>(outputWindow) + 0x3cu)
                             : nullptr;
            FExec *viewportExec = reinterpret_cast<FExec *>(reinterpret_cast<uint32_t>(viewport) + 0x30u);
            const uint16_t *text = *execCommand;
            const uint32_t table = *reinterpret_cast<const uint32_t *>(viewportExec);
            using ExecCommand = int32_t(__thiscall *)(FExec *, const uint16_t *, FOutputDevice *);
            const auto exec = *reinterpret_cast<const ExecCommand *>(table);
            exec(viewportExec, text, output);
          }
        }
      }
      if ((*reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(engine) + 0x120) & 0x1000) != 0)
      {
        auto *client = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44);
        if (client && reinterpret_cast<FArray *>(client + 0x30)->Num())
        {
          client = *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44);
          UViewport *viewport = **reinterpret_cast<UViewport ***>(client + 0x30);
          if (viewport)
          {
            WLog *outputWindow = GLogWindow;
            FOutputDevice *output =
                outputWindow ? reinterpret_cast<FOutputDevice *>(reinterpret_cast<uint32_t>(outputWindow) + 0x3cu)
                             : nullptr;
            FExec *viewportExec = reinterpret_cast<FExec *>(reinterpret_cast<uint32_t>(viewport) + 0x30u);
            const uint32_t table = *reinterpret_cast<const uint32_t *>(viewportExec);
            using ExecCommand = int32_t(__thiscall *)(FExec *, const uint16_t *, FOutputDevice *);
            const auto exec = *reinterpret_cast<const ExecCommand *>(table);
            exec(viewportExec, reinterpret_cast<const uint16_t *>(g_winMainGoToGameCommand), output);
          }
        }
      }
      if (!GIsRequestingExit) MainLoop(engine);
    }
    manager = GFileManager;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(manager);
    const auto removeFile =
        *reinterpret_cast<int32_t(__thiscall **)(FFileManager *, const uint16_t *, int32_t, int32_t)>(table + 0x10);
    removeFile(manager, reinterpret_cast<const uint16_t *>(g_winMainRunningIni), 0, 0);
    if (GUnicodeOS)
    {
      RemovePropW(getWindow(reinterpret_cast<const WWindow *>(GLogWindow)),
                  reinterpret_cast<const wchar_t *>(browserProperty));
    }
    else
    {
      char *removeBrowserBuffer = nullptr;
      if (winGetSizeANSI(browserProperty) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(browserProperty)) + 7u) & 0xfffffff8u;
        bytes = (bytes + 3u) & 0xfffffffcu;
        removeBrowserBuffer = static_cast<char *>(_alloca(bytes));
      }
      const int32_t removeBrowserBufferCount = winGetSizeANSI(browserProperty);
      const char *removeBrowserBufferText = winToANSI(removeBrowserBuffer, browserProperty, removeBrowserBufferCount);
      HWND window = getWindow(reinterpret_cast<const WWindow *>(GLogWindow));
      RemovePropA(window, removeBrowserBufferText);
    }
    const uint16_t *exit = localize(reinterpret_cast<const uint16_t *>(g_winMainExitKey), GPackage, nullptr);
    logText(reinterpret_cast<FOutputDevice *>(reinterpret_cast<uint32_t>(GLogWindow) + 0x3cu), 0x314, exit);
    if (GLogWindow)
    {
      WLog *window = GLogWindow;
      const uint32_t table = *reinterpret_cast<const uint32_t *>(window);
      const auto destroyWindow = *reinterpret_cast<WLog *(__thiscall **)(WLog *, uint32_t)>(table + 4);
      destroyWindow(window, 1);
    }
    appPreExit();
    GIsGuarded = 0;
  } // Height, width and logo are destroyed in that order before appExit on the normal path.
  // RavenShield.exe @ 1091186b : HandleGameWinMainFailure
  // Record failure and invoke the fixed Windows error device after automatic string/construction cleanup.
  catch (...)
  {
    result = 1;
    reinterpret_cast<FOutputDeviceWindowsError *>(g_launchErrorStorage)->HandleError();
  }
  appExit(); // Outside the guarded catch; a returning HandleError reaches this same native continuation.
  GIsStarted = 0;
  return result;
}

// RavenShield.exe @ 10912f20 : DestroyWinMainHelpDirectory
// Destroy the live HelpDirectory FString at parent EBP-64 during unwinding.
__declspec(naked) void DestroyWinMainHelpDirectory()
{
  __asm {
    lea ecx, [ebp-64h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f29 : DestroyWinMainPackageLogoPath
// Destroy the live PackageLogoPath FString at parent EBP-48 during unwinding.
__declspec(naked) void DestroyWinMainPackageLogoPath()
{
  __asm {
    lea ecx, [ebp-48h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f32 : DestroyWinMainLogo
// Destroy the live Logo FString at parent EBP-54 during unwinding.
__declspec(naked) void DestroyWinMainLogo()
{
  __asm {
    lea ecx, [ebp-54h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f46 : DestroyWinMainWidth
// Destroy the live Width FString at parent EBP-20 during unwinding.
__declspec(naked) void DestroyWinMainWidth()
{
  __asm {
    lea ecx, [ebp-20h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f4f : DestroyWinMainHeight
// Destroy the live Height FString at parent EBP-2c during unwinding.
__declspec(naked) void DestroyWinMainHeight()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f58 : DestroyWinMainExecCommand
// Destroy the live ExecCommand FString at parent EBP-3c during unwinding.
__declspec(naked) void DestroyWinMainExecCommand()
{
  __asm {
    lea ecx, [ebp-3ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f61 : DestroyWinMainExecPrefix
// Destroy the live ExecPrefix FString at parent EBP-70 during unwinding.
__declspec(naked) void DestroyWinMainExecPrefix()
{
  __asm {
    lea ecx, [ebp-70h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f6a : DestroyWinMainExecConcatenation
// Destroy the live ExecConcatenation FString at parent EBP-7c during unwinding.
__declspec(naked) void DestroyWinMainExecConcatenation()
{
  __asm {
    lea ecx, [ebp-7ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f3b : FreeWinMainLogStorage
// Free raw WLog storage at parent EBP-14 only while construction is active.
__declspec(naked) void FreeWinMainLogStorage()
{
  __asm {
    mov eax, [ebp-14h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 1091af90 : g_gameWinMainUnwind
const NativeCppUnwindEntry g_gameWinMainUnwind[13] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_DestroyWinMainHelpDirectory)},      // DestroyWinMainHelpDirectory
    {1, NativeAddress(NativeEntry_DestroyWinMainPackageLogoPath)},    // DestroyWinMainPackageLogoPath
    {2, NativeAddress(NativeEntry_DestroyWinMainLogo)},               // DestroyWinMainLogo
    {0, NativeAddress(NativeEntry_DestroyWinMainLogo)},               // DestroyWinMainLogo
    {4, NativeAddress(NativeEntry_DestroyWinMainPackageLogoPath)},    // DestroyWinMainPackageLogoPath
    {4, NativeAddress(NativeEntry_FreeWinMainLogStorage)},            // FreeWinMainLogStorage
    {4, NativeAddress(NativeEntry_DestroyWinMainWidth)},              // DestroyWinMainWidth
    {7, NativeAddress(NativeEntry_DestroyWinMainHeight)},             // DestroyWinMainHeight
    {8, NativeAddress(NativeEntry_DestroyWinMainExecCommand)},        // DestroyWinMainExecCommand
    {9, NativeAddress(NativeEntry_DestroyWinMainExecPrefix)},         // DestroyWinMainExecPrefix
    {10, NativeAddress(NativeEntry_DestroyWinMainExecConcatenation)}, // DestroyWinMainExecConcatenation
    {-1, 0},
};

// RavenShield.exe data @ 1091aff8 : g_gameWinMainCatches
const NativeCppCatchHandler g_gameWinMainCatches[1] = {
    {0, 0, 0, 0x1091186b}, // HandleGameWinMainFailure
};

// RavenShield.exe data @ 1091b008 : g_gameWinMainTryBlocks
const NativeCppTryBlock g_gameWinMainTryBlocks[1] = {
    {0, 11, 12, 1, NativeAddress(g_gameWinMainCatches)},
};

// RavenShield.exe data @ 1091b01c : g_gameWinMainExceptionInfo
const NativeCppFunctionInfo g_gameWinMainExceptionInfo = {
    0x19930520, 13, NativeAddress(g_gameWinMainUnwind), 1, NativeAddress(g_gameWinMainTryBlocks), 0, 0};

// RavenShield.exe @ 10912f73 : HandleGameWinMainException
// Dispatch the thirteen-state string/allocation cleanup and the single crash catch-all.
__declspec(naked) void HandleGameWinMainException()
{
  __asm {
    mov eax, offset g_gameWinMainExceptionInfo
    jmp DispatchExecutableCppException
  }
}
