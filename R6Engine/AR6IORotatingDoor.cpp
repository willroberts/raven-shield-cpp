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
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);
FVector* __cdecl ScaleVectorToResult(FVector* result, float scale, const FVector* source);
int __thiscall RemoveMatchingWords4(FArray* words, const uint* keyReference);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004e328 : AR6IORotatingDoorVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6IORotatingDoor::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6IORotatingDoorVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050d3c : nativeTextAR6AIControllerAddBreach
extern const ushort nativeTextAR6AIControllerAddBreach[27];

// R6Engine.dll data @ 10050cc0 : nativeTextAR6AIControllerExecWillOpenOnTouch
extern const ushort nativeTextAR6AIControllerExecWillOpenOnTouch[37];

// R6Engine.dll data @ 10050d74 : nativeTextAR6AIControllerRemoveBreach
extern const ushort nativeTextAR6AIControllerRemoveBreach[30];

// R6Engine.dll data @ 10050bd8 : nativeTextAR6IORotatingDoorAddMyMarker
extern const ushort nativeTextAR6IORotatingDoorAddMyMarker[31];

// R6Engine.dll data @ 10050a88 : nativeTextAR6IORotatingDoorPostNetReceive
extern const ushort nativeTextAR6IORotatingDoorPostNetReceive[34];

// R6Engine.dll data @ 100509f0 : nativeTextAR6IORotatingDoorPostScriptDestroyed
extern const ushort nativeTextAR6IORotatingDoorPostScriptDestroyed[39];

// R6Engine.dll data @ 10050a40 : nativeTextAR6IORotatingDoorPreNetReceive
extern const ushort nativeTextAR6IORotatingDoorPreNetReceive[33];

// R6Engine.dll data @ 10050b40 : nativeTextAR6IORotatingDoorRenderEditorInfo
extern const ushort nativeTextAR6IORotatingDoorRenderEditorInfo[36];

// R6Engine.dll data @ 100509ac : nativeTextAR6IORotatingDoorShouldTrace
extern const ushort nativeTextAR6IORotatingDoorShouldTrace[31];

// R6Engine.dll data @ 100559be : nativeTextR6IORotatingDoor
extern const ushort nativeTextR6IORotatingDoor[17];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl RotatingDoorDestructionState0Cleanup(void);
__declspec(naked) void __cdecl RotatingDoorDestructionState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecAddBreachCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecAddBreachCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecRemoveBreachCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecRemoveBreachCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecWillOpenOnTouchCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecWillOpenOnTouchCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorMarkerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorMarkerCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostNetReceiveCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostNetReceiveCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostScriptDestroyedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostScriptDestroyedCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPreNetReceiveCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPreNetReceiveCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorRenderEditorInfoCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorRenderEditorInfoCatchPointer(void);
__declspec(naked) void __cdecl RotatingDoorRenderEditorInfoState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorShouldTraceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorShouldTraceCatchPointer(void);

// R6Engine.dll data @ 1005a608 : rotatingDoorMarkerUnwindMap
// Retains two terminal null-action states and the marker parent's exact typed/context catches.
const NativeUnwindEntry rotatingDoorMarkerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a618 : rotatingDoorMarkerCatchMap
// Retains two terminal null-action states and the marker parent's exact typed/context catches.
const NativeCatchEntry rotatingDoorMarkerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -220, ((uint)&RotatingDoorMarkerCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorMarkerCatchContext) }
};

// R6Engine.dll data @ 1005a638 : rotatingDoorMarkerTryMap
// Retains two terminal null-action states and the marker parent's exact typed/context catches.
const NativeTryBlock rotatingDoorMarkerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorMarkerCatchMap) }
};

// R6Engine.dll data @ 1005a64c : rotatingDoorMarkerFuncInfo
// Retains two terminal null-action states and the marker parent's exact typed/context catches.
const NativeFunctionInfoPrefix rotatingDoorMarkerFuncInfo = { 0x19930520, 0x2, ((uint)&rotatingDoorMarkerUnwindMap),
    0x1, ((uint)&rotatingDoorMarkerTryMap), 0 };

// R6Engine.dll data @ 1005a668 : rotatingDoorExecWillOpenOnTouchUnwindMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeUnwindEntry rotatingDoorExecWillOpenOnTouchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a678 : rotatingDoorExecWillOpenOnTouchCatchMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeCatchEntry rotatingDoorExecWillOpenOnTouchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RotatingDoorExecWillOpenOnTouchCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorExecWillOpenOnTouchCatchContext) }
};

// R6Engine.dll data @ 1005a698 : rotatingDoorExecWillOpenOnTouchTryMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeTryBlock rotatingDoorExecWillOpenOnTouchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorExecWillOpenOnTouchCatchMap) }
};

// R6Engine.dll data @ 1005a6ac : rotatingDoorExecWillOpenOnTouchFuncInfo
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeFunctionInfoPrefix rotatingDoorExecWillOpenOnTouchFuncInfo = {
    0x19930520, 0x2, ((uint)&rotatingDoorExecWillOpenOnTouchUnwindMap), 0x1,
        ((uint)&rotatingDoorExecWillOpenOnTouchTryMap), 0
};

// R6Engine.dll data @ 1005a728 : rotatingDoorExecAddBreachUnwindMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeUnwindEntry rotatingDoorExecAddBreachUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a738 : rotatingDoorExecAddBreachCatchMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeCatchEntry rotatingDoorExecAddBreachCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RotatingDoorExecAddBreachCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorExecAddBreachCatchContext) }
};

// R6Engine.dll data @ 1005a758 : rotatingDoorExecAddBreachTryMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeTryBlock rotatingDoorExecAddBreachTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorExecAddBreachCatchMap) }
};

// R6Engine.dll data @ 1005a76c : rotatingDoorExecAddBreachFuncInfo
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeFunctionInfoPrefix rotatingDoorExecAddBreachFuncInfo = { 0x19930520, 0x2,
    ((uint)&rotatingDoorExecAddBreachUnwindMap), 0x1, ((uint)&rotatingDoorExecAddBreachTryMap), 0 };

// R6Engine.dll data @ 1005a788 : rotatingDoorExecRemoveBreachUnwindMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeUnwindEntry rotatingDoorExecRemoveBreachUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a798 : rotatingDoorExecRemoveBreachCatchMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeCatchEntry rotatingDoorExecRemoveBreachCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RotatingDoorExecRemoveBreachCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorExecRemoveBreachCatchContext) }
};

// R6Engine.dll data @ 1005a7b8 : rotatingDoorExecRemoveBreachTryMap
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeTryBlock rotatingDoorExecRemoveBreachTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorExecRemoveBreachCatchMap) }
};

// R6Engine.dll data @ 1005a7cc : rotatingDoorExecRemoveBreachFuncInfo
// Preserves catch-only states and the exact inherited typed/context catch bindings.
const NativeFunctionInfoPrefix rotatingDoorExecRemoveBreachFuncInfo = {
    0x19930520, 0x2, ((uint)&rotatingDoorExecRemoveBreachUnwindMap), 0x1, ((uint)&rotatingDoorExecRemoveBreachTryMap), 0
};

// R6Engine.dll data @ 1005a358 : rotatingDoorShouldTraceUnwindMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeUnwindEntry rotatingDoorShouldTraceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a368 : rotatingDoorShouldTraceCatchMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeCatchEntry rotatingDoorShouldTraceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RotatingDoorShouldTraceCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorShouldTraceCatchContext) }
};

// R6Engine.dll data @ 1005a388 : rotatingDoorShouldTraceTryMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeTryBlock rotatingDoorShouldTraceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorShouldTraceCatchMap) }
};

// R6Engine.dll data @ 1005a39c : rotatingDoorShouldTraceFuncInfo
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeFunctionInfoPrefix rotatingDoorShouldTraceFuncInfo = { 0x19930520, 0x2,
    ((uint)&rotatingDoorShouldTraceUnwindMap), 0x1, ((uint)&rotatingDoorShouldTraceTryMap), 0 };

// R6Engine.dll data @ 1005a3b8 : rotatingDoorPostScriptDestroyedUnwindMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeUnwindEntry rotatingDoorPostScriptDestroyedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a3c8 : rotatingDoorPostScriptDestroyedCatchMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeCatchEntry rotatingDoorPostScriptDestroyedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RotatingDoorPostScriptDestroyedCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorPostScriptDestroyedCatchContext) }
};

// R6Engine.dll data @ 1005a3e8 : rotatingDoorPostScriptDestroyedTryMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeTryBlock rotatingDoorPostScriptDestroyedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorPostScriptDestroyedCatchMap) }
};

// R6Engine.dll data @ 1005a3fc : rotatingDoorPostScriptDestroyedFuncInfo
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeFunctionInfoPrefix rotatingDoorPostScriptDestroyedFuncInfo = {
    0x19930520, 0x2, ((uint)&rotatingDoorPostScriptDestroyedUnwindMap), 0x1,
        ((uint)&rotatingDoorPostScriptDestroyedTryMap), 0
};

// R6Engine.dll data @ 1005a418 : rotatingDoorPreNetReceiveUnwindMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeUnwindEntry rotatingDoorPreNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a428 : rotatingDoorPreNetReceiveCatchMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeCatchEntry rotatingDoorPreNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RotatingDoorPreNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorPreNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005a448 : rotatingDoorPreNetReceiveTryMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeTryBlock rotatingDoorPreNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorPreNetReceiveCatchMap) }
};

// R6Engine.dll data @ 1005a45c : rotatingDoorPreNetReceiveFuncInfo
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeFunctionInfoPrefix rotatingDoorPreNetReceiveFuncInfo = { 0x19930520, 0x2,
    ((uint)&rotatingDoorPreNetReceiveUnwindMap), 0x1, ((uint)&rotatingDoorPreNetReceiveTryMap), 0 };

// R6Engine.dll data @ 1005a478 : rotatingDoorPostNetReceiveUnwindMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeUnwindEntry rotatingDoorPostNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a488 : rotatingDoorPostNetReceiveCatchMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeCatchEntry rotatingDoorPostNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RotatingDoorPostNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorPostNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005a4a8 : rotatingDoorPostNetReceiveTryMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeTryBlock rotatingDoorPostNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotatingDoorPostNetReceiveCatchMap) }
};

// R6Engine.dll data @ 1005a4bc : rotatingDoorPostNetReceiveFuncInfo
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeFunctionInfoPrefix rotatingDoorPostNetReceiveFuncInfo = { 0x19930520, 0x2,
    ((uint)&rotatingDoorPostNetReceiveUnwindMap), 0x1, ((uint)&rotatingDoorPostNetReceiveTryMap), 0 };

// R6Engine.dll data @ 1005a538 : rotatingDoorRenderEditorInfoUnwindMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeUnwindEntry rotatingDoorRenderEditorInfoUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&RotatingDoorRenderEditorInfoState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a550 : rotatingDoorRenderEditorInfoCatchMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeCatchEntry rotatingDoorRenderEditorInfoCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RotatingDoorRenderEditorInfoCatchPointer) },
    { 0, 0, 0, ((uint)&RotatingDoorRenderEditorInfoCatchContext) }
};

// R6Engine.dll data @ 1005a570 : rotatingDoorRenderEditorInfoTryMap
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeTryBlock rotatingDoorRenderEditorInfoTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&rotatingDoorRenderEditorInfoCatchMap) }
};

// R6Engine.dll data @ 1005a584 : rotatingDoorRenderEditorInfoFuncInfo
// Retains the exact native guard states, catch slots and completed temporary cleanup.
const NativeFunctionInfoPrefix rotatingDoorRenderEditorInfoFuncInfo = {
    0x19930520, 0x3, ((uint)&rotatingDoorRenderEditorInfoUnwindMap), 0x1, ((uint)&rotatingDoorRenderEditorInfoTryMap), 0
};

// R6Engine.dll data @ 100754e8 : PreNetDoorLocationX
// Shared receive snapshot, loader-zeroed storage; the descriptive name does not imply per-object ownership.
float PreNetDoorLocationX = 0.0f;

// R6Engine.dll data @ 100754ec : PreNetDoorLocationY
// Shared receive snapshot, loader-zeroed storage; the descriptive name does not imply per-object ownership.
float PreNetDoorLocationY = 0.0f;

// R6Engine.dll data @ 100754f0 : PreNetDoorLocationZ
// Shared receive snapshot, loader-zeroed storage; the descriptive name does not imply per-object ownership.
float PreNetDoorLocationZ = 0.0f;

// R6Engine.dll data @ 100585d8 : rotatingDoorDestructionUnwindMap
// Preserves native predecessor states and exact action-object/member cleanup associations.
const NativeUnwindEntry rotatingDoorDestructionUnwindMap[2] = {
    { -1, ((uint)&RotatingDoorDestructionState0Cleanup) },
    { 0, ((uint)&RotatingDoorDestructionState1Cleanup) }
};

// R6Engine.dll data @ 100585e8 : rotatingDoorDestructionFuncInfo
// Preserves native predecessor states and exact action-object/member cleanup associations.
const NativeFunctionInfoPrefix rotatingDoorDestructionFuncInfo = { 0x19930520, 0x2,
    ((uint)&rotatingDoorDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 100743e4 : intAR6IORotatingDoorexecRemoveBreach
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6IORotatingDoorexecRemoveBreach = (Native)&AR6IORotatingDoor::execRemoveBreach;

// R6Engine.dll data @ 1007ac10 : AR6IORotatingDoorRemoveBreachRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6IORotatingDoorRemoveBreachRegistrationResult = 0;

// R6Engine.dll data @ 100743e8 : intAR6IORotatingDoorexecAddBreach
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6IORotatingDoorexecAddBreach = (Native)&AR6IORotatingDoor::execAddBreach;

// R6Engine.dll data @ 1007a6d0 : AR6IORotatingDoorAddBreachRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6IORotatingDoorAddBreachRegistrationResult = 0;

// R6Engine.dll data @ 100743ec : intAR6IORotatingDoorexecWillOpenOnTouch
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6IORotatingDoorexecWillOpenOnTouch = (Native)&AR6IORotatingDoor::execWillOpenOnTouch;

// R6Engine.dll data @ 1007f390 : AR6IORotatingDoorWillOpenOnTouchRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6IORotatingDoorWillOpenOnTouchRegistrationResult = 0;

// R6Engine.dll data @ 1007abf8 : autoclassAR6IORotatingDoor
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6IORotatingDoor = nullptr;

// R6Engine.dll @ 10008fd0 : AR6IORotatingDoor::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6IORotatingDoor::StaticClass(void)
{
    return &AR6IORotatingDoor::PrivateStaticClass; // Selected object at0x10079778.
}

// R6Engine.dll @ 10008fe0 : AR6IORotatingDoor::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6IORotatingDoor::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6IORotatingDoor::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10014530 : AR6IORotatingDoor::operator=
// Copies action settings, door state, sound references, breach storage and geometry.
AR6IORotatingDoor& __thiscall AR6IORotatingDoor::operator=(const AR6IORotatingDoor& sourceObject)
{
    const AR6IORotatingDoor* source = &sourceObject;
    this->AR6InteractiveObject::operator=(*source);
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
    this->m_iLockHP = source->m_iLockHP;
    this->m_iCurrentLockHP = source->m_iCurrentLockHP;
    this->m_iMaxOpeningDeg = source->m_iMaxOpeningDeg;
    this->m_iInitialOpeningDeg = source->m_iInitialOpeningDeg;
    this->m_iYawInit = source->m_iYawInit;
    this->m_iYawMax = source->m_iYawMax;
    this->m_iMaxOpening = source->m_iMaxOpening;
    int initialOpening = source->m_iInitialOpening;
    // Native snapshot precedes the last opening stores.
    uint earlyFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x488);
    this->m_iInitialOpening = initialOpening;
    this->m_iCurrentOpening = source->m_iCurrentOpening;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x488);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x488);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 0x1U;
    uint copiedFlags = *destinationFlags; // Reload after sampling the first source difference.
    copiedFlags ^= firstDifference; // m_bTreatDoorAsWindow.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bInProcessOfClosing.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bInProcessOfOpening.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bUseWheel.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // m_bForceNoFormation.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bIsOpeningClockWise.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bIsDoorLocked.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // sm_bIsDoorLocked.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bIsDoorClosed.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fWindowWidth) = reinterpret_cast<const uint&>(source->m_fWindowWidth);
    reinterpret_cast<uint&>(this->m_fUnlockBaseTime) = reinterpret_cast<const uint&>(source->m_fUnlockBaseTime);
    this->m_DoorActorA = source->m_DoorActorA;
    this->m_DoorActorB = source->m_DoorActorB;
    this->m_OpeningSound = source->m_OpeningSound;
    this->m_OpeningWheelSound = source->m_OpeningWheelSound;
    this->m_ClosingSound = source->m_ClosingSound;
    this->m_ClosingWheelSound = source->m_ClosingWheelSound;
    this->m_LockSound = source->m_LockSound;
    this->m_UnlockSound = source->m_UnlockSound;
    this->m_MoveAmbientSound = source->m_MoveAmbientSound;
    this->m_MoveAmbientSoundStop = source->m_MoveAmbientSoundStop;
    this->m_LockPickSound = source->m_LockPickSound;
    this->m_LockPickSoundStop = source->m_LockPickSoundStop;
    this->m_ExplosionSound = source->m_ExplosionSound;
    AssignRecords4((FArray*)&this->m_BreachAttached,
        (const FArray*)&source->m_BreachAttached);
    reinterpret_cast<uint&>(this->m_vNormal.X) = reinterpret_cast<const uint&>(source->m_vNormal.X);
    reinterpret_cast<uint&>(this->m_vNormal.Y) = reinterpret_cast<const uint&>(source->m_vNormal.Y);
    reinterpret_cast<uint&>(this->m_vNormal.Z) = reinterpret_cast<const uint&>(source->m_vNormal.Z);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.X) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.X);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.Y) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.Y);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.Z) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.Z);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.X) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.X);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.Y) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.Y);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.Z) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.Z);
    return *this;
}

// R6Engine.dll @ 10015420 : AR6IORotatingDoor::~AR6IORotatingDoor
// Runs conditional cleanup before automatic breach-array and action-object base destruction.
AR6IORotatingDoor::~AR6IORotatingDoor()
{
    // Compiler installs vtable1004e328; state1 protects both the member and base during this call.
    UObject::ConditionalDestroy();
    // Implicit m_BreachAttached destruction calls1000e970 at state0; the base calls10015300 at state-1.
    // On exceptional exit, actions43b68/43b60 preserve that member-before-base order through FuncInfo100585e8.
}

// R6Engine.dll @ 10015480 : AR6IORotatingDoor::AR6IORotatingDoor()
// Constructs through AActor, installs the rotating-door vtable and leaves derived fields untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6IORotatingDoor* __thiscall AR6IORotatingDoor::AR6IORotatingDoor(AR6IORotatingDoor* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6IORotatingDoorVirtualTable);
    return this; // Original storage, ignoring the base constructor's EAX.
}

// R6Engine.dll @ 100154a0 : AR6IORotatingDoor::AR6IORotatingDoor
// Copies action settings, door state, sound references, breach storage and geometry.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6IORotatingDoor* __thiscall
AR6IORotatingDoor::AR6IORotatingDoor(AR6IORotatingDoor* this, const AR6IORotatingDoor* source)
{
    struct PendingBase {
        AR6IORotatingDoor* object;
        bool active;
        // Unwinds only the completed action-object base; no derived-array action exists in this FuncInfo.
        ~PendingBase() noexcept(false) {
            if (active) ((AR6IActionObject*)object)->AR6IActionObject::~AR6IActionObject();
        }
    } cleanup{this, false}; // Inferred lifetime view of shared native FuncInfo1005860c.
    AR6InteractiveObject::AR6InteractiveObject(this, source);
    *(uint*)this = ((uint)&AR6IActionObjectVirtualTable); // Inlined AR6IActionObject construction.
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
    *(uint*)this = ((uint)&AR6IORotatingDoorVirtualTable);
    this->m_iLockHP = source->m_iLockHP;
    this->m_iCurrentLockHP = source->m_iCurrentLockHP;
    this->m_iMaxOpeningDeg = source->m_iMaxOpeningDeg;
    this->m_iInitialOpeningDeg = source->m_iInitialOpeningDeg;
    this->m_iYawInit = source->m_iYawInit;
    this->m_iYawMax = source->m_iYawMax;
    this->m_iMaxOpening = source->m_iMaxOpening;
    int initialOpening = source->m_iInitialOpening;
    // Native snapshot precedes the last opening stores.
    uint earlyFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x488);
    this->m_iInitialOpening = initialOpening;
    this->m_iCurrentOpening = source->m_iCurrentOpening;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x488);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x488);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 0x1U;
    uint copiedFlags = *destinationFlags; // Reload after sampling the first source difference.
    copiedFlags ^= firstDifference; // m_bTreatDoorAsWindow.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bInProcessOfClosing.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bInProcessOfOpening.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bUseWheel.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // m_bForceNoFormation.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bIsOpeningClockWise.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bIsDoorLocked.
    *destinationFlags = copiedFlags;
    uint copiedLockBit = (*sourceFlags ^ copiedFlags) & 0x100U; // sm_bIsDoorLocked.
    cleanup.active = true; // Native state0 starts after sampling bit0x100, before merging it.
    copiedFlags ^= copiedLockBit;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bIsDoorClosed.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fWindowWidth) = reinterpret_cast<const uint&>(source->m_fWindowWidth);
    reinterpret_cast<uint&>(this->m_fUnlockBaseTime) = reinterpret_cast<const uint&>(source->m_fUnlockBaseTime);
    this->m_DoorActorA = source->m_DoorActorA;
    this->m_DoorActorB = source->m_DoorActorB;
    this->m_OpeningSound = source->m_OpeningSound;
    this->m_OpeningWheelSound = source->m_OpeningWheelSound;
    this->m_ClosingSound = source->m_ClosingSound;
    this->m_ClosingWheelSound = source->m_ClosingWheelSound;
    this->m_LockSound = source->m_LockSound;
    this->m_UnlockSound = source->m_UnlockSound;
    this->m_MoveAmbientSound = source->m_MoveAmbientSound;
    this->m_MoveAmbientSoundStop = source->m_MoveAmbientSoundStop;
    this->m_LockPickSound = source->m_LockPickSound;
    this->m_LockPickSoundStop = source->m_LockPickSoundStop;
    this->m_ExplosionSound = source->m_ExplosionSound;
    CopyConstructRecords4((FArray*)&this->m_BreachAttached,
        (const FArray*)&source->m_BreachAttached);
    reinterpret_cast<uint&>(this->m_vNormal.X) = reinterpret_cast<const uint&>(source->m_vNormal.X);
    reinterpret_cast<uint&>(this->m_vNormal.Y) = reinterpret_cast<const uint&>(source->m_vNormal.Y);
    reinterpret_cast<uint&>(this->m_vNormal.Z) = reinterpret_cast<const uint&>(source->m_vNormal.Z);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.X) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.X);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.Y) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.Y);
    reinterpret_cast<uint&>(this->m_vCenterOfDoor.Z) = reinterpret_cast<const uint&>(source->m_vCenterOfDoor.Z);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.X) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.X);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.Y) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.Y);
    reinterpret_cast<uint&>(this->m_vDoorADir2D.Z) = reinterpret_cast<const uint&>(source->m_vDoorADir2D.Z);
    cleanup.active = false; // Successful construction leaves the derived array owned by the result.
    return this;
}

// R6Engine.dll @ 10016150 : AR6IORotatingDoor::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6IORotatingDoor::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6IORotatingDoorConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001d0c0 : AR6IORotatingDoor::ShouldTrace
// Applies the door's see-through and bullet-through exceptions, then normalizes the ancestor trace result.
int __thiscall AR6IORotatingDoor::ShouldTrace(AActor* sourceActor, ulong traceFlags)
{
    AR6IORotatingDoor* door = this;
    bool unconditional = (traceFlags & 0x80000U) != 0; // Native argument read/test precedes guard state0.
    try {
        if (unconditional) return 1;
        if ((traceFlags & 0x20000U) != 0 && (reinterpret_cast<byte*>(door)[0xaa] & 1) != 0) return 0; // m_bSeeThrough.
        if ((traceFlags & 0x40000U) != 0 &&
            (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(door) + 0xa8) & 0x40000U) != 0)
            return 0;
        // The second rejection tests m_bBulletGoThrough; numeric trace-mask names remain unresolved.
        if ((traceFlags & 2U) != 0) return 1;
        return door->AR6InteractiveObject::ShouldTrace(sourceActor, traceFlags) != 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::ShouldTrace");
        throw;
    }
}

// R6Engine.dll @ 1001d13c : RotatingDoorShouldTraceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorShouldTraceCatchPointer(void)
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

// R6Engine.dll @ 1001d150 : RotatingDoorShouldTraceCatchContext
// Reports the ShouldTrace context and rethrows the active exception through the native C++ helper.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorShouldTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorShouldTrace
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d190 : AR6IORotatingDoor::IsMovingBrush
// Reports whether the inherited StaticMesh pointer is nonnull, irrespective of movement flags.
int __thiscall AR6IORotatingDoor::IsMovingBrush(void) const
{
    const AR6IORotatingDoor* door = this;
    return *(UStaticMesh* const*)((const byte*)door + 0x170) != nullptr;
}

// R6Engine.dll @ 1001d1a0 : AR6IORotatingDoor::PostScriptDestroyed
// Destroys both associated door markers through one captured helper before invoking the ancestor hook.
void __thiscall AR6IORotatingDoor::PostScriptDestroyed(void)
{
    AR6IORotatingDoor* door = this;
    using SafeDestroy = void (__thiscall*)(AActor*, AActor*);
    SafeDestroy destroy = reinterpret_cast<SafeDestroy&>(AActorSafeDestroyActorImport);
    AActor* markerA = door->m_DoorActorA; // Capture before state0, including null.
    try {
        destroy(door, markerA);
        AActor* markerB = door->m_DoorActorB; // Read after the first callback; reuse captured target.
        destroy(door, markerB);
        SharedNoOp(door);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 1001d1fc : RotatingDoorPostScriptDestroyedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostScriptDestroyedCatchPointer(void)
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

// R6Engine.dll @ 1001d210 : RotatingDoorPostScriptDestroyedCatchContext
// Reports the PostScriptDestroyed context and rethrows the active exception through the native C++ helper.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostScriptDestroyedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorPostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d230 : AR6IORotatingDoor::WillOpenOnTouch
// Allows a nonplayer pawn to open a closed door whose yaw differs from its initial yaw.
int __thiscall AR6IORotatingDoor::WillOpenOnTouch(AR6Pawn* pawn)
{
    if ((reinterpret_cast<const byte*>(pawn)[0x3e8] & 0x10U) != 0) // m_bIsPlayer.
        return 0;
    if ((*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x488) & 0x200U) == 0) // m_bIsDoorClosed.
        return 0;
    return this->Rotation.Yaw != this->m_iYawInit; // +0x244 versus +0x474.
}

// R6Engine.dll @ 1001d270 : AR6IORotatingDoor::PreNetReceive
// Saves location words after the interactive-object receive hook.
void __thiscall AR6IORotatingDoor::PreNetReceive(void)
{
    try {
        this->AR6InteractiveObject::PreNetReceive();
        reinterpret_cast<uint&>(PreNetDoorLocationX) = reinterpret_cast<const uint&>(this->Location.X);
        reinterpret_cast<uint&>(PreNetDoorLocationY) = reinterpret_cast<const uint&>(this->Location.Y);
        reinterpret_cast<uint&>(PreNetDoorLocationZ) = reinterpret_cast<const uint&>(this->Location.Z);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::PreNetReceive");
        throw;
    }
}

// R6Engine.dll @ 1001d2cf : RotatingDoorPreNetReceiveCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPreNetReceiveCatchPointer(void)
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

// R6Engine.dll @ 1001d2e3 : RotatingDoorPreNetReceiveCatchContext
// Reports the PreNetReceive context and rethrows the active exception through the native C++ helper.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPreNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorPreNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d300 : AR6IORotatingDoor::PostNetReceive
// Restores the saved location after an unequal or unordered coordinate comparison.
void __thiscall AR6IORotatingDoor::PostNetReceive(void)
{
    try {
        this->AR6InteractiveObject::PostNetReceive();
        float10 currentX = (float10)this->Location.X;
        float10 savedX = (float10)PreNetDoorLocationX;
        bool locationChanged = !(savedX == currentX);
        if (!locationChanged) {
            float10 currentY = (float10)this->Location.Y;
            float10 savedY = (float10)PreNetDoorLocationY;
            locationChanged = !(savedY == currentY);
        }
        if (!locationChanged) {
            float10 currentZ = (float10)this->Location.Z;
            float10 savedZ = (float10)PreNetDoorLocationZ;
            locationChanged = !(savedZ == currentZ);
        }
        if (locationChanged) {
            reinterpret_cast<uint&>(this->Location.X) = reinterpret_cast<const uint&>(PreNetDoorLocationX);
            reinterpret_cast<uint&>(this->Location.Y) = reinterpret_cast<const uint&>(PreNetDoorLocationY);
            reinterpret_cast<uint&>(this->Location.Z) = reinterpret_cast<const uint&>(PreNetDoorLocationZ);
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::PostNetReceive");
        throw;
    }
}

// R6Engine.dll @ 1001d397 : RotatingDoorPostNetReceiveCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostNetReceiveCatchPointer(void)
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

// R6Engine.dll @ 1001d3ab : RotatingDoorPostNetReceiveCatchContext
// Reports the PostNetReceive context and rethrows the active exception through the native C++ helper.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorPostNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorPostNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d550 : AR6IORotatingDoor::RenderEditorInfo
// Draws the selected rotating door's maximum-opening direction from its current location.
void __thiscall AR6IORotatingDoor::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* unusedInterface,
    FDynamicActor* unusedActor)
{
    AR6IORotatingDoor* door = this;
    // Samples selection before protected state0.
    bool selected = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(door) + 0xac) & 0x4000U) != 0;
    using SetTransform = void (__thiscall*)(FRenderInterface*, int, FMatrix); // Inferred native slot+0x34 role.
    using Destroy = void (__thiscall*)(FLineBatcher*);
    using Line = void (__thiscall*)(FLineBatcher*, FVector, FVector, uint);
    struct PendingBatcher {
        FLineBatcher* batcher;
        bool active;
        // Disables the cleanup state before normal destruction.
        void Finish() {
            active = false;
            (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
        // Cleans only the temporary whose delayed native completed state was reached.
        ~PendingBatcher() noexcept(false) {
            if (active) (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
    }; // Inferred lifetime view; actual frame/actions remain explicit in the native metadata and funclet.
    try {
        if (!selected) return;
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* render = *(FRenderInterface**)(owner + 0x164);
        const uint* identityWords = *(const uint**)&FMatrixIdentityImport;
        byte* renderTable = *(byte**)render;
        alignas(FMatrix) uint identityCopy[16]; // Raw argument storage avoids an extra caller FMatrix lifetime.
        for (uint i = 0; i != 16; ++i) identityCopy[i] = identityWords[i];
        (*(SetTransform*)(renderTable + 0x34))(render, 0, *(const FMatrix*)identityCopy);
        owner = *(byte**)((byte*)scene + 4);
        render = *(FRenderInterface**)(owner + 0x164);
        alignas(FLineBatcher) byte batcherStorage[0x24]; // Native EBP-0x64.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        // Constructor result is ignored.
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(render, 1, 0);
        int pitch = door->Rotation.Pitch;
        int roll = door->Rotation.Roll;
        uint openingDegrees = static_cast<uint>(door->m_iMaxOpeningDeg);
        uint yaw = static_cast<uint>(door->Rotation.Yaw);
        int openingProduct = (int)(openingDegrees * 0xffffU); // Native signed32 wrapped product.
        byte openingFlags = reinterpret_cast<const byte*>(door)[0x488];
        int openingAngle = openingProduct / 360; // Signed truncation toward zero, using the native magic divide.
        yaw -= 0x8000U;
        bool clockwise = (openingFlags & 0x40) != 0;
        PendingBatcher cleanup{batcher, true}; // State1 follows all of these reads and the clockwise test.
        yaw = clockwise ? yaw + (uint)openingAngle : yaw - (uint)openingAngle;
        FRotator limit = {pitch, (int)yaw, roll};
        FVector directionStorage;
        FVector* direction = &(directionStorage = limit.Vector());
        float10 offsetZ = (float10)direction->Z * 128.0f;
        float offsetY = (float)((float10)direction->Y * 128.0f);
        float offsetX = (float)((float10)direction->X * 128.0f);
        FVector* location = &door->Location;
        float10 endZ = offsetZ + location->Z;
        float10 endY = (float10)offsetY + location->Y;
        float10 endX = (float10)offsetX + location->X;
        FVector end = {(float)endX, (float)endY, (float)endZ}, start;
        ((uint*)&start)[0] = ((const uint*)location)[0];
        ((uint*)&start)[1] = ((const uint*)location)[1];
        ((uint*)&start)[2] = ((const uint*)location)[2];
        reinterpret_cast<Line&>(FLineBatcherDrawLineImport)(batcher, start, end, 0xff0000ff);
        cleanup.Finish();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001d6d1 : RotatingDoorRenderEditorInfoCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorRenderEditorInfoCatchPointer(void)
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

// R6Engine.dll @ 1001d6e5 : RotatingDoorRenderEditorInfoCatchContext
// Reports the RenderEditorInfo context and rethrows the active exception through the native C++ helper.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorRenderEditorInfoCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d710 : AR6IORotatingDoor::DoorOpenTowards
// Refreshes the door center/normal and tests the supplied point against its clockwise opening side.
int __thiscall AR6IORotatingDoor::DoorOpenTowards(FVector point)
{
    FRotator* rotation = &this->Rotation;
    FVector* location = &this->Location;
    FVector* center = &this->m_vCenterOfDoor;
    FVector* normal = &this->m_vNormal;
    FVector forwardStorage;
    FVector* forward = &(forwardStorage = rotation->Vector());
    float10 scaledX = (float10)forward->X * 64.0f;
    float10 scaledY = (float10)forward->Y * 64.0f;
    float scaledZ = (float)((float10)forward->Z * 64.0f);
    float centerX = (float)((float10)location->X - scaledX);
    float centerY = (float)((float10)location->Y - scaledY);
    float10 centerZ = (float10)location->Z - scaledZ;
    center->X = centerX;
    center->Y = centerY;
    center->Z = (float)centerZ;
    FVector up = {0.0f, 0.0f, 1.0f};
    FVector secondForwardStorage, normalStorage;
    FVector* secondForward = &(secondForwardStorage = rotation->Vector());
    FVector* derivedNormal = &(normalStorage = *secondForward ^ up);
    uint* normalWords = reinterpret_cast<uint*>(normal);
    const uint* derivedWords = reinterpret_cast<const uint*>(derivedNormal);
    normalWords[0] = derivedWords[0];
    normalWords[1] = derivedWords[1];
    normalWords[2] = derivedWords[2];
    FVector pointToCenter;
    pointToCenter.X = (float)((float10)center->X - point.X);
    pointToCenter.Y = (float)((float10)center->Y - point.Y);
    pointToCenter.Z = (float)((float10)center->Z - point.Z);
    // Return value ignored; current field values are read afterward.
    pointToCenter.Normalize();
    float10 dot = (float10)pointToCenter.Y * normal->Y;
    dot += (float10)pointToCenter.Z * normal->Z;
    dot += (float10)pointToCenter.X * normal->X;
    bool positiveSide = dot > 0.0f;
    uint openingFlags = reinterpret_cast<byte*>(this)[0x488]; // m_bIsOpeningClockWise is mask0x40.
    return (positiveSide ? ~openingFlags : openingFlags) >> 6 & 1; // Zero/unordered uses the original flag.
}

// R6Engine.dll @ 1001f330 : void AddMyMarker(AR6IORotatingDoor * this, AActor * scoutActor)
// Builds paired scout navigation markers using collision probes and the rotating door's window settings.
void __thiscall AR6IORotatingDoor::AddMyMarker(AActor* scoutActor)
{
    FRotator* doorRotation;
    bool firstProbeHit;
    alignas(FCheckResult) byte initialHitStorage[0x30];
    // Only explicit native writes initialize this storage.
    FCheckResult& initialHit = *reinterpret_cast<FCheckResult*>(initialHitStorage);
    FVector probeStart; // Native EBP-0x98.
    UClass* markerClass;
    FRotator markerRotation; // Native EBP-0x88.
    FVector perpendicular;
    FVector vectorScratch; // Native EBP-0x68; also reused as FRotator output.
    FVector markerBase; // Native base words at EBP-0x3c/-0x58/-0x5c.
    FVector openingSide;
    try {
        if (scoutActor == nullptr) return;
        // Imported AScout metadata; the supplied actor is not arbitrary.
        UClass* scoutClass = AScoutPrivateStaticClassImport;
        if (scoutActor->UObject::IsA(scoutClass) == 0) return;
        // Imported UClass metadata, distinct from the scout class.
        UClass* classClass = UClassPrivateStaticClassImport;
        markerClass = static_cast<UClass*>(UObject::StaticFindObjectChecked(classClass,
            reinterpret_cast<UObject*>(0xffffffffU), (const ushort*)L"R6Door", 0));
        float windowWidth;
        // Preserve raw width before its zero test.
        reinterpret_cast<uint&>(windowWidth) = reinterpret_cast<const uint&>(this->m_fWindowWidth);
        initialHit.Next = nullptr;
        initialHit.Actor = nullptr;
        initialHit.Location = {0.0f, 0.0f, 0.0f};
        initialHit.Normal = {0.0f, 0.0f, 0.0f};
        initialHit.Primitive = nullptr;
        initialHit.Time = 1.0f;
        initialHit.Item = -1;
        initialHit.Material = nullptr;
        if (windowWidth == nativeFloatZero) {
            windowWidth = 46.0f;
        }
        using LineCheck = int (__thiscall*)(ULevel*, FCheckResult&, AActor*, const FVector&,
                const FVector&, uint, FVector);
        doorRotation = &this->Rotation;
        FVector directionScratch; // Native EBP-0x2c; reused by the first two Vector calls.
        FVector axis;
        FVector* direction = &(directionScratch = doorRotation->Vector());
        float10 backZ = (float10)direction->Z * 64.0f;
        float10 backY = (float10)direction->Y * 64.0f;
        float backX = (float)((float10)direction->X * 64.0f); // Only X's product spills here.
        axis.X = 0.0f;
        axis.Y = 0.0f;
        axis.Z = 1.0f;
        markerBase.Z = (float)((float10)this->Location.Z - backZ);
        markerBase.Y = (float)((float10)this->Location.Y - backY);
        markerBase.X = (float)((float10)this->Location.X - backX);
        direction = &(directionScratch = doorRotation->Vector());
        // Use hidden storage, ignoring returned EAX.
        perpendicular = *direction ^ axis;
        float10 oppositeZ = (float10)perpendicular.Z * -1.0f;
        float10 oppositeY = (float10)perpendicular.Y * -1.0f;
        axis.X = (float)((float10)perpendicular.X * -1.0f);
        axis.Y = (float)oppositeY;
        axis.Z = (float)oppositeZ;
        // Ignore EAX; retain the hidden output storage.
        markerRotation = axis.Rotation();
        openingSide = {0.0f, 0.0f, 0.0f};
        probeStart.Z = probeStart.Y = probeStart.X = 0.0f;
        FVector discardedDirection; // Native EBP-0x178; this Vector result is deliberately unused.
        discardedDirection = doorRotation->Vector();
        bool clockwise = (reinterpret_cast<byte*>(this)[0x488] & 0x40) != 0;
        axis.Z = 1.0f;
        axis.Y = 0.0f;
        axis.X = 0.0f;
        FVector* side;
        if (clockwise) {
            direction = &(directionScratch = doorRotation->Vector());
            side = &(vectorScratch = axis ^ *direction);
        } else {
            direction = &(vectorScratch = doorRotation->Vector());
            side = &(directionScratch = *direction ^ axis);
        }
        reinterpret_cast<uint&>(openingSide.X) = reinterpret_cast<uint&>(side->X);
        reinterpret_cast<uint&>(openingSide.Y) = reinterpret_cast<uint&>(side->Y);
        reinterpret_cast<uint&>(openingSide.Z) = reinterpret_cast<uint&>(side->Z);
        float sideZ = (float)((float10)openingSide.Z * 20.0f);
        float sideY = (float)((float10)openingSide.Y * 20.0f);
        float sideX = (float)((float10)openingSide.X * 20.0f);
        direction = &(vectorScratch = doorRotation->Vector());
        float10 probeBackZ = (float10)direction->Z;
        ULevel* probeLevel = this->XLevel; // Capture before the final Vector callback.
        probeBackZ *= 10.0f;
        float10 probeBackY = (float10)direction->Y * 10.0f;
        float probeBackX = (float)((float10)direction->X * 10.0f);
        float probeZ = (float)((float10)this->Location.Z - probeBackZ);
        float probeY = (float)((float10)this->Location.Y - probeBackY);
        float probeX = (float)((float10)this->Location.X - probeBackX);
        float10 startZ = (float10)probeZ + sideZ;
        float10 startY = (float10)probeY + sideY;
        probeStart.X = (float)((float10)probeX + sideX);
        probeStart.Y = (float)startY;
        probeStart.Z = (float)startZ;
        reinterpret_cast<uint&>(axis.X) = reinterpret_cast<uint&>(probeStart.X);
        reinterpret_cast<uint&>(axis.Y) = reinterpret_cast<uint&>(probeStart.Y);
        reinterpret_cast<uint&>(axis.Z) = reinterpret_cast<uint&>(probeStart.Z);
        direction = &(vectorScratch = doorRotation->Vector());
        float10 probeForwardZ = (float10)direction->Z * 15.0f;
        float probeForwardY = (float)((float10)direction->Y * 15.0f);
        float probeForwardX = (float)((float10)direction->X * 15.0f);
        FVector& probeEnd = axis; // Native end packet reuses the earlier up/negated-axis storage.
        float10 endZ = probeForwardZ + probeStart.Z;
        float10 endY = (float10)probeStart.Y + probeForwardY;
        probeEnd.X = (float)((float10)probeForwardX + probeStart.X);
        probeEnd.Y = (float)endY;
        probeEnd.Z = (float)endZ;
        const uint* zeroVector = *(const uint**)&FVectorFVector0Import;
        byte* probeTable = *reinterpret_cast<byte**>(probeLevel); // Current table of the earlier captured level.
        FVector extent;
        reinterpret_cast<uint&>(extent.X) = zeroVector[0];
        reinterpret_cast<uint&>(extent.Y) = zeroVector[1];
        reinterpret_cast<uint&>(extent.Z) = zeroVector[2];
        (*reinterpret_cast<LineCheck*>(probeTable + 0xcc))(probeLevel, initialHit, this,
                probeEnd, probeStart, 0x286, extent);
        firstProbeHit = initialHit.Time != nativeFloatOne; // Unordered Time also counts as a hit.
        using Spawn = AActor* (__thiscall*)(ULevel*, UClass*, uint, FVector, FRotator,
                AActor*, int, int, AActor*, APawn*); // FName is one raw word in this outgoing ABI.
        if ((reinterpret_cast<byte*>(this)[0x488] & 1) != 0) { // m_bTreatDoorAsWindow is sampled after the first trace.
            float10 reachZ = (float10)perpendicular.Z;
            ULevel* tableLevel = this->XLevel;
            reachZ *= 64.0f;
            float reachZSpill = (float)reachZ;
            float10 reachY = (float10)perpendicular.Y * 64.0f;
            float reachYSpill = (float)reachY;
            float reachX = (float)((float10)perpendicular.X * 64.0f);
            float10 upperZ = (float10)reachZSpill + markerBase.Z;
            float10 upperY = (float10)reachYSpill + markerBase.Y;
            axis.X = (float)((float10)reachX + markerBase.X);
            axis.Y = (float)upperY;
            axis.Z = (float)upperZ;
            float lowerZ = (float)((float10)(float)reachZ + markerBase.Z);
            float10 lowerY = reachY + markerBase.Y; // This second Y sum uses the retained, unspilled product.
            float10 lowerX = (float10)reachX + markerBase.X;
            FVector& lower = directionScratch; // Native end buffer EBP-0x2c.
            lower.Z = (float)((float10)lowerZ - 200.0f);
            lower.Y = (float)lowerY;
            lower.X = (float)lowerX;
            const uint* zero = *(const uint**)&FVectorFVector0Import;
            uint extentX = zero[0];
            byte* table = *reinterpret_cast<byte**>(tableLevel);
            FVector traceExtent;
            reinterpret_cast<uint&>(traceExtent.X) = extentX;
            reinterpret_cast<uint&>(traceExtent.Y) = zero[1];
            reinterpret_cast<uint&>(traceExtent.Z) = zero[2];
            ULevel* receiver = this->XLevel; // Slot belongs to the earlier level snapshot.
            (*reinterpret_cast<LineCheck*>(table + 0xcc))(receiver, initialHit, this, lower, axis, 0x286, traceExtent);
            if (initialHit.Time != 1.0f) {
                float10 distance = (float10)(firstProbeHit ? 32 : 16) + windowWidth; // No float spill of this sum.
                float offsetZ = (float)((float10)perpendicular.Z * distance);
                float offsetY = (float)((float10)perpendicular.Y * distance);
                float offsetX = (float)(distance * perpendicular.X);
                direction = &(vectorScratch = doorRotation->Vector());
                float10 halfWidth = (float10)windowWidth;
                ULevel* level = this->XLevel;
                halfWidth *= nativeDouble0Point5;
                float10 backZ = halfWidth * direction->Z;
                float backY = (float)(halfWidth * direction->Y);
                float backX = (float)(halfWidth * direction->X);
                FRotator outgoingRotation;
                outgoingRotation.Pitch = markerRotation.Pitch;
                outgoingRotation.Yaw = markerRotation.Yaw;
                float10 baseZ = (float10)this->Location.Z - backZ;
                outgoingRotation.Roll = markerRotation.Roll;
                float baseY = (float)((float10)this->Location.Y - backY);
                float baseX = (float)((float10)this->Location.X - backX);
                float10 locationZ = baseZ + offsetZ;
                float10 locationY = (float10)baseY + offsetY;
                axis.X = (float)((float10)baseX + offsetX);
                axis.Y = (float)locationY;
                axis.Z = (float)locationZ;
                byte* spawnTable = *reinterpret_cast<byte**>(level);
                AActor* marker =
                    (*reinterpret_cast<Spawn*>(spawnTable + 0xa8))(level, markerClass, 0, axis, outgoingRotation,
                        nullptr, 0, 0, nullptr, nullptr);
                this->m_DoorActorA = static_cast<AR6Door*>(marker);
                if (marker != nullptr) {
                    // Preserve captured width bits in CollisionRadius.
                    reinterpret_cast<uint&>(marker->CollisionRadius) = reinterpret_cast<uint&>(windowWidth);
                    // bNoAutoConnect, using current marker storage.
                    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_DoorActorA) + 0x3a4) |= 0x200;
                }
            } else {
                this->m_DoorActorA = nullptr;
            }
            FRotator* oppositeRotation = &(*reinterpret_cast<FRotator*>(&vectorScratch) = perpendicular.Rotation());
            reachZ = (float10)perpendicular.Z * 64.0f;
            markerRotation.Pitch = oppositeRotation->Pitch;
            reachZSpill = (float)reachZ;
            markerRotation.Yaw = oppositeRotation->Yaw;
            reachY = (float10)perpendicular.Y * 64.0f;
            int roll = oppositeRotation->Roll;
            markerRotation.Roll = roll;
            tableLevel = this->XLevel;
            reachYSpill = (float)reachY;
            reachX = (float)((float10)perpendicular.X * 64.0f);
            float10 nearZ = (float10)markerBase.Z - reachZSpill;
            float10 nearY = (float10)markerBase.Y - reachYSpill;
            FVector& upper = directionScratch; // Opposite probe reuses EBP-0x2c as its start buffer.
            upper.X = (float)((float10)markerBase.X - reachX);
            upper.Y = (float)nearY;
            upper.Z = (float)nearZ;
            lowerZ = (float)((float10)markerBase.Z - (float)reachZ);
            lowerY = (float10)markerBase.Y - reachY;
            lowerX = (float10)markerBase.X - reachX;
            axis.Z = (float)((float10)lowerZ - 200.0f);
            axis.Y = (float)lowerY;
            axis.X = (float)lowerX;
            table = *reinterpret_cast<byte**>(tableLevel);
            zero = *(const uint**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(traceExtent.X) = zero[0];
            reinterpret_cast<uint&>(traceExtent.Y) = zero[1];
            reinterpret_cast<uint&>(traceExtent.Z) = zero[2];
            receiver = this->XLevel;
            (*reinterpret_cast<LineCheck*>(table + 0xcc))(receiver, initialHit, this, axis, upper, 0x286, traceExtent);
            if (initialHit.Time != 1.0f) {
                float10 distance = (float10)(firstProbeHit ? 32 : 16) + windowWidth;
                float offsetZ = (float)((float10)perpendicular.Z * distance);
                float offsetY = (float)((float10)perpendicular.Y * distance);
                float offsetX = (float)(distance * perpendicular.X);
                direction = &(vectorScratch = doorRotation->Vector());
                float10 halfWidth = (float10)windowWidth;
                FRotator outgoingRotation;
                outgoingRotation.Pitch = markerRotation.Pitch;
                halfWidth *= nativeDouble0Point5;
                ULevel* level = this->XLevel;
                float10 backZ = halfWidth * direction->Z;
                float backY = (float)(halfWidth * direction->Y);
                outgoingRotation.Yaw = markerRotation.Yaw;
                float backX = (float)(halfWidth * direction->X);
                float10 baseZ = (float10)this->Location.Z - backZ;
                outgoingRotation.Roll = markerRotation.Roll;
                float baseY = (float)((float10)this->Location.Y - backY);
                float baseX = (float)((float10)this->Location.X - backX);
                float10 locationZ = baseZ - offsetZ;
                float10 locationY = (float10)baseY - offsetY;
                axis.X = (float)((float10)baseX - offsetX);
                axis.Y = (float)locationY;
                axis.Z = (float)locationZ;
                byte* spawnTable = *reinterpret_cast<byte**>(level);
                AActor* marker =
                    (*reinterpret_cast<Spawn*>(spawnTable + 0xa8))(level, markerClass, 0, axis, outgoingRotation,
                        nullptr, 0, 0, nullptr, nullptr);
                this->m_DoorActorB = static_cast<AR6Door*>(marker);
                if (marker != nullptr) {
                    reinterpret_cast<uint&>(marker->CollisionRadius) = reinterpret_cast<uint&>(windowWidth);
                    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_DoorActorB) + 0x3a4) |= 0x200;
                }
            } else {
                this->m_DoorActorB = nullptr;
            }
        } else {
            int distance = firstProbeHit ? 80 : 72;
            float offsetZ = (float)((float10)openingSide.Z * distance);
            float offsetY = (float)((float10)openingSide.Y * distance);
            float offsetX = (float)((float10)distance * openingSide.X);
            float10 locationZ = (float10)offsetZ + markerBase.Z;
            float10 locationY = (float10)offsetY + markerBase.Y;
            axis.X = (float)((float10)offsetX + markerBase.X);
            axis.Y = (float)locationY;
            axis.Z = (float)locationZ;
            float10 negativeZ = (float10)openingSide.Z * -1.0f;
            float10 negativeY = (float10)openingSide.Y * -1.0f;
            directionScratch.X = (float)((float10)openingSide.X * -1.0f);
            directionScratch.Y = (float)negativeY;
            directionScratch.Z = (float)negativeZ;
            FRotator* facing = &(*reinterpret_cast<FRotator*>(&vectorScratch) = directionScratch.Rotation());
            markerRotation.Pitch = facing->Pitch;
            markerRotation.Yaw = facing->Yaw;
            markerRotation.Roll = facing->Roll;
            FRotator outgoingRotation;
            outgoingRotation.Pitch = facing->Pitch; // Outgoing words are a second read from the returned buffer.
            ULevel* level = this->XLevel;
            outgoingRotation.Yaw = facing->Yaw;
            outgoingRotation.Roll = facing->Roll;
            byte* spawnTable = *reinterpret_cast<byte**>(level);
            AActor* marker =
                (*reinterpret_cast<Spawn*>(spawnTable + 0xa8))(level, markerClass, 0, axis, outgoingRotation,
                    nullptr, 0, 0, nullptr, nullptr);
            this->m_DoorActorA = static_cast<AR6Door*>(marker);
            distance = firstProbeHit ? 48 : 56;
            offsetZ = (float)((float10)openingSide.Z * distance);
            offsetY = (float)((float10)openingSide.Y * distance);
            offsetX = (float)((float10)distance * openingSide.X);
            locationZ = (float10)markerBase.Z - offsetZ;
            locationY = (float10)markerBase.Y - offsetY;
            axis.X = (float)((float10)markerBase.X - offsetX);
            axis.Y = (float)locationY;
            axis.Z = (float)locationZ;
            facing = &(*reinterpret_cast<FRotator*>(&vectorScratch) = openingSide.Rotation());
            markerRotation.Pitch = facing->Pitch;
            markerRotation.Yaw = facing->Yaw;
            int roll = facing->Roll;
            level = this->XLevel;
            markerRotation.Roll = roll;
            outgoingRotation.Pitch = facing->Pitch;
            outgoingRotation.Yaw = facing->Yaw;
            outgoingRotation.Roll = facing->Roll;
            spawnTable = *reinterpret_cast<byte**>(level);
            marker = (*reinterpret_cast<Spawn*>(spawnTable + 0xa8))(level, markerClass, 0, axis, outgoingRotation,
                    nullptr, 0, 0, nullptr, nullptr);
            this->m_DoorActorB = static_cast<AR6Door*>(marker);
        }
        AR6Door* marker = this->m_DoorActorA;
        if (marker != nullptr) {
            uint floorLow = reinterpret_cast<uint&>(this->m_iPlanningFloor_0);
            reinterpret_cast<uint&>(marker->m_iPlanningFloor_0) = floorLow;
            marker = this->m_DoorActorA;
            uint floorHigh = reinterpret_cast<uint&>(this->m_iPlanningFloor_1);
            reinterpret_cast<uint&>(marker->m_iPlanningFloor_1) = floorHigh;
            marker = this->m_DoorActorA;
            marker->m_RotatingDoor = this;
            AR6Door* corresponding = this->m_DoorActorB;
            marker = this->m_DoorActorA;
            marker->m_CorrespondingDoor = corresponding;
            if ((reinterpret_cast<byte*>(this)[0x488] & 0x80U) != 0) {
                marker = this->m_DoorActorA;
                marker->ExtraCost = 300;
            }
        }
        marker = this->m_DoorActorB;
        if (marker != nullptr) {
            uint floorLow = reinterpret_cast<uint&>(this->m_iPlanningFloor_0);
            reinterpret_cast<uint&>(marker->m_iPlanningFloor_0) = floorLow;
            marker = this->m_DoorActorB;
            uint floorHigh = reinterpret_cast<uint&>(this->m_iPlanningFloor_1);
            reinterpret_cast<uint&>(marker->m_iPlanningFloor_1) = floorHigh;
            marker = this->m_DoorActorB;
            marker->m_RotatingDoor = this;
            marker = this->m_DoorActorB;
            AR6Door* corresponding = this->m_DoorActorA;
            marker->m_CorrespondingDoor = corresponding;
            if ((reinterpret_cast<byte*>(this)[0x488] & 0x80U) != 0) {
                marker = this->m_DoorActorB;
                marker->ExtraCost = 300;
            }
        }
        if ((reinterpret_cast<byte*>(this)[0x488] & 1) != 0) return;
        if (this->m_DoorActorA == nullptr || this->m_DoorActorB == nullptr) {
            FOutputDevice* output = **(FOutputDevice***)&CoreGLogImport;
            output->FOutputDevice::Logf(
                (const ushort*)L" There is a problem with spawning R6Door actors for a rotating door...");
            return;
        }
        FVector layoutExtent = {40.0f, 40.0f, 80.0f};
        alignas(FCheckResult) byte layoutHitStorage[3][0x30]; // Native EBP-0x16c/-0x13c/-0x10c; no extra constructors.
        FCheckResult& backwardHit = *reinterpret_cast<FCheckResult*>(layoutHitStorage[0]);
        FCheckResult& positiveHit = *reinterpret_cast<FCheckResult*>(layoutHitStorage[1]);
        FCheckResult& negativeHit = *reinterpret_cast<FCheckResult*>(layoutHitStorage[2]);
        InitializeCheckResult(&backwardHit, 1.0f, nullptr);
        InitializeCheckResult(&positiveHit, 1.0f, nullptr);
        InitializeCheckResult(&negativeHit, 1.0f, nullptr);
        bool fixedLayout = (reinterpret_cast<byte*>(this)[0x488] & 0x20) != 0;
        AR6Door* firstMarker = this->m_DoorActorA;
        FVector anchor = {0.0f, 0.0f, 0.0f}; // Native EBP-0x48/-0x44/-0x40; reused for the other approach.
        if (fixedLayout) {
            firstMarker->m_eRoomLayout = 3;
            this->m_DoorActorB->m_eRoomLayout = 3;
            return;
        }
        FVector secondaryScratch; // Native EBP-0xa4; distinct from vectorScratch at EBP-0x68.
        // Native EBP-0x2c reused as a rotator.
        FRotator& sideRotation = *reinterpret_cast<FRotator*>(&directionScratch);
        // Describes the two inlined approach branches; there is no additional native method.
        auto classifyApproach = [&](bool first) {
            ULevel* level = this->XLevel;
            AR6Door* source = first ? firstMarker : this->m_DoorActorB;
            FVector* forward = &(*(first ? &vectorScratch : &secondaryScratch) = source->Rotation.Vector());
            FVector* scaled = ScaleVectorToResult(first ? &axis : &vectorScratch, 264.0f, forward);
            source = first ? this->m_DoorActorA : this->m_DoorActorB;
            float10 backZ = (float10)source->Location.Z - scaled->Z;
            FVector* start = &source->Location;
            float10 backY = (float10)start->Y - scaled->Y;
            float10 backX = (float10)start->X - scaled->X;
            const uint* zero = *(const uint**)&FVectorFVector0Import;
            directionScratch.X = (float)backX;
            directionScratch.Y = (float)backY;
            directionScratch.Z = (float)backZ;
            uint extentX = zero[0];
            byte* table = *reinterpret_cast<byte**>(level);
            FVector traceExtent;
            reinterpret_cast<uint&>(traceExtent.X) = extentX;
            reinterpret_cast<uint&>(traceExtent.Y) = zero[1];
            reinterpret_cast<uint&>(traceExtent.Z) = zero[2];
            // Current actor; start still belongs to the earlier snapshot.
            AActor* traceActor = first ? this->m_DoorActorA : this->m_DoorActorB;
            (*reinterpret_cast<LineCheck*>(table + 0xcc))(
                level, backwardHit, traceActor, directionScratch, *start, 0x286, traceExtent);
            if (backwardHit.Time != 1.0f) {
                (first ? this->m_DoorActorB : this->m_DoorActorA)->m_eRoomLayout = 3;
                return;
            }
            source = first ? this->m_DoorActorA : this->m_DoorActorB;
            forward = &(*(first ? &vectorScratch : &secondaryScratch) = source->Rotation.Vector());
            scaled = ScaleVectorToResult(first ? &directionScratch : &vectorScratch, 100.0f, forward);
            source = first ? this->m_DoorActorA : this->m_DoorActorB;
            float10 anchorZ = (float10)source->Location.Z;
            // This snapshot is retained through the first lateral direction/scale calls.
            level = this->XLevel;
            anchorZ -= scaled->Z;
            float10 anchorY = (float10)source->Location.Y - scaled->Y;
            float10 anchorX = (float10)source->Location.X - scaled->X;
            axis.X = (float)anchorX;
            reinterpret_cast<uint&>(anchor.X) = reinterpret_cast<uint&>(axis.X);
            axis.Y = (float)anchorY;
            reinterpret_cast<uint&>(anchor.Y) = reinterpret_cast<uint&>(axis.Y);
            axis.Z = (float)anchorZ;
            reinterpret_cast<uint&>(anchor.Z) = reinterpret_cast<uint&>(axis.Z);
            int roll = source->Rotation.Roll;
            uint yaw = static_cast<uint>(source->Rotation.Yaw);
            int pitch = source->Rotation.Pitch;
            sideRotation.Roll = roll;
            sideRotation.Pitch = pitch;
            sideRotation.Yaw = (int)(yaw + 0x4000U); // Native yaw adjustment wraps32 bits.
            uint cachedExtentZ;
            // Keeps direct and anchor fallback traces distinct, including their level and buffer snapshots.
            auto lateralProbe = [&](bool positive, bool fallback, FCheckResult& hit) {
                if (!(positive && !fallback)) {
                    AR6Door* current = first ? this->m_DoorActorA : this->m_DoorActorB;
                    uint currentYaw = static_cast<uint>(current->Rotation.Yaw);
                    int currentRoll = current->Rotation.Roll;
                    level = this->XLevel;
                    int currentPitch = current->Rotation.Pitch;
                    sideRotation.Yaw = (int)(positive ? currentYaw + 0x4000U : currentYaw - 0x4000U);
                    sideRotation.Pitch = currentPitch;
                    sideRotation.Roll = currentRoll;
                }
                FVector* directionOutput = first && positive && !fallback ? &vectorScratch : &secondaryScratch;
                forward = &(*directionOutput = sideRotation.Vector());
                FVector* scaleOutput = first && positive && !fallback ? &secondaryScratch : &vectorScratch;
                scaled = ScaleVectorToResult(scaleOutput, 244.0f, forward);
                if (!fallback) {
                    float10 endZ = (float10)scaled->Z;
                    AR6Door* current = first ? this->m_DoorActorA : this->m_DoorActorB;
                    endZ += current->Location.Z;
                    uint currentExtentX = reinterpret_cast<uint&>(layoutExtent.X);
                    float10 endY = (float10)scaled->Y;
                    FVector* origin = &current->Location;
                    endY += origin->Y;
                    float10 endX = (float10)scaled->X + origin->X;
                    axis.X = (float)endX;
                    axis.Y = (float)endY;
                    axis.Z = (float)endZ;
                    byte* currentTable = *reinterpret_cast<byte**>(level);
                    reinterpret_cast<uint&>(traceExtent.X) = currentExtentX;
                    reinterpret_cast<uint&>(traceExtent.Y) = reinterpret_cast<uint&>(layoutExtent.Y);
                    cachedExtentZ = reinterpret_cast<uint&>(layoutExtent.Z);
                    reinterpret_cast<uint&>(traceExtent.Z) = cachedExtentZ;
                    (*reinterpret_cast<LineCheck*>(currentTable + 0xcc))(level, hit, current, axis, *origin, 0x286,
                        traceExtent);
                } else {
                    float10 endZ = (float10)anchor.Z + scaled->Z;
                    uint currentExtentX = reinterpret_cast<uint&>(layoutExtent.X);
                    float10 endY = (float10)anchor.Y + scaled->Y;
                    reinterpret_cast<uint&>(traceExtent.X) = currentExtentX;
                    float10 endX = (float10)anchor.X + scaled->X;
                    reinterpret_cast<uint&>(traceExtent.Y) = reinterpret_cast<uint&>(layoutExtent.Y);
                    // Callee-preserved EBX from the preceding direct trace.
                    reinterpret_cast<uint&>(traceExtent.Z) = cachedExtentZ;
                    axis.X = (float)endX;
                    AActor* actor = first ? this->m_DoorActorA : this->m_DoorActorB;
                    axis.Y = (float)endY;
                    axis.Z = (float)endZ;
                    byte* currentTable = *reinterpret_cast<byte**>(level);
                    (*reinterpret_cast<LineCheck*>(currentTable + 0xcc))(
                        level, hit, actor, axis, anchor, 0x286, traceExtent);
                }
            };
            lateralProbe(true, false, positiveHit);
            if (positiveHit.Time == 1.0f) lateralProbe(true, true, positiveHit);
            lateralProbe(false, false, negativeHit);
            if (negativeHit.Time == 1.0f) lateralProbe(false, true, negativeHit);
            bool positiveBlocked = positiveHit.Time != 1.0f; // Unordered results take the blocked branch.
            bool negativeBlocked = negativeHit.Time != 1.0f;
            byte layout = (byte)((positiveBlocked ? 2 : 0) | (negativeBlocked ? 1 : 0));
            (first ? this->m_DoorActorB : this->m_DoorActorA)->m_eRoomLayout = layout;
        };
        classifyApproach(true);
        classifyApproach(false);
        return;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6IORotatingDoor::AddMyMarker");
        throw;
    }
}

// R6Engine.dll @ 100206f5 : RotatingDoorMarkerCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0xdc through EBP-0xa8.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorMarkerCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xdc]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0xa8]
        push ecx
        mov dword ptr [ebp-0xa8],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020712 : RotatingDoorMarkerCatchContext
// Reports the marker-construction context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorMarkerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6IORotatingDoorAddMyMarker
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020730 : AR6IORotatingDoor::execWillOpenOnTouch
// Evaluates a pawn and optional debug token, then stores the complete touch-opening result.
void __thiscall AR6IORotatingDoor::execWillOpenOnTouch(FFrame& stack, void* result)
{
    AR6IORotatingDoor* door = this;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** code = &frame->Code;
    byte* cursor = *code;
    AR6Pawn* pawn = nullptr; // Evaluated pointer at native EBP-0x14.
    byte opcode = *cursor;
    *code = cursor + 1; // Native state-1: the first cursor advance and dispatch preparation precede catches.
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Object read follows the captured table address.
    try {
        natives[opcode](receiver, frame, &pawn);
        byte* afterArguments = *code + 1;
        *code = afterArguments; // Skip the end-parameters byte before peeking at the following opcode.
        if (*afterArguments == 0x42) {
            UObject* debugReceiver = frame->Object;
            *code = afterArguments + 1;
            ScriptNative* debugNatives = *(ScriptNative**)&CoreGNativesImport;
            debugNatives[0x42](debugReceiver, frame, nullptr);
        }
        int answer = door->AR6IORotatingDoor::WillOpenOnTouch(pawn); // Direct native call; no virtual slot.
        *(int*)result = answer; // Native result pointer is read after the call, and all four result bytes are stored.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        // Preserve the native AIController diagnostic label, including its inconsistent exec prefix.
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6AIController::execWillOpenOnTouch");
        throw;
    }
}

// R6Engine.dll @ 100207c5 : RotatingDoorExecWillOpenOnTouchCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecWillOpenOnTouchCatchPointer(void)
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

// R6Engine.dll @ 100207d9 : RotatingDoorExecWillOpenOnTouchCatchContext
// Reports the execWillOpenOnTouch context and rethrows the active native exception.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecWillOpenOnTouchCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerExecWillOpenOnTouch
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020960 : AR6IORotatingDoor::execAddBreach
// Evaluates a bullet pointer, captures it before Add and appends it through the current array storage.
void __thiscall AR6IORotatingDoor::execAddBreach(FFrame& stack, void* unusedResult)
{
    AR6IORotatingDoor* door = this;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** code = &frame->Code;
    byte* cursor = *code;
    AR6AbstractBullet* breachAttached = nullptr; // Evaluated pointer at native EBP-0x14.
    byte opcode = *cursor;
    *code = cursor + 1; // Native state-1: the first cursor advance and dispatch preparation precede catches.
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Object read follows the captured table address.
    try {
        natives[opcode](receiver, frame, &breachAttached);
        byte* afterArguments = *code + 1;
        *code = afterArguments; // Skip the end-parameters byte before peeking at the following opcode.
        if (*afterArguments == 0x42) {
            UObject* debugReceiver = frame->Object;
            *code = afterArguments + 1;
            ScriptNative* debugNatives = *(ScriptNative**)&CoreGNativesImport;
            debugNatives[0x42](debugReceiver, frame, nullptr);
        }
        AR6AbstractBullet* capturedBreach = breachAttached;
        FArray* breaches = reinterpret_cast<FArray*>(&door->m_BreachAttached);
        int index = breaches->FArray::Add(1, 4);
        // Reload after Add; the captured pointer survives its callbacks.
        uint data = reinterpret_cast<const NativeArrayHeader32*>(breaches)->dataAddress;
        // Unchecked wrapped slot; no element constructor.
        *reinterpret_cast<AR6AbstractBullet**>(data + (uint)index * 4U) = capturedBreach;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        // Preserve the native AIController diagnostic label, including its inconsistent exec prefix.
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6AIController::AddBreach");
        throw;
    }
}

// R6Engine.dll @ 100209ff : RotatingDoorExecAddBreachCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecAddBreachCatchPointer(void)
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

// R6Engine.dll @ 10020a13 : RotatingDoorExecAddBreachCatchContext
// Reports the execAddBreach context and rethrows the active native exception.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecAddBreachCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerAddBreach
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020a30 : AR6IORotatingDoor::execRemoveBreach
// Evaluates a bullet pointer and removes matching words through a live key in the reused frame argument.
// Native ABI view retains the incoming frame word for the breach-removal key.
void __thiscall AR6IORotatingDoor::execRemoveBreach(FFrame* stack, void* unusedResult)
{
    AR6IORotatingDoor* door = this;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* frame = stack;
    byte** code = &frame->Code;
    byte* cursor = *code;
    AR6AbstractBullet* breachAttached = nullptr; // Evaluated pointer at native EBP-0x14.
    byte opcode = *cursor;
    *code = cursor + 1; // Native state-1: the first cursor advance and dispatch preparation precede catches.
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = frame->Object; // Object read follows the captured table address.
    try {
        natives[opcode](receiver, frame, &breachAttached);
        byte* afterArguments = *code + 1;
        *code = afterArguments; // Skip the end-parameters byte before peeking at the following opcode.
        if (*afterArguments == 0x42) {
            UObject* debugReceiver = frame->Object;
            *code = afterArguments + 1;
            ScriptNative* debugNatives = *(ScriptNative**)&CoreGNativesImport;
            debugNatives[0x42](debugReceiver, frame, nullptr);
        }
        // Native reuses incoming EBP+8 for this word; cached frame is no longer used.
        stack = reinterpret_cast<FFrame*>(breachAttached);
        RemoveMatchingWords4(reinterpret_cast<FArray*>(&door->m_BreachAttached), reinterpret_cast<const uint*>(&stack));
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        // Preserve the native AIController diagnostic label, including its inconsistent exec prefix.
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6AIController::RemoveBreach");
        throw;
    }
}

// R6Engine.dll @ 10020aca : RotatingDoorExecRemoveBreachCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecRemoveBreachCatchPointer(void)
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

// R6Engine.dll @ 10020ade : RotatingDoorExecRemoveBreachCatchContext
// Reports the execRemoveBreach context and rethrows the active native exception.
__declspec(naked) __declspec(noreturn) void __cdecl RotatingDoorExecRemoveBreachCatchContext(void)
{
    __asm {
        push offset nativeTextAR6AIControllerRemoveBreach
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043b60 : RotatingDoorDestructionState0Cleanup
// Tail-enters action-object base destruction on the saved rotating-door receiver at inherited EBP-0x10.
__declspec(naked) void __cdecl RotatingDoorDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6IActionObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043b68 : RotatingDoorDestructionState1Cleanup
// Tail-enters canonical array destruction on the saved object's breach array at +0x4c8.
__declspec(naked) void __cdecl RotatingDoorDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4c8
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10044370 : RotatingDoorRenderEditorInfoState1Cleanup
// Tail-enters current batcher destruction on the completed renderer temporary at inherited EBP-0x64.
__declspec(naked) void __cdecl RotatingDoorRenderEditorInfoState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x64]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10048170 : DestroyAR6IORotatingDoorClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6IORotatingDoorClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6IORotatingDoor::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046e00 : InitializeAR6IORotatingDoorClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6IORotatingDoorClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6IORotatingDoor::PrivateStaticClass, 0, 0x4f8, 0,
        &AR6IActionObject::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6IORotatingDoor,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6IORotatingDoor::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6IORotatingDoorClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046e80 : PublishAR6IORotatingDoorAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6IORotatingDoorAutoClass(void)
{
    autoclassAR6IORotatingDoor = &AR6IORotatingDoor::PrivateStaticClass;
}

// R6Engine.dll @ 10047200 : RegisterAR6IORotatingDoorRemoveBreachNative
// Registers native index0x7e3 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6IORotatingDoorRemoveBreachNative(void)
{
    AR6IORotatingDoorRemoveBreachRegistrationResult = GRegisterNative(0x7e3, intAR6IORotatingDoorexecRemoveBreach);
}

// R6Engine.dll @ 10047220 : RegisterAR6IORotatingDoorAddBreachNative
// Registers native index0x7e2 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6IORotatingDoorAddBreachNative(void)
{
    AR6IORotatingDoorAddBreachRegistrationResult = GRegisterNative(0x7e2, intAR6IORotatingDoorexecAddBreach);
}

// R6Engine.dll @ 10047240 : RegisterAR6IORotatingDoorWillOpenOnTouchNative
// Registers native index0x5e7 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6IORotatingDoorWillOpenOnTouchNative(void)
{
    AR6IORotatingDoorWillOpenOnTouchRegistrationResult =
        GRegisterNative(0x5e7, intAR6IORotatingDoorexecWillOpenOnTouch);
}
// R6Engine.dll @ 10015770 : AR6IORotatingDoor::DeletingDestructor
// Destroys one door or a cookie-counted array, optionally frees storage and returns its original allocation address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6IORotatingDoor::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6IORotatingDoor* door = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(door) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6IORotatingDoorDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(door) - 4;
        _eh_vector_destructor_iterator_(door, 0x4f8, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is fetched after element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    door->AR6IORotatingDoor::~AR6IORotatingDoor();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(door, 0x4f8);
    }
    return door;
}

// R6Engine.dll @ 10043b76 : RotatingDoorDestructionExceptionHandler
// Supplies the member/base destruction FuncInfo while retaining the native dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}
// R6Engine.dll @ 10044320 : RotatingDoorShouldTraceExceptionHandler
// Supplies the ShouldTrace FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorShouldTraceExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorShouldTraceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044330 : RotatingDoorPostScriptDestroyedExceptionHandler
// Supplies the PostScriptDestroyed FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorPostScriptDestroyedExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorPostScriptDestroyedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044340 : RotatingDoorPreNetReceiveExceptionHandler
// Supplies the PreNetReceive FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorPreNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorPreNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044350 : RotatingDoorPostNetReceiveExceptionHandler
// Supplies the PostNetReceive FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorPostNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorPostNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044379 : RotatingDoorRenderEditorInfoExceptionHandler
// Supplies the RenderEditorInfo FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorRenderEditorInfoExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorRenderEditorInfoFuncInfo
        jmp __CxxFrameHandler
    }
}
// R6Engine.dll @ 100443c0 : RotatingDoorExecWillOpenOnTouchExceptionHandler
// Supplies the exact execWillOpenOnTouch FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorExecWillOpenOnTouchExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorExecWillOpenOnTouchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100443e0 : RotatingDoorExecAddBreachExceptionHandler
// Supplies the exact execAddBreach FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorExecAddBreachExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorExecAddBreachFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100443f0 : RotatingDoorExecRemoveBreachExceptionHandler
// Supplies the exact execRemoveBreach FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorExecRemoveBreachExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorExecRemoveBreachFuncInfo
        jmp __CxxFrameHandler
    }
}
// R6Engine.dll @ 100443b0 : RotatingDoorMarkerExceptionHandler
// Supplies the marker parent's catch-only FuncInfo without creating a dispatcher frame.
__declspec(naked) void __cdecl RotatingDoorMarkerExceptionHandler(void)
{
    __asm {
        mov eax,offset rotatingDoorMarkerFuncInfo
        jmp __CxxFrameHandler
    }
}
