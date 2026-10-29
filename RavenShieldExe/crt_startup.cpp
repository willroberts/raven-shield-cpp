#include "native_symbols.hpp"
// Original executable's MSVCR71 startup; all pointer widths and native addresses refer to its x86 image.
#include <cstdint>
#include "launch_runtime.hpp"
#include "game_entry.hpp"

using RuntimeInitializer = void(__cdecl *)();
using OnExitCallback = int32_t(__cdecl *)();
using MathErrorCallback = int32_t(__cdecl *)(void *);
struct CrtStartupInfo
{
  int32_t newMode;
};
struct StartupInfoA
{
  uint32_t size, reserved, desktop, title;
  uint32_t x, y, width, height, columnCount, rowCount, fillAttribute, flags;
  uint16_t showWindow, reservedByteCount;
  uint32_t reservedBytes, standardInput, standardOutput, standardError;
};
extern "C" uint32_t __stdcall GetModuleHandleA(const char *name);
extern "C" void __stdcall GetStartupInfoA(StartupInfoA *info);
extern "C" void __cdecl __set_app_type(int32_t type);
extern "C" int32_t *__cdecl __p__fmode();
extern "C" int32_t *__cdecl __p__commode();
extern "C" int32_t _adjust_fdiv;
extern "C" char *_acmdln;
extern "C" void __cdecl __setusermatherr(MathErrorCallback callback);
extern "C" int32_t __cdecl __getmainargs(int32_t *argc, char ***argv, char ***env, int32_t expandWildcards,
                                         CrtStartupInfo *startup);
extern "C" int32_t __cdecl _ismbblead(uint32_t value);
extern "C" void __cdecl exit(int32_t code);
extern "C" void __cdecl _exit(int32_t code);
extern "C" void __cdecl _cexit();
extern "C" void __cdecl _c_exit();
extern "C" OnExitCallback __cdecl _onexit(OnExitCallback callback);

// RavenShield.exe @ 10911f70 : ForwardExecutableDllOnExit
// Tail-forward callback and exit-list pointers to imported __dllonexit, preserving its callback-pointer result.
__declspec(naked) OnExitCallback __cdecl ForwardExecutableDllOnExit(OnExitCallback callback, OnExitCallback **begin,
                                                                    OnExitCallback **end)
{
  __asm jmp dword ptr [NativeImport_dllonexit]
}

// RavenShield.exe @ 10911f76 : FilterExecutableCrtFault
// Tail-forward the exception code and context to imported _XcptFilter, preserving its signed filter result.
__declspec(naked) int32_t __cdecl FilterExecutableCrtFault(uint32_t code, void *exceptionPointers)
{
  __asm jmp dword ptr [NativeImport_XcptFilter]
}

// RavenShield.exe @ 10911f7c : ReportExecutableRuntimeError
// Tail-forward the fatal runtime-message number to imported _amsg_exit.
__declspec(naked) void __cdecl ReportExecutableRuntimeError(int32_t message)
{
  __asm jmp dword ptr [NativeImport_amsg_exit]
}

// RavenShield.exe @ 1091200a : RunExecutableInitializerRange
// Tail-forward a half-open initializer-pointer range to imported _initterm.
__declspec(naked) void __cdecl RunExecutableInitializerRange(const RuntimeInitializer *begin,
                                                             const RuntimeInitializer *end)
{
  __asm jmp dword ptr [NativeImport_initterm]
}

// RavenShield.exe @ 10912080 : ControlExecutableFloatingPoint
// Tail-forward the control-word value/mask to imported _controlfp, preserving its full unsigned result.
__declspec(naked) uint32_t __cdecl ControlExecutableFloatingPoint(uint32_t value, uint32_t mask)
{
  __asm jmp dword ptr [NativeImport_controlfp]
}

// Observed zero words at the empty RTC begin/end bounds; their contents are not active callback entries.
// RavenShield.exe data @ 1091852c : g_runtimeCheckInitBoundary
const uint32_t g_runtimeCheckInitBoundary = 0;
// RavenShield.exe data @ 10918534 : g_runtimeCheckTermBoundary
const uint32_t g_runtimeCheckTermBoundary = 0;

// Compiler SEH scope records are previous-level/filter/handler words; raw addresses retain native dispatch identity.
struct NativeCrtSehScope
{
  int32_t previousScope;
  uint32_t filterWord, handlerWord;
};
// RavenShield.exe data @ 109182b0 : g_executableStartupScope
const NativeCrtSehScope g_executableStartupScope = {-1, 0x10911e72, 0x10911e86};
// RavenShield.exe data @ 109182e0 : g_runtimeCheckInitializationScope
const NativeCrtSehScope g_runtimeCheckInitializationScope = {-1, 0x10911faf, 0x10911fb3};
// RavenShield.exe data @ 109182f0 : g_runtimeCheckTerminationScope
const NativeCrtSehScope g_runtimeCheckTerminationScope = {-1, 0x10911ff3, 0x10911ff7};

// RavenShield.exe data @ 1091f000 : g_executableCppInitializers
// Include the observed end sentinel after the five class-owned global construction callbacks.
RuntimeInitializer g_executableCppInitializers[7] = {nullptr,
                                                     InitializeLaunchAllocator,
                                                     InitializeLaunchFileLog,
                                                     InitializeLaunchErrorDevice,
                                                     InitializeLaunchFeedback,
                                                     InitializeLaunchFileManager,
                                                     nullptr};
// RavenShield.exe data @ 1091f01c : g_executableCInitializers
RuntimeInitializer g_executableCInitializers[2] = {nullptr, nullptr}; // One slot, then end sentinel.
// RavenShield.exe data @ 1091f0f8 : g_hasUserMathErrorHandler
int32_t g_hasUserMathErrorHandler = 1;
// RavenShield.exe data @ 10940630 : g_expandStartupWildcards
int32_t g_expandStartupWildcards = 0;
// RavenShield.exe data @ 10940634 : g_startupNewMode
int32_t g_startupNewMode = 0;
// RavenShield.exe data @ 10940638 : g_startupCommitMode
int32_t g_startupCommitMode = 0;
// RavenShield.exe data @ 1094063c : g_startupFileMode
int32_t g_startupFileMode = 0;
// RavenShield.exe data @ 10940640 : g_startupAdjustedFdiv
int32_t g_startupAdjustedFdiv = 0;
// RavenShield.exe data @ 10940644 : g_onExitEnd
OnExitCallback *g_onExitEnd = nullptr;
// RavenShield.exe data @ 10940648 : g_onExitBegin
OnExitCallback *g_onExitBegin = nullptr;

// RavenShield.exe @ 10911c74 : RegisterExecutableOnExit
// Use the process CRT exit list for the -1 sentinel, otherwise append to the local begin/end pair.
OnExitCallback __cdecl RegisterExecutableOnExit(OnExitCallback callback)
{
  if (reinterpret_cast<uintptr_t>(g_onExitBegin) == 0xffffffffu) return _onexit(callback);
  return ForwardExecutableDllOnExit(callback, &g_onExitBegin, &g_onExitEnd);
}

// RavenShield.exe @ 10911c9a : RegisterExecutableAtExit
// Convert an on-exit registration result to zero on success or -1 on failure.
int32_t __cdecl RegisterExecutableAtExit(RuntimeInitializer callback)
{
  return RegisterExecutableOnExit(reinterpret_cast<OnExitCallback>(callback)) != nullptr ? 0 : -1;
}

// RavenShield.exe @ 10911f82 : InitializeExecutableRuntimeChecks
// Traverse the selected empty RTC initializer range, swallowing faults from any attempted callback.
void __cdecl InitializeExecutableRuntimeChecks()
{
  for (uint32_t slot = reinterpret_cast<uint32_t>(&g_runtimeCheckInitBoundary);
       slot < reinterpret_cast<uint32_t>(&g_runtimeCheckInitBoundary); slot += 4)
  {
    __try
    {
      RuntimeInitializer callback = *reinterpret_cast<RuntimeInitializer *>(slot);
      if (callback != nullptr) callback();
    }
    // RavenShield.exe @ 10911faf : RuntimeCheckInitializationFilter
    // Select the handler for any exception in an RTC initializer callback.
    __except (1)
    {
      // RavenShield.exe @ 10911fb3 : ResumeRuntimeCheckInitialization
      // Resume at the callback loop's state reset and next-slot increment after restoring saved ESP.
    }
  }
}

// RavenShield.exe @ 10911fc6 : TerminateExecutableRuntimeChecks
// Traverse the selected empty RTC terminator range with the same fault suppression as initialization.
void __cdecl TerminateExecutableRuntimeChecks()
{
  for (uint32_t slot = reinterpret_cast<uint32_t>(&g_runtimeCheckTermBoundary);
       slot < reinterpret_cast<uint32_t>(&g_runtimeCheckTermBoundary); slot += 4)
  {
    __try
    {
      RuntimeInitializer callback = *reinterpret_cast<RuntimeInitializer *>(slot);
      if (callback != nullptr) callback();
    }
    // RavenShield.exe @ 10911ff3 : RuntimeCheckTerminationFilter
    // Select the handler for any exception in an RTC terminator callback.
    __except (1)
    {
      // RavenShield.exe @ 10911ff7 : ResumeRuntimeCheckTermination
      // Resume at the callback loop's state reset and next-slot increment after restoring saved ESP.
    }
  }
}

// RavenShield.exe @ 10912010 : SetExecutableDefaultPrecision
// Set the x87 precision-control field to 53-bit precision while preserving other control bits.
void __cdecl SetExecutableDefaultPrecision()
{
  ControlExecutableFloatingPoint(0x10000, 0x30000);
}

// RavenShield.exe @ 10912022 : DefaultExecutableMathError
// Genuine native stub: return zero, leaving math-error handling to the runtime's default behavior.
int32_t __cdecl DefaultExecutableMathError()
{
  return 0;
}

// RavenShield.exe @ 10911cac : ExecutableCrtEntry
// Initialize the process CRT, skip the ANSI executable name, call the game launcher and perform CRT shutdown.
int32_t __cdecl ExecutableCrtEntry()
{
  bool quoted = false;
  bool managedImage = false;
  const uint8_t *image = reinterpret_cast<const uint8_t *>(GetModuleHandleA(nullptr));
  if (*reinterpret_cast<const uint16_t *>(image) == 0x5a4d)
  {
    const uint8_t *pe = image + *reinterpret_cast<const uint32_t *>(image + 0x3c);
    if (*reinterpret_cast<const uint32_t *>(pe) == 0x4550)
    {
      const uint16_t magic = *reinterpret_cast<const uint16_t *>(pe + 0x18);
      if (magic == 0x10b && *reinterpret_cast<const uint32_t *>(pe + 0x74) > 14)
        managedImage = *reinterpret_cast<const uint32_t *>(pe + 0xe8) != 0;
      else if (magic == 0x20b && *reinterpret_cast<const uint32_t *>(pe + 0x84) > 14)
        managedImage = *reinterpret_cast<const uint32_t *>(pe + 0xf8) != 0;
    }
  } // Native header probing precedes activation of the startup SEH scope.
  int32_t result;
  uint32_t exceptionCode;
  __try
  {
    __set_app_type(2); // GUI application.
    g_onExitEnd = reinterpret_cast<OnExitCallback *>(uintptr_t(0xffffffffu));
    g_onExitBegin = reinterpret_cast<OnExitCallback *>(uintptr_t(0xffffffffu));
    int32_t *fileMode = __p__fmode();
    *fileMode = g_startupFileMode;
    int32_t *commitMode = __p__commode();
    *commitMode = g_startupCommitMode;
    g_startupAdjustedFdiv = _adjust_fdiv;
    InitializeExecutableRuntimeChecks();
    DefaultExecutableMathError();
    if (g_hasUserMathErrorHandler == 0)
      __setusermatherr(reinterpret_cast<MathErrorCallback>(DefaultExecutableMathError));
    SetExecutableDefaultPrecision();
    RunExecutableInitializerRange(g_executableCInitializers, g_executableCInitializers + 1);
    RegisterExecutableAtExit(TerminateExecutableRuntimeChecks); // Result ignored.
    CrtStartupInfo startup;
    startup.newMode = g_startupNewMode;
    int32_t argc;
    char **argv, **environment;
    if (__getmainargs(&argc, &argv, &environment, g_expandStartupWildcards, &startup) < 0)
      ReportExecutableRuntimeError(8);
    RunExecutableInitializerRange(g_executableCppInitializers, g_executableCppInitializers + 6);
    uint8_t *commandLine = reinterpret_cast<uint8_t *>(_acmdln);
    while (*commandLine > 0x20 || (*commandLine != 0 && quoted))
    {
      const uint8_t character = *commandLine;
      if (character == '"') quoted = !quoted;
      if (_ismbblead(character) != 0) ++commandLine;
      ++commandLine; // Native multibyte skipping does not check for a trailing NUL after a lead byte.
    }
    while (*commandLine != 0 && *commandLine <= 0x20) ++commandLine;
    StartupInfoA info; // Native clears only flags, not size or the rest of the structure.
    info.flags = 0;
    GetStartupInfoA(&info);
    result = GameWinMain(GetModuleHandleA(nullptr), 0, reinterpret_cast<char *>(commandLine),
                         (info.flags & 1) != 0 ? info.showWindow : 10);
    if (!managedImage) exit(result);
    _cexit();
  }
  // RavenShield.exe @ 10911e72 : ExecutableStartupExceptionFilter
  // Save the exception code and ask the CRT whether to handle the startup fault.
  __except ((exceptionCode = GetExceptionCode(), FilterExecutableCrtFault(exceptionCode, GetExceptionInformation())))
  {
    // RavenShield.exe @ 10911e86 : HandleExecutableStartupFault
    // The native landing restores ESP, exits unmanaged images without cleanup, or runs _c_exit and returns.
    result = static_cast<int32_t>(exceptionCode);
    if (!managedImage) _exit(result);
    _c_exit();
  }
  return result;
}
