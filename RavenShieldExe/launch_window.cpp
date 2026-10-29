#include "native_symbols.hpp"
// Window callbacks in the restored original executable code; native addresses retain the selected Steam image base.
#include "cpp_exception_metadata.hpp"
#include <cstdint>
#include "launch_runtime.hpp"

extern "C" void __stdcall PostQuitMessage(int32_t exitCode);
using StartupDialogCallback = int32_t(__stdcall *)(uint32_t, uint32_t, uint32_t, int32_t);
extern "C" uint32_t __stdcall CreateDialogParamW(uint32_t instance, const uint16_t *resource, uint32_t parent,
                                                 StartupDialogCallback callback, int32_t value);
extern "C" uint32_t __stdcall CreateDialogParamA(uint32_t instance, const char *resource, uint32_t parent,
                                                 StartupDialogCallback callback, int32_t value);
extern "C" uint32_t __stdcall GetDlgItem(uint32_t window, int32_t identifier);
extern "C" int32_t __stdcall GetSystemMetrics(int32_t metric);
extern "C" int32_t __stdcall SetWindowPos(uint32_t window, uint32_t insertAfter, int32_t x, int32_t y, int32_t width,
                                          int32_t height, uint32_t flags);
extern "C" int32_t __stdcall SendMessageW(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall SendMessageA(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall UpdateWindow(uint32_t window);
extern "C" int32_t __stdcall GetMessageW(void *message, uint32_t window, uint32_t minimum, uint32_t maximum);
extern "C" int32_t __stdcall GetMessageA(void *message, uint32_t window, uint32_t minimum, uint32_t maximum);
extern "C" int32_t __stdcall DispatchMessageW(const void *message);
extern "C" int32_t __stdcall DispatchMessageA(const void *message);
extern "C" int32_t __stdcall PostThreadMessageW(uint32_t thread, uint32_t message, uint32_t wParam, int32_t lParam);
extern "C" int32_t __stdcall PostThreadMessageA(uint32_t thread, uint32_t message, uint32_t wParam, int32_t lParam);
extern int32_t GUnicodeOS; // Core.dll imported data.
extern int32_t GIsEditor;  // Core.dll imported data.
using StartupThreadProcedure = uint32_t(__stdcall *)(uint32_t);
extern "C" uint32_t __stdcall CreateThread(void *attributes, uint32_t stackSize, StartupThreadProcedure procedure,
                                           uint32_t argument, uint32_t flags, uint32_t *threadId);
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);

// Imported Window.dll contract: native constructor/destructor accesses confirm all four x86 words.
class __declspec(dllimport) FWindowsBitmap
{
public:
  int32_t SizeX, SizeY, Keep; // +0, +4, +8; Keep suppresses handle deletion on destruction.
  FWindowsBitmap(int32_t keep);
  ~FWindowsBitmap();
  int32_t LoadFile(const uint16_t *filename);
  uint32_t GetBitmapHandle();

private:
  uint32_t hBitmap; // +12.
};

extern "C" void DispatchExecutableCppException(); // EAX carries the native FuncInfo pointer.

// RavenShield.exe data @ 10914750 : g_startupBitmapLoadExpression
const char g_startupBitmapLoadExpression[] = "Bitmap.LoadFile(Filename)";

// RavenShield.exe data @ 1091f100 : g_startupDialogInstance
uint32_t g_startupDialogInstance = 0;
// RavenShield.exe data @ 1091f104 : g_startupDialogWindow
uint32_t g_startupDialogWindow = 0;
// RavenShield.exe data @ 1091f108 : g_startupDialogBitmap
uint32_t g_startupDialogBitmap = 0;
// RavenShield.exe data @ 1091f10c : g_startupDialogWidth
int32_t g_startupDialogWidth = 0;
// RavenShield.exe data @ 1091f110 : g_startupDialogHeight
int32_t g_startupDialogHeight = 0;
// RavenShield.exe data @ 1091f114 : g_startupDialogThreadId
uint32_t g_startupDialogThreadId = 0;
// RavenShield.exe data @ 1091f118 : g_startupDialogThreadHandle
uint32_t g_startupDialogThreadHandle = 0;

// RavenShield.exe @ 10901000 : StartupDialogProcedure
// Post a zero-status quit message on WM_DESTROY and return zero for every dialog message.
int32_t __stdcall StartupDialogProcedure(uint32_t window, uint32_t message, uint32_t wParam, int32_t lParam)
{
  if (message == 2) PostQuitMessage(0);
  return 0;
}

// RavenShield.exe @ 10901020 : RunStartupDialogThread
// Create and center the startup bitmap dialog, then dispatch messages until GetMessage returns exactly zero.
uint32_t __stdcall RunStartupDialogThread(uint32_t ignoredValue)
{
  uint32_t dialog;
  if (GUnicodeOS != 0)
    dialog = CreateDialogParamW(g_startupDialogInstance, reinterpret_cast<const uint16_t *>(0x77), 0,
                                StartupDialogProcedure, 0);
  else
    dialog =
        CreateDialogParamA(g_startupDialogInstance, reinterpret_cast<const char *>(0x77), 0, StartupDialogProcedure, 0);
  g_startupDialogWindow = dialog;
  if (g_startupDialogWindow == 0) return 0;
  const uint32_t bitmapControl = GetDlgItem(g_startupDialogWindow, 0x400);
  if (bitmapControl == 0) return 0;
  const int32_t height = g_startupDialogHeight;
  const int32_t width = g_startupDialogWidth;
  const int32_t screenHeight = GetSystemMetrics(1);
  const int32_t y =
      static_cast<int32_t>(static_cast<uint32_t>(screenHeight) - static_cast<uint32_t>(g_startupDialogHeight)) / 2;
  const int32_t screenWidth = GetSystemMetrics(0);
  const int32_t x =
      static_cast<int32_t>(static_cast<uint32_t>(screenWidth) - static_cast<uint32_t>(g_startupDialogWidth)) / 2;
  SetWindowPos(g_startupDialogWindow, 0xffffffff, x, y, width, height, 0x40);
  SetWindowPos(g_startupDialogWindow, 0xfffffffe, 0, 0, 0, 0, 3);
  if (GUnicodeOS != 0)
    SendMessageW(bitmapControl, 0x172, 0, static_cast<int32_t>(g_startupDialogBitmap));
  else
    SendMessageA(bitmapControl, 0x172, 0, static_cast<int32_t>(g_startupDialogBitmap));
  UpdateWindow(g_startupDialogWindow);
  uint32_t message[7]; // Raw 28-byte x86 MSG storage; entry contents are not initialized.
  for (;;)
  {
    const int32_t received = GUnicodeOS != 0 ? GetMessageW(message, 0, 0, 0) : GetMessageA(message, 0, 0, 0);
    if (received == 0) break;
    if (GUnicodeOS != 0)
      DispatchMessageW(message);
    else
      DispatchMessageA(message);
  }
  return 0;
}

// RavenShield.exe @ 109011c0 : InitializeStartupDialog
// In editor mode, optionally load a retained bitmap and start the dialog thread without checking creation success.
void __cdecl InitializeStartupDialog(const uint16_t *filename)
{
  if (GIsEditor == 0) return;
  FWindowsBitmap bitmap(1); // Local at native EBP-1c; Keep=1 leaves the handle alive after this scope.
  if (filename != nullptr)
  {
    if (bitmap.LoadFile(filename) == 0) appFailAssert(g_startupBitmapLoadExpression, g_unEngineWinSourcePath, 0x42);
    g_startupDialogBitmap = bitmap.GetBitmapHandle(); // Continue if the assertion returns.
    g_startupDialogWidth = bitmap.SizeX;
    g_startupDialogHeight = bitmap.SizeY;
  }
  g_startupDialogThreadHandle = CreateThread(nullptr, 0, RunStartupDialogThread, 0, 0, &g_startupDialogThreadId);
} // Destroy the local bitmap on normal exit and on exceptions after its constructor returns.

// RavenShield.exe @ 10912090 : UnwindStartupDialogBitmap
// Destroy the initializer's live bitmap using the parent's EBP, tail-transferring to its imported destructor.
__declspec(naked) void UnwindStartupDialogBitmap()
{
  __asm {
    lea ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FWindowsBitmapDestroy] // Window.dll FWindowsBitmap::~FWindowsBitmap IAT slot.
  }
}

// RavenShield.exe data @ 10918538 : g_startupDialogUnwind
const NativeCppUnwindEntry g_startupDialogUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindStartupDialogBitmap)}, // UnwindStartupDialogBitmap
};

// RavenShield.exe data @ 10918540 : g_startupDialogExceptionInfo
const NativeCppFunctionInfo g_startupDialogExceptionInfo = {0x19930520, 1, NativeAddress(g_startupDialogUnwind), 0, 0,
                                                            0,          0};

// RavenShield.exe @ 10912099 : HandleStartupDialogException
// Supply the initializer's FuncInfo in EAX and preserve the runtime's stack-based exception arguments.
__declspec(naked) void HandleStartupDialogException()
{
  __asm {
    // Native map 10918538 releases the bitmap through landing 10912090.
    mov eax, offset g_startupDialogExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10901290 : RequestStartupDialogQuit
// Post WM_QUIT to a recorded startup thread only in editor mode, ignoring the post result.
void __cdecl RequestStartupDialogQuit()
{
  if (GIsEditor != 0 && g_startupDialogThreadId != 0)
  {
    if (GUnicodeOS != 0)
      PostThreadMessageW(g_startupDialogThreadId, 0x12, 0, 0);
    else
      PostThreadMessageA(g_startupDialogThreadId, 0x12, 0, 0);
  }
}
