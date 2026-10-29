#include "native_symbols.hpp"
// Original system-directory initialization, filename normalization and dormant imported CD-presence prompt loop.
#include "system_directory_support.hpp"
#include <malloc.h>

class FOutputDevice;
extern int32_t GUnicodeOS;
extern const char g_fileManagerEmptyAnsiUnit;
extern const char16_t g_allocatorErrorPackage[];
extern int32_t __cdecl winGetSizeUNICODE(const char *text);
extern uint16_t *__cdecl winToUNICODE(uint16_t *buffer, const char *text, int32_t count);
extern uint16_t *__cdecl appStrcpy(uint16_t *destination, const uint16_t *source);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern int32_t __cdecl appStricmp(const uint16_t *left, const uint16_t *right);
extern "C" uint32_t __stdcall GetSystemDirectoryW(uint16_t *path, uint32_t capacity);
extern "C" uint32_t __stdcall GetWindowsDirectoryW(uint16_t *path, uint32_t capacity);
extern "C" uint32_t __stdcall GetModuleFileNameW(uint32_t module, uint16_t *path, uint32_t capacity);
extern "C" uint32_t __stdcall GetSystemDirectoryA(char *path, uint32_t capacity);
extern "C" uint32_t __stdcall GetWindowsDirectoryA(char *path, uint32_t capacity);
extern "C" uint32_t __stdcall GetModuleFileNameA(uint32_t module, char *path, uint32_t capacity);
extern "C" int32_t __stdcall MessageBoxW(uint32_t window, const uint16_t *text, const uint16_t *caption,
                                         uint32_t flags);
using NativeLocalize = const uint16_t *(__cdecl *)(const uint16_t *, const uint16_t *, const uint16_t *,
                                                   const uint16_t *, int32_t, int32_t);
using NativeCDPresence = int32_t(__cdecl *)();
using NativeDirectoryErrorLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);

// RavenShield.exe data @ 1091f120 : g_systemDirectory
uint16_t g_systemDirectory[256] = {};
// RavenShield.exe data @ 1091f320 : g_windowsDirectory
uint16_t g_windowsDirectory[256] = {};
// RavenShield.exe data @ 1091f520 : g_moduleFilename
uint16_t g_moduleFilename[256] = {};
// RavenShield.exe data @ 1091478c : g_systemDirectoryCDRequiredKey
const char16_t g_systemDirectoryCDRequiredKey[] = u"CDRequired";
// RavenShield.exe data @ 109147a4 : g_systemDirectoryCDNotFoundKey
const char16_t g_systemDirectoryCDNotFoundKey[] = u"CDNotFound";
// RavenShield.exe data @ 109147bc : g_systemDirectoryErrorsSection
const char16_t g_systemDirectoryErrorsSection[] = u"Errors";
// RavenShield.exe data @ 109147cc : g_systemDirectoryErrorCaptionKey
const char16_t g_systemDirectoryErrorCaptionKey[] = u"Error";
// RavenShield.exe data @ 109147ec : g_systemDirectoryExeSuffix
const char16_t g_systemDirectoryExeSuffix[] = u".EXE";
// RavenShield.exe data @ 109147f8 : g_systemDirectoryIcdSuffix
const char16_t g_systemDirectoryIcdSuffix[] = u".ICD";

// RavenShield.exe @ 109012f0 : InitializeSystemDirectories
// Populate paths and rewrite a final .ICD suffix unchecked; the selected Core CD probe returns one immediately.
void __cdecl InitializeSystemDirectories()
{
  if (GUnicodeOS == 0)
  {
    char scratch[0x300]; // Native order in the frame is module, system, Windows, each 256 bytes.
    char *system = scratch + 0x100;
    char *windows = scratch + 0x200;
    char *module = scratch;
    system[0] = g_fileManagerEmptyAnsiUnit;
    for (uint32_t i = 1; i < 256; ++i) system[i] = 0;
    windows[0] = g_fileManagerEmptyAnsiUnit;
    for (uint32_t i = 1; i < 256; ++i) windows[i] = 0;
    module[0] = g_fileManagerEmptyAnsiUnit;
    for (uint32_t i = 1; i < 256; ++i) module[i] = 0;
    GetSystemDirectoryA(system, 256);
    GetWindowsDirectoryA(windows, 256);
    GetModuleFileNameA(0, module, 256);
    uint16_t *systemScratch = nullptr;
    if ((static_cast<uint32_t>(winGetSizeUNICODE(system)) << 1) != 0)
    {
      const uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(system)) * 2u + 7u) & ~7u;
      systemScratch = static_cast<uint16_t *>(_alloca((bytes + 3u) & ~3u));
    }
    const int32_t systemCount = winGetSizeUNICODE(system);
    const uint16_t *convertedSystem = winToUNICODE(systemScratch, system, systemCount);
    appStrcpy(g_systemDirectory, convertedSystem);
    uint16_t *windowsScratch = nullptr;
    if ((static_cast<uint32_t>(winGetSizeUNICODE(windows)) << 1) != 0)
    {
      const uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(windows)) * 2u + 7u) & ~7u;
      windowsScratch = static_cast<uint16_t *>(_alloca((bytes + 3u) & ~3u));
    }
    const int32_t windowsCount = winGetSizeUNICODE(windows);
    const uint16_t *convertedWindows = winToUNICODE(windowsScratch, windows, windowsCount);
    appStrcpy(g_windowsDirectory, convertedWindows);
    uint16_t *moduleScratch = nullptr;
    if ((static_cast<uint32_t>(winGetSizeUNICODE(module)) << 1) != 0)
    {
      const uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(module)) * 2u + 7u) & ~7u;
      moduleScratch = static_cast<uint16_t *>(_alloca((bytes + 3u) & ~3u));
    }
    const int32_t moduleCount = winGetSizeUNICODE(module);
    const uint16_t *convertedModule = winToUNICODE(moduleScratch, module, moduleCount);
    appStrcpy(g_moduleFilename, convertedModule);
  }
  else
  {
    GetSystemDirectoryW(g_systemDirectory, 256);
    GetWindowsDirectoryW(g_windowsDirectory, 256);
    GetModuleFileNameW(0, g_moduleFilename, 256);
  }
  const uint32_t suffix =
      reinterpret_cast<uint32_t>(g_moduleFilename) + static_cast<uint32_t>(appStrlen(g_moduleFilename)) * 2u - 8u;
  if (appStricmp(reinterpret_cast<const uint16_t *>(suffix),
                 reinterpret_cast<const uint16_t *>(g_systemDirectoryIcdSuffix)) == 0)
  {
    const uint32_t replacement =
        reinterpret_cast<uint32_t>(g_moduleFilename) + static_cast<uint32_t>(appStrlen(g_moduleFilename)) * 2u - 8u;
    appStrcpy(reinterpret_cast<uint16_t *>(replacement),
              reinterpret_cast<const uint16_t *>(g_systemDirectoryExeSuffix));
  }
  for (;;)
  {
    const auto cdPresent =
        *reinterpret_cast<const NativeCDPresence *>(NativeAddress(NativeImport_IsRavenShieldCDInDrive));
    if (cdPresent() != 0) return;
    auto localize = *reinterpret_cast<const NativeLocalize *>(NativeAddress(NativeImport_Localize));
    const uint16_t *caption = localize(reinterpret_cast<const uint16_t *>(g_systemDirectoryErrorsSection),
                                       reinterpret_cast<const uint16_t *>(g_systemDirectoryErrorCaptionKey),
                                       reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr, 0, 0);
    localize = *reinterpret_cast<const NativeLocalize *>(NativeAddress(NativeImport_Localize));
    const uint16_t *message = localize(reinterpret_cast<const uint16_t *>(g_systemDirectoryErrorsSection),
                                       reinterpret_cast<const uint16_t *>(g_systemDirectoryCDNotFoundKey),
                                       reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr, 0, 0);
    if (MessageBoxW(0, message, caption, 5) == 2)
    {
      *(*reinterpret_cast<int32_t **>(NativeAddress(NativeImport_GIsErrorNotABug))) = 1;
      localize = *reinterpret_cast<const NativeLocalize *>(NativeAddress(NativeImport_Localize));
      const uint16_t *required = localize(reinterpret_cast<const uint16_t *>(g_systemDirectoryErrorsSection),
                                          reinterpret_cast<const uint16_t *>(g_systemDirectoryCDRequiredKey),
                                          reinterpret_cast<const uint16_t *>(g_allocatorErrorPackage), nullptr, 0, 0);
      const uint32_t errorSlot = *reinterpret_cast<const uint32_t *>(NativeAddress(NativeImport_GError));
      FOutputDevice *error = *reinterpret_cast<FOutputDevice *const *>(errorSlot);
      const auto logf =
          *reinterpret_cast<const NativeDirectoryErrorLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
      logf(error, required); // Native format-only error logging; if it returns, the CD probe runs again.
    }
  }
}
