#pragma once
#include <cstdint>

class FMalloc;
extern FMalloc *GMalloc; // Core.dll imported data; reload at each native allocation/free site.
using NativeAllocate = void *(__thiscall *)(FMalloc *, uint32_t, const uint16_t *);
using NativeFree = void(__thiscall *)(FMalloc *, void *);
extern const char16_t g_executableAllocationTag[];
void *__cdecl AllocateExecutableBytes(uint32_t size);
void __cdecl FreeExecutableAllocation(void *allocation);
uint32_t __cdecl HashCaseInsensitiveUtf16(const uint16_t *text);
uint32_t __cdecl Align(uint32_t value, uint32_t alignment);
int32_t __cdecl MaxSigned(int32_t first, int32_t second);
int32_t __cdecl MinSigned(int32_t first, int32_t second);
uint32_t __cdecl MinUnsigned(uint32_t first, uint32_t second);
void __cdecl CopyExecutableMemory(void *destination, const void *source, uint32_t count);
void *__cdecl AllocateTaggedExecutableBytes(uint32_t size, const uint16_t *tag);
