#include "native_array_views.hpp"
#include "native_text_data.hpp"
#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
void* __thiscall ConstructTemplateCopy(void* destination, const void* source);
__declspec(naked) float10 __thiscall FR6CharTemplate_GetSkill(FR6CharTemplate* charTemplate, int skillIndex);
__declspec(naked) int __thiscall FR6CharTemplate_GetTerroristPersonality(FR6CharTemplate* charTemplate);
__declspec(naked) FString* __thiscall FR6CharTemplate_GetWeapon(FR6CharTemplate* charTemplate, FString* result);
__declspec(naked) FString* __thiscall FR6CharTemplate_GetGrenade(
    FR6CharTemplate* charTemplate, FString* result);
__declspec(naked) FString* __thiscall FR6CharTemplate_GetGadget(FR6CharTemplate* charTemplate, FString* result);
__declspec(naked) int __thiscall FR6CharTemplate_GetAttachmentType(FR6CharTemplate* charTemplate);
__declspec(naked) int __thiscall FR6CharTemplate_GetHostagePersonality(FR6CharTemplate* charTemplate);
__declspec(naked) uint __thiscall FR6CharTemplate_GetStartingPosition(FR6CharTemplate* charTemplate);
void __thiscall RemoveRecords4(FArray* array, int index, int count);
__declspec(naked) void __cdecl DestroyAR6DeploymentZoneClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// External native storage views; names describe roles rather than recovered original identifiers.
FArray* __thiscall CopyConstructWordsDirect(FArray* destination, const FArray* source);

__declspec(naked) FString* __thiscall CopyStringToHiddenResult(const FString* source, FString* resultString);

__declspec(naked) void __thiscall DestroyEmbeddedEightByteArrayPair(FArray* array);

// R6Engine.dll data @ 100745b4 : nativeDeploymentTerroristHostageIcon
// Shared lazily initialized icon pointer storage; ownership is unchanged.
extern UObject* nativeDeploymentTerroristHostageIcon;

// R6Engine.dll data @ 100745b8 : nativeDeploymentHostageIcon
// Shared lazily initialized icon pointer storage; ownership is unchanged.
extern UObject* nativeDeploymentHostageIcon;

// R6Engine.dll data @ 100745bc : nativeDeploymentIconInitializationFlags
// Shared editor-icon initialization bit mask; narrow/volatile views remain explicit.
extern uint nativeDeploymentIconInitializationFlags;

// R6Engine.dll data @ 1004d2c8 : AR6DeploymentZoneVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6DeploymentZone::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6DeploymentZoneVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004f888 : nativeTextAR6DeploymentZoneExecAddHostage
extern const ushort nativeTextAR6DeploymentZoneExecAddHostage[34];

// R6Engine.dll data @ 1004f4c0 : nativeTextAR6DeploymentZoneExecFindClosestPointTo
extern const ushort nativeTextAR6DeploymentZoneExecFindClosestPointTo[42];

// R6Engine.dll data @ 1004f410 : nativeTextAR6DeploymentZoneExecFindRandomPointInArea
extern const ushort nativeTextAR6DeploymentZoneExecFindRandomPointInArea[45];

// R6Engine.dll data @ 1004f3c8 : nativeTextAR6DeploymentZoneExecFirstInit
extern const ushort nativeTextAR6DeploymentZoneExecFirstInit[33];

// R6Engine.dll data @ 1004f8d0 : nativeTextAR6DeploymentZoneExecGetClosestHostage
extern const ushort nativeTextAR6DeploymentZoneExecGetClosestHostage[41];

// R6Engine.dll data @ 1004f978 : nativeTextAR6DeploymentZoneExecHaveHostage
extern const ushort nativeTextAR6DeploymentZoneExecHaveHostage[35];

// R6Engine.dll data @ 1004f928 : nativeTextAR6DeploymentZoneExecHaveTerrorist
extern const ushort nativeTextAR6DeploymentZoneExecHaveTerrorist[37];

// R6Engine.dll data @ 1004f470 : nativeTextAR6DeploymentZoneExecIsPointInZone
extern const ushort nativeTextAR6DeploymentZoneExecIsPointInZone[37];

// R6Engine.dll data @ 1004f9c0 : nativeTextAR6DeploymentZoneExecOrderTerroListFromDistanceTo
extern const ushort nativeTextAR6DeploymentZoneExecOrderTerroListFromDistanceTo[52];

// R6Engine.dll data @ 1004f618 : nativeTextAR6DeploymentZoneFindClosestPointTo
extern const ushort nativeTextAR6DeploymentZoneFindClosestPointTo[38];

// R6Engine.dll data @ 1004f748 : nativeTextAR6DeploymentZoneFindRandomPointInArea
extern const ushort nativeTextAR6DeploymentZoneFindRandomPointInArea[41];

// R6Engine.dll data @ 1004fab4 : nativeTextAR6DeploymentZoneFirstInit
extern const ushort nativeTextAR6DeploymentZoneFirstInit[29];

// R6Engine.dll data @ 1004f370 : nativeTextAR6DeploymentZoneGetNbOfTerroristToSpawn
extern const ushort nativeTextAR6DeploymentZoneGetNbOfTerroristToSpawn[43];

// R6Engine.dll data @ 1004f844 : nativeTextAR6DeploymentZoneHaveHostage
extern const ushort nativeTextAR6DeploymentZoneHaveHostage[31];

// R6Engine.dll data @ 1004f668 : nativeTextAR6DeploymentZoneHavePlaceForPawnAt
extern const ushort nativeTextAR6DeploymentZoneHavePlaceForPawnAt[38];

// R6Engine.dll data @ 1004f800 : nativeTextAR6DeploymentZoneHaveTerrorist
extern const ushort nativeTextAR6DeploymentZoneHaveTerrorist[33];

// R6Engine.dll data @ 1004f700 : nativeTextAR6DeploymentZoneInitHostageAI
extern const ushort nativeTextAR6DeploymentZoneInitHostageAI[33];

// R6Engine.dll data @ 1004f6b8 : nativeTextAR6DeploymentZoneInitTerroristAI
extern const ushort nativeTextAR6DeploymentZoneInitTerroristAI[35];

// R6Engine.dll data @ 1004f518 : nativeTextAR6DeploymentZoneRenderEditorInfo
extern const ushort nativeTextAR6DeploymentZoneRenderEditorInfo[36];

// R6Engine.dll data @ 1004fa28 : nativeTextAR6DeploymentZoneSpawnAHostage
extern const ushort nativeTextAR6DeploymentZoneSpawnAHostage[33];

// R6Engine.dll data @ 1004fa70 : nativeTextAR6DeploymentZoneSpawnTerrorist
extern const ushort nativeTextAR6DeploymentZoneSpawnTerrorist[34];

// R6Engine.dll data @ 1004f0d8 : nativeTextAR6DeploymentZoneSpawned
extern const ushort nativeTextAR6DeploymentZoneSpawned[27];

// R6Engine.dll data @ 1005577e : nativeTextR6DeploymentZone
extern const ushort nativeTextR6DeploymentZone[17];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentClosestPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentClosestPointCatchPointer(void);
__declspec(naked) void __cdecl DeploymentCopyState0Cleanup(void);
__declspec(naked) void __cdecl DeploymentCopyState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentCopyState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentCopyState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentCopyState4Cleanup(void);
__declspec(naked) void __cdecl DeploymentCopyState5Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState0Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState4Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState5Cleanup(void);
__declspec(naked) void __cdecl DeploymentDefaultState6Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState0Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState4Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState5Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState6Cleanup(void);
__declspec(naked) void __cdecl DeploymentDestructionState7Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecAddHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecAddHostageCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecClosestHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecClosestHostageCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecFirstInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecFirstInitCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveHostageCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveTerroristCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveTerroristCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecOrderTerroristsCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecOrderTerroristsCatchPointer(void);
__declspec(naked) void __cdecl DeploymentExecOrderTerroristsState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentFirstInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentFirstInitCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveHostageCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveTerroristCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveTerroristCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitHostageCatchPointer(void);
__declspec(naked) void __cdecl DeploymentInitHostageState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitTerroristCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitTerroristCatchPointer(void);
__declspec(naked) void __cdecl DeploymentInitTerroristState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentInitTerroristState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentInitTerroristState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentInitTerroristState4Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentPlacementCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentPlacementCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryClosestPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryClosestPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryPointInZoneCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryPointInZoneCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryRandomPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryRandomPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRandomAreaCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRandomAreaCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRendererCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRendererCatchPointer(void);
__declspec(naked) void __cdecl DeploymentRendererState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentRendererState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentRendererState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnHostageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnHostageCatchPointer(void);
__declspec(naked) void __cdecl DeploymentSpawnHostageState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnHostageState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnHostageState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnHostageState4Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnTerroristCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnTerroristCatchPointer(void);
__declspec(naked) void __cdecl DeploymentSpawnTerroristState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnTerroristState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnTerroristState3Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnTerroristState4Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnedCatchPointer(void);
__declspec(naked) void __cdecl DeploymentSpawnedState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnedState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentSpawnedState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentTerroristCountCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentTerroristCountCatchPointer(void);
__declspec(naked) void __cdecl DeploymentValidateTemplatesState0Cleanup(void);
__declspec(naked) void __cdecl DeploymentValidateTemplatesState1Cleanup(void);
__declspec(naked) void __cdecl DeploymentValidateTemplatesState2Cleanup(void);
__declspec(naked) void __cdecl DeploymentValidateTemplatesState3Cleanup(void);

// R6Engine.dll data @ 10058c08 : deploymentQueryRandomPointUnwindMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeUnwindEntry deploymentQueryRandomPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058c18 : deploymentQueryRandomPointCatchMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeCatchEntry deploymentQueryRandomPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentQueryRandomPointCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentQueryRandomPointCatchContext) }
};

// R6Engine.dll data @ 10058c38 : deploymentQueryRandomPointTryMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeTryBlock deploymentQueryRandomPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentQueryRandomPointCatchMap) }
};

// R6Engine.dll data @ 10058c4c : deploymentQueryRandomPointFuncInfo
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentQueryRandomPointFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentQueryRandomPointUnwindMap), 0x1, ((uint)&deploymentQueryRandomPointTryMap), 0 };

// R6Engine.dll data @ 10058c68 : deploymentQueryPointInZoneUnwindMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeUnwindEntry deploymentQueryPointInZoneUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058c78 : deploymentQueryPointInZoneCatchMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeCatchEntry deploymentQueryPointInZoneCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentQueryPointInZoneCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentQueryPointInZoneCatchContext) }
};

// R6Engine.dll data @ 10058c98 : deploymentQueryPointInZoneTryMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeTryBlock deploymentQueryPointInZoneTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentQueryPointInZoneCatchMap) }
};

// R6Engine.dll data @ 10058cac : deploymentQueryPointInZoneFuncInfo
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentQueryPointInZoneFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentQueryPointInZoneUnwindMap), 0x1, ((uint)&deploymentQueryPointInZoneTryMap), 0 };

// R6Engine.dll data @ 10058cc8 : deploymentQueryClosestPointUnwindMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeUnwindEntry deploymentQueryClosestPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058cd8 : deploymentQueryClosestPointCatchMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeCatchEntry deploymentQueryClosestPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentQueryClosestPointCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentQueryClosestPointCatchContext) }
};

// R6Engine.dll data @ 10058cf8 : deploymentQueryClosestPointTryMap
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeTryBlock deploymentQueryClosestPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentQueryClosestPointCatchMap) }
};

// R6Engine.dll data @ 10058d0c : deploymentQueryClosestPointFuncInfo
// Retains exact query-bridge states/catches with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentQueryClosestPointFuncInfo = {
    0x19930520, 0x2, ((uint)&deploymentQueryClosestPointUnwindMap), 0x1, ((uint)&deploymentQueryClosestPointTryMap), 0
};

// R6Engine.dll data @ 10059194 : deploymentExecHaveTerroristUnwindMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeUnwindEntry deploymentExecHaveTerroristUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100591a4 : deploymentExecHaveTerroristCatchMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeCatchEntry deploymentExecHaveTerroristCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentExecHaveTerroristCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecHaveTerroristCatchContext) }
};

// R6Engine.dll data @ 100591c4 : deploymentExecHaveTerroristTryMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeTryBlock deploymentExecHaveTerroristTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentExecHaveTerroristCatchMap) }
};

// R6Engine.dll data @ 100591d8 : deploymentExecHaveTerroristFuncInfo
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeFunctionInfoPrefix deploymentExecHaveTerroristFuncInfo = {
    0x19930520, 0x2, ((uint)&deploymentExecHaveTerroristUnwindMap), 0x1, ((uint)&deploymentExecHaveTerroristTryMap), 0
};

// R6Engine.dll data @ 100591f4 : deploymentExecHaveHostageUnwindMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeUnwindEntry deploymentExecHaveHostageUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059204 : deploymentExecHaveHostageCatchMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeCatchEntry deploymentExecHaveHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentExecHaveHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecHaveHostageCatchContext) }
};

// R6Engine.dll data @ 10059224 : deploymentExecHaveHostageTryMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeTryBlock deploymentExecHaveHostageTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentExecHaveHostageCatchMap) }
};

// R6Engine.dll data @ 10059238 : deploymentExecHaveHostageFuncInfo
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeFunctionInfoPrefix deploymentExecHaveHostageFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentExecHaveHostageUnwindMap), 0x1, ((uint)&deploymentExecHaveHostageTryMap), 0 };

// R6Engine.dll data @ 10059254 : deploymentExecOrderTerroristsUnwindMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeUnwindEntry deploymentExecOrderTerroristsUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentExecOrderTerroristsState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005926c : deploymentExecOrderTerroristsCatchMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeCatchEntry deploymentExecOrderTerroristsCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentExecOrderTerroristsCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecOrderTerroristsCatchContext) }
};

// R6Engine.dll data @ 1005928c : deploymentExecOrderTerroristsTryMap
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeTryBlock deploymentExecOrderTerroristsTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&deploymentExecOrderTerroristsCatchMap) }
};

// R6Engine.dll data @ 100592a0 : deploymentExecOrderTerroristsFuncInfo
// Retains the exact script-bridge cleanup/catch states and native handler records.
const NativeFunctionInfoPrefix deploymentExecOrderTerroristsFuncInfo = {
    0x19930520, 0x3, ((uint)&deploymentExecOrderTerroristsUnwindMap), 0x1, ((uint)&deploymentExecOrderTerroristsTryMap),
        0
};

// R6Engine.dll data @ 10059068 : deploymentExecAddHostageUnwindMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeUnwindEntry deploymentExecAddHostageUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059078 : deploymentExecAddHostageCatchMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeCatchEntry deploymentExecAddHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DeploymentExecAddHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecAddHostageCatchContext) }
};

// R6Engine.dll data @ 10059098 : deploymentExecAddHostageTryMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeTryBlock deploymentExecAddHostageTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentExecAddHostageCatchMap) }
};

// R6Engine.dll data @ 100590ac : deploymentExecAddHostageFuncInfo
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentExecAddHostageFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentExecAddHostageUnwindMap), 0x1, ((uint)&deploymentExecAddHostageTryMap), 0 };

// R6Engine.dll data @ 100590c8 : deploymentExecClosestHostageUnwindMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeUnwindEntry deploymentExecClosestHostageUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100590d8 : deploymentExecClosestHostageCatchMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeCatchEntry deploymentExecClosestHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DeploymentExecClosestHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecClosestHostageCatchContext) }
};

// R6Engine.dll data @ 100590f8 : deploymentExecClosestHostageTryMap
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeTryBlock deploymentExecClosestHostageTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentExecClosestHostageCatchMap) }
};

// R6Engine.dll data @ 1005910c : deploymentExecClosestHostageFuncInfo
// Retains the exact script-bridge states/catches with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentExecClosestHostageFuncInfo = {
    0x19930520, 0x2, ((uint)&deploymentExecClosestHostageUnwindMap), 0x1, ((uint)&deploymentExecClosestHostageTryMap), 0
};

// R6Engine.dll data @ 10058fa8 : deploymentHaveTerroristUnwindMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeUnwindEntry deploymentHaveTerroristUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058fb8 : deploymentHaveTerroristCatchMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeCatchEntry deploymentHaveTerroristCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentHaveTerroristCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentHaveTerroristCatchContext) }
};

// R6Engine.dll data @ 10058fd8 : deploymentHaveTerroristTryMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeTryBlock deploymentHaveTerroristTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentHaveTerroristCatchMap) }
};

// R6Engine.dll data @ 10058fec : deploymentHaveTerroristFuncInfo
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentHaveTerroristFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentHaveTerroristUnwindMap), 0x1, ((uint)&deploymentHaveTerroristTryMap), 0 };

// R6Engine.dll data @ 10059008 : deploymentHaveHostageUnwindMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeUnwindEntry deploymentHaveHostageUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059018 : deploymentHaveHostageCatchMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeCatchEntry deploymentHaveHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DeploymentHaveHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentHaveHostageCatchContext) }
};

// R6Engine.dll data @ 10059038 : deploymentHaveHostageTryMap
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeTryBlock deploymentHaveHostageTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentHaveHostageCatchMap) }
};

// R6Engine.dll data @ 1005904c : deploymentHaveHostageFuncInfo
// Retains exact availability state/catch metadata with no local cleanup actions.
const NativeFunctionInfoPrefix deploymentHaveHostageFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentHaveHostageUnwindMap), 0x1, ((uint)&deploymentHaveHostageTryMap), 0 };

// R6Engine.dll data @ 10058f48 : deploymentRandomAreaUnwindMap
// Retains the exact random-area state/catch metadata; there are no local cleanup actions.
const NativeUnwindEntry deploymentRandomAreaUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058f58 : deploymentRandomAreaCatchMap
// Retains the exact random-area state/catch metadata; there are no local cleanup actions.
const NativeCatchEntry deploymentRandomAreaCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -124, ((uint)&DeploymentRandomAreaCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentRandomAreaCatchContext) }
};

// R6Engine.dll data @ 10058f78 : deploymentRandomAreaTryMap
// Retains the exact random-area state/catch metadata; there are no local cleanup actions.
const NativeTryBlock deploymentRandomAreaTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentRandomAreaCatchMap) }
};

// R6Engine.dll data @ 10058f8c : deploymentRandomAreaFuncInfo
// Retains the exact random-area state/catch metadata; there are no local cleanup actions.
const NativeFunctionInfoPrefix deploymentRandomAreaFuncInfo = { 0x19930520, 0x2, ((uint)&deploymentRandomAreaUnwindMap),
    0x1, ((uint)&deploymentRandomAreaTryMap), 0 };

// R6Engine.dll data @ 10058e60 : deploymentInitTerroristUnwindMap
// Retains the native completed-string states and exact cleanup entries.
const NativeUnwindEntry deploymentInitTerroristUnwindMap[6] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentInitTerroristState1Cleanup) },
    { 0, ((uint)&DeploymentInitTerroristState2Cleanup) },
    { 0, ((uint)&DeploymentInitTerroristState3Cleanup) },
    { 0, ((uint)&DeploymentInitTerroristState4Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10058e90 : deploymentInitTerroristCatchMap
// Binds unsigned-short-pointer and catch-all handlers.
const NativeCatchEntry deploymentInitTerroristCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentInitTerroristCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentInitTerroristCatchContext) }
};

// R6Engine.dll data @ 10058eb0 : deploymentInitTerroristTryMap
// Retains the exact guarded state range and two handler records.
const NativeTryBlock deploymentInitTerroristTryMap[1] = {
    { 0, 0x4, 0x5, 0x2, ((uint)&deploymentInitTerroristCatchMap) }
};

// R6Engine.dll data @ 10058ec4 : deploymentInitTerroristFuncInfo
// Binds the native AI initialization cleanup/catch maps.
const NativeFunctionInfoPrefix deploymentInitTerroristFuncInfo = { 0x19930520, 0x6,
    ((uint)&deploymentInitTerroristUnwindMap), 0x1, ((uint)&deploymentInitTerroristTryMap), 0 };

// R6Engine.dll data @ 10058ee0 : deploymentInitHostageUnwindMap
// Retains the native completed-string states and exact cleanup entries.
const NativeUnwindEntry deploymentInitHostageUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentInitHostageState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10058ef8 : deploymentInitHostageCatchMap
// Binds unsigned-short-pointer and catch-all handlers.
const NativeCatchEntry deploymentInitHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentInitHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentInitHostageCatchContext) }
};

// R6Engine.dll data @ 10058f18 : deploymentInitHostageTryMap
// Retains the exact guarded state range and two handler records.
const NativeTryBlock deploymentInitHostageTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&deploymentInitHostageCatchMap) }
};

// R6Engine.dll data @ 10058f2c : deploymentInitHostageFuncInfo
// Binds the native AI initialization cleanup/catch maps.
const NativeFunctionInfoPrefix deploymentInitHostageFuncInfo = { 0x19930520, 0x3,
    ((uint)&deploymentInitHostageUnwindMap), 0x1, ((uint)&deploymentInitHostageTryMap), 0 };

// R6Engine.dll data @ 10058e00 : deploymentPlacementUnwindMap
// Retains two predecessor states with no cleanup actions.
const NativeUnwindEntry deploymentPlacementUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058e10 : deploymentPlacementCatchMap
// Binds the unsigned-short-pointer and catch-all native handlers.
const NativeCatchEntry deploymentPlacementCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentPlacementCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentPlacementCatchContext) }
};

// R6Engine.dll data @ 10058e30 : deploymentPlacementTryMap
// Retains the guarded state range and its two catch handlers.
const NativeTryBlock deploymentPlacementTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentPlacementCatchMap) }
};

// R6Engine.dll data @ 10058e44 : deploymentPlacementFuncInfo
// Binds the native placement exception maps.
const NativeFunctionInfoPrefix deploymentPlacementFuncInfo = { 0x19930520, 0x2, ((uint)&deploymentPlacementUnwindMap),
    0x1, ((uint)&deploymentPlacementTryMap), 0 };

// R6Engine.dll data @ 10058d28 : deploymentRendererUnwindMap
// Retains icon retry-bit resets, batcher destruction and native predecessor states.
const NativeUnwindEntry deploymentRendererUnwindMap[5] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentRendererState1Cleanup) },
    { 0, ((uint)&DeploymentRendererState2Cleanup) },
    { 0, ((uint)&DeploymentRendererState3Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10058d50 : deploymentRendererCatchMap
// Binds the unsigned-short-pointer and catch-all native handlers.
const NativeCatchEntry deploymentRendererCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentRendererCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentRendererCatchContext) }
};

// R6Engine.dll data @ 10058d70 : deploymentRendererTryMap
// Retains guarded states0..3 and the two native catch handlers.
const NativeTryBlock deploymentRendererTryMap[1] = {
    { 0, 0x3, 0x4, 0x2, ((uint)&deploymentRendererCatchMap) }
};

// R6Engine.dll data @ 10058d84 : deploymentRendererFuncInfo
// Binds the native renderer cleanup and catch maps.
const NativeFunctionInfoPrefix deploymentRendererFuncInfo = { 0x19930520, 0x5, ((uint)&deploymentRendererUnwindMap),
    0x1, ((uint)&deploymentRendererTryMap), 0 };

// R6Engine.dll data @ 10058da0 : deploymentClosestPointUnwindMap
// Retains two predecessor states with no cleanup actions.
const NativeUnwindEntry deploymentClosestPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058db0 : deploymentClosestPointCatchMap
// Binds the unsigned-short-pointer and catch-all native handlers.
const NativeCatchEntry deploymentClosestPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -20, ((uint)&DeploymentClosestPointCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentClosestPointCatchContext) }
};

// R6Engine.dll data @ 10058dd0 : deploymentClosestPointTryMap
// Retains the guarded state range and its two catch handlers.
const NativeTryBlock deploymentClosestPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentClosestPointCatchMap) }
};

// R6Engine.dll data @ 10058de4 : deploymentClosestPointFuncInfo
// Binds the native closest-point exception maps.
const NativeFunctionInfoPrefix deploymentClosestPointFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentClosestPointUnwindMap), 0x1, ((uint)&deploymentClosestPointTryMap), 0 };

// R6Engine.dll data @ 10058a94 : deploymentSpawnedUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry deploymentSpawnedUnwindMap[5] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentSpawnedState1Cleanup) },
    { 0, ((uint)&DeploymentSpawnedState2Cleanup) },
    { 0, ((uint)&DeploymentSpawnedState3Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10058abc : deploymentSpawnedCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry deploymentSpawnedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentSpawnedCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentSpawnedCatchContext) }
};

// R6Engine.dll data @ 10058adc : deploymentSpawnedTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock deploymentSpawnedTryMap[1] = {
    { 0, 0x3, 0x4, 0x2, ((uint)&deploymentSpawnedCatchMap) }
};

// R6Engine.dll data @ 10058af0 : deploymentSpawnedFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DeploymentZone::Spawned.
const NativeFunctionInfoPrefix deploymentSpawnedFuncInfo = { 0x19930520, 0x5, ((uint)&deploymentSpawnedUnwindMap), 0x1,
    ((uint)&deploymentSpawnedTryMap), 0 };

// R6Engine.dll data @ 100581b4 : deploymentCopyUnwindMap
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeUnwindEntry deploymentCopyUnwindMap[6] = {
    { -1, ((uint)&DeploymentCopyState0Cleanup) },
    { 0, ((uint)&DeploymentCopyState1Cleanup) },
    { 0x1, ((uint)&DeploymentCopyState2Cleanup) },
    { 0x2, ((uint)&DeploymentCopyState3Cleanup) },
    { 0x3, ((uint)&DeploymentCopyState4Cleanup) },
    { 0x4, ((uint)&DeploymentCopyState5Cleanup) }
};

// R6Engine.dll data @ 100581e4 : deploymentCopyFuncInfo
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeFunctionInfoPrefix deploymentCopyFuncInfo = { 0x19930520, 0x6, ((uint)&deploymentCopyUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058104 : deploymentDestructionUnwindMap
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeUnwindEntry deploymentDestructionUnwindMap[8] = {
    { -1, ((uint)&DeploymentDestructionState0Cleanup) },
    { 0, ((uint)&DeploymentDestructionState1Cleanup) },
    { 0x1, ((uint)&DeploymentDestructionState2Cleanup) },
    { 0x2, ((uint)&DeploymentDestructionState3Cleanup) },
    { 0x3, ((uint)&DeploymentDestructionState4Cleanup) },
    { 0x4, ((uint)&DeploymentDestructionState5Cleanup) },
    { 0x5, ((uint)&DeploymentDestructionState6Cleanup) },
    { 0x6, ((uint)&DeploymentDestructionState7Cleanup) }
};

// R6Engine.dll data @ 10058144 : deploymentDestructionFuncInfo
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeFunctionInfoPrefix deploymentDestructionFuncInfo = { 0x19930520, 0x8,
    ((uint)&deploymentDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058160 : deploymentDefaultUnwindMap
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeUnwindEntry deploymentDefaultUnwindMap[7] = {
    { -1, ((uint)&DeploymentDefaultState0Cleanup) },
    { 0, ((uint)&DeploymentDefaultState1Cleanup) },
    { 0x1, ((uint)&DeploymentDefaultState2Cleanup) },
    { 0x2, ((uint)&DeploymentDefaultState3Cleanup) },
    { 0x3, ((uint)&DeploymentDefaultState4Cleanup) },
    { 0x4, ((uint)&DeploymentDefaultState5Cleanup) },
    { 0x5, ((uint)&DeploymentDefaultState6Cleanup) }
};

// R6Engine.dll data @ 10058198 : deploymentDefaultFuncInfo
// Retains exact completed-member/base cleanup states with no catch handlers.
const NativeFunctionInfoPrefix deploymentDefaultFuncInfo = { 0x19930520, 0x7, ((uint)&deploymentDefaultUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 10058b0c : deploymentValidateTemplatesUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry deploymentValidateTemplatesUnwindMap[4] = {
    { -1, ((uint)&DeploymentValidateTemplatesState0Cleanup) },
    { -1, ((uint)&DeploymentValidateTemplatesState1Cleanup) },
    { -1, ((uint)&DeploymentValidateTemplatesState2Cleanup) },
    { -1, ((uint)&DeploymentValidateTemplatesState3Cleanup) }
};

// R6Engine.dll data @ 10058b2c : deploymentValidateTemplatesFuncInfo
// Binds the selected MSVC cleanup/catch maps for CheckForErrors(bool).
const NativeFunctionInfoPrefix deploymentValidateTemplatesFuncInfo = { 0x19930520, 0x4,
    ((uint)&deploymentValidateTemplatesUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058b48 : deploymentTerroristCountUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry deploymentTerroristCountUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058b58 : deploymentTerroristCountCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry deploymentTerroristCountCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentTerroristCountCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentTerroristCountCatchContext) }
};

// R6Engine.dll data @ 10058b78 : deploymentTerroristCountTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock deploymentTerroristCountTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentTerroristCountCatchMap) }
};

// R6Engine.dll data @ 10058b8c : deploymentTerroristCountFuncInfo
// Binds the selected MSVC cleanup/catch maps for GetNbOfTerroristToSpawn.
const NativeFunctionInfoPrefix deploymentTerroristCountFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentTerroristCountUnwindMap), 0x1, ((uint)&deploymentTerroristCountTryMap), 0 };

// R6Engine.dll data @ 10058ba8 : deploymentExecFirstInitUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry deploymentExecFirstInitUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10058bb8 : deploymentExecFirstInitCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry deploymentExecFirstInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DeploymentExecFirstInitCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentExecFirstInitCatchContext) }
};

// R6Engine.dll data @ 10058bd8 : deploymentExecFirstInitTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock deploymentExecFirstInitTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentExecFirstInitCatchMap) }
};

// R6Engine.dll data @ 10058bec : deploymentExecFirstInitFuncInfo
// Binds the selected MSVC cleanup/catch maps for execFirstInit.
const NativeFunctionInfoPrefix deploymentExecFirstInitFuncInfo = { 0x19930520, 0x2,
    ((uint)&deploymentExecFirstInitUnwindMap), 0x1, ((uint)&deploymentExecFirstInitTryMap), 0 };

// R6Engine.dll data @ 100593e8 : deploymentFirstInitUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry deploymentFirstInitUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100593f8 : deploymentFirstInitCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry deploymentFirstInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DeploymentFirstInitCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentFirstInitCatchContext) }
};

// R6Engine.dll data @ 10059418 : deploymentFirstInitTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock deploymentFirstInitTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&deploymentFirstInitCatchMap) }
};

// R6Engine.dll data @ 1005942c : deploymentFirstInitFuncInfo
// Binds FirstInit to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix deploymentFirstInitFuncInfo = { 0x19930520, 0x2, ((uint)&deploymentFirstInitUnwindMap),
    0x1, ((uint)&deploymentFirstInitTryMap), 0 };

// Routes FirstInit through its selected C++ exception metadata.
__declspec(naked) void __cdecl DeploymentZoneFirstInitExceptionHandler(void);

// R6Engine.dll data @ 100592e8 : deploymentSpawnHostageUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry deploymentSpawnHostageUnwindMap[6] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentSpawnHostageState1Cleanup) },
    { 0, ((uint)&DeploymentSpawnHostageState2Cleanup) },
    { 0x2, ((uint)&DeploymentSpawnHostageState3Cleanup) },
    { 0x3, ((uint)&DeploymentSpawnHostageState4Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10059318 : deploymentSpawnHostageCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry deploymentSpawnHostageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&DeploymentSpawnHostageCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentSpawnHostageCatchContext) }
};

// R6Engine.dll data @ 10059338 : deploymentSpawnHostageTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock deploymentSpawnHostageTryMap[1] = {
    { 0, 0x4, 0x5, 0x2, ((uint)&deploymentSpawnHostageCatchMap) }
};

// R6Engine.dll data @ 1005934c : deploymentSpawnHostageFuncInfo
// Binds SpawnAHostage to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix deploymentSpawnHostageFuncInfo = { 0x19930520, 0x6,
    ((uint)&deploymentSpawnHostageUnwindMap), 0x1, ((uint)&deploymentSpawnHostageTryMap), 0 };

// R6Engine.dll data @ 10059368 : deploymentSpawnTerroristUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry deploymentSpawnTerroristUnwindMap[6] = {
    { -1, 0 },
    { 0, ((uint)&DeploymentSpawnTerroristState1Cleanup) },
    { 0, ((uint)&DeploymentSpawnTerroristState2Cleanup) },
    { 0x2, ((uint)&DeploymentSpawnTerroristState3Cleanup) },
    { 0x3, ((uint)&DeploymentSpawnTerroristState4Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10059398 : deploymentSpawnTerroristCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry deploymentSpawnTerroristCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -84, ((uint)&DeploymentSpawnTerroristCatchPointer) },
    { 0, 0, 0, ((uint)&DeploymentSpawnTerroristCatchContext) }
};

// R6Engine.dll data @ 100593b8 : deploymentSpawnTerroristTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock deploymentSpawnTerroristTryMap[1] = {
    { 0, 0x4, 0x5, 0x2, ((uint)&deploymentSpawnTerroristCatchMap) }
};

// R6Engine.dll data @ 100593cc : deploymentSpawnTerroristFuncInfo
// Binds SpawnATerrorist to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix deploymentSpawnTerroristFuncInfo = { 0x19930520, 0x6,
    ((uint)&deploymentSpawnTerroristUnwindMap), 0x1, ((uint)&deploymentSpawnTerroristTryMap), 0 };

// Routes SpawnAHostage through its selected C++ exception metadata.
__declspec(naked) void __cdecl DeploymentZoneSpawnAHostageExceptionHandler(void);
// Routes SpawnATerrorist through its selected C++ exception metadata.
__declspec(naked) void __cdecl DeploymentZoneSpawnATerroristExceptionHandler(void);

// R6Engine.dll data @ 100743f8 : intAR6DeploymentZoneexecGetClosestHostage
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecGetClosestHostage = (Native)&AR6DeploymentZone::execGetClosestHostage;

// R6Engine.dll data @ 10080d18 : AR6DeploymentZoneGetClosestHostageRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneGetClosestHostageRegistrationResult = 0;

// R6Engine.dll data @ 100743fc : intAR6DeploymentZoneexecOrderTerroListFromDistanceTo
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecOrderTerroListFromDistanceTo =
    (Native)&AR6DeploymentZone::execOrderTerroListFromDistanceTo;

// R6Engine.dll data @ 10076eb8 : AR6DeploymentZoneOrderTerroListFromDistanceToRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneOrderTerroListFromDistanceToRegistrationResult = 0;

// R6Engine.dll data @ 10074400 : intAR6DeploymentZoneexecAddHostage
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecAddHostage = (Native)&AR6DeploymentZone::execAddHostage;

// R6Engine.dll data @ 100769a0 : AR6DeploymentZoneAddHostageRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneAddHostageRegistrationResult = 0;

// R6Engine.dll data @ 10074404 : intAR6DeploymentZoneexecHaveHostage
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecHaveHostage = (Native)&AR6DeploymentZone::execHaveHostage;

// R6Engine.dll data @ 10080d1c : AR6DeploymentZoneHaveHostageRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneHaveHostageRegistrationResult = 0;

// R6Engine.dll data @ 10074408 : intAR6DeploymentZoneexecHaveTerrorist
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecHaveTerrorist = (Native)&AR6DeploymentZone::execHaveTerrorist;

// R6Engine.dll data @ 100830bc : AR6DeploymentZoneHaveTerroristRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneHaveTerroristRegistrationResult = 0;

// R6Engine.dll data @ 1007440c : intAR6DeploymentZoneexecFindClosestPointTo
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecFindClosestPointTo = (Native)&AR6DeploymentZone::execFindClosestPointTo;

// R6Engine.dll data @ 1007df28 : AR6DeploymentZoneFindClosestPointToRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneFindClosestPointToRegistrationResult = 0;

// R6Engine.dll data @ 10074410 : intAR6DeploymentZoneexecIsPointInZone
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecIsPointInZone = (Native)&AR6DeploymentZone::execIsPointInZone;

// R6Engine.dll data @ 1007ee6c : AR6DeploymentZoneIsPointInZoneRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneIsPointInZoneRegistrationResult = 0;

// R6Engine.dll data @ 10074414 : intAR6DeploymentZoneexecFindRandomPointInArea
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecFindRandomPointInArea = (Native)&AR6DeploymentZone::execFindRandomPointInArea;

// R6Engine.dll data @ 10077e01 : AR6DeploymentZoneFindRandomPointInAreaRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneFindRandomPointInAreaRegistrationResult = 0;

// R6Engine.dll data @ 10074418 : intAR6DeploymentZoneexecFirstInit
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6DeploymentZoneexecFirstInit = (Native)&AR6DeploymentZone::execFirstInit;

// R6Engine.dll data @ 1007fdc8 : AR6DeploymentZoneFirstInitRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6DeploymentZoneFirstInitRegistrationResult = 0;

// R6Engine.dll data @ 1007c568 : autoclassAR6DeploymentZone
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DeploymentZone = nullptr;

// R6Engine.dll @ 10009660 : AR6DeploymentZone::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DeploymentZone::StaticClass(void)
{
    return &AR6DeploymentZone::PrivateStaticClass; // Selected object at0x100802f8.
}

// R6Engine.dll @ 10009670 : AR6DeploymentZone::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DeploymentZone::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DeploymentZone::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100096a0 : FindSpawningPoint
// Forwards the hidden Vector result to the virtual at vtable offset 0x18c and returns that result pointer.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DeploymentZone::FindSpawningPoint(FVector* resultLocation, FRotator* unusedRotation,
    int* unusedInteger0, EStance* unusedStance, int* unusedInteger1)
{
    using RandomPointCall = FVector* (__thiscall *)(AR6DeploymentZone*, FVector*);
    RandomPointCall findRandomPoint = *(RandomPointCall*)(*(byte**)this + 0x18c);
    findRandomPoint(this, resultLocation);
    return resultLocation;
}

// R6Engine.dll @ 1000ff50 : AR6DeploymentZone::operator=
// Assigns scalar settings, individual flag bits, five arrays and both fixed template lists in native order.
AR6DeploymentZone& AR6DeploymentZone::operator=(const AR6DeploymentZone& source)
{
    AActor::operator=(source);
    reinterpret_cast<byte&>(m_eDefCon) = reinterpret_cast<const byte&>(source.m_eDefCon);
    // Preserve padding at +0x396..+0x397.
    reinterpret_cast<byte&>(m_eEngageReaction) = reinterpret_cast<const byte&>(source.m_eEngageReaction);
    m_iGroupID = source.m_iGroupID;
    m_HostageShootChance = source.m_HostageShootChance;
    m_iMinTerrorist = source.m_iMinTerrorist;
    m_iMaxTerrorist = source.m_iMaxTerrorist;
    m_iChanceToUseGrenadeAtFirstReaction = source.m_iChanceToUseGrenadeAtFirstReaction;
    m_iMinHostage = source.m_iMinHostage;
    int maxHostage = source.m_iMaxHostage;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3b8);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(&source) + 0x3b8);
    uint earlyFlags = *destinationFlags; // Native loads this before storing MaxHostage and copying PrisonerTeam.
    m_iMaxHostage = maxHostage;
    m_iPrisonerTeam = source.m_iPrisonerTeam;
    uint sourceWord = *sourceFlags;
    uint flags = *destinationFlags;
    flags ^= (sourceWord ^ earlyFlags) & 1U; // m_bDontSeePlayer; preserve the separate early/current reads.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bDontHearPlayer.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bHearNothing.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 8U; // m_bAllowLeave.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x10U; // m_bPreventCrouching.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x20U; // m_bKnowInPlanning.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x40U; // m_bHuntDisallowed.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x80U; // m_bHuntFromStart.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x100U; // m_bAlreadyInitialized.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x200U; // m_bUseGrenade.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x400U; // m_bClassicMissionCivilian.
    *destinationFlags = flags;
    m_InteractiveObject = source.m_InteractiveObject;
    AssignRecords4((FArray*)&m_iGroupIDsToCall, (const FArray*)&source.m_iGroupIDsToCall);
    AssignRecords4((FArray*)&m_HostageZoneToCheck, (const FArray*)&source.m_HostageZoneToCheck);
    AssignRecords4((FArray*)&m_pListOfCoverNodes, (const FArray*)&source.m_pListOfCoverNodes);
    AssignRecords4((FArray*)&m_aTerrorist, (const FArray*)&source.m_aTerrorist);
    AssignRecords4((FArray*)&m_aHostage, (const FArray*)&source.m_aHostage);
    for (uint index = 0; index < 5; ++index) {
        m_Template[index].m_szName = source.m_Template[index].m_szName;
        m_Template[index].m_iChance = source.m_Template[index].m_iChance; // Read after the string callback.
    }
    for (uint index = 0; index < 5; ++index) {
        m_HostageTemplates[index].m_szName = source.m_HostageTemplates[index].m_szName;
        m_HostageTemplates[index].m_iChance = source.m_HostageTemplates[index].m_iChance;
    }
    return *this; // No self-assignment shortcut, local unwind scope or rollback is present.
}

// R6Engine.dll @ 10012520 : AR6DeploymentZone::~AR6DeploymentZone
// Runs ConditionalDestroy, then destroys both template arrays, five ordinary arrays and the Actor base on all exits.
AR6DeploymentZone::~AR6DeploymentZone()
{
    // Compiler installs vtable1004d2c8; states7..0 retain pending template/array/base cleanup before each native call.
    UObject::ConditionalDestroy(); // Ignore its int result; implicit members unwind in reverse declaration order.
    // HostageTemplates44c then Template3fc use five 16-byte elements and FString callback100096c0.
    // Arrays3f0/3e4/3d8/3cc/3c0 use1000e970 before imported AActor destruction, including exceptional exits.
}

// R6Engine.dll @ 10012600 : AR6DeploymentZone::AR6DeploymentZone(void)
// Constructs Actor, registers five no-write array lifetimes, then default-constructs both fixed template lists.
AR6DeploymentZone::AR6DeploymentZone()
    : AActor(), m_iGroupIDsToCall(E_NoInit), m_HostageZoneToCheck(E_NoInit), m_pListOfCoverNodes(E_NoInit),
      m_aTerrorist(E_NoInit), m_aHostage(E_NoInit)
{
    // E_NoInit is a UE2 spelling for observed no-header-write construction, not a recovered original initializer.
    // Compiler installs vtable1004d2c8 after Actor; scalars, flags and all five array headers retain input storage.
    // Omitted template initializers mean default initialization: five leading strings each, chance words untouched.
    // Native1004286c uses ConstructFirstString/100096c0; failed current prefix unwinds inside that helper.
    // States5/6 clean completed arrays and then Actor; native EAX is the original receiver.
}

// R6Engine.dll @ 10012690 : AR6DeploymentZone::AR6DeploymentZone(const AR6DeploymentZone&)
// Copies settings and owned arrays while retaining the native delayed guard and unregistered fixed-template lists.
// Native ABI view preserves explicit no-init/owned-array lifetimes and native cleanup coverage.
AR6DeploymentZone* __thiscall AR6DeploymentZone::AR6DeploymentZone(AR6DeploymentZone* object,
    const AR6DeploymentZone* source)
{
    using CopyActor = AActor* (__thiscall*)(AActor*, const AActor*);
    reinterpret_cast<CopyActor&>(AActorCopyConstructorImport)(object, source);
    *(void**)object = (void*)&AR6DeploymentZoneVirtualTable;
    reinterpret_cast<byte&>(object->m_eDefCon) = reinterpret_cast<const byte&>(source->m_eDefCon);
    reinterpret_cast<byte&>(object->m_eEngageReaction) = reinterpret_cast<const byte&>(source->m_eEngageReaction);
    object->m_iGroupID = source->m_iGroupID;
    object->m_HostageShootChance = source->m_HostageShootChance;
    object->m_iMinTerrorist = source->m_iMinTerrorist;
    object->m_iMaxTerrorist = source->m_iMaxTerrorist;
    object->m_iChanceToUseGrenadeAtFirstReaction = source->m_iChanceToUseGrenadeAtFirstReaction;
    object->m_iMinHostage = source->m_iMinHostage;
    int maxHostage = source->m_iMaxHostage;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(object) + 0x3b8);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3b8);
    uint earlyFlags = *destinationFlags;
    object->m_iMaxHostage = maxHostage;
    object->m_iPrisonerTeam = source->m_iPrisonerTeam;
    uint sourceWord = *sourceFlags;
    uint flags = *destinationFlags;
    flags ^= (sourceWord ^ earlyFlags) & 1U; // m_bDontSeePlayer.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bDontHearPlayer.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bHearNothing.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 8U; // m_bAllowLeave.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x10U; // m_bPreventCrouching.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x20U; // m_bKnowInPlanning.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x40U; // m_bHuntDisallowed.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x80U; // m_bHuntFromStart.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x100U; // m_bAlreadyInitialized.
    *destinationFlags = flags;
    uint grenadeDifference = *sourceFlags ^ flags; // Still state-1 through this source read and XOR.
    // Local reference view of native states0..5, not a recovered native type or compiler frame layout.
    struct PendingCopyCleanup {
        AR6DeploymentZone* object;
        uint completedArrays;
        bool active;
        // Unwinds only completed ordinary arrays and Actor; no fixed-template list is registered by this parent.
        ~PendingCopyCleanup() noexcept(false)
        {
            if (!active) return;
            while (completedArrays != 0) {
                --completedArrays;
                FArray* array = (FArray*)((byte*)object + 0x3c0 + 12U * completedArrays);
                ForwardWordArrayDestruction(array);
            }
            using DestroyActor = void (__thiscall*)(AActor*);
            (*(DestroyActor*)&AActorDestructorImport)((AActor*)object);
        }
    } cleanup{object, 0, true}; // Native state0 starts here, before the grenade bit merge/store.
    flags ^= grenadeDifference & 0x200U; // m_bUseGrenade.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 0x400U; // m_bClassicMissionCivilian.
    *destinationFlags = flags;
    object->m_InteractiveObject = source->m_InteractiveObject;
    CopyConstructWordsDirect((FArray*)&object->m_iGroupIDsToCall, (const FArray*)&source->m_iGroupIDsToCall);
    cleanup.completedArrays = 1;
    CopyConstructRecords4((FArray*)&object->m_HostageZoneToCheck,
        (const FArray*)&source->m_HostageZoneToCheck);
    cleanup.completedArrays = 2;
    CopyConstructRecords4((FArray*)&object->m_pListOfCoverNodes, (const FArray*)&source->m_pListOfCoverNodes);
    cleanup.completedArrays = 3;
    CopyConstructRecords4((FArray*)&object->m_aTerrorist, (const FArray*)&source->m_aTerrorist);
    cleanup.completedArrays = 4;
    CopyConstructRecords4((FArray*)&object->m_aHostage, (const FArray*)&source->m_aHostage);
    cleanup.completedArrays = 5;
    using CopyElement = void* (__thiscall*)(void*, const void*);
    using DestroyElement = void (__thiscall*)(void*);
    using CopyArray = void (__stdcall*)(void*, const void*, uint, int, CopyElement, DestroyElement);
    CopyArray copyArray = (CopyArray)&_eh_vector_copy_constructor_iterator_;
    copyArray(&object->m_Template, &source->m_Template, 16, 5,
        ConstructTemplateCopy, (DestroyElement)&FStringDestructorNativeEntry);
    copyArray(&object->m_HostageTemplates, &source->m_HostageTemplates, 16, 5,
        // Both calls retain only state5 ordinary cleanup.
        ConstructTemplateCopy, (DestroyElement)&FStringDestructorNativeEntry);
    cleanup.active = false;
    return object; // Iterator owns its failed prefix; completed template lists get no parent cleanup action.
}

// R6Engine.dll @ 10013a80 : AR6DeploymentZone::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DeploymentZone::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DeploymentZoneConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10016b20 : AR6DeploymentZone::Spawned
// Assigns the three default template names, destroying each temporary before committing its chance value.
void __thiscall AR6DeploymentZone::Spawned(void)
{
    AR6DeploymentZone* zone = this;
    using DestroyString = void (__thiscall*)(FString*);
    // Reference view of each native temporary cleanup, not a recovered type or compiler-frame layout.
    struct PendingTemporary {
        FString* temporary;
        bool active;
        // Destroys the original temporary slot if assignment escapes, regardless of the constructor's returned pointer.
        ~PendingTemporary() noexcept(false)
        {
            if (active) (*(DestroyString*)&FStringDestructorImport)(temporary);
        }
    };
    alignas(FString) byte temporaryStorage[sizeof(FString)]; // One native EBP-0x24 slot reused three times.
    FString* temporary = (FString*)temporaryStorage;
    try {
        {
            FString* value = ::new (temporary) FString((const ushort*)L"Normal");
            PendingTemporary cleanup{temporary, true}; // State1 only after successful construction.
            zone->m_Template[0].m_szName = *value;
            cleanup.active = false;
            // State0 before destruction; no retry if it throws.
            temporary->FString::~FString();
        }
        zone->m_Template[0].m_iChance = 100;
        {
            FString* value = ::new (temporary) FString((const ushort*)L"NormalHostage");
            PendingTemporary cleanup{temporary, true}; // State2, with the same physical temporary storage.
            zone->m_HostageTemplates[0].m_szName = *value;
            cleanup.active = false;
            temporary->FString::~FString();
        }
        zone->m_HostageTemplates[0].m_iChance = 100;
        {
            FString* value = ::new (temporary) FString((const ushort*)L"NormalCivilian");
            PendingTemporary cleanup{temporary, true}; // State3; other template records are untouched.
            zone->m_HostageTemplates[1].m_szName = *value;
            cleanup.active = false;
            temporary->FString::~FString();
        }
        zone->m_HostageTemplates[1].m_iChance = 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::Spawned");
        throw;
    }
}

// R6Engine.dll @ 10016bf1 : DeploymentSpawnedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnedCatchPointer(void)
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

// R6Engine.dll @ 10016c30 : AR6DeploymentZone::getChanceFromArrayTemplates
// Sums template chance words, asserting that the requested count does not exceed five.
int __thiscall AR6DeploymentZone::getChanceFromArrayTemplates(FSTTemplate* templates, int sizeOfArray)
{
    const int requestedCount = sizeOfArray; // Captured before the assertion callback.
    if (requestedCount > 5)
        appFailAssert("sizeOfArray <= UCONST_C_NB_Template", ".\\Src\\AR6DeploymentZone.cpp", 0x58);
    uint chanceTotal = 0;
    if (requestedCount > 0) {
        uint chanceCursorAddress = (uint)templates + 0xcU; // STTemplate.m_iChance.
        int remainingCount = requestedCount;
        do {
            chanceTotal += *(const uint*)chanceCursorAddress;
            chanceCursorAddress += 0x10U;
            --remainingCount;
        } while (remainingCount != 0);
    }
    return (int)chanceTotal;
}

// R6Engine.dll @ 10016c70 : AR6DeploymentZone::CheckForErrors(bool)
// Reports invalid weight totals and ranges through map-check or runtime messages without correcting the zone.
void __thiscall AR6DeploymentZone::CheckForErrors(bool editorCheck)
{
    AR6DeploymentZone* zone = this;
    // Native cleanup-only FuncInfo10058b2c has four separate formatted-string lifetimes, with no catch/report scope.
    using FormatCall = FString (__cdecl *)(const ushort*, ...);
    using MapCheckCall = void (__thiscall *)(FFeedbackContext*, int, UObject*, const ushort*);
    // Five STTemplate rows have name at0 and chance at+0xc, stride0x10.
    uint chance3 = (uint)zone->m_Template[3].m_iChance;
    uint chance2 = (uint)zone->m_Template[2].m_iChance;
    uint chance1 = (uint)zone->m_Template[1].m_iChance;
    uint chance0 = (uint)zone->m_Template[0].m_iChance;
    uint total = (uint)zone->m_Template[4].m_iChance;
    total += chance3;
    // Cache before reporting; reuse across all editor diagnostics.
    FormatCall format = reinterpret_cast<FormatCall&>(FStringPrintfImport);
    total += chance2;
    total += chance1;
    total += chance0;
    if (total != 100 && total != 0) {
        bool useMapCheck = *(const volatile byte*)&editorCheck != 0;
        const ushort* zoneName = zone->UObject::GetName();
        if (useMapCheck) {
            FString text = format((const ushort*)L"Total template chance of TERRORIST is %d%% in %s",
                (int)total, zoneName);
            FFeedbackContext* warn = **(FFeedbackContext***)&CoreGWarnImport;
            byte* warnTable = *(byte**)warn;
            const ushort* detail = *text;
            MapCheckCall report = *(MapCheckCall*)(warnTable + 0x28);
            report(warn, 0, zone, detail);
        } else {
            appMsgf(0, (const ushort*)L"Total template chance of TERRORIST is %d%% in %s", (int)total, zoneName);
        }
    }
    total = (uint)zone->m_HostageTemplates[4].m_iChance;
    chance3 = (uint)zone->m_HostageTemplates[3].m_iChance;
    chance2 = (uint)zone->m_HostageTemplates[2].m_iChance;
    chance1 = (uint)zone->m_HostageTemplates[1].m_iChance;
    chance0 = (uint)zone->m_HostageTemplates[0].m_iChance;
    total += chance3;
    total += chance2;
    total += chance1;
    total += chance0;
    if (total != 100 && total != 0) {
        bool useMapCheck = *(const volatile byte*)&editorCheck != 0;
        const ushort* zoneName = zone->UObject::GetName();
        if (useMapCheck) {
            FString text = format((const ushort*)L"Total template chance of HOSTAGE is %d%% in %s",
                (int)total, zoneName);
            FFeedbackContext* warn = **(FFeedbackContext***)&CoreGWarnImport;
            byte* warnTable = *(byte**)warn;
            const ushort* detail = *text;
            MapCheckCall report = *(MapCheckCall*)(warnTable + 0x28);
            report(warn, 0, zone, detail);
        } else {
            appMsgf(0, (const ushort*)L"Total template chance of HOSTAGE is %d%% in %s", (int)total, zoneName);
        }
    }
    int minimum = zone->m_iMinTerrorist;
    if (minimum < 0 || zone->m_iMaxTerrorist < minimum) {
        bool useMapCheck = *(const volatile byte*)&editorCheck != 0;
        const ushort* zoneName = zone->UObject::GetName();
        if (useMapCheck) {
            int maximum = zone->m_iMaxTerrorist;
            minimum = zone->m_iMinTerrorist;
            // The editor path deliberately retains the native HOSTAGE label for the terrorist range.
            FString text = format((const ushort*)L"Template min max of HOSTAGE is wrong (min=%d%% max=%d%%) in %s",
                minimum, maximum, zoneName);
            FFeedbackContext* warn = **(FFeedbackContext***)&CoreGWarnImport;
            byte* warnTable = *(byte**)warn;
            const ushort* detail = *text;
            MapCheckCall report = *(MapCheckCall*)(warnTable + 0x28);
            report(warn, 0, zone, detail);
        } else {
            minimum = zone->m_iMinTerrorist;
            int maximum = zone->m_iMaxTerrorist;
            appMsgf(0, (const ushort*)L"Template min max of TERRORIST is wrong (min=%d%% max=%d%%) in %s",
                minimum, maximum, zoneName);
        }
    }
    minimum = zone->m_iMinHostage;
    if (minimum < 0 || zone->m_iMaxHostage < minimum) {
        bool useMapCheck = *(const volatile byte*)&editorCheck != 0;
        const ushort* zoneName = zone->UObject::GetName();
        if (useMapCheck) {
            int maximum = zone->m_iMaxHostage;
            minimum = zone->m_iMinHostage;
            FString text = format((const ushort*)L"Template min max of HOSTAGE is wrong (min=%d%% max=%d%%) in %s",
                minimum, maximum, zoneName);
            FFeedbackContext* warn = **(FFeedbackContext***)&CoreGWarnImport;
            byte* warnTable = *(byte**)warn;
            const ushort* detail = *text;
            MapCheckCall report = *(MapCheckCall*)(warnTable + 0x28);
            report(warn, 0, zone, detail);
        } else {
            minimum = zone->m_iMinHostage;
            int maximum = zone->m_iMaxHostage;
            appMsgf(0, (const ushort*)L"Template min max of HOSTAGE is wrong (min=%d%% max=%d%%) in %s",
                minimum, maximum, zoneName);
        }
    }
}

// R6Engine.dll @ 10016f40 : AR6DeploymentZone::GetNbOfTerroristToSpawn
// Lets the game-type event suppress spawning; otherwise returns the captured minimum plus a signed random remainder.
int __thiscall AR6DeploymentZone::GetNbOfTerroristToSpawn(void)
{
    AR6DeploymentZone* zone = this;
    using CountOverrideCall = uint (__thiscall *)(ALevelInfo*, const FString&);
    ALevelInfo* level = zone->Level;
    const FString& gameType = level->Game->m_szGameTypeFlag;
    // The native two-state catch scope begins after obtaining the level/game/type argument.
    try {
        CountOverrideCall overrideCount =
            reinterpret_cast<CountOverrideCall&>(ALevelInfoEventGameTypeUseNbOfTerroristToSpawnImport);
        if (overrideCount(level, gameType) != 0) return 0;
        int minimum = zone->m_iMinTerrorist;
        if (zone->m_iMaxTerrorist <= minimum) return minimum;
        int randomValue = appRand();
        uint range = (uint)zone->m_iMaxTerrorist;
        range -= (uint)zone->m_iMinTerrorist;
        range += 1;
        int divisor = (int)range;
        int remainder;
        __asm {
            mov eax,randomValue
            cdq
            idiv divisor
            mov remainder,edx
        }
        return (int)((uint)minimum + (uint)remainder);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::GetNbOfTerroristToSpawn");
        throw;
    }
}

// R6Engine.dll @ 10016fd2 : DeploymentTerroristCountCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentTerroristCountCatchPointer(void)
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

// R6Engine.dll @ 10017010 : AR6DeploymentZone::execFirstInit
// Skips parameter end, handles optional debug bytecode and dispatches FirstInit without writing a result.
void __thiscall AR6DeploymentZone::execFirstInit(FFrame& stack, void* const unusedResult)
{
    AR6DeploymentZone* zone = this;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** code = &stack.Code;
    byte* next = *code + 1;
    *code = next;
    bool hasDebugToken = *next == 0x42;
    // The native guarded state starts after advancing Code and testing the following byte.
    try {
        if (hasDebugToken) {
            UObject* debugReceiver = stack.Object;
            *code = next + 1;
            ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
            natives[0x42](debugReceiver, &stack, nullptr);
        }
        zone->FirstInit();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execFirstInit");
        throw;
    }
}

// R6Engine.dll @ 1001707b : DeploymentExecFirstInitCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecFirstInitCatchPointer(void)
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

// R6Engine.dll @ 100170b0 : AR6DeploymentZone::execFindRandomPointInArea
// Handles optional debug bytecode and copies the virtual random-point result in three interleaved raw-word steps.
void __thiscall AR6DeploymentZone::execFindRandomPointInArea(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    using FindPointCall = FVector* (__thiscall*)(AR6DeploymentZone*, FVector*);
    byte* code = frame.Code + 1;
    frame.Code = code;
    bool hasDebug = *code == 0x42; // Native state-1 includes the initial cursor advance/store and byte probe.
    try {
        if (hasDebug) {
            UObject* context = frame.Object;
            frame.Code = code + 1;
            NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        byte* table = *(byte**)zone;
        FVector storage; // Native hidden output is not preinitialized.
        FindPointCall findPoint = *(FindPointCall*)(table + 0x18c);
        const uint* returned = (const uint*)findPoint(zone, &storage);
        uint firstWord = returned[0]; // Consumes EAX, which may point outside the supplied output storage.
        uint* destination = (uint*)result;
        destination[0] = firstWord;
        destination[1] = returned[1];
        destination[2] = returned[2]; // Preserve overlapping source/destination behavior; no FVector snapshot copy.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execFindRandomPointInArea");
        throw;
    }
}

// R6Engine.dll @ 10017170 : AR6DeploymentZone::execIsPointInZone
// Evaluates vPoint and optional debug bytecode, then stores only the containment result low byte.
void __thiscall AR6DeploymentZone::execIsPointInZone(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    FVector vPoint; // Native vector argument storage is not preinitialized.
    byte* code = frame.Code;
    byte opcode = *code;
    frame.Code = code + 1;
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* context = frame.Object;
    try { // State0 starts after the cursor/table/Object preparation, before the captured-table slot lookup.
        natives[opcode](context, &frame, &vPoint);
        code = frame.Code + 1;
        frame.Code = code;
        if (*code == 0x42) {
            context = frame.Object;
            frame.Code = code + 1;
            natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        int value = zone->IsPointInZone(vPoint);
        *(byte*)result = (byte)value; // Native MOV BYTE copies AL without normalizing or clearing upper result bytes.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execIsPointInZone");
        throw;
    }
}

// R6Engine.dll @ 10017240 : AR6DeploymentZone::execFindClosestPointTo
// Evaluates vPoint and optional debug bytecode, then copies the returned closest-point words in native order.
void __thiscall AR6DeploymentZone::execFindClosestPointTo(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    FVector vPoint; // Native vector argument storage is not preinitialized.
    byte* code = frame.Code;
    byte opcode = *code;
    frame.Code = code + 1;
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* context = frame.Object;
    try { // State0 starts after the cursor/table/Object preparation, before the captured-table slot lookup.
        natives[opcode](context, &frame, &vPoint);
        code = frame.Code + 1;
        frame.Code = code;
        if (*code == 0x42) {
            context = frame.Object;
            frame.Code = code + 1;
            natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        byte* table = *(byte**)zone;
        using ClosestCall = FVector* (__thiscall*)(AR6DeploymentZone*, FVector*, const FVector*);
        FVector storage;
        ClosestCall closest = *(ClosestCall*)(table + 0x198);
        const uint* returned = (const uint*)closest(zone, &storage, &vPoint);
        uint firstWord = returned[0];
        uint* destination = (uint*)result;
        destination[0] = firstWord;
        destination[1] = returned[1];
        destination[2] = returned[2]; // These reads follow preceding writes even when buffers overlap.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execFindClosestPointTo");
        throw;
    }
}

// R6Engine.dll @ 10017132 : DeploymentQueryRandomPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryRandomPointCatchPointer(void)
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

// R6Engine.dll @ 10017146 : DeploymentQueryRandomPointCatchContext
// Reports execFindRandomPointInArea and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryRandomPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecFindRandomPointInArea
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10017201 : DeploymentQueryPointInZoneCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryPointInZoneCatchPointer(void)
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

// R6Engine.dll @ 10017215 : DeploymentQueryPointInZoneCatchContext
// Reports execIsPointInZone and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryPointInZoneCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecIsPointInZone
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100172e3 : DeploymentQueryClosestPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryClosestPointCatchPointer(void)
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

// R6Engine.dll @ 100172f7 : DeploymentQueryClosestPointCatchContext
// Reports execFindClosestPointTo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentQueryClosestPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecFindClosestPointTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043d80 : DeploymentQueryRandomPointExceptionHandler
// Supplies the exact query-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentQueryRandomPointExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentQueryRandomPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043d90 : DeploymentQueryPointInZoneExceptionHandler
// Supplies the exact query-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentQueryPointInZoneExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentQueryPointInZoneFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043da0 : DeploymentQueryClosestPointExceptionHandler
// Supplies the exact query-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentQueryClosestPointExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentQueryClosestPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10017350 : AR6DeploymentZone::RenderEditorInfo
// Lazily loads hostage icons, draws unselected markers, and outlines selected circle/rectangle bounds.
void __thiscall AR6DeploymentZone::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* renderInterface,
    FDynamicActor* dynamicActor)
{
    AR6DeploymentZone* zone = this;
    const uint* selectionFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(zone) + 0xac);
    // Descriptive aliases for native statics.
    volatile uint& iconInitializationFlags = *(volatile uint*)((uint)&nativeDeploymentIconInitializationFlags);
    UObject*& hostageIcon = reinterpret_cast<UObject*&>(nativeDeploymentHostageIcon);
    UObject*& terroristHostageIcon = reinterpret_cast<UObject*&>(nativeDeploymentTerroristHostageIcon);
    try {
        if ((*(const volatile byte*)((uint)&nativeDeploymentIconInitializationFlags) & 1U) == 0) {
            iconInitializationFlags |= 1U;
            // This read precedes activation of the reset-bit action.
            UClass* loadClass = UTexturePrivateStaticClassImport;
            try {
                UObject* texture = UObject::StaticLoadObject(loadClass, nullptr,
                    (const ushort*)L"R6Engine_T.Icons.DZoneHos", nullptr, 2, nullptr);
                if (texture) {
                    UClass* checkClass = UTexturePrivateStaticClassImport;
                    int matches = texture->UObject::IsA(checkClass);
                    hostageIcon = texture;
                    if (!matches) hostageIcon = nullptr;
                } else hostageIcon = nullptr;
            } catch (...) {
                iconInitializationFlags &= ~1U;
                throw;
            }
        }
        if ((*(const volatile byte*)((uint)&nativeDeploymentIconInitializationFlags) & 2U) == 0) {
            iconInitializationFlags |= 2U;
            UClass* loadClass = UTexturePrivateStaticClassImport;
            try {
                UObject* texture = UObject::StaticLoadObject(loadClass, nullptr,
                    (const ushort*)L"R6Engine_T.Icons.DZoneTerHos", nullptr, 2, nullptr);
                if (texture) {
                    UClass* checkClass = UTexturePrivateStaticClassImport;
                    int matches = texture->UObject::IsA(checkClass);
                    terroristHostageIcon = texture;
                    if (!matches) terroristHostageIcon = nullptr;
                } else terroristHostageIcon = nullptr;
            } catch (...) {
                iconInitializationFlags &= ~2U;
                throw;
            }
        }
        if ((*selectionFlagWord & 0x4000U) == 0 && zone->m_iMaxHostage != 0) {
            bool mixed = zone->m_iMaxTerrorist != 0;
            byte* owner = *(byte**)((byte*)scene + 4);
            FRenderInterface* spriteInterface = *(FRenderInterface**)(owner + 0x164);
            UMaterial* icon = static_cast<UMaterial*>(mixed ? terroristHostageIcon : hostageIcon);
            FVector location;
            reinterpret_cast<uint&>(location.X) = reinterpret_cast<const uint&>(zone->Location.X);
            reinterpret_cast<uint&>(location.Y) = reinterpret_cast<const uint&>(zone->Location.Y);
            reinterpret_cast<uint&>(location.Z) = reinterpret_cast<const uint&>(zone->Location.Z);
            DrawSprite(zone, location, icon, scene,
                spriteInterface);
        }
        if ((*selectionFlagWord & 0x4000U) == 0) return; // Rechecked after DrawSprite.
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* batchInterface = *(FRenderInterface**)(owner + 0x164);
        alignas(FLineBatcher) byte batcherStorage[sizeof(FLineBatcher)];
        FLineBatcher* batcher = new (batcherStorage) FLineBatcher(batchInterface, 1, 0);
        UClass* type = zone->Class; // Native state0 still applies to this header read.
        try { // State3 activates batcher cleanup only after the header read.
            for (; type; type = type->GetSuperClass())
                if (type == &AR6DZoneCircle::PrivateStaticClass) break;
            if (type) {
                uint radiusWord = *(const uint*)&static_cast<AR6DZoneCircle*>(zone)->m_fRadius;
                FVector axisZ(0, 0, 1), axisY(0, 1, 0), axisX(1, 0, 0);
                FPlane plane(0.75f, 1.0f, 0.0f, 0.0f);
                FColor color(plane);
                FVector location; // Color construction precedes all location and drawing-interface snapshots.
                reinterpret_cast<uint&>(location.X) = reinterpret_cast<const uint&>(zone->Location.X);
                reinterpret_cast<uint&>(location.Y) = reinterpret_cast<const uint&>(zone->Location.Y);
                reinterpret_cast<uint&>(location.Z) = reinterpret_cast<const uint&>(zone->Location.Z);
                owner = *(byte**)((byte*)scene + 4);
                FRenderInterface* cylinderInterface = *(FRenderInterface**)(owner + 0x164);
                float radius;
                reinterpret_cast<uint&>(radius) = radiusWord;
                batcher->DrawCylinder(cylinderInterface, location, axisX, axisY, axisZ, color, radius, 50.0f, 12);
            } else {
                type = zone->Class; // Rectangle fallback reloads Class after circle ancestry.
                for (; type; type = type->GetSuperClass())
                    if (type == &AR6DZoneRectangle::PrivateStaticClass) break;
                if (type) {
                    // float10 denotes native x87 intermediates under the caller's precision/control mode.
                    float halfY = (float)((float10)static_cast<AR6DZoneRectangle*>(zone)->m_fY * (float10)0.5f);
                    FBox bounds; // Only IsValid is set; the by-value native copy retains its three padding bytes.
                    bounds.IsValid = 1;
                    FPlane plane(0.75f, 1.0f, 0.0f, 0.0f);
                    float halfX = (float)((float10)static_cast<AR6DZoneRectangle*>(zone)->m_fX * (float10)0.5f);
                    const volatile float* location = (const volatile float*)&zone->Location;
                    float10 maxZ = (float10)location[2] + (float10)50.0f;
                    float10 maxY = (float10)halfY + (float10)location[1];
                    float10 maxX = (float10)halfX + (float10)location[0];
                    float roundedMaxX = (float)maxX;
                    float roundedMaxY = (float)maxY;
                    float roundedMaxZ = (float)maxZ;
                    float10 minZ = (float10)location[2] - (float10)50.0f;
                    float10 minY = (float10)location[1] - (float10)halfY;
                    float10 minX = (float10)location[0] - (float10)halfX;
                    bounds.Min.X = (float)minX;
                    bounds.Min.Y = (float)minY;
                    bounds.Min.Z = (float)minZ;
                    bounds.Max.X = roundedMaxX;
                    bounds.Max.Y = roundedMaxY;
                    bounds.Max.Z = roundedMaxZ;
                    FColor color(plane);
                    batcher->DrawBox(bounds, color);
                }
            }
        } catch (...) {
            batcher->~FLineBatcher();
            throw;
        }
        batcher->~FLineBatcher(); // State0 before destruction prevents repeated cleanup on destructor failure.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001772a : DeploymentRendererCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRendererCatchPointer(void)
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

// R6Engine.dll @ 1001773e : DeploymentRendererCatchContext
// Reports the deployment renderer context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRendererCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10017760 : AR6DeploymentZone::CheckForErrors(void)
// Grounds ordinary zones, warns if grounding leaves no base, then validates template settings in editor mode.
void __thiscall AR6DeploymentZone::CheckForErrors(void)
{
    AR6DeploymentZone* zone = this;
    UClass* originalClass = zone->Class;
    bool skipGrounding = false;
    for (UClass* type = originalClass; type; type = type->GetSuperClass()) {
        if (type == &AR6DZoneRandomPoints::PrivateStaticClass) { skipGrounding = true; break; }
    }
    if (!skipGrounding) {
        for (UClass* type = originalClass; type; type = type->GetSuperClass()) {
            if (type == &AR6DZonePath::PrivateStaticClass) { skipGrounding = true; break; }
        }
    }
    if (!skipGrounding) {
        zone->AActor::PutOnGround();
        if (zone->Base == nullptr) { // +0x15c is read after PutOnGround returns.
            FFeedbackContext* warn = **(FFeedbackContext***)&CoreGWarnImport;
            using MapCheckCall = void (__thiscall*)(FFeedbackContext*, int, UObject*, const ushort*);
            MapCheckCall report = *(MapCheckCall*)(*(byte**)warn + 0x28);
            report(warn, 0, zone, (const ushort*)L"Deployment zone not on valid base.");
        }
    }
    zone->AR6DeploymentZone::CheckForErrors(true);
}

// R6Engine.dll @ 100177d0 : AR6DeploymentZone::IsPointInZone
// Requires strict vertical distance below100, then inclusive rectangle half-extents or circle radius squared.
int __thiscall AR6DeploymentZone::IsPointInZone(const FVector& point)
{
    AR6DeploymentZone* zone = this;
    float deltaX = (float)((float10)point.X - (float10)zone->Location.X);
    float deltaY = (float)((float10)point.Y - (float10)zone->Location.Y);
    float10 deltaZ = (float10)point.Z - (float10)zone->Location.Z; // No binary32 spill for Z.
    if (!(deltaZ >= (float10)0)) deltaZ = -deltaZ; // Native C0 test also negates unordered operands.
    if (!(deltaZ < (float10)100)) return 0;
    UClass* originalClass = zone->Class;
    for (UClass* type = originalClass; type; type = type->GetSuperClass()) {
        if (type != &AR6DZoneRectangle::PrivateStaticClass) continue;
        float10 absoluteX = (float10)deltaX;
        if (!(absoluteX >= (float10)0)) absoluteX = -absoluteX;
        float10 halfX = (float10)static_cast<AR6DZoneRectangle*>(zone)->m_fX * (float10)0.5;
        if (!(absoluteX <= halfX)) return 0; // Equality passes; unordered comparisons fail.
        float10 absoluteY = (float10)deltaY;
        if (!(absoluteY >= (float10)0)) absoluteY = -absoluteY;
        float10 halfY = (float10)static_cast<AR6DZoneRectangle*>(zone)->m_fY * (float10)0.5;
        return absoluteY <= halfY ? 1 : 0;
    }
    for (UClass* type = originalClass; type; type = type->GetSuperClass()) {
        if (type != &AR6DZoneCircle::PrivateStaticClass) continue;
        float10 radius = (float10)static_cast<AR6DZoneCircle*>(zone)->m_fRadius;
        float10 squareY = (float10)deltaY * (float10)deltaY;
        float10 squareX = (float10)deltaX * (float10)deltaX;
        float10 squaredDistance = squareY + squareX;
        float10 squaredRadius = radius * radius;
        return squaredRadius >= squaredDistance ? 1 : 0;
    }
    return 0;
}

// R6Engine.dll @ 100178f0 : AR6DeploymentZone::FindClosestPointTo
// Clamps rectangle XY bounds or projects circles to their circumference, with the native asymmetric float spills.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DeploymentZone::FindClosestPointTo(FVector* result, const FVector* point)
{
    AR6DeploymentZone* zone = this;
    FVector closest;
    uint queryX = reinterpret_cast<const uint&>(point->X);
    uint queryY = reinterpret_cast<const uint&>(point->Y);
    // Native reads all three input words before replacing Z.
    volatile uint queryZ = reinterpret_cast<const uint&>(point->Z);
    reinterpret_cast<uint&>(closest.X) = queryX;
    uint centerZ = reinterpret_cast<const uint&>(zone->Location.Z);
    UClass* type = zone->Class;
    try { // State0 starts after the initial input, center-Z and class reads.
        reinterpret_cast<uint&>(closest.Y) = queryY;
        reinterpret_cast<uint&>(closest.Z) = centerZ;
        for (; type; type = type->GetSuperClass())
            if (type == &AR6DZoneRectangle::PrivateStaticClass) break;
        if (type) {
            // float10 records unspilled x87 work; it does not set the caller's precision mode.
            float10 halfX = (float10)static_cast<AR6DZoneRectangle*>(zone)->m_fX * (float10)0.5;
            float halfY = (float)((float10)static_cast<AR6DZoneRectangle*>(zone)->m_fY * (float10)0.5);
            float maximumX = (float)(halfX + (float10)zone->Location.X);
            float10 minimumX = (float10)zone->Location.X - halfX;
            if ((float10)closest.X < minimumX) closest.X = (float)minimumX;
            else if (!((float10)closest.X < (float10)maximumX))
                // Unordered comparisons select the raw upper bound.
                reinterpret_cast<uint&>(closest.X) = reinterpret_cast<const uint&>(maximumX);
            float maximumY = (float)((float10)halfY + (float10)zone->Location.Y);
            float10 minimumY = (float10)zone->Location.Y - (float10)halfY;
            if ((float10)closest.Y < minimumY) closest.Y = (float)minimumY;
            else if (!((float10)closest.Y < (float10)maximumY))
                reinterpret_cast<uint&>(closest.Y) = reinterpret_cast<const uint&>(maximumY);
        } else {
            type = zone->Class; // Circle ancestry starts from a fresh header read.
            for (; type; type = type->GetSuperClass())
                if (type == &AR6DZoneCircle::PrivateStaticClass) break;
            if (type) {
                float10 deltaZ = (float10)closest.Z - (float10)zone->Location.Z;
                float10 deltaY = (float10)closest.Y - (float10)zone->Location.Y;
                float10 deltaX = (float10)closest.X - (float10)zone->Location.X;
                FVector delta;
                delta.X = (float)deltaX;
                delta.Y = (float)deltaY;
                delta.Z = (float)deltaZ;
                FVector direction;
                direction = delta.GetNormalized(); // Return pointer ignored; native consumes its own result storage.
                float10 radius = (float10)static_cast<AR6DZoneCircle*>(zone)->m_fRadius; // Read after normalization.
                float10 productX = (float10)direction.X * radius;
                float scaledY = (float)((float10)direction.Y * radius);
                float scaledZ = (float)((float10)direction.Z * radius);
                closest.X = (float)(productX + (float10)zone->Location.X);
                closest.Y = (float)((float10)scaledY + (float10)zone->Location.Y);
                closest.Z = (float)((float10)scaledZ + (float10)zone->Location.Z);
            }
        }
        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(closest.X);
        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(closest.Y);
        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(closest.Z);
        return result; // Hidden FVector output pointer in EAX; native RET8 consumes both stack pointers.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::FindClosestPointTo");
        throw;
    }
}

// R6Engine.dll @ 10017aa6 : DeploymentClosestPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x14 by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentClosestPointCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x14]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10017aba : DeploymentClosestPointCatchContext
// Reports the closest-point method context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentClosestPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneFindClosestPointTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043df0 : DeploymentClosestPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentClosestPointExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentClosestPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10017ae0 : AR6DeploymentZone::HavePlaceForPawnAt
// Tests and adjusts a mutable candidate using terrorist collision extents and the initially captured level.
int __thiscall AR6DeploymentZone::HavePlaceForPawnAt(FVector* candidatePosition)
{
    AR6DeploymentZone* zone = this;
    using FindSpotCall = int (__thiscall*)(ULevel*, FVector, FVector*, int, AActor*);
    ULevel* level = zone->XLevel; // Native state-1: this read precedes activation of the method's catches.
    try {
        AActor* defaults =
            (&AR6Terrorist::PrivateStaticClass)->UClass::GetDefaultActor();
        // float10 denotes native FLD work, not an inferred original type or a new caller FPU setting.
        float10 height = (float10)defaults->CollisionHeight;
        float10 radiusY = (float10)defaults->CollisionRadius;
        uint radiusX = reinterpret_cast<const uint&>(defaults->CollisionRadius);
        byte* levelTable = *(byte**)level; // Captured after GetDefaultActor, before either extent float spill.
        FVector extent;
        extent.Y = (float)radiusY;
        // X stays raw; Y and Z pass through FLD/FSTP, including NaN conversion.
        reinterpret_cast<uint&>(extent.X) = radiusX;
        extent.Z = (float)height;
        FindSpotCall findSpot = *(FindSpotCall*)(levelTable + 0xb8); // Slot lookup follows both float spills.
        // The full EAX result and any candidate changes are retained.
        return findSpot(level, extent, candidatePosition, 0, nullptr);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::HavePlaceForPawnAt");
        throw;
    }
}

// R6Engine.dll @ 10017b6f : DeploymentPlacementCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentPlacementCatchPointer(void)
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

// R6Engine.dll @ 10017b83 : DeploymentPlacementCatchContext
// Reports the placement method context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentPlacementCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneHavePlaceForPawnAt
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043e00 : DeploymentPlacementExceptionHandler
// Supplies the exact native placement FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentPlacementExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentPlacementFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10017ba0 : AR6DeploymentZone::InitTerroristAI
// Applies template skills and equipment, then sets the zone's strategy and perception options.
void __thiscall AR6DeploymentZone::InitTerroristAI(FR6CharTemplate* charTemplate, AR6Terrorist* terrorist)
{
    using DestroyString = void (__thiscall*)(FString*);
    alignas(FString) byte temporaryStorage[sizeof(FString)]; // Native EBP-0x24 reused for each completed result.
    FString* temporaryString = (FString*)temporaryStorage;
    try {
        FString* selectedText = CopyStringToHiddenResult((const FString*)charTemplate, temporaryString);
        try { // Only assignment owns the completed result slot. A getter failure has no parent cleanup.
            reinterpret_cast<FStringNoInit*>(&terrorist->m_szUsedTemplate)->operator=(*selectedText);
        } catch (...) {
            (*(DestroyString*)&FStringDestructorImport)(temporaryString);
            throw;
        }
        temporaryString->FString::~FString();

        float10 skillValue = FR6CharTemplate_GetSkill(charTemplate, 0);
        terrorist->m_fSkillAssault = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 1);
        terrorist->m_fSkillDemolitions = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 2);
        terrorist->m_fSkillElectronics = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 3);
        terrorist->m_fSkillSniper = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 4);
        terrorist->m_fSkillStealth = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 5);
        terrorist->m_fSkillSelfControl = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 6);
        terrorist->m_fSkillLeadership = (float)skillValue;
        skillValue = FR6CharTemplate_GetSkill(charTemplate, 7);
        terrorist->m_fSkillObservation = (float)skillValue;
        int selectedIndex = FR6CharTemplate_GetTerroristPersonality(charTemplate);
        terrorist->m_ePersonality = (byte)selectedIndex;

        selectedText = FR6CharTemplate_GetWeapon(charTemplate, temporaryString);
        try { // Only assignment owns the completed result slot. A getter failure has no parent cleanup.
            reinterpret_cast<FStringNoInit*>(&terrorist->m_szPrimaryWeapon)->operator=(*selectedText);
        } catch (...) {
            (*(DestroyString*)&FStringDestructorImport)(temporaryString);
            throw;
        }
        temporaryString->FString::~FString();
        selectedText = FR6CharTemplate_GetGrenade(charTemplate, temporaryString);
        try { // Only assignment owns the completed result slot. A getter failure has no parent cleanup.
            reinterpret_cast<FStringNoInit*>(&terrorist->m_szGrenadeWeapon)->operator=(*selectedText);
        } catch (...) {
            (*(DestroyString*)&FStringDestructorImport)(temporaryString);
            throw;
        }
        temporaryString->FString::~FString();

        // Alias packed-word addresses without caching their byte/DWORD contents.
        uint* terroristFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(terrorist) + 0xa44);
        uint* perceptionFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(terrorist) + 0x6c8);
        const uint* zoneFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3b8);
        uint earlyTerroristFlags = *terroristFlagWord;
        terrorist->m_DZone = this;
        uint allowLeaveDifference = earlyTerroristFlags ^ *zoneFlagWord;
        uint terroristFlags = *terroristFlagWord;
        terroristFlags ^= allowLeaveDifference & 0x08U;
        *terroristFlagWord = terroristFlags; // m_bAllowLeave.
        terroristFlags ^= (terroristFlags ^ *zoneFlagWord) & 0x10U;
        *terroristFlagWord = terroristFlags; // m_bPreventCrouching.
        terrorist->m_eDefCon = this->m_eDefCon;

        byte huntFlags = *reinterpret_cast<const byte*>(zoneFlagWord);
        if ((huntFlags & 0xc0U) == 0x80U) { // m_bHuntFromStart set and m_bHuntDisallowed clear.
            terrorist->m_eStrategy = 3;
        } else {
            UClass* classCursor = this->Class;
            while (classCursor != nullptr) {
                if (classCursor == &AR6DZoneCircle::PrivateStaticClass) goto useAreaStrategy;
                classCursor = classCursor->GetSuperClass();
            }
            classCursor = this->Class;
            while (classCursor != nullptr) {
                if (classCursor == &AR6DZoneRectangle::PrivateStaticClass) goto useAreaStrategy;
                classCursor = classCursor->GetSuperClass();
            }
            classCursor = this->Class;
            while (classCursor != nullptr) {
                if (classCursor == &AR6DZonePath::PrivateStaticClass) {
                    terrorist->m_eStrategy = 0;
                    goto strategyReady;
                }
                classCursor = classCursor->GetSuperClass();
            }
            terrorist->m_eStrategy = 2;
            goto strategyReady;
    useAreaStrategy:
            terrorist->m_eStrategy = 1;
        }
    strategyReady:
        uint zoneFlags = *zoneFlagWord;
        uint perceptionFlags = *perceptionFlagWord;
        perceptionFlags ^= ((zoneFlags << 6) ^ perceptionFlags) & 0x40U;
        *perceptionFlagWord = perceptionFlags; // m_bDontSeePlayer.
        zoneFlags = *zoneFlagWord;
        perceptionFlags ^= ((zoneFlags << 6) ^ perceptionFlags) & 0x80U;
        *perceptionFlagWord = perceptionFlags; // m_bDontHearPlayer.
        zoneFlags = *zoneFlagWord;
        terroristFlags = *terroristFlagWord;
        terroristFlags ^= ((zoneFlags << 3) ^ terroristFlags) & 0x20U;
        *terroristFlagWord = terroristFlags; // m_bHearNothing.

        selectedText = FR6CharTemplate_GetGadget(charTemplate, temporaryString);
        try { // Only assignment owns the completed result slot. A getter failure has no parent cleanup.
            reinterpret_cast<FStringNoInit*>(&terrorist->m_szGadget)->operator=(*selectedText);
        } catch (...) {
            (*(DestroyString*)&FStringDestructorImport)(temporaryString);
            throw;
        }
        temporaryString->FString::~FString();
        selectedIndex = FR6CharTemplate_GetAttachmentType(charTemplate);
        terrorist->m_eHeadAttachmentType = (byte)selectedIndex;
        *terroristFlagWord |= 0x04U; // m_bInitFinished.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::InitTerroristAI");
        throw;
    }
}

// R6Engine.dll @ 10017e5c : DeploymentInitTerroristCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitTerroristCatchPointer(void)
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

// R6Engine.dll @ 10017e90 : AR6DeploymentZone::InitHostageAI
// Applies the template's hostage settings and the zone's patrol and perception options.
void __thiscall AR6DeploymentZone::InitHostageAI(FR6CharTemplate* charTemplate, AR6Hostage* hostage)
{
    using DestroyString = void (__thiscall*)(FString*);
    alignas(FString) byte temporaryStorage[sizeof(FString)]; // Native EBP-0x24 reused for each completed result.
    FString* temporaryString = (FString*)temporaryStorage;
    try {
        FString* templateName = CopyStringToHiddenResult((const FString*)charTemplate, temporaryString);
        try { // Only assignment owns the completed result slot. A getter failure has no parent cleanup.
            reinterpret_cast<FStringNoInit*>(&hostage->m_szUsedTemplate)->operator=(*templateName);
        } catch (...) {
            (*(DestroyString*)&FStringDestructorImport)(temporaryString);
            throw;
        }
        temporaryString->FString::~FString();
        int personality = FR6CharTemplate_GetHostagePersonality(charTemplate);
        hostage->m_ePersonality = (byte)personality;
        byte startingPosition = (byte)FR6CharTemplate_GetStartingPosition(charTemplate);
        hostage->m_ePosition = (byte)startingPosition;
        uint civilianWord = *(const uint*)((const byte*)charTemplate + 0x98);
        // Alias packed-word addresses without caching their byte/DWORD contents.
        uint* hostageFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(hostage) + 0xa38);
        uint* perceptionFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(hostage) + 0x6c8);
        const uint* zoneFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3b8);
        uint hostageFlags = *hostageFlagWord;
        hostageFlags ^= ((civilianWord << 1) ^ hostageFlags) & 0x02U;
        *hostageFlagWord = hostageFlags; // m_bStartAsCivilian.
        hostage->m_DZone = this;

        UClass* classCursor = this->Class;
        while (classCursor != nullptr) {
            if (classCursor == &AR6DZoneCircle::PrivateStaticClass) goto useAreaPatrol;
            classCursor = classCursor->GetSuperClass();
        }
        classCursor = this->Class;
        while (classCursor != nullptr) {
            if (classCursor == &AR6DZoneRectangle::PrivateStaticClass) goto useAreaPatrol;
            classCursor = classCursor->GetSuperClass();
        }
        classCursor = this->Class;
        while (classCursor != nullptr) {
            if (classCursor == &AR6DZonePath::PrivateStaticClass) {
                hostage->m_eCivPatrol = 1;
                goto patrolReady;
            }
            classCursor = classCursor->GetSuperClass();
        }
        hostage->m_eCivPatrol = 3;
        goto patrolReady;
    useAreaPatrol:
        hostage->m_eCivPatrol = 2;
    patrolReady:
        uint zoneFlags = *zoneFlagWord;
        uint perceptionFlags = *perceptionFlagWord;
        perceptionFlags ^= ((zoneFlags << 6) ^ perceptionFlags) & 0x40U;
        *perceptionFlagWord = perceptionFlags; // m_bDontSeePlayer.
        zoneFlags = *zoneFlagWord;
        perceptionFlags ^= ((zoneFlags << 6) ^ perceptionFlags) & 0x80U;
        uint finalHostageFlags = *hostageFlagWord;
        *perceptionFlagWord = perceptionFlags; // m_bDontHearPlayer.
        *hostageFlagWord = finalHostageFlags | 0x01U; // m_bInitFinished.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::InitHostageAI");
        throw;
    }
}

// R6Engine.dll @ 10017fda : DeploymentInitHostageCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitHostageCatchPointer(void)
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

// R6Engine.dll @ 10018010 : AR6DeploymentZone::FindRandomPointInArea
// Tries five samples with five refinement steps each, retaining placement edits and the previous refinement vector.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DeploymentZone::FindRandomPointInArea(FVector* result)
{
    AR6DeploymentZone* zone = this;
    using FrandCall = float10 (__cdecl*)(void);
    try {
        // Return intentionally unused.
        (&AR6Terrorist::PrivateStaticClass)->UClass::GetDefaultActor();
        FVector step(0, 0, 0); // Initialized once, outside all five outer attempts.
        FVector candidate; // Unknown classes retain native uninitialized stack storage; no zero fallback is inferred.
        byte* zoneBytes = (byte*)zone;
        for (int attempt = 0; attempt < 5; ++attempt) {
            UClass* type = zone->Class;
            for (; type; type = type->GetSuperClass())
                if (type == &AR6DZoneRectangle::PrivateStaticClass) break;
            if (type) {
                float randomX = appFrand();
                int randomXOffset;
                int candidateX;
                __asm {
                    mov edx, zoneBytes
                    fld dword ptr [edx+49ch]
                    fmul dword ptr [nativeFloatHalf]
                    fsubr dword ptr [edx+234h]
                    fld dword ptr [randomX]
                    fmul dword ptr [edx+49ch]
                    call TruncateX87ToSigned64
                    mov randomXOffset, eax
                    fiadd dword ptr [randomXOffset]
                    call TruncateX87ToSigned64
                    mov candidateX, eax
                }
                float randomY = appFrand();
                int randomYOffset;
                int candidateY;
                __asm {
                    mov edx, zoneBytes
                    fld dword ptr [edx+4a0h]
                    fmul dword ptr [nativeFloatHalf]
                    fsubr dword ptr [edx+238h]
                    fld dword ptr [randomY]
                    fmul dword ptr [edx+4a0h]
                    call TruncateX87ToSigned64
                    mov randomYOffset, eax
                    fiadd dword ptr [randomYOffset]
                    call TruncateX87ToSigned64
                    mov candidateY, eax
                }
                float10 centerZ = (float10)zone->Location.Z;
                candidate.X = (float)candidateX;
                candidate.Y = (float)candidateY;
                candidate.Z = (float)centerZ;
                if (zone->AR6DeploymentZone::HavePlaceForPawnAt(&candidate) != 0) {
                    reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(candidate.X);
                    reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(candidate.Y);
                    reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(candidate.Z);
                    return result;
                }
                // float10 denotes native x87 work under the caller's control word, not original local type spelling.
                bool aboveX = (float10)candidate.X > (float10)zone->Location.X;
                float10 halfX = (float10)static_cast<AR6DZoneRectangle*>(zone)->m_fX * (float10)0.5f;
                float10 targetX = aboveX ? (float10)zone->Location.X - halfX : halfX + (float10)zone->Location.X;
                bool aboveY = (float10)candidate.Y > (float10)zone->Location.Y;
                float10 halfY = (float10)static_cast<AR6DZoneRectangle*>(zone)->m_fY * (float10)0.5f;
                float10 targetY = aboveY ? (float10)zone->Location.Y - halfY : halfY + (float10)zone->Location.Y;
                float roundedStepZ = (float)((float10)step.Z - (float10)candidate.Z);
                float10 workY = targetY - (float10)candidate.Y;
                step.Z = roundedStepZ; // Previous step.Z survives between attempts; only the first begins at zero.
                float10 workX = targetX - (float10)candidate.X;
                step.X = (float)workX;
                step.Y = (float)workY;
            } else {
                type = zone->Class;
                for (; type; type = type->GetSuperClass())
                    if (type == &AR6DZoneCircle::PrivateStaticClass) break;
                if (type) {
                    int remainder = appRand() % 0x7fff;
                    FRotator rotation;
                    rotation.Pitch = 0;
                    rotation.Roll = 0;
                    rotation.Yaw = (int)((uint)remainder * 2U); // Signed IDIV residue, then DWORD shift/wrap.
                    float10 fraction = reinterpret_cast<FrandCall&>(CoreAppFrandImport)();
                    volatile float fractionSpill = (float)fraction; // FST32 does not pop or narrow the working ST0.
                    float distance = (float)(fraction * (float10)static_cast<AR6DZoneCircle*>(zone)->m_fRadius);
                    FVector directionStorage;
                    FVector* direction = &(directionStorage = rotation.Vector());
                    float10 productZ = (float10)distance * (float10)direction->Z;
                    float scaledY = (float)((float10)distance * (float10)direction->Y);
                    float scaledX = (float)((float10)distance * (float10)direction->X);
                    float10 locationZ = productZ + (float10)zone->Location.Z;
                    float10 locationY = (float10)scaledY + (float10)zone->Location.Y;
                    float10 locationX = (float10)scaledX + (float10)zone->Location.X;
                    candidate.X = (float)locationX;
                    candidate.Y = (float)locationY;
                    candidate.Z = (float)locationZ;
                    if (zone->AR6DeploymentZone::HavePlaceForPawnAt(&candidate) != 0) {
                        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(candidate.X);
                        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(candidate.Y);
                        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(candidate.Z);
                        return result;
                    }
                    float10 deltaZ = (float10)zone->Location.Z - (float10)candidate.Z;
                    float10 deltaY = (float10)zone->Location.Y - (float10)candidate.Y;
                    float10 deltaX = (float10)zone->Location.X - (float10)candidate.X;
                    FVector towardCenter;
                    towardCenter.X = (float)deltaX;
                    reinterpret_cast<uint&>(step.X) = reinterpret_cast<const uint&>(towardCenter.X);
                    uint radiusWord = *(const uint*)&static_cast<AR6DZoneCircle*>(zone)->m_fRadius;
                    towardCenter.Y = (float)deltaY;
                    reinterpret_cast<uint&>(step.Y) = reinterpret_cast<const uint&>(towardCenter.Y);
                    towardCenter.Z = (float)deltaZ;
                    reinterpret_cast<uint&>(step.Z) = reinterpret_cast<const uint&>(towardCenter.Z);
                    FVector normalizedStorage;
                    FVector* normalized = &(normalizedStorage = towardCenter.GetNormalized());
                    // Captured before normalization.
                    float10 radius = (float10)reinterpret_cast<const float&>(radiusWord);
                    productZ = radius * (float10)normalized->Z;
                    float10 productY = radius * (float10)normalized->Y;
                    float10 productX = radius * (float10)normalized->X;
                    step.X = (float)(productX + (float10)step.X);
                    step.Y = (float)(productY + (float10)step.Y);
                    step.Z = (float)((float10)step.Z + productZ); // Uses saved deltas, not current towardCenter.
                }
            }
            step.X = (float)((float10)step.X * (float10)0.25f);
            step.Y = (float)((float10)step.Y * (float10)0.25f);
            step.Z = (float)((float10)step.Z * (float10)0.25f);
            for (int refinement = 0; refinement < 5; ++refinement) {
                candidate.X = (float)((float10)step.X + (float10)candidate.X);
                candidate.Y = (float)((float10)step.Y + (float10)candidate.Y);
                candidate.Z = (float)((float10)candidate.Z + (float10)step.Z);
                if (zone->AR6DeploymentZone::HavePlaceForPawnAt(&candidate) != 0) {
                    reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(candidate.X);
                    reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(candidate.Y);
                    reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(candidate.Z);
                    return result;
                }
            }
        }
        const ushort* name = zone->UObject::GetName();
        // Current log pointer is fetched after GetName.
        FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
        log->FOutputDevice::Logf((const ushort*)L"Cannot find a valid random point in area %s", name);
        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(candidate.X);
        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(candidate.Y);
        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(candidate.Z);
        return result; // Original hidden result pointer in EAX; native RET4 consumes only that pointer.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::FindRandomPointInArea");
        throw;
    }
}

// R6Engine.dll @ 100183a6 : DeploymentRandomAreaCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x7c through EBP-0x60.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRandomAreaCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x7c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x60]
        push eax
        mov dword ptr [ebp-0x60],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100183ba : DeploymentRandomAreaCatchContext
// Reports the random-point method context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentRandomAreaCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneFindRandomPointInArea
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043e60 : DeploymentRandomAreaExceptionHandler
// Supplies the exact random-point FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentRandomAreaExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentRandomAreaFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100183e0 : AR6DeploymentZone::HaveTerrorist
// Prunes incapacitated terrorists and stops at the first remaining actor whose current location is in this zone.
int __thiscall AR6DeploymentZone::HaveTerrorist(void)
{
    AR6DeploymentZone* zone = this;
    try {
        const NativeArrayHeader32* terrorists = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aTerrorist);
        uint index = 0;
        while ((int)index < terrorists->count) {
            AR6Terrorist* terrorist = reinterpret_cast<AR6Terrorist**>(terrorists->dataAddress)[index];
            // Unsigned byte comparison; no null-actor guard.
            if (reinterpret_cast<const byte&>(terrorist->m_eHealth) >= 2) {
                RemoveRecords4(reinterpret_cast<FArray*>(&zone->m_aTerrorist), (int)index, 1);
                continue; // Native DEC/INC pair leaves the index unchanged after removal.
            }
            const FVector& point = terrorist->Location;
            if (zone->IsPointInZone(point) != 0) return 1;
            ++index; // Count/data and virtual table are reloaded on the next iteration.
        }
        return 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::HaveTerrorist");
        throw;
    }
}

// R6Engine.dll @ 10018465 : DeploymentHaveTerroristCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveTerroristCatchPointer(void)
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

// R6Engine.dll @ 10018479 : DeploymentHaveTerroristCatchContext
// Reports the terrorist availability method and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveTerroristCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneHaveTerrorist
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100184b0 : AR6DeploymentZone::HaveHostage
// Prunes unavailable leading hostages in this zone and configured zones, treating a null entry as available.
int __thiscall AR6DeploymentZone::HaveHostage(void)
{
    AR6DeploymentZone* originalZone = this;
    try {
        uint zoneIndex = 0xffffffffU;
        const NativeArrayHeader32& configuredZones =
            reinterpret_cast<const NativeArrayHeader32&>(originalZone->m_HostageZoneToCheck);
        while ((int)zoneIndex < configuredZones.count) {
            AR6DeploymentZone* zone = originalZone;
            if (zoneIndex != 0xffffffffU)
                zone = reinterpret_cast<AR6DeploymentZone**>(configuredZones.dataAddress)[zoneIndex];
            const NativeArrayHeader32* hostages =
                reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aHostage);
            while (0 < hostages->count) {
                AR6Hostage* hostage = *reinterpret_cast<AR6Hostage**>(hostages->dataAddress);
                if (hostage == nullptr) return 1;
                if (reinterpret_cast<const byte&>(hostage->m_eHealth) < 2 &&
                    (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(hostage) + 0xa38) & 0x4000U) == 0)
                    return 1; // m_bExtracted.
                RemoveRecords4((FArray*)&zone->m_aHostage, 0, 1);
            }
            ++zoneIndex; // The current zone stays cached during pruning; the outer count/data remain live.
        }
        return 0; // Even the initial -1 iteration is skipped if the configured-zone count is negative.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::HaveHostage");
        throw;
    }
}

// R6Engine.dll @ 1001853c : DeploymentHaveHostageCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveHostageCatchPointer(void)
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

// R6Engine.dll @ 10018550 : DeploymentHaveHostageCatchContext
// Reports the hostage availability method and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentHaveHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneHaveHostage
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043e70 : DeploymentHaveTerroristExceptionHandler
// Supplies the exact availability FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentHaveTerroristExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentHaveTerroristFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043e80 : DeploymentHaveHostageExceptionHandler
// Supplies the exact availability FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentHaveHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentHaveHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100185a0 : AR6DeploymentZone::execAddHostage
// Evaluates one hostage argument and appends it without rejecting nulls/duplicates or touching script result storage.
void __thiscall AR6DeploymentZone::execAddHostage(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = frame.Code;
    AR6Hostage* hostage = nullptr;
    byte opcode = *code;
    frame.Code = code + 1;
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* context = frame.Object;
    try { // Native state0 starts after the initial cursor, table and Object reads, before the dispatch slot lookup.
        natives[opcode](context, &frame, &hostage);
        code = frame.Code + 1;
        frame.Code = code;
        if (*code == 0x42) {
            context = frame.Object; // Debug receiver is captured before the next Code store.
            frame.Code = code + 1;
            natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        NativeArrayHeader32* hostages = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aHostage);
        int index = reinterpret_cast<FArray*>(hostages)->FArray::Add(1, 4);
        uint storage = hostages->dataAddress; // Reload after Add, then capture the current evaluated local.
        AR6Hostage* value = hostage;
        uint appendAddress = storage + (uint)index * 4U;
        // Native unchecked DWORD address calculation; no owner assignment.
        *reinterpret_cast<AR6Hostage**>(appendAddress) = value;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execAddHostage");
        throw;
    }
}

// R6Engine.dll @ 1001863f : DeploymentExecAddHostageCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecAddHostageCatchPointer(void)
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

// R6Engine.dll @ 10018653 : DeploymentExecAddHostageCatchContext
// Reports the hostage append bridge and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecAddHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecAddHostage
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10018670 : AR6DeploymentZone::execGetClosestHostage
// Returns the strict closest XY candidate from configured zones after availability pruning, without per-entry filters.
void __thiscall AR6DeploymentZone::execGetClosestHostage(FFrame& frame, void* result)
{
    AR6DeploymentZone* originalZone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    FVector vPoint; // Native argument storage is not initialized; Z is never read by this parent.
    byte* code = frame.Code;
    byte opcode = *code;
    AR6Hostage* closest = nullptr;
    frame.Code = code + 1;
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* context = frame.Object;
    try { // State0 begins only after preparing the first dispatch receiver/table.
        natives[opcode](context, &frame, &vPoint);
        code = frame.Code + 1;
        frame.Code = code;
        if (*code == 0x42) {
            context = frame.Object;
            frame.Code = code + 1;
            natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        if (originalZone->AR6DeploymentZone::HaveHostage() == 0) {
            *reinterpret_cast<AR6Hostage**>(result) = nullptr;
            return;
        }
        float closestScore; // Only selected candidates spill a score; the first does not read this slot.
        const NativeArrayHeader32* zones =
            reinterpret_cast<const NativeArrayHeader32*>(&originalZone->m_HostageZoneToCheck);
        uint zoneIndex = 0;
        while ((int)zoneIndex < zones->count) {
            AR6DeploymentZone* zone = reinterpret_cast<AR6DeploymentZone**>(zones->dataAddress)[zoneIndex];
            const NativeArrayHeader32* hostages = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aHostage);
            uint index = 0;
            while ((int)index < hostages->count) {
                AR6Hostage* hostage = reinterpret_cast<AR6Hostage**>(hostages->dataAddress)[index];
                // float10 denotes native unspilled x87 work under the caller's precision/control mode.
                float10 dx = (float10)hostage->Location.X - (float10)vPoint.X;
                float10 dy = (float10)hostage->Location.Y - (float10)vPoint.Y;
                float10 squareY = dy * dy;
                float10 squareX = dx * dx;
                float10 score = squareY + squareX;
                if (closest == nullptr || score < (float10)closestScore) {
                    closestScore = (float)score; // Strict ordered improvement; equal/unordered scores keep the winner.
                    closest = hostage;
                }
                ++index;
            }
            ++zoneIndex;
        }
        // Own-zone hostages are absent unless self appears in the configured list.
        *reinterpret_cast<AR6Hostage**>(result) = closest;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execGetClosestHostage");
        throw;
    }
}

// R6Engine.dll @ 1001877d : DeploymentExecClosestHostageCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecClosestHostageCatchPointer(void)
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

// R6Engine.dll @ 10018791 : DeploymentExecClosestHostageCatchContext
// Reports the closest-hostage bridge and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecClosestHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecGetClosestHostage
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043e90 : DeploymentExecAddHostageExceptionHandler
// Supplies the exact script-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecAddHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecAddHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043ea0 : DeploymentExecClosestHostageExceptionHandler
// Supplies the exact script-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecClosestHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecClosestHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10018920 : AR6DeploymentZone::execHaveTerrorist
// Skips the call terminator/optional debug record and writes the full native availability word.
void __thiscall AR6DeploymentZone::execHaveTerrorist(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = frame.Code + 1;
    frame.Code = code;
    bool hasDebug = *code == 0x42; // Native state-1 covers the initial cursor read/store and opcode probe.
    try {
        if (hasDebug) {
            UObject* context = frame.Object;
            frame.Code = code + 1;
            NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        int available = zone->AR6DeploymentZone::HaveTerrorist();
        *(int*)result = available; // No bool conversion; native stores the complete EAX value.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execHaveTerrorist");
        throw;
    }
}

// R6Engine.dll @ 1001898d : DeploymentExecHaveTerroristCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveTerroristCatchPointer(void)
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

// R6Engine.dll @ 100189a1 : DeploymentExecHaveTerroristCatchContext
// Reports the availability script bridge and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveTerroristCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecHaveTerrorist
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100189c0 : AR6DeploymentZone::execHaveHostage
// Skips the call terminator/optional debug record and writes the full native availability word.
void __thiscall AR6DeploymentZone::execHaveHostage(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = frame.Code + 1;
    frame.Code = code;
    bool hasDebug = *code == 0x42; // Native state-1 covers the initial cursor read/store and opcode probe.
    try {
        if (hasDebug) {
            UObject* context = frame.Object;
            frame.Code = code + 1;
            NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        int available = zone->AR6DeploymentZone::HaveHostage();
        *(int*)result = available; // No bool conversion; native stores the complete EAX value.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execHaveHostage");
        throw;
    }
}

// R6Engine.dll @ 10018a2d : DeploymentExecHaveHostageCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveHostageCatchPointer(void)
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

// R6Engine.dll @ 10018a41 : DeploymentExecHaveHostageCatchContext
// Reports the availability script bridge and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecHaveHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecHaveHostage
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10018a60 : AR6DeploymentZone::execOrderTerroListFromDistanceTo
// Permutes terrorists and rounded XY scores using the native all-pairs strict comparison and swap sequence.
void __thiscall AR6DeploymentZone::execOrderTerroListFromDistanceTo(FFrame& frame, void* result)
{
    AR6DeploymentZone* zone = this;
    using NativeExec = void (__thiscall*)(UObject*, FFrame*, void*);
    // Reference owner for native state1, not a recovered compiler-frame type or additional native body.
    struct PendingDistances {
        FArray* array;
        bool active;
        // Runs during exceptional unwinding; normal destruction is explicitly disabled before the final call.
        ~PendingDistances() noexcept(false)
        {
            if (active) DestroyEmbeddedEightByteArrayPair(array);
        }
    };
    FVector vPoint; // Argument storage is uninitialized; this parent does not read Z or use result.
    byte* code = frame.Code;
    byte opcode = *code;
    uint cachedDistanceData = 0;
    frame.Code = code + 1;
    NativeExec* natives = *(NativeExec**)&CoreGNativesImport;
    UObject* context = frame.Object;
    try {
        natives[opcode](context, &frame, &vPoint);
        code = frame.Code + 1;
        frame.Code = code;
        if (*code == 0x42) {
            context = frame.Object;
            frame.Code = code + 1;
            natives = *(NativeExec**)&CoreGNativesImport;
            natives[0x42](context, &frame, nullptr);
        }
        uint distanceWords[3] = {0, 0, 0}; // Native EBP-0x24 header; cleanup activates after all three zero stores.
        FArray* distances = (FArray*)distanceWords;
        PendingDistances cleanup{distances, true}; // State1 protects partial fills and all swap operations.
        const NativeArrayHeader32* terrorists = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aTerrorist);
        const NativeArrayHeader32* distanceHeader = reinterpret_cast<const NativeArrayHeader32*>(distances);
        uint index = 0;
        while ((int)index < terrorists->count) {
            AR6Terrorist* terrorist = reinterpret_cast<AR6Terrorist**>(terrorists->dataAddress)[index];
            // float10 denotes native x87 intermediates under the caller's precision/control mode.
            float10 dy = (float10)terrorist->Location.Y - (float10)vPoint.Y;
            float10 dx = (float10)terrorist->Location.X - (float10)vPoint.X;
            float10 squareX = dx * dx;
            float10 squareY = dy * dy;
            float distanceSquared = (float)(squareX + squareY); // Spill precedes the potentially mutating Add.
            int slot = distances->FArray::Add(1, 4);
            float10 value = (float10)distanceSquared;
            uint storage = distanceHeader->dataAddress;
            *(float*)(storage + (uint)slot * 4U) = (float)value; // Native FLD/FSTP, not a raw word copy.
            cachedDistanceData = distanceHeader->dataAddress;
            ++index;
        }
        uint first = 0;
        while ((int)first < terrorists->count) {
            uint second = 0;
            while ((int)second < terrorists->count) {
                if (first != second &&
                    (float10)*(const float*)(cachedDistanceData + first * 4U) <
                    (float10)*(const float*)(cachedDistanceData + second * 4U)) {
                    uint terroristData = terrorists->dataAddress;
                    float10 savedDistance = (float10)*(const float*)(cachedDistanceData + first * 4U);
                    uint secondTerrorist = *(const uint*)(terroristData + second * 4U);
                    uint firstTerrorist = *(const uint*)(terroristData + first * 4U);
                    *(uint*)(terroristData + first * 4U) = secondTerrorist;
                    uint distanceData = distanceHeader->dataAddress;
                    uint secondDistance = *(const uint*)(distanceData + second * 4U);
                    *(uint*)(distanceData + first * 4U) = secondDistance;
                    terroristData = terrorists->dataAddress;
                    *(uint*)(terroristData + second * 4U) = firstTerrorist;
                    distanceData = distanceHeader->dataAddress;
                    *(float*)(distanceData + second * 4U) = (float)savedDistance;
                    cachedDistanceData = distanceHeader->dataAddress; // No reload on failed/self comparisons.
                }
                ++second;
            }
            ++first;
        }
        cleanup.active = false;
        // State0 before destruction; a throwing destructor is not retried.
        DestroyEmbeddedEightByteArrayPair(distances);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DeploymentZone::execOrderTerroListFromDistanceTo");
        throw;
    }
}

// R6Engine.dll @ 10018bab : DeploymentExecOrderTerroristsCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecOrderTerroristsCatchPointer(void)
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

// R6Engine.dll @ 10018bbf : DeploymentExecOrderTerroristsCatchContext
// Reports the terrorist ordering bridge and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecOrderTerroristsCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecOrderTerroListFromDistanceTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043ef0 : DeploymentExecHaveTerroristExceptionHandler
// Supplies the exact script-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecHaveTerroristExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecHaveTerroristFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043f00 : DeploymentExecHaveHostageExceptionHandler
// Supplies the exact script-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecHaveHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecHaveHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043f18 : DeploymentExecOrderTerroristsExceptionHandler
// Supplies the exact script-bridge FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecOrderTerroristsExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecOrderTerroristsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10018c40 : AR6DeploymentZone::SpawnAHostage
// Selects one hostage template, tries up to ten actor spawns and initializes/notifies/appends the first valid hostage.
void __thiscall AR6DeploymentZone::SpawnAHostage(void)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc4];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&DeploymentZoneSpawnAHostageExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    AR6DeploymentZone* zone = this;
    byte* fields = reinterpret_cast<byte*>(zone);
    frame.state = 0;
    int remainder = appRand() % 100;
    uint selected = 0;
    while (selected < 5 && remainder >= *reinterpret_cast<int*>(fields + 0x458 + selected * 16U)) ++selected;
    if (selected == 5) { ExceptionList = frame.previousExceptionList; return; }
    FR6CharTemplate* loadedTemplate = reinterpret_cast<FR6CharTemplate*>(nativeFrame - 0xd0);
    InitializeCharTemplate(loadedTemplate);
    *(byte*)&frame.state = 1;
    const ushort* filename = **reinterpret_cast<FString*>(fields + 0x44c + selected * 16U);
    uint loaded = FR6CharTemplate_GetData(loadedTemplate, filename, 2);
    if (!loaded) {
        *(byte*)&frame.state = 0;
        DestroyCharTemplate(loadedTemplate);
        ExceptionList = frame.previousExceptionList;
        return;
    }
    UClass*& pawnClass = *reinterpret_cast<UClass**>(nativeFrame - 0x20);
    pawnClass = FR6CharTemplate_GetPawnClass(loadedTemplate);
    AR6Hostage* hostage = nullptr;
    uint& attempts = *reinterpret_cast<uint*>(nativeFrame - 0x14);
    attempts = 0;
    while (!hostage && static_cast<int>(attempts) < 10) {
        FVector* locationStorage = reinterpret_cast<FVector*>(nativeFrame - 0x30);
        using RandomPoint = FVector* (__thiscall*)(AR6DeploymentZone*, FVector*);
        byte* table = *reinterpret_cast<byte**>(zone);
        FVector* location = (*reinterpret_cast<RandomPoint*>(table + 0x18c))(zone, locationStorage);
        ULevel* level = zone->XLevel;
        FRotator rotation;
        reinterpret_cast<uint&>(rotation.Pitch) = reinterpret_cast<uint&>(zone->Rotation.Pitch);
        uint yaw = reinterpret_cast<uint&>(zone->Rotation.Yaw);
        uint roll = reinterpret_cast<uint&>(zone->Rotation.Roll);
        reinterpret_cast<uint&>(rotation.Yaw) = yaw;
        reinterpret_cast<uint&>(rotation.Roll) = roll;
        FVector position;
        reinterpret_cast<uint&>(position.X) = reinterpret_cast<uint&>(location->X);
        uint y = reinterpret_cast<uint&>(location->Y), z = reinterpret_cast<uint&>(location->Z);
        reinterpret_cast<uint&>(position.Y) = y;
        reinterpret_cast<uint&>(position.Z) = z;
        using SpawnActor = AActor* (__thiscall*)(ULevel*, UClass*, uint, FVector, FRotator, uint, uint, uint, uint, uint);
        byte* levelTable = *reinterpret_cast<byte**>(level);
        AActor* actor = (*reinterpret_cast<SpawnActor*>(levelTable + 0xa8))(level, pawnClass, 0, position, rotation, 0, 0, 0, 0, 0);
        if (actor) {
            UClass* type = actor->Class;
            while (type && type != &AR6Hostage::PrivateStaticClass) type = type->GetSuperClass();
            if (type == &AR6Hostage::PrivateStaticClass) hostage = reinterpret_cast<AR6Hostage*>(actor);
        }
        ++attempts; // Rejected actors are not destroyed. A valid tenth result is processed before checking the limit again.
    }
    if (hostage) {
        zone->AR6DeploymentZone::InitHostageAI(loadedTemplate, hostage);
        FName finishName = R6ENGINE_FinishInitialization;
        UFunction* finish = UObject::FindFunctionChecked(hostage, finishName, 0);
        using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
        byte* table = *reinterpret_cast<byte**>(hostage);
        (*reinterpret_cast<ProcessEvent*>(table + 0x10))(hostage, finish, nullptr, nullptr);
        FArray* actors = reinterpret_cast<FArray*>(fields + 0x3f0);
        int added = actors->Add(1, 4);
        AActor** entries = *reinterpret_cast<AActor***>(actors);
        entries[added] = hostage;
    }
    *reinterpret_cast<void**>(nativeFrame - 0x18) = reinterpret_cast<byte*>(loadedTemplate) + 0x18;
    *(byte*)&frame.state = 4;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0x64);
    *(byte*)&frame.state = 3;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0x58);
    *(byte*)&frame.state = 2;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0xc);
    *(byte*)&frame.state = 0;
    FString::~FString(reinterpret_cast<FString*>(loadedTemplate));
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 10018e29 : DeploymentSpawnHostageCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x24 by value through EBP-0x1c.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnHostageCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10018e60 : AR6DeploymentZone::SpawnATerrorist
// Spawns a selected terrorist through group-step or ordinary placement, then initializes/notifies/appends it.
void __thiscall AR6DeploymentZone::SpawnATerrorist(void)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xe8];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&DeploymentZoneSpawnATerroristExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    AR6DeploymentZone* zone = this;
    byte* fields = reinterpret_cast<byte*>(zone);
    frame.state = 0;
    int remainder = appRand() % 100;
    uint selected = 0;
    while (selected < 5 && remainder >= *reinterpret_cast<int*>(fields + 0x408 + selected * 16U)) ++selected;
    if (selected == 5) { ExceptionList = frame.previousExceptionList; return; }
    FR6CharTemplate* loadedTemplate = reinterpret_cast<FR6CharTemplate*>(nativeFrame - 0xf4);
    InitializeCharTemplate(loadedTemplate);
    *(byte*)&frame.state = 1;
    const ushort* filename = **reinterpret_cast<FString*>(fields + 0x3fc + selected * 16U);
    if (!FR6CharTemplate_GetData(loadedTemplate, filename, 1)) {
        *(byte*)&frame.state = 0;
        DestroyCharTemplate(loadedTemplate);
        ExceptionList = frame.previousExceptionList;
        return;
    }
    UClass*& pawnClass = *reinterpret_cast<UClass**>(nativeFrame - 0x38);
    pawnClass = FR6CharTemplate_GetPawnClass(loadedTemplate);
    uint flags = *reinterpret_cast<uint*>(fields + 0x3b8);
    int& group = *reinterpret_cast<int*>(nativeFrame - 0x40);
    group = *reinterpret_cast<int*>(fields + 0x398);
    int count = *reinterpret_cast<int*>(fields + 0x3e8);
    uint& stance = *reinterpret_cast<uint*>(nativeFrame - 0x3c);
    stance = 1;
    uint& allowLeave = *reinterpret_cast<uint*>(nativeFrame - 0x30);
    allowLeave = (flags >> 3) & 1;
    AR6Terrorist* terrorist = nullptr;
    bool actAsGroup = false;
    if (count != 0) {
        UClass* type = zone->Class;
        while (type && type != &AR6DZonePath::PrivateStaticClass) type = type->GetSuperClass();
        if (type == &AR6DZonePath::PrivateStaticClass) actAsGroup = (*(fields + 0x49c) & 4) != 0;
    }
    FVector* position = reinterpret_cast<FVector*>(nativeFrame - 0x2c);
    auto spawn = [&](ULevel* level, const FVector* location, const FRotator* rotation) {
        FRotator copiedRotation;
        reinterpret_cast<uint&>(copiedRotation.Pitch) = reinterpret_cast<const uint&>(rotation->Pitch);
        uint yaw = reinterpret_cast<const uint&>(rotation->Yaw), roll = reinterpret_cast<const uint&>(rotation->Roll);
        reinterpret_cast<uint&>(copiedRotation.Yaw) = yaw;
        reinterpret_cast<uint&>(copiedRotation.Roll) = roll;
        FVector copiedLocation;
        reinterpret_cast<uint&>(copiedLocation.X) = reinterpret_cast<const uint&>(location->X);
        uint y = reinterpret_cast<const uint&>(location->Y), z = reinterpret_cast<const uint&>(location->Z);
        reinterpret_cast<uint&>(copiedLocation.Y) = y;
        reinterpret_cast<uint&>(copiedLocation.Z) = z;
        using SpawnActor = AActor* (__thiscall*)(ULevel*, UClass*, uint, FVector, FRotator, uint, uint, uint, uint, uint);
        byte* table = *reinterpret_cast<byte**>(level);
        return (*reinterpret_cast<SpawnActor*>(table + 0xa8))(level, pawnClass, 0,
            copiedLocation, copiedRotation, 0, 0, 0, 0, 0);
    };
    auto accept = [&](AActor* actor) {
        if (!actor) return static_cast<AR6Terrorist*>(nullptr);
        UClass* type = actor->Class;
        while (type && type != &AR6Terrorist::PrivateStaticClass) type = type->GetSuperClass();
        return type == &AR6Terrorist::PrivateStaticClass ? reinterpret_cast<AR6Terrorist*>(actor) : nullptr;
    };
    if (actAsGroup) {
        AActor** actors = *reinterpret_cast<AActor***>(fields + 0x3e4);
        AActor* first = actors[0]; // Nonempty list was tested earlier; this actor and its class are not revalidated.
        reinterpret_cast<uint&>(position->X) = reinterpret_cast<uint&>(first->Location.X);
        uint y = reinterpret_cast<uint&>(first->Location.Y), z = reinterpret_cast<uint&>(first->Location.Z);
        reinterpret_cast<uint&>(position->Y) = y;
        reinterpret_cast<uint&>(position->Z) = z;
        FVector* step = reinterpret_cast<FVector*>(nativeFrame - 0x20);
        reinterpret_cast<uint&>(step->X) = 0;
        reinterpret_cast<uint&>(step->Y) = 0;
        reinterpret_cast<uint&>(step->Z) = 0;
        uint& attemptScratch = *reinterpret_cast<uint*>(nativeFrame - 0x14);
        uint attempts = 0;
        while (attempts < 5) {
            attemptScratch = attempts;
            // FST rounds only the shared scratch; doubled/subtracted coordinates consume the unspilled random return.
            __asm {
                call dword ptr [CoreAppFrandImport]
                mov ecx,nativeFrame
                fst dword ptr [ecx-0x14]
                fadd st(0),st
                fsub dword ptr [nativeFloatOne]
                fstp dword ptr [ecx-0x20]
                call dword ptr [CoreAppFrandImport]
                mov ecx,nativeFrame
                fst dword ptr [ecx-0x14]
            }
            ++attempts;
            __asm {
                fadd st(0),st
                fsub dword ptr [nativeFloatOne]
                mov ecx,nativeFrame
                fstp dword ptr [ecx-0x1c]
            }
        }
        attemptScratch = attempts; // Five overwriting iterations, not five candidate directions retained for retries.
        FVector::Normalize(step);
        using DefaultActor = AActor* (__thiscall*)(UClass*);
        AActor* defaults = reinterpret_cast<DefaultActor&>(UClassGetDefaultActorImport)(&AR6Terrorist::PrivateStaticClass);
        // Scale the final normalized vector by the base terrorist default radius, retaining one live x87 radius.
        __asm {
            mov eax,defaults
            mov ecx,step
            fld dword ptr [eax+0xf8]
            fld dword ptr [ecx]
            fmul st,st(1)
            fstp dword ptr [ecx]
            fld dword ptr [ecx+4]
            fmul st,st(1)
            fstp dword ptr [ecx+4]
            fld dword ptr [ecx+8]
            fmul st,st(1)
            fstp dword ptr [ecx+8]
            fstp st(0)
        }
        while (!terrorist && static_cast<int>(attempts) < 10) {
            __asm {
                mov eax,position
                mov ecx,step
                fld dword ptr [eax]
                fadd dword ptr [ecx]
                fstp dword ptr [eax]
                fld dword ptr [eax+4]
                fadd dword ptr [ecx+4]
                fstp dword ptr [eax+4]
                fld dword ptr [eax+8]
                fadd dword ptr [ecx+8]
                fstp dword ptr [eax+8]
            }
            if (zone->AR6DeploymentZone::HavePlaceForPawnAt(position)) {
                ULevel* level = zone->XLevel;
                FRotator rotation;
                rotation.Pitch = rotation.Yaw = rotation.Roll = 0;
                terrorist = accept(spawn(level, position, &rotation));
            }
            attempts = attemptScratch + 1U;
            attemptScratch = attempts; // Clearance failures also consume attempts; group candidates are attempts five to nine.
        }
    } else {
        FRotator* rotation = reinterpret_cast<FRotator*>(nativeFrame - 0x4c);
        rotation->Pitch = rotation->Yaw = rotation->Roll = 0;
        uint attempts = 0;
        while (!terrorist && static_cast<int>(attempts) < 10) {
            using SpawningPoint = FVector* (__thiscall*)(AR6DeploymentZone*, FVector*, FRotator*, int*, uint*, uint*);
            byte* table = *reinterpret_cast<byte**>(zone);
            FVector* location = (*reinterpret_cast<SpawningPoint*>(table + 0x190))(
                zone, position, rotation, &group, &stance, &allowLeave);
            ULevel* level = zone->XLevel;
            terrorist = accept(spawn(level, location, rotation)); // Use the provider-returned Location, not the supplied buffer.
            ++attempts;
        }
    }
    if (terrorist) {
        terrorist->AActor::PutOnGround();
        using Initialize = void (__thiscall*)(AR6DeploymentZone*, FR6CharTemplate*, AR6Terrorist*);
        byte* table = *reinterpret_cast<byte**>(zone);
        (*reinterpret_cast<Initialize*>(table + 0x19c))(zone, loadedTemplate, terrorist);
        byte* actor = reinterpret_cast<byte*>(terrorist);
        *reinterpret_cast<int*>(actor + 0xa34) = group;
        *(actor + 0xa2b) = static_cast<byte>(stance);
        uint allowBits = allowLeave * 8U;
        uint* actorFlags = reinterpret_cast<uint*>(actor + 0xa44);
        *actorFlags ^= (*actorFlags ^ allowBits) & 8;
        FName finishName = R6ENGINE_FinishInitialization;
        UFunction* finish = UObject::FindFunctionChecked(terrorist, finishName, 0);
        using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
        table = *reinterpret_cast<byte**>(terrorist);
        (*reinterpret_cast<ProcessEvent*>(table + 0x10))(terrorist, finish, nullptr, nullptr);
        FArray* actors = reinterpret_cast<FArray*>(fields + 0x3e4);
        int added = actors->Add(1, 4);
        AActor** entries = *reinterpret_cast<AActor***>(actors);
        entries[added] = terrorist;
    }
    *reinterpret_cast<void**>(nativeFrame - 0x34) = reinterpret_cast<byte*>(loadedTemplate) + 0x18;
    *(byte*)&frame.state = 4;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0x64);
    *(byte*)&frame.state = 3;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0x58);
    *(byte*)&frame.state = 2;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(loadedTemplate) + 0xc);
    *(byte*)&frame.state = 0;
    FString::~FString(reinterpret_cast<FString*>(loadedTemplate));
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1001923b : DeploymentSpawnTerroristCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x54 by value through EBP-0x50.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnTerroristCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x54]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x50]
        push ecx
        mov dword ptr [ebp-0x50],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10019270 : AR6DeploymentZone::FirstInit
// Checks game-type availability, prepares cumulative weights when needed and runs both spawn loops on available calls.
void __thiscall AR6DeploymentZone::FirstInit(void)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x10];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&DeploymentZoneFirstInitExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    AR6DeploymentZone* zone = this;
    byte* fields = reinterpret_cast<byte*>(zone);
    byte* level = *reinterpret_cast<byte**>(fields + 0x144);
    byte* game = *reinterpret_cast<byte**>(level + 0x4cc);
    FString* gameType = reinterpret_cast<FString*>(game + 0x4b0);
    frame.state = 0;
    int available;
    // Retained ABI packet: the copied outgoing FString is owned/destroyed by IsAvailableInGameType.
    __asm {
        sub esp,0xc
        mov ecx,esp
        mov edx,nativeFrame
        mov dword ptr [edx-0x18],esp
        mov eax,gameType
        push eax
        call dword ptr [FStringCopyConstructorImport]
        mov ecx,zone
        call dword ptr [AActorIsAvailableInGameTypeImport]
        mov available,eax
    }
    if (available) {
        uint* flags = reinterpret_cast<uint*>(fields + 0x3b8);
        if ((*flags & 0x100) == 0) {
            zone->AR6DeploymentZone::CheckForErrors(false);
            if ((*flags & 0x100) == 0) {
                uint terroristTotal = 0, hostageTotal = 0;
                for (uint index = 0; index < 5; ++index) {
                    uint* terroristChance = reinterpret_cast<uint*>(fields + 0x408 + index * 16U);
                    terroristTotal += *terroristChance;
                    *terroristChance = terroristTotal;
                    uint* hostageChance = reinterpret_cast<uint*>(fields + 0x458 + index * 16U);
                    hostageTotal += *hostageChance;
                    *hostageChance = hostageTotal;
                }
            }
        }
        using TerroristCount = int (__thiscall*)(AR6DeploymentZone*);
        byte* table = *reinterpret_cast<byte**>(zone);
        int count = (*reinterpret_cast<TerroristCount*>(table + 0x184))(zone);
        for (int index = 0; index < count; ++index) zone->AR6DeploymentZone::SpawnATerrorist();
        int hostages = *reinterpret_cast<int*>(fields + 0x3ac);
        if (*reinterpret_cast<int*>(fields + 0x3b0) > hostages) {
            int random = appRand();
            uint divisor = *reinterpret_cast<uint*>(fields + 0x3b0);
            divisor -= *reinterpret_cast<uint*>(fields + 0x3ac);
            ++divisor;
            int remainder;
            __asm {
                mov eax,random
                mov ecx,divisor
                cdq
                idiv ecx
                mov remainder,edx
            }
            hostages = static_cast<int>(static_cast<uint>(hostages) + static_cast<uint>(remainder));
        }
        for (int index = 0; index < hostages; ++index) zone->AR6DeploymentZone::SpawnAHostage();
        *flags |= 0x100; // Initialization skips only prefix preparation; available repeated calls still run both spawn loops.
    }
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1001938f : DeploymentFirstInitCatchPointer
// Throws the unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentFirstInitCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043760 : DeploymentDestructionState0Cleanup
// Destroys the saved AActor base at inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl DeploymentDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043769 : DeploymentDestructionState1Cleanup
// Destroys the saved deployment group-ID array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043777 : DeploymentDestructionState2Cleanup
// Destroys the saved deployment hostage-zone array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDestructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3cc
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043785 : DeploymentDestructionState3Cleanup
// Destroys the saved deployment cover-node array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDestructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3d8
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043793 : DeploymentDestructionState4Cleanup
// Destroys the saved deployment terrorist array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDestructionState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3e4
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100437a1 : DeploymentDestructionState5Cleanup
// Destroys the saved deployment hostage array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDestructionState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3f0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100437af : DeploymentDestructionState6Cleanup
// Destroys five saved terrorist template strings backward using the native array iterator.
__declspec(naked) void __cdecl DeploymentDestructionState6Cleanup(void)
{
    __asm {
        push offset FStringDestructorNativeEntry
        push 0x5
        push 0x10
        mov eax,dword ptr [ebp-0x10]
        add eax,0x3fc
        push eax
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 100437c7 : DeploymentDestructionState7Cleanup
// Destroys five saved hostage template strings backward using the native array iterator.
__declspec(naked) void __cdecl DeploymentDestructionState7Cleanup(void)
{
    __asm {
        push offset FStringDestructorNativeEntry
        push 0x5
        push 0x10
        mov eax,dword ptr [ebp-0x10]
        add eax,0x44c
        push eax
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 100437f0 : DeploymentDefaultState0Cleanup
// Destroys the saved AActor base at inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl DeploymentDefaultState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 100437f9 : DeploymentDefaultState1Cleanup
// Destroys the saved deployment group-ID array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDefaultState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043807 : DeploymentDefaultState2Cleanup
// Destroys the saved deployment hostage-zone array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDefaultState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3cc
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043815 : DeploymentDefaultState3Cleanup
// Destroys the saved deployment cover-node array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDefaultState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3d8
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043823 : DeploymentDefaultState4Cleanup
// Destroys the saved deployment terrorist array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDefaultState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3e4
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043831 : DeploymentDefaultState5Cleanup
// Destroys the saved deployment hostage array through its native storage helper.
__declspec(naked) void __cdecl DeploymentDefaultState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3f0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 1004383f : DeploymentDefaultState6Cleanup
// Destroys five saved terrorist template strings backward using the native array iterator.
__declspec(naked) void __cdecl DeploymentDefaultState6Cleanup(void)
{
    __asm {
        push offset FStringDestructorNativeEntry
        push 0x5
        push 0x10
        mov eax,dword ptr [ebp-0x10]
        add eax,0x3fc
        push eax
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10043870 : DeploymentCopyState0Cleanup
// Destroys the saved AActor base at inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl DeploymentCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043879 : DeploymentCopyState1Cleanup
// Destroys the saved deployment group-ID array through its native storage helper.
__declspec(naked) void __cdecl DeploymentCopyState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3c0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043887 : DeploymentCopyState2Cleanup
// Destroys the saved deployment hostage-zone array through its native storage helper.
__declspec(naked) void __cdecl DeploymentCopyState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3cc
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043895 : DeploymentCopyState3Cleanup
// Destroys the saved deployment cover-node array through its native storage helper.
__declspec(naked) void __cdecl DeploymentCopyState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3d8
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100438a3 : DeploymentCopyState4Cleanup
// Destroys the saved deployment terrorist array through its native storage helper.
__declspec(naked) void __cdecl DeploymentCopyState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3e4
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100438b1 : DeploymentCopyState5Cleanup
// Destroys the saved deployment hostage array through its native storage helper.
__declspec(naked) void __cdecl DeploymentCopyState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x3f0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043d00 : DeploymentSpawnedState1Cleanup
// Destroys the reused FString temporary at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentSpawnedState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d09 : DeploymentSpawnedState2Cleanup
// Destroys the reused FString temporary at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentSpawnedState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d12 : DeploymentSpawnedState3Cleanup
// Destroys the reused FString temporary at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentSpawnedState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d30 : DeploymentValidateTemplatesState0Cleanup
// Destroys the first formatted warning string at dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentValidateTemplatesState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d39 : DeploymentValidateTemplatesState1Cleanup
// Destroys the second formatted warning string at dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentValidateTemplatesState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d42 : DeploymentValidateTemplatesState2Cleanup
// Destroys the terrorist-range editor warning at dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentValidateTemplatesState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043d4b : DeploymentValidateTemplatesState3Cleanup
// Destroys the hostage-range editor warning at dispatcher-frame EBP-0x18.
__declspec(naked) void __cdecl DeploymentValidateTemplatesState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043db0 : DeploymentRendererState1Cleanup
// Clears the hostage-icon initialization bit so a failed load/type check can be retried.
__declspec(naked) void __cdecl DeploymentRendererState1Cleanup(void)
{
    __asm {
        mov eax,dword ptr [nativeDeploymentIconInitializationFlags]
        and eax,0xfffffffe
        mov dword ptr [nativeDeploymentIconInitializationFlags],eax
        ret
    }
}

// R6Engine.dll @ 10043dbe : DeploymentRendererState2Cleanup
// Clears the mixed terrorist/hostage icon initialization bit after failed initialization.
__declspec(naked) void __cdecl DeploymentRendererState2Cleanup(void)
{
    __asm {
        mov eax,dword ptr [nativeDeploymentIconInitializationFlags]
        and eax,0xfffffffd
        mov dword ptr [nativeDeploymentIconInitializationFlags],eax
        ret
    }
}

// R6Engine.dll @ 10043dcc : DeploymentRendererState3Cleanup
// Destroys the active FLineBatcher at inherited dispatcher-frame EBP-0x8c.
__declspec(naked) void __cdecl DeploymentRendererState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x8c]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10043dd8 : DeploymentRendererExceptionHandler
// Supplies the exact renderer FuncInfo to the private native dispatcher.
__declspec(naked) void __cdecl DeploymentRendererExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentRendererFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043e10 : DeploymentInitTerroristState1Cleanup
// Destroys the original temporary string slot at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentInitTerroristState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043e19 : DeploymentInitTerroristState2Cleanup
// Destroys the original temporary string slot at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentInitTerroristState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043e22 : DeploymentInitTerroristState3Cleanup
// Destroys the original temporary string slot at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentInitTerroristState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043e2b : DeploymentInitTerroristState4Cleanup
// Destroys the original temporary string slot at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentInitTerroristState4Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043e40 : DeploymentInitHostageState1Cleanup
// Destroys the original temporary string slot at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentInitHostageState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043f10 : DeploymentExecOrderTerroristsState1Cleanup
// Destroys the ordering bridge's temporary score array at inherited dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl DeploymentExecOrderTerroristsState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp DestroyEmbeddedEightByteArrayPair
    }
}

// R6Engine.dll @ 10043f50 : DeploymentSpawnHostageState1Cleanup
// Destroys the complete temporary template at inherited EBP-0xd0.
__declspec(naked) void __cdecl DeploymentSpawnHostageState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xd0]
        jmp DestroyCharTemplate
    }
}

// R6Engine.dll @ 10043f5b : DeploymentSpawnHostageState2Cleanup
// Destroys the template leading FString at inherited EBP-0xd0.
__declspec(naked) void __cdecl DeploymentSpawnHostageState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xd0]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043f67 : DeploymentSpawnHostageState3Cleanup
// Destroys the template pawn array after later arrays have ended their lifetimes.
__declspec(naked) void __cdecl DeploymentSpawnHostageState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xc4]
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 10043f72 : DeploymentSpawnHostageState4Cleanup
// Destroys weapon-array storage at saved partial-template pointer EBP-0x18 plus0x40.
__declspec(naked) void __cdecl DeploymentSpawnHostageState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        add ecx,0x40
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 10043f90 : DeploymentSpawnTerroristState1Cleanup
// Destroys the complete temporary template at inherited EBP-0xf4.
__declspec(naked) void __cdecl DeploymentSpawnTerroristState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xf4]
        jmp DestroyCharTemplate
    }
}

// R6Engine.dll @ 10043f9b : DeploymentSpawnTerroristState2Cleanup
// Destroys the template leading FString at inherited EBP-0xf4.
__declspec(naked) void __cdecl DeploymentSpawnTerroristState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xf4]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043fa7 : DeploymentSpawnTerroristState3Cleanup
// Destroys the template pawn array after later arrays have ended their lifetimes.
__declspec(naked) void __cdecl DeploymentSpawnTerroristState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0xe8]
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 10043fb2 : DeploymentSpawnTerroristState4Cleanup
// Destroys weapon-array storage at saved partial-template pointer EBP-0x34 plus0x40.
__declspec(naked) void __cdecl DeploymentSpawnTerroristState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x34]
        add ecx,0x40
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 100463e0 : InitializeAR6DeploymentZoneClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DeploymentZoneClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AActor object address, captured before config lookup.
    UClass* parentClass = AActorPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DeploymentZone::PrivateStaticClass, 0, 0x49c, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DeploymentZone,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6DeploymentZone::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DeploymentZoneClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048060 : DestroyAR6DeploymentZoneClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DeploymentZoneClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DeploymentZone::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046470 : PublishAR6DeploymentZoneAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DeploymentZoneAutoClass(void)
{
    autoclassAR6DeploymentZone = &AR6DeploymentZone::PrivateStaticClass;
}

// R6Engine.dll @ 100472a0 : RegisterAR6DeploymentZoneGetClosestHostageNative
// Registers native index0x72e using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneGetClosestHostageNative(void)
{
    AR6DeploymentZoneGetClosestHostageRegistrationResult =
        GRegisterNative(0x72e, intAR6DeploymentZoneexecGetClosestHostage);
}

// R6Engine.dll @ 100472c0 : RegisterAR6DeploymentZoneOrderTerroListFromDistanceToNative
// Registers native index0x72d using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneOrderTerroListFromDistanceToNative(void)
{
    AR6DeploymentZoneOrderTerroListFromDistanceToRegistrationResult =
        GRegisterNative(0x72d,
            intAR6DeploymentZoneexecOrderTerroListFromDistanceTo);
}

// R6Engine.dll @ 100472e0 : RegisterAR6DeploymentZoneAddHostageNative
// Registers native index0x72c using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneAddHostageNative(void)
{
    AR6DeploymentZoneAddHostageRegistrationResult = GRegisterNative(0x72c, intAR6DeploymentZoneexecAddHostage);
}

// R6Engine.dll @ 10047300 : RegisterAR6DeploymentZoneHaveHostageNative
// Registers native index0x72b using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneHaveHostageNative(void)
{
    AR6DeploymentZoneHaveHostageRegistrationResult = GRegisterNative(0x72b, intAR6DeploymentZoneexecHaveHostage);
}

// R6Engine.dll @ 10047320 : RegisterAR6DeploymentZoneHaveTerroristNative
// Registers native index0x72a using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneHaveTerroristNative(void)
{
    AR6DeploymentZoneHaveTerroristRegistrationResult = GRegisterNative(0x72a, intAR6DeploymentZoneexecHaveTerrorist);
}

// R6Engine.dll @ 10047340 : RegisterAR6DeploymentZoneFindClosestPointToNative
// Registers native index0x729 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneFindClosestPointToNative(void)
{
    AR6DeploymentZoneFindClosestPointToRegistrationResult =
        GRegisterNative(0x729, intAR6DeploymentZoneexecFindClosestPointTo);
}

// R6Engine.dll @ 10047360 : RegisterAR6DeploymentZoneIsPointInZoneNative
// Registers native index0x728 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneIsPointInZoneNative(void)
{
    AR6DeploymentZoneIsPointInZoneRegistrationResult = GRegisterNative(0x728, intAR6DeploymentZoneexecIsPointInZone);
}

// R6Engine.dll @ 10047380 : RegisterAR6DeploymentZoneFindRandomPointInAreaNative
// Registers native index0x727 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneFindRandomPointInAreaNative(void)
{
    AR6DeploymentZoneFindRandomPointInAreaRegistrationResult =
        GRegisterNative(0x727, intAR6DeploymentZoneexecFindRandomPointInArea);
}

// R6Engine.dll @ 100473a0 : RegisterAR6DeploymentZoneFirstInitNative
// Registers native index0x726 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6DeploymentZoneFirstInitNative(void)
{
    AR6DeploymentZoneFirstInitRegistrationResult = GRegisterNative(0x726, intAR6DeploymentZoneexecFirstInit);
}

// R6Engine.dll @ 10018e3d : DeploymentSpawnHostageCatchContext
// Reports AR6DeploymentZone::SpawnAHostage and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneSpawnAHostage
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043f7d : DeploymentZoneSpawnAHostageExceptionHandler
// Supplies SpawnAHostage exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl DeploymentZoneSpawnAHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentSpawnHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001924f : DeploymentSpawnTerroristCatchContext
// Reports AR6DeploymentZone::SpawnTerrorist and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnTerroristCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneSpawnTerrorist
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043fbd : DeploymentZoneSpawnATerroristExceptionHandler
// Supplies SpawnATerrorist exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl DeploymentZoneSpawnATerroristExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentSpawnTerroristFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100193a3 : DeploymentFirstInitCatchContext
// Reports AR6DeploymentZone::FirstInit and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentFirstInitCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneFirstInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043fd0 : DeploymentZoneFirstInitExceptionHandler
// Supplies FirstInit exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl DeploymentZoneFirstInitExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentFirstInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10016fe6 : DeploymentTerroristCountCatchContext
// Reports AR6DeploymentZone::GetNbOfTerroristToSpawn and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentTerroristCountCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneGetNbOfTerroristToSpawn
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001708f : DeploymentExecFirstInitCatchContext
// Reports AR6DeploymentZone::execFirstInit and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentExecFirstInitCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneExecFirstInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043d54 : DeploymentValidateTemplatesExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentValidateTemplatesExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentValidateTemplatesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043d60 : DeploymentTerroristCountExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentTerroristCountExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentTerroristCountFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043d70 : DeploymentExecFirstInitExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentExecFirstInitExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentExecFirstInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100096d0 : ConstructFirstString
// Default-constructs the leading FString of a template element, leaving its trailing chance word unchanged.
FString* __thiscall ConstructFirstString(FString* firstString)
{
    ::new (firstString) FString;
    return firstString;
}

// R6Engine.dll @ 100096e0 : ConstructTemplateCopy
// Copy-constructs a template's leading FString, then copies its current raw chance word and returns the destination.
void* __thiscall ConstructTemplateCopy(void* destination, const void* source)
{
    ::new (reinterpret_cast<void*>(destination)) FString(*reinterpret_cast<const FString*>(source));
    *(uint*)((byte*)destination + 0xc) = *(const uint*)((const byte*)source + 0xc);
    return destination;
}

// R6Engine.dll @ 10012900 : AR6DeploymentZone::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DeploymentZone::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DeploymentZone* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DeploymentZoneDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x49c, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DeploymentZone::~AR6DeploymentZone(); // Direct native call10012520, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x49c);
    }
    return object;
}

// R6Engine.dll @ 100437df : DeploymentDestructionExceptionHandler
// Supplies exact cleanup-only FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl DeploymentDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043857 : DeploymentDefaultExceptionHandler
// Supplies exact cleanup-only FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl DeploymentDefaultExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentDefaultFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100438bf : DeploymentCopyExceptionHandler
// Supplies exact cleanup-only FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl DeploymentCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentCopyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10016c05 : DeploymentSpawnedCatchContext
// Reports AR6DeploymentZone::Spawned and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentSpawnedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneSpawned
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043d1b : DeploymentSpawnedExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl DeploymentSpawnedExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentSpawnedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10017e70 : DeploymentInitTerroristCatchContext
// Reports InitTerroristAI and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitTerroristCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneInitTerroristAI
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10017fee : DeploymentInitHostageCatchContext
// Reports InitHostageAI and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DeploymentInitHostageCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DeploymentZoneInitHostageAI
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043e34 : DeploymentInitTerroristExceptionHandler
// Supplies the exact initialization FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentInitTerroristExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentInitTerroristFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043e49 : DeploymentInitHostageExceptionHandler
// Supplies the exact initialization FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DeploymentInitHostageExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentInitHostageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000d5a0 : CopyConstructWordsDirect
// Reserves the captured source count, then directly copies words while following the live destination count.
FArray* __thiscall CopyConstructWordsDirect(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    // Native shared584a8 frame stays state-1 throughout; no storage cleanup is armed by this body.
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    destination->FArray::Realloc(4);
    int liveCount = destinationHeaderView->count;
    uint index = 0;
    while ((int)index < liveCount) {
        uint inputWord = *(const uint*)(sourceHeaderView->dataAddress + index * 4U);
        // Load destination Data after the input word.
        uint outputAddress = destinationHeaderView->dataAddress + index * 4U;
        *(uint*)outputAddress = inputWord;
        liveCount = destinationHeaderView->count;
        ++index;
    }
    return destination; // No identity shortcut, Add call, null-placement skip or post-allocation Num reset.
}

// R6Engine.dll @ 10016b00 : CopyStringToHiddenResult
// Copy-constructs a string at the hidden output, ignores constructor EAX, and preserves the source ECX register.
__declspec(naked) FString* __thiscall CopyStringToHiddenResult(const FString* source, FString* resultString)
{
    __asm {
        push ecx
        push esi
        mov esi,dword ptr [esp+0xc]
        push ecx
        mov ecx,esi
        mov dword ptr [esp+0x8],0x0
        call dword ptr [FStringCopyConstructorImport]
        mov eax,esi
        pop esi
        pop ecx
        ret 0x4
    }
}

// R6Engine.dll @ 100187b0 : DestroyEmbeddedEightByteArrayPair
// Removes the captured signed count of four-byte elements, then destroys array storage on normal or exceptional exit.
__declspec(naked) void __thiscall DestroyEmbeddedEightByteArrayPair(FArray* array)
{
    __asm {
        push -1
        push offset ArrayStorageExceptionHandler
        mov eax,dword ptr fs:[0]
        push eax
        mov dword ptr fs:[0],esp
        push ecx
        push ebx
        push esi
        mov esi,ecx
        push edi
        mov dword ptr [esp+0xc],esi
        // Capture signed count once before assertions; later count changes do not replace this removal count.
        mov edi,dword ptr [esi+0x4]
        test edi,edi
        mov ebx,dword ptr [CoreAppFailAssertImport]
        mov dword ptr [esp+0x18],0x0
        jge check_current_count
        // Report Index<=ArrayNum at line0x202; continue if assertion hook returns.
        push 0x202
        push offset nativePathUnTemplateH
        push offset nativeTextIndexArrayNum
        call ebx
        add esp,0xc
    check_current_count:
        // Reload current count for the second assertion against the captured count.
        cmp edi,dword ptr [esi+0x4]
        jle remove_elements
        push 0x203
        push offset nativePathUnTemplateH
        push offset nativeTextIndexCountArrayNum
        call ebx
        add esp,0xc
    remove_elements:
        push 0x4
        push edi
        push 0x0
        mov ecx,esi
        // FArray::Remove(0,capturedCount,4); no per-element destructor loop is added.
        call dword ptr [FArrayRemoveImport]
        mov ecx,esi
        // Disable this cleanup before entering the normal FArray destructor.
        mov dword ptr [esp+0x18],0xffffffff
        call dword ptr [FArrayDestructorImport]
        mov ecx,dword ptr [esp+0x10]
        pop edi
        pop esi
        pop ebx
        mov dword ptr fs:[0],ecx
        add esp,0x10
        ret
    }
}
