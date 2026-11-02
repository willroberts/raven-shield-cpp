#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl ActionObjectBaseOnlyState0Cleanup(void);
__declspec(naked) void __cdecl ActorBaseOnlyDestructionState0Cleanup(void);
__declspec(naked) void AiControllerBaseState0Cleanup(void);
__declspec(naked) void __cdecl DeploymentBaseOnlyCleanupState0Cleanup(void);
__declspec(naked) void __cdecl GenericHBBaseOnlyState0Cleanup(void);
__declspec(naked) void __cdecl InteractiveObjectBaseOnlyState0Cleanup(void);
__declspec(naked) void __cdecl MatSubActionBaseCleanupState0Cleanup(void);
__declspec(naked) void __cdecl NavigationBaseOnlyDestructionState0Cleanup(void);
__declspec(naked) void __cdecl ObjectBaseConstructionState0Cleanup(void);
__declspec(naked) void __cdecl StatusStringState0Cleanup(void);
__declspec(naked) void __cdecl StatusStringState1Cleanup(void);
__declspec(naked) void __cdecl StatusStringState2Cleanup(void);

// R6Engine.dll data @ 1005e714 : statusStringUnwindMap
// Retains the exact shared temporary/result cleanup chain, without catch handlers.
const NativeUnwindEntry statusStringUnwindMap[3] = {
    { -1, ((uint)&StatusStringState0Cleanup) },
    { 0, ((uint)&StatusStringState1Cleanup) },
    { 0x1, ((uint)&StatusStringState2Cleanup) }
};

// R6Engine.dll data @ 1005e72c : statusStringFuncInfo
// Retains the exact shared temporary/result cleanup chain, without catch handlers.
const NativeFunctionInfoPrefix statusStringFuncInfo = { 0x19930520, 0x3, ((uint)&statusStringUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 100570a0 : objectBaseConstructionUnwind
// Retains the exact pending base/member cleanup states, without catches.
const NativeUnwindEntry objectBaseConstructionUnwind[1] = {
    { -1, ((uint)&ObjectBaseConstructionState0Cleanup) }
};

// R6Engine.dll data @ 100570a8 : objectBaseConstructionInfo
// Retains the exact pending base/member cleanup states, without catches.
const NativeFunctionInfoPrefix objectBaseConstructionInfo = { 0x19930520, 0x1, ((uint)&objectBaseConstructionUnwind), 0,
    0, 0 };

// R6Engine.dll data @ 100583a8 : matSubActionBaseCleanupUnwind
// State zero destroys the shared UMatSubAction base with no catch/report scope.
const NativeUnwindEntry matSubActionBaseCleanupUnwind[1] = {
    { -1, ((uint)&MatSubActionBaseCleanupState0Cleanup) }
};

// R6Engine.dll data @ 100583b0 : matSubActionBaseCleanupInfo
// Retains the exact shared one-state base cleanup map and no catches.
const NativeFunctionInfoPrefix matSubActionBaseCleanupInfo = { 0x19930520, 0x1, ((uint)&matSubActionBaseCleanupUnwind),
    0, 0, 0 };

// R6Engine.dll data @ 10058004 : aiControllerBaseUnwind
// Completed base unwinds to state-1 through the shared saved-this cleanup.
const NativeUnwindEntry aiControllerBaseUnwind[1] = {
    { -1, ((uint)&AiControllerBaseState0Cleanup) }
};

// R6Engine.dll data @ 1005800c : aiControllerBaseInfo
// One cleanup-only state, no try/catch regions; shared by RainbowAI default construction/destruction and HostageAI copy
// construction.
const NativeFunctionInfoPrefix aiControllerBaseInfo = { 0x19930520, 0x1, ((uint)&aiControllerBaseUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10058744 : genericHBBaseOnlyUnwindMap
// Destroys the completed GenericHB base if derived conditional destruction exits exceptionally.
const NativeUnwindEntry genericHBBaseOnlyUnwindMap[1] = {
    { -1, ((uint)&GenericHBBaseOnlyState0Cleanup) }
};

// R6Engine.dll data @ 1005874c : genericHBBaseOnlyFuncInfo
// Shares one cleanup-only state between the jammer and false-heartbeat destructors, with no catches.
const NativeFunctionInfoPrefix genericHBBaseOnlyFuncInfo = { 0x19930520, 0x1, ((uint)&genericHBBaseOnlyUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 100585b4 : interactiveObjectBaseOnlyUnwindMap
// Destroys the completed interactive-object base when conditional destruction exits exceptionally.
const NativeUnwindEntry interactiveObjectBaseOnlyUnwindMap[1] = {
    { -1, ((uint)&InteractiveObjectBaseOnlyState0Cleanup) }
};

// R6Engine.dll data @ 100585bc : interactiveObjectBaseOnlyFuncInfo
// Shares one cleanup-only state between ActionObject and GenericHB destruction, with no catches.
const NativeFunctionInfoPrefix interactiveObjectBaseOnlyFuncInfo = { 0x19930520, 0x1,
    ((uint)&interactiveObjectBaseOnlyUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058604 : actionObjectBaseOnlyUnwindMap
// Preserves native predecessor states and exact action-object/member cleanup associations.
const NativeUnwindEntry actionObjectBaseOnlyUnwindMap[1] = {
    { -1, ((uint)&ActionObjectBaseOnlyState0Cleanup) }
};

// R6Engine.dll data @ 1005860c : actionObjectBaseOnlyFuncInfo
// Preserves native predecessor states and exact action-object/member cleanup associations.
const NativeFunctionInfoPrefix actionObjectBaseOnlyFuncInfo = { 0x19930520, 0x1, ((uint)&actionObjectBaseOnlyUnwindMap),
    0, 0, 0 };

// R6Engine.dll data @ 10056d84 : navigationBaseOnlyDestructionUnwindMap
// Retains shared cleanup-only NavigationPoint-base destruction, without a catch/report scope.
const NativeUnwindEntry navigationBaseOnlyDestructionUnwindMap[1] = {
    { -1, ((uint)&NavigationBaseOnlyDestructionState0Cleanup) }
};

// R6Engine.dll data @ 10056d8c : navigationBaseOnlyDestructionFuncInfo
// Retains shared cleanup-only NavigationPoint-base destruction, without a catch/report scope.
const NativeFunctionInfoPrefix navigationBaseOnlyDestructionFuncInfo = { 0x19930520, 0x1,
    ((uint)&navigationBaseOnlyDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10058270 : deploymentBaseOnlyCleanupUnwindMap
// Retains exact pending member/base cleanup states, without a catch/report scope.
const NativeUnwindEntry deploymentBaseOnlyCleanupUnwindMap[1] = {
    { -1, ((uint)&DeploymentBaseOnlyCleanupState0Cleanup) }
};

// R6Engine.dll data @ 10058278 : deploymentBaseOnlyCleanupFuncInfo
// Retains exact pending member/base cleanup states, without a catch/report scope.
const NativeFunctionInfoPrefix deploymentBaseOnlyCleanupFuncInfo = { 0x19930520, 0x1,
    ((uint)&deploymentBaseOnlyCleanupUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 10056ea4 : actorBaseOnlyDestructionUnwindMap
// Retains shared cleanup-only AActor-base destruction, with no catch/report scope.
const NativeUnwindEntry actorBaseOnlyDestructionUnwindMap[1] = {
    { -1, ((uint)&ActorBaseOnlyDestructionState0Cleanup) }
};

// R6Engine.dll data @ 10056eac : actorBaseOnlyDestructionFuncInfo
// Retains shared cleanup-only AActor-base destruction, with no catch/report scope.
const NativeFunctionInfoPrefix actorBaseOnlyDestructionFuncInfo = { 0x19930520, 0x1,
    ((uint)&actorBaseOnlyDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll @ 10004c60 : DispatchFinishInitialization
// Shared Hostage/Terrorist FinishInitialization event body; uses the table captured before checked lookup.
void __thiscall DispatchFinishInitialization(UObject* object)
{
    uint nameWord = reinterpret_cast<const uint&>(R6ENGINE_FinishInitialization);
    byte* dispatchTable = *(byte**)object;
    UFunction* function = UObject::FindFunctionChecked(object, *(FName*)&nameWord, 0);
    using Dispatch = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    Dispatch processEvent = *(Dispatch*)(dispatchTable + 0x10);
    processEvent(object, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007990 : ReturnPlacementStorage
// Shared by fifty class placement-new exports; returns the storage argument without allocation or construction.
void* __cdecl ReturnPlacementStorage(uint allocationSize, EInternal* objectMemory)
{
    return objectMemory; // Plain RET leaves both arguments to the caller; null and aliased storage pass through.
}

// R6Engine.dll @ 10007c90 : DispatchSetCrouchBlend
// Shared Pawn/PlayerController export: dispatches the raw crouch-blend word from its incoming slot.
void __thiscall DispatchSetCrouchBlend(UObject* object, float fCrouchBlend)
{
    FName eventName = R6ENGINE_SetCrouchBlend;
    uint inputWord = reinterpret_cast<uint&>(fCrouchBlend);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(object);
    reinterpret_cast<uint&>(fCrouchBlend) = inputWord;
    UFunction* function = UObject::FindFunctionChecked(object, eventName, 0);
    using ProcessEvent = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    ProcessEvent processEvent = reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress);
    processEvent(object, function, &fCrouchBlend, nullptr);
}

// R6Engine.dll @ 100193c0 : SharedZeroResult
// Shared HurtByVolume/IsPointInZone leaf: ignores ECX and one argument word, then returns full-width zero.
// The neutral name and word parameter describe its ABI without selecting one class-facing export.
int __thiscall SharedZeroResult(void* object, uint unusedArgumentWord)
{
    return 0;
}

// R6Engine.dll @ 1001c220 : SharedNoOp
// Shared empty body for AMP2IOKarma::CheckForErrors and AR6InteractiveObject::PostScriptDestroyed.
void __thiscall SharedNoOp(void* object)
{
    return; // Genuine single RET; ignores ECX and does not define a return value.
}

// R6Engine.dll @ 10043230 : NavigationBaseOnlyDestructionState0Cleanup
// Destroys the saved NavigationPoint base through the real inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl NavigationBaseOnlyDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [ANavigationPointDestructorImport]
    }
}

// R6Engine.dll @ 100432d0 : ActorBaseOnlyDestructionState0Cleanup
// Destroys the saved AActor base through the real inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl ActorBaseOnlyDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AActorDestructorImport]
    }
}

// R6Engine.dll @ 100433c0 : ObjectBaseConstructionState0Cleanup
// Destroys the saved UObject base through the inherited dispatcher frame.
__declspec(naked) void __cdecl ObjectBaseConstructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UObjectDestructorImport]
    }
}

// R6Engine.dll @ 10043940 : DeploymentBaseOnlyCleanupState0Cleanup
// Destroys the shared completed deployment-zone base at inherited dispatcher EBP-0x10.
__declspec(naked) void __cdecl DeploymentBaseOnlyCleanupState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6DeploymentZoneDestructorNativeEntry
    }
}

// R6Engine.dll @ 100439d0 : MatSubActionBaseCleanupState0Cleanup
// Destroys the shared saved UMatSubAction base through the inherited dispatcher frame.
__declspec(naked) void __cdecl MatSubActionBaseCleanupState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UMatSubActionDestructorImport]
    }
}

// R6Engine.dll @ 10043b40 : InteractiveObjectBaseOnlyState0Cleanup
// Tail-enters the saved interactive-object base destructor for ActionObject and GenericHB destruction.
__declspec(naked) void __cdecl InteractiveObjectBaseOnlyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6InteractiveObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043b80 : ActionObjectBaseOnlyState0Cleanup
// Tail-enters the saved action-object base destructor for rotating-door construction and IOObject destruction.
__declspec(naked) void __cdecl ActionObjectBaseOnlyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6IActionObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043c50 : GenericHBBaseOnlyState0Cleanup
// Tail-enters the saved GenericHB base destructor for jammer and false-heartbeat destruction.
__declspec(naked) void __cdecl GenericHBBaseOnlyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6GenericHBDestructorNativeEntry
    }
}

// R6Engine.dll @ 10045470 : StatusStringState1Cleanup
// Destroys the shared status-string base temporary through the inherited FPO frame.
__declspec(naked) void __cdecl StatusStringState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045479 : StatusStringState2Cleanup
// Destroys the shared status-string label temporary through the inherited FPO frame.
__declspec(naked) void __cdecl StatusStringState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045482 : StatusStringState0Cleanup
// Clears the constructed-result bit before tail-calling the current destructor on the hidden output.
__declspec(naked) void __cdecl StatusStringState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x28]
        and eax,1
        je noResult
        and dword ptr [ebp-0x28],0xfffffffe
        mov ecx,dword ptr [ebp+4]
        jmp dword ptr [FStringDestructorImport]
    noResult:
        ret
    }
}

// R6Engine.dll @ 1001bc10 : CastToAPlayerController
// Returns the original object word when its class chain matches the imported player-controller class.
int __cdecl CastToAPlayerController(int object)
{
    if (object == 0)
        return 0;
    UClass* type = reinterpret_cast<UObject*>(static_cast<uint>(object))->Class;
    UClass* playerControllerClass = APlayerControllerPrivateStaticClassImport;
    while (type != nullptr) {
        if (type == playerControllerClass)
            return object;
        type = type->GetSuperClass();
    }
    return playerControllerClass == nullptr ? object : 0;
}

// R6Engine.dll @ 1001bc40 : return squared distance between two three-float vectors
float10 __cdecl SquaredDistanceBetweenVectors(const float *firstVector, const float *secondVector)
{
  float10 deltaX = (float10)secondVector[0] - (float10)firstVector[0];
  float10 deltaY = (float10)secondVector[1] - (float10)firstVector[1];
  float10 deltaZ = (float10)secondVector[2] - (float10)firstVector[2];
  return (deltaZ * deltaZ + deltaY * deltaY) + deltaX * deltaX;
}

// R6Engine.dll @ 1001bc70 : return the object if its class chain contains AR6SAHeartBeatJammer
int __cdecl CastToAR6SAHeartBeatJammer(int object)
{
  UClass *classCursor;
  if (object != 0) {
    for (classCursor = reinterpret_cast<UObject*>(static_cast<uint>(object))->Class; classCursor != nullptr;
        classCursor = classCursor->GetSuperClass()) {
      if (classCursor == &AR6SAHeartBeatJammer::PrivateStaticClass) {
        return object;
      }
    }
  }
  return 0;
}

// R6Engine.dll @ 100015a0 : ScaleVectorToResult
// Scales all three vector components before writing and returns the supplied output storage.
FVector* __cdecl ScaleVectorToResult(FVector* result, float scale, const FVector* source)
{
    float10 scaledZ = (float10)scale * source->Z;
    float10 scaledY = (float10)scale * source->Y;
    float10 scaledX = (float10)scale * source->X;
    result->X = (float)scaledX;
    result->Y = (float)scaledY;
    result->Z = (float)scaledZ;
    return result;
}

// R6Engine.dll @ 100432d9 : ActorBaseOnlyDestructionExceptionHandler
// Supplies the shared cleanup-only AActor-base FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl ActorBaseOnlyDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset actorBaseOnlyDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043948 : DeploymentBaseOnlyCleanupExceptionHandler
// Supplies the exact cleanup-only FuncInfo to the shared dispatcher without adding a frame.
__declspec(naked) void __cdecl DeploymentBaseOnlyCleanupExceptionHandler(void)
{
    __asm {
        mov eax,offset deploymentBaseOnlyCleanupFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043239 : NavigationBaseOnlyDestructionExceptionHandler
// Supplies the shared NavigationPoint-base FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl NavigationBaseOnlyDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset navigationBaseOnlyDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043b88 : ActionObjectBaseOnlyExceptionHandler
// Supplies one shared base-destruction action for two parents without creating a dispatcher frame.
__declspec(naked) void __cdecl ActionObjectBaseOnlyExceptionHandler(void)
{
    __asm {
        mov eax,offset actionObjectBaseOnlyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043b48 : InteractiveObjectBaseOnlyExceptionHandler
// Supplies the shared interactive-object destruction FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl InteractiveObjectBaseOnlyExceptionHandler(void)
{
    __asm {
        mov eax,offset interactiveObjectBaseOnlyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043c58 : GenericHBBaseOnlyExceptionHandler
// Supplies the shared GenericHB-base destruction FuncInfo without changing the native dispatcher frame.
__declspec(naked) void __cdecl GenericHBBaseOnlyExceptionHandler(void)
{
    __asm {
        mov eax,offset genericHBBaseOnlyFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100436a0 : AiControllerBaseState0Cleanup
// Destroys the saved controller base when the a registered AI-controller-base guard unwinds.
__declspec(naked) void AiControllerBaseState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6AIControllerDestructorNativeEntry
    }
}

// R6Engine.dll @ 100436a8 : AiControllerBaseExceptionHandler
// Supplies the shared AI-controller-base cleanup metadata without changing the inherited frame.
__declspec(naked) void AiControllerBaseExceptionHandler(void)
{
    __asm {
        mov eax,offset aiControllerBaseInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100439d9 : MatSubActionBaseCleanupExceptionHandler
// Supplies the exact shared base-cleanup FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl MatSubActionBaseCleanupExceptionHandler(void)
{
    __asm {
        mov eax,offset matSubActionBaseCleanupInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100433c9 : ObjectBaseConstructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl ObjectBaseConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset objectBaseConstructionInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1004549c : StatusStringExceptionHandler
// Selects the exception metadata shared by both action status-string overrides.
__declspec(naked) void __cdecl StatusStringExceptionHandler(void)
{
    __asm {
        mov eax,offset statusStringFuncInfo
        jmp __CxxFrameHandler
    }
}
