#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 100127f0 : GS-client byte-state dispatch targets
// Preferred-VA code pointers for states 0..10; every cell has a PE HIGHLOW relocation.
const unsigned int GSClientManagerStateTargets[11] = {
    R6GameAddresses::GSClientManagerStateTargetsCase1, // State 0.
    R6GameAddresses::GSClientManagerStateTargetsCase2, // State 1.
    R6GameAddresses::GSClientManagerStateTargetsCase3, // State 2.
    R6GameAddresses::GSClientManagerStateTargetsCase4, // State 3.
    R6GameAddresses::GSClientManagerStateTargetsCase5, // State 4.
    R6GameAddresses::GSClientManagerStateTargetsCase6, // State 5.
    R6GameAddresses::GSClientManagerStateTargetsCase7, // State 6.
    R6GameAddresses::GSClientManagerStateTargetsCase8, // State 7.
    R6GameAddresses::GSClientManagerStateTargetsCase9, // State 8.
    R6GameAddresses::GSClientManagerStateTargetsCase10, // State 9.
    R6GameAddresses::GSClientManagerStateTargetsCase11, // State 10.
};

// R6Game.dll data @ 100292c8 : last logged GS-client state DWORD
int LastLoggedGSClientState = 0;

// R6Game.dll data @ 100292cc : nonzero GS-client logging enable DWORD
int GSClientStateLoggingEnabled = 0;

// R6Game.dll data @ 100292d0 : full shared create-Ubi-server integer
int CreateUbiServerValue = 0;

// R6Game.dll data @ 100292d4 : shared float cell passed by address to master-server processing
float MasterServerProcessValue = 0.0f;

// R6Game.dll data @ 100250f0 : class metadata storage
// Backing storage for UR6GameManager::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char UR6GameManagerClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 10027964 : auto-class pointer
UClass* autoclassUR6GameManager = nullptr;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a024 : native C++ unwind-state transitions
const unsigned int UR6GameManager_DestructUnwindMap[4] = {
    0xffffffff, R6GameAddresses::UR6GameManager_DestructUnwind, // State 0: previous state, cleanup action.
    0xffffffff, R6GameAddresses::UR6GameManager_DestructUnwind1, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a034 : native C++ exception function descriptor
const unsigned int UR6GameManager_DestructExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bd58 : native C++ unwind-state transitions
const unsigned int UR6GameManager_InitializeGSClientUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001bd68 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_InitializeGSClientCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_InitializeGSClientCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_InitializeGSClientCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bd88 : native C++ try-block ranges
const unsigned int UR6GameManager_InitializeGSClientTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_InitializeGSClientCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bd9c : native C++ exception function descriptor
const unsigned int UR6GameManager_InitializeGSClientExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_InitializeGSClientUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_InitializeGSClientTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bdb8 : native C++ unwind-state transitions
const unsigned int UR6GameManager_StartPreJoinProcedureUnwindMap[12] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartPreJoinProcedureUnwind1, // State 1: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartPreJoinProcedureUnwind2, // State 2: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartPreJoinProcedureUnwind3, // State 3: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartPreJoinProcedureUnwind4, // State 4: previous state, cleanup action.
    0xffffffff, 0x0, // State 5: previous state, cleanup action.
};

// R6Game.dll data @ 1001bde8 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_StartPreJoinProcedureCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_StartPreJoinProcedureCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_StartPreJoinProcedureCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001be08 : native C++ try-block ranges
const unsigned int UR6GameManager_StartPreJoinProcedureTryMap[5] = {
    0x0, 0x4, 0x5, 0x2, R6GameAddresses::UR6GameManager_StartPreJoinProcedureCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001be1c : native C++ exception function descriptor
const unsigned int UR6GameManager_StartPreJoinProcedureExceptionInfo[7] = {
    0x19930520, 0x6, R6GameAddresses::UR6GameManager_StartPreJoinProcedureUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_StartPreJoinProcedureTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001be38 : native C++ unwind-state transitions
const unsigned int UR6GameManager_StartLogInProcedureUnwindMap[10] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartLogInProcedureUnwind1, // State 1: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartLogInProcedureUnwind2, // State 2: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartLogInProcedureUnwind3, // State 3: previous state, cleanup action.
    0xffffffff, 0x0, // State 4: previous state, cleanup action.
};

// R6Game.dll data @ 1001be60 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_StartLogInProcedureCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_StartLogInProcedureCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_StartLogInProcedureCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001be80 : native C++ try-block ranges
const unsigned int UR6GameManager_StartLogInProcedureTryMap[5] = {
    0x0, 0x3, 0x4, 0x2, R6GameAddresses::UR6GameManager_StartLogInProcedureCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001be94 : native C++ exception function descriptor
const unsigned int UR6GameManager_StartLogInProcedureExceptionInfo[7] = {
    0x19930520, 0x5, R6GameAddresses::UR6GameManager_StartLogInProcedureUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_StartLogInProcedureTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001beb0 : native C++ unwind-state transitions
const unsigned int UR6GameManager_ConnectionInterruptedUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001bec0 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_ConnectionInterruptedCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_ConnectionInterruptedCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_ConnectionInterruptedCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bee0 : native C++ try-block ranges
const unsigned int UR6GameManager_ConnectionInterruptedTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_ConnectionInterruptedCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bef4 : native C++ exception function descriptor
const unsigned int UR6GameManager_ConnectionInterruptedExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_ConnectionInterruptedUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_ConnectionInterruptedTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bf10 : native C++ unwind-state transitions
const unsigned int UR6GameManager_ClientLeaveServerUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001bf20 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_ClientLeaveServerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_ClientLeaveServerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_ClientLeaveServerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bf40 : native C++ try-block ranges
const unsigned int UR6GameManager_ClientLeaveServerTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_ClientLeaveServerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bf54 : native C++ exception function descriptor
const unsigned int UR6GameManager_ClientLeaveServerExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_ClientLeaveServerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_ClientLeaveServerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bf70 : native C++ unwind-state transitions
const unsigned int UR6GameManager_MSClientManagerUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001bf80 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_MSClientManagerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6GameManager_MSClientManagerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_MSClientManagerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bfa0 : native C++ try-block ranges
const unsigned int UR6GameManager_MSClientManagerTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_MSClientManagerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bfb4 : native C++ exception function descriptor
const unsigned int UR6GameManager_MSClientManagerExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_MSClientManagerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_MSClientManagerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bfd0 : native C++ unwind-state transitions
const unsigned int UR6GameManager_DoConsoleCommandUnwindMap[6] = {
    0xffffffff, R6GameAddresses::UR6GameManager_DoConsoleCommandUnwind, // State 0: previous state, cleanup action.
    0x0, 0x0, // State 1: previous state, cleanup action.
    0x0, 0x0, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001bfe8 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_DoConsoleCommandCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_DoConsoleCommandCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_DoConsoleCommandCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c008 : native C++ try-block ranges
const unsigned int UR6GameManager_DoConsoleCommandTryMap[5] = {
    0x1, 0x1, 0x2, 0x2, R6GameAddresses::UR6GameManager_DoConsoleCommandCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c01c : native C++ exception function descriptor
const unsigned int UR6GameManager_DoConsoleCommandExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::UR6GameManager_DoConsoleCommandUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_DoConsoleCommandTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001c038 : native C++ unwind-state transitions
const unsigned int UR6GameManager_MinimizeAndPauseMusicUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001c048 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_MinimizeAndPauseMusicCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c068 : native C++ try-block ranges
const unsigned int UR6GameManager_MinimizeAndPauseMusicTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c07c : native C++ exception function descriptor
const unsigned int UR6GameManager_MinimizeAndPauseMusicExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001c098 : native C++ unwind-state transitions
const unsigned int UR6GameManager_GSClientManagerUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001c0a8 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_GSClientManagerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6GameManager_GSClientManagerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_GSClientManagerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c0c8 : native C++ try-block ranges
const unsigned int UR6GameManager_GSClientManagerTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_GSClientManagerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c0dc : native C++ exception function descriptor
const unsigned int UR6GameManager_GSClientManagerExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_GSClientManagerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_GSClientManagerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001c0f8 : native C++ unwind-state transitions
const unsigned int UR6GameManager_LaunchListenSrvUnwindMap[14] = {
    0xffffffff, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwind1, // State 1: previous state, cleanup action.
    0x1, 0x0, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwind4, // State 4: previous state, cleanup action.
    0x3, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwind5, // State 5: previous state, cleanup action.
    0x1, 0x0, // State 6: previous state, cleanup action.
};

// R6Game.dll data @ 1001c130 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_LaunchListenSrvCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::UR6GameManager_LaunchListenSrvCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_LaunchListenSrvCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c150 : native C++ try-block ranges
const unsigned int UR6GameManager_LaunchListenSrvTryMap[5] = {
    0x2, 0x5, 0x6, 0x2, R6GameAddresses::UR6GameManager_LaunchListenSrvCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c164 : native C++ exception function descriptor
const unsigned int UR6GameManager_LaunchListenSrvExceptionInfo[7] = {
    0x19930520, 0x7, R6GameAddresses::UR6GameManager_LaunchListenSrvUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_LaunchListenSrvTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001c180 : native C++ unwind-state transitions
const unsigned int UR6GameManager_StartJoinServerUnwindMap[14] = {
    0xffffffff, R6GameAddresses::UR6GameManager_StartJoinServerUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::UR6GameManager_StartJoinServerUnwind1, // State 1: previous state, cleanup action.
    0x1, 0x0, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::UR6GameManager_StartJoinServerUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::UR6GameManager_StartJoinServerUnwind4, // State 4: previous state, cleanup action.
    0x3, R6GameAddresses::UR6GameManager_StartJoinServerUnwind5, // State 5: previous state, cleanup action.
    0x1, 0x0, // State 6: previous state, cleanup action.
};

// R6Game.dll data @ 1001c1b8 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_StartJoinServerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_StartJoinServerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_StartJoinServerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c1d8 : native C++ try-block ranges
const unsigned int UR6GameManager_StartJoinServerTryMap[5] = {
    0x2, 0x5, 0x6, 0x2, R6GameAddresses::UR6GameManager_StartJoinServerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c1ec : native C++ exception function descriptor
const unsigned int UR6GameManager_StartJoinServerExceptionInfo[7] = {
    0x19930520, 0x7, R6GameAddresses::UR6GameManager_StartJoinServerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_StartJoinServerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001c208 : native C++ unwind-state transitions
const unsigned int UR6GameManager_GameServiceTickUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001c218 : native typed-pointer and catch-all handler pair
const unsigned int UR6GameManager_GameServiceTickCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::UR6GameManager_GameServiceTickCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::UR6GameManager_GameServiceTickCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001c238 : native C++ try-block ranges
const unsigned int UR6GameManager_GameServiceTickTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::UR6GameManager_GameServiceTickCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001c24c : native C++ exception function descriptor
const unsigned int UR6GameManager_GameServiceTickExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::UR6GameManager_GameServiceTickUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::UR6GameManager_GameServiceTickTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10016c88 : UR6GameManager virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint UR6GameManager_vftable[36] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::UR6GameManager_VectorDeletingDestructor, // +0xc: UR6GameManager::VectorDeletingDestructor
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
    R6GameAddresses::UR6GameManager_InitializeGameService, // +0x64: UR6GameManager::InitializeGameService
    R6GameAddresses::UR6GameManager_UnInitialize, // +0x68: UR6GameManager::UnInitialize
    R6GameAddresses::UR6GameManager_GameServiceTick, // +0x6c: GameServiceTick
    R6GameAddresses::UR6GameManager_ConnectionInterrupted, // +0x70: ConnectionInterrupted
    R6GameAddresses::UR6GameManager_ClientLeaveServer, // +0x74: ClientLeaveServer
    R6GameAddresses::UR6GameManager_LaunchListenSrv, // +0x78: LaunchListenSrv
    R6GameAddresses::UR6GameManager_StartJoinServer, // +0x7c: StartJoinServer
    R6GameAddresses::UR6GameManager_StartPreJoinProcedure, // +0x80: UR6GameManager::StartPreJoinProcedure
    R6GameAddresses::UR6GameManager_StartLogInProcedure, // +0x84: UR6GameManager::StartLogInProcedure
    R6GameAddresses::UR6GameManager_SetGSCreateUbiServer, // +0x88: SetGSCreateUbiServer
    R6GameAddresses::UR6GameManager_GetGSCreateUbiServer, // +0x8c: GetGSCreateUbiServer
};

// R6Game.dll @ 10002690 : return the UR6GameManager class object
UClass* __cdecl UR6GameManager::StaticClass(void)
{
    return (UClass*)UR6GameManagerClassMetadataStorage;
}

// R6Game.dll @ 100026a0 : allocate a manager using its class and the supplied outer, name and flags
void* __cdecl UR6GameManager::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)UR6GameManagerClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 100026d0 : shut down at concrete and abstract manager phases, then destroy UObject
void __thiscall UR6GameManager::~UR6GameManager(UR6GameManager* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&UR6GameManagerExceptionDispatcher;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native EBP-0x10 saves this; FuncInfo 0x1001a034 gives each phase a separate cleanup ending at state -1.
    *(const uint**)this = UR6GameManager_vftable;
    using ConditionalDestroyCall = int (__thiscall *)(UObject*);
    ConditionalDestroyCall conditionalDestroy = *(ConditionalDestroyCall*)R6GameImports::Core_UObject_ConditionalDestroySlot;
    exceptionRegistration.state = 0; // UR6GameManager_DestructUnwind destroys the abstract-manager base if this phase throws.
    conditionalDestroy((UObject*)this);
    *(const uint**)this = *(const uint* const*)R6GameImports::Engine_UR6AbstractGameManager_VftableSlot;
    exceptionRegistration.state = 1; // UR6GameManager_DestructUnwind1 destroys UObject if this phase throws.
    conditionalDestroy((UObject*)this); // Reuses the native cached import target.
    exceptionRegistration.state = -1;
    UObject::~UObject((UObject*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10002740 : construct UObject and install the concrete manager vtable
UR6GameManager* __thiscall UR6GameManager::UR6GameManager(UR6GameManager* this)
{
    UObject::UObject((UObject*)this);
    *(const uint**)this = UR6GameManager_vftable;
    return this;
}

// R6Game.dll @ 10002760 : copy the abstract-manager base and the service and console references
UR6GameManager* __thiscall UR6GameManager::UR6GameManager(UR6GameManager* this, const UR6GameManager* source)
{
    UR6AbstractGameManager::UR6AbstractGameManager(
        (UR6AbstractGameManager*)this, (const UR6AbstractGameManager*)source);
    *(const uint**)this = UR6GameManager_vftable;
    this->m_GameMgrGameService = source->m_GameMgrGameService; // +0x30, copied object reference.
    this->m_GameMgrConsole = source->m_GameMgrConsole; // +0x34, copied object reference.
    return this;
}

// R6Game.dll @ 10002790 : assign the abstract-manager base and the service and console references
UR6GameManager* __thiscall UR6GameManager::operator=(UR6GameManager* this, const UR6GameManager* source)
{
    UR6AbstractGameManager::operator=((UR6AbstractGameManager*)this, (const UR6AbstractGameManager*)source);
    this->m_GameMgrGameService = source->m_GameMgrGameService; // +0x30.
    this->m_GameMgrConsole = source->m_GameMgrConsole; // +0x34.
    return this;
}

// R6Game.dll @ 100027c0 : destroy one game manager or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall UR6GameManager::VectorDeletingDestructor(UR6GameManager* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x38, elementCount,
            (_func_void_void_ptr*)UR6GameManager::~UR6GameManager);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    UR6GameManager::~UR6GameManager(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x38);
    return this;
}

// R6Game.dll @ 10003e80 : construct a game manager in supplied memory when nonnull
void __cdecl UR6GameManager::InternalConstructor(void* objectMemory)
{
    if (objectMemory != nullptr)
        UR6GameManager::UR6GameManager((UR6GameManager*)objectMemory); // Native tail jump.
}

// R6Game.dll @ 10011a00 : InitializeGSClient
// Copies the client initialization low bit and initializes its communication interface.
void __thiscall UR6GameManager::InitializeGSClient(UR6GameManager* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler1;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6GSServers* service = this->m_GameMgrGameService;
    byte* initialServiceVtable = *(byte**)service;
    exceptionRegistration.state = 0;
    auto initializeClient = *(int (__thiscall**)(UR6GSServers*))(initialServiceVtable + 0xc4);
    uint initializationResult = (uint)initializeClient(service);
    uint* managerFlags = (uint*)((byte*)this + 0x2c);
    uint changedInitializationBit = (*managerFlags ^ initializationResult) & 1U;
    uint updatedFlags = *managerFlags ^ changedInitializationBit;
    service = this->m_GameMgrGameService;
    *managerFlags = updatedFlags; // m_bGSClientInitialized; preserve the other 31 bits.
    auto setComInterface = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xc8);
    if (setComInterface(service) == 0) {
        FOutputDevice* log = *(FOutputDevice**)ImportedGLogAddress;
        FOutputDevice::Logf(log, L"ERROR: GS Client Com interface not initialized!!!");
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10011a7b : rethrow InitializeGSClient's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_InitializeGSClientCatchPointer(void)
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

// R6Game.dll @ 10011ab0 : UnInitialize
// Clears the global manager initialization flag.
void __thiscall UR6GameManager::UnInitialize(UR6GameManager* this)
{
    // This native method uses the global manager; its this argument is unused.
    UR6AbstractGameManager* globalManager = *(UR6AbstractGameManager**)ImportedGR6GameManagerAddress;
    uint* managerFlags = (uint*)((byte*)globalManager + 0x2c);
    if ((*(byte *)managerFlags & 1U) != 0) // m_bGSClientInitialized.
        *managerFlags &= ~1U;
}

// R6Game.dll @ 10011ad0 : StartPreJoinProcedure
// Selects a CD-key activation/authentication step and reports it to the manager event.
void __thiscall UR6GameManager::StartPreJoinProcedure(UR6GameManager* this, int useMod)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler2;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    alignas(4) byte messageStorage[12];
    FString* message = (FString*)messageStorage;
    int requestedMod = useMod;
    UR6GSServers* service = this->m_GameMgrGameService;
    byte* initialServiceVtable = *(byte**)service;
    exceptionRegistration.state = 0;
    auto requestModProcess = *(void (__thiscall**)(UR6GSServers*, int))(initialServiceVtable + 0xb4);
    requestModProcess(service, requestedMod);
    service = this->m_GameMgrGameService;
    if (requestedMod != 0) {
        UR6ModGSInfo* modInfo = service->m_ModGSInfo; // +0x19c.
        if ((*(byte *)((byte *)modInfo + 0x3c) & 1U) == 0) { // m_bModValidActivationID
            FString::FString(message, L"UP_MOD_ENTER_CD_KEY");
            *(byte*)&exceptionRegistration.state = 1;
        } else {
            service = this->m_GameMgrGameService;
            auto requestAuthId = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xb8);
            requestAuthId(service);
            FString::FString(message, L"UP_MOD_REQUEST_AUTHID");
            *(byte*)&exceptionRegistration.state = 2;
        }
    } else if ((*(byte *)((byte *)service + 0x194) & 1U) == 0) { // m_bValidActivationID
        FString::FString(message, L"UP_ENTER_CD_KEY");
        *(byte*)&exceptionRegistration.state = 3;
    } else {
        service = this->m_GameMgrGameService;
        auto requestAuthId = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xb8);
        requestAuthId(service);
        FString::FString(message, L"UP_REQUEST_AUTHID");
        *(byte*)&exceptionRegistration.state = 4;
    }
    UR6AbstractGameManager::eventGMProcessMsg((UR6AbstractGameManager*)this, message);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(message);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10011bc3 : rethrow StartPreJoinProcedure's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_StartPreJoinProcedureCatchPointer(void)
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

// R6Game.dll @ 10011c00 : StartLogInProcedure
// Reports pending, new, or skipped login and returns whether another request was absent.
int __thiscall UR6GameManager::StartLogInProcedure(UR6GameManager* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler3;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    alignas(4) byte messageStorage[12];
    FString* message = (FString*)messageStorage;
    UR6GSServers* service = this->m_GameMgrGameService;
    byte* initialServiceVtable = *(byte**)service;
    exceptionRegistration.state = 0;
    auto isInRequest = *(int (__thiscall**)(UR6GSServers*))(initialServiceVtable + 0xdc);
    if (isInRequest(service) != 0) {
        FString::FString(message, L"LOGIN_ALREADY_IN_PROGRESS");
        *(byte*)&exceptionRegistration.state = 1;
        UR6AbstractGameManager::eventGMProcessMsg((UR6AbstractGameManager*)this, message);
        *(byte*)&exceptionRegistration.state = 0;
        FString::~FString(message);
        __writefsdword(0, exceptionRegistration.previousAddress);
        return 0;
    }
    service = this->m_GameMgrGameService;
    auto isLoggedIn = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xe0);
    if (isLoggedIn(service) == 0) {
        FString::FString(message, L"LOGIN_START");
        *(byte*)&exceptionRegistration.state = 2;
    } else {
        FString::FString(message, L"LOGIN_SKIPPED");
        *(byte*)&exceptionRegistration.state = 3;
    }
    UR6AbstractGameManager::eventGMProcessMsg((UR6AbstractGameManager*)this, message);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(message);
    __writefsdword(0, exceptionRegistration.previousAddress);
    return 1;
}

// R6Game.dll @ 10011cd8 : rethrow StartLogInProcedure's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_StartLogInProcedureCatchPointer(void)
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

// R6Game.dll @ 10011d10 : ConnectionInterrupted
// Optionally disconnects CD-key players and dispatches the service authentication reset.
void __thiscall UR6GameManager::ConnectionInterrupted(UR6GameManager* this, int disconnectCDKeyPlayers)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler4;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6GSServers* initialService = this->m_GameMgrGameService;
    bool hasService = initialService != nullptr;
    exceptionRegistration.state = 0;
    if (hasService) {
        if (disconnectCDKeyPlayers != 0) {
            UR6GSServers* service = this->m_GameMgrGameService;
            auto disconnectPlayers = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x90);
            disconnectPlayers(service); // DisconnectAllCDKeyPlayers.
        }
        UR6GSServers* service = this->m_GameMgrGameService;
        auto resetAuthId = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xbc);
        resetAuthId(service); // ResetAuthId.
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10011d71 : rethrow ConnectionInterrupted's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_ConnectionInterruptedCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10011db0 : ClientLeaveServer
// Clears multiplayer-active state and requests server leave when joined.
void __thiscall UR6GameManager::ClientLeaveServer(UR6GameManager* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler5;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    *(uint*)((byte*)this + 0x2c) &= ~0x10U; // m_bMultiPlayerGameActive.
    UR6GSServers* service = this->m_GameMgrGameService;
    bool hasService = service != nullptr;
    exceptionRegistration.state = 0;
    if (hasService) {
        auto isServerJoined = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xe4);
        if (isServerJoined(service) != 0) {
            service = this->m_GameMgrGameService;
            auto leaveServer = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xd8);
            leaveServer(service); // MSCLientLeaveServer.
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10011e0d : rethrow ClientLeaveServer's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_ClientLeaveServerCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10011e40 : store the shared create-Ubi-server integer without normalization
void __thiscall UR6GameManager::SetGSCreateUbiServer(UR6GameManager* this, int value)
{
    int& createUbiServerValue = CreateUbiServerValue;
    createUbiServerValue = value;
}

// R6Game.dll @ 10011e50 : return the shared create-Ubi-server integer
int __thiscall UR6GameManager::GetGSCreateUbiServer(UR6GameManager* this)
{
    const int& createUbiServerValue = CreateUbiServerValue;
    return createUbiServerValue;
}

// R6Game.dll @ 10011e90 : InitializeGameService
// Loads and constructs the game service, then initializes CD-key support for selected launch modes.
void __thiscall UR6GameManager::InitializeGameService(UR6GameManager* this, UConsole* console)
{
    UClass* serviceClass = UObject::StaticLoadClass(&UR6AbstractGameService::PrivateStaticClass, nullptr,
        L"R6GameService.R6GSServers", nullptr, 1, nullptr);
    UClass* classCursor = serviceClass;
    while (classCursor != nullptr && classCursor != &UR6AbstractGameService::PrivateStaticClass)
        classCursor = *(UClass**)((byte*)classCursor + 0x2c);
    if (classCursor == nullptr)
        appFailAssert("Class->IsChildOf(T::StaticClass())",
            "d:\\ravenshield\\412\\core\\inc\\UnObjBas.h", 0x476);
    UPackage* transientPackage = UObject::GetTransientPackage();
    UR6GSServers* service = (UR6GSServers*)UObject::StaticConstructObject(serviceClass, (UObject*)transientPackage,
        (FName)0, 0, nullptr, *(FOutputDeviceError**)ImportedGErrorAddress, 0);
    this->m_GameMgrGameService = service;
    if (service == nullptr) {
        FOutputDevice* log = *(FOutputDevice**)ImportedGLogAddress;
        FOutputDevice::Logf(log, L"Unable to initialize the gameservice inside gamemanager");
    } else if ((*(byte *)((byte *)console + 0x4c) & 0xe0U) != 0) {
        // m_bStartedByGSClient, m_bNonUbiMatchMaking, or m_bNonUbiMatchMakingHost.
        auto initializeCDKey = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x68);
        initializeCDKey(service); // InitGSCDKey; result ignored.
    }
}

// R6Game.dll @ 10011f40 : MSClientManager
// Dispatches master-server login/join work, disconnect checks, and general service processing.
void __thiscall UR6GameManager::MSClientManager(UR6GameManager* this, UConsole* console)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler6;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6GameMenuCom* menuCommunication = console->Master->m_MenuCommunication;
    exceptionRegistration.state = 0; // The console/Master reads precede this guard; there is no local string cleanup.
    AR6GameReplicationInfo* replicationInfo = nullptr;
    if (menuCommunication != nullptr) {
        AGameReplicationInfo* candidate = menuCommunication->m_GameRepInfo;
        if (candidate != nullptr)
            replicationInfo = (AR6GameReplicationInfo*)CastToAR6GameReplicationInfo((int)candidate);
    }
    float* processValue = &MasterServerProcessValue;
    // m_bMultiPlayerGameActive is mask 0x10 of the packed flags at +0x2c.
    if ((*(byte*)((byte*)this + 0x2c) & 0x10) != 0 && replicationInfo != nullptr) {
        if (replicationInfo->m_eCurrectServerState == 1) {
            bool hasServerIds = replicationInfo->m_iGameSvrLobbyID != 0 && replicationInfo->m_iGameSvrGroupID != 0;
            UR6GSServers* service = this->m_GameMgrGameService;
            auto processLogin = *(void (__thiscall**)(UR6GSServers*, int, float*))(*(byte**)service + 0x9c);
            processLogin(service, (int)hasServerIds, processValue);
            if (hasServerIds) {
                // The getter fills the outgoing by-value password; the join callee consumes those same words.
                __asm {
                    mov ecx,console
                    push offset MasterServerProcessValue
                    sub esp,0xc
                    mov eax,esp
                    mov dword ptr [ebp-0x18],esp
                    push eax
                    call dword ptr ds:R6GameAddresses::Engine_UInteraction_eventGetStoreGamePwdSlot // Hidden FString result; EAX is ignored.
                    mov eax,replicationInfo
                    mov eax,dword ptr [eax+0x3c8] // Live group ID after the getter.
                    mov ecx,this
                    mov ecx,dword ptr [ecx+0x30]
                    mov edx,dword ptr [ecx]
                    push eax
                    mov eax,replicationInfo
                    mov eax,dword ptr [eax+0x3cc] // Live lobby ID follows the service vptr read.
                    push eax
                    call dword ptr [edx+0xa0]
                }
            }
        }
        UR6GSServers* service = this->m_GameMgrGameService;
        auto processJoin = *(void (__thiscall**)(UR6GSServers*, float*))(*(byte**)service + 0xac);
        processJoin(service, processValue);
    }
    UR6GSServers* service = this->m_GameMgrGameService;
    auto processRouterDisconnect = *(void (__thiscall**)(UR6GSServers*, float*))(*(byte**)service + 0xa4);
    processRouterDisconnect(service, processValue);
    service = this->m_GameMgrGameService;
    auto processLobbyDisconnect = *(void (__thiscall**)(UR6GSServers*, float*))(*(byte**)service + 0xa8);
    processLobbyDisconnect(service, processValue);
    service = this->m_GameMgrGameService;
    auto processService = *(void (__thiscall**)(UR6GSServers*, int, int, int, int))(*(byte**)service + 0x98);
    processService(service, 1, 1, 0, 0);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1001204c : rethrow MSClientManager's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_MSClientManagerCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10012060 : report MSClientManager context and forward the active exception
__declspec(naked) void UR6GameManager_MSClientManagerCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_MSClientManagerExceptionContext // L"UR6GameManager::MSClientManager"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014330 : dispatch MSClientManager's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler6(void)
{
    __asm { mov eax, offset UR6GameManager_MSClientManagerExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10012080 : route a console command and consume its by-value string
// Selects a console and output device, executes the command, and destroys the command string.
void __thiscall UR6GameManager::DoConsoleCommand(UR6GameManager* this, FString command, UConsole* console)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler7;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10. This receiver is unused.
    __writefsdword(0, (uint)&exceptionRegistration);
    UConsole* selectedConsole = console;
    bool hasSuppliedConsole = selectedConsole != nullptr;
    exceptionRegistration.state = 0; // The twelve-byte incoming string is already constructed.
    *(byte*)&exceptionRegistration.state = 1;
    if (!hasSuppliedConsole) {
        UEngine* engine = *(UEngine**)Importedg_pEngineAddress;
        UClient* client = engine != nullptr ? engine->Client : nullptr;
        if (client != nullptr) {
            UPlayer** playerDataAt30 = *(UPlayer***)((byte*)client + 0x30);
            UPlayer* firstPlayer = playerDataAt30[0]; // No native array-count/data-pointer check.
            if (firstPlayer != nullptr) {
                selectedConsole = (UConsole*)firstPlayer->Console;
                if (selectedConsole != nullptr && selectedConsole->Master == nullptr)
                    selectedConsole = nullptr;
            }
        }
    }
    if (selectedConsole == nullptr) {
        FOutputDevice* warningOutput = *(FOutputDevice**)ImportedGWarnAddress;
        FOutputDevice::Logf(warningOutput,
            L"Attempt to execute a console command through an Interaction that is without a master");
    } else {
        UPlayer* outputPlayer = selectedConsole->ViewportOwner;
        if (outputPlayer == nullptr) {
            UClient* client = selectedConsole->Master->Client;
            UPlayer** playerDataAt30 = *(UPlayer***)((byte*)client + 0x30);
            outputPlayer = playerDataAt30[0];
        }
        FOutputDevice* output = outputPlayer != nullptr ? (FOutputDevice*)((byte*)outputPlayer + 0x2c) : nullptr;
        const ushort* commandText = FString::operator*(&command);
        UInteractionMaster* master = selectedConsole->Master;
        // Preserve the imported reference's pointer word, including the native null-output path.
        using ExecWordABI = int (__thiscall *)(UInteractionMaster*, const ushort*, FOutputDevice*);
        ExecWordABI execute = *(ExecWordABI*)R6GameImports::Engine_UInteractionMaster_ExecSlot;
        execute(master, commandText, output);
    }
    exceptionRegistration.state = -1;
    FString::~FString(&command);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10012149 : rethrow DoConsoleCommand's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_DoConsoleCommandCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10012180 : dispatch the audio callback and minimize the application
// Invokes the available audio callback, then executes MINIMIZEAPP through the console.
void __thiscall UR6GameManager::MinimizeAndPauseMusic(UR6GameManager* this, UConsole* console)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler8;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UEngine* engine = *(UEngine**)Importedg_pEngineAddress;
    bool hasEngine = engine != nullptr;
    exceptionRegistration.state = 0;
    if (hasEngine) {
        UAudioSubsystem* audio = engine->Audio;
        if (audio != nullptr) {
            auto audioCallbackAtFC = *(void (__thiscall**)(UAudioSubsystem*))(*(byte**)audio + 0xfc);
            audioCallbackAtFC(audio);
        }
    }
    // The inline argument string is consumed by DoConsoleCommand; this frame has no string cleanup action.
    using ConsoleCommandABI = void (__thiscall *)(UR6GameManager*, FString, UConsole*);
    const ConsoleCommandABI executeCommand = &UR6GameManager::DoConsoleCommand;
    __asm {
        mov eax,console
        push eax
        sub esp,0xc
        mov ecx,esp
        mov dword ptr [ebp+0x8],esp // Native reuse of the incoming console slot.
        push R6GameAddresses::MinimizeApplicationCommand // L"MINIMIZEAPP".
        call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
        mov ecx,this
        call executeCommand
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100121f7 : rethrow MinimizeAndPauseMusic's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_MinimizeAndPauseMusicCatchPointer(void)
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

// R6Game.dll @ 10012230 : GSClientManager
// Advances GS-client launch states and handles application return, termination and server setup messages.
void __thiscall UR6GameManager::GSClientManager(UR6GameManager* this, UConsole* console)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler9;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    uint* managerFlags = (uint*)((byte*)this + 0x2c);
    uint initialFlags = *managerFlags;
    bool needsInitialization = (initialFlags & 9U) == 0;
    exceptionRegistration.state = 0; // The initial flags read/test precedes the guard; no local string cleanup.
    if (needsInitialization) {
        InitializeGSClient(this);
        uint flags = *managerFlags;
        *managerFlags = flags ^ (((flags << 3) ^ flags) & 8U); // Copy Initialized into AlreadyInit.
    }
    UR6GSServers* service = this->m_GameMgrGameService;
    auto processService = *(void (__thiscall**)(UR6GSServers*, int, int, int, int))(*(byte**)service + 0x98);
    processService(service, 1, 1, 0, 1);
    service = this->m_GameMgrGameService;
    auto getGSState = *(byte (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xd0);
    const byte gsState = getGSState(service);
    int& gsClientStateLoggingEnabled = GSClientStateLoggingEnabled;
    int& lastLoggedGSClientState = LastLoggedGSClientState;
    using LogfCall = void (__cdecl *)(FOutputDevice*, const ushort*, ...);
    if (gsState <= 10 && gsClientStateLoggingEnabled != 0 && lastLoggedGSClientState != gsState) {
        const ushort* stateMessage = nullptr;
        switch (gsState) {
        case 0: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_WAITING_FOR_GS_INIT"; break;
        case 1: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_CLIENT_INIT_RCVD"; break;
        case 2: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_CLIENT_WAITING_CHSTA"; break;
        case 3: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_CLIENT_CHSTA_RCVD"; break;
        case 4: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_CLIENT_IN_GAME"; break;
        case 5: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_SERVER_INIT_RCVD"; break;
        case 6: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_SERVER_WAITING_CHSTA"; break;
        case 7: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_SERVER_CHSTA_RCVD"; break;
        case 8: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_SERVER_SETTING_UP_GAME"; break;
        case 9: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_TERMINATE_RCVD"; break;
        case 10: stateMessage = (const ushort*)L"GAMEMANAGER ----> EGS_SERVER_READY"; break;
        }
        FOutputDevice** logPointer;
        if (gsState == 0 || gsState == 1 || gsState == 2 || gsState == 5 || gsState == 8 || gsState == 9) {
            logPointer = (FOutputDevice**)ImportedGLogAddress;
            lastLoggedGSClientState = gsState;
        } else {
            lastLoggedGSClientState = gsState;
            logPointer = (FOutputDevice**)ImportedGLogAddress;
        }
        ((LogfCall)FOutputDevice::Logf)(*logPointer, stateMessage);
    }
    using ConsoleCommandABI = void (__thiscall *)(UR6GameManager*, FString, UConsole*);
    const ConsoleCommandABI executeCommand = &UR6GameManager::DoConsoleCommand;
    uint flags;
    void (__thiscall* postMessage)(UR6GSServers*, byte);
    void (__thiscall* setGSState)(UR6GSServers*, byte);
    switch (gsState) {
    case 0: // EGS_WAITING_FOR_GS_INIT.
        if ((*(byte*)((byte*)this->m_GameMgrGameService + 0x194) & 8U) != 0) { // m_bUbiComClientDied
            __asm {
                mov eax,console
                push eax
                sub esp,0xc
                mov ecx,esp
                mov dword ptr [ebp-0x18],esp
                push R6GameAddresses::QuitApplicationCommand // L"quit".
                call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
                mov ecx,this
                call executeCommand
            }
            ((LogfCall)FOutputDevice::Logf)(*(FOutputDevice**)ImportedGLogAddress,
                (const ushort*)L"Game exited because ubi.com client application died");
        }
        flags = *managerFlags;
        if ((flags & 4U) != 0) {
            UConsole* returnConsole = console;
            *managerFlags = flags & ~4U;
            MinimizeAndPauseMusic(this, returnConsole);
        }
        break;
    case 1: // EGS_CLIENT_INIT_RCVD.
        service = this->m_GameMgrGameService;
        postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
        postMessage(service, 3);
        service = this->m_GameMgrGameService;
        setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
        setGSState(service, 2);
        break;
    case 2: // EGS_CLIENT_WAITING_CHSTA.
        if ((*(byte*)((byte*)this->m_GameMgrGameService + 0x194) & 8U) != 0) { // m_bUbiComClientDied
            __asm {
                mov eax,console
                push eax
                sub esp,0xc
                mov ecx,esp
                mov dword ptr [ebp+0x8],esp
                push R6GameAddresses::QuitApplicationCommand // L"quit".
                call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
                mov ecx,this
                call executeCommand
            }
            if (gsClientStateLoggingEnabled != 0)
                ((LogfCall)FOutputDevice::Logf)(*(FOutputDevice**)ImportedGLogAddress,
                    (const ushort*)L"Game exited because ubi.com client application died");
        }
        service = this->m_GameMgrGameService;
        if ((*(byte*)((byte*)service + 0x194) & 0x10U) != 0) { // m_bUbiComRoomDestroyed
            *(uint*)((byte*)service + 0x194) &= ~0x10U;
            service = this->m_GameMgrGameService;
            setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
            setGSState(service, 0);
        }
        break;
    case 3: // EGS_CLIENT_CHSTA_RCVD.
        __asm {
            mov eax,console
            push eax
            sub esp,0xc
            mov ecx,esp
            mov dword ptr [ebp+0x8],esp
            push R6GameAddresses::MaximizeApplicationCommand // L"MAXIMIZEAPP".
            call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
            mov ecx,this
            call executeCommand
        }
        service = this->m_GameMgrGameService;
        postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
        postMessage(service, 4);
        service = this->m_GameMgrGameService;
        setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
        setGSState(service, 4);
        *managerFlags = (*managerFlags & ~0x40U) | 0x20U; // Clear QueryServerInfoDone; set GSJoinUbiServer.
        break;
    case 4: // EGS_CLIENT_IN_GAME.
    case 10: // EGS_SERVER_READY.
        flags = *managerFlags;
        if ((flags & 4U) != 0) {
            *managerFlags = flags & ~4U;
            MinimizeAndPauseMusic(this, console);
            service = this->m_GameMgrGameService;
            postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
            postMessage(service, 5);
            service = this->m_GameMgrGameService;
            setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
            setGSState(service, 0);
        }
        break;
    case 5: // EGS_SERVER_INIT_RCVD.
        service = this->m_GameMgrGameService;
        postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
        postMessage(service, 0);
        service = this->m_GameMgrGameService;
        setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
        setGSState(service, 6);
        break;
    case 6: // EGS_SERVER_WAITING_CHSTA.
        if ((*(byte*)((byte*)this->m_GameMgrGameService + 0x194) & 8U) != 0) { // m_bUbiComClientDied
            __asm {
                mov eax,console
                push eax
                sub esp,0xc
                mov ecx,esp
                mov dword ptr [ebp+0x8],esp
                push R6GameAddresses::QuitApplicationCommand // L"quit".
                call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
                mov ecx,this
                call executeCommand
            }
            if (gsClientStateLoggingEnabled != 0)
                ((LogfCall)FOutputDevice::Logf)(*(FOutputDevice**)ImportedGLogAddress,
                    (const ushort*)L"Game exited because ubi.com client application died");
        }
        break;
    case 7: { // EGS_SERVER_CHSTA_RCVD.
        __asm {
            mov eax,console
            push eax
            sub esp,0xc
            mov ecx,esp
            mov dword ptr [ebp+0x8],esp
            push R6GameAddresses::MaximizeApplicationCommand // L"MAXIMIZEAPP".
            call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
            mov ecx,this
            call executeCommand
        }
        service = this->m_GameMgrGameService;
        postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
        postMessage(service, 1);
        service = this->m_GameMgrGameService;
        setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
        setGSState(service, 8);
        auto setCreateServer = *(void (__thiscall**)(UR6GameManager*, int))(*(byte**)this + 0x88);
        setCreateServer(this, 1);
        break;
    }
    case 8: // EGS_SERVER_SETTING_UP_GAME.
        flags = *managerFlags;
        if ((flags & 4U) != 0) {
            *managerFlags = flags & ~4U;
            MinimizeAndPauseMusic(this, console);
            service = this->m_GameMgrGameService;
            postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
            postMessage(service, 5);
            service = this->m_GameMgrGameService;
            setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
            setGSState(service, 0);
        } else if ((flags & 0x10U) != 0) {
            service = this->m_GameMgrGameService;
            postMessage = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xd4);
            postMessage(service, 2);
            service = this->m_GameMgrGameService;
            setGSState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0xcc);
            setGSState(service, 10);
        }
        break;
    case 9: // EGS_TERMINATE_RCVD.
        __asm {
            mov eax,console
            push eax
            sub esp,0xc
            mov ecx,esp
            mov dword ptr [ebp+0x8],esp
            push R6GameAddresses::QuitApplicationCommand // L"quit".
            call dword ptr ds:R6GameAddresses::Core_FString_TextConstructorSlot
            mov ecx,this
            call executeCommand
        }
        break;
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100127bf : rethrow GSClientManager's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_GSClientManagerCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100127d3 : report GSClientManager context and forward the active exception
__declspec(naked) void UR6GameManager_GSClientManagerCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_GSClientManagerExceptionContext // L"UR6GameManager::GSClientManager"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014370 : dispatch GSClientManager's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler9(void)
{
    __asm { mov eax, offset UR6GameManager_GSClientManagerExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10012820 : LaunchListenSrv
// Builds and executes a listen-server command with map, options and two authentication IDs.
void __thiscall UR6GameManager::LaunchListenSrv(UR6GameManager* this, FString mapName, FString options)
{
    alignas(4) byte commandStorage[12], authStorage[12]; // Native command/auth bindings: -0x28/-0x34.
    FString* command = (FString*)commandStorage;
    FString* authResult = (FString*)authStorage;
    using GetAuthIDCall = FString* (__thiscall *)(UR6GSServers*, FString*, int);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler10;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // States 0 and 1 own options and the first incoming string; ESP is saved at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    *(byte*)&exceptionRegistration.state = 2;
    FString::FString(command, (ushort*)L"OPEN ");
    *(byte*)&exceptionRegistration.state = 3;
    FString::operator+=(command, &mapName);
    FString::operator+=(command, (ushort*)L"?listen?");
    FString::operator+=(command, &options);
    FString::operator+=(command, (ushort*)L"?AuthID1=");
    UR6GSServers* service = this->m_GameMgrGameService;
    GetAuthIDCall getAuthID = *(GetAuthIDCall*)(*(byte**)service + 0xc0);
    FString* authID = getAuthID(service, authResult, 0);
    *(byte*)&exceptionRegistration.state = 4;
    FString::operator+=(command, authID);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(authResult);
    FString::operator+=(command, (ushort*)L"?AuthID2=");
    service = this->m_GameMgrGameService;
    getAuthID = *(GetAuthIDCall*)(*(byte**)service + 0xc0);
    authID = getAuthID(service, authResult, 1);
    *(byte*)&exceptionRegistration.state = 5;
    FString::operator+=(command, authID);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(authResult);
    FString::operator+=(command, (ushort*)L"?ESRB");
    // Copy directly into the outgoing by-value string; DoConsoleCommand owns its destruction.
    using ConsoleCommandABI = void (__thiscall *)(UR6GameManager*, FString, UConsole*);
    const ConsoleCommandABI executeCommand = &UR6GameManager::DoConsoleCommand;
    __asm {
        push 0x0
        sub esp,0xc
        mov edx,command
        mov ecx,esp
        mov dword ptr [ebp-0x18],esp
        push edx
        call dword ptr ds:R6GameAddresses::Core_FString_CopyConstructorSlot
        mov ecx,this
        call executeCommand
    }
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(command);
    exceptionRegistration.state = 0;
    FString::~FString(&mapName);
    exceptionRegistration.state = -1;
    FString::~FString(&options);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10012964 : rethrow LaunchListenSrv's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_LaunchListenSrvCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 100129a0 : StartJoinServer
// Builds and executes a join command with server, spawn number, options and two authentication IDs.
void __thiscall UR6GameManager::StartJoinServer(
    UR6GameManager* this, FString serverAddress, FString options, int spawnNumber)
{
    alignas(4) byte commandStorage[12], authStorage[12]; // Native command/auth bindings: -0x24/-0x30.
    FString* command = (FString*)commandStorage;
    FString* authResult = (FString*)authStorage;
    using GetAuthIDCall = FString* (__thiscall *)(UR6GSServers*, FString*, int);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler11;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // States 0 and 1 own options and the first incoming string; ESP is saved at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    *(byte*)&exceptionRegistration.state = 2;
    FString::FString(command, (ushort*)L"Start ");
    *(byte*)&exceptionRegistration.state = 3;
    FString::operator+=(command, &serverAddress);
    FString::operator+=(command, (ushort*)L"?SpawnNum=");
    ushort* spawnText = appItoa(spawnNumber); // Borrowed Core conversion buffer.
    FString::operator+=(command, spawnText);
    FString::operator+=(command, &options);
    FString::operator+=(command, (ushort*)L"?AuthID1=");
    UR6GSServers* service = this->m_GameMgrGameService;
    GetAuthIDCall getAuthID = *(GetAuthIDCall*)(*(byte**)service + 0xc0);
    FString* authID = getAuthID(service, authResult, 0);
    *(byte*)&exceptionRegistration.state = 4;
    FString::operator+=(command, authID);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(authResult);
    FString::operator+=(command, (ushort*)L"?AuthID2=");
    service = this->m_GameMgrGameService;
    getAuthID = *(GetAuthIDCall*)(*(byte**)service + 0xc0);
    authID = getAuthID(service, authResult, 1);
    *(byte*)&exceptionRegistration.state = 5;
    FString::operator+=(command, authID);
    *(byte*)&exceptionRegistration.state = 3;
    FString::~FString(authResult);
    FString::operator+=(command, (ushort*)L"?ESRB");
    // Copy directly into the outgoing by-value string; DoConsoleCommand owns its destruction.
    using ConsoleCommandABI = void (__thiscall *)(UR6GameManager*, FString, UConsole*);
    const ConsoleCommandABI executeCommand = &UR6GameManager::DoConsoleCommand;
    __asm {
        push 0x0
        sub esp,0xc
        mov eax,command
        mov ecx,esp
        mov dword ptr [ebp+0x20],esp // Reuse the incoming spawn-number word after conversion.
        push eax
        call dword ptr ds:R6GameAddresses::Core_FString_CopyConstructorSlot
        mov ecx,this
        call executeCommand
    }
    *(byte*)&exceptionRegistration.state = 2;
    FString::~FString(command);
    exceptionRegistration.state = 0;
    FString::~FString(&serverAddress);
    exceptionRegistration.state = -1;
    FString::~FString(&options);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10012afb : rethrow StartJoinServer's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_StartJoinServerCatchPointer(void)
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

// R6Game.dll @ 10012b30 : GameServiceTick
// Dispatches the service manager selected by the console launch flag.
void __thiscall UR6GameManager::GameServiceTick(UR6GameManager* this, UConsole* console)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&Shared_UR6GameManager_ExceptionHandler12;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UR6GSServers* initialService = this->m_GameMgrGameService;
    bool hasService = initialService != nullptr;
    exceptionRegistration.state = 0;
    if (hasService) {
        if ((*(byte*)((byte*)console + 0x4c) & 0x20U) != 0) // m_bStartedByGSClient.
            GSClientManager(this, console);
        else
            MSClientManager(this, console);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10012b99 : rethrow GameServiceTick's caught UTF-16 pointer value
__declspec(naked) void UR6GameManager_GameServiceTickCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 10013530 : destroy the abstract-manager base if concrete-phase shutdown unwinds
__declspec(naked) void UR6GameManager_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Engine_UR6AbstractGameManager_DestructorSlot // UR6AbstractGameManager destructor.
    }
}

// R6Game.dll @ 10013539 : destroy UObject if abstract-phase shutdown unwinds
__declspec(naked) void UR6GameManager_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::Core_UObject_DestructorSlot // UObject destructor.
    }
}

// R6Game.dll @ 100142b0 : destroy StartPreJoinProcedure's message while unwinding branch state 1
__declspec(naked) void UR6GameManager_StartPreJoinProcedureUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142b9 : destroy StartPreJoinProcedure's message while unwinding branch state 2
__declspec(naked) void UR6GameManager_StartPreJoinProcedureUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142c2 : destroy StartPreJoinProcedure's message while unwinding branch state 3
__declspec(naked) void UR6GameManager_StartPreJoinProcedureUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142cb : destroy StartPreJoinProcedure's message while unwinding branch state 4
__declspec(naked) void UR6GameManager_StartPreJoinProcedureUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142e0 : destroy StartLogInProcedure's message while unwinding branch state 1
__declspec(naked) void UR6GameManager_StartLogInProcedureUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142e9 : destroy StartLogInProcedure's message while unwinding branch state 2
__declspec(naked) void UR6GameManager_StartLogInProcedureUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100142f2 : destroy StartLogInProcedure's message while unwinding branch state 3
__declspec(naked) void UR6GameManager_StartLogInProcedureUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014340 : destroy DoConsoleCommand's incoming by-value string during unwinding
__declspec(naked) void UR6GameManager_DoConsoleCommandUnwind(void)
{
    __asm {
        lea ecx,[ebp+0x8]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014380 : destroy LaunchListenSrv's incoming options during unwinding
__declspec(naked) void UR6GameManager_LaunchListenSrvUnwind(void)
{
    __asm {
        lea ecx,[ebp+0x14]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014389 : destroy LaunchListenSrv's incoming map name during unwinding
__declspec(naked) void UR6GameManager_LaunchListenSrvUnwind1(void)
{
    __asm {
        lea ecx,[ebp+0x8]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014392 : destroy LaunchListenSrv's command during unwinding
__declspec(naked) void UR6GameManager_LaunchListenSrvUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 1001439b : destroy LaunchListenSrv's first authentication result during unwinding
__declspec(naked) void UR6GameManager_LaunchListenSrvUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143a4 : destroy LaunchListenSrv's second authentication result during unwinding
__declspec(naked) void UR6GameManager_LaunchListenSrvUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143c0 : destroy StartJoinServer's incoming options during unwinding
__declspec(naked) void UR6GameManager_StartJoinServerUnwind(void)
{
    __asm {
        lea ecx,[ebp+0x14]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143c9 : destroy StartJoinServer's incoming server address during unwinding
__declspec(naked) void UR6GameManager_StartJoinServerUnwind1(void)
{
    __asm {
        lea ecx,[ebp+0x8]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143d2 : destroy StartJoinServer's command during unwinding
__declspec(naked) void UR6GameManager_StartJoinServerUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143db : destroy StartJoinServer's first authentication result during unwinding
__declspec(naked) void UR6GameManager_StartJoinServerUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100143e4 : destroy StartJoinServer's second authentication result during unwinding
__declspec(naked) void UR6GameManager_StartJoinServerUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014d80 : initialize UR6GameManager class metadata and register its cleanup
void InitializeUR6GameManagerClassMetadata(void)
{
    auto staticConstructor = ImportedUObjectStaticConstructorAddress;
    UClass* withinClass = (UClass*)ImportedUObjectClass;
    UClass* parentClass = (UClass*)ImportedUR6AbstractGameManagerClass;
    const ushort* configName = UObject::StaticConfigName();
    UClass::UClass((UClass*)UR6GameManagerClassMetadataStorage, 0, 0x38, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
        L"R6GameManager", GPackage, configName, 0x4084004, UR6GameManager::InternalConstructor, staticConstructor);
    _atexit(DestroyUR6GameManagerClassMetadata);
}

// R6Game.dll @ 10015180 : destroy UR6GameManager class metadata
void DestroyUR6GameManagerClassMetadata(void)
{
    UClass::~UClass((UClass*)UR6GameManagerClassMetadataStorage); // Native tail jump.
}

// R6Game.dll @ 10011d85 : report ConnectionInterrupted context and forward the active exception
__declspec(naked) void UR6GameManager_ConnectionInterruptedCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_ConnectionInterruptedExceptionContext // L"UR6GameManager::ConnectionInterrupted"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014310 : dispatch ConnectionInterrupted's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler4(void)
{
    __asm { mov eax, offset UR6GameManager_ConnectionInterruptedExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10011e21 : report ClientLeaveServer context and forward the active exception
__declspec(naked) void UR6GameManager_ClientLeaveServerCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_ClientLeaveServerExceptionContext // L"UR6GameManager::ClientLeaveServer"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014320 : dispatch ClientLeaveServer's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler5(void)
{
    __asm { mov eax, offset UR6GameManager_ClientLeaveServerExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 1001215d : report DoConsoleCommand context and forward the active exception
__declspec(naked) void UR6GameManager_DoConsoleCommandCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_DoConsoleCommandExceptionContext // L"UR6GameManager::DoConsoleCommand"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014349 : dispatch DoConsoleCommand's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler7(void)
{
    __asm { mov eax, offset UR6GameManager_DoConsoleCommandExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 1001220b : report MinimizeAndPauseMusic context and forward the active exception
__declspec(naked) void UR6GameManager_MinimizeAndPauseMusicCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_MinimizeAndPauseMusicExceptionContext // L"UR6GameManager::MinimizeAndPauseMusic"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014360 : dispatch MinimizeAndPauseMusic's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler8(void)
{
    __asm { mov eax, offset UR6GameManager_MinimizeAndPauseMusicExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10011a8f : report InitializeGSClient context and forward the active exception
__declspec(naked) void UR6GameManager_InitializeGSClientCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_InitializeGSClientExceptionContext // L"UR6GameManager::InitializeGSClient"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100142a0 : dispatch InitializeGSClient's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler1(void)
{
    __asm { mov eax, offset UR6GameManager_InitializeGSClientExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10011bd7 : report StartPreJoinProcedure context and forward the active exception
__declspec(naked) void UR6GameManager_StartPreJoinProcedureCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_StartPreJoinProcedureExceptionContext // L"UR6GameManager::StartPreJoinProcedure"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100142d4 : dispatch StartPreJoinProcedure's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler2(void)
{
    __asm { mov eax, offset UR6GameManager_StartPreJoinProcedureExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10011cec : report StartLogInProcedure context and forward the active exception
__declspec(naked) void UR6GameManager_StartLogInProcedureCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_StartLogInProcedureExceptionContext // L"UR6GameManager::StartLogInProcedure"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100142fb : dispatch StartLogInProcedure's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler3(void)
{
    __asm { mov eax, offset UR6GameManager_StartLogInProcedureExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10012bad : report GameServiceTick context and forward the active exception
__declspec(naked) void UR6GameManager_GameServiceTickCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_GameServiceTickExceptionContext // L"UR6GameManager::GameServiceTick"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10014400 : dispatch GameServiceTick's guard and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler12(void)
{
    __asm { mov eax, offset UR6GameManager_GameServiceTickExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10012978 : report LaunchListenSrv context and forward the active exception
__declspec(naked) void UR6GameManager_LaunchListenSrvCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_LaunchListenSrvExceptionContext // L"UR6GameManager::LaunchListenSrv"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100143ad : dispatch LaunchListenSrv's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler10(void)
{
    __asm { mov eax, offset UR6GameManager_LaunchListenSrvExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10012b0f : report StartJoinServer context and forward the active exception
__declspec(naked) void UR6GameManager_StartJoinServerCatchContext(void)
{
    __asm {
        push R6GameAddresses::UR6GameManager_StartJoinServerExceptionContext // L"UR6GameManager::StartJoinServer"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100143ed : dispatch StartJoinServer's guard, string cleanup and catch states
__declspec(naked) void Shared_UR6GameManager_ExceptionHandler11(void)
{
    __asm { mov eax, offset UR6GameManager_StartJoinServerExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014e10 : bind the exported UR6GameManager auto-class pointer
void InitializeUR6GameManagerAutoClassPointer(void)
{
    autoclassUR6GameManager = (UClass*)UR6GameManagerClassMetadataStorage; // Exported slot 0x10027964.
}

// R6Game.dll @ 10013542 : dispatch native C++ cleanup and catch states through FuncInfo 0x1001a034
__declspec(naked) void UR6GameManagerExceptionDispatcher(void)
{
    __asm { mov eax, offset UR6GameManager_DestructExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
