#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_text_data.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl ClearActionSpotExceptionHandler(void);
__declspec(naked) void __cdecl PickActorAdjustExceptionHandler(void);
__declspec(naked) void __cdecl ActorReachableExceptionHandler(void);
float10 __cdecl EvaluateNavigationNodeWeight(
    ANavigationPoint* candidateNode, APawn* searchingPawn, float unusedCurrentWeight);
int __cdecl CheckSpotValidForCover(AR6Pawn* unusedPawn, AR6ActionSpot* spot, STActionSpotCheck* check);
int __cdecl CheckSpotValidForFire(AR6Pawn* pawn, AR6ActionSpot* spot, STActionSpotCheck* check);
int __cdecl CheckSpotValidForInvestigation(
    AR6Pawn* unusedPawn, AR6ActionSpot* spot, STActionSpotCheck* check);
ANavigationPoint* __cdecl CastToANavigationPoint(UObject* object);
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);
AR6Door* __cdecl CastToAR6Door(UObject* object);
FVector* __cdecl ScaleVectorToResult(FVector* result, float scale, const FVector* source);
__declspec(naked) void __cdecl DestroyAR6AIControllerClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// External native storage views; names describe roles rather than recovered original identifiers.
float10 __cdecl DistanceToSegment(const FVector* point, const FVector* start, const FVector* end);

// R6Engine.dll data @ 1004c9ac : nativeFloat120
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat120;

// R6Engine.dll data @ 1004b340 : AR6AIControllerVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6AIController::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6AIControllerVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004ca80 : nativeTextAR6AIControllerAdjustFromWall
extern const ushort nativeTextAR6AIControllerAdjustFromWall[32];

// R6Engine.dll data @ 1004c700 : nativeTextAR6AIControllerCanHear
extern const ushort nativeTextAR6AIControllerCanHear[25];

// R6Engine.dll data @ 1004c7d0 : nativeTextAR6AIControllerCanWalkTo
extern const ushort nativeTextAR6AIControllerCanWalkTo[27];

// R6Engine.dll data @ 10049838 : nativeTextAR6AIControllerClearActionSpot
extern const ushort nativeTextAR6AIControllerClearActionSpot[33];

// R6Engine.dll data @ 100498d8 : nativeTextAR6AIControllerExecActorReachableFromLocation
extern const ushort nativeTextAR6AIControllerExecActorReachableFromLocation[48];

// R6Engine.dll data @ 1004cac0 : nativeTextAR6AIControllerExecCanWalkTo
extern const ushort nativeTextAR6AIControllerExecCanWalkTo[31];

// R6Engine.dll data @ 1004c810 : nativeTextAR6AIControllerExecFindGrenadeDirectionToHitActor
extern const ushort nativeTextAR6AIControllerExecFindGrenadeDirectionToHitActor[52];

// R6Engine.dll data @ 1004c668 : nativeTextAR6AIControllerExecFindInvestigationPoint
extern const ushort nativeTextAR6AIControllerExecFindInvestigationPoint[44];

// R6Engine.dll data @ 1004c618 : nativeTextAR6AIControllerExecFindPlaceToFire
extern const ushort nativeTextAR6AIControllerExecFindPlaceToFire[37];

// R6Engine.dll data @ 1004c5c0 : nativeTextAR6AIControllerExecFindPlaceToTakeCover
extern const ushort nativeTextAR6AIControllerExecFindPlaceToTakeCover[42];

// R6Engine.dll data @ 1004cb40 : nativeTextAR6AIControllerExecGotoOpenDoorState
extern const ushort nativeTextAR6AIControllerExecGotoOpenDoorState[39];

// R6Engine.dll data @ 1004c420 : nativeTextAR6AIControllerExecMakePathToRun
extern const ushort nativeTextAR6AIControllerExecMakePathToRun[35];

// R6Engine.dll data @ 1004cbf8 : nativeTextAR6AIControllerExecNeedToOpenDoor
extern const ushort nativeTextAR6AIControllerExecNeedToOpenDoor[36];

// R6Engine.dll data @ 10049888 : nativeTextAR6AIControllerExecPickActorAdjust
extern const ushort nativeTextAR6AIControllerExecPickActorAdjust[37];

// R6Engine.dll data @ 1004c8b0 : nativeTextAR6AIControllerGotoOpenDoorState
extern const ushort nativeTextAR6AIControllerGotoOpenDoorState[35];

// R6Engine.dll data @ 1004c6c4 : nativeTextAR6AIControllerHearingCheck
extern const ushort nativeTextAR6AIControllerHearingCheck[30];

// R6Engine.dll data @ 1004cb00 : nativeTextAR6AIControllerNeedToOpenDoor
extern const ushort nativeTextAR6AIControllerNeedToOpenDoor[32];

// R6Engine.dll data @ 1004c960 : nativeTextAR6RainbowAIExecFindNearbyWaitSpot
extern const ushort nativeTextAR6RainbowAIExecFindNearbyWaitSpot[37];

// R6Engine.dll data @ 1004c530 : nativeTextFindNearestActionSpot
extern const ushort nativeTextFindNearestActionSpot[22];

// R6Engine.dll data @ 1004ca74 : nativeTextNone
extern const ushort nativeTextNone[5];

// R6Engine.dll data @ 1004c8f8 : nativeTextOpenDoor
extern const ushort nativeTextOpenDoor[9];

// R6Engine.dll data @ 10055646 : nativeTextR6AIController
extern const ushort nativeTextR6AIController[15];

// R6Engine.dll data @ 1004c468 : nativeTextSCannotReachSSBlockedByEnemy
extern const ushort nativeTextSCannotReachSSBlockedByEnemy[40];

// R6Engine.dll data @ 1004c4c0 : nativeTextSMustHaveAnEnemyToCreateAPathInMakePathToRun
extern const ushort nativeTextSMustHaveAnEnemyToCreateAPathInMakePathToRun[56];

// R6Engine.dll data @ 1004c740 : nativeTextWARNINGReceivedMakeNoiseWithoutApropriateTypeFromSInStateS
extern const ushort nativeTextWARNINGReceivedMakeNoiseWithoutApropriateTypeFromSInStateS[72];

// R6Engine.dll data @ 1004c9b8 : nativeTextWARNINGSAt62f62f62fAnchorSCannotFindAPathTo62f62f62f
extern const ushort nativeTextWARNINGSAt62f62f62fAnchorSCannotFindAPathTo62f62f62f[94];

// R6Engine.dll data @ 10049938 : nativeTextWarningNoPawnOrGoalForActorReachableFromLocationBySInS
extern const ushort nativeTextWarningNoPawnOrGoalForActorReachableFromLocationBySInS[68];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void AIControllerCanHearExceptionHandler(void);
__declspec(naked) void AIControllerCanWalkToExceptionHandler(void);
__declspec(naked) void AIControllerCanWalkVMExceptionHandler(void);
__declspec(naked) void AIControllerDtorExceptionHandler(void);
__declspec(naked) void AIControllerGotoDoorVMExceptionHandler(void);
__declspec(naked) void AIControllerGrenadeDirectionExceptionHandler(void);
__declspec(naked) void AIControllerNeedDoorExceptionHandler(void);
__declspec(naked) void AIControllerNeedDoorVMExceptionHandler(void);
__declspec(naked) void AIControllerOpenDoorExceptionHandler(void);
__declspec(naked) void AIControllerWaitSpotExceptionHandler(void);
__declspec(naked) void AIControllerWallAdjustExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl ActorReachableCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ActorReachableCatchPointer(void);
__declspec(naked) void AiControllerDtorState0Cleanup(void);
__declspec(naked) void CanHearCatchContext(void);
__declspec(naked) void CanHearCatchPointer(void);
__declspec(naked) void CanWalkToCatchContext(void);
__declspec(naked) void CanWalkToCatchPointer(void);
__declspec(naked) void CanWalkVMCatchContext(void);
__declspec(naked) void CanWalkVMCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClearActionSpotCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClearActionSpotCatchPointer(void);
__declspec(naked) void CoverSearchCatchContext(void);
__declspec(naked) void CoverSearchCatchPointer(void);
__declspec(naked) void CoverSearchExceptionHandler(void);
__declspec(naked) void EscapeRouteCatchContext(void);
__declspec(naked) void EscapeRouteCatchPointer(void);
__declspec(naked) void EscapeRouteExceptionHandler(void);
__declspec(naked) void FireSearchCatchContext(void);
__declspec(naked) void FireSearchCatchPointer(void);
__declspec(naked) void FireSearchExceptionHandler(void);
__declspec(naked) void GotoDoorVMCatchContext(void);
__declspec(naked) void GotoDoorVMCatchPointer(void);
__declspec(naked) void GrenadeDirectionCatchContext(void);
__declspec(naked) void GrenadeDirectionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl HearingCheckCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl HearingCheckCatchPointer(void);
__declspec(naked) void __cdecl HearingCheckExceptionHandler(void);
__declspec(naked) void InvestigationSearchCatchContext(void);
__declspec(naked) void InvestigationSearchCatchPointer(void);
__declspec(naked) void InvestigationSearchExceptionHandler(void);
__declspec(naked) void NearestSpotCatchContext(void);
__declspec(naked) void NearestSpotCatchPointer(void);
__declspec(naked) void NearestSpotExceptionHandler(void);
__declspec(naked) void NeedDoorCatchContext(void);
__declspec(naked) void NeedDoorCatchPointer(void);
__declspec(naked) void NeedDoorVMCatchContext(void);
__declspec(naked) void NeedDoorVMCatchPointer(void);
__declspec(naked) void OpenDoorCatchContext(void);
__declspec(naked) void OpenDoorCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PickActorAdjustCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PickActorAdjustCatchPointer(void);
__declspec(naked) void WaitSpotCatchContext(void);
__declspec(naked) void WaitSpotCatchPointer(void);
__declspec(naked) void WallAdjustCatchContext(void);
__declspec(naked) void WallAdjustCatchPointer(void);

// R6Engine.dll data @ 10049828 : nativeFloat2Point4
extern const float nativeFloat2Point4;

// R6Engine.dll data @ 1004c808 : nativeDouble33
extern const double nativeDouble33;

// R6Engine.dll data @ 1004c878 : nativeDouble0Point3183098861837907
extern const double nativeDouble0Point3183098861837907;

// R6Engine.dll data @ 1004c880 : nativeFloat32767
extern const float nativeFloat32767;

// R6Engine.dll data @ 10057ae0 : gotoDoorVMUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry gotoDoorVMUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10057af0 : gotoDoorVMCatchMap
// The typed catch reads parent EBP-0x1c; separate rethrow storage is at EBP-0x18.
const NativeCatchEntry gotoDoorVMCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&GotoDoorVMCatchPointer) },
    { 0, 0, 0, ((uint)&GotoDoorVMCatchContext) }
};

// R6Engine.dll data @ 10057b10 : gotoDoorVMTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock gotoDoorVMTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&gotoDoorVMCatchMap) }
};

// R6Engine.dll data @ 10057b24 : gotoDoorVMFuncInfo
// Binds the complete execGotoOpenDoorState exception frame.
const NativeFunctionInfoPrefix gotoDoorVMFuncInfo = { 0x19930520, 0x2, ((uint)&gotoDoorVMUnwindMap), 0x1,
    ((uint)&gotoDoorVMTryMap), 0 };

// R6Engine.dll data @ 10057e68 : needDoorVMUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry needDoorVMUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10057e78 : needDoorVMCatchMap
// The typed catch reads parent EBP-0x1c; separate rethrow storage is at EBP-0x18.
const NativeCatchEntry needDoorVMCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&NeedDoorVMCatchPointer) },
    { 0, 0, 0, ((uint)&NeedDoorVMCatchContext) }
};

// R6Engine.dll data @ 10057e98 : needDoorVMTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock needDoorVMTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&needDoorVMCatchMap) }
};

// R6Engine.dll data @ 10057eac : needDoorVMFuncInfo
// Binds the complete execNeedToOpenDoor exception frame.
const NativeFunctionInfoPrefix needDoorVMFuncInfo = { 0x19930520, 0x2, ((uint)&needDoorVMUnwindMap), 0x1,
    ((uint)&needDoorVMTryMap), 0 };

// R6Engine.dll data @ 10057a80 : needDoorUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry needDoorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10057a90 : needDoorCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry needDoorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&NeedDoorCatchPointer) },
    { 0, 0, 0, ((uint)&NeedDoorCatchContext) }
};

// R6Engine.dll data @ 10057ab0 : needDoorTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock needDoorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&needDoorCatchMap) }
};

// R6Engine.dll data @ 10057ac4 : needDoorFuncInfo
// Binds the complete door-opening predicate's exception frame.
const NativeFunctionInfoPrefix needDoorFuncInfo = { 0x19930520, 0x2, ((uint)&needDoorUnwindMap), 0x1,
    ((uint)&needDoorTryMap), 0 };

// R6Engine.dll data @ 10057a20 : canWalkVMUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry canWalkVMUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10057a30 : canWalkVMCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry canWalkVMCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CanWalkVMCatchPointer) },
    { 0, 0, 0, ((uint)&CanWalkVMCatchContext) }
};

// R6Engine.dll data @ 10057a50 : canWalkVMTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock canWalkVMTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&canWalkVMCatchMap) }
};

// R6Engine.dll data @ 10057a64 : canWalkVMFuncInfo
// Binds the complete CanWalkTo VM bridge's exception frame.
const NativeFunctionInfoPrefix canWalkVMFuncInfo = { 0x19930520, 0x2, ((uint)&canWalkVMUnwindMap), 0x1,
    ((uint)&canWalkVMTryMap), 0 };

// R6Engine.dll data @ 100579c0 : wallAdjustUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry wallAdjustUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100579d0 : wallAdjustCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry wallAdjustCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&WallAdjustCatchPointer) },
    { 0, 0, 0, ((uint)&WallAdjustCatchContext) }
};

// R6Engine.dll data @ 100579f0 : wallAdjustTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock wallAdjustTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&wallAdjustCatchMap) }
};

// R6Engine.dll data @ 10057a04 : wallAdjustFuncInfo
// Binds the complete wall-adjustment exception frame.
const NativeFunctionInfoPrefix wallAdjustFuncInfo = { 0x19930520, 0x2, ((uint)&wallAdjustUnwindMap), 0x1,
    ((uint)&wallAdjustTryMap), 0 };

// R6Engine.dll data @ 100575dc : waitSpotUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry waitSpotUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100575ec : waitSpotCatchMap
// The typed catch reads parent EBP-0x90; separate rethrow storage is at EBP-0x8c.
const NativeCatchEntry waitSpotCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -144, ((uint)&WaitSpotCatchPointer) },
    { 0, 0, 0, ((uint)&WaitSpotCatchContext) }
};

// R6Engine.dll data @ 1005760c : waitSpotTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock waitSpotTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&waitSpotCatchMap) }
};

// R6Engine.dll data @ 10057620 : waitSpotFuncInfo
// Binds the complete wait-spot search's exception frame.
const NativeFunctionInfoPrefix waitSpotFuncInfo = { 0x19930520, 0x2, ((uint)&waitSpotUnwindMap), 0x1,
    ((uint)&waitSpotTryMap), 0 };

// R6Engine.dll data @ 1005757c : openDoorUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry openDoorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005758c : openDoorCatchMap
// The typed catch reads parent EBP-0x20; separate rethrow storage is at EBP-0x1c.
const NativeCatchEntry openDoorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&OpenDoorCatchPointer) },
    { 0, 0, 0, ((uint)&OpenDoorCatchContext) }
};

// R6Engine.dll data @ 100575ac : openDoorTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock openDoorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&openDoorCatchMap) }
};

// R6Engine.dll data @ 100575c0 : openDoorFuncInfo
// Binds the complete open-door transition's exception frame.
const NativeFunctionInfoPrefix openDoorFuncInfo = { 0x19930520, 0x2, ((uint)&openDoorUnwindMap), 0x1,
    ((uint)&openDoorTryMap), 0 };

// R6Engine.dll data @ 1005751c : grenadeDirectionUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry grenadeDirectionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005752c : grenadeDirectionCatchMap
// The typed catch reads parent EBP-0x3c; separate rethrow storage is at EBP-0x38.
const NativeCatchEntry grenadeDirectionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -60, ((uint)&GrenadeDirectionCatchPointer) },
    { 0, 0, 0, ((uint)&GrenadeDirectionCatchContext) }
};

// R6Engine.dll data @ 1005754c : grenadeDirectionTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock grenadeDirectionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&grenadeDirectionCatchMap) }
};

// R6Engine.dll data @ 10057560 : grenadeDirectionFuncInfo
// Binds the grenade-direction bridge's complete exception frame.
const NativeFunctionInfoPrefix grenadeDirectionFuncInfo = { 0x19930520, 0x2, ((uint)&grenadeDirectionUnwindMap), 0x1,
    ((uint)&grenadeDirectionTryMap), 0 };

// R6Engine.dll data @ 100574bc : canWalkToUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry canWalkToUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100574cc : canWalkToCatchMap
// Catches the typed word at parent EBP-0x18; rethrow storage is separate at EBP-0x14.
const NativeCatchEntry canWalkToCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CanWalkToCatchPointer) },
    { 0, 0, 0, ((uint)&CanWalkToCatchContext) }
};

// R6Engine.dll data @ 100574ec : canWalkToTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock canWalkToTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&canWalkToCatchMap) }
};

// R6Engine.dll data @ 10057500 : canWalkToFuncInfo
// Binds the complete walk-clearance frame without local cleanup actions.
const NativeFunctionInfoPrefix canWalkToFuncInfo = { 0x19930520, 0x2, ((uint)&canWalkToUnwindMap), 0x1,
    ((uint)&canWalkToTryMap), 0 };

// R6Engine.dll data @ 1005745c : canHearUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry canHearUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005746c : canHearCatchMap
// The caught word is at parent EBP-0x40; rethrow storage is at EBP-0x30.
const NativeCatchEntry canHearCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -64, ((uint)&CanHearCatchPointer) },
    { 0, 0, 0, ((uint)&CanHearCatchContext) }
};

// R6Engine.dll data @ 1005748c : canHearTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock canHearTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&canHearCatchMap) }
};

// R6Engine.dll data @ 100574a0 : canHearFuncInfo
// Binds the hearing guard without adding local cleanup actions.
const NativeFunctionInfoPrefix canHearFuncInfo = { 0x19930520, 0x2, ((uint)&canHearUnwindMap), 0x1,
    ((uint)&canHearTryMap), 0 };

// R6Engine.dll data @ 1005739c : investigationSearchUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry investigationSearchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100573ac : investigationSearchCatchMap
// The caught word is at parent EBP-0x20; no owned local cleanup is installed.
const NativeCatchEntry investigationSearchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&InvestigationSearchCatchPointer) },
    { 0, 0, 0, ((uint)&InvestigationSearchCatchContext) }
};

// R6Engine.dll data @ 100573cc : investigationSearchTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock investigationSearchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&investigationSearchCatchMap) }
};

// R6Engine.dll data @ 100573e0 : investigationSearchFuncInfo
// Binds the complete script bridge without adding local cleanup actions.
const NativeFunctionInfoPrefix investigationSearchFuncInfo = { 0x19930520, 0x2, ((uint)&investigationSearchUnwindMap),
    0x1, ((uint)&investigationSearchTryMap), 0 };

// R6Engine.dll data @ 1005733c : fireSearchUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry fireSearchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005734c : fireSearchCatchMap
// The caught word is at parent EBP-0x1c; no owned local cleanup is installed.
const NativeCatchEntry fireSearchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&FireSearchCatchPointer) },
    { 0, 0, 0, ((uint)&FireSearchCatchContext) }
};

// R6Engine.dll data @ 1005736c : fireSearchTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock fireSearchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&fireSearchCatchMap) }
};

// R6Engine.dll data @ 10057380 : fireSearchFuncInfo
// Binds the complete script bridge without adding local cleanup actions.
const NativeFunctionInfoPrefix fireSearchFuncInfo = { 0x19930520, 0x2, ((uint)&fireSearchUnwindMap), 0x1,
    ((uint)&fireSearchTryMap), 0 };

// R6Engine.dll data @ 100572dc : coverSearchUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry coverSearchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100572ec : coverSearchCatchMap
// The caught word is at parent EBP-0x18; no owned local cleanup is installed.
const NativeCatchEntry coverSearchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CoverSearchCatchPointer) },
    { 0, 0, 0, ((uint)&CoverSearchCatchContext) }
};

// R6Engine.dll data @ 1005730c : coverSearchTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock coverSearchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&coverSearchCatchMap) }
};

// R6Engine.dll data @ 10057320 : coverSearchFuncInfo
// Binds the complete script bridge without adding local cleanup actions.
const NativeFunctionInfoPrefix coverSearchFuncInfo = { 0x19930520, 0x2, ((uint)&coverSearchUnwindMap), 0x1,
    ((uint)&coverSearchTryMap), 0 };

// R6Engine.dll data @ 100571bc : nearestSpotUnwindMap
// Two states retain the cleanup-free inherited catch frame.
const NativeUnwindEntry nearestSpotUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100571cc : nearestSpotCatchMap
// The typed caught word is at parent EBP-0x1c.
const NativeCatchEntry nearestSpotCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&NearestSpotCatchPointer) },
    { 0, 0, 0, ((uint)&NearestSpotCatchContext) }
};

// R6Engine.dll data @ 100571ec : nearestSpotTryMap
// State zero selects the inherited typed and context handlers.
const NativeTryBlock nearestSpotTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&nearestSpotCatchMap) }
};

// R6Engine.dll data @ 10057200 : nearestSpotFuncInfo
// Binds the complete guarded search without local cleanup actions.
const NativeFunctionInfoPrefix nearestSpotFuncInfo = { 0x19930520, 0x2, ((uint)&nearestSpotUnwindMap), 0x1,
    ((uint)&nearestSpotTryMap), 0 };

// R6Engine.dll data @ 1005715c : escapeRouteUnwindMap
// Two cleanup-free states retain the inherited typed/context catch frame.
const NativeUnwindEntry escapeRouteUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005716c : escapeRouteCatchMap
// The typed catch receives parent EBP-0x1c; both handlers belong to this bridge.
const NativeCatchEntry escapeRouteCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&EscapeRouteCatchPointer) },
    { 0, 0, 0, ((uint)&EscapeRouteCatchContext) }
};

// R6Engine.dll data @ 1005718c : escapeRouteTryMap
// State zero selects the two inherited-frame handlers.
const NativeTryBlock escapeRouteTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&escapeRouteCatchMap) }
};

// R6Engine.dll data @ 100571a0 : escapeRouteFuncInfo
// Binds the complete guarded bridge without owned local cleanup.
const NativeFunctionInfoPrefix escapeRouteFuncInfo = { 0x19930520, 0x2, ((uint)&escapeRouteUnwindMap), 0x1,
    ((uint)&escapeRouteTryMap), 0 };

// R6Engine.dll data @ 10056e14 : aiControllerDtorUnwind
// State zero destroys the AAIController base if ConditionalDestroy exits through an exception.
const NativeUnwindEntry aiControllerDtorUnwind[1] = {
    { -1, ((uint)&AiControllerDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056e1c : aiControllerDtorInfo
// One unwind state with no typed or context catch region.
const NativeFunctionInfoPrefix aiControllerDtorInfo = { 0x19930520, 0x1, ((uint)&aiControllerDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10056888 : actorReachableUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry actorReachableUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10056898 : actorReachableCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry actorReachableCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ActorReachableCatchPointer) },
    { 0, 0, 0, ((uint)&ActorReachableCatchContext) }
};

// R6Engine.dll data @ 100568b8 : actorReachableTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock actorReachableTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&actorReachableCatchMap) }
};

// R6Engine.dll data @ 100568cc : actorReachableFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix actorReachableFuncInfo = { 0x19930520, 0x2, ((uint)&actorReachableUnwindMap), 0x1,
    ((uint)&actorReachableTryMap), 0 };

// R6Engine.dll data @ 10056828 : pickActorAdjustUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry pickActorAdjustUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10056838 : pickActorAdjustCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry pickActorAdjustCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&PickActorAdjustCatchPointer) },
    { 0, 0, 0, ((uint)&PickActorAdjustCatchContext) }
};

// R6Engine.dll data @ 10056858 : pickActorAdjustTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock pickActorAdjustTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pickActorAdjustCatchMap) }
};

// R6Engine.dll data @ 1005686c : pickActorAdjustFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix pickActorAdjustFuncInfo = { 0x19930520, 0x2, ((uint)&pickActorAdjustUnwindMap), 0x1,
    ((uint)&pickActorAdjustTryMap), 0 };

// R6Engine.dll data @ 100567c8 : clearActionSpotUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry clearActionSpotUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100567d8 : clearActionSpotCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry clearActionSpotCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClearActionSpotCatchPointer) },
    { 0, 0, 0, ((uint)&ClearActionSpotCatchContext) }
};

// R6Engine.dll data @ 100567f8 : clearActionSpotTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock clearActionSpotTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&clearActionSpotCatchMap) }
};

// R6Engine.dll data @ 1005680c : clearActionSpotFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix clearActionSpotFuncInfo = { 0x19930520, 0x2, ((uint)&clearActionSpotUnwindMap), 0x1,
    ((uint)&clearActionSpotTryMap), 0 };

// R6Engine.dll data @ 100573fc : hearingCheckUnwind
// Retains exact guarded states and inherited-frame typed/context catches, with no owned local cleanup.
const NativeUnwindEntry hearingCheckUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005740c : hearingCheckCatch
// Retains exact guarded states and inherited-frame typed/context catches, with no owned local cleanup.
const NativeCatchEntry hearingCheckCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&HearingCheckCatchPointer) },
    { 0, 0, 0, ((uint)&HearingCheckCatchContext) }
};

// R6Engine.dll data @ 1005742c : hearingCheckTry
// Retains exact guarded states and inherited-frame typed/context catches, with no owned local cleanup.
const NativeTryBlock hearingCheckTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&hearingCheckCatch) }
};

// R6Engine.dll data @ 10057440 : hearingCheckInfo
// Retains exact guarded states and inherited-frame typed/context catches, with no owned local cleanup.
const NativeFunctionInfoPrefix hearingCheckInfo = { 0x19930520, 0x2, ((uint)&hearingCheckUnwind), 0x1,
    ((uint)&hearingCheckTry), 0 };

// R6Engine.dll data @ 10074488 : intAR6AIControllerexecActorReachableFromLocation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecActorReachableFromLocation =
    (Native)&AR6AIController::execActorReachableFromLocation;

// R6Engine.dll data @ 100773d8 : AR6AIControllerActorReachableFromLocationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerActorReachableFromLocationRegistrationResult = 0;

// R6Engine.dll data @ 1007448c : intAR6AIControllerexecFindNearbyWaitSpot
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFindNearbyWaitSpot = (Native)&AR6AIController::execFindNearbyWaitSpot;

// R6Engine.dll data @ 10081c60 : AR6AIControllerFindNearbyWaitSpotRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFindNearbyWaitSpotRegistrationResult = 0;

// R6Engine.dll data @ 10074490 : intAR6AIControllerexecGotoOpenDoorState
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecGotoOpenDoorState = (Native)&AR6AIController::execGotoOpenDoorState;

// R6Engine.dll data @ 10080d1a : AR6AIControllerGotoOpenDoorStateRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerGotoOpenDoorStateRegistrationResult = 0;

// R6Engine.dll data @ 10074494 : intAR6AIControllerexecNeedToOpenDoor
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecNeedToOpenDoor = (Native)&AR6AIController::execNeedToOpenDoor;

// R6Engine.dll data @ 10080d1b : AR6AIControllerNeedToOpenDoorRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerNeedToOpenDoorRegistrationResult = 0;

// R6Engine.dll data @ 10074498 : intAR6AIControllerexecFindGrenadeDirectionToHitActor
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFindGrenadeDirectionToHitActor =
    (Native)&AR6AIController::execFindGrenadeDirectionToHitActor;

// R6Engine.dll data @ 1007f8a8 : AR6AIControllerFindGrenadeDirectionToHitActorRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFindGrenadeDirectionToHitActorRegistrationResult = 0;

// R6Engine.dll data @ 1007449c : intAR6AIControllerexecCanWalkTo
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecCanWalkTo = (Native)&AR6AIController::execCanWalkTo;

// R6Engine.dll data @ 1007abf4 : AR6AIControllerCanWalkToRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerCanWalkToRegistrationResult = 0;

// R6Engine.dll data @ 100744a0 : intAR6AIControllerexecFollowPathTo
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFollowPathTo = (Native)&AR6AIController::execFollowPathTo;

// R6Engine.dll data @ 10081c4d : AR6AIControllerFollowPathToRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFollowPathToRegistrationResult = 0;

// R6Engine.dll data @ 100744a4 : intAR6AIControllerexecFollowPath
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFollowPath = (Native)&AR6AIController::execFollowPath;

// R6Engine.dll data @ 100826a0 : AR6AIControllerFollowPathRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFollowPathRegistrationResult = 0;

// R6Engine.dll data @ 100744a8 : intAR6AIControllerexecMoveToPosition
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecMoveToPosition = (Native)&AR6AIController::execMoveToPosition;

// R6Engine.dll data @ 1007ca90 : AR6AIControllerMoveToPositionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerMoveToPositionRegistrationResult = 0;

// R6Engine.dll data @ 100744ac : intAR6AIControllerexecPickActorAdjust
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecPickActorAdjust = (Native)&AR6AIController::execPickActorAdjust;

// R6Engine.dll data @ 100773c8 : AR6AIControllerPickActorAdjustRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerPickActorAdjustRegistrationResult = 0;

// R6Engine.dll data @ 100744b0 : intAR6AIControllerexecFindInvestigationPoint
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFindInvestigationPoint = (Native)&AR6AIController::execFindInvestigationPoint;

// R6Engine.dll data @ 1007c57c : AR6AIControllerFindInvestigationPointRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFindInvestigationPointRegistrationResult = 0;

// R6Engine.dll data @ 100744b4 : intAR6AIControllerexecFindPlaceToFire
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFindPlaceToFire = (Native)&AR6AIController::execFindPlaceToFire;

// R6Engine.dll data @ 1007b120 : AR6AIControllerFindPlaceToFireRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFindPlaceToFireRegistrationResult = 0;

// R6Engine.dll data @ 100744b8 : intAR6AIControllerexecFindPlaceToTakeCover
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecFindPlaceToTakeCover = (Native)&AR6AIController::execFindPlaceToTakeCover;

// R6Engine.dll data @ 1007b130 : AR6AIControllerFindPlaceToTakeCoverRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerFindPlaceToTakeCoverRegistrationResult = 0;

// R6Engine.dll data @ 100744bc : intAR6AIControllerexecMakePathToRun
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6AIControllerexecMakePathToRun = (Native)&AR6AIController::execMakePathToRun;

// R6Engine.dll data @ 10080805 : AR6AIControllerMakePathToRunRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6AIControllerMakePathToRunRegistrationResult = 0;

// R6Engine.dll data @ 10078828 : autoclassAR6AIController
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6AIController = nullptr;

// R6Engine.dll data @ 10074310 : intAR6AIControllerexecPollMoveToPosition
// Exported four-byte member-callback word; registration passes its address, not the code pointer by value.
extern "C" Native intAR6AIControllerexecPollMoveToPosition = (Native)&AR6AIController::execPollMoveToPosition;

// R6Engine.dll data @ 100745b1 : pollPollMoveToPositionRegistrationResult
// Native startup stores GRegisterNative's returned byte here without interpreting it as a success boolean.
byte pollPollMoveToPositionRegistrationResult = 0;

// R6Engine.dll data @ 10074314 : intAR6AIControllerexecPollFollowPath
// Exported four-byte member-callback word; registration passes its address, not the code pointer by value.
extern "C" Native intAR6AIControllerexecPollFollowPath = (Native)&AR6AIController::execPollFollowPath;

// R6Engine.dll data @ 100745b0 : pollPollFollowPathRegistrationResult
// Native startup stores GRegisterNative's returned byte here without interpreting it as a success boolean.
byte pollPollFollowPathRegistrationResult = 0;

// R6Engine.dll data @ 10074318 : intAR6AIControllerexecPollFollowPathBlocked
// Exported four-byte member-callback word; registration passes its address, not the code pointer by value.
extern "C" Native intAR6AIControllerexecPollFollowPathBlocked = (Native)&AR6AIController::execPollFollowPathBlocked;

// R6Engine.dll data @ 100745b2 : pollPollFollowPathBlockedRegistrationResult
// Native startup stores GRegisterNative's returned byte here without interpreting it as a success boolean.
byte pollPollFollowPathBlockedRegistrationResult = 0;

// R6Engine.dll Ghidra decompilation reference; reconstruction status and evidence vary by method.
// Repeat-analysis boundary omissions have separate checked bodies in class_metadata_cleanup.cpp, runtime_callbacks.cpp,
// and runtime_support.cpp; see notes/r6-engine-foundations.md.
// R6Engine.dll @ 10001000 : AR6AIController::ClearActionSpot
// Clears pawn paths, then clears each current level action spot's valid-target bit.
void __thiscall AR6AIController::ClearActionSpot(void)
{
    // Descriptive frame: saved ESP EBP-24, caught/rethrow EBP-18/-14; no local cleanup.
    struct ClearFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ClearActionSpotExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    APawn* pawn = this->Pawn;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    pawn->APawn::clearPaths();
    ALevelInfo* levelInfo = this->Level;
    AR6ActionSpot* spot = levelInfo->m_ActionSpotList;
    while (spot != nullptr) {
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(spot) + 0x39c) &= ~1U;
        spot = spot->m_NextSpot;
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10001059 : ClearActionSpotCatchPointer
// Copies caught text from EBP-18 into the inherited EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl ClearActionSpotCatchPointer(void)
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

// R6Engine.dll @ 1000106d : ClearActionSpotCatchContext
// Reports the native ClearActionSpot context and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClearActionSpotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerClearActionSpot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100010f0 : AR6AIController::execPollMoveToPosition
// Polls adjustment then destination, clears the latent action on completion, and updates an unset move-result byte.
void __thiscall AR6AIController::execPollMoveToPosition(FFrame& unusedStack, void* unusedResult)
{
    // Native state-frame pointer slot; reload its value across callbacks.
    FStateFrame** stateFrameSlot = reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0xc);
    AR6Pawn* pawn = static_cast<AR6Pawn*>(this->Pawn);
    if (pawn == nullptr) {
        // Read before the result-byte store.
        FStateFrame* stateFrame = *stateFrameSlot;
        this->m_eMoveToResult = 2;
        stateFrame->LatentAction = 0; // Selected FStateFrame::LatentAction is the DWORD at +0x28.
        return;
    }
    uint* controllerFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8);
    if ((reinterpret_cast<byte*>(controllerFlagWord)[0] & 0x40U) != 0) {
        int adjustmentFinished = pawn->AR6Pawn::moveToPosition(&this->AdjustLoc);
        uint flags = *controllerFlagWord; // Fresh full word after the callback.
        flags = (flags & ~0x40U) | (adjustmentFinished == 0 ? 0x40U : 0U);
        *controllerFlagWord = flags;
        if ((flags & 0x40U) != 0)
            goto CheckLatentCompletion;
    }
    pawn = static_cast<AR6Pawn*>(this->Pawn); // Reload without another null guard before polling the destination.
    if (pawn->AR6Pawn::moveToPosition(&this->Destination) != 0) {
        FStateFrame* stateFrame = *stateFrameSlot;
        stateFrame->LatentAction = 0;
    }
CheckLatentCompletion:
    // Reread even after the preceding clear.
    FStateFrame* stateFrame = *stateFrameSlot;
    if (stateFrame->LatentAction == 0 && this->m_eMoveToResult == 0)
        this->m_eMoveToResult = 2;
}

// R6Engine.dll @ 10001190 : AR6AIController::SetDestinationToNextInCache
// Advances the unchecked route index, sets destination/timer, and copies the current destination when Focus is absent.
int __thiscall AR6AIController::SetDestinationToNextInCache(void)
{
    uint nextWord = (uint)this->m_iCurrentRouteCache + 1U;
    this->m_iCurrentRouteCache = (int)nextWord; // INC wraps; the increment remains on failure.
    if ((int)nextWord > 15)
        return 0;
    auto routeAt = [&](uint indexWord) { // Native has no lower-bound check; address arithmetic wraps at 32 bits.
        uint address = (uint)(uintptr_t)this + 0x408U + indexWord * 4U;
        return *reinterpret_cast<AActor**>(static_cast<uintptr_t>(address));
    };
    if (routeAt(nextWord) == nullptr)
        return 0;
    APawn* pawn = this->Pawn;
    pawn->DesiredSpeed = 1.0f; // No pawn-null check.
    uint currentIndex = (uint)this->m_iCurrentRouteCache;
    AActor* target = routeAt(currentIndex); // Reload index/entry after the speed store, without another bounds check.
    this->MoveTarget = target;
    const uint* location = (const uint*)&target->Location;
    uint* destination = (uint*)&this->Destination;
    destination[0] = location[0];
    destination[1] = location[1];
    destination[2] = location[2];
    float10 deltaZ = this->Destination.Z;
    pawn = this->Pawn; // One captured pawn supplies all three subtractions.
    deltaZ -= pawn->Location.Z;
    float10 deltaY = (float10)this->Destination.Y - pawn->Location.Y;
    float10 deltaX = (float10)this->Destination.X - pawn->Location.X;
    struct NativeLocalView { // Inferred entryESP-relative storage, before saved registers.
        float distance; // entryESP-0x10.
        FVector delta; // entryESP-0x0c.
    } frame;
    frame.delta.X = (float)deltaX;
    frame.delta.Y = (float)deltaY;
    frame.delta.Z = (float)deltaZ;
    float10 length = frame.delta.Size();
    frame.distance = (float)length;
    uint distanceWord = reinterpret_cast<uint&>(frame.distance);
    pawn = this->Pawn; // Reload after Size and the distance spill/word read.
    pawn->APawn::setMoveTimer(reinterpret_cast<float&>(distanceWord));
    if (this->Focus == nullptr) {
        uint x = destination[0];
        uint y = destination[1];
        uint z = destination[2];
        uint* focal = (uint*)&this->FocalPoint;
        focal[0] = x;
        focal[1] = y;
        focal[2] = z;
    }
    return 1;
}

// R6Engine.dll @ 10001280 : AR6AIController::execPollFollowPathBlocked
// Advances the destination cache only when Pawn is nonnull, then writes latent action 0x25a or zero; RET 8.
void __thiscall AR6AIController::execPollFollowPathBlocked(FFrame& unusedStack, void* unusedResult)
{
    int cacheAdvanced = 0;
    if (this->Pawn != nullptr) // Controller.Pawn at +0x3d8.
        cacheAdvanced = this->AR6AIController::SetDestinationToNextInCache();
    FStateFrame* stateFrame = *reinterpret_cast<FStateFrame**>((byte*)this + 0xc);
    stateFrame->LatentAction = cacheAdvanced != 0 ? 0x25aU : 0U;
}

// R6Engine.dll @ 100012c0 : AR6AIController::execPickActorAdjust
// Delegates adjustment outside the strict radius test, otherwise resets or advances the latent path action.
void __thiscall AR6AIController::execPickActorAdjust(FFrame& stack, void* result)
{
    // Descriptive frame: saved ESP EBP-40, actor/destination words EBP-34/-28, caught/rethrow EBP-1c/-18.
    struct AdjustFrame {
        uint savedEDI, savedESI, savedEBX, actorWords[3], destinationWords[3], caughtText, rethrowText;
        AActor* actor;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &PickActorAdjustExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = &stack;
    byte* code = frame->Code;
    nativeFrame.actor = nullptr;
    uint token = *code;
    frame->Code = code + 1;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    nativeFrame.exceptionState = 0;
    natives[token](receiver, frame, &nativeFrame.actor);
    code = frame->Code + 1;
    frame->Code = code;
    if (*code == 0x42) {
        receiver = frame->Object;
        frame->Code = code + 1;
        natives = *(NativeExec**)&CoreGNativesImport;
        natives[0x42](receiver, frame, nullptr);
    }
    AR6Pawn* pawn = static_cast<AR6Pawn*>(this->Pawn);
    if (pawn != nullptr) {
        AActor* actor = nativeFrame.actor;
        nativeFrame.actorWords[0] = reinterpret_cast<const uint&>(actor->Location.X);
        uint actorY = reinterpret_cast<const uint&>(actor->Location.Y);
        uint actorZ = reinterpret_cast<const uint&>(actor->Location.Z);
        nativeFrame.actorWords[2] = actorZ;
        nativeFrame.actorWords[1] = actorY;
        nativeFrame.destinationWords[0] = reinterpret_cast<const uint&>(this->Destination.X);
        nativeFrame.destinationWords[1] = reinterpret_cast<const uint&>(this->Destination.Y);
        float10 deltaY = (float10)reinterpret_cast<float&>(nativeFrame.destinationWords[1]) -
            (float10)reinterpret_cast<float&>(nativeFrame.actorWords[1]);
        uint destinationZ = reinterpret_cast<const uint&>(this->Destination.Z);
        float10 destinationX = (float10)reinterpret_cast<float&>(nativeFrame.destinationWords[0]);
        nativeFrame.destinationWords[2] = destinationZ;
        float10 deltaX = destinationX - (float10)reinterpret_cast<float&>(nativeFrame.actorWords[0]);
        float10 radius = (float10)actor->CollisionRadius;
        float10 squareX = deltaX * deltaX;
        float10 squareY = deltaY * deltaY;
        float10 distanceSquared = squareX + squareY;
        float10 threshold = radius * radius;
        threshold *= (float10)nativeFloat4;
        if (!(threshold > distanceSquared)) {
            int adjusted = pawn->AR6Pawn::PickActorAdjust(actor);
            void* resultBuffer = result;
            void* previousChain = nativeFrame.previousExceptionList;
            *(int*)resultBuffer = adjusted;
            ExceptionList = previousChain;
            return;
        }
        *(uint*)result = 0;
        FStateFrame* stateFrame = *reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0x0c);
        uint previousAction = stateFrame->LatentAction;
        stateFrame->LatentAction = (previousAction == 0x25a || previousAction == 0x25b) ? 0x25b : 0;
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10001406 : PickActorAdjustCatchPointer
// Copies caught text from EBP-1c into the inherited EBP-18 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl PickActorAdjustCatchPointer(void)
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

// R6Engine.dll @ 1000141a : PickActorAdjustCatchContext
// Reports the native adjustment context, clears EBX and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PickActorAdjustCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecPickActorAdjust
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10001440 : AR6AIController::execActorReachableFromLocation
// Evaluates target and origin, then stores reachability or logs missing inputs before storing zero.
void __thiscall AR6AIController::execActorReachableFromLocation(FFrame& stack, void* result)
{
    // Descriptive frame: saved ESP EBP-34, raw origin EBP-28, caught/rethrow EBP-1c/-18, target EBP-14.
    struct ReachFrame {
        uint savedEDI, savedESI, savedEBX, locationWords[3], caughtText, rethrowText;
        AActor* target;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &ActorReachableExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = &stack;
    byte* code = frame->Code;
    nativeFrame.target = nullptr;
    uint token = *code;
    frame->Code = code + 1;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* receiver = frame->Object;
    nativeFrame.exceptionState = 0;
    natives[token](receiver, frame, &nativeFrame.target);
    code = frame->Code;
    token = *code;
    receiver = frame->Object;
    frame->Code = code + 1;
    natives = *(NativeExec**)&CoreGNativesImport;
    natives[token](receiver, frame, nativeFrame.locationWords); // Required vector output storage is uninitialized.
    code = frame->Code + 1;
    frame->Code = code;
    if (*code == 0x42) {
        receiver = frame->Object;
        frame->Code = code + 1;
        natives = *(NativeExec**)&CoreGNativesImport;
        natives[0x42](receiver, frame, nullptr);
    }
    AActor* target = nativeFrame.target;
    if (target != nullptr && this->Pawn != nullptr) {
        uint originX = nativeFrame.locationWords[0];
        uint originY = nativeFrame.locationWords[1];
        uint originZ = nativeFrame.locationWords[2];
        // Pawn gates the call; this separately loaded receiver is unchecked.
        AR6Pawn* pawn = this->m_r6pawn;
        using Reachable = int (__thiscall*)(AR6Pawn*, AActor*, uint, uint, uint); // Raw actor/FVector by-value packet.
        int reachable = ((Reachable)&AR6PawnActorReachableFromLocationNativeEntry)(pawn, target, originX,
            originY, originZ);
        *(int*)result = reachable;
    } else {
        FStateFrame* stateFrame = *reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0x0c);
        const ushort* stateDescription = stateFrame->FStateFrame::Describe();
        const ushort* controllerName = this->UObject::GetName();
        FOutputDevice** logSlot = *(FOutputDevice***)&CoreGLogImport;
        FOutputDevice* log = *logSlot;
        log->FOutputDevice::Logf(static_cast<EName>(0x305),
            nativeTextWarningNoPawnOrGoalForActorReachableFromLocationBySInS, controllerName,
            stateDescription);
        *(uint*)result = 0; // Logging completes before this current output pointer is read; inputs are not rechecked.
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10001564 : ActorReachableCatchPointer
// Copies caught text from EBP-1c into the inherited EBP-18 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl ActorReachableCatchPointer(void)
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

// R6Engine.dll @ 10001578 : ActorReachableCatchContext
// Reports the native reachability context and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ActorReachableCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecActorReachableFromLocation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10007dd0 : AR6AIController::eventOpenDoorFailed
// Dispatches OpenDoorFailed with no parameter or result buffer using the pre-lookup vtable.
void __thiscall AR6AIController::eventOpenDoorFailed(void)
{
    FName eventName = R6ENGINE_OpenDoorFailed;
    using EventDispatcher = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007e00 : AR6AIController::eventCanOpenDoor
// Dispatches the rotating-door query and returns the full updated result word.
ulong __thiscall AR6AIController::eventCanOpenDoor(AR6IORotatingDoor* Door)
{
    FName eventName = R6ENGINE_CanOpenDoor;
    AR6IORotatingDoor* capturedDoor = Door; // Incoming word is read before the vtable and packet stores.
    using EventDispatcher = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    struct {
        AR6IORotatingDoor* Door; // +0x0.
        ulong ReturnValue; // +0x4; native Windows unsigned long is four bytes.
    } parameters;
    parameters.ReturnValue = 0;
    parameters.Door = capturedDoor;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &parameters, nullptr);
    return parameters.ReturnValue;
}

// R6Engine.dll @ 10007e50 : AR6AIController::eventR6SetMovement
// Dispatches movement pace from its native argument slot using the pre-lookup vtable.
void __thiscall AR6AIController::eventR6SetMovement(uchar ePace)
{
    FName eventName = R6ENGINE_R6SetMovement;
    byte capturedPace = ePace; // Incoming BYTE is read before the vtable.
    using EventDispatcher = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    ePace = capturedPace; // Native rewrites only this BYTE before lookup; upper argument bytes stay current.
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Other bytes of the native argument word stay untouched.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &ePace, nullptr);
}

// R6Engine.dll @ 10007e90 : AR6AIController::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6AIController::StaticClass(void)
{
    return &AR6AIController::PrivateStaticClass; // Selected object at0x1007c060.
}

// R6Engine.dll @ 10007ea0 : AR6AIController::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6AIController::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
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
    packet.classObject = &AR6AIController::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10007ed0 : AR6AIController::~AR6AIController
// Installs the derived table, conditionally destroys the object, then destroys its AIController base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6AIController::~AR6AIController(AR6AIController* this)
{
    struct NativeFrameView { // Descriptive FPO frame; inherited cleanup EBP points at entry ESP.
        uint savedEsi; // Entry ESP-0x14.
        AR6AIController* object; // Entry ESP-0x10.
        void* previousExceptionList; // Entry ESP-0x0c.
        void* handler; // Entry ESP-0x08.
        int state; // Entry ESP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerDtorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.object = this;
    *(uint*)this = ((uint)&AR6AIControllerVirtualTable);
    frame.state = 0;
    // Native ignores the returned integer.
    this->UObject::ConditionalDestroy();
    frame.state = -1;
    this->AAIController::~AAIController();
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 10043290 : destroy the AAIController base when ConditionalDestroy unwinds
// Loads the saved receiver from the inherited FPO frame and tail-jumps through the current base-destructor import.
__declspec(naked) void AiControllerDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AAIControllerDestructorImport]
    }
}

// R6Engine.dll @ 10043299 : AIControllerDtorExceptionHandler
// Forwards the destructor's exact unwind metadata to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset aiControllerDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10007f30 : AR6AIController::AR6AIController
// Constructs the base and publishes the class table without initializing derived field words.
AR6AIController::AR6AIController() : AAIController()
{
    // Native publication: AR6AIControllerVirtualTable after the base returns; EAX preserves incoming ECX.
}

// R6Engine.dll @ 10007f50 : AR6AIController::AR6AIController(const AR6AIController&)
// Copies the base and named AI state, preserving destination flag bits above the eight declared Booleans.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6AIController* __thiscall AR6AIController::AR6AIController(AR6AIController* this, const AR6AIController* source)
{
    const AR6AIController* capturedSource = source; // Native EDI retains this pointer across the base call.
    AAIController::AAIController(this, capturedSource);
    // +0x500: eight low-bit flags; keep fresh DWORD reads and preserve the upper 24 bits.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x500);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x500);
    uint initialFlags = *destinationFlagWord;
    *(uint*)this = ((uint)&AR6AIControllerVirtualTable);
    this->c_iDistanceBumpBackUp = capturedSource->c_iDistanceBumpBackUp; // +0x4f8.
    this->m_iCurrentRouteCache = capturedSource->m_iCurrentRouteCache; // +0x4fc.
    uint firstFlagDifference = initialFlags ^ *sourceFlagWord;
    uint flags = *destinationFlagWord;
    flags ^= firstFlagDifference & 1U;
    *destinationFlagWord = flags; // m_bStateBackupAvoidFacingWalls.
    flags ^= (*sourceFlagWord ^ flags) & 0x2U;
    *destinationFlagWord = flags; // m_bIgnoreBackupBump.
    flags ^= (*sourceFlagWord ^ flags) & 0x4U;
    *destinationFlagWord = flags; // m_bGetOffLadder.
    flags ^= (*sourceFlagWord ^ flags) & 0x8U;
    *destinationFlagWord = flags; // bShowLog.
    flags ^= (*sourceFlagWord ^ flags) & 0x10U;
    *destinationFlagWord = flags; // bShowInteractionLog.
    flags ^= (*sourceFlagWord ^ flags) & 0x20U;
    *destinationFlagWord = flags; // m_bChangingState.
    flags ^= (*sourceFlagWord ^ flags) & 0x40U;
    *destinationFlagWord = flags; // m_bCantInterruptIO.
    flags ^= (*sourceFlagWord ^ flags) & 0x80U;
    *destinationFlagWord = flags; // m_bMoveTargetAlreadySet.
    reinterpret_cast<uint&>(this->m_fLastBump) = reinterpret_cast<const uint&>(capturedSource->m_fLastBump); // +0x504.
    // +0x508.
    reinterpret_cast<uint&>(this->m_fLoopAnimTime) = reinterpret_cast<const uint&>(capturedSource->m_fLoopAnimTime);
    this->m_r6pawn = capturedSource->m_r6pawn; // +0x50c.
    this->m_TargetLadder = capturedSource->m_TargetLadder; // +0x510.
    this->m_BumpedBy = capturedSource->m_BumpedBy; // +0x514.
    this->m_climbingObject = capturedSource->m_climbingObject; // +0x518.
    this->m_InteractionObject = capturedSource->m_InteractionObject; // +0x51c.
    this->m_ActorTarget = capturedSource->m_ActorTarget; // +0x520.
    this->m_closeDoor = capturedSource->m_closeDoor; // +0x524.
    *(uint*)&this->m_bumpBackUpNextState = *(const uint*)&capturedSource->m_bumpBackUpNextState; // +0x528.
    *(uint*)&this->m_openDoorNextState = *(const uint*)&capturedSource->m_openDoorNextState; // +0x52c.
    *(uint*)&this->m_climbingObjectNextState = *(const uint*)&capturedSource->m_climbingObjectNextState; // +0x530.
    reinterpret_cast<uint&>(this->m_AnimName) = reinterpret_cast<const uint&>(capturedSource->m_AnimName); // +0x534.
    *(uint*)&this->m_StateAfterInteraction = *(const uint*)&capturedSource->m_StateAfterInteraction; // +0x538.
    reinterpret_cast<uint&>(this->m_vTargetPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.X);
    reinterpret_cast<uint&>(this->m_vTargetPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.Y);
    reinterpret_cast<uint&>(this->m_vTargetPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.Z);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.X);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Y);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Z);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.X);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.Y);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.Z);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.X);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.Y);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.Z);
    return this;
}

// R6Engine.dll @ 10008150 : AR6AIController::operator=
// Assigns base and AI state with eight ordered flag merges and raw-word float/vector copies.
AR6AIController& __thiscall AR6AIController::operator=(const AR6AIController& sourceObject)
{
    const AR6AIController* source = &sourceObject;
    const AR6AIController* capturedSource = source; // Native EDI retains this pointer across the base call.
    this->AAIController::operator=(*capturedSource);
    this->c_iDistanceBumpBackUp = capturedSource->c_iDistanceBumpBackUp; // +0x4f8.
    int routeCacheIndex = capturedSource->m_iCurrentRouteCache;
    // +0x500: eight low-bit flags; keep fresh DWORD reads and preserve the upper 24 bits.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x500);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x500);
    uint initialFlags = *destinationFlagWord;
    this->m_iCurrentRouteCache = routeCacheIndex; // +0x4fc.
    uint firstFlagDifference = initialFlags ^ *sourceFlagWord;
    uint flags = *destinationFlagWord;
    flags ^= firstFlagDifference & 1U;
    *destinationFlagWord = flags; // m_bStateBackupAvoidFacingWalls.
    flags ^= (*sourceFlagWord ^ flags) & 0x2U;
    *destinationFlagWord = flags; // m_bIgnoreBackupBump.
    flags ^= (*sourceFlagWord ^ flags) & 0x4U;
    *destinationFlagWord = flags; // m_bGetOffLadder.
    flags ^= (*sourceFlagWord ^ flags) & 0x8U;
    *destinationFlagWord = flags; // bShowLog.
    flags ^= (*sourceFlagWord ^ flags) & 0x10U;
    *destinationFlagWord = flags; // bShowInteractionLog.
    flags ^= (*sourceFlagWord ^ flags) & 0x20U;
    *destinationFlagWord = flags; // m_bChangingState.
    flags ^= (*sourceFlagWord ^ flags) & 0x40U;
    *destinationFlagWord = flags; // m_bCantInterruptIO.
    flags ^= (*sourceFlagWord ^ flags) & 0x80U;
    *destinationFlagWord = flags; // m_bMoveTargetAlreadySet.
    reinterpret_cast<uint&>(this->m_fLastBump) = reinterpret_cast<const uint&>(capturedSource->m_fLastBump); // +0x504.
    // +0x508.
    reinterpret_cast<uint&>(this->m_fLoopAnimTime) = reinterpret_cast<const uint&>(capturedSource->m_fLoopAnimTime);
    this->m_r6pawn = capturedSource->m_r6pawn; // +0x50c.
    this->m_TargetLadder = capturedSource->m_TargetLadder; // +0x510.
    this->m_BumpedBy = capturedSource->m_BumpedBy; // +0x514.
    this->m_climbingObject = capturedSource->m_climbingObject; // +0x518.
    this->m_InteractionObject = capturedSource->m_InteractionObject; // +0x51c.
    this->m_ActorTarget = capturedSource->m_ActorTarget; // +0x520.
    this->m_closeDoor = capturedSource->m_closeDoor; // +0x524.
    *(uint*)&this->m_bumpBackUpNextState = *(const uint*)&capturedSource->m_bumpBackUpNextState; // +0x528.
    *(uint*)&this->m_openDoorNextState = *(const uint*)&capturedSource->m_openDoorNextState; // +0x52c.
    *(uint*)&this->m_climbingObjectNextState = *(const uint*)&capturedSource->m_climbingObjectNextState; // +0x530.
    reinterpret_cast<uint&>(this->m_AnimName) = reinterpret_cast<const uint&>(capturedSource->m_AnimName); // +0x534.
    *(uint*)&this->m_StateAfterInteraction = *(const uint*)&capturedSource->m_StateAfterInteraction; // +0x538.
    reinterpret_cast<uint&>(this->m_vTargetPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.X);
    reinterpret_cast<uint&>(this->m_vTargetPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.Y);
    reinterpret_cast<uint&>(this->m_vTargetPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vTargetPosition.Z);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.X);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Y);
    reinterpret_cast<uint&>(this->m_vPreviousPosition.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vPreviousPosition.Z);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.X);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.Y);
    reinterpret_cast<uint&>(this->m_vBumpedByLocation.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByLocation.Z);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.X);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.Y);
    reinterpret_cast<uint&>(this->m_vBumpedByVelocity.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vBumpedByVelocity.Z);
    return *this;
}

// R6Engine.dll @ 1000aec0 : AR6AIController::execMakePathToRun
// Penalizes exposed nodes, finds an escape route and rejects either initial segment when too close to the enemy.
// Native ABI view retains the incoming frame word for the live path-node pointer.
void __thiscall AR6AIController::execMakePathToRun(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage, not an inferred original declaration.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x64/-0x60/-0x5c.
        NativeCheckResult32 hit; // EBP-0x58..-0x2c; Actor+4,Time+0x24,Item+0x28.
        FVector difference; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        uint distanceWord; // EBP-0x14: float scratch, then signed conversion low word.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&EscapeRouteExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    // Native reuses EBP+8 for node, path weight and the common distance limit.
    uint& incomingWord = reinterpret_cast<uint&>(stack);
    FFrame* scriptFrame = stack;
    byte* code = scriptFrame->Code + 1;
    scriptFrame->Code = code;
    bool debugInfo = *code == 0x42;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (debugInfo) {
        UObject* receiver = scriptFrame->Object;
        scriptFrame->Code = code + 1;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, scriptFrame, nullptr);
    }
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    APawn* pawn = this->Pawn;
    if (pawn == nullptr) {
        *(uint*)result = 0;
        finish();
        return;
    }
    APawn* enemy = this->Enemy;
    if (enemy == nullptr) {
        const ushort* pawnName = pawn->UObject::GetName();
        FOutputDevice** logSlot = *(FOutputDevice***)&CoreGLogImport;
        FOutputDevice* log = *logSlot;
        log->FOutputDevice::Logf(static_cast<EName>(0x301),
            nativeTextSMustHaveAnEnemyToCreateAPathInMakePathToRun, pawnName);
        *(uint*)result = 0; // Warning finishes before loading the current output pointer.
        finish();
        return;
    }
    pawn->APawn::clearPaths();
    ALevelInfo* levelInfo = this->Level;
    ANavigationPoint* node = levelInfo->NavigationPointList;
    // Views the native live ST(0), including unspilled return precision.
    using Size = float10 (__thiscall*)(const FVector*);
    for (;;) {
        incomingWord = (uint)node;
        if (node == nullptr)
            break;
        enemy = this->Enemy;
        float10 dz = (float10)enemy->Location.Z - node->Location.Z;
        const FVector* nodeLocation = &node->Location;
        float10 dy = (float10)enemy->Location.Y - nodeLocation->Y;
        float10 dx = (float10)enemy->Location.X - nodeLocation->X;
        frame.difference.X = (float)dx;
        frame.difference.Y = (float)dy;
        frame.difference.Z = (float)dz;
        float10 liveDistance = reinterpret_cast<Size&>(FVectorSizeImport)(&frame.difference);
        // FST does not pop or replace the conversion input.
        reinterpret_cast<float&>(frame.distanceWord) = (float)liveDistance;
        __asm {
            call TruncateX87ToSigned64
            mov frame.distanceWord,eax
        }
        if ((int)frame.distanceWord < 10000) {
            for (uint i = 0; i < 9; ++i)
                reinterpret_cast<uint*>(&frame.hit)[i] = 0;
            frame.hit.materialAddress = 0;
            ULevel* capturedLevel = this->XLevel;
            reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000;
            reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffff;
            byte* capturedVtable = *reinterpret_cast<byte**>(capturedLevel);
            uint* zero = *(uint**)&FVectorFVector0Import;
            uint zeroX = zero[0];
            uint zeroY = zero[1];
            uint zeroZ = zero[2];
            enemy = this->Enemy;
            ULevel* receiver = this->XLevel;
            // Raw FCheckResult and by-value FVector packet; the vtable slot remains current until CALL.
            using LineCheck = int (__thiscall*)(ULevel*, uint*, AActor*, const FVector*, const FVector*, uint,
                uint, uint, uint);
            (*reinterpret_cast<LineCheck*>(capturedVtable + 0xcc))(receiver, reinterpret_cast<uint*>(&frame.hit), enemy,
                &enemy->Location, nodeLocation, 0x286, zeroX, zeroY, zeroZ);
            uint hitActor = frame.hit.actorAddress;
            node = reinterpret_cast<ANavigationPoint*>(incomingWord);
            if (hitActor == 0)
                reinterpret_cast<uint&>(node->cost) = 10000U - frame.distanceWord;
        }
        node = node->nextNavigationPoint;
    }
    uint* zero = *(uint**)&FVectorFVector0Import;
    uint zeroX = zero[0];
    uint zeroY = zero[1];
    uint zeroZ = zero[2];
    pawn = this->Pawn;
    using NodeEvaluator = float10 (__cdecl*)(ANavigationPoint*, APawn*, float);
    using FindPath = float10 (__thiscall*)(APawn*, AActor*, uint, uint, uint, NodeEvaluator, int, uint);
    float10 pathWeight = reinterpret_cast<FindPath&>(APawnFindPathTowardImport)(pawn, nullptr, zeroX, zeroY, zeroZ,
        EvaluateNavigationNodeWeight, 0, 0);
    // Scratch spill; ordered comparison still uses live ST(0).
    reinterpret_cast<float&>(incomingWord) = (float)pathWeight;
    if (!(pathWeight > (float10)nativeFloatZero)) {
        void* output = result;
        void* previous = frame.previousExceptionList; // This path captures FS before writing the result.
        *(uint*)output = 0;
        ExceptionList = previous;
        return;
    }
    enemy = this->Enemy;
    float10 dz = enemy->Location.Z;
    pawn = this->Pawn;
    dz -= pawn->Location.Z;
    float10 dy = (float10)enemy->Location.Y - pawn->Location.Y;
    float10 dx = (float10)enemy->Location.X - pawn->Location.X;
    frame.difference.X = (float)dx;
    frame.difference.Y = (float)dy;
    frame.difference.Z = (float)dz;
    float10 livePawnDistance = reinterpret_cast<Size&>(FVectorSizeImport)(&frame.difference);
    AActor* first = this->RouteCache[0];
    reinterpret_cast<float&>(incomingWord) = (float)livePawnDistance;
    pawn = this->Pawn;
    float10 liveLimit = livePawnDistance - nativeFloat1EPlus01;
    enemy = this->Enemy;
    reinterpret_cast<float&>(incomingWord) = (float)liveLimit;
    float10 segment = DistanceToSegment(&enemy->Location, &pawn->Location, &first->Location);
    bool below500 = segment < (float10)nativeFloat5EPlus02;
    reinterpret_cast<float&>(frame.distanceWord) = (float)segment; // Both lazy tests use the unspilled distance.
    int blockedIndex = -1;
    if (below500 && segment < (float10)reinterpret_cast<float&>(incomingWord)) {
        blockedIndex = 0;
    } else {
        AActor* second = this->RouteCache[1];
        if (second != nullptr) {
            enemy = this->Enemy;
            first = this->RouteCache[0];
            segment = DistanceToSegment(&enemy->Location, &first->Location, &second->Location);
            below500 = segment < (float10)nativeFloat5EPlus02;
            reinterpret_cast<float&>(frame.distanceWord) = (float)segment;
            if (below500 && segment < (float10)reinterpret_cast<float&>(incomingWord))
                blockedIndex = 1;
        }
    }
    if (blockedIndex >= 0) {
        *(uint*)result = 0;
        AActor* blocked = this->RouteCache[blockedIndex];
        const ushort* nodeName = blocked->UObject::GetName();
        AActor* goal = this->RouteGoal;
        const ushort* goalName = goal->UObject::GetName();
        pawn = this->Pawn;
        const ushort* pawnName = pawn->UObject::GetName();
        FOutputDevice** logSlot = *(FOutputDevice***)&CoreGLogImport;
        FOutputDevice* log = *logSlot;
        log->FOutputDevice::Logf(static_cast<EName>(0x301),
            nativeTextSCannotReachSSBlockedByEnemy, pawnName,
            goalName, nodeName);
    } else {
        *(uint*)result = 1;
    }
    finish();
}

// R6Engine.dll @ 1000b278 : forward the caught escape-route bridge exception value
// Copies the inherited caught word into the rethrow slot and forwards its original throw metadata.
__declspec(naked) void EscapeRouteCatchPointer(void)
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

// R6Engine.dll @ 1000b28c : report escape-route bridge context and forward the active exception
// Reports the native context through the current import, then rethrows with two null words.
__declspec(naked) void EscapeRouteCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecMakePathToRun
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043400 : EscapeRouteExceptionHandler
// Forwards this bridge's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void EscapeRouteExceptionHandler(void)
{
    __asm {
        mov eax,offset escapeRouteFuncInfo
        jmp __CxxFrameHandler
    }
}

// The native export identifies this reference type; its field layout remains separately scoped.
struct STActionSpotCheck;

// Inferred names for the used 20-byte context prefix; the full original type remains unclaimed.
struct NativeActionSpotCheckPrefix {
    FVector location; // +0.
    AActor* target; // +0xc.
    int searchIndex; // +0x10.
};
using ActionSpotFilter = int (__cdecl *)(AR6Pawn*, AR6ActionSpot*, STActionSpotCheck*);

// R6Engine.dll @ 1000b2b0 : AR6AIController::FindNearestActionSpot
// Marks in-range filtered spots, finds a path through the last accepted seed and selects a marked route-goal anchor.
AR6ActionSpot* __thiscall AR6AIController::FindNearestActionSpot(float searchRadius, FVector origin,
    ActionSpotFilter spotFilter, STActionSpotCheck* filterContext)
{
    struct NativeFrameView { // Descriptive EBP-relative frame; callback context is an opaque reference-pointer view.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        float radiusSquared; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&NearestSpotExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    APawn* initialPawn = this->Pawn;
    AR6ActionSpot* lastAcceptedSpot = nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (initialPawn == nullptr) {
        ExceptionList = frame.previousExceptionList;
        return nullptr;
    }
    this->AR6AIController::ClearActionSpot();
    float10 liveRadiusSquared = (float10)searchRadius * searchRadius;
    ALevelInfo* levelInfo = this->Level;
    AR6ActionSpot* spot = levelInfo->m_ActionSpotList;
    frame.radiusSquared = (float)liveRadiusSquared; // List-head access precedes this binary32 spill.
    while (spot != nullptr) {
        float10 deltaZ = (float10)spot->Location.Z - origin.Z;
        float10 deltaY = (float10)spot->Location.Y - origin.Y;
        float10 deltaX = (float10)spot->Location.X - origin.X;
        float10 xSquared = deltaX * deltaX;
        float10 ySquared = deltaY * deltaY;
        float10 distanceSquared = xSquared + ySquared;
        float10 zSquared = deltaZ * deltaZ;
        distanceSquared += zSquared;
        bool inRange = distanceSquared < (float10)frame.radiusSquared; // Native empties the x87 stack before callback.
        if (inRange) {
            STActionSpotCheck* currentContext = filterContext;
            AR6Pawn* receiver = this->m_r6pawn;
            ActionSpotFilter currentFilter = spotFilter;
            if (currentFilter(receiver, spot, currentContext) != 0) {
                uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(spot) + 0x39c);
                *reinterpret_cast<uint*>(reinterpret_cast<byte*>(spot) + 0x39c) = flags | 1U;
                ANavigationPoint* anchor = spot->m_Anchor;
                uint anchorFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(anchor) + 0x3e4);
                lastAcceptedSpot = spot;
                // No anchor guard; preserve other flag bits.
                *reinterpret_cast<uint*>(reinterpret_cast<byte*>(anchor) + 0x3e4) = anchorFlags | 1U;
            }
        }
        spot = spot->m_NextSpot;
    }
    AR6ActionSpot* selectedSpot = nullptr;
    if (lastAcceptedSpot != nullptr) {
        uint* zero = *(uint**)&FVectorFVector0Import;
        uint zeroX = zero[0];
        uint zeroY = zero[1];
        uint zeroZ = zero[2];
        using FindPath = AActor* (__thiscall*)(AController*, uint, uint, uint, AActor*, int);
        AActor* path = reinterpret_cast<FindPath&>(AControllerFindPathImport)(this, zeroX, zeroY, zeroZ,
            lastAcceptedSpot, 0); // Raw by-value FVector packet; path is only a nonnull gate.
        if (path != nullptr && (float10)this->RouteDist < (float10)searchRadius) {
            levelInfo = this->Level;
            spot = levelInfo->m_ActionSpotList;
            while (spot != nullptr) {
                ANavigationPoint* anchor = spot->m_Anchor;
                AActor* routeGoal = this->RouteGoal;
                if (anchor == routeGoal && (reinterpret_cast<byte*>(spot)[0x39c] & 1U) != 0) {
                    selectedSpot = spot;
                    break;
                }
                spot = spot->m_NextSpot;
            }
        }
    }
    ExceptionList = frame.previousExceptionList;
    return selectedSpot;
}

// R6Engine.dll @ 1000b42a : forward the caught action-spot search exception value
// Copies the inherited caught word into its rethrow slot and forwards the original throw metadata.
__declspec(naked) void NearestSpotCatchPointer(void)
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

// R6Engine.dll @ 1000b43e : report action-spot search context and forward the active exception
// Reports the native FindNearestActionSpot diagnostic through the current import before null-word rethrow.
__declspec(naked) void NearestSpotCatchContext(void)
{
    __asm {
        push offset nativeTextFindNearestActionSpot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043410 : NearestSpotExceptionHandler
// Forwards the search's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void NearestSpotExceptionHandler(void)
{
    __asm {
        mov eax,offset nearestSpotFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000b7b0 : AR6AIController::execFindPlaceToTakeCover
// Evaluates cover-search operands, builds the raw predicate context and stores the selected action spot.
// Native ABI view retains the incoming frame word for the cover-radius operand.
void __thiscall AR6AIController::execFindPlaceToTakeCover(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; untouched words remain uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x44/-0x40/-0x3c.
        uint context[5]; // EBP-0x38..-0x28; native writes only the first three words.
        uint threat[3]; // EBP-0x24/-0x20/-0x1c; required operand starts uninitialized.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CoverSearchExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* scriptFrame = stack;
    uint& radiusWord = reinterpret_cast<uint&>(stack); // Native reuses incoming EBP+8; retained FFrame is separate.
    byte* code = scriptFrame->Code;
    uint token = *code;
    scriptFrame->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = scriptFrame->Object;
    frame.state = 0;
    natives[token](receiver, scriptFrame, frame.threat);
    code = scriptFrame->Code;
    receiver = scriptFrame->Object;
    radiusWord = 0;
    token = *code;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, &radiusWord);
    code = scriptFrame->Code + 1;
    scriptFrame->Code = code;
    if (*code == 0x42) {
        receiver = scriptFrame->Object;
        scriptFrame->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, scriptFrame, nullptr);
    }
    uint threatX = frame.threat[0];
    uint threatY = frame.threat[1];
    uint threatZ = frame.threat[2];
    frame.context[0] = threatX;
    frame.context[1] = threatY;
    APawn* pawn = this->Pawn;
    frame.context[2] = threatZ;
    uint originX = reinterpret_cast<uint&>(pawn->Location.X); // Native does not guard Pawn.
    uint originY = reinterpret_cast<uint&>(pawn->Location.Y);
    uint originZ = reinterpret_cast<uint&>(pawn->Location.Z);
    uint radius = radiusWord;
    // Raw radius/by-value FVector/predicate/reference-pointer words; this is an ABI view of the named search method.
    using Search = AR6ActionSpot* (__thiscall*)(AR6AIController*, uint, uint, uint, uint, ActionSpotFilter,
        STActionSpotCheck*);
    AR6ActionSpot* selected = ((Search)&AR6AIControllerFindNearestActionSpotNativeEntry)(this, radius, originX,
        originY, originZ,
        CheckSpotValidForCover, (STActionSpotCheck*)frame.context);
    // Current output argument is read only after the search returns.
    *reinterpret_cast<AR6ActionSpot**>(result) = selected;
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1000b89b : forward the caught execFindPlaceToTakeCover exception value
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void CoverSearchCatchPointer(void)
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

// R6Engine.dll @ 1000b8af : report execFindPlaceToTakeCover context and forward the active exception
// Reports the native context through the current import before null-word rethrow.
__declspec(naked) void CoverSearchCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecFindPlaceToTakeCover
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043440 : CoverSearchExceptionHandler
// Forwards the bridge's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void CoverSearchExceptionHandler(void)
{
    __asm {
        mov eax,offset coverSearchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000b8d0 : AR6AIController::execFindPlaceToFire
// Evaluates fire-search operands, builds the raw predicate context and stores the selected action spot.
// Native ABI view retains the incoming frame word for the fire-radius operand.
void __thiscall AR6AIController::execFindPlaceToFire(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; untouched words remain uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x48/-0x44/-0x40.
        uint context[5]; // EBP-0x3c..-0x2c; native leaves the final word untouched.
        uint destination[3]; // EBP-0x28/-0x24/-0x20; required operand starts uninitialized.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        uint target; // EBP-0x14; required operand starts uninitialized.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&FireSearchExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* scriptFrame = stack;
    uint& radiusWord = reinterpret_cast<uint&>(stack); // Native reuses incoming EBP+8; retained FFrame is separate.
    byte* code = scriptFrame->Code;
    uint token = *code;
    scriptFrame->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = scriptFrame->Object;
    frame.state = 0;
    natives[token](receiver, scriptFrame, &frame.target);
    code = scriptFrame->Code;
    token = *code;
    receiver = scriptFrame->Object;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, frame.destination);
    code = scriptFrame->Code;
    receiver = scriptFrame->Object;
    radiusWord = 0;
    token = *code;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, &radiusWord);
    code = scriptFrame->Code + 1;
    scriptFrame->Code = code;
    if (*code == 0x42) {
        receiver = scriptFrame->Object;
        scriptFrame->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, scriptFrame, nullptr);
    }
    uint target = frame.target;
    uint destinationY = frame.destination[1];
    uint destinationZ = frame.destination[2];
    frame.context[3] = target;
    uint destinationX = frame.destination[0];
    frame.context[1] = destinationY;
    uint radius = radiusWord;
    frame.context[0] = destinationX;
    frame.context[2] = destinationZ;
    // Raw radius/by-value FVector/predicate/reference-pointer words; this is an ABI view of the named search method.
    using Search = AR6ActionSpot* (__thiscall*)(AR6AIController*, uint, uint, uint, uint, ActionSpotFilter,
        STActionSpotCheck*);
    AR6ActionSpot* selected = ((Search)&AR6AIControllerFindNearestActionSpotNativeEntry)(this, radius,
        destinationX, destinationY, destinationZ,
        CheckSpotValidForFire, (STActionSpotCheck*)frame.context);
    AR6ActionSpot** output = reinterpret_cast<AR6ActionSpot**>(result);
    void* previous = frame.previousExceptionList; // Native captures the prior chain before the result store.
    *output = selected;
    ExceptionList = previous;
}

// R6Engine.dll @ 1000b9c7 : forward the caught execFindPlaceToFire exception value
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void FireSearchCatchPointer(void)
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

// R6Engine.dll @ 1000b9db : report execFindPlaceToFire context and forward the active exception
// Reports the native context through the current import before null-word rethrow.
__declspec(naked) void FireSearchCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecFindPlaceToFire
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043450 : FireSearchExceptionHandler
// Forwards the bridge's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void FireSearchExceptionHandler(void)
{
    __asm {
        mov eax,offset fireSearchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000ba00 : AR6AIController::execFindInvestigationPoint
// Evaluates investigation operands, chooses the raw search origin and stores the selected action spot.
// Native ABI view retains the incoming frame word for the from-threat operand.
void __thiscall AR6AIController::execFindInvestigationPoint(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; untouched context words remain uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x4c/-0x48/-0x44.
        uint context[5]; // EBP-0x40..-0x30; native initializes only context[4].
        uint threat[3]; // EBP-0x2c/-0x28/-0x24; copied from current FVector0 before evaluation.
        uint caught, rethrow; // EBP-0x20/-0x1c.
        uint radius, index; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&InvestigationSearchExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* scriptFrame = stack;
    uint& fromThreatWord = reinterpret_cast<uint&>(stack); // Native reuses incoming EBP+8; retained FFrame is separate.
    byte* code = scriptFrame->Code;
    frame.index = 0;
    uint token = *code;
    scriptFrame->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = scriptFrame->Object;
    frame.state = 0;
    natives[token](receiver, scriptFrame, &frame.index);
    code = scriptFrame->Code;
    receiver = scriptFrame->Object;
    frame.radius = 0;
    token = *code;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, &frame.radius);
    code = scriptFrame->Code;
    receiver = scriptFrame->Object;
    fromThreatWord = 0;
    token = *code;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, &fromThreatWord);
    uint* zero = *(uint**)&FVectorFVector0Import;
    frame.threat[0] = zero[0];
    frame.threat[1] = zero[1];
    uint zeroZ = zero[2];
    code = scriptFrame->Code;
    frame.threat[2] = zeroZ;
    token = *code;
    receiver = scriptFrame->Object;
    scriptFrame->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[token](receiver, scriptFrame, frame.threat);
    code = scriptFrame->Code + 1;
    scriptFrame->Code = code;
    if (*code == 0x42) {
        receiver = scriptFrame->Object;
        scriptFrame->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, scriptFrame, nullptr);
    }
    APawn* pawn = this->Pawn;
    uint fromThreat = fromThreatWord;
    // All Pawn coordinates are read before the captured flag branches.
    uint originX = reinterpret_cast<uint&>(pawn->Location.X);
    uint originY = reinterpret_cast<uint&>(pawn->Location.Y);
    uint originZ = reinterpret_cast<uint&>(pawn->Location.Z);
    if (fromThreat != 0) {
        originX = frame.threat[0];
        originY = frame.threat[1];
        originZ = frame.threat[2];
    }
    uint index = frame.index;
    frame.context[4] = index;
    uint radius = frame.radius;
    // Raw radius/by-value FVector/predicate/reference-pointer words; this is an ABI view of the named search method.
    using Search = AR6ActionSpot* (__thiscall*)(AR6AIController*, uint, uint, uint, uint, ActionSpotFilter,
        STActionSpotCheck*);
    AR6ActionSpot* selected = ((Search)&AR6AIControllerFindNearestActionSpotNativeEntry)(this, radius, originX,
        originY, originZ,
        CheckSpotValidForInvestigation, (STActionSpotCheck*)frame.context);
    *reinterpret_cast<AR6ActionSpot**>(result) = selected;
    ExceptionList = frame.previousExceptionList; // Current prior-chain slot is read after the output store.
}

// R6Engine.dll @ 1000bb3a : forward the caught execFindInvestigationPoint exception value
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void InvestigationSearchCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x1c]
        push eax
        mov dword ptr [ebp-0x1c],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1000bb4e : report execFindInvestigationPoint context and forward the active exception
// Reports through the current import, then clears EBX and uses it for both null rethrow words.
__declspec(naked) void InvestigationSearchCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecFindInvestigationPoint
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043460 : InvestigationSearchExceptionHandler
// Forwards the bridge's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void InvestigationSearchExceptionHandler(void)
{
    __asm {
        mov eax,offset investigationSearchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000bb70 : AR6AIController::execMoveToPosition
// Evaluates position/orientation, starts latent movement, and builds the focal point before the first movement call.
// Native ABI view retains the incoming frame word for the rounded move-distance spill.
void __thiscall AR6AIController::execMoveToPosition(FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    struct NativeLocalView { // Inferred entryESP-relative slots; none are initialized.
        FVector position; // -0x3c.
        FVector focalScratch; // -0x30.
        FVector displacement; // -0x24.
        FRotator orientation; // -0x18.
        FVector orientationVector; // -0x0c; Z later holds the rounded scaled product.
    } frame;
    FFrame* expressionStack = stack; // Retained even when a callback changes the incoming argument slot.
    byte* cursor = expressionStack->Code;
    byte opcode = *cursor;
    expressionStack->Code = cursor + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = expressionStack->Object;
    natives[opcode](receiver, expressionStack, &frame.position);
    cursor = expressionStack->Code;
    opcode = *cursor;
    receiver = expressionStack->Object;
    expressionStack->Code = cursor + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &frame.orientation);
    cursor = expressionStack->Code + 1;
    expressionStack->Code = cursor; // EndFunctionParms is consumed unconditionally.
    if (*cursor == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = cursor + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    APawn* pawn = this->Pawn;
    this->m_eMoveToResult = 0;
    if (pawn == nullptr) {
        this->m_eMoveToResult = 2;
        return;
    }
    float10 deltaZ = (float10)frame.position.Z - pawn->Location.Z;
    float10 deltaY = (float10)frame.position.Y - pawn->Location.Y;
    float10 deltaX = (float10)frame.position.X - pawn->Location.X;
    frame.displacement.X = (float)deltaX;
    frame.displacement.Y = (float)deltaY;
    frame.displacement.Z = (float)deltaZ;
    float10 length = frame.displacement.Size();
    pawn = this->Pawn; // Read before the distance spill into the incoming FFrame argument slot.
    // entryESP+4 is reused; expressionStack remains the original frame.
    reinterpret_cast<float&>(stack) = (float)length;
    uint distanceWord = reinterpret_cast<uint&>(stack);
    this->MoveTarget = nullptr;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x3e0) &= ~0x2000U; // bReducedSpeed.
    pawn = this->Pawn;
    uint speedWord = reinterpret_cast<uint&>(pawn->MaxDesiredSpeed);
    reinterpret_cast<uint&>(pawn->DesiredSpeed) = speedWord;
    pawn = this->Pawn;
    pawn->APawn::setMoveTimer(reinterpret_cast<float&>(distanceWord));
    (*reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0xc))->LatentAction = 0x259;
    uint x = reinterpret_cast<uint&>(frame.position.X);
    uint y = reinterpret_cast<uint&>(frame.position.Y);
    uint* destination = (uint*)&this->Destination;
    destination[0] = x;
    uint z = reinterpret_cast<uint&>(frame.position.Z);
    destination[1] = y;
    destination[2] = z;
    this->Focus = nullptr;
    FVector* orientation = &(frame.orientationVector = frame.orientation.Vector());
    float10 scaledX = (float10)orientation->X * nativeFloat2EPlus02;
    float10 scaledY = (float10)orientation->Y * nativeFloat2EPlus02;
    float10 scaledZ = (float10)orientation->Z * nativeFloat2EPlus02;
    frame.orientationVector.Z = (float)scaledZ;
    frame.focalScratch.X = (float)(scaledX + this->Destination.X);
    x = reinterpret_cast<uint&>(frame.focalScratch.X);
    frame.focalScratch.Y = (float)(scaledY + this->Destination.Y);
    y = reinterpret_cast<uint&>(frame.focalScratch.Y);
    float10 focalZ = (float10)frame.orientationVector.Z + this->Destination.Z;
    uint* focal = (uint*)&this->FocalPoint;
    focal[0] = x;
    focal[1] = y;
    frame.focalScratch.Z = (float)focalZ;
    z = reinterpret_cast<uint&>(frame.focalScratch.Z);
    focal[2] = z;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8) &= ~0x40U; // bAdjusting.
    static_cast<AR6Pawn*>(this->Pawn)->AR6Pawn::moveToPosition(&this->Destination);
}

// R6Engine.dll @ 1000bd20 : AR6AIController::FollowPath
// Resumes or finds a cached route, starts latent movement, and dispatches pace through its incoming argument slot.
void __thiscall AR6AIController::FollowPath(eMovementPace pace, FName returnLabel, int continuePath)
{
    APawn* initialPawn = this->Pawn;
    if (initialPawn == nullptr)
        return;
    // Inferred NextLabel name; +0x464 store precedes continuePath.
    reinterpret_cast<uint&>(this->NextLabel) = reinterpret_cast<uint&>(returnLabel);
    auto routeAt = [&](uint indexWord) { // No lower-bound check; scaled addresses wrap at 32 bits.
        uint address = static_cast<uint>(reinterpret_cast<uintptr_t>(&this->RouteCache)) + indexWord * 4U;
        return *reinterpret_cast<AActor**>(static_cast<uintptr_t>(address));
    };
    if (continuePath == 0) {
        this->m_iCurrentRouteCache = -1;
    } else {
        uint index = (uint)this->m_iCurrentRouteCache;
        ANavigationPoint* anchor = initialPawn->Anchor;
        AActor* cached = routeAt(index);
        if (anchor != cached) {
            bool foundAnchor = false;
            index += 1U;
            this->m_iCurrentRouteCache = (int)index;
            if ((int)index <= 15) {
                do {
                    cached = routeAt(index); // Read even when the preceding iteration found the anchor.
                    if (cached == nullptr || foundAnchor)
                        break;
                    if (initialPawn->Anchor == cached)
                        foundAnchor = true;
                    index += 1U;
                    this->m_iCurrentRouteCache = (int)index;
                } while ((int)index <= 15);
            }
            cached = routeAt(index); // Unconditional post-loop read, before the upper-bound test.
            if (cached == nullptr || (int)index > 15) {
                if (foundAnchor)
                    return;
                AActor* goal = this->RouteGoal;
                const uint* zero = *(const uint**)&FVectorFVector0Import;
                struct FindPathPacketView { // Inferred outgoing packet at entryESP-0x20, consumed by FindPath.
                    FVector point;
                    AActor* goal;
                    int singlePath;
                } packet;
                packet.singlePath = 1;
                packet.goal = goal;
                uint x = zero[0];
                reinterpret_cast<uint&>(packet.point.X) = x;
                uint y = zero[1];
                uint z = zero[2];
                reinterpret_cast<uint&>(packet.point.Y) = y;
                reinterpret_cast<uint&>(packet.point.Z) = z;
                using FindPath = AActor* (__thiscall*)(AController*, FVector, AActor*, int);
                FindPath findPath = reinterpret_cast<FindPath&>(AControllerFindPathImport);
                AActor* path = findPath(this, packet.point, packet.goal, packet.singlePath);
                if (path == nullptr)
                    return;
                this->m_iCurrentRouteCache = 0;
            }
        }
    }
    APawn* pawn = this->Pawn;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x3e0) &= ~0x2000U; // bReducedSpeed.
    pawn = this->Pawn;
    uint speedWord = reinterpret_cast<uint&>(pawn->MaxDesiredSpeed);
    reinterpret_cast<uint&>(pawn->DesiredSpeed) = speedWord;
    (*reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0xc))->LatentAction = 0x25a;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8) &= ~0x40U; // bAdjusting.
    // Failure does not prevent event dispatch or the first movement call.
    this->AR6AIController::SetDestinationToNextInCache();
    byte health = this->Pawn->m_eHealth;
    uint selectedPace = (uint)pace; // Full incoming DWORD is sampled after health and cache callbacks.
    if (health == 1) {
        if (selectedPace == 3)
            selectedPace = 2;
        else if (selectedPace == 5)
            selectedPace = 4;
    }
    FName movementName = *(FName*)&R6ENGINE_R6SetMovement;
    byte* cachedVtable = *(byte**)this;
    // Reuse entryESP+4; upper three bytes remain current, not recopied.
    reinterpret_cast<byte&>(pace) = (byte)selectedPace;
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(movementName), 0);
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    (*(EventDispatcher*)(cachedVtable + 0x10))(this, function, &pace, nullptr);
    AActor* moveTarget = this->MoveTarget;
    pawn = this->Pawn;
    using MoveToward = int (__thiscall*)(APawn*, const FVector&, AActor*);
    MoveToward moveToward = *(MoveToward*)(*(byte**)pawn + 0x184);
    moveToward(pawn, this->Destination, moveTarget);
}

// R6Engine.dll @ 1000beb0 : AR6AIController::execPollFollowPath
// Polls adjustment or destination movement, updates the anchor, and advances the cached route when requested.
void __thiscall AR6AIController::execPollFollowPath(FFrame& unusedStack, void* unusedResult)
{
    // Native state-frame pointer slot; reload its value across callbacks.
    FStateFrame** stateFrameSlot = reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0xc);
    APawn* pawn = this->Pawn;
    // Ordered negative-timer test; NaNs continue polling. The constant is read only when Pawn is nonnull.
    if (pawn == nullptr || (float10)this->MoveTimer < (float10)nativeFloatZero) {
        (*stateFrameSlot)->LatentAction = 0;
        this->m_eMoveToResult = 2;
        return;
    }
    using MoveToward = int (__thiscall *)(APawn*, const FVector&, AActor*);
    uint* movementFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8);
    if ((reinterpret_cast<byte*>(movementFlags)[0] & 0x40U) != 0) { // Initial bAdjusting test reads only one byte.
        MoveToward moveToward = *(MoveToward*)(*(byte**)pawn + 0x184);
        int reached = moveToward(pawn, this->AdjustLoc, nullptr);
        uint flags = *movementFlags; // Full DWORD is sampled only after the callback.
        *movementFlags = (flags & ~0x40U) | (reached == 0 ? 0x40U : 0U);
        return; // Native returns even if this call just finished the adjustment leg.
    }
    AActor* moveTarget = this->MoveTarget;
    this->m_eMoveToResult = 0;
    MoveToward moveToward = *(MoveToward*)(*(byte**)pawn + 0x184);
    if (moveToward(pawn, this->Destination, moveTarget) == 0)
        return;
    if (this->m_eMoveToResult != 1) { // Read the result byte after the virtual call.
        (*stateFrameSlot)->LatentAction = 0;
        this->m_eMoveToResult = 2;
        return;
    }
    uint index = (uint)this->m_iCurrentRouteCache; // No bounds checks; address arithmetic wraps at 32 bits.
    uint cacheAddress = static_cast<uint>(reinterpret_cast<uintptr_t>(&this->RouteCache)) + index * 4U;
    AActor* cachedActor = *reinterpret_cast<AActor**>(static_cast<uintptr_t>(cacheAddress));
    if (cachedActor != nullptr) {
        UClass* actorClass = cachedActor->Class;
        // ANavigationPoint::PrivateStaticClass import.
        UClass* navigationPointClass = ANavigationPointPrivateStaticClassImport;
        while (actorClass != nullptr && actorClass != navigationPointClass)
            actorClass = actorClass->GetSuperClass();
        if (actorClass == navigationPointClass) { // Also accepts a null class import after an exhausted walk.
            ANavigationPoint* anchor = CastToANavigationPoint(cachedActor);
            this->Pawn->Anchor = anchor; // Reload Pawn after the cast, rather than reuse the first receiver.
        }
    }
    if (this->AR6AIController::SetDestinationToNextInCache() == 0) {
        (*stateFrameSlot)->LatentAction = 0;
        return; // This branch leaves m_eMoveToResult as set by the preceding movement callback.
    }
    moveTarget = this->MoveTarget;
    pawn = this->Pawn;
    moveToward = *(MoveToward*)(*(byte**)pawn + 0x184); // Reload both receiver and virtual target after callbacks.
    moveToward(pawn, this->Destination, moveTarget);
}

// R6Engine.dll @ 1000bff0 : AR6AIController::HearingCheck
// Traces from start to end with the controlled pawn as source and returns whether hit.Actor remains null.
int __thiscall AR6AIController::HearingCheck(FVector start, FVector end)
{
    uint guard[3]; // Native previous-SEH/handler/state view; the dispatcher also retains the parent ESP at EBP-0x10.
    guard[2] = 0xffffffff;
    guard[1] = ((uint)&HearingCheckExceptionHandler);
    guard[0] = (uint)ExceptionList;
    ExceptionList = &guard[0];
    // Captured before initialization and state0 activation.
    const uint* zeroWords = *(const uint**)&FVectorFVector0Import;
    NativeCheckResult32 hit;
    for (int i = 0; i != 9; ++i)
        reinterpret_cast<uint*>(&hit)[i] = 0;
    hit.materialAddress = 0;
    reinterpret_cast<uint&>(hit.Time) = 0x3f800000;
    reinterpret_cast<uint&>(hit.Item) = 0xffffffff;
    struct RawVector { uint x, y, z; } extent;
    extent.x = zeroWords[0];
    uint extentY = zeroWords[1];
    uint extentZ = zeroWords[2];
    extent.y = extentY;
    extent.z = extentZ;
    guard[2] = 0;
    void* level = reinterpret_cast<void*&>(this->XLevel);
    AActor* pawn = reinterpret_cast<AActor*&>(this->Pawn);
    byte* traceTable = *(byte**)level;
    using SingleLineCheck = int (__thiscall*)(void*, NativeCheckResult32*, AActor*, const FVector*, const FVector*,
        uint,
        RawVector);
    SingleLineCheck lineCheck = *(SingleLineCheck*)(traceTable + 0xcc);
    // Ignore provider EAX; vectors are live incoming slots.
    lineCheck(level, &hit, pawn, &end, &start, 0x40286, extent);
    uint hitActorWord = hit.actorAddress;
    ExceptionList = (void*)guard[0];
    return hitActorWord == 0; // Full EAX is normalized to zero or one.
}

// R6Engine.dll @ 1000c0a2 : HearingCheckCatchPointer
// Rethrows the caught text pointer through a temporary in the inherited HearingCheck frame.
__declspec(naked) __declspec(noreturn) void __cdecl HearingCheckCatchPointer(void)
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

// R6Engine.dll @ 1000c0b6 : HearingCheckCatchContext
// Reports HearingCheck context and rethrows the active exception from the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl HearingCheckCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerHearingCheck
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1000c0e0 : AR6AIController::CanHear
// Tests team and sound-zone gates, skill-scaled range, direct/muffled hearing and corner propagation.
int __thiscall AR6AIController::CanHear(FVector noiseLocation, float loudness, AActor* noiseActor,
    ENoiseType unusedNoiseType, EPawnType pawnType)
{
    struct SortedPathView { ANavigationPoint* nodes[32]; int scores[32]; int count; };
    struct NativeFrameView { // Descriptive EBP-relative storage; only the sorted-list count is initialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x180/-0x17c/-0x178.
        SortedPathView candidates; // EBP-0x174..-0x74; Engine addPath corroborates this storage view.
        NativeCheckResult32 hit; // EBP-0x70..-0x44.
        uint caught; // EBP-0x40.
        uint sourceZone, listenerRoot, sourceRoot; // EBP-0x3c/-0x38/-0x34.
        uint rethrow; // EBP-0x30.
        uint eyeContact[3]; // EBP-0x2c/-0x28/-0x24: eye output, then first trace contact.
        uint ear[3]; // EBP-0x20/-0x1c/-0x18.
        uint shared; // EBP-0x14: listener zone, distance, then current LevelInfo pointer.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerCanHearExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    // EBP+0x20: category, skill scratch, squared radius, then corner budget.
    uint& radiusOrType = reinterpret_cast<uint&>(pawnType);
    // EBP+0x14: loudness, scaled distance, current node and distance scratch.
    uint& scalarOrNode = reinterpret_cast<uint&>(loudness);
    // EBP+0x18 becomes the state FName only on the diagnostic exit.
    uint& actorOrName = reinterpret_cast<uint&>(noiseActor);
    AActor* source = noiseActor;
    APawn* instigator = source->Instigator; // Native does not guard the source actor.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    // Inline native sequence views; these lambdas do not identify additional native functions.
    auto zoneMask = [](ALevelInfo* info, uint from, uint to) {
        uint lowMask = 1U << (to & 31U);
        uint highMask = (lowMask & 0x80000000U) != 0 ? 0xffffffffU : 0;
        byte* row = reinterpret_cast<byte*>(info) + (0x650U + from * 8U);
        uint low = *(uint*)row & lowMask;
        uint high = *(uint*)(row + 4) & highMask;
        return low | high; // Both row words are read; the high mask is native CDQ sign extension.
    };
    auto squaredDistance = [](const FVector* first, const FVector* second) {
        float10 dz = (float10)first->Z - second->Z;
        float10 dy = (float10)first->Y - second->Y;
        float10 dx = (float10)first->X - second->X;
        float10 xSquared = dx * dx;
        float10 ySquared = dy * dy;
        float10 sum = xSquared + ySquared;
        float10 zSquared = dz * dz;
        return sum + zSquared;
    };
    auto rootBits = [](uint word) {
        uint difference = word - 0x3f800000U;
        return (uint)((int)difference >> 1) + 0x3f800000U; // Wrapping SUB/SAR/ADD, not a numeric conversion.
    };
    if (instigator == nullptr)
        return finish(0);
    AController* instigatorController = instigator->Controller;
    if (instigatorController == nullptr)
        return finish(0);
    APawn* pawn = this->Pawn;
    if (pawn == nullptr)
        return finish(0);
    if (radiusOrType != 4) {
        int listenerTeam = pawn->m_iTeam;
        int sourceTeam = instigator->m_iTeam;
        if (listenerTeam == sourceTeam)
            return finish(0);
    }
    AZoneInfo* zone = pawn->Region.Zone;
    uint listenerZone = zone->m_SoundZone;
    zone = source->Region.Zone;
    ULevel* level = this->XLevel;
    uint sourceZone = zone->m_SoundZone;
    frame.shared = listenerZone;
    ALevelInfo* info = level->ULevel::GetLevelInfo();
    listenerZone = frame.shared;
    if (sourceZone != listenerZone && zoneMask(info, sourceZone, listenerZone) == 0)
        return finish(0);
    if (radiusOrType == 0) {
        source = noiseActor;
        byte* state = *(byte**)((byte*)source + 0x0c);
        byte* node = state != nullptr ? *(byte**)(state + 0x1c) : nullptr;
        FName* stateName;
        if (node != nullptr) {
            actorOrName = *(uint*)(node + 0x20);
            stateName = (FName*)&actorOrName;
        } else {
            radiusOrType = 0;
            stateName = (FName*)&radiusOrType;
        }
        const ushort* stateText = stateName->operator*();
        const ushort* actorName = source->UObject::GetName();
        FOutputDevice** logSlot = *(FOutputDevice***)&CoreGLogImport;
        FOutputDevice* log = *logSlot;
        log->FOutputDevice::Logf(nativeTextWARNINGReceivedMakeNoiseWithoutApropriateTypeFromSInStateS,
            actorName,
            stateText);
        return finish(0);
    }
    pawn = this->Pawn;
    float10 distance = squaredDistance(&pawn->Location, &noiseLocation);
    reinterpret_cast<float&>(frame.shared) = (float)distance;
    using GetSkill = float10 (__thiscall*)(AR6AbstractPawn*, byte); // Views the native unspilled ST(0) result.
    float10 skill = reinterpret_cast<GetSkill&>(AR6AbstractPawnEventGetSkillImport)(
        static_cast<AR6AbstractPawn*>(pawn), 7);
    reinterpret_cast<float&>(radiusOrType) = (float)skill; // FST scratch leaves the live skill result on ST(0).
    float10 radius = skill * nativeFloatHalf;
    radius += nativeFloat0Point75;
    radius *= reinterpret_cast<float&>(scalarOrNode);
    reinterpret_cast<float&>(radiusOrType) = (float)(radius * radius);
    float10 currentRadius = reinterpret_cast<float&>(radiusOrType);
    float10 currentDistance = reinterpret_cast<float&>(frame.shared);
    if (currentRadius < currentDistance)
        return finish(0); // Equal or unordered comparisons continue.
    pawn = this->Pawn;
    uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x3e4);
    if ((flags & 0x60U) != 0) {
        source = noiseActor;
        AZoneInfo* ownZone = this->Region.Zone;
        AZoneInfo* otherZone = source->Region.Zone;
        if (ownZone == otherZone)
            return finish(1);
    }
    if ((flags & 0x40U) != 0) {
        source = noiseActor;
        uint sourceNumber = source->Region.ZoneNumber;
        uint listenerNumber = pawn->Region.ZoneNumber;
        level = this->XLevel;
        byte* model = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(level) + 0x90);
        uint word = *(uint*)(model + 0x128 + ((sourceNumber >> 5) + listenerNumber * 18U) * 4U);
        if ((word & (1U << (sourceNumber & 31U))) != 0)
            return finish(1);
    }
    if ((reinterpret_cast<byte*>(pawn)[0x3e4] & 0x10U) == 0)
        return finish(0);
    using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
    FVector* eye = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(pawn, (FVector*)frame.eyeContact);
    float10 earZ = eye->Z;
    pawn = this->Pawn;
    earZ += pawn->Location.Z;
    float10 earY = (float10)eye->Y + pawn->Location.Y;
    float10 earX = (float10)pawn->Location.X + eye->X;
    reinterpret_cast<float&>(frame.ear[0]) = (float)earX;
    uint ex = frame.ear[0];
    reinterpret_cast<float&>(frame.ear[1]) = (float)earY;
    uint ey = frame.ear[1];
    reinterpret_cast<float&>(frame.ear[2]) = (float)earZ;
    uint ez = frame.ear[2];
    uint nx = reinterpret_cast<uint&>(noiseLocation.X);
    uint ny = reinterpret_cast<uint&>(noiseLocation.Y);
    uint nz = reinterpret_cast<uint&>(noiseLocation.Z);
    using Hear = int (__thiscall*)(AR6AIController*, uint, uint, uint, uint, uint, uint);
    if (((Hear)&AR6AIControllerHearingCheckNativeEntry)(this, nx, ny, nz, ex, ey, ez) != 0)
        return finish(1);
    pawn = this->Pawn;
    byte lowFlags = reinterpret_cast<byte*>(pawn)[0x3e4];
    using Trace = int (__thiscall*)(ULevel*, uint*, AActor*, const FVector*, const FVector*, uint, uint, uint, uint);
    if ((lowFlags & 0x80U) != 0) {
        float10 liveScaled = (float10)reinterpret_cast<float&>(frame.shared) * nativeFloat4;
        reinterpret_cast<float&>(scalarOrNode) = (float)liveScaled;
        currentRadius = reinterpret_cast<float&>(radiusOrType);
        float10 scaled = reinterpret_cast<float&>(scalarOrNode);
        if (currentRadius > scaled) {
            InitializeCheckResult(reinterpret_cast<FCheckResult*>(&frame.hit), 1.0f, nullptr);
            uint* zero = *(uint**)&FVectorFVector0Import;
            uint zx = zero[0];
            level = this->XLevel;
            byte* vtable = *reinterpret_cast<byte**>(level);
            uint zy = zero[1];
            uint zz = zero[2];
            (*reinterpret_cast<Trace*>(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), this, &noiseLocation,
                (const FVector*)frame.ear, 4, zx, zy, zz);
            uint contactZ = reinterpret_cast<uint&>(frame.hit.Location.Z);
            uint contactY = reinterpret_cast<uint&>(frame.hit.Location.Y);
            uint contactX = reinterpret_cast<uint&>(frame.hit.Location.X);
            frame.eyeContact[2] = contactZ;
            zero = *(uint**)&FVectorFVector0Import;
            zx = zero[0];
            zy = zero[1];
            zz = zero[2];
            frame.eyeContact[1] = contactY;
            level = this->XLevel;
            frame.eyeContact[0] = contactX;
            vtable = *reinterpret_cast<byte**>(level);
            (*reinterpret_cast<Trace*>(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), this,
                (const FVector*)frame.ear,
                &noiseLocation, 4, zx, zy, zz);
            float10 separation = squaredDistance((const FVector*)frame.eyeContact,
                reinterpret_cast<const FVector*>(&frame.hit.Location));
            float10 total = separation * separation;
            // Native fourth power of contact separation is intentional.
            total += reinterpret_cast<float&>(scalarOrNode);
            currentRadius = reinterpret_cast<float&>(radiusOrType);
            if (currentRadius > total)
                return finish(1);
        }
    }
    pawn = this->Pawn;
    flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x3e4);
    if ((flags & 0x100U) == 0)
        return finish(0);
    currentRadius = reinterpret_cast<float&>(radiusOrType);
    frame.candidates.count = 0;
    float10 budget = currentRadius * nativeFloat0Point75;
    reinterpret_cast<float&>(scalarOrNode) = (float)budget;
    frame.shared = rootBits(scalarOrNode);
    radiusOrType = frame.shared;
    level = this->XLevel;
    info = level->ULevel::GetLevelInfo();
    ALevelInfo* levelInfo = this->Level;
    ANavigationPoint* node = levelInfo->NavigationPointList;
    frame.shared = (uint)info;
    for (;;) {
        scalarOrNode = (uint)node;
        if (node == nullptr)
            break;
        if ((reinterpret_cast<byte*>(node)[0x3a4] & 4U) != 0) {
            zone = node->Region.Zone;
            source = noiseActor;
            uint nodeZone = zone->m_SoundZone;
            zone = source->Region.Zone;
            uint sourceZone = zone->m_SoundZone;
            frame.sourceZone = sourceZone;
            bool allowed = true;
            if (sourceZone != nodeZone) {
                info = reinterpret_cast<ALevelInfo*>(frame.shared);
                sourceZone = frame.sourceZone;
                uint mask = zoneMask(info, sourceZone, nodeZone);
                node = reinterpret_cast<ANavigationPoint*>(scalarOrNode);
                allowed = mask != 0;
                if (allowed)
                    source = noiseActor;
            }
            if (allowed) {
                pawn = this->Pawn;
                zone = pawn->Region.Zone;
                listenerZone = zone->m_SoundZone;
                if (nodeZone != listenerZone) {
                    info = reinterpret_cast<ALevelInfo*>(frame.shared);
                    allowed = zoneMask(info, nodeZone, listenerZone) != 0;
                    if (allowed)
                        source = noiseActor;
                }
                if (allowed) {
                    float10 toListener = squaredDistance(&node->Location, &this->Location);
                    reinterpret_cast<float&>(scalarOrNode) = (float)toListener;
                    frame.listenerRoot = rootBits(scalarOrNode);
                    float10 toSource = squaredDistance(&node->Location, &source->Location);
                    reinterpret_cast<float&>(scalarOrNode) = (float)toSource;
                    frame.sourceRoot = rootBits(scalarOrNode);
                    float10 total = (float10)reinterpret_cast<float&>(frame.sourceRoot) +
                        reinterpret_cast<float&>(frame.listenerRoot);
                    if (total < (float10)reinterpret_cast<float&>(radiusOrType)) {
                        int score;
                        // Actual conversion consumes the extended sum already on ST(0).
                        __asm {
                            call TruncateX87ToSigned64
                            mov score,eax
                        }
                        reinterpret_cast<FSortedPathList*>(&frame.candidates)->FSortedPathList::addPath(node, score);
                    }
                }
            }
        }
        node = node->nextNavigationPoint;
    }
    for (uint index = 0; (int)index < frame.candidates.count; ++index) {
        nx = reinterpret_cast<uint&>(noiseLocation.X);
        ny = reinterpret_cast<uint&>(noiseLocation.Y);
        nz = reinterpret_cast<uint&>(noiseLocation.Z);
        ANavigationPoint* candidate = frame.candidates.nodes[index];
        uint x = reinterpret_cast<uint&>(candidate->Location.X);
        uint y = reinterpret_cast<uint&>(candidate->Location.Y);
        uint z = reinterpret_cast<uint&>(candidate->Location.Z);
        if (((Hear)&AR6AIControllerHearingCheckNativeEntry)(this, x, y, z, nx, ny, nz) != 0) {
            ex = frame.ear[0];
            ey = frame.ear[1];
            ez = frame.ear[2];
            candidate = frame.candidates.nodes[index];
            x = reinterpret_cast<uint&>(candidate->Location.X);
            y = reinterpret_cast<uint&>(candidate->Location.Y);
            z = reinterpret_cast<uint&>(candidate->Location.Z);
            if (((Hear)&AR6AIControllerHearingCheckNativeEntry)(this, x, y, z, ex, ey, ez) != 0)
                return finish(1);
        }
    }
    return finish(0);
}

// R6Engine.dll @ 1000c6de : throw the caught CanHear exception value through its parent frame
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void CanHearCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x40]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x30]
        push eax
        mov dword ptr [ebp-0x30],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1000c6f2 : report CanHear context and forward the active exception
// Reports the native context through the current import before null-word rethrow.
__declspec(naked) void CanHearCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerCanHear
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043480 : AIControllerCanHearExceptionHandler
// Forwards the hearing guard's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerCanHearExceptionHandler(void)
{
    __asm {
        mov eax,offset canHearFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000c710 : AR6AIController::CanWalkTo
// Traces down to a contact, then tests pawn-sized clearance to its elevated position.
int __thiscall AR6AIController::CanWalkTo(FVector target, int unusedDebugFlag)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; target remains the incoming argument slot.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x6c/-0x68/-0x64.
        NativeCheckResult32 hit; // EBP-0x60..-0x34.
        uint loweredOrExtent[3]; // EBP-0x30/-0x2c/-0x28, reused after the first trace.
        uint pawnLocation[3]; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerCanWalkToExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.savedEsp = &frame.savedEdi;
    float10 loweredZ = (float10)target.Z - nativeFloat2EPlus02;
    float10 targetY = target.Y;
    reinterpret_cast<float&>(frame.loweredOrExtent[1]) = (float)targetY;
    frame.hit.nextAddress = 0;
    frame.hit.actorAddress = 0;
    reinterpret_cast<float&>(frame.loweredOrExtent[2]) = (float)loweredZ;
    reinterpret_cast<uint&>(frame.hit.Location.X) = 0;
    reinterpret_cast<uint&>(frame.hit.Location.Y) = 0;
    reinterpret_cast<uint&>(frame.hit.Location.Z) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.X) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.Y) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.Z) = 0;
    frame.hit.primitiveAddress = 0;
    frame.hit.materialAddress = 0;
    frame.state = 0;
    frame.loweredOrExtent[0] = reinterpret_cast<uint&>(target.X);
    uint* zeroExtent = *(uint**)&FVectorFVector0Import;
    reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000U;
    reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffffU;
    uint extentX = zeroExtent[0];
    uint extentY = zeroExtent[1];
    uint extentZ = zeroExtent[2];
    ULevel* level = this->XLevel;
    byte* vtable = *(byte**)level;
    using SingleLineCheck = int (__thiscall *)(ULevel*, uint*, AActor*, const FVector*, const FVector*,
        uint, uint, uint, uint); // Raw by-value FVector extent words.
    (*(SingleLineCheck*)(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), this,
        (FVector*)frame.loweredOrExtent, &target, 0x86U, extentX, extentY, extentZ);
    float10 zero = nativeFloatZero;
    float10 time = frame.hit.Time;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (time == zero) // Ordered equality only: signed zero rejects, unordered continues.
        return finish(0);
    uint contactX = reinterpret_cast<uint&>(frame.hit.Location.X);
    uint contactY = reinterpret_cast<uint&>(frame.hit.Location.Y);
    uint contactZ = reinterpret_cast<uint&>(frame.hit.Location.Z);
    reinterpret_cast<uint&>(target.X) = contactX;
    APawn* locationPawn = this->Pawn;
    reinterpret_cast<uint&>(target.Z) = contactZ;
    reinterpret_cast<uint&>(target.Y) = contactY;
    frame.pawnLocation[0] = reinterpret_cast<uint&>(locationPawn->Location.X);
    frame.pawnLocation[1] = reinterpret_cast<uint&>(locationPawn->Location.Y);
    APawn* pawn = this->Pawn;
    frame.pawnLocation[2] = reinterpret_cast<uint&>(locationPawn->Location.Z);
    float10 height = pawn->CollisionHeight;
    float10 radius = pawn->CollisionRadius;
    uint rawRadius = reinterpret_cast<uint&>(pawn->CollisionRadius);
    reinterpret_cast<float&>(frame.loweredOrExtent[1]) = (float)radius;
    frame.loweredOrExtent[0] = rawRadius;
    reinterpret_cast<float&>(frame.loweredOrExtent[2]) = (float)height;
    float10 raisedZ = (float10)target.Z + pawn->CollisionHeight;
    raisedZ += nativeFloat2Point4;
    target.Z = (float)raisedZ;
    uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(pawn) + 0x3e0);
    if ((flags & 0x200U) == 0) { // Matching 1.60 Pawn.m_bIsProne.
        reinterpret_cast<float&>(frame.pawnLocation[2]) =
            (float)((float10)reinterpret_cast<float&>(frame.pawnLocation[2]) + nativeDouble33);
        target.Z = (float)((float10)target.Z + nativeDouble33);
    }
    float10 verticalDifference = (float10)target.Z - reinterpret_cast<float&>(frame.pawnLocation[2]);
    if (!(verticalDifference >= nativeFloatZero)) // Native C0 includes unordered in the sign inversion.
        verticalDifference = -verticalDifference;
    if (verticalDifference >= nativeDouble33) // C0-only rejection lets unordered continue.
        return finish(0);
    extentX = frame.loweredOrExtent[0];
    level = this->XLevel;
    vtable = *(byte**)level;
    extentY = frame.loweredOrExtent[1];
    extentZ = frame.loweredOrExtent[2];
    int clear = (*(SingleLineCheck*)(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), this,
        &target, (FVector*)frame.pawnLocation, 0x296U, extentX, extentY, extentZ);
    return finish(clear); // Preserve the entire delegated EAX; native RET 0x10 ignores the debug word.
}

// R6Engine.dll @ 1000c8d1 : CanWalkToCatchPointer
// Rethrows the caught word through the parent's separate rethrow slot.
__declspec(naked) void CanWalkToCatchPointer(void)
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

// R6Engine.dll @ 1000c8e5 : CanWalkToCatchContext
// Reports walk-clearance context before forwarding the current exception.
__declspec(naked) void CanWalkToCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerCanWalkTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor eax,eax
        push eax
        push eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043490 : AIControllerCanWalkToExceptionHandler
// Forwards the walk-clearance guard's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerCanWalkToExceptionHandler(void)
{
    __asm {
        mov eax,offset canWalkToFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000c910 : AR6AIController::execFindGrenadeDirectionToHitActor
// Computes ballistic pitch and direction from current target, hand geometry, gravity and launch speed.
// Native ABI view retains the incoming frame word for the grenade-speed operand.
void __thiscall AR6AIController::execFindGrenadeDirectionToHitActor(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive stack storage, including the temporary by-value FName below saved registers.
        uint handName; // EBP-0xa0, reserved only during name construction and consumed by MatchRefBone.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x9c/-0x98/-0x94.
        FCoords boneStorage; // EBP-0x90..-0x61.
        FVector targetPosition; // EBP-0x60/-0x5c/-0x58; evaluator output remains initially uninitialized.
        FRotator rotation; // EBP-0x54/-0x50/-0x4c.
        FVector delta; // EBP-0x48/-0x44/-0x40.
        uint caught, rethrow; // EBP-0x3c/-0x38.
        uint originX; // EBP-0x34.
        uint sharedDoubleLow, sharedZ; // EBP-0x30/-0x2c: originY/Z, then double sqrt and scaled distance/pitch.
        float gravity; // EBP-0x28.
        uint trigLow, trigHigh; // EBP-0x24/-0x20: double scratch, initially scaled horizontal at -0x20.
        float sizeOrCosine; // EBP-0x1c.
        AActor* target; // EBP-0x18.
        float heightOrAngle; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerGrenadeDirectionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    frame.target = nullptr;
    byte opcode = *code;
    *cursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    natives[opcode](receiver, vmFrame, &frame.target);
    code = *cursor;
    opcode = *code;
    receiver = vmFrame->Object;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &frame.targetPosition);
    code = *cursor;
    receiver = vmFrame->Object;
    uint& speedSlot = reinterpret_cast<uint&>(stack); // EBP+8: the incoming FFrame word is reused as a float output.
    speedSlot = 0;
    opcode = *code;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &speedSlot);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    AActor* target = frame.target;
    FVector* position = target != nullptr ? &target->Location : &frame.targetPosition;
    float10 dz = position->Z;
    APawn* pawn = this->Pawn;
    dz -= pawn->Location.Z;
    float10 dy = (float10)position->Y - pawn->Location.Y;
    float10 dx = (float10)position->X - pawn->Location.X;
    frame.delta.X = (float)dx;
    frame.delta.Y = (float)dy;
    frame.delta.Z = (float)dz; // FST preserves the live Z difference for the following subtraction.
    float10 targetHeight = target != nullptr ? target->CollisionHeight : nativeFloatZero;
    frame.handName = (uint)position; // Native PUSH ECX reserves the name word without zero initialization.
    dz -= targetHeight;
    frame.sharedZ = (uint)&frame.handName;
    frame.delta.Z = (float)dz;
    // L"R6 R Hand".
    ::new (reinterpret_cast<void*>(&frame.handName)) FName(nativeTextR6RHand, static_cast<EFindName>(1));
    pawn = this->Pawn;
    USkeletalMeshInstance* mesh = reinterpret_cast<USkeletalMeshInstance*>(pawn->MeshInstance);
    int bone = mesh->USkeletalMeshInstance::MatchRefBone(reinterpret_cast<FName&>(frame.handName));
    if (bone >= 0) {
        pawn = this->Pawn;
        mesh = reinterpret_cast<USkeletalMeshInstance*>(pawn->MeshInstance);
        // Physical result view keeps the supplied buffer and returned pointer.
        FCoords* coordinates = mesh->USkeletalMeshInstance::GetBoneCoords(
            &frame.boneStorage, (uint)bone, 0);
        uint originX = reinterpret_cast<uint&>(coordinates->Origin.X);
        uint originY = reinterpret_cast<uint&>(coordinates->Origin.Y);
        uint originZ = reinterpret_cast<uint&>(coordinates->Origin.Z);
        frame.originX = originX;
        pawn = this->Pawn;
        frame.sharedZ = originZ;
        float10 handHeight = (float10)reinterpret_cast<float&>(frame.sharedZ) - pawn->Location.Z;
        frame.sharedDoubleLow = originY;
        frame.delta.Z = (float)((float10)frame.delta.Z - handHeight);
    }
    float10 ySquared = frame.delta.Y;
    uint rawHeight = reinterpret_cast<uint&>(frame.delta.Z);
    ySquared *= frame.delta.Y;
    float10 xSquared = frame.delta.X;
    reinterpret_cast<uint&>(frame.heightOrAngle) = rawHeight;
    xSquared *= frame.delta.X;
    double horizontalSquared = (double)(ySquared + xSquared);
    using MathCall = float10 (__cdecl *)(double); // Observed ST(0) values may retain more than the stored copy.
    float10 horizontal = reinterpret_cast<MathCall&>(CoreAppSqrtImport)(horizontalSquared);
    *(double*)&frame.sharedDoubleLow = (double)horizontal; // Unused FST copy does not replace live ST(0).
    horizontal *= nativeDouble0Point75;
    reinterpret_cast<float&>(frame.trigHigh) = (float)horizontal;
    using VectorSize = float10 (__thiscall *)(const FVector*);
    float10 distance = reinterpret_cast<VectorSize&>(FVectorSizeImport)(&frame.delta);
    APhysicsVolume* volume = this->PhysicsVolume;
    frame.sizeOrCosine = (float)distance;
    reinterpret_cast<float&>(frame.sharedZ) = (float)(distance * nativeDouble0Point75);
    frame.gravity = (float)(-(float10)volume->Gravity.Z * nativeDouble0Point5);
    double ratio = (double)((float10)frame.heightOrAngle / reinterpret_cast<float&>(frame.trigHigh));
    float10 angle = reinterpret_cast<MathCall&>(CoreAppAtanImport)(ratio);
    *(double*)&frame.trigLow = (double)angle;
    frame.heightOrAngle = (float)angle;
    float10 cosine = reinterpret_cast<MathCall&>(CoreAppCosImport)((double)angle);
    *(double*)&frame.trigLow = (double)cosine;
    frame.sizeOrCosine = (float)cosine;
    *(double*)&frame.trigLow = appSin((double)frame.heightOrAngle);
    float10 numerator = frame.sizeOrCosine;
    numerator *= frame.sizeOrCosine;
    numerator *= frame.gravity;
    numerator *= reinterpret_cast<float&>(frame.sharedZ);
    float10 speed = reinterpret_cast<float&>(speedSlot);
    speed *= reinterpret_cast<float&>(speedSlot);
    float10 correction = numerator / speed;
    correction += *(double*)&frame.trigLow;
    // FST copy is overwritten after the live intrinsic call.
    reinterpret_cast<float&>(frame.sharedZ) = (float)correction;
    float10 arcSine;
    __asm {
        fld correction
        call _CIasin
        fstp arcSine
    }
    arcSine += frame.heightOrAngle;
    reinterpret_cast<float&>(frame.sharedZ) = (float)(arcSine * nativeFloatHalf);
    // Returned EAX is ignored.
    frame.rotation = frame.delta.Rotation();
    float10 units = reinterpret_cast<float&>(frame.sharedZ);
    units *= nativeFloat32767;
    units *= nativeDouble0Point3183098861837907;
    uint pitch;
    __asm {
        fld units
        call TruncateX87ToSigned64
        mov pitch,eax
    }
    uint* output = (uint*)result; // Current EBP+0xc is sampled only after the conversion.
    uint roll = reinterpret_cast<uint&>(frame.rotation.Roll);
    output[0] = pitch;
    uint yaw = reinterpret_cast<uint&>(frame.rotation.Yaw);
    output[1] = yaw;
    output[2] = roll;
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1000cb8d : GrenadeDirectionCatchPointer
// Rethrows the caught word through separate storage in the inherited grenade-direction frame.
__declspec(naked) void GrenadeDirectionCatchPointer(void)
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

// R6Engine.dll @ 1000cba1 : GrenadeDirectionCatchContext
// Reports grenade-direction context before forwarding the active exception.
__declspec(naked) void GrenadeDirectionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecFindGrenadeDirectionToHitActor
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100434a0 : AIControllerGrenadeDirectionExceptionHandler
// Forwards the grenade-direction frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerGrenadeDirectionExceptionHandler(void)
{
    __asm {
        mov eax,offset grenadeDirectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000cbc0 : AR6AIController::GotoOpenDoorState
// Registers a potential door, reports rejection, or saves the previous state and enters OpenDoor.
void __thiscall AR6AIController::GotoOpenDoorState(AActor* doorActor)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; event parameters share the two high local words.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x2c/-0x28/-0x24.
        uint caught, rethrow; // EBP-0x20/-0x1c.
        AR6IORotatingDoor* rotatingDoor; // EBP-0x18, CanOpenDoor's first parameter.
        uint potentialOrReturn; // EBP-0x14, PotentialOpenDoor argument then CanOpenDoor's Bool output.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerOpenDoorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* originalDoor = doorActor;
    UClass* type = originalDoor->Class; // Native assumes a nonnull actor, before state zero.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    while (type != nullptr && type != &AR6Door::PrivateStaticClass)
        type = type->GetSuperClass();
    if (type == nullptr)
        appFailAssert("navPointToOpenFrom->IsA( AR6Door::StaticClass() )", ".\\Src\\AR6AIController.cpp", 0x4a1);
    using FindFunctionChecked = UFunction* (__thiscall *)(UObject*, uint, int);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    AR6Pawn* pawn = this->m_r6pawn;
    uint name = reinterpret_cast<uint&>(R6ENGINE_PotentialOpenDoor); // PotentialOpenDoor.
    frame.potentialOrReturn = (uint)originalDoor;
    FindFunctionChecked findFunction = reinterpret_cast<FindFunctionChecked&>(UObjectFindFunctionCheckedImport);
    UFunction* function = findFunction(pawn, name, 0);
    byte* vtable = *(byte**)pawn;
    (*(ProcessEvent*)(vtable + 0x10))(pawn, function, &frame.potentialOrReturn, nullptr);
    pawn = this->m_r6pawn;
    AR6Door* currentDoor = pawn->m_Door;
    if (currentDoor != nullptr) {
        frame.rotatingDoor = currentDoor->m_RotatingDoor;
        name = reinterpret_cast<uint&>(R6ENGINE_CanOpenDoor); // CanOpenDoor.
        frame.potentialOrReturn = 0;
        function = findFunction(this, name, 0);
        vtable = *(byte**)this;
        (*(ProcessEvent*)(vtable + 0x10))(this, function, &frame.rotatingDoor, nullptr);
        if (frame.potentialOrReturn == 0) {
            pawn = this->m_r6pawn;
            name = reinterpret_cast<uint&>(R6ENGINE_RemovePotentialOpenDoor); // RemovePotentialOpenDoor.
            // Current incoming slot, independent of PotentialOpenDoor's buffer.
            uint removalDoor = reinterpret_cast<uint&>(doorActor);
            reinterpret_cast<uint&>(doorActor) = removalDoor;
            function = findFunction(pawn, name, 0);
            vtable = *(byte**)pawn;
            (*(ProcessEvent*)(vtable + 0x10))(pawn, function, &doorActor, nullptr);
            name = reinterpret_cast<uint&>(R6ENGINE_OpenDoorFailed); // OpenDoorFailed.
            function = findFunction(this, name, 0);
            vtable = *(byte**)this;
            (*(ProcessEvent*)(vtable + 0x10))(this, function, nullptr, nullptr);
            ExceptionList = frame.previousExceptionList;
            return;
        }
    }
    byte* stateFrame = *(byte**)((byte*)this + 0xc);
    byte* stateNode = stateFrame != nullptr ? *(byte**)(stateFrame + 0x1c) : nullptr;
    uint previousState = stateNode != nullptr ? *(uint*)(stateNode + 0x20) : 0;
    // EBP+8 is now the saved-state and both FName constructor outputs.
    uint& stateSlot = reinterpret_cast<uint&>(doorActor);
    stateSlot = previousState;
    using ConstructName = FName* (__thiscall *)(FName*, const ushort*, int);
    ConstructName constructName = reinterpret_cast<ConstructName&>(FNameConstructorImport);
    previousState = stateSlot;
    // L"OpenDoor".
    FName* constructed = constructName((FName*)&stateSlot, nativeTextOpenDoor, 1);
    if (previousState != *(uint*)constructed)
        *(uint*)&this->m_openDoorNextState = previousState;
    this->m_closeDoor = nullptr;
    constructed = constructName((FName*)&stateSlot, nativeTextOpenDoor, 1);
    uint destination = *(uint*)constructed;
    vtable = *(byte**)this;
    using GotoState = int (__thiscall *)(UObject*, uint); // Observed FName word; native EGotoState result is ignored.
    (*(GotoState*)(vtable + 0x34))(this, destination);
    vtable = *(byte**)this;
    using GotoLabel = int (__thiscall *)(UObject*, uint);
    (*(GotoLabel*)(vtable + 0x38))(this, 100); // Native name index; UE2's Begin spelling is supplementary.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1000cd48 : OpenDoorCatchPointer
// Rethrows the caught word through separate storage in the inherited open-door frame.
__declspec(naked) void OpenDoorCatchPointer(void)
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

// R6Engine.dll @ 1000cd5c : OpenDoorCatchContext
// Reports open-door transition context before forwarding the current exception.
__declspec(naked) void OpenDoorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerGotoOpenDoorState
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100434b0 : AIControllerOpenDoorExceptionHandler
// Forwards the open-door frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerOpenDoorExceptionHandler(void)
{
    __asm {
        mov eax,offset openDoorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000cd80 : AR6AIController::execFindNearbyWaitSpot
// Tries forward and side clearance with ground support, falling back to the farthest blocked contact.
// Native ABI view retains the incoming frame word for the selected output-buffer address.
void __thiscall AR6AIController::execFindNearbyWaitSpot(FFrame* stack, void* unusedResult)
{
    // Descriptive EBP-relative storage; scratch vectors overlap rotation/extent/difference roles.
    struct NativeFrameView {
        uint savedEdi, savedEsi, savedEbx; // EBP-0xa8/-0xa4/-0xa0.
        uint temporaryOutput[3]; // EBP-0x9c/-0x98/-0x94; initially uninitialized.
        uint caught, rethrow; // EBP-0x90/-0x8c.
        FVector direction; // EBP-0x88/-0x84/-0x80.
        NativeCheckResult32 hit; // EBP-0x7c..-0x50.
        float bestDistance; // EBP-0x4c.
        uint best[3]; // EBP-0x48/-0x44/-0x40, also initial output-zero storage.
        AActor* node; // EBP-0x3c.
        uint start[3]; // EBP-0x38/-0x34/-0x30.
        uint candidate[3]; // EBP-0x2c/-0x28/-0x24.
        float productOrSize; // EBP-0x20.
        uint scratch[3]; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerWaitSpotExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    frame.node = nullptr;
    byte opcode = *code;
    *cursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    natives[opcode](receiver, vmFrame, &frame.node);
    **(uint**)&CoreGPropAddrImport = 0; // Current GPropAddr pointee.
    code = *cursor;
    opcode = *code;
    receiver = vmFrame->Object;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, frame.temporaryOutput);
    UObject* propertyOwner = *reinterpret_cast<UObject**&>(CoreGPropObjectImport);
    if (propertyOwner != nullptr) {
        UProperty* property = *reinterpret_cast<UProperty**&>(CoreGPropertyImport);
        byte* ownerTable = *(byte**)propertyOwner;
        using PropertyNotification = void (__thiscall *)(UObject*, UProperty*);
        (*(PropertyNotification*)(ownerTable + 0x60))(propertyOwner, property);
    }
    uint selectedOutput = **(uint**)&CoreGPropAddrImport;
    // EBP+8 reuses the incoming FFrame word; retained vmFrame stays independent.
    uint& outputSlot = reinterpret_cast<uint&>(stack);
    outputSlot = selectedOutput != 0 ? selectedOutput : (uint)frame.temporaryOutput;
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    uint* output = (uint*)outputSlot;
    frame.best[0] = 0;
    output[0] = frame.best[0];
    frame.best[1] = 0;
    uint zeroY = frame.best[1];
    frame.best[2] = 0;
    uint zeroZ = frame.best[2];
    output[1] = zeroY;
    output[2] = zeroZ;
    AActor* node = frame.node;
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (node == nullptr) {
        finish();
        return;
    }
    AR6Pawn* r6pawn = this->m_r6pawn;
    frame.candidate[2] = 0;
    frame.candidate[1] = 0;
    frame.candidate[0] = 0;
    frame.hit.nextAddress = 0;
    frame.hit.actorAddress = 0;
    reinterpret_cast<uint&>(frame.hit.Location.X) = 0;
    reinterpret_cast<uint&>(frame.hit.Location.Y) = 0;
    reinterpret_cast<uint&>(frame.hit.Location.Z) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.X) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.Y) = 0;
    reinterpret_cast<uint&>(frame.hit.Normal.Z) = 0;
    frame.hit.primitiveAddress = 0;
    reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000U;
    reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffffU;
    frame.hit.materialAddress = 0;
    frame.start[2] = 0;
    frame.start[1] = 0;
    frame.start[0] = 0;
    AR6Ladder* ladder = r6pawn->m_Ladder;
    frame.best[2] = 0;
    frame.best[1] = 0;
    frame.best[0] = 0;
    frame.bestDistance = 0.0f;
    bool positive = ladder == node && (*reinterpret_cast<byte*>(reinterpret_cast<byte*>(node) + 0x3f0) & 1U) != 0;
    using LiveVectorSize = float10 (__thiscall *)(const FVector*);
    using SingleLineCheck = int (__thiscall *)(ULevel*, uint*, AActor*, const FVector*, const FVector*,
        uint, uint, uint, uint); // Raw by-value extent words; all trace returns are ignored.
    // Inline sequence views, not additional recovered native functions.
    auto offsetFromNode = [&](FVector* direction, const float* scale, uint* destination) {
        float10 z = (float10)direction->Z * *scale;
        float10 y = (float10)direction->Y * *scale;
        frame.productOrSize = (float)y;
        float10 x = direction->X;
        AActor* currentNode = frame.node;
        x *= *scale;
        reinterpret_cast<float&>(frame.scratch[0]) = (float)x;
        z = positive ? z + currentNode->Location.Z : (float10)currentNode->Location.Z - z;
        y = positive ? (float10)frame.productOrSize + currentNode->Location.Y :
            (float10)currentNode->Location.Y - frame.productOrSize;
        x = positive ? (float10)reinterpret_cast<float&>(frame.scratch[0]) + currentNode->Location.X :
            (float10)currentNode->Location.X - reinterpret_cast<float&>(frame.scratch[0]);
        reinterpret_cast<float&>(frame.scratch[0]) = (float)x;
        destination[0] = frame.scratch[0];
        reinterpret_cast<float&>(frame.scratch[1]) = (float)y;
        destination[1] = frame.scratch[1];
        reinterpret_cast<float&>(frame.scratch[2]) = (float)z;
        destination[2] = frame.scratch[2];
        return currentNode; // Native keeps this sampled node through the second Rotation::Vector call setup.
    };
    FVector* direction = &(frame.direction = node->Rotation.Vector());
    node = offsetFromNode(direction, &nativeFloat1EPlus02, frame.start);
    direction = &(frame.direction = node->Rotation.Vector());
    offsetFromNode(direction, &nativeFloat5EPlus02, frame.candidate);
    uint extentX, extentY, extentZ;
    auto prepareExtent = [&]() {
        frame.scratch[0] = 0x42200000U;
        extentX = frame.scratch[0];
        frame.scratch[1] = 0x42200000U;
        extentY = frame.scratch[1];
        frame.scratch[2] = 0x42700000U;
        extentZ = frame.scratch[2];
    };
    APawn* pawn = this->Pawn;
    uint pawnZ = reinterpret_cast<uint&>(pawn->Location.Z);
    ULevel* level = this->XLevel;
    frame.start[2] = pawnZ;
    frame.candidate[2] = reinterpret_cast<uint&>(pawn->Location.Z);
    byte* vtable = *(byte**)level;
    prepareExtent();
    (*(SingleLineCheck*)(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), this,
        (FVector*)frame.candidate, (FVector*)frame.start, 0x86U, extentX, extentY, extentZ);
    auto sideProbe = [&](uint index) {
        AActor* currentNode = frame.node;
        uint roll = reinterpret_cast<uint&>(currentNode->Rotation.Roll);
        uint yaw = reinterpret_cast<uint&>(currentNode->Rotation.Yaw);
        uint pitch = reinterpret_cast<uint&>(currentNode->Rotation.Pitch);
        frame.scratch[2] = roll;
        yaw += index == 1 ? 0x4000U : 0xffffc000U;
        frame.scratch[0] = pitch;
        frame.scratch[1] = yaw;
        FVector* side = &(frame.direction = ((FRotator*)frame.scratch)->Vector());
        float10 z = (float10)side->Z * nativeFloat5EPlus02;
        float10 y = (float10)side->Y * nativeFloat5EPlus02;
        frame.productOrSize = (float)y;
        float10 x = (float10)side->X * nativeFloat5EPlus02;
        reinterpret_cast<float&>(frame.scratch[0]) = (float)x;
        z += reinterpret_cast<float&>(frame.start[2]);
        y = (float10)reinterpret_cast<float&>(frame.start[1]) + frame.productOrSize;
        x = (float10)reinterpret_cast<float&>(frame.scratch[0]) + reinterpret_cast<float&>(frame.start[0]);
        reinterpret_cast<float&>(frame.scratch[0]) = (float)x;
        frame.candidate[0] = frame.scratch[0];
        APawn* currentPawn = this->Pawn;
        reinterpret_cast<float&>(frame.scratch[1]) = (float)y;
        uint rawY = frame.scratch[1];
        reinterpret_cast<float&>(frame.scratch[2]) = (float)z;
        uint rawZ = frame.scratch[2];
        frame.candidate[1] = rawY;
        frame.candidate[2] = rawZ;
        uint currentPawnZ = reinterpret_cast<uint&>(currentPawn->Location.Z);
        prepareExtent();
        frame.candidate[2] = currentPawnZ;
        ULevel* currentLevel = this->XLevel;
        byte* table = *(byte**)currentLevel;
        (*(SingleLineCheck*)(table + 0xcc))(currentLevel, reinterpret_cast<uint*>(&frame.hit), this,
            (FVector*)frame.candidate, (FVector*)frame.start, 0x86U, extentX, extentY, extentZ);
    };
    auto groundProbe = [&](uint index) {
        float10 z = reinterpret_cast<float&>(frame.candidate[2]);
        uint x = frame.candidate[0];
        z -= (index == 0 ? nativeFloat120 : nativeFloat2EPlus02);
        ULevel* currentLevel = this->XLevel;
        float10 y = reinterpret_cast<float&>(frame.candidate[1]);
        frame.scratch[0] = x;
        uint* zero = *(uint**)&FVectorFVector0Import;
        reinterpret_cast<float&>(frame.scratch[1]) = (float)y;
        reinterpret_cast<float&>(frame.scratch[2]) = (float)z;
        uint zx = zero[0];
        byte* table = *(byte**)currentLevel;
        uint zy = zero[1];
        uint zz = zero[2];
        (*(SingleLineCheck*)(table + 0xcc))(currentLevel, reinterpret_cast<uint*>(&frame.hit), this,
            (FVector*)frame.scratch, (FVector*)frame.candidate, 0x86U, zx, zy, zz);
        float10 time = frame.hit.Time;
        return time < nativeFloatOne; // Ordered ground hit; no success for unordered or equality.
    };
    auto rememberBlocked = [&](uint index) {
        float10 z = frame.hit.Location.Z;
        uint rawZ, rawX, rawY;
        if (index == 0)
            rawZ = reinterpret_cast<uint&>(frame.hit.Location.Z);
        z -= reinterpret_cast<float&>(frame.start[2]);
        if (index == 0)
            rawX = reinterpret_cast<uint&>(frame.hit.Location.X);
        float10 y = frame.hit.Location.Y;
        if (index == 0)
            rawY = reinterpret_cast<uint&>(frame.hit.Location.Y);
        y -= reinterpret_cast<float&>(frame.start[1]);
        if (index == 0)
            frame.best[2] = rawZ;
        float10 x = (float10)frame.hit.Location.X - reinterpret_cast<float&>(frame.start[0]);
        if (index == 0) {
            frame.best[0] = rawX;
            frame.best[1] = rawY;
        }
        reinterpret_cast<float&>(frame.scratch[0]) = (float)x;
        reinterpret_cast<float&>(frame.scratch[1]) = (float)y;
        reinterpret_cast<float&>(frame.scratch[2]) = (float)z;
        float10 distance = reinterpret_cast<LiveVectorSize&>(FVectorSizeImport)((FVector*)frame.scratch);
        if (index == 0) {
            frame.productOrSize = (float)distance;
            reinterpret_cast<uint&>(frame.bestDistance) = reinterpret_cast<uint&>(frame.productOrSize);
            return;
        }
        float10 best;
        if (index == 1) {
            best = frame.bestDistance;
            frame.productOrSize = (float)distance; // FCOM precedes FST; live distance survives both.
        } else {
            frame.productOrSize = (float)distance;
            best = frame.bestDistance; // Last block spills before its popping compare, without updating bestDistance.
        }
        if (distance > best) {
            uint hitX = reinterpret_cast<uint&>(frame.hit.Location.X);
            if (index == 1)
                frame.bestDistance = (float)distance;
            uint hitY = reinterpret_cast<uint&>(frame.hit.Location.Y);
            uint hitZ = reinterpret_cast<uint&>(frame.hit.Location.Z);
            frame.best[0] = hitX;
            frame.best[1] = hitY;
            frame.best[2] = hitZ;
        }
    };
    for (uint index = 0; index != 3; ++index) {
        if (index != 0)
            sideProbe(index);
        float10 one = nativeFloatOne;
        float10 time = frame.hit.Time;
        if (time == one) {
            if (groundProbe(index)) {
                uint x = frame.candidate[0];
                output = (uint*)outputSlot;
                output[0] = x;
                output[1] = frame.candidate[1];
                output[2] = frame.candidate[2];
                finish();
                return;
            }
        } else {
            rememberBlocked(index);
        }
    }
    output = (uint*)outputSlot;
    uint bestX = frame.best[0];
    uint bestY = frame.best[1];
    output[0] = bestX;
    uint bestZ = frame.best[2];
    output[1] = bestY;
    void* previousExceptionList = frame.previousExceptionList;
    output[2] = bestZ;
    ExceptionList = previousExceptionList;
}

// R6Engine.dll @ 1000d563 : WaitSpotCatchPointer
// Rethrows the caught word through separate storage in the inherited wait-spot frame.
__declspec(naked) void WaitSpotCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x90]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x8c]
        push ecx
        mov dword ptr [ebp-0x8c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1000d580 : WaitSpotCatchContext
// Reports the native RainbowAI wait-spot diagnostic before forwarding the active exception.
__declspec(naked) void WaitSpotCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowAIExecFindNearbyWaitSpot
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100434c0 : AIControllerWaitSpotExceptionHandler
// Forwards the wait-spot frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerWaitSpotExceptionHandler(void)
{
    __asm {
        mov eax,offset waitSpotFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000dde0 : AR6AIController::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6AIController::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6AIControllerConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1000e020 : AR6AIController::execFollowPath
// Evaluates pace, return label and the raw continuation word before delegating path following.
// Native ABI view retains the incoming frame word for the continue-path operand.
void __thiscall AR6AIController::execFollowPath(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Descriptive FPO storage relative to entry ESP; no guard or EBP frame is installed.
        uint savedEsi, savedEbx; // Entry ESP-0x10/-0x0c.
        byte untouched[3], pace; // Entry ESP-0x08..-0x05; only the final byte is initialized.
        uint returnLabel; // Entry ESP-0x04.
    } frame;
    FFrame* vmFrame = stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    frame.pace = 4;
    byte opcode = *code;
    *cursor = code + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    natives[opcode](receiver, vmFrame, &frame.pace);
    code = *cursor;
    frame.returnLabel = 0;
    opcode = *code;
    receiver = vmFrame->Object;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &frame.returnLabel);
    code = *cursor;
    // Incoming entry ESP+4 becomes the evaluator's full continuation word.
    uint& continueSlot = reinterpret_cast<uint&>(stack);
    continueSlot = 0;
    opcode = *code;
    receiver = vmFrame->Object;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &continueSlot);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    uint continuation = continueSlot;
    uint label = frame.returnLabel;
    uint pace = frame.pace;
    // Void RET 8; script result is untouched.
    this->AR6AIController::FollowPath((eMovementPace)pace, *(FName*)&label, (int)continuation);
}

// R6Engine.dll @ 1000e0e0 : AR6AIController::execFollowPathTo
// Far-moves the controller, finds and appends a route goal, or logs failure and ends the latent action.
void __thiscall AR6AIController::execFollowPathTo(FFrame& stack, void* unusedResult)
{
    struct NativeFrameView { // Relative to A = EBP & ~7 after the native saved-EBP push; no local exception guard.
        uint savedEdi, savedEsi; // A-0x20/-0x1c.
        byte untouched[7], pace; // A-0x18..-0x11; only the final byte is initialized.
        AActor* target; // A-0x10.
        uint destination[3]; // A-0x0c/-0x08/-0x04, required operand remains initially uninitialized.
    } frame;
    FFrame* vmFrame = &stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    natives[opcode](receiver, vmFrame, frame.destination);
    code = *cursor;
    receiver = vmFrame->Object;
    frame.pace = 4;
    opcode = *code;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &frame.pace);
    code = *cursor;
    receiver = vmFrame->Object;
    frame.target = nullptr;
    opcode = *code;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &frame.target);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    uint x = frame.destination[0];
    ULevel* level = this->XLevel;
    byte* vtable = *(byte**)level;
    uint y = frame.destination[1];
    uint z = frame.destination[2];
    using FarMoveActor = int (__thiscall *)(ULevel*, AActor*, uint, uint, uint, int, int, int, int);
    (*(FarMoveActor*)(vtable + 0x9c))(level, this, x, y, z, 0, 0, 0, 0); // Raw FVector packet; ignored return.
    AActor* target = frame.target;
    AActor* goal;
    if (target != nullptr) {
        uint* zero = *(uint**)&FVectorFVector0Import;
        x = zero[0];
        y = zero[1];
        z = zero[2];
        goal = target;
    } else {
        x = frame.destination[0];
        y = frame.destination[1];
        z = frame.destination[2];
        goal = this;
    }
    using FindPath = AActor* (__thiscall *)(AController*, uint, uint, uint, AActor*, int);
    AActor* path = reinterpret_cast<FindPath&>(AControllerFindPathImport)(this, x, y, z, goal, 1);
    this->MoveTarget = path;
    if (path == nullptr) {
        APawn* pawn = this->Pawn;
        ANavigationPoint* anchor = pawn->Anchor; // No Pawn null gate is present.
        const ushort* anchorName = anchor != nullptr ?
            anchor->UObject::GetName() :
            nativeTextNone; // L"None".
        float10 liveZ = reinterpret_cast<float&>(frame.destination[2]);
        pawn = this->Pawn;
        double destinationZ = (double)liveZ;
        double destinationY = (double)reinterpret_cast<float&>(frame.destination[1]);
        double destinationX = (double)reinterpret_cast<float&>(frame.destination[0]);
        double pawnZ = (double)pawn->Location.Z;
        double pawnY = (double)pawn->Location.Y;
        double pawnX = (double)pawn->Location.X;
        const ushort* pawnName = pawn->UObject::GetName();
        FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
        log->FOutputDevice::Logf(nativeTextWARNINGSAt62f62f62fAnchorSCannotFindAPathTo62f62f62f,
            pawnName,
            pawnX, pawnY, pawnZ, anchorName, destinationX, destinationY, destinationZ);
        FStateFrame* currentState = *reinterpret_cast<FStateFrame**>((byte*)this + 0xc);
        currentState->LatentAction = 0;
        this->m_eMoveToResult = 2;
        return;
    }
    uint index = 0;
    for (;;) {
        AActor* routeNode = this->RouteCache[index];
        if (routeNode == nullptr || routeNode == this)
            break;
        if (++index > 15)
            break;
    }
    if (index < 16) {
        target = frame.target;
        this->RouteCache[index] = target != nullptr ? target : this;
    }
    uint label = 0;
    uint pace = frame.pace;
    // Full sixteen-entry cache still delegates.
    this->AR6AIController::FollowPath((eMovementPace)pace, *(FName*)&label, 0);
}

// R6Engine.dll @ 1000e2f0 : AR6AIController::AdjustFromWall
// Chooses a lateral door adjustment or delegates wall steering during selected latent movement actions.
void __thiscall AR6AIController::AdjustFromWall(FVector hitNormal, AActor* hitActor)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; branch paths exchange the two vector buffers.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x60/-0x5c/-0x58.
        FVector first, second; // EBP-0x54/-0x48.
        FVector side, axis; // EBP-0x3c/-0x30.
        FVector difference; // EBP-0x24, reused for post-scale sums.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerWallAdjustExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    // bAdjustFromWalls is read before state zero.
    bool enabled = (*reinterpret_cast<byte*>(reinterpret_cast<byte*>(this) + 0x4ec) & 2U) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (!enabled) {
        finish();
        return;
    }
    FStateFrame* state = *reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(this) + 0xc);
    uint action = state->LatentAction;
    if (action != 0x1f5 && action != 0x1f7 && action != 0x25a) {
        finish();
        return;
    }
    AActor* hit = hitActor;
    if (hit != nullptr && hit->UObject::IsA(&AR6IORotatingDoor::PrivateStaticClass) != 0) {
        APawn* initialPawn = this->Pawn;
        if (initialPawn != nullptr) {
            AActor* moveTarget = this->MoveTarget;
            if (moveTarget != nullptr) {
                AR6Door* door = CastToAR6Door(moveTarget);
                if (door != nullptr) {
                    uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8);
                    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8) = flags | 0x40U;
                    float10 z = (float10)door->Location.Z - initialPawn->Location.Z;
                    float10 y = (float10)door->Location.Y - initialPawn->Location.Y;
                    float10 x = (float10)door->Location.X - initialPawn->Location.X;
                    frame.difference.X = (float)x;
                    frame.difference.Y = (float)y;
                    frame.difference.Z = (float)z;
                    FVector* forward = &(frame.axis = hit->Rotation.Vector());
                    // Returned EAX is ignored.
                    frame.side = frame.difference ^ *forward;
                    float10 zero = nativeFloatZero;
                    float10 sideZ = frame.side.Z;
                    bool negative = sideZ < zero; // Ordered negative only; zero, positive and unordered choose -1.
                    frame.axis.X = (float)zero;
                    frame.axis.Y = (float)zero;
                    frame.axis.Z = negative ? 1.0f : -1.0f;
                    FVector* lateralOutput = negative ? &frame.second : &frame.first;
                    FVector* scaledOutput = negative ? &frame.first : &frame.second;
                    FVector* lateral = &(*lateralOutput = hitNormal ^ frame.axis);
                    FVector* displacement = ScaleVectorToResult(scaledOutput, 64.0f, lateral);
                    APawn* pawn = this->Pawn;
                    float10 sumX = (float10)pawn->Location.X + displacement->X;
                    frame.difference.X = (float)sumX;
                    uint rawX = reinterpret_cast<uint&>(frame.difference.X);
                    float10 sumY = (float10)pawn->Location.Y + displacement->Y;
                    frame.difference.Y = (float)sumY;
                    float10 sumZ = (float10)pawn->Location.Z + displacement->Z;
                    uint rawY = reinterpret_cast<uint&>(frame.difference.Y);
                    reinterpret_cast<uint&>(this->AdjustLoc.X) = rawX;
                    reinterpret_cast<uint&>(this->AdjustLoc.Y) = rawY;
                    frame.difference.Z = (float)sumZ;
                    reinterpret_cast<uint&>(this->AdjustLoc.Z) = reinterpret_cast<uint&>(frame.difference.Z);
                    finish();
                    return;
                }
            }
        }
    }
    uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8);
    if ((flags & 0x40U) != 0) {
        this->MoveTimer = -1.0f;
        finish();
        return;
    }
    uint normalY = reinterpret_cast<uint&>(hitNormal.Y);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3a8) = flags | 0x40U;
    uint normalX = reinterpret_cast<uint&>(hitNormal.X);
    uint normalZ = reinterpret_cast<uint&>(hitNormal.Z);
    APawn* pawn = this->Pawn;
    using PickWallAdjust = int (__thiscall *)(APawn*, uint, uint, uint); // Raw by-value normal packet.
    if (reinterpret_cast<PickWallAdjust&>(APawnPickWallAdjustImport)(pawn, normalX, normalY, normalZ) == 0) {
        this->MoveTimer = -1.0f;
    } else {
        pawn = this->Pawn;
        if (pawn->AActor::IsAnimating(0) == 0) {
            // Native dispatches this event on the controller.
            this->AActor::eventAnimEnd(0);
        }
    }
    pawn = this->Pawn;
    if (pawn->Physics == 2) {
        pawn->AActor::eventFalling();
    }
    finish(); // Native RET 0x10; fallback deliberately adds no Pawn null gate.
}

// R6Engine.dll @ 1000e541 : WallAdjustCatchPointer
// Rethrows the caught word through separate storage in the inherited wall-adjustment frame.
__declspec(naked) void WallAdjustCatchPointer(void)
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

// R6Engine.dll @ 1000e555 : WallAdjustCatchContext
// Reports wall-adjustment context before forwarding the active exception.
__declspec(naked) void WallAdjustCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerAdjustFromWall
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043510 : AIControllerWallAdjustExceptionHandler
// Forwards the wall-adjustment frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerWallAdjustExceptionHandler(void)
{
    __asm {
        mov eax,offset wallAdjustFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000e580 : AR6AIController::execCanWalkTo
// Evaluates destination and the raw debug word, then stores the full native reachability result.
// Native ABI view retains the incoming frame word for the debug operand.
void __thiscall AR6AIController::execCanWalkTo(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; required destination remains initially untouched.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        uint destination[3]; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerCanWalkVMExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    byte opcode = *code;
    *cursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    natives[opcode](receiver, vmFrame, frame.destination);
    code = *cursor;
    receiver = vmFrame->Object;
    // Incoming EBP+8 becomes the evaluator's debug output; retained VM stays live.
    uint& debugSlot = reinterpret_cast<uint&>(stack);
    debugSlot = 0;
    opcode = *code;
    *cursor = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, vmFrame, &debugSlot);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    uint debug = debugSlot;
    uint x = frame.destination[0];
    uint y = frame.destination[1];
    uint z = frame.destination[2];
    using NativeCanWalkTo = int (__thiscall *)(AR6AIController*, uint, uint, uint, int);
    // Raw by-value FVector and full debug word.
    int canWalk = ((NativeCanWalkTo)&AR6AIControllerCanWalkToNativeEntry)(this, x, y, z, (int)debug);
    uint* output = (uint*)result; // Native samples EBP+0xc after the call.
    *output = (uint)canWalk;
    ExceptionList = frame.previousExceptionList; // Native RET 8; no owned local cleanup.
}

// R6Engine.dll @ 1000e645 : CanWalkVMCatchPointer
// Rethrows the caught word through separate storage in the inherited VM bridge frame.
__declspec(naked) void CanWalkVMCatchPointer(void)
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

// R6Engine.dll @ 1000e659 : CanWalkVMCatchContext
// Reports CanWalkTo VM context before forwarding the active exception.
__declspec(naked) void CanWalkVMCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecCanWalkTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043520 : AIControllerCanWalkVMExceptionHandler
// Forwards the CanWalkTo VM frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerCanWalkVMExceptionHandler(void)
{
    __asm {
        mov eax,offset canWalkVMFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000e680 : AR6AIController::NeedToOpenDoor
// Applies closed-door interaction gates, then tests whether a direct trace hits any rotating-door class.
int __thiscall AR6AIController::NeedToOpenDoor(AActor* targetActor)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; native failure tail is at 1000e88b..1000e8a0.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x54/-0x50/-0x4c.
        NativeCheckResult32 hit; // EBP-0x48..-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerNeedDoorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6Pawn* interactionPawn = this->m_r6pawn;
    byte pawnType = interactionPawn->m_ePawnType; // Native reads this before saved ESP/state zero, without a null gate.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    ULevel* level;
    APawn* tracePawn;
    byte* vtable;
    uint extentX, extentY, extentZ;
    if (pawnType == 1) {
        AR6Door* door = interactionPawn->m_Door;
        if (door == nullptr)
            return finish(0);
        AR6IORotatingDoor* rotating = door->m_RotatingDoor;
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(rotating) + 0x488) & 0x200U) == 0)
            return finish(0);
        uint* zero = *(uint**)&FVectorFVector0Import;
        level = this->XLevel;
        tracePawn = this->Pawn;
        frame.hit.nextAddress = 0;
        frame.hit.actorAddress = 0;
        reinterpret_cast<uint&>(frame.hit.Location.X) = 0;
        reinterpret_cast<uint&>(frame.hit.Location.Y) = 0;
        reinterpret_cast<uint&>(frame.hit.Location.Z) = 0;
        reinterpret_cast<uint&>(frame.hit.Normal.X) = 0;
        reinterpret_cast<uint&>(frame.hit.Normal.Y) = 0;
        reinterpret_cast<uint&>(frame.hit.Normal.Z) = 0;
        frame.hit.primitiveAddress = 0;
        frame.hit.materialAddress = 0;
        reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000U;
        reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffffU;
        extentX = zero[0];
        vtable = *(byte**)level;
        extentY = zero[1];
        extentZ = zero[2];
    } else {
        AActor* target = targetActor;
        if (target == nullptr)
            return finish(0);
        UClass* type = target->Class;
        while (type != nullptr && type != &AR6Door::PrivateStaticClass)
            type = type->GetSuperClass();
        if (type == nullptr)
            return finish(0);
        if (target == nullptr)
            return finish(0);
        AR6IORotatingDoor* rotating = static_cast<AR6Door*>(target)->m_RotatingDoor;
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(rotating) + 0x488) & 0x200U) == 0)
            return finish(0);
        AR6Pawn* currentPawn = this->m_r6pawn;
        if (rotating->AR6IORotatingDoor::WillOpenOnTouch(currentPawn) != 0)
            return finish(0);
        InitializeCheckResult(reinterpret_cast<FCheckResult*>(&frame.hit), 1.0f, nullptr);
        uint* zero = *(uint**)&FVectorFVector0Import;
        extentX = zero[0];
        level = this->XLevel;
        tracePawn = this->Pawn;
        vtable = *(byte**)level;
        extentY = zero[1];
        extentZ = zero[2];
    }
    const FVector* start =
        reinterpret_cast<const FVector*>(static_cast<uint>(reinterpret_cast<uintptr_t>(tracePawn)) + 0x234U);
    // Type 1 leaves target unchecked, including null.
    const FVector* end =
        reinterpret_cast<const FVector*>(static_cast<uint>(reinterpret_cast<uintptr_t>(targetActor)) + 0x234U);
    using SingleLineCheck = int (__thiscall *)(ULevel*, uint*, AActor*, const FVector*, const FVector*,
        uint, uint, uint, uint); // Direct field pointers and raw by-value extent words.
    (*(SingleLineCheck*)(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), tracePawn,
        end, start, 0xbfU, extentX, extentY, extentZ); // Return value and hit.Time are ignored.
    AActor* hitActor = reinterpret_cast<AActor*>(frame.hit.actorAddress);
    if (hitActor == nullptr)
        return finish(0);
    UClass* hitType = hitActor->Class;
    while (hitType != nullptr && hitType != &AR6IORotatingDoor::PrivateStaticClass)
        hitType = hitType->GetSuperClass();
    // Native RET 4; hit identity and current closed/touch flags are not retested.
    return finish(hitType != nullptr ? 1 : 0);
}

// R6Engine.dll @ 1000e85b : NeedDoorCatchPointer
// Rethrows the caught word through separate storage in the inherited door-predicate frame.
__declspec(naked) void NeedDoorCatchPointer(void)
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

// R6Engine.dll @ 1000e86f : NeedDoorCatchContext
// Reports door-predicate context before forwarding the active exception.
__declspec(naked) void NeedDoorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerNeedToOpenDoor
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043530 : AIControllerNeedDoorExceptionHandler
// Forwards the door-predicate frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerNeedDoorExceptionHandler(void)
{
    __asm {
        mov eax,offset needDoorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000e8a0 : AR6AIController::execGotoOpenDoorState
// Evaluates the door and delegates the open-door state transition after optional DebugInfo.
void __thiscall AR6AIController::execGotoOpenDoorState(FFrame& stack, void* unusedResult)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; actor output starts null after the cursor read.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        AR6Door* navPointToOpenFrom; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerGotoDoorVMExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = &stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    frame.navPointToOpenFrom = nullptr;
    byte opcode = *code;
    *cursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    natives[opcode](receiver, vmFrame, &frame.navPointToOpenFrom);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    AActor* actor = frame.navPointToOpenFrom;
    // Null is forwarded without an added guard; result storage is not read.
    this->AR6AIController::GotoOpenDoorState(actor);
    ExceptionList = frame.previousExceptionList; // Native RET 8; no owned local cleanup.
}

// R6Engine.dll @ 1000e930 : GotoDoorVMCatchPointer
// Rethrows the caught word through separate storage in the inherited door VM frame.
__declspec(naked) void GotoDoorVMCatchPointer(void)
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

// R6Engine.dll @ 1000e944 : GotoDoorVMCatchContext
// Reports execGotoOpenDoorState context before forwarding the active exception.
__declspec(naked) void GotoDoorVMCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecGotoOpenDoorState
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043540 : AIControllerGotoDoorVMExceptionHandler
// Forwards this door VM frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerGotoDoorVMExceptionHandler(void)
{
    __asm {
        mov eax,offset gotoDoorVMFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10010ba0 : AR6AIController::execNeedToOpenDoor
// Evaluates the target and stores the full door-predicate result after optional DebugInfo.
void __thiscall AR6AIController::execNeedToOpenDoor(FFrame& stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; actor output starts null after the cursor read.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        AActor* target; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&AIControllerNeedDoorVMExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = &stack;
    byte** cursor = &vmFrame->Code;
    byte* code = *cursor;
    frame.target = nullptr;
    byte opcode = *code;
    *cursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    natives[opcode](receiver, vmFrame, &frame.target);
    code = *cursor + 1;
    *cursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *cursor = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, vmFrame, nullptr);
    }
    AActor* actor = frame.target;
    int needsOpening = this->AR6AIController::NeedToOpenDoor(actor);
    uint* output = (uint*)result; // Native reads current EBP+0xc only after delegation.
    *output = (uint)needsOpening; // Preserve the full returned DWORD.
    ExceptionList = frame.previousExceptionList; // Native RET 8; no owned local cleanup.
}

// R6Engine.dll @ 10010c35 : NeedDoorVMCatchPointer
// Rethrows the caught word through separate storage in the inherited door VM frame.
__declspec(naked) void NeedDoorVMCatchPointer(void)
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

// R6Engine.dll @ 10010c49 : NeedDoorVMCatchContext
// Reports execNeedToOpenDoor context before forwarding the active exception.
__declspec(naked) void NeedDoorVMCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecNeedToOpenDoor
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100435a0 : AIControllerNeedDoorVMExceptionHandler
// Forwards this door VM frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void AIControllerNeedDoorVMExceptionHandler(void)
{
    __asm {
        mov eax,offset needDoorVMFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045d40 : InitializeAR6AIControllerClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6AIControllerClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = AAIControllerPrivateStaticClassImport;
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
    packet.internalConstructor = &AR6AIController::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload saved words after the configuration callback.
    parentClass = captures.parentClass;
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6AIController;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x56c;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6AIController::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6AIControllerClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10047fb0 : DestroyAR6AIControllerClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6AIControllerClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6AIController::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100455e0 : RegisterPollMoveToPositionNative
// Binds polling native index0x259 to the exported callback word and retains the provider's byte result.
void __cdecl RegisterPollMoveToPositionNative(void)
{
    pollPollMoveToPositionRegistrationResult = GRegisterNative(0x259, intAR6AIControllerexecPollMoveToPosition);
}

// R6Engine.dll @ 10045600 : RegisterPollFollowPathNative
// Binds polling native index0x25a to the exported callback word and retains the provider's byte result.
void __cdecl RegisterPollFollowPathNative(void)
{
    pollPollFollowPathRegistrationResult = GRegisterNative(0x25a, intAR6AIControllerexecPollFollowPath);
}

// R6Engine.dll @ 10045620 : RegisterPollFollowPathBlockedNative
// Binds polling native index0x25b to the exported callback word and retains the provider's byte result.
void __cdecl RegisterPollFollowPathBlockedNative(void)
{
    pollPollFollowPathBlockedRegistrationResult = GRegisterNative(0x25b, intAR6AIControllerexecPollFollowPathBlocked);
}

// R6Engine.dll @ 10045dd0 : PublishAR6AIControllerAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6AIControllerAutoClass(void)
{
    autoclassAR6AIController = &AR6AIController::PrivateStaticClass;
}

// R6Engine.dll @ 10047720 : RegisterAR6AIControllerActorReachableFromLocationNative
// Registers native index0x8ac using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerActorReachableFromLocationNative(void)
{
    AR6AIControllerActorReachableFromLocationRegistrationResult =
        GRegisterNative(0x8ac, intAR6AIControllerexecActorReachableFromLocation);
}

// R6Engine.dll @ 10047740 : RegisterAR6AIControllerFindNearbyWaitSpotNative
// Registers native index0x8a1 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFindNearbyWaitSpotNative(void)
{
    AR6AIControllerFindNearbyWaitSpotRegistrationResult =
        GRegisterNative(0x8a1, intAR6AIControllerexecFindNearbyWaitSpot);
}

// R6Engine.dll @ 10047760 : RegisterAR6AIControllerGotoOpenDoorStateNative
// Registers native index0x5e6 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerGotoOpenDoorStateNative(void)
{
    AR6AIControllerGotoOpenDoorStateRegistrationResult =
        GRegisterNative(0x5e6, intAR6AIControllerexecGotoOpenDoorState);
}

// R6Engine.dll @ 10047780 : RegisterAR6AIControllerNeedToOpenDoorNative
// Registers native index0x5e5 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerNeedToOpenDoorNative(void)
{
    AR6AIControllerNeedToOpenDoorRegistrationResult = GRegisterNative(0x5e5, intAR6AIControllerexecNeedToOpenDoor);
}

// R6Engine.dll @ 100477a0 : RegisterAR6AIControllerFindGrenadeDirectionToHitActorNative
// Registers native index0x718 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFindGrenadeDirectionToHitActorNative(void)
{
    AR6AIControllerFindGrenadeDirectionToHitActorRegistrationResult =
        GRegisterNative(0x718,
            intAR6AIControllerexecFindGrenadeDirectionToHitActor);
}

// R6Engine.dll @ 100477c0 : RegisterAR6AIControllerCanWalkToNative
// Registers native index0x717 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerCanWalkToNative(void)
{
    AR6AIControllerCanWalkToRegistrationResult = GRegisterNative(0x717, intAR6AIControllerexecCanWalkTo);
}

// R6Engine.dll @ 100477e0 : RegisterAR6AIControllerFollowPathToNative
// Registers native index0x716 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFollowPathToNative(void)
{
    AR6AIControllerFollowPathToRegistrationResult = GRegisterNative(0x716, intAR6AIControllerexecFollowPathTo);
}

// R6Engine.dll @ 10047800 : RegisterAR6AIControllerFollowPathNative
// Registers native index0x714 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFollowPathNative(void)
{
    AR6AIControllerFollowPathRegistrationResult = GRegisterNative(0x714, intAR6AIControllerexecFollowPath);
}

// R6Engine.dll @ 10047820 : RegisterAR6AIControllerMoveToPositionNative
// Registers native index0x899 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerMoveToPositionNative(void)
{
    AR6AIControllerMoveToPositionRegistrationResult = GRegisterNative(0x899, intAR6AIControllerexecMoveToPosition);
}

// R6Engine.dll @ 10047840 : RegisterAR6AIControllerPickActorAdjustNative
// Registers native index0x715 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerPickActorAdjustNative(void)
{
    AR6AIControllerPickActorAdjustRegistrationResult = GRegisterNative(0x715, intAR6AIControllerexecPickActorAdjust);
}

// R6Engine.dll @ 10047860 : RegisterAR6AIControllerFindInvestigationPointNative
// Registers native index0x71a using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFindInvestigationPointNative(void)
{
    AR6AIControllerFindInvestigationPointRegistrationResult =
        GRegisterNative(0x71a, intAR6AIControllerexecFindInvestigationPoint);
}

// R6Engine.dll @ 10047880 : RegisterAR6AIControllerFindPlaceToFireNative
// Registers native index0x719 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFindPlaceToFireNative(void)
{
    AR6AIControllerFindPlaceToFireRegistrationResult = GRegisterNative(0x719, intAR6AIControllerexecFindPlaceToFire);
}

// R6Engine.dll @ 100478a0 : RegisterAR6AIControllerFindPlaceToTakeCoverNative
// Registers native index0x713 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerFindPlaceToTakeCoverNative(void)
{
    AR6AIControllerFindPlaceToTakeCoverRegistrationResult =
        GRegisterNative(0x713, intAR6AIControllerexecFindPlaceToTakeCover);
}

// R6Engine.dll @ 100478c0 : RegisterAR6AIControllerMakePathToRunNative
// Registers native index0x712 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6AIControllerMakePathToRunNative(void)
{
    AR6AIControllerMakePathToRunRegistrationResult = GRegisterNative(0x712, intAR6AIControllerexecMakePathToRun);
}

// R6Engine.dll @ 10043470 : HearingCheckExceptionHandler
// Supplies the exact guarded-trace FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl HearingCheckExceptionHandler(void)
{
    __asm {
        mov eax,offset hearingCheckInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042c80 : ClearActionSpotExceptionHandler
// Selects ClearActionSpot's exact C++ exception metadata.
__declspec(naked) void __cdecl ClearActionSpotExceptionHandler(void)
{
    __asm {
        mov eax,offset clearActionSpotFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042c90 : PickActorAdjustExceptionHandler
// Selects the actor-adjustment script bridge's exact C++ exception metadata.
__declspec(naked) void __cdecl PickActorAdjustExceptionHandler(void)
{
    __asm {
        mov eax,offset pickActorAdjustFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042ca0 : ActorReachableExceptionHandler
// Selects the reachability script bridge's exact C++ exception metadata.
__declspec(naked) void __cdecl ActorReachableExceptionHandler(void)
{
    __asm {
        mov eax,offset actorReachableFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10008340 : AR6AIController::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6AIController::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6AIControllerDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x56c;
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
    this->AR6AIController::~AR6AIController();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x56c;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll @ 1000db10 : return the object if its class chain contains AR6Door
AR6Door* __cdecl CastToAR6Door(UObject* object)
{
    if (object == nullptr)
        return nullptr;
    UClass* classCursor = object->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6Door::PrivateStaticClass)
            return static_cast<AR6Door*>(object);
        classCursor = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(classCursor) + 0x2c);
    }
    return nullptr;
}

// Private cast names and pointer types are inferred from native class tests and caller packets.
// R6Engine.dll @ 100017c0 : CastToANavigationPoint
// Returns the original object for a matching class chain or a null imported target class.
ANavigationPoint* __cdecl CastToANavigationPoint(UObject* object)
{
    if (object == nullptr) return nullptr;
    UClass* classCursor = object->Class;
    // ANavigationPoint::PrivateStaticClass, sampled after object.Class.
    UClass* expectedClass = ANavigationPointPrivateStaticClassImport;
    while (classCursor != nullptr) {
        if (classCursor == expectedClass) return static_cast<ANavigationPoint*>(object);
        classCursor = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(classCursor) + 0x2c);
    }
    return expectedClass == nullptr ? reinterpret_cast<ANavigationPoint*>(object) : nullptr;
}

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004c590 : nativeTextCheckSpotValidForCover
extern const ushort nativeTextCheckSpotValidForCover[23];

// R6Engine.dll data @ 1004c55c : nativeTextCheckSpotValidForFire
extern const ushort nativeTextCheckSpotValidForFire[22];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void CoverFilterCatchContext(void);
__declspec(naked) void CoverFilterCatchPointer(void);
__declspec(naked) void CoverFilterExceptionHandler(void);
__declspec(naked) void FireFilterCatchContext(void);
__declspec(naked) void FireFilterCatchPointer(void);
__declspec(naked) void FireFilterExceptionHandler(void);

// R6Engine.dll data @ 1005721c : fireFilterUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry fireFilterUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005722c : fireFilterCatchMap
// The caught word is at parent EBP-0x18; no owned local cleanup is installed.
const NativeCatchEntry fireFilterCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&FireFilterCatchPointer) },
    { 0, 0, 0, ((uint)&FireFilterCatchContext) }
};

// R6Engine.dll data @ 1005724c : fireFilterTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock fireFilterTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&fireFilterCatchMap) }
};

// R6Engine.dll data @ 10057260 : fireFilterFuncInfo
// Binds the complete predicate without adding local cleanup actions.
const NativeFunctionInfoPrefix fireFilterFuncInfo = { 0x19930520, 0x2, ((uint)&fireFilterUnwindMap), 0x1,
    ((uint)&fireFilterTryMap), 0 };

// R6Engine.dll data @ 1005727c : coverFilterUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry coverFilterUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005728c : coverFilterCatchMap
// The caught word is at parent EBP-0x18; no owned local cleanup is installed.
const NativeCatchEntry coverFilterCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CoverFilterCatchPointer) },
    { 0, 0, 0, ((uint)&CoverFilterCatchContext) }
};

// R6Engine.dll data @ 100572ac : coverFilterTryMap
// State zero selects both inherited-frame handlers.
const NativeTryBlock coverFilterTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&coverFilterCatchMap) }
};

// R6Engine.dll data @ 100572c0 : coverFilterFuncInfo
// Binds the complete predicate without adding local cleanup actions.
const NativeFunctionInfoPrefix coverFilterFuncInfo = { 0x19930520, 0x2, ((uint)&coverFilterUnwindMap), 0x1,
    ((uint)&coverFilterTryMap), 0 };

// R6Engine.dll @ 1000adc0 : EvaluateNavigationNodeWeight
// Scores eligible non-ladder nodes by escape alignment divided by their signed visited weight.
float10 __cdecl EvaluateNavigationNodeWeight(
    ANavigationPoint* candidateNode, APawn* searchingPawn, float unusedCurrentWeight)
{
    if (candidateNode->cost != 0)
        return nativeFloatZero;
    if (candidateNode == searchingPawn->Anchor)
        return nativeFloatZero;
    UClass* classCursor = candidateNode->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6Ladder::PrivateStaticClass) // Exported AR6Ladder::PrivateStaticClass.
            return nativeFloatZero;
        classCursor = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(classCursor) + 0x2c);
    }
    FVector towardNode; // Native entryESP-0x18/-0x14/-0x10.
    FVector awayFromEnemy; // Native entryESP-0x0c/-0x08/-0x04.
    AController* controller = searchingPawn->Controller;
    float10 dz = searchingPawn->Location.Z;
    APawn* enemy = controller->Enemy; // Native does not guard either receiver.
    dz -= enemy->Location.Z;
    float10 dy = (float10)searchingPawn->Location.Y - enemy->Location.Y;
    float10 dx = (float10)searchingPawn->Location.X - enemy->Location.X;
    awayFromEnemy.X = (float)dx;
    awayFromEnemy.Y = (float)dy;
    awayFromEnemy.Z = (float)dz;
    towardNode.X = (float)((float10)candidateNode->Location.X - searchingPawn->Location.X);
    towardNode.Y = (float)((float10)candidateNode->Location.Y - searchingPawn->Location.Y);
    towardNode.Z = (float)((float10)candidateNode->Location.Z - searchingPawn->Location.Z);
    awayFromEnemy.Normalize();
    // Current import is reread; both integer return values are ignored.
    towardNode.Normalize();
    float10 zProduct = (float10)towardNode.Z * awayFromEnemy.Z;
    float10 yProduct = (float10)towardNode.Y * awayFromEnemy.Y;
    float10 alignment = zProduct + yProduct;
    float10 xProduct = (float10)towardNode.X * awayFromEnemy.X;
    alignment += xProduct;
    int visitedWeight = candidateNode->visitedWeight;
    return alignment / (float10)visitedWeight; // FIDIV signed DWORD; no zero check or final binary32 spill.
}

// R6Engine.dll @ 100010c0 : CheckSpotValidForInvestigation
// Accepts investigation spots not yet used for the supplied search index; the pawn argument is unused.
int __cdecl CheckSpotValidForInvestigation(
    AR6Pawn* unusedPawn, AR6ActionSpot* spot, STActionSpotCheck* check)
{
    if ((reinterpret_cast<byte*>(spot)[0x39c] & 2U) == 0) // m_bInvestigate.
        return 0;
    NativeActionSpotCheckPrefix* context = reinterpret_cast<NativeActionSpotCheckPrefix*>(check); // Before last-ID.
    int lastInvestigationID = spot->m_iLastInvestigateID;
    int searchIndex = context->searchIndex;
    return lastInvestigationID < searchIndex ? 1 : 0;
}

// R6Engine.dll @ 1000b460 : CheckSpotValidForFire
// Filters unused spots by mode, target distance, facing and an optional target-to-spot trace.
int __cdecl CheckSpotValidForFire(AR6Pawn* pawn, AR6ActionSpot* spot, STActionSpotCheck* check)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; shared scratch retains native reuse.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x6c/-0x68/-0x64.
        NativeCheckResult32 hit; // EBP-0x60..-0x34; native FCheckResult storage.
        uint scratch[3]; // EBP-0x30/-0x2c/-0x28: component spills, hidden rotator, then trace start.
        FVector direction; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&FireFilterExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6ActionSpot* activeSpot = spot;
    uint& incomingYaw = reinterpret_cast<uint&>(spot); // Native overwrites EBP+0x0c and rereads it after Rotation.
    APawn* currentUser = activeSpot->m_pCurrentUser;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (currentUser != nullptr)
        return finish(0);
    byte fire = activeSpot->m_eFire;
    NativeActionSpotCheckPrefix* context = reinterpret_cast<NativeActionSpotCheckPrefix*>(check);
    if (fire == 0) {
        if (context->target != nullptr)
            return finish(0);
        if (activeSpot->m_eCover == 0)
            return finish(0);
    }
    AActor* target = context->target;
    if (target != nullptr) {
        float10 dz = (float10)target->Location.Z - activeSpot->Location.Z;
        float10 dy = (float10)target->Location.Y - activeSpot->Location.Y;
        float10 dx = (float10)target->Location.X - activeSpot->Location.X;
        float10 xSquared = dx * dx;
        float10 ySquared = dy * dy;
        float10 distanceSquared = xSquared + ySquared;
        float10 zSquared = dz * dz;
        distanceSquared += zSquared;
        if (distanceSquared < (float10)nativeFloat2Point5EPlus03)
            return finish(0); // Ordered strict less; equality and unordered continue.
    }
    const FVector* spotLocation = &activeSpot->Location;
    const FVector* aim = target != nullptr ? &target->Location : &context->location;
    float10 deltaZ = (float10)aim->Z - spotLocation->Z;
    float10 deltaY = (float10)aim->Y - spotLocation->Y;
    float10 deltaX = (float10)aim->X - spotLocation->X;
    reinterpret_cast<float&>(frame.scratch[0]) = (float)deltaX;
    reinterpret_cast<uint&>(frame.direction.X) = frame.scratch[0];
    uint yaw = reinterpret_cast<uint&>(activeSpot->Rotation.Yaw);
    reinterpret_cast<float&>(frame.scratch[1]) = (float)deltaY;
    reinterpret_cast<uint&>(frame.direction.Y) = frame.scratch[1];
    reinterpret_cast<float&>(frame.scratch[2]) = (float)deltaZ;
    reinterpret_cast<uint&>(frame.direction.Z) = frame.scratch[2];
    incomingYaw = yaw;
    FRotator* heading = &(*reinterpret_cast<FRotator*>(frame.scratch) = frame.direction.Rotation());
    uint returnedYaw = reinterpret_cast<uint&>(heading->Yaw);
    uint currentYaw = incomingYaw;
    uint difference = (returnedYaw - currentYaw) & 0xffffU;
    if (difference > 0x7fffU)
        difference = 0x10000U - difference;
    if (difference >= 0x30d4U)
        return finish(0);
    if (activeSpot->m_Anchor == nullptr)
        return finish(0);
    target = context->target;
    if (target != nullptr) {
        InitializeCheckResult(reinterpret_cast<FCheckResult*>(&frame.hit), 1.0f, nullptr);
        ULevel* level = pawn->XLevel;
        target = context->target;
        float10 raisedZ = target->Location.Z;
        uint startX = reinterpret_cast<uint&>(target->Location.X);
        raisedZ += nativeFloat5EPlus01;
        float10 startY = target->Location.Y;
        frame.scratch[0] = startX;
        uint* zero = reinterpret_cast<uint*&>(FVectorFVector0Import);
        reinterpret_cast<float&>(frame.scratch[1]) = (float)startY;
        reinterpret_cast<float&>(frame.scratch[2]) = (float)raisedZ;
        uint zeroX = zero[0];
        byte* vtable = *reinterpret_cast<byte**>(level);
        uint zeroY = zero[1];
        uint zeroZ = zero[2];
        AR6Pawn* traceActor = pawn;
        using LineCheck = int (__thiscall*)(ULevel*, uint*, AActor*, const FVector*, const FVector*, uint,
            uint, uint, uint); // Raw hit/by-value extent words; slot is sampled only at CALL.
        (*reinterpret_cast<LineCheck*>(vtable + 0xcc))(level, reinterpret_cast<uint*>(&frame.hit), traceActor,
            spotLocation,
            reinterpret_cast<const FVector*>(frame.scratch), 0x20286, zeroX, zeroY, zeroZ);
        uint hitActor = frame.hit.actorAddress;
        if (hitActor != 0) {
            NativeActionSpotCheckPrefix* currentContext = reinterpret_cast<NativeActionSpotCheckPrefix*>(check);
            if (hitActor != reinterpret_cast<uint>(currentContext->target))
                return finish(0);
        }
    }
    return finish(1);
}

// R6Engine.dll @ 1000b653 : forward the caught fire-filter exception value
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void FireFilterCatchPointer(void)
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

// R6Engine.dll @ 1000b667 : report fire-filter context and forward the active exception
// Reports the native context through the current import before null-word rethrow.
__declspec(naked) void FireFilterCatchContext(void)
{
    __asm {
        push offset nativeTextCheckSpotValidForFire
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043420 : FireFilterExceptionHandler
// Forwards the predicate's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void FireFilterExceptionHandler(void)
{
    __asm {
        mov eax,offset fireFilterFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000b6a0 : CheckSpotValidForCover
// Accepts unused fire/cover spots facing the supplied location and retaining a navigation anchor.
int __cdecl CheckSpotValidForCover(AR6Pawn* unusedPawn, AR6ActionSpot* spot, STActionSpotCheck* check)
{
    struct NativeFrameView { // Descriptive EBP-relative storage, not an inferred original declaration.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x3c/-0x38/-0x34.
        FRotator heading; // EBP-0x30/-0x2c/-0x28.
        FVector direction; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CoverFilterExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    APawn* currentUser = spot->m_pCurrentUser;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (currentUser != nullptr)
        return finish(0);
    byte fire = spot->m_eFire;
    if (fire == 0 && spot->m_eCover == 0)
        return finish(0);
    const FVector* threat = &reinterpret_cast<NativeActionSpotCheckPrefix*>(check)->location;
    float10 deltaZ = threat->Z;
    uint spotYaw = reinterpret_cast<uint&>(spot->Rotation.Yaw);
    deltaZ -= spot->Location.Z;
    float10 deltaY = (float10)threat->Y - spot->Location.Y;
    float10 deltaX = (float10)threat->X - spot->Location.X;
    frame.direction.X = (float)deltaX;
    frame.direction.Y = (float)deltaY;
    frame.direction.Z = (float)deltaZ;
    FRotator* returned = &(frame.heading = frame.direction.Rotation());
    uint yaw = reinterpret_cast<uint&>(returned->Yaw); // The selected provider returns the supplied heading slot.
    uint difference = (yaw - spotYaw) & 0xffffU;
    if (difference > 0x7fffU)
        difference = 0x10000U - difference;
    if (difference >= 0x30d4U)
        return finish(0);
    if (spot->m_Anchor == nullptr)
        return finish(0);
    return finish(1);
}

// R6Engine.dll @ 1000b76b : forward the caught cover-filter exception value
// Copies the inherited caught word to its rethrow slot and forwards the original throw metadata.
__declspec(naked) void CoverFilterCatchPointer(void)
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

// R6Engine.dll @ 1000b77f : report cover-filter context and forward the active exception
// Reports the native context through the current import before null-word rethrow.
__declspec(naked) void CoverFilterCatchContext(void)
{
    __asm {
        push offset nativeTextCheckSpotValidForCover
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043430 : CoverFilterExceptionHandler
// Forwards the predicate's exact FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void CoverFilterExceptionHandler(void)
{
    __asm {
        mov eax,offset coverFilterFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10001600 : DistanceToSegment
// Returns point-to-segment distance with the native endpoint tests and projection rounding.
float10 __cdecl DistanceToSegment(const FVector* point, const FVector* start, const FVector* end)
{
    using VectorSizeCall = float10 (__thiscall*)(const FVector*); // Live ST0 return view.
    float segment[3]; // Native ESP-relative delta buffer, reused for either endpoint's Size query.
    segment[0] = (float)((float10)end->X - start->X);
    segment[1] = (float)((float10)end->Y - start->Y);
    segment[2] = (float)((float10)end->Z - start->Z);
    float10 pointX = (float10)point->X - start->X;
    float10 pointY = (float10)point->Y - start->Y;
    float roundedPointY = (float)pointY;
    float10 pointZ = (float10)point->Z - start->Z;
    float roundedPointZ = (float)pointZ;
    float10 projectionDot = (pointZ * segment[2] + pointY * segment[1]) + pointX * segment[0];
    float roundedDot = (float)projectionDot; // Argument slots hold rounded Y/Z/dot; captured pointers stay live.
    if (projectionDot <= (float10)nativeFloatZero) {
        segment[0] = (float)pointX;
        segment[2] = roundedPointZ;
        segment[1] = roundedPointY;
        // Import loaded after all vector accesses.
        return reinterpret_cast<VectorSizeCall&>(FVectorSizeImport)((const FVector*)segment);
    }
    float10 lengthSquared = ((float10)segment[2] * segment[2] + (float10)segment[0] * segment[0])
        + (float10)segment[1] * segment[1];
    if (lengthSquared <= (float10)roundedDot) {
        segment[0] = (float)((float10)point->X - end->X);
        segment[1] = (float)((float10)point->Y - end->Y);
        segment[2] = (float)((float10)point->Z - end->Z);
        return reinterpret_cast<VectorSizeCall&>(FVectorSizeImport)((const FVector*)segment);
    }
    float10 ratio = (float10)roundedDot / lengthSquared;
    float10 scaledX = (float10)segment[0] * ratio;
    float scaledY = (float)((float10)segment[1] * ratio);
    float scaledZ = (float)((float10)segment[2] * ratio);
    float10 projectedX = scaledX + start->X;
    float10 projectedY = (float10)scaledY + start->Y;
    segment[2] = (float)((float10)scaledZ + start->Z);
    float difference[3]; // Distinct native interior Size-query buffer.
    difference[0] = (float)((float10)point->X - projectedX);
    difference[1] = (float)((float10)point->Y - projectedY);
    difference[2] = (float)((float10)point->Z - segment[2]);
    return reinterpret_cast<VectorSizeCall&>(FVectorSizeImport)((const FVector*)difference);
}
