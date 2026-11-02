#include "native_array_views.hpp"
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
FArray* __thiscall AssignZDRArray(FArray* destination, const FArray* source);
FArray* __thiscall AssignRecords4(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructZDRArray(FArray* destination, const FArray* source);
FArray* __thiscall CopyConstructRecords4(FArray* destination, const FArray* source);
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);
FArray* __thiscall CopyConstructRecords16(FArray* destination, const FArray* source);
void* __thiscall CopyConstructZDR(void* destination, const void* source);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
__declspec(naked) void __thiscall ForwardZDRArrayDestruction(FArray* array);

FArray* __thiscall CopyConstructRecords12(FArray* destination, const FArray* source);

FArray* __thiscall AssignRecords12(FArray* destination, const FArray* source);

void __thiscall DestroyTwelveByteArrayStorage(FArray* array);

__declspec(naked) void __thiscall ForwardTwelveByteArrayDestruction(FArray* array);

int __cdecl CastToAMP2IOKarma(int object);

// R6Engine.dll data @ 1004e018 : AMP2IOKarmaVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AMP2IOKarma::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AMP2IOKarmaVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050758 : nativeTextAMP2IOKarmaExecMP2IOKarmaAllNativeFct
extern const ushort nativeTextAMP2IOKarmaExecMP2IOKarmaAllNativeFct[40];

// R6Engine.dll data @ 10050900 : nativeTextAMP2IOKarmaRenderEditorInfo
extern const ushort nativeTextAMP2IOKarmaRenderEditorInfo[30];

// R6Engine.dll data @ 10050860 : nativeTextKMP2DynKarmaInterfaceRenderEditorInfo
extern const ushort nativeTextKMP2DynKarmaInterfaceRenderEditorInfo[40];

// R6Engine.dll data @ 10055a76 : nativeTextMP2IOKarma
extern const ushort nativeTextMP2IOKarma[11];

// R6Engine.dll data @ 10050730 : nativeTextSS04X
extern const ushort nativeTextSS04X[17];

// R6Engine.dll data @ 100508b0 : nativeTextZDRDFSSoundS
extern const ushort nativeTextZDRDFSSoundS[34];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl KarmaCopyState0Cleanup(void);
__declspec(naked) void __cdecl KarmaCopyState1Cleanup(void);
__declspec(naked) void __cdecl KarmaCopyState2Cleanup(void);
__declspec(naked) void __cdecl KarmaDestructionState0Cleanup(void);
__declspec(naked) void __cdecl KarmaDestructionState1Cleanup(void);
__declspec(naked) void __cdecl KarmaDestructionState2Cleanup(void);
__declspec(naked) void __cdecl KarmaDestructionState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaExecCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaExecCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaInterfaceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaInterfaceCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaRenderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl KarmaRenderCatchPointer(void);
__declspec(naked) void __cdecl KarmaRenderState1Cleanup(void);
__declspec(naked) void __cdecl KarmaRenderState2Cleanup(void);

// R6Engine.dll data @ 100508f8 : nativeDoubleMinus10000000
extern const double nativeDoubleMinus10000000;

// R6Engine.dll data @ 10058544 : karmaDestructionUnwindMap
// Retains the exact member/base cleanup chain and native completed-state boundaries.
const NativeUnwindEntry karmaDestructionUnwindMap[4] = {
    { -1, ((uint)&KarmaDestructionState0Cleanup) },
    { 0, ((uint)&KarmaDestructionState1Cleanup) },
    { 0x1, ((uint)&KarmaDestructionState2Cleanup) },
    { 0x2, ((uint)&KarmaDestructionState3Cleanup) }
};

// R6Engine.dll data @ 10058564 : karmaDestructionFuncInfo
// Retains the exact member/base cleanup chain and native completed-state boundaries.
const NativeFunctionInfoPrefix karmaDestructionFuncInfo = { 0x19930520, 0x4, ((uint)&karmaDestructionUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 10058580 : karmaCopyUnwindMap
// Retains the exact member/base cleanup chain and native completed-state boundaries.
const NativeUnwindEntry karmaCopyUnwindMap[3] = {
    { -1, ((uint)&KarmaCopyState0Cleanup) },
    { 0, ((uint)&KarmaCopyState1Cleanup) },
    { 0x1, ((uint)&KarmaCopyState2Cleanup) }
};

// R6Engine.dll data @ 10058598 : karmaCopyFuncInfo
// Retains the exact member/base cleanup chain and native completed-state boundaries.
const NativeFunctionInfoPrefix karmaCopyFuncInfo = { 0x19930520, 0x3, ((uint)&karmaCopyUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 1005a13c : karmaExecUnwindMap
// Retains terminal null-action states and the exec bridge's exact typed/context catches.
const NativeUnwindEntry karmaExecUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a14c : karmaExecCatchMap
// Retains terminal null-action states and the exec bridge's exact typed/context catches.
const NativeCatchEntry karmaExecCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&KarmaExecCatchPointer) },
    { 0, 0, 0, ((uint)&KarmaExecCatchContext) }
};

// R6Engine.dll data @ 1005a16c : karmaExecTryMap
// Retains terminal null-action states and the exec bridge's exact typed/context catches.
const NativeTryBlock karmaExecTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&karmaExecCatchMap) }
};

// R6Engine.dll data @ 1005a180 : karmaExecFuncInfo
// Retains terminal null-action states and the exec bridge's exact typed/context catches.
const NativeFunctionInfoPrefix karmaExecFuncInfo = { 0x19930520, 0x2, ((uint)&karmaExecUnwindMap), 0x1,
    ((uint)&karmaExecTryMap), 0 };

// R6Engine.dll data @ 1005a220 : karmaInterfaceUnwindMap
// Retains two terminal null-action states and the interface's exact typed/context catches.
const NativeUnwindEntry karmaInterfaceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a230 : karmaInterfaceCatchMap
// Retains two terminal null-action states and the interface's exact typed/context catches.
const NativeCatchEntry karmaInterfaceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -104, ((uint)&KarmaInterfaceCatchPointer) },
    { 0, 0, 0, ((uint)&KarmaInterfaceCatchContext) }
};

// R6Engine.dll data @ 1005a250 : karmaInterfaceTryMap
// Retains two terminal null-action states and the interface's exact typed/context catches.
const NativeTryBlock karmaInterfaceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&karmaInterfaceCatchMap) }
};

// R6Engine.dll data @ 1005a264 : karmaInterfaceFuncInfo
// Retains two terminal null-action states and the interface's exact typed/context catches.
const NativeFunctionInfoPrefix karmaInterfaceFuncInfo = { 0x19930520, 0x2, ((uint)&karmaInterfaceUnwindMap), 0x1,
    ((uint)&karmaInterfaceTryMap), 0 };

// R6Engine.dll data @ 1005a280 : karmaRenderUnwindMap
// Retains delayed batcher/record cleanup and exact typed/context catch associations.
const NativeUnwindEntry karmaRenderUnwindMap[4] = {
    { -1, 0 },
    { 0, ((uint)&KarmaRenderState1Cleanup) },
    { 0x1, ((uint)&KarmaRenderState2Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a2a0 : karmaRenderCatchMap
// Retains delayed batcher/record cleanup and exact typed/context catch associations.
const NativeCatchEntry karmaRenderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -108, ((uint)&KarmaRenderCatchPointer) },
    { 0, 0, 0, ((uint)&KarmaRenderCatchContext) }
};

// R6Engine.dll data @ 1005a2c0 : karmaRenderTryMap
// Retains delayed batcher/record cleanup and exact typed/context catch associations.
const NativeTryBlock karmaRenderTryMap[1] = {
    { 0, 0x2, 0x3, 0x2, ((uint)&karmaRenderCatchMap) }
};

// R6Engine.dll data @ 1005a2d4 : karmaRenderFuncInfo
// Retains delayed batcher/record cleanup and exact typed/context catch associations.
const NativeFunctionInfoPrefix karmaRenderFuncInfo = { 0x19930520, 0x4, ((uint)&karmaRenderUnwindMap), 0x1,
    ((uint)&karmaRenderTryMap), 0 };

// R6Engine.dll data @ 100743e0 : intAMP2IOKarmaexecMP2IOKarmaAllNativeFct
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAMP2IOKarmaexecMP2IOKarmaAllNativeFct = (Native)&AMP2IOKarma::execMP2IOKarmaAllNativeFct;

// R6Engine.dll data @ 1007c570 : AMP2IOKarmaMP2IOKarmaAllNativeFctRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AMP2IOKarmaMP2IOKarmaAllNativeFctRegistrationResult = 0;

// R6Engine.dll data @ 10076ebc : autoclassAMP2IOKarma
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAMP2IOKarma = nullptr;

// R6Engine.dll @ 10008e90 : AMP2IOKarma::eventStartSimulation
// Dispatches StartSimulation with the raw argument word and the pre-lookup object table.
void __thiscall AMP2IOKarma::eventStartSimulation(int WhatIdo)
{
    uint name = reinterpret_cast<const uint&>(R6ENGINE_StartSimulation);
    uint argument = reinterpret_cast<const uint&>(WhatIdo);
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    reinterpret_cast<uint&>(WhatIdo) = argument; // Native same-slot write preserves the complete input word.
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Process = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    reinterpret_cast<Process&>(table->processEventAddress)(this, function, &WhatIdo, nullptr);
}

// R6Engine.dll @ 10008ed0 : AMP2IOKarma::eventStopSimulation
// Dispatches StopSimulation with the raw argument word and the pre-lookup object table.
void __thiscall AMP2IOKarma::eventStopSimulation(int WhatIdo)
{
    uint name = reinterpret_cast<const uint&>(R6ENGINE_StopSimulation);
    uint argument = reinterpret_cast<const uint&>(WhatIdo);
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    reinterpret_cast<uint&>(WhatIdo) = argument; // Native same-slot write preserves the complete input word.
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Process = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    reinterpret_cast<Process&>(table->processEventAddress)(this, function, &WhatIdo, nullptr);
}

// R6Engine.dll @ 10008f10 : AMP2IOKarma::eventReinitSimulation
// Dispatches ReinitSimulation with the raw argument word and the pre-lookup object table.
void __thiscall AMP2IOKarma::eventReinitSimulation(int WhatIdo)
{
    uint name = reinterpret_cast<const uint&>(R6ENGINE_ReinitSimulation);
    uint argument = reinterpret_cast<const uint&>(WhatIdo);
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    reinterpret_cast<uint&>(WhatIdo) = argument; // Native same-slot write preserves the complete input word.
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Process = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    reinterpret_cast<Process&>(table->processEventAddress)(this, function, &WhatIdo, nullptr);
}

// R6Engine.dll @ 10008f50 : AMP2IOKarma::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AMP2IOKarma::StaticClass(void)
{
    return &AMP2IOKarma::PrivateStaticClass; // Selected object at0x10082bb0.
}

// R6Engine.dll @ 10008f60 : AMP2IOKarma::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AMP2IOKarma::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AMP2IOKarma::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 1000df20 : AMP2IOKarma::eventZDRSetDamageState
// Dispatches five raw damage/location words through the pre-lookup object table.
void __thiscall AMP2IOKarma::eventZDRSetDamageState(int iDamageStat, float fPercentage, FVector ZDRLocation)
{
    uint x = reinterpret_cast<const uint&>(ZDRLocation.X);
    uint damage = reinterpret_cast<const uint&>(iDamageStat);
    uint percentage = reinterpret_cast<const uint&>(fPercentage);
    NativeEventVtablePrefix* table = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    uint parameters[5];
    parameters[0] = damage;
    uint y = reinterpret_cast<const uint&>(ZDRLocation.Y);
    parameters[2] = x;
    parameters[1] = percentage;
    uint z = reinterpret_cast<const uint&>(ZDRLocation.Z);
    parameters[3] = y;
    uint name = *(const uint*)&R6ENGINE_ZDRSetDamageState;
    parameters[4] = z;
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
    using Process = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    reinterpret_cast<Process&>(table->processEventAddress)(this, function, parameters, nullptr);
}

// R6Engine.dll @ 100142f0 : AMP2IOKarma::operator=
// Copies physics state, reaction arrays, saved transforms and impact timing.
AMP2IOKarma& __thiscall AMP2IOKarma::operator=(const AMP2IOKarma& sourceObject)
{
    const AMP2IOKarma* source = &sourceObject;
    this->AR6InteractiveObject::operator=(*source);
    this->m_eReactionType = source->m_eReactionType;
    byte physics = source->SavePhysics;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x45c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x45c);
    uint firstDestinationWord = *destinationFlags; // Captured before the SavePhysics/SaveReactionType stores.
    this->SavePhysics = physics;
    this->SaveReactionType = source->SaveReactionType; // Padding +0x45b is untouched.
    uint firstDifference = firstDestinationWord ^ *sourceFlags;
    uint copiedFlags = *destinationFlags; // Native reload before the first bCollideRagDoll merge.
    copiedFlags ^= firstDifference & 1U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // bUseSafeTimeWithLevel.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // bUseSafeTimeWithSM.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // bHideBefore.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // bHideAfter.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // bHideCollision.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // bSimulationActive.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bOneTime.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // SavebCollideActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // SavebBlockActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // SavebBlockPlayers.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fMaxSimAge) = reinterpret_cast<const uint&>(source->m_fMaxSimAge);
    reinterpret_cast<uint&>(this->m_fLoseTime) = reinterpret_cast<const uint&>(source->m_fLoseTime);
    reinterpret_cast<uint&>(this->m_fCurrentLoseTime) = reinterpret_cast<const uint&>(source->m_fCurrentLoseTime);
    reinterpret_cast<uint&>(this->m_fCurrentSimAge) = reinterpret_cast<const uint&>(source->m_fCurrentSimAge);
    reinterpret_cast<uint&>(this->m_fZMin) = reinterpret_cast<const uint&>(source->m_fZMin);
    reinterpret_cast<uint&>(this->m_fScaleStartLinVel) = reinterpret_cast<const uint&>(source->m_fScaleStartLinVel);
    reinterpret_cast<uint&>(this->ImpactVolume) = reinterpret_cast<const uint&>(source->ImpactVolume);
    reinterpret_cast<uint&>(this->ImpactInterval) = reinterpret_cast<const uint&>(source->ImpactInterval);
    AssignZDRArray((FArray*)&this->m_ZDRList,
        (const FArray*)&source->m_ZDRList);
    AssignRecords4((FArray*)&this->ImpactSounds,
        (const FArray*)&source->ImpactSounds);
    AssignRecords12((FArray*)&this->m_ActorReactionList,
        (const FArray*)&source->m_ActorReactionList);
    reinterpret_cast<uint&>(this->SaveLocation.X) = reinterpret_cast<const uint&>(source->SaveLocation.X);
    reinterpret_cast<uint&>(this->SaveLocation.Y) = reinterpret_cast<const uint&>(source->SaveLocation.Y);
    reinterpret_cast<uint&>(this->SaveLocation.Z) = reinterpret_cast<const uint&>(source->SaveLocation.Z);
    reinterpret_cast<uint&>(this->SaveRotation.Pitch) = reinterpret_cast<const uint&>(source->SaveRotation.Pitch);
    reinterpret_cast<uint&>(this->SaveRotation.Yaw) = reinterpret_cast<const uint&>(source->SaveRotation.Yaw);
    reinterpret_cast<uint&>(this->SaveRotation.Roll) = reinterpret_cast<const uint&>(source->SaveRotation.Roll);
    reinterpret_cast<uint&>(this->LastImpactTime) = reinterpret_cast<const uint&>(source->LastImpactTime);
    return *this;
}

// R6Engine.dll @ 10014fb0 : AMP2IOKarma::~AMP2IOKarma
// Runs conditional cleanup before reverse array-member and InteractiveObject base destruction.
AMP2IOKarma::~AMP2IOKarma()
{
    // Compiler installs table1004e018 and protects all completed members/base with state3.
    UObject::ConditionalDestroy();
    // Implicit members: ActorReactionList498->ImpactSounds48c->ZDR480, then InteractiveObject base.
    // Native states2/1/0/-1 precede normal ea90/e970/13e20/14b60; exact private actions remain below.
}

// R6Engine.dll @ 10015030 : AMP2IOKarma::AMP2IOKarma()
// Constructs through AActor, installs the Karma table and leaves derived storage untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AMP2IOKarma* __thiscall AMP2IOKarma::AMP2IOKarma(AMP2IOKarma* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AMP2IOKarmaVirtualTable);
    return this; // Preserve original storage independently of the imported constructor's EAX.
}

// R6Engine.dll @ 10015050 : AMP2IOKarma::AMP2IOKarma
// Copies physics state, reaction arrays, saved transforms and impact timing.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AMP2IOKarma* __thiscall AMP2IOKarma::AMP2IOKarma(AMP2IOKarma* this, const AMP2IOKarma* source)
{
    using Destroy = void (__thiscall*)(void*);
    struct PendingConstruction {
        AMP2IOKarma* object;
        int stage;
        bool active;
        // Releases only completed members represented in the native copy map, then the completed base.
        ~PendingConstruction() noexcept(false) {
            if (!active) return;
            if (stage >= 2) (*(Destroy)&ForwardWordArrayDestruction)((byte*)object + 0x48c);
            if (stage >= 1) (*(Destroy)&ForwardZDRArrayDestruction)((byte*)object + 0x480);
            (*(Destroy)&AR6InteractiveObjectDestructorNativeEntry)(object);
        }
    }; // Inferred lifetime view; no completed ActorReactionList action exists in this native map.
    AR6InteractiveObject::AR6InteractiveObject(this, source);
    *(uint*)this = ((uint)&AMP2IOKarmaVirtualTable);
    this->m_eReactionType = source->m_eReactionType;
    byte physics = source->SavePhysics;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x45c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x45c);
    uint firstDestinationWord = *destinationFlags; // Captured before the SavePhysics/SaveReactionType stores.
    this->SavePhysics = physics;
    this->SaveReactionType = source->SaveReactionType; // Padding +0x45b is untouched.
    uint firstDifference = firstDestinationWord ^ *sourceFlags;
    uint copiedFlags = *destinationFlags; // Native reload before the first bCollideRagDoll merge.
    copiedFlags ^= firstDifference & 1U;
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // bUseSafeTimeWithLevel.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // bUseSafeTimeWithSM.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // bHideBefore.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10U; // bHideAfter.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20U; // bHideCollision.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40U; // bSimulationActive.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80U; // m_bOneTime.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100U; // SavebCollideActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200U; // SavebBlockActors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400U; // SavebBlockPlayers.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fMaxSimAge) = reinterpret_cast<const uint&>(source->m_fMaxSimAge);
    reinterpret_cast<uint&>(this->m_fLoseTime) = reinterpret_cast<const uint&>(source->m_fLoseTime);
    reinterpret_cast<uint&>(this->m_fCurrentLoseTime) = reinterpret_cast<const uint&>(source->m_fCurrentLoseTime);
    uint currentSimulationAgeWord = reinterpret_cast<const uint&>(source->m_fCurrentSimAge);
    PendingConstruction cleanup{this, 0, true}; // State0 begins after the raw current-age source read.
    reinterpret_cast<uint&>(this->m_fCurrentSimAge) = currentSimulationAgeWord;
    reinterpret_cast<uint&>(this->m_fZMin) = reinterpret_cast<const uint&>(source->m_fZMin);
    reinterpret_cast<uint&>(this->m_fScaleStartLinVel) = reinterpret_cast<const uint&>(source->m_fScaleStartLinVel);
    reinterpret_cast<uint&>(this->ImpactVolume) = reinterpret_cast<const uint&>(source->ImpactVolume);
    reinterpret_cast<uint&>(this->ImpactInterval) = reinterpret_cast<const uint&>(source->ImpactInterval);
    CopyConstructZDRArray((FArray*)&this->m_ZDRList,
        (const FArray*)&source->m_ZDRList);
    cleanup.stage = 1;
    CopyConstructRecords4((FArray*)&this->ImpactSounds,
        (const FArray*)&source->ImpactSounds);
    cleanup.stage = 2;
    CopyConstructRecords12((FArray*)&this->m_ActorReactionList,
        (const FArray*)&source->m_ActorReactionList);
    reinterpret_cast<uint&>(this->SaveLocation.X) = reinterpret_cast<const uint&>(source->SaveLocation.X);
    reinterpret_cast<uint&>(this->SaveLocation.Y) = reinterpret_cast<const uint&>(source->SaveLocation.Y);
    reinterpret_cast<uint&>(this->SaveLocation.Z) = reinterpret_cast<const uint&>(source->SaveLocation.Z);
    reinterpret_cast<uint&>(this->SaveRotation.Pitch) = reinterpret_cast<const uint&>(source->SaveRotation.Pitch);
    reinterpret_cast<uint&>(this->SaveRotation.Yaw) = reinterpret_cast<const uint&>(source->SaveRotation.Yaw);
    reinterpret_cast<uint&>(this->SaveRotation.Roll) = reinterpret_cast<const uint&>(source->SaveRotation.Roll);
    reinterpret_cast<uint&>(this->LastImpactTime) = reinterpret_cast<const uint&>(source->LastImpactTime);
    cleanup.active = false; // Transfer completed ownership without inventing a final native state3 write.
    return this;
}

// R6Engine.dll @ 10015290 : AMP2IOKarma::DeletingDestructor
// Destroys one AMP2IOKarma object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AMP2IOKarma::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AMP2IOKarma* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AMP2IOKarmaDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4c0, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AMP2IOKarma::~AMP2IOKarma();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4c0);
    }
    return object;
}

// R6Engine.dll @ 10016130 : AMP2IOKarma::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AMP2IOKarma::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AMP2IOKarmaConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001c230 : AMP2IOKarma::execMP2IOKarmaAllNativeFct
// Evaluates four script arguments, then increments/decrements the current level counter for operation1/0.
// Native ABI view retains the incoming frame word for the late-read diagnostic frame pointer.
void __thiscall AMP2IOKarma::execMP2IOKarmaAllNativeFct(FFrame* frame, void* unusedResult)
{
    using Step = void (__thiscall*)(UObject*, FFrame*, void*);
    byte** code = &frame->Code;
    byte* cursor = *code;
    int operation = 0;
    byte opcode = *cursor;
    *code = cursor + 1; // The first decode/advance precedes native state0.
    // IAT points directly to GNatives, not another table-pointer variable.
    Step* firstTable = *(Step**)&CoreGNativesImport;
    UObject* firstReceiver = frame->Object;
    try {
        firstTable[opcode](firstReceiver, frame, &operation);
        cursor = *code;
        UObject* receiver = frame->Object;
        AActor* owner = nullptr;
        opcode = *cursor;
        *code = cursor + 1;
        Step* table = *(Step**)&CoreGNativesImport;
        table[opcode](receiver, frame, &owner);
        cursor = *code;
        receiver = frame->Object;
        float varInt = 0.0f; // Matching1.60 declares optional _var_int as FloatProperty.
        opcode = *cursor;
        *code = cursor + 1;
        table = *(Step**)&CoreGNativesImport;
        table[opcode](receiver, frame, &varInt);
        cursor = *code;
        receiver = frame->Object;
        float varFloat = 0.0f;
        opcode = *cursor;
        *code = cursor + 1;
        table = *(Step**)&CoreGNativesImport;
        table[opcode](receiver, frame, &varFloat);
        cursor = *code + 1; // Skip the native end-parameters byte without validation.
        *code = cursor;
        if (*cursor == 0x42) {
            receiver = frame->Object;
            *code = cursor + 1;
            table = *(Step**)&CoreGNativesImport;
            table[0x42](receiver, frame, nullptr);
        }
        // Later operand/debug handlers may have changed the operation word and this object's level.
        if (operation == 0 || operation == 1) {
            byte* level = reinterpret_cast<byte*&>(this->XLevel);
            uint* count = (uint*)(level + 0x10188);
            if (operation == 0) --*count;
            else ++*count;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        using Report = void (__cdecl*)(const ushort*, ...);
        using FullName = const ushort* (__thiscall*)(const UObject*, ushort*);
        Report report = *(Report*)&CoreAppUnwindfImport;
        report(unwindStringFormat, nativeTextAMP2IOKarmaExecMP2IOKarmaAllNativeFct);
        byte* activeFrame = (byte*)frame; // Native reloads the incoming frame after the first report.
        const UObject* node = *(const UObject**)(activeFrame + 4);
        byte* currentCode = *(byte**)(activeFrame + 0x0c);
        byte* scriptData = *(byte**)((const byte*)node + 0x4c);
        FullName fullName = *(FullName*)&UObjectGetFullNameImport;
        uint byteOffset = (uint)currentCode - (uint)scriptData; // Snapshot before either name call; wraps natively.
        const ushort* nodeName = fullName(node, nullptr);
        const UObject* context = *(const UObject**)(activeFrame + 8);
        const ushort* contextName = fullName(context, nullptr); // Cached provider; names remain borrowed pointers.
        report(nativeTextSS04X, contextName, nodeName, byteOffset);
        throw;
    }
}

// R6Engine.dll @ 1001c331 : KarmaExecCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x28 through EBP-0x24.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaExecCatchPointer(void)
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

// R6Engine.dll @ 1001c345 : KarmaExecCatchContext
// Reports exec context and a captured bytecode offset through the inherited native frame.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaExecCatchContext(void)
{
    __asm {
        mov edi,dword ptr [CoreAppUnwindfImport]
        push offset nativeTextAMP2IOKarmaExecMP2IOKarmaAllNativeFct
        push offset unwindStringFormat
        call edi
        mov esi,dword ptr [ebp+0x8]
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr [UObjectGetFullNameImport]
        add esp,0x8
        sub edx,eax
        push edx
        push 0x0
        call ebx
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx
        push eax
        push offset nativeTextSS04X
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044290 : KarmaExecExceptionHandler
// Supplies the exec FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl KarmaExecExceptionHandler(void)
{
    __asm {
        mov eax,offset karmaExecFuncInfo
        jmp __CxxFrameHandler
    }
}

// Inferred PE32 ZDR record view; field names and offsets agree with the matching script struct.
struct NativeZDRRecord
{
    byte m_eZDRType; // +0x00
    byte m_eZDRStat; // +0x01
    byte untouchedPadding[2]; // +0x02: not copied or initialized by editor rendering.
    float m_fZDRRadius; // +0x04
    FVector m_vZDRLocation; // +0x08
    NativeArrayHeader32 m_ZDRSoundList; // +0x14: owned array of 16-byte sound records.
    int m_iZDRDamageStat; // +0x20
    float m_fZDRImpactInterval; // +0x24
    float m_fZDRLastImpactTime; // +0x28
};

// R6Engine.dll @ 1001c630 : AMP2IOKarma::KMP2DynKarmaInterface
// Dispatches native Karma queries, simulation ticks, timed ZDR sounds and swept damage/status updates.
int __thiscall AMP2IOKarma::KMP2DynKarmaInterface(int operationId, FVector vectorArgument, FRotator rotationArgument,
    AActor* actorArgument)
{
    byte* object = (byte*)this;
    byte* engine = **(byte***)&EngineGPEngineImport;
    void* audio = *(void**)(engine + 0x48); // Captured even for queries, before native state0.
    // Native reuses these by-value argument slots as scratch.
    uint& operationScratch = reinterpret_cast<uint&>(operationId);
    uint& actorScratch = reinterpret_cast<uint&>(actorArgument);
    using Size = float10 (__thiscall*)(const FVector*); // Native unspilled ST0 view; export declares float.
    using Sound = void (__thiscall*)(void*, AActor*, uint, int, int); // Descriptive audio-slot0x84 ABI.
    auto playSound = [&](uint sound) {
        byte* table = *(byte**)audio; // Captured receiver, current vtable/slot on each call.
        (*(Sound*)(table + 0x84))(audio, this, sound, 3, 0);
    };
    auto makeCoords = [&](FCoords* output, const FRotator* rotation) {
        const FCoords* unit = (const FCoords*)(*(const byte**)&CoreGMathImport + 0x18);
        // Hidden output is used; EAX is ignored.
        *output = *unit / *rotation;
    };
    auto translate = [](FVector* point, const FVector* origin) {
        float10 z = (float10)point->Z + (float10)origin->Z;
        float10 y = (float10)point->Y + (float10)origin->Y;
        float10 x = (float10)point->X + (float10)origin->X;
        point->X = (float)x;
        point->Y = (float)y;
        point->Z = (float)z; // Native X/Y/Z single-precision spills after Z/Y/X additions.
    };
    try {
        if (operationId == 10) return (*(const uint*)(object + 0x45c) >> 1) & 1U; // bUseSafeTimeWithLevel.
        if (operationId == 11) return (*(const uint*)(object + 0x45c) >> 2) & 1U; // bUseSafeTimeWithSM.
        if (operationId == 7) return (*(const byte*)(object + 0x45c) & 6U) != 0 ? 1 : 0;
        if (operationId == 6) return *(const uint*)(object + 0x45c) & 1U; // bCollideRagDoll.
        if (operationId == 5) { this->AMP2IOKarma::eventReinitSimulation(0); return 1; }
        // m_eReactionType.
        if (operationId == 4) return reinterpret_cast<const byte&>(this->m_eReactionType) != 0 ? 1 : -1;
        if (operationId == 2) { reinterpret_cast<byte&>(this->m_eReactionType) = 0; return 1; }
        if (operationId == 3 || operationId == 33) {
            if (operationId == 3 && (*(const byte*)(object + 0x45c) & 0x40U) == 0) return 1;
            float10 zMin = (float10)this->m_fZMin; // +0x470, not maximum simulation age.
            if (zMin > (float10)nativeDoubleMinus10000000 &&
                (float10)this->Location.Z < (float10)this->m_fZMin) {
                this->AMP2IOKarma::eventStopSimulation(1);
                return -2;
            }
            if (operationId == 33 && (*(const byte*)(object + 0x45c) & 0x40U) == 0) return 1;
            float10 age = (float10)this->m_fCurrentSimAge - (float10)vectorArgument.X;
            this->m_fCurrentSimAge = (float)age; // Store single precision, compare the unspilled value.
            if (age < (float10)nativeFloatZero) { this->AMP2IOKarma::eventStopSimulation(0); return -2; }
            return 1;
        }
        if (operationId == 9) {
            alignas(FCoords) byte coords[0x30]; // Native EBP-0x98.
            makeCoords((FCoords*)coords, &this->Rotation);
            actorScratch = 0; // Actor argument slot becomes the live loop index.
            while ((int)actorScratch < reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).count) {
                uint offset = actorScratch * 0x2cU;
                NativeZDRRecord* record = reinterpret_cast<NativeZDRRecord*>(
                    reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress + offset);
                if (record->m_eZDRType == 3 && record->m_ZDRSoundList.count != 0) {
                    FVector point;
                    point =
                        record->m_vZDRLocation.TransformVectorByTranspose(*reinterpret_cast<const FCoords*>(coords));
                    translate(&point, &this->Location);
                    float10 dz = (float10)point.Z - (float10)vectorArgument.Z;
                    float10 dy = (float10)point.Y - (float10)vectorArgument.Y;
                    float10 dx = (float10)point.X - (float10)vectorArgument.X;
                    FVector delta = {(float)dx, (float)dy, (float)dz};
                    float10 distance = reinterpret_cast<Size&>(FVectorSizeImport)(&delta);
                    // Native argument-slot spill is not reloaded for compare.
                    reinterpret_cast<float&>(operationScratch) = (float)distance;
                    if (distance < (float10)record->m_fZDRRadius) {
                        float10 next = (float10)record->m_fZDRLastImpactTime;
                        byte* level = reinterpret_cast<byte*&>(this->XLevel);
                        next += (float10)record->m_fZDRImpactInterval;
                        if (next < (float10)*(const double*)(level + 0xd4)) {
                            uint sound =
                                *(const uint*)(reinterpret_cast<const byte*>(record->m_ZDRSoundList.dataAddress) + 4);
                            playSound(sound);
                            // Time and Data are reloaded after the audio callback.
                            level = reinterpret_cast<byte*&>(this->XLevel);
                            double time = *(const double*)(level + 0xd4);
                            byte* currentRecords = reinterpret_cast<byte*>(
                            reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress);
                            *(float*)(currentRecords + offset + 0x28) = (float)time;
                        }
                    }
                }
                ++actorScratch;
            }
            return 1;
        }
        if (operationId == 8) {
            int index = 0;
            while (index < reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).count) {
                NativeZDRRecord* original = reinterpret_cast<NativeZDRRecord*>(
                    reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress + (uint)index * 0x2cU);
                if (original->m_eZDRType == 2 && original->m_ZDRSoundList.count != 0) {
                    NativeZDRRecord* selected = original;
                    byte* first = reinterpret_cast<byte*>(original->m_ZDRSoundList.dataAddress);
                    if (first[1] == 1) {
                        AMP2IOKarma* linked =
                            reinterpret_cast<AMP2IOKarma*>(CastToAMP2IOKarma(*(const int*)(first + 8)));
                        if (linked == nullptr ||
                            reinterpret_cast<const NativeArrayHeader32&>(linked->m_ZDRList).count == 0) return 0;
                        // Always the linked object's first record.
                        selected = reinterpret_cast<NativeZDRRecord*>(
                            reinterpret_cast<const NativeArrayHeader32&>(linked->m_ZDRList).dataAddress);
                    }
                    int entryIndex = 0;
                    for (;;) {
                        if (entryIndex >= selected->m_ZDRSoundList.count) return 0;
                        const byte* entry =
                            reinterpret_cast<const byte*>(selected->m_ZDRSoundList.dataAddress) +
                                (uint)entryIndex * 16U;
                        uint tagWord = *(const uint*)entry;
                        uint soundWord = *(const uint*)(entry + 4);
                        AActor* actor = *(AActor* const*)(entry + 8);
                        // All four native words are read before testing actor.
                        uint volumeWord = *(const uint*)(entry + 12);
                        if (actor != nullptr && actorScratch != 0 && actor != this &&
                            (uint)actor == actorScratch) {
                            operationScratch = (operationScratch & 0x00ffffffU) | (tagWord << 24);
                            break;
                        }
                        entryIndex = (int)((uint)entryIndex + 1U);
                    }
                    entryIndex = 0;
                    while (entryIndex < selected->m_ZDRSoundList.count) {
                        const byte* entry =
                            reinterpret_cast<const byte*>(selected->m_ZDRSoundList.dataAddress) +
                                (uint)entryIndex * 16U;
                        uint tagWord = *(const uint*)entry;
                        uint sound = *(const uint*)(entry + 4);
                        uint actorWord = *(const uint*)(entry + 8);
                        uint volumeWord = *(const uint*)(entry + 12);
                        if (sound != 0 && (byte)tagWord == (byte)(operationScratch >> 24) &&
                            (float10)vectorArgument.X > (float10)reinterpret_cast<const float&>(volumeWord)) {
                            float10 next = (float10)original->m_fZDRImpactInterval;
                            byte* level = reinterpret_cast<byte*&>(this->XLevel);
                            next += (float10)original->m_fZDRLastImpactTime;
                            if (!(next < (float10)*(const double*)(level + 0xd4))) return 1;
                            playSound(sound);
                            AActor* incomingActor = reinterpret_cast<AActor*>(actorScratch);
                            actorScratch = reinterpret_cast<const uint&>(incomingActor->Name);
                            operationScratch = reinterpret_cast<const uint&>(this->Name);
                            const ushort* actorText = reinterpret_cast<const FName*>(&actorScratch)->operator*();
                            const ushort* thisText = reinterpret_cast<const FName*>(&operationScratch)->operator*();
                            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
                            log->FOutputDevice::Logf(nativeTextZDRDFSSoundS,
                                entryIndex,
                                (double)vectorArgument.X, thisText, actorText);
                            level = reinterpret_cast<byte*&>(this->XLevel);
                            original->m_fZDRLastImpactTime = (float)*(const double*)(level + 0xd4);
                            return 1; // Captured original record, even when the audio/log callbacks replace Data.
                        }
                        entryIndex = (int)((uint)entryIndex + 1U);
                    }
                }
                index = (int)((uint)index + 1U);
            }
            return 0;
        }
        if (operationId != 1) return 1;
        if ((*(const byte*)(object + 0x45c) & 0x40U) == 0) {
            byte* level = reinterpret_cast<byte*&>(this->XLevel);
            ++*(uint*)(level + 0x10188);
            uint flags = *(const uint*)(object + 0x45c);
            uint maximumAge = reinterpret_cast<const uint&>(this->m_fMaxSimAge);
            reinterpret_cast<uint&>(this->m_fCurrentSimAge) = maximumAge;
            *(uint*)(object + 0x45c) = flags | 0x40U;
        }
        alignas(FCoords) byte inputCoords[0x30], currentCoords[0x30]; // EBP-0xc8/-0xf8 hidden results.
        makeCoords((FCoords*)inputCoords, &rotationArgument);
        makeCoords((FCoords*)currentCoords, &this->Rotation);
        actorScratch = 0; // One timed sound at most across this sweep.
        int index = 0;
        while (index < reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).count) {
            NativeZDRRecord* record = reinterpret_cast<NativeZDRRecord*>(
                reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress + (uint)index * 0x2cU);
            operationScratch = (uint)index * 0x2cU; // Raw byte offset, not an int/float conversion.
            if (record->m_eZDRType != 2) {
                const FVector* local = &record->m_vZDRLocation;
                FVector endpoint, start;
                endpoint = local->TransformVectorByTranspose(*reinterpret_cast<const FCoords*>(inputCoords));
                translate(&endpoint, &vectorArgument);
                start = local->TransformVectorByTranspose(*reinterpret_cast<const FCoords*>(currentCoords));
                translate(&start, &this->Location);
                alignas(FCheckResult) byte hitStorage[0x30]; // Only the native constructor initializes this storage.
                FCheckResult* hit = (FCheckResult*)hitStorage;
                InitializeCheckResult(hit, 1.0f, nullptr); // Return pointer is ignored.
                float10 radius = (float10)record->m_fZDRRadius;
                byte* level = reinterpret_cast<byte*&>(this->XLevel);
                float extentZ = (float)radius;
                byte* levelTable = *(byte**)level;
                float extentY = (float)radius, extentX = (float)radius;
                FVector extent = {extentX, extentY, extentZ};
                using Trace = void (__thiscall*)(void*, FCheckResult*, AActor*, const FVector*, const FVector*, uint,
                    FVector);
                (*(Trace*)(levelTable + 0xcc))(level, hit, this, &start, &endpoint, 0xdf, extent);
                byte kind = record->m_eZDRType; // Reload after tracing, using the captured record pointer.
                if (kind == 1 && hit->Actor != nullptr) {
                    uint damageState = reinterpret_cast<const uint&>(record->m_iZDRDamageStat);
                    this->AMP2IOKarma::eventZDRSetDamageState(damageState, 100.0f, start);
                    return 2;
                }
                if (kind == 0) {
                    if (hit->Actor != nullptr) {
                        float10 next = (float10)record->m_fZDRImpactInterval;
                        level = reinterpret_cast<byte*&>(this->XLevel);
                        next += (float10)record->m_fZDRLastImpactTime;
                        if (next < (float10)*(const double*)(level + 0xd4) &&
                            record->m_eZDRStat == 0 && actorScratch == 0 &&
                            record->m_ZDRSoundList.count != 0) {
                            uint sound =
                                *(const uint*)(reinterpret_cast<const byte*>(record->m_ZDRSoundList.dataAddress) + 4);
                            playSound(sound);
                            level = reinterpret_cast<byte*&>(this->XLevel);
                            double time = *(const double*)(level + 0xd4);
                            actorScratch = 1;
                            record->m_fZDRLastImpactTime = (float)time; // Captured record for timestamp.
                        }
                        byte* currentRecords = reinterpret_cast<byte*>(
                            reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress);
                        currentRecords[operationScratch + 1] = 1; // Current Data for the status byte.
                    } else {
                        byte* currentRecords = reinterpret_cast<byte*>(
                            reinterpret_cast<const NativeArrayHeader32&>(this->m_ZDRList).dataAddress);
                        currentRecords[operationScratch + 1] = 0;
                    }
                }
            }
            index = (int)((uint)index + 1U);
        }
        return 1;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"KMP2DynKarmaInterface::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001cd60 : KarmaInterfaceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x68 through EBP-0x54.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaInterfaceCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x68]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x54]
        push ecx
        mov dword ptr [ebp-0x54],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001cd74 : KarmaInterfaceCatchContext
// Reports the interface's native rendering diagnostic and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaInterfaceCatchContext(void)
{
    __asm {
        push offset nativeTextKMP2DynKarmaInterfaceRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100442d0 : KarmaInterfaceExceptionHandler
// Supplies the interface FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl KarmaInterfaceExceptionHandler(void)
{
    __asm {
        mov eax,offset karmaInterfaceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001cda0 : AMP2IOKarma::RenderEditorInfo
// Draws selected Karma ZDR spheres from copied local records and rotated positions.
void __thiscall AMP2IOKarma::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* unusedInterface,
    FDynamicActor* unusedActor)
{
    // bSelected before state0.
    bool selected = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0xac) & 0x4000U) != 0;
    using SetTransform = void (__thiscall*)(FRenderInterface*, int, FMatrix);
    using Destroy = void (__thiscall*)(FLineBatcher*);
    struct PendingBatcher {
        FLineBatcher* batcher;
        bool active;
        // Disables cleanup before normal batcher destruction.
        void Finish() {
            active = false;
            (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
        // Releases the completed batcher on an escaping provider exception.
        ~PendingBatcher() noexcept(false) {
            if (active) (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
    };
    struct PendingRecord {
        void* record;
        bool active;
        // Drops record state2 before normal nested-array destruction.
        void Finish() {
            active = false;
            DestroySixteenByteArrayStorage((FArray*)((byte*)record + 0x14));
        }
        // Uses the exact record-array tail associated with native state2.
        ~PendingRecord() noexcept(false) {
            if (active) DestroyRecordArrayAt14(record);
        }
    }; // Inferred lifetime views; exact frame/action maps remain explicit below.
    try {
        if (!selected) return;
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* render = *(FRenderInterface**)(owner + 0x164);
        const uint* identity = *(const uint**)&FMatrixIdentityImport;
        byte* renderTable = *(byte**)render; // Captured before copying the argument matrix.
        alignas(FMatrix) uint identityCopy[16];
        for (uint i = 0; i != 16; ++i) identityCopy[i] = identity[i];
        (*(SetTransform*)(renderTable + 0x34))(render, 0, *(const FMatrix*)identityCopy);
        owner = *(byte**)((byte*)scene + 4);
        render = *(FRenderInterface**)(owner + 0x164); // Reload after SetTransform.
        alignas(FLineBatcher) byte batcherStorage[0x24]; // Native EBP-0x90.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(render, 1, 0); // Ignore returned EAX.
        const FRotator* rotation = &this->Rotation;
        alignas(FCoords) byte coordsStorage[0x30]; // Native EBP-0xc0; hidden output address is authoritative.
        const FCoords* unitCoords = (const FCoords*)(*(const byte**)&CoreGMathImport + 0x18);
        PendingBatcher batcherCleanup{batcher, true}; // State1 follows captured GMath/argument setup.
        *reinterpret_cast<FCoords*>(coordsStorage) = *unitCoords / *rotation;
        int index = 0;
        while (index < reinterpret_cast<NativeArrayHeader32&>(this->m_ZDRList).count) {
            const NativeZDRRecord* input = reinterpret_cast<const NativeZDRRecord*>(
                reinterpret_cast<NativeArrayHeader32&>(this->m_ZDRList).dataAddress + (uint)index * 0x2cU);
            alignas(FArray) byte record[0x2c]; // Native EBP-0x68; padding +2/+3 is left untouched.
            NativeZDRRecord& local = *reinterpret_cast<NativeZDRRecord*>(record);
            local.m_eZDRType = input->m_eZDRType;
            local.m_eZDRStat = input->m_eZDRStat;
            reinterpret_cast<uint&>(local.m_fZDRRadius) = reinterpret_cast<const uint&>(input->m_fZDRRadius);
            reinterpret_cast<uint&>(local.m_vZDRLocation.X) = reinterpret_cast<const uint&>(input->m_vZDRLocation.X);
            reinterpret_cast<uint&>(local.m_vZDRLocation.Y) = reinterpret_cast<const uint&>(input->m_vZDRLocation.Y);
            reinterpret_cast<uint&>(local.m_vZDRLocation.Z) = reinterpret_cast<const uint&>(input->m_vZDRLocation.Z);
            CopyConstructRecords16(reinterpret_cast<FArray*>(&local.m_ZDRSoundList),
                reinterpret_cast<const FArray*>(&input->m_ZDRSoundList));
            // Three tail words reload after nested copy.
            reinterpret_cast<uint&>(local.m_iZDRDamageStat) = reinterpret_cast<const uint&>(input->m_iZDRDamageStat);
            reinterpret_cast<uint&>(local.m_fZDRImpactInterval) =
                reinterpret_cast<const uint&>(input->m_fZDRImpactInterval);
            reinterpret_cast<uint&>(local.m_fZDRLastImpactTime) =
                reinterpret_cast<const uint&>(input->m_fZDRLastImpactTime);
            FVector transformed; // Native EBP-0x1c, with no implicit initialization.
            PendingRecord recordCleanup{record, true}; // State2 follows all tail reads and transform argument setup.
            transformed =
                local.m_vZDRLocation.TransformVectorByTranspose(*reinterpret_cast<const FCoords*>(coordsStorage));
            float10 centerZ = (float10)transformed.Z + (float10)this->Location.Z;
            float10 centerY = (float10)transformed.Y + (float10)this->Location.Y;
            alignas(FPlane) uint planeWords[4] = {0x3f800000, 0x3f400000, 0, 0};
            float10 centerX = (float10)transformed.X + (float10)this->Location.X;
            float x = (float)centerX; // First native single-precision spill.
            ((uint*)&transformed)[0] = reinterpret_cast<const uint&>(x);
            // Captured before the remaining spills/color construction.
            uint radiusWord = reinterpret_cast<const uint&>(local.m_fZDRRadius);
            float y = (float)centerY, z = (float)centerZ;
            ((uint*)&transformed)[2] = reinterpret_cast<const uint&>(z);
            ((uint*)&transformed)[1] = reinterpret_cast<const uint&>(y);
            // Native PUSH of Y reserves the color argument; constructor EAX is ignored.
            uint colorWord = reinterpret_cast<const uint&>(y);
            ::new (reinterpret_cast<void*>(&colorWord)) FColor(*reinterpret_cast<const FPlane*>(planeWords));
            FVector center;
            uint centerXWord = ((const uint*)&transformed)[0];
            uint centerYWord = ((const uint*)&transformed)[1];
            ((uint*)&center)[0] = centerXWord;
            uint centerZWord = ((const uint*)&transformed)[2];
            ((uint*)&center)[1] = centerYWord;
            ((uint*)&center)[2] = centerZWord;
            batcher->FLineBatcher::DrawSphere(
                center, *(const FColor*)&colorWord, reinterpret_cast<const float&>(radiusWord), 16);
            recordCleanup.Finish();
            index = (int)((uint)index + 1U);
        }
        batcherCleanup.Finish();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"KMP2DynKarmaInterface::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001cf76 : KarmaRenderCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x6c through EBP-0x2c.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaRenderCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x6c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x2c]
        push eax
        mov dword ptr [ebp-0x2c],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001cf8a : KarmaRenderCatchContext
// Reports the native Karma rendering diagnostic and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl KarmaRenderCatchContext(void)
{
    __asm {
        push offset nativeTextAMP2IOKarmaRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043ad0 : KarmaDestructionState0Cleanup
// Tail-destroys the completed InteractiveObject base through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6InteractiveObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043ad8 : KarmaDestructionState1Cleanup
// Tail-destroys the completed Karma member at+0x480 through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x480
        jmp ForwardZDRArrayDestruction
    }
}

// R6Engine.dll @ 10043ae6 : KarmaDestructionState2Cleanup
// Tail-destroys the completed Karma member at+0x48c through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaDestructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x48c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 10043af4 : KarmaDestructionState3Cleanup
// Tail-destroys the completed Karma member at+0x498 through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaDestructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x498
        jmp ForwardTwelveByteArrayDestruction
    }
}

// R6Engine.dll @ 10043b10 : KarmaCopyState0Cleanup
// Tail-destroys the completed InteractiveObject base through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6InteractiveObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043b18 : KarmaCopyState1Cleanup
// Tail-destroys the completed Karma member at+0x480 through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaCopyState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x480
        jmp ForwardZDRArrayDestruction
    }
}

// R6Engine.dll @ 10043b26 : KarmaCopyState2Cleanup
// Tail-destroys the completed Karma member at+0x48c through inherited EBP-0x10.
__declspec(naked) void __cdecl KarmaCopyState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x48c
        jmp ForwardWordArrayDestruction
    }
}

// R6Engine.dll @ 100442e0 : KarmaRenderState1Cleanup
// Tail-destroys the renderer's completed batcher through its inherited EBP-0x90 binding.
__declspec(naked) void __cdecl KarmaRenderState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x90]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 100442ec : KarmaRenderState2Cleanup
// Tail-enters cleanup of the copied ZDR record at inherited EBP-0x68.
__declspec(naked) void __cdecl KarmaRenderState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x68]
        jmp DestroyRecordArrayAt14
    }
}

// R6Engine.dll @ 100442f4 : KarmaRenderExceptionHandler
// Supplies rendering's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl KarmaRenderExceptionHandler(void)
{
    __asm {
        mov eax,offset karmaRenderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100481c0 : DestroyAMP2IOKarmaClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAMP2IOKarmaClassMetadata(void)
{
    __asm {
        mov ecx,offset AMP2IOKarma::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047110 : InitializeAMP2IOKarmaClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAMP2IOKarmaClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AMP2IOKarma::PrivateStaticClass, 0, 0x4c0, 0,
        &AR6InteractiveObject::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextMP2IOKarma, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AMP2IOKarma::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAMP2IOKarmaClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10047190 : PublishAMP2IOKarmaAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAMP2IOKarmaAutoClass(void)
{
    autoclassAMP2IOKarma = &AMP2IOKarma::PrivateStaticClass;
}

// R6Engine.dll @ 100471e0 : RegisterAMP2IOKarmaMP2IOKarmaAllNativeFctNative
// Registers native index0xfaa using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAMP2IOKarmaMP2IOKarmaAllNativeFctNative(void)
{
    AMP2IOKarmaMP2IOKarmaAllNativeFctRegistrationResult =
        GRegisterNative(0xfaa, intAMP2IOKarmaexecMP2IOKarmaAllNativeFct);
}

// R6Engine.dll @ 10043b02 : KarmaDestructionExceptionHandler
// Supplies the exact Karma destruction FuncInfo without changing the dispatcher frame.
__declspec(naked) void __cdecl KarmaDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset karmaDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043b34 : KarmaCopyExceptionHandler
// Supplies the exact Karma copy FuncInfo without changing the dispatcher frame.
__declspec(naked) void __cdecl KarmaCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset karmaCopyFuncInfo
        jmp __CxxFrameHandler
    }
}

// Raw native array providers for the script-bound 0x2c-byte stZDR record.

// Native helper declarations match the canonical definitions below.
void __thiscall DestroyZDRArray(FArray* array);

// R6Engine.dll @ 100139f0 : EmptyZDRArray
// Destroys live records, clears the count and reallocates storage to the requested capacity.
void __thiscall EmptyZDRArray(FArray* array, int reservedCount)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    uint index = 0;
    uint offset = 0;
    int liveCount = arrayHeaderView->count;
    while ((int)index < liveCount) {
        void* record = (void*)(arrayHeaderView->dataAddress + offset);
        DestroyRecordArrayAt14(record);
        liveCount = arrayHeaderView->count;
        ++index;
        offset += 0x2cU;
    }
    int capacity = reservedCount; // Sample the argument after record destruction and before either header store.
    arrayHeaderView->count = 0;
    arrayHeaderView->capacity = capacity;
    array->FArray::Realloc(0x2c);
}

// R6Engine.dll @ 10013b10 : CopyConstructZDRArray
// Reserves the captured count and constructs records with a delayed outer-storage cleanup guard.
FArray* __thiscall CopyConstructZDRArray(FArray* destination, const FArray* source)
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
    destination->FArray::Realloc(0x2c);
    destinationHeaderView->count = 0;
    uint index = 0;
    uint offset = 0;
    int liveCount = sourceHeaderView->count;
    cleanup.active = true; // State0 follows the live count comparison, not initial header setup or Realloc.
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 0x2c);
        void* output = (void*)(destinationHeaderView->dataAddress + (uint)addedIndex * 0x2cU);
        if (output != nullptr) {
            const void* input = (const void*)(sourceHeaderView->dataAddress + offset);
            CopyConstructZDR(output, input);
        }
        liveCount = sourceHeaderView->count;
        ++index;
        offset += 0x2cU;
    }
    cleanup.active = false; // Successful ownership transfer; no extra native state write is implied.
    return destination;
}

// R6Engine.dll @ 10013c30 : RemoveZDRRecords
// Validates a captured start, destroys its captured range and removes with the later count argument.
void __thiscall RemoveZDRRecords(FArray* array, int index, int count)
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
        uint offset = (uint)first * 0x2cU;
        uint remaining = (uint)end - (uint)first;
        do {
            DestroyRecordArrayAt14((void*)(arrayHeaderView->dataAddress + offset));
            offset += 0x2cU;
        } while (--remaining != 0);
    }
    // Count is resampled after reporting/destruction callbacks.
    array->FArray::Remove(first, count, 0x2c);
}

// R6Engine.dll @ 10013cd0 : AssignZDRArray
// Replaces distinct arrays and copies records while following current source headers and destination storage.
FArray* __thiscall AssignZDRArray(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    if (destination == source) return destination;
    EmptyZDRArray(destination, sourceHeaderView->count);
    uint index = 0;
    uint offset = 0;
    int liveCount = sourceHeaderView->count;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 0x2c);
        void* output = (void*)(destinationHeaderView->dataAddress + (uint)addedIndex * 0x2cU);
        if (output != nullptr) {
            const void* input = (const void*)(sourceHeaderView->dataAddress + offset);
            CopyConstructZDR(output, input);
        }
        liveCount = sourceHeaderView->count;
        ++index;
        offset += 0x2cU;
    }
    return destination;
}

// R6Engine.dll @ 10013e20 : DestroyZDRArray
// Destroys the captured record count and releases outer storage on normal or exceptional exit.
void __thiscall DestroyZDRArray(FArray* array)
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
    RemoveZDRRecords(array, 0, count);
    cleanup.active = false;
    // State-1 prevents a second cleanup if storage destruction throws.
    array->FArray::~FArray();
}

// R6Engine.dll @ 10013f80 : ForwardZDRArrayDestruction
// Tail-enters ZDR array destruction with the original ECX receiver and return frame.
__declspec(naked) void __thiscall ForwardZDRArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyZDRArray
    }
}

// R6Engine.dll @ 1000d6b0 : CopyConstructRecords12
// Reserves the captured source count and copies three interleaved raw words with delayed outer-storage protection.
FArray* __thiscall CopyConstructRecords12(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->dataAddress = 0;
    destinationHeaderView->count = initialCount;
    destinationHeaderView->capacity = initialCount;
    destination->FArray::Realloc(12);
    destinationHeaderView->count = 0;
    int liveCount = sourceHeaderView->count;
    uint index = 0;
    struct PendingStorage {
        FArray* array;
        bool active;
        // Releases outer FArray storage only after the delayed native state0 was entered.
        ~PendingStorage() noexcept(false) {
            if (active) {
                using DestroyStorage = void (__thiscall*)(FArray*);
                (*(DestroyStorage*)&FArrayDestructorImport)(array);
            }
        }
    } cleanup{destination, true}; // Shared43a20/43a29/584a8; no cleanup applies to an escaping Realloc.
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 12);
        byte* output = (byte*)(destinationHeaderView->dataAddress + (uint)addedIndex * 12U);
        if (output != nullptr) {
            const byte* input = (const byte*)(sourceHeaderView->dataAddress + index * 12U);
            *(uint*)output = *(const uint*)input;
            *(uint*)(output + 4) = *(const uint*)(input + 4);
            *(uint*)(output + 8) = *(const uint*)(input + 8); // Interleaved writes use one captured input base.
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    cleanup.active = false; // Transfer ownership; native returns without another state write.
    return destination;
}

// R6Engine.dll @ 1000d9a0 : AssignRecords12
// Reuses array storage for raw 12-byte copies, with an identity fast path and live source count/data reloads.
FArray* __thiscall AssignRecords12(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    if (destination == source) return destination;
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->count = 0;
    destinationHeaderView->capacity = initialCount;
    // Existing data pointer is retained until this callback changes it.
    destination->FArray::Realloc(12);
    int liveCount = sourceHeaderView->count;
    uint index = 0;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 12);
        uint outputAddress = destinationHeaderView->dataAddress + (uint)addedIndex * 12U;
        if (outputAddress != 0) {
            uint sourceData = sourceHeaderView->dataAddress;
            const byte* input = (const byte*)(sourceData + index * 12U);
            *(uint*)outputAddress = *(const uint*)input;
            *(uint*)(outputAddress + 4) = *(const uint*)(input + 4);
            *(uint*)(outputAddress + 8) = *(const uint*)(input + 8);
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    return destination; // No method guard, rollback or per-element destructor exists.
}

// R6Engine.dll @ 1000ea90 : DestroyTwelveByteArrayStorage
// Removes the captured signed count of 12-byte elements, then destroys storage on normal or exceptional exit.
void __thiscall DestroyTwelveByteArrayStorage(FArray* array)
{
    NativeArrayHeader32* arrayHeaderView = reinterpret_cast<NativeArrayHeader32*>(array);
    int count = arrayHeaderView->count; // Capture before both the assertion target and state0.
    using FailAssert = void (__cdecl*)(const char*, const char*, int);
    // Reuse this captured target if the first assertion changes its IAT.
    FailAssert fail = reinterpret_cast<FailAssert&>(CoreAppFailAssertImport);
    // Local reference view of the single native cleanup state, not a recovered native type or compiler frame.
    struct PendingStorageCleanup {
        FArray* array;
        bool active;
        // Releases the current array storage when an assertion or removal escapes before normal destruction.
        ~PendingStorageCleanup() noexcept(false)
        {
            if (!active) return;
            using DestroyStorage = void (__thiscall*)(FArray*);
            (*(DestroyStorage*)&FArrayDestructorImport)(array);
        }
    } cleanup{array, true};
    if (count < 0)
        fail("Index<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x202);
    if (count > arrayHeaderView->count) // Reread count after any first assertion callback.
        fail("Index+Count<=ArrayNum", "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h", 0x203);
    // Original signed count, even if assertions return after changing it.
    array->FArray::Remove(0, count, 12);
    cleanup.active = false;
    // Native state-1 before this call prevents duplicate cleanup on failure.
    array->FArray::~FArray();
}

// R6Engine.dll @ 1000ff40 : ForwardTwelveByteArrayDestruction
// Tail-enters 12-byte array destruction with the original ECX receiver, stack and return frame.
__declspec(naked) void __thiscall ForwardTwelveByteArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroyTwelveByteArrayStorage
    }
}

// R6Engine.dll @ 1001c600 : CastToAMP2IOKarma
// Returns the original object word only if its class ancestry includes the fixed Karma class.
int __cdecl CastToAMP2IOKarma(int object)
{
    if (object == 0) return 0;
    UClass* type = reinterpret_cast<UObject*>(static_cast<uint>(object))->Class;
    while (type != nullptr) {
        if (type == &AMP2IOKarma::PrivateStaticClass) // Selected metadata object at0x10082bb0.
            return object;
        type = type->GetSuperClass();
    }
    return 0;
}
