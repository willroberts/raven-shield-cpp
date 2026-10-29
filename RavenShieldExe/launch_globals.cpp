#include "native_symbols.hpp"
// Selected executable launch data; native UTF-16 storage is explicit rather than host-dependent wchar_t.
#include "launch_runtime.hpp"

// RavenShield.exe data @ 1091476c : g_unEngineWinSourcePath
const char g_unEngineWinSourcePath[] = "..\\..\\Engine\\Inc\\UnEngineWin.h";

// RavenShield.exe data @ 10914920 : g_unwindContextFormat
// Format the guard name appended by shared native unwind paths.
extern const char16_t g_unwindContextFormat[] = u"%s";

// RavenShield.exe data @ 1091f030 : GPackage
// Hold the exported launch package name; native spacing and the UE2 Launch declaration support 64 UTF-16 units.
extern "C"
{
  uint16_t GPackage[64] = {'L', 'a', 'u', 'n', 'c', 'h', 0};
}
