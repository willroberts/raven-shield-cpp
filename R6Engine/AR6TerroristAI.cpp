#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// Address-only private labels retain their canonical body and inherited register/stack contracts.
// These labels are never invoked with ordinary C++ call syntax and add no implementations.
// R6Engine.dll code alias @ 1003cb3a : within canonical body 1003cb00
__declspec(naked) void TerroristHearingCategoriesZeroAndThreeNativeEntry(void);
// R6Engine.dll code alias @ 1003cb58 : within canonical body 1003cb00
__declspec(naked) void TerroristHearingCategoryOneNativeEntry(void);
// R6Engine.dll code alias @ 1003cb61 : within canonical body 1003cb00
__declspec(naked) void TerroristHearingCategoryTwoNativeEntry(void);

// R6Engine.dll data @ 1004cf90 : AR6TerroristAIVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6TerroristAI::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6TerroristAIVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10053a58 : nativeTextAR6TerroristAICanHear
extern const ushort nativeTextAR6TerroristAICanHear[24];

// R6Engine.dll data @ 10053bd0 : nativeTextAR6TerroristAIExecCallBackupForAttack
extern const ushort nativeTextAR6TerroristAIExecCallBackupForAttack[40];

// R6Engine.dll data @ 10053c20 : nativeTextAR6TerroristAIExecCallBackupForInvestigation
extern const ushort nativeTextAR6TerroristAIExecCallBackupForInvestigation[47];

// R6Engine.dll data @ 10053d20 : nativeTextAR6TerroristAIExecCallVisibleTerrorist
extern const ushort nativeTextAR6TerroristAIExecCallVisibleTerrorist[41];

// R6Engine.dll data @ 10053c80 : nativeTextAR6TerroristAIExecFindBetterShotLocation
extern const ushort nativeTextAR6TerroristAIExecFindBetterShotLocation[43];

// R6Engine.dll data @ 10053ac0 : nativeTextAR6TerroristAIExecGetNextRandomNode
extern const ushort nativeTextAR6TerroristAIExecGetNextRandomNode[38];

// R6Engine.dll data @ 10053cd8 : nativeTextAR6TerroristAIExecHaveAClearShot
extern const ushort nativeTextAR6TerroristAIExecHaveAClearShot[35];

// R6Engine.dll data @ 10053a00 : nativeTextAR6TerroristAIExecIsAttackSpotStillValid
extern const ushort nativeTextAR6TerroristAIExecIsAttackSpotStillValid[43];

// R6Engine.dll data @ 10053b88 : nativeTextAR6TerroristAIExecMakeBackupList
extern const ushort nativeTextAR6TerroristAIExecMakeBackupList[35];

// R6Engine.dll data @ 10053b0c : nativeTextAR6TerroristAIHaveAClearShot
extern const ushort nativeTextAR6TerroristAIHaveAClearShot[31];

// R6Engine.dll data @ 100556aa : nativeTextR6TerroristAI
extern const ushort nativeTextR6TerroristAI[14];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void TerroristAIConstructorExceptionHandler(void);
__declspec(naked) void TerroristAIConstructorState0Cleanup(void);
__declspec(naked) void TerroristAIConstructorState1Cleanup(void);
__declspec(naked) void TerroristAIDestructorExceptionHandler(void);
__declspec(naked) void TerroristAIDestructorState0Cleanup(void);
__declspec(naked) void TerroristAIDestructorState1Cleanup(void);
__declspec(naked) void TerroristAIDestructorState2Cleanup(void);
__declspec(naked) void TerroristBackupAttackCatchContext(void);
__declspec(naked) void TerroristBackupAttackCatchPointer(void);
__declspec(naked) void TerroristBackupInvestigationCatchContext(void);
__declspec(naked) void TerroristBackupInvestigationCatchPointer(void);
__declspec(naked) void TerroristBackupListCatchContext(void);
__declspec(naked) void TerroristBackupListCatchPointer(void);
__declspec(naked) void TerroristBetterShotCatchContext(void);
__declspec(naked) void TerroristBetterShotCatchPointer(void);
__declspec(naked) void TerroristClearBridgeCatchContext(void);
__declspec(naked) void TerroristClearBridgeCatchPointer(void);
__declspec(naked) void TerroristHearingCatchContext(void);
__declspec(naked) void TerroristHearingCatchPointer(void);
__declspec(naked) void TerroristRandomCatchContext(void);
__declspec(naked) void TerroristRandomCatchPointer(void);
__declspec(naked) void TerroristShotCatchContext(void);
__declspec(naked) void TerroristShotCatchPointer(void);
__declspec(naked) void TerroristSpotCatchContext(void);
__declspec(naked) void TerroristSpotCatchPointer(void);
__declspec(naked) void TerroristVisibleCatchContext(void);
__declspec(naked) void TerroristVisibleCatchPointer(void);

// R6Engine.dll data @ 10050e2c : nativeFloat4EPlus02
extern const float nativeFloat4EPlus02;

// R6Engine.dll data @ 1005d7bc : terroristHearingUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristHearingUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d7cc : terroristHearingCatch
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry terroristHearingCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TerroristHearingCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristHearingCatchContext) }
};

// R6Engine.dll data @ 1005d7ec : terroristHearingTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristHearingTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristHearingCatch) }
};

// R6Engine.dll data @ 1005d800 : terroristHearingInfo
// Exact terrorist-hearing parent-frame metadata.
const NativeFunctionInfoPrefix terroristHearingInfo = { 0x19930520, 0x2, ((uint)&terroristHearingUnwind), 0x1,
    ((uint)&terroristHearingTry), 0 };

// R6Engine.dll data @ 1003cbd8 : terroristHearingCaseTargets
// Compiler dispatch targets for category indices0..3; code addresses are retained as data.
const uint terroristHearingCaseTargets[4] = {
    ((uint)&TerroristHearingCategoriesZeroAndThreeNativeEntry), ((uint)&TerroristHearingCategoryOneNativeEntry),
        ((uint)&TerroristHearingCategoryTwoNativeEntry), ((uint)&TerroristHearingCategoriesZeroAndThreeNativeEntry)
};

// R6Engine.dll data @ 1005db7c : terroristVisibleUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristVisibleUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005db8c : terroristVisibleCatch
// Typed pointer at EBP-1c followed by context catch-all.
const NativeCatchEntry terroristVisibleCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TerroristVisibleCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristVisibleCatchContext) }
};

// R6Engine.dll data @ 1005dbac : terroristVisibleTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristVisibleTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristVisibleCatch) }
};

// R6Engine.dll data @ 1005dbc0 : terroristVisibleInfo
// Exact visible-terrorist script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristVisibleInfo = { 0x19930520, 0x2, ((uint)&terroristVisibleUnwind), 0x1,
    ((uint)&terroristVisibleTry), 0 };

// R6Engine.dll data @ 1005db1c : terroristClearBridgeUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristClearBridgeUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005db2c : terroristClearBridgeCatch
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry terroristClearBridgeCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TerroristClearBridgeCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristClearBridgeCatchContext) }
};

// R6Engine.dll data @ 1005db4c : terroristClearBridgeTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristClearBridgeTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristClearBridgeCatch) }
};

// R6Engine.dll data @ 1005db60 : terroristClearBridgeInfo
// Exact clear-shot script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristClearBridgeInfo = { 0x19930520, 0x2, ((uint)&terroristClearBridgeUnwind), 0x1,
    ((uint)&terroristClearBridgeTry), 0 };

// R6Engine.dll data @ 1005dabc : terroristBetterShotUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristBetterShotUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dacc : terroristBetterShotCatch
// Typed pointer at EBP-1c followed by context catch-all.
const NativeCatchEntry terroristBetterShotCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TerroristBetterShotCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristBetterShotCatchContext) }
};

// R6Engine.dll data @ 1005daec : terroristBetterShotTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristBetterShotTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristBetterShotCatch) }
};

// R6Engine.dll data @ 1005db00 : terroristBetterShotInfo
// Exact better-shot-location parent-frame metadata.
const NativeFunctionInfoPrefix terroristBetterShotInfo = { 0x19930520, 0x2, ((uint)&terroristBetterShotUnwind), 0x1,
    ((uint)&terroristBetterShotTry), 0 };

// R6Engine.dll data @ 1005da5c : terroristBackupInvestigationUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristBackupInvestigationUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005da6c : terroristBackupInvestigationCatch
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry terroristBackupInvestigationCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TerroristBackupInvestigationCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristBackupInvestigationCatchContext) }
};

// R6Engine.dll data @ 1005da8c : terroristBackupInvestigationTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristBackupInvestigationTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristBackupInvestigationCatch) }
};

// R6Engine.dll data @ 1005daa0 : terroristBackupInvestigationInfo
// Exact backup-investigation script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristBackupInvestigationInfo = { 0x19930520, 0x2,
    ((uint)&terroristBackupInvestigationUnwind), 0x1, ((uint)&terroristBackupInvestigationTry), 0 };

// R6Engine.dll data @ 1005d9fc : terroristBackupAttackUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristBackupAttackUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005da0c : terroristBackupAttackCatch
// Typed pointer at EBP-28 followed by context catch-all.
const NativeCatchEntry terroristBackupAttackCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&TerroristBackupAttackCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristBackupAttackCatchContext) }
};

// R6Engine.dll data @ 1005da2c : terroristBackupAttackTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristBackupAttackTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristBackupAttackCatch) }
};

// R6Engine.dll data @ 1005da40 : terroristBackupAttackInfo
// Exact backup-attack script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristBackupAttackInfo = { 0x19930520, 0x2, ((uint)&terroristBackupAttackUnwind), 0x1,
    ((uint)&terroristBackupAttackTry), 0 };

// R6Engine.dll data @ 1005d99c : terroristBackupListUnwind
// Two terminal null-action states; this caller owns no local cleanup.
const NativeUnwindEntry terroristBackupListUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d9ac : terroristBackupListCatch
// Typed pointer at EBP-28 followed by context catch-all.
const NativeCatchEntry terroristBackupListCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&TerroristBackupListCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristBackupListCatchContext) }
};

// R6Engine.dll data @ 1005d9cc : terroristBackupListTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristBackupListTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristBackupListCatch) }
};

// R6Engine.dll data @ 1005d9e0 : terroristBackupListInfo
// Exact backup-list script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristBackupListInfo = { 0x19930520, 0x2, ((uint)&terroristBackupListUnwind), 0x1,
    ((uint)&terroristBackupListTry), 0 };

// R6Engine.dll data @ 1005d8dc : terroristShotUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristShotUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d8ec : terroristShotCatch
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry terroristShotCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TerroristShotCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristShotCatchContext) }
};

// R6Engine.dll data @ 1005d90c : terroristShotTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristShotTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristShotCatch) }
};

// R6Engine.dll data @ 1005d920 : terroristShotInfo
// Exact clear-shot parent-frame metadata.
const NativeFunctionInfoPrefix terroristShotInfo = { 0x19930520, 0x2, ((uint)&terroristShotUnwind), 0x1,
    ((uint)&terroristShotTry), 0 };

// R6Engine.dll data @ 1005d87c : terroristRandomUnwind
// Two terminal null-action states; neither sorted-path local owns cleanup.
const NativeUnwindEntry terroristRandomUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d88c : terroristRandomCatch
// Typed pointer at EBP-18 followed by context catch-all.
const NativeCatchEntry terroristRandomCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&TerroristRandomCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristRandomCatchContext) }
};

// R6Engine.dll data @ 1005d8ac : terroristRandomTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristRandomTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristRandomCatch) }
};

// R6Engine.dll data @ 1005d8c0 : terroristRandomInfo
// Exact next-node script-bridge parent-frame metadata.
const NativeFunctionInfoPrefix terroristRandomInfo = { 0x19930520, 0x2, ((uint)&terroristRandomUnwind), 0x1,
    ((uint)&terroristRandomTry), 0 };

// R6Engine.dll data @ 1005d75c : terroristSpotUnwind
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry terroristSpotUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d76c : terroristSpotCatch
// Typed pointer at EBP-1c followed by context catch-all.
const NativeCatchEntry terroristSpotCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&TerroristSpotCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristSpotCatchContext) }
};

// R6Engine.dll data @ 1005d78c : terroristSpotTry
// State0 body/state1 catches select both handlers.
const NativeTryBlock terroristSpotTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristSpotCatch) }
};

// R6Engine.dll data @ 1005d7a0 : terroristSpotInfo
// Exact firing-spot validation parent-frame metadata.
const NativeFunctionInfoPrefix terroristSpotInfo = { 0x19930520, 0x2, ((uint)&terroristSpotUnwind), 0x1,
    ((uint)&terroristSpotTry), 0 };

// R6Engine.dll data @ 10058028 : terroristAIDestructorUnwind
// State2 string -> state1 array -> state0 base -> state-1, with no catch regions.
const NativeUnwindEntry terroristAIDestructorUnwind[3] = {
    { -1, ((uint)&TerroristAIDestructorState0Cleanup) },
    { 0, ((uint)&TerroristAIDestructorState1Cleanup) },
    { 0x1, ((uint)&TerroristAIDestructorState2Cleanup) }
};

// R6Engine.dll data @ 10058040 : terroristAIDestructorInfo
// Exact three-state destructor metadata.
const NativeFunctionInfoPrefix terroristAIDestructorInfo = { 0x19930520, 0x3, ((uint)&terroristAIDestructorUnwind), 0,
    0, 0 };

// R6Engine.dll data @ 10058088 : terroristAIConstructorUnwind
// State1 array -> state0 base -> state-1; no completed-string cleanup action is added.
const NativeUnwindEntry terroristAIConstructorUnwind[2] = {
    { -1, ((uint)&TerroristAIConstructorState0Cleanup) },
    { 0, ((uint)&TerroristAIConstructorState1Cleanup) }
};

// R6Engine.dll data @ 10058098 : terroristAIConstructorInfo
// Exact shared default/copy constructor metadata, with no catch regions.
const NativeFunctionInfoPrefix terroristAIConstructorInfo = { 0x19930520, 0x2, ((uint)&terroristAIConstructorUnwind), 0,
    0, 0 };

// R6Engine.dll data @ 100744c0 : intAR6TerroristAIexecIsAttackSpotStillValid
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecIsAttackSpotStillValid = (Native)&AR6TerroristAI::execIsAttackSpotStillValid;

// R6Engine.dll data @ 100802e0 : AR6TerroristAIIsAttackSpotStillValidRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAIIsAttackSpotStillValidRegistrationResult = 0;

// R6Engine.dll data @ 100744c4 : intAR6TerroristAIexecCallVisibleTerrorist
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecCallVisibleTerrorist = (Native)&AR6TerroristAI::execCallVisibleTerrorist;

// R6Engine.dll data @ 1007a1b8 : AR6TerroristAICallVisibleTerroristRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAICallVisibleTerroristRegistrationResult = 0;

// R6Engine.dll data @ 100744c8 : intAR6TerroristAIexecHaveAClearShot
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecHaveAClearShot = (Native)&AR6TerroristAI::execHaveAClearShot;

// R6Engine.dll data @ 1007f8a0 : AR6TerroristAIHaveAClearShotRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAIHaveAClearShotRegistrationResult = 0;

// R6Engine.dll data @ 100744cc : intAR6TerroristAIexecFindBetterShotLocation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecFindBetterShotLocation = (Native)&AR6TerroristAI::execFindBetterShotLocation;

// R6Engine.dll data @ 10081c4c : AR6TerroristAIFindBetterShotLocationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAIFindBetterShotLocationRegistrationResult = 0;

// R6Engine.dll data @ 100744d0 : intAR6TerroristAIexecMakeBackupList
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecMakeBackupList = (Native)&AR6TerroristAI::execMakeBackupList;

// R6Engine.dll data @ 100778e8 : AR6TerroristAIMakeBackupListRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAIMakeBackupListRegistrationResult = 0;

// R6Engine.dll data @ 100744d4 : intAR6TerroristAIexecCallBackupForInvestigation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecCallBackupForInvestigation =
    (Native)&AR6TerroristAI::execCallBackupForInvestigation;

// R6Engine.dll data @ 1007d9fe : AR6TerroristAICallBackupForInvestigationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAICallBackupForInvestigationRegistrationResult = 0;

// R6Engine.dll data @ 100744d8 : intAR6TerroristAIexecCallBackupForAttack
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecCallBackupForAttack = (Native)&AR6TerroristAI::execCallBackupForAttack;

// R6Engine.dll data @ 10081c58 : AR6TerroristAICallBackupForAttackRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAICallBackupForAttackRegistrationResult = 0;

// R6Engine.dll data @ 100744dc : intAR6TerroristAIexecGetNextRandomNode
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6TerroristAIexecGetNextRandomNode = (Native)&AR6TerroristAI::execGetNextRandomNode;

// R6Engine.dll data @ 100802ec : AR6TerroristAIGetNextRandomNodeRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6TerroristAIGetNextRandomNodeRegistrationResult = 0;

// R6Engine.dll data @ 1007d4d8 : autoclassAR6TerroristAI
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6TerroristAI = nullptr;

// R6Engine.dll @ 100083f0 : AR6TerroristAI::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6TerroristAI::StaticClass(void)
{
    return &AR6TerroristAI::PrivateStaticClass; // Selected object at0x100769b0.
}

// R6Engine.dll @ 10008400 : AR6TerroristAI::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6TerroristAI::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6TerroristAI::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000ddf0 : AR6TerroristAI::eventGotoStateEngageByThreat
// Dispatches the twelve raw threat-location bytes through the captured vtable's current event slot.
void __thiscall AR6TerroristAI::eventGotoStateEngageByThreat(FVector vThreathLocation)
{
    const uint* input = (const uint*)&vThreathLocation;
    uint x = input[0], z = input[2], y = input[1];
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    uint parameters[3];
    parameters[0] = x; parameters[1] = y; parameters[2] = z;
    uint name = *(uint*)&R6ENGINE_GotoStateEngageByThreat;
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Event = void (__thiscall*)(AR6TerroristAI*, UFunction*, void*, void*);
    reinterpret_cast<Event&>(table->processEventAddress)(this, function, parameters, nullptr);
}

// R6Engine.dll @ 1000de40 : AR6TerroristAI::eventGotoPointToAttack
// Dispatches the raw destination and target pointer; lookup does not replace the captured event table.
void __thiscall AR6TerroristAI::eventGotoPointToAttack(FVector vDestination, AActor* PTarget)
{
    const uint* input = (const uint*)&vDestination;
    uint z = input[2], x = input[0], y = input[1];
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    uint parameters[4];
    parameters[1] = y; parameters[2] = z; parameters[0] = x; parameters[3] = (uint)PTarget;
    uint name = reinterpret_cast<uint&>(R6ENGINE_GotoPointToAttack);
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Event = void (__thiscall*)(AR6TerroristAI*, UFunction*, void*, void*);
    reinterpret_cast<Event&>(table->processEventAddress)(this, function, parameters, nullptr);
}

// R6Engine.dll @ 1000de90 : AR6TerroristAI::eventGotoPointAndSearch
// Dispatches the packed search parameters without normalizing Bool words or initializing the two byte-field paddings.
void __thiscall AR6TerroristAI::eventGotoPointAndSearch(FVector vDestination, uchar ePace, ulong bCallBackup,
    float fSearchTime, uchar eNewDefCon)
{
    const uint* input = (const uint*)&vDestination;
    uint x = input[0], z = input[2], y = input[1];
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    uint parameters[7]; // Native28B: Vector0,byte12,Bool16,float20,byte24; six padding bytes stay untouched.
    parameters[1] = y;
    parameters[4] = bCallBackup;
    parameters[2] = z;
    parameters[0] = x;
    parameters[5] = reinterpret_cast<uint&>(fSearchTime);
    uint name = reinterpret_cast<uint&>(R6ENGINE_GotoPointAndSearch);
    reinterpret_cast<byte&>(parameters[3]) = ePace;
    reinterpret_cast<byte&>(parameters[6]) = eNewDefCon;
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Event = void (__thiscall*)(AR6TerroristAI*, UFunction*, void*, void*);
    reinterpret_cast<Event&>(table->processEventAddress)(this, function, parameters, nullptr);
}

// R6Engine.dll @ 1000fa90 : AR6TerroristAI::operator=
// Assigns the base, raw derived fields and thirteen flags, then the backup array and no-init string.
AR6TerroristAI& __thiscall AR6TerroristAI::operator=(const AR6TerroristAI& sourceObject)
{
    const AR6TerroristAI* source = &sourceObject;
    this->AR6AIController::operator=(*source);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0x56c; offset < 0x572; ++offset) destination[offset] = input[offset];
    for (uint offset = 0x574; offset < 0x588; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint word = *(const uint*)(input + 0x588);
    uint firstFlags = *(uint*)(destination + 0x590);
    reinterpret_cast<uint&>(this->m_iStateVariable) = word;
    reinterpret_cast<uint&>(this->m_iFollowYaw) = *(const uint*)(input + 0x58c);
    uint difference = firstFlags ^ *(const uint*)(input + 0x590);
    uint flags = *(uint*)(destination + 0x590) ^ (difference & 1U);
    *(uint*)(destination + 0x590) = flags;
    for (uint mask = 2; mask <= 0x1000; mask <<= 1) {
        flags ^= (*(const uint*)(input + 0x590) ^ flags) & mask;
        *(uint*)(destination + 0x590) = flags;
    }
    for (uint offset = 0x594; offset < 0x5c0; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    for (uint offset = 0x5c0; offset < 0x5e8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset); // Assignment uses explicit forward words.
    for (uint offset = 0x5e8; offset < 0x61c; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    AssignRecords4((FArray*)(destination + 0x61c), (const FArray*)(input + 0x61c));
    for (uint offset = 0x628; offset < 0x670; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    reinterpret_cast<FStringNoInit*>(destination + 0x670)->operator=(
        *reinterpret_cast<const FStringNoInit*>(input + 0x670));
    return *this;
}

// R6Engine.dll @ 10011e30 : AR6TerroristAI::~AR6TerroristAI
// Conditionally destroys UObject state, then releases the debug string, backup array and AI-controller base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6TerroristAI::~AR6TerroristAI(AR6TerroristAI* this)
{
    uint guard[4]; // Native saved-this/previous-SEH/handler/state stack view, not additional class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristAIDestructorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6TerroristAIVirtualTable);
    guard[3] = 2;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 1;
    reinterpret_cast<FStringNoInit*>(reinterpret_cast<FStringNoInit*>(&this->m_sDebugString))->FStringNoInit::~FStringNoInit(
);
    *(byte*)&guard[3] = 0;
    DestroyWordArrayStorage(reinterpret_cast<FArray*>(&this->m_listAvailableBackup));
    guard[3] = 0xffffffff;
    this->AR6AIController::~AR6AIController();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10011eb0 : AR6TerroristAI::AR6TerroristAI (native default-constructor view)
// Constructs the imported AI base and no-init debug string while adopting the native backup-array cleanup state.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6TerroristAI* __thiscall AR6TerroristAI::AR6TerroristAI(AR6TerroristAI* this)
{
    uint guard[4]; // Exact two-state constructor metadata; derived array storage is not initialized here.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristAIConstructorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    using BaseConstructor = AAIController* (__thiscall*)(AAIController*);
    reinterpret_cast<BaseConstructor&>(AAIControllerDefaultConstructorImport)(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6TerroristAIVirtualTable);
    *(byte*)&guard[3] = 1;
    // Retail constructor writes no header words.
    ::new (reinterpret_cast<void*>(reinterpret_cast<FStringNoInit*>(&this->m_sDebugString))) FStringNoInit;
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10011f10 : AR6TerroristAI::AR6TerroristAI (native copy-constructor view)
// Copies raw controller state and constructs the owned backup array and debug string with delayed native guard states.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6TerroristAI* __thiscall AR6TerroristAI::AR6TerroristAI(AR6TerroristAI* this, const AR6TerroristAI* source)
{
    uint guard[4];
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristAIConstructorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6AIController::AR6AIController(this, source);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    *(uint*)destination = ((uint)&AR6TerroristAIVirtualTable);
    for (uint offset = 0x56c; offset < 0x572; ++offset) destination[offset] = input[offset];
    for (uint offset = 0x574; offset < 0x588; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint word = *(const uint*)(input + 0x588);
    uint firstFlags = *(uint*)(destination + 0x590);
    *(uint*)(destination + 0x588) = word;
    *(uint*)(destination + 0x58c) = *(const uint*)(input + 0x58c);
    uint difference = firstFlags ^ *(const uint*)(input + 0x590);
    uint flags = *(uint*)(destination + 0x590) ^ (difference & 1U);
    *(uint*)(destination + 0x590) = flags;
    for (uint mask = 2; mask <= 0x1000; mask <<= 1) {
        flags ^= (*(const uint*)(input + 0x590) ^ flags) & mask;
        if (mask == 0x80) guard[3] = 0; // Native computes this eighth merge BEFORE activating base cleanup.
        *(uint*)(destination + 0x590) = flags;
    }
    for (uint offset = 0x594; offset < 0x5c0; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    __asm { // Native REP MOVSD copies the ten m_aLastNode pointer words with the incoming direction flag.
        push esi
        push edi
        mov esi,input
        add esi,0x5c0
        mov edi,destination
        add edi,0x5c0
        mov ecx,10
        rep movsd
        pop edi
        pop esi
    }
    for (uint offset = 0x5e8; offset < 0x61c; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    CopyConstructRecords4((FArray*)(destination + 0x61c), (const FArray*)(input + 0x61c));
    for (uint offset = 0x628; offset < 0x670; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    *(byte*)&guard[3] = 1; // Completed array is owned before entering string copy; no completed-string state is added.
    ::new (reinterpret_cast<void*>(destination + 0x670)) FStringNoInit(
        *reinterpret_cast<const FStringNoInit*>(input + 0x670));
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10012320 : AR6TerroristAI::DeletingDestructor
// Destroys scalar or cookie-counted array storage and conditionally releases it using the low-byte flags.
void* __thiscall AR6TerroristAI::DeletingDestructor(uint flags)
{
    byte deleteFlags = (byte)flags;
    if ((deleteFlags & 2) != 0) {
        byte* cookie = (byte*)this - 4;
        uint count = *(uint*)cookie;
        using DestroyArray = void (__stdcall*)(void*, uint, uint, void (__thiscall*)(AR6TerroristAI*));
        (*(DestroyArray)((uint)&_eh_vector_destructor_iterator_))(this, 0x67c, count,
            (void (__thiscall*)(AR6TerroristAI*))((uint)&AR6TerroristAIDestructorNativeEntry));
        if ((deleteFlags & 1) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    this->AR6TerroristAI::~AR6TerroristAI();
    if ((deleteFlags & 1) != 0) {
        UObject::operator delete(this, 0x67c);
    }
    return this;
}

// R6Engine.dll @ 10013a60 : AR6TerroristAI::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6TerroristAI::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6TerroristAIConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1003c880 : execIsAttackSpotStillValid
// Retains a firing spot when its enemy distance and direct or cached route pass the native tests.
void AR6TerroristAI::execIsAttackSpotStillValid(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor + 1;
    *cursor = code;
    byte opcode = *code; // Read before catch state0; no operand is evaluated for this parameterless bridge.
    try {
        if (opcode == 0x42) {
            UObject* receiver = frame->Object;
            *cursor = code + 1;
            ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        int valid = 0;
        APawn* enemy = this->Enemy;
        if (enemy != nullptr) {
            AR6ActionSpot* spot = this->m_pActionSpot;
            if (spot != nullptr && spot->m_eFire != 0) { // m_eFire, not a Boolean bitfield.
                enemy = this->Enemy;
                APawn* pawn = this->Pawn;
                FVector* pawnLocation = &pawn->Location;
                FVector* enemyLocation = &enemy->Location;
                float10 deltaZ = (float10)pawnLocation->Z - enemyLocation->Z;
                float10 deltaY = (float10)pawnLocation->Y - enemyLocation->Y;
                float deltaX = (float)((float10)pawnLocation->X - enemyLocation->X);
                float scaledZ = (float)(deltaZ * nativeFloatHalf); // Native half-distance scale.
                float10 scaledY = deltaY * nativeFloatHalf;
                float10 scaledX = (float10)deltaX * nativeFloatHalf;
                float minimumDistanceSquared = (float)(scaledX * scaledX + scaledY * scaledY
                    + (float10)scaledZ * scaledZ); // X delta, scaled Z and final threshold spill to32f.
                FVector* spotLocation = &spot->Location;
                float10 spotZ = (float10)spotLocation->Z - enemyLocation->Z;
                float10 spotY = (float10)spotLocation->Y - enemyLocation->Y;
                float10 spotX = (float10)spotLocation->X - enemyLocation->X;
                if ((float10)minimumDistanceSquared < spotX * spotX + spotY * spotY + spotZ * spotZ) {
                    uint destination[3] = { ((uint*)spotLocation)[0], ((uint*)spotLocation)[1],
                        ((uint*)spotLocation)[2] };
                    if (pawn->APawn::walkReachable(reinterpret_cast<FVector&>(destination), 0, spot) != 0) {
                        valid = 1;
                    } else {
                        uint* zeroSource = *(uint**)&FVectorFVector0Import;
                        uint zero[3] = { zeroSource[0], zeroSource[1], zeroSource[2] }; // Raw FVector0 words.
                        AActor* currentSpot = this->m_pActionSpot;
                        APawn* currentPawn = this->Pawn;
                        float10 pathWeight = currentPawn->APawn::findPathToward(currentSpot,
                            reinterpret_cast<FVector&>(zero),
                            nullptr, 1, 0.0f);
                        // FST stores32f but leaves extended ST0 for comparison.
                        float pathWeightSpill = (float)pathWeight;
                        if ((float10)nativeFloatZero < pathWeight) {
                            valid = 1;
                            for (int routeIndex = 0; routeIndex < 16; ++routeIndex) {
                                AActor* routeNode = this->RouteCache[routeIndex];
                                if (routeNode == nullptr) break;
                                APawn* currentEnemy = this->Enemy;
                                FVector* nodeLocation = &routeNode->Location;
                                FVector* currentEnemyLocation = &currentEnemy->Location;
                                float10 routeX = (float10)nodeLocation->X - currentEnemyLocation->X;
                                float10 routeY = (float10)nodeLocation->Y - currentEnemyLocation->Y;
                                float10 routeZ = (float10)nodeLocation->Z - currentEnemyLocation->Z;
                                if (routeZ * routeZ + routeY * routeY + routeX * routeX < minimumDistanceSquared) {
                                    valid = 0; // Equality and unordered route distances retain the spot.
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (valid == 0) {
            AR6ActionSpot* currentSpot = this->m_pActionSpot;
            if (currentSpot != nullptr) currentSpot->m_pCurrentUser = nullptr;
        }
        *(int*)result = valid;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execIsAttackSpotStillValid");
        throw;
    }
}

// R6Engine.dll @ 1003ca98 : TerroristSpotCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristSpotCatchPointer(void)
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

// R6Engine.dll @ 1003caac : TerroristSpotCatchContext
// Reports firing-spot validation context before rethrowing the active exception.
__declspec(naked) void TerroristSpotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecIsAttackSpotStillValid
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003cb00 : AR6TerroristAI::CanHear
// Filters noise categories by terrorist hearing flags, then forwards the complete raw query to the base controller.
int AR6TerroristAI::CanHear(FVector noiseLocation, float loudness, AActor* noiseActor,
    ENoiseType noiseType, EPawnType pawnType)
{
    uint noiseWord = (uint)noiseType;
    uint categoryIndex = noiseWord - 1U;
    bool restricted = categoryIndex <= 3U; // Native input read, index and range comparison precede catch state0.
    try {
        if (restricted) {
            uint requiredFlag;
            switch (categoryIndex) {
            case 0:
            case 3: requiredFlag = 1; break; // m_bHearInvestigate.
            case 1: requiredFlag = 4; break; // m_bHearThreat.
            case 2: requiredFlag = 0x10; break; // m_bHearGrenade.
            }
            if ((reinterpret_cast<byte*>(this)[0x590] & requiredFlag) == 0) return 0;
        }
        uint pawnWord = (uint)pawnType;
        uint loudnessWord = reinterpret_cast<uint&>(loudness);
        AActor* actor = noiseActor;
        uint* location = reinterpret_cast<uint*>(&noiseLocation);
        uint position[3] = { location[0], location[1], location[2] };
        // Native packet view preserves the float/enum words and the full integer return.
        using HearingPacket = int (__thiscall*)(AR6AIController*, FVector, uint, AActor*, uint, uint);
        return reinterpret_cast<HearingPacket>(&AR6AIControllerCanHearNativeEntry)(
            static_cast<AR6AIController*>(this), *(FVector*)position,
            loudnessWord,
            actor, noiseWord, pawnWord);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::CanHear");
        throw;
    }
}

// R6Engine.dll @ 1003cba5 : TerroristHearingCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristHearingCatchPointer(void)
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

// R6Engine.dll @ 1003cbb9 : TerroristHearingCatchContext
// Reports terrorist-hearing context before rethrowing the active exception.
__declspec(naked) void TerroristHearingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAICanHear
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003cc90 : execGetNextRandomNode
// Chooses a connected node using recent-history scores, then shifts the ten-node history.
void AR6TerroristAI::execGetNextRandomNode(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor + 1;
    *cursor = code;
    byte opcode = *code; // This byte is read before catch state0.
    try {
        if (opcode == 0x42) {
            UObject* receiver = frame->Object;
            *cursor = code + 1;
            ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        // Native FSortedPathList storage: pointers +0, signed scores +0x80, count +0x100; only count is initialized.
        struct SortedPathStorage {
            ANavigationPoint *nodes[32];
            int scores[32];
            int count;
        };
        ANavigationPoint *anchor = this->m_aLastNode[0]; // m_aLastNode[0]
        ANavigationPoint *selectedNode = nullptr;
        if (anchor == nullptr) {
            SortedPathStorage nearby;
            ALevelInfo *level = this->Level;
            nearby.count = 0;
            ANavigationPoint *node = level->NavigationPointList; // NavigationPointList
            while (node != nullptr) {
                APawn *pawn = this->Pawn;
                FVector *pawnLocation = &pawn->Location;
                FVector *nodeLocation = &node->Location;
                float10 deltaZ = (float10)pawnLocation->Z - nodeLocation->Z;
                float10 deltaY = (float10)pawnLocation->Y - nodeLocation->Y;
                float10 deltaX = (float10)pawnLocation->X - nodeLocation->X;
                float10 distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                int distanceScore;
                // The helper consumes ST(0); only the low signed EAX word of its 64-bit conversion is compared.
                __asm {
                    fld distanceSquared
                    call TruncateX87ToSigned64
                    mov distanceScore,eax
                }
                if (distanceScore < 0x15f900) { // 1200 squared, compared after conversion rather than as a float.
                    FSortedPathList::addPath((FSortedPathList *)&nearby,node,distanceScore);
                }
                node = node->nextNavigationPoint; // nextNavigationPoint, reloaded after addPath.
            }
            APawn *pawn = this->Pawn;
            anchor = FSortedPathList::findStartAnchor((FSortedPathList *)&nearby,pawn);
        }
        if (anchor != nullptr) {
            SortedPathStorage candidates;
            candidates.count = 0;
            for (int pathIndex = 0;
                pathIndex < reinterpret_cast<NativeArrayHeader32&>(anchor->PathList).count; ++pathIndex) {
                UReachSpec **pathData = reinterpret_cast<UReachSpec**>(
                    reinterpret_cast<NativeArrayHeader32&>(anchor->PathList).dataAddress); // PathList.Data
                UReachSpec *path = pathData[pathIndex];
                int historyIndex = 0;
                while (historyIndex < 10) {
                    ANavigationPoint *historyNode = *reinterpret_cast<ANavigationPoint**>(
                        reinterpret_cast<byte*>(this) + 0x5c0 + historyIndex * 4);
                    if (historyNode == nullptr || path->End == historyNode) {
                        break;
                    }
                    ++historyIndex;
                }
                // At index 10 this native read reaches the adjacent m_huntedPawn word; retain the access.
                void *historyWord = *reinterpret_cast<void**>(reinterpret_cast<byte*>(this) + 0x5c0 + historyIndex * 4);
                if (historyWord == nullptr) {
                    historyIndex = 10;
                }
                ANavigationPoint *destination = path->End; // ReachSpec.End
                FSortedPathList::addPath((FSortedPathList *)&candidates,destination,10 - historyIndex);
            }
            if (candidates.count == 0) {
                *reinterpret_cast<ANavigationPoint**>(result) = nullptr;
                return; // An anchor with no candidates leaves the history untouched.
            }
            int selectedIndex = 0;
            if (candidates.scores[0] == 0) {
                int zeroScoreCount = 1;
                for (int index = 1; index < candidates.count && candidates.scores[index] == 0; ++index) {
                    ++zeroScoreCount;
                }
                selectedIndex = appRand() % zeroScoreCount; // Signed remainder; no negative-result repair.
            }
            selectedNode = candidates.nodes[selectedIndex];
        }

        for (int index = 8; index >= 0; --index) {
            this->m_aLastNode[index + 1] = this->m_aLastNode[index];
        }
        this->m_aLastNode[0] = selectedNode;
        *reinterpret_cast<ANavigationPoint**>(result) = selectedNode;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execGetNextRandomNode");
        throw;
    }
}

// R6Engine.dll @ 1003ce52 : TerroristRandomCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristRandomCatchPointer(void)
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

// R6Engine.dll @ 1003ce66 : TerroristRandomCatchContext
// Reports node-selection script context before rethrowing the active exception.
__declspec(naked) void TerroristRandomCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecGetNextRandomNode
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003cea0 : HaveAClearShot
// Applies the fog limit, traces to the target, and retargets a blocking hostile pawn.
int AR6TerroristAI::HaveAClearShot(FVector traceStartPoint, APawn* targetPawn)
{
    bool targetIsEnemy = targetPawn == this->Enemy; // Comparison precedes catch state0.
    try {
        uint* source = targetIsEnemy ? reinterpret_cast<uint*>(&this->LastSeenPos)
            : reinterpret_cast<uint*>(&targetPawn->Location);
        uint targetWords[3]; // Raw FVector at EBP-24, live across trace and relationship callbacks.
        targetWords[0] = source[0];
        uint targetY = source[1];
        targetWords[2] = source[2];
        AR6Pawn* ownerPawn = this->m_pawn;
        targetWords[1] = targetY;
        AZoneInfo* zone = ownerPawn->Region.Zone;
        FVector& targetPoint = *(FVector*)targetWords;
        if ((reinterpret_cast<byte*>(zone)[0x398] & 1U) != 0) {
            float10 fogRange = (float10)zone->DistanceFogEnd - zone->DistanceFogStart;
            float10 fogReduction = fogRange * nativeFloat0Point1; // Native0.1f factor.
            float10 fogLimit = (float10)zone->DistanceFogEnd - fogReduction;
            float10 deltaZ = (float10)traceStartPoint.Z - targetPoint.Z;
            float10 deltaY = (float10)traceStartPoint.Y - targetPoint.Y;
            float10 deltaX = (float10)traceStartPoint.X - targetPoint.X;
            float10 limitSquared = fogLimit * fogLimit;
            if (limitSquared < deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ) return 0;
        }
        NativeCheckResult32 hit; // Native FCheckResult offset view.
        uint* zeroSource = *(uint**)&FVectorFVector0Import;
        hit.nextAddress = 0;
        hit.actorAddress = 0;
        hit.primitiveAddress = 0;
        hit.materialAddress = 0;
        ULevel* level = this->XLevel;
        for (int index = 2; index < 8; ++index) reinterpret_cast<uint*>(&hit)[index] = 0;
        reinterpret_cast<uint&>(hit.Time) = 0x3f800000;
        reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
        uint extent[3];
        extent[0] = zeroSource[0];
        void** levelTable = *reinterpret_cast<void***>(level);
        extent[1] = zeroSource[1];
        extent[2] = zeroSource[2];
        APawn* ignoredPawn = this->Pawn;
        using SingleLineCheck = int (__thiscall*)(ULevel*, NativeCheckResult32*, AActor*, const FVector*,
            const FVector*, uint, FVector);
        reinterpret_cast<SingleLineCheck&>(levelTable[0xcc / 4])(
            level, &hit, ignoredPawn, &targetPoint, &traceStartPoint, 0x4400bf, *(FVector*)extent);
        AActor* hitActor = reinterpret_cast<AActor*>(hit.actorAddress);
        if (hitActor == nullptr) return 1;
        APawn* hitPawn = hitActor->GetPawnOrColBoxOwner();
        if (hit.actorAddress == 0 || hitPawn == targetPawn) return 1; // Recheck hit.Actor after classification.
        if (hitPawn == nullptr) return 0;
        APawn* friendObserver = this->m_pawn;
        if (friendObserver->APawn::IsFriend(hitPawn) != 0) return 0;
        APawn* neutralObserver = this->m_pawn; // Current owner after the friend callback.
        if (neutralObserver->APawn::IsNeutral(hitPawn) == 0) {
            uint lastSeen[3] = { targetWords[0], targetWords[1], targetWords[2] };
            this->Enemy = hitPawn;
            this->Focus = hitPawn;
            this->Target = hitPawn;
            reinterpret_cast<uint&>(this->LastSeenPos.X) = lastSeen[0];
            reinterpret_cast<uint&>(this->LastSeenPos.Y) = lastSeen[1];
            reinterpret_cast<uint&>(this->LastSeenPos.Z) = lastSeen[2];
        }
        return 1; // Neutral blockers also permit this shot without retargeting.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::HaveAClearShot");
        throw;
    }
}

// R6Engine.dll @ 1003d07c : TerroristShotCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristShotCatchPointer(void)
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

// R6Engine.dll @ 1003d090 : TerroristShotCatchContext
// Reports clear-shot context before rethrowing the active exception.
__declspec(naked) void TerroristShotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIHaveAClearShot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d190 : execMakeBackupList
// Rebuilds available backup controllers from group IDs, or copies the leader's group count.
void AR6TerroristAI::execMakeBackupList(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor + 1;
    *cursor = code;
    byte opcode = *code; // Read before catch state0.
    try {
        if (opcode == 0x42) {
            UObject* receiver = frame->Object;
            *cursor = code + 1;
            ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        *(byte *)result = 0; // Native writes only one byte of the script Bool result.
        AR6TerroristAI *leader = this->m_TerroristLeader; // m_TerroristLeader
        if (leader != nullptr) {
            this->m_iTerroristInGroup = leader->m_iTerroristInGroup; // m_iTerroristInGroup
            return; // The copied count does not change the false result or copy the leader's array.
        }

        UR6TerroristMgr *manager = this->m_Manager; // m_Manager
        ++reinterpret_cast<uint&>(manager->m_iCurrentGroupID); // m_iCurrentGroupID, wrapping 32-bit increment.
        manager = this->m_Manager;
        int currentGroupID = manager->m_iCurrentGroupID;
        AR6Terrorist *pawn = this->m_pawn;
        this->m_iCurrentGroupID = currentGroupID;
        int pawnGroupID = pawn->m_iGroupID; // m_iGroupID
        AR6DeploymentZone *deploymentZone = pawn->m_DZone; // m_DZone
        FArray *allowedGroups = reinterpret_cast<FArray*>(&deploymentZone->m_iGroupIDsToCall); // m_iGroupIDsToCall
        if (pawnGroupID != 0 || reinterpret_cast<NativeArrayHeader32*>(allowedGroups)->count != 0) {
            this->m_iTerroristInGroup = 0;
            FArray *backups = reinterpret_cast<FArray*>(&this->m_listAvailableBackup); // m_listAvailableBackup
            // Advances over the old count without touching entries or invoking destructors.
            for (int discardedIndex = 0;
                discardedIndex < reinterpret_cast<NativeArrayHeader32*>(backups)->count; ++discardedIndex) {
            }
            reinterpret_cast<NativeArrayHeader32*>(backups)->count = 0;
            reinterpret_cast<NativeArrayHeader32*>(backups)->capacity = 0;
            FArray::Realloc(backups,4);

            ULevel *initialLevel = this->XLevel;
            // Native start index for the actor-array scan.
            int actorIndex = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(initialLevel) + 0x104);
            for (;;) {
                ULevel *level = this->XLevel;
                const NativeArrayHeader32* actorsHeader =
                    reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(level) + 0x30);
                if (actorIndex >= actorsHeader->count) {
                    break;
                }
                AActor** actors = reinterpret_cast<AActor**>(actorsHeader->dataAddress);
                AActor *actor = actors[actorIndex];
                if (actor != nullptr) {
                    UClass *actorClass = actor->Class;
                    while (actorClass != nullptr && actorClass != &AR6Terrorist::PrivateStaticClass) {
                        actorClass = actorClass->GetSuperClass();
                    }
                    if (actorClass == &AR6Terrorist::PrivateStaticClass) {
                        AR6Terrorist *candidate = static_cast<AR6Terrorist*>(actor);
                        byte health = candidate->m_eHealth; // m_eHealth
                        int candidateGroupID = candidate->m_iGroupID;
                        if (health < 2 && candidate != this->Pawn
                                && candidateGroupID != 0) {
                            if (candidateGroupID == pawnGroupID) {
                                FArray::Add(backups,1,4);
                                int index = this->m_iTerroristInGroup;
                                AR6TerroristAI *controller = candidate->m_controller;
                                AR6TerroristAI **data = reinterpret_cast<AR6TerroristAI**>(
                                    reinterpret_cast<NativeArrayHeader32*>(backups)->dataAddress);
                                data[index] = controller;
                                ++reinterpret_cast<uint&>(this->m_iTerroristInGroup);
                            } else {
                                for (int groupIndex = 0;
                                    groupIndex < reinterpret_cast<NativeArrayHeader32*>(allowedGroups)->count;
                                    ++groupIndex) {
                                    int *groupIDs = reinterpret_cast<int*>(
                                        reinterpret_cast<NativeArrayHeader32*>(allowedGroups)->dataAddress);
                                    if (groupIDs[groupIndex] == candidateGroupID) {
                                        // Duplicate allowed IDs deliberately produce duplicate entries.
                                        FArray::Add(backups,1,4);
                                        int index = this->m_iTerroristInGroup;
                                        AR6TerroristAI **data = reinterpret_cast<AR6TerroristAI**>(
                                            reinterpret_cast<NativeArrayHeader32*>(backups)->dataAddress);
                                        AR6TerroristAI *controller = candidate->m_controller;
                                        data[index] = controller;
                                        ++reinterpret_cast<uint&>(this->m_iTerroristInGroup);
                                    }
                                }
                            }
                        }
                    }
                }
                actorIndex = (int)((uint)actorIndex + 1U);
            }
            *(byte *)result = this->m_iTerroristInGroup != 0;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execMakeBackupList");
        throw;
    }
}

// R6Engine.dll @ 1003d376 : TerroristBackupListCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristBackupListCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x28]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x24]
        push edx
        mov dword ptr [ebp-0x24],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d38a : TerroristBackupListCatchContext
// Reports backup-list script context before rethrowing the active exception.
__declspec(naked) void TerroristBackupListCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecMakeBackupList
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d3b0 : execCallBackupForAttack
// Tests two offset positions and assigns interruptible backups to weighted attack destinations.
void AR6TerroristAI::execCallBackupForAttack(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    FVector destination; // Native EBP-34, filled by operand evaluation and retained across later callbacks.
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Capture both before catch state0.
    try {
        natives[opcode](receiver, &stack, &destination);
        code = *cursor;
        receiver = frame->Object;
        byte pace = 0; // Evaluated but unused; native reuses the incoming frame-pointer slot's high byte.
        opcode = *code;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[opcode](receiver, &stack, &pace);
        code = *cursor + 1;
        *cursor = code;
        if (*code == 0x42) {
            receiver = frame->Object;
            *cursor = code + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        if (this->m_iTerroristInGroup == 0) return;

        APawn* pawn = this->Pawn;
        float10 differenceY = (float10)destination.Y - pawn->Location.Y;
        uint* firstZeroSource = *(uint**)&FVectorFVector0Import;
        ULevel* firstLevel = this->XLevel;
        float deltaY = (float)differenceY;
        float10 deltaX = (float10)destination.X - pawn->Location.X;
        float negativeX = (float)((float10)nativeFloatMinus1 * deltaX);
        float10 scaledZ = (float10)destination.Z * nativeFloat4EPlus02;
        float scaledNegativeX = (float)((float10)negativeX * nativeFloat4EPlus02);
        float scaledY = (float)((float10)deltaY * nativeFloat4EPlus02);
        float10 firstZ = scaledZ + destination.Z;
        float10 firstY = (float10)destination.Y + scaledNegativeX;
        float10 firstX = (float10)scaledY + destination.X;
        FVector firstCandidate = { (float)firstX, (float)firstY, (float)firstZ };
        float negativeY = (float)((float10)deltaY * nativeFloatMinus1);
        float scaledZSpill = (float)scaledZ; // First candidate used the extended product; second reloads this32f spill.
        float scaledX = (float)(deltaX * nativeFloat4EPlus02);
        float scaledNegativeY = (float)((float10)negativeY * nativeFloat4EPlus02);
        float10 secondZ = (float10)scaledZSpill + destination.Z;
        float10 secondY = (float10)destination.Y + scaledX;
        float10 secondX = (float10)scaledNegativeY + destination.X;
        FVector secondCandidate = { (float)secondX, (float)secondY, (float)secondZ };
        NativeCheckResult32 hit = {};
        reinterpret_cast<uint&>(hit.Time) = 0x3f800000;
        reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
        using SingleLineCheck = int (__thiscall*)(ULevel*, NativeCheckResult32*, AActor*, const FVector*,
            const FVector*, uint, FVector);
        uint firstExtent[3];
        firstExtent[0] = firstZeroSource[0];
        void** firstTable = *reinterpret_cast<void***>(firstLevel);
        firstExtent[1] = firstZeroSource[1];
        firstExtent[2] = firstZeroSource[2];
        AActor* ignoredEnemy = this->Enemy;
        reinterpret_cast<SingleLineCheck&>(firstTable[0xcc / 4])(
            firstLevel, &hit, ignoredEnemy, &firstCandidate, &destination, 0x286, *(FVector*)firstExtent);
        bool firstValid = false;
        if (hit.Time == nativeFloatOne) {
            AR6Terrorist* owner = this->m_pawn;
            AR6DeploymentZone* zone = owner->m_DZone;
            firstValid = zone->AR6DeploymentZone::HavePlaceForPawnAt(&firstCandidate) != 0;
        }
        uint* secondZeroSource = *(uint**)&FVectorFVector0Import;
        uint secondExtent[3];
        secondExtent[0] = secondZeroSource[0];
        ULevel* secondLevel = this->XLevel;
        void** secondTable = *reinterpret_cast<void***>(secondLevel);
        secondExtent[1] = secondZeroSource[1];
        secondExtent[2] = secondZeroSource[2];
        ignoredEnemy = this->Enemy;
        reinterpret_cast<SingleLineCheck&>(secondTable[0xcc / 4])(
            secondLevel, &hit, ignoredEnemy, &secondCandidate, &destination, 0x286, *(FVector*)secondExtent);
        bool secondValid = false; // All hit words, including Time, carry over from the first trace/placement callback.
        if (hit.Time == nativeFloatOne) {
            AR6Terrorist* owner = this->m_pawn;
            AR6DeploymentZone* zone = owner->m_DZone;
            secondValid = zone->AR6DeploymentZone::HavePlaceForPawnAt(&secondCandidate) != 0;
        }
        int destinationCutoff;
        int firstCutoff = 0;
        int secondCutoff = 0;
        if (firstValid) {
            if (secondValid) {
                destinationCutoff = 50;
                firstCutoff = 75;
                secondCutoff = 100;
            } else {
                destinationCutoff = 66;
                firstCutoff = 100;
            }
        } else if (secondValid) {
            destinationCutoff = 66;
            secondCutoff = 100;
        } else {
            destinationCutoff = 100;
        }
        for (int index = 0; index < this->m_iTerroristInGroup; index = (int)((uint)index + 1U)) {
            AR6TerroristAI** backups = reinterpret_cast<AR6TerroristAI**>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_listAvailableBackup).dataAddress);
            AR6TerroristAI* member = backups[index];
            if ((reinterpret_cast<byte*>(member)[0x500] & 0x40U) == 0) {
                member->m_iCurrentGroupID = this->m_iCurrentGroupID;
                member->m_TerroristLeader = this;
                int randomPercent = appRand() % 100;
                uint* selected; // Signed remainder is below100, so one of these fixed cutoff branches always selects.
                if (randomPercent < destinationCutoff) selected = (uint*)&destination;
                else if (randomPercent < firstCutoff) selected = (uint*)&firstCandidate;
                else if (randomPercent < secondCutoff) selected = (uint*)&secondCandidate;
                uint selectedY = selected[1];
                uint selectedZ = selected[2];
                uint selectedX = selected[0];
                AActor* enemy = this->Enemy;
                uint position[3] = { selectedX, selectedY, selectedZ };
                member->AR6TerroristAI::eventGotoPointToAttack(*(FVector*)position, enemy);
            }
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execCallBackupForAttack");
        throw;
    }
}

// R6Engine.dll @ 1003d72f : TerroristBackupAttackCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristBackupAttackCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x28]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x24]
        push ecx
        mov dword ptr [ebp-0x24],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d743 : TerroristBackupAttackCatchContext
// Reports backup-attack script context before rethrowing the active exception.
__declspec(naked) void TerroristBackupAttackCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecCallBackupForAttack
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d780 : execCallBackupForInvestigation
// Assigns interruptible backups to this leader's group and sends them to search the destination.
void AR6TerroristAI::execCallBackupForInvestigation(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    uint destination[3]; // Raw Vector output at native EBP-24, live across operand/debug/event callbacks.
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Both captures precede catch state0.
    try {
        natives[opcode](receiver, &stack, destination);
        code = *cursor;
        receiver = frame->Object;
        uint paceWord = (uint)(uintptr_t)frame & 0xffffff00U; // Native incoming frame word with its low byte cleared.
        opcode = *code;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        // Byte operand writes low byte; upper frame-address bytes survive.
        natives[opcode](receiver, &stack, &paceWord);
        code = *cursor + 1;
        *cursor = code;
        if (*code == 0x42) {
            receiver = frame->Object;
            *cursor = code + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        if (this->m_iTerroristInGroup != 0) {
            for (int index = 0; index < this->m_iTerroristInGroup; index = (int)((uint)index + 1U)) {
                AR6TerroristAI** backups = reinterpret_cast<AR6TerroristAI**>(
                    reinterpret_cast<NativeArrayHeader32&>(this->m_listAvailableBackup).dataAddress);
                AR6TerroristAI* member = backups[index];
                if ((reinterpret_cast<byte*>(member)[0x500] & 0x40U) == 0) {
                    member->m_iCurrentGroupID = this->m_iCurrentGroupID;
                    member->m_TerroristLeader = this;
                    uint currentPaceWord = paceWord;
                    uint position[3] = { destination[0], destination[1], destination[2] };
                    // Packet view preserves full argument words; the wrapper consumes only the pace byte.
                    using SearchEventPacket = void (__thiscall*)(AR6TerroristAI*, FVector, uint, int, float, uint);
                    ((SearchEventPacket)&AR6TerroristAIEventGotoPointAndSearchNativeEntry)(member,
                        *(FVector*)position, currentPaceWord, 0, 30.0f, 2);
                }
            }
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execCallBackupForInvestigation");
        throw;
    }
}

// R6Engine.dll @ 1003d876 : TerroristBackupInvestigationCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristBackupInvestigationCatchPointer(void)
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

// R6Engine.dll @ 1003d88a : TerroristBackupInvestigationCatchContext
// Reports backup-investigation context before rethrowing the active exception.
__declspec(naked) void TerroristBackupInvestigationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecCallBackupForInvestigation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d8c0 : execFindBetterShotLocation
// Tries two lateral firing points, then returns a path point, a short path step, or a forward fallback.
void AR6TerroristAI::execFindBetterShotLocation(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor;
    APawn* targetPawn = nullptr; // EBP-14, live across callbacks through the operand output pointer.
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Both captures precede catch state0.
    try {
        natives[opcode](receiver, &stack, &targetPawn);
        code = *cursor + 1;
        *cursor = code;
        if (*code == 0x42) {
            receiver = frame->Object;
            *cursor = code + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        FVector firingStart; // Native EBP-34, retained across later callbacks.
        AR6Pawn* pawn = this->m_pawn;
        // Use hidden output; native ignores the returned pointer.
        pawn->AR6Pawn::eventGetFiringStartPoint(&firingStart);
        FVector forwardDirection; // EBP-4c, reused as final output scratch.
        float10 deltaY = (float10)targetPawn->Location.Y - firingStart.Y;
        float targetX = targetPawn->Location.X;
        forwardDirection.Z = 0.0f;
        float10 deltaX = (float10)targetX - firingStart.X;
        forwardDirection.X = (float)deltaX;
        forwardDirection.Y = (float)deltaY;
        forwardDirection.Normalize();
        FVector candidate = { 0.0f, 0.0f, 1.0f }; // EBP-40: up operand, then candidate, then normalized-result buffer.
        FVector sideDirection; // EBP-28, live cross-product output and later path-direction input.
        // Ignore return pointer.
        sideDirection = forwardDirection ^ candidate;
        auto tryLateralPoint = [&]() -> bool {
            float10 scaledZ = (float10)sideDirection.Z * nativeFloat1EPlus02;
            float scaledY = (float)((float10)sideDirection.Y * nativeFloat1EPlus02);
            float scaledX = (float)((float10)sideDirection.X * nativeFloat1EPlus02);
            float10 z = scaledZ + firingStart.Z;
            float10 y = (float10)firingStart.Y + scaledY;
            float10 x = (float10)scaledX + firingStart.X;
            candidate.X = (float)x;
            uint cachedX = ((uint*)&candidate)[0];
            candidate.Y = (float)y;
            uint cachedY = ((uint*)&candidate)[1];
            candidate.Z = (float)z;
            uint shotPosition[3] = { cachedX, cachedY, ((uint*)&candidate)[2] };
            if (HaveAClearShot(*(FVector*)shotPosition, targetPawn) == 0) return false;
            uint walkPosition[3] = { cachedX, cachedY, ((uint*)&candidate)[2] }; // Cached X/Y; current Z.
            if (this->AR6AIController::CanWalkTo(*(FVector*)walkPosition, 0) == 0) return false;
            uint currentZ = ((uint*)&candidate)[2];
            ((uint*)result)[0] = cachedX;
            ((uint*)result)[1] = cachedY;
            ((uint*)result)[2] = currentZ;
            return true;
        };
        if (tryLateralPoint()) return;
        float10 negativeZ = -(float10)sideDirection.Z;
        float10 negativeY = -(float10)sideDirection.Y;
        float10 negativeX = -(float10)sideDirection.X;
        candidate.X = (float)negativeX;
        ((uint*)&sideDirection)[0] = ((uint*)&candidate)[0];
        candidate.Y = (float)negativeY;
        candidate.Z = (float)negativeZ;
        ((uint*)&sideDirection)[2] = ((uint*)&candidate)[2];
        ((uint*)&sideDirection)[1] = ((uint*)&candidate)[1];
        if (tryLateralPoint()) return;

        APawn* pathTarget = targetPawn;
        uint* zeroSource = *(uint**)&FVectorFVector0Import;
        uint zero[3] = { zeroSource[0], zeroSource[1], zeroSource[2] };
        AActor* path = this->AController::FindPath(*(FVector*)zero, pathTarget, 1);
        this->MoveTarget = path;
        auto emitStep = [&](const FVector* direction) {
            float10 scaledX = (float10)direction->X * nativeFloat1EPlus02;
            float10 scaledY = (float10)direction->Y * nativeFloat1EPlus02;
            candidate.Z = (float)((float10)direction->Z * nativeFloat1EPlus02);
            forwardDirection.X = (float)(scaledX + firingStart.X);
            ((uint*)result)[0] = ((uint*)&forwardDirection)[0];
            forwardDirection.Y = (float)(scaledY + firingStart.Y);
            float roundedZ = candidate.Z;
            ((uint*)result)[1] = ((uint*)&forwardDirection)[1];
            forwardDirection.Z = (float)((float10)roundedZ + firingStart.Z);
            ((uint*)result)[2] = ((uint*)&forwardDirection)[2];
        };
        if (path == nullptr) {
            emitStep(&forwardDirection);
            return;
        }
        UClass* pathClass = path->Class;
        while (pathClass != nullptr && pathClass != &AR6Door::PrivateStaticClass) {
            pathClass = pathClass->GetSuperClass();
        }
        if (pathClass == &AR6Door::PrivateStaticClass) {
            AR6Door* otherDoor = static_cast<AR6Door*>(path)->m_CorrespondingDoor;
            if (this->RouteCache[1] == otherDoor) {
                this->MoveTarget = otherDoor;
            }
        }
        APawn* currentPawn = this->Pawn;
        AActor* moveTarget = this->MoveTarget;
        FVector* moveLocation = &moveTarget->Location;
        FVector* pawnLocation = &currentPawn->Location;
        float10 pathZ = (float10)moveLocation->Z - pawnLocation->Z;
        float10 pathY = (float10)moveLocation->Y - pawnLocation->Y;
        float10 pathX = (float10)moveLocation->X - pawnLocation->X;
        candidate.X = (float)pathX;
        ((uint*)&sideDirection)[0] = ((uint*)&candidate)[0];
        candidate.Y = (float)pathY;
        ((uint*)&sideDirection)[1] = ((uint*)&candidate)[1];
        candidate.Z = (float)pathZ;
        ((uint*)&sideDirection)[2] = ((uint*)&candidate)[2];
        float10 distanceSquared = (float10)sideDirection.Y * sideDirection.Y
            + (float10)sideDirection.Z * sideDirection.Z + (float10)sideDirection.X * sideDirection.X;
        if ((float10)nativeFloat1EPlus04 < distanceSquared) {
            FVector* normalized = &(candidate = sideDirection.GetNormalized());
            emitStep(normalized); // This hidden-result call's returned pointer is used.
        } else {
            ((uint*)result)[0] = ((uint*)moveLocation)[0];
            ((uint*)result)[1] = ((uint*)moveLocation)[1];
            ((uint*)result)[2] = ((uint*)moveLocation)[2]; // Ordered forward raw copy, including unordered distances.
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execFindBetterShotLocation");
        throw;
    }
}

// R6Engine.dll @ 1003dc90 : TerroristBetterShotCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristBetterShotCatchPointer(void)
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

// R6Engine.dll @ 1003dca4 : TerroristBetterShotCatchContext
// Reports better-shot-location context before rethrowing the active exception.
__declspec(naked) void TerroristBetterShotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecFindBetterShotLocation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003dcd0 : execHaveAClearShot
// Evaluates the start vector and pawn target, then stores the native clear-shot result word.
void AR6TerroristAI::execHaveAClearShot(FFrame& stack, void* result)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    uint start[3]; // Raw Vector output at EBP-24; retained through target evaluation and DebugInfo.
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Both captures precede catch state0.
    try {
        natives[opcode](receiver, &stack, start);
        code = *cursor;
        receiver = frame->Object;
        APawn* targetPawn = nullptr; // Native reuses the whole incoming frame-word slot, while ESI retains frame.
        opcode = *code;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[opcode](receiver, &stack, &targetPawn);
        code = *cursor + 1;
        *cursor = code;
        if (*code == 0x42) {
            receiver = frame->Object;
            *cursor = code + 1;
            natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        APawn* currentTarget = targetPawn;
        uint position[3] = { start[0], start[1], start[2] };
        int nativeResult = HaveAClearShot(*(FVector*)position, currentTarget);
        *(uint*)result = (uint)nativeResult; // Full EAX word; no Bool normalization or byte store.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execHaveAClearShot");
        throw;
    }
}

// R6Engine.dll @ 1003dd95 : TerroristClearBridgeCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristClearBridgeCatchPointer(void)
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

// R6Engine.dll @ 1003dda9 : TerroristClearBridgeCatchContext
// Reports clear-shot bridge context before rethrowing the active exception.
__declspec(naked) void TerroristClearBridgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecHaveAClearShot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ddd0 : execCallVisibleTerrorist
// Calls eligible terrorists in audible zones to attack a visible point or engage a nearby threat.
void AR6TerroristAI::execCallVisibleTerrorist(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** cursor = &frame->Code;
    byte* code = *cursor + 1;
    *cursor = code;
    byte opcode = *code; // Read before catch state0.
    try {
        if (opcode == 0x42) {
            UObject* receiver = frame->Object;
            *cursor = code + 1;
            ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](receiver, &stack, nullptr);
        }
        AR6Pawn* initialPawn = this->m_pawn;
        FVector selfHead; // EBP-28, live throughout the controller scan.
        // Return pointer ignored.
        initialPawn->AR6Pawn::GetHeadLocation(&selfHead, initialPawn);
        ALevelInfo* initialLevelInfo = this->Level;
        AController* controller = initialLevelInfo->ControllerList;
        while (controller != nullptr) {
            UClass* controllerClass = controller->Class;
            while (controllerClass != nullptr && controllerClass != &AR6TerroristAI::PrivateStaticClass) {
                controllerClass = controllerClass->GetSuperClass();
            }
            if (controllerClass == &AR6TerroristAI::PrivateStaticClass && controller != this) {
                AR6TerroristAI* otherAI = static_cast<AR6TerroristAI*>(controller);
                if (otherAI->m_eAttackMode == 0) {
                    APawn* alivePawn = otherAI->m_pawn;
                    int alive = alivePawn->APawn::IsAlive();
                    if (alive != 0 && (reinterpret_cast<byte*>(otherAI)[0x500] & 0x40U) == 0) {
                        APawn* controlledPawn = this->Pawn;
                        AZoneInfo* selfZone = controlledPawn->Region.Zone;
                        uint selfSoundZone = selfZone->m_SoundZone;
                        AR6Pawn* otherPawn = otherAI->m_pawn;
                        ULevel* soundLevel = this->XLevel;
                        AZoneInfo* otherZone = otherPawn->Region.Zone;
                        uint otherSoundZone = otherZone->m_SoundZone;
                        // Includes equal zones.
                        ALevelInfo* levelInfo = soundLevel->ULevel::GetLevelInfo();
                        bool audible = otherSoundZone == selfSoundZone;
                        if (!audible) {
                            uint bit = 1U << (selfSoundZone & 31U);
                            uint* mask = (uint*)((byte*)levelInfo + 0x650 + otherSoundZone * 8);
                            uint lowMask = mask[0];
                            uint highBits = (uint)((int)bit >> 31); // CDQ sign-extends the shifted32-bit value.
                            uint lowAudibility = bit & lowMask;
                            uint highAudibility = highBits & mask[1];
                            audible = (lowAudibility | highAudibility) != 0;
                        }
                        if (audible) {
                            AActor* otherActor = otherAI->m_pawn;
                            AR6Pawn* visibilityPawn = this->m_pawn;
                            FVector otherHead; // EBP-34; only the hidden output is used.
                            visibilityPawn->AR6Pawn::GetHeadLocation(&otherHead, otherActor);
                            float10 deltaZ = (float10)otherHead.Z - selfHead.Z;
                            float10 deltaY = (float10)otherHead.Y - selfHead.Y;
                            float10 deltaX = (float10)otherHead.X - selfHead.X;
                            float distanceSquared = (float)(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
                            if ((float10)distanceSquared < nativeFloat4EPlus06) {
                                NativeCheckResult32 hit;
                                InitializeCheckResult((FCheckResult*)&hit, 1.0f, nullptr);
                                ULevel* level = this->XLevel;
                                uint* zeroSource = *(uint**)&FVectorFVector0Import;
                                uint extent[3];
                                extent[0] = zeroSource[0];
                                void** table = *reinterpret_cast<void***>(level);
                                extent[1] = zeroSource[1];
                                extent[2] = zeroSource[2];
                                AActor* ignoredPawn = otherAI->m_pawn;
                                using SingleLineCheck = int (__thiscall*)(ULevel*, NativeCheckResult32*, AActor*,
                                    const FVector*, const FVector*, uint, FVector);
                                reinterpret_cast<SingleLineCheck&>(table[0xcc / 4])(
                                    level, &hit, ignoredPawn, &selfHead, &otherHead, 0x20286, *(FVector*)extent);
                                AActor* hitActor = reinterpret_cast<AActor*>(hit.actorAddress);
                                APawn* selfActor = nullptr;
                                bool clear = hitActor == nullptr;
                                if (!clear) {
                                    selfActor = this->Pawn;
                                    clear = hitActor == selfActor;
                                }
                                if (clear) {
                                    AActor* enemy = this->Enemy;
                                    uint* headWords = (uint*)&selfHead;
                                    uint position[3] = { headWords[0], headWords[1], headWords[2] };
                                    otherAI->AR6TerroristAI::eventGotoPointToAttack(*(FVector*)position, enemy);
                                } else if ((float10)distanceSquared < nativeFloat1EPlus06) {
                                    AActor* threatSource = this->Enemy;
                                    if (threatSource == nullptr) threatSource = selfActor;
                                    uint* location = reinterpret_cast<uint*>(&threatSource->Location);
                                    uint threat[3] = { location[0], location[1], location[2] };
                                    otherAI->AR6TerroristAI::eventGotoStateEngageByThreat(*(FVector*)threat);
                                }
                            }
                        }
                    }
                }
            }
            controller = controller->nextController; // Current link after any callback/event.
        }
        // Native leaves the script Bool return storage untouched.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6TerroristAI::execCallVisibleTerrorist");
        throw;
    }
}

// R6Engine.dll @ 1003e06d : TerroristVisibleCatchPointer
// Forwards the parent's typed exception pointer through its native throw temporary.
__declspec(naked) void TerroristVisibleCatchPointer(void)
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

// R6Engine.dll @ 1003e081 : TerroristVisibleCatchContext
// Reports visible-terrorist context before rethrowing the active exception.
__declspec(naked) void TerroristVisibleCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristAIExecCallVisibleTerrorist
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100436c0 : TerroristAIDestructorState0Cleanup
// Destroys the saved AI-controller base during destructor unwinding.
__declspec(naked) void TerroristAIDestructorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6AIControllerDestructorNativeEntry
    }
}

// R6Engine.dll @ 100436c8 : TerroristAIDestructorState1Cleanup
// Tail-destroys the saved backup array during destructor unwinding.
__declspec(naked) void TerroristAIDestructorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x61c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100436d6 : TerroristAIDestructorState2Cleanup
// Tail-destroys the saved debug string through the current imported destructor.
__declspec(naked) void TerroristAIDestructorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x670
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100436f0 : TerroristAIConstructorState0Cleanup
// Destroys the completed AI-controller base during constructor unwinding.
__declspec(naked) void TerroristAIConstructorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6AIControllerDestructorNativeEntry
    }
}

// R6Engine.dll @ 100436f8 : TerroristAIConstructorState1Cleanup
// Tail-destroys the adopted or completed backup array during constructor unwinding.
__declspec(naked) void TerroristAIConstructorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x61c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10047fe0 : DestroyAR6TerroristAIClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6TerroristAIClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6TerroristAI::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045f10 : InitializeAR6TerroristAIClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6TerroristAIClassMetadata(void)
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
    packet.internalConstructor = &AR6TerroristAI::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6TerroristAI;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6AIController::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x67c;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6TerroristAI::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6TerroristAIClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045f90 : PublishAR6TerroristAIAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6TerroristAIAutoClass(void)
{
    autoclassAR6TerroristAI = &AR6TerroristAI::PrivateStaticClass;
}

// R6Engine.dll @ 100478e0 : RegisterAR6TerroristAIIsAttackSpotStillValidNative
// Registers native index0x725 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAIIsAttackSpotStillValidNative(void)
{
    AR6TerroristAIIsAttackSpotStillValidRegistrationResult =
        GRegisterNative(0x725, intAR6TerroristAIexecIsAttackSpotStillValid);
}

// R6Engine.dll @ 10047900 : RegisterAR6TerroristAICallVisibleTerroristNative
// Registers native index0x724 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAICallVisibleTerroristNative(void)
{
    AR6TerroristAICallVisibleTerroristRegistrationResult =
        GRegisterNative(0x724, intAR6TerroristAIexecCallVisibleTerrorist);
}

// R6Engine.dll @ 10047920 : RegisterAR6TerroristAIHaveAClearShotNative
// Registers native index0x723 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAIHaveAClearShotNative(void)
{
    AR6TerroristAIHaveAClearShotRegistrationResult = GRegisterNative(0x723, intAR6TerroristAIexecHaveAClearShot);
}

// R6Engine.dll @ 10047940 : RegisterAR6TerroristAIFindBetterShotLocationNative
// Registers native index0x720 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAIFindBetterShotLocationNative(void)
{
    AR6TerroristAIFindBetterShotLocationRegistrationResult =
        GRegisterNative(0x720, intAR6TerroristAIexecFindBetterShotLocation);
}

// R6Engine.dll @ 10047960 : RegisterAR6TerroristAIMakeBackupListNative
// Registers native index0x71e using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAIMakeBackupListNative(void)
{
    AR6TerroristAIMakeBackupListRegistrationResult = GRegisterNative(0x71e, intAR6TerroristAIexecMakeBackupList);
}

// R6Engine.dll @ 10047980 : RegisterAR6TerroristAICallBackupForInvestigationNative
// Registers native index0x71f using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAICallBackupForInvestigationNative(void)
{
    AR6TerroristAICallBackupForInvestigationRegistrationResult =
        GRegisterNative(0x71f, intAR6TerroristAIexecCallBackupForInvestigation);
}

// R6Engine.dll @ 100479a0 : RegisterAR6TerroristAICallBackupForAttackNative
// Registers native index0x71d using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAICallBackupForAttackNative(void)
{
    AR6TerroristAICallBackupForAttackRegistrationResult =
        GRegisterNative(0x71d, intAR6TerroristAIexecCallBackupForAttack);
}

// R6Engine.dll @ 100479c0 : RegisterAR6TerroristAIGetNextRandomNodeNative
// Registers native index0x71c using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6TerroristAIGetNextRandomNodeNative(void)
{
    AR6TerroristAIGetNextRandomNodeRegistrationResult = GRegisterNative(0x71c, intAR6TerroristAIexecGetNextRandomNode);
}

// R6Engine.dll @ 100436e5 : TerroristAIDestructorExceptionHandler
// Supplies the destructor string/array/base cleanup metadata to the inherited dispatcher frame.
__declspec(naked) void TerroristAIDestructorExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristAIDestructorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043706 : TerroristAIConstructorExceptionHandler
// Supplies the default/copy constructor array/base cleanup metadata to the inherited dispatcher frame.
__declspec(naked) void TerroristAIConstructorExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristAIConstructorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100450d0 : TerroristSpotExceptionHandler
// Supplies the firing-spot validation FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristSpotExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristSpotInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045100 : TerroristRandomExceptionHandler
// Supplies next-node selection FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristRandomExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristRandomInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045110 : TerroristShotExceptionHandler
// Supplies clear-shot FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristShotExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristShotInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045130 : TerroristBackupListExceptionHandler
// Supplies backup-list FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristBackupListExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristBackupListInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045140 : TerroristBackupAttackExceptionHandler
// Supplies backup-attack FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristBackupAttackExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristBackupAttackInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045150 : TerroristBackupInvestigationExceptionHandler
// Supplies backup-investigation FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristBackupInvestigationExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristBackupInvestigationInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045160 : TerroristBetterShotExceptionHandler
// Supplies better-shot-location FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristBetterShotExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristBetterShotInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045170 : TerroristClearBridgeExceptionHandler
// Supplies clear-shot bridge FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristClearBridgeExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristClearBridgeInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045180 : TerroristVisibleExceptionHandler
// Supplies visible-terrorist FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristVisibleExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristVisibleInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100450e0 : TerroristHearingExceptionHandler
// Supplies terrorist-hearing FuncInfo to the inherited dispatcher frame.
__declspec(naked) void TerroristHearingExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristHearingInfo
        jmp __CxxFrameHandler
    }
}
