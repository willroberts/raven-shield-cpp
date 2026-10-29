#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 10026f50 : class metadata storage
// Backing storage for UR6Operative::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6OperativeClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10028da0 : auto-class pointer
UClass* autoclassUR6Operative = nullptr;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a774 : native C++ unwind-state transitions
const unsigned int UR6Operative_DestructUnwindMap[40] = {
    0xffffffff, R6GameAddresses::UR6Operative_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6Operative_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6Operative_DestructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6Operative_DestructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6Operative_DestructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6Operative_DestructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6Operative_DestructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::UR6Operative_DestructUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::UR6Operative_DestructUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::UR6Operative_DestructUnwind9, // State 9: previous state, cleanup action.
    0x9, R6GameAddresses::UR6Operative_DestructUnwind10, // State 10: previous state, cleanup action.
    0xa, R6GameAddresses::UR6Operative_DestructUnwind11, // State 11: previous state, cleanup action.
    0xb, R6GameAddresses::UR6Operative_DestructUnwind12, // State 12: previous state, cleanup action.
    0xc, R6GameAddresses::UR6Operative_DestructUnwind13, // State 13: previous state, cleanup action.
    0xd, R6GameAddresses::UR6Operative_DestructUnwind14, // State 14: previous state, cleanup action.
    0xe, R6GameAddresses::UR6Operative_DestructUnwind15, // State 15: previous state, cleanup action.
    0xf, R6GameAddresses::UR6Operative_DestructUnwind16, // State 16: previous state, cleanup action.
    0x10, R6GameAddresses::UR6Operative_DestructUnwind17, // State 17: previous state, cleanup action.
    0x11, R6GameAddresses::UR6Operative_DestructUnwind18, // State 18: previous state, cleanup action.
    0x12, R6GameAddresses::UR6Operative_DestructUnwind19, // State 19: previous state, cleanup action.
};

// R6Game.dll data @ 1001a814 : native C++ exception function descriptor
const unsigned int UR6Operative_DestructExceptionInfo[7] = {
    0x19930520, 0x14, R6GameAddresses::UR6Operative_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001aadc : native C++ unwind-state transitions
const unsigned int UR6OperativeUnwindMap[38] = {
    0xffffffff, R6GameAddresses::UR6OperativeUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6OperativeUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::UR6OperativeUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6OperativeUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6OperativeUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::UR6OperativeUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::UR6OperativeUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::UR6OperativeUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::UR6OperativeUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::UR6OperativeUnwind9, // State 9: previous state, cleanup action.
    0x9, R6GameAddresses::UR6OperativeUnwind10, // State 10: previous state, cleanup action.
    0xa, R6GameAddresses::UR6OperativeUnwind11, // State 11: previous state, cleanup action.
    0xb, R6GameAddresses::UR6OperativeUnwind12, // State 12: previous state, cleanup action.
    0xc, R6GameAddresses::UR6OperativeUnwind13, // State 13: previous state, cleanup action.
    0xd, R6GameAddresses::UR6OperativeUnwind14, // State 14: previous state, cleanup action.
    0xe, R6GameAddresses::UR6OperativeUnwind15, // State 15: previous state, cleanup action.
    0xf, R6GameAddresses::UR6OperativeUnwind16, // State 16: previous state, cleanup action.
    0x10, R6GameAddresses::UR6OperativeUnwind17, // State 17: previous state, cleanup action.
    0x11, R6GameAddresses::UR6OperativeUnwind18, // State 18: previous state, cleanup action.
};

// R6Game.dll data @ 1001ab74 : native C++ exception function descriptor
const unsigned int UR6OperativeExceptionInfo[7] = {
    0x19930520, 0x13, R6GameAddresses::UR6OperativeUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b084 : native C++ unwind-state transitions
const unsigned int UR6Operative_TransferFileUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b094 : native typed-pointer and catch-all handler pair
const unsigned int UR6Operative_TransferFileCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6Operative_TransferFileCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6Operative_TransferFileCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b0b4 : native C++ try-block ranges
const unsigned int UR6Operative_TransferFileTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6Operative_TransferFileCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b0c8 : native C++ exception function descriptor
const unsigned int UR6Operative_TransferFileExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6Operative_TransferFileUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6Operative_TransferFileTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 100176c0 : UR6Operative virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6Operative_vftable[25] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6Operative_VectorDeletingDestructor, // +0xc: UR6Operative::VectorDeletingDestructor
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

// R6Game.dll @ 10002c40 : return the UR6Operative class object
UClass* __cdecl UR6Operative::StaticClass(void)
{
    return (UClass*)UR6OperativeClassMetadataStorage;
}

// R6Game.dll @ 10002c50 : allocate an operative using its class and object parameters
void* __cdecl UR6Operative::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6OperativeClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10004ea0 : destroy owned resources and inherited state
// Shuts down, destroys eighteen strings in reverse order, releases the face array and destroys UObject.
void __thiscall UR6Operative::~UR6Operative(UR6Operative *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6OperativeExceptionDispatcher1;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = UR6Operative_vftable;
  // Native EBP-0x10 saves this; FuncInfo 0x1001a814 chains states 19..0 down to -1.
  exceptionRegistration.state = 19;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 18;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szArmor); // +0x16c.
  *(byte*)&exceptionRegistration.state = 17;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSecondaryGadget); // +0x160.
  *(byte*)&exceptionRegistration.state = 16;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeaponBullet); // +0x154.
  *(byte*)&exceptionRegistration.state = 15;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeaponGadget); // +0x148.
  *(byte*)&exceptionRegistration.state = 14;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeapon); // +0x13c.
  *(byte*)&exceptionRegistration.state = 13;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szPrimaryGadget); // +0x130.
  *(byte*)&exceptionRegistration.state = 12;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeaponBullet); // +0x124.
  *(byte*)&exceptionRegistration.state = 11;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeaponGadget); // +0x118.
  *(byte*)&exceptionRegistration.state = 10;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeapon); // +0x10c.
  *(byte*)&exceptionRegistration.state = 9;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szGender); // +0x100.
  *(byte*)&exceptionRegistration.state = 8;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szGenderID); // +0xf4.
  *(byte*)&exceptionRegistration.state = 7;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szEyesColorID); // +0xe8.
  *(byte*)&exceptionRegistration.state = 6;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szHairColorID); // +0xdc.
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSpecialityID); // +0xd0.
  *(byte*)&exceptionRegistration.state = 4;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szStateID); // +0xc4.
  *(byte*)&exceptionRegistration.state = 3;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szCityID); // +0xb8.
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szCountryID); // +0xac.
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szOperativeClass); // +0xa0.
  *(byte*)&exceptionRegistration.state = 0;
  DestroyFourByteFArray((FArray *)&this->m_OperativeFaces); // +0x94.
  exceptionRegistration.state = -1;
  UObject::~UObject((UObject *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10005040 : assign inherited state and members
// Assigns UObject, 26 plain member words, face-array storage and eighteen strings in member order.
UR6Operative * __thiscall UR6Operative::operator=(UR6Operative *this, const UR6Operative *source)
{
  UObject::operator=((UObject *)this, (const UObject *)source);
  this->m_iUniqueID = source->m_iUniqueID; // +0x2c.
  this->m_iRookieID = source->m_iRookieID; // +0x30.
  this->m_RMenuFaceX = source->m_RMenuFaceX; // +0x34.
  this->m_RMenuFaceY = source->m_RMenuFaceY; // +0x38.
  this->m_RMenuFaceW = source->m_RMenuFaceW; // +0x3c.
  this->m_RMenuFaceH = source->m_RMenuFaceH; // +0x40.
  this->m_RMenuFaceSmallX = source->m_RMenuFaceSmallX; // +0x44.
  this->m_RMenuFaceSmallY = source->m_RMenuFaceSmallY; // +0x48.
  this->m_RMenuFaceSmallW = source->m_RMenuFaceSmallW; // +0x4c.
  this->m_RMenuFaceSmallH = source->m_RMenuFaceSmallH; // +0x50.
  this->m_iHealth = source->m_iHealth; // +0x54.
  this->m_iNbMissionPlayed = source->m_iNbMissionPlayed; // +0x58.
  this->m_iTerrokilled = source->m_iTerrokilled; // +0x5c.
  this->m_iRoundsfired = source->m_iRoundsfired; // +0x60.
  this->m_iRoundsOntarget = source->m_iRoundsOntarget; // +0x64.
  this->m_fAssault = source->m_fAssault; // +0x68.
  this->m_fDemolitions = source->m_fDemolitions; // +0x6c.
  this->m_fElectronics = source->m_fElectronics; // +0x70.
  this->m_fSniper = source->m_fSniper; // +0x74.
  this->m_fStealth = source->m_fStealth; // +0x78.
  this->m_fSelfControl = source->m_fSelfControl; // +0x7c.
  this->m_fLeadership = source->m_fLeadership; // +0x80.
  this->m_fObservation = source->m_fObservation; // +0x84.
  this->m_TMenuFace = source->m_TMenuFace; // +0x88.
  this->m_TMenuFaceSmall = source->m_TMenuFaceSmall; // +0x8c.
  this->m_CanUseArmorType = source->m_CanUseArmorType; // +0x90.
  AssignFourByteFArray((FArray *)&this->m_OperativeFaces, (const FArray *)&source->m_OperativeFaces);
  FStringNoInit::operator=((FStringNoInit *)&this->m_szOperativeClass,
      (const FStringNoInit *)&source->m_szOperativeClass); // +0xa0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szCountryID,
      (const FStringNoInit *)&source->m_szCountryID); // +0xac.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szCityID,
      (const FStringNoInit *)&source->m_szCityID); // +0xb8.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szStateID,
      (const FStringNoInit *)&source->m_szStateID); // +0xc4.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szSpecialityID,
      (const FStringNoInit *)&source->m_szSpecialityID); // +0xd0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szHairColorID,
      (const FStringNoInit *)&source->m_szHairColorID); // +0xdc.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szEyesColorID,
      (const FStringNoInit *)&source->m_szEyesColorID); // +0xe8.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szGenderID,
      (const FStringNoInit *)&source->m_szGenderID); // +0xf4.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szGender,
      (const FStringNoInit *)&source->m_szGender); // +0x100.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szPrimaryWeapon,
      (const FStringNoInit *)&source->m_szPrimaryWeapon); // +0x10c.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szPrimaryWeaponGadget,
      (const FStringNoInit *)&source->m_szPrimaryWeaponGadget); // +0x118.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szPrimaryWeaponBullet,
      (const FStringNoInit *)&source->m_szPrimaryWeaponBullet); // +0x124.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szPrimaryGadget,
      (const FStringNoInit *)&source->m_szPrimaryGadget); // +0x130.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szSecondaryWeapon,
      (const FStringNoInit *)&source->m_szSecondaryWeapon); // +0x13c.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szSecondaryWeaponGadget,
      (const FStringNoInit *)&source->m_szSecondaryWeaponGadget); // +0x148.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szSecondaryWeaponBullet,
      (const FStringNoInit *)&source->m_szSecondaryWeaponBullet); // +0x154.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szSecondaryGadget,
      (const FStringNoInit *)&source->m_szSecondaryGadget); // +0x160.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szArmor,
      (const FStringNoInit *)&source->m_szArmor); // +0x16c.
  return this;
}

// R6Game.dll @ 10005280 : destroy one operative or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6Operative::VectorDeletingDestructor(UR6Operative* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x178, elementCount,
            (_func_void_void_ptr*)UR6Operative::~UR6Operative);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6Operative::~UR6Operative(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x178);
    return this;
}

// R6Game.dll @ 10006660 : construct UObject and call no-init constructors for eighteen string members
UR6Operative * __thiscall UR6Operative::UR6Operative(UR6Operative *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6OperativeExceptionDispatcher2;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  UObject::UObject((UObject *)this);
  // Native EBP-0x10 saves this; FuncInfo 0x1001ab74 protects the completed base, array and prior strings.
  exceptionRegistration.state = 0;
  *(const uint**)this = UR6Operative_vftable;
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szOperativeClass);
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szCountryID);
  *(byte*)&exceptionRegistration.state = 3;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szCityID);
  *(byte*)&exceptionRegistration.state = 4;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szStateID);
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSpecialityID);
  *(byte*)&exceptionRegistration.state = 6;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szHairColorID);
  *(byte*)&exceptionRegistration.state = 7;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szEyesColorID);
  *(byte*)&exceptionRegistration.state = 8;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szGenderID);
  *(byte*)&exceptionRegistration.state = 9;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szGender);
  *(byte*)&exceptionRegistration.state = 10;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szPrimaryWeapon);
  *(byte*)&exceptionRegistration.state = 11;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szPrimaryWeaponGadget);
  *(byte*)&exceptionRegistration.state = 12;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szPrimaryWeaponBullet);
  *(byte*)&exceptionRegistration.state = 13;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szPrimaryGadget);
  *(byte*)&exceptionRegistration.state = 14;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSecondaryWeapon);
  *(byte*)&exceptionRegistration.state = 15;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSecondaryWeaponGadget);
  *(byte*)&exceptionRegistration.state = 16;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSecondaryWeaponBullet);
  *(byte*)&exceptionRegistration.state = 17;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSecondaryGadget);
  *(byte*)&exceptionRegistration.state = 18;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szArmor);
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 100067e0 : copy-construct inherited state and members
// Copies UObject, 26 plain member words, face-array storage and eighteen strings in member order.
UR6Operative * __thiscall UR6Operative::UR6Operative(UR6Operative *this, const UR6Operative *source)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&Shared_UR6OperativeExceptionDispatcher2;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  UObject::UObject((UObject *)this, (const UObject *)source);
  *(const uint**)this = UR6Operative_vftable;
  this->m_iUniqueID = source->m_iUniqueID; // +0x2c.
  this->m_iRookieID = source->m_iRookieID; // +0x30.
  this->m_RMenuFaceX = source->m_RMenuFaceX; // +0x34.
  this->m_RMenuFaceY = source->m_RMenuFaceY; // +0x38.
  this->m_RMenuFaceW = source->m_RMenuFaceW; // +0x3c.
  this->m_RMenuFaceH = source->m_RMenuFaceH; // +0x40.
  this->m_RMenuFaceSmallX = source->m_RMenuFaceSmallX; // +0x44.
  this->m_RMenuFaceSmallY = source->m_RMenuFaceSmallY; // +0x48.
  this->m_RMenuFaceSmallW = source->m_RMenuFaceSmallW; // +0x4c.
  this->m_RMenuFaceSmallH = source->m_RMenuFaceSmallH; // +0x50.
  this->m_iHealth = source->m_iHealth; // +0x54.
  this->m_iNbMissionPlayed = source->m_iNbMissionPlayed; // +0x58.
  this->m_iTerrokilled = source->m_iTerrokilled; // +0x5c.
  this->m_iRoundsfired = source->m_iRoundsfired; // +0x60.
  this->m_iRoundsOntarget = source->m_iRoundsOntarget; // +0x64.
  this->m_fAssault = source->m_fAssault; // +0x68.
  this->m_fDemolitions = source->m_fDemolitions; // +0x6c.
  this->m_fElectronics = source->m_fElectronics; // +0x70.
  this->m_fSniper = source->m_fSniper; // +0x74.
  this->m_fStealth = source->m_fStealth; // +0x78.
  this->m_fSelfControl = source->m_fSelfControl; // +0x7c.
  this->m_fLeadership = source->m_fLeadership; // +0x80.
  this->m_fObservation = source->m_fObservation; // +0x84.
  this->m_TMenuFace = source->m_TMenuFace; // +0x88.
  this->m_TMenuFaceSmall = source->m_TMenuFaceSmall; // +0x8c.
  this->m_CanUseArmorType = source->m_CanUseArmorType; // +0x90.
  // Shared construction FuncInfo 0x1001ab74: array call at state 0, string calls at states 1..18.
  exceptionRegistration.state = 0;
  ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_OperativeFaces, (const FArray *)&source->m_OperativeFaces);
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szOperativeClass,
      (const FStringNoInit *)&source->m_szOperativeClass); // +0xa0.
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szCountryID,
      (const FStringNoInit *)&source->m_szCountryID); // +0xac.
  *(byte*)&exceptionRegistration.state = 3;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szCityID,
      (const FStringNoInit *)&source->m_szCityID); // +0xb8.
  *(byte*)&exceptionRegistration.state = 4;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szStateID,
      (const FStringNoInit *)&source->m_szStateID); // +0xc4.
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSpecialityID,
      (const FStringNoInit *)&source->m_szSpecialityID); // +0xd0.
  *(byte*)&exceptionRegistration.state = 6;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szHairColorID,
      (const FStringNoInit *)&source->m_szHairColorID); // +0xdc.
  *(byte*)&exceptionRegistration.state = 7;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szEyesColorID,
      (const FStringNoInit *)&source->m_szEyesColorID); // +0xe8.
  *(byte*)&exceptionRegistration.state = 8;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szGenderID,
      (const FStringNoInit *)&source->m_szGenderID); // +0xf4.
  *(byte*)&exceptionRegistration.state = 9;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szGender,
      (const FStringNoInit *)&source->m_szGender); // +0x100.
  *(byte*)&exceptionRegistration.state = 10;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeapon,
      (const FStringNoInit *)&source->m_szPrimaryWeapon); // +0x10c.
  *(byte*)&exceptionRegistration.state = 11;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeaponGadget,
      (const FStringNoInit *)&source->m_szPrimaryWeaponGadget); // +0x118.
  *(byte*)&exceptionRegistration.state = 12;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szPrimaryWeaponBullet,
      (const FStringNoInit *)&source->m_szPrimaryWeaponBullet); // +0x124.
  *(byte*)&exceptionRegistration.state = 13;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szPrimaryGadget,
      (const FStringNoInit *)&source->m_szPrimaryGadget); // +0x130.
  *(byte*)&exceptionRegistration.state = 14;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeapon,
      (const FStringNoInit *)&source->m_szSecondaryWeapon); // +0x13c.
  *(byte*)&exceptionRegistration.state = 15;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeaponGadget,
      (const FStringNoInit *)&source->m_szSecondaryWeaponGadget); // +0x148.
  *(byte*)&exceptionRegistration.state = 16;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSecondaryWeaponBullet,
      (const FStringNoInit *)&source->m_szSecondaryWeaponBullet); // +0x154.
  *(byte*)&exceptionRegistration.state = 17;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSecondaryGadget,
      (const FStringNoInit *)&source->m_szSecondaryGadget); // +0x160.
  *(byte*)&exceptionRegistration.state = 18;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szArmor,
      (const FStringNoInit *)&source->m_szArmor); // +0x16c.
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10006e50 : construct an operative in supplied memory when nonnull
void __cdecl UR6Operative::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6Operative::UR6Operative((UR6Operative*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 10007e00 : TransferFile
// Transfers operative skills, accumulated statistics, rookie ID and selected equipment.
void __thiscall UR6Operative::TransferFile(UR6Operative* this, FArchive* archive)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6OperativeExceptionDispatcher3;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; neither try nor catch state owns local resources.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0; // FuncInfo 0x1001b0c8 has no local cleanup actions.
    FArchive::ByteOrderSerialize(archive, &this->m_fAssault, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fDemolitions, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fElectronics, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fSniper, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fStealth, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fSelfControl, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fLeadership, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_fObservation, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iHealth, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iNbMissionPlayed, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iTerrokilled, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iRoundsfired, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iRoundsOntarget, 4);
    FArchive::ByteOrderSerialize(archive, &this->m_iRookieID, 4);
    using SerializeStringCall = FArchive* (__cdecl *)(FArchive*, FString*);
    SerializeStringCall serializeString = *(SerializeStringCall*)R6GameImports::Core_SerializeFStringSlot; // Cached once after numeric transfers.
    FArchive* equipmentArchive = archive;
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szPrimaryWeapon);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szPrimaryWeaponGadget);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szPrimaryWeaponBullet);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szPrimaryGadget);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szSecondaryWeapon);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szSecondaryWeaponGadget);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szSecondaryWeaponBullet);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szSecondaryGadget);
    equipmentArchive = serializeString(equipmentArchive, (FString*)&this->m_szArmor);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10007f85 : forward the caught exception-pointer value through the parent frame to the throw helper
__declspec(naked) void UR6Operative_TransferFileCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10007f99 : add operative transfer context, then rethrow through the native helper
__declspec(naked) void UR6Operative_TransferFileCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6Operative_TransferFileExceptionContext // L"UR6Operative::TransferFile"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100136c0 : destroy the completed UObject base during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 100136c9 : release the operative face array during destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x94 // m_OperativeFaces.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 100136d7 : destroy m_szOperativeClass during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa0 // m_szOperativeClass.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100136e6 : destroy m_szCountryID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xac // m_szCountryID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100136f5 : destroy m_szCityID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xb8 // m_szCityID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013704 : destroy m_szStateID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xc4 // m_szStateID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013713 : destroy m_szSpecialityID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xd0 // m_szSpecialityID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013722 : destroy m_szHairColorID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xdc // m_szHairColorID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013731 : destroy m_szEyesColorID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xe8 // m_szEyesColorID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013740 : destroy m_szGenderID during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xf4 // m_szGenderID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001374f : destroy m_szGender during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind10(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x100 // m_szGender.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001375e : destroy m_szPrimaryWeapon during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind11(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x10c // m_szPrimaryWeapon.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001376d : destroy m_szPrimaryWeaponGadget during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind12(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x118 // m_szPrimaryWeaponGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001377c : destroy m_szPrimaryWeaponBullet during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind13(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x124 // m_szPrimaryWeaponBullet.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001378b : destroy m_szPrimaryGadget during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind14(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x130 // m_szPrimaryGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 1001379a : destroy m_szSecondaryWeapon during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind15(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x13c // m_szSecondaryWeapon.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100137a9 : destroy m_szSecondaryWeaponGadget during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind16(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x148 // m_szSecondaryWeaponGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100137b8 : destroy m_szSecondaryWeaponBullet during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind17(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x154 // m_szSecondaryWeaponBullet.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100137c7 : destroy m_szSecondaryGadget during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind18(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x160 // m_szSecondaryGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100137d6 : destroy m_szArmor during operative destructor unwinding
__declspec(naked) void UR6Operative_DestructUnwind19(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x16c // m_szArmor.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013b80 : destroy the completed UObject base during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 10013b89 : release the operative face array during construction unwinding
__declspec(naked) void UR6OperativeUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x94 // m_OperativeFaces.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013b97 : destroy m_szOperativeClass during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa0 // m_szOperativeClass.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013ba6 : destroy m_szCountryID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xac // m_szCountryID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013bb5 : destroy m_szCityID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xb8 // m_szCityID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013bc4 : destroy m_szStateID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xc4 // m_szStateID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013bd3 : destroy m_szSpecialityID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xd0 // m_szSpecialityID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013be2 : destroy m_szHairColorID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xdc // m_szHairColorID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013bf1 : destroy m_szEyesColorID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xe8 // m_szEyesColorID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c00 : destroy m_szGenderID during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xf4 // m_szGenderID.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c0f : destroy m_szGender during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind10(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x100 // m_szGender.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c1e : destroy m_szPrimaryWeapon during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind11(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x10c // m_szPrimaryWeapon.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c2d : destroy m_szPrimaryWeaponGadget during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind12(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x118 // m_szPrimaryWeaponGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c3c : destroy m_szPrimaryWeaponBullet during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind13(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x124 // m_szPrimaryWeaponBullet.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c4b : destroy m_szPrimaryGadget during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind14(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x130 // m_szPrimaryGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c5a : destroy m_szSecondaryWeapon during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind15(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x13c // m_szSecondaryWeapon.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c69 : destroy m_szSecondaryWeaponGadget during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind16(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x148 // m_szSecondaryWeaponGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c78 : destroy m_szSecondaryWeaponBullet during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind17(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x154 // m_szSecondaryWeaponBullet.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013c87 : destroy m_szSecondaryGadget during operative construction unwinding
__declspec(naked) void UR6OperativeUnwind18(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x160 // m_szSecondaryGadget.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10014c60 : construct operative class metadata and register its process-exit destruction
void InitializeUR6OperativeClassMetadata(void)
{
    UClass* objectClass = (UClass*)ImportedUObjectClass;
    auto staticConstructor = ImportedUObjectStaticConstructorAddress; // Native four-byte member-function address.
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6OperativeClassMetadataStorage, 0, 0x178, 0, objectClass, objectClass, FGuid(0, 0, 0, 0),
        L"R6Operative", GPackage, configName, 0x4084004, UR6Operative::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6OperativeClassMetadata);
}

// R6Game.dll @ 10014ce0 : bind the exported operative auto-class pointer to its static class metadata
void InitializeUR6OperativeAutoClassPointer(void)
{
    autoclassUR6Operative = (UClass*)UR6OperativeClassMetadataStorage; // Exported pointer slot at 0x10028da0.
}

// R6Game.dll @ 10015160 : destroy the operative class metadata through the imported class destructor
void DestroyUR6OperativeClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6OperativeClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 100137e5 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a814
__declspec(naked) void Shared_UR6OperativeExceptionDispatcher1(void)
{
    __asm { mov eax, offset UR6Operative_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013c96 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001ab74
__declspec(naked) void Shared_UR6OperativeExceptionDispatcher2(void)
{
    __asm { mov eax, offset UR6OperativeExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013f00 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001b0c8
__declspec(naked) void Shared_UR6OperativeExceptionDispatcher3(void)
{
    __asm { mov eax, offset UR6Operative_TransferFileExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
