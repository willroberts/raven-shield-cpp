#include "import_bindings.h"

// Local import tails shared by the selected module's inherited virtual-method slots.
// The void(void) entry labels do not claim recovered imported-method prototypes. All native arguments, return widths,
// receiver/hidden-result registers, x87 values and caller stack state pass directly to the imported target.
// Imported method implementations and class layouts remain owned by their provider modules.
// FromList distinguishes the recovered const TArray<AVolume*>& overload; the descriptive entry names are inferred.

// R6Game.dll @ 10012bca : forward UObject::GetPropertiesSize through its Core.dll import
__declspec(naked) void ForwardImported_UObject_GetPropertiesSize(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_GetPropertiesSizeSlot] }
}

// R6Game.dll @ 10012bd0 : forward UObject::LanguageChange through its Core.dll import
__declspec(naked) void ForwardImported_UObject_LanguageChange(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_LanguageChangeSlot] }
}

// R6Game.dll @ 10012bd6 : forward UObject::Register through its Core.dll import
__declspec(naked) void ForwardImported_UObject_Register(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_RegisterSlot] }
}

// R6Game.dll @ 10012bdc : forward UObject::ScriptConsoleExec through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ScriptConsoleExec(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ScriptConsoleExecSlot] }
}

// R6Game.dll @ 10012be2 : forward UObject::CallFunction through its Core.dll import
__declspec(naked) void ForwardImported_UObject_CallFunction(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_CallFunctionSlot] }
}

// R6Game.dll @ 10012be8 : forward UObject::ShutdownAfterError through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ShutdownAfterError(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ShutdownAfterErrorSlot] }
}

// R6Game.dll @ 10012bee : forward UObject::GotoLabel through its Core.dll import
__declspec(naked) void ForwardImported_UObject_GotoLabel(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_GotoLabelSlot] }
}

// R6Game.dll @ 10012bf4 : forward UObject::GotoState through its Core.dll import
__declspec(naked) void ForwardImported_UObject_GotoState(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_GotoStateSlot] }
}

// R6Game.dll @ 10012bfa : forward UObject::Modify through its Core.dll import
__declspec(naked) void ForwardImported_UObject_Modify(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ModifySlot] }
}

// R6Game.dll @ 10012c00 : forward UObject::ProcessDelegate through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ProcessDelegate(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ProcessDelegateSlot] }
}

// R6Game.dll @ 10012c06 : forward UObject::Release through its Core.dll import
__declspec(naked) void ForwardImported_UObject_Release(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ReleaseSlot] }
}

// R6Game.dll @ 10012c0c : forward UObject::AddRef through its Core.dll import
__declspec(naked) void ForwardImported_UObject_AddRef(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_AddRefSlot] }
}

// R6Game.dll @ 10012c12 : forward UObject::QueryInterface through its Core.dll import
__declspec(naked) void ForwardImported_UObject_QueryInterface(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_QueryInterfaceSlot] }
}

// R6Game.dll @ 10012c18 : forward UObject::NetDirty through its Core.dll import
__declspec(naked) void ForwardImported_UObject_NetDirty(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_NetDirtySlot] }
}

// R6Game.dll @ 10012c1e : forward UObject::IsPendingDelete through its Core.dll import
__declspec(naked) void ForwardImported_UObject_IsPendingDelete(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_IsPendingDeleteSlot] }
}

// R6Game.dll @ 10012c24 : forward UObject::PostEditChange through its Core.dll import
__declspec(naked) void ForwardImported_UObject_PostEditChange(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_PostEditChangeSlot] }
}

// R6Game.dll @ 10012c2a : forward UObject::InitExecution through its Core.dll import
__declspec(naked) void ForwardImported_UObject_InitExecution(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_InitExecutionSlot] }
}

// R6Game.dll @ 10012c30 : forward UObject::IsPendingKill through its Core.dll import
__declspec(naked) void ForwardImported_UObject_IsPendingKill(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_IsPendingKillSlot] }
}

// R6Game.dll @ 10012c36 : forward UObject::Serialize through its Core.dll import
__declspec(naked) void ForwardImported_UObject_Serialize(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_SerializeSlot] }
}

// R6Game.dll @ 10012c3c : forward UObject::Destroy through its Core.dll import
__declspec(naked) void ForwardImported_UObject_Destroy(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_DestroySlot] }
}

// R6Game.dll @ 10012c42 : forward UObject::PostLoad through its Core.dll import
__declspec(naked) void ForwardImported_UObject_PostLoad(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_PostLoadSlot] }
}

// R6Game.dll @ 10012c48 : forward UObject::ProcessRemoteFunction through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ProcessRemoteFunction(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ProcessRemoteFunctionSlot] }
}

// R6Game.dll @ 10012c4e : forward UObject::ProcessState through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ProcessState(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ProcessStateSlot] }
}

// R6Game.dll @ 10012c54 : forward UObject::ProcessEvent through its Core.dll import
__declspec(naked) void ForwardImported_UObject_ProcessEvent(void)
{
    __asm { jmp dword ptr [R6GameImports::Core_UObject_ProcessEventSlot] }
}

// R6Game.dll @ 10012c5a : forward AController::GetTeamManager through its Engine.dll import
__declspec(naked) void ForwardImported_AController_GetTeamManager(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_GetTeamManagerSlot] }
}

// R6Game.dll @ 10012c60 : forward APlayerController::LocalPlayerController through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_LocalPlayerController(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_LocalPlayerControllerSlot] }
}

// R6Game.dll @ 10012c66 : forward AController::SetAdjustLocation through its Engine.dll import
__declspec(naked) void ForwardImported_AController_SetAdjustLocation(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_SetAdjustLocationSlot] }
}

// R6Game.dll @ 10012c6c : forward AController::AdjustFromWall through its Engine.dll import
__declspec(naked) void ForwardImported_AController_AdjustFromWall(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_AdjustFromWallSlot] }
}

// R6Game.dll @ 10012c72 : forward AController::AcceptNearbyPath through its Engine.dll import
__declspec(naked) void ForwardImported_AController_AcceptNearbyPath(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_AcceptNearbyPathSlot] }
}

// R6Game.dll @ 10012c78 : forward APlayerController::GetViewTarget through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_GetViewTarget(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_GetViewTargetSlot] }
}

// R6Game.dll @ 10012c7e : forward APlayerController::CheckHearSound through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_CheckHearSound(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_CheckHearSoundSlot] }
}

// R6Game.dll @ 10012c84 : forward AController::CanHear through its Engine.dll import
__declspec(naked) void ForwardImported_AController_CanHear(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_CanHearSlot] }
}

// R6Game.dll @ 10012c8a : forward AActor::GetProjectorBase through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetProjectorBase(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetProjectorBaseSlot] }
}

// R6Game.dll @ 10012c90 : forward AActor::PostPath through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostPath(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostPathSlot] }
}

// R6Game.dll @ 10012c96 : forward AActor::PrePath through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PrePath(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PrePathSlot] }
}

// R6Game.dll @ 10012c9c : forward AActor::CheckForErrors through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_CheckForErrors(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_CheckForErrorsSlot] }
}

// R6Game.dll @ 10012ca2 : forward AActor::TickThisFrame through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_TickThisFrame(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_TickThisFrameSlot] }
}

// R6Game.dll @ 10012ca8 : forward AActor::IsRelevantToPawnHeartBeat through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsRelevantToPawnHeartBeat(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsRelevantToPawnHeartBeatSlot] }
}

// R6Game.dll @ 10012cae : forward AActor::IsRelevantToPawnHeatVision through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsRelevantToPawnHeatVision(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsRelevantToPawnHeatVisionSlot] }
}

// R6Game.dll @ 10012cb4 : forward AActor::IsRelevantToPawnRadar through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsRelevantToPawnRadar(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsRelevantToPawnRadarSlot] }
}

// R6Game.dll @ 10012cba : forward AActor::PlayAnim through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PlayAnim(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PlayAnimSlot] }
}

// R6Game.dll @ 10012cc0 : forward AActor::HasAssociatedLevelGeometry through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_HasAssociatedLevelGeometry(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_HasAssociatedLevelGeometrySlot] }
}

// R6Game.dll @ 10012cc6 : forward AActor::AssociatedLevelGeometry through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_AssociatedLevelGeometry(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_AssociatedLevelGeometrySlot] }
}

// R6Game.dll @ 10012ccc : forward AActor::AddMyMarker through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_AddMyMarker(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_AddMyMarkerSlot] }
}

// R6Game.dll @ 10012cd2 : forward AActor::KMP2DynKarmaInterface through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_KMP2DynKarmaInterface(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_KMP2DynKarmaInterfaceSlot] }
}

// R6Game.dll @ 10012cd8 : forward AActor::postKarmaStep through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_postKarmaStep(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_postKarmaStepSlot] }
}

// R6Game.dll @ 10012cde : forward AActor::preKarmaStep through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_preKarmaStep(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_preKarmaStepSlot] }
}

// R6Game.dll @ 10012ce4 : forward AActor::physKarma through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_physKarma(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_physKarmaSlot] }
}

// R6Game.dll @ 10012cea : forward AActor::getKModel through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_getKModel(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_getKModelSlot] }
}

// R6Game.dll @ 10012cf0 : forward AActor::stepUp through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_stepUp(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_stepUpSlot] }
}

// R6Game.dll @ 10012cf6 : forward AActor::SmoothHitWall through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_SmoothHitWall(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SmoothHitWallSlot] }
}

// R6Game.dll @ 10012cfc : forward AActor::FindSlopeRotation through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_FindSlopeRotation(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_FindSlopeRotationSlot] }
}

// R6Game.dll @ 10012d02 : forward AActor::physFalling through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_physFalling(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_physFallingSlot] }
}

// R6Game.dll @ 10012d08 : forward AActor::processLanded through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_processLanded(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_processLandedSlot] }
}

// R6Game.dll @ 10012d0e : forward AActor::processHitWall through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_processHitWall(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_processHitWallSlot] }
}

// R6Game.dll @ 10012d14 : forward AActor::BoundProjectileVelocity through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_BoundProjectileVelocity(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_BoundProjectileVelocitySlot] }
}

// R6Game.dll @ 10012d1a : forward AActor::performPhysics through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_performPhysics(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_performPhysicsSlot] }
}

// R6Game.dll @ 10012d20 : forward AActor::setPhysics through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_setPhysics(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_setPhysicsSlot] }
}

// R6Game.dll @ 10012d26 : forward AActor::PostBeginPlay through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostBeginPlay(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostBeginPlaySlot] }
}

// R6Game.dll @ 10012d2c : forward AActor::SetVolumes through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_SetVolumes(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SetVolumesSlot] }
}

// R6Game.dll @ 10012d32 : forward AActor::SetVolumes through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_SetVolumesFromList(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SetVolumesFromListSlot] }
}

// R6Game.dll @ 10012d38 : forward AActor::SetZone through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_SetZone(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SetZoneSlot] }
}

// R6Game.dll @ 10012d3e : forward AActor::RenderEditorSelected through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_RenderEditorSelected(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_RenderEditorSelectedSlot] }
}

// R6Game.dll @ 10012d44 : forward AActor::RenderEditorInfo through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_RenderEditorInfo(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_RenderEditorInfoSlot] }
}

// R6Game.dll @ 10012d4a : forward APlayerController::IsNetRelevantFor through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_IsNetRelevantFor(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_IsNetRelevantForSlot] }
}

// R6Game.dll @ 10012d50 : forward AActor::PlayerControlled through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PlayerControlled(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PlayerControlledSlot] }
}

// R6Game.dll @ 10012d56 : forward AActor::TickSpecial through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_TickSpecial(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_TickSpecialSlot] }
}

// R6Game.dll @ 10012d5c : forward AActor::TickSimulated through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_TickSimulated(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_TickSimulatedSlot] }
}

// R6Game.dll @ 10012d62 : forward AActor::TickAuthoritative through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_TickAuthoritative(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_TickAuthoritativeSlot] }
}

// R6Game.dll @ 10012d68 : forward AActor::CheckOwnerUpdated through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_CheckOwnerUpdated(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_CheckOwnerUpdatedSlot] }
}

// R6Game.dll @ 10012d6e : forward AActor::UpdateTimers through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_UpdateTimers(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_UpdateTimersSlot] }
}

// R6Game.dll @ 10012d74 : forward AController::CheckAnimFinished through its Engine.dll import
__declspec(naked) void ForwardImported_AController_CheckAnimFinished(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_CheckAnimFinishedSlot] }
}

// R6Game.dll @ 10012d7a : forward AController::StartAnimPoll through its Engine.dll import
__declspec(naked) void ForwardImported_AController_StartAnimPoll(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AController_StartAnimPollSlot] }
}

// R6Game.dll @ 10012d80 : forward AActor::UpdateAnimation through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_UpdateAnimation(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_UpdateAnimationSlot] }
}

// R6Game.dll @ 10012d86 : forward AActor::NotifyAnimEnd through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_NotifyAnimEnd(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_NotifyAnimEndSlot] }
}

// R6Game.dll @ 10012d8c : forward AActor::GetViewRotation through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetViewRotation(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetViewRotationSlot] }
}

// R6Game.dll @ 10012d92 : forward AActor::SetBase through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_SetBase(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SetBaseSlot] }
}

// R6Game.dll @ 10012d98 : forward AActor::NotifyBump through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_NotifyBump(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_NotifyBumpSlot] }
}

// R6Game.dll @ 10012d9e : forward AActor::IsMovingBrush through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsMovingBrush(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsMovingBrushSlot] }
}

// R6Game.dll @ 10012da4 : forward AActor::BeginTouch through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_BeginTouch(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_BeginTouchSlot] }
}

// R6Game.dll @ 10012daa : forward AActor::GetPrimitive through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetPrimitive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetPrimitiveSlot] }
}

// R6Game.dll @ 10012db0 : forward AActor::ShouldTrace through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ShouldTrace(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ShouldTraceSlot] }
}

// R6Game.dll @ 10012db6 : forward AActor::PostScriptDestroyed through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostScriptDestroyed(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostScriptDestroyedSlot] }
}

// R6Game.dll @ 10012dbc : forward AActor::UpdateColBox through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_UpdateColBox(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_UpdateColBoxSlot] }
}

// R6Game.dll @ 10012dc2 : forward AActor::WorldToLocal through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_WorldToLocal(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_WorldToLocalSlot] }
}

// R6Game.dll @ 10012dc8 : forward AActor::LocalToWorld through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_LocalToWorld(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_LocalToWorldSlot] }
}

// R6Game.dll @ 10012dce : forward AActor::ToWorld through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ToWorld(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ToWorldSlot] }
}

// R6Game.dll @ 10012dd4 : forward AActor::ToLocal through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ToLocal(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ToLocalSlot] }
}

// R6Game.dll @ 10012dda : forward AActor::GetSkin through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetSkin(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetSkinSlot] }
}

// R6Game.dll @ 10012de0 : forward AActor::PostNetReceiveLocation through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostNetReceiveLocation(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostNetReceiveLocationSlot] }
}

// R6Game.dll @ 10012de6 : forward APlayerController::PostNetReceive through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_PostNetReceive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_PostNetReceiveSlot] }
}

// R6Game.dll @ 10012dec : forward APlayerController::PreNetReceive through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_PreNetReceive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_PreNetReceiveSlot] }
}

// R6Game.dll @ 10012df2 : forward AActor::Spawned through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_Spawned(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SpawnedSlot] }
}

// R6Game.dll @ 10012df8 : forward AActor::PostRaytrace through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostRaytrace(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostRaytraceSlot] }
}

// R6Game.dll @ 10012dfe : forward AActor::PreRaytrace through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PreRaytrace(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PreRaytraceSlot] }
}

// R6Game.dll @ 10012e04 : forward AActor::PostEditLoad through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostEditLoad(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostEditLoadSlot] }
}

// R6Game.dll @ 10012e0a : forward AActor::PostEditMove through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostEditMove(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostEditMoveSlot] }
}

// R6Game.dll @ 10012e10 : forward APlayerController::Tick through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_Tick(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_TickSlot] }
}

// R6Game.dll @ 10012e16 : forward AActor::WorldLightRadius through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_WorldLightRadius(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_WorldLightRadiusSlot] }
}

// R6Game.dll @ 10012e1c : forward AActor::GetNetPriority through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetNetPriority(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetNetPrioritySlot] }
}

// R6Game.dll @ 10012e22 : forward AActor::IsBlockedBy through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsBlockedBy(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsBlockedBySlot] }
}

// R6Game.dll @ 10012e28 : forward AActor::GetPawnOrColBoxOwner through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetPawnOrColBoxOwner(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetPawnOrColBoxOwnerSlot] }
}

// R6Game.dll @ 10012e2e : forward AActor::GetPlayerPawn through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetPlayerPawn(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetPlayerPawnSlot] }
}

// R6Game.dll @ 10012e34 : forward APlayerController::GetOptimizedRepList through its Engine.dll import
__declspec(naked) void ForwardImported_APlayerController_GetOptimizedRepList(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_APlayerController_GetOptimizedRepListSlot] }
}

// R6Game.dll @ 10012e3a : forward AActor::NetDirty through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_NetDirty(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_NetDirtySlot] }
}

// R6Game.dll @ 10012e40 : forward AActor::IsPendingDelete through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsPendingDelete(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsPendingDeleteSlot] }
}

// R6Game.dll @ 10012e46 : forward AActor::PostEditChange through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostEditChange(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostEditChangeSlot] }
}

// R6Game.dll @ 10012e4c : forward AActor::InitExecution through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_InitExecution(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_InitExecutionSlot] }
}

// R6Game.dll @ 10012e52 : forward AActor::IsPendingKill through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsPendingKill(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsPendingKillSlot] }
}

// R6Game.dll @ 10012e58 : forward AActor::Serialize through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_Serialize(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_SerializeSlot] }
}

// R6Game.dll @ 10012e5e : forward AActor::Destroy through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_Destroy(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_DestroySlot] }
}

// R6Game.dll @ 10012e64 : forward AActor::PostLoad through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostLoad(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostLoadSlot] }
}

// R6Game.dll @ 10012e6a : forward AActor::ProcessRemoteFunction through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ProcessRemoteFunction(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ProcessRemoteFunctionSlot] }
}

// R6Game.dll @ 10012e70 : forward AActor::ProcessState through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ProcessState(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ProcessStateSlot] }
}

// R6Game.dll @ 10012e76 : forward AActor::ProcessEvent through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_ProcessEvent(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_ProcessEventSlot] }
}

// R6Game.dll @ 10012e7c : forward AActor::IsNetRelevantFor through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_IsNetRelevantFor(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_IsNetRelevantForSlot] }
}

// R6Game.dll @ 10012e82 : forward AActor::CheckAnimFinished through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_CheckAnimFinished(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_CheckAnimFinishedSlot] }
}

// R6Game.dll @ 10012e88 : forward AActor::StartAnimPoll through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_StartAnimPoll(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_StartAnimPollSlot] }
}

// R6Game.dll @ 10012e8e : forward AActor::PostNetReceive through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PostNetReceive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PostNetReceiveSlot] }
}

// R6Game.dll @ 10012e94 : forward AActor::PreNetReceive through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_PreNetReceive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_PreNetReceiveSlot] }
}

// R6Game.dll @ 10012e9a : forward AActor::Tick through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_Tick(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_TickSlot] }
}

// R6Game.dll @ 10012ea0 : forward AActor::GetOptimizedRepList through its Engine.dll import
__declspec(naked) void ForwardImported_AActor_GetOptimizedRepList(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AActor_GetOptimizedRepListSlot] }
}

// R6Game.dll @ 10012ea6 : forward UR6FileManager::FindFile through its Engine.dll import
__declspec(naked) void ForwardImported_UR6FileManager_FindFile(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_UR6FileManager_FindFileSlot] }
}

// R6Game.dll @ 10012eac : forward UR6FileManager::GetNbFile through its Engine.dll import
__declspec(naked) void ForwardImported_UR6FileManager_GetNbFile(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_UR6FileManager_GetNbFileSlot] }
}

// R6Game.dll @ 10012eb2 : forward UR6FileManager::GetFileName through its Engine.dll import
__declspec(naked) void ForwardImported_UR6FileManager_GetFileName(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_UR6FileManager_GetFileNameSlot] }
}

// R6Game.dll @ 10012eb8 : forward ABrush::InitPosRotScale through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_InitPosRotScale(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_InitPosRotScaleSlot] }
}

// R6Game.dll @ 10012ebe : forward ABrush::CopyPosRotScaleFrom through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_CopyPosRotScaleFrom(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_CopyPosRotScaleFromSlot] }
}

// R6Game.dll @ 10012ec4 : forward ABrush::CheckForErrors through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_CheckForErrors(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_CheckForErrorsSlot] }
}

// R6Game.dll @ 10012eca : forward AVolume::PostBeginPlay through its Engine.dll import
__declspec(naked) void ForwardImported_AVolume_PostBeginPlay(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AVolume_PostBeginPlaySlot] }
}

// R6Game.dll @ 10012ed0 : forward AVolume::SetVolumes through its Engine.dll import
__declspec(naked) void ForwardImported_AVolume_SetVolumes(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AVolume_SetVolumesSlot] }
}

// R6Game.dll @ 10012ed6 : forward AVolume::SetVolumes through its Engine.dll import
__declspec(naked) void ForwardImported_AVolume_SetVolumesFromList(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AVolume_SetVolumesFromListSlot] }
}

// R6Game.dll @ 10012edc : forward ABrush::GetPrimitive through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_GetPrimitive(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_GetPrimitiveSlot] }
}

// R6Game.dll @ 10012ee2 : forward AVolume::ShouldTrace through its Engine.dll import
__declspec(naked) void ForwardImported_AVolume_ShouldTrace(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AVolume_ShouldTraceSlot] }
}

// R6Game.dll @ 10012ee8 : forward ABrush::ToWorld through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_ToWorld(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_ToWorldSlot] }
}

// R6Game.dll @ 10012eee : forward ABrush::ToLocal through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_ToLocal(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_ToLocalSlot] }
}

// R6Game.dll @ 10012ef4 : forward ABrush::PostEditChange through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_PostEditChange(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_PostEditChangeSlot] }
}

// R6Game.dll @ 10012efa : forward ABrush::PostLoad through its Engine.dll import
__declspec(naked) void ForwardImported_ABrush_PostLoad(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_ABrush_PostLoadSlot] }
}

// R6Game.dll @ 10012f00 : forward AHUD::DrawSpecificModeInfo through its Engine.dll import
__declspec(naked) void ForwardImported_AHUD_DrawSpecificModeInfo(void)
{
    __asm { jmp dword ptr [R6GameImports::Engine_AHUD_DrawSpecificModeInfoSlot] }
}
