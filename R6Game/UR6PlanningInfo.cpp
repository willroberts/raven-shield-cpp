#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 1001822c : shared binary32 fifty for retry displacement and HUD target height
const float NativeFloatFifty = 50.0f;

// R6Game.dll data @ 10028da8 : shared planning stair-transition state
int PlanningStairTransition = 0;

// R6Game.dll data @ 10024144 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6PlanningInfo::execAddToTeam.
unsigned int intUR6PlanningInfoexecAddToTeam = R6GameAddresses::UR6PlanningInfo_execAddToTeam;

// R6Game.dll data @ 10024148 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6PlanningInfo::execInsertToTeam.
unsigned int intUR6PlanningInfoexecInsertToTeam = R6GameAddresses::UR6PlanningInfo_execInsertToTeam;

// R6Game.dll data @ 1002414c : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6PlanningInfo::execDeletePoint.
unsigned int intUR6PlanningInfoexecDeletePoint = R6GameAddresses::UR6PlanningInfo_execDeletePoint;

// R6Game.dll data @ 10024150 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to UR6PlanningInfo::execFindPathToNextPoint.
unsigned int intUR6PlanningInfoexecFindPathToNextPoint = R6GameAddresses::UR6PlanningInfo_execFindPathToNextPoint;

// R6Game.dll data @ 100255fc : native registration result byte
unsigned char UR6PlanningInfoexecAddToTeamRegistrationResult = 0;

// R6Game.dll data @ 1002602c : native registration result byte
unsigned char UR6PlanningInfoexecDeletePointRegistrationResult = 0;

// R6Game.dll data @ 10026030 : class metadata storage
// Backing storage for UR6PlanningInfo::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6PlanningInfoClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10026f48 : native registration result byte
unsigned char UR6PlanningInfoexecInsertToTeamRegistrationResult = 0;

// R6Game.dll data @ 10027968 : native registration result byte
unsigned char UR6PlanningInfoexecFindPathToNextPointRegistrationResult = 0;

// R6Game.dll data @ 10028da4 : auto-class pointer
UClass* autoclassUR6PlanningInfo = nullptr;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a050 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_DestructUnwindMap[2] = {
    0xffffffff, R6GameAddresses::UR6PlanningInfo_DestructUnwind, // State 0: previous state, cleanup action.
};

// R6Game.dll data @ 1001a058 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_DestructExceptionInfo[7] = {
    0x19930520, 0x1, R6GameAddresses::UR6PlanningInfo_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001adb4 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_execAddToTeamUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001adc4 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_execAddToTeamCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6PlanningInfo_execAddToTeamCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_execAddToTeamCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001ade4 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_execAddToTeamTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_execAddToTeamCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001adf8 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_execAddToTeamExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_execAddToTeamUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_execAddToTeamTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001ae14 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_NoStairsBetweenPointsUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001ae24 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_NoStairsBetweenPointsCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001ae44 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_NoStairsBetweenPointsTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001ae58 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_NoStairsBetweenPointsExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b224 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_execInsertToTeamUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b234 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_execInsertToTeamCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6PlanningInfo_execInsertToTeamCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_execInsertToTeamCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b254 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_execInsertToTeamTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_execInsertToTeamCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b268 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_execInsertToTeamExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_execInsertToTeamUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_execInsertToTeamTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b2e4 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_AddPointUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b2f4 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_AddPointCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6PlanningInfo_AddPointCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_AddPointCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b314 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_AddPointTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_AddPointCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b328 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_AddPointExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_AddPointUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_AddPointTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b344 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_execFindPathToNextPointUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b354 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_execFindPathToNextPointCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff58, R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b374 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_execFindPathToNextPointTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b388 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_execFindPathToNextPointExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b3a4 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_TransferFileUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b3b4 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_TransferFileCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::UR6PlanningInfo_TransferFileCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_TransferFileCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b3d4 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_TransferFileTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_TransferFileCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b3e8 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_TransferFileExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_TransferFileUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_TransferFileTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b464 : native C++ unwind-state transitions
const unsigned int UR6PlanningInfo_execDeletePointUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b474 : native typed-pointer and catch-all handler pair
const unsigned int UR6PlanningInfo_execDeletePointCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::UR6PlanningInfo_execDeletePointCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6PlanningInfo_execDeletePointCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b494 : native C++ try-block ranges
const unsigned int UR6PlanningInfo_execDeletePointTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6PlanningInfo_execDeletePointCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b4a8 : native C++ exception function descriptor
const unsigned int UR6PlanningInfo_execDeletePointExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6PlanningInfo_execDeletePointUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6PlanningInfo_execDeletePointTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016d18 : UR6PlanningInfo virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6PlanningInfo_vftable[28] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6PlanningInfo_VectorDeletingDestructor, // +0xc: UR6PlanningInfo::VectorDeletingDestructor
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
    R6GameAddresses::UR6PlanningInfo_AddPoint, // +0x64: AddPoint
    R6GameAddresses::UR6PlanningInfo_TransferFile, // +0x68: TransferFile
    R6GameAddresses::UR6PlanningInfo_GetTeamLeader, // +0x6c: GetTeamLeader
};

// R6Game.dll @ 10002820 : return the UR6PlanningInfo class object
UClass* __cdecl UR6PlanningInfo::StaticClass(void)
{
    return (UClass*)UR6PlanningInfoClassMetadataStorage;
}

// R6Game.dll @ 10002830 : allocate planning information using its class, outer, name and flags
void* __cdecl UR6PlanningInfo::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6PlanningInfoClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10002860 : conditionally shut down planning information, then destroy its abstract base
void __thiscall UR6PlanningInfo::~UR6PlanningInfo(UR6PlanningInfo* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfoExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; FuncInfo 0x1001a058 maps state 0 to UR6PlanningInfo_DestructUnwind.
    *(const uint**)this = UR6PlanningInfo_vftable;
    exceptionRegistration.state = 0;
    UObject::ConditionalDestroy((UObject*)this);
    exceptionRegistration.state = -1;
    UR6AbstractPlanningInfo::~UR6AbstractPlanningInfo((UR6AbstractPlanningInfo*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100028c0 : construct planning information in supplied memory when nonnull
void __cdecl UR6PlanningInfo::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6PlanningInfo::UR6PlanningInfo((UR6PlanningInfo*)objectMemory); // Native tail jump to 0x10006f30.
}

// R6Game.dll @ 100028d0 : copy the abstract planning state and install the concrete vtable
UR6PlanningInfo* __thiscall UR6PlanningInfo::UR6PlanningInfo(UR6PlanningInfo* this, const UR6PlanningInfo* source)
{
    UR6AbstractPlanningInfo::UR6AbstractPlanningInfo(
        (UR6AbstractPlanningInfo*)this, (const UR6AbstractPlanningInfo*)source);
    *(const uint**)this = UR6PlanningInfo_vftable;
    return this;
}

// R6Game.dll @ 100028f0 : assign the abstract planning state and return this object
UR6PlanningInfo* __thiscall UR6PlanningInfo::operator=(UR6PlanningInfo* this, const UR6PlanningInfo* source)
{
    UR6AbstractPlanningInfo::operator=((UR6AbstractPlanningInfo*)this, (const UR6AbstractPlanningInfo*)source);
    return this;
}

// R6Game.dll @ 10002910 : destroy one planning-info object or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6PlanningInfo::VectorDeletingDestructor(UR6PlanningInfo* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x6c, elementCount,
            (_func_void_void_ptr*)UR6PlanningInfo::~UR6PlanningInfo);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6PlanningInfo::~UR6PlanningInfo(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x6c);
    return this;
}

// R6Game.dll @ 10006f30 : initialize planning indices, display flags, action defaults and reach ranges
UR6PlanningInfo* __thiscall UR6PlanningInfo::UR6PlanningInfo(UR6PlanningInfo* this)
{
    UR6AbstractPlanningInfo::UR6AbstractPlanningInfo((UR6AbstractPlanningInfo*)this);
    this->m_iCurrentNode = -1; // +0x34.
    this->m_iCurrentPathIndex = -1; // +0x38.
    uint* planningFlags = (uint*)((byte*)this + 0x4c);
    *planningFlags = (*planningFlags & ~8U) | 1U; // Clear bShowLog, set m_bDisplayPath, preserve other bits.
    this->m_eDefaultMode = 0; // +0x30.
    this->m_eDefaultAction = 0; // +0x32.
    this->m_eDefaultActionType = 0; // +0x33.
    *(const uint**)this = UR6PlanningInfo_vftable;
    this->m_fReachRange = 60.0f; // +0x50, native bits 0x42700000.
    this->m_fZReachRange = 100.0f; // +0x54, native bits 0x42c80000.
    this->m_eDefaultSpeed = 1; // +0x31, written after the range values.
    return this;
}

// R6Game.dll @ 10006f80 : return the planning team's leader, or null when no manager is assigned
AActor* __thiscall UR6PlanningInfo::GetTeamLeader(UR6PlanningInfo* this)
{
    AActor* teamManager = this->m_pTeamManager; // +0x58, reflected as Actor.
    if (teamManager == nullptr)
        return nullptr;
    // Native code reads R6RainbowTeam.m_TeamLeader at +0x420 without checking the manager's class.
    return *(AActor**)((byte*)teamManager + 0x420);
}

// R6Game.dll @ 10006fa0 : execAddToTeam
// Evaluates a new point, appends it through AddPoint, and returns success.
void __thiscall UR6PlanningInfo::execAddToTeam(UR6PlanningInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler1;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* argumentCode = *codeCursor;
    AR6ActionPoint* pNewPoint = nullptr;
    byte opcode = *argumentCode;
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* context = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    nativeTable[opcode](context, stack, &pNewPoint);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, stack, nullptr);
    }
    AActor* newPointArgument = (AActor*)pNewPoint;
    auto addPoint = *(void (__thiscall**)(UR6PlanningInfo*, AActor*))(*(byte**)this + 0x64);
    addPoint(this, newPointArgument);
    uint* output = (uint*)result;
    uint previousExceptionAddress = exceptionRegistration.previousAddress;
    *output = 1;
    __writefsdword(0, previousExceptionAddress);
}

// R6Game.dll @ 10007032 : rethrow execAddToTeam's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_execAddToTeamCatchPointer(void)
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

// R6Game.dll @ 10007046 : report execAddToTeam context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_execAddToTeamCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6PlanningInfo_execAddToTeamExceptionContext // L"UR6PlanningInfo::execAddToTeam"
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

// R6Game.dll @ 100070a0 : NoStairsBetweenPoints
// Reports whether no stairs actor appears in the discovered route cache.
int __thiscall UR6PlanningInfo::NoStairsBetweenPoints(UR6PlanningInfo* this, AActor* destination)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler2;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    AActor* pathDestination = destination;
    const uint* vectorZero = (const uint*)ImportedVectorZeroAddress;
    uint originX = vectorZero[0];
    uint originY = vectorZero[1];
    uint originZ = vectorZero[2];
    AController* controller = (AController*)this->m_pTeamManager;
    exceptionRegistration.state = 0;
    // FVector is passed by value as three raw stack words, without a floating conversion.
    using FindPathWordABI = AActor* (__thiscall *)(AController*, uint, uint, uint, AActor*, int);
    FindPathWordABI findPath = *(FindPathWordABI*)R6GameImports::Engine_AController_FindPathSlot;
    AActor* pathResult = findPath(controller, originX, originY, originZ, pathDestination, 1);
    if (pathResult != nullptr) {
        UClass* stairsClass = (UClass*)ImportedAR6StairsClass; // Selected import +0x16578.
        for (int routeIndex = 0; routeIndex < 16; ++routeIndex) {
            controller = (AController*)this->m_pTeamManager;
            AActor* routePoint = controller->RouteCache[routeIndex]; // +0x408, sixteen Actor pointers.
            if (routePoint == nullptr)
                break;
            UClass* classCursor = *(UClass**)((byte*)routePoint + 0x24);
            while (classCursor != nullptr && classCursor != stairsClass)
                classCursor = *(UClass**)((byte*)classCursor + 0x2c);
            if (classCursor == stairsClass) { // Also retains the native null-target class behavior.
                __writefsdword(0, exceptionRegistration.previousAddress);
                return 0;
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return 1;
}

// R6Game.dll @ 10007163 : rethrow NoStairsBetweenPoints's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_NoStairsBetweenPointsCatchPointer(void)
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

// R6Game.dll @ 10007177 : report NoStairsBetweenPoints context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_NoStairsBetweenPointsCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6PlanningInfo_NoStairsBetweenPointsExceptionContext // L"UR6PlanningInfo::NoStairsBetweenPoints"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100091a0 : execInsertToTeam
// Inserts a point after the current node and splices its backward action-point link.
void __thiscall UR6PlanningInfo::execInsertToTeam(UR6PlanningInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler3;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* argumentCode = *codeCursor;
    AR6ActionPoint* pNewPoint = nullptr;
    byte opcode = *argumentCode;
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* context = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    nativeTable[opcode](context, stack, &pNewPoint);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, stack, nullptr);
    }
    int currentNode = this->m_iCurrentNode;
    AR6ActionPointAbstract** nodeData = *(AR6ActionPointAbstract***)&this->m_NodeList;
    uint followingSlot = (uint)currentNode * 4U + 4U;
    AR6ActionPointAbstract* followingPoint = *(AR6ActionPointAbstract**)((uint)nodeData + followingSlot);
    int insertIndex = (int)((uint)currentNode + 1U);
    FArray::Insert((FArray*)&this->m_NodeList, insertIndex, 1, 4);
    uint destinationSlot = (uint)this->m_iCurrentNode * 4U + 4U;
    nodeData = *(AR6ActionPointAbstract***)&this->m_NodeList;
    AR6ActionPointAbstract* newPointForSlot = (AR6ActionPointAbstract*)pNewPoint;
    *(AR6ActionPointAbstract**)((uint)nodeData + destinationSlot) = newPointForSlot;
    AR6ActionPointAbstract* followingPrevious = followingPoint->prevActionPoint; // +0x394.
    AR6ActionPoint* insertedPoint = pNewPoint;
    insertedPoint->prevActionPoint = followingPrevious;
    AR6ActionPointAbstract* linkPoint = (AR6ActionPointAbstract*)pNewPoint;
    uint* output = (uint*)result;
    followingPoint->prevActionPoint = linkPoint;
    uint previousExceptionAddress = exceptionRegistration.previousAddress;
    *output = 1;
    __writefsdword(0, previousExceptionAddress);
}

// R6Game.dll @ 10009266 : rethrow execInsertToTeam's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_execInsertToTeamCatchPointer(void)
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

// R6Game.dll @ 1000927a : report execInsertToTeam context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_execInsertToTeamCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6PlanningInfo_execInsertToTeamExceptionContext // L"UR6PlanningInfo::execInsertToTeam"
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

// R6Game.dll @ 10009550 : AddPoint
// Appends a planned actor and sets its previous-point link when a current node is selected.
void __thiscall UR6PlanningInfo::AddPoint(UR6PlanningInfo* this, AActor* plannedActor)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler4;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    FArray* nodeList = (FArray*)&this->m_NodeList;
    int addedIndex = FArray::Add(nodeList, 1, 4);
    AActor** nodeData = *(AActor***)nodeList;
    AActor* actorForSlot = plannedActor;
    *(AActor**)((uint)nodeData + (uint)addedIndex * 4U) = actorForSlot;
    int currentNode = this->m_iCurrentNode;
    if (currentNode != -1) {
        nodeData = *(AActor***)nodeList;
        AR6ActionPointAbstract* previousPoint =
            *(AR6ActionPointAbstract**)((uint)nodeData + (uint)currentNode * 4U);
        ((AR6ActionPointAbstract*)actorForSlot)->prevActionPoint = previousPoint; // +0x394; no native class check.
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100095b7 : rethrow AddPoint's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_AddPointCatchPointer(void)
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

// R6Game.dll @ 100095cb : report AddPoint context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_AddPointCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6PlanningInfo_execAddPointExceptionContext // L"UR6PlanningInfo::execAddPoint"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100095f0 : execFindPathToNextPoint
// Builds a stair-aware path between action points, retrying once from an offset toward the previous path.
void __thiscall UR6PlanningInfo::execFindPathToNextPoint(UR6PlanningInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using FarMoveCall = int (__thiscall *)(ULevel*, AActor*, FVector, int, int, int, int);
    using MoveCall = int (__thiscall *)(ULevel*, AActor*, FVector, FRotator, FCheckResult*, int, int, int, int, int);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler5;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    FFrame* callStack = stack;
    byte** codeCursor = (byte**)((byte*)callStack + 0xc);
    byte* startCode = *codeCursor;
    AR6ActionPoint* pStartPoint = nullptr;
    byte startOpcode = *startCode;
    *codeCursor = startCode + 1;
    ScriptNative* startNativeTable = (ScriptNative*)ImportedGNativesAddress;
    UR6PlanningInfo* planning = this;
    UObject* startContext = *(UObject**)((byte*)callStack + 8);
    exceptionRegistration.state = 0;
    startNativeTable[startOpcode](startContext, callStack, &pStartPoint);
    byte* destinationCode = *codeCursor;
    UObject* destinationContext = *(UObject**)((byte*)callStack + 8);
    AR6ActionPoint* pPointToReach = nullptr;
    byte destinationOpcode = *destinationCode;
    *codeCursor = destinationCode + 1;
    ScriptNative* destinationNativeTable = (ScriptNative*)ImportedGNativesAddress;
    destinationNativeTable[destinationOpcode](destinationContext, callStack, &pPointToReach);
    byte* postArguments = *codeCursor + 1;
    *codeCursor = postArguments;
    if (*postArguments == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)callStack + 8);
        *codeCursor = postArguments + 1;
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, callStack, nullptr);
    }
    uint* validationResult = (uint*)result;
    AR6ActionPoint* checkedPoint = pPointToReach;
    *validationResult = 1;
    ushort coordinateStatus;
    __asm {
        mov ecx,checkedPoint
        fld dword ptr [ecx+0x234]
        fld dword ptr [ecx+0x234]
        fucompp
        fnstsw ax
        mov coordinateStatus,ax
    }
    bool rejectDestination = (coordinateStatus & 0x4400U) != 0x4000U;
    if (!rejectDestination) {
        __asm {
            mov ecx,checkedPoint
            fld dword ptr [ecx+0x238]
            fld dword ptr [ecx+0x238]
            fucompp
            fnstsw ax
            mov coordinateStatus,ax
        }
        rejectDestination = (coordinateStatus & 0x4400U) != 0x4000U;
    }
    if (!rejectDestination) {
        __asm {
            mov ecx,checkedPoint
            fld dword ptr [ecx+0x23c]
            fld dword ptr [ecx+0x23c]
            fucompp
            fnstsw ax
            mov coordinateStatus,ax
        }
        rejectDestination = (coordinateStatus & 0x4400U) != 0x4000U;
    }
    if (rejectDestination) {
        uint validationPreviousChain = exceptionRegistration.previousAddress;
        *validationResult = 0;
        __writefsdword(0, validationPreviousChain);
        return;
    }
    AR6ActionPoint* locationStart = pStartPoint;
    FVector pawnStart;
    *(uint*)&pawnStart.X = *(uint*)&locationStart->Location.X;
    *(uint*)&pawnStart.Y = *(uint*)&locationStart->Location.Y;
    *(uint*)&pawnStart.Z = *(uint*)&locationStart->Location.Z;
    uint clearPathOnFirstChunk = 1;
    uint retryAvailable = 1;
    int& stairTransition = PlanningStairTransition;
    stairTransition = 0;
    alignas(4) uint hitWords[12];
    for (;;) {
        uint placementZWord = *(uint*)&pawnStart.Z; // Native spill at frame -0x6c.
        AController* controller = (AController*)planning->m_pTeamManager;
        FVector placementLocation;
        *(uint*)&placementLocation.X = *(uint*)&pawnStart.X;
        uint placementYWord = *(uint*)&pawnStart.Y; // Native spill at frame -0x70.
        ULevel* placementLevel = controller->XLevel;
        uint placementY = placementYWord;
        APawn* placementPawn = controller->Pawn;
        byte* placementVtable = *(byte**)placementLevel;
        *(uint*)&placementLocation.Y = placementY;
        uint placementZ = placementZWord;
        *(uint*)&placementLocation.Z = placementZ;
        FarMoveCall farMove = *(FarMoveCall*)(placementVtable + 0x9c);
        farMove(placementLevel, (AActor*)placementPawn, placementLocation, 0, 1, 0, 0);
        controller = (AController*)planning->m_pTeamManager;
        for (int word = 0; word < 9; ++word)
            hitWords[word] = 0;
        hitWords[11] = 0;
        hitWords[9] = 0x3f800000; // FCheckResult +0x24, Time = 1.
        hitWords[10] = 0xffffffff; // +0x28, Item = -1.
        ULevel* level = controller->XLevel;
        APawn* selectedDropPawn = controller->Pawn;
        byte* dropVtable = *(byte**)level;
        APawn* dropPawn = selectedDropPawn; // Native saves the pawn at frame -0x14.
        FRotator dropRotation;
        ((uint*)&dropRotation)[0] = *(uint*)&selectedDropPawn->Rotation.Pitch;
        ((uint*)&dropRotation)[1] = *(uint*)&selectedDropPawn->Rotation.Yaw;
        ((uint*)&dropRotation)[2] = *(uint*)&selectedDropPawn->Rotation.Roll;
        FVector dropDelta, moveDelta;
        *(uint*)&dropDelta.X = 0;
        *(uint*)&moveDelta.X = *(uint*)&dropDelta.X;
        *(uint*)&dropDelta.Y = 0;
        *(uint*)&moveDelta.Y = *(uint*)&dropDelta.Y;
        *(uint*)&dropDelta.Z = 0xc20c0000; // -35.0f, copied as a native DWORD.
        *(uint*)&moveDelta.Z = *(uint*)&dropDelta.Z;
        APawn* movePawn = dropPawn;
        MoveCall move = *(MoveCall*)(dropVtable + 0x98);
        move(level, (AActor*)movePawn, moveDelta, dropRotation, (FCheckResult*)hitWords, 1, 1, 0, 0, 0);
        AR6ActionPoint* walkTarget = pPointToReach;
        FVector walkLocation;
        *(uint*)&walkLocation.X = *(uint*)&walkTarget->Location.X;
        *(uint*)&walkLocation.Y = *(uint*)&walkTarget->Location.Y;
        *(uint*)&walkLocation.Z = *(uint*)&walkTarget->Location.Z;
        controller = (AController*)planning->m_pTeamManager;
        APawn* walkPawn = controller->Pawn;
        int walkResult = APawn::walkReachable(walkPawn, walkLocation, 0, (AActor*)walkTarget);
        if (walkResult != 0 && NoStairsBetweenPoints(planning, (AActor*)pPointToReach) != 0) {
            AR6ActionPoint* rotationTarget = pPointToReach;
            FVector rotationLocation;
            *(uint*)&rotationLocation.X = *(uint*)&rotationTarget->Location.X;
            *(uint*)&rotationLocation.Y = *(uint*)&rotationTarget->Location.Y;
            *(uint*)&rotationLocation.Z = *(uint*)&rotationTarget->Location.Z;
            AR6ActionPoint* rotationStart = pStartPoint;
            AR6ActionPoint::SetRotationToward(rotationStart, rotationLocation);
            AR6ActionPoint* clearStart = pStartPoint;
            FArray* path = (FArray*)&clearStart->m_PathToNextPoint;
            int& count = *(int*)((byte*)path + 4);
            for (int index = 0; index < count; ++index) {
                // Actor-reference elements have no native element destructor.
            }
            count = 0;
            *(int*)((byte*)path + 8) = 0;
            FArray::Realloc(path, 4);
            __writefsdword(0, exceptionRegistration.previousAddress);
            return;
        }
        APawn* pawn;
        AActor* findDestination = (AActor*)pPointToReach;
        uint firstChunkSnapshot = clearPathOnFirstChunk;
        for (;;) {
            const FVector* zeroVector = (const FVector*)ImportedVectorZeroAddress;
            FVector searchOrigin;
            *(uint*)&searchOrigin.X = *(const uint*)&zeroVector->X;
            *(uint*)&searchOrigin.Y = *(const uint*)&zeroVector->Y;
            *(uint*)&searchOrigin.Z = *(const uint*)&zeroVector->Z;
            controller = (AController*)planning->m_pTeamManager;
            if (AController::FindPath(controller, searchOrigin, findDestination, 1) == nullptr)
                break;
            if (firstChunkSnapshot == 1) {
                FArray* path = (FArray*)&pStartPoint->m_PathToNextPoint;
                int& count = *(int*)((byte*)path + 4);
                for (int index = 0; index < count; ++index) {
                    // Actor-reference elements have no native element destructor.
                }
                count = 0;
                *(int*)((byte*)path + 8) = 0;
                FArray::Realloc(path, 4);
            }
            controller = (AController*)planning->m_pTeamManager;
            AActor* routeGate = controller->RouteCache[0];
            AActor* destinationSnapshot = (AActor*)pPointToReach;
            int scanIndex = 0;
            int savedRouteIndex = 0;
            while (routeGate != nullptr) {
                while (scanIndex < 16) {
                    controller = (AController*)planning->m_pTeamManager;
                    // The last look-ahead reads +0x448, beyond the sixteen RouteCache slots, as in native code.
                    AActor* nextRoute = *(AActor**)((byte*)controller + 0x40c + scanIndex * 4);
                    ++scanIndex;
                    clearPathOnFirstChunk = (uint)nextRoute; // Native reuses the first-chunk word for look-ahead.
                    if (nextRoute == nullptr) {
                        nextRoute = destinationSnapshot;
                        clearPathOnFirstChunk = (uint)nextRoute;
                    }
                    uint routeSlotOffset = 0x404U + (uint)scanIndex * 4U;
                    AActor* currentRoute = *(AActor**)((byte*)controller + routeSlotOffset);
                    UClass* cursor = *(UClass**)((byte*)currentRoute + 0x24);
                    UClass* stairsClass = (UClass*)ImportedAR6StairsClass;
                    while (cursor != nullptr && cursor != stairsClass)
                        cursor = *(UClass**)((byte*)cursor + 0x2c);
                    bool currentIsStairs = cursor == stairsClass;
                    bool commitRoute = false;
                    int transitionWrite = -1;
                    if (currentIsStairs) {
                        if (stairTransition == 1) {
                            if (nextRoute == destinationSnapshot &&
                                IsActorInsideStairVolume(destinationSnapshot) != 0) {
                                transitionWrite = 0;
                            } else {
                                commitRoute = true;
                                transitionWrite = 0;
                            }
                        } else {
                            uint selectedAnchorIsStairs = 0;
                            if (scanIndex == 1) {
                                controller = (AController*)planning->m_pTeamManager;
                                APawn* anchorPawn = controller->Pawn;
                                AActor* firstRoute = controller->RouteCache[0];
                                AActor* firstAnchor = anchorPawn->Anchor;
                                if (firstRoute != firstAnchor) {
                                    controller = (AController*)planning->m_pTeamManager;
                                    APawn* selectedAnchorPawn = controller->Pawn;
                                    AActor* anchor = selectedAnchorPawn->Anchor;
                                    cursor = *(UClass**)((byte*)anchor + 0x24);
                                    while (cursor != nullptr && cursor != stairsClass)
                                        cursor = *(UClass**)((byte*)cursor + 0x2c);
                                    selectedAnchorIsStairs = cursor == stairsClass ? 1U : 0U;
                                }
                            }
                            uint anchorIsStairs = selectedAnchorIsStairs; // Native frame -0x14 is a DWORD.
                            cursor = *(UClass**)((byte*)nextRoute + 0x24);
                            while (cursor != nullptr && cursor != stairsClass)
                                cursor = *(UClass**)((byte*)cursor + 0x2c);
                            if (cursor == stairsClass ||
                                (scanIndex == 1 && IsActorInsideStairVolume(pStartPoint) != 0) ||
                                anchorIsStairs) {
                                commitRoute = true;
                                transitionWrite = 1;
                            } else if (scanIndex == 16) {
                                commitRoute = true;
                            } else {
                                FVector nextLocation;
                                *(uint*)&nextLocation.X = *(uint*)&nextRoute->Location.X;
                                *(uint*)&nextLocation.Y = *(uint*)&nextRoute->Location.Y;
                                *(uint*)&nextLocation.Z = *(uint*)&nextRoute->Location.Z;
                                controller = (AController*)planning->m_pTeamManager;
                                APawn* routePawn = controller->Pawn;
                                commitRoute = APawn::walkReachable(routePawn, nextLocation, 0, nextRoute) == 0;
                            }
                        }
                    } else {
                        if (scanIndex == 16) {
                            commitRoute = true;
                        } else {
                            FVector nextLocation;
                            *(uint*)&nextLocation.X = *(uint*)&nextRoute->Location.X;
                            *(uint*)&nextLocation.Y = *(uint*)&nextRoute->Location.Y;
                            *(uint*)&nextLocation.Z = *(uint*)&nextRoute->Location.Z;
                            controller = (AController*)planning->m_pTeamManager;
                            APawn* routePawn = controller->Pawn;
                            commitRoute = APawn::walkReachable(routePawn, nextLocation, 0, nextRoute) == 0;
                        }
                        transitionWrite = 0;
                    }
                    if (commitRoute) {
                        FArray* path = (FArray*)&pStartPoint->m_PathToNextPoint;
                        if (!currentIsStairs)
                            savedRouteIndex = scanIndex;
                        controller = (AController*)planning->m_pTeamManager;
                        if (currentIsStairs)
                            savedRouteIndex = scanIndex;
                        AActor** routeSlot = (AActor**)((byte*)controller + routeSlotOffset);
                        int addedIndex = FArray::Add(path, 1, 4);
                        AActor** pathData = *(AActor***)path;
                        AActor* appendedRoute = *routeSlot;
                        pathData[(uint)addedIndex] = appendedRoute;
                        controller = (AController*)planning->m_pTeamManager;
                        level = controller->XLevel;
                        byte* placementVtable = *(byte**)level;
                        AActor* routeActor = *(AActor**)((byte*)controller + routeSlotOffset);
                        APawn* placementPawn = controller->Pawn;
                        FVector routeLocation;
                        *(uint*)&routeLocation.X = *(uint*)&routeActor->Location.X;
                        *(uint*)&routeLocation.Y = *(uint*)&routeActor->Location.Y;
                        *(uint*)&routeLocation.Z = *(uint*)&routeActor->Location.Z;
                        farMove = *(FarMoveCall*)(placementVtable + 0x9c);
                        farMove(level, (AActor*)placementPawn, routeLocation, 0, 1, 0, 0);
                        controller = (AController*)planning->m_pTeamManager;
                        level = controller->XLevel;
                        pawn = controller->Pawn;
                        byte* movementVtable = *(byte**)level;
                        FRotator commitRotation;
                        *(uint*)&commitRotation.Pitch = *(uint*)&pawn->Rotation.Pitch;
                        *(uint*)&commitRotation.Yaw = *(uint*)&pawn->Rotation.Yaw;
                        *(uint*)&commitRotation.Roll = *(uint*)&pawn->Rotation.Roll;
                        FVector commitDelta;
                        *(uint*)&commitDelta.X = *(uint*)&dropDelta.X;
                        *(uint*)&commitDelta.Y = *(uint*)&dropDelta.Y;
                        *(uint*)&commitDelta.Z = *(uint*)&dropDelta.Z;
                        move = *(MoveCall*)(movementVtable + 0x98);
                        move(level, (AActor*)pawn, commitDelta, commitRotation, (FCheckResult*)hitWords,
                            1, 1, 0, 0, 0);
                        nextRoute = (AActor*)clearPathOnFirstChunk;
                        scanIndex = 16;
                    }
                    if (transitionWrite >= 0)
                        stairTransition = transitionWrite;
                    destinationSnapshot = (AActor*)pPointToReach;
                    if (nextRoute == destinationSnapshot) {
                        scanIndex = 16;
                        routeGate = nullptr;
                    } else {
                        controller = (AController*)planning->m_pTeamManager;
                        routeGate = *(AActor**)((byte*)controller + 0x408U + (uint)savedRouteIndex * 4U);
                    }
                }
                scanIndex = savedRouteIndex;
            }
            if (scanIndex != 16) {
                AR6ActionPoint* rotationStart = pStartPoint;
                FArray* path = (FArray*)&rotationStart->m_PathToNextPoint;
                int pathCount = *(int*)((byte*)path + 4);
                AActor* facingActor = destinationSnapshot;
                if (pathCount != 0)
                    facingActor = (*(AActor***)path)[0];
                FVector facingTarget;
                *(uint*)&facingTarget.X = *(uint*)&facingActor->Location.X;
                *(uint*)&facingTarget.Y = *(uint*)&facingActor->Location.Y;
                *(uint*)&facingTarget.Z = *(uint*)&facingActor->Location.Z;
                AR6ActionPoint::SetRotationToward(rotationStart, facingTarget);
                goto finished;
            }
            firstChunkSnapshot = 0;
            clearPathOnFirstChunk = 0;
            findDestination = destinationSnapshot;
        }
        if (retryAvailable == 0) {
            uint* exhaustedResult = (uint*)result;
            uint exhaustedPreviousChain = exceptionRegistration.previousAddress;
            *exhaustedResult = 0;
            __writefsdword(0, exhaustedPreviousChain);
            return;
        }
        AR6ActionPoint* retryStart = pStartPoint;
        AR6ActionPointAbstract* previousPoint = retryStart->prevActionPoint;
        retryAvailable = 0;
        if (previousPoint == nullptr)
            goto failed;
        FArray* previousPath = (FArray*)&previousPoint->m_PathToNextPoint;
        AActor* previousActor = (AActor*)previousPoint;
        if (*(int*)((byte*)previousPath + 4) != 0) {
            uint previousCount = *(uint*)((byte*)previousPath + 4);
            AActor** previousData = *(AActor***)previousPath;
            previousActor = *(AActor**)((byte*)previousData + previousCount * 4U - 4U);
        }
        FVector previousLocation;
        *(uint*)&previousLocation.X = *(uint*)&previousActor->Location.X;
        uint previousYWord = *(uint*)&previousActor->Location.Y;
        uint previousZWord = *(uint*)&previousActor->Location.Z;
        *(uint*)&previousLocation.Y = previousYWord;
        *(uint*)&previousLocation.Z = previousZWord;
        FVector differenceSpill, offsetDirection;
        // Keep Z/Y differences extended until the native X/Y/Z float spills.
        __asm {
            lea eax,previousLocation
            mov ecx,retryStart
            fld dword ptr [eax+0x8]
            fsub dword ptr [ecx+0x23c]
            fld dword ptr [eax+0x4]
            fsub dword ptr [ecx+0x238]
            fld dword ptr [eax]
            fsub dword ptr [ecx+0x234]
            lea edi,differenceSpill
            fstp dword ptr [edi]
            mov ecx,dword ptr [edi]
            lea edx,offsetDirection
            mov dword ptr [edx],ecx
            fstp dword ptr [edi+0x4]
            mov ecx,dword ptr [edi+0x4]
            fstp dword ptr [edi+0x8]
            mov eax,dword ptr [edi+0x8]
            mov dword ptr [edx+0x4],ecx
            mov dword ptr [edx+0x8],eax
        }
        FVector::Normalize(&offsetDirection);
        float scaledZ;
        // Only scaled Z is rounded before adding the refreshed start location.
        __asm {
            lea ecx,offsetDirection
            fld dword ptr [ecx]
            fmul dword ptr NativeFloatFifty
            mov eax,pStartPoint
            fld dword ptr [ecx+0x4]
            fmul dword ptr NativeFloatFifty
            fld dword ptr [ecx+0x8]
            fmul dword ptr NativeFloatFifty
            fstp dword ptr scaledZ
            fxch st(1)
            fadd dword ptr [eax+0x234]
            lea edi,pawnStart
            fstp dword ptr [edi]
            mov edx,dword ptr [edi]
            fadd dword ptr [eax+0x238]
            fstp dword ptr [edi+0x4]
            mov ecx,dword ptr [edi+0x4]
            fld dword ptr scaledZ
            fadd dword ptr [eax+0x23c]
            fstp dword ptr [edi+0x8]
            mov eax,dword ptr [edi+0x8]
        }
    }
failed:
    *(uint*)result = 0;
finished:
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10009f3d : rethrow execFindPathToNextPoint's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_execFindPathToNextPointCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xa8]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x50]
        push ecx
        mov dword ptr [ebp-0x50],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10009f54 : report execFindPathToNextPoint context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_execFindPathToNextPointCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6PlanningInfo_execFindPathToNextPointExceptionContext // L"UR6PlanningInfo::execFindPathToNextPoint"
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

// R6Game.dll @ 10009fa0 : TransferFile
// Loads or saves planned point locations and action settings with the native archive-version rules.
void __thiscall UR6PlanningInfo::TransferFile(UR6PlanningInfo* this, FArchive* archive)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler6;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; both states have no local cleanup actions.
    __writefsdword(0, (uint)&exceptionRegistration);
    FArchive* transferArchive = archive;
    uint& indexWord = *(uint*)&archive; // Native reuses the incoming DWORD after retaining the archive in EBX.
    int loadingFlag = *(int*)((byte*)transferArchive + 0x14);
    exceptionRegistration.state = 0;
    if (loadingFlag != 0) { // ArIsLoading.
        this->m_iCurrentNode = -1;
        this->m_iCurrentPathIndex = -1;
        int savedCurrentNode = 0;
        FArray* nodeList = (FArray*)&this->m_NodeList;
        int& nodeCount = *(int*)((byte*)nodeList + 4);
        for (int index = 0; index < nodeCount; ++index) {
            // Actor-reference array elements have no native element destructor.
        }
        nodeCount = 0;
        *(int*)((byte*)nodeList + 8) = 0;
        FArray::Realloc(nodeList, 4);
        FArchive::ByteOrderSerialize(transferArchive, &this->m_iStartingPointNumber, 4);
        FVector location;
        if (*(int*)((byte*)transferArchive + 4) < 1) {
            FArchive::ByteOrderSerialize(transferArchive, &location.X, 4);
            FArchive::ByteOrderSerialize(transferArchive, &location.Y, 4);
            FArchive::ByteOrderSerialize(transferArchive, &location.Z, 4);
        }
        FArchive::ByteOrderSerialize(transferArchive, &this->m_iNbNode, 4);
        if (*(int*)((byte*)transferArchive + 4) > 2)
            FArchive::ByteOrderSerialize(transferArchive, &savedCurrentNode, 4);
        if (this->m_iNbNode > 0) {
            indexWord = 0;
            for (;;) {
                int index = (int)indexWord;
                int nodeLimit = this->m_iNbNode;
                if (index >= nodeLimit)
                    break;
                FArchive::ByteOrderSerialize(transferArchive, &location.X, 4);
                FArchive::ByteOrderSerialize(transferArchive, &location.Y, 4);
                FArchive::ByteOrderSerialize(transferArchive, &location.Z, 4);
                ULevel* level = ((AActor*)this->m_pTeamManager)->XLevel;
                using SpawnCall = AActor* (__thiscall *)(ULevel*, UClass*, FName, FVector, FRotator,
                    AActor*, int, int, AActor*, APawn*);
                FVector spawnLocation;
                *(uint*)&spawnLocation.X = *(uint*)&location.X;
                *(uint*)&spawnLocation.Y = *(uint*)&location.Y;
                *(uint*)&spawnLocation.Z = *(uint*)&location.Z;
                SpawnCall spawnActor = *(SpawnCall*)(*(byte**)level + 0xa8);
                AR6ActionPoint* point = (AR6ActionPoint*)spawnActor(level, (UClass*)AR6ActionPointClassMetadataStorage,
                    FName(0), spawnLocation, FRotator(0, 0, 0), nullptr, 0, 0, nullptr, nullptr);
                *(uint*)((byte*)point + 0xa0) &= ~2U; // bHidden; the native pointer is unchecked.
                using AddPointCall = void (__thiscall *)(UR6PlanningInfo*, AActor*);
                AddPointCall addPoint = *(AddPointCall*)(*(byte**)this + 0x64);
                addPoint(this, (AActor*)point);
                this->m_iCurrentNode = (int)((uint)this->m_iCurrentNode + 1U);
                AR6ActionPoint::TransferFile(point, transferArchive);
                uint nextIndex = indexWord;
                UTexture* currentTexture = point->m_pCurrentTexture;
                ++nextIndex;
                point->Texture = currentTexture;
                indexWord = nextIndex;
            }
            uint placementFlags = *(uint*)((byte*)this + 0x4c);
            int restoredNode = savedCurrentNode;
            *(uint*)((byte*)this + 0x4c) = placementFlags | 4U; // m_bPlacedFirstPoint.
            this->m_iCurrentNode = restoredNode;
        }
    } else {
        FArchive::ByteOrderSerialize(transferArchive, &this->m_iStartingPointNumber, 4);
        FArchive::ByteOrderSerialize(transferArchive, &this->m_iNbNode, 4);
        FArchive::ByteOrderSerialize(transferArchive, &this->m_iCurrentNode, 4);
        int index = 0;
        indexWord = 0;
        while (index < this->m_iNbNode) {
            AActor* point = (*(AActor***)&this->m_NodeList)[index];
            FArchive::ByteOrderSerialize(transferArchive, &point->Location.X, 4);
            FArchive::ByteOrderSerialize(transferArchive, &point->Location.Y, 4);
            FArchive::ByteOrderSerialize(transferArchive, &point->Location.Z, 4);
            AActor** currentPoints = *(AActor***)&this->m_NodeList;
            int currentIndex = (int)indexWord;
            AR6ActionPoint* currentPoint = (AR6ActionPoint*)currentPoints[currentIndex];
            AR6ActionPoint::TransferFile(currentPoint, transferArchive);
            uint nextIndex = indexWord + 1U;
            indexWord = nextIndex;
            index = (int)nextIndex;
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000a1d0 : rethrow TransferFile's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_TransferFileCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000a1e4 : report TransferFile context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_TransferFileCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6PlanningInfo_TransferFileExceptionContext // L"UR6PlanningInfo::TransferFile"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000a340 : execDeletePoint
// Clears cached paths, removes current-point references, and requests destruction of that actor.
void __thiscall UR6PlanningInfo::execDeletePoint(UR6PlanningInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler7;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved at frame -0x10; both states have no local cleanup actions.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* cursor = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = cursor;
    bool hasDebugInfo = *cursor == 0x42;
    exceptionRegistration.state = 0;
    if (hasDebugInfo) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)cursor + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, stack, nullptr);
    }
    ULevel* level = this->m_pTeamManager->XLevel;
    int currentIndex = this->m_iCurrentNode;
    byte* nodeData = *(byte**)&this->m_NodeList;
    AR6ActionPointAbstract* currentPoint =
        *(AR6ActionPointAbstract**)((uint)nodeData + (uint)currentIndex * 4U);
    const int& nodeCount = *(const int*)((byte*)&this->m_NodeList + 4);
    if (currentIndex == 0 && nodeCount < 1) {
        *(uint*)result = 0;
        __writefsdword(0, exceptionRegistration.previousAddress);
        return;
    }
    AR6ActionPointAbstract* previousPoint = currentPoint->prevActionPoint;
    if (previousPoint != nullptr) {
        FArray* previousPath = (FArray*)&previousPoint->m_PathToNextPoint;
        int& previousCount = *(int*)((byte*)previousPath + 4);
        int& previousCapacity = *(int*)((byte*)previousPath + 8);
        for (int pathIndex = 0; pathIndex < previousCount; ++pathIndex) {
            // Actor references have no element destructor.
        }
        previousCount = 0;
        previousCapacity = 0;
        FArray::Realloc(previousPath, 4);
    }
    FArray* currentPath = (FArray*)&currentPoint->m_PathToNextPoint;
    int& currentCount = *(int*)((byte*)currentPath + 4);
    int& currentCapacity = *(int*)((byte*)currentPath + 8);
    for (int pathIndex = 0; pathIndex < currentCount; ++pathIndex) {
        // Actor references have no element destructor.
    }
    currentCount = 0;
    currentCapacity = 0;
    FArray::Realloc(currentPath, 4);
    AR6ActionPointAbstract* pointToRemove = currentPoint;
    RemoveMatchingFArrayElements((FArray*)&this->m_NodeList, (const int*)&pointToRemove);
    auto destroyActor = *(int (__thiscall**)(ULevel*, AActor*, int))(*(byte**)level + 0xa0);
    destroyActor(level, (AActor*)currentPoint, 0);
    uint* output = (uint*)result;
    uint previousAddress = exceptionRegistration.previousAddress;
    *output = 1;
    __writefsdword(0, previousAddress);
}

// R6Game.dll @ 1000a442 : rethrow execDeletePoint's caught UTF-16 pointer value
__declspec(naked) void UR6PlanningInfo_execDeletePointCatchPointer(void)
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

// R6Game.dll @ 1000a456 : report execDeletePoint context and rethrow the active exception
__declspec(naked) void UR6PlanningInfo_execDeletePointCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::UR6PlanningInfo_execDeletePointExceptionContext // L"UR6PlanningInfo::execDeletePoint"
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

// R6Game.dll @ 10013550 : destroy the abstract planning base if ConditionalDestroy unwinds
__declspec(naked) void UR6PlanningInfo_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_UR6AbstractPlanningInfo_DestructorSlot // UR6AbstractPlanningInfo destructor.
    }
}

// R6Game.dll @ 100147a0 : initialize planning-info class metadata and register its cleanup
void InitializeUR6PlanningInfoClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  UClass* parentClass = (UClass*)ImportedUR6AbstractPlanningInfoClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)UR6PlanningInfoClassMetadataStorage, 0, 0x6c, 8, parentClass, withinClass, FGuid(0, 0, 0, 0),
      L"R6PlanningInfo", GPackage, configName, 0x4084004, UR6PlanningInfo::InternalConstructor, staticConstructor);
  _atexit(DestroyUR6PlanningInfoClassMetadata);
}

// R6Game.dll @ 100150e0 : destroy planning-info class metadata
void DestroyUR6PlanningInfoClassMetadata(void)
{
  UClass::~UClass((UClass*)UR6PlanningInfoClassMetadataStorage);
}

// R6Game.dll @ 10014830 : bind the exported planning-info auto-class pointer to its metadata
void InitializeUR6PlanningInfoAutoClassPointer(void)
{
  autoclassUR6PlanningInfo = (UClass*)UR6PlanningInfoClassMetadataStorage; // Exported slot at 0x10028da4.
}

// R6Game.dll @ 10013da0 : dispatch execAddToTeam's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler1(void)
{
  __asm { mov eax, offset UR6PlanningInfo_execAddToTeamExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013db0 : dispatch NoStairsBetweenPoints's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler2(void)
{
  __asm { mov eax, offset UR6PlanningInfo_NoStairsBetweenPointsExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013f80 : dispatch execInsertToTeam's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler3(void)
{
  __asm { mov eax, offset UR6PlanningInfo_execInsertToTeamExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013fa0 : dispatch AddPoint's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler4(void)
{
  __asm { mov eax, offset UR6PlanningInfo_AddPointExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013fb0 : dispatch execFindPathToNextPoint's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler5(void)
{
  __asm { mov eax, offset UR6PlanningInfo_execFindPathToNextPointExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013fc0 : dispatch TransferFile's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler6(void)
{
  __asm { mov eax, offset UR6PlanningInfo_TransferFileExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013fe0 : dispatch execDeletePoint's guard and catch states
__declspec(naked) void UR6PlanningInfo_UR6PlanningInfo_ExceptionHandler7(void)
{
  __asm { mov eax, offset UR6PlanningInfo_execDeletePointExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014ea0 : register UR6PlanningInfo::execAddToTeam at native index 1411
void InitializeUR6PlanningInfoNativeAddToTeam(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6PlanningInfoexecAddToTeam;
    byte& nativeRegistrationResult = UR6PlanningInfoexecAddToTeamRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1411, nativeExecPointerWord);
}

// R6Game.dll @ 10014ec0 : register UR6PlanningInfo::execInsertToTeam at native index 1412
void InitializeUR6PlanningInfoNativeInsertToTeam(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6PlanningInfoexecInsertToTeam;
    byte& nativeRegistrationResult = UR6PlanningInfoexecInsertToTeamRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1412, nativeExecPointerWord);
}

// R6Game.dll @ 10014ee0 : register UR6PlanningInfo::execDeletePoint at native index 1413
void InitializeUR6PlanningInfoNativeDeletePoint(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6PlanningInfoexecDeletePoint;
    byte& nativeRegistrationResult = UR6PlanningInfoexecDeletePointRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1413, nativeExecPointerWord);
}

// R6Game.dll @ 10014f00 : register UR6PlanningInfo::execFindPathToNextPoint at native index 2007
void InitializeUR6PlanningInfoNativeFindPathToNextPoint(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intUR6PlanningInfoexecFindPathToNextPoint;
    byte& nativeRegistrationResult = UR6PlanningInfoexecFindPathToNextPointRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2007, nativeExecPointerWord);
}

// R6Game.dll @ 10013559 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a058
__declspec(naked) void UR6PlanningInfoExceptionDispatcher(void)
{
    __asm { mov eax, offset UR6PlanningInfo_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
