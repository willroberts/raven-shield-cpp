#include "native_symbols.hpp"
// Native 0x1c-byte config pairs: FString key at +4 and FString value at +10.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include <new>

// RavenShield.exe @ 109043c0 : TMapBase<FString, FString>::TPair::~TPair
// Destroy Value (+10) then Key (+4), also destroying Key if value destruction throws.
template <> TMapBase<FString, FString>::TPair::~TPair() noexcept(false) = default;

// RavenShield.exe @ 10908010 : TArray<TMapBase<FString, FString>::TPair>::Remove
// Assert the native index bounds, destroy the selected pairs in ascending order, then compact the base array.
template <> void TArray<TMapBase<FString, FString>::TPair>::Remove(int32_t index, int32_t count)
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
    uint32_t offset = static_cast<uint32_t>(index) * 0x1c;
    uint32_t remaining = static_cast<uint32_t>(end) - static_cast<uint32_t>(index);
    do
    {
      const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
      reinterpret_cast<TMapBase<FString, FString>::TPair *>(address)->~TPair();
      offset += 0x1c;
      --remaining;
    } while (remaining != 0);
  }
  FArray::Remove(index, count, 0x1c); // Still called for zero/negative counts if assertions return.
}

// RavenShield.exe @ 1090aca0 : TArray<TMapBase<FString, FString>::TPair>::~TArray
// Remove every pair; automatic FArray base destruction runs normally and if Remove throws.
template <> TArray<TMapBase<FString, FString>::TPair>::~TArray() noexcept(false)
{
  Remove(0, *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 4));
}

// RavenShield.exe @ 1090b1c0 : TMapBase<FString, FString>::~TMapBase
// Free and clear the hash; automatic Pairs member destruction also runs if freeing the hash throws.
template <> TMapBase<FString, FString>::~TMapBase() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = *reinterpret_cast<const uint32_t *>(object + 0xc);
  if (hash != 0) FreeExecutableAllocation(reinterpret_cast<void *>(hash));
  *reinterpret_cast<uint32_t *>(object + 0xc) = 0;
  *reinterpret_cast<uint32_t *>(object + 0x10) = 0;
} // Pairs at +0 is destroyed after this body, matching the native clear-before-array order.

// RavenShield.exe @ 1090dad0 : ForwardFStringMapDestruction
// Tail-forward ECX to the one canonical map destruction body, preserving native register and stack state.
__declspec(naked) void ForwardFStringMapDestruction()
{
  __asm jmp NativeEntry_TMapBase_FString_FString_DestroyTMapBase
}

// RavenShield.exe @ 10912710 : UnwindFStringMapPairs
// Destroy the map's completed pair array if hash deallocation throws, using the runtime parent's EBP-10 slot.
__declspec(naked) void UnwindFStringMapPairs()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray
  }
}

// RavenShield.exe data @ 10919ba0 : g_fStringMapDestructionUnwind
const NativeCppUnwindEntry g_fStringMapDestructionUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindFStringMapPairs)}, // UnwindFStringMapPairs
};

// RavenShield.exe data @ 10919ba8 : g_fStringMapDestructionExceptionInfo
const NativeCppFunctionInfo g_fStringMapDestructionExceptionInfo = {
    0x19930520, 1, NativeAddress(g_fStringMapDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912718 : HandleFStringMapDestructionException
// Dispatch shared pair-array cleanup for entry-map destruction and default construction.
__declspec(naked) void HandleFStringMapDestructionException()
{
  __asm {
    mov eax, offset g_fStringMapDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// Inlined iterator operations in the config writer: native fields are Map +0, Pairs +4, Index +8 and Removed +c.
template <>
TMapBase<FString, FString>::TIterator::TIterator(TMapBase &map) : Map(map), Pairs(map.Pairs), Index(0), Removed(0)
{
}

// Test the current signed index against the imported, reloaded pair count.
template <> TMapBase<FString, FString>::TIterator::operator int32_t() const
{
  return Index < Pairs.Num();
}

// Advance the native iterator word with x86 wrap, retaining its stored index for exception cleanup.
template <> void TMapBase<FString, FString>::TIterator::operator++()
{
  Index = static_cast<int32_t>(static_cast<uint32_t>(Index) + 1);
}

// Return the current pair's key without adding bounds checks to the native inlined access.
template <> FString &TMapBase<FString, FString>::TIterator::Key() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x1c + 4;
  return *reinterpret_cast<FString *>(address);
}

// Return the current pair's value at +10, using the same native pair stride.
template <> FString &TMapBase<FString, FString>::TIterator::Value() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x1c + 0x10;
  return *reinterpret_cast<FString *>(address);
}

// RavenShield.exe @ 1090f740 : TMapBase<FString, FString>::Relax
// Halve oversized hash counts toward twice the current pair count plus eight, then always rebuild the hash.
template <> void TMapBase<FString, FString>::Relax()
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

// RavenShield.exe @ 1090f830 : TMapBase<FString, FString>::TIterator::~TIterator
// Relax the referenced map only if the iterator records removals.
template <> TMapBase<FString, FString>::TIterator::~TIterator() noexcept(false)
{
  if (Removed != 0) Map.Relax();
}

// RavenShield.exe @ 1090f780 : TMapBase<FString, FString>::Rehash
// Rebuild bucket heads and pair links before freeing the old hash; count validity and allocation success are unchecked.
template <> void TMapBase<FString, FString>::Rehash()
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
      pairOffset += 0x1c;
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

// RavenShield.exe @ 10910270 : TArray<TMapBase<FString, FString>::TPair>::TArray
// Reserve source-count storage, reset Num, and copy pairs in order; a failed copy releases only the raw FArray base.
template <>
TArray<TMapBase<FString, FString>::TPair>::TArray(const TArray &other)
    : FArray(*reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(&other) + 4), 0x1c)
{
  using Pair = TMapBase<FString, FString>::TPair;
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  *reinterpret_cast<int32_t *>(destination + 4) = 0;
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 0x1c);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 0x1c;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) Pair(*reinterpret_cast<const Pair *>(sourceAddress));
    }
    ++index;
    offset += 0x1c;
  }
} // Construction failure runs FArray destruction, without destroying previously copied Pair elements.

// Inlined by native copy construction: copy Pairs before allocating a distinct hash with the source bucket count.
template <>
TMapBase<FString, FString>::TMapBase(const TMapBase &other)
    : Pairs(other.Pairs), Hash(nullptr), HashCount(other.HashCount)
{
  Rehash(); // If rebuilding fails, the completed Pairs member destroys its copied elements.
}

// RavenShield.exe @ 109100c0 : TMapBase<FString, FString>::TPair::TPair
// Copy HashNext, then Key and Value; completed subobjects unwind in reverse order on a later failure.
template <>
TMapBase<FString, FString>::TPair::TPair(const TPair &other)
    : HashNext(other.HashNext), Key(other.Key), Value(other.Value)
{
}

// RavenShield.exe @ 1090fe90 : TMapBase<FString, FString>::Add
// Append and construct a entry pair, link it into the current bucket, then grow/rebuild an overloaded hash.
template <> FString &TMapBase<FString, FString>::Add(const uint16_t *key, const uint16_t *value)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *pairs = reinterpret_cast<FArray *>(this);
  const int32_t index = pairs->Add(1, 0x1c); // Num increases before construction, including construction failure.
  const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + static_cast<uint32_t>(index) * 0x1c;
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
  return *reinterpret_cast<FString *>(address + 0x10);
}

// RavenShield.exe @ 10910120 : TArray<TMapBase<FString, FString>::TPair>::Empty
// Destroy current entry pairs in order, reloading count/data, then empty the base array with the supplied slack.
template <> void TArray<TMapBase<FString, FString>::TPair>::Empty(int32_t slack)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(object + 4))
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    reinterpret_cast<TMapBase<FString, FString>::TPair *>(address)->~TPair();
    ++index;
    offset += 0x1c;
  }
  FArray::Empty(0x1c, slack);
}

// RavenShield.exe @ 10910050 : TArray<TMapBase<FString, FString>::TPair>::operator=
// Retain self-assignment; otherwise empty with source-count slack and append copied pairs without rollback cleanup.
template <>
TArray<TMapBase<FString, FString>::TPair> &TArray<TMapBase<FString, FString>::TPair>::operator=(const TArray &other)
{
  if (this == &other) return *this;
  using Pair = TMapBase<FString, FString>::TPair;
  auto *destination = reinterpret_cast<uint8_t *>(this);
  const auto *source = reinterpret_cast<const uint8_t *>(&other);
  Empty(*reinterpret_cast<const int32_t *>(source + 4));
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(source + 4))
  {
    const int32_t slot = FArray::Add(1, 0x1c);
    const uint32_t address = *reinterpret_cast<const uint32_t *>(destination) + static_cast<uint32_t>(slot) * 0x1c;
    if (address != 0)
    {
      const uint32_t sourceAddress = *reinterpret_cast<const uint32_t *>(source) + offset;
      new (reinterpret_cast<void *>(address)) Pair(*reinterpret_cast<const Pair *>(sourceAddress));
    }
    ++index;
    offset += 0x1c;
  }
  return *this;
}

// RavenShield.exe @ 1090ff20 : TMapBase<FString, FString>::TPair::TPair
// Construct Key before Value from UTF-16 text pointers; leave HashNext untouched until Add links the pair.
template <>
TMapBase<FString, FString>::TPair::TPair(const uint16_t *key, const uint16_t *value) : Key(key), Value(value)
{
  // Shared 10912d6c key cleanup also serves this constructor if Value construction throws.
}

// RavenShield.exe @ 10910c00 : TMapBase<FString, FString>::TMapBase
// Build the pair array before allocating eight hash buckets; also inlined in Read's temporary section construction.
template <> TMapBase<FString, FString>::TMapBase() : Pairs(), Hash(nullptr), HashCount(8)
{
  Rehash();
}

// Inlined by section-map Set: assign entries first, then copy HashCount and rebuild even on self-assignment.
template <> TMapBase<FString, FString> &TMapBase<FString, FString>::operator=(const TMapBase &other)
{
  Pairs = other.Pairs;
  HashCount = other.HashCount;
  Rehash();
  return *this;
}

// RavenShield.exe @ 1090ec30 : TMapBase<FString, FString>::Find
// Follow the entry key's hash chain and return the first equal key's value; reload pair data after comparison calls.
template <> FString *TMapBase<FString, FString>::Find(const FString &key)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = HashCaseInsensitiveUtf16(*key);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  int32_t index = *reinterpret_cast<const int32_t *>(heads + bucket * 4);
  while (index != -1)
  {
    const uint32_t offset = static_cast<uint32_t>(index) * 0x1c;
    uint32_t data = *reinterpret_cast<const uint32_t *>(object);
    if (reinterpret_cast<const FString *>(data + offset + 4)->operator==(key) != 0)
    {
      data = *reinterpret_cast<const uint32_t *>(object);
      return reinterpret_cast<FString *>(data + offset + 0x10);
    }
    data = *reinterpret_cast<const uint32_t *>(object);
    index = *reinterpret_cast<const int32_t *>(data + offset);
  }
  return nullptr;
}

// Inlined by EmptySection: destroy pairs before resetting the bucket count and replacing the hash allocation.
template <> void TMapBase<FString, FString>::Empty()
{
  Pairs.Empty(0);
  HashCount = 8;
  Rehash();
}
