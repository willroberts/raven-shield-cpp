#include "native_symbols.hpp"
// Native 0x24-byte config pairs: FString key at +4 and FConfigSection value at +10.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include <new>

// RavenShield.exe @ 1090dae0 : TMapBase<FString, FConfigSection>::TPair::~TPair
// Destroy Value (+10) then Key (+4), also destroying Key if value destruction throws.
template <> TMapBase<FString, FConfigSection>::TPair::~TPair() noexcept(false) = default;

// RavenShield.exe @ 1090db30 : TArray<TMapBase<FString, FConfigSection>::TPair>::Remove
// Assert the native index bounds, destroy the selected pairs in ascending order, then compact the base array.
template <> void TArray<TMapBase<FString, FConfigSection>::TPair>::Remove(int32_t index, int32_t count)
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
    uint32_t offset = static_cast<uint32_t>(index) * 0x24;
    uint32_t remaining = static_cast<uint32_t>(end) - static_cast<uint32_t>(index);
    do
    {
      const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
      reinterpret_cast<TMapBase<FString, FConfigSection>::TPair *>(address)->~TPair();
      offset += 0x24;
      --remaining;
    } while (remaining != 0);
  }
  FArray::Remove(index, count, 0x24); // Still called for zero/negative counts if assertions return.
}

// RavenShield.exe @ 1090dbd0 : TArray<TMapBase<FString, FConfigSection>::TPair>::~TArray
// Remove every pair; automatic FArray base destruction runs normally and if Remove throws.
template <> TArray<TMapBase<FString, FConfigSection>::TPair>::~TArray() noexcept(false)
{
  Remove(0, *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 4));
}

// RavenShield.exe @ 1090dc20 : TMapBase<FString, FConfigSection>::~TMapBase
// Free and clear the hash; automatic Pairs member destruction also runs if freeing the hash throws.
template <> TMapBase<FString, FConfigSection>::~TMapBase() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = *reinterpret_cast<const uint32_t *>(object + 0xc);
  if (hash != 0) FreeExecutableAllocation(reinterpret_cast<void *>(hash));
  *reinterpret_cast<uint32_t *>(object + 0xc) = 0;
  *reinterpret_cast<uint32_t *>(object + 0x10) = 0;
} // Pairs at +0 is destroyed after this body, matching the native clear-before-array order.

// RavenShield.exe @ 1090dc90 : ForwardFConfigSectionMapDestruction
// Tail-forward ECX to the one canonical map destruction body, preserving native register and stack state.
__declspec(naked) void ForwardFConfigSectionMapDestruction()
{
  __asm jmp NativeEntry_TMapBase_FString_FConfigSection_DestroyTMapBase
}

// RavenShield.exe @ 10912da0 : UnwindFConfigSectionMapPairs
// Destroy the map's completed pair array if hash deallocation throws, using the runtime parent's EBP-10 slot.
__declspec(naked) void UnwindFConfigSectionMapPairs()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp NativeEntry_TArray_TMapBase_FString_FConfigSection_TPair_DestroyTArray
  }
}

// RavenShield.exe data @ 1091abbc : g_fConfigSectionMapDestructionUnwind
const NativeCppUnwindEntry g_fConfigSectionMapDestructionUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindFConfigSectionMapPairs)}, // UnwindFConfigSectionMapPairs
};

// RavenShield.exe data @ 1091abc4 : g_fConfigSectionMapDestructionExceptionInfo
const NativeCppFunctionInfo g_fConfigSectionMapDestructionExceptionInfo = {
    0x19930520, 1, NativeAddress(g_fConfigSectionMapDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912da8 : HandleFConfigSectionMapDestructionException
// Dispatch shared pair-array cleanup for map destruction and FConfigFile default/copy construction.
__declspec(naked) void HandleFConfigSectionMapDestructionException()
{
  __asm {
    mov eax, offset g_fConfigSectionMapDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// Inlined iterator operations in the config writer: native fields are Map +0, Pairs +4, Index +8 and Removed +c.
template <>
TMapBase<FString, FConfigSection>::TIterator::TIterator(TMapBase &map)
    : Map(map), Pairs(map.Pairs), Index(0), Removed(0)
{
}

// Test the current signed index against the imported, reloaded pair count.
template <> TMapBase<FString, FConfigSection>::TIterator::operator int32_t() const
{
  return Index < Pairs.Num();
}

// Advance the native iterator word with x86 wrap, retaining its stored index for exception cleanup.
template <> void TMapBase<FString, FConfigSection>::TIterator::operator++()
{
  Index = static_cast<int32_t>(static_cast<uint32_t>(Index) + 1);
}

// Return the current pair's key without adding bounds checks to the native inlined access.
template <> FString &TMapBase<FString, FConfigSection>::TIterator::Key() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x24 + 4;
  return *reinterpret_cast<FString *>(address);
}

// Return the current pair's value at +10, using the same native pair stride.
template <> FConfigSection &TMapBase<FString, FConfigSection>::TIterator::Value() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x24 + 0x10;
  return *reinterpret_cast<FConfigSection *>(address);
}

// RavenShield.exe @ 1090f640 : TMapBase<FString, FConfigSection>::Relax
// Halve oversized hash counts toward twice the current pair count plus eight, then always rebuild the hash.
template <> void TMapBase<FString, FConfigSection>::Relax()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *pairs = reinterpret_cast<FArray *>(this);
  int32_t &hashCount = *reinterpret_cast<int32_t *>(object + 0x10);
  for (;;)
  {
    const uint32_t count = static_cast<uint32_t>(pairs->Num());
    const int32_t threshold = static_cast<int32_t>(count * 2 + 8);
    if (hashCount <= threshold) break;
    hashCount /= 2; // Signed division truncates toward zero, matching CDQ/SUB/SAR in the native body.
  }
  Rehash();
}

// RavenShield.exe @ 1090f730 : TMapBase<FString, FConfigSection>::TIterator::~TIterator
// Relax the referenced map only if the iterator records removals.
template <> TMapBase<FString, FConfigSection>::TIterator::~TIterator() noexcept(false)
{
  if (Removed != 0) Map.Relax();
}

// RavenShield.exe @ 1090f680 : TMapBase<FString, FConfigSection>::Rehash
// Rebuild bucket heads and pair links before freeing the old hash; count validity and allocation success are unchecked.
template <> void TMapBase<FString, FConfigSection>::Rehash()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t bytes = *reinterpret_cast<const uint32_t *>(object + 0x10) << 2;
  FMalloc *allocator = GMalloc;
  const uint32_t allocationTable = *reinterpret_cast<const uint32_t *>(allocator);
  const auto allocate = *reinterpret_cast<const NativeAllocate *>(allocationTable);
  auto *heads =
      reinterpret_cast<uint32_t *>(allocate(allocator, bytes, reinterpret_cast<const uint16_t *>(g_configMapHashTag)));
  for (int32_t bucket = 0; bucket < *reinterpret_cast<const int32_t *>(object + 0x10); ++bucket)
    heads[bucket] = 0xffffffff;
  auto *pairs = reinterpret_cast<FArray *>(this);
  int32_t index = 0;
  uint32_t pairOffset = 0;
  if (pairs->Num() > 0)
  {
    do
    {
      const uint32_t pairAddress = *reinterpret_cast<const uint32_t *>(object) + pairOffset;
      auto *pair = reinterpret_cast<uint8_t *>(pairAddress);
      const uint16_t *key = reinterpret_cast<FString *>(pair + 4)->operator*();
      const uint32_t hash = HashCaseInsensitiveUtf16(key);
      const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
      *reinterpret_cast<uint32_t *>(pair) = heads[bucket];
      pairOffset += 0x24;
      heads[bucket] = static_cast<uint32_t>(index);
      ++index;
    } while (index < pairs->Num()); // Reload the imported Num result after every linked pair.
  }
  const uint32_t oldHash = *reinterpret_cast<const uint32_t *>(object + 0xc);
  if (oldHash != 0)
  {
    allocator = GMalloc;
    const uint32_t freeTable = *reinterpret_cast<const uint32_t *>(allocator);
    const auto free = *reinterpret_cast<const NativeFree *>(freeTable + 8);
    free(allocator, reinterpret_cast<void *>(oldHash));
  }
  *reinterpret_cast<uint32_t *>(object + 0xc) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(heads));
}

// Inlined into FConfigFile construction 10910300: finish the pair array before allocating the eight-bucket hash.
template <> TMapBase<FString, FConfigSection>::TMapBase() : Pairs(), Hash(nullptr), HashCount(8)
{
  Rehash(); // If this throws, the shared 10912da8 handler destroys only the completed pair array.
}

// RavenShield.exe @ 10910650 : TArray<TMapBase<FString, FConfigSection>::TPair>::TArray
// Reserve source-count storage, reset Num, and copy pairs in order; a failed copy releases only the raw FArray base.
template <>
TArray<TMapBase<FString, FConfigSection>::TPair>::TArray(const TArray &other)
    : FArray(*reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(&other) + 4), 0x24)
{
  using Pair = TMapBase<FString, FConfigSection>::TPair;
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  *reinterpret_cast<int32_t *>(destination + 4) = 0;
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 0x24);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 0x24;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) Pair(*reinterpret_cast<const Pair *>(sourceAddress));
    }
    ++index;
    offset += 0x24;
  }
} // Construction failure runs FArray destruction, without destroying previously copied Pair elements.

// Inlined by native copy construction: copy Pairs before allocating a distinct hash with the source bucket count.
template <>
TMapBase<FString, FConfigSection>::TMapBase(const TMapBase &other)
    : Pairs(other.Pairs), Hash(nullptr), HashCount(other.HashCount)
{
  Rehash(); // If rebuilding fails, the completed Pairs member destroys its copied elements.
}

// RavenShield.exe @ 10910480 : TMapBase<FString, FConfigSection>::TPair::TPair
// Copy HashNext, then Key and Value; completed subobjects unwind in reverse order on a later failure.
template <>
TMapBase<FString, FConfigSection>::TPair::TPair(const TPair &other)
    : HashNext(other.HashNext), Key(other.Key), Value(other.Value)
{
}

// RavenShield.exe @ 1090ff80 : TArray<TMapBase<FString, FConfigSection>::TPair>::Empty
// Destroy current section pairs in order, reloading count/data, then empty the base array with the supplied slack.
template <> void TArray<TMapBase<FString, FConfigSection>::TPair>::Empty(int32_t slack)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(object + 4))
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    reinterpret_cast<TMapBase<FString, FConfigSection>::TPair *>(address)->~TPair();
    ++index;
    offset += 0x24;
  }
  FArray::Empty(0x24, slack);
}

// RavenShield.exe @ 10910410 : TArray<TMapBase<FString, FConfigSection>::TPair>::operator=
// Retain self-assignment; otherwise empty with source-count slack and append copied pairs without rollback cleanup.
template <>
TArray<TMapBase<FString, FConfigSection>::TPair> &
TArray<TMapBase<FString, FConfigSection>::TPair>::operator=(const TArray &other)
{
  if (this == &other) return *this;
  using Pair = TMapBase<FString, FConfigSection>::TPair;
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  Empty(*reinterpret_cast<const int32_t *>(source + 4));
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 0x24);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 0x24;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) Pair(*reinterpret_cast<const Pair *>(sourceAddress));
    }
    ++index;
    offset += 0x24;
  }
  return *this;
}

// RavenShield.exe @ 10912d80 : UnwindCopiedConfigSectionPairKey
// Destroy the completed copied key from the pair pointer saved at runtime parent EBP-10.
__declspec(naked) void UnwindCopiedConfigSectionPairKey()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 4
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912d8c : UnwindCopiedConfigSectionEntries
// Destroy the completed entry array from parent EBP+4 when the inlined entry-map hash rebuild throws.
__declspec(naked) void UnwindCopiedConfigSectionEntries()
{
  __asm {
    mov ecx, [ebp+4]
    jmp NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray
  }
}

// RavenShield.exe data @ 1091ab6c : g_configSectionPairCopyUnwind
const NativeCppUnwindEntry g_configSectionPairCopyUnwind[2] = {
    {-1, NativeAddress(NativeEntry_UnwindCopiedConfigSectionPairKey)}, // UnwindCopiedConfigSectionPairKey
    {0, NativeAddress(NativeEntry_UnwindCopiedConfigSectionEntries)},  // UnwindCopiedConfigSectionEntries
};

// RavenShield.exe data @ 1091ab7c : g_configSectionPairCopyExceptionInfo
const NativeCppFunctionInfo g_configSectionPairCopyExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configSectionPairCopyUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912d94 : HandleConfigSectionPairCopyException
// Supply the copied-key and completed-entry-array unwind states to shared C++ exception dispatch.
__declspec(naked) void HandleConfigSectionPairCopyException()
{
  __asm {
    mov eax, offset g_configSectionPairCopyExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090eca0 : TMapBase<FString, FConfigSection>::Find
// Follow the section name's hash chain and return the first equal key's value; reload pair data after comparison calls.
template <> FConfigSection *TMapBase<FString, FConfigSection>::Find(const FString &key)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = HashCaseInsensitiveUtf16(*key);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  int32_t index = *reinterpret_cast<const int32_t *>(heads + bucket * 4);
  while (index != -1)
  {
    const uint32_t offset = static_cast<uint32_t>(index) * 0x24;
    uint32_t data = *reinterpret_cast<const uint32_t *>(object);
    if (reinterpret_cast<const FString *>(data + offset + 4)->operator==(key) != 0)
    {
      data = *reinterpret_cast<const uint32_t *>(object);
      return reinterpret_cast<FConfigSection *>(data + offset + 0x10);
    }
    data = *reinterpret_cast<const uint32_t *>(object);
    index = *reinterpret_cast<const int32_t *>(data + offset);
  }
  return nullptr;
}

// RavenShield.exe @ 1090ffc0 : TMapBase<FString, FConfigSection>::Set
// Assign the first matching section or append a new name/section pair, returning its value reference.
template <> FConfigSection &TMapBase<FString, FConfigSection>::Set(const uint16_t *key, const FConfigSection &value)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = HashCaseInsensitiveUtf16(key);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  int32_t index = *reinterpret_cast<const int32_t *>(heads + bucket * 4);
  while (index != -1)
  {
    const uint32_t offset = static_cast<uint32_t>(index) * 0x24;
    uint32_t data = *reinterpret_cast<const uint32_t *>(object);
    if (reinterpret_cast<const FString *>(data + offset + 4)->operator==(key) != 0)
    {
      data = *reinterpret_cast<const uint32_t *>(object);
      *reinterpret_cast<FConfigSection *>(data + offset + 0x10) = value;
      data = *reinterpret_cast<const uint32_t *>(object);
      return *reinterpret_cast<FConfigSection *>(data + offset + 0x10);
    }
    data = *reinterpret_cast<const uint32_t *>(object);
    index = *reinterpret_cast<const int32_t *>(data + offset);
  }
  return Add(key, value); // Native append boundary 10910160; it owns pair construction and hash growth.
}

// RavenShield.exe @ 10910160 : TMapBase<FString, FConfigSection>::Add
// Append and construct a section pair, link it into the current bucket, then grow/rebuild an overloaded hash.
template <> FConfigSection &TMapBase<FString, FConfigSection>::Add(const uint16_t *key, const FConfigSection &value)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *pairs = reinterpret_cast<FArray *>(this);
  const int32_t index = pairs->Add(1, 0x24); // Num increases before construction, including construction failure.
  const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + static_cast<uint32_t>(index) * 0x24;
  if (address != 0) new (reinterpret_cast<void *>(address)) TPair(key, value);
  const uint16_t *storedKey = reinterpret_cast<FString *>(address + 4)->operator*();
  const uint32_t hash = HashCaseInsensitiveUtf16(storedKey);
  uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  *reinterpret_cast<uint32_t *>(address) = *reinterpret_cast<const uint32_t *>(heads + bucket * 4);
  const uint32_t lastIndex = static_cast<uint32_t>(pairs->Num()) - 1;
  heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  *reinterpret_cast<uint32_t *>(heads + bucket * 4) = lastIndex;
  const uint32_t oldHashCount = *reinterpret_cast<const uint32_t *>(object + 0x10);
  if (static_cast<int32_t>(oldHashCount * 2 + 8) < pairs->Num())
  {
    *reinterpret_cast<uint32_t *>(object + 0x10) = oldHashCount * 2;
    Rehash(); // Pair construction and bucket insertion are not rolled back if this throws.
  }
  return *reinterpret_cast<FConfigSection *>(address + 0x10);
}

// Inlined by Read: discard section pairs before resetting the bucket count and rebuilding the hash.
template <> void TMapBase<FString, FConfigSection>::Empty()
{
  Pairs.Empty(0);
  HashCount = 8;
  Rehash();
}

// RavenShield.exe @ 109101f0 : TMapBase<FString, FConfigSection>::TPair::TPair
// Construct Key, then copy the entry map into Value; HashNext is installed only after this constructor returns.
template <>
TMapBase<FString, FConfigSection>::TPair::TPair(const uint16_t *key, const FConfigSection &value)
    : Key(key), Value(value)
{
  // Shared handler 10912d94 cleans Key and any completed entry array if Value's hash construction fails.
}
