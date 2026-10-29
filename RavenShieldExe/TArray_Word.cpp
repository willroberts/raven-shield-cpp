#include "native_symbols.hpp"
// Canonical four-byte element indexing shared by viewport pointers and signed integer statistics.
#include "container_support.hpp"

// RavenShield.exe @ 109043b0 : TArray<T>::operator()
// Return the four-byte element slot with wrapping arithmetic, without checking index or count.
template <class Item> Item &TArray<Item>::operator()(int32_t index)
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(this);
  return *reinterpret_cast<Item *>(data + static_cast<uint32_t>(index) * 4u);
} // This body represents only the native four-byte specializations, including UViewport* and int32_t.
