#include "native_import_slots.hpp"

// Import-tail and slot names are descriptive, not recovered C++ identifiers.
// Each mutable PE32 IAT word is read by the original tail jump without adding a C++ call frame.

// R6Engine.dll @ 100422c4 : UObjectGetPropertiesSizeImportThunk
// Tail-forwards to Core.dll UObject::GetPropertiesSize with the original registers and stack.
__declspec(naked) void UObjectGetPropertiesSizeImportThunk(void)
{
    __asm { jmp dword ptr [UObjectGetPropertiesSizeImport] }
}

// R6Engine.dll @ 100422ca : UObjectLanguageChangeImportThunk
// Tail-forwards to Core.dll UObject::LanguageChange with the original registers and stack.
__declspec(naked) void UObjectLanguageChangeImportThunk(void)
{
    __asm { jmp dword ptr [UObjectLanguageChangeImport] }
}

// R6Engine.dll @ 100422d0 : UObjectRegisterImportThunk
// Tail-forwards to Core.dll UObject::Register with the original registers and stack.
__declspec(naked) void UObjectRegisterImportThunk(void)
{
    __asm { jmp dword ptr [UObjectRegisterImport] }
}

// R6Engine.dll @ 100422d6 : UObjectScriptConsoleExecImportThunk
// Tail-forwards to Core.dll UObject::ScriptConsoleExec with the original registers and stack.
__declspec(naked) void UObjectScriptConsoleExecImportThunk(void)
{
    __asm { jmp dword ptr [UObjectScriptConsoleExecImport] }
}

// R6Engine.dll @ 100422dc : UObjectCallFunctionImportThunk
// Tail-forwards to Core.dll UObject::CallFunction with the original registers and stack.
__declspec(naked) void UObjectCallFunctionImportThunk(void)
{
    __asm { jmp dword ptr [UObjectCallFunctionImport] }
}

// R6Engine.dll @ 100422e2 : UObjectShutdownAfterErrorImportThunk
// Tail-forwards to Core.dll UObject::ShutdownAfterError with the original registers and stack.
__declspec(naked) void UObjectShutdownAfterErrorImportThunk(void)
{
    __asm { jmp dword ptr [UObjectShutdownAfterErrorImport] }
}

// R6Engine.dll @ 100422e8 : UObjectGotoLabelImportThunk
// Tail-forwards to Core.dll UObject::GotoLabel with the original registers and stack.
__declspec(naked) void UObjectGotoLabelImportThunk(void)
{
    __asm { jmp dword ptr [UObjectGotoLabelImport] }
}

// R6Engine.dll @ 100422ee : UObjectGotoStateImportThunk
// Tail-forwards to Core.dll UObject::GotoState with the original registers and stack.
__declspec(naked) void UObjectGotoStateImportThunk(void)
{
    __asm { jmp dword ptr [UObjectGotoStateImport] }
}

// R6Engine.dll @ 100422f4 : UObjectModifyImportThunk
// Tail-forwards to Core.dll UObject::Modify with the original registers and stack.
__declspec(naked) void UObjectModifyImportThunk(void)
{
    __asm { jmp dword ptr [UObjectModifyImport] }
}

// R6Engine.dll @ 100422fa : UObjectProcessDelegateImportThunk
// Tail-forwards to Core.dll UObject::ProcessDelegate with the original registers and stack.
__declspec(naked) void UObjectProcessDelegateImportThunk(void)
{
    __asm { jmp dword ptr [UObjectProcessDelegateImport] }
}

// R6Engine.dll @ 10042312 : UObjectNetDirtyImportThunk
// Tail-forwards to Core.dll UObject::NetDirty with the original registers and stack.
__declspec(naked) void UObjectNetDirtyImportThunk(void)
{
    __asm { jmp dword ptr [UObjectNetDirtyImport] }
}

// R6Engine.dll @ 10042318 : UObjectIsPendingDeleteImportThunk
// Tail-forwards to Core.dll UObject::IsPendingDelete with the original registers and stack.
__declspec(naked) void UObjectIsPendingDeleteImportThunk(void)
{
    __asm { jmp dword ptr [UObjectIsPendingDeleteImport] }
}

// R6Engine.dll @ 1004231e : UObjectInitExecutionImportThunk
// Tail-forwards to Core.dll UObject::InitExecution with the original registers and stack.
__declspec(naked) void UObjectInitExecutionImportThunk(void)
{
    __asm { jmp dword ptr [UObjectInitExecutionImport] }
}

// R6Engine.dll @ 10042324 : UObjectIsPendingKillImportThunk
// Tail-forwards to Core.dll UObject::IsPendingKill with the original registers and stack.
__declspec(naked) void UObjectIsPendingKillImportThunk(void)
{
    __asm { jmp dword ptr [UObjectIsPendingKillImport] }
}

// R6Engine.dll @ 1004232a : UObjectSerializeImportThunk
// Tail-forwards to Core.dll UObject::Serialize with the original registers and stack.
__declspec(naked) void UObjectSerializeImportThunk(void)
{
    __asm { jmp dword ptr [UObjectSerializeImport] }
}

// R6Engine.dll @ 10042330 : UObjectDestroyImportThunk
// Tail-forwards to Core.dll UObject::Destroy with the original registers and stack.
__declspec(naked) void UObjectDestroyImportThunk(void)
{
    __asm { jmp dword ptr [UObjectDestroyImport] }
}

// R6Engine.dll @ 10042336 : UObjectPostLoadImportThunk
// Tail-forwards to Core.dll UObject::PostLoad with the original registers and stack.
__declspec(naked) void UObjectPostLoadImportThunk(void)
{
    __asm { jmp dword ptr [UObjectPostLoadImport] }
}

// R6Engine.dll @ 1004233c : UObjectProcessRemoteFunctionImportThunk
// Tail-forwards to Core.dll UObject::ProcessRemoteFunction with the original registers and stack.
__declspec(naked) void UObjectProcessRemoteFunctionImportThunk(void)
{
    __asm { jmp dword ptr [UObjectProcessRemoteFunctionImport] }
}

// R6Engine.dll @ 10042342 : UObjectProcessStateImportThunk
// Tail-forwards to Core.dll UObject::ProcessState with the original registers and stack.
__declspec(naked) void UObjectProcessStateImportThunk(void)
{
    __asm { jmp dword ptr [UObjectProcessStateImport] }
}

// R6Engine.dll @ 10042348 : UObjectProcessEventImportThunk
// Tail-forwards to Core.dll UObject::ProcessEvent with the original registers and stack.
__declspec(naked) void UObjectProcessEventImportThunk(void)
{
    __asm { jmp dword ptr [UObjectProcessEventImport] }
}

// R6Engine.dll @ 1004234e : UObjectPostEditChangeImportThunk
// Tail-forwards to Core.dll UObject::PostEditChange with the original registers and stack.
__declspec(naked) void UObjectPostEditChangeImportThunk(void)
{
    __asm { jmp dword ptr [UObjectPostEditChangeImport] }
}

// R6Engine.dll @ 10042354 : AActorGetProjectorBaseImportThunk
// Tail-forwards to Engine.dll AActor::GetProjectorBase with the original registers and stack.
__declspec(naked) void AActorGetProjectorBaseImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetProjectorBaseImport] }
}

// R6Engine.dll @ 1004235a : AActorPostPathImportThunk
// Tail-forwards to Engine.dll AActor::PostPath with the original registers and stack.
__declspec(naked) void AActorPostPathImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostPathImport] }
}

// R6Engine.dll @ 10042360 : AActorPrePathImportThunk
// Tail-forwards to Engine.dll AActor::PrePath with the original registers and stack.
__declspec(naked) void AActorPrePathImportThunk(void)
{
    __asm { jmp dword ptr [AActorPrePathImport] }
}

// R6Engine.dll @ 10042366 : AActorCheckForErrorsImportThunk
// Tail-forwards to Engine.dll AActor::CheckForErrors with the original registers and stack.
__declspec(naked) void AActorCheckForErrorsImportThunk(void)
{
    __asm { jmp dword ptr [AActorCheckForErrorsImport] }
}

// R6Engine.dll @ 1004236c : AActorTickThisFrameImportThunk
// Tail-forwards to Engine.dll AActor::TickThisFrame with the original registers and stack.
__declspec(naked) void AActorTickThisFrameImportThunk(void)
{
    __asm { jmp dword ptr [AActorTickThisFrameImport] }
}

// R6Engine.dll @ 10042372 : AActorIsRelevantToPawnHeartBeatImportThunk
// Tail-forwards to Engine.dll AActor::IsRelevantToPawnHeartBeat with the original registers and stack.
__declspec(naked) void AActorIsRelevantToPawnHeartBeatImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsRelevantToPawnHeartBeatImport] }
}

// R6Engine.dll @ 10042378 : AActorIsRelevantToPawnHeatVisionImportThunk
// Tail-forwards to Engine.dll AActor::IsRelevantToPawnHeatVision with the original registers and stack.
__declspec(naked) void AActorIsRelevantToPawnHeatVisionImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsRelevantToPawnHeatVisionImport] }
}

// R6Engine.dll @ 1004237e : AActorIsRelevantToPawnRadarImportThunk
// Tail-forwards to Engine.dll AActor::IsRelevantToPawnRadar with the original registers and stack.
__declspec(naked) void AActorIsRelevantToPawnRadarImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsRelevantToPawnRadarImport] }
}

// R6Engine.dll @ 10042384 : AActorPlayAnimImportThunk
// Tail-forwards to Engine.dll AActor::PlayAnim with the original registers and stack.
__declspec(naked) void AActorPlayAnimImportThunk(void)
{
    __asm { jmp dword ptr [AActorPlayAnimImport] }
}

// R6Engine.dll @ 1004238a : AActorHasAssociatedLevelGeometryImportThunk
// Tail-forwards to Engine.dll AActor::HasAssociatedLevelGeometry with the original registers and stack.
__declspec(naked) void AActorHasAssociatedLevelGeometryImportThunk(void)
{
    __asm { jmp dword ptr [AActorHasAssociatedLevelGeometryImport] }
}

// R6Engine.dll @ 10042390 : AActorAssociatedLevelGeometryImportThunk
// Tail-forwards to Engine.dll AActor::AssociatedLevelGeometry with the original registers and stack.
__declspec(naked) void AActorAssociatedLevelGeometryImportThunk(void)
{
    __asm { jmp dword ptr [AActorAssociatedLevelGeometryImport] }
}

// R6Engine.dll @ 10042396 : AActorAddMyMarkerImportThunk
// Tail-forwards to Engine.dll AActor::AddMyMarker with the original registers and stack.
__declspec(naked) void AActorAddMyMarkerImportThunk(void)
{
    __asm { jmp dword ptr [AActorAddMyMarkerImport] }
}

// R6Engine.dll @ 1004239c : AActorKMP2DynKarmaInterfaceImportThunk
// Tail-forwards to Engine.dll AActor::KMP2DynKarmaInterface with the original registers and stack.
__declspec(naked) void AActorKMP2DynKarmaInterfaceImportThunk(void)
{
    __asm { jmp dword ptr [AActorKMP2DynKarmaInterfaceImport] }
}

// R6Engine.dll @ 100423a2 : AActorPostKarmaStepImportThunk
// Tail-forwards to Engine.dll AActor::postKarmaStep with the original registers and stack.
__declspec(naked) void AActorPostKarmaStepImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostKarmaStepImport] }
}

// R6Engine.dll @ 100423a8 : AActorPreKarmaStepImportThunk
// Tail-forwards to Engine.dll AActor::preKarmaStep with the original registers and stack.
__declspec(naked) void AActorPreKarmaStepImportThunk(void)
{
    __asm { jmp dword ptr [AActorPreKarmaStepImport] }
}

// R6Engine.dll @ 100423ae : AActorPhysKarmaImportThunk
// Tail-forwards to Engine.dll AActor::physKarma with the original registers and stack.
__declspec(naked) void AActorPhysKarmaImportThunk(void)
{
    __asm { jmp dword ptr [AActorPhysKarmaImport] }
}

// R6Engine.dll @ 100423b4 : AActorGetKModelImportThunk
// Tail-forwards to Engine.dll AActor::getKModel with the original registers and stack.
__declspec(naked) void AActorGetKModelImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetKModelImport] }
}

// R6Engine.dll @ 100423ba : AActorStepUpImportThunk
// Tail-forwards to Engine.dll AActor::stepUp with the original registers and stack.
__declspec(naked) void AActorStepUpImportThunk(void)
{
    __asm { jmp dword ptr [AActorStepUpImport] }
}

// R6Engine.dll @ 100423c0 : AActorSmoothHitWallImportThunk
// Tail-forwards to Engine.dll AActor::SmoothHitWall with the original registers and stack.
__declspec(naked) void AActorSmoothHitWallImportThunk(void)
{
    __asm { jmp dword ptr [AActorSmoothHitWallImport] }
}

// R6Engine.dll @ 100423c6 : AActorFindSlopeRotationImportThunk
// Tail-forwards to Engine.dll AActor::FindSlopeRotation with the original registers and stack.
__declspec(naked) void AActorFindSlopeRotationImportThunk(void)
{
    __asm { jmp dword ptr [AActorFindSlopeRotationImport] }
}

// R6Engine.dll @ 100423cc : AActorPhysFallingImportThunk
// Tail-forwards to Engine.dll AActor::physFalling with the original registers and stack.
__declspec(naked) void AActorPhysFallingImportThunk(void)
{
    __asm { jmp dword ptr [AActorPhysFallingImport] }
}

// R6Engine.dll @ 100423d2 : AActorProcessLandedImportThunk
// Tail-forwards to Engine.dll AActor::processLanded with the original registers and stack.
__declspec(naked) void AActorProcessLandedImportThunk(void)
{
    __asm { jmp dword ptr [AActorProcessLandedImport] }
}

// R6Engine.dll @ 100423d8 : AActorProcessHitWallImportThunk
// Tail-forwards to Engine.dll AActor::processHitWall with the original registers and stack.
__declspec(naked) void AActorProcessHitWallImportThunk(void)
{
    __asm { jmp dword ptr [AActorProcessHitWallImport] }
}

// R6Engine.dll @ 100423de : AActorBoundProjectileVelocityImportThunk
// Tail-forwards to Engine.dll AActor::BoundProjectileVelocity with the original registers and stack.
__declspec(naked) void AActorBoundProjectileVelocityImportThunk(void)
{
    __asm { jmp dword ptr [AActorBoundProjectileVelocityImport] }
}

// R6Engine.dll @ 100423e4 : AActorPerformPhysicsImportThunk
// Tail-forwards to Engine.dll AActor::performPhysics with the original registers and stack.
__declspec(naked) void AActorPerformPhysicsImportThunk(void)
{
    __asm { jmp dword ptr [AActorPerformPhysicsImport] }
}

// R6Engine.dll @ 100423f0 : AActorPostBeginPlayImportThunk
// Tail-forwards to Engine.dll AActor::PostBeginPlay with the original registers and stack.
__declspec(naked) void AActorPostBeginPlayImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostBeginPlayImport] }
}

// R6Engine.dll @ 100423f6 : AActorSetVolumesImportThunk
// Tail-forwards to Engine.dll AActor::SetVolumes with the original registers and stack.
__declspec(naked) void AActorSetVolumesImportThunk(void)
{
    __asm { jmp dword ptr [AActorSetVolumesImport] }
}

// R6Engine.dll @ 100423fc : AActorSetVolumesFromListImportThunk
// Tail-forwards to Engine.dll AActor::SetVolumes with the original registers and stack.
__declspec(naked) void AActorSetVolumesFromListImportThunk(void)
{
    __asm { jmp dword ptr [AActorSetVolumesFromListImport] }
}

// R6Engine.dll @ 10042402 : AActorSetZoneImportThunk
// Tail-forwards to Engine.dll AActor::SetZone with the original registers and stack.
__declspec(naked) void AActorSetZoneImportThunk(void)
{
    __asm { jmp dword ptr [AActorSetZoneImport] }
}

// R6Engine.dll @ 10042408 : AActorRenderEditorSelectedImportThunk
// Tail-forwards to Engine.dll AActor::RenderEditorSelected with the original registers and stack.
__declspec(naked) void AActorRenderEditorSelectedImportThunk(void)
{
    __asm { jmp dword ptr [AActorRenderEditorSelectedImport] }
}

// R6Engine.dll @ 1004240e : AActorRenderEditorInfoImportThunk
// Tail-forwards to Engine.dll AActor::RenderEditorInfo with the original registers and stack.
__declspec(naked) void AActorRenderEditorInfoImportThunk(void)
{
    __asm { jmp dword ptr [AActorRenderEditorInfoImport] }
}

// R6Engine.dll @ 10042414 : AActorIsNetRelevantForImportThunk
// Tail-forwards to Engine.dll AActor::IsNetRelevantFor with the original registers and stack.
__declspec(naked) void AActorIsNetRelevantForImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsNetRelevantForImport] }
}

// R6Engine.dll @ 1004241a : AActorPlayerControlledImportThunk
// Tail-forwards to Engine.dll AActor::PlayerControlled with the original registers and stack.
__declspec(naked) void AActorPlayerControlledImportThunk(void)
{
    __asm { jmp dword ptr [AActorPlayerControlledImport] }
}

// R6Engine.dll @ 10042420 : AActorTickSpecialImportThunk
// Tail-forwards to Engine.dll AActor::TickSpecial with the original registers and stack.
__declspec(naked) void AActorTickSpecialImportThunk(void)
{
    __asm { jmp dword ptr [AActorTickSpecialImport] }
}

// R6Engine.dll @ 10042426 : AActorTickSimulatedImportThunk
// Tail-forwards to Engine.dll AActor::TickSimulated with the original registers and stack.
__declspec(naked) void AActorTickSimulatedImportThunk(void)
{
    __asm { jmp dword ptr [AActorTickSimulatedImport] }
}

// R6Engine.dll @ 1004242c : AActorTickAuthoritativeImportThunk
// Tail-forwards to Engine.dll AActor::TickAuthoritative with the original registers and stack.
__declspec(naked) void AActorTickAuthoritativeImportThunk(void)
{
    __asm { jmp dword ptr [AActorTickAuthoritativeImport] }
}

// R6Engine.dll @ 10042432 : AActorCheckOwnerUpdatedImportThunk
// Tail-forwards to Engine.dll AActor::CheckOwnerUpdated with the original registers and stack.
__declspec(naked) void AActorCheckOwnerUpdatedImportThunk(void)
{
    __asm { jmp dword ptr [AActorCheckOwnerUpdatedImport] }
}

// R6Engine.dll @ 10042438 : AActorUpdateTimersImportThunk
// Tail-forwards to Engine.dll AActor::UpdateTimers with the original registers and stack.
__declspec(naked) void AActorUpdateTimersImportThunk(void)
{
    __asm { jmp dword ptr [AActorUpdateTimersImport] }
}

// R6Engine.dll @ 1004243e : AActorCheckAnimFinishedImportThunk
// Tail-forwards to Engine.dll AActor::CheckAnimFinished with the original registers and stack.
__declspec(naked) void AActorCheckAnimFinishedImportThunk(void)
{
    __asm { jmp dword ptr [AActorCheckAnimFinishedImport] }
}

// R6Engine.dll @ 10042444 : AActorStartAnimPollImportThunk
// Tail-forwards to Engine.dll AActor::StartAnimPoll with the original registers and stack.
__declspec(naked) void AActorStartAnimPollImportThunk(void)
{
    __asm { jmp dword ptr [AActorStartAnimPollImport] }
}

// R6Engine.dll @ 1004244a : AActorUpdateAnimationImportThunk
// Tail-forwards to Engine.dll AActor::UpdateAnimation with the original registers and stack.
__declspec(naked) void AActorUpdateAnimationImportThunk(void)
{
    __asm { jmp dword ptr [AActorUpdateAnimationImport] }
}

// R6Engine.dll @ 10042450 : AActorNotifyAnimEndImportThunk
// Tail-forwards to Engine.dll AActor::NotifyAnimEnd with the original registers and stack.
__declspec(naked) void AActorNotifyAnimEndImportThunk(void)
{
    __asm { jmp dword ptr [AActorNotifyAnimEndImport] }
}

// R6Engine.dll @ 10042456 : AActorGetViewRotationImportThunk
// Tail-forwards to Engine.dll AActor::GetViewRotation with the original registers and stack.
__declspec(naked) void AActorGetViewRotationImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetViewRotationImport] }
}

// R6Engine.dll @ 1004245c : AActorSetBaseImportThunk
// Tail-forwards to Engine.dll AActor::SetBase with the original registers and stack.
__declspec(naked) void AActorSetBaseImportThunk(void)
{
    __asm { jmp dword ptr [AActorSetBaseImport] }
}

// R6Engine.dll @ 10042462 : AActorNotifyBumpImportThunk
// Tail-forwards to Engine.dll AActor::NotifyBump with the original registers and stack.
__declspec(naked) void AActorNotifyBumpImportThunk(void)
{
    __asm { jmp dword ptr [AActorNotifyBumpImport] }
}

// R6Engine.dll @ 10042468 : AActorIsMovingBrushImportThunk
// Tail-forwards to Engine.dll AActor::IsMovingBrush with the original registers and stack.
__declspec(naked) void AActorIsMovingBrushImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsMovingBrushImport] }
}

// R6Engine.dll @ 1004246e : AActorBeginTouchImportThunk
// Tail-forwards to Engine.dll AActor::BeginTouch with the original registers and stack.
__declspec(naked) void AActorBeginTouchImportThunk(void)
{
    __asm { jmp dword ptr [AActorBeginTouchImport] }
}

// R6Engine.dll @ 10042474 : AActorGetPrimitiveImportThunk
// Tail-forwards to Engine.dll AActor::GetPrimitive with the original registers and stack.
__declspec(naked) void AActorGetPrimitiveImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetPrimitiveImport] }
}

// R6Engine.dll @ 1004247a : AActorShouldTraceImportThunk
// Tail-forwards to Engine.dll AActor::ShouldTrace with the original registers and stack.
__declspec(naked) void AActorShouldTraceImportThunk(void)
{
    __asm { jmp dword ptr [AActorShouldTraceImport] }
}

// R6Engine.dll @ 10042480 : AActorPostScriptDestroyedImportThunk
// Tail-forwards to Engine.dll AActor::PostScriptDestroyed with the original registers and stack.
__declspec(naked) void AActorPostScriptDestroyedImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostScriptDestroyedImport] }
}

// R6Engine.dll @ 10042486 : AActorUpdateColBoxImportThunk
// Tail-forwards to Engine.dll AActor::UpdateColBox with the original registers and stack.
__declspec(naked) void AActorUpdateColBoxImportThunk(void)
{
    __asm { jmp dword ptr [AActorUpdateColBoxImport] }
}

// R6Engine.dll @ 1004248c : AActorWorldToLocalImportThunk
// Tail-forwards to Engine.dll AActor::WorldToLocal with the original registers and stack.
__declspec(naked) void AActorWorldToLocalImportThunk(void)
{
    __asm { jmp dword ptr [AActorWorldToLocalImport] }
}

// R6Engine.dll @ 10042492 : AActorLocalToWorldImportThunk
// Tail-forwards to Engine.dll AActor::LocalToWorld with the original registers and stack.
__declspec(naked) void AActorLocalToWorldImportThunk(void)
{
    __asm { jmp dword ptr [AActorLocalToWorldImport] }
}

// R6Engine.dll @ 10042498 : AActorToWorldImportThunk
// Tail-forwards to Engine.dll AActor::ToWorld with the original registers and stack.
__declspec(naked) void AActorToWorldImportThunk(void)
{
    __asm { jmp dword ptr [AActorToWorldImport] }
}

// R6Engine.dll @ 100424a4 : AActorGetSkinImportThunk
// Tail-forwards to Engine.dll AActor::GetSkin with the original registers and stack.
__declspec(naked) void AActorGetSkinImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetSkinImport] }
}

// R6Engine.dll @ 100424aa : AActorPostNetReceiveLocationImportThunk
// Tail-forwards to Engine.dll AActor::PostNetReceiveLocation with the original registers and stack.
__declspec(naked) void AActorPostNetReceiveLocationImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostNetReceiveLocationImport] }
}

// R6Engine.dll @ 100424b0 : AGameReplicationInfoPostNetReceiveImportThunk
// Tail-forwards to Engine.dll AGameReplicationInfo::PostNetReceive with the original registers and stack.
__declspec(naked) void AGameReplicationInfoPostNetReceiveImportThunk(void)
{
    __asm { jmp dword ptr [AGameReplicationInfoPostNetReceiveImport] }
}

// R6Engine.dll @ 100424b6 : AActorPreNetReceiveImportThunk
// Tail-forwards to Engine.dll AActor::PreNetReceive with the original registers and stack.
__declspec(naked) void AActorPreNetReceiveImportThunk(void)
{
    __asm { jmp dword ptr [AActorPreNetReceiveImport] }
}

// R6Engine.dll @ 100424bc : AActorSpawnedImportThunk
// Tail-forwards to Engine.dll AActor::Spawned with the original registers and stack.
__declspec(naked) void AActorSpawnedImportThunk(void)
{
    __asm { jmp dword ptr [AActorSpawnedImport] }
}

// R6Engine.dll @ 100424c2 : AActorPostRaytraceImportThunk
// Tail-forwards to Engine.dll AActor::PostRaytrace with the original registers and stack.
__declspec(naked) void AActorPostRaytraceImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostRaytraceImport] }
}

// R6Engine.dll @ 100424c8 : AActorPreRaytraceImportThunk
// Tail-forwards to Engine.dll AActor::PreRaytrace with the original registers and stack.
__declspec(naked) void AActorPreRaytraceImportThunk(void)
{
    __asm { jmp dword ptr [AActorPreRaytraceImport] }
}

// R6Engine.dll @ 100424ce : AActorPostEditLoadImportThunk
// Tail-forwards to Engine.dll AActor::PostEditLoad with the original registers and stack.
__declspec(naked) void AActorPostEditLoadImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostEditLoadImport] }
}

// R6Engine.dll @ 100424d4 : AActorPostEditMoveImportThunk
// Tail-forwards to Engine.dll AActor::PostEditMove with the original registers and stack.
__declspec(naked) void AActorPostEditMoveImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostEditMoveImport] }
}

// R6Engine.dll @ 100424da : AActorTickImportThunk
// Tail-forwards to Engine.dll AActor::Tick with the original registers and stack.
__declspec(naked) void AActorTickImportThunk(void)
{
    __asm { jmp dword ptr [AActorTickImport] }
}

// R6Engine.dll @ 100424e0 : AActorWorldLightRadiusImportThunk
// Tail-forwards to Engine.dll AActor::WorldLightRadius with the original registers and stack.
__declspec(naked) void AActorWorldLightRadiusImportThunk(void)
{
    __asm { jmp dword ptr [AActorWorldLightRadiusImport] }
}

// R6Engine.dll @ 100424e6 : AActorGetNetPriorityImportThunk
// Tail-forwards to Engine.dll AActor::GetNetPriority with the original registers and stack.
__declspec(naked) void AActorGetNetPriorityImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetNetPriorityImport] }
}

// R6Engine.dll @ 100424ec : AActorIsBlockedByImportThunk
// Tail-forwards to Engine.dll AActor::IsBlockedBy with the original registers and stack.
__declspec(naked) void AActorIsBlockedByImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsBlockedByImport] }
}

// R6Engine.dll @ 100424f2 : AActorGetPawnOrColBoxOwnerImportThunk
// Tail-forwards to Engine.dll AActor::GetPawnOrColBoxOwner with the original registers and stack.
__declspec(naked) void AActorGetPawnOrColBoxOwnerImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetPawnOrColBoxOwnerImport] }
}

// R6Engine.dll @ 100424f8 : AActorGetPlayerPawnImportThunk
// Tail-forwards to Engine.dll AActor::GetPlayerPawn with the original registers and stack.
__declspec(naked) void AActorGetPlayerPawnImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetPlayerPawnImport] }
}

// R6Engine.dll @ 100424fe : AGameReplicationInfoGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll AGameReplicationInfo::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void AGameReplicationInfoGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [AGameReplicationInfoGetOptimizedRepListImport] }
}

// R6Engine.dll @ 10042504 : AActorNetDirtyImportThunk
// Tail-forwards to Engine.dll AActor::NetDirty with the original registers and stack.
__declspec(naked) void AActorNetDirtyImportThunk(void)
{
    __asm { jmp dword ptr [AActorNetDirtyImport] }
}

// R6Engine.dll @ 1004250a : AActorIsPendingDeleteImportThunk
// Tail-forwards to Engine.dll AActor::IsPendingDelete with the original registers and stack.
__declspec(naked) void AActorIsPendingDeleteImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsPendingDeleteImport] }
}

// R6Engine.dll @ 10042510 : AActorPostEditChangeImportThunk
// Tail-forwards to Engine.dll AActor::PostEditChange with the original registers and stack.
__declspec(naked) void AActorPostEditChangeImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostEditChangeImport] }
}

// R6Engine.dll @ 10042516 : AActorInitExecutionImportThunk
// Tail-forwards to Engine.dll AActor::InitExecution with the original registers and stack.
__declspec(naked) void AActorInitExecutionImportThunk(void)
{
    __asm { jmp dword ptr [AActorInitExecutionImport] }
}

// R6Engine.dll @ 1004251c : AActorIsPendingKillImportThunk
// Tail-forwards to Engine.dll AActor::IsPendingKill with the original registers and stack.
__declspec(naked) void AActorIsPendingKillImportThunk(void)
{
    __asm { jmp dword ptr [AActorIsPendingKillImport] }
}

// R6Engine.dll @ 10042522 : AActorSerializeImportThunk
// Tail-forwards to Engine.dll AActor::Serialize with the original registers and stack.
__declspec(naked) void AActorSerializeImportThunk(void)
{
    __asm { jmp dword ptr [AActorSerializeImport] }
}

// R6Engine.dll @ 10042528 : AActorDestroyImportThunk
// Tail-forwards to Engine.dll AActor::Destroy with the original registers and stack.
__declspec(naked) void AActorDestroyImportThunk(void)
{
    __asm { jmp dword ptr [AActorDestroyImport] }
}

// R6Engine.dll @ 1004252e : AActorPostLoadImportThunk
// Tail-forwards to Engine.dll AActor::PostLoad with the original registers and stack.
__declspec(naked) void AActorPostLoadImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostLoadImport] }
}

// R6Engine.dll @ 10042534 : AActorProcessRemoteFunctionImportThunk
// Tail-forwards to Engine.dll AActor::ProcessRemoteFunction with the original registers and stack.
__declspec(naked) void AActorProcessRemoteFunctionImportThunk(void)
{
    __asm { jmp dword ptr [AActorProcessRemoteFunctionImport] }
}

// R6Engine.dll @ 1004253a : AActorProcessStateImportThunk
// Tail-forwards to Engine.dll AActor::ProcessState with the original registers and stack.
__declspec(naked) void AActorProcessStateImportThunk(void)
{
    __asm { jmp dword ptr [AActorProcessStateImport] }
}

// R6Engine.dll @ 10042546 : APawnCheckForErrorsImportThunk
// Tail-forwards to Engine.dll APawn::CheckForErrors with the original registers and stack.
__declspec(naked) void APawnCheckForErrorsImportThunk(void)
{
    __asm { jmp dword ptr [APawnCheckForErrorsImport] }
}

// R6Engine.dll @ 1004254c : APawnStepUpImportThunk
// Tail-forwards to Engine.dll APawn::stepUp with the original registers and stack.
__declspec(naked) void APawnStepUpImportThunk(void)
{
    __asm { jmp dword ptr [APawnStepUpImport] }
}

// R6Engine.dll @ 10042552 : APawnSmoothHitWallImportThunk
// Tail-forwards to Engine.dll APawn::SmoothHitWall with the original registers and stack.
__declspec(naked) void APawnSmoothHitWallImportThunk(void)
{
    __asm { jmp dword ptr [APawnSmoothHitWallImport] }
}

// R6Engine.dll @ 1004255e : APawnPhysFallingImportThunk
// Tail-forwards to Engine.dll APawn::physFalling with the original registers and stack.
__declspec(naked) void APawnPhysFallingImportThunk(void)
{
    __asm { jmp dword ptr [APawnPhysFallingImport] }
}

// R6Engine.dll @ 10042564 : APawnProcessLandedImportThunk
// Tail-forwards to Engine.dll APawn::processLanded with the original registers and stack.
__declspec(naked) void APawnProcessLandedImportThunk(void)
{
    __asm { jmp dword ptr [APawnProcessLandedImport] }
}

// R6Engine.dll @ 1004256a : APawnProcessHitWallImportThunk
// Tail-forwards to Engine.dll APawn::processHitWall with the original registers and stack.
__declspec(naked) void APawnProcessHitWallImportThunk(void)
{
    __asm { jmp dword ptr [APawnProcessHitWallImport] }
}

// R6Engine.dll @ 10042570 : APawnPostBeginPlayImportThunk
// Tail-forwards to Engine.dll APawn::PostBeginPlay with the original registers and stack.
__declspec(naked) void APawnPostBeginPlayImportThunk(void)
{
    __asm { jmp dword ptr [APawnPostBeginPlayImport] }
}

// R6Engine.dll @ 10042576 : APawnSetZoneImportThunk
// Tail-forwards to Engine.dll APawn::SetZone with the original registers and stack.
__declspec(naked) void APawnSetZoneImportThunk(void)
{
    __asm { jmp dword ptr [APawnSetZoneImport] }
}

// R6Engine.dll @ 1004257c : APawnRenderEditorSelectedImportThunk
// Tail-forwards to Engine.dll APawn::RenderEditorSelected with the original registers and stack.
__declspec(naked) void APawnRenderEditorSelectedImportThunk(void)
{
    __asm { jmp dword ptr [APawnRenderEditorSelectedImport] }
}

// R6Engine.dll @ 10042582 : APawnIsNetRelevantForImportThunk
// Tail-forwards to Engine.dll APawn::IsNetRelevantFor with the original registers and stack.
__declspec(naked) void APawnIsNetRelevantForImportThunk(void)
{
    __asm { jmp dword ptr [APawnIsNetRelevantForImport] }
}

// R6Engine.dll @ 10042588 : APawnPlayerControlledImportThunk
// Tail-forwards to Engine.dll APawn::PlayerControlled with the original registers and stack.
__declspec(naked) void APawnPlayerControlledImportThunk(void)
{
    __asm { jmp dword ptr [APawnPlayerControlledImport] }
}

// R6Engine.dll @ 1004258e : APawnTickSimulatedImportThunk
// Tail-forwards to Engine.dll APawn::TickSimulated with the original registers and stack.
__declspec(naked) void APawnTickSimulatedImportThunk(void)
{
    __asm { jmp dword ptr [APawnTickSimulatedImport] }
}

// R6Engine.dll @ 10042594 : APawnCheckOwnerUpdatedImportThunk
// Tail-forwards to Engine.dll APawn::CheckOwnerUpdated with the original registers and stack.
__declspec(naked) void APawnCheckOwnerUpdatedImportThunk(void)
{
    __asm { jmp dword ptr [APawnCheckOwnerUpdatedImport] }
}

// R6Engine.dll @ 1004259a : APawnNotifyAnimEndImportThunk
// Tail-forwards to Engine.dll APawn::NotifyAnimEnd with the original registers and stack.
__declspec(naked) void APawnNotifyAnimEndImportThunk(void)
{
    __asm { jmp dword ptr [APawnNotifyAnimEndImport] }
}

// R6Engine.dll @ 100425a0 : APawnSetBaseImportThunk
// Tail-forwards to Engine.dll APawn::SetBase with the original registers and stack.
__declspec(naked) void APawnSetBaseImportThunk(void)
{
    __asm { jmp dword ptr [APawnSetBaseImport] }
}

// R6Engine.dll @ 100425a6 : APawnNotifyBumpImportThunk
// Tail-forwards to Engine.dll APawn::NotifyBump with the original registers and stack.
__declspec(naked) void APawnNotifyBumpImportThunk(void)
{
    __asm { jmp dword ptr [APawnNotifyBumpImport] }
}

// R6Engine.dll @ 100425ac : APawnShouldTraceImportThunk
// Tail-forwards to Engine.dll APawn::ShouldTrace with the original registers and stack.
__declspec(naked) void APawnShouldTraceImportThunk(void)
{
    __asm { jmp dword ptr [APawnShouldTraceImport] }
}

// R6Engine.dll @ 100425b2 : APawnPostNetReceiveLocationImportThunk
// Tail-forwards to Engine.dll APawn::PostNetReceiveLocation with the original registers and stack.
__declspec(naked) void APawnPostNetReceiveLocationImportThunk(void)
{
    __asm { jmp dword ptr [APawnPostNetReceiveLocationImport] }
}

// R6Engine.dll @ 100425b8 : APawnGetNetPriorityImportThunk
// Tail-forwards to Engine.dll APawn::GetNetPriority with the original registers and stack.
__declspec(naked) void APawnGetNetPriorityImportThunk(void)
{
    __asm { jmp dword ptr [APawnGetNetPriorityImport] }
}

// R6Engine.dll @ 100425be : APawnIsBlockedByImportThunk
// Tail-forwards to Engine.dll APawn::IsBlockedBy with the original registers and stack.
__declspec(naked) void APawnIsBlockedByImportThunk(void)
{
    __asm { jmp dword ptr [APawnIsBlockedByImport] }
}

// R6Engine.dll @ 100425c4 : APawnGetPawnOrColBoxOwnerImportThunk
// Tail-forwards to Engine.dll APawn::GetPawnOrColBoxOwner with the original registers and stack.
__declspec(naked) void APawnGetPawnOrColBoxOwnerImportThunk(void)
{
    __asm { jmp dword ptr [APawnGetPawnOrColBoxOwnerImport] }
}

// R6Engine.dll @ 100425d0 : APawnGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll APawn::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void APawnGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [APawnGetOptimizedRepListImport] }
}

// R6Engine.dll @ 100425d6 : APawnDestroyImportThunk
// Tail-forwards to Engine.dll APawn::Destroy with the original registers and stack.
__declspec(naked) void APawnDestroyImportThunk(void)
{
    __asm { jmp dword ptr [APawnDestroyImport] }
}

// R6Engine.dll @ 100425dc : ANavigationPointCheckSymmetryImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::CheckSymmetry with the original registers and stack.
__declspec(naked) void ANavigationPointCheckSymmetryImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointCheckSymmetryImport] }
}

// R6Engine.dll @ 100425e2 : ANavigationPointReviewPathImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::ReviewPath with the original registers and stack.
__declspec(naked) void ANavigationPointReviewPathImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointReviewPathImport] }
}

// R6Engine.dll @ 100425e8 : ANavigationPointIsIdentifiedAsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::IsIdentifiedAs with the original registers and stack.
__declspec(naked) void ANavigationPointIsIdentifiedAsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointIsIdentifiedAsImport] }
}

// R6Engine.dll @ 100425ee : ANavigationPointPrunePathsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::PrunePaths with the original registers and stack.
__declspec(naked) void ANavigationPointPrunePathsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointPrunePathsImport] }
}

// R6Engine.dll @ 100425f4 : ANavigationPointFindBaseImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::FindBase with the original registers and stack.
__declspec(naked) void ANavigationPointFindBaseImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointFindBaseImport] }
}

// R6Engine.dll @ 100425fa : ALadderClearPathsImportThunk
// Tail-forwards to Engine.dll ALadder::ClearPaths with the original registers and stack.
__declspec(naked) void ALadderClearPathsImportThunk(void)
{
    __asm { jmp dword ptr [ALadderClearPathsImport] }
}

// R6Engine.dll @ 10042600 : ANavigationPointSetupForcedPathImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::SetupForcedPath with the original registers and stack.
__declspec(naked) void ANavigationPointSetupForcedPathImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointSetupForcedPathImport] }
}

// R6Engine.dll @ 10042606 : ALadderInitForPathFindingImportThunk
// Tail-forwards to Engine.dll ALadder::InitForPathFinding with the original registers and stack.
__declspec(naked) void ALadderInitForPathFindingImportThunk(void)
{
    __asm { jmp dword ptr [ALadderInitForPathFindingImport] }
}

// R6Engine.dll @ 1004260c : ANavigationPointPostaddReachSpecsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::PostaddReachSpecs with the original registers and stack.
__declspec(naked) void ANavigationPointPostaddReachSpecsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointPostaddReachSpecsImport] }
}

// R6Engine.dll @ 10042612 : ALadderAddReachSpecsImportThunk
// Tail-forwards to Engine.dll ALadder::addReachSpecs with the original registers and stack.
__declspec(naked) void ALadderAddReachSpecsImportThunk(void)
{
    __asm { jmp dword ptr [ALadderAddReachSpecsImport] }
}

// R6Engine.dll @ 10042618 : ALadderProscribedPathToImportThunk
// Tail-forwards to Engine.dll ALadder::ProscribedPathTo with the original registers and stack.
__declspec(naked) void ALadderProscribedPathToImportThunk(void)
{
    __asm { jmp dword ptr [ALadderProscribedPathToImport] }
}

// R6Engine.dll @ 1004261e : ANavigationPointCheckForErrorsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::CheckForErrors with the original registers and stack.
__declspec(naked) void ANavigationPointCheckForErrorsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointCheckForErrorsImport] }
}

// R6Engine.dll @ 10042624 : ANavigationPointSetVolumesFromListImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::SetVolumes with the original registers and stack.
__declspec(naked) void ANavigationPointSetVolumesFromListImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointSetVolumesFromListImport] }
}

// R6Engine.dll @ 1004262a : AActorPostNetReceiveImportThunk
// Tail-forwards to Engine.dll AActor::PostNetReceive with the original registers and stack.
__declspec(naked) void AActorPostNetReceiveImportThunk(void)
{
    __asm { jmp dword ptr [AActorPostNetReceiveImport] }
}

// R6Engine.dll @ 10042630 : ANavigationPointSpawnedImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::Spawned with the original registers and stack.
__declspec(naked) void ANavigationPointSpawnedImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointSpawnedImport] }
}

// R6Engine.dll @ 10042636 : ANavigationPointPostEditMoveImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::PostEditMove with the original registers and stack.
__declspec(naked) void ANavigationPointPostEditMoveImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointPostEditMoveImport] }
}

// R6Engine.dll @ 1004263c : AActorGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll AActor::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void AActorGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [AActorGetOptimizedRepListImport] }
}

// R6Engine.dll @ 10042642 : ANavigationPointDestroyImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::Destroy with the original registers and stack.
__declspec(naked) void ANavigationPointDestroyImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointDestroyImport] }
}

// R6Engine.dll @ 10042648 : ANavigationPointClearPathsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::ClearPaths with the original registers and stack.
__declspec(naked) void ANavigationPointClearPathsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointClearPathsImport] }
}

// R6Engine.dll @ 1004264e : ANavigationPointInitForPathFindingImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::InitForPathFinding with the original registers and stack.
__declspec(naked) void ANavigationPointInitForPathFindingImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointInitForPathFindingImport] }
}

// R6Engine.dll @ 10042654 : ANavigationPointAddReachSpecsImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::addReachSpecs with the original registers and stack.
__declspec(naked) void ANavigationPointAddReachSpecsImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointAddReachSpecsImport] }
}

// R6Engine.dll @ 1004265a : ANavigationPointProscribedPathToImportThunk
// Tail-forwards to Engine.dll ANavigationPoint::ProscribedPathTo with the original registers and stack.
__declspec(naked) void ANavigationPointProscribedPathToImportThunk(void)
{
    __asm { jmp dword ptr [ANavigationPointProscribedPathToImport] }
}

// R6Engine.dll @ 10042660 : ABrushInitPosRotScaleImportThunk
// Tail-forwards to Engine.dll ABrush::InitPosRotScale with the original registers and stack.
__declspec(naked) void ABrushInitPosRotScaleImportThunk(void)
{
    __asm { jmp dword ptr [ABrushInitPosRotScaleImport] }
}

// R6Engine.dll @ 10042666 : ABrushCopyPosRotScaleFromImportThunk
// Tail-forwards to Engine.dll ABrush::CopyPosRotScaleFrom with the original registers and stack.
__declspec(naked) void ABrushCopyPosRotScaleFromImportThunk(void)
{
    __asm { jmp dword ptr [ABrushCopyPosRotScaleFromImport] }
}

// R6Engine.dll @ 1004266c : ABrushCheckForErrorsImportThunk
// Tail-forwards to Engine.dll ABrush::CheckForErrors with the original registers and stack.
__declspec(naked) void ABrushCheckForErrorsImportThunk(void)
{
    __asm { jmp dword ptr [ABrushCheckForErrorsImport] }
}

// R6Engine.dll @ 10042672 : AVolumePostBeginPlayImportThunk
// Tail-forwards to Engine.dll AVolume::PostBeginPlay with the original registers and stack.
__declspec(naked) void AVolumePostBeginPlayImportThunk(void)
{
    __asm { jmp dword ptr [AVolumePostBeginPlayImport] }
}

// R6Engine.dll @ 10042678 : AVolumeSetVolumesImportThunk
// Tail-forwards to Engine.dll AVolume::SetVolumes with the original registers and stack.
__declspec(naked) void AVolumeSetVolumesImportThunk(void)
{
    __asm { jmp dword ptr [AVolumeSetVolumesImport] }
}

// R6Engine.dll @ 1004267e : AVolumeSetVolumesFromListImportThunk
// Tail-forwards to Engine.dll AVolume::SetVolumes with the original registers and stack.
__declspec(naked) void AVolumeSetVolumesFromListImportThunk(void)
{
    __asm { jmp dword ptr [AVolumeSetVolumesFromListImport] }
}

// R6Engine.dll @ 10042684 : APhysicsVolumeSetZoneImportThunk
// Tail-forwards to Engine.dll APhysicsVolume::SetZone with the original registers and stack.
__declspec(naked) void APhysicsVolumeSetZoneImportThunk(void)
{
    __asm { jmp dword ptr [APhysicsVolumeSetZoneImport] }
}

// R6Engine.dll @ 1004268a : ALadderVolumeRenderEditorInfoImportThunk
// Tail-forwards to Engine.dll ALadderVolume::RenderEditorInfo with the original registers and stack.
__declspec(naked) void ALadderVolumeRenderEditorInfoImportThunk(void)
{
    __asm { jmp dword ptr [ALadderVolumeRenderEditorInfoImport] }
}

// R6Engine.dll @ 10042690 : ABrushGetPrimitiveImportThunk
// Tail-forwards to Engine.dll ABrush::GetPrimitive with the original registers and stack.
__declspec(naked) void ABrushGetPrimitiveImportThunk(void)
{
    __asm { jmp dword ptr [ABrushGetPrimitiveImport] }
}

// R6Engine.dll @ 10042696 : ABrushToWorldImportThunk
// Tail-forwards to Engine.dll ABrush::ToWorld with the original registers and stack.
__declspec(naked) void ABrushToWorldImportThunk(void)
{
    __asm { jmp dword ptr [ABrushToWorldImport] }
}

// R6Engine.dll @ 1004269c : ABrushToLocalImportThunk
// Tail-forwards to Engine.dll ABrush::ToLocal with the original registers and stack.
__declspec(naked) void ABrushToLocalImportThunk(void)
{
    __asm { jmp dword ptr [ABrushToLocalImport] }
}

// R6Engine.dll @ 100426a2 : APhysicsVolumeGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll APhysicsVolume::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void APhysicsVolumeGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [APhysicsVolumeGetOptimizedRepListImport] }
}

// R6Engine.dll @ 100426a8 : ABrushPostEditChangeImportThunk
// Tail-forwards to Engine.dll ABrush::PostEditChange with the original registers and stack.
__declspec(naked) void ABrushPostEditChangeImportThunk(void)
{
    __asm { jmp dword ptr [ABrushPostEditChangeImport] }
}

// R6Engine.dll @ 100426ae : ABrushPostLoadImportThunk
// Tail-forwards to Engine.dll ABrush::PostLoad with the original registers and stack.
__declspec(naked) void ABrushPostLoadImportThunk(void)
{
    __asm { jmp dword ptr [ABrushPostLoadImport] }
}

// R6Engine.dll @ 100426b4 : AVolumeShouldTraceImportThunk
// Tail-forwards to Engine.dll AVolume::ShouldTrace with the original registers and stack.
__declspec(naked) void AVolumeShouldTraceImportThunk(void)
{
    __asm { jmp dword ptr [AVolumeShouldTraceImport] }
}

// R6Engine.dll @ 100426ba : AControllerGetTeamManagerImportThunk
// Tail-forwards to Engine.dll AController::GetTeamManager with the original registers and stack.
__declspec(naked) void AControllerGetTeamManagerImportThunk(void)
{
    __asm { jmp dword ptr [AControllerGetTeamManagerImport] }
}

// R6Engine.dll @ 100426c0 : AControllerLocalPlayerControllerImportThunk
// Tail-forwards to Engine.dll AController::LocalPlayerController with the original registers and stack.
__declspec(naked) void AControllerLocalPlayerControllerImportThunk(void)
{
    __asm { jmp dword ptr [AControllerLocalPlayerControllerImport] }
}

// R6Engine.dll @ 100426c6 : AAIControllerSetAdjustLocationImportThunk
// Tail-forwards to Engine.dll AAIController::SetAdjustLocation with the original registers and stack.
__declspec(naked) void AAIControllerSetAdjustLocationImportThunk(void)
{
    __asm { jmp dword ptr [AAIControllerSetAdjustLocationImport] }
}

// R6Engine.dll @ 100426cc : AAIControllerAcceptNearbyPathImportThunk
// Tail-forwards to Engine.dll AAIController::AcceptNearbyPath with the original registers and stack.
__declspec(naked) void AAIControllerAcceptNearbyPathImportThunk(void)
{
    __asm { jmp dword ptr [AAIControllerAcceptNearbyPathImport] }
}

// R6Engine.dll @ 100426d2 : AControllerGetViewTargetImportThunk
// Tail-forwards to Engine.dll AController::GetViewTarget with the original registers and stack.
__declspec(naked) void AControllerGetViewTargetImportThunk(void)
{
    __asm { jmp dword ptr [AControllerGetViewTargetImport] }
}

// R6Engine.dll @ 100426d8 : AControllerCheckHearSoundImportThunk
// Tail-forwards to Engine.dll AController::CheckHearSound with the original registers and stack.
__declspec(naked) void AControllerCheckHearSoundImportThunk(void)
{
    __asm { jmp dword ptr [AControllerCheckHearSoundImport] }
}

// R6Engine.dll @ 100426de : AControllerCheckAnimFinishedImportThunk
// Tail-forwards to Engine.dll AController::CheckAnimFinished with the original registers and stack.
__declspec(naked) void AControllerCheckAnimFinishedImportThunk(void)
{
    __asm { jmp dword ptr [AControllerCheckAnimFinishedImport] }
}

// R6Engine.dll @ 100426e4 : AControllerStartAnimPollImportThunk
// Tail-forwards to Engine.dll AController::StartAnimPoll with the original registers and stack.
__declspec(naked) void AControllerStartAnimPollImportThunk(void)
{
    __asm { jmp dword ptr [AControllerStartAnimPollImport] }
}

// R6Engine.dll @ 100426ea : AControllerTickImportThunk
// Tail-forwards to Engine.dll AController::Tick with the original registers and stack.
__declspec(naked) void AControllerTickImportThunk(void)
{
    __asm { jmp dword ptr [AControllerTickImport] }
}

// R6Engine.dll @ 100426f0 : AControllerGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll AController::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void AControllerGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [AControllerGetOptimizedRepListImport] }
}

// R6Engine.dll @ 100426f6 : UMatSubActionPreBeginPreviewImportThunk
// Tail-forwards to Engine.dll UMatSubAction::PreBeginPreview with the original registers and stack.
__declspec(naked) void UMatSubActionPreBeginPreviewImportThunk(void)
{
    __asm { jmp dword ptr [UMatSubActionPreBeginPreviewImport] }
}

// R6Engine.dll @ 100426fc : UMatSubActionInitializeImportThunk
// Tail-forwards to Engine.dll UMatSubAction::Initialize with the original registers and stack.
__declspec(naked) void UMatSubActionInitializeImportThunk(void)
{
    __asm { jmp dword ptr [UMatSubActionInitializeImport] }
}

// R6Engine.dll @ 10042702 : UMatSubActionIsEndingImportThunk
// Tail-forwards to Engine.dll UMatSubAction::IsEnding with the original registers and stack.
__declspec(naked) void UMatSubActionIsEndingImportThunk(void)
{
    __asm { jmp dword ptr [UMatSubActionIsEndingImport] }
}

// R6Engine.dll @ 1004270e : UMatSubActionPostEditChangeImportThunk
// Tail-forwards to Engine.dll UMatSubAction::PostEditChange with the original registers and stack.
__declspec(naked) void UMatSubActionPostEditChangeImportThunk(void)
{
    __asm { jmp dword ptr [UMatSubActionPostEditChangeImport] }
}

// R6Engine.dll @ 1004271a : AControllerSetAdjustLocationImportThunk
// Tail-forwards to Engine.dll AController::SetAdjustLocation with the original registers and stack.
__declspec(naked) void AControllerSetAdjustLocationImportThunk(void)
{
    __asm { jmp dword ptr [AControllerSetAdjustLocationImport] }
}

// R6Engine.dll @ 10042720 : AControllerAdjustFromWallImportThunk
// Tail-forwards to Engine.dll AController::AdjustFromWall with the original registers and stack.
__declspec(naked) void AControllerAdjustFromWallImportThunk(void)
{
    __asm { jmp dword ptr [AControllerAdjustFromWallImport] }
}

// R6Engine.dll @ 10042726 : AControllerAcceptNearbyPathImportThunk
// Tail-forwards to Engine.dll AController::AcceptNearbyPath with the original registers and stack.
__declspec(naked) void AControllerAcceptNearbyPathImportThunk(void)
{
    __asm { jmp dword ptr [AControllerAcceptNearbyPathImport] }
}

// R6Engine.dll @ 1004272c : APlayerControllerGetViewTargetImportThunk
// Tail-forwards to Engine.dll APlayerController::GetViewTarget with the original registers and stack.
__declspec(naked) void APlayerControllerGetViewTargetImportThunk(void)
{
    __asm { jmp dword ptr [APlayerControllerGetViewTargetImport] }
}

// R6Engine.dll @ 10042732 : APlayerControllerCheckHearSoundImportThunk
// Tail-forwards to Engine.dll APlayerController::CheckHearSound with the original registers and stack.
__declspec(naked) void APlayerControllerCheckHearSoundImportThunk(void)
{
    __asm { jmp dword ptr [APlayerControllerCheckHearSoundImport] }
}

// R6Engine.dll @ 10042738 : AControllerCanHearImportThunk
// Tail-forwards to Engine.dll AController::CanHear with the original registers and stack.
__declspec(naked) void AControllerCanHearImportThunk(void)
{
    __asm { jmp dword ptr [AControllerCanHearImport] }
}

// R6Engine.dll @ 1004273e : APlayerControllerIsNetRelevantForImportThunk
// Tail-forwards to Engine.dll APlayerController::IsNetRelevantFor with the original registers and stack.
__declspec(naked) void APlayerControllerIsNetRelevantForImportThunk(void)
{
    __asm { jmp dword ptr [APlayerControllerIsNetRelevantForImport] }
}

// R6Engine.dll @ 10042744 : APlayerControllerGetOptimizedRepListImportThunk
// Tail-forwards to Engine.dll APlayerController::GetOptimizedRepList with the original registers and stack.
__declspec(naked) void APlayerControllerGetOptimizedRepListImportThunk(void)
{
    __asm { jmp dword ptr [APlayerControllerGetOptimizedRepListImport] }
}
