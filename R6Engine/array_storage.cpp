#include "native_array_views.hpp"
#include "native_text_data.hpp"
#include "native_shared_entries.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl ArrayStorageState0Cleanup(void);
__declspec(naked) void __cdecl SharedArrayStorageDestructionState0Cleanup(void);

// R6Engine.dll data @ 100584a0 : sharedArrayStorageDestructionUnwindMap
// Retains one shared storage-destructor cleanup state with no catch handlers.
const NativeUnwindEntry sharedArrayStorageDestructionUnwindMap[1] = {
    { -1, ((uint)&SharedArrayStorageDestructionState0Cleanup) }
};

// R6Engine.dll data @ 100584a8 : sharedArrayStorageDestructionFuncInfo
// Retains one shared storage-destructor cleanup state with no catch handlers.
const NativeFunctionInfoPrefix sharedArrayStorageDestructionFuncInfo = { 0x19930520, 0x1,
    ((uint)&sharedArrayStorageDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10059128 : arrayStorageUnwindMap
// Retains the native predecessor states and destructor cleanup entries.
const NativeUnwindEntry arrayStorageUnwindMap[1] = {
    { -1, ((uint)&ArrayStorageState0Cleanup) }
};

// R6Engine.dll data @ 10059130 : arrayStorageFuncInfo
// Binds cleanup states with no typed or catch-all handlers.
const NativeFunctionInfoPrefix arrayStorageFuncInfo = { 0x19930520, 0x1, ((uint)&arrayStorageUnwindMap), 0, 0, 0 };

// Routes destruction through its selected cleanup-only exception metadata.
__declspec(naked) void __cdecl ArrayStorageExceptionHandler(void);

// Routes destruction through its selected cleanup-only exception metadata.
__declspec(naked) void __cdecl ArrayPairExceptionHandler(void);

// R6Engine.dll @ 10018840 : DestroyEightByteArrayStorageWithOwnGuard
// Removes the captured signed count of eight-byte elements, then destroys array storage on normal or exceptional exit.
__declspec(naked) void __thiscall DestroyEightByteArrayStorageWithOwnGuard(FArray* array)
{
    __asm {
        push -1
        push offset ArrayStorageExceptionHandler
        mov eax,dword ptr fs:[0]
        push eax
        mov dword ptr fs:[0],esp
        push ecx
        push ebx
        push esi
        mov esi,ecx
        push edi
        mov dword ptr [esp+0xc],esi
        // Capture signed count once before assertions; later count changes do not replace this removal count.
        mov edi,dword ptr [esi+0x4]
        test edi,edi
        mov ebx,dword ptr [CoreAppFailAssertImport]
        mov dword ptr [esp+0x18],0x0
        jge check_current_count
        // Report Index<=ArrayNum at line0x202; continue if assertion hook returns.
        push 0x202
        push offset nativePathUnTemplateH
        push offset nativeTextIndexArrayNum
        call ebx
        add esp,0xc
    check_current_count:
        // Reload current count for the second assertion against the captured count.
        cmp edi,dword ptr [esi+0x4]
        jle remove_elements
        push 0x203
        push offset nativePathUnTemplateH
        push offset nativeTextIndexCountArrayNum
        call ebx
        add esp,0xc
    remove_elements:
        push 0x8
        push edi
        push 0x0
        mov ecx,esi
        // FArray::Remove(0,capturedCount,8); no per-element destructor loop is added.
        call dword ptr [FArrayRemoveImport]
        mov ecx,esi
        // Disable this cleanup before entering the normal FArray destructor.
        mov dword ptr [esp+0x18],0xffffffff
        call dword ptr [FArrayDestructorImport]
        mov ecx,dword ptr [esp+0x10]
        pop edi
        pop esi
        pop ebx
        mov dword ptr fs:[0],ecx
        add esp,0x10
        ret
    }
}

// R6Engine.dll @ 10043eb0 : ArrayStorageState0Cleanup
// Destroys the FArray saved at dispatcher-frame EBP-0x10 after an exceptional removal.
__declspec(naked) void __cdecl ArrayStorageState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [FArrayDestructorImport]
    }
}

// R6Engine.dll @ 10043eb9 : ArrayStorageExceptionHandler
// Supplies cleanup-only exception metadata without changing the native dispatcher frame.
__declspec(naked) void __cdecl ArrayStorageExceptionHandler(void)
{
    __asm {
        mov eax,offset arrayStorageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000e970 : DestroyWordArrayStorage
// Removes the captured signed count of 4-byte elements, then destroys storage on normal or exceptional exit.
void __thiscall DestroyWordArrayStorage(FArray* array)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int count = arrayHeaderView->count; // Capture before both the assertion target and state0.
    using FailAssert = void (__cdecl*)(const char*, const char*, int);
    // Reuse this captured target if the first assertion changes its IAT.
    FailAssert fail = reinterpret_cast<FailAssert&>(CoreAppFailAssertImport);
    // Local reference view of the single native cleanup state, not a recovered native type or compiler frame.
    struct PendingStorageCleanup {
        FArray* array;
        bool active;
        // Releases the current array storage when an assertion or removal escapes before normal destruction.
        ~PendingStorageCleanup() noexcept(false)
        {
            if (!active) return;
            using DestroyStorage = void (__thiscall*)(FArray*);
            (*(DestroyStorage*)&FArrayDestructorImport)(array);
        }
    } cleanup{array, true};
    if (count < 0)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    if (count > arrayHeaderView->count) // Reread count after any first assertion callback.
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    // Original signed count, even if assertions return after changing it.
    array->FArray::Remove(0, count, 4);
    cleanup.active = false;
    // Native state-1 before this call prevents duplicate cleanup on failure.
    array->FArray::~FArray();
}

// R6Engine.dll @ 1000ea00 : DestroySixteenByteArrayStorage
// Removes the captured signed count of 16-byte elements, then destroys storage on normal or exceptional exit.
void __thiscall DestroySixteenByteArrayStorage(FArray* array)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int count = arrayHeaderView->count; // Capture before both the assertion target and state0.
    using FailAssert = void (__cdecl*)(const char*, const char*, int);
    // Reuse this captured target if the first assertion changes its IAT.
    FailAssert fail = reinterpret_cast<FailAssert&>(CoreAppFailAssertImport);
    // Local reference view of the single native cleanup state, not a recovered native type or compiler frame.
    struct PendingStorageCleanup {
        FArray* array;
        bool active;
        // Releases the current array storage when an assertion or removal escapes before normal destruction.
        ~PendingStorageCleanup() noexcept(false)
        {
            if (!active) return;
            using DestroyStorage = void (__thiscall*)(FArray*);
            (*(DestroyStorage*)&FArrayDestructorImport)(array);
        }
    } cleanup{array, true};
    if (count < 0)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    if (count > arrayHeaderView->count) // Reread count after any first assertion callback.
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    // Original signed count, even if assertions return after changing it.
    array->FArray::Remove(0, count, 16);
    cleanup.active = false;
    // Native state-1 before this call prevents duplicate cleanup on failure.
    array->FArray::~FArray();
}

// R6Engine.dll @ 100109c0 : ForwardWordArrayDestruction
// Tail-enters 4-byte array destruction with the original ECX receiver, stack and return frame.
__declspec(naked) void __thiscall ForwardWordArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyWordArrayStorage
    }
}

// R6Engine.dll @ 10043a20 : SharedArrayStorageDestructionState0Cleanup
// Destroys the FArray saved at inherited dispatcher-frame EBP-0x10 through the current imported destructor.
__declspec(naked) void __cdecl SharedArrayStorageDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [FArrayDestructorImport]
    }
}

// R6Engine.dll @ 10043a29 : SharedArrayStorageDestructionExceptionHandler
// Supplies exact shared cleanup-only FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl SharedArrayStorageDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset sharedArrayStorageDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000da20 : RemoveRecords4
// Checks three range predicates with a cached assertion target, then removes four-byte entries without destruction.
void __thiscall RemoveRecords4(FArray* array, int index, int count)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    using AssertCall = void (__cdecl*)(const char*, const char*, int);
    // Reused even when a reporting callback replaces the import.
    AssertCall fail = reinterpret_cast<AssertCall&>(CoreAppFailAssertImport);
    int removalIndex = index;
    if (removalIndex < 0)
        fail("Index>=0", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x201);
    if (removalIndex > arrayHeaderView->count)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    int removalCount = count; // Native captures Count only after the first two possible assertion callbacks.
    int currentNum = arrayHeaderView->count;
    int endIndex = (int)((uint)removalIndex + (uint)removalCount);
    if (endIndex > currentNum)
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    // Negative Count has no separate assertion.
    array->FArray::Remove(removalIndex, removalCount, 4);
}

// R6Engine.dll @ 1000d750 : CopyConstructRecords4
// Reserves from the initial source count, then appends raw four-byte entries using live source headers.
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    // State-1; no storage cleanup applies if this call escapes.
    destination->FArray::Realloc(4);
    destinationHeaderView->count = 0;
    int liveCount = sourceHeaderView->count;
    struct PendingStorage {
        FArray* array;
        bool active;
        // Releases only FArray storage if copying an element or invoking Add escapes construction.
        ~PendingStorage() noexcept(false) {
            if (!active) return;
            using DestroyStorage = void (__thiscall*)(FArray*);
            (*(DestroyStorage*)&FArrayDestructorImport)(array);
        }
    } cleanup{destination, true}; // Inferred view of shared FuncInfo100584a8; activation follows the live count read.
    uint index = 0;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 4);
        uint outputAddress = destinationHeaderView->dataAddress + (uint)addedIndex * 4U;
        if (outputAddress != 0) {
            uint sourceData = sourceHeaderView->dataAddress;
            *(uint*)outputAddress = *(const uint*)(sourceData + index * 4U);
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    cleanup.active = false; // Completed result owns storage; no per-element destruction is added.
    return destination;
}

// R6Engine.dll @ 1000daa0 : AssignRecords4
// Reuses array storage for raw four-byte copies, with an identity fast path and live source count/data reloads.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    if (destination == source) return destination;
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->count = 0;
    destinationHeaderView->capacity = initialCount;
    // Existing data pointer is retained until this callback changes it.
    destination->FArray::Realloc(4);
    int liveCount = sourceHeaderView->count;
    uint index = 0;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 4);
        uint outputAddress = destinationHeaderView->dataAddress + (uint)addedIndex * 4U;
        if (outputAddress != 0) {
            uint sourceData = sourceHeaderView->dataAddress;
            *(uint*)outputAddress = *(const uint*)(sourceData + index * 4U);
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    return destination; // No method guard, rollback or per-element destructor exists.
}

// R6Engine.dll @ 100416b0 : RemoveMatchingWords4
// Removes matching four-byte words, rereading the referenced comparison word after each removal.
int __thiscall RemoveMatchingWords4(FArray* words, const uint* keyReference)
{
    NativeArrayHeader32* wordsHeaderView = reinterpret_cast<NativeArrayHeader32*>(words);
    int originalCount = wordsHeaderView->count;
    uint wordIndex = 0; // Native32-bit INC/DEC arithmetic; comparisons use the signed view.
    if (originalCount > 0) {
        const uint* comparisonWord = keyReference; // Capture the pointer once, but reload its word each iteration.
        do {
            uint dataAddress = wordsHeaderView->dataAddress;
            uint entryWord = *(const uint*)(dataAddress + (uint)wordIndex * 4U);
            if (entryWord == *comparisonWord) {
                RemoveRecords4(words, (int)wordIndex, 1);
                --wordIndex;
            }
            int liveCount = wordsHeaderView->count;
            ++wordIndex;
            if ((int)wordIndex >= liveCount) break;
        } while (true);
    }
    uint finalCountWord = *(const uint*)((const byte*)words + 4);
    return (int)((uint)originalCount - finalCountWord);
}

// R6Engine.dll @ 1000d610 : CopyConstructRecords16
// Reserves the captured source count and copies four interleaved raw words with delayed outer-storage protection.
FArray* __thiscall CopyConstructRecords16(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    destination->FArray::Realloc(16);
    destinationHeaderView->count = 0;
    int liveCount = sourceHeaderView->count;
    uint index = 0;
    struct PendingStorage {
        FArray* array;
        bool active;
        // Releases outer FArray storage only after the delayed native state0 was entered.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{destination, true}; // Shared43a20/43a29/584a8; no cleanup applies to an escaping Realloc.
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 16);
        byte* output = (byte*)(destinationHeaderView->dataAddress + (uint)addedIndex * 16U);
        if (output != nullptr) {
            const byte* input = (const byte*)(sourceHeaderView->dataAddress + index * 16U);
            *(uint*)output = *(const uint*)input;
            *(uint*)(output + 4) = *(const uint*)(input + 4);
            *(uint*)(output + 8) = *(const uint*)(input + 8);
            *(uint*)(output + 12) = *(const uint*)(input + 12); // Interleaved writes use one captured input base.
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    cleanup.active = false; // Transfer ownership; native returns without another state write.
    return destination;
}

