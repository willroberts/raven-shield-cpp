#include "native_symbols.hpp"
// Launcher/window helper shared by native class-name callers; all text is native 16-bit UTF-16.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"

extern const uint16_t *__cdecl appPackage();
extern int32_t __cdecl appSprintf(uint16_t *result, const uint16_t *format, ...);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 109153b4 : g_windowClassGuardName
const char16_t g_windowClassGuardName[] = u"MakeWindowClassName";
// RavenShield.exe data @ 109153dc : g_windowClassFormat
const char16_t g_windowClassFormat[] = u"%sUnreal%s";

// RavenShield.exe @ 10904310 : MakeWindowClassName
// Format package + Unreal + base without a length bound; preserve pointer exceptions and annotate other failures.
void __cdecl MakeWindowClassName(uint16_t *result, const uint16_t *base)
{
  try
  {
    const uint16_t *package = appPackage();
    appSprintf(result, reinterpret_cast<const uint16_t *>(g_windowClassFormat), package, base);
  }
  // RavenShield.exe @ 10904366 : RethrowWindowClassNamePointer
  // Throw a copy of the caught unsigned-short pointer, rather than rethrowing the original exception object.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090437a : UnwindWindowClassNameFailure
  // Append the helper name to the unwind trace and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_windowClassGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918c6c : g_windowClassNameUnwind
const NativeCppUnwindEntry g_windowClassNameUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918c7c : g_windowClassNameCatches
const NativeCppCatchHandler g_windowClassNameCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x10904366}, // RethrowWindowClassNamePointer
    {0, 0, 0, 0x1090437a},                                               // UnwindWindowClassNameFailure
};

// RavenShield.exe data @ 10918c9c : g_windowClassNameTryBlocks
const NativeCppTryBlock g_windowClassNameTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_windowClassNameCatches)},
};

// RavenShield.exe data @ 10918cb0 : g_windowClassNameExceptionInfo
const NativeCppFunctionInfo g_windowClassNameExceptionInfo = {
    0x19930520, 2, NativeAddress(g_windowClassNameUnwind), 1, NativeAddress(g_windowClassNameTryBlocks), 0, 0};

// RavenShield.exe @ 10912290 : HandleWindowClassNameException
// Supply the helper's two-catch FuncInfo in EAX and tail-transfer to shared C++ dispatch.
__declspec(naked) void HandleWindowClassNameException()
{
  __asm {
    mov eax, offset g_windowClassNameExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern const char16_t g_launcherStartupPackage[];

// RavenShield.exe @ 10901c20 : GetLauncherWindowPackageName
// Return the shared Startup package pointer for several launcher-window GetPackageName overrides; ECX is unused.
__declspec(naked) const uint16_t *GetLauncherWindowPackageName()
{
  __asm {
    push ebp
    mov ebp, esp
    push ecx
    mov [ebp-4], ecx
    mov eax, offset g_launcherStartupPackage
    mov esp, ebp
    pop ebp
    ret
  }
}
