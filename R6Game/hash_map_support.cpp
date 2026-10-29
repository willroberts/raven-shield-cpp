#include "import_bindings.h"

// Inferred views of the selected PE32 map records; addresses stay DWORDs and values remain opaque words.
struct NativeHashMapLayout {
    unsigned int pairsAddress; // +0x0: FArray storage.
    int pairCount; // +0x4.
    int pairCapacity; // +0x8.
    unsigned int bucketsAddress; // +0xc.
    int bucketCount; // +0x10.
};
struct NativeHashEntryLayout {
    unsigned int nextIndex; // +0x0: bucket-chain index, including the -1 bit pattern.
    unsigned int key; // +0x4.
    unsigned int value[2]; // +0x8: uninterpreted two-word payload.
};

// R6Game.dll @ 1000cc90 : RebuildHashMapBuckets
// Rebuilds bucket heads and entry chains, then releases the previous bucket table.
void __fastcall RebuildHashMapBuckets(void* map)
{
    auto* mapWords = reinterpret_cast<NativeHashMapLayout*>(map);
    void* const& pairsData = *reinterpret_cast<void* const*>(&mapWords->pairsAddress);
    const int& pairCount = mapWords->pairCount;
    int*& bucketHeads = *reinterpret_cast<int**>(&mapWords->bucketsAddress);
    const int& bucketCount = mapWords->bucketCount;
    uint allocationBytes = (uint)bucketCount * 4U;
    FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
    auto allocate = *(void* (__thiscall**)(FMalloc*, uint, const ushort*))(*(byte**)allocator);
    int* newBucketHeads = (int*)allocate(allocator, allocationBytes, L"HashMapHash");
    for (int bucketIndex = 0; bucketIndex < bucketCount; ++bucketIndex)
        newBucketHeads[bucketIndex] = -1;
    uint entryByteOffset = 0;
    for (int entryIndex = 0; entryIndex < pairCount; ++entryIndex) {
        auto* entry = reinterpret_cast<NativeHashEntryLayout*>((uint)pairsData + entryByteOffset);
        uint bucketIndex = entry->key & ((uint)bucketCount - 1U);
        entry->nextIndex = (uint)newBucketHeads[bucketIndex];
        newBucketHeads[bucketIndex] = entryIndex;
        entryByteOffset += 16U;
    }
    int* oldBucketHeads = bucketHeads;
    if (oldBucketHeads != nullptr) {
        allocator = *(FMalloc**)ImportedGMallocAddress;
        auto release = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
        release(allocator, oldBucketHeads);
    }
    bucketHeads = newBucketHeads;
}

// R6Game.dll @ 1000cd20 : AddHashMapEntry
// Appends a key and two-word value, links its bucket, and grows a crowded bucket table.
uint* __thiscall AddHashMapEntry(void* map, const uint* key, const uint* value)
{
    auto* mapWords = reinterpret_cast<NativeHashMapLayout*>(map);
    void* const& pairsData = *reinterpret_cast<void* const*>(&mapWords->pairsAddress);
    const int& pairCount = mapWords->pairCount;
    int* const& bucketHeads = *reinterpret_cast<int* const*>(&mapWords->bucketsAddress);
    int& bucketCount = mapWords->bucketCount;
    int addedIndex = FArray::Add((FArray*)map, 1, 16);
    auto* newEntry = reinterpret_cast<NativeHashEntryLayout*>((uint)pairsData + (uint)addedIndex * 16U);
    if (newEntry != nullptr) {
        newEntry->key = *key;
        newEntry->value[0] = value[0];
        newEntry->value[1] = value[1];
    }
    int capturedBucketCount = bucketCount;
    uint entryKey = newEntry->key;
    int* insertionBuckets = bucketHeads;
    uint bucketIndex = entryKey & ((uint)capturedBucketCount - 1U);
    newEntry->nextIndex = (uint)insertionBuckets[bucketIndex];
    int newEntryIndex = (int)((uint)pairCount - 1U);
    int* bucketTableForStore = bucketHeads;
    bucketTableForStore[bucketIndex] = newEntryIndex;
    int growthThreshold = (int)((uint)bucketCount * 2U + 8U);
    if (growthThreshold < pairCount) {
        bucketCount = (int)((uint)bucketCount * 2U);
        RebuildHashMapBuckets(map);
    }
    return (uint*)((uint)newEntry + 8U);
}

// R6Game.dll @ 1000cda0 : RemoveHashMapEntriesChecked
// Checks the signed index range, then removes 16-byte array slots.
void __thiscall RemoveHashMapEntriesChecked(FArray* array, int firstIndex, int count)
{
    const int& arrayCount = *(const int*)((byte*)array + 4);
    using AssertCall = void (__cdecl *)(const char*, const char*, int);
    AssertCall failAssert = *(AssertCall*)R6GameImports::Core_appFailAssertSlot;
    if (firstIndex < 0)
        failAssert("Index>=0", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x201);
    if (firstIndex > arrayCount)
        failAssert("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    int rangeEnd = (int)((uint)firstIndex + (uint)count);
    if (rangeEnd > arrayCount)
        failAssert("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    FArray::Remove(array, firstIndex, count, 16);
}

// R6Game.dll @ 10010020 : UpsertHashMapEntry
// Replaces a matching key's two-word value or appends a new entry.
uint* __thiscall UpsertHashMapEntry(void* map, const uint* key, const uint* value)
{
    auto* mapWords = reinterpret_cast<NativeHashMapLayout*>(map);
    void* const& pairsData = *reinterpret_cast<void* const*>(&mapWords->pairsAddress);
    int* const& bucketHeads = *reinterpret_cast<int* const*>(&mapWords->bucketsAddress);
    const int& bucketCount = mapWords->bucketCount;
    int lookupBucketCount = bucketCount;
    int* lookupBuckets = bucketHeads;
    uint lookupKey = *key;
    int entryIndex = lookupBuckets[lookupKey & ((uint)lookupBucketCount - 1U)];
    if (entryIndex != -1) {
        void* capturedPairsData = pairsData;
        do {
            auto* entry = reinterpret_cast<NativeHashEntryLayout*>((uint)capturedPairsData + (uint)entryIndex * 16U);
            if (entry->key == lookupKey) {
                entry->value[0] = value[0];
                entry->value[1] = value[1];
                return (uint*)((uint)pairsData + (uint)entryIndex * 16U + 8U);
            }
            entryIndex = (int)entry->nextIndex;
        } while (entryIndex != -1);
    }
    return AddHashMapEntry(map, key, value);
}

// R6Game.dll @ 10010090 : ShrinkHashMapIfSparse
// Shrinks a modified iterator's map while sparse, then rebuilds its bucket chains.
void __fastcall ShrinkHashMapIfSparse(void* iterator)
{
    const int& removedCount = *(const int*)((byte*)iterator + 0xc);
    if (removedCount == 0)
        return;
    void* map = *(void**)iterator;
    auto* mapWords = reinterpret_cast<NativeHashMapLayout*>(map);
    const int& pairCount = mapWords->pairCount;
    int& bucketCount = mapWords->bucketCount;
    while ((int)((uint)pairCount * 2U + 8U) < bucketCount)
        bucketCount /= 2; // CDQ, SUB, SAR implement signed division toward zero.
    RebuildHashMapBuckets(map);
}
