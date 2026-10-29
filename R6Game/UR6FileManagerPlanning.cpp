#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10024154 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6FileManagerPlanning::execLoadPlanning.
unsigned int intUR6FileManagerPlanningexecLoadPlanning = R6GameAddresses::UR6FileManagerPlanning_execLoadPlanning;

// R6Game.dll data @ 10024158 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6FileManagerPlanning::execSavePlanning.
unsigned int intUR6FileManagerPlanningexecSavePlanning = R6GameAddresses::UR6FileManagerPlanning_execSavePlanning;

// R6Game.dll data @ 1002415c : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6FileManagerPlanning::execGetNumberOfFiles.
unsigned int intUR6FileManagerPlanningexecGetNumberOfFiles = R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFiles;

// R6Game.dll data @ 10024be0 : class metadata storage
// Backing storage for UR6FileManagerPlanning::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6FileManagerPlanningClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10025b10 : native registration result byte
unsigned char UR6FileManagerPlanningexecLoadPlanningRegistrationResult = 0;

// R6Game.dll data @ 10025b11 : native registration result byte
unsigned char UR6FileManagerPlanningexecGetNumberOfFilesRegistrationResult = 0;

// R6Game.dll data @ 1002602d : native registration result byte
unsigned char UR6FileManagerPlanningexecSavePlanningRegistrationResult = 0;

// R6Game.dll data @ 10027e80 : auto-class pointer
UClass* autoclassUR6FileManagerPlanning = nullptr;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001ae74 : native C++ unwind-state transitions
const unsigned int UR6FileManagerPlanning_execLoadPlanningUnwindMap[30] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind9, // State 9: previous state, cleanup action.
    0x8, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind10, // State 10: previous state, cleanup action.
    0x8, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind11, // State 11: previous state, cleanup action.
    0x8, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind12, // State 12: previous state, cleanup action.
    0xc, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwind13, // State 13: previous state, cleanup action.
    0xffffffff, 0x0, // State 14: previous state, cleanup action.
};

// R6Game.dll data @ 1001aeec : native typed-pointer and catch-all handler pair
const unsigned int UR6FileManagerPlanning_execLoadPlanningCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff60, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001af0c : native C++ try-block ranges
const unsigned int UR6FileManagerPlanning_execLoadPlanningTryMap[5] = {
    0x0, 0xd, 0xe, 0x2, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001af20 : native C++ exception function descriptor
const unsigned int UR6FileManagerPlanning_execLoadPlanningExceptionInfo[7] = {
    0x19930520, 0xf, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001af3c : native C++ unwind-state transitions
const unsigned int UR6FileManagerPlanning_execSavePlanningUnwindMap[26] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind8, // State 8: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind9, // State 9: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind10, // State 10: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwind11, // State 11: previous state, cleanup action.
    0xffffffff, 0x0, // State 12: previous state, cleanup action.
};

// R6Game.dll data @ 1001afa4 : native typed-pointer and catch-all handler pair
const unsigned int UR6FileManagerPlanning_execSavePlanningCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001afc4 : native C++ try-block ranges
const unsigned int UR6FileManagerPlanning_execSavePlanningTryMap[5] = {
    0x0, 0xb, 0xc, 0x2, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001afd8 : native C++ exception function descriptor
const unsigned int UR6FileManagerPlanning_execSavePlanningExceptionInfo[7] = {
    0x19930520, 0xd, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execSavePlanningTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001aff4 : native C++ unwind-state transitions
const unsigned int UR6FileManagerPlanning_execGetNumberOfFilesUnwindMap[16] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind5, // State 5: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwind6, // State 6: previous state, cleanup action.
    0xffffffff, 0x0, // State 7: previous state, cleanup action.
};

// R6Game.dll data @ 1001b034 : native typed-pointer and catch-all handler pair
const unsigned int UR6FileManagerPlanning_execGetNumberOfFilesCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b054 : native C++ try-block ranges
const unsigned int UR6FileManagerPlanning_execGetNumberOfFilesTryMap[5] = {
    0x0, 0x6, 0x7, 0x2, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b068 : native C++ exception function descriptor
const unsigned int UR6FileManagerPlanning_execGetNumberOfFilesExceptionInfo[7] = {
    0x19930520, 0x8, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016df8 : UR6FileManagerPlanning virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6FileManagerPlanning_vftable[28] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6FileManagerPlanning_VectorDeletingDestructor, // +0xc: UR6FileManagerPlanning::VectorDeletingDestructor
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
    R6GameAddresses::ForwardImported_UR6FileManager_GetFileName, // +0x64: UR6FileManager::GetFileName
    R6GameAddresses::ForwardImported_UR6FileManager_GetNbFile, // +0x68: UR6FileManager::GetNbFile
    R6GameAddresses::ForwardImported_UR6FileManager_FindFile, // +0x6c: UR6FileManager::FindFile
};

// R6Game.dll @ 10002ad0 : return the UR6FileManagerPlanning class object
UClass* __cdecl UR6FileManagerPlanning::StaticClass(void)
{
    return (UClass*)UR6FileManagerPlanningClassMetadataStorage;
}

// R6Game.dll @ 10002ae0 : allocate a planning file manager using its class and object parameters
void* __cdecl UR6FileManagerPlanning::operator_new(
    uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6FileManagerPlanningClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10002b10 : conditionally shut down the planning file manager, then destroy its base
void __thiscall UR6FileManagerPlanning::~UR6FileManagerPlanning(UR6FileManagerPlanning* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&FileManagerDestructionExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; state 0 invokes shared base cleanup FileManagerDestructionUnwind.
    *(const uint**)this = UR6FileManagerPlanning_vftable;
    exceptionRegistration.state = 0;
    UObject::ConditionalDestroy((UObject*)this);
    exceptionRegistration.state = -1;
    UR6FileManager::~UR6FileManager((UR6FileManager*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10002b70 : construct the file-manager base and install the planning vtable
UR6FileManagerPlanning* __thiscall UR6FileManagerPlanning::UR6FileManagerPlanning(UR6FileManagerPlanning* this)
{
    UR6FileManager::UR6FileManager((UR6FileManager*)this);
    *(const uint**)this = UR6FileManagerPlanning_vftable;
    return this;
}

// R6Game.dll @ 10002b90 : copy the base, install the planning vtable, then copy the current team
UR6FileManagerPlanning* __thiscall UR6FileManagerPlanning::UR6FileManagerPlanning(
    UR6FileManagerPlanning* this, const UR6FileManagerPlanning* source)
{
    UR6FileManager::UR6FileManager((UR6FileManager*)this, (const UR6FileManager*)source);
    *(const uint**)this = UR6FileManagerPlanning_vftable;
    this->m_iCurrentTeam = source->m_iCurrentTeam; // +0x38.
    return this;
}

// R6Game.dll @ 10002bc0 : assign the file-manager base and current team, then return this manager
UR6FileManagerPlanning* __thiscall UR6FileManagerPlanning::operator=(
    UR6FileManagerPlanning* this, const UR6FileManagerPlanning* source)
{
    UR6FileManager::operator=((UR6FileManager*)this, (const UR6FileManager*)source);
    this->m_iCurrentTeam = source->m_iCurrentTeam; // +0x38.
    return this;
}

// R6Game.dll @ 10002be0 : destroy one planning file manager or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6FileManagerPlanning::VectorDeletingDestructor(UR6FileManagerPlanning* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x3c, elementCount,
            (_func_void_void_ptr*)UR6FileManagerPlanning::~UR6FileManagerPlanning);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6FileManagerPlanning::~UR6FileManagerPlanning(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x3c);
    return this;
}

// R6Game.dll @ 10003ea0 : construct a planning file manager in supplied memory when nonnull
void __cdecl UR6FileManagerPlanning::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6FileManagerPlanning::UR6FileManagerPlanning((UR6FileManagerPlanning*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 100071a0 : execLoadPlanning
// Loads planning records, returning saved map/game names when newer metadata mismatches the request.
void __thiscall UR6FileManagerPlanning::execLoadPlanning(UR6FileManagerPlanning* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using AppendSuffixCall = FString* (__thiscall *)(FString*, FString*, const ushort*);
    alignas(4) byte mapStorage[12], localizedMapStorage[12], englishGTStorage[12], gameTypeStorage[12];
    alignas(4) byte filenameStorage[12], mapFallbackStorage[12], gameTypeFallbackStorage[12], pathStorage[12];
    alignas(4) byte temporaryStorage[12], loadedGTStorage[12];
    FString* szMapName = (FString*)mapStorage;
    FString* szLocalizedMapName = (FString*)localizedMapStorage;
    FString* szEnglishGT = (FString*)englishGTStorage;
    FString* szGameType = (FString*)gameTypeStorage;
    FString* szFileName = (FString*)filenameStorage;
    FString* mapFallback = (FString*)mapFallbackStorage;
    FString* gameTypeFallback = (FString*)gameTypeFallbackStorage;
    FString* path = (FString*)pathStorage;
    FString* temporary = (FString*)temporaryStorage;
    FString* loadedGameType = (FString*)loadedGTStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6FileManagerPlanning_ExceptionHandler1;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP and the manager are saved at frame -0x10/-0x48; no reader unwind action exists.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6FileManagerPlanning* manager = this;
    exceptionRegistration.state = 0;
    FString::FString(szMapName);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* mapCode = *codeCursor;
    byte mapOpcode = *mapCode;
    UObject* mapOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)mapCode + 1U);
    ScriptNative* mapOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 1;
    mapOpcodeTable[mapOpcode](mapOpcodeContext, executionStack, szMapName);
    FString::FString(szLocalizedMapName);
    byte* localizedMapCode = *codeCursor;
    byte localizedMapOpcode = *localizedMapCode;
    UObject* localizedMapOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)localizedMapCode + 1U);
    ScriptNative* localizedMapOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 2;
    localizedMapOpcodeTable[localizedMapOpcode](localizedMapOpcodeContext, executionStack, szLocalizedMapName);
    FString::FString(szEnglishGT);
    byte* englishGTCode = *codeCursor;
    byte englishGTOpcode = *englishGTCode;
    UObject* englishGTOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)englishGTCode + 1U);
    ScriptNative* englishGTOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 3;
    englishGTOpcodeTable[englishGTOpcode](englishGTOpcodeContext, executionStack, szEnglishGT);
    FString::FString(szGameType);
    byte* gameTypeCode = *codeCursor;
    byte gameTypeOpcode = *gameTypeCode;
    UObject* gameTypeOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)gameTypeCode + 1U);
    ScriptNative* gameTypeOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 4;
    gameTypeOpcodeTable[gameTypeOpcode](gameTypeOpcodeContext, executionStack, szGameType);
    FString::FString(szFileName);
    byte* filenameCode = *codeCursor;
    byte filenameOpcode = *filenameCode;
    UObject* filenameOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)filenameCode + 1U);
    ScriptNative* filenameOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 5;
    filenameOpcodeTable[filenameOpcode](filenameOpcodeContext, executionStack, szFileName);
    UObject* startInfoContext = *(UObject**)((byte*)executionStack + 8);
    byte* startInfoCode = *codeCursor;
    AR6StartGameInfo* sgi = nullptr;
    byte startInfoOpcode = *startInfoCode;
    *codeCursor = (byte*)((uint)startInfoCode + 1U);
    ScriptNative* startInfoTable = (ScriptNative*)ImportedGNativesAddress;
    startInfoTable[startInfoOpcode](startInfoContext, executionStack, &sgi);
    FString::FString(mapFallback);
    *(void**)ImportedGPropAddrAddress = nullptr;
    byte* mapErrorCode = *codeCursor;
    byte mapErrorOpcode = *mapErrorCode;
    UObject* mapErrorOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)mapErrorCode + 1U);
    ScriptNative* mapErrorOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 6;
    mapErrorOpcodeTable[mapErrorOpcode](mapErrorOpcodeContext, executionStack, mapFallback);
    UObject* propertyObject = *(UObject**)ImportedGPropObjectAddress;
    if (propertyObject != nullptr) {
        UProperty* property = *(UProperty**)ImportedGPropertyAddress;
        auto markDirty = *(void (__thiscall**)(UObject*, UProperty*))(*(byte**)propertyObject + 0x60);
        markDirty(propertyObject, property);
    }
    FString* LoadErrorMsgMapName = *(FString**)ImportedGPropAddrAddress;
    if (LoadErrorMsgMapName == nullptr)
        LoadErrorMsgMapName = mapFallback;
    FString::FString(gameTypeFallback);
    *(void**)ImportedGPropAddrAddress = nullptr;
    byte* gameTypeErrorCode = *codeCursor;
    byte gameTypeErrorOpcode = *gameTypeErrorCode;
    UObject* gameTypeErrorOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)gameTypeErrorCode + 1U);
    ScriptNative* gameTypeErrorOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 7;
    gameTypeErrorOpcodeTable[gameTypeErrorOpcode](gameTypeErrorOpcodeContext, executionStack, gameTypeFallback);
    propertyObject = *(UObject**)ImportedGPropObjectAddress;
    if (propertyObject != nullptr) {
        UProperty* property = *(UProperty**)ImportedGPropertyAddress;
        auto markDirty = *(void (__thiscall**)(UObject*, UProperty*))(*(byte**)propertyObject + 0x60);
        markDirty(propertyObject, property);
    }
    FString* LoadErrorMsgGameType = *(FString**)ImportedGPropAddrAddress;
    if (LoadErrorMsgGameType == nullptr)
        LoadErrorMsgGameType = gameTypeFallback;
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugTable = (ScriptNative*)ImportedGNativesAddress;
        debugTable[0x42](debugContext, executionStack, nullptr);
    }
    FString::FString(path);
    *(uint*)result = 0;
    *(byte*)&exceptionRegistration.state = 8;
    FString::operator=(path, (ushort*)L"..\\Save\\Plan\\");
    AppendSuffixCall appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
    FString* suffixedName = appendSuffix(szLocalizedMapName, temporary, (ushort*)L"\\");
    *(byte*)&exceptionRegistration.state = 9;
    FString::operator+=(path, suffixedName);
    *(byte*)&exceptionRegistration.state = 8;
    FString::~FString(temporary);
    int gameTypeCount = *(int*)((byte*)szGameType + 4);
    if (gameTypeCount != 0 && gameTypeCount != 1) {
        appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
        suffixedName = appendSuffix(szGameType, temporary, (ushort*)L"\\");
        *(byte*)&exceptionRegistration.state = 10;
        FString::operator+=(path, suffixedName);
        *(byte*)&exceptionRegistration.state = 8;
        FString::~FString(temporary);
    }
    FString::operator+=(path, szFileName);
    const ushort* pathText = FString::operator*(path);
    using SubstringCall = ushort* (__cdecl*)(const ushort*, const ushort*);
    SubstringCall findSubstring = *(SubstringCall*)R6GameImports::Core_appStrstrSlot;
    if (findSubstring(pathText, L".pln") == nullptr &&
        findSubstring(FString::operator*(path), L".PLN") == nullptr) {
        FString* suffix = FString::FString(temporary, (ushort*)L".pln");
        *(byte*)&exceptionRegistration.state = 11;
        FString::operator+=(path, suffix);
        *(byte*)&exceptionRegistration.state = 8;
        FString::~FString(temporary);
    }
    const ushort* filename = FString::operator*(path);
    FFileManager* fileManager = *(FFileManager**)ImportedGFileManagerAddress;
    auto readerCall = *(FArchive* (__thiscall**)(FFileManager*, const ushort*, uint, FOutputDevice*))
        (*(byte**)fileManager + 4);
    FArchive* archive = readerCall(fileManager, filename, 0, nullptr);
    if (archive != nullptr) {
        int* version = (int*)((byte*)archive + 4);
        FArchive::ByteOrderSerialize(archive, version, 4);
        if (*version > 2) {
            FString::FString(temporary);
            *(byte*)&exceptionRegistration.state = 12;
            FString::FString(loadedGameType);
            using StringTransferCall = FArchive* (__cdecl*)(FArchive*, FString*);
            StringTransferCall transferString = *(StringTransferCall*)R6GameImports::Core_SerializeFStringSlot;
            *(byte*)&exceptionRegistration.state = 13;
            transferString(archive, temporary);
            transferString(archive, loadedGameType);
            if (*version > 6 && (FString::operator!=(temporary, szMapName) != 0 ||
                FString::operator!=(loadedGameType, szEnglishGT) != 0)) {
                FString::operator=(LoadErrorMsgMapName, temporary);
                FString::operator=(LoadErrorMsgGameType, loadedGameType);
                auto closeArchive = *(int (__thiscall**)(FArchive*))(*(byte**)archive + 0x50);
                closeArchive(archive);
                *(byte*)&exceptionRegistration.state = 12;
                FString::~FString(loadedGameType);
                *(byte*)&exceptionRegistration.state = 8;
                FString::~FString(temporary);
                goto cleanupInputs;
            }
            FArchive::ByteOrderSerialize(archive, &manager->m_iCurrentTeam, 4);
            *(byte*)&exceptionRegistration.state = 12;
            FString::~FString(loadedGameType);
            *(byte*)&exceptionRegistration.state = 8;
            FString::~FString(temporary);
        }
        AR6StartGameInfo* teamStartInfo = sgi;
        uint firstTeamFlags = *(uint*)((byte*)teamStartInfo + 0x3a4);
        AR6TeamStartInfo* firstTeam = teamStartInfo->m_TeamInfo[0];
        using TeamTransferCall = void (__thiscall*)(AR6TeamStartInfo*, FArchive*, int);
        TeamTransferCall transferTeam = *(TeamTransferCall*)R6GameImports::Engine_AR6TeamStartInfo_TransferFileSlot;
        transferTeam(firstTeam, archive, (firstTeamFlags >> 2) & 1);
        teamStartInfo = sgi;
        int secondReload = (*(uint*)((byte*)teamStartInfo + 0x3a4) >> 2) & 1;
        AR6TeamStartInfo* secondTeam = teamStartInfo->m_TeamInfo[1];
        transferTeam(secondTeam, archive, secondReload);
        teamStartInfo = sgi;
        uint thirdTeamFlags = *(uint*)((byte*)teamStartInfo + 0x3a4);
        AR6TeamStartInfo* thirdTeam = teamStartInfo->m_TeamInfo[2];
        transferTeam(thirdTeam, archive, (thirdTeamFlags >> 2) & 1);
        *(uint*)((byte*)sgi + 0x3a4) &= ~4U; // m_ReloadActionPointOnly.
        auto deleteArchive = *(void* (__thiscall**)(FArchive*, uint))(*(byte**)archive);
        deleteArchive(archive, 1);
        *(uint*)result = 1;
    }
cleanupInputs:
    *(byte*)&exceptionRegistration.state = 7;
    FString::~FString(path);
    *(byte*)&exceptionRegistration.state = 6;
    FString::~FString(gameTypeFallback);
    *(byte*)&exceptionRegistration.state = 5;
    FString::~FString(mapFallback);
    *(byte*)&exceptionRegistration.state = 4;
    FString::~FString(szFileName);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(szGameType);
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(szEnglishGT);
    *(byte*)&exceptionRegistration.state = 1;
    FString::~FString(szLocalizedMapName);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(szMapName);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10007695 : rethrow LoadPlanning's caught UTF-16 pointer value
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0xa0]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x44]
        push eax
        mov dword ptr [ebp-0x44],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10007700 : execSavePlanning
// Writes named planning data and three team records into a version-7 planning file.
void __thiscall UR6FileManagerPlanning::execSavePlanning(UR6FileManagerPlanning* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using AppendSuffixCall = FString* (__thiscall *)(FString*, FString*, const ushort*);
    using StringSumCall = FString* (__thiscall *)(FString*, FString*, const FString*);
    alignas(4) byte mapStorage[12], localizedMapStorage[12], englishGTStorage[12], gameTypeStorage[12];
    alignas(4) byte filenameStorage[12], directoryStorage[12], pathStorage[12], temporaryStorage[12];
    FString* szMapName = (FString*)mapStorage;
    FString* szLocalizedMapName = (FString*)localizedMapStorage;
    FString* szEnglishGT = (FString*)englishGTStorage;
    FString* szGameType = (FString*)gameTypeStorage;
    FString* szFileName = (FString*)filenameStorage;
    FString* directory = (FString*)directoryStorage;
    FString* path = (FString*)pathStorage;
    FString* temporary = (FString*)temporaryStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6FileManagerPlanning_ExceptionHandler2;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP and the manager are saved at frame -0x10/-0x18; no writer unwind action exists.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6FileManagerPlanning* manager = this;
    exceptionRegistration.state = 0;
    FString::FString(szMapName);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* mapCode = *codeCursor;
    byte mapOpcode = *mapCode;
    UObject* mapOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)mapCode + 1U);
    ScriptNative* mapOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 1;
    mapOpcodeTable[mapOpcode](mapOpcodeContext, executionStack, szMapName);
    FString::FString(szLocalizedMapName);
    byte* localizedMapCode = *codeCursor;
    byte localizedMapOpcode = *localizedMapCode;
    UObject* localizedMapOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)localizedMapCode + 1U);
    ScriptNative* localizedMapOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 2;
    localizedMapOpcodeTable[localizedMapOpcode](localizedMapOpcodeContext, executionStack, szLocalizedMapName);
    FString::FString(szEnglishGT);
    byte* englishGTCode = *codeCursor;
    byte englishGTOpcode = *englishGTCode;
    UObject* englishGTOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)englishGTCode + 1U);
    ScriptNative* englishGTOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 3;
    englishGTOpcodeTable[englishGTOpcode](englishGTOpcodeContext, executionStack, szEnglishGT);
    FString::FString(szGameType);
    byte* gameTypeCode = *codeCursor;
    byte gameTypeOpcode = *gameTypeCode;
    UObject* gameTypeOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)gameTypeCode + 1U);
    ScriptNative* gameTypeOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 4;
    gameTypeOpcodeTable[gameTypeOpcode](gameTypeOpcodeContext, executionStack, szGameType);
    FString::FString(szFileName);
    byte* filenameCode = *codeCursor;
    byte filenameOpcode = *filenameCode;
    UObject* filenameOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)filenameCode + 1U);
    ScriptNative* filenameOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 5;
    filenameOpcodeTable[filenameOpcode](filenameOpcodeContext, executionStack, szFileName);
    UObject* startInfoContext = *(UObject**)((byte*)executionStack + 8);
    byte* startInfoCode = *codeCursor;
    AR6StartGameInfo* sgi = nullptr;
    byte startInfoOpcode = *startInfoCode;
    *codeCursor = (byte*)((uint)startInfoCode + 1U);
    ScriptNative* startInfoTable = (ScriptNative*)ImportedGNativesAddress;
    startInfoTable[startInfoOpcode](startInfoContext, executionStack, &sgi);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugTable = (ScriptNative*)ImportedGNativesAddress;
        debugTable[0x42](debugContext, executionStack, nullptr);
    }
    FString::FString(directory);
    *(byte*)&exceptionRegistration.state = 6;
    FString::FString(path);
    *(byte*)&exceptionRegistration.state = 7;
    FString::operator=(directory, (ushort*)L"..\\Save\\Plan\\");
    AppendSuffixCall appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
    FString* suffixedName = appendSuffix(szLocalizedMapName, temporary, (ushort*)L"\\");
    *(byte*)&exceptionRegistration.state = 8;
    FString::operator+=(directory, suffixedName);
    *(byte*)&exceptionRegistration.state = 7;
    FString::~FString(temporary);
    int gameTypeCount = *(int*)((byte*)szGameType + 4);
    if (gameTypeCount != 0 && gameTypeCount != 1) {
        appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
        suffixedName = appendSuffix(szGameType, temporary, (ushort*)L"\\");
        *(byte*)&exceptionRegistration.state = 9;
        FString::operator+=(directory, suffixedName);
        *(byte*)&exceptionRegistration.state = 7;
        FString::~FString(temporary);
    }
    const ushort* directoryText = FString::operator*(directory);
    FFileManager* fileManager = *(FFileManager**)ImportedGFileManagerAddress;
    auto directoryCall = *(int (__thiscall**)(FFileManager*, const ushort*, int))(*(byte**)fileManager + 0x24);
    directoryCall(fileManager, directoryText, 1);
    StringSumCall stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
    FString* completePath = stringSum(directory, temporary, szFileName);
    *(byte*)&exceptionRegistration.state = 10;
    FString::operator=(path, completePath);
    *(byte*)&exceptionRegistration.state = 7;
    FString::~FString(temporary);
    const ushort* pathText = FString::operator*(path);
    using SubstringCall = ushort* (__cdecl*)(const ushort*, const ushort*);
    SubstringCall findSubstring = *(SubstringCall*)R6GameImports::Core_appStrstrSlot;
    if (findSubstring(pathText, L".pln") == nullptr &&
        findSubstring(FString::operator*(path), L".PLN") == nullptr) {
        FString* suffix = FString::FString(temporary, (ushort*)L".pln");
        *(byte*)&exceptionRegistration.state = 11;
        FString::operator+=(path, suffix);
        *(byte*)&exceptionRegistration.state = 7;
        FString::~FString(temporary);
    }
    const ushort* filename = FString::operator*(path);
    FOutputDevice* errorOutput = *(FOutputDevice**)ImportedGNullAddress;
    fileManager = *(FFileManager**)ImportedGFileManagerAddress;
    auto writerCall = *(FArchive* (__thiscall**)(FFileManager*, const ushort*, uint, FOutputDevice*))
        (*(byte**)fileManager + 8);
    FArchive* archive = writerCall(fileManager, filename, 0, errorOutput);
    uint* output = (uint*)result;
    *output = 0;
    if (archive != nullptr) {
        int* version = (int*)((byte*)archive + 4);
        *version = 7;
        FArchive::ByteOrderSerialize(archive, version, 4);
        using StringTransferCall = FArchive* (__cdecl*)(FArchive*, FString*);
        StringTransferCall transferString = *(StringTransferCall*)R6GameImports::Core_SerializeFStringSlot;
        transferString(archive, szMapName);
        transferString(archive, szEnglishGT);
        FArchive::ByteOrderSerialize(archive, &manager->m_iCurrentTeam, 4);
        AR6TeamStartInfo* firstTeam = sgi->m_TeamInfo[0];
        using TeamTransferCall = void (__thiscall*)(AR6TeamStartInfo*, FArchive*, int);
        TeamTransferCall transferTeam = *(TeamTransferCall*)R6GameImports::Engine_AR6TeamStartInfo_TransferFileSlot;
        transferTeam(firstTeam, archive, 0);
        transferTeam(sgi->m_TeamInfo[1], archive, 0);
        transferTeam(sgi->m_TeamInfo[2], archive, 0);
        auto deleteArchive = *(void* (__thiscall**)(FArchive*, uint))(*(byte**)archive);
        deleteArchive(archive, 1);
        *output = 1;
    }
    *(byte*)&exceptionRegistration.state = 6;
    FString::~FString(path);
    *(byte*)&exceptionRegistration.state = 5;
    FString::~FString(directory);
    *(byte*)&exceptionRegistration.state = 4;
    FString::~FString(szFileName);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(szGameType);
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(szEnglishGT);
    *(byte*)&exceptionRegistration.state = 1;
    FString::~FString(szLocalizedMapName);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(szMapName);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10007a78 : rethrow SavePlanning's caught UTF-16 pointer value
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningCatchPointer(void)
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

// R6Game.dll @ 10007ae0 : execGetNumberOfFiles
// Counts planning files in the map directory, optionally narrowed to a game-type directory.
void __thiscall UR6FileManagerPlanning::execGetNumberOfFiles(UR6FileManagerPlanning* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using AppendSuffixCall = FString* (__thiscall *)(FString*, FString*, const ushort*);
    alignas(4) byte mapStorage[12], gameTypeStorage[12], directoryStorage[12], extensionStorage[12], suffixStorage[12];
    FString* MapName = (FString*)mapStorage;
    FString* szGameType = (FString*)gameTypeStorage;
    FString* directory = (FString*)directoryStorage;
    FString* extension = (FString*)extensionStorage;
    FString* suffixResult = (FString*)suffixStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6FileManagerPlanning_ExceptionHandler3;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; states 5/6 share suffix storage with separate cleanup actions.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    FString::FString(MapName);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* mapCode = *codeCursor;
    byte mapOpcode = *mapCode;
    UObject* mapOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)mapCode + 1U);
    ScriptNative* mapOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 1;
    mapOpcodeTable[mapOpcode](mapOpcodeContext, executionStack, MapName);
    FString::FString(szGameType);
    byte* gameTypeCode = *codeCursor;
    byte gameTypeOpcode = *gameTypeCode;
    UObject* gameTypeOpcodeContext = *(UObject**)((byte*)executionStack + 8);
    *codeCursor = (byte*)((uint)gameTypeCode + 1U);
    ScriptNative* gameTypeOpcodeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 2;
    gameTypeOpcodeTable[gameTypeOpcode](gameTypeOpcodeContext, executionStack, szGameType);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugTable = (ScriptNative*)ImportedGNativesAddress;
        debugTable[0x42](debugContext, executionStack, nullptr);
    }
    FString::FString(directory);
    *(byte*)&exceptionRegistration.state = 3;
    FString::FString(extension, (ushort*)L"pln");
    *(byte*)&exceptionRegistration.state = 4;
    FString::operator=(directory, (ushort*)L"..\\Save\\Plan\\");
    AppendSuffixCall appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
    FString* suffixedName = appendSuffix(MapName, suffixResult, (ushort*)L"\\");
    *(byte*)&exceptionRegistration.state = 5;
    FString::operator+=(directory, suffixedName);
    *(byte*)&exceptionRegistration.state = 4;
    FString::~FString(suffixResult);
    int gameTypeCount = *(int*)((byte*)szGameType + 4);
    if (gameTypeCount != 0 && gameTypeCount != 1) {
        appendSuffix = *(AppendSuffixCall*)R6GameImports::Core_FString_OperatorAddTextSlot;
        suffixedName = appendSuffix(szGameType, suffixResult, (ushort*)L"\\");
        *(byte*)&exceptionRegistration.state = 6;
        FString::operator+=(directory, suffixedName);
        *(byte*)&exceptionRegistration.state = 4;
        FString::~FString(suffixResult);
    }
    using GetNbFileCall = int (__thiscall *)(UR6FileManagerPlanning*, FString*, FString*);
    GetNbFileCall getNbFile = *(GetNbFileCall*)(*(byte**)this + 0x68);
    getNbFile(this, directory, extension);
    uint fileCount = *(uint*)((byte*)&this->m_pFileList + 4); // Ignore the enumeration call's return.
    uint* output = (uint*)result;
    *output = fileCount;
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(extension);
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(directory);
    *(byte*)&exceptionRegistration.state = 1;
    FString::~FString(szGameType);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(MapName);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10007c6d : rethrow file enumeration's caught UTF-16 pointer value
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013dc0 : destroy LoadPlanning's map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x9c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013dcc : destroy LoadPlanning's localized map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x90]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013dd8 : destroy LoadPlanning's English game type during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x78]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013de1 : destroy LoadPlanning's game type during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x54]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013dea : destroy LoadPlanning's file name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x6c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013df3 : destroy LoadPlanning's map-error fallback during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x84]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013dff : destroy LoadPlanning's game-type-error fallback during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind7(void)
{
    __asm {
        lea ecx,[ebp-0x60]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e08 : destroy LoadPlanning's path during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind8(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e11 : destroy LoadPlanning's map suffix during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind9(void)
{
    __asm {
        lea ecx,[ebp-0x20]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e1a : destroy LoadPlanning's game-type suffix during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind10(void)
{
    __asm {
        lea ecx,[ebp-0x20]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e23 : destroy LoadPlanning's extension temporary during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind11(void)
{
    __asm {
        lea ecx,[ebp-0x20]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e2c : destroy LoadPlanning's loaded map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind12(void)
{
    __asm {
        lea ecx,[ebp-0x20]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e35 : destroy LoadPlanning's loaded game type during unwinding
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningUnwind13(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e50 : destroy SavePlanning's map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x74]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e59 : destroy SavePlanning's localized map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x68]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e62 : destroy SavePlanning's English game type during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x5c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e6b : destroy SavePlanning's game type during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x44]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e74 : destroy SavePlanning's file name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x50]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e7d : destroy SavePlanning's directory during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x38]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e86 : destroy SavePlanning's path during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind7(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e8f : destroy SavePlanning's map suffix during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind8(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013e98 : destroy SavePlanning's game-type suffix during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind9(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ea1 : destroy SavePlanning's complete-path temporary during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind10(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013eaa : destroy SavePlanning's extension temporary during unwinding
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningUnwind11(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ec0 : destroy file enumeration's map name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x3c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ec9 : destroy file enumeration's game-type name during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ed2 : destroy file enumeration's directory during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013edb : destroy file enumeration's extension during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x48]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013ee4 : destroy file enumeration's map suffix temporary during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x54]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013eed : destroy file enumeration's game-type suffix temporary during unwinding
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x54]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014840 : register the planning file-manager class and its metadata cleanup
void InitializeUR6FileManagerPlanningClassMetadata(void)
{
    auto staticConstructor = ImportedUObjectStaticConstructorAddress;
    UClass* withinClass = (UClass*)ImportedUObjectClass;
    UClass* parentClass = (UClass*)ImportedUR6FileManagerClass;
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6FileManagerPlanningClassMetadataStorage, 0, 0x3c, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
        L"R6FileManagerPlanning", GPackage, configName, 0x4084004,
        UR6FileManagerPlanning::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6FileManagerPlanningClassMetadata);
}

// R6Game.dll @ 100150f0 : destroy planning file-manager class metadata
void DestroyUR6FileManagerPlanningClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6FileManagerPlanningClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 100148d0 : bind the exported planning file-manager auto-class pointer
void InitializeUR6FileManagerPlanningAutoClassPointer(void)
{
    autoclassUR6FileManagerPlanning = (UClass*)UR6FileManagerPlanningClassMetadataStorage; // Exported slot 0x10027e80.
}

// R6Game.dll @ 10007c81 : report execGetNumberOfFiles context and rethrow the active exception
__declspec(naked) void UR6FileManagerPlanning_execGetNumberOfFilesCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6FileManagerPlanning_execGetNumberOfFilesExceptionContext // L"UR6FileManagerPlanning::execGetNumberOfFiles"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov eax,dword ptr [esi+0xc]
        mov edx,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub eax,edx // Bytecode offset modulo 32 bits.
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013ef6 : dispatch file enumeration's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6FileManagerPlanning_ExceptionHandler3(void)
{
    __asm { mov eax, offset UR6FileManagerPlanning_execGetNumberOfFilesExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10007a8c : report execSavePlanning context and rethrow the active exception
__declspec(naked) void UR6FileManagerPlanning_execSavePlanningCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6FileManagerPlanning_execSavePlanningExceptionContext // L"UR6FileManagerPlanning::execSavePlanning"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov eax,dword ptr [esi+0xc]
        mov edx,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub eax,edx // Bytecode offset modulo 32 bits.
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013eb3 : dispatch SavePlanning's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6FileManagerPlanning_ExceptionHandler2(void)
{
    __asm { mov eax, offset UR6FileManagerPlanning_execSavePlanningExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100076ac : report execLoadPlanning context and rethrow the active exception
__declspec(naked) void UR6FileManagerPlanning_execLoadPlanningCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6FileManagerPlanning_execLoadPlanningExceptionContext // L"UR6FileManagerPlanning::execLoadPlanning"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013e3e : dispatch LoadPlanning's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6FileManagerPlanning_ExceptionHandler1(void)
{
    __asm { mov eax, offset UR6FileManagerPlanning_execLoadPlanningExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014f20 : register UR6FileManagerPlanning::execLoadPlanning at native index 1416
void InitializeUR6FileManagerPlanningNativeLoadPlanning(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6FileManagerPlanningexecLoadPlanning;
    byte& nativeRegistrationResult = UR6FileManagerPlanningexecLoadPlanningRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1416, nativeExecPointerWord);
}

// R6Game.dll @ 10014f40 : register UR6FileManagerPlanning::execSavePlanning at native index 1417
void InitializeUR6FileManagerPlanningNativeSavePlanning(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6FileManagerPlanningexecSavePlanning;
    byte& nativeRegistrationResult = UR6FileManagerPlanningexecSavePlanningRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1417, nativeExecPointerWord);
}

// R6Game.dll @ 10014f60 : register UR6FileManagerPlanning::execGetNumberOfFiles at native index 1418
void InitializeUR6FileManagerPlanningNativeGetNumberOfFiles(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6FileManagerPlanningexecGetNumberOfFiles;
    byte& nativeRegistrationResult = UR6FileManagerPlanningexecGetNumberOfFilesRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1418, nativeExecPointerWord);
}
