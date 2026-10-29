#include "native_symbols.hpp"
// Windows feedback serialization, prompts, progress tasks and owned map-check messages.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"
#include "map_check.hpp"
#include <new>
#include <malloc.h>

// RavenShield.exe data @ 10915018 : g_windowsFeedbackVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_windowsFeedbackVtable[11] = {
    NativeAddress(NativeEntry_FFeedbackContextWindows_Serialize),     // +000 FFeedbackContextWindows::Serialize
    NativeAddress(NativeEntry_FFeedbackContextWindows_YesNof),        // +004 FFeedbackContextWindows::YesNof
    NativeAddress(NativeEntry_FFeedbackContextWindows_BeginSlowTask), // +008 FFeedbackContextWindows::BeginSlowTask
    NativeAddress(NativeEntry_FFeedbackContextWindows_EndSlowTask),   // +00c FFeedbackContextWindows::EndSlowTask
    NativeAddress(NativeEntry_FFeedbackContextWindows_StatusUpdatef), // +010 FFeedbackContextWindows::StatusUpdatef
    NativeAddress(NativeEntry_IgnoreSharedVirtualArgument),           // +014 IgnoreSharedVirtualArgument
    NativeAddress(NativeEntry_FFeedbackContextWindows_MapCheck_Show), // +018 FFeedbackContextWindows::MapCheck_Show
    NativeAddress(
        NativeEntry_FFeedbackContextWindows_MapCheck_ShowConditionally), // +01c
  // FFeedbackContextWindows::MapCheck_ShowConditionally
    NativeAddress(NativeEntry_FFeedbackContextWindows_MapCheck_Hide),  // +020 FFeedbackContextWindows::MapCheck_Hide
    NativeAddress(NativeEntry_FFeedbackContextWindows_MapCheck_Clear), // +024 FFeedbackContextWindows::MapCheck_Clear
    NativeAddress(NativeEntry_FFeedbackContextWindows_MapCheck_Add),   // +028 FFeedbackContextWindows::MapCheck_Add
};

// RavenShield.exe data @ 109405d8 : g_launchFeedbackStorage
alignas(4) uint8_t g_launchFeedbackStorage[0x18] = {};

// RavenShield.exe @ 109036b0 : FFeedbackContextWindows::FFeedbackContextWindows
// Construct the imported feedback base, install the Windows table and clear task/progress-window state.
FFeedbackContextWindows::FFeedbackContextWindows() : FFeedbackContext() // Imported base, IAT 1091408c.
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_windowsFeedbackVtable;
  *reinterpret_cast<uint32_t *>(object + 4) = 0;    // SlowTaskCount.
  *reinterpret_cast<uint32_t *>(object + 8) = 0;    // hWndProgressBar.
  *reinterpret_cast<uint32_t *>(object + 0xc) = 0;  // hWndProgressText.
  *reinterpret_cast<uint32_t *>(object + 0x10) = 0; // hWndProgressDlg.
  *reinterpret_cast<uint32_t *>(object + 0x14) = 0; // hWndMapCheckDlg.
}

// RavenShield.exe @ 10913010 : InitializeLaunchFeedback
// Construct the static feedback context passed to appInit.
void __cdecl InitializeLaunchFeedback()
{
  new (g_launchFeedbackStorage) FFeedbackContextWindows;
}

extern int32_t GUnicodeOS;
extern int32_t GIsSlowTask;
extern "C" int32_t __stdcall SendMessageW(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SendMessageA(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall ShowWindow(uint32_t window, int32_t command);
extern "C" int32_t __stdcall UpdateWindow(uint32_t window);
extern "C" int32_t __stdcall PeekMessageW(void *message, uint32_t window, uint32_t minimum, uint32_t maximum,
                                          uint32_t remove);
extern "C" int32_t __stdcall TranslateMessage(const void *message);
extern "C" int32_t __stdcall DispatchMessageW(const void *message);
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *buffer, const uint16_t *text, int32_t count);
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 109150e8 : g_feedbackMapCheckShowGuardName
const char16_t g_feedbackMapCheckShowGuardName[] = u"FFeedbackContextWindows::MapCheck_Show";

// RavenShield.exe @ 10903900 : FFeedbackContextWindows::MapCheck_Show
// Send the show map-check command to the current dialog, selecting the native Unicode or ANSI API.
void FFeedbackContextWindows::MapCheck_Show()
{
  try
  {
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    if (GUnicodeOS != 0)
      SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8015, 0);
    else
      SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8015, 0);
  }
  // RavenShield.exe @ 10903972 : RethrowFeedbackMapCheckShowPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903986 : UnwindFeedbackMapCheckShowFailure
  // Append the native method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackMapCheckShowGuardName));
    throw;
  }
}

// RavenShield.exe data @ 109189cc : g_feedbackMapCheckShowUnwind
const NativeCppUnwindEntry g_feedbackMapCheckShowUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109189dc : g_feedbackMapCheckShowCatches
const NativeCppCatchHandler g_feedbackMapCheckShowCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10903972}, // RethrowFeedbackMapCheckShowPointer
    {0, 0, 0, 0x10903986},                                               // UnwindFeedbackMapCheckShowFailure
};

// RavenShield.exe data @ 109189fc : g_feedbackMapCheckShowTryBlocks
const NativeCppTryBlock g_feedbackMapCheckShowTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackMapCheckShowCatches)},
};

// RavenShield.exe data @ 10918a10 : g_feedbackMapCheckShowExceptionInfo
const NativeCppFunctionInfo g_feedbackMapCheckShowExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackMapCheckShowUnwind), 1, NativeAddress(g_feedbackMapCheckShowTryBlocks),
    0,          0};

// RavenShield.exe @ 10912220 : HandleFeedbackMapCheckShowException
// Supply MapCheck_Show's two-state pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleFeedbackMapCheckShowException()
{
  __asm {
    mov eax, offset g_feedbackMapCheckShowExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915138 : g_feedbackMapCheckShowConditionallyGuardName
const char16_t g_feedbackMapCheckShowConditionallyGuardName[] = u"FFeedbackContextWindows::MapCheck_ShowConditionally";

// RavenShield.exe @ 109039c0 : FFeedbackContextWindows::MapCheck_ShowConditionally
// Send the conditionally show map-check command to the current dialog, selecting the native Unicode or ANSI API.
void FFeedbackContextWindows::MapCheck_ShowConditionally()
{
  try
  {
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    if (GUnicodeOS != 0)
      SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8016, 0);
    else
      SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8016, 0);
  }
  // RavenShield.exe @ 10903a32 : RethrowFeedbackMapCheckShowConditionallyPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903a46 : UnwindFeedbackMapCheckShowConditionallyFailure
  // Append the native method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackMapCheckShowConditionallyGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918a2c : g_feedbackMapCheckShowConditionallyUnwind
const NativeCppUnwindEntry g_feedbackMapCheckShowConditionallyUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918a3c : g_feedbackMapCheckShowConditionallyCatches
const NativeCppCatchHandler g_feedbackMapCheckShowConditionallyCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14,
     0x10903a32},          // RethrowFeedbackMapCheckShowConditionallyPointer
    {0, 0, 0, 0x10903a46}, // UnwindFeedbackMapCheckShowConditionallyFailure
};

// RavenShield.exe data @ 10918a5c : g_feedbackMapCheckShowConditionallyTryBlocks
const NativeCppTryBlock g_feedbackMapCheckShowConditionallyTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackMapCheckShowConditionallyCatches)},
};

// RavenShield.exe data @ 10918a70 : g_feedbackMapCheckShowConditionallyExceptionInfo
const NativeCppFunctionInfo g_feedbackMapCheckShowConditionallyExceptionInfo = {
    0x19930520,
    2,
    NativeAddress(g_feedbackMapCheckShowConditionallyUnwind),
    1,
    NativeAddress(g_feedbackMapCheckShowConditionallyTryBlocks),
    0,
    0};

// RavenShield.exe @ 10912230 : HandleFeedbackMapCheckShowConditionallyException
// Supply MapCheck_ShowConditionally's two-state pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleFeedbackMapCheckShowConditionallyException()
{
  __asm {
    mov eax, offset g_feedbackMapCheckShowConditionallyExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 109151a0 : g_feedbackMapCheckHideGuardName
const char16_t g_feedbackMapCheckHideGuardName[] = u"FFeedbackContextWindows::MapCheck_Hide";

// RavenShield.exe @ 10903a80 : FFeedbackContextWindows::MapCheck_Hide
// Send the hide map-check command to the current dialog, selecting the native Unicode or ANSI API.
void FFeedbackContextWindows::MapCheck_Hide()
{
  try
  {
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    if (GUnicodeOS != 0)
      SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8036, 0);
    else
      SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8036, 0);
  }
  // RavenShield.exe @ 10903af2 : RethrowFeedbackMapCheckHidePointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903b06 : UnwindFeedbackMapCheckHideFailure
  // Append the native method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackMapCheckHideGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918a8c : g_feedbackMapCheckHideUnwind
const NativeCppUnwindEntry g_feedbackMapCheckHideUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918a9c : g_feedbackMapCheckHideCatches
const NativeCppCatchHandler g_feedbackMapCheckHideCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10903af2}, // RethrowFeedbackMapCheckHidePointer
    {0, 0, 0, 0x10903b06},                                               // UnwindFeedbackMapCheckHideFailure
};

// RavenShield.exe data @ 10918abc : g_feedbackMapCheckHideTryBlocks
const NativeCppTryBlock g_feedbackMapCheckHideTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackMapCheckHideCatches)},
};

// RavenShield.exe data @ 10918ad0 : g_feedbackMapCheckHideExceptionInfo
const NativeCppFunctionInfo g_feedbackMapCheckHideExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackMapCheckHideUnwind), 1, NativeAddress(g_feedbackMapCheckHideTryBlocks),
    0,          0};

// RavenShield.exe @ 10912240 : HandleFeedbackMapCheckHideException
// Supply MapCheck_Hide's two-state pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleFeedbackMapCheckHideException()
{
  __asm {
    mov eax, offset g_feedbackMapCheckHideExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 109151f0 : g_feedbackMapCheckClearGuardName
const char16_t g_feedbackMapCheckClearGuardName[] = u"FFeedbackContextWindows::MapCheck_Clear";

// RavenShield.exe @ 10903b40 : FFeedbackContextWindows::MapCheck_Clear
// Send the clear map-check command to the current dialog, selecting the native Unicode or ANSI API.
void FFeedbackContextWindows::MapCheck_Clear()
{
  try
  {
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    if (GUnicodeOS != 0)
      SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8017, 0);
    else
      SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8017, 0);
  }
  // RavenShield.exe @ 10903bb2 : RethrowFeedbackMapCheckClearPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903bc6 : UnwindFeedbackMapCheckClearFailure
  // Append the native method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackMapCheckClearGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918aec : g_feedbackMapCheckClearUnwind
const NativeCppUnwindEntry g_feedbackMapCheckClearUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918afc : g_feedbackMapCheckClearCatches
const NativeCppCatchHandler g_feedbackMapCheckClearCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10903bb2}, // RethrowFeedbackMapCheckClearPointer
    {0, 0, 0, 0x10903bc6},                                               // UnwindFeedbackMapCheckClearFailure
};

// RavenShield.exe data @ 10918b1c : g_feedbackMapCheckClearTryBlocks
const NativeCppTryBlock g_feedbackMapCheckClearTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackMapCheckClearCatches)},
};

// RavenShield.exe data @ 10918b30 : g_feedbackMapCheckClearExceptionInfo
const NativeCppFunctionInfo g_feedbackMapCheckClearExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackMapCheckClearUnwind), 1, NativeAddress(g_feedbackMapCheckClearTryBlocks),
    0,          0};

// RavenShield.exe @ 10912250 : HandleFeedbackMapCheckClearException
// Supply MapCheck_Clear's two-state pointer/catch-all guard map with no cleanup actions.
__declspec(naked) void HandleFeedbackMapCheckClearException()
{
  __asm {
    mov eax, offset g_feedbackMapCheckClearExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915240 : g_feedbackBeginSlowTaskGuardName
const char16_t g_feedbackBeginSlowTaskGuardName[] = u"FFeedbackContextWindows::BeginSlowTask";
// RavenShield.exe data @ 10915290 : g_feedbackEndSlowTaskGuardName
const char16_t g_feedbackEndSlowTaskGuardName[] = u"FFeedbackContextWindows::EndSlowTask";
// RavenShield.exe data @ 109152dc : g_feedbackPositiveTaskCountExpression
const char g_feedbackPositiveTaskCountExpression[] = "SlowTaskCount>0";
// RavenShield.exe data @ 109152ec : g_feedbackSourcePath
const char g_feedbackSourcePath[] = "..\\..\\Core\\Inc\\FFeedbackContextWindows.h";

// RavenShield.exe @ 10903c00 : FFeedbackContextWindows::BeginSlowTask
// Show progress, set text/range and pump Unicode messages before incrementing the task count; StatusWindow is ignored.
void FFeedbackContextWindows::BeginSlowTask(const uint16_t *task, int32_t statusWindow)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    ShowWindow(*reinterpret_cast<const uint32_t *>(object + 0x10), 5);
    if (*reinterpret_cast<const uint32_t *>(object + 8) != 0 && *reinterpret_cast<const uint32_t *>(object + 0xc) != 0)
    {
      if (GUnicodeOS != 0)
      {
        SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0xc), 0xc, 0, reinterpret_cast<int32_t>(task));
      }
      else
      {
        char *buffer = nullptr;
        if (winGetSizeANSI(task) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(task)) + 7) & 0xfffffff8;
          bytes = (bytes + 3) & 0xfffffffc;
          buffer = reinterpret_cast<char *>(_alloca(bytes)); // Native probes this method's stack; no heap ownership.
        }
        const int32_t count = winGetSizeANSI(task);
        char *converted = winToANSI(buffer, task, count);
        SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0xc), 0xc, 0, reinterpret_cast<int32_t>(converted));
      }
      if (GUnicodeOS != 0)
        SendMessageW(*reinterpret_cast<const uint32_t *>(object + 8), 0x401, 0, 0x640000);
      else
        SendMessageA(*reinterpret_cast<const uint32_t *>(object + 8), 0x401, 0, 0x640000);
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 0x10));
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 0xc));
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 0xc)); // Native repeats the text window here.
      uint32_t message[7]; // Uninitialized x86 MSG, 28 bytes; every iteration reloads the progress-dialog handle.
      while (PeekMessageW(message, *reinterpret_cast<const uint32_t *>(object + 0x10), 0, 0, 1) != 0)
      {
        TranslateMessage(message);
        DispatchMessageW(message); // Unicode pump is unconditional, including the ANSI text path.
      }
    }
    ++*reinterpret_cast<uint32_t *>(object + 4);
    GIsSlowTask = *reinterpret_cast<const int32_t *>(object + 4) > 0 ? 1 : 0;
  }
  // RavenShield.exe @ 10903dcc : RethrowFeedbackBeginSlowTaskPointer
  // Copy-throw the caught pointer from parent EBP-30 into a new throw object at EBP-34.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903de0 : UnwindFeedbackBeginSlowTaskFailure
  // Append the BeginSlowTask guard and rethrow without reversing window changes or partial task state.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackBeginSlowTaskGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918b4c : g_feedbackBeginSlowTaskUnwind
const NativeCppUnwindEntry g_feedbackBeginSlowTaskUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918b5c : g_feedbackBeginSlowTaskCatches
const NativeCppCatchHandler g_feedbackBeginSlowTaskCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x30, 0x10903dcc}, // RethrowFeedbackBeginSlowTaskPointer
    {0, 0, 0, 0x10903de0},                                               // UnwindFeedbackBeginSlowTaskFailure
};

// RavenShield.exe data @ 10918b7c : g_feedbackBeginSlowTaskTryBlocks
const NativeCppTryBlock g_feedbackBeginSlowTaskTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackBeginSlowTaskCatches)},
};

// RavenShield.exe data @ 10918b90 : g_feedbackBeginSlowTaskExceptionInfo
const NativeCppFunctionInfo g_feedbackBeginSlowTaskExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackBeginSlowTaskUnwind), 1, NativeAddress(g_feedbackBeginSlowTaskTryBlocks),
    0,          0};

// RavenShield.exe @ 10912260 : HandleFeedbackBeginSlowTaskException
// Supply BeginSlowTask's two-state pointer/catch-all guard map without owned local cleanup.
__declspec(naked) void HandleFeedbackBeginSlowTaskException()
{
  __asm {
    mov eax, offset g_feedbackBeginSlowTaskExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10903e20 : FFeedbackContextWindows::EndSlowTask
// Assert a positive task count, decrement with wrapping, publish signed positivity and hide the dialog when inactive.
void FFeedbackContextWindows::EndSlowTask()
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    if (*reinterpret_cast<const int32_t *>(object + 4) <= 0)
      appFailAssert(g_feedbackPositiveTaskCountExpression, g_feedbackSourcePath, 0x73);
    --*reinterpret_cast<uint32_t *>(object + 4); // Reload after a returning assertion; do not clamp an invalid count.
    GIsSlowTask = *reinterpret_cast<const int32_t *>(object + 4) > 0 ? 1 : 0;
    if (GIsSlowTask == 0) ShowWindow(*reinterpret_cast<const uint32_t *>(object + 0x10), 0);
  }
  // RavenShield.exe @ 10903ea8 : RethrowFeedbackEndSlowTaskPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10903ebc : UnwindFeedbackEndSlowTaskFailure
  // Append the EndSlowTask guard and rethrow without restoring the counter, global flag or dialog visibility.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackEndSlowTaskGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918bac : g_feedbackEndSlowTaskUnwind
const NativeCppUnwindEntry g_feedbackEndSlowTaskUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918bbc : g_feedbackEndSlowTaskCatches
const NativeCppCatchHandler g_feedbackEndSlowTaskCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10903ea8}, // RethrowFeedbackEndSlowTaskPointer
    {0, 0, 0, 0x10903ebc},                                               // UnwindFeedbackEndSlowTaskFailure
};

// RavenShield.exe data @ 10918bdc : g_feedbackEndSlowTaskTryBlocks
const NativeCppTryBlock g_feedbackEndSlowTaskTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackEndSlowTaskCatches)},
};

// RavenShield.exe data @ 10918bf0 : g_feedbackEndSlowTaskExceptionInfo
const NativeCppFunctionInfo g_feedbackEndSlowTaskExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackEndSlowTaskUnwind), 1, NativeAddress(g_feedbackEndSlowTaskTryBlocks), 0, 0};

// RavenShield.exe @ 10912270 : HandleFeedbackEndSlowTaskException
// Supply EndSlowTask's two-state pointer/catch-all guard map without cleanup actions.
__declspec(naked) void HandleFeedbackEndSlowTaskException()
{
  __asm {
    mov eax, offset g_feedbackEndSlowTaskExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FOutputDevice;
extern FOutputDevice *GLog;
using FeedbackOutputLogf = void(__cdecl *)(FOutputDevice *, int32_t, const uint16_t *, ...);
extern int32_t GIsClient;
extern int32_t GIsEditor;
extern const uint16_t *__cdecl LocalizeError(const char *key, const uint16_t *package, const uint16_t *language);
extern int32_t __cdecl appGetVarArgs(uint16_t *buffer, int32_t capacity, const uint16_t *&formatSlot);
extern "C" int32_t __stdcall MessageBoxW(uint32_t window, const uint16_t *text, const uint16_t *caption,
                                         uint32_t flags);

// RavenShield.exe data @ 10914f48 : g_feedbackLocalizationPackage
extern const char16_t g_feedbackLocalizationPackage[] = u"Core";
// RavenShield.exe data @ 10915048 : g_feedbackSerializeGuardName
const char16_t g_feedbackSerializeGuardName[] = u"FFeedbackContextWindows::Serialize";
// RavenShield.exe data @ 10915090 : g_feedbackWarningKey
const char g_feedbackWarningKey[] = "Warning";
// RavenShield.exe data @ 10915098 : g_feedbackYesNofGuardName
const char16_t g_feedbackYesNofGuardName[] = u"FFeedbackContextWindows::YesNof";
// RavenShield.exe data @ 109150d8 : g_feedbackQuestionKey
const char g_feedbackQuestionKey[] = "Question";
// RavenShield.exe data @ 10915318 : g_feedbackStatusUpdateGuardName
const char16_t g_feedbackStatusUpdateGuardName[] = u"FFeedbackContextWindows::StatusUpdatef";
// RavenShield.exe data @ 10915890 : g_feedbackMapCheckAddGuardName
const char16_t g_feedbackMapCheckAddGuardName[] = u"FFeedbackContextWindows::MapCheck_Add";

// RavenShield.exe @ 10903710 : FFeedbackContextWindows::Serialize
// Show client/editor UserPrompt events in a Unicode task-modal box; route all other events to the warning logger.
void FFeedbackContextWindows::Serialize(const uint16_t *text, int32_t event)
{
  try
  {
    if (event == 0x31a && (GIsClient != 0 || GIsEditor != 0))
    { // NAME_UserPrompt.
      const uint16_t *caption = LocalizeError(
          g_feedbackWarningKey, reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr);
      MessageBoxW(0, text, caption, 0x2000); // MB_OK | MB_TASKMODAL, independent of GUnicodeOS.
    }
    else
    {
      FOutputDevice *output = GLog;
      const auto logf =
          *reinterpret_cast<const FeedbackOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
      logf(output, 0x2ff, reinterpret_cast<const uint16_t *>(g_unwindContextFormat), text); // NAME_Warning.
    }
  }
  // RavenShield.exe @ 109037ab : RethrowFeedbackSerializePointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109037bf : UnwindFeedbackSerializeFailure
  // Append the Serialize guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackSerializeGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091890c : g_feedbackSerializeUnwind
const NativeCppUnwindEntry g_feedbackSerializeUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091891c : g_feedbackSerializeCatches
const NativeCppCatchHandler g_feedbackSerializeCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x109037ab}, // RethrowFeedbackSerializePointer
    {0, 0, 0, 0x109037bf},                                               // UnwindFeedbackSerializeFailure
};

// RavenShield.exe data @ 1091893c : g_feedbackSerializeTryBlocks
const NativeCppTryBlock g_feedbackSerializeTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackSerializeCatches)},
};

// RavenShield.exe data @ 10918950 : g_feedbackSerializeExceptionInfo
const NativeCppFunctionInfo g_feedbackSerializeExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackSerializeUnwind), 1, NativeAddress(g_feedbackSerializeTryBlocks), 0, 0};

// RavenShield.exe @ 10912200 : HandleFeedbackSerializeException
// Supply Serialize's two-state pointer/catch-all guard map without local cleanup actions.
__declspec(naked) void HandleFeedbackSerializeException()
{
  __asm {
    mov eax, offset g_feedbackSerializeExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10903800 : FFeedbackContextWindows::YesNof
// Format before the guard, then ask a client/editor Unicode yes/no question and return full-width normalized success.
int32_t __cdecl FFeedbackContextWindows::YesNof(const uint16_t *format, ...)
{
  uint16_t text[0x1000];               // Native uninitialized 8192-byte buffer at parent EBP-2010.
  appGetVarArgs(text, 0x1000, format); // Pass the address of the actual format slot preceding the variadic words.
  try
  {
    if (GIsClient != 0 || GIsEditor != 0)
    {
      const uint16_t *caption = LocalizeError(
          g_feedbackQuestionKey, reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr);
      return MessageBoxW(0, text, caption, 0x2004) == 6 ? 1 : 0; // MB_YESNO | MB_TASKMODAL, IDYES.
    }
    return 0;
  }
  // RavenShield.exe @ 109038a2 : RethrowFeedbackYesNofPointer
  // Copy-throw the caught pointer from parent EBP-2014 into a new throw object at EBP-2018.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109038bf : UnwindFeedbackYesNofFailure
  // Append the YesNof guard and rethrow; exceptions from the initial formatter bypass this guard.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackYesNofGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091896c : g_feedbackYesNofUnwind
const NativeCppUnwindEntry g_feedbackYesNofUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091897c : g_feedbackYesNofCatches
const NativeCppCatchHandler g_feedbackYesNofCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x2014, 0x109038a2}, // RethrowFeedbackYesNofPointer
    {0, 0, 0, 0x109038bf},                                                 // UnwindFeedbackYesNofFailure
};

// RavenShield.exe data @ 1091899c : g_feedbackYesNofTryBlocks
const NativeCppTryBlock g_feedbackYesNofTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackYesNofCatches)},
};

// RavenShield.exe data @ 109189b0 : g_feedbackYesNofExceptionInfo
const NativeCppFunctionInfo g_feedbackYesNofExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackYesNofUnwind), 1, NativeAddress(g_feedbackYesNofTryBlocks), 0, 0};

// RavenShield.exe @ 10912210 : HandleFeedbackYesNofException
// Supply YesNof's two-state guard map; the formatter runs while the native state is still -1.
__declspec(naked) void HandleFeedbackYesNofException()
{
  __asm {
    mov eax, offset g_feedbackYesNofExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10903ef0 : FFeedbackContextWindows::StatusUpdatef
// Format under the guard, update active progress UI, pump Unicode messages and return one on every normal path.
int32_t __cdecl FFeedbackContextWindows::StatusUpdatef(int32_t numerator, int32_t denominator, const uint16_t *format,
                                                       ...)
{
  try
  {
    uint16_t text[0x1000];
    appGetVarArgs(text, 0x1000, format);
    auto *object = reinterpret_cast<uint8_t *>(this);
    if (GIsSlowTask != 0 && *reinterpret_cast<const uint32_t *>(object + 8) != 0 &&
        *reinterpret_cast<const uint32_t *>(object + 0xc) != 0)
    {
      if (GUnicodeOS != 0)
      {
        SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0xc), 0xc, 0, reinterpret_cast<int32_t>(text));
      }
      else
      {
        char *buffer = nullptr;
        if (winGetSizeANSI(text) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(text)) + 7) & 0xfffffff8;
          bytes = (bytes + 3) & 0xfffffffc;
          buffer = reinterpret_cast<char *>(_alloca(bytes));
        }
        const int32_t count = winGetSizeANSI(text);
        char *converted = winToANSI(buffer, text, count);
        SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0xc), 0xc, 0, reinterpret_cast<int32_t>(converted));
      }
      const int32_t unicode = GUnicodeOS; // Capture the second API choice before its arithmetic, as in native code.
      uint32_t position = 0;
      if (denominator != 0)
      {
        __asm {
          mov eax, numerator
          imul eax, eax, 100
          cdq
          idiv denominator
          mov position, eax
        } // Wrapped signed product and native IDIV, including its INT_MIN/-1 overflow fault.
      }
      if (unicode != 0)
        SendMessageW(*reinterpret_cast<const uint32_t *>(object + 8), 0x402, position, 0);
      else
        SendMessageA(*reinterpret_cast<const uint32_t *>(object + 8), 0x402, position, 0);
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 0x10));
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 0xc));
      UpdateWindow(*reinterpret_cast<const uint32_t *>(object + 8));
      uint32_t message[7]; // Uninitialized x86 MSG at parent EBP-202c.
      while (PeekMessageW(message, *reinterpret_cast<const uint32_t *>(object + 0x10), 0, 0, 1) != 0)
      {
        TranslateMessage(message);
        DispatchMessageW(message);
      }
    }
    return 1;
  }
  // RavenShield.exe @ 10904150 : RethrowFeedbackStatusUpdatePointer
  // Copy-throw the caught pointer from parent EBP-2030 into a new throw object at EBP-2034.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090416d : UnwindFeedbackStatusUpdateFailure
  // Append the StatusUpdatef guard and rethrow without reversing UI changes or altering task counts.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackStatusUpdateGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918c0c : g_feedbackStatusUpdateUnwind
const NativeCppUnwindEntry g_feedbackStatusUpdateUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918c1c : g_feedbackStatusUpdateCatches
const NativeCppCatchHandler g_feedbackStatusUpdateCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x2030, 0x10904150}, // RethrowFeedbackStatusUpdatePointer
    {0, 0, 0, 0x1090416d},                                                 // UnwindFeedbackStatusUpdateFailure
};

// RavenShield.exe data @ 10918c3c : g_feedbackStatusUpdateTryBlocks
const NativeCppTryBlock g_feedbackStatusUpdateTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_feedbackStatusUpdateCatches)},
};

// RavenShield.exe data @ 10918c50 : g_feedbackStatusUpdateExceptionInfo
const NativeCppFunctionInfo g_feedbackStatusUpdateExceptionInfo = {
    0x19930520, 2, NativeAddress(g_feedbackStatusUpdateUnwind), 1, NativeAddress(g_feedbackStatusUpdateTryBlocks),
    0,          0};

// RavenShield.exe @ 10912280 : HandleFeedbackStatusUpdateException
// Supply StatusUpdatef's two-state pointer/catch-all guard map without local cleanup callbacks.
__declspec(naked) void HandleFeedbackStatusUpdateException()
{
  __asm {
    mov eax, offset g_feedbackStatusUpdateExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10905600 : FFeedbackContextWindows::MapCheck_Add
// Build an owned message packet, send its stack address synchronously, then destroy the message before guard exit.
void FFeedbackContextWindows::MapCheck_Add(int32_t type, void *actor, const uint16_t *message)
{
  try
  {
    MAPCHECK check; // Message default construction precedes the scalar stores and text assignment.
    check.Type = type;
    check.Actor = actor;
    check.Message = message;
    const auto *object = reinterpret_cast<const uint8_t *>(this);
    if (GUnicodeOS != 0)
      SendMessageW(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8018,
                   reinterpret_cast<int32_t>(&check));
    else
      SendMessageA(*reinterpret_cast<const uint32_t *>(object + 0x14), 0x111, 0x8018,
                   reinterpret_cast<int32_t>(&check));
  }
  // RavenShield.exe @ 109056a9 : RethrowFeedbackMapCheckAddPointer
  // Copy-throw the caught pointer from parent EBP-28 into a new throw object at EBP-2c after packet cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109056bd : UnwindFeedbackMapCheckAddFailure
  // Append the MapCheck_Add guard and rethrow after any constructed packet message is released.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_feedbackMapCheckAddGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912370 : DestroyFeedbackMapCheckPacketOnUnwind
// Destroy the constructed packet at parent EBP-24 by tail-transferring to its message-owning destructor.
__declspec(naked) void DestroyFeedbackMapCheckPacketOnUnwind()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp MAPCHECK::~MAPCHECK
  }
}

// RavenShield.exe data @ 10918ed4 : g_feedbackMapCheckAddUnwind
const NativeCppUnwindEntry g_feedbackMapCheckAddUnwind[3] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_DestroyFeedbackMapCheckPacketOnUnwind)}, // DestroyFeedbackMapCheckPacketOnUnwind
    {-1, 0},
};

// RavenShield.exe data @ 10918eec : g_feedbackMapCheckAddCatches
const NativeCppCatchHandler g_feedbackMapCheckAddCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x28, 0x109056a9}, // RethrowFeedbackMapCheckAddPointer
    {0, 0, 0, 0x109056bd},                                               // UnwindFeedbackMapCheckAddFailure
};

// RavenShield.exe data @ 10918f0c : g_feedbackMapCheckAddTryBlocks
const NativeCppTryBlock g_feedbackMapCheckAddTryBlocks[1] = {
    {0, 1, 2, 2, NativeAddress(g_feedbackMapCheckAddCatches)},
};

// RavenShield.exe data @ 10918f20 : g_feedbackMapCheckAddExceptionInfo
const NativeCppFunctionInfo g_feedbackMapCheckAddExceptionInfo = {
    0x19930520, 3, NativeAddress(g_feedbackMapCheckAddUnwind), 1, NativeAddress(g_feedbackMapCheckAddTryBlocks), 0, 0};

// RavenShield.exe @ 10912378 : HandleFeedbackMapCheckAddException
// Supply MapCheck_Add's three-state guard map, including the constructed packet's cleanup action.
__declspec(naked) void HandleFeedbackMapCheckAddException()
{
  __asm {
    mov eax, offset g_feedbackMapCheckAddExceptionInfo
    jmp DispatchExecutableCppException
  }
}
