#include "native_symbols.hpp"
// Original engine initialization: migration, console/test modes, configuration wizard and engine construction.
#include "cpp_exception_metadata.hpp"
#include "game_entry.hpp"
#include "object_support.hpp"
#include "container_support.hpp"
#include "launch_runtime.hpp"
#include <windows.h>
#include <malloc.h>
#include <new>

class FConfigCache;
class FFileManager;
class FOutputDevice;
class FExec;
class FArchive;
class WConfigWizard;
class WWizardPage;
class WConfigPageSafeMode;
class WConfigPageRenderer;
extern FConfigCache *GConfig;
extern FFileManager *GFileManager;
extern FOutputDevice *GLog, *GNull;
extern FExec *GExec;
extern int32_t GIsEditor, GIsClient, GUnicodeOS;
extern const uint16_t *__cdecl appCmdLine();
extern int32_t __cdecl ParseParam(const uint16_t *text, const uint16_t *parameter);
extern int32_t __cdecl Parse(const uint16_t *text, const uint16_t *match, FString &result);
extern const uint16_t *__cdecl appStrfind(const uint16_t *text, const uint16_t *match);
extern int32_t __cdecl appAtoi(const uint16_t *text);
extern int32_t __cdecl appStricmp(const uint16_t *left, const uint16_t *right);
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *destination, const uint16_t *text, int32_t count);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern void __cdecl RequestStartupDialogQuit();
extern void __cdecl InitializeStartupDialog(const uint16_t *filename);
extern const char16_t g_configEmptyString[];
extern const char16_t g_rendererDescriptionFlagsKey[];
extern const char16_t g_rendererDetectionFile[];
extern const char16_t g_launcherStartupPackage[];
extern const char16_t g_rendererEngineSection[];
extern const char16_t g_rendererRenderDeviceKey[];
extern const char16_t g_rendererDirect3DClass[];
extern const char16_t g_winMainRunningIni[];
extern const char16_t g_winMainChangeVideo[];
extern double __cdecl ReadTimestampSeconds(); // Native ST0 retains extended precision until spilled.

// RavenShield.exe data @ 10940604 : g_initEngineExecHookGuard
uint32_t g_initEngineExecHookGuard = 0; // Bit zero is set before construction, without rollback or locking.
// RavenShield.exe data @ 10917874 : g_initEngineMutexName
const char16_t g_initEngineMutexName[] = u"UnrealIsRunning";
// RavenShield.exe data @ 10917860 : g_initEngineFirstRunKey
const char16_t g_initEngineFirstRunKey[] = u"FirstRun";
// RavenShield.exe data @ 10917844 : g_initEngineSaveMask
const char16_t g_initEngineSaveMask[] = u"..\\Save\\*.usa";
// RavenShield.exe data @ 1091780c : g_initEngineSlotSection
const char16_t g_initEngineSlotSection[] = u"UnrealShare.UnrealSlotMenu";
// RavenShield.exe data @ 109177f0 : g_initEngineSlotKeyFormat
const char16_t g_initEngineSlotKeyFormat[] = u"SlotNames[%i]";
// RavenShield.exe data @ 109177e4 : g_initEngineUserFile
const char16_t g_initEngineUserFile[] = u"user";
// RavenShield.exe data @ 109177cc : g_initEngineSavedGameLabel
const char16_t g_initEngineSavedGameLabel[] = u"Saved game";
// RavenShield.exe data @ 109177ac : g_initEngineConsoleKey
const char16_t g_initEngineConsoleKey[] = u"consolecommand=";
// RavenShield.exe data @ 10917770 : g_initEngineConsoleMessage
const char16_t g_initEngineConsoleMessage[] = u"Executing console command %s";
// RavenShield.exe data @ 10917758 : g_initEngineRenderTestKey
const char16_t g_initEngineRenderTestKey[] = u"testrendev=";
// RavenShield.exe data @ 1091773c : g_initEngineDetectingMessage
const char16_t g_initEngineDetectingMessage[] = u"Detecting %s";
// RavenShield.exe data @ 10917708 : g_initEngineDetectedMessage
const char16_t g_initEngineDetectedMessage[] = u"Successfully detected %s";
// RavenShield.exe data @ 109176fc : g_initEngineSafeParameter
const char16_t g_initEngineSafeParameter[] = u"safe";
// RavenShield.exe data @ 109176ec : g_initEngineReadIniParameter
const char16_t g_initEngineReadIniParameter[] = u"readini";
// RavenShield.exe data @ 109176d8 : g_initEngineSafeTitleKey
const char16_t g_initEngineSafeTitleKey[] = u"SafeMode";
// RavenShield.exe data @ 109176b4 : g_initEngineVideoTitleKey
const char16_t g_initEngineVideoTitleKey[] = u"Video";
// RavenShield.exe data @ 109176a0 : g_initEngineConfigGuardName
const char16_t g_initEngineConfigGuardName[] = u"ConfigUI";
// RavenShield.exe data @ 1091764c : g_initEngineGameEngineClass
const char16_t g_initEngineGameEngineClass[] = u"ini:Engine.Engine.GameEngine";
// RavenShield.exe data @ 1091760c : g_initEngineEditorEngineClass
const char16_t g_initEngineEditorEngineClass[] = u"ini:Engine.Engine.EditorEngine";
// RavenShield.exe data @ 109175f4 : g_initEngineFromEditorParameter
const char16_t g_initEngineFromEditorParameter[] = u"FROMEDITOR";
// RavenShield.exe data @ 109175c0 : g_initEngineStartupMessage
const char16_t g_initEngineStartupMessage[] = u"Startup time: %f seconds";
// RavenShield.exe data @ 109175a8 : g_initEngineGuardName
const char16_t g_initEngineGuardName[] = u"InitEngine";

// RavenShield.exe @ 1090ce00 : InitEngine
// Migrate old save labels, handle special modes, run the optional wizard and initialize the selected engine.
UEngine *__cdecl InitEngine()
{
  const auto slot = [](const void *object, uint32_t offset)
  { return *reinterpret_cast<const uint32_t *>(*reinterpret_cast<const uint32_t *>(object) + offset); };
  // Bind import slots without reading targets before the native guard.
  const auto &logf = *reinterpret_cast<void(__cdecl **)(FOutputDevice *, const uint16_t *, ...)>(
      NativeAddress(NativeImport_FOutputDeviceLogf));
  const auto &enumName =
      *reinterpret_cast<void(__thiscall **)(uint32_t *, int32_t)>(NativeAddress(NativeImport_FNameConstructEnum));
  const auto &localize =
      *reinterpret_cast<const uint16_t *(__cdecl **)(const uint16_t *, const uint16_t *, const uint16_t *)>(
          NativeAddress(NativeImport_LocalizeGeneralWide));
  // Source-only virtual accessors preserve the known slots without inventing a complete FConfigCache declaration.
  const auto setString =
      [&slot](const uint16_t *section, const uint16_t *key, const uint16_t *value, const uint16_t *filename)
  {
    FConfigCache *receiver = GConfig;
    FConfigCache *config = GConfig;
    reinterpret_cast<void(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *,
                                        const uint16_t *)>(slot(config, 0x30))(receiver, section, key, value, filename);
  };
  const auto setInt = [&slot](const uint16_t *section, const uint16_t *key, int32_t value)
  {
    FConfigCache *receiver = GConfig;
    FConfigCache *config = GConfig;
    reinterpret_cast<void(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, int32_t, const uint16_t *)>(
        slot(config, 0x28))(receiver, section, key, value, nullptr);
  };
  const auto createWriter = [&slot](const uint16_t *filename)
  {
    FOutputDevice *error = GNull; // Imported pointer variable, sampled before the current manager.
    FFileManager *receiver = GFileManager;
    FFileManager *manager = GFileManager;
    return reinterpret_cast<FArchive *(__thiscall *)(FFileManager *, const uint16_t *, uint32_t, FOutputDevice *)>(
        slot(manager, 8))(receiver, filename, 0, error);
  };
  try
  {
    const double startTime = ReadTimestampSeconds();
    if ((g_initEngineExecHookGuard & 1u) == 0)
    {
      g_initEngineExecHookGuard |= 1u;
      ConstructLaunchExecHookInline(); // No atexit registration, partial-base unwind or guard reset.
    }
    GExec = reinterpret_cast<FExec *>(g_launchExecHookStorage);
    HANDLE mutex;
    if (GUnicodeOS)
    {
      mutex = CreateMutexW(nullptr, 0, reinterpret_cast<const wchar_t *>(g_initEngineMutexName));
    }
    else
    {
      const auto *name = reinterpret_cast<const uint16_t *>(g_initEngineMutexName);
      char *buffer = nullptr;
      if (winGetSizeANSI(name))
      {
        const uint32_t size = static_cast<uint32_t>(winGetSizeANSI(name));
        buffer = static_cast<char *>(_alloca((((size + 7u) & ~7u) + 3u) & ~3u));
      }
      const int32_t count = winGetSizeANSI(name);
      mutex = CreateMutexA(nullptr, 0, winToANSI(buffer, name, count));
    }
    const int32_t alreadyRunning = GetLastError() == ERROR_ALREADY_EXISTS;
    // Native stores both locals but never tests them again, closes the handle or rejects another instance.
    int32_t firstRun = 0;
    FConfigCache *receiver = GConfig;
    FConfigCache *config = GConfig;
    reinterpret_cast<int32_t(__thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, int32_t *,
                                           const uint16_t *)>(slot(config, 4))(
        receiver, reinterpret_cast<const uint16_t *>(g_initEngineFirstRunKey),
        reinterpret_cast<const uint16_t *>(g_initEngineFirstRunKey), &firstRun, nullptr);
    if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineFirstRunKey))) firstRun = 0;
    if (firstRun < 220)
    {
      FFileManager *managerReceiver = GFileManager;
      FFileManager *manager = GFileManager;
      const auto findFiles =
          reinterpret_cast<TArray<FString>(__thiscall *)(FFileManager *, const uint16_t *, int32_t, int32_t)>(
              slot(manager, 0x2c));
      TArray<FString> files =
          findFiles(managerReceiver, reinterpret_cast<const uint16_t *>(g_initEngineSaveMask), 1,
                    0); // Native hidden result constructs EBP-50 directly; there is no preceding default construction.
      for (TArray<FString>::TIterator file(files); file; ++file)
      {
        const int32_t index = appAtoi(**file + 4); // Native skips four UTF-16 units without validating the filename.
        FString section(reinterpret_cast<const uint16_t *>(g_initEngineSlotSection));
        FString key = FString::Printf(reinterpret_cast<const uint16_t *>(g_initEngineSlotKeyFormat), index);
        const uint16_t *keyText = *key;
        const uint16_t *sectionText = *section;
        receiver = GConfig;
        config = GConfig;
        const auto getStr = reinterpret_cast<const uint16_t *(
            __thiscall *)(FConfigCache *, const uint16_t *, const uint16_t *, const uint16_t *)>(slot(config, 0x14));
        const uint16_t *value =
            getStr(receiver, sectionText, keyText, reinterpret_cast<const uint16_t *>(g_initEngineUserFile));
        if (appStricmp(value, reinterpret_cast<const uint16_t *>(g_configEmptyString)) == 0)
        {
          keyText = *key;
          sectionText = *section;
          setString(sectionText, keyText, reinterpret_cast<const uint16_t *>(g_initEngineSavedGameLabel),
                    reinterpret_cast<const uint16_t *>(g_initEngineUserFile));
        }
      } // Key, section and finally the returned array are destroyed in that order.
    }
    FString consoleCommand;
    if (Parse(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineConsoleKey), consoleCommand))
    {
      const uint16_t *text = *consoleCommand;
      logf(GLog, reinterpret_cast<const uint16_t *>(g_initEngineConsoleMessage), text);
      text = *consoleCommand;
      FOutputDevice *output = GLog;
      FExec *execReceiver = GExec;
      FExec *exec = GExec;
      reinterpret_cast<int32_t(__thiscall *)(FExec *, const uint16_t *, FOutputDevice *)>(slot(exec, 0))(execReceiver,
                                                                                                         text, output);
      return nullptr;
    }
    FString renderName;
    if (Parse(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineRenderTestKey), renderName))
    {
      const uint16_t *text = *renderName;
      logf(GLog, reinterpret_cast<const uint16_t *>(g_initEngineDetectingMessage), text);
      try
      {
        UClass *type = LoadRenderDeviceClass(nullptr, *renderName, nullptr, 0, nullptr);
        text = *renderName;
        setInt(text, reinterpret_cast<const uint16_t *>(g_rendererDescriptionFlagsKey), 2);
        receiver = GConfig;
        config = GConfig;
        reinterpret_cast<void(__thiscall *)(FConfigCache *, int32_t, const uint16_t *)>(slot(config, 0x34))(receiver, 0,
                                                                                                            nullptr);
        if (type)
        {
          uint32_t nameWord;
          enumName(&nameWord, 0);
          URenderDevice *device = ConstructRenderDevice(type, reinterpret_cast<UObject *>(0xffffffffu), nameWord, 0);
          if (device)
          {
            const int32_t initialized =
                reinterpret_cast<int32_t(__thiscall *)(URenderDevice *)>(slot(device, 0x68))(device);
            if (initialized)
            {
              text = *renderName;
              logf(GLog, reinterpret_cast<const uint16_t *>(g_initEngineDetectedMessage), text);
            }
            else
            {
              if (device)
                reinterpret_cast<URenderDevice *(__thiscall *)(URenderDevice *, uint32_t)>(slot(device, 0xc))(device,
                                                                                                              1);
              device = nullptr;
            }
          } // A successful device is retained; no exception cleanup action owns this pointer.
        }
      }
      // RavenShield.exe @ 1090d454 : IgnoreRenderDetectionFailure
      // Silently continue at 1090d45a after any renderer-probe exception, with both strings still live.
      catch (...)
      {
      }
      FArchive *marker = createWriter(reinterpret_cast<const uint16_t *>(g_rendererDetectionFile));
      if (marker && marker)
        reinterpret_cast<FArchive *(__thiscall *)(FArchive *, uint32_t)>(slot(marker, 0))(marker, 1);
      return nullptr;
    }
    bool cancelled = false;
    try
    {
      if (!GIsEditor && GIsClient)
      {
        WConfigWizard wizard; // Native EBP-3e8; Title at +350 (EBP-98), complete extent 35c.
        WWizardPage *page = nullptr;
        if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineSafeParameter)) ||
            appStrfind(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineReadIniParameter)))
        {
          auto *storage = static_cast<WConfigPageSafeMode *>(AllocateExecutableBytes(0x2b4));
          try
          {
            if (storage) page = new (storage) WConfigPageSafeMode(&wizard);
          }
          catch (...)
          {
            FreeExecutableAllocation(storage);
            throw;
          }
          wizard.Title = localize(reinterpret_cast<const uint16_t *>(g_initEngineSafeTitleKey),
                                  reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
        }
        else if (firstRun < 927)
        {
          setString(reinterpret_cast<const uint16_t *>(g_rendererEngineSection),
                    reinterpret_cast<const uint16_t *>(g_rendererRenderDeviceKey),
                    reinterpret_cast<const uint16_t *>(g_rendererDirect3DClass), nullptr);
        }
        else if (ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_winMainChangeVideo)))
        {
          auto *storage = static_cast<WConfigPageRenderer *>(AllocateExecutableBytes(0x248));
          try
          {
            if (storage) page = new (storage) WConfigPageRenderer(&wizard);
          }
          catch (...)
          {
            FreeExecutableAllocation(storage);
            throw;
          }
          wizard.Title = localize(reinterpret_cast<const uint16_t *>(g_initEngineVideoTitleKey),
                                  reinterpret_cast<const uint16_t *>(g_launcherStartupPackage), nullptr);
        }
        if (page)
        {
          RequestStartupDialogQuit();
          const auto advance = *reinterpret_cast<void(__thiscall **)(WConfigWizard *, WWizardPage *)>(
              NativeAddress(NativeImport_WWizardDialog_Advance));
          advance(&wizard, page);
          HINSTANCE instance =
              **reinterpret_cast<HINSTANCE **>(NativeAddress(NativeImport_HINSTANCE___hInstanceWindow));
          const auto doModal = *reinterpret_cast<int32_t(__thiscall **)(WConfigWizard *, HINSTANCE)>(
              NativeAddress(NativeImport_WDialog_DoModal));
          if (doModal(&wizard, instance) == 0)
            cancelled = true;
          else
            InitializeStartupDialog(nullptr);
        }
      } // Destroy the wizard within ConfigUI; do not give successfully constructed pages a new rollback owner.
    }
    // RavenShield.exe @ 1090d815 : RethrowConfigUIPointer
    // Copy-throw the caught UTF-16 pointer from parent EBP-3ec through EBP-424.
    catch (uint16_t *error)
    {
      throw error;
    }
    // RavenShield.exe @ 1090d832 : UnwindConfigUIFailure
    // Annotate configuration failure after wizard/construction cleanup, then propagate to the outer guard.
    catch (...)
    {
      appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
                 reinterpret_cast<const uint16_t *>(g_initEngineConfigGuardName));
      throw;
    }
    if (cancelled) return nullptr; // Outer strings are destroyed outside the ConfigUI guard.
    FArchive *marker = createWriter(reinterpret_cast<const uint16_t *>(g_winMainRunningIni));
    if (marker && marker) reinterpret_cast<FArchive *(__thiscall *)(FArchive *, uint32_t)>(slot(marker, 0))(marker, 1);
    if (firstRun < 927) firstRun = 927;
    setInt(reinterpret_cast<const uint16_t *>(g_initEngineFirstRunKey),
           reinterpret_cast<const uint16_t *>(g_initEngineFirstRunKey), firstRun);
    const auto &loadClass =
        *reinterpret_cast<UClass *(__cdecl **)(UClass *, UObject *, const uint16_t *, const uint16_t *, uint32_t,
                                               UPackageMap *)>(NativeAddress(NativeImport_UObject_StaticLoadClass));
    UClass *type;
    if (!GIsEditor)
    {
      const auto gameEngineClass =
          *reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UGameEngine_StaticClass));
      UClass *base = gameEngineClass();
      type = loadClass(base, nullptr, reinterpret_cast<const uint16_t *>(g_initEngineGameEngineClass), nullptr, 1,
                       nullptr);
    }
    else
    {
      const auto engineClass =
          *reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UEngine_StaticClass));
      UClass *base = engineClass();
      type = loadClass(base, nullptr, reinterpret_cast<const uint16_t *>(g_initEngineEditorEngineClass), nullptr, 1,
                       nullptr);
    }
    uint32_t nameWord;
    enumName(&nameWord, 0);
    UEngine *engine = ConstructEngine(type, reinterpret_cast<UObject *>(0xffffffffu), nameWord, 0);
    const uint32_t fromEditor = static_cast<uint32_t>(
        ParseParam(appCmdLine(), reinterpret_cast<const uint16_t *>(g_initEngineFromEditorParameter)));
    auto &flags = *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(engine) + 0x120);
    flags = (flags & ~0x1000u) | ((fromEditor & 1u) << 12); // Preserve the low bit, not a truth-normalized result.
    reinterpret_cast<void(__thiscall *)(UEngine *)>(slot(engine, 0x70))(engine); // No null-engine guard.
    double elapsed;
    __asm {
      call ReadTimestampSeconds
      fsub qword ptr [startTime]
      fstp qword ptr [elapsed]
    }
    logf(GLog, reinterpret_cast<const uint16_t *>(g_initEngineStartupMessage), elapsed);
    return engine;
  }
  // RavenShield.exe @ 1090da6a : RethrowInitEnginePointer
  // Copy-throw the caught UTF-16 pointer from parent EBP-3f0 through EBP-438.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090da87 : UnwindInitEngineFailure
  // Annotate engine-initialization failure after the applicable string cleanup, then rethrow.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_initEngineGuardName));
    throw;
  }
} // Native plain RET returns the complete UEngine pointer in EAX.

// RavenShield.exe @ 10912a50 : DestroyInitEngineSaveFiles
// Destroy the returned save-file array at parent EBP-50.
__declspec(naked) void DestroyInitEngineSaveFiles()
{
  __asm {
    lea ecx, [ebp-50h]
    jmp TArray<FString>::~TArray
  }
}

// RavenShield.exe @ 10912a58 : DestroyInitEngineSlotSection
// Destroy the slot-menu section string at parent EBP-64.
__declspec(naked) void DestroyInitEngineSlotSection()
{
  __asm {
    lea ecx, [ebp-64h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912a61 : DestroyInitEngineSlotKey
// Destroy the formatted slot key at parent EBP-70.
__declspec(naked) void DestroyInitEngineSlotKey()
{
  __asm {
    lea ecx, [ebp-70h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912a6a : DestroyInitEngineConsoleCommand
// Destroy the console-command string at parent EBP-28.
__declspec(naked) void DestroyInitEngineConsoleCommand()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912a73 : DestroyInitEngineRenderName
// Destroy the renderer-name string at parent EBP-44.
__declspec(naked) void DestroyInitEngineRenderName()
{
  __asm {
    lea ecx, [ebp-44h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912a7c : DestroyInitEngineWizard
// Destroy the completed configuration wizard at parent EBP-3e8.
__declspec(naked) void DestroyInitEngineWizard()
{
  __asm {
    lea ecx, [ebp-3e8h]
    jmp WConfigWizard::~WConfigWizard
  }
}

// RavenShield.exe @ 10912a87 : FreeInitEngineSafePageStorage
// Free parent EBP-414 raw page storage only if its placement constructor throws.
__declspec(naked) void FreeInitEngineSafePageStorage()
{
  __asm {
    mov eax, [ebp-414h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe @ 10912a95 : FreeInitEngineRendererPageStorage
// Free parent EBP-41c raw page storage only if its placement constructor throws.
__declspec(naked) void FreeInitEngineRendererPageStorage()
{
  __asm {
    mov eax, [ebp-41ch]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 10919f98 : g_initEngineUnwind
const NativeCppUnwindEntry g_initEngineUnwind[14] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_DestroyInitEngineSaveFiles)},      // DestroyInitEngineSaveFiles
    {1, NativeAddress(NativeEntry_DestroyInitEngineSlotSection)},    // DestroyInitEngineSlotSection
    {2, NativeAddress(NativeEntry_DestroyInitEngineSlotKey)},        // DestroyInitEngineSlotKey
    {0, NativeAddress(NativeEntry_DestroyInitEngineConsoleCommand)}, // DestroyInitEngineConsoleCommand
    {4, NativeAddress(NativeEntry_DestroyInitEngineRenderName)},     // DestroyInitEngineRenderName
    {5, 0},
    {5, 0},
    {5, 0},
    {8, NativeAddress(NativeEntry_DestroyInitEngineWizard)},           // DestroyInitEngineWizard
    {9, NativeAddress(NativeEntry_FreeInitEngineSafePageStorage)},     // FreeInitEngineSafePageStorage
    {9, NativeAddress(NativeEntry_FreeInitEngineRendererPageStorage)}, // FreeInitEngineRendererPageStorage
    {5, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a008 : g_initEngineRenderDetectionCatches
const NativeCppCatchHandler g_initEngineRenderDetectionCatches[1] = {
    {0, 0, 0, 0x1090d454}, // IgnoreRenderDetectionFailure
};

// RavenShield.exe data @ 1091a018 : g_initEngineConfigUICatches
const NativeCppCatchHandler g_initEngineConfigUICatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x3ec, 0x1090d815}, // RethrowConfigUIPointer
    {0, 0, 0, 0x1090d832},                                                // UnwindConfigUIFailure
};

// RavenShield.exe data @ 1091a038 : g_initEngineInitializationCatches
const NativeCppCatchHandler g_initEngineInitializationCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x3f0, 0x1090da6a}, // RethrowInitEnginePointer
    {0, 0, 0, 0x1090da87},                                                // UnwindInitEngineFailure
};

// RavenShield.exe data @ 1091a058 : g_initEngineTryBlocks
const NativeCppTryBlock g_initEngineTryBlocks[3] = {
    {6, 6, 7, 1, NativeAddress(g_initEngineRenderDetectionCatches)},
    {8, 11, 12, 2, NativeAddress(g_initEngineConfigUICatches)},
    {0, 12, 13, 2, NativeAddress(g_initEngineInitializationCatches)},
};

// RavenShield.exe data @ 1091a094 : g_initEngineExceptionInfo
const NativeCppFunctionInfo g_initEngineExceptionInfo = {
    0x19930520, 14, NativeAddress(g_initEngineUnwind), 3, NativeAddress(g_initEngineTryBlocks), 0, 0};

// RavenShield.exe @ 10912aa3 : HandleInitEngineException
// Dispatch InitEngine's migration/strings/wizard cleanup, silent renderer catch and two named guard scopes.
// FuncInfo 1091a094: 14 states, unwind 10919f98, three tries at 1091a058; saved ESP is parent EBP-10.
// Predecessors/actions: 0(-1,none), 1(0,12a50), 2(1,12a58), 3(2,12a61), 4(0,12a6a), 5(4,12a73),
// 6(5,none), 7(5,none), 8(5,none), 9(8,12a7c), 10(9,12a87), 11(9,12a95), 12(5,none), 13(-1,none).
// Try 6..6/catch-state 7: catch-all 1090d454. Try 8..11/catch-state 12: pointer/all 1090d815/1090d832.
// Try 0..12/catch-state 13: pointer/all 1090da6a/1090da87. Pointer catches use type 1091f0c0, throw-info 10918618.
__declspec(naked) void HandleInitEngineException()
{
  __asm {
    mov eax, offset g_initEngineExceptionInfo
    jmp DispatchExecutableCppException
  }
}
