#include "native_symbols.hpp"
// Inherited notify-hook methods tail-forward directly to Core.dll with their original receiver and arguments.
#include <cstdint>

class FNotifyHook;

// RavenShield.exe @ 10911b5a : FNotifyHook::NotifyPreChange
// Forward the property/source pointer without adjusting the FNotifyHook receiver or adding work.
__declspec(naked) void FNotifyHook::NotifyPreChange(void *source)
{
  __asm jmp dword ptr [NativeImport_FNotifyHook_NotifyPreChange]
}

// RavenShield.exe @ 10911b54 : FNotifyHook::NotifyPostChange
// Forward the property/source pointer without adjusting the FNotifyHook receiver or adding work.
__declspec(naked) void FNotifyHook::NotifyPostChange(void *source)
{
  __asm jmp dword ptr [NativeImport_FNotifyHook_NotifyPostChange]
}

// RavenShield.exe @ 10911b4e : FNotifyHook::NotifyExec
// Forward the source and command text unchanged to Core's void notification method.
__declspec(naked) void FNotifyHook::NotifyExec(void *source, const uint16_t *command)
{
  __asm jmp dword ptr [NativeImport_FNotifyHook_NotifyExec]
}
