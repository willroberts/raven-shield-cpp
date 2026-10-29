#include "native_symbols.hpp"
// Native registry-array iteration uses a 60-byte entry stride; entry fields remain separately reviewed.
#include "container_support.hpp"

// RavenShield.exe @ 10907a10 : TArray<FRegistryObjectInfo>::TIterator::operator*
// Return the unchecked current registry-record slot using the common array-reference/index state.
template <> FRegistryObjectInfo &TArray<FRegistryObjectInfo>::TIterator::operator*() const
{
  const auto *state = reinterpret_cast<const uint32_t *>(this);
  const uint32_t data = *reinterpret_cast<const uint32_t *>(state[0]);
  return *reinterpret_cast<FRegistryObjectInfo *>(data + state[1] * 60u);
}

// RavenShield.exe @ 10907a60 : TArray<FRegistryObjectInfo>::Remove
// Check the native range, destroy selected registry records in ascending order, then compact the base array.
template <> void TArray<FRegistryObjectInfo>::Remove(int32_t index, int32_t count)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  if (index < 0) appFailAssert(g_arrayRemoveNonnegativeExpression, g_arrayTemplateSourcePath, 0x201);
  if (index > *reinterpret_cast<const int32_t *>(object + 4))
    appFailAssert(g_arrayRemoveIndexExpression, g_arrayTemplateSourcePath, 0x202);
  const int32_t end = static_cast<int32_t>(static_cast<uint32_t>(index) + static_cast<uint32_t>(count));
  if (end > *reinterpret_cast<const int32_t *>(object + 4))
    appFailAssert(g_arrayRemoveEndExpression, g_arrayTemplateSourcePath, 0x203);
  if (index < end)
  {
    uint32_t offset = static_cast<uint32_t>(index) * 60u;
    uint32_t remaining = static_cast<uint32_t>(end) - static_cast<uint32_t>(index);
    do
    {
      const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
      reinterpret_cast<FRegistryObjectInfo *>(address)->~FRegistryObjectInfo();
      offset += 60u;
      --remaining;
    } while (remaining != 0);
  }
  FArray::Remove(index, count, 60); // Still called for zero/negative counts if assertions return.
}

// RavenShield.exe @ 10907e70 : TArray<FRegistryObjectInfo>::~TArray
// Remove every registry record; automatic FArray destruction also runs if removing a registry record throws.
template <> TArray<FRegistryObjectInfo>::~TArray() noexcept(false)
{
  Remove(0, *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 4));
} // Shared unwind 10912660 and handler 10912669 are canonical in container_support.cpp.

// RavenShield.exe @ 109079d0 : TArray<FRegistryObjectInfo>::Empty
// Destroy registry records in ascending order, then empty the base array with the requested slack.
template <> void TArray<FRegistryObjectInfo>::Empty(int32_t slack)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(object + 4))
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    reinterpret_cast<FRegistryObjectInfo *>(address)->~FRegistryObjectInfo();
    ++index;
    offset += 60u;
  }
  FArray::Empty(60, slack);
}
