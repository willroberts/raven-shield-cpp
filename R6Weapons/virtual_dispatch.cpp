// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006014 : Core.dll ?GetPropertiesSize@UObject@@UAEHXZ
extern uint UObjectGetPropertiesSizeImport;
// R6Weapons.dll import @ 10006018 : Core.dll ?LanguageChange@UObject@@UAEXXZ
extern uint UObjectLanguageChangeImport;
// R6Weapons.dll import @ 1000601c : Core.dll ?Register@UObject@@UAEXXZ
extern uint UObjectRegisterImport;
// R6Weapons.dll import @ 10006020 : Core.dll ?ScriptConsoleExec@UObject@@UAEHPBGAAVFOutputDevice@@PAV1@@Z
extern uint UObjectScriptConsoleExecImport;
// R6Weapons.dll import @ 10006024 : Core.dll ?CallFunction@UObject@@UAEXAAUFFrame@@QAXPAVUFunction@@@Z
extern uint UObjectCallFunctionImport;
// R6Weapons.dll import @ 10006028 : Core.dll ?ShutdownAfterError@UObject@@UAEXXZ
extern uint UObjectShutdownAfterErrorImport;
// R6Weapons.dll import @ 1000602c : Core.dll ?GotoLabel@UObject@@UAEHVFName@@@Z
extern uint UObjectGotoLabelImport;
// R6Weapons.dll import @ 10006030 : Core.dll ?GotoState@UObject@@UAE?AW4EGotoState@@VFName@@@Z
extern uint UObjectGotoStateImport;
// R6Weapons.dll import @ 10006034 : Core.dll ?Modify@UObject@@UAEXXZ
extern uint UObjectModifyImport;
// R6Weapons.dll import @ 10006038 : Core.dll ?ProcessDelegate@UObject@@UAEXVFName@@PAUFScriptDelegate@@PAX2@Z
extern uint UObjectProcessDelegateImport;
// R6Weapons.dll import @ 1000603c : Core.dll ?Release@UObject@@UAGKXZ
extern uint UObjectReleaseImport;
// R6Weapons.dll import @ 10006040 : Core.dll ?AddRef@UObject@@UAGKXZ
extern uint UObjectAddRefImport;
// R6Weapons.dll import @ 10006044 : Core.dll ?QueryInterface@UObject@@UAGKABVFGuid@@PAPAX@Z
extern uint UObjectQueryInterfaceImport;
// R6Weapons.dll import @ 100060b8 : Engine.dll ?IsBlockedBy@AActor@@UBEHPBV1@@Z
extern uint AActorIsBlockedByImport;
// R6Weapons.dll import @ 100060c0 : Engine.dll ?ShouldTrace@AActor@@UAEHPAV1@K@Z
extern uint AActorShouldTraceImport;
// R6Weapons.dll import @ 100060c4 : Engine.dll ?PostNetReceive@AActor@@UAEXXZ
extern uint AActorPostNetReceiveImport;
// R6Weapons.dll import @ 100060c8 : Engine.dll ?GetProjectorBase@AActor@@UAEPAV1@XZ
extern uint AActorGetProjectorBaseImport;
// R6Weapons.dll import @ 100060cc : Engine.dll ?PostPath@AActor@@UAEXXZ
extern uint AActorPostPathImport;
// R6Weapons.dll import @ 100060d0 : Engine.dll ?PrePath@AActor@@UAEXXZ
extern uint AActorPrePathImport;
// R6Weapons.dll import @ 100060d4 : Engine.dll ?CheckForErrors@AActor@@UAEXXZ
extern uint AActorCheckForErrorsImport;
// R6Weapons.dll import @ 100060d8 : Engine.dll ?TickThisFrame@AActor@@UAEHM@Z
extern uint AActorTickThisFrameImport;
// R6Weapons.dll import @ 100060dc : Engine.dll ?IsRelevantToPawnHeartBeat@AActor@@UAEHPAVAPawn@@@Z
extern uint AActorIsRelevantToPawnHeartBeatImport;
// R6Weapons.dll import @ 100060e0 : Engine.dll ?IsRelevantToPawnHeatVision@AActor@@UAEHPAVAPawn@@@Z
extern uint AActorIsRelevantToPawnHeatVisionImport;
// R6Weapons.dll import @ 100060e4 : Engine.dll ?IsRelevantToPawnRadar@AActor@@UAEHPAVAPawn@@@Z
extern uint AActorIsRelevantToPawnRadarImport;
// R6Weapons.dll import @ 100060e8 : Engine.dll ?PlayAnim@AActor@@UAEXHVFName@@MMHHH@Z
extern uint AActorPlayAnimImport;
// R6Weapons.dll import @ 100060ec : Engine.dll ?HasAssociatedLevelGeometry@AActor@@UAEHPAV1@@Z
extern uint AActorHasAssociatedLevelGeometryImport;
// R6Weapons.dll import @ 100060f0 : Engine.dll ?AssociatedLevelGeometry@AActor@@UAEPAV1@XZ
extern uint AActorAssociatedLevelGeometryImport;
// R6Weapons.dll import @ 100060f4 : Engine.dll ?AddMyMarker@AActor@@UAEXPAV1@@Z
extern uint AActorAddMyMarkerImport;
// R6Weapons.dll import @ 100060f8 : Engine.dll ?KMP2DynKarmaInterface@AActor@@UAEHHVFVector@@VFRotator@@PAV1@@Z
extern uint AActorKMP2DynKarmaInterfaceImport;
// R6Weapons.dll import @ 100060fc : Engine.dll ?postKarmaStep@AActor@@UAEXXZ
extern uint AActorpostKarmaStepImport;
// R6Weapons.dll import @ 10006100 : Engine.dll ?preKarmaStep@AActor@@UAEXM@Z
extern uint AActorpreKarmaStepImport;
// R6Weapons.dll import @ 10006104 : Engine.dll ?physKarma@AActor@@UAEXM@Z
extern uint AActorphysKarmaImport;
// R6Weapons.dll import @ 10006108 : Engine.dll ?getKModel@AActor@@UBEPAU_McdModel@@XZ
extern uint AActorgetKModelImport;
// R6Weapons.dll import @ 1000610c : Engine.dll ?stepUp@AActor@@UAEXVFVector@@00AAUFCheckResult@@@Z
extern uint AActorstepUpImport;
// R6Weapons.dll import @ 10006110 : Engine.dll ?SmoothHitWall@AActor@@UAEXVFVector@@PAV1@@Z
extern uint AActorSmoothHitWallImport;
// R6Weapons.dll import @ 10006114 : Engine.dll ?FindSlopeRotation@AActor@@UAE?AVFRotator@@VFVector@@V2@@Z
extern uint AActorFindSlopeRotationImport;
// R6Weapons.dll import @ 10006118 : Engine.dll ?physFalling@AActor@@UAEXMH@Z
extern uint AActorphysFallingImport;
// R6Weapons.dll import @ 1000611c : Engine.dll ?processLanded@AActor@@UAEXVFVector@@PAV1@MH@Z
extern uint AActorprocessLandedImport;
// R6Weapons.dll import @ 10006120 : Engine.dll ?processHitWall@AActor@@UAEXVFVector@@PAV1@@Z
extern uint AActorprocessHitWallImport;
// R6Weapons.dll import @ 10006124 : Engine.dll ?BoundProjectileVelocity@AActor@@UAEXXZ
extern uint AActorBoundProjectileVelocityImport;
// R6Weapons.dll import @ 10006128 : Engine.dll ?performPhysics@AActor@@UAEXM@Z
extern uint AActorperformPhysicsImport;
// R6Weapons.dll import @ 1000612c : Engine.dll ?setPhysics@AActor@@UAEXEPAV1@VFVector@@@Z
extern uint AActorsetPhysicsImport;
// R6Weapons.dll import @ 10006130 : Engine.dll ?PostBeginPlay@AActor@@UAEXXZ
extern uint AActorPostBeginPlayImport;
// R6Weapons.dll import @ 10006134 : Engine.dll ?SetVolumes@AActor@@UAEXXZ
extern uint AActorSetVolumesImport;
// R6Weapons.dll import @ 10006138 : Engine.dll ?SetVolumes@AActor@@UAEXABV?$TArray@PAVAVolume@@@@@Z
extern uint AActorSetVolumesFromArrayImport;
// R6Weapons.dll import @ 1000613c : Engine.dll ?SetZone@AActor@@UAEXHH@Z
extern uint AActorSetZoneImport;
// R6Weapons.dll import @ 10006140 : Engine.dll
// ?RenderEditorSelected@AActor@@UAEXPAVFLevelSceneNode@@PAVFRenderInterface@@PAVFDynamicActor@@@Z
extern uint AActorRenderEditorSelectedImport;
// R6Weapons.dll import @ 10006144 : Engine.dll
// ?RenderEditorInfo@AActor@@UAEXPAVFLevelSceneNode@@PAVFRenderInterface@@PAVFDynamicActor@@@Z
extern uint AActorRenderEditorInfoImport;
// R6Weapons.dll import @ 10006148 : Engine.dll ?IsNetRelevantFor@AActor@@UAEHPAVAPlayerController@@PAV1@VFVector@@@Z
extern uint AActorIsNetRelevantForImport;
// R6Weapons.dll import @ 1000614c : Engine.dll ?PlayerControlled@AActor@@UAEHXZ
extern uint AActorPlayerControlledImport;
// R6Weapons.dll import @ 10006150 : Engine.dll ?TickSpecial@AActor@@UAEXM@Z
extern uint AActorTickSpecialImport;
// R6Weapons.dll import @ 10006154 : Engine.dll ?TickSimulated@AActor@@UAEXM@Z
extern uint AActorTickSimulatedImport;
// R6Weapons.dll import @ 10006158 : Engine.dll ?CheckOwnerUpdated@AActor@@UAEHXZ
extern uint AActorCheckOwnerUpdatedImport;
// R6Weapons.dll import @ 1000615c : Engine.dll ?UpdateTimers@AActor@@UAEXM@Z
extern uint AActorUpdateTimersImport;
// R6Weapons.dll import @ 10006160 : Engine.dll ?CheckAnimFinished@AActor@@UAEHH@Z
extern uint AActorCheckAnimFinishedImport;
// R6Weapons.dll import @ 10006164 : Engine.dll ?StartAnimPoll@AActor@@UAEXXZ
extern uint AActorStartAnimPollImport;
// R6Weapons.dll import @ 10006168 : Engine.dll ?UpdateAnimation@AActor@@UAEXM@Z
extern uint AActorUpdateAnimationImport;
// R6Weapons.dll import @ 1000616c : Engine.dll ?NotifyAnimEnd@AActor@@UAEXH@Z
extern uint AActorNotifyAnimEndImport;
// R6Weapons.dll import @ 10006170 : Engine.dll ?GetViewRotation@AActor@@UAE?AVFRotator@@XZ
extern uint AActorGetViewRotationImport;
// R6Weapons.dll import @ 10006174 : Engine.dll ?SetBase@AActor@@UAEXPAV1@VFVector@@H@Z
extern uint AActorSetBaseImport;
// R6Weapons.dll import @ 10006178 : Engine.dll ?NotifyBump@AActor@@UAEXPAV1@@Z
extern uint AActorNotifyBumpImport;
// R6Weapons.dll import @ 1000617c : Engine.dll ?IsMovingBrush@AActor@@UBEHXZ
extern uint AActorIsMovingBrushImport;
// R6Weapons.dll import @ 10006180 : Engine.dll ?BeginTouch@AActor@@UAEXPAV1@@Z
extern uint AActorBeginTouchImport;
// R6Weapons.dll import @ 10006184 : Engine.dll ?GetPrimitive@AActor@@UAEPAVUPrimitive@@XZ
extern uint AActorGetPrimitiveImport;
// R6Weapons.dll import @ 10006188 : Engine.dll ?PostScriptDestroyed@AActor@@UAEXXZ
extern uint AActorPostScriptDestroyedImport;
// R6Weapons.dll import @ 1000618c : Engine.dll ?UpdateColBox@AActor@@UAEXAAVFVector@@HHH@Z
extern uint AActorUpdateColBoxImport;
// R6Weapons.dll import @ 10006190 : Engine.dll ?WorldToLocal@AActor@@UBE?AVFMatrix@@XZ
extern uint AActorWorldToLocalImport;
// R6Weapons.dll import @ 10006194 : Engine.dll ?LocalToWorld@AActor@@UBE?AVFMatrix@@XZ
extern uint AActorLocalToWorldImport;
// R6Weapons.dll import @ 10006198 : Engine.dll ?ToWorld@AActor@@UBE?AVFCoords@@XZ
extern uint AActorToWorldImport;
// R6Weapons.dll import @ 1000619c : Engine.dll ?ToLocal@AActor@@UBE?AVFCoords@@XZ
extern uint AActorToLocalImport;
// R6Weapons.dll import @ 100061a0 : Engine.dll ?GetSkin@AActor@@UAEPAVUMaterial@@H@Z
extern uint AActorGetSkinImport;
// R6Weapons.dll import @ 100061a4 : Engine.dll ?PostNetReceiveLocation@AActor@@UAEXXZ
extern uint AActorPostNetReceiveLocationImport;
// R6Weapons.dll import @ 100061a8 : Engine.dll ?Spawned@AActor@@UAEXXZ
extern uint AActorSpawnedImport;
// R6Weapons.dll import @ 100061ac : Engine.dll ?PostRaytrace@AActor@@UAEXXZ
extern uint AActorPostRaytraceImport;
// R6Weapons.dll import @ 100061b0 : Engine.dll ?PreRaytrace@AActor@@UAEXXZ
extern uint AActorPreRaytraceImport;
// R6Weapons.dll import @ 100061b4 : Engine.dll ?PostEditLoad@AActor@@UAEXXZ
extern uint AActorPostEditLoadImport;
// R6Weapons.dll import @ 100061b8 : Engine.dll ?PostEditMove@AActor@@UAEXXZ
extern uint AActorPostEditMoveImport;
// R6Weapons.dll import @ 100061bc : Engine.dll ?Tick@AActor@@UAEHMW4ELevelTick@@@Z
extern uint AActorTickImport;
// R6Weapons.dll import @ 100061c0 : Engine.dll ?WorldLightRadius@AActor@@UBEMXZ
extern uint AActorWorldLightRadiusImport;
// R6Weapons.dll import @ 100061c4 : Engine.dll ?GetNetPriority@AActor@@UAEMPAV1@MM@Z
extern uint AActorGetNetPriorityImport;
// R6Weapons.dll import @ 100061c8 : Engine.dll ?GetPawnOrColBoxOwner@AActor@@UBEPAVAPawn@@XZ
extern uint AActorGetPawnOrColBoxOwnerImport;
// R6Weapons.dll import @ 100061cc : Engine.dll ?GetPlayerPawn@AActor@@UBEPAVAPawn@@XZ
extern uint AActorGetPlayerPawnImport;
// R6Weapons.dll import @ 100061d0 : Engine.dll
// ?GetOptimizedRepList@AActor@@UAEPAHPAEPAUFPropertyRetirement@@PAHPAVUPackageMap@@PAVUActorChannel@@@Z
extern uint AActorGetOptimizedRepListImport;
// R6Weapons.dll import @ 100061d4 : Engine.dll ?NetDirty@AActor@@UAEXPAVUProperty@@@Z
extern uint AActorNetDirtyImport;
// R6Weapons.dll import @ 100061d8 : Engine.dll ?IsPendingDelete@AActor@@UAEHXZ
extern uint AActorIsPendingDeleteImport;
// R6Weapons.dll import @ 100061dc : Engine.dll ?PostEditChange@AActor@@UAEXXZ
extern uint AActorPostEditChangeImport;
// R6Weapons.dll import @ 100061e0 : Engine.dll ?InitExecution@AActor@@UAEXXZ
extern uint AActorInitExecutionImport;
// R6Weapons.dll import @ 100061e4 : Engine.dll ?IsPendingKill@AActor@@UAEHXZ
extern uint AActorIsPendingKillImport;
// R6Weapons.dll import @ 100061e8 : Engine.dll ?Serialize@AActor@@UAEXAAVFArchive@@@Z
extern uint AActorSerializeImport;
// R6Weapons.dll import @ 100061ec : Engine.dll ?Destroy@AActor@@UAEXXZ
extern uint AActorDestroyImport;
// R6Weapons.dll import @ 100061f0 : Engine.dll ?PostLoad@AActor@@UAEXXZ
extern uint AActorPostLoadImport;
// R6Weapons.dll import @ 100061f4 : Engine.dll ?ProcessRemoteFunction@AActor@@UAEHPAVUFunction@@PAXPAUFFrame@@@Z
extern uint AActorProcessRemoteFunctionImport;
// R6Weapons.dll import @ 100061f8 : Engine.dll ?ProcessEvent@AActor@@UAEXPAVUFunction@@PAX1@Z
extern uint AActorProcessEventImport;
// R6Weapons.dll import @ 100061fc : Engine.dll ?TickAuthoritative@AActor@@UAEXM@Z
extern uint AActorTickAuthoritativeImport;
// R6Weapons.dll import @ 10006200 : Engine.dll ?PreNetReceive@AActor@@UAEXXZ
extern uint AActorPreNetReceiveImport;
// R6Weapons.dll import @ 10006204 : Engine.dll ?ProcessState@AActor@@UAEXM@Z
extern uint AActorProcessStateImport;

// Native entry-frame views for inherited virtual-method imports.
// Each naked jump retains ECX, stack arguments, return address and all imported return conventions unchanged.
// The empty source parameter lists are frame views, not replacement C++ declarations of the imported methods.

// R6Weapons.dll @ 10004dfe : forward UObject::GetPropertiesSize through the selected import
// Tail-jumps to Core.dll IAT 0x10006014 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectGetPropertiesSize(void) {
  __asm jmp dword ptr ds : [UObjectGetPropertiesSizeImport]
}

// R6Weapons.dll @ 10004e04 : forward UObject::LanguageChange through the selected import
// Tail-jumps to Core.dll IAT 0x10006018 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectLanguageChange(void) {
  __asm jmp dword ptr ds : [UObjectLanguageChangeImport]
}

// R6Weapons.dll @ 10004e0a : forward UObject::Register through the selected import
// Tail-jumps to Core.dll IAT 0x1000601c without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectRegister(void) {
  __asm jmp dword ptr ds : [UObjectRegisterImport]
}

// R6Weapons.dll @ 10004e10 : forward UObject::ScriptConsoleExec through the selected import
// Tail-jumps to Core.dll IAT 0x10006020 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectScriptConsoleExec(void) {
  __asm jmp dword ptr ds : [UObjectScriptConsoleExecImport]
}

// R6Weapons.dll @ 10004e16 : forward UObject::CallFunction through the selected import
// Tail-jumps to Core.dll IAT 0x10006024 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectCallFunction(void) {
  __asm jmp dword ptr ds : [UObjectCallFunctionImport]
}

// R6Weapons.dll @ 10004e1c : forward UObject::ShutdownAfterError through the selected import
// Tail-jumps to Core.dll IAT 0x10006028 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectShutdownAfterError(void) {
  __asm jmp dword ptr ds : [UObjectShutdownAfterErrorImport]
}

// R6Weapons.dll @ 10004e22 : forward UObject::GotoLabel through the selected import
// Tail-jumps to Core.dll IAT 0x1000602c without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectGotoLabel(void) {
  __asm jmp dword ptr ds : [UObjectGotoLabelImport]
}

// R6Weapons.dll @ 10004e28 : forward UObject::GotoState through the selected import
// Tail-jumps to Core.dll IAT 0x10006030 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectGotoState(void) {
  __asm jmp dword ptr ds : [UObjectGotoStateImport]
}

// R6Weapons.dll @ 10004e2e : forward UObject::Modify through the selected import
// Tail-jumps to Core.dll IAT 0x10006034 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectModify(void) {
  __asm jmp dword ptr ds : [UObjectModifyImport]
}

// R6Weapons.dll @ 10004e34 : forward UObject::ProcessDelegate through the selected import
// Tail-jumps to Core.dll IAT 0x10006038 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectProcessDelegate(void) {
  __asm jmp dword ptr ds : [UObjectProcessDelegateImport]
}

// R6Weapons.dll @ 10004e3a : forward UObject::Release through the selected import
// Tail-jumps to Core.dll IAT 0x1000603c without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectRelease(void) {
  __asm jmp dword ptr ds : [UObjectReleaseImport]
}

// R6Weapons.dll @ 10004e40 : forward UObject::AddRef through the selected import
// Tail-jumps to Core.dll IAT 0x10006040 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectAddRef(void) {
  __asm jmp dword ptr ds : [UObjectAddRefImport]
}

// R6Weapons.dll @ 10004e46 : forward UObject::QueryInterface through the selected import
// Tail-jumps to Core.dll IAT 0x10006044 without changing the native frame or result ABI.
__declspec(naked) void ForwardUObjectQueryInterface(void) {
  __asm jmp dword ptr ds : [UObjectQueryInterfaceImport]
}

// R6Weapons.dll @ 10004e4c : forward AActor::IsBlockedBy through the selected import
// Tail-jumps to Engine.dll IAT 0x100060b8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsBlockedBy(void) {
  __asm jmp dword ptr ds : [AActorIsBlockedByImport]
}

// R6Weapons.dll @ 10004e52 : forward AActor::ShouldTrace through the selected import
// Tail-jumps to Engine.dll IAT 0x100060c0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorShouldTrace(void) {
  __asm jmp dword ptr ds : [AActorShouldTraceImport]
}

// R6Weapons.dll @ 10004e58 : forward AActor::PostNetReceive through the selected import
// Tail-jumps to Engine.dll IAT 0x100060c4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostNetReceive(void) {
  __asm jmp dword ptr ds : [AActorPostNetReceiveImport]
}

// R6Weapons.dll @ 10004e5e : forward AActor::GetProjectorBase through the selected import
// Tail-jumps to Engine.dll IAT 0x100060c8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetProjectorBase(void) {
  __asm jmp dword ptr ds : [AActorGetProjectorBaseImport]
}

// R6Weapons.dll @ 10004e64 : forward AActor::PostPath through the selected import
// Tail-jumps to Engine.dll IAT 0x100060cc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostPath(void) {
  __asm jmp dword ptr ds : [AActorPostPathImport]
}

// R6Weapons.dll @ 10004e6a : forward AActor::PrePath through the selected import
// Tail-jumps to Engine.dll IAT 0x100060d0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPrePath(void) {
  __asm jmp dword ptr ds : [AActorPrePathImport]
}

// R6Weapons.dll @ 10004e70 : forward AActor::CheckForErrors through the selected import
// Tail-jumps to Engine.dll IAT 0x100060d4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorCheckForErrors(void) {
  __asm jmp dword ptr ds : [AActorCheckForErrorsImport]
}

// R6Weapons.dll @ 10004e76 : forward AActor::TickThisFrame through the selected import
// Tail-jumps to Engine.dll IAT 0x100060d8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorTickThisFrame(void) {
  __asm jmp dword ptr ds : [AActorTickThisFrameImport]
}

// R6Weapons.dll @ 10004e7c : forward AActor::IsRelevantToPawnHeartBeat through the selected import
// Tail-jumps to Engine.dll IAT 0x100060dc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsRelevantToPawnHeartBeat(void) {
  __asm jmp dword ptr ds : [AActorIsRelevantToPawnHeartBeatImport]
}

// R6Weapons.dll @ 10004e82 : forward AActor::IsRelevantToPawnHeatVision through the selected import
// Tail-jumps to Engine.dll IAT 0x100060e0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsRelevantToPawnHeatVision(void) {
  __asm jmp dword ptr ds : [AActorIsRelevantToPawnHeatVisionImport]
}

// R6Weapons.dll @ 10004e88 : forward AActor::IsRelevantToPawnRadar through the selected import
// Tail-jumps to Engine.dll IAT 0x100060e4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsRelevantToPawnRadar(void) {
  __asm jmp dword ptr ds : [AActorIsRelevantToPawnRadarImport]
}

// R6Weapons.dll @ 10004e8e : forward AActor::PlayAnim through the selected import
// Tail-jumps to Engine.dll IAT 0x100060e8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPlayAnim(void) {
  __asm jmp dword ptr ds : [AActorPlayAnimImport]
}

// R6Weapons.dll @ 10004e94 : forward AActor::HasAssociatedLevelGeometry through the selected import
// Tail-jumps to Engine.dll IAT 0x100060ec without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorHasAssociatedLevelGeometry(void) {
  __asm jmp dword ptr ds : [AActorHasAssociatedLevelGeometryImport]
}

// R6Weapons.dll @ 10004e9a : forward AActor::AssociatedLevelGeometry through the selected import
// Tail-jumps to Engine.dll IAT 0x100060f0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorAssociatedLevelGeometry(void) {
  __asm jmp dword ptr ds : [AActorAssociatedLevelGeometryImport]
}

// R6Weapons.dll @ 10004ea0 : forward AActor::AddMyMarker through the selected import
// Tail-jumps to Engine.dll IAT 0x100060f4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorAddMyMarker(void) {
  __asm jmp dword ptr ds : [AActorAddMyMarkerImport]
}

// R6Weapons.dll @ 10004ea6 : forward AActor::KMP2DynKarmaInterface through the selected import
// Tail-jumps to Engine.dll IAT 0x100060f8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorKMP2DynKarmaInterface(void) {
  __asm jmp dword ptr ds : [AActorKMP2DynKarmaInterfaceImport]
}

// R6Weapons.dll @ 10004eac : forward AActor::postKarmaStep through the selected import
// Tail-jumps to Engine.dll IAT 0x100060fc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorpostKarmaStep(void) {
  __asm jmp dword ptr ds : [AActorpostKarmaStepImport]
}

// R6Weapons.dll @ 10004eb2 : forward AActor::preKarmaStep through the selected import
// Tail-jumps to Engine.dll IAT 0x10006100 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorpreKarmaStep(void) {
  __asm jmp dword ptr ds : [AActorpreKarmaStepImport]
}

// R6Weapons.dll @ 10004eb8 : forward AActor::physKarma through the selected import
// Tail-jumps to Engine.dll IAT 0x10006104 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorphysKarma(void) {
  __asm jmp dword ptr ds : [AActorphysKarmaImport]
}

// R6Weapons.dll @ 10004ebe : forward AActor::getKModel through the selected import
// Tail-jumps to Engine.dll IAT 0x10006108 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorgetKModel(void) {
  __asm jmp dword ptr ds : [AActorgetKModelImport]
}

// R6Weapons.dll @ 10004ec4 : forward AActor::stepUp through the selected import
// Tail-jumps to Engine.dll IAT 0x1000610c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorstepUp(void) {
  __asm jmp dword ptr ds : [AActorstepUpImport]
}

// R6Weapons.dll @ 10004eca : forward AActor::SmoothHitWall through the selected import
// Tail-jumps to Engine.dll IAT 0x10006110 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSmoothHitWall(void) {
  __asm jmp dword ptr ds : [AActorSmoothHitWallImport]
}

// R6Weapons.dll @ 10004ed0 : forward AActor::FindSlopeRotation through the selected import
// Tail-jumps to Engine.dll IAT 0x10006114 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorFindSlopeRotation(void) {
  __asm jmp dword ptr ds : [AActorFindSlopeRotationImport]
}

// R6Weapons.dll @ 10004ed6 : forward AActor::physFalling through the selected import
// Tail-jumps to Engine.dll IAT 0x10006118 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorphysFalling(void) {
  __asm jmp dword ptr ds : [AActorphysFallingImport]
}

// R6Weapons.dll @ 10004edc : forward AActor::processLanded through the selected import
// Tail-jumps to Engine.dll IAT 0x1000611c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorprocessLanded(void) {
  __asm jmp dword ptr ds : [AActorprocessLandedImport]
}

// R6Weapons.dll @ 10004ee2 : forward AActor::processHitWall through the selected import
// Tail-jumps to Engine.dll IAT 0x10006120 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorprocessHitWall(void) {
  __asm jmp dword ptr ds : [AActorprocessHitWallImport]
}

// R6Weapons.dll @ 10004ee8 : forward AActor::BoundProjectileVelocity through the selected import
// Tail-jumps to Engine.dll IAT 0x10006124 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorBoundProjectileVelocity(void) {
  __asm jmp dword ptr ds : [AActorBoundProjectileVelocityImport]
}

// R6Weapons.dll @ 10004eee : forward AActor::performPhysics through the selected import
// Tail-jumps to Engine.dll IAT 0x10006128 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorperformPhysics(void) {
  __asm jmp dword ptr ds : [AActorperformPhysicsImport]
}

// R6Weapons.dll @ 10004ef4 : forward AActor::setPhysics through the selected import
// Tail-jumps to Engine.dll IAT 0x1000612c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorsetPhysics(void) {
  __asm jmp dword ptr ds : [AActorsetPhysicsImport]
}

// R6Weapons.dll @ 10004efa : forward AActor::PostBeginPlay through the selected import
// Tail-jumps to Engine.dll IAT 0x10006130 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostBeginPlay(void) {
  __asm jmp dword ptr ds : [AActorPostBeginPlayImport]
}

// R6Weapons.dll @ 10004f00 : forward AActor::SetVolumes through the selected import
// Tail-jumps to Engine.dll IAT 0x10006134 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSetVolumes(void) {
  __asm jmp dword ptr ds : [AActorSetVolumesImport]
}

// R6Weapons.dll @ 10004f06 : forward AActor::SetVolumes through the selected import
// Tail-jumps to Engine.dll IAT 0x10006138 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSetVolumesFromArray(void) {
  __asm jmp dword ptr ds : [AActorSetVolumesFromArrayImport]
}

// R6Weapons.dll @ 10004f0c : forward AActor::SetZone through the selected import
// Tail-jumps to Engine.dll IAT 0x1000613c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSetZone(void) {
  __asm jmp dword ptr ds : [AActorSetZoneImport]
}

// R6Weapons.dll @ 10004f12 : forward AActor::RenderEditorSelected through the selected import
// Tail-jumps to Engine.dll IAT 0x10006140 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorRenderEditorSelected(void) {
  __asm jmp dword ptr ds : [AActorRenderEditorSelectedImport]
}

// R6Weapons.dll @ 10004f18 : forward AActor::RenderEditorInfo through the selected import
// Tail-jumps to Engine.dll IAT 0x10006144 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorRenderEditorInfo(void) {
  __asm jmp dword ptr ds : [AActorRenderEditorInfoImport]
}

// R6Weapons.dll @ 10004f1e : forward AActor::IsNetRelevantFor through the selected import
// Tail-jumps to Engine.dll IAT 0x10006148 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsNetRelevantFor(void) {
  __asm jmp dword ptr ds : [AActorIsNetRelevantForImport]
}

// R6Weapons.dll @ 10004f24 : forward AActor::PlayerControlled through the selected import
// Tail-jumps to Engine.dll IAT 0x1000614c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPlayerControlled(void) {
  __asm jmp dword ptr ds : [AActorPlayerControlledImport]
}

// R6Weapons.dll @ 10004f2a : forward AActor::TickSpecial through the selected import
// Tail-jumps to Engine.dll IAT 0x10006150 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorTickSpecial(void) {
  __asm jmp dword ptr ds : [AActorTickSpecialImport]
}

// R6Weapons.dll @ 10004f30 : forward AActor::TickSimulated through the selected import
// Tail-jumps to Engine.dll IAT 0x10006154 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorTickSimulated(void) {
  __asm jmp dword ptr ds : [AActorTickSimulatedImport]
}

// R6Weapons.dll @ 10004f36 : forward AActor::CheckOwnerUpdated through the selected import
// Tail-jumps to Engine.dll IAT 0x10006158 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorCheckOwnerUpdated(void) {
  __asm jmp dword ptr ds : [AActorCheckOwnerUpdatedImport]
}

// R6Weapons.dll @ 10004f3c : forward AActor::UpdateTimers through the selected import
// Tail-jumps to Engine.dll IAT 0x1000615c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorUpdateTimers(void) {
  __asm jmp dword ptr ds : [AActorUpdateTimersImport]
}

// R6Weapons.dll @ 10004f42 : forward AActor::CheckAnimFinished through the selected import
// Tail-jumps to Engine.dll IAT 0x10006160 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorCheckAnimFinished(void) {
  __asm jmp dword ptr ds : [AActorCheckAnimFinishedImport]
}

// R6Weapons.dll @ 10004f48 : forward AActor::StartAnimPoll through the selected import
// Tail-jumps to Engine.dll IAT 0x10006164 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorStartAnimPoll(void) {
  __asm jmp dword ptr ds : [AActorStartAnimPollImport]
}

// R6Weapons.dll @ 10004f4e : forward AActor::UpdateAnimation through the selected import
// Tail-jumps to Engine.dll IAT 0x10006168 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorUpdateAnimation(void) {
  __asm jmp dword ptr ds : [AActorUpdateAnimationImport]
}

// R6Weapons.dll @ 10004f54 : forward AActor::NotifyAnimEnd through the selected import
// Tail-jumps to Engine.dll IAT 0x1000616c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorNotifyAnimEnd(void) {
  __asm jmp dword ptr ds : [AActorNotifyAnimEndImport]
}

// R6Weapons.dll @ 10004f5a : forward AActor::GetViewRotation through the selected import
// Tail-jumps to Engine.dll IAT 0x10006170 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetViewRotation(void) {
  __asm jmp dword ptr ds : [AActorGetViewRotationImport]
}

// R6Weapons.dll @ 10004f60 : forward AActor::SetBase through the selected import
// Tail-jumps to Engine.dll IAT 0x10006174 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSetBase(void) {
  __asm jmp dword ptr ds : [AActorSetBaseImport]
}

// R6Weapons.dll @ 10004f66 : forward AActor::NotifyBump through the selected import
// Tail-jumps to Engine.dll IAT 0x10006178 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorNotifyBump(void) {
  __asm jmp dword ptr ds : [AActorNotifyBumpImport]
}

// R6Weapons.dll @ 10004f6c : forward AActor::IsMovingBrush through the selected import
// Tail-jumps to Engine.dll IAT 0x1000617c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsMovingBrush(void) {
  __asm jmp dword ptr ds : [AActorIsMovingBrushImport]
}

// R6Weapons.dll @ 10004f72 : forward AActor::BeginTouch through the selected import
// Tail-jumps to Engine.dll IAT 0x10006180 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorBeginTouch(void) {
  __asm jmp dword ptr ds : [AActorBeginTouchImport]
}

// R6Weapons.dll @ 10004f78 : forward AActor::GetPrimitive through the selected import
// Tail-jumps to Engine.dll IAT 0x10006184 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetPrimitive(void) {
  __asm jmp dword ptr ds : [AActorGetPrimitiveImport]
}

// R6Weapons.dll @ 10004f7e : forward AActor::PostScriptDestroyed through the selected import
// Tail-jumps to Engine.dll IAT 0x10006188 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostScriptDestroyed(void) {
  __asm jmp dword ptr ds : [AActorPostScriptDestroyedImport]
}

// R6Weapons.dll @ 10004f84 : forward AActor::UpdateColBox through the selected import
// Tail-jumps to Engine.dll IAT 0x1000618c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorUpdateColBox(void) {
  __asm jmp dword ptr ds : [AActorUpdateColBoxImport]
}

// R6Weapons.dll @ 10004f8a : forward AActor::WorldToLocal through the selected import
// Tail-jumps to Engine.dll IAT 0x10006190 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorWorldToLocal(void) {
  __asm jmp dword ptr ds : [AActorWorldToLocalImport]
}

// R6Weapons.dll @ 10004f90 : forward AActor::LocalToWorld through the selected import
// Tail-jumps to Engine.dll IAT 0x10006194 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorLocalToWorld(void) {
  __asm jmp dword ptr ds : [AActorLocalToWorldImport]
}

// R6Weapons.dll @ 10004f96 : forward AActor::ToWorld through the selected import
// Tail-jumps to Engine.dll IAT 0x10006198 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorToWorld(void) {
  __asm jmp dword ptr ds : [AActorToWorldImport]
}

// R6Weapons.dll @ 10004f9c : forward AActor::ToLocal through the selected import
// Tail-jumps to Engine.dll IAT 0x1000619c without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorToLocal(void) {
  __asm jmp dword ptr ds : [AActorToLocalImport]
}

// R6Weapons.dll @ 10004fa2 : forward AActor::GetSkin through the selected import
// Tail-jumps to Engine.dll IAT 0x100061a0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetSkin(void) {
  __asm jmp dword ptr ds : [AActorGetSkinImport]
}

// R6Weapons.dll @ 10004fa8 : forward AActor::PostNetReceiveLocation through the selected import
// Tail-jumps to Engine.dll IAT 0x100061a4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostNetReceiveLocation(void) {
  __asm jmp dword ptr ds : [AActorPostNetReceiveLocationImport]
}

// R6Weapons.dll @ 10004fae : forward AActor::Spawned through the selected import
// Tail-jumps to Engine.dll IAT 0x100061a8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSpawned(void) {
  __asm jmp dword ptr ds : [AActorSpawnedImport]
}

// R6Weapons.dll @ 10004fb4 : forward AActor::PostRaytrace through the selected import
// Tail-jumps to Engine.dll IAT 0x100061ac without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostRaytrace(void) {
  __asm jmp dword ptr ds : [AActorPostRaytraceImport]
}

// R6Weapons.dll @ 10004fba : forward AActor::PreRaytrace through the selected import
// Tail-jumps to Engine.dll IAT 0x100061b0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPreRaytrace(void) {
  __asm jmp dword ptr ds : [AActorPreRaytraceImport]
}

// R6Weapons.dll @ 10004fc0 : forward AActor::PostEditLoad through the selected import
// Tail-jumps to Engine.dll IAT 0x100061b4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostEditLoad(void) {
  __asm jmp dword ptr ds : [AActorPostEditLoadImport]
}

// R6Weapons.dll @ 10004fc6 : forward AActor::PostEditMove through the selected import
// Tail-jumps to Engine.dll IAT 0x100061b8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostEditMove(void) {
  __asm jmp dword ptr ds : [AActorPostEditMoveImport]
}

// R6Weapons.dll @ 10004fcc : forward AActor::Tick through the selected import
// Tail-jumps to Engine.dll IAT 0x100061bc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorTick(void) {
  __asm jmp dword ptr ds : [AActorTickImport]
}

// R6Weapons.dll @ 10004fd2 : forward AActor::WorldLightRadius through the selected import
// Tail-jumps to Engine.dll IAT 0x100061c0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorWorldLightRadius(void) {
  __asm jmp dword ptr ds : [AActorWorldLightRadiusImport]
}

// R6Weapons.dll @ 10004fd8 : forward AActor::GetNetPriority through the selected import
// Tail-jumps to Engine.dll IAT 0x100061c4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetNetPriority(void) {
  __asm jmp dword ptr ds : [AActorGetNetPriorityImport]
}

// R6Weapons.dll @ 10004fde : forward AActor::GetPawnOrColBoxOwner through the selected import
// Tail-jumps to Engine.dll IAT 0x100061c8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetPawnOrColBoxOwner(void) {
  __asm jmp dword ptr ds : [AActorGetPawnOrColBoxOwnerImport]
}

// R6Weapons.dll @ 10004fe4 : forward AActor::GetPlayerPawn through the selected import
// Tail-jumps to Engine.dll IAT 0x100061cc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetPlayerPawn(void) {
  __asm jmp dword ptr ds : [AActorGetPlayerPawnImport]
}

// R6Weapons.dll @ 10004fea : forward AActor::GetOptimizedRepList through the selected import
// Tail-jumps to Engine.dll IAT 0x100061d0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorGetOptimizedRepList(void) {
  __asm jmp dword ptr ds : [AActorGetOptimizedRepListImport]
}

// R6Weapons.dll @ 10004ff0 : forward AActor::NetDirty through the selected import
// Tail-jumps to Engine.dll IAT 0x100061d4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorNetDirty(void) {
  __asm jmp dword ptr ds : [AActorNetDirtyImport]
}

// R6Weapons.dll @ 10004ff6 : forward AActor::IsPendingDelete through the selected import
// Tail-jumps to Engine.dll IAT 0x100061d8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsPendingDelete(void) {
  __asm jmp dword ptr ds : [AActorIsPendingDeleteImport]
}

// R6Weapons.dll @ 10004ffc : forward AActor::PostEditChange through the selected import
// Tail-jumps to Engine.dll IAT 0x100061dc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostEditChange(void) {
  __asm jmp dword ptr ds : [AActorPostEditChangeImport]
}

// R6Weapons.dll @ 10005002 : forward AActor::InitExecution through the selected import
// Tail-jumps to Engine.dll IAT 0x100061e0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorInitExecution(void) {
  __asm jmp dword ptr ds : [AActorInitExecutionImport]
}

// R6Weapons.dll @ 10005008 : forward AActor::IsPendingKill through the selected import
// Tail-jumps to Engine.dll IAT 0x100061e4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorIsPendingKill(void) {
  __asm jmp dword ptr ds : [AActorIsPendingKillImport]
}

// R6Weapons.dll @ 1000500e : forward AActor::Serialize through the selected import
// Tail-jumps to Engine.dll IAT 0x100061e8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorSerialize(void) {
  __asm jmp dword ptr ds : [AActorSerializeImport]
}

// R6Weapons.dll @ 10005014 : forward AActor::Destroy through the selected import
// Tail-jumps to Engine.dll IAT 0x100061ec without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorDestroy(void) {
  __asm jmp dword ptr ds : [AActorDestroyImport]
}

// R6Weapons.dll @ 1000501a : forward AActor::PostLoad through the selected import
// Tail-jumps to Engine.dll IAT 0x100061f0 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPostLoad(void) {
  __asm jmp dword ptr ds : [AActorPostLoadImport]
}

// R6Weapons.dll @ 10005020 : forward AActor::ProcessRemoteFunction through the selected import
// Tail-jumps to Engine.dll IAT 0x100061f4 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorProcessRemoteFunction(void) {
  __asm jmp dword ptr ds : [AActorProcessRemoteFunctionImport]
}

// R6Weapons.dll @ 10005026 : forward AActor::ProcessEvent through the selected import
// Tail-jumps to Engine.dll IAT 0x100061f8 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorProcessEvent(void) {
  __asm jmp dword ptr ds : [AActorProcessEventImport]
}

// R6Weapons.dll @ 1000502c : forward AActor::TickAuthoritative through the selected import
// Tail-jumps to Engine.dll IAT 0x100061fc without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorTickAuthoritative(void) {
  __asm jmp dword ptr ds : [AActorTickAuthoritativeImport]
}

// R6Weapons.dll @ 10005032 : forward AActor::PreNetReceive through the selected import
// Tail-jumps to Engine.dll IAT 0x10006200 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorPreNetReceive(void) {
  __asm jmp dword ptr ds : [AActorPreNetReceiveImport]
}

// R6Weapons.dll @ 10005038 : forward AActor::ProcessState through the selected import
// Tail-jumps to Engine.dll IAT 0x10006204 without changing the native frame or result ABI.
__declspec(naked) void ForwardAActorProcessState(void) {
  __asm jmp dword ptr ds : [AActorProcessStateImport]
}
