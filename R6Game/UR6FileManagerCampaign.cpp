#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10024160 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6FileManagerCampaign::execLoadCampaign.
unsigned int intUR6FileManagerCampaignexecLoadCampaign = R6GameAddresses::UR6FileManagerCampaign_execLoadCampaign;

// R6Game.dll data @ 10024164 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6FileManagerCampaign::execSaveCampaign.
unsigned int intUR6FileManagerCampaignexecSaveCampaign = R6GameAddresses::UR6FileManagerCampaign_execSaveCampaign;

// R6Game.dll data @ 100250e8 : native registration result byte
unsigned char UR6FileManagerCampaignexecLoadCampaignRegistrationResult = 0;

// R6Game.dll data @ 100255fd : native registration result byte
unsigned char UR6FileManagerCampaignexecSaveCampaignRegistrationResult = 0;

// R6Game.dll data @ 1002796c : auto-class pointer
UClass* autoclassUR6FileManagerCampaign = nullptr;

// R6Game.dll data @ 10028898 : class metadata storage
// Backing storage for UR6FileManagerCampaign::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6FileManagerCampaignClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001b554 : native C++ unwind-state transitions
const unsigned int UR6FileManagerCampaign_execLoadCampaignUnwindMap[26] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind5, // State 5: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind9, // State 9: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind10, // State 10: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwind11, // State 11: previous state, cleanup action.
    0xffffffff, 0x0, // State 12: previous state, cleanup action.
};

// R6Game.dll data @ 1001b5bc : native typed-pointer and catch-all handler pair
const unsigned int UR6FileManagerCampaign_execLoadCampaignCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b5dc : native C++ try-block ranges
const unsigned int UR6FileManagerCampaign_execLoadCampaignTryMap[5] = {
    0x0, 0xb, 0xc, 0x2, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b5f0 : native C++ exception function descriptor
const unsigned int UR6FileManagerCampaign_execLoadCampaignExceptionInfo[7] = {
    0x19930520, 0xd, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b60c : native C++ unwind-state transitions
const unsigned int UR6FileManagerCampaign_execSaveCampaignUnwindMap[16] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind3, // State 3: previous state, cleanup action.
    0x2, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwind6, // State 6: previous state, cleanup action.
    0xffffffff, 0x0, // State 7: previous state, cleanup action.
};

// R6Game.dll data @ 1001b64c : native typed-pointer and catch-all handler pair
const unsigned int UR6FileManagerCampaign_execSaveCampaignCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b66c : native C++ try-block ranges
const unsigned int UR6FileManagerCampaign_execSaveCampaignTryMap[5] = {
    0x0, 0x6, 0x7, 0x2, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b680 : native C++ exception function descriptor
const unsigned int UR6FileManagerCampaign_execSaveCampaignExceptionInfo[7] = {
    0x19930520, 0x8, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016d88 : UR6FileManagerCampaign virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6FileManagerCampaign_vftable[28] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6FileManagerCampaign_VectorDeletingDestructor, // +0xc: UR6FileManagerCampaign::VectorDeletingDestructor
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

// R6Game.dll @ 10002970 : return the UR6FileManagerCampaign class object
UClass* __cdecl UR6FileManagerCampaign::StaticClass(void)
{
    return (UClass*)UR6FileManagerCampaignClassMetadataStorage;
}

// R6Game.dll @ 10002980 : allocate a campaign file manager using its class and object parameters
void* __cdecl UR6FileManagerCampaign::operator_new(
    uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6FileManagerCampaignClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100029b0 : conditionally shut down the campaign file manager, then destroy its base
void __thiscall UR6FileManagerCampaign::~UR6FileManagerCampaign(UR6FileManagerCampaign* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&FileManagerDestructionExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; state 0 invokes shared base cleanup FileManagerDestructionUnwind.
    *(const uint**)this = UR6FileManagerCampaign_vftable;
    exceptionRegistration.state = 0;
    UObject::ConditionalDestroy((UObject*)this);
    exceptionRegistration.state = -1;
    UR6FileManager::~UR6FileManager((UR6FileManager*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10002a10 : construct the file-manager base and install the campaign vtable
UR6FileManagerCampaign* __thiscall UR6FileManagerCampaign::UR6FileManagerCampaign(UR6FileManagerCampaign* this)
{
    UR6FileManager::UR6FileManager((UR6FileManager*)this);
    *(const uint**)this = UR6FileManagerCampaign_vftable;
    return this;
}

// R6Game.dll @ 10002a30 : copy the file-manager base and install the campaign vtable
UR6FileManagerCampaign* __thiscall UR6FileManagerCampaign::UR6FileManagerCampaign(
    UR6FileManagerCampaign* this, const UR6FileManagerCampaign* source)
{
    UR6FileManager::UR6FileManager((UR6FileManager*)this, (const UR6FileManager*)source);
    *(const uint**)this = UR6FileManagerCampaign_vftable;
    return this;
}

// R6Game.dll @ 10002a50 : assign the file-manager base and return this campaign manager
UR6FileManagerCampaign* __thiscall UR6FileManagerCampaign::operator=(
    UR6FileManagerCampaign* this, const UR6FileManagerCampaign* source)
{
    UR6FileManager::operator=((UR6FileManager*)this, (const UR6FileManager*)source);
    return this;
}

// R6Game.dll @ 10002a70 : destroy one campaign file manager or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6FileManagerCampaign::VectorDeletingDestructor(UR6FileManagerCampaign* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x38, elementCount,
            (_func_void_void_ptr*)UR6FileManagerCampaign::~UR6FileManagerCampaign);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6FileManagerCampaign::~UR6FileManagerCampaign(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x38);
    return this;
}

// R6Game.dll @ 10003e90 : construct a campaign file manager in supplied memory when nonnull
void __cdecl UR6FileManagerCampaign::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6FileManagerCampaign::UR6FileManagerCampaign((UR6FileManagerCampaign*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 1000a740 : execLoadCampaign
// Loads a player campaign from the mod directory or default fallback and transfers its roster.
void __thiscall UR6FileManagerCampaign::execLoadCampaign(UR6FileManagerCampaign* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using DirectoryCall = FString* (__thiscall *)(UR6ModMgr*, FString*);
    using StringSumCall = FString* (__thiscall *)(FString*, FString*, const FString*);
    alignas(4) byte pathStorage[12], temporaryAStorage[12], temporaryBStorage[12];
    alignas(4) byte temporaryCStorage[12], temporaryDStorage[12];
    FString* path = (FString*)pathStorage;
    FString* temporaryA = (FString*)temporaryAStorage; // Native frame -0x58.
    FString* temporaryB = (FString*)temporaryBStorage; // Native frame -0x4c.
    FString* temporaryC = (FString*)temporaryCStorage; // Native frame -0x40.
    FString* temporaryD = (FString*)temporaryDStorage; // Native frame -0x34.
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6FileManagerCampaign_ExceptionHandler1;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; the reader has no parent unwind cleanup action.
    __writefsdword(0, (uint)&exceptionRegistration);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* parameterCode = *codeCursor;
    UObject* parameterContext = *(UObject**)((byte*)executionStack + 8);
    UR6PlayerCampaign* MyCampaign = nullptr;
    byte campaignOpcode = *parameterCode;
    *codeCursor = (byte*)((uint)parameterCode + 1U);
    ScriptNative* parameterTable = (ScriptNative*)ImportedGNativesAddress;
    exceptionRegistration.state = 0;
    parameterTable[campaignOpcode](parameterContext, executionStack, &MyCampaign);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugTable = (ScriptNative*)ImportedGNativesAddress;
        debugTable[0x42](debugContext, executionStack, nullptr);
    }
    FString::FString(path);
    *(byte*)&exceptionRegistration.state = 1;
    FString* suffix = FString::FString(temporaryA, (ushort*)L".cmp");
    UR6ModMgr* modManager = *(UR6ModMgr**)ImportedGModMgrAddress;
    *(byte*)&exceptionRegistration.state = 2;
    DirectoryCall getDirectory = *(DirectoryCall*)R6GameImports::Engine_UR6ModMgr_eventGetCampaignDirSlot;
    FString* directory = getDirectory(modManager, temporaryB);
    UR6PlayerCampaign* pathCampaign = MyCampaign;
    *(byte*)&exceptionRegistration.state = 3;
    StringSumCall stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
    FString* namedPath = stringSum(directory, temporaryC, &pathCampaign->m_FileName);
    *(byte*)&exceptionRegistration.state = 4;
    stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
    FString* completePath = stringSum(namedPath, temporaryD, suffix);
    *(byte*)&exceptionRegistration.state = 5;
    FString::operator=(path, completePath);
    *(byte*)&exceptionRegistration.state = 4;
    FString::~FString(temporaryD);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(temporaryC);
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(temporaryB);
    *(byte*)&exceptionRegistration.state = 1;
    FString::~FString(temporaryA);
    const ushort* filename = FString::operator*(path);
    FFileManager* fileManager = *(FFileManager**)ImportedGFileManagerAddress;
    using ReaderCall = FArchive* (__thiscall *)(FFileManager*, const ushort*, uint, FOutputDevice*);
    ReaderCall readerCall = *(ReaderCall*)(*(byte**)fileManager + 4);
    FArchive* archive = readerCall(fileManager, filename, 0, nullptr);
    if (archive == nullptr) {
        suffix = FString::FString(temporaryD, (ushort*)L".cmp");
        modManager = *(UR6ModMgr**)ImportedGModMgrAddress;
        *(byte*)&exceptionRegistration.state = 6;
        getDirectory = *(DirectoryCall*)R6GameImports::Engine_UR6ModMgr_eventGetDefaultCampaignDirSlot;
        directory = getDirectory(modManager, temporaryC);
        pathCampaign = MyCampaign;
        *(byte*)&exceptionRegistration.state = 7;
        stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
        namedPath = stringSum(directory, temporaryB, &pathCampaign->m_FileName);
        *(byte*)&exceptionRegistration.state = 8;
        stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
        completePath = stringSum(namedPath, temporaryA, suffix);
        *(byte*)&exceptionRegistration.state = 9;
        FString::operator=(path, completePath);
        *(byte*)&exceptionRegistration.state = 8;
        FString::~FString(temporaryA);
        *(byte*)&exceptionRegistration.state = 7;
        FString::~FString(temporaryB);
        *(byte*)&exceptionRegistration.state = 6;
        FString::~FString(temporaryC);
        *(byte*)&exceptionRegistration.state = 1;
        FString::~FString(temporaryD);
        filename = FString::operator*(path);
        fileManager = *(FFileManager**)ImportedGFileManagerAddress;
        readerCall = *(ReaderCall*)(*(byte**)fileManager + 4);
        archive = readerCall(fileManager, filename, 0, nullptr);
    }
    *(uint*)result = 0;
    if (archive != nullptr) {
        FArchive::ByteOrderSerialize(archive, (byte*)archive + 4, 4);
        FArchive::ByteOrderSerialize(archive, &MyCampaign->m_iDifficultyLevel, 4);
        UR6PlayerCampaign* campaignForName = MyCampaign;
        int* missionNumber = &campaignForName->m_iNoMission;
        FArchive* campaignArchive = operator<<(archive, &campaignForName->m_CampaignFileName);
        FArchive::ByteOrderSerialize(campaignArchive, missionNumber, 4);
        using ArchiveSlot18 = FArchive* (__thiscall *)(FArchive*, UObject**);
        UR6PlayerCampaign* rosterCampaign = MyCampaign;
        ArchiveSlot18 transferRosterReference = *(ArchiveSlot18*)(*(byte**)campaignArchive + 0x18);
        transferRosterReference(campaignArchive, (UObject**)&rosterCampaign->m_OperativesMissionDetails);
        if (*(int*)((byte*)archive + 4) > 1) {
            using SerializeCall = void (__thiscall *)(FArchive*, void*, int);
            UR6PlayerCampaign* completionCampaign = MyCampaign;
            SerializeCall transferCompletion = *(SerializeCall*)(*(byte**)archive + 4);
            transferCompletion(archive, &completionCampaign->m_bCampaignCompleted, 1);
        }
        UR6MissionRoster::TransferFile(MyCampaign->m_OperativesMissionDetails, archive);
        auto flushArchive = *(void (__thiscall**)(FArchive*))(*(byte**)archive + 0x4c);
        flushArchive(archive);
        auto deleteArchive = *(void* (__thiscall**)(FArchive*, uint))(*(byte**)archive);
        deleteArchive(archive, 1);
        using CapsCall = FString* (__thiscall *)(const FString*, FString*);
        UR6PlayerCampaign* capsCampaign = MyCampaign;
        CapsCall uppercase = *(CapsCall*)R6GameImports::Core_FString_CapsSlot;
        FString* uppercaseName = uppercase(&capsCampaign->m_CampaignFileName, temporaryA);
        *(byte*)&exceptionRegistration.state = 10;
        bool chopSuffix = FString::InStr(uppercaseName, (ushort*)L".INI", 0) > 0;
        *(byte*)&exceptionRegistration.state = 1;
        FString::~FString(temporaryA);
        if (chopSuffix) {
            using LeftChopCall = FString* (__thiscall *)(const FString*, FString*, int);
            UR6PlayerCampaign* chopCampaign = MyCampaign;
            LeftChopCall leftChop = *(LeftChopCall*)R6GameImports::Core_FString_LeftChopSlot;
            FString* shortened = leftChop(&chopCampaign->m_CampaignFileName, temporaryA, 4);
            UR6PlayerCampaign* assignmentCampaign = MyCampaign;
            *(byte*)&exceptionRegistration.state = 11;
            FStringNoInit::operator=((FStringNoInit*)&assignmentCampaign->m_CampaignFileName, shortened);
            *(byte*)&exceptionRegistration.state = 1;
            FString::~FString(temporaryA);
        }
        *(uint*)result = 1;
    }
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(path);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000aa32 : rethrow LoadCampaign's caught UTF-16 pointer value
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000aa70 : execSaveCampaign
// Writes a named player campaign and mission roster, reporting whether a writer was available.
void __thiscall UR6FileManagerCampaign::execSaveCampaign(UR6FileManagerCampaign* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using StringSumCall = FString* (__thiscall *)(FString*, FString*, const FString*);
    alignas(4) byte pathStorage[12], directoryStorage[12], firstSumStorage[12];
    alignas(4) byte sharedResultStorage[12], suffixStorage[12];
    FString* path = (FString*)pathStorage;
    FString* directory = (FString*)directoryStorage;
    FString* firstSum = (FString*)firstSumStorage;
    FString* sharedResult = (FString*)sharedResultStorage;
    FString* suffix = (FString*)suffixStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6FileManagerCampaign_ExceptionHandler2;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; the writer has no parent unwind cleanup action.
    __writefsdword(0, (uint)&exceptionRegistration);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* parameterCode = *codeCursor;
    UObject* parameterContext = *(UObject**)((byte*)executionStack + 8);
    UR6PlayerCampaign* MyCampaign = nullptr;
    byte campaignOpcode = *parameterCode;
    *codeCursor = (byte*)((uint)parameterCode + 1U);
    ScriptNative* parameterTable = (ScriptNative*)ImportedGNativesAddress;
    exceptionRegistration.state = 0;
    parameterTable[campaignOpcode](parameterContext, executionStack, &MyCampaign);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugTable = (ScriptNative*)ImportedGNativesAddress;
        debugTable[0x42](debugContext, executionStack, nullptr);
    }
    FString::FString(path);
    *(byte*)&exceptionRegistration.state = 1;
    FString::FString(directory);
    uint* initialOutput = (uint*)result;
    UR6PlayerCampaign* filenameCampaign = MyCampaign;
    *initialOutput = 0;
    int filenameCount = *(int*)((byte*)&filenameCampaign->m_FileName + 4);
    *(byte*)&exceptionRegistration.state = 2;
    if (filenameCount != 0 && (int)((uint)filenameCount - 1U) > 0) {
        using CampaignDirCall = FString* (__thiscall *)(UR6ModMgr*, FString*);
        UR6ModMgr* modManager = *(UR6ModMgr**)ImportedGModMgrAddress;
        CampaignDirCall getCampaignDirectory = *(CampaignDirCall*)R6GameImports::Engine_UR6ModMgr_eventGetCampaignDirSlot;
        FString* directoryResult = getCampaignDirectory(modManager, sharedResult);
        *(byte*)&exceptionRegistration.state = 3;
        FString::operator=(directory, directoryResult);
        *(byte*)&exceptionRegistration.state = 2;
        FString::~FString(sharedResult);
        const ushort* directoryText = FString::operator*(directory);
        FFileManager* fileManager = *(FFileManager**)ImportedGFileManagerAddress;
        auto directoryCall = *(int (__thiscall**)(FFileManager*, const ushort*, int))(*(byte**)fileManager + 0x24);
        directoryCall(fileManager, directoryText, 1);
        FString* suffixValue = FString::FString(suffix, (ushort*)L".cmp");
        UR6PlayerCampaign* pathCampaign = MyCampaign;
        *(byte*)&exceptionRegistration.state = 4;
        StringSumCall stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
        FString* namedPath = stringSum(directory, firstSum, &pathCampaign->m_FileName);
        *(byte*)&exceptionRegistration.state = 5;
        stringSum = *(StringSumCall*)R6GameImports::Core_FString_OperatorAddStringSlot;
        FString* completePath = stringSum(namedPath, sharedResult, suffixValue);
        *(byte*)&exceptionRegistration.state = 6;
        FString::operator=(path, completePath);
        *(byte*)&exceptionRegistration.state = 5;
        FString::~FString(sharedResult);
        *(byte*)&exceptionRegistration.state = 4;
        FString::~FString(firstSum);
        *(byte*)&exceptionRegistration.state = 2;
        FString::~FString(suffix);
        const ushort* filename = FString::operator*(path);
        FOutputDevice* errorOutput = *(FOutputDevice**)ImportedGNullAddress;
        fileManager = *(FFileManager**)ImportedGFileManagerAddress;
        auto writerCall = *(FArchive* (__thiscall**)(FFileManager*, const ushort*, uint, FOutputDevice*))
            (*(byte**)fileManager + 8);
        FArchive* archive = writerCall(fileManager, filename, 0, errorOutput);
        if (archive != nullptr) {
            int* archiveVersion = (int*)((byte*)archive + 4);
            *archiveVersion = 4;
            FArchive::ByteOrderSerialize(archive, archiveVersion, 4);
            FArchive::ByteOrderSerialize(archive, &MyCampaign->m_iDifficultyLevel, 4);
            UR6PlayerCampaign* campaignForName = MyCampaign;
            int* missionNumber = &campaignForName->m_iNoMission;
            FArchive* campaignArchive = operator<<(archive, &campaignForName->m_CampaignFileName);
            FArchive::ByteOrderSerialize(campaignArchive, missionNumber, 4);
            using ArchiveSlot18 = FArchive* (__thiscall *)(FArchive*, UObject**);
            UR6PlayerCampaign* rosterCampaign = MyCampaign;
            ArchiveSlot18 transferRosterReference = *(ArchiveSlot18*)(*(byte**)campaignArchive + 0x18);
            FArchive* completionArchive = transferRosterReference(campaignArchive,
                (UObject**)&rosterCampaign->m_OperativesMissionDetails);
            using SerializeCall = void (__thiscall *)(FArchive*, void*, int);
            UR6PlayerCampaign* completionCampaign = MyCampaign;
            SerializeCall transferCompletion = *(SerializeCall*)(*(byte**)completionArchive + 4);
            transferCompletion(completionArchive, &completionCampaign->m_bCampaignCompleted, 1);
            UR6MissionRoster::TransferFile(MyCampaign->m_OperativesMissionDetails, archive);
            auto flushArchive = *(void (__thiscall**)(FArchive*))(*(byte**)archive + 0x4c);
            flushArchive(archive);
            auto deleteArchive = *(void* (__thiscall**)(FArchive*, uint))(*(byte**)archive);
            deleteArchive(archive, 1);
            *(uint*)result = 1;
        }
    }
    *(byte*)&exceptionRegistration.state = 1;
    FString::~FString(directory);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(path);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000aca2 : rethrow SaveCampaign's caught UTF-16 pointer value
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014030 : destroy LoadCampaign's path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014039 : destroy LoadCampaign's mod-path suffix during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x58]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014042 : destroy LoadCampaign's mod directory during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x4c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001404b : destroy LoadCampaign's mod named path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014054 : destroy LoadCampaign's mod complete path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001405d : destroy LoadCampaign's fallback suffix during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014066 : destroy LoadCampaign's default directory during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind7(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001406f : destroy LoadCampaign's default named path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind8(void)
{
    __asm {
        lea ecx,[ebp-0x4c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014078 : destroy LoadCampaign's default complete path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind9(void)
{
    __asm {
        lea ecx,[ebp-0x58]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014081 : destroy LoadCampaign's uppercase name during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind10(void)
{
    __asm {
        lea ecx,[ebp-0x58]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001408a : destroy LoadCampaign's chopped name during unwinding
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignUnwind11(void)
{
    __asm {
        lea ecx,[ebp-0x58]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140a0 : destroy SaveCampaign's path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140a9 : destroy SaveCampaign's directory during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140b2 : destroy SaveCampaign's directory-result temporary during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140bb : destroy SaveCampaign's suffix during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x58]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140c4 : destroy SaveCampaign's named path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x4c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100140cd : destroy SaveCampaign's complete path during unwinding
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100148e0 : register R6FileManagerCampaign class metadata and its cleanup
void InitializeUR6FileManagerCampaignClassMetadata(void)
{
    auto staticConstructor = ImportedUObjectStaticConstructorAddress;
    UClass* withinClass = (UClass*)ImportedUObjectClass;
    UClass* parentClass = (UClass*)ImportedUR6FileManagerClass;
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6FileManagerCampaignClassMetadataStorage, 0, 0x38, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
        L"R6FileManagerCampaign", GPackage, configName, 0x4084004,
        UR6FileManagerCampaign::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6FileManagerCampaignClassMetadata);
}

// R6Game.dll @ 10015100 : destroy R6FileManagerCampaign class metadata
void DestroyUR6FileManagerCampaignClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6FileManagerCampaignClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 10014970 : bind the exported R6FileManagerCampaign auto-class pointer
void InitializeUR6FileManagerCampaignAutoClassPointer(void)
{
    autoclassUR6FileManagerCampaign = (UClass*)UR6FileManagerCampaignClassMetadataStorage; // Exported slot 0x1002796c.
}

// R6Game.dll @ 1000acb6 : report SaveCampaign context and forward the active exception
__declspec(naked) void UR6FileManagerCampaign_execSaveCampaignCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6FileManagerCampaign_execSaveCampaignExceptionContext // L"UR6FileManagerCampaign::execSaveCampaign"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100140d6 : dispatch SaveCampaign's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6FileManagerCampaign_ExceptionHandler2(void)
{
    __asm { mov eax, offset UR6FileManagerCampaign_execSaveCampaignExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 1000aa46 : report LoadCampaign context and forward the active exception
__declspec(naked) void UR6FileManagerCampaign_execLoadCampaignCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6FileManagerCampaign_execLoadCampaignExceptionContext // L"UR6FileManagerCampaign::execLoadCampaign"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014093 : dispatch LoadCampaign's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6FileManagerCampaign_ExceptionHandler1(void)
{
    __asm { mov eax, offset UR6FileManagerCampaign_execLoadCampaignExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014f80 : register UR6FileManagerCampaign::execLoadCampaign at native index 1003
void InitializeUR6FileManagerCampaignNativeLoadCampaign(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6FileManagerCampaignexecLoadCampaign;
    byte& nativeRegistrationResult = UR6FileManagerCampaignexecLoadCampaignRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1003, nativeExecPointerWord);
}

// R6Game.dll @ 10014fa0 : register UR6FileManagerCampaign::execSaveCampaign at native index 1004
void InitializeUR6FileManagerCampaignNativeSaveCampaign(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6FileManagerCampaignexecSaveCampaign;
    byte& nativeRegistrationResult = UR6FileManagerCampaignexecSaveCampaignRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1004, nativeExecPointerWord);
}
