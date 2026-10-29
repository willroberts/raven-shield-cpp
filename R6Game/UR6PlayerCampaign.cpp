#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 100255f8 : auto-class pointer
UClass* autoclassUR6PlayerCampaign = nullptr;

// R6Game.dll data @ 10026a40 : class metadata storage
// Backing storage for UR6PlayerCampaign::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6PlayerCampaignClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a0bc : native C++ unwind-state transitions
const unsigned int UR6PlayerCampaign_DestructUnwindMap[6] = {
    0xffffffff, R6GameAddresses::UR6PlayerCampaign_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6PlayerCampaign_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6PlayerCampaign_DestructUnwind2, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001a0d4 : native C++ exception function descriptor
const unsigned int UR6PlayerCampaign_DestructExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::UR6PlayerCampaign_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a11c : native C++ unwind-state transitions
const unsigned int UR6PlayerCampaignUnwindMap[4] = {
    0xffffffff, R6GameAddresses::UR6PlayerCampaignUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6PlayerCampaignUnwind1, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a12c : native C++ exception function descriptor
const unsigned int UR6PlayerCampaignExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlayerCampaignUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016e68 : UR6PlayerCampaign virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6PlayerCampaign_vftable[25] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6PlayerCampaign_VectorDeletingDestructor, // +0xc: UR6PlayerCampaign::VectorDeletingDestructor
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

// R6Game.dll @ 10002cc0 : return the UR6PlayerCampaign class object
UClass* __cdecl UR6PlayerCampaign::StaticClass(void)
{
    return (UClass*)UR6PlayerCampaignClassMetadataStorage;
}

// R6Game.dll @ 10002cd0 : allocate a player campaign using its class and object parameters
void* __cdecl UR6PlayerCampaign::operator_new(
    uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6PlayerCampaignClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10002d00 : destroy owned resources and inherited state
// Shuts down, destroys the campaign and player filenames, then destroys UObject.
void __thiscall UR6PlayerCampaign::~UR6PlayerCampaign(UR6PlayerCampaign *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6PlayerCampaignExceptionDispatcher1;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = UR6PlayerCampaign_vftable;
  // FuncInfo 0x1001a0d4 unwinds states 2, 1 and 0 through both strings and UObject.
  exceptionRegistration.state = 2;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_CampaignFileName); // +0x48.
  *(byte*)&exceptionRegistration.state = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_FileName); // +0x3c.
  exceptionRegistration.state = -1;
  UObject::~UObject((UObject *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10002d70 : construct UObject and the two no-init filename members
UR6PlayerCampaign * __thiscall UR6PlayerCampaign::UR6PlayerCampaign(UR6PlayerCampaign *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6PlayerCampaignExceptionDispatcher2;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  UObject::UObject((UObject *)this);
  // Shared construction FuncInfo 0x1001a12c protects UObject, then the completed m_FileName.
  exceptionRegistration.state = 0;
  *(const uint**)this = UR6PlayerCampaign_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_FileName);
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_CampaignFileName);
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10002dd0 : copy-construct inherited state and members
// Copies UObject, one byte, three dwords and both owned filename strings.
UR6PlayerCampaign * __thiscall UR6PlayerCampaign::UR6PlayerCampaign(UR6PlayerCampaign *this,
    const UR6PlayerCampaign *source)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6PlayerCampaignExceptionDispatcher2;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  UObject::UObject((UObject *)this, (const UObject *)source);
  *(const uint**)this = UR6PlayerCampaign_vftable;
  this->m_bCampaignCompleted = source->m_bCampaignCompleted; // Byte +0x2c; padding +0x2d..+0x2f is untouched.
  this->m_iDifficultyLevel = source->m_iDifficultyLevel; // +0x30.
  this->m_iNoMission = source->m_iNoMission; // +0x34.
  auto copiedMissionDetails = source->m_OperativesMissionDetails; // +0x38; native read precedes state zero.
  exceptionRegistration.state = 0;
  this->m_OperativesMissionDetails = copiedMissionDetails;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_FileName,
      (const FStringNoInit *)&source->m_FileName); // +0x3c.
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_CampaignFileName,
      (const FStringNoInit *)&source->m_CampaignFileName); // +0x48.
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10002e60 : assign inherited state and members
// Assigns UObject, one byte, three dwords and both filename strings without adding rollback.
UR6PlayerCampaign * __thiscall UR6PlayerCampaign::operator=(UR6PlayerCampaign *this, const UR6PlayerCampaign *source)
{
  UObject::operator=((UObject *)this, (const UObject *)source);
  this->m_bCampaignCompleted = source->m_bCampaignCompleted; // Byte +0x2c; padding +0x2d..+0x2f is untouched.
  this->m_iDifficultyLevel = source->m_iDifficultyLevel; // +0x30.
  this->m_iNoMission = source->m_iNoMission; // +0x34.
  this->m_OperativesMissionDetails = source->m_OperativesMissionDetails; // +0x38.
  FStringNoInit::operator=((FStringNoInit *)&this->m_FileName,
      (const FStringNoInit *)&source->m_FileName); // +0x3c.
  FStringNoInit::operator=((FStringNoInit *)&this->m_CampaignFileName,
      (const FStringNoInit *)&source->m_CampaignFileName); // +0x48.
  return this;
}

// R6Game.dll @ 10002eb0 : destroy one player campaign or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6PlayerCampaign::VectorDeletingDestructor(UR6PlayerCampaign* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x54, elementCount,
            (_func_void_void_ptr*)UR6PlayerCampaign::~UR6PlayerCampaign);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6PlayerCampaign::~UR6PlayerCampaign(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x54);
    return this;
}

// R6Game.dll @ 10003eb0 : construct a player campaign in supplied memory when nonnull
void __cdecl UR6PlayerCampaign::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6PlayerCampaign::UR6PlayerCampaign((UR6PlayerCampaign*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 10013590 : destroy UObject during player-campaign destructor unwinding
__declspec(naked) void UR6PlayerCampaign_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 10013599 : destroy the player filename during destructor unwinding
__declspec(naked) void UR6PlayerCampaign_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c // m_FileName.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100135a5 : destroy the campaign filename during destructor unwinding
__declspec(naked) void UR6PlayerCampaign_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x48 // m_CampaignFileName.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100135c0 : destroy UObject if player-campaign construction unwinds
__declspec(naked) void UR6PlayerCampaignUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 100135c9 : destroy the completed player filename if campaign-filename construction unwinds
__declspec(naked) void UR6PlayerCampaignUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c // m_FileName.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10014980 : construct player-campaign class metadata and register its process-exit destruction
void InitializeUR6PlayerCampaignClassMetadata(void)
{
    UClass* objectClass = (UClass*)ImportedUObjectClass;
    auto staticConstructor = ImportedUObjectStaticConstructorAddress; // Native four-byte member-function address.
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6PlayerCampaignClassMetadataStorage, 0, 0x54, 0, objectClass, objectClass, FGuid(0, 0, 0, 0),
        L"R6PlayerCampaign", GPackage, configName, 0x4084004,
        UR6PlayerCampaign::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6PlayerCampaignClassMetadata);
}

// R6Game.dll @ 10014a00 : bind the exported player-campaign auto-class pointer to its static metadata
void InitializeUR6PlayerCampaignAutoClassPointer(void)
{
    autoclassUR6PlayerCampaign = (UClass*)UR6PlayerCampaignClassMetadataStorage; // Exported pointer slot at 0x100255f8.
}

// R6Game.dll @ 10015110 : destroy the player-campaign class metadata through the imported class destructor
void DestroyUR6PlayerCampaignClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6PlayerCampaignClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 100135b1 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a0d4
__declspec(naked) void Shared_UR6PlayerCampaignExceptionDispatcher1(void)
{
    __asm { mov eax, offset UR6PlayerCampaign_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100135d5 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a12c
__declspec(naked) void Shared_UR6PlayerCampaignExceptionDispatcher2(void)
{
    __asm { mov eax, offset UR6PlayerCampaignExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
