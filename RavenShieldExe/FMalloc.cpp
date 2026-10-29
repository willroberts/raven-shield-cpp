#include "native_symbols.hpp"
// Executable forwarding body for the imported allocator base query.
#include <cstdint>

class FMalloc;

// RavenShield.exe @ 10911b60 : FMalloc::GetMemoryBlockSize
// Tail-forward this and the allocation pointer to Core.dll's base query, preserving the full signed EAX result.
__declspec(naked) int32_t FMalloc::GetMemoryBlockSize(void *allocation)
{
  __asm jmp dword ptr [NativeImport_FMalloc_GetMemoryBlockSize]
}
