#include "native_symbols.hpp"
// Executable forwarding bodies for the imported Core file-manager base interface.
#include <cstdint>

class FFileManager;

// RavenShield.exe @ 10911b66 : FFileManager::Init
// Tail-forward the inherited initialization slot, preserving the ECX receiver and one signed stack argument.
__declspec(naked) void FFileManager::Init(int32_t startup)
{
  __asm jmp dword ptr [NativeImport_FFileManager_Init]
}
