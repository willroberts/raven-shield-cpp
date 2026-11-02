#include "native_array_views.hpp"

#include "native_exported_data.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Partial PE32 animation-query slots; gaps do not assert the remaining mesh interface.
// Calls retain raw FName/float words, live ST0 results and separately captured table timing.
struct NativeAnimQueryVtable {
    byte unmodeledBeforeAnimNamed[0xb0];
    uint getAnimNamedAddress;
    byte unmodeledBeforeFrameCount[12];
    uint animGetFrameCountAddress;
    uint animGetRateAddress;
    byte unmodeledBeforeForcePose[60];
    uint animForcePoseAddress;
};

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl AnimLaunchExceptionHandler(void);
__declspec(naked) void __cdecl StatusStringExceptionHandler(void);
__declspec(naked) void __cdecl AnimPercentageExceptionHandler(void);
__declspec(naked) long long TruncateX87ToSigned64();
__declspec(naked) void __cdecl AnimDurationExceptionHandler(void);
__declspec(naked) void __cdecl AnimUpdateExceptionHandler(void);
__declspec(naked) void __cdecl AnimThresholdExceptionHandler(void);
__declspec(naked) void __cdecl AnimTotalExceptionHandler(void);
__declspec(naked) void __cdecl AnimTransitionExceptionHandler(void);
__declspec(naked) void __cdecl AnimPreviewExceptionHandler(void);
__declspec(naked) void __cdecl DestroyUR6SubActionAnimSequenceClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
int __cdecl CastToUSkeletalMeshInstance(int object);

// R6Engine.dll data @ 1004de10 : UR6SubActionAnimSequenceVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: UR6SubActionAnimSequence::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix UR6SubActionAnimSequenceVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055c44 : nativeTextAnimSFrameF
extern const ushort nativeTextAnimSFrameF[17];

// R6Engine.dll data @ 10055ad4 : nativeTextAnimSequence
extern const ushort nativeTextAnimSequence[14];

// R6Engine.dll data @ 10055e1e : nativeTextR6SubActionAnimSequence
extern const ushort nativeTextR6SubActionAnimSequence[24];

// R6Engine.dll data @ 10055ba8 : nativeTextUR6SubActionAnimSequenceGetAnimDuration
extern const ushort nativeTextUR6SubActionAnimSequenceGetAnimDuration[42];

// R6Engine.dll data @ 10055b58 : nativeTextUR6SubActionAnimSequenceGetAnimation
extern const ushort nativeTextUR6SubActionAnimSequenceGetAnimation[39];

// R6Engine.dll data @ 10055cf8 : nativeTextUR6SubActionAnimSequenceGetTotalLength
extern const ushort nativeTextUR6SubActionAnimSequenceGetTotalLength[41];

// R6Engine.dll data @ 10055da0 : nativeTextUR6SubActionAnimSequencePreBeginPreview
extern const ushort nativeTextUR6SubActionAnimSequencePreBeginPreview[42];

// R6Engine.dll data @ 10055d50 : nativeTextUR6SubActionAnimSequenceUpdateGame
extern const ushort nativeTextUR6SubActionAnimSequenceUpdateGame[37];

// R6Engine.dll data @ 10055a90 : nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage1
extern const ushort nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage1[33];

// R6Engine.dll data @ 10055c00 : nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage2
extern const ushort nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage2[33];

// R6Engine.dll data @ 10055c68 : nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage3
extern const ushort nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage3[33];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl AnimDurationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimDurationCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimLaunchCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimLaunchCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimPercentageCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimPercentageCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimPreviewCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimPreviewCatchPointer(void);
__declspec(naked) void __cdecl AnimSequenceDtorState0Cleanup(void);
__declspec(naked) void __cdecl AnimSequenceDtorState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimThresholdCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimThresholdCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimTotalCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimTotalCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimTransitionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimTransitionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimUpdateCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl AnimUpdateCatchPointer(void);
__declspec(naked) void __cdecl AnimUpdateState1Cleanup(void);
__declspec(naked) void __cdecl UR6SubActionAnimSequenceDestructionExceptionHandler(void);

// R6Engine.dll data @ 1005ea84 : animPreviewUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animPreviewUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ea94 : animPreviewCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animPreviewCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&AnimPreviewCatchPointer) },
    { 0, 0, 0, ((uint)&AnimPreviewCatchContext) }
};

// R6Engine.dll data @ 1005eab4 : animPreviewTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animPreviewTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animPreviewCatchMap) }
};

// R6Engine.dll data @ 1005eac8 : animPreviewFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animPreviewFuncInfo = { 0x19930520, 0x2, ((uint)&animPreviewUnwindMap), 0x1,
    ((uint)&animPreviewTryMap), 0 };

// R6Engine.dll data @ 1005ea24 : animTransitionUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animTransitionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ea34 : animTransitionCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animTransitionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&AnimTransitionCatchPointer) },
    { 0, 0, 0, ((uint)&AnimTransitionCatchContext) }
};

// R6Engine.dll data @ 1005ea54 : animTransitionTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animTransitionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animTransitionCatchMap) }
};

// R6Engine.dll data @ 1005ea68 : animTransitionFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animTransitionFuncInfo = { 0x19930520, 0x2, ((uint)&animTransitionUnwindMap), 0x1,
    ((uint)&animTransitionTryMap), 0 };

// R6Engine.dll data @ 1005e904 : animThresholdUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animThresholdUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e914 : animThresholdCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animThresholdCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AnimThresholdCatchPointer) },
    { 0, 0, 0, ((uint)&AnimThresholdCatchContext) }
};

// R6Engine.dll data @ 1005e934 : animThresholdTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animThresholdTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animThresholdCatchMap) }
};

// R6Engine.dll data @ 1005e948 : animThresholdFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animThresholdFuncInfo = { 0x19930520, 0x2, ((uint)&animThresholdUnwindMap), 0x1,
    ((uint)&animThresholdTryMap), 0 };

// R6Engine.dll data @ 1005e89c : animUpdateUnwindMap
// Retains exact preview ownership, terminal states and inherited catch-frame bindings.
const NativeUnwindEntry animUpdateUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&AnimUpdateState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e8b4 : animUpdateCatchMap
// Retains exact preview ownership, terminal states and inherited catch-frame bindings.
const NativeCatchEntry animUpdateCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AnimUpdateCatchPointer) },
    { 0, 0, 0, ((uint)&AnimUpdateCatchContext) }
};

// R6Engine.dll data @ 1005e8d4 : animUpdateTryMap
// Retains exact preview ownership, terminal states and inherited catch-frame bindings.
const NativeTryBlock animUpdateTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&animUpdateCatchMap) }
};

// R6Engine.dll data @ 1005e8e8 : animUpdateFuncInfo
// Retains exact preview ownership, terminal states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animUpdateFuncInfo = { 0x19930520, 0x3, ((uint)&animUpdateUnwindMap), 0x1,
    ((uint)&animUpdateTryMap), 0 };

// R6Engine.dll data @ 1005e7dc : animPercentageUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animPercentageUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e7ec : animPercentageCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animPercentageCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AnimPercentageCatchPointer) },
    { 0, 0, 0, ((uint)&AnimPercentageCatchContext) }
};

// R6Engine.dll data @ 1005e80c : animPercentageTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animPercentageTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animPercentageCatchMap) }
};

// R6Engine.dll data @ 1005e820 : animPercentageFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animPercentageFuncInfo = { 0x19930520, 0x2, ((uint)&animPercentageUnwindMap), 0x1,
    ((uint)&animPercentageTryMap), 0 };

// R6Engine.dll data @ 1005e83c : animDurationUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animDurationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e84c : animDurationCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animDurationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&AnimDurationCatchPointer) },
    { 0, 0, 0, ((uint)&AnimDurationCatchContext) }
};

// R6Engine.dll data @ 1005e86c : animDurationTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animDurationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animDurationCatchMap) }
};

// R6Engine.dll data @ 1005e880 : animDurationFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animDurationFuncInfo = { 0x19930520, 0x2, ((uint)&animDurationUnwindMap), 0x1,
    ((uint)&animDurationTryMap), 0 };

// R6Engine.dll data @ 1005e9c4 : animTotalUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry animTotalUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e9d4 : animTotalCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry animTotalCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&AnimTotalCatchPointer) },
    { 0, 0, 0, ((uint)&AnimTotalCatchContext) }
};

// R6Engine.dll data @ 1005e9f4 : animTotalTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock animTotalTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animTotalCatchMap) }
};

// R6Engine.dll data @ 1005ea08 : animTotalFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix animTotalFuncInfo = { 0x19930520, 0x2, ((uint)&animTotalUnwindMap), 0x1,
    ((uint)&animTotalTryMap), 0 };

// R6Engine.dll data @ 1005e6b4 : animLaunchUnwindMap
// Retains the launch method's exact no-local-cleanup states and inherited catches.
const NativeUnwindEntry animLaunchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e6c4 : animLaunchCatchMap
// Retains the launch method's exact no-local-cleanup states and inherited catches.
const NativeCatchEntry animLaunchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&AnimLaunchCatchPointer) },
    { 0, 0, 0, ((uint)&AnimLaunchCatchContext) }
};

// R6Engine.dll data @ 1005e6e4 : animLaunchTryMap
// Retains the launch method's exact no-local-cleanup states and inherited catches.
const NativeTryBlock animLaunchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&animLaunchCatchMap) }
};

// R6Engine.dll data @ 1005e6f8 : animLaunchFuncInfo
// Retains the launch method's exact no-local-cleanup states and inherited catches.
const NativeFunctionInfoPrefix animLaunchFuncInfo = { 0x19930520, 0x2, ((uint)&animLaunchUnwindMap), 0x1,
    ((uint)&animLaunchTryMap), 0 };

// R6Engine.dll data @ 1005837c : animSequenceDtorUnwind
// Retains pending array/base cleanup states, without catches.
const NativeUnwindEntry animSequenceDtorUnwind[2] = {
    { -1, ((uint)&AnimSequenceDtorState0Cleanup) },
    { 0, ((uint)&AnimSequenceDtorState1Cleanup) }
};

// R6Engine.dll data @ 1005838c : animSequenceDtorInfo
// Retains pending array/base cleanup states, without catches.
const NativeFunctionInfoPrefix animSequenceDtorInfo = { 0x19930520, 0x2, ((uint)&animSequenceDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 100844e0 : autoclassUR6SubActionAnimSequence
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassUR6SubActionAnimSequence = nullptr;

// R6Engine.dll @ 1000a570 : UR6SubActionAnimSequence::eventSequenceFinished
// Dispatches SequenceFinished through the captured table with preplaced null parameter/result words.
void __thiscall UR6SubActionAnimSequence::eventSequenceFinished(void)
{
    FName eventName = R6ENGINE_SequenceFinished;
    struct EventPacketView { // Inferred words at entryESP-0x18..-0xc, reused across lookup and dispatch.
        FName eventName;
        union { int lookupSuper; UFunction* function; };
        void* parameters;
        void* result;
    } packet;
    packet.result = nullptr;
    packet.parameters = nullptr;
    packet.lookupSuper = 0;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    packet.eventName = eventName;
    packet.function = this->UObject::FindFunctionChecked(
        reinterpret_cast<const FName&>(packet.eventName), packet.lookupSuper);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, packet.function, packet.parameters, packet.result);
}

// R6Engine.dll @ 1000a5a0 : UR6SubActionAnimSequence::eventSequenceChanged
// Dispatches SequenceChanged through the captured table with preplaced null parameter/result words.
void __thiscall UR6SubActionAnimSequence::eventSequenceChanged(void)
{
    FName eventName = R6ENGINE_SequenceChanged;
    struct EventPacketView { // Inferred words at entryESP-0x18..-0xc, reused across lookup and dispatch.
        FName eventName;
        union { int lookupSuper; UFunction* function; };
        void* parameters;
        void* result;
    } packet;
    packet.result = nullptr;
    packet.parameters = nullptr;
    packet.lookupSuper = 0;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    packet.eventName = eventName;
    packet.function = this->UObject::FindFunctionChecked(
        reinterpret_cast<const FName&>(packet.eventName), packet.lookupSuper);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, packet.function, packet.parameters, packet.result);
}

// R6Engine.dll @ 1000a5d0 : UR6SubActionAnimSequence::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl UR6SubActionAnimSequence::StaticClass(void)
{
    return &UR6SubActionAnimSequence::PrivateStaticClass; // Selected object at0x10083fd8.
}

// R6Engine.dll @ 1000a5e0 : UR6SubActionAnimSequence::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl UR6SubActionAnimSequence::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &UR6SubActionAnimSequence::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10010950 : UR6SubActionAnimSequence::operator=
// Assigns sequence state and its array in native read/write order.
UR6SubActionAnimSequence& __thiscall UR6SubActionAnimSequence::operator=(const UR6SubActionAnimSequence& sourceObject)
{
    const UR6SubActionAnimSequence* source = &sourceObject;
    const UR6SubActionAnimSequence* capturedSource = source;
    const UR6SubActionAnimSequence* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    this->UMatSubAction::operator=(*baseSourceArgument);
    int currentIndex = capturedSource->m_CurIndex;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x5c);
    uint earlyFlags = *destinationFlags; // Captured before publishing the current index.
    this->m_CurIndex = currentIndex;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x5c);
    uint firstDifference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ firstDifference; // m_bUseRootMotion.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bFirstTime.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bResetAnimation.
    *destinationFlags = copiedFlags;
    this->m_AffectedPawn = capturedSource->m_AffectedPawn;
    this->m_AffectedActor = capturedSource->m_AffectedActor;
    uint currentSequenceWord = reinterpret_cast<const uint&>(capturedSource->m_CurSequence);
    const FArray* arraySourceArgument = (const FArray*)&capturedSource->m_Sequences; // Reuses entryESP-0xc.
    reinterpret_cast<uint&>(this->m_CurSequence) = currentSequenceWord;
    AssignRecords4((FArray*)&this->m_Sequences, arraySourceArgument);
    return *this;
}

// R6Engine.dll @ 10013770 : UR6SubActionAnimSequence::~UR6SubActionAnimSequence
// Conditionally destroys UObject state, then destroys array storage and the base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall UR6SubActionAnimSequence::~UR6SubActionAnimSequence(UR6SubActionAnimSequence* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&UR6SubActionAnimSequenceDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    *(uint*)this = ((uint)&UR6SubActionAnimSequenceVirtualTable);
    guard[3] = 1;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0;
    DestroyWordArrayStorage((FArray*)&this->m_Sequences);
    guard[3] = 0xffffffff;
    this->UMatSubAction::~UMatSubAction();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 100137d0 : UR6SubActionAnimSequence::UR6SubActionAnimSequence (native default view)
// Constructs the base and publishes the derived vtable without scalar or array-header initialization.
// Keep the native ABI view: array member no-init declarations remain unresolved.
UR6SubActionAnimSequence* __thiscall UR6SubActionAnimSequence::UR6SubActionAnimSequence(UR6SubActionAnimSequence* this)
{
    UMatSubAction::UMatSubAction(this);
    *(uint*)this = ((uint)&UR6SubActionAnimSequenceVirtualTable);
    return this;
}

// R6Engine.dll @ 100137f0 : UR6SubActionAnimSequence::UR6SubActionAnimSequence
// Copy-constructs sequence state and its array while retaining the delayed base-cleanup state.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
UR6SubActionAnimSequence* __thiscall
UR6SubActionAnimSequence::UR6SubActionAnimSequence(UR6SubActionAnimSequence* this,
    const UR6SubActionAnimSequence* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&MatSubActionBaseCleanupExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const UR6SubActionAnimSequence* capturedSource = source;
    const UR6SubActionAnimSequence* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats saved-this placement after the outgoing argument.
    UMatSubAction::UMatSubAction(this, baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x5c);
    uint earlyFlags = *destinationFlags; // Captured before vtable and current-index publication.
    *(uint*)this = ((uint)&UR6SubActionAnimSequenceVirtualTable);
    this->m_CurIndex = capturedSource->m_CurIndex;
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x5c);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bFirstTime.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bResetAnimation.
    *destinationFlags = copiedFlags;
    this->m_AffectedPawn = capturedSource->m_AffectedPawn;
    this->m_AffectedActor = capturedSource->m_AffectedActor;
    uint currentSequenceWord = reinterpret_cast<const uint&>(capturedSource->m_CurSequence);
    const FArray* arraySourceArgument = (const FArray*)&capturedSource->m_Sequences; // Reuses entryESP-0x1c.
    guard[3] = 0;
    reinterpret_cast<uint&>(this->m_CurSequence) = currentSequenceWord;
    CopyConstructRecords4((FArray*)&this->m_Sequences, arraySourceArgument);
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10013af0 : UR6SubActionAnimSequence::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl UR6SubActionAnimSequence::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp UR6SubActionAnimSequenceConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100408d0 : UR6SubActionAnimSequence::GetCurAnimPct
// Returns the current interval fraction as an unspilled x87 value, or the native zero for equal endpoints.
float10 __thiscall UR6SubActionAnimSequence::GetCurAnimPct(float positionPct)
{
    byte* sequence = reinterpret_cast<byte*&>(this->m_CurSequence);
    float10 zero = (float10)nativeFloatZero; // Loaded before either endpoint, even on the division path.
    float10 beginPct = (float10)*(float*)(sequence + 0x44);
    float10 endPct = (float10)*(float*)(sequence + 0x48);
    if (endPct == beginPct) return zero; // FUCOMPP unordered endpoints take the division path.
    float10 elapsedPct = (float10)positionPct; // Native first discards the retained zero operand.
    elapsedPct -= (float10)*(float*)(sequence + 0x44);
    float10 intervalPct = (float10)*(float*)(sequence + 0x48);
    intervalPct -= (float10)*(float*)(sequence + 0x44);
    return elapsedPct / intervalPct;
}

// R6Engine.dll @ 10040900 : UR6SubActionAnimSequence::LaunchSequence
// Starts animation channel17 and optionally enables root motion before clearing world collision on the current actor.
int __thiscall UR6SubActionAnimSequence::LaunchSequence(void)
{
    // Descriptive frame: saved ESP EBP-34, caught EBP-1c/rethrow EBP-14; EBP-18 holds the FName argument view.
    struct LaunchFrame {
        uint savedEDI, savedESI, savedEBX, floorX, floorY, floorZ, caughtText;
        uint* nameArgument;
        uint rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimLaunchExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte* action = (byte*)this;
    byte* actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (actor == nullptr) {
        ExceptionList = nativeFrame.previousExceptionList;
        return 0;
    }
    uint noBone = (uint)this;
    nativeFrame.nameArgument = &noBone; // Reserved outgoing FName word at EBP-38.
    uint blendZeroArgument3 = 0; // EBP-3c/-40/-44 precede the FName overwrite.
    uint blendZeroArgument2 = 0;
    uint blendWeightArgument = 0x3f800000;
    noBone = 0;
    actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
    // Raw stack-word call views preserve float/name arguments without conversions.
    uint blendChannelArgument = 17; // EBP-48 follows the current actor read.
    reinterpret_cast<AActor*>(actor)->AActor::AnimBlendParams(blendChannelArgument,
        reinterpret_cast<float&>(blendWeightArgument), reinterpret_cast<float&>(blendZeroArgument2),
        reinterpret_cast<float&>(blendZeroArgument3), reinterpret_cast<FName&>(noBone));
    byte* sequence = reinterpret_cast<byte*&>(this->m_CurSequence);
    uint tweenWord = *(uint*)(sequence + 0x40);
    actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
    NativeActorControlVtable* vtable = *reinterpret_cast<NativeActorControlVtable**>(actor);
    uint playZeroArgument3 = 0; // EBP-38/-3c/-40/-44 precede the rate and name reads.
    uint playZeroArgument2 = 0;
    uint playZeroArgument1 = 0;
    uint playTweenArgument = tweenWord;
    uint rateWord = *(uint*)(sequence + 0x3c);
    uint sequenceName = *(uint*)(sequence + 0x50);
    using Play = void (__thiscall*)(byte*, uint, uint, uint, uint, uint, uint, uint);
    uint playRateArgument = rateWord;
    uint playNameArgument = sequenceName;
    uint playChannelArgument = 17;
    reinterpret_cast<Play&>(vtable->playAnimAddress)(actor, playChannelArgument, playNameArgument, playRateArgument,
        playTweenArgument, playZeroArgument1, playZeroArgument2, playZeroArgument3);
    if ((*(byte*)(action + 0x5c) & 1) != 0) {
        actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
        vtable = *reinterpret_cast<NativeActorControlVtable**>(actor);
        nativeFrame.floorX = 0;
        uint floorXArgument = nativeFrame.floorX; // EBP-40 precedes local floorY initialization.
        nativeFrame.floorY = 0;
        uint floorYArgument = nativeFrame.floorY; // EBP-3c.
        uint physicsExtraArgument = 0; // EBP-44 precedes local floorZ initialization.
        nativeFrame.floorZ = 0x3f800000;
        uint heldFloorZ = nativeFrame.floorZ;
        uint physicsModeArgument = 0x0c; // EBP-48 precedes the outgoing Z word.
        uint floorZArgument = heldFloorZ;
        using Physics = void (__thiscall*)(byte*, uint, uint, uint, uint, uint);
        reinterpret_cast<Physics&>(vtable->setPhysicsAddress)(
            actor, physicsModeArgument, physicsExtraArgument, floorXArgument, floorYArgument, floorZArgument);
        // Reload after the physics callback, without a new null check.
        actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
        *(uint*)(actor + 0xa8) &= ~0x1000u; // bCollideWorld.
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return 1;
}

// R6Engine.dll @ 100409e9 : AnimLaunchCatchPointer
// Copies the caught text at EBP-1c into the inherited EBP-14 rethrow slot.
__declspec(naked) __declspec(noreturn) void __cdecl AnimLaunchCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100409fd : AnimLaunchCatchContext
// Reports the native Update diagnostic retained by LaunchSequence, then forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimLaunchCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage1
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10040a20 : UR6SubActionAnimSequence::GetStatString
// Appends the action label to the base status text and constructs the caller's result.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FString* __thiscall UR6SubActionAnimSequence::GetStatString(FString* result)
{
    // Descriptive FPO frame: unwind EBP is entry ESP; result mask -28, base -24, label -18, output argument +4.
    struct StatusFrame {
        uint savedESI, resultConstructed, baseWords[3], labelWords[3];
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &StatusStringExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FString* baseText = (FString*)nativeFrame.baseWords;
    FString* labelText = (FString*)nativeFrame.labelWords;
    FString* baseResultArgument = baseText; // Outgoing word at entryESP-0x30, before mask initialization.
    nativeFrame.resultConstructed = 0;
    using BaseText = FString* (__thiscall*)(UMatSubAction*, FString*);
    reinterpret_cast<BaseText&>(UMatSubActionGetStatStringImport)(this, baseResultArgument);
    struct FormatPacketView { // Inferred outgoing words at entryESP-0x34 and entryESP-0x30.
        FString* result;
        const ushort* format;
    } formatPacket;
    formatPacket.format = nativeTextAnimSequence;
    formatPacket.result = labelText;
    nativeFrame.exceptionState = 1;
    using Printf = FString* (__cdecl*)(FString*, const ushort*);
    FString* printedLabel = reinterpret_cast<Printf&>(FStringPrintfImport)(formatPacket.result, formatPacket.format);
    *(byte*)&nativeFrame.exceptionState = 2;
    const ushort* characters = printedLabel->operator*();
    const ushort* appendArgument = characters; // Reuses the outgoing word at entryESP-0x30.
    baseText->operator+=(appendArgument);
    *(byte*)&nativeFrame.exceptionState = 1;
    labelText->FString::~FString();
    FString* completedResult = result; // Native loads the hidden output word after the label destructor.
    const FString* copyArgument = baseText; // Placed after the late hidden-result capture.
    ::new (completedResult) FString(*copyArgument);
    nativeFrame.resultConstructed = 1;
    *(byte*)&nativeFrame.exceptionState = 0;
    baseText->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
    return completedResult; // Explicit native hidden-result pointer/RET4 view of the exported FString return.
}

// R6Engine.dll @ 10040c60 : UR6SubActionAnimSequence::GetAnimation
// Finds the first matching half-open interval, resampling the percentage before each bound.
UR6PlayAnim* __thiscall UR6SubActionAnimSequence::GetAnimation(float positionPct)
{
    const NativeArrayHeader32* sequences = reinterpret_cast<const NativeArrayHeader32*>(&this->m_Sequences);
    int sequenceCount = sequences->count; // +0x70.
    if (sequenceCount <= 0)
        return nullptr;
    UR6PlayAnim** sequenceData = reinterpret_cast<UR6PlayAnim**>(sequences->dataAddress); // +0x6c.
    for (int sequenceIndex = 0; sequenceIndex < sequenceCount; ++sequenceIndex) {
        UR6PlayAnim* sequence = sequenceData[sequenceIndex];
        float10 positionAtBegin = (float10)positionPct;
        float10 beginPct = (float10)sequence->m_fBeginPct;
        if (positionAtBegin >= beginPct) {
            float10 positionAtEnd = (float10)positionPct; // Native reloads the incoming word for the second comparison.
            float10 endPct = (float10)sequence->m_fEndPct;
            if (positionAtEnd < endPct)
                return sequenceData[sequenceIndex]; // Native rereads the slot instead of returning the tested pointer.
        }
    }
    return nullptr;
}

// R6Engine.dll @ 10040cb0 : UR6SubActionAnimSequence::PctToFrameNumber
// Interpolates within strict frame boundaries using the native signed integer reciprocal scale.
float10 __thiscall UR6SubActionAnimSequence::PctToFrameNumber(UR6PlayAnim* sequence, float positionPct)
{
    // Descriptive frame: saved ESP EBP-2c, caught/scale EBP-18, rethrow EBP-20, index/begin EBP-14.
    struct PercentageFrame {
        uint savedEDI, savedESI, savedEBX, rethrowText, zeroOrNextFrame, scaleWord, indexOrBegin;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimPercentageExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    AActor* actor = this->m_AffectedActor;
    UMesh* mesh = actor->Mesh;
    uint* meshVtable = *(uint**)mesh;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    AActor* actorArgument = actor; // Outgoing word at EBP-0x30, before state0 and zero initialization.
    nativeFrame.exceptionState = 0;
    nativeFrame.zeroOrNextFrame = 0;
    using MeshInstance = UMeshInstance* (__thiscall*)(UMesh*, const AActor*);
    MeshInstance getInstance = reinterpret_cast<MeshInstance>(meshVtable[0x88 / 4]);
    byte* rawInstance = reinterpret_cast<byte*>(getInstance(mesh, actorArgument));
    byte* instance = nullptr;
    if (rawInstance != nullptr) {
        UClass* classCursor = reinterpret_cast<UObject*>(rawInstance)->Class;
        UClass* expectedClass = USkeletalMeshInstancePrivateStaticClassImport;
        while (classCursor != nullptr && classCursor != expectedClass)
            classCursor = classCursor->GetSuperClass();
        if (classCursor == expectedClass) instance = rawInstance;
    }
    UR6PlayAnim* currentSequence = sequence;
    uint sequenceName = reinterpret_cast<const uint&>(currentSequence->m_Sequence);
    // Native has no second null-instance guard.
    NativeAnimQueryVtable* instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
    using Animation = void* (__thiscall*)(byte*, uint);
    uint animationArgument = sequenceName; // Reuses EBP-0x30 before reading slot0xb0.
    Animation getAnimation = reinterpret_cast<Animation&>(instanceVtable->getAnimNamedAddress);
    void* animation = getAnimation(instance, animationArgument);
    instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
    using FrameCount = float10 (__thiscall*)(byte*, void*);
    void* frameCountArgument = animation; // Reuses EBP-0x30 after the current vtable reload.
    FrameCount getFrameCount = reinterpret_cast<FrameCount&>(instanceVtable->animGetFrameCountAddress);
    float10 exactFrameCount = getFrameCount(instance, frameCountArgument);
    // FST32 aliases EBP+8 without popping the live conversion operand.
    reinterpret_cast<float&>(sequence) = (float)exactFrameCount;
    long long convertedCount = TruncateX87ToSigned64(); // Consumes the existing ST0 operand.
    int maxPlayTime = currentSequence->m_MaxPlayTime;
    reinterpret_cast<int&>(sequence) = maxPlayTime;
    float10 exactMaximum = (float10)reinterpret_cast<int&>(sequence);
    int frameCount = (int)(uint)convertedCount;
    nativeFrame.scaleWord = 0;
    reinterpret_cast<float&>(sequence) = (float)((float10)nativeFloatOne / exactMaximum);
    if (frameCount != 0) {
        int integerScale = 1 - 1 / frameCount;
        reinterpret_cast<int&>(nativeFrame.scaleWord) = integerScale;
        reinterpret_cast<float&>(nativeFrame.scaleWord) = (float)(float10)reinterpret_cast<int&>(nativeFrame.scaleWord);
    }
    float10 fractionalFrame = (float10)reinterpret_cast<float&>(nativeFrame.zeroOrNextFrame);
    int frame = 0;
    for (;;) {
        nativeFrame.indexOrBegin = (uint)frame;
        if (frame >= maxPlayTime) break;
        reinterpret_cast<float&>(nativeFrame.indexOrBegin) =
            (float)((float10)reinterpret_cast<int&>(nativeFrame.indexOrBegin) *
            (float10)reinterpret_cast<float&>(sequence));
        float10 positionAtBegin = (float10)positionPct;
        float10 frameBegin = (float10)reinterpret_cast<float&>(nativeFrame.indexOrBegin);
        if (positionAtBegin > frameBegin) {
            nativeFrame.zeroOrNextFrame = (uint)frame + 1;
            float10 nextFrame = (float10)reinterpret_cast<int&>(nativeFrame.zeroOrNextFrame);
            float10 frameEnd = nextFrame * (float10)reinterpret_cast<float&>(sequence);
            if (frameEnd > (float10)positionPct) {
                fractionalFrame = (float10)positionPct; // Native first discards the retained ST0 result.
                fractionalFrame -= (float10)reinterpret_cast<float&>(nativeFrame.indexOrBegin);
                fractionalFrame /= (float10)reinterpret_cast<float&>(sequence);
                fractionalFrame *= (float10)reinterpret_cast<float&>(nativeFrame.scaleWord);
            }
        }
        ++frame;
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return fractionalFrame;
}

// R6Engine.dll @ 10040dc2 : AnimPercentageCatchPointer
// Copies caught text from EBP-18 into the inherited EBP-20 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimPercentageCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10040dd6 : AnimPercentageCatchContext
// Reports the native GetAnimation diagnostic and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimPercentageCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceGetAnimation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10040e10 : UR6SubActionAnimSequence::GetAnimDuration
// Caches the converted frame count and returns the unspilled rate-scaled duration through ST0.
float10 __thiscall UR6SubActionAnimSequence::GetAnimDuration(UR6PlayAnim* sequence)
{
    // Descriptive frame: saved ESP EBP-28, caught/rethrow EBP-1c/-18, float/count scratch EBP-14.
    struct DurationFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, countScratch;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimDurationExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    AActor* actor = this->m_AffectedActor;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (actor == nullptr) {
        void* previousChain = nativeFrame.previousExceptionList;
        float10 zero = (float10)nativeFloatZero;
        ExceptionList = previousChain;
        return zero;
    }
    byte* currentSequence = (byte*)sequence;
    if (currentSequence == nullptr) {
        void* previousChain = nativeFrame.previousExceptionList;
        float10 zero = (float10)nativeFloatZero;
        ExceptionList = previousChain;
        return zero;
    }
    UMesh* testedMesh = actor->Mesh;
    if (testedMesh == nullptr) {
        void* previousChain = nativeFrame.previousExceptionList;
        float10 zero = (float10)nativeFloatZero;
        ExceptionList = previousChain;
        return zero;
    }
    UMesh* mesh = actor->Mesh; // Native second mesh read precedes the virtual call.
    AActor* actorArgument = actor; // Outgoing EBP-2c precedes the current virtual-slot read.
    byte* rawInstance = reinterpret_cast<byte*>(mesh->MeshGetInstance(actorArgument));
    byte* instanceArgument = rawInstance; // Same outgoing word, now passed to the cdecl cast.
    byte* instance = (byte*)CastToUSkeletalMeshInstance((int)instanceArgument);
    if (instance == nullptr) {
        void* previousChain = nativeFrame.previousExceptionList;
        float10 zero = (float10)nativeFloatZero;
        ExceptionList = previousChain;
        return zero;
    }
    uint sequenceName = *(uint*)(currentSequence + 0x50);
    NativeAnimQueryVtable* instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
    using Animation = void* (__thiscall*)(byte*, uint);
    uint animationArgument = sequenceName;
    void* animation = reinterpret_cast<Animation&>(instanceVtable->getAnimNamedAddress)(instance, animationArgument);
    instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
    using AnimationNumber = float10 (__thiscall*)(byte*, void*);
    void* rateArgument = animation;
    float10 rateValue = reinterpret_cast<AnimationNumber&>(instanceVtable->animGetRateAddress)(instance, rateArgument);
    reinterpret_cast<float&>(sequence) = (float)rateValue; // FSTP32 overwrites the incoming sequence word at EBP+8.
    uint rateWord = reinterpret_cast<uint&>(sequence);
    instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
    void* frameCountArgument = animation; // Outgoing word is placed before the incoming rate mirror.
    // Retain the native whole-word mirror before the frame-count callback.
    reinterpret_cast<uint&>(sequence) = rateWord;
    float10 exactFrameCount = reinterpret_cast<AnimationNumber&>(instanceVtable->animGetFrameCountAddress)(
        instance, frameCountArgument);
    // FST32; the native ST0 operand stays unspilled.
    reinterpret_cast<float&>(nativeFrame.countScratch) = (float)exactFrameCount;
    // Descriptive live-ST0 view: this canonical helper consumes GetFrameCount's operand and returns EDX:EAX.
    long long convertedCount = TruncateX87ToSigned64();
    float10 sequenceRate = (float10)*(float*)(currentSequence + 0x3c);
    float10 zero = (float10)nativeFloatZero;
    float10 currentRate = (float10)reinterpret_cast<float&>(sequence);
    uint lowCountWord = (uint)convertedCount;
    nativeFrame.countScratch = lowCountWord; // Cached before FNSTSW overwrites AX.
    if (currentRate == zero) reinterpret_cast<uint&>(sequence) = 0x3f800000; // Ordered positive/negative zero only.
    float10 signedFrameCount = (float10)reinterpret_cast<int&>(nativeFrame.countScratch);
    *(uint*)(currentSequence + 0x34) = lowCountWord;
    float10 duration = signedFrameCount / (float10)reinterpret_cast<float&>(sequence);
    duration *= (float10)*(int*)(currentSequence + 0x2c); // Native FIMUL uses the signed integer maximum-play count.
    duration = sequenceRate * duration;
    ExceptionList = nativeFrame.previousExceptionList;
    return duration;
}

// R6Engine.dll @ 10040ef7 : AnimDurationCatchPointer
// Copies caught text from EBP-1c into the inherited EBP-18 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimDurationCatchPointer(void)
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

// R6Engine.dll @ 10040f0b : AnimDurationCatchContext
// Reports the native duration context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl AnimDurationCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceGetAnimDuration
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10040f40 : UR6SubActionAnimSequence::Update
// Advances the game action or formats and forces the editor's current animation pose.
int __thiscall UR6SubActionAnimSequence::Update(float scenePct, ASceneManager* sceneManager)
{
    // Descriptive frame: saved ESP EBP-30, preview string EBP-24, caught/rethrow EBP-18/-14.
    struct UpdateFrame {
        uint savedEDI, savedESI, savedEBX, previewWords[3], caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimUpdateExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    ASceneManager* manager = sceneManager; // Retained before EBP+0c becomes the displayed-frame scratch word.
    uint originalPctWord = reinterpret_cast<uint&>(scenePct);
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    ASceneManager* baseManagerArgument = manager; // EBP-34, before the full state-0 store.
    uint basePctArgument = originalPctWord; // EBP-38.
    nativeFrame.exceptionState = 0;
    int baseResult = this->UMatSubAction::Update(reinterpret_cast<const float&>(basePctArgument), baseManagerArgument);
    if (baseResult == 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return baseResult;
    }
    int* isEditor = *(int**)&CoreGIsEditorImport;
    if (*isEditor == 0) {
        uint* vtable = *(uint**)this;
        using UpdateGame = int (__thiscall*)(UR6SubActionAnimSequence*, uint, ASceneManager*);
        ASceneManager* gameManagerArgument = manager;
        uint gamePctArgument = originalPctWord;
        int result = ((UpdateGame)vtable[0x7c / 4])(this, gamePctArgument, gameManagerArgument);
        ExceptionList = nativeFrame.previousExceptionList;
        return result;
    }
    int running = this->IsRunning();
    if (running == 0 && (reinterpret_cast<byte&>(this->Status) != 3 ||
        (*reinterpret_cast<byte*>(reinterpret_cast<byte*>(this) + 0x5c) & 4U) != 0)) {
        ExceptionList = nativeFrame.previousExceptionList;
        return 1;
    }
    float10 position = (float10)scenePct - (float10)this->PctStarting;
    position /= (float10)this->PctDuration;
    scenePct = (float)position; // FST32 retains the extended operand used by the lower comparison.
    float10 lower = (float10)nativeFloat0Point0001;
    if (!(position >= lower)) {
        scenePct = nativeFloat0Point0001;
    } else {
        float10 retainedPosition = (float10)scenePct;
        float10 comparedPosition = (float10)scenePct;
        float10 upper = (float10)nativeFloatOne;
        if (comparedPosition <= upper) scenePct = (float)retainedPosition;
        else reinterpret_cast<uint&>(scenePct) = 0x3f800000;
    }
    uint positionWord = reinterpret_cast<uint&>(scenePct);
    UR6PlayAnim* selected = this->UR6SubActionAnimSequence::GetAnimation(reinterpret_cast<float&>(positionWord));
    this->m_CurSequence = selected;
    if (selected != nullptr) {
        scenePct = (float)this->UR6SubActionAnimSequence::GetCurAnimPct(reinterpret_cast<float&>(positionWord));
        uint sequencePctWord = reinterpret_cast<uint&>(scenePct);
        UR6PlayAnim* sequence = this->m_CurSequence;
        scenePct = (float)this->UR6SubActionAnimSequence::PctToFrameNumber(sequence,
            reinterpret_cast<float&>(sequencePctWord));
        uint framePctWord = reinterpret_cast<uint&>(scenePct);
        reinterpret_cast<uint&>(scenePct) = framePctWord;
        sequence = this->m_CurSequence;
        float10 frameNumber = (float10)sequence->m_iFrameNumber;
        FName* sequenceName = &sequence->m_Sequence;
        float10 displayed = frameNumber * (float10)scenePct;
        reinterpret_cast<float&>(sceneManager) = (float)displayed; // FSTP32 overwrites the incoming EBP+0c word.
        const ushort* nameText = sequenceName->operator*();
        double displayedArgument = (double)reinterpret_cast<float&>(sceneManager); // Reload after the name callback.
        FString* preview = (FString*)nativeFrame.previewWords;
        using Printf = FString* (__cdecl*)(FString*, const ushort*, const ushort*, double);
        reinterpret_cast<Printf&>(FStringPrintfImport)(preview, nativeTextAnimSFrameF, nameText, displayedArgument);
        FString* displayString = &manager->m_DisplayString;
        FString* appendArgument = preview; // EBP-34 is populated before the byte state-1 store.
        *(byte*)&nativeFrame.exceptionState = 1;
        displayString->operator+=(*appendArgument);
        AActor* actor = this->m_AffectedActor;
        UMesh* mesh = actor->Mesh;
        AActor* actorArgument = actor;
        byte* instance = reinterpret_cast<byte*>(mesh->MeshGetInstance(actorArgument));
        framePctWord = reinterpret_cast<uint&>(scenePct);
        NativeAnimQueryVtable* instanceVtable = *reinterpret_cast<NativeAnimQueryVtable**>(instance);
        uint poseZeroArgument3 = 0; // EBP-34/-38/-3c are prepared before current sequence reads.
        uint poseZeroArgument2 = 0;
        uint poseFrameArgument = framePctWord;
        sequence = this->m_CurSequence;
        uint currentSequenceName = reinterpret_cast<uint&>(sequence->m_Sequence);
        using ForcePose = int (__thiscall*)(byte*, uint, uint, uint, uint);
        uint poseNameArgument = currentSequenceName;
        reinterpret_cast<ForcePose&>(instanceVtable->animForcePoseAddress)(
            instance, poseNameArgument, poseFrameArgument, poseZeroArgument2, poseZeroArgument3);
        FString* destroyReceiver = preview;
        *(byte*)&nativeFrame.exceptionState = 0;
        destroyReceiver->FString::~FString();
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return 1;
}

// R6Engine.dll @ 100410e5 : AnimUpdateCatchPointer
// Copies caught text from EBP-18 into the inherited EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimUpdateCatchPointer(void)
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

// R6Engine.dll @ 10041120 : UR6SubActionAnimSequence::IncrementSequence
// Advances the wrapped index, selects the indexed sequence when below the count and sends SequenceChanged.
int __thiscall UR6SubActionAnimSequence::IncrementSequence(void)
{
    uint nextIndex = (uint)this->m_CurIndex; // +0x58.
    const NativeArrayHeader32* sequences = reinterpret_cast<const NativeArrayHeader32*>(&this->m_Sequences);
    int sequenceCount = sequences->count; // +0x70.
    ++nextIndex;
    this->m_CurIndex = (int)nextIndex;
    if ((int)nextIndex >= sequenceCount)
        return 0;
    uint sequenceDataAddress = sequences->dataAddress; // +0x6c.
    UR6PlayAnim* sequence = *reinterpret_cast<UR6PlayAnim**>(sequenceDataAddress + nextIndex * 4U);
    this->m_CurSequence = sequence; // +0x68.
    if (sequence == nullptr)
        return 0;
    FName eventName = R6ENGINE_SequenceChanged;
    byte* eventVtable = *(byte**)this;
    void* eventResultArgument = nullptr; // Entry ESP-0c/-10 precede the FindFunction packet.
    void* eventParametersArgument = nullptr;
    UFunction* eventFunction = this->UObject::FindFunctionChecked(eventName, 0);
    using ProcessEventCall = void (__thiscall *)(UR6SubActionAnimSequence*, UFunction*, void*, void*);
    ProcessEventCall dispatch = *(ProcessEventCall*)(eventVtable + 0x10);
    dispatch(this, eventFunction, eventParametersArgument, eventResultArgument);
    return 1;
}

// R6Engine.dll @ 10041170 : UR6SubActionAnimSequence::IsAnimAtFrame
// Returns one for an ordered channel frame at or above the signed integer threshold.
int __thiscall UR6SubActionAnimSequence::IsAnimAtFrame(int channelIndex, int frameThreshold)
{
    // Descriptive frame: saved ESP EBP-24, caught/rethrow EBP-18/-14; no local cleanup.
    struct ThresholdFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimThresholdExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    AActor* actor = this->m_AffectedActor;
    UMesh* mesh = actor->Mesh;
    uint* meshVtable = *(uint**)mesh;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    AActor* actorArgument = actor; // EBP-28 is populated before the full state-0 store.
    nativeFrame.exceptionState = 0;
    using MeshInstance = UMeshInstance* (__thiscall*)(UMesh*, const AActor*);
    byte* rawInstance = reinterpret_cast<byte*>(
        reinterpret_cast<MeshInstance>(meshVtable[0x88 / 4])(mesh, actorArgument));
    byte* instance = nullptr;
    if (rawInstance != nullptr) {
        UClass* classCursor = reinterpret_cast<UObject*>(rawInstance)->Class;
        UClass* expectedClass = USkeletalMeshInstancePrivateStaticClassImport;
        while (classCursor != nullptr && classCursor != expectedClass)
            classCursor = classCursor->GetSuperClass();
        if (classCursor == expectedClass) instance = rawInstance;
    }
    uint indexWord = (uint)channelIndex;
    float10 threshold = (float10)frameThreshold; // FILD preserves the full signed integer before the data read.
    uint channelData = *(uint*)(instance + 0x10c); // Native leaves cast failure and index unchecked.
    uint channelOffset = indexWord * 0x74U;
    uint channelFrameAddress = channelData + channelOffset + 0x10U;
    float10 channelFrame = (float10)*(float*)channelFrameAddress;
    int result = threshold <= channelFrame;
    ExceptionList = nativeFrame.previousExceptionList;
    return result;
}

// R6Engine.dll @ 10041218 : AnimThresholdCatchPointer
// Copies caught text from EBP-18 into the inherited EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimThresholdCatchPointer(void)
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

// R6Engine.dll @ 1004122c : AnimThresholdCatchContext
// Reports the native Update diagnostic and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimThresholdCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage3
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041380 : UR6SubActionAnimSequence::GetTotalLength
// Sums current sequence durations with an unspilled add and a float store after each iteration.
float __thiscall UR6SubActionAnimSequence::GetTotalLength(void)
{
    // Descriptive frame: saved ESP EBP-2c, caught/rethrow EBP-20/-1c, duration spill/total EBP-18/-14.
    struct TotalLengthFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        float durationSpill, total;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimTotalExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    reinterpret_cast<uint&>(nativeFrame.total) = 0;
    const NativeArrayHeader32* sequences = reinterpret_cast<const NativeArrayHeader32*>(&this->m_Sequences);
    int index = 0;
    while (index < sequences->count) {
        UR6PlayAnim** data = reinterpret_cast<UR6PlayAnim**>(sequences->dataAddress);
        UR6PlayAnim* sequence = data[index];
        float10 duration = this->UR6SubActionAnimSequence::GetAnimDuration(sequence);
        nativeFrame.durationSpill = (float)duration; // Native FST32 does not replace the value used by FADD.
        float10 sum = duration + (float10)nativeFrame.total;
        ++index;
        nativeFrame.total = (float)sum;
    }
    void* previousChain = nativeFrame.previousExceptionList;
    float result = nativeFrame.total;
    ExceptionList = previousChain;
    return result;
}

// R6Engine.dll @ 100413d2 : AnimTotalCatchPointer
// Copies caught text from EBP-20 into the inherited EBP-1c rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimTotalCatchPointer(void)
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

// R6Engine.dll @ 100413e6 : AnimTotalCatchContext
// Reports the native duration context and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl AnimTotalCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceGetTotalLength
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041420 : UR6SubActionAnimSequence::UpdateGame
// Starts, repeats, advances or finishes the current animation with the native blend and event order.
int __thiscall UR6SubActionAnimSequence::UpdateGame(float unusedScenePct, ASceneManager* unusedSceneManager)
{
    // Descriptive frame: saved ESP EBP-28, caught/rethrow EBP-1c/-14, outgoing FName pointer EBP-18.
    struct TransitionFrame {
        uint savedEDI, savedESI, savedEBX, caughtText;
        uint* nameArgument;
        uint rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimTransitionExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    byte* action = (byte*)this;
    uint* actionVtable = *(uint**)this;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    using IsRunning = int (__thiscall*)(UR6SubActionAnimSequence*);
    if (((IsRunning)actionVtable[0x6c / 4])(this) == 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return 1;
    }
    int sequenceCount = *(int*)(action + 0x70);
    if (sequenceCount <= 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return 1;
    }
    if ((action[0x5c] & 2U) != 0) {
        uint* data = *(uint**)(action + 0x6c);
        reinterpret_cast<uint&>(this->m_CurIndex) = 0;
        byte* sequence = (byte*)data[0];
        reinterpret_cast<byte*&>(this->m_CurSequence) = sequence;
        if (sequenceCount == 0 || sequence == nullptr) { // Native retains this branch after the positive-count gate.
            ExceptionList = nativeFrame.previousExceptionList;
            return 0;
        }
        *(uint*)(sequence + 0x30) = 0;
        uint flags = *(uint*)(action + 0x5c) & ~2U;
        *(uint*)(action + 0x5c) = flags;
        this->UR6SubActionAnimSequence::eventSequenceChanged();
        int result = this->UR6SubActionAnimSequence::LaunchSequence();
        ExceptionList = nativeFrame.previousExceptionList;
        return result;
    }
    byte* actor = reinterpret_cast<byte*&>(this->m_AffectedActor);
    NativeActorControlVtable* actorVtable = *reinterpret_cast<NativeActorControlVtable**>(actor);
    using CheckFinished = int (__thiscall*)(byte*, uint);
    uint finishedArgument = 17; // EBP-2c precedes the current virtual-slot read.
    int finished = reinterpret_cast<CheckFinished&>(actorVtable->checkAnimFinishedAddress)(actor, finishedArgument);
    if (finished != 0) {
        byte* sequence = reinterpret_cast<byte*&>(this->m_CurSequence);
        *(uint*)(sequence + 0x30) += 1U;
        sequence = reinterpret_cast<byte*&>(this->m_CurSequence);
        int played = *(int*)(sequence + 0x30);
        int maximum = *(int*)(sequence + 0x2c);
        if (played < maximum || (sequence[0x38] & 1U) != 0) {
            this->UR6SubActionAnimSequence::LaunchSequence(); // Repeat ignores the launch result and returns one.
        } else {
            // Descriptive local operation for the native by-value FName word and five raw blend arguments.
            auto clearBlend = [&]() {
                uint noBone; // Native PUSH ECX reserves EBP-2c; overwritten below.
                nativeFrame.nameArgument = &noBone;
                uint zeroArgument3 = 0; // EBP-30/-34/-38 precede the FName overwrite.
                uint zeroArgument2 = 0;
                uint zeroArgument1 = 0;
                noBone = 0;
                byte* currentActor = reinterpret_cast<byte*&>(this->m_AffectedActor);
                uint blendArgument = 17; // EBP-3c follows the current actor read.
                reinterpret_cast<AActor*>(currentActor)->AActor::AnimBlendParams(blendArgument,
                    reinterpret_cast<float&>(zeroArgument1), reinterpret_cast<float&>(zeroArgument2),
                    reinterpret_cast<float&>(zeroArgument3), reinterpret_cast<FName&>(noBone));
            };
            int advanced = this->UR6SubActionAnimSequence::IncrementSequence();
            if (advanced == 1) {
                clearBlend();
                int result = this->UR6SubActionAnimSequence::LaunchSequence();
                ExceptionList = nativeFrame.previousExceptionList;
                return result;
            }
            if ((action[0x5c] & 4U) != 0) clearBlend();
            this->UR6SubActionAnimSequence::eventSequenceFinished();
            uint flags = *(uint*)(action + 0x5c) | 2U;
            reinterpret_cast<byte&>(this->Status) = 3;
            *(uint*)(action + 0x5c) = flags;
        }
    }
    ExceptionList = nativeFrame.previousExceptionList;
    return 1;
}

// R6Engine.dll @ 10041577 : AnimTransitionCatchPointer
// Copies caught text from EBP-1c into the inherited EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimTransitionCatchPointer(void)
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

// R6Engine.dll @ 1004158b : AnimTransitionCatchContext
// Reports the native UpdateGame context, clears EDI and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimTransitionCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceUpdateGame
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100415b0 : UR6SubActionAnimSequence::PreBeginPreview
// Sets duration and sequence intervals, retaining each unspilled end percentage for the next beginning.
void __thiscall UR6SubActionAnimSequence::PreBeginPreview(void)
{
    // Descriptive frame: saved ESP EBP-30, caught/rethrow EBP-24/-20, total/duration/sum EBP-1c/-18/-14.
    struct PreviewFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        float total, durationSpill, sum;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &AnimPreviewExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    int initialCount = reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).count;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    nativeFrame.exceptionState = 0;
    if (initialCount == 0) {
        ExceptionList = nativeFrame.previousExceptionList;
        return;
    }
    UR6PlayAnim** data = reinterpret_cast<UR6PlayAnim**>(
        reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).dataAddress);
    UR6PlayAnim* firstSequence = data[0];
    this->m_CurSequence = firstSequence;
    float10 totalLength = (float10)this->UR6SubActionAnimSequence::GetTotalLength();
    nativeFrame.sum = (float)totalLength; // First FST32 does not pop the duration operand.
    nativeFrame.total = (float)totalLength;
    reinterpret_cast<uint&>(nativeFrame.sum) = 0;
    this->Duration = (float)totalLength;
    int index = 0;
    float10 previousEnd = (float10)nativeFloatZero;
    while (index < reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).count) {
        data = reinterpret_cast<UR6PlayAnim**>(reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).dataAddress);
        UR6PlayAnim* sequence = data[index];
        if (sequence == nullptr) break;
        sequence->m_fBeginPct = (float)previousEnd; // FSTP32 consumes the retained end value.
        data = reinterpret_cast<UR6PlayAnim**>(reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).dataAddress);
        sequence = data[index];
        float10 duration = this->UR6SubActionAnimSequence::GetAnimDuration(sequence);
        nativeFrame.durationSpill = (float)duration; // FST32 retains the value used by FADD.
        float10 accumulated = duration + (float10)nativeFrame.sum;
        data = reinterpret_cast<UR6PlayAnim**>(reinterpret_cast<NativeArrayHeader32&>(this->m_Sequences).dataAddress);
        UR6PlayAnim* endSequence = data[index];
        ++index;
        nativeFrame.sum = (float)accumulated;
        previousEnd = accumulated / (float10)nativeFrame.total;
        endSequence->m_fEndPct = (float)previousEnd; // FST32 leaves ST0 for the following iteration.
    }
    // Native FSTP discards the final retained percentage before restoring the exception chain.
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10041648 : AnimPreviewCatchPointer
// Copies caught text from EBP-24 into the inherited EBP-20 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl AnimPreviewCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x20]
        push edx
        mov dword ptr [ebp-0x20],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004165c : AnimPreviewCatchContext
// Reports the native PreBeginPreview context and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimPreviewCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequencePreBeginPreview
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100439b0 : AnimSequenceDtorState0Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl AnimSequenceDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UMatSubActionDestructorImport]
    }
}

// R6Engine.dll @ 100439b9 : AnimSequenceDtorState1Cleanup
// Destroys the pending base/member subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl AnimSequenceDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100454e0 : AnimUpdateState1Cleanup
// Destroys Update's constructed preview text through the inherited EBP-24 binding.
__declspec(naked) void __cdecl AnimUpdateState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100410f9 : AnimUpdateCatchContext
// Reports the native Update diagnostic and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl AnimUpdateCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAnimSequenceUpdateUR6SubActionAnimSequenceStorage2
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10047d30 : InitializeUR6SubActionAnimSequenceClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeUR6SubActionAnimSequenceClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = UMatSubActionPrivateStaticClassImport;
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
    packet.internalConstructor = &UR6SubActionAnimSequence::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload saved words after the configuration callback.
    parentClass = captures.parentClass;
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6SubActionAnimSequence;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x78;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&UR6SubActionAnimSequence::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyUR6SubActionAnimSequenceClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100481e0 : DestroyUR6SubActionAnimSequenceClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyUR6SubActionAnimSequenceClassMetadata(void)
{
    __asm {
        mov ecx,offset UR6SubActionAnimSequence::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047dc0 : PublishUR6SubActionAnimSequenceAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishUR6SubActionAnimSequenceAutoClass(void)
{
    autoclassUR6SubActionAnimSequence = &UR6SubActionAnimSequence::PrivateStaticClass;
}

// R6Engine.dll @ 100439c4 : UR6SubActionAnimSequenceDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl UR6SubActionAnimSequenceDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset animSequenceDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045460 : AnimLaunchExceptionHandler
// Selects the exact launch FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl AnimLaunchExceptionHandler(void)
{
    __asm {
        mov eax,offset animLaunchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100454d0 : AnimDurationExceptionHandler
// Selects the exact duration FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl AnimDurationExceptionHandler(void)
{
    __asm {
        mov eax,offset animDurationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045520 : AnimTotalExceptionHandler
// Selects the exact duration FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl AnimTotalExceptionHandler(void)
{
    __asm {
        mov eax,offset animTotalFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100454c0 : AnimPercentageExceptionHandler
// Selects the percentage converter's exact C++ exception metadata.
__declspec(naked) void __cdecl AnimPercentageExceptionHandler(void)
{
    __asm {
        mov eax,offset animPercentageFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100454e9 : AnimUpdateExceptionHandler
// Selects Update's exact C++ exception metadata and preview cleanup state.
__declspec(naked) void __cdecl AnimUpdateExceptionHandler(void)
{
    __asm {
        mov eax,offset animUpdateFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045500 : AnimThresholdExceptionHandler
// Selects the channel threshold method's exact C++ exception metadata.
__declspec(naked) void __cdecl AnimThresholdExceptionHandler(void)
{
    __asm {
        mov eax,offset animThresholdFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045530 : AnimTransitionExceptionHandler
// Selects the game animation transition method's exact C++ exception metadata.
__declspec(naked) void __cdecl AnimTransitionExceptionHandler(void)
{
    __asm {
        mov eax,offset animTransitionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045540 : AnimPreviewExceptionHandler
// Selects preview initialization's exact C++ exception metadata.
__declspec(naked) void __cdecl AnimPreviewExceptionHandler(void)
{
    __asm {
        mov eax,offset animPreviewFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10013890 : UR6SubActionAnimSequence::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall UR6SubActionAnimSequence::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&UR6SubActionAnimSequenceDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x78;
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
    this->UR6SubActionAnimSequence::~UR6SubActionAnimSequence();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x78;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll @ 10024530 : CastToUSkeletalMeshInstance
// Returns the original object word for an imported skeletal-instance class match or a null required class.
int __cdecl CastToUSkeletalMeshInstance(int object)
{
    if (object == 0)
        return 0;
    UClass* type = reinterpret_cast<UObject*>(static_cast<uint>(object))->Class;
    // Class is read before the imported required class.
    UClass* required = USkeletalMeshInstancePrivateStaticClassImport;
    while (type != nullptr) {
        if (type == required)
            return object;
        type = type->GetSuperClass();
    }
    return required == nullptr ? object : 0;
}
