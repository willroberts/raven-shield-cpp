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
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void GetAnimStateExceptionHandler(void);
__declspec(naked) void initCrawlModeExceptionHandler(void);
__declspec(naked) void CrawlExceptionHandler(void);
__declspec(naked) void UnCrawlExceptionHandler(void);
__declspec(naked) void performPhysicsExceptionHandler(void);
__declspec(naked) void execGetMovementDirectionExceptionHandler(void);
__declspec(naked) void execCheckCylinderTranslationExceptionHandler(void);
__declspec(naked) void AdjustCylinderExceptionHandler(void);
__declspec(naked) void MoveToPositionExceptionHandler(void);
FVector* __cdecl ScaleVectorToResult(FVector* result, float scale, const FVector* source);
__declspec(naked) void PawnPickActorAdjustExceptionHandler(void);
FCheckResult* __thiscall InitializeCheckResult(FCheckResult* result, float initialTime,
    FCheckResult* next);
__declspec(naked) void physicsRotationExceptionHandler(void);
int __cdecl CastToAPlayerController(int object);
__declspec(naked) void physLadderExceptionHandler(void);
__declspec(naked) void CheckForLedgesExceptionHandler(void);
__declspec(naked) void UpdateColBoxExceptionHandler(void);
__declspec(naked) void BeginTouchExceptionHandler(void);
__declspec(naked) void UpdateColBoxPeekingExceptionHandler(void);
__declspec(naked) void execFootStepExceptionHandler(void);
__declspec(naked) void SetPawnLookDirectionExceptionHandler(void);
__declspec(naked) void SetPawnLookAndAimDirectionExceptionHandler(void);
float10 __cdecl SquaredDistanceBetweenVectors(const float *firstVector, const float *secondVector);
int __cdecl CastToAR6SAHeartBeatJammer(int object);
void __stdcall ConstructArrayElements(void* firstElement, uint elementSize, int elementCount,
    void (__thiscall *constructElement)(void*));
float10 __cdecl NegateNegativeOrUnordered(float value);
__declspec(naked) void __cdecl DestroyAR6PawnClassMetadata(void);

// Native guard metadata; partial PE32 records retain the existing frame and cleanup contracts.
__declspec(naked) void AR6PawnSharedConstructionCatchPointer(void);
__declspec(naked) void AR6PawnSharedConstructionCatchContext(void);
__declspec(naked) void AR6PawninitCrawlModeCatchPointer(void);
__declspec(naked) void AR6PawninitCrawlModeCatchContext(void);
__declspec(naked) void AR6PawnCrawlCatchPointer(void);
__declspec(naked) void AR6PawnCrawlCatchContext(void);
__declspec(naked) void AR6PawnUnCrawlCatchPointer(void);
__declspec(naked) void AR6PawnUnCrawlCatchContext(void);
__declspec(naked) void AR6PawnperformPhysicsCatchPointer(void);
__declspec(naked) void AR6PawnperformPhysicsCatchContext(void);
__declspec(naked) void AR6PawnexecGetMovementDirectionCatchPointer(void);
__declspec(naked) void AR6PawnexecGetMovementDirectionCatchContext(void);
__declspec(naked) void AR6PawnexecCheckCylinderTranslationCatchPointer(void);
__declspec(naked) void AR6PawnexecCheckCylinderTranslationCatchContext(void);
__declspec(naked) void AR6PawnphysicsRotationCatchPointer(void);
__declspec(naked) void AR6PawnphysicsRotationCatchContext(void);
__declspec(naked) void AR6PawnphysLadderCatchPointer(void);
__declspec(naked) void AR6PawnphysLadderCatchContext(void);
__declspec(naked) void AR6PawnCheckForLedgesCatchPointer(void);
__declspec(naked) void AR6PawnCheckForLedgesCatchContext(void);
__declspec(naked) void AR6PawnUpdateColBoxCatchPointer(void);
__declspec(naked) void AR6PawnUpdateColBoxCatchContext(void);
__declspec(naked) void AR6PawnAR6PawnSharedConstructionCatchPointer(void);
__declspec(naked) void AR6PawnAR6PawnSharedConstructionCatchContext(void);
__declspec(naked) void AR6PawnUpdateColBoxPeekingCatchPointer(void);
__declspec(naked) void AR6PawnUpdateColBoxPeekingCatchContext(void);
__declspec(naked) void AR6PawnexecFootStepCatchPointer(void);
__declspec(naked) void AR6PawnexecFootStepCatchContext(void);
__declspec(naked) void AR6PawnSetPawnLookDirectionCatchPointer(void);
__declspec(naked) void AR6PawnSetPawnLookDirectionCatchContext(void);
__declspec(naked) void AR6PawnSetPawnLookAndAimDirectionCatchPointer(void);
__declspec(naked) void AR6PawnSetPawnLookAndAimDirectionCatchContext(void);

// External native storage views; names describe roles rather than recovered original identifiers.
float10 __cdecl ClampFloatOrdered(float value, float minimum, float maximum);

float10 __cdecl MinFloatOrdered(float first, float second);

int __cdecl CastToUNetConnection(int object);

uint __thiscall FindPointerMapWord(void* map, const uint* keyReference);

// R6Engine.dll data @ 10050ff0 : nativeFloat1Point4
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat1Point4;

// R6Engine.dll data @ 10050ff4 : nativeFloat1Point2
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat1Point2;

// R6Engine.dll data @ 10050ff8 : nativeFloat0Point6
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat0Point6;

// R6Engine.dll data @ 10051754 : nativeFloat16
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat16;

// R6Engine.dll data @ 10051758 : nativeFloat32
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat32;

// R6Engine.dll data @ 1005175c : nativeFloatMinus5
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloatMinus5;

// R6Engine.dll data @ 100519d0 : nativeFloatMinus10000
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloatMinus10000;

// R6Engine.dll data @ 100519d4 : nativeFloat14000
// Conditional float operand; selection/read timing stays explicit.
extern const float nativeFloat14000;

// R6Engine.dll data @ 100754fc : nativePawnPonyTailName
// Shared pony-tail FName storage; current guard/name sampling remains explicit.
extern FName nativePawnPonyTailName;

// R6Engine.dll data @ 10075500 : nativePawnPonyTailNameGuard
// Shared pony-tail name initialization guard.
extern uint nativePawnPonyTailNameGuard;

// R6Engine.dll data @ 10076480 : nativeChartsReceiver
// Address used as the existing Charts receiver; only the storage prefix is identified,no object size/layout is claimed.
extern R6Charts nativeChartsReceiver;

// R6Engine.dll data @ 1005aecc : GetAnimStateUnwindMap
const NativeUnwindEntry GetAnimStateUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005af2c : initCrawlModeUnwindMap
const NativeUnwindEntry initCrawlModeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005af8c : CrawlUnwindMap
const NativeUnwindEntry CrawlUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005afec : UnCrawlUnwindMap
const NativeUnwindEntry UnCrawlUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b04c : performPhysicsUnwindMap
const NativeUnwindEntry performPhysicsUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b0ac : execGetMovementDirectionUnwindMap
const NativeUnwindEntry execGetMovementDirectionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b10c : execCheckCylinderTranslationUnwindMap
const NativeUnwindEntry execCheckCylinderTranslationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b28c : physicsRotationUnwindMap
const NativeUnwindEntry physicsRotationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b2ec : physLadderUnwindMap
const NativeUnwindEntry physLadderUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b34c : CheckForLedgesUnwindMap
const NativeUnwindEntry CheckForLedgesUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b3ac : UpdateColBoxUnwindMap
const NativeUnwindEntry UpdateColBoxUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b40c : BeginTouchUnwindMap
const NativeUnwindEntry BeginTouchUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b4cc : UpdateColBoxPeekingUnwindMap
const NativeUnwindEntry UpdateColBoxPeekingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b52c : execFootStepUnwindMap
const NativeUnwindEntry execFootStepUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b58c : SetPawnLookDirectionUnwindMap
const NativeUnwindEntry SetPawnLookDirectionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b5ec : SetPawnLookAndAimDirectionUnwindMap
const NativeUnwindEntry SetPawnLookAndAimDirectionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005aedc : GetAnimStateCatchMap
const NativeCatchEntry GetAnimStateCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&AR6PawnSharedConstructionCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnSharedConstructionCatchContext) }
};

// R6Engine.dll data @ 1005af3c : initCrawlModeCatchMap
const NativeCatchEntry initCrawlModeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6PawninitCrawlModeCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawninitCrawlModeCatchContext) }
};

// R6Engine.dll data @ 1005af9c : CrawlCatchMap
const NativeCatchEntry CrawlCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -148, ((uint)&AR6PawnCrawlCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnCrawlCatchContext) }
};

// R6Engine.dll data @ 1005affc : UnCrawlCatchMap
const NativeCatchEntry UnCrawlCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&AR6PawnUnCrawlCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnUnCrawlCatchContext) }
};

// R6Engine.dll data @ 1005b05c : performPhysicsCatchMap
const NativeCatchEntry performPhysicsCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6PawnperformPhysicsCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnperformPhysicsCatchContext) }
};

// R6Engine.dll data @ 1005b0bc : execGetMovementDirectionCatchMap
const NativeCatchEntry execGetMovementDirectionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6PawnexecGetMovementDirectionCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnexecGetMovementDirectionCatchContext) }
};

// R6Engine.dll data @ 1005b11c : execCheckCylinderTranslationCatchMap
const NativeCatchEntry execCheckCylinderTranslationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&AR6PawnexecCheckCylinderTranslationCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnexecCheckCylinderTranslationCatchContext) }
};

// R6Engine.dll data @ 1005b29c : physicsRotationCatchMap
const NativeCatchEntry physicsRotationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&AR6PawnphysicsRotationCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnphysicsRotationCatchContext) }
};

// R6Engine.dll data @ 1005b2fc : physLadderCatchMap
const NativeCatchEntry physLadderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&AR6PawnphysLadderCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnphysLadderCatchContext) }
};

// R6Engine.dll data @ 1005b35c : CheckForLedgesCatchMap
const NativeCatchEntry CheckForLedgesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -204, ((uint)&AR6PawnCheckForLedgesCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnCheckForLedgesCatchContext) }
};

// R6Engine.dll data @ 1005b3bc : UpdateColBoxCatchMap
const NativeCatchEntry UpdateColBoxCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -176, ((uint)&AR6PawnUpdateColBoxCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnUpdateColBoxCatchContext) }
};

// R6Engine.dll data @ 1005b41c : BeginTouchCatchMap
const NativeCatchEntry BeginTouchCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6PawnAR6PawnSharedConstructionCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnAR6PawnSharedConstructionCatchContext) }
};

// R6Engine.dll data @ 1005b4dc : UpdateColBoxPeekingCatchMap
const NativeCatchEntry UpdateColBoxPeekingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -44, ((uint)&AR6PawnUpdateColBoxPeekingCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnUpdateColBoxPeekingCatchContext) }
};

// R6Engine.dll data @ 1005b53c : execFootStepCatchMap
const NativeCatchEntry execFootStepCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -104, ((uint)&AR6PawnexecFootStepCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnexecFootStepCatchContext) }
};

// R6Engine.dll data @ 1005b59c : SetPawnLookDirectionCatchMap
const NativeCatchEntry SetPawnLookDirectionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -48, ((uint)&AR6PawnSetPawnLookDirectionCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnSetPawnLookDirectionCatchContext) }
};

// R6Engine.dll data @ 1005b5fc : SetPawnLookAndAimDirectionCatchMap
const NativeCatchEntry SetPawnLookAndAimDirectionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&AR6PawnSetPawnLookAndAimDirectionCatchPointer) },
    { 0, 0, 0, ((uint)&AR6PawnSetPawnLookAndAimDirectionCatchContext) }
};

// R6Engine.dll data @ 1005aefc : GetAnimStateTryMap
const NativeTryBlock GetAnimStateTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&GetAnimStateCatchMap) }
};

// R6Engine.dll data @ 1005af5c : initCrawlModeTryMap
const NativeTryBlock initCrawlModeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&initCrawlModeCatchMap) }
};

// R6Engine.dll data @ 1005afbc : CrawlTryMap
const NativeTryBlock CrawlTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&CrawlCatchMap) }
};

// R6Engine.dll data @ 1005b01c : UnCrawlTryMap
const NativeTryBlock UnCrawlTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&UnCrawlCatchMap) }
};

// R6Engine.dll data @ 1005b07c : performPhysicsTryMap
const NativeTryBlock performPhysicsTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&performPhysicsCatchMap) }
};

// R6Engine.dll data @ 1005b0dc : execGetMovementDirectionTryMap
const NativeTryBlock execGetMovementDirectionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execGetMovementDirectionCatchMap) }
};

// R6Engine.dll data @ 1005b13c : execCheckCylinderTranslationTryMap
const NativeTryBlock execCheckCylinderTranslationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execCheckCylinderTranslationCatchMap) }
};

// R6Engine.dll data @ 1005b2bc : physicsRotationTryMap
const NativeTryBlock physicsRotationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&physicsRotationCatchMap) }
};

// R6Engine.dll data @ 1005b31c : physLadderTryMap
const NativeTryBlock physLadderTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&physLadderCatchMap) }
};

// R6Engine.dll data @ 1005b37c : CheckForLedgesTryMap
const NativeTryBlock CheckForLedgesTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&CheckForLedgesCatchMap) }
};

// R6Engine.dll data @ 1005b3dc : UpdateColBoxTryMap
const NativeTryBlock UpdateColBoxTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&UpdateColBoxCatchMap) }
};

// R6Engine.dll data @ 1005b43c : BeginTouchTryMap
const NativeTryBlock BeginTouchTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&BeginTouchCatchMap) }
};

// R6Engine.dll data @ 1005b4fc : UpdateColBoxPeekingTryMap
const NativeTryBlock UpdateColBoxPeekingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&UpdateColBoxPeekingCatchMap) }
};

// R6Engine.dll data @ 1005b55c : execFootStepTryMap
const NativeTryBlock execFootStepTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execFootStepCatchMap) }
};

// R6Engine.dll data @ 1005b5bc : SetPawnLookDirectionTryMap
const NativeTryBlock SetPawnLookDirectionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&SetPawnLookDirectionCatchMap) }
};

// R6Engine.dll data @ 1005b61c : SetPawnLookAndAimDirectionTryMap
const NativeTryBlock SetPawnLookAndAimDirectionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&SetPawnLookAndAimDirectionCatchMap) }
};

// R6Engine.dll data @ 1005af10 : GetAnimStateFuncInfo
const NativeFunctionInfoPrefix GetAnimStateFuncInfo = {
    0x19930520, 0x2, ((uint)&GetAnimStateUnwindMap), 0x1, ((uint)&GetAnimStateTryMap), 0
};

// R6Engine.dll data @ 1005af70 : initCrawlModeFuncInfo
const NativeFunctionInfoPrefix initCrawlModeFuncInfo = {
    0x19930520, 0x2, ((uint)&initCrawlModeUnwindMap), 0x1, ((uint)&initCrawlModeTryMap), 0
};

// R6Engine.dll data @ 1005afd0 : CrawlFuncInfo
const NativeFunctionInfoPrefix CrawlFuncInfo = {
    0x19930520, 0x2, ((uint)&CrawlUnwindMap), 0x1, ((uint)&CrawlTryMap), 0
};

// R6Engine.dll data @ 1005b030 : UnCrawlFuncInfo
const NativeFunctionInfoPrefix UnCrawlFuncInfo = {
    0x19930520, 0x2, ((uint)&UnCrawlUnwindMap), 0x1, ((uint)&UnCrawlTryMap), 0
};

// R6Engine.dll data @ 1005b090 : performPhysicsFuncInfo
const NativeFunctionInfoPrefix performPhysicsFuncInfo = {
    0x19930520, 0x2, ((uint)&performPhysicsUnwindMap), 0x1, ((uint)&performPhysicsTryMap), 0
};

// R6Engine.dll data @ 1005b0f0 : execGetMovementDirectionFuncInfo
const NativeFunctionInfoPrefix execGetMovementDirectionFuncInfo = {
    0x19930520, 0x2, ((uint)&execGetMovementDirectionUnwindMap), 0x1, ((uint)&execGetMovementDirectionTryMap), 0
};

// R6Engine.dll data @ 1005b150 : execCheckCylinderTranslationFuncInfo
const NativeFunctionInfoPrefix execCheckCylinderTranslationFuncInfo = {
    0x19930520, 0x2, ((uint)&execCheckCylinderTranslationUnwindMap), 0x1, ((uint)&execCheckCylinderTranslationTryMap), 0
};

// R6Engine.dll data @ 1005b2d0 : physicsRotationFuncInfo
const NativeFunctionInfoPrefix physicsRotationFuncInfo = {
    0x19930520, 0x2, ((uint)&physicsRotationUnwindMap), 0x1, ((uint)&physicsRotationTryMap), 0
};

// R6Engine.dll data @ 1005b330 : physLadderFuncInfo
const NativeFunctionInfoPrefix physLadderFuncInfo = {
    0x19930520, 0x2, ((uint)&physLadderUnwindMap), 0x1, ((uint)&physLadderTryMap), 0
};

// R6Engine.dll data @ 1005b390 : CheckForLedgesFuncInfo
const NativeFunctionInfoPrefix CheckForLedgesFuncInfo = {
    0x19930520, 0x2, ((uint)&CheckForLedgesUnwindMap), 0x1, ((uint)&CheckForLedgesTryMap), 0
};

// R6Engine.dll data @ 1005b3f0 : UpdateColBoxFuncInfo
const NativeFunctionInfoPrefix UpdateColBoxFuncInfo = {
    0x19930520, 0x2, ((uint)&UpdateColBoxUnwindMap), 0x1, ((uint)&UpdateColBoxTryMap), 0
};

// R6Engine.dll data @ 1005b450 : BeginTouchFuncInfo
const NativeFunctionInfoPrefix BeginTouchFuncInfo = {
    0x19930520, 0x2, ((uint)&BeginTouchUnwindMap), 0x1, ((uint)&BeginTouchTryMap), 0
};

// R6Engine.dll data @ 1005b510 : UpdateColBoxPeekingFuncInfo
const NativeFunctionInfoPrefix UpdateColBoxPeekingFuncInfo = {
    0x19930520, 0x2, ((uint)&UpdateColBoxPeekingUnwindMap), 0x1, ((uint)&UpdateColBoxPeekingTryMap), 0
};

// R6Engine.dll data @ 1005b570 : execFootStepFuncInfo
const NativeFunctionInfoPrefix execFootStepFuncInfo = {
    0x19930520, 0x2, ((uint)&execFootStepUnwindMap), 0x1, ((uint)&execFootStepTryMap), 0
};

// R6Engine.dll data @ 1005b5d0 : SetPawnLookDirectionFuncInfo
const NativeFunctionInfoPrefix SetPawnLookDirectionFuncInfo = {
    0x19930520, 0x2, ((uint)&SetPawnLookDirectionUnwindMap), 0x1, ((uint)&SetPawnLookDirectionTryMap), 0
};

// R6Engine.dll data @ 1005b630 : SetPawnLookAndAimDirectionFuncInfo
const NativeFunctionInfoPrefix SetPawnLookAndAimDirectionFuncInfo = {
    0x19930520, 0x2, ((uint)&SetPawnLookAndAimDirectionUnwindMap), 0x1, ((uint)&SetPawnLookAndAimDirectionTryMap), 0
};

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 10049ba8 : AR6PawnVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Pawn::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6PawnVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10051624 : nativePathAR6PawnCpp
extern const char nativePathAR6PawnCpp[18];

// R6Engine.dll data @ 10051ab8 : nativeTextAPawnIsRelevantToPawnHeatVision
extern const ushort nativeTextAPawnIsRelevantToPawnHeatVision[34];

// R6Engine.dll data @ 10051bb8 : nativeTextAPawnMoveToward
extern const ushort nativeTextAPawnMoveToward[18];

// R6Engine.dll data @ 10051b08 : nativeTextAR6PawnActorReachableFromLocation
extern const ushort nativeTextAR6PawnActorReachableFromLocation[36];

// R6Engine.dll data @ 10051540 : nativeTextAR6PawnAdjustFluidCollisionCylinder
extern const ushort nativeTextAR6PawnAdjustFluidCollisionCylinder[38];

// R6Engine.dll data @ 10051784 : nativeTextAR6PawnBeginTouch
extern const ushort nativeTextAR6PawnBeginTouch[20];

// R6Engine.dll data @ 10050f18 : nativeTextAR6PawnCalcVelocity
extern const ushort nativeTextAR6PawnCalcVelocity[22];

// R6Engine.dll data @ 100516dc : nativeTextAR6PawnCheckForLedges
extern const ushort nativeTextAR6PawnCheckForLedges[24];

// R6Engine.dll data @ 10051d64 : nativeTextAR6PawnCheckLineOfSight
extern const ushort nativeTextAR6PawnCheckLineOfSight[26];

// R6Engine.dll data @ 100513f8 : nativeTextAR6PawnCrawl
extern const ushort nativeTextAR6PawnCrawl[15];

// R6Engine.dll data @ 10050f50 : nativeTextAR6PawnDirectionChanged
extern const ushort nativeTextAR6PawnDirectionChanged[26];

// R6Engine.dll data @ 10051b60 : nativeTextAR6PawnExecAdjustFluidCollisionCylinder
extern const ushort nativeTextAR6PawnExecAdjustFluidCollisionCylinder[42];

// R6Engine.dll data @ 100514f0 : nativeTextAR6PawnExecCheckCylinderTranslation
extern const ushort nativeTextAR6PawnExecCheckCylinderTranslation[38];

// R6Engine.dll data @ 10051968 : nativeTextAR6PawnExecFootStep
extern const ushort nativeTextAR6PawnExecFootStep[22];

// R6Engine.dll data @ 10055458 : nativeTextAR6PawnExecGetKillResult
extern const ushort nativeTextAR6PawnExecGetKillResult[27];

// R6Engine.dll data @ 100514a8 : nativeTextAR6PawnExecGetMovementDirection
extern const ushort nativeTextAR6PawnExecGetMovementDirection[34];

// R6Engine.dll data @ 100510c8 : nativeTextAR6PawnExecGetPeekingRatioNorm
extern const ushort nativeTextAR6PawnExecGetPeekingRatioNorm[33];

// R6Engine.dll data @ 1005135c : nativeTextAR6PawnExecGetRotationOffset
extern const ushort nativeTextAR6PawnExecGetRotationOffset[31];

// R6Engine.dll data @ 10055558 : nativeTextAR6PawnExecGetStunResult
extern const ushort nativeTextAR6PawnExecGetStunResult[27];

// R6Engine.dll data @ 10055510 : nativeTextAR6PawnExecGetThroughResult
extern const ushort nativeTextAR6PawnExecGetThroughResult[30];

// R6Engine.dll data @ 10051c38 : nativeTextAR6PawnExecMoveHitBone
extern const ushort nativeTextAR6PawnExecMoveHitBone[25];

// R6Engine.dll data @ 10051a78 : nativeTextAR6PawnExecPawnCanBeHurtFrom
extern const ushort nativeTextAR6PawnExecPawnCanBeHurtFrom[31];

// R6Engine.dll data @ 10051e38 : nativeTextAR6PawnExecPawnLook
extern const ushort nativeTextAR6PawnExecPawnLook[22];

// R6Engine.dll data @ 10051e64 : nativeTextAR6PawnExecPawnLookAbsolute
extern const ushort nativeTextAR6PawnExecPawnLookAbsolute[30];

// R6Engine.dll data @ 10051ea0 : nativeTextAR6PawnExecPawnLookAt
extern const ushort nativeTextAR6PawnExecPawnLookAt[24];

// R6Engine.dll data @ 10051fc4 : nativeTextAR6PawnExecPawnTrackActor
extern const ushort nativeTextAR6PawnExecPawnTrackActor[28];

// R6Engine.dll data @ 1005131c : nativeTextAR6PawnExecR6GetViewRotation
extern const ushort nativeTextAR6PawnExecR6GetViewRotation[31];

// R6Engine.dll data @ 10055380 : nativeTextAR6PawnExecToggleHeatProperties
extern const ushort nativeTextAR6PawnExecToggleHeatProperties[34];

// R6Engine.dll data @ 100553c8 : nativeTextAR6PawnExecToggleNightProperties
extern const ushort nativeTextAR6PawnExecToggleNightProperties[35];

// R6Engine.dll data @ 10055410 : nativeTextAR6PawnExecToggleScopeProperties
extern const ushort nativeTextAR6PawnExecToggleScopeProperties[35];

// R6Engine.dll data @ 10051ed0 : nativeTextAR6PawnExecUpdatePawnTrackActor
extern const ushort nativeTextAR6PawnExecUpdatePawnTrackActor[34];

// R6Engine.dll data @ 1005139c : nativeTextAR6PawnGetAnimState
extern const ushort nativeTextAR6PawnGetAnimState[22];

// R6Engine.dll data @ 10050ec4 : nativeTextAR6PawnGetMovementDirection
extern const ushort nativeTextAR6PawnGetMovementDirection[30];

// R6Engine.dll data @ 10051a28 : nativeTextAR6PawnGetViewRotation
extern const ushort nativeTextAR6PawnGetViewRotation[25];

// R6Engine.dll data @ 100513c8 : nativeTextAR6PawnInitCrawlMode
extern const ushort nativeTextAR6PawnInitCrawlMode[23];

// R6Engine.dll data @ 10051050 : nativeTextAR6PawnIsOverLedge
extern const ushort nativeTextAR6PawnIsOverLedge[21];

// R6Engine.dll data @ 10051cf0 : nativeTextAR6PawnIsRelevantToPawnHeartBeat
extern const ushort nativeTextAR6PawnIsRelevantToPawnHeartBeat[35];

// R6Engine.dll data @ 10051110 : nativeTextAR6PawnIsUsingHeartBeatSensor
extern const ushort nativeTextAR6PawnIsUsingHeartBeatSensor[32];

// R6Engine.dll data @ 1005158c : nativeTextAR6PawnMoveToPosition
extern const ushort nativeTextAR6PawnMoveToPosition[24];

// R6Engine.dll data @ 10051c70 : nativeTextAR6PawnPawnLook
extern const ushort nativeTextAR6PawnPawnLook[18];

// R6Engine.dll data @ 10051c94 : nativeTextAR6PawnPawnLookAbsolute
extern const ushort nativeTextAR6PawnPawnLookAbsolute[26];

// R6Engine.dll data @ 10051cc8 : nativeTextAR6PawnPawnLookAt
extern const ushort nativeTextAR6PawnPawnLookAt[20];

// R6Engine.dll data @ 10051190 : nativeTextAR6PawnPawnSetBoneRotation
extern const ushort nativeTextAR6PawnPawnSetBoneRotation[29];

// R6Engine.dll data @ 1005143c : nativeTextAR6PawnPerformPhysics
extern const ushort nativeTextAR6PawnPerformPhysics[24];

// R6Engine.dll data @ 100516a8 : nativeTextAR6PawnPhysLadder
extern const ushort nativeTextAR6PawnPhysLadder[20];

// R6Engine.dll data @ 1005163c : nativeTextAR6PawnPhysicsRotation
extern const ushort nativeTextAR6PawnPhysicsRotation[25];

// R6Engine.dll data @ 100515c8 : nativeTextAR6PawnPickWallAdjust
extern const ushort nativeTextAR6PawnPickWallAdjust[24];

// R6Engine.dll data @ 10050fb4 : nativeTextAR6PawnPostNetReceive
extern const ushort nativeTextAR6PawnPostNetReceive[24];

// R6Engine.dll data @ 10050f84 : nativeTextAR6PawnPreNetReceive
extern const ushort nativeTextAR6PawnPreNetReceive[23];

// R6Engine.dll data @ 10051da0 : nativeTextAR6PawnR6LineOfSightTo
extern const ushort nativeTextAR6PawnR6LineOfSightTo[25];

// R6Engine.dll data @ 10051020 : nativeTextAR6PawnR6SeePawn
extern const ushort nativeTextAR6PawnR6SeePawn[19];

// R6Engine.dll data @ 1005107c : nativeTextAR6PawnResetColBox
extern const ushort nativeTextAR6PawnResetColBox[23];

// R6Engine.dll data @ 10051d38 : nativeTextAR6PawnSetAudioInfo
extern const ushort nativeTextAR6PawnSetAudioInfo[22];

// R6Engine.dll data @ 100519e0 : nativeTextAR6PawnSetPawnLookAndAimDirection
extern const ushort nativeTextAR6PawnSetPawnLookAndAimDirection[36];

// R6Engine.dll data @ 10051994 : nativeTextAR6PawnSetPawnLookDirection
extern const ushort nativeTextAR6PawnSetPawnLookDirection[30];

// R6Engine.dll data @ 10051418 : nativeTextAR6PawnUnCrawl
extern const ushort nativeTextAR6PawnUnCrawl[17];

// R6Engine.dll data @ 10051728 : nativeTextAR6PawnUpdateColBox
extern const ushort nativeTextAR6PawnUpdateColBox[22];

// R6Engine.dll data @ 1005187c : nativeTextAR6PawnUpdateColBoxPeeking
extern const ushort nativeTextAR6PawnUpdateColBoxPeeking[29];

// R6Engine.dll data @ 10051bdc : nativeTextAR6PawnUpdateFullPeekingMode
extern const ushort nativeTextAR6PawnUpdateFullPeekingMode[31];

// R6Engine.dll data @ 10051f18 : nativeTextAR6PawnUpdateMovementAnimation
extern const ushort nativeTextAR6PawnUpdateMovementAnimation[33];

// R6Engine.dll data @ 10051dd4 : nativeTextAR6PawnUpdatePeeking
extern const ushort nativeTextAR6PawnUpdatePeeking[23];

// R6Engine.dll data @ 100511cc : nativeTextAR6PawnWeaponFollow
extern const ushort nativeTextAR6PawnWeaponFollow[22];

// R6Engine.dll data @ 100512a0 : nativeTextAR6PawnWeaponLock
extern const ushort nativeTextAR6PawnWeaponLock[20];

// R6Engine.dll data @ 10051150 : nativeTextAR6PawnWeaponShouldFollowHead
extern const ushort nativeTextAR6PawnWeaponShouldFollowHead[32];

// R6Engine.dll data @ 10051610 : nativeTextFAdjustDistLeft0F
extern const char nativeTextFAdjustDistLeft0F[20];

// R6Engine.dll data @ 100515f8 : nativeTextFAdjustDistRight0F
extern const char nativeTextFAdjustDistRight0F[21];

// R6Engine.dll data @ 10051268 : nativeTextR6LClavicle
extern const ushort nativeTextR6LClavicle[14];

// R6Engine.dll data @ 10055602 : nativeTextR6Pawn
extern const ushort nativeTextR6Pawn[7];

// R6Engine.dll data @ 10051764 : nativeTextR6Pelvis
extern const ushort nativeTextR6Pelvis[10];

// R6Engine.dll data @ 10051284 : nativeTextR6RClavicle
extern const ushort nativeTextR6RClavicle[14];

// R6Engine.dll data @ 10051470 : nativeTextSFellOutOfTheWorld
extern const ushort nativeTextSFellOutOfTheWorld[26];

// R6Engine.dll data @ 10051678 : nativeTextThisMCollisionBoxBase
extern const char nativeTextThisMCollisionBoxBase[29];

// R6Engine.dll data @ 100518c0 : nativeTextWARNINGAR6ColBoxEnableCollisionOwnerIsNullInUpdateColBoxPeeking
extern const ushort nativeTextWARNINGAR6ColBoxEnableCollisionOwnerIsNullInUpdateColBoxPeeking[80];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void AdjustCylinderCatchContext(void);
__declspec(naked) void AdjustCylinderCatchPointer(void);
__declspec(naked) void AudioInfoCatchContext(void);
__declspec(naked) void AudioInfoCatchPointer(void);
__declspec(naked) void BoneRotationCatchContext(void);
__declspec(naked) void BoneRotationCatchPointer(void);
__declspec(naked) void CalcVelocityCatchContext(void);
__declspec(naked) void CalcVelocityCatchPointer(void);
__declspec(naked) void CheckLineOfSightExceptionHandler(void);
__declspec(naked) void CylinderBridgeCatchContext(void);
__declspec(naked) void CylinderBridgeCatchPointer(void);
__declspec(naked) void CylinderBridgeExceptionHandler(void);
__declspec(naked) void DirectionChangedCatchContext(void);
__declspec(naked) void DirectionChangedCatchPointer(void);
__declspec(naked) void ExecPawnLookAbsoluteCatchContext(void);
__declspec(naked) void ExecPawnLookAbsoluteCatchPointer(void);
__declspec(naked) void ExecPawnLookAtCatchContext(void);
__declspec(naked) void ExecPawnLookAtCatchPointer(void);
__declspec(naked) void ExecPawnLookCatchContext(void);
__declspec(naked) void ExecPawnLookCatchPointer(void);
__declspec(naked) void ExecPawnTrackActorCatchContext(void);
__declspec(naked) void ExecPawnTrackActorCatchPointer(void);
__declspec(naked) void ExecUpdatePawnTrackActorCatchContext(void);
__declspec(naked) void ExecUpdatePawnTrackActorCatchPointer(void);
__declspec(naked) void FollowHeadCatchContext(void);
__declspec(naked) void FollowHeadCatchPointer(void);
__declspec(naked) void FollowHeadExceptionHandler(void);
__declspec(naked) void FullPeekingCatchContext(void);
__declspec(naked) void FullPeekingCatchPointer(void);
__declspec(naked) void GetViewRotationExceptionHandler(void);
__declspec(naked) void HeartBeatRelevanceCatchContext(void);
__declspec(naked) void HeartBeatRelevanceCatchPointer(void);
__declspec(naked) void HeatRelevanceCatchContext(void);
__declspec(naked) void HeatRelevanceCatchPointer(void);
__declspec(naked) void HitBoneCatchContext(void);
__declspec(naked) void HitBoneCatchPointer(void);
__declspec(naked) void HurtTraceCatchContext(void);
__declspec(naked) void HurtTraceCatchPointer(void);
__declspec(naked) void IsRelevantToPawnHeartBeatExceptionHandler(void);
__declspec(naked) void IsRelevantToPawnHeatVisionExceptionHandler(void);
__declspec(naked) void LedgeCatchContext(void);
__declspec(naked) void LedgeCatchPointer(void);
__declspec(naked) void LineOfSightCatchContext(void);
__declspec(naked) void LineOfSightCatchPointer(void);
__declspec(naked) void LipInitExceptionHandler(void);
__declspec(naked) void LipInitState0Cleanup(void);
__declspec(naked) void MoveToPositionCatchContext(void);
__declspec(naked) void MoveToPositionCatchPointer(void);
__declspec(naked) void MoveTowardCatchContext(void);
__declspec(naked) void MoveTowardCatchPointer(void);
__declspec(naked) void MoveTowardExceptionHandler(void);
__declspec(naked) void MovementDirectionCatchContext(void);
__declspec(naked) void MovementDirectionCatchPointer(void);
__declspec(naked) void OriginReachabilityCatchContext(void);
__declspec(naked) void OriginReachabilityCatchPointer(void);
__declspec(naked) void OriginReachabilityExceptionHandler(void);
__declspec(naked) void PawnCalcVelocityExceptionHandler(void);
__declspec(naked) void PawnDirectionChangedExceptionHandler(void);
__declspec(naked) void PawnDtorExceptionHandler(void);
__declspec(naked) void PawnDtorState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnKillResultCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnKillResultCatchPointer(void);
__declspec(naked) void PawnLedgeExceptionHandler(void);
__declspec(naked) void PawnLookAbsoluteCatchContext(void);
__declspec(naked) void PawnLookAbsoluteCatchPointer(void);
__declspec(naked) void PawnLookAbsoluteExceptionHandler(void);
__declspec(naked) void PawnLookAtCatchContext(void);
__declspec(naked) void PawnLookAtCatchPointer(void);
__declspec(naked) void PawnLookAtExceptionHandler(void);
__declspec(naked) void PawnLookCatchContext(void);
__declspec(naked) void PawnLookCatchPointer(void);
__declspec(naked) void PawnLookExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnMovementCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnMovementCatchPointer(void);
__declspec(naked) void PawnMovementDirectionExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnNightCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnNightCatchPointer(void);
__declspec(naked) void PawnPickActorAdjustCatchContext(void);
__declspec(naked) void PawnPickActorAdjustCatchPointer(void);
__declspec(naked) void PawnPostNetReceiveExceptionHandler(void);
__declspec(naked) void PawnPostReceiveCatchContext(void);
__declspec(naked) void PawnPostReceiveCatchPointer(void);
__declspec(naked) void PawnPreNetReceiveExceptionHandler(void);
__declspec(naked) void PawnPreReceiveCatchContext(void);
__declspec(naked) void PawnPreReceiveCatchPointer(void);
__declspec(naked) void PawnR6SeeExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnScopeCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnScopeCatchPointer(void);
__declspec(naked) void PawnSetBoneRotationExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnStunCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnStunCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnThroughCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PawnThroughCatchPointer(void);
__declspec(naked) void PeekNormCatchContext(void);
__declspec(naked) void PeekNormCatchPointer(void);
__declspec(naked) void PeekNormExceptionHandler(void);
__declspec(naked) void R6LineOfSightToExceptionHandler(void);
__declspec(naked) void R6SeeCatchContext(void);
__declspec(naked) void R6SeeCatchPointer(void);
__declspec(naked) void ResetBoxCatchContext(void);
__declspec(naked) void ResetBoxCatchPointer(void);
__declspec(naked) void ResetColBoxExceptionHandler(void);
__declspec(naked) void RotationOffsetBridgeCatchContext(void);
__declspec(naked) void RotationOffsetBridgeCatchPointer(void);
__declspec(naked) void SensorCatchContext(void);
__declspec(naked) void SensorCatchPointer(void);
__declspec(naked) void SensorExceptionHandler(void);
__declspec(naked) void SetAudioInfoExceptionHandler(void);
__declspec(naked) void SightCallerCatchContext(void);
__declspec(naked) void SightCallerCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ToggleHeatPropertiesCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ToggleHeatPropertiesCatchPointer(void);
__declspec(naked) void UpdateFullPeekingModeExceptionHandler(void);
__declspec(naked) void UpdatePeekingCatchContext(void);
__declspec(naked) void UpdatePeekingCatchPointer(void);
__declspec(naked) void UpdatePeekingExceptionHandler(void);
__declspec(naked) void ViewCacheCatchContext(void);
__declspec(naked) void ViewCacheCatchPointer(void);
__declspec(naked) void ViewCacheState1Cleanup(void);
__declspec(naked) void ViewRotationBridgeCatchContext(void);
__declspec(naked) void ViewRotationBridgeCatchPointer(void);
__declspec(naked) void WeaponFollowCatchContext(void);
__declspec(naked) void WeaponFollowCatchPointer(void);
__declspec(naked) void WeaponFollowExceptionHandler(void);
__declspec(naked) void WeaponLockCatchContext(void);
__declspec(naked) void WeaponLockCatchPointer(void);
__declspec(naked) void WeaponLockExceptionHandler(void);
__declspec(naked) void execGetRotationOffsetExceptionHandler(void);
__declspec(naked) void execMoveHitBoneExceptionHandler(void);
__declspec(naked) void execPawnCanBeHurtFromExceptionHandler(void);
__declspec(naked) void execPawnLookAbsoluteExceptionHandler(void);
__declspec(naked) void execPawnLookAtExceptionHandler(void);
__declspec(naked) void execPawnLookExceptionHandler(void);
__declspec(naked) void execPawnTrackActorExceptionHandler(void);
__declspec(naked) void execR6GetViewRotationExceptionHandler(void);
__declspec(naked) void execUpdatePawnTrackActorExceptionHandler(void);

// R6Engine.dll data @ 1004ee38 : nativeFloat3EPlus01
extern const float nativeFloat3EPlus01;

// R6Engine.dll data @ 1004f7f8 : nativeFloat0Point25
extern const float nativeFloat0Point25;

// R6Engine.dll data @ 1004ff40 : nativeFloat4EPlus01
extern const float nativeFloat4EPlus01;

// R6Engine.dll data @ 10050e28 : nativeFloat1Point5EPlus03
extern const float nativeFloat1Point5EPlus03;

// R6Engine.dll data @ 10050ea0 : nativeFloat8EPlus01
extern const float nativeFloat8EPlus01;

// R6Engine.dll data @ 10050ec0 : nativeFloatMinus8EPlus01
extern const float nativeFloatMinus8EPlus01;

// R6Engine.dll data @ 10050f00 : nativeDoubleMinus0Point75
extern const double nativeDoubleMinus0Point75;

// R6Engine.dll data @ 10050f08 : nativeDoubleMinus0Point25
extern const double nativeDoubleMinus0Point25;

// R6Engine.dll data @ 10050f44 : nativeFloat0Point894427
extern const float nativeFloat0Point894427;

// R6Engine.dll data @ 10050f48 : nativeDouble0
extern const double nativeDouble0;

// R6Engine.dll data @ 10050fe4 : nativeFloat0Point7
extern const float nativeFloat0Point7;

// R6Engine.dll data @ 10050fe8 : nativeFloat0Point3
extern const float nativeFloat0Point3;

// R6Engine.dll data @ 10050fec : nativeFloat0Point0078125
extern const float nativeFloat0Point0078125;

// R6Engine.dll data @ 10050ffc : nativeFloat0Point8
extern const float nativeFloat0Point8;

// R6Engine.dll data @ 10051000 : nativeFloat1Point2544EPlus08
extern const float nativeFloat1Point2544EPlus08;

// R6Engine.dll data @ 10051004 : nativeFloat5Point0176EPlus08
extern const float nativeFloat5Point0176EPlus08;

// R6Engine.dll data @ 10051010 : nativeFloat1Point12896EPlus09
extern const float nativeFloat1Point12896EPlus09;

// R6Engine.dll data @ 10051018 : nativeDouble10
extern const double nativeDouble10;

// R6Engine.dll data @ 1005104c : nativeFloatMinus0Point5
extern const float nativeFloatMinus0Point5;

// R6Engine.dll data @ 100510b0 : nativeDouble5
extern const double nativeDouble5;

// R6Engine.dll data @ 100510b8 : nativeDouble0Point001
extern const double nativeDouble0Point001;

// R6Engine.dll data @ 100510c0 : nativeDouble1000
extern const double nativeDouble1000;

// R6Engine.dll data @ 100511f8 : nativeFloatMinus3Point2EPlus03
extern const float nativeFloatMinus3Point2EPlus03;

// R6Engine.dll data @ 100511fc : nativeFloatMinus5Point5EPlus03
extern const float nativeFloatMinus5Point5EPlus03;

// R6Engine.dll data @ 10051200 : nativeFloat1Point25EPlus03
extern const float nativeFloat1Point25EPlus03;

// R6Engine.dll data @ 10051204 : nativeFloat4Point75EPlus03
extern const float nativeFloat4Point75EPlus03;

// R6Engine.dll data @ 10051208 : nativeFloatMinus2Point55EPlus03
extern const float nativeFloatMinus2Point55EPlus03;

// R6Engine.dll data @ 1005120c : nativeFloat1Point2EPlus03
extern const float nativeFloat1Point2EPlus03;

// R6Engine.dll data @ 10051210 : nativeFloat1Point8EPlus03
extern const float nativeFloat1Point8EPlus03;

// R6Engine.dll data @ 10051214 : nativeFloatMinus5Point75EPlus03
extern const float nativeFloatMinus5Point75EPlus03;

// R6Engine.dll data @ 10051218 : nativeFloatMinus1Point5EPlus03
extern const float nativeFloatMinus1Point5EPlus03;

// R6Engine.dll data @ 1005121c : nativeFloat1EPlus03
extern const float nativeFloat1EPlus03;

// R6Engine.dll data @ 10051220 : nativeFloatMinus3EPlus03
extern const float nativeFloatMinus3EPlus03;

// R6Engine.dll data @ 10051224 : nativeFloatMinus6EPlus03
extern const float nativeFloatMinus6EPlus03;

// R6Engine.dll data @ 10051228 : nativeFloat5EPlus03
extern const float nativeFloat5EPlus03;

// R6Engine.dll data @ 1005122c : nativeFloatMinus5EPlus02
extern const float nativeFloatMinus5EPlus02;

// R6Engine.dll data @ 10051230 : nativeFloatMinus2Point5EPlus03
extern const float nativeFloatMinus2Point5EPlus03;

// R6Engine.dll data @ 10051234 : nativeFloat2EPlus03
extern const float nativeFloat2EPlus03;

// R6Engine.dll data @ 10051238 : nativeFloat8EPlus02
extern const float nativeFloat8EPlus02;

// R6Engine.dll data @ 1005123c : nativeFloat5Point5EPlus03
extern const float nativeFloat5Point5EPlus03;

// R6Engine.dll data @ 10051240 : nativeFloatMinus2EPlus03
extern const float nativeFloatMinus2EPlus03;

// R6Engine.dll data @ 10051244 : nativeFloatMinus1EPlus03
extern const float nativeFloatMinus1EPlus03;

// R6Engine.dll data @ 10051248 : nativeFloat4EPlus03
extern const float nativeFloat4EPlus03;

// R6Engine.dll data @ 1005124c : nativeFloat0Point00024414062
extern const float nativeFloat0Point00024414062;

// R6Engine.dll data @ 10051250 : nativeFloatMinus2Point75EPlus03
extern const float nativeFloatMinus2Point75EPlus03;

// R6Engine.dll data @ 10051254 : nativeFloat3EPlus03
extern const float nativeFloat3EPlus03;

// R6Engine.dll data @ 10051258 : nativeFloatMinus2Point5EPlus02
extern const float nativeFloatMinus2Point5EPlus02;

// R6Engine.dll data @ 1005125c : nativeFloat1Point4EPlus03
extern const float nativeFloat1Point4EPlus03;

// R6Engine.dll data @ 10051260 : nativeFloatMinus2Point25EPlus03
extern const float nativeFloatMinus2Point25EPlus03;

// R6Engine.dll data @ 10051264 : nativeFloat0Point00012207031
extern const float nativeFloat0Point00012207031;

// R6Engine.dll data @ 100512c8 : nativeFloat3Point3EPlus03
extern const float nativeFloat3Point3EPlus03;

// R6Engine.dll data @ 100512cc : nativeFloat3Point5EPlus03
extern const float nativeFloat3Point5EPlus03;

// R6Engine.dll data @ 100512d0 : nativeFloat9Point5EPlus03
extern const float nativeFloat9Point5EPlus03;

// R6Engine.dll data @ 100512d4 : nativeFloatMinus8Point5EPlus03
extern const float nativeFloatMinus8Point5EPlus03;

// R6Engine.dll data @ 100512d8 : nativeFloat2Point55EPlus03
extern const float nativeFloat2Point55EPlus03;

// R6Engine.dll data @ 100512dc : nativeFloat0Point00016276042
extern const float nativeFloat0Point00016276042;

// R6Engine.dll data @ 100512e0 : nativeFloatMinus1Point15EPlus04
extern const float nativeFloatMinus1Point15EPlus04;

// R6Engine.dll data @ 100512e4 : nativeFloat1Point1EPlus04
extern const float nativeFloat1Point1EPlus04;

// R6Engine.dll data @ 100512e8 : nativeFloatMinus1Point2EPlus04
extern const float nativeFloatMinus1Point2EPlus04;

// R6Engine.dll data @ 100512ec : nativeFloatMinus5EPlus03
extern const float nativeFloatMinus5EPlus03;

// R6Engine.dll data @ 100512f0 : nativeFloatMinus1Point8EPlus03
extern const float nativeFloatMinus1Point8EPlus03;

// R6Engine.dll data @ 100512f4 : nativeFloat3Point7EPlus03
extern const float nativeFloat3Point7EPlus03;

// R6Engine.dll data @ 100512f8 : nativeFloatMinus7Point5EPlus03
extern const float nativeFloatMinus7Point5EPlus03;

// R6Engine.dll data @ 100512fc : nativeFloatMinus4EPlus03
extern const float nativeFloatMinus4EPlus03;

// R6Engine.dll data @ 10051300 : nativeFloat8EPlus03
extern const float nativeFloat8EPlus03;

// R6Engine.dll data @ 10051304 : nativeFloatMinus8EPlus03
extern const float nativeFloatMinus8EPlus03;

// R6Engine.dll data @ 10051308 : nativeFloat9EPlus03
extern const float nativeFloat9EPlus03;

// R6Engine.dll data @ 1005130c : nativeFloat6EPlus03
extern const float nativeFloat6EPlus03;

// R6Engine.dll data @ 10051310 : nativeFloat2Point8EPlus03
extern const float nativeFloat2Point8EPlus03;

// R6Engine.dll data @ 10051314 : nativeFloatMinus4Point5EPlus03
extern const float nativeFloatMinus4Point5EPlus03;

// R6Engine.dll data @ 10051318 : nativeFloat6Point5EPlus03
extern const float nativeFloat6Point5EPlus03;

// R6Engine.dll data @ 100514a4 : nativeFloat0Point33
extern const float nativeFloat0Point33;

// R6Engine.dll data @ 1005153c : nativeFloat3Point3500001
extern const float nativeFloat3Point3500001;

// R6Engine.dll data @ 100515c0 : nativeDouble1Point4
extern const double nativeDouble1Point4;

// R6Engine.dll data @ 10051638 : nativeFloatMinus0Point45
extern const float nativeFloatMinus0Point45;

// R6Engine.dll data @ 10051670 : nativeFloat2Point15
extern const float nativeFloat2Point15;

// R6Engine.dll data @ 10051674 : nativeFloat33
extern const float nativeFloat33;

// R6Engine.dll data @ 1005169c : nativeFloat65536
extern const float nativeFloat65536;

// R6Engine.dll data @ 100516a0 : nativeFloat8
extern const float nativeFloat8;

// R6Engine.dll data @ 100516a4 : nativeFloat4EPlus04
extern const float nativeFloat4EPlus04;

// R6Engine.dll data @ 100516d0 : nativeFloatMinus0Point4
extern const float nativeFloatMinus0Point4;

// R6Engine.dll data @ 100516d4 : nativeFloatMinus1Point5
extern const float nativeFloatMinus1Point5;

// R6Engine.dll data @ 100516d8 : nativeFloat1Point1
extern const float nativeFloat1Point1;

// R6Engine.dll data @ 1005170c : nativeFloat39
extern const float nativeFloat39;

// R6Engine.dll data @ 10051710 : nativeFloat6
extern const float nativeFloat6;

// R6Engine.dll data @ 10051714 : nativeFloat37
extern const float nativeFloat37;

// R6Engine.dll data @ 10051718 : nativeDouble37
extern const double nativeDouble37;

// R6Engine.dll data @ 10051720 : nativeDouble0Point7
extern const double nativeDouble0Point7;

// R6Engine.dll data @ 10051760 : nativeFloat7
extern const float nativeFloat7;

// R6Engine.dll data @ 10051780 : nativeFloat0Point33333334
extern const float nativeFloat0Point33333334;

// R6Engine.dll data @ 100518b8 : nativeFloat0Point017857144
extern const float nativeFloat0Point017857144;

// R6Engine.dll data @ 100518bc : nativeFloat28
extern const float nativeFloat28;

// R6Engine.dll data @ 10051960 : nativeFloat26
extern const float nativeFloat26;

// R6Engine.dll data @ 10051964 : nativeFloat56
extern const float nativeFloat56;

// R6Engine.dll data @ 100519d8 : nativeFloat6Point1035156EMinus05
extern const float nativeFloat6Point1035156EMinus05;

// R6Engine.dll data @ 100519dc : nativeFloat8Point138021EMinus05
extern const float nativeFloat8Point138021EMinus05;

// R6Engine.dll data @ 10051afc : nativeFloat6Point4EPlus07
extern const float nativeFloat6Point4EPlus07;

// R6Engine.dll data @ 10051b00 : nativeDouble0Point017453292519943295
extern const double nativeDouble0Point017453292519943295;

// R6Engine.dll data @ 10051b50 : nativeFloat1Point5
extern const float nativeFloat1Point5;

// R6Engine.dll data @ 10051b58 : nativeFloat48
extern const float nativeFloat48;

// R6Engine.dll data @ 10051bb4 : nativeFloat0Point45
extern const float nativeFloat0Point45;

// R6Engine.dll data @ 10051c20 : nativeDouble3000
extern const double nativeDouble3000;

// R6Engine.dll data @ 10051c28 : nativeDouble1600
extern const double nativeDouble1600;

// R6Engine.dll data @ 10051c30 : nativeDouble400
extern const double nativeDouble400;

// R6Engine.dll data @ 10051f60 : nativeDouble0Point6
extern const double nativeDouble0Point6;

// R6Engine.dll data @ 10051f68 : nativeDouble0Point8
extern const double nativeDouble0Point8;

// R6Engine.dll data @ 10055508 : nativeDouble0Point1
extern const double nativeDouble0Point1;

// R6Engine.dll data @ 10055550 : nativeDouble0Point7071
extern const double nativeDouble0Point7071;

// R6Engine.dll data @ 1007433c : nativeFloatMinus4EPlus01
extern float nativeFloatMinus4EPlus01;

// R6Engine.dll data @ 1005b22c : PawnPickActorAdjustUnwindMap
// Both adjustment states have no owned local cleanup.
const NativeUnwindEntry PawnPickActorAdjustUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b23c : PawnPickActorAdjustCatchMap
// Typed pointer catch uses EBP-0xec, followed by the native PickWallAdjust context catch.
const NativeCatchEntry PawnPickActorAdjustCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -236, ((uint)&PawnPickActorAdjustCatchPointer) },
    { 0, 0, 0, ((uint)&PawnPickActorAdjustCatchContext) }
};

// R6Engine.dll data @ 1005b25c : PawnPickActorAdjustTryMap
// Only actor-adjustment state zero is protected by the catches.
const NativeTryBlock PawnPickActorAdjustTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&PawnPickActorAdjustCatchMap) }
};

// R6Engine.dll data @ 1005b270 : PawnPickActorAdjustFuncInfo
// Connects the actor-adjustment frame to cleanup-free states and catches.
const NativeFunctionInfoPrefix PawnPickActorAdjustFuncInfo = { 0x19930520, 0x2, ((uint)&PawnPickActorAdjustUnwindMap),
    0x1, ((uint)&PawnPickActorAdjustTryMap), 0 };

// R6Engine.dll data @ 1005b1cc : MoveToPositionUnwindMap
// Both movement states have no owned local cleanup.
const NativeUnwindEntry MoveToPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b1dc : MoveToPositionCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry MoveToPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&MoveToPositionCatchPointer) },
    { 0, 0, 0, ((uint)&MoveToPositionCatchContext) }
};

// R6Engine.dll data @ 1005b1fc : MoveToPositionTryMap
// Only movement state zero is protected by the catches.
const NativeTryBlock MoveToPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&MoveToPositionCatchMap) }
};

// R6Engine.dll data @ 1005b210 : MoveToPositionFuncInfo
// Connects movement cleanup-free states and catch tables.
const NativeFunctionInfoPrefix MoveToPositionFuncInfo = { 0x19930520, 0x2, ((uint)&MoveToPositionUnwindMap), 0x1,
    ((uint)&MoveToPositionTryMap), 0 };

// R6Engine.dll data @ 1005b16c : AdjustCylinderUnwindMap
// Both adjustment states have no owned local cleanup.
const NativeUnwindEntry AdjustCylinderUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b17c : AdjustCylinderCatchMap
// Typed pointer catch uses EBP-0x30, followed by the context catch.
const NativeCatchEntry AdjustCylinderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -48, ((uint)&AdjustCylinderCatchPointer) },
    { 0, 0, 0, ((uint)&AdjustCylinderCatchContext) }
};

// R6Engine.dll data @ 1005b19c : AdjustCylinderTryMap
// Only state zero is protected by the adjustment catches.
const NativeTryBlock AdjustCylinderTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&AdjustCylinderCatchMap) }
};

// R6Engine.dll data @ 1005b1b0 : AdjustCylinderFuncInfo
// Binds cylinder-adjustment cleanup-free states and catches.
const NativeFunctionInfoPrefix AdjustCylinderFuncInfo = { 0x19930520, 0x2, ((uint)&AdjustCylinderUnwindMap), 0x1,
    ((uint)&AdjustCylinderTryMap), 0 };

// R6Engine.dll data @ 1005bdd4 : execUpdatePawnTrackActorUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry execUpdatePawnTrackActorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bde4 : execUpdatePawnTrackActorCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry execUpdatePawnTrackActorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ExecUpdatePawnTrackActorCatchPointer) },
    { 0, 0, 0, ((uint)&ExecUpdatePawnTrackActorCatchContext) }
};

// R6Engine.dll data @ 1005be04 : execUpdatePawnTrackActorTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock execUpdatePawnTrackActorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execUpdatePawnTrackActorCatchMap) }
};

// R6Engine.dll data @ 1005be18 : execUpdatePawnTrackActorFuncInfo
// Connects the tracking bridge to its cleanup-free catch tables.
const NativeFunctionInfoPrefix execUpdatePawnTrackActorFuncInfo = { 0x19930520, 0x2,
    ((uint)&execUpdatePawnTrackActorUnwindMap), 0x1, ((uint)&execUpdatePawnTrackActorTryMap), 0 };

// R6Engine.dll data @ 1005be94 : execPawnTrackActorUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry execPawnTrackActorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bea4 : execPawnTrackActorCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry execPawnTrackActorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ExecPawnTrackActorCatchPointer) },
    { 0, 0, 0, ((uint)&ExecPawnTrackActorCatchContext) }
};

// R6Engine.dll data @ 1005bec4 : execPawnTrackActorTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock execPawnTrackActorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execPawnTrackActorCatchMap) }
};

// R6Engine.dll data @ 1005bed8 : execPawnTrackActorFuncInfo
// Connects the tracking bridge to its cleanup-free catch tables.
const NativeFunctionInfoPrefix execPawnTrackActorFuncInfo = { 0x19930520, 0x2, ((uint)&execPawnTrackActorUnwindMap),
    0x1, ((uint)&execPawnTrackActorTryMap), 0 };

// R6Engine.dll data @ 1005bcb4 : execPawnLookUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry execPawnLookUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bcc4 : execPawnLookCatchMap
// Typed pointer catch precedes the context catch.
const NativeCatchEntry execPawnLookCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ExecPawnLookCatchPointer) },
    { 0, 0, 0, ((uint)&ExecPawnLookCatchContext) }
};

// R6Engine.dll data @ 1005bce4 : execPawnLookTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock execPawnLookTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execPawnLookCatchMap) }
};

// R6Engine.dll data @ 1005bcf8 : execPawnLookFuncInfo
// Connects the parent frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix execPawnLookFuncInfo = { 0x19930520, 0x2, ((uint)&execPawnLookUnwindMap), 0x1,
    ((uint)&execPawnLookTryMap), 0 };

// R6Engine.dll data @ 1005bd14 : execPawnLookAbsoluteUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry execPawnLookAbsoluteUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bd24 : execPawnLookAbsoluteCatchMap
// Typed pointer catch precedes the context catch.
const NativeCatchEntry execPawnLookAbsoluteCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ExecPawnLookAbsoluteCatchPointer) },
    { 0, 0, 0, ((uint)&ExecPawnLookAbsoluteCatchContext) }
};

// R6Engine.dll data @ 1005bd44 : execPawnLookAbsoluteTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock execPawnLookAbsoluteTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execPawnLookAbsoluteCatchMap) }
};

// R6Engine.dll data @ 1005bd58 : execPawnLookAbsoluteFuncInfo
// Connects the parent frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix execPawnLookAbsoluteFuncInfo = { 0x19930520, 0x2, ((uint)&execPawnLookAbsoluteUnwindMap),
    0x1, ((uint)&execPawnLookAbsoluteTryMap), 0 };

// R6Engine.dll data @ 1005bd74 : execPawnLookAtUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry execPawnLookAtUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bd84 : execPawnLookAtCatchMap
// Typed pointer catch precedes the context catch.
const NativeCatchEntry execPawnLookAtCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&ExecPawnLookAtCatchPointer) },
    { 0, 0, 0, ((uint)&ExecPawnLookAtCatchContext) }
};

// R6Engine.dll data @ 1005bda4 : execPawnLookAtTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock execPawnLookAtTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&execPawnLookAtCatchMap) }
};

// R6Engine.dll data @ 1005bdb8 : execPawnLookAtFuncInfo
// Connects the parent frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix execPawnLookAtFuncInfo = { 0x19930520, 0x2, ((uint)&execPawnLookAtUnwindMap), 0x1,
    ((uint)&execPawnLookAtTryMap), 0 };

// R6Engine.dll data @ 1005bbf4 : updatePeekingUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry updatePeekingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bc04 : updatePeekingCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry updatePeekingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&UpdatePeekingCatchPointer) },
    { 0, 0, 0, ((uint)&UpdatePeekingCatchContext) }
};

// R6Engine.dll data @ 1005bc24 : updatePeekingTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock updatePeekingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&updatePeekingCatchMap) }
};

// R6Engine.dll data @ 1005bc38 : updatePeekingFuncInfo
// Connects the peeking-update frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix updatePeekingFuncInfo = { 0x19930520, 0x2, ((uint)&updatePeekingUnwindMap), 0x1,
    ((uint)&updatePeekingTryMap), 0 };

// R6Engine.dll data @ 1005bb94 : sightCallerUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry sightCallerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bba4 : sightCallerCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry sightCallerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SightCallerCatchPointer) },
    { 0, 0, 0, ((uint)&SightCallerCatchContext) }
};

// R6Engine.dll data @ 1005bbc4 : sightCallerTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock sightCallerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&sightCallerCatchMap) }
};

// R6Engine.dll data @ 1005bbd8 : sightCallerFuncInfo
// Connects the sight-caller frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix sightCallerFuncInfo = { 0x19930520, 0x2, ((uint)&sightCallerUnwindMap), 0x1,
    ((uint)&sightCallerTryMap), 0 };

// R6Engine.dll data @ 1005bb34 : lineOfSightUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry lineOfSightUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bb44 : lineOfSightCatchMap
// Typed pointer catch uses EBP-0x1c, followed by the context catch.
const NativeCatchEntry lineOfSightCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&LineOfSightCatchPointer) },
    { 0, 0, 0, ((uint)&LineOfSightCatchContext) }
};

// R6Engine.dll data @ 1005bb64 : lineOfSightTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock lineOfSightTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&lineOfSightCatchMap) }
};

// R6Engine.dll data @ 1005bb78 : lineOfSightFuncInfo
// Connects the sight-trace frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix lineOfSightFuncInfo = { 0x19930520, 0x2, ((uint)&lineOfSightUnwindMap), 0x1,
    ((uint)&lineOfSightTryMap), 0 };

// R6Engine.dll data @ 1005bad4 : audioInfoUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry audioInfoUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bae4 : audioInfoCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry audioInfoCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AudioInfoCatchPointer) },
    { 0, 0, 0, ((uint)&AudioInfoCatchContext) }
};

// R6Engine.dll data @ 1005bb04 : audioInfoTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock audioInfoTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&audioInfoCatchMap) }
};

// R6Engine.dll data @ 1005bb18 : audioInfoFuncInfo
// Connects the audio-update frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix audioInfoFuncInfo = { 0x19930520, 0x2, ((uint)&audioInfoUnwindMap), 0x1,
    ((uint)&audioInfoTryMap), 0 };

// R6Engine.dll data @ 1005ba74 : heartBeatRelevanceUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry heartBeatRelevanceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ba84 : heartBeatRelevanceCatchMap
// Typed pointer catch uses EBP-0x28, followed by the context catch.
const NativeCatchEntry heartBeatRelevanceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -40, ((uint)&HeartBeatRelevanceCatchPointer) },
    { 0, 0, 0, ((uint)&HeartBeatRelevanceCatchContext) }
};

// R6Engine.dll data @ 1005baa4 : heartBeatRelevanceTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock heartBeatRelevanceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&heartBeatRelevanceCatchMap) }
};

// R6Engine.dll data @ 1005bab8 : heartBeatRelevanceFuncInfo
// Connects the sensor-relevance frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix heartBeatRelevanceFuncInfo = { 0x19930520, 0x2, ((uint)&heartBeatRelevanceUnwindMap),
    0x1, ((uint)&heartBeatRelevanceTryMap), 0 };

// R6Engine.dll data @ 1005b9b4 : pawnLookAbsoluteUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry pawnLookAbsoluteUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b9c4 : pawnLookAbsoluteCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry pawnLookAbsoluteCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PawnLookAbsoluteCatchPointer) },
    { 0, 0, 0, ((uint)&PawnLookAbsoluteCatchContext) }
};

// R6Engine.dll data @ 1005b9e4 : pawnLookAbsoluteTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock pawnLookAbsoluteTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnLookAbsoluteCatchMap) }
};

// R6Engine.dll data @ 1005b9f8 : pawnLookAbsoluteFuncInfo
// Connects the selector frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix pawnLookAbsoluteFuncInfo = { 0x19930520, 0x2, ((uint)&pawnLookAbsoluteUnwindMap), 0x1,
    ((uint)&pawnLookAbsoluteTryMap), 0 };

// R6Engine.dll data @ 1005ba14 : pawnLookAtUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry pawnLookAtUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ba24 : pawnLookAtCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry pawnLookAtCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PawnLookAtCatchPointer) },
    { 0, 0, 0, ((uint)&PawnLookAtCatchContext) }
};

// R6Engine.dll data @ 1005ba44 : pawnLookAtTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock pawnLookAtTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnLookAtCatchMap) }
};

// R6Engine.dll data @ 1005ba58 : pawnLookAtFuncInfo
// Connects the selector frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix pawnLookAtFuncInfo = { 0x19930520, 0x2, ((uint)&pawnLookAtUnwindMap), 0x1,
    ((uint)&pawnLookAtTryMap), 0 };

// R6Engine.dll data @ 1005b954 : pawnLookUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry pawnLookUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b964 : pawnLookCatchMap
// Typed pointer catch uses EBP-0x18, followed by the context catch.
const NativeCatchEntry pawnLookCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PawnLookCatchPointer) },
    { 0, 0, 0, ((uint)&PawnLookCatchContext) }
};

// R6Engine.dll data @ 1005b984 : pawnLookTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock pawnLookTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnLookCatchMap) }
};

// R6Engine.dll data @ 1005b998 : pawnLookFuncInfo
// Connects the look-selector frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix pawnLookFuncInfo = { 0x19930520, 0x2, ((uint)&pawnLookUnwindMap), 0x1,
    ((uint)&pawnLookTryMap), 0 };

// R6Engine.dll data @ 1005b8f4 : hitBoneUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry hitBoneUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b904 : hitBoneCatchMap
// Typed pointer catch uses EBP-0x2c, followed by the context catch.
const NativeCatchEntry hitBoneCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -44, ((uint)&HitBoneCatchPointer) },
    { 0, 0, 0, ((uint)&HitBoneCatchContext) }
};

// R6Engine.dll data @ 1005b924 : hitBoneTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock hitBoneTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&hitBoneCatchMap) }
};

// R6Engine.dll data @ 1005b938 : hitBoneFuncInfo
// Connects the hit-bone frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix hitBoneFuncInfo = { 0x19930520, 0x2, ((uint)&hitBoneUnwindMap), 0x1,
    ((uint)&hitBoneTryMap), 0 };

// R6Engine.dll data @ 1005b894 : fullPeekingUnwindMap
// Retains two cleanup-free states; intermediate peeking writes are not rolled back.
const NativeUnwindEntry fullPeekingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b8a4 : fullPeekingCatchMap
// Binds caught EBP-0x20 and both inherited-frame full-peeking handlers.
const NativeCatchEntry fullPeekingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&FullPeekingCatchPointer) },
    { 0, 0, 0, ((uint)&FullPeekingCatchContext) }
};

// R6Engine.dll data @ 1005b8c4 : fullPeekingTryMap
// State zero selects the typed/context handlers without local destruction.
const NativeTryBlock fullPeekingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&fullPeekingCatchMap) }
};

// R6Engine.dll data @ 1005b8d8 : fullPeekingFuncInfo
// Binds the full-peeking parent and its existing exception adapter.
const NativeFunctionInfoPrefix fullPeekingFuncInfo = { 0x19930520, 0x2, ((uint)&fullPeekingUnwindMap), 0x1,
    ((uint)&fullPeekingTryMap), 0 };

// R6Engine.dll data @ 1005b834 : moveTowardUnwindMap
// Retains two cleanup-free states for pawn movement.
const NativeUnwindEntry moveTowardUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b844 : moveTowardCatchMap
// Binds caught EBP-0x18 and both inherited-frame movement handlers.
const NativeCatchEntry moveTowardCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&MoveTowardCatchPointer) },
    { 0, 0, 0, ((uint)&MoveTowardCatchContext) }
};

// R6Engine.dll data @ 1005b864 : moveTowardTryMap
// State zero selects the typed/context handlers without local destruction.
const NativeTryBlock moveTowardTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&moveTowardCatchMap) }
};

// R6Engine.dll data @ 1005b878 : moveTowardFuncInfo
// Binds pawn movement and its omitted compiler exception adapter.
const NativeFunctionInfoPrefix moveTowardFuncInfo = { 0x19930520, 0x2, ((uint)&moveTowardUnwindMap), 0x1,
    ((uint)&moveTowardTryMap), 0 };

// R6Engine.dll data @ 1005b7d4 : cylinderBridgeUnwindMap
// Retains two cleanup-free states for the cylinder VM bridge.
const NativeUnwindEntry cylinderBridgeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b7e4 : cylinderBridgeCatchMap
// Binds caught EBP-0x1c and both inherited-frame cylinder handlers.
const NativeCatchEntry cylinderBridgeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&CylinderBridgeCatchPointer) },
    { 0, 0, 0, ((uint)&CylinderBridgeCatchContext) }
};

// R6Engine.dll data @ 1005b804 : cylinderBridgeTryMap
// State zero selects the typed/context handlers without local destruction.
const NativeTryBlock cylinderBridgeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&cylinderBridgeCatchMap) }
};

// R6Engine.dll data @ 1005b818 : cylinderBridgeFuncInfo
// Binds the cylinder VM bridge and its omitted compiler exception adapter.
const NativeFunctionInfoPrefix cylinderBridgeFuncInfo = { 0x19930520, 0x2, ((uint)&cylinderBridgeUnwindMap), 0x1,
    ((uint)&cylinderBridgeTryMap), 0 };

// R6Engine.dll data @ 1005b774 : originReachabilityUnwindMap
// Retains two cleanup-free states; no position-restoration unwind action is registered.
const NativeUnwindEntry originReachabilityUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b784 : originReachabilityCatchMap
// Binds caught EBP-0x1c and both inherited-frame origin-reachability handlers.
const NativeCatchEntry originReachabilityCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&OriginReachabilityCatchPointer) },
    { 0, 0, 0, ((uint)&OriginReachabilityCatchContext) }
};

// R6Engine.dll data @ 1005b7a4 : originReachabilityTryMap
// State zero selects both handlers without local destruction.
const NativeTryBlock originReachabilityTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&originReachabilityCatchMap) }
};

// R6Engine.dll data @ 1005b7b8 : originReachabilityFuncInfo
// Binds the origin-reachability parent and its omitted compiler exception adapter.
const NativeFunctionInfoPrefix originReachabilityFuncInfo = { 0x19930520, 0x2, ((uint)&originReachabilityUnwindMap),
    0x1, ((uint)&originReachabilityTryMap), 0 };

// R6Engine.dll data @ 1005b714 : heatRelevanceUnwindMap
// Retains two cleanup-free states for the heat-vision query.
const NativeUnwindEntry heatRelevanceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b724 : heatRelevanceCatchMap
// Binds caught EBP-0x24 and the typed/context heat-vision handlers.
const NativeCatchEntry heatRelevanceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&HeatRelevanceCatchPointer) },
    { 0, 0, 0, ((uint)&HeatRelevanceCatchContext) }
};

// R6Engine.dll data @ 1005b744 : heatRelevanceTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock heatRelevanceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&heatRelevanceCatchMap) }
};

// R6Engine.dll data @ 1005b758 : heatRelevanceFuncInfo
// Binds the heat-vision query and its existing exception adapter.
const NativeFunctionInfoPrefix heatRelevanceFuncInfo = { 0x19930520, 0x2, ((uint)&heatRelevanceUnwindMap), 0x1,
    ((uint)&heatRelevanceTryMap), 0 };

// R6Engine.dll data @ 1005b6b4 : hurtTraceUnwindMap
// Retains two cleanup-free states for the hurt-trace VM bridge.
const NativeUnwindEntry hurtTraceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b6c4 : hurtTraceCatchMap
// Binds caught EBP-0x18 and both inherited-frame hurt-trace handlers.
const NativeCatchEntry hurtTraceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&HurtTraceCatchPointer) },
    { 0, 0, 0, ((uint)&HurtTraceCatchContext) }
};

// R6Engine.dll data @ 1005b6e4 : hurtTraceTryMap
// State zero selects the typed/context handlers without local destruction.
const NativeTryBlock hurtTraceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&hurtTraceCatchMap) }
};

// R6Engine.dll data @ 1005b6f8 : hurtTraceFuncInfo
// Binds the hurt-trace parent and its existing exception adapter.
const NativeFunctionInfoPrefix hurtTraceFuncInfo = { 0x19930520, 0x2, ((uint)&hurtTraceUnwindMap), 0x1,
    ((uint)&hurtTraceTryMap), 0 };

// R6Engine.dll data @ 1005b64c : viewCacheUnwindMap
// State one clears the constructor guard bit; the other states own no local cleanup.
const NativeUnwindEntry viewCacheUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&ViewCacheState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b664 : viewCacheCatchMap
// Binds caught EBP-0x18 and both inherited-frame view-cache handlers.
const NativeCatchEntry viewCacheCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ViewCacheCatchPointer) },
    { 0, 0, 0, ((uint)&ViewCacheCatchContext) }
};

// R6Engine.dll data @ 1005b684 : viewCacheTryMap
// States zero and one select the typed/context handlers in catch state two.
const NativeTryBlock viewCacheTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&viewCacheCatchMap) }
};

// R6Engine.dll data @ 1005b698 : viewCacheFuncInfo
// Binds the view-cache guard, constructor cleanup and existing exception adapter.
const NativeFunctionInfoPrefix viewCacheFuncInfo = { 0x19930520, 0x3, ((uint)&viewCacheUnwindMap), 0x1,
    ((uint)&viewCacheTryMap), 0 };

// R6Engine.dll data @ 1005ae6c : rotationOffsetBridgeUnwindMap
// Retains two cleanup-free states for the rotation-offset bridge.
const NativeUnwindEntry rotationOffsetBridgeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ae7c : rotationOffsetBridgeCatchMap
// Binds the typed caught word at EBP-0x18 and the catch-all context routine.
const NativeCatchEntry rotationOffsetBridgeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RotationOffsetBridgeCatchPointer) },
    { 0, 0, 0, ((uint)&RotationOffsetBridgeCatchContext) }
};

// R6Engine.dll data @ 1005ae9c : rotationOffsetBridgeTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock rotationOffsetBridgeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&rotationOffsetBridgeCatchMap) }
};

// R6Engine.dll data @ 1005aeb0 : rotationOffsetBridgeFuncInfo
// Binds the rotation-offset bridge and its existing exception adapter.
const NativeFunctionInfoPrefix rotationOffsetBridgeFuncInfo = { 0x19930520, 0x2, ((uint)&rotationOffsetBridgeUnwindMap),
    0x1, ((uint)&rotationOffsetBridgeTryMap), 0 };

// R6Engine.dll data @ 1005ae0c : viewRotationBridgeUnwindMap
// Retains two cleanup-free states for the view-rotation bridge.
const NativeUnwindEntry viewRotationBridgeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ae1c : viewRotationBridgeCatchMap
// Binds the typed caught word at EBP-0x18 and the catch-all context routine.
const NativeCatchEntry viewRotationBridgeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ViewRotationBridgeCatchPointer) },
    { 0, 0, 0, ((uint)&ViewRotationBridgeCatchContext) }
};

// R6Engine.dll data @ 1005ae3c : viewRotationBridgeTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock viewRotationBridgeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&viewRotationBridgeCatchMap) }
};

// R6Engine.dll data @ 1005ae50 : viewRotationBridgeFuncInfo
// Binds the view-rotation bridge and its existing exception adapter.
const NativeFunctionInfoPrefix viewRotationBridgeFuncInfo = { 0x19930520, 0x2, ((uint)&viewRotationBridgeUnwindMap),
    0x1, ((uint)&viewRotationBridgeTryMap), 0 };

// R6Engine.dll data @ 1005adac : weaponLockUnwindMap
// Retains two cleanup-free states for the inherited weapon-lock catches.
const NativeUnwindEntry weaponLockUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005adbc : weaponLockCatchMap
// Typed caught/rethrow words occupy parent EBP-0x94/-0x18.
const NativeCatchEntry weaponLockCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -148, ((uint)&WeaponLockCatchPointer) },
    { 0, 0, 0, ((uint)&WeaponLockCatchContext) }
};

// R6Engine.dll data @ 1005addc : weaponLockTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock weaponLockTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&weaponLockCatchMap) }
};

// R6Engine.dll data @ 1005adf0 : weaponLockFuncInfo
// Binds the weapon-lock parent and its existing exception adapter.
const NativeFunctionInfoPrefix weaponLockFuncInfo = { 0x19930520, 0x2, ((uint)&weaponLockUnwindMap), 0x1,
    ((uint)&weaponLockTryMap), 0 };

// R6Engine.dll data @ 1005ad4c : weaponFollowUnwindMap
// Retains two cleanup-free states for the inherited clavicle-follow catches.
const NativeUnwindEntry weaponFollowUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ad5c : weaponFollowCatchMap
// Typed caught/rethrow words occupy parent EBP-0x64/-0x18.
const NativeCatchEntry weaponFollowCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -100, ((uint)&WeaponFollowCatchPointer) },
    { 0, 0, 0, ((uint)&WeaponFollowCatchContext) }
};

// R6Engine.dll data @ 1005ad7c : weaponFollowTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock weaponFollowTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&weaponFollowCatchMap) }
};

// R6Engine.dll data @ 1005ad90 : weaponFollowFuncInfo
// Binds the clavicle-follow parent and its existing exception adapter.
const NativeFunctionInfoPrefix weaponFollowFuncInfo = { 0x19930520, 0x2, ((uint)&weaponFollowUnwindMap), 0x1,
    ((uint)&weaponFollowTryMap), 0 };

// R6Engine.dll data @ 1005acec : boneRotationUnwindMap
// Retains two cleanup-free states for the inherited bone-rotation catches.
const NativeUnwindEntry boneRotationUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005acfc : boneRotationCatchMap
// Typed caught/rethrow words occupy parent EBP-0x18/-0x14.
const NativeCatchEntry boneRotationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&BoneRotationCatchPointer) },
    { 0, 0, 0, ((uint)&BoneRotationCatchContext) }
};

// R6Engine.dll data @ 1005ad1c : boneRotationTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock boneRotationTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&boneRotationCatchMap) }
};

// R6Engine.dll data @ 1005ad30 : boneRotationFuncInfo
// Binds the bone-rotation parent and its existing exception adapter.
const NativeFunctionInfoPrefix boneRotationFuncInfo = { 0x19930520, 0x2, ((uint)&boneRotationUnwindMap), 0x1,
    ((uint)&boneRotationTryMap), 0 };

// R6Engine.dll data @ 1005ac8c : followHeadUnwindMap
// Retains two cleanup-free states for the inherited weapon-follow catches.
const NativeUnwindEntry followHeadUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ac9c : followHeadCatchMap
// Typed caught/rethrow words occupy parent EBP-0x18/-0x14.
const NativeCatchEntry followHeadCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&FollowHeadCatchPointer) },
    { 0, 0, 0, ((uint)&FollowHeadCatchContext) }
};

// R6Engine.dll data @ 1005acbc : followHeadTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock followHeadTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&followHeadCatchMap) }
};

// R6Engine.dll data @ 1005acd0 : followHeadFuncInfo
// Binds the weapon-follow query and its private exception adapter.
const NativeFunctionInfoPrefix followHeadFuncInfo = { 0x19930520, 0x2, ((uint)&followHeadUnwindMap), 0x1,
    ((uint)&followHeadTryMap), 0 };

// R6Engine.dll data @ 1005ac2c : sensorUnwindMap
// Retains two cleanup-free states for the inherited sensor-query catches.
const NativeUnwindEntry sensorUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ac3c : sensorCatchMap
// Typed caught/rethrow words occupy parent EBP-0x18/-0x14.
const NativeCatchEntry sensorCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&SensorCatchPointer) },
    { 0, 0, 0, ((uint)&SensorCatchContext) }
};

// R6Engine.dll data @ 1005ac5c : sensorTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock sensorTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&sensorCatchMap) }
};

// R6Engine.dll data @ 1005ac70 : sensorFuncInfo
// Binds the sensor query and its private exception adapter.
const NativeFunctionInfoPrefix sensorFuncInfo = { 0x19930520, 0x2, ((uint)&sensorUnwindMap), 0x1, ((uint)&sensorTryMap),
    0 };

// R6Engine.dll data @ 1005abcc : peekNormUnwindMap
// Retains two cleanup-free states for the inherited peeking-normalization catches.
const NativeUnwindEntry peekNormUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005abdc : peekNormCatchMap
// Typed caught/rethrow words occupy parent EBP-0x1c/-0x18.
const NativeCatchEntry peekNormCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&PeekNormCatchPointer) },
    { 0, 0, 0, ((uint)&PeekNormCatchContext) }
};

// R6Engine.dll data @ 1005abfc : peekNormTryMap
// State zero selects both handlers without local destruction actions.
const NativeTryBlock peekNormTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&peekNormCatchMap) }
};

// R6Engine.dll data @ 1005ac10 : peekNormFuncInfo
// Binds the peeking VM frame to its inherited typed and context handlers.
const NativeFunctionInfoPrefix peekNormFuncInfo = { 0x19930520, 0x2, ((uint)&peekNormUnwindMap), 0x1,
    ((uint)&peekNormTryMap), 0 };

// R6Engine.dll data @ 1005aba8 : lipInitUnwindMap
// State zero releases the saved raw allocation through the inherited-frame cleanup.
const NativeUnwindEntry lipInitUnwindMap[1] = {
    { -1, ((uint)&LipInitState0Cleanup) }
};

// R6Engine.dll data @ 1005abb0 : lipInitFuncInfo
// Registers one allocation cleanup state and no local catch handlers.
const NativeFunctionInfoPrefix lipInitFuncInfo = { 0x19930520, 0x1, ((uint)&lipInitUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 1005ab48 : resetBoxUnwindMap
// Retains two cleanup-free states for the inherited collision-reset catches.
const NativeUnwindEntry resetBoxUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ab58 : resetBoxCatchMap
// Typed caught/rethrow words occupy parent EBP-0x18/-0x14.
const NativeCatchEntry resetBoxCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ResetBoxCatchPointer) },
    { 0, 0, 0, ((uint)&ResetBoxCatchContext) }
};

// R6Engine.dll data @ 1005ab78 : resetBoxTryMap
// State zero selects both inherited-frame handlers without local destruction.
const NativeTryBlock resetBoxTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&resetBoxCatchMap) }
};

// R6Engine.dll data @ 1005ab8c : resetBoxFuncInfo
// Binds the collision-reset parent and its private exception adapter.
const NativeFunctionInfoPrefix resetBoxFuncInfo = { 0x19930520, 0x2, ((uint)&resetBoxUnwindMap), 0x1,
    ((uint)&resetBoxTryMap), 0 };

// R6Engine.dll data @ 1005aae8 : ledgeUnwindMap
// Retains two cleanup-free states for the inherited ledge-probe catches.
const NativeUnwindEntry ledgeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005aaf8 : ledgeCatchMap
// Typed caught/rethrow words occupy parent EBP-0x24/-0x20.
const NativeCatchEntry ledgeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&LedgeCatchPointer) },
    { 0, 0, 0, ((uint)&LedgeCatchContext) }
};

// R6Engine.dll data @ 1005ab18 : ledgeTryMap
// State zero selects the typed and context handlers without local destruction.
const NativeTryBlock ledgeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ledgeCatchMap) }
};

// R6Engine.dll data @ 1005ab2c : ledgeFuncInfo
// Binds the complete ledge-probe frame to its inherited handlers.
const NativeFunctionInfoPrefix ledgeFuncInfo = { 0x19930520, 0x2, ((uint)&ledgeUnwindMap), 0x1, ((uint)&ledgeTryMap),
    0 };

// R6Engine.dll data @ 1005aa88 : r6SeeUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry r6SeeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005aa98 : r6SeeCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry r6SeeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&R6SeeCatchPointer) },
    { 0, 0, 0, ((uint)&R6SeeCatchContext) }
};

// R6Engine.dll data @ 1005aab8 : r6SeeTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock r6SeeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&r6SeeCatchMap) }
};

// R6Engine.dll data @ 1005aacc : r6SeeFuncInfo
// Binds the complete sight-query exception frame.
const NativeFunctionInfoPrefix r6SeeFuncInfo = { 0x19930520, 0x2, ((uint)&r6SeeUnwindMap), 0x1, ((uint)&r6SeeTryMap),
    0 };

// R6Engine.dll data @ 100754f4 : PreNetSoundRepInfo
// Loader-zeroed module snapshot shared by pawn receive hooks; identifier is descriptive.
AR6SoundReplicationInfo* PreNetSoundRepInfo = nullptr;

// R6Engine.dll data @ 100754f8 : PreNetCurrentActionIndex
// Loader-zeroed module action snapshot; native writes one byte, independently of neighboring storage.
byte PreNetCurrentActionIndex = 0;

// R6Engine.dll data @ 1005a9c8 : pawnPreReceiveUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry pawnPreReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a9d8 : pawnPreReceiveCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry pawnPreReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PawnPreReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&PawnPreReceiveCatchContext) }
};

// R6Engine.dll data @ 1005a9f8 : pawnPreReceiveTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock pawnPreReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnPreReceiveCatchMap) }
};

// R6Engine.dll data @ 1005aa0c : pawnPreReceiveFuncInfo
// Binds the complete pawn PreNetReceive exception frame.
const NativeFunctionInfoPrefix pawnPreReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&pawnPreReceiveUnwindMap), 0x1,
    ((uint)&pawnPreReceiveTryMap), 0 };

// R6Engine.dll data @ 1005aa28 : pawnPostReceiveUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry pawnPostReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005aa38 : pawnPostReceiveCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry pawnPostReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PawnPostReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&PawnPostReceiveCatchContext) }
};

// R6Engine.dll data @ 1005aa58 : pawnPostReceiveTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock pawnPostReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnPostReceiveCatchMap) }
};

// R6Engine.dll data @ 1005aa6c : pawnPostReceiveFuncInfo
// Binds the complete pawn PostNetReceive exception frame.
const NativeFunctionInfoPrefix pawnPostReceiveFuncInfo = { 0x19930520, 0x2, ((uint)&pawnPostReceiveUnwindMap), 0x1,
    ((uint)&pawnPostReceiveTryMap), 0 };

// R6Engine.dll data @ 1005a968 : directionChangedUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry directionChangedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a978 : directionChangedCatchMap
// The typed catch reads parent EBP-0x18; separate rethrow storage is at EBP-0x14.
const NativeCatchEntry directionChangedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&DirectionChangedCatchPointer) },
    { 0, 0, 0, ((uint)&DirectionChangedCatchContext) }
};

// R6Engine.dll data @ 1005a998 : directionChangedTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock directionChangedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&directionChangedCatchMap) }
};

// R6Engine.dll data @ 1005a9ac : directionChangedFuncInfo
// Binds the complete strafe-direction exception frame.
const NativeFunctionInfoPrefix directionChangedFuncInfo = { 0x19930520, 0x2, ((uint)&directionChangedUnwindMap), 0x1,
    ((uint)&directionChangedTryMap), 0 };

// R6Engine.dll data @ 1005a908 : calcVelocityUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry calcVelocityUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a918 : calcVelocityCatchMap
// The typed catch reads parent EBP-0x1c; separate rethrow storage is at EBP-0x18.
const NativeCatchEntry calcVelocityCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&CalcVelocityCatchPointer) },
    { 0, 0, 0, ((uint)&CalcVelocityCatchContext) }
};

// R6Engine.dll data @ 1005a938 : calcVelocityTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock calcVelocityTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&calcVelocityCatchMap) }
};

// R6Engine.dll data @ 1005a94c : calcVelocityFuncInfo
// Binds the complete velocity-calculation exception frame.
const NativeFunctionInfoPrefix calcVelocityFuncInfo = { 0x19930520, 0x2, ((uint)&calcVelocityUnwindMap), 0x1,
    ((uint)&calcVelocityTryMap), 0 };

// R6Engine.dll data @ 1005a8a8 : movementDirectionUnwindMap
// Retains two cleanup-free states for the inherited typed and context catches.
const NativeUnwindEntry movementDirectionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a8b8 : movementDirectionCatchMap
// The typed catch reads parent EBP-0x1c; separate rethrow storage is at EBP-0x18.
const NativeCatchEntry movementDirectionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&MovementDirectionCatchPointer) },
    { 0, 0, 0, ((uint)&MovementDirectionCatchContext) }
};

// R6Engine.dll data @ 1005a8d8 : movementDirectionTryMap
// State zero selects both inherited-frame handlers without local destruction actions.
const NativeTryBlock movementDirectionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&movementDirectionCatchMap) }
};

// R6Engine.dll data @ 1005a8ec : movementDirectionFuncInfo
// Binds the complete movement-direction exception frame.
const NativeFunctionInfoPrefix movementDirectionFuncInfo = { 0x19930520, 0x2, ((uint)&movementDirectionUnwindMap), 0x1,
    ((uint)&movementDirectionTryMap), 0 };

// R6Engine.dll data @ 10074548 : heatRestoreRenderMap
// Descriptive name for the raw render mode remembered on every successful heat-vision enable.
uint heatRestoreRenderMap = 5;

// R6Engine.dll data @ 1005e654 : pawnStunUnwind
// Body and catch states have no owned local cleanup.
const NativeUnwindEntry pawnStunUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e664 : pawnStunCatch
// Catches a text pointer at parent EBP-30, then reports other exceptions.
const NativeCatchEntry pawnStunCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -48, ((uint)&PawnStunCatchPointer) },
    { 0, 0, 0, ((uint)&PawnStunCatchContext) }
};

// R6Engine.dll data @ 1005e684 : pawnStunTry
// State zero guards the query; state one belongs to its catches.
const NativeTryBlock pawnStunTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnStunCatch) }
};

// R6Engine.dll data @ 1005e698 : pawnStunInfo
// Binds the stun query to its exact inherited-frame exception records.
const NativeFunctionInfoPrefix pawnStunInfo = { 0x19930520, 0x2, ((uint)&pawnStunUnwind), 0x1, ((uint)&pawnStunTry),
    0 };

// Selects the stun-query metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl StunResultExceptionHandler(void);

// R6Engine.dll data @ 1005e5f4 : pawnThroughUnwind
// Neither body nor catch state owns local cleanup.
const NativeUnwindEntry pawnThroughUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e604 : pawnThroughCatch
// Binds the caught text pointer at parent EBP-1c to the two inherited catch routines.
const NativeCatchEntry pawnThroughCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&PawnThroughCatchPointer) },
    { 0, 0, 0, ((uint)&PawnThroughCatchContext) }
};

// R6Engine.dll data @ 1005e624 : pawnThroughTry
// State zero guards the query; state one belongs to its catches.
const NativeTryBlock pawnThroughTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnThroughCatch) }
};

// R6Engine.dll data @ 1005e638 : pawnThroughInfo
// Supplies the exact through-query exception metadata.
const NativeFunctionInfoPrefix pawnThroughInfo = { 0x19930520, 0x2, ((uint)&pawnThroughUnwind), 0x1,
    ((uint)&pawnThroughTry), 0 };

// Selects the through-query metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl ThroughResultExceptionHandler(void);

// R6Engine.dll data @ 1005e594 : pawnKillResultUnwind
// Both guarded/catch states terminate without owned cleanup.
const NativeUnwindEntry pawnKillResultUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e5a4 : pawnKillResultCatch
// Catches a text pointer in parent EBP-34, then reports other exceptions.
const NativeCatchEntry pawnKillResultCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -52, ((uint)&PawnKillResultCatchPointer) },
    { 0, 0, 0, ((uint)&PawnKillResultCatchContext) }
};

// R6Engine.dll data @ 1005e5c4 : pawnKillResultTry
// State zero guards the query; state one belongs to its two catches.
const NativeTryBlock pawnKillResultTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnKillResultCatch) }
};

// R6Engine.dll data @ 1005e5d8 : pawnKillResultInfo
// Binds the kill-result query to its exact inherited-frame exception records.
const NativeFunctionInfoPrefix pawnKillResultInfo = { 0x19930520, 0x2, ((uint)&pawnKillResultUnwind), 0x1,
    ((uint)&pawnKillResultTry), 0 };

// Selects the kill-query metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl KillResultExceptionHandler(void);

// R6Engine.dll data @ 1005e4d4 : pawnNightUnwind
// Both body/catch states terminate without owned cleanup.
const NativeUnwindEntry pawnNightUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e4e4 : pawnNightCatch
// Catches a text pointer in parent EBP-20, then reports other exceptions.
const NativeCatchEntry pawnNightCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&PawnNightCatchPointer) },
    { 0, 0, 0, ((uint)&PawnNightCatchContext) }
};

// R6Engine.dll data @ 1005e504 : pawnNightTry
// State zero guards script evaluation and vision changes; state one belongs to the catches.
const NativeTryBlock pawnNightTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnNightCatch) }
};

// R6Engine.dll data @ 1005e518 : pawnNightInfo
// Binds the vision toggle to its exact inherited-frame exception metadata.
const NativeFunctionInfoPrefix pawnNightInfo = { 0x19930520, 0x2, ((uint)&pawnNightUnwind), 0x1, ((uint)&pawnNightTry),
    0 };

// Selects the night-vision exception metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl NightVisionExceptionHandler(void);

// R6Engine.dll data @ 1005e534 : pawnScopeUnwind
// Both body/catch states terminate without owned cleanup.
const NativeUnwindEntry pawnScopeUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e544 : pawnScopeCatch
// Catches a text pointer in parent EBP-20, then reports other exceptions.
const NativeCatchEntry pawnScopeCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&PawnScopeCatchPointer) },
    { 0, 0, 0, ((uint)&PawnScopeCatchContext) }
};

// R6Engine.dll data @ 1005e564 : pawnScopeTry
// State zero guards script evaluation and vision changes; state one belongs to the catches.
const NativeTryBlock pawnScopeTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnScopeCatch) }
};

// R6Engine.dll data @ 1005e578 : pawnScopeInfo
// Binds the vision toggle to its exact inherited-frame exception metadata.
const NativeFunctionInfoPrefix pawnScopeInfo = { 0x19930520, 0x2, ((uint)&pawnScopeUnwind), 0x1, ((uint)&pawnScopeTry),
    0 };

// Selects the scope-vision exception metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl ScopeVisionExceptionHandler(void);

// R6Engine.dll data @ 1007454c : nightRestoreRenderMap
// Descriptive name for the render map remembered on every successful night-vision enable.
uint nightRestoreRenderMap = 5;

// R6Engine.dll data @ 10074550 : scopeRestoreRenderMap
// Descriptive name for scope disable's restoration word; scope enable does not update it.
uint scopeRestoreRenderMap = 5;

// R6Engine.dll data @ 1005be34 : pawnMovementUnwind
// Both guarded/catch states terminate without owned local cleanup.
const NativeUnwindEntry pawnMovementUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005be44 : pawnMovementCatch
// Catches a text pointer in parent EBP-9c, then reports other exceptions with parent context.
const NativeCatchEntry pawnMovementCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -156, ((uint)&PawnMovementCatchPointer) },
    { 0, 0, 0, ((uint)&PawnMovementCatchContext) }
};

// R6Engine.dll data @ 1005be64 : pawnMovementTry
// State zero guards the body; state one belongs to its two catches.
const NativeTryBlock pawnMovementTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pawnMovementCatch) }
};

// R6Engine.dll data @ 1005be78 : pawnMovementInfo
// Binds UpdateMovementAnimation to its inherited-frame catch records.
const NativeFunctionInfoPrefix pawnMovementInfo = { 0x19930520, 0x2, ((uint)&pawnMovementUnwind), 0x1,
    ((uint)&pawnMovementTry), 0 };

// Selects the parent's exception metadata without creating another dispatcher frame.
__declspec(naked) void __cdecl UpdateMovementAnimationExceptionHandler(void);

// R6Engine.dll data @ 10056a24 : pawnDtorUnwind
// State zero destroys the imported base and then terminates cleanup.
const NativeUnwindEntry pawnDtorUnwind[1] = {
    { -1, ((uint)&PawnDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056a2c : pawnDtorInfo
// Pawn destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix pawnDtorInfo = { 0x19930520, 0x1, ((uint)&pawnDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1005e474 : toggleHeatPropertiesUnwindMap
// Maps private states to prior states and cleanup entries; zero actions retain native empty transitions.
const NativeUnwindEntry toggleHeatPropertiesUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e484 : toggleHeatPropertiesCatchMap
// Retains four-word unsigned-short-pointer and catch-all handler records with signed frame displacements.
const NativeCatchEntry toggleHeatPropertiesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&ToggleHeatPropertiesCatchPointer) },
    { 0, 0, 0, ((uint)&ToggleHeatPropertiesCatchContext) }
};

// R6Engine.dll data @ 1005e4a4 : toggleHeatPropertiesTryMap
// Bounds the guarded private states and their two catch handlers.
const NativeTryBlock toggleHeatPropertiesTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&toggleHeatPropertiesCatchMap) }
};

// R6Engine.dll data @ 1005e4b8 : toggleHeatPropertiesFuncInfo
// Binds the selected MSVC exception dispatcher to its exact state, try and catch maps.
const NativeFunctionInfoPrefix toggleHeatPropertiesFuncInfo = { 0x19930520, 0x2, ((uint)&toggleHeatPropertiesUnwindMap),
    0x1, ((uint)&toggleHeatPropertiesTryMap), 0 };

// Routes the parent method through its selected C++ exception metadata.
__declspec(naked) void __cdecl ToggleHeatPropertiesExceptionHandler(void);

// R6Engine.dll data @ 1007441c : intAR6PawnexecSetAudioInfo
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecSetAudioInfo = (Native)&AR6Pawn::execSetAudioInfo;

// R6Engine.dll data @ 1007d9ed : AR6PawnSetAudioInfoRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnSetAudioInfoRegistrationResult = 0;

// R6Engine.dll data @ 10074420 : intAR6PawnexecPlayVoices
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPlayVoices = (Native)&AR6Pawn::execPlayVoices;

// R6Engine.dll data @ 1007ac00 : AR6PawnPlayVoicesRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPlayVoicesRegistrationResult = 0;

// R6Engine.dll data @ 10074424 : intAR6PawnexecSendPlaySound
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecSendPlaySound = (Native)&AR6Pawn::execSendPlaySound;

// R6Engine.dll data @ 10082688 : AR6PawnSendPlaySoundRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnSendPlaySoundRegistrationResult = 0;

// R6Engine.dll data @ 10074428 : intAR6PawnexecPawnCanBeHurtFrom
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPawnCanBeHurtFrom = (Native)&AR6Pawn::execPawnCanBeHurtFrom;

// R6Engine.dll data @ 1007a1a8 : AR6PawnPawnCanBeHurtFromRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPawnCanBeHurtFromRegistrationResult = 0;

// R6Engine.dll data @ 1007442c : intAR6PawnexecGetRotationOffset
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetRotationOffset = (Native)&AR6Pawn::execGetRotationOffset;

// R6Engine.dll data @ 1007831c : AR6PawnGetRotationOffsetRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetRotationOffsetRegistrationResult = 0;

// R6Engine.dll data @ 10074430 : intAR6PawnexecR6GetViewRotation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecR6GetViewRotation = (Native)&AR6Pawn::execR6GetViewRotation;

// R6Engine.dll data @ 1007e94d : AR6PawnR6GetViewRotationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnR6GetViewRotationRegistrationResult = 0;

// R6Engine.dll data @ 10074434 : intAR6PawnexecUpdatePawnTrackActor
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecUpdatePawnTrackActor = (Native)&AR6Pawn::execUpdatePawnTrackActor;

// R6Engine.dll data @ 1007d9f5 : AR6PawnUpdatePawnTrackActorRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnUpdatePawnTrackActorRegistrationResult = 0;

// R6Engine.dll data @ 10074438 : intAR6PawnexecPawnTrackActor
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPawnTrackActor = (Native)&AR6Pawn::execPawnTrackActor;

// R6Engine.dll data @ 1007d9f7 : AR6PawnPawnTrackActorRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPawnTrackActorRegistrationResult = 0;

// R6Engine.dll data @ 1007443c : intAR6PawnexecPawnLookAt
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPawnLookAt = (Native)&AR6Pawn::execPawnLookAt;

// R6Engine.dll data @ 10076eba : AR6PawnPawnLookAtRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPawnLookAtRegistrationResult = 0;

// R6Engine.dll data @ 10074440 : intAR6PawnexecPawnLookAbsolute
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPawnLookAbsolute = (Native)&AR6Pawn::execPawnLookAbsolute;

// R6Engine.dll data @ 1007a19c : AR6PawnPawnLookAbsoluteRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPawnLookAbsoluteRegistrationResult = 0;

// R6Engine.dll data @ 10074444 : intAR6PawnexecPawnLook
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecPawnLook = (Native)&AR6Pawn::execPawnLook;

// R6Engine.dll data @ 1007d9fd : AR6PawnPawnLookRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnPawnLookRegistrationResult = 0;

// R6Engine.dll data @ 10074448 : intAR6PawnexecFootStep
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecFootStep = (Native)&AR6Pawn::execFootStep;

// R6Engine.dll data @ 1007ac01 : AR6PawnFootStepRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnFootStepRegistrationResult = 0;

// R6Engine.dll data @ 1007444c : intAR6PawnexecMoveHitBone
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecMoveHitBone = (Native)&AR6Pawn::execMoveHitBone;

// R6Engine.dll data @ 1007fdc9 : AR6PawnMoveHitBoneRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnMoveHitBoneRegistrationResult = 0;

// R6Engine.dll data @ 10074450 : intAR6PawnexecStopLipSynch
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecStopLipSynch = (Native)&AR6Pawn::execStopLipSynch;

// R6Engine.dll data @ 100802e1 : AR6PawnStopLipSynchRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnStopLipSynchRegistrationResult = 0;

// R6Engine.dll data @ 10074454 : intAR6PawnexecStartLipSynch
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecStartLipSynch = (Native)&AR6Pawn::execStartLipSynch;

// R6Engine.dll data @ 1007e94c : AR6PawnStartLipSynchRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnStartLipSynchRegistrationResult = 0;

// R6Engine.dll data @ 10074458 : intAR6PawnexecGetMovementDirection
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetMovementDirection = (Native)&AR6Pawn::execGetMovementDirection;

// R6Engine.dll data @ 10076eb9 : AR6PawnGetMovementDirectionRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetMovementDirectionRegistrationResult = 0;

// R6Engine.dll data @ 1007445c : intAR6PawnexecGetMaxRotationOffset
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetMaxRotationOffset = (Native)&AR6Pawn::execGetMaxRotationOffset;

// R6Engine.dll data @ 10077e00 : AR6PawnGetMaxRotationOffsetRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetMaxRotationOffsetRegistrationResult = 0;

// R6Engine.dll data @ 10074460 : intAR6PawnexecGetPeekingRatioNorm
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetPeekingRatioNorm = (Native)&AR6Pawn::execGetPeekingRatioNorm;

// R6Engine.dll data @ 10080804 : AR6PawnGetPeekingRatioNormRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetPeekingRatioNormRegistrationResult = 0;

// R6Engine.dll data @ 10074464 : intAR6PawnexecCheckCylinderTranslation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecCheckCylinderTranslation = (Native)&AR6Pawn::execCheckCylinderTranslation;

// R6Engine.dll data @ 10081c61 : AR6PawnCheckCylinderTranslationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnCheckCylinderTranslationRegistrationResult = 0;

// R6Engine.dll data @ 10074468 : intAR6PawnexecSetPawnScale
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecSetPawnScale = (Native)&AR6Pawn::execSetPawnScale;

// R6Engine.dll data @ 100773d9 : AR6PawnSetPawnScaleRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnSetPawnScaleRegistrationResult = 0;

// R6Engine.dll data @ 1007446c : intAR6PawnexecAdjustFluidCollisionCylinder
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecAdjustFluidCollisionCylinder = (Native)&AR6Pawn::execAdjustFluidCollisionCylinder;

// R6Engine.dll data @ 1007abf5 : AR6PawnAdjustFluidCollisionCylinderRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnAdjustFluidCollisionCylinderRegistrationResult = 0;

// R6Engine.dll data @ 10074470 : intAR6PawnexecToggleScopeProperties
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecToggleScopeProperties = (Native)&AR6Pawn::execToggleScopeProperties;

// R6Engine.dll data @ 1007a190 : AR6PawnToggleScopePropertiesRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnToggleScopePropertiesRegistrationResult = 0;

// R6Engine.dll data @ 10074474 : intAR6PawnexecToggleNightProperties
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecToggleNightProperties = (Native)&AR6Pawn::execToggleNightProperties;

// R6Engine.dll data @ 1007a19d : AR6PawnToggleNightPropertiesRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnToggleNightPropertiesRegistrationResult = 0;

// R6Engine.dll data @ 10074478 : intAR6PawnexecToggleHeatProperties
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecToggleHeatProperties = (Native)&AR6Pawn::execToggleHeatProperties;

// R6Engine.dll data @ 1007ca88 : AR6PawnToggleHeatPropertiesRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnToggleHeatPropertiesRegistrationResult = 0;

// R6Engine.dll data @ 1007447c : intAR6PawnexecGetThroughResult
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetThroughResult = (Native)&AR6Pawn::execGetThroughResult;

// R6Engine.dll data @ 100773c9 : AR6PawnGetThroughResultRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetThroughResultRegistrationResult = 0;

// R6Engine.dll data @ 10074480 : intAR6PawnexecGetStunResult
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetStunResult = (Native)&AR6Pawn::execGetStunResult;

// R6Engine.dll data @ 1007d9fc : AR6PawnGetStunResultRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetStunResultRegistrationResult = 0;

// R6Engine.dll data @ 10074484 : intAR6PawnexecGetKillResult
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intAR6PawnexecGetKillResult = (Native)&AR6Pawn::execGetKillResult;

// R6Engine.dll data @ 100830bd : AR6PawnGetKillResultRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte AR6PawnGetKillResultRegistrationResult = 0;

// R6Engine.dll data @ 10081228 : autoclassAR6Pawn
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Pawn = nullptr;

// R6Engine.dll @ 100024a0 : AR6Pawn::eventUpdateBipodPosture
// Dispatches UpdateBipodPosture through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventUpdateBipodPosture(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_UpdateBipodPosture;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 100024d0 : AR6Pawn::eventResetBipodPosture
// Dispatches ResetBipodPosture through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventResetBipodPosture(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_ResetBipodPosture;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002500 : AR6Pawn::eventInitBiPodPosture
// Dispatches InitBiPodPosture through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventInitBiPodPosture(ulong bEnable)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_InitBiPodPosture;
    ulong enableWord = bEnable; // Full raw Bool word; no normalization.
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    bEnable = enableWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &bEnable, nullptr);
}

// R6Engine.dll @ 10002540 : AR6Pawn::eventSpawnRagDoll
// Dispatches SpawnRagDoll through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventSpawnRagDoll(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_SpawnRagDoll;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002570 : AR6Pawn::eventPlaySpecialPendingAction
// Dispatches the action byte and integer in an eight-byte packet, retaining untouched padding.
void __thiscall AR6Pawn::eventPlaySpecialPendingAction(byte eAction, int iActionInt)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    struct Parameters { byte action; byte padding[3]; int actionInt; } parameters; // Native padding stays unwritten.
    byte action = eAction;
    int actionInt = iActionInt;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    parameters.action = action;
    FName eventName = R6ENGINE_PlaySpecialPendingAction;
    parameters.actionInt = actionInt;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &parameters, nullptr);
}

// R6Engine.dll @ 100025b0 : AR6Pawn::eventEndOfGrenadeEffect
// Dispatches EndOfGrenadeEffect through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventEndOfGrenadeEffect(byte eType)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_EndOfGrenadeEffect;
    byte typeByte = eType; // Native reads only the low byte of the incoming argument slot.
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    eType = typeByte;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &eType, nullptr);
}

// R6Engine.dll @ 100025f0 : AR6Pawn::eventGetStanceReticuleModifier
// Dispatches the stance query with a zero-initialized result slot and returns its updated float.
float __thiscall AR6Pawn::eventGetStanceReticuleModifier(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_GetStanceReticuleModifier;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    float returnValue = 0.0f;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &returnValue, nullptr);
    return returnValue; // Native FLD reads the post-dispatch slot and returns live ST0.
}

// R6Engine.dll @ 10002630 : AR6Pawn::eventPlaySurfaceSwitch
// Dispatches PlaySurfaceSwitch through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventPlaySurfaceSwitch(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_PlaySurfaceSwitch;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002660 : AR6Pawn::eventR6ResetLookDirection
// Dispatches R6ResetLookDirection through the vtable captured before function lookup.
void __thiscall AR6Pawn::eventR6ResetLookDirection(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_R6ResetLookDirection;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    // Current slot of the captured table.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002690 : AR6Pawn::eventTurnToFaceActor
// Dispatches TurnToFaceActor using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventTurnToFaceActor(AActor* Target)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_TurnToFaceActor;
    AActor* argument = Target;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    Target = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &Target, nullptr);
}

// R6Engine.dll @ 100026d0 : AR6Pawn::eventResetDiagonalStrafing
// Dispatches ResetDiagonalStrafing with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventResetDiagonalStrafing(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_ResetDiagonalStrafing;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002700 : AR6Pawn::eventAdjustPawnForDiagonalStrafing
// Dispatches AdjustPawnForDiagonalStrafing with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventAdjustPawnForDiagonalStrafing(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_AdjustPawnForDiagonalStrafing;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002730 : AR6Pawn::eventRemovePotentialOpenDoor
// Dispatches RemovePotentialOpenDoor using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventRemovePotentialOpenDoor(AR6Door* Door)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_RemovePotentialOpenDoor;
    AR6Door* argument = Door;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    Door = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &Door, nullptr);
}

// R6Engine.dll @ 10002770 : AR6Pawn::eventPotentialOpenDoor
// Dispatches PotentialOpenDoor using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventPotentialOpenDoor(AR6Door* Door)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_PotentialOpenDoor;
    AR6Door* argument = Door;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    Door = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &Door, nullptr);
}

// R6Engine.dll @ 100027b0 : AR6Pawn::eventEndCrawl
// Dispatches the captured EndCrawl name with no parameters, retaining the vtable from before function lookup.
void __thiscall AR6Pawn::eventEndCrawl(void)
{
    // R6ENGINE_EndCrawl FName word precedes the vtable capture.
    uint eventNameWord = reinterpret_cast<uint&>(R6ENGINE_EndCrawl);
    NativeEventVtablePrefix* eventVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, *(FName*)&eventNameWord, 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    reinterpret_cast<ProcessEvent&>(eventVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 100027e0 : AR6Pawn::eventStartCrawl
// Dispatches StartCrawl with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventStartCrawl(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_StartCrawl;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002810 : AR6Pawn::eventPlayProneToCrouch
// Dispatches PlayProneToCrouch using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventPlayProneToCrouch(ulong bForcedByClient)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_PlayProneToCrouch;
    ulong argument = bForcedByClient;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    bForcedByClient = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &bForcedByClient, nullptr);
}

// R6Engine.dll @ 10002850 : AR6Pawn::eventPlayCrouchToProne
// Dispatches PlayCrouchToProne using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventPlayCrouchToProne(ulong bForcedByClient)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_PlayCrouchToProne;
    ulong argument = bForcedByClient;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    bForcedByClient = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &bForcedByClient, nullptr);
}

// R6Engine.dll @ 10002890 : AR6Pawn::eventPlayFluidPeekingAnim
// Dispatches three raw float words, preserving native input and packet-store order.
void __thiscall AR6Pawn::eventPlayFluidPeekingAnim(float fForwardPct, float fLeftPct, float fDeltaTime)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    uint parameters[3]; // ABI view of three FloatProperty words; MOV copies do not narrow or quiet inputs.
    uint forwardWord = reinterpret_cast<uint&>(fForwardPct);
    uint deltaWord = reinterpret_cast<uint&>(fDeltaTime);
    uint leftWord = reinterpret_cast<uint&>(fLeftPct);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    parameters[0] = forwardWord;
    parameters[1] = leftWord;
    FName eventName = R6ENGINE_PlayFluidPeekingAnim;
    parameters[2] = deltaWord;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, parameters, nullptr);
}

// R6Engine.dll @ 100028e0 : AR6Pawn::eventPlayPeekingAnim
// Dispatches PlayPeekingAnim using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventPlayPeekingAnim(ulong bUseSpecialPeekAnim)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_PlayPeekingAnim;
    ulong argument = bUseSpecialPeekAnim;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    bUseSpecialPeekAnim = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &bUseSpecialPeekAnim,
        nullptr);
}

// R6Engine.dll @ 10002920 : AR6Pawn::eventIsFullPeekingOver
// Dispatches IsFullPeekingOver with a zeroed result word and returns the full script-written Bool word.
ulong __thiscall AR6Pawn::eventIsFullPeekingOver(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_IsFullPeekingOver;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    ulong returnValue = 0;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &returnValue, nullptr);
    return returnValue; // Native MOV returns all 32 bits, with no Bool normalization.
}

// R6Engine.dll @ 10002960 : AR6Pawn::eventEndPeekingMode
// Dispatches EndPeekingMode using the captured vtable and a live parameter buffer.
void __thiscall AR6Pawn::eventEndPeekingMode(byte eMode)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_EndPeekingMode;
    byte argument = eMode;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    eMode = argument;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &eMode, nullptr);
}

// R6Engine.dll @ 100029a0 : AR6Pawn::eventStartFullPeeking
// Dispatches StartFullPeeking with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventStartFullPeeking(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_StartFullPeeking;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 100029d0 : AR6Pawn::eventStartFluidPeeking
// Dispatches StartFluidPeeking with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventStartFluidPeeking(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_StartFluidPeeking;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002a00 : AR6Pawn::eventIsPeekingLeft
// Dispatches IsPeekingLeft with a zeroed result word and returns the full script-written Bool word.
ulong __thiscall AR6Pawn::eventIsPeekingLeft(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_IsPeekingLeft;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    ulong returnValue = 0;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &returnValue, nullptr);
    return returnValue; // Native MOV returns all 32 bits, with no Bool normalization.
}

// R6Engine.dll @ 10002a40 : AR6Pawn::eventSetPeekingInfo
// Dispatches the mode byte, raw peeking float and full Bool word with untouched packet padding.
void __thiscall AR6Pawn::eventSetPeekingInfo(byte eMode, float fPeeking, ulong bPeekLeft)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    struct Parameters { byte mode; byte padding[3]; uint peekingWord; ulong peekLeft; } parameters;
    byte mode = eMode;
    ulong peekLeft = bPeekLeft;
    uint peekingWord = reinterpret_cast<uint&>(fPeeking);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    parameters.mode = mode; // Bytes +1..+3 retain native stack residue.
    parameters.peekingWord = peekingWord;
    FName eventName = R6ENGINE_SetPeekingInfo;
    parameters.peekLeft = peekLeft;
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &parameters, nullptr);
}

// R6Engine.dll @ 10002a90 : AR6Pawn::eventSetRotationOffset
// Dispatches three integer angle offsets through the pre-lookup vtable, retaining the native parameter-store order.
void __thiscall AR6Pawn::eventSetRotationOffset(int iPitch, int iYaw, int iRoll)
{
    int pitch = iPitch;
    int roll = iRoll;
    int yaw = iYaw;
    NativeEventVtablePrefix* eventVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    struct { int iPitch, iYaw, iRoll; } parameters; // Inferred twelve-byte packet at entryESP-12.
    parameters.iPitch = pitch;
    parameters.iYaw = yaw;
    FName name = R6ENGINE_SetRotationOffset;
    parameters.iRoll = roll;
    UFunction* function = UObject::FindFunctionChecked(this, name, 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(eventVtable->processEventAddress);
    processEvent(this, function, &parameters, nullptr); // Current slot of the saved table, after lookup.
}

// R6Engine.dll @ 10002ae0 : AR6Pawn::eventR6MakeMovementNoise
// Dispatches R6MakeMovementNoise with no parameter buffer, retaining the vtable captured before lookup.
void __thiscall AR6Pawn::eventR6MakeMovementNoise(void)
{
    using EventDispatcher = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    FName eventName = R6ENGINE_R6MakeMovementNoise;
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10002b10 : AR6Pawn::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Pawn::StaticClass(void)
{
    return &AR6Pawn::PrivateStaticClass; // Selected object at0x10078320.
}

// R6Engine.dll @ 10002b20 : AR6Pawn::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6Pawn::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    ulong retainedFlags = objectFlags;
    uint retainedNameWord = reinterpret_cast<uint&>(objectName);
    UObject* retainedOuter = outer;
    return UObject::StaticAllocateObject(&AR6Pawn::PrivateStaticClass, retainedOuter, *(FName*)&retainedNameWord,
        retainedFlags, nullptr, (FOutputDevice*)error, nullptr, 0);
}

// R6Engine.dll @ 10002b50 : AR6Pawn::~AR6Pawn
// Conditionally destroys UObject state and then enters imported abstract-pawn base destruction.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6Pawn::~AR6Pawn(AR6Pawn* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&PawnDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6PawnVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->AR6AbstractPawn::~AR6AbstractPawn();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10002bb0 : AR6Pawn::AR6Pawn (native default-constructor view)
// Constructs the AR6AbstractPawn base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6PawnVirtualTable follows base completion.
AR6Pawn::AR6Pawn() : AR6AbstractPawn()
{
}

// R6Engine.dll @ 10002bd0 : AR6Pawn::AR6Pawn (native copy-constructor view)
// Copies base, pending-action bytes, packed flags and raw derived words in native forward order.
AR6Pawn::AR6Pawn(const AR6Pawn& sourceObject) : AR6AbstractPawn(sourceObject)
{
    // Publishes AR6PawnVirtualTable after base copy; native EAX retains original storage.
    const AR6Pawn* source = &sourceObject;
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    reinterpret_cast<byte&>(this->m_eMovementPace) = input[0x664]; // m_eMovementPace.
    *(uint*)(destination + 0x665) = *(const uint*)(input + 0x665); // First four m_ePendingAction bytes together.
    for (uint offset = 0x669; offset < 0x678; ++offset) destination[offset] = input[offset];
    for (uint offset = 0x678; offset < 0x6c0; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint lastScalar = *(const uint*)(input + 0x6c0);
    uint firstFlags = *(uint*)(destination + 0x6c4); // Captured before m_iDesignHeavyTweak publication.
    reinterpret_cast<uint&>(this->m_iDesignHeavyTweak) = lastScalar;
    uint difference = firstFlags ^ *(const uint*)(input + 0x6c4);
    uint flags = *(uint*)(destination + 0x6c4) ^ (difference & 1U);
    *(uint*)(destination + 0x6c4) = flags;
    for (uint mask = 2; mask != 0x80000000U; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x6c4);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x6c4) = flags; // Separate stores for the first 31 declared flags.
    }
    difference = *(const uint*)(input + 0x6c4) ^ flags;
    uint lastSourceFlags = *(const uint*)(input + 0x6c4); // Native rereads the source for the final high-bit merge.
    uint lastFlags = (difference & 0x7fffffffU) ^ lastSourceFlags;
    uint secondFlags = *(uint*)(destination + 0x6c8); // Captured before publishing the first word's final bit.
    *(uint*)(destination + 0x6c4) = lastFlags;
    difference = secondFlags ^ *(const uint*)(input + 0x6c8);
    flags = *(uint*)(destination + 0x6c8) ^ (difference & 1U);
    *(uint*)(destination + 0x6c8) = flags;
    for (uint mask = 2; mask != 0x800000U; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x6c8);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x6c8) = flags; // 23 declared flags; retain the upper nine destination bits.
    }
    // Skill/speed values, names, references, vectors and rotators use ordered raw DWORD transfers.
    for (uint offset = 0x6cc; offset < 0xa28; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
}

// Copies the AR6AbstractPawn base and derived byte/word fields; only bit 0 at +0x6c4 is replaced.
// R6Engine.dll @ 10003b30 : AR6Pawn::operator=
// Copies base, pending-action bytes, packed flags and raw derived words in native forward order.
AR6Pawn& __thiscall AR6Pawn::operator=(const AR6Pawn& sourceObject)
{
    const AR6Pawn* source = &sourceObject;
    this->AR6AbstractPawn::operator=(*source);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0x664; offset < 0x678; ++offset) destination[offset] = input[offset];
    for (uint offset = 0x678; offset < 0x6bc; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint mediumTweak = *(const uint*)(input + 0x6bc);
    uint firstFlags = *(uint*)(destination + 0x6c4); // Captured before medium/heavy tweak publication.
    reinterpret_cast<uint&>(this->m_iDesignMediumTweak) = mediumTweak;
    reinterpret_cast<uint&>(this->m_iDesignHeavyTweak) = *(const uint*)(input + 0x6c0);
    uint difference = firstFlags ^ *(const uint*)(input + 0x6c4);
    uint flags = *(uint*)(destination + 0x6c4) ^ (difference & 1U);
    *(uint*)(destination + 0x6c4) = flags;
    for (uint mask = 2; mask != 0x80000000U; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x6c4);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x6c4) = flags; // Separate stores for the first 31 declared flags.
    }
    difference = *(const uint*)(input + 0x6c4) ^ flags;
    uint lastSourceFlags = *(const uint*)(input + 0x6c4); // Native rereads the source for the final high-bit merge.
    uint lastFlags = (difference & 0x7fffffffU) ^ lastSourceFlags;
    uint secondFlags = *(uint*)(destination + 0x6c8); // Captured before publishing the first word's final bit.
    *(uint*)(destination + 0x6c4) = lastFlags;
    difference = secondFlags ^ *(const uint*)(input + 0x6c8);
    flags = *(uint*)(destination + 0x6c8) ^ (difference & 1U);
    *(uint*)(destination + 0x6c8) = flags;
    for (uint mask = 2; mask != 0x800000U; mask <<= 1) {
        uint sourceFlags = *(const uint*)(input + 0x6c8);
        flags ^= (sourceFlags ^ flags) & mask;
        *(uint*)(destination + 0x6c8) = flags; // 23 declared flags; retain the upper nine destination bits.
    }
    // Skill/speed values, names, references, vectors and rotators use ordered raw DWORD transfers.
    for (uint offset = 0x6cc; offset < 0xa28; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    return *this; // Native has no self-assignment shortcut, owned member calls or local EH guard.
}

// R6Engine.dll @ 1000db50 : AR6Pawn::eventGetFiringStartPoint (native hidden-result view)
// Dispatches a zero-initialized vector result and copies its raw words forward to the caller's hidden output.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6Pawn::eventGetFiringStartPoint(FVector* result)
{
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    uint zeroScratch[3]; // Native uses separate scratch and event-result storage.
    uint parameters[3];
    zeroScratch[0] = 0;
    parameters[0] = zeroScratch[0];
    zeroScratch[1] = 0;
    parameters[1] = zeroScratch[1];
    FName eventName = R6ENGINE_GetFiringStartPoint;
    zeroScratch[2] = 0;
    parameters[2] = zeroScratch[2];
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(this, function, parameters, nullptr);
    uint* outputWords = (uint*)result; // Native samples the incoming hidden pointer only after dispatch.
    outputWords[0] = parameters[0];
    outputWords[1] = parameters[1];
    outputWords[2] = parameters[2];
    return (FVector*)outputWords; // EAX retains the captured output; RET4 consumes its hidden pointer.
}

// R6Engine.dll @ 1000dbd0 : AR6Pawn::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Pawn::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6PawnConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100215d0 : AR6Pawn::IsCrawling
// Tests for prone collision height below the class default collision height.
int __thiscall AR6Pawn::IsCrawling(void)
{
    float10 proneHeight = (float10)this->m_fProneHeight; // +0x464.
    float10 collisionHeight = (float10)this->CollisionHeight; // +0xfc.
    if (!(collisionHeight == proneHeight))
        return 0;
    UClass* pawnClass = this->Class;
    AR6Pawn* defaults = static_cast<AR6Pawn*>(pawnClass->GetDefaultObject());
    return (float10)this->CollisionHeight < (float10)defaults->CollisionHeight;
}

// R6Engine.dll @ 10021610 : AR6Pawn::GetMovementDirection
// Classifies player acceleration against facing, or nonplayer focus against destination, using native enum values.
eMovementDirection __thiscall AR6Pawn::GetMovementDirection(void)
{
    // Descriptive EBP-relative storage; normalized vectors reuse earlier snapshots and products.
    struct NativeFrameView {
        uint savedEdi, savedEsi, savedEbx; // EBP-0x94/-0x90/-0x8c.
        FCoords coords; // EBP-0x88..-0x59; native consumes the hidden output, not returned EAX.
        uint destination[3]; // EBP-0x58/-0x54/-0x50.
        uint products[3]; // EBP-0x4c/-0x48/-0x44.
        uint pawnOrProducts[3]; // EBP-0x40/-0x3c/-0x38.
        uint focus[3]; // EBP-0x34/-0x30/-0x2c, later normalized facing.
        uint direction[3]; // EBP-0x28/-0x24/-0x20: normalized acceleration or destination direction.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        float scalar; // EBP-0x14: rounded Size, or first nonplayer rounded reciprocal.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnMovementDirectionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AController* controller = this->Controller;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return (eMovementDirection)value; };
    if (controller == nullptr)
        return finish(0);
    UClass* type = controller->Class;
    UClass* playerClass = APlayerControllerPrivateStaticClassImport;
    while (type != nullptr && type != playerClass)
        type = type->GetSuperClass();
    if (type == playerClass) { // Native also enters here when the import and exhausted chain are both null.
        const FCoords* unitCoords = (FCoords*)(*(byte**)&CoreGMathImport + 0x18);
        frame.coords = *unitCoords / this->Rotation;
        FVector* acceleration = &this->Acceleration;
        frame.scalar = (float)acceleration->Size();
        float10 inverse = (float10)nativeFloatOne / frame.scalar;
        reinterpret_cast<float&>(frame.pawnOrProducts[0]) = (float)(inverse * acceleration->X);
        frame.direction[0] = frame.pawnOrProducts[0];
        reinterpret_cast<float&>(frame.pawnOrProducts[1]) = (float)(inverse * acceleration->Y);
        frame.direction[1] = frame.pawnOrProducts[1];
        reinterpret_cast<float&>(frame.pawnOrProducts[2]) = (float)(inverse * acceleration->Z);
        uint rawZ = frame.pawnOrProducts[2];
        float10 projection = frame.coords.XAxis.Z;
        frame.direction[2] = rawZ;
        projection *= reinterpret_cast<float&>(frame.direction[2]);
        float10 y = (float10)frame.coords.XAxis.Y * reinterpret_cast<float&>(frame.direction[1]);
        projection += y;
        float10 x = (float10)frame.coords.XAxis.X * reinterpret_cast<float&>(frame.direction[0]);
        projection += x;
        if (!(projection < nativeDouble0Point25))
            return finish(0);
        const FVector* zero = *(FVector**)&FVectorFVector0Import;
        float10 zx = zero->X;
        float10 nx = reinterpret_cast<float&>(frame.direction[0]);
        if (nx == zx) {
            float10 zy = zero->Y;
            float10 ny = reinterpret_cast<float&>(frame.direction[1]);
            if (ny == zy) {
                float10 zz = zero->Z;
                float10 nz = reinterpret_cast<float&>(frame.direction[2]);
                if (nz == zz)
                    return finish(0);
            }
        }
        return finish(projection < nativeDoubleMinus0Point25 ? 1 : 2);
    }
    controller = this->Controller;
    AActor* focusActor = controller->Focus;
    const uint* focus = focusActor != nullptr ? (uint*)&focusActor->Location : (uint*)&controller->FocalPoint;
    frame.focus[0] = focus[0];
    frame.focus[1] = focus[1];
    frame.focus[2] = focus[2];
    float10 y = reinterpret_cast<float&>(frame.focus[1]);
    uint pawnX = reinterpret_cast<uint&>(this->Location.X);
    uint pawnY = reinterpret_cast<uint&>(this->Location.Y);
    frame.pawnOrProducts[0] = pawnX;
    uint pawnZ = reinterpret_cast<uint&>(this->Location.Z);
    frame.pawnOrProducts[1] = pawnY;
    y -= reinterpret_cast<float&>(frame.pawnOrProducts[1]);
    float10 x = reinterpret_cast<float&>(frame.focus[0]);
    uint destinationX = reinterpret_cast<uint&>(controller->Destination.X);
    x -= reinterpret_cast<float&>(frame.pawnOrProducts[0]);
    frame.pawnOrProducts[2] = pawnZ;
    uint destinationY = reinterpret_cast<uint&>(controller->Destination.Y);
    frame.destination[0] = destinationX;
    uint destinationZ = reinterpret_cast<uint&>(controller->Destination.Z);
    reinterpret_cast<float&>(frame.direction[0]) = (float)x;
    uint rawX = frame.direction[0];
    frame.destination[1] = destinationY;
    reinterpret_cast<float&>(frame.direction[1]) = (float)y;
    uint rawY = frame.direction[1];
    frame.destination[2] = destinationZ;
    frame.direction[2] = 0;
    uint rawZ = frame.direction[2];
    frame.focus[1] = rawY;
    frame.focus[0] = rawX;
    frame.focus[2] = rawZ;
    frame.scalar = (float)((FVector*)frame.focus)->Size();
    frame.scalar = (float)((float10)nativeFloatOne / frame.scalar); // This reciprocal alone spills to binary32.
    float10 z = (float10)reinterpret_cast<float&>(frame.focus[2]) * frame.scalar;
    y = (float10)reinterpret_cast<float&>(frame.focus[1]) * frame.scalar;
    x = (float10)frame.scalar * reinterpret_cast<float&>(frame.focus[0]);
    reinterpret_cast<float&>(frame.products[0]) = (float)x;
    frame.focus[0] = frame.products[0];
    reinterpret_cast<float&>(frame.products[1]) = (float)y;
    frame.focus[1] = frame.products[1];
    reinterpret_cast<float&>(frame.products[2]) = (float)z;
    rawZ = frame.products[2];
    y = reinterpret_cast<float&>(frame.destination[1]);
    frame.focus[2] = rawZ;
    y -= reinterpret_cast<float&>(frame.pawnOrProducts[1]);
    frame.products[2] = 0;
    x = reinterpret_cast<float&>(frame.destination[0]);
    rawZ = frame.products[2];
    x -= reinterpret_cast<float&>(frame.pawnOrProducts[0]);
    frame.direction[2] = rawZ;
    reinterpret_cast<float&>(frame.products[0]) = (float)x;
    frame.direction[0] = frame.products[0];
    reinterpret_cast<float&>(frame.products[1]) = (float)y;
    frame.direction[1] = frame.products[1];
    frame.scalar = (float)((FVector*)frame.direction)->Size();
    float10 inverse = (float10)nativeFloatOne / frame.scalar;
    x = reinterpret_cast<float&>(frame.direction[0]);
    x *= inverse;
    reinterpret_cast<float&>(frame.products[0]) = (float)x;
    rawX = frame.products[0];
    y = reinterpret_cast<float&>(frame.direction[1]);
    frame.direction[0] = rawX;
    y *= inverse;
    reinterpret_cast<float&>(frame.products[1]) = (float)y;
    rawY = frame.products[1];
    z = reinterpret_cast<float&>(frame.direction[2]);
    frame.direction[1] = rawY;
    z *= inverse;
    reinterpret_cast<float&>(frame.products[2]) = (float)z;
    rawZ = frame.products[2];
    float10 projection = reinterpret_cast<float&>(frame.focus[2]);
    frame.direction[2] = rawZ;
    projection *= reinterpret_cast<float&>(frame.direction[2]);
    y = (float10)reinterpret_cast<float&>(frame.focus[1]) * reinterpret_cast<float&>(frame.direction[1]);
    projection += y;
    x = (float10)reinterpret_cast<float&>(frame.focus[0]) * reinterpret_cast<float&>(frame.direction[0]);
    projection += x;
    if (!(projection < nativeDouble0Point75))
        return finish(0);
    return finish(projection < nativeDoubleMinus0Point75 ? 1 : 2); // No zero-length or safe-normalization repair.
}

// R6Engine.dll @ 100218ed : MovementDirectionCatchPointer
// Rethrows the caught word through separate storage in the inherited movement-direction frame.
__declspec(naked) void MovementDirectionCatchPointer(void)
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

// R6Engine.dll @ 10021901 : MovementDirectionCatchContext
// Reports movement-direction context before forwarding the active exception.
__declspec(naked) void MovementDirectionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnGetMovementDirection
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044420 : PawnMovementDirectionExceptionHandler
// Forwards the movement-direction frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnMovementDirectionExceptionHandler(void)
{
    __asm {
        mov eax,offset movementDirectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10021920 : AR6Pawn::calcVelocity
// Selects posture speed, blends upright movement, applies stair scaling and forwards the native velocity packet.
void __thiscall AR6Pawn::calcVelocity(FVector accelDir, float deltaTime, float maxSpeed, float friction, int bFluid,
    int bBrake, int bBuoyant)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; unblended speed copies preserve raw float bits.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        uint selected; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnCalcVelocityExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.selected = 0;
    // Always called, including physics modes without posture selection.
    uint direction = (uint)this->AR6Pawn::GetMovementDirection();
    byte physics = reinterpret_cast<byte&>(this->Physics);
    if (physics == 1) {
        uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
        if ((flags & 0x200U) != 0) {
            frame.selected = direction == 2 ? reinterpret_cast<uint&>(this->m_fProneStrafeSpeed) :
                reinterpret_cast<uint&>(this->m_fProneSpeed);
        } else if ((flags & 0x20U) != 0) {
            if ((flags & 4U) != 0)
                frame.selected = direction == 0 ? reinterpret_cast<uint&>(this->m_fCrouchedWalkingSpeed) :
                    reinterpret_cast<uint&>(this->m_fCrouchedWalkingBackwardStrafeSpeed);
            else
                frame.selected = direction == 0 ? reinterpret_cast<uint&>(this->m_fCrouchedRunningSpeed) :
                    reinterpret_cast<uint&>(this->m_fCrouchedRunningBackwardStrafeSpeed);
        } else {
            float10 blend = this->m_fCrouchBlendRate;
            bool walking = (flags & 4U) != 0;
            bool positiveBlend = blend > nativeDouble0; // FCOMP preserves the prior walking TEST's CPU flags.
            const float* standing;
            const float* crouched;
            if (walking) {
                standing = direction == 0 ? &this->m_fWalkingSpeed : &this->m_fWalkingBackwardStrafeSpeed;
                crouched = direction == 0 ? &this->m_fCrouchedWalkingSpeed :
                    &this->m_fCrouchedWalkingBackwardStrafeSpeed;
            } else {
                standing = direction == 0 ? &this->m_fRunningSpeed : &this->m_fRunningBackwardStrafeSpeed;
                crouched = direction == 0 ? &this->m_fCrouchedRunningSpeed :
                    &this->m_fCrouchedRunningBackwardStrafeSpeed;
            }
            if (positiveBlend) {
                float10 difference = (float10)*standing - *crouched;
                float10 weight = (float10)nativeFloatOne - this->m_fCrouchBlendRate;
                float10 product = difference * weight;
                reinterpret_cast<float&>(frame.selected) = (float)(product + *crouched);
            } else {
                frame.selected = *(const uint*)standing;
            }
        }
    }
    float10 selected = reinterpret_cast<float&>(frame.selected);
    float10 zero = nativeDouble0;
    if (zero == selected) // Ordered equality: both signed zeros fall back; unordered values do not.
        frame.selected = reinterpret_cast<uint&>(maxSpeed);
    if ((reinterpret_cast<byte*>(this)[0x6c4] & 1U) != 0)
        reinterpret_cast<float&>(frame.selected) = (float)((float10)reinterpret_cast<float&>(frame.selected) *
            nativeFloat0Point894427);
    uint buoyant = reinterpret_cast<uint&>(bBuoyant);
    uint groundSpeed = frame.selected;
    uint brake = reinterpret_cast<uint&>(bBrake);
    uint rawFriction = reinterpret_cast<uint&>(friction);
    uint forwardedSpeed = frame.selected;
    reinterpret_cast<uint&>(this->GroundSpeed) = groundSpeed;
    uint fluid = reinterpret_cast<uint&>(bFluid);
    uint rawDelta = reinterpret_cast<uint&>(deltaTime);
    uint x = reinterpret_cast<uint&>(accelDir.X);
    uint y = reinterpret_cast<uint&>(accelDir.Y);
    uint z = reinterpret_cast<uint&>(accelDir.Z);
    using BaseCalcVelocity = void (__thiscall *)(APawn*, uint, uint, uint, uint, uint, uint, uint, uint, uint);
    reinterpret_cast<BaseCalcVelocity&>(APawnCalcVelocityImport)(this, x, y, z, rawDelta, forwardedSpeed,
        rawFriction,
        fluid, brake, buoyant); // Raw FVector/float/int words; selected speed replaces incoming maxSpeed only here.
    ExceptionList = frame.previousExceptionList; // Native RET 0x24; no owned local cleanup.
}

// R6Engine.dll @ 10021b3b : CalcVelocityCatchPointer
// Rethrows the caught word through separate storage in the inherited velocity frame.
__declspec(naked) void CalcVelocityCatchPointer(void)
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

// R6Engine.dll @ 10021b4f : CalcVelocityCatchContext
// Reports velocity-calculation context before forwarding the active exception.
__declspec(naked) void CalcVelocityCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnCalcVelocity
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044430 : PawnCalcVelocityExceptionHandler
// Forwards the velocity frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnCalcVelocityExceptionHandler(void)
{
    __asm {
        mov eax,offset calcVelocityFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10021b70 : AR6Pawn::GetDefaultHeightAndRadius
// Copies default collision height, collision radius and crouch height in that store order.
void __thiscall AR6Pawn::GetDefaultHeightAndRadius(float& height, float& crouchHeight, float& radius)
{
    UClass* pawnClass = this->Class;
    AR6Pawn* defaults = static_cast<AR6Pawn*>(pawnClass->GetDefaultObject());
    // +0xfc, first argument.
    reinterpret_cast<uint&>(height) = reinterpret_cast<const uint&>(defaults->CollisionHeight);
    // +0xf8, third argument.
    reinterpret_cast<uint&>(radius) = reinterpret_cast<const uint&>(defaults->CollisionRadius);
    // +0x454, second argument.
    reinterpret_cast<uint&>(crouchHeight) = reinterpret_cast<const uint&>(defaults->CrouchHeight);
}

// R6Engine.dll @ 10021ba0 : AR6Pawn::execSetPawnScale
// Evaluates scale and optional DebugInfo, then passes the current raw scale word to SetDrawScale.
void __thiscall AR6Pawn::execSetPawnScale(FFrame& stack, void* unusedResult)
{
    uint scaleWord = (uint)(uintptr_t)this; // Inferred entryESP-4: PUSH ECX, cleared after the Code read.
    FFrame* scriptFrame = &stack;
    uint cursor = reinterpret_cast<uint&>(scriptFrame->Code);
    scaleWord = 0;
    byte opcode = *(byte*)(uintptr_t)cursor;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* context = scriptFrame->Object;
    natives[opcode](context, scriptFrame, &scaleWord);
    cursor = reinterpret_cast<uint&>(scriptFrame->Code) + 1U;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor;
    if (*(byte*)(uintptr_t)cursor == 0x42) {
        context = scriptFrame->Object;
        reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](context, scriptFrame, nullptr);
    }
    uint argument = scaleWord; // Reload after both callbacks; no native x87 conversion.
    this->AActor::SetDrawScale(reinterpret_cast<float&>(argument));
    // Native pops the scale slot into ECX. Result is untouched; RET 8 removes both incoming arguments.
}

// R6Engine.dll @ 10021c10 : AR6Pawn::DirectionHasChanged
// Selects a strafe-direction byte from facing-dot and velocity-cross signs, returning whether the cache changed.
int __thiscall AR6Pawn::DirectionHasChanged(float movementFacingDot)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; all vector buffers remain local to this guard.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x48/-0x44/-0x40.
        FVector facing, cross, velocity; // EBP-0x3c/-0x30/-0x24.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnDirectionChangedExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint x = reinterpret_cast<uint&>(this->Velocity.X);
    uint y = reinterpret_cast<uint&>(this->Velocity.Y);
    uint z = reinterpret_cast<uint&>(this->Velocity.Z);
    reinterpret_cast<uint&>(frame.velocity.X) = x;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    reinterpret_cast<uint&>(frame.velocity.Y) = y;
    reinterpret_cast<uint&>(frame.velocity.Z) = z;
    frame.velocity.Normalize(); // Integer return is ignored.
    FVector* facing = &(frame.facing = this->Rotation.Vector());
    // Returned EAX is ignored.
    frame.cross = frame.velocity ^ *facing;
    float10 dot = movementFacingDot;
    float10 dotZero = nativeFloatZero;
    bool positive = dot > dotZero; // Ordered positive; unordered selects the second pair.
    float10 side = frame.cross.Z;
    float10 sideZero = nativeFloatZero;
    bool negative = side < sideZero;
    byte direction = positive ? (negative ? 1 : 2) : (negative ? 3 : 4);
    byte previousDirection = reinterpret_cast<byte&>(this->m_eStrafeDirection);
    if (direction == previousDirection) {
        ExceptionList = frame.previousExceptionList;
        return 0;
    }
    void* previousExceptionList = frame.previousExceptionList;
    // Only m_eStrafeDirection changes; adjacent bytes remain untouched.
    reinterpret_cast<byte&>(this->m_eStrafeDirection) = direction;
    ExceptionList = previousExceptionList;
    return 1; // Both native exits return a full integer and RET 4.
}

// R6Engine.dll @ 10021ce4 : DirectionChangedCatchPointer
// Rethrows the caught word through separate storage in the inherited strafe-direction frame.
__declspec(naked) void DirectionChangedCatchPointer(void)
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

// R6Engine.dll @ 10021cf8 : DirectionChangedCatchContext
// Reports the native DirectionChanged context before forwarding the active exception.
__declspec(naked) void DirectionChangedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnDirectionChanged
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044440 : PawnDirectionChangedExceptionHandler
// Forwards the strafe-direction frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnDirectionChangedExceptionHandler(void)
{
    __asm {
        mov eax,offset directionChangedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10021d20 : AR6Pawn::PreNetReceive
// Publishes the action byte and sound pointer to module snapshots before the base receive hook.
void __thiscall AR6Pawn::PreNetReceive(void)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; snapshots remain shared module data.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnPreNetReceiveExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte action = this->m_iNetCurrentActionIndex;
    AR6SoundReplicationInfo* sound = this->m_SoundRepInfo;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    PreNetCurrentActionIndex = action;
    PreNetSoundRepInfo = sound;
    this->APawn::PreNetReceive();
    ExceptionList = frame.previousExceptionList; // Native plain RET; no snapshot rollback or refresh.
}

// R6Engine.dll @ 10021d76 : PawnPreReceiveCatchPointer
// Rethrows the caught word through separate storage in the inherited pawn receive frame.
__declspec(naked) void PawnPreReceiveCatchPointer(void)
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

// R6Engine.dll @ 10021d8a : PawnPreReceiveCatchContext
// Reports pawn PreNetReceive context before forwarding the active exception.
__declspec(naked) void PawnPreReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPreNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044450 : PawnPreNetReceiveExceptionHandler
// Forwards this pawn receive frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnPreNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnPreReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10021db0 : AR6Pawn::PostNetReceive
// Stops newly received ragdoll sound when changed, initializes an action, then delegates the base receive hook.
void __thiscall AR6Pawn::PostNetReceive(void)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; snapshots remain shared module data.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnPostNetReceiveExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6SoundReplicationInfo* previousSound = PreNetSoundRepInfo;
    AR6SoundReplicationInfo* currentSound = this->m_SoundRepInfo;
    bool changed = previousSound != currentSound;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (changed && (reinterpret_cast<byte*>(this)[0xa4] & 0x20U) != 0 && currentSound != nullptr)
        currentSound->AR6SoundReplicationInfo::StopWeaponSound(); // Captured new object, without reloading the member.
    if (PreNetCurrentActionIndex == 0xffU) {
        byte action = this->m_iNetCurrentActionIndex; // Fresh shared snapshot and net byte after the sound callback.
        if (action != 0xffU)
            this->m_iLocalCurrentActionIndex = action;
    }
    this->APawn::PostNetReceive();
    ExceptionList = frame.previousExceptionList; // Native plain RET; no snapshot rollback or refresh.
}

// R6Engine.dll @ 10021e2d : PawnPostReceiveCatchPointer
// Rethrows the caught word through separate storage in the inherited pawn receive frame.
__declspec(naked) void PawnPostReceiveCatchPointer(void)
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

// R6Engine.dll @ 10021e41 : PawnPostReceiveCatchContext
// Reports pawn PostNetReceive context before forwarding the active exception.
__declspec(naked) void PawnPostReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPostNetReceive
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044460 : PawnPostNetReceiveExceptionHandler
// Forwards this pawn receive frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnPostNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnPostReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10021e60 : AR6Pawn::CheckSeePawn
// Applies zoom distance, view-cone and observation/visibility gates before the controller line-of-sight query.
ulong __thiscall AR6Pawn::CheckSeePawn(AR6Pawn* targetPawn, FVector* targetLocation, int unusedSightOptions)
{
    struct NativeFrameView { // Descriptive FPO storage relative to L = entry ESP-0x3c; no exception frame is installed.
        uint savedEsi; // L+0x00.
        byte untouched[3], rangeTier; // L+0x04..0x07; only the tier byte is initialized.
        float distanceSquared; // L+0x08.
        FVector direction; // L+0x0c.
        FVector inputOrFacing; // L+0x18: SafeNormal input, then copied facing.
        FVector temporary; // L+0x24: SafeNormal output, then Rotation::Vector output.
        FRotator rotation; // L+0x30.
    } frame;
    const uint* observationFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0x6c4);
    FVector* location = targetLocation;
    float10 x = location->X;
    AR6EngineWeapon* weapon = this->EngineWeapon;
    x -= this->Location.X;
    float10 y = location->Y;
    frame.rangeTier = 1;
    y -= this->Location.Y;
    float10 z = (float10)location->Z - this->Location.Z;
    float10 zSquared = z * z;
    float10 ySquared = y * y;
    float10 liveDistance = zSquared + ySquared;
    float10 xSquared = x * x;
    liveDistance += xSquared;
    frame.distanceSquared = (float)liveDistance;
    byte tier = 1; // Inline branch-selection view; the frame byte updates only after the native range comparison.
    const float* initialLimit = (float*)&nativeFloat1Point2544EPlus08;
    if (weapon != nullptr) {
        if ((float10)weapon->m_fMaxZoom >= nativeDouble10) {
            tier = 3;
            initialLimit = (float*)&nativeFloat1Point12896EPlus09;
        } else if ((*observationFlagWord & 0x800U) != 0 &&
            (float10)weapon->m_fMaxZoom >= nativeDouble2Point5) {
            tier = 2;
            initialLimit = (float*)&nativeFloat5Point0176EPlus08;
        }
    }
    bool tooFar = liveDistance > *initialLimit; // Uses the live extended sum, not its saved float copy.
    if (tier != 1)
        frame.rangeTier = tier;
    if (tooFar)
        return 0;
    frame.inputOrFacing.X = (float)((float10)location->X - this->Location.X);
    frame.inputOrFacing.Y = (float)((float10)location->Y - this->Location.Y);
    frame.inputOrFacing.Z = (float)((float10)location->Z - this->Location.Z);
    FVector* normal = &(frame.temporary = frame.inputOrFacing.SafeNormal());
    reinterpret_cast<uint&>(frame.direction.X) = reinterpret_cast<uint&>(normal->X);
    reinterpret_cast<uint&>(frame.direction.Y) = reinterpret_cast<uint&>(normal->Y);
    uint rawZ = reinterpret_cast<uint&>(normal->Z);
    byte* vtable = *(byte**)this;
    reinterpret_cast<uint&>(frame.direction.Z) = rawZ;
    FVector* pendingFacingOutput = &frame.temporary; // Native pushes this hidden output before the virtual call.
    using GetViewRotation = FRotator* (__thiscall *)(AR6Pawn*, FRotator*);
    FRotator* rotation = (*(GetViewRotation*)(vtable + 0xd4))(this, &frame.rotation);
    FVector* facing = &(*pendingFacingOutput = rotation->Vector());
    uint facingY = reinterpret_cast<uint&>(facing->Y);
    uint facingX = reinterpret_cast<uint&>(facing->X);
    uint facingZ = reinterpret_cast<uint&>(facing->Z);
    reinterpret_cast<uint&>(frame.inputOrFacing.Y) = facingY;
    float10 first = (float10)frame.inputOrFacing.Y * frame.direction.Y;
    reinterpret_cast<uint&>(frame.inputOrFacing.X) = facingX;
    float10 second = frame.inputOrFacing.X;
    AController* controller = this->Controller;
    second *= frame.direction.X;
    reinterpret_cast<uint&>(frame.inputOrFacing.Z) = facingZ;
    float10 stimulus = first + second;
    float10 third = (float10)frame.inputOrFacing.Z * frame.direction.Z;
    stimulus += third;
    stimulus -= this->PeripheralVision;
    controller->Stimulus = (float)stimulus;
    controller = this->Controller;
    float10 currentStimulus = controller->Stimulus;
    if (currentStimulus < nativeFloatZero)
        return 0;
    if ((*observationFlagWord & 0x800U) != 0) {
        z = frame.direction.Z;
        frame.direction.Z = (float)(z + z);
        frame.direction.Normalize();
        first = frame.inputOrFacing.Y;
        controller = this->Controller;
        first *= frame.direction.Y;
        second = (float10)frame.inputOrFacing.X * frame.direction.X;
        stimulus = first + second;
        third = (float10)frame.inputOrFacing.Z * frame.direction.Z;
        stimulus += third;
        stimulus -= this->PeripheralVision;
        controller->Stimulus = (float)stimulus;
        controller = this->Controller;
        currentStimulus = controller->Stimulus;
        if (currentStimulus < nativeFloatZero)
            return 0;
    }
    float10 effectiveRange = this->m_fSkillObservation;
    byte observerType = this->m_ePawnType;
    effectiveRange *= nativeDouble0Point5;
    const FVector* zero = *(FVector**)&FVectorFVector0Import;
    effectiveRange += nativeDouble0Point75;
    // Inline lazy-comparison view: zero loads precede each corresponding acceleration load.
    auto moving = [](AR6Pawn* pawn, const FVector* zeroVector) {
        float10 zx = zeroVector->X;
        float10 ax = pawn->Acceleration.X;
        if (!(ax == zx))
            return true;
        float10 zy = zeroVector->Y;
        float10 ay = pawn->Acceleration.Y;
        if (!(ay == zy))
            return true;
        float10 zz = zeroVector->Z;
        float10 az = pawn->Acceleration.Z;
        return !(az == zz);
    };
    if (observerType != 1 && moving(this, zero)) {
        bool walking = (reinterpret_cast<byte*>(this)[0x3e0] & 4U) != 0;
        effectiveRange *= (walking ? nativeFloat0Point8 : nativeFloat0Point6);
    }
    AR6Pawn* target = targetPawn; // Current incoming entry ESP+4 is sampled only after the math callbacks.
    if (target->m_ePawnType != 1 && moving(target, zero)) {
        bool walking = (reinterpret_cast<byte*>(target)[0x3e0] & 4U) != 0;
        effectiveRange *= (walking ? nativeFloat1Point2 : nativeFloat1Point4);
    }
    byte visibility = target->Visibility;
    // Incoming entry ESP+8 becomes integer visibility, then tier.
    uint& locationOrInteger = reinterpret_cast<uint&>(targetLocation);
    locationOrInteger = visibility;
    float10 visibilityFactor = (int)locationOrInteger; // Native FILD keeps the integer exact before the multiplication.
    visibilityFactor *= nativeFloat0Point0078125;
    effectiveRange *= visibilityFactor;
    float10 light = target->fLightValue;
    if (light < nativeFloat0Point3) {
        effectiveRange *= nativeFloatHalf;
    } else {
        light = target->fLightValue;
        if (light < nativeFloat0Point7)
            effectiveRange *= nativeFloat0Point75;
    }
    effectiveRange *= this->SightRadius;
    uint currentTier = frame.rangeTier;
    locationOrInteger = currentTier;
    effectiveRange *= (int)locationOrInteger;
    float10 squaredRange = effectiveRange * effectiveRange;
    float10 savedDistance = frame.distanceSquared;
    if (savedDistance > squaredRange)
        return 0;
    controller = this->Controller;
    // Full DWORD result; native RET 0x0c.
    return controller->AController::LineOfSightTo(target, 1);
}

// R6Engine.dll @ 100221b0 : AR6Pawn::R6SeePawn
// Filters fog, team and dead-target state, then checks an enemy or the pawn and prone-box locations.
ulong __thiscall AR6Pawn::R6SeePawn(APawn* targetPawn, int sightOptions)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; target is retained independently of its incoming slot.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnR6SeeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    APawn* target = targetPawn;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](ulong value) { ExceptionList = frame.previousExceptionList; return value; };
    if (target == nullptr)
        return finish(0);
    AController* initialController = this->Controller;
    if (initialController == nullptr)
        return finish(0);
    AZoneInfo* zone = this->Region.Zone;
    // bFogZone; the native zone pointer is unchecked.
    if ((*reinterpret_cast<byte*>(reinterpret_cast<byte*>(zone) + 0x398) & 1U) != 0) {
        float10 fog = (float10)zone->DistanceFogEnd - zone->DistanceFogStart;
        fog *= nativeFloat0Point1;
        fog = (float10)zone->DistanceFogEnd - fog;
        float10 z = (float10)this->Location.Z - target->Location.Z;
        float10 y = (float10)this->Location.Y - target->Location.Y;
        float10 x = (float10)this->Location.X - target->Location.X;
        float10 squaredRange = fog * fog;
        float10 xSquared = x * x;
        float10 ySquared = y * y;
        float10 squaredDistance = xSquared + ySquared;
        float10 zSquared = z * z;
        squaredDistance += zSquared;
        if (squaredDistance > squaredRange) // Extended arithmetic throughout; equality and unordered continue.
            return finish(0);
    }
    byte health = target->m_eHealth;
    uint& rememberSlot = reinterpret_cast<uint&>(targetPawn); // Incoming EBP+8 becomes a mutable dead-target flag.
    rememberSlot = 0;
    if (health < 2) {
        uint observerTeam = reinterpret_cast<uint&>(this->m_iTeam);
        uint targetTeam = reinterpret_cast<uint&>(target->m_iTeam);
        if (observerTeam == targetTeam)
            return finish(0);
    } else {
        uint targetFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(target) + 0x6c8);
        rememberSlot = 1;
        if ((targetFlags & 0x200U) != 0)
            return finish(0);
    }
    ulong result;
    AActor* enemy = initialController->Enemy;
    if (target == enemy) {
        // sightOptions is unused here.
        result = initialController->AController::LineOfSightTo(target, 0);
    } else {
        AController* activeController = this->Controller;
        uint activeFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(activeController) + 0x3a8);
        uint initialFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(initialController) + 0x3a8);
        uint mixedFlags = ((~activeFlags ^ initialFlags) & 4U) ^ initialFlags;
        // Retained across both sight queries, even if callbacks change EBP+0xc.
        uint options = reinterpret_cast<uint&>(sightOptions);
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(activeController) + 0x3a8) = mixedFlags;
        result = this->AR6Pawn::CheckSeePawn(reinterpret_cast<AR6Pawn*>(target), &target->Location, (int)options);
        if (result == 0) {
            uint proneFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(target) + 0x3e0);
            if ((proneFlags & 0x200U) == 0)
                return finish(0);
            AActor* collisionBox = target->m_collisionBox;
            if (collisionBox == nullptr)
                return finish(0);
            uint collisionFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(collisionBox) + 0xa8);
            if ((collisionFlags & 0x800U) == 0)
                return finish(0);
            result =
                this->AR6Pawn::CheckSeePawn(reinterpret_cast<AR6Pawn*>(target), &collisionBox->Location, (int)options);
        }
    }
    if (result == 0)
        return finish(0);
    uint remember = rememberSlot;
    if (remember != 0)
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(target) + 0x6c8) |= 0x200U;
    return finish(result); // Full DWORD survives the final flag update; native RET 8.
}

// R6Engine.dll @ 10022350 : R6SeeCatchPointer
// Rethrows the caught word through separate storage in the inherited sight-query frame.
__declspec(naked) void R6SeeCatchPointer(void)
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

// R6Engine.dll @ 10022364 : R6SeeCatchContext
// Reports R6SeePawn context before forwarding the active exception.
__declspec(naked) void R6SeeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnR6SeePawn
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044470 : PawnR6SeeExceptionHandler
// Forwards the sight-query frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnR6SeeExceptionHandler(void)
{
    __asm {
        mov eax,offset r6SeeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022390 : AR6Pawn::GetMidSectionLocation
// Returns a prone facing offset or a selector-dependent vertical sample through the hidden output buffer.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6Pawn::GetMidSectionLocation(FVector* result, AActor* targetActor)
{
    AActor* target = targetActor; // Retained independently of the incoming word reused below.
    APawn* pawnResult = target->GetPlayerPawn(); // Only its nullness is used; subsequent reads use target.
    if (pawnResult != nullptr && (*(uint*)((byte*)target + 0x3e0) & 0x200U) != 0) { // m_bIsProne.
        // Incoming entry ESP+8 changes from target to integer to float.
        uint& distanceWord = reinterpret_cast<uint&>(targetActor);
        distanceWord = (uint)this->m_iVisibilityTest + 1U; // Wrapping INC, followed by signed FILD of this slot.
        float10 scaledDistance = (int)distanceWord;
        scaledDistance *= nativeFloatMinus0Point5;
        scaledDistance *= target->CollisionRadius;
        reinterpret_cast<float&>(distanceWord) = (float)scaledDistance;
        FVector facingOutput; // Descriptive FPO local at entry ESP-0x0c; X/Y offsets occupy ESP-0x18/-0x14.
        FVector* facing = &(facingOutput = target->Rotation.Vector());
        float10 x = reinterpret_cast<float&>(distanceWord);
        x *= facing->X;
        float offsetX = (float)x;
        float10 y = reinterpret_cast<float&>(distanceWord);
        y *= facing->Y;
        float offsetY = (float)y;
        float10 z = reinterpret_cast<float&>(distanceWord); // Reload after the callback for each product.
        z *= facing->Z;
        FVector* output = result; // Capture the current hidden pointer only after the Z product.
        z += target->Location.Z;
        y = offsetY;
        y += target->Location.Y;
        x = offsetX;
        x += target->Location.X;
        output->X = (float)x;
        output->Y = (float)y;
        output->Z = (float)z;
        return output;
    }
    int selector = this->m_iVisibilityTest; // Reload after the virtual gate.
    FVector* output = result;
    if (selector == 0) {
        reinterpret_cast<uint&>(output->X) = reinterpret_cast<const uint&>(target->Location.X);
        reinterpret_cast<uint&>(output->Y) = reinterpret_cast<const uint&>(target->Location.Y);
        reinterpret_cast<uint&>(output->Z) = reinterpret_cast<const uint&>(target->Location.Z);
        return output;
    }
    float10 z = target->Location.Z;
    if (selector == 1)
        z += nativeFloat15;
    else
        z -= nativeFloat15;
    uint xWord = reinterpret_cast<const uint&>(target->Location.X);
    float10 y = target->Location.Y;
    output->Y = (float)y; // These branches write Y before X, with Z still live.
    reinterpret_cast<uint&>(output->X) = xWord;
    output->Z = (float)z;
    return output;
}

// R6Engine.dll @ 100224b0 : AR6Pawn::IsOverLedge
// Probes ledges with a normalized direction, then restores acceleration and the current controller's timer.
int __thiscall AR6Pawn::IsOverLedge(AActor* actor, FVector movementDelta, float deltaSeconds)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; the output and snapshots remain callback-visible.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x60/-0x5c/-0x58.
        FVector adjustedDelta; // EBP-0x54.
        uint unused48;
        uint directionY, directionZ; // EBP-0x44/-0x40; X remains in a register until argument copying.
        FVector normalOrGravity; // EBP-0x3c; SafeNormal output becomes the gravity vector.
        FVector savedAcceleration; // EBP-0x30.
        uint caught, rethrow; // EBP-0x24/-0x20.
        uint savedMoveTimer; // EBP-0x1c.
        int checkedFall, mustJump; // EBP-0x18/-0x14; descriptive flag names.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnLedgeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    auto orderedZero = [](const float* component) {
        float10 zero = nativeFloatZero;
        float10 value = *component;
        return value == zero; // Unordered is false; each test reloads the native zero constant first.
    };
    FVector* acceleration = &this->Acceleration;
    bool zeroX = orderedZero(&acceleration->X); // X comparison finishes before state zero is activated.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    FVector* directionSource = acceleration;
    if (!(zeroX && orderedZero(&acceleration->Y) && orderedZero(&acceleration->Z))) {
        directionSource = &(frame.normalOrGravity = acceleration->SafeNormal());
    }
    uint directionX = reinterpret_cast<uint&>(directionSource->X);
    uint directionY = reinterpret_cast<uint&>(directionSource->Y);
    uint directionZ = reinterpret_cast<uint&>(directionSource->Z);
    frame.directionY = directionY;
    frame.directionZ = directionZ;
    uint savedX = reinterpret_cast<uint&>(acceleration->X); // Snapshot follows the possible normalization callback.
    reinterpret_cast<uint&>(frame.savedAcceleration.X) = savedX;
    uint savedY = reinterpret_cast<uint&>(acceleration->Y);
    uint savedZ = reinterpret_cast<uint&>(acceleration->Z);
    reinterpret_cast<uint&>(frame.savedAcceleration.Y) = savedY;
    AController* controller = this->Controller;
    reinterpret_cast<uint&>(frame.savedAcceleration.Z) = savedZ;
    uint timer = reinterpret_cast<uint&>(controller->MoveTimer);
    APhysicsVolume* volume = this->PhysicsVolume;
    float10 gravityZ = volume->Gravity.Z;
    frame.savedMoveTimer = timer;
    bool positiveGravity = gravityZ > nativeFloatZero;
    reinterpret_cast<uint&>(frame.normalOrGravity.X) = 0;
    reinterpret_cast<uint&>(frame.normalOrGravity.Y) = 0;
    reinterpret_cast<uint&>(frame.normalOrGravity.Z) = 0xbf800000;
    if (positiveGravity) // Ordered positive; NaN retains -1.
        reinterpret_cast<uint&>(frame.normalOrGravity.Z) = 0x3f800000;
    // Queued before flag initialization and the by-value vectors.
    uint timeWord = reinterpret_cast<uint&>(deltaSeconds);
    frame.checkedFall = 0;
    frame.mustJump = 0;
    FVector gravityArgument;
    reinterpret_cast<uint&>(gravityArgument.X) = reinterpret_cast<uint&>(frame.normalOrGravity.X);
    reinterpret_cast<uint&>(gravityArgument.Y) = reinterpret_cast<uint&>(frame.normalOrGravity.Y);
    reinterpret_cast<uint&>(gravityArgument.Z) = reinterpret_cast<uint&>(frame.normalOrGravity.Z);
    FVector deltaArgument;
    reinterpret_cast<uint&>(deltaArgument.X) = reinterpret_cast<uint&>(movementDelta.X);
    byte* vtable = *(byte**)this; // Captured between the first and second incoming delta reads.
    reinterpret_cast<uint&>(deltaArgument.Y) = reinterpret_cast<uint&>(movementDelta.Y);
    reinterpret_cast<uint&>(deltaArgument.Z) = reinterpret_cast<uint&>(movementDelta.Z);
    FVector directionArgument;
    reinterpret_cast<uint&>(directionArgument.X) = directionX;
    reinterpret_cast<uint&>(directionArgument.Y) = frame.directionY;
    reinterpret_cast<uint&>(directionArgument.Z) = frame.directionZ;
    AActor* actorArgument = actor;
    using CheckForLedges = FVector* (__thiscall *)(AR6Pawn*, FVector*, AActor*, FVector, FVector, FVector,
        int*, int*, float);
    CheckForLedges checkForLedges = *(CheckForLedges*)(vtable + 0x190);
    checkForLedges(this, &frame.adjustedDelta, actorArgument, directionArgument, deltaArgument, gravityArgument,
        // EAX and both flag results are ignored.
        &frame.checkedFall, &frame.mustJump, reinterpret_cast<float&>(timeWord));
    bool wasMoving = !(orderedZero(&frame.savedAcceleration.X) && orderedZero(&frame.savedAcceleration.Y) &&
        orderedZero(&frame.savedAcceleration.Z));
    bool blocked = wasMoving && orderedZero(&acceleration->X) && orderedZero(&acceleration->Y) &&
        orderedZero(&acceleration->Z);
    auto same = [](const float* incoming, const float* output) {
        float10 first = *incoming;
        float10 second = *output;
        return second == first; // Unordered counts as unequal; component comparisons short-circuit.
    };
    bool changed = !blocked && !(same(&movementDelta.X, &frame.adjustedDelta.X) &&
        same(&movementDelta.Y, &frame.adjustedDelta.Y) && same(&movementDelta.Z, &frame.adjustedDelta.Z));
    int overLedge = blocked || changed;
    savedX = reinterpret_cast<uint&>(frame.savedAcceleration.X);
    savedY = reinterpret_cast<uint&>(frame.savedAcceleration.Y);
    reinterpret_cast<uint&>(acceleration->X) = savedX;
    savedZ = reinterpret_cast<uint&>(frame.savedAcceleration.Z);
    reinterpret_cast<uint&>(acceleration->Y) = savedY;
    controller = this->Controller;
    reinterpret_cast<uint&>(acceleration->Z) = savedZ;
    timer = frame.savedMoveTimer;
    reinterpret_cast<uint&>(controller->MoveTimer) = timer; // The current controller receives the saved word.
    ExceptionList = frame.previousExceptionList;
    return overLedge; // Native RET 0x14; exceptional exits perform no restoration cleanup.
}

// R6Engine.dll @ 100226c6 : LedgeCatchPointer
// Rethrows the caught word through separate storage in the inherited ledge-probe frame.
__declspec(naked) void LedgeCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100226da : LedgeCatchContext
// Reports IsOverLedge context before forwarding the active exception.
__declspec(naked) void LedgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnIsOverLedge
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044480 : PawnLedgeExceptionHandler
// Passes the ledge-probe frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnLedgeExceptionHandler(void)
{
    __asm {
        mov eax,offset ledgeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022700 : AR6Pawn::ResetColBox
// Resets the collision-box relative position, aligns its height through the hash, and clears prone-pivot bookkeeping.
void __thiscall AR6Pawn::ResetColBox(void)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; the temporary zero vector is distinct from FVector0.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        FVector zero; // EBP-0x24.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&ResetColBoxExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* initialBox = this->m_collisionBox;
    bool hasBox = initialBox != nullptr; // Native TEST precedes saved-ESP storage and state zero activation.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (!hasBox) {
        ExceptionList = frame.previousExceptionList;
        return;
    }
    // IAT directly addresses the imported FVector0 object.
    const uint* zero = *(const uint**)&FVectorFVector0Import;
    uint* relative = (uint*)&initialBox->RelativeLocation;
    relative[0] = zero[0];
    relative[1] = zero[1];
    relative[2] = zero[2];
    float10 pawnZ = (float10)this->Location.Z;
    AActor* box = this->m_collisionBox;
    if ((float10)box->Location.Z != pawnZ) { // Unordered heights also enter the alignment path.
        void* collisionHash = *(void**)((byte*)this->XLevel + 0xf0);
        using HashActorCall = void (__thiscall *)(void*, AActor*);
        // bCollideActors.
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8) & 0x800U) != 0 && collisionHash != nullptr) {
            HashActorCall removeActor = *(HashActorCall*)(*(byte**)collisionHash + 0xc);
            removeActor(collisionHash, box);
        }
        box = this->m_collisionBox;
        uint pawnZWord = reinterpret_cast<const uint&>(this->Location.Z);
        reinterpret_cast<uint&>(box->Location.Z) = pawnZWord;
        box = this->m_collisionBox;
        box->RelativeLocation.Z = (float)((float10)box->Location.Z - this->Location.Z);
        box = this->m_collisionBox;
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8) & 0x800U) != 0 && collisionHash != nullptr) {
            HashActorCall addActor = *(HashActorCall*)(*(byte**)collisionHash + 8);
            addActor(collisionHash, box); // Retains the captured hash, even if the removal changed XLevel.
        }
    }
    reinterpret_cast<uint&>(frame.zero.X) = 0;
    uint zeroX = reinterpret_cast<uint&>(frame.zero.X);
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.X) = zeroX;
    reinterpret_cast<uint&>(frame.zero.Y) = 0;
    uint zeroY = reinterpret_cast<uint&>(frame.zero.Y);
    reinterpret_cast<uint&>(frame.zero.Z) = 0;
    uint zeroZ = reinterpret_cast<uint&>(frame.zero.Z);
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.Y) = zeroY;
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.Z) = zeroZ;
    reinterpret_cast<uint&>(this->m_fPrePivotLastUpdate) = 0;
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 10022820 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ResetBoxCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10022834 : report method context and rethrow without adding a funclet frame
__declspec(naked) void ResetBoxCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnResetColBox // L"AR6Pawn::ResetColBox()".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044490 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void ResetColBoxExceptionHandler(void)
{
    __asm {
        mov eax,offset resetBoxFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022860 : AR6Pawn::SetPrePivot
// Copies the pivot and lowers matching initial Z by five while climbing stairs.
void __thiscall AR6Pawn::SetPrePivot(FVector prePivot)
{
    uint pivotXWord = reinterpret_cast<const uint&>(prePivot.X);
    float10 initialOffset = (float10)this->m_fPrePivotPawnInitialOffset; // +0x4e8, captured before the stores.
    reinterpret_cast<uint&>(this->PrePivot.X) = pivotXWord; // +0x2c8.
    reinterpret_cast<uint&>(this->PrePivot.Y) = reinterpret_cast<const uint&>(prePivot.Y);
    reinterpret_cast<uint&>(this->PrePivot.Z) = reinterpret_cast<const uint&>(prePivot.Z);
    float10 pivotZ = (float10)this->PrePivot.Z; // Ordered equality below accepts signed zeros and rejects NaNs.
    if (pivotZ == initialOffset &&
        (reinterpret_cast<const byte*>(this)[0x6c4] & 1U) != 0) { // m_bIsClimbingStairs.
        float10 adjustedZ = (float10)this->PrePivot.Z - nativeDouble5;
        this->PrePivot.Z = (float)adjustedZ;
    }
}

// R6Engine.dll @ 100228b0 : AR6Pawn::m_vExecuteLipsSynch
// Checks the mesh class before forwarding delta time to the lip-sync data.
void __thiscall AR6Pawn::m_vExecuteLipsSynch(float deltaSeconds)
{
    UMesh* mesh = this->Mesh; // +0x16c.
    if (mesh == nullptr)
        return;
    UClass* classCursor = mesh->Class;
    // USkeletalMesh::PrivateStaticClass import.
    UClass* skeletalMeshClass = USkeletalMeshPrivateStaticClassImport;
    while (classCursor != nullptr && classCursor != skeletalMeshClass)
        classCursor = classCursor->GetSuperClass();
    if (classCursor == nullptr && skeletalMeshClass != nullptr)
        return;
    ECLipSynchData* lipSynch = (ECLipSynchData*)(uint)this->m_hLipSynchData; // +0x6b0.
    if (lipSynch != nullptr) {
        // Native tail-jumps with the original slot.
        lipSynch->ECLipSynchData::m_vUpdateLipSynch(deltaSeconds);
    }
}

// R6Engine.dll @ 100228f0 : AR6Pawn::m_vInitNewLipSynch
// Replaces lip-sync storage, constructs it from the current mesh and captured sounds, then starts the returned object.
void __thiscall AR6Pawn::m_vInitNewLipSynch(USound* sound, USound* stopSound)
{
    struct NativeFrameView { // Descriptive offsets relative to entry ESP; this parent omits EBP.
        uint savedEdi, savedEsi; // Entry ESP-0x18/-0x14.
        void* allocation; // Entry ESP-0x10; cleanup receives an EBP base equal to entry ESP.
        void* previousExceptionList; // Entry ESP-0x0c.
        void* handler; // Entry ESP-0x08.
        int state; // Entry ESP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&LipInitExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.allocation = this; // The initial PUSH ECX slot is replaced only after allocation returns.
    ECLipSynchData* oldData = (ECLipSynchData*)(uint)this->m_hLipSynchData;
    if (oldData != nullptr) {
        FMalloc* allocator = **(FMalloc***)&CoreGMallocImport; // Imported address of GMalloc, then its current value.
        allocator->Free(oldData);
        this->m_hLipSynchData = 0; // Clear only after release returns; no destructor or stop call.
    }
    FMalloc* allocator = **(FMalloc***)&CoreGMallocImport; // Reload even if release changed the global allocator.
    // L"new".
    ECLipSynchData* allocation = (ECLipSynchData*)allocator->Malloc(0x18, nativeTextNew);
    frame.allocation = allocation; // Cleanup uses this slot; the constructor receiver remains retained separately.
    bool hasAllocation = allocation != nullptr;
    frame.state = 0;
    ECLipSynchData* initializedData = nullptr;
    if (hasAllocation) {
        USound* constructorStopSound = stopSound;
        USound* constructorSound = sound; // Already queued before MeshGetInstance can change the incoming slots.
        UMesh* mesh = this->Mesh;
        UMeshInstance* meshInstance = mesh->MeshGetInstance(this); // Native mesh pointer is unchecked.
        initializedData = ::new (reinterpret_cast<void*>(allocation)) ECLipSynchData(
            meshInstance, constructorSound, constructorStopSound, this);
    }
    frame.state = -1;
    this->m_hLipSynchData = (int)(uint)initializedData;
    // Also called for null; outside allocation cleanup.
    initializedData->ECLipSynchData::m_vStartLipsynch();
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 100444a0 : LipInitState0Cleanup
// Frees the saved raw allocation through the current global allocator using the initializer's inherited frame base.
__declspec(naked) void LipInitState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x10]
        push eax
        call FreeThroughGlobalAllocator
        pop ecx
        ret
    }
}

// R6Engine.dll @ 100444ab : LipInitExceptionHandler
// Passes the frameless initializer's cleanup metadata to the shared C++ exception dispatcher.
__declspec(naked) void LipInitExceptionHandler(void)
{
    __asm {
        mov eax,offset lipInitFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100229a0 : AR6Pawn::TickSpecial
// Tail-forwards the original receiver and delta-time stack slot to imported APawn::TickSpecial.
__declspec(naked) void __thiscall AR6Pawn::TickSpecial(float deltaSeconds)
{
    __asm { jmp dword ptr [APawnTickSpecialImport] }
}

// R6Engine.dll @ 100229b0 : AR6Pawn::execStartLipSynch
// Evaluates two sounds and optional debug data, then initializes lip-sync from the current sound words.
// Native ABI view retains the incoming frame word for the second sound pointer.
void __thiscall AR6Pawn::execStartLipSynch(FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    USound* sound = reinterpret_cast<USound*>(this); // Native PUSH ECX creates the local word at entry ESP-4.
    FFrame* frame = stack; // Retained while the incoming frame word becomes the second sound below.
    byte** codeCursor = &frame->Code;
    byte* code = *codeCursor;
    sound = nullptr;
    byte opcode = *code;
    *codeCursor = code + 1;
    ScriptNative* natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
    UObject* expressionReceiver = frame->Object;
    natives[opcode](expressionReceiver, frame, &sound);
    code = *codeCursor;
    USound*& stopSound = reinterpret_cast<USound*&>(stack); // Entry ESP+4: incoming frame slot, not the result slot.
    stopSound = nullptr;
    opcode = *code;
    byte* next = code + 1;
    expressionReceiver = frame->Object; // Receiver read precedes the second cursor store.
    *codeCursor = next;
    natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
    natives[opcode](expressionReceiver, frame, &stopSound);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        expressionReceiver = frame->Object;
        *codeCursor = code + 1;
        natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
        natives[0x42](expressionReceiver, frame, nullptr);
    }
    USound* currentSound = sound;
    if (currentSound != nullptr) {
        USound* currentStopSound = stopSound;
        this->AR6Pawn::m_vInitNewLipSynch(currentSound, currentStopSound);
    }
}

// R6Engine.dll @ 10022a40 : AR6Pawn::execStopLipSynch
// Consumes the terminator and optional debug record, then stops the current lip-sync data.
void __thiscall AR6Pawn::execStopLipSynch(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    FFrame* frame = &stack;
    byte** codeCursor = &frame->Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        *codeCursor = code + 1; // Stop's debug receiver is read after this store.
        UObject* debugReceiver = frame->Object;
        ScriptNative* natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
        natives[0x42](debugReceiver, frame, nullptr);
    }
    ECLipSynchData* lipSynch = (ECLipSynchData*)(uint)this->m_hLipSynchData;
    if (lipSynch != nullptr) {
        lipSynch->ECLipSynchData::m_vStopLipsynch();
    }
}

// R6Engine.dll @ 10022a80 : AR6Pawn::getMaxRotationOffset
// Returns the general rotation limit or selects the weapon limit from its bipod flag.
int __thiscall AR6Pawn::getMaxRotationOffset(int useWeaponLimit)
{
    if (useWeaponLimit == 0)
        return 0x1555;
    AR6EngineWeapon* weapon = this->EngineWeapon; // +0x4fc.
    if (weapon == nullptr)
        return 3000;
    if ((reinterpret_cast<const byte*>(weapon)[0x3a0] & 2U) != 0) // m_bBipod.
        return 0x15e0;
    return 3000;
}

// R6Engine.dll @ 10022ac0 : AR6Pawn::GetPeekingRatioNorm
// Subtracts the peeking origin and scales the extended result using the native double constants.
float10 __thiscall AR6Pawn::GetPeekingRatioNorm(float fPeeking)
{
    float10 normalized = fPeeking;
    normalized -= nativeDouble1000;
    normalized *= nativeDouble0Point001;
    return normalized; // Native ST0 result and RET 4; the receiver is unused.
}

// R6Engine.dll @ 10022ae0 : AR6Pawn::execGetPeekingRatioNorm
// Evaluates peeking and optional debug data, then spills the extended normalization to the shared input and result.
// Native ABI view retains the incoming frame word for the rounded normalization spill.
void __thiscall AR6Pawn::execGetPeekingRatioNorm(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        float peeking; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PeekNormExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    FFrame* vmFrame = stack;
    byte** codeCursor = &vmFrame->Code;
    byte* code = *codeCursor;
    reinterpret_cast<uint&>(frame.peeking) = 0;
    byte opcode = *code;
    *codeCursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
    UObject* expressionReceiver = vmFrame->Object;
    frame.state = 0; // The late opcode-function read and call are both inside state zero.
    natives[opcode](expressionReceiver, vmFrame, &frame.peeking);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        expressionReceiver = vmFrame->Object;
        *codeCursor = code + 1;
        natives = reinterpret_cast<ScriptNative*&>(CoreGNativesImport);
        natives[0x42](expressionReceiver, vmFrame, nullptr);
    }
    float peekingArgument = frame.peeking;
    float10 normalizedRatio = this->AR6Pawn::GetPeekingRatioNorm(peekingArgument);
    reinterpret_cast<float&>(stack) = (float)normalizedRatio; // FST into incoming EBP+8, replacing the frame pointer.
    void* output = result; // Native samples EBP+0xc after that shared-slot store.
    *(float*)output = (float)normalizedRatio; // FSTP from the live value, without reloading the preceding spill.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 10022b78 : PeekNormCatchPointer
// Rethrows the caught word through separate storage in the inherited peeking VM frame.
__declspec(naked) void PeekNormCatchPointer(void)
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

// R6Engine.dll @ 10022b8c : PeekNormCatchContext
// Reports the peeking-normalization VM context before forwarding the active exception.
__declspec(naked) void PeekNormCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetPeekingRatioNorm
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100444c0 : PeekNormExceptionHandler
// Passes the peeking VM's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PeekNormExceptionHandler(void)
{
    __asm {
        mov eax,offset peekNormFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022bb0 : AR6Pawn::GetMaxFluidPeeking
// Computes the selected fluid-peeking side from the crouch blend, retaining the live extended intermediates.
float10 __thiscall AR6Pawn::GetMaxFluidPeeking(float crouchBlendRate, int peekingLeft)
{
    float10 normalizedPeeking = this->AR6Pawn::GetPeekingRatioNorm(1600.0f);
    float10 inverseNormalized = nativeFloatOne;
    int left = peekingLeft; // Native reads this word between the first FLD one and its subtraction.
    inverseNormalized -= normalizedPeeking;
    float10 inverseBlend = nativeFloatOne;
    inverseBlend -= crouchBlendRate;
    float10 scaledPeeking = inverseNormalized * inverseBlend;
    scaledPeeking = normalizedPeeking + scaledPeeking;
    scaledPeeking *= nativeDouble1000;
    if (left != 0)
        return nativeDouble1000 - scaledPeeking;
    return scaledPeeking + nativeDouble1000; // Native ST0 result and RET 8, with no float spill.
}

// R6Engine.dll @ 10022bf0 : AR6Pawn::IsUsingHeartBeatSensor
// Requires the player flag, a weapon and a nonzero full-word IsGoggles event result.
int __thiscall AR6Pawn::IsUsingHeartBeatSensor(void)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; no owned cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&SensorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool isPlayer = (reinterpret_cast<byte*>(this)[0x3e8] & 0x10U) != 0; // m_bIsPlayer, tested before state zero.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (!isPlayer)
        return finish(0);
    AR6EngineWeapon* weapon = this->EngineWeapon;
    if (weapon == nullptr)
        return finish(0);
    uint gogglesResult = weapon->AR6EngineWeapon::eventIsGoggles();
    return finish(gogglesResult != 0); // Full DWORD normalization; the callback is followed by no field recheck.
}

// R6Engine.dll @ 10022c4b : SensorCatchPointer
// Rethrows the caught word through separate storage in the inherited sensor-query frame.
__declspec(naked) void SensorCatchPointer(void)
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

// R6Engine.dll @ 10022c5f : SensorCatchContext
// Reports the sensor-query context before forwarding the active exception.
__declspec(naked) void SensorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnIsUsingHeartBeatSensor
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100444d0 : SensorExceptionHandler
// Passes the sensor query's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void SensorExceptionHandler(void)
{
    __asm {
        mov eax,offset sensorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022c90 : AR6Pawn::WeaponShouldFollowHead
// Suppresses following in physics mode 12 or on ladders, then checks the sensor, current timer and gadget flag.
int __thiscall AR6Pawn::WeaponShouldFollowHead(void)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; no owned cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&FollowHeadExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool physicsSuppressesFollow = (byte)this->Physics == 12; // Native comparison precedes saved ESP and state zero.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (physicsSuppressesFollow)
        return finish(0);
    if ((reinterpret_cast<byte*>(this)[0x6c4] & 4U) != 0) // m_bIsClimbingLadder.
        return finish(0);
    if (this->AR6Pawn::IsUsingHeartBeatSensor() != 0)
        return finish(1);
    float10 firingTimer = this->m_fFiringTimer; // +0x75c; sampled after the nested sensor/event call.
    float10 zero = nativeFloatZero;
    if (firingTimer > zero) // Ordered positive; unordered takes the gadget path.
        return finish(1);
    // Fresh full word; earlier ladder/physics gates are not repeated.
    uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4);
    return finish((flags >> 9) & 1U); // m_bWeaponGadgetActivated; native plain RET and normalized 0/1.
}

// R6Engine.dll @ 10022d1c : FollowHeadCatchPointer
// Rethrows the caught word through separate storage in the inherited weapon-follow frame.
__declspec(naked) void FollowHeadCatchPointer(void)
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

// R6Engine.dll @ 10022d30 : FollowHeadCatchContext
// Reports the weapon-follow context before forwarding the active exception.
__declspec(naked) void FollowHeadCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnWeaponShouldFollowHead
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100444e0 : FollowHeadExceptionHandler
// Passes the weapon-follow frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void FollowHeadExceptionHandler(void)
{
    __asm {
        mov eax,offset followHeadFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022d60 : AR6Pawn::WeaponIsAGadget
// Returns one for an absent weapon or weapon type six or seven.
int __thiscall AR6Pawn::WeaponIsAGadget(void)
{
    AR6EngineWeapon* weapon = this->EngineWeapon; // +0x4fc.
    if (weapon == nullptr)
        return 1;
    byte weaponType = weapon->m_eWeaponType; // +0x394.
    if (weaponType == 7)
        return 1;
    return weaponType == 6;
}

// R6Engine.dll @ 10022d90 : AR6Pawn::PawnSetBoneRotation
// Applies a bone rotation through the current mesh instance with space zero, unit alpha and raw blend time.
void __thiscall AR6Pawn::PawnSetBoneRotation(FName bone, int pitch, int yaw, int roll, float blendTime)
{
    struct NativeFrameView { // Descriptive EBP-relative storage; no owned cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnSetBoneRotationExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    UMesh* mesh = this->Mesh; // Unchecked; both the mesh and vtable read precede state zero.
    byte* meshVtable = *(byte**)mesh;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    using MeshGetInstance = UMeshInstance* (__thiscall *)(UMesh*, const AActor*);
    MeshGetInstance meshGetInstance = *(MeshGetInstance*)(meshVtable + 0x88); // The slot read is inside the guard.
    USkeletalMeshInstance* meshInstance = static_cast<USkeletalMeshInstance*>(meshGetInstance(mesh, this));
    // All incoming argument words are sampled after the mesh callback.
    uint blendWord = reinterpret_cast<uint&>(blendTime);
    uint pitchWord = reinterpret_cast<uint&>(pitch);
    uint yawWord = reinterpret_cast<uint&>(yaw);
    uint rollWord = reinterpret_cast<uint&>(roll);
    FRotator boneTurn;
    reinterpret_cast<uint&>(boneTurn.Pitch) = pitchWord;
    uint boneWord = reinterpret_cast<uint&>(bone); // The one-word name is read after the outgoing pitch store.
    reinterpret_cast<uint&>(boneTurn.Yaw) = yawWord;
    reinterpret_cast<uint&>(boneTurn.Roll) = rollWord;
    meshInstance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(boneWord),
        boneTurn, 0, 1.0f, reinterpret_cast<float&>(blendWord));
    ExceptionList = frame.previousExceptionList; // The native ignores the imported integer result and returns RET 0x14.
}

// R6Engine.dll @ 10022e09 : BoneRotationCatchPointer
// Rethrows the caught word through separate storage in the inherited bone-rotation frame.
__declspec(naked) void BoneRotationCatchPointer(void)
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

// R6Engine.dll @ 10022e1d : BoneRotationCatchContext
// Reports the bone-rotation context before forwarding the active exception.
__declspec(naked) void BoneRotationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPawnSetBoneRotation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100444f0 : PawnSetBoneRotationExceptionHandler
// Passes the bone-rotation frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void PawnSetBoneRotationExceptionHandler(void)
{
    __asm {
        mov eax,offset boneRotationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10022e40 : AR6Pawn::WeaponFollow
// Adjusts both clavicles for relative pitch and weapon grip, or resets them when high stance is disabled.
void __thiscall AR6Pawn::WeaponFollow(int relativePitch, float blendTime)
{
    struct NativeFrameView { // Descriptive EBP-relative guard, name-word and reset-path storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x70/-0x6c/-0x68.
        uint caught; // EBP-0x64.
        uint nameWords[18]; // EBP-0x60 through -0x1c.
        uint rethrow, resetName; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&WeaponFollowExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6EngineWeapon* weapon = this->EngineWeapon; // Captured before state zero; retained for grip selection.
    bool hasWeapon = weapon != nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (!hasWeapon) {
        finish();
        return;
    }
    using NameConstructor = FName* (__thiscall *)(FName*, const ushort*, int);
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e4) & 0x40000U) == 0) { // m_bUseHighStance.
        UMesh* mesh = this->Mesh; // +0x16c.
        USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(this));
        uint& instanceWord = reinterpret_cast<uint&>(relativePitch); // Incoming EBP+8 becomes the reset receiver slot.
        instanceWord = (uint)instance;
        FRotator zeroRotation = {0, 0, 0}; // The native zero registers survive both callback sequences.
        NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        // R6 R Clavicle.
        FName* right = constructName((FName*)&frame.resetName, nativeTextR6RClavicle, 1);
        uint timeWord = reinterpret_cast<uint&>(blendTime);
        uint boneWord = *(uint*)right;
        instance = reinterpret_cast<USkeletalMeshInstance*>(instanceWord); // Reread after the name callback.
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(boneWord),
            zeroRotation, 0, 1.0f, reinterpret_cast<float&>(timeWord));
        constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        // Same name output slot.
        FName* left = constructName((FName*)&frame.resetName, nativeTextR6LClavicle, 1);
        timeWord = reinterpret_cast<uint&>(blendTime);
        boneWord = *(uint*)left;
        instance = reinterpret_cast<USkeletalMeshInstance*>(instanceWord);
        // Both receiver and time remain current for the second call.
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(boneWord),
            zeroRotation, 0, 1.0f, reinterpret_cast<float&>(timeWord));
        finish();
        return;
    }
    // Preserve the helper's ST0 input and low EAX result; rotation channels keep native conversion order.
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    byte gripType = weapon->m_eGripType; // +0x395; unsigned one-based jump table, other values do nothing.
    switch (gripType) {
    case 8: {
        uint& fractionWord = reinterpret_cast<uint&>(relativePitch);
        uint originalPitch = fractionWord;
        if ((int)originalPitch > 0) {
            fractionWord = originalPitch - 0x1000U;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x1c.
            FName* right = constructName((FName*)&frame.nameWords[17], nativeTextR6RClavicle,
                1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            // Native EBX retains this word for both calls in this branch.
            uint timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloatMinus2Point25EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloat1Point4EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, 0, roll, reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x20.
            FName* left = constructName((FName*)&frame.nameWords[16], nativeTextR6LClavicle, 1);
            // Each product reloads the callback-visible fraction slot.
            rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloatMinus2Point5EPlus02;
            roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat3EPlus03;
            int yaw = truncateLowWord(yawProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus2Point75EPlus03;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        } else {
            uint adjustedWord = 0xfffff000U - originalPitch; // Wrapping subtraction, then a signed threshold test.
            fractionWord = adjustedWord;
            if ((int)adjustedWord > 0x1000) {
                // Retained across both constructors.
                NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                fractionWord = adjustedWord - 0x1000U;
                float10 scaledPitch = (int)fractionWord;
                scaledPitch *= nativeFloat0Point00024414062;
                reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
                // EBP-0x2c.
                FName* right = constructName((FName*)&frame.nameWords[13],
                    nativeTextR6RClavicle, 1);
                float10 rollProduct = reinterpret_cast<float&>(fractionWord);
                uint timeWord = reinterpret_cast<uint&>(blendTime);
                rollProduct += nativeFloatOne;
                rollProduct *= nativeFloat4EPlus03;
                int roll = truncateLowWord(rollProduct);
                float10 yawProduct = reinterpret_cast<float&>(fractionWord);
                yawProduct *= nativeFloat3EPlus03;
                yawProduct = (float10)nativeFloatMinus1EPlus03 - yawProduct;
                int yaw = truncateLowWord(yawProduct);
                float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
                pitchProduct *= nativeFloat2Point5EPlus03;
                pitchProduct = (float10)nativeFloatMinus2EPlus03 - pitchProduct;
                int pitch = truncateLowWord(pitchProduct);
                uint boneWord = *(uint*)right;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                    reinterpret_cast<float&>(timeWord));
                // EBP-0x30.
                FName* left = constructName((FName*)&frame.nameWords[12], nativeTextR6LClavicle,
                    1);
                rollProduct = reinterpret_cast<float&>(fractionWord);
                rollProduct *= nativeFloat5Point5EPlus03;
                timeWord = reinterpret_cast<uint&>(blendTime); // Fresh time after the left roll multiplication.
                rollProduct = (float10)nativeFloatMinus2EPlus03 - rollProduct;
                roll = truncateLowWord(rollProduct);
                yawProduct = reinterpret_cast<float&>(fractionWord);
                yawProduct *= nativeFloat8EPlus02;
                yawProduct = (float10)nativeFloatMinus1EPlus03 - yawProduct;
                yaw = truncateLowWord(yawProduct);
                pitchProduct = reinterpret_cast<float&>(fractionWord);
                pitchProduct *= nativeFloat2EPlus03;
                pitchProduct += nativeFloat4EPlus03;
                pitch = truncateLowWord(pitchProduct);
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                    reinterpret_cast<float&>(timeWord));
            } else {
                float10 scaledPitch = (int)fractionWord;
                scaledPitch *= nativeFloat0Point00024414062;
                reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
                NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                // EBP-0x24.
                FName* right = constructName((FName*)&frame.nameWords[15],
                    nativeTextR6RClavicle, 1);
                float10 rollProduct = reinterpret_cast<float&>(fractionWord);
                frame.resetName = (uint)right; // EBP-0x14 is a returned-name pointer cache on this path.
                rollProduct *= nativeFloat4EPlus03;
                int roll = truncateLowWord(rollProduct);
                float10 yawProduct = reinterpret_cast<float&>(fractionWord);
                yawProduct *= nativeFloatMinus1EPlus03;
                int yaw = truncateLowWord(yawProduct);
                float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
                pitchProduct *= nativeFloatMinus2EPlus03;
                int pitch = truncateLowWord(pitchProduct);
                uint timeWord = reinterpret_cast<uint&>(blendTime);
                right = (FName*)frame.resetName;
                fractionWord = (uint)pitch; // Incoming EBP+8 changes again, from float fraction to converted pitch.
                uint boneWord = *(uint*)right;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                    reinterpret_cast<float&>(timeWord));
                constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                // EBP-0x28.
                FName* left = constructName((FName*)&frame.nameWords[14], nativeTextR6LClavicle,
                    1);
                timeWord = reinterpret_cast<uint&>(blendTime);
                // Reread after both callbacks; the other converted integers stay cached.
                int leftRoll = (int)fractionWord;
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, roll, yaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            }
        }
        break;
    }
    case 1: {
        uint& fractionWord = reinterpret_cast<uint&>(relativePitch);
        uint originalPitch = fractionWord;
        if ((int)originalPitch > 0) {
            // Cached before adjusting the incoming word.
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            fractionWord = originalPitch - 0x1000U;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            // EBP-0x34.
            FName* right = constructName((FName*)&frame.nameWords[11], nativeTextR6RClavicle,
                1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            uint timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloatMinus2Point5EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat5EPlus02;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus2Point25EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
            // EBP-0x38.
            FName* left = constructName((FName*)&frame.nameWords[10], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            // Current time for the second call; constructor pointer remains cached.
            timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloat3EPlus03;
            roll = truncateLowWord(rollProduct);
            yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloatMinus1EPlus03;
            yaw = truncateLowWord(yawProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus5EPlus02;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        } else {
            fractionWord = 0xfffff000U - originalPitch;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x3c.
            FName* right = constructName((FName*)&frame.nameWords[9], nativeTextR6RClavicle, 1);
            float10 pitchYawProduct = reinterpret_cast<float&>(fractionWord);
            pitchYawProduct *= nativeFloat4EPlus03;
            int pitchAndYaw = truncateLowWord(pitchYawProduct);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            // Read after the first conversion, before the roll multiplication.
            uint timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloat5EPlus03;
            int roll = truncateLowWord(rollProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitchAndYaw, pitchAndYaw, roll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x40.
            FName* left = constructName((FName*)&frame.nameWords[8], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloatMinus6EPlus03;
            roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat1Point5EPlus03;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus5EPlus02;
            int pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        }
        break;
    }
    case 4: {
        uint& fractionWord = reinterpret_cast<uint&>(relativePitch);
        uint originalPitch = fractionWord;
        if ((int)originalPitch > 0) {
            fractionWord = originalPitch - 0x1000U;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x44.
            FName* right = constructName((FName*)&frame.nameWords[7], nativeTextR6RClavicle, 1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            uint timeWord = reinterpret_cast<uint&>(blendTime); // Retained in native EBX for both bone calls.
            rollProduct *= nativeFloatMinus3EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat1EPlus03;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus2EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x48.
            FName* left = constructName((FName*)&frame.nameWords[6], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloat4EPlus03;
            roll = truncateLowWord(rollProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus1Point5EPlus03;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, 0, roll, reinterpret_cast<float&>(timeWord));
        } else {
            // Cached before the wrapping adjustment.
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            fractionWord = 0xfffff000U - originalPitch;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            // EBP-0x4c.
            FName* right = constructName((FName*)&frame.nameWords[5], nativeTextR6RClavicle, 1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            uint timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloat5Point5EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat2EPlus03;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloat3EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
            // EBP-0x50.
            FName* left = constructName((FName*)&frame.nameWords[4], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            // Current time after the left fraction load; constructor stays cached.
            timeWord = reinterpret_cast<uint&>(blendTime);
            rollProduct *= nativeFloatMinus5Point75EPlus03;
            roll = truncateLowWord(rollProduct);
            yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat2Point5EPlus03;
            yaw = truncateLowWord(yawProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus1EPlus03;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        }
        break;
    }
    case 2:
    case 3:
    case 5:
    case 6:
    case 7: {
        uint& fractionWord = reinterpret_cast<uint&>(relativePitch);
        uint originalPitch = fractionWord;
        bool positivePitch = (int)originalPitch > 0; // Sign is retained across the name callbacks.
        // Captured before either adjustment.
        NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        if (positivePitch) {
            fractionWord = originalPitch - 0x1000U;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            // EBP-0x54.
            FName* right = constructName((FName*)&frame.nameWords[3], nativeTextR6RClavicle, 1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloatMinus2Point25EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat1EPlus03;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus2Point5EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll, 0.0f);
            // EBP-0x58.
            FName* left = constructName((FName*)&frame.nameWords[2], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloat1Point8EPlus03;
            roll = truncateLowWord(rollProduct);
            yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat1Point2EPlus03;
            yaw = truncateLowWord(yawProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus2Point55EPlus03;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll, 0.0f);
        } else {
            fractionWord = 0xfffff000U - originalPitch;
            float10 scaledPitch = (int)fractionWord;
            scaledPitch *= nativeFloat0Point00012207031;
            reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
            // EBP-0x5c.
            FName* right = constructName((FName*)&frame.nameWords[1], nativeTextR6RClavicle, 1);
            float10 rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloat4Point75EPlus03;
            int roll = truncateLowWord(rollProduct);
            float10 yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloat1Point25EPlus03;
            int yaw = truncateLowWord(yawProduct);
            float10 pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloat3EPlus03;
            int pitch = truncateLowWord(pitchProduct);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll, 0.0f);
            // EBP-0x60.
            FName* left = constructName((FName*)&frame.nameWords[0], nativeTextR6LClavicle, 1);
            rollProduct = reinterpret_cast<float&>(fractionWord);
            rollProduct *= nativeFloatMinus5Point5EPlus03;
            roll = truncateLowWord(rollProduct);
            yawProduct = reinterpret_cast<float&>(fractionWord);
            yawProduct *= nativeFloatMinus3Point2EPlus03;
            yaw = truncateLowWord(yawProduct);
            pitchProduct = reinterpret_cast<float&>(fractionWord);
            pitchProduct *= nativeFloatMinus1Point5EPlus03;
            pitch = truncateLowWord(pitchProduct);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll, 0.0f);
        }
        break;
    }
    }
    finish();
}

// R6Engine.dll @ 10023524 : WeaponFollowCatchPointer
// Rethrows the caught word through separate storage in the inherited clavicle-follow frame.
__declspec(naked) void WeaponFollowCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x64]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10023538 : WeaponFollowCatchContext
// Reports the clavicle-follow context before forwarding the active exception.
__declspec(naked) void WeaponFollowCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnWeaponFollow
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044500 : WeaponFollowExceptionHandler
// Passes the clavicle-follow frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void WeaponFollowExceptionHandler(void)
{
    __asm {
        mov eax,offset weaponFollowFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10023580 : AR6Pawn::WeaponLock
// Applies grip/posture clavicle rotations using the supplied fraction or pitch-derived standing segments.
void __thiscall AR6Pawn::WeaponLock(int relativePitch, float fraction, float blendTime)
{
    struct NativeFrameView { // Descriptive EBP-relative guard and shared word storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xa0/-0x9c/-0x98.
        uint caught; // EBP-0x94.
        uint words[30]; // EBP-0x90 through -0x1c; roles are path-dependent.
        uint rethrow, word14; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&WeaponLockExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6EngineWeapon* weapon = this->EngineWeapon; // Captured before state zero; retained for grip selection.
    bool hasWeapon = weapon != nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (!hasWeapon) {
        finish();
        return;
    }
    using NameConstructor = FName* (__thiscall *)(FName*, const ushort*, int);
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e4) & 0x40000U) == 0) { // m_bUseHighStance.
        UMesh* mesh = this->Mesh; // +0x16c.
        USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(this));
        // Incoming EBP+0xc changes from float fraction to instance pointer.
        uint& instanceWord = reinterpret_cast<uint&>(fraction);
        instanceWord = (uint)instance;
        FRotator zeroRotation = {0, 0, 0};
        NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        // Output is incoming EBP+8.
        FName* right = constructName((FName*)&relativePitch, nativeTextR6RClavicle, 1);
        uint timeWord = reinterpret_cast<uint&>(blendTime);
        uint boneWord = *(uint*)right;
        instance = reinterpret_cast<USkeletalMeshInstance*>(instanceWord); // Reread after the name callback.
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(boneWord),
            zeroRotation, 0, 1.0f, reinterpret_cast<float&>(timeWord));
        constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        // Reuse the same incoming word.
        FName* left = constructName((FName*)&relativePitch, nativeTextR6LClavicle, 1);
        timeWord = reinterpret_cast<uint&>(blendTime);
        boneWord = *(uint*)left;
        instance = reinterpret_cast<USkeletalMeshInstance*>(instanceWord);
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(boneWord),
            zeroRotation, 0, 1.0f, reinterpret_cast<float&>(timeWord));
        finish();
        return;
    }
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    auto wrappingAbsolute = [](int value) {
        uint sign = (uint)(value >> 31);
        return (int)(((uint)value ^ sign) - sign); // INT_MIN stays negative, as in native CDQ/XOR/SUB.
    };
    uint* proneFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    byte gripType = weapon->m_eGripType; // +0x395; all out-of-range bytes return through the common guard exit.
    switch (gripType) {
    case 8: {
        uint& pitchWord = reinterpret_cast<uint&>(relativePitch);
        uint& fractionWord = reinterpret_cast<uint&>(fraction);
        uint& timeSlot = reinterpret_cast<uint&>(blendTime);
        uint originalPitch = pitchWord;
        bool positivePitch = (int)originalPitch > 0;
        bool prone = (*proneFlagWord & 0x200U) != 0; // Captured before either name callback.
        if (positivePitch && prone) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x58.
            FName* right = constructName((FName*)&frame.words[14], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat1EPlus03;
            pitchWord = (uint)right; // Incoming EBP+8 becomes the returned-name pointer cache.
            int pitch = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus6EPlus03;
            uint timeWord = timeSlot;
            int roll = truncateLowWord(product);
            right = (FName*)pitchWord;
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, 0, roll, reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x78.
            FName* left = constructName((FName*)&frame.words[6], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat6Point5EPlus03;
            timeSlot = (uint)left; // EBP+0x10 changes role; the original time remains in native EBX.
            roll = truncateLowWord(product);
            left = (FName*)timeSlot;
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, 0, pitch, roll, reinterpret_cast<float&>(timeWord));
        } else if (positivePitch) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x28.
            FName* right = constructName((FName*)&frame.words[26], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus4Point5EPlus03;
            uint timeWord = timeSlot; // Captured after multiplication, retained for both bone calls.
            int roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2Point8EPlus03;
            int pitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, 0, roll, reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x60.
            FName* left = constructName((FName*)&frame.words[12], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5EPlus02;
            roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat6EPlus03;
            int yaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5Point5EPlus03;
            pitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        } else if (prone) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x30.
            FName* right = constructName((FName*)&frame.words[24], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat9EPlus03;
            uint timeWord = timeSlot;
            int roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2EPlus03;
            int pitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, 0, roll, reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x88.
            FName* left = constructName((FName*)&frame.words[2], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus8EPlus03;
            roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat4EPlus03;
            int yaw = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, 0, yaw, roll, reinterpret_cast<float&>(timeWord));
        } else {
            // Signed comparison keeps INT_MIN on the near path.
            int absolutePitch = wrappingAbsolute((int)originalPitch);
            if (absolutePitch <= 0x1000) {
                fractionWord = 0U - originalPitch;
                float10 scaledPitch = (int)fractionWord;
                scaledPitch *= nativeFloat0Point00024414062;
                reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
                NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                // EBP-0x38.
                FName* right = constructName((FName*)&frame.words[22], nativeTextR6RClavicle,
                    1);
                float10 product = reinterpret_cast<float&>(fractionWord);
                pitchWord = (uint)right;
                product *= nativeFloat4EPlus03;
                int roll = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloatMinus1EPlus03;
                int yaw = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloatMinus2EPlus03;
                int pitch = truncateLowWord(product);
                uint timeWord = timeSlot;
                right = (FName*)pitchWord;
                fractionWord = (uint)pitch; // Fraction storage becomes the converted integer used by the second packet.
                uint boneWord = *(uint*)right;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                    reinterpret_cast<float&>(timeWord));
                constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                // EBP-0x68.
                FName* left = constructName((FName*)&frame.words[10], nativeTextR6LClavicle, 1);
                timeWord = timeSlot;
                int leftRoll = (int)fractionWord;
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, roll, yaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            } else {
                bool middleSegment = absolutePitch <= 0x2000;
                // Cached for either deeper segment.
                NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
                if (middleSegment) {
                    fractionWord = 0xfffff000U - originalPitch;
                    float10 scaledPitch = (int)fractionWord;
                    scaledPitch *= nativeFloat0Point00024414062;
                    reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
                    // EBP-0x40.
                    FName* right = constructName((FName*)&frame.words[20],
                        nativeTextR6RClavicle, 1);
                    float10 product = reinterpret_cast<float&>(fractionWord);
                    product += nativeFloatOne;
                    uint timeWord = timeSlot;
                    product *= nativeFloat4EPlus03;
                    int roll = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat3EPlus03;
                    product = (float10)nativeFloatMinus1EPlus03 - product;
                    int yaw = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat2Point5EPlus03;
                    product = (float10)nativeFloatMinus2EPlus03 - product;
                    int pitch = truncateLowWord(product);
                    uint boneWord = *(uint*)right;
                    this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                        reinterpret_cast<float&>(timeWord));
                    // EBP-0x80.
                    FName* left = constructName((FName*)&frame.words[4], nativeTextR6LClavicle,
                        1);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat5Point5EPlus03;
                    timeWord = timeSlot;
                    product = (float10)nativeFloatMinus2EPlus03 - product;
                    roll = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat8EPlus02;
                    product = (float10)nativeFloatMinus1EPlus03 - product;
                    yaw = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat2EPlus03;
                    product += nativeFloat4EPlus03;
                    pitch = truncateLowWord(product);
                    boneWord = *(uint*)left;
                    this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                        reinterpret_cast<float&>(timeWord));
                } else {
                    fractionWord = 0xffffe000U - originalPitch;
                    float10 scaledPitch = (int)fractionWord;
                    scaledPitch *= nativeFloat0Point00024414062;
                    reinterpret_cast<float&>(fractionWord) = (float)scaledPitch;
                    // EBP-0x48.
                    FName* right = constructName((FName*)&frame.words[18],
                        nativeTextR6RClavicle, 1);
                    float10 product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat4EPlus03;
                    uint timeWord = timeSlot;
                    // Native float roll-offset spill in incoming EBP+8.
                    reinterpret_cast<float&>(pitchWord) = (float)product;
                    product = reinterpret_cast<float&>(pitchWord);
                    product += nativeFloat8EPlus03;
                    int roll = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat3EPlus03;
                    product = (float10)nativeFloatMinus4EPlus03 - product;
                    int yaw = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat1Point5EPlus03;
                    product = (float10)nativeFloatMinus4Point5EPlus03 - product;
                    int pitch = truncateLowWord(product);
                    uint boneWord = *(uint*)right;
                    this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                        reinterpret_cast<float&>(timeWord));
                    // EBP-0x70.
                    FName* left = constructName((FName*)&frame.words[8], nativeTextR6LClavicle,
                        1);
                    product = nativeFloatMinus7Point5EPlus03;
                    timeWord = timeSlot;
                    // Reload the offset after both callbacks, not a cached local.
                    product -= reinterpret_cast<float&>(pitchWord);
                    roll = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat3Point7EPlus03;
                    product = (float10)nativeFloatMinus1Point8EPlus03 - product;
                    yaw = truncateLowWord(product);
                    product = reinterpret_cast<float&>(fractionWord);
                    product *= nativeFloat2EPlus03;
                    product += nativeFloat6EPlus03;
                    pitch = truncateLowWord(product);
                    boneWord = *(uint*)left;
                    this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                        reinterpret_cast<float&>(timeWord));
                }
            }
        }
        break;
    }
    case 1: {
        uint& fractionWord = reinterpret_cast<uint&>(fraction);
        // Only the original sign selects this grip's branch.
        uint originalPitch = reinterpret_cast<uint&>(relativePitch);
        if ((int)originalPitch > 0) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x50.
            FName* right = constructName((FName*)&frame.words[16], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5EPlus03;
            // Captured after the first multiplication; retained for both calls.
            uint timeWord = reinterpret_cast<uint&>(blendTime);
            int roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat1EPlus03;
            int yaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus4Point5EPlus03;
            int pitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x90.
            FName* left = constructName((FName*)&frame.words[0], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat6EPlus03;
            roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus2EPlus03;
            yaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus1EPlus03;
            pitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        } else {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x1c.
            FName* right = constructName((FName*)&frame.words[29], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat8EPlus03;
            int pitchAndYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat1EPlus04;
            uint timeWord = reinterpret_cast<uint&>(blendTime); // Native samples time after this second multiplication.
            int roll = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitchAndYaw, pitchAndYaw, roll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            // EBP-0x20.
            FName* left = constructName((FName*)&frame.words[28], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            timeWord = reinterpret_cast<uint&>(blendTime); // A fresh time word, now before the first multiplication.
            product *= nativeFloatMinus1Point2EPlus04;
            roll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat3EPlus03;
            int yaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus1EPlus03;
            int pitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, pitch, yaw, roll,
                reinterpret_cast<float&>(timeWord));
        }
        break;
    }
    case 4: {
        uint& fractionWord = reinterpret_cast<uint&>(fraction);
        uint& timeSlot = reinterpret_cast<uint&>(blendTime);
        uint originalPitch = reinterpret_cast<uint&>(relativePitch);
        if ((int)originalPitch > 0) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[27], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus6EPlus03;
            uint timeWord = timeSlot;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus4EPlus03;
            int rightPitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* left = constructName((FName*)&frame.words[25], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat8EPlus03;
            int leftRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus3EPlus03;
            int leftPitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, 0, leftRoll,
                reinterpret_cast<float&>(timeWord));
        } else {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[23], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat1Point1EPlus04;
            uint timeWord = timeSlot;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat4EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat6EPlus03;
            int rightPitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* left = constructName((FName*)&frame.words[21], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus1Point15EPlus04;
            int leftRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat5EPlus03;
            int leftYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus2EPlus03;
            int leftPitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                reinterpret_cast<float&>(timeWord));
        }
        break;
    }
    case 2:
    case 3:
    case 5:
    case 6:
    case 7: {
        uint& pitchWord = reinterpret_cast<uint&>(relativePitch);
        uint& fractionWord = reinterpret_cast<uint&>(fraction);
        uint& timeSlot = reinterpret_cast<uint&>(blendTime);
        uint originalPitch = pitchWord;
        bool positivePitch = (int)originalPitch > 0;
        bool prone = (*proneFlagWord & 0x200U) != 0;
        if (positivePitch && prone) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[19], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5EPlus03;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            uint timeWord = timeSlot;
            product *= nativeFloatMinus4EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus1EPlus03;
            int rightPitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* left = constructName((FName*)&frame.words[17], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            timeWord = timeSlot;
            product *= nativeFloat3EPlus03;
            int leftRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat4EPlus03;
            int leftYaw = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightRoll, leftYaw, leftRoll,
                reinterpret_cast<float&>(timeWord));
        } else if (prone) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[9], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat8EPlus03;
            uint timeWord = timeSlot;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat4EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus2EPlus03;
            int rightPitch = truncateLowWord(product);
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* left = constructName((FName*)&frame.words[7], nativeTextR6LClavicle, 1);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus8Point5EPlus03;
            int leftRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5EPlus03;
            int leftYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2EPlus03;
            int leftPitch = truncateLowWord(product);
            boneWord = *(uint*)left;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                reinterpret_cast<float&>(timeWord));
        } else if (positivePitch) {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[15], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus4Point5EPlus03;
            frame.word14 = (uint)right; // Native returned-name pointer cache at EBP-0x14.
            uint timeWord = timeSlot;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloatMinus5EPlus03;
            int rightPitch = truncateLowWord(product);
            right = (FName*)frame.word14;
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            int absolutePitch = wrappingAbsolute((int)originalPitch);
            if (absolutePitch <= 0x1800) {
                float10 normalized = (int)pitchWord; // FILD uses the current input word after the right-bone callback.
                normalized *= nativeFloat0Point00016276042;
                reinterpret_cast<float&>(fractionWord) = (float)normalized;
                FName* left = constructName((FName*)&frame.words[13], nativeTextR6LClavicle, 1);
                product = reinterpret_cast<float&>(fractionWord);
                timeWord = timeSlot;
                product *= nativeFloat1Point8EPlus03;
                int leftRoll = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat1Point2EPlus03;
                int leftYaw = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloatMinus2Point55EPlus03;
                int leftPitch = truncateLowWord(product);
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            } else {
                fractionWord = originalPitch - 0x1800U;
                float10 normalized = (int)fractionWord;
                normalized *= nativeFloat0Point00016276042;
                reinterpret_cast<float&>(fractionWord) = (float)normalized;
                FName* left = constructName((FName*)&frame.words[11], nativeTextR6LClavicle, 1);
                product = reinterpret_cast<float&>(fractionWord);
                timeWord = timeSlot;
                product += nativeFloatOne;
                product *= nativeFloat1Point8EPlus03;
                int leftRoll = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat8EPlus02;
                product += nativeFloat1Point2EPlus03;
                int leftYaw = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat2Point55EPlus03;
                product = (float10)nativeFloatMinus2Point55EPlus03 - product;
                int leftPitch = truncateLowWord(product);
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            }
        } else {
            NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
            FName* right = constructName((FName*)&frame.words[5], nativeTextR6RClavicle, 1);
            float10 product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat9Point5EPlus03;
            pitchWord = (uint)right; // Incoming pitch becomes the name-pointer cache; originalPitch stays separate.
            uint timeWord = timeSlot;
            int rightRoll = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat2Point5EPlus03;
            int rightYaw = truncateLowWord(product);
            product = reinterpret_cast<float&>(fractionWord);
            product *= nativeFloat6EPlus03;
            int rightPitch = truncateLowWord(product);
            right = (FName*)pitchWord;
            uint boneWord = *(uint*)right;
            this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, rightPitch, rightYaw, rightRoll,
                reinterpret_cast<float&>(timeWord));
            int absolutePitch = wrappingAbsolute((int)originalPitch);
            if (absolutePitch <= 0x1800) {
                fractionWord = 0U - originalPitch;
                float10 normalized = (int)fractionWord;
                normalized *= nativeFloat0Point00016276042;
                reinterpret_cast<float&>(fractionWord) = (float)normalized;
                FName* left = constructName((FName*)&frame.words[3], nativeTextR6LClavicle, 1);
                product = reinterpret_cast<float&>(fractionWord);
                timeWord = timeSlot;
                product *= nativeFloatMinus5Point5EPlus03;
                int leftRoll = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloatMinus3Point2EPlus03;
                int leftYaw = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloatMinus1Point5EPlus03;
                int leftPitch = truncateLowWord(product);
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            } else {
                fractionWord = 0xffffe800U - originalPitch;
                float10 normalized = (int)fractionWord;
                normalized *= nativeFloat0Point00016276042;
                reinterpret_cast<float&>(fractionWord) = (float)normalized;
                FName* left = constructName((FName*)&frame.words[1], nativeTextR6LClavicle, 1);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat3Point5EPlus03;
                timeWord = timeSlot;
                product = (float10)nativeFloatMinus5Point5EPlus03 - product;
                int leftRoll = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat3Point3EPlus03;
                product = (float10)nativeFloatMinus3Point2EPlus03 - product;
                int leftYaw = truncateLowWord(product);
                product = reinterpret_cast<float&>(fractionWord);
                product *= nativeFloat1Point5EPlus03;
                product = (float10)nativeFloatMinus1Point5EPlus03 - product;
                int leftPitch = truncateLowWord(product);
                boneWord = *(uint*)left;
                this->AR6Pawn::PawnSetBoneRotation(*(FName*)&boneWord, leftPitch, leftYaw, leftRoll,
                    reinterpret_cast<float&>(timeWord));
            }
        }
        break;
    }
    }
    finish(); // Includes absent/invalid grip values; native returns void with RET 0xc.
}

// R6Engine.dll @ 10023fe0 : WeaponLockCatchPointer
// Rethrows the caught word through separate storage in the inherited weapon-lock frame.
__declspec(naked) void WeaponLockCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x94]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10023ff7 : WeaponLockCatchContext
// Reports the weapon-lock context before forwarding the active exception.
__declspec(naked) void WeaponLockCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnWeaponLock
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044510 : WeaponLockExceptionHandler
// Passes the weapon-lock frame's FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void WeaponLockExceptionHandler(void)
{
    __asm {
        mov eax,offset weaponLockFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10024040 : GetRotValueCenteredAroundZero
// Adjusts a rotation value by one turn when it lies outside the inclusive centered interval.
int __thiscall AR6Pawn::GetRotValueCenteredAroundZero(int rotationValue)
{
    if (rotationValue > 32768)
        return (int)((uint)rotationValue - 65536U);
    if (rotationValue < -32768)
        return (int)((uint)rotationValue + 65536U);
    return rotationValue;
}

// R6Engine.dll @ 10024070 : AR6Pawn::execR6GetViewRotation
// Consumes optional DebugInfo, then copies the current virtual view rotation through its returned pointer.
void __thiscall AR6Pawn::execR6GetViewRotation(FFrame& stack, void* result)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        uint rotationWords[3]; // EBP-0x24/-0x20/-0x1c; hidden output, not necessarily the returned pointer.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execR6GetViewRotationExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    bool debugInfo = *code == 0x42;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (debugInfo) {
        UObject* expressionReceiver = stack.Object;
        *codeCursor = code + 1;
        using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
        ScriptNative* nativeTable = *(ScriptNative**)&CoreGNativesImport;
        nativeTable[0x42](expressionReceiver, &stack, nullptr);
    }
    const uint* returnedWords = (const uint*)this->GetViewRotation((FRotator*)frame.rotationWords);
    uint pitchWord = returnedWords[0]; // Native reads this before loading the incoming output pointer.
    uint* resultWords = (uint*)result;
    resultWords[0] = pitchWord;
    resultWords[1] = returnedWords[1];
    resultWords[2] = returnedWords[2];
    ExceptionList = frame.previousExceptionList; // Sequential raw copies retain overlap effects; native RET 8.
}

// R6Engine.dll @ 100240f2 : ViewRotationBridgeCatchPointer
// Rethrows the caught word through separate storage in the inherited view-rotation bridge frame.
__declspec(naked) void ViewRotationBridgeCatchPointer(void)
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

// R6Engine.dll @ 10024106 : ViewRotationBridgeCatchContext
// Reports the view-rotation bridge context and rethrows the active exception.
__declspec(naked) void ViewRotationBridgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecR6GetViewRotation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044520 : execR6GetViewRotationExceptionHandler
// Passes the view-rotation bridge FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void execR6GetViewRotationExceptionHandler(void)
{
    __asm {
        mov eax,offset viewRotationBridgeFuncInfo
        jmp __CxxFrameHandler
    }
}

// Copies the player's offset, or interpolates wrapping component differences using the retained x87 transition factor.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
// R6Engine.dll @ 10024130 : AR6Pawn::GetRotationOffset (hidden FRotator result)
FRotator* __thiscall AR6Pawn::GetRotationOffset(FRotator* result)
{
    byte* pawnBytes = (byte*)this;
    const uint* currentOffset = (const uint*)(pawnBytes + 0x5f0); // m_rRotationOffset.
    if ((pawnBytes[0x3e8] & 0x10U) != 0) { // m_bIsPlayer; only the low byte is read.
        uint* resultWords = (uint*)result;
        resultWords[0] = currentOffset[0];
        resultWords[1] = currentOffset[1];
        resultWords[2] = currentOffset[2];
        return (FRotator*)resultWords;
    }
    const uint* previousOffset = (const uint*)(pawnBytes + 0x8a8); // m_rPrevRotationOffset.
    uint previousPitch = previousOffset[0];
    const float* transitionFactor = (const float*)(pawnBytes + 0x118); // m_fBoneRotationTransition.
    float10 factor = (float10)*transitionFactor; // Live x87 value, retained below each component product.
    uint currentPitch = currentOffset[0];
    uint currentRoll = currentOffset[2];
    int pitchDelta = (int)(currentPitch - previousPitch);
    uint currentYaw = currentOffset[1];
    int pitchDifference = pitchDelta; // Native scratch at entry ESP-0x0c.
    float10 pitchProduct = (float10)pitchDifference;
    uint previousYaw = previousOffset[1];
    pitchProduct *= factor;
    uint previousRoll = previousOffset[2];
    int yawDifference = (int)(currentYaw - previousYaw); // Entry ESP-0x08.
    int rollDifference = (int)(currentRoll - previousRoll); // Entry ESP-0x04.
    // These casts denote the native compiler's ST0 -> EDX:EAX helper at10042934, including its correction/faults.
    // No stack operands or binary32/64 product spills are introduced; only the low returned words contribute.
    uint pitchStep = (uint)(longlong)pitchProduct;
    float10 yawProduct = (float10)yawDifference;
    yawProduct *= factor;
    uint yawStep = (uint)(longlong)yawProduct;
    float10 rollProduct = (float10)rollDifference;
    rollProduct *= factor;
    uint rollStep = (uint)(longlong)rollProduct;
    uint baseRoll = previousOffset[2];
    uint baseYaw = previousOffset[1];
    uint basePitch = previousOffset[0];
    uint roll = baseRoll + rollStep;
    uint* resultWords = (uint*)result; // Incoming hidden pointer is read after the base-component reloads.
    uint yaw = baseYaw + yawStep;
    uint pitch = basePitch + pitchStep;
    resultWords[0] = pitch;
    resultWords[1] = yaw;
    resultWords[2] = roll;
    return (FRotator*)resultWords;
}

// R6Engine.dll @ 10024200 : AR6Pawn::execGetRotationOffset
// Consumes optional DebugInfo, then copies the rotation offset through its returned pointer.
void __thiscall AR6Pawn::execGetRotationOffset(FFrame& stack, void* result)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        uint rotationWords[3]; // EBP-0x24/-0x20/-0x1c; hidden output, not necessarily the returned pointer.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execGetRotationOffsetExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    bool debugInfo = *code == 0x42;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (debugInfo) {
        UObject* expressionReceiver = stack.Object;
        *codeCursor = code + 1;
        using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
        ScriptNative* nativeTable = *(ScriptNative**)&CoreGNativesImport;
        nativeTable[0x42](expressionReceiver, &stack, nullptr);
    }
    const uint* returnedWords = (const uint*)this->AR6Pawn::GetRotationOffset((FRotator*)frame.rotationWords);
    uint pitchWord = returnedWords[0]; // Native reads this before loading the incoming output pointer.
    uint* resultWords = (uint*)result;
    resultWords[0] = pitchWord;
    resultWords[1] = returnedWords[1];
    uint rollWord = returnedWords[2];
    void* previousExceptionList = frame.previousExceptionList; // Captured before the final output store.
    resultWords[2] = rollWord;
    ExceptionList = previousExceptionList; // Sequential raw copies retain overlap effects; native RET 8.
}

// R6Engine.dll @ 1002427f : RotationOffsetBridgeCatchPointer
// Rethrows the caught word through separate storage in the inherited rotation-offset bridge frame.
__declspec(naked) void RotationOffsetBridgeCatchPointer(void)
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

// R6Engine.dll @ 10024293 : RotationOffsetBridgeCatchContext
// Reports the rotation-offset bridge context and rethrows the active exception.
__declspec(naked) void RotationOffsetBridgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetRotationOffset
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044530 : execGetRotationOffsetExceptionHandler
// Passes the rotation-offset bridge FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void execGetRotationOffsetExceptionHandler(void)
{
    __asm {
        mov eax,offset rotationOffsetBridgeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100242b0 : AR6Pawn::GetAnimState
// Selects a compact sound-animation state in native health, posture, landing and movement priority order.
uchar __thiscall AR6Pawn::GetAnimState(void)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        byte unused14[3];
        byte health; // EBP-0x11, only this byte of the local word is stored.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &GetAnimStateExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte entryHealth = (byte)this->m_eHealth;
    bool healthAtLeastTwo = entryHealth >= 2;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.health = entryHealth;
    auto finish = [&](uchar state) { ExceptionList = frame.previousExceptionList; return state; };
    // Local views retain the native constant-before-component reads and lazy ordered comparisons.
    auto componentIsZero = [](const float* component) {
        float10 zero = nativeFloatZero;
        float10 value = *component;
        return value == zero;
    };
    auto stationary = [&]() {
        return componentIsZero(&this->Velocity.X) && componentIsZero(&this->Velocity.Y) &&
            componentIsZero(&this->Velocity.Z);
    };
    if (healthAtLeastTwo)
        return finish(14);
    uint* postureFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    uint soundFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8);
    if ((soundFlags & 2U) != 0) { // m_bSoundChangePosture.
        uint postureFlags = *postureFlagWord;
        return finish((postureFlags & 0x100U) != 0 ? 4 : 5); // m_bWantsToProne.
    }
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e4) & 0x20000000U) != 0) // m_bIsLanding.
        return finish(13);
    if (stationary())
        return finish(3);
    uint movementFlags = *postureFlagWord;
    if ((movementFlags & 0x200U) != 0) { // m_bIsProne.
        int direction = (int)this->AR6Pawn::GetMovementDirection();
        return finish(direction == 2 ? 7 : 6);
    }
    if ((reinterpret_cast<byte*>(this)[0x6c4] & 1U) != 0) { // m_bIsClimbingStairs.
        float10 y = this->Velocity.Y;
        float10 zero = nativeFloatZero;
        return finish(y > zero ? 8 : 9); // Zero, negative and unordered select 9.
    }
    // Native repeats these ordered comparisons; retain their fresh field reads.
    if (stationary())
        return finish(0);
    if ((movementFlags & 4U) == 0) // bIsWalking, from the word captured before the prone/stair branches.
        return finish(2);
    if (frame.health == 1)
        return finish((soundFlags & 0x4000U) != 0 ? 12 : 15); // Captured m_bLeftFootDown.
    return finish(1);
}

// R6Engine.dll @ 100243bd : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnSharedConstructionCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100243d1 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnSharedConstructionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnGetAnimState // L"AR6Pawn::GetAnimState".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044540 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void GetAnimStateExceptionHandler(void)
{
    __asm {
        mov eax,offset GetAnimStateFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100244e0 : AR6Pawn::GetSoundGunType
// Selects the indoor/outdoor bit from the lower pair for nonzero input, otherwise the upper pair.
uchar __thiscall AR6Pawn::GetSoundGunType(int useLowPair)
{
    int selector = useLowPair; // Capture the full input DWORD before the Zone pointer read.
    AZoneInfo* zone = this->Region.Zone; // +0x228; native has no null guard.
    bool lowerPair = selector != 0; // Tested before reading the flag byte.
    byte zoneFlags = reinterpret_cast<const byte*>(zone)[0x398];
    if (lowerPair)
        return (zoneFlags >> 4) & 1U; // m_bInDoor.
    return ((zoneFlags & 0x10U) | 0x20U) >> 4; // Native masks/ORs before shifting; only AL is returned.
}

// R6Engine.dll @ 10024590 : AR6Pawn::initCrawlMode
// Updates collision-box activation and ledge flags, resets the box when leaving crawl, and refreshes rotation limits.
void __thiscall AR6Pawn::initCrawlMode(bool enableCrawl)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &initCrawlModeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    // Raw native argument byte; other incoming bytes are not read.
    byte modeByte = reinterpret_cast<const byte&>(enableCrawl);
    AR6ColBox* initialBox = this->m_collisionBox;
    bool hasBox = initialBox != nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (hasBox) {
        if (modeByte != 0 && ((byte)this->m_ePeekingMode != 0 ||
            // m_bPeekingReturnToCenter.
            (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0x2000000U) != 0 ||
            (reinterpret_cast<byte*>(initialBox)[0x394] & 1U) != 0)) { // m_bActive.
            initialBox->AR6ColBox::EnableCollision(0, 0, 0);
        }
        uint mode = modeByte;
        // Reload without a new null check.
        this->m_collisionBox->AR6ColBox::EnableCollision(mode, mode, mode);
    }
    uint* movementFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    uint movementFlags = *movementFlagWord; // Read after both possible collision callbacks.
    movementFlags &= ~0x08100000U;
    movementFlags |= ((uint)modeByte & 1U) << 20; // bAvoidLedges uses the low bit, not nonzero normalization.
    movementFlags |= (uint)(modeByte == 0) << 27; // bCanWalkOffLedges.
    *movementFlagWord = movementFlags;
    if (modeByte == 0)
        this->AR6Pawn::ResetColBox();
    int rotationLimit = this->AR6Pawn::getMaxRotationOffset((int)modeByte);
    void* restoreChain = frame.previousExceptionList; // Native loads this before the output-field store.
    this->m_iMaxRotationOffset = rotationLimit;
    ExceptionList = restoreChain;
}

// R6Engine.dll @ 10024662 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawninitCrawlModeCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10024676 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawninitCrawlModeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnInitCrawlMode // L"AR6Pawn::initCrawlMode".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044550 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void initCrawlModeExceptionHandler(void)
{
    __asm {
        mov eax,offset initCrawlModeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100246a0 : AR6Pawn::Crawl
// Tests the prone collision profile, enters crawl on acceptance, or restores dimensions and requests crouching.
void __thiscall AR6Pawn::Crawl(int unused)
{
    struct NativeFrameView { // Inferred inherited EBP storage; vector buffers overlap across phases.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xdc/-0xd8/-0xd4.
        uint coordinates[12]; // EBP-0xd0.
        uint update[3]; // EBP-0xa0; output is uninitialized and never read by this caller.
        uint caught; // EBP-0x94.
        uint end[3], boxLocation[3]; // EBP-0x90/-0x84.
        uint previousHeight, previousRadius, rethrow; // EBP-0x78/-0x74/-0x70.
        NativeCheckResult32 hit; // EBP-0x6c; Time at -0x48, reused by the final MoveActor.
        uint start[3]; // EBP-0x3c.
        int accepted; // EBP-0x30, reloaded after the final UpdateColBox callback.
        uint extentOrOutput[3]; // EBP-0x2c: trace extent, expected XY, then transformed output.
        float stepOrDrop; // EBP-0x20: step spill, then collision-height drop.
        uint vector[3]; // EBP-0x1c: size, movement delta, pivot and zero/up vectors.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &CrawlExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    float10 proneHeight = this->m_fProneHeight;
    float10 currentHeight = this->CollisionHeight;
    bool sameHeight = currentHeight == proneHeight;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0; // Height comparison precedes activation; the incoming integer is never read.
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (sameHeight) {
        float10 proneRadius = this->m_fProneRadius;
        if ((float10)this->CollisionRadius == proneRadius) {
            finish();
            return;
        }
    }
    float10 extentHeight = this->m_fProneHeight;
    uint radiusWord = reinterpret_cast<uint&>(this->m_fProneRadius);
    float10 extentRadius = this->m_fProneRadius;
    ((FVector*)frame.vector)->Y = (float)extentRadius;
    frame.extentOrOutput[0] = radiusWord;
    AR6ColBox* box = this->m_collisionBox;
    bool hasBox = box != nullptr;
    ((FVector*)frame.vector)->Z = (float)extentHeight;
    extentRadius = this->m_fProneRadius;
    frame.hit.nextAddress = 0;
    ((FVector*)frame.extentOrOutput)->Y = (float)extentRadius;
    for (int i = 1; i < 9; ++i)
        reinterpret_cast<uint*>(&frame.hit)[i] = 0;
    reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffff;
    frame.hit.materialAddress = 0;
    frame.vector[0] = radiusWord;
    frame.extentOrOutput[2] = 0x3f800000;
    if (!hasBox || box->Owner == nullptr) {
        finish(); // These exits do not reset crawl mode or request crouching.
        return;
    }
    uint* movementFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    auto reject = [&]() {
        uint flags = *movementFlagWord;
        AController* controller = this->Controller; // Captured before the flag store; neither controller is checked.
        *movementFlagWord = (flags & ~0x100U) | 0x10U;
        controller->bDuck = 1;
        controller = this->Controller;
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0x3a8) &= ~0x400U;
        this->AR6Pawn::initCrawlMode(false);
        finish();
    };
    using FarMove = int (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
    using ToLocal = FCoords* (__thiscall*)(const AActor*, FCoords*);
    // Physical output-pointer view: UpdateColBox later reuses its incoming word.
    using UpdateColBox = void (__thiscall*)(AR6Pawn*, FVector*, int, int, int);
    float10 boxOffsetLive = this->m_fProneRadius;
    boxOffsetLive += boxOffsetLive;
    float boxOffset = (float)boxOffsetLive;
    box->AR6ColBox::GetColBoxLocationFromOwner(*reinterpret_cast<FVector*>(frame.boxLocation), boxOffset);
    float10 heightDifference = (float10)this->CollisionHeight - this->m_fProneHeight;
    uint boxY = frame.boxLocation[1];
    uint boxX = frame.boxLocation[0];
    float10 startZ = (float10)((FVector*)frame.boxLocation)->Z - heightDifference;
    frame.start[1] = boxY;
    box = this->m_collisionBox;
    ((FVector*)frame.boxLocation)->Z = (float)startZ;
    uint boxZ = frame.boxLocation[2];
    frame.start[0] = boxX;
    frame.start[2] = boxZ;
    using GetStepUp = float10 (__thiscall*)(AR6ColBox*, bool, float);
    float10 stepUp = reinterpret_cast<GetStepUp&>(AR6ColBoxGetMaxStepUpImport)(box, true, 0.0f);
    frame.stepOrDrop = (float)stepUp; // FST preserves the live ST0 used by the following addition.
    float10 steppedZ = stepUp + ((FVector*)frame.start)->Z;
    frame.end[0] = frame.start[0];
    AR6EngineWeapon* weapon = this->EngineWeapon;
    ((FVector*)frame.start)->Z = (float)steppedZ;
    float10 doubledHeight = this->m_fProneHeight;
    doubledHeight += doubledHeight;
    float10 downTrace = (float10)nativeFloatMinus8EPlus01 - doubledHeight;
    downTrace += ((FVector*)frame.start)->Z;
    ((FVector*)frame.end)->Y = (float)(float10)((FVector*)frame.start)->Y;
    ((FVector*)frame.end)->Z = (float)downTrace;
    if (weapon != nullptr && (reinterpret_cast<byte*>(weapon)[0x3a0] & 2U) != 0) {
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        auto componentMatches = [](const float* constant, const float* component) {
            float10 expected = *constant; // Native loads the retained zero vector before each component.
            float10 actual = *component;
            return actual == expected;
        };
        if (!componentMatches(&zero->X, &this->Velocity.X) || !componentMatches(&zero->Y, &this->Velocity.Y) ||
            !componentMatches(&zero->Z, &this->Velocity.Z) || !componentMatches(&zero->X, &this->Acceleration.X) ||
            !componentMatches(&zero->Y, &this->Acceleration.Y) || !componentMatches(&zero->Z, &this->Acceleration.Z)) {
            reject(); // Every comparison must be ordered equal; unordered counts as moving.
            return;
        }
    }
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0xc00000U) != 0 ||
        (byte)this->m_ePlayerIsUsingHands == 3) {
        reject(); // Reloading/changing weapon, or native hands selector 3.
        return;
    }
    uint extentX = frame.extentOrOutput[0];
    ULevel* level = this->XLevel;
    byte* levelVtable = *(byte**)level;
    uint traceExtentWords[3] = {extentX, frame.extentOrOutput[1], frame.extentOrOutput[2]};
    using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    (*(LineCheck*)(levelVtable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&frame.hit), this,
        (FVector*)frame.end, (FVector*)frame.start, 0x2000df, *(FVector*)traceExtentWords); // Ignore the return.
    if (frame.hit.actorAddress == 0) {
        reject();
        return;
    }
    float10 zeroTime = nativeFloatZero;
    float10 hitTime = frame.hit.Time;
    if (hitTime == zeroTime) {
        reject(); // Unordered time is accepted by this gate.
        return;
    }
    FVector* floorLocation = reinterpret_cast<FVector*>(&frame.hit.Location);
    float10 floorZ = floorLocation->Z;
    uint sizeX = frame.vector[0];
    floorZ += this->m_fProneHeight;
    uint expectedX = reinterpret_cast<uint&>(frame.hit.Location.X);
    uint expectedY = reinterpret_cast<uint&>(frame.hit.Location.Y);
    floorLocation->Z = (float)floorZ;
    frame.extentOrOutput[2] = reinterpret_cast<uint&>(frame.hit.Location.Z);
    uint sizeY = frame.vector[1];
    frame.extentOrOutput[0] = expectedX;
    level = this->XLevel;
    uint sizeZ = frame.vector[2];
    frame.extentOrOutput[1] = expectedY;
    levelVtable = *(byte**)level;
    uint sizeWords[3] = {sizeX, sizeY, sizeZ};
    using FindSpot = int (__thiscall*)(ULevel*, FVector, FVector*, int, AActor*);
    int found = (*(FindSpot*)(levelVtable + 0xb8))(level, *(FVector*)sizeWords, floorLocation, 1, this);
    auto hitCoordinateMatches = [](const float* actual, const float* saved) {
        float10 current = *actual;
        float10 expected = *saved;
        return expected == current;
    };
    if (found == 0 || !hitCoordinateMatches(&floorLocation->X, &((FVector*)frame.extentOrOutput)->X) ||
        !hitCoordinateMatches(&floorLocation->Y, &((FVector*)frame.extentOrOutput)->Y)) {
        reject(); // Expected XY are frame reads after the callback; updated Z is unrestricted.
        return;
    }
    uint oldRadius = reinterpret_cast<uint&>(this->CollisionRadius);
    float10 oldHeightLive = this->CollisionHeight;
    uint newHeightWord = reinterpret_cast<uint&>(this->m_fProneHeight);
    float10 drop = oldHeightLive - this->m_fProneHeight;
    uint oldHeight = reinterpret_cast<uint&>(this->CollisionHeight);
    frame.previousRadius = oldRadius;
    uint newRadiusWord = reinterpret_cast<uint&>(this->m_fProneRadius);
    frame.stepOrDrop = (float)drop;
    frame.previousHeight = oldHeight;
    this->AActor::SetCollisionSize(reinterpret_cast<float&>(newRadiusWord), reinterpret_cast<float&>(newHeightWord));
    auto rollback = [&]() {
        uint x = reinterpret_cast<uint&>(this->Location.X);
        float10 raisedZ = (float10)frame.stepOrDrop + this->Location.Z;
        ULevel* currentLevel = this->XLevel;
        float10 y = this->Location.Y;
        byte* vtable = *(byte**)currentLevel;
        ((FVector*)frame.vector)->Y = (float)y;
        ((FVector*)frame.vector)->Z = (float)raisedZ;
        frame.vector[0] = x;
        FVector target = *(FVector*)frame.vector;
        (*(FarMove*)(vtable + 0x9c))(currentLevel, this, target, 0, 0, 0, 0);
        uint height = frame.previousHeight;
        uint radius = frame.previousRadius;
        this->AActor::SetCollisionSize(reinterpret_cast<float&>(radius), reinterpret_cast<float&>(height));
        // Raises CURRENT location even when the lowering move failed; no box move-back.
        this->AR6Pawn::initCrawlMode(false);
    };
    float10 lowerZ = this->Location.Z;
    uint lowerX = reinterpret_cast<uint&>(this->Location.X);
    lowerZ -= frame.stepOrDrop;
    float10 lowerY = this->Location.Y;
    level = this->XLevel;
    levelVtable = *(byte**)level;
    ((FVector*)frame.vector)->Y = (float)lowerY;
    ((FVector*)frame.vector)->Z = (float)lowerZ;
    frame.vector[0] = lowerX;
    FVector target = *(FVector*)frame.vector;
    int accepted = (*(FarMove*)(levelVtable + 0x9c))(level, this, target, 0, 0, 0, 0);
    if (accepted == 0) {
        rollback();
        reject();
        return;
    }
    this->AR6Pawn::initCrawlMode(true);
    uint floorX = reinterpret_cast<uint&>(frame.hit.Location.X);
    level = this->XLevel;
    levelVtable = *(byte**)level;
    uint floorTargetWords[3] = {floorX, reinterpret_cast<uint&>(frame.hit.Location.Y),
        reinterpret_cast<uint&>(frame.hit.Location.Z)};
    box = this->m_collisionBox;
    accepted = (*(FarMove*)(levelVtable + 0x9c))(level, box, *(FVector*)floorTargetWords, 0, 0, 1, 1);
    frame.accepted = accepted;
    if (accepted != 0) {
        box = this->m_collisionBox;
        float10 deltaZ = (float10)box->Location.Z - this->Location.Z;
        float10 deltaY = (float10)box->Location.Y - this->Location.Y;
        float10 deltaX = box->Location.X;
        byte* pawnVtable = *(byte**)this;
        deltaX -= this->Location.X;
        ((FVector*)frame.vector)->X = (float)deltaX;
        ((FVector*)frame.vector)->Y = (float)deltaY;
        ((FVector*)frame.vector)->Z = (float)deltaZ;
        FCoords* local = (*(ToLocal*)(pawnVtable + 0xa4))(this, (FCoords*)frame.coordinates);
        const FVector* output = &(*reinterpret_cast<FVector*>(frame.extentOrOutput) =
            reinterpret_cast<const FVector*>(frame.vector)->TransformVectorBy(*local));
        uint* relative = reinterpret_cast<uint*>(&this->m_collisionBox->RelativeLocation);
        relative[0] = reinterpret_cast<const uint&>(output->X);
        relative[1] = reinterpret_cast<const uint&>(output->Y);
        relative[2] = reinterpret_cast<const uint&>(output->Z);
        pawnVtable = *(byte**)this;
        (*reinterpret_cast<UpdateColBox*>(pawnVtable + 0xb4))(this, (FVector*)frame.update, 0, 0, 1);
        frame.vector[0] = 0;
        uint x = frame.vector[0];
        frame.vector[1] = 0;
        uint y = frame.vector[1];
        frame.vector[2] = 0;
        uint z = frame.vector[2];
        box = this->m_collisionBox;
        uint zeroWords[3] = {x, y, z};
        accepted = box->AR6ColBox::CanStepUp(*(FVector*)zeroWords);
        frame.accepted = accepted;
        if (accepted != 0) {
            pawnVtable = *(byte**)this;
            frame.vector[0] = 0;
            x = frame.vector[0];
            frame.vector[1] = 0;
            y = frame.vector[1];
            frame.vector[2] = 0x3f800000;
            z = frame.vector[2];
            box = this->m_collisionBox;
            uint upWords[3] = {x, y, z};
            using IsOverLedge = int (__thiscall*)(AR6Pawn*, AActor*, FVector, float);
            int overLedge = (*(IsOverLedge*)(pawnVtable + 0x1ac))(this, box, *(FVector*)upWords, 1.0f);
            accepted = overLedge == 0;
            frame.accepted = accepted;
        }
    }
    if (accepted == 0) {
        this->AR6Pawn::initCrawlMode(false); // Native resets here, again in rollback, then again in rejection.
        rollback();
        reject();
        return;
    }
    UClass* currentClass = this->Class;
    APawn* defaults = static_cast<APawn*>(currentClass->GetDefaultObject());
    float10 pivotZ = (float10)defaults->CollisionHeight - this->m_fProneHeight;
    byte* pawnVtable = *(byte**)this;
    frame.vector[0] = 0;
    uint pivotX = frame.vector[0];
    pivotZ += this->m_fPrePivotPawnInitialOffset;
    frame.vector[1] = 0;
    ((FVector*)frame.vector)->Z = (float)pivotZ;
    uint pivotY = frame.vector[1];
    uint pivotZWord = frame.vector[2];
    uint pivotWords[3] = {pivotX, pivotY, pivotZWord};
    using SetPrePivot = void (__thiscall*)(AR6Pawn*, FVector);
    (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)pivotWords);
    *movementFlagWord &= ~0x10U;
    this->AR6Pawn::eventStartCrawl();
    uint backupX = reinterpret_cast<uint&>(this->PrePivot.X);
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.X) = backupX;
    uint backupY = reinterpret_cast<uint&>(this->PrePivot.Y);
    uint backupZ = reinterpret_cast<uint&>(this->PrePivot.Z);
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.Y) = backupY;
    pawnVtable = *(byte**)this;
    reinterpret_cast<uint&>(this->m_vPrePivotProneBackup.Z) = backupZ;
    (*reinterpret_cast<UpdateColBox*>(pawnVtable + 0xb4))(this, (FVector*)frame.update, 1, 0, 0);
    uint rotationWords[3]; // By-value outgoing packet; only Roll also occupies the shared frame vector's Z word.
    rotationWords[0] = reinterpret_cast<uint&>(this->Rotation.Pitch);
    uint yaw = reinterpret_cast<uint&>(this->Rotation.Yaw);
    uint roll = reinterpret_cast<uint&>(this->Rotation.Roll);
    rotationWords[1] = yaw + 1U;
    const uint* zero = *(const uint**)&FVectorFVector0Import;
    frame.vector[2] = roll;
    rotationWords[2] = frame.vector[2];
    level = this->XLevel;
    levelVtable = *(byte**)level;
    uint movementWords[3];
    movementWords[0] = zero[0];
    movementWords[1] = zero[1];
    movementWords[2] = zero[2];
    using MoveActor = int (__thiscall*)(ULevel*, AActor*, FVector, FRotator, FCheckResult*, int, int, int, int, int);
    (*(MoveActor*)(levelVtable + 0x98))(level, this, *(FVector*)movementWords, *(FRotator*)rotationWords,
        reinterpret_cast<FCheckResult*>(&frame.hit), 0, 0, 0, 0, 0); // Reuse the hit record; ignore the result.
    box = this->m_collisionBox2;
    if (box != nullptr) {
        box->AR6ColBox::EnableCollision(1, 0, 0);
        box = this->m_collisionBox2; // Reload unchecked after activation.
        AActor* owner = box->Owner;
        if (owner != nullptr) {
            float10 deltaZ = (float10)box->Location.Z - owner->Location.Z;
            float10 deltaY = (float10)box->Location.Y - owner->Location.Y;
            float10 deltaX = (float10)box->Location.X - owner->Location.X;
            ((FVector*)frame.vector)->X = (float)deltaX;
            ((FVector*)frame.vector)->Y = (float)deltaY;
            ((FVector*)frame.vector)->Z = (float)deltaZ;
            owner = box->Owner;
            byte* ownerVtable = *(byte**)owner;
            FCoords* local = (*(ToLocal*)(ownerVtable + 0xa4))(owner, (FCoords*)frame.coordinates);
            const FVector* output = &(*reinterpret_cast<FVector*>(frame.extentOrOutput) =
                reinterpret_cast<const FVector*>(frame.vector)->TransformVectorBy(*local));
            uint* relative = reinterpret_cast<uint*>(&this->m_collisionBox2->RelativeLocation);
            relative[0] = reinterpret_cast<const uint&>(output->X);
            relative[1] = reinterpret_cast<const uint&>(output->Y);
            relative[2] = reinterpret_cast<const uint&>(output->Z);
        }
    }
    pawnVtable = *(byte**)this;
    (*reinterpret_cast<UpdateColBox*>(pawnVtable + 0xb4))(this, (FVector*)frame.update, 1, 0, 0);
    accepted = frame.accepted;
    if (accepted != 0)
        finish();
    else
        reject(); // Final callback can change the saved acceptance without a size/mode rollback.
}

// R6Engine.dll @ 10024dcf : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnCrawlCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x94]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x70]
        push edx
        mov dword ptr [ebp-0x70],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10024de6 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnCrawlCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnCrawl // L"AR6Pawn::Crawl".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044560 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void CrawlExceptionHandler(void)
{
    __asm {
        mov eax,offset CrawlFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10024e10 : AR6Pawn::UnCrawl
// Tries standing then crouched clearance, restoring dimensions/pivot after failed moves and updating posture requests.
void __thiscall AR6Pawn::UnCrawl(int moveFlag)
{
    struct NativeFrameView { // Inferred inherited EBP storage; each vector is reused across phases.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x70/-0x6c/-0x68.
        NativeCheckResult32 hit; // EBP-0x64, reused without resetting between traces; Time is at -0x40.
        uint endOrPivot[3]; // EBP-0x34: trace endpoint, saved pivot, then final crouch pivot.
        uint extentOrMove[3]; // EBP-0x28: trace extent, move destination and first pivot.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        float crouchRise; // EBP-0x14, includes a separate float spill before/after the stair adjustment.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &UnCrawlExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    UClass* initialClass = this->Class;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    for (int i = 0; i < 9; ++i)
        reinterpret_cast<uint*>(&frame.hit)[i] = 0;
    reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffff;
    frame.hit.materialAddress = 0;
    APawn* defaults = static_cast<APawn*>(initialClass->GetDefaultObject());
    using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    using FarMove = int (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
    using SetPrePivot = void (__thiscall*)(AR6Pawn*, FVector);
    const uint* inputFlag = (const uint*)&moveFlag; // Native rereads the incoming DWORD after callbacks.
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    auto clearTrace = [&]() {
        float10 one = nativeFloatOne; // Constant is loaded before the current hit time.
        float10 time = frame.hit.Time;
        return time == one; // Only ordered equality accepts; trace return and hit actor are ignored.
    };
    // Alias addresses, preserving the byte gate, live DWORD updates and two separate stair reads.
    uint* postureFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    const byte* stairFlagByte = reinterpret_cast<const byte*>(this) + 0x6c4;
    if ((*reinterpret_cast<byte*>(postureFlagWord) & 0x10U) == 0) {
        float10 heightRise = defaults->CollisionHeight;
        uint radiusWord = reinterpret_cast<uint&>(defaults->CollisionRadius);
        heightRise -= this->m_fProneHeight;
        uint endX = reinterpret_cast<uint&>(this->Location.X);
        float10 extentHeight = defaults->CollisionHeight;
        ULevel* slotLevel = this->XLevel;
        float10 extentRadius = defaults->CollisionRadius;
        ((FVector*)frame.extentOrMove)->Y = (float)extentRadius;
        frame.extentOrMove[0] = radiusWord;
        frame.endOrPivot[0] = endX;
        ((FVector*)frame.extentOrMove)->Z = (float)extentHeight;
        uint extentWords[3]; // Raw outgoing by-value packet, distinct from the frame extent.
        extentWords[0] = frame.extentOrMove[0];
        heightRise += this->Location.Z;
        float10 y = this->Location.Y;
        extentWords[1] = frame.extentOrMove[1];
        ((FVector*)frame.endOrPivot)->Y = (float)y;
        extentWords[2] = frame.extentOrMove[2];
        ((FVector*)frame.endOrPivot)->Z = (float)heightRise;
        byte* levelVtable = *(byte**)slotLevel;
        ULevel* receiver = this->XLevel; // Slot provider and receiver are sampled separately.
        (*(LineCheck*)(levelVtable + 0xcc))(receiver, reinterpret_cast<FCheckResult*>(&frame.hit), this,
            (FVector*)frame.endOrPivot, &this->Location, 0x86, *(FVector*)extentWords);
        if (clearTrace()) {
            uint heightWord = reinterpret_cast<uint&>(defaults->CollisionHeight);
            radiusWord = reinterpret_cast<uint&>(defaults->CollisionRadius);
            this->AActor::SetCollisionSize(reinterpret_cast<float&>(radiusWord), reinterpret_cast<float&>(heightWord));
            float10 moveZ = (float10)this->Location.Z + this->PrePivot.Z;
            uint flag = *inputFlag;
            float10 moveY = this->Location.Y;
            ULevel* level = this->XLevel;
            moveY += this->PrePivot.Y;
            levelVtable = *(byte**)level;
            float10 moveX = (float10)this->Location.X + this->PrePivot.X;
            uint destinationWords[3];
            ((FVector*)frame.extentOrMove)->X = (float)moveX;
            destinationWords[0] = frame.extentOrMove[0];
            ((FVector*)frame.extentOrMove)->Y = (float)moveY;
            destinationWords[1] = frame.extentOrMove[1];
            ((FVector*)frame.extentOrMove)->Z = (float)moveZ;
            destinationWords[2] = frame.extentOrMove[2];
            int moved = (*(FarMove*)(levelVtable + 0x9c))(
                level, this, *(FVector*)destinationWords, flag, 0, 0, 0);
            if (moved != 0) {
                this->AR6Pawn::initCrawlMode(false);
                float10 initialOffset = this->m_fPrePivotPawnInitialOffset;
                byte* pawnVtable = *(byte**)this;
                ((FVector*)frame.extentOrMove)->Z = (float)initialOffset;
                uint pivotWords[3];
                frame.extentOrMove[0] = 0;
                pivotWords[0] = frame.extentOrMove[0];
                frame.extentOrMove[1] = 0;
                pivotWords[1] = frame.extentOrMove[1];
                pivotWords[2] = frame.extentOrMove[2];
                (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)pivotWords);
                if (*inputFlag == 0)
                    this->AR6Pawn::eventEndCrawl(); // Wrapper retains its pre-lookup vtable.
                uint flags = *postureFlagWord;
                void* previous = frame.previousExceptionList; // Native reads this before storing the flags.
                *postureFlagWord = flags & ~0x200U;
                ExceptionList = previous; // Standing clears prone even for a nonzero current input flag.
                return;
            }
            heightWord = reinterpret_cast<uint&>(this->m_fProneHeight);
            radiusWord = reinterpret_cast<uint&>(this->m_fProneRadius);
            this->AActor::SetCollisionSize(reinterpret_cast<float&>(radiusWord), reinterpret_cast<float&>(heightWord));
        }
    }
    float10 defaultCrouchHeight = defaults->CrouchHeight;
    bool onStairs = (*stairFlagByte & 1U) != 0;
    frame.crouchRise = (float)(defaultCrouchHeight - this->m_fProneHeight);
    if (onStairs)
        frame.crouchRise = (float)((float10)frame.crouchRise - nativeDouble5);
    float10 traceRise = defaultCrouchHeight - this->CollisionHeight; // Original live height survives the rise spill.
    uint radiusWord = reinterpret_cast<uint&>(defaults->CrouchRadius);
    uint endX = reinterpret_cast<uint&>(this->Location.X);
    ULevel* level = this->XLevel;
    frame.endOrPivot[0] = endX;
    traceRise += traceRise;
    float10 extentHeight = this->CollisionHeight;
    frame.extentOrMove[0] = radiusWord;
    float10 extentRadius = defaults->CrouchRadius;
    uint extentWords[3];
    extentWords[0] = frame.extentOrMove[0];
    ((FVector*)frame.extentOrMove)->Y = (float)extentRadius;
    extentWords[1] = frame.extentOrMove[1];
    ((FVector*)frame.extentOrMove)->Z = (float)extentHeight;
    extentWords[2] = frame.extentOrMove[2];
    traceRise += this->Location.Z;
    float10 y = this->Location.Y;
    ((FVector*)frame.endOrPivot)->Y = (float)y;
    ((FVector*)frame.endOrPivot)->Z = (float)traceRise;
    byte* levelVtable = *(byte**)level;
    (*(LineCheck*)(levelVtable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&frame.hit), this,
        (FVector*)frame.endOrPivot, &this->Location, 0x86, *(FVector*)extentWords); // Reuse the hit record.
    if (clearTrace()) {
        // Current dimensions differ from the default trace dimensions.
        uint heightWord = reinterpret_cast<uint&>(this->CrouchHeight);
        radiusWord = reinterpret_cast<uint&>(this->CrouchRadius);
        this->AActor::SetCollisionSize(reinterpret_cast<float&>(radiusWord), reinterpret_cast<float&>(heightWord));
        float10 pivotZ = (float10)frame.crouchRise + this->m_fPrePivotPawnInitialOffset;
        uint previousX = reinterpret_cast<uint&>(this->PrePivot.X);
        uint previousY = reinterpret_cast<uint&>(this->PrePivot.Y);
        ((FVector*)frame.extentOrMove)->Z = (float)pivotZ;
        uint previousZ = reinterpret_cast<uint&>(this->PrePivot.Z);
        frame.endOrPivot[1] = previousY;
        frame.endOrPivot[2] = previousZ;
        uint pivotWords[3];
        frame.extentOrMove[0] = 0;
        pivotWords[0] = frame.extentOrMove[0];
        frame.extentOrMove[1] = 0;
        pivotWords[1] = frame.extentOrMove[1];
        pivotWords[2] = frame.extentOrMove[2];
        frame.endOrPivot[0] = previousX;
        byte* pawnVtable = *(byte**)this;
        (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)pivotWords);
        float10 moveZ = (float10)this->PrePivot.Z + this->Location.Z;
        uint flag = *inputFlag;
        float10 moveY = this->PrePivot.Y;
        level = this->XLevel;
        moveY += this->Location.Y;
        levelVtable = *(byte**)level;
        float10 moveX = (float10)this->Location.X + this->PrePivot.X;
        uint destinationWords[3];
        ((FVector*)frame.extentOrMove)->X = (float)moveX;
        destinationWords[0] = frame.extentOrMove[0];
        ((FVector*)frame.extentOrMove)->Y = (float)moveY;
        destinationWords[1] = frame.extentOrMove[1];
        ((FVector*)frame.extentOrMove)->Z = (float)moveZ;
        destinationWords[2] = frame.extentOrMove[2];
        int moved = (*(FarMove*)(levelVtable + 0x9c))(
            level, this, *(FVector*)destinationWords, flag, 0, 0, 0);
        if (moved != 0) {
            this->AR6Pawn::initCrawlMode(false);
            UClass* currentClass = this->Class;
            APawn* firstDefaults = static_cast<APawn*>(currentClass->GetDefaultObject());
            APawn* secondDefaults = static_cast<APawn*>(currentClass->GetDefaultObject());
            float10 finalPivotZ = (float10)firstDefaults->CollisionHeight - secondDefaults->CrouchHeight;
            if ((*stairFlagByte & 1U) != 0)
                finalPivotZ -= nativeDouble5; // Live difference; no intermediate float spill here.
            finalPivotZ += this->m_fPrePivotPawnInitialOffset;
            pawnVtable = *(byte**)this;
            uint finalPivotWords[3];
            frame.endOrPivot[0] = 0;
            finalPivotWords[0] = frame.endOrPivot[0];
            ((FVector*)frame.endOrPivot)->Z = (float)finalPivotZ;
            frame.endOrPivot[1] = 0;
            finalPivotWords[1] = frame.endOrPivot[1];
            finalPivotWords[2] = frame.endOrPivot[2];
            (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)finalPivotWords);
            if (*inputFlag != 0) {
                finish(); // Crouched success retains posture/controller flags for nonzero current input.
                return;
            }
            *postureFlagWord = (*postureFlagWord & ~0x200U) | 0x20U;
            FName name = R6ENGINE_EndCrawl;
            UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(name), 0);
            pawnVtable = *(byte**)this; // Inline event samples the vtable after lookup.
            using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
            (*(ProcessEvent*)(pawnVtable + 0x10))(this, function, nullptr, nullptr);
            AController* controller = this->Controller;
            controller->bDuck = 1;
            controller = this->Controller;
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0x3a8) &= ~0x400U;
            finish();
            return;
        }
        heightWord = reinterpret_cast<uint&>(this->m_fProneHeight);
        radiusWord = reinterpret_cast<uint&>(this->m_fProneRadius);
        this->AActor::SetCollisionSize(reinterpret_cast<float&>(radiusWord), reinterpret_cast<float&>(heightWord));
        uint previousPivotWords[3];
        previousPivotWords[0] = frame.endOrPivot[0];
        pawnVtable = *(byte**)this;
        previousPivotWords[1] = frame.endOrPivot[1];
        previousPivotWords[2] = frame.endOrPivot[2];
        (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)previousPivotWords);
    }
    if (this->APawn::IsHumanControlled() != 0) {
        uint flags = *postureFlagWord;
        AController* controller = this->Controller;
        *postureFlagWord = (flags & ~0x10U) | 0x100U;
        controller->bDuck = 0;
        controller = this->Controller;
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0x3a8) |= 0x400U;
    }
    finish(); // No automatic dimension, pivot or movement restoration on exceptions.
}

// R6Engine.dll @ 100252ca : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnUnCrawlCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100252de : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnUnCrawlCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUnCrawl // L"AR6Pawn::UnCrawl".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044570 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void UnCrawlExceptionHandler(void)
{
    __asm {
        mov eax,offset UnCrawlFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10025300 : AR6Pawn::performPhysics
// Updates effect/noise timers, posture, physics, rotation and deferred touches while accumulating low-word cycles.
void __thiscall AR6Pawn::performPhysics(float deltaSeconds)
{
    struct NativeFrameView { // Inferred inherited EBP storage; old velocity X is retained in EBX.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        uint unused24, oldVelocityY, oldVelocityZ; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &performPhysicsExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    const uint* inputDelta = (const uint*)&deltaSeconds; // Native reloads this word or retains it in EDI.
    byte actorFlags = reinterpret_cast<byte*>(this)[0xa4];
    bool useRagdoll = (actorFlags & 0x20) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (useRagdoll) {
        uint deltaWord = *inputDelta;
        this->APawn::performPhysics(reinterpret_cast<float&>(deltaWord));
        ExceptionList = frame.previousExceptionList;
        return;
    }
    // IAT addresses the exported statistics objects directly.
    byte* engineStats = *(byte**)&EngineGEngineStatsImport;
    uint counterIndex = *(uint*)(engineStats + 0x124);
    byte* stats = *(byte**)&EngineGStatsImport;
    uint* counters = *(uint**)(stats + 0x1c);
    uint* counter = counters + counterIndex;
    uint cycleLow;
    __asm {
        rdtsc
        mov cycleLow,eax
    }
    uint counterBefore = *counter;
    *counter = counterBefore - cycleLow; // Read after RDTSC; native arithmetic wraps in the low 32 bits.
    // Both normal completion paths reload the statistics objects/index; exception paths do not balance the counter.
    auto finishStatistics = [&]() {
        byte* currentEngineStats = *(byte**)&EngineGEngineStatsImport;
        byte* currentStats = *(byte**)&EngineGStatsImport;
        uint index = *(uint*)(currentEngineStats + 0x124);
        uint* currentCounters = *(uint**)(currentStats + 0x1c);
        uint* currentCounter = currentCounters + index;
        uint endCycleLow;
        __asm {
            rdtsc
            mov endCycleLow,eax
        }
        uint count = *currentCounter;
        *currentCounter = count + endCycleLow - 0x22U;
        ExceptionList = frame.previousExceptionList;
    };
    byte grenadeEffect = this->m_eEffectiveGrenade;
    if (grenadeEffect != 0) {
        float10 remaining = (float10)this->m_fRemainingGrenadeTime - *(float*)inputDelta;
        this->m_fRemainingGrenadeTime = (float)remaining;
        if (remaining <= nativeFloatZero) { // Compare live ST0 after FST; unordered does not expire.
            uint callWord = ((uint)(uintptr_t)counter & 0xffffff00U) | grenadeEffect;
            using EndEffect = void (__thiscall*)(AR6Pawn*, uint); // Raw stack-word view of the BYTE argument.
            // MOV CL preserves the counter address's upper bytes.
            (*(EndEffect)&AR6PawnEventEndOfGrenadeEffectNativeEntry)(this, callWord);
            this->m_eEffectiveGrenade = 0;
            reinterpret_cast<uint&>(this->m_fRemainingGrenadeTime) = 0;
        }
    }
    ALevelInfo* levelInfo = this->Level;
    float10 now = levelInfo->TimeSeconds;
    float10 noiseTimer = this->m_fNoiseTimer;
    if (now > noiseTimer) {
        this->m_fNoiseTimer = (float)((float10)levelInfo->TimeSeconds + nativeFloat0Point33);
        float10 velocityZ = this->Velocity.Z;
        float10 velocityY = this->Velocity.Y;
        float10 velocityX = this->Velocity.X;
        float10 speedSquared = (velocityX * velocityX + velocityY * velocityY) + velocityZ * velocityZ;
        if (speedSquared > nativeFloat1EPlus03) {
            UFunction* function = UObject::FindFunctionChecked(this, R6ENGINE_R6MakeMovementNoise, 0);
            using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
            byte* vtable = *(byte**)this; // Reload after function lookup.
            (*(ProcessEvent*)(vtable + 0x10))(this, function, nullptr, nullptr);
        }
    }
    // Nonplayer outside zones, without bIgnoreOutOfWorld.
    if ((reinterpret_cast<byte*>(this)[0x3e8] & 0x10) == 0 && this->Region.ZoneNumber == 0 &&
        (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa8) & 0x40000000U) == 0) {
        const ushort* name = this->UObject::GetName();
        FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
        log->FOutputDevice::Logf(nativeTextSFellOutOfTheWorld, name);
        AActor::eventFellOutOfWorld(this);
        finishStatistics();
        return;
    }
    using IsCrouched = int (__thiscall*)(APawn*);
    // Retained through UnCrouch/Crawl and the second query.
    IsCrouched isCrouched = reinterpret_cast<IsCrouched&>(APawnIsCrouchedImport);
    uint oldVelocityX = reinterpret_cast<uint&>(this->Velocity.X); // Retained in EBX across callbacks.
    uint oldY = reinterpret_cast<uint&>(this->Velocity.Y);
    uint oldZ = reinterpret_cast<uint&>(this->Velocity.Z);
    frame.oldVelocityY = oldY;
    frame.oldVelocityZ = oldZ;
    int crouched = isCrouched(this);
    float10 proneHeight = this->m_fProneHeight;
    // Alias the stable packed word; every read below remains live across callbacks.
    uint* pawnFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    uint flags = *pawnFlagWord;
    float10 collisionHeight = this->CollisionHeight;
    flags = (flags & ~0x20U) | (((uint)crouched << 5) & 0x20U); // Native low result bit, not nonzero normalization.
    *pawnFlagWord = flags;
    bool prone = false;
    if (collisionHeight == proneHeight) {
        APawn* defaults = static_cast<APawn*>(this->Class->GetDefaultObject());
        prone = (float10)this->CollisionHeight < defaults->CollisionHeight; // Ordered comparison; NaN is false.
    }
    flags = *pawnFlagWord; // GetDefaultObject may have changed this word.
    flags = (flags & ~0x200U) | ((uint)prone << 9);
    byte physics = this->Physics;
    *pawnFlagWord = flags;
    if (physics == 1 || physics == 12) {
        if ((flags & 0x100) != 0) { // m_bWantsToProne takes priority over crouching.
            if ((flags & 0x200) == 0) {
                if ((flags & 0x20) != 0)
                    APawn::UnCrouch(this, 0);
                this->AR6Pawn::Crawl(0);
                crouched = isCrouched(this);
                flags = *pawnFlagWord;
                *pawnFlagWord = (flags & ~0x20U) | (((uint)crouched << 5) & 0x20U);
            } else if ((flags & 0x400) != 0) { // m_bTryToUnProne.
                float10 remaining = (float10)this->UncrouchTime - *(float*)inputDelta;
                this->UncrouchTime = (float)remaining;
                if (remaining <= nativeFloatZero)
                    *pawnFlagWord = flags & ~0x500U;
            }
        } else if ((flags & 0x10) != 0 && physics != 12) { // bWantsToCrouch.
            if ((flags & 0x20) == 0) {
                APawn::Crouch(this, 0);
            } else if ((flags & 0x40) != 0) { // bTryToUncrouch.
                float10 remaining = (float10)this->UncrouchTime - *(float*)inputDelta;
                this->UncrouchTime = (float)remaining;
                if (remaining <= nativeFloatZero)
                    *pawnFlagWord = flags & ~0x50U;
            }
        }
    } else {
        if ((flags & 0x20) != 0)
            APawn::UnCrouch(this, 0);
        if ((*pawnFlagWord & 0x200) != 0)
            this->AR6Pawn::UnCrawl(0);
    }
    uint physicsDeltaWord = *inputDelta; // EDI retains this packet through startNewPhysics and later callbacks.
    this->APawn::startNewPhysics(reinterpret_cast<float&>(physicsDeltaWord), 0);
    physics = this->Physics;
    flags = *pawnFlagWord;
    flags = (flags & ~0x1000000U) | ((uint)(physics == 2 || physics == 1) << 24); // bSimulateGravity.
    *pawnFlagWord = flags;
    if ((flags & 0x20) != 0 && ((physics != 1 && physics != 12) || (flags & 0x10) == 0))
        APawn::UnCrouch(this, 0);
    flags = *pawnFlagWord;
    if ((flags & 0x200) != 0 && (this->Physics != 1 || (flags & 0x100) == 0))
        this->AR6Pawn::UnCrawl(0);
    AController* controller = this->Controller;
    if (controller != nullptr) {
        controller->MoveTimer = (float)((float10)controller->MoveTimer - *(float*)inputDelta);
        if ((reinterpret_cast<byte*>(this)[0xac] & 4) == 0) { // bInterpolating suppresses rotation, not MoveTimer.
            physics = this->Physics;
            if (physics != 13 && physics != 14) {
                bool rotate = (*pawnFlagWord & 0x1000) != 0; // bCrawler.
                if (!rotate)
                    rotate = this->Rotation.Pitch != this->DesiredRotation.Pitch ||
                        this->Rotation.Yaw != this->DesiredRotation.Yaw ||
                        this->Rotation.Roll != this->DesiredRotation.Roll || this->RotationRate.Roll > 0;
                if (!rotate)
                    rotate = APawn::IsHumanControlled(this) != 0;
                if (rotate) {
                    using PhysicsRotation = void (__thiscall*)(AR6Pawn*, float, FVector);
                    uint y = frame.oldVelocityY;
                    byte* vtable = *(byte**)this; // Reload after the optional human query, between the Y/Z reads.
                    uint z = frame.oldVelocityZ;
                    uint oldVelocityWords[3] = {oldVelocityX, y, z};
                    (*(PhysicsRotation*)(vtable + 0x198))(
                        this, reinterpret_cast<float&>(physicsDeltaWord), *(FVector*)oldVelocityWords);
                }
            }
        }
    }
    float10 weightedDelta = *(float*)inputDelta;
    AActor* pending = this->PendingTouch; // Capture before updating AvgPhysicsTime.
    weightedDelta *= nativeFloat0Point2;
    float10 weightedAverage = (float10)this->AvgPhysicsTime * nativeFloat0Point8;
    this->AvgPhysicsTime = (float)(weightedDelta + weightedAverage);
    if (pending != nullptr) {
        AActor::eventPostTouch(pending, this);
        pending = this->PendingTouch; // The callback may replace or empty the list.
        if (pending != nullptr) {
            this->PendingTouch = pending->PendingTouch;
            pending->PendingTouch = nullptr;
        }
    }
    finishStatistics(); // Plain normal completion; no RAII accounting on exceptions. RET 4.
}

// R6Engine.dll @ 10025780 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnperformPhysicsCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10025794 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnperformPhysicsCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPerformPhysics // L"AR6Pawn::performPhysics".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044580 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void performPhysicsExceptionHandler(void)
{
    __asm {
        mov eax,offset performPhysicsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100257c0 : AR6Pawn::execGetMovementDirection
// Skips the parameter terminator, dispatches optional DebugInfo and stores the movement enum's low byte.
void __thiscall AR6Pawn::execGetMovementDirection(FFrame& stack, void* result)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &execGetMovementDirectionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* scriptFrame = &stack; // Captured once; the optional callback does not cause another frame-argument read.
    uint cursor = reinterpret_cast<uint&>(scriptFrame->Code) + 1U;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor;
    bool hasDebugInfo = *(byte*)(uintptr_t)cursor == 0x42;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0; // Cursor update and token comparison both precede activation.
    if (hasDebugInfo) {
        UObject* context = scriptFrame->Object;
        reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
        using Expression = void (__thiscall*)(UObject*, FFrame*, void*);
        Expression* natives = *(Expression**)&CoreGNativesImport;
        natives[0x42](context, scriptFrame, nullptr);
    }
    eMovementDirection direction = this->AR6Pawn::GetMovementDirection();
    void** resultSlot = &result; // Native reloads this incoming pointer after the delegate returns.
    void* output = *resultSlot;
    *(byte*)output = (byte)direction;
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1002582d : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnexecGetMovementDirectionCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10025841 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnexecGetMovementDirectionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetMovementDirection // L"AR6Pawn::execGetMovementDirection".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044590 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execGetMovementDirectionExceptionHandler(void)
{
    __asm {
        mov eax,offset execGetMovementDirectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10025860 : AR6Pawn::execCheckCylinderTranslation
// Evaluates a cylinder sweep, filters borrowed hits, and restores temporary memory before storing the script result.
// Native ABI view retains the incoming frame word for the ignored-actor operand.
void __thiscall AR6Pawn::execCheckCylinderTranslation(FFrame* stack, void* result)
{
    struct NativeFrameView { // Inferred inherited EBP storage; required vector outputs remain uninitialized.
        uint savedEdi, savedEsi, savedEbx, unused50; // EBP-0x5c/-0x58/-0x54/-0x50.
        uint savedTop, savedChunk; // EBP-0x4c/-0x48.
        uint destination[3], start[3], extent[3]; // EBP-0x44/-0x38/-0x2c.
        uint caught, rethrow; // EBP-0x20/-0x1c.
        uint defaultResult, ignoreClass; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &execCheckCylinderTranslationExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    using Expression = void (__thiscall*)(UObject*, FFrame*, void*);
    FFrame* scriptFrame = stack;
    uint cursor = reinterpret_cast<uint&>(scriptFrame->Code);
    byte opcode = *(byte*)(uintptr_t)cursor;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
    frame.savedEsp = &frame.savedEdi;
    Expression* natives = *(Expression**)&CoreGNativesImport;
    UObject* context = scriptFrame->Object;
    frame.state = 0;
    natives[opcode](context, scriptFrame, frame.start);
    cursor = reinterpret_cast<uint&>(scriptFrame->Code);
    opcode = *(byte*)(uintptr_t)cursor;
    context = scriptFrame->Object;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
    natives = *(Expression**)&CoreGNativesImport;
    natives[opcode](context, scriptFrame, frame.destination);
    cursor = reinterpret_cast<uint&>(scriptFrame->Code);
    context = scriptFrame->Object;
    uint* ignoredActorSlot = (uint*)&stack; // Native reuses the incoming frame-argument word for this optional output.
    *ignoredActorSlot = 0;
    opcode = *(byte*)(uintptr_t)cursor;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
    natives = *(Expression**)&CoreGNativesImport;
    natives[opcode](context, scriptFrame, ignoredActorSlot);
    cursor = reinterpret_cast<uint&>(scriptFrame->Code);
    context = scriptFrame->Object;
    frame.ignoreClass = 0;
    opcode = *(byte*)(uintptr_t)cursor;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
    natives = *(Expression**)&CoreGNativesImport;
    natives[opcode](context, scriptFrame, &frame.ignoreClass);
    cursor = reinterpret_cast<uint&>(scriptFrame->Code) + 1U;
    reinterpret_cast<uint&>(scriptFrame->Code) = cursor;
    if (*(byte*)(uintptr_t)cursor == 0x42) {
        context = scriptFrame->Object;
        reinterpret_cast<uint&>(scriptFrame->Code) = cursor + 1U;
        natives = *(Expression**)&CoreGNativesImport;
        natives[0x42](context, scriptFrame, nullptr);
    }
    float10 destinationZ = ((FVector*)frame.destination)->Z;
    // Captured exported GMem object, retained through query and cleanup.
    FMemStack* memory = *(FMemStack**)&CoreGMemImport;
    destinationZ += nativeFloat3Point3500001;
    frame.defaultResult = 1;
    ((FVector*)frame.destination)->Z = (float)destinationZ;
    ((FVector*)frame.start)->Z = (float)((float10)((FVector*)frame.start)->Z + nativeFloat3Point3500001);
    // Native FMemMark field views; saved words and explicit Pop ordering remain separate.
    uint top = reinterpret_cast<uint&>(memory->Top);
    uint chunk = reinterpret_cast<uint&>(memory->TopChunk);
    frame.savedTop = top;
    uint collisionFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa8);
    frame.savedChunk = chunk;
    ALevelInfo* world = (collisionFlags & 0x1000U) != 0 ? this->Level : nullptr;
    uint radiusWord = reinterpret_cast<uint&>(this->CollisionRadius);
    float10 height = this->CollisionHeight;
    ULevel* level = this->XLevel;
    float10 radiusY = this->CollisionRadius;
    ((FVector*)frame.extent)->Y = (float)radiusY;
    ((FVector*)frame.extent)->Z = (float)height;
    frame.extent[0] = radiusWord;
    uint extentWords[3];
    extentWords[0] = frame.extent[0];
    extentWords[1] = frame.extent[1];
    uint extentZ = frame.extent[2];
    byte* levelVtable = *(byte**)level;
    extentWords[2] = extentZ;
    uint startWords[3] = {frame.start[0], frame.start[1], frame.start[2]};
    uint destinationWords[3] = {frame.destination[0], frame.destination[1], frame.destination[2]};
    using MultiLineCheck = FCheckResult* (__thiscall*)(ULevel*, FMemStack*, FVector, FVector, FVector,
        ALevelInfo*, uint, AActor*);
    FCheckResult* hit = (*(MultiLineCheck*)(levelVtable + 0xd8))(level, memory, *(FVector*)destinationWords,
        *(FVector*)startWords, *(FVector*)extentWords, world, 0xdf, this);
    AActor* ignored = reinterpret_cast<AActor*>(static_cast<uintptr_t>(*ignoredActorSlot));
    uint ignoreClass = frame.ignoreClass;
    UClass* actorClass = AActorPrivateStaticClassImport; // Read even for an empty hit list.
    bool blocked = false;
    while (hit != nullptr) {
        AActor* actor = hit->Actor;
        if (actor != ignored) {
            if (ignoreClass == 0) {
                blocked = true;
                break;
            }
            UClass* type = actor->Class; // Deliberately unchecked actor pointer.
            while (type != nullptr && type != actorClass)
                type = type->GetSuperClass();
            if (type == nullptr && actorClass != nullptr) {
                blocked = true;
                break;
            }
        }
        hit = reinterpret_cast<FCheckResult*>(hit->Next);
    }
    uint canTranslate = blocked ? 0U : frame.defaultResult; // Loaded after the query; retained across FreeChunks.
    uint savedChunk = frame.savedChunk;
    if (savedChunk != reinterpret_cast<uint&>(memory->TopChunk)) {
        memory->FMemStack::FreeChunks((FMemStack::FTaggedMemory*)(uintptr_t)savedChunk);
    }
    uint restoreTop = frame.savedTop;
    void** resultSlot = &result;
    void* output = *resultSlot; // Pointer read precedes Top restoration; native has no allocator cleanup on exceptions.
    reinterpret_cast<uint&>(memory->Top) = restoreTop;
    void* previous = frame.previousExceptionList;
    *(uint*)output = canTranslate; // Full script BOOL word, after memory restore and saved-chain read.
    ExceptionList = previous; // Borrowed hit nodes are not read after FreeChunks.
}

// R6Engine.dll @ 10025a47 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnexecCheckCylinderTranslationCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10025a5b : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnexecCheckCylinderTranslationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecCheckCylinderTranslation // L"AR6Pawn::execCheckCylinderTranslation".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445a0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execCheckCylinderTranslationExceptionHandler(void)
{
    __asm {
        mov eax,offset execCheckCylinderTranslationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10025a80 : AR6Pawn::ComputeCrouchBlendRate
// Returns the absolute current-height ratio bounded by ordered comparisons; unordered ratios select one.
float10 __thiscall AR6Pawn::ComputeCrouchBlendRate(float firstHeight, float secondHeight)
{
    float10 rate;
    __asm {
        mov eax,this
        fld dword ptr [eax+0xfc]
        fsub dword ptr [firstHeight]
        fld dword ptr [firstHeight]
        fsub dword ptr [secondHeight]
        fdivp st(1),st
        fabs
        fstp tbyte ptr [rate] // Preserve live x87 precision; there is no native float result spill here.
    }
    if (rate < nativeFloatZero)
        return (float10)nativeFloatZero;
    if (rate < nativeFloatOne)
        return rate;
    return (float10)nativeFloatOne; // Includes equal/greater/unordered, with no denominator-zero guard; RET 8.
}

// R6Engine.dll @ 10025ad0 : AR6Pawn::AdjustFluidCollisionCylinder
// Blends cylinder height, checks upward clearance, and moves with optional restoration for a test call.
int __thiscall AR6Pawn::AdjustFluidCollisionCylinder(float blendRate, int bTest)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; no owned cleanup objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x84/-0x80/-0x7c.
        NativeCheckResult32 hitWords; // EBP-0x78..-0x4c: FCheckResult.
        uint endWords[3]; // EBP-0x48..-0x40: trace endpoint, later movement destination Z.
        uint extentOrPivotWords[3]; // EBP-0x3c..-0x34: trace extent, then each pivot packet.
        uint caught, rethrow; // EBP-0x30/-0x2c.
        uint savedPrePivotZ; // EBP-0x28; raw word, never converted to float.
        float pivotHeightOffset, defaultRadius; // EBP-0x24/-0x20.
        union { float defaultCrouchHeight; uint savedHeight; }; // EBP-0x1c, reused after clearance.
        float heightDelta, defaultHeight; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &AdjustCylinderExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint pawnFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0); // Read before saved ESP/state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if ((pawnFlags & 0x200U) != 0) // m_bIsProne.
        return finish(1);
    APawn* defaults = static_cast<APawn*>(this->Class->GetDefaultObject());
    uint defaultHeightWord = reinterpret_cast<uint&>(defaults->CollisionHeight);
    uint defaultRadiusWord = reinterpret_cast<uint&>(defaults->CollisionRadius);
    uint defaultCrouchWord = reinterpret_cast<uint&>(defaults->CrouchHeight);
    reinterpret_cast<uint&>(frame.defaultHeight) = defaultHeightWord;
    float10 heightDifference = (float10)frame.defaultHeight;
    reinterpret_cast<uint&>(frame.defaultCrouchHeight) = defaultCrouchWord;
    heightDifference -= frame.defaultCrouchHeight;
    reinterpret_cast<uint&>(frame.defaultRadius) = defaultRadiusWord;
    blendRate = (float)((float10)frame.defaultHeight - heightDifference * blendRate); // Overwrites incoming EBP+8.
    float10 currentHeight = (float10)this->CollisionHeight;
    if ((float10)blendRate == currentHeight) // Ordered equality; NaN continues.
        return finish(1);
    float10 targetHeight = (float10)blendRate;
    uint oldPivotZ = reinterpret_cast<uint&>(this->PrePivot.Z);
    float10 difference = targetHeight - this->CollisionHeight;
    frame.savedPrePivotZ = oldPivotZ;
    frame.heightDelta = (float)difference;
    frame.pivotHeightOffset = (float)((float10)frame.defaultHeight - blendRate);
    bool hasClearance = true;
    if ((float10)frame.heightDelta > nativeFloatZero) {
        float10 extentHeight = (float10)this->CollisionHeight;
        uint radiusWord = reinterpret_cast<uint&>(this->CollisionRadius);
        float10 extentRadius = (float10)this->CollisionRadius;
        ULevel* level = this->XLevel;
        FVector& extent = *(FVector*)frame.extentOrPivotWords;
        extent.Y = (float)extentRadius;
        frame.hitWords.nextAddress = 0;
        extent.Z = (float)extentHeight;
        frame.hitWords.actorAddress = 0;
        float10 endZ = (float10)frame.heightDelta;
        frame.hitWords.primitiveAddress = 0;
        endZ += this->Location.Z;
        frame.hitWords.materialAddress = 0;
        FVector& end = *(FVector*)frame.endWords;
        end.Y = (float)(float10)this->Location.Y;
        end.Z = (float)endZ;
        frame.extentOrPivotWords[0] = radiusWord;
        uint endX = reinterpret_cast<uint&>(this->Location.X);
        for (int i = 2; i != 8; ++i)
            reinterpret_cast<uint*>(&frame.hitWords)[i] = 0;
        reinterpret_cast<uint&>(frame.hitWords.Time) = 0x3f800000;
        reinterpret_cast<uint&>(frame.hitWords.Item) = 0xffffffff;
        frame.endWords[0] = endX;
        using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*,
            const FVector*, const FVector*, uint, FVector);
        SingleLineCheck trace = *(SingleLineCheck*)(*(byte**)level + 0xcc);
        trace(level, reinterpret_cast<FCheckResult*>(&frame.hitWords), this, &end, &this->Location, 0x286, extent);
        float10 one = (float10)nativeFloatOne;
        hasClearance = (float10)frame.hitWords.Time == one; // Ignore raw trace return.
    }
    int testAfterTrace = bTest;
    if (!hasClearance) {
        if (testAfterTrace == 0) {
            this->m_fCrouchBlendRate = (float)this->AR6Pawn::ComputeCrouchBlendRate(frame.defaultHeight,
                frame.defaultCrouchHeight);
            AController* controller = this->Controller; // Native assumes nonnull before walking Class.
            UClass* type = controller->Class;
            while (type != nullptr && type != &AR6PlayerController::PrivateStaticClass)
                type = type->GetSuperClass();
            if (type != nullptr) {
                uint blendWord = reinterpret_cast<uint&>(this->m_fCrouchBlendRate); // Before rereading Controller.
                AController* currentController = this->Controller;
                DispatchSetCrouchBlend(currentController, reinterpret_cast<float&>(blendWord));
            }
        }
        return finish(0);
    }
    uint savedHeightWord = reinterpret_cast<uint&>(this->CollisionHeight); // After the clearance callback.
    uint targetHeightWord = reinterpret_cast<uint&>(blendRate);
    uint radiusWord = reinterpret_cast<uint&>(frame.defaultRadius);
    frame.savedHeight = savedHeightWord;
    this->AActor::SetCollisionSize(reinterpret_cast<float&>(radiusWord), reinterpret_cast<float&>(targetHeightWord));
    float10 pivotZ = (float10)frame.pivotHeightOffset + this->m_fPrePivotPawnInitialOffset;
    using SetPrePivot = void (__thiscall*)(APawn*, FVector);
    byte* pawnVtable = *(byte**)this; // Before the pivot result spill.
    frame.extentOrPivotWords[0] = 0;
    ((FVector*)frame.extentOrPivotWords)->Z = (float)pivotZ;
    frame.extentOrPivotWords[1] = 0;
    (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)frame.extentOrPivotWords);
    uint destinationX = reinterpret_cast<uint&>(this->Location.X);
    uint destinationY = reinterpret_cast<uint&>(this->Location.Y);
    uint destinationZ = reinterpret_cast<uint&>(this->Location.Z);
    frame.endWords[2] = destinationZ;
    float10 movedZ = (float10)((FVector*)frame.endWords)->Z + frame.heightDelta;
    ULevel* level = this->XLevel;
    byte* levelVtable = *(byte**)level;
    ((FVector*)frame.endWords)->Z = (float)movedZ;
    FVector destination;
    ((uint*)&destination)[0] = destinationX;
    ((uint*)&destination)[1] = destinationY;
    ((uint*)&destination)[2] = frame.endWords[2];
    using FarMoveActor = int (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
    int moveResult = (*(FarMoveActor*)(levelVtable + 0x9c))(level, this, destination, 1, 0, 0, 0);
    if (moveResult == 0 || bTest != 0) { // Current incoming test word is read only after nonzero move result.
        uint restoreHeight = frame.savedHeight;
        uint restoreRadius = reinterpret_cast<uint&>(this->CollisionRadius);
        this->AActor::SetCollisionSize(reinterpret_cast<float&>(restoreRadius), reinterpret_cast<float&>(restoreHeight));
        uint restorePivotZ = frame.savedPrePivotZ;
        pawnVtable = *(byte**)this;
        frame.extentOrPivotWords[2] = restorePivotZ;
        frame.extentOrPivotWords[0] = 0;
        frame.extentOrPivotWords[1] = 0;
        (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)frame.extentOrPivotWords);
    }
    return finish(moveResult); // RET 8; exceptions do not roll back cylinder, pivot or Location.
}

// R6Engine.dll @ 10025de7 : forward the caught cylinder-adjustment pointer through its inherited frame
__declspec(naked) void AdjustCylinderCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x30]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x2c]
        push edx
        mov dword ptr [ebp-0x2c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10025dfb : report cylinder-adjustment context and forward the active exception
__declspec(naked) void AdjustCylinderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnAdjustFluidCollisionCylinder // L"AR6Pawn::AdjustFluidCollisionCylinder".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445b0 : select cylinder-adjustment exception tables without creating a frame
__declspec(naked) void AdjustCylinderExceptionHandler(void)
{
    __asm {
        mov eax,offset AdjustCylinderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10025e20 : AR6Pawn::moveToPosition
// Steers planar walking acceleration, reports arrival/timeout, and reduces speed near the target.
int __thiscall AR6Pawn::moveToPosition(const FVector* target)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x4c/-0x48/-0x44.
        uint scaledWords[3]; // EBP-0x40..-0x38, scale helper output.
        uint scratchWords[3]; // EBP-0x34..-0x2c, product spills and direction difference.
        uint directionWords[3]; // EBP-0x28..-0x20.
        uint caught, rethrow; // EBP-0x1c/-0x18.
        float distance; // EBP-0x14, retained through the speed callback.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &MoveToPositionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AController* entryController = this->Controller; // Read/test before saved ESP and state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (entryController == nullptr)
        return finish(0);
    const FVector* capturedTarget = target;
    float10 deltaZ = (float10)capturedTarget->Z - this->Location.Z;
    float10 deltaY = (float10)capturedTarget->Y - this->Location.Y;
    float10 deltaX = (float10)capturedTarget->X;
    byte physics = this->Physics;
    deltaX -= this->Location.X;
    FVector& direction = *(FVector*)frame.directionWords;
    direction.X = (float)deltaX;
    direction.Y = (float)deltaY;
    direction.Z = (float)deltaZ;
    if (physics != 1)
        return finish(0);
    frame.directionWords[2] = 0;
    // Native EBP+8 aliases target, distance, reciprocal, rate and speed.
    uint& argumentWord = reinterpret_cast<uint&>(target);
    float& argumentFloat = reinterpret_cast<float&>(argumentWord);
    argumentFloat = (float)direction.Size();
    reinterpret_cast<uint&>(frame.distance) = argumentWord;
    float10 sampledDistance = (float10)frame.distance;
    float10 zero = (float10)nativeFloatZero;
    float10 magnitude = (float10)frame.distance;
    if (!(sampledDistance >= zero)) // Native negates ordered negatives and unordered values; it does not use FABS.
        magnitude = -magnitude;
    if (magnitude < nativeFloat1EPlus01) { // Strict ordered magnitude <10.
        uint* zeroVector = *(uint**)&FVectorFVector0Import;
        reinterpret_cast<uint&>(this->Acceleration.X) = zeroVector[0];
        reinterpret_cast<uint&>(this->Acceleration.Y) = zeroVector[1];
        uint zeroZ = zeroVector[2];
        AController* controller = this->Controller;
        reinterpret_cast<uint&>(this->Acceleration.Z) = zeroZ;
        controller->m_eMoveToResult = 1;
        return finish(1);
    }
    FVector& scratch = *(FVector*)frame.scratchWords;
    if ((float10)frame.distance > nativeFloatZero) {
        float10 inverseDistance = (float10)nativeFloatOne / frame.distance;
        argumentFloat = (float)inverseDistance;
        float10 normalizedZ = inverseDistance * direction.Z;
        float10 normalizedY = (float10)direction.Y * argumentFloat;
        float10 normalizedX = (float10)argumentFloat * direction.X;
        scratch.X = (float)normalizedX;
        frame.directionWords[0] = frame.scratchWords[0];
        scratch.Y = (float)normalizedY;
        frame.directionWords[1] = frame.scratchWords[1];
        scratch.Z = (float)normalizedZ;
        frame.directionWords[2] = frame.scratchWords[2];
    }
    argumentWord = reinterpret_cast<uint&>(this->AccelRate);
    float10 accelerationZ = (float10)argumentFloat * direction.Z;
    float10 accelerationY = (float10)direction.Y * argumentFloat;
    float10 accelerationX = (float10)argumentFloat * direction.X;
    scratch.X = (float)accelerationX;
    reinterpret_cast<uint&>(this->Acceleration.X) = frame.scratchWords[0];
    scratch.Y = (float)accelerationY;
    reinterpret_cast<uint&>(this->Acceleration.Y) = frame.scratchWords[1];
    AController* controller = this->Controller; // Captured before the Z spill/store, retained for timer/result.
    scratch.Z = (float)accelerationZ;
    reinterpret_cast<uint&>(this->Acceleration.Z) = frame.scratchWords[2];
    float10 timer = (float10)controller->MoveTimer;
    if (timer < nativeFloatZero) { // Unordered timer continues.
        controller->m_eMoveToResult = 2;
        return finish(1);
    }
    argumentFloat = (float)this->Velocity.Size();
    uint speedWord = argumentWord;
    argumentWord = speedWord; // Native redundant store retains the shared incoming slot.
    if ((float10)argumentFloat > nativeFloat1EPlus02) { // Ordered speed >100.
        float10 inverseSpeed = (float10)nativeFloatOne / argumentFloat;
        float10 velocityX = inverseSpeed * this->Velocity.X;
        float10 velocityY = inverseSpeed * this->Velocity.Y;
        float10 velocityZ = inverseSpeed * this->Velocity.Z;
        scratch.X = (float)(velocityX - direction.X);
        scratch.Y = (float)(velocityY - direction.Y);
        scratch.Z = (float)(velocityZ - direction.Z);
        float10 alignment = velocityY * direction.Y;
        alignment += velocityX * direction.X;
        alignment += velocityZ * direction.Z;
        float10 correctionScale = ((float10)nativeFloatOne - alignment) * argumentFloat;
        correctionScale *= nativeFloat0Point2;
        FVector* correction = ScaleVectorToResult(
            (FVector*)frame.scaledWords, (float)correctionScale, &scratch);
        this->Acceleration.X = (float)((float10)this->Acceleration.X - correction->X);
        this->Acceleration.Y = (float)((float10)this->Acceleration.Y - correction->Y);
        this->Acceleration.Z = (float)((float10)this->Acceleration.Z - correction->Z);
    }
    float10 distance = (float10)frame.distance;
    float10 reductionDistance = (float10)this->AvgPhysicsTime * argumentFloat;
    reductionDistance *= nativeDouble1Point4; // Native double 1.4.
    if (distance < reductionDistance) {
        uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
        if ((flags & 0x2000U) == 0) { // bReducedSpeed is applied only once.
            float10 reducedSpeed = (float10)this->DesiredSpeed * nativeDouble0Point5; // Double 0.5.
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) = flags | 0x2000U;
            this->DesiredSpeed = (float)reducedSpeed;
        }
        if ((float10)argumentFloat > nativeFloatZero) {
            float10 speedLimit = (float10)nativeFloat2EPlus02 / argumentFloat; // 200/speed, then binary32 spill.
            uint desiredWord = reinterpret_cast<uint&>(this->DesiredSpeed);
            this->DesiredSpeed = (float)MinFloatOrdered(reinterpret_cast<float&>(desiredWord), (float)speedLimit);
        }
    }
    zero = (float10)nativeFloatZero;
    if ((float10)argumentFloat == zero) { // Ordered equality includes both signed zeros.
        controller = this->Controller;
        controller->MoveTimer = (float)((float10)controller->MoveTimer - nativeFloat0Point25);
    }
    return finish(0); // thiscall RET 4; delegated failures have no local rollback.
}

// R6Engine.dll @ 10026105 : forward the caught moveToPosition pointer through its inherited frame
__declspec(naked) void MoveToPositionCatchPointer(void)
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

// R6Engine.dll @ 10026119 : report moveToPosition context and forward the active exception
__declspec(naked) void MoveToPositionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnMoveToPosition // L"AR6Pawn::MoveToPosition".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445c0 : select moveToPosition exception tables without creating a frame
__declspec(naked) void MoveToPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset MoveToPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10026140 : AR6Pawn::PickActorAdjust
// Tries right then left lateral clearance and stores an accepted adjustment in the current controller.
int __thiscall AR6Pawn::PickActorAdjust(AActor* actor)
{
    struct NativeFrameView { // Inferred inherited EBP storage; all buffers are unowned local words.
        uint savedEdi, savedEsi, savedEbx, caught; // EBP-0xf8/-0xf4/-0xf0/-0xec.
        NativeCheckResult32 hitWords; // EBP-0xe8..-0xbc, shared FCheckResult initialized once.
        uint rightExtentStart[3], rightDisplacement[3]; // EBP-0xb8/-0xac.
        uint leftDisplacement[3], leftExtentStart[3]; // EBP-0xa0/-0x94.
        uint rightPointStart[3], leftPointStart[3]; // EBP-0x88/-0x7c.
        uint rethrow; // EBP-0x70.
        uint endWords[3]; // EBP-0x6c..-0x64, persistent trace endpoint.
        int iteration; // EBP-0x60.
        uint leftExtentOrAdjust[3]; // EBP-0x5c..-0x54.
        float hitDistance; // EBP-0x50.
        uint rightExtentOrAdjust[3]; // EBP-0x4c..-0x44.
        uint distanceSpillOrSelector; // EBP-0x40, later mutable side selector.
        uint directionWords[3]; // EBP-0x3c..-0x34.
        float radiusSum; // EBP-0x30.
        uint rightWords[3], leftWords[3]; // EBP-0x2c/-0x20.
        float reciprocalOrRightDistance; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &PawnPickActorAdjustExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte physics = this->Physics; // Read/compare before saved ESP and state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (physics == 2)
        return finish(0);
    AController* initialController = this->Controller;
    if (initialController == nullptr)
        return finish(0);
    float10 deltaY = (float10)initialController->Destination.Y - this->Location.Y;
    float10 deltaX = (float10)initialController->Destination.X;
    frame.directionWords[2] = 0;
    deltaX -= this->Location.X;
    FVector& direction = *(FVector*)frame.directionWords;
    direction.X = (float)deltaX;
    direction.Y = (float)deltaY;
    frame.endWords[0] = ((uint*)&initialController->Destination)[0];
    uint destinationY = ((uint*)&initialController->Destination)[1];
    uint locationZ = reinterpret_cast<uint&>(this->Location.Z);
    frame.endWords[1] = destinationY;
    frame.endWords[2] = ((uint*)&initialController->Destination)[2]; // Native reads this even though it is overwritten.
    frame.endWords[2] = locationZ;
    using VectorSize = float10 (__thiscall*)(const FVector*);
    float10 distance = reinterpret_cast<VectorSize&>(FVectorSizeImport)(&direction);
    // The live ST0 value still drives zero/reciprocal.
    reinterpret_cast<float&>(frame.distanceSpillOrSelector) = (float)distance;
    float10 zero = (float10)nativeFloatZero;
    if (distance == zero)
        return finish(0);
    float10 one = (float10)nativeFloatOne;
    frame.rightWords[2] = 0;
    frame.reciprocalOrRightDistance = (float)(one / distance);
    FVector& right = *(FVector*)frame.rightWords;
    FVector& left = *(FVector*)frame.leftWords;
    float10 normalizedZ = (float10)frame.reciprocalOrRightDistance * direction.Z;
    float10 normalizedY = (float10)frame.reciprocalOrRightDistance * direction.Y;
    float10 normalizedX = (float10)frame.reciprocalOrRightDistance * direction.X;
    left.X = (float)normalizedX;
    frame.directionWords[0] = frame.leftWords[0];
    left.Y = (float)normalizedY;
    frame.directionWords[1] = frame.leftWords[1];
    AActor* capturedActor = actor;
    left.Z = (float)normalizedZ;
    float10 actorDeltaY = (float10)capturedActor->Location.Y; // No native actor-null check.
    uint normalizedZWord = frame.leftWords[2];
    actorDeltaY -= this->Location.Y;
    uint normalizedYWord = frame.directionWords[1];
    float10 actorDeltaX = (float10)capturedActor->Location.X;
    frame.directionWords[2] = normalizedZWord;
    actorDeltaX -= this->Location.X;
    uint normalizedXWord = frame.directionWords[0];
    float10 leftY = (float10)direction.X * nativeFloatMinus1; // Native -1f multiply, not sign-bit XOR.
    frame.leftWords[0] = normalizedYWord;
    frame.leftWords[2] = 0;
    frame.rightWords[1] = normalizedXWord;
    left.Y = (float)leftY;
    right.X = (float)((float10)direction.Y * nativeFloatMinus1);
    frame.radiusSum = (float)((float10)capturedActor->CollisionRadius + this->CollisionRadius);
    // EBP+8 aliases actor pointer, lateral offset, then left distance.
    uint& argumentWord = reinterpret_cast<uint&>(actor);
    float& argumentFloat = reinterpret_cast<float&>(argumentWord);
    argumentFloat = (float)((float10)right.X * actorDeltaX + actorDeltaY * direction.X);
    float10 offset = (float10)argumentFloat;
    zero = (float10)nativeFloatZero;
    float10 magnitude = (float10)argumentFloat;
    if (!(offset >= zero)) // Includes native FCHS on unordered values.
        magnitude = -magnitude;
    if (magnitude > frame.radiusSum)
        return finish(1); // Already outside the lateral span; no adjustment flag or position update.
    float10 negatedOffset = -(float10)argumentFloat;
    float10 leftDistance = (float10)frame.radiusSum - argumentFloat;
    argumentFloat = (float)leftDistance;
    frame.reciprocalOrRightDistance = (float)((float10)frame.radiusSum - negatedOffset);
    if (!(leftDistance > nativeFloatZero)) // Test the unspilled left distance; assertions may return.
        appFailAssert(nativeTextFAdjustDistLeft0F, nativePathAR6PawnCpp, 0x3d3);
    if (!((float10)frame.reciprocalOrRightDistance > nativeFloatZero))
        appFailAssert(nativeTextFAdjustDistRight0F, nativePathAR6PawnCpp, 0x3d4);
    frame.distanceSpillOrSelector = 0;
    InitializeCheckResult(reinterpret_cast<FCheckResult*>(&frame.hitWords), 1.0f, nullptr);
    frame.iteration = 0;
    int side = 0; // Models native EDI; only rejection reloads/toggles the saved selector.
    using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*,
        const FVector*, uint, FVector);
    while (frame.iteration < 2) {
        uint* zeroExtent = *(uint**)&FVectorFVector0Import;
        ULevel* level = this->XLevel;
        uint* offsetWords = side == 0 ? frame.rightWords : frame.leftWords;
        float& adjustmentDistance = side == 0 ? frame.reciprocalOrRightDistance : argumentFloat;
        uint* pointWords = side == 0 ? frame.rightPointStart : frame.leftPointStart;
        uint* extentStartWords = side == 0 ? frame.rightExtentStart : frame.leftExtentStart;
        uint* extentWords = side == 0 ? frame.rightExtentOrAdjust : frame.leftExtentOrAdjust;
        uint* displacementWords = side == 0 ? frame.rightDisplacement : frame.leftDisplacement;
        FVector& sideOffset = *(FVector*)offsetWords;
        sideOffset.X = (float)((float10)sideOffset.X * adjustmentDistance);
        sideOffset.Y = (float)((float10)sideOffset.Y * adjustmentDistance);
        sideOffset.Z = (float)((float10)sideOffset.Z * adjustmentDistance);
        float10 startZ = (float10)sideOffset.Z + this->Location.Z;
        float10 startY = (float10)sideOffset.Y + this->Location.Y;
        float10 startX = (float10)sideOffset.X + this->Location.X;
        FVector& pointStart = *(FVector*)pointWords;
        pointStart.X = (float)startX;
        pointStart.Y = (float)startY;
        pointStart.Z = (float)startZ;
        FVector zeroPacket;
        ((uint*)&zeroPacket)[0] = zeroExtent[0];
        byte* levelVtable = *(byte**)level; // Between zero-extent X and Y/Z reads.
        ((uint*)&zeroPacket)[1] = zeroExtent[1];
        ((uint*)&zeroPacket)[2] = zeroExtent[2];
        (*(SingleLineCheck*)(levelVtable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&frame.hitWords), this,
            (FVector*)frame.endWords, &pointStart, 0x286, zeroPacket);
        one = (float10)nativeFloatOne;
        bool accept = false;
        if ((float10)frame.hitWords.Time == one) {
            float10 extentHeight = (float10)this->CollisionHeight;
            uint radiusWord = reinterpret_cast<uint&>(this->CollisionRadius);
            float10 extentRadiusY = (float10)this->CollisionRadius;
            level = this->XLevel;
            FVector& extent = *(FVector*)extentWords;
            extent.Y = (float)extentRadiusY;
            extentWords[0] = radiusWord;
            uint extentXWord = extentWords[0];
            extent.Z = (float)extentHeight;
            startZ = (float10)sideOffset.Z + this->Location.Z;
            startY = (float10)sideOffset.Y;
            uint extentYWord = extentWords[1];
            startY += this->Location.Y;
            startX = (float10)sideOffset.X;
            uint extentZWord = extentWords[2];
            startX += this->Location.X;
            FVector& extentStart = *(FVector*)extentStartWords;
            extentStart.X = (float)startX;
            extentStart.Y = (float)startY;
            extentStart.Z = (float)startZ;
            levelVtable = *(byte**)level;
            FVector extentPacket;
            ((uint*)&extentPacket)[0] = extentXWord;
            ((uint*)&extentPacket)[1] = extentYWord;
            ((uint*)&extentPacket)[2] = extentZWord;
            (*(SingleLineCheck*)(levelVtable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&frame.hitWords), this,
                (FVector*)frame.endWords, &extentStart, 0x286, extentPacket);
            one = (float10)nativeFloatOne;
            accept = (float10)frame.hitWords.Time == one;
            if (!accept) {
                FCheckResult& hit = *reinterpret_cast<FCheckResult*>(&frame.hitWords);
                float10 displacementZ = (float10)hit.Location.Z - this->Location.Z;
                float10 displacementY = (float10)hit.Location.Y - this->Location.Y;
                float10 displacementX = (float10)hit.Location.X - this->Location.X;
                FVector& displacement = *(FVector*)displacementWords;
                displacement.X = (float)displacementX;
                displacement.Y = (float)displacementY;
                displacement.Z = (float)displacementZ;
                frame.hitDistance = (float)displacement.Size();
                accept = (float10)frame.radiusSum * nativeFloat4 < frame.hitDistance; // Strict 4*radiusSum.
            }
        }
        if (accept) {
            AController* controller = this->Controller;
            float10 adjustX = (float10)sideOffset.X;
            uint* controllerFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0x3a8);
            uint flags = *controllerFlagWord;
            *controllerFlagWord = flags | 0x40U;
            adjustX += this->Location.X;
            controller = this->Controller;
            FVector& adjust = *(FVector*)extentWords;
            adjust.X = (float)adjustX;
            uint adjustXWord = extentWords[0];
            adjust.Y = (float)((float10)sideOffset.Y + this->Location.Y);
            uint adjustYWord = extentWords[1];
            float10 adjustZ = (float10)sideOffset.Z + this->Location.Z;
            ((uint*)&controller->AdjustLoc)[0] = adjustXWord;
            ((uint*)&controller->AdjustLoc)[1] = adjustYWord;
            adjust.Z = (float)adjustZ;
            ((uint*)&controller->AdjustLoc)[2] = extentWords[2];
            return finish(1);
        }
        int count = frame.iteration;
        uint previousSelector = frame.distanceSpillOrSelector;
        frame.iteration = (int)((uint)count + 1U);
        side = previousSelector == 0 ? 1 : 0;
        frame.distanceSpillOrSelector = (uint)side;
    }
    return finish(0); // RET 4; shared hit storage is never reinitialized between probes or sides.
}

// R6Engine.dll @ 1002674b : forward the caught adjustment pointer through its inherited frame
__declspec(naked) void PawnPickActorAdjustCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xec]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x70]
        push ecx
        mov dword ptr [ebp-0x70],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10026762 : report the native PickWallAdjust context and forward the active exception
__declspec(naked) void PawnPickActorAdjustCatchContext(void)
{
    __asm {
        // L"AR6Pawn::PickWallAdjust", despite exported PickActorAdjust owner.
        push offset nativeTextAR6PawnPickWallAdjust
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445d0 : select Pawn actor-adjustment exception tables without creating a frame
__declspec(naked) void PawnPickActorAdjustExceptionHandler(void)
{
    __asm {
        mov eax,offset PawnPickActorAdjustFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10026780 : AR6Pawn::GetFootLocation
// Writes a visibility-test foot point from the actor's current collision box or height/location.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6Pawn::GetFootLocation(FVector* result, AActor* actor)
{
    struct NativeLocalView { // Inferred FPO scratch relative to entry ESP; no SEH or owned cleanup.
        float scaledX, scaledY; // ESPentry-0x18/-0x14.
        uint unused; // ESPentry-0x10, not initialized or read here.
        uint forwardWords[3]; // ESPentry-0x0c..-0x04, hidden FRotator::Vector output.
    } locals;
    AActor* capturedActor = actor; // ESI retains this entry word even if callbacks change incoming actor storage.
    if (capturedActor->GetPlayerPawn() != nullptr &&
        (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(capturedActor) + 0x3e0) & 0x200U) != 0) { // m_bIsProne.
        AActor* collisionBox = capturedActor->m_collisionBox;
        if (collisionBox != nullptr &&
            (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(collisionBox) + 0xa8) & 0x800U) != 0) {
            float10 displacementValue = (float10)this->m_iVisibilityTest; // Native FILD32, no prior float rounding.
            displacementValue *= nativeFloatMinus0Point45; // -0.45f.
            displacementValue *= collisionBox->CollisionRadius;
            // Incoming actor slot ESPentry+8 is reused as a float spill.
            float& displacement = reinterpret_cast<float&>(actor);
            displacement = (float)displacementValue;
            FVector* forward = &(*(FVector*)locals.forwardWords = collisionBox->Rotation.Vector());
            float10 scaledX = (float10)displacement;
            collisionBox = capturedActor->m_collisionBox; // Reread before the first forward-coordinate load.
            scaledX *= forward->X;
            locals.scaledX = (float)scaledX;
            locals.scaledY = (float)((float10)displacement * forward->Y);
            float10 footZ = (float10)displacement * forward->Z;
            FVector* output = result; // Capture current incoming output after all forward products, before Location.Z.
            footZ += collisionBox->Location.Z;
            float10 footY = (float10)locals.scaledY + collisionBox->Location.Y;
            float10 footX = (float10)locals.scaledX + collisionBox->Location.X;
            output->X = (float)footX;
            output->Y = (float)footY;
            output->Z = (float)footZ;
            return output;
        }
    }
    int visibilityTest = this->m_iVisibilityTest; // Sample after the actor virtual call and any rejected box path.
    float10 height = (float10)capturedActor->CollisionHeight;
    if (visibilityTest == 1) {
        height -= nativeFloat15; // 15f.
        uint xBits = reinterpret_cast<uint&>(capturedActor->Location.X);
        FVector* output = result;
        float10 footZ = (float10)capturedActor->Location.Z - height;
        float10 footY = (float10)capturedActor->Location.Y;
        reinterpret_cast<uint&>(output->X) = xBits;
        output->Y = (float)footY;
        output->Z = (float)footZ;
        return output;
    }
    if (visibilityTest != 0)
        height -= nativeFloat3EPlus01; // 30f; all other nonzero selectors use this branch.
    float10 footZ = (float10)capturedActor->Location.Z - height;
    uint xBits = reinterpret_cast<uint&>(capturedActor->Location.X);
    float10 footY = (float10)capturedActor->Location.Y;
    FVector* output = result;
    output->Y = (float)footY;
    reinterpret_cast<uint&>(output->X) = xBits;
    output->Z = (float)footZ;
    return output; // Hidden vector result pointer in EAX, thiscall RET 8; no guard or added actor-null check.
}

// R6Engine.dll @ 100268a0 : AR6Pawn::physicsRotation
// Turns to controller goals, banks or aligns to the floor, and probes box rotation before moving the pawn.
void __thiscall AR6Pawn::physicsRotation(float deltaSeconds, FVector oldVelocity)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x98/-0x94/-0x90.
        uint coordinatesOrHitWords[12]; // EBP-0x8c..-0x60, FCoords then FCheckResult.
        uint temporaryWords[3]; // EBP-0x5c..-0x54.
        uint movementDeltaWords[3]; // EBP-0x50..-0x48.
        uint extentWords[3]; // EBP-0x44..-0x3c.
        uint accelerationOrDestinationWords[3]; // EBP-0x38..-0x30.
        uint rotationWords[3]; // EBP-0x2c..-0x24.
        uint caught, rethrow; // EBP-0x20/-0x1c.
        int integerTemporary; // EBP-0x18: turn rate, later saved box Z.
        union { int floorPhysics; float accelerationZ; }; // EBP-0x14, reused after the turning phase.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &physicsRotationExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint initialPitch = reinterpret_cast<uint&>(this->Rotation.Pitch);
    uint initialYaw = reinterpret_cast<uint&>(this->Rotation.Yaw);
    uint initialRoll = reinterpret_cast<uint&>(this->Rotation.Roll);
    frame.rotationWords[2] = initialRoll; // Roll is stored before Physics and state 0.
    byte initialPhysics = this->Physics;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.rotationWords[0] = initialPitch;
    frame.rotationWords[1] = initialYaw;
    FRotator& rotation = *(FRotator*)frame.rotationWords;
    if (initialPhysics == 1) {
        frame.floorPhysics = 1;
    } else {
        frame.floorPhysics = 0;
        if (initialPhysics == 12)
            frame.floorPhysics = 1;
    }
    int& floorPhysics = frame.floorPhysics; // Native reads the current saved DWORD around callbacks.
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    // Stable addresses only: byte tests and subsequent DWORD reloads stay separate.
    uint* rotationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xac);
    const uint* pawnFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3e0);
    const uint* rollFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3e4);
    uint flags = *rotationFlagWord;
    *rotationFlagWord = flags & ~1U; // bFixedRotationDir.
    int turnStep = 0; // Native EBX remains independent of frame scratch through turn callbacks.
    int humanControlled = this->APawn::IsHumanControlled();
    flags = *rotationFlagWord;
    AController* controller = this->Controller;
    if (humanControlled != 0) {
        // Native assumes nonnull here.
        uint controllerFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0xac);
        flags ^= (controllerFlags ^ flags) & 2U;
        *rotationFlagWord = flags;
        if ((flags & 2U) != 0) {
            APlayerController* player = reinterpret_cast<APlayerController*>(CastToAPlayerController((int)controller));
            uint speed = reinterpret_cast<uint&>(player->EnemyTurnSpeed);
            frame.integerTemporary = (int)(speed << 1); // Wrapped DWORD shift precedes signed FILD32.
            float10 step = (float10)frame.integerTemporary * deltaSeconds;
            turnStep = appRound((float)step);
            controller = this->Controller;
            this->DesiredRotation.Pitch = controller->DesiredRotation.Pitch;
            this->DesiredRotation.Yaw = controller->DesiredRotation.Yaw;
        }
    } else {
        uint toggle = (flags ^ (controller != nullptr ? 2U : 0U)) & 2U;
        flags = *rotationFlagWord ^ toggle;
        *rotationFlagWord = flags;
        bool useControllerRate = false;
        if ((flags & 2U) != 0) {
            AActor* enemy = controller->Enemy;
            useControllerRate = enemy != nullptr && controller->Focus == enemy;
        }
        float10 rate;
        if (useControllerRate) {
            int pawnRate = this->RotationRate.Yaw;
            int controllerRate = controller->RotationRate.Yaw;
            frame.integerTemporary = pawnRate;
            if (pawnRate < controllerRate)
                frame.integerTemporary = controllerRate;
            rate = (float10)frame.integerTemporary;
        } else {
            rate = (float10)this->RotationRate.Yaw;
        }
        float10 step = rate * deltaSeconds;
        turnStep = appRound((float)step);
    }
    using FixedTurn = int (__thiscall*)(AActor*, int, int, int);
    FixedTurn fixedTurn;
    if ((this->Physics != 11 || this->OnLadder == nullptr) && (*reinterpret_cast<byte*>(rotationFlagWord) & 2U) != 0) {
        int desiredYaw = this->DesiredRotation.Yaw;
        int currentYaw = rotation.Yaw;
        // Capture even if yaw already matches; retain across later callbacks.
        fixedTurn = reinterpret_cast<FixedTurn&>(AActorFixedTurnImport);
        if (desiredYaw != currentYaw)
            rotation.Yaw = fixedTurn(this, currentYaw, desiredYaw, turnStep);
        if ((*rollFlagWord & 0x800U) == 0 && (floorPhysics || this->Physics == 2))
            this->DesiredRotation.Pitch = 0;
        if ((*pawnFlagWord & 0x1000U) == 0 || !floorPhysics) {
            int desiredPitch = this->DesiredRotation.Pitch;
            int currentPitch = rotation.Pitch;
            if (desiredPitch != currentPitch)
                rotation.Pitch = fixedTurn(this, currentPitch, desiredPitch, turnStep);
        }
        controller = this->Controller;
        if ((reinterpret_cast<byte*>(controller)[0xac] & 2U) != 0) {
            controller->Rotation.Yaw = rotation.Yaw;
            controller = this->Controller;
            int desiredPitch = controller->DesiredRotation.Pitch;
            int currentPitch = controller->Rotation.Pitch;
            int pitch = fixedTurn(this, currentPitch, desiredPitch, turnStep);
            controller = this->Controller;
            controller->Rotation.Pitch = pitch;
        }
    } else {
        fixedTurn = reinterpret_cast<FixedTurn&>(AActorFixedTurnImport);
    }
    // EBP+0x14: reciprocal, bank scale or remaining-turn integer.
    uint& sharedIncomingWord = reinterpret_cast<uint&>(oldVelocity.Z);
    float& sharedIncomingFloat = oldVelocity.Z;
    auto truncateLowWord = [](float10 value) { // Models the actual shared x87-to-signed64 helper's low EAX word.
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    auto capAtOne = [](float10 factor) {
        float10 one = (float10)nativeFloatOne;
        return one <= factor ? (float10)nativeFloatOne : factor;
    };
    auto decayRoll = [&](float10 factor) {
        int roll = rotation.Roll;
        if (roll < 0x8000) {
            float10 remainder = (float10)nativeFloatOne - factor;
            return truncateLowWord(remainder * rotation.Roll);
        }
        sharedIncomingWord = 0x10000U - (uint)roll;
        float10 remainingTurn = (float10)reinterpret_cast<int&>(sharedIncomingWord);
        return truncateLowWord(remainingTurn * factor + rotation.Roll);
    };
    int rollCandidate; // Native EAX survives the roll phase into comparison and the direct pawn-move packet.
    if ((*rollFlagWord & 0x800U) != 0) { // bRollToDesired.
        int desiredRoll = this->DesiredRotation.Roll;
        int currentRoll = rotation.Roll;
        rollCandidate = currentRoll;
        if (desiredRoll != currentRoll) {
            rollCandidate = fixedTurn(this, currentRoll, desiredRoll, turnStep);
            rotation.Roll = rollCandidate;
        }
    } else if ((*pawnFlagWord & 0x1000U) != 0) { // bCrawler.
        if (!floorPhysics) {
            float10 step = (float10)this->RotationRate.Yaw * deltaSeconds;
            turnStep = truncateLowWord(step); // Native replaces retained EBX with the reset step.
            int pitch = rotation.Pitch;
            int updatedPitch = fixedTurn(this, pitch, 0, turnStep);
            rotation.Pitch = updatedPitch;
            int roll = rotation.Roll;
            rollCandidate = fixedTurn(this, roll, 0, turnStep);
            rotation.Roll = rollCandidate;
        } else {
            uint slopeRotationWords[3];
            slopeRotationWords[0] = frame.rotationWords[0];
            byte* pawnVtable = *(byte**)this;
            slopeRotationWords[1] = frame.rotationWords[1];
            slopeRotationWords[2] = frame.rotationWords[2];
            uint floorWords[3];
            floorWords[0] = ((uint*)&this->Floor)[0];
            floorWords[1] = ((uint*)&this->Floor)[1];
            floorWords[2] = ((uint*)&this->Floor)[2];
            using FindSlopeRotation = FRotator* (__thiscall*)(AR6Pawn*, FRotator*, FVector, FRotator);
            FRotator* slope = (*(FindSlopeRotation*)(pawnVtable + 0x134))(
                this, (FRotator*)&oldVelocity, *(FVector*)floorWords, *(FRotator*)slopeRotationWords);
            frame.rotationWords[0] = ((uint*)slope)[0];
            frame.rotationWords[1] = ((uint*)slope)[1];
            rollCandidate = (int)((uint*)slope)[2];
            frame.rotationWords[2] = (uint)rollCandidate;
        }
    } else {
        int rollRate = this->RotationRate.Roll;
        if (rollRate <= 0) {
            rollCandidate = 0;
            rotation.Roll = rollCandidate;
        } else {
            byte rollPhysics = this->Physics;
            bool lowWalkingSpeed = false;
            if (rollPhysics == 1) {
                float10 vz = (float10)this->Velocity.Z;
                float10 vy = (float10)this->Velocity.Y;
                float10 vx = (float10)this->Velocity.X;
                float10 speedSquared = (vx * vx + vy * vy) + vz * vz;
                lowWalkingSpeed = speedSquared < nativeFloat4EPlus04; // Strict 40000f.
            }
            if (lowWalkingSpeed) {
                float10 factorInput = (float10)deltaSeconds * nativeFloat8;
                float10 factor = MinFloatOrdered(1.0f, (float)factorInput);
                rollCandidate = decayRoll(factor);
                rotation.Roll = rollCandidate;
            } else {
                float10 changeZ = (float10)this->Velocity.Z - oldVelocity.Z;
                float10 changeY = (float10)this->Velocity.Y - oldVelocity.Y;
                float10 changeX = (float10)this->Velocity.X - oldVelocity.X;
                FVector& temporary = *(FVector*)frame.temporaryWords;
                temporary.X = (float)changeX;
                float10 inverseTime = (float10)nativeFloatOne / deltaSeconds;
                sharedIncomingFloat = (float)inverseTime;
                frame.accelerationZ = (float)(inverseTime * changeZ);
                float10 inverseForY = (float10)sharedIncomingFloat;
                uint accelerationZWord = reinterpret_cast<uint&>(frame.accelerationZ);
                float10 accelerationY = inverseForY * changeY; // Retain this value despite its later 32f spill.
                frame.accelerationOrDestinationWords[2] = accelerationZWord;
                float10 accelerationX = (float10)sharedIncomingFloat * temporary.X;
                FVector& acceleration = *(FVector*)frame.accelerationOrDestinationWords;
                acceleration.X = (float)accelerationX;
                acceleration.Y = (float)accelerationY;
                float10 squareX = (float10)acceleration.X * acceleration.X;
                float10 magnitudeSquared = squareX + accelerationY * accelerationY;
                magnitudeSquared += (float10)frame.accelerationZ * frame.accelerationZ;
                if (magnitudeSquared > nativeFloat1EPlus04) { // Strict 10000f; unordered takes decay.
                    sharedIncomingWord = 0x46dac000; // 28000f, overwritten with 4096f for walking.
                    if (rollPhysics == 1)
                        sharedIncomingWord = 0x45800000;
                    byte* math = *(byte**)&CoreGMathImport;
                    rotation.Roll = 0;
                    FCoords* coordinates = &(*reinterpret_cast<FCoords*>(frame.coordinatesOrHitWords) =
                        *reinterpret_cast<const FCoords*>(math + 0x18) / rotation);
                    const FVector* transformed = &(*reinterpret_cast<FVector*>(frame.temporaryWords) =
                        acceleration.TransformVectorBy(*coordinates));
                    FVector* accelerationAddress = &acceleration;
                    float* bankScaleAddress = &sharedIncomingFloat;
                    float10 rollValue;
                    ushort bankStatus;
                    // Preserve the late status sample; do not replace it with a sign test on transformed Y.
                    __asm {
                        mov eax,transformed
                        mov edx,accelerationAddress
                        mov ecx,dword ptr [eax]
                        mov dword ptr [edx],ecx
                        mov ecx,dword ptr [eax+4]
                        mov dword ptr [edx+4],ecx
                        fld dword ptr [edx+4]
                        fcomp dword ptr [nativeFloatZero]
                        mov ecx,dword ptr [eax+8]
                        fld dword ptr [edx+4]
                        mov dword ptr [edx+8],ecx
                        mov ecx,this
                        fdiv dword ptr [ecx+0x438]
                        mov ecx,bankScaleAddress
                        fmul dword ptr [ecx]
                        fnstsw ax
                        mov bankStatus,ax
                        fstp tbyte ptr [rollValue]
                    }
                    int targetRoll;
                    if ((bankStatus & 0x4100U) == 0) {
                        int requested = truncateLowWord(rollValue);
                        int limit = this->RotationRate.Roll;
                        targetRoll = limit <= requested ? limit : requested;
                    } else {
                        int requested = truncateLowWord(rollValue + nativeFloat65536);
                        int limit = this->RotationRate.Roll;
                        targetRoll = (int)(0x10000U - (uint)limit);
                        if (targetRoll < requested)
                            targetRoll = requested;
                    }
                    *(ushort*)((byte*)this + 0x24a) = 0; // Clear only the actual Roll high word before its DWORD read.
                    int currentRoll = this->Rotation.Roll;
                    rotation.Roll = targetRoll;
                    if (targetRoll > 0x8000 && currentRoll < 0x8000)
                        this->Rotation.Roll = (int)((uint)currentRoll + 0x10000U);
                    else if (targetRoll <= 0x8000 && currentRoll > 0x8000)
                        this->Rotation.Roll = (int)((uint)currentRoll - 0x10000U);
                    float10 factor = capAtOne((float10)deltaSeconds * nativeFloat5);
                    float10 current = ((float10)nativeFloatOne - factor) * this->Rotation.Roll;
                    float10 target = (float10)rotation.Roll * factor;
                    rollCandidate = truncateLowWord(current + target);
                    rotation.Roll = rollCandidate;
                } else {
                    rollCandidate = decayRoll(capAtOne((float10)deltaSeconds * nativeFloat8));
                    rotation.Roll = rollCandidate;
                }
            }
        }
    }
    if (rotation.Pitch == this->Rotation.Pitch && rotation.Yaw == this->Rotation.Yaw &&
        rollCandidate == this->Rotation.Roll)
        return finish();
    AR6ColBox* box = this->m_collisionBox; // Capture before replacing coordinate storage with a hit record.
    for (int i = 0; i != 9; ++i)
        frame.coordinatesOrHitWords[i] = 0;
    frame.coordinatesOrHitWords[9] = 0x3f800000;
    frame.coordinatesOrHitWords[10] = 0xffffffff;
    frame.coordinatesOrHitWords[11] = 0;
    FCheckResult& hit = *(FCheckResult*)frame.coordinatesOrHitWords;
    using MoveActor = int (__thiscall*)(ULevel*, AActor*, FVector, FRotator, FCheckResult*, int, int, int, int, int);
    auto applyPawnRotation = [&](int candidateRoll) {
        uint pitch = frame.rotationWords[0];
        ULevel* level = this->XLevel;
        byte* levelVtable = *(byte**)level;
        uint yaw = frame.rotationWords[1];
        uint* zero = *(uint**)&FVectorFVector0Import;
        uint movementWords[3];
        movementWords[0] = zero[0];
        movementWords[1] = zero[1];
        movementWords[2] = zero[2];
        uint rotationWords[3] = {pitch, yaw, (uint)candidateRoll};
        (*(MoveActor*)(levelVtable + 0x98))(level, this, *(FVector*)movementWords,
            *(FRotator*)rotationWords, &hit, 0, 0, 0, 0, 0); // Ignore the raw move result.
    };
    if (box == nullptr || (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8) & 0x800U) == 0) {
        applyPawnRotation(rollCandidate); // EAX candidate is retained here; do not reload the frame Roll word.
        return finish();
    }
    if (box->Base != this)
        appFailAssert(nativeTextThisMCollisionBoxBase, nativePathAR6PawnCpp, 0x96f);
    FVector& boxDestination = *(FVector*)frame.accelerationOrDestinationWords;
    box = this->m_collisionBox;
    box->AR6ColBox::GetDestination(boxDestination, rotation);
    auto moveBox = [&](bool retry) {
        AActor* currentBox = this->m_collisionBox;
        float10 deltaZ = (float10)currentBox->Location.Z;
        uint pitch = frame.rotationWords[0]; // Sample between the first location load and destination subtraction.
        deltaZ -= boxDestination.Z;
        float10 deltaY = (float10)currentBox->Location.Y - boxDestination.Y;
        float10 deltaX = (float10)currentBox->Location.X - boxDestination.X;
        uint* spillWords = retry ? frame.extentWords : (uint*)&oldVelocity;
        FVector& spill = *(FVector*)spillWords;
        spill.X = (float)deltaX;
        uint xWord = spillWords[0];
        spill.Y = (float)deltaY;
        uint yWord = spillWords[1];
        spill.Z = (float)deltaZ;
        uint yaw = frame.rotationWords[1];
        uint roll = frame.rotationWords[2];
        uint outgoingX = spillWords[0];
        frame.movementDeltaWords[0] = xWord;
        uint zWord = spillWords[2];
        uint outgoingY = spillWords[1];
        frame.movementDeltaWords[2] = zWord;
        ULevel* level = this->XLevel;
        uint outgoingZ = spillWords[2];
        frame.movementDeltaWords[1] = yWord;
        if (retry)
            hit.Time = 1.0f;
        byte* levelVtable = *(byte**)level;
        uint movementWords[3] = {outgoingX, outgoingY, outgoingZ};
        uint rotationWords[3] = {pitch, yaw, roll};
        return (*(MoveActor*)(levelVtable + 0x98))(level, currentBox, *(FVector*)movementWords,
            *(FRotator*)rotationWords, &hit, 1, 0, 0, 0, 1);
    };
    auto rejectPawnRotation = [&]() {
        if (this->APawn::IsHumanControlled() != 0) {
            AController* currentController = this->Controller;
            uint* actual = (uint*)&this->Rotation;
            uint* target = (uint*)&currentController->Rotation;
            target[0] = actual[0];
            target[1] = actual[1];
            target[2] = actual[2];
            currentController = this->Controller;
            target = (uint*)&currentController->DesiredRotation;
            target[0] = actual[0];
            target[1] = actual[1];
            target[2] = actual[2];
            uint pitch = actual[0];
            currentController = this->Controller; // Capture before the pawn's own desired stores.
            target = (uint*)&this->DesiredRotation;
            target[0] = pitch;
            uint yaw = actual[1];
            uint roll = actual[2];
            target[1] = yaw;
            target[2] = roll;
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(currentController) + 0xac) &= ~2U;
        }
    };
    if (moveBox(false) == 0) {
        hit.Time = 0.0f;
        hit.Actor = nullptr;
        uint* zero = *(uint**)&FVectorFVector0Import;
        frame.coordinatesOrHitWords[5] = zero[0];
        frame.coordinatesOrHitWords[6] = zero[1];
        frame.coordinatesOrHitWords[7] = zero[2];
        rejectPawnRotation();
        return finish();
    }
    if (hit.Actor != nullptr) {
        box = this->m_collisionBox;
        if ((reinterpret_cast<byte*>(box)[0x394] & 4U) != 0) { // m_bCanStepUp.
            uint oldZ = reinterpret_cast<uint&>(box->Location.Z);
            uint boxFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8);
            reinterpret_cast<uint&>(frame.integerTemporary) = oldZ;
            ULevel* stepLevel = this->XLevel;
            sharedIncomingWord = *(uint*)((byte*)stepLevel + 0xf0); // Native collision-hash word replaces incoming Z.
            if ((boxFlags & 0x800U) != 0 && sharedIncomingWord != 0) {
                hit.Time = 1.0f;
                float10 extentHeight = (float10)box->CollisionHeight;
                uint radiusWord = reinterpret_cast<uint&>(box->CollisionRadius);
                float10 extentRadiusY = (float10)box->CollisionRadius;
                FVector& extent = *(FVector*)frame.extentWords;
                extent.Y = (float)extentRadiusY;
                frame.extentWords[0] = radiusWord;
                extent.Z = (float)extentHeight;
                uint extentX = frame.extentWords[0];
                float10 endZ = (float10)boxDestination.Z - nativeFloat33;
                uint endX = frame.accelerationOrDestinationWords[0];
                float10 endY = (float10)boxDestination.Y;
                uint extentY = frame.extentWords[1];
                FVector& end = *(FVector*)frame.temporaryWords;
                end.Y = (float)endY;
                uint extentZ = frame.extentWords[2];
                end.Z = (float)endZ;
                frame.temporaryWords[0] = endX;
                byte* levelVtable = *(byte**)stepLevel;
                uint extentPacket[3] = {extentX, extentY, extentZ};
                using SingleLineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*,
                    const FVector*, uint, FVector);
                (*(SingleLineCheck*)(levelVtable + 0xcc))(stepLevel, &hit, box, &end, &box->Location,
                    0x2000dfU, *(FVector*)extentPacket);
                if (hit.Actor == nullptr) {
                    hit.Time = 0.0f;
                    rejectPawnRotation();
                    return finish();
                }
                using HashActorCall = void (__thiscall*)(void*, AActor*);
                void* collisionHash = (void*)sharedIncomingWord;
                box = this->m_collisionBox;
                byte* hashVtable = *(byte**)collisionHash;
                (*(HashActorCall*)(hashVtable + 0xc))(collisionHash, box);
                float10 stepZ = (float10)hit.Location.Z;
                box = this->m_collisionBox;
                stepZ += box->CollisionHeight;
                stepZ += nativeFloat2Point15;
                box->Location.Z = (float)stepZ;
                box = this->m_collisionBox;
                box->AR6ColBox::GetDestination(boxDestination, rotation);
                if (moveBox(true) == 0) { // Retry spills into frame extent words, preserving incoming collision hash.
                    hit.Time = 0.0f;
                    hit.Actor = nullptr;
                }
                box = this->m_collisionBox;
                uint restoredZ = reinterpret_cast<uint&>(frame.integerTemporary);
                // Current box gets the saved raw word, even after replacement.
                reinterpret_cast<uint&>(box->Location.Z) = restoredZ;
                collisionHash = (void*)sharedIncomingWord;
                box = this->m_collisionBox;
                hashVtable = *(byte**)collisionHash;
                (*(HashActorCall*)(hashVtable + 8))(collisionHash, box);
            }
        }
    }
    float10 currentTime = (float10)hit.Time;
    float10 one = (float10)nativeFloatOne;
    if (currentTime < one) {
        rejectPawnRotation();
        return finish();
    }
    box = this->m_collisionBox;
    // m_bCheckForEdges; unordered hit time also reaches this gate.
    if ((reinterpret_cast<byte*>(box)[0x394] & 2U) != 0) {
        uint deltaWord = reinterpret_cast<uint&>(deltaSeconds);
        uint movementX = frame.movementDeltaWords[0];
        byte* pawnVtable = *(byte**)this;
        uint movementY = frame.movementDeltaWords[1];
        uint movementZ = frame.movementDeltaWords[2];
        uint movementWords[3] = {movementX, movementY, movementZ};
        using IsOverLedge = int (__thiscall*)(AR6Pawn*, AActor*, FVector, float);
        int overLedge = (*(IsOverLedge*)(pawnVtable + 0x1ac))(this, box,
            *(FVector*)movementWords, reinterpret_cast<float&>(deltaWord));
        if (overLedge != 0) {
            rejectPawnRotation();
            return finish();
        }
    }
    rollCandidate = rotation.Roll; // Accepted probe path rereads Roll after callbacks, unlike the direct path.
    applyPawnRotation(rollCandidate);
    finish(); // Void RET 16; no automatic hash reattachment or Z/rotation rollback on delegated failure.
}

// R6Engine.dll @ 10027250 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnphysicsRotationCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10027264 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnphysicsRotationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPhysicsRotation // L"AR6Pawn::physicsRotation".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445e0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void physicsRotationExceptionHandler(void)
{
    __asm {
        mov eax,offset physicsRotationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10027290 : AR6Pawn::physLadder
// Moves along a ladder, performs detach/top adjustments, and switches physics after controller loss.
void __thiscall AR6Pawn::physLadder(float deltaSeconds, int unusedIterations)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x68/-0x64/-0x60.
        NativeCheckResult32 hitWords; // EBP-0x5c..-0x30, one FCheckResult shared by every move.
        uint movementWords[3]; // EBP-0x2c..-0x24, product scratch, movement, head point or up vector.
        uint caught, rethrow; // EBP-0x20/-0x1c.
        uint ladderOrFirstY; // EBP-0x18, initial ladder pointer then a rounded first Y product.
        uint speedOrFirstY; // EBP-0x14, raw/rounded speed then a rounded first Y product.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &physLadderExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint* zero = *(uint**)&FVectorFVector0Import;
    uint zeroX = zero[0];
    ALadderVolume* initialLadder = this->OnLadder;
    bool hasLadder = initialLadder != nullptr;
    uint* velocity = (uint*)&this->Velocity;
    velocity[0] = zeroX;
    velocity[1] = zero[1];
    uint zeroZ = zero[2];
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.ladderOrFirstY = (uint)initialLadder;
    velocity[2] = zeroZ; // X/Y stores precede state 0; saved ladder and Z store follow it.
    bool hasAcceleration = false;
    AController* initialController = nullptr;
    if (hasLadder) {
        initialController = this->Controller;
        if (initialController != nullptr) {
            float10 zeroValue = (float10)nativeFloatZero;
            hasAcceleration = (float10)this->Acceleration.X != zeroValue;
            if (!hasAcceleration) {
                zeroValue = (float10)nativeFloatZero;
                hasAcceleration = (float10)this->Acceleration.Y != zeroValue;
            }
            if (!hasAcceleration) {
                zeroValue = (float10)nativeFloatZero;
                hasAcceleration = (float10)this->Acceleration.Z != zeroValue;
            }
        }
    }
    FVector& movement = *(FVector*)frame.movementWords;
    float& speedOrFirstY = reinterpret_cast<float&>(frame.speedOrFirstY);
    float& ladderOrFirstY = reinterpret_cast<float&>(frame.ladderOrFirstY);
    // EBP+8 becomes a raw radius word during detach adjustments.
    uint& deltaOrRadiusWord = reinterpret_cast<uint&>(deltaSeconds);
    using MoveActor = int (__thiscall*)(ULevel*, AActor*, FVector, FRotator, FCheckResult*, int, int, int, int, int);
    auto dispatchMove = [&](ULevel* receiver, byte* vtable, uint pitch, uint yaw, uint roll, uint x, uint y, uint z) {
        uint rotationPacket[3] = {pitch, yaw, roll};
        uint movementPacket[3] = {x, y, z};
        (*(MoveActor*)(vtable + 0x98))(receiver, this, *(FVector*)movementPacket,
            *(FRotator*)rotationPacket, reinterpret_cast<FCheckResult*>(&frame.hitWords), 0, 0, 0, 0, 0);
    };
    if (hasAcceleration) {
        if ((reinterpret_cast<byte*>(this)[0x3e0] & 4U) != 0) { // bIsWalking keeps the raw speed word.
            frame.speedOrFirstY = reinterpret_cast<uint&>(this->LadderSpeed);
        } else {
            bool descending = false;
            if (reinterpret_cast<byte&>(this->m_ePawnType) == 1)
                descending = (float10)this->Acceleration.Z < nativeFloatZero;
            if (descending) {
                speedOrFirstY = (float)((float10)this->LadderSpeed * nativeDouble10);
            } else {
                float10 speed = (float10)this->LadderSpeed;
                speedOrFirstY = (float)(speed + speed);
            }
        }
        float10 climbZ = (float10)speedOrFirstY * initialLadder->ClimbDir.Z;
        float10 climbY = (float10)speedOrFirstY * initialLadder->ClimbDir.Y;
        float10 climbX = (float10)speedOrFirstY * initialLadder->ClimbDir.X;
        movement.X = (float)climbX;
        velocity[0] = frame.movementWords[0];
        movement.Y = (float)climbY;
        velocity[1] = frame.movementWords[1];
        movement.Z = (float)climbZ;
        velocity[2] = frame.movementWords[2];
        // Full DWORD, not a byte.
        uint latentAction =
            (*reinterpret_cast<FStateFrame**>(reinterpret_cast<byte*>(initialController) + 0xc))->LatentAction;
        float10 signal;
        if (latentAction != 0) {
            signal = ((float10)this->Acceleration.Z + this->Acceleration.Y) + this->Acceleration.X;
        } else {
            signal = (float10)initialLadder->ClimbDir.Z * this->Acceleration.Z;
            signal += (float10)initialLadder->ClimbDir.Y * this->Acceleration.Y;
            signal += (float10)initialLadder->ClimbDir.X * this->Acceleration.X;
        }
        if (signal < nativeFloatZero) { // Unordered signals do not reverse.
            this->Velocity.X = (float)((float10)this->Velocity.X * nativeFloatMinus1);
            this->Velocity.Y = (float)((float10)this->Velocity.Y * nativeFloatMinus1);
            this->Velocity.Z = (float)((float10)this->Velocity.Z * nativeFloatMinus1);
        }
        float10 moveZ = (float10)deltaSeconds;
        ULevel* slotLevel = this->XLevel;
        moveZ *= this->Velocity.Z;
        float10 moveY = (float10)deltaSeconds * this->Velocity.Y;
        float10 moveX = (float10)deltaSeconds * this->Velocity.X;
        frame.hitWords.nextAddress = 0;
        frame.hitWords.actorAddress = 0;
        frame.hitWords.primitiveAddress = 0;
        movement.X = (float)moveX;
        frame.hitWords.materialAddress = 0;
        reinterpret_cast<uint&>(frame.hitWords.Location.X) = 0;
        movement.Y = (float)moveY;
        reinterpret_cast<uint&>(frame.hitWords.Location.Y) = 0;
        reinterpret_cast<uint&>(frame.hitWords.Location.Z) = 0;
        movement.Z = (float)moveZ;
        reinterpret_cast<uint&>(frame.hitWords.Normal.X) = 0;
        reinterpret_cast<uint&>(frame.hitWords.Normal.Y) = 0;
        reinterpret_cast<uint&>(frame.hitWords.Normal.Z) = 0;
        reinterpret_cast<uint&>(frame.hitWords.Time) = 0x3f800000;
        reinterpret_cast<uint&>(frame.hitWords.Item) = 0xffffffff;
        byte* slotVtable = *(byte**)slotLevel;
        uint* liveRotation = (uint*)&this->Rotation;
        uint pitch = liveRotation[0], yaw = liveRotation[1], roll = liveRotation[2];
        uint x = frame.movementWords[0], y = frame.movementWords[1], z = frame.movementWords[2];
        ULevel* receiver = this->XLevel;
        dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z); // Ignore results; keep the shared hit record.
        ALadderVolume* currentLadder = this->OnLadder;
        if (currentLadder == nullptr) {
            slotLevel = this->XLevel;
            moveZ = (float10)this->CollisionHeight;
            slotVtable = *(byte**)slotLevel;
            moveZ *= nativeFloat1Point1;
            movement.Z = (float)moveZ;
            frame.movementWords[0] = 0;
            frame.movementWords[1] = 0;
            pitch = liveRotation[0]; yaw = liveRotation[1]; roll = liveRotation[2];
            x = frame.movementWords[0]; y = frame.movementWords[1]; z = frame.movementWords[2];
            receiver = this->XLevel;
            dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z);
            ALadderVolume* savedLadder = reinterpret_cast<ALadderVolume*>(frame.ladderOrFirstY);
            float10 firstZ = (float10)savedLadder->LookDir.Z;
            slotLevel = this->XLevel;
            firstZ *= nativeFloatHalf;
            uint radiusWord = reinterpret_cast<uint&>(this->CollisionRadius);
            float10 firstY = (float10)savedLadder->LookDir.Y * nativeFloatHalf;
            deltaOrRadiusWord = radiusWord;
            speedOrFirstY = (float)firstY; // Overwrite the speed slot after detach.
            float10 firstX = (float10)savedLadder->LookDir.X;
            slotVtable = *(byte**)slotLevel;
            firstX *= nativeFloatHalf;
            movement.X = (float)firstX;
            moveZ = firstZ * deltaSeconds;
            pitch = liveRotation[0];
            moveY = (float10)speedOrFirstY * deltaSeconds;
            yaw = liveRotation[1];
            moveX = (float10)movement.X * deltaSeconds;
            roll = liveRotation[2];
            movement.X = (float)moveX; x = frame.movementWords[0];
            movement.Y = (float)moveY; y = frame.movementWords[1];
            movement.Z = (float)moveZ; z = frame.movementWords[2];
            receiver = this->XLevel;
            dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z);
            moveZ = (float10)this->CollisionHeight * nativeFloatMinus1Point5;
            slotLevel = this->XLevel;
            movement.Z = (float)moveZ;
            slotVtable = *(byte**)slotLevel;
            pitch = liveRotation[0]; yaw = liveRotation[1]; roll = liveRotation[2];
            frame.movementWords[0] = 0; x = frame.movementWords[0];
            frame.movementWords[1] = 0; y = frame.movementWords[1];
            z = frame.movementWords[2];
            receiver = this->XLevel;
            dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z);
            savedLadder = reinterpret_cast<ALadderVolume*>(frame.ladderOrFirstY);
            firstZ = (float10)savedLadder->LookDir.Z;
            pitch = liveRotation[0];
            firstZ *= nativeFloatMinus0Point4;
            firstY = (float10)savedLadder->LookDir.Y;
            receiver = this->XLevel;
            firstY *= nativeFloatMinus0Point4;
            slotVtable = *(byte**)receiver;
            ladderOrFirstY = (float)firstY; // The saved pointer slot now becomes rounded first Y.
            firstX = (float10)savedLadder->LookDir.X;
            radiusWord = reinterpret_cast<uint&>(this->CollisionRadius);
            firstX *= nativeFloatMinus0Point4;
            deltaOrRadiusWord = radiusWord;
            movement.X = (float)firstX;
            moveZ = firstZ * deltaSeconds;
            moveY = (float10)ladderOrFirstY * deltaSeconds;
            yaw = liveRotation[1];
            moveX = (float10)movement.X;
            roll = liveRotation[2];
            moveX *= deltaSeconds;
            movement.X = (float)moveX; x = frame.movementWords[0];
            movement.Y = (float)moveY; y = frame.movementWords[1];
            movement.Z = (float)moveZ; z = frame.movementWords[2];
            dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z); // This move retains the captured receiver.
            zero = *(uint**)&FVectorFVector0Import;
            velocity[0] = zero[0];
            velocity[1] = zero[1];
            velocity[2] = zero[2];
        } else {
            FCheckResult* hit = reinterpret_cast<FCheckResult*>(&frame.hitWords);
            float10 time = (float10)hit->Time;
            float10 one = (float10)nativeFloatOne;
            if (time < one && (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(hit->Actor) + 0xa0) & 0x100000U) != 0) {
                // Native does not guard hit.Actor here.
                this->APawn::eventEndClimbLadder(currentLadder);
            } else if ((reinterpret_cast<byte*>(currentLadder)[0x478] & 1U) == 0) {
                float10 headZ = (float10)this->CollisionHeight;
                uint headX = reinterpret_cast<uint&>(this->Location.X);
                headZ += this->Location.Z;
                float10 headY = (float10)this->Location.Y;
                movement.Y = (float)headY;
                frame.movementWords[0] = headX;
                uint headYWord = frame.movementWords[1];
                movement.Z = (float)headZ;
                uint headZWord = frame.movementWords[2];
                uint headWords[3] = {headX, headYWord, headZWord};
                if (currentLadder->AVolume::Encompasses(*(FVector*)headWords) !=
                    0) {
                    currentLadder = this->OnLadder; // Reload without an added null check after the callback.
                    moveZ = (float10)deltaSeconds * currentLadder->LookDir.Z;
                    pitch = liveRotation[0];
                    float10 firstY = (float10)deltaSeconds * currentLadder->LookDir.Y;
                    receiver = this->XLevel;
                    ladderOrFirstY = (float)firstY;
                    slotVtable = *(byte**)receiver;
                    float10 firstX = (float10)deltaSeconds * currentLadder->LookDir.X;
                    movement.X = (float)firstX;
                    moveZ *= speedOrFirstY;
                    moveY = (float10)ladderOrFirstY * speedOrFirstY;
                    yaw = liveRotation[1];
                    moveX = (float10)movement.X;
                    roll = liveRotation[2];
                    moveX *= speedOrFirstY;
                    movement.X = (float)moveX; x = frame.movementWords[0];
                    movement.Y = (float)moveY; y = frame.movementWords[1];
                    movement.Z = (float)moveZ; z = frame.movementWords[2];
                    dispatchMove(receiver, slotVtable, pitch, yaw, roll, x, y, z); // Retain the captured receiver.
                }
            }
        }
    }
    if (this->Controller == nullptr) {
        NativeActorControlVtable* pawnVtable = *reinterpret_cast<NativeActorControlVtable**>(this);
        frame.movementWords[0] = 0;
        uint upX = frame.movementWords[0];
        frame.movementWords[1] = 0;
        uint upY = frame.movementWords[1];
        frame.movementWords[2] = 0x3f800000;
        uint upZ = frame.movementWords[2];
        uint upWords[3] = {upX, upY, upZ};
        using SetPhysics = void (__thiscall*)(AActor*, byte, AActor*, FVector);
        reinterpret_cast<SetPhysics&>(pawnVtable->setPhysicsAddress)(this, 2, nullptr, *(FVector*)upWords);
    }
    ExceptionList = frame.previousExceptionList; // Void RET 8 consumes the untouched unusedIterations slot.
}

// R6Engine.dll @ 1002786a : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnphysLadderCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x1c]
        push eax
        mov dword ptr [ebp-0x1c],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002787e : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnphysLadderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPhysLadder // L"AR6Pawn::physLadder".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100445f0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void physLadderExceptionHandler(void)
{
    __asm {
        mov eax,offset physLadderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100278a0 : AR6Pawn::CheckForLedges
// Probes support and lateral alternatives, updates fall/jump state and returns an adjusted movement vector.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6Pawn::CheckForLedges(FVector* result, AActor* subject, FVector direction, FVector movementDelta,
    FVector gravityDirection, int* checkedFall, int* mustJump, float deltaSeconds)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xd8/-0xd4/-0xd0.
        uint caught, rethrow; // EBP-0xcc/-0xc8.
        uint mathWords[3]; // EBP-0xc4..-0xbc.
        uint originalY, originalZ; // EBP-0xb8/-0xb4.
        NativeCheckResult32 hitWords; // EBP-0xb0..-0x84, one shared FCheckResult.
        float unitZ; // EBP-0x80.
        uint radiusShiftWords[3]; // EBP-0x7c..-0x74.
        float intermediateZ, intermediateY; // EBP-0x70/-0x6c.
        uint supportOrDropWords[3]; // EBP-0x68..-0x60.
        uint extentWords[3]; // EBP-0x5c..-0x54, raw radius X/Y and rounded height.
        uint tangentWords[3]; // EBP-0x50..-0x48.
        float scratch; // EBP-0x44.
        float probeLengthOrUnitY, movementLength; // EBP-0x40/-0x3c.
        uint traceOrRootWords[3]; // EBP-0x38..-0x30; double root occupies the final two words.
        uint productWords[3]; // EBP-0x2c..-0x24.
        uint radiusWord; // EBP-0x20, later reused by directional arithmetic.
        uint candidateWords[3]; // EBP-0x1c..-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &CheckForLedgesExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* entrySubject = subject;
    frame.radiusWord = reinterpret_cast<uint&>(entrySubject->CollisionRadius);
    AActor* primaryBox = this->m_collisionBox;
    bool isPrimaryBox = primaryBox == entrySubject;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    uint& radiusWord = frame.radiusWord;
    const uint* movementFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0x3e0);
    if (!isPrimaryBox && (*movementFlagWord & 0x200U) != 0)
        reinterpret_cast<float&>(radiusWord) = (float)((float10)reinterpret_cast<float&>(radiusWord) * nativeFloatHalf);
    uint frozenRadius = radiusWord;
    float10 extentHeight = (float10)entrySubject->CollisionHeight;
    frame.hitWords.nextAddress = 0;
    ((FVector*)frame.extentWords)->Z = (float)extentHeight;
    float10 shiftZ = (float10)direction.Z;
    frame.hitWords.actorAddress = 0;
    frame.hitWords.primitiveAddress = 0;
    frame.hitWords.materialAddress = 0;
    uint shapeFlags = *movementFlagWord;
    frame.extentWords[0] = frozenRadius;
    frame.extentWords[1] = frozenRadius;
    for (int i = 2; i != 8; ++i)
        reinterpret_cast<uint*>(&frame.hitWords)[i] = 0;
    reinterpret_cast<uint&>(frame.hitWords.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hitWords.Item) = 0xffffffff;
    FCheckResult* hit = reinterpret_cast<FCheckResult*>(&frame.hitWords);
    uint* extentWords = frame.extentWords;
    FVector& product = *(FVector*)frame.productWords;
    FVector& radiusShift = *(FVector*)frame.radiusShiftWords;
    FVector& candidatePosition = *(FVector*)frame.candidateWords;
    FVector& traceEnd = product;
    float& movementLength = frame.movementLength;
    float& probeLength = frame.probeLengthOrUnitY;
    // Local views abbreviate repeated native copies, arithmetic and dispatch; they add no native helper bodies.
    auto copyVector = [](FVector& out, const FVector& in) {
        uint* destination = (uint*)&out;
        const uint* source = (const uint*)&in;
        destination[0] = source[0];
        destination[1] = source[1];
        destination[2] = source[2];
    };
    auto finish = [&]() -> FVector* {
        FVector* output = result; // Cache the current hidden output even when its own argument word is overwritten.
        uint* destination = (uint*)output;
        uint* source = (uint*)&movementDelta;
        uint x = source[0];
        destination[0] = x;
        destination[1] = source[1];
        destination[2] = source[2];
        ExceptionList = frame.previousExceptionList;
        return output; // Interleaved forward copy, hidden result in EAX, RET 0x38.
    };
    float10 shiftY, shiftX;
    if ((shapeFlags & 0x100000U) != 0) {
        shiftZ *= nativeFloatHalf;
        frame.scratch = (float)((float10)direction.Y * nativeFloatHalf);
        product.X = (float)((float10)direction.X * nativeFloatHalf);
        shiftZ *= reinterpret_cast<float&>(radiusWord);
        shiftY = (float10)frame.scratch * reinterpret_cast<float&>(radiusWord);
        shiftX = (float10)product.X;
    } else {
        shiftZ *= reinterpret_cast<float&>(radiusWord);
        shiftY = (float10)direction.Y * reinterpret_cast<float&>(radiusWord);
        shiftX = (float10)direction.X;
    }
    shiftX *= reinterpret_cast<float&>(radiusWord);
    const FVector* subjectLocation = &entrySubject->Location; // Retain the original location address across callbacks.
    product.X = (float)shiftX;
    product.Y = (float)shiftY;
    product.Z = (float)shiftZ;
    uint shiftXWord = frame.productWords[0];
    float10 candidateZ = (float10)movementDelta.Z;
    uint shiftYWord = frame.productWords[1];
    candidateZ += subjectLocation->Z;
    frame.radiusShiftWords[0] = shiftXWord;
    float10 candidateY = (float10)movementDelta.Y;
    uint shiftZWord = frame.productWords[2];
    candidateY += subjectLocation->Y;
    frame.radiusShiftWords[1] = shiftYWord;
    uint* zero = *(uint**)&FVectorFVector0Import;
    frame.radiusShiftWords[2] = shiftZWord;
    frame.scratch = (float)candidateY;
    ULevel* slotLevel = this->XLevel;
    product.X = (float)((float10)movementDelta.X + subjectLocation->X);
    candidateZ += radiusShift.Z;
    candidateY = (float10)radiusShift.Y + frame.scratch;
    float10 candidateX = (float10)radiusShift.X + product.X;
    candidatePosition.X = (float)candidateX;
    candidatePosition.Y = (float)candidateY;
    candidatePosition.Z = (float)candidateZ;
    uint zeroX = zero[0];
    byte* slotVtable = *(byte**)slotLevel;
    uint zeroY = zero[1];
    uint zeroZ = zero[2];
    AActor* activeSubject = subject; // Native EBX retains this packet's subject across its callback.
    ULevel* receiver = this->XLevel;
    uint zeroPacket[3] = {zeroX, zeroY, zeroZ};
    using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
        &candidatePosition, subjectLocation, 0x2de, *(FVector*)zeroPacket);
    float10 one = (float10)nativeFloatOne;
    if ((float10)hit->Time != one)
        return finish();
    frame.scratch = (float)movementDelta.Size();
    reinterpret_cast<uint&>(movementLength) = reinterpret_cast<uint&>(frame.scratch);
    float10 reach = (float10)movementLength + reinterpret_cast<float&>(radiusWord);
    float10 reachLimit = (float10)nativeFloat33;
    if (reach <= reachLimit)
        reach = (float10)nativeFloat33;
    reach += activeSubject->CollisionHeight;
    zero = *(uint**)&FVectorFVector0Import;
    slotLevel = this->XLevel;
    probeLength = (float)(reach + nativeFloat4);
    float10 endZ = (float10)gravityDirection.Z * probeLength;
    frame.scratch = (float)((float10)gravityDirection.Y * probeLength);
    product.X = (float)((float10)gravityDirection.X * probeLength);
    endZ += candidatePosition.Z;
    float10 endYLive = (float10)candidatePosition.Y + frame.scratch;
    float10 endXLive = (float10)product.X + candidatePosition.X;
    traceEnd.X = (float)endXLive;
    traceEnd.Y = (float)endYLive;
    traceEnd.Z = (float)endZ;
    zeroX = zero[0];
    slotVtable = *(byte**)slotLevel;
    zeroY = zero[1];
    zeroZ = zero[2];
    activeSubject = subject;
    receiver = this->XLevel;
    zeroPacket[0] = zeroX; zeroPacket[1] = zeroY; zeroPacket[2] = zeroZ;
    (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
        &traceEnd, &candidatePosition, 0xde, *(FVector*)zeroPacket);
    if ((*movementFlagWord & 0x100000U) == 0) {
        candidateZ = (float10)movementDelta.Z + this->Location.Z; // Pawn location, even for another subject.
        candidateY = (float10)movementDelta.Y + this->Location.Y;
        candidateX = (float10)movementDelta.X + this->Location.X;
        product.X = (float)candidateX; frame.candidateWords[0] = frame.productWords[0];
        product.Y = (float)candidateY; frame.candidateWords[1] = frame.productWords[1];
        product.Z = (float)candidateZ; frame.candidateWords[2] = frame.productWords[2];
    }
    one = (float10)nativeFloatOne;
    bool useCylinder = (float10)hit->Time == one;
    if (!useCylinder)
        useCylinder = (float10)hit->Normal.Z < nativeDouble0Point7;
    if (!useCylinder) {
        float10 hitDistance = (float10)probeLength * hit->Time;
        float10 minimum = (float10)activeSubject->CollisionHeight + nativeDouble37;
        if (minimum < hitDistance) {
            float10 normalSquare = (float10)hit->Normal.Z * hit->Normal.Z;
            float10 rootInput = (float10)nativeFloatOne - normalSquare;
            *(double*)&frame.traceOrRootWords[1] =
                appSqrt((double)rootInput);
            hitDistance = (float10)probeLength * hit->Time;
            float10 projected = (float10)movementLength + activeSubject->CollisionRadius;
            projected *= *(double*)&frame.traceOrRootWords[1];
            projected /= hit->Normal.Z;
            float10 height = (float10)activeSubject->CollisionHeight + nativeFloat4;
            useCylinder = projected + height < hitDistance;
        }
    }
    if (useCylinder) {
        endZ = (float10)gravityDirection.Z;
        uint extentX = frame.extentWords[0];
        endZ *= nativeFloat37;
        slotLevel = this->XLevel;
        float10 endY = (float10)gravityDirection.Y * nativeFloat37;
        uint extentY = frame.extentWords[1];
        frame.scratch = (float)endY;
        float10 endX = (float10)gravityDirection.X;
        uint extentZ = frame.extentWords[2];
        endX *= nativeFloat37;
        activeSubject = subject;
        product.X = (float)endX;
        endZ += candidatePosition.Z;
        endYLive = (float10)candidatePosition.Y + frame.scratch;
        endXLive = (float10)product.X + candidatePosition.X;
        traceEnd.X = (float)endXLive;
        traceEnd.Y = (float)endYLive;
        traceEnd.Z = (float)endZ;
        slotVtable = *(byte**)slotLevel;
        uint extentPacket[3] = {extentX, extentY, extentZ};
        (*(LineCheck*)(slotVtable + 0xcc))(slotLevel, hit, activeSubject,
            &traceEnd, &candidatePosition, 0x2de, *(FVector*)extentPacket); // This probe retains its level receiver.
    }
    one = (float10)nativeFloatOne;
    if ((float10)hit->Time != one)
        return finish();
    float10 originalZ = (float10)direction.Z * movementLength;
    reinterpret_cast<float&>(frame.originalZ) = (float)originalZ;
    float10 originalY = (float10)direction.Y * movementLength;
    reinterpret_cast<float&>(frame.originalY) = (float)originalY;
    float10 originalX = (float10)direction.X * movementLength;
    frame.scratch = (float)originalX;
    product.X = (float)originalX;
    frame.intermediateZ = (float)(originalZ + subjectLocation->Z);
    frame.intermediateY = (float)(originalY + subjectLocation->Y);
    product.X = (float)((float10)product.X + subjectLocation->X);
    candidateZ = (float10)radiusShift.Z + frame.intermediateZ;
    candidateY = (float10)radiusShift.Y + frame.intermediateY;
    candidateX = (float10)product.X + radiusShift.X;
    product.X = (float)candidateX; frame.candidateWords[0] = frame.productWords[0];
    product.Y = (float)candidateY; frame.candidateWords[1] = frame.productWords[1];
    product.Z = (float)candidateZ;
    uint candidateZWord = frame.productWords[2];
    one = (float10)nativeFloatOne;
    frame.candidateWords[2] = candidateZWord;
    float10 inverseLength = one / movementLength; // Native divides even for zero or nonfinite length.
    slotLevel = this->XLevel;
    float10 unitZ = (float10)movementDelta.Z * inverseLength;
    frame.unitZ = (float)unitZ;
    float10 unitY = (float10)movementDelta.Y * inverseLength;
    frame.probeLengthOrUnitY = (float)unitY;
    product.X = (float)(inverseLength * movementDelta.X);
    product.Y = (float)unitY;
    product.Z = (float)unitZ;
    float10 probeHeight = (float10)activeSubject->CollisionHeight + nativeFloat6;
    frame.intermediateY = (float)((float10)gravityDirection.Z * probeHeight);
    frame.intermediateZ = (float)((float10)gravityDirection.Y * probeHeight);
    float10 gravityXProduct = probeHeight * gravityDirection.X;
    FVector& supportStart = *(FVector*)frame.supportOrDropWords;
    float10 supportZ = (float10)candidatePosition.Z + frame.intermediateY;
    float10 supportY = (float10)candidatePosition.Y + frame.intermediateZ;
    float10 supportX = gravityXProduct + candidatePosition.X;
    supportStart.X = (float)supportX;
    supportStart.Y = (float)supportY;
    supportStart.Z = (float)supportZ;
    float10 diameter = (float10)reinterpret_cast<float&>(radiusWord);
    diameter += diameter;
    // Reuses the radius slot for backstep Z.
    reinterpret_cast<float&>(radiusWord) = (float)((float10)direction.Z * diameter);
    reinterpret_cast<float&>(frame.traceOrRootWords[2]) = (float)((float10)direction.Y * diameter);
    reinterpret_cast<float&>(frame.mathWords[0]) = (float)(diameter * direction.X);
    frame.intermediateY = (float)((float10)frame.intermediateY + subjectLocation->Z);
    supportY = (float10)frame.intermediateZ + subjectLocation->Y;
    zero = *(uint**)&FVectorFVector0Import;
    frame.intermediateZ = (float)supportY;
    reinterpret_cast<float&>(frame.tangentWords[0]) = (float)(gravityXProduct + subjectLocation->X);
    float10 sweepZ = (float10)frame.intermediateY - reinterpret_cast<float&>(radiusWord);
    float10 sweepY = (float10)frame.intermediateZ - reinterpret_cast<float&>(frame.traceOrRootWords[2]);
    float10 sweepX = (float10)reinterpret_cast<float&>(frame.tangentWords[0]) -
        reinterpret_cast<float&>(frame.mathWords[0]);
    FVector& sweepEnd = *(FVector*)frame.traceOrRootWords;
    sweepEnd.X = (float)sweepX;
    sweepEnd.Y = (float)sweepY;
    sweepEnd.Z = (float)sweepZ;
    zeroX = zero[0];
    slotVtable = *(byte**)slotLevel;
    zeroY = zero[1];
    zeroZ = zero[2];
    zeroPacket[0] = zeroX; zeroPacket[1] = zeroY; zeroPacket[2] = zeroZ;
    activeSubject = subject;
    receiver = this->XLevel;
    (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
        &sweepEnd, &supportStart, 0x86, *(FVector*)zeroPacket);
    float10 dropZ = (float10)gravityDirection.Z * nativeFloat39;
    float10 dropY = (float10)gravityDirection.Y * nativeFloat39;
    float10 dropX = (float10)gravityDirection.X * nativeFloat39;
    gravityDirection.X = (float)dropX;
    frame.supportOrDropWords[0] = reinterpret_cast<uint&>(gravityDirection.X);
    gravityDirection.Y = (float)dropY;
    frame.supportOrDropWords[1] = reinterpret_cast<uint&>(gravityDirection.Y);
    gravityDirection.Z = (float)dropZ;
    uint dropZWord = reinterpret_cast<uint&>(gravityDirection.Z);
    float10 sweepTime = (float10)hit->Time;
    frame.supportOrDropWords[2] = dropZWord;
    one = (float10)nativeFloatOne;
    bool sweepHit = sweepTime < one;
    reinterpret_cast<uint&>(gravityDirection.Z) = 0; // Incoming gravity Z becomes the side-blocked word.
    FVector& drop = supportStart;
    FVector& unitMovement = product;
    float& unitZSpill = frame.unitZ;
    float& unitYSpill = frame.probeLengthOrUnitY;
    uint& sideBlocked = reinterpret_cast<uint&>(gravityDirection.Z);
    uint& needsJump = reinterpret_cast<uint&>(direction.Z);
    FVector& tangent = *(FVector*)frame.tangentWords;
    FVector& mathOutput = *(FVector*)frame.mathWords;
    uint retainedExtentY;
    if (!sweepHit) { // Equal, greater and unordered all choose the perpendicular candidate.
        float10 tangentY = (float10)unitMovement.X;
        uint tangentXWord = reinterpret_cast<uint&>(unitYSpill);
        tangentY *= nativeFloatMinus1;
        frame.tangentWords[0] = tangentXWord;
        frame.tangentWords[2] = 0;
        needsJump = 1;
        tangent.Y = (float)tangentY;
        float10 cappedSpeed = (float10)this->DesiredSpeed;
        float10 limit = (float10)nativeFloat0Point8;
        if (limit <= cappedSpeed)
            cappedSpeed = (float10)nativeFloat0Point8;
        float10 scale = cappedSpeed * this->GroundSpeed;
        retainedExtentY = frame.extentWords[1];
        scale *= deltaSeconds;
        reinterpret_cast<float&>(radiusWord) = (float)scale;
        float10 z = scale * nativeFloatZero;
        float10 y = (float10)reinterpret_cast<float&>(radiusWord) * tangent.Y;
        float10 x = (float10)reinterpret_cast<float&>(radiusWord) * unitYSpill;
        sweepEnd.X = (float)x; reinterpret_cast<uint&>(movementDelta.X) = frame.traceOrRootWords[0];
        sweepEnd.Y = (float)y; reinterpret_cast<uint&>(movementDelta.Y) = frame.traceOrRootWords[1];
        sweepEnd.Z = (float)z; reinterpret_cast<uint&>(movementDelta.Z) = frame.traceOrRootWords[2];
        z = (float10)movementDelta.Z + subjectLocation->Z;
        y = (float10)movementDelta.Y + subjectLocation->Y;
        x = (float10)movementDelta.X + subjectLocation->X;
        sweepEnd.X = (float)x; frame.candidateWords[0] = frame.traceOrRootWords[0];
        sweepEnd.Y = (float)y; frame.candidateWords[1] = frame.traceOrRootWords[1];
        slotLevel = this->XLevel;
        sweepEnd.Z = (float)z; frame.candidateWords[2] = frame.traceOrRootWords[2];
        slotVtable = *(byte**)slotLevel;
        uint extentX = frame.extentWords[0];
        uint extentZ = frame.extentWords[2];
        activeSubject = subject;
        receiver = this->XLevel;
        uint extentPacket[3] = {extentX, retainedExtentY, extentZ};
        (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
            &candidatePosition, subjectLocation, 0x2de, *(FVector*)extentPacket);
        one = (float10)nativeFloatOne;
        if ((float10)hit->Time == one) {
            z = (float10)drop.Z;
            slotLevel = this->XLevel;
            z += candidatePosition.Z;
            extentX = frame.extentWords[0];
            y = (float10)drop.Y + candidatePosition.Y;
            x = (float10)drop.X + candidatePosition.X;
            sweepEnd.X = (float)x;
            sweepEnd.Y = (float)y;
            sweepEnd.Z = (float)z;
            slotVtable = *(byte**)slotLevel;
            extentZ = frame.extentWords[2];
            extentPacket[0] = extentX; extentPacket[1] = retainedExtentY; extentPacket[2] = extentZ;
            activeSubject = subject;
            receiver = this->XLevel;
            (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
                &sweepEnd, &candidatePosition, 0x2de, *(FVector*)extentPacket);
            one = (float10)nativeFloatOne;
            if ((float10)hit->Time == one) {
                movementDelta.X = (float)((float10)movementDelta.X * nativeFloatMinus1);
                movementDelta.Y = (float)((float10)movementDelta.Y * nativeFloatMinus1);
                movementDelta.Z = (float)((float10)movementDelta.Z * nativeFloatMinus1);
            } else {
                sideBlocked = 1;
            }
        } else {
            sideBlocked = 1;
        }
    } else {
        uint avoidanceFlags = *movementFlagWord;
        if ((avoidanceFlags & 0x100000U) == 0) {
            float10 tangentY = (float10)hit->Normal.X;
            uint tangentXWord = reinterpret_cast<uint&>(hit->Normal.Y);
            tangentY *= nativeFloatMinus1;
            tangent.Y = (float)tangentY;
            frame.tangentWords[0] = tangentXWord;
            frame.tangentWords[2] = 0;
            FVector* normalized = &(mathOutput = tangent.SafeNormal());
            float10 dotY = (float10)direction.Y;
            frame.tangentWords[0] = reinterpret_cast<uint&>(normalized->X);
            frame.tangentWords[1] = reinterpret_cast<uint&>(normalized->Y);
            dotY *= tangent.Y;
            uint normalizedZ = reinterpret_cast<uint&>(normalized->Z);
            float10 dotZ = (float10)direction.Z;
            frame.tangentWords[2] = normalizedZ;
            dotZ *= tangent.Z;
            float10 dot = dotY + dotZ;
            float10 dotX = (float10)direction.X * tangent.X;
            dot += dotX;
            if (dot < nativeFloatZero) {
                tangent.X = (float)((float10)tangent.X * nativeFloatMinus1);
                tangent.Y = (float)((float10)tangent.Y * nativeFloatMinus1);
                tangent.Z = (float)((float10)tangent.Z * nativeFloatMinus1);
            }
            dotY = (float10)direction.Y * tangent.Y;
            dotZ = (float10)direction.Z * tangent.Z;
            dot = dotY + dotZ;
            dotX = (float10)direction.X * tangent.X;
            dot += dotX;
            bool jump = dot < nativeDouble0Point5;
            if (!jump && (*movementFlagWord & 0x4000U) != 0)
                jump = dot < nativeDouble0Point7;
            needsJump = jump ? 1 : 0; // Overwrites incoming direction Z after both dot products.
            float10 scale;
            if (dot < nativeDouble0Point7) {
                uint speedWord = reinterpret_cast<uint&>(this->DesiredSpeed);
                scale = MinFloatOrdered(0.8f, reinterpret_cast<float&>(speedWord));
                scale *= this->GroundSpeed;
                scale *= deltaSeconds;
            } else {
                scale = ((float10)this->DesiredSpeed * this->GroundSpeed) * deltaSeconds;
            }
            FVector* scaled = ScaleVectorToResult(&mathOutput, (float)scale, &tangent);
            uint scaledX = reinterpret_cast<uint&>(scaled->X);
            retainedExtentY = frame.extentWords[1];
            reinterpret_cast<uint&>(movementDelta.X) = scaledX;
            reinterpret_cast<uint&>(movementDelta.Y) = reinterpret_cast<uint&>(scaled->Y);
            reinterpret_cast<uint&>(movementDelta.Z) = reinterpret_cast<uint&>(scaled->Z);
        } else {
            bool stopAtLedges = (avoidanceFlags & 0x200000U) != 0;
            float10 scale = (float10)this->DesiredSpeed * this->GroundSpeed;
            uint normalY = reinterpret_cast<uint&>(hit->Normal.Y);
            uint normalX = reinterpret_cast<uint&>(hit->Normal.X);
            frame.tangentWords[1] = normalY;
            scale *= deltaSeconds;
            frame.tangentWords[0] = normalX;
            frame.tangentWords[2] = reinterpret_cast<uint&>(hit->Normal.Z);
            scale *= nativeFloatMinus1;
            frame.tangentWords[2] = 0;
            direction.Z = (float)scale;
            float10 z = scale * nativeFloatZero;
            float10 y = (float10)direction.Z * tangent.Y;
            float10 x = (float10)direction.Z * tangent.X;
            direction.X = (float)x; reinterpret_cast<uint&>(movementDelta.X) = reinterpret_cast<uint&>(direction.X);
            direction.Y = (float)y; reinterpret_cast<uint&>(movementDelta.Y) = reinterpret_cast<uint&>(direction.Y);
            direction.Z = (float)z;
            uint movementZWord = reinterpret_cast<uint&>(direction.Z);
            needsJump = 0;
            retainedExtentY = frame.extentWords[1];
            reinterpret_cast<uint&>(movementDelta.Z) = movementZWord;
            AController* controller = this->Controller; // Native avoidance branch assumes a controller.
            if (stopAtLedges)
                reinterpret_cast<uint&>(controller->MoveTimer) = 0xbf800000;
            else
                controller->MoveTimer = (float)((float10)controller->MoveTimer - nativeFloat0Point25);
        }
    }
    if (APawn::IsHumanControlled(this) != 0) {
        uint blocked = sideBlocked;
        needsJump = 0;
        if (blocked == 0) {
            float10 z = (float10)movementDelta.Z + subjectLocation->Z;
            float10 y = (float10)movementDelta.Y + subjectLocation->Y;
            reinterpret_cast<float&>(frame.traceOrRootWords[2]) = (float)y;
            reinterpret_cast<float&>(frame.mathWords[0]) = (float)((float10)movementDelta.X + subjectLocation->X);
            z += radiusShift.Z;
            y = (float10)radiusShift.Y + reinterpret_cast<float&>(frame.traceOrRootWords[2]);
            float10 x = (float10)reinterpret_cast<float&>(frame.mathWords[0]) + radiusShift.X;
            sweepEnd.X = (float)x; frame.candidateWords[0] = frame.traceOrRootWords[0];
            sweepEnd.Y = (float)y; frame.candidateWords[1] = frame.traceOrRootWords[1];
            slotLevel = this->XLevel;
            sweepEnd.Z = (float)z; frame.candidateWords[2] = frame.traceOrRootWords[2];
            slotVtable = *(byte**)slotLevel;
            uint extentX = frame.extentWords[0];
            uint extentZ = frame.extentWords[2];
            activeSubject = subject;
            receiver = this->XLevel;
            uint extentPacket[3] = {extentX, retainedExtentY, extentZ};
            (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
                &candidatePosition, subjectLocation, 0x2de, *(FVector*)extentPacket);
            one = (float10)nativeFloatOne;
            if ((float10)hit->Time == one) {
                z = (float10)drop.Z;
                slotLevel = this->XLevel;
                z += candidatePosition.Z;
                extentX = frame.extentWords[0];
                y = (float10)drop.Y + candidatePosition.Y;
                x = (float10)drop.X + candidatePosition.X;
                sweepEnd.X = (float)x;
                sweepEnd.Y = (float)y;
                sweepEnd.Z = (float)z;
                slotVtable = *(byte**)slotLevel;
                extentZ = frame.extentWords[2];
                extentPacket[0] = extentX; extentPacket[1] = retainedExtentY; extentPacket[2] = extentZ;
                activeSubject = subject;
                receiver = this->XLevel;
                (*(LineCheck*)(slotVtable + 0xcc))(receiver, hit, activeSubject,
                    &sweepEnd, &candidatePosition, 0x2de, *(FVector*)extentPacket);
                one = (float10)nativeFloatOne;
                if ((float10)hit->Time == one) {
                    const FVector* zero = *(const FVector**)&FVectorFVector0Import;
                    copyVector(this->Acceleration, *zero);
                    zero = *(const FVector**)&FVectorFVector0Import;
                    copyVector(movementDelta, *zero);
                }
            }
        }
    }
    // Restores frame-backed original products, retaining scratch writes around an aliased jump output.
    auto useOriginalStep = [&](bool setJumpFlag) {
        float10 z = reinterpret_cast<float&>(frame.originalZ);
        uint xWord = reinterpret_cast<uint&>(frame.scratch);
        float10 y = reinterpret_cast<float&>(frame.originalY);
        uint yWord, zWord;
        if (setJumpFlag) {
            int* jumpOutput = mustJump;
            sweepEnd.Y = (float)y;
            *jumpOutput = 1;
            yWord = frame.traceOrRootWords[1];
            sweepEnd.Z = (float)z;
            frame.traceOrRootWords[0] = xWord;
            zWord = frame.traceOrRootWords[2];
        } else {
            sweepEnd.Y = (float)y;
            yWord = frame.traceOrRootWords[1];
            frame.traceOrRootWords[0] = xWord;
            sweepEnd.Z = (float)z;
            zWord = frame.traceOrRootWords[2];
        }
        reinterpret_cast<uint&>(movementDelta.X) = xWord;
        reinterpret_cast<uint&>(movementDelta.Y) = yWord;
        reinterpret_cast<uint&>(movementDelta.Z) = zWord;
    };
    if ((*movementFlagWord & 0x4000U) != 0) { // bCanJump.
        if (needsJump != 0) {
            AController* controller = this->Controller;
            bool canNotify = false;
            if (controller != nullptr) {
                byte* controllerFrame = *(byte**)((byte*)controller + 0xc);
                canNotify = controllerFrame == nullptr;
                if (controllerFrame != nullptr)
                    canNotify = (*(uint*)(controllerFrame + 0x24) & 2U) != 0;
            }
            if (!canNotify) {
                useOriginalStep(false);
            } else {
                int* fallOutput = checkedFall;
                if (*fallOutput == 0) {
                    *fallOutput = 1;
                    controller = this->Controller;
                    needsJump = 0;
                    AController::eventMayFall(controller);
                    if ((*movementFlagWord & 0x4000U) == 0)
                        goto projectRemainingMovement;
                    useOriginalStep(true);
                }
            }
        }
        if ((*movementFlagWord & 0x4000U) != 0)
            return finish(); // Recheck follows callbacks and aliased reference/scratch writes.
    }
projectRemainingMovement:
    // Local views retain the incoming pointer slots reused as floats and the shared native trace packet.
    float& fallScratch = reinterpret_cast<float&>(checkedFall);
    float& jumpScratch = reinterpret_cast<float&>(mustJump);
    auto dispatchCurrentTrace = [&](byte* table, uint extentX, uint extentZ, const FVector* end,
        const FVector* start) {
        AActor* traceSubject = subject;
        ULevel* traceReceiver = this->XLevel;
        uint packet[3] = {extentX, retainedExtentY, extentZ};
        (*(LineCheck*)(table + 0xcc))(traceReceiver, hit, traceSubject, end, start, 0x2de, *(FVector*)packet);
    };
    auto restoreUnitMovement = [&]() -> FVector* {
        float10 z = (float10)unitZSpill * movementLength;
        float10 y = (float10)unitYSpill * movementLength;
        float10 x = (float10)unitMovement.X * movementLength;
        direction.X = (float)x; reinterpret_cast<uint&>(movementDelta.X) = reinterpret_cast<uint&>(direction.X);
        direction.Y = (float)y; reinterpret_cast<uint&>(movementDelta.Y) = reinterpret_cast<uint&>(direction.Y);
        direction.Z = (float)z; reinterpret_cast<uint&>(movementDelta.Z) = reinterpret_cast<uint&>(direction.Z);
        return finish();
    };
    if (needsJump != 0) {
        AActor* projectionSubject = subject;
        float10 projectedLength = (float10)movementLength + projectionSubject->CollisionRadius;
        fallScratch = (float)((float10)unitZSpill * projectedLength);
        jumpScratch = (float)((float10)unitYSpill * projectedLength);
        direction.X = (float)(projectedLength * unitMovement.X);
        float10 z = (float10)fallScratch + subjectLocation->Z;
        float10 y = (float10)jumpScratch + subjectLocation->Y;
        float10 x = (float10)direction.X + subjectLocation->X;
        direction.X = (float)x; frame.candidateWords[0] = reinterpret_cast<uint&>(direction.X);
        slotLevel = this->XLevel;
        direction.Y = (float)y; frame.candidateWords[1] = reinterpret_cast<uint&>(direction.Y);
        direction.Z = (float)z; frame.candidateWords[2] = reinterpret_cast<uint&>(direction.Z);
        uint extentX = frame.extentWords[0];
        slotVtable = *(byte**)slotLevel;
        uint extentZ = frame.extentWords[2];
        dispatchCurrentTrace(slotVtable, extentX, extentZ, &candidatePosition, subjectLocation);
        one = (float10)nativeFloatOne;
        if ((float10)hit->Time == one) {
            z = (float10)drop.Z;
            slotLevel = this->XLevel;
            z += candidatePosition.Z;
            extentX = frame.extentWords[0];
            y = (float10)drop.Y + candidatePosition.Y;
            x = (float10)drop.X + candidatePosition.X;
            direction.X = (float)x;
            direction.Y = (float)y;
            direction.Z = (float)z;
            slotVtable = *(byte**)slotLevel;
            extentZ = frame.extentWords[2];
            dispatchCurrentTrace(slotVtable, extentX, extentZ, &direction, &candidatePosition);
            float10 projectedTime = (float10)hit->Time;
            one = (float10)nativeFloatOne;
            if (!(projectedTime < one))
                goto updateProjectionTimer;
            z = (float10)unitZSpill * movementLength;
            fallScratch = (float)((float10)unitYSpill * movementLength);
            direction.X = (float)((float10)unitMovement.X * movementLength);
            z += subjectLocation->Z;
            y = (float10)fallScratch + subjectLocation->Y;
            x = (float10)direction.X + subjectLocation->X;
            direction.X = (float)x; frame.candidateWords[0] = reinterpret_cast<uint&>(direction.X);
            direction.Y = (float)y; frame.candidateWords[1] = reinterpret_cast<uint&>(direction.Y);
            slotLevel = this->XLevel;
            direction.Z = (float)z;
            uint candidateZWord = reinterpret_cast<uint&>(direction.Z);
            z = (float10)drop.Z;
            frame.candidateWords[2] = candidateZWord;
            z += candidatePosition.Z;
            y = (float10)drop.Y;
            extentX = frame.extentWords[0];
            y += candidatePosition.Y;
            x = (float10)drop.X + candidatePosition.X;
            direction.X = (float)x;
            direction.Y = (float)y;
            direction.Z = (float)z;
            slotVtable = *(byte**)slotLevel;
            extentZ = frame.extentWords[2];
            dispatchCurrentTrace(slotVtable, extentX, extentZ, &direction, &candidatePosition);
        }
        {
            float10 projectedTime = (float10)hit->Time;
            one = (float10)nativeFloatOne;
            if (projectedTime < one)
                return restoreUnitMovement();
        }
updateProjectionTimer:
        AController* controller = this->Controller;
        if (controller != nullptr) {
            fallScratch = (float)appFrand();
            float10 twiceTime = (float10)deltaSeconds;
            twiceTime += twiceTime;
            float10 randomValue = (float10)fallScratch;
            controller = this->Controller; // Native reloads after the provider without another null check.
            if (twiceTime > randomValue)
                reinterpret_cast<uint&>(controller->MoveTimer) = 0xbf800000;
            else
                controller->MoveTimer = (float)((float10)controller->MoveTimer - nativeFloat0Point1);
        }
    }
    if (sideBlocked != 0)
        return finish();
    float10 z = (float10)movementDelta.Z + subjectLocation->Z;
    float10 y = (float10)movementDelta.Y + subjectLocation->Y;
    fallScratch = (float)y;
    direction.X = (float)((float10)movementDelta.X + subjectLocation->X);
    z += radiusShift.Z;
    y = (float10)radiusShift.Y + fallScratch;
    float10 x = (float10)direction.X + radiusShift.X;
    direction.X = (float)x; frame.candidateWords[0] = reinterpret_cast<uint&>(direction.X);
    slotLevel = this->XLevel;
    direction.Y = (float)y; frame.candidateWords[1] = reinterpret_cast<uint&>(direction.Y);
    direction.Z = (float)z; frame.candidateWords[2] = reinterpret_cast<uint&>(direction.Z);
    uint extentX = frame.extentWords[0];
    slotVtable = *(byte**)slotLevel;
    uint extentZ = frame.extentWords[2];
    dispatchCurrentTrace(slotVtable, extentX, extentZ, &candidatePosition, subjectLocation);
    one = (float10)nativeFloatOne;
    if ((float10)hit->Time == one) {
        z = (float10)drop.Z;
        slotLevel = this->XLevel;
        z += candidatePosition.Z;
        extentX = frame.extentWords[0];
        y = (float10)drop.Y + candidatePosition.Y;
        x = (float10)drop.X + candidatePosition.X;
        direction.X = (float)x;
        direction.Y = (float)y;
        direction.Z = (float)z;
        slotVtable = *(byte**)slotLevel;
        extentZ = frame.extentWords[2];
        dispatchCurrentTrace(slotVtable, extentX, extentZ, &direction, &candidatePosition);
    } else {
        AController* controller = this->Controller;
        if (controller != nullptr) {
            float10 dotY = (float10)unitYSpill * hit->Normal.Y;
            float10 dotZ = (float10)unitZSpill * hit->Normal.Z;
            float10 dot = dotY + dotZ;
            float10 dotX = (float10)unitMovement.X * hit->Normal.X;
            dot += dotX;
            if (dot < controller->MinHitWall)
                reinterpret_cast<uint&>(controller->MoveTimer) = 0xbf800000;
        }
    }
    one = (float10)nativeFloatOne;
    if ((float10)hit->Time != one)
        return finish();
    z = (float10)drop.Z;
    slotLevel = this->XLevel;
    z += subjectLocation->Z;
    extentX = frame.extentWords[0];
    y = (float10)drop.Y + subjectLocation->Y;
    x = (float10)drop.X + subjectLocation->X;
    direction.X = (float)x;
    direction.Y = (float)y;
    direction.Z = (float)z;
    slotVtable = *(byte**)slotLevel;
    extentZ = frame.extentWords[2];
    dispatchCurrentTrace(slotVtable, extentX, extentZ, &direction, subjectLocation);
    AController* controller = this->Controller;
    if (controller != nullptr)
        reinterpret_cast<uint&>(controller->MoveTimer) = 0xbf800000;
    const uint* zeroWords = *(const uint**)&FVectorFVector0Import;
    one = (float10)nativeFloatOne;
    uint zeroXWord = zeroWords[0];
    bool noSupport = (float10)hit->Time == one;
    uint* acceleration = (uint*)&this->Acceleration;
    acceleration[0] = zeroXWord;
    acceleration[1] = zeroWords[1];
    uint zeroZWord = zeroWords[2];
    acceleration[2] = zeroZWord;
    if (noSupport) {
        float10 reverseScale = (float10)deltaSeconds * this->GroundSpeed;
        reverseScale *= nativeFloatMinus1;
        FVector* scaled = ScaleVectorToResult(&direction, (float)reverseScale, &unitMovement);
        copyVector(movementDelta, *scaled);
    } else {
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        copyVector(movementDelta, *zero);
    }
    return finish();
}

// R6Engine.dll @ 100288da : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnCheckForLedgesCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xcc]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0xc8]
        push ecx
        mov dword ptr [ebp-0xc8],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100288f7 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnCheckForLedgesCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnCheckForLedges // L"AR6Pawn::CheckForLedges".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044600 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void CheckForLedgesExceptionHandler(void)
{
    __asm {
        mov eax,offset CheckForLedgesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10028920 : AR6Pawn::UpdateColBox
// Aligns the prone collision boxes with floor support and updates pelvis rotation and vertical pre-pivot.
void __thiscall AR6Pawn::UpdateColBox(FVector* movedLocation, int forceUpdate, int poseOnly, int testMove)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xbc/-0xb8/-0xb4.
        uint caught; // EBP-0xb0.
        uint rotationWords[3]; // EBP-0xac..-0xa4, side-probe rotator.
        float productY; // EBP-0xa0, later probe product scratch.
        uint rethrow; // EBP-0x9c.
        NativeCheckResult32 hitWords; // EBP-0x98..-0x6c, shared FCheckResult.
        uint directionWords[3]; // EBP-0x68..-0x60, in-place normalized box direction.
        uint sideWords[3]; // EBP-0x5c..-0x54, first probe start/hit snapshot.
        uint scratchWords[3]; // EBP-0x50/-0x4c/-0x48, cleared before the entry gates.
        float signedStairOffset; // EBP-0x44.
        uint startWords[3]; // EBP-0x40..-0x38.
        uint endWords[3]; // EBP-0x34..-0x2c.
        uint targetWords[3]; // EBP-0x28..-0x20.
        uint extentWords[3]; // EBP-0x1c..-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &UpdateColBoxExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint* outputWords = (uint*)movedLocation; // Capture before the stair flag write; explicit output/RET 16.
    this->m_iIsInStairVolume = 0; // +0x3a8; pawn volume contributes 1, primary-box volume contributes 0x10.
    outputWords[0] = 0;
    outputWords[1] = 0;
    outputWords[2] = 0;
    AR6ColBox* box = this->m_collisionBox;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.scratchWords[2] = 0;
    frame.scratchWords[1] = 0;
    frame.scratchWords[0] = 0;
    // Restores the inherited exception chain on normal exits.
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (box == nullptr) {
        finish();
        return;
    }
    int retainedPoseOnly = poseOnly;
    if (retainedPoseOnly == 0 &&
        ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8) & 0x800U) == 0 ||
            (reinterpret_cast<byte*>(box)[0x394] & 4U) == 0)) {
        finish();
        return;
    }
    for (UClass* type = this->PhysicsVolume->Class; type != nullptr; type = type->GetSuperClass()) {
        if (type == &AR6StairVolume::PrivateStaticClass) {
            this->m_iIsInStairVolume |= 1;
            break;
        }
    }
    box = this->m_collisionBox;
    for (UClass* type = box->PhysicsVolume->Class; type != nullptr; type = type->GetSuperClass()) {
        if (type == &AR6StairVolume::PrivateStaticClass) {
            this->m_iIsInStairVolume |= 0x10;
            break;
        }
    }
    float& signedStairOffset = frame.signedStairOffset;
    signedStairOffset = 0.0f;
    NativeCheckResult32& hitWords = frame.hitWords;
    hitWords.nextAddress = 0;
    hitWords.actorAddress = 0;
    for (int i = 2; i != 9; ++i)
        reinterpret_cast<uint*>(&hitWords)[i] = 0;
    reinterpret_cast<uint&>(hitWords.Time) = 0x3f800000;
    reinterpret_cast<uint&>(hitWords.Item) = 0xffffffff;
    hitWords.materialAddress = 0;
    FCheckResult* hit = reinterpret_cast<FCheckResult*>(&hitWords); // Retained across four later trace sites.
    if (retainedPoseOnly == 0) {
        box = this->m_collisionBox;
        uint radiusWord = reinterpret_cast<uint&>(box->CollisionRadius);
        ((FVector*)frame.extentWords)->Y = (float)(float10)box->CollisionRadius;
        frame.extentWords[0] = radiusWord;
        float10 startZ = (float10)this->m_fProneHeight;
        uint extentX = frame.extentWords[0];
        startZ += this->Location.Z;
        FVector& start = *(FVector*)frame.startWords;
        frame.startWords[0] = reinterpret_cast<uint&>(box->Location.X);
        frame.startWords[1] = reinterpret_cast<uint&>(box->Location.Y);
        uint originalBoxZ = reinterpret_cast<uint&>(box->Location.Z);
        uint startXWord = frame.startWords[0];
        uint extentY = frame.extentWords[1];
        frame.startWords[2] = originalBoxZ;
        start.Z = (float)startZ;
        float10 endZ = (float10)this->m_fProneHeight;
        endZ += endZ;
        frame.extentWords[2] = 0x3f800000;
        uint retainedExtentZ = frame.extentWords[2]; // Native EDI retains this through both probes.
        endZ = nativeFloatMinus8EPlus01 - endZ;
        endZ += start.Z;
        FVector& end = *(FVector*)frame.endWords;
        end.Y = (float)(float10)start.Y;
        frame.endWords[0] = startXWord;
        ULevel* floorLevel = this->XLevel;
        end.Z = (float)endZ;
        byte* floorTable = *(byte**)floorLevel;
        using FloorTrace = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*,
            uint, FVector);
        uint extentPacket[3] = {extentX, extentY, retainedExtentZ};
        (*(FloorTrace*)(floorTable + 0xcc))(floorLevel, hit, box,
            &end, &start, 0x2000df, *(FVector*)extentPacket);
        bool retry = hit->Actor == nullptr;
        if (!retry) {
            float10 zero = (float10)nativeFloatZero;
            retry = (float10)hit->Time == zero;
        }
        if (retry) {
            extentX = frame.extentWords[0];
            float10 retryZ = (float10)nativeFloatMinus4EPlus01;
            startXWord = frame.startWords[0];
            retryZ = -retryZ;
            retryZ += start.Z;
            float10 retryY = (float10)start.Y;
            FVector& retryStart = *(FVector*)frame.targetWords;
            retryStart.Y = (float)retryY;
            extentY = frame.extentWords[1];
            retryStart.Z = (float)retryZ;
            box = this->m_collisionBox;
            frame.targetWords[0] = startXWord;
            floorLevel = this->XLevel;
            floorTable = *(byte**)floorLevel;
            extentPacket[0] = extentX; extentPacket[1] = extentY; extentPacket[2] = retainedExtentZ;
            (*(FloorTrace*)(floorTable + 0xcc))(floorLevel, hit, box,
                &end, &retryStart, 0x2000df, *(FVector*)extentPacket);
            if (hit->Actor == nullptr) {
                finish();
                return;
            }
            float10 zero = (float10)nativeFloatZero;
            if ((float10)hit->Time == zero) {
                finish();
                return;
            }
        }
        float10 desiredZ = (float10)hit->Location.Z;
        box = this->m_collisionBox;
        desiredZ += this->m_fProneHeight;
        hit->Location.Z = (float)desiredZ;
        uint desiredXWord = reinterpret_cast<uint&>(box->Location.X);
        uint desiredYWord = reinterpret_cast<uint&>(box->Location.Y);
        frame.targetWords[2] = reinterpret_cast<uint&>(box->Location.Z);
        frame.targetWords[2] = reinterpret_cast<uint&>(hit->Location.Z);
        int retainedTestMove = testMove;
        frame.targetWords[0] = desiredXWord;
        frame.targetWords[1] = desiredYWord;
        FVector& desired = *(FVector*)frame.targetWords;
        if (retainedTestMove != 0) {
            float10 currentX = (float10)box->Location.X;
            uint savedXWord = reinterpret_cast<uint&>(box->Location.X);
            float10 targetX = (float10)desired.X;
            frame.extentWords[0] = savedXWord;
            bool same = targetX == currentX;
            uint savedYWord = reinterpret_cast<uint&>(box->Location.Y);
            uint savedZWord = reinterpret_cast<uint&>(box->Location.Z);
            frame.extentWords[2] = savedZWord;
            frame.extentWords[1] = savedYWord;
            if (same) {
                float10 currentY = (float10)box->Location.Y;
                same = (float10)desired.Y == currentY;
            }
            if (same) {
                float10 currentZ = (float10)box->Location.Z;
                same = (float10)hit->Location.Z == currentZ;
            }
            bool success = same;
            if (!same) {
                ULevel* moveLevel = this->XLevel;
                byte* moveTable = *(byte**)moveLevel;
                uint targetYWord = frame.targetWords[1];
                uint targetZWord = frame.targetWords[2];
                uint moveWords[3] = {desiredXWord, targetYWord, targetZWord};
                using TestMove = int (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
                success = (*(TestMove*)(moveTable + 0x9c))(moveLevel, box,
                    *(FVector*)moveWords, 1, 0, 1, 1) != 0;
                if (success)
                    desiredXWord = frame.targetWords[0];
            }
            if (success) {
                uint* output = (uint*)movedLocation;
                uint targetYWord = frame.targetWords[1];
                uint targetZWord = frame.targetWords[2];
                output[0] = desiredXWord;
                output[1] = targetYWord;
                output[2] = targetZWord;
            }
            box = this->m_collisionBox;
            float10 savedX = (float10)((FVector*)frame.extentWords)->X;
            same = (float10)box->Location.X == savedX;
            if (same) {
                float10 savedY = (float10)((FVector*)frame.extentWords)->Y;
                same = (float10)box->Location.Y == savedY;
            }
            if (same) {
                float10 savedZ = (float10)((FVector*)frame.extentWords)->Z;
                same = (float10)box->Location.Z == savedZ;
            }
            if (!same && (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(box) + 0xa8) & 0x800U) != 0) {
                ULevel* hashLevel = this->XLevel;
                void* hash = *(void**)((byte*)hashLevel + 0xf0);
                if (hash != nullptr) {
                    byte* hashTable = *(byte**)hash;
                    using HashOperation = void (__thiscall*)(void*, AActor*);
                    (*(HashOperation*)(hashTable + 0xc))(hash, box);
                    AR6ColBox* restoreBox = this->m_collisionBox;
                    uint restoreX = frame.extentWords[0];
                    uint restoreY = frame.extentWords[1];
                    reinterpret_cast<uint&>(restoreBox->Location.X) = restoreX;
                    uint restoreZ = frame.extentWords[2];
                    reinterpret_cast<uint&>(restoreBox->Location.Y) = restoreY;
                    reinterpret_cast<uint&>(restoreBox->Location.Z) = restoreZ;
                    hashLevel = this->XLevel;
                    hash = *(void**)((byte*)hashLevel + 0xf0);
                    AR6ColBox* addBox = this->m_collisionBox;
                    hashTable = *(byte**)hash; // Native assumes the post-removal hash remains nonnull.
                    (*(HashOperation*)(hashTable + 8))(hash, addBox);
                }
            }
            finish();
            return;
        }
        float10 heightDifference = (float10)hit->Location.Z - box->Location.Z;
        bool update = heightDifference > nativeFloatHalf;
        if (!update) {
            update = heightDifference < nativeFloatMinus0Point5;
            if (!update)
                update = forceUpdate != 0;
        }
        if (update) {
            float10 z = (float10)hit->Location.Z - box->Location.Z;
            float10 y = (float10)desired.Y;
            // Incoming test flag becomes the full-width move-result word.
            uint& movedWord = reinterpret_cast<uint&>(testMove);
            movedWord = 0;
            y -= box->Location.Y;
            float10 x = (float10)desired.X - box->Location.X;
            ((FVector*)frame.extentWords)->X = (float)x;
            uint stepX = frame.extentWords[0];
            ((FVector*)frame.extentWords)->Y = (float)y;
            uint stepY = frame.extentWords[1];
            ((FVector*)frame.extentWords)->Z = (float)z;
            uint stepZ = frame.extentWords[2];
            uint stepWords[3] = {stepX, stepY, stepZ};
            if (box->AR6ColBox::CanStepUp(*(FVector*)stepWords) != 0) {
                ULevel* moveLevel = this->XLevel;
                byte* moveTable = *(byte**)moveLevel;
                uint targetZWord = frame.targetWords[2];
                AR6ColBox* moveBox = this->m_collisionBox;
                uint targetWords[3] = {desiredXWord, desiredYWord, targetZWord};
                using Move = uint (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
                uint result = (*(Move*)(moveTable + 0x9c))(moveLevel, moveBox,
                    *(FVector*)targetWords, 0, 0, 1, 1);
                movedWord = result;
                if (result != 0) {
                    uint* output = (uint*)movedLocation;
                    uint targetYWord = frame.targetWords[1];
                    output[0] = desiredXWord;
                    output[1] = targetYWord;
                    output[2] = targetZWord;
                }
            }
            AR6ColBox* secondBox = this->m_collisionBox2;
            if (secondBox != nullptr &&
                (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(secondBox) + 0xa8) & 0x800U) != 0) {
                uint moved = movedWord;
                if (moved != 0 || forceUpdate != 0) {
                    uint secondXWord = reinterpret_cast<uint&>(secondBox->Location.X);
                    uint secondYWord = reinterpret_cast<uint&>(secondBox->Location.Y);
                    frame.extentWords[2] = reinterpret_cast<uint&>(secondBox->Location.Z);
                    AR6ColBox* primaryBox = this->m_collisionBox;
                    float10 secondZ = (float10)primaryBox->Location.Z;
                    ULevel* moveLevel = this->XLevel;
                    secondZ += secondZ;
                    secondZ -= this->Location.Z;
                    frame.extentWords[1] = secondYWord;
                    uint packetYWord = frame.extentWords[1];
                    ((FVector*)frame.extentWords)->Z = (float)secondZ;
                    byte* moveTable = *(byte**)moveLevel;
                    uint packetZWord = frame.extentWords[2];
                    uint targetWords[3] = {secondXWord, packetYWord, packetZWord};
                    using Move = uint (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
                    (*(Move*)(moveTable + 0x9c))(moveLevel, secondBox, *(FVector*)targetWords, 0, 1, 1, 1);
                    secondBox = this->m_collisionBox2;
                    primaryBox = this->m_collisionBox;
                    secondBox->RelativeLocation.Z = (float)((float10)secondBox->Location.Z - primaryBox->Location.Z);
                }
            }
        }
        box = this->m_collisionBox;
        float10 relativeZ = (float10)box->Location.Z;
        relativeZ -= this->Location.Z;
        box->RelativeLocation.Z = (float)relativeZ;
    }
    const FVector* pawnLocation = &this->Location;
    uint pawnXWord = reinterpret_cast<const uint&>(pawnLocation->X);
    uint pawnYWord = reinterpret_cast<const uint&>(pawnLocation->Y);
    uint pawnZWord = reinterpret_cast<const uint&>(pawnLocation->Z);
    frame.targetWords[1] = pawnYWord;
    frame.targetWords[0] = pawnXWord;
    box = this->m_collisionBox;
    frame.targetWords[2] = pawnZWord;
    frame.extentWords[0] = reinterpret_cast<uint&>(box->Location.X);
    uint boxYWord = reinterpret_cast<uint&>(box->Location.Y);
    frame.extentWords[2] = reinterpret_cast<uint&>(box->Location.Z);
    uint entryStairFlags = reinterpret_cast<uint&>(this->m_iIsInStairVolume);
    frame.extentWords[1] = boxYWord;
    FVector& pawnPosition = *(FVector*)frame.targetWords;
    FVector& boxPosition = *(FVector*)frame.extentWords;
    // Incoming output pointer becomes floating-point scratch.
    float& poseScratch = reinterpret_cast<float&>(movedLocation);
    float10 adjustedBoxZ;
    if (entryStairFlags != 0) {
        float10 correction = ABS((float10)box->Location.Z - this->Location.Z);
        correction *= nativeFloat0Point33333334;
        poseScratch = (float)correction;
        adjustedBoxZ = (float10)boxPosition.Z - poseScratch;
        float10 currentPawnZ = (float10)this->Location.Z;
        if (currentPawnZ > box->Location.Z) {
            signedStairOffset = (float)(-(float10)poseScratch);
            pawnPosition.X = (float)((float10)pawnPosition.X - poseScratch);
            pawnPosition.Y = (float)((float10)pawnPosition.Y - poseScratch);
            pawnPosition.Z = (float)((float10)pawnPosition.Z - poseScratch);
        }
    } else {
        adjustedBoxZ = (float10)boxPosition.Z;
    }
    float10 directionZ = adjustedBoxZ - pawnPosition.Z;
    float10 directionY = (float10)boxPosition.Y - pawnPosition.Y;
    float10 directionX = (float10)boxPosition.X - pawnPosition.X;
    FVector& boxDirection = *(FVector*)frame.directionWords;
    boxDirection.X = (float)directionX;
    boxDirection.Y = (float)directionY;
    boxDirection.Z = (float)directionZ;
    boxDirection.Normalize();
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    int& pelvisYaw = reinterpret_cast<int&>(frame.extentWords[1]);
    float10 absoluteZ = (float10)boxDirection.Z;
    pelvisYaw = 0;
    absoluteZ = ABS(absoluteZ);
    frame.extentWords[2] = 0;
    poseScratch = (float)absoluteZ;
    if (absoluteZ > nativeFloat0Point01) {
        float10 directionZ = (float10)boxDirection.Z;
        float10 zero = (float10)nativeFloatZero;
        if (directionZ > zero) {
            pelvisYaw = truncateLowWord((float10)boxDirection.Z * nativeFloat2EPlus04);
            if ((float10)pelvisYaw > nativeFloat8EPlus03)
                pelvisYaw = 8000;
        } else {
            float10 angle = (float10)poseScratch * nativeFloat2EPlus04;
            angle *= boxDirection.Z;
            pelvisYaw = truncateLowWord(angle);
            if ((float10)pelvisYaw < nativeFloatMinus8EPlus03)
                pelvisYaw = -8000;
        }
    }
    float10 half = (float10)this->CollisionRadius;
    uint currentYaw = reinterpret_cast<uint&>(this->Rotation.Yaw);
    half *= nativeFloatHalf;
    uint sideYaw = currentYaw + 0x3fffU;
    float& halfRadius = reinterpret_cast<float&>(testMove);
    halfRadius = (float)half;
    FRotator& sideRotation = *(FRotator*)frame.rotationWords;
    float10 radius = (float10)this->CollisionRadius;
    frame.scratchWords[2] = 0;
    radius -= halfRadius;
    frame.scratchWords[1] = 0;
    frame.scratchWords[0] = 0;
    sideRotation.Pitch = 0;
    poseScratch = (float)radius;
    sideRotation.Roll = 0;
    reinterpret_cast<uint&>(sideRotation.Yaw) = sideYaw;
    float& probeRadius = poseScratch;
    FVector& vectorStorage = *(FVector*)frame.endWords;
    FVector* side = &(vectorStorage = sideRotation.Vector());
    float10 probeZ = (float10)probeRadius * side->Z;
    frame.productY = (float)((float10)probeRadius * side->Y);
    vectorStorage.X = (float)((float10)probeRadius * side->X);
    probeZ += pawnLocation->Z;
    float10 liveProbeY = (float10)frame.productY + pawnLocation->Y;
    float10 liveProbeX = (float10)vectorStorage.X + pawnLocation->X;
    FVector& start = *(FVector*)frame.startWords;
    FVector& firstHit = *(FVector*)frame.sideWords; // First probe start, then first hit snapshot.
    start.X = (float)liveProbeX;
    uint firstXWord = frame.startWords[0];
    frame.sideWords[0] = firstXWord;
    start.Y = (float)liveProbeY;
    frame.sideWords[1] = frame.startWords[1];
    start.Z = (float)probeZ;
    frame.sideWords[2] = frame.startWords[2];
    float10 endZ = (float10)firstHit.Z - nativeFloat8EPlus01;
    ULevel* sideLevel = this->XLevel;
    float10 endY = (float10)firstHit.Y;
    frame.endWords[0] = firstXWord;
    vectorStorage.Y = (float)endY;
    vectorStorage.Z = (float)endZ;
    byte* sideTable = *(byte**)sideLevel;
    const uint* zero = *(const uint**)&FVectorFVector0Import;
    uint zeroX = zero[0];
    uint zeroY = zero[1];
    uint zeroZ = zero[2];
    ULevel* sideReceiver = this->XLevel;
    using SideTrace = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    uint zeroPacket[3] = {zeroX, zeroY, zeroZ};
    (*(SideTrace*)(sideTable + 0xcc))(sideReceiver, hit, this,
        &vectorStorage, &firstHit, 0x2000df, *(FVector*)zeroPacket);
    if (hit->Actor == nullptr) {
        finish();
        return;
    }
    uint firstHitX = reinterpret_cast<uint&>(hit->Location.X);
    float10 nextRadius = (float10)this->CollisionRadius;
    uint firstHitY = reinterpret_cast<uint&>(hit->Location.Y);
    nextRadius -= halfRadius;
    uint firstHitZ = reinterpret_cast<uint&>(hit->Location.Z);
    frame.sideWords[0] = firstHitX;
    uint currentSideYaw = reinterpret_cast<uint&>(this->Rotation.Yaw);
    frame.sideWords[1] = firstHitY;
    frame.sideWords[2] = firstHitZ;
    uint secondYaw = currentSideYaw - 0x3fffU;
    probeRadius = (float)nextRadius;
    reinterpret_cast<uint&>(sideRotation.Yaw) = secondYaw;
    side = &(vectorStorage = sideRotation.Vector());
    probeZ = (float10)probeRadius * side->Z;
    halfRadius = (float)((float10)probeRadius * side->Y); // Incoming test word becomes the rounded Y product.
    vectorStorage.X = (float)((float10)probeRadius * side->X);
    probeZ += pawnLocation->Z;
    liveProbeY = (float10)halfRadius + pawnLocation->Y;
    liveProbeX = (float10)vectorStorage.X + pawnLocation->X;
    vectorStorage.X = (float)liveProbeX;
    frame.startWords[0] = frame.endWords[0];
    vectorStorage.Y = (float)liveProbeY;
    uint secondYWord = frame.endWords[1];
    sideLevel = this->XLevel;
    vectorStorage.Z = (float)probeZ;
    uint secondZWord = frame.endWords[2];
    frame.startWords[1] = secondYWord;
    uint secondXWord = frame.startWords[0];
    frame.startWords[2] = secondZWord;
    endZ = (float10)start.Z - nativeFloat8EPlus01;
    frame.endWords[0] = secondXWord;
    endY = (float10)start.Y;
    zero = *(const uint**)&FVectorFVector0Import;
    vectorStorage.Y = (float)endY;
    vectorStorage.Z = (float)endZ;
    zeroX = zero[0];
    sideTable = *(byte**)sideLevel;
    zeroY = zero[1];
    zeroZ = zero[2];
    zeroPacket[0] = zeroX; zeroPacket[1] = zeroY; zeroPacket[2] = zeroZ;
    (*(SideTrace*)(sideTable + 0xcc))(sideLevel, hit, this,
        &vectorStorage, &start, 0x2000df, *(FVector*)zeroPacket);
    if (hit->Actor == nullptr) {
        finish();
        return;
    }
    uint secondHitZ = reinterpret_cast<uint&>(hit->Location.Z);
    float10 acrossZ = (float10)firstHit.Z;
    uint secondHitY = reinterpret_cast<uint&>(hit->Location.Y);
    uint secondHitX = reinterpret_cast<uint&>(hit->Location.X);
    frame.startWords[2] = secondHitZ;
    acrossZ -= start.Z;
    float10 acrossY = (float10)firstHit.Y;
    frame.startWords[1] = secondHitY;
    acrossY -= start.Y;
    frame.startWords[0] = secondHitX;
    float10 acrossX = (float10)firstHit.X - start.X;
    FVector& acrossFloor = *(FVector*)frame.scratchWords;
    vectorStorage.X = (float)acrossX;
    frame.scratchWords[0] = frame.endWords[0];
    vectorStorage.Y = (float)acrossY;
    frame.scratchWords[1] = frame.endWords[1];
    vectorStorage.Z = (float)acrossZ;
    frame.scratchWords[2] = frame.endWords[2];
    acrossFloor.Normalize();
    int pelvisRoll = truncateLowWord((float10)acrossFloor.Z * nativeFloat2EPlus04);
    UMesh* mesh = this->Mesh;
    if (mesh == nullptr) {
        finish();
        return;
    }
    USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(this));
    uint boneYawWord = frame.extentWords[1];
    struct BonePacketView { // Inferred outgoing stack packet, EBP-0xd8..-0xc0; FName constructs in its first word.
        uint nameWord;
        FRotator rotation;
        int space;
        float alpha, time;
    } bonePacket;
    bonePacket.time = 0.0f;
    bonePacket.alpha = 1.0f;
    bonePacket.space = 0;
    bonePacket.rotation.Pitch = 0;
    reinterpret_cast<uint&>(bonePacket.rotation.Yaw) = boneYawWord;
    bonePacket.nameWord = (uint)&bonePacket.rotation;
    bonePacket.rotation.Roll = pelvisRoll;
    *(FName**)&movedLocation = (FName*)&bonePacket.nameWord;
    // L"r6 pelvis".
    ::new (reinterpret_cast<void*>(&bonePacket.nameWord)) FName(nativeTextR6Pelvis, static_cast<EFindName>(1));
    instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(bonePacket.nameWord), bonePacket.rotation,
        bonePacket.space, bonePacket.alpha, bonePacket.time);
    if (poseOnly != 0) {
        finish();
        return;
    }
    AR6ColBox* pivotBox = this->m_collisionBox;
    float10 gap = ABS((float10)this->Location.Z - pivotBox->Location.Z);
    float10 gapLimit = (float10)nativeFloat5EPlus01;
    if (gap > gapLimit)
        gap = (float10)nativeFloat5EPlus01;
    int stairFlags = this->m_iIsInStairVolume;
    float10 stairOffset = (float10)signedStairOffset;
    if ((stairFlags & 1) != 0)
        stairOffset -= nativeFloat7;
    if ((stairFlags & 0x10) != 0)
        stairOffset -= nativeFloat7;
    float10 pivot = gap * boxDirection.Z;
    pivot += nativeFloat5EPlus01;
    pivot *= boxDirection.Z;
    pivot += this->m_vPrePivotProneBackup.Z;
    pivot = stairOffset + pivot;
    float10 spreadScale = (float10)(stairFlags == 0 ? nativeFloat1EPlus01 : nativeFloatMinus5);
    float10 pivotAcrossZ = (float10)acrossFloor.Z;
    int currentForce = forceUpdate;
    pivot += ABS(pivotAcrossZ) * spreadScale;
    bool stampOnly = currentForce != 0;
    if (!stampOnly)
        stampOnly = !(ABS((float10)this->PrePivot.Z - pivot) > nativeFloatHalf);
    if (stampOnly) {
        auto* levelInfo = this->Level;
        reinterpret_cast<uint&>(this->m_fPrePivotLastUpdate) = reinterpret_cast<uint&>(levelInfo->TimeSeconds);
    } else {
        poseScratch = (float)pivot;
        float10 zero = (float10)nativeFloatZero;
        float10 lastUpdate = (float10)this->m_fPrePivotLastUpdate;
        if (lastUpdate == zero) {
            auto* levelInfo = this->Level;
            this->m_fPrePivotLastUpdate = (float)((float10)levelInfo->TimeSeconds - nativeFloat0Point1);
        }
        bool stationary = true;
        for (int axis = 0; axis != 3; ++axis) {
            zero = (float10)nativeFloatZero;
            float10 velocity = (float10)((float*)&this->Velocity)[axis];
            if (velocity != zero) {
                stationary = false;
                break;
            }
        }
        if (stationary) {
            for (int axis = 0; axis != 3; ++axis) {
                uint current = ((uint*)&this->Rotation)[axis];
                uint desired = ((uint*)&this->DesiredRotation)[axis];
                if (current != desired) {
                    stationary = false;
                    break;
                }
            }
        }
        if (stationary)
            stationary = this->RotationRate.Roll == 0;
        if (stationary) {
            auto* levelInfo = this->Level;
            reinterpret_cast<uint&>(this->m_fPrePivotLastUpdate) = reinterpret_cast<uint&>(levelInfo->TimeSeconds);
        }
        auto* levelInfo = this->Level;
        float10 now = (float10)levelInfo->TimeSeconds;
        uint nowWord = reinterpret_cast<uint&>(levelInfo->TimeSeconds);
        float10 elapsed = now - this->m_fPrePivotLastUpdate;
        reinterpret_cast<uint&>(this->m_fPrePivotLastUpdate) = nowWord;
        float10 rate = (float10)(stairFlags < 2 ? nativeFloat16 : nativeFloat32);
        bool rotating = false;
        for (int axis = 0; axis != 3; ++axis) {
            uint current = ((uint*)&this->Rotation)[axis];
            uint desired = ((uint*)&this->DesiredRotation)[axis];
            if (current != desired) {
                rotating = true;
                break;
            }
        }
        if (!rotating)
            rotating = this->RotationRate.Roll > 0;
        if (rotating)
            rate += rate;
        float10 currentPivot = (float10)this->PrePivot.Z;
        float10 desiredPivot = (float10)poseScratch;
        float10 comparisonPivot = (float10)this->PrePivot.Z;
        bool increasing = desiredPivot > comparisonPivot;
        float10 step = rate * elapsed;
        uint desiredWord = reinterpret_cast<uint&>(movedLocation);
        if (increasing) {
            signedStairOffset = (float)(step + currentPivot); // Reuses EBP-0x44 for the rounded candidate.
            uint candidateWord = reinterpret_cast<uint&>(signedStairOffset);
            pivot = ClampFloatOrdered(reinterpret_cast<float&>(candidateWord), reinterpret_cast<float&>(candidateWord),
                reinterpret_cast<float&>(desiredWord));
        } else {
            signedStairOffset = (float)(currentPivot - step);
            uint candidateWord = reinterpret_cast<uint&>(signedStairOffset);
            pivot = ClampFloatOrdered(reinterpret_cast<float&>(candidateWord), reinterpret_cast<float&>(desiredWord),
                reinterpret_cast<float&>(candidateWord));
        }
    }
    byte* pawnVtable = *(byte**)this;
    ((FVector*)frame.targetWords)->Z = (float)pivot;
    frame.targetWords[0] = 0;
    uint pivotXWord = frame.targetWords[0];
    frame.targetWords[1] = 0;
    uint pivotYWord = frame.targetWords[1];
    uint pivotZWord = frame.targetWords[2];
    uint pivotWords[3] = {pivotXWord, pivotYWord, pivotZWord};
    using SetPrePivot = void (__thiscall*)(AR6Pawn*, FVector);
    (*(SetPrePivot*)(pawnVtable + 0x18c))(this, *(FVector*)pivotWords);
    finish();
}

// R6Engine.dll @ 100294b5 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnUpdateColBoxCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0xb0]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x9c]
        push eax
        mov dword ptr [ebp-0x9c],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100294d2 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnUpdateColBoxCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUpdateColBox // L"AR6Pawn::UpdateColBox".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044610 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void UpdateColBoxExceptionHandler(void)
{
    __asm {
        mov eax,offset UpdateColBoxFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100294f0 : AR6Pawn::BeginTouch
// Forwards touches to AActor, suppressing door touches when the actors no longer overlap.
void __thiscall AR6Pawn::BeginTouch(AActor* other)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &BeginTouchExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* retainedOther = other;
    UClass* type = retainedOther->Class; // Read before state 0, including an unchecked null actor.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    while (type != nullptr && type != &AR6Door::PrivateStaticClass)
        type = type->GetSuperClass();
    bool notifyBase = type == nullptr;
    if (!notifyBase) {
        notifyBase = this->AActor::IsOverlapping(retainedOther, nullptr) != 0;
    }
    if (notifyBase) {
        // Current import, retained EDI actor.
        this->AActor::BeginTouch(retainedOther);
    }
    ExceptionList = frame.previousExceptionList; // Void return, RET 4.
}

// R6Engine.dll @ 1002955b : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnAR6PawnSharedConstructionCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002956f : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnAR6PawnSharedConstructionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnBeginTouch // L"AR6Pawn::BeginTouch".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044620 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void BeginTouchExceptionHandler(void)
{
    __asm {
        mov eax,offset BeginTouchFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10029ac0 : AR6Pawn::execGetMaxRotationOffset
// Consumes optional DebugInfo, selects the prone rotation limit, and writes its integer result.
void __thiscall AR6Pawn::execGetMaxRotationOffset(FFrame& stack, void* result)
{
    FFrame* frame = &stack;
    byte* code = frame->Code;
    code = (byte*)((uint)code + 1U);
    frame->Code = code;
    if (*code == 0x42) {
        code = (byte*)((uint)code + 1U);
        frame->Code = code;
        UObject* expressionReceiver = frame->Object;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
        ScriptNative debugInfo = natives[0x42];
        debugInfo(expressionReceiver, frame, nullptr);
    }
    // WantsToProne/IsProne, sampled after DebugInfo.
    uint proneFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3e0);
    int useWeaponLimit = (proneFlags & 0x300U) != 0 ? 1 : 0;
    int offset = this->AR6Pawn::getMaxRotationOffset(useWeaponLimit);
    int* output = (int*)result; // Current incoming result pointer loads after the native leaf returns.
    *output = offset; // FPO void return, RET 8; no exception-chain access.
}

// R6Engine.dll @ 10029b20 : AR6Pawn::UpdateColBoxPeeking
// Moves the lateral collision box with retries, updates its relative offset and retains an accepted peeking limit.
float10 __thiscall AR6Pawn::UpdateColBoxPeeking(float requestedPeeking)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x8c/-0x88/-0x84.
        uint coordinateWords[12]; // EBP-0x80..-0x54, shared ToLocal hidden FCoords output.
        FRotator sideRotation; // EBP-0x50/-0x4c/-0x48.
        uint vectorWords[3]; // EBP-0x44/-0x40/-0x3c, vector output and rounded products.
        FVector target; // EBP-0x38/-0x34/-0x30.
        uint caught, rethrow; // EBP-0x2c/-0x28.
        float offsetY, offsetZ; // EBP-0x24/-0x20, subsequently reused.
        int originallyActive; // EBP-0x1c, a full DWORD.
        float ratio; // EBP-0x18, explicitly rounded after normalization.
        int needsCorrection; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &UpdateColBoxPeekingExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    const uint* postureFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0x6c4);
    uint flags = *postureFlagWord;
    bool postureTransition = (flags & 0x40000000U) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](float10 value) { ExceptionList = frame.previousExceptionList; return value; };
    if (postureTransition && (flags & 0x02000000U) == 0)
        return finish(nativeFloat1EPlus03); // 1000; no LastValidPeeking write on this exit.
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x300U) != 0 ||
        this->m_collisionBox == nullptr || postureTransition)
        return finish(requestedPeeking);
    FRotator& sideRotation = frame.sideRotation;
    uint pitch = reinterpret_cast<uint&>(this->Rotation.Pitch);
    uint yaw = reinterpret_cast<uint&>(this->Rotation.Yaw);
    uint roll = reinterpret_cast<uint&>(this->Rotation.Roll);
    sideRotation.Pitch = (int)pitch;
    uint requestedWord = reinterpret_cast<uint&>(requestedPeeking);
    sideRotation.Roll = (int)roll;
    int& needsCorrection = frame.needsCorrection;
    int& originallyActive = frame.originallyActive;
    needsCorrection = 0;
    originallyActive = 1;
    sideRotation.Yaw = (int)(yaw + 16000U);
    float& ratio = frame.ratio;
    ratio = (float)this->AR6Pawn::GetPeekingRatioNorm(reinterpret_cast<float&>(requestedWord));
    uint ratioWord = reinterpret_cast<uint&>(ratio);
    reinterpret_cast<uint&>(ratio) = ratioWord;
    FVector& directionStorage = *(FVector*)frame.vectorWords;
    FVector* direction = &(directionStorage = sideRotation.Vector());
    float10 scaledZ = (float10)ratio * direction->Z;
    float10 scaledY = (float10)ratio * direction->Y;
    directionStorage.X = (float)((float10)ratio * direction->X); // X spills before multiplying by 56.
    frame.offsetZ = (float)(scaledZ * nativeFloat56);
    frame.offsetY = (float)(scaledY * nativeFloat56);
    directionStorage.X = (float)((float10)directionStorage.X * nativeFloat56);
    float10 targetZ = (float10)frame.offsetZ + this->Location.Z;
    float10 targetY = (float10)frame.offsetY + this->Location.Y;
    float10 targetX = (float10)directionStorage.X + this->Location.X;
    FVector& target = frame.target;
    directionStorage.X = (float)targetX;
    uint retainedTargetX = frame.vectorWords[0];
    ((uint*)&target)[0] = retainedTargetX;
    directionStorage.Y = (float)targetY;
    ((uint*)&target)[1] = frame.vectorWords[1];
    directionStorage.Z = (float)targetZ;
    uint initialTargetZ = frame.vectorWords[2];
    float10 top = this->CollisionHeight;
    ((uint*)&target)[2] = initialTargetZ;
    top += this->Location.Z;
    AR6ColBox* secondBox = this->m_collisionBox2;
    target.Z = (float)(top - nativeFloat26); // The rounded side-vector Z is overwritten by top minus 26.
    if (secondBox != nullptr && (reinterpret_cast<byte*>(secondBox)[0x394] & 1U) != 0) {
        if (this->APawn::IsLocallyControlled() != 0 || this->Level->NetMode != 3)
            this->m_collisionBox2->AR6ColBox::EnableCollision(0, 0, 0);
    }
    AR6ColBox* box = this->m_collisionBox;
    if ((reinterpret_cast<byte*>(box)[0x394] & 1U) == 0) {
        if (this->APawn::IsLocallyControlled() == 0 && this->Level->NetMode == 3)
            return finish(requestedPeeking); // Reread the incoming slot after the callback.
        if (this->m_Ladder == nullptr || (reinterpret_cast<const byte*>(postureFlagWord)[0] & 4U) == 0)
            this->m_collisionBox->AR6ColBox::EnableCollision(1, 0, 0);
        box = this->m_collisionBox;
        if (box->Owner == nullptr) {
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf(nativeTextWARNINGAR6ColBoxEnableCollisionOwnerIsNullInUpdateColBoxPeeking);
            return finish(requestedPeeking); // Vararg member receiver is passed on the stack.
        }
        box->AActor::SetCollisionSize(28.0f, 26.0f);
        originallyActive = 0; // Clear the full DWORD only after the callback returns.
    }
    // Local packet view describes the existing by-value FVector and four native DWORD flags.
    struct MovePacket { AActor* actor; uint x, y, z; int flag0, flag1, flag2, flag3; } packet;
    using FarMoveWords = int (__thiscall*)(ULevel*, AActor*, uint, uint, uint, int, int, int, int);
    auto moveWithPacket = [&](ULevel* level, byte* vtable) {
        return (*(FarMoveWords*)(vtable + 0x9c))(level, packet.actor, packet.x, packet.y, packet.z,
            packet.flag0, packet.flag1, packet.flag2, packet.flag3);
    };
    FVector& oldPosition = directionStorage; // EBP-0x44/-0x40/-0x3c; later becomes the delta/correction vector.
    box = this->m_collisionBox;
    packet.flag3 = 1;
    packet.flag2 = 1;
    packet.flag1 = 0;
    packet.flag0 = 0;
    uint oldX = ((uint*)&box->Location)[0];
    frame.vectorWords[0] = oldX;
    uint oldY = ((uint*)&box->Location)[1];
    uint oldZ = ((uint*)&box->Location)[2];
    packet.x = retainedTargetX; // Native EDI retains this across every earlier collision callback.
    uint targetYWord = ((uint*)&target)[1];
    frame.vectorWords[2] = oldZ;
    ULevel* level = this->XLevel;
    packet.y = targetYWord;
    uint targetZWord = ((uint*)&target)[2];
    frame.vectorWords[1] = oldY;
    byte* levelVtable = *(byte**)level;
    packet.actor = box;
    packet.z = targetZWord;
    int moved = moveWithPacket(level, levelVtable);
    box = this->m_collisionBox;
    bool atTarget = box->Location.X == target.X && box->Location.Y == target.Y && box->Location.Z == target.Z;
    if (!atTarget && this->m_ePeekingMode == 2)
        return finish(this->m_fLastValidPeeking); // Keep partial fluid movement; skip retry and relative update.
    if (originallyActive != 0 && moved == 0) {
        float10 restoredTop = this->CollisionHeight;
        oldX = frame.vectorWords[0];
        restoredTop += this->Location.Z;
        level = this->XLevel;
        levelVtable = *(byte**)level;
        oldPosition.Z = (float)(restoredTop - nativeFloat26);
        packet.x = oldX;
        packet.y = frame.vectorWords[1];
        oldZ = frame.vectorWords[2];
        packet.actor = box; // Retain the post-first-move receiver.
        needsCorrection = 1;
        packet.z = oldZ;
        packet.flag0 = 0;
        packet.flag1 = 0;
        packet.flag2 = 1;
        packet.flag3 = 1;
        moved = moveWithPacket(level, levelVtable);
    }
    box = this->m_collisionBox;
    float10 boxX = box->Location.X;
    int retainedCorrection = needsCorrection; // EBX survives the later reuse of EBP-0x14 for radial distance.
    if (boxX != (float10)target.X || box->Location.Y != target.Y || box->Location.Z != target.Z)
        retainedCorrection = 1; // Lazy unordered comparisons count as unequal.
    if (moved == 0) {
        float& radialOffset = reinterpret_cast<float&>(frame.needsCorrection);
        radialOffset = (float)((float10)this->CollisionRadius - nativeFloat28);
        if ((float10)ratio < nativeFloatZero)
            radialOffset = (float)((float10)radialOffset * nativeFloatMinus1);
        // Shared hidden output.
        direction = &(target = sideRotation.Vector());
        float10 radialZ = (float10)radialOffset * direction->Z;
        float10 radialY = (float10)radialOffset * direction->Y;
        frame.offsetY = (float)radialY;
        target.X = (float)((float10)radialOffset * direction->X);
        float10 positionZ = radialZ + this->Location.Z;
        float10 positionY = (float10)frame.offsetY + this->Location.Y;
        float10 positionX = (float10)target.X + this->Location.X;
        target.X = (float)positionX;
        packet.x = ((uint*)&target)[0];
        box = this->m_collisionBox;
        target.Y = (float)positionY;
        targetYWord = ((uint*)&target)[1];
        target.Z = (float)positionZ;
        targetZWord = ((uint*)&target)[2];
        float10 heightOffset = this->CollisionHeight;
        ((uint*)&target)[2] = targetZWord;
        heightOffset -= nativeFloat26;
        level = this->XLevel;
        levelVtable = *(byte**)level;
        packet.y = targetYWord;
        heightOffset += target.Z;
        packet.actor = box;
        target.Z = (float)heightOffset;
        packet.z = ((uint*)&target)[2];
        packet.flag0 = 0;
        packet.flag1 = 0;
        packet.flag2 = 1;
        packet.flag3 = 1;
        int radialMove = moveWithPacket(level, levelVtable);
        if (radialMove == 0) {
            float10 centerHeight = this->CollisionHeight;
            uint centerZ = reinterpret_cast<uint&>(this->Location.Z);
            centerHeight -= nativeFloat26;
            uint centerX = reinterpret_cast<uint&>(this->Location.X);
            uint centerY = reinterpret_cast<uint&>(this->Location.Y);
            ((uint*)&target)[2] = centerZ;
            centerHeight += target.Z;
            level = this->XLevel;
            levelVtable = *(byte**)level;
            target.Z = (float)centerHeight;
            packet.x = centerX;
            box = this->m_collisionBox;
            packet.y = centerY;
            packet.z = ((uint*)&target)[2];
            packet.actor = box;
            packet.flag0 = 0;
            packet.flag1 = 1;
            packet.flag2 = 1;
            packet.flag3 = 1;
            moveWithPacket(level, levelVtable);
            return finish(nativeFloat1EPlus03); // Ignore the final move result; do not update LastValidPeeking.
        }
        retainedCorrection = 1;
    }
    box = this->m_collisionBox;
    if (box->Location.X != oldPosition.X || box->Location.Y != oldPosition.Y || box->Location.Z != oldPosition.Z) {
        float10 deltaZ = box->Location.Z;
        byte* pawnVtable = *(byte**)this;
        deltaZ -= this->Location.Z;
        float10 deltaY = (float10)box->Location.Y - this->Location.Y;
        float10 deltaX = (float10)box->Location.X - this->Location.X;
        oldPosition.X = (float)deltaX;
        oldPosition.Y = (float)deltaY;
        oldPosition.Z = (float)deltaZ;
        using ToLocal = FCoords* (__thiscall*)(const AActor*, FCoords*);
        FCoords* local = (*(ToLocal*)(pawnVtable + 0xa4))(this, (FCoords*)frame.coordinateWords);
        const FVector* transformed = &(target = oldPosition.TransformVectorBy(*local));
        uint* relative = reinterpret_cast<uint*>(&this->m_collisionBox->RelativeLocation);
        relative[0] = reinterpret_cast<const uint&>(transformed->X);
        relative[1] = reinterpret_cast<const uint&>(transformed->Y);
        relative[2] = reinterpret_cast<const uint&>(transformed->Z); // Sequential word copies preserve overlap.
    }
    if (retainedCorrection == 0) {
        reinterpret_cast<uint&>(this->m_fLastValidPeeking) = reinterpret_cast<uint&>(requestedPeeking);
        return finish(requestedPeeking);
    }
    box = this->m_collisionBox;
    float10 firstZ = this->Location.Z;
    float10 sameZ = (float10)this->Location.Z - firstZ; // Reverse self-subtraction remains observable for NaN/infinity.
    oldX = ((uint*)&box->Location)[0];
    float10 pawnY = this->Location.Y;
    oldY = ((uint*)&box->Location)[1];
    oldZ = ((uint*)&box->Location)[2];
    frame.vectorWords[1] = oldY;
    float10 differenceY = pawnY - oldPosition.Y;
    float10 pawnX = this->Location.X;
    frame.vectorWords[0] = oldX;
    float10 differenceX = pawnX - oldPosition.X;
    frame.vectorWords[2] = oldZ;
    oldPosition.X = (float)differenceX;
    oldPosition.Y = (float)differenceY;
    oldPosition.Z = (float)sameZ;
    float10 size;
    using VectorSize = float10 (__thiscall*)(const FVector*);
    size = reinterpret_cast<VectorSize&>(FVectorSizeImport)(&oldPosition);
    requestedPeeking = (float)size; // Native FST32 overwrites EBP+8 without popping live ST0.
    if ((float10)ratio < nativeFloatZero)
        size *= nativeFloatMinus1;
    size *= nativeFloat0Point017857144;
    size *= nativeDouble1000;
    size += nativeDouble1000;
    float proposed = (float)size;
    float10 accepted = ClampFloatOrdered(proposed, 0.0f, 2000.0f);
    float10 changeMagnitude = (float10)this->m_fLastValidPeeking - accepted;
    __asm {
        fld tbyte ptr [changeMagnitude]
        fabs
        fstp tbyte ptr [changeMagnitude]
    }
    if (changeMagnitude > nativeFloat1EPlus02)
        this->m_fLastValidPeeking = (float)accepted; // Strict >100; equality/unordered retain the current cache.
    return finish(this->m_fLastValidPeeking);
}

// R6Engine.dll @ 1002a11d : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnUpdateColBoxPeekingCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x2c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x28]
        push ecx
        mov dword ptr [ebp-0x28],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002a131 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnUpdateColBoxPeekingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUpdateColBoxPeeking // L"AR6Pawn::UpdateColBoxPeeking".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044640 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void UpdateColBoxPeekingExceptionHandler(void)
{
    __asm {
        mov eax,offset UpdateColBoxPeekingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002a150 : AR6Pawn::AdjustMaxFluidPeeking
// Selects the directional peeking bound with ordered comparisons and side-specific fallback values.
float10 __thiscall AR6Pawn::AdjustMaxFluidPeeking(float value, float bound)
{
    uint peekingFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x3e4);
    float10 extendedValue = (float10)value;
    if ((peekingFlags & 0x80000000U) != 0) { // m_bPeekingLeft.
        if (extendedValue < (float10)bound)
            return (float10)bound;
        return (float10)value;
    }
    if (extendedValue < (float10)value) // Preserve the native self-comparison, including its unordered status.
        return (float10)value;
    if ((float10)value < (float10)bound)
        return (float10)value;
    return (float10)bound;
}

// R6Engine.dll @ 1002a1a0 : AR6Pawn::execFootStep
// Traces below a named bone, updates dirty-foot state, emits a decal and notifies the surface-switch event.
// Native ABI view retains the incoming frame word for the left-foot operand.
void __thiscall AR6Pawn::execFootStep(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0xbc/-0xb8/-0xb4.
        uint hitNormalWords[3]; // EBP-0xb0..-0xa8, uninitialized trace output.
        uint hitLocationWords[3]; // EBP-0xa4..-0x9c, uninitialized trace output.
        uint coordinateWords[12]; // EBP-0x98..-0x6c, hidden BoneCoords output.
        uint caught; // EBP-0x68.
        FVector traceEnd, traceStart, decalLocation; // EBP-0x64/-0x58/-0x4c.
        uint extentWords[3]; // EBP-0x40/-0x3c/-0x38.
        float decalY; // EBP-0x34.
        uint rethrow; // EBP-0x30.
        float decalX; // EBP-0x2c.
        uint boneNameWord; // EBP-0x28.
        float dirtyDuration; // EBP-0x24.
        uint durationWord; // EBP-0x20.
        uint originAndRotationWords[3]; // EBP-0x1c/-0x18/-0x14, later hidden OrthoRotation output.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &execFootStepExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = stack; // Retain the original pointer before its incoming slot becomes the required BOOL.
    using Expression = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = vmFrame->Code;
    uint& boneNameWord = frame.boneNameWord;
    boneNameWord = 0; // Required FName defaults to raw index 0 before reading the opcode.
    byte opcode = *code;
    vmFrame->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    Expression* natives = *(Expression**)&CoreGNativesImport;
    UObject* context = vmFrame->Object;
    frame.state = 0;
    natives[opcode](context, vmFrame, &boneNameWord);
    code = vmFrame->Code;
    context = vmFrame->Object;
    uint& leftFoot = reinterpret_cast<uint&>(stack);
    leftFoot = 0; // Required BOOL defaults after capturing the current Code and Object.
    opcode = *code;
    vmFrame->Code = code + 1;
    natives = *(Expression**)&CoreGNativesImport;
    natives[opcode](context, vmFrame, &leftFoot);
    code = vmFrame->Code + 1;
    vmFrame->Code = code;
    if (*code == 0x42) {
        context = vmFrame->Object;
        vmFrame->Code = code + 1;
        natives = *(Expression**)&CoreGNativesImport;
        natives[0x42](context, vmFrame, nullptr);
    }
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    UMesh* mesh = this->Mesh;
    if (mesh == nullptr) {
        finish();
        return;
    }
    UClass* type = mesh->Class;
    UClass* skeletalClass = USkeletalMeshPrivateStaticClassImport;
    while (type != nullptr && type != skeletalClass)
        type = type->GetSuperClass();
    if (type != skeletalClass) { // Native also accepts a null imported class when ancestry is exhausted.
        finish();
        return;
    }
    mesh = this->Mesh;
    mesh->MeshGetInstance(this); // Ignore return; reload MeshInstance below.
    int boneIndex = static_cast<USkeletalMeshInstance*>(this->MeshInstance)->USkeletalMeshInstance::MatchRefBone(
        reinterpret_cast<FName&>(boneNameWord));
    if (boneIndex < 0) {
        finish();
        return;
    }
    uint* coordinateWords = frame.coordinateWords;
    FCoords* coordinates = (FCoords*)coordinateWords;
    // Physical result view keeps the supplied buffer; the returned pointer is ignored.
    static_cast<USkeletalMeshInstance*>(this->MeshInstance)->USkeletalMeshInstance::GetBoneCoords(
        coordinates, (uint)boneIndex, 1);
    uint originZWord = coordinateWords[2]; // Ignore returned coords; use the supplied buffer in native Z/Y/X order.
    uint originYWord = coordinateWords[1];
    uint originXWord = coordinateWords[0];
    frame.originAndRotationWords[1] = originYWord;
    const uint* zero = *(const uint**)&FVectorFVector0Import;
    frame.originAndRotationWords[2] = originZWord;
    float& originZ = reinterpret_cast<float&>(frame.originAndRotationWords[2]);
    float10 endZ = (float10)originZ - nativeFloat5EPlus01;
    frame.originAndRotationWords[0] = originXWord;
    float10 originY = reinterpret_cast<float&>(frame.originAndRotationWords[1]);
    FVector& traceStart = frame.traceStart;
    ((uint*)&traceStart)[0] = originXWord;
    float& decalY = frame.decalY;
    decalY = (float)originY;
    float10 originX = reinterpret_cast<float&>(frame.originAndRotationWords[0]);
    float& decalX = frame.decalX;
    decalX = (float)originX;
    FVector& traceEnd = frame.traceEnd;
    traceEnd.X = (float)originX;
    traceEnd.Y = (float)originY;
    traceEnd.Z = (float)endZ;
    float10 startZ = (float10)originZ + nativeFloat1EPlus01;
    traceStart.Y = (float)(float10)reinterpret_cast<float&>(frame.originAndRotationWords[1]);
    traceStart.Z = (float)startZ;
    uint* extentWords = frame.extentWords;
    extentWords[0] = zero[0];
    extentWords[1] = zero[1];
    extentWords[2] = zero[2];
    uint* hitLocationWords = frame.hitLocationWords;
    uint* hitNormalWords = frame.hitNormalWords;
    UMaterial** hitMaterial = &this->m_HitMaterial;
    this->AActor::Trace(
        *reinterpret_cast<FVector*>(hitLocationWords), *reinterpret_cast<FVector*>(hitNormalWords), traceEnd,
        traceStart, 8, *reinterpret_cast<FVector*>(extentWords), hitMaterial); // Ignore return and output vectors.
    UMaterial* material = *hitMaterial;
    if (material != nullptr) {
        UClass* surfaceClass = material->m_pFootStep; // Material.m_pFootStep.
        UTexture* texture = nullptr;
        AR6FootStep* defaults = nullptr;
        uint& durationWord = frame.durationWord;
        float& dirtyDuration = frame.dirtyDuration;
        durationWord = 0;
        dirtyDuration = 0.0f;
        if (surfaceClass != nullptr) {
            defaults = static_cast<AR6FootStep*>(
                surfaceClass->UClass::GetDefaultActor());
            if (defaults == nullptr)
                goto notifySurface;
            if (leftFoot != 0) {
                texture = defaults->m_DecalLeftFootTexture;
                this->m_LeftDirtyFootStep = nullptr;
                if ((float10)defaults->m_fDirtyTime != nativeDouble0) {
                    this->m_LeftDirtyFootStep = (*hitMaterial)->m_pFootStep; // Current material class.
                    reinterpret_cast<uint&>(this->m_fLeftDirtyFootStepRemainingTime) =
                        reinterpret_cast<const uint&>(defaults->m_fDirtyTime);
                }
            } else {
                texture = defaults->m_DecalRightFootTexture;
                this->m_RightDirtyFootStep = nullptr;
                if ((float10)defaults->m_fDirtyTime != nativeDouble0) {
                    this->m_RightDirtyFootStep = (*hitMaterial)->m_pFootStep;
                    reinterpret_cast<uint&>(this->m_fRightDirtyFootStepRemainingTime) =
                        reinterpret_cast<const uint&>(defaults->m_fDirtyTime);
                }
            }
            // Zero dirty time clears the class but retains the old timer.
            durationWord = reinterpret_cast<const uint&>(defaults->m_fDuration);
        } else {
            if (leftFoot != 0) {
                UClass* dirtyClass = this->m_LeftDirtyFootStep;
                if (dirtyClass != nullptr) {
                    defaults = static_cast<AR6FootStep*>(
                        dirtyClass->UClass::GetDefaultActor());
                    if (defaults != nullptr) {
                        float10 dirtyTime = defaults->m_fDirtyTime;
                        uint dirtyLife = reinterpret_cast<const uint&>(defaults->m_fDurationDirty);
                        float10 elapsed = dirtyTime - this->m_fLeftDirtyFootStepRemainingTime;
                        texture = defaults->m_DecalLeftFootTextureDirty;
                        durationWord = dirtyLife;
                        dirtyDuration = (float)(elapsed / defaults->m_fDirtyTime * defaults->m_fDurationDirty);
                    }
                }
                if (leftFoot != 0)
                    goto emitDecal; // Preserve the native BOOL reload after the left-default path.
            }
            UClass* dirtyClass = this->m_RightDirtyFootStep;
            if (dirtyClass != nullptr) {
                defaults = static_cast<AR6FootStep*>(
                    dirtyClass->UClass::GetDefaultActor());
                if (defaults == nullptr)
                    goto notifySurface;
                float10 dirtyTime = defaults->m_fDirtyTime;
                texture = defaults->m_DecalRightFootTextureDirty;
                float10 elapsed = dirtyTime - this->m_fRightDirtyFootStepRemainingTime;
                uint dirtyLife = reinterpret_cast<const uint&>(defaults->m_fDurationDirty);
                dirtyDuration = (float)(elapsed / defaults->m_fDirtyTime * defaults->m_fDurationDirty);
                durationWord = dirtyLife;
            }
        }
    emitDecal:
        if (defaults != nullptr && texture != nullptr) {
            float10 decalZ = originZ;
            uint savedX = reinterpret_cast<uint&>(decalX);
            decalZ -= nativeFloat6;
            float10 savedY = decalY;
            FVector& location = frame.decalLocation;
            location.Y = (float)savedY;
            ((uint*)&location)[0] = savedX;
            location.Z = (float)decalZ;
            uint* rotationWords = frame.originAndRotationWords;
            // Ignore returned pointer.
            *reinterpret_cast<FRotator*>(rotationWords) = coordinates->OrthoRotation();
            uint yaw = rotationWords[1];
            uint dirtyWord = reinterpret_cast<uint&>(dirtyDuration);
            rotationWords[1] = yaw - 0x4000U;
            uint retainedDurationWord = durationWord;
            ALevelInfo* level = this->Level;
            rotationWords[0] = 0xc001; // Roll remains the supplied output's third word.
            AR6DecalManager* manager = level->m_DecalManager;
            manager->AR6DecalManager::AddDecal(
                &location, (FRotator*)rotationWords, texture, (eDecalType)0, 0,
                reinterpret_cast<float&>(retainedDurationWord), reinterpret_cast<float&>(dirtyWord), 25.0f, 0.0f, 0);
        }
    }
notifySurface:
    // Captured only after all trace/default/decal work.
    FName switchName = *(FName*)&R6ENGINE_PlaySurfaceSwitch;
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(switchName), 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    this->ProcessEvent(function, nullptr, nullptr);
    finish(); // RET 8; script result remains untouched and prior dirty-state writes are not rolled back.
}

// R6Engine.dll @ 1002a51d : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnexecFootStepCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x68]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x30]
        push ecx
        mov dword ptr [ebp-0x30],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002a531 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnexecFootStepCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecFootStep // L"AR6Pawn::execFootStep".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044650 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execFootStepExceptionHandler(void)
{
    __asm {
        mov eax,offset execFootStepFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002a550 : AR6Pawn::SetPawnLookDirection
// Reports centered look angles, then poses head/spine/clavicles according to posture, movement and weapon gates.
void __thiscall AR6Pawn::SetPawnLookDirection(FRotator lookRotation, int noBlend)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x3c/-0x38/-0x34.
        uint caught; // EBP-0x30.
        FName scratchName; // EBP-0x2c.
        uint rethrow; // EBP-0x28.
        FName* returnedName; // EBP-0x24.
        int absolutePitch; // EBP-0x20.
        uint blendOrPitch; // EBP-0x1c, float bits initially and signed pitch after centering.
        float headYaw; // EBP-0x18.
        AR6Pawn* pawn; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &SetPawnLookDirectionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    int initialNoBlend = noBlend; // Read the incoming DWORD before state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.pawn = this;
    frame.state = 0;
    frame.blendOrPitch = 0;
    if (initialNoBlend == 0) {
        uint flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8);
        frame.blendOrPitch = 0x3ecccccd;
        if ((flags & 0x20000U) == 0)
            frame.blendOrPitch = 0x3f000000;
    }
    UMesh* mesh = this->Mesh;
    USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(this));
    float blendTime; // Native ESI captures this after the first name callback and retains it afterward.
    void*& previousExceptionList = frame.previousExceptionList;
    using NameConstructor = FName* (__thiscall *)(FName*, const ushort*, int);
    FName& modeName = *(FName*)&noBlend;
    FName& rollName = *(FName*)&lookRotation.Roll;
    FName& scratchName = frame.scratchName;
    auto constructBone = [](FName* storage, const ushort* text) {
        // Every parent constructor call reloads the IAT.
        NameConstructor constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        return constructName(storage, text, 1);
    };
    auto resetBone = [&](FName* storage, const ushort* text) {
        FName* name = constructBone(storage, text);
        FRotator zeroRotation = {0, 0, 0};
        instance->USkeletalMeshInstance::SetBoneRotation(*name, zeroRotation, 0, 1.0f, blendTime);
    };
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    auto finish = [&]() { ExceptionList = previousExceptionList; };
    FName* neckName = constructBone(&modeName, nativeTextR6Neck);
    blendTime = reinterpret_cast<float&>(frame.blendOrPitch);
    uint neckNameWord = *(uint*)neckName;
    FRotator zeroRotation = {0, 0, 0};
    instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(neckNameWord),
        zeroRotation, 0, 1.0f, blendTime);
    int inputYaw = lookRotation.Yaw;
    AR6Pawn* centeringPawn = frame.pawn;
    int centeredYaw = centeringPawn->AR6Pawn::GetRotValueCenteredAroundZero(inputYaw);
    int inputPitch = lookRotation.Pitch;
    noBlend = centeredYaw;
    int centeredPitch = centeringPawn->AR6Pawn::GetRotValueCenteredAroundZero(inputPitch);
    FName offsetName = *(FName*)&R6ENGINE_SetRotationOffset;
    frame.blendOrPitch = (uint)centeredPitch;
    lookRotation.Pitch = centeredPitch;
    int packetYaw = noBlend;
    AR6Pawn* lookupPawn = frame.pawn;
    lookRotation.Yaw = packetYaw;
    lookRotation.Roll = 0;
    UFunction* setOffset = lookupPawn->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(offsetName), 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    AR6Pawn* vtablePawn = frame.pawn;
    byte* eventVtable = *(byte**)vtablePawn;
    AR6Pawn* eventPawn = frame.pawn;
    (*(ProcessEvent*)(eventVtable + 0x10))(eventPawn, setOffset, &lookRotation, nullptr);
    int& yaw = noBlend; // This incoming slot later becomes several returned FName pointers.
    int& pitch = reinterpret_cast<int&>(frame.blendOrPitch);
    auto clampStoredAngle = [](int& slot, int limit) {
        int value = slot;
        if (value < -limit)
            slot = -limit;
        else if (value >= limit)
            slot = limit;
    };
    auto absoluteWord = [](int value) { return value < 0 ? 0U - (uint)value : (uint)value; };
    clampStoredAngle(yaw, 0x4000);
    int pitchValue = pitch;
    if (pitchValue < -0x3000)
        pitch = pitchValue = -0x3000;
    else if (pitchValue >= 0x3000)
        pitch = pitchValue = 0x3000;
    frame.absolutePitch = (int)absoluteWord(pitchValue);
    float10 headScale = (float10)frame.absolutePitch * nativeFloat8Point138021EMinus05;
    headScale *= (pitchValue > 0 ? nativeFloatMinus8EPlus03 : nativeFloat8EPlus03);
    AR6Pawn* posturePawn = frame.pawn;
    frame.headYaw = (float)headScale;
    uint postureFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(posturePawn) + 0x3e0);
    float& yawFraction = reinterpret_cast<float&>(lookRotation.Roll);
    const uint* postureFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(posturePawn) + 0x6c8);
    if ((postureFlags & 0x200U) == 0) {
        if ((reinterpret_cast<byte*>(posturePawn)[0x6c4] & 4U) != 0)
            clampStoredAngle(yaw, 0x2000);
        bool diagonal = (*postureFlagWord & 0x20000U) != 0;
        if (diagonal) {
            lookRotation.Roll = (int)absoluteWord(yaw);
            yawFraction = (float)((float10)lookRotation.Roll * nativeFloat6Point1035156EMinus05);
            FName* returned = constructBone(&scratchName, nativeTextR6Head);
            float10 headValue = frame.headYaw;
            frame.returnedName = returned;
            int headRotation = truncateLowWord(headValue);
            returned = frame.returnedName;
            AR6Pawn* posePawn = frame.pawn;
            uint nameWord = *(uint*)returned;
            posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, 0, headRotation, 0, blendTime);
            bool positiveYaw = yaw > 0; // Test the current saved slot after the head callback.
            returned = constructBone(&scratchName, nativeTextR6Spine1);
            float10 rollValue = (float10)yawFraction * (positiveYaw ? nativeFloat14000 :
                nativeFloatMinus1Point2EPlus04);
            *(FName**)&noBlend = returned;
            int roll = truncateLowWord(rollValue);
            int spineYaw = truncateLowWord((float10)yawFraction *
                (positiveYaw ? nativeFloat4EPlus03 : nativeFloat2EPlus03));
            int spinePitch = truncateLowWord((float10)yawFraction *
                (positiveYaw ? nativeFloat6EPlus03 : nativeFloatMinus10000));
            returned = *(FName**)&noBlend;
            nameWord = *(uint*)returned;
            posePawn = frame.pawn;
            posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, spinePitch, spineYaw, roll, blendTime);
        } else {
            int signedYaw = yaw;
            yaw = (int)absoluteWord(signedYaw);
            float10 magnitude = yaw;
            bool positiveYaw = signedYaw > 0;
            yawFraction = (float)(magnitude * nativeFloat0Point00012207031);
            FName* returned = constructBone(&scratchName, nativeTextR6Head);
            float10 rollValue = (float10)yawFraction * (positiveYaw ? nativeFloat8EPlus03 : nativeFloatMinus8EPlus03);
            *(FName**)&noBlend = returned;
            int roll = truncateLowWord(rollValue);
            int headRotation = truncateLowWord((float10)frame.headYaw);
            returned = *(FName**)&noBlend;
            uint nameWord = *(uint*)returned;
            AR6Pawn* posePawn = frame.pawn;
            posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, 0, headRotation, roll, blendTime);
            // Reset through the retained original mesh instance.
            resetBone(&modeName, nativeTextR6Spine1);
        }
        AR6Pawn* weaponPawn = frame.pawn;
        uint weaponFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(weaponPawn) + 0x6c4);
        if ((weaponFlags & 4U) == 0 && (weaponFlags & 0x80040000U) == 0 &&
            weaponPawn->AR6Pawn::WeaponIsAGadget() == 0 && frame.absolutePitch > 0x1000) {
            int retainedPitch = pitch;
            AR6Pawn* followPawn = frame.pawn;
            followPawn->AR6Pawn::WeaponFollow(retainedPitch, blendTime);
            finish();
            return;
        }
    } else if ((*postureFlagWord & 0x2000U) == 0) {
        FName* returned = constructBone(&scratchName, nativeTextR6Head);
        float10 headValue = frame.headYaw;
        *(FName**)&lookRotation.Roll = returned;
        int headRotation = truncateLowWord(headValue);
        returned = *(FName**)&lookRotation.Roll;
        uint nameWord = *(uint*)returned;
        AR6Pawn* posePawn = frame.pawn;
        posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, 0, headRotation, 0, blendTime);
        resetBone(&rollName, nativeTextR6RClavicle);
        resetBone(&rollName, nativeTextR6LClavicle);
        int retainedYaw = yaw;
        if ((int)absoluteWord(retainedYaw) > 0x2000) {
            if (retainedYaw < -0x4000)
                retainedYaw = -0x4000;
            else if (retainedYaw >= 0x4000)
                retainedYaw = 0x4000;
        }
        returned = constructBone(&modeName, nativeTextR6Spine);
        nameWord = *(uint*)returned;
        posePawn = frame.pawn;
        posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, retainedYaw, 0, 0, blendTime);
        finish();
        return;
    } else {
        resetBone(&modeName, nativeTextR6Head);
        resetBone(&modeName, nativeTextR6Spine);
    }
    resetBone(&modeName, nativeTextR6RClavicle);
    resetBone(&modeName, nativeTextR6LClavicle);
    finish(); // Void RET 16; the original Roll is overwritten before it can supply a pose angle.
}

// R6Engine.dll @ 1002aab4 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnSetPawnLookDirectionCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x30]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x28]
        push eax
        mov dword ptr [ebp-0x28],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002aac8 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnSetPawnLookDirectionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnSetPawnLookDirection // L"AR6Pawn::SetPawnLookDirection".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044660 : select the parent's exception tables and preserve the native frame-handler ABI
__declspec(naked) void SetPawnLookDirectionExceptionHandler(void)
{
    __asm {
        mov eax,offset SetPawnLookDirectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002aaf0 : AR6Pawn::SetPawnLookAndAimDirection
// Reports aim angles, poses the spine and head/neck, and delegates eligible clavicle movement to WeaponLock.
void __thiscall AR6Pawn::SetPawnLookAndAimDirection(FRotator lookRotation, int noBlend)
{
    struct NativeFrameView { // Inferred inherited EBP storage; no owned local cleanup.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x40/-0x3c/-0x38.
        struct { int pitch, yaw, roll; } offsetParameters; // EBP-0x34/-0x30/-0x2c, three script INTs.
        uint caught; // EBP-0x28.
        FName scratchName; // EBP-0x24.
        uint rethrow; // EBP-0x20.
        FName* returnedName; // EBP-0x1c; also FName storage on the initial prone path.
        float blendTime; // EBP-0x18.
        AR6Pawn* pawn; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &SetPawnLookAndAimDirectionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    int initialNoBlend = noBlend;
    AR6Pawn* originalPawn = this;
    frame.savedEsp = &frame.savedEdi;
    frame.pawn = originalPawn;
    frame.state = 0;
    reinterpret_cast<uint&>(frame.blendTime) = 0;
    const uint* poseFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(originalPawn) + 0x6c8);
    if (initialNoBlend == 0) {
        uint flags = *poseFlagWord;
        reinterpret_cast<uint&>(frame.blendTime) = 0x3ecccccd;
        if ((flags & 0x20000U) == 0)
            reinterpret_cast<uint&>(frame.blendTime) = 0x3f19999a;
    }
    int inputYaw = lookRotation.Yaw;
    int centeredYaw = originalPawn->AR6Pawn::GetRotValueCenteredAroundZero(inputYaw);
    int inputPitch = lookRotation.Pitch;
    noBlend = centeredYaw;
    int centeredPitch = originalPawn->AR6Pawn::GetRotValueCenteredAroundZero(inputPitch);
    uint eventFlags = *poseFlagWord;
    FName offsetName = *(FName*)&R6ENGINE_SetRotationOffset;
    lookRotation.Roll = centeredPitch;
    frame.offsetParameters.roll = 0;
    frame.offsetParameters.pitch = centeredPitch;
    frame.offsetParameters.yaw = 0;
    if ((eventFlags & 0x20000U) == 0)
        frame.offsetParameters.yaw = centeredYaw;
    UFunction* setOffset = originalPawn->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(offsetName), 0);
    byte* eventVtable = *(byte**)originalPawn;
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    (*(ProcessEvent*)(eventVtable + 0x10))(originalPawn, setOffset, &frame.offsetParameters, nullptr);
    auto constructBone = [](FName* storage, const ushort* text) {
        return ::new (storage) FName(text, static_cast<EFindName>(1));
    };
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    auto absoluteWord = [](int value) { return value < 0 ? 0U - (uint)value : (uint)value; };
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    FName& scratchName = frame.scratchName;
    FName& parameterName = *(FName*)&noBlend;
    int& pitch = lookRotation.Roll; // Incoming EBP+0x10; later also holds returned-name pointers.
    // Incoming EBP+0x14: saved yaw, yaw fraction, pitch fraction, then FName.
    float& fraction = reinterpret_cast<float&>(noBlend);
    float blendTime; // Retained ESI value captures only after the initial spine name callback.
    uint postureFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(originalPawn) + 0x3e0);
    if ((postureFlags & 0x200U) != 0) {
        if (centeredYaw < -0x2000)
            noBlend = -0x2000;
        else if (centeredYaw >= 0x2000)
            noBlend = 0x2000;
        FName* returned = constructBone((FName*)&frame.returnedName, nativeTextR6Spine);
        blendTime = frame.blendTime;
        int spinePitch = noBlend; // Reload the live saved-yaw slot after construction.
        uint nameWord = *(uint*)returned;
        originalPawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, spinePitch, 0, 0, blendTime);
    } else {
        int clampedYaw = centeredYaw;
        if (clampedYaw < -0x4000)
            clampedYaw = -0x4000;
        else if (clampedYaw >= 0x4000)
            clampedYaw = 0x4000;
        noBlend = (int)absoluteWord(clampedYaw);
        fraction = (float)((float10)noBlend * nativeFloat6Point1035156EMinus05);
        FName* returned = constructBone(&scratchName, nativeTextR6Spine1);
        float10 rollValue = fraction;
        bool positiveYaw = clampedYaw > 0;
        blendTime = frame.blendTime;
        rollValue *= (positiveYaw ? nativeFloat14000 : nativeFloatMinus1Point2EPlus04);
        frame.returnedName = returned;
        int roll = truncateLowWord(rollValue);
        int spineYaw = truncateLowWord((float10)fraction * (positiveYaw ? nativeFloat8EPlus03 : nativeFloat2EPlus03));
        int spinePitch = truncateLowWord((float10)fraction * (positiveYaw ? nativeFloat6EPlus03 :
            nativeFloatMinus10000));
        returned = frame.returnedName;
        uint nameWord = *(uint*)returned;
        originalPawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, spinePitch, spineYaw, roll, blendTime);
    }
    int pitchValue = pitch;
    if (pitchValue < -0x3000)
        pitch = -0x3000;
    else if (pitchValue >= 0x3000)
        pitch = 0x3000;
    pitchValue = pitch; // Current incoming slot after the spine callback and conditional clamp stores.
    noBlend = (int)absoluteWord(pitchValue);
    float10 pitchMagnitude = noBlend;
    AR6Pawn* meshPawn = frame.pawn;
    UMesh* mesh = meshPawn->Mesh;
    byte* meshVtable = *(byte**)mesh; // Captured before pitch multiplication/spill.
    pitchMagnitude *= nativeFloat8Point138021EMinus05;
    fraction = (float)pitchMagnitude;
    using MeshGetInstance = UMeshInstance* (__thiscall*)(UMesh*, const AActor*);
    USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(
        (*reinterpret_cast<MeshGetInstance*>(meshVtable + 0x88))(mesh, meshPawn));
    auto resetBone = [&](FName* storage, const ushort* text) {
        FName* returned = constructBone(storage, text);
        uint nameWord = *(uint*)returned;
        FRotator zeroRotation = {0, 0, 0};
        instance->USkeletalMeshInstance::SetBoneRotation(reinterpret_cast<FName&>(nameWord),
            zeroRotation, 0, 1.0f, blendTime);
    };
    AR6Pawn* weaponPawn = frame.pawn;
    AR6EngineWeapon* weapon = weaponPawn->EngineWeapon;
    bool resetNeck = weapon == nullptr;
    if (!resetNeck && weapon->m_eWeaponType == 7) {
        AR6Pawn* sensorPawn = frame.pawn;
        resetNeck = sensorPawn->AR6Pawn::IsUsingHeartBeatSensor() == 0;
    }
    if (resetNeck) {
        resetBone(&parameterName, nativeTextR6Neck);
    } else {
        int signPitch = pitch;
        AR6Pawn* sensorPawn = frame.pawn;
        bool positivePitch = signPitch > 0; // Retain this branch decision across the second sensor query.
        int usingSensor = sensorPawn->AR6Pawn::IsUsingHeartBeatSensor();
        if (usingSensor != 0) {
            FName* returned = constructBone(&scratchName, nativeTextR6Neck);
            float10 firstValue = (float10)fraction * (positivePitch ? nativeFloatMinus1EPlus03 : nativeFloat6EPlus03);
            *(FName**)&lookRotation.Roll = returned;
            int roll, neckYaw, neckPitch;
            if (positivePitch) {
                roll = truncateLowWord(firstValue);
                neckYaw = truncateLowWord((float10)fraction * nativeFloatMinus6EPlus03);
                neckPitch = truncateLowWord((float10)fraction * nativeFloat2EPlus03);
            } else {
                roll = 0;
                neckYaw = truncateLowWord(firstValue);
                neckPitch = truncateLowWord((float10)fraction * nativeFloatMinus4EPlus03);
            }
            returned = *(FName**)&lookRotation.Roll;
            uint nameWord = *(uint*)returned;
            AR6Pawn* posePawn = frame.pawn;
            posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, neckPitch, neckYaw, roll, blendTime);
            resetBone(&parameterName, nativeTextR6Head);
        } else {
            resetBone(&scratchName, nativeTextR6Neck);
            FName* returned = constructBone(&scratchName, nativeTextR6Head);
            float10 headValue = (float10)fraction * (positivePitch ? nativeFloatMinus8EPlus03 : nativeFloat8EPlus03);
            frame.returnedName = returned;
            int headYaw = truncateLowWord(headValue);
            returned = frame.returnedName;
            uint nameWord = *(uint*)returned;
            AR6Pawn* posePawn = frame.pawn;
            posePawn->AR6Pawn::PawnSetBoneRotation(*(FName*)&nameWord, 0, headYaw, 0, blendTime);
            AR6Pawn* currentPawn = frame.pawn;
            AR6EngineWeapon* currentWeapon = currentPawn->EngineWeapon; // Unchecked native reload.
            if (currentWeapon->m_eWeaponType != 6) {
                AR6Pawn* predicatePawn = frame.pawn;
                if (predicatePawn->AR6Pawn::WeaponShouldFollowHead() != 0) {
                    AR6Pawn* lockPawn = frame.pawn;
                    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(lockPawn) + 0x3e4) & 0x40000U) != 0) {
                        uint fractionWord = reinterpret_cast<uint&>(noBlend);
                        int currentPitch = pitch;
                        lockPawn->AR6Pawn::WeaponLock(currentPitch, reinterpret_cast<float&>(fractionWord), blendTime);
                        finish();
                        return;
                    }
                }
            }
        }
    }
    resetBone(&parameterName, nativeTextR6RClavicle);
    resetBone(&parameterName, nativeTextR6LClavicle);
    finish(); // Void RET 16; original Roll is overwritten before it can supply a pose angle.
}

// R6Engine.dll @ 1002af84 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6PawnSetPawnLookAndAimDirectionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x28]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x20]
        push edx
        mov dword ptr [ebp-0x20],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002af98 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6PawnSetPawnLookAndAimDirectionCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnSetPawnLookAndAimDirection // L"AR6Pawn::SetPawnLookAndAimDirection".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044670 : select the parent's exception tables and preserve the native frame-handler ABI
__declspec(naked) void SetPawnLookAndAimDirectionExceptionHandler(void)
{
    __asm {
        mov eax,offset SetPawnLookAndAimDirectionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002afc0 : AR6Pawn::GetViewRotation
// Returns player/controller rotation or a once-per-time cached nonplayer bone/controller rotation.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FRotator* __thiscall AR6Pawn::GetViewRotation(FRotator* result)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no local owned destruction.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x90/-0x8c/-0x88.
        uint coordinatesStorage[12]; // EBP-0x84 through -0x58; hidden bone-coordinate output.
        uint coordinatesCopy[12]; // EBP-0x54 through -0x28; separate complete FCoords copy.
        uint rotationWords[3]; // EBP-0x24/-0x20/-0x1c; shared bone/interpolation hidden output.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04; constructor transitions write its low byte only.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&GetViewRotationExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool player = (reinterpret_cast<byte*>(this)[0x3e8] & 0x10U) != 0; // m_bIsPlayer, read before state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    uint* cached = (uint*)&this->m_rViewRotation; // +0x8c0.
    auto finish = [&]() {
        uint* output = (uint*)result;
        output[0] = cached[0]; // Sequential word copies retain native behavior if result overlaps the cache.
        output[1] = cached[1];
        output[2] = cached[2];
        ExceptionList = frame.previousExceptionList;
        return (FRotator*)output; // Return the captured pointer even if output overwrote the incoming argument.
    };
    if (player) {
        AController* controller = this->Controller; // +0x4ec; only the player gate reads it before the time test.
        if (controller != nullptr) {
            byte rotationFlags = reinterpret_cast<byte*>(this)[0xac];
            this->DesiredRotation.Roll = 0; // +0x304, on both player branches; flags captured before this store.
            uint offsetPitch = (uint)this->m_rRotationOffset.Pitch; // +0x5f0.
            uint pitch, yaw, roll;
            if ((rotationFlags & 2U) != 0) { // bRotateToDesired.
                uint basePitch = (uint)this->DesiredRotation.Pitch;
                uint baseYaw = (uint)this->DesiredRotation.Yaw;
                uint baseRoll = (uint)this->DesiredRotation.Roll;
                uint offsetRoll = (uint)this->m_rRotationOffset.Roll;
                pitch = offsetPitch + basePitch;
                yaw = (uint)this->m_rRotationOffset.Yaw + baseYaw;
                roll = offsetRoll + baseRoll;
            } else {
                uint basePitch = (uint)controller->Rotation.Pitch;
                uint baseYaw = (uint)controller->Rotation.Yaw;
                uint offsetYaw = (uint)this->m_rRotationOffset.Yaw;
                pitch = offsetPitch + basePitch;
                uint baseRoll = (uint)controller->Rotation.Roll;
                yaw = offsetYaw + baseYaw;
                roll = (uint)this->m_rRotationOffset.Roll + baseRoll;
            }
            cached[0] = pitch;
            cached[1] = yaw;
            cached[2] = roll;
            return finish();
        }
    }
    ALevelInfo* level = this->Level; // +0x144.
    float10 timeSeconds = (float10)level->TimeSeconds; // +0x45c, loaded before the cached time.
    float10 previousTime = (float10)this->m_fLastVRPUpdate; // +0x750.
    if (previousTime == timeSeconds) // Ordered equality only; unordered refreshes.
        return finish();
    // Native rereads/copies the raw time word.
    reinterpret_cast<uint&>(this->m_fLastVRPUpdate) = reinterpret_cast<uint&>(level->TimeSeconds);
    AController* controller = this->Controller;
    if (controller == nullptr) {
        uint offsetPitch = (uint)this->m_rRotationOffset.Pitch;
        uint basePitch = (uint)this->Rotation.Pitch;
        uint baseYaw = (uint)this->Rotation.Yaw;
        uint baseRoll = (uint)this->Rotation.Roll;
        uint offsetRoll = (uint)this->m_rRotationOffset.Roll;
        uint pitch = offsetPitch + basePitch;
        uint yaw = (uint)this->m_rRotationOffset.Yaw + baseYaw;
        uint roll = offsetRoll + baseRoll;
        cached[0] = pitch;
        cached[1] = yaw;
        cached[2] = roll;
        return finish();
    }
    USkeletalMeshInstance* instance = nullptr;
    UMesh* mesh = this->Mesh;
    if (mesh != nullptr) {
        UClass* meshClass = mesh->Class;
        // Imported USkeletalMesh::PrivateStaticClass object address.
        UClass* skeletalMeshClass = USkeletalMeshPrivateStaticClassImport;
        while (meshClass != nullptr && meshClass != skeletalMeshClass)
            meshClass = meshClass->GetSuperClass();
        if (meshClass == skeletalMeshClass) { // Includes a null class import after the ancestry walk reaches null.
            mesh = this->Mesh; // Native reloads Mesh for the virtual call.
            mesh->MeshGetInstance(this); // Native ignores EAX and reads the current pawn field afterward.
            instance = static_cast<USkeletalMeshInstance*>(this->MeshInstance);
            // +0x324, retained across later bone callbacks.
        }
    }
    bool useBoneRotation = instance != nullptr &&
        instance->USkeletalMeshInstance::WasSkeletonUpdated() != 0;
    if (useBoneRotation) {
        float10 peeking = (float10)this->m_fPeeking;
        float10 peekingSentinel = (float10)nativeDouble1000; // Field loaded before the double sentinel 1000.
        useBoneRotation = peekingSentinel == peeking; // Ordered equality; unordered falls back.
    }
    if (useBoneRotation) {
        FName* ponyTailName = (FName*)&nativePawnPonyTailName;
        uint* ponyTailNameGuard = (uint*)&nativePawnPonyTailNameGuard;
        if ((*(byte*)ponyTailNameGuard & 1U) == 0) {
            *ponyTailNameGuard |= 1U;
            *(byte*)&frame.state = 1;
            // R6 PonyTail1.
            ::new (ponyTailName) FName(nativeTextR6PonyTail1, static_cast<EFindName>(1));
            *(byte*)&frame.state = 0; // Constructor failure alone runs the guard-bit cleanup below.
        }
        uint boneNameWord = *(uint*)ponyTailName;
        int boneIndex = instance->USkeletalMeshInstance::MatchRefBone(
            reinterpret_cast<FName&>(boneNameWord));
        // Physical result view keeps the supplied buffer and returned pointer.
        FCoords* returnedCoordinates = instance->USkeletalMeshInstance::GetBoneCoords(
            (FCoords*)frame.coordinatesStorage, (uint)boneIndex, 1);
        uint* copiedWords = frame.coordinatesCopy;
        const uint* returnedWords = (const uint*)returnedCoordinates;
        for (int word = 0; word != 12; ++word)
            copiedWords[word] = returnedWords[word]; // Native REP MOVSD copies the complete 48-byte FCoords.
        const FRotator* rotation = &(*reinterpret_cast<FRotator*>(frame.rotationWords) =
            reinterpret_cast<const FCoords*>(frame.coordinatesCopy)->OrthoRotation());
        cached[0] = reinterpret_cast<const uint&>(rotation->Pitch);
        cached[1] = reinterpret_cast<const uint&>(rotation->Yaw);
        cached[2] = reinterpret_cast<const uint&>(rotation->Roll);
    } else {
        const uint* offset = (const uint*)this->AR6Pawn::GetRotationOffset((FRotator*)frame.rotationWords);
        uint offsetPitch = offset[0];
        controller = this->Controller; // Reload after interpolation/bone callbacks; native does not guard it.
        uint basePitch = (uint)controller->Rotation.Pitch;
        uint baseYaw = (uint)controller->Rotation.Yaw;
        uint pitch = basePitch + offsetPitch;
        uint offsetYaw = offset[1];
        uint offsetRoll = offset[2];
        uint yaw = offsetYaw + baseYaw;
        uint baseRoll = (uint)controller->Rotation.Roll;
        cached[0] = pitch;
        uint roll = offsetRoll + baseRoll;
        cached[1] = yaw;
        cached[2] = roll;
    }
    return finish();
}

// R6Engine.dll @ 1002b226 : ViewCacheCatchPointer
// Rethrows the caught word through separate storage in the inherited view-cache frame.
__declspec(naked) void ViewCacheCatchPointer(void)
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

// R6Engine.dll @ 1002b23a : ViewCacheCatchContext
// Reports the view-cache method context and rethrows the active exception.
__declspec(naked) void ViewCacheCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnGetViewRotation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044680 : ViewCacheState1Cleanup
// Clears only the static bone-name guard bit after construction fails, retaining the name word.
__declspec(naked) void ViewCacheState1Cleanup(void)
{
    __asm {
        mov eax,dword ptr [nativePawnPonyTailNameGuard]
        and eax,0xfffffffe
        mov dword ptr [nativePawnPonyTailNameGuard],eax
        ret
    }
}

// R6Engine.dll @ 1004468e : GetViewRotationExceptionHandler
// Passes the view-cache FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void GetViewRotationExceptionHandler(void)
{
    __asm {
        mov eax,offset viewCacheFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002b260 : AR6Pawn::execPawnCanBeHurtFrom
// Decodes a source point and reports a clear center trace, or a clear eye trace using the same hit record.
void __thiscall AR6Pawn::execPawnCanBeHurtFrom(FFrame& stack, void* result)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame and reused outgoing extent packet.
        uint extentWords[3]; // EBP-0x84/-0x80/-0x7c; outgoing by-value FVector for either trace.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x78/-0x74/-0x70.
        NativeCheckResult32 hitWords; // EBP-0x6c through -0x40; the same FCheckResult survives both traces.
        uint eyeStorage[3]; // EBP-0x3c/-0x38/-0x34; hidden EyePosition output.
        uint sourceWords[3]; // EBP-0x30/-0x2c/-0x28; required FVector, initially uninitialized.
        uint eyePoint[3]; // EBP-0x24/-0x20/-0x1c; spilled absolute eye endpoint.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execPawnCanBeHurtFromExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = &stack; // Native retains ESI across expression callbacks.
    using Expression = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = vmFrame->Code;
    byte opcode = *code;
    vmFrame->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    Expression* natives = *(Expression**)&CoreGNativesImport;
    UObject* context = vmFrame->Object;
    frame.state = 0;
    Expression evaluate = natives[opcode];
    evaluate(context, vmFrame, frame.sourceWords);
    code = vmFrame->Code + 1;
    vmFrame->Code = code;
    if (*code == 0x42) {
        context = vmFrame->Object;
        vmFrame->Code = code + 1;
        natives = *(Expression**)&CoreGNativesImport;
        natives[0x42](context, vmFrame, nullptr);
    }
    using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    const uint* zeroVector = *(const uint**)&FVectorFVector0Import;
    ULevel* firstLevel = this->XLevel; // +0x328, captured before inline hit initialization.
    for (int i = 0; i != 9; ++i)
        reinterpret_cast<uint*>(&frame.hitWords)[i] = 0;
    reinterpret_cast<uint&>(frame.hitWords.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hitWords.Item) = 0xffffffff;
    frame.hitWords.materialAddress = 0;
    uint extentX = zeroVector[0];
    byte* levelVtable = *(byte**)firstLevel;
    frame.extentWords[0] = extentX;
    uint extentY = zeroVector[1];
    uint extentZ = zeroVector[2];
    frame.extentWords[1] = extentY;
    frame.extentWords[2] = extentZ;
    FVector* center = &this->Location; // +0x234; retain the live address across callbacks.
    ULevel* receiver = this->XLevel;
    LineCheck lineCheck = *(LineCheck*)(levelVtable + 0xcc);
    lineCheck(receiver, reinterpret_cast<FCheckResult*>(&frame.hitWords), this, center, (FVector*)frame.sourceWords,
        0x40086, *(FVector*)frame.extentWords);
    if (frame.hitWords.actorAddress != 0) {
        ULevel* secondLevel = this->XLevel; // Captured before EyePosition; retained for vtable and receiver.
        using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
        FVector* eyeOffset = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(this,
            (FVector*)frame.eyeStorage);
        float10 eyeZ = (float10)center->Z + eyeOffset->Z;
        zeroVector = *(const uint**)&FVectorFVector0Import;
        float10 eyeY = (float10)center->Y + eyeOffset->Y;
        float10 eyeX = (float10)eyeOffset->X + center->X;
        reinterpret_cast<float&>(frame.eyePoint[0]) = (float)eyeX;
        reinterpret_cast<float&>(frame.eyePoint[1]) = (float)eyeY;
        reinterpret_cast<float&>(frame.eyePoint[2]) = (float)eyeZ;
        extentX = zeroVector[0];
        levelVtable = *(byte**)secondLevel;
        frame.extentWords[0] = extentX;
        extentY = zeroVector[1];
        extentZ = zeroVector[2];
        frame.extentWords[1] = extentY;
        frame.extentWords[2] = extentZ;
        lineCheck = *(LineCheck*)(levelVtable + 0xcc);
        lineCheck(secondLevel, reinterpret_cast<FCheckResult*>(&frame.hitWords), this, (FVector*)frame.eyePoint,
            (FVector*)frame.sourceWords, 0x40086, *(FVector*)frame.extentWords);
    }
    uint clear = frame.hitWords.actorAddress == 0 ? 1U : 0U;
    uint* output = (uint*)result;
    *output = clear; // Full script BOOL depends only on final Actor; trace return values are ignored.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1002b3db : HurtTraceCatchPointer
// Rethrows the caught word through separate storage in the inherited hurt-trace frame.
__declspec(naked) void HurtTraceCatchPointer(void)
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

// R6Engine.dll @ 1002b3ef : HurtTraceCatchContext
// Reports the hurt-trace method context and rethrows the active exception.
__declspec(naked) void HurtTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecPawnCanBeHurtFrom
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446a0 : execPawnCanBeHurtFromExceptionHandler
// Passes the hurt-trace FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void execPawnCanBeHurtFromExceptionHandler(void)
{
    __asm {
        mov eax,offset hurtTraceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002b410 : AR6Pawn::IsRelevantToPawnHeatVision
// Tests an active player viewer's strict view cone and 8000-unit center-distance limit.
int __thiscall AR6Pawn::IsRelevantToPawnHeatVision(APawn* viewer)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative shared storage.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x48/-0x44/-0x40.
        uint forward[3]; // EBP-0x3c/-0x38/-0x34; supplied Rotator::Vector output.
        uint direction[3]; // EBP-0x30/-0x2c/-0x28; supplied Normalize receiver.
        uint caught, rethrow; // EBP-0x24/-0x20.
        uint rotationWords[3]; // EBP-0x1c/-0x18/-0x14; rotation, delta scratch, then squared distance.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&IsRelevantToPawnHeatVisionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    APawn* viewPawn = viewer; // Native retains ESI when the incoming viewer word becomes the cone threshold.
    bool missingViewer = viewPawn == nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    int relevant = 0;
    if (!missingViewer) {
        AController* controller = viewPawn->Controller; // Captured before the self comparison.
        if (controller != nullptr && viewPawn != this) {
            byte* player = (byte*)CastToAPlayerController((int)controller);
            if (player != nullptr && (*(uint*)(player + 0x524) & 0x02000000) != 0) {
                float10 halfAngle = ((float10)*(float*)(player + 0x3b0) + nativeFloat1EPlus01)
                    * nativeFloatHalf;
                double radians = (double)(halfAngle * nativeDouble0Point017453292519943295);
                double* cosineDoubleSpill = (double*)&frame.rotationWords[1]; // EBP-0x18/-0x14.
                // Incoming EBP+8 changes from pawn pointer to float threshold.
                uint& thresholdWord = reinterpret_cast<uint&>(viewer);
                uint* thresholdSlot = &thresholdWord;
                byte* viewerVtable;
                // FST64 does not pop: FSTP32 takes the live ST0 value, preserving the distinct rounding boundaries.
                __asm {
                    sub esp,8
                    mov eax,dword ptr [radians]
                    mov dword ptr [esp],eax
                    mov eax,dword ptr [radians+4]
                    mov dword ptr [esp+4],eax
                    call dword ptr [CoreAppCosImport]
                    mov eax,viewPawn
                    mov eax,dword ptr [eax]
                    mov viewerVtable,eax
                    mov edx,cosineDoubleSpill
                    fst qword ptr [edx]
                    add esp,8
                    mov edx,thresholdSlot
                    fstp dword ptr [edx]
                }
                using ViewRotation = FRotator* (__thiscall*)(APawn*, FRotator*);
                FRotator* rotation = (*(ViewRotation*)(viewerVtable + 0xd4))(viewPawn, (FRotator*)frame.rotationWords);
                // Ignore returned pointer.
                *(FVector*)frame.forward = rotation->Vector();
                float10 deltaZ = (float10)this->Location.Z - viewPawn->Location.Z;
                float10 deltaY = (float10)this->Location.Y - viewPawn->Location.Y;
                float10 deltaX = (float10)this->Location.X - viewPawn->Location.X;
                reinterpret_cast<float&>(frame.rotationWords[0]) = (float)deltaX;
                frame.direction[0] = frame.rotationWords[0];
                reinterpret_cast<float&>(frame.rotationWords[1]) = (float)deltaY;
                frame.direction[1] = frame.rotationWords[1];
                reinterpret_cast<float&>(frame.rotationWords[2]) = (float)deltaZ;
                frame.direction[2] = frame.rotationWords[2];
                float10 squareZ = reinterpret_cast<float&>(frame.direction[2]);
                squareZ *= reinterpret_cast<float&>(frame.direction[2]);
                float10 squareY = reinterpret_cast<float&>(frame.direction[1]);
                squareY *= reinterpret_cast<float&>(frame.direction[1]);
                float10 distanceSquared = squareZ + squareY;
                float10 squareX = reinterpret_cast<float&>(frame.direction[0]);
                squareX *= reinterpret_cast<float&>(frame.direction[0]);
                distanceSquared += squareX;
                // EBP-0x14 is reused after deltaZ.
                reinterpret_cast<float&>(frame.rotationWords[2]) = (float)distanceSquared;
                // Ignore failure; no zero-distance exclusion.
                ((FVector*)frame.direction)->Normalize();
                float10 facingZ = reinterpret_cast<float&>(frame.forward[2]);
                facingZ *= reinterpret_cast<float&>(frame.direction[2]);
                float10 facingY = reinterpret_cast<float&>(frame.forward[1]);
                facingY *= reinterpret_cast<float&>(frame.direction[1]);
                float10 facing = facingZ + facingY;
                float10 facingX = reinterpret_cast<float&>(frame.forward[0]);
                facingX *= reinterpret_cast<float&>(frame.direction[0]);
                facing += facingX;
                if (facing > (float10)reinterpret_cast<float&>(thresholdWord)
                    && reinterpret_cast<float&>(frame.rotationWords[2]) < nativeFloat6Point4EPlus07)
                    relevant = 1;
            }
        }
    }
    ExceptionList = frame.previousExceptionList; // Includes disjoint native false tail 1002b59c..1002b5b1.
    return relevant;
}

// R6Engine.dll @ 1002b56c : HeatRelevanceCatchPointer
// Rethrows the caught word through separate storage in the inherited heat-vision frame.
__declspec(naked) void HeatRelevanceCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002b580 : HeatRelevanceCatchContext
// Reports the native APawn heat-vision context and rethrows the active exception.
__declspec(naked) void HeatRelevanceCatchContext(void)
{
    __asm {
        push offset nativeTextAPawnIsRelevantToPawnHeatVision
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446b0 : IsRelevantToPawnHeatVisionExceptionHandler
// Passes the heat-vision FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void IsRelevantToPawnHeatVisionExceptionHandler(void)
{
    __asm {
        mov eax,offset heatRelevanceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002b5c0 : AR6Pawn::actorReachableFromLocation
// Applies anchor/range/visibility shortcuts, probes the target position and delegates reachability from the selected
// point.
int __thiscall AR6Pawn::actorReachableFromLocation(AActor* targetActor, FVector origin)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage and outgoing extent packet.
        uint extent[3]; // EBP-0x88/-0x84/-0x80; trace's outgoing by-value FVector.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x7c/-0x78/-0x74.
        NativeCheckResult32 hit; // EBP-0x70 through -0x44.
        uint traceStart[3]; // EBP-0x40/-0x3c/-0x38.
        uint shared34[3]; // EBP-0x34/-0x30/-0x2c; anchor delta, eye output, then saved pawn position.
        uint anchorDelta[3]; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow, distanceWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&OriginReachabilityExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* initialTarget = targetActor;
    uint zeroWord = 0; // Native EBX stays zero through the anchor shortcut, including the ValidAnchor call.
    bool missingTarget = initialTarget == nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (missingTarget)
        return finish(0);
    auto hasClass = [](AActor* actor, UClass* const* importedClassAddress) {
        UClass* cursor = actor->Class;
        UClass* expected = *importedClassAddress;
        while (cursor != nullptr) {
            if (cursor == expected)
                return true;
            cursor = cursor->GetSuperClass();
        }
        return expected == nullptr;
    };
    uint* originWords = (uint*)&origin; // Incoming EBP+0x0c/+0x10/+0x14 acquire later packet/scratch roles.
    if (hasClass(initialTarget, &ANavigationPointPrivateStaticClassImport) && this->CollisionRadius <=
        nativeFloat4EPlus01) {
        float10 radius = this->CollisionRadius;
        if ((float10)nativeFloat48 >= radius)
            radius = nativeFloat48;
        reinterpret_cast<float&>(frame.distanceWord) = (float)(radius * radius);
        if (this->APawn::ValidAnchor() != 0) {
            ANavigationPoint* anchor = this->Anchor;
            if (anchor == initialTarget) {
                float10 dz = (float10)anchor->Location.Z - reinterpret_cast<float&>(originWords[2]);
                float10 dy = (float10)anchor->Location.Y - reinterpret_cast<float&>(originWords[1]);
                float10 dx = (float10)anchor->Location.X - reinterpret_cast<float&>(originWords[0]);
                reinterpret_cast<float&>(frame.shared34[0]) = (float)dx;
                frame.anchorDelta[0] = frame.shared34[0];
                reinterpret_cast<float&>(frame.shared34[1]) = (float)dy;
                frame.anchorDelta[1] = frame.shared34[1];
                reinterpret_cast<float&>(frame.shared34[2]) = (float)dz;
                uint zWord = frame.shared34[2];
                float10 horizontalSquared = reinterpret_cast<float&>(frame.anchorDelta[1]);
                frame.anchorDelta[2] = zWord;
                horizontalSquared *= reinterpret_cast<float&>(frame.anchorDelta[1]);
                horizontalSquared += (float10)reinterpret_cast<float&>(frame.anchorDelta[0]) *
                    reinterpret_cast<float&>(frame.anchorDelta[0]);
                if (horizontalSquared < (float10)reinterpret_cast<float&>(frame.distanceWord))
                    return finish(1);
            }
        }
    }
    if (zeroWord != 0) { // Native 1002b6d9/1002b6db are unreachable with the preserved-zero EBX under its callee ABI.
        initialTarget = reinterpret_cast<AActor*>(zeroWord);
        targetActor = initialTarget;
    }
    float10 dz = initialTarget->Location.Z;
    int* editorAddress = *(int**)&CoreGIsEditorImport;
    dz -= reinterpret_cast<float&>(originWords[2]);
    int editorMode = *editorAddress;
    float10 dy = (float10)initialTarget->Location.Y - reinterpret_cast<float&>(originWords[1]);
    float10 dx = (float10)initialTarget->Location.X - reinterpret_cast<float&>(originWords[0]);
    reinterpret_cast<float&>(frame.distanceWord) = (float)((dx * dx + dy * dy) + dz * dz);
    if (editorMode == 0) {
        if (reinterpret_cast<float&>(frame.distanceWord) > nativeFloat1Point44EPlus06)
            return finish(0);
        using HurtByVolume = int (__thiscall*)(AR6Pawn*, AActor*);
        HurtByVolume hurt = *(HurtByVolume*)(*(byte**)this + 0x188);
        if (hurt(this, initialTarget) != 0)
            return finish(0);
        APhysicsVolume* volume = initialTarget->PhysicsVolume;
        if ((reinterpret_cast<byte*>(volume)[0x410] & 0x40U) != 0) {
            if ((reinterpret_cast<byte*>(this)[0x3e2] & 1U) == 0)
                return finish(0);
        } else if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x28000U) == 0) {
            return finish(0);
        }
    }
    for (int i = 0; i != 9; ++i)
        reinterpret_cast<uint*>(&frame.hit)[i] = 0;
    reinterpret_cast<uint&>(frame.hit.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hit.Item) = 0xffffffff;
    frame.hit.materialAddress = 0;
    using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
    FVector* eye = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(this, (FVector*)frame.shared34);
    float10 startZ = (float10)reinterpret_cast<float&>(originWords[2]) + eye->Z;
    ULevel* level = this->XLevel; // Captured between Z and Y additions.
    float10 startY = (float10)reinterpret_cast<float&>(originWords[1]) + eye->Y;
    float10 startX = (float10)reinterpret_cast<float&>(originWords[0]) + eye->X;
    const uint* zeroVector = *(const uint**)&FVectorFVector0Import;
    reinterpret_cast<float&>(frame.traceStart[0]) = (float)startX;
    reinterpret_cast<float&>(frame.traceStart[1]) = (float)startY;
    reinterpret_cast<float&>(frame.traceStart[2]) = (float)startZ;
    uint extentX = zeroVector[0];
    byte* levelVtable = *(byte**)level;
    frame.extent[0] = extentX;
    uint extentY = zeroVector[1];
    uint extentZ = zeroVector[2];
    frame.extent[1] = extentY;
    AActor* traceTarget = targetActor; // Reload incoming EBP+8 after eye/event callbacks.
    frame.extent[2] = extentZ;
    using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*, const FVector*, const FVector*, uint, FVector);
    (*(LineCheck*)(levelVtable + 0xcc))(level, reinterpret_cast<FCheckResult*>(&frame.hit), this,
        &traceTarget->Location,
        (FVector*)frame.traceStart, 0x86, *(FVector*)frame.extent);
    float10 one = nativeFloatOne;
    float10 hitTime = frame.hit.Time;
    if (hitTime != one && frame.hit.actorAddress != (uint)traceTarget)
        return finish(0);
    if (hasClass(traceTarget, &APawnPrivateStaticClassImport)) {
        float10 melee = this->MeleeRange;
        float10 scaledRadius = (float10)this->CollisionRadius * nativeFloat1Point5;
        // Incoming origin.Z becomes the rounded radius scratch.
        reinterpret_cast<float&>(originWords[2]) = (float)scaledRadius;
        float10 extra = melee;
        if (scaledRadius <= melee)
            extra = reinterpret_cast<float&>(originWords[2]);
        float10 combined = (float10)traceTarget->CollisionRadius + this->CollisionRadius;
        combined += extra;
        if ((float10)reinterpret_cast<float&>(frame.distanceWord) <= combined * combined)
            return finish(1);
    }
    uint savedX = reinterpret_cast<uint&>(this->Location.X);
    uint savedY = reinterpret_cast<uint&>(this->Location.Y);
    uint savedZ = reinterpret_cast<uint&>(this->Location.Z);
    frame.shared34[0] = savedX;
    frame.shared34[2] = savedZ;
    frame.shared34[1] = savedY;
    uint probeX = reinterpret_cast<uint&>(traceTarget->Location.X);
    originWords[0] = reinterpret_cast<uint&>(traceTarget->Location.X);
    uint targetY = reinterpret_cast<uint&>(traceTarget->Location.Y);
    uint targetZ = reinterpret_cast<uint&>(traceTarget->Location.Z);
    originWords[1] = targetY;
    level = this->XLevel;
    originWords[2] = targetZ;
    levelVtable = *(byte**)level;
    uint probePacket[3]; // Native outgoing by-value FVector at EBP-0x98/-0x94/-0x90.
    probePacket[0] = probeX;
    uint probeY = reinterpret_cast<uint&>(traceTarget->Location.Y);
    uint probeZ = reinterpret_cast<uint&>(traceTarget->Location.Z);
    probePacket[1] = probeY;
    probePacket[2] = probeZ;
    ULevel* receiver = this->XLevel; // Reread independently of the captured vtable.
    using FarMoveActor = int (__thiscall*)(ULevel*, AActor*, FVector, int, int, int, int);
    int moved = (*(FarMoveActor*)(levelVtable + 0x9c))(receiver, this, *(FVector*)probePacket, 1, 0, 0, 0);
    uint reachableX;
    if (moved != 0) {
        uint movedZ = reinterpret_cast<uint&>(this->Location.Z);
        uint movedY = reinterpret_cast<uint&>(this->Location.Y);
        // Retained independently of the incoming origin.X word across restore.
        reachableX = reinterpret_cast<uint&>(this->Location.X);
        uint restoreX = frame.shared34[0];
        originWords[2] = movedZ;
        uint restorePacket[3];
        restorePacket[0] = restoreX;
        uint restoreY = frame.shared34[1];
        originWords[1] = movedY;
        level = this->XLevel;
        levelVtable = *(byte**)level;
        restorePacket[1] = restoreY;
        uint restoreZ = frame.shared34[2];
        restorePacket[2] = restoreZ;
        (*(FarMoveActor*)(levelVtable + 0x9c))(level, this, *(FVector*)restorePacket, 1, 1, 0, 0);
    } else {
        reachableX = originWords[0];
    }
    AActor* finalTarget = targetActor;
    uint reachableY = originWords[1];
    uint reachableZ = originWords[2];
    uint reachPacket[3] = { reachableX, reachableY, reachableZ };
    int reachable = this->APawn::Reachable(*(FVector*)reachPacket, finalTarget);
    return finish(reachable); // Only a successful normal probe invokes restore; catches add no restoration.
}

// R6Engine.dll @ 1002b969 : OriginReachabilityCatchPointer
// Rethrows the caught word through separate storage in the inherited origin-reachability frame.
__declspec(naked) void OriginReachabilityCatchPointer(void)
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

// R6Engine.dll @ 1002b97d : OriginReachabilityCatchContext
// Reports the origin-reachability context and rethrows the active exception.
__declspec(naked) void OriginReachabilityCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnActorReachableFromLocation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446c0 : OriginReachabilityExceptionHandler
// Passes the origin-reachability FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void OriginReachabilityExceptionHandler(void)
{
    __asm {
        mov eax,offset originReachabilityFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002b9a0 : AR6Pawn::GetCurrentMaterial
// Peels cached modifiers (+0x520/+0x58) and returns the terminal surface byte (+0x4c); native defines AL only.
uchar __thiscall AR6Pawn::GetCurrentMaterial(void)
{
    UMaterial* material = this->m_HitMaterial;
    if (material == nullptr)
        return 0;
    for (;;) {
        UClass* classCursor = material->Class;
        UClass* modifierClass = UModifierPrivateStaticClassImport;
        while (classCursor != nullptr && classCursor != modifierClass)
            classCursor = classCursor->GetSuperClass();
        if (classCursor != modifierClass)
            break;
        material = static_cast<UModifier*>(material)->Material;
        this->m_HitMaterial = material;
        if (material == nullptr)
            break;
    }
    return this->m_HitMaterial->m_eSurfIdForSnd; // A null modifier link is still dereferenced in the native body.
}

// R6Engine.dll @ 1002bad0 : AR6Pawn::execAdjustFluidCollisionCylinder
// Evaluates blend/test through shared native storage and forwards the full cylinder-adjustment result word.
// Native ABI view retains the incoming frame word for the cylinder-test operand.
void __thiscall AR6Pawn::execAdjustFluidCollisionCylinder(FFrame* stack, void* result)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow, blendWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CylinderBridgeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* vmFrame = stack; // Retained in native ESI when the incoming frame argument becomes the test word.
    uint& testStorage = reinterpret_cast<uint&>(stack); // Incoming EBP+8 changes roles before the second evaluation.
    byte** codeCursor = &vmFrame->Code;
    byte* code = *codeCursor;
    frame.blendWord = 0;
    byte opcode = *code;
    *codeCursor = code + 1;
    frame.savedEsp = &frame.savedEdi;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = vmFrame->Object;
    frame.state = 0;
    table[opcode](receiver, vmFrame, &frame.blendWord);
    code = *codeCursor;
    receiver = vmFrame->Object;
    testStorage = 0;
    opcode = *code;
    *codeCursor = code + 1;
    table = *(ScriptNative**)&CoreGNativesImport;
    table[opcode](receiver, vmFrame, &testStorage);
    code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        receiver = vmFrame->Object;
        *codeCursor = code + 1;
        table = *(ScriptNative**)&CoreGNativesImport;
        table[0x42](receiver, vmFrame, nullptr);
    }
    uint testWord = testStorage;
    uint blendWord = frame.blendWord;
    int adjustment = this->AR6Pawn::AdjustFluidCollisionCylinder(reinterpret_cast<float&>(blendWord), (int)testWord);
    uint* output = (uint*)result;
    void* previousExceptionList = frame.previousExceptionList; // Captured before output can overwrite guard storage.
    *output = (uint)adjustment;
    ExceptionList = previousExceptionList;
}

// R6Engine.dll @ 1002bb8a : CylinderBridgeCatchPointer
// Rethrows the caught word through separate storage in the inherited cylinder-bridge frame.
__declspec(naked) void CylinderBridgeCatchPointer(void)
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

// R6Engine.dll @ 1002bb9e : CylinderBridgeCatchContext
// Reports the cylinder-bridge context and rethrows the active exception.
__declspec(naked) void CylinderBridgeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecAdjustFluidCollisionCylinder
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446d0 : CylinderBridgeExceptionHandler
// Passes the cylinder-bridge FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void CylinderBridgeExceptionHandler(void)
{
    __asm {
        mov eax,offset cylinderBridgeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002bbc0 : AR6Pawn::GetHeadLocation (explicit hidden FVector result)
// Writes a visibility-test point using prone facing or eye height and the selector's vertical adjustment.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6Pawn::GetHeadLocation(FVector* result, AActor* actor)
{
    struct NativeFrameView { // Descriptive offsets relative to entry ESP; native establishes no EBP guard frame.
        uint savedEdi, savedEsi; // ESP-0x20/-0x1c.
        uint offsetWords[3]; // ESP-0x18/-0x14/-0x10; direction output or common eye offset.
        uint scratchWords[3]; // ESP-0x0c/-0x08/-0x04; eye output, prone XY products or rounded head Z.
    } frame;
    AActor* target = actor; // Retained ESI, independent of the incoming argument word.
    uint& actorWord = reinterpret_cast<uint&>(actor); // Incoming ESP+8 becomes the prone-distance float spill.
    if (target != nullptr && target->UObject::IsA(&AR6Pawn::PrivateStaticClass) != 0) {
        if ((*(uint*)((byte*)target + 0x3e0) & 0x200U) != 0) {
            float10 distance = this->m_iVisibilityTest;
            distance *= target->CollisionRadius;
            distance *= nativeFloat0Point45;
            reinterpret_cast<float&>(actorWord) = (float)distance;
            const uint* direction = (const
                uint*)&(*(FVector*)frame.offsetWords = target->Rotation.Vector());
            float10 product = reinterpret_cast<float&>(actorWord);
            product *= reinterpret_cast<const float&>(direction[0]);
            reinterpret_cast<float&>(frame.scratchWords[0]) = (float)product;
            product = reinterpret_cast<float&>(actorWord);
            product *= reinterpret_cast<const float&>(direction[1]);
            reinterpret_cast<float&>(frame.scratchWords[1]) = (float)product;
            product = reinterpret_cast<float&>(actorWord);
            product *= reinterpret_cast<const float&>(direction[2]);
            FVector* output = result; // Native loads the hidden pointer before the live Location.Z read.
            float10 headZ = product + target->Location.Z;
            float10 headY = (float10)reinterpret_cast<float&>(frame.scratchWords[1]) + target->Location.Y;
            float10 headX = (float10)reinterpret_cast<float&>(frame.scratchWords[0]) + target->Location.X;
            output->X = (float)headX;
            output->Y = (float)headY;
            output->Z = (float)headZ;
            return output;
        }
        using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
        const uint* eye = (const uint*)reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(
            static_cast<APawn*>(target),
            (FVector*)frame.scratchWords);
        uint eyeX = eye[0];
        uint eyeY = eye[1];
        frame.offsetWords[0] = eyeX;
        uint eyeZ = eye[2];
        frame.offsetWords[1] = eyeY;
        frame.offsetWords[2] = eyeZ;
    } else {
        // Null actor still faults here in the native body.
        uint heightWord = reinterpret_cast<uint&>(target->CollisionHeight);
        frame.scratchWords[0] = 0;
        uint zeroX = frame.scratchWords[0];
        frame.scratchWords[1] = 0;
        uint zeroY = frame.scratchWords[1];
        frame.scratchWords[2] = heightWord;
        frame.offsetWords[0] = zeroX;
        frame.offsetWords[1] = zeroY;
        frame.offsetWords[2] = heightWord;
    }
    int selector = this->m_iVisibilityTest; // Current after EyePosition; prone path captured its selector earlier.
    FVector* output = result;
    if (selector == 0) {
        float10 headZ = (float10)reinterpret_cast<float&>(frame.offsetWords[2]) + target->Location.Z;
        float10 headY = (float10)reinterpret_cast<float&>(frame.offsetWords[1]) + target->Location.Y;
        float10 headX = (float10)reinterpret_cast<float&>(frame.offsetWords[0]) + target->Location.X;
        output->X = (float)headX;
        output->Y = (float)headY;
        output->Z = (float)headZ;
        return output;
    }
    float10 headX = (float10)reinterpret_cast<float&>(frame.offsetWords[0]) + target->Location.X;
    float10 headY = (float10)reinterpret_cast<float&>(frame.offsetWords[1]) + target->Location.Y;
    float10 headZ = (float10)reinterpret_cast<float&>(frame.offsetWords[2]) + target->Location.Z;
    reinterpret_cast<float&>(frame.scratchWords[2]) = (float)headZ;
    output->X = (float)headX;
    output->Y = (float)headY;
    // Reload after XY stores, retaining native output aliases.
    float10 adjustedZ = reinterpret_cast<float&>(frame.scratchWords[2]);
    adjustedZ -= (selector == 1 ? nativeFloat1EPlus01 : nativeFloat2EPlus01);
    output->Z = (float)adjustedZ;
    return output; // Captured hidden pointer survives writes that alias its incoming argument.
}

// R6Engine.dll @ 1002bd50 : AR6Pawn::moveToward
// Defers movement to door opening when required, otherwise returns the base pawn's movement result.
int __thiscall AR6Pawn::moveToward(const FVector& destination, AActor* target)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&MoveTowardExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AController* initialController = this->Controller; // Native captures/tests this before saved ESP and state zero.
    bool missingController = initialController == nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (missingController)
        return finish(0);
    UClass* type = initialController->Class;
    while (type != nullptr && type != &AR6AIController::PrivateStaticClass)
        type = type->GetSuperClass();
    AR6AIController* ai = type != nullptr ? static_cast<AR6AIController*>(initialController) : nullptr;
    byte pawnType = reinterpret_cast<byte&>(this->m_ePawnType);
    AActor* capturedTarget;
    if (pawnType != 1 && ai != nullptr) {
        capturedTarget = target; // Native ESI retains this argument across the door predicate.
        if (capturedTarget != nullptr && ai->AR6AIController::NeedToOpenDoor(capturedTarget) != 0) {
            // Native assumes the retained target is a door here.
            AR6Door* correspondingDoor = static_cast<AR6Door*>(capturedTarget)->m_CorrespondingDoor;
            ai->AR6AIController::GotoOpenDoorState(correspondingDoor);
            return finish(1); // Ignore the transition's result; null corresponding doors remain unchecked.
        }
    } else {
        capturedTarget = target;
    }
    const FVector& currentDestination = destination; // Read after a false predicate; target/controller stay captured.
    int moveResult = this->APawn::moveToward(currentDestination, capturedTarget);
    return finish(moveResult);
}

// R6Engine.dll @ 1002be1b : MoveTowardCatchPointer
// Rethrows the caught word through separate storage in the inherited movement frame.
__declspec(naked) void MoveTowardCatchPointer(void)
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

// R6Engine.dll @ 1002be2f : MoveTowardCatchContext
// Reports the native APawn movement context and rethrows the active exception.
__declspec(naked) void MoveTowardCatchContext(void)
{
    __asm {
        push offset nativeTextAPawnMoveToward
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446e0 : MoveTowardExceptionHandler
// Passes the movement FuncInfo to the shared C++ exception dispatcher.
__declspec(naked) void MoveTowardExceptionHandler(void)
{
    __asm {
        mov eax,offset moveTowardFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002be50 : AR6Pawn::UpdateFullPeekingMode
// Queries completion, advances peeking toward its stance-dependent goal and updates player collision when needed.
void __thiscall AR6Pawn::UpdateFullPeekingMode(float deltaSeconds)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x2c/-0x28/-0x24.
        uint caught, rethrow, previousWord, sharedWord; // EBP-0x20/-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&UpdateFullPeekingModeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    // R6ENGINE_IsFullPeekingOver, captured before state 0.
    FName completionName = *(FName*)&R6ENGINE_IsFullPeekingOver;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    frame.sharedWord = 0; // Completion BOOL, later reused as the desired float word.
    UFunction* function = this->UObject::FindFunctionChecked(reinterpret_cast<const FName&>(completionName), 0);
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    this->ProcessEvent(function, &frame.sharedWord, nullptr);
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    uint& deltaWord = reinterpret_cast<uint&>(deltaSeconds); // Incoming EBP+8 becomes the collision-return float spill.
    auto updateCollision = [&]() {
        uint peekingWord = reinterpret_cast<uint&>(this->m_fPeeking);
        // Native float return remains in ST0 until FSTP32.
        float10 accepted = this->AR6Pawn::UpdateColBoxPeeking(reinterpret_cast<float&>(peekingWord));
        reinterpret_cast<float&>(deltaWord) = (float)accepted;
        uint acceptedWord = deltaWord;
        reinterpret_cast<uint&>(this->m_fPeeking) = acceptedWord;
    };
    if (frame.sharedWord != 0) {
        if ((reinterpret_cast<byte*>(this)[0x3e8] & 0x10U) != 0) { // m_bIsPlayer, sampled after the event.
            const FVector* zero = *(const FVector**)&FVectorFVector0Import;
            const float* velocity = (const float*)&this->Velocity;
            auto componentAtRest = [&](int component) {
                float10 zeroComponent = *(const float*)((const byte*)zero + component * 4);
                float10 velocityComponent = velocity[component];
                return velocityComponent == zeroComponent;
            };
            bool atRest = componentAtRest(0) && componentAtRest(1) && componentAtRest(2);
            if (!atRest || (reinterpret_cast<byte*>(this)[0xac] & 2U) != 0) { // bRotateToDesired.
                updateCollision();
            }
        }
        finish();
        return;
    }
    // bIsCrouched, retained through the clamps.
    bool crouched = (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x20U) != 0;
    float& desired = reinterpret_cast<float&>(frame.sharedWord); // Reuse the actual completion-result word.
    const uint* peekingFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<byte*>(this) + 0x6c4);
    if (crouched && (*peekingFlagWord & 0x02000000U) == 0) { // m_bPeekingReturnToCenter.
        if ((float10)this->m_fPeekingGoal <= nativeDouble400)
            frame.sharedWord = 0x43c80000;
        else if ((float10)this->m_fPeekingGoal >= nativeDouble1600)
            frame.sharedWord = 0x44c80000;
        else
            // Each comparison/fallthrough reloads the raw goal.
            frame.sharedWord = reinterpret_cast<uint&>(this->m_fPeekingGoal);
    } else {
        frame.sharedWord = reinterpret_cast<uint&>(this->m_fPeekingGoal);
    }
    float10 step = deltaSeconds;
    uint previousWord = reinterpret_cast<uint&>(this->m_fPeeking); // Loaded before the step multiplication.
    step *= nativeDouble3000;
    frame.previousWord = previousWord;
    float& previous = reinterpret_cast<float&>(frame.previousWord);
    float10 magnitude;
    uint* desiredSlot = &frame.sharedWord;
    __asm {
        mov eax,this
        fld dword ptr [eax+0x734]
        mov edx,desiredSlot
        fsub dword ptr [edx]
        fabs
        fstp tbyte ptr [magnitude] // Preserve extended subtraction and FABS, including signed zero/unordered values.
    }
    if (magnitude >= nativeDouble1000)
        step += step; // Gap at least 1000 doubles the live extended step; unordered does not.
    if ((float10)desired > this->m_fPeeking)
        this->m_fPeeking = (float)(step + (float10)this->m_fPeeking);
    else
        this->m_fPeeking = (float)((float10)this->m_fPeeking - step); // Includes unordered and equality.
    float10 clamped;
    if ((*peekingFlagWord & 0x02000000U) != 0) { // Native rereads return-to-center after the step store.
        bool lowerHalf = (float10)previous < nativeDouble1000;
        float current = this->m_fPeeking; // Native loads this after comparing previous, before choosing a half.
        if (lowerHalf) {
            if ((float10)current < nativeFloatZero)
                clamped = nativeFloatZero;
            else if ((float10)current < nativeFloat1EPlus03)
                clamped = current;
            else
                clamped = nativeFloat1EPlus03; // Unordered current chooses upper bound 1000.
        } else {
            if ((float10)current < nativeFloat1EPlus03)
                clamped = nativeFloat1EPlus03;
            else if ((float10)current < nativeFloat2EPlus03)
                clamped = current;
            else
                clamped = nativeFloat2EPlus03; // Previous equality/unordered selects upper half; current NaN -> 2000.
        }
    } else {
        bool peekingLeft = (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e4) & 0x80000000U) != 0;
        uint boundWord = frame.sharedWord;
        uint currentWord = reinterpret_cast<uint&>(this->m_fPeeking);
        if (crouched)
            clamped = peekingLeft ? ClampFloatOrdered(reinterpret_cast<float&>(currentWord),
                reinterpret_cast<float&>(boundWord), 1600.0f)
                : ClampFloatOrdered(reinterpret_cast<float&>(currentWord), 400.0f, reinterpret_cast<float&>(boundWord));
        else
            clamped = peekingLeft ? ClampFloatOrdered(reinterpret_cast<float&>(currentWord),
                reinterpret_cast<float&>(boundWord), 2000.0f)
                : ClampFloatOrdered(reinterpret_cast<float&>(currentWord), 0.0f, reinterpret_cast<float&>(boundWord));
    }
    byte playerFlags = reinterpret_cast<byte*>(this)[0x3e8]; // Loaded before the final clamped store.
    this->m_fPeeking = (float)clamped;
    if ((playerFlags & 0x10U) != 0) {
        float10 currentAfterClamp = this->m_fPeeking;
        float10 previousAfterClamp = previous;
        if (previousAfterClamp != currentAfterClamp) // Includes unordered; current is loaded before previous.
            updateCollision();
    }
    finish(); // All normal paths return void with RET 4; the intermediate peeking write is not rolled back.
}

// R6Engine.dll @ 1002c101 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void FullPeekingCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002c115 : report method context and rethrow without adding a funclet frame
__declspec(naked) void FullPeekingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUpdateFullPeekingMode // L"AR6Pawn::UpdateFullPeekingMode".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100446f0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void UpdateFullPeekingModeExceptionHandler(void)
{
    __asm {
        mov eax,offset fullPeekingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002c140 : AR6Pawn::execMoveHitBone
// Decodes a hit, rotates its bone with optional spine compensation and updates the local controller's hit effect.
// Native ABI view retains the incoming frame word for the bone-index operand.
void __thiscall AR6Pawn::execMoveHitBone(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage; union roles share actual native slots.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x98/-0x94/-0x90.
        FCoords coordinates; // EBP-0x8c..-0x60; hidden result, irrespective of the provider's returned pointer.
        FVector vectorBuffer; // EBP-0x5c..-0x54, reused for both hit-direction conversions.
        FRotator hitDirection; // EBP-0x50..-0x48; required operand is uninitialized before evaluation.
        union { uint pitchWord; FVector controllerDirection; }; // EBP-0x44..-0x3c.
        FVector crossOrRequested; // EBP-0x38..-0x30; normalized cross product, later copied requested direction.
        uint caught, rethrow; // EBP-0x2c/-0x28.
        AR6Pawn* owner; // EBP-0x24, reread for the controller stage.
        uint spineFlagName, boneNameWord; // EBP-0x20/-0x1c; flag becomes the name-constructor output.
        float zProjection, yProjection; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execMoveHitBoneExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = stack; // Retained ESI; incoming EBP+8 is reused as the bone operand/index.
    uint& boneIndex = reinterpret_cast<uint&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    UObject* receiver = expressionStack->Object;
    frame.owner = this;
    frame.state = 0;
    natives[opcode](receiver, expressionStack, &frame.hitDirection);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    boneIndex = 0; // Zero after reading Code/Object and before reading the second opcode.
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &boneIndex);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (boneIndex == 0) {
        finish();
        return;
    }
    --boneIndex;
    if (boneIndex == 1 || boneIndex == 0x13 || boneIndex == 0x17)
        boneIndex = 2;
    UMesh* mesh = this->Mesh;
    USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(this));
    uint nameIndex = boneIndex; // Captured after GetInstance; GetMesh may change the incoming index again.
    UMesh* instanceMesh = instance->GetMesh();
    byte* records = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(instanceMesh) + 0x19c);
    uint coordinateIndex = boneIndex;
    frame.boneNameWord = *(uint*)((uint)records + (nameIndex << 6)); // Unchecked DWORD address arithmetic.
    // Physical result view keeps the supplied buffer; the returned pointer is ignored.
    instance->USkeletalMeshInstance::GetBoneCoords(&frame.coordinates,
        coordinateIndex, 0);
    frame.pitchWord = 0;
    uint yawStep = 0; // Native ESI survives the providers and conversion helper.
    FVector* direction = &(frame.vectorBuffer = frame.hitDirection.Vector());
    frame.crossOrRequested = frame.coordinates.XAxis ^ *direction;
    frame.crossOrRequested.Normalize(); // Both returned values are ignored.
    float10 yZ = (float10)frame.coordinates.YAxis.Z * frame.crossOrRequested.Z;
    uint switchIndex = boneIndex - 2U; // Reloaded after all geometry callbacks; range is unsigned 0..24.
    float10 yY = (float10)frame.coordinates.YAxis.Y * frame.crossOrRequested.Y;
    frame.spineFlagName = 0;
    frame.yProjection = (float)((yZ + yY) + (float10)frame.crossOrRequested.X * frame.coordinates.YAxis.X);
    frame.zProjection = (float)(((float10)frame.coordinates.ZAxis.Z * frame.crossOrRequested.Z +
        (float10)frame.coordinates.ZAxis.Y * frame.crossOrRequested.Y) +
        (float10)frame.crossOrRequested.X * frame.coordinates.ZAxis.X);
    float pitchScale, yawScale;
    bool convert = true;
    bool spineFamily = false;
    switch (switchIndex) { // Native byte classification and jump tables at 1002c4f8/1002c4e8.
    case 0: case 1: case 2: case 3: case 9: case 10: case 11: case 14: case 15: case 16:
        pitchScale = 6000.0f;
        yawScale = -6000.0f;
        break;
    case 4:
        pitchScale = 9000.0f;
        yawScale = -9000.0f;
        break;
    case 18: case 19: case 20: case 22: case 23: case 24:
        pitchScale = 3000.0f;
        yawScale = -3000.0f;
        spineFamily = true;
        break;
    default:
        convert = false;
        break;
    }
    if (convert) {
        float* yProjection = &frame.yProjection;
        float* zProjection = &frame.zProjection;
        uint* pitchSlot = &frame.pitchWord;
        __asm {
            mov ecx,yProjection
            fld dword ptr [ecx]
            fmul dword ptr [pitchScale]
            call TruncateX87ToSigned64
            mov ecx,zProjection
            fld dword ptr [ecx]
            fmul dword ptr [yawScale]
            mov ecx,pitchSlot
            mov dword ptr [ecx],eax // Store after loading/scaling Z, before its conversion.
            call TruncateX87ToSigned64
            mov yawStep,eax
        }
        if (spineFamily)
            frame.spineFlagName = 1;
    }
    using SetBoneRotation = int (__thiscall*)(USkeletalMeshInstance*, FName, FRotator, int, float, float);
    uint pitch = frame.pitchWord;
    uint nameWord = frame.boneNameWord;
    FRotator rotation = { (int)pitch, (int)yawStep, 0 };
    // Cache only after building the first rotation packet.
    SetBoneRotation setBone = reinterpret_cast<SetBoneRotation&>(USkeletalMeshInstanceSetBoneRotationImport);
    setBone(instance, *(FName*)&nameWord, rotation, 0, 1.0f, 0.0f);
    rotation = { 0, 0, 0 };
    nameWord = frame.boneNameWord; // First call can change this retained word.
    setBone(instance, *(FName*)&nameWord, rotation, 0, 1.0f, 0.6f);
    if (frame.spineFlagName != 0) { // Test after both calls; do not cache the original family flag.
        yawStep = 0U - yawStep;
        FName* name = ::new (reinterpret_cast<void*>(&frame.spineFlagName)) FName(
            nativeTextR6Spine, static_cast<EFindName>(1));
        pitch = frame.pitchWord; // Constructor may rewrite pitch; its returned name pointer remains authoritative.
        rotation = { (int)pitch, (int)yawStep, 0 };
        nameWord = *(uint*)name;
        setBone(instance, *(FName*)&nameWord, rotation, 0, 1.0f, 0.0f);
        yawStep = 0;
        name = ::new (reinterpret_cast<void*>(&frame.spineFlagName)) FName(
            nativeTextR6Spine, static_cast<EFindName>(1));
        nameWord = *(uint*)name;
        rotation = { 0, 0, 0 };
        setBone(instance, *(FName*)&nameWord, rotation, 0, 1.0f, 0.2f);
    }
    AR6Pawn* currentOwner = frame.owner;
    AR6PlayerController* controller = reinterpret_cast<AR6PlayerController*>(currentOwner->Controller);
    if (controller != nullptr) {
        UClass* type = controller->Class;
        while (type != nullptr && type != &AR6PlayerController::PrivateStaticClass)
            type = type->GetSuperClass();
        if (type != nullptr && controller != nullptr) { // Native repeats the captured controller null test.
            if (controller->LocalPlayerController() != 0) {
                const uint* requested = (const uint*)&(frame.vectorBuffer = frame.hitDirection.Vector());
                ((uint*)&frame.crossOrRequested)[0] = requested[0];
                ((uint*)&frame.crossOrRequested)[1] = requested[1];
                ((uint*)&frame.crossOrRequested)[2] = requested[2]; // Sequential copies retain alias behavior.
                frame.controllerDirection = controller->Rotation.Vector();
                FVector* controllerVector = &frame.controllerDirection;
                FVector* requestedVector = &frame.crossOrRequested;
                float effectScale = 2000.0f;
                uint controllerPitch, controllerYaw;
                __asm {
                    mov ecx,controllerVector
                    mov edx,requestedVector
                    fld dword ptr [ecx+8]
                    fmul dword ptr [edx+8]
                    fld dword ptr [edx+4]
                    fmul dword ptr [ecx+4]
                    faddp st(1),st
                    fld dword ptr [ecx]
                    fmul dword ptr [edx]
                    faddp st(1),st
                    fmul dword ptr [effectScale]
                    call TruncateX87ToSigned64
                    mov controllerPitch,eax
                    mov ecx,controllerVector
                    fld dword ptr [ecx]
                    fld dword ptr [ecx+8]
                    mov edx,controller
                    mov dword ptr [edx+0x90c],eax // X/Z are loaded before the pitch store.
                    mov edx,requestedVector
                    fmul dword ptr [edx+8]
                    fld dword ptr [edx+4]
                    fmul st,st(2) // Retain the native X term; this is not the usual dot product.
                    faddp st(1),st
                    fld dword ptr [ecx+4]
                    fmul dword ptr [edx]
                    faddp st(1),st
                    fmul dword ptr [effectScale]
                    call TruncateX87ToSigned64
                    fstp st(0)
                    mov controllerYaw,eax
                }
                reinterpret_cast<uint&>(controller->m_rHitRotation.Yaw) = controllerYaw;
                reinterpret_cast<uint&>(controller->m_rHitRotation.Roll) = 0;
                reinterpret_cast<uint&>(controller->m_fHitEffectTime) = 0x3e4ccccd; // 0.2f.
            }
        }
    }
    finish(); // Void RET 8; unusedResult is never read or written.
}

// R6Engine.dll @ 1002c4b5 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void HitBoneCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x2c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x28]
        push eax
        mov dword ptr [ebp-0x28],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002c4c9 : report method context and rethrow without adding a funclet frame
__declspec(naked) void HitBoneCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecMoveHitBone // L"AR6Pawn::execMoveHitBone".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044700 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execMoveHitBoneExceptionHandler(void)
{
    __asm {
        mov eax,offset hitBoneFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002c520 : AR6Pawn::UpdatePawnTrackActor
// Faces the unchecked tracked actor using the aim flag captured before vector-to-rotation conversion.
void __thiscall AR6Pawn::UpdatePawnTrackActor(int noBlend)
{
    // m_bAim; tested before loading m_TrackActor.
    bool aim = (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0x20000000U) != 0;
    AActor* trackedActor = this->m_TrackActor; // +0x7c0; native has no null guard.
    float10 deltaZ = (float10)trackedActor->Location.Z - this->Location.Z;
    float10 deltaY = (float10)trackedActor->Location.Y - this->Location.Y;
    float10 deltaX = (float10)trackedActor->Location.X - this->Location.X;
    struct NativeScratchView { // Inferred contiguous entry-ESP-relative hidden buffers.
        FVector direction; // Entry ESP-0x18..-0x10.
        FRotator rotation; // Entry ESP-0x0c..-0x04.
    } scratch;
    scratch.direction.X = (float)deltaX;
    scratch.direction.Y = (float)deltaY;
    scratch.direction.Z = (float)deltaZ;
    FRotator* targetRotation = &(scratch.rotation = scratch.direction.Rotation());
    uint targetPitch = (uint)targetRotation->Pitch; // Reads Pitch from the produced rotation slot.
    uint pawnPitch = (uint)this->Rotation.Pitch;
    uint pawnYaw = (uint)this->Rotation.Yaw;
    int relativePitch = (int)(targetPitch - pawnPitch);
    uint targetYaw = (uint)targetRotation->Yaw;
    uint targetRoll = (uint)targetRotation->Roll;
    int relativeYaw = (int)(targetYaw - pawnYaw);
    int relativeRoll = (int)(targetRoll - (uint)this->Rotation.Roll);
    int currentNoBlend = noBlend; // Incoming word is read only after the conversion and all rotation loads.
    FRotator relative = {relativePitch, relativeYaw, relativeRoll};
    if (aim)
        this->AR6Pawn::SetPawnLookAndAimDirection(relative, currentNoBlend);
    else
        this->AR6Pawn::SetPawnLookDirection(relative, currentNoBlend);
}

// R6Engine.dll @ 1002c640 : AR6Pawn::PawnLook
// Selects look or aim from captured ladder/request state and fresh callback-dependent weapon/posture gates.
void __thiscall AR6Pawn::PawnLook(FRotator relative, int aimRequested, int noBlend)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnLookExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool climbingLadder = (reinterpret_cast<byte*>(this)[0x6c4] & 4U) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    int effectiveAim = climbingLadder ? 0 : aimRequested;
    uint* movementFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8);
    auto chooseAim = [&]() {
        if ((*movementFlagWord & 0x20000U) != 0 && this->AR6Pawn::WeaponShouldFollowHead() == 0)
            return false; // m_bMovingDiagonally gate, not repeated after the predicate callback.
        if (effectiveAim == 0 && this->AR6Pawn::IsUsingHeartBeatSensor() == 0)
            return false;
        // Fresh m_bWeaponTransition.
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0x80000000U) != 0)
            return false;
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x200U) != 0 &&
            (*movementFlagWord & 0x2000U) != 0) // Fresh prone/bipod gates after any sensor event.
            return false;
        return true;
    };
    bool aim = chooseAim();
    int currentNoBlend = noBlend; // Build the packet from current incoming words after all selection callbacks.
    uint pitchWord = (uint)relative.Pitch;
    uint yawWord = (uint)relative.Yaw;
    uint rollWord = (uint)relative.Roll;
    FRotator currentRelative = { (int)pitchWord, (int)yawWord, (int)rollWord };
    if (aim)
        this->AR6Pawn::SetPawnLookAndAimDirection(currentRelative, currentNoBlend);
    else
        this->AR6Pawn::SetPawnLookDirection(currentRelative, currentNoBlend);
    ExceptionList = frame.previousExceptionList; // Native returns void and RET 0x14.
}

// R6Engine.dll @ 1002c728 : forward the caught PawnLook pointer through its inherited frame
__declspec(naked) void PawnLookCatchPointer(void)
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

// R6Engine.dll @ 1002c73c : report look-selection context and rethrow the active exception
__declspec(naked) void PawnLookCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPawnLook // L"AR6Pawn::PawnLook".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044710 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void PawnLookExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnLookFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002c760 : AR6Pawn::PawnLookAbsolute
// Selects look or aim before subtracting the pawn rotation read after all selection callbacks.
void __thiscall AR6Pawn::PawnLookAbsolute(FRotator worldRotation, int aimRequested, int noBlend)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnLookAbsoluteExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool climbingLadder = (reinterpret_cast<byte*>(this)[0x6c4] & 4U) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    int effectiveAim = climbingLadder ? 0 : aimRequested;
    uint* movementFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8);
    auto chooseAim = [&]() {
        if ((*movementFlagWord & 0x20000U) != 0 && this->AR6Pawn::WeaponShouldFollowHead() == 0)
            return false; // m_bMovingDiagonally gate, not repeated after the predicate callback.
        if (effectiveAim == 0 && this->AR6Pawn::IsUsingHeartBeatSensor() == 0)
            return false;
        // Fresh m_bWeaponTransition.
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0x80000000U) != 0)
            return false;
        if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x200U) != 0 &&
            (*movementFlagWord & 0x2000U) != 0) // Fresh prone/bipod gates after any sensor event.
            return false;
        return true;
    };
    bool aim = chooseAim();
    uint pawnPitch = (uint)this->Rotation.Pitch;
    uint targetPitch = (uint)worldRotation.Pitch;
    uint pawnRoll = (uint)this->Rotation.Roll;
    uint targetRoll = (uint)worldRotation.Roll;
    uint pawnYaw = (uint)this->Rotation.Yaw;
    uint relativePitch = targetPitch - pawnPitch;
    int currentNoBlend = noBlend; // Native reads mode after Pitch subtraction, before incoming Yaw.
    uint relativeRoll = targetRoll - pawnRoll;
    uint targetYaw = (uint)worldRotation.Yaw;
    FRotator relative = { (int)relativePitch, (int)(targetYaw - pawnYaw), (int)relativeRoll };
    if (aim)
        this->AR6Pawn::SetPawnLookAndAimDirection(relative, currentNoBlend);
    else
        this->AR6Pawn::SetPawnLookDirection(relative, currentNoBlend);
    ExceptionList = frame.previousExceptionList; // Void RET 0x14; input rotation words are not overwritten.
}

// R6Engine.dll @ 1002c878 : forward the caught PawnLookAbsolute pointer through its inherited frame
__declspec(naked) void PawnLookAbsoluteCatchPointer(void)
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

// R6Engine.dll @ 1002c88c : report the PawnLookAbsolute context and rethrow the active exception
__declspec(naked) void PawnLookAbsoluteCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPawnLookAbsolute // L"AR6Pawn::PawnLookAbsolute".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044720 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void PawnLookAbsoluteExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnLookAbsoluteFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002c8b0 : AR6Pawn::PawnLookAt
// Faces a point; the sensor can override ladder, prone/bipod or absent-aim gates before direction evaluation.
void __thiscall AR6Pawn::PawnLookAt(FVector targetPosition, int aimRequested, int noBlend)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x30/-0x2c/-0x28.
        FRotator rotation; // EBP-0x24..-0x1c; uninitialized before the hidden-output call.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&PawnLookAtExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    bool climbingLadder = (reinterpret_cast<byte*>(this)[0x6c4] & 4U) != 0;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    bool aim;
    if (climbingLadder || ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x200U) != 0 &&
        (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8) & 0x2000U) != 0) || aimRequested == 0)
        // Query only when an initial gate fails; no transition/diagonal gate.
        aim = this->AR6Pawn::IsUsingHeartBeatSensor() != 0;
    else
        aim = true;
    float10 deltaZ = (float10)targetPosition.Z - this->Location.Z;
    float10 deltaY = (float10)targetPosition.Y - this->Location.Y;
    float10 deltaX = (float10)targetPosition.X - this->Location.X;
    targetPosition.X = (float)deltaX; // Reuse by-value input words; all differences precede the X/Y/Z stores.
    targetPosition.Y = (float)deltaY;
    targetPosition.Z = (float)deltaZ;
    FRotator* targetRotation = &(frame.rotation = targetPosition.Rotation());
    uint targetRoll = (uint)targetRotation->Roll;
    uint pawnRoll = (uint)this->Rotation.Roll;
    uint pawnPitch = (uint)this->Rotation.Pitch;
    uint pawnYaw = (uint)this->Rotation.Yaw;
    int relativeRoll = (int)(targetRoll - pawnRoll);
    uint targetYaw = (uint)targetRotation->Yaw;
    uint targetPitch = (uint)targetRotation->Pitch;
    uint relativePitch = targetPitch - pawnPitch;
    int currentNoBlend = noBlend; // Read only after returned/current rotation captures and Pitch subtraction.
    FRotator relative = { (int)relativePitch, (int)(targetYaw - pawnYaw), relativeRoll };
    if (aim)
        this->AR6Pawn::SetPawnLookAndAimDirection(relative, currentNoBlend);
    else
        this->AR6Pawn::SetPawnLookDirection(relative, currentNoBlend);
    // Selection is not repeated after FVector::Rotation or the pose callback.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1002ca07 : forward the caught PawnLookAt pointer through its inherited frame
__declspec(naked) void PawnLookAtCatchPointer(void)
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

// R6Engine.dll @ 1002ca1b : report the PawnLookAt context and rethrow the active exception
__declspec(naked) void PawnLookAtCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnPawnLookAt // L"AR6Pawn::PawnLookAt".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044730 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void PawnLookAtExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnLookAtFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002ca40 : AR6Pawn::IsRelevantToPawnHeartBeat
// Checks the viewer's sensor cone/range and rejects nearby active pawn or standalone jammers.
int __thiscall AR6Pawn::IsRelevantToPawnHeartBeat(APawn* viewer)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x4c/-0x48/-0x44.
        FVector forward; // EBP-0x40..-0x38.
        FVector direction; // EBP-0x34..-0x2c.
        uint caught, rethrow; // EBP-0x28/-0x24.
        union { uint temporaryWords[3]; FRotator viewRotation; FVector deltaTemporary; }; // EBP-0x20..-0x18.
        AR6Pawn* owner; // EBP-0x14; reread throughout the jammer scan.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&IsRelevantToPawnHeartBeatExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.savedEsp = &frame.savedEdi;
    frame.owner = this;
    frame.state = 0;
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    if (this->APawn::IsAlive() == 0)
        return finish(0);
    APawn* capturedViewer = viewer; // Read incoming EBP+8 only after IsAlive; retain ESI when that slot is overwritten.
    if (capturedViewer == nullptr)
        return finish(0);
    AController* controller = capturedViewer->Controller;
    if (controller == nullptr || capturedViewer == this)
        return finish(0);
    // Native query-result view; the shared helper retains its null-class fallback.
    APlayerController* player = reinterpret_cast<APlayerController*>(CastToAPlayerController((int)controller));
    if (player == nullptr)
        return finish(0);
    AR6EngineWeapon* weapon = capturedViewer->EngineWeapon; // Current +0x4fc, after the cast.
    if (weapon == nullptr)
        return finish(0);
    using HeartBeatStatus = int (__thiscall*)(AR6EngineWeapon*);
    if ((*(HeartBeatStatus*)(*(byte**)weapon + 0x184))(weapon) == 0)
        return finish(0);
    float10 halfAngle = ((float10)player->FovAngle + nativeFloat1EPlus01) * nativeFloatHalf;
    double radians = (double)(halfAngle * nativeDouble0Point017453292519943295);
    double* cosineSpill = (double*)&frame.temporaryWords[1]; // EBP-0x1c/-0x18, later overwritten by rotation/delta.
    float* coneThreshold = (float*)&viewer; // Incoming viewer pointer becomes the float threshold.
    byte* viewerVtable;
    __asm {
        sub esp,8
        mov eax,dword ptr [radians]
        mov dword ptr [esp],eax
        mov eax,dword ptr [radians+4]
        mov dword ptr [esp+4],eax
        call dword ptr [CoreAppCosImport]
        mov edx,capturedViewer
        mov edx,dword ptr [edx] // Capture vtable before either cosine store.
        mov viewerVtable,edx
        mov ecx,cosineSpill
        fst qword ptr [ecx]
        add esp,8
        mov ecx,coneThreshold
        fstp dword ptr [ecx] // Round live ST0 directly, rather than the binary64 spill.
    }
    using ViewRotation = FRotator* (__thiscall*)(APawn*, FRotator*);
    FRotator* rotation = (*(ViewRotation*)(viewerVtable + 0xd4))(capturedViewer, &frame.viewRotation);
    // Supplied output is used; returned vector pointer ignored.
    frame.forward = rotation->Vector();
    float10 deltaZ = (float10)this->Location.Z - capturedViewer->Location.Z;
    float10 deltaY = (float10)this->Location.Y - capturedViewer->Location.Y;
    float10 deltaX = (float10)this->Location.X - capturedViewer->Location.X;
    frame.deltaTemporary.X = (float)deltaX;
    ((uint*)&frame.direction)[0] = frame.temporaryWords[0];
    frame.deltaTemporary.Y = (float)deltaY;
    ((uint*)&frame.direction)[1] = frame.temporaryWords[1];
    frame.deltaTemporary.Z = (float)deltaZ;
    ((uint*)&frame.direction)[2] = frame.temporaryWords[2]; // Each temporary spill/copy precedes the next spill.
    float& distanceSquared = reinterpret_cast<float&>(frame.temporaryWords[2]); // Reuse former rotation Roll/delta Z.
    distanceSquared = (float)(((float10)frame.direction.Z * frame.direction.Z +
        (float10)frame.direction.Y * frame.direction.Y) + (float10)frame.direction.X * frame.direction.X);
    // Ignore return; retained frame words may change during the callback.
    frame.direction.Normalize();
    float10 facing = ((float10)frame.forward.Z * frame.direction.Z + (float10)frame.forward.Y * frame.direction.Y)
        + (float10)frame.forward.X * frame.direction.X;
    if (!(facing > (float10)*coneThreshold))
        return finish(0);
    if (!(distanceSquared < nativeFloat2Point25EPlus06))
        return finish(0); // Both gates are strict ordered comparisons; no minimum range or occlusion test.
    uint index = 0;
    for (;;) {
        AR6Pawn* currentOwner = frame.owner;
        ULevel* level = currentOwner->XLevel;
        // Inferred native Actors header at +0x30; count/data remain live on each iteration.
        const NativeArrayHeader32* actorsHeader =
            reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(level) + 0x30);
        if ((int)index >= actorsHeader->count)
            return finish(1);
        AActor** actors = reinterpret_cast<AActor**>(actorsHeader->dataAddress);
        AActor* actor = actors[index];
        if (actor != nullptr) {
            APawn* pawn = actor->GetPlayerPawn();
            if (pawn != nullptr) {
                if (pawn->APawn::IsAlive() != 0 &&
                    (reinterpret_cast<byte*>(pawn)[0x3e8] & 1U) != 0) {
                    currentOwner = frame.owner; // Reload after IsAlive/flag, not just at the start of this iteration.
                    if (SquaredDistanceBetweenVectors((const float*)&currentOwner->Location,
                        (const float*)&pawn->Location) < (float10)nativeFloat2Point25EPlus06)
                        return finish(0); // Any living flagged pawn in range blocks; no self/viewer exclusion.
                }
            } else {
                AR6SAHeartBeatJammer* jammer =
                    reinterpret_cast<AR6SAHeartBeatJammer*>(CastToAR6SAHeartBeatJammer((int)actor));
                if (jammer != nullptr && (reinterpret_cast<byte*>(jammer)[0x3ac] & 0x40U) == 0) {
                    currentOwner = frame.owner;
                    if (SquaredDistanceBetweenVectors((const float*)&currentOwner->Location,
                        &jammer->Location.X) < (float10)nativeFloat1EPlus06)
                        return finish(0); // A nonnull returned pawn suppresses this standalone-jammer branch.
                }
            }
        }
        ++index; // DWORD increment, signed count comparison; re-read owner/level/count/data on the next iteration.
    }
}

// R6Engine.dll @ 1002cc80 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void HeartBeatRelevanceCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x28]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x24]
        push eax
        mov dword ptr [ebp-0x24],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002cc94 : report method context and rethrow without adding a funclet frame
__declspec(naked) void HeartBeatRelevanceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnIsRelevantToPawnHeartBeat // L"AR6Pawn::IsRelevantToPawnHeartBeat".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044740 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void IsRelevantToPawnHeartBeatExceptionHandler(void)
{
    __asm {
        mov eax,offset heartBeatRelevanceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002ccc0 : AR6Pawn::SetAudioInfo
// Updates packed replicated audio state and, outside net mode 1, the separate local playback bytes.
int __thiscall AR6Pawn::SetAudioInfo(void)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&SetAudioInfoExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6SoundReplicationInfo* initialSound = this->m_SoundRepInfo; // +0x7d8, tested before activating state 0.
    int result = 0;
    bool hasSound = initialSound != nullptr;
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (!hasSound) {
        ExceptionList = frame.previousExceptionList;
        return 0;
    }
    if (this->Role == 4) { // Actor.Role +0x2d.
        ALevelInfo* levelInfo = this->Level; // +0x144; native assumes it is nonnull.
        if (levelInfo->NetMode != 0) { // +0x425.
            AController* controller = levelInfo->ControllerList; // +0x4d4.
            // Captured once even when the list is empty.
            UClass* playerClass = APlayerControllerPrivateStaticClassImport;
            while (controller != nullptr) {
                UClass* type = controller->Class;
                while (type != nullptr && type != playerClass)
                    type = type->GetSuperClass();
                bool isPlayer = type != nullptr || playerClass == nullptr;
                if (isPlayer && controller->Pawn != nullptr) { // +0x3d8; any qualifying controller suffices.
                    byte soundType = this->AR6Pawn::GetSoundGunType(0);
                    this->m_SoundRepInfo->m_NewPawnState = soundType; // +0x396; reload receiver after each query.
                    byte state = this->AR6Pawn::GetAnimState();
                    AR6SoundReplicationInfo* sound = this->m_SoundRepInfo;
                    byte previousPawnState = sound->m_NewPawnState;
                    sound->m_NewPawnState = (byte)((byte)(previousPawnState << 4) + state); // No state nibble mask.
                    byte material = this->AR6Pawn::GetCurrentMaterial();
                    this->m_SoundRepInfo->m_Material = material; // +0x397.
                    // bNetDirty, after all three queries/stores.
                    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa0) |= 0x40000000U;
                    result = 1;
                    break;
                }
                controller = controller->nextController; // +0x3dc; native disjoint tail 1002ce82.
            }
        }
    }
    if (this->m_SoundRepInfo != nullptr && this->Level->NetMode != 1) {
        // IAT -> address of exported g_pEngine -> engine.
        UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
        UClient* client = engine->Client; // +0x44; native does not guard engine.
        // Native viewport header prefix; keep nullable client and separate live count/data reads.
        const NativeArrayHeader32* viewportHeader = client != nullptr ?
            reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
        int localPawn = 0;
        if (client != nullptr && viewportHeader->count != 0) {
            UViewport** viewports = reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
            UViewport* viewport = viewports[0]; // Nonzero count only; no data/first-viewport null check.
            APlayerController* localController = viewport->Actor; // +0x34; this pointer IS checked.
            if (localController != nullptr && localController->Pawn == this)
                localPawn = 1;
        }
        byte soundType = this->AR6Pawn::GetSoundGunType(localPawn);
        this->m_SoundRepInfo->m_GunSoundType = soundType; // +0x39a.
        byte material = this->AR6Pawn::GetCurrentMaterial();
        this->m_SoundRepInfo->m_Material = material;
        byte state = this->AR6Pawn::GetAnimState(); // GetCurrentMaterial preserves ECX=this on every normal path.
        this->m_SoundRepInfo->m_pawnState = state; // +0x398.
        byte teamColor = this->GetTeamColor();
        this->m_SoundRepInfo->m_TeamColor = teamColor; // +0x399.
        byte otherTeamStatus = this->GetStatusOtherTeam();
        this->m_SoundRepInfo->m_StatusOtherTeam = otherTeamStatus; // +0x39b.
        result = 1;
    }
    // No local ownership/cleanup; preserve already-written bytes on exceptions.
    ExceptionList = frame.previousExceptionList;
    return result; // Full int 0/1, plain RET; either block can update independently and both may run.
}

// R6Engine.dll @ 1002ce8d : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AudioInfoCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002cea1 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AudioInfoCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnSetAudioInfo // L"AR6Pawn::SetAudioInfo".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044750 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void SetAudioInfoExceptionHandler(void)
{
    __asm {
        mov eax,offset audioInfoFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002cec0 : AR6Pawn::GetTeamColor
// Maps Rainbow team names zero and two to colors two and one, preserving other-controller fallback two.
uchar __thiscall AR6Pawn::GetTeamColor(void)
{
    AController* controller = this->Controller; // +0x4ec.
    if (controller == nullptr)
        return 0;
    int teamName = 0;
    UClass* classCursor = controller->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6RainbowAI::PrivateStaticClass) {
            AR6RainbowTeam* team = static_cast<AR6RainbowAI*>(controller)->m_TeamManager; // +0x59c.
            teamName = team->m_iRainbowTeamName; // Full signed word at +0x3e0; no null-team check.
            break;
        }
        classCursor = classCursor->GetSuperClass();
    }
    if (teamName == 0)
        return 2;
    if (teamName == 2)
        return 1;
    return 0;
}

// R6Engine.dll @ 1002cf10 : AR6Pawn::GetStatusOtherTeam
// Returns the low byte of a Rainbow controller team's lost-member count, or zero for other controllers.
uchar __thiscall AR6Pawn::GetStatusOtherTeam(void)
{
    AController* controller = this->Controller; // +0x4ec.
    if (controller == nullptr)
        return 0;
    UClass* classCursor = controller->Class;
    while (classCursor != nullptr) {
        if (classCursor == &AR6RainbowAI::PrivateStaticClass) {
            AR6RainbowTeam* team = static_cast<AR6RainbowAI*>(controller)->m_TeamManager; // +0x59c.
            return *(const uchar*)&team->m_iMembersLost; // Low byte at +0x3c4; no null-team check.
        }
        classCursor = classCursor->GetSuperClass();
    }
    return 0;
}

// R6Engine.dll @ 1002cf40 : AR6Pawn::CheckLineOfSight
// Traces enemy points or selected radius probes and feet, retaining the shared hit record and current call arguments.
int __thiscall AR6Pawn::CheckLineOfSight(AActor* originActor, FVector* traceStart, int useLOSFlag, AActor* targetActor,
    FVector* targetPoint, AActor* secondaryActor, FVector* visiblePointOut)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage, including raw constructor outputs.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x94/-0x90/-0x8c.
        uint probeWords[12]; // EBP-0x88..-0x5c.
        NativeCheckResult32 hitWords; // EBP-0x58..-0x2c.
        uint temporaryWords[3]; // EBP-0x28..-0x20; helper output, then coordinate spills.
        uint caught, rethrow, sharedWord; // EBP-0x1c/-0x18/-0x14; sharedWord is plus-X, then maximum index.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CheckLineOfSightExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* currentTarget = targetActor; // Captured before hit initialization and state zero.
    for (int i = 0; i != 9; ++i)
        reinterpret_cast<uint*>(&frame.hitWords)[i] = 0;
    frame.hitWords.materialAddress = 0;
    frame.state = 0;
    AController* controller = this->Controller;
    reinterpret_cast<uint&>(frame.hitWords.Time) = 0x3f800000;
    reinterpret_cast<uint&>(frame.hitWords.Item) = 0xffffffff;
    AActor* enemy = controller->Enemy;
    bool enemyPath = currentTarget == enemy;
    frame.savedEsp = &frame.savedEdi; // Native publishes this only after comparing the captured enemy.
    // EBP+8: origin pointer, distance, minus-X, then minimum score.
    uint& originWord = reinterpret_cast<uint&>(originActor);
    // EBP+0x10: LOS flag, radius, maximum score, then trace-loop index.
    uint& flagWord = reinterpret_cast<uint&>(useLOSFlag);
    uint& pointWord = reinterpret_cast<uint&>(targetPoint); // EBP+0x18: target pointer, second Z, then minimum index.
    uint& outputWord = reinterpret_cast<uint&>(visiblePointOut); // EBP+0x20 also holds the enemy-mid trace receiver.
    auto finish = [&](int value) { ExceptionList = frame.previousExceptionList; return value; };
    auto accepted = [&](AActor* hit) { return hit == nullptr || hit == targetActor || hit == secondaryActor; };
    auto copyReturnedPoint = [&](const uint* point, uint* capturedOutput = nullptr) {
        uint x = point[0]; // Read returned X before reading the incoming output pointer.
        uint* output = capturedOutput != nullptr ? capturedOutput : (uint*)visiblePointOut;
        output[0] = x;
        output[1] = point[1];
        output[2] = point[2];
        return output;
    };
    enum TraceSite { EnemyHead, EnemyMid, OrdinaryMid, OrdinaryHead, RadiusProbe, Foot }; // Local read-order view.
    auto trace = [&](TraceSite site, const FVector* capturedEndpoint = nullptr) {
        const uint* zero;
        uint extent[3];
        ULevel* level;
        byte* vtable;
        if (site == OrdinaryMid || site == Foot) {
            zero = *(const uint**)&FVectorFVector0Import;
            extent[0] = zero[0];
            level = this->XLevel;
            vtable = *(byte**)level;
        } else {
            level = this->XLevel;
            vtable = *(byte**)level;
            if (site == EnemyMid)
                outputWord = (uint)level; // EDI retains visible output while this incoming slot is reused.
            zero = *(const uint**)&FVectorFVector0Import;
            extent[0] = zero[0];
        }
        extent[1] = zero[1];
        extent[2] = zero[2];
        const FVector* start = traceStart;
        const FVector* endpoint = capturedEndpoint;
        ULevel* receiver;
        if (site == EnemyHead || site == RadiusProbe) {
            receiver = this->XLevel;
        } else if (site == EnemyMid) {
            receiver = reinterpret_cast<ULevel*>(outputWord);
        } else {
            endpoint = visiblePointOut;
            receiver = site == OrdinaryHead ? this->XLevel : level;
        }
        using LineCheck = int (__thiscall*)(ULevel*, FCheckResult*, AActor*,
            const FVector*, const FVector*, uint, FVector);
        (*(LineCheck*)(vtable + 0xcc))(receiver, reinterpret_cast<FCheckResult*>(&frame.hitWords), this,
            endpoint, start, 0x20286, *(FVector*)extent); // Ignore result/Time; reuse all hit words.
    };
    FVector* temporary = (FVector*)frame.temporaryWords;
    if (enemyPath) {
        FVector* head = this->AR6Pawn::GetHeadLocation(temporary, enemy);
        uint* capturedOutput = copyReturnedPoint((const uint*)head);
        trace(EnemyHead, (const FVector*)capturedOutput);
        AActor* hit = reinterpret_cast<AActor*>(frame.hitWords.actorAddress);
        if (hit != nullptr && (hit != targetActor || hit != secondaryActor)) {
            AActor* currentEnemy = this->Controller->Enemy;
            FVector* mid = this->AR6Pawn::GetMidSectionLocation(temporary, currentEnemy);
            copyReturnedPoint((const uint*)mid, capturedOutput);
            trace(EnemyMid, (const FVector*)capturedOutput);
            hit = reinterpret_cast<AActor*>(frame.hitWords.actorAddress);
        }
        return finish(accepted(hit) ? 1 : 0);
    }
    FVector* mid = this->AR6Pawn::GetMidSectionLocation(temporary, currentTarget);
    copyReturnedPoint((const uint*)mid);
    trace(OrdinaryMid);
    AActor* hit = reinterpret_cast<AActor*>(frame.hitWords.actorAddress);
    if (hit == nullptr)
        return finish(1);
    currentTarget = targetActor;
    if (hit == currentTarget)
        return finish(1);
    AActor* currentSecondary = secondaryActor;
    if (hit == currentSecondary)
        return finish(1);
    AActor* origin = originActor;
    FVector* retainedTargetPoint = targetPoint; // EDI survives callbacks and reuse of the incoming point slot.
    float10 deltaZ = (float10)retainedTargetPoint->Z - origin->Location.Z;
    float10 deltaY = (float10)retainedTargetPoint->Y - origin->Location.Y;
    float10 deltaX = (float10)retainedTargetPoint->X - origin->Location.X;
    float& distanceOrMinimum = reinterpret_cast<float&>(originWord);
    distanceOrMinimum = (float)((deltaX * deltaX + deltaY * deltaY) + deltaZ * deltaZ);
    if ((float10)distanceOrMinimum > nativeFloat6Point4EPlus07)
        return finish(0);
    bool bypassNearLimit = false;
    if ((*(byte*)((byte*)this->Controller + 0x3a8) & 1U) != 0) {
        APawn* pawn = currentTarget->GetPlayerPawn();
        currentTarget = targetActor; // Reload regardless of the callback result; secondary remains captured.
        bypassNearLimit = pawn != nullptr;
    }
    if (!bypassNearLimit && (float10)distanceOrMinimum > nativeFloat4EPlus06)
        return finish(0);
    if (flagWord == 0 || (*(byte*)((byte*)this->Controller + 0x3a8) & 4U) == 0) {
        FVector* head = this->AR6Pawn::GetHeadLocation(temporary, currentTarget);
        copyReturnedPoint((const uint*)head);
        trace(OrdinaryHead);
        hit = reinterpret_cast<AActor*>(frame.hitWords.actorAddress);
        if (hit == nullptr)
            return finish(1);
        currentTarget = targetActor;
        if (hit == currentTarget)
            return finish(1);
        currentSecondary = secondaryActor;
        if (hit == currentSecondary)
            return finish(1);
    }
    if (flagWord != 0 && (*(byte*)((byte*)this->Controller + 0x3a8) & 4U) == 0)
        return finish(0);
    AActor* radiusActor = currentSecondary != nullptr ? currentSecondary : currentTarget;
    float10 ratioRadius = radiusActor->CollisionRadius;
    float10 radiusRatio = (ratioRadius / (float10)distanceOrMinimum) * ratioRadius;
    if (radiusRatio < nativeFloat0Point0001)
        return finish(0); // Equality/unordered continue; divide then multiply, without a zero-distance repair.
    flagWord = reinterpret_cast<uint&>(radiusActor->CollisionRadius);
    float& radiusOrMaximum = reinterpret_cast<float&>(flagWord);
    using ElementConstructor = void (__thiscall*)(void*);
    ElementConstructor constructVector = reinterpret_cast<ElementConstructor&>(FVectorDefaultConstructorImport);
    ConstructArrayElements(frame.probeWords, 12, 4, constructVector);
    float10 negativeRadius = (float10)radiusOrMaximum * nativeFloatMinus1;
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)negativeRadius;
    float10 firstZ = retainedTargetPoint->Z;
    float10 firstY = (float10)retainedTargetPoint->Y - reinterpret_cast<float&>(frame.temporaryWords[1]);
    float10 firstX = (float10)retainedTargetPoint->X - radiusOrMaximum;
    distanceOrMinimum = (float)firstX;
    reinterpret_cast<float&>(frame.temporaryWords[0]) = (float)firstX;
    frame.probeWords[0] = frame.temporaryWords[0];
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)firstY;
    frame.probeWords[1] = frame.temporaryWords[1];
    reinterpret_cast<float&>(frame.temporaryWords[2]) = (float)firstZ;
    uint firstZWord = frame.temporaryWords[2];
    float10 secondZ = retainedTargetPoint->Z;
    frame.probeWords[2] = firstZWord;
    reinterpret_cast<float&>(pointWord) = (float)secondZ;
    float10 secondY = (float10)radiusOrMaximum + retainedTargetPoint->Y;
    float10 secondX = (float10)radiusOrMaximum + retainedTargetPoint->X;
    reinterpret_cast<float&>(frame.sharedWord) = (float)secondX;
    reinterpret_cast<float&>(frame.temporaryWords[0]) = (float)secondX;
    frame.probeWords[3] = frame.temporaryWords[0];
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)secondY;
    uint secondYWord = frame.temporaryWords[1];
    uint minusXWord = originWord;
    reinterpret_cast<float&>(frame.temporaryWords[2]) = (float)secondZ;
    uint secondZWord = frame.temporaryWords[2];
    float10 thirdY = retainedTargetPoint->Y;
    frame.probeWords[5] = secondZWord;
    thirdY -= radiusOrMaximum;
    frame.probeWords[4] = secondYWord;
    frame.temporaryWords[0] = minusXWord;
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)thirdY;
    uint thirdYWord = frame.temporaryWords[1];
    frame.probeWords[6] = minusXWord;
    reinterpret_cast<float&>(frame.temporaryWords[2]) = (float)firstZ;
    uint thirdZWord = frame.temporaryWords[2];
    uint plusXWord = frame.sharedWord;
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)negativeRadius;
    frame.probeWords[7] = thirdYWord;
    float10 fourthZ = reinterpret_cast<float&>(pointWord);
    float10 fourthY = reinterpret_cast<float&>(frame.temporaryWords[1]);
    frame.temporaryWords[0] = plusXWord;
    fourthY += retainedTargetPoint->Y;
    frame.probeWords[8] = thirdZWord;
    frame.probeWords[9] = plusXWord;
    reinterpret_cast<float&>(frame.temporaryWords[1]) = (float)fourthY;
    frame.probeWords[10] = frame.temporaryWords[1];
    reinterpret_cast<float&>(frame.temporaryWords[2]) = (float)fourthZ;
    uint fourthZWord = frame.temporaryWords[2];
    float10 firstScoreZ = reinterpret_cast<float&>(frame.probeWords[2]);
    frame.probeWords[11] = fourthZWord;
    firstScoreZ *= reinterpret_cast<float&>(frame.probeWords[2]);
    float10 firstScoreY = reinterpret_cast<float&>(frame.probeWords[1]);
    pointWord = 0; // Former target pointer/second Z becomes minimum index.
    firstScoreY *= reinterpret_cast<float&>(frame.probeWords[1]);
    frame.sharedWord = 0; // Former plus-X becomes maximum index.
    float10 firstScore = (firstScoreZ + firstScoreY) +
        (float10)reinterpret_cast<float&>(frame.probeWords[0]) * reinterpret_cast<float&>(frame.probeWords[0]);
    distanceOrMinimum = (float)firstScore;
    radiusOrMaximum = (float)firstScore;
    for (int i = 1; i != 4; ++i) {
        const float* point = (const float*)(frame.probeWords + i * 3);
        float10 z = point[2];
        float10 y = point[1];
        float10 x = point[0];
        float10 score = (x * x + y * y) + z * z;
        if (score > (float10)radiusOrMaximum) {
            frame.sharedWord = (uint)i;
            radiusOrMaximum = (float)score;
        } else if (score < (float10)distanceOrMinimum) {
            pointWord = (uint)i;
            distanceOrMinimum = (float)score; // Compare live extended candidate before rounding a replacement bound.
        }
    }
    uint index = 0;
    for (;;) {
        flagWord = index; // Incoming flag/radius/maximum slot now stores the current trace index, including final 3.
        if ((int)index >= 3)
            break;
        if (index != pointWord && index != frame.sharedWord) {
            uint* output = (uint*)visiblePointOut;
            uint* candidate = frame.probeWords + index * 3;
            output[0] = candidate[0];
            uint y = candidate[1];
            uint z = candidate[2];
            output[1] = y;
            output[2] = z;
            trace(RadiusProbe, (const FVector*)candidate); // Endpoint is the array element, not visible output.
            hit = reinterpret_cast<AActor*>(frame.hitWords.actorAddress);
            if (accepted(hit))
                return finish(1);
            index = flagWord; // Callback may change the actual incoming loop slot.
        }
        ++index;
    }
    FVector* foot = this->AR6Pawn::GetFootLocation(temporary, targetActor);
    copyReturnedPoint((const uint*)foot);
    trace(Foot);
    // Full int/RET 0x1c; no hit reset or cleanup.
    return finish(accepted(reinterpret_cast<AActor*>(frame.hitWords.actorAddress)) ? 1 : 0);
}

// R6Engine.dll @ 1002d53b : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void LineOfSightCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002d54f : report method context and rethrow without adding a funclet frame
__declspec(naked) void LineOfSightCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnCheckLineOfSight // L"AR6Pawn::CheckLineOfSight".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044760 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void CheckLineOfSightExceptionHandler(void)
{
    __asm {
        mov eax,offset lineOfSightFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002d570 : AR6Pawn::R6LineOfSightTo
// Tests an actor and its eligible prone collision box, rotating the visibility selector or caching enemy sight data.
ulong __thiscall AR6Pawn::R6LineOfSightTo(AActor* targetActor, int useLOSFlag)
{
    struct NativeFrameView { // Inferred inherited EBP-relative buffers; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x48/-0x44/-0x40.
        uint eyeWords[3]; // EBP-0x3c..-0x34, uninitialized hidden eye output.
        uint visibleWords[3]; // EBP-0x30..-0x28, shared by both trace calls.
        uint startWords[3]; // EBP-0x24..-0x1c, raw origin snapshot followed by eye additions.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&R6LineOfSightToExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AActor* capturedTarget = targetActor; // EDI retains the entry target through eye/trace callbacks.
    bool missingTarget = capturedTarget == nullptr; // Native comparison precedes state 0 and any Controller read.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&](ulong value) { ExceptionList = frame.previousExceptionList; return value; };
    if (missingTarget)
        return finish(0);
    AController* controller = this->Controller;
    if (controller == nullptr)
        return finish(0);
    APawn* controlledPawn = controller->Pawn;
    UClass* type = this->Class; // Native deliberately class-walks this, not the controller.
    UClass* required = APlayerControllerPrivateStaticClassImport;
    while (type != nullptr && type != required)
        type = type->GetSuperClass();
    uint originOverride = 0;
    if (type != nullptr || required == nullptr)
        // Only under this native self-as-PlayerController gate.
        originOverride = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x5b8);
    AActor* origin = originOverride != 0 || controlledPawn == nullptr ? this : controlledPawn;
    FVector& start = *(FVector*)frame.startWords;
    ((uint*)&start)[0] = ((uint*)&origin->Location)[0];
    ((uint*)&start)[1] = ((uint*)&origin->Location)[1];
    ((uint*)&start)[2] = ((uint*)&origin->Location)[2];
    if (origin == controlledPawn) {
        FVector& eyeStorage = *(FVector*)frame.eyeWords;
        using EyePosition = FVector* (__thiscall*)(APawn*, FVector*);
        FVector* eye = reinterpret_cast<EyePosition&>(APawnEventEyePositionImport)(controlledPawn, &eyeStorage);
        start.X = (float)((float10)start.X + eye->X); // Keep the pre-event Location snapshot, round each addition.
        start.Y = (float)((float10)start.Y + eye->Y);
        start.Z = (float)((float10)start.Z + eye->Z);
    }
    int firstLOSFlag = useLOSFlag; // Current incoming flag precedes clearing the output buffer.
    frame.visibleWords[0] = 0;
    frame.visibleWords[1] = 0;
    frame.visibleWords[2] = 0;
    int visible = this->AR6Pawn::CheckLineOfSight(origin, &start, firstLOSFlag, capturedTarget,
        &capturedTarget->Location, nullptr, (FVector*)frame.visibleWords);
    if (visible == 0) {
        type = capturedTarget->Class;
        while (type != nullptr && type != &AR6Pawn::PrivateStaticClass)
            type = type->GetSuperClass();
        // m_bIsProne.
        if (type != nullptr &&
            (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(capturedTarget) + 0x3e0) & 0x200U) != 0) {
            AActor* secondary = capturedTarget->m_collisionBox;
            if (secondary != nullptr &&
                (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(secondary) + 0xa8) & 0x800U) != 0) {
                int retryLOSFlag = useLOSFlag;
                // bCollideActors; no output reset.
                visible = this->AR6Pawn::CheckLineOfSight(origin, &start, retryLOSFlag, capturedTarget,
                    &secondary->Location, secondary, (FVector*)frame.visibleWords);
            }
        }
        if (visible == 0) {
            uint next = (uint)this->m_iVisibilityTest + 1U;
            this->m_iVisibilityTest = (int)next % 3; // DWORD INC wrap, then signed CDQ/IDIV remainder.
            return finish(0);
        }
    }
    controller = this->Controller; // Current controller after eye/trace callbacks; native does not guard null again.
    if (capturedTarget == controller->Enemy) {
        uint* seen = (uint*)&controller->LastSeenPos;
        seen[0] = frame.visibleWords[0];
        seen[1] = frame.visibleWords[1];
        seen[2] = frame.visibleWords[2];
        controller = this->Controller;
        uint* seeing = (uint*)&controller->LastSeeingPos;
        seeing[0] = ((uint*)&origin->Location)[0]; // Current origin Location, rather than the eye-adjusted start.
        seeing[1] = ((uint*)&origin->Location)[1];
        seeing[2] = ((uint*)&origin->Location)[2];
        ALevelInfo* level = this->Level;
        controller = this->Controller;
        reinterpret_cast<uint&>(controller->LastSeenTime) = reinterpret_cast<uint&>(level->TimeSeconds);
        controller = this->Controller;
        // bEnemyInfoValid; preserve the native reloads/store order.
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(controller) + 0x3a8) |= 0x200U;
    }
    return finish(1); // Normalized full ULONG, RET 8, with no local ownership or exception cleanup actions.
}

// R6Engine.dll @ 1002d76b : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void SightCallerCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002d77f : report method context and rethrow without adding a funclet frame
__declspec(naked) void SightCallerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnR6LineOfSightTo // L"AR6Pawn::R6LineOfSightTo".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044770 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void R6LineOfSightToExceptionHandler(void)
{
    __asm {
        mov eax,offset sightCallerFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002d7a0 : AR6Pawn::UpdatePeeking
// Disables the centered box, advances full peeking, or recomputes the fluid limit before updating collision.
void __thiscall AR6Pawn::UpdatePeeking(float deltaSeconds)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow, previousWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&UpdatePeekingExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    AR6ColBox* initialBox = this->m_collisionBox;
    bool missingBox = initialBox == nullptr; // Tested before state 0 activation.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    auto finish = [&]() { ExceptionList = frame.previousExceptionList; };
    if (missingBox) {
        finish();
        return;
    }
    // m_bWantsToProne/m_bIsProne.
    if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e0) & 0x300U) != 0) {
        if (this->m_ePeekingMode == 1)
            this->AR6Pawn::UpdateFullPeekingMode(deltaSeconds); // Return-to-center flag does not gate this prone route.
        finish();
        return;
    }
    byte mode = this->m_ePeekingMode;
    if (mode == 0) {
        float10 currentPeeking = this->m_fPeeking;
        float10 center = nativeDouble1000;
        if (center == currentPeeking) {
            if ((reinterpret_cast<byte*>(initialBox)[0x394] & 1U) != 0) { // Captured box's m_bActive.
                if (this->APawn::IsLocallyControlled() != 0 ||
                    this->Level->NetMode !=
                    3) {
                    // Reload receiver after IsLocal.
                    this->m_collisionBox->AR6ColBox::EnableCollision(0, 0, 0);
                }
            }
            finish();
            return;
        }
    }
    if (mode == 1 && (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4) & 0x02000000U) == 0) {
        this->AR6Pawn::UpdateFullPeekingMode(deltaSeconds);
        finish();
        return;
    }
    if (mode != 2) {
        finish();
        return;
    }
    uint rateWord = reinterpret_cast<uint&>(this->m_fCrouchBlendRate);
    uint previousWord = reinterpret_cast<uint&>(this->m_fPeeking);
    uint goalWord = reinterpret_cast<uint&>(this->m_fPeekingGoal);
    frame.previousWord = previousWord;
    reinterpret_cast<uint&>(this->m_fPeeking) = goalWord;
    this->AR6Pawn::AdjustFluidCollisionCylinder(reinterpret_cast<float&>(rateWord), 0);
    // Read side before current blend rate.
    uint sideWord = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3e4);
    uint currentRateWord = reinterpret_cast<uint&>(this->m_fCrouchBlendRate);
    // Incoming EBP+8 becomes bound, adjusted value and collision-return spill.
    uint& argumentWord = reinterpret_cast<uint&>(deltaSeconds);
    deltaSeconds = (float)this->AR6Pawn::GetMaxFluidPeeking(reinterpret_cast<float&>(currentRateWord),
        (int)(sideWord >> 31));
    uint boundWord = argumentWord;
    uint currentWord = reinterpret_cast<uint&>(this->m_fPeeking);
    deltaSeconds = (float)this->AR6Pawn::AdjustMaxFluidPeeking(reinterpret_cast<float&>(currentWord),
        reinterpret_cast<float&>(boundWord));
    float10 adjustedForComparison = deltaSeconds;
    uint adjustedWord = argumentWord;
    float10 previousForComparison = reinterpret_cast<float&>(frame.previousWord);
    // Captured comparisons precede this store; FUCOMPP follows it.
    reinterpret_cast<uint&>(this->m_fPeeking) = adjustedWord;
    bool updateBox = previousForComparison != adjustedForComparison;
    if (!updateBox && (reinterpret_cast<byte*>(this)[0x3e8] & 0x10U) != 0) {
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        const float* velocity = (const float*)&this->Velocity;
        auto componentAtRest = [&](int component) {
            float10 zeroComponent = ((const float*)zero)[component];
            float10 velocityComponent = velocity[component];
            return velocityComponent == zeroComponent;
        };
        bool atRest = componentAtRest(0) && componentAtRest(1) && componentAtRest(2);
        updateBox = !atRest || (reinterpret_cast<byte*>(this)[0xac] & 2U) != 0;
    }
    if (updateBox) {
        uint packetWord = argumentWord; // Read the actual spill after the changed/player/velocity gates.
        deltaSeconds = (float)this->AR6Pawn::UpdateColBoxPeeking(reinterpret_cast<float&>(packetWord));
        uint acceptedWord = argumentWord;
        reinterpret_cast<uint&>(this->m_fPeeking) = acceptedWord;
    }
    finish(); // Void RET4; all three native float returns spill through the incoming argument word.
}

// R6Engine.dll @ 1002d9af : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void UpdatePeekingCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002d9c3 : report method context and rethrow without adding a funclet frame
__declspec(naked) void UpdatePeekingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUpdatePeeking // L"AR6Pawn::UpdatePeeking".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044780 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void UpdatePeekingExceptionHandler(void)
{
    __asm {
        mov eax,offset updatePeekingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002daa0 : AR6Pawn::execPawnLook
// Evaluates the aggregate and two flags, retaining frame/input aliases through optional DebugInfo before pose
// selection.
// Native ABI view retains the incoming frame word for the no-blend operand.
void __thiscall AR6Pawn::execPawnLook(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; required aggregate starts uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x34/-0x30/-0x2c.
        uint operandWords[3]; // EBP-0x28..-0x20.
        uint caught, rethrow, aimWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execPawnLookExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = stack; // Retained ESI; incoming EBP+8 later becomes the noBlend evaluator output.
    uint& noBlendWord = reinterpret_cast<uint&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    frame.state = 0;
    natives[opcode](receiver, expressionStack, frame.operandWords);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    frame.aimWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &frame.aimWord);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    noBlendWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &noBlendWord);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    uint currentNoBlend = noBlendWord;
    uint currentAim = frame.aimWord;
    uint x = frame.operandWords[0];
    uint y = frame.operandWords[1];
    uint z = frame.operandWords[2];
    uint packetWords[3] = { x, y, z };
    capturedPawn->AR6Pawn::PawnLook(*(FRotator*)packetWords, (int)currentAim, (int)currentNoBlend);
    ExceptionList = frame.previousExceptionList; // Void RET8; script result remains untouched.
}

// R6Engine.dll @ 1002db7a : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ExecPawnLookCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002db8e : report script bridge context and rethrow without adding a funclet frame
__declspec(naked) void ExecPawnLookCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecPawnLook // L"AR6Pawn::execPawnLook".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447a0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execPawnLookExceptionHandler(void)
{
    __asm {
        mov eax,offset execPawnLookFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002dbb0 : AR6Pawn::execPawnLookAbsolute
// Evaluates the aggregate and two flags, retaining frame/input aliases through optional DebugInfo before pose
// selection.
// Native ABI view retains the incoming frame word for the no-blend operand.
void __thiscall AR6Pawn::execPawnLookAbsolute(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; required aggregate starts uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x34/-0x30/-0x2c.
        uint operandWords[3]; // EBP-0x28..-0x20.
        uint caught, rethrow, aimWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execPawnLookAbsoluteExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = stack; // Retained ESI; incoming EBP+8 later becomes the noBlend evaluator output.
    uint& noBlendWord = reinterpret_cast<uint&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    frame.state = 0;
    natives[opcode](receiver, expressionStack, frame.operandWords);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    frame.aimWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &frame.aimWord);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    noBlendWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &noBlendWord);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    uint currentNoBlend = noBlendWord;
    uint currentAim = frame.aimWord;
    uint x = frame.operandWords[0];
    uint y = frame.operandWords[1];
    uint z = frame.operandWords[2];
    uint packetWords[3] = { x, y, z };
    capturedPawn->AR6Pawn::PawnLookAbsolute(*(FRotator*)packetWords, (int)currentAim, (int)currentNoBlend);
    ExceptionList = frame.previousExceptionList; // Void RET8; script result remains untouched.
}

// R6Engine.dll @ 1002dc8a : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ExecPawnLookAbsoluteCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002dc9e : report script bridge context and rethrow without adding a funclet frame
__declspec(naked) void ExecPawnLookAbsoluteCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecPawnLookAbsolute // L"AR6Pawn::execPawnLookAbsolute".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447b0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execPawnLookAbsoluteExceptionHandler(void)
{
    __asm {
        mov eax,offset execPawnLookAbsoluteFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002dcc0 : AR6Pawn::execPawnLookAt
// Evaluates the aggregate and two flags, retaining frame/input aliases through optional DebugInfo before pose
// selection.
// Native ABI view retains the incoming frame word for the no-blend operand.
void __thiscall AR6Pawn::execPawnLookAt(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Inferred inherited EBP-relative storage; required aggregate starts uninitialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x34/-0x30/-0x2c.
        uint operandWords[3]; // EBP-0x28..-0x20.
        uint caught, rethrow, aimWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execPawnLookAtExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = stack; // Retained ESI; incoming EBP+8 later becomes the noBlend evaluator output.
    uint& noBlendWord = reinterpret_cast<uint&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    frame.state = 0;
    natives[opcode](receiver, expressionStack, frame.operandWords);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    frame.aimWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &frame.aimWord);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    noBlendWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &noBlendWord);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    uint currentNoBlend = noBlendWord;
    uint currentAim = frame.aimWord;
    uint x = frame.operandWords[0];
    uint y = frame.operandWords[1];
    uint z = frame.operandWords[2];
    uint packetWords[3] = { x, y, z };
    capturedPawn->AR6Pawn::PawnLookAt(*(FVector*)packetWords, (int)currentAim, (int)currentNoBlend);
    ExceptionList = frame.previousExceptionList; // Void RET8; script result remains untouched.
}

// R6Engine.dll @ 1002dd9a : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ExecPawnLookAtCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x18]
        push edx
        mov dword ptr [ebp-0x18],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002ddae : report script bridge context and rethrow without adding a funclet frame
__declspec(naked) void ExecPawnLookAtCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecPawnLookAt // L"AR6Pawn::execPawnLookAt".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447c0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execPawnLookAtExceptionHandler(void)
{
    __asm {
        mov eax,offset execPawnLookAtFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002ddd0 : AR6Pawn::execUpdatePawnTrackActor
// Evaluates tracking operands and updates immediately, leaving terminator and DebugInfo bytes unconsumed.
void __thiscall AR6Pawn::execUpdatePawnTrackActor(FFrame& stack, void* unusedResult)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow, operandWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execUpdatePawnTrackActorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = &stack;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    frame.operandWord = 0; // Default is written before reading the opcode, while state is still -1.
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport; // This bridge reads Object before the table.
    frame.state = 0;
    natives[opcode](receiver, expressionStack, &frame.operandWord);
    uint noBlendWord = frame.operandWord;
    capturedPawn->AR6Pawn::UpdatePawnTrackActor((int)noBlendWord);
    ExceptionList = frame.previousExceptionList; // Void RET8; no later Code access or script-result write.
}

// R6Engine.dll @ 1002de3c : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ExecUpdatePawnTrackActorCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002de50 : report script bridge context and rethrow without adding a funclet frame
__declspec(naked) void ExecUpdatePawnTrackActorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecUpdatePawnTrackActor // L"AR6Pawn::execUpdatePawnTrackActor".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447d0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execUpdatePawnTrackActorExceptionHandler(void)
{
    __asm {
        mov eax,offset execUpdatePawnTrackActorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002de70 : AR6Pawn::PawnTrackActor
// Sets the aim flag from the input's low bit, stores the tracked actor and updates tracking immediately.
void __thiscall AR6Pawn::PawnTrackActor(AActor* actor, int aimInput)
{
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c4);
    uint pawnFlags = *destinationFlags;
    pawnFlags ^= (((uint)aimInput << 29) ^ pawnFlags) & 0x20000000U; // m_bAim.
    *destinationFlags = pawnFlags;
    this->m_TrackActor = actor; // +0x7c0.
    this->AR6Pawn::UpdatePawnTrackActor(1);
}

// R6Engine.dll @ 1002dea0 : AR6Pawn::execPlayVoices
// Evaluates voice operands and relays to eligible player controllers, rereading packet data after callbacks.
// Native ABI view retains the incoming frame word for the voice send-mode byte.
void __thiscall AR6Pawn::execPlayVoices(FFrame* stack, void* unusedResult)
{
    struct NativeStackView { // Inferred entry-ESP-relative storage; this body has no local exception registration.
        uint savedEdi, savedEsi, savedEbx; // Entry ESP-0x20/-0x1c/-0x18.
        uint timeWord, waitWord, priorityWord; // Entry ESP-0x14/-0x10/-0x0c.
        uint slotWord, soundWord; // Entry ESP-0x08/-0x04; only slotWord's low byte is initialized/evaluated.
    } scratch;
    FFrame* expressionStack = stack;
    // Incoming Frame argument's low byte becomes eSend; ESI retains the Frame.
    byte& sendMode = reinterpret_cast<byte&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    scratch.soundWord = 0;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    natives[opcode](receiver, expressionStack, &scratch.soundWord);
    auto evaluateNext = [&](void* output, int width) {
        byte* currentCode = expressionStack->Code;
        if (width == 1)
            *(byte*)output = 0;
        else
            *(uint*)output = 0;
        byte currentOpcode = *currentCode;
        UObject* currentReceiver = expressionStack->Object;
        expressionStack->Code = currentCode + 1;
        ScriptNative* currentTable = *(ScriptNative**)&CoreGNativesImport;
        currentTable[currentOpcode](currentReceiver, expressionStack, output);
    };
    evaluateNext(&scratch.slotWord, 1);
    evaluateNext(&scratch.priorityWord, 4);
    evaluateNext(&sendMode, 1);
    evaluateNext(&scratch.waitWord, 4);
    evaluateNext(&scratch.timeWord, 4);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    capturedPawn->AR6Pawn::SetAudioInfo(); // Its result does not gate voice relay.
    int human = capturedPawn->APawn::IsHumanControlled();
    auto isR6PlayerController = [&](AController* candidate) {
        UClass* type = candidate->Class;
        while (type != nullptr) {
            if (type == &AR6PlayerController::PrivateStaticClass)
                return true;
            type = type->GetSuperClass();
        }
        return false;
    };
    auto relay = [&](AController* recipient) {
        uint timeWord = scratch.timeWord;
        uint waitWord = scratch.waitWord;
        uint priorityWord = scratch.priorityWord;
        uint slotWord = scratch.slotWord;
        uint soundWord = scratch.soundWord;
        AR6SoundReplicationInfo* info = capturedPawn->m_SoundRepInfo;
        // Raw ABI view: native pushes the containing slot DWORD; the event wrapper consumes only its low byte.
        using ClientVoicePacket = void (__thiscall*)(AR6PlayerController*, AR6SoundReplicationInfo*, USound*,
            uint, int, uint, float);
        ((ClientVoicePacket)&AR6PlayerControllerEventClientPlayVoicesNativeEntry)(
            static_cast<AR6PlayerController*>(recipient), info, reinterpret_cast<USound*>(soundWord),
            slotWord, (int)priorityWord, waitWord, reinterpret_cast<float&>(timeWord));
    };
    if (human == 0 && capturedPawn->m_ePawnType != 1) {
        AController* recipient = capturedPawn->Level->ControllerList;
        while (recipient != nullptr) {
            if (isR6PlayerController(recipient))
                relay(recipient);
            recipient = recipient->nextController; // Read after relay, while retaining the current list node.
        }
        return;
    }
    AController* recipient = capturedPawn->Level->ControllerList;
    while (recipient != nullptr) {
        if (isR6PlayerController(recipient)) {
            bool eligible = true;
            ALevelInfo* currentLevel = capturedPawn->Level;
            if (currentLevel->NetMode != 0) {
                byte currentMode = sendMode;
                if (currentMode == 0) {
                    AController* source = capturedPawn->Controller;
                    using GetTeamManager = AActor* (__thiscall*)(AController*);
                    AActor* sourceTeam = (*(GetTeamManager*)(*(byte**)source + 0x1a0))(source);
                    AActor* recipientTeam = (*(GetTeamManager*)(*(byte**)recipient + 0x1a0))(recipient);
                    eligible = recipientTeam == sourceTeam; // Source result stays captured across the second callback.
                } else if (currentMode == 1) {
                    APawn* pawn = recipient->Pawn;
                    eligible = pawn != nullptr && pawn->m_iTeam == capturedPawn->m_iTeam;
                } else {
                    eligible = currentMode == 2;
                }
            }
            if (eligible)
                relay(recipient);
        }
        recipient = recipient->nextController;
    }
    // Void RET8; no script-result access, local cleanup, authority check or output rollback.
}

// R6Engine.dll @ 1002e0e0 : AR6Pawn::execSetAudioInfo
// Consumes the terminator, runs optional DebugInfo, then refreshes audio without writing the script result.
void __thiscall AR6Pawn::execSetAudioInfo(FFrame& stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte** codeCursor = &stack.Code;
    byte* code = *codeCursor + 1;
    *codeCursor = code;
    if (*code == 0x42) {
        *codeCursor = code + 1;
        UObject* expressionReceiver = stack.Object;
        ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](expressionReceiver, &stack, nullptr);
    }
    this->AR6Pawn::SetAudioInfo();
}

// R6Engine.dll @ 1002e120 : AR6Pawn::execSendPlaySound
// Relays sounds missing from normal actor replication, then applies the local-audio gates.
// Native ABI view retains the incoming frame word for the sound-slot byte and containing word.
void __thiscall AR6Pawn::execSendPlaySound(FFrame* stack, void* unusedResult)
{
    struct NativeStackView { // Inferred entry-ESP-relative storage; no local exception registration.
        uint savedEdi, savedEsi, savedEbp, savedEbx; // Entry ESP-0x20/-0x1c/-0x18/-0x14.
        AR6Pawn* savedPawn; // Entry ESP-0x10, reloaded after the sound-relevance path.
        uint soundWord, doNotPlayLocallyWord, pawnKey; // Entry ESP-0x0c/-0x08/-0x04.
    } scratch;
    FFrame* expressionStack = stack;
    // Incoming Frame argument's low byte becomes the slot; ESI retains Frame.
    byte& soundSlot = reinterpret_cast<byte&>(stack);
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    scratch.soundWord = 0;
    byte opcode = *code;
    expressionStack->Code = code + 1;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* livePawn = this;
    UObject* receiver = expressionStack->Object;
    scratch.savedPawn = livePawn;
    natives[opcode](receiver, expressionStack, &scratch.soundWord);
    auto evaluateNext = [&](void* output, int width) {
        byte* currentCode = expressionStack->Code;
        if (width == 1)
            *(byte*)output = 0;
        else
            *(uint*)output = 0;
        byte currentOpcode = *currentCode;
        UObject* currentReceiver = expressionStack->Object;
        expressionStack->Code = currentCode + 1;
        ScriptNative* currentTable = *(ScriptNative**)&CoreGNativesImport;
        currentTable[currentOpcode](currentReceiver, expressionStack, output);
    };
    evaluateNext(&soundSlot, 1);
    evaluateNext(&scratch.doNotPlayLocallyWord, 4);
    code = expressionStack->Code + 1;
    expressionStack->Code = code;
    if (*code == 0x42) {
        receiver = expressionStack->Object;
        expressionStack->Code = code + 1;
        natives = *(ScriptNative**)&CoreGNativesImport;
        natives[0x42](receiver, expressionStack, nullptr);
    }
    if (livePawn->AR6Pawn::SetAudioInfo() == 0)
        return;
    using IsNetRelevant = int (__thiscall*)(AActor*, APlayerController*, AActor*, FVector);
    auto testRelevance = [&](AActor* actor, byte* capturedVtable, APlayerController* recipient, APawn* pawn) {
        uint eyeWords[3]; // Outgoing packet at entry ESP-0x2c..-0x24; raw words avoid float conversion.
        eyeWords[0] = reinterpret_cast<uint&>(pawn->m_vEyeLocation.X);
        uint eyeY = reinterpret_cast<uint&>(pawn->m_vEyeLocation.Y);
        uint eyeZ = reinterpret_cast<uint&>(pawn->m_vEyeLocation.Z);
        eyeWords[1] = eyeY;
        eyeWords[2] = eyeZ;
        return (*(IsNetRelevant*)(capturedVtable + 0x100))(actor, recipient, pawn, *(FVector*)eyeWords);
    };
    if (livePawn->Role == 4) { // ROLE_Authority.
        ALevelInfo* level = livePawn->Level;
        if (level->NetMode != 0) {
            APlayerController* recipient = reinterpret_cast<APlayerController*>(level->ControllerList);
            if (recipient != nullptr) {
                UClass* targetClass = APlayerControllerPrivateStaticClassImport;
                do {
                    UClass* type = recipient->Class;
                    while (type != nullptr && type != targetClass)
                        type = type->GetSuperClass();
                    if (type == targetClass) { // Native also accepts exhausted ancestry when targetClass is null.
                        APawn* recipientPawn = recipient->Pawn;
                        if (recipientPawn != nullptr) {
                            byte* pawnTable = *(byte**)livePawn;
                            if (testRelevance(livePawn, pawnTable, recipient, recipientPawn) == 0) {
                                AActor* info = livePawn->m_SoundRepInfo;
                                recipientPawn = recipient->Pawn; // Fresh pawn and eye data after the first callback.
                                byte* infoTable = *(byte**)info;
                                if (testRelevance(info, infoTable, recipient, recipientPawn) != 0) {
                                    int player = reinterpret_cast<int>(recipient->Player);
                                    int connection = CastToUNetConnection(player);
                                    livePawn = scratch.savedPawn; // Reload occurs even when the cast returns null.
                                    if (connection != 0) {
                                        scratch.pawnKey = reinterpret_cast<uint>(livePawn);
                                        if (FindPointerMapWord((void*)(connection + 0x4b94), &scratch.pawnKey) == 0) {
                                            uint slotWord = reinterpret_cast<uint&>(stack);
                                            uint soundWord = scratch.soundWord;
                                            AActor* currentInfo = livePawn->m_SoundRepInfo;
                                            // Raw caller ABI: eventClientHearSound consumes only this DWORD's low byte.
                                            using HearSoundPacket = void (__thiscall*)(APlayerController*, AActor*,
                                                USound*, uint);
                                            reinterpret_cast<HearSoundPacket&>(
                                                APlayerControllerEventClientHearSoundImport)(
                                                recipient, currentInfo, reinterpret_cast<USound*>(soundWord), slotWord);
                                        }
                                    }
                                } else {
                                    livePawn = scratch.savedPawn;
                                }
                            }
                            // Reload only after a matched, nonnull-pawn path.
                            targetClass = APlayerControllerPrivateStaticClassImport;
                        }
                    }
                    // Read after all callbacks.
                    recipient = reinterpret_cast<APlayerController*>(recipient->nextController);
                } while (recipient != nullptr);
            }
        }
    }
    byte* engineGlobal = *(byte**)&EngineGPEngineImport;
    byte* engine = *(byte**)engineGlobal;
    void* audio = *(void**)(engine + 0x48);
    if (audio == nullptr)
        return;
    ALevelInfo* level = livePawn->Level;
    if (level->NetMode == 1) // NM_DedicatedServer.
        return;
    uint doNotPlayLocally = scratch.doNotPlayLocallyWord;
    if (doNotPlayLocally != 0 && livePawn->APawn::IsLocallyControlled() != 0)
        return;
    engineGlobal = *(byte**)&EngineGPEngineImport;
    engine = *(byte**)engineGlobal;
    audio = *(void**)(engine + 0x48); // Reload after local-control call, without another null check.
    uint localSlot = soundSlot; // Local audio zero-extends the BYTE, unlike the network packet.
    byte* audioTable = *(byte**)audio;
    uint localSound = scratch.soundWord;
    AActor* currentInfo = livePawn->m_SoundRepInfo;
    using LocalAudio = void (__thiscall*)(void*, AActor*, USound*, uint, int);
    (*(LocalAudio*)(audioTable + 0x84))(audio, currentInfo, reinterpret_cast<USound*>(localSound), localSlot, 0);
    // Void RET8; script result untouched, no owned sound or local cleanup.
}

// R6Engine.dll @ 1002e360 : AR6Pawn::UpdateMovementAnimation
// Drains queued actions and updates aiming, movement, peeking and weapon animation before saving acceleration.
void __thiscall AR6Pawn::UpdateMovementAnimation(float deltaSecondsSlot)
{
  // The incoming delta slot is later reused for script and trace packets; raw aliases remain intentional.
  // Descriptive 32-bit frame view: packets and vector outputs deliberately overlap in native EBP-relative storage.
  struct MovementFrame {
    uint savedEDI, savedESI, savedEBX;
    byte localBytes[0x8c];
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } frame;
  byte* const frameTop = (byte*)&frame + 0xa8; // Native EBP; localBytes cover EBP-9c through EBP-11.
  FVector& scratch60 = *(FVector*)(frameTop - 0x60);
  FVector& scratch50 = *(FVector*)(frameTop - 0x50);
  FVector& scratch40 = *(FVector*)(frameTop - 0x40);
  FVector& scratch30 = *(FVector*)(frameTop - 0x30);
  uint* aimVectorWords = (uint*)&scratch60;
  float& sideBias = *(float*)(frameTop - 0x54);
  float& forwardBias = *(float*)(frameTop - 0x44);
  float& scalar34 = *(float*)(frameTop - 0x34);
  int& isLocallyControlled = *(int*)(frameTop - 0x24);
  float& savedOffset734 = *(float*)(frameTop - 0x24);
  float& scaledDelta = *(float*)(frameTop - 0x20);
  float& heightSpill = *(float*)(frameTop - 0x1c);
  USkeletalMeshInstance*& meshInstance = *reinterpret_cast<USkeletalMeshInstance**>(frameTop - 0x18);
  float& movementRate = *(float*)(frameTop - 0x14);
  frame.exceptionState = -1;
  frame.exceptionHandler = &UpdateMovementAnimationExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  byte* pawnBytes = (byte*)this;
  byte initialLocalAction = pawnBytes[0x66b]; // m_iLocalCurrentActionIndex is read before state zero.
  bool localActionDisabled = initialLocalAction == 0xff; // Native CMP also precedes state zero.
  frame.savedEsp = &frame.savedEDI;
  frame.exceptionState = 0;
  using FindChecked = UFunction* (__thiscall*)(UObject*, FName, int);
  using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
  FindChecked cachedFind;
  byte initialNetAction = 0;
  if (!localActionDisabled) initialNetAction = pawnBytes[0x66a]; // m_iNetCurrentActionIndex.
  if (!localActionDisabled && initialLocalAction != initialNetAction) {
    if (initialNetAction >= 5) {
      appFailAssert(
          "m_iNetCurrentActionIndex>=0 && m_iNetCurrentActionIndex<UCONST_C_MaxPendingAction",
          ".\\Src\\AR6Pawn.cpp", 0x468);
    }
    using IsAlive = int (__thiscall*)(APawn*);
    IsAlive cachedIsAlive = reinterpret_cast<IsAlive&>(APawnIsAliveImport);
    cachedFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
    struct PendingActionParameters { byte action; byte padding[3]; int parameter; };
    PendingActionParameters& actionParameters = *(PendingActionParameters*)(frameTop - 0x2c);
    do {
      byte next = (byte)(pawnBytes[0x66b] + 1);
      pawnBytes[0x66b] = next;
      if (next >= 5) pawnBytes[0x66b] = 0; // Native publishes the increment before its optional wrap store.
      if (cachedIsAlive(this) != 0) {
        byte slot = pawnBytes[0x66b]; // The provider may have changed the local index.
        int parameter = *(int*)(pawnBytes + 0x678 + (uint)slot * 4);
        byte action = pawnBytes[0x665 + slot];
        actionParameters.parameter = parameter;
        FName eventName = R6ENGINE_PlaySpecialPendingAction;
        actionParameters.action = action; // Three padding bytes remain untouched between iterations.
        UFunction* function = cachedFind(this, eventName, 0);
        ProcessEvent process = *(ProcessEvent*)(*(byte**)this + 0x10);
        process(this, function, &actionParameters, nullptr);
      }
    } while (pawnBytes[0x66b] != pawnBytes[0x66a]);
  } else {
    cachedFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
  }
  if ((pawnBytes[0xa4] & 0x20) != 0) { // m_bUseRagdoll.
    if ((*(uint*)(pawnBytes + 0x3e4) & 0x10000000) == 0) { // bPlayedDeath.
      const FVector* zero = *(const FVector**)&FVectorFVector0Import;
      FVector* momentum = (FVector*)(pawnBytes + 0x5cc); // TearOffMomentum.
      float10 zeroX = zero->X;
      float10 momentumX = momentum->X;
      bool hasMomentum = momentumX != zeroX;
      if (!hasMomentum) {
        float10 zeroY = zero->Y;
        float10 momentumY = momentum->Y;
        hasMomentum = momentumY != zeroY;
      }
      if (!hasMomentum) {
        float10 zeroZ = zero->Z;
        float10 momentumZ = momentum->Z;
        hasMomentum = momentumZ != zeroZ;
      }
      if (hasMomentum) {
        UFunction* function = cachedFind(this, R6ENGINE_SpawnRagDoll, 0);
        ProcessEvent process = *(ProcessEvent*)(*(byte**)this + 0x10);
        process(this, function, nullptr, nullptr);
      }
    }
    ExceptionList = frame.previousExceptionList;
    return;
  }
  UMesh* mesh = this->Mesh;
  mesh->MeshGetInstance(this); // Its return word is ignored.
  meshInstance = static_cast<USkeletalMeshInstance*>(this->MeshInstance); // Reload the pawn field after the callback.
  if (meshInstance == nullptr) {
    ExceptionList = frame.previousExceptionList;
    return;
  }
  UClass* instanceClass = meshInstance->Class;
  UClass* skeletalClass = USkeletalMeshInstancePrivateStaticClassImport;
  while (instanceClass != nullptr && instanceClass != skeletalClass) {
    instanceClass = instanceClass->GetSuperClass();
  }
  if (instanceClass == nullptr && skeletalClass != nullptr) {
    ExceptionList = frame.previousExceptionList;
    return;
  }
  int localControlResult = this->APawn::IsLocallyControlled();
  byte aimingPawnType = pawnBytes[0x39e];
  isLocallyControlled = localControlResult; // The type-byte read precedes this full-word frame store.
  if (aimingPawnType == 1) { // m_ePawnType.
    if ((pawnBytes[0x3e8] & 0x10) == 0) { // m_bIsPlayer.
      static_cast<AR6Rainbow*>(this)->AR6Rainbow::UpdateAiming();
    } else if (isLocallyControlled == 0) {
      FVector& normalizedVelocity = scratch50;
      uint velocityX = *(uint*)(pawnBytes + 0x24c);
      int& diagonalStateChanged = reinterpret_cast<int&>(heightSpill);
      diagonalStateChanged = 0;
      uint velocityY = *(uint*)(pawnBytes + 0x250);
      uint velocityZ = *(uint*)(pawnBytes + 0x254);
      reinterpret_cast<uint&>(normalizedVelocity.Z) = velocityZ;
      reinterpret_cast<uint&>(normalizedVelocity.X) = velocityX;
      reinterpret_cast<uint&>(normalizedVelocity.Y) = velocityY;
      normalizedVelocity.Normalize();
      FVector* facing = &(*(FVector*)aimVectorWords = ((FRotator*)(pawnBytes + 0x240))->Vector());
      float10 yProduct = (float10)normalizedVelocity.Y * facing->Y;
      float10 zProduct = (float10)normalizedVelocity.Z * facing->Z;
      float10 yz = yProduct + zProduct;
      float10 xProduct = (float10)normalizedVelocity.X * facing->X;
      float10 dot = yz + xProduct;
      volatile float& dotSpill = scalar34;
      dotSpill = (float)dot; // FST retains the extended operand for the first comparison.
      float10 magnitude = dot >= 0.0f ? dot : -dot; // Unordered follows native FCHS too.
      bool diagonalCandidate = magnitude < nativeDouble0Point8; // Double0.8, not its float approximation.
      if (diagonalCandidate) {
        diagonalCandidate = NegateNegativeOrUnordered(dotSpill) > nativeDouble0Point6; // Double0.6.
      }
      if (diagonalCandidate) {
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        FVector* velocity = (FVector*)(pawnBytes + 0x24c); // Reload after both math callbacks.
        float10 zeroX = zero->X;
        float10 velocityX = velocity->X;
        bool moving = velocityX != zeroX;
        if (!moving) {
          float10 zeroY = zero->Y;
          float10 velocityY = velocity->Y;
          moving = velocityY != zeroY;
        }
        if (!moving) {
          float10 zeroZ = zero->Z;
          float10 velocityZ = velocity->Z;
          moving = velocityZ != zeroZ;
        }
        diagonalCandidate = moving;
      }
      if (diagonalCandidate) {
        if (this->AR6Pawn::DirectionHasChanged(dotSpill) != 0 || (*(uint*)(pawnBytes + 0x6c8) & 0x20000) == 0) {
          *(uint*)(pawnBytes + 0x6c8) |= 0x20000; // m_bMovingDiagonally is published before its event.
          this->AR6Pawn::eventAdjustPawnForDiagonalStrafing();
          diagonalStateChanged = true;
        }
      } else if ((*(uint*)(pawnBytes + 0x6c8) & 0x20000) != 0) {
        this->AR6Pawn::eventResetDiagonalStrafing();
        *(uint*)(pawnBytes + 0x6c8) &= ~0x20000u; // Preserve other bits changed by the event.
        diagonalStateChanged = true;
      }
      FVector* currentAcceleration = (FVector*)(pawnBytes + 0x258);
      if ((currentAcceleration->X != 0.0f || currentAcceleration->Y != 0.0f || currentAcceleration->Z != 0.0f) &&
          (*(uint*)(pawnBytes + 0x6c8) & 0x20000) == 0) {
        *(uint*)(pawnBytes + 0x5f4) = 0; // m_rRotationOffset.Yaw.
      }
      if ((*(uint*)(pawnBytes + 0x3e0) & 0x200) != 0) { // m_bIsProne.
        byte firing = pawnBytes[0x39d];
        this->AR6Pawn::PawnLook(*(FRotator*)(pawnBytes + 0x5f0), (int)firing, firing == 0);
      } else if (!diagonalStateChanged) {
        if ((*(uint*)(pawnBytes + 0x6c8) & 0x20000) != 0) {
          byte strafe = pawnBytes[0x674];
          *(uint*)(pawnBytes + 0x5f4) = strafe == 1 || strafe == 4 ? 0xffffe93f : 0x16c1;
          this->AR6Pawn::PawnLook(*(FRotator*)(pawnBytes + 0x5f0), 1, 1);
          *(uint*)(pawnBytes + 0x5f4) = 0;
        } else if ((*(uint*)(pawnBytes + 0x6c4) & 0x200) != 0 || pawnBytes[0x39d] != 0 ||
                   *(float*)(pawnBytes + 0x75c) > 0.0f) {
          this->AR6Pawn::PawnLook(*(FRotator*)(pawnBytes + 0x5f0), 1, 1);
        } else {
          this->AR6Pawn::PawnLook(*(FRotator*)(pawnBytes + 0x5f0), 0, 1);
        }
      }
      uint cancelFlags = *(uint*)(pawnBytes + 0x6c4);
      if ((((cancelFlags >> 1) ^ cancelFlags) & 0x8000) != 0) { // Current/old server-cancel toggle differs.
        // Native outgoing FName storage is recorded at EBP-28.
        reinterpret_cast<uint&>(scratch30.Z) = (uint)((byte*)frame.savedEsp - 8);
        *(uint*)(pawnBytes + 0x6c4) = cancelFlags & ~0x40000000u; // Clear m_bPostureTransition.
        pawnBytes[0x66c] = 0; // m_ePlayerIsUsingHands.
        meshInstance->USkeletalMeshInstance::SetBlendParams(1, 0.0f, 0.0f, 0.0f, FName(0), 0);
        meshInstance->ClearChannel(1);
        this->APawn::eventPlayWeaponAnimation();
        cancelFlags = *(uint*)(pawnBytes + 0x6c4);
        *(uint*)(pawnBytes + 0x6c4) = cancelFlags ^ (((cancelFlags * 2) ^ cancelFlags) & 0x10000);
      }
    }
    float* firingTimer = (float*)(pawnBytes + 0x75c);
    if (*firingTimer > 0.0f) *firingTimer = (float)((float10)*firingTimer - deltaSecondsSlot);
    if (*firingTimer < 0.0f) *(uint*)firingTimer = 0; // Ordered comparisons leave NaNs and negative zero untouched.
  }
  if (isLocallyControlled == 0 && (*(uint*)(pawnBytes + 0x3e0) & 0x200) != 0) {
    using RotationRequest = uint (__thiscall*)(AR6Pawn*, void*, uint, uint, uint);
    (*(RotationRequest*)(*(byte**)this + 0xb4))(this, aimVectorWords, 0, 1, 0); // Exact native packet; return ignored.
  }
  if (pawnBytes[0x39e] == 2) static_cast<AR6Terrorist*>(this)->AR6Terrorist::UpdateAiming(deltaSecondsSlot);
  uint animationFlags = *(uint*)(pawnBytes + 0x3e4);
  if ((animationFlags & 0x08000000) == 0) { // bInitializeAnimation is published before the channel callbacks.
    using PlayChannel = void (__thiscall*)(AR6Pawn*, int, FName, float, float, int, int, int);
    NativeActorControlVtable* firstTable = *reinterpret_cast<NativeActorControlVtable**>(this);
    *(uint*)(pawnBytes + 0x3e4) = animationFlags | 0x08000000;
    FName sequence = *(FName*)(pawnBytes + 0x560);
    reinterpret_cast<PlayChannel&>(firstTable->playAnimAddress)(this, 2, sequence, 1.0f, 0.1f, 1, 0, 0);
    sequence = *(FName*)(pawnBytes + 0x55c);
    this->PlayAnim(3, sequence, 1.0f, 0.1f, 1, 0, 0);
    for (int channel = 4; channel < 8; ++channel) {
      sequence = *(FName*)(pawnBytes + 0x53c + channel * 4);
      this->PlayAnim(channel, sequence, 1.0f, 0.1f, 1, 0, 0);
    }
    using EnableNotify = int (__thiscall*)(USkeletalMeshInstance*, int, int);
    EnableNotify cachedNotify = reinterpret_cast<EnableNotify&>(USkeletalMeshInstanceEnableChannelNotifyImport);
    for (int channel = 2; channel < 12; ++channel) {
      cachedNotify(meshInstance, channel, 1);
      // This import reloads after every notify.
      meshInstance->USkeletalMeshInstance::SetBlendAlpha(channel, 0.0f);
    }
  }
  float10 scaledDeltaST0 = (float10)deltaSecondsSlot / *(float*)(pawnBytes + 0x4a4); // BlendChangeTime.
  byte initialPhysics = pawnBytes[0x2c];
  byte previousPhysics = pawnBytes[0x397];
  uint previousAnimationFlags = *(uint*)(pawnBytes + 0x3e4);
  uint currentPawnFlags = *(uint*)(pawnBytes + 0x3e0);
  scaledDelta = (float)scaledDeltaST0; // The ratio remains extended until after the physics/flag captures.
  using FadeCall = void (__thiscall*)(APawn*, int, int, float);
  // Describe repeated inlined calls; these imports reload on each invocation.
  auto changeAnimation = [&]() { this->APawn::eventChangeAnimation(); };
  auto updateBlend = [&](int channel, float alpha, float rate) {
    meshInstance->USkeletalMeshInstance::UpdateBlendAlpha(channel, alpha, rate);
  };
  auto fadeCurrent = [&](int first, int limit, float rate) {
    this->APawn::ZeroMovementAlpha(first, limit, rate);
  };
  if ((((previousAnimationFlags >> 19) ^ currentPawnFlags) & 0x20) != 0 ||
      (((previousAnimationFlags >> 14) ^ currentPawnFlags) & 0x200) != 0 ||
      (((previousAnimationFlags >> 23) ^ currentPawnFlags) & 4) != 0) {
    changeAnimation();
    currentPawnFlags = *(uint*)(pawnBytes + 0x3e0);
    uint savedFlags = *(uint*)(pawnBytes + 0x3e4);
    uint snapshots = ((currentPawnFlags & 4) << 23) | ((currentPawnFlags & 0x20) << 19) |
        ((currentPawnFlags & 0x200) << 14);
    *(uint*)(pawnBytes + 0x3e4) = (savedFlags & 0xfc7fffff) | snapshots;
    updateBlend(2, 0.0f, 1.0f);
    updateBlend(3, 0.0f, 1.0f);
  }
  const FVector* transitionZero = *(const FVector**)&FVectorFVector0Import;
  if ((initialPhysics == 2) != (previousPhysics == 2)) {
    byte physics = pawnBytes[0x2c]; // The falling decision is old; the selected transition uses current physics.
    if (physics == 1) {
      this->APawn::eventPlayLandingAnimation(*(float*)(pawnBytes + 0x254));
      changeAnimation();
    } else if (physics == 2) {
      if ((*(uint*)(pawnBytes + 0x3e4) & 0x04000000) != 0 && *(float*)(pawnBytes + 0x254) > 0.0f) {
        this->APawn::eventPlayJump();
      } else {
        this->APawn::eventPlayFalling();
      }
    } else {
      changeAnimation();
    }
  } else if (pawnBytes[0x2c] != pawnBytes[0x397]) {
    changeAnimation();
  } else if ((pawnBytes[0x6c4] & 1) != 0) { // m_bIsClimbingStairs.
    FVector* stairVelocity = (FVector*)(pawnBytes + 0x24c);
    if (stairVelocity->X != transitionZero->X || stairVelocity->Y != transitionZero->Y ||
        stairVelocity->Z != transitionZero->Z) {
      scratch60 = *stairVelocity;
      FVector* stairDirection = &(scratch50 = ((FVector*)(pawnBytes + 0x890))->GetNormalized());
      FVector* velocityDirection = &(scratch40 = scratch60.GetNormalized());
      float10 zProduct = (float10)velocityDirection->Z * stairDirection->Z;
      uint stairFlags = *(uint*)(pawnBytes + 0x6c4);
      float10 yProduct = (float10)velocityDirection->Y * stairDirection->Y;
      float10 zy = zProduct + yProduct;
      float10 xProduct = (float10)velocityDirection->X * stairDirection->X;
      float10 stairDot = zy + xProduct; // Both selected result slots remain live across the second normalization.
      bool movingUpStairs = (stairFlags & 2) != 0;
      if ((movingUpStairs && stairDot <= nativeDouble0) ||
          (!movingUpStairs && stairDot > 0.0f)) {
        changeAnimation();
      }
    }
  }
  if ((pawnBytes[0x6c8] & 1) == 0) fadeCurrent(16, 17, scaledDelta); // No pawn-specific animation.
  byte physics = pawnBytes[0x2c];
  uint liveAnimationFlags = *(uint*)(pawnBytes + 0x3e4);
  pawnBytes[0x397] = physics;
  forwardBias = 0.0f;
  sideBias = 0.0f;
  liveAnimationFlags ^= (((uint)(physics == 1) << 26) ^ liveAnimationFlags) & 0x04000000;
  *(uint*)(pawnBytes + 0x3e4) = liveAnimationFlags;
  if (physics == 2 || *(float*)(pawnBytes + 0x4a8) >
      *(float*)(*(byte**)(pawnBytes + 0x144) + 0x45c)) { // MovementBlendStartTime versus level time.
    fadeCurrent(2, 12, scaledDelta);
  } else {
    FVector* acceleration = (FVector*)(pawnBytes + 0x258);
    bool idle = (acceleration->X == 0.0f && acceleration->Y == 0.0f && acceleration->Z == 0.0f) || physics == 12 ||
        ((*(uint*)(pawnBytes + 0x6c4) & 0x40000000) != 0 && (liveAnimationFlags & 0x20000000) == 0);
    using SetRateCall = void (__thiscall*)(USkeletalMeshInstance*, int, float);
    using FloatChannelST0 = float10 (__thiscall*)(USkeletalMeshInstance*, int); // Live native float-return operand.
    float& rateSpill = scratch30.Z; // Native EBP-28 also belongs to the shared vector-result buffer.
    if (idle) {
      FVector* oldAcceleration = (FVector*)(pawnBytes + 0x5d8);
      if (oldAcceleration->X != 0.0f || oldAcceleration->Y != 0.0f || oldAcceleration->Z != 0.0f) {
        changeAnimation();
        if (isLocallyControlled != 0 && (pawnBytes[0x3e8] & 0x10) != 0) {
          AR6EngineWeapon* weapon = this->EngineWeapon;
          if (weapon != nullptr)
              weapon->AR6EngineWeapon::eventPawnStoppedMoving();
        }
      }
      bool postureTransition = (*(uint*)(pawnBytes + 0x6c4) & 0x40000000) != 0;
      bool crouched = !postureTransition && (pawnBytes[0x3e0] & 0x20) != 0;
      FadeCall cachedFade = reinterpret_cast<FadeCall&>(APawnZeroMovementAlphaImport);
      if (!postureTransition && !crouched) cachedFade(this, 1, 2, scaledDelta);
      cachedFade(this, 4, 12, scaledDelta);
      *(ushort*)(pawnBytes + 0x246) = 0; // Clear the upper half of Rotation.Yaw, not Roll.
      float10 yawInteger = (float10)*(int*)(pawnBytes + 0x244);
      float& yawSpill = heightSpill;
      yawSpill = (float)yawInteger;
      float* oldYaw = (float*)(pawnBytes + 0x49c);
      if (yawInteger - *oldYaw > 32768.0f) {
        *oldYaw = (float)((float10)*oldYaw + 65536.0f);
      } else if ((float10)*oldYaw - yawSpill > 32768.0f) {
        *oldYaw = (float)((float10)*oldYaw - 65536.0f);
      }
      if (pawnBytes[0x2c] == 1 && *(float*)(pawnBytes + 0x4b4) == 0.0f) {
        float& turnRate = movementRate;
        turnRate = (float)(((float10)yawSpill - *oldYaw) / deltaSecondsSlot);
        if (isLocallyControlled == 0 && ((pawnBytes[0x3e8] & 0x10) != 0 ||
            (*(byte**)(pawnBytes + 0x144))[0x425] == 3)) {
          turnRate = 16384.0f; // This path retains the prior turn-direction bits.
        } else {
          bool crouchThreshold = (pawnBytes[0x3e0] & 0x20) != 0 && pawnBytes[0x39e] == 1;
          bool rightTurn = turnRate > (crouchThreshold ? 8000.0f : 1000.0f);
          bool leftTurn = turnRate < (crouchThreshold ? -8000.0f : -1000.0f);
          uint flags = *(uint*)(pawnBytes + 0x3e4);
          flags ^= (((uint)rightTurn << 20) ^ flags) & 0x00100000;
          *(uint*)(pawnBytes + 0x3e4) = flags;
          *(uint*)(pawnBytes + 0x3e4) = flags ^ ((((uint)leftTurn << 21) ^ flags) & 0x00200000);
        }
        if ((*(uint*)(pawnBytes + 0x3e4) & 0x00100000) != 0) {
          meshInstance->USkeletalMeshInstance::SetAnimSequence(2, *(FName*)(pawnBytes + 0x560));
          updateBlend(2, 1.0f, scaledDelta);
          float10 magnitude = turnRate >= 0.0f ? (float10)turnRate : -(float10)turnRate;
          meshInstance->USkeletalMeshInstance::SetAnimRate(2, (float)(magnitude * nativeFloat6Point1035156EMinus05));
        } else {
          cachedFade(this, 2, 3, scaledDelta);
        }
        if ((*(uint*)(pawnBytes + 0x3e4) & 0x00200000) != 0) {
          meshInstance->USkeletalMeshInstance::SetAnimSequence(3, *(FName*)(pawnBytes + 0x55c));
          updateBlend(3, 1.0f, scaledDelta);
          float10 magnitude = turnRate >= 0.0f ? (float10)turnRate : -(float10)turnRate;
          meshInstance->USkeletalMeshInstance::SetAnimRate(3, (float)(magnitude * nativeFloat6Point1035156EMinus05));
        } else {
          fadeCurrent(3, 4, scaledDelta);
        }
      } else {
        cachedFade(this, 2, 3, scaledDelta);
        cachedFade(this, 3, 4, scaledDelta);
      }
      // Keep the integer unspilled for the post-callback comparison.
      float10 currentYaw = (float10)*(int*)(pawnBytes + 0x244);
      if ((float10)*oldYaw != currentYaw) *oldYaw = (float)currentYaw;
      if ((*(uint*)(pawnBytes + 0x3e0) & 0x200) != 0 && pawnBytes[0x66c] != 0 && pawnBytes[0x3a0] == 0 &&
          (*(uint*)(pawnBytes + 0x6c4) & 0x1000) == 0 && (pawnBytes[0x6c8] & 4) == 0) {
        pawnBytes[0x66c] = 0;
        changeAnimation();
      }
    } else {
      FVector* oldAcceleration = (FVector*)(pawnBytes + 0x5d8);
      if (oldAcceleration->X == 0.0f && oldAcceleration->Y == 0.0f && oldAcceleration->Z == 0.0f &&
          isLocallyControlled != 0 && (pawnBytes[0x3e8] & 0x10) != 0) {
        AR6EngineWeapon* weapon = this->EngineWeapon;
        if (weapon != nullptr) weapon->AR6EngineWeapon::eventPawnIsMoving();
      }
      if ((*(uint*)(pawnBytes + 0x3e0) & 0x200) != 0) {
        if (pawnBytes[0x66c] == 0 && pawnBytes[0x39d] == 0) {
          pawnBytes[0x66c] = 3;
          changeAnimation();
        }
        if (pawnBytes[0x66c] == 3 && pawnBytes[0x39d] != 0) {
          pawnBytes[0x66c] = 0;
          changeAnimation();
        }
      }
      if ((*(uint*)(pawnBytes + 0x6c4) & 0x40000000) == 0) fadeCurrent(1, 2, scaledDelta);
      fadeCurrent(2, 4, scaledDelta);
      // Native ignores this returned pointer.
      scratch40 = ((FRotator*)(pawnBytes + 0x240))->Vector();
      byte movingPhysics = pawnBytes[0x2c];
      if (movingPhysics == 1) {
        scratch40.Z = 0.0f;
      } else if (movingPhysics == 11) {
        byte* onLadder = *(byte**)(pawnBytes + 0x51c);
        if (onLadder != nullptr) {
          scratch40 = *(FVector*)(onLadder + 0x4a4);
        } else {
          byte* ladder = *(byte**)(pawnBytes + 0x784);
          if (ladder != nullptr) scratch40 = *(FVector*)(*(byte**)(ladder + 0x3e8) + 0x4a4);
        }
      }
      using SafeNormalCall = FVector* (__thiscall*)(const FVector*, FVector*);
      SafeNormalCall cachedSafeNormal = reinterpret_cast<SafeNormalCall&>(FVectorSafeNormalImport);
      FVector* normalized = cachedSafeNormal(&scratch40, &scratch30);
      scratch40 = *normalized; // Copy the actual return before reusing the shared output.
      cachedSafeNormal(acceleration, &scratch60); // This return is ignored; its hidden output supplies velocity.
      scratch30 = FVector{0.0f, 0.0f, 1.0f};
      // Its returned pointer is ignored.
      scratch50 = scratch40 ^ scratch30;
      FVector* right = cachedSafeNormal(&scratch50, &scratch30);
      float10 forwardZ = (float10)scratch60.Z * scratch40.Z;
      uint rightX = reinterpret_cast<uint&>(right->X);
      float10 forwardY = scratch60.Y;
      reinterpret_cast<uint&>(scratch50.X) = rightX;
      forwardY *= scratch40.Y;
      reinterpret_cast<uint&>(scratch50.Y) = reinterpret_cast<uint&>(right->Y);
      uint rightZ = reinterpret_cast<uint&>(right->Z);
      float10 zy = forwardZ + forwardY;
      reinterpret_cast<uint&>(scratch50.Z) = rightZ;
      float10 forwardX = scratch60.X;
      movingPhysics = pawnBytes[0x2c];
      forwardX *= scratch40.X;
      movementRate = 1.0f;
      forwardBias = (float)(zy + forwardX);
      float10 sideZY = (float10)scratch50.Z * scratch60.Z + (float10)scratch50.Y * scratch60.Y;
      sideBias = (float)(sideZY + (float10)scratch50.X * scratch60.X);
      float& forwardWeight = heightSpill;
      float& sideWeight = *(float*)(frameTop - 0x24);
      forwardWeight = (float)((float10)forwardBias * forwardBias);
      sideWeight = (float)((float10)sideBias * sideBias);
      float& speedScale = movementRate;
      if (movingPhysics == 11 && (pawnBytes[0x3e0] & 4) == 0) speedScale = 2.0f;
      int axes = 0;
      float& forwardRate = *(float*)(frameTop - 0x64);
      float& sideRate = scalar34;
      forwardRate = 0.0f;
      sideRate = 0.0f;
      if (forwardBias != 0.0f) {
        ++axes;
        rateSpill =
            (float)reinterpret_cast<FloatChannelST0&>(USkeletalMeshInstanceGetAnimRateOnChannelImport)(meshInstance,
            forwardBias > 0.0f ? 4 : 6);
        forwardRate = rateSpill;
      }
      if (sideBias != 0.0f) {
        ++axes;
        rateSpill =
            (float)reinterpret_cast<FloatChannelST0&>(USkeletalMeshInstanceGetAnimRateOnChannelImport)(meshInstance,
            sideBias > 0.0f ? 5 : 7);
        sideRate = rateSpill;
      }
      float10 selectedRate;
      if (axes == 2 && (*(uint*)(pawnBytes + 0x6c8) & 0x20000) == 0) {
        float10 numerator = (float10)sideRate * sideWeight + (float10)forwardRate * forwardWeight;
        float10 denominator = (float10)sideWeight + forwardWeight;
        selectedRate = numerator / denominator;
      } else {
        selectedRate = forwardBias == 0.0f ? (float10)sideRate : (float10)forwardRate;
      }
      movementRate = (float)(selectedRate * speedScale);
      using GetSequenceCall = FName* (__thiscall*)(USkeletalMeshInstance*, FName*, int);
      uint& sequenceWord = *(uint*)(frameTop - 0x64);
      for (int channel = 4; channel < 8; ++channel) {
        FName* sequence = reinterpret_cast<GetSequenceCall&>(USkeletalMeshInstanceGetAnimSequenceImport)(meshInstance,
            (FName*)&sequenceWord, channel);
        uint desiredName = *(uint*)(pawnBytes + 0x53c + channel * 4);
        if (desiredName != *(uint*)sequence) {
          rateSpill = (float)reinterpret_cast<FloatChannelST0&>(USkeletalMeshInstanceGetBlendAlphaImport)(meshInstance,
              channel + 4);
          float pairAlpha = rateSpill;
          float& currentAlpha = scalar34;
          currentAlpha =
              (float)reinterpret_cast<FloatChannelST0&>(USkeletalMeshInstanceGetBlendAlphaImport)(meshInstance,
              channel);
          if (pairAlpha < currentAlpha)
              meshInstance->USkeletalMeshInstance::CopyAnimation(channel, channel + 4);
          meshInstance->USkeletalMeshInstance::SetAnimSequence(
              channel, *(FName*)(pawnBytes + 0x53c + channel * 4)); // Reload after the copy callback.
        }
      }
      if (forwardBias >= 0.0f) {
        updateBlend(4, (*(uint*)(pawnBytes + 0x6c8) & 0x20000) != 0 ? 1.0f : forwardWeight, scaledDelta);
        updateBlend(6, 0.0f, scaledDelta);
      } else { // Native C0 routes unordered forward/side comparisons with the negative direction.
        updateBlend(4, 0.0f, scaledDelta);
        updateBlend(6, (*(uint*)(pawnBytes + 0x6c8) & 0x20000) != 0 ? 1.0f : forwardWeight, scaledDelta);
      }
      if ((*(uint*)(pawnBytes + 0x6c8) & 0x20000) != 0) {
        updateBlend(5, 0.0f, scaledDelta);
        updateBlend(7, 0.0f, scaledDelta);
      } else if (sideBias >= 0.0f) {
        updateBlend(5, sideWeight, scaledDelta);
        updateBlend(7, 0.0f, scaledDelta);
      } else {
        updateBlend(5, 0.0f, scaledDelta);
        updateBlend(7, sideWeight, scaledDelta);
      }
      for (int channel = 8; channel < 12; ++channel) updateBlend(channel, 0.0f, scaledDelta);
      SetRateCall cachedSetRate = reinterpret_cast<SetRateCall&>(USkeletalMeshInstanceSetAnimRateImport);
      for (int channel = 4; channel < 12; ++channel) {
        bool reverse = channel < 8 && pawnBytes[0x394 + channel] == 1; // AnimPlayBackward is tested before GetAnimRate.
        rateSpill =
            (float)reinterpret_cast<FloatChannelST0&>(USkeletalMeshInstanceGetAnimRateOnChannelImport)(meshInstance,
            channel);
        float10 rate = (float10)movementRate / rateSpill;
        if (reverse) rate = -rate;
        cachedSetRate(meshInstance, channel, (float)rate);
      }
    }
  }
  // Update peeking, retaining the original delta while its incoming slot becomes script-parameter storage.
  reinterpret_cast<uint&>(savedOffset734) = *(uint*)(pawnBytes + 0x734);
  uint originalDeltaWord = reinterpret_cast<uint&>(deltaSecondsSlot);
  float originalDelta = reinterpret_cast<float&>(originalDeltaWord);
  this->AR6Pawn::UpdatePeeking(originalDelta);
  auto dispatchPeeking = [&](FindChecked lookup, FName name, void* parameters) {
    UFunction* function = lookup(this, name, 0);
    ProcessEvent process = *(ProcessEvent*)(*(byte**)this + 0x10);
    process(this, function, parameters, nullptr);
  };
  auto adjustPeekingCylinder = [&](float10 blendRate) {
    byte netMode = (*(byte**)(pawnBytes + 0x144))[0x425];
    if (netMode == 1 || (netMode == 2 && (pawnBytes[0xac] & 0x40) == 0) ||
        blendRate < nativeFloatHalf) this->AR6Pawn::AdjustFluidCollisionCylinder(0.0f, 0);
  };
  byte peekingMode = pawnBytes[0x39c];
  if (peekingMode == 0) {
    if (pawnBytes[0x671] != 0) {
      // EndPeekingMode uses only the high byte of the incoming float slot.
      ((byte*)&deltaSecondsSlot)[3] = pawnBytes[0x671];
      dispatchPeeking(reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport), R6ENGINE_EndPeekingMode,
          (byte*)&deltaSecondsSlot + 3);
      if (pawnBytes[0x671] == 2 && (*(uint*)(pawnBytes + 0x3e0) & 0x120) == 0) {
        APawn* defaults = static_cast<APawn*>(this->Class->GetDefaultObject());
        uint defaultHeight = reinterpret_cast<const uint&>(defaults->CollisionHeight);
        uint defaultCrouchHeight = reinterpret_cast<const uint&>(defaults->CrouchHeight);
        reinterpret_cast<uint&>(scratch30.Z) = defaultHeight; // Native EBP-28 shares the earlier vector-result storage.
        reinterpret_cast<uint&>(deltaSecondsSlot) = defaultCrouchHeight;
        float10 blendRate = this->AR6Pawn::ComputeCrouchBlendRate(reinterpret_cast<float&>(defaultHeight),
            deltaSecondsSlot);
        adjustPeekingCylinder(blendRate); // Keep ST0 extended through the network/rate decision.
      }
    }
    if (*(float*)(pawnBytes + 0x730) == *(float*)(pawnBytes + 0x734)) {
      uint flags = *(uint*)(pawnBytes + 0x6c4) & ~0x2000000u;
      *(uint*)(pawnBytes + 0x720) = 0x447a0000; // m_fLastValidPeeking = 1000.
      *(uint*)(pawnBytes + 0x6c4) = flags;
      fadeCurrent(13, 14, scaledDelta);
    } else {
      this->AR6Pawn::UpdateFullPeekingMode(originalDelta);
      reinterpret_cast<uint&>(deltaSecondsSlot) = 0;
      dispatchPeeking(reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport), R6ENGINE_PlayPeekingAnim,
          &deltaSecondsSlot);
      if (*(float*)(pawnBytes + 0x730) == *(float*)(pawnBytes + 0x734) &&
          (*(uint*)(pawnBytes + 0x6c4) & 0x2000000) != 0)
        *(uint*)(pawnBytes + 0x6c4) &= ~0x2000000u;
    }
  } else {
    FindChecked peekingFind;
    if (peekingMode != pawnBytes[0x671]) {
      if (peekingMode == 2) {
        peekingFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
        dispatchPeeking(peekingFind, R6ENGINE_StartFluidPeeking, nullptr);
        this->AR6Pawn::UpdatePeeking(originalDelta);
      } else if (peekingMode == 1) {
        if (pawnBytes[0x671] == 2 && (*(uint*)(pawnBytes + 0x3e0) & 0x120) == 0) {
          this->AR6Pawn::GetDefaultHeightAndRadius(heightSpill, scratch30.Z, scalar34);
          float10 blendRate = this->AR6Pawn::ComputeCrouchBlendRate(heightSpill, scratch30.Z);
          adjustPeekingCylinder(blendRate);
        }
        peekingFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
        dispatchPeeking(peekingFind, R6ENGINE_StartFullPeeking, nullptr);
        uint flags = *(uint*)(pawnBytes + 0x6c4);
        *(uint*)(pawnBytes + 0x6c4) = flags ^ (((*(uint*)(pawnBytes + 0x3e4) >> 4) ^ flags) & 0x8000000);
        this->AR6Pawn::UpdatePeeking(originalDelta);
      } else {
        // Capture precedes the second UpdatePeeking even for other mode values.
        peekingFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
        this->AR6Pawn::UpdatePeeking(originalDelta);
      }
    } else {
      peekingFind = reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport);
    }
    peekingMode = pawnBytes[0x39c];
    if (peekingMode == 1) {
      if (((*(uint*)(pawnBytes + 0x3e4) >> 4) & 0x8000000) != (*(uint*)(pawnBytes + 0x6c4) & 0x8000000))
        dispatchPeeking(peekingFind, R6ENGINE_StartFullPeeking, nullptr);
    } else if (peekingMode == 2) {
      aimVectorWords[0] = reinterpret_cast<uint&>(forwardBias);
      // Current incoming-slot contents, which callbacks may already have overwritten.
      aimVectorWords[2] = reinterpret_cast<uint&>(deltaSecondsSlot);
      aimVectorWords[1] = reinterpret_cast<uint&>(sideBias);
      dispatchPeeking(peekingFind, R6ENGINE_PlayFluidPeekingAnim, aimVectorWords);
      *(uint*)(pawnBytes + 0x724) = *(uint*)(pawnBytes + 0x4b4); // Current m_fCrouchBlendRate after the event.
    }
    if ((peekingMode == 1 || peekingMode == 2) && savedOffset734 != *(float*)(pawnBytes + 0x734)) {
      reinterpret_cast<uint&>(deltaSecondsSlot) = 0;
      dispatchPeeking(peekingFind, R6ENGINE_PlayPeekingAnim, &deltaSecondsSlot);
    }
  }
  uint peekingFlags = *(uint*)(pawnBytes + 0x6c4);
  uint peekingEngineFlags = *(uint*)(pawnBytes + 0x3e4);
  uint peekingFlags2 = *(uint*)(pawnBytes + 0x6c8);
  peekingMode = pawnBytes[0x39c];
  *(uint*)(pawnBytes + 0x6c4) = peekingFlags ^ (((peekingEngineFlags >> 4) ^ peekingFlags) & 0x8000000);
  pawnBytes[0x671] = peekingMode;
  if ((peekingFlags2 & 0x2000) == 0 && peekingMode != 2) fadeCurrent(12, 13, scaledDelta);
  // Refresh weapon animation, high stance, bipod posture, and the acceleration history.
  if (pawnBytes[0x39e] == 1 || pawnBytes[0x39e] == 2) {
    uint flags = *(uint*)(pawnBytes + 0x6c4);
    uint oldHighStance = (*(uint*)(pawnBytes + 0x3e4) >> 18) & 1;
    uint* hitWords = (uint*)(frameTop - 0x98);
    for (int word = 0; word < 9; ++word) hitWords[word] = 0;
    hitWords[9] = 0x3f800000;
    hitWords[10] = 0xffffffff;
    hitWords[11] = 0;
    uint oldReloading = (flags >> 22) & 1;
    uint reloading = (flags >> 18) & 1;
    uint reloadLoopChange = ((flags >> 5) ^ flags) & 0x80000;
    uint weaponChange = ((flags >> 3) ^ flags) & 0x100000;
    if (oldReloading != reloading || reloadLoopChange != 0 || weaponChange != 0 ||
        pawnBytes[0x66f] != pawnBytes[0x66c]) {
      if ((oldReloading != reloading && reloading == 0) || reloadLoopChange != 0)
        *(uint*)(pawnBytes + 0x7dc) = 0; // m_WeaponAnimPlaying = NAME_None.
      flags ^= ((flags << 4) ^ flags) & 0x400000;
      flags ^= ((flags << 5) ^ flags) & 0x1000000;
      flags ^= ((flags << 3) ^ flags) & 0x800000;
      byte currentHands = pawnBytes[0x66c];
      *(uint*)(pawnBytes + 0x6c4) = flags;
      pawnBytes[0x66f] = currentHands;
      this->APawn::eventPlayWeaponAnimation();
    }
    byte currentPawnType = pawnBytes[0x39e]; // PlayWeaponAnimation may have changed the pawn state.
    if (currentPawnType == 1 && (*(uint*)(pawnBytes + 0xa50) & 0x200) != 0) { // Rainbow m_bReloadToFullAmmo.
      *(uint*)(pawnBytes + 0x3e4) &= ~0x40000u;
    } else if (currentPawnType == 2 && (*(uint*)(pawnBytes + 0x6c8) & 0x40000) != 0) {
      *(uint*)(pawnBytes + 0x3e4) |= 0x40000; // Engaged terrorist uses high stance.
    } else if (pawnBytes[0x39d] != 0) {
      uint engineFlags = *(uint*)(pawnBytes + 0x3e4);
      bool isPlayer = (pawnBytes[0x3e8] & 0x10) != 0;
      *(uint*)(pawnBytes + 0x3e4) = engineFlags | 0x40000;
      *(uint*)(pawnBytes + 0x75c) = isPlayer ? 0x40400000 : 0x3fc00000; // Firing timer: 3 or 1.5 seconds.
    } else if ((*(uint*)(pawnBytes + 0x3e4) & 0x80000) == 0) {
      *(uint*)(pawnBytes + 0x3e4) &= ~0x40000u;
    } else {
      scratch40 = FVector{0.0f, 0.0f, 0.0f}; // Shared storage is a raw FRotator for this query.
      if ((pawnBytes[0x3e8] & 0x10) != 0) {
        uint pitch = *(uint*)(pawnBytes + 0x240);
        uint yaw = *(uint*)(pawnBytes + 0x244);
        uint roll = *(uint*)(pawnBytes + 0x248);
        reinterpret_cast<uint&>(scratch40.X) = pitch;
        reinterpret_cast<uint&>(scratch40.Y) = yaw;
        reinterpret_cast<uint&>(scratch40.Z) = roll;
      } else {
        using RotationOutput = FRotator* (__thiscall*)(AR6Pawn*, void*); // Slot d4; original method name unresolved.
        FRotator* rotation = (*(RotationOutput*)(*(byte**)this + 0xd4))(this, &scratch50);
        reinterpret_cast<uint&>(scratch40.X) = ((uint*)rotation)[0];
        reinterpret_cast<uint&>(scratch40.Y) = ((uint*)rotation)[1];
        reinterpret_cast<uint&>(scratch40.Z) = ((uint*)rotation)[2];
      }
      *(uint*)(pawnBytes + 0x3e4) |= 0x40000;
      reinterpret_cast<uint&>(scratch40.X) = 0; // Flatten the pitch before obtaining the facing vector.
      using EyeOutput = FVector* (__thiscall*)(APawn*, FVector*);
      FVector* eye = reinterpret_cast<EyeOutput&>(APawnEventEyePositionImport)(this, &scratch50);
      float10 startZ = (float10)eye->Z + *(float*)(pawnBytes + 0x23c);
      float10 startY = (float10)eye->Y + *(float*)(pawnBytes + 0x238);
      float10 startX = (float10)eye->X + *(float*)(pawnBytes + 0x234);
      scratch60.X = (float)startX;
      scratch60.Y = (float)startY;
      scratch60.Z = (float)startZ;
      FVector* facing = &(scratch50 = ((FRotator*)&scratch40)->Vector());
      float10 reachZ = facing->Z;
      byte* traceLevel = *(byte**)(pawnBytes + 0x328);
      reachZ *= nativeFloat8EPlus01; // 80 units, with the Z product retained extended.
      deltaSecondsSlot = (float)((float10)facing->Y * nativeFloat8EPlus01);
      float10 reachX = facing->X;
      scratch50.Y = 15.0f;
      reachX *= nativeFloat8EPlus01;
      scratch50.Z = 15.0f;
      scratch50.X = (float)reachX;
      float10 endZ = reachZ + scratch60.Z;
      float10 endY = (float10)scratch60.Y + deltaSecondsSlot;
      float10 endX = scratch50.X;
      scratch50.X = 15.0f;
      endX += scratch60.X;
      scratch30.X = (float)endX;
      scratch30.Y = (float)endY;
      scratch30.Z = (float)endZ;
      using TraceCall = int (__thiscall*)(void*, void*, AR6Pawn*, FVector*, FVector*, uint, FVector);
      TraceCall trace = *(TraceCall*)(*(byte**)traceLevel + 0xcc);
      if (trace(traceLevel, hitWords, this, &scratch30, &scratch60, 0xdf, scratch50) == 0) {
        uint* hit = hitWords;
        while (hit != nullptr) {
          AActor* actor = reinterpret_cast<AActor*>(hit[1]);
          AActor* owner = actor->Owner; // Native reads Owner before testing actor for null.
          if (owner != this && actor != nullptr) {
            // Preserve the full-width native Boolean test.
            if (this->IsBlockedBy(actor) != 0) {
              *(uint*)(pawnBytes + 0x3e4) &= ~0x40000u;
              break;
            }
          }
          hit = (uint*)hit[0]; // The test provider may change the next link.
        }
      }
    }
    if (oldHighStance != ((*(uint*)(pawnBytes + 0x3e4) >> 18) & 1))
      this->APawn::eventPlayWeaponAnimation();
  }
  if ((*(uint*)(pawnBytes + 0x3e0) & 0x200) != 0) {
    AR6EngineWeapon* weapon = this->EngineWeapon;
    bool supportsBipod = weapon != nullptr && (reinterpret_cast<const byte*>(weapon)[0x3a0] & 2) != 0;
    bool usingBipod = (*(uint*)(pawnBytes + 0x6c8) & 0x2000) != 0;
    if (usingBipod != supportsBipod) {
      reinterpret_cast<uint&>(deltaSecondsSlot) = supportsBipod ? 1 : 0;
      dispatchPeeking(reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport), R6ENGINE_InitBiPodPosture,
          &deltaSecondsSlot);
    }
    if ((*(uint*)(pawnBytes + 0x6c8) & 0x2000) != 0)
      dispatchPeeking(reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport), R6ENGINE_UpdateBipodPosture,
          nullptr);
  } else if ((*(uint*)(pawnBytes + 0x6c8) & 0x2000) != 0) {
    reinterpret_cast<uint&>(deltaSecondsSlot) = 0;
    dispatchPeeking(reinterpret_cast<FindChecked&>(UObjectFindFunctionCheckedImport), R6ENGINE_InitBiPodPosture,
        &deltaSecondsSlot);
  }
  uint accelerationX = *(uint*)(pawnBytes + 0x258);
  uint accelerationY = *(uint*)(pawnBytes + 0x25c);
  uint accelerationZ = *(uint*)(pawnBytes + 0x260);
  *(uint*)(pawnBytes + 0x5d8) = accelerationX;
  *(uint*)(pawnBytes + 0x5dc) = accelerationY;
  *(uint*)(pawnBytes + 0x5e0) = accelerationZ;
  ExceptionList = frame.previousExceptionList;
  return;
}

// R6Engine.dll @ 1002fbc5 : PawnMovementCatchPointer
// Rethrows the caught text pointer through inherited parent EBP-68 storage.
__declspec(naked) __declspec(noreturn) void __cdecl PawnMovementCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x9c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x68]
        push ecx
        mov dword ptr [ebp-0x68],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002fbdc : PawnMovementCatchContext
// Reports UpdateMovementAnimation context and rethrows the active inherited-frame exception.
__declspec(naked) __declspec(noreturn) void __cdecl PawnMovementCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnUpdateMovementAnimation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447e0 : UpdateMovementAnimationExceptionHandler
// Supplies the exact movement-animation FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl UpdateMovementAnimationExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnMovementInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1002fc00 : AR6Pawn::execPawnTrackActor
// Evaluates tracking operands and updates immediately, leaving terminator and DebugInfo bytes unconsumed.
// Native ABI view retains the incoming frame word for the aim operand.
void __thiscall AR6Pawn::execPawnTrackActor(FFrame* stack, void* unusedResult)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative storage; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x28/-0x24/-0x20.
        uint caught, rethrow, operandWord; // EBP-0x1c/-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&execPawnTrackActorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    FFrame* expressionStack = stack;
    using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
    byte* code = expressionStack->Code;
    frame.operandWord = 0; // Default is written before reading the opcode, while state is still -1.
    byte opcode = *code;
    expressionStack->Code = code + 1;
    frame.savedEsp = &frame.savedEdi;
    ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
    AR6Pawn* capturedPawn = this;
    UObject* receiver = expressionStack->Object;
    frame.state = 0;
    natives[opcode](receiver, expressionStack, &frame.operandWord);
    code = expressionStack->Code;
    receiver = expressionStack->Object;
    // Incoming EBP+8 Frame argument becomes the second evaluator's output.
    uint& aimWord = reinterpret_cast<uint&>(stack);
    aimWord = 0;
    opcode = *code;
    expressionStack->Code = code + 1;
    natives = *(ScriptNative**)&CoreGNativesImport;
    natives[opcode](receiver, expressionStack, &aimWord);
    uint currentAim = aimWord; // Read before the pawn flags; ESI retained the original expression Frame.
    uint* trackingFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(capturedPawn) + 0x6c4);
    uint currentFlags = *trackingFlagWord;
    uint replacement = ((currentAim << 29) ^ currentFlags) & 0x20000000U;
    *trackingFlagWord = currentFlags ^ replacement;
    uint actorWord = frame.operandWord; // Read after the flag write; native inlines this setter sequence.
    capturedPawn->m_TrackActor = reinterpret_cast<AActor*>(actorWord);
    capturedPawn->AR6Pawn::UpdatePawnTrackActor(1);
    ExceptionList = frame.previousExceptionList; // Void RET8; no terminator/DebugInfo or script-result access.
}

// R6Engine.dll @ 1002fca8 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void ExecPawnTrackActorCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1002fcbc : report script bridge context and rethrow without adding a funclet frame
__declspec(naked) void ExecPawnTrackActorCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecPawnTrackActor // L"AR6Pawn::execPawnTrackActor".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100447f0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void execPawnTrackActorExceptionHandler(void)
{
    __asm {
        mov eax,offset execPawnTrackActorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003fd90 : AR6Pawn::execToggleHeatProperties
// Toggles heat-vision textures and viewport render mode, then increments the material revision byte.
// Native ABI view retains the incoming frame word for the mask-texture pointer.
void __thiscall AR6Pawn::execToggleHeatProperties(FFrame* stack, void* unusedResult)
{
  // Descriptive 32-bit native frame view; the incoming stack slot is reused for the mask output.
  struct VisionFrame {
    uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, word18, word14;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &ToggleHeatPropertiesExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& bTurnItOn = reinterpret_cast<int&>(nativeFrame.word14);
  UTexture*& pAddTexture = reinterpret_cast<UTexture*&>(nativeFrame.word18);
  UTexture*& pMaskTexture = reinterpret_cast<UTexture*&>(stack);
  bTurnItOn = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0; // The first opcode/cursor/table-base/receiver reads precede this guard.
  firstTable[token](firstReceiver, scriptFrame, &bTurnItOn);
  code = *codeCursor;
  UObject* maskReceiver = scriptFrame->Object;
  pMaskTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* maskTable = *(ScriptNative**)&CoreGNativesImport;
  maskTable[token](maskReceiver, scriptFrame, &pMaskTexture);
  code = *codeCursor;
  UObject* addReceiver = scriptFrame->Object;
  pAddTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* addTable = *(ScriptNative**)&CoreGNativesImport;
  addTable[token](addReceiver, scriptFrame, &pAddTexture);
  code = *codeCursor + 1; // Consume the native parameter terminator before looking for DebugInfo.
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  if (bTurnItOn != 0 && pMaskTexture != nullptr) {
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) |= 0x02000000;
    level = this->Level;
    UTexture* currentMask = pMaskTexture;
    level->m_pScopeMaskTexture = currentMask;
    UTexture* currentAdd = pAddTexture;
    level = this->Level;
    level->m_pScopeAddTexture = currentAdd;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport); // Current g_pEngine through its import.
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        client = engine->Client; // Native reloads this chain after the first Actor-null test.
        viewportHeader =
          reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30);
        viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
        controller = viewport->Actor;
        heatRestoreRenderMap = reinterpret_cast<const uint&>(controller->RendMap);
        controller->RendMap = 6;
      }
    }
  } else {
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) &= 0xfdffffff;
    level = this->Level;
    level->m_pScopeAddTexture = nullptr;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        reinterpret_cast<uint&>(controller->RendMap) = heatRestoreRenderMap;
      }
    }
  }
  byte* materialsRevision = *(byte**)&CoreGCompileMaterialsRevisionImport;
  byte revision = *materialsRevision;
  *materialsRevision = (byte)(revision + 1u);
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1003ff13 : ToggleHeatPropertiesCatchPointer
// Throws the caught unsigned-short pointer by value through the inherited heat-toggle frame.
__declspec(naked) __declspec(noreturn) void __cdecl ToggleHeatPropertiesCatchPointer(void)
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

// R6Engine.dll @ 1003ff50 : AR6Pawn::execToggleNightProperties
// Toggles night-vision textures and viewport render mode, then increments the material revision byte.
// Native ABI view retains the incoming frame word for the mask-texture pointer.
void __thiscall AR6Pawn::execToggleNightProperties(FFrame* stack, void* unusedResult)
{
  // Descriptive 32-bit native frame view; the incoming stack slot is reused for the mask output.
  struct VisionFrame {
    uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, word18, word14;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &NightVisionExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& bTurnItOn = reinterpret_cast<int&>(nativeFrame.word14);
  UTexture*& pAddTexture = reinterpret_cast<UTexture*&>(nativeFrame.word18);
  UTexture*& pMaskTexture = reinterpret_cast<UTexture*&>(stack);
  bTurnItOn = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0; // The first opcode/cursor/table-base/receiver reads precede this guard.
  firstTable[token](firstReceiver, scriptFrame, &bTurnItOn);
  code = *codeCursor;
  UObject* maskReceiver = scriptFrame->Object;
  pMaskTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* maskTable = *(ScriptNative**)&CoreGNativesImport;
  maskTable[token](maskReceiver, scriptFrame, &pMaskTexture);
  code = *codeCursor;
  UObject* addReceiver = scriptFrame->Object;
  pAddTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* addTable = *(ScriptNative**)&CoreGNativesImport;
  addTable[token](addReceiver, scriptFrame, &pAddTexture);
  code = *codeCursor + 1; // Consume the native parameter terminator before looking for DebugInfo.
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  if (bTurnItOn != 0 && pMaskTexture != nullptr) {
    **(int**)&CoreGNightVisionActiveImport = 1; // GNightVisionActive.
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) |= 0x01000000;
    level = this->Level;
    UTexture* currentMask = pMaskTexture;
    level->m_pScopeMaskTexture = currentMask;
    level = this->Level;
    UTexture* currentAdd = pAddTexture;
    level->m_pScopeAddTexture = currentAdd;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport); // Current g_pEngine through its import.
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        client = engine->Client; // Native reloads this chain after the first Actor-null test.
        viewportHeader =
          reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30);
        viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
        controller = viewport->Actor;
        nightRestoreRenderMap = reinterpret_cast<const uint&>(controller->RendMap);
        controller->RendMap = 5;
      }
    }
  } else {
    **(int**)&CoreGNightVisionActiveImport = 0;
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) &= 0xfeffffff;
    level = this->Level;
    level->m_pScopeAddTexture = nullptr;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        reinterpret_cast<uint&>(controller->RendMap) = nightRestoreRenderMap;
      }
    }
  }
  byte* materialsRevision = *(byte**)&CoreGCompileMaterialsRevisionImport;
  byte revision = *materialsRevision;
  *materialsRevision = (byte)(revision + 1u);
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 100400ef : PawnNightCatchPointer
// Rethrows the caught text pointer through the inherited parent EBP-1c word.
__declspec(naked) __declspec(noreturn) void __cdecl PawnNightCatchPointer(void)
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

// R6Engine.dll @ 10040103 : PawnNightCatchContext
// Reports the vision-toggle context and rethrows through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PawnNightCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecToggleNightProperties
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045410 : NightVisionExceptionHandler
// Supplies the exact vision-toggle FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl NightVisionExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnNightInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10040120 : AR6Pawn::execToggleScopeProperties
// Toggles scope-vision textures and viewport render mode, then increments the material revision byte.
// Native ABI view retains the incoming frame word for the mask-texture pointer.
void __thiscall AR6Pawn::execToggleScopeProperties(FFrame* stack, void* unusedResult)
{
  // Descriptive 32-bit native frame view; the incoming stack slot is reused for the mask output.
  struct VisionFrame {
    uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, word18, word14;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &ScopeVisionExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& bTurnItOn = reinterpret_cast<int&>(nativeFrame.word18);
  UTexture*& pAddTexture = reinterpret_cast<UTexture*&>(nativeFrame.word14);
  UTexture*& pMaskTexture = reinterpret_cast<UTexture*&>(stack);
  bTurnItOn = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0; // The first opcode/cursor/table-base/receiver reads precede this guard.
  firstTable[token](firstReceiver, scriptFrame, &bTurnItOn);
  code = *codeCursor;
  UObject* maskReceiver = scriptFrame->Object;
  pMaskTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* maskTable = *(ScriptNative**)&CoreGNativesImport;
  maskTable[token](maskReceiver, scriptFrame, &pMaskTexture);
  code = *codeCursor;
  UObject* addReceiver = scriptFrame->Object;
  pAddTexture = nullptr;
  token = *code++;
  *codeCursor = code;
  ScriptNative* addTable = *(ScriptNative**)&CoreGNativesImport;
  addTable[token](addReceiver, scriptFrame, &pAddTexture);
  code = *codeCursor + 1; // Consume the native parameter terminator before looking for DebugInfo.
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  if (bTurnItOn != 0 && pMaskTexture != nullptr && pAddTexture != nullptr) {
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) |= 0x04000000;
    level = this->Level;
    UTexture* currentMask = pMaskTexture;
    level->m_pScopeMaskTexture = currentMask;
    level = this->Level;
    UTexture* currentAdd = pAddTexture;
    level->m_pScopeAddTexture = currentAdd;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport); // Current g_pEngine through its import.
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        controller->RendMap = 5;
      }
    }
  } else {
    ALevelInfo* level = this->Level;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(level) + 0x450) &= 0xfbffffff;
    level = this->Level;
    level->m_pScopeMaskTexture = nullptr;
    level = this->Level;
    level->m_pScopeAddTexture = nullptr;
    UEngine* engine = *reinterpret_cast<UEngine**&>(EngineGPEngineImport);
    UClient* client = engine->Client;
    const NativeArrayHeader32* viewportHeader = client != nullptr ?
      reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(client) + 0x30) : nullptr;
    if (client != nullptr && viewportHeader->count != 0) {
      UViewport* viewport = *reinterpret_cast<UViewport**>(viewportHeader->dataAddress);
      APlayerController* controller = viewport->Actor;
      if (controller != nullptr) {
        reinterpret_cast<uint&>(controller->RendMap) = scopeRestoreRenderMap;
      }
    }
  }
  byte* materialsRevision = *(byte**)&CoreGCompileMaterialsRevisionImport;
  byte revision = *materialsRevision;
  *materialsRevision = (byte)(revision + 1u);
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 100402a0 : PawnScopeCatchPointer
// Rethrows the caught text pointer through the inherited parent EBP-1c word.
__declspec(naked) __declspec(noreturn) void __cdecl PawnScopeCatchPointer(void)
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

// R6Engine.dll @ 100402b4 : PawnScopeCatchContext
// Reports the vision-toggle context and rethrows through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PawnScopeCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecToggleScopeProperties
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045420 : ScopeVisionExceptionHandler
// Supplies the exact vision-toggle FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl ScopeVisionExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnScopeInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100402e0 : AR6Pawn::execGetKillResult
// Applies armor and random design tweaks to hit energy and stores one kill-chart category byte.
// Native ABI view retains the incoming frame word for the adjusted-damage word.
void __thiscall AR6Pawn::execGetKillResult(FFrame* stack, void* result)
{
  // Descriptive 32-bit native frame view; the incoming frame argument later holds adjusted damage.
  struct KillFrame {
    uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, tableWord, randomWord;
    int silencedWord, armorWord, damageWord, partWord, modifierWord;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &KillResultExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& iKillDamage = nativeFrame.damageWord;
  int& ePartHit = nativeFrame.partWord;
  int& eArmorType = nativeFrame.armorWord;
  int& iBulletToArmorModifier = nativeFrame.modifierWord;
  int& bHitBySilencedWeapon = nativeFrame.silencedWord;
  iKillDamage = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0;
  firstTable[token](firstReceiver, scriptFrame, &iKillDamage);
  // Describe the remaining inlined word evaluations; receiver/table/cursor reloads remain current.
  auto readWord = [&](int& word) {
    byte* currentCode = *codeCursor;
    UObject* receiver = scriptFrame->Object;
    word = 0;
    byte argumentToken = *currentCode++;
    *codeCursor = currentCode;
    ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
    table[argumentToken](receiver, scriptFrame, &word);
  };
  readWord(ePartHit);
  readWord(eArmorType);
  readWord(iBulletToArmorModifier);
  readWord(bHitBySilencedWeapon); // Evaluated but never read by this native calculation.
  code = *codeCursor + 1;
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  if (iKillDamage <= 0) {
    *(byte*)result = 0;
    ExceptionList = nativeFrame.previousExceptionList;
    return;
  }
  stResultTable* returnedTable = ((R6Charts*)&nativeChartsReceiver)->R6Charts::GetKillTable((eBodyPart)ePartHit);
  float10 scaledDamage = (float10)iKillDamage; // Load the live parameter after selecting the table.
  stResultTable*& killTable = *(stResultTable**)&nativeFrame.tableWord;
  killTable = returnedTable;
  scaledDamage *= nativeDouble0Point1;
  // Caller ABI view: pass the extended operand in ST0 and retain only the helper's low EAX word.
  auto truncateLowWord = [](float10 value) -> uint {
    uint lowWord;
    __asm {
      fld value
      call TruncateX87ToSigned64
      mov lowWord,eax
    }
    return lowWord;
  };
  uint adjusted = truncateLowWord(scaledDamage);
  int currentPart = ePartHit;
  int& adjustedDamage = reinterpret_cast<int&>(stack); // Reuses native EBP+8 after the last VM frame access.
  adjustedDamage = (int)adjusted;
  if (currentPart == 0 && (reinterpret_cast<byte*>(this)[0x6ca] & 1) == 0) { // Current m_bHelmetWasHit is false.
    adjusted += (uint)iBulletToArmorModifier;
    adjustedDamage = (int)adjusted;
  } else {
    int armor = eArmorType;
    if (armor == 0) {
      adjusted += (uint)iBulletToArmorModifier;
      adjustedDamage = (int)adjusted;
    } else if (armor == 1 || armor == 2 || armor == 3) {
      uint tweak = armor == 1 ? reinterpret_cast<const uint&>(this->m_iDesignLightTweak) :
          (armor == 2 ? reinterpret_cast<const uint&>(this->m_iDesignMediumTweak) :
              reinterpret_cast<const uint&>(this->m_iDesignHeavyTweak));
      uint modifier = (uint)iBulletToArmorModifier;
      adjusted -= tweak + modifier; // All arithmetic wraps in the native low DWORD.
      adjustedDamage = (int)adjusted;
    }
  }
  if ((int)adjusted < -50) adjustedDamage = -50;
  else if ((int)adjusted >= 50) adjustedDamage = 50;
  using RandomST0 = float10 (__cdecl*)();
  float10 randomValue = reinterpret_cast<RandomST0&>(CoreAppFrandImport)();
  volatile float& randomSpill = reinterpret_cast<float&>(nativeFrame.randomWord);
  randomSpill = (float)randomValue; // Native FST retains the unrounded ST0 operand below the conversion input.
  int randomTweak = this->m_iDesignRandomTweak;
  float10 randomAdjustment = (float10)randomTweak * randomValue;
  int adjustedResult = (int)truncateLowWord(randomAdjustment + (float10)adjustedDamage);
  if (adjustedResult < 1) adjustedResult = 1;
  if ((*reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x6c8) & 0x400000) != 0) { // m_bDesignToggleLog.
    int loggedPart = ePartHit;
    int loggedDamage = iKillDamage;
    FOutputDevice** logAddress = *(FOutputDevice***)&CoreGLogImport;
    FOutputDevice* device = *logAddress;
    double loggedRandom = (double)randomValue;
    device->FOutputDevice::Logf((const ushort*)L"Hit Energy %i rand %f ajusted result : %i on body part: %i",
        loggedDamage, loggedRandom, adjustedResult, loggedPart);
  }
  // Keep the original returned table pointer, then read current thresholds.
  const int* thresholds = (const int*)killTable;
  if (adjustedResult < thresholds[0]) *(byte*)result = 0;
  else if (adjustedResult < thresholds[1]) *(byte*)result = 1;
  else *(byte*)result = (byte)(2 + (adjustedResult >= thresholds[2]));
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1004051e : PawnKillResultCatchPointer
// Rethrows the caught text pointer through the inherited parent EBP-30 word.
__declspec(naked) __declspec(noreturn) void __cdecl PawnKillResultCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x34]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x30]
        push eax
        mov dword ptr [ebp-0x30],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10040532 : PawnKillResultCatchContext
// Reports the kill-query context and rethrows through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PawnKillResultCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetKillResult
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045430 : KillResultExceptionHandler
// Supplies the exact kill-query FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl KillResultExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnKillResultInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10040550 : AR6Pawn::execGetThroughResult
// Compares horizontal bullet direction with facing and stores a nonnegative penetration result word.
// Native ABI view retains the incoming frame word for the hit-part operand.
void __thiscall AR6Pawn::execGetThroughResult(FFrame* stack, void* result)
{
  // Descriptive 32-bit frame view; vector outputs remain uninitialized until their providers write them.
  struct ThroughFrame {
    uint savedEDI, savedESI, savedEBX, forwardWords[3], directionWords[3], caughtText, rethrowText;
    int damageWord;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &ThroughResultExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& iKillDamage = nativeFrame.damageWord;
  int& ePartHit = reinterpret_cast<int&>(stack); // Native reuses the incoming FFrame argument word at EBP+8.
  FVector& vBulletDirection = *(FVector*)nativeFrame.directionWords;
  FVector& forwardStorage = *(FVector*)nativeFrame.forwardWords;
  iKillDamage = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0;
  firstTable[token](firstReceiver, scriptFrame, &iKillDamage);
  code = *codeCursor;
  UObject* partReceiver = scriptFrame->Object;
  ePartHit = 0;
  token = *code++;
  *codeCursor = code;
  ScriptNative* partTable = *(ScriptNative**)&CoreGNativesImport;
  partTable[token](partReceiver, scriptFrame, &ePartHit);
  code = *codeCursor;
  token = *code; // The vector token is read before Frame.Object, unlike the preceding word argument.
  UObject* directionReceiver = scriptFrame->Object;
  ++code;
  *codeCursor = code;
  ScriptNative* directionTable = *(ScriptNative**)&CoreGNativesImport;
  directionTable[token](directionReceiver, scriptFrame, &vBulletDirection);
  code = *codeCursor + 1;
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  reinterpret_cast<uint&>(vBulletDirection.Z) = 0;
  vBulletDirection.Normalize(); // Its full return word is ignored.
  FVector* forward = &(forwardStorage = this->Rotation.Vector());
  float10 yProduct = (float10)vBulletDirection.Y * forward->Y;
  float10 zProduct = (float10)vBulletDirection.Z * forward->Z;
  float10 yz = yProduct + zProduct;
  float10 xProduct = (float10)vBulletDirection.X * forward->X;
  float10 alignment = yz + xProduct; // Uses the actual returned pointer and keeps the dot product extended.
  if (!(alignment >= nativeFloatZero)) alignment = -alignment; // Unordered takes FCHS; signed zero is retained.
  int oblique = alignment < nativeDouble0Point7071; // Exact native double0.7071; unordered yields zero.
  // Current m_eArmorType after both math providers, zero-extended from one byte.
  int armor = reinterpret_cast<byte&>(this->m_eArmorType);
  int currentPart = ePartHit;
  int currentDamage = iKillDamage;
  int penetration = ((R6Charts*)&nativeChartsReceiver)->R6Charts::BulletGoesThroughCharacter(currentDamage, currentPart,
      armor, oblique);
  *(int*)result = penetration < 0 ? 0 : penetration;
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10040689 : PawnThroughCatchPointer
// Rethrows the caught text pointer through the inherited parent EBP-18 word.
__declspec(naked) __declspec(noreturn) void __cdecl PawnThroughCatchPointer(void)
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

// R6Engine.dll @ 1004069d : PawnThroughCatchContext
// Reports the through-query context and rethrows through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PawnThroughCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetThroughResult
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045440 : ThroughResultExceptionHandler
// Supplies the exact through-query FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl ThroughResultExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnThroughInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100406c0 : AR6Pawn::execGetStunResult
// Applies armor and rounded random design tweaks to stun damage and stores a stun-chart category byte.
// Native ABI view retains the incoming frame word for the adjusted-damage word.
void __thiscall AR6Pawn::execGetStunResult(FFrame* stack, void* result)
{
  // Descriptive 32-bit native frame view; the incoming frame argument later holds adjusted damage.
  struct StunFrame {
    uint savedEDI, savedESI, savedEBX, caughtText, rethrowText, randomWord;
    int silencedWord, armorWord, partWord, damageWord, modifierWord;
    void* savedEsp;
    void* previousExceptionList;
    void* exceptionHandler;
    int exceptionState;
  } nativeFrame;
  nativeFrame.exceptionState = -1;
  nativeFrame.exceptionHandler = &StunResultExceptionHandler;
  nativeFrame.previousExceptionList = ExceptionList;
  ExceptionList = &nativeFrame.previousExceptionList;
  FFrame* scriptFrame = stack;
  byte** codeCursor = &scriptFrame->Code;
  byte* code = *codeCursor;
  int& iStunDamage = nativeFrame.damageWord;
  int& ePartHit = nativeFrame.partWord;
  int& eArmorType = nativeFrame.armorWord;
  int& iBulletToArmorModifier = nativeFrame.modifierWord;
  int& bHitBySilencedWeapon = nativeFrame.silencedWord;
  iStunDamage = 0;
  byte token = *code++;
  *codeCursor = code;
  nativeFrame.savedEsp = &nativeFrame.savedEDI;
  using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
  ScriptNative* firstTable = *(ScriptNative**)&CoreGNativesImport;
  UObject* firstReceiver = scriptFrame->Object;
  nativeFrame.exceptionState = 0;
  firstTable[token](firstReceiver, scriptFrame, &iStunDamage);
  // Describe the remaining inlined word evaluations; receiver/table/cursor reloads remain current.
  auto readWord = [&](int& word) {
    byte* currentCode = *codeCursor;
    UObject* receiver = scriptFrame->Object;
    word = 0;
    byte argumentToken = *currentCode++;
    *codeCursor = currentCode;
    ScriptNative* table = *(ScriptNative**)&CoreGNativesImport;
    table[argumentToken](receiver, scriptFrame, &word);
  };
  readWord(ePartHit);
  readWord(eArmorType);
  readWord(iBulletToArmorModifier);
  readWord(bHitBySilencedWeapon); // Evaluated but never read by this native calculation.
  code = *codeCursor + 1;
  *codeCursor = code;
  if (*code == 0x42) {
    UObject* debugReceiver = scriptFrame->Object;
    *codeCursor = code + 1;
    ScriptNative* debugTable = *(ScriptNative**)&CoreGNativesImport;
    debugTable[0x42](debugReceiver, scriptFrame, nullptr);
  }
  if (iStunDamage <= 0) {
    *(byte*)result = 0;
    ExceptionList = nativeFrame.previousExceptionList;
    return;
  }
  stResultTable* returnedTable = ((R6Charts*)&nativeChartsReceiver)->R6Charts::GetStunTable((eBodyPart)ePartHit);
  float10 scaledDamage = (float10)iStunDamage;
  stResultTable* stunTable = returnedTable; // Native retains this pointer in its callee-saved ESI.
  scaledDamage *= nativeDouble0Point1;
  // Caller ABI view: pass ST0 to the canonical helper and retain only low EAX.
  auto truncateLowWord = [](float10 value) -> uint {
    uint lowWord;
    __asm {
      fld value
      call TruncateX87ToSigned64
      mov lowWord,eax
    }
    return lowWord;
  };
  uint adjusted = truncateLowWord(scaledDamage);
  int armor = eArmorType;
  iStunDamage = (int)adjusted; // Native reuses the original VM damage-output word at EBP-18.
  if (armor == 1 || armor == 2 || armor == 3) {
    uint tweak = *(uint*)((byte*)this + 0x6b4 + armor * 4);
    uint modifier = (uint)iBulletToArmorModifier;
    adjusted -= tweak;
    adjusted -= modifier;
  } else {
    adjusted += (uint)iBulletToArmorModifier; // Includes unknown armor codes.
  }
  int& adjustedDamage = reinterpret_cast<int&>(stack); // Original incoming FFrame argument word at EBP+8.
  adjustedDamage = (int)adjusted;
  if ((int)adjusted < -50) adjustedDamage = -50;
  else if ((int)adjusted >= 50) adjustedDamage = 50;
  float returnedRandom = appFrand();
  volatile float& randomSpill = reinterpret_cast<float&>(nativeFrame.randomWord);
  randomSpill = returnedRandom; // Native FSTP discards the extended value before loading the tweak.
  int randomTweak = this->m_iDesignRandomTweak;
  float10 randomAdjustment = (float10)randomTweak * randomSpill;
  int adjustedResult = (int)truncateLowWord(randomAdjustment + (float10)adjustedDamage);
  const int* thresholds = (const int*)stunTable;
  if (adjustedResult < thresholds[0]) *(byte*)result = 0;
  else if (adjustedResult < thresholds[1]) *(byte*)result = 1;
  else *(byte*)result = (byte)(2 + (adjustedResult >= thresholds[2]));
  ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 1004089f : PawnStunCatchPointer
// Rethrows the caught text pointer through the inherited parent EBP-2c word.
__declspec(naked) __declspec(noreturn) void __cdecl PawnStunCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x30]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x2c]
        push edx
        mov dword ptr [ebp-0x2c],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100408b3 : PawnStunCatchContext
// Reports the stun-query context and rethrows through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl PawnStunCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecGetStunResult
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045450 : StunResultExceptionHandler
// Supplies the exact stun-query FuncInfo and tail-enters the exception dispatcher.
__declspec(naked) void __cdecl StunResultExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnStunInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042f80 : PawnDtorState0Cleanup
// Tail-enters abstract-pawn destruction through the inherited parent-frame saved receiver.
__declspec(naked) void PawnDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AR6AbstractPawnDestructorImport]
    }
}

// R6Engine.dll @ 10042f89 : PawnDtorExceptionHandler
// Selects the Pawn destructor's base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void PawnDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset pawnDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045b80 : InitializeAR6PawnClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6PawnClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = AR6AbstractPawnPrivateStaticClassImport;
    struct ConstructorPacket { // Inferred outgoing words at entry ESP-84..-28; no local ownership or cleanup.
        int zero;
        uint size, classFlags;
        UClass* parent;
        UClass* within;
        uint guid[4];
        const ushort* name;
        const ushort* package;
        const ushort* config;
        uint objectFlags;
        void (__cdecl* internalConstructor)(void*);
        uint staticConstructorWord;
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6Pawn::InternalConstructor;
    packet.objectFlags = 0x04084004;
    struct SavedImports { UClass* within; UClass* parent; } saved; // Entry ESP-8/-4, reloaded after config lookup.
    saved.within = withinClass;
    saved.parent = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = saved.within;
    parentClass = saved.parent;
    packet.config = configName;
    packet.package = (const ushort*)&enginePackageName;
    packet.name = nativeTextR6Pawn;
    packet.within = withinClass;
    packet.parent = parentClass;
    packet.guid[0] = 0;
    packet.classFlags = 0;
    packet.guid[1] = 0;
    packet.size = 0xa28;
    packet.guid[2] = 0;
    packet.zero = 0;
    packet.guid[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6Pawn::PrivateStaticClass, packet.zero, packet.size,
        packet.classFlags,
        packet.parent, packet.within, *(FGuid*)packet.guid, packet.name, packet.package, packet.config,
        packet.objectFlags, packet.internalConstructor, packet.staticConstructorWord);
    return _atexit(DestroyAR6PawnClassMetadata); // Register only after construction returns; preserve full EAX.
}

// R6Engine.dll @ 10047f80 : DestroyAR6PawnClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6PawnClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Pawn::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045c10 : PublishAR6PawnAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6PawnAutoClass(void)
{
    autoclassAR6Pawn = &AR6Pawn::PrivateStaticClass;
}

// R6Engine.dll @ 100473c0 : RegisterAR6PawnSetAudioInfoNative
// Registers native index0xaab using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnSetAudioInfoNative(void)
{
    AR6PawnSetAudioInfoRegistrationResult = GRegisterNative(0xaab, intAR6PawnexecSetAudioInfo);
}

// R6Engine.dll @ 100473e0 : RegisterAR6PawnPlayVoicesNative
// Registers native index0xaaa using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPlayVoicesNative(void)
{
    AR6PawnPlayVoicesRegistrationResult = GRegisterNative(0xaaa, intAR6PawnexecPlayVoices);
}

// R6Engine.dll @ 10047400 : RegisterAR6PawnSendPlaySoundNative
// Registers native index0xaa9 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnSendPlaySoundNative(void)
{
    AR6PawnSendPlaySoundRegistrationResult = GRegisterNative(0xaa9, intAR6PawnexecSendPlaySound);
}

// R6Engine.dll @ 10047420 : RegisterAR6PawnPawnCanBeHurtFromNative
// Registers native index0x735 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPawnCanBeHurtFromNative(void)
{
    AR6PawnPawnCanBeHurtFromRegistrationResult = GRegisterNative(0x735, intAR6PawnexecPawnCanBeHurtFrom);
}

// R6Engine.dll @ 10047440 : RegisterAR6PawnGetRotationOffsetNative
// Registers native index0x732 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetRotationOffsetNative(void)
{
    AR6PawnGetRotationOffsetRegistrationResult = GRegisterNative(0x732, intAR6PawnexecGetRotationOffset);
}

// R6Engine.dll @ 10047460 : RegisterAR6PawnR6GetViewRotationNative
// Registers native index0x731 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnR6GetViewRotationNative(void)
{
    AR6PawnR6GetViewRotationRegistrationResult = GRegisterNative(0x731, intAR6PawnexecR6GetViewRotation);
}

// R6Engine.dll @ 10047480 : RegisterAR6PawnUpdatePawnTrackActorNative
// Registers native index0x8aa using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnUpdatePawnTrackActorNative(void)
{
    AR6PawnUpdatePawnTrackActorRegistrationResult = GRegisterNative(0x8aa, intAR6PawnexecUpdatePawnTrackActor);
}

// R6Engine.dll @ 100474a0 : RegisterAR6PawnPawnTrackActorNative
// Registers native index0x8a9 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPawnTrackActorNative(void)
{
    AR6PawnPawnTrackActorRegistrationResult = GRegisterNative(0x8a9, intAR6PawnexecPawnTrackActor);
}

// R6Engine.dll @ 100474c0 : RegisterAR6PawnPawnLookAtNative
// Registers native index0x8a8 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPawnLookAtNative(void)
{
    AR6PawnPawnLookAtRegistrationResult = GRegisterNative(0x8a8, intAR6PawnexecPawnLookAt);
}

// R6Engine.dll @ 100474e0 : RegisterAR6PawnPawnLookAbsoluteNative
// Registers native index0x8a7 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPawnLookAbsoluteNative(void)
{
    AR6PawnPawnLookAbsoluteRegistrationResult = GRegisterNative(0x8a7, intAR6PawnexecPawnLookAbsolute);
}

// R6Engine.dll @ 10047500 : RegisterAR6PawnPawnLookNative
// Registers native index0x8a6 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnPawnLookNative(void)
{
    AR6PawnPawnLookRegistrationResult = GRegisterNative(0x8a6, intAR6PawnexecPawnLook);
}

// R6Engine.dll @ 10047520 : RegisterAR6PawnFootStepNative
// Registers native index0x734 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnFootStepNative(void)
{
    AR6PawnFootStepRegistrationResult = GRegisterNative(0x734, intAR6PawnexecFootStep);
}

// R6Engine.dll @ 10047540 : RegisterAR6PawnMoveHitBoneNative
// Registers native index0x736 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnMoveHitBoneNative(void)
{
    AR6PawnMoveHitBoneRegistrationResult = GRegisterNative(0x736, intAR6PawnexecMoveHitBone);
}

// R6Engine.dll @ 10047560 : RegisterAR6PawnStopLipSynchNative
// Registers native index0x643 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnStopLipSynchNative(void)
{
    AR6PawnStopLipSynchRegistrationResult = GRegisterNative(0x643, intAR6PawnexecStopLipSynch);
}

// R6Engine.dll @ 10047580 : RegisterAR6PawnStartLipSynchNative
// Registers native index0xa33 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnStartLipSynchNative(void)
{
    AR6PawnStartLipSynchRegistrationResult = GRegisterNative(0xa33, intAR6PawnexecStartLipSynch);
}

// R6Engine.dll @ 100475a0 : RegisterAR6PawnGetMovementDirectionNative
// Registers native index0x5ed using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetMovementDirectionNative(void)
{
    AR6PawnGetMovementDirectionRegistrationResult = GRegisterNative(0x5ed, intAR6PawnexecGetMovementDirection);
}

// R6Engine.dll @ 100475c0 : RegisterAR6PawnGetMaxRotationOffsetNative
// Registers native index0x5e8 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetMaxRotationOffsetNative(void)
{
    AR6PawnGetMaxRotationOffsetRegistrationResult = GRegisterNative(0x5e8, intAR6PawnexecGetMaxRotationOffset);
}

// R6Engine.dll @ 100475e0 : RegisterAR6PawnGetPeekingRatioNormNative
// Registers native index0x5e4 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetPeekingRatioNormNative(void)
{
    AR6PawnGetPeekingRatioNormRegistrationResult = GRegisterNative(0x5e4, intAR6PawnexecGetPeekingRatioNorm);
}

// R6Engine.dll @ 10047600 : RegisterAR6PawnCheckCylinderTranslationNative
// Registers native index0x5e3 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnCheckCylinderTranslationNative(void)
{
    AR6PawnCheckCylinderTranslationRegistrationResult = GRegisterNative(0x5e3, intAR6PawnexecCheckCylinderTranslation);
}

// R6Engine.dll @ 10047620 : RegisterAR6PawnSetPawnScaleNative
// Registers native index0x8a4 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnSetPawnScaleNative(void)
{
    AR6PawnSetPawnScaleRegistrationResult = GRegisterNative(0x8a4, intAR6PawnexecSetPawnScale);
}

// R6Engine.dll @ 10047640 : RegisterAR6PawnAdjustFluidCollisionCylinderNative
// Registers native index0x898 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnAdjustFluidCollisionCylinderNative(void)
{
    AR6PawnAdjustFluidCollisionCylinderRegistrationResult =
        GRegisterNative(0x898, intAR6PawnexecAdjustFluidCollisionCylinder);
}

// R6Engine.dll @ 10047660 : RegisterAR6PawnToggleScopePropertiesNative
// Registers native index0xa2d using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnToggleScopePropertiesNative(void)
{
    AR6PawnToggleScopePropertiesRegistrationResult = GRegisterNative(0xa2d, intAR6PawnexecToggleScopeProperties);
}

// R6Engine.dll @ 10047680 : RegisterAR6PawnToggleNightPropertiesNative
// Registers native index0xa28 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnToggleNightPropertiesNative(void)
{
    AR6PawnToggleNightPropertiesRegistrationResult = GRegisterNative(0xa28, intAR6PawnexecToggleNightProperties);
}

// R6Engine.dll @ 100476a0 : RegisterAR6PawnToggleHeatPropertiesNative
// Registers native index0x7d4 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnToggleHeatPropertiesNative(void)
{
    AR6PawnToggleHeatPropertiesRegistrationResult = GRegisterNative(0x7d4, intAR6PawnexecToggleHeatProperties);
}

// R6Engine.dll @ 100476c0 : RegisterAR6PawnGetThroughResultNative
// Registers native index0x7d6 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetThroughResultNative(void)
{
    AR6PawnGetThroughResultRegistrationResult = GRegisterNative(0x7d6, intAR6PawnexecGetThroughResult);
}

// R6Engine.dll @ 100476e0 : RegisterAR6PawnGetStunResultNative
// Registers native index0x7d3 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetStunResultNative(void)
{
    AR6PawnGetStunResultRegistrationResult = GRegisterNative(0x7d3, intAR6PawnexecGetStunResult);
}

// R6Engine.dll @ 10047700 : RegisterAR6PawnGetKillResultNative
// Registers native index0x7d2 using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterAR6PawnGetKillResultNative(void)
{
    AR6PawnGetKillResultRegistrationResult = GRegisterNative(0x7d2, intAR6PawnexecGetKillResult);
}

// R6Engine.dll @ 10045400 : ToggleHeatPropertiesExceptionHandler
// Supplies execToggleHeatProperties's selected FuncInfo to the shared frame handler, preserving the dispatcher's frame.
__declspec(naked) void __cdecl ToggleHeatPropertiesExceptionHandler(void)
{
    __asm {
        mov eax,offset toggleHeatPropertiesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003ff27 : ToggleHeatPropertiesCatchContext
// Reports the heat-toggle context, clears EBX and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ToggleHeatPropertiesCatchContext(void)
{
    __asm {
        push offset nativeTextAR6PawnExecToggleHeatProperties
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        xor ebx,ebx
        push ebx
        push ebx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10004ac0 : AR6Pawn::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6Pawn::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6PawnDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xa28;
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
    this->AR6Pawn::~AR6Pawn();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xa28;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll @ 10017320 : ClampFloatOrdered
// Selects the lower bound, value or upper bound using two ordered comparisons.
float10 __cdecl ClampFloatOrdered(float value, float minimum, float maximum)
{
    if ((float10)value < (float10)minimum)
        return (float10)minimum;
    if ((float10)value < (float10)maximum)
        return (float10)value;
    return (float10)maximum;
}

// R6Engine.dll @ 10024510 : MinFloatOrdered
// Returns the first operand for ordered less/equal, otherwise the second; signed-zero ties retain the first.
float10 __cdecl MinFloatOrdered(float first, float second)
{
    if (first <= second)
        return (float10)first;
    return (float10)second;
}

// R6Engine.dll @ 10024560 : CastToUNetConnection
// Returns the original object word for an imported connection class match or a null required class.
int __cdecl CastToUNetConnection(int object)
{
    if (object == 0)
        return 0;
    UClass* type = reinterpret_cast<UObject*>(static_cast<uint>(object))->Class;
    UClass* required = UNetConnectionPrivateStaticClassImport;
    while (type != nullptr) {
        if (type == required)
            return object;
        type = type->GetSuperClass();
    }
    return required == nullptr ? object : 0;
}

// R6Engine.dll @ 1002ba20 : FindPointerMapWord
// Follows the selected pointer-key bucket chain and returns its first matching value word, or zero.
uint __thiscall FindPointerMapWord(void* map, const uint* keyReference)
{
    // Partial native views; the untouched header bytes and original container type remain unresolved.
    struct MapPrefix {
        uint entriesAddress; // +0
        byte unaccessed4To11[8];
        uint bucketsAddress; // +12
        uint bucketCount; // +16
    };
    struct EntryPrefix {
        int nextIndex; // +0
        uint keyAddress; // +4
        uint valueWord; // +8
    };

    uint keyAddress = *keyReference;
    uint hashWord = keyAddress != 0 ? *(const uint*)(keyAddress + 4U) : 0U;
    const MapPrefix* mapView = reinterpret_cast<const MapPrefix*>(map);
    uint bucketCount = mapView->bucketCount;
    uint bucketIndex = (bucketCount - 1U) & hashWord;
    uint bucketsAddress = mapView->bucketsAddress;
    int entryIndex = *(const int*)(bucketsAddress + bucketIndex * 4U);
    if (entryIndex == -1)
        return 0;
    uint entriesAddress = mapView->entriesAddress;
    do {
        uint entryAddress = entriesAddress + (uint)entryIndex * 12U;
        const EntryPrefix* entryView = reinterpret_cast<const EntryPrefix*>(entryAddress);
        if (entryView->keyAddress == keyAddress)
            return entryView->valueWord;
        entryIndex = entryView->nextIndex;
    } while (entryIndex != -1);
    return 0;
}
