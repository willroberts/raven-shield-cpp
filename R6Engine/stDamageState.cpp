#include "native_array_views.hpp"
#include "native_import_slots.hpp"
#include "native_shared_entries.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"

// Native helper declarations match their canonical definitions.
void __thiscall DestroyStringRecordArray16(FArray* array);
FArray* __thiscall CopyConstructStringRecords16(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);

// The selected script stDamageState binds this 0x3c-byte native record; original C++ type spelling is unknown.
// RandomSkins uses native stride8 providers even though the selected script element layout is16 bytes.

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl DamageStateState0Cleanup(void);
__declspec(naked) void __cdecl DamageStateState1Cleanup(void);
__declspec(naked) void __cdecl DamageStateState2Cleanup(void);

__declspec(naked) void __thiscall ForwardStringRecordArrayDestruction(FArray* array);

FArray* __thiscall CopyConstructRecords8(FArray* destination, const FArray* source);

void __thiscall DestroyEightByteArrayStorage(FArray* array);

__declspec(naked) void __thiscall ForwardEightByteArrayDestruction(FArray* array);

// R6Engine.dll data @ 100583cc : damageStateUnwindMap
// Protects the three completed array members, with no completed SoundList action or catch handlers.
const NativeUnwindEntry damageStateUnwindMap[3] = {
    { -1, ((uint)&DamageStateState0Cleanup) },
    { 0, ((uint)&DamageStateState1Cleanup) },
    { 0x1, ((uint)&DamageStateState2Cleanup) }
};

// R6Engine.dll data @ 100583e4 : damageStateFuncInfo
// Shares the exact three-state cleanup map between record construction and destruction.
const NativeFunctionInfoPrefix damageStateFuncInfo = { 0x19930520, 0x3, ((uint)&damageStateUnwindMap), 0, 0, 0 };

// R6Engine.dll @ 10013980 : DestroyDamageState
// Destroys SoundList, ActorList, RandomSkins and RandomMeshes in reverse ownership order.
void __thiscall DestroyDamageState(void* damageState)
{
    struct PendingMembers {
        byte* record;
        int state;
        // Releases only members still protected by the record's exact cleanup map.
        ~PendingMembers() noexcept(false) {
            if (state >= 2) ForwardStringRecordArrayDestruction((FArray*)(record + 0x1c));
            if (state >= 1) ForwardEightByteArrayDestruction((FArray*)(record + 0x10));
            if (state >= 0) ForwardEightByteArrayDestruction((FArray*)(record + 4));
        }
    } cleanup{(byte*)damageState, 2}; // Inferred view of FuncInfo100583e4; no additional native body.
    DestroyWordArrayStorage((FArray*)((byte*)damageState + 0x28));
    cleanup.state = 1;
    DestroyStringRecordArray16((FArray*)((byte*)damageState + 0x1c));
    cleanup.state = 0;
    DestroyEightByteArrayStorage((FArray*)((byte*)damageState + 0x10)); // Native stride8, with no inner Skin cleanup.
    cleanup.state = -1;
    DestroyEightByteArrayStorage((FArray*)((byte*)damageState + 4));
}

// R6Engine.dll @ 10013ba0 : CopyConstructDamageState
// Copies the damage word, constructs four arrays and then copies both ambient-sound references.
void* __thiscall CopyConstructDamageState(void* destination, const void* source)
{
    struct PendingMembers {
        byte* record;
        int state;
        // Destroys completed arrays only; the current constructor owns its partial member.
        ~PendingMembers() noexcept(false) {
            if (state >= 2) ForwardStringRecordArrayDestruction((FArray*)(record + 0x1c));
            if (state >= 1) ForwardEightByteArrayDestruction((FArray*)(record + 0x10));
            if (state >= 0) ForwardEightByteArrayDestruction((FArray*)(record + 4));
        }
    } cleanup{(byte*)destination, -1};
    byte* output = (byte*)destination;
    const byte* input = (const byte*)source;
    *(uint*)output = *(const uint*)input; // fDamagePercentage is a raw MOV word, including NaN payloads.
    CopyConstructRecords8((FArray*)(output + 4), (const FArray*)(input + 4));
    cleanup.state = 0;
    CopyConstructRecords8((FArray*)(output + 0x10), (const FArray*)(input + 0x10));
    cleanup.state = 1;
    CopyConstructStringRecords16((FArray*)(output + 0x1c), (const FArray*)(input + 0x1c));
    cleanup.state = 2;
    CopyConstructRecords4((FArray*)(output + 0x28), (const FArray*)(input + 0x28));
    *(uint*)(output + 0x34) = *(const uint*)(input + 0x34); // NewAmbientSound.
    *(uint*)(output + 0x38) = *(const uint*)(input + 0x38); // NewAmbientSoundStop.
    cleanup.state = -1; // Transfer completed ownership; no completed SoundList action exists in the native map.
    return destination;
}

// R6Engine.dll @ 100439f0 : DamageStateState0Cleanup
// Tail-destroys the saved record's RandomMeshes array using the native eight-byte provider.
__declspec(naked) void __cdecl DamageStateState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,4
        jmp ForwardEightByteArrayDestruction
    }
}

// R6Engine.dll @ 100439fb : DamageStateState1Cleanup
// Tail-destroys the saved record's RandomSkins array using the native eight-byte provider.
__declspec(naked) void __cdecl DamageStateState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x10
        jmp ForwardEightByteArrayDestruction
    }
}

// R6Engine.dll @ 10043a06 : DamageStateState2Cleanup
// Tail-destroys the saved record's ActorList array through its string-record provider.
__declspec(naked) void __cdecl DamageStateState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x1c
        jmp ForwardStringRecordArrayDestruction
    }
}

// R6Engine.dll @ 10043a11 : DamageStateExceptionHandler
// Supplies the shared record FuncInfo without changing the inherited dispatcher frame or arguments.
__declspec(naked) void __cdecl DamageStateExceptionHandler(void)
{
    __asm {
        mov eax,offset damageStateFuncInfo
        jmp __CxxFrameHandler
    }
}

// Shared native providers for a leading word followed by a12-byte FStringNoInit. Exact record ownership is unresolved.

// Native helper declarations match the canonical definitions below.

// R6Engine.dll @ 10001790 : DestroyRecordStringAt4
// Tail-enters current FStringNoInit destruction on the record member at+4, preserving the return frame.
__declspec(naked) void __thiscall DestroyRecordStringAt4(void* record)
{
    __asm {
        add ecx,4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 1000d880 : CopyConstructStringRecords16
// Reserves captured capacity and constructs leading-word/string records while following live array headers.
FArray* __thiscall CopyConstructStringRecords16(FArray* destination, const FArray* source)
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
    uint offset = 0;
    struct PendingStorage {
        FArray* array;
        bool active;
        // Protects only outer storage, without destroying strings in previously completed records.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{destination, true}; // Shared state0 is delayed until after Realloc, Num reset and live count sampling.
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 16);
        byte* output = (byte*)(destinationHeaderView->dataAddress + ((uint)addedIndex << 4));
        if (output != nullptr) {
            const byte* input = (const byte*)(sourceHeaderView->dataAddress + offset);
            uint leadingWord = *(const uint*)input;
            const FStringNoInit* inputString = (const FStringNoInit*)(input + 4);
            *(uint*)output = leadingWord;
            // Returned EAX is ignored.
            ::new (reinterpret_cast<void*>(output + 4)) FStringNoInit(*inputString);
        }
        liveCount = sourceHeaderView->count;
        ++index;
        offset += 16U;
    }
    cleanup.active = false; // Successful transfer; no additional native cleanup state or record guard.
    return destination;
}

// R6Engine.dll @ 1000ebb0 : RemoveStringRecords16
// Validates a captured start, destroys its fixed string range and removes with the later count argument.
void __thiscall RemoveStringRecords16(FArray* array, int index, int count)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int first = index;
    using AssertCall = void (__cdecl*)(const char*, const char*, int);
    AssertCall fail = reinterpret_cast<AssertCall&>(CoreAppFailAssertImport);
    if (first < 0) fail("Index>=0", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x201);
    if (first > arrayHeaderView->count)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    int end = (int)((uint)first + (uint)count);
    if (end > arrayHeaderView->count)
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    if (first < end) {
        uint offset = (uint)first << 4;
        uint remaining = (uint)end - (uint)first;
        do {
            DestroyRecordStringAt4((void*)(arrayHeaderView->dataAddress + offset));
            offset += 16U;
        } while (--remaining != 0);
    }
    // Count and Remove import are resampled after callbacks.
    array->FArray::Remove(first, count, 16);
}

// R6Engine.dll @ 10010c80 : DestroyStringRecordArray16
// Removes the captured string-record count and releases outer storage on normal or exceptional exit.
void __thiscall DestroyStringRecordArray16(FArray* array)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int count = arrayHeaderView->count;
    struct PendingStorage {
        FArray* array;
        bool active;
        // On removal failure, only outer storage is released here; remaining records are not visited.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{array, true};
    RemoveStringRecords16(array, 0, count);
    cleanup.active = false;
    // State-1 prevents a second attempt if this destructor throws.
    array->FArray::~FArray();
}

// R6Engine.dll @ 10013970 : ForwardStringRecordArrayDestruction
// Tail-enters string-record array destruction with the unchanged ECX receiver, stack and return address.
__declspec(naked) void __thiscall ForwardStringRecordArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyStringRecordArray16
    }
}

// R6Engine.dll @ 1000d7e0 : CopyConstructRecords8
// Reserves the captured source count and copies each pair of raw words with delayed outer-storage protection.
FArray* __thiscall CopyConstructRecords8(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    destination->FArray::Realloc(8);
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
        int addedIndex = destination->FArray::Add(1, 8);
        byte* output = (byte*)(destinationHeaderView->dataAddress + (uint)addedIndex * 8U);
        if (output != nullptr) {
            const byte* input = (const byte*)(sourceHeaderView->dataAddress + index * 8U);
            *(uint*)output = *(const uint*)input;
            *(uint*)(output + 4) = *(const uint*)(input + 4); // Retain interleaving and the captured input base.
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    cleanup.active = false; // Transfer ownership; native returns without another state write.
    return destination;
}

// R6Engine.dll @ 1000eb20 : DestroyEightByteArrayStorage
// Removes the captured signed count of 8-byte elements, then destroys storage on normal or exceptional exit.
void __thiscall DestroyEightByteArrayStorage(FArray* array)
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
    array->FArray::Remove(0, count, 8);
    cleanup.active = false;
    // Native state-1 before this call prevents duplicate cleanup on failure.
    array->FArray::~FArray();
}

// R6Engine.dll @ 10010c70 : ForwardEightByteArrayDestruction
// Tail-enters 8-byte array destruction with the original ECX receiver, stack and return frame.
__declspec(naked) void __thiscall ForwardEightByteArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyEightByteArrayStorage
    }
}
