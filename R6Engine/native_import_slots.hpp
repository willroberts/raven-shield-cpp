#pragma once

// Mutable PE32 import cells. Known class-data entries hold UClass*; other entries retain raw address words.
// The selected target uses four-byte pointers; provider function prototypes are described at individual uses.
class UClass;

// R6Engine.dll data @ 10049000 : FVectorNormalizeImport
extern uint FVectorNormalizeImport;

// R6Engine.dll data @ 10049004 : CoreAppUnwindfImport
extern uint CoreAppUnwindfImport;

// R6Engine.dll data @ 10049008 : CoreGMallocImport
extern uint CoreGMallocImport;

// R6Engine.dll data @ 1004900c : FVectorSizeImport
extern uint FVectorSizeImport;

// R6Engine.dll data @ 10049010 : CoreGNativesImport
extern uint CoreGNativesImport;

// R6Engine.dll data @ 10049014 : FOutputDeviceLogfWithNameImport
extern uint FOutputDeviceLogfWithNameImport;

// R6Engine.dll data @ 10049018 : CoreGLogImport
extern uint CoreGLogImport;

// R6Engine.dll data @ 1004901c : UObjectGetNameImport
extern uint UObjectGetNameImport;

// R6Engine.dll data @ 10049020 : FStateFrameDescribeImport
extern uint FStateFrameDescribeImport;

// R6Engine.dll data @ 10049024 : FArrayRemoveImport
extern uint FArrayRemoveImport;

// R6Engine.dll data @ 10049028 : CoreAppFailAssertImport
extern uint CoreAppFailAssertImport;

// R6Engine.dll data @ 1004902c : FStringNoInitCopyConstructorImport
extern uint FStringNoInitCopyConstructorImport;

// R6Engine.dll data @ 10049030 : FStringNoInitAssignNoInitStringImport
extern uint FStringNoInitAssignNoInitStringImport;

// R6Engine.dll data @ 10049034 : FArrayReallocImport
extern uint FArrayReallocImport;

// R6Engine.dll data @ 10049038 : FStringNoInitDestructorImport
extern uint FStringNoInitDestructorImport;

// R6Engine.dll data @ 1004903c : FArrayAddImport
extern uint FArrayAddImport;

// R6Engine.dll data @ 10049040 : UObjectFindFunctionCheckedImport
extern uint UObjectFindFunctionCheckedImport;

// R6Engine.dll data @ 10049044 : UObjectStaticAllocateObjectImport
extern uint UObjectStaticAllocateObjectImport;

// R6Engine.dll data @ 10049048 : CoreGErrorImport
extern uint CoreGErrorImport;

// R6Engine.dll data @ 1004904c : UObjectGetPropertiesSizeImport
extern uint UObjectGetPropertiesSizeImport;

// R6Engine.dll data @ 10049050 : UObjectLanguageChangeImport
extern uint UObjectLanguageChangeImport;

// R6Engine.dll data @ 10049054 : UObjectRegisterImport
extern uint UObjectRegisterImport;

// R6Engine.dll data @ 10049058 : UObjectScriptConsoleExecImport
extern uint UObjectScriptConsoleExecImport;

// R6Engine.dll data @ 1004905c : UObjectCallFunctionImport
extern uint UObjectCallFunctionImport;

// R6Engine.dll data @ 10049060 : UObjectShutdownAfterErrorImport
extern uint UObjectShutdownAfterErrorImport;

// R6Engine.dll data @ 10049064 : UObjectGotoLabelImport
extern uint UObjectGotoLabelImport;

// R6Engine.dll data @ 10049068 : UObjectGotoStateImport
extern uint UObjectGotoStateImport;

// R6Engine.dll data @ 1004906c : UObjectModifyImport
extern uint UObjectModifyImport;

// R6Engine.dll data @ 10049070 : UObjectProcessDelegateImport
extern uint UObjectProcessDelegateImport;

// R6Engine.dll data @ 10049074 : UObjectReleaseImport
extern uint UObjectReleaseImport;

// R6Engine.dll data @ 10049078 : UObjectAddRefImport
extern uint UObjectAddRefImport;

// R6Engine.dll data @ 1004907c : UObjectQueryInterfaceImport
extern uint UObjectQueryInterfaceImport;

// R6Engine.dll data @ 10049080 : UObjectConditionalDestroyImport
extern uint UObjectConditionalDestroyImport;

// R6Engine.dll data @ 10049084 : FStringNoInitDefaultConstructorImport
extern uint FStringNoInitDefaultConstructorImport;

// R6Engine.dll data @ 10049088 : UObjectDeallocateImport
extern uint UObjectDeallocateImport;

// R6Engine.dll data @ 1004908c : FStringDefaultConstructorImport
extern uint FStringDefaultConstructorImport;

// R6Engine.dll data @ 10049090 : FStringDestructorImport
extern uint FStringDestructorImport;

// R6Engine.dll data @ 10049094 : FStringCopyConstructorImport
extern uint FStringCopyConstructorImport;

// R6Engine.dll data @ 10049098 : FStringAssignStringImport
extern uint FStringAssignStringImport;

// R6Engine.dll data @ 1004909c : FVectorDefaultConstructorImport
extern uint FVectorDefaultConstructorImport;

// R6Engine.dll data @ 100490a0 : UObjectNetDirtyImport
extern uint UObjectNetDirtyImport;

// R6Engine.dll data @ 100490a4 : UObjectIsPendingDeleteImport
extern uint UObjectIsPendingDeleteImport;

// R6Engine.dll data @ 100490a8 : UObjectInitExecutionImport
extern uint UObjectInitExecutionImport;

// R6Engine.dll data @ 100490ac : UObjectIsPendingKillImport
extern uint UObjectIsPendingKillImport;

// R6Engine.dll data @ 100490b0 : UObjectSerializeImport
extern uint UObjectSerializeImport;

// R6Engine.dll data @ 100490b4 : UObjectDestroyImport
extern uint UObjectDestroyImport;

// R6Engine.dll data @ 100490b8 : UObjectPostLoadImport
extern uint UObjectPostLoadImport;

// R6Engine.dll data @ 100490bc : UObjectProcessRemoteFunctionImport
extern uint UObjectProcessRemoteFunctionImport;

// R6Engine.dll data @ 100490c0 : UObjectProcessStateImport
extern uint UObjectProcessStateImport;

// R6Engine.dll data @ 100490c4 : UObjectProcessEventImport
extern uint UObjectProcessEventImport;

// R6Engine.dll data @ 100490c8 : UObjectPostEditChangeImport
extern uint UObjectPostEditChangeImport;

// R6Engine.dll data @ 100490cc : UObjectDestructorImport
extern uint UObjectDestructorImport;

// R6Engine.dll data @ 100490d0 : UObjectDefaultConstructorImport
extern uint UObjectDefaultConstructorImport;

// R6Engine.dll data @ 100490d4 : UObjectCopyConstructorImport
extern uint UObjectCopyConstructorImport;

// R6Engine.dll data @ 100490d8 : UObjectAssignImport
extern uint UObjectAssignImport;

// R6Engine.dll data @ 100490dc : FVectorFVector0Import
extern uint FVectorFVector0Import;

// R6Engine.dll data @ 100490e0 : FVectorRotationImport
extern uint FVectorRotationImport;

// R6Engine.dll data @ 100490e4 : FRotatorVectorImport
extern uint FRotatorVectorImport;

// R6Engine.dll data @ 100490e8 : FOutputDeviceLogfImport
extern uint FOutputDeviceLogfImport;

// R6Engine.dll data @ 100490ec : FNameDereferenceImport
extern uint FNameDereferenceImport;

// R6Engine.dll data @ 100490f0 : CoreAppSinImport
extern uint CoreAppSinImport;

// R6Engine.dll data @ 100490f4 : CoreAppCosImport
extern uint CoreAppCosImport;

// R6Engine.dll data @ 100490f8 : CoreAppAtanImport
extern uint CoreAppAtanImport;

// R6Engine.dll data @ 100490fc : CoreAppSqrtImport
extern uint CoreAppSqrtImport;

// R6Engine.dll data @ 10049100 : FNameConstructorImport
extern uint FNameConstructorImport;

// R6Engine.dll data @ 10049104 : CoreGPropertyImport
extern uint CoreGPropertyImport;

// R6Engine.dll data @ 10049108 : CoreGPropObjectImport
extern uint CoreGPropObjectImport;

// R6Engine.dll data @ 1004910c : CoreGPropAddrImport
extern uint CoreGPropAddrImport;

// R6Engine.dll data @ 10049110 : FArrayDestructorImport
extern uint FArrayDestructorImport;

// R6Engine.dll data @ 10049114 : FVectorOperatorImport
extern uint FVectorOperatorImport;

// R6Engine.dll data @ 10049118 : UObjectIsAImport
extern uint UObjectIsAImport;

// R6Engine.dll data @ 1004911c : CoreGRegisterNativeImport
extern uint CoreGRegisterNativeImport;

// R6Engine.dll data @ 10049120 : CoreGWarnImport
extern uint CoreGWarnImport;

// R6Engine.dll data @ 10049124 : UObjectStaticFindObjectCheckedImport
extern uint UObjectStaticFindObjectCheckedImport;

// R6Engine.dll data @ 10049128 : UClassPrivateStaticClassImport
extern UClass* UClassPrivateStaticClassImport;

// R6Engine.dll data @ 1004912c : UClassGetDefaultActorImport
extern uint UClassGetDefaultActorImport;

// R6Engine.dll data @ 10049130 : FStringConstructorImport
extern uint FStringConstructorImport;

// R6Engine.dll data @ 10049134 : CoreAppMsgfImport
extern uint CoreAppMsgfImport;

// R6Engine.dll data @ 10049138 : FStringDereferenceImport
extern uint FStringDereferenceImport;

// R6Engine.dll data @ 1004913c : FStringPrintfImport
extern uint FStringPrintfImport;

// R6Engine.dll data @ 10049140 : CoreAppRandImport
extern uint CoreAppRandImport;

// R6Engine.dll data @ 10049144 : UObjectStaticLoadObjectImport
extern uint UObjectStaticLoadObjectImport;

// R6Engine.dll data @ 10049148 : FVectorGetNormalizedImport
extern uint FVectorGetNormalizedImport;

// R6Engine.dll data @ 1004914c : FStringNoInitAssignStringImport
extern uint FStringNoInitAssignStringImport;

// R6Engine.dll data @ 10049150 : CoreAppFrandImport
extern uint CoreAppFrandImport;

// R6Engine.dll data @ 10049154 : FStringEqualImport
extern uint FStringEqualImport;

// R6Engine.dll data @ 10049158 : UClassConstructorImport
extern uint UClassConstructorImport;

// R6Engine.dll data @ 1004915c : UObjectStaticConfigNameImport
extern uint UObjectStaticConfigNameImport;

// R6Engine.dll data @ 10049160 : UObjectPrivateStaticClassImport
extern UClass* UObjectPrivateStaticClassImport;

// R6Engine.dll data @ 10049164 : UObjectStaticConstructorImport
extern uint UObjectStaticConstructorImport;

// R6Engine.dll data @ 10049168 : UClassDestructorImport
extern uint UClassDestructorImport;

// R6Engine.dll data @ 1004916c : UObjectGetFullNameImport
extern uint UObjectGetFullNameImport;

// R6Engine.dll data @ 10049170 : FArrayAddZeroedImport
extern uint FArrayAddZeroedImport;

// R6Engine.dll data @ 10049174 : FStringNotEqualTextImport
extern uint FStringNotEqualTextImport;

// R6Engine.dll data @ 10049178 : FVectorTransformVectorByTransposeImport
extern uint FVectorTransformVectorByTransposeImport;

// R6Engine.dll data @ 1004917c : FCoordsDivideImport
extern uint FCoordsDivideImport;

// R6Engine.dll data @ 10049180 : CoreGMathImport
extern uint CoreGMathImport;

// R6Engine.dll data @ 10049184 : FMatrixIdentityImport
extern uint FMatrixIdentityImport;

// R6Engine.dll data @ 10049188 : UObjectStaticConstructObjectImport
extern uint UObjectStaticConstructObjectImport;

// R6Engine.dll data @ 1004918c : UObjectGetTransientPackageImport
extern uint UObjectGetTransientPackageImport;

// R6Engine.dll data @ 10049190 : UClassGetDefaultObjectImport
extern uint UClassGetDefaultObjectImport;

// R6Engine.dll data @ 10049194 : FVectorSafeNormalImport
extern uint FVectorSafeNormalImport;

// R6Engine.dll data @ 10049198 : FVectorTransformVectorByImport
extern uint FVectorTransformVectorByImport;

// R6Engine.dll data @ 1004919c : FMemStackFreeChunksImport
extern uint FMemStackFreeChunksImport;

// R6Engine.dll data @ 100491a0 : CoreGMemImport
extern uint CoreGMemImport;

// R6Engine.dll data @ 100491a4 : CoreAppRoundImport
extern uint CoreAppRoundImport;

// R6Engine.dll data @ 100491a8 : FCoordsOrthoRotationImport
extern uint FCoordsOrthoRotationImport;

// R6Engine.dll data @ 100491ac : CoreGIsEditorImport
extern uint CoreGIsEditorImport;

// R6Engine.dll data @ 100491b0 : CoreAppStricmpImport
extern uint CoreAppStricmpImport;

// R6Engine.dll data @ 100491b4 : FStringNotEqualStringImport
extern uint FStringNotEqualStringImport;

// R6Engine.dll data @ 100491b8 : FStringAssignTextImport
extern uint FStringAssignTextImport;

// R6Engine.dll data @ 100491bc : CoreAppItoaImport
extern uint CoreAppItoaImport;

// R6Engine.dll data @ 100491c0 : CoreAppAtoiImport
extern uint CoreAppAtoiImport;

// R6Engine.dll data @ 100491c4 : FStringNoInitAssignTextImport
extern uint FStringNoInitAssignTextImport;

// R6Engine.dll data @ 100491c8 : CoreAppStrcmpImport
extern uint CoreAppStrcmpImport;

// R6Engine.dll data @ 100491cc : CoreAppSprintfImport
extern uint CoreAppSprintfImport;

// R6Engine.dll data @ 100491d0 : CoreLocalizeImport
extern uint CoreLocalizeImport;

// R6Engine.dll data @ 100491d4 : CoreAppStrcpyImport
extern uint CoreAppStrcpyImport;

// R6Engine.dll data @ 100491d8 : FCoordsMultiplyImport
extern uint FCoordsMultiplyImport;

// R6Engine.dll data @ 100491dc : FBoxExpandByImport
extern uint FBoxExpandByImport;

// R6Engine.dll data @ 100491e0 : FVectorIsNearlyZeroImport
extern uint FVectorIsNearlyZeroImport;

// R6Engine.dll data @ 100491e4 : FVectorTransformPointByImport
extern uint FVectorTransformPointByImport;

// R6Engine.dll data @ 100491e8 : FStringAddStringImport
extern uint FStringAddStringImport;

// R6Engine.dll data @ 100491ec : FStringAddTextImport
extern uint FStringAddTextImport;

// R6Engine.dll data @ 100491f0 : CoreAppSaveStringToFileImport
extern uint CoreAppSaveStringToFileImport;

// R6Engine.dll data @ 100491f4 : CoreGFileManagerImport
extern uint CoreGFileManagerImport;

// R6Engine.dll data @ 100491f8 : CoreAppLoadFileToStringImport
extern uint CoreAppLoadFileToStringImport;

// R6Engine.dll data @ 100491fc : CoreParseLineImport
extern uint CoreParseLineImport;

// R6Engine.dll data @ 10049200 : CoreParseIntegerImport
extern uint CoreParseIntegerImport;

// R6Engine.dll data @ 10049204 : CoreParseStringImport
extern uint CoreParseStringImport;

// R6Engine.dll data @ 10049208 : CoreGCompileMaterialsRevisionImport
extern uint CoreGCompileMaterialsRevisionImport;

// R6Engine.dll data @ 1004920c : CoreGNightVisionActiveImport
extern uint CoreGNightVisionActiveImport;

// R6Engine.dll data @ 10049210 : FStringAppendTextImport
extern uint FStringAppendTextImport;

// R6Engine.dll data @ 10049214 : FStringAppendStringImport
extern uint FStringAppendStringImport;

// R6Engine.dll data @ 10049218 : CoreGZoomAdjustmentSniperModeImport
extern uint CoreGZoomAdjustmentSniperModeImport;

// R6Engine.dll data @ 1004921c : CoreGZoomAdjustmentSniperNoZoomImport
extern uint CoreGZoomAdjustmentSniperNoZoomImport;

// R6Engine.dll data @ 10049220 : CoreGZoomAdjustmentSniperZoomImport
extern uint CoreGZoomAdjustmentSniperZoomImport;

// R6Engine.dll data @ 10049224 : CoreGZoomAdjustmentImport
extern uint CoreGZoomAdjustmentImport;

// R6Engine.dll data @ 1004922c : APawnClearPathsImport
extern uint APawnClearPathsImport;

// R6Engine.dll data @ 10049230 : APawnSetMoveTimerImport
extern uint APawnSetMoveTimerImport;

// R6Engine.dll data @ 10049234 : ANavigationPointPrivateStaticClassImport
extern UClass* ANavigationPointPrivateStaticClassImport;

// R6Engine.dll data @ 10049238 : AActorGetProjectorBaseImport
extern uint AActorGetProjectorBaseImport;

// R6Engine.dll data @ 1004923c : AActorPostPathImport
extern uint AActorPostPathImport;

// R6Engine.dll data @ 10049240 : AActorPrePathImport
extern uint AActorPrePathImport;

// R6Engine.dll data @ 10049244 : AActorCheckForErrorsImport
extern uint AActorCheckForErrorsImport;

// R6Engine.dll data @ 10049248 : AActorTickThisFrameImport
extern uint AActorTickThisFrameImport;

// R6Engine.dll data @ 1004924c : AActorIsRelevantToPawnHeartBeatImport
extern uint AActorIsRelevantToPawnHeartBeatImport;

// R6Engine.dll data @ 10049250 : AActorIsRelevantToPawnHeatVisionImport
extern uint AActorIsRelevantToPawnHeatVisionImport;

// R6Engine.dll data @ 10049254 : AActorIsRelevantToPawnRadarImport
extern uint AActorIsRelevantToPawnRadarImport;

// R6Engine.dll data @ 10049258 : AActorPlayAnimImport
extern uint AActorPlayAnimImport;

// R6Engine.dll data @ 1004925c : AActorHasAssociatedLevelGeometryImport
extern uint AActorHasAssociatedLevelGeometryImport;

// R6Engine.dll data @ 10049260 : AActorAssociatedLevelGeometryImport
extern uint AActorAssociatedLevelGeometryImport;

// R6Engine.dll data @ 10049264 : AActorAddMyMarkerImport
extern uint AActorAddMyMarkerImport;

// R6Engine.dll data @ 10049268 : AActorKMP2DynKarmaInterfaceImport
extern uint AActorKMP2DynKarmaInterfaceImport;

// R6Engine.dll data @ 1004926c : AActorPostKarmaStepImport
extern uint AActorPostKarmaStepImport;

// R6Engine.dll data @ 10049270 : AActorPreKarmaStepImport
extern uint AActorPreKarmaStepImport;

// R6Engine.dll data @ 10049274 : AActorPhysKarmaImport
extern uint AActorPhysKarmaImport;

// R6Engine.dll data @ 10049278 : AActorGetKModelImport
extern uint AActorGetKModelImport;

// R6Engine.dll data @ 1004927c : AActorStepUpImport
extern uint AActorStepUpImport;

// R6Engine.dll data @ 10049280 : AActorSmoothHitWallImport
extern uint AActorSmoothHitWallImport;

// R6Engine.dll data @ 10049284 : AActorFindSlopeRotationImport
extern uint AActorFindSlopeRotationImport;

// R6Engine.dll data @ 10049288 : AActorPhysFallingImport
extern uint AActorPhysFallingImport;

// R6Engine.dll data @ 1004928c : AActorProcessLandedImport
extern uint AActorProcessLandedImport;

// R6Engine.dll data @ 10049290 : AActorProcessHitWallImport
extern uint AActorProcessHitWallImport;

// R6Engine.dll data @ 10049294 : AActorBoundProjectileVelocityImport
extern uint AActorBoundProjectileVelocityImport;

// R6Engine.dll data @ 10049298 : AActorPerformPhysicsImport
extern uint AActorPerformPhysicsImport;

// R6Engine.dll data @ 1004929c : AActorSetPhysicsImport
extern uint AActorSetPhysicsImport;

// R6Engine.dll data @ 100492a0 : AActorPostBeginPlayImport
extern uint AActorPostBeginPlayImport;

// R6Engine.dll data @ 100492a4 : AActorSetVolumesImport
extern uint AActorSetVolumesImport;

// R6Engine.dll data @ 100492a8 : AActorSetVolumesFromListImport
extern uint AActorSetVolumesFromListImport;

// R6Engine.dll data @ 100492ac : AActorSetZoneImport
extern uint AActorSetZoneImport;

// R6Engine.dll data @ 100492b0 : AActorRenderEditorSelectedImport
extern uint AActorRenderEditorSelectedImport;

// R6Engine.dll data @ 100492b4 : AActorRenderEditorInfoImport
extern uint AActorRenderEditorInfoImport;

// R6Engine.dll data @ 100492b8 : AActorIsNetRelevantForImport
extern uint AActorIsNetRelevantForImport;

// R6Engine.dll data @ 100492bc : AActorPlayerControlledImport
extern uint AActorPlayerControlledImport;

// R6Engine.dll data @ 100492c0 : AActorTickSpecialImport
extern uint AActorTickSpecialImport;

// R6Engine.dll data @ 100492c4 : AActorTickSimulatedImport
extern uint AActorTickSimulatedImport;

// R6Engine.dll data @ 100492c8 : AActorTickAuthoritativeImport
extern uint AActorTickAuthoritativeImport;

// R6Engine.dll data @ 100492cc : AActorCheckOwnerUpdatedImport
extern uint AActorCheckOwnerUpdatedImport;

// R6Engine.dll data @ 100492d0 : AActorUpdateTimersImport
extern uint AActorUpdateTimersImport;

// R6Engine.dll data @ 100492d4 : AActorCheckAnimFinishedImport
extern uint AActorCheckAnimFinishedImport;

// R6Engine.dll data @ 100492d8 : AActorStartAnimPollImport
extern uint AActorStartAnimPollImport;

// R6Engine.dll data @ 100492dc : AActorUpdateAnimationImport
extern uint AActorUpdateAnimationImport;

// R6Engine.dll data @ 100492e0 : AActorNotifyAnimEndImport
extern uint AActorNotifyAnimEndImport;

// R6Engine.dll data @ 100492e4 : AActorGetViewRotationImport
extern uint AActorGetViewRotationImport;

// R6Engine.dll data @ 100492e8 : AActorSetBaseImport
extern uint AActorSetBaseImport;

// R6Engine.dll data @ 100492ec : AActorNotifyBumpImport
extern uint AActorNotifyBumpImport;

// R6Engine.dll data @ 100492f0 : AActorIsMovingBrushImport
extern uint AActorIsMovingBrushImport;

// R6Engine.dll data @ 100492f4 : AActorBeginTouchImport
extern uint AActorBeginTouchImport;

// R6Engine.dll data @ 100492f8 : AActorGetPrimitiveImport
extern uint AActorGetPrimitiveImport;

// R6Engine.dll data @ 100492fc : AActorShouldTraceImport
extern uint AActorShouldTraceImport;

// R6Engine.dll data @ 10049300 : AActorPostScriptDestroyedImport
extern uint AActorPostScriptDestroyedImport;

// R6Engine.dll data @ 10049304 : AActorUpdateColBoxImport
extern uint AActorUpdateColBoxImport;

// R6Engine.dll data @ 10049308 : AActorWorldToLocalImport
extern uint AActorWorldToLocalImport;

// R6Engine.dll data @ 1004930c : AActorLocalToWorldImport
extern uint AActorLocalToWorldImport;

// R6Engine.dll data @ 10049310 : AActorToWorldImport
extern uint AActorToWorldImport;

// R6Engine.dll data @ 10049314 : AActorToLocalImport
extern uint AActorToLocalImport;

// R6Engine.dll data @ 10049318 : AActorGetSkinImport
extern uint AActorGetSkinImport;

// R6Engine.dll data @ 1004931c : AActorPostNetReceiveLocationImport
extern uint AActorPostNetReceiveLocationImport;

// R6Engine.dll data @ 10049320 : AGameReplicationInfoPostNetReceiveImport
extern uint AGameReplicationInfoPostNetReceiveImport;

// R6Engine.dll data @ 10049324 : AActorPreNetReceiveImport
extern uint AActorPreNetReceiveImport;

// R6Engine.dll data @ 10049328 : AActorSpawnedImport
extern uint AActorSpawnedImport;

// R6Engine.dll data @ 1004932c : AActorPostRaytraceImport
extern uint AActorPostRaytraceImport;

// R6Engine.dll data @ 10049330 : AActorPreRaytraceImport
extern uint AActorPreRaytraceImport;

// R6Engine.dll data @ 10049334 : AActorPostEditLoadImport
extern uint AActorPostEditLoadImport;

// R6Engine.dll data @ 10049338 : AActorPostEditMoveImport
extern uint AActorPostEditMoveImport;

// R6Engine.dll data @ 1004933c : AActorTickImport
extern uint AActorTickImport;

// R6Engine.dll data @ 10049340 : AActorWorldLightRadiusImport
extern uint AActorWorldLightRadiusImport;

// R6Engine.dll data @ 10049344 : AActorGetNetPriorityImport
extern uint AActorGetNetPriorityImport;

// R6Engine.dll data @ 10049348 : AActorIsBlockedByImport
extern uint AActorIsBlockedByImport;

// R6Engine.dll data @ 1004934c : AActorGetPawnOrColBoxOwnerImport
extern uint AActorGetPawnOrColBoxOwnerImport;

// R6Engine.dll data @ 10049350 : AActorGetPlayerPawnImport
extern uint AActorGetPlayerPawnImport;

// R6Engine.dll data @ 10049354 : AGameReplicationInfoGetOptimizedRepListImport
extern uint AGameReplicationInfoGetOptimizedRepListImport;

// R6Engine.dll data @ 10049358 : AActorNetDirtyImport
extern uint AActorNetDirtyImport;

// R6Engine.dll data @ 1004935c : AActorIsPendingDeleteImport
extern uint AActorIsPendingDeleteImport;

// R6Engine.dll data @ 10049360 : AActorPostEditChangeImport
extern uint AActorPostEditChangeImport;

// R6Engine.dll data @ 10049364 : AActorInitExecutionImport
extern uint AActorInitExecutionImport;

// R6Engine.dll data @ 10049368 : AActorIsPendingKillImport
extern uint AActorIsPendingKillImport;

// R6Engine.dll data @ 1004936c : AActorSerializeImport
extern uint AActorSerializeImport;

// R6Engine.dll data @ 10049370 : AActorDestroyImport
extern uint AActorDestroyImport;

// R6Engine.dll data @ 10049374 : AActorPostLoadImport
extern uint AActorPostLoadImport;

// R6Engine.dll data @ 10049378 : AActorProcessRemoteFunctionImport
extern uint AActorProcessRemoteFunctionImport;

// R6Engine.dll data @ 1004937c : AActorProcessStateImport
extern uint AActorProcessStateImport;

// R6Engine.dll data @ 10049380 : AActorProcessEventImport
extern uint AActorProcessEventImport;

// R6Engine.dll data @ 10049384 : AGameReplicationInfoDestructorImport
extern uint AGameReplicationInfoDestructorImport;

// R6Engine.dll data @ 10049388 : AGameReplicationInfoDefaultConstructorImport
extern uint AGameReplicationInfoDefaultConstructorImport;

// R6Engine.dll data @ 1004938c : AGameReplicationInfoCopyConstructorImport
extern uint AGameReplicationInfoCopyConstructorImport;

// R6Engine.dll data @ 10049390 : AGameReplicationInfoAssignImport
extern uint AGameReplicationInfoAssignImport;

// R6Engine.dll data @ 10049394 : APawnCheckForErrorsImport
extern uint APawnCheckForErrorsImport;

// R6Engine.dll data @ 10049398 : APawnStepUpImport
extern uint APawnStepUpImport;

// R6Engine.dll data @ 1004939c : APawnSmoothHitWallImport
extern uint APawnSmoothHitWallImport;

// R6Engine.dll data @ 100493a0 : APawnFindSlopeRotationImport
extern uint APawnFindSlopeRotationImport;

// R6Engine.dll data @ 100493a4 : APawnPhysFallingImport
extern uint APawnPhysFallingImport;

// R6Engine.dll data @ 100493a8 : APawnProcessLandedImport
extern uint APawnProcessLandedImport;

// R6Engine.dll data @ 100493ac : APawnProcessHitWallImport
extern uint APawnProcessHitWallImport;

// R6Engine.dll data @ 100493b0 : APawnPostBeginPlayImport
extern uint APawnPostBeginPlayImport;

// R6Engine.dll data @ 100493b4 : APawnSetZoneImport
extern uint APawnSetZoneImport;

// R6Engine.dll data @ 100493b8 : APawnRenderEditorSelectedImport
extern uint APawnRenderEditorSelectedImport;

// R6Engine.dll data @ 100493bc : APawnIsNetRelevantForImport
extern uint APawnIsNetRelevantForImport;

// R6Engine.dll data @ 100493c0 : APawnPlayerControlledImport
extern uint APawnPlayerControlledImport;

// R6Engine.dll data @ 100493c4 : APawnTickSimulatedImport
extern uint APawnTickSimulatedImport;

// R6Engine.dll data @ 100493c8 : APawnCheckOwnerUpdatedImport
extern uint APawnCheckOwnerUpdatedImport;

// R6Engine.dll data @ 100493cc : APawnNotifyAnimEndImport
extern uint APawnNotifyAnimEndImport;

// R6Engine.dll data @ 100493d0 : APawnSetBaseImport
extern uint APawnSetBaseImport;

// R6Engine.dll data @ 100493d4 : APawnNotifyBumpImport
extern uint APawnNotifyBumpImport;

// R6Engine.dll data @ 100493d8 : APawnShouldTraceImport
extern uint APawnShouldTraceImport;

// R6Engine.dll data @ 100493dc : APawnPostNetReceiveLocationImport
extern uint APawnPostNetReceiveLocationImport;

// R6Engine.dll data @ 100493e0 : APawnGetNetPriorityImport
extern uint APawnGetNetPriorityImport;

// R6Engine.dll data @ 100493e4 : APawnIsBlockedByImport
extern uint APawnIsBlockedByImport;

// R6Engine.dll data @ 100493e8 : APawnGetPawnOrColBoxOwnerImport
extern uint APawnGetPawnOrColBoxOwnerImport;

// R6Engine.dll data @ 100493ec : APawnGetPlayerPawnImport
extern uint APawnGetPlayerPawnImport;

// R6Engine.dll data @ 100493f0 : APawnGetOptimizedRepListImport
extern uint APawnGetOptimizedRepListImport;

// R6Engine.dll data @ 100493f4 : APawnDestroyImport
extern uint APawnDestroyImport;

// R6Engine.dll data @ 100493f8 : ANavigationPointCheckSymmetryImport
extern uint ANavigationPointCheckSymmetryImport;

// R6Engine.dll data @ 100493fc : ANavigationPointReviewPathImport
extern uint ANavigationPointReviewPathImport;

// R6Engine.dll data @ 10049400 : ANavigationPointIsIdentifiedAsImport
extern uint ANavigationPointIsIdentifiedAsImport;

// R6Engine.dll data @ 10049404 : ANavigationPointPrunePathsImport
extern uint ANavigationPointPrunePathsImport;

// R6Engine.dll data @ 10049408 : ANavigationPointFindBaseImport
extern uint ANavigationPointFindBaseImport;

// R6Engine.dll data @ 1004940c : ALadderClearPathsImport
extern uint ALadderClearPathsImport;

// R6Engine.dll data @ 10049410 : ANavigationPointSetupForcedPathImport
extern uint ANavigationPointSetupForcedPathImport;

// R6Engine.dll data @ 10049414 : ALadderInitForPathFindingImport
extern uint ALadderInitForPathFindingImport;

// R6Engine.dll data @ 10049418 : ANavigationPointPostaddReachSpecsImport
extern uint ANavigationPointPostaddReachSpecsImport;

// R6Engine.dll data @ 1004941c : ALadderAddReachSpecsImport
extern uint ALadderAddReachSpecsImport;

// R6Engine.dll data @ 10049420 : ALadderProscribedPathToImport
extern uint ALadderProscribedPathToImport;

// R6Engine.dll data @ 10049424 : ANavigationPointCheckForErrorsImport
extern uint ANavigationPointCheckForErrorsImport;

// R6Engine.dll data @ 10049428 : ANavigationPointSetVolumesFromListImport
extern uint ANavigationPointSetVolumesFromListImport;

// R6Engine.dll data @ 1004942c : AActorPostNetReceiveImport
extern uint AActorPostNetReceiveImport;

// R6Engine.dll data @ 10049430 : ANavigationPointSpawnedImport
extern uint ANavigationPointSpawnedImport;

// R6Engine.dll data @ 10049434 : ANavigationPointPostEditMoveImport
extern uint ANavigationPointPostEditMoveImport;

// R6Engine.dll data @ 10049438 : AActorGetOptimizedRepListImport
extern uint AActorGetOptimizedRepListImport;

// R6Engine.dll data @ 1004943c : ANavigationPointDestroyImport
extern uint ANavigationPointDestroyImport;

// R6Engine.dll data @ 10049440 : ALadderDestructorImport
extern uint ALadderDestructorImport;

// R6Engine.dll data @ 10049444 : ALadderDefaultConstructorImport
extern uint ALadderDefaultConstructorImport;

// R6Engine.dll data @ 10049448 : ALadderCopyConstructorImport
extern uint ALadderCopyConstructorImport;

// R6Engine.dll data @ 1004944c : ALadderAssignImport
extern uint ALadderAssignImport;

// R6Engine.dll data @ 10049450 : ANavigationPointDestructorImport
extern uint ANavigationPointDestructorImport;

// R6Engine.dll data @ 10049454 : ANavigationPointDefaultConstructorImport
extern uint ANavigationPointDefaultConstructorImport;

// R6Engine.dll data @ 10049458 : ANavigationPointCopyConstructorImport
extern uint ANavigationPointCopyConstructorImport;

// R6Engine.dll data @ 1004945c : ANavigationPointAssignImport
extern uint ANavigationPointAssignImport;

// R6Engine.dll data @ 10049460 : ANavigationPointClearPathsImport
extern uint ANavigationPointClearPathsImport;

// R6Engine.dll data @ 10049464 : ANavigationPointInitForPathFindingImport
extern uint ANavigationPointInitForPathFindingImport;

// R6Engine.dll data @ 10049468 : ANavigationPointAddReachSpecsImport
extern uint ANavigationPointAddReachSpecsImport;

// R6Engine.dll data @ 1004946c : ANavigationPointProscribedPathToImport
extern uint ANavigationPointProscribedPathToImport;

// R6Engine.dll data @ 10049470 : ABrushInitPosRotScaleImport
extern uint ABrushInitPosRotScaleImport;

// R6Engine.dll data @ 10049474 : ABrushCopyPosRotScaleFromImport
extern uint ABrushCopyPosRotScaleFromImport;

// R6Engine.dll data @ 10049478 : ABrushCheckForErrorsImport
extern uint ABrushCheckForErrorsImport;

// R6Engine.dll data @ 1004947c : AVolumePostBeginPlayImport
extern uint AVolumePostBeginPlayImport;

// R6Engine.dll data @ 10049480 : AVolumeSetVolumesImport
extern uint AVolumeSetVolumesImport;

// R6Engine.dll data @ 10049484 : AVolumeSetVolumesFromListImport
extern uint AVolumeSetVolumesFromListImport;

// R6Engine.dll data @ 10049488 : APhysicsVolumeSetZoneImport
extern uint APhysicsVolumeSetZoneImport;

// R6Engine.dll data @ 1004948c : ALadderVolumeRenderEditorInfoImport
extern uint ALadderVolumeRenderEditorInfoImport;

// R6Engine.dll data @ 10049490 : ABrushGetPrimitiveImport
extern uint ABrushGetPrimitiveImport;

// R6Engine.dll data @ 10049494 : ABrushToWorldImport
extern uint ABrushToWorldImport;

// R6Engine.dll data @ 10049498 : ABrushToLocalImport
extern uint ABrushToLocalImport;

// R6Engine.dll data @ 1004949c : APhysicsVolumeGetOptimizedRepListImport
extern uint APhysicsVolumeGetOptimizedRepListImport;

// R6Engine.dll data @ 100494a0 : ABrushPostEditChangeImport
extern uint ABrushPostEditChangeImport;

// R6Engine.dll data @ 100494a4 : ABrushPostLoadImport
extern uint ABrushPostLoadImport;

// R6Engine.dll data @ 100494a8 : ALadderVolumeDestructorImport
extern uint ALadderVolumeDestructorImport;

// R6Engine.dll data @ 100494ac : ALadderVolumeDefaultConstructorImport
extern uint ALadderVolumeDefaultConstructorImport;

// R6Engine.dll data @ 100494b0 : ALadderVolumeCopyConstructorImport
extern uint ALadderVolumeCopyConstructorImport;

// R6Engine.dll data @ 100494b4 : ALadderVolumeAssignImport
extern uint ALadderVolumeAssignImport;

// R6Engine.dll data @ 100494b8 : AVolumeShouldTraceImport
extern uint AVolumeShouldTraceImport;

// R6Engine.dll data @ 100494bc : APhysicsVolumeDestructorImport
extern uint APhysicsVolumeDestructorImport;

// R6Engine.dll data @ 100494c0 : APhysicsVolumeDefaultConstructorImport
extern uint APhysicsVolumeDefaultConstructorImport;

// R6Engine.dll data @ 100494c4 : APhysicsVolumeCopyConstructorImport
extern uint APhysicsVolumeCopyConstructorImport;

// R6Engine.dll data @ 100494c8 : APhysicsVolumeAssignImport
extern uint APhysicsVolumeAssignImport;

// R6Engine.dll data @ 100494cc : AControllerGetTeamManagerImport
extern uint AControllerGetTeamManagerImport;

// R6Engine.dll data @ 100494d0 : AControllerLocalPlayerControllerImport
extern uint AControllerLocalPlayerControllerImport;

// R6Engine.dll data @ 100494d4 : AAIControllerSetAdjustLocationImport
extern uint AAIControllerSetAdjustLocationImport;

// R6Engine.dll data @ 100494d8 : AAIControllerAcceptNearbyPathImport
extern uint AAIControllerAcceptNearbyPathImport;

// R6Engine.dll data @ 100494dc : AControllerGetViewTargetImport
extern uint AControllerGetViewTargetImport;

// R6Engine.dll data @ 100494e0 : AControllerCheckHearSoundImport
extern uint AControllerCheckHearSoundImport;

// R6Engine.dll data @ 100494e4 : AControllerCheckAnimFinishedImport
extern uint AControllerCheckAnimFinishedImport;

// R6Engine.dll data @ 100494e8 : AControllerStartAnimPollImport
extern uint AControllerStartAnimPollImport;

// R6Engine.dll data @ 100494ec : AControllerTickImport
extern uint AControllerTickImport;

// R6Engine.dll data @ 100494f0 : AControllerGetOptimizedRepListImport
extern uint AControllerGetOptimizedRepListImport;

// R6Engine.dll data @ 100494f4 : AAIControllerDestructorImport
extern uint AAIControllerDestructorImport;

// R6Engine.dll data @ 100494f8 : AAIControllerDefaultConstructorImport
extern uint AAIControllerDefaultConstructorImport;

// R6Engine.dll data @ 100494fc : AAIControllerCopyConstructorImport
extern uint AAIControllerCopyConstructorImport;

// R6Engine.dll data @ 10049500 : AAIControllerAssignImport
extern uint AAIControllerAssignImport;

// R6Engine.dll data @ 10049504 : AR6AbstractClimbableObjDestructorImport
extern uint AR6AbstractClimbableObjDestructorImport;

// R6Engine.dll data @ 10049508 : AR6AbstractClimbableObjDefaultConstructorImport
extern uint AR6AbstractClimbableObjDefaultConstructorImport;

// R6Engine.dll data @ 1004950c : AR6AbstractClimbableObjCopyConstructorImport
extern uint AR6AbstractClimbableObjCopyConstructorImport;

// R6Engine.dll data @ 10049510 : AR6AbstractClimbableObjAssignImport
extern uint AR6AbstractClimbableObjAssignImport;

// R6Engine.dll data @ 10049514 : AActorDestructorImport
extern uint AActorDestructorImport;

// R6Engine.dll data @ 10049518 : AActorDefaultConstructorImport
extern uint AActorDefaultConstructorImport;

// R6Engine.dll data @ 1004951c : AActorCopyConstructorImport
extern uint AActorCopyConstructorImport;

// R6Engine.dll data @ 10049520 : AActorAssignImport
extern uint AActorAssignImport;

// R6Engine.dll data @ 10049524 : UMatSubActionPreBeginPreviewImport
extern uint UMatSubActionPreBeginPreviewImport;

// R6Engine.dll data @ 10049528 : UMatSubActionInitializeImport
extern uint UMatSubActionInitializeImport;

// R6Engine.dll data @ 1004952c : UMatSubActionIsEndingImport
extern uint UMatSubActionIsEndingImport;

// R6Engine.dll data @ 10049530 : UMatSubActionIsRunningImport
extern uint UMatSubActionIsRunningImport;

// R6Engine.dll data @ 10049534 : UMatSubActionPostEditChangeImport
extern uint UMatSubActionPostEditChangeImport;

// R6Engine.dll data @ 10049538 : UMatSubActionDestructorImport
extern uint UMatSubActionDestructorImport;

// R6Engine.dll data @ 1004953c : UMatSubActionDefaultConstructorImport
extern uint UMatSubActionDefaultConstructorImport;

// R6Engine.dll data @ 10049540 : UMatSubActionCopyConstructorImport
extern uint UMatSubActionCopyConstructorImport;

// R6Engine.dll data @ 10049544 : UMatSubActionAssignImport
extern uint UMatSubActionAssignImport;

// R6Engine.dll data @ 10049548 : APawnFindPathTowardImport
extern uint APawnFindPathTowardImport;

// R6Engine.dll data @ 1004954c : AControllerFindPathImport
extern uint AControllerFindPathImport;

// R6Engine.dll data @ 10049550 : FSortedPathListAddPathImport
extern uint FSortedPathListAddPathImport;

// R6Engine.dll data @ 10049554 : APawnEventEyePositionImport
extern uint APawnEventEyePositionImport;

// R6Engine.dll data @ 10049558 : ULevelGetLevelInfoImport
extern uint ULevelGetLevelInfoImport;

// R6Engine.dll data @ 1004955c : USkeletalMeshInstanceGetBoneCoordsImport
extern uint USkeletalMeshInstanceGetBoneCoordsImport;

// R6Engine.dll data @ 10049560 : USkeletalMeshInstanceMatchRefBoneImport
extern uint USkeletalMeshInstanceMatchRefBoneImport;

// R6Engine.dll data @ 10049564 : AActorEventFallingImport
extern uint AActorEventFallingImport;

// R6Engine.dll data @ 10049568 : AActorEventAnimEndImport
extern uint AActorEventAnimEndImport;

// R6Engine.dll data @ 1004956c : AActorIsAnimatingImport
extern uint AActorIsAnimatingImport;

// R6Engine.dll data @ 10049570 : APawnPickWallAdjustImport
extern uint APawnPickWallAdjustImport;

// R6Engine.dll data @ 10049574 : APlayerControllerAssignImport
extern uint APlayerControllerAssignImport;

// R6Engine.dll data @ 10049578 : UR6AbstractTerroristMgrDestructorImport
extern uint UR6AbstractTerroristMgrDestructorImport;

// R6Engine.dll data @ 1004957c : UR6AbstractTerroristMgrVtableImport
extern uint UR6AbstractTerroristMgrVtableImport;

// R6Engine.dll data @ 10049580 : APlayerControllerLocalPlayerControllerImport
extern uint APlayerControllerLocalPlayerControllerImport;

// R6Engine.dll data @ 10049584 : AControllerSetAdjustLocationImport
extern uint AControllerSetAdjustLocationImport;

// R6Engine.dll data @ 10049588 : AControllerAdjustFromWallImport
extern uint AControllerAdjustFromWallImport;

// R6Engine.dll data @ 1004958c : AControllerAcceptNearbyPathImport
extern uint AControllerAcceptNearbyPathImport;

// R6Engine.dll data @ 10049590 : APlayerControllerGetViewTargetImport
extern uint APlayerControllerGetViewTargetImport;

// R6Engine.dll data @ 10049594 : APlayerControllerCheckHearSoundImport
extern uint APlayerControllerCheckHearSoundImport;

// R6Engine.dll data @ 10049598 : AControllerCanHearImport
extern uint AControllerCanHearImport;

// R6Engine.dll data @ 1004959c : APlayerControllerIsNetRelevantForImport
extern uint APlayerControllerIsNetRelevantForImport;

// R6Engine.dll data @ 100495a0 : APlayerControllerGetOptimizedRepListImport
extern uint APlayerControllerGetOptimizedRepListImport;

// R6Engine.dll data @ 100495a4 : APlayerControllerDestructorImport
extern uint APlayerControllerDestructorImport;

// R6Engine.dll data @ 100495a8 : APlayerControllerDefaultConstructorImport
extern uint APlayerControllerDefaultConstructorImport;

// R6Engine.dll data @ 100495ac : APlayerControllerCopyConstructorImport
extern uint APlayerControllerCopyConstructorImport;

// R6Engine.dll data @ 100495b0 : AActorSafeDestroyActorImport
extern uint AActorSafeDestroyActorImport;

// R6Engine.dll data @ 100495b4 : AScoutPrivateStaticClassImport
extern UClass* AScoutPrivateStaticClassImport;

// R6Engine.dll data @ 100495b8 : FLineBatcherDestructorImport
extern uint FLineBatcherDestructorImport;

// R6Engine.dll data @ 100495bc : FLineBatcherDrawCylinderImport
extern uint FLineBatcherDrawCylinderImport;

// R6Engine.dll data @ 100495c0 : FColorConstructorImport
extern uint FColorConstructorImport;

// R6Engine.dll data @ 100495c4 : FLineBatcherConstructorImport
extern uint FLineBatcherConstructorImport;

// R6Engine.dll data @ 100495c8 : ALevelInfoEventGameTypeUseNbOfTerroristToSpawnImport
extern uint ALevelInfoEventGameTypeUseNbOfTerroristToSpawnImport;

// R6Engine.dll data @ 100495cc : UTexturePrivateStaticClassImport
extern UClass* UTexturePrivateStaticClassImport;

// R6Engine.dll data @ 100495d0 : FLineBatcherDrawBoxImport
extern uint FLineBatcherDrawBoxImport;

// R6Engine.dll data @ 100495d4 : EngineDrawSpriteImport
extern uint EngineDrawSpriteImport;

// R6Engine.dll data @ 100495d8 : AActorPutOnGroundImport
extern uint AActorPutOnGroundImport;

// R6Engine.dll data @ 100495dc : AActorIsAvailableInGameTypeImport
extern uint AActorIsAvailableInGameTypeImport;

// R6Engine.dll data @ 100495e0 : FLineBatcherDrawCircleImport
extern uint FLineBatcherDrawCircleImport;

// R6Engine.dll data @ 100495e4 : FLineBatcherDrawLineImport
extern uint FLineBatcherDrawLineImport;

// R6Engine.dll data @ 100495e8 : AActorCopyR6AvailabilityImport
extern uint AActorCopyR6AvailabilityImport;

// R6Engine.dll data @ 100495ec : EngineGPEngineImport
extern uint EngineGPEngineImport;

// R6Engine.dll data @ 100495f0 : APlayerControllerPrivateStaticClassImport
extern UClass* APlayerControllerPrivateStaticClassImport;

// R6Engine.dll data @ 100495f4 : APawnIsAliveImport
extern uint APawnIsAliveImport;

// R6Engine.dll data @ 100495f8 : FLineBatcherDrawSphereImport
extern uint FLineBatcherDrawSphereImport;

// R6Engine.dll data @ 100495fc : UStaticMeshGetTagImport
extern uint UStaticMeshGetTagImport;

// R6Engine.dll data @ 10049600 : AActorSetGameTypeImport
extern uint AActorSetGameTypeImport;

// R6Engine.dll data @ 10049604 : UReachSpecPrivateStaticClassImport
extern UClass* UReachSpecPrivateStaticClassImport;

// R6Engine.dll data @ 10049608 : ANavigationPointCleanUpPrunedImport
extern uint ANavigationPointCleanUpPrunedImport;

// R6Engine.dll data @ 1004960c : ANavigationPointFindAlternatePathImport
extern uint ANavigationPointFindAlternatePathImport;

// R6Engine.dll data @ 10049610 : UReachSpecOperatorImport
extern uint UReachSpecOperatorImport;

// R6Engine.dll data @ 10049614 : FLineBatcherDrawDirectionalArrowImport
extern uint FLineBatcherDrawDirectionalArrowImport;

// R6Engine.dll data @ 10049618 : UReachSpecInitImport
extern uint UReachSpecInitImport;

// R6Engine.dll data @ 1004961c : AActorSetCollisionSizeImport
extern uint AActorSetCollisionSizeImport;

// R6Engine.dll data @ 10049620 : ALadderVolumeFindTopImport
extern uint ALadderVolumeFindTopImport;

// R6Engine.dll data @ 10049624 : APawnCalcVelocityImport
extern uint APawnCalcVelocityImport;

// R6Engine.dll data @ 10049628 : AActorSetDrawScaleImport
extern uint AActorSetDrawScaleImport;

// R6Engine.dll data @ 1004962c : APawnPreNetReceiveImport
extern uint APawnPreNetReceiveImport;

// R6Engine.dll data @ 10049630 : APawnPostNetReceiveImport
extern uint APawnPostNetReceiveImport;

// R6Engine.dll data @ 10049634 : AControllerLineOfSightToImport
extern uint AControllerLineOfSightToImport;

// R6Engine.dll data @ 10049638 : ECLipSynchDataM_vUpdateLipSynchImport
extern uint ECLipSynchDataM_vUpdateLipSynchImport;

// R6Engine.dll data @ 1004963c : USkeletalMeshPrivateStaticClassImport
extern UClass* USkeletalMeshPrivateStaticClassImport;

// R6Engine.dll data @ 10049640 : ECLipSynchDataM_vStartLipsynchImport
extern uint ECLipSynchDataM_vStartLipsynchImport;

// R6Engine.dll data @ 10049644 : ECLipSynchDataConstructorImport
extern uint ECLipSynchDataConstructorImport;

// R6Engine.dll data @ 10049648 : APawnTickSpecialImport
extern uint APawnTickSpecialImport;

// R6Engine.dll data @ 1004964c : ECLipSynchDataM_vStopLipsynchImport
extern uint ECLipSynchDataM_vStopLipsynchImport;

// R6Engine.dll data @ 10049650 : AR6EngineWeaponEventIsGogglesImport
extern uint AR6EngineWeaponEventIsGogglesImport;

// R6Engine.dll data @ 10049654 : USkeletalMeshInstanceSetBoneRotationImport
extern uint USkeletalMeshInstanceSetBoneRotationImport;

// R6Engine.dll data @ 10049658 : USkeletalMeshInstancePrivateStaticClassImport
extern UClass* USkeletalMeshInstancePrivateStaticClassImport;

// R6Engine.dll data @ 1004965c : UNetConnectionPrivateStaticClassImport
extern UClass* UNetConnectionPrivateStaticClassImport;

// R6Engine.dll data @ 10049660 : UModifierPrivateStaticClassImport
extern UClass* UModifierPrivateStaticClassImport;

// R6Engine.dll data @ 10049664 : AR6ColBoxEnableCollisionImport
extern uint AR6ColBoxEnableCollisionImport;

// R6Engine.dll data @ 10049668 : AR6ColBoxCanStepUpImport
extern uint AR6ColBoxCanStepUpImport;

// R6Engine.dll data @ 1004966c : AR6ColBoxGetMaxStepUpImport
extern uint AR6ColBoxGetMaxStepUpImport;

// R6Engine.dll data @ 10049670 : AR6ColBoxGetColBoxLocationFromOwnerImport
extern uint AR6ColBoxGetColBoxLocationFromOwnerImport;

// R6Engine.dll data @ 10049674 : APawnIsHumanControlledImport
extern uint APawnIsHumanControlledImport;

// R6Engine.dll data @ 10049678 : AActorEventPostTouchImport
extern uint AActorEventPostTouchImport;

// R6Engine.dll data @ 1004967c : APawnStartNewPhysicsImport
extern uint APawnStartNewPhysicsImport;

// R6Engine.dll data @ 10049680 : APawnCrouchImport
extern uint APawnCrouchImport;

// R6Engine.dll data @ 10049684 : APawnUnCrouchImport
extern uint APawnUnCrouchImport;

// R6Engine.dll data @ 10049688 : APawnIsCrouchedImport
extern uint APawnIsCrouchedImport;

// R6Engine.dll data @ 1004968c : AActorEventFellOutOfWorldImport
extern uint AActorEventFellOutOfWorldImport;

// R6Engine.dll data @ 10049690 : EngineGStatsImport
extern uint EngineGStatsImport;

// R6Engine.dll data @ 10049694 : EngineGEngineStatsImport
extern uint EngineGEngineStatsImport;

// R6Engine.dll data @ 10049698 : APawnPerformPhysicsImport
extern uint APawnPerformPhysicsImport;

// R6Engine.dll data @ 1004969c : AActorPrivateStaticClassImport
extern UClass* AActorPrivateStaticClassImport;

// R6Engine.dll data @ 100496a0 : AR6ColBoxGetDestinationImport
extern uint AR6ColBoxGetDestinationImport;

// R6Engine.dll data @ 100496a4 : AActorFixedTurnImport
extern uint AActorFixedTurnImport;

// R6Engine.dll data @ 100496a8 : AVolumeEncompassesImport
extern uint AVolumeEncompassesImport;

// R6Engine.dll data @ 100496ac : APawnEventEndClimbLadderImport
extern uint APawnEventEndClimbLadderImport;

// R6Engine.dll data @ 100496b0 : AControllerEventMayFallImport
extern uint AControllerEventMayFallImport;

// R6Engine.dll data @ 100496b4 : AActorIsOverlappingImport
extern uint AActorIsOverlappingImport;

// R6Engine.dll data @ 100496b8 : APawnIsLocallyControlledImport
extern uint APawnIsLocallyControlledImport;

// R6Engine.dll data @ 100496bc : AR6DecalManagerAddDecalImport
extern uint AR6DecalManagerAddDecalImport;

// R6Engine.dll data @ 100496c0 : AActorTraceImport
extern uint AActorTraceImport;

// R6Engine.dll data @ 100496c4 : USkeletalMeshInstanceWasSkeletonUpdatedImport
extern uint USkeletalMeshInstanceWasSkeletonUpdatedImport;

// R6Engine.dll data @ 100496c8 : APawnReachableImport
extern uint APawnReachableImport;

// R6Engine.dll data @ 100496cc : APawnPrivateStaticClassImport
extern UClass* APawnPrivateStaticClassImport;

// R6Engine.dll data @ 100496d0 : APawnValidAnchorImport
extern uint APawnValidAnchorImport;

// R6Engine.dll data @ 100496d4 : APawnMoveTowardImport
extern uint APawnMoveTowardImport;

// R6Engine.dll data @ 100496d8 : APlayerControllerEventClientHearSoundImport
extern uint APlayerControllerEventClientHearSoundImport;

// R6Engine.dll data @ 100496dc : AR6EngineWeaponEventPawnStoppedMovingImport
extern uint AR6EngineWeaponEventPawnStoppedMovingImport;

// R6Engine.dll data @ 100496e0 : USkeletalMeshInstanceSetAnimRateImport
extern uint USkeletalMeshInstanceSetAnimRateImport;

// R6Engine.dll data @ 100496e4 : USkeletalMeshInstanceSetAnimSequenceImport
extern uint USkeletalMeshInstanceSetAnimSequenceImport;

// R6Engine.dll data @ 100496e8 : USkeletalMeshInstanceCopyAnimationImport
extern uint USkeletalMeshInstanceCopyAnimationImport;

// R6Engine.dll data @ 100496ec : USkeletalMeshInstanceGetBlendAlphaImport
extern uint USkeletalMeshInstanceGetBlendAlphaImport;

// R6Engine.dll data @ 100496f0 : USkeletalMeshInstanceGetAnimSequenceImport
extern uint USkeletalMeshInstanceGetAnimSequenceImport;

// R6Engine.dll data @ 100496f4 : USkeletalMeshInstanceGetAnimRateOnChannelImport
extern uint USkeletalMeshInstanceGetAnimRateOnChannelImport;

// R6Engine.dll data @ 100496f8 : AR6EngineWeaponEventPawnIsMovingImport
extern uint AR6EngineWeaponEventPawnIsMovingImport;

// R6Engine.dll data @ 100496fc : APawnZeroMovementAlphaImport
extern uint APawnZeroMovementAlphaImport;

// R6Engine.dll data @ 10049700 : APawnEventPlayFallingImport
extern uint APawnEventPlayFallingImport;

// R6Engine.dll data @ 10049704 : APawnEventPlayJumpImport
extern uint APawnEventPlayJumpImport;

// R6Engine.dll data @ 10049708 : APawnEventPlayLandingAnimationImport
extern uint APawnEventPlayLandingAnimationImport;

// R6Engine.dll data @ 1004970c : USkeletalMeshInstanceUpdateBlendAlphaImport
extern uint USkeletalMeshInstanceUpdateBlendAlphaImport;

// R6Engine.dll data @ 10049710 : APawnEventChangeAnimationImport
extern uint APawnEventChangeAnimationImport;

// R6Engine.dll data @ 10049714 : USkeletalMeshInstanceSetBlendAlphaImport
extern uint USkeletalMeshInstanceSetBlendAlphaImport;

// R6Engine.dll data @ 10049718 : USkeletalMeshInstanceEnableChannelNotifyImport
extern uint USkeletalMeshInstanceEnableChannelNotifyImport;

// R6Engine.dll data @ 1004971c : APawnEventPlayWeaponAnimationImport
extern uint APawnEventPlayWeaponAnimationImport;

// R6Engine.dll data @ 10049720 : USkeletalMeshInstanceSetBlendParamsImport
extern uint USkeletalMeshInstanceSetBlendParamsImport;

// R6Engine.dll data @ 10049724 : AR6EngineWeaponEventSetIdentifyTargetImport
extern uint AR6EngineWeaponEventSetIdentifyTargetImport;

// R6Engine.dll data @ 10049728 : AActorEventGetReticuleInfoImport
extern uint AActorEventGetReticuleInfoImport;

// R6Engine.dll data @ 1004972c : APlayerControllerPreNetReceiveImport
extern uint APlayerControllerPreNetReceiveImport;

// R6Engine.dll data @ 10049730 : FCameraSceneNodeDestructorImport
extern uint FCameraSceneNodeDestructorImport;

// R6Engine.dll data @ 10049734 : FCanvasUtilDestructorImport
extern uint FCanvasUtilDestructorImport;

// R6Engine.dll data @ 10049738 : FSceneNodeProjectImport
extern uint FSceneNodeProjectImport;

// R6Engine.dll data @ 1004973c : FCanvasUtilConstructorImport
extern uint FCanvasUtilConstructorImport;

// R6Engine.dll data @ 10049740 : FCameraSceneNodeConstructorImport
extern uint FCameraSceneNodeConstructorImport;

// R6Engine.dll data @ 10049744 : UViewportPrivateStaticClassImport
extern UClass* UViewportPrivateStaticClassImport;

// R6Engine.dll data @ 10049748 : UInteractionEventConvertKeyToLocalisationImport
extern uint UInteractionEventConvertKeyToLocalisationImport;

// R6Engine.dll data @ 1004974c : AActorEventR6QueryCircumstantialActionImport
extern uint AActorEventR6QueryCircumstantialActionImport;

// R6Engine.dll data @ 10049750 : ATerrainInfoPrivateStaticClassImport
extern UClass* ATerrainInfoPrivateStaticClassImport;

// R6Engine.dll data @ 10049754 : AStaticMeshActorPrivateStaticClassImport
extern UClass* AStaticMeshActorPrivateStaticClassImport;

// R6Engine.dll data @ 10049758 : ALevelInfoPrivateStaticClassImport
extern UClass* ALevelInfoPrivateStaticClassImport;

// R6Engine.dll data @ 1004975c : APlayerControllerPostNetReceiveImport
extern uint APlayerControllerPostNetReceiveImport;

// R6Engine.dll data @ 10049760 : USkeletalMeshInstanceSetBonePositionImport
extern uint USkeletalMeshInstanceSetBonePositionImport;

// R6Engine.dll data @ 10049764 : APawnActorReachableImport
extern uint APawnActorReachableImport;

// R6Engine.dll data @ 10049768 : APawnIsNeutralImport
extern uint APawnIsNeutralImport;

// R6Engine.dll data @ 1004976c : APawnIsFriendImport
extern uint APawnIsFriendImport;

// R6Engine.dll data @ 10049770 : AR6EngineWeaponEventShowWeaponParticulesImport
extern uint AR6EngineWeaponEventShowWeaponParticulesImport;

// R6Engine.dll data @ 10049774 : APawnWalkReachableImport
extern uint APawnWalkReachableImport;

// R6Engine.dll data @ 10049778 : FSortedPathListFindStartAnchorImport
extern uint FSortedPathListFindStartAnchorImport;

// R6Engine.dll data @ 1004977c : EngineGModMgrImport
extern uint EngineGModMgrImport;

// R6Engine.dll data @ 10049780 : AAIControllerPrivateStaticClassImport
extern UClass* AAIControllerPrivateStaticClassImport;

// R6Engine.dll data @ 10049784 : ALadderPrivateStaticClassImport
extern UClass* ALadderPrivateStaticClassImport;

// R6Engine.dll data @ 10049788 : APhysicsVolumePrivateStaticClassImport
extern UClass* APhysicsVolumePrivateStaticClassImport;

// R6Engine.dll data @ 1004978c : UR6AbstractTerroristMgrPrivateStaticClassImport
extern UClass* UR6AbstractTerroristMgrPrivateStaticClassImport;

// R6Engine.dll data @ 10049790 : ALadderVolumePrivateStaticClassImport
extern UClass* ALadderVolumePrivateStaticClassImport;

// R6Engine.dll data @ 10049794 : AR6AbstractClimbableObjPrivateStaticClassImport
extern UClass* AR6AbstractClimbableObjPrivateStaticClassImport;

// R6Engine.dll data @ 10049798 : AGameReplicationInfoPrivateStaticClassImport
extern UClass* AGameReplicationInfoPrivateStaticClassImport;

// R6Engine.dll data @ 1004979c : AActorAnimBlendParamsImport
extern uint AActorAnimBlendParamsImport;

// R6Engine.dll data @ 100497a0 : UMatSubActionGetStatStringImport
extern uint UMatSubActionGetStatStringImport;

// R6Engine.dll data @ 100497a4 : UMatSubActionUpdateImport
extern uint UMatSubActionUpdateImport;

// R6Engine.dll data @ 100497a8 : USkeletalMeshInstanceGetTagPositionImport
extern uint USkeletalMeshInstanceGetTagPositionImport;

// R6Engine.dll data @ 100497ac : USkeletalMeshInstanceGetBoneNameImport
extern uint USkeletalMeshInstanceGetBoneNameImport;

// R6Engine.dll data @ 100497b0 : UMatSubActionPrivateStaticClassImport
extern UClass* UMatSubActionPrivateStaticClassImport;

// R6Engine.dll data @ 100497b4 : APlayerControllerTickImport
extern uint APlayerControllerTickImport;

// R6Engine.dll data @ 100497f8 : AR6AbstractPawnPrivateStaticClassImport
extern UClass* AR6AbstractPawnPrivateStaticClassImport;

// R6Engine.dll data @ 100497fc : AR6AbstractCorpsePrivateStaticClassImport
extern UClass* AR6AbstractCorpsePrivateStaticClassImport;

// R6Engine.dll data @ 10049800 : AR6AbstractCorpseCopyConstructorImport
extern uint AR6AbstractCorpseCopyConstructorImport;

// R6Engine.dll data @ 10049804 : AR6AbstractCorpseDefaultConstructorImport
extern uint AR6AbstractCorpseDefaultConstructorImport;

// R6Engine.dll data @ 10049808 : AR6AbstractCorpseDestructorImport
extern uint AR6AbstractCorpseDestructorImport;

// R6Engine.dll data @ 1004980c : AR6AbstractCorpseAssignImport
extern uint AR6AbstractCorpseAssignImport;

// R6Engine.dll data @ 10049810 : AR6AbstractPawnEventGetSkillImport
extern uint AR6AbstractPawnEventGetSkillImport;

// R6Engine.dll data @ 10049814 : AR6AbstractPawnAssignImport
extern uint AR6AbstractPawnAssignImport;

// R6Engine.dll data @ 10049818 : AR6AbstractPawnCopyConstructorImport
extern uint AR6AbstractPawnCopyConstructorImport;

// R6Engine.dll data @ 1004981c : AR6AbstractPawnDefaultConstructorImport
extern uint AR6AbstractPawnDefaultConstructorImport;

// R6Engine.dll data @ 10049820 : AR6AbstractPawnDestructorImport
extern uint AR6AbstractPawnDestructorImport;

// R6Engine.dll data @ 100497bc : CrtCxxThrowExceptionImport
extern uint CrtCxxThrowExceptionImport;

// R6Engine.dll data @ 100497c0 : CrtCppXcptFilterImport
extern uint CrtCppXcptFilterImport;

// R6Engine.dll data @ 100497c4 : CrtAdjustFdivImport
extern uint CrtAdjustFdivImport;

// R6Engine.dll data @ 100497c8 : CrtMallocImport
extern uint CrtMallocImport;

// R6Engine.dll data @ 100497cc : CrtInittermImport
extern uint CrtInittermImport;

// R6Engine.dll data @ 100497d0 : CrtFreeImport
extern uint CrtFreeImport;

// R6Engine.dll data @ 100497d4 : CrtOnexitImport
extern uint CrtOnexitImport;

// R6Engine.dll data @ 100497d8 : CrtDllonexitImport
extern uint CrtDllonexitImport;

// R6Engine.dll data @ 100497dc : CrtExceptHandler3Import
extern uint CrtExceptHandler3Import;

// R6Engine.dll data @ 100497e0 : CrtTerminateImport
extern uint CrtTerminateImport;

// R6Engine.dll data @ 100497e4 : type_infoDestructorImport
extern uint type_infoDestructorImport;

// R6Engine.dll data @ 100497e8 : CrtSwscanfImport
extern uint CrtSwscanfImport;

// R6Engine.dll data @ 100497ec : CrtCxxFrameHandlerImport
extern uint CrtCxxFrameHandlerImport;

// R6Engine.dll data @ 100497f0 : CrtCIasinImport
extern uint CrtCIasinImport;
