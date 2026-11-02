#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_array_views.hpp"

// Native helper declarations match their canonical definitions.
void __thiscall RemoveRecords4(FArray* array, int index, int count);
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl RandomPointsCopyConstructionExceptionHandler(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004d468 : AR6DZoneRandomPointsVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6DZoneRandomPoints::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6DZoneRandomPointsVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050350 : nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage1
extern const ushort nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage1[34];

// R6Engine.dll data @ 100503b8 : nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage2
extern const ushort nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage2[34];

// R6Engine.dll data @ 100501e0 : nativeTextAR6DZoneRandomPointsFindRandomPointInArea
extern const ushort nativeTextAR6DZoneRandomPointsFindRandomPointInArea[44];

// R6Engine.dll data @ 100502c0 : nativeTextAR6DZoneRandomPointsFindSpawningPoint
extern const ushort nativeTextAR6DZoneRandomPointsFindSpawningPoint[40];

// R6Engine.dll data @ 10050280 : nativeTextAR6DZoneRandomPointsFirstInit
extern const ushort nativeTextAR6DZoneRandomPointsFirstInit[32];

// R6Engine.dll data @ 100500d8 : nativeTextAR6DZoneRandomPointsGetNbOfTerroristToSpawn
extern const ushort nativeTextAR6DZoneRandomPointsGetNbOfTerroristToSpawn[46];

// R6Engine.dll data @ 10050458 : nativeTextAR6DZoneRandomPointsPostScriptDestroyed
extern const ushort nativeTextAR6DZoneRandomPointsPostScriptDestroyed[42];

// R6Engine.dll data @ 10050088 : nativeTextAR6DZoneRandomPointsRenderEditorInfo
extern const ushort nativeTextAR6DZoneRandomPointsRenderEditorInfo[39];

// R6Engine.dll data @ 10050238 : nativeTextAR6DZoneRandomPointsSpawnANewNode
extern const ushort nativeTextAR6DZoneRandomPointsSpawnANewNode[36];

// R6Engine.dll data @ 10050310 : nativeTextAR6DZoneRandomPointsSpawned
extern const ushort nativeTextAR6DZoneRandomPointsSpawned[30];

// R6Engine.dll data @ 10055842 : nativeTextR6DZoneRandomPoints
extern const ushort nativeTextR6DZoneRandomPoints[20];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl RandomPointsCopyConstructionState0Cleanup(void);
__declspec(naked) void __cdecl RandomPointsCopyConstructionState1Cleanup(void);
__declspec(naked) void __cdecl RandomPointsCopyConstructionState2Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsCreateNodeCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsCreateNodeCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeleteIndexCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeleteIndexCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeletePointerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeletePointerCatchPointer(void);
__declspec(naked) void __cdecl RandomPointsDestructionState0Cleanup(void);
__declspec(naked) void __cdecl RandomPointsDestructionState1Cleanup(void);
__declspec(naked) void __cdecl RandomPointsDestructionState2Cleanup(void);
__declspec(naked) void __cdecl RandomPointsDestructionState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsEditorCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsEditorCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFindSpawningPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFindSpawningPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFirstInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFirstInitCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsRandomLocationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsRandomLocationCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsSpawnedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsSpawnedCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTeardownCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTeardownCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTerroristCountCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTerroristCountCatchPointer(void);
__declspec(naked) void __cdecl RandomPointsValidationState0Cleanup(void);
__declspec(naked) void __cdecl RandomPointsValidationState1Cleanup(void);

// R6Engine.dll data @ 10058200 : randomPointsDestructionUnwindMap
// Binds pending native member/base destruction states to their exact private cleanup entries.
const NativeUnwindEntry randomPointsDestructionUnwindMap[4] = {
    { -1, ((uint)&RandomPointsDestructionState0Cleanup) },
    { 0, ((uint)&RandomPointsDestructionState1Cleanup) },
    { 0x1, ((uint)&RandomPointsDestructionState2Cleanup) },
    { 0x2, ((uint)&RandomPointsDestructionState3Cleanup) }
};

// R6Engine.dll data @ 10058220 : randomPointsDestructionFuncInfo
// Binds cleanup-only state transitions, with no catch or guard-report scope.
const NativeFunctionInfoPrefix randomPointsDestructionFuncInfo = { 0x19930520, 0x4,
    ((uint)&randomPointsDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 1005823c : randomPointsCopyConstructionUnwindMap
// Binds pending native member/base destruction states to their exact private cleanup entries.
const NativeUnwindEntry randomPointsCopyConstructionUnwindMap[3] = {
    { -1, ((uint)&RandomPointsCopyConstructionState0Cleanup) },
    { 0, ((uint)&RandomPointsCopyConstructionState1Cleanup) },
    { 0x1, ((uint)&RandomPointsCopyConstructionState2Cleanup) }
};

// R6Engine.dll data @ 10058254 : randomPointsCopyConstructionFuncInfo
// Binds cleanup-only state transitions, with no catch or guard-report scope.
const NativeFunctionInfoPrefix randomPointsCopyConstructionFuncInfo = { 0x19930520, 0x3,
    ((uint)&randomPointsCopyConstructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10059aa8 : randomPointsEditorUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsEditorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059ab8 : randomPointsEditorCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsEditorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsEditorCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsEditorCatchContext) }
};

// R6Engine.dll data @ 10059ad8 : randomPointsEditorTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsEditorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsEditorCatchMap) }
};

// R6Engine.dll data @ 10059aec : randomPointsEditorFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZoneRandomPoints::RenderEditorInfo.
const NativeFunctionInfoPrefix randomPointsEditorFuncInfo = { 0x19930520, 0x2, ((uint)&randomPointsEditorUnwindMap),
    0x1, ((uint)&randomPointsEditorTryMap), 0 };

// R6Engine.dll data @ 10059e34 : randomPointsTeardownUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsTeardownUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059e44 : randomPointsTeardownCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsTeardownCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsTeardownCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsTeardownCatchContext) }
};

// R6Engine.dll data @ 10059e64 : randomPointsTeardownTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsTeardownTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsTeardownCatchMap) }
};

// R6Engine.dll data @ 10059e78 : randomPointsTeardownFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZoneRandomPoints::PostScriptDestroyed.
const NativeFunctionInfoPrefix randomPointsTeardownFuncInfo = { 0x19930520, 0x2, ((uint)&randomPointsTeardownUnwindMap),
    0x1, ((uint)&randomPointsTeardownTryMap), 0 };

// R6Engine.dll data @ 10059bc8 : randomPointsCreateNodeUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsCreateNodeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059bd8 : randomPointsCreateNodeCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsCreateNodeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsCreateNodeCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsCreateNodeCatchContext) }
};

// R6Engine.dll data @ 10059bf8 : randomPointsCreateNodeTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsCreateNodeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsCreateNodeCatchMap) }
};

// R6Engine.dll data @ 10059c0c : randomPointsCreateNodeFuncInfo
// Binds the selected MSVC cleanup/catch maps for SpawnANewNode.
const NativeFunctionInfoPrefix randomPointsCreateNodeFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsCreateNodeUnwindMap), 0x1, ((uint)&randomPointsCreateNodeTryMap), 0 };

// R6Engine.dll data @ 10059ce8 : randomPointsSpawnedUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsSpawnedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059cf8 : randomPointsSpawnedCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsSpawnedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsSpawnedCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsSpawnedCatchContext) }
};

// R6Engine.dll data @ 10059d18 : randomPointsSpawnedTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsSpawnedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsSpawnedCatchMap) }
};

// R6Engine.dll data @ 10059d2c : randomPointsSpawnedFuncInfo
// Binds the selected MSVC cleanup/catch maps for Spawned.
const NativeFunctionInfoPrefix randomPointsSpawnedFuncInfo = { 0x19930520, 0x2, ((uint)&randomPointsSpawnedUnwindMap),
    0x1, ((uint)&randomPointsSpawnedTryMap), 0 };

// R6Engine.dll data @ 10059d48 : randomPointsDeleteIndexUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsDeleteIndexUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059d58 : randomPointsDeleteIndexCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsDeleteIndexCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsDeleteIndexCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsDeleteIndexCatchContext) }
};

// R6Engine.dll data @ 10059d78 : randomPointsDeleteIndexTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsDeleteIndexTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsDeleteIndexCatchMap) }
};

// R6Engine.dll data @ 10059d8c : randomPointsDeleteIndexFuncInfo
// Binds the selected MSVC cleanup/catch maps for DeleteANode(int).
const NativeFunctionInfoPrefix randomPointsDeleteIndexFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsDeleteIndexUnwindMap), 0x1, ((uint)&randomPointsDeleteIndexTryMap), 0 };

// R6Engine.dll data @ 10059da8 : randomPointsDeletePointerUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsDeletePointerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059db8 : randomPointsDeletePointerCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsDeletePointerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsDeletePointerCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsDeletePointerCatchContext) }
};

// R6Engine.dll data @ 10059dd8 : randomPointsDeletePointerTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsDeletePointerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsDeletePointerCatchMap) }
};

// R6Engine.dll data @ 10059dec : randomPointsDeletePointerFuncInfo
// Binds the selected MSVC cleanup/catch maps for DeleteANode(AR6DZoneRandomPointNode*).
const NativeFunctionInfoPrefix randomPointsDeletePointerFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsDeletePointerUnwindMap), 0x1, ((uint)&randomPointsDeletePointerTryMap), 0 };

// R6Engine.dll data @ 10059b08 : randomPointsTerroristCountUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsTerroristCountUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059b18 : randomPointsTerroristCountCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsTerroristCountCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsTerroristCountCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsTerroristCountCatchContext) }
};

// R6Engine.dll data @ 10059b38 : randomPointsTerroristCountTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsTerroristCountTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsTerroristCountCatchMap) }
};

// R6Engine.dll data @ 10059b4c : randomPointsTerroristCountFuncInfo
// Binds the selected MSVC cleanup/catch maps for GetNbOfTerroristToSpawn.
const NativeFunctionInfoPrefix randomPointsTerroristCountFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsTerroristCountUnwindMap), 0x1, ((uint)&randomPointsTerroristCountTryMap), 0 };

// R6Engine.dll data @ 10059b68 : randomPointsRandomLocationUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsRandomLocationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059b78 : randomPointsRandomLocationCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsRandomLocationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointsRandomLocationCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsRandomLocationCatchContext) }
};

// R6Engine.dll data @ 10059b98 : randomPointsRandomLocationTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsRandomLocationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsRandomLocationCatchMap) }
};

// R6Engine.dll data @ 10059bac : randomPointsRandomLocationFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindRandomPointInArea.
const NativeFunctionInfoPrefix randomPointsRandomLocationFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsRandomLocationUnwindMap), 0x1, ((uint)&randomPointsRandomLocationTryMap), 0 };

// R6Engine.dll data @ 10059e08 : randomPointsValidationUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsValidationUnwindMap[2] = {
    { -1, ((uint)&RandomPointsValidationState0Cleanup) },
    { -1, ((uint)&RandomPointsValidationState1Cleanup) }
};

// R6Engine.dll data @ 10059e18 : randomPointsValidationFuncInfo
// Binds the selected MSVC cleanup/catch maps for CheckForErrors.
const NativeFunctionInfoPrefix randomPointsValidationFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsValidationUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10059c28 : randomPointsFirstInitUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsFirstInitUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059c38 : randomPointsFirstInitCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsFirstInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RandomPointsFirstInitCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsFirstInitCatchContext) }
};

// R6Engine.dll data @ 10059c58 : randomPointsFirstInitTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsFirstInitTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsFirstInitCatchMap) }
};

// R6Engine.dll data @ 10059c6c : randomPointsFirstInitFuncInfo
// Binds the selected MSVC cleanup/catch maps for FirstInit.
const NativeFunctionInfoPrefix randomPointsFirstInitFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointsFirstInitUnwindMap), 0x1, ((uint)&randomPointsFirstInitTryMap), 0 };

// R6Engine.dll data @ 10059c88 : randomPointsFindSpawningPointUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointsFindSpawningPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059c98 : randomPointsFindSpawningPointCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointsFindSpawningPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RandomPointsFindSpawningPointCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointsFindSpawningPointCatchContext) }
};

// R6Engine.dll data @ 10059cb8 : randomPointsFindSpawningPointTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointsFindSpawningPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointsFindSpawningPointCatchMap) }
};

// R6Engine.dll data @ 10059ccc : randomPointsFindSpawningPointFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindSpawningPoint.
const NativeFunctionInfoPrefix randomPointsFindSpawningPointFuncInfo = {
    0x19930520, 0x2, ((uint)&randomPointsFindSpawningPointUnwindMap), 0x1, ((uint)&randomPointsFindSpawningPointTryMap),
        0
};

// R6Engine.dll data @ 100802e4 : autoclassAR6DZoneRandomPoints
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZoneRandomPoints = nullptr;

// R6Engine.dll @ 10009700 : AR6DZoneRandomPoints::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZoneRandomPoints::StaticClass(void)
{
    return &AR6DZoneRandomPoints::PrivateStaticClass; // Selected object at0x1007ee80.
}

// R6Engine.dll @ 10009710 : AR6DZoneRandomPoints::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZoneRandomPoints::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZoneRandomPoints::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100101b0 : AR6DZoneRandomPoints::operator=
// Assigns the base, three flag bits and node arrays, retaining both initial destination-word reads.
AR6DZoneRandomPoints& AR6DZoneRandomPoints::operator=(const AR6DZoneRandomPoints& source)
{
    AR6DeploymentZone::operator=(source);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x49c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(&source) + 0x49c);
    uint sourceWord = *sourceFlags;
    uint firstDestination = *destinationFlags;
    uint difference = firstDestination ^ sourceWord;
    uint currentDestination = *destinationFlags;
    uint flags = currentDestination ^ (difference & 1U);
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bUseAllowLeave.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bInInit.
    const FArray* masterSourceArgument = reinterpret_cast<const FArray*>(&source.m_aNode);
    *destinationFlags = flags;
    AssignRecords4(reinterpret_cast<FArray*>(&m_aNode), masterSourceArgument);
    AssignRecords4(reinterpret_cast<FArray*>(&m_aTempHighPriorityNode),
        reinterpret_cast<const FArray*>(&source.m_aTempHighPriorityNode));
    AssignRecords4(reinterpret_cast<FArray*>(&m_aTempNode), reinterpret_cast<const FArray*>(&source.m_aTempNode));
    return *this;
}

// R6Engine.dll @ 10012970 : AR6DZoneRandomPoints::~AR6DZoneRandomPoints
// Runs ConditionalDestroy, then implicitly destroys temp, high-priority, master storage and the base on all exits.
AR6DZoneRandomPoints::~AR6DZoneRandomPoints()
{
    // Compiler installs vtable1004d468 first; member cleanup uses1000e970, then base destructor10012520.
    UObject::ConditionalDestroy(); // Ignore its int result; native unwind states3..0 preserve pending cleanup.
}

// R6Engine.dll @ 100129f0 : AR6DZoneRandomPoints::AR6DZoneRandomPoints(void)
// Constructs the base and installs the derived vtable, without initializing the flags or three array headers.
// Native ABI view preserves explicit no-init/owned-array lifetimes and native cleanup coverage.
AR6DZoneRandomPoints* __thiscall AR6DZoneRandomPoints::AR6DZoneRandomPoints(AR6DZoneRandomPoints* object)
{
    // Native 0x10012600.
    (*(AR6DeploymentZone*
        (__thiscall*)(AR6DeploymentZone*))((uint)&AR6DeploymentZoneConstructorNativeEntry))(object);
    *(void**)object = (void*)&AR6DZoneRandomPointsVirtualTable;
    return object; // The explicit ABI view avoids inventing an original no-init member-constructor spelling.
}

// R6Engine.dll @ 10012a10 : AR6DZoneRandomPoints::AR6DZoneRandomPoints
// Copies the base, flags and three arrays while preserving pre-vtable reads and completed-prefix cleanup.
// Native ABI view retains the original registration, delayed state0 and byte-width state transitions.
AR6DZoneRandomPoints* __thiscall AR6DZoneRandomPoints::AR6DZoneRandomPoints(
    AR6DZoneRandomPoints* object, const AR6DZoneRandomPoints* source)
{
    uint guard[4]; // Inferred saved-object/previous SEH/handler/state words; not class storage.
    guard[3] = 0xffffffff;
    guard[2] = reinterpret_cast<uint>(&RandomPointsCopyConstructionExceptionHandler);
    guard[1] = reinterpret_cast<uint>(ExceptionList);
    ExceptionList = &guard[1];
    const AR6DeploymentZone* baseSourceArgument = static_cast<const AR6DeploymentZone*>(source);
    guard[0] = reinterpret_cast<uint>(object);
    AR6DeploymentZone::AR6DeploymentZone(static_cast<AR6DeploymentZone*>(object), baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(object) + 0x49c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x49c);
    uint earlyFlags = *destinationFlags;
    *reinterpret_cast<uint*>(object) = reinterpret_cast<uint>(&AR6DZoneRandomPointsVirtualTable);
    uint sourceWord = *sourceFlags;
    uint difference = earlyFlags ^ sourceWord;
    uint currentFlags = *destinationFlags;
    uint flags = currentFlags ^ (difference & 1U);
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bUseAllowLeave.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bInInit.
    const FArray* masterSourceArgument = reinterpret_cast<const FArray*>(&source->m_aNode);
    *destinationFlags = flags;
    FArray* masterDestinationArgument = reinterpret_cast<FArray*>(&object->m_aNode);
    guard[3] = 0;
    CopyConstructRecords4(masterDestinationArgument, masterSourceArgument);
    const FArray* highSourceArgument = reinterpret_cast<const FArray*>(&source->m_aTempHighPriorityNode);
    FArray* highDestinationArgument = reinterpret_cast<FArray*>(&object->m_aTempHighPriorityNode);
    *reinterpret_cast<byte*>(&guard[3]) = 1;
    CopyConstructRecords4(highDestinationArgument, highSourceArgument);
    const FArray* tempSourceArgument = reinterpret_cast<const FArray*>(&source->m_aTempNode);
    FArray* tempDestinationArgument = reinterpret_cast<FArray*>(&object->m_aTempNode);
    *reinterpret_cast<byte*>(&guard[3]) = 2;
    CopyConstructRecords4(tempDestinationArgument, tempSourceArgument);
    ExceptionList = reinterpret_cast<void*>(guard[1]);
    return object;
}

// R6Engine.dll @ 10013a90 : AR6DZoneRandomPoints::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZoneRandomPoints::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZoneRandomPointsConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001ad10 : AR6DZoneRandomPoints::RenderEditorInfo
// Claims unowned nodes and offsets their locations from the live list's penultimate node after base rendering.
void __thiscall AR6DZoneRandomPoints::RenderEditorInfo(FLevelSceneNode* sceneNode,
    FRenderInterface* renderInterface, FDynamicActor* dynamicActor)
{
    AR6DZoneRandomPoints* zone = this;
    try {
        zone->AR6DeploymentZone::RenderEditorInfo(sceneNode, renderInterface, dynamicActor);
        const NativeArrayHeader32* nodes = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
        uint index = 0;
        while ((int)index < nodes->count) {
            uint dataAddress = nodes->dataAddress;
            AR6DZoneRandomPointNode* node = *reinterpret_cast<AR6DZoneRandomPointNode**>(dataAddress + index * 4U);
            if (node->m_pZone == nullptr) {
                node->m_pZone = zone;
                uint count = reinterpret_cast<const uint&>(nodes->count);
                uint currentData = nodes->dataAddress;
                AR6DZoneRandomPointNode* anchor =
                    *reinterpret_cast<AR6DZoneRandomPointNode**>(currentData + count * 4U - 8U);
                const volatile float* coordinates = (const volatile float*)&anchor->Location;
                // float10 denotes native x87 work; X spills before reading Y, while Y spills after writing X.
                float10 x = (float10)coordinates[0] + (float10)25.0f;
                float roundedX = (float)x;
                float10 y = (float10)coordinates[1];
                uint z = reinterpret_cast<const uint&>(anchor->Location.Z);
                y += (float10)25.0f;
                reinterpret_cast<uint&>(node->Location.X) = reinterpret_cast<const uint&>(roundedX);
                node->Location.Y = (float)y;
                reinterpret_cast<uint&>(node->Location.Z) = z; // Raw copy; no x87 load or NaN quieting for Z here.
            }
            ++index; // Live count/data are read again; no null or minimum-count check is added.
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001adc5 : RandomPointsEditorCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsEditorCatchPointer(void)
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

// R6Engine.dll @ 1001ae10 : AR6DZoneRandomPoints::GetNbOfTerroristToSpawn
// Chooses the game-type or zone count, warns when nodes are insufficient and returns the live post-warning node count.
int __thiscall AR6DZoneRandomPoints::GetNbOfTerroristToSpawn(void)
{
    AR6DZoneRandomPoints* zone = this;
    using CountOverrideCall = uint (__thiscall *)(ALevelInfo*, const FString&);
    ALevelInfo* initialLevel = zone->Level;
    const FString& initialGameType = initialLevel->Game->m_szGameTypeFlag;
    try {
        CountOverrideCall overrideCount =
            reinterpret_cast<CountOverrideCall&>(ALevelInfoEventGameTypeUseNbOfTerroristToSpawnImport);
        uint suppliesCount = overrideCount(initialLevel, initialGameType);
        bool useGameCount = suppliesCount != 0;
        if (!useGameCount) {
            ALevelInfo* level = zone->Level;
            useGameCount = level->Game->m_szGameTypeFlag.operator==((const ushort*)L"RGM_CountDownMode") != 0;
        }
        int requestedCount;
        if (!useGameCount) {
            int minimum = zone->m_iMinTerrorist;
            requestedCount = minimum;
            if (zone->m_iMaxTerrorist > minimum) {
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
                requestedCount = (int)((uint)minimum + (uint)remainder);
            }
        } else {
            ALevelInfo* level = zone->Level; // Reload after the event or game-type comparison callback.
            if (level->NetMode == 0) {
                UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
                UClient* client = engine->Client;
                // Native first-viewport storage; the client prefix remains a partial view.
                UPlayer** viewports = *reinterpret_cast<UPlayer***>(reinterpret_cast<byte*>(client) + 0x30);
                UPlayer* viewport = viewports[0];
                requestedCount = viewport->Console->Master->m_StartGameInfo->m_iNbTerro;
            } else {
                // R6AbstractGameInfo.m_iNbOfTerroristToSpawn, without an added class check.
                requestedCount = *(const int*)((const byte*)level->Game + 0x4d8);
            }
        }
        const NativeArrayHeader32* nodeList = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
        int nodeCount = nodeList->count;
        if (requestedCount > nodeCount) {
            const ushort* zoneName = zone->UObject::GetName();
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L"WARNING!! Trying to spawn %i terrorists in zone %s with %i nodes",
                requestedCount, zoneName, nodeCount);
            requestedCount = nodeList->count; // May grow or shrink during reporting.
        }
        return requestedCount;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::GetNbOfTerroristToSpawn");
        throw;
    }
}

// R6Engine.dll @ 1001af21 : RandomPointsTerroristCountCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTerroristCountCatchPointer(void)
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

// R6Engine.dll @ 1001af60 : AR6DZoneRandomPoints::FindRandomPointInArea
// Copies one node location using a cached signed count, or logs and copies the imported zero vector on an empty list.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZoneRandomPoints::FindRandomPointInArea(FVector* result)
{
    AR6DZoneRandomPoints* zone = this;
    const NativeArrayHeader32* zoneNodes = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    int nodeCount = zoneNodes->count; // Captured before the guarded state.
    try {
        const FVector* location;
        if (nodeCount == 0) {
            const ushort* zoneName = zone->UObject::GetName();
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L"WARNING!! %s don't have any node", zoneName);
            location = *(const FVector**)&FVectorFVector0Import;
        } else {
            int randomValue = appRand();
            int selectedIndex;
            __asm {
                mov eax,randomValue
                cdq
                idiv nodeCount
                mov selectedIndex,edx
            }
            AR6DZoneRandomPointNode** nodes = reinterpret_cast<AR6DZoneRandomPointNode**>(zoneNodes->dataAddress);
            location = &nodes[selectedIndex]->Location;
        }
        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(location->X);
        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(location->Y);
        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(location->Z);
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::FindRandomPointInArea");
        throw;
    }
}

// R6Engine.dll @ 1001aff9 : RandomPointsRandomLocationCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsRandomLocationCatchPointer(void)
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

// R6Engine.dll @ 1001b030 : AR6DZoneRandomPoints::FindClosestPointTo
// Keeps the first ordered minimum, retaining the initial x87 score and the float-rounded score of each later winner.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZoneRandomPoints::FindClosestPointTo(FVector* result, const FVector* point)
{
    AR6DZoneRandomPoints* zone = this;
    // float10 denotes the native x87 working value, not a recovered original C++ type spelling.
    const NativeArrayHeader32* nodeList = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    AR6DZoneRandomPointNode** nodes = reinterpret_cast<AR6DZoneRandomPointNode**>(nodeList->dataAddress);
    AR6DZoneRandomPointNode* first = nodes[0]; // No empty-list check precedes this load.
    const volatile float* query = (const volatile float*)point;
    float10 deltaX = (float10)first->Location.X - (float10)query[0];
    int nodeCount = nodeList->count;
    float10 initialY = (float10)first->Location.Y;
    uint bestY = reinterpret_cast<const uint&>(first->Location.Y);
    float10 deltaY = initialY - (float10)query[1];
    uint bestZ = reinterpret_cast<const uint&>(first->Location.Z);
    float10 deltaZ = (float10)first->Location.Z - (float10)query[2];
    uint bestX = reinterpret_cast<const uint&>(first->Location.X);
    float10 bestDistance = deltaZ * deltaZ;
    float10 ySquare = deltaY * deltaY;
    bestDistance += ySquare;
    float10 xSquare = deltaX * deltaX;
    bestDistance += xSquare; // The initial best remains in x87 precision, without a float spill.
    uint index = 1;
    uint forcedCandidates = 0;
    if ((int)((uint)nodeCount - 1U) >= 4) {
        uint groups = (((uint)nodeCount - 5U) >> 2) + 1U;
        forcedCandidates = groups * 4U; // Preserve the native unrolled schedule for wrapped invalid counts too.
    }
    while (forcedCandidates != 0 || (int)index < nodeCount) {
        AR6DZoneRandomPointNode* node = nodes[index];
        deltaX = (float10)node->Location.X - (float10)query[0];
        deltaY = (float10)node->Location.Y - (float10)query[1];
        deltaZ = (float10)node->Location.Z - (float10)query[2];
        float10 candidateDistance = deltaZ * deltaZ;
        ySquare = deltaY * deltaY;
        candidateDistance += ySquare;
        xSquare = deltaX * deltaX;
        candidateDistance += xSquare;
        volatile float roundedDistance = (float)candidateDistance; // Native FST occurs even for a losing candidate.
        ushort comparisonStatus;
        __asm {
            fld tbyte ptr candidateDistance
            fld tbyte ptr bestDistance
            fxch st(1)
            fcomp st(1)
            fnstsw ax
            mov comparisonStatus,ax
            fstp st(0)
        }
        if ((((comparisonStatus >> 8) ^ (comparisonStatus >> 10)) & 1U) != 0) { // Native C0 xor C2 parity test.
            bestX = reinterpret_cast<const uint&>(node->Location.X);
            bestY = reinterpret_cast<const uint&>(node->Location.Y);
            bestDistance = (float10)roundedDistance;
            bestZ = reinterpret_cast<const uint&>(node->Location.Z);
        }
        ++index;
        if (forcedCandidates != 0) --forcedCandidates;
    }
    reinterpret_cast<uint&>(result->X) = bestX;
    reinterpret_cast<uint&>(result->Y) = bestY;
    reinterpret_cast<uint&>(result->Z) = bestZ;
    return result;
}

// R6Engine.dll @ 1001b2a0 : AR6DZoneRandomPoints::SpawnANewNode
// Spawns a node with zero name/rotation/options, appends the returned pointer, then assigns its zone back-pointer.
void __thiscall AR6DZoneRandomPoints::SpawnANewNode(FVector location)
{
    AR6DZoneRandomPoints* zone = this;
    using SpawnCall = AActor* (__thiscall *)(ULevel*, UClass*, FName, FVector, FRotator,
        AActor*, int, int, AActor*, APawn*);
    using AddCall = int (__thiscall *)(FArray*, int, int);
    FRotator rotation;
    rotation.Pitch = 0;
    rotation.Yaw = 0;
    rotation.Roll = 0;
    ULevel* level = zone->XLevel;
    FName name;
    reinterpret_cast<uint&>(name) = 0;
    SpawnCall spawn = *(SpawnCall*)(*(byte**)level + 0xa8);
    try { // Native state0 begins immediately before the virtual spawn call, after preparing its arguments.
        AR6DZoneRandomPointNode* node = static_cast<AR6DZoneRandomPointNode*>(
            spawn(level, &AR6DZoneRandomPointNode::PrivateStaticClass, name, location, rotation,
                nullptr, 0, 0, nullptr, nullptr));
        NativeArrayHeader32* nodes = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aNode);
        AddCall add = reinterpret_cast<AddCall&>(FArrayAddImport);
        int index = add(reinterpret_cast<FArray*>(nodes), 1, 4);
        // Read storage after Add, while retaining the original spawn result.
        AR6DZoneRandomPointNode** data = reinterpret_cast<AR6DZoneRandomPointNode**>(nodes->dataAddress);
        data[index] = node;
        node->m_pZone = zone; // Native code writes even after a null spawn result.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::SpawnANewNode");
        throw;
    }
}

// R6Engine.dll @ 1001b341 : RandomPointsCreateNodeCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsCreateNodeCatchPointer(void)
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

// R6Engine.dll @ 1001b380 : AR6DZoneRandomPoints::FirstInit
// Rebuilds both temporary node lists, then runs base initialization with m_bInInit set until normal return.
void __thiscall AR6DZoneRandomPoints::FirstInit(void)
{
    AR6DZoneRandomPoints* zone = this;
    using ReallocCall = void (__thiscall *)(FArray*, int);
    using AddCall = int (__thiscall *)(FArray*, int, int);
    // Native +0x4ac.
    NativeArrayHeader32* high = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aTempHighPriorityNode);
    NativeArrayHeader32* other = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aTempNode); // Native +0x4b8.
    const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    try {
        // The native pointer-element destruction loops only reread count; they do not touch the old elements.
        for (int index = 0; index < reinterpret_cast<const volatile NativeArrayHeader32*>(high)->count; ++index) {}
        ReallocCall reallocate = reinterpret_cast<ReallocCall&>(FArrayReallocImport);
        high->count = 0;
        high->capacity = 0;
        reallocate(reinterpret_cast<FArray*>(high), 4);
        for (int index = 0; index < reinterpret_cast<const volatile NativeArrayHeader32*>(other)->count; ++index) {}
        other->count = 0;
        other->capacity = 0;
        reallocate(reinterpret_cast<FArray*>(other), 4); // Reuse the function pointer captured before the first reset.
        int nodeIndex = 0;
        while (nodeIndex < nodesHeader->count) {
            AR6DZoneRandomPointNode** nodes = reinterpret_cast<AR6DZoneRandomPointNode**>(nodesHeader->dataAddress);
            AR6DZoneRandomPointNode* node = nodes[nodeIndex];
            NativeArrayHeader32* destination = (reinterpret_cast<const byte*>(node)[0x39c] & 1) != 0 ? high : other;
            AddCall add = reinterpret_cast<AddCall&>(FArrayAddImport);
            int addedIndex = add(reinterpret_cast<FArray*>(destination), 1, 4);
            AR6DZoneRandomPointNode** destinationData =
                reinterpret_cast<AR6DZoneRandomPointNode**>(destination->dataAddress);
            destinationData[addedIndex] = node;
            ++nodeIndex; // The next iteration reloads the master count and data after Add.
        }
        uint* flags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(zone) + 0x49c);
        *flags |= 4U; // m_bInInit; preserve the other bits.
        zone->AR6DeploymentZone::FirstInit();
        *flags &= ~4U; // Clear on normal return only, without restoring the old bit value.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::FirstInit");
        throw;
    }
}

// R6Engine.dll @ 1001b473 : RandomPointsFirstInitCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFirstInitCatchPointer(void)
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

// R6Engine.dll @ 1001b4b0 : AR6DZoneRandomPoints::FindSpawningPoint
// Selects a node, consumes a temporary entry during initialization, writes attributes and finally copies location.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZoneRandomPoints::FindSpawningPoint(FVector* result,
    FRotator* rotationOut, int* groupOut, EStance* stanceOut, int* allowLeaveOut)
{
    AR6DZoneRandomPoints* zone = this;
    NativeArrayHeader32* high = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aTempHighPriorityNode);
    const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    int highCount = high->count; // This read precedes the native guarded state.
    try {
        NativeArrayHeader32* candidates =
            highCount != 0 ? high : reinterpret_cast<NativeArrayHeader32*>(&zone->m_aTempNode);
        int nodeCount = nodesHeader->count;
        if (nodeCount == 0) {
            const ushort* zoneName = zone->UObject::GetName();
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L"WARNING!! %s don't have any node", zoneName);
            const FVector* zero = *(const FVector**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(zero->X);
            reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(zero->Z);
            return result; // Rotation, group, stance and allow-leave outputs remain untouched.
        }
        AR6DZoneRandomPointNode* node;
        int temporaryCount = 0;
        if ((reinterpret_cast<const byte*>(zone)[0x49c] & 4) != 0)
            temporaryCount = candidates->count;
        if (temporaryCount != 0) {
            int divisor = temporaryCount;
            int randomValue = appRand();
            int selectedIndex;
            __asm {
                mov eax,randomValue
                cdq
                idiv divisor
                mov selectedIndex,edx
            }
            AR6DZoneRandomPointNode** data = reinterpret_cast<AR6DZoneRandomPointNode**>(candidates->dataAddress);
            node = data[selectedIndex];
            RemoveRecords4(reinterpret_cast<FArray*>(candidates), selectedIndex, 1);
        } else {
            int randomValue = appRand();
            int selectedIndex;
            __asm {
                mov eax,randomValue
                cdq
                idiv nodeCount
                mov selectedIndex,edx
            }
            AR6DZoneRandomPointNode** data = reinterpret_cast<AR6DZoneRandomPointNode**>(nodesHeader->dataAddress);
            node = data[selectedIndex];
        }
        rotationOut->Pitch = node->Rotation.Pitch;
        rotationOut->Yaw = node->Rotation.Yaw;
        rotationOut->Roll = node->Rotation.Roll;
        *groupOut = node->m_iGroupID;
        *stanceOut = (EStance)(byte)node->m_eStance; // Native node storage is one byte; the output is a DWORD.
        *allowLeaveOut = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(node) + 0x39c) >> 1) & 1U;
        // Preserve raw word copies and their order after all attribute outputs, including aliases into the node.
        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(node->Location.X);
        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(node->Location.Y);
        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(node->Location.Z);
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::FindSpawningPoint");
        throw;
    }
}

// R6Engine.dll @ 1001b5e4 : RandomPointsFindSpawningPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFindSpawningPointCatchPointer(void)
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

// R6Engine.dll @ 1001b620 : AR6DZoneRandomPoints::Spawned
// Runs base initialization, then creates a node at the resulting location with a 100-unit positive Y offset.
void __thiscall AR6DZoneRandomPoints::Spawned(void)
{
    AR6DZoneRandomPoints* zone = this;
    try {
        zone->AR6DeploymentZone::Spawned();
        // float10 denotes native x87 working values; Z is loaded and stored through x87 too, rather than copied raw.
        const volatile float* actorLocation = (const volatile float*)&zone->Location;
        float10 z = (float10)actorLocation[2];
        float10 y = (float10)actorLocation[1];
        uint x = reinterpret_cast<const uint&>(zone->Location.X);
        y += (float10)100.0f;
        FVector nodeLocation;
        reinterpret_cast<uint&>(nodeLocation.X) = x;
        nodeLocation.Y = (float)y;
        nodeLocation.Z = (float)z;
        zone->AR6DZoneRandomPoints::SpawnANewNode(nodeLocation);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::Spawned");
        throw;
    }
}

// R6Engine.dll @ 1001b69d : RandomPointsSpawnedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsSpawnedCatchPointer(void)
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

// R6Engine.dll @ 1001b6d0 : AR6DZoneRandomPoints::DeleteANode(int)
// Removes the indexed entry before checking its live deletion flag and requesting destruction from the current level.
void __thiscall AR6DZoneRandomPoints::DeleteANode(int nodeIndex)
{
    AR6DZoneRandomPoints* zone = this;
    using DestroyCall = int (__thiscall *)(ULevel*, AActor*, int);
    const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    int nodeCount = nodesHeader->count; // Captured before the guarded state.
    try {
        if (nodeIndex >= nodeCount) { // Native assertion has no lower-bound test and may return.
            appFailAssert("iIndex<m_aNode.Num()", ".\\Src\\AR6DZoneRandomPoints.cpp", 0x109);
        }
        uint dataAddress = nodesHeader->dataAddress; // Read after any assertion callback.
        AActor* node = *reinterpret_cast<AActor**>(dataAddress + (uint)nodeIndex * 4U);
        RemoveRecords4(reinterpret_cast<FArray*>(&zone->m_aNode), nodeIndex, 1);
        if ((reinterpret_cast<const byte*>(node)[0xa0] & 0x80U) == 0) { // Live bDeleteMe after removal.
            ULevel* level = zone->XLevel;
            DestroyCall destroy = *(DestroyCall*)(*(byte**)level + 0xa0);
            destroy(level, node, 0); // Ignore the result; do not clear the node's owner or remove temporary entries.
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::DeleteANode");
        throw;
    }
}

// R6Engine.dll @ 1001b764 : RandomPointsDeleteIndexCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeleteIndexCatchPointer(void)
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

// R6Engine.dll @ 1001b7a0 : AR6DZoneRandomPoints::DeleteANode(AR6DZoneRandomPointNode*)
// Scans the live master list and delegates deletion of its first matching node, then returns without rescanning.
void __thiscall AR6DZoneRandomPoints::DeleteANode(AR6DZoneRandomPointNode* node)
{
    AR6DZoneRandomPoints* zone = this;
    try {
        uint nodeIndex = 0;
        while ((int)nodeIndex < *(const int*)((const byte*)&zone->m_aNode + 4)) {
            uint dataAddress = reinterpret_cast<const uint&>(zone->m_aNode);
            if (*(const uint*)(dataAddress + nodeIndex * 4U) == (uint)node) {
                zone->AR6DZoneRandomPoints::DeleteANode((int)nodeIndex);
                break;
            }
            ++nodeIndex;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::DeleteANode");
        throw;
    }
}

// R6Engine.dll @ 1001b7fc : RandomPointsDeletePointerCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeletePointerCatchPointer(void)
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

// R6Engine.dll @ 1001b830 : AR6DZoneRandomPoints::CheckForErrors
// Reports missing nodes, removes foreign-owned list entries after warning callbacks, then validates base settings.
void __thiscall AR6DZoneRandomPoints::CheckForErrors(void)
{
    AR6DZoneRandomPoints* zone = this;
    using MapCheckCall = void (__thiscall *)(FFeedbackContext*, int, UObject*, const ushort*);
    const NativeArrayHeader32* nodeList = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    if (nodeList->count == 0) {
        const ushort* zoneName = zone->UObject::GetName();
        FString text = FString::Printf((const ushort*)L"%s don't have any node!", zoneName);
        FFeedbackContext* warning = **(FFeedbackContext***)&CoreGWarnImport;
        byte* table = *(byte**)warning;
        const ushort* detail = *text;
        // Retain the old table but reload its receiver after dereference.
        warning = **(FFeedbackContext***)&CoreGWarnImport;
        MapCheckCall report = *(MapCheckCall*)(table + 0x28);
        report(warning, 0, zone, detail);
    }
    for (int index = 0; index < nodeList->count; ++index) {
        AR6DZoneRandomPointNode** nodes = reinterpret_cast<AR6DZoneRandomPointNode**>(nodeList->dataAddress);
        AR6DZoneRandomPointNode* node = nodes[index];
        if (node->m_pZone != zone) {
            const ushort* zoneName = zone->UObject::GetName();
            const ushort* ownerName = node->m_pZone->UObject::GetName(); // Reload owner after GetName(zone).
            const ushort* nodeName = node->UObject::GetName();
            {
                FString text = FString::Printf(
                    (const ushort*)L"%s belong %s and have been removed from %s",
                    nodeName, ownerName, zoneName);
                FFeedbackContext* warning = **(FFeedbackContext***)&CoreGWarnImport;
                byte* table = *(byte**)warning;
                const ushort* detail = *text;
                warning = **(FFeedbackContext***)&CoreGWarnImport;
                MapCheckCall report = *(MapCheckCall*)(table + 0x28);
                report(warning, 0, zone, detail);
            }
            RemoveRecords4(reinterpret_cast<FArray*>(&zone->m_aNode), index, 1);
            --index; // Revisit this index in the live array; do not delete the cached actor or clear its owner.
        }
    }
    zone->AR6DeploymentZone::CheckForErrors(true);
}

// R6Engine.dll @ 1001b970 : AR6DZoneRandomPoints::PostScriptDestroyed
// Removes each first node before destroying it, then clears the master header and releases its storage.
void __thiscall AR6DZoneRandomPoints::PostScriptDestroyed(void)
{
    AR6DZoneRandomPoints* zone = this;
    using RemoveCall = void (__thiscall *)(FArray*, int, int, int);
    using DestroyCall = void (__thiscall *)(AActor*, AActor*);
    using ReallocCall = void (__thiscall *)(FArray*, int);
    NativeArrayHeader32* nodes = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aNode);
    const volatile int& count = nodes->count;
    try {
        while (count > 0) {
            AActor* node = *reinterpret_cast<AActor**>(nodes->dataAddress);
            if (count < 0) {
                appFailAssert("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
            }
            if (count < 1) {
                appFailAssert("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
            }
            // The native one-element pointer destruction loop has no element accesses or calls.
            RemoveCall remove = reinterpret_cast<RemoveCall&>(FArrayRemoveImport);
            remove(reinterpret_cast<FArray*>(nodes), 0, 1, 4);
            DestroyCall destroy = reinterpret_cast<DestroyCall&>(AActorSafeDestroyActorImport);
            destroy(zone, node); // Retain this cached node even if removal changed storage or its owner.
        }
        for (int index = 0; index < count; ++index) {} // Native pointer-element loop only rereads the live count.
        nodes->count = 0;
        nodes->capacity = 0;
        ReallocCall reallocate = reinterpret_cast<ReallocCall&>(FArrayReallocImport);
        reallocate(reinterpret_cast<FArray*>(nodes), 4);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPoints::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 1001ba5f : RandomPointsTeardownCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTeardownCatchPointer(void)
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

// R6Engine.dll @ 100438d0 : RandomPointsDestructionState0Cleanup
// Destroys the saved base at dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl RandomPointsDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6DeploymentZoneDestructorNativeEntry
    }
}

// R6Engine.dll @ 100438d8 : RandomPointsDestructionState1Cleanup
// Destroys master node-array storage at saved object+0x4a0.
__declspec(naked) void __cdecl RandomPointsDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4a0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100438e6 : RandomPointsDestructionState2Cleanup
// Destroys high-priority temporary storage at saved object+0x4ac.
__declspec(naked) void __cdecl RandomPointsDestructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4ac
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100438f4 : RandomPointsDestructionState3Cleanup
// Destroys temporary storage at saved object+0x4b8.
__declspec(naked) void __cdecl RandomPointsDestructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4b8
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043910 : RandomPointsCopyConstructionState0Cleanup
// Destroys the completed base when copy construction fails.
__declspec(naked) void __cdecl RandomPointsCopyConstructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6DeploymentZoneDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043918 : RandomPointsCopyConstructionState1Cleanup
// Destroys completed master storage when later array construction fails.
__declspec(naked) void __cdecl RandomPointsCopyConstructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4a0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043926 : RandomPointsCopyConstructionState2Cleanup
// Destroys completed high-priority storage when the final array construction fails.
__declspec(naked) void __cdecl RandomPointsCopyConstructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4ac
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100441e0 : RandomPointsValidationState0Cleanup
// Destroys the empty-list warning FString at dispatcher-frame EBP-0x24.
__declspec(naked) void __cdecl RandomPointsValidationState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100441e9 : RandomPointsValidationState1Cleanup
// Destroys the ownership warning FString at dispatcher-frame EBP-0x18.
__declspec(naked) void __cdecl RandomPointsValidationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100480c0 : DestroyAR6DZoneRandomPointsClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZoneRandomPointsClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZoneRandomPoints::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046760 : InitializeAR6DZoneRandomPointsClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZoneRandomPointsClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZoneRandomPoints::PrivateStaticClass, 0, 0x4c4, 0,
        &AR6DeploymentZone::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZoneRandomPoints,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6DZoneRandomPoints::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZoneRandomPointsClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100467e0 : PublishAR6DZoneRandomPointsAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZoneRandomPointsAutoClass(void)
{
    autoclassAR6DZoneRandomPoints = &AR6DZoneRandomPoints::PrivateStaticClass;
}

// R6Engine.dll @ 1001b487 : RandomPointsFirstInitCatchContext
// Reports AR6DZoneRandomPoints::FirstInit and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFirstInitCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsFirstInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001b5f8 : RandomPointsFindSpawningPointCatchContext
// Reports AR6DZoneRandomPoints::FindSpawningPoint and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsFindSpawningPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsFindSpawningPoint
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044190 : RandomPointsFirstInitExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsFirstInitExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsFirstInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100441a0 : RandomPointsFindSpawningPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsFindSpawningPointExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsFindSpawningPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100441f2 : RandomPointsValidationExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsValidationExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsValidationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001af35 : RandomPointsTerroristCountCatchContext
// Reports AR6DZoneRandomPoints::GetNbOfTerroristToSpawn and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTerroristCountCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsGetNbOfTerroristToSpawn
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001b00d : RandomPointsRandomLocationCatchContext
// Reports AR6DZoneRandomPoints::FindRandomPointInArea and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsRandomLocationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsFindRandomPointInArea
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044160 : RandomPointsTerroristCountExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsTerroristCountExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsTerroristCountFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044170 : RandomPointsRandomLocationExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsRandomLocationExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsRandomLocationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001b778 : RandomPointsDeleteIndexCatchContext
// Reports AR6DZoneRandomPoints::DeleteANode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeleteIndexCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage1
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001b810 : RandomPointsDeletePointerCatchContext
// Reports AR6DZoneRandomPoints::DeleteANode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsDeletePointerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsDeleteANodeAR6DZoneRandomPointsStorage2
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100441c0 : RandomPointsDeleteIndexExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsDeleteIndexExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsDeleteIndexFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100441d0 : RandomPointsDeletePointerExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsDeletePointerExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsDeletePointerFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001b355 : RandomPointsCreateNodeCatchContext
// Reports AR6DZoneRandomPoints::SpawnANewNode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsCreateNodeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsSpawnANewNode
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001b6b1 : RandomPointsSpawnedCatchContext
// Reports AR6DZoneRandomPoints::Spawned and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsSpawnedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsSpawned
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044180 : RandomPointsCreateNodeExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsCreateNodeExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsCreateNodeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100441b0 : RandomPointsSpawnedExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsSpawnedExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsSpawnedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001ba73 : RandomPointsTeardownCatchContext
// Reports AR6DZoneRandomPoints::PostScriptDestroyed and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsTeardownCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsPostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044200 : RandomPointsTeardownExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsTeardownExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsTeardownFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001add9 : RandomPointsEditorCatchContext
// Reports AR6DZoneRandomPoints::RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointsEditorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointsRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044150 : RandomPointsEditorExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointsEditorExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsEditorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043902 : RandomPointsDestructionExceptionHandler
// Supplies exact native FuncInfo to the shared C++ frame handler without creating a new frame.
__declspec(naked) void __cdecl RandomPointsDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043934 : RandomPointsCopyConstructionExceptionHandler
// Supplies exact native FuncInfo to the shared C++ frame handler without creating a new frame.
__declspec(naked) void __cdecl RandomPointsCopyConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointsCopyConstructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10012ae0 : AR6DZoneRandomPoints::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZoneRandomPoints::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZoneRandomPoints* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZoneRandomPointsDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4c4, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZoneRandomPoints::~AR6DZoneRandomPoints(); // Direct native call10012970, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4c4);
    }
    return object;
}
