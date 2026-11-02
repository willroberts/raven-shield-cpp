#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_text_data.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall AssignDamageStateArray(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructDamageStateArray(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl DestroyAR6InteractiveObjectClassMetadata(void);
void __thiscall DestroyDamageState(void* damageState);
void* __thiscall CopyConstructDamageState(void* destination, const void* source);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
__declspec(naked) void __thiscall ForwardDamageStateArrayDestruction(FArray* array);

// R6Engine.dll data @ 1004de90 : AR6InteractiveObjectVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6InteractiveObject::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6InteractiveObjectVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100507a8 : nativeTextAR6InteractiveObjectPostNetReceive
extern const ushort nativeTextAR6InteractiveObjectPostNetReceive[37];

// R6Engine.dll data @ 100506e8 : nativeTextAR6InteractiveObjectPreNetReceive
extern const ushort nativeTextAR6InteractiveObjectPreNetReceive[36];

// R6Engine.dll data @ 10050698 : nativeTextAR6InteractiveObjectRenderEditorInfo
extern const ushort nativeTextAR6InteractiveObjectRenderEditorInfo[39];

// R6Engine.dll data @ 10050650 : nativeTextAR6InteractiveObjectShouldTrace
extern const ushort nativeTextAR6InteractiveObjectShouldTrace[34];

// R6Engine.dll data @ 100507f8 : nativeTextInvalidTagSInMStateListDActorListD
extern const ushort nativeTextInvalidTagSInMStateListDActorListD[50];

// R6Engine.dll data @ 10055902 : nativeTextR6InteractiveObject
extern const ushort nativeTextR6InteractiveObject[20];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl InteractiveCopyState0Cleanup(void);
__declspec(naked) void __cdecl InteractiveCopyState1Cleanup(void);
__declspec(naked) void __cdecl InteractiveCopyState2Cleanup(void);
__declspec(naked) void __cdecl InteractiveCopyState3Cleanup(void);
__declspec(naked) void __cdecl InteractiveDestructionState0Cleanup(void);
__declspec(naked) void __cdecl InteractiveDestructionState1Cleanup(void);
__declspec(naked) void __cdecl InteractiveDestructionState2Cleanup(void);
__declspec(naked) void __cdecl InteractiveDestructionState3Cleanup(void);
__declspec(naked) void __cdecl InteractiveDestructionState4Cleanup(void);
__declspec(naked) void __cdecl InteractiveObjectCheckErrorsState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPostNetCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPostNetCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPreNetCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPreNetCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectRenderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectRenderCatchPointer(void);
__declspec(naked) void __cdecl InteractiveObjectRenderState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectTraceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectTraceCatchPointer(void);

// R6Engine.dll data @ 1005a19c : interactiveObjectPostNetUnwindMap
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeUnwindEntry interactiveObjectPostNetUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a1ac : interactiveObjectPostNetCatchMap
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeCatchEntry interactiveObjectPostNetCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&InteractiveObjectPostNetCatchPointer) },
    { 0, 0, 0, ((uint)&InteractiveObjectPostNetCatchContext) }
};

// R6Engine.dll data @ 1005a1cc : interactiveObjectPostNetTryMap
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeTryBlock interactiveObjectPostNetTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&interactiveObjectPostNetCatchMap) }
};

// R6Engine.dll data @ 1005a1e0 : interactiveObjectPostNetFuncInfo
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeFunctionInfoPrefix interactiveObjectPostNetFuncInfo = { 0x19930520, 0x2,
    ((uint)&interactiveObjectPostNetUnwindMap), 0x1, ((uint)&interactiveObjectPostNetTryMap), 0 };

// R6Engine.dll data @ 1005a1fc : interactiveObjectCheckErrorsUnwindMap
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeUnwindEntry interactiveObjectCheckErrorsUnwindMap[1] = {
    { -1, ((uint)&InteractiveObjectCheckErrorsState0Cleanup) }
};

// R6Engine.dll data @ 1005a204 : interactiveObjectCheckErrorsFuncInfo
// Retains this method's exact exception states, cleanup actions and handler associations.
const NativeFunctionInfoPrefix interactiveObjectCheckErrorsFuncInfo = { 0x19930520, 0x1,
    ((uint)&interactiveObjectCheckErrorsUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 1005a0dc : interactiveObjectPreNetUnwindMap
// Retains the pre-receive guard's null-action states and exact typed/context catches.
const NativeUnwindEntry interactiveObjectPreNetUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a0ec : interactiveObjectPreNetCatchMap
// Retains the pre-receive guard's null-action states and exact typed/context catches.
const NativeCatchEntry interactiveObjectPreNetCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&InteractiveObjectPreNetCatchPointer) },
    { 0, 0, 0, ((uint)&InteractiveObjectPreNetCatchContext) }
};

// R6Engine.dll data @ 1005a10c : interactiveObjectPreNetTryMap
// Retains the pre-receive guard's null-action states and exact typed/context catches.
const NativeTryBlock interactiveObjectPreNetTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&interactiveObjectPreNetCatchMap) }
};

// R6Engine.dll data @ 1005a120 : interactiveObjectPreNetFuncInfo
// Retains the pre-receive guard's null-action states and exact typed/context catches.
const NativeFunctionInfoPrefix interactiveObjectPreNetFuncInfo = { 0x19930520, 0x2,
    ((uint)&interactiveObjectPreNetUnwindMap), 0x1, ((uint)&interactiveObjectPreNetTryMap), 0 };

// R6Engine.dll data @ 100754e4 : PreNetDamagePercentage
// One module-global snapshot is overwritten by each object's successful pre-receive hook.
float PreNetDamagePercentage = 0.0f; // Loader-zeroed native storage; descriptive name.

// R6Engine.dll data @ 1005a074 : interactiveObjectRenderUnwindMap
// Retains the delayed batcher cleanup state and exact typed/context catches.
const NativeUnwindEntry interactiveObjectRenderUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&InteractiveObjectRenderState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a08c : interactiveObjectRenderCatchMap
// Retains the delayed batcher cleanup state and exact typed/context catches.
const NativeCatchEntry interactiveObjectRenderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&InteractiveObjectRenderCatchPointer) },
    { 0, 0, 0, ((uint)&InteractiveObjectRenderCatchContext) }
};

// R6Engine.dll data @ 1005a0ac : interactiveObjectRenderTryMap
// Retains the delayed batcher cleanup state and exact typed/context catches.
const NativeTryBlock interactiveObjectRenderTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&interactiveObjectRenderCatchMap) }
};

// R6Engine.dll data @ 1005a0c0 : interactiveObjectRenderFuncInfo
// Retains the delayed batcher cleanup state and exact typed/context catches.
const NativeFunctionInfoPrefix interactiveObjectRenderFuncInfo = { 0x19930520, 0x3,
    ((uint)&interactiveObjectRenderUnwindMap), 0x1, ((uint)&interactiveObjectRenderTryMap), 0 };

// R6Engine.dll data @ 1005a014 : interactiveObjectTraceUnwindMap
// Retains the trace guard's null-action states and exact typed/context catches.
const NativeUnwindEntry interactiveObjectTraceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a024 : interactiveObjectTraceCatchMap
// Retains the trace guard's null-action states and exact typed/context catches.
const NativeCatchEntry interactiveObjectTraceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&InteractiveObjectTraceCatchPointer) },
    { 0, 0, 0, ((uint)&InteractiveObjectTraceCatchContext) }
};

// R6Engine.dll data @ 1005a044 : interactiveObjectTraceTryMap
// Retains the trace guard's null-action states and exact typed/context catches.
const NativeTryBlock interactiveObjectTraceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&interactiveObjectTraceCatchMap) }
};

// R6Engine.dll data @ 1005a058 : interactiveObjectTraceFuncInfo
// Retains the trace guard's null-action states and exact typed/context catches.
const NativeFunctionInfoPrefix interactiveObjectTraceFuncInfo = { 0x19930520, 0x2,
    ((uint)&interactiveObjectTraceUnwindMap), 0x1, ((uint)&interactiveObjectTraceTryMap), 0 };

// R6Engine.dll data @ 100584c4 : interactiveDestructionUnwindMap
// Retains the exact completed-member/base cleanup states without any catch handlers.
const NativeUnwindEntry interactiveDestructionUnwindMap[5] = {
    { -1, ((uint)&InteractiveDestructionState0Cleanup) },
    { 0, ((uint)&InteractiveDestructionState1Cleanup) },
    { 0x1, ((uint)&InteractiveDestructionState2Cleanup) },
    { 0x2, ((uint)&InteractiveDestructionState3Cleanup) },
    { 0x3, ((uint)&InteractiveDestructionState4Cleanup) }
};

// R6Engine.dll data @ 100584ec : interactiveDestructionFuncInfo
// Retains the exact completed-member/base cleanup states without any catch handlers.
const NativeFunctionInfoPrefix interactiveDestructionFuncInfo = { 0x19930520, 0x5,
    ((uint)&interactiveDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058508 : interactiveCopyUnwindMap
// Retains the exact completed-member/base cleanup states without any catch handlers.
const NativeUnwindEntry interactiveCopyUnwindMap[4] = {
    { -1, ((uint)&InteractiveCopyState0Cleanup) },
    { 0, ((uint)&InteractiveCopyState1Cleanup) },
    { 0x1, ((uint)&InteractiveCopyState2Cleanup) },
    { 0x2, ((uint)&InteractiveCopyState3Cleanup) }
};

// R6Engine.dll data @ 10058528 : interactiveCopyFuncInfo
// Retains the exact completed-member/base cleanup states without any catch handlers.
const NativeFunctionInfoPrefix interactiveCopyFuncInfo = { 0x19930520, 0x4, ((uint)&interactiveCopyUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 10080800 : autoclassAR6InteractiveObject
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6InteractiveObject = nullptr;

// R6Engine.dll @ 10008e10 : AR6InteractiveObject::eventSetNewDamageState
// Dispatches SetNewDamageState from the live incoming argument slot through the captured table.
void __thiscall AR6InteractiveObject::eventSetNewDamageState(float fPercentage)
{
    FName eventName = R6ENGINE_SetNewDamageState;
    uint inputWord = reinterpret_cast<uint&>(fPercentage);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    reinterpret_cast<uint&>(fPercentage) = inputWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, &fPercentage, nullptr);
}

// R6Engine.dll @ 10008e50 : AR6InteractiveObject::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6InteractiveObject::StaticClass(void)
{
    return &AR6InteractiveObject::PrivateStaticClass; // Selected object at0x1007fdd0.
}

// R6Engine.dll @ 10008e60 : AR6InteractiveObject::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6InteractiveObject::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6InteractiveObject::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10013fe0 : AR6InteractiveObject::operator=
// Copies interaction settings, skin references and four owned arrays.
AR6InteractiveObject& __thiscall AR6InteractiveObject::operator=(const AR6InteractiveObject& sourceObject)
{
    const AR6InteractiveObject* source = &sourceObject;
    this->AActor::operator=(*source);
    this->m_HearNoiseType = source->m_HearNoiseType;
    this->m_iActionNumber = source->m_iActionNumber;
    this->m_iActionIndex = source->m_iActionIndex;
    this->m_iHitPoints = source->m_iHitPoints;
    auto hitPoints = source->m_iCurrentHitPoints;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3ac);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3ac);
    uint earlyFlags = *destinationFlags; // Sampled before the hit-point/state stores.
    this->m_iCurrentHitPoints = hitPoints;
    this->m_iCurrentState = source->m_iCurrentState;
    uint difference = earlyFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags;
    copiedFlags ^= difference & 0x1U; // m_bCollisionRemovedFromActor.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bOriginalCollideActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bOriginalBlockActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bOriginalBlockPlayers.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bPawnDied.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bBroken.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bRainbowCanInteract.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // m_bEndAction.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bBlockCoronas.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // m_bBreakableByFlashBang.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fRadius) = reinterpret_cast<const uint&>(source->m_fRadius);
    reinterpret_cast<uint&>(this->m_fProbability) = reinterpret_cast<const uint&>(source->m_fProbability);
    reinterpret_cast<uint&>(this->m_fActionInterval) = reinterpret_cast<const uint&>(source->m_fActionInterval);
    reinterpret_cast<uint&>(this->m_fTimeSinceAction) = reinterpret_cast<const uint&>(source->m_fTimeSinceAction);
    reinterpret_cast<uint&>(this->m_fTimeForNextSound) = reinterpret_cast<const uint&>(source->m_fTimeForNextSound);
    reinterpret_cast<uint&>(this->m_fTimerInterval) = reinterpret_cast<const uint&>(source->m_fTimerInterval);
    reinterpret_cast<uint&>(this->m_fPlayerCAStartTime) = reinterpret_cast<const uint&>(source->m_fPlayerCAStartTime);
    reinterpret_cast<uint&>(this->m_HearNoiseLoudness) = reinterpret_cast<const uint&>(source->m_HearNoiseLoudness);
    reinterpret_cast<uint&>(this->m_fNetDamagePercentage) = reinterpret_cast<const
        uint&>(source->m_fNetDamagePercentage);
    reinterpret_cast<uint&>(this->m_fAIBreakNoiseRadius) = reinterpret_cast<const uint&>(source->m_fAIBreakNoiseRadius);
    this->m_InteractionOwner = source->m_InteractionOwner;
    this->m_RemoveCollisionFromActor = source->m_RemoveCollisionFromActor;
    this->m_Anchor = source->m_Anchor;
    this->m_vEndActionGoto = source->m_vEndActionGoto;
    this->m_CurrentInteractiveObject = source->m_CurrentInteractiveObject;
    this->m_SeePlayerPawn = source->m_SeePlayerPawn;
    this->m_HearNoiseNoiseMaker = source->m_HearNoiseNoiseMaker;
    this->m_aOldSkins[0] = source->m_aOldSkins[0];
    this->m_aOldSkins[1] = source->m_aOldSkins[1];
    this->m_aOldSkins[2] = source->m_aOldSkins[2];
    this->m_aOldSkins[3] = source->m_aOldSkins[3];
    this->m_aRepSkins[0] = source->m_aRepSkins[0];
    this->m_aRepSkins[1] = source->m_aRepSkins[1];
    this->m_aRepSkins[2] = source->m_aRepSkins[2];
    this->m_aRepSkins[3] = source->m_aRepSkins[3];
    this->sm_staticMesh = source->sm_staticMesh;
    this->m_User = source->m_User;
    this->sm_AmbientSound = source->sm_AmbientSound;
    this->sm_AmbientSoundStop = source->sm_AmbientSoundStop;
    reinterpret_cast<uint&>(this->m_vEndActionAnimName) = reinterpret_cast<const uint&>(source->m_vEndActionAnimName);
    AssignRecords4((FArray*)&this->m_ActionList,
        (const FArray*)&source->m_ActionList);
    AssignRecords4((FArray*)&this->sm_aSkins,
        (const FArray*)&source->sm_aSkins);
    AssignDamageStateArray((FArray*)&this->m_StateList,
        (const FArray*)&source->m_StateList);
    AssignRecords4((FArray*)&this->m_AttachedActors,
        (const FArray*)&source->m_AttachedActors);
    return *this;
}

// R6Engine.dll @ 10014b60 : AR6InteractiveObject::~AR6InteractiveObject
// Runs conditional cleanup before automatic array-member and AActor base destruction.
AR6InteractiveObject::~AR6InteractiveObject()
{
    // Compiler installs vtable1004de90; state4 protects all four arrays and the AActor base during this call.
    UObject::ConditionalDestroy();
    // Implicit destruction: m_AttachedActors(e970,state3), m_StateList(13f90,state2), sm_aSkins(e970,state1),
    // m_ActionList(e970,state0), then AActor(49514,state-1). Exact exception actions are retained below.
}

// R6Engine.dll @ 10014c00 : AR6InteractiveObject::AR6InteractiveObject()
// Constructs through AActor, installs the interactive-object vtable and leaves derived storage untouched.
// Keep the native ABI view: array member no-init declarations remain unresolved.
AR6InteractiveObject* __thiscall AR6InteractiveObject::AR6InteractiveObject(AR6InteractiveObject* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6InteractiveObjectVirtualTable);
    return this;
}

// R6Engine.dll @ 10014c20 : AR6InteractiveObject::AR6InteractiveObject
// Copies interaction settings, skin references and four owned arrays.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6InteractiveObject* __thiscall
AR6InteractiveObject::AR6InteractiveObject(AR6InteractiveObject* this, const AR6InteractiveObject* source)
{
    struct PendingConstruction {
        AR6InteractiveObject* object;
        int state;
        // Releases only completed members, then the completed AActor base, in native map order.
        ~PendingConstruction() noexcept(false) {
            if (state >= 3) ForwardDamageStateArrayDestruction((FArray*)((byte*)object + 0x440));
            if (state >= 2) ForwardWordArrayDestruction((FArray*)((byte*)object + 0x434));
            if (state >= 1) ForwardWordArrayDestruction((FArray*)((byte*)object + 0x428));
            if (state >= 0) {
                using DestroyActor = void (__thiscall*)(AActor*);
                (*(DestroyActor*)&AActorDestructorImport)((AActor*)object);
            }
        }
    } cleanup{this, -1}; // Inferred view of FuncInfo10058528, not another native body.
    using CopyActor = AActor* (__thiscall*)(AActor*, const AActor*);
    reinterpret_cast<CopyActor&>(AActorCopyConstructorImport)(this, source);
    *(uint*)this = ((uint)&AR6InteractiveObjectVirtualTable);
    this->m_HearNoiseType = source->m_HearNoiseType;
    this->m_iActionNumber = source->m_iActionNumber;
    this->m_iActionIndex = source->m_iActionIndex;
    this->m_iHitPoints = source->m_iHitPoints;
    auto hitPoints = source->m_iCurrentHitPoints;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3ac);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3ac);
    uint earlyFlags = *destinationFlags; // Sampled before the hit-point/state stores.
    this->m_iCurrentHitPoints = hitPoints;
    this->m_iCurrentState = source->m_iCurrentState;
    uint difference = earlyFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags;
    copiedFlags ^= difference & 0x1U; // m_bCollisionRemovedFromActor.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bOriginalCollideActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bOriginalBlockActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // m_bOriginalBlockPlayers.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // m_bPawnDied.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // m_bBroken.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bRainbowCanInteract.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // m_bEndAction.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // m_bBlockCoronas.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // m_bBreakableByFlashBang.
    *destinationFlags = copiedFlags;
    uint radiusWord = reinterpret_cast<const uint&>(source->m_fRadius);
    cleanup.state = 0; // Delayed base protection begins after sampling radius.
    reinterpret_cast<uint&>(this->m_fRadius) = radiusWord;
    reinterpret_cast<uint&>(this->m_fProbability) = reinterpret_cast<const uint&>(source->m_fProbability);
    reinterpret_cast<uint&>(this->m_fActionInterval) = reinterpret_cast<const uint&>(source->m_fActionInterval);
    reinterpret_cast<uint&>(this->m_fTimeSinceAction) = reinterpret_cast<const uint&>(source->m_fTimeSinceAction);
    reinterpret_cast<uint&>(this->m_fTimeForNextSound) = reinterpret_cast<const uint&>(source->m_fTimeForNextSound);
    reinterpret_cast<uint&>(this->m_fTimerInterval) = reinterpret_cast<const uint&>(source->m_fTimerInterval);
    reinterpret_cast<uint&>(this->m_fPlayerCAStartTime) = reinterpret_cast<const uint&>(source->m_fPlayerCAStartTime);
    reinterpret_cast<uint&>(this->m_HearNoiseLoudness) = reinterpret_cast<const uint&>(source->m_HearNoiseLoudness);
    reinterpret_cast<uint&>(this->m_fNetDamagePercentage) = reinterpret_cast<const
        uint&>(source->m_fNetDamagePercentage);
    reinterpret_cast<uint&>(this->m_fAIBreakNoiseRadius) = reinterpret_cast<const uint&>(source->m_fAIBreakNoiseRadius);
    this->m_InteractionOwner = source->m_InteractionOwner;
    this->m_RemoveCollisionFromActor = source->m_RemoveCollisionFromActor;
    this->m_Anchor = source->m_Anchor;
    this->m_vEndActionGoto = source->m_vEndActionGoto;
    this->m_CurrentInteractiveObject = source->m_CurrentInteractiveObject;
    this->m_SeePlayerPawn = source->m_SeePlayerPawn;
    this->m_HearNoiseNoiseMaker = source->m_HearNoiseNoiseMaker;
    this->m_aOldSkins[0] = source->m_aOldSkins[0];
    this->m_aOldSkins[1] = source->m_aOldSkins[1];
    this->m_aOldSkins[2] = source->m_aOldSkins[2];
    this->m_aOldSkins[3] = source->m_aOldSkins[3];
    this->m_aRepSkins[0] = source->m_aRepSkins[0];
    this->m_aRepSkins[1] = source->m_aRepSkins[1];
    this->m_aRepSkins[2] = source->m_aRepSkins[2];
    this->m_aRepSkins[3] = source->m_aRepSkins[3];
    this->sm_staticMesh = source->sm_staticMesh;
    this->m_User = source->m_User;
    this->sm_AmbientSound = source->sm_AmbientSound;
    this->sm_AmbientSoundStop = source->sm_AmbientSoundStop;
    reinterpret_cast<uint&>(this->m_vEndActionAnimName) = reinterpret_cast<const uint&>(source->m_vEndActionAnimName);
    CopyConstructRecords4((FArray*)&this->m_ActionList,
        (const FArray*)&source->m_ActionList);
    cleanup.state = 1;
    CopyConstructRecords4((FArray*)&this->sm_aSkins,
        (const FArray*)&source->sm_aSkins);
    cleanup.state = 2;
    CopyConstructDamageStateArray((FArray*)&this->m_StateList,
        (const FArray*)&source->m_StateList);
    cleanup.state = 3;
    CopyConstructRecords4((FArray*)&this->m_AttachedActors,
        (const FArray*)&source->m_AttachedActors);
    cleanup.state = -1; // Transfer completed ownership; native returns with no state4/member action.
    return this;
}

// R6Engine.dll @ 10014f40 : AR6InteractiveObject::DeletingDestructor
// Destroys one interactive object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6InteractiveObject::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6InteractiveObject* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6InteractiveObjectDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x458, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6InteractiveObject::~AR6InteractiveObject();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x458);
    }
    return object;
}

// R6Engine.dll @ 10016120 : AR6InteractiveObject::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6InteractiveObject::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6InteractiveObjectConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001bf60 : AR6InteractiveObject::ShouldTrace
// Applies ordered trace-through gates, corona blocking and the final actor trace query.
int __thiscall AR6InteractiveObject::ShouldTrace(AActor* other, ulong traceFlags)
{
    const uint* collisionFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0xa8);
    try {
        if ((traceFlags & 0x800000U) != 0)
            return 1;
        if ((traceFlags & 0x400000U) != 0 && (*collisionFlagWord & 0x80000U) != 0)
            return 0; // m_bShotThrough.
        if ((traceFlags & 0x2000U) != 0)
            // m_bBlockCoronas.
            return (*reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0x3ac) >> 9) & 1U;
        if ((traceFlags & 0x20000U) != 0 && (reinterpret_cast<const byte*>(collisionFlagWord)[2] & 1U) != 0)
            return 0; // m_bSeeThrough; preserve native byte access.
        if ((traceFlags & 0x40000U) != 0 && (*collisionFlagWord & 0x40000U) != 0)
            return 0; // m_bBulletGoThrough.
        if ((traceFlags & 0x200000U) != 0 && (*collisionFlagWord & 0x20000U) != 0)
            return 0; // m_bPawnGoThrough.
        if ((traceFlags & 2U) != 0)
            return 1;
        return this->AActor::ShouldTrace(other, traceFlags) != 0 ? 1 : 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6InteractiveObject::ShouldTrace");
        throw;
    }
}

// R6Engine.dll @ 1001c02b : InteractiveObjectTraceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectTraceCatchPointer(void)
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

// R6Engine.dll @ 1001c03f : InteractiveObjectTraceCatchContext
// Reports the interactive-object trace context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6InteractiveObjectShouldTrace
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044250 : InteractiveObjectTraceExceptionHandler
// Supplies the trace FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveObjectTraceExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectTraceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001c080 : AR6InteractiveObject::RenderEditorInfo
// Draws a selected object's radius sphere when its probability is nonzero or unordered.
void __thiscall AR6InteractiveObject::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* unusedInterface,
    FDynamicActor* unusedActor)
{
    // bSelected; before state0.
    bool selected = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0xac) & 0x4000U) != 0;
    using Destroy = void (__thiscall*)(FLineBatcher*);
    struct PendingBatcher {
        FLineBatcher* batcher;
        bool active;
        // Disables cleanup before normal destruction, preserving a destructor failure's state0.
        void Finish() {
            active = false;
            (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
        // Cleans the completed temporary only after the native delayed state1 was reached.
        ~PendingBatcher() noexcept(false) {
            if (active) (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
    }; // Inferred lifetime view; the exact frame/action is retained beside the native FuncInfo.
    try {
        if (!selected || this->m_fProbability == nativeFloatZero) return; // Native FUCOMPP; NaN draws.
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* render = *(FRenderInterface**)(owner + 0x164);
        alignas(FLineBatcher) byte batcherStorage[0x24]; // Native EBP-0x4c; no implicit extra construction.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        // Return pointer is ignored.
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(render, 1, 0);
        // Capture native float bits after construction.
        uint radiusWord = reinterpret_cast<const uint&>(this->m_fRadius);
        PendingBatcher cleanup{batcher, true}; // State1 follows radius capture and outgoing argument setup.
        alignas(FPlane) uint planeWords[4] = {0x3f400000, 0x3f800000, 0, 0};
        uint colorWord; // Constructor writes the outgoing four-byte color, without default initialization.
        ::new (reinterpret_cast<void*>(&colorWord)) FColor(*reinterpret_cast<const FPlane*>(planeWords));
        FVector center;
        uint centerX = reinterpret_cast<const uint&>(this->Location.X);
        uint centerY = reinterpret_cast<const uint&>(this->Location.Y);
        ((uint*)&center)[0] = centerX;
        uint centerZ = reinterpret_cast<const uint&>(this->Location.Z);
        ((uint*)&center)[1] = centerY;
        ((uint*)&center)[2] = centerZ;
        batcher->FLineBatcher::DrawSphere(
            center, *(const FColor*)&colorWord, reinterpret_cast<const float&>(radiusWord), 16);
        cleanup.Finish();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6InteractiveObject::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001c169 : InteractiveObjectRenderCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectRenderCatchPointer(void)
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

// R6Engine.dll @ 1001c17d : InteractiveObjectRenderCatchContext
// Reports the interactive-object editor-render context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectRenderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6InteractiveObjectRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001c1a0 : AR6InteractiveObject::PreNetReceive
// Saves the live damage-percentage word after the actor base receive hook succeeds.
void __thiscall AR6InteractiveObject::PreNetReceive(void)
{
    try {
        this->AActor::PreNetReceive();
        // +0x3d0.
        reinterpret_cast<uint&>(PreNetDamagePercentage) = reinterpret_cast<const uint&>(this->m_fNetDamagePercentage);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6InteractiveObject::PreNetReceive");
        throw;
    }
}

// R6Engine.dll @ 1001c1ec : InteractiveObjectPreNetCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPreNetCatchPointer(void)
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

// R6Engine.dll @ 1001c200 : InteractiveObjectPreNetCatchContext
// Reports the interactive-object pre-receive context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPreNetCatchContext(void)
{
    __asm {
        push offset nativeTextAR6InteractiveObjectPreNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044280 : InteractiveObjectPreNetExceptionHandler
// Supplies the pre-receive FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveObjectPreNetExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectPreNetFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001c390 : AR6InteractiveObject::PostNetReceive
// Applies changed replicated damage, then reconciles four replicated skin slots in native order.
void __thiscall AR6InteractiveObject::PostNetReceive(void)
{
    try {
        this->AActor::PostNetReceive();
        float previousDamage = PreNetDamagePercentage;
        float currentDamage = this->m_fNetDamagePercentage;
        if (currentDamage != previousDamage) { // Native FUCOMPP; unordered also invokes the event.
            // Current SetNewDamageState FName index.
            uint callbackName = *(const uint*)&R6ENGINE_SetNewDamageState;
            // Native EBP-0x14, reloaded raw.
            uint damageParameter = reinterpret_cast<const uint&>(this->m_fNetDamagePercentage);
            UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(callbackName), 0);
            byte* currentTable = *(byte**)this; // Sample after FindFunctionChecked returns.
            using Process = void (__thiscall*)(UObject*, UFunction*, void*, void*);
            (*(Process*)(currentTable + 0x10))(this, function, &damageParameter, nullptr);
        }
        for (int index = 0; index != 4; ++index) {
            UMaterial* comparisonSkin = this->m_aRepSkins[index];
            if (comparisonSkin == this->m_aOldSkins[index])
                continue;
            FArray* skins = reinterpret_cast<FArray*>(&this->Skins);
            if (reinterpret_cast<NativeArrayHeader32*>(skins)->count < 4) {
                // Adds four, not the deficit; EAX is ignored.
                skins->FArray::AddZeroed(4, 4);
            }
            UMaterial* replicatedSkin = this->m_aRepSkins[index]; // Reload after AddZeroed.
            this->m_aOldSkins[index] = replicatedSkin;
            UMaterial** currentSkins = reinterpret_cast<UMaterial**>(
                reinterpret_cast<NativeArrayHeader32&>(this->Skins).dataAddress); // Sample after the saved-slot store.
            currentSkins[index] = replicatedSkin;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6InteractiveObject::PostNetReceive");
        throw;
    }
}

// R6Engine.dll @ 1001c448 : InteractiveObjectPostNetCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPostNetCatchPointer(void)
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

// R6Engine.dll @ 1001c45c : InteractiveObjectPostNetCatchContext
// Reports the interactive-object post-receive context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl InteractiveObjectPostNetCatchContext(void)
{
    __asm {
        push offset nativeTextAR6InteractiveObjectPostNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100442a0 : InteractiveObjectPostNetExceptionHandler
// Supplies post-receive's FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveObjectPostNetExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectPostNetFuncInfo
        jmp __CxxFrameHandler
    }
}

// Inferred PE32 views of the matching damage-state and spawned-actor records; no local objects are constructed.
struct NativeDamageStateRecord
{
    float fDamagePercentage; // +0x00
    NativeArrayHeader32 RandomMeshes; // +0x04
    NativeArrayHeader32 RandomSkins; // +0x10
    NativeArrayHeader32 ActorList; // +0x1c: 16-byte spawned-actor records.
    NativeArrayHeader32 SoundList; // +0x28
    USound* NewAmbientSound; // +0x34
    USound* NewAmbientSoundStop; // +0x38
};

struct NativeSpawnedActorRecord
{
    UClass* ActorToSpawn; // +0x00
    FString HelperName; // +0x04
};

// R6Engine.dll @ 1001c490 : AR6InteractiveObject::CheckForErrors
// Checks state actor tags against the static mesh and reports missing tags with the native warning packet.
void __thiscall AR6InteractiveObject::CheckForErrors(void)
{
    // Native DrawType byte and mesh guard.
    if (reinterpret_cast<const byte&>(this->DrawType) != 8 || this->StaticMesh == nullptr)
        return;
    struct StringPacket { uint data, num, max; }; // Twelve-byte by-value FString ABI; callee consumes its lifetime.
    using GetTag = FTags* (__thiscall*)(UStaticMesh*, StringPacket);
    using Format = FString* (__cdecl*)(FString*, const ushort*, uint, uint, uint, int, int);
    using Destroy = void (__thiscall*)(FString*);
    using Report = void (__thiscall*)(FFeedbackContext*, int, AActor*, const ushort*); // Native slot0x28 role.
    struct PendingString {
        FString* string;
        bool active;
        // Drops the protected state before normal destruction.
        void Finish() {
            active = false;
            (*(Destroy*)&FStringDestructorImport)(string);
        }
        // Releases only the completed formatted warning on an escaping provider exception.
        ~PendingString() noexcept(false) {
            if (active) (*(Destroy*)&FStringDestructorImport)(string);
        }
    }; // Inferred lifetime view; exact parent-frame map is retained below.
    int stateIndex = 0;
    uint stateOffset = 0;
    while (stateIndex < reinterpret_cast<const NativeArrayHeader32&>(this->m_StateList).count) {
        // Captured for this whole inner loop.
        NativeDamageStateRecord* state = reinterpret_cast<NativeDamageStateRecord*>(
            reinterpret_cast<const NativeArrayHeader32&>(this->m_StateList).dataAddress + stateOffset);
        int actorIndex = 0;
        uint actorOffset = 0;
        while (actorIndex < state->ActorList.count) {
            NativeSpawnedActorRecord* record = reinterpret_cast<NativeSpawnedActorRecord*>(
                state->ActorList.dataAddress + actorOffset);
            const FString* tag = &record->HelperName; // Captured descriptor, not its later container header.
            if (tag->operator!=(nativeEmptyText) != 0) {
                alignas(FString) uint outgoingTag[3];
                // No caller-owned completed-string state.
                ::new (reinterpret_cast<void*>(outgoingTag)) FString(*tag);
                UStaticMesh* mesh = this->StaticMesh; // Reload after the string constructor.
                if (reinterpret_cast<GetTag&>(UStaticMeshGetTagImport)(mesh,
                    *(const StringPacket*)outgoingTag) == nullptr) {
                    uint tagData = *(const uint*)tag;
                    uint tagNum = *((const uint*)tag + 1);
                    alignas(FString) byte warningStorage[12]; // Native EBP-0x18; no extra default construction.
                    uint tagMax = *((const uint*)tag + 2);
                    FString* warning = (FString*)warningStorage;
                    reinterpret_cast<Format&>(FStringPrintfImport)(warning,
                        nativeTextInvalidTagSInMStateListDActorListD,
                        tagData, tagNum, tagMax, stateIndex, actorIndex);
                    // Native %s/%d/%d sees Data/Num/Max; the two intended indices are extra vararg words.
                    FFeedbackContext* firstWarning = **(FFeedbackContext***)&CoreGWarnImport;
                    byte* warningTable = *(byte**)firstWarning; // Capture table before FString::operator*.
                    PendingString cleanup{warning, true}; // State0 begins only after formatting and table capture.
                    const ushort* text = warning->operator*();
                    FFeedbackContext* currentWarning = **(FFeedbackContext***)&CoreGWarnImport;
                    (*(Report*)(warningTable + 0x28))(currentWarning, 0, this, text);
                    cleanup.Finish();
                }
            }
            actorIndex = (int)((uint)actorIndex + 1U);
            actorOffset += 0x10U;
        }
        stateIndex = (int)((uint)stateIndex + 1U);
        stateOffset += 0x3cU;
    }
}

// R6Engine.dll @ 10043a40 : InteractiveDestructionState0Cleanup
// Tail-destroys the saved AActor base through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043a49 : InteractiveDestructionState1Cleanup
// Tail-destroys the saved array at+0x428 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x428
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043a57 : InteractiveDestructionState2Cleanup
// Tail-destroys the saved array at+0x434 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveDestructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x434
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043a65 : InteractiveDestructionState3Cleanup
// Tail-destroys the saved array at+0x440 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveDestructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x440
        jmp ForwardDamageStateArrayDestruction
    }
}

// R6Engine.dll @ 10043a73 : InteractiveDestructionState4Cleanup
// Tail-destroys the saved array at+0x44c through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveDestructionState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x44c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043a90 : InteractiveCopyState0Cleanup
// Tail-destroys the saved AActor base through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 10043a99 : InteractiveCopyState1Cleanup
// Tail-destroys the saved array at+0x428 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveCopyState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x428
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043aa7 : InteractiveCopyState2Cleanup
// Tail-destroys the saved array at+0x434 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveCopyState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x434
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043ab5 : InteractiveCopyState3Cleanup
// Tail-destroys the saved array at+0x440 through the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveCopyState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x440
        jmp ForwardDamageStateArrayDestruction
    }
}

// R6Engine.dll @ 10044260 : InteractiveObjectRenderState1Cleanup
// Tail-destroys the editor-render batcher at inherited EBP-0x4c through the current import.
__declspec(naked) void __cdecl InteractiveObjectRenderState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x4c]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10044269 : InteractiveObjectRenderExceptionHandler
// Supplies editor rendering's FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl InteractiveObjectRenderExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectRenderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100442b0 : InteractiveObjectCheckErrorsState0Cleanup
// Tail-destroys the completed check-warning string at inherited EBP-0x18 through the current import.
__declspec(naked) void __cdecl InteractiveObjectCheckErrorsState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100442b9 : InteractiveObjectCheckErrorsExceptionHandler
// Supplies the check-warning cleanup FuncInfo without adding a dispatcher frame or catch block.
__declspec(naked) void __cdecl InteractiveObjectCheckErrorsExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectCheckErrorsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10046a70 : InitializeAR6InteractiveObjectClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6InteractiveObjectClassMetadata(void)
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
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6InteractiveObject::PrivateStaticClass, 0, 0x458, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6InteractiveObject,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6InteractiveObject::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6InteractiveObjectClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048110 : DestroyAR6InteractiveObjectClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6InteractiveObjectClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6InteractiveObject::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046b00 : PublishAR6InteractiveObjectAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6InteractiveObjectAutoClass(void)
{
    autoclassAR6InteractiveObject = &AR6InteractiveObject::PrivateStaticClass;
}

// R6Engine.dll @ 10043a81 : InteractiveDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo while preserving the native dispatcher frame and arguments.
__declspec(naked) void __cdecl InteractiveDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043ac3 : InteractiveCopyExceptionHandler
// Supplies the exact cleanup-only FuncInfo while preserving the native dispatcher frame and arguments.
__declspec(naked) void __cdecl InteractiveCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveCopyFuncInfo
        jmp __CxxFrameHandler
    }
}

// Raw native array providers for the script-bound 0x3c-byte stDamageState record.

// Native helper declarations match the canonical definitions below.
void __thiscall DestroyDamageStateArray(FArray* array);

// R6Engine.dll @ 10013d40 : EmptyDamageStateArray
// Destroys live records, clears the count and reallocates storage to the requested capacity.
void __thiscall EmptyDamageStateArray(FArray* array, int reservedCount)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    uint index = 0;
    uint offset = 0;
    int liveCount = arrayHeaderView->count;
    while ((int)index < liveCount) {
        void* record = (void*)(arrayHeaderView->dataAddress + offset);
        DestroyDamageState(record);
        liveCount = arrayHeaderView->count;
        ++index;
        offset += 0x3cU;
    }
    int capacity = reservedCount; // Sample the argument after record destruction and before either header store.
    arrayHeaderView->count = 0;
    arrayHeaderView->capacity = capacity;
    array->FArray::Realloc(0x3c);
}

// R6Engine.dll @ 10013d90 : CopyConstructDamageStateArray
// Reserves the captured count and constructs records with a delayed outer-storage cleanup guard.
FArray* __thiscall CopyConstructDamageStateArray(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    struct PendingStorage {
        FArray* array;
        bool active;
        // Only outer FArray storage is protected here; no previously completed records are destroyed.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{destination, false}; // Shared43a20/43a29/584a8 also serves independently scoped array parents.
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    destination->FArray::Realloc(0x3c);
    destinationHeaderView->count = 0;
    uint index = 0;
    uint offset = 0;
    int liveCount = sourceHeaderView->count;
    cleanup.active = true; // State0 follows the live count comparison, not initial header setup or Realloc.
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 0x3c);
        void* output = (void*)(destinationHeaderView->dataAddress + (uint)addedIndex * 0x3cU);
        if (output != nullptr) {
            const void* input = (const void*)(sourceHeaderView->dataAddress + offset);
            CopyConstructDamageState(output, input);
        }
        liveCount = sourceHeaderView->count;
        ++index;
        offset += 0x3cU;
    }
    cleanup.active = false; // Successful ownership transfer; no extra native state write is implied.
    return destination;
}

// R6Engine.dll @ 10013e70 : RemoveDamageStates
// Validates a captured start, destroys its captured range and removes with the later count argument.
void __thiscall RemoveDamageStates(FArray* array, int index, int count)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int first = index;
    using AssertCall = void (__cdecl*)(const char*, const char*, int);
    // All three reports retain this target if callbacks replace the import.
    AssertCall fail = reinterpret_cast<AssertCall&>(CoreAppFailAssertImport);
    if (first < 0) fail("Index>=0", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x201);
    if (first > arrayHeaderView->count)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    int end = (int)((uint)first + (uint)count);
    if (end > arrayHeaderView->count)
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    if (first < end) {
        uint offset = (uint)first * 0x3cU;
        uint remaining = (uint)end - (uint)first;
        do {
            DestroyDamageState((void*)(arrayHeaderView->dataAddress + offset));
            offset += 0x3cU;
        } while (--remaining != 0);
    }
    // Count is resampled after reporting/destruction callbacks.
    array->FArray::Remove(first, count, 0x3c);
}

// R6Engine.dll @ 10013f10 : AssignDamageStateArray
// Replaces distinct arrays and copies records while following current source headers and destination storage.
FArray* __thiscall AssignDamageStateArray(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    if (destination == source) return destination;
    EmptyDamageStateArray(destination, sourceHeaderView->count);
    uint index = 0;
    uint offset = 0;
    int liveCount = sourceHeaderView->count;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 0x3c);
        void* output = (void*)(destinationHeaderView->dataAddress + (uint)addedIndex * 0x3cU);
        if (output != nullptr) {
            const void* input = (const void*)(sourceHeaderView->dataAddress + offset);
            CopyConstructDamageState(output, input);
        }
        liveCount = sourceHeaderView->count;
        ++index;
        offset += 0x3cU;
    }
    return destination;
}

// R6Engine.dll @ 10013f90 : DestroyDamageStateArray
// Destroys the captured record count and releases outer storage on normal or exceptional exit.
void __thiscall DestroyDamageStateArray(FArray* array)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int count = arrayHeaderView->count; // Captured before native state0 is armed.
    struct PendingStorage {
        FArray* array;
        bool active;
        // Releases outer storage only; record-removal failure does not destroy unvisited records here.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{array, true};
    RemoveDamageStates(array, 0, count);
    cleanup.active = false;
    // State-1 prevents a second cleanup if storage destruction throws.
    array->FArray::~FArray();
}

// R6Engine.dll @ 100142e0 : ForwardDamageStateArrayDestruction
// Tail-enters damage-state array destruction with the original ECX receiver and return frame.
__declspec(naked) void __thiscall ForwardDamageStateArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyDamageStateArray
    }
}
