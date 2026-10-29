#include "native_symbols.hpp"
// Windows error reporting and crash-dialog lifetime; offsets retain the selected 12-byte device layout.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"

// RavenShield.exe data @ 10914ef4 : g_windowsErrorVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_windowsErrorVtable[2] = {
    NativeAddress(NativeEntry_FOutputDeviceWindowsError_Serialize),   // +000 FOutputDeviceWindowsError::Serialize
    NativeAddress(NativeEntry_FOutputDeviceWindowsError_HandleError), // +004 FOutputDeviceWindowsError::HandleError
};

// RavenShield.exe data @ 1093fdbc : g_launchErrorStorage
alignas(4) uint8_t g_launchErrorStorage[0xc] = {};

// RavenShield.exe @ 10912fe0 : InitializeLaunchErrorDevice
// Construct the imported error base, install the Windows table and clear error-position/type state.
void __cdecl InitializeLaunchErrorDevice()
{
  const auto constructBase =
      *reinterpret_cast<const ImportedBaseConstructor *>(NativeAddress(NativeImport_FOutputDeviceErrorConstruct));
  auto *object = g_launchErrorStorage;
  constructBase(object); // Core.dll FOutputDeviceError::FOutputDeviceError; derived construction is inlined here.
  *reinterpret_cast<const uint32_t **>(object) = g_windowsErrorVtable;
  *reinterpret_cast<uint32_t *>(object + 4) = 0; // ErrorPos.
  *reinterpret_cast<uint32_t *>(object + 8) = 0; // ErrorType, NAME_None.
}

class FConfigCache;
class FOutputDevice;
class UObject;
class WDialog;
class WCrashBoxDialog; // Window.dll contract: caller slot at EBP-288; full class size/layout remain partial.
extern FConfigCache *GConfig;
extern FOutputDevice *GLog;
extern FOutputDevice *GLogHook;
extern int32_t GIsErrorNotABug, GIsCriticalError, GIsGuarded, GIsRunning, GIsStarted, GIsClient, GIsEditor;
extern uint16_t GErrorHist[0x1000]; // Imported Core array, not an imported pointer variable.
extern uint32_t hInstanceWindow;
extern const char16_t g_feedbackLocalizationPackage[]; // Shared native Core package literal.
extern const uint16_t *__cdecl LocalizeError(const char *key, const uint16_t *package, const uint16_t *language);
extern const uint16_t *__cdecl LocalizeError(const uint16_t *key, const uint16_t *package, const uint16_t *language);
extern void __cdecl appExit();
extern void __cdecl appRequestExit(int32_t force);
extern const uint16_t *__cdecl appGetSystemErrorMessage(int32_t error);
extern uint16_t *__cdecl appStrncpy(uint16_t *destination, const uint16_t *source, int32_t capacity);
extern uint16_t *__cdecl appStrncat(uint16_t *destination, const uint16_t *source, int32_t capacity);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern "C" uint32_t __stdcall GetLastError();
extern "C" int32_t __stdcall MessageBoxW(uint32_t window, const uint16_t *text, const uint16_t *caption,
                                         uint32_t flags);
extern "C" void DispatchExecutableCppException();
using ImportedDialogDoModal = int32_t(__thiscall *)(WDialog *dialog, uint32_t instance);
using ErrorOutputLogf = void(__cdecl *)(FOutputDevice *, int32_t, const uint16_t *, ...);
using ErrorHandleDispatch = void(__thiscall *)(FOutputDeviceWindowsError *);

// RavenShield.exe data @ 10914efc : g_errorReentryFormat
const char16_t g_errorReentryFormat[] = u"Error reentered: %s";
// RavenShield.exe data @ 10914f24 : g_errorHistorySeparator
const char16_t g_errorHistorySeparator[] = u": ";
// RavenShield.exe data @ 10914f2c : g_errorHistoryFallback
const char16_t g_errorHistoryFallback[] = u"History: ";
// RavenShield.exe data @ 10914f40 : g_errorHistoryKey
const char g_errorHistoryKey[] = "History";
// RavenShield.exe data @ 10914f54 : g_errorHistoryNewlines
const char16_t g_errorHistoryNewlines[] = u"\r\n\r\n";
// RavenShield.exe data @ 10914f60 : g_errorSystemErrorFormat
const char16_t g_errorSystemErrorFormat[] = u"Windows GetLastError: %s (%i)";
// RavenShield.exe data @ 10914f9c : g_errorFirstCallMessage
const char16_t g_errorFirstCallMessage[] = u"appError called:";
// RavenShield.exe data @ 10914fc0 : g_errorStartupCaption
const char16_t g_errorStartupCaption[] = u"Critical Error At Startup";
// RavenShield.exe data @ 10914ff4 : g_errorCriticalKey
const char16_t g_errorCriticalKey[] = u"Critical";
// RavenShield.exe data @ 10915008 : g_errorWindowPackage
extern const char16_t g_errorWindowPackage[] = u"Window";

// RavenShield.exe @ 109032a0 : FOutputDeviceWindowsError::Serialize
// Capture/report the first critical error or log reentry, then propagate integer one when guarded or request exit.
void FOutputDeviceWindowsError::Serialize(const uint16_t *message, int32_t event)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t error = GetLastError();
  if (GIsErrorNotABug != 0)
  {
    const uint16_t *caption = GConfig != nullptr
                                  ? LocalizeError(reinterpret_cast<const uint16_t *>(g_errorCriticalKey),
                                                  reinterpret_cast<const uint16_t *>(g_errorWindowPackage), nullptr)
                                  : reinterpret_cast<const uint16_t *>(g_errorStartupCaption);
    MessageBoxW(0, message, caption, 0x2010);
    GIsCriticalError = 1;
    appExit();
    appRequestExit(1); // Native continues into the common path if these imported shutdown calls return.
  }
  if (GIsCriticalError == 0)
  {
    GIsCriticalError = 1;
    *reinterpret_cast<int32_t *>(object + 8) = event;
    FOutputDevice *firstOutput = GLog;
    const auto firstLogf =
        *reinterpret_cast<const ErrorOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
    firstLogf(firstOutput, 0x2f9,
              reinterpret_cast<const uint16_t *>(g_errorFirstCallMessage)); // NAME_Critical.
    FOutputDevice *contextOutput = GLog;
    const auto contextLogf =
        *reinterpret_cast<const ErrorOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
    contextLogf(contextOutput, 0x2f9, reinterpret_cast<const uint16_t *>(g_unwindContextFormat), message);
    const uint16_t *systemError = appGetSystemErrorMessage(static_cast<int32_t>(error));
    FOutputDevice *systemOutput = GLog;
    const auto systemLogf =
        *reinterpret_cast<const ErrorOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
    systemLogf(systemOutput, 0x2f9, reinterpret_cast<const uint16_t *>(g_errorSystemErrorFormat), systemError,
               static_cast<int32_t>(error));
    UObject::StaticShutdownAfterError();
    appStrncpy(GErrorHist, message, 0x1000);
    appStrncat(GErrorHist, reinterpret_cast<const uint16_t *>(g_errorHistoryNewlines), 0x1000);
    *reinterpret_cast<int32_t *>(object + 4) = appStrlen(GErrorHist);
    if (GIsGuarded != 0)
    {
      const uint16_t *history =
          GIsGuarded != 0 ? LocalizeError(g_errorHistoryKey,
                                          reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr)
                          : reinterpret_cast<const uint16_t *>(g_errorHistoryFallback);
      appStrncat(GErrorHist, history, 0x1000);
      appStrncat(GErrorHist, reinterpret_cast<const uint16_t *>(g_errorHistorySeparator), 0x1000);
    }
    else
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto handleError = *reinterpret_cast<const ErrorHandleDispatch *>(table + 4);
      handleError(this); // Reload the live device table; no stack arguments or consumed result.
    }
  }
  else
  {
    FOutputDevice *reentryOutput = GLog;
    const auto reentryLogf =
        *reinterpret_cast<const ErrorOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
    reentryLogf(reentryOutput, 0x2f9, reinterpret_cast<const uint16_t *>(g_errorReentryFormat), message);
  }
  if (GIsGuarded != 0) throw 1; // Native simple four-byte int ThrowInfo 10918870; no local catch or guard.
  appRequestExit(1);
}

// RavenShield.exe @ 109034c0 : FOutputDeviceWindowsError::HandleError
// Reset runtime flags, truncate history and show a crash dialog with message-box fallback, swallowing outer failures.
void FOutputDeviceWindowsError::HandleError()
{
  try
  {
    GIsGuarded = 0;
    GIsRunning = 0;
    GIsCriticalError = 1;
    GLogHook = nullptr;
    UObject::StaticShutdownAfterError();
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    const int32_t end = *reinterpret_cast<const int32_t *>(object + 8) == 0x318 // NAME_FriendlyError.
                            ? *reinterpret_cast<const int32_t *>(object + 4)
                            : 0xfff;
    const uint32_t historyEnd = reinterpret_cast<uint32_t>(GErrorHist) + static_cast<uint32_t>(end) * 2;
    *reinterpret_cast<uint16_t *>(historyEnd) = 0; // Unchecked native 32-bit indexing, including wrapped positions.
    if (GIsClient != 0 || GIsEditor != 0 || GIsStarted == 0)
    {
      try
      {
        const uint16_t *caption = GConfig != nullptr
                                      ? LocalizeError(reinterpret_cast<const uint16_t *>(g_errorCriticalKey),
                                                      reinterpret_cast<const uint16_t *>(g_errorWindowPackage), nullptr)
                                      : reinterpret_cast<const uint16_t *>(g_errorStartupCaption);
        WCrashBoxDialog crashBox(caption, GErrorHist); // Imported construction/destruction, native EBP-288 storage.
        GIsCriticalError = 0;
        const auto doModal =
            *reinterpret_cast<const ImportedDialogDoModal *>(NativeAddress(NativeImport_WDialog_DoModal));
        doModal(reinterpret_cast<WDialog *>(&crashBox), hInstanceWindow); // Native zero-offset WDialog base.
        GIsCriticalError = 1;
      }
      // RavenShield.exe @ 1090362a : ShowErrorMessageBoxFallback
      // Recompute the caption and show current history after construction/modal/destruction failure; retain flag state.
      catch (...)
      {
        const uint16_t *caption = GConfig != nullptr
                                      ? LocalizeError(reinterpret_cast<const uint16_t *>(g_errorCriticalKey),
                                                      reinterpret_cast<const uint16_t *>(g_errorWindowPackage), nullptr)
                                      : reinterpret_cast<const uint16_t *>(g_errorStartupCaption);
        MessageBoxW(0, GErrorHist, caption, 0x2010);
      }
    }
  }
  // RavenShield.exe @ 10903692 : SwallowErrorHandlerFailure
  // Discard any outer failure, including failure of the fallback localization or message box.
  catch (...)
  {
  }
}

// RavenShield.exe @ 109121e0 : DestroyErrorCrashDialogOnUnwind
// Destroy the fully constructed Window.dll crash dialog at parent EBP-288 without freeing its stack storage.
__declspec(naked) void DestroyErrorCrashDialogOnUnwind()
{
  __asm {
    lea ecx, [ebp-288h]
    jmp dword ptr [NativeImport_WCrashBoxDialogDestroy]
  }
}

// RavenShield.exe data @ 10918880 : g_windowsErrorDeviceUnwind
const NativeCppUnwindEntry g_windowsErrorDeviceUnwind[5] = {
    {-1, 0},
    {0, 0},
    {1, NativeAddress(NativeEntry_DestroyErrorCrashDialogOnUnwind)}, // DestroyErrorCrashDialogOnUnwind
    {0, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109188a8 : g_windowsErrorDeviceMessageBoxCatches
const NativeCppCatchHandler g_windowsErrorDeviceMessageBoxCatches[1] = {
    {0, 0, 0, 0x1090362a}, // ShowErrorMessageBoxFallback
};

// RavenShield.exe data @ 109188b8 : g_windowsErrorDeviceHandlerFailureCatches
const NativeCppCatchHandler g_windowsErrorDeviceHandlerFailureCatches[1] = {
    {0, 0, 0, 0x10903692}, // SwallowErrorHandlerFailure
};

// RavenShield.exe data @ 109188c8 : g_windowsErrorDeviceTryBlocks
const NativeCppTryBlock g_windowsErrorDeviceTryBlocks[2] = {
    {1, 2, 3, 1, NativeAddress(g_windowsErrorDeviceMessageBoxCatches)},
    {0, 3, 4, 1, NativeAddress(g_windowsErrorDeviceHandlerFailureCatches)},
};

// RavenShield.exe data @ 109188f0 : g_windowsErrorDeviceExceptionInfo
const NativeCppFunctionInfo g_windowsErrorDeviceExceptionInfo = {
    0x19930520, 5, NativeAddress(g_windowsErrorDeviceUnwind), 2, NativeAddress(g_windowsErrorDeviceTryBlocks), 0, 0};

// RavenShield.exe @ 109121ec : HandleWindowsErrorDeviceException
// Supply the five-state nested catch-all map with crash-dialog cleanup and no method-guard annotation.
__declspec(naked) void HandleWindowsErrorDeviceException()
{
  __asm {
    mov eax, offset g_windowsErrorDeviceExceptionInfo
    jmp DispatchExecutableCppException
  }
}
