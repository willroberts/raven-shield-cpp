#include "native_symbols.hpp"
// Native 12-byte FString arrays used by file enumeration and launcher callers.
#include "container_support.hpp"
#include <new>

// RavenShield.exe @ 10907a40 : TArray<FString>::TIterator::operator*
// Return the current string's 12-byte slot without validating the index or array count.
template <> FString &TArray<FString>::TIterator::operator*() const
{
  const auto *state = reinterpret_cast<const uint32_t *>(this);
  const uint32_t data = *reinterpret_cast<const uint32_t *>(state[0]);
  return *reinterpret_cast<FString *>(data + state[1] * 12u);
}

// RavenShield.exe @ 1090ac10 : TArray<FString>::TArray
// Reserve source-count storage, then grow the count before each deep copy; construction failure frees only the base.
template <>
TArray<FString>::TArray(const TArray &other)
    : FArray(*reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(&other) + 4), 12)
{
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  *reinterpret_cast<int32_t *>(destination + 4) = 0;
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 12);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 12u;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) FString(*reinterpret_cast<const FString *>(sourceAddress));
    }
    ++index;
    offset += 12u;
  }
} // Base-only unwind 10912660 and handler 10912669 remain canonical in container_support.cpp.

// RavenShield.exe @ 10904430 : AllocateStringArraySlot
// Ignore the placement size, append one 12-byte element, and return its unchecked address.
void *__cdecl AllocateStringArraySlot(uint32_t ignoredSize, TArray<FString> *array)
{
  const auto add =
      *reinterpret_cast<const int32_t(__thiscall **)(void *, int32_t, int32_t)>(NativeAddress(NativeImport_FArray_Add));
  const int32_t slot = add(array, 1, 12);
  const uint32_t data = *reinterpret_cast<const uint32_t *>(array);
  return reinterpret_cast<void *>(data + static_cast<uint32_t>(slot) * 12u);
}

// RavenShield.exe @ 109043a0 : TArray<FString>::operator()
// Return the selected 12-byte string slot without checking bounds, count or capacity.
template <> FString &TArray<FString>::operator()(int32_t index)
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(this);
  return *reinterpret_cast<FString *>(data + static_cast<uint32_t>(index) * 12u);
}

// RavenShield.exe @ 10907bb0 : TArray<FString>::Remove
// Check the native range, destroy selected strings in ascending order, then compact the base array.
template <> void TArray<FString>::Remove(int32_t index, int32_t count)
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
    uint32_t offset = static_cast<uint32_t>(index) * 12u;
    uint32_t remaining = static_cast<uint32_t>(end) - static_cast<uint32_t>(index);
    do
    {
      const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
      reinterpret_cast<FString *>(address)->~FString();
      offset += 12u;
      --remaining;
    } while (remaining != 0);
  }
  FArray::Remove(index, count, 12); // Still called for zero/negative counts if assertions return.
}

// RavenShield.exe @ 10907fc0 : TArray<FString>::~TArray
// Remove every string; automatic FArray destruction also runs if removing a string throws.
template <> TArray<FString>::~TArray() noexcept(false)
{
  Remove(0, *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 4));
} // Shared unwind 10912660 and handler 10912669 are canonical in container_support.cpp.

// RavenShield.exe @ 1090a660 : TArray<FString>::Empty
// Destroy strings in ascending order, then empty the base array with the requested slack.
template <> void TArray<FString>::Empty(int32_t slack)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(object + 4))
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    reinterpret_cast<FString *>(address)->~FString();
    ++index;
    offset += 12u;
  }
  FArray::Empty(12, slack);
}

// RavenShield.exe @ 1090a5f0 : TArray<FString>::operator=
// Retain self-assignment; otherwise reserve source-count slack and append deep copies without rollback cleanup.
template <> TArray<FString> &TArray<FString>::operator=(const TArray &other)
{
  if (this == &other) return *this;
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  Empty(*reinterpret_cast<const int32_t *>(source + 4));
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 12);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 12u;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) FString(*reinterpret_cast<const FString *>(sourceAddress));
    }
    ++index;
    offset += 12u;
  }
  return *this;
}
