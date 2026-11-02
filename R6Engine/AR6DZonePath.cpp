#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_array_views.hpp"

// Native helper declarations match their canonical definitions.
void __thiscall RemoveRecords4(FArray* array, int index, int count);
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl DeploymentBaseOnlyCleanupExceptionHandler(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004d948 : AR6DZonePathVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6DZonePath::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6DZonePathVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004fce4 : nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage1
extern const ushort nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage1[26];

// R6Engine.dll data @ 1004fd48 : nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage2
extern const ushort nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage2[26];

// R6Engine.dll data @ 1004fc38 : nativeTextAR6DZonePathFindClosestPointTo
extern const ushort nativeTextAR6DZonePathFindClosestPointTo[33];

// R6Engine.dll data @ 1004fbf0 : nativeTextAR6DZonePathFindRandomPointInArea
extern const ushort nativeTextAR6DZonePathFindRandomPointInArea[36];

// R6Engine.dll data @ 1004fb68 : nativeTextAR6DZonePathFindSpawningPoint
extern const ushort nativeTextAR6DZonePathFindSpawningPoint[32];

// R6Engine.dll data @ 1004fd80 : nativeTextAR6DZonePathPostScriptDestroyed
extern const ushort nativeTextAR6DZonePathPostScriptDestroyed[34];

// R6Engine.dll data @ 1004fb20 : nativeTextAR6DZonePathRenderEditorInfo
extern const ushort nativeTextAR6DZonePathRenderEditorInfo[31];

// R6Engine.dll data @ 1004fc7c : nativeTextAR6DZonePathSpawnANewNode
extern const ushort nativeTextAR6DZonePathSpawnANewNode[28];

// R6Engine.dll data @ 1004fcb4 : nativeTextAR6DZonePathSpawned
extern const ushort nativeTextAR6DZonePathSpawned[22];

// R6Engine.dll data @ 100557c2 : nativeTextR6DZonePath
extern const ushort nativeTextR6DZonePath[12];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl PathClosestPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathClosestPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathRandomPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathRandomPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathSpawningPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathSpawningPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathTeardownCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathTeardownCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneCreateNodeCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneCreateNodeCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeleteIndexCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeleteIndexCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeletePointerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeletePointerCatchPointer(void);
__declspec(naked) void __cdecl PathZoneDestructionState0Cleanup(void);
__declspec(naked) void __cdecl PathZoneDestructionState1Cleanup(void);
__declspec(naked) void __cdecl PathZoneEmptyValidationState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneRenderingCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneRenderingCatchPointer(void);
__declspec(naked) void __cdecl PathZoneRenderingState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneSpawnedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneSpawnedCatchPointer(void);

// R6Engine.dll data @ 10059774 : pathTeardownUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathTeardownUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059784 : pathTeardownCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathTeardownCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathTeardownCatchPointer) },
    { 0, 0, 0, ((uint)&PathTeardownCatchContext) }
};

// R6Engine.dll data @ 100597a4 : pathTeardownTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathTeardownTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathTeardownCatchMap) }
};

// R6Engine.dll data @ 100597b8 : pathTeardownFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZonePath::PostScriptDestroyed.
const NativeFunctionInfoPrefix pathTeardownFuncInfo = { 0x19930520, 0x2, ((uint)&pathTeardownUnwindMap), 0x1,
    ((uint)&pathTeardownTryMap), 0 };

// R6Engine.dll data @ 100596b4 : pathZoneDeleteIndexUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathZoneDeleteIndexUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100596c4 : pathZoneDeleteIndexCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathZoneDeleteIndexCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathZoneDeleteIndexCatchPointer) },
    { 0, 0, 0, ((uint)&PathZoneDeleteIndexCatchContext) }
};

// R6Engine.dll data @ 100596e4 : pathZoneDeleteIndexTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathZoneDeleteIndexTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathZoneDeleteIndexCatchMap) }
};

// R6Engine.dll data @ 100596f8 : pathZoneDeleteIndexFuncInfo
// Binds the selected MSVC cleanup/catch maps for DeleteANode(int).
const NativeFunctionInfoPrefix pathZoneDeleteIndexFuncInfo = { 0x19930520, 0x2, ((uint)&pathZoneDeleteIndexUnwindMap),
    0x1, ((uint)&pathZoneDeleteIndexTryMap), 0 };

// R6Engine.dll data @ 10059714 : pathZoneDeletePointerUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathZoneDeletePointerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059724 : pathZoneDeletePointerCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathZoneDeletePointerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathZoneDeletePointerCatchPointer) },
    { 0, 0, 0, ((uint)&PathZoneDeletePointerCatchContext) }
};

// R6Engine.dll data @ 10059744 : pathZoneDeletePointerTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathZoneDeletePointerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathZoneDeletePointerCatchMap) }
};

// R6Engine.dll data @ 10059758 : pathZoneDeletePointerFuncInfo
// Binds the selected MSVC cleanup/catch maps for DeleteANode(AR6DZonePathNode*).
const NativeFunctionInfoPrefix pathZoneDeletePointerFuncInfo = { 0x19930520, 0x2,
    ((uint)&pathZoneDeletePointerUnwindMap), 0x1, ((uint)&pathZoneDeletePointerTryMap), 0 };

// R6Engine.dll data @ 100595f4 : pathZoneCreateNodeUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathZoneCreateNodeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059604 : pathZoneCreateNodeCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathZoneCreateNodeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathZoneCreateNodeCatchPointer) },
    { 0, 0, 0, ((uint)&PathZoneCreateNodeCatchContext) }
};

// R6Engine.dll data @ 10059624 : pathZoneCreateNodeTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathZoneCreateNodeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathZoneCreateNodeCatchMap) }
};

// R6Engine.dll data @ 10059638 : pathZoneCreateNodeFuncInfo
// Binds the selected MSVC cleanup/catch maps for SpawnANewNode.
const NativeFunctionInfoPrefix pathZoneCreateNodeFuncInfo = { 0x19930520, 0x2, ((uint)&pathZoneCreateNodeUnwindMap),
    0x1, ((uint)&pathZoneCreateNodeTryMap), 0 };

// R6Engine.dll data @ 10059654 : pathZoneSpawnedUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathZoneSpawnedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059664 : pathZoneSpawnedCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathZoneSpawnedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathZoneSpawnedCatchPointer) },
    { 0, 0, 0, ((uint)&PathZoneSpawnedCatchContext) }
};

// R6Engine.dll data @ 10059684 : pathZoneSpawnedTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathZoneSpawnedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathZoneSpawnedCatchMap) }
};

// R6Engine.dll data @ 10059698 : pathZoneSpawnedFuncInfo
// Binds the selected MSVC cleanup/catch maps for Spawned.
const NativeFunctionInfoPrefix pathZoneSpawnedFuncInfo = { 0x19930520, 0x2, ((uint)&pathZoneSpawnedUnwindMap), 0x1,
    ((uint)&pathZoneSpawnedTryMap), 0 };

// R6Engine.dll data @ 10059594 : pathClosestPointUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathClosestPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100595a4 : pathClosestPointCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathClosestPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&PathClosestPointCatchPointer) },
    { 0, 0, 0, ((uint)&PathClosestPointCatchContext) }
};

// R6Engine.dll data @ 100595c4 : pathClosestPointTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathClosestPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathClosestPointCatchMap) }
};

// R6Engine.dll data @ 100595d8 : pathClosestPointFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindClosestPointTo.
const NativeFunctionInfoPrefix pathClosestPointFuncInfo = { 0x19930520, 0x2, ((uint)&pathClosestPointUnwindMap), 0x1,
    ((uint)&pathClosestPointTryMap), 0 };

// R6Engine.dll data @ 100594d4 : pathSpawningPointUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathSpawningPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100594e4 : pathSpawningPointCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathSpawningPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&PathSpawningPointCatchPointer) },
    { 0, 0, 0, ((uint)&PathSpawningPointCatchContext) }
};

// R6Engine.dll data @ 10059504 : pathSpawningPointTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathSpawningPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathSpawningPointCatchMap) }
};

// R6Engine.dll data @ 10059518 : pathSpawningPointFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindSpawningPoint.
const NativeFunctionInfoPrefix pathSpawningPointFuncInfo = { 0x19930520, 0x2, ((uint)&pathSpawningPointUnwindMap), 0x1,
    ((uint)&pathSpawningPointTryMap), 0 };

// R6Engine.dll data @ 10059534 : pathRandomPointUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathRandomPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059544 : pathRandomPointCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathRandomPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&PathRandomPointCatchPointer) },
    { 0, 0, 0, ((uint)&PathRandomPointCatchContext) }
};

// R6Engine.dll data @ 10059564 : pathRandomPointTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathRandomPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathRandomPointCatchMap) }
};

// R6Engine.dll data @ 10059578 : pathRandomPointFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindRandomPointInArea.
const NativeFunctionInfoPrefix pathRandomPointFuncInfo = { 0x19930520, 0x2, ((uint)&pathRandomPointUnwindMap), 0x1,
    ((uint)&pathRandomPointTryMap), 0 };

// R6Engine.dll data @ 1005946c : pathZoneRenderingUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathZoneRenderingUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&PathZoneRenderingState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10059484 : pathZoneRenderingCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathZoneRenderingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathZoneRenderingCatchPointer) },
    { 0, 0, 0, ((uint)&PathZoneRenderingCatchContext) }
};

// R6Engine.dll data @ 100594a4 : pathZoneRenderingTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathZoneRenderingTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&pathZoneRenderingCatchMap) }
};

// R6Engine.dll data @ 100594b8 : pathZoneRenderingFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZonePath::RenderEditorInfo.
const NativeFunctionInfoPrefix pathZoneRenderingFuncInfo = { 0x19930520, 0x3, ((uint)&pathZoneRenderingUnwindMap), 0x1,
    ((uint)&pathZoneRenderingTryMap), 0 };

// R6Engine.dll data @ 10059448 : pathZoneEmptyValidationUnwindMap
// Retains the warning FString cleanup-only state with no catch or report scope.
const NativeUnwindEntry pathZoneEmptyValidationUnwindMap[1] = {
    { -1, ((uint)&PathZoneEmptyValidationState0Cleanup) }
};

// R6Engine.dll data @ 10059450 : pathZoneEmptyValidationFuncInfo
// Retains the warning FString cleanup-only state with no catch or report scope.
const NativeFunctionInfoPrefix pathZoneEmptyValidationFuncInfo = { 0x19930520, 0x1,
    ((uint)&pathZoneEmptyValidationUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 100582b8 : pathZoneDestructionUnwindMap
// Retains exact pending member/base cleanup states, without a catch/report scope.
const NativeUnwindEntry pathZoneDestructionUnwindMap[2] = {
    { -1, ((uint)&PathZoneDestructionState0Cleanup) },
    { 0, ((uint)&PathZoneDestructionState1Cleanup) }
};

// R6Engine.dll data @ 100582c8 : pathZoneDestructionFuncInfo
// Retains exact pending member/base cleanup states, without a catch/report scope.
const NativeFunctionInfoPrefix pathZoneDestructionFuncInfo = { 0x19930520, 0x2, ((uint)&pathZoneDestructionUnwindMap),
    0, 0, 0 };

// R6Engine.dll data @ 1007ee70 : autoclassAR6DZonePath
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZonePath = nullptr;

// R6Engine.dll @ 100097c0 : AR6DZonePath::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZonePath::StaticClass(void)
{
    return &AR6DZonePath::PrivateStaticClass; // Selected object at0x1007e960.
}

// R6Engine.dll @ 100097d0 : AR6DZonePath::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZonePath::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZonePath::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100102e0 : AR6DZonePath::operator=
// Assigns the base, four flag bits and node storage with the native source/current-word read order.
AR6DZonePath& AR6DZonePath::operator=(const AR6DZonePath& source)
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
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bSelectNodeInEditor.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bActAsGroup.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 8U; // bShowLog.
    const FArray* arraySourceArgument = reinterpret_cast<const FArray*>(&source.m_aNode);
    FArray* arrayDestinationArgument = reinterpret_cast<FArray*>(&m_aNode);
    *destinationFlags = flags;
    AssignRecords4(arrayDestinationArgument, arraySourceArgument);
    return *this;
}

// R6Engine.dll @ 10012dd0 : AR6DZonePath::~AR6DZonePath
// Runs ConditionalDestroy, then implicitly destroys node-array storage and the deployment-zone base on all exits.
AR6DZonePath::~AR6DZonePath()
{
    // Compiler installs vtable1004d948; states1/0 retain pending array/base destruction before each native call.
    UObject::ConditionalDestroy(); // Ignore its int result; native member cleanup0e970 precedes base12520.
}

// R6Engine.dll @ 10012e30 : AR6DZonePath::AR6DZonePath(void)
// Constructs the base and installs the derived vtable without initializing derived flags or the array header.
// Native ABI view preserves explicit no-init/owned-array lifetimes and native cleanup coverage.
AR6DZonePath* __thiscall AR6DZonePath::AR6DZonePath(AR6DZonePath* object)
{
    (*(AR6DeploymentZone*
        (__thiscall*)(AR6DeploymentZone*))((uint)&AR6DeploymentZoneConstructorNativeEntry))(object);
    *(void**)object = (void*)&AR6DZonePathVirtualTable;
    return object; // Explicit ABI view avoids guessing the original no-init array spelling.
}

// R6Engine.dll @ 10012e50 : AR6DZonePath::AR6DZonePath
// Copies the base, flags and node array with the destination snapshot before vtable publication.
// Native ABI view activates base cleanup before the final flag store and node-array construction.
AR6DZonePath* __thiscall AR6DZonePath::AR6DZonePath(AR6DZonePath* object, const AR6DZonePath* source)
{
    uint guard[4]; // Inferred saved-object/previous SEH/handler/state words; not class storage.
    guard[3] = 0xffffffff;
    guard[2] = reinterpret_cast<uint>(&DeploymentBaseOnlyCleanupExceptionHandler);
    guard[1] = reinterpret_cast<uint>(ExceptionList);
    ExceptionList = &guard[1];
    const AR6DeploymentZone* baseSourceArgument = static_cast<const AR6DeploymentZone*>(source);
    guard[0] = reinterpret_cast<uint>(object);
    AR6DeploymentZone::AR6DeploymentZone(static_cast<AR6DeploymentZone*>(object), baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(object) + 0x49c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x49c);
    uint earlyFlags = *destinationFlags;
    *reinterpret_cast<uint*>(object) = reinterpret_cast<uint>(&AR6DZonePathVirtualTable);
    uint sourceWord = *sourceFlags;
    uint difference = earlyFlags ^ sourceWord;
    uint currentFlags = *destinationFlags;
    uint flags = currentFlags ^ (difference & 1U);
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bSelectNodeInEditor.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bActAsGroup.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 8U; // bShowLog.
    const FArray* arraySourceArgument = reinterpret_cast<const FArray*>(&source->m_aNode);
    FArray* arrayDestinationArgument = reinterpret_cast<FArray*>(&object->m_aNode);
    guard[3] = 0;
    *destinationFlags = flags;
    CopyConstructRecords4(arrayDestinationArgument, arraySourceArgument);
    ExceptionList = reinterpret_cast<void*>(guard[1]);
    return object;
}

// R6Engine.dll @ 10013ac0 : AR6DZonePath::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZonePath::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZonePathConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100193d0 : AR6DZonePath::CheckForErrors
// Reports an exactly empty path, destroys its warning string, then runs base validation in editor mode.
void AR6DZonePath::CheckForErrors()
{
    using ReportCall = void (__thiscall*)(FFeedbackContext*, int, UObject*, const ushort*);
    if (*(const int*)((const byte*)&m_aNode + 4) == 0) {
        const ushort* objectName = GetName();
        FString text = FString::Printf((const ushort*)L"%s don't have any node!", objectName);
        FFeedbackContext* warning = **(FFeedbackContext***)&CoreGWarnImport;
        byte* table = *(byte**)warning;
        const ushort* detail = *text;
        // Retain the old table, but reload its receiver after dereference.
        warning = **(FFeedbackContext***)&CoreGWarnImport;
        ReportCall report = *(ReportCall*)(table + 0x28);
        report(warning, 0, this, detail);
    }
    this->AR6DeploymentZone::CheckForErrors(true);
}

// R6Engine.dll @ 10019470 : AR6DZonePath::RenderEditorInfo
// Claims the first unowned node or renders the selected path with connecting lines and per-node radius circles.
void AR6DZonePath::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* render, FDynamicActor* dynamicActor)
{
    try {
        this->AR6DeploymentZone::RenderEditorInfo(scene, render, dynamicActor);
        const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&m_aNode);
        uint* selection = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xac);
        bool selectedNode = false;
        uint index = 0;
        while ((int)index < nodesHeader->count) {
            uint selectedPath = *selection & 0x4000U;
            AR6DZonePathNode** nodes = reinterpret_cast<AR6DZonePathNode**>(nodesHeader->dataAddress);
            AR6DZonePathNode* node = nodes[index];
            if (selectedPath != 0 && (reinterpret_cast<const byte*>(this)[0x49c] & 2) != 0)
                *reinterpret_cast<uint*>(reinterpret_cast<byte*>(node) + 0xac) |= 0x4000U;
            else if (node != nullptr &&
                (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(node) + 0xac) & 0x4000U) != 0)
                selectedNode = true;
            if (node->m_pPath == nullptr) { // Native owner access is unconditional, including for a null list slot.
                node->m_pPath = this;
                uint count = static_cast<uint>(nodesHeader->count);
                uint data = nodesHeader->dataAddress;
                AR6DZonePathNode* anchor = *reinterpret_cast<AR6DZonePathNode**>(data + count * 4U - 8U);
                const volatile float* position = (const volatile float*)&anchor->Location;
                // float10 denotes x87 work. X spills before Y loads; Y spills after the destination X store.
                float10 x = (float10)position[0];
                uint z = reinterpret_cast<const uint&>(anchor->Location.Z);
                x += (float10)25.0f;
                float roundedX = (float)x;
                float10 y = (float10)position[1] + (float10)25.0f;
                reinterpret_cast<uint&>(node->Location.X) = reinterpret_cast<const uint&>(roundedX);
                node->Location.Y = (float)y;
                reinterpret_cast<uint&>(node->Location.Z) = z;
                *selection &= ~0x4000U;
                uint clearIndex = 0;
                while ((int)clearIndex < nodesHeader->count) {
                    AR6DZonePathNode** live = reinterpret_cast<AR6DZonePathNode**>(nodesHeader->dataAddress);
                    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(live[clearIndex]) + 0xac) &= ~0x4000U;
                    ++clearIndex;
                }
                *reinterpret_cast<uint*>(reinterpret_cast<byte*>(node) + 0xac) |= 0x4000U;
                return;
            }
            ++index;
        }
        if ((*selection & 0x4000U) == 0 && !selectedNode) return;
        byte* sceneOwner = *(byte**)((byte*)scene + 4);
        FRenderInterface* sceneInterface = *(FRenderInterface**)(sceneOwner + 0x164);
        FLineBatcher batcher(sceneInterface, 1, 0);
        bool selectedPath = (*selection & 0x4000U) != 0; // Reload after construction; do not recheck eligibility.
        FPlane linePlane(selectedPath ? 0.75f : 0.0f, selectedPath ? 1.0f : 0.5f, 0.0f, 0.0f);
        // Native scene-vector fields remain explicit offsets; X copies raw while Y/Z pass through x87.
        const volatile float* sceneVector50 = (const volatile float*)((const byte*)scene + 0x50);
        float10 axisXZ = (float10)sceneVector50[2];
        uint axisXX = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(scene) + 0x50);
        float10 axisXY = (float10)sceneVector50[1];
        uint axisYX = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(scene) + 0x60);
        FVector axisX;
        axisX.Y = (float)axisXY;
        reinterpret_cast<uint&>(axisX.X) = axisXX;
        axisX.Z = (float)axisXZ;
        const volatile float* sceneVector60 = (const volatile float*)((const byte*)scene + 0x60);
        float10 axisYZ = (float10)sceneVector60[2];
        float10 axisYY = (float10)sceneVector60[1];
        FVector axisY;
        axisY.Y = (float)axisYY;
        axisY.Z = (float)axisYZ;
        reinterpret_cast<uint&>(axisY.X) = axisYX;
        index = 0;
        while ((int)index < nodesHeader->count) {
            AR6DZonePathNode** data = reinterpret_cast<AR6DZonePathNode**>(nodesHeader->dataAddress);
            AR6DZonePathNode** slot = data + index;
            AR6DZonePathNode* node = *slot;
            if (node != nullptr) {
                if (index != 0) {
                    FColor lineColor(linePlane);
                    AR6DZonePathNode* previous = slot[-1]; // Captured slot, read after the color constructor.
                    FVector previousLocation;
                    reinterpret_cast<uint&>(previousLocation.X) = reinterpret_cast<const uint&>(previous->Location.X);
                    reinterpret_cast<uint&>(previousLocation.Y) = reinterpret_cast<const uint&>(previous->Location.Y);
                    reinterpret_cast<uint&>(previousLocation.Z) = reinterpret_cast<const uint&>(previous->Location.Z);
                    FVector currentLocation;
                    reinterpret_cast<uint&>(currentLocation.X) = reinterpret_cast<const uint&>(node->Location.X);
                    reinterpret_cast<uint&>(currentLocation.Y) = reinterpret_cast<const uint&>(node->Location.Y);
                    reinterpret_cast<uint&>(currentLocation.Z) = reinterpret_cast<const uint&>(node->Location.Z);
                    batcher.DrawLine(currentLocation, previousLocation, lineColor);
                }
                bool selected =
                    (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(node) + 0xac) & 0x4000U) != 0;
                // Cache before color construction, without a float load.
                uint radius = reinterpret_cast<const uint&>(node->m_fRadius);
                FPlane circlePlane(selected ? 0.75f : 0.0f, selected ? 1.0f : 0.5f, 0.0f, 0.0f);
                FColor circleColor(circlePlane);
                FVector center;
                reinterpret_cast<uint&>(center.X) = reinterpret_cast<const uint&>(node->Location.X);
                reinterpret_cast<uint&>(center.Y) = reinterpret_cast<const uint&>(node->Location.Y);
                reinterpret_cast<uint&>(center.Z) = reinterpret_cast<const uint&>(node->Location.Z);
                batcher.DrawCircle(center, axisX, axisY, circleColor, reinterpret_cast<const float&>(radius), 12);
            }
            ++index; // Reload count/data after callbacks, retaining the cached node within this iteration.
        }
        if ((reinterpret_cast<const byte*>(this)[0x49c] & 1) != 0) {
            uint count = static_cast<uint>(nodesHeader->count);
            uint data = nodesHeader->dataAddress;
            FColor closingColor(linePlane);
            AR6DZonePathNode* last = *reinterpret_cast<AR6DZonePathNode**>(data + count * 4U - 4U);
            FVector lastLocation;
            reinterpret_cast<uint&>(lastLocation.X) = reinterpret_cast<const uint&>(last->Location.X);
            reinterpret_cast<uint&>(lastLocation.Y) = reinterpret_cast<const uint&>(last->Location.Y);
            reinterpret_cast<uint&>(lastLocation.Z) = reinterpret_cast<const uint&>(last->Location.Z);
            AR6DZonePathNode* first = *reinterpret_cast<AR6DZonePathNode**>(data);
            FVector firstLocation;
            reinterpret_cast<uint&>(firstLocation.X) = reinterpret_cast<const uint&>(first->Location.X);
            reinterpret_cast<uint&>(firstLocation.Y) = reinterpret_cast<const uint&>(first->Location.Y);
            reinterpret_cast<uint&>(firstLocation.Z) = reinterpret_cast<const uint&>(first->Location.Z);
            batcher.DrawLine(firstLocation, lastLocation, closingColor); // No count or endpoint-null check is added.
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001988f : PathZoneRenderingCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneRenderingCatchPointer(void)
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

// R6Engine.dll @ 100198c0 : AR6DZonePath::FindSpawningPoint
// Selects a radial node offset, writes rotation and returns a hidden vector without accessing the other outputs.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePath::FindSpawningPoint(FVector* result, FRotator* rotationOut,
    int* unusedGroupOut, EStance* unusedStanceOut, int* unusedFlagOut)
{
    AR6DZonePath* path = this;
    using RandCall = int (__cdecl*)();
    const NativeArrayHeader32* nodes = reinterpret_cast<const NativeArrayHeader32*>(&path->m_aNode);
    int nodeCount = nodes->count; // Captured before guarded state0.
    try {
        if (nodeCount == 0) {
            const ushort* name = path->UObject::GetName();
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L"WARNING!! %s don't have any node", name);
            const FVector* zero = *(const FVector**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(zero->X);
            reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(zero->Z);
            return result;
        }
        RandCall random = reinterpret_cast<RandCall&>(CoreAppRandImport);
        int value = random();
        int nodeIndex;
        __asm {
            mov eax,value
            cdq
            idiv nodeCount
            mov nodeIndex,edx
        }
        value = random(); // Reuse the target captured before the first call.
        int yawDivisor = 0x7fff;
        int yawRemainder;
        __asm {
            mov eax,value
            cdq
            idiv yawDivisor
            mov yawRemainder,edx
        }
        uint byteOffset = (uint)nodeIndex * 4U;
        uint radiusData = nodes->dataAddress;
        AR6DZonePathNode** radiusSlot = reinterpret_cast<AR6DZonePathNode**>(radiusData + byteOffset);
        FRotator rotation;
        rotation.Pitch = 0;
        rotation.Yaw = (int)((uint)yawRemainder << 1);
        rotation.Roll = 0;
        volatile float fraction = appFrand();
        uint rotationData = nodes->dataAddress;
        AR6DZonePathNode* rotationNode = *reinterpret_cast<AR6DZonePathNode**>(rotationData + byteOffset);
        AR6DZonePathNode* radiusNode = *radiusSlot; // Keep the old slot; read its node only after appFrand.
        // float10 denotes native x87 work, not a recovered original type spelling.
        float10 distance = (float10)fraction * (float10)radiusNode->m_fRadius;
        reinterpret_cast<uint&>(rotationOut->Pitch) = reinterpret_cast<const uint&>(rotationNode->Rotation.Pitch);
        volatile float roundedDistance = (float)distance; // Native spill occurs between Pitch and Yaw writes.
        reinterpret_cast<uint&>(rotationOut->Yaw) = reinterpret_cast<const uint&>(rotationNode->Rotation.Yaw);
        reinterpret_cast<uint&>(rotationOut->Roll) = reinterpret_cast<const uint&>(rotationNode->Rotation.Roll);
        FVector directionStorage;
        FVector* direction = &(directionStorage = rotation.Vector()); // Preserve the actual EAX pointer.
        float10 xProduct = (float10)roundedDistance * (float10)direction->X;
        volatile float xOffset = (float)xProduct;
        float10 yProduct = (float10)roundedDistance * (float10)direction->Y;
        volatile float yOffset = (float)yProduct;
        float10 zProduct = (float10)roundedDistance * (float10)direction->Z;
        uint locationData = nodes->dataAddress;
        AR6DZonePathNode* locationNode = *reinterpret_cast<AR6DZonePathNode**>(locationData + byteOffset);
        float10 z = zProduct + (float10)locationNode->Location.Z;
        float10 y = (float10)yOffset + (float10)locationNode->Location.Y;
        float10 x = (float10)xOffset + (float10)locationNode->Location.X;
        result->X = (float)x;
        result->Y = (float)y;
        result->Z = (float)z;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::FindSpawningPoint");
        throw;
    }
}

// R6Engine.dll @ 10019a09 : PathSpawningPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl PathSpawningPointCatchPointer(void)
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

// R6Engine.dll @ 10019a40 : AR6DZonePath::FindRandomPointInArea
// Offsets a randomly selected path node using cached radius storage, returning the caller's hidden vector buffer.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePath::FindRandomPointInArea(FVector* result)
{
    AR6DZonePath* path = this;
    using RandCall = int (__cdecl*)();
    const NativeArrayHeader32* nodes = reinterpret_cast<const NativeArrayHeader32*>(&path->m_aNode);
    int nodeCount = nodes->count;
    try {
        if (nodeCount == 0) {
            const ushort* name = path->UObject::GetName();
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L"WARNING!! %s don't have any node", name);
            const FVector* zero = *(const FVector**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(zero->X);
            reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(zero->Z);
            return result;
        }
        RandCall random = reinterpret_cast<RandCall&>(CoreAppRandImport);
        int value = random();
        int nodeIndex;
        __asm {
            mov eax,value
            cdq
            idiv nodeCount
            mov nodeIndex,edx
        }
        value = random();
        int yawDivisor = 0x7fff;
        int yawRemainder;
        __asm {
            mov eax,value
            cdq
            idiv yawDivisor
            mov yawRemainder,edx
        }
        uint byteOffset = (uint)nodeIndex * 4U;
        uint radiusData = nodes->dataAddress;
        AR6DZonePathNode** radiusSlot = reinterpret_cast<AR6DZonePathNode**>(radiusData + byteOffset);
        FRotator rotation;
        rotation.Pitch = 0;
        rotation.Yaw = (int)((uint)yawRemainder << 1);
        rotation.Roll = 0;
        volatile float fraction = appFrand();
        AR6DZonePathNode* radiusNode = *radiusSlot;
        float10 distance = (float10)fraction * (float10)radiusNode->m_fRadius;
        volatile float roundedDistance = (float)distance;
        FVector directionStorage;
        FVector* direction = &(directionStorage = rotation.Vector());
        // Native captures this before multiplying direction X.
        uint locationData = nodes->dataAddress;
        float10 xProduct = (float10)roundedDistance * (float10)direction->X;
        volatile float xOffset = (float)xProduct;
        float10 yProduct = (float10)roundedDistance * (float10)direction->Y;
        volatile float yOffset = (float)yProduct;
        float10 zProduct = (float10)roundedDistance * (float10)direction->Z;
        AR6DZonePathNode* locationNode = *reinterpret_cast<AR6DZonePathNode**>(locationData + byteOffset);
        float10 z = zProduct + (float10)locationNode->Location.Z;
        float10 y = (float10)yOffset + (float10)locationNode->Location.Y;
        float10 x = (float10)xOffset + (float10)locationNode->Location.X;
        result->X = (float)x;
        result->Y = (float)y;
        result->Z = (float)z;
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::FindRandomPointInArea");
        throw;
    }
}

// R6Engine.dll @ 10019b67 : PathRandomPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl PathRandomPointCatchPointer(void)
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

// R6Engine.dll @ 10019ba0 : AR6DZonePath::FindClosestPointTo
// Compares normalized-radius candidates, retaining native first-candidate rounding and ordered x87 score selection.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePath::FindClosestPointTo(FVector* result, const FVector* point)
{
    AR6DZonePath* path = this;
    // float10 denotes native x87 work, not a recovered original type or a new precision/control-word setting.
    const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&path->m_aNode);
    uint data = nodesHeader->dataAddress;
    const volatile float* query = (const volatile float*)point;
    float10 initialQueryZ = (float10)query[2];
    AR6DZonePathNode* node = *reinterpret_cast<AR6DZonePathNode**>(data); // First-node access precedes any count test.
    float10 inputZ = initialQueryZ - (float10)node->Location.Z;
    float10 inputY = (float10)query[1] - (float10)node->Location.Y;
    float10 inputX = (float10)query[0] - (float10)node->Location.X;
    try { // State0 starts before the input float spills, after the initial extended subtractions.
        FVector input;
        input.X = (float)inputX;
        input.Y = (float)inputY;
        input.Z = (float)inputZ;
        FVector normalizedStorage;
        FVector* normalized = &(normalizedStorage = input.GetNormalized());
        float10 radius = (float10)node->m_fRadius; // Node remains cached across normalization.
        uint normalizedY = reinterpret_cast<const uint&>(normalized->Y);
        // Native constant is positive zero, not 2.4.
        float10 zero = (float10)*(const volatile float*)((uint)&nativeFloatZero);
        uint normalizedX = reinterpret_cast<const uint&>(normalized->X);
        float10 zProduct = zero * radius;
        // Native snapshots Z but never multiplies by it.
        volatile uint ignoredZ = reinterpret_cast<const uint&>(normalized->Z);
        volatile float zOffset = (float)zProduct;
        float10 yProduct = (float10)reinterpret_cast<const float&>(normalizedY) * radius;
        volatile float yOffset = (float)yProduct;
        float10 xProduct = (float10)reinterpret_cast<const float&>(normalizedX) * radius;
        volatile float xOffset = (float)xProduct;
        float10 z = (float10)zOffset + (float10)node->Location.Z;
        float10 y = (float10)yOffset + (float10)node->Location.Y;
        float10 x = (float10)xOffset + (float10)node->Location.X;
        FVector best;
        best.X = (float)x;
        best.Y = (float)y;
        best.Z = (float)z;
        float10 deltaZ = (float10)query[2] - (float10)best.Z;
        float10 deltaY = (float10)query[1] - (float10)best.Y;
        float10 deltaX = (float10)query[0] - (float10)best.X;
        float10 xSquare = deltaX * deltaX;
        float10 ySquare = deltaY * deltaY;
        float10 bestScoreWork = xSquare + ySquare;
        float10 zSquare = deltaZ * deltaZ;
        bestScoreWork += zSquare; // Initial accumulation is X square, then Y, then Z.
        volatile float bestScore = (float)bestScoreWork;
        uint index = 1;
        while ((int)index < nodesHeader->count) {
            data = nodesHeader->dataAddress;
            float10 queryZ = (float10)query[2];
            node = *reinterpret_cast<AR6DZonePathNode**>(data + index * 4U);
            inputZ = queryZ - (float10)node->Location.Z;
            inputY = (float10)query[1] - (float10)node->Location.Y;
            inputX = (float10)query[0] - (float10)node->Location.X;
            FVector nextInput;
            nextInput.X = (float)inputX;
            nextInput.Y = (float)inputY;
            nextInput.Z = (float)inputZ;
            FVector nextNormalizedStorage;
            normalized = &(nextNormalizedStorage = nextInput.GetNormalized());
            normalizedX = reinterpret_cast<const uint&>(normalized->X);
            radius = (float10)node->m_fRadius;
            normalizedY = reinterpret_cast<const uint&>(normalized->Y);
            xProduct = (float10)reinterpret_cast<const float&>(normalizedX) * radius;
            yProduct = (float10)reinterpret_cast<const float&>(normalizedY);
            ignoredZ = reinterpret_cast<const uint&>(normalized->Z);
            yProduct *= radius;
            yOffset = (float)yProduct;
            zProduct = radius * (float10)*(const volatile float*)((uint)&nativeFloatZero);
            zOffset = (float)zProduct;
            x = xProduct + (float10)node->Location.X; // Later X products are not narrowed before this addition.
            FVector candidate;
            candidate.X = (float)x;
            y = (float10)yOffset + (float10)node->Location.Y;
            candidate.Y = (float)y;
            z = (float10)zOffset + (float10)node->Location.Z;
            candidate.Z = (float)z;
            deltaX = (float10)candidate.X - (float10)query[0];
            deltaY = (float10)candidate.Y - (float10)query[1];
            deltaZ = (float10)candidate.Z - (float10)query[2];
            zSquare = deltaZ * deltaZ;
            ySquare = deltaY * deltaY;
            float10 candidateScore = zSquare + ySquare;
            xSquare = deltaX * deltaX;
            candidateScore += xSquare; // Later accumulation is Z square, then Y, then X.
            ushort status;
            __asm {
                fld tbyte ptr candidateScore
                fcom dword ptr bestScore
                fnstsw ax
                mov status,ax
                fstp st(0)
            }
            if ((((status >> 8) ^ (status >> 10)) & 1U) != 0) { // Native C0 xor C2: ordered strict improvement.
                bestScore = (float)candidateScore; // Only winners spill the working score to float.
                reinterpret_cast<uint&>(best.X) = reinterpret_cast<const uint&>(candidate.X);
                reinterpret_cast<uint&>(best.Y) = reinterpret_cast<const uint&>(candidate.Y);
                reinterpret_cast<uint&>(best.Z) = reinterpret_cast<const uint&>(candidate.Z);
            }
            ++index; // Count and data are live after every normalization callback.
        }
        reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(best.X);
        reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(best.Y);
        reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(best.Z);
        return result;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::FindClosestPointTo");
        throw;
    }
}

// R6Engine.dll @ 10019dbe : PathClosestPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x20 by value through EBP-0x1c.
__declspec(naked) __declspec(noreturn) void __cdecl PathClosestPointCatchPointer(void)
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

// R6Engine.dll @ 10019df0 : AR6DZonePath::SpawnANewNode
// Spawns a node with zero name/rotation/options, appends the returned pointer, then assigns its zone back-pointer.
void __thiscall AR6DZonePath::SpawnANewNode(FVector location)
{
    AR6DZonePath* zone = this;
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
        AR6DZonePathNode* node = static_cast<AR6DZonePathNode*>(
            spawn(level, &AR6DZonePathNode::PrivateStaticClass, name, location, rotation,
                nullptr, 0, 0, nullptr, nullptr));
        NativeArrayHeader32* nodes = reinterpret_cast<NativeArrayHeader32*>(&zone->m_aNode);
        AddCall add = reinterpret_cast<AddCall&>(FArrayAddImport);
        int index = add(reinterpret_cast<FArray*>(nodes), 1, 4);
        // Read storage after Add, while retaining the original spawn result.
        AR6DZonePathNode** data = reinterpret_cast<AR6DZonePathNode**>(nodes->dataAddress);
        data[index] = node;
        node->m_pPath = zone; // Native code writes even after a null spawn result.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::SpawnANewNode");
        throw;
    }
}

// R6Engine.dll @ 10019e91 : PathZoneCreateNodeCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneCreateNodeCatchPointer(void)
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

// R6Engine.dll @ 10019ed0 : AR6DZonePath::Spawned
// Runs base initialization, then creates nodes at the current location with positive Y offsets of 20 and 100.
void __thiscall AR6DZonePath::Spawned(void)
{
    AR6DZonePath* zone = this;
    try {
        zone->AR6DeploymentZone::Spawned();
        // float10 denotes native x87 working values; Z is loaded and stored through x87 too, rather than copied raw.
        const volatile float* actorLocation = (const volatile float*)&zone->Location;
        float10 z = (float10)actorLocation[2];
        float10 y = (float10)actorLocation[1];
        uint x = reinterpret_cast<const uint&>(zone->Location.X);
        y += (float10)20.0f;
        FVector nodeLocation;
        reinterpret_cast<uint&>(nodeLocation.X) = x;
        nodeLocation.Y = (float)y;
        nodeLocation.Z = (float)z;
        zone->AR6DZonePath::SpawnANewNode(nodeLocation);
        // Reload after the first spawn callback; retain raw X and x87-loaded Y/Z.
        actorLocation = (const volatile float*)&zone->Location;
        z = (float10)actorLocation[2];
        y = (float10)actorLocation[1];
        x = reinterpret_cast<const uint&>(zone->Location.X);
        y += (float10)100.0f;
        reinterpret_cast<uint&>(nodeLocation.X) = x;
        nodeLocation.Y = (float)y;
        nodeLocation.Z = (float)z;
        zone->AR6DZonePath::SpawnANewNode(nodeLocation);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::Spawned");
        throw;
    }
}

// R6Engine.dll @ 10019f8a : PathZoneSpawnedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneSpawnedCatchPointer(void)
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

// R6Engine.dll @ 10019fc0 : AR6DZonePath::DeleteANode(int)
// Removes the indexed entry before checking its live deletion flag and requesting destruction from the current level.
void __thiscall AR6DZonePath::DeleteANode(int nodeIndex)
{
    AR6DZonePath* zone = this;
    using DestroyCall = int (__thiscall *)(ULevel*, AActor*, int);
    const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
    int nodeCount = nodesHeader->count; // Captured before the guarded state.
    try {
        if (nodeIndex >= nodeCount) { // Native assertion has no lower-bound test and may return.
            appFailAssert("iIndex<m_aNode.Num()", ".\\Src\\AR6DZonePath.cpp", 0x100);
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
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::DeleteANode");
        throw;
    }
}

// R6Engine.dll @ 1001a054 : PathZoneDeleteIndexCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeleteIndexCatchPointer(void)
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

// R6Engine.dll @ 1001a090 : AR6DZonePath::DeleteANode(AR6DZonePathNode*)
// Scans the live master list and delegates deletion of its first matching node, then returns without rescanning.
void __thiscall AR6DZonePath::DeleteANode(AR6DZonePathNode* node)
{
    AR6DZonePath* zone = this;
    try {
        uint nodeIndex = 0;
        while ((int)nodeIndex < *(const int*)((const byte*)&zone->m_aNode + 4)) {
            uint dataAddress = reinterpret_cast<const uint&>(zone->m_aNode);
            if (*(const uint*)(dataAddress + nodeIndex * 4U) == (uint)node) {
                zone->AR6DZonePath::DeleteANode((int)nodeIndex);
                break;
            }
            ++nodeIndex;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::DeleteANode");
        throw;
    }
}

// R6Engine.dll @ 1001a0ec : PathZoneDeletePointerCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeletePointerCatchPointer(void)
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

// R6Engine.dll @ 1001a120 : AR6DZonePath::PostScriptDestroyed
// Removes each first node before destroying it, then clears the master header and releases its storage.
void __thiscall AR6DZonePath::PostScriptDestroyed(void)
{
    AR6DZonePath* zone = this;
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
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePath::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 1001a20f : PathTeardownCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathTeardownCatchPointer(void)
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

// R6Engine.dll @ 10043960 : PathZoneDestructionState0Cleanup
// Destroys the saved deployment-zone base during PathZone destruction unwinding.
__declspec(naked) void __cdecl PathZoneDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6DeploymentZoneDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043968 : PathZoneDestructionState1Cleanup
// Destroys saved PathZone node-array storage at object+0x4a0.
__declspec(naked) void __cdecl PathZoneDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4a0
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043fe0 : PathZoneEmptyValidationState0Cleanup
// Destroys the warning FString at inherited dispatcher-frame EBP-0x18.
__declspec(naked) void __cdecl PathZoneEmptyValidationState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044000 : PathZoneRenderingState1Cleanup
// Destroys the live FLineBatcher at inherited dispatcher-frame EBP-0x8c.
__declspec(naked) void __cdecl PathZoneRenderingState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x8c]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10048080 : DestroyAR6DZonePathClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZonePathClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZonePath::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046510 : InitializeAR6DZonePathClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZonePathClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZonePath::PrivateStaticClass, 0, 0x4ac, 0,
        &AR6DeploymentZone::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZonePath, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6DZonePath::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZonePathClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046590 : PublishAR6DZonePathAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZonePathAutoClass(void)
{
    autoclassAR6DZonePath = &AR6DZonePath::PrivateStaticClass;
}

// R6Engine.dll @ 10012f10 : AR6DZonePath::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZonePath::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZonePath* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZonePathDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4ac, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZonePath::~AR6DZonePath(); // Direct native call10012dd0, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4ac);
    }
    return object;
}

// R6Engine.dll @ 10043976 : PathZoneDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo to the shared dispatcher without adding a frame.
__declspec(naked) void __cdecl PathZoneDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043fe9 : PathZoneEmptyValidationExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating another dispatcher frame.
__declspec(naked) void __cdecl PathZoneEmptyValidationExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneEmptyValidationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100198a3 : PathZoneRenderingCatchContext
// Reports AR6DZonePath::RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneRenderingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004400c : PathZoneRenderingExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathZoneRenderingExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneRenderingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10019a1d : PathSpawningPointCatchContext
// Reports AR6DZonePath::FindSpawningPoint and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathSpawningPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathFindSpawningPoint
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10019b7b : PathRandomPointCatchContext
// Reports AR6DZonePath::FindRandomPointInArea and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathRandomPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathFindRandomPointInArea
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044020 : PathSpawningPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathSpawningPointExceptionHandler(void)
{
    __asm {
        mov eax,offset pathSpawningPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044030 : PathRandomPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathRandomPointExceptionHandler(void)
{
    __asm {
        mov eax,offset pathRandomPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10019dd2 : PathClosestPointCatchContext
// Reports AR6DZonePath::FindClosestPointTo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathClosestPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathFindClosestPointTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044040 : PathClosestPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathClosestPointExceptionHandler(void)
{
    __asm {
        mov eax,offset pathClosestPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10019ea5 : PathZoneCreateNodeCatchContext
// Reports AR6DZonePath::SpawnANewNode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneCreateNodeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathSpawnANewNode
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10019f9e : PathZoneSpawnedCatchContext
// Reports AR6DZonePath::Spawned and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneSpawnedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathSpawned
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044050 : PathZoneCreateNodeExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathZoneCreateNodeExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneCreateNodeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044060 : PathZoneSpawnedExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathZoneSpawnedExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneSpawnedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001a068 : PathZoneDeleteIndexCatchContext
// Reports AR6DZonePath::DeleteANode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeleteIndexCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage1
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001a100 : PathZoneDeletePointerCatchContext
// Reports AR6DZonePath::DeleteANode and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathZoneDeletePointerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathDeleteANodeAR6DZonePathStorage2
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044070 : PathZoneDeleteIndexExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathZoneDeleteIndexExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneDeleteIndexFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044080 : PathZoneDeletePointerExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathZoneDeletePointerExceptionHandler(void)
{
    __asm {
        mov eax,offset pathZoneDeletePointerFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001a223 : PathTeardownCatchContext
// Reports AR6DZonePath::PostScriptDestroyed and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathTeardownCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathPostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044090 : PathTeardownExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathTeardownExceptionHandler(void)
{
    __asm {
        mov eax,offset pathTeardownFuncInfo
        jmp __CxxFrameHandler
    }
}
