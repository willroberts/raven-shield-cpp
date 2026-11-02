#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl TerroristMgrNearestExceptionHandler(void);
__declspec(naked) void __cdecl TerroristMgrInitExceptionHandler(void);
__declspec(naked) void __cdecl DestroyUR6TerroristMgrClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// External native storage views; names describe roles rather than recovered original identifiers.
// R6Engine.dll data @ 10074554 : nativeKillChartDefaults
// Twelve native default chart words,read in forward copy order.
extern uint nativeKillChartDefaults[12];

// R6Engine.dll data @ 1004cb90 : UR6TerroristMgrVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: UR6TerroristMgr::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix UR6TerroristMgrVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005597e : nativeTextR6TerroristMgr
extern const ushort nativeTextR6TerroristMgr[15];

// R6Engine.dll data @ 10056048 : nativeTextUR6TerroristMgrExecFindNearestHostageAndTerroristZone
extern const ushort nativeTextUR6TerroristMgrExecFindNearestHostageAndTerroristZone[56];

// R6Engine.dll data @ 100560b8 : nativeTextUR6TerroristMgrExecInit
extern const ushort nativeTextUR6TerroristMgrExecInit[26];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl TerroristMgrCopyExceptionHandler(void);
__declspec(naked) void __cdecl TerroristMgrCopyState0Cleanup(void);
__declspec(naked) void __cdecl TerroristMgrDestructionExceptionHandler(void);
__declspec(naked) void __cdecl TerroristMgrDtorState0Cleanup(void);
__declspec(naked) void __cdecl TerroristMgrDtorState1Cleanup(void);
__declspec(naked) void __cdecl TerroristMgrDtorState2Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrInitCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrNearestCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrNearestCatchPointer(void);

// R6Engine.dll data @ 1005ed8c : terroristMgrInitUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry terroristMgrInitUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ed9c : terroristMgrInitCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry terroristMgrInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&TerroristMgrInitCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristMgrInitCatchContext) }
};

// R6Engine.dll data @ 1005edbc : terroristMgrInitTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock terroristMgrInitTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristMgrInitCatchMap) }
};

// R6Engine.dll data @ 1005edd0 : terroristMgrInitFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix terroristMgrInitFuncInfo = { 0x19930520, 0x2, ((uint)&terroristMgrInitUnwindMap), 0x1,
    ((uint)&terroristMgrInitTryMap), 0 };

// R6Engine.dll data @ 1005ed2c : terroristMgrNearestUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry terroristMgrNearestUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ed3c : terroristMgrNearestCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry terroristMgrNearestCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&TerroristMgrNearestCatchPointer) },
    { 0, 0, 0, ((uint)&TerroristMgrNearestCatchContext) }
};

// R6Engine.dll data @ 1005ed5c : terroristMgrNearestTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock terroristMgrNearestTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&terroristMgrNearestCatchMap) }
};

// R6Engine.dll data @ 1005ed70 : terroristMgrNearestFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix terroristMgrNearestFuncInfo = { 0x19930520, 0x2, ((uint)&terroristMgrNearestUnwindMap),
    0x1, ((uint)&terroristMgrNearestTryMap), 0 };

// R6Engine.dll data @ 10057e10 : terroristMgrDtorUnwind
// Retains exact pending base/array cleanup states without catches.
const NativeUnwindEntry terroristMgrDtorUnwind[3] = {
    { -1, ((uint)&TerroristMgrDtorState0Cleanup) },
    { 0, ((uint)&TerroristMgrDtorState1Cleanup) },
    { -1, ((uint)&TerroristMgrDtorState2Cleanup) }
};

// R6Engine.dll data @ 10057e28 : terroristMgrDtorInfo
// Retains exact pending base/array cleanup states without catches.
const NativeFunctionInfoPrefix terroristMgrDtorInfo = { 0x19930520, 0x3, ((uint)&terroristMgrDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10057e44 : terroristMgrCopyUnwind
// Retains exact pending base/array cleanup states without catches.
const NativeUnwindEntry terroristMgrCopyUnwind[1] = {
    { -1, ((uint)&TerroristMgrCopyState0Cleanup) }
};

// R6Engine.dll data @ 10057e4c : terroristMgrCopyInfo
// Retains exact pending base/array cleanup states without catches.
const NativeFunctionInfoPrefix terroristMgrCopyInfo = { 0x19930520, 0x1, ((uint)&terroristMgrCopyUnwind), 0, 0, 0 };

// R6Engine.dll data @ 100743f0 : intUR6TerroristMgrexecFindNearestZoneForHostage
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intUR6TerroristMgrexecFindNearestZoneForHostage =
    (Native)&UR6TerroristMgr::execFindNearestZoneForHostage;

// R6Engine.dll data @ 1007ee7c : UR6TerroristMgrFindNearestZoneForHostageRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte UR6TerroristMgrFindNearestZoneForHostageRegistrationResult = 0;

// R6Engine.dll data @ 100743f4 : intUR6TerroristMgrexecInit
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intUR6TerroristMgrexecInit = (Native)&UR6TerroristMgr::execInit;

// R6Engine.dll data @ 1007d9f6 : UR6TerroristMgrInitRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte UR6TerroristMgrInitRegistrationResult = 0;

// R6Engine.dll data @ 1007cfa8 : autoclassUR6TerroristMgr
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassUR6TerroristMgr = nullptr;

// R6Engine.dll @ 1000a7d0 : UR6TerroristMgr::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl UR6TerroristMgr::StaticClass(void)
{
    return &UR6TerroristMgr::PrivateStaticClass; // Selected object at0x10078830.
}

// R6Engine.dll @ 1000a7e0 : UR6TerroristMgr::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl UR6TerroristMgr::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&UR6TerroristMgr::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100109d0 : UR6TerroristMgr::~UR6TerroristMgr
// Releases deployment-zone storage and runs the abstract manager's inlined base cleanup.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall UR6TerroristMgr::~UR6TerroristMgr(UR6TerroristMgr* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristMgrDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&UR6TerroristMgrVirtualTable);
    using ConditionalDestroyCall = int (__thiscall *)(UObject*);
    ConditionalDestroyCall conditionalDestroy =
        reinterpret_cast<ConditionalDestroyCall&>(UObjectConditionalDestroyImport);
    guard[3] = 1;
    conditionalDestroy(this);
    *(byte*)&guard[3] = 0;
    DestroyWordArrayStorage((FArray*)&this->m_aDeploymentZoneWithHostage); // +0x34.
    // UR6AbstractTerroristMgr vtable imported from Engine.dll.
    *(uint*)this = reinterpret_cast<const uint&>(UR6AbstractTerroristMgrVtableImport);
    guard[3] = 2;
    conditionalDestroy(this);
    guard[3] = 0xffffffff;
    this->UObject::~UObject();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10010a50 : UR6TerroristMgr::UR6TerroristMgr
// Copies group counters, deployment-zone storage and sixteen hostage records.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
UR6TerroristMgr* __thiscall UR6TerroristMgr::UR6TerroristMgr(UR6TerroristMgr* this, const UR6TerroristMgr* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristMgrCopyExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    UObject::UObject(this, source);
    *(uint*)this = ((uint)&UR6TerroristMgrVirtualTable);
    this->m_iCurrentMax = source->m_iCurrentMax;
    this->m_iCurrentGroupID = source->m_iCurrentGroupID;
    guard[3] = 0;
    CopyConstructRecords4((FArray*)&this->m_aDeploymentZoneWithHostage,
        (const FArray*)&source->m_aDeploymentZoneWithHostage);
    uint* destinationWords = (uint*)&this->m_ArrayHostage;
    const uint* sourceWords = (const uint*)&source->m_ArrayHostage;
    __asm { // Exact REP view preserves the incoming direction flag, including overlapping storage behavior.
        push esi
        push edi
        mov esi,sourceWords
        mov edi,destinationWords
        mov ecx,48
        rep movsd
        pop edi
        pop esi
    }
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10010ad0 : UR6TerroristMgr::operator=
// Copies group counters, deployment-zone storage and sixteen hostage records.
UR6TerroristMgr& __thiscall UR6TerroristMgr::operator=(const UR6TerroristMgr& sourceObject)
{
    const UR6TerroristMgr* source = &sourceObject;
    UObject::operator=(*source);
    this->m_iCurrentMax = source->m_iCurrentMax;
    this->m_iCurrentGroupID = source->m_iCurrentGroupID;
    AssignRecords4((FArray*)&this->m_aDeploymentZoneWithHostage,
        (const FArray*)&source->m_aDeploymentZoneWithHostage);
    for (uint hostageIndex = 0; hostageIndex < 16U; ++hostageIndex) {
        uint* destinationWords = (uint*)&this->m_ArrayHostage[hostageIndex];
        const uint* sourceWords = (const uint*)&source->m_ArrayHostage[hostageIndex];
        destinationWords[0] = sourceWords[0];
        destinationWords[1] = sourceWords[1];
        destinationWords[2] = sourceWords[2];
    }
    return *this;
}

// R6Engine.dll @ 100138f0 : UR6TerroristMgr::UR6TerroristMgr (native default view)
// Constructs UObject and publishes the derived vtable, leaving counters, array header and hostage records untouched.
// The emitted call targets UObject; the intermediate C++ initializer structure remains unresolved.
UR6TerroristMgr* __thiscall UR6TerroristMgr::UR6TerroristMgr(UR6TerroristMgr* this)
{
    UObject::UObject(this);
    *(uint*)this = ((uint)&UR6TerroristMgrVirtualTable);
    return this;
}

// R6Engine.dll @ 10013b00 : UR6TerroristMgr::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl UR6TerroristMgr::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp UR6TerroristMgrConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10042020 : UR6TerroristMgr::execFindNearestZoneForHostage
// Selects the nearest eligible zone, falling back to the decoded terrorist's deployment zone.
// Native ABI view retains the incoming frame word for the closest-distance float spill.
void __thiscall UR6TerroristMgr::execFindNearestZoneForHostage(FFrame* stack, void* result)
{
    // Descriptive frame: saved ESP EBP-2c, caught/rethrow EBP-20/-1c, manager/terrorist EBP-18/-14.
    struct NearestFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        UR6TerroristMgr* manager;
        AR6Terrorist* terrorist;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TerroristMgrNearestExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = stack;
    byte* code = frame->Code;
    nativeFrame.terrorist = nullptr;
    uint token = *code;
    frame->Code = code + 1;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    nativeFrame.manager = this;
    UObject* receiver = frame->Object;
    nativeFrame.exceptionState = 0;
    natives[token](receiver, frame, &nativeFrame.terrorist);
    code = frame->Code + 1;
    frame->Code = code;
    if (*code == 0x42) {
        receiver = frame->Object;
        frame->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, frame, nullptr);
    }
    byte* terrorist = (byte*)nativeFrame.terrorist;
    byte* nearest = nullptr;
    int index = 0;
    for (;;) {
        byte* manager = (byte*)nativeFrame.manager;
        if (index >= *(int*)(manager + 0x38)) break;
        byte** zones = *(byte***)(manager + 0x34);
        byte* zone = zones[index];
        int eligible = reinterpret_cast<AR6DeploymentZone*>(zone)->AR6DeploymentZone::HaveTerrorist();
        terrorist = (byte*)nativeFrame.terrorist; // Reloaded even for an ineligible zone.
        if (eligible != 0) {
            bool firstCandidate = nearest == nullptr;
            float10 deltaX = (float10)*(float*)(zone + 0x234) - (float10)*(float*)(terrorist + 0x234);
            float10 deltaY = (float10)*(float*)(zone + 0x238) - (float10)*(float*)(terrorist + 0x238);
            float10 deltaZ = (float10)*(float*)(zone + 0x23c) - (float10)*(float*)(terrorist + 0x23c);
            float10 squareZ = deltaZ * deltaZ;
            float10 squareY = deltaY * deltaY;
            float10 distanceSquared = squareZ + squareY;
            float10 squareX = deltaX * deltaX;
            distanceSquared += squareX;
            if (firstCandidate || distanceSquared < (float10)reinterpret_cast<float&>(stack)) {
                // FSTP32 reuses the incoming FFrame word at EBP+8.
                reinterpret_cast<float&>(stack) = (float)distanceSquared;
                nearest = zone;
            }
        }
        ++index;
    }
    if (nearest == nullptr) nearest = *(byte**)(terrorist + 0xa58);
    *(byte**)result = nearest;
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10042124 : TerroristMgrNearestCatchPointer
// Copies caught text from EBP-20 into the inherited EBP-1c rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrNearestCatchPointer(void)
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

// R6Engine.dll @ 10042138 : TerroristMgrNearestCatchContext
// Reports the native nearest-hostage-and-terrorist-zone context and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrNearestCatchContext(void)
{
    __asm {
        push offset nativeTextUR6TerroristMgrExecFindNearestHostageAndTerroristZone
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10042160 : UR6TerroristMgr::execInit
// Appends eligible deployment zones, then resets current zoom scalars and copies the kill-chart defaults.
// Native ABI view retains the incoming frame word for the retained level pointer.
void __thiscall UR6TerroristMgr::execInit(FFrame* stack, void* unusedResult)
{
    // Descriptive frame: saved ESP EBP-2c, caught/rethrow EBP-20/-1c, manager/actor EBP-18/-14.
    struct InitFrame {
        uint savedEDI, savedESI, savedEBX, caughtText, rethrowText;
        UR6TerroristMgr* manager;
        AActor* actor;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &TerroristMgrInitExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = stack;
    byte* code = frame->Code;
    nativeFrame.actor = nullptr;
    uint token = *code;
    frame->Code = code + 1;
    nativeFrame.savedEsp = &nativeFrame.savedEDI;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    nativeFrame.manager = this;
    UObject* receiver = frame->Object;
    nativeFrame.exceptionState = 0;
    natives[token](receiver, frame, &nativeFrame.actor);
    code = frame->Code + 1;
    frame->Code = code;
    if (*code == 0x42) {
        receiver = frame->Object;
        frame->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, frame, nullptr);
    }
    byte* actor = (byte*)nativeFrame.actor;
    byte* level = *(byte**)(actor + 0x328);
    *(byte**)&stack = level; // The incoming FFrame word at EBP+8 becomes the retained level slot.
    for (int index = 0; index < *(int*)(level + 0x104); ++index) {
        byte** actors = *(byte***)(level + 0x30);
        actor = actors[index];
        if (actor == nullptr) continue;
        byte* actorClass = *(byte**)(actor + 0x24);
        while (actorClass != nullptr && actorClass != (byte*)&AR6DeploymentZone::PrivateStaticClass)
            actorClass = *(byte**)(actorClass + 0x2c);
        if (actorClass != (byte*)&AR6DeploymentZone::PrivateStaticClass) continue;
        if (actor != nullptr && *(uint*)(actor + 0x3a4) != 0 &&
            (*(uint*)(actor + 0x3d0) != 0 || *(uint*)(actor + 0x3b0) != 0)) {
            FArray* zones = (FArray*)((byte*)nativeFrame.manager + 0x34);
            int addedIndex = zones->FArray::Add(1, 4);
            uint dataAddress = *(uint*)zones;
            *(byte**)(dataAddress + (uint)addedIndex * 4U) = actor;
            level = *(byte**)&stack; // Reload only after an append callback and the resulting element store.
        }
    }
    uint* zoom = *(uint**)&CoreGZoomAdjustmentImport;
    *zoom = 0x3f800000;
    zoom = *(uint**)&CoreGZoomAdjustmentSniperZoomImport;
    *zoom = 0x3dcccccd;
    zoom = *(uint**)&CoreGZoomAdjustmentSniperNoZoomImport;
    *zoom = 0x3e4ccccd;
    zoom = *(uint**)&CoreGZoomAdjustmentSniperModeImport;
    *zoom = 0x3eb33333;
    const uint* defaults = (const uint*)&nativeKillChartDefaults;
    uint* killChart = (uint*)&R6Charts::m_stKillChart;
    for (int index = 0; index < 12; ++index) killChart[index] = defaults[index]; // Forward REP MOVSD order.
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10042292 : TerroristMgrInitCatchPointer
// Copies caught text from EBP-20 into the inherited EBP-1c rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrInitCatchPointer(void)
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

// R6Engine.dll @ 100422a6 : TerroristMgrInitCatchContext
// Reports the native Init context and forwards the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl TerroristMgrInitCatchContext(void)
{
    __asm {
        push offset nativeTextUR6TerroristMgrExecInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043550 : TerroristMgrDtorState0Cleanup
// Destroys the pending base subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UR6AbstractTerroristMgrDestructorImport]
    }
}

// R6Engine.dll @ 10043559 : TerroristMgrDtorState1Cleanup
// Destroys the pending deployment-zone array through the inherited dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x34
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043564 : TerroristMgrDtorState2Cleanup
// Destroys the pending base subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrDtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UObjectDestructorImport]
    }
}

// R6Engine.dll @ 10043580 : TerroristMgrCopyState0Cleanup
// Destroys the pending base subobject through the inherited dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UR6AbstractTerroristMgrDestructorImport]
    }
}

// R6Engine.dll @ 10046cc0 : InitializeUR6TerroristMgrClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeUR6TerroristMgrClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // Capture the imported UR6AbstractTerroristMgr object address before configuration lookup.
    UClass* parentClass = UR6AbstractTerroristMgrPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&UR6TerroristMgr::PrivateStaticClass, 0, 0x100, 0,
        parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6TerroristMgr, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &UR6TerroristMgr::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyUR6TerroristMgrClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048150 : DestroyUR6TerroristMgrClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyUR6TerroristMgrClassMetadata(void)
{
    __asm {
        mov ecx,offset UR6TerroristMgr::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046d50 : PublishUR6TerroristMgrAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishUR6TerroristMgrAutoClass(void)
{
    autoclassUR6TerroristMgr = &UR6TerroristMgr::PrivateStaticClass;
}

// R6Engine.dll @ 10047260 : RegisterUR6TerroristMgrFindNearestZoneForHostageNative
// Registers native index0x722 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterUR6TerroristMgrFindNearestZoneForHostageNative(void)
{
    UR6TerroristMgrFindNearestZoneForHostageRegistrationResult =
        GRegisterNative(0x722, intUR6TerroristMgrexecFindNearestZoneForHostage);
}

// R6Engine.dll @ 10047280 : RegisterUR6TerroristMgrInitNative
// Registers native index0x721 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterUR6TerroristMgrInitNative(void)
{
    UR6TerroristMgrInitRegistrationResult = GRegisterNative(0x721, intUR6TerroristMgrexecInit);
}

// R6Engine.dll @ 1004356d : TerroristMgrDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristMgrDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043589 : TerroristMgrCopyExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl TerroristMgrCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristMgrCopyInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100455c0 : TerroristMgrNearestExceptionHandler
// Selects the nearest-zone script bridge's exact C++ exception metadata.
__declspec(naked) void __cdecl TerroristMgrNearestExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristMgrNearestFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100455d0 : TerroristMgrInitExceptionHandler
// Selects the manager initialization script bridge's exact C++ exception metadata.
__declspec(naked) void __cdecl TerroristMgrInitExceptionHandler(void)
{
    __asm {
        mov eax,offset terroristMgrInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10010b30 : UR6TerroristMgr::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall UR6TerroristMgr::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&UR6TerroristMgrDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x100;
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
    this->UR6TerroristMgr::~UR6TerroristMgr();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x100;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
