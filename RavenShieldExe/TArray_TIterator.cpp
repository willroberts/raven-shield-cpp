#include "native_symbols.hpp"
// Canonical iterator bodies shared by native TArray specializations with different element strides.
#include "container_support.hpp"

// RavenShield.exe @ 10907a20 : TArray<T>::TIterator::TIterator
// Store the array reference at +0 and start at index zero at +4; the native constructor returns ECX in EAX.
template <class Item> TArray<Item>::TIterator::TIterator(TArray<Item> &array)
{
  auto *state = reinterpret_cast<uint32_t *>(this);
  state[0] = reinterpret_cast<uint32_t>(&array);
  state[1] = 0;
}

// RavenShield.exe @ 109041d0 : TArray<T>::TIterator::operator++
// Increment the index word with 32-bit wrapping, without checking bounds or returning the iterator.
template <class Item> void TArray<Item>::TIterator::operator++()
{
  ++reinterpret_cast<uint32_t *>(this)[1];
}

// RavenShield.exe @ 109041e0 : TArray<T>::TIterator::operator int32_t
// Query the live array count, reload the signed index, and return full EAX zero/one for index < count.
template <class Item> TArray<Item>::TIterator::operator int32_t() const
{
  const uint32_t array = *reinterpret_cast<const uint32_t *>(this);
  const auto num =
      *reinterpret_cast<const int32_t(__thiscall **)(const void *)>(NativeAddress(NativeImport_FArray_Num));
  const int32_t count = num(reinterpret_cast<const void *>(array));
  const int32_t index = reinterpret_cast<const int32_t *>(this)[1];
  return index < count ? 1 : 0;
}
