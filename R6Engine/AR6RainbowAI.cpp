#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b4e8 : AR6RainbowAIVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6RainbowAI::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6RainbowAIVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10052d98 : nativeTextAR6RainbowAIAClearShotIsAvailable
extern const ushort nativeTextAR6RainbowAIAClearShotIsAvailable[36];

// R6Engine.dll data @ 10052c48 : nativeTextAR6RainbowAICheckEnvironment
extern const ushort nativeTextAR6RainbowAICheckEnvironment[31];

// R6Engine.dll data @ 10052de0 : nativeTextAR6RainbowAIClearToSnipe
extern const ushort nativeTextAR6RainbowAIClearToSnipe[27];

// R6Engine.dll data @ 10053008 : nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage1
extern const ushort nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage1[40];

// R6Engine.dll data @ 10053058 : nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage2
extern const ushort nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage2[40];

// R6Engine.dll data @ 10052f80 : nativeTextAR6RainbowAIExecCheckEnvironment
extern const ushort nativeTextAR6RainbowAIExecCheckEnvironment[35];

// R6Engine.dll data @ 10052fc8 : nativeTextAR6RainbowAIExecFindSafeSpot
extern const ushort nativeTextAR6RainbowAIExecFindSafeSpot[31];

// R6Engine.dll data @ 10052ef0 : nativeTextAR6RainbowAIExecGetEntryPosition
extern const ushort nativeTextAR6RainbowAIExecGetEntryPosition[35];

// R6Engine.dll data @ 10052ea8 : nativeTextAR6RainbowAIExecGetGuardPosition
extern const ushort nativeTextAR6RainbowAIExecGetGuardPosition[35];

// R6Engine.dll data @ 10052e60 : nativeTextAR6RainbowAIExecGetLadderPosition
extern const ushort nativeTextAR6RainbowAIExecGetLadderPosition[36];

// R6Engine.dll data @ 10052e18 : nativeTextAR6RainbowAIExecGetTargetPosition
extern const ushort nativeTextAR6RainbowAIExecGetTargetPosition[36];

// R6Engine.dll data @ 10052d18 : nativeTextAR6RainbowAIExecLookAroundRoom
extern const ushort nativeTextAR6RainbowAIExecLookAroundRoom[33];

// R6Engine.dll data @ 10052f38 : nativeTextAR6RainbowAIExecSetOrientation
extern const ushort nativeTextAR6RainbowAIExecSetOrientation[33];

// R6Engine.dll data @ 10052d5c : nativeTextAR6RainbowAIFindSafeSpot
extern const ushort nativeTextAR6RainbowAIFindSafeSpot[27];

// R6Engine.dll data @ 10052b84 : nativeTextAR6RainbowAIGetEntryPosition
extern const ushort nativeTextAR6RainbowAIGetEntryPosition[31];

// R6Engine.dll data @ 10052bc4 : nativeTextAR6RainbowAIGetGuardPosition
extern const ushort nativeTextAR6RainbowAIGetGuardPosition[31];

// R6Engine.dll data @ 10052c08 : nativeTextAR6RainbowAIGetLadderPosition
extern const ushort nativeTextAR6RainbowAIGetLadderPosition[32];

// R6Engine.dll data @ 10052b40 : nativeTextAR6RainbowAIGetPreEntryPosition
extern const ushort nativeTextAR6RainbowAIGetPreEntryPosition[34];

// R6Engine.dll data @ 10052c98 : nativeTextAR6RainbowAIGetTargetPosition
extern const ushort nativeTextAR6RainbowAIGetTargetPosition[32];

// R6Engine.dll data @ 10052af8 : nativeTextAR6RainbowAISetMemberOrientation
extern const ushort nativeTextAR6RainbowAISetMemberOrientation[35];

// R6Engine.dll data @ 10052cd8 : nativeTextAR6RainbowAIUpdateTimers
extern const ushort nativeTextAR6RainbowAIUpdateTimers[27];

// R6Engine.dll data @ 1005568e : nativeTextR6RainbowAI
extern const ushort nativeTextR6RainbowAI[12];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void RainbowBridgeAClearShotIsAvailableCatchContext(void);
__declspec(naked) void RainbowBridgeAClearShotIsAvailableCatchPointer(void);
__declspec(naked) void RainbowBridgeCheckEnvironmentCatchContext(void);
__declspec(naked) void RainbowBridgeCheckEnvironmentCatchPointer(void);
__declspec(naked) void RainbowBridgeClearToSnipeCatchContext(void);
__declspec(naked) void RainbowBridgeClearToSnipeCatchPointer(void);
__declspec(naked) void RainbowBridgeFindSafeSpotCatchContext(void);
__declspec(naked) void RainbowBridgeFindSafeSpotCatchPointer(void);
__declspec(naked) void RainbowBridgeGetEntryPositionCatchContext(void);
__declspec(naked) void RainbowBridgeGetEntryPositionCatchPointer(void);
__declspec(naked) void RainbowBridgeGetGuardPositionCatchContext(void);
__declspec(naked) void RainbowBridgeGetGuardPositionCatchPointer(void);
__declspec(naked) void RainbowBridgeGetLadderPositionCatchContext(void);
__declspec(naked) void RainbowBridgeGetLadderPositionCatchPointer(void);
__declspec(naked) void RainbowBridgeGetTargetPositionCatchContext(void);
__declspec(naked) void RainbowBridgeGetTargetPositionCatchPointer(void);
__declspec(naked) void RainbowBridgeSetOrientationCatchContext(void);
__declspec(naked) void RainbowBridgeSetOrientationCatchPointer(void);
__declspec(naked) void RainbowClearanceShotCatchContext(void);
__declspec(naked) void RainbowClearanceShotCatchPointer(void);
__declspec(naked) void RainbowClearanceSnipeCatchContext(void);
__declspec(naked) void RainbowClearanceSnipeCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEntryCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEntryCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEnvironmentCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEnvironmentCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowGuardCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowGuardCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowLadderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowLadderCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowOrientationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowOrientationCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowPreEntryCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RainbowPreEntryCatchPointer(void);
__declspec(naked) void RainbowRoomBridgeCatchContext(void);
__declspec(naked) void RainbowRoomBridgeCatchPointer(void);
__declspec(naked) void RainbowSafeCatchContext(void);
__declspec(naked) void RainbowSafeCatchPointer(void);
__declspec(naked) void RainbowTargetCatchContext(void);
__declspec(naked) void RainbowTargetCatchPointer(void);
__declspec(naked) void RainbowTimersCatchContext(void);
__declspec(naked) void RainbowTimersCatchPointer(void);

// R6Engine.dll data @ 10050bd0 : nativeFloat108
extern const float nativeFloat108;

// R6Engine.dll data @ 10050bd4 : nativeFloat115
extern const float nativeFloat115;

// R6Engine.dll data @ 10052c88 : nativeDouble1
extern const double nativeDouble1;

// R6Engine.dll data @ 10052c90 : nativeFloat3EPlus02
extern const float nativeFloat3EPlus02;

// R6Engine.dll data @ 10052d10 : nativeFloat0Point05
extern const float nativeFloat0Point05;

// R6Engine.dll data @ 1005cd4c : rainbowBridgeGetTargetPositionUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeGetTargetPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cd5c : rainbowBridgeGetTargetPositionCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeGetTargetPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeGetTargetPositionCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeGetTargetPositionCatchContext) }
};

// R6Engine.dll data @ 1005cd7c : rainbowBridgeGetTargetPositionTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeGetTargetPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeGetTargetPositionCatchMap) }
};

// R6Engine.dll data @ 1005cd90 : rainbowBridgeGetTargetPositionFuncInfo
// Exact GetTargetPosition script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeGetTargetPositionFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeGetTargetPositionUnwindMap), 0x1,
        ((uint)&rainbowBridgeGetTargetPositionTryMap), 0
};

// R6Engine.dll data @ 1005cdac : rainbowBridgeGetLadderPositionUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeGetLadderPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cdbc : rainbowBridgeGetLadderPositionCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeGetLadderPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeGetLadderPositionCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeGetLadderPositionCatchContext) }
};

// R6Engine.dll data @ 1005cddc : rainbowBridgeGetLadderPositionTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeGetLadderPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeGetLadderPositionCatchMap) }
};

// R6Engine.dll data @ 1005cdf0 : rainbowBridgeGetLadderPositionFuncInfo
// Exact GetLadderPosition script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeGetLadderPositionFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeGetLadderPositionUnwindMap), 0x1,
        ((uint)&rainbowBridgeGetLadderPositionTryMap), 0
};

// R6Engine.dll data @ 1005ce0c : rainbowBridgeGetGuardPositionUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeGetGuardPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ce1c : rainbowBridgeGetGuardPositionCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeGetGuardPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeGetGuardPositionCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeGetGuardPositionCatchContext) }
};

// R6Engine.dll data @ 1005ce3c : rainbowBridgeGetGuardPositionTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeGetGuardPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeGetGuardPositionCatchMap) }
};

// R6Engine.dll data @ 1005ce50 : rainbowBridgeGetGuardPositionFuncInfo
// Exact GetGuardPosition script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeGetGuardPositionFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeGetGuardPositionUnwindMap), 0x1, ((uint)&rainbowBridgeGetGuardPositionTryMap),
        0
};

// R6Engine.dll data @ 1005ce6c : rainbowBridgeGetEntryPositionUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeGetEntryPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ce7c : rainbowBridgeGetEntryPositionCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeGetEntryPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowBridgeGetEntryPositionCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeGetEntryPositionCatchContext) }
};

// R6Engine.dll data @ 1005ce9c : rainbowBridgeGetEntryPositionTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeGetEntryPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeGetEntryPositionCatchMap) }
};

// R6Engine.dll data @ 1005ceb0 : rainbowBridgeGetEntryPositionFuncInfo
// Exact GetEntryPosition script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeGetEntryPositionFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeGetEntryPositionUnwindMap), 0x1, ((uint)&rainbowBridgeGetEntryPositionTryMap),
        0
};

// R6Engine.dll data @ 1005cecc : rainbowBridgeSetOrientationUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeSetOrientationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cedc : rainbowBridgeSetOrientationCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeSetOrientationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowBridgeSetOrientationCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeSetOrientationCatchContext) }
};

// R6Engine.dll data @ 1005cefc : rainbowBridgeSetOrientationTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeSetOrientationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeSetOrientationCatchMap) }
};

// R6Engine.dll data @ 1005cf10 : rainbowBridgeSetOrientationFuncInfo
// Exact SetOrientation script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeSetOrientationFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeSetOrientationUnwindMap), 0x1, ((uint)&rainbowBridgeSetOrientationTryMap), 0
};

// R6Engine.dll data @ 1005cf2c : rainbowBridgeCheckEnvironmentUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeCheckEnvironmentUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cf3c : rainbowBridgeCheckEnvironmentCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeCheckEnvironmentCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeCheckEnvironmentCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeCheckEnvironmentCatchContext) }
};

// R6Engine.dll data @ 1005cf5c : rainbowBridgeCheckEnvironmentTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeCheckEnvironmentTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeCheckEnvironmentCatchMap) }
};

// R6Engine.dll data @ 1005cf70 : rainbowBridgeCheckEnvironmentFuncInfo
// Exact CheckEnvironment script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeCheckEnvironmentFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeCheckEnvironmentUnwindMap), 0x1, ((uint)&rainbowBridgeCheckEnvironmentTryMap),
        0
};

// R6Engine.dll data @ 1005cf8c : rainbowBridgeFindSafeSpotUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeFindSafeSpotUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cf9c : rainbowBridgeFindSafeSpotCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeFindSafeSpotCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeFindSafeSpotCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeFindSafeSpotCatchContext) }
};

// R6Engine.dll data @ 1005cfbc : rainbowBridgeFindSafeSpotTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeFindSafeSpotTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeFindSafeSpotCatchMap) }
};

// R6Engine.dll data @ 1005cfd0 : rainbowBridgeFindSafeSpotFuncInfo
// Exact FindSafeSpot script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeFindSafeSpotFuncInfo = { 0x19930520, 0x2,
    ((uint)&rainbowBridgeFindSafeSpotUnwindMap), 0x1, ((uint)&rainbowBridgeFindSafeSpotTryMap), 0 };

// R6Engine.dll data @ 1005cfec : rainbowBridgeAClearShotIsAvailableUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeAClearShotIsAvailableUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cffc : rainbowBridgeAClearShotIsAvailableCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeAClearShotIsAvailableCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowBridgeAClearShotIsAvailableCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeAClearShotIsAvailableCatchContext) }
};

// R6Engine.dll data @ 1005d01c : rainbowBridgeAClearShotIsAvailableTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeAClearShotIsAvailableTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeAClearShotIsAvailableCatchMap) }
};

// R6Engine.dll data @ 1005d030 : rainbowBridgeAClearShotIsAvailableFuncInfo
// Exact AClearShotIsAvailable script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeAClearShotIsAvailableFuncInfo = {
    0x19930520, 0x2, ((uint)&rainbowBridgeAClearShotIsAvailableUnwindMap), 0x1,
        ((uint)&rainbowBridgeAClearShotIsAvailableTryMap), 0
};

// R6Engine.dll data @ 1005d04c : rainbowBridgeClearToSnipeUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowBridgeClearToSnipeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d05c : rainbowBridgeClearToSnipeCatchMap
// Typed pointer followed by context catch-all.
const NativeCatchEntry rainbowBridgeClearToSnipeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowBridgeClearToSnipeCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowBridgeClearToSnipeCatchContext) }
};

// R6Engine.dll data @ 1005d07c : rainbowBridgeClearToSnipeTryMap
// State0 body and state1 catches select both handlers.
const NativeTryBlock rainbowBridgeClearToSnipeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowBridgeClearToSnipeCatchMap) }
};

// R6Engine.dll data @ 1005d090 : rainbowBridgeClearToSnipeFuncInfo
// Exact ClearToSnipe script-bridge exception metadata.
const NativeFunctionInfoPrefix rainbowBridgeClearToSnipeFuncInfo = { 0x19930520, 0x2,
    ((uint)&rainbowBridgeClearToSnipeUnwindMap), 0x1, ((uint)&rainbowBridgeClearToSnipeTryMap), 0 };

// R6Engine.dll data @ 1005cc8c : rainbowClearanceShotUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowClearanceShotUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cc9c : rainbowClearanceShotCatchMap
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry rainbowClearanceShotCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowClearanceShotCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowClearanceShotCatchContext) }
};

// R6Engine.dll data @ 1005ccbc : rainbowClearanceShotTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowClearanceShotTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowClearanceShotCatchMap) }
};

// R6Engine.dll data @ 1005ccd0 : rainbowClearanceShotFuncInfo
// Exact clear-shot parent-frame metadata.
const NativeFunctionInfoPrefix rainbowClearanceShotFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowClearanceShotUnwindMap),
    0x1, ((uint)&rainbowClearanceShotTryMap), 0 };

// R6Engine.dll data @ 1005ccec : rainbowClearanceSnipeUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowClearanceSnipeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ccfc : rainbowClearanceSnipeCatchMap
// Typed pointer at EBP-1c followed by context catch-all.
const NativeCatchEntry rainbowClearanceSnipeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowClearanceSnipeCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowClearanceSnipeCatchContext) }
};

// R6Engine.dll data @ 1005cd1c : rainbowClearanceSnipeTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowClearanceSnipeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowClearanceSnipeCatchMap) }
};

// R6Engine.dll data @ 1005cd30 : rainbowClearanceSnipeFuncInfo
// Exact sniping-clearance parent-frame metadata.
const NativeFunctionInfoPrefix rainbowClearanceSnipeFuncInfo = { 0x19930520, 0x2,
    ((uint)&rainbowClearanceSnipeUnwindMap), 0x1, ((uint)&rainbowClearanceSnipeTryMap), 0 };

// R6Engine.dll data @ 1005cc2c : rainbowSafeUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowSafeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cc3c : rainbowSafeCatchMap
// Typed pointer at EBP-20 followed by context catch-all.
const NativeCatchEntry rainbowSafeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&RainbowSafeCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowSafeCatchContext) }
};

// R6Engine.dll data @ 1005cc5c : rainbowSafeTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowSafeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowSafeCatchMap) }
};

// R6Engine.dll data @ 1005cc70 : rainbowSafeFuncInfo
// Exact safe-navigation-search parent-frame metadata.
const NativeFunctionInfoPrefix rainbowSafeFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowSafeUnwindMap), 0x1,
    ((uint)&rainbowSafeTryMap), 0 };

// R6Engine.dll data @ 1005cbcc : rainbowRoomBridgeUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowRoomBridgeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cbdc : rainbowRoomBridgeCatchMap
// Typed pointer at EBP-1c followed by context catch-all.
const NativeCatchEntry rainbowRoomBridgeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowRoomBridgeCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowRoomBridgeCatchContext) }
};

// R6Engine.dll data @ 1005cbfc : rainbowRoomBridgeTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowRoomBridgeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowRoomBridgeCatchMap) }
};

// R6Engine.dll data @ 1005cc10 : rainbowRoomBridgeFuncInfo
// Exact room-scan bridge parent-frame metadata.
const NativeFunctionInfoPrefix rainbowRoomBridgeFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowRoomBridgeUnwindMap), 0x1,
    ((uint)&rainbowRoomBridgeTryMap), 0 };

// R6Engine.dll data @ 1005cb6c : rainbowTimersUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowTimersUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cb7c : rainbowTimersCatchMap
// Typed pointer at EBP-20 followed by context catch-all.
const NativeCatchEntry rainbowTimersCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&RainbowTimersCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowTimersCatchContext) }
};

// R6Engine.dll data @ 1005cb9c : rainbowTimersTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowTimersTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowTimersCatchMap) }
};

// R6Engine.dll data @ 1005cbb0 : rainbowTimersFuncInfo
// Exact timer-update parent-frame metadata.
const NativeFunctionInfoPrefix rainbowTimersFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowTimersUnwindMap), 0x1,
    ((uint)&rainbowTimersTryMap), 0 };

// R6Engine.dll data @ 1005cb0c : rainbowTargetUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowTargetUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cb1c : rainbowTargetCatchMap
// Typed pointer at EBP-8c followed by context catch-all.
const NativeCatchEntry rainbowTargetCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -140, ((uint)&RainbowTargetCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowTargetCatchContext) }
};

// R6Engine.dll data @ 1005cb3c : rainbowTargetTryMap
// State0 body/state1 catches select both handlers.
const NativeTryBlock rainbowTargetTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowTargetCatchMap) }
};

// R6Engine.dll data @ 1005cb50 : rainbowTargetFuncInfo
// Exact formation-target parent-frame metadata.
const NativeFunctionInfoPrefix rainbowTargetFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowTargetUnwindMap), 0x1,
    ((uint)&rainbowTargetTryMap), 0 };

// R6Engine.dll data @ 1005caac : rainbowEnvironmentUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowEnvironmentUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005cabc : rainbowEnvironmentCatchMap
// Typed pointer at EBP-ac followed by context catch-all.
const NativeCatchEntry rainbowEnvironmentCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -172, ((uint)&RainbowEnvironmentCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowEnvironmentCatchContext) }
};

// R6Engine.dll data @ 1005cadc : rainbowEnvironmentTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowEnvironmentTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowEnvironmentCatchMap) }
};

// R6Engine.dll data @ 1005caf0 : rainbowEnvironmentFuncInfo
// Exact checkEnvironment parent-frame metadata.
const NativeFunctionInfoPrefix rainbowEnvironmentFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowEnvironmentUnwindMap),
    0x1, ((uint)&rainbowEnvironmentTryMap), 0 };

// R6Engine.dll data @ 1005c9ec : rainbowGuardUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowGuardUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c9fc : rainbowGuardCatchMap
// Typed pointer catch followed by context catch-all.
const NativeCatchEntry rainbowGuardCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&RainbowGuardCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowGuardCatchContext) }
};

// R6Engine.dll data @ 1005ca1c : rainbowGuardTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowGuardTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowGuardCatchMap) }
};

// R6Engine.dll data @ 1005ca30 : rainbowGuardFuncInfo
// Exact parent-frame metadata.
const NativeFunctionInfoPrefix rainbowGuardFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowGuardUnwindMap), 0x1,
    ((uint)&rainbowGuardTryMap), 0 };

// R6Engine.dll data @ 1005ca4c : rainbowLadderUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowLadderUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ca5c : rainbowLadderCatchMap
// Typed pointer catch followed by context catch-all.
const NativeCatchEntry rainbowLadderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RainbowLadderCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowLadderCatchContext) }
};

// R6Engine.dll data @ 1005ca7c : rainbowLadderTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowLadderTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowLadderCatchMap) }
};

// R6Engine.dll data @ 1005ca90 : rainbowLadderFuncInfo
// Exact parent-frame metadata.
const NativeFunctionInfoPrefix rainbowLadderFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowLadderUnwindMap), 0x1,
    ((uint)&rainbowLadderTryMap), 0 };

// R6Engine.dll data @ 1005c98c : rainbowEntryUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowEntryUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c99c : rainbowEntryCatchMap
// Typed pointer at EBP-3c followed by context catch-all.
const NativeCatchEntry rainbowEntryCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -60, ((uint)&RainbowEntryCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowEntryCatchContext) }
};

// R6Engine.dll data @ 1005c9bc : rainbowEntryTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowEntryTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowEntryCatchMap) }
};

// R6Engine.dll data @ 1005c9d0 : rainbowEntryFuncInfo
// Exact getEntryPosition parent-frame metadata.
const NativeFunctionInfoPrefix rainbowEntryFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowEntryUnwindMap), 0x1,
    ((uint)&rainbowEntryTryMap), 0 };

// R6Engine.dll data @ 1005c92c : rainbowPreEntryUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowPreEntryUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c93c : rainbowPreEntryCatchMap
// Typed pointer at EBP-54 followed by context catch-all.
const NativeCatchEntry rainbowPreEntryCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -84, ((uint)&RainbowPreEntryCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowPreEntryCatchContext) }
};

// R6Engine.dll data @ 1005c95c : rainbowPreEntryTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowPreEntryTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowPreEntryCatchMap) }
};

// R6Engine.dll data @ 1005c970 : rainbowPreEntryFuncInfo
// Exact getPreEntryPosition parent-frame metadata.
const NativeFunctionInfoPrefix rainbowPreEntryFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowPreEntryUnwindMap), 0x1,
    ((uint)&rainbowPreEntryTryMap), 0 };

// R6Engine.dll data @ 1005c8cc : rainbowOrientationUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry rainbowOrientationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c8dc : rainbowOrientationCatchMap
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry rainbowOrientationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RainbowOrientationCatchPointer) },
    { 0, 0, 0, ((uint)&RainbowOrientationCatchContext) }
};

// R6Engine.dll data @ 1005c8fc : rainbowOrientationTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock rainbowOrientationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rainbowOrientationCatchMap) }
};

// R6Engine.dll data @ 1005c910 : rainbowOrientationFuncInfo
// Exact setMemberOrientation parent-frame metadata.
const NativeFunctionInfoPrefix rainbowOrientationFuncInfo = { 0x19930520, 0x2, ((uint)&rainbowOrientationUnwindMap),
    0x1, ((uint)&rainbowOrientationTryMap), 0 };

// R6Engine.dll data @ 100744e0 : intAR6RainbowAIexecClearToSnipe
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecClearToSnipe = (Native)&AR6RainbowAI::execClearToSnipe;

// R6Engine.dll data @ 1007df20 : AR6RainbowAIClearToSnipeRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIClearToSnipeRegistrationResult = 0;

// R6Engine.dll data @ 100744e4 : intAR6RainbowAIexecAClearShotIsAvailable
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecAClearShotIsAvailable = (Native)&AR6RainbowAI::execAClearShotIsAvailable;

// R6Engine.dll data @ 1007a6d8 : AR6RainbowAIAClearShotIsAvailableRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIAClearShotIsAvailableRegistrationResult = 0;

// R6Engine.dll data @ 100744e8 : intAR6RainbowAIexecFindSafeSpot
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecFindSafeSpot = (Native)&AR6RainbowAI::execFindSafeSpot;

// R6Engine.dll data @ 10082699 : AR6RainbowAIFindSafeSpotRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIFindSafeSpotRegistrationResult = 0;

// R6Engine.dll data @ 100744ec : intAR6RainbowAIexecLookAroundRoom
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecLookAroundRoom = (Native)&AR6RainbowAI::execLookAroundRoom;

// R6Engine.dll data @ 100802ee : AR6RainbowAILookAroundRoomRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAILookAroundRoomRegistrationResult = 0;

// R6Engine.dll data @ 100744f0 : intAR6RainbowAIexecSetOrientation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecSetOrientation = (Native)&AR6RainbowAI::execSetOrientation;

// R6Engine.dll data @ 1007d4d4 : AR6RainbowAISetOrientationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAISetOrientationRegistrationResult = 0;

// R6Engine.dll data @ 100744f4 : intAR6RainbowAIexecCheckEnvironment
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecCheckEnvironment = (Native)&AR6RainbowAI::execCheckEnvironment;

// R6Engine.dll data @ 1007d9ec : AR6RainbowAICheckEnvironmentRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAICheckEnvironmentRegistrationResult = 0;

// R6Engine.dll data @ 100744f8 : intAR6RainbowAIexecGetEntryPosition
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecGetEntryPosition = (Native)&AR6RainbowAI::execGetEntryPosition;

// R6Engine.dll data @ 10077e03 : AR6RainbowAIGetEntryPositionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIGetEntryPositionRegistrationResult = 0;

// R6Engine.dll data @ 100744fc : intAR6RainbowAIexecGetGuardPosition
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecGetGuardPosition = (Native)&AR6RainbowAI::execGetGuardPosition;

// R6Engine.dll data @ 1007d4c4 : AR6RainbowAIGetGuardPositionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIGetGuardPositionRegistrationResult = 0;

// R6Engine.dll data @ 10074500 : intAR6RainbowAIexecGetLadderPosition
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecGetLadderPosition = (Native)&AR6RainbowAI::execGetLadderPosition;

// R6Engine.dll data @ 10077e02 : AR6RainbowAIGetLadderPositionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIGetLadderPositionRegistrationResult = 0;

// R6Engine.dll data @ 10074504 : intAR6RainbowAIexecGetTargetPosition
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6RainbowAIexecGetTargetPosition = (Native)&AR6RainbowAI::execGetTargetPosition;

// R6Engine.dll data @ 10080d19 : AR6RainbowAIGetTargetPositionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6RainbowAIGetTargetPositionRegistrationResult = 0;

// R6Engine.dll data @ 1007d4dc : autoclassAR6RainbowAI
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6RainbowAI = nullptr;

// R6Engine.dll @ 10008430 : AR6RainbowAI::eventStopAttack
// Dispatches the no-parameter event through the captured vtable's current ProcessEvent slot.
void __thiscall AR6RainbowAI::eventStopAttack(void)
{
    uint name = reinterpret_cast<uint&>(R6ENGINE_StopAttack);
    // Captured before lookup; lookup may replace the object vtable or this table's slot.
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Event = void (__thiscall*)(AR6RainbowAI*, UFunction*, void*, void*);
    reinterpret_cast<Event&>(table->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10008460 : AR6RainbowAI::eventAttackTimer
// Dispatches the no-parameter event through the captured vtable's current ProcessEvent slot.
void __thiscall AR6RainbowAI::eventAttackTimer(void)
{
    uint name = reinterpret_cast<uint&>(R6ENGINE_AttackTimer);
    // Captured before lookup; lookup may replace the object vtable or this table's slot.
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Event = void (__thiscall*)(AR6RainbowAI*, UFunction*, void*, void*);
    reinterpret_cast<Event&>(table->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10008490 : AR6RainbowAI::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6RainbowAI::StaticClass(void)
{
    return &AR6RainbowAI::PrivateStaticClass; // Selected object at0x100778f0.
}

// R6Engine.dll @ 100084a0 : AR6RainbowAI::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6RainbowAI::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    uint flagsWord = reinterpret_cast<uint&>(objectFlags);
    FName capturedName = objectName;
    struct AllocatePacketView { // Inferred eight-word outgoing packet at entryESP-0x20.
        UClass* classObject;
        UObject* outer;
        FName objectName;
        uint objectFlags;
        UObject* templateObject;
        FOutputDevice* error;
        UObject* extraObject;
        int finalZero;
    } packet;
    packet.finalZero = 0;
    packet.extraObject = nullptr;
    packet.error = (FOutputDevice*)error;
    UObject* capturedOuter = outer; // Read after the first three outgoing words have been placed.
    packet.templateObject = nullptr;
    packet.objectFlags = flagsWord;
    packet.objectName = capturedName;
    packet.outer = capturedOuter;
    packet.classObject = &AR6RainbowAI::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 100084d0 : AR6RainbowAI::~AR6RainbowAI
// Installs the derived vtable, conditionally destroys UObject state, then destroys the AI-controller base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6RainbowAI::~AR6RainbowAI(AR6RainbowAI* this)
{
    uint guard[4]; // Native stack view: saved this/previous SEH/handler/state at dispatcher EBP-10..EBP-4.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&AiControllerBaseExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6RainbowAIVirtualTable);
    guard[3] = 0; // Exact shared FuncInfo invokes AiControllerBaseState0Cleanup if ConditionalDestroy unwinds.
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff; // Base failure does not run this same base cleanup again.
    this->AR6AIController::~AR6AIController();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10008520 : AR6RainbowAI::AR6RainbowAI (native default-constructor view)
// Constructs the imported AI base, installs the derived vtable and default-constructs the two pre-entry vectors.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6RainbowAI* __thiscall AR6RainbowAI::AR6RainbowAI(AR6RainbowAI* this)
{
    uint guard[4]; // Same native compiler stack view as the destructor, not additional class storage.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&AiControllerBaseExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    using BaseConstructor = AAIController* (__thiscall*)(AAIController*);
    // Actual native target is the imported AAIController constructor.
    reinterpret_cast<BaseConstructor&>(AAIControllerDefaultConstructorImport)(this);
    guard[3] = 0; // Later failure unwinds through AR6AIController::~AR6AIController, as the native map specifies.
    *(uint*)this = ((uint)&AR6RainbowAIVirtualTable);
    byte* vector = (byte*)this + 0x5f4;
    for (int remaining = 2; remaining != 0; vector += 12, --remaining)
        // Retail Core default constructor writes no vector words.
        ::new (reinterpret_cast<void*>(vector)) FVector;
    ExceptionList = (void*)guard[1];
    return this; // Native EAX is this; state0 remains active until the registration is removed normally.
}

// R6Engine.dll @ 10008590 : AR6RainbowAI::AR6RainbowAI (native copy-constructor view)
// Copies base/derived storage and publishes the thirteen source Bool bits individually, retaining higher destination
// bits.
AR6RainbowAI::AR6RainbowAI(const AR6RainbowAI& sourceObject) : AR6AIController(sourceObject)
{
    // Publishes AR6RainbowAIVirtualTable after base copy; native EAX retains original storage.
    const AR6RainbowAI* source = &sourceObject;
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0x56c; offset < 0x570; ++offset) destination[offset] = input[offset];
    *(uint*)(destination + 0x570) = *(const uint*)(input + 0x570);
    *(uint*)(destination + 0x574) = *(const uint*)(input + 0x574);
    uint word = *(const uint*)(input + 0x578);
    uint firstFlags = *(uint*)(destination + 0x580); // Native early read precedes the final two scalar stores.
    *(uint*)(destination + 0x578) = word;
    *(uint*)(destination + 0x57c) = *(const uint*)(input + 0x57c);
    uint difference = firstFlags ^ *(const uint*)(input + 0x580);
    uint flags = *(uint*)(destination + 0x580) ^ (difference & 1U);
    *(uint*)(destination + 0x580) = flags;
    for (uint mask = 2; mask <= 0x1000; mask <<= 1) {
        flags ^= (*(const uint*)(input + 0x580) ^ flags) & mask;
        // Each source read and each publication is retained, including self/overlap.
        *(uint*)(destination + 0x580) = flags;
    }
    for (uint offset = 0x584; offset < 0x60c; offset += 4)
        // Scalar/pointer/vector words, read then write.
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
}

// R6Engine.dll @ 10008880 : AR6RainbowAI::operator=
// Assigns the base and derived words with thirteen sequential Bool-bit merges; the destination vtable is retained.
AR6RainbowAI& __thiscall AR6RainbowAI::operator=(const AR6RainbowAI& sourceObject)
{
    const AR6RainbowAI* source = &sourceObject;
    this->AR6AIController::operator=(*source);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0x56c; offset < 0x570; ++offset) destination[offset] = input[offset];
    reinterpret_cast<uint&>(this->m_iStateProgress) = *(const uint*)(input + 0x570);
    reinterpret_cast<uint&>(this->m_iTurn) = *(const uint*)(input + 0x574);
    uint word = *(const uint*)(input + 0x578);
    uint firstFlags = *(uint*)(destination + 0x580);
    reinterpret_cast<uint&>(this->m_iWaitCounter) = word;
    reinterpret_cast<uint&>(this->m_iActionUseGadgetGroup) = *(const uint*)(input + 0x57c);
    uint difference = firstFlags ^ *(const uint*)(input + 0x580);
    uint flags = *(uint*)(destination + 0x580) ^ (difference & 1U);
    *(uint*)(destination + 0x580) = flags;
    for (uint mask = 2; mask <= 0x1000; mask <<= 1) {
        flags ^= (*(const uint*)(input + 0x580) ^ flags) & mask;
        *(uint*)(destination + 0x580) = flags;
    }
    for (uint offset = 0x584; offset < 0x60c; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    return *this; // No self-assignment shortcut or deep ownership operation is added.
}

// R6Engine.dll @ 10008b70 : AR6RainbowAI::DeletingDestructor
// Destroys a scalar or cookie-counted array and conditionally releases its allocation using the native low-byte flags.
void* __thiscall AR6RainbowAI::DeletingDestructor(uint flags)
{
    byte deleteFlags = (byte)flags;
    if ((deleteFlags & 2) != 0) {
        byte* cookie = (byte*)this - 4;
        uint count = *(uint*)cookie;
        using DestroyArray = void (__stdcall*)(void*, uint, uint, void (__thiscall*)(AR6RainbowAI*));
        (*(DestroyArray)((uint)&_eh_vector_destructor_iterator_))(this, 0x60c, count,
            (void (__thiscall*)(AR6RainbowAI*))((uint)&AR6RainbowAIDestructorNativeEntry));
        if ((deleteFlags & 1) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    this->AR6RainbowAI::~AR6RainbowAI();
    if ((deleteFlags & 1) != 0) {
        UObject::operator delete(this, 0x60c);
    }
    return this;
}

// R6Engine.dll @ 1000df00 : AR6RainbowAI::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6RainbowAI::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6RainbowAIConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10035b50 : AR6RainbowAI::resetBoneRotation
// Resets three named bone rotations on the captured mesh instance with native weights and blend time.
void __thiscall AR6RainbowAI::resetBoneRotation(void)
{
    APawn* pawn = this->Pawn;
    UMesh* mesh = pawn->Mesh;
    USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(pawn));
    const ushort* const names[3] = {
        (const ushort*)L"R6 Spine", (const ushort*)L"R6 Spine1", (const ushort*)L"R6 Neck"
    };
    struct RotationPacket { uint name; FRotator rotation; int space; float weight, blend; };
    RotationPacket packet; // Descriptive view of contiguous native outgoing stack words; not a new native type.
    for (int i = 0; i < 3; ++i) {
        packet.blend = 0.5f;
        packet.weight = 1.0f;
        packet.space = 0;
        packet.rotation.Pitch = 0;
        packet.rotation.Yaw = 0;
        packet.rotation.Roll = 0;
        // Returned pointer ignored.
        ::new (reinterpret_cast<void*>(&packet.name)) FName(names[i], static_cast<EFindName>(1));
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(packet.name),
            packet.rotation, packet.space, packet.weight, packet.blend);
    }
}

// R6Engine.dll @ 10035c10 : AR6RainbowAI::updatePawnOrientation
// Chooses the orientation from formation, member ID, last-member status and stair flags.
ePawnOrientation __thiscall AR6RainbowAI::updatePawnOrientation(void)
{
    byte* controller = (byte*)this;
    byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
    uint memberID = *(uint*)(pawn + 0x68c); // m_iID is loaded before the prone gate.
    if ((*(uint*)(pawn + 0x3e0) & 0x200) != 0)
        return (ePawnOrientation)0;
    byte formation = reinterpret_cast<byte&>(this->m_eFormation); // m_eFormation.
    if (formation != 0 && memberID != 0) {
        uint memberCount = *(uint*)(reinterpret_cast<byte*&>(this->m_TeamManager) + 0x3a4);
        if (memberID == memberCount - 1U) // Native decrement wraps, including INT_MIN.
            return (ePawnOrientation)5;
    }
    switch (formation) {
    case 1:
        if (memberID == 1 || memberID == 2) {
            pawn = reinterpret_cast<byte*&>(this->Pawn);
            if ((pawn[0x6c4] & 1) != 0)
                return (ePawnOrientation)0;
            return (ePawnOrientation)(memberID == 1 ? 6 : 7);
        }
        break;
    case 2:
        if (memberID == 1) return (ePawnOrientation)4;
        if (memberID == 2) return (ePawnOrientation)3;
        break;
    case 3:
        if (memberID == 1) return (ePawnOrientation)1;
        if (memberID == 2) return (ePawnOrientation)2;
        break;
    case 4:
        if (memberID == 1) return (ePawnOrientation)4;
        if (memberID == 2) return (ePawnOrientation)1;
        break;
    case 5:
        if (memberID == 1) return (ePawnOrientation)7;
        if (memberID == 2) return (ePawnOrientation)6;
        return (ePawnOrientation)0;
    default:
        return (ePawnOrientation)0;
    }
    return (ePawnOrientation)(memberID == 3 ? 5 : 0); // Applies only to formations1..4.
}

// R6Engine.dll @ 10035d10 : AR6RainbowAI::LookAroundRoom
// Selects one of two room-cover yaw offsets, unless an enemy already holds the controller's attention.
void __thiscall AR6RainbowAI::LookAroundRoom(int isLeadingRoomEntry)
{
    byte* controller = (byte*)this;
    if (reinterpret_cast<uint&>(this->Enemy) != 0) // Enemy.
        return;
    int firstYaw = 0, secondYaw = 0;
    if (isLeadingRoomEntry != 0) {
        uint memberCount = *(uint*)(reinterpret_cast<byte*&>(this->m_TeamManager) + 0x3a4); // Read before Pawn.m_iID.
        uint memberID = *(uint*)(reinterpret_cast<byte*&>(this->Pawn) + 0x68c);
        byte roomLayout = reinterpret_cast<byte&>(this->m_eCurrentRoomLayout);
        if (memberID == memberCount - 1U) {
            switch (roomLayout) {
            case 0: firstYaw = 0x1555; secondYaw = -0x1555; break;
            case 1: firstYaw = -0x2000; secondYaw = 0xe38; break;
            case 2: firstYaw = 0x2000; secondYaw = -0xe38; break;
            case 3: firstYaw = 0xe38; secondYaw = -0xe38; break;
            }
        } else {
            switch (roomLayout) {
            case 0: case 2: firstYaw = 0xe38; secondYaw = -0x1555; break;
            case 1: firstYaw = -0xe38; secondYaw = 0x1555; break;
            case 3: firstYaw = 0xe38; secondYaw = -0xe38; break;
            }
        }
    } else {
        byte roomLayout = reinterpret_cast<byte&>(this->m_eCurrentRoomLayout);
        if (roomLayout == 0) {
            // m_eCoverDirection; other values, including out-of-range, take this path.
            if (reinterpret_cast<byte&>(this->m_eCoverDirection) != 3) {
                firstYaw = -0x1555;
                secondYaw = 0x1555;
            }
        } else if (roomLayout <= 2) {
            switch (reinterpret_cast<byte&>(this->m_eCoverDirection)) {
            case 0: firstYaw = 0x1555; secondYaw = -0xe38; break;
            case 1: firstYaw = -0x1555; secondYaw = 0x1555; break;
            case 2: firstYaw = -0x1555; secondYaw = 0xe38; break;
            }
        }
    }
    uint turn = reinterpret_cast<uint&>(this->m_iTurn); // m_iTurn: only the exact words0 and1 select offsets.
    byte desiredYaw = turn == 0 ? (byte)(firstYaw >> 8) : turn == 1 ? (byte)(secondYaw >> 8) : 0;
    (reinterpret_cast<byte*&>(this->Pawn))[0xa2a] = desiredYaw; // Pawn.m_u8DesiredYaw; no controller byte is changed.
}

// R6Engine.dll @ 10035e80 : AR6RainbowAI::GetTeamManager
// Returns m_TeamManager as the exported actor-pointer result, including null.
AActor* __thiscall AR6RainbowAI::GetTeamManager(void)
{
    return reinterpret_cast<AActor*&>(this->m_TeamManager);
}

// R6Engine.dll @ 10035e90 : AR6RainbowAI::setMemberOrientation
// Handles peeking requests or derives desired pitch/yaw bytes from movement, stairs and turn state.
void __thiscall AR6RainbowAI::setMemberOrientation(EPawnOrientation orientation)
{
    uint pawnFlags = *(uint*)(reinterpret_cast<byte*&>(this->Pawn) + 0x3e0); // Read before native catch state0.
    try {
        int yaw = 0, pitch = 0;
        if ((pawnFlags & 0x200) != 0) // Pawn.m_bIsProne.
            return;
        const uint requested = (uint)orientation; // Native EBX snapshot; full word retained after low-byte comparison.
        if (reinterpret_cast<byte&>(this->m_ePawnOrientation) == (byte)requested)
            reinterpret_cast<byte&>(this->m_ePawnOrientation) = (byte)this->AR6RainbowAI::updatePawnOrientation();
        APawn* pawn = this->Pawn;
        UMesh* mesh = pawn->Mesh;
        if (mesh == nullptr)
            return;
        UClass* meshClass = mesh->Class;
        UClass* skeletalMeshClass = USkeletalMeshPrivateStaticClassImport;
        while (meshClass != nullptr && meshClass != skeletalMeshClass)
            meshClass = meshClass->GetSuperClass();
        if (meshClass == nullptr && skeletalMeshClass != nullptr)
            return;
        pawn = this->Pawn;
        mesh = pawn->Mesh;
        mesh->MeshGetInstance(pawn); // Instance result ignored.
        if (requested == 7 || requested == 6) {
            this->AR6RainbowAI::resetBoneRotation();
            this->m_pawn->AR6Pawn::eventSetPeekingInfo(1, requested == 7 ? 2000.0f : 0.0f,
                requested == 6 ? 1 : 0);
            return;
        }
        AR6Rainbow* rainbow = this->m_pawn;
        if (reinterpret_cast<byte&>(rainbow->m_ePeekingMode) != 0)
            rainbow->AR6Pawn::eventSetPeekingInfo(0, 1000.0f, 0);
        rainbow = this->m_pawn;
        float10 ratio = rainbow->AR6Pawn::GetPeekingRatioNorm(rainbow->m_fPeeking);
        // Native incoming-slot spill does not replace the extended comparison.
        reinterpret_cast<float&>(orientation) = (float)ratio;
        if (ratio > (float10)nativeFloatZero)
            return; // Less, equal and unordered continue.
        switch (requested) {
        case 1: case 7: yaw = 0x1555; break;
        case 2: yaw = 0x2aab; break;
        case 3: yaw = -0x2aab; break;
        case 4: case 6: yaw = -0x1555; break;
        }
        pawn = this->Pawn;
        uint stairFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x6c4);
        if ((stairFlags & 1) != 0) { // m_bIsClimbingStairs; bit2 is m_bIsMovingUpStairs.
            if ((stairFlags & 2) != 0)
                pitch = requested == 5 ? -0xe38 : 0xe38;
            else
                pitch = requested == 5 ? 0xe38 : -0xe38;
        } else {
            // Captured Core FVector0 provider, not literal zeros.
            const float* zero = *(const float**)&FVectorFVector0Import;
            bool stationary = zero[0] == pawn->Velocity.X
                && zero[1] == pawn->Velocity.Y && zero[2] == pawn->Velocity.Z;
            if (stationary) {
                int turn;
                if (*reinterpret_cast<int*>(reinterpret_cast<byte*>(pawn) + 0x68c) == 1 && requested != 5) { // m_iID.
                    turn = this->m_iTurn; // m_iTurn; signed thresholds differ by ID/request.
                    if (turn < 2) yaw += 0xe38;
                    else if (turn > 4) yaw -= 0xe38;
                } else {
                    turn = this->m_iTurn;
                    if (turn < 1) yaw += 0xe38;
                    else if (turn > 3) yaw -= 0xe38;
                }
            } else {
                uint turn = reinterpret_cast<uint&>(this->m_iTurn);
                yaw += (turn & 1) == 0 ? 0xe38 : -0xe38; // Native signed remainder sequence has this parity.
            }
        }
        reinterpret_cast<byte*>(pawn)[0xa28] = (byte)(pitch >> 8); // m_u8DesiredPitch on the captured current Pawn.
        (reinterpret_cast<byte*&>(this->Pawn))[0xa2a] = (byte)(yaw >> 8); // Reload Pawn before m_u8DesiredYaw.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::setMemberOrientation");
        throw;
    }
}

// R6Engine.dll @ 100360e4 : RainbowOrientationCatchPointer
// Throws the inherited EBP-18 pointer through EBP-14 without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowOrientationCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100360f8 : RainbowOrientationCatchContext
// Reports setMemberOrientation context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowOrientationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAISetMemberOrientation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10036130 : AR6RainbowAI::GetTeamRightOfDoorPosition
// Computes a right-side door slot and, for slots2/3, updates both pre-entry approach points.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::GetTeamRightOfDoorPosition(FVector* result, int slot, AR6Door* door)
{
    byte* controller = (byte*)this;
    const uint* pawnLocation = (const uint*)(reinterpret_cast<byte*&>(this->Pawn) + 0x234);
    uint position[3]; // Raw fallback snapshot, including NaN payloads and signed zero.
    position[0] = pawnLocation[0];
    position[1] = pawnLocation[1];
    position[2] = pawnLocation[2];
    byte* doorBytes = (byte*)door;
    FRotator* doorRotation = (FRotator*)(doorBytes + 0x240);
    FRotator sideRotation;
    sideRotation.Yaw = (int)(*(uint*)(doorBytes + 0x244) + 0x4000U); // Yaw sampled first, even for invalid slots.
    sideRotation.Pitch = *(int*)(doorBytes + 0x240);
    sideRotation.Roll = *(int*)(doorBytes + 0x248);
    FVector vectorResults[14]; // Distinct hidden buffers for all fourteen static Vector call sites.
    auto vectorAt = [&](FRotator* rotation, int index) -> const FVector* {
        return &(vectorResults[index] = rotation->Vector());
    };
    auto forwardOffset = [&](int index, const float* distance, FVector* offset) {
        const FVector* direction = vectorAt(doorRotation, index);
        offset->X = (float)((float10)direction->X * *distance);
        offset->Y = (float)((float10)direction->Y * *distance);
        offset->Z = (float)((float10)direction->Z * *distance);
    };
    // Describes inlined arithmetic; X point and Z product round before subtraction, Y/Z points stay extended.
    auto sidePoint = [&](int index, const float* distance, const FVector* back, uint* destination,
                         bool finishBeforeStores) {
        const FVector* direction = vectorAt(&sideRotation, index);
        float10 xProduct = (float10)direction->X * *distance;
        float10 yProduct = (float10)direction->Y * *distance;
        float zProduct = (float)((float10)direction->Z * *distance);
        float xPoint = (float)(xProduct + *(float*)(doorBytes + 0x234));
        float10 yPoint = yProduct + *(float*)(doorBytes + 0x238);
        float10 zPoint = (float10)zProduct + *(float*)(doorBytes + 0x23c);
        if (finishBeforeStores) { // Slot3's first cache point completes all three subtractions before MOV stores.
            float x = back ? (float)((float10)xPoint - back->X) : xPoint;
            float y = (float)(back ? yPoint - back->Y : yPoint);
            float z = (float)(back ? zPoint - back->Z : zPoint);
            destination[0] = reinterpret_cast<uint&>(x);
            destination[1] = reinterpret_cast<uint&>(y);
            destination[2] = reinterpret_cast<uint&>(z);
        } else {
            float x = back ? (float)((float10)xPoint - back->X) : xPoint;
            destination[0] = reinterpret_cast<uint&>(x);
            float y = (float)(back ? yPoint - back->Y : yPoint);
            destination[1] = reinterpret_cast<uint&>(y);
            float z = (float)(back ? zPoint - back->Z : zPoint);
            destination[2] = reinterpret_cast<uint&>(z);
        }
    };
    const float* side115 = (const float*)&nativeFloat115;
    const float* side108 = (const float*)&nativeFloat108;
    const float* distance100 = (const float*)&nativeFloat1EPlus02;
    const float* distance200 = (const float*)&nativeFloat2EPlus02;
    uint* approach = (uint*)(controller + 0x5f4);
    FVector back;
    switch ((uint)slot) {
    case 0:
        sidePoint(0, side115, nullptr, position, false);
        break;
    case 1:
        forwardOffset(1, distance100, &back);
        sidePoint(2, side108, &back, position, false);
        break;
    case 2:
        sidePoint(3, distance200, nullptr, position, false);
        forwardOffset(4, distance200, &back);
        sidePoint(5, side108, &back, approach, false);
        forwardOffset(6, distance200, &back);
        sidePoint(7, distance200, &back, approach + 3, false);
        break;
    case 3:
        forwardOffset(8, distance100, &back);
        sidePoint(9, distance200, &back, position, false);
        forwardOffset(10, distance200, &back);
        sidePoint(11, side108, &back, approach, true);
        forwardOffset(12, distance200, &back);
        sidePoint(13, distance200, &back, approach + 3, false);
        break;
    }
    uint y = position[1];
    ((uint*)result)[0] = position[0];
    ((uint*)result)[1] = y;
    ((uint*)result)[2] = position[2];
    return result; // Hidden output, full slot and door words; RET0x0c.
}

// R6Engine.dll @ 10036700 : AR6RainbowAI::GetTeamLeftOfDoorPosition
// Computes a left-side door slot and, for slots2/3, updates both pre-entry approach points.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::GetTeamLeftOfDoorPosition(FVector* result, int slot, AR6Door* door)
{
    byte* controller = (byte*)this;
    const uint* pawnLocation = (const uint*)(reinterpret_cast<byte*&>(this->Pawn) + 0x234);
    uint position[3]; // Raw fallback snapshot, including NaN payloads and signed zero.
    position[0] = pawnLocation[0];
    position[1] = pawnLocation[1];
    position[2] = pawnLocation[2];
    byte* doorBytes = (byte*)door;
    FRotator* doorRotation = (FRotator*)(doorBytes + 0x240);
    FRotator sideRotation;
    sideRotation.Yaw = (int)(*(uint*)(doorBytes + 0x244) + 0x4000U); // Yaw sampled first, even for invalid slots.
    sideRotation.Pitch = *(int*)(doorBytes + 0x240);
    sideRotation.Roll = *(int*)(doorBytes + 0x248);
    FVector vectorResults[14]; // Distinct hidden buffers for all fourteen static Vector call sites.
    auto vectorAt = [&](FRotator* rotation, int index) -> const FVector* {
        return &(vectorResults[index] = rotation->Vector());
    };
    auto forwardOffset = [&](int index, const float* distance, FVector* offset) {
        const FVector* direction = vectorAt(doorRotation, index);
        offset->X = (float)((float10)direction->X * *distance);
        offset->Y = (float)((float10)direction->Y * *distance);
        offset->Z = (float)((float10)direction->Z * *distance);
    };
    // Describes inlined arithmetic; X point and Z product round before subtraction, Y/Z points stay extended.
    auto sidePoint = [&](int index, const float* distance, const FVector* back, uint* destination,
                         bool subtractYBeforeXStore) {
        const FVector* direction = vectorAt(&sideRotation, index);
        float10 xProduct = (float10)direction->X * *distance;
        float10 yProduct = (float10)direction->Y * *distance;
        float zProduct = (float)((float10)direction->Z * *distance);
        float xPoint = (float)((float10)*(float*)(doorBytes + 0x234) - xProduct);
        float10 yPoint = (float10)*(float*)(doorBytes + 0x238) - yProduct;
        float10 zPoint = (float10)*(float*)(doorBytes + 0x23c) - zProduct;
        float x = back ? (float)((float10)xPoint - back->X) : xPoint;
        if (subtractYBeforeXStore) // Slot3 cache0 subtracts Y before the X store, then subtracts Z after Y's store.
            yPoint = back ? yPoint - back->Y : yPoint;
        destination[0] = reinterpret_cast<uint&>(x);
        float y = (float)(back && !subtractYBeforeXStore ? yPoint - back->Y : yPoint);
        destination[1] = reinterpret_cast<uint&>(y);
        float z = (float)(back ? zPoint - back->Z : zPoint);
        destination[2] = reinterpret_cast<uint&>(z);
    };
    const float* side115 = (const float*)&nativeFloat115;
    const float* side108 = (const float*)&nativeFloat108;
    const float* distance100 = (const float*)&nativeFloat1EPlus02;
    const float* distance200 = (const float*)&nativeFloat2EPlus02;
    uint* approach = (uint*)(controller + 0x5f4);
    FVector back;
    switch ((uint)slot) {
    case 0:
        sidePoint(0, side115, nullptr, position, false);
        break;
    case 1:
        forwardOffset(1, distance100, &back);
        sidePoint(2, side108, &back, position, false);
        break;
    case 2:
        sidePoint(3, distance200, nullptr, position, false);
        forwardOffset(4, distance200, &back);
        sidePoint(5, side108, &back, approach, false);
        forwardOffset(6, distance200, &back);
        sidePoint(7, distance200, &back, approach + 3, false);
        break;
    case 3:
        forwardOffset(8, distance100, &back);
        sidePoint(9, distance200, &back, position, false);
        forwardOffset(10, distance200, &back);
        sidePoint(11, side108, &back, approach, true);
        forwardOffset(12, distance200, &back);
        sidePoint(13, distance200, &back, approach + 3, false);
        break;
    }
    uint y = position[1];
    ((uint*)result)[0] = position[0];
    ((uint*)result)[1] = y;
    ((uint*)result)[2] = position[2];
    return result; // Hidden output, full slot and door words; RET0x0c.
}

// R6Engine.dll @ 10036d00 : AR6RainbowAI::getPreEntryPosition
// Selects a pre-entry door slot and updates the applicable approach caches using current team/door providers.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::getPreEntryPosition(FVector* result)
{
    byte* controller = (byte*)this;
    byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
    uint slot = *(uint*)(pawn + 0x68c);
    uint position[3] = {*(uint*)(pawn + 0x234), *(uint*)(pawn + 0x238), *(uint*)(pawn + 0x23c)};
    try { // Native arms state0 after the initial member-ID and raw Location reads.
        byte* team = reinterpret_cast<byte*&>(this->m_TeamManager);
        bool separated = (*(uint*)(team + 0x3e8) & 0x10) != 0;
        if (separated) --slot;
        bool nearSecond = (team[0x3e8] & 1) == 0 || separated;
        byte* door = *(byte**)(team + 0x430);
        auto copyRawResult = [&](const uint* words) -> FVector* {
            uint x = words[0];
            ((uint*)result)[0] = x;
            ((uint*)result)[1] = words[1];
            ((uint*)result)[2] = words[2];
            return result;
        };
        if (door == nullptr)
            return copyRawResult(*(const uint**)&FVectorFVector0Import);
        byte layout = (*(byte**)(door + 0x3f0))[0x3e8];
        if (layout == 3 && slot == 0)
            return copyRawResult((const uint*)(door + 0x234));
        uint openingFlags = *(uint*)(team + 0x3e8);
        bool towardTeam = (openingFlags & 0x100) != 0;
        bool clockwise = (openingFlags & 0x200) != 0;
        // These vector slots reproduce the native shared-buffer identities; offsets name inherited EBP locations.
        FVector buffers[25]; // Native EBP-180 through EBP-60, twelve-byte stride.
        FVector smallResult; // Separate EBP-50 side-helper/scale result.
        auto bufferAt = [&](int offset) -> FVector* {
            return offset == 0x50 ? &smallResult : &buffers[(0x180 - offset) / 12];
        };
        auto sideHelper = [&](bool right, int outputOffset, int readOrder) {
            FVector* output = bufferAt(outputOffset);
            FVector* returned = right ? this->AR6RainbowAI::GetTeamRightOfDoorPosition(output, (int)slot,
                reinterpret_cast<AR6Door*>(door))
                : this->AR6RainbowAI::GetTeamLeftOfDoorPosition(output, (int)slot, reinterpret_cast<AR6Door*>(door));
            const uint* words = (const uint*)returned;
            if (readOrder == 0) {
                position[2] = words[2]; position[0] = words[0]; position[1] = words[1];
            } else {
                position[1] = words[1]; position[0] = words[0]; position[2] = words[2];
            }
        };
        if (towardTeam) {
            if (clockwise) {
                if (layout <= 1) { door = *(byte**)(team + 0x430); sideHelper(true, 0x50, 1); }
            } else if (layout == 0 || layout == 2) {
                door = *(byte**)(team + 0x430);
                sideHelper(false, 0x50, 1);
            }
        } else if (layout == 1 || layout == 2) {
            door = *(byte**)(team + 0x430);
            sideHelper(layout == 1, clockwise ? (layout == 1 ? 0x180 : 0x174) : (layout == 1 ? 0x168 : 0x50),
                clockwise ? 0 : 1);
        } else if (layout == 0) {
            FRotator sideRotation;
            if (clockwise || slot <= 3) {
                door = *(byte**)(team + 0x430);
                if (clockwise || slot == 2) { // Native roll/yaw sampling precedes pitch on these paths.
                    sideRotation.Roll = *(int*)(door + 0x248);
                    sideRotation.Yaw = (int)(*(uint*)(door + 0x244) + 0x4000U);
                } else {
                    sideRotation.Yaw = (int)(*(uint*)(door + 0x244) + 0x4000U);
                    sideRotation.Roll = *(int*)(door + 0x248);
                }
                sideRotation.Pitch = *(int*)(door + 0x240);
            }
            auto currentDoor = [&]() -> byte* {
                return *(byte**)(reinterpret_cast<byte*&>(this->m_TeamManager) + 0x430);
            };
            auto scaledDirection = [&](FRotator* rotation, float distance, int vectorOffset, int scaleOffset) {
                const FVector* vector = &(*bufferAt(vectorOffset) = rotation->Vector());
                return ScaleVectorToResult(bufferAt(scaleOffset), distance, vector);
            };
            // Computes the inlined point arithmetic and returns the same current door used for a following forward
            // call.
            auto sidePoint = [&](const FVector* offset, bool add, uint offsetFirst, bool reverse, uint* point) {
                bool preloadZ = add && (offsetFirst & 4) != 0 && reverse;
                float zOffset = preloadZ ? offset->Z : 0.0f; // Native samples this word before its team/door reload.
                door = currentDoor();
                auto component = [&](int axis) -> float {
                    const float* value = (const float*)offset + axis;
                    const float* location = (const float*)(door + 0x234) + axis;
                    if (!add) return (float)((float10)*location - *value);
                    if ((offsetFirst & (1U << axis)) != 0)
                        return (float)((float10)(axis == 2 && preloadZ ? zOffset : *value) + *location);
                    return (float)((float10)*location + *value);
                };
                float x, y, z;
                if (reverse) { z = component(2); y = component(1); x = component(0); }
                else { x = component(0); y = component(1); z = component(2); }
                point[0] = reinterpret_cast<uint&>(x); point[1] = reinterpret_cast<uint&>(y); point[2] =
                    reinterpret_cast<uint&>(z);
            };
            // Schedules the native 32f spills relative to cache stores; schedule0 is a local, fully completed snapshot.
            auto behind = [&](const uint* point, const FVector* offset, uint* destination, bool reverse, int schedule) {
                float10 x, y, z;
                if (reverse) {
                    z = (float10)*(const float*)(point + 2) - offset->Z;
                    y = (float10)*(const float*)(point + 1) - offset->Y;
                    x = (float10)*(const float*)point - offset->X;
                } else {
                    x = (float10)*(const float*)point - offset->X;
                    y = (float10)*(const float*)(point + 1) - offset->Y;
                    z = (float10)*(const float*)(point + 2) - offset->Z;
                }
                float roundedX = (float)x;
                if (schedule == 1) {
                    destination[0] = reinterpret_cast<uint&>(roundedX);
                    float roundedY = (float)y; destination[1] = reinterpret_cast<uint&>(roundedY);
                    float roundedZ = (float)z; destination[2] = reinterpret_cast<uint&>(roundedZ);
                } else if (schedule == 2 && reverse) {
                    destination[0] = reinterpret_cast<uint&>(roundedX);
                    float roundedY = (float)y;
                    float roundedZ = (float)z;
                    destination[1] = reinterpret_cast<uint&>(roundedY);
                    destination[2] = reinterpret_cast<uint&>(roundedZ);
                } else {
                    float roundedY = (float)y;
                    if (schedule != 0) destination[0] = reinterpret_cast<uint&>(roundedX);
                    if (schedule == 3) destination[1] = reinterpret_cast<uint&>(roundedY);
                    float roundedZ = (float)z;
                    if (schedule == 0) destination[0] = reinterpret_cast<uint&>(roundedX);
                    if (schedule != 3) destination[1] = reinterpret_cast<uint&>(roundedY);
                    destination[2] = reinterpret_cast<uint&>(roundedZ);
                }
            };
            uint approachPoint[3];
            uint* approach = (uint*)(controller + 0x5f4);
            const FVector* offset;
            switch (slot) {
            case 0:
                offset = scaledDirection(&sideRotation, 108.0f, clockwise ? 0xfc : 0x150,
                    clockwise ? 0x84 : 0x138);
                sidePoint(offset, clockwise, 0, false, position);
                break;
            case 1:
                offset = scaledDirection(&sideRotation, nearSecond ? 108.0f : 200.0f,
                    clockwise ? (nearSecond ? 0x144 : 0x114) : (nearSecond ? 0x120 : 0xf0),
                    clockwise ? (nearSecond ? 0x9c : 0xb4) : (nearSecond ? 0x108 : 0xd8));
                sidePoint(offset, !clockwise, nearSecond ? 1 : 7, true, position);
                offset = scaledDirection((FRotator*)(door + 0x240), 115.0f,
                    clockwise ? 0x60 : 0xc0, clockwise ? 0xcc : 0xa8);
                behind(position, offset, approach, false, 3);
                break;
            case 2:
                offset = scaledDirection(&sideRotation, 200.0f, clockwise ? 0x12c : 0x90,
                    clockwise ? 0xe4 : 0x78);
                sidePoint(offset, clockwise, 6, true, position);
                offset = scaledDirection(&sideRotation, 108.0f, clockwise ? 0x15c : 0x6c,
                    clockwise ? 0x6c : 0x15c);
                sidePoint(offset, clockwise, 6, true, approachPoint);
                offset = scaledDirection((FRotator*)(door + 0x240), 115.0f,
                    clockwise ? 0x78 : 0xe4, clockwise ? 0x90 : 0x12c);
                behind(approachPoint, offset, approach, true, clockwise ? 1 : 2);
                door = currentDoor();
                offset = scaledDirection((FRotator*)(door + 0x240), 100.0f,
                    clockwise ? 0xa8 : 0xcc, clockwise ? 0xc0 : 0x60);
                behind(position, offset, approach + 3, false, 2);
                break;
            case 3:
                offset = scaledDirection(&sideRotation, 200.0f, clockwise ? 0xd8 : 0xb4,
                    clockwise ? 0xf0 : 0x114);
                sidePoint(offset, clockwise, 6, true, approachPoint);
                offset = scaledDirection((FRotator*)(door + 0x240), 100.0f,
                    clockwise ? 0x108 : 0x9c, clockwise ? 0x120 : 0x144);
                behind(approachPoint, offset, position, true, 0);
                offset = scaledDirection(&sideRotation, 108.0f, clockwise ? 0x138 : 0x84,
                    clockwise ? 0x150 : 0xfc);
                sidePoint(offset, clockwise, 7, true, approachPoint);
                offset = scaledDirection((FRotator*)(door + 0x240), 115.0f,
                    clockwise ? 0x168 : 0x180, clockwise ? 0x50 : 0x174);
                behind(approachPoint, offset, approach, false, 2);
                break;
            }
        }
        uint z = position[2];
        ((uint*)result)[0] = position[0];
        ((uint*)result)[1] = position[1];
        ((uint*)result)[2] = z;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::getPreEntryPosition");
        throw;
    }
}

// R6Engine.dll @ 100377e5 : RainbowPreEntryCatchPointer
// Throws the inherited EBP-54 pointer through EBP-44 without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowPreEntryCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x54]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x44]
        push ecx
        mov dword ptr [ebp-0x44],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100377f9 : RainbowPreEntryCatchContext
// Reports getPreEntryPosition context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowPreEntryCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIGetPreEntryPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10037840 : AR6RainbowAI::getEntryPosition
// Chooses an entry slot, derives its position from the current corresponding door, and sets cover/focal state.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::getEntryPosition(FVector* result)
{
    byte* controller = (byte*)this;
    byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
    uint slot = *(uint*)(pawn + 0x68c); // Native loads member ID before catch state0.
    try {
        const uint* pawnLocation = (const uint*)(pawn + 0x234);
        uint position[3] = {pawnLocation[0], pawnLocation[1], pawnLocation[2]};
        byte* team = reinterpret_cast<byte*&>(this->m_TeamManager);
        byte* door = *(byte**)(team + 0x430);
        // Native rereads the raw source and interleaves loads/stores, rather than using the snapshot.
        if (door == nullptr) {
            uint x = pawnLocation[0];
            ((uint*)result)[0] = x;
            ((uint*)result)[1] = pawnLocation[1];
            ((uint*)result)[2] = pawnLocation[2];
            return result;
        }
        team = reinterpret_cast<byte*&>(this->m_TeamManager);
        uint flags = *(uint*)(team + 0x3e8);
        if ((flags & 0x10) != 0) { // m_bTeamIsSeparatedFromLeader.
            --slot;
            if (slot == 2) slot = 3;
        } else {
            bool playerTakesSlot = false;
            if ((flags & 1) != 0) { // m_bLeaderIsAPlayer; initial door layout determines the player's side entry.
                bool layoutOne = door[0x3e8] == 1;
                team = reinterpret_cast<byte*&>(this->m_TeamManager);
                byte playerEntry = team[0x397];
                playerTakesSlot = (playerEntry == 0 && slot == 2)
                    || (playerEntry == (layoutOne ? 2 : 1) && slot == 1);
            }
            if (playerTakesSlot) slot = 0;
            else if (slot == 2) {
                team = reinterpret_cast<byte*&>(this->m_TeamManager);
                if (*(uint*)(team + 0x3a4) == 3) slot = 3;
            }
        }
        team = reinterpret_cast<byte*&>(this->m_TeamManager);
        door = *(byte**)(team + 0x430);
        byte layout = door[0x3e8]; // Captured dispatch layout; later callback changes do not reselect this case.
        if (layout <= 2 && slot <= 3) {
            // Descriptive grouping of the twelve native cases, not a recovered table or additional native structure.
            struct EntryCase {
                int positionYaw, focalYaw;
                float positionDistance, focalDistance;
                int firstVector, firstScale, secondVector, secondScale;
                byte cover, offsetFirst;
                bool coverBeforeFocal;
            };
            const EntryCase cases[3][4] = {
                {{0x2aab,0x2aab,120.0f,120.0f,0x114,0x12c,0x144,0x15c,2,7,true},
                 {-0x2aab,-0x2aab,120.0f,120.0f,0x174,0x18c,0x1a4,0x1bc,0,0,true},
                 {0,0,120.0f,120.0f,0x1d4,0x1ec,0x204,0x21c,1,7,false},
                 {0,0,30.0f,120.0f,0x234,0x24c,0x264,0x27c,3,7,true}},
                {{-0x38e0,-0x38e0,120.0f,100.0f,0x1c8,0x120,0x228,0x138,0,1,true},
                 {0x71c,-0xe38,160.0f,100.0f,0x1e0,0x48,0x258,0x168,2,1,true},
                 {-0x1555,-0x2000,120.0f,100.0f,0x54,0x6c,0x84,0x9c,1,0,true},
                 {0,0,30.0f,100.0f,0xb4,0xcc,0xe4,0xfc,3,7,false}},
                {{0x38e0,0x38e0,120.0f,100.0f,0x150,0x60,0x1f8,0x78,2,0,true},
                 {-0x71c,0xe38,160.0f,100.0f,0x180,0x90,0x240,0xa8,0,0,true},
                 {0x1555,0x2000,120.0f,100.0f,0x198,0xc0,0x210,0xd8,1,1,true},
                 {0,0,30.0f,100.0f,0x1b0,0xf0,0x270,0x108,3,7,false}}
            };
            const EntryCase& selected = cases[layout][slot];
            FVector buffers[48]; // Shared native vector slots EBP-27c through EBP-48, twelve-byte stride.
            FRotator rotation; // Native EBP-28; layout0 and slots0/3 retain it for their second Vector call.
            auto sampleRotation = [&](byte* owner, int yawDelta, int readOrder) {
                if (readOrder == 0) {
                    rotation.Yaw = *(int*)(owner + 0x244);
                    rotation.Roll = *(int*)(owner + 0x248);
                    rotation.Pitch = *(int*)(owner + 0x240);
                } else if (readOrder == 1) {
                    rotation.Roll = *(int*)(owner + 0x248);
                    rotation.Yaw = *(int*)(owner + 0x244);
                    rotation.Pitch = *(int*)(owner + 0x240);
                } else {
                    rotation.Pitch = *(int*)(owner + 0x240);
                    rotation.Yaw = *(int*)(owner + 0x244);
                    rotation.Roll = *(int*)(owner + 0x248);
                }
                rotation.Yaw = (int)((uint)rotation.Yaw + (uint)yawDelta);
            };
            auto scaledDirection = [&](float distance, int vectorOffset, int scaleOffset) {
                const FVector* vector = &(buffers[(0x27c - vectorOffset) / 12] = rotation.Vector());
                return ScaleVectorToResult(&buffers[(0x27c - scaleOffset) / 12], distance, vector);
            };
            sampleRotation(door, selected.positionYaw, slot == 0 ? 0 : slot == 3 ? 2 : 1);
            const FVector* offset = scaledDirection(
                selected.positionDistance, selected.firstVector, selected.firstScale);
            float10 firstZ = (selected.offsetFirst & 4) != 0 ? (float10)offset->Z : (float10)0.0f;
            team = reinterpret_cast<byte*&>(this->m_TeamManager);
            byte* positionDoor = *(byte**)(team + 0x430);
            byte* corresponding = *(byte**)(positionDoor + 0x3f0);
            auto coordinate = [&](int axis) -> float10 {
                const float* location = (const float*)(corresponding + 0x234) + axis;
                const float* displacement = (const float*)offset + axis;
                if ((selected.offsetFirst & (1U << axis)) != 0)
                    return (float10)(axis == 2 ? firstZ : (float10)*displacement) + *location;
                return (float10)*location + *displacement;
            };
            float10 pointZ = coordinate(2), pointY = coordinate(1), pointX = coordinate(0);
            float x = (float)pointX; position[0] = reinterpret_cast<uint&>(x);
            float y = (float)pointY; position[1] = reinterpret_cast<uint&>(y);
            float z = (float)pointZ; position[2] = reinterpret_cast<uint&>(z);
            if (layout != 0 && (slot == 1 || slot == 2))
                sampleRotation(positionDoor, selected.focalYaw, 1); // Samples the same current door used for the point.
            offset = scaledDirection(selected.focalDistance, selected.secondVector, selected.secondScale);
            float focalX = (float)((float10)*(float*)position + offset->X);
            float focalY = (float)((float10)*(float*)(position + 1) + offset->Y);
            float10 focalZ = (float10)*(float*)(position + 2) + offset->Z;
            if (selected.coverBeforeFocal) {
                reinterpret_cast<byte&>(this->m_eCoverDirection) = selected.cover;
                float focalZWord = (float)focalZ;
                *(float*)(controller + 0x48c) = focalX;
                *(float*)(controller + 0x490) = focalY;
                *(float*)(controller + 0x494) = focalZWord;
            } else {
                *(float*)(controller + 0x48c) = focalX;
                *(float*)(controller + 0x490) = focalY;
                *(float*)(controller + 0x494) = (float)focalZ;
                reinterpret_cast<byte&>(this->m_eCoverDirection) = selected.cover;
            }
        }
        uint z = position[2];
        ((uint*)result)[0] = position[0];
        ((uint*)result)[1] = position[1];
        ((uint*)result)[2] = z;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::getEntryPosition");
        throw;
    }
}

// R6Engine.dll @ 100383e3 : RainbowEntryCatchPointer
// Throws the inherited EBP-3c pointer through EBP-38 without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEntryCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x3c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x38]
        push eax
        mov dword ptr [ebp-0x38],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100383f7 : RainbowEntryCatchContext
// Reports getEntryPosition context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEntryCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIGetEntryPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038450 : AR6RainbowAI::getGuardPosition
// Normalizes the leader direction and places the cached member anchor at a straight or diagonal offset.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::getGuardPosition(FVector* result)
{
    byte* controller = (byte*)this;
    byte* team = reinterpret_cast<byte*&>(this->m_TeamManager);
    int formationDistance = *(int*)(team + 0x3ac);
    byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
    uint slot = *(uint*)(pawn + 0x68c);
    int diagonalDistance = *(int*)(team + 0x3b0); // Both distances and member ID precede native catch state0.
    try {
        byte* anchor = (team[0x3e8] & 0x10) != 0
            ? *(byte**)((uint)team + 0x3ecU + slot * 4U) : *(byte**)(team + 0x3f0);
        byte* leader = reinterpret_cast<byte*&>(this->m_TeamLeader);
        float10 deltaZ = (float10)*(float*)(leader + 0x23c) - *(float*)(pawn + 0x23c);
        float10 deltaY = (float10)*(float*)(leader + 0x238) - *(float*)(pawn + 0x238);
        float10 deltaX = (float10)*(float*)(leader + 0x234) - *(float*)(pawn + 0x234);
        FVector direction = {(float)deltaX, (float)deltaY, (float)deltaZ}; // Native EBP-2c, rounded XYZ.
        // Return value ignored; anchor and distances stay captured.
        direction.Normalize();
        reinterpret_cast<byte&>(this->m_ePawnOrientation) = 0;
        if (slot != 1 && slot != 2 && slot != 3) {
            const uint* location = (const uint*)(reinterpret_cast<byte*&>(this->Pawn) + 0x234);
            uint x = location[0], y = location[1], z = location[2];
            ((uint*)result)[0] = x; ((uint*)result)[1] = y; ((uint*)result)[2] = z;
            return result;
        }
        bool straight = slot == 3;
        if (slot == 1) {
            team = reinterpret_cast<byte*&>(this->m_TeamManager);
            straight = *(uint*)(team + 0x3a4) == 2; // Current member count after Normalize.
        }
        float10 xProduct;
        float yProduct, zProduct;
        if (straight) {
            float10 distance = (float10)formationDistance; // FILD retains the exact signed32 integer.
            if (slot == 3) distance *= nativeDouble2Point5; // Native double2.5; no distance32f spill.
            xProduct = (float10)direction.X * distance;
            yProduct = (float)((float10)direction.Y * distance);
            zProduct = (float)((float10)direction.Z * distance);
        } else {
            uint returnWords[5][3]; // Native twelve-byte return slots -74/-68/-5c/-50/-44; -50 is unused here.
            FRotator* rotationOutput = (FRotator*)returnWords[slot == 1 ? 1 : 4];
            const FRotator* returned = &(*rotationOutput = direction.Rotation());
            FRotator rotation; // Native EBP-38.
            rotation.Roll = returned->Roll;
            uint yaw = (uint)returned->Yaw;
            rotation.Pitch = returned->Pitch;
            rotation.Yaw = (int)(yaw + (slot == 1 ? 0x2000U : 0xffffe000U));
            FVector* vectorOutput = (FVector*)returnWords[slot == 1 ? 0 : 2];
            const FVector* vector = &(*vectorOutput = rotation.Vector());
            float10 distance = (float10)diagonalDistance; // Native FILD follows the Vector callback.
            xProduct = distance * vector->X;
            yProduct = (float)(distance * vector->Y);
            zProduct = (float)(distance * vector->Z);
        }
        float x = (float)((float10)*(float*)(anchor + 0x234) - xProduct);
        float y = (float)((float10)*(float*)(anchor + 0x238) - yProduct);
        float z = (float)((float10)*(float*)(anchor + 0x23c) - zProduct);
        ((float*)result)[0] = x; ((float*)result)[1] = y; ((float*)result)[2] = z;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::getGuardPosition");
        throw;
    }
}

// R6Engine.dll @ 1003862d : RainbowGuardCatchPointer
// Throws the inherited EBP-20 pointer through EBP-1c without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowGuardCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038641 : RainbowGuardCatchContext
// Reports the method context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowGuardCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIGetGuardPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038660 : AR6RainbowAI::getLadderPosition
// Uses the initial ladder-list rotation, then offsets the current pawn's ladder with wrapped integer spacing.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6RainbowAI::getLadderPosition(FVector* result)
{
    try {
        byte* controller = (byte*)this;
        byte* team = reinterpret_cast<byte*&>(this->m_TeamManager);
        int formationDistance = *(int*)(team + 0x3ac);
        byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
        byte* initialLadder = *(byte**)(pawn + 0x784);
        byte* ladderVolume = *(byte**)(initialLadder + 0x3e8);
        byte* ladderList = *(byte**)(ladderVolume + 0x47c);
        uint slot = *(uint*)(pawn + 0x68c);
        FRotator rotation; // Native EBP-28, copied Pitch/Yaw/Roll before the top flag.
        rotation.Pitch = *(int*)(ladderList + 0x240);
        rotation.Yaw = *(int*)(ladderList + 0x244);
        rotation.Roll = *(int*)(ladderList + 0x248);
        byte* topLadder = *(byte**)(pawn + 0x784);
        if ((topLadder[0x3f0] & 1) != 0)
            rotation.Yaw = (int)((uint)rotation.Yaw + 0x8000U);
        uint multiplier;
        if (slot == 1) {
            rotation.Yaw = (int)((uint)rotation.Yaw + 0x2000U);
            topLadder = *(byte**)(pawn + 0x784); // Fresh top test before this case's Vector call.
            multiplier = (topLadder[0x3f0] & 1) != 0 ? 2 : 3;
        } else if (slot == 2) {
            rotation.Yaw = (int)((uint)rotation.Yaw - 0x2000U);
            multiplier = 2;
        } else {
            multiplier = slot;
        }
        FVector vectorReturns[5]; // Native -7c/-70/-64/-58/-4c, twelve-byte stride.
        int vectorIndex = slot == 1 ? (multiplier == 2 ? 1 : 0) : slot == 2 ? 2 : slot == 3 ? 3 : 4;
        const FVector* vector = &(vectorReturns[vectorIndex] = rotation.Vector());
        float10 distance;
        if (slot == 3) distance = (float10)formationDistance * nativeDouble2Point5;
        else distance = (float10)(int)((uint)formationDistance * multiplier); // LEA/IMUL wrap before signed FILD.
        byte* currentPawn = nullptr;
        if (slot == 2 || slot == 3) currentPawn = reinterpret_cast<byte*&>(this->Pawn);
        float10 xProduct = distance * vector->X;
        float yProduct = (float)(distance * vector->Y);
        float10 zProduct = distance * vector->Z;
        if (slot != 2 && slot != 3) currentPawn = reinterpret_cast<byte*&>(this->Pawn);
        byte* currentLadder = *(byte**)(currentPawn + 0x784);
        float zProductWord = (float)zProduct;
        float x = (float)((float10)*(float*)(currentLadder + 0x234) - xProduct);
        float y = (float)((float10)*(float*)(currentLadder + 0x238) - yProduct);
        float10 z = (float10)*(float*)(currentLadder + 0x23c) - zProductWord;
        reinterpret_cast<byte&>(this->m_ePawnOrientation) = 0;
        ((float*)result)[0] = x;
        float roundedZ = (float)z; // Native spills Z only after clearing orientation and writing output X.
        ((float*)result)[1] = y;
        ((float*)result)[2] = roundedZ;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::getLadderPosition");
        throw;
    }
}

// R6Engine.dll @ 1003881e : RainbowLadderCatchPointer
// Throws the inherited EBP-1c pointer through EBP-18 without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowLadderCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038832 : RainbowLadderCatchContext
// Reports the method context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowLadderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIGetLadderPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038850 : AR6RainbowAI::checkEnvironment
// Traces both formation sides and dispatches the resulting formation byte to the captured current team.
void AR6RainbowAI::checkEnvironment()
{
    byte* controller = (byte*)this;
    bool active = controller[0x56c] != 0; // Native formation read precedes catch state0.
    try {
        if (!active) return;
        uint hits[2][12]; // Native positive EBP-a8 and negative EBP-78, initialized separately before their vectors.
        FRotator rotation; // Shared EBP-2c.
        FVector vectorReturn; // Shared EBP-b8; both calls reuse this hidden output.
        FVector end; // Shared EBP-38; providers can retain its address across the traces.
        for (int side = 0; side < 2; ++side) {
            byte* pawn = *(byte**)(controller + 0x3d8);
            const uint* pawnRotation = (const uint*)(pawn + 0x240);
            byte* level = nullptr;
            if (side == 0) level = *(byte**)(controller + 0x328);
            for (int word = 0; word < 9; ++word) hits[side][word] = 0;
            hits[side][9] = 0x3f800000;
            hits[side][10] = 0xffffffff;
            hits[side][11] = 0;
            uint pitch, yaw, roll;
            if (side == 0) {
                yaw = pawnRotation[1]; roll = pawnRotation[2]; pitch = pawnRotation[0];
            } else {
                roll = pawnRotation[2]; yaw = pawnRotation[1]; pitch = pawnRotation[0];
                level = *(byte**)(controller + 0x328);
            }
            rotation.Pitch = (int)pitch;
            rotation.Yaw = (int)(yaw + (side == 0 ? 0x2aabU : 0xffffd555U));
            rotation.Roll = (int)roll;
            const FVector* vector = &(vectorReturn = rotation.Vector());
            float10 zProduct = (float10)vector->Z * nativeFloat3EPlus02;
            const uint* zero = nullptr;
            // Captured before the remaining products on the second side.
            if (side == 1) zero = *(const uint**)&FVectorFVector0Import;
            float yProduct = (float)((float10)vector->Y * nativeFloat3EPlus02);
            float10 xValue = vector->X;
            pawn = *(byte**)(controller + 0x3d8);
            float xProduct = (float)(xValue * nativeFloat3EPlus02);
            const FVector* start = (const FVector*)(pawn + 0x234);
            float10 endZ = zProduct + start->Z;
            float10 endY = (float10)yProduct + start->Y;
            float10 endX = (float10)xProduct + start->X;
            if (side == 0) zero = *(const uint**)&FVectorFVector0Import;
            end.X = (float)endX; end.Y = (float)endY; end.Z = (float)endZ;
            byte* levelTable = *(byte**)level; // Level stays captured across Vector; table/slot are read afterward.
            uint extent[3];
            extent[0] = zero[0];
            uint extentY = zero[1], extentZ = zero[2];
            extent[1] = extentY; extent[2] = extentZ;
            using Trace = int (__thiscall*)(byte*, uint*, AR6RainbowAI*, const FVector*, const FVector*, uint,
                uint, uint, uint);
            (*(Trace*)(levelTable + 0xcc))(level, hits[side], this, &end, start, 0x86,
                // Trace return is ignored; each Time remains live until both calls finish.
                extent[0], extent[1], extent[2]);
        }
        bool positiveClear = !((float10)reinterpret_cast<float&>(hits[0][9]) < nativeDouble1);
        bool negativeClear = !((float10)reinterpret_cast<float&>(hits[1][9]) < nativeDouble1);
        controller[0x56c] = positiveClear ? (negativeClear ? 4 : 3) : (negativeClear ? 2 : 1);
        byte selectedFormation = controller[0x56c];
        // Retained across function lookup, even if the controller changes teams.
        byte* team = *(byte**)(controller + 0x59c);
        byte formation = selectedFormation;
        uint requestName = reinterpret_cast<uint&>(R6ENGINE_RequestFormationChange);
        UFunction* function = reinterpret_cast<UObject*>(team)->UObject::FindFunctionChecked(
            reinterpret_cast<const FName&>(requestName), 0);
        using ProcessEvent = void (__thiscall*)(byte*, UFunction*, void*, void*);
        reinterpret_cast<UObject*>(team)->ProcessEvent(function, &formation, nullptr);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::checkEnvironment");
        throw;
    }
}

// R6Engine.dll @ 10038afe : RainbowEnvironmentCatchPointer
// Throws the inherited EBP-ac pointer through EBP-3c without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEnvironmentCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0xac]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x3c]
        push eax
        mov dword ptr [ebp-0x3c],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038b15 : RainbowEnvironmentCatchContext
// Reports checkEnvironment context and rethrows the active exception using the native zeroed EBX packet.
__declspec(naked) __declspec(noreturn) void __cdecl RainbowEnvironmentCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAICheckEnvironment
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10038b40 : AR6RainbowAI::getTargetPosition
// Computes a formation slot, traces it, and uses a straight trailing point when the trace reports an Actor.
// Explicit hidden result: ECX=this, [ESP+4]=result, EAX=result, RET4; early return is 10039452..10039475.
FVector* __thiscall AR6RainbowAI::getTargetPosition(FVector* result)
{
    byte* controller = (byte*)this;
    byte* initialPawn = *(byte**)(controller + 0x3d8);
    const uint* initialLocation = (const uint*)(initialPawn + 0x234);
    uint initialX = initialLocation[0], initialY = initialLocation[1], initialZ = initialLocation[2];
    uint target[3] = {initialX, initialY, initialZ}; // EBP-28, retained and writable through the trace endpoint.
    byte* leader = *(byte**)(controller + 0x5a0); // These reads precede catch state0.
    try {
        if (leader == nullptr || *(uint*)(leader + 0x4ec) == 0) { // Pawn.Controller.
            ((uint*)result)[0] = initialX; ((uint*)result)[1] = initialY; ((uint*)result)[2] = initialZ;
            return result;
        }
        byte* team = *(byte**)(controller + 0x59c);
        uint spacing = *(uint*)(team + 0x3ac), diagonal = *(uint*)(team + 0x3b0);
        uint slot = *(uint*)(initialPawn + 0x68c);
        byte formation = controller[0x56c]; // Saved dispatch; callbacks do not reselect a formation or slot.
        FRotator rotation = {0,0,0}; // Shared EBP-34; slot2 of formations1/4 retains it across two Vector calls.
        FVector temporary; // EBP-1c; also the first Vector output for formation1's unrecognized slots.
        FVector vectors[38]; // Native twelve-byte slots EBP-254..EBP-98, including reused fallback output EBP-98.
        auto buffer = [&](int offset) -> FVector* {
            return offset == 0x1c ? &temporary : &vectors[(0x254 - offset) / 12];
        };
        auto vector = [&](int offset, int yawDelta, bool useLocal) -> const FVector* {
            byte* currentTeam = *(byte**)(controller + 0x59c);
            FRotator* direction = (FRotator*)(currentTeam + 0x460);
            if (useLocal) {
                rotation.Pitch = direction->Pitch;
                rotation.Yaw = (int)((uint)direction->Yaw + (uint)yawDelta);
                rotation.Roll = direction->Roll;
                direction = &rotation;
            }
            return &(*buffer(offset) = direction->Vector());
        };
        auto scale = [&](int offset, uint distance, const FVector* direction) -> const FVector* {
            float scalar = (float)(float10)(int)distance; // FILD then native32f outgoing argument.
            return ScaleVectorToResult(buffer(offset), scalar, direction);
        };
        auto difference = [&](const FVector* anchor, const FVector* scaled) {
            float10 z = (float10)anchor->Z - scaled->Z;
            float10 y = (float10)anchor->Y - scaled->Y;
            float10 x = (float10)anchor->X - scaled->X;
            temporary.X = (float)x; target[0] = ((uint*)&temporary)[0];
            temporary.Y = (float)y; target[1] = ((uint*)&temporary)[1];
            temporary.Z = (float)z; target[2] = ((uint*)&temporary)[2];
        };
        if (formation >= 1 && formation <= 4) {
            // Descriptive branch grouping, not a recovered native table. Column0 handles all slots outside1..3.
            struct TargetCase { int vectorOffset, scaleOffset, yaw, member; };
            const TargetCase cases[4][4] = {
                {{0x1c,0x230,0,-1},{0x1a0,0xf8,0x1555,0},{0x188,0xc8,-0x4000,1},{0x23c,0x254,0x1555,2}},
                {{0x1e8,0xb0,0,-1},{0x11c,0x134,0x1555,0},{0xec,0x104,-0x1555,1},{0xbc,0xd4,0,2}},
                {{0x14c,0x164,0,-1},{0x1dc,0x1f4,-0x1555,0},{0x1ac,0x1c4,0x1555,1},{0x17c,0x194,0,2}},
                {{0x200,0x110,0,-1},{0x218,0x170,0x1555,0},{0xa4,0x140,-0x4000,1},{0x1b8,0x128,0x1555,2}}
            };
            const TargetCase& selected = cases[formation - 1][slot >= 1 && slot <= 3 ? slot : 0];
            bool twoOffsets = (formation == 1 || formation == 4) && slot == 2;
            const FVector* direction;
            if (twoOffsets) {
                team = *(byte**)(controller + 0x59c);
                const FRotator* originalDirection = (const FRotator*)(team + 0x460);
                rotation.Pitch = originalDirection->Pitch;
                rotation.Yaw = (int)((uint)originalDirection->Yaw - 0x4000U);
                rotation.Roll = originalDirection->Roll;
                // First Vector deliberately receives the team direction, not the adjusted local rotation.
                direction = &(*buffer(selected.vectorOffset) = ((FRotator*)originalDirection)->Vector());
            } else direction = vector(selected.vectorOffset, selected.yaw, selected.yaw != 0);
            uint distance = selected.member < 0 ? spacing * slot : selected.yaw !=
                0 && !twoOffsets ? diagonal : spacing;
            const FVector* scaled = scale(selected.scaleOffset, distance, direction);
            byte* anchor = selected.member < 0 ? *(byte**)(controller + 0x5a0)
                : *(byte**)(*(byte**)(controller + 0x59c) + 0x3f0 + selected.member * 4);
            if (twoOffsets) {
                float firstZ = (float)((float10)*(float*)(anchor + 0x23c) - scaled->Z);
                float firstY = (float)((float10)*(float*)(anchor + 0x238) - scaled->Y);
                float firstX = (float)((float10)*(float*)(anchor + 0x234) - scaled->X);
                direction = &(*buffer(formation == 1 ? 0x248 : 0x1d0) = rotation.Vector());
                scaled = scale(formation == 1 ? 0xe0 : 0x158, diagonal, direction);
                float10 z = (float10)firstZ - scaled->Z;
                float10 y = (float10)firstY - scaled->Y;
                float10 x = (float10)firstX - scaled->X;
                temporary.X = (float)x; target[0] = ((uint*)&temporary)[0];
                temporary.Y = (float)y; target[1] = ((uint*)&temporary)[1];
                temporary.Z = (float)z; target[2] = ((uint*)&temporary)[2];
            } else difference((const FVector*)(anchor + 0x234), scaled);
        } else if (formation == 5) {
            const FVector* direction = vector(0x20c, 0, false);
            const FVector* scaled = scale(0x224, spacing, direction);
            team = *(byte**)(controller + 0x59c);
            byte* anchor = *(byte**)(team + (uint)(0x3ecU + slot * 4U)); // Native raw m_Team[slot-1], no bounds check.
            difference((const FVector*)(anchor + 0x234), scaled);
        } else {
            const FVector* direction = vector(0x98, 0, false);
            float10 distance = (float10)(int)(spacing * slot); // Unlike helper paths, no32f scalar spill here.
            float z = (float)(distance * direction->Z);
            float y = (float)(distance * direction->Y);
            float x = (float)(distance * direction->X);
            leader = *(byte**)(controller + 0x5a0);
            FVector scaled = {x,y,z};
            difference((const FVector*)(leader + 0x234), &scaled);
        }
        byte* level = *(byte**)(controller + 0x328);
        NativeCheckResult32 hit; // EBP-88; inline native initialization, not a constructor/owned cleanup.
        for (int i = 0; i < 9; ++i) reinterpret_cast<uint*>(&hit)[i] = 0;
        hit.materialAddress = 0;
        const uint* zero = *(const uint**)&FVectorFVector0Import;
        reinterpret_cast<uint&>(hit.Time) = 0x3f800000; reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
        uint extentX = zero[0];
        byte* levelTable = *(byte**)level;
        uint extentY = zero[1], extentZ = zero[2]; // Raw FVector0 words, preserving signed zero/payloads.
        byte* pawn = *(byte**)(controller + 0x3d8);
        using Trace = int (__thiscall*)(byte*, uint*, byte*, uint*, const FVector*, uint, uint, uint, uint);
        (*(Trace*)(levelTable + 0xcc))(level, reinterpret_cast<uint*>(&hit), pawn, target,
            (const FVector*)(pawn + 0x234), 0x86,
            extentX, extentY, extentZ);
        if (hit.actorAddress != 0) { // Actor, not Time or the native trace return value.
            const FVector* direction = vector(0x98, 0, false);
            uint distanceWord = spacing * slot;
            leader = *(byte**)(controller + 0x5a0);
            const FVector* anchor = (const FVector*)(leader + 0x234);
            float10 distance = (float10)(int)distanceWord;
            float10 xProduct = distance * direction->X; // X remains extended; Y/Z products spill32f.
            float yProduct = (float)(distance * direction->Y);
            float zProduct = (float)(distance * direction->Z);
            temporary.X = (float)((float10)anchor->X - xProduct);
            temporary.Y = (float)((float10)anchor->Y - yProduct);
            uint y = ((uint*)&temporary)[1];
            float10 z = (float10)anchor->Z - zProduct;
            uint x = ((uint*)&temporary)[0];
            ((uint*)result)[0] = x; ((uint*)result)[1] = y;
            temporary.Z = (float)z;
            ((uint*)result)[2] = ((uint*)&temporary)[2];
        } else {
            uint x = target[0], y = target[1], z = target[2];
            ((uint*)result)[0] = x; ((uint*)result)[1] = y; ((uint*)result)[2] = z;
        }
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::getTargetPosition");
        throw;
    }
}

// R6Engine.dll @ 1003941f : RainbowTargetCatchPointer
// Forwards the parent-frame typed pointer through its native throw temporary.
__declspec(naked) void RainbowTargetCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x8c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x58]
        push eax
        mov dword ptr [ebp-0x58],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039436 : RainbowTargetCatchContext
// Reports formation-target context before rethrowing the active exception.
__declspec(naked) void RainbowTargetCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIGetTargetPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039490 : AR6RainbowAI::UpdateTimers
// Advances the attack counter, dispatches due attack/stop events, then updates base actor timers.
void AR6RainbowAI::UpdateTimers(float deltaSeconds)
{
    byte* controller = (byte*)this;
    bool positiveRate = *(float*)(controller + 0x58c) > nativeFloatZero; // Compare before catch state0.
    try {
        bool attackPeriodElapsed = false;
        if (positiveRate) {
            float advanced = (float)((float10)deltaSeconds + *(float*)(controller + 0x590));
            bool reachedRate = advanced >= *(float*)(controller + 0x58c);
            *(float*)(controller + 0x590) = advanced;
            if (reachedRate) { // Unordered is false; this branch suppresses StopAttack even without an enemy/bFire.
                attackPeriodElapsed = true;
                if (*(float*)(controller + 0x58c) > nativeFloatZero) {
                    float10 quotient = (float10)advanced / *(float*)(controller + 0x58c);
                    int periods;
                    __asm {
                        fld quotient
                        call TruncateX87ToSigned64
                        mov periods,eax
                    } // Only the signed low32 bits of the native64-bit conversion feed the next FILD.
                    float10 product = (float10)periods * *(float*)(controller + 0x58c);
                    *(float*)(controller + 0x590) = (float)((float10)advanced - product);
                }
                if (*(uint*)(controller + 0x400) != 0 || controller[0x396] != 0) { // Enemy / bFire.
                    uint name = reinterpret_cast<uint&>(R6ENGINE_AttackTimer); // R6ENGINE_AttackTimer.
                    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
                    using Event = void (__thiscall*)(AR6RainbowAI*, UFunction*, void*, void*);
                    (*(Event*)(*(byte**)controller + 0x10))(this, function, nullptr, nullptr);
                    // Event can change bFire; reload before deciding whether to randomize.
                    if (controller[0x396] != 0) {
                        int random = appRand();
                        int firingStep = random % 6 + 1; // Signed native IDIV, including negative provider results.
                        *(float*)(controller + 0x594) = (float)((float10)firingStep * nativeFloat0Point05);
                    }
                }
            }
        }
        if (!attackPeriodElapsed && controller[0x396] != 0
            && *(float*)(controller + 0x590) >= *(float*)(controller + 0x594)) {
            // R6ENGINE_StopAttack; unordered counter/threshold does not dispatch.
            uint name = reinterpret_cast<uint&>(R6ENGINE_StopAttack);
            UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
            using Event = void (__thiscall*)(AR6RainbowAI*, UFunction*, void*, void*);
            (*(Event*)(*(byte**)controller + 0x10))(this, function, nullptr, nullptr);
        }
        // Current base import, original delta; skipped if a provider throws.
        this->AActor::UpdateTimers(deltaSeconds);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::UpdateTimers");
        throw;
    }
}

// R6Engine.dll @ 100395eb : RainbowTimersCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void RainbowTimersCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100395ff : RainbowTimersCatchContext
// Reports timer-update context before rethrowing the active exception.
__declspec(naked) void RainbowTimersCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIUpdateTimers
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039620 : AR6RainbowAI::execLookAroundRoom
// Evaluates the leading-entry word, consumes optional DebugInfo, then dispatches the room scan on this controller.
void AR6RainbowAI::execLookAroundRoom(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    int bIsLeadingRoomEntry = 0; // EBP-14, passed to the operand and retained across optional DebugInfo.
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // These captures precede catch state0.
    try {
        natives[opcode](receiver, &stack, &bIsLeadingRoomEntry);
        code = *cursor + 1; // Current cursor after operand evaluation; consume its EndFunctionParms byte.
        *cursor = code;
        if (*code == 0x42) {
            receiver = frame->Object;
            *cursor = code + 1;
            natives = *(ScriptNative**)&CoreGNativesImport; // Reload current table after the operand callback.
            natives[0x42](receiver, &stack, nullptr);
        }
        // Current full32-bit local, not a normalized bool or frame.Object receiver.
        this->AR6RainbowAI::LookAroundRoom(bIsLeadingRoomEntry);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execLookAroundRoom");
        throw;
    }
}

// R6Engine.dll @ 100396b0 : RainbowRoomBridgeCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void RainbowRoomBridgeCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100396c4 : RainbowRoomBridgeCatchContext
// Reports room-scan script-bridge context before rethrowing the active exception.
__declspec(naked) void RainbowRoomBridgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecLookAroundRoom
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100396f0 : AR6RainbowAI::FindSafeSpot
// Searches nearby reachable navigation points farther from the grenade than the initial pawn position.
// Native thiscall returns an Actor pointer in EAX with plain RET; the script bridge stores its full word.
AActor* AR6RainbowAI::FindSafeSpot()
{
    byte* controller = (byte*)this;
    byte* initialPawn = *(byte**)(controller + 0x3d8);
    float10 initialZ = (float10)*(float*)(initialPawn + 0x23c) - *(float*)(controller + 0x5d8);
    // Native state0 begins after this load, before Y subtraction.
    float10 initialYValue = *(float*)(initialPawn + 0x238);
    try {
        float10 initialY = initialYValue - *(float*)(controller + 0x5d4);
        float10 initialX = (float10)*(float*)(initialPawn + 0x234) - *(float*)(controller + 0x5d0);
        auto squared = [](float10 z, float10 y, float10 x) -> float10 {
            float10 xx = x * x, yy = y * y;
            float10 xy = xx + yy;
            float10 zz = z * z;
            return xy + zz;
        };
        // EBP-18, retained across callbacks.
        float initialGrenadeDistance = (float)squared(initialZ, initialY, initialX);
        auto reachableSafePoint = [&](byte* pawn, byte* candidate, float10 pawnZ) -> bool {
            float10 dz = pawnZ - *(float*)(candidate + 0x23c);
            float10 dy = (float10)*(float*)(pawn + 0x238) - *(float*)(candidate + 0x238);
            float10 dx = (float10)*(float*)(pawn + 0x234) - *(float*)(candidate + 0x234);
            float10 pawnDistance = squared(dz, dy, dx); // Extended, not a32f FVector delta or distance.
            dz = (float10)*(float*)(controller + 0x5d8) - *(float*)(candidate + 0x23c);
            dy = (float10)*(float*)(controller + 0x5d4) - *(float*)(candidate + 0x238);
            dx = (float10)*(float*)(controller + 0x5d0) - *(float*)(candidate + 0x234);
            // EBP-14, calculated even when candidate is too far away.
            float grenadeDistance = (float)squared(dz, dy, dx);
            if (!(pawnDistance < nativeFloat1Point44EPlus06)) return false; // Strict1200-squared; unordered rejects.
            if (!(initialGrenadeDistance < grenadeDistance)) return false; // Both operands are saved32f distances.
            return reinterpret_cast<APawn*>(pawn)->APawn::actorReachable(
                reinterpret_cast<AActor*>(candidate), 0, 0) != 0;
        };
        if (reinterpret_cast<APawn*>(initialPawn)->APawn::ValidAnchor() != 0) {
            uint index = 0;
            for (;;) {
                // Current Pawn and Anchor each iteration, including after callbacks.
                byte* pawn = *(byte**)(controller + 0x3d8);
                byte* anchor = *(byte**)(pawn + 0x4f8);
                // Current Anchor.PathList count, signed native comparison.
                if ((int)index >= *(int*)(anchor + 0x3dc)) break;
                anchor = *(byte**)(pawn + 0x4f8);
                float10 pawnZ = *(float*)(pawn + 0x23c);
                byte** paths = *(byte***)(anchor + 0x3d8);
                byte* reachSpec = paths[index];
                byte* candidate = *(byte**)(reachSpec + 0x4c); // Matching1.60 ReachSpec.End.
                if (reachableSafePoint(pawn, candidate, pawnZ)) return reinterpret_cast<AActor*>(candidate);
                ++index;
            }
        }
        byte* levelInfo = *(byte**)(controller + 0x144);
        // LevelInfo.NavigationPointList after the anchor search/callbacks.
        byte* candidate = *(byte**)(levelInfo + 0x4d0);
        while (candidate != nullptr) {
            byte* pawn = *(byte**)(controller + 0x3d8);
            float10 pawnZ = *(float*)(pawn + 0x23c);
            if (reachableSafePoint(pawn, candidate, pawnZ)) return reinterpret_cast<AActor*>(candidate);
            // Current nextNavigationPoint after a failed reachability callback.
            candidate = *(byte**)(candidate + 0x3a8);
        }
        return nullptr;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::FindSafeSpot");
        throw;
    }
}

// R6Engine.dll @ 10039931 : RainbowSafeCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void RainbowSafeCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039945 : RainbowSafeCatchContext
// Reports safe-navigation-search context before rethrowing the active exception.
__declspec(naked) void RainbowSafeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIFindSafeSpot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039970 : AR6RainbowAI::AClearShotIsAvailable
// Traces the target head and accepts clear hits, the target pawn, or a pawn classified as neither friend nor neutral.
// Native thiscall takes target plus by-value FVector, returns full0/1 EAX and RET0x10.
int AR6RainbowAI::AClearShotIsAvailable(APawn* target, FVector traceStart)
{
    bool useLastSeen = target == this->Enemy; // Enemy comparison precedes catch state0.
    try {
        FVector headReturn; // Native hidden helper output EBP-30, distinct from the copied endpoint EBP-24.
        uint head[3];
        if (useLastSeen) {
            const uint* lastSeen = reinterpret_cast<const uint*>(&this->LastSeenPos); // Controller.LastSeenPos.
            uint x = lastSeen[0], y = lastSeen[1], z = lastSeen[2];
            head[0] = x; head[1] = y; head[2] = z;
        } else {
            AR6Pawn* pawn = this->m_pawn;
            const uint* returned = (const uint*)pawn->AR6Pawn::GetHeadLocation(&headReturn, target);
            head[0] = returned[0]; head[1] = returned[1]; head[2] = returned[2];
        }
        const uint* zero = *(const uint**)&FVectorFVector0Import;
        ULevel* level = this->XLevel;
        NativeCheckResult32 hit; // EBP-60; inline initialization, no FCheckResult constructor or owned cleanup.
        hit.nextAddress = 0; hit.actorAddress = 0; hit.primitiveAddress = 0; hit.materialAddress = 0;
        for (int word = 2; word < 8; ++word) reinterpret_cast<uint*>(&hit)[word] = 0;
        reinterpret_cast<uint&>(hit.Time) = 0x3f800000; reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
        uint extentX = zero[0];
        byte* levelTable = *(byte**)level;
        uint extentY = zero[1], extentZ = zero[2]; // Current imported FVector0 words, not a literal zero extent.
        APawn* pawn = this->Pawn;
        using Trace = int (__thiscall*)(ULevel*, uint*, AActor*, uint*, const FVector*, uint, uint, uint, uint);
        (*(Trace*)(levelTable + 0xcc))(level, reinterpret_cast<uint*>(&hit), pawn, head, &traceStart, 0x4400bf,
            extentX, extentY, extentZ);
        AActor* hitObject = reinterpret_cast<AActor*>(hit.actorAddress);
        if (hitObject == nullptr) return 1;
        APawn* hitPawn = hitObject->GetPawnOrColBoxOwner();
        if (hit.actorAddress == 0 || hitPawn == target) return 1; // Classification may change the retained trace hit.
        if (hitPawn == nullptr) return 0;
        // Native IsFriend self-to-self call.
        if (hitPawn->APawn::IsFriend(hitPawn) != 0) return 0;
        // Current IsNeutral import, same retained receiver/argument.
        return hitPawn->APawn::IsNeutral(hitPawn) == 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::AClearShotIsAvailable");
        throw;
    }
}

// R6Engine.dll @ 10039ac9 : RainbowClearanceShotCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void RainbowClearanceShotCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039add : RainbowClearanceShotCatchContext
// Reports clear-shot context before rethrowing the active exception.
__declspec(naked) void RainbowClearanceShotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIAClearShotIsAvailable
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039b00 : AR6RainbowAI::ClearToSnipe
// Traces along the supplied rotation and returns full0/1 according to the hit Actor word.
// Native thiscall takes by-value FVector/FRotator and returns with RET0x18.
int AR6RainbowAI::ClearToSnipe(FVector vStart, FRotator rSnipingDir)
{
    try {
        FVector directionReturn; // EBP-34; native later reuses its X word for the scaled X product.
        const FVector* direction = &(directionReturn = rSnipingDir.Vector());
        float10 zProduct = (float10)direction->Z * nativeFloat3EPlus02;
        ULevel* level = this->XLevel;
        float yProduct = (float)((float10)direction->Y * nativeFloat3EPlus02);
        float10 xValue = direction->X;
        // Captured before X multiplication and endpoint stores.
        const uint* zero = *(const uint**)&FVectorFVector0Import;
        float10 xProduct = xValue * nativeFloat3EPlus02;
        NativeCheckResult32 hit; // EBP-64, with native initialization interleaved through endpoint calculation.
        hit.nextAddress = 0; hit.actorAddress = 0; reinterpret_cast<uint&>(hit.Location.X) = 0;
        directionReturn.X = (float)xProduct;
        reinterpret_cast<uint&>(hit.Location.Y) = 0; reinterpret_cast<uint&>(hit.Location.Z) = 0;
        float10 endZ = zProduct + vStart.Z; // Z product stays extended across this addition.
        reinterpret_cast<uint&>(hit.Normal.X) = 0;
        float10 startY = vStart.Y;
        reinterpret_cast<uint&>(hit.Normal.Y) = 0;
        float10 endY = startY + yProduct;
        reinterpret_cast<uint&>(hit.Normal.Z) = 0;
        float10 startX = vStart.X;
        hit.primitiveAddress = 0;
        float10 endX = startX + directionReturn.X;
        hit.materialAddress = 0; reinterpret_cast<uint&>(hit.Time) = 0x3f800000;
        FVector end; // EBP-28, separate from the retained Vector output and by-value start.
        end.X = (float)endX;
        reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
        end.Y = (float)endY; end.Z = (float)endZ;
        uint extentX = zero[0];
        byte* levelTable = *(byte**)level;
        uint extentY = zero[1], extentZ = zero[2];
        APawn* pawn = this->Pawn;
        using Trace =
            int (__thiscall*)(ULevel*, uint*, AActor*, const FVector*, const FVector*, uint, uint, uint, uint);
        (*(Trace*)(levelTable + 0xcc))(level, reinterpret_cast<uint*>(&hit), pawn, &end, &vStart, 0x4400bf, extentX,
            extentY, extentZ);
        return hit.actorAddress == 0; // Full native EAX is zeroed before SETE AL; trace EAX and hit.Time are ignored.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::ClearToSnipe");
        throw;
    }
}

// R6Engine.dll @ 10039bf6 : RainbowClearanceSnipeCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void RainbowClearanceSnipeCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039c0a : RainbowClearanceSnipeCatchContext
// Reports sniping-clearance context before rethrowing the active exception.
__declspec(naked) void RainbowClearanceSnipeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIClearToSnipe
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039c30 : AR6RainbowAI::execGetTargetPosition
// Consumes optional DebugInfo and copies the native returned Vector words.
void __thiscall AR6RainbowAI::execGetTargetPosition(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* finish = *cursor + 1;
    *cursor = finish;
    bool hasDebug = *finish == 0x42; // Native finish-byte comparison precedes catch state0.
    UObject* receiver;
    ScriptNative* natives;
    try {
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        FVector temporary; // Native hidden output EBP-24; use the returned pointer below.
        const uint* position = (const uint*)this->getTargetPosition(&temporary);
        uint first = position[0];
        uint* output = (uint*)result;
        output[0] = first;
        output[1] = position[1];
        // Native interleaves returned-pointer reads and result stores; no snapshot/normalization.
        output[2] = position[2];
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execGetTargetPosition");
        throw;
    }
}

// R6Engine.dll @ 10039caf : RainbowBridgeGetTargetPositionCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeGetTargetPositionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039cc3 : RainbowBridgeGetTargetPositionCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeGetTargetPositionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecGetTargetPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039ce0 : AR6RainbowAI::execGetLadderPosition
// Consumes optional DebugInfo and copies the native returned Vector words.
void __thiscall AR6RainbowAI::execGetLadderPosition(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* finish = *cursor + 1;
    *cursor = finish;
    bool hasDebug = *finish == 0x42; // Native finish-byte comparison precedes catch state0.
    UObject* receiver;
    ScriptNative* natives;
    try {
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        FVector temporary; // Native hidden output EBP-24; use the returned pointer below.
        const uint* position = (const uint*)this->AR6RainbowAI::getLadderPosition(&temporary);
        uint first = position[0];
        uint* output = (uint*)result;
        output[0] = first;
        output[1] = position[1];
        // Native interleaves returned-pointer reads and result stores; no snapshot/normalization.
        output[2] = position[2];
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execGetLadderPosition");
        throw;
    }
}

// R6Engine.dll @ 10039d5f : RainbowBridgeGetLadderPositionCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeGetLadderPositionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039d73 : RainbowBridgeGetLadderPositionCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeGetLadderPositionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecGetLadderPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039d90 : AR6RainbowAI::execGetGuardPosition
// Consumes optional DebugInfo and copies the native returned Vector words.
void __thiscall AR6RainbowAI::execGetGuardPosition(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* finish = *cursor + 1;
    *cursor = finish;
    bool hasDebug = *finish == 0x42; // Native finish-byte comparison precedes catch state0.
    UObject* receiver;
    ScriptNative* natives;
    try {
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        FVector temporary; // Native hidden output EBP-24; use the returned pointer below.
        const uint* position = (const uint*)this->AR6RainbowAI::getGuardPosition(&temporary);
        uint first = position[0];
        uint* output = (uint*)result;
        output[0] = first;
        output[1] = position[1];
        // Native interleaves returned-pointer reads and result stores; no snapshot/normalization.
        output[2] = position[2];
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execGetGuardPosition");
        throw;
    }
}

// R6Engine.dll @ 10039e0f : RainbowBridgeGetGuardPositionCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeGetGuardPositionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039e23 : RainbowBridgeGetGuardPositionCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeGetGuardPositionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecGetGuardPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039e40 : AR6RainbowAI::execGetEntryPosition
// Evaluates the room-entry Bool word and returns the selected native position.
void __thiscall AR6RainbowAI::execGetEntryPosition(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor;
    int bInsideRoom = 0; // EBP-14, retained across optional DebugInfo.
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    try { // Operand dispatch starts state0 after the captures above.
        natives[opcode](receiver, &stack, &bInsideRoom);
        byte* finish = *cursor + 1;
        *cursor = finish;
        bool hasDebug = *finish == 0x42;
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        FVector temporary; // Shared EBP-28 output for both native paths.
        const uint* position = (const uint*)(bInsideRoom != 0
            ? this->AR6RainbowAI::getEntryPosition(&temporary) : this->AR6RainbowAI::getPreEntryPosition(&temporary));
        uint first = position[0];
        uint* output = (uint*)result;
        output[0] = first;
        output[1] = position[1];
        // Native interleaves returned-pointer reads and result stores; no snapshot/normalization.
        output[2] = position[2];
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execGetEntryPosition");
        throw;
    }
}

// R6Engine.dll @ 10039f1b : RainbowBridgeGetEntryPositionCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeGetEntryPositionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039f2f : RainbowBridgeGetEntryPositionCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeGetEntryPositionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecGetEntryPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10039f50 : AR6RainbowAI::execSetOrientation
// Evaluates the optional orientation byte and applies it or dispatches the peeking fallback.
void __thiscall AR6RainbowAI::execSetOrientation(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte eOverrideOrientation = *((byte*)this + 0x56d); // EBP-11; selected default captured before state0.
    UObject* receiver = frame->Object;
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    try { // Operand dispatch starts state0 after the captures above.
        natives[opcode](receiver, &stack, &eOverrideOrientation);
        byte* finish = *cursor + 1;
        *cursor = finish;
        bool hasDebug = *finish == 0x42;
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        byte* controller = (byte*)this;
        bool applyOrientation = reinterpret_cast<uint&>(this->Enemy) == 0;
        if (applyOrientation) {
            byte* pawn = reinterpret_cast<byte*&>(this->Pawn);
            applyOrientation = !(*(float*)(pawn + 0x75c) > nativeFloatZero);
        } // Ordered positive firing timer blocks; zero/negative/unordered uses the decoded byte.
        if (applyOrientation) {
            this->AR6RainbowAI::setMemberOrientation((EPawnOrientation)eOverrideOrientation);
            return;
        }
        // Captured across lookup; later m_pawn changes do not retarget it.
        UObject* pawn = reinterpret_cast<UObject*&>(this->m_pawn);
        uint name = reinterpret_cast<uint&>(R6ENGINE_SetPeekingInfo); // R6ENGINE_SetPeekingInfo.
        uint parameters[3]; // EBP-28, byte eMode + three untouched padding bytes, fPeeking and bPeekLeft.
        reinterpret_cast<byte&>(parameters[0]) = 0;
        parameters[1] = 0x447a0000;
        parameters[2] = 0;
        UFunction* function = pawn->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
        pawn->ProcessEvent(function, parameters, nullptr); // Captured pawn's CURRENT event vtable.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execSetOrientation");
        throw;
    }
}

// R6Engine.dll @ 1003a044 : RainbowBridgeSetOrientationCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeSetOrientationCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a058 : RainbowBridgeSetOrientationCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeSetOrientationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecSetOrientation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a080 : AR6RainbowAI::execCheckEnvironment
// Consumes optional DebugInfo and checks formation traces without writing the script result.
void __thiscall AR6RainbowAI::execCheckEnvironment(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* finish = *cursor + 1;
    *cursor = finish;
    bool hasDebug = *finish == 0x42; // Native finish-byte comparison precedes catch state0.
    UObject* receiver;
    ScriptNative* natives;
    try {
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        this->checkEnvironment(); // Matching script declares Vector, but native intentionally leaves result untouched.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execCheckEnvironment");
        throw;
    }
}

// R6Engine.dll @ 1003a0e8 : RainbowBridgeCheckEnvironmentCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeCheckEnvironmentCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a0fc : RainbowBridgeCheckEnvironmentCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeCheckEnvironmentCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecCheckEnvironment
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a120 : AR6RainbowAI::execFindSafeSpot
// Consumes optional DebugInfo and writes the native safe-point Actor word.
void __thiscall AR6RainbowAI::execFindSafeSpot(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* finish = *cursor + 1;
    *cursor = finish;
    bool hasDebug = *finish == 0x42; // Native finish-byte comparison precedes catch state0.
    UObject* receiver;
    ScriptNative* natives;
    try {
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        uint word = (uint)this->FindSafeSpot();
        *(uint*)result = word;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execFindSafeSpot");
        throw;
    }
}

// R6Engine.dll @ 1003a18d : RainbowBridgeFindSafeSpotCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeFindSafeSpotCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a1a1 : RainbowBridgeFindSafeSpotCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeFindSafeSpotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecFindSafeSpot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a1c0 : AR6RainbowAI::execAClearShotIsAvailable
// Evaluates the target/start arguments and writes the full native clear-shot word.
void __thiscall AR6RainbowAI::execAClearShotIsAvailable(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor;
    APawn* PTarget = nullptr; // EBP-14; vStart remains uninitialized until evaluation.
    FVector vStart; // EBP-28.
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    try { // Operand dispatch starts state0 after the captures above.
        natives[opcode](receiver, &stack, &PTarget);
        code = *cursor;
        opcode = *code;
        receiver = frame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[opcode](receiver, &stack, &vStart);
        byte* finish = *cursor + 1;
        *cursor = finish;
        bool hasDebug = *finish == 0x42;
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        uint word = (uint)this->AClearShotIsAvailable(PTarget, vStart);
        *(uint*)result = word; // Native copies full EAX even though script declares Bool.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execAClearShotIsAvailable");
        throw;
    }
}

// R6Engine.dll @ 1003a285 : RainbowBridgeAClearShotIsAvailableCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeAClearShotIsAvailableCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a299 : RainbowBridgeAClearShotIsAvailableCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeAClearShotIsAvailableCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage1
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a2c0 : AR6RainbowAI::execClearToSnipe
// Evaluates start/rotation arguments and writes the full native sniper-clearance word.
void __thiscall AR6RainbowAI::execClearToSnipe(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor;
    FVector vStart; // EBP-30; no default vector initialization in native.
    FRotator rSnipingDir; // EBP-24, evaluated by the second opcode.
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    try { // Operand dispatch starts state0 after the captures above.
        natives[opcode](receiver, &stack, &vStart);
        code = *cursor;
        opcode = *code;
        receiver = frame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[opcode](receiver, &stack, &rSnipingDir);
        byte* finish = *cursor + 1;
        *cursor = finish;
        bool hasDebug = *finish == 0x42;
        if (hasDebug) {
            receiver = frame->Object;
            *cursor = finish + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        uint word = (uint)this->ClearToSnipe(vStart, rSnipingDir);
        *(uint*)result = word; // Both structures are raw twelve-byte by-value arguments.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RainbowAI::execAClearShotIsAvailable");
        throw;
    }
}

// R6Engine.dll @ 1003a390 : RainbowBridgeClearToSnipeCatchPointer
// Forwards the parent's typed pointer through its native throw temporary.
__declspec(naked) void RainbowBridgeClearToSnipeCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003a3a4 : RainbowBridgeClearToSnipeCatchContext
// Reports the native script-bridge diagnostic before rethrowing the active exception.
__declspec(naked) void RainbowBridgeClearToSnipeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecAClearShotIsAvailableAR6RainbowAIStorage2
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10047fd0 : DestroyAR6RainbowAIClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6RainbowAIClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6RainbowAI::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045e80 : InitializeAR6RainbowAIClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6RainbowAIClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred saved within-class word at entryESP-4.
        UClass* withinClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x50.
        int nativeConstructorTag;
        uint classSize;
        uint classFlags;
        UClass* parentClass;
        UClass* withinClass;
        uint guidWords[4];
        const ushort* className;
        const ushort* packageName;
        const ushort* configName;
        uint objectFlags;
        void (__cdecl* internalConstructor)(void*);
        union { // entryESP-0x18 is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6RainbowAI::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6RainbowAI;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6AIController::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x60c;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6RainbowAI::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6RainbowAIClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045f00 : PublishAR6RainbowAIAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6RainbowAIAutoClass(void)
{
    autoclassAR6RainbowAI = &AR6RainbowAI::PrivateStaticClass;
}

// R6Engine.dll @ 100479e0 : RegisterAR6RainbowAIClearToSnipeNative
// Registers native index0x8af using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIClearToSnipeNative(void)
{
    AR6RainbowAIClearToSnipeRegistrationResult = GRegisterNative(0x8af, intAR6RainbowAIexecClearToSnipe);
}

// R6Engine.dll @ 10047a00 : RegisterAR6RainbowAIAClearShotIsAvailableNative
// Registers native index0x8ae using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIAClearShotIsAvailableNative(void)
{
    AR6RainbowAIAClearShotIsAvailableRegistrationResult =
        GRegisterNative(0x8ae, intAR6RainbowAIexecAClearShotIsAvailable);
}

// R6Engine.dll @ 10047a20 : RegisterAR6RainbowAIFindSafeSpotNative
// Registers native index0x8ad using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIFindSafeSpotNative(void)
{
    AR6RainbowAIFindSafeSpotRegistrationResult = GRegisterNative(0x8ad, intAR6RainbowAIexecFindSafeSpot);
}

// R6Engine.dll @ 10047a40 : RegisterAR6RainbowAILookAroundRoomNative
// Registers native index0x8ab using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAILookAroundRoomNative(void)
{
    AR6RainbowAILookAroundRoomRegistrationResult = GRegisterNative(0x8ab, intAR6RainbowAIexecLookAroundRoom);
}

// R6Engine.dll @ 10047a60 : RegisterAR6RainbowAISetOrientationNative
// Registers native index0x89f using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAISetOrientationNative(void)
{
    AR6RainbowAISetOrientationRegistrationResult = GRegisterNative(0x89f, intAR6RainbowAIexecSetOrientation);
}

// R6Engine.dll @ 10047a80 : RegisterAR6RainbowAICheckEnvironmentNative
// Registers native index0x89e using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAICheckEnvironmentNative(void)
{
    AR6RainbowAICheckEnvironmentRegistrationResult = GRegisterNative(0x89e, intAR6RainbowAIexecCheckEnvironment);
}

// R6Engine.dll @ 10047aa0 : RegisterAR6RainbowAIGetEntryPositionNative
// Registers native index0x89d using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIGetEntryPositionNative(void)
{
    AR6RainbowAIGetEntryPositionRegistrationResult = GRegisterNative(0x89d, intAR6RainbowAIexecGetEntryPosition);
}

// R6Engine.dll @ 10047ac0 : RegisterAR6RainbowAIGetGuardPositionNative
// Registers native index0x89c using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIGetGuardPositionNative(void)
{
    AR6RainbowAIGetGuardPositionRegistrationResult = GRegisterNative(0x89c, intAR6RainbowAIexecGetGuardPosition);
}

// R6Engine.dll @ 10047ae0 : RegisterAR6RainbowAIGetLadderPositionNative
// Registers native index0x89b using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIGetLadderPositionNative(void)
{
    AR6RainbowAIGetLadderPositionRegistrationResult = GRegisterNative(0x89b, intAR6RainbowAIexecGetLadderPosition);
}

// R6Engine.dll @ 10047b00 : RegisterAR6RainbowAIGetTargetPositionNative
// Registers native index0x89a using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6RainbowAIGetTargetPositionNative(void)
{
    AR6RainbowAIGetTargetPositionRegistrationResult = GRegisterNative(0x89a, intAR6RainbowAIexecGetTargetPosition);
}

// R6Engine.dll @ 10044d80 : RainbowOrientationExceptionHandler
// Supplies setMemberOrientation's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowOrientationExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowOrientationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d90 : RainbowPreEntryExceptionHandler
// Supplies getPreEntryPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowPreEntryExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowPreEntryFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044da0 : RainbowEntryExceptionHandler
// Supplies getEntryPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowEntryExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowEntryFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044db0 : RainbowGuardExceptionHandler
// Supplies getGuardPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowGuardExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowGuardFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044dc0 : RainbowLadderExceptionHandler
// Supplies getLadderPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowLadderExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowLadderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044dd0 : RainbowEnvironmentExceptionHandler
// Supplies checkEnvironment's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowEnvironmentExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowEnvironmentFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044de0 : RainbowTargetExceptionHandler
// Supplies the formation-target FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowTargetExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowTargetFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044df0 : RainbowTimersExceptionHandler
// Supplies the timer-update FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowTimersExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowTimersFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e00 : RainbowRoomBridgeExceptionHandler
// Supplies the room-scan bridge FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowRoomBridgeExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowRoomBridgeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e10 : RainbowSafeExceptionHandler
// Supplies the safe-navigation-search FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowSafeExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowSafeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e20 : RainbowClearanceShotExceptionHandler
// Supplies the clear-shot FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowClearanceShotExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowClearanceShotFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e30 : RainbowClearanceSnipeExceptionHandler
// Supplies the sniping-clearance FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowClearanceSnipeExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowClearanceSnipeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e40 : RainbowBridgeGetTargetPositionExceptionHandler
// Supplies execGetTargetPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeGetTargetPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeGetTargetPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e50 : RainbowBridgeGetLadderPositionExceptionHandler
// Supplies execGetLadderPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeGetLadderPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeGetLadderPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e60 : RainbowBridgeGetGuardPositionExceptionHandler
// Supplies execGetGuardPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeGetGuardPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeGetGuardPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e70 : RainbowBridgeGetEntryPositionExceptionHandler
// Supplies execGetEntryPosition's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeGetEntryPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeGetEntryPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e80 : RainbowBridgeSetOrientationExceptionHandler
// Supplies execSetOrientation's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeSetOrientationExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeSetOrientationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044e90 : RainbowBridgeCheckEnvironmentExceptionHandler
// Supplies execCheckEnvironment's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeCheckEnvironmentExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeCheckEnvironmentFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044ea0 : RainbowBridgeFindSafeSpotExceptionHandler
// Supplies execFindSafeSpot's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeFindSafeSpotExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeFindSafeSpotFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044eb0 : RainbowBridgeAClearShotIsAvailableExceptionHandler
// Supplies execAClearShotIsAvailable's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeAClearShotIsAvailableExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeAClearShotIsAvailableFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044ec0 : RainbowBridgeClearToSnipeExceptionHandler
// Supplies execClearToSnipe's exact FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RainbowBridgeClearToSnipeExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowBridgeClearToSnipeFuncInfo
        jmp __CxxFrameHandler
    }
}
