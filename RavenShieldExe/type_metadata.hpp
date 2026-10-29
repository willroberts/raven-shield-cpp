#pragma once
#include <cstdint>

// Source-only MSVC x86 metadata layouts. Address words retain native values, not host pointers/member pointers.
// Descriptor name storage includes its observed terminator/alignment bytes; this does not redefine class type_info.
template <uint32_t NameStorageBytes> struct NativeTypeDescriptor
{
  uint32_t vtableWord;     // +0, points at the observed executable type_info deleting slot.
  uint32_t cachedNameWord; // +4, initially zero; supporting MSVCR71 name/destructor accesses corroborate ownership.
  char decoratedNameStorage[NameStorageBytes]; // +8, exact native raw-name bytes and any included zero alignment.
};

// Signed displacement triples are retained verbatim; field names describe the x86 PMD convention.
struct NativeThisAdjustment
{
  int32_t memberOffset;
  int32_t vbtableOffset;
  int32_t virtualBaseOffset;
};
struct NativeRttiBaseDescriptor
{
  uint32_t typeDescriptorWord;
  uint32_t containedBases;
  NativeThisAdjustment adjustment;
  uint32_t attributes;
};
struct NativeRttiHierarchy
{
  uint32_t signature, attributes, baseCount, baseArrayWord;
};
struct NativeRttiCompleteObjectLocator
{
  uint32_t signature, objectOffset, constructorDisplacement, typeDescriptorWord, hierarchyWord;
};
struct NativeCatchableType
{
  uint32_t properties, typeDescriptorWord;
  NativeThisAdjustment adjustment;
  int32_t objectSize;
  uint32_t copyFunctionWord;
};
template <uint32_t Count> struct NativeCatchableTypeArray
{
  uint32_t count;
  uint32_t typeWords[Count];
};
struct NativeThrowInfo
{
  uint32_t attributes, unwindFunctionWord, forwardCompatibilityWord, catchableTypeArrayWord;
};
