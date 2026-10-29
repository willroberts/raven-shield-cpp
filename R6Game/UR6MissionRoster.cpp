#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10025600 : class metadata storage
// Backing storage for UR6MissionRoster::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6MissionRosterClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10027970 : auto-class pointer
UClass* autoclassUR6MissionRoster = nullptr;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001ac44 : native C++ unwind-state transitions
const unsigned int UR6MissionRoster_DestructUnwindMap[4] = {
    0xffffffff, R6GameAddresses::UR6MissionRoster_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6MissionRoster_DestructUnwind1, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001ac54 : native C++ exception function descriptor
const unsigned int UR6MissionRoster_DestructExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6MissionRoster_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001ac70 : native C++ unwind-state transitions
const unsigned int UR6MissionRoster_CopyConstructUnwindMap[2] = {
    0xffffffff, R6GameAddresses::UR6MissionRoster_CopyConstructUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001ac78 : native C++ exception function descriptor
const unsigned int UR6MissionRoster_CopyConstructExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::UR6MissionRoster_CopyConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b4c4 : native C++ unwind-state transitions
const unsigned int UR6MissionRoster_TransferFileUnwindMap[16] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6MissionRoster_TransferFileUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6MissionRoster_TransferFileUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6MissionRoster_TransferFileUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6MissionRoster_TransferFileUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6MissionRoster_TransferFileUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6MissionRoster_TransferFileUnwind6, // State 6: previous state, cleanup action.
    0xffffffff, 0x0, // State 7: previous state, cleanup action.
};

// R6Game.dll data @ 1001b504 : native typed-pointer and catch-all handler pair
const unsigned int UR6MissionRoster_TransferFileCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::UR6MissionRoster_TransferFileCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6MissionRoster_TransferFileCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b524 : native C++ try-block ranges
const unsigned int UR6MissionRoster_TransferFileTryMap[5] = {
    0x0, 0x6, 0x7, 0x2, R6GameAddresses::UR6MissionRoster_TransferFileCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b538 : native C++ exception function descriptor
const unsigned int UR6MissionRoster_TransferFileExceptionInfo[7] = {
    0x19930520, 0x8, R6GameAddresses::UR6MissionRoster_TransferFileUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6MissionRoster_TransferFileTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017c40 : UR6MissionRoster virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6MissionRoster_vftable[25] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6MissionRoster_VectorDeletingDestructor, // +0xc: UR6MissionRoster::VectorDeletingDestructor
    R6GameAddresses::ForwardImported_UObject_ProcessEvent, // +0x10: UObject::ProcessEvent
    R6GameAddresses::ForwardImported_UObject_ProcessDelegate, // +0x14: UObject::ProcessDelegate
    R6GameAddresses::ForwardImported_UObject_ProcessState, // +0x18: UObject::ProcessState
    R6GameAddresses::ForwardImported_UObject_ProcessRemoteFunction, // +0x1c: UObject::ProcessRemoteFunction
    R6GameAddresses::ForwardImported_UObject_Modify, // +0x20: UObject::Modify
    R6GameAddresses::ForwardImported_UObject_PostLoad, // +0x24: UObject::PostLoad
    R6GameAddresses::ForwardImported_UObject_Destroy, // +0x28: UObject::Destroy
    R6GameAddresses::ForwardImported_UObject_Serialize, // +0x2c: UObject::Serialize
    R6GameAddresses::ForwardImported_UObject_IsPendingKill, // +0x30: UObject::IsPendingKill
    R6GameAddresses::ForwardImported_UObject_GotoState, // +0x34: UObject::GotoState
    R6GameAddresses::ForwardImported_UObject_GotoLabel, // +0x38: UObject::GotoLabel
    R6GameAddresses::ForwardImported_UObject_InitExecution, // +0x3c: UObject::InitExecution
    R6GameAddresses::ForwardImported_UObject_ShutdownAfterError, // +0x40: UObject::ShutdownAfterError
    R6GameAddresses::ForwardImported_UObject_PostEditChange, // +0x44: UObject::PostEditChange
    R6GameAddresses::ForwardImported_UObject_CallFunction, // +0x48: UObject::CallFunction
    R6GameAddresses::ForwardImported_UObject_ScriptConsoleExec, // +0x4c: UObject::ScriptConsoleExec
    R6GameAddresses::ForwardImported_UObject_Register, // +0x50: UObject::Register
    R6GameAddresses::ForwardImported_UObject_LanguageChange, // +0x54: UObject::LanguageChange
    R6GameAddresses::ForwardImported_UObject_IsPendingDelete, // +0x58: UObject::IsPendingDelete
    R6GameAddresses::ForwardImported_UObject_GetPropertiesSize, // +0x5c: UObject::GetPropertiesSize
    R6GameAddresses::ForwardImported_UObject_NetDirty, // +0x60: UObject::NetDirty
};

// R6Game.dll @ 10002c80 : return the UR6MissionRoster class object
UClass* __cdecl UR6MissionRoster::StaticClass(void)
{
    return (UClass*)UR6MissionRosterClassMetadataStorage;
}

// R6Game.dll @ 10002c90 : allocate a mission roster using its class and object parameters
void* __cdecl UR6MissionRoster::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6MissionRosterClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100052f0 : assign UObject state and copy the operative-pointer array into separate storage
UR6MissionRoster* __thiscall UR6MissionRoster::operator=(UR6MissionRoster* this, const UR6MissionRoster* source)
{
    UObject::operator=((UObject*)this, (const UObject*)source);
    AssignFourByteFArray((FArray*)&this->m_MissionOperatives, (const FArray*)&source->m_MissionOperatives);
    return this;
}

// R6Game.dll @ 10006ab0 : conditionally shut down the roster, release its pointer array, then destroy UObject
void __thiscall UR6MissionRoster::~UR6MissionRoster(UR6MissionRoster* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6MissionRosterExceptionDispatcher1;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; FuncInfo 0x1001ac54 unwinds array state 1 to UObject state 0, then -1.
    *(const uint**)this = UR6MissionRoster_vftable;
    exceptionRegistration.state = 1;
    UObject::ConditionalDestroy((UObject*)this);
    *(byte*)&exceptionRegistration.state = 0;
    DestroyFourByteFArray((FArray*)&this->m_MissionOperatives); // +0x2c; does not destroy pointed-to operatives.
    exceptionRegistration.state = -1;
    UObject::~UObject((UObject*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10006b10 : construct UObject and install the roster vtable
UR6MissionRoster* __thiscall UR6MissionRoster::UR6MissionRoster(UR6MissionRoster* this)
{
    UObject::UObject((UObject*)this);
    *(const uint**)this = UR6MissionRoster_vftable;
    return this;
}

// R6Game.dll @ 10006b30 : copy UObject state and construct a new array of operative pointers
UR6MissionRoster* __thiscall UR6MissionRoster::UR6MissionRoster(UR6MissionRoster* this, const UR6MissionRoster* source)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6MissionRosterExceptionDispatcher2;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; FuncInfo 0x1001ac78 unwinds the completed UObject base at state 0.
    UObject::UObject((UObject*)this, (const UObject*)source);
    exceptionRegistration.state = 0;
    *(const uint**)this = UR6MissionRoster_vftable;
    ConstructFourByteFArrayCopyWithAdd((FArray*)&this->m_MissionOperatives,
        (const FArray*)&source->m_MissionOperatives);
    __writefsdword(0, exceptionRegistration.previousAddress);
    return this;
}

// R6Game.dll @ 10006b90 : destroy one mission roster or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6MissionRoster::VectorDeletingDestructor(UR6MissionRoster* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x38, elementCount,
            (_func_void_void_ptr*)UR6MissionRoster::~UR6MissionRoster);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6MissionRoster::~UR6MissionRoster(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x38);
    return this;
}

// R6Game.dll @ 10006e60 : construct a mission roster in supplied memory when nonnull
void __cdecl UR6MissionRoster::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6MissionRoster::UR6MissionRoster((UR6MissionRoster*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 1000a4b0 : TransferFile
// Transfers roster slots, operative class paths and each operative's saved state.
void __thiscall UR6MissionRoster::TransferFile(UR6MissionRoster* this, FArchive* archive)
{
    alignas(4) byte pathStorage[12], classNameStorage[12], dotStorage[12], outerNameStorage[12];
    alignas(4) byte prefixStorage[12], completeStorage[12];
    FString* classPath = (FString*)pathStorage;
    FString* className = (FString*)classNameStorage;
    FString* dot = (FString*)dotStorage;
    FString* outerName = (FString*)outerNameStorage;
    FString* prefix = (FString*)prefixStorage;
    FString* complete = (FString*)completeStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6MissionRoster_ExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP and the roster receiver are saved at frame -0x10 and -0x18.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    FString::FString(classPath);
    FArchive* currentArchive = archive;
    *(byte*)&exceptionRegistration.state = 1;
    FArray* operativeArray = (FArray*)&this->m_MissionOperatives;
    SerializeFArray(currentArchive, operativeArray);
    for (int index = 0; index < *(int*)((byte*)operativeArray + 4); index = (int)((uint)index + 1U)) {
        if (*(int*)((byte*)currentArchive + 0x18) != 0) { // ArIsSaving takes precedence over ArIsLoading.
            UObject* operative = (*(UObject***)operativeArray)[index];
            UClass* operativeClass = *(UClass**)((byte*)operative + 0x24);
            FString* classNameValue = FString::FString(className, UObject::GetName((UObject*)operativeClass));
            *(byte*)&exceptionRegistration.state = 2;
            FString* dotValue = FString::FString(dot, (ushort*)L".");
            operative = (*(UObject***)operativeArray)[index];
            operativeClass = *(UClass**)((byte*)operative + 0x24);
            UObject* classOuter = *(UObject**)((byte*)operativeClass + 0x18);
            *(byte*)&exceptionRegistration.state = 3;
            FString* outerNameValue = FString::FString(outerName, UObject::GetName(classOuter));
            *(byte*)&exceptionRegistration.state = 4;
            using StringSumCall = FString* (__thiscall *)(FString*, FString*, const FString*);
            StringSumCall stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
            FString* prefixValue = stringSum(outerNameValue, prefix, dotValue);
            *(byte*)&exceptionRegistration.state = 5;
            stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
            FString* completeValue = stringSum(prefixValue, complete, classNameValue);
            *(byte*)&exceptionRegistration.state = 6;
            FString::operator=(classPath, completeValue);
            *(byte*)&exceptionRegistration.state = 5;
            FString::~FString(complete);
            *(byte*)&exceptionRegistration.state = 4;
            FString::~FString(prefix);
            *(byte*)&exceptionRegistration.state = 3;
            FString::~FString(outerName);
            *(byte*)&exceptionRegistration.state = 2;
            FString::~FString(dot);
            *(byte*)&exceptionRegistration.state = 1;
            FString::~FString(className);
            FArchive* pathArchive = archive;
            operator<<(pathArchive, classPath);
            UObject** currentSlots = *(UObject***)operativeArray;
            currentArchive = archive;
            UR6Operative* currentOperative = (UR6Operative*)currentSlots[index];
            UR6Operative::TransferFile(currentOperative, currentArchive);
            continue;
        } else if (*(int*)((byte*)currentArchive + 0x14) != 0) { // ArIsLoading.
            operator<<(currentArchive, classPath);
            UClass* classConstraint = (UClass*)ImportedUClassClass;
            const ushort* classPathText = FString::operator*(classPath);
            using LoadObjectCall = UObject* (__cdecl*)(
                UClass*, UObject*, const ushort*, const ushort*, uint, UPackageMap*);
            LoadObjectCall loadObject = *(LoadObjectCall*)R6GameImports::Core_UObject_StaticLoadObjectSlot;
            UObject* loadedObject = loadObject(classConstraint, nullptr, classPathText, nullptr, 2, nullptr);
            UClass* targetClass = (UClass*)ImportedUClassClass;
            UClass* loadedClass = nullptr;
            if (loadedObject != nullptr) {
                UClass* cursor = *(UClass**)((byte*)loadedObject + 0x24);
                while (cursor != nullptr && cursor != targetClass)
                    cursor = *(UClass**)((byte*)cursor + 0x2c);
                if (cursor == targetClass)
                    loadedClass = (UClass*)loadedObject;
            }
            if (loadedClass == nullptr) {
                loadedObject = loadObject(targetClass, nullptr,
                    (ushort*)L"R6Game.R6RetiredOperative", nullptr, 2, nullptr);
                if (loadedObject != nullptr) {
                    UClass* cursor = *(UClass**)((byte*)loadedObject + 0x24);
                    targetClass = (UClass*)ImportedUClassClass;
                    while (cursor != nullptr && cursor != targetClass)
                        cursor = *(UClass**)((byte*)cursor + 0x2c);
                    if (cursor == targetClass)
                        loadedClass = (UClass*)loadedObject;
                }
            }
            FOutputDevice* errorOutput = *(FOutputDevice**)ImportedGErrorAddress;
            UPackage* outer = UObject::GetTransientPackage();
            UObject* constructed = UObject::StaticConstructObject(loadedClass, outer, FName(0), 0, nullptr,
                errorOutput, 0);
            UObject** loadedSlots = *(UObject***)operativeArray;
            currentArchive = archive;
            loadedSlots[index] = constructed;
        }
        UR6Operative* currentOperative = (UR6Operative*)(*(UObject***)operativeArray)[index];
        UR6Operative::TransferFile(currentOperative, currentArchive);
    }
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(classPath);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000a70c : rethrow roster transfer's caught UTF-16 pointer value
__declspec(naked) void UR6MissionRoster_TransferFileCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013ca0 : destroy UObject after the roster's array cleanup during destructor unwinding
__declspec(naked) void UR6MissionRoster_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 10013ca9 : release the roster's operative-pointer array if conditional shutdown unwinds
__declspec(naked) void UR6MissionRoster_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x2c
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013cc0 : destroy the completed UObject base if roster array copy construction unwinds
__declspec(naked) void UR6MissionRoster_CopyConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 10013ff0 : destroy roster transfer's class path during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ff9 : destroy roster transfer's class name during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x68]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014002 : destroy roster transfer's dot separator during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x5c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001400b : destroy roster transfer's outer name during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x50]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014014 : destroy roster transfer's path prefix during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x44]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001401d : destroy roster transfer's complete path during unwinding
__declspec(naked) void UR6MissionRoster_TransferFileUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x38]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014a10 : register R6MissionRoster class metadata and its cleanup
void InitializeUR6MissionRosterClassMetadata(void)
{
    UClass* objectClass = (UClass*)ImportedUObjectClass;
    auto staticConstructor = ImportedUObjectStaticConstructorAddress;
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6MissionRosterClassMetadataStorage, 0, 0x38, 0, objectClass, objectClass, FGuid(0, 0, 0, 0),
        L"R6MissionRoster", GPackage, configName, 0x4084004, UR6MissionRoster::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6MissionRosterClassMetadata);
}

// R6Game.dll @ 10015120 : destroy R6MissionRoster class metadata
void DestroyUR6MissionRosterClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6MissionRosterClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 10014a90 : bind the exported R6MissionRoster auto-class pointer
void InitializeUR6MissionRosterAutoClassPointer(void)
{
    autoclassUR6MissionRoster = (UClass*)UR6MissionRosterClassMetadataStorage; // Exported slot 0x10027970.
}

// R6Game.dll @ 1000a720 : report roster transfer context and forward the active exception
__declspec(naked) void UR6MissionRoster_TransferFileCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6MissionRoster_TransferFileExceptionContext // L"UR6MissionRoster::TransferFile"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014026 : dispatch roster transfer's guard, string cleanup and catch states
__declspec(naked) void UR6MissionRoster_ExceptionHandler(void)
{
    __asm { mov eax, offset UR6MissionRoster_TransferFileExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013cb4 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001ac54
__declspec(naked) void Shared_UR6MissionRosterExceptionDispatcher1(void)
{
    __asm { mov eax, offset UR6MissionRoster_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013cc9 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001ac78
__declspec(naked) void Shared_UR6MissionRosterExceptionDispatcher2(void)
{
    __asm { mov eax, offset UR6MissionRoster_CopyConstructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
