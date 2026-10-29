#include "native_symbols.hpp"
// Config-file map specialization: FArray at +0, hash pointer +c, count +10, and 2c-byte linked pairs.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include <new>

// Inlined into cache constructor 1090de60: build the array before allocating the initial eight-bucket hash.
template <> TMapBase<FString, FConfigFile>::TMapBase() : Pairs(), Hash(nullptr), HashCount(8)
{
  Rehash(); // If this throws, only Pairs has completed construction; the map destructor must not run.
}

// Inlined iterator operations in Flush: native fields are Map +0, Pairs +4, Index +8 and Removed +c.
template <>
TMapBase<FString, FConfigFile>::TIterator::TIterator(TMapBase &map) : Map(map), Pairs(map.Pairs), Index(0), Removed(0)
{
}

// Test the current signed index against the imported, reloaded pair count.
template <> TMapBase<FString, FConfigFile>::TIterator::operator int32_t() const
{
  return Index < Pairs.Num();
}

// Advance the native iterator word with x86 wrap, retaining its stored index for exception cleanup.
template <> void TMapBase<FString, FConfigFile>::TIterator::operator++()
{
  Index = static_cast<int32_t>(static_cast<uint32_t>(Index) + 1);
}

// Return the current pair's key without adding bounds checks to the native inlined access.
template <> FString &TMapBase<FString, FConfigFile>::TIterator::Key() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x2c + 4;
  return *reinterpret_cast<FString *>(address);
}

// Return the current pair's value at +10, using the same native pair stride.
template <> FConfigFile &TMapBase<FString, FConfigFile>::TIterator::Value() const
{
  const uint32_t data = *reinterpret_cast<const uint32_t *>(&Pairs);
  const uint32_t address = data + static_cast<uint32_t>(Index) * 0x2c + 0x10;
  return *reinterpret_cast<FConfigFile *>(address);
}

// RavenShield.exe @ 1090ed10 : TMapBase<FString, FConfigFile>::Relax
// Halve oversized hash counts toward twice the current pair count plus eight, then always rebuild the hash.
template <> void TMapBase<FString, FConfigFile>::Relax()
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

// RavenShield.exe @ 1090ed50 : TMapBase<FString, FConfigFile>::TIterator::~TIterator
// Relax the referenced map only if the iterator records removals.
template <> TMapBase<FString, FConfigFile>::TIterator::~TIterator() noexcept(false)
{
  if (Removed != 0) Map.Relax();
}

// Inlined by Flush: clear pairs before resetting the count and replacing the hash allocation.
template <> void TMapBase<FString, FConfigFile>::Empty()
{
  Pairs.Empty(0);
  HashCount = 8;
  Rehash();
}

// RavenShield.exe @ 1090f840 : TArray<TMapBase<FString, FConfigFile>::TPair>::Empty
// Destroy pairs in ascending order with a reloaded count, then empty the base array using the requested slack.
template <> void TArray<TMapBase<FString, FConfigFile>::TPair>::Empty(int32_t slack)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  int32_t index = 0;
  uint32_t offset = 0;
  while (index < *reinterpret_cast<const int32_t *>(object + 4))
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    reinterpret_cast<TMapBase<FString, FConfigFile>::TPair *>(address)->~TPair();
    ++index;
    offset += 0x2c;
  }
  FArray::Empty(0x2c, slack);
}

// RavenShield.exe @ 1090f880 : TMapBase<FString, FConfigFile>::Remove
// Remove every matching filename from back to front; relax once after any removal and return the removed count.
template <> int32_t TMapBase<FString, FConfigFile>::Remove(const uint16_t *filename)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *pairs = reinterpret_cast<FArray *>(this);
  int32_t removed = 0;
  int32_t index = static_cast<int32_t>(static_cast<uint32_t>(pairs->Num()) - 1);
  uint32_t offset = static_cast<uint32_t>(index) * 0x2c;
  while (index >= 0)
  {
    const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
    if (reinterpret_cast<const FString *>(address + 4)->operator==(filename) != 0)
    {
      Pairs.Remove(index, 1);
      ++removed;
    }
    --index;
    offset -= 0x2c;
  }
  if (removed != 0) Relax();
  return removed;
}

// RavenShield.exe @ 1090dca0 : TMapBase<FString, FConfigFile>::TPair::~TPair
// Destroy Value (+10) then Key (+4), also destroying Key if value destruction throws.
template <> TMapBase<FString, FConfigFile>::TPair::~TPair() noexcept(false) = default;

// RavenShield.exe @ 1090dcf0 : TArray<TMapBase<FString, FConfigFile>::TPair>::Remove
// Assert the native index bounds, destroy the selected pairs in ascending order, then compact the base array.
template <> void TArray<TMapBase<FString, FConfigFile>::TPair>::Remove(int32_t index, int32_t count)
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
    uint32_t offset = static_cast<uint32_t>(index) * 0x2c;
    uint32_t remaining = static_cast<uint32_t>(end) - static_cast<uint32_t>(index);
    do
    {
      const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + offset;
      reinterpret_cast<TMapBase<FString, FConfigFile>::TPair *>(address)->~TPair();
      offset += 0x2c;
      --remaining;
    } while (remaining != 0);
  }
  FArray::Remove(index, count, 0x2c); // Still called for zero/negative counts if assertions return.
}

// RavenShield.exe @ 1090dd90 : TArray<TMapBase<FString, FConfigFile>::TPair>::~TArray
// Remove every pair; automatic FArray base destruction runs normally and if Remove throws.
template <> TArray<TMapBase<FString, FConfigFile>::TPair>::~TArray() noexcept(false)
{
  Remove(0, *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 4));
}

// RavenShield.exe @ 1090dde0 : TMapBase<FString, FConfigFile>::~TMapBase
// Free and clear the hash; automatic Pairs member destruction also runs if freeing the hash throws.
template <> TMapBase<FString, FConfigFile>::~TMapBase() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = *reinterpret_cast<const uint32_t *>(object + 0xc);
  if (hash != 0) FreeExecutableAllocation(reinterpret_cast<void *>(hash));
  *reinterpret_cast<uint32_t *>(object + 0xc) = 0;
  *reinterpret_cast<uint32_t *>(object + 0x10) = 0;
} // Pairs at +0 is destroyed after this body, matching the native clear-before-array order.

// RavenShield.exe @ 1090de50 : DestroyConfigFileMapThunk
// Tail-forward ECX to the common map destructor without adding a second destruction implementation.
__declspec(naked) void DestroyConfigFileMapThunk()
{
  __asm jmp NativeEntry_TMapBase_FString_FConfigFile_DestroyTMapBase
}

// RavenShield.exe @ 10912ab0 : UnwindConfigMapPairs
// Destroy the completed pair-array member when the map destructor's body throws.
__declspec(naked) void UnwindConfigMapPairs()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp NativeEntry_TArray_TMapBase_FString_FConfigFile_TPair_DestroyTArray
  }
}

// RavenShield.exe data @ 1091a164 : g_configMapDestructionUnwind
const NativeCppUnwindEntry g_configMapDestructionUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindConfigMapPairs)}, // UnwindConfigMapPairs
};

// RavenShield.exe data @ 1091a16c : g_configMapDestructionExceptionInfo
const NativeCppFunctionInfo g_configMapDestructionExceptionInfo = {
    0x19930520, 1, NativeAddress(g_configMapDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912ab8 : HandleConfigMapDestructionException
// Dispatch the map destructor's pair-array cleanup state.
__declspec(naked) void HandleConfigMapDestructionException()
{
  __asm {
    mov eax, offset g_configMapDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10907b00 : TMapBase<FString, FConfigFile>::Rehash
// Rebuild bucket heads and pair links before freeing the old hash; count validity and allocation success are unchecked.
template <> void TMapBase<FString, FConfigFile>::Rehash()
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
      pairOffset += 0x2c;
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

// RavenShield.exe @ 1090fb90 : TMapBase<FString, FConfigFile>::Find
// Follow the filename's hash chain and return the first equal key's value; reload pair data after comparison calls.
template <> FConfigFile *TMapBase<FString, FConfigFile>::Find(const FString &key)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = HashCaseInsensitiveUtf16(*key);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  int32_t index = *reinterpret_cast<const int32_t *>(heads + bucket * 4);
  while (index != -1)
  {
    const uint32_t offset = static_cast<uint32_t>(index) * 0x2c;
    uint32_t data = *reinterpret_cast<const uint32_t *>(object);
    if (reinterpret_cast<const FString *>(data + offset + 4)->operator==(key) != 0)
    {
      data = *reinterpret_cast<const uint32_t *>(object);
      return reinterpret_cast<FConfigFile *>(data + offset + 0x10);
    }
    data = *reinterpret_cast<const uint32_t *>(object);
    index = *reinterpret_cast<const int32_t *>(data + offset);
  }
  return nullptr;
}

// RavenShield.exe @ 10910360 : TMapBase<FString, FConfigFile>::Set
// Assign the first matching value or append a new filename/file pair, returning its value reference.
template <> FConfigFile &TMapBase<FString, FConfigFile>::Set(const uint16_t *key, const FConfigFile &value)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t hash = HashCaseInsensitiveUtf16(key);
  const uint32_t bucket = hash & (*reinterpret_cast<const uint32_t *>(object + 0x10) - 1);
  const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
  int32_t index = *reinterpret_cast<const int32_t *>(heads + bucket * 4);
  while (index != -1)
  {
    const uint32_t offset = static_cast<uint32_t>(index) * 0x2c;
    uint32_t data = *reinterpret_cast<const uint32_t *>(object);
    if (reinterpret_cast<const FString *>(data + offset + 4)->operator==(key) != 0)
    {
      data = *reinterpret_cast<const uint32_t *>(object);
      *reinterpret_cast<FConfigFile *>(data + offset + 0x10) = value;
      data = *reinterpret_cast<const uint32_t *>(object);
      return *reinterpret_cast<FConfigFile *>(data + offset + 0x10);
    }
    data = *reinterpret_cast<const uint32_t *>(object);
    index = *reinterpret_cast<const int32_t *>(data + offset);
  }
  return Add(key, value); // Native append boundary 10910500; it owns pair construction and hash growth.
}

// RavenShield.exe @ 10910500 : TMapBase<FString, FConfigFile>::Add
// Append and construct a file pair, link it into the current bucket, then grow/rebuild an overloaded hash.
template <> FConfigFile &TMapBase<FString, FConfigFile>::Add(const uint16_t *key, const FConfigFile &value)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *pairs = reinterpret_cast<FArray *>(this);
  const int32_t index = pairs->Add(1, 0x2c); // Num increases before construction, including construction failure.
  const uint32_t address = *reinterpret_cast<const uint32_t *>(object) + static_cast<uint32_t>(index) * 0x2c;
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
  return *reinterpret_cast<FConfigFile *>(address + 0x10);
}

// RavenShield.exe @ 10910590 : TMapBase<FString, FConfigFile>::TPair::TPair
// Construct Key before copying Value; leave HashNext untouched until Add links the completed pair.
template <>
TMapBase<FString, FConfigFile>::TPair::TPair(const uint16_t *key, const FConfigFile &value) : Key(key), Value(value)
{
  // Shared handler 10912d6c destroys only Key if Value copy construction throws.
}

class FOutputDevice;
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern const char16_t g_unwindContextFormat[];

// RavenShield.exe data @ 10917c2c : g_configFileMapDumpGuardName
const char16_t g_configFileMapDumpGuardName[] = u"TMapBase::Dump";
// RavenShield.exe data @ 10917c4c : g_configFileMapBucketFormat
const char16_t g_configFileMapBucketFormat[] = u"   Hash[%i] = %i";
// RavenShield.exe data @ 10917c70 : g_configFileMapSummaryFormat
const char16_t g_configFileMapSummaryFormat[] = u"TMapBase: %i items, %i hash slots";

// RavenShield.exe @ 1090e8e0 : TMapBase<FString, FConfigFile>::Dump
// Log pair/bucket counts and each bucket's linked-chain length, reloading map storage between callbacks.
template <> void TMapBase<FString, FConfigFile>::Dump(FOutputDevice &output)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    using DumpLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);
    const auto &logf = *reinterpret_cast<const DumpLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    const int32_t count = reinterpret_cast<FArray *>(this)->Num();
    const int32_t hashCount = *reinterpret_cast<const int32_t *>(object + 0x10);
    logf(&output, reinterpret_cast<const uint16_t *>(g_configFileMapSummaryFormat), count, hashCount);
    for (int32_t bucket = 0; bucket < *reinterpret_cast<const int32_t *>(object + 0x10); ++bucket)
    {
      const uint32_t heads = *reinterpret_cast<const uint32_t *>(object + 0xc);
      int32_t index = *reinterpret_cast<const int32_t *>(heads + static_cast<uint32_t>(bucket) * 4);
      uint32_t chainLength = 0;
      while (index != -1)
      {
        const uint32_t data = *reinterpret_cast<const uint32_t *>(object);
        ++chainLength;
        index = *reinterpret_cast<const int32_t *>(data + static_cast<uint32_t>(index) * 0x2c);
      }
      logf(&output, reinterpret_cast<const uint16_t *>(g_configFileMapBucketFormat), bucket,
           static_cast<int32_t>(chainLength));
    }
  }
  // RavenShield.exe @ 1090e956 : RethrowConfigFileMapDumpPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e96a : UnwindConfigFileMapDumpFailure
  // Append the map Dump guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configFileMapDumpGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a774 : g_configFileMapDumpUnwind
const NativeCppUnwindEntry g_configFileMapDumpUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a784 : g_configFileMapDumpCatches
const NativeCppCatchHandler g_configFileMapDumpCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e956}, // RethrowConfigFileMapDumpPointer
    {0, 0, 0, 0x1090e96a},                                               // UnwindConfigFileMapDumpFailure
};

// RavenShield.exe data @ 1091a7a4 : g_configFileMapDumpTryBlocks
const NativeCppTryBlock g_configFileMapDumpTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configFileMapDumpCatches)},
};

// RavenShield.exe data @ 1091a7b8 : g_configFileMapDumpExceptionInfo
const NativeCppFunctionInfo g_configFileMapDumpExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configFileMapDumpUnwind), 1, NativeAddress(g_configFileMapDumpTryBlocks), 0, 0};

// RavenShield.exe @ 10912c10 : HandleConfigFileMapDumpException
// Supply the map dump's two-state typed-pointer/catch-all guard map to shared C++ exception dispatch.
__declspec(naked) void HandleConfigFileMapDumpException()
{
  __asm {
    mov eax, offset g_configFileMapDumpExceptionInfo
    jmp DispatchExecutableCppException
  }
}
