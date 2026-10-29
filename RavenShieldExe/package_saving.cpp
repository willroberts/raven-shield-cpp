#include "native_symbols.hpp"
// Editor shutdown package prompts and the original ANSI save-dialog path.
#include "cpp_exception_metadata.hpp"
#include "object_support.hpp"
#include "container_support.hpp"
#include "launch_runtime.hpp"
#include "package_saving.hpp"
#include <windows.h>
#include <commdlg.h>
#include <cstring>

class FOutputDevice;
class FExec;
extern FOutputDevice *GLog;
extern const char g_fileManagerEmptyAnsiUnit;
extern void __cdecl appUnwindf(const uint16_t *format, ...);

// RavenShield.exe data @ 10916524 : g_saveDirtyPackagesGuardName
const char16_t g_saveDirtyPackagesGuardName[] = u"SaveDirtyPackages";
// RavenShield.exe data @ 10916548 : g_saveDirtyPackageCommand
const char16_t g_saveDirtyPackageCommand[] = u"OBJ SAVEPACKAGE PACKAGE=\"%s\" FILE=\"%s\"";
// RavenShield.exe data @ 10916598 : g_saveDirtyPackageDialogTitle
const char g_saveDirtyPackageDialogTitle[] = "Save Dirty Package";
// RavenShield.exe data @ 109165ac : g_saveDirtyPackageDialogFilter
const char g_saveDirtyPackageDialogFilter[] = "Packages (*.*)\0*.*\0";
// RavenShield.exe data @ 109165c4 : g_dirtyPackageInitialFilenameWord
const uint16_t g_dirtyPackageInitialFilenameWord = 0;
// RavenShield.exe data @ 109165c8 : g_saveDirtyPackagePrompt
const char16_t g_saveDirtyPackagePrompt[] = u"The package '%s' has been changed and needs to be saved.  Save it now?";
// RavenShield.exe data @ 10916658 : g_saveDirtyPackageExcludedName
const char16_t g_saveDirtyPackageExcludedName[] = u"MyLevel";

// RavenShield.exe @ 10909010 : SaveDirtyPackages
// Prompt for dirty top-level packages except exact MyLevel, optionally issue save commands, and always return one.
int32_t __cdecl SaveDirtyPackages(UEngine *engine)
{
  // Refer to native import slots; each guarded call reads the current target.
  const auto &getOuter =
      *reinterpret_cast<UObject *(__thiscall **)(const UObject *)>(NativeAddress(NativeImport_UObject_GetOuter));
  const auto &getName =
      *reinterpret_cast<const uint16_t *(__thiscall **)(const UObject *)>(NativeAddress(NativeImport_UObject_GetName));
  const auto &compare =
      *reinterpret_cast<int32_t(__cdecl **)(const uint16_t *, const uint16_t *)>(NativeAddress(NativeImport_appStrcmp));
  const auto &message =
      *reinterpret_cast<int32_t(__cdecl **)(int32_t, const uint16_t *, ...)>(NativeAddress(NativeImport_appMsgf));
  const auto &fromAnsi =
      *reinterpret_cast<const uint16_t *(__cdecl **)(const char *)>(NativeAddress(NativeImport_appFromAnsi));
  try
  {
    for (TObjectIterator<UPackage> packages; packages; ++packages)
    {
      if (getOuter(reinterpret_cast<UObject *>(*packages)) != nullptr) continue;
      if (*reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(*packages) + 0x38) == 0) continue;
      const uint16_t *name = getName(reinterpret_cast<UObject *>(*packages));
      if (compare(name, reinterpret_cast<const uint16_t *>(g_saveDirtyPackageExcludedName)) == 0) continue;
      name = getName(reinterpret_cast<UObject *>(*packages));
      if (message(1, reinterpret_cast<const uint16_t *>(g_saveDirtyPackagePrompt), name) == 0) continue;
      char filename[8192];
      std::memcpy(filename, &g_dirtyPackageInitialFilenameWord, 2);
      std::memset(filename + 2, 0, sizeof(filename) - 2);
      OPENFILENAMEA dialog;
      std::memset(&dialog, 0, 0x4c); // Native legacy Win32 structure prefix; no later SDK extension fields are touched.
      dialog.lStructSize = 0x4c;
      dialog.hwndOwner = nullptr;
      dialog.lpstrFile = filename;
      dialog.nMaxFile = 8192;
      dialog.lpstrFilter = g_saveDirtyPackageDialogFilter;
      dialog.lpstrDefExt = &g_fileManagerEmptyAnsiUnit;
      dialog.lpstrTitle = g_saveDirtyPackageDialogTitle;
      dialog.Flags = 0x0e; // HIDEREADONLY | NOCHANGEDIR | OVERWRITEPROMPT.
      if (GetSaveFileNameA(&dialog) == 0) continue;
      const uint16_t *path = fromAnsi(filename);
      name = getName(reinterpret_cast<UObject *>(*packages));
      FString command = FString::Printf(reinterpret_cast<const uint16_t *>(g_saveDirtyPackageCommand), name, path);
      const uint16_t *text = *command;
      FOutputDevice *log = GLog;
      auto *execBase = reinterpret_cast<FExec *>(reinterpret_cast<uint32_t>(engine) + 0x2cu);
      const uint32_t table = *reinterpret_cast<const uint32_t *>(execBase);
      using ExecCommand = int32_t(__thiscall *)(FExec *, const uint16_t *, FOutputDevice *);
      const auto exec = *reinterpret_cast<const ExecCommand *>(table);
      exec(execBase, text, log); // Ignore the result; command destruction precedes the next iterator increment.
    }
    return 1;
  }
  // RavenShield.exe @ 1090926e : RethrowSaveDirtyPackagesPointer
  // Copy-throw the caught UTF-16 pointer from parent EBP-206c through EBP-207c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090928b : UnwindSaveDirtyPackagesFailure
  // Append the guard and rethrow after the live formatted command, if any, has been destroyed.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_saveDirtyPackagesGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912560 : DestroySaveDirtyPackagesCommand
// Destroy the one live formatted FString at parent EBP-2078 during exceptional unwinding.
__declspec(naked) void DestroySaveDirtyPackagesCommand()
{
  __asm {
    lea ecx, [ebp-2078h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 10919684 : g_saveDirtyPackagesUnwind
const NativeCppUnwindEntry g_saveDirtyPackagesUnwind[3] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_DestroySaveDirtyPackagesCommand)}, // DestroySaveDirtyPackagesCommand
    {-1, 0},
};

// RavenShield.exe data @ 1091969c : g_saveDirtyPackagesCatches
const NativeCppCatchHandler g_saveDirtyPackagesCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x206c, 0x1090926e}, // RethrowSaveDirtyPackagesPointer
    {0, 0, 0, 0x1090928b},                                                 // UnwindSaveDirtyPackagesFailure
};

// RavenShield.exe data @ 109196bc : g_saveDirtyPackagesTryBlocks
const NativeCppTryBlock g_saveDirtyPackagesTryBlocks[1] = {
    {0, 1, 2, 2, NativeAddress(g_saveDirtyPackagesCatches)},
};

// RavenShield.exe data @ 109196d0 : g_saveDirtyPackagesExceptionInfo
const NativeCppFunctionInfo g_saveDirtyPackagesExceptionInfo = {
    0x19930520, 3, NativeAddress(g_saveDirtyPackagesUnwind), 1, NativeAddress(g_saveDirtyPackagesTryBlocks), 0, 0};

// RavenShield.exe @ 1091256c : HandleSaveDirtyPackagesException
// Supply the three-state command cleanup and pointer/catch-all guard map to shared C++ dispatch.
__declspec(naked) void HandleSaveDirtyPackagesException()
{
  __asm {
    mov eax, offset g_saveDirtyPackagesExceptionInfo
    jmp DispatchExecutableCppException
  }
}
