#include "native_symbols.hpp"
// Shared object-iterator bodies; Class at +0 and Index at +4 are corroborated by UE2 UnObjBas.h.
#include "object_support.hpp"
#include "container_support.hpp"

// RavenShield.exe data @ 10916198 : g_objectIteratorClassExpression
const char g_objectIteratorClassExpression[] = "Class";

// Initialize the two native words, assert the selected class, then seek the first matching object.
// Source-only constructor for the six native inlined initializations; no separate native entry is identified.
FObjectIterator::FObjectIterator(UClass *type)
{
  auto *state = reinterpret_cast<uint32_t *>(this);
  state[0] = reinterpret_cast<uint32_t>(type);
  state[1] = 0xffffffffu;
  if (!type) appFailAssert(g_objectIteratorClassExpression, g_constructObjectSourcePath, 0x49b);
  ++*this;
}

// RavenShield.exe @ 10902990 : FObjectIterator::operator int32_t
// Query the live object-array count, then reload Index and return a full-width signed-comparison result.
FObjectIterator::operator int32_t()
{
  const void *objects = *reinterpret_cast<const void **>(NativeAddress(NativeImport_UObject_GObjObjects));
  const auto num = *reinterpret_cast<int32_t(__thiscall **)(const void *)>(NativeAddress(NativeImport_FArray_Num));
  const int32_t count = num(objects);
  return reinterpret_cast<const int32_t *>(this)[1] < count ? 1 : 0;
}

// RavenShield.exe @ 10904b60 : FObjectIterator::operator++
// Advance with wrapping until the captured index reaches Num or names a nonnull object of the selected class.
void FObjectIterator::operator++()
{
  auto *state = reinterpret_cast<uint32_t *>(this);
  const auto &num = *reinterpret_cast<int32_t(__thiscall **)(const void *)>(NativeAddress(NativeImport_FArray_Num));
  const auto &isA =
      *reinterpret_cast<int32_t(__thiscall **)(const UObject *, UClass *)>(NativeAddress(NativeImport_UObject_IsA));
  for (;;)
  {
    const uint32_t index = ++state[1];
    const void *objects = *reinterpret_cast<const void **>(NativeAddress(NativeImport_UObject_GObjObjects));
    if (static_cast<int32_t>(index) >= num(objects)) return;
    const auto *array = *reinterpret_cast<const uint32_t **>(NativeAddress(NativeImport_UObject_GObjObjects));
    UObject *object = *reinterpret_cast<UObject **>(array[0] + index * 4u);
    if (object && isA(object, reinterpret_cast<UClass *>(state[0])) != 0) return;
  }
}

// RavenShield.exe @ 10907a50 : FObjectIterator::operator*
// Return the unchecked current object; dereference and arrow specializations share this one native body.
UObject *FObjectIterator::operator*()
{
  const uint32_t index = reinterpret_cast<const uint32_t *>(this)[1];
  const auto *array = *reinterpret_cast<const uint32_t **>(NativeAddress(NativeImport_UObject_GObjObjects));
  return *reinterpret_cast<UObject **>(array[0] + index * 4u);
}
