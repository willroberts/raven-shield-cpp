#include "native_symbols.hpp"
// Original executable allocation wrappers use the currently imported Core allocator without extra null checks.
#include "allocation_support.hpp"

// RavenShield.exe data @ 10914c18 : g_executableAllocationTag
extern const char16_t g_executableAllocationTag[] = u"new";

// RavenShield.exe @ 10902580 : AllocateExecutableBytes
// Forward a 32-bit byte count to allocator slot zero with the native new-allocation tag.
void *__cdecl AllocateExecutableBytes(uint32_t size)
{
  FMalloc *allocator = GMalloc;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(allocator);
  const auto allocate = *reinterpret_cast<const NativeAllocate *>(table);
  return allocate(allocator, size, reinterpret_cast<const uint16_t *>(g_executableAllocationTag));
}

// RavenShield.exe @ 109025a0 : FreeExecutableAllocation
// Forward the pointer, including null, to slot two of the current allocator.
void __cdecl FreeExecutableAllocation(void *allocation)
{
  FMalloc *allocator = GMalloc;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(allocator);
  const auto free = *reinterpret_cast<const NativeFree *>(table + 8);
  free(allocator, allocation);
}

// RavenShield.exe @ 10904b30 : Align
// Round using the native wrapped power-of-two mask formula without checking the alignment.
uint32_t __cdecl Align(uint32_t value, uint32_t alignment)
{
  return (value + alignment - 1) & ~(alignment - 1);
}

// RavenShield.exe @ 10904b50 : MaxSigned
// Select the larger signed 32-bit counter, retaining the first argument on equality.
int32_t __cdecl MaxSigned(int32_t first, int32_t second)
{
  return first >= second ? first : second;
}

// RavenShield.exe @ 10904fe0 : MinUnsigned
// Limit a copy length with an unsigned comparison, retaining the first argument on equality.
uint32_t __cdecl MinUnsigned(uint32_t first, uint32_t second)
{
  return first <= second ? first : second;
}

// RavenShield.exe @ 10906030 : AllocateTaggedExecutableBytes
// Forward a size and caller-supplied tag to the current allocator's slot zero, preserving the pointer result.
void *__cdecl AllocateTaggedExecutableBytes(uint32_t size, const uint16_t *tag)
{
  FMalloc *allocator = GMalloc;
  const uint32_t table = *reinterpret_cast<const uint32_t *>(allocator);
  const auto allocate = *reinterpret_cast<const NativeAllocate *>(table);
  return allocate(allocator, size, tag);
}

// RavenShield.exe @ 10905a70 : MinSigned
// Return the smaller signed 32-bit value, retaining the first argument on equality.
int32_t __cdecl MinSigned(int32_t first, int32_t second)
{
  return first <= second ? first : second;
}
