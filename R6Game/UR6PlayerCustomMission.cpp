#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10025b14 : auto-class pointer
UClass* autoclassUR6PlayerCustomMission = nullptr;

// R6Game.dll data @ 10027e88 : class metadata storage
// Backing storage for UR6PlayerCustomMission::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6PlayerCustomMissionClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a830 : native C++ unwind-state transitions
const unsigned int UR6PlayerCustomMission_DestructUnwindMap[6] = {
    0xffffffff, R6GameAddresses::UR6PlayerCustomMission_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6PlayerCustomMission_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6PlayerCustomMission_DestructUnwind2, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001a848 : native C++ exception function descriptor
const unsigned int UR6PlayerCustomMission_DestructExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::UR6PlayerCustomMission_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a864 : native C++ unwind-state transitions
const unsigned int UR6PlayerCustomMission_CopyConstructUnwindMap[4] = {
    0xffffffff, R6GameAddresses::UR6PlayerCustomMission_CopyConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6PlayerCustomMission_CopyConstructUnwind1, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a874 : native C++ exception function descriptor
const unsigned int UR6PlayerCustomMission_CopyConstructExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlayerCustomMission_CopyConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017728 : UR6PlayerCustomMission virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6PlayerCustomMission_vftable[25] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6PlayerCustomMission_VectorDeletingDestructor, // +0xc: UR6PlayerCustomMission::VectorDeletingDestructor
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

// R6Game.dll @ 10002f10 : return the UR6PlayerCustomMission class object
UClass* __cdecl UR6PlayerCustomMission::StaticClass(void)
{
    return (UClass*)UR6PlayerCustomMissionClassMetadataStorage;
}

// R6Game.dll @ 10002f20 : allocate custom-mission data using its class and object parameters
void* __cdecl UR6PlayerCustomMission::operator_new(
    uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6PlayerCustomMissionClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10005320 : destroy owned resources and inherited state
// Shuts down, releases unlock-count storage and filename strings, then destroys UObject.
void __thiscall UR6PlayerCustomMission::~UR6PlayerCustomMission(UR6PlayerCustomMission *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&CustomMissionDestructionExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = UR6PlayerCustomMission_vftable;
  // Native EBP-0x10 saves this; FuncInfo 0x1001a848 chains both arrays and UObject through states 2..0.
  exceptionRegistration.state = 2;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 1;
  DestroyFourByteFArray((FArray *)&this->m_iNbMapUnlock); // +0x38.
  *(byte*)&exceptionRegistration.state = 0;
  DestroyFStringArray((FArray *)&this->m_aCampaignFileName); // +0x2c.
  exceptionRegistration.state = -1;
  UObject::~UObject((UObject *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10005390 : construct UObject and install the custom-mission vtable
UR6PlayerCustomMission * __thiscall
UR6PlayerCustomMission::UR6PlayerCustomMission(UR6PlayerCustomMission *this)
{
  UObject::UObject((UObject *)this);
  *(const uint**)this = UR6PlayerCustomMission_vftable;
  return this;
}

// R6Game.dll @ 100053b0 : copy-construct inherited state and members
// Copies UObject, constructs the filename-string array, then copies four-byte unlock counts.
UR6PlayerCustomMission * __thiscall UR6PlayerCustomMission::UR6PlayerCustomMission(UR6PlayerCustomMission *this,
    const UR6PlayerCustomMission *source)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&CustomMissionCopyExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  UObject::UObject((UObject *)this, (const UObject *)source);
  // FuncInfo 0x1001a874 protects UObject at state 0 and the completed string array at state 1.
  exceptionRegistration.state = 0;
  *(const uint**)this = UR6PlayerCustomMission_vftable;
  ConstructFStringArrayCopy((FArray *)&this->m_aCampaignFileName, (const FArray *)&source->m_aCampaignFileName);
  *(byte*)&exceptionRegistration.state = 1;
  ConstructFourByteFArrayCopy((FArray *)&this->m_iNbMapUnlock, (const FArray *)&source->m_iNbMapUnlock);
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10005420 : assign inherited state and members
// Assigns UObject, filename strings and unlock counts in order, without adding rollback.
UR6PlayerCustomMission * __thiscall UR6PlayerCustomMission::operator=(UR6PlayerCustomMission *this,
    const UR6PlayerCustomMission *source)
{
  UObject::operator=((UObject *)this, (const UObject *)source);
  AssignFStringArray((FArray *)&this->m_aCampaignFileName, (const FArray *)&source->m_aCampaignFileName);
  AssignFourByteFArray((FArray *)&this->m_iNbMapUnlock, (const FArray *)&source->m_iNbMapUnlock);
  return this;
}

// R6Game.dll @ 10005450 : destroy one custom-mission object or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6PlayerCustomMission::VectorDeletingDestructor(UR6PlayerCustomMission* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x44, elementCount,
            (_func_void_void_ptr*)UR6PlayerCustomMission::~UR6PlayerCustomMission);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6PlayerCustomMission::~UR6PlayerCustomMission(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x44);
    return this;
}

// R6Game.dll @ 10006bf0 : construct custom-mission data in supplied memory when nonnull
void __cdecl UR6PlayerCustomMission::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6PlayerCustomMission::UR6PlayerCustomMission((UR6PlayerCustomMission*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 100137f0 : destroy UObject during custom-mission destructor unwinding
__declspec(naked) void UR6PlayerCustomMission_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 100137f9 : destroy filename strings during custom-mission destructor unwinding
__declspec(naked) void UR6PlayerCustomMission_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x2c // m_aCampaignFileName.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013804 : release unlock-count storage during custom-mission destructor unwinding
__declspec(naked) void UR6PlayerCustomMission_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x38 // m_iNbMapUnlock.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001380f : select custom-mission destruction cleanup metadata and tail-dispatch it
__declspec(naked) void CustomMissionDestructionExceptionHandler(void)
{
    __asm {
        mov eax, offset UR6PlayerCustomMission_DestructExceptionInfo
        jmp R6GameAddresses::CxxFrameHandler
    }
}

// R6Game.dll @ 10013820 : destroy UObject if custom-mission array construction unwinds
__declspec(naked) void UR6PlayerCustomMission_CopyConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 10013829 : destroy the completed filename array if unlock-array construction unwinds
__declspec(naked) void UR6PlayerCustomMission_CopyConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x2c // m_aCampaignFileName.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013834 : select custom-mission copy-construction cleanup metadata and tail-dispatch it
__declspec(naked) void CustomMissionCopyExceptionHandler(void)
{
    __asm {
        mov eax, offset UR6PlayerCustomMission_CopyConstructExceptionInfo
        jmp R6GameAddresses::CxxFrameHandler
    }
}

// R6Game.dll @ 100145d0 : construct custom-mission class metadata and register process-exit destruction
void InitializeUR6PlayerCustomMissionClassMetadata(void)
{
    UClass* objectClass = (UClass*)ImportedUObjectClass;
    auto staticConstructor = ImportedUObjectStaticConstructorAddress; // Native four-byte member-function address.
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6PlayerCustomMissionClassMetadataStorage, 0, 0x44, 0, objectClass, objectClass, FGuid(0, 0, 0, 0),
        L"R6PlayerCustomMission", GPackage, configName, 0x4084004,
        UR6PlayerCustomMission::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6PlayerCustomMissionClassMetadata);
}

// R6Game.dll @ 10014650 : bind the exported custom-mission auto-class pointer to its static metadata
void InitializeUR6PlayerCustomMissionAutoClassPointer(void)
{
    autoclassUR6PlayerCustomMission = (UClass*)UR6PlayerCustomMissionClassMetadataStorage; // Slot 0x10025b14.
}

// R6Game.dll @ 100150b0 : destroy custom-mission class metadata through the imported class destructor
void DestroyUR6PlayerCustomMissionClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6PlayerCustomMissionClassMetadataStorage); // Native tail jump.
}
