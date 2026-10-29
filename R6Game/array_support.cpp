#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10019af0 : three-DWORD SEH scope record
const unsigned int array_support_ExceptionScopeRecord1[3] = {
    0xffffffff, R6GameAddresses::ArrayUnwindExceptionFilter, R6GameAddresses::ArrayCleanupSehHandler, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10019b00 : three-DWORD SEH scope record
const unsigned int array_support_ExceptionScopeRecord2[3] = {
    0xffffffff, 0x0, R6GameAddresses::UnwindArrayDestructorIterator, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10019b10 : three-DWORD SEH scope record
const unsigned int array_support_ExceptionScopeRecord3[3] = {
    0xffffffff, 0x0, R6GameAddresses::UnwindArrayConstructorIterator, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10019b20 : three-DWORD SEH scope record
const unsigned int array_support_ExceptionScopeRecord4[3] = {
    0xffffffff, 0x0, R6GameAddresses::UnwindArrayCopyConstructorIterator, // Previous state, filter (zero for finally), handler.
};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a5fc : native C++ unwind-state transitions
const unsigned int ArrayUnwindMap[2] = {
    0xffffffff, R6GameAddresses::ArrayUnwindEntry2, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a604 : native C++ exception function descriptor
const unsigned int ArrayExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::ArrayUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b404 : native C++ unwind-state transitions
const unsigned int SerializeFArrayUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b414 : native typed-pointer and catch-all handler pair
const unsigned int SerializeFArrayCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::SerializeFArrayCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::SerializeFArrayCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b434 : native C++ try-block ranges
const unsigned int SerializeFArrayTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::SerializeFArrayCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b448 : native C++ exception function descriptor
const unsigned int SerializeFArrayExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::SerializeFArrayUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::SerializeFArrayTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// Shared native array operations and compiler array-construction/destruction support.

// R6Game.dll @ 10003af0 : ConstructFStringArrayCopy
// Initializes fresh array storage and copy-constructs its strings.
FArray* __thiscall ConstructFStringArrayCopy(FArray* destination, const FArray* source)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&ArrayExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native saves the receiver immediately before the header for shared FArray-only unwind cleanup.
    void*& destinationData = *(void**)destination;
    int& destinationCount = *(int*)((byte*)destination + 4);
    int& destinationCapacity = *(int*)((byte*)destination + 8);
    void* const& sourceData = *(void* const*)source;
    const int& sourceCount = *(const int*)((const byte*)source + 4);
    int initialCount = sourceCount;
    destinationData = nullptr;
    destinationCount = initialCount;
    destinationCapacity = initialCount;
    FArray::Realloc(destination, 12);
    destinationCount = 0;
    int sourceIndex = 0;
    int copyCount = sourceCount; // Native initial loop-bound read precedes the state-zero store.
    exceptionRegistration.state = 0;
    while (sourceIndex < copyCount) {
        int destinationIndex = FArray::Add(destination, 1, 12);
        FString* element = (FString*)((uint)destinationData + (uint)destinationIndex * 12U);
        if (element != nullptr)
            FString::FString(element, (const FString*)((uint)sourceData + (uint)sourceIndex * 12U));
        copyCount = sourceCount;
        sourceIndex = (int)((uint)sourceIndex + 1U);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return destination;
}

// R6Game.dll @ 10003b80 : ConstructFourByteFArrayCopy
// Initializes fresh array storage and copies its four-byte elements.
FArray* __thiscall ConstructFourByteFArrayCopy(FArray* destination, const FArray* source)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&ArrayExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native saves the receiver immediately before the header for shared FArray-only unwind cleanup.
    void*& destinationData = *(void**)destination;
    int& destinationCount = *(int*)((byte*)destination + 4);
    int& destinationCapacity = *(int*)((byte*)destination + 8);
    void* const& sourceData = *(void* const*)source;
    const int& sourceCount = *(const int*)((const byte*)source + 4);
    int initialCount = sourceCount;
    destinationData = nullptr;
    destinationCount = initialCount;
    destinationCapacity = initialCount;
    FArray::Realloc(destination, 4);
    int sourceIndex = 0;
    int copyCount = destinationCount; // This body never enters state zero, even during copying.
    while (sourceIndex < copyCount) {
        uint sourceWord = *(const uint*)((uint)sourceData + (uint)sourceIndex * 4U);
        *(uint*)((uint)destinationData + (uint)sourceIndex * 4U) = sourceWord;
        copyCount = destinationCount;
        sourceIndex = (int)((uint)sourceIndex + 1U);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return destination;
}

// R6Game.dll @ 10003bf0 : ConstructFourByteFArrayCopyWithAdd
// Initializes fresh array storage and copies its four-byte elements.
FArray* __thiscall ConstructFourByteFArrayCopyWithAdd(FArray* destination, const FArray* source)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&ArrayExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native saves the receiver immediately before the header for shared FArray-only unwind cleanup.
    void*& destinationData = *(void**)destination;
    int& destinationCount = *(int*)((byte*)destination + 4);
    int& destinationCapacity = *(int*)((byte*)destination + 8);
    void* const& sourceData = *(void* const*)source;
    const int& sourceCount = *(const int*)((const byte*)source + 4);
    int initialCount = sourceCount;
    destinationData = nullptr;
    destinationCount = initialCount;
    destinationCapacity = initialCount;
    FArray::Realloc(destination, 4);
    destinationCount = 0;
    int sourceIndex = 0;
    int copyCount = sourceCount; // Native initial loop-bound read precedes the state-zero store.
    exceptionRegistration.state = 0;
    while (sourceIndex < copyCount) {
        int destinationIndex = FArray::Add(destination, 1, 4);
        uint* element = (uint*)((uint)destinationData + (uint)destinationIndex * 4U);
        if (element != nullptr)
            *element = *(const uint*)((uint)sourceData + (uint)sourceIndex * 4U);
        copyCount = sourceCount;
        sourceIndex = (int)((uint)sourceIndex + 1U);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return destination;
}

// R6Game.dll @ 10003c80 : RemoveFStringArrayItemsChecked
// Destroys a checked range of strings, then removes their array slots.
void __thiscall RemoveFStringArrayItemsChecked(FArray* array, int firstIndex, int count)
{
    using AssertCall = void (__cdecl *)(const char*, const char*, int);
    AssertCall failAssert = *(AssertCall*)R6GameImports::Core_appFailAssertSlot;
    const int& arrayCount = *(const int*)((byte*)array + 4);
    if (firstIndex < 0)
        failAssert("Index>=0", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x201);
    if (firstIndex > arrayCount)
        failAssert("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    int rangeEnd = (int)((uint)firstIndex + (uint)count);
    if (rangeEnd > arrayCount)
        failAssert("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    if (firstIndex < rangeEnd) {
        uint byteOffset = (uint)firstIndex * 12U;
        uint remainingCount = (uint)rangeEnd - (uint)firstIndex;
        do {
            FString::~FString((FString*)((uint)*(void**)array + byteOffset));
            byteOffset += 12;
            --remainingCount;
        } while (remainingCount != 0);
    }
    FArray::Remove(array, firstIndex, count, 12);
}

// R6Game.dll @ 10003d20 : ClearFStringArrayAndReserve
// Destroys every string, clears the count, and reallocates the requested capacity.
void __thiscall ClearFStringArrayAndReserve(FArray* array, int requestedCapacity)
{
    int& arrayCount = *(int*)((byte*)array + 4);
    int& arrayCapacity = *(int*)((byte*)array + 8);
    uint byteOffset = 0;
    for (int elementIndex = 0; elementIndex < arrayCount; ++elementIndex) {
        FString::~FString((FString*)((uint)*(void**)array + byteOffset));
        byteOffset += 12;
    }
    arrayCount = 0;
    arrayCapacity = requestedCapacity;
    FArray::Realloc(array, 12);
}

// R6Game.dll @ 10003d70 : AssignFStringArray
// Replaces a distinct destination array with copies of the source elements.
FArray* __thiscall AssignFStringArray(FArray* destination, const FArray* source)
{
    if (destination == source)
        return destination;
    void*& destinationData = *(void**)destination;
    void* const& sourceData = *(void* const*)source;
    const int& sourceCount = *(const int*)((const byte*)source + 4);
    ClearFStringArrayAndReserve(destination, sourceCount);
    for (int sourceIndex = 0; sourceIndex < sourceCount; ++sourceIndex) {
        int destinationIndex = FArray::Add(destination, 1, 12);
        FString* element = (FString*)((uint)destinationData + (uint)destinationIndex * 12U);
        if (element != nullptr)
            FString::FString(element, (const FString*)((uint)sourceData + (uint)sourceIndex * 12U));
    }
    return destination;
}

// R6Game.dll @ 10003de0 : AssignFourByteFArray
// Replaces a distinct destination array with copies of the source elements.
FArray* __thiscall AssignFourByteFArray(FArray* destination, const FArray* source)
{
    if (destination == source)
        return destination;
    void*& destinationData = *(void**)destination;
    void* const& sourceData = *(void* const*)source;
    const int& sourceCount = *(const int*)((const byte*)source + 4);
    int initialCount = sourceCount;
    *(int*)((byte*)destination + 4) = 0;
    *(int*)((byte*)destination + 8) = initialCount;
    FArray::Realloc(destination, 4);
    for (int sourceIndex = 0; sourceIndex < sourceCount; ++sourceIndex) {
        int destinationIndex = FArray::Add(destination, 1, 4);
        uint* element = (uint*)((uint)destinationData + (uint)destinationIndex * 4U);
        if (element != nullptr)
            *element = ((const uint*)sourceData)[sourceIndex];
    }
    return destination;
}

// R6Game.dll @ 10003e50 : ForwardToFourByteArrayDestructor
// Forwards the array receiver in ECX and preserves the remaining machine state.
__declspec(naked) void __thiscall ForwardToFourByteArrayDestructor(FArray* array)
{
    __asm {
        jmp R6GameAddresses::DestroyFourByteFArray
    }
}

// R6Game.dll @ 10003ec0 : DestroyFStringArray
// Destroys all string elements and releases the backing FArray storage.
void __thiscall DestroyFStringArray(FArray* array)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&ArrayExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native saves the receiver immediately before the header for shared FArray-only unwind cleanup.
    int originalCount = *(int*)((byte*)array + 4);
    exceptionRegistration.state = 0;
    RemoveFStringArrayItemsChecked(array, 0, originalCount);
    exceptionRegistration.state = -1;
    FArray::~FArray(array);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003f10 : remove all four-byte elements and destroy their array storage
void __thiscall DestroyFourByteFArray(FArray* array)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&ArrayExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native saves the receiver immediately before the header for shared FArray-only unwind cleanup.
    int countToRemove = *(int*)((byte*)array + 4);
    using AssertCall = void (__cdecl *)(const char*, const char*, int);
    AssertCall failAssert = *(AssertCall*)R6GameImports::Core_appFailAssertSlot;
    exceptionRegistration.state = 0;
    if (countToRemove < 0)
        failAssert("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    if (*(int*)((byte*)array + 4) < countToRemove)
        failAssert("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    FArray::Remove(array, 0, countToRemove, 4);
    exceptionRegistration.state = -1;
    FArray::~FArray(array);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003fa0 : ForwardToFStringArrayDestructor
// Forwards the array receiver in ECX and preserves the remaining machine state.
__declspec(naked) void __thiscall ForwardToFStringArrayDestructor(FArray* array)
{
    __asm {
        jmp R6GameAddresses::DestroyFStringArray
    }
}

// R6Game.dll @ 10013650 : release the saved array's backing storage during helper unwinding
__declspec(naked) void ArrayUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_FArray_DestructorSlot // FArray destructor.
    }
}

// R6Game.dll @ 10013659 : select the common array-helper exception map and tail-dispatch it
__declspec(naked) void ArrayExceptionHandler(void)
{
    __asm {
        mov eax, offset ArrayExceptionInfo
        jmp R6GameAddresses::CxxFrameHandler
    }
}

// R6Game.dll @ 100094d0 : RemoveFArrayItemsChecked
// Checks the signed index range, then removes 4-byte array slots.
void __thiscall RemoveFArrayItemsChecked(FArray* array, int firstIndex, int count)
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
    FArray::Remove(array, firstIndex, count, 4);
}

// R6Game.dll @ 1000a210 : RemoveMatchingFArrayElements
// Removes matching four-byte values and returns how many slots were removed.
int __thiscall RemoveMatchingFArrayElements(FArray* array, const int* valueToRemove)
{
    void* const& arrayData = *(void* const*)array;
    const int& arrayCount = *(const int*)((byte*)array + 4);
    int initialCount = arrayCount;
    for (int index = 0; index < arrayCount; ++index) {
        if (((const int*)arrayData)[index] == *valueToRemove) {
            RemoveFArrayItemsChecked(array, index, 1);
            --index;
        }
    }
    return (int)((uint)initialCount - (uint)arrayCount);
}

// R6Game.dll @ 1000a250 : transfer a compact count and each object-reference slot through the archive
FArchive* __cdecl SerializeFArray(FArchive* archive, FArray* array)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&SerializeFArray_ExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; neither state owns element cleanup.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    void*& arrayData = *(void**)array;
    int& arrayCount = *(int*)((byte*)array + 4);
    int& arrayCapacity = *(int*)((byte*)array + 8);
    FArray::CountBytes(array, archive, 4);
    if (*(int*)((byte*)archive + 0x14) != 0) { // FArchive::IsLoading.
        int loadedCount;
        operator<<(archive, (FCompactIndex*)&loadedCount);
        const int capacityCount = loadedCount; // Captured before the old-count walk; loop bound stays live.
        for (int oldIndex = 0; oldIndex < arrayCount; ++oldIndex) {
            // The selected loop has no per-element destructor call.
        }
        arrayCapacity = capacityCount;
        arrayCount = 0;
        FArray::Realloc(array, 4);
        for (int elementIndex = 0; elementIndex < loadedCount; ++elementIndex) {
            int addedIndex = FArray::Add(array, 1, 4);
            UObject** element = (UObject**)((uint)arrayData + (uint)addedIndex * 4U);
            auto transferElement = *(FArchive* (__thiscall**)(FArchive*, UObject**))(*(byte**)archive + 0x18);
            transferElement(archive, element);
        }
    } else {
        operator<<(archive, (FCompactIndex*)&arrayCount);
        for (int elementIndex = 0; elementIndex < arrayCount; ++elementIndex) {
            UObject** element = (UObject**)((uint)arrayData + (uint)elementIndex * 4U);
            auto transferElement = *(FArchive* (__thiscall**)(FArchive*, UObject**))(*(byte**)archive + 0x18);
            transferElement(archive, element);
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return archive;
}

// R6Game.dll @ 1000a30f : rethrow the array serializer's caught UTF-16 pointer value
__declspec(naked) void SerializeFArrayCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000a323 : report array serialization context and forward the active exception
__declspec(naked) void SerializeFArrayCatchContext(void)
{
    __asm {
        push R6GameAddresses::TArrayExceptionContext // L"TArray<<"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013fd0 : dispatch array serialization's guard and catch states
__declspec(naked) void SerializeFArray_ExceptionHandler(void)
{
    __asm { mov eax, offset SerializeFArrayExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// Callback receivers use ECX; copy callbacks receive their source pointer as the single stack argument.
using ArrayElementCallback = void (__thiscall *)(void*);
using ArrayCopyCallback = void (__thiscall *)(void*, void*);

// R6Game.dll @ 10001830 : construct successive elements without installing a local exception handler
void __stdcall ConstructArrayElements(void* elements, uint elementSize, int elementCount,
    ArrayElementCallback constructElement)
{
    uint remaining = (uint)elementCount;
    if ((int)(remaining - 1U) < 0) return; // Native DEC/JS admits INT_MIN after wrap.
    ArrayElementCallback constructor = constructElement;
    uint stride = elementSize;
    void* cursor = elements;
    do {
        constructor(cursor);
        cursor = (void*)((uint)cursor + stride);
        --remaining;
    } while (remaining != 0);
}

// R6Game.dll @ 10012f66 : destroy preceding elements, terminating on a C++ exception during cleanup
void __stdcall __ArrayUnwind(void* elementCursor, uint elementSize, int remainingCount,
    ArrayElementCallback destroyElement)
{
    // Native scope 0 at 0x10019af0 covers the decrement, pointer update and callback.
    __try {
        for (;;) {
            remainingCount = (int)((uint)remainingCount - 1U);
            if (remainingCount < 0) break;
            elementCursor = (void*)((uint)elementCursor - elementSize);
            destroyElement(elementCursor);
        }
    }
    __except (ArrayUnwindExceptionFilter()) {
        // Native internal handler 0x10012fb9 restores ESP and joins the common epilogue.
    }
}

// R6Game.dll @ 10012f95 : continue exception search except for C++ cleanup failures, which terminate
// Private filter: EBP is the inherited __ArrayUnwind frame; exception pointers are at frame -0x14.
__declspec(naked) int ArrayUnwindExceptionFilter(void)
{
    __asm {
        mov eax, dword ptr [ebp-0x14]
        mov dword ptr [ebp-0x1c], eax
        mov eax, dword ptr [ebp-0x1c]
        mov eax, dword ptr [eax]
        mov dword ptr [ebp-0x20], eax
        mov eax, dword ptr [ebp-0x20]
        cmp dword ptr [eax], 0xe06d7363
        je cppCleanupFailure
        mov dword ptr [ebp-0x24], 0
        mov eax, dword ptr [ebp-0x24]
        ret
    cppCleanupFailure:
        call terminate
        int 3
    }
}

// R6Game.dll @ 10012fc4 : destroy an array backward and unwind the remaining prefix if destruction fails
void __stdcall _eh_vector_destructor_iterator_(void* elementCursor, uint elementSize, int remainingCount,
    ArrayElementCallback destroyElement)
{
    uint completed = 0; // Native frame -0x1c; argument cursor/count remain at +0x08/+0x10.
    uint stride = elementSize; // Native ESI remains cached across destructor callbacks.
    elementCursor = (void*)((uint)elementCursor + stride * (uint)remainingCount);
    __try {
        for (;;) {
            remainingCount = (int)((uint)remainingCount - 1U);
            if (remainingCount < 0) break;
            elementCursor = (void*)((uint)elementCursor - stride);
            destroyElement(elementCursor);
        }
        completed = 1;
    }
    __finally {
        UnwindArrayDestructorIterator(); // Native scope 0 at 0x10019b00 invokes this on both exits.
    }
}

// R6Game.dll @ 1001300c : destroy the destructor iterator's remaining prefix after an abnormal exit
__declspec(naked) void UnwindArrayDestructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x1c], 0
        jne complete
        push dword ptr [ebp+0x14]
        push dword ptr [ebp+0x10]
        push dword ptr [ebp+0xc]
        push dword ptr [ebp+0x8]
        call __ArrayUnwind
    complete:
        ret
    }
}

// R6Game.dll @ 10013024 : construct elements forward and destroy the completed prefix on failure
void __stdcall _eh_vector_constructor_iterator_(void* elementCursor, uint elementSize, int elementCount,
    ArrayElementCallback constructElement, ArrayElementCallback destroyElement)
{
    uint completed = 0; // Native frame -0x20; completed-element count is frame -0x1c.
    int constructedCount;
    __try {
        constructedCount = 0;
        while (constructedCount < elementCount) {
            void* constructedElement = elementCursor; // Native ESI survives the constructor callback.
            constructElement(constructedElement);
            elementCursor = (void*)((uint)constructedElement + elementSize);
            ++constructedCount;
        }
        completed = 1;
    }
    __finally {
        UnwindArrayConstructorIterator(); // Native scope 0 at 0x10019b10; cursor is argument +0x08.
    }
}

// R6Game.dll @ 1001306e : destroy the constructor iterator's completed prefix after an abnormal exit
__declspec(naked) void UnwindArrayConstructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x20], 0
        jne complete
        push dword ptr [ebp+0x18]
        push dword ptr [ebp-0x1c]
        push dword ptr [ebp+0xc]
        push dword ptr [ebp+0x8]
        call __ArrayUnwind
    complete:
        ret
    }
}

// R6Game.dll @ 10013086 : copy elements forward and destroy only successfully completed copies on failure
void __stdcall _eh_vector_copy_constructor_iterator_(void* destinationCursor, void* sourceCursor, uint elementSize,
    int elementCount, ArrayCopyCallback copyConstructElement, ArrayElementCallback destroyElement)
{
    uint completed = 0; // Native frame -0x20; completed count -0x1c, destination/source arguments +0x08/+0x0c.
    int constructedCount;
    __try {
        constructedCount = 0;
        while (constructedCount < elementCount) {
            copyConstructElement(destinationCursor, sourceCursor);
            uint stride = elementSize;
            destinationCursor = (void*)((uint)destinationCursor + stride);
            sourceCursor = (void*)((uint)sourceCursor + stride);
            ++constructedCount;
        }
        completed = 1;
    }
    __finally {
        UnwindArrayCopyConstructorIterator(); // Native scope 0 at 0x10019b20.
    }
}

// R6Game.dll @ 100130d4 : destroy the copy iterator's completed destinations after an abnormal exit
__declspec(naked) void UnwindArrayCopyConstructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x20], 0
        jne complete
        push dword ptr [ebp+0x1c]
        push dword ptr [ebp-0x1c]
        push dword ptr [ebp+0x10]
        push dword ptr [ebp+0x8]
        call __ArrayUnwind
    complete:
        ret
    }
}
