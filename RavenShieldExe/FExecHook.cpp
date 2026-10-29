#include "native_symbols.hpp"
// Launcher execution commands and notification through the secondary FNotifyHook base.
#include "cpp_exception_metadata.hpp"
#include "exec_hook_support.hpp"
#include "object_support.hpp"
#include "container_support.hpp"
#include "launcher_math.hpp"
#include "launch_runtime.hpp"
#include <windows.h>

class FExecHook;
class UViewport;
class ULevel;
class ALevelInfo;
class UExporter;
class FObjectsItem;
class WWindow;
class FNotifyHook;
class FOutputDevice;
class FStringOutputDevice;
class WLog;
extern WLog *GLogWindow; // Window.dll imported data; each native use reloads the current window.
extern int32_t GIsClient;
extern const char16_t g_configEmptyString[];
extern const char16_t g_errorWindowPackage[];
extern void __cdecl appUnwindf(const uint16_t *format, ...);

// RavenShield.exe data @ 109405f8 : g_launchExecHookStorage
alignas(4) uint8_t g_launchExecHookStorage[12] = {}; // FExec, FNotifyHook, Preferences words.
// RavenShield.exe data @ 10914c34 : g_execHookNotifyVtable
const uint32_t g_execHookNotifyVtable[] = {
    NativeAddress(NativeEntry_FExecHook_NotifyDestroy), NativeAddress(NativeEntry_FNotifyHook_NotifyPreChange),
    NativeAddress(NativeEntry_FNotifyHook_NotifyPostChange), NativeAddress(NativeEntry_FNotifyHook_NotifyExec)};
// RavenShield.exe data @ 10914c44 : g_execHookExecVtable
const uint32_t g_execHookExecVtable[] = {NativeAddress(NativeEntry_FExecHook_Exec)};

// RavenShield.exe data @ 10914c48 : g_execHookNoPlayerDistance
extern const double g_execHookNoPlayerDistance = 0.0;
// RavenShield.exe data @ 109161bc : g_execHookGuardName
const char16_t g_execHookGuardName[] = u"FExecHook::Exec";
// RavenShield.exe data @ 109162e4 : g_execHookPreferencesTitleKey
const char g_execHookPreferencesTitleKey[] = "AdvancedOptionsTitle";
// RavenShield.exe data @ 109162fc : g_execHookPreferencesCommand
const char16_t g_execHookPreferencesCommand[] = u"Preferences";
// RavenShield.exe data @ 10916314 : g_execHookHideLogCommand
const char16_t g_execHookHideLogCommand[] = u"HideLog";
// RavenShield.exe data @ 10916324 : g_execHookMissingClassMessage
const char16_t g_execHookMissingClassMessage[] = u"Missing class";
// RavenShield.exe data @ 10916340 : g_execHookActorNotFoundMessage
const char16_t g_execHookActorNotFoundMessage[] = u"Actor not found";
// RavenShield.exe data @ 10916360 : g_execHookExportType
const char16_t g_execHookExportType[] = u"T3D";
// RavenShield.exe data @ 10916368 : g_execHookCopyCommand
const char16_t g_execHookCopyCommand[] = u"CopyToClipboard";
// RavenShield.exe data @ 10916388 : g_execHookTargetNotFoundMessage
const char16_t g_execHookTargetNotFoundMessage[] = u"Target not found";
// RavenShield.exe data @ 109164b4 : g_execHookActorKey
const char16_t g_execHookActorKey[] = u"Actor=";
// RavenShield.exe data @ 109164c4 : g_execHookDefaultsCommand
const char16_t g_execHookDefaultsCommand[] = u"Defaults";
// RavenShield.exe data @ 109164d8 : g_execHookClassKey
const char16_t g_execHookClassKey[] = u"Class=";
// RavenShield.exe data @ 109164e8 : g_execHookEditCommand
const char16_t g_execHookEditCommand[] = u"EditActor";
// RavenShield.exe data @ 109164fc : g_execHookTakeFocusCommand
const char16_t g_execHookTakeFocusCommand[] = u"TakeFocus";
// RavenShield.exe data @ 10916510 : g_execHookShowLogCommand
const char16_t g_execHookShowLogCommand[] = u"ShowLog";

// Source helper for the native inlined InitEngine sequence: construct both bases, then publish tables/preferences.
void ConstructLaunchExecHookInline()
{
  const auto execBase = *reinterpret_cast<ImportedBaseConstructor *>(NativeAddress(NativeImport_FExecConstruct));
  execBase(g_launchExecHookStorage);
  const auto notifyBase =
      *reinterpret_cast<ImportedBaseConstructor *>(NativeAddress(NativeImport_FNotifyHookConstruct));
  notifyBase(g_launchExecHookStorage + 4);
  *reinterpret_cast<const uint32_t **>(g_launchExecHookStorage) = g_execHookExecVtable;
  *reinterpret_cast<const uint32_t **>(g_launchExecHookStorage + 4) = g_execHookNotifyVtable;
  *reinterpret_cast<uint32_t *>(g_launchExecHookStorage + 8) = 0;
}

// RavenShield.exe @ 109028d0 : FExecHook::NotifyDestroy
// Clear Preferences only when the destroyed source equals the stored window, without destroying it again.
// Native ECX is complete FExecHook +4, so Preferences is +4 from this adjusted receiver (+8 from the complete object).
void FExecHook::NotifyDestroy(void *source)
{
  void *&preferences = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(this) + 4);
  if (source == preferences) preferences = nullptr;
} // Native RET 4; this reference definition explicitly retains the adjusted-receiver entry contract.

// RavenShield.exe @ 10908150 : FExecHook::Exec
// Handle launcher log/focus, actor editing/export and preferences commands, returning full-width handled status.
int32_t FExecHook::Exec(const uint16_t *command, FOutputDevice &output)
{
  // Bind import slots without reading them until each guarded call evaluates its target.
  const auto &parseCommand = *reinterpret_cast<int32_t(__cdecl **)(const uint16_t **, const uint16_t *)>(
      NativeAddress(NativeImport_ParseCommand));
  const auto &getWindow = *reinterpret_cast<HWND(__thiscall **)(void *)>(NativeAddress(NativeImport_HWND));
  const auto &getLevel =
      *reinterpret_cast<ULevel *(__thiscall **)(const AActor *)>(NativeAddress(NativeImport_AActor_GetLevel));
  const auto &getLevelInfo =
      *reinterpret_cast<ALevelInfo *(__thiscall **)(ULevel *)>(NativeAddress(NativeImport_ULevel_GetLevelInfo));
  const auto &getDefault =
      *reinterpret_cast<UObject *(__thiscall **)(UClass *)>(NativeAddress(NativeImport_UClass_GetDefaultObject));
  const auto &isA =
      *reinterpret_cast<int32_t(__thiscall **)(const UObject *, UClass *)>(NativeAddress(NativeImport_UObject_IsA));
  const auto &getName =
      *reinterpret_cast<const uint16_t *(__thiscall **)(const UObject *)>(NativeAddress(NativeImport_UObject_GetName));
  const auto &logf = *reinterpret_cast<void(__cdecl **)(FOutputDevice *, const uint16_t *, ...)>(
      NativeAddress(NativeImport_FOutputDeviceLogf));
  const auto &constructName = *reinterpret_cast<void(__thiscall **)(uint32_t *, const uint16_t *, int32_t)>(
      NativeAddress(NativeImport_FNameConstructText));
  const auto &openProperties =
      *reinterpret_cast<void(__thiscall **)(void *, HWND)>(NativeAddress(NativeImport_WProperties_OpenWindow));
  // These source-only accessors expose native offsets without inventing complete engine/window declarations.
  const auto client = [](UEngine *engine)
  { return *reinterpret_cast<uint8_t **>(reinterpret_cast<uint8_t *>(engine) + 0x44); };
  const auto viewports = [&client](UEngine *engine) -> TArray<UViewport *> &
  { return *reinterpret_cast<TArray<UViewport *> *>(client(engine) + 0x30); };
  const auto show = [](auto &window, int32_t visible)
  {
    auto *receiver = window;
    auto *dispatchWindow = window;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchWindow);
    const auto invoke = *reinterpret_cast<void(__thiscall **)(void *, int32_t)>(table + 8);
    invoke(receiver, visible);
  };
  const auto viewportWindow = [](UViewport *viewport)
  {
    const uint32_t table = *reinterpret_cast<const uint32_t *>(viewport);
    const auto invoke = *reinterpret_cast<HWND(__thiscall **)(UViewport *)>(table + 0x94);
    return invoke(viewport);
  };
  try
  {
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookShowLogCommand)))
    {
      if (GLogWindow)
      {
        show(GLogWindow, 1);
        SetFocus(getWindow(GLogWindow));
        const auto scrollCaret =
            *reinterpret_cast<void(__thiscall **)(void *)>(NativeAddress(NativeImport_WEdit_ScrollCaret));
        scrollCaret(reinterpret_cast<uint8_t *>(GLogWindow) + 0x40);
      }
      return 1;
    }
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookTakeFocusCommand)))
    {
      TObjectIterator<UEngine> engines;
      if (engines && client(*engines) && viewports(*engines).Num())
      {
        SetForegroundWindow(viewportWindow(viewports(*engines)(0)));
      }
      return 1;
    }
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookEditCommand)))
    {
      TObjectIterator<UEngine> engines;
      if (engines)
      {
        AActor *player = nullptr;
        if (client(*engines) && viewports(*engines)(0))
          player = *reinterpret_cast<AActor **>(reinterpret_cast<uint8_t *>(viewports(*engines)(0)) + 0x34);
        ALevelInfo *levelInfo = nullptr;
        if (player && getLevel(player)) levelInfo = getLevelInfo(getLevel(player));
        if (levelInfo && *(reinterpret_cast<const uint8_t *>(levelInfo) + 0x425) != 0) return 1;
      }
      UObject *found = nullptr;
      if (engines)
      {
        UClass *type;
        if (ParseClass(command, reinterpret_cast<const uint16_t *>(g_execHookClassKey), type,
                       reinterpret_cast<UObject *>(0xffffffffu)))
        {
          if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookDefaultsCommand)))
          {
            found = getDefault(type);
          }
          else
          {
            AActor *player = nullptr;
            if (client(*engines))
              player = *reinterpret_cast<AActor **>(reinterpret_cast<uint8_t *>(viewports(*engines)(0)) + 0x34);
            float minimumDistance = 999999.0f;
            for (TObjectIterator<AActor> actors; actors; ++actors)
            {
              const float distance =
                  player ? FDist(*reinterpret_cast<const FVector *>(reinterpret_cast<const uint8_t *>(*actors) + 0x234),
                                 *reinterpret_cast<const FVector *>(reinterpret_cast<const uint8_t *>(player) + 0x234))
                         : static_cast<float>(g_execHookNoPlayerDistance);
              if (player)
              {
                ULevel *actorLevel = getLevel(*actors);
                ULevel *playerLevel = getLevel(player);
                if (actorLevel != playerLevel) continue;
              }
              const uint32_t actorFlags =
                  *reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(*actors) + 0xa0);
              if ((actorFlags & 0x80) != 0) continue; // bDeleteMe; keep the native packed-word test.
              if (isA(reinterpret_cast<UObject *>(*actors), type) && distance < minimumDistance)
              {
                minimumDistance = distance;
                found = reinterpret_cast<UObject *>(*actors);
              }
            }
          }
        }
        else
        {
          uint32_t actorNameWord; // Native FName is one word, with no local destructor action.
          const auto defaultName =
              *reinterpret_cast<void(__thiscall **)(uint32_t *)>(NativeAddress(NativeImport_FNameConstructEmpty));
          defaultName(&actorNameWord);
          const auto parseName = *reinterpret_cast<int32_t(__cdecl **)(const uint16_t *, const uint16_t *, uint32_t *)>(
              NativeAddress(NativeImport_ParseName));
          if (parseName(command, reinterpret_cast<const uint16_t *>(g_execHookActorKey), &actorNameWord))
          {
            for (TObjectIterator<AActor> actors; actors; ++actors)
            {
              const uint32_t actorFlags =
                  *reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(*actors) + 0xa0);
              if ((actorFlags & 0x80) != 0) continue;
              const uint16_t *name = getName(reinterpret_cast<UObject *>(*actors));
              const auto nameText = *reinterpret_cast<const uint16_t *(__thiscall **)(const uint32_t *)>(
                  NativeAddress(NativeImport_FName_Dereference));
              if (name == nameText(&actorNameWord))
              { // Pointer identity, not a text comparison.
                found = reinterpret_cast<UObject *>(*actors);
                break;
              }
            }
          }
        }
        if (found)
        {
          auto *storage = static_cast<WObjectProperties *>(AllocateExecutableBytes(0x160));
          WObjectProperties *properties = nullptr;
          try
          {
            if (storage)
            {
              uint32_t nameWord;
              constructName(&nameWord, reinterpret_cast<const uint16_t *>(g_execHookEditCommand), 1);
              ConstructExecObjectPropertiesInline(storage, nameWord);
              properties = storage;
            }
          }
          catch (...)
          {
            FreeExecutableAllocation(storage);
            throw;
          }
          HWND owner = viewportWindow(viewports(*engines)(0));
          openProperties(properties, owner); // Null allocation still reaches these native calls.
          auto *root = reinterpret_cast<FObjectsItem *>(reinterpret_cast<uint32_t>(properties) + 0xfcu);
          const uint32_t table = *reinterpret_cast<const uint32_t *>(root);
          using SetRootObjects = void(__thiscall *)(FObjectsItem *, UObject **, int32_t);
          const auto setObjects = *reinterpret_cast<const SetRootObjects *>(table + 0x94);
          setObjects(root, &found, 1);
          show(properties, 1);
        }
        else
        {
          logf(&output, reinterpret_cast<const uint16_t *>(g_execHookTargetNotFoundMessage));
        }
      }
      return 1;
    }
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookCopyCommand)))
    {
      TObjectIterator<UEngine> engines;
      UClass *type;
      if (engines && ParseClass(command, reinterpret_cast<const uint16_t *>(g_execHookClassKey), type,
                                reinterpret_cast<UObject *>(0xffffffffu)))
      {
        UObject *found = nullptr;
        if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookDefaultsCommand)))
        {
          found = getDefault(type);
        }
        else
        {
          AActor *player = nullptr;
          if (client(*engines))
            player = *reinterpret_cast<AActor **>(reinterpret_cast<uint8_t *>(viewports(*engines)(0)) + 0x34);
          float minimumDistance = 999999.0f;
          for (TObjectIterator<AActor> actors; actors; ++actors)
          {
            const float distance =
                player ? FDist(*reinterpret_cast<const FVector *>(reinterpret_cast<const uint8_t *>(*actors) + 0x234),
                               *reinterpret_cast<const FVector *>(reinterpret_cast<const uint8_t *>(player) + 0x234))
                       : static_cast<float>(g_execHookNoPlayerDistance);
            if (player)
            {
              ULevel *actorLevel = getLevel(*actors);
              ULevel *playerLevel = getLevel(player);
              if (actorLevel != playerLevel) continue;
            }
            const uint32_t actorFlags =
                *reinterpret_cast<const uint32_t *>(reinterpret_cast<const uint8_t *>(*actors) + 0xa0);
            if ((actorFlags & 0x80) != 0) continue;
            if (isA(reinterpret_cast<UObject *>(*actors), type) && distance < minimumDistance)
            {
              minimumDistance = distance;
              found = reinterpret_cast<UObject *>(*actors);
            }
          }
        }
        if (found)
        {
          FStringOutputDevice text(reinterpret_cast<const uint16_t *>(g_configEmptyString));
          const auto &exportObject =
              *reinterpret_cast<void(__cdecl **)(UObject *, UExporter *, FOutputDevice &, const uint16_t *, int32_t)>(
                  NativeAddress(NativeImport_UExporter_ExportToOutputDevice));
          exportObject(found, nullptr, *reinterpret_cast<FOutputDevice *>(&text),
                       reinterpret_cast<const uint16_t *>(g_execHookExportType), 0);
          const auto stringText = *reinterpret_cast<const uint16_t *(__thiscall **)(const FString *)>(
              NativeAddress(NativeImport_FStringGetText));
          const uint16_t *contents =
              stringText(reinterpret_cast<const FString *>(reinterpret_cast<const uint8_t *>(&text) + 4));
          const auto clipboardCopy =
              *reinterpret_cast<void(__cdecl **)(const uint16_t *)>(NativeAddress(NativeImport_appClipboardCopy));
          clipboardCopy(contents);
        }
        else
        {
          logf(&output, reinterpret_cast<const uint16_t *>(g_execHookActorNotFoundMessage));
        }
      }
      else
      {
        logf(&output, reinterpret_cast<const uint16_t *>(g_execHookMissingClassMessage));
      }
      return 1;
    }
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookHideLogCommand)))
    {
      if (GLogWindow) show(GLogWindow, 0);
      return 1;
    }
    if (parseCommand(&command, reinterpret_cast<const uint16_t *>(g_execHookPreferencesCommand)) && GIsClient == 0)
    {
      auto *&preferences = *reinterpret_cast<WConfigProperties **>(reinterpret_cast<uint8_t *>(this) + 8);
      if (!preferences)
      {
        auto *storage = static_cast<WConfigProperties *>(AllocateExecutableBytes(0x164));
        WConfigProperties *properties = nullptr;
        try
        {
          if (storage)
          {
            const auto localize =
                *reinterpret_cast<const uint16_t *(__cdecl **)(const char *, const uint16_t *, const uint16_t *)>(
                    NativeAddress(NativeImport_LocalizeGeneralAnsi));
            const uint16_t *title = localize(g_execHookPreferencesTitleKey,
                                             reinterpret_cast<const uint16_t *>(g_errorWindowPackage), nullptr);
            uint32_t nameWord;
            constructName(&nameWord, reinterpret_cast<const uint16_t *>(g_execHookPreferencesCommand), 1);
            ConstructExecConfigPropertiesInline(storage, nameWord, title);
            properties = storage;
          }
        }
        catch (...)
        {
          FreeExecutableAllocation(storage);
          throw;
        }
        preferences = properties;
        FNotifyHook *notifyBase =
            this ? reinterpret_cast<FNotifyHook *>(reinterpret_cast<uint8_t *>(this) + 4) : nullptr;
        const auto &setNotifyHook = *reinterpret_cast<void(__thiscall **)(WWindow *, FNotifyHook *)>(
            NativeAddress(NativeImport_WWindow_SetNotifyHook));
        setNotifyHook(reinterpret_cast<WWindow *>(preferences), notifyBase);
        HWND owner = GLogWindow ? *reinterpret_cast<HWND *>(reinterpret_cast<uint8_t *>(GLogWindow) + 4) : nullptr;
        openProperties(preferences, owner);
        const uint32_t table = *reinterpret_cast<const uint32_t *>(preferences);
        const auto refresh = *reinterpret_cast<void(__thiscall **)(void *)>(table + 0xf8);
        refresh(preferences);
      }
      show(preferences, 1);
      SetFocus(getWindow(preferences));
      return 1;
    }
    return 0;
  }
  // RavenShield.exe @ 10908dea : RethrowExecHookPointer
  // Copy-throw the caught UTF-16 pointer from parent EBP-8c through EBP-a8.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10908e07 : UnwindExecHookFailure
  // Annotate the active exception after construction-only allocation or export-string cleanup, then rethrow.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_execHookGuardName));
    throw;
  }
} // Native ECX is the complete FExecHook/FExec base; RET 8 consumes command and output-reference words.

// RavenShield.exe @ 10912520 : FreeExecHookObjectPropertiesStorage
// Free the allocation at parent EBP-94 only while inline object-properties construction is active.
__declspec(naked) void FreeExecHookObjectPropertiesStorage()
{
  __asm {
    mov eax, [ebp-94h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe @ 1091252e : DestroyExecHookExportString
// Destroy the live string-output device at parent EBP-88 during export/clipboard failure.
__declspec(naked) void DestroyExecHookExportString()
{
  __asm {
    lea ecx, [ebp-88h]
    jmp FStringOutputDevice::~FStringOutputDevice
  }
}

// RavenShield.exe @ 10912539 : FreeExecHookConfigPropertiesStorage
// Free the allocation at parent EBP-a0 only while inline configuration-properties construction is active.
__declspec(naked) void FreeExecHookConfigPropertiesStorage()
{
  __asm {
    mov eax, [ebp-0a0h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 1091960c : g_execHookUnwind
const NativeCppUnwindEntry g_execHookUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_FreeExecHookObjectPropertiesStorage)}, // FreeExecHookObjectPropertiesStorage
    {0, NativeAddress(NativeEntry_DestroyExecHookExportString)},         // DestroyExecHookExportString
    {0, NativeAddress(NativeEntry_FreeExecHookConfigPropertiesStorage)}, // FreeExecHookConfigPropertiesStorage
    {-1, 0},
};

// RavenShield.exe data @ 10919634 : g_execHookCatches
const NativeCppCatchHandler g_execHookCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x8c, 0x10908dea}, // RethrowExecHookPointer
    {0, 0, 0, 0x10908e07},                                               // UnwindExecHookFailure
};

// RavenShield.exe data @ 10919654 : g_execHookTryBlocks
const NativeCppTryBlock g_execHookTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_execHookCatches)},
};

// RavenShield.exe data @ 10919668 : g_execHookExceptionInfo
const NativeCppFunctionInfo g_execHookExceptionInfo = {
    0x19930520, 5, NativeAddress(g_execHookUnwind), 1, NativeAddress(g_execHookTryBlocks), 0, 0};

// RavenShield.exe @ 10912547 : HandleExecHookException
// Supply Exec's five-state construction/export cleanup and typed/catch-all guard graph to shared dispatch.
__declspec(naked) void HandleExecHookException()
{
  __asm {
    mov eax, offset g_execHookExceptionInfo
    jmp DispatchExecutableCppException
  }
}
