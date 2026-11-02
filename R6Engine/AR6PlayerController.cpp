#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_text_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl DebugFunctionExceptionHandler(void);
__declspec(naked) void __cdecl UpdateCircumstantialActionExceptionHandler(void);
__declspec(naked) void ReticuleIdentificationExceptionHandler(void);
__declspec(naked) void PlayerPreNetReceiveExceptionHandler(void);
__declspec(naked) void __cdecl KeyLocalizationExceptionHandler(void);
__declspec(naked) void FindPlayerExceptionHandler(void);
int __cdecl CastToAPlayerController(int object);
__declspec(naked) void SpectatorReticuleExceptionHandler(void);
__declspec(naked) void CircumstantialActionExceptionHandler(void);
float10 __cdecl NegateNegativeOrUnordered(float value);
__declspec(naked) void PlayerPostNetReceiveExceptionHandler(void);
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);
__declspec(naked) void __cdecl TrainingLocalizationExceptionHandler(void);
__declspec(naked) void __cdecl LocStringActionExceptionHandler(void);
__declspec(naked) void __cdecl UpdateSpectatorReticuleExceptionHandler(void);
__declspec(naked) void __cdecl UpdateReticuleExceptionHandler(void);
__declspec(naked) void __cdecl StopVoicesExceptionHandler(void);
int __thiscall RemoveMatchingWords4(FArray* words, const uint* keyReference);
__declspec(naked) void __cdecl PlayPriorityExceptionHandler(void);
__declspec(naked) void __cdecl ControllerDestroyExceptionHandler(void);
void __thiscall RemoveRecords4(FArray* array, int index, int count);
__declspec(naked) void __cdecl ExecVoicesExceptionHandler(void);
__declspec(naked) void __cdecl VoicePollExceptionHandler(void);
__declspec(naked) void __cdecl ControllerTickExceptionHandler(void);
__declspec(naked) void __cdecl DestroyAR6PlayerControllerClassMetadata(void);
__declspec(naked) void ProjectionExceptionHandler(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
void __thiscall DestroyTenStrings(void* strings);

// R6Engine.dll data @ 1004cc40 : AR6PlayerControllerVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6PlayerController::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6PlayerControllerVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055f2c : nativeTextAR6PlayerControllerDestroy
extern const ushort nativeTextAR6PlayerControllerDestroy[29];

// R6Engine.dll data @ 10052000 : nativeTextAR6PlayerControllerExecDebugFunction
extern const ushort nativeTextAR6PlayerControllerExecDebugFunction[39];

// R6Engine.dll data @ 10052188 : nativeTextAR6PlayerControllerExecFindPlayer
extern const ushort nativeTextAR6PlayerControllerExecFindPlayer[36];

// R6Engine.dll data @ 10052738 : nativeTextAR6PlayerControllerExecGetLocStringWithActionKey
extern const ushort nativeTextAR6PlayerControllerExecGetLocStringWithActionKey[51];

// R6Engine.dll data @ 10052320 : nativeTextAR6PlayerControllerExecLocalizeTraining
extern const ushort nativeTextAR6PlayerControllerExecLocalizeTraining[42];

// R6Engine.dll data @ 10055f68 : nativeTextAR6PlayerControllerExecPlayVoicesPriority
extern const ushort nativeTextAR6PlayerControllerExecPlayVoicesPriority[44];

// R6Engine.dll data @ 10052070 : nativeTextAR6PlayerControllerExecUpdateCircumstantialAction
extern const ushort nativeTextAR6PlayerControllerExecUpdateCircumstantialAction[52];

// R6Engine.dll data @ 10052808 : nativeTextAR6PlayerControllerExecUpdateReticule
extern const ushort nativeTextAR6PlayerControllerExecUpdateReticule[40];

// R6Engine.dll data @ 100527a0 : nativeTextAR6PlayerControllerExecUpdateSpectatorReticule
extern const ushort nativeTextAR6PlayerControllerExecUpdateSpectatorReticule[49];

// R6Engine.dll data @ 10055ee8 : nativeTextAR6PlayerControllerPlayPriority
extern const ushort nativeTextAR6PlayerControllerPlayPriority[34];

// R6Engine.dll data @ 10055fc0 : nativeTextAR6PlayerControllerPlayVoicesPriority
extern const ushort nativeTextAR6PlayerControllerPlayVoicesPriority[40];

// R6Engine.dll data @ 100522d8 : nativeTextAR6PlayerControllerPostNetReceive
extern const ushort nativeTextAR6PlayerControllerPostNetReceive[36];

// R6Engine.dll data @ 10052140 : nativeTextAR6PlayerControllerPreNetReceive
extern const ushort nativeTextAR6PlayerControllerPreNetReceive[35];

// R6Engine.dll data @ 10055e90 : nativeTextAR6PlayerControllerStopAndRemoveVoices
extern const ushort nativeTextAR6PlayerControllerStopAndRemoveVoices[41];

// R6Engine.dll data @ 10056010 : nativeTextAR6PlayerControllerTick
extern const ushort nativeTextAR6PlayerControllerTick[26];

// R6Engine.dll data @ 10052230 : nativeTextAR6PlayerControllerUpdateCircumstantialAction
extern const ushort nativeTextAR6PlayerControllerUpdateCircumstantialAction[48];

// R6Engine.dll data @ 100520d8 : nativeTextAR6PlayerControllerUpdateReticuleIdentification
extern const ushort nativeTextAR6PlayerControllerUpdateReticuleIdentification[50];

// R6Engine.dll data @ 100521d0 : nativeTextAR6PlayerControllerUpdateSpectatorReticule
extern const ushort nativeTextAR6PlayerControllerUpdateSpectatorReticule[45];

// R6Engine.dll data @ 10055666 : nativeTextR6PlayerController
extern const ushort nativeTextR6PlayerController[19];

// R6Engine.dll data @ 100522a0 : nativeTextRGMCaptureTheEnemyAdvMode
extern const ushort nativeTextRGMCaptureTheEnemyAdvMode[27];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl AR6PlayerControllerSpectatorReticuleCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AR6PlayerControllerSpectatorReticuleCatchPointer(void);
__declspec(naked) void CircumstantialActionCatchContext(void);
__declspec(naked) void CircumstantialActionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ControllerDestroyCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ControllerDestroyCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ControllerTickCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ControllerTickCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DebugFunctionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DebugFunctionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ExecVoicesCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ExecVoicesCatchPointer(void);
__declspec(naked) void FindPlayerCatchContext(void);
__declspec(naked) void FindPlayerCatchPointer(void);
__declspec(naked) void FindPlayerState1Cleanup(void);
__declspec(naked) void FindPlayerState2Cleanup(void);
__declspec(naked) void __cdecl KeyLocalizationState0Cleanup(void);
__declspec(naked) void __cdecl KeyLocalizationState1Cleanup(void);
__declspec(naked) void __cdecl KeyLocalizationState2Cleanup(void);
__declspec(naked) void __cdecl KeyLocalizationState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl LocStringActionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl LocStringActionCatchPointer(void);
__declspec(naked) void __cdecl LocStringActionState1Cleanup(void);
__declspec(naked) void __cdecl LocStringActionState2Cleanup(void);
__declspec(naked) void __cdecl LocStringActionState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl PlayPriorityCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PlayPriorityCatchPointer(void);
__declspec(naked) void __cdecl PlayPriorityState1Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerConstructionExceptionHandler(void);
__declspec(naked) void __cdecl PlayerControllerCtorState0Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerCtorState1Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerCtorState2Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerCtorState3Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerCtorState4Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerCtorState5Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDestructionExceptionHandler(void);
__declspec(naked) void __cdecl PlayerControllerDtorState0Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState1Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState2Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState3Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState4Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState5Cleanup(void);
__declspec(naked) void __cdecl PlayerControllerDtorState6Cleanup(void);
__declspec(naked) void PlayerPostNetReceiveCatchContext(void);
__declspec(naked) void PlayerPostNetReceiveCatchPointer(void);
__declspec(naked) void PlayerPreNetReceiveCatchContext(void);
__declspec(naked) void PlayerPreNetReceiveCatchPointer(void);
int __cdecl ProjectPointToViewport(UViewport* viewport, float* outputX, float* outputY,
    float worldX, float worldY, float worldZ, float cameraX, float cameraY, float cameraZ,
    int cameraPitch, int cameraYaw, int cameraRoll);
__declspec(naked) void ProjectionState0Cleanup(void);
__declspec(naked) void ProjectionState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl ReticuleCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ReticuleCatchPointer(void);
__declspec(naked) void ReticuleIdentificationCatchContext(void);
__declspec(naked) void ReticuleIdentificationCatchPointer(void);
__declspec(naked) void ReticuleIdentificationState1Cleanup(void);
__declspec(naked) void SpectatorReticuleCatchContext(void);
__declspec(naked) void SpectatorReticuleCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl StopVoicesCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StopVoicesCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TrainingLocalizationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TrainingLocalizationCatchPointer(void);
__declspec(naked) void __cdecl TrainingLocalizationState10Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState11Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState12Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState13Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState14Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState15Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState16Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState17Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState18Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState19Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState1Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState20Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState21Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState22Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState23Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState24Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState25Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState26Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState27Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState28Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState29Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState2Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState30Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState31Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState32Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState33Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState34Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState35Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState36Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState37Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState38Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState39Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState3Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState40Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState41Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState42Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState43Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState44Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState45Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState46Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState47Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState48Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState49Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState4Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState50Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState51Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState52Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState53Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState54Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState55Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState56Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState57Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState58Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState59Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState5Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState60Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState61Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState62Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState63Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState64Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState65Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState66Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState67Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState68Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState69Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState6Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState70Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState71Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState72Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState73Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState74Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState75Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState76Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState77Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState78Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState79Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState7Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState8Cleanup(void);
__declspec(naked) void __cdecl TrainingLocalizationState9Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl UpdateCircumstantialActionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl UpdateCircumstantialActionCatchPointer(void);
__declspec(naked) void __cdecl UpdateLadderStatExceptionHandler(void);
__declspec(naked) void __cdecl UpdateLadderStatState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl VoicePollCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl VoicePollCatchPointer(void);
__declspec(naked) void __cdecl VoteSessionAbortExceptionHandler(void);
__declspec(naked) void __cdecl VoteSessionAbortState0Cleanup(void);

// R6Engine.dll data @ 10052290 : nativeDouble0Point4
extern const double nativeDouble0Point4;

// R6Engine.dll data @ 10052298 : nativeDouble0Point707
extern const double nativeDouble0Point707;

// R6Engine.dll data @ 1005c214 : PlayerPostNetReceiveUnwindMap
// Both receive states have no owned local cleanup.
const NativeUnwindEntry PlayerPostNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c224 : PlayerPostNetReceiveCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry PlayerPostNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PlayerPostNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&PlayerPostNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005c244 : PlayerPostNetReceiveTryMap
// Only state zero is protected by the post-receive catches.
const NativeTryBlock PlayerPostNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&PlayerPostNetReceiveCatchMap) }
};

// R6Engine.dll data @ 1005c258 : PlayerPostNetReceiveFuncInfo
// Binds the post-receive guard to its cleanup-free states and catches.
const NativeFunctionInfoPrefix PlayerPostNetReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&PlayerPostNetReceiveUnwindMap),
    0x1, ((uint)&PlayerPostNetReceiveTryMap), 0 };

// R6Engine.dll data @ 1005c1b4 : CircumstantialActionUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry CircumstantialActionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c1c4 : CircumstantialActionCatchMap
// Typed pointer catch uses EBP-0xc0, followed by the context catch.
const NativeCatchEntry CircumstantialActionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -192, ((uint)&CircumstantialActionCatchPointer) },
    { 0, 0, 0, ((uint)&CircumstantialActionCatchContext) }
};

// R6Engine.dll data @ 1005c1e4 : CircumstantialActionTryMap
// Only state zero is protected by the action-update catches.
const NativeTryBlock CircumstantialActionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&CircumstantialActionCatchMap) }
};

// R6Engine.dll data @ 1005c1f8 : CircumstantialActionFuncInfo
// Binds the action-update frame to its cleanup-free catches.
const NativeFunctionInfoPrefix CircumstantialActionFuncInfo = { 0x19930520, 0x2, ((uint)&CircumstantialActionUnwindMap),
    0x1, ((uint)&CircumstantialActionTryMap), 0 };

// R6Engine.dll data @ 1005c154 : SpectatorReticuleUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry SpectatorReticuleUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c164 : SpectatorReticuleCatchMap
// Typed pointer catch uses EBP-0x20, followed by the context catch.
const NativeCatchEntry SpectatorReticuleCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&SpectatorReticuleCatchPointer) },
    { 0, 0, 0, ((uint)&SpectatorReticuleCatchContext) }
};

// R6Engine.dll data @ 1005c184 : SpectatorReticuleTryMap
// Only state zero is protected by the spectator-reticule catches.
const NativeTryBlock SpectatorReticuleTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&SpectatorReticuleCatchMap) }
};

// R6Engine.dll data @ 1005c198 : SpectatorReticuleFuncInfo
// Binds the spectator-reticule frame to its cleanup-free catches.
const NativeFunctionInfoPrefix SpectatorReticuleFuncInfo = { 0x19930520, 0x2, ((uint)&SpectatorReticuleUnwindMap), 0x1,
    ((uint)&SpectatorReticuleTryMap), 0 };

// R6Engine.dll data @ 1005c0e4 : FindPlayerUnwindMap
// State two owns canonical ID, then state one owns the input identifier.
const NativeUnwindEntry FindPlayerUnwindMap[4] = {
    { -1, 0 },
    { 0, ((uint)&FindPlayerState1Cleanup) },
    { 0x1, ((uint)&FindPlayerState2Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c104 : FindPlayerCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry FindPlayerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&FindPlayerCatchPointer) },
    { 0, 0, 0, ((uint)&FindPlayerCatchContext) }
};

// R6Engine.dll data @ 1005c124 : FindPlayerTryMap
// States zero through two share the typed and reporting catches.
const NativeTryBlock FindPlayerTryMap[1] = {
    { 0, 0x2, 0x3, 0x2, ((uint)&FindPlayerCatchMap) }
};

// R6Engine.dll data @ 1005c138 : FindPlayerFuncInfo
// Binds both string cleanups and the player-search catches.
const NativeFunctionInfoPrefix FindPlayerFuncInfo = { 0x19930520, 0x4, ((uint)&FindPlayerUnwindMap), 0x1,
    ((uint)&FindPlayerTryMap), 0 };

// R6Engine.dll data @ 1005bfb4 : ReticuleIdentificationUnwindMap
// State one owns the name string; states zero and two have no local cleanup.
const NativeUnwindEntry ReticuleIdentificationUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&ReticuleIdentificationState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bfcc : ReticuleIdentificationCatchMap
// Typed pointer catch writes EBP-0x18, followed by the context catch.
const NativeCatchEntry ReticuleIdentificationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ReticuleIdentificationCatchPointer) },
    { 0, 0, 0, ((uint)&ReticuleIdentificationCatchContext) }
};

// R6Engine.dll data @ 1005bfec : ReticuleIdentificationTryMap
// States zero and one share the typed and reporting catches.
const NativeTryBlock ReticuleIdentificationTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&ReticuleIdentificationCatchMap) }
};

// R6Engine.dll data @ 1005c000 : ReticuleIdentificationFuncInfo
// Binds reticule string cleanup and the two catch handlers.
const NativeFunctionInfoPrefix ReticuleIdentificationFuncInfo = { 0x19930520, 0x3,
    ((uint)&ReticuleIdentificationUnwindMap), 0x1, ((uint)&ReticuleIdentificationTryMap), 0 };

// R6Engine.dll data @ 1005c01c : PlayerPreNetReceiveUnwindMap
// Both receive states have no owned local cleanup.
const NativeUnwindEntry PlayerPreNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c02c : PlayerPreNetReceiveCatchMap
// Typed pointer catch writes EBP-0x18, followed by the context catch.
const NativeCatchEntry PlayerPreNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PlayerPreNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&PlayerPreNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005c04c : PlayerPreNetReceiveTryMap
// Only state zero is protected by the receive catches.
const NativeTryBlock PlayerPreNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&PlayerPreNetReceiveCatchMap) }
};

// R6Engine.dll data @ 1005c060 : PlayerPreNetReceiveFuncInfo
// Binds the receive guard to its cleanup-free states and catches.
const NativeFunctionInfoPrefix PlayerPreNetReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&PlayerPreNetReceiveUnwindMap),
    0x1, ((uint)&PlayerPreNetReceiveTryMap), 0 };

// R6Engine.dll data @ 1005ec6c : voicePollUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry voicePollUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ec7c : voicePollCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry voicePollCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&VoicePollCatchPointer) },
    { 0, 0, 0, ((uint)&VoicePollCatchContext) }
};

// R6Engine.dll data @ 1005ec9c : voicePollTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock voicePollTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&voicePollCatchMap) }
};

// R6Engine.dll data @ 1005ecb0 : voicePollFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix voicePollFuncInfo = { 0x19930520, 0x2, ((uint)&voicePollUnwindMap), 0x1,
    ((uint)&voicePollTryMap), 0 };

// R6Engine.dll data @ 1005eccc : controllerTickUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry controllerTickUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ecdc : controllerTickCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry controllerTickCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ControllerTickCatchPointer) },
    { 0, 0, 0, ((uint)&ControllerTickCatchContext) }
};

// R6Engine.dll data @ 1005ecfc : controllerTickTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock controllerTickTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&controllerTickCatchMap) }
};

// R6Engine.dll data @ 1005ed10 : controllerTickFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix controllerTickFuncInfo = { 0x19930520, 0x2, ((uint)&controllerTickUnwindMap), 0x1,
    ((uint)&controllerTickTryMap), 0 };

// R6Engine.dll data @ 1005ec0c : execVoicesUnwindMap
// Retains exact no-local-cleanup states and inherited script catch-frame bindings.
const NativeUnwindEntry execVoicesUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ec1c : execVoicesCatchMap
// Retains exact no-local-cleanup states and inherited script catch-frame bindings.
const NativeCatchEntry execVoicesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -60, ((uint)&ExecVoicesCatchPointer) },
    { 0, 0, 0, ((uint)&ExecVoicesCatchContext) }
};

// R6Engine.dll data @ 1005ec3c : execVoicesTryMap
// Retains exact no-local-cleanup states and inherited script catch-frame bindings.
const NativeTryBlock execVoicesTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execVoicesCatchMap) }
};

// R6Engine.dll data @ 1005ec50 : execVoicesFuncInfo
// Retains exact no-local-cleanup states and inherited script catch-frame bindings.
const NativeFunctionInfoPrefix execVoicesFuncInfo = { 0x19930520, 0x2, ((uint)&execVoicesUnwindMap), 0x1,
    ((uint)&execVoicesTryMap), 0 };

// R6Engine.dll data @ 1005ebac : controllerDestroyUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry controllerDestroyUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ebbc : controllerDestroyCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry controllerDestroyCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ControllerDestroyCatchPointer) },
    { 0, 0, 0, ((uint)&ControllerDestroyCatchContext) }
};

// R6Engine.dll data @ 1005ebdc : controllerDestroyTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock controllerDestroyTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&controllerDestroyCatchMap) }
};

// R6Engine.dll data @ 1005ebf0 : controllerDestroyFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix controllerDestroyFuncInfo = { 0x19930520, 0x2, ((uint)&controllerDestroyUnwindMap), 0x1,
    ((uint)&controllerDestroyTryMap), 0 };

// R6Engine.dll data @ 1005eb44 : playPriorityUnwindMap
// Retains exact active-index array lifetime and inherited catch-frame bindings.
const NativeUnwindEntry playPriorityUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&PlayPriorityState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005eb5c : playPriorityCatchMap
// Retains exact active-index array lifetime and inherited catch-frame bindings.
const NativeCatchEntry playPriorityCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&PlayPriorityCatchPointer) },
    { 0, 0, 0, ((uint)&PlayPriorityCatchContext) }
};

// R6Engine.dll data @ 1005eb7c : playPriorityTryMap
// Retains exact active-index array lifetime and inherited catch-frame bindings.
const NativeTryBlock playPriorityTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&playPriorityCatchMap) }
};

// R6Engine.dll data @ 1005eb90 : playPriorityFuncInfo
// Retains exact active-index array lifetime and inherited catch-frame bindings.
const NativeFunctionInfoPrefix playPriorityFuncInfo = { 0x19930520, 0x3, ((uint)&playPriorityUnwindMap), 0x1,
    ((uint)&playPriorityTryMap), 0 };

// R6Engine.dll data @ 1005eae4 : stopVoicesUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry stopVoicesUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005eaf4 : stopVoicesCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry stopVoicesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&StopVoicesCatchPointer) },
    { 0, 0, 0, ((uint)&StopVoicesCatchContext) }
};

// R6Engine.dll data @ 1005eb14 : stopVoicesTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock stopVoicesTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stopVoicesCatchMap) }
};

// R6Engine.dll data @ 1005eb28 : stopVoicesFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix stopVoicesFuncInfo = { 0x19930520, 0x2, ((uint)&stopVoicesUnwindMap), 0x1,
    ((uint)&stopVoicesTryMap), 0 };

// R6Engine.dll data @ 1005c274 : trainingLocalizationUnwindMap
// Retains exact input/action string lifetime states and inherited catch bindings.
const NativeUnwindEntry trainingLocalizationUnwindMap[81] = {
    { -1, 0 },
    { 0, ((uint)&TrainingLocalizationState1Cleanup) },
    { 0x1, ((uint)&TrainingLocalizationState2Cleanup) },
    { 0x2, ((uint)&TrainingLocalizationState3Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState4Cleanup) },
    { 0x4, ((uint)&TrainingLocalizationState5Cleanup) },
    { 0x5, ((uint)&TrainingLocalizationState6Cleanup) },
    { 0x6, ((uint)&TrainingLocalizationState7Cleanup) },
    { 0x7, ((uint)&TrainingLocalizationState8Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState9Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState10Cleanup) },
    { 0xa, ((uint)&TrainingLocalizationState11Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState12Cleanup) },
    { 0xc, ((uint)&TrainingLocalizationState13Cleanup) },
    { 0xd, ((uint)&TrainingLocalizationState14Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState15Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState16Cleanup) },
    { 0x10, ((uint)&TrainingLocalizationState17Cleanup) },
    { 0x11, ((uint)&TrainingLocalizationState18Cleanup) },
    { 0x12, ((uint)&TrainingLocalizationState19Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState20Cleanup) },
    { 0x14, ((uint)&TrainingLocalizationState21Cleanup) },
    { 0x15, ((uint)&TrainingLocalizationState22Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState23Cleanup) },
    { 0x17, ((uint)&TrainingLocalizationState24Cleanup) },
    { 0x18, ((uint)&TrainingLocalizationState25Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState26Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState27Cleanup) },
    { 0x1b, ((uint)&TrainingLocalizationState28Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState29Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState30Cleanup) },
    { 0x1e, ((uint)&TrainingLocalizationState31Cleanup) },
    { 0x1f, ((uint)&TrainingLocalizationState32Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState33Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState34Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState35Cleanup) },
    { 0x23, ((uint)&TrainingLocalizationState36Cleanup) },
    { 0x24, ((uint)&TrainingLocalizationState37Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState38Cleanup) },
    { 0x26, ((uint)&TrainingLocalizationState39Cleanup) },
    { 0x27, ((uint)&TrainingLocalizationState40Cleanup) },
    { 0x28, ((uint)&TrainingLocalizationState41Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState42Cleanup) },
    { 0x2a, ((uint)&TrainingLocalizationState43Cleanup) },
    { 0x2b, ((uint)&TrainingLocalizationState44Cleanup) },
    { 0x2c, ((uint)&TrainingLocalizationState45Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState46Cleanup) },
    { 0x2e, ((uint)&TrainingLocalizationState47Cleanup) },
    { 0x2f, ((uint)&TrainingLocalizationState48Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState49Cleanup) },
    { 0x31, ((uint)&TrainingLocalizationState50Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState51Cleanup) },
    { 0x33, ((uint)&TrainingLocalizationState52Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState53Cleanup) },
    { 0x35, ((uint)&TrainingLocalizationState54Cleanup) },
    { 0x36, ((uint)&TrainingLocalizationState55Cleanup) },
    { 0x37, ((uint)&TrainingLocalizationState56Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState57Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState58Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState59Cleanup) },
    { 0x3b, ((uint)&TrainingLocalizationState60Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState61Cleanup) },
    { 0x3d, ((uint)&TrainingLocalizationState62Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState63Cleanup) },
    { 0x3f, ((uint)&TrainingLocalizationState64Cleanup) },
    { 0x40, ((uint)&TrainingLocalizationState65Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState66Cleanup) },
    { 0x42, ((uint)&TrainingLocalizationState67Cleanup) },
    { 0x43, ((uint)&TrainingLocalizationState68Cleanup) },
    { 0x44, ((uint)&TrainingLocalizationState69Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState70Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState71Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState72Cleanup) },
    { 0x48, ((uint)&TrainingLocalizationState73Cleanup) },
    { 0x49, ((uint)&TrainingLocalizationState74Cleanup) },
    { 0x4a, ((uint)&TrainingLocalizationState75Cleanup) },
    { 0x4b, ((uint)&TrainingLocalizationState76Cleanup) },
    { 0x4c, ((uint)&TrainingLocalizationState77Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState78Cleanup) },
    { 0x3, ((uint)&TrainingLocalizationState79Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c4fc : trainingLocalizationCatchMap
// Retains exact input/action string lifetime states and inherited catch bindings.
const NativeCatchEntry trainingLocalizationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -84, ((uint)&TrainingLocalizationCatchPointer) },
    { 0, 0, 0, ((uint)&TrainingLocalizationCatchContext) }
};

// R6Engine.dll data @ 1005c51c : trainingLocalizationTryMap
// Retains exact input/action string lifetime states and inherited catch bindings.
const NativeTryBlock trainingLocalizationTryMap[1] = {
    { 0, 0x4f, 0x50, 0x2, ((uint)&trainingLocalizationCatchMap) }
};

// R6Engine.dll data @ 1005c530 : trainingLocalizationFuncInfo
// Retains exact input/action string lifetime states and inherited catch bindings.
const NativeFunctionInfoPrefix trainingLocalizationFuncInfo = { 0x19930520, 0x51,
    ((uint)&trainingLocalizationUnwindMap), 0x1, ((uint)&trainingLocalizationTryMap), 0 };

// R6Engine.dll data @ 1005c0a8 : keyLocalizationUnwindMap
// Retains exact temporary/result cleanup states without a catch map.
const NativeUnwindEntry keyLocalizationUnwindMap[4] = {
    { -1, ((uint)&KeyLocalizationState0Cleanup) },
    { 0, ((uint)&KeyLocalizationState1Cleanup) },
    { 0x1, ((uint)&KeyLocalizationState2Cleanup) },
    { 0x2, ((uint)&KeyLocalizationState3Cleanup) }
};

// R6Engine.dll data @ 1005c0c8 : keyLocalizationFuncInfo
// Retains exact temporary/result cleanup states without a catch map.
const NativeFunctionInfoPrefix keyLocalizationFuncInfo = { 0x19930520, 0x4, ((uint)&keyLocalizationUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 1005c54c : locStringActionUnwindMap
// Retains exact string lifetime states and inherited catch-frame bindings.
const NativeUnwindEntry locStringActionUnwindMap[5] = {
    { -1, 0 },
    { 0, ((uint)&LocStringActionState1Cleanup) },
    { 0x1, ((uint)&LocStringActionState2Cleanup) },
    { 0x2, ((uint)&LocStringActionState3Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c574 : locStringActionCatchMap
// Retains exact string lifetime states and inherited catch-frame bindings.
const NativeCatchEntry locStringActionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -48, ((uint)&LocStringActionCatchPointer) },
    { 0, 0, 0, ((uint)&LocStringActionCatchContext) }
};

// R6Engine.dll data @ 1005c594 : locStringActionTryMap
// Retains exact string lifetime states and inherited catch-frame bindings.
const NativeTryBlock locStringActionTryMap[1] = {
    { 0, 0x3, 0x4, 0x2, ((uint)&locStringActionCatchMap) }
};

// R6Engine.dll data @ 1005c5a8 : locStringActionFuncInfo
// Retains exact string lifetime states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix locStringActionFuncInfo = { 0x19930520, 0x5, ((uint)&locStringActionUnwindMap), 0x1,
    ((uint)&locStringActionTryMap), 0 };

// R6Engine.dll data @ 1005c5c4 : spectatorReticuleUnwindMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeUnwindEntry spectatorReticuleUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c5d4 : spectatorReticuleCatchMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeCatchEntry spectatorReticuleCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6PlayerControllerSpectatorReticuleCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PlayerControllerSpectatorReticuleCatchContext) }
};

// R6Engine.dll data @ 1005c5f4 : spectatorReticuleTryMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeTryBlock spectatorReticuleTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&spectatorReticuleCatchMap) }
};

// R6Engine.dll data @ 1005c608 : spectatorReticuleFuncInfo
// Retains the native script guard states and inherited catch-frame associations.
const NativeFunctionInfoPrefix spectatorReticuleFuncInfo = { 0x19930520, 0x2, ((uint)&spectatorReticuleUnwindMap), 0x1,
    ((uint)&spectatorReticuleTryMap), 0 };

// R6Engine.dll data @ 1005c624 : reticuleUnwindMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeUnwindEntry reticuleUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c634 : reticuleCatchMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeCatchEntry reticuleCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ReticuleCatchPointer) },
    { 0, 0, 0, ((uint)&ReticuleCatchContext) }
};

// R6Engine.dll data @ 1005c654 : reticuleTryMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeTryBlock reticuleTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&reticuleCatchMap) }
};

// R6Engine.dll data @ 1005c668 : reticuleFuncInfo
// Retains the native script guard states and inherited catch-frame associations.
const NativeFunctionInfoPrefix reticuleFuncInfo = { 0x19930520, 0x2, ((uint)&reticuleUnwindMap), 0x1,
    ((uint)&reticuleTryMap), 0 };

// R6Engine.dll data @ 1005bef4 : debugFunctionUnwindMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeUnwindEntry debugFunctionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bf04 : debugFunctionCatchMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeCatchEntry debugFunctionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DebugFunctionCatchPointer) },
    { 0, 0, 0, ((uint)&DebugFunctionCatchContext) }
};

// R6Engine.dll data @ 1005bf24 : debugFunctionTryMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeTryBlock debugFunctionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&debugFunctionCatchMap) }
};

// R6Engine.dll data @ 1005bf38 : debugFunctionFuncInfo
// Retains the native script guard states and inherited catch-frame associations.
const NativeFunctionInfoPrefix debugFunctionFuncInfo = { 0x19930520, 0x2, ((uint)&debugFunctionUnwindMap), 0x1,
    ((uint)&debugFunctionTryMap), 0 };

// R6Engine.dll data @ 1005bf54 : updateCircumstantialActionUnwindMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeUnwindEntry updateCircumstantialActionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bf64 : updateCircumstantialActionCatchMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeCatchEntry updateCircumstantialActionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&UpdateCircumstantialActionCatchPointer) },
    { 0, 0, 0, ((uint)&UpdateCircumstantialActionCatchContext) }
};

// R6Engine.dll data @ 1005bf84 : updateCircumstantialActionTryMap
// Retains the native script guard states and inherited catch-frame associations.
const NativeTryBlock updateCircumstantialActionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&updateCircumstantialActionCatchMap) }
};

// R6Engine.dll data @ 1005bf98 : updateCircumstantialActionFuncInfo
// Retains the native script guard states and inherited catch-frame associations.
const NativeFunctionInfoPrefix updateCircumstantialActionFuncInfo = { 0x19930520, 0x2,
    ((uint)&updateCircumstantialActionUnwindMap), 0x1, ((uint)&updateCircumstantialActionTryMap), 0 };

// R6Engine.dll data @ 10057eec : playerControllerDtorUnwind
// Retains exact pending base/member cleanup states without catches.
const NativeUnwindEntry playerControllerDtorUnwind[7] = {
    { -1, ((uint)&PlayerControllerDtorState0Cleanup) },
    { 0, ((uint)&PlayerControllerDtorState1Cleanup) },
    { 0x1, ((uint)&PlayerControllerDtorState2Cleanup) },
    { 0x2, ((uint)&PlayerControllerDtorState3Cleanup) },
    { 0x3, ((uint)&PlayerControllerDtorState4Cleanup) },
    { 0x4, ((uint)&PlayerControllerDtorState5Cleanup) },
    { 0x5, ((uint)&PlayerControllerDtorState6Cleanup) }
};

// R6Engine.dll data @ 10057f24 : playerControllerDtorInfo
// Retains exact pending base/member cleanup states without catches.
const NativeFunctionInfoPrefix playerControllerDtorInfo = { 0x19930520, 0x7, ((uint)&playerControllerDtorUnwind), 0, 0,
    0 };

// R6Engine.dll data @ 10057f40 : playerControllerCtorUnwind
// Retains exact pending base/member cleanup states without catches.
const NativeUnwindEntry playerControllerCtorUnwind[6] = {
    { -1, ((uint)&PlayerControllerCtorState0Cleanup) },
    { 0, ((uint)&PlayerControllerCtorState1Cleanup) },
    { 0x1, ((uint)&PlayerControllerCtorState2Cleanup) },
    { 0x2, ((uint)&PlayerControllerCtorState3Cleanup) },
    { 0x3, ((uint)&PlayerControllerCtorState4Cleanup) },
    { 0x4, ((uint)&PlayerControllerCtorState5Cleanup) }
};

// R6Engine.dll data @ 10057f70 : playerControllerCtorInfo
// Retains exact pending base/member cleanup states without catches.
const NativeFunctionInfoPrefix playerControllerCtorInfo = { 0x19930520, 0x6, ((uint)&playerControllerCtorUnwind), 0, 0,
    0 };

// R6Engine.dll data @ 10057978 : voteSessionAbortUnwind
// State zero retains the event string cleanup; no catches are present.
const NativeUnwindEntry voteSessionAbortUnwind[1] = {
    { -1, ((uint)&VoteSessionAbortState0Cleanup) }
};

// R6Engine.dll data @ 10057980 : voteSessionAbortInfo
// State zero retains the event string cleanup; no catches are present.
const NativeFunctionInfoPrefix voteSessionAbortInfo = { 0x19930520, 0x1, ((uint)&voteSessionAbortUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1005799c : updateLadderStatUnwind
// State zero retains the event string cleanup; no catches are present.
const NativeUnwindEntry updateLadderStatUnwind[1] = {
    { -1, ((uint)&UpdateLadderStatState0Cleanup) }
};

// R6Engine.dll data @ 100579a4 : updateLadderStatInfo
// State zero retains the event string cleanup; no catches are present.
const NativeFunctionInfoPrefix updateLadderStatInfo = { 0x19930520, 0x1, ((uint)&updateLadderStatUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10074508 : intAR6PlayerControllerexecPlayVoicesPriority
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecPlayVoicesPriority = (Native)&AR6PlayerController::execPlayVoicesPriority;

// R6Engine.dll data @ 1008080c : AR6PlayerControllerPlayVoicesPriorityRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerPlayVoicesPriorityRegistrationResult = 0;

// R6Engine.dll data @ 1007450c : intAR6PlayerControllerexecGetLocStringWithActionKey
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecGetLocStringWithActionKey =
    (Native)&AR6PlayerController::execGetLocStringWithActionKey;

// R6Engine.dll data @ 1007831d : AR6PlayerControllerGetLocStringWithActionKeyRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerGetLocStringWithActionKeyRegistrationResult = 0;

// R6Engine.dll data @ 10074510 : intAR6PlayerControllerexecLocalizeTraining
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecLocalizeTraining = (Native)&AR6PlayerController::execLocalizeTraining;

// R6Engine.dll data @ 1007a1b0 : AR6PlayerControllerLocalizeTrainingRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerLocalizeTrainingRegistrationResult = 0;

// R6Engine.dll data @ 10074514 : intAR6PlayerControllerexecFindPlayer
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecFindPlayer = (Native)&AR6PlayerController::execFindPlayer;

// R6Engine.dll data @ 1007a6d1 : AR6PlayerControllerFindPlayerRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerFindPlayerRegistrationResult = 0;

// R6Engine.dll data @ 10074518 : intAR6PlayerControllerexecDebugFunction
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecDebugFunction = (Native)&AR6PlayerController::execDebugFunction;

// R6Engine.dll data @ 10082698 : AR6PlayerControllerDebugFunctionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerDebugFunctionRegistrationResult = 0;

// R6Engine.dll data @ 1007451c : intAR6PlayerControllerexecUpdateSpectatorReticule
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecUpdateSpectatorReticule =
    (Native)&AR6PlayerController::execUpdateSpectatorReticule;

// R6Engine.dll data @ 1007d4bc : AR6PlayerControllerUpdateSpectatorReticuleRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerUpdateSpectatorReticuleRegistrationResult = 0;

// R6Engine.dll data @ 10074520 : intAR6PlayerControllerexecUpdateReticule
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecUpdateReticule = (Native)&AR6PlayerController::execUpdateReticule;

// R6Engine.dll data @ 100773d0 : AR6PlayerControllerUpdateReticuleRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerUpdateReticuleRegistrationResult = 0;

// R6Engine.dll data @ 10074524 : intAR6PlayerControllerexecUpdateCircumstantialAction
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PlayerControllerexecUpdateCircumstantialAction =
    (Native)&AR6PlayerController::execUpdateCircumstantialAction;

// R6Engine.dll data @ 10079768 : AR6PlayerControllerUpdateCircumstantialActionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PlayerControllerUpdateCircumstantialActionRegistrationResult = 0;

// R6Engine.dll data @ 1007a1a0 : autoclassAR6PlayerController
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6PlayerController = nullptr;

// R6Engine.dll @ 10007bb0 : AR6PlayerController::eventClientPlayVoices
// Packs voice playback arguments and dispatches ClientPlayVoices through the cached ProcessEvent slot.
void __thiscall AR6PlayerController::eventClientPlayVoices(AR6SoundReplicationInfo* aAudioRepInfo, USound* sndPlayVoice,
    byte eSlotUse, int iPriority, uint bWaitToFinishSound, float fTime)
{
    struct VoiceParameters {
        AR6SoundReplicationInfo* aAudioRepInfo;
        USound* sndPlayVoice;
        byte eSlotUse;
        byte padding[3]; // Native leaves these bytes untouched.
        int iPriority;
        uint bWaitToFinishSound;
        float fTime;
    } parameters; // Inferred 24-byte packet at entryESP-0x18, with no initialization.
    AR6SoundReplicationInfo* capturedAudio = aAudioRepInfo;
    byte capturedSlot = eSlotUse;
    USound* capturedSound = sndPlayVoice;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    parameters.aAudioRepInfo = capturedAudio;
    int capturedPriority = iPriority;
    parameters.sndPlayVoice = capturedSound;
    uint capturedWait = bWaitToFinishSound;
    parameters.iPriority = capturedPriority;
    parameters.bWaitToFinishSound = capturedWait;
    FName eventName = R6ENGINE_ClientPlayVoices;
    parameters.eSlotUse = capturedSlot;
    uint timeWord = reinterpret_cast<uint&>(fTime);
    reinterpret_cast<uint&>(parameters.fTime) = timeWord; // Native raw DWORD transfer; no FPU conversion.
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &parameters, nullptr);
}

// R6Engine.dll @ 10007c10 : AR6PlayerController::eventGetZoomMultiplyFactor
// Dispatches the raw zoom input word and returns the float result slot initialized to zero.
float __thiscall AR6PlayerController::eventGetZoomMultiplyFactor(float fWeaponMaxZoom)
{
    FName eventName = R6ENGINE_GetZoomMultiplyFactor;
    uint inputWord = reinterpret_cast<uint&>(fWeaponMaxZoom);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    struct { uint weaponMaxZoomWord; float returnValue; } parameters;
    parameters.returnValue = 0.0f;
    parameters.weaponMaxZoomWord = inputWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &parameters, nullptr);
    return parameters.returnValue;
}

// R6Engine.dll @ 10007c60 : AR6PlayerController::eventPlayerTeamSelectionReceived
// Dispatches PlayerTeamSelectionReceived with null parameter and separate result pointers.
void __thiscall AR6PlayerController::eventPlayerTeamSelectionReceived(void)
{
    FName eventName = R6ENGINE_PlayerTeamSelectionReceived;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007cd0 : AR6PlayerController::eventPostRender
// Dispatches PostRender using the live incoming Canvas argument slot.
void __thiscall AR6PlayerController::eventPostRender(UCanvas* Canvas)
{
    FName eventName = R6ENGINE_PostRender;
    UCanvas* canvasWord = Canvas;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    Canvas = canvasWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &Canvas, nullptr);
}

// R6Engine.dll @ 10007d10 : AR6PlayerController::eventClientNotifySendStartMatch
// Dispatches ClientNotifySendStartMatch with null parameter and separate result pointers.
void __thiscall AR6PlayerController::eventClientNotifySendStartMatch(void)
{
    FName eventName = R6ENGINE_ClientNotifySendStartMatch;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007d40 : AR6PlayerController::eventClientNotifySendMatchResults
// Dispatches ClientNotifySendMatchResults with null parameter and separate result pointers.
void __thiscall AR6PlayerController::eventClientNotifySendMatchResults(void)
{
    FName eventName = R6ENGINE_ClientNotifySendMatchResults;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007d70 : AR6PlayerController::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6PlayerController::StaticClass(void)
{
    return &AR6PlayerController::PrivateStaticClass; // Selected object at0x1007b648.
}

// R6Engine.dll @ 10007d80 : AR6PlayerController::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6PlayerController::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6PlayerController::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000dcb0 : AR6PlayerController::eventClientVoteSessionAbort
// Assigns the string event parameter, dispatches its live packet, then destroys that string.
// Native ABI view retains receiver/string-address words for the reviewed R6Game caller.
void __thiscall AR6PlayerController::eventClientVoteSessionAbort( AR6PlayerController* this, const FString* _PlayerName)
{
    uint guard[3]; // Native previous-SEH/handler/state view; unwind uses the dispatcher-provided parent frame.
    guard[2] = 0xffffffff;
    guard[1] = ((uint)&VoteSessionAbortExceptionHandler);
    guard[0] = (uint)ExceptionList;
    ExceptionList = &guard[0];
    uint parameters[3]; // Only the leading 12 bytes are FString storage; remaining words are raw scalar slots.
    FString* stringParameter = (FString*)parameters;
    ::new (stringParameter) FString;
    const FString* sourceString = _PlayerName; // Sampled after default construction, before cleanup state0.
    guard[2] = 0;
    stringParameter->operator=(*sourceString);
    FName eventName = R6ENGINE_ClientVoteSessionAbort;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, parameters, nullptr);
    guard[2] = 0xffffffff;
    stringParameter->FString::~FString();
    ExceptionList = (void*)guard[0];
}

// R6Engine.dll @ 100434d0 : VoteSessionAbortState0Cleanup
// Tail-enters FString destruction on the event packet embedded in the inherited parent frame.
__declspec(naked) void __cdecl VoteSessionAbortState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp FStringDestructorNativeEntry
    }
}

// R6Engine.dll @ 1000dd40 : AR6PlayerController::eventClientUpdateLadderStat
// Assigns the string event parameter, dispatches its live packet, then destroys that string.
void __thiscall AR6PlayerController::eventClientUpdateLadderStat(const FString& _UserUbiID, int _iKillStat,
    int _iDeathStat, float fPlayTime)
{
    uint guard[3]; // Native previous-SEH/handler/state view; unwind uses the dispatcher-provided parent frame.
    guard[2] = 0xffffffff;
    guard[1] = ((uint)&UpdateLadderStatExceptionHandler);
    guard[0] = (uint)ExceptionList;
    ExceptionList = &guard[0];
    uint parameters[6]; // Only the leading 12 bytes are FString storage; remaining words are raw scalar slots.
    FString* stringParameter = (FString*)parameters;
    ::new (stringParameter) FString;
    const FString* sourceString = &_UserUbiID; // Sampled after default construction, before cleanup state0.
    guard[2] = 0;
    stringParameter->operator=(*sourceString);
    uint killWord = reinterpret_cast<uint&>(_iKillStat);
    uint deathWord = reinterpret_cast<uint&>(_iDeathStat);
    uint playTimeWord = reinterpret_cast<uint&>(fPlayTime);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    parameters[3] = killWord;
    parameters[4] = deathWord;
    FName eventName = R6ENGINE_ClientUpdateLadderStat;
    parameters[5] = playTimeWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, parameters, nullptr);
    guard[2] = 0xffffffff;
    stringParameter->FString::~FString();
    ExceptionList = (void*)guard[0];
}

// R6Engine.dll @ 100434f0 : UpdateLadderStatState0Cleanup
// Tail-enters FString destruction on the event packet embedded in the inherited parent frame.
__declspec(naked) void __cdecl UpdateLadderStatState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp FStringDestructorNativeEntry
    }
}

// R6Engine.dll @ 1000ec50 : AR6PlayerController::operator=
// Assigns base state, ordered scalar/bit fields, voice records and controller strings.
// Native ABI view preserves reuse of the incoming source-pointer word as a counter.
AR6PlayerController* __thiscall
AR6PlayerController::operator=(AR6PlayerController* this, AR6PlayerController* source)
{
    AR6PlayerController* const capturedSource = source;
    this->APlayerController::operator=(*capturedSource);
    byte* destinationBytes = reinterpret_cast<byte*>(this);
    byte* sourceBytes = reinterpret_cast<byte*>(capturedSource);
    for (uint offset = 0x7e8; offset < 0x7f2; ++offset)
        destinationBytes[offset] = sourceBytes[offset];
    for (uint offset = 0x7f4; offset < 0x81c; offset += 4)
        *(uint*)(destinationBytes + offset) = *(uint*)(sourceBytes + offset);
    uint word81c = *(uint*)(sourceBytes + 0x81c);
    uint flags = *(uint*)(destinationBytes + 0x838);
    reinterpret_cast<uint&>(this->m_iSpectatorYaw) = word81c;
    for (uint offset = 0x820; offset < 0x830; offset += 4)
        *(uint*)(destinationBytes + offset) = *(uint*)(sourceBytes + offset);
    uint word830 = *(uint*)(sourceBytes + 0x830);
    uint initialFlags = *(uint*)(destinationBytes + 0x838);
    reinterpret_cast<uint&>(this->m_iAdmin) = word830;
    reinterpret_cast<uint&>(this->m_iBanPage) = *(uint*)(sourceBytes + 0x834);
    flags ^= (initialFlags ^ *(uint*)(sourceBytes + 0x838)) & 1;
    *(uint*)(destinationBytes + 0x838) = flags;
    for (uint bit = 1; bit < 30; ++bit) {
        flags ^= (flags ^ *(uint*)(sourceBytes + 0x838)) & (1U << bit);
        *(uint*)(destinationBytes + 0x838) = flags;
    }
    flags ^= (flags ^ *(uint*)(sourceBytes + 0x838)) & 0x40000000;
    uint initialNextFlags = *(uint*)(destinationBytes + 0x83c);
    *(uint*)(destinationBytes + 0x838) = flags;
    uint sourceFlags = *(uint*)(sourceBytes + 0x838);
    uint sourceFlagsAgain = *(uint*)(sourceBytes + 0x838);
    uint nextFlags = *(uint*)(destinationBytes + 0x83c);
    *(uint*)(destinationBytes + 0x838) = sourceFlagsAgain ^ ((sourceFlags ^ flags) & 0x7fffffff);
    nextFlags ^= (initialNextFlags ^ *(uint*)(sourceBytes + 0x83c)) & 1;
    *(uint*)(destinationBytes + 0x83c) = nextFlags;
    for (uint bit = 1; bit < 10; ++bit) {
        nextFlags ^= (nextFlags ^ *(uint*)(sourceBytes + 0x83c)) & (1U << bit);
        *(uint*)(destinationBytes + 0x83c) = nextFlags;
    }
    for (uint offset = 0x840; offset < 0x8fc; offset += 4)
        *(uint*)(destinationBytes + offset) = *(uint*)(sourceBytes + offset);
    uint word8fc = *(uint*)(sourceBytes + 0x8fc);
    // Inferred view of the outgoing argument at entry ESP-0x14; it precedes the last scalar store.
    const FArray* voiceSourceArgument = reinterpret_cast<const FArray*>(&capturedSource->m_PlayVoicesPriority);
    reinterpret_cast<uint&>(this->m_pInteractingRainbow) = word8fc;
    AssignRecords4(reinterpret_cast<FArray*>(&this->m_PlayVoicesPriority), voiceSourceArgument);
    for (uint offset = 0x90c; offset < 0x9d8; offset += 4)
        *(uint*)(destinationBytes + offset) = *(uint*)(sourceBytes + offset);
    FString* banDestination = &this->m_BanPage.szBanID[0];
    FString* banSource = &capturedSource->m_BanPage.szBanID[0];
    uint& remaining = reinterpret_cast<uint&>(source); // Native reuses the incoming argument word at entry ESP+4.
    remaining = 10;
    uint next;
    do {
        banDestination->operator=(*banSource);
        next = remaining;
        banSource = (FString*)((byte*)banSource + 12);
        banDestination = (FString*)((byte*)banDestination + 12);
        remaining = --next;
    } while (next != 0);
    for (uint offset = 0xa50; offset < 0xa80; offset += 12)
        reinterpret_cast<FStringNoInit*>((byte*)this + offset)->operator=(
            *reinterpret_cast<const FStringNoInit*>((byte*)capturedSource + offset));
    for (uint offset = 0xa80; offset < 0xa8c; offset += 4)
        *(uint*)(destinationBytes + offset) = *(uint*)(sourceBytes + offset);
    reinterpret_cast<uint&>(this->m_fLastVoteEmoteTimeStamp) = *(uint*)(sourceBytes + 0xa8c);
    return this;
}

// R6Engine.dll @ 10010ce0 : AR6PlayerController::~AR6PlayerController
// Conditionally destroys UObject state, four strings, ten ban strings, voice storage and the base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6PlayerController::~AR6PlayerController(AR6PlayerController* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&PlayerControllerDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6PlayerControllerVirtualTable);
    guard[3] = 6;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 5;
    reinterpret_cast<FStringNoInit*>(&this->m_szBanSearch)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 4;
    reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 3;
    reinterpret_cast<FStringNoInit*>(&this->m_szMileStoneMessage)->FStringNoInit::~FStringNoInit();
    *(byte*)&guard[3] = 2;
    reinterpret_cast<FStringNoInit*>(&this->m_szLastAdminPassword)->FStringNoInit::~FStringNoInit();
    using DestroyString = void (__thiscall*)(FString*);
    // Sampled before state1 publication.
    DestroyString destroyString = reinterpret_cast<DestroyString&>(FStringDestructorImport);
    *(byte*)&guard[3] = 1;
    using DestroyArray = void (__stdcall*)(void*, uint, int, DestroyString);
    ((DestroyArray)((uint)&_eh_vector_destructor_iterator_))((byte*)this + 0x9d8, 12, 10, destroyString);
    *(byte*)&guard[3] = 0;
    DestroyWordArrayStorage((FArray*)&this->m_PlayVoicesPriority);
    guard[3] = 0xffffffff;
    this->APlayerController::~APlayerController();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10010db0 : AR6PlayerController::AR6PlayerController (native default view)
// Constructs the base, ten ordinary ban strings and four no-init strings without scalar/header initialization.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6PlayerController* __thiscall AR6PlayerController::AR6PlayerController(AR6PlayerController* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&PlayerControllerConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    APlayerController::APlayerController(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6PlayerControllerVirtualTable);
    using DestroyString = void (__thiscall*)(FString*);
    using ConstructString = void (__thiscall*)(FString*);
    DestroyString destroyString = reinterpret_cast<DestroyString&>(FStringDestructorImport);
    ConstructString constructString = reinterpret_cast<ConstructString&>(FStringDefaultConstructorImport);
    *(byte*)&guard[3] = 1; // The no-write voice-array lifetime precedes the fixed string list.
    using ConstructArray = void (__stdcall*)(void*, uint, int, ConstructString, DestroyString);
    ((ConstructArray)&_eh_vector_constructor_iterator_)((byte*)this + 0x9d8, 12, 10, constructString,
        destroyString);
    *(byte*)&guard[3] = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szLastAdminPassword);
    *(byte*)&guard[3] = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMileStoneMessage);
    *(byte*)&guard[3] = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_CharacterName);
    *(byte*)&guard[3] = 5;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szBanSearch);
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10010e60 : AR6PlayerController::AR6PlayerController (native copy view)
// Copies raw controller fields and individual flags, then constructs voice storage, ban strings and trailing strings.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6PlayerController* __thiscall AR6PlayerController::AR6PlayerController(
    AR6PlayerController* this, const AR6PlayerController* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&PlayerControllerConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    APlayerController::APlayerController(this, source);
    byte* output = (byte*)this;
    const byte* input = (const byte*)source;
    *(uint*)output = ((uint)&AR6PlayerControllerVirtualTable);
    for (uint offset = 0x7e8; offset != 0x7f2; ++offset)
        output[offset] = input[offset];
    for (uint offset = 0x7f4; offset != 0x830; offset += 4)
        *(uint*)(output + offset) = *(const uint*)(input + offset);
    uint lastScalar = *(const uint*)(input + 0x830);
    uint earlyFlags = *(uint*)(output + 0x838);
    *(uint*)(output + 0x830) = lastScalar;
    *(uint*)(output + 0x834) = *(const uint*)(input + 0x834);
    uint difference = (earlyFlags ^ *(const uint*)(input + 0x838)) & 1U;
    uint flags = *(uint*)(output + 0x838) ^ difference;
    *(uint*)(output + 0x838) = flags;
    flags ^= (*(const uint*)(input + 0x838) ^ flags) & 2U;
    *(uint*)(output + 0x838) = flags;
    uint thirdSourceFlags = *(const uint*)(input + 0x838);
    guard[3] = 0; // Native activates base cleanup after this third flag read, before publishing bit2.
    flags ^= (thirdSourceFlags ^ flags) & 4U;
    *(uint*)(output + 0x838) = flags;
    for (uint bit = 3; bit != 31; ++bit) {
        flags ^= (*(const uint*)(input + 0x838) ^ flags) & (1U << bit);
        *(uint*)(output + 0x838) = flags;
    }
    uint highSourceFirst = *(const uint*)(input + 0x838);
    uint highSourceSecond = *(const uint*)(input + 0x838);
    uint highDifference = (highSourceFirst ^ flags) & 0x7fffffffU;
    uint secondEarlyFlags = *(uint*)(output + 0x83c); // Captured before the first flag word's final store.
    *(uint*)(output + 0x838) = highDifference ^ highSourceSecond;
    difference = (secondEarlyFlags ^ *(const uint*)(input + 0x83c)) & 1U;
    flags = *(uint*)(output + 0x83c) ^ difference;
    *(uint*)(output + 0x83c) = flags;
    for (uint bit = 1; bit != 10; ++bit) {
        flags ^= (*(const uint*)(input + 0x83c) ^ flags) & (1U << bit);
        *(uint*)(output + 0x83c) = flags;
    }
    for (uint offset = 0x840; offset != 0x900; offset += 4)
        *(uint*)(output + offset) = *(const uint*)(input + offset);
    CopyConstructRecords4((FArray*)(output + 0x900), (const FArray*)(input + 0x900));
    for (uint offset = 0x90c; offset != 0x928; offset += 4)
        *(uint*)(output + offset) = *(const uint*)(input + offset);
    uint delayedVectorY = *(const uint*)(input + 0x928);
    *(byte*)&guard[3] = 1; // Voice-array cleanup activates between this vector component's read and store.
    *(uint*)(output + 0x928) = delayedVectorY;
    for (uint offset = 0x92c; offset != 0x9d0; offset += 4)
        *(uint*)(output + offset) = *(const uint*)(input + offset);
    uint vectorZ = *(const uint*)(input + 0x9d0);
    using DestroyString = void (__thiscall*)(FString*);
    DestroyString destroyString = reinterpret_cast<DestroyString&>(FStringDestructorImport);
    *(uint*)(output + 0x9d0) = vectorZ;
    using CopyString = void (__thiscall*)(FString*, const FString*);
    CopyString copyString = reinterpret_cast<CopyString&>(FStringCopyConstructorImport);
    uint finalWord = *(const uint*)(input + 0x9d4);
    *(uint*)(output + 0x9d4) = finalWord;
    using CopyArray = void (__stdcall*)(void*, const void*, uint, int, CopyString, DestroyString);
    ((CopyArray)&_eh_vector_copy_constructor_iterator_)(output + 0x9d8, input + 0x9d8, 12, 10, copyString,
        destroyString);
    *(byte*)&guard[3] = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szLastAdminPassword,
        (const FStringNoInit*)&source->m_szLastAdminPassword);
    *(byte*)&guard[3] = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMileStoneMessage,
        (const FStringNoInit*)&source->m_szMileStoneMessage);
    *(byte*)&guard[3] = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_CharacterName,
        (const FStringNoInit*)&source->m_CharacterName);
    *(byte*)&guard[3] = 5;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szBanSearch, (const FStringNoInit*)&source->m_szBanSearch);
    *(uint*)(output + 0xa80) = *(const uint*)(input + 0xa80);
    *(uint*)(output + 0xa84) = *(const uint*)(input + 0xa84);
    uint trailingWord = *(const uint*)(input + 0xa88);
    void* previousChain = (void*)guard[1];
    *(uint*)(output + 0xa88) = trailingWord;
    *(uint*)(output + 0xa8c) = *(const uint*)(input + 0xa8c);
    ExceptionList = previousChain;
    return this;
}

// R6Engine.dll @ 10013a40 : AR6PlayerController::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6PlayerController::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6PlayerControllerConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1002fce0 : AR6PlayerController::execDebugFunction
// Consumes the terminator and optional debug record, then logs DebugFunction through the current output device.
void __thiscall AR6PlayerController::execDebugFunction(FFrame& stack, void* unusedResult)
{
    // Descriptive native frame view: saved ESP is EBP-10; caught/rethrow words are EBP-18/EBP-14.
    struct ScriptGuardFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &DebugFunctionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    bool hasDebugRecord = *code == 0x42;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0; // The cursor update and debug-byte read precede catch state 0.
    if (hasDebugRecord) {
        UObject* receiver = stack.Object;
        *codeCursor = code + 1;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, &stack, nullptr);
    }
    FOutputDevice** logSlot = *(FOutputDevice***)&CoreGLogImport;
    FOutputDevice* output = *logSlot;
    output->FOutputDevice::Logf((const ushort*)L"DebugFunction");
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1002fd56 : DebugFunctionCatchPointer
// Rethrows the caught text pointer through the parent's EBP-14 slot.
__declspec(naked) __declspec(noreturn) void __cdecl DebugFunctionCatchPointer(void)
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

// R6Engine.dll @ 1002fd6a : DebugFunctionCatchContext
// Reports the native method context and forwards the active exception without a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl DebugFunctionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecDebugFunction
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002fd90 : AR6PlayerController::execUpdateCircumstantialAction
// Consumes the terminator and optional debug record, then dispatches the current virtual action update.
void __thiscall AR6PlayerController::execUpdateCircumstantialAction(FFrame& stack, void* unusedResult)
{
    // Descriptive native frame view: saved ESP is EBP-10; caught/rethrow words are EBP-18/EBP-14.
    struct ScriptGuardFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &UpdateCircumstantialActionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    bool hasDebugRecord = *code == 0x42;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0; // The cursor update and debug-byte read precede catch state 0.
    if (hasDebugRecord) {
        UObject* receiver = stack.Object;
        *codeCursor = code + 1;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, &stack, nullptr);
    }
    this->UpdateCircumstantialAction();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1002fdfb : UpdateCircumstantialActionCatchPointer
// Rethrows the caught text pointer through the parent's EBP-14 slot.
__declspec(naked) __declspec(noreturn) void __cdecl UpdateCircumstantialActionCatchPointer(void)
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

// R6Engine.dll @ 1002fe0f : UpdateCircumstantialActionCatchContext
// Reports the native method context and forwards the active exception without a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl UpdateCircumstantialActionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecUpdateCircumstantialAction
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002fe30 : AR6PlayerController::UpdateReticuleIdentification
// Queries eligible non-self targets and sends their name and raw result to the cached weapon.
void __thiscall AR6PlayerController::UpdateReticuleIdentification(AActor* target)
{
    struct ReticuleFrame { // Inferred native EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        uint nameWords[3]; // FString at EBP-0x24..-0x1c.
        uint caughtText, rethrowText; // EBP-0x18/-0x14.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ReticuleIdentificationExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FString* targetName = (FString*)nativeFrame.nameWords;
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    nativeFrame.exceptionState = 0;
    ::new (targetName) FString;
    AActor* currentTarget = target; // Native reads the incoming target before the pawn/weapon fields.
    AR6Pawn* pawn = this->m_pawn;
    AR6EngineWeapon* weapon = pawn->EngineWeapon;
    *(byte*)&nativeFrame.exceptionState = 1; // Cleanup starts only after the weapon fetch.
    uint identification = 0;
    if (currentTarget != nullptr &&
        (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(currentTarget) + 0xa4) & 0x800U) != 0) {
        APawn* ownerReticule = this->Pawn;
        if (currentTarget != ownerReticule) {
            identification = currentTarget->AActor::eventGetReticuleInfo(ownerReticule, *targetName);
        }
    }
    weapon->AR6EngineWeapon::eventSetIdentifyTarget(identification, identification, *targetName);
    *(byte*)&nativeFrame.exceptionState = 0;
    targetName->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1002fecd : forward the caught reticule-identification pointer
__declspec(naked) void ReticuleIdentificationCatchPointer(void)
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

// R6Engine.dll @ 1002fee1 : report reticule context and forward the active exception
__declspec(naked) void ReticuleIdentificationCatchContext(void)
{
    __asm {
        // L"AR6PlayerController::UpdateReticuleIdentification".
        push offset nativeTextAR6PlayerControllerUpdateReticuleIdentification
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044820 : destroy the reticule name through the inherited parent frame
__declspec(naked) void ReticuleIdentificationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044829 : select the reticule-identification exception tables
__declspec(naked) void ReticuleIdentificationExceptionHandler(void)
{
    __asm {
        mov eax,offset ReticuleIdentificationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002ff00 : AR6PlayerController::PreNetReceive
// Saves the current team BYTE in the module snapshot before the base receive hook.
void __thiscall AR6PlayerController::PreNetReceive(void)
{
    struct ReceiveFrame { // Inferred native EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caughtText, rethrowText; // EBP-0x18/-0x14.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &PlayerPreNetReceiveExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte teamSelection = this->m_TeamSelection; // This read precedes state zero.
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    nativeFrame.exceptionState = 0;
    PreNetTeamSelection = teamSelection;
    this->APlayerController::PreNetReceive();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1002ff4a : forward the caught pre-receive pointer
__declspec(naked) void PlayerPreNetReceiveCatchPointer(void)
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

// R6Engine.dll @ 1002ff5e : report pre-receive context and forward the active exception
__declspec(naked) void PlayerPreNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerPreNetReceive // L"AR6PlayerController::PreNetReceive".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044840 : select the pre-receive exception tables
__declspec(naked) void PlayerPreNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset PlayerPreNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10030260 : AR6PlayerController::GetTeamManager
// Returns the current team-manager actor from the +0x8ac member.
AActor* __thiscall AR6PlayerController::GetTeamManager(void)
{
    return this->m_TeamManager;
}

// R6Engine.dll @ 10030270 : AR6PlayerController::GetLocKeyNameByActionKey
// Builds a localized key name through the player's input and console, then copies it into the hidden return object.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FString* __thiscall AR6PlayerController::GetLocKeyNameByActionKey(FString* result, const ushort* actionKey)
{
    // Descriptive ESP-relative frame view; dispatcher EBP corresponds to the entry ESP, not a saved caller EBP.
    struct KeyLocalizationFrame {
        uint savedEDI, savedESI, constructedResultFlags;
        uint localizedTextStorage[3], enumKeyNameStorage[3], convertedTextStorage[3];
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &KeyLocalizationExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    nativeFrame.constructedResultFlags = 0;
    FString* localizedText = (FString*)nativeFrame.localizedTextStorage;
    FString* enumKeyName = (FString*)nativeFrame.enumKeyNameStorage;
    FString* convertedText = (FString*)nativeFrame.convertedTextStorage;
    byte& state = *(byte*)&nativeFrame.exceptionState;
    ::new (localizedText) FString;
    // Player is read before the first string's state becomes active.
    UPlayer* viewport = this->Player;
    nativeFrame.exceptionState = 1;
    if (viewport != nullptr) {
        UClass* viewportClass = viewport->Class;
        UClass* requiredViewportClass = UViewportPrivateStaticClassImport;
        while (viewportClass != nullptr && viewportClass != requiredViewportClass)
            viewportClass = viewportClass->GetSuperClass();
        if (viewportClass == requiredViewportClass) {
            // Input pointer words retain their partial native viewport view.
            const byte* viewportBytes = reinterpret_cast<const byte*>(viewport);
            void* actionInput = *reinterpret_cast<void* const*>(viewportBytes + 0x84);
            if (actionInput != nullptr) {
                const ushort* currentActionKey = actionKey;
                byte* inputTable = *(byte**)actionInput;
                using GetKey = byte (__thiscall*)(void*, const ushort*);
                byte keyCode = (*(GetKey*)(inputTable + 0x88))(actionInput, currentActionKey);
                void* keyNameInput = *reinterpret_cast<void* const*>(viewportBytes + 0x88);
                byte* keyNameTable = *(byte**)keyNameInput;
                // Native reuses the low byte of the incoming pointer word at entry ESP+8.
                reinterpret_cast<byte&>(actionKey) = keyCode;
                using GetKeyName = const ushort* (__thiscall*)(void*, uint);
                const ushort* keyNameText = (*(GetKeyName*)(keyNameTable + 0x80))(keyNameInput, (uint)keyCode);
                ::new (enumKeyName) FString(keyNameText);
                uint conversionKeyWord = reinterpret_cast<uint&>(actionKey);
                UPlayer* currentPlayer = this->Player;
                UInteraction* console = currentPlayer->Console;
                state = 2;
                // Raw-word view of the native BYTE argument: upper bytes retain the old incoming pointer word.
                using ConvertKeyRaw = FString* (__thiscall*)(UInteraction*, FString*, uint, const FString*);
                FString* returnedText =
                    reinterpret_cast<ConvertKeyRaw&>(UInteractionEventConvertKeyToLocalisationImport)(console,
                        convertedText,
                    conversionKeyWord, enumKeyName);
                state = 3;
                localizedText->operator=(*returnedText);
                state = 2;
                convertedText->FString::~FString();
                state = 1;
                enumKeyName->FString::~FString();
            }
        }
    }
    FString* returnObject = result; // Captured before the copy constructor and retained through final destruction.
    ::new (returnObject) FString(*localizedText);
    nativeFrame.constructedResultFlags = 1;
    state = 0;
    localizedText->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
    return returnObject;
}

// R6Engine.dll @ 100303b0 : AR6PlayerController::execFindPlayer
// Finds the first concrete player controller by name or a nonzero parse/format-validated ID.
void __thiscall AR6PlayerController::execFindPlayer(FFrame& stack, void* resultController)
{
    struct FindPlayerFrame { // Inferred native EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x40/-0x3c/-0x38.
        uint canonicalWords[3], identifierWords[3]; // FString headers at EBP-0x34/-0x28.
        uint caughtText, rethrowText, isIdWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &FindPlayerExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FString* inPlayerIdent = (FString*)nativeFrame.identifierWords;
    FString* canonicalId = (FString*)nativeFrame.canonicalWords;
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    nativeFrame.exceptionState = 0;
    ::new (inPlayerIdent) FString;
    FFrame* expressionStack = &stack; // Incoming Frame is captured only after construction.
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    byte opcode = *code;
    UObject* receiver = expressionStack->Object;
    expressionStack->Code = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    *(byte*)&nativeFrame.exceptionState = 1;
    natives[opcode](receiver, expressionStack, inPlayerIdent);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    nativeFrame.isIdWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &nativeFrame.isIdWord);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    ::new (canonicalId) FString;
    uint bIsIdInt = nativeFrame.isIdWord; // The mode read precedes the byte-only state change.
    *(byte*)&nativeFrame.exceptionState = 2;
    APlayerController* foundPlayer = nullptr;
    auto isR6PlayerController = [](AController* candidate) {
        UClass* type = candidate->Class;
        while (type != nullptr) {
            if (type == &AR6PlayerController::PrivateStaticClass)
                return true;
            type = type->GetSuperClass();
        }
        return false;
    };
    if (bIsIdInt != 0) {
        const ushort* identifierText = inPlayerIdent->operator*();
        uint playerId = (uint)appAtoi(identifierText);
        if (playerId != 0) {
            ushort* canonicalText = appItoa((int)playerId);
            canonicalId->operator=(canonicalText);
            if (inPlayerIdent->operator!=(*canonicalId) == 0) {
                AController* candidate = this->Level->ControllerList;
                while (candidate != nullptr) {
                    if (isR6PlayerController(candidate)) {
                        APlayerReplicationInfo* info = candidate->PlayerReplicationInfo;
                        if ((uint)info->PlayerID == playerId) {
                            foundPlayer = reinterpret_cast<APlayerController*>(CastToAPlayerController((int)candidate));
                            break; // The first matching ID terminates the search even if the cast rejects it.
                        }
                    }
                    candidate = candidate->nextController;
                }
            }
        }
    } else {
        AController* candidate = this->Level->ControllerList;
        using CompareNames = int (__cdecl*)(const ushort*, const ushort*);
        // Captured even for an empty list; retained across callbacks.
        CompareNames compare = reinterpret_cast<CompareNames&>(CoreAppStricmpImport);
        while (candidate != nullptr) {
            if (isR6PlayerController(candidate)) {
                const ushort* identifierText = inPlayerIdent->operator*();
                APlayerReplicationInfo* info = candidate->PlayerReplicationInfo;
                const FString* name = &info->PlayerName;
                const ushort* playerName = name->operator*();
                if (compare(playerName, identifierText) == 0) {
                    UClass* type = candidate->Class;
                    UClass* required = APlayerControllerPrivateStaticClassImport;
                    while (type != nullptr && type != required)
                        type = type->GetSuperClass();
                    if (type == required) // An exhausted chain also matches a null required class.
                        foundPlayer = static_cast<APlayerController*>(candidate);
                    break;
                }
            }
            candidate = candidate->nextController; // Read after text/comparison callbacks.
        }
    }
    // Incoming result slot is read only at this point.
    *reinterpret_cast<APlayerController**>(resultController) = foundPlayer;
    *(byte*)&nativeFrame.exceptionState = 1;
    canonicalId->FString::~FString();
    *(byte*)&nativeFrame.exceptionState = 0;
    inPlayerIdent->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 100305bc : forward the caught player-search pointer through its inherited frame
__declspec(naked) void FindPlayerCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100305d0 : report player-search context and forward the active exception
__declspec(naked) void FindPlayerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecFindPlayer // L"AR6PlayerController::execFindPlayer".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100448c0 : destroy the identifier through the inherited parent frame
__declspec(naked) void FindPlayerState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100448c9 : destroy the canonical ID through the inherited parent frame
__declspec(naked) void FindPlayerState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100448d2 : select the player-search exception tables without creating a frame
__declspec(naked) void FindPlayerExceptionHandler(void)
{
    __asm {
        mov eax,offset FindPlayerFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100305f0 : AR6PlayerController::UpdateSpectatorReticule
// Traces the spectator view ray and copies the hit pawn's display name, clearing it when no pawn is available.
void __thiscall AR6PlayerController::UpdateSpectatorReticule(void)
{
    struct SpectatorFrame { // Inferred native EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x98/-0x94/-0x90.
        NativeCheckResult32 hitWords; // FCheckResult at EBP-0x8c..-0x60.
        uint returnedWords[3], temporaryWords[3]; // EBP-0x5c/-0x50; returned direction storage becomes eye output.
        uint endWords[3], directionWords[3], startWords[3]; // EBP-0x44/-0x38/-0x2c.
        uint caughtText, rethrowText; // EBP-0x20/-0x1c.
        float product18, product14;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &SpectatorReticuleExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    uint playerFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x524);
    bool cheatFlying = (playerFlags & 0x20000U) != 0; // Both load and test precede state zero.
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    nativeFrame.exceptionState = 0;
    float* direction = (float*)nativeFrame.directionWords;
    float* start = (float*)nativeFrame.startWords;
    float* temporary = (float*)nativeFrame.temporaryWords;
    uint endX, endY, endZ;
    if (cheatFlying) {
        FVector* returned = &(*(FVector*)nativeFrame.temporaryWords = this->Rotation.Vector());
        float10 distance = (float10)this->m_fTeamMoveToDistance;
        uint dx = ((uint*)returned)[0];
        uint dy = ((uint*)returned)[1];
        uint dz = ((uint*)returned)[2];
        nativeFrame.directionWords[2] = dz;
        float10 deltaZ = (float10)direction[2] * distance;
        nativeFrame.directionWords[1] = dy;
        nativeFrame.directionWords[0] = dx;
        uint originX = reinterpret_cast<uint&>(this->Location.X);
        nativeFrame.product14 = (float)deltaZ;
        float10 deltaY = (float10)direction[1];
        uint originY = reinterpret_cast<uint&>(this->Location.Y);
        uint originZ = reinterpret_cast<uint&>(this->Location.Z);
        deltaY *= distance;
        nativeFrame.startWords[2] = originZ;
        nativeFrame.startWords[1] = originY;
        nativeFrame.product18 = (float)deltaY;
        nativeFrame.startWords[0] = originX;
        float10 deltaX = (float10)direction[0] * distance;
        temporary[0] = (float)deltaX;
        float10 sumZ = (float10)start[2] + nativeFrame.product14;
        float10 sumY = (float10)start[1] + nativeFrame.product18;
        float10 sumX = (float10)start[0] + temporary[0];
        direction[0] = (float)sumX; // Cheat path reuses the direction storage for endpoint words.
        endX = nativeFrame.directionWords[0];
        direction[1] = (float)sumY;
        endY = nativeFrame.directionWords[1];
        direction[2] = (float)sumZ;
        endZ = nativeFrame.directionWords[2];
    } else {
        AActor* initialTarget = this->ViewTarget;
        bool hasView = false;
        if (initialTarget != nullptr) {
            hasView = initialTarget->GetPlayerPawn() != nullptr;
        }
        if (!hasView) {
            reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->operator=(nativeEmptyText);
            ExceptionList = nativeFrame.previousExceptionList;
            return;
        }
        // Fresh member; the gate's returned pawn is not used.
        APawn* viewPawn = reinterpret_cast<APawn*>(this->ViewTarget);
        // Physical hidden-result call retains its supplied buffer and returned EAX pointer.
        FRotator* rotation = viewPawn->GetViewRotation((FRotator*)nativeFrame.temporaryWords);
        FVector* returned = &(*(FVector*)nativeFrame.returnedWords = rotation->Vector());
        uint dx = ((uint*)returned)[0];
        uint dy = ((uint*)returned)[1];
        uint dz = ((uint*)returned)[2];
        nativeFrame.directionWords[0] = dx;
        nativeFrame.directionWords[1] = dy;
        nativeFrame.directionWords[2] = dz;
        using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
        FVector* eye = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(viewPawn,
            (FVector*)nativeFrame.returnedWords);
        float10 originZ = (float10)eye->Z + viewPawn->Location.Z;
        float10 originY = (float10)eye->Y + viewPawn->Location.Y;
        float10 originX = (float10)eye->X + viewPawn->Location.X;
        temporary[0] = (float)originX;
        nativeFrame.startWords[0] = nativeFrame.temporaryWords[0];
        temporary[1] = (float)originY;
        nativeFrame.startWords[1] = nativeFrame.temporaryWords[1];
        temporary[2] = (float)originZ;
        uint originZWord = nativeFrame.temporaryWords[2];
        float10 distance = (float10)this->m_fTeamMoveToDistance;
        nativeFrame.startWords[2] = originZWord;
        float10 deltaZ = (float10)direction[2] * distance;
        nativeFrame.product18 = (float)deltaZ;
        float10 deltaY = (float10)direction[1] * distance;
        nativeFrame.product14 = (float)deltaY;
        float10 deltaX = distance * (float10)direction[0];
        temporary[0] = (float)deltaX;
        float10 sumZ = (float10)start[2] + nativeFrame.product18;
        float10 sumY = (float10)start[1] + nativeFrame.product14;
        float10 sumX = (float10)temporary[0] + start[0];
        temporary[0] = (float)sumX;
        endX = nativeFrame.temporaryWords[0];
        temporary[1] = (float)sumY;
        endY = nativeFrame.temporaryWords[1];
        temporary[2] = (float)sumZ;
        endZ = nativeFrame.temporaryWords[2];
    }
    nativeFrame.endWords[1] = endY;
    const uint* zeroExtent = *(const uint**)&FVectorFVector0Import;
    nativeFrame.endWords[2] = endZ;
    ULevel* level = this->XLevel;
    nativeFrame.endWords[0] = endX;
    for (int i = 0; i < 9; ++i)
        reinterpret_cast<uint*>(&nativeFrame.hitWords)[i] = 0;
    reinterpret_cast<uint&>(nativeFrame.hitWords.Time) = 0x3f800000; // Time.
    reinterpret_cast<uint&>(nativeFrame.hitWords.Item) = 0xffffffff; // Item.
    nativeFrame.hitWords.materialAddress = 0;
    uint extentWords[3];
    extentWords[0] = zeroExtent[0];
    byte* levelTable = *(byte**)level;
    extentWords[1] = zeroExtent[1];
    extentWords[2] = zeroExtent[2];
    APawn* ignoredPawn = this->Pawn;
    using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint,
        FVector);
    (*(SingleLineCheck*)(levelTable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&nativeFrame.hitWords), ignoredPawn,
        (FVector*)nativeFrame.endWords, (FVector*)nativeFrame.startWords, 0x210bf, *(FVector*)extentWords);
    AActor* hitActor =
        // The trace's integer return does not gate this path.
        reinterpret_cast<AActor*>(nativeFrame.hitWords.actorAddress);
    APawn* hitPawn = nullptr;
    if (hitActor != nullptr) {
        hitPawn = hitActor->GetPawnOrColBoxOwner();
    }
    if (hitPawn != nullptr) {
        APlayerReplicationInfo* info = hitPawn->PlayerReplicationInfo;
        const FStringNoInit* name = info != nullptr ? (const FStringNoInit*)&info->PlayerName :
            (const FStringNoInit*)&hitPawn->m_CharacterName;
        reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->operator=(*name);
    } else {
        reinterpret_cast<FStringNoInit*>(&this->m_CharacterName)->operator=(nativeEmptyText);
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10030880 : forward the caught spectator-reticule pointer through the inherited frame
__declspec(naked) void SpectatorReticuleCatchPointer(void)
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

// R6Engine.dll @ 10030894 : report spectator-reticule context and forward the active exception
__declspec(naked) void SpectatorReticuleCatchContext(void)
{
    __asm {
        // L"AR6PlayerController::UpdateSpectatorReticule".
        push offset nativeTextAR6PlayerControllerUpdateSpectatorReticule
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100448e0 : select the spectator-reticule exception tables without creating a frame
__declspec(naked) void SpectatorReticuleExceptionHandler(void)
{
    __asm {
        mov eax,offset SpectatorReticuleFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100308c0 : AR6PlayerController::UpdateCircumstantialAction
// Traces the view target, updates identification, and queries an actor or a walkable destination for actions.
void __thiscall AR6PlayerController::UpdateCircumstantialAction(void)
{
    struct ActionFrame { // Inferred native EBP-relative storage; the local region includes both trace packets.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xd8/-0xd4/-0xd0.
        byte localStorage[0xbc]; // EBP-0xcc..-0x11, including caught pointer -0xc0 and rethrow word -0x80.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    byte* frameTop = (byte*)&nativeFrame + 0xd8;
    AR6AbstractCircumstantialActionQuery*& query =
        *reinterpret_cast<AR6AbstractCircumstantialActionQuery**>(frameTop - 0x14);
    AR6PlayerController*& savedReceiver = *reinterpret_cast<AR6PlayerController**>(frameTop - 0x24);
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &CircumstantialActionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte initialRole = this->Role;
    AR6AbstractCircumstantialActionQuery* initialQuery = this->m_CurrentCircumstantialAction;
    bool authority = initialRole == 4; // Role read/comparison precedes state zero and the shared query-slot store.
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    savedReceiver = this;
    nativeFrame.exceptionState = 0;
    query = initialQuery;
    if (authority) {
        initialQuery->iHasAction = 0;
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(query) + 0x3b4) &= ~1U; // bCanBeInterrupted.
        reinterpret_cast<uint&>(query->fPlayerActionTimeRequired) = 0;
        query->iMenuChoice = -1;
        query->iSubMenuChoice = -1;
    }
    // bOnlySpectator or bCheatFlying.
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x524) & 0x24000U) != 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    FVector& direction = *(FVector*)(frameTop - 0x4c);
    FVector& start = *(FVector*)(frameTop - 0x40);
    FVector& end = *(FVector*)(frameTop - 0x8c);
    FCheckResult& hit = *(FCheckResult*)(frameTop - 0x7c);
    FVector& vectorScratch = *(FVector*)(frameTop - 0x30);
    uint* directionWords = (uint*)&direction;
    if (this->m_wAutoAim != 0 && this->m_targetedPawn != nullptr) {
        APawn* pawn = this->Pawn;
        float10 towardZ = (float10)this->m_vAutoAimTarget.Z - pawn->m_vEyeLocation.Z;
        float10 towardY = (float10)this->m_vAutoAimTarget.Y - pawn->m_vEyeLocation.Y;
        float10 towardX = (float10)this->m_vAutoAimTarget.X - pawn->m_vEyeLocation.X;
        vectorScratch.X = (float)towardX;
        vectorScratch.Y = (float)towardY;
        vectorScratch.Z = (float)towardZ;
        FVector* normalized = &(*(FVector*)(frameTop - 0xcc) = vectorScratch.GetNormalized());
        uint x = ((uint*)normalized)[0];
        uint y = ((uint*)normalized)[1];
        uint z = ((uint*)normalized)[2];
        directionWords[0] = x;
        directionWords[1] = y;
        directionWords[2] = z;
    } else {
        APawn* pawn = this->Pawn;
        // Physical hidden-result call retains its supplied buffer and returned EAX pointer.
        FRotator* rotation = pawn->GetViewRotation((FRotator*)(frameTop - 0xcc));
        FVector* returned = &(vectorScratch = rotation->Vector());
        uint x = ((uint*)returned)[0];
        uint y = ((uint*)returned)[1];
        directionWords[0] = x; // Native stores X before reading the returned Z word.
        uint z = ((uint*)returned)[2];
        directionWords[1] = y;
        directionWords[2] = z;
    }
    APawn* eyePawn = this->Pawn;
    using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
    FVector* eyeOffset = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(eyePawn,
        (FVector*)(frameTop - 0xcc));
    APawn* tracePawn = this->Pawn;
    float10 liveStartZ = (float10)tracePawn->Location.Z;
    ULevel* traceLevel = this->XLevel;
    liveStartZ += eyeOffset->Z;
    float10 liveStartY = (float10)tracePawn->Location.Y + eyeOffset->Y;
    float& roundedStartY = *(float*)(frameTop - 0x34);
    roundedStartY = (float)liveStartY;
    float10 liveStartX = (float10)tracePawn->Location.X + eyeOffset->X;
    uint* hitWords = (uint*)&hit;
    hitWords[10] = 0xffffffff; // Item is initialized before the other hit fields.
    hitWords[0] = 0;
    start.X = (float)liveStartX;
    hitWords[1] = 0;
    hitWords[2] = 0;
    start.Y = (float)liveStartY;
    hitWords[3] = 0;
    hitWords[4] = 0;
    start.Z = (float)liveStartZ; // The live extended value also survives for endpoint Z.
    hitWords[5] = 0;
    float10 distance = (float10)this->m_fTeamMoveToDistance;
    const uint* zeroExtent = *(const uint**)&FVectorFVector0Import;
    float10 deltaZ = (float10)direction.Z;
    hitWords[6] = 0;
    deltaZ *= distance;
    hitWords[7] = 0;
    hitWords[8] = 0;
    hitWords[9] = 0x3f800000; // Time.
    float& roundedDeltaZ = *(float*)(frameTop - 0x1c);
    roundedDeltaZ = (float)deltaZ;
    hitWords[11] = 0;
    float10 deltaY = (float10)direction.Y * distance;
    float& roundedDeltaY = *(float*)(frameTop - 0x18);
    roundedDeltaY = (float)deltaY;
    float10 deltaX = (float10)direction.X * distance;
    vectorScratch.X = (float)deltaX;
    float10 endZ = liveStartZ + roundedDeltaZ;
    float10 endY = (float10)roundedDeltaY + roundedStartY;
    float10 endX = (float10)vectorScratch.X + start.X;
    end.X = (float)endX;
    end.Y = (float)endY;
    end.Z = (float)endZ;
    uint extentWords[3];
    extentWords[0] = zeroExtent[0];
    byte* levelTable = *(byte**)traceLevel;
    extentWords[1] = zeroExtent[1];
    extentWords[2] = zeroExtent[2];
    using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint,
        FVector);
    SingleLineCheck trace = *(SingleLineCheck*)(levelTable + 0xcc);
    trace(traceLevel, &hit, tracePawn, &end, &start, 0xa10bf, *(FVector*)extentWords);
    AActor* firstHitActor = hit.Actor;
    uint& walkable = *(uint*)(frameTop - 0x18); // Product spills become the classification flags after tracing.
    uint& suppressQuery = *(uint*)(frameTop - 0x1c);
    walkable = 0;
    suppressQuery = 0;
    auto matchesType = [](UClass* type, UClass* required) {
        while (type != nullptr && type != required)
            type = type->GetSuperClass();
        return type == required;
    };
    AR6PlayerController* actionController;
    if (firstHitActor != nullptr) {
        int item = hit.Item;
        bool isModelHit = false;
        if (item != -1) {
            UClass* type = firstHitActor->Class;
            UClass* required = ALevelInfoPrivateStaticClassImport;
            isModelHit = matchesType(type, required);
        }
        if (isModelHit) {
            actionController = savedReceiver;
            ULevel* currentLevel = actionController->XLevel;
            byte* model = *(byte**)((byte*)currentLevel + 0x90);
            byte* nodes = *(byte**)(model + 0x5c);
            byte* surfaces = *(byte**)(model + 0x9c);
            uint nodeAddress = (uint)nodes + (uint)item * 0x90U;
            uint surfaceIndex = *(uint*)(nodeAddress + 0x34U);
            uint surfaceAddress = (uint)surfaces + surfaceIndex * 0x5cU;
            uint surfaceWalkable = *(byte*)(surfaceAddress + 0x58U);
            uint surfaceSuppression = *(byte*)(surfaceAddress + 0x50U);
            walkable = surfaceWalkable;
            suppressQuery = surfaceSuppression;
        } else {
            UClass* type = firstHitActor->Class;
            UClass* required = AStaticMeshActorPrivateStaticClassImport;
            if (matchesType(type, required))
                walkable = (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(firstHitActor) + 0xac) >> 22) & 1U;
            actionController = savedReceiver;
        }
    } else {
        actionController = savedReceiver;
    }
    AActor* actionActor = firstHitActor;
    uint& defaultFallbackWord = *(uint*)(frameTop - 0x20);
    defaultFallbackWord = 0;
    // Former rounded-Y spill becomes the actor fallback slot.
    AActor*& savedActionActor = *reinterpret_cast<AActor**>(frameTop - 0x34);
    savedActionActor = actionActor;
    APawn* identifiedPawn = nullptr;
    if (actionActor != nullptr) {
        identifiedPawn = actionActor->GetPawnOrColBoxOwner();
    }
    int isLocal = actionController->LocalPlayerController();
    bool identifyOrCapture = false;
    if (isLocal != 0)
        identifyOrCapture = actionController->m_pawn->EngineWeapon != nullptr;
    if (!identifyOrCapture) {
        AGameReplicationInfo* gameInfo = actionController->GameReplicationInfo;
        const FString* gameType = &gameInfo->m_szGameTypeFlagRep;
        identifyOrCapture = gameType->operator==(nativeTextRGMCaptureTheEnemyAdvMode) != 0;
    }
    if (identifyOrCapture) {
        bool needsSecondTrace = identifiedPawn == nullptr;
        FCheckResult& identificationHit = *(FCheckResult*)(frameTop - 0xbc);
        uint* secondWords = (uint*)&identificationHit;
        for (int i = 0; i < 9; ++i)
            secondWords[i] = 0;
        secondWords[9] = 0x3f800000;
        secondWords[10] = 0xffffffff;
        secondWords[11] = 0;
        if (needsSecondTrace && actionActor != nullptr) {
            ULevel* secondLevel = actionController->XLevel;
            const uint* secondExtent = *(const uint**)&FVectorFVector0Import;
            uint secondExtentWords[3];
            secondExtentWords[0] = secondExtent[0];
            byte* secondTable = *(byte**)secondLevel;
            secondExtentWords[1] = secondExtent[1];
            secondExtentWords[2] = secondExtent[2];
            // Reload after extent capture; the level/table remain from the earlier receiver.
            actionController = savedReceiver;
            APawn* ignoredPawn = actionController->Pawn;
            (*(SingleLineCheck*)(secondTable + 0xcc))(secondLevel, &identificationHit, ignoredPawn,
                &end, &start, 0x20087, *(FVector*)secondExtentWords);
            AActor* secondActor = identificationHit.Actor;
            if (secondActor != nullptr) {
                identifiedPawn = secondActor->GetPawnOrColBoxOwner();
                if (identifiedPawn != nullptr) {
                    if (identifiedPawn->APawn::IsAlive() == 0)
                        identifiedPawn = nullptr;
                }
            }
            AGameReplicationInfo* gameInfo = actionController->GameReplicationInfo;
            const FString* gameType = &gameInfo->m_szGameTypeFlagRep;
            int captureMode = gameType->operator==(nativeTextRGMCaptureTheEnemyAdvMode);
            if (captureMode != 0 && identifiedPawn != nullptr) {
                actionActor = identifiedPawn;
                suppressQuery = 0;
                walkable = 0;
            } else {
                actionActor = savedActionActor; // Reload the shared fallback after the callbacks.
            }
        }
        if (actionController->m_pawn->EngineWeapon != nullptr)
            actionController->AR6PlayerController::UpdateReticuleIdentification(identifiedPawn);
    }
    if (actionActor == nullptr || suppressQuery != 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    for (;;) {
        AActor* parent = actionActor->m_AttachedTo;
        if (parent == nullptr)
            break;
        actionActor = parent;
    }
    UClass* rootType = actionActor->Class;
    UClass* terrainClass = ATerrainInfoPrivateStaticClassImport;
    bool geometrySelectsDefault = false;
    if (matchesType(rootType, terrainClass)) {
        float10 verticalNormal = (float10)hit.Normal.Y + hit.Normal.X;
        verticalNormal *= nativeFloatZero;
        verticalNormal += hit.Normal.Z;
        float zero = nativeFloatZero;
        if (!(verticalNormal >= (float10)zero))
            verticalNormal = -verticalNormal;
        double threshold = nativeDouble0Point707; // 0.707, retained as the native double constant.
        geometrySelectsDefault = verticalNormal > (float10)threshold;
    } else {
        rootType = actionActor->Class;
        UClass* meshClass = AStaticMeshActorPrivateStaticClassImport;
        if (matchesType(rootType, meshClass)) {
            if (walkable != 0) {
                float10 verticalNormal = (float10)hit.Normal.Y + hit.Normal.X;
                verticalNormal *= nativeFloatZero;
                verticalNormal += hit.Normal.Z;
                float roundedNormal = (float)verticalNormal;
                float10 magnitude = NegateNegativeOrUnordered(roundedNormal);
                double threshold = nativeDouble0Point4; // 0.4 after the helper's live x87 return.
                geometrySelectsDefault = magnitude > (float10)threshold;
            }
        } else {
            geometrySelectsDefault = walkable != 0;
        }
    }
    uint useDefaultLocation = geometrySelectsDefault ? 1U : defaultFallbackWord;
    uint* defaultWords = reinterpret_cast<uint*>(&actionController->m_vDefaultLocation);
    if (actionController->Role == 4) {
        AActor* receiver = useDefaultLocation != 0 ? actionController : actionActor;
        query->aQueryTarget = receiver;
        float10 differenceZ = (float10)hit.Location.Z - start.Z;
        float10 differenceY = (float10)hit.Location.Y - start.Y;
        float10 differenceX = (float10)hit.Location.X - start.X;
        vectorScratch.X = (float)differenceX;
        vectorScratch.Y = (float)differenceY;
        vectorScratch.Z = (float)differenceZ;
        float10 liveQueryDistance = (float10)vectorScratch.Size();
        // Query distance reuses the selector's zero word.
        reinterpret_cast<float&>(defaultFallbackWord) = (float)liveQueryDistance;
        uint queryDistanceWord = defaultFallbackWord;
        // Raw caller ABI view preserves the by-value float distance word.
        receiver->AActor::eventR6QueryCircumstantialAction(
            reinterpret_cast<const float&>(queryDistanceWord), query, actionController);
        if (useDefaultLocation != 0) {
            uint x = hitWords[2];
            uint y = hitWords[3];
            defaultWords[0] = x;
            uint z = hitWords[4]; // Native reads Z after the first destination store.
            defaultWords[1] = y;
            defaultWords[2] = z;
        } else {
            const uint* zero = *(const uint**)&FVectorFVector0Import;
            for (int i = 0; i < 3; ++i)
                defaultWords[i] = zero[i];
        }
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(actionController) + 0x838) & 0x200000U) != 0) {
            AR6AbstractCircumstantialActionQuery* currentQuery = query;
            byte inRange = currentQuery->iInRange;
            if (inRange == 0) {
                void* savedLink = nativeFrame.previousExceptionList;
                currentQuery->iHasAction = 0;
                ExceptionList = savedLink;
                return;
            }
        }
    } else if (useDefaultLocation != 0) {
        uint x = hitWords[2];
        uint y = hitWords[3];
        uint z = hitWords[4];
        defaultWords[0] = x;
        defaultWords[1] = y;
        defaultWords[2] = z;
    } else {
        const uint* zero = *(const uint**)&FVectorFVector0Import;
        for (int i = 0; i < 3; ++i)
            defaultWords[i] = zero[i];
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10030f2d : forward the caught action-update pointer through the inherited frame
__declspec(naked) void CircumstantialActionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xc0]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x80]
        push edx
        mov dword ptr [ebp-0x80],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10030f44 : report action-update context and forward the active exception
__declspec(naked) void CircumstantialActionCatchContext(void)
{
    __asm {
        // L"AR6PlayerController::UpdateCircumstantialAction".
        push offset nativeTextAR6PlayerControllerUpdateCircumstantialAction
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100448f0 : select the action-update exception tables without creating a frame
__declspec(naked) void CircumstantialActionExceptionHandler(void)
{
    __asm {
        mov eax,offset CircumstantialActionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10030f70 : AR6PlayerController::PostNetReceive
// Dispatches a team-selection change through the current vtable before the base receive hook.
void __thiscall AR6PlayerController::PostNetReceive(void)
{
    struct ReceiveFrame { // Inferred native EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caughtText, rethrowText; // EBP-0x18/-0x14.
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &PlayerPostNetReceiveExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte previousTeam = PreNetTeamSelection;
    byte currentTeam = this->m_TeamSelection;
    bool teamChanged = previousTeam != currentTeam; // Both reads and the comparison precede state zero.
    nativeFrame.savedEsp = &nativeFrame.savedEdi;
    nativeFrame.exceptionState = 0;
    if (teamChanged) {
        FName eventName = R6ENGINE_PlayerTeamSelectionReceived;
        UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(eventName), 0);
        byte* currentVtable = *(byte**)this;
        using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
        (*(ProcessEvent*)(currentVtable + 0x10))(this, function, nullptr, nullptr);
    }
    this->APlayerController::PostNetReceive();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10030fdd : forward the caught post-receive pointer through its inherited frame
__declspec(naked) void PlayerPostNetReceiveCatchPointer(void)
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

// R6Engine.dll @ 10030ff1 : report post-receive context and forward the active exception
__declspec(naked) void PlayerPostNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerPostNetReceive // L"AR6PlayerController::PostNetReceive".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044900 : select the post-receive exception tables without creating a frame
__declspec(naked) void PlayerPostNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset PlayerPostNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10031010 : AR6PlayerController::UpdateReticule
// Selects a nearby visible projected pawn, then moves the reticule toward its current lock position.
void __thiscall AR6PlayerController::UpdateReticule(float deltaTime)
{
    struct ReticuleFrame { // Inferred entry-ESP view; this method has no local exception registration or owned cleanup.
        uint savedEdi, savedEsi, savedEbp, savedEbx; // Entry ESP-0xc8..-0xbc.
        uint distanceWord, indexWord; // Bottom ESP+0x10/+0x14; indexWord initially holds the radius divisor.
        uint centerYWord, screenYWord, screenXWord, bestDistanceWord, centerXWord;
        uint aimWords[3], radiusSquaredWord, cameraLocationWords[3], cameraRotationWords[3];
        uint targetBoneWord, previousTargetWord, eyeWords[3], hitWords[12], boneCoordsWords[12];
    } frame;
    if (this->LocalPlayerController() == 0)
        return;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
    uint previousTarget = reinterpret_cast<uint>(this->m_targetedPawn);
    frame.previousTargetWord = previousTarget;
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportsHeader =
        reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30);
    UViewport** viewports = reinterpret_cast<UViewport**>(viewportsHeader->dataAddress);
    UViewport* viewport = viewports[0];
    UCanvas* canvas = *reinterpret_cast<UCanvas**>(reinterpret_cast<byte*>(viewport) + 0x7c);
    uint centerX = reinterpret_cast<uint&>(canvas->HalfClipX);
    uint centerY = reinterpret_cast<uint&>(canvas->HalfClipY);
    byte autoAim = this->m_wAutoAim;
    frame.centerXWord = centerX;
    frame.centerYWord = centerY;
    if (autoAim == 0) {
        this->m_targetedPawn = nullptr;
    } else {
        uint x = *(uint*)((byte*)viewport + 0x1b8);
        frame.cameraLocationWords[0] = x;
        uint y = *(uint*)((byte*)viewport + 0x1bc);
        uint z = *(uint*)((byte*)viewport + 0x1c0);
        frame.cameraLocationWords[1] = y;
        frame.cameraLocationWords[2] = z;
        x = *(uint*)((byte*)viewport + 0x1c4);
        frame.cameraRotationWords[0] = x;
        y = *(uint*)((byte*)viewport + 0x1c8);
        z = *(uint*)((byte*)viewport + 0x1cc);
        frame.cameraRotationWords[1] = y;
        APawn* pawn = this->Pawn;
        frame.cameraRotationWords[2] = z;
        x = reinterpret_cast<uint&>(pawn->m_vEyeLocation.X);
        frame.eyeWords[0] = x;
        y = reinterpret_cast<uint&>(pawn->m_vEyeLocation.Y);
        frame.eyeWords[1] = y;
        frame.indexWord = 4U - (uint)autoAim;
        z = reinterpret_cast<uint&>(pawn->m_vEyeLocation.Z);
        int radiusDivisor = (int)frame.indexWord;
        frame.eyeWords[2] = z;
        float10 radius = (float10)reinterpret_cast<float&>(frame.centerYWord) / (float10)radiusDivisor;
        frame.bestDistanceWord = 0x4bbebc20; // 25,000,000 squared screen units.
        this->m_targetedPawn = nullptr;
        // Quotient stays extended through the square.
        reinterpret_cast<float&>(frame.radiusSquaredWord) = (float)(radius * radius);
        // L"R6 PonyTail1".
        ::new (reinterpret_cast<void*>(&frame.targetBoneWord)) FName(nativeTextR6PonyTail1, static_cast<EFindName>(1));
        // Inferred wrappers retain the native read order of repeated inline packets and screening operations.
        auto project = [&](const uint* point) {
            uint pitch = frame.cameraRotationWords[0];
            uint yaw = frame.cameraRotationWords[1];
            uint roll = frame.cameraRotationWords[2];
            uint cameraX = frame.cameraLocationWords[0];
            uint cameraY = frame.cameraLocationWords[1];
            uint cameraZ = frame.cameraLocationWords[2];
            uint pointX = point[0];
            uint pointY = point[1];
            uint pointZ = point[2];
            // Raw caller ABI view preserves the by-value float and rotation words.
            using ProjectPacket = int (__cdecl*)(UViewport*, float*, float*, uint, uint, uint, uint, uint, uint, uint,
                uint, uint);
            return ((ProjectPacket)&ProjectPointToViewport)(viewport, (float*)&frame.screenXWord,
                (float*)&frame.screenYWord,
                pointX, pointY, pointZ, cameraX, cameraY, cameraZ, pitch, yaw, roll);
        };
        auto withinScreenLimits = [&]() {
            float10 yDifference = (float10)reinterpret_cast<float&>(frame.screenYWord) -
                reinterpret_cast<float&>(frame.centerYWord);
            float10 xDifference = (float10)reinterpret_cast<float&>(frame.screenXWord) -
                reinterpret_cast<float&>(frame.centerXWord);
            float10 xSquared = xDifference * xDifference;
            float10 ySquared = yDifference * yDifference;
            reinterpret_cast<float&>(frame.distanceWord) = (float)(xSquared + ySquared);
            float10 distance = (float10)reinterpret_cast<float&>(frame.distanceWord);
            float radiusSquared = reinterpret_cast<float&>(frame.radiusSquaredWord);
            if (!(distance < (float10)radiusSquared))
                return false;
            distance = (float10)reinterpret_cast<float&>(frame.distanceWord);
            float bestDistance = reinterpret_cast<float&>(frame.bestDistanceWord);
            return distance < (float10)bestDistance;
        };
        auto traceTarget = [&]() {
            const uint* zeroExtent = *(const uint**)&FVectorFVector0Import;
            uint extentWords[3];
            extentWords[0] = zeroExtent[0];
            ULevel* tableLevel = this->XLevel;
            byte* table = *(byte**)tableLevel;
            extentWords[1] = zeroExtent[1];
            extentWords[2] = zeroExtent[2];
            APawn* ignoredPawn = this->Pawn;
            ULevel* receiverLevel = this->XLevel;
            using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*,
                uint, FVector);
            (*(SingleLineCheck*)(table + 0xcc))(receiverLevel, (FCheckResult*)frame.hitWords, ignoredPawn,
                (FVector*)frame.aimWords, (FVector*)frame.eyeWords, 0x20286, *(FVector*)extentWords);
        };
        ULevel* countLevel = this->XLevel;
        const NativeArrayHeader32* countHeader =
            reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(countLevel) + 0x101c0);
        int candidateCount = countHeader->count;
        uint candidateIndex = 0;
        frame.indexWord = 0;
        if (candidateCount > 0) {
            do {
                ULevel* dataLevel = this->XLevel;
                const NativeArrayHeader32* dataHeader =
                    reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(dataLevel) + 0x101c0);
                uint dataAddress = dataHeader->dataAddress;
                APawn* candidate = *reinterpret_cast<APawn**>(dataAddress + candidateIndex * 4U);
                if (candidate->m_ePawnType == 2) {
                    if (candidate->APawn::IsAlive() != 0) {
                        UMesh* mesh = candidate->Mesh;
                        // Return ignored; receiver argument is the controller.
                        mesh->MeshGetInstance(this);
                        USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(candidate->MeshInstance);
                        uint boneName = frame.targetBoneWord;
                        int boneIndex = instance->USkeletalMeshInstance::MatchRefBone(
                            reinterpret_cast<FName&>(boneName));
                        if (boneIndex >= 0) {
                            // Physical result view keeps the supplied buffer and returned pointer.
                            FCoords* bone = instance->USkeletalMeshInstance::GetBoneCoords(
                                (FCoords*)frame.boneCoordsWords, (uint)boneIndex, 0);
                            uint pointX = ((uint*)bone)[0];
                            frame.aimWords[0] = pointX;
                            uint pointY = ((uint*)bone)[1];
                            frame.aimWords[1] = pointY;
                            uint pointZ = ((uint*)bone)[2];
                            frame.aimWords[2] = pointZ;
                            if (project((uint*)bone) != 0 && withinScreenLimits()) {
                                InitializeCheckResult((FCheckResult*)frame.hitWords, 1.0f, nullptr);
                                traceTarget();
                                AActor* firstActor = reinterpret_cast<AActor*>(frame.hitWords[1]);
                                bool accept = firstActor == nullptr;
                                if (firstActor != nullptr) {
                                    if (firstActor != candidate) {
                                        const uint* location = reinterpret_cast<const uint*>(&candidate->Location);
                                        frame.aimWords[0] = location[0];
                                        frame.aimWords[1] = location[1];
                                        frame.aimWords[2] = location[2];
                                        if (project(location) != 0 && withinScreenLimits())
                                            traceTarget(); // Retains the first hit record without reinitializing it.
                                    }
                                    AActor* currentActor = reinterpret_cast<AActor*>(frame.hitWords[1]);
                                    accept = currentActor == nullptr || currentActor == candidate;
                                }
                                if (accept) {
                                    uint pointX = frame.aimWords[0];
                                    uint pointY = frame.aimWords[1];
                                    reinterpret_cast<uint&>(this->m_vAutoAimTarget.X) = pointX;
                                    uint pointZ = frame.aimWords[2];
                                    reinterpret_cast<uint&>(this->m_vAutoAimTarget.Y) = pointY;
                                    uint screenX = frame.screenXWord;
                                    reinterpret_cast<uint&>(this->m_vAutoAimTarget.Z) = pointZ;
                                    uint screenY = frame.screenYWord;
                                    uint distanceWord = frame.distanceWord;
                                    this->m_targetedPawn = static_cast<AR6Pawn*>(candidate);
                                    reinterpret_cast<uint&>(this->m_fRetLockPosX) = screenX;
                                    reinterpret_cast<uint&>(this->m_fRetLockPosY) = screenY;
                                    frame.bestDistanceWord = distanceWord;
                                }
                            }
                        }
                    }
                }
                candidateIndex = frame.indexWord;
                countLevel = this->XLevel;
                countHeader =
                    reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(countLevel) + 0x101c0);
                candidateCount = countHeader->count;
                ++candidateIndex; // Native wraps the DWORD before its signed comparison.
                frame.indexWord = candidateIndex;
            } while ((int)candidateIndex < candidateCount);
        }
    }
    AR6Pawn* selectedTarget = this->m_targetedPawn;
    if (selectedTarget == nullptr) {
        uint centerX = frame.centerXWord;
        uint centerY = frame.centerYWord;
        reinterpret_cast<uint&>(this->m_fRetLockPosX) = centerX;
        reinterpret_cast<uint&>(this->m_fRetLockPosY) = centerY;
    }
    previousTarget = frame.previousTargetWord;
    if (reinterpret_cast<uint>(selectedTarget) != previousTarget)
        reinterpret_cast<uint&>(this->m_fRetLockTime) = 0x3e19999a; // 0.15f.
    float10 lockX = (float10)this->m_fRetLockPosX;
    float10 currentX = (float10)this->m_fCurrRetPosX;
    bool positionDiffers = currentX != lockX;
    if (!positionDiffers) {
        float10 lockY = (float10)this->m_fRetLockPosY;
        float10 currentY = (float10)this->m_fCurrRetPosY;
        positionDiffers = currentY != lockY;
    }
    if (positionDiffers) {
        float10 lockTime = (float10)this->m_fRetLockTime;
        float zero = nativeFloatZero;
        if (lockTime > (float10)zero) {
            // Incoming delta word is read after callbacks.
            float10 fraction = (float10)deltaTime / this->m_fRetLockTime;
            float10 xDifference = (float10)this->m_fRetLockPosX - this->m_fCurrRetPosX;
            this->m_fCurrRetPosX = (float)(xDifference * fraction + this->m_fCurrRetPosX);
            float10 yDifference = (float10)this->m_fRetLockPosY - this->m_fCurrRetPosY;
            this->m_fCurrRetPosY = (float)(yDifference * fraction + this->m_fCurrRetPosY);
            this->m_fRetLockTime = (float)((float10)this->m_fRetLockTime - deltaTime);
        } else {
            uint x = reinterpret_cast<uint&>(this->m_fRetLockPosX);
            uint y = reinterpret_cast<uint&>(this->m_fRetLockPosY);
            reinterpret_cast<uint&>(this->m_fCurrRetPosX) = x;
            reinterpret_cast<uint&>(this->m_fCurrRetPosY) = y;
        }
    }
    // Void RET4; no local cleanup, target null guard, viewport bounds check or interpolation clamp.
}

// Evaluates a training localization request, inserts its action-key names, and returns the formatted instruction.
// R6Engine.dll @ 10031530 : AR6PlayerController::execLocalizeTraining
// Localizes training text, substitutes the selected action-key names and retries localization when formatting stays
// empty.
// Native ABI view retains the incoming frame word for the localized text pointer.
void __thiscall AR6PlayerController::execLocalizeTraining(FFrame* stack, void* resultString)
{
    // Descriptive native frame: locals occupy EBP-be4..-10; saved registers extend down to EBP-bf0.
    struct TrainingFrame {
        uint savedEDI, savedESI, savedEBX;
        uint locals[0xbd8 / 4];
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    byte* frameBase = (byte*)&nativeFrame.exceptionState + 4;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TrainingLocalizationExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    *(void**)(frameBase - 0x10) = &nativeFrame.savedEDI;
    FString* SectionName = (FString*)(frameBase - 0x28);
    FString* KeyName = (FString*)(frameBase - 0x40);
    FString* PackageName = (FString*)(frameBase - 0x34);
    int& iBox = *(int*)(frameBase - 0x4c);
    int& iParagraph = *(int*)(frameBase - 0x18);
    byte& guardState = *(byte*)&nativeFrame.exceptionState;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    nativeFrame.exceptionState = 0;
    ::new (SectionName) FString;
    FFrame* scriptFrame = stack; // EDI retains this frame while the incoming stack word is later reused.
    byte** codeCursor = &scriptFrame->Code;
    byte* code = *codeCursor;
    byte opcode = *code++;
    UObject* receiver = scriptFrame->Object;
    *codeCursor = code;
    ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
    guardState = 1;
    table[opcode](receiver, scriptFrame, SectionName);
    ::new (KeyName) FString;
    code = *codeCursor;
    opcode = *code++;
    receiver = scriptFrame->Object;
    *codeCursor = code;
    table = *(ScriptNative**)&CoreGNativesImport;
    guardState = 2;
    table[opcode](receiver, scriptFrame, KeyName);
    ::new (PackageName) FString;
    code = *codeCursor;
    opcode = *code++;
    receiver = scriptFrame->Object;
    *codeCursor = code;
    table = *(ScriptNative**)&CoreGNativesImport;
    guardState = 3;
    table[opcode](receiver, scriptFrame, PackageName);
    code = *codeCursor;
    receiver = scriptFrame->Object;
    iBox = 0;
    opcode = *code++;
    *codeCursor = code;
    table = *(ScriptNative**)&CoreGNativesImport;
    table[opcode](receiver, scriptFrame, &iBox);
    code = *codeCursor;
    receiver = scriptFrame->Object;
    iParagraph = 0;
    opcode = *code++;
    *codeCursor = code;
    table = *(ScriptNative**)&CoreGNativesImport;
    table[opcode](receiver, scriptFrame, &iParagraph);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        receiver = scriptFrame->Object;
        *codeCursor = code + 1;
        table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, scriptFrame, nullptr);
    }
    ushort* formattedText = (ushort*)(frameBase - 0xbe4); // Native 1024-ushort buffer, without a formatting bound.
    appStrcpy(formattedText, nativeEmptyText);
    // Inferred lookup tables describe actual native storage/capture operations; they are not additional native bodies.
    const uint actionSlotOffsets[76] = {
        0x9c, 0x384, 0x84, 0x234, 0x1ec, 0x24c, 0x324, 0xb4,
        0x3e4, 0xe4, 0x264, 0xcc, 0x33c, 0x114, 0x27c, 0xfc,
        0x144, 0x294, 0x12c, 0x2ac, 0x15c, 0x39c, 0x174, 0x18c,
        0x354, 0x2c4, 0x1bc, 0x3cc, 0x1a4, 0x2dc, 0x1d4, 0x2f4,
        0x60, 0x36c, 0x30c, 0x21c, 0x3b4, 0x204, 0xa8, 0x90,
        0x78, 0x6c, 0xf0, 0xd8, 0xc0, 0x120, 0x108, 0x150,
        0x138, 0x1b0, 0x198, 0x180, 0x168, 0x1c8, 0x1e0, 0x210,
        0x1f8, 0x240, 0x228, 0x288, 0x270, 0x258, 0x2e8, 0x2d0,
        0x2b8, 0x2a0, 0x300, 0x318, 0x3a8, 0x390, 0x378, 0x360,
        0x348, 0x330, 0x3c0, 0x3d8
    };
    struct Captures { uint firstState; int returnedOffsets[6], textOffsets[6]; };
    const Captures captureMap[32] = {
        {4, {8, -72, -68, 0, 0, 0}, {8, -72, -68, -28, -20, 0}},
        {9, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {10, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {12, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {15, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {16, {8, 0, 0, 0, 0, 0}, {8, -20, -28, 0, 0, 0}},
        {20, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {23, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {26, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {27, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {29, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {30, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {33, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {34, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {35, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {38, {8, 0, 0, 0, 0, 0}, {8, -20, -28, 0, 0, 0}},
        {42, {8, 0, 0, 0, 0, 0}, {8, -20, -28, 0, 0, 0}},
        {46, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {49, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {51, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {53, {8, 0, 0, 0, 0, 0}, {8, -20, -28, 0, 0, 0}},
        {57, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {58, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {59, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {61, {0, 0, 0, 0, 0, 0}, {8, 0, 0, 0, 0, 0}},
        {63, {0, 0, 0, 0, 0, 0}, {8, -20, 0, 0, 0, 0}},
        {66, {8, 0, 0, 0, 0, 0}, {8, -20, -28, 0, 0, 0}},
        {70, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {71, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {72, {8, -20, -28, 0, 0, 0}, {8, -20, -28, -68, -72, 0}},
        {78, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
        {79, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}}
    };
    auto captureWord = [&](int offset, const void* value) {
        if (offset == 8)
            reinterpret_cast<uint&>(stack) = (uint)value;
        else if (offset != 0)
            *(uint*)(frameBase + offset) = (uint)value;
    };
    auto actionSlot = [&](uint state) { return (FString*)(frameBase - actionSlotOffsets[state - 4]); };
    auto localizedTemplate = [&]() {
        const ushort* packageText = PackageName->operator*();
        const ushort* keyText = KeyName->operator*();
        const ushort* sectionText = SectionName->operator*();
        return Localize(sectionText, keyText, packageText, nullptr, 0, 0);
    };
    auto formatActionKeys = [&](uint firstState, std::initializer_list<const wchar_t*> actions) {
        const Captures* captures = captureMap;
        while (captures->firstState != firstState)
            ++captures;
        FString* returnedKeys[6]; // Reference views of the native register/word captures, without FString ownership.
        const ushort* keyTexts[6];
        uint actionCount = 0;
        for (const wchar_t* action : actions) {
            uint state = firstState + actionCount;
            returnedKeys[actionCount] = this->AR6PlayerController::GetLocKeyNameByActionKey(actionSlot(state),
                (const ushort*)action);
            captureWord(captures->returnedOffsets[actionCount], returnedKeys[actionCount]);
            guardState = (byte)state;
            ++actionCount;
        }
        for (uint index = 0; index < actionCount; ++index) {
            keyTexts[index] = returnedKeys[index]->operator*();
            captureWord(captures->textOffsets[index], keyTexts[index]);
        }
        const ushort* format = localizedTemplate();
        switch (actionCount) {
        case 1: appSprintf(formattedText, format, keyTexts[0]); break;
        case 2: appSprintf(formattedText, format, keyTexts[1], keyTexts[0]); break;
        case 3: appSprintf(formattedText, format, keyTexts[2], keyTexts[1], keyTexts[0]); break;
        case 4: appSprintf(formattedText, format, keyTexts[3], keyTexts[2], keyTexts[1], keyTexts[0]); break;
        case 5:
            appSprintf(formattedText, format, keyTexts[4], keyTexts[3], keyTexts[2], keyTexts[1], keyTexts[0]);
            break;
        case 6:
            appSprintf(formattedText, format, keyTexts[5], keyTexts[4],
                keyTexts[3],
                keyTexts[2],
                keyTexts[1], keyTexts[0]);
            break;
        }
        for (uint remaining = actionCount; remaining != 0; --remaining) {
            uint state = firstState + remaining - 1;
            guardState = (byte)(remaining == 1 ? 3 : state - 1);
            reinterpret_cast<FString*>(actionSlot(state))->FString::~FString();
        }
    };
    switch (iBox) {
    case 1:
      if (iParagraph == 1) {
        formatActionKeys(0x4,{L"Run",L"StrafeLeft",L"StrafeRight",L"MoveBackward",L"MoveForward"});
      }
      if (iParagraph == 2) {
        formatActionKeys(0x9,{L"Menu"});
      }
      break;
    case 2:
      if (iParagraph == 0 || iParagraph == 1) {
        formatActionKeys(0xa,{L"RaisePosture",L"LowerPosture"});
      }
      break;
    case 3:
      if (iParagraph == 0 || iParagraph == 2) {
        formatActionKeys(0xc,{L"GraduallyCloseDoor",L"GraduallyOpenDoor",L"Action"});
      } else if (iParagraph == 1) {
        formatActionKeys(0xf,{L"Action"});
      }
      break;
    case 4:
      if (iParagraph == 0) {
        formatActionKeys(0x10,{L"Run",L"MoveBackward",L"MoveForward",L"Action"});
      } else if (iParagraph == 1) {
        formatActionKeys(0x14,{L"MoveBackward",L"MoveForward",L"Action"});
      }
      break;
    case 5:
      formatActionKeys(0x17,{L"FluidPosture",L"PeekLeft",L"PeekRight"});
      break;
    case 6:
      if (iParagraph == 1) {
        formatActionKeys(0x1a,{L"ToggleNightVision"});
      }
      break;
    case 8:
      if (iParagraph == 1) {
        formatActionKeys(0x1b,{L"ChangeRateOfFire",L"PrimaryFire"});
      } else if (iParagraph == 2) {
        formatActionKeys(0x1d,{L"Reload"});
      } else if (iParagraph == 3) {
        formatActionKeys(0x1e,{L"InventoryMenu",L"SecondaryWeapon",L"PrimaryWeapon"});
      }
      break;
    case 9:
      if (iParagraph == 0) {
        formatActionKeys(0x21,{L"PrimaryFire"});
      } else if (iParagraph == 2) {
        formatActionKeys(0x22,{L"Zoom"});
      }
      break;
    case 10:
      formatActionKeys(0x23,{L"Reload",L"Zoom",L"PrimaryFire"});
      break;
    case 11:
    case 12:
    case 13:
    case 15:
      formatActionKeys(0x26,{L"ChangeRateOfFire",L"Reload",L"Zoom",L"PrimaryFire"});
      break;
    case 14:
      formatActionKeys(0x2a,{L"SecondaryFire",L"Reload",L"Zoom",L"PrimaryFire"});
      break;
    case 16:
      formatActionKeys(0x2e,{L"InventoryMenu",L"GadgetTwo",L"GadgetOne"});
      break;
    case 17:
      formatActionKeys(0x31,{L"SecondaryFire",L"PrimaryFire"});
      break;
    case 18:
    case 19:
    case 20:
      formatActionKeys(0x33,{L"PrimaryFire",L"PrimaryFire"});
      break;
    case 21:
      if (iParagraph == 1) {
        formatActionKeys(0x35,{L"OperativeSelector",L"PreviousMember",L"NextMember",L"ToggleTeamHold"});
      }
      break;
    case 22:
      formatActionKeys(0x39,{L"RulesOfEngagement"});
      break;
    case 23:
      if (iParagraph == 0) {
        formatActionKeys(0x3a,{L"Action"});
      } else if (iParagraph == 1) {
        formatActionKeys(0x3b,{L"GoCodeZulu",L"Action"});
      } else if (iParagraph == 2) {
        formatActionKeys(0x3d,{L"Action",L"ToggleTeamHold"});
      }
      break;
    case 24:
      if (iParagraph == 0) {
        formatActionKeys(0x3f,{L"OperativeSelector",L"PreviousTeam",L"NextTeam"});
      } else if (iParagraph == 1) {
        formatActionKeys(0x42,{L"GoCodeZulu",L"GoCodeCharlie",L"GoCodeBravo",L"GoCodeAlpha"});
      } else if (iParagraph == 2) {
        formatActionKeys(0x46,{L"GoCodeAlpha"});
      }
      break;
    case 25:
      if (iParagraph == 0) {
        formatActionKeys(0x47,{L"ToggleSniperControl"});
      } else if (iParagraph == 1) {
        formatActionKeys(0x48,
            {L"GoCodeAlpha",L"OperativeSelector",L"GoCodeZulu",L"GoCodeCharlie",L"GoCodeBravo",L"GoCodeAlpha"});
      }
      break;
    case 26:
      if (iParagraph == 2) {
        formatActionKeys(0x4e,{L"GoCodeAlpha"});
      }
      break;
    case 27:
    case 28:
      if (iParagraph == 0) {
        formatActionKeys(0x4f,{L"GoCodeAlpha"});
      }
      break;
    default:
      break;
    }
    if (appStrcmp(formattedText, nativeEmptyText) == 0) {
        const ushort* format = localizedTemplate();
        appSprintf(formattedText, format);
    }
    reinterpret_cast<FString*>(resultString)->operator=(formattedText);
    guardState = 2;
    PackageName->FString::~FString();
    guardState = 1;
    KeyName->FString::~FString();
    guardState = 0;
    SectionName->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10032f74 : TrainingLocalizationCatchPointer
// Copies the caught text pointer at EBP-54 into the parent's EBP-50 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl TrainingLocalizationCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x54]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x50]
        push eax
        mov dword ptr [ebp-0x50],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10033020 : AR6PlayerController::execGetLocStringWithActionKey
// Evaluates the template and action strings, formats the localized key and assigns the result after temporary cleanup.
void __thiscall AR6PlayerController::execGetLocStringWithActionKey(FFrame& stack, void* result)
{
    // Descriptive native frame view; explicit storage preserves the three distinct FString lifetimes.
    struct LocStringFrame {
        uint savedEDI, savedESI, savedEBX;
        ushort formattedText[256];
        uint localizedKeyStorage[3], caughtText, textStorage[3], actionKeyStorage[3], rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &LocStringActionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FString* szText = (FString*)nativeFrame.textStorage;
    FString* szActionKey = (FString*)nativeFrame.actionKeyStorage;
    FString* localizedKey = (FString*)nativeFrame.localizedKeyStorage;
    byte& state = *(byte*)&nativeFrame.exceptionState;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ::new (szText) FString;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor;
    byte opcode = *code++;
    UObject* receiver = stack.Object;
    *codeCursor = code;
    ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
    state = 1;
    table[opcode](receiver, &stack, szText);
    ::new (szActionKey) FString;
    code = *codeCursor;
    opcode = *code++;
    receiver = stack.Object;
    *codeCursor = code;
    table = *(ScriptNative**)&CoreGNativesImport;
    state = 2;
    table[opcode](receiver, &stack, szActionKey);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        receiver = stack.Object;
        *codeCursor = code + 1;
        table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, &stack, nullptr);
    }
    const ushort* actionKeyText = szActionKey->operator*();
    FString* returnedKey = this->AR6PlayerController::GetLocKeyNameByActionKey(localizedKey, actionKeyText);
    state = 3;
    const ushort* localizedKeyText = returnedKey->operator*();
    const ushort* formatText = szText->operator*();
    appSprintf(nativeFrame.formattedText, formatText, localizedKeyText);
    state = 2;
    localizedKey->FString::~FString();
    reinterpret_cast<FString*>(result)->operator=(nativeFrame.formattedText);
    state = 1;
    szActionKey->FString::~FString();
    state = 0;
    szText->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003314a : LocStringActionCatchPointer
// Copies the caught text pointer at EBP-30 into the parent's rethrow slot at EBP-14.
__declspec(naked) __declspec(noreturn) void __cdecl LocStringActionCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x30]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10033180 : AR6PlayerController::execUpdateSpectatorReticule
// Consumes the terminator and optional debug record, then directly updates the spectator reticule.
void __thiscall AR6PlayerController::execUpdateSpectatorReticule(FFrame& stack, void* unusedResult)
{
    // Descriptive native frame view: caught/rethrow words are EBP-18/EBP-14; saved ESP is EBP-10.
    struct ScriptGuardFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &UpdateSpectatorReticuleExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    bool hasDebugRecord = *code == 0x42;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0; // The cursor update and debug-byte read precede catch state 0.
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    if (hasDebugRecord) {
        UObject* receiver = stack.Object;
        *codeCursor = code + 1;
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, &stack, nullptr);
    }
    this->AR6PlayerController::UpdateSpectatorReticule();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 100331e8 : AR6PlayerControllerSpectatorReticuleCatchPointer
// Rethrows the caught text pointer through the parent's EBP-14 slot.
__declspec(naked) __declspec(noreturn) void __cdecl AR6PlayerControllerSpectatorReticuleCatchPointer(void)
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

// R6Engine.dll @ 100331fc : AR6PlayerControllerSpectatorReticuleCatchContext
// Reports the native method context and forwards the active exception without a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl AR6PlayerControllerSpectatorReticuleCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecUpdateSpectatorReticule
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10033220 : AR6PlayerController::execUpdateReticule
// Evaluates the delta-time word, consumes trailing tokens and directly updates the reticule.
void __thiscall AR6PlayerController::execUpdateReticule(FFrame& stack, void* unusedResult)
{
    // Descriptive native frame view: caught/rethrow words are EBP-1c/EBP-18; saved ESP is EBP-10.
    struct ScriptGuardFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, deltaTimeWord;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &UpdateReticuleExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor;
    nativeFrame.deltaTimeWord = 0;
    byte token = *code++;
    *codeCursor = code;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
    UObject* firstReceiver = stack.Object;
    nativeFrame.exceptionState = 0; // The first opcode, cursor, table-base and receiver reads precede catch state 0.
    firstTable[token](firstReceiver, &stack, &nativeFrame.deltaTimeWord);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        UObject* receiver = stack.Object;
        *codeCursor = code + 1;
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, &stack, nullptr);
    }
    // Raw-word call view of UpdateReticule(float) at 10031010: the native bridge performs no FP conversion.
    using UpdateReticuleRaw = void (__thiscall*)(AR6PlayerController*, uint);
    ((UpdateReticuleRaw)&AR6PlayerControllerUpdateReticuleNativeEntry)(this, nativeFrame.deltaTimeWord);
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 100332b0 : ReticuleCatchPointer
// Rethrows the caught text pointer through the parent's EBP-18 slot.
__declspec(naked) __declspec(noreturn) void __cdecl ReticuleCatchPointer(void)
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

// R6Engine.dll @ 100332c4 : ReticuleCatchContext
// Reports the native method context and forwards the active exception without a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl ReticuleCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecUpdateReticule
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041690 : SelectActorForSound
// Uses the supplied sound actor, then the possessed pawn, then this controller as the sound actor.
AActor* __thiscall AR6PlayerController::SelectActorForSound(AR6SoundReplicationInfo* soundInfo)
{
    if (soundInfo != nullptr)
        return soundInfo;
    APawn* pawn = this->Pawn;
    if (pawn != nullptr)
        return pawn;
    return this;
}

// Inferred PE32 voice-record view; native flags occupy separate DWORDs rather than script bitfields.
struct NativeVoicePriorityRecord
{
    AR6SoundReplicationInfo* aSoundRepInfo; // +0x00
    USound* sndPlayVoice; // +0x04
    int iPriority; // +0x08
    byte eSlotUse; // +0x0c
    byte EPawnType; // +0x0d
    byte untouchedBytes[2]; // +0x0e: these methods leave both bytes untouched.
    float fTimeStart; // +0x10
    uint playingWord; // +0x14: native tests the entire word.
    uint waitWord; // +0x18: separate from the 24-byte script struct's packed flag.
};

// R6Engine.dll @ 100416f0 : AR6PlayerController::StopAndRemoveVoices
// Stops an active voice, removes matching queue pointers, frees the captured record and decrements the referenced
// index.
void __thiscall AR6PlayerController::StopAndRemoveVoices(int& queueIndex)
{
    // Descriptive native frame: removal key EBP-14, rethrow/caught EBP-18/-1c, saved ESP EBP-28.
    struct StopVoicesFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        uint* removalKey;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &StopVoicesExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    NativeVoicePriorityRecord** queueData = reinterpret_cast<NativeVoicePriorityRecord**>(
        reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
    int* indexReference = &queueIndex;
    uint indexWord = reinterpret_cast<uint&>(*indexReference);
    NativeVoicePriorityRecord* capturedRecord = *reinterpret_cast<NativeVoicePriorityRecord**>(
        reinterpret_cast<byte*>(queueData) + indexWord * 4U);
    uint activeWord = capturedRecord->playingWord; // Native reads this before enabling catch state 0.
    FArray* queue = reinterpret_cast<FArray*>(&this->m_PlayVoicesPriority);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    nativeFrame.removalKey = reinterpret_cast<uint*>(capturedRecord);
    if (activeWord != 0) {
        AActor* actor = this->AR6PlayerController::SelectActorForSound(capturedRecord->aSoundRepInfo);
        byte* engine = **(byte***)&EngineGPEngineImport;
        USound* sound = capturedRecord->sndPlayVoice;
        void* audio = *reinterpret_cast<void**>(engine + 0x48);
        using StopSound = void (__thiscall*)(void*, AActor*, USound*);
        byte* audioTable = *reinterpret_cast<byte**>(audio);
        (*reinterpret_cast<StopSound*>(audioTable + 0x100))(audio, actor, sound);
        indexReference = &queueIndex; // Native reloads the incoming reference after EBX held the sound pointer.
    }
    RemoveMatchingWords4(queue, reinterpret_cast<const uint*>(&nativeFrame.removalKey));
    FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
    allocator->Free(capturedRecord); // The borrowed removal-key word does not replace the captured owner pointer.
    uint currentIndex = reinterpret_cast<uint&>(*indexReference);
    void* previousChain = nativeFrame.previousExceptionList;
    reinterpret_cast<uint&>(*indexReference) = currentIndex - 1U;
    ExceptionList = previousChain;
}

// R6Engine.dll @ 1004178a : StopVoicesCatchPointer
// Copies the caught text pointer at EBP-1c into the parent's rethrow slot at EBP-18.
__declspec(naked) __declspec(noreturn) void __cdecl StopVoicesCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004179e : StopVoicesCatchContext
// Reports the native voice-removal context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl StopVoicesCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerStopAndRemoveVoices
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100417c0 : AR6PlayerController::PlayPriority
// Starts one due voice at the requested priority unless an earlier active record requires waiting.
int __thiscall AR6PlayerController::PlayPriority(int priority)
{
    // Descriptive native frame: array EBP-30, caught/rethrow EBP-24/-20, level EBP-1c, saved ESP EBP-3c.
    struct PlayPriorityFrame {
        uint savedEDI, savedESI, savedEBX, activeData, activeCount, activeMax, caughtText, rethrowText;
        ULevel* cachedLevel;
        int hasActiveAtPriority;
        uint indexWord;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &PlayPriorityExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    ULevel* xLevel = this->XLevel;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    nativeFrame.cachedLevel = xLevel;
    if (xLevel == nullptr) {
        ExceptionList = nativeFrame.previousExceptionList;
        return 0;
    }
    nativeFrame.activeData = 0;
    nativeFrame.activeCount = 0;
    nativeFrame.activeMax = 0;
    byte& guardState = *(byte*)&nativeFrame.exceptionState;
    guardState = 1;
    nativeFrame.hasActiveAtPriority = 0;
    FArray* activeIndices = reinterpret_cast<FArray*>(&nativeFrame.activeData);
    uint indexWord = 0;
    while (true) {
        int liveCount = reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count;
        nativeFrame.indexWord = indexWord;
        if ((int)indexWord >= liveCount)
            break;
        NativeVoicePriorityRecord** queue = reinterpret_cast<NativeVoicePriorityRecord**>(
            reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
        NativeVoicePriorityRecord* record = queue[indexWord];
        if (record == nullptr || record->iPriority != priority) {
            xLevel = nativeFrame.cachedLevel;
            ++indexWord;
            continue;
        }
        if (record->playingWord != 0) {
            int addedAt = activeIndices->FArray::Add(1, 4);
            *reinterpret_cast<uint*>(nativeFrame.activeData + (uint)addedAt * 4U) = indexWord;
            xLevel = nativeFrame.cachedLevel;
            nativeFrame.hasActiveAtPriority = 1;
            ++indexWord;
            continue;
        }
        float10 startTime = record->fTimeStart; // Native FLD32 followed by FCOMP64; equal/unordered skip.
        if (!(startTime < (float10)*reinterpret_cast<double*>(reinterpret_cast<byte*>(xLevel) + 0xd4))) {
            xLevel = nativeFrame.cachedLevel;
            ++indexWord;
            continue;
        }
        bool mayStart = true;
        uint activeIndex = 0;
        while ((int)activeIndex < (int)nativeFrame.activeCount) {
            int priorIndex = *reinterpret_cast<int*>(nativeFrame.activeData + activeIndex * 4U);
            if (priorIndex >= 0
                && priorIndex < reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count) {
                queue = reinterpret_cast<NativeVoicePriorityRecord**>(
                    reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
                NativeVoicePriorityRecord* prior = queue[priorIndex];
                if (prior->waitWord != 0) { // Native wait DWORD at +18, separate from the playing DWORD at +14.
                    mayStart = false;
                    break;
                }
            }
            ++activeIndex;
        }
        queue = reinterpret_cast<NativeVoicePriorityRecord**>(
            reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
        record = queue[indexWord];
        AR6SoundReplicationInfo* soundInfo = record->aSoundRepInfo;
        APawn* associatedPawn = soundInfo == nullptr ? nullptr : soundInfo->m_pawnOwner;
        if (associatedPawn != nullptr) {
            if (associatedPawn->APawn::IsAlive() == 0) {
                this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(nativeFrame.indexWord));
                indexWord = nativeFrame.indexWord;
                xLevel = nativeFrame.cachedLevel;
                ++indexWord;
                continue;
            }
        }
        if (mayStart) {
            queue = reinterpret_cast<NativeVoicePriorityRecord**>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
            record = queue[indexWord];
            AActor* actor = this->AR6PlayerController::SelectActorForSound(record->aSoundRepInfo);
            byte* engine = **(byte***)&EngineGPEngineImport;
            void* audio = *reinterpret_cast<void**>(engine + 0x48);
            // The incoming priority word becomes the actor argument after the final selection.
            reinterpret_cast<AActor*&>(priority) = actor;
            queue = reinterpret_cast<NativeVoicePriorityRecord**>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
            record = queue[indexWord];
            uint slot = record->eSlotUse;
            USound* sound = record->sndPlayVoice;
            using PlayVoice = void (__thiscall*)(void*, AActor*, USound*, uint, int);
            byte* audioTable = *reinterpret_cast<byte**>(audio);
            (*reinterpret_cast<PlayVoice*>(audioTable + 0x84))(
                audio, reinterpret_cast<AActor*&>(priority), sound, slot, 0);
            queue = reinterpret_cast<NativeVoicePriorityRecord**>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
            record = queue[indexWord];
            record->playingWord = 1;
            int addedAt = activeIndices->FArray::Add(1, 4);
            *reinterpret_cast<uint*>(nativeFrame.activeData + (uint)addedAt * 4U) = indexWord;
            nativeFrame.hasActiveAtPriority = 1;
            break;
        }
        xLevel = nativeFrame.cachedLevel;
        ++indexWord;
    }
    nativeFrame.activeCount = 0;
    nativeFrame.activeMax = 0;
    activeIndices->FArray::Realloc(4);
    guardState = 0;
    DestroyWordArrayStorage(activeIndices);
    void* previousChain = nativeFrame.previousExceptionList;
    int result = nativeFrame.hasActiveAtPriority;
    ExceptionList = previousChain;
    return result;
}

// R6Engine.dll @ 1004198e : PlayPriorityCatchPointer
// Copies the caught text pointer at EBP-24 into the parent's EBP-20 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl PlayPriorityCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100419c0 : AR6PlayerController::Destroy
// Removes all aliases of each queued voice pointer, frees each captured pointer once and invokes base actor
// destruction.
void __thiscall AR6PlayerController::Destroy(void)
{
    // Descriptive native frame: controller EBP-14, caught/rethrow EBP-1c/-18, saved ESP EBP-28.
    struct DestroyFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        AR6PlayerController* controller;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ControllerDestroyExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.controller = this;
    nativeFrame.exceptionState = 0;
    byte* controller = (byte*)this;
    while (*(int*)(controller + 0x904) > 0) {
        FArray* queue = (FArray*)(controller + 0x900);
        uint* data = *(uint**)queue;
        uint recordAddress = data[0];
        uint indexWord = 0;
        while ((int)indexWord < *(int*)((byte*)queue + 4)) {
            data = *(uint**)queue;
            if (*(uint*)((byte*)data + indexWord * 4U) == recordAddress) {
                RemoveRecords4(queue, (int)indexWord, 1);
                --indexWord;
            }
            ++indexWord;
        }
        FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
        allocator->Free((void*)recordAddress);
        controller = (byte*)nativeFrame.controller;
    }
    reinterpret_cast<AActor*>(controller)->AActor::Destroy();
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10041a53 : ControllerDestroyCatchPointer
// Copies the caught text pointer at EBP-1c into the parent's EBP-18 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl ControllerDestroyCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041a67 : ControllerDestroyCatchContext
// Reports the native controller-destruction context and forwards the active exception without creating a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl ControllerDestroyCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerDestroy
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041a90 : AR6PlayerController::execPlayVoicesPriority
// Evaluates a voice request, resolves priority conflicts and appends a native record unless a duplicate suppresses it.
// Native ABI view retains the incoming frame word for the voice slot in its high byte.
void __thiscall AR6PlayerController::execPlayVoicesPriority(FFrame* stack, void* unusedResult)
{
    // Descriptive frame: eSlotUse aliases EBP+b; caught/rethrow EBP-3c/-38; saved ESP EBP-48.
    struct VoiceRequestFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        uint waitWord, recordWord, startedImmediately, delayWord, priorityWord, suppressAppend, indexWord;
        uint soundWord, soundInfoWord;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ExecVoicesExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* scriptFrame = stack;
    byte** codeCursor = &scriptFrame->Code;
    byte* code = *codeCursor;
    AR6SoundReplicationInfo*& aAudioRepInfo = reinterpret_cast<AR6SoundReplicationInfo*&>(nativeFrame.soundInfoWord);
    USound*& sndPlayVoice = reinterpret_cast<USound*&>(nativeFrame.soundWord);
    byte& eSlotUse = *((byte*)&stack + 3);
    int& iPriority = reinterpret_cast<int&>(nativeFrame.priorityWord);
    int& bWaitToFinishSound = reinterpret_cast<int&>(nativeFrame.waitWord);
    float& fTime = reinterpret_cast<float&>(nativeFrame.delayWord);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    aAudioRepInfo = nullptr;
    byte token = *code++;
    *codeCursor = code;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
    UObject* firstReceiver = scriptFrame->Object;
    nativeFrame.exceptionState = 0; // The first opcode/cursor/table-base/receiver reads precede this state.
    firstTable[token](firstReceiver, scriptFrame, &aAudioRepInfo);
    // The remaining operands read Code/Object before clearing their actual live output eSlotUse.
    auto readOperand = [&](void* destination, bool byteOutput) {
        byte* currentCode = *codeCursor;
        UObject* receiver = scriptFrame->Object;
        if (byteOutput)
            *(byte*)destination = 0;
        else
            *(uint*)destination = 0;
        byte opcode = *currentCode++;
        *codeCursor = currentCode;
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[opcode](receiver, scriptFrame, destination);
    };
    readOperand(&sndPlayVoice, false);
    readOperand(&eSlotUse, true);
    readOperand(&iPriority, false);
    readOperand(&bWaitToFinishSound, false);
    readOperand(&fTime, false);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        UObject* receiver = scriptFrame->Object;
        *codeCursor = code + 1;
        ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, scriptFrame, nullptr);
    }
    byte* engine = **(byte***)&EngineGPEngineImport;
    if (*reinterpret_cast<void**>(engine + 0x48) == nullptr) {
          ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    if (sndPlayVoice == nullptr) {
        AActor* actor = this->AR6PlayerController::SelectActorForSound(aAudioRepInfo);
        actor->UObject::GetName();
          ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
    NativeVoicePriorityRecord* record =
        reinterpret_cast<NativeVoicePriorityRecord*>(allocator->Malloc(0x1c, nativeTextNew));
    nativeFrame.recordWord = reinterpret_cast<uint>(record);
    if (record == nullptr) {
          ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    auto queueRecord = [&](uint index) {
        NativeVoicePriorityRecord** queue = reinterpret_cast<NativeVoicePriorityRecord**>(
            reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
        return *reinterpret_cast<NativeVoicePriorityRecord**>(reinterpret_cast<byte*>(queue) + index * 4U);
    };
    auto startVoice = [&]() {
        AActor* actor = this->AR6PlayerController::SelectActorForSound(aAudioRepInfo);
        uint currentSlot = eSlotUse;
        byte* currentEngine = **(byte***)&EngineGPEngineImport;
        void* audio = *reinterpret_cast<void**>(currentEngine + 0x48);
        byte* audioTable = *reinterpret_cast<byte**>(audio);
        USound* currentSound = sndPlayVoice;
        using PlaySound = void (__thiscall*)(void*, AActor*, USound*, uint, int);
        (*reinterpret_cast<PlaySound*>(audioTable + 0x84))(audio, actor, currentSound, currentSlot, 0);
    };
    bool matchingVoiceFound = false;
    uint& suppressAppend = nativeFrame.suppressAppend;
    uint& startedImmediately = nativeFrame.startedImmediately;
    uint& index = nativeFrame.indexWord;
    float10 zero = nativeFloatZero;
    // Native FUCOMPP: only ordered positive/negative zero selects the special priority paths.
    float10 testedDelay = fTime;
    bool orderedZeroDelay = testedDelay == zero;
    suppressAppend = 0;
    startedImmediately = 0;
    if (orderedZeroDelay) {
        if (iPriority == 5) {
            for (index = 0;
                (int)index < reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count; ++index) {
                NativeVoicePriorityRecord* existing = queueRecord(index);
                if (existing->aSoundRepInfo == aAudioRepInfo &&
                    (existing->playingWord == 0 || existing->iPriority != 5 || existing->waitWord == 0)) {
                    // The referenced index is decremented after removing matching pointers.
                    this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(index));
                }
            }
            startVoice();
            startedImmediately = 1;
        } else if (iPriority == 10) {
            for (index = 0;
                (int)index < reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count; ++index) {
                NativeVoicePriorityRecord* existing = queueRecord(index);
                if (existing->aSoundRepInfo == aAudioRepInfo) {
                    if (existing->iPriority != 10) {
                        if (existing->iPriority == 15) {
                            this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(index));
                        }
                        continue;
                    }
                    if (existing->playingWord == 0 || existing->waitWord == 0) {
                        this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(index));
                        continue;
                    }
                    if (existing->sndPlayVoice == sndPlayVoice) {
                        suppressAppend = 1;
                    }
                    matchingVoiceFound = true;
                } else if (existing->playingWord != 0 && existing->sndPlayVoice == sndPlayVoice) {
                    matchingVoiceFound = true;
                    suppressAppend = 1;
                } else if (aAudioRepInfo != nullptr) {
                    AR6PawnReplicationInfo* owner = aAudioRepInfo->m_PawnRepInfo;
                    if (owner != nullptr && owner->m_PawnType == 1 &&
                        existing->EPawnType == 1 && existing->iPriority >= 15) {
                        this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(index));
                    }
                }
            }
            if (!matchingVoiceFound) {
                startVoice();
                startedImmediately = 1;
            }
        } else if (iPriority == 15) {
            for (index = 0;
                (int)index < reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count; ++index) {
                NativeVoicePriorityRecord* existing = queueRecord(index);
                if (existing->iPriority == 15 && existing->aSoundRepInfo == aAudioRepInfo &&
                    (existing->playingWord == 0 || existing->waitWord == 0)) {
                    this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(index));
                }
            }
        }
    }
    if (suppressAppend) {
        ExceptionList = nativeFrame.previousExceptionList;
        return; // Native leaves the just-allocated record unreleased on this duplicate path.
    }
    record->aSoundRepInfo = aAudioRepInfo;
    record->sndPlayVoice = sndPlayVoice;
    record->iPriority = iPriority;
    record->eSlotUse = eSlotUse;
    float10 delayValue = fTime;
    ULevel* level = this->XLevel;
    float10 startTime = delayValue + *reinterpret_cast<double*>(reinterpret_cast<byte*>(level) + 0xd4);
    uint currentStarted = startedImmediately;
    record->fTimeStart = (float)startTime; // Native FADD64 then FSTP32; no intermediate double store.
    uint currentWait = reinterpret_cast<uint&>(bWaitToFinishSound);
    record->waitWord = currentWait;
    record->playingWord = currentStarted;
    AR6SoundReplicationInfo* currentInfo = aAudioRepInfo;
    if (currentInfo == nullptr) {
        record->EPawnType = 1;
    } else {
        AR6PawnReplicationInfo* owner = currentInfo->m_PawnRepInfo;
        if (owner == nullptr) {
            currentInfo->UObject::GetFullName(nullptr);
            record = reinterpret_cast<NativeVoicePriorityRecord*>(nativeFrame.recordWord);
            record->EPawnType = 1;
        } else {
            record->EPawnType = owner->m_PawnType;
        }
    }
    FArray* queue = reinterpret_cast<FArray*>(&this->m_PlayVoicesPriority);
    int queueSlot = queue->FArray::Add(1, 4);
    uint* queueData = reinterpret_cast<uint*>(reinterpret_cast<NativeArrayHeader32*>(queue)->dataAddress);
    uint recordWord = nativeFrame.recordWord;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(queueData) + (uint)queueSlot * 4U) = recordWord;
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10041e31 : ExecVoicesCatchPointer
// Copies the caught text pointer at EBP-3c into the parent's EBP-38 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl ExecVoicesCatchPointer(void)
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

// R6Engine.dll @ 10041e45 : ExecVoicesCatchContext
// Reports the native voice-enqueue context and forwards the active exception without creating a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl ExecVoicesCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecPlayVoicesPriority
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041e70 : AR6PlayerController::PlayVoicesPriority
// Removes finished active voices, then tries priorities 5, 10 and 15 until one reports an active voice.
void __thiscall AR6PlayerController::PlayVoicesPriority(void)
{
    // Descriptive frame: index EBP-14, caught/rethrow EBP-1c/-18, saved ESP EBP-28.
    struct VoicePollFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, indexWord;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &VoicePollExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    int queueCount = reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (queueCount > 0) {
        uint indexWord = 0;
        while (true) {
            int liveCount = reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count;
            nativeFrame.indexWord = indexWord;
            if ((int)indexWord >= liveCount)
                break;
            NativeVoicePriorityRecord** data = reinterpret_cast<NativeVoicePriorityRecord**>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
            NativeVoicePriorityRecord* record = data[indexWord];
            if (record->playingWord != 0) {
                AActor* actor = this->AR6PlayerController::SelectActorForSound(record->aSoundRepInfo);
                data = reinterpret_cast<NativeVoicePriorityRecord**>(
                    reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).dataAddress);
                byte** engineSlot = *(byte***)&EngineGPEngineImport;
                record = data[indexWord];
                byte* engine = *engineSlot;
                USound* sound = record->sndPlayVoice;
                void* audio = *reinterpret_cast<void**>(engine + 0x48);
                using IsVoicePlaying = int (__thiscall*)(void*, AActor*, USound*);
                byte* audioTable = *reinterpret_cast<byte**>(audio);
                if ((*reinterpret_cast<IsVoicePlaying*>(audioTable + 0x8c))(audio, actor, sound) == 0) {
                    this->AR6PlayerController::StopAndRemoveVoices(reinterpret_cast<int&>(nativeFrame.indexWord));
                    indexWord = nativeFrame.indexWord;
                }
            }
            ++indexWord;
        }
        if (reinterpret_cast<NativeArrayHeader32&>(this->m_PlayVoicesPriority).count > 0
            && this->AR6PlayerController::PlayPriority(5) == 0 &&
            this->AR6PlayerController::PlayPriority(10) == 0)
            this->AR6PlayerController::PlayPriority(15);
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10041f43 : VoicePollCatchPointer
// Copies the caught text pointer at EBP-1c into the parent's EBP-18 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl VoicePollCatchPointer(void)
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

// R6Engine.dll @ 10041f57 : VoicePollCatchContext
// Reports the native method context and forwards the active exception without creating a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl VoicePollCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerPlayVoicesPriority
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041f80 : AR6PlayerController::Tick
// Polls voice playback when audio exists, then forwards both raw tick argument words and the full base result.
int __thiscall AR6PlayerController::Tick(float deltaTime, ELevelTick tickType)
{
    // Descriptive frame: caught/rethrow EBP-18/-14, saved ESP EBP-24.
    struct TickFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ControllerTickExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte* engine = **(byte***)&EngineGPEngineImport;
    void* audio = *(void**)(engine + 0x48);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (audio != nullptr)
        this->AR6PlayerController::PlayVoicesPriority();
    uint tickTypeWord = reinterpret_cast<uint&>(tickType);
    uint deltaTimeWord = reinterpret_cast<uint&>(deltaTime);
    // Raw-word view of APlayerController::Tick(float, ELevelTick); the native wrapper performs no FP load or
    // conversion.
    using BaseTickRaw = int (__thiscall*)(APlayerController*, uint, uint);
    BaseTickRaw baseTick = reinterpret_cast<BaseTickRaw&>(APlayerControllerTickImport);
    int result = baseTick(this, deltaTimeWord, tickTypeWord);
    ExceptionList = nativeFrame.previousExceptionList;
    return result;
}

// R6Engine.dll @ 10041fe2 : ControllerTickCatchPointer
// Copies the caught text pointer at EBP-18 into the parent's EBP-14 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl ControllerTickCatchPointer(void)
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

// R6Engine.dll @ 10041ff6 : ControllerTickCatchContext
// Reports the native method context and forwards the active exception without creating a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl ControllerTickCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerTick
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100435b0 : PlayerControllerDtorState0Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [APlayerControllerDestructorImport]
    }
}

// R6Engine.dll @ 100435b9 : PlayerControllerDtorState1Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x900
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100435c7 : PlayerControllerDtorState2Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x9d8
        jmp DestroyTenStrings
    }
}

// R6Engine.dll @ 100435d5 : PlayerControllerDtorState3Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa50
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100435e4 : PlayerControllerDtorState4Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa5c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100435f3 : PlayerControllerDtorState5Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa68
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043602 : PlayerControllerDtorState6Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDtorState6Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa74
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043620 : PlayerControllerCtorState0Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [APlayerControllerDestructorImport]
    }
}

// R6Engine.dll @ 10043629 : PlayerControllerCtorState1Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x900
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043637 : PlayerControllerCtorState2Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x9d8
        jmp DestroyTenStrings
    }
}

// R6Engine.dll @ 10043645 : PlayerControllerCtorState3Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa50
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043654 : PlayerControllerCtorState4Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa5c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043663 : PlayerControllerCtorState5Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerCtorState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa68
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10044880 : KeyLocalizationState1Cleanup
// Tail-enters the current FString destructor on the parent's localized text storage.
__declspec(naked) void __cdecl KeyLocalizationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044889 : KeyLocalizationState2Cleanup
// Tail-enters the current FString destructor on the parent's enum key name storage.
__declspec(naked) void __cdecl KeyLocalizationState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044892 : KeyLocalizationState3Cleanup
// Tail-enters the current FString destructor on the parent's converted text storage.
__declspec(naked) void __cdecl KeyLocalizationState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004489b : KeyLocalizationState0Cleanup
// Clears the constructed-result bit before destroying the hidden return object if construction completed.
__declspec(naked) void __cdecl KeyLocalizationState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x34]
        and eax,1
        je no_result
        and dword ptr [ebp-0x34],0xfffffffe
        mov ecx,dword ptr [ebp+4]
        jmp dword ptr [FStringDestructorImport]
    no_result:
        ret
    }
}

// R6Engine.dll @ 10044910 : TrainingLocalizationState1Cleanup
// Tail-enters the current FString destructor on the parent's section storage at EBP-0x28.
__declspec(naked) void __cdecl TrainingLocalizationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044919 : TrainingLocalizationState2Cleanup
// Tail-enters the current FString destructor on the parent's key storage at EBP-0x40.
__declspec(naked) void __cdecl TrainingLocalizationState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x40]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044922 : TrainingLocalizationState3Cleanup
// Tail-enters the current FString destructor on the parent's package storage at EBP-0x34.
__declspec(naked) void __cdecl TrainingLocalizationState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004492b : TrainingLocalizationState4Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 4 storage at EBP-0x9c.
__declspec(naked) void __cdecl TrainingLocalizationState4Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x9c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044937 : TrainingLocalizationState5Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 5 storage at EBP-0x384.
__declspec(naked) void __cdecl TrainingLocalizationState5Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x384]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044943 : TrainingLocalizationState6Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 6 storage at EBP-0x84.
__declspec(naked) void __cdecl TrainingLocalizationState6Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x84]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004494f : TrainingLocalizationState7Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 7 storage at EBP-0x234.
__declspec(naked) void __cdecl TrainingLocalizationState7Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x234]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004495b : TrainingLocalizationState8Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 8 storage at EBP-0x1ec.
__declspec(naked) void __cdecl TrainingLocalizationState8Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1ec]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044967 : TrainingLocalizationState9Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 9 storage at EBP-0x24c.
__declspec(naked) void __cdecl TrainingLocalizationState9Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044973 : TrainingLocalizationState10Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 10 storage at EBP-0x324.
__declspec(naked) void __cdecl TrainingLocalizationState10Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x324]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004497f : TrainingLocalizationState11Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 11 storage at EBP-0xb4.
__declspec(naked) void __cdecl TrainingLocalizationState11Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xb4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1004498b : TrainingLocalizationState15Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 15 storage at EBP-0xcc.
__declspec(naked) void __cdecl TrainingLocalizationState15Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xcc]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044997 : TrainingLocalizationState12Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 12 storage at EBP-0x3e4.
__declspec(naked) void __cdecl TrainingLocalizationState12Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3e4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449a3 : TrainingLocalizationState13Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 13 storage at EBP-0xe4.
__declspec(naked) void __cdecl TrainingLocalizationState13Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xe4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449af : TrainingLocalizationState14Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 14 storage at EBP-0x264.
__declspec(naked) void __cdecl TrainingLocalizationState14Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x264]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449bb : TrainingLocalizationState16Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 16 storage at EBP-0x33c.
__declspec(naked) void __cdecl TrainingLocalizationState16Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x33c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449c7 : TrainingLocalizationState17Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 17 storage at EBP-0x114.
__declspec(naked) void __cdecl TrainingLocalizationState17Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x114]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449d3 : TrainingLocalizationState18Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 18 storage at EBP-0x27c.
__declspec(naked) void __cdecl TrainingLocalizationState18Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x27c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449df : TrainingLocalizationState19Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 19 storage at EBP-0xfc.
__declspec(naked) void __cdecl TrainingLocalizationState19Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xfc]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449eb : TrainingLocalizationState20Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 20 storage at EBP-0x144.
__declspec(naked) void __cdecl TrainingLocalizationState20Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x144]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100449f7 : TrainingLocalizationState21Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 21 storage at EBP-0x294.
__declspec(naked) void __cdecl TrainingLocalizationState21Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x294]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a03 : TrainingLocalizationState22Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 22 storage at EBP-0x12c.
__declspec(naked) void __cdecl TrainingLocalizationState22Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x12c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a0f : TrainingLocalizationState23Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 23 storage at EBP-0x2ac.
__declspec(naked) void __cdecl TrainingLocalizationState23Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2ac]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a1b : TrainingLocalizationState24Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 24 storage at EBP-0x15c.
__declspec(naked) void __cdecl TrainingLocalizationState24Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x15c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a27 : TrainingLocalizationState25Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 25 storage at EBP-0x39c.
__declspec(naked) void __cdecl TrainingLocalizationState25Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x39c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a33 : TrainingLocalizationState26Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 26 storage at EBP-0x174.
__declspec(naked) void __cdecl TrainingLocalizationState26Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x174]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a3f : TrainingLocalizationState27Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 27 storage at EBP-0x18c.
__declspec(naked) void __cdecl TrainingLocalizationState27Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a4b : TrainingLocalizationState28Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 28 storage at EBP-0x354.
__declspec(naked) void __cdecl TrainingLocalizationState28Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x354]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a57 : TrainingLocalizationState29Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 29 storage at EBP-0x2c4.
__declspec(naked) void __cdecl TrainingLocalizationState29Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2c4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a63 : TrainingLocalizationState30Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 30 storage at EBP-0x1bc.
__declspec(naked) void __cdecl TrainingLocalizationState30Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1bc]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a6f : TrainingLocalizationState31Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 31 storage at EBP-0x3cc.
__declspec(naked) void __cdecl TrainingLocalizationState31Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3cc]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a7b : TrainingLocalizationState32Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 32 storage at EBP-0x1a4.
__declspec(naked) void __cdecl TrainingLocalizationState32Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1a4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a87 : TrainingLocalizationState33Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 33 storage at EBP-0x2dc.
__declspec(naked) void __cdecl TrainingLocalizationState33Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2dc]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a93 : TrainingLocalizationState34Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 34 storage at EBP-0x1d4.
__declspec(naked) void __cdecl TrainingLocalizationState34Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1d4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044a9f : TrainingLocalizationState35Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 35 storage at EBP-0x2f4.
__declspec(naked) void __cdecl TrainingLocalizationState35Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2f4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044aab : TrainingLocalizationState36Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 36 storage at EBP-0x60.
__declspec(naked) void __cdecl TrainingLocalizationState36Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x60]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044ab4 : TrainingLocalizationState37Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 37 storage at EBP-0x36c.
__declspec(naked) void __cdecl TrainingLocalizationState37Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x36c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044ac0 : TrainingLocalizationState38Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 38 storage at EBP-0x30c.
__declspec(naked) void __cdecl TrainingLocalizationState38Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044acc : TrainingLocalizationState39Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 39 storage at EBP-0x21c.
__declspec(naked) void __cdecl TrainingLocalizationState39Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x21c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044ad8 : TrainingLocalizationState40Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 40 storage at EBP-0x3b4.
__declspec(naked) void __cdecl TrainingLocalizationState40Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3b4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044ae4 : TrainingLocalizationState41Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 41 storage at EBP-0x204.
__declspec(naked) void __cdecl TrainingLocalizationState41Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x204]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044af0 : TrainingLocalizationState42Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 42 storage at EBP-0xa8.
__declspec(naked) void __cdecl TrainingLocalizationState42Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xa8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044afc : TrainingLocalizationState43Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 43 storage at EBP-0x90.
__declspec(naked) void __cdecl TrainingLocalizationState43Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x90]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b08 : TrainingLocalizationState44Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 44 storage at EBP-0x78.
__declspec(naked) void __cdecl TrainingLocalizationState44Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x78]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b11 : TrainingLocalizationState45Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 45 storage at EBP-0x6c.
__declspec(naked) void __cdecl TrainingLocalizationState45Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x6c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b1a : TrainingLocalizationState46Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 46 storage at EBP-0xf0.
__declspec(naked) void __cdecl TrainingLocalizationState46Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xf0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b26 : TrainingLocalizationState47Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 47 storage at EBP-0xd8.
__declspec(naked) void __cdecl TrainingLocalizationState47Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xd8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b32 : TrainingLocalizationState48Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 48 storage at EBP-0xc0.
__declspec(naked) void __cdecl TrainingLocalizationState48Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xc0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b3e : TrainingLocalizationState49Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 49 storage at EBP-0x120.
__declspec(naked) void __cdecl TrainingLocalizationState49Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x120]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b4a : TrainingLocalizationState50Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 50 storage at EBP-0x108.
__declspec(naked) void __cdecl TrainingLocalizationState50Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x108]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b56 : TrainingLocalizationState51Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 51 storage at EBP-0x150.
__declspec(naked) void __cdecl TrainingLocalizationState51Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x150]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b62 : TrainingLocalizationState52Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 52 storage at EBP-0x138.
__declspec(naked) void __cdecl TrainingLocalizationState52Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x138]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b6e : TrainingLocalizationState53Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 53 storage at EBP-0x1b0.
__declspec(naked) void __cdecl TrainingLocalizationState53Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1b0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b7a : TrainingLocalizationState54Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 54 storage at EBP-0x198.
__declspec(naked) void __cdecl TrainingLocalizationState54Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x198]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b86 : TrainingLocalizationState55Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 55 storage at EBP-0x180.
__declspec(naked) void __cdecl TrainingLocalizationState55Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x180]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b92 : TrainingLocalizationState56Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 56 storage at EBP-0x168.
__declspec(naked) void __cdecl TrainingLocalizationState56Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x168]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044b9e : TrainingLocalizationState57Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 57 storage at EBP-0x1c8.
__declspec(naked) void __cdecl TrainingLocalizationState57Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1c8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044baa : TrainingLocalizationState58Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 58 storage at EBP-0x1e0.
__declspec(naked) void __cdecl TrainingLocalizationState58Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1e0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bb6 : TrainingLocalizationState59Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 59 storage at EBP-0x210.
__declspec(naked) void __cdecl TrainingLocalizationState59Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x210]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bc2 : TrainingLocalizationState60Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 60 storage at EBP-0x1f8.
__declspec(naked) void __cdecl TrainingLocalizationState60Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1f8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bce : TrainingLocalizationState61Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 61 storage at EBP-0x240.
__declspec(naked) void __cdecl TrainingLocalizationState61Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x240]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bda : TrainingLocalizationState62Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 62 storage at EBP-0x228.
__declspec(naked) void __cdecl TrainingLocalizationState62Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x228]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044be6 : TrainingLocalizationState63Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 63 storage at EBP-0x288.
__declspec(naked) void __cdecl TrainingLocalizationState63Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x288]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bf2 : TrainingLocalizationState64Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 64 storage at EBP-0x270.
__declspec(naked) void __cdecl TrainingLocalizationState64Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x270]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044bfe : TrainingLocalizationState65Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 65 storage at EBP-0x258.
__declspec(naked) void __cdecl TrainingLocalizationState65Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x258]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c0a : TrainingLocalizationState66Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 66 storage at EBP-0x2e8.
__declspec(naked) void __cdecl TrainingLocalizationState66Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2e8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c16 : TrainingLocalizationState67Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 67 storage at EBP-0x2d0.
__declspec(naked) void __cdecl TrainingLocalizationState67Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2d0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c22 : TrainingLocalizationState68Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 68 storage at EBP-0x2b8.
__declspec(naked) void __cdecl TrainingLocalizationState68Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2b8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c2e : TrainingLocalizationState69Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 69 storage at EBP-0x2a0.
__declspec(naked) void __cdecl TrainingLocalizationState69Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2a0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c3a : TrainingLocalizationState70Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 70 storage at EBP-0x300.
__declspec(naked) void __cdecl TrainingLocalizationState70Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x300]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c46 : TrainingLocalizationState71Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 71 storage at EBP-0x318.
__declspec(naked) void __cdecl TrainingLocalizationState71Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x318]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c52 : TrainingLocalizationState72Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 72 storage at EBP-0x3a8.
__declspec(naked) void __cdecl TrainingLocalizationState72Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3a8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c5e : TrainingLocalizationState73Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 73 storage at EBP-0x390.
__declspec(naked) void __cdecl TrainingLocalizationState73Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x390]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c6a : TrainingLocalizationState74Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 74 storage at EBP-0x378.
__declspec(naked) void __cdecl TrainingLocalizationState74Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x378]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c76 : TrainingLocalizationState75Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 75 storage at EBP-0x360.
__declspec(naked) void __cdecl TrainingLocalizationState75Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x360]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c82 : TrainingLocalizationState76Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 76 storage at EBP-0x348.
__declspec(naked) void __cdecl TrainingLocalizationState76Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x348]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c8e : TrainingLocalizationState77Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 77 storage at EBP-0x330.
__declspec(naked) void __cdecl TrainingLocalizationState77Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x330]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044c9a : TrainingLocalizationState78Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 78 storage at EBP-0x3c0.
__declspec(naked) void __cdecl TrainingLocalizationState78Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3c0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044ca6 : TrainingLocalizationState79Cleanup
// Tail-enters the current FString destructor on the parent's action-key state 79 storage at EBP-0x3d8.
__declspec(naked) void __cdecl TrainingLocalizationState79Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3d8]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10032f88 : TrainingLocalizationCatchContext
// Reports the native training-localization context and forwards the active exception without creating a new frame.
__declspec(naked) __declspec(noreturn) void __cdecl TrainingLocalizationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecLocalizeTraining
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044cc0 : LocStringActionState1Cleanup
// Tail-enters the current FString destructor on the parent's template storage.
__declspec(naked) void __cdecl LocStringActionState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044cc9 : LocStringActionState2Cleanup
// Tail-enters the current FString destructor on the parent's action key storage.
__declspec(naked) void __cdecl LocStringActionState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x20]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044cd2 : LocStringActionState3Cleanup
// Tail-enters the current FString destructor on the parent's localized key storage.
__declspec(naked) void __cdecl LocStringActionState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 1003315e : LocStringActionCatchContext
// Reports the native method context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl LocStringActionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerExecGetLocStringWithActionKey
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045560 : PlayPriorityState1Cleanup
// Tail-enters the shared raw-array destructor on the parent's active-index array at EBP-30.
__declspec(naked) void __cdecl PlayPriorityState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp DestroyWordArrayStorage
    }
}

// R6Engine.dll @ 100419a2 : PlayPriorityCatchContext
// Reports the native priority-playback context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PlayPriorityCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PlayerControllerPlayPriority
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045de0 : InitializeAR6PlayerControllerClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6PlayerControllerClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = APlayerControllerPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred local words at entryESP-8 and entryESP-4.
        UClass* withinClass;
        UClass* parentClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x54.
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
        union { // entryESP-0x1c is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6PlayerController::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload saved words after the configuration callback.
    parentClass = captures.parentClass;
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6PlayerController;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 4;
    packet.guidWords[1] = 0;
    packet.classSize = 0xa90;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6PlayerController::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6PlayerControllerClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10047fc0 : DestroyAR6PlayerControllerClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6PlayerControllerClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6PlayerController::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045e70 : PublishAR6PlayerControllerAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6PlayerControllerAutoClass(void)
{
    autoclassAR6PlayerController = &AR6PlayerController::PrivateStaticClass;
}

// R6Engine.dll @ 10047b20 : RegisterAR6PlayerControllerPlayVoicesPriorityNative
// Registers native index0xaa6 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerPlayVoicesPriorityNative(void)
{
    AR6PlayerControllerPlayVoicesPriorityRegistrationResult =
        GRegisterNative(0xaa6, intAR6PlayerControllerexecPlayVoicesPriority);
}

// R6Engine.dll @ 10047b40 : RegisterAR6PlayerControllerGetLocStringWithActionKeyNative
// Registers native index0x5f1 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerGetLocStringWithActionKeyNative(void)
{
    AR6PlayerControllerGetLocStringWithActionKeyRegistrationResult =
        GRegisterNative(0x5f1,
            intAR6PlayerControllerexecGetLocStringWithActionKey);
}

// R6Engine.dll @ 10047b60 : RegisterAR6PlayerControllerLocalizeTrainingNative
// Registers native index0xaa4 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerLocalizeTrainingNative(void)
{
    AR6PlayerControllerLocalizeTrainingRegistrationResult =
        GRegisterNative(0xaa4, intAR6PlayerControllerexecLocalizeTraining);
}

// R6Engine.dll @ 10047b80 : RegisterAR6PlayerControllerFindPlayerNative
// Registers native index0x4c8 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerFindPlayerNative(void)
{
    AR6PlayerControllerFindPlayerRegistrationResult = GRegisterNative(0x4c8, intAR6PlayerControllerexecFindPlayer);
}

// R6Engine.dll @ 10047ba0 : RegisterAR6PlayerControllerDebugFunctionNative
// Registers native index0x730 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerDebugFunctionNative(void)
{
    AR6PlayerControllerDebugFunctionRegistrationResult =
        GRegisterNative(0x730, intAR6PlayerControllerexecDebugFunction);
}

// R6Engine.dll @ 10047bc0 : RegisterAR6PlayerControllerUpdateSpectatorReticuleNative
// Registers native index0x8a5 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerUpdateSpectatorReticuleNative(void)
{
    AR6PlayerControllerUpdateSpectatorReticuleRegistrationResult =
        GRegisterNative(0x8a5,
            intAR6PlayerControllerexecUpdateSpectatorReticule);
}

// R6Engine.dll @ 10047be0 : RegisterAR6PlayerControllerUpdateReticuleNative
// Registers native index0x733 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerUpdateReticuleNative(void)
{
    AR6PlayerControllerUpdateReticuleRegistrationResult =
        GRegisterNative(0x733, intAR6PlayerControllerexecUpdateReticule);
}

// R6Engine.dll @ 10047c00 : RegisterAR6PlayerControllerUpdateCircumstantialActionNative
// Registers native index0x8a3 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PlayerControllerUpdateCircumstantialActionNative(void)
{
    AR6PlayerControllerUpdateCircumstantialActionRegistrationResult =
        GRegisterNative(0x8a3,
            intAR6PlayerControllerexecUpdateCircumstantialAction);
}

// R6Engine.dll @ 100434d8 : VoteSessionAbortExceptionHandler
// Supplies the exact string-cleanup FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl VoteSessionAbortExceptionHandler(void)
{
    __asm {
        mov eax,offset voteSessionAbortInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100434f8 : UpdateLadderStatExceptionHandler
// Supplies the exact string-cleanup FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl UpdateLadderStatExceptionHandler(void)
{
    __asm {
        mov eax,offset updateLadderStatInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043611 : PlayerControllerDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset playerControllerDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043672 : PlayerControllerConstructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl PlayerControllerConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset playerControllerCtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044800 : DebugFunctionExceptionHandler
// Selects the script bridge's exact FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl DebugFunctionExceptionHandler(void)
{
    __asm {
        mov eax,offset debugFunctionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044810 : UpdateCircumstantialActionExceptionHandler
// Selects the script bridge's exact FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl UpdateCircumstantialActionExceptionHandler(void)
{
    __asm {
        mov eax,offset updateCircumstantialActionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044cf0 : UpdateSpectatorReticuleExceptionHandler
// Selects the script bridge's exact FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl UpdateSpectatorReticuleExceptionHandler(void)
{
    __asm {
        mov eax,offset spectatorReticuleFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d00 : UpdateReticuleExceptionHandler
// Selects the script bridge's exact FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl UpdateReticuleExceptionHandler(void)
{
    __asm {
        mov eax,offset reticuleFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044cdb : LocStringActionExceptionHandler
// Selects the exact string-lifetime FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl LocStringActionExceptionHandler(void)
{
    __asm {
        mov eax,offset locStringActionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100448b5 : KeyLocalizationExceptionHandler
// Selects the exact temporary/result cleanup FuncInfo without creating another dispatcher frame.
__declspec(naked) void __cdecl KeyLocalizationExceptionHandler(void)
{
    __asm {
        mov eax,offset keyLocalizationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044cb2 : TrainingLocalizationExceptionHandler
// Selects the exact training string-lifetime FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl TrainingLocalizationExceptionHandler(void)
{
    __asm {
        mov eax,offset trainingLocalizationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045550 : StopVoicesExceptionHandler
// Selects the exact voice-removal FuncInfo without creating another dispatcher frame.
__declspec(naked) void __cdecl StopVoicesExceptionHandler(void)
{
    __asm {
        mov eax,offset stopVoicesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045568 : PlayPriorityExceptionHandler
// Selects the exact active-index lifetime FuncInfo without creating another dispatcher frame.
__declspec(naked) void __cdecl PlayPriorityExceptionHandler(void)
{
    __asm {
        mov eax,offset playPriorityFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045580 : ControllerDestroyExceptionHandler
// Selects the exact controller-destruction FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl ControllerDestroyExceptionHandler(void)
{
    __asm {
        mov eax,offset controllerDestroyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045590 : ExecVoicesExceptionHandler
// Selects the exact script voice-enqueue FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl ExecVoicesExceptionHandler(void)
{
    __asm {
        mov eax,offset execVoicesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100455a0 : VoicePollExceptionHandler
// Selects the exact method FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl VoicePollExceptionHandler(void)
{
    __asm {
        mov eax,offset voicePollFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100455b0 : ControllerTickExceptionHandler
// Selects the exact method FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl ControllerTickExceptionHandler(void)
{
    __asm {
        mov eax,offset controllerTickFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10011840 : AR6PlayerController::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6PlayerController::DeletingDestructor(uint flags)
{
    byte deleteFlags = reinterpret_cast<byte&>(flags); // Captured once; native RET4 consumes the full incoming word.
    if ((deleteFlags & 2U) != 0) {
        int count = *(int*)((byte*)this - 4);
        using Destructor = void (__thiscall*)(void*);
        struct ArrayPacketView { // Inferred four-word outgoing packet at entryESP-0x1c.
            void* objects;
            uint stride;
            int count;
            Destructor destroy;
        } packet;
        packet.destroy = (Destructor)&AR6PlayerControllerDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xa90;
        packet.objects = this;
        _eh_vector_destructor_iterator_(packet.objects, packet.stride, packet.count, packet.destroy);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            NativeAllocatorVtablePrefix* allocatorVtable = *reinterpret_cast<NativeAllocatorVtablePrefix**>(allocator);
            void* freeArgument = cookie; // Outgoing argument precedes the current virtual target read.
            using Free = void (__thiscall*)(void*, void*);
            Free free = reinterpret_cast<Free&>(allocatorVtable->freeAddress);
            free(allocator, freeArgument);
        }
        return cookie;
    }
    this->AR6PlayerController::~AR6PlayerController();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xa90;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll data @ 1005c07c : ProjectionUnwindMap
// State one destroys the canvas before state zero destroys the scene.
const NativeUnwindEntry ProjectionUnwindMap[2] = {
    { -1, ((uint)&ProjectionState0Cleanup) },
    { 0, ((uint)&ProjectionState1Cleanup) }
};

// R6Engine.dll data @ 1005c08c : ProjectionFuncInfo
// Projection owns two cleanup states and no local catch handlers.
const NativeFunctionInfoPrefix ProjectionFuncInfo = { 0x19930520, 0x2, ((uint)&ProjectionUnwindMap), 0, 0, 0 };

// R6Engine.dll @ 1002ff80 : ProjectPointToViewport
// Projects a point, writes both coordinates, then tests strict viewport/depth bounds and destroys its utilities.
int __cdecl ProjectPointToViewport(UViewport* viewport, float* outputX, float* outputY,
    float worldX, float worldY, float worldZ, float cameraX, float cameraY, float cameraZ,
    int cameraPitch, int cameraYaw, int cameraRoll)
{
    struct ProjectionFrame { // Inferred 32-bit entry-ESP-relative storage; runtime EBP holds the viewport.
        uint savedEdi, savedEsi, savedEbp; // Entry ESP-0xee4/-0xee0/-0xedc.
        float scaledX, scaledY, depth; // Entry ESP-0xed8/-0xed4/-0xed0.
        uint* pointSpill;
        float* matrixSpill;
        uint pointWords[4], transformedWords[4], projectedWords[4];
        byte sceneStorage[0x1e0]; // Entry ESP-0xe94; bounded native region, not a recovered class declaration.
        byte canvasStorage[0xca8]; // Entry ESP-0xcb4 through ESP-0x0d.
        void* previousExceptionList;
        void* exceptionHandler;
        int cleanupState;
    } nativeFrame;
    nativeFrame.cleanupState = -1;
    nativeFrame.exceptionHandler = &ProjectionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    UViewport* capturedViewport = viewport;
    APlayerController* cameraActor = capturedViewport->Actor;
    float cameraFov = cameraActor->FovAngle;
    FRotator cameraRotation;
    cameraRotation.Pitch = cameraPitch;
    cameraRotation.Yaw = cameraYaw;
    cameraRotation.Roll = cameraRoll;
    FVector cameraLocation;
    cameraLocation.X = cameraX;
    cameraLocation.Y = cameraY;
    cameraLocation.Z = cameraZ;
    FCameraSceneNode* scene = reinterpret_cast<FCameraSceneNode*>(nativeFrame.sceneStorage);
    ::new (reinterpret_cast<void*>(scene)) FCameraSceneNode(
        capturedViewport, cameraActor, cameraLocation, cameraRotation, cameraFov);
    FCanvasUtil* canvas = reinterpret_cast<FCanvasUtil*>(nativeFrame.canvasStorage);
    nativeFrame.cleanupState = 0;
    ::new (reinterpret_cast<void*>(canvas)) FCanvasUtil(
        capturedViewport, reinterpret_cast<FRenderInterface*>(nullptr), 1, 0);
    FVector worldPoint;
    worldPoint.X = worldX;
    worldPoint.Y = worldY;
    worldPoint.Z = worldZ;
    *(byte*)&nativeFrame.cleanupState = 1;
    using Project = FPlane* (__thiscall*)(FSceneNode*, FPlane*, FVector);
    reinterpret_cast<Project&>(FSceneNodeProjectImport)(scene, reinterpret_cast<FPlane*>(nativeFrame.projectedWords),
        worldPoint);
    uint projectedX = nativeFrame.projectedWords[0];
    uint projectedY = nativeFrame.projectedWords[1];
    uint projectedZ = nativeFrame.projectedWords[2];
    nativeFrame.pointWords[0] = projectedX;
    nativeFrame.pointWords[1] = projectedY;
    nativeFrame.pointWords[2] = projectedZ;
    nativeFrame.pointWords[3] = 0x3f800000; // Input W is forced to one; Project's W is not read.
    nativeFrame.pointSpill = nativeFrame.pointWords;
    nativeFrame.matrixSpill = reinterpret_cast<float*>(reinterpret_cast<byte*>(canvas) + 0x14);
    uint* point = nativeFrame.pointSpill;
    float* matrix = nativeFrame.matrixSpill;
    float10 columns[4]; // Native computes every column, including the discarded W, in interleaved x87 registers.
    for (int column = 0; column < 4; ++column)
        columns[column] = (float10)reinterpret_cast<float&>(point[0]) * matrix[column];
    for (int row = 1; row < 4; ++row) {
        float10 terms[4];
        for (int column = 0; column < 4; ++column)
            terms[column] = (float10)reinterpret_cast<float&>(point[row]) * matrix[row * 4 + column];
        columns[0] += terms[0];
        columns[2] += terms[2];
        columns[1] += terms[1];
        columns[3] += terms[3];
    }
    for (int column = 0; column < 4; ++column)
        reinterpret_cast<float&>(nativeFrame.transformedWords[column]) = (float)columns[column];
    uint transformedX = nativeFrame.transformedWords[0];
    uint transformedZ = nativeFrame.transformedWords[2];
    uint transformedY = nativeFrame.transformedWords[1];
    reinterpret_cast<uint&>(nativeFrame.scaledX) = transformedX;
    float10 screenX = (float10)nativeFrame.scaledX;
    reinterpret_cast<uint&>(nativeFrame.depth) = transformedZ;
    UCanvas* renderCanvas = *reinterpret_cast<UCanvas**>(reinterpret_cast<byte*>(capturedViewport) + 0x7c);
    screenX /= renderCanvas->m_fStretchX;
    reinterpret_cast<uint&>(nativeFrame.scaledY) = transformedY;
    float* xDestination = outputX;
    float* yDestination = outputY;
    float10 screenY = (float10)nativeFrame.scaledY / renderCanvas->m_fStretchY;
    nativeFrame.scaledY = (float)screenY;
    *xDestination = (float)screenX;
    *yDestination = nativeFrame.scaledY; // Read after X's store, preserving aliasing with the Y scratch word.
    float zeroForX = nativeFloatZero;
    bool inside = screenX > (float10)zeroForX; // X remains extended after the output copy.
    UCanvas* boundsCanvas = nullptr;
    if (inside) {
        boundsCanvas = *reinterpret_cast<UCanvas**>(reinterpret_cast<byte*>(capturedViewport) + 0x7c);
        float clipX = boundsCanvas->ClipX;
        inside = screenX < (float10)clipX;
    }
    if (inside) {
        float10 currentY = (float10)nativeFrame.scaledY;
        float zeroForY = nativeFloatZero;
        inside = currentY > (float10)zeroForY;
    }
    if (inside) {
        float10 currentY = (float10)nativeFrame.scaledY;
        float clipY = boundsCanvas->ClipY;
        inside = currentY < (float10)clipY;
    }
    if (inside) {
        float10 currentDepth = (float10)nativeFrame.depth;
        float zeroForDepth = nativeFloatZero;
        inside = currentDepth > (float10)zeroForDepth;
    }
    if (inside) {
        float10 currentDepth = (float10)nativeFrame.depth;
        float farDepth = nativeFloatOne;
        inside = currentDepth < (float10)farDepth;
    }
    *(byte*)&nativeFrame.cleanupState = 0;
    canvas->FCanvasUtil::~FCanvasUtil();
    nativeFrame.cleanupState = -1;
    scene->FCameraSceneNode::~FCameraSceneNode();
    ExceptionList = nativeFrame.previousExceptionList;
    return inside ? 1 : 0;
}

// R6Engine.dll @ 10044850 : destroy the scene using the dispatcher's entry-ESP frame binding
__declspec(naked) void ProjectionState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xe94]
        jmp dword ptr [FCameraSceneNodeDestructorImport]
    }
}

// R6Engine.dll @ 1004485c : destroy the canvas using the dispatcher's entry-ESP frame binding
__declspec(naked) void ProjectionState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xcb4]
        jmp dword ptr [FCanvasUtilDestructorImport]
    }
}

// R6Engine.dll @ 10044868 : select the projection cleanup tables without creating a frame
__declspec(naked) void ProjectionExceptionHandler(void)
{
    __asm {
        mov eax,offset ProjectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10007db0 : DestroyTenStrings
// Destroys ten consecutive 12-byte FString elements through the current ordinary-string destructor import.
void __thiscall DestroyTenStrings(void* strings)
{
    using DestroyString = void (__thiscall *)(FString*);
    using DestroyArray = void (__stdcall *)(void*, uint, uint, DestroyString);
    DestroyString destroy = reinterpret_cast<DestroyString&>(FStringDestructorImport);
    ((DestroyArray)((uint)&_eh_vector_destructor_iterator_))(strings, 12, 10, destroy);
}
