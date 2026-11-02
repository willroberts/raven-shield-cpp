#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
FArray* __thiscall CopyConstructRecords16(FArray* destination, const FArray* source);
__declspec(naked) void __cdecl DestroyAR6RagDollClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// External native storage views; names describe roles rather than recovered original identifiers.
FArray* __thiscall AssignRecords16(FArray* destination, const FArray* source);

__declspec(naked) void __thiscall ForwardSixteenByteArrayDestruction(FArray* array);

// R6Engine.dll data @ 10074340 : nativeRagDollSimulationEnabled
// Current shared simulation-enable word.
extern uint nativeRagDollSimulationEnabled;

// R6Engine.dll data @ 10075508 : nativeRagDollStepCount
// Shared simulation step counter reset during first initialization.
extern uint nativeRagDollStepCount;

// R6Engine.dll data @ 1004d138 : AR6RagDollVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6RagDoll::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6RagDollVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10052984 : nativePathAR6RagDollCpp
extern const char nativePathAR6RagDollCpp[21];

// R6Engine.dll data @ 1005299c : nativeTextAR6RagDollAddSpring
extern const ushort nativeTextAR6RagDollAddSpring[22];

// R6Engine.dll data @ 100528e4 : nativeTextAR6RagDollCollisionDetection
extern const ushort nativeTextAR6RagDollCollisionDetection[31];

// R6Engine.dll data @ 10052860 : nativeTextAR6RagDollExecRenderBones
extern const ushort nativeTextAR6RagDollExecRenderBones[28];

// R6Engine.dll data @ 100529c8 : nativeTextAR6RagDollFirstInit
extern const ushort nativeTextAR6RagDollFirstInit[22];

// R6Engine.dll data @ 10052898 : nativeTextAR6RagDollSatisfyConstraints
extern const ushort nativeTextAR6RagDollSatisfyConstraints[31];

// R6Engine.dll data @ 10052924 : nativeTextAR6RagDollTick
extern const ushort nativeTextAR6RagDollTick[17];

// R6Engine.dll data @ 1005294c : nativeTextMPawnOwnerMeshIsAUSkeletalMeshStaticClass
extern const char nativeTextMPawnOwnerMeshIsAUSkeletalMeshStaticClass[55];

// R6Engine.dll data @ 10052ade : nativeTextR6RagDoll
extern const ushort nativeTextR6RagDoll[10];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollAddSpringCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollAddSpringCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollCollisionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollCollisionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollConstraintsCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollConstraintsCatchPointer(void);
__declspec(naked) void __cdecl RagdollCopyState0Cleanup(void);
__declspec(naked) void __cdecl RagdollDestructionState0Cleanup(void);
__declspec(naked) void __cdecl RagdollDestructionState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollFirstInitCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollFirstInitCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollRenderBonesCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RagdollRenderBonesCatchPointer(void);
__declspec(naked) void __cdecl RagdollRenderBonesState1Cleanup(void);
__declspec(naked) void RagdollTickCatchContext(void);
__declspec(naked) void RagdollTickCatchPointer(void);

// R6Engine.dll data @ 10052858 : nativeFloat0Point025
extern const float nativeFloat0Point025;

// R6Engine.dll data @ 1005285c : nativeFloatMinus6EPlus02
extern const float nativeFloatMinus6EPlus02;

// R6Engine.dll data @ 100528d8 : nativeFloat35
extern const float nativeFloat35;

// R6Engine.dll data @ 100528dc : nativeFloat14
extern const float nativeFloat14;

// R6Engine.dll data @ 100528e0 : nativeFloat0Point95
extern const float nativeFloat0Point95;

// R6Engine.dll data @ 10052948 : nativeFloat3
extern const float nativeFloat3;

// R6Engine.dll data @ 1005c86c : ragdollFirstInitUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry ragdollFirstInitUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c87c : ragdollFirstInitCatchMap
// Typed pointer at EBP-c4 followed by the context catch-all.
const NativeCatchEntry ragdollFirstInitCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -196, ((uint)&RagdollFirstInitCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollFirstInitCatchContext) }
};

// R6Engine.dll data @ 1005c89c : ragdollFirstInitTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock ragdollFirstInitTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ragdollFirstInitCatchMap) }
};

// R6Engine.dll data @ 1005c8b0 : ragdollFirstInitFuncInfo
// Exact FirstInit parent-frame metadata.
const NativeFunctionInfoPrefix ragdollFirstInitFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollFirstInitUnwindMap), 0x1,
    ((uint)&ragdollFirstInitTryMap), 0 };

// R6Engine.dll data @ 1005c7ac : ragdollTickUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry ragdollTickUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c7bc : ragdollTickCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry ragdollTickCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RagdollTickCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollTickCatchContext) }
};

// R6Engine.dll data @ 1005c7dc : ragdollTickTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock ragdollTickTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ragdollTickCatchMap) }
};

// R6Engine.dll data @ 1005c7f0 : ragdollTickFuncInfo
// Exact selected Tick parent-frame metadata.
const NativeFunctionInfoPrefix ragdollTickFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollTickUnwindMap), 0x1,
    ((uint)&ragdollTickTryMap), 0 };

// R6Engine.dll data @ 1005c74c : ragdollCollisionUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry ragdollCollisionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c75c : ragdollCollisionCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry ragdollCollisionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&RagdollCollisionCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollCollisionCatchContext) }
};

// R6Engine.dll data @ 1005c77c : ragdollCollisionTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock ragdollCollisionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ragdollCollisionCatchMap) }
};

// R6Engine.dll data @ 1005c790 : ragdollCollisionFuncInfo
// Exact selected parent frame metadata.
const NativeFunctionInfoPrefix ragdollCollisionFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollCollisionUnwindMap), 0x1,
    ((uint)&ragdollCollisionTryMap), 0 };

// R6Engine.dll data @ 1005c80c : ragdollAddSpringUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry ragdollAddSpringUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c81c : ragdollAddSpringCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry ragdollAddSpringCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RagdollAddSpringCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollAddSpringCatchContext) }
};

// R6Engine.dll data @ 1005c83c : ragdollAddSpringTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock ragdollAddSpringTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ragdollAddSpringCatchMap) }
};

// R6Engine.dll data @ 1005c850 : ragdollAddSpringFuncInfo
// Exact selected parent frame metadata.
const NativeFunctionInfoPrefix ragdollAddSpringFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollAddSpringUnwindMap), 0x1,
    ((uint)&ragdollAddSpringTryMap), 0 };

// R6Engine.dll data @ 1005c6ec : ragdollConstraintsUnwindMap
// Two terminal null-action states; no owned local cleanup.
const NativeUnwindEntry ragdollConstraintsUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c6fc : ragdollConstraintsCatchMap
// Typed unsigned-short pointer at EBP-1ac followed by context catch-all.
const NativeCatchEntry ragdollConstraintsCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -428, ((uint)&RagdollConstraintsCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollConstraintsCatchContext) }
};

// R6Engine.dll data @ 1005c71c : ragdollConstraintsTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock ragdollConstraintsTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ragdollConstraintsCatchMap) }
};

// R6Engine.dll data @ 1005c730 : ragdollConstraintsFuncInfo
// Exact SatisfyConstraints frame metadata; full normal parent review remains separate.
const NativeFunctionInfoPrefix ragdollConstraintsFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollConstraintsUnwindMap),
    0x1, ((uint)&ragdollConstraintsTryMap), 0 };

// R6Engine.dll data @ 1005c684 : ragdollRenderBonesUnwindMap
// State1 destroys the line batcher then state0; states0/2 have no local actions.
const NativeUnwindEntry ragdollRenderBonesUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&RagdollRenderBonesState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005c69c : ragdollRenderBonesCatchMap
// Typed unsigned-short pointer at EBP-f4 followed by native context catch-all.
const NativeCatchEntry ragdollRenderBonesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -244, ((uint)&RagdollRenderBonesCatchPointer) },
    { 0, 0, 0, ((uint)&RagdollRenderBonesCatchContext) }
};

// R6Engine.dll data @ 1005c6bc : ragdollRenderBonesTryMap
// Body states0..1 and catch region2 select both handlers.
const NativeTryBlock ragdollRenderBonesTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&ragdollRenderBonesCatchMap) }
};

// R6Engine.dll data @ 1005c6d0 : ragdollRenderBonesFuncInfo
// Exact RenderBones frame metadata.
const NativeFunctionInfoPrefix ragdollRenderBonesFuncInfo = { 0x19930520, 0x3, ((uint)&ragdollRenderBonesUnwindMap),
    0x1, ((uint)&ragdollRenderBonesTryMap), 0 };

// R6Engine.dll data @ 100580b4 : ragdollDestructionUnwindMap
// State1 destroys spring storage, then state0 destroys the completed corpse base.
const NativeUnwindEntry ragdollDestructionUnwindMap[2] = {
    { -1, ((uint)&RagdollDestructionState0Cleanup) },
    { 0, ((uint)&RagdollDestructionState1Cleanup) }
};

// R6Engine.dll data @ 100580c4 : ragdollDestructionFuncInfo
// Exact destructor frame metadata.
const NativeFunctionInfoPrefix ragdollDestructionFuncInfo = { 0x19930520, 0x2, ((uint)&ragdollDestructionUnwindMap), 0,
    0, 0 };

// R6Engine.dll data @ 100580e0 : ragdollCopyUnwindMap
// Only the completed corpse base has an action; no completed-spring action exists.
const NativeUnwindEntry ragdollCopyUnwindMap[1] = {
    { -1, ((uint)&RagdollCopyState0Cleanup) }
};

// R6Engine.dll data @ 100580e8 : ragdollCopyFuncInfo
// Exact copy-constructor frame metadata.
const NativeFunctionInfoPrefix ragdollCopyFuncInfo = { 0x19930520, 0x1, ((uint)&ragdollCopyUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10075a18 : autoclassAR6RagDoll
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6RagDoll = nullptr;

// R6Engine.dll @ 10008dd0 : AR6RagDoll::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6RagDoll::StaticClass(void)
{
    return &AR6RagDoll::PrivateStaticClass; // Selected object at0x10075510.
}

// R6Engine.dll @ 10008de0 : AR6RagDoll::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6RagDoll::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6RagDoll::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 1000fec0 : AR6RagDoll::operator=
// Assigns the base and spring storage, then copies sixteen raw particle records in forward word order.
AR6RagDoll& __thiscall AR6RagDoll::operator=(const AR6RagDoll& sourceObject)
{
    const AR6RagDoll* source = &sourceObject;
    this->AR6AbstractCorpse::operator=(*source);
    reinterpret_cast<uint&>(this->m_fAccumulatedTime) = reinterpret_cast<const uint&>(source->m_fAccumulatedTime);
    this->m_pawnOwner = source->m_pawnOwner;
    AssignRecords16((FArray*)&this->m_aSpring,
        (const FArray*)&source->m_aSpring);
    for (uint particleIndex = 0; particleIndex < 16U; ++particleIndex) {
        uint* destinationWords = (uint*)&this->m_aParticle[particleIndex];
        const uint* sourceWords = (const uint*)&source->m_aParticle[particleIndex];
        // Native sixteen groups of REP MOVSD 22, assuming ABI-clear DF.
        for (uint wordIndex = 0; wordIndex < 22U; ++wordIndex)
            destinationWords[wordIndex] = sourceWords[wordIndex];
    }
    return *this;
}

// R6Engine.dll @ 10012390 : AR6RagDoll::~AR6RagDoll
// Runs conditional cleanup before automatic spring-storage and AR6AbstractCorpse base destruction.
AR6RagDoll::~AR6RagDoll()
{
    // Compiler installs4d138 and arms state1 around this call; no particle record destructor is needed.
    UObject::ConditionalDestroy();
    // Normal spring ea00 runs under state0, then current base49808 under state-1; EH spring uses ff30.
}

// R6Engine.dll @ 10012400 : AR6RagDoll::AR6RagDoll()
// Constructs the imported corpse base, installs this class's table and leaves derived storage untouched.
// Keep the native ABI view: array member no-init declarations remain unresolved.
AR6RagDoll* __thiscall AR6RagDoll::AR6RagDoll(AR6RagDoll* this)
{
    using ConstructBase = AR6AbstractCorpse* (__thiscall*)(AR6AbstractCorpse*);
    reinterpret_cast<ConstructBase&>(AR6AbstractCorpseDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6RagDollVirtualTable);
    return this; // Native adds no spring-header or particle initialization and ignores imported EAX.
}

// R6Engine.dll @ 10012420 : AR6RagDoll::AR6RagDoll
// Copies the completed base and spring array, then 352 raw particle words with only base cleanup protection.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6RagDoll* __thiscall AR6RagDoll::AR6RagDoll(AR6RagDoll* this, const AR6RagDoll* source)
{
    AR6AbstractCorpse::AR6AbstractCorpse(this, source);
    *(uint*)this = ((uint)&AR6RagDollVirtualTable);
    reinterpret_cast<uint&>(this->m_fAccumulatedTime) = reinterpret_cast<const uint&>(source->m_fAccumulatedTime);
    this->m_pawnOwner = source->m_pawnOwner;
    struct PendingBase {
        AR6AbstractCorpse* object;
        bool active;
        // Inferred view of580e0/580e8: only the completed base is protected, including after spring copy succeeds.
        ~PendingBase() noexcept(false) {
            if (active) object->AR6AbstractCorpse::~AR6AbstractCorpse();
        }
    } cleanup{this, true}; // Native state0 follows owner398 store; preceding work stays state-1.
    CopyConstructRecords16((FArray*)&this->m_aSpring, (const FArray*)&source->m_aSpring);
    uint* destinationWords = (uint*)&this->m_aParticle;
    const uint* sourceWords = (const uint*)&source->m_aParticle;
    for (uint wordIndex = 0; wordIndex < 352U; ++wordIndex) // One native REP MOVSD 160 hex; ABI-clear DF.
        destinationWords[wordIndex] = sourceWords[wordIndex];
    cleanup.active = false; // Transfer ownership without an extra native state1/write or completed-spring action.
    return this;
}

// R6Engine.dll @ 10013a70 : AR6RagDoll::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6RagDoll::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6RagDollConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100332f0 : AR6RagDoll::AddImpulseToBone
// Remaps the selector, then adds the by-value impulse to the first matching particle's current origin.
void __thiscall AR6RagDoll::AddImpulseToBone(int boneSelector, FVector impulse)
{
    switch (boneSelector) {
    case 2:
    case 4:
        boneSelector = 3;
        break;
    case 7:
    case 8:
    case 9:
        boneSelector = 6;
        break;
    case 10:
    case 15:
        boneSelector = 5;
        break;
    case 14:
    case 19:
    case 23:
    case 27:
        --boneSelector;
        break;
    }

    byte* record = (byte*)this + 0x3a8;
    for (int recordIndex = 0; recordIndex < 16; ++recordIndex, record += 0x58) {
        if (*(const int*)(record + 0x50) != boneSelector) continue; // STParticle.iRefBone.
        *(float*)record = (float)((float10)impulse.X + *(float*)record);
        *(float*)(record + 4) = (float)((float10)impulse.Y + *(float*)(record + 4));
        *(float*)(record + 8) = (float)((float10)impulse.Z + *(float*)(record + 8));
        return; // No later matching particle is modified and no impulse word is read on a miss.
    }
}

// R6Engine.dll @ 100333a0 : AR6RagDoll::VerletIntegration
// Advances all sixteen origins using native x87 rounding points, then copies original position words to history.
void __thiscall AR6RagDoll::VerletIntegration(float deltaSeconds)
{
    float10 horizontalFirst = (float10)deltaSeconds * nativeFloatZero; // Selected constant is +0.0f.
    float horizontalFirstWord = (float)horizontalFirst;
    // Selected constant is -600.0f.
    float verticalFirstWord = (float)((float10)deltaSeconds * nativeFloatMinus6EPlus02);
    float10 xStep = horizontalFirst * deltaSeconds; // Retained extended first product, unlike Y.
    float10 yStep = (float10)horizontalFirstWord * deltaSeconds;
    float10 zStep = (float10)verticalFirstWord * deltaSeconds;
    for (int particleIndex = 0; particleIndex < 16; ++particleIndex) { // Native unrolls two groups of eight.
        byte* particle = (byte*)this + 0x3a8 + particleIndex * 0x58;
        float* current = (float*)particle;
        float* previous = (float*)(particle + 0x30);
        float10 deltaX = (float10)current[0] - previous[0];
        float10 loadedY = current[1];
        uint oldX = *(uint*)current;
        float10 deltaY = loadedY - previous[1];
        uint oldY = *(uint*)(current + 1);
        float10 loadedZ = current[2];
        uint oldZ = *(uint*)(current + 2);
        float deltaZWord = (float)(loadedZ - previous[2]);
        float xCorrectionWord = (float)(deltaX + xStep);
        float10 yCorrection = deltaY + yStep;
        float10 zCorrection = (float10)deltaZWord + zStep;
        current[0] = (float)((float10)xCorrectionWord + current[0]);
        current[1] = (float)(yCorrection + current[1]);
        current[2] = (float)(zCorrection + current[2]);
        *(uint*)previous = oldX; // Raw MOV stores preserve original NaN payloads and signed zero.
        *(uint*)(previous + 1) = oldY;
        *(uint*)(previous + 2) = oldZ;
    }
}

// R6Engine.dll @ 10033760 : AR6RagDoll::RenderBones
// Draws selected particle/bone boxes, child-to-parent links and three current axes through a scoped line batcher.
void __thiscall AR6RagDoll::RenderBones(UCanvas* canvas)
{
    AR6AbstractPawn* owner = this->m_pawnOwner;
    UMesh* mesh = owner->Mesh;
    using GetMeshInstance = UMeshInstance* (__thiscall*)(UMesh*, const AActor*);
    byte* meshTable = *(byte**)mesh; // Native captures the table before state0; the slot is read inside.
    try {
        byte* meshInstance = reinterpret_cast<byte*>(
            (*(GetMeshInstance*)(meshTable + 0x88))(mesh, owner));
        UCanvas* currentCanvas = canvas;
        UViewport* viewport = currentCanvas->Viewport;
        FRenderInterface* renderInterface = *reinterpret_cast<FRenderInterface**>(reinterpret_cast<byte*>(viewport)
            + 0x164);
        uint batcherStorage[10]; // Opaque reserved local span; no complete FLineBatcher layout is invented.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        int drawParticle[16];
        for (uint index = 0; index < 16; ++index) drawParticle[index] = 1;
        struct PendingBatcher {
            FLineBatcher* object;
            bool active;
            // Native state1 alone owns this local; state0 has no cleanup action.
            ~PendingBatcher() noexcept(false) {
                if (active) {
                    using Destroy = void (__thiscall*)(FLineBatcher*);
                    (*(Destroy*)&FLineBatcherDestructorImport)(object);
                }
            }
        } cleanup{batcher, false};
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(renderInterface, 1, 0);
        viewport = currentCanvas->Viewport; // Reread after the constructor callback.
        renderInterface = *reinterpret_cast<FRenderInterface**>(reinterpret_cast<byte*>(viewport) + 0x164);
        struct MatrixWords { uint word[16]; } identity;
        using SetMatrix = void (__thiscall*)(FRenderInterface*, uint, MatrixWords);
        SetMatrix setMatrix = *(SetMatrix*)(*(byte**)renderInterface + 0x34);
        const uint* identitySource = *(const uint**)&FMatrixIdentityImport;
        for (uint word = 0; word < 16; ++word) identity.word[word] = identitySource[word];
        cleanup.active = true; // State1 follows all matrix/receiver preparation, immediately before this call.
        setMatrix(renderInterface, 0, identity);
        uint boundsStorage[7]; // Native only writes six Min/Max words; validity and padding remain untouched.
        uint expandedParticle[7], expandedMesh[7], transformedStorage[12];
        uint colorWord;
        // Inferred local views of repeated native packets, not additional recovered helper bodies.
        auto liftedPoint = [](const FVector* origin) -> FVector {
            float10 liftedZ = (float10)origin->Z + nativeFloat15;
            FVector point;
            point.Y = (float)(float10)origin->Y;
            point.Z = (float)liftedZ;
            reinterpret_cast<uint&>(point.X) = reinterpret_cast<const uint&>(origin->X);
            return point;
        };
        auto makeColor = [&](const FPlane& plane) {
            // Ignore EAX; use the constructed output word.
            ::new (reinterpret_cast<void*>(&colorWord)) FColor(*reinterpret_cast<const FPlane*>(&plane));
        };
        auto drawBox = [&](const FVector& point, const FPlane& plane, uint* hiddenOutput, float extent) {
            const uint* xyz = (const uint*)&point;
            for (uint word = 0; word < 3; ++word) boundsStorage[word] = boundsStorage[word + 3] = xyz[word];
            makeColor(plane);
            using Expand = FBox* (__thiscall*)(const FBox*, FBox*, float);
            const uint* expanded = (const uint*)reinterpret_cast<Expand&>(FBoxExpandByImport)((FBox*)boundsStorage,
                (FBox*)hiddenOutput, extent);
            struct BoxWords { uint word[7]; } packet;
            for (uint word = 0; word < 7; ++word) packet.word[word] = expanded[word]; // Returned pointer, all28 bytes.
            using DrawBox = void (__thiscall*)(FLineBatcher*, BoxWords, uint);
            reinterpret_cast<DrawBox&>(FLineBatcherDrawBoxImport)(batcher, packet, colorWord);
        };
        auto drawLine = [&](const FVector& start, const FVector& end, const FPlane& plane) {
            makeColor(plane);
            using DrawLine = void (__thiscall*)(FLineBatcher*, FVector, FVector, uint);
            reinterpret_cast<DrawLine&>(FLineBatcherDrawLineImport)(batcher, start, end, colorWord);
        };
        for (uint index = 0; index < 16; ++index) {
            if (drawParticle[index] == 0) continue;
            auto* particle = &this->m_aParticle[index];
            FVector point = liftedPoint(&particle->cCurrentPos.Origin);
            drawBox(point, FPlane(0.0f, 255.0f, 255.0f, 0.0f), expandedParticle, 2.0f);
            uint boneIndex = reinterpret_cast<const uint&>(particle->iRefBone);
            const FCoords* bone = (const FCoords*)(*(uint*)(meshInstance + 0xb8) + boneIndex * 0x30U);
            const FCoords* transformed = &(*reinterpret_cast<FCoords*>(transformedStorage) =
                *bone * *reinterpret_cast<const FCoords*>(meshInstance + 0xc4));
            FVector meshPoint = transformed->Origin; // Copy the returned origin before constructing the yellow color.
            drawBox(meshPoint, FPlane(255.0f, 255.0f, 0.0f, 0.0f), expandedMesh, 1.0f);
            int parent = particle->iToward; // Read only after both boxes and their callbacks.
            if (parent >= 0) {
                FVector parentPoint = liftedPoint(reinterpret_cast<const FVector*>(
                    reinterpret_cast<const byte*>(&this->m_aParticle) + (uint)parent * 0x58U));
                // Current coordinates, not the earlier box snapshot.
                FVector childPoint = liftedPoint(&particle->cCurrentPos.Origin);
                drawLine(childPoint, parentPoint, FPlane(0.0f, 255.0f, 255.0f, 0.0f));
            }
        }
        for (uint index = 0; index < 16; ++index) {
            if (drawParticle[index] == 0) continue;
            const auto* particle = &this->m_aParticle[index];
            float liftedZ = (float)((float10)particle->cCurrentPos.Origin.Z + nativeFloat15);
            FVector start;
            reinterpret_cast<uint&>(start.X) = reinterpret_cast<const uint&>(particle->cCurrentPos.Origin.X);
            reinterpret_cast<uint&>(start.Y) = reinterpret_cast<const uint&>(particle->cCurrentPos.Origin.Y);
            start.Z = liftedZ;
            for (uint axis = 0; axis < 3; ++axis) {
                // Axis address remains live after prior draw calls; the native walk uses a 12-byte stride.
                const float* direction = reinterpret_cast<const float*>(
                    reinterpret_cast<const byte*>(&particle->cCurrentPos.XAxis) + axis * 12U);
                float10 scaledZ = (float10)direction[2] * nativeFloat1EPlus01;
                float scaledY = (float)((float10)direction[1] * nativeFloat1EPlus01);
                float scaledX = (float)((float10)direction[0] * nativeFloat1EPlus01);
                float10 endZ = scaledZ + liftedZ;
                float10 endY = (float10)scaledY + start.Y;
                float10 endX = (float10)scaledX + start.X;
                FVector end = {(float)endX, (float)endY, (float)endZ};
                FPlane plane(0.0f, 0.0f, 0.0f, 0.0f);
                ((float*)&plane)[axis] = 255.0f;
                drawLine(start, end, plane);
            }
        }
        cleanup.active = false; // Native state0 excludes the batcher before its normal destruction call.
        batcher->FLineBatcher::~FLineBatcher();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RagDoll::execRenderBones"); // Native diagnostic spelling.
        throw;
    }
}

// R6Engine.dll @ 10033d07 : RagdollRenderBonesCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-f4 through EBP-54.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollRenderBonesCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xf4]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x54]
        push edx
        mov dword ptr [ebp-0x54],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10033d1e : RagdollRenderBonesCatchContext
// Reports the native execRenderBones diagnostic and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollRenderBonesCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollExecRenderBones
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10033d40 : AR6RagDoll::ClipParticleToPlane
// Projects an indexed origin toward the plane only for ordered negative distance, using native correction spills.
void __thiscall AR6RagDoll::ClipParticleToPlane(int particleIndex, const FVector* planeNormal,
    const FVector* planePoint)
{
    byte* particle = (byte*)((uint)this + (uint)particleIndex * 0x58U + 0x3a8U); // Native wraps without an index guard.
    const float* normal = (const float*)planeNormal;
    const float* point = (const float*)planePoint;
    float10 currentDot = ((float10)*(float*)(particle + 8) * normal[2] +
        (float10)*(float*)particle * normal[0]) + (float10)*(float*)(particle + 4) * normal[1];
    float10 planeDot = ((float10)point[1] * normal[1] + (float10)point[2] * normal[2]) +
        (float10)normal[0] * point[0];
    float10 distance = currentDot - planeDot;
    if (distance < nativeFloatZero) { // FCOM/status parity excludes equal, positive and unordered distances.
        distance *= nativeFloat0Point2; // Selected scale is0.2f, not full plane projection.
        float10 correctionX = distance * normal[0];
        float correctionY = (float)(distance * normal[1]);
        float correctionZ = (float)(distance * normal[2]); // All corrections precede the first coordinate write.
        *(float*)particle = (float)((float10)*(float*)particle - correctionX);
        *(float*)(particle + 4) = (float)((float10)*(float*)(particle + 4) - correctionY);
        *(float*)(particle + 8) = (float)((float10)*(float*)(particle + 8) - correctionZ);
    }
}

// R6Engine.dll @ 10033de0 : AR6RagDoll::SatisfyConstraints
// Rebuilds particle axes, applies nineteen plane relaxations and solves springs in reverse order, twice.
void __thiscall AR6RagDoll::SatisfyConstraints(void)
{
    byte* object = (byte*)this;
    try {
        // Scratch carries the last direction input into the next particle's special case.
        FVector scratch, normal, point;
        FVector refreshOutput, firstOutput, thirdOutput, torsoInput, torsoOutput, armDifference;
        FVector leftLegInput, leftLegOutput, rightLegInput, rightLegOutput;
        FVector leftArmCross, rightArmCross, leftLegCross, rightLegCross, yCross, yOutput, zCross, zOutput;
        // Inferred local views of repeated native packets; these are not additional recovered native bodies.
        // Returns the wrapped origin address without validating the index.
        auto particle = [&](uint index) -> byte* { return (byte*)((uint)this + index * 0x58U + 0x3a8U); };
        // Copies three component words in forward native order.
        auto copy3 = [](void* destination, const void* source) {
            for (uint word = 0; word < 3; ++word) ((uint*)destination)[word] = ((const uint*)source)[word];
        };
        // Spills X/Y/Z differences after computing them in Z/Y/X order.
        auto difference = [](FVector* output, const void* first, const void* second) {
            const float* a = (const float*)first;
            const float* b = (const float*)second;
            float10 z = (float10)a[2] - b[2];
            float10 y = (float10)a[1] - b[1];
            float10 x = (float10)a[0] - b[0];
            output->X = (float)x;
            output->Y = (float)y;
            output->Z = (float)z;
        };
        // Normalizes the input, copies it to the supplied result and returns that result.
        auto normalize = [](FVector* input, FVector* hiddenOutput) -> const FVector* {
            return &(*hiddenOutput = input->GetNormalized());
        };
        // Copies the cross product to the supplied result and returns that result.
        auto cross = [](const void* left, FVector* hiddenOutput, const void* right) -> const FVector* {
            return &(*hiddenOutput = *static_cast<const FVector*>(left) ^ *static_cast<const FVector*>(right));
        };
        // Negates the three components through binary32 stores.
        auto negate = [](const void* input) -> FVector {
            const float* value = (const float*)input;
            return FVector((float)(-(float10)value[0]), (float)(-(float10)value[1]), (float)(-(float10)value[2]));
        };
        // Retains all scaled products until their ordered position updates.
        auto offsetBonePosition = [](byte* position, const FVector* direction, float scale, bool subtract) {
            float10 z = (float10)direction->Z * scale;
            float10 y = (float10)direction->Y * scale;
            float10 x = (float10)direction->X * scale;
            float* value = (float*)position;
            value[0] = (float)(subtract ? (float10)value[0] - x : x + value[0]);
            value[1] = (float)(subtract ? (float10)value[1] - y : y + value[1]);
            value[2] = (float)(subtract ? (float10)value[2] - z : z + value[2]);
        };
        // Flips the captured torso axis only for an ordered positive dot-product difference.
        auto orientTorsoAxis = [&](bool reverseFirstProduct) {
            FVector axis, first, second;
            copy3(&axis, object + 0x3b4);
            copy3(&first, object + 0x4b0);
            copy3(&second, object + 0x668);
            float10 firstX = reverseFirstProduct ? (float10)first.X * axis.X : (float10)axis.X * first.X;
            float10 firstDot = (firstX + (float10)axis.Z * first.Z) + (float10)axis.Y * first.Y;
            float10 secondDot = ((float10)axis.Z * second.Z + (float10)axis.Y * second.Y) +
                (float10)axis.X * second.X;
            if (secondDot - firstDot > nativeFloatZero) scratch = negate(&scratch);
        };
        // Rounds the Z product before translation while retaining extended X/Y products.
        auto planePoint = [&](const void* origin, float scale, bool twice = false) {
            const float* base = (const float*)origin;
            float10 x = twice ? (float10)normal.X + normal.X : (float10)normal.X * scale;
            float10 y = twice ? (float10)normal.Y + normal.Y : (float10)normal.Y * scale;
            float zWord = (float)(twice ? (float10)normal.Z + normal.Z : (float10)normal.Z * scale);
            point.X = (float)(x + base[0]);
            point.Y = (float)(y + base[1]);
            point.Z = (float)((float10)zWord + base[2]);
        };
        // Reuses the current plane snapshots for each selected particle relaxation.
        auto clip = [&](int index) { this->AR6RagDoll::ClipParticleToPlane(index, &normal, &point); };
        for (uint pass = 0; pass < 2; ++pass) {
            for (uint index = 0; index < 16; ++index) {
                byte* record = particle(index);
                int toward = *(const int*)(record + 0x4c); // Captured before either normalization callback.
                byte* bonePosition = record + 0x3c;
                copy3(bonePosition, record);
                if (index == 1) {
                    for (uint component = 0; component < 3; ++component)
                        ((float*)bonePosition)[component] = (float)((float10)((float*)particle(0))[component] +
                            ((float*)bonePosition)[component]);
                    for (uint component = 0; component < 3; ++component)
                        ((float*)bonePosition)[component] = (float)((float10)((float*)bonePosition)[component] *
                            nativeFloatHalf);
                    const FVector* direction = normalize(&scratch, &firstOutput);
                    offsetBonePosition(bonePosition, direction, nativeFloat2EPlus01, true);
                    // The input was running scratch, and the scale is sampled after the normalization callback.
                } else if (index == 3) {
                    // Native subtracts signed link offset.
                    difference(&scratch, particle(0U - (uint)toward), bonePosition);
                    const FVector* direction = normalize(&scratch, &thirdOutput);
                    offsetBonePosition(bonePosition, direction, nativeFloat1EPlus01, false);
                }
                uint linked = toward < 0 ? 0U - (uint)toward : (uint)toward;
                if (toward < 0) difference(&scratch, bonePosition, particle(linked));
                else difference(&scratch, particle(linked), bonePosition);
                copy3(record + 0x0c, normalize(&scratch, &refreshOutput));
            }
            difference(&torsoInput, object + 0x3a8, object + 0x400);
            const FVector* torso = normalize(&torsoInput, &torsoOutput);
            copy3(object + 0x3cc, torso);
            copy3(object + 0x424, torso);
            difference(&armDifference, object + 0x508, object + 0x610);
            copy3(object + 0x47c, &armDifference);
            copy3(object + 0x4d4, &armDifference);
            copy3(&scratch, object + 0x3cc);
            orientTorsoAxis(false);
            copy3(object + 0x52c, &scratch);
            copy3(object + 0x584, &scratch);
            copy3(object + 0x5dc, cross(object + 0x5c4, &leftArmCross, &scratch));
            copy3(&scratch, object + 0x3cc);
            orientTorsoAxis(true); // Reload all source fields after the preceding cross callback.
            copy3(object + 0x634, &scratch);
            copy3(object + 0x68c, &scratch);
            copy3(object + 0x6e4, cross(&scratch, &rightArmCross, object + 0x6cc));
            for (uint side = 0; side < 2; ++side) {
                FVector negatedTorso = negate(object + 0x3cc);
                uint firstAxis = side == 0 ? 0x73c : 0x844;
                copy3(object + firstAxis, &negatedTorso);
                copy3(object + firstAxis + 0x58, &negatedTorso);
                copy3(object + firstAxis + 0xb0, &negatedTorso);
                FVector* input = side == 0 ? &leftLegInput : &rightLegInput;
                difference(input, object + (side == 0 ? 0x718 : 0x820), object + (side == 0 ? 0x7c8 : 0x8d0));
                copy3(&scratch, normalize(input, side == 0 ? &leftLegOutput : &rightLegOutput));
                const float* alignment = (const float*)(object + (side == 0 ? 0x77c : 0x884));
                float10 dot = ((float10)scratch.Y * alignment[1] + (float10)scratch.Z * alignment[2]) +
                    (float10)scratch.X * alignment[0];
                if (!(dot >= nativeFloatZero)) dot = -dot; // Native also negates unordered values.
                if (dot < nativeFloat0Point95) {
                    const FVector* result = cross(object + (side == 0 ? 0x7d4 : 0x8dc),
                        side == 0 ? &leftLegCross : &rightLegCross, &scratch);
                    if (side != 0) copy3(&scratch, result);
                    copy3(object + firstAxis + 0xb0, result);
                }
            }
            for (uint index = 0; index < 16; ++index) {
                byte* record = particle(index);
                const FVector* crossed = cross(record + 0x24, &yCross, record + 0x0c);
                copy3(record + 0x18, normalize((FVector*)crossed, &yOutput));
            }
            for (uint index = 2; index < 16; ++index) {
                byte* record = particle(index);
                const FVector* crossed = cross(record + 0x0c, &zCross, record + 0x18);
                copy3(record + 0x24, normalize((FVector*)crossed, &zOutput));
            }
            copy3(&normal, object + 0x3b4); planePoint(object + 0x458, nativeFloat14); clip(3);
            copy3(&normal, object + 0x3cc); planePoint(object + 0x3a8, nativeFloat5); clip(5);
            normal = negate(object + 0x3cc); planePoint(object + 0x3a8, nativeFloat5); clip(8);
            copy3(&normal, object + 0x520); planePoint(object + 0x560, 0.0f, true); clip(6);
            copy3(&normal, object + 0x628); planePoint(object + 0x668, 0.0f, true); clip(9);
            normal = negate(object + 0x3b4); copy3(&point, object + 0x3e4); clip(10); clip(13);
            copy3(&normal, object + 0x3cc); planePoint(object + 0x3e4, nativeFloat5); clip(11); clip(12);
            normal = negate(object + 0x3cc); planePoint(object + 0x3e4, nativeFloat5); clip(14); clip(15);
            normal = negate(object + 0x3c0); copy3(&point, object + 0x3a8); clip(11); clip(14);
            normal = negate(object + 0x3b4); copy3(&point, object + 0x718); clip(11); clip(14);
            planePoint(object + 0x718, nativeFloat35); clip(12); clip(15); // Reuse captured normal.
            copy3(&normal, object + 0x730); copy3(&point, object + 0x718); clip(12);
            copy3(&normal, object + 0x838); copy3(&point, object + 0x820); clip(15);
            uint springIndex = *(const uint*)(object + 0x3a0);
            for (;;) {
                --springIndex; // Native wrapped decrement precedes its signed exit test.
                if ((int)springIndex < 0) break;
                const byte* spring = (const byte*)(*(uint*)(object + 0x39c) + springIndex * 16U);
                byte* first = particle(*(const uint*)spring);
                byte* second = particle(*(const uint*)(spring + 4));
                float dx = (float)((float10)*(float*)second - *(float*)first);
                float dy = (float)((float10)*(float*)(second + 4) - *(float*)(first + 4));
                float firstMass = *(float*)(first + 0x48);
                float10 deltaZ = (float10)*(float*)(second + 8) - *(float*)(first + 8);
                float secondMass = *(float*)(second + 0x48);
                float dz = (float)deltaZ;
                float lengthWord = (float)((deltaZ * dz + (float10)dy * dy) + (float10)dx * dx);
                float target;
                if (*(const uint*)(spring + 12) != 0xbf800000 && lengthWord > *(const float*)(spring + 12))
                    target = *(const float*)(spring + 12);
                else if (*(const uint*)(spring + 8) != 0xbf800000 && lengthWord < *(const float*)(spring + 8))
                    target = *(const float*)(spring + 8);
                else continue;
                if (!(target >= nativeFloatZero)) continue;
                float10 factor = ((float10)target - lengthWord) /
                    (((float10)secondMass + firstMass) * ((float10)target + lengthWord));
                float10 correctionX = (float10)dx * factor;
                float correctionY = (float)((float10)dy * factor);
                float correctionZ = (float)((float10)dz * factor);
                float10 firstX = (float10)firstMass * correctionX;
                float10 firstY = (float10)correctionY * firstMass;
                float firstZ = (float)((float10)correctionZ * firstMass);
                *(float*)first = (float)((float10)*(float*)first - firstX);
                *(float*)(first + 4) = (float)((float10)*(float*)(first + 4) - firstY);
                *(float*)(first + 8) = (float)((float10)*(float*)(first + 8) - firstZ);
                float10 secondX = correctionX * secondMass;
                float10 secondY = (float10)correctionY * secondMass;
                float secondZ = (float)((float10)correctionZ * secondMass);
                *(float*)second = (float)(secondX + *(float*)second); // Reload after first writes, even if both alias.
                *(float*)(second + 4) = (float)(secondY + *(float*)(second + 4));
                *(float*)(second + 8) = (float)((float10)secondZ + *(float*)(second + 8));
            }
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RagDoll::SatisfyConstraints");
        throw;
    }
}

// R6Engine.dll @ 10034e9a : RagdollConstraintsCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-1ac through EBP-108.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollConstraintsCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1ac]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x108]
        push edx
        mov dword ptr [ebp-0x108],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10034eb7 : RagdollConstraintsCatchContext
// Reports SatisfyConstraints context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollConstraintsCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollSatisfyConstraints
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10034ef0 : AR6RagDoll::CollisionDetection
// Traces sixteen current-to-previous segments and copies hit Location except for ordered Time equal to one.
void __thiscall AR6RagDoll::CollisionDetection(void)
{
    try {
        NativeCheckResult32 hitWords; // Native FCheckResult view; all other words retain their previous/local contents.
        hitWords.materialAddress = 0; // Only +2c is initialized once, consistent with the default Material slot.
        FVector snapshot;
        for (uint index = 0; index < 16; ++index) {
            byte* particle = (byte*)this + 0x3a8 + index * 0x58;
            uint x = *(const uint*)particle;
            uint y = *(const uint*)(particle + 4);
            uint z = *(const uint*)(particle + 8);
            reinterpret_cast<uint&>(snapshot.X) = x;
            reinterpret_cast<uint&>(snapshot.Z) = z;
            void* levelForTable = reinterpret_cast<void*&>(this->XLevel);
            reinterpret_cast<uint&>(snapshot.Y) = y;
            byte* table = *(byte**)levelForTable;
            const uint* zero = *(const uint**)&FVectorFVector0Import;
            FVector extent;
            for (uint word = 0; word < 3; ++word) ((uint*)&extent)[word] = zero[word];
            using Trace = int (__thiscall*)(void*, void*, AActor*, const FVector*, const FVector*, uint, FVector);
            // Reload after capturing the table and extent words.
            void* receiver = reinterpret_cast<void*&>(this->XLevel);
            (*(Trace*)(table + 0xcc))(receiver, reinterpret_cast<uint*>(&hitWords), this, &snapshot,
                (const FVector*)(particle + 0x30), 0x86, extent); // EAX is ignored; no per-iteration hit reset.
            // FUCOMPP/status parity also copies unordered NaN.
            if (hitWords.Time != nativeFloatOne) {
                x = reinterpret_cast<uint&>(hitWords.Location.X);
                y = reinterpret_cast<uint&>(hitWords.Location.Y);
                z = reinterpret_cast<uint&>(hitWords.Location.Z);
                *(uint*)particle = x;
                *(uint*)(particle + 4) = y;
                *(uint*)(particle + 8) = z;
            }
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RagDoll::CollisionDetection");
        throw;
    }
}

// R6Engine.dll @ 10034fb0 : RagdollCollisionCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-1c through EBP-18.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollCollisionCatchPointer(void)
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

// R6Engine.dll @ 10034fc4 : RagdollCollisionCatchContext
// Reports CollisionDetection context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollCollisionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollCollisionDetection
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor eax,eax
        push eax
        push eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10035000 : AR6RagDoll::Tick
// Advances fixed simulation steps, writes bone transforms and conditionally moves the current owner.
int __thiscall AR6RagDoll::Tick(float deltaSeconds, ELevelTick tickType)
{
    try {
        byte* ragdoll = (byte*)this;
        byte* owner = reinterpret_cast<byte*&>(this->m_pawnOwner);
        if (owner == nullptr) {
            (*(void (__thiscall**)(AR6RagDoll*))(*(byte**)this + 0x28))(this);
            return 1;
        }
        if ((ragdoll[0xa2] & 1) != 0)
            return 1;
        UClass* meshClass = reinterpret_cast<UObject*>(*(byte**)(owner + 0x16c))->Class;
        UClass* skeletalMeshClass = USkeletalMeshPrivateStaticClassImport;
        while (meshClass != nullptr && meshClass != skeletalMeshClass)
            meshClass = meshClass->GetSuperClass();
        if (meshClass == nullptr && skeletalMeshClass != nullptr)
            appFailAssert(nativeTextMPawnOwnerMeshIsAUSkeletalMeshStaticClass, nativePathAR6RagDollCpp, 0x2b0);
        float* timer = (float*)(ragdoll + 0xbc); // Timer role inferred; native offset is explicit.
        if (*timer > nativeFloat3) {
            *(uint*)(ragdoll + 0xa0) |= 0x10000;
            return 1;
        }
        *timer = (float)((float10)deltaSeconds + *timer);
        float* accumulator = (float*)(ragdoll + 0x394);
        float10 pending = (float10)deltaSeconds + *accumulator;
        bool advanced = false;
        for (;;) {
            // Read before the pending value's 32-bit store.
            uint enabled = reinterpret_cast<const uint&>(nativeRagDollSimulationEnabled);
            *accumulator = (float)pending;
            if (enabled == 0 || !(*accumulator > nativeFloat0Point025))
                break;
            ++reinterpret_cast<uint&>(nativeRagDollStepCount);
            this->AR6RagDoll::VerletIntegration(0.025f);
            this->AR6RagDoll::SatisfyConstraints();
            this->AR6RagDoll::CollisionDetection();
            pending = (float10)*accumulator - nativeFloat0Point025;
            advanced = true;
        }
        if (!advanced)
            return 1;
        AR6AbstractPawn* meshOwner = this->m_pawnOwner;
        UMesh* mesh = meshOwner->Mesh;
        USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(meshOwner));
        for (int index = 1; index < 16; ++index) {
            byte* particle = ragdoll + 0x3a8 + index * 0x58;
            FRotator rotationStorage;
            const FRotator* result = &(rotationStorage = reinterpret_cast<const FCoords*>(particle)->OrthoRotation());
            FRotator rotation = *result; // Copies the selected result before the particle-position update.
            *(float*)(particle + 0x44) = (float)((float10)*(float*)(particle + 0x44) +
                nativeFloat15);
            FVector position = *(FVector*)(particle + 0x3c);
            instance->USkeletalMeshInstance::SetBonePosition(
                *reinterpret_cast<FName*>(particle + 0x54), rotation, position, 1.0f);
        }
        owner = reinterpret_cast<byte*&>(this->m_pawnOwner);
        FVector difference;
        difference.X = (float)((float10)*(float*)(ragdoll + 0x3a8) - *(float*)(owner + 0x234));
        difference.Y = (float)((float10)*(float*)(ragdoll + 0x3ac) - *(float*)(owner + 0x238));
        difference.Z = (float)((float10)*(float*)(ragdoll + 0x3b0) - *(float*)(owner + 0x23c));
        using Size = float10 (__thiscall*)(const FVector*); // Native compares ST(0), retaining extended precision.
        float10 distance = reinterpret_cast<Size&>(FVectorSizeImport)(&difference);
        deltaSeconds = (float)distance; // Native FST spills into the reused incoming argument without popping ST(0).
        if (!(distance > nativeFloat5) || !(*timer > nativeDouble0Point5))
            return 1;
        owner = reinterpret_cast<byte*&>(this->m_pawnOwner); // Size may have changed the owner or positions.
        difference = *(FVector*)(owner + 0x234); // Reuse the vector buffer previously passed to Size.
        FVector rootPosition = *(FVector*)(ragdoll + 0x3a8);
        void* level = *(void**)(ragdoll + 0x328);
        using Move = int (__thiscall*)(void*, void*, FVector, uint, uint, uint, uint);
        (*(Move*)(*(byte**)level + 0x9c))(level, owner, rootPosition, 0, 0, 0, 0);
        FVector previousPosition = difference;
        owner = reinterpret_cast<byte*&>(this->m_pawnOwner); // Compare against the owner current after movement.
        difference.X = (float)((float10)previousPosition.X - *(float*)(owner + 0x234));
        difference.Y = (float)((float10)previousPosition.Y - *(float*)(owner + 0x238));
        difference.Z = (float)((float10)previousPosition.Z - *(float*)(owner + 0x23c));
        int unchanged = difference.IsNearlyZero();
        if (unchanged == 0)
            *(uint*)timer = 0;
        return 1; // ELevelTick is unused; every normal path returns EAX=1 and pops both incoming words.
    } catch (unsigned short* value) {
        throw value;
    } catch (...) {
        (*(void (__cdecl**)(const unsigned short*, const unsigned short*))((uint)&CoreAppUnwindfImport))(
            (const unsigned short*)((uint)&unwindStringFormat),
                (const unsigned short*)((uint)&nativeTextAR6RagDollTick));
        throw;
    }
}

// R6Engine.dll @ 100352cd : copy the caught pointer into the parent throw slot and forward it.
__declspec(naked) void RagdollTickCatchPointer(void)
{
    __asm {
        mov eax,[ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100352e1 : report Tick context and rethrow the active exception.
__declspec(naked) void RagdollTickCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollTick
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0
        push 0
        call _CxxThrowException
    }
}

// Inferred PE32 view of the script-backed 16-byte spring record; aliasing adds no construction.
struct NativeSpringRecord
{
    int iFirst; // +0x00
    int iSecond; // +0x04
    float fMinSquared; // +0x08
    float fMaxSquared; // +0x0c
};

// R6Engine.dll @ 10035300 : AR6RagDoll::AddSpring
// Appends a spring, preserving disabled -1 bounds, squared distances and the maximum-zero minimum copy.
void __thiscall AR6RagDoll::AddSpring(int firstParticle, int secondParticle, float minimumDistance,
    float maximumDistance)
{
    try {
        FArray* springs = reinterpret_cast<FArray*>(&this->m_aSpring);
        int addedIndex = springs->FArray::Add(1, 16);
        float sentinel = nativeFloatMinus1; // Selected constant is -1.0f, not 15.0f.
        uint data = reinterpret_cast<const NativeArrayHeader32*>(springs)->dataAddress;
        bool minimumDisabled = minimumDistance == sentinel; // Native comparison precedes the record stores.
        int savedSecond = secondParticle;
        // No computed-null guard or rollback.
        NativeSpringRecord* record = reinterpret_cast<NativeSpringRecord*>(data + (uint)addedIndex * 16U);
        record->iFirst = firstParticle;
        record->iSecond = savedSecond;
        if (minimumDisabled) {
            reinterpret_cast<uint&>(record->fMinSquared) = 0xbf800000;
        } else {
            record->fMinSquared = (float)((float10)minimumDistance * minimumDistance); // Resample after index stores.
        }
        if (maximumDistance == nativeFloatZero) { // Both signed zeros copy the current minimum word.
            reinterpret_cast<uint&>(record->fMaxSquared) = reinterpret_cast<const uint&>(record->fMinSquared);
        } else if (maximumDistance == nativeFloatMinus1) {
            reinterpret_cast<uint&>(record->fMaxSquared) = 0xbf800000;
        } else {
            record->fMaxSquared = (float)((float10)maximumDistance * maximumDistance);
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RagDoll::AddSpring");
        throw;
    }
}

// R6Engine.dll @ 100353e5 : RagdollAddSpringCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-18 through EBP-14.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollAddSpringCatchPointer(void)
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

// R6Engine.dll @ 100353f9 : RagdollAddSpringCatchContext
// Reports AddSpring context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollAddSpringCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollAddSpring
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10035420 : AR6RagDoll::FirstInit
// Binds the current owner mesh, seeds sixteen bone origins and appends thirty-two springs.
void __thiscall AR6RagDoll::FirstInit(AR6AbstractPawn* pawnOwner)
{
    using NameConstructor = FName* (__thiscall*)(FName*, const ushort*, int);
    // Captured before owner stores; reused sixteen times.
    NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
    byte* ragdoll = (byte*)this;
    this->m_pawnOwner = pawnOwner;
    reinterpret_cast<uint&>(this->m_fAccumulatedTime) = 0x3ccccccd;
    try {
        reinterpret_cast<uint&>(nativeRagDollStepCount) = 0;
        uint nameScratch; // Native reuses incoming pawnOwner's stack slot for names, then the mesh instance.
        const ushort* const boneNames[16] = {
            (const ushort*)L"R6 Spine1", (const ushort*)L"R6 Pelvis", (const ushort*)L"R6 Neck",
            (const ushort*)L"R6 Head", (const ushort*)L"R6 L UpperArm", (const ushort*)L"R6 L Forearm",
            (const ushort*)L"R6 L Hand", (const ushort*)L"R6 R UpperArm", (const ushort*)L"R6 R Forearm",
            (const ushort*)L"R6 R Hand", (const ushort*)L"R6 L Thigh", (const ushort*)L"R6 L Calf",
            (const ushort*)L"R6 L Foot", (const ushort*)L"R6 R Thigh", (const ushort*)L"R6 R Calf",
            (const ushort*)L"R6 R Foot"
        };
        for (int i = 0; i < 16; ++i) { // Native spells out the same calls and interleaved returned-word stores.
            const uint* name = (const uint*)constructName((FName*)&nameScratch, boneNames[i], 1);
            *(uint*)(ragdoll + 0x3fc + i * 0x58) = *name;
        }
        byte* owner = reinterpret_cast<byte*&>(this->m_pawnOwner);
        UClass* skeletalMeshClass = USkeletalMeshPrivateStaticClassImport;
        UClass* meshClass = reinterpret_cast<UObject*>(*(byte**)(owner + 0x16c))->Class;
        const int toward[16] = {2, 2, 3, -2, 5, 6, -5, 8, 9, -8, 11, 12, -11, 14, 15, -14};
        const float massDivisors[16] = {
            3.0f, 3.0f, 3.0f, 1.5f, 2.0f, 1.0f, 0.5f, 2.0f,
            1.0f, 0.5f, 2.0f, 1.0f, 0.5f, 2.0f, 1.0f, 0.5f
        };
        while (meshClass != nullptr && meshClass != skeletalMeshClass)
            meshClass = meshClass->GetSuperClass();
        if (meshClass == nullptr && skeletalMeshClass != nullptr)
            appFailAssert(nativeTextMPawnOwnerMeshIsAUSkeletalMeshStaticClass, nativePathAR6RagDollCpp, 0x56);
        AR6AbstractPawn* meshOwner = this->m_pawnOwner;
        UMesh* mesh = meshOwner->Mesh;
        byte* returnedInstance = reinterpret_cast<byte*>(mesh->MeshGetInstance(meshOwner));
        byte*& instance = *(byte**)&nameScratch; // Preserve the reused slot if a name provider retained its address.
        instance = returnedInstance;
        byte renderScratch[16]; // Opaque native EBP-d0 output, not the later point transform's FCoords.
        uint renderCount = 0;
        (*(void (__thiscall**)(byte*, AR6RagDoll*, int, void*, int, uint*, int))
            (*(byte**)instance + 0x110))(instance, this, 0, renderScratch, 0, &renderCount, 0);
        float previousDelta[3] = {0.0f, 0.0f, -0.375f};
        FVector transformedPoint; // Native EBP-dc hidden return buffer, separate from renderScratch.
        for (int i = 0; i < 16; ++i) {
            byte* particle = ragdoll + 0x3a8 + i * 0x58;
            *(float*)(particle + 0x48) = (float)((float10)nativeFloatOne / massDivisors[i]);
            uint boneName = *(uint*)(particle + 0x54);
            *(int*)(particle + 0x4c) = toward[i];
            int boneIndex =
                reinterpret_cast<USkeletalMeshInstance*>(instance)->USkeletalMeshInstance::MatchRefBone(
                    reinterpret_cast<FName&>(boneName));
            *(int*)(particle + 0x50) = boneIndex;
            uint* bone = (uint*)(*(byte**)(instance + 0xb8) + (uint)boneIndex * 0x30);
            *(uint*)particle = bone[0];
            *(uint*)(particle + 4) = bone[1];
            *(uint*)(particle + 8) = bone[2];
            if (i == 0) {
                float10 x = (float10)*(float*)particle + nativeFloat1EPlus01;
                uint y = *(uint*)(particle + 4), z = *(uint*)(particle + 8);
                *(uint*)(particle + 4) = y;
                *(uint*)(particle + 8) = z;
                *(float*)particle = (float)x;
            } else if (i == 1) {
                uint rootBoneIndex = *(uint*)(ragdoll + 0x3f8);
                bone = (uint*)(*(byte**)(instance + 0xb8) + rootBoneIndex * 0x30);
                float10 z = *(float*)(bone + 2), y = *(float*)(bone + 1);
                float x = (float)((float10)*(float*)bone - nativeFloat1EPlus01);
                *(float*)particle = x;
                *(float*)(particle + 4) = (float)y;
                *(float*)(particle + 8) = (float)z;
            } else if (i == 3) {
                float10 z = (float10)*(float*)(particle + 8) + nativeFloat1EPlus01;
                uint x = *(uint*)particle, y = *(uint*)(particle + 4);
                *(uint*)particle = x;
                *(uint*)(particle + 4) = y;
                *(float*)(particle + 8) = (float)z;
            }
            const FVector* result = &(transformedPoint =
                reinterpret_cast<const FVector*>(particle)->TransformPointBy(
                    *reinterpret_cast<const FCoords*>(instance + 0xc4)));
            *(uint*)particle = reinterpret_cast<const uint&>(result->X); // Sequential word copies preserve overlap.
            *(uint*)(particle + 4) = reinterpret_cast<const uint&>(result->Y);
            *(uint*)(particle + 8) = reinterpret_cast<const uint&>(result->Z);
            float10 x = *(float*)particle;
            *(float*)particle = (float)x;
            float10 y = *(float*)(particle + 4);
            *(float*)(particle + 4) = (float)y;
            float10 z = (float10)*(float*)(particle + 8) - nativeFloat15;
            float roundedZ = (float)z;
            *(float*)(particle + 8) = (float)z;
            *(float*)(particle + 0x30) = (float)(x - previousDelta[0]);
            *(float*)(particle + 0x34) = (float)(y - previousDelta[1]);
            *(float*)(particle + 0x38) = (float)((float10)roundedZ - previousDelta[2]);
        }
        this->AR6RagDoll::AddSpring(0xb, 0xc, 43.91, 0.0f);
        this->AR6RagDoll::AddSpring(10, 0xb, 42.31, 0.0f);
        this->AR6RagDoll::AddSpring(0, 10, 18.94, 0.0f);
        this->AR6RagDoll::AddSpring(0xe, 0xf, 43.91, 0.0f);
        this->AR6RagDoll::AddSpring(0xd, 0xe, 42.31, 0.0f);
        this->AR6RagDoll::AddSpring(1, 0xd, 18.94, 0.0f);
        this->AR6RagDoll::AddSpring(4, 5, 32.35, 0.0f);
        this->AR6RagDoll::AddSpring(5, 6, 22.6, 0.0f);
        this->AR6RagDoll::AddSpring(7, 8, 32.35, 0.0f);
        this->AR6RagDoll::AddSpring(8, 9, 22.6, 0.0f);
        this->AR6RagDoll::AddSpring(2, 4, 15.22, 0.0f);
        this->AR6RagDoll::AddSpring(2, 7, 15.22, 0.0f);
        this->AR6RagDoll::AddSpring(2, 3, 21.84, 0.0f);
        this->AR6RagDoll::AddSpring(0, 1, 20.0, 0.0f);
        this->AR6RagDoll::AddSpring(10, 0xd, 19.06, 0.0f);
        this->AR6RagDoll::AddSpring(0, 2, 31.02, 0.0f);
        this->AR6RagDoll::AddSpring(1, 2, 31.02, 0.0f);
        this->AR6RagDoll::AddSpring(1, 10, 27.2, 0.0f);
        this->AR6RagDoll::AddSpring(0, 0xd, 27.2, 0.0f);
        this->AR6RagDoll::AddSpring(0, 4, 26.58, 0.0f);
        this->AR6RagDoll::AddSpring(1, 7, 26.57, 0.0f);
        this->AR6RagDoll::AddSpring(0, 7, 36.07, 0.0f);
        this->AR6RagDoll::AddSpring(1, 4, 36.07, 0.0f);
        this->AR6RagDoll::AddSpring(0, 5, 15.0, -1.0);
        this->AR6RagDoll::AddSpring(0, 6, 15.0, -1.0);
        this->AR6RagDoll::AddSpring(1, 8, 15.0, -1.0);
        this->AR6RagDoll::AddSpring(1, 9, 15.0, -1.0);
        this->AR6RagDoll::AddSpring(5, 8, 25.0, -1.0);
        this->AR6RagDoll::AddSpring(0xb, 0xe, 15.0, 50.0);
        this->AR6RagDoll::AddSpring(0xc, 0xf, 15.0, 60.0);
        this->AR6RagDoll::AddSpring(2, 0xc, 100.0, 160.0);
        this->AR6RagDoll::AddSpring(2, 0xf, 100.0, 160.0);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6RagDoll::FirstInit");
        throw;
    }
}

// R6Engine.dll @ 10035b1b : RagdollFirstInitCatchPointer
// Throws the inherited EBP-c4 pointer through EBP-30 without a new stack frame.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollFirstInitCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xc4]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x30]
        push edx
        mov dword ptr [ebp-0x30],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10035b32 : RagdollFirstInitCatchContext
// Reports FirstInit context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RagdollFirstInitCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RagDollFirstInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043710 : RagdollDestructionState0Cleanup
// Tail-enters current corpse-base destruction on the saved object.
__declspec(naked) void __cdecl RagdollDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AR6AbstractCorpseDestructorImport]
    }
}

// R6Engine.dll @ 10043719 : RagdollDestructionState1Cleanup
// Tail-enters the spring-storage forwarder on saved object+39c.
__declspec(naked) void __cdecl RagdollDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x39c
        jmp ForwardSixteenByteArrayDestruction
    }
}

// R6Engine.dll @ 10043740 : RagdollCopyState0Cleanup
// Tail-enters current corpse-base destruction on the saved object.
__declspec(naked) void __cdecl RagdollCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AR6AbstractCorpseDestructorImport]
    }
}

// R6Engine.dll @ 10044d10 : RagdollRenderBonesState1Cleanup
// Tail-enters current line-batcher destruction on the inherited parent-frame local at EBP-118.
__declspec(naked) void __cdecl RagdollRenderBonesState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x118]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 100457f0 : InitializeAR6RagDollClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6RagDollClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AR6AbstractCorpse object address, captured before config lookup.
    UClass* parentClass = AR6AbstractCorpsePrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6RagDoll::PrivateStaticClass, 0, 0x928, 0,
        parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6RagDoll, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6RagDoll::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6RagDollClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10047f20 : DestroyAR6RagDollClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6RagDollClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6RagDoll::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045880 : PublishAR6RagDollAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6RagDollAutoClass(void)
{
    autoclassAR6RagDoll = &AR6RagDoll::PrivateStaticClass;
}

// R6Engine.dll @ 10043727 : ragdollDestructionExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl ragdollDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043749 : ragdollCopyExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl ragdollCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollCopyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100124b0 : AR6RagDoll::DeletingDestructor
// Destroys one ragdoll or a cookie-counted array and optionally frees the captured allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6RagDoll::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6RagDoll* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6RagDollDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x928, count, callback);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6RagDoll::~AR6RagDoll();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x928);
    }
    return object;
}

// R6Engine.dll @ 10044d1c : RagDollRenderBonesExceptionHandler
// Supplies the exact renderer FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl RagDollRenderBonesExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollRenderBonesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d30 : RagDollConstraintsExceptionHandler
// Supplies the constraint parent's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl RagDollConstraintsExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollConstraintsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d40 : ragdollCollisionExceptionHandler
// Supplies the exact parent FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl ragdollCollisionExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollCollisionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d60 : ragdollAddSpringExceptionHandler
// Supplies the exact parent FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl ragdollAddSpringExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollAddSpringFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d50 : supply Tick's exact parent-frame FuncInfo to the shared dispatcher.
__declspec(naked) void RagdollTickExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollTickFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044d70 : RagdollFirstInitExceptionHandler
// Supplies FirstInit's exact parent FuncInfo to the inherited dispatcher frame.
__declspec(naked) void RagdollFirstInitExceptionHandler(void)
{
    __asm {
        mov eax,offset ragdollFirstInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000d920 : AssignRecords16
// Reuses array storage for raw 16-byte copies, with an identity fast path and live source count/data reloads.
FArray* __thiscall AssignRecords16(FArray* destination, const FArray* source)
{
    NativeArrayHeader32* destinationHeaderView = reinterpret_cast<NativeArrayHeader32*>(destination);
    const NativeArrayHeader32* sourceHeaderView = reinterpret_cast<const NativeArrayHeader32*>(source);
    if (destination == source) return destination;
    int initialCount = sourceHeaderView->count;
    destinationHeaderView->count = 0;
    destinationHeaderView->capacity = initialCount;
    // Existing data pointer is retained until this callback changes it.
    destination->FArray::Realloc(16);
    int liveCount = sourceHeaderView->count;
    uint index = 0;
    while ((int)index < liveCount) {
        int addedIndex = destination->FArray::Add(1, 16);
        uint outputAddress = destinationHeaderView->dataAddress + (uint)addedIndex * 16U;
        if (outputAddress != 0) {
            uint sourceData = sourceHeaderView->dataAddress;
            const byte* input = (const byte*)(sourceData + index * 16U);
            *(uint*)outputAddress = *(const uint*)input;
            *(uint*)(outputAddress + 4) = *(const uint*)(input + 4);
            *(uint*)(outputAddress + 8) = *(const uint*)(input + 8);
            *(uint*)(outputAddress + 12) = *(const uint*)(input + 12);
        }
        liveCount = sourceHeaderView->count;
        ++index;
    }
    return destination; // No method guard, rollback or per-element destructor exists.
}

// R6Engine.dll @ 1000ff30 : ForwardSixteenByteArrayDestruction
// Tail-enters 16-byte array destruction with the original ECX receiver, stack and return frame.
__declspec(naked) void __thiscall ForwardSixteenByteArrayDestruction(FArray* array)
{
    __asm {
        jmp DestroySixteenByteArrayStorage
    }
}
