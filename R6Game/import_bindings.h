#pragma once

// Selected PE32 IAT cell addresses. These constants/views name existing loader-owned words; they allocate no copy.
// On disk nonzero words contain import-by-name RVAs; the loader replaces them with provider addresses.
// Provider symbol/prototype evidence and initial lookup words are recorded in the module native-data ledger/evidence.
namespace R6GameImports {
// R6Game.dll data @ 10016000 : Core.dll Core_UObject_Constructor_10016000 import address word
constexpr unsigned int Core_UObject_DefaultConstructorSlot = 0x10016000;

// R6Game.dll data @ 10016004 : Core.dll Core_appItoa import address word
constexpr unsigned int Core_appItoaSlot = 0x10016004;

// R6Game.dll data @ 10016008 : Core.dll Core_GWarn import address word
constexpr unsigned int Core_GWarnSlot = 0x10016008;

// R6Game.dll data @ 1001600c : Core.dll Core_UObject_IsA import address word
constexpr unsigned int Core_UObject_IsASlot = 0x1001600c;

// R6Game.dll data @ 10016010 : Core.dll Core_UObject_StaticFindObject import address word
constexpr unsigned int Core_UObject_StaticFindObjectSlot = 0x10016010;

// R6Game.dll data @ 10016014 : Core.dll Core_FCoords_OperatorDivide import address word
constexpr unsigned int Core_FCoords_OperatorDivideSlot = 0x10016014;

// R6Game.dll data @ 10016018 : Core.dll Core_appMemset import address word
constexpr unsigned int Core_appMemsetSlot = 0x10016018;

// R6Game.dll data @ 1001601c : Core.dll Core_FMatrix_Coords import address word
constexpr unsigned int Core_FMatrix_CoordsSlot = 0x1001601c;

// R6Game.dll data @ 10016020 : Core.dll Core_appSqrt import address word
constexpr unsigned int Core_appSqrtSlot = 0x10016020;

// R6Game.dll data @ 10016024 : Core.dll Core_appSprintf import address word
constexpr unsigned int Core_appSprintfSlot = 0x10016024;

// R6Game.dll data @ 10016028 : Core.dll Core_FRotator_Vector import address word
constexpr unsigned int Core_FRotator_VectorSlot = 0x10016028;

// R6Game.dll data @ 1001602c : Core.dll Core_FVector_Size import address word
constexpr unsigned int Core_FVector_SizeSlot = 0x1001602c;

// R6Game.dll data @ 10016030 : Core.dll Core_appCos import address word
constexpr unsigned int Core_appCosSlot = 0x10016030;

// R6Game.dll data @ 10016034 : Core.dll Core_appAcos import address word
constexpr unsigned int Core_appAcosSlot = 0x10016034;

// R6Game.dll data @ 10016038 : Core.dll Core_Localize import address word
constexpr unsigned int Core_LocalizeSlot = 0x10016038;

// R6Game.dll data @ 1001603c : Core.dll Core_FStringNoInit_OperatorAssign_1001603c import address word
constexpr unsigned int Core_FStringNoInit_AssignTextSlot = 0x1001603c;

// R6Game.dll data @ 10016040 : Core.dll Core_FString_OperatorAppendAssign_10016040 import address word
constexpr unsigned int Core_FString_OperatorAppendAssignTextSlot = 0x10016040;

// R6Game.dll data @ 10016044 : Core.dll Core_GIsSSE import address word
constexpr unsigned int Core_GIsSSESlot = 0x10016044;

// R6Game.dll data @ 10016048 : Core.dll Core_appUnwindf import address word
constexpr unsigned int Core_appUnwindfSlot = 0x10016048;

// R6Game.dll data @ 1001604c : Core.dll Core_FOutputDevice_Logf import address word
constexpr unsigned int Core_FOutputDevice_LogfSlot = 0x1001604c;

// R6Game.dll data @ 10016050 : Core.dll Core_GLog import address word
constexpr unsigned int Core_GLogSlot = 0x10016050;

// R6Game.dll data @ 10016054 : Core.dll Core_GMalloc import address word
constexpr unsigned int Core_GMallocSlot = 0x10016054;

// R6Game.dll data @ 10016058 : Core.dll Core_UObject_GetFullName import address word
constexpr unsigned int Core_UObject_GetFullNameSlot = 0x10016058;

// R6Game.dll data @ 1001605c : Core.dll Core_FString_Constructor_1001605c import address word
constexpr unsigned int Core_FString_CopyConstructorSlot = 0x1001605c;

// R6Game.dll data @ 10016060 : Core.dll Core_GNatives import address word
constexpr unsigned int Core_GNativesSlot = 0x10016060;

// R6Game.dll data @ 10016064 : Core.dll Core_FString_Destructor import address word
constexpr unsigned int Core_FString_DestructorSlot = 0x10016064;

// R6Game.dll data @ 10016068 : Core.dll Core_FString_OperatorAssign_10016068 import address word
constexpr unsigned int Core_FString_AssignTextSlot = 0x10016068;

// R6Game.dll data @ 1001606c : Core.dll Core_appUserName import address word
constexpr unsigned int Core_appUserNameSlot = 0x1001606c;

// R6Game.dll data @ 10016070 : Core.dll Core_GProperty import address word
constexpr unsigned int Core_GPropertySlot = 0x10016070;

// R6Game.dll data @ 10016074 : Core.dll Core_GPropObject import address word
constexpr unsigned int Core_GPropObjectSlot = 0x10016074;

// R6Game.dll data @ 10016078 : Core.dll Core_GPropAddr import address word
constexpr unsigned int Core_GPropAddrSlot = 0x10016078;

// R6Game.dll data @ 1001607c : Core.dll Core_FString_Constructor_1001607c import address word
constexpr unsigned int Core_FString_DefaultConstructorSlot = 0x1001607c;

// R6Game.dll data @ 10016080 : Core.dll Core_UClass_GetDefaultActor import address word
constexpr unsigned int Core_UClass_GetDefaultActorSlot = 0x10016080;

// R6Game.dll data @ 10016084 : Core.dll Core_FArray_Remove import address word
constexpr unsigned int Core_FArray_RemoveSlot = 0x10016084;

// R6Game.dll data @ 10016088 : Core.dll Core_appFailAssert import address word
constexpr unsigned int Core_appFailAssertSlot = 0x10016088;

// R6Game.dll data @ 1001608c : Core.dll Core_FArray_Realloc import address word
constexpr unsigned int Core_FArray_ReallocSlot = 0x1001608c;

// R6Game.dll data @ 10016090 : Core.dll Core_FArray_Add import address word
constexpr unsigned int Core_FArray_AddSlot = 0x10016090;

// R6Game.dll data @ 10016094 : Core.dll Core_UObject_StaticConstructObject import address word
constexpr unsigned int Core_UObject_StaticConstructObjectSlot = 0x10016094;

// R6Game.dll data @ 10016098 : Core.dll Core_GError import address word
constexpr unsigned int Core_GErrorSlot = 0x10016098;

// R6Game.dll data @ 1001609c : Core.dll Core_UObject_GetTransientPackage import address word
constexpr unsigned int Core_UObject_GetTransientPackageSlot = 0x1001609c;

// R6Game.dll data @ 100160a0 : Core.dll Core_UObject_StaticAllocateObject import address word
constexpr unsigned int Core_UObject_StaticAllocateObjectSlot = 0x100160a0;

// R6Game.dll data @ 100160a4 : Core.dll Core_UObject_GetPropertiesSize import address word
constexpr unsigned int Core_UObject_GetPropertiesSizeSlot = 0x100160a4;

// R6Game.dll data @ 100160a8 : Core.dll Core_UObject_LanguageChange import address word
constexpr unsigned int Core_UObject_LanguageChangeSlot = 0x100160a8;

// R6Game.dll data @ 100160ac : Core.dll Core_UObject_Register import address word
constexpr unsigned int Core_UObject_RegisterSlot = 0x100160ac;

// R6Game.dll data @ 100160b0 : Core.dll Core_UObject_ScriptConsoleExec import address word
constexpr unsigned int Core_UObject_ScriptConsoleExecSlot = 0x100160b0;

// R6Game.dll data @ 100160b4 : Core.dll Core_UObject_CallFunction import address word
constexpr unsigned int Core_UObject_CallFunctionSlot = 0x100160b4;

// R6Game.dll data @ 100160b8 : Core.dll Core_UObject_ShutdownAfterError import address word
constexpr unsigned int Core_UObject_ShutdownAfterErrorSlot = 0x100160b8;

// R6Game.dll data @ 100160bc : Core.dll Core_UObject_GotoLabel import address word
constexpr unsigned int Core_UObject_GotoLabelSlot = 0x100160bc;

// R6Game.dll data @ 100160c0 : Core.dll Core_UObject_GotoState import address word
constexpr unsigned int Core_UObject_GotoStateSlot = 0x100160c0;

// R6Game.dll data @ 100160c4 : Core.dll Core_UObject_Modify import address word
constexpr unsigned int Core_UObject_ModifySlot = 0x100160c4;

// R6Game.dll data @ 100160c8 : Core.dll Core_UObject_ProcessDelegate import address word
constexpr unsigned int Core_UObject_ProcessDelegateSlot = 0x100160c8;

// R6Game.dll data @ 100160cc : Core.dll Core_UObject_Release import address word
constexpr unsigned int Core_UObject_ReleaseSlot = 0x100160cc;

// R6Game.dll data @ 100160d0 : Core.dll Core_UObject_AddRef import address word
constexpr unsigned int Core_UObject_AddRefSlot = 0x100160d0;

// R6Game.dll data @ 100160d4 : Core.dll Core_UObject_QueryInterface import address word
constexpr unsigned int Core_UObject_QueryInterfaceSlot = 0x100160d4;

// R6Game.dll data @ 100160d8 : Core.dll Core_UObject_ConditionalDestroy import address word
constexpr unsigned int Core_UObject_ConditionalDestroySlot = 0x100160d8;

// R6Game.dll data @ 100160dc : Core.dll Core_UObject_OperatorDelete import address word
constexpr unsigned int Core_UObject_OperatorDeleteSlot = 0x100160dc;

// R6Game.dll data @ 100160e0 : Core.dll Core_UObject_NetDirty import address word
constexpr unsigned int Core_UObject_NetDirtySlot = 0x100160e0;

// R6Game.dll data @ 100160e4 : Core.dll Core_UObject_IsPendingDelete import address word
constexpr unsigned int Core_UObject_IsPendingDeleteSlot = 0x100160e4;

// R6Game.dll data @ 100160e8 : Core.dll Core_UObject_PostEditChange import address word
constexpr unsigned int Core_UObject_PostEditChangeSlot = 0x100160e8;

// R6Game.dll data @ 100160ec : Core.dll Core_UObject_InitExecution import address word
constexpr unsigned int Core_UObject_InitExecutionSlot = 0x100160ec;

// R6Game.dll data @ 100160f0 : Core.dll Core_UObject_IsPendingKill import address word
constexpr unsigned int Core_UObject_IsPendingKillSlot = 0x100160f0;

// R6Game.dll data @ 100160f4 : Core.dll Core_UObject_Serialize import address word
constexpr unsigned int Core_UObject_SerializeSlot = 0x100160f4;

// R6Game.dll data @ 100160f8 : Core.dll Core_UObject_Destroy import address word
constexpr unsigned int Core_UObject_DestroySlot = 0x100160f8;

// R6Game.dll data @ 100160fc : Core.dll Core_UObject_PostLoad import address word
constexpr unsigned int Core_UObject_PostLoadSlot = 0x100160fc;

// R6Game.dll data @ 10016100 : Core.dll Core_UObject_ProcessRemoteFunction import address word
constexpr unsigned int Core_UObject_ProcessRemoteFunctionSlot = 0x10016100;

// R6Game.dll data @ 10016104 : Core.dll Core_UObject_ProcessState import address word
constexpr unsigned int Core_UObject_ProcessStateSlot = 0x10016104;

// R6Game.dll data @ 10016108 : Core.dll Core_UObject_ProcessEvent import address word
constexpr unsigned int Core_UObject_ProcessEventSlot = 0x10016108;

// R6Game.dll data @ 1001610c : Core.dll Core_UObject_Destructor import address word
constexpr unsigned int Core_UObject_DestructorSlot = 0x1001610c;

// R6Game.dll data @ 10016110 : Core.dll Core_FStringNoInit_Destructor import address word
constexpr unsigned int Core_FStringNoInit_DestructorSlot = 0x10016110;

// R6Game.dll data @ 10016114 : Core.dll Core_FStringNoInit_Constructor_10016114 import address word
constexpr unsigned int Core_FStringNoInit_DefaultConstructorSlot = 0x10016114;

// R6Game.dll data @ 10016118 : Core.dll Core_FStringNoInit_Constructor_10016118 import address word
constexpr unsigned int Core_FStringNoInit_CopyConstructorSlot = 0x10016118;

// R6Game.dll data @ 1001611c : Core.dll Core_UObject_Constructor_1001611c import address word
constexpr unsigned int Core_UObject_CopyConstructorSlot = 0x1001611c;

// R6Game.dll data @ 10016120 : Core.dll Core_FStringNoInit_OperatorAssign_10016120 import address word
constexpr unsigned int import_bindings_Core_FStringNoInit_AssignFStringSlot1 = 0x10016120;

// R6Game.dll data @ 10016124 : Core.dll Core_UObject_OperatorAssign import address word
constexpr unsigned int Core_UObject_OperatorAssignSlot = 0x10016124;

// R6Game.dll data @ 10016128 : Core.dll Core_appAtoi import address word
constexpr unsigned int Core_appAtoiSlot = 0x10016128;

// R6Game.dll data @ 1001612c : Core.dll Core_FString_OperatorAssign_1001612c import address word
constexpr unsigned int Core_FString_AssignFStringSlot = 0x1001612c;

// R6Game.dll data @ 10016130 : Core.dll Core_FString_Mid import address word
constexpr unsigned int Core_FString_MidSlot = 0x10016130;

// R6Game.dll data @ 10016134 : Core.dll Core_FString_InStr import address word
constexpr unsigned int Core_FString_InStrSlot = 0x10016134;

// R6Game.dll data @ 10016138 : Core.dll Core_FString_Printf import address word
constexpr unsigned int Core_FString_PrintfSlot = 0x10016138;

// R6Game.dll data @ 1001613c : Core.dll Core_FString_OperatorMultiply import address word
constexpr unsigned int Core_FString_OperatorMultiplySlot = 0x1001613c;

// R6Game.dll data @ 10016140 : Core.dll Core_UStruct_IsChildOf import address word
constexpr unsigned int Core_UStruct_IsChildOfSlot = 0x10016140;

// R6Game.dll data @ 10016144 : Core.dll Core_UObject_StaticLoadClass import address word
constexpr unsigned int Core_UObject_StaticLoadClassSlot = 0x10016144;

// R6Game.dll data @ 10016148 : Core.dll Core_FString_OperatorEquals import address word
constexpr unsigned int Core_FString_OperatorEqualsSlot = 0x10016148;

// R6Game.dll data @ 1001614c : Core.dll Core_FArray_Destructor import address word
constexpr unsigned int Core_FArray_DestructorSlot = 0x1001614c;

// R6Game.dll data @ 10016150 : Core.dll Core_UClass_Constructor import address word
constexpr unsigned int Core_UClass_ConstructorSlot = 0x10016150;

// R6Game.dll data @ 10016154 : Core.dll Core_UObject_StaticConfigName import address word
constexpr unsigned int Core_UObject_StaticConfigNameSlot = 0x10016154;

// R6Game.dll data @ 10016158 : Core.dll Core_UObject_PrivateStaticClass import address word
constexpr unsigned int Core_UObject_PrivateStaticClassSlot = 0x10016158;

// R6Game.dll data @ 1001615c : Core.dll Core_UObject_StaticConstructor import address word
constexpr unsigned int Core_UObject_StaticConstructorSlot = 0x1001615c;

// R6Game.dll data @ 10016160 : Core.dll Core_GRegisterNative import address word
constexpr unsigned int Core_GRegisterNativeSlot = 0x10016160;

// R6Game.dll data @ 10016164 : Core.dll Core_UClass_Destructor import address word
constexpr unsigned int Core_UClass_DestructorSlot = 0x10016164;

// R6Game.dll data @ 10016168 : Core.dll Core_FArchive_ByteOrderSerialize import address word
constexpr unsigned int Core_FArchive_ByteOrderSerializeSlot = 0x10016168;

// R6Game.dll data @ 1001616c : Core.dll Core_FVector_FVector0 import address word
constexpr unsigned int Core_FVector_FVector0Slot = 0x1001616c;

// R6Game.dll data @ 10016170 : Core.dll Core_FString_OperatorNotEquals import address word
constexpr unsigned int Core_FString_OperatorNotEqualsSlot = 0x10016170;

// R6Game.dll data @ 10016174 : Core.dll Core_OperatorShiftLeft_10016174 import address word
constexpr unsigned int Core_SerializeFStringSlot = 0x10016174;

// R6Game.dll data @ 10016178 : Core.dll Core_GFileManager import address word
constexpr unsigned int Core_GFileManagerSlot = 0x10016178;

// R6Game.dll data @ 1001617c : Core.dll Core_FString_Constructor_1001617c import address word
constexpr unsigned int Core_FString_TextConstructorSlot = 0x1001617c;

// R6Game.dll data @ 10016180 : Core.dll Core_appStrstr import address word
constexpr unsigned int Core_appStrstrSlot = 0x10016180;

// R6Game.dll data @ 10016184 : Core.dll Core_FString_OperatorAppendAssign_10016184 import address word
constexpr unsigned int Core_FString_OperatorAppendAssignStringSlot = 0x10016184;

// R6Game.dll data @ 10016188 : Core.dll Core_FString_OperatorAdd_10016188 import address word
constexpr unsigned int Core_FString_OperatorAddTextSlot = 0x10016188;

// R6Game.dll data @ 1001618c : Core.dll Core_GNull import address word
constexpr unsigned int Core_GNullSlot = 0x1001618c;

// R6Game.dll data @ 10016190 : Core.dll Core_FString_OperatorAdd_10016190 import address word
constexpr unsigned int Core_FString_OperatorAddStringSlot = 0x10016190;

// R6Game.dll data @ 10016194 : Core.dll Core_FCoords_OrthoRotation import address word
constexpr unsigned int Core_FCoords_OrthoRotationSlot = 0x10016194;

// R6Game.dll data @ 10016198 : Core.dll Core_FVector_Normalize import address word
constexpr unsigned int Core_FVector_NormalizeSlot = 0x10016198;

// R6Game.dll data @ 1001619c : Core.dll Core_FArray_Insert import address word
constexpr unsigned int Core_FArray_InsertSlot = 0x1001619c;

// R6Game.dll data @ 100161a0 : Core.dll Core_FArray_CountBytes import address word
constexpr unsigned int Core_FArray_CountBytesSlot = 0x100161a0;

// R6Game.dll data @ 100161a4 : Core.dll Core_UClass_PrivateStaticClass import address word
constexpr unsigned int Core_UClass_PrivateStaticClassSlot = 0x100161a4;

// R6Game.dll data @ 100161a8 : Core.dll Core_OperatorShiftLeft_100161a8 import address word
constexpr unsigned int Core_SerializeFCompactIndexSlot = 0x100161a8;

// R6Game.dll data @ 100161ac : Core.dll Core_UObject_StaticLoadObject import address word
constexpr unsigned int Core_UObject_StaticLoadObjectSlot = 0x100161ac;

// R6Game.dll data @ 100161b0 : Core.dll Core_UObject_GetName import address word
constexpr unsigned int Core_UObject_GetNameSlot = 0x100161b0;

// R6Game.dll data @ 100161b4 : Core.dll Core_FStringNoInit_OperatorAssign_100161b4 import address word
constexpr unsigned int import_bindings_Core_FStringNoInit_AssignFStringSlot2 = 0x100161b4;

// R6Game.dll data @ 100161b8 : Core.dll Core_FString_LeftChop import address word
constexpr unsigned int Core_FString_LeftChopSlot = 0x100161b8;

// R6Game.dll data @ 100161bc : Core.dll Core_FString_Caps import address word
constexpr unsigned int Core_FString_CapsSlot = 0x100161bc;

// R6Game.dll data @ 100161c0 : Core.dll Core_GSecondsPerCycle import address word
constexpr unsigned int Core_GSecondsPerCycleSlot = 0x100161c0;

// R6Game.dll data @ 100161c4 : Core.dll Core_FMatrix_Destructor import address word
constexpr unsigned int Core_FMatrix_DestructorSlot = 0x100161c4;

// R6Game.dll data @ 100161c8 : Core.dll Core_FMatrix_OperatorMultiply import address word
constexpr unsigned int Core_FMatrix_OperatorMultiplySlot = 0x100161c8;

// R6Game.dll data @ 100161cc : Core.dll Core_FMatrix_Identity import address word
constexpr unsigned int Core_FMatrix_IdentitySlot = 0x100161cc;

// R6Game.dll data @ 100161d0 : Core.dll Core_FMatrix_Constructor import address word
constexpr unsigned int Core_FMatrix_ConstructorSlot = 0x100161d0;

// R6Game.dll data @ 100161d4 : Core.dll Core_GMath import address word
constexpr unsigned int Core_GMathSlot = 0x100161d4;

// R6Game.dll data @ 100161d8 : Core.dll null import delimiter
constexpr unsigned int Core_ImportTerminatorSlot = 0x100161d8;

// R6Game.dll data @ 100161dc : Engine.dll Engine_UR6AbstractGameManager_eventGMProcessMsg import address word
constexpr unsigned int Engine_UR6AbstractGameManager_eventGMProcessMsgSlot = 0x100161dc;

// R6Game.dll data @ 100161e0 : Engine.dll Engine_UInteraction_eventGetStoreGamePwd import address word
constexpr unsigned int Engine_UInteraction_eventGetStoreGamePwdSlot = 0x100161e0;

// R6Game.dll data @ 100161e4 : Engine.dll Engine_UInteractionMaster_Exec import address word
constexpr unsigned int Engine_UInteractionMaster_ExecSlot = 0x100161e4;

// R6Game.dll data @ 100161e8 : Engine.dll Engine_FLineBatcher_Destructor import address word
constexpr unsigned int Engine_FLineBatcher_DestructorSlot = 0x100161e8;

// R6Game.dll data @ 100161ec : Engine.dll Engine_FLineBatcher_Flush import address word
constexpr unsigned int Engine_FLineBatcher_FlushSlot = 0x100161ec;

// R6Game.dll data @ 100161f0 : Engine.dll Engine_FLineBatcher_DrawDirectionalArrow import address word
constexpr unsigned int Engine_FLineBatcher_DrawDirectionalArrowSlot = 0x100161f0;

// R6Game.dll data @ 100161f4 : Engine.dll Engine_FLineBatcher_Constructor import address word
constexpr unsigned int Engine_FLineBatcher_ConstructorSlot = 0x100161f4;

// R6Game.dll data @ 100161f8 : Engine.dll Engine_FColor_Constructor import address word
constexpr unsigned int Engine_FColor_ConstructorSlot = 0x100161f8;

// R6Game.dll data @ 100161fc : Engine.dll Engine_GGameOptions import address word
constexpr unsigned int Engine_GGameOptionsSlot = 0x100161fc;

// R6Game.dll data @ 10016200 : Engine.dll Engine_UCanvas_SetStretch import address word
constexpr unsigned int Engine_UCanvas_SetStretchSlot = 0x10016200;

// R6Game.dll data @ 10016204 : Engine.dll Engine_APawn_IsFriend import address word
constexpr unsigned int Engine_APawn_IsFriendSlot = 0x10016204;

// R6Game.dll data @ 10016208 : Engine.dll Engine_FLineBatcher_DrawLine import address word
constexpr unsigned int Engine_FLineBatcher_DrawLineSlot = 0x10016208;

// R6Game.dll data @ 1001620c : Engine.dll Engine_FLineBatcher_DrawCircle import address word
constexpr unsigned int Engine_FLineBatcher_DrawCircleSlot = 0x1001620c;

// R6Game.dll data @ 10016210 : Engine.dll Engine_APawn_IsAlive import address word
constexpr unsigned int Engine_APawn_IsAliveSlot = 0x10016210;

// R6Game.dll data @ 10016214 : Engine.dll Engine_ATerrainInfo_PrivateStaticClass import address word
constexpr unsigned int Engine_ATerrainInfo_PrivateStaticClassSlot = 0x10016214;

// R6Game.dll data @ 10016218 : Engine.dll Engine_AActor_RenderEditorSelected import address word
constexpr unsigned int Engine_AActor_RenderEditorSelectedSlot = 0x10016218;

// R6Game.dll data @ 1001621c : Engine.dll Engine_ULevel_GetLevelInfo import address word
constexpr unsigned int Engine_ULevel_GetLevelInfoSlot = 0x1001621c;

// R6Game.dll data @ 10016220 : Engine.dll Engine_AActor_NativeStartedByGSClient import address word
constexpr unsigned int Engine_AActor_NativeStartedByGSClientSlot = 0x10016220;

// R6Game.dll data @ 10016224 : Engine.dll Engine_AActor_PrivateStaticClass import address word
constexpr unsigned int Engine_AActor_PrivateStaticClassSlot = 0x10016224;

// R6Game.dll data @ 10016228 : Engine.dll Engine_UViewport_PrivateStaticClass import address word
constexpr unsigned int Engine_UViewport_PrivateStaticClassSlot = 0x10016228;

// R6Game.dll data @ 1001622c : Engine.dll Engine_AController_GetTeamManager import address word
constexpr unsigned int Engine_AController_GetTeamManagerSlot = 0x1001622c;

// R6Game.dll data @ 10016230 : Engine.dll Engine_APlayerController_LocalPlayerController import address word
constexpr unsigned int Engine_APlayerController_LocalPlayerControllerSlot = 0x10016230;

// R6Game.dll data @ 10016234 : Engine.dll Engine_AController_SetAdjustLocation import address word
constexpr unsigned int Engine_AController_SetAdjustLocationSlot = 0x10016234;

// R6Game.dll data @ 10016238 : Engine.dll Engine_AController_AdjustFromWall import address word
constexpr unsigned int Engine_AController_AdjustFromWallSlot = 0x10016238;

// R6Game.dll data @ 1001623c : Engine.dll Engine_AController_AcceptNearbyPath import address word
constexpr unsigned int Engine_AController_AcceptNearbyPathSlot = 0x1001623c;

// R6Game.dll data @ 10016240 : Engine.dll Engine_APlayerController_GetViewTarget import address word
constexpr unsigned int Engine_APlayerController_GetViewTargetSlot = 0x10016240;

// R6Game.dll data @ 10016244 : Engine.dll Engine_APlayerController_CheckHearSound import address word
constexpr unsigned int Engine_APlayerController_CheckHearSoundSlot = 0x10016244;

// R6Game.dll data @ 10016248 : Engine.dll Engine_AController_CanHear import address word
constexpr unsigned int Engine_AController_CanHearSlot = 0x10016248;

// R6Game.dll data @ 1001624c : Engine.dll Engine_AActor_GetProjectorBase import address word
constexpr unsigned int Engine_AActor_GetProjectorBaseSlot = 0x1001624c;

// R6Game.dll data @ 10016250 : Engine.dll Engine_AActor_PostPath import address word
constexpr unsigned int Engine_AActor_PostPathSlot = 0x10016250;

// R6Game.dll data @ 10016254 : Engine.dll Engine_AActor_PrePath import address word
constexpr unsigned int Engine_AActor_PrePathSlot = 0x10016254;

// R6Game.dll data @ 10016258 : Engine.dll Engine_AActor_CheckForErrors import address word
constexpr unsigned int Engine_AActor_CheckForErrorsSlot = 0x10016258;

// R6Game.dll data @ 1001625c : Engine.dll Engine_AActor_TickThisFrame import address word
constexpr unsigned int Engine_AActor_TickThisFrameSlot = 0x1001625c;

// R6Game.dll data @ 10016260 : Engine.dll Engine_AActor_IsRelevantToPawnHeartBeat import address word
constexpr unsigned int Engine_AActor_IsRelevantToPawnHeartBeatSlot = 0x10016260;

// R6Game.dll data @ 10016264 : Engine.dll Engine_AActor_IsRelevantToPawnHeatVision import address word
constexpr unsigned int Engine_AActor_IsRelevantToPawnHeatVisionSlot = 0x10016264;

// R6Game.dll data @ 10016268 : Engine.dll Engine_AActor_IsRelevantToPawnRadar import address word
constexpr unsigned int Engine_AActor_IsRelevantToPawnRadarSlot = 0x10016268;

// R6Game.dll data @ 1001626c : Engine.dll Engine_AActor_PlayAnim import address word
constexpr unsigned int Engine_AActor_PlayAnimSlot = 0x1001626c;

// R6Game.dll data @ 10016270 : Engine.dll Engine_AActor_HasAssociatedLevelGeometry import address word
constexpr unsigned int Engine_AActor_HasAssociatedLevelGeometrySlot = 0x10016270;

// R6Game.dll data @ 10016274 : Engine.dll Engine_AActor_AssociatedLevelGeometry import address word
constexpr unsigned int Engine_AActor_AssociatedLevelGeometrySlot = 0x10016274;

// R6Game.dll data @ 10016278 : Engine.dll Engine_AActor_AddMyMarker import address word
constexpr unsigned int Engine_AActor_AddMyMarkerSlot = 0x10016278;

// R6Game.dll data @ 1001627c : Engine.dll Engine_AActor_KMP2DynKarmaInterface import address word
constexpr unsigned int Engine_AActor_KMP2DynKarmaInterfaceSlot = 0x1001627c;

// R6Game.dll data @ 10016280 : Engine.dll Engine_AActor_postKarmaStep import address word
constexpr unsigned int Engine_AActor_postKarmaStepSlot = 0x10016280;

// R6Game.dll data @ 10016284 : Engine.dll Engine_AActor_preKarmaStep import address word
constexpr unsigned int Engine_AActor_preKarmaStepSlot = 0x10016284;

// R6Game.dll data @ 10016288 : Engine.dll Engine_AActor_physKarma import address word
constexpr unsigned int Engine_AActor_physKarmaSlot = 0x10016288;

// R6Game.dll data @ 1001628c : Engine.dll Engine_AActor_getKModel import address word
constexpr unsigned int Engine_AActor_getKModelSlot = 0x1001628c;

// R6Game.dll data @ 10016290 : Engine.dll Engine_AActor_stepUp import address word
constexpr unsigned int Engine_AActor_stepUpSlot = 0x10016290;

// R6Game.dll data @ 10016294 : Engine.dll Engine_AActor_SmoothHitWall import address word
constexpr unsigned int Engine_AActor_SmoothHitWallSlot = 0x10016294;

// R6Game.dll data @ 10016298 : Engine.dll Engine_AActor_FindSlopeRotation import address word
constexpr unsigned int Engine_AActor_FindSlopeRotationSlot = 0x10016298;

// R6Game.dll data @ 1001629c : Engine.dll Engine_AActor_physFalling import address word
constexpr unsigned int Engine_AActor_physFallingSlot = 0x1001629c;

// R6Game.dll data @ 100162a0 : Engine.dll Engine_AActor_processLanded import address word
constexpr unsigned int Engine_AActor_processLandedSlot = 0x100162a0;

// R6Game.dll data @ 100162a4 : Engine.dll Engine_AActor_processHitWall import address word
constexpr unsigned int Engine_AActor_processHitWallSlot = 0x100162a4;

// R6Game.dll data @ 100162a8 : Engine.dll Engine_AActor_BoundProjectileVelocity import address word
constexpr unsigned int Engine_AActor_BoundProjectileVelocitySlot = 0x100162a8;

// R6Game.dll data @ 100162ac : Engine.dll Engine_AActor_performPhysics import address word
constexpr unsigned int Engine_AActor_performPhysicsSlot = 0x100162ac;

// R6Game.dll data @ 100162b0 : Engine.dll Engine_AActor_setPhysics import address word
constexpr unsigned int Engine_AActor_setPhysicsSlot = 0x100162b0;

// R6Game.dll data @ 100162b4 : Engine.dll Engine_AActor_PostBeginPlay import address word
constexpr unsigned int Engine_AActor_PostBeginPlaySlot = 0x100162b4;

// R6Game.dll data @ 100162b8 : Engine.dll AActor::SetVolumes() import address word
constexpr unsigned int Engine_AActor_SetVolumesSlot = 0x100162b8;

// R6Game.dll data @ 100162bc : Engine.dll AActor::SetVolumes(const TArray<AVolume*>&) import address word
constexpr unsigned int Engine_AActor_SetVolumesFromListSlot = 0x100162bc;

// R6Game.dll data @ 100162c0 : Engine.dll Engine_AActor_SetZone import address word
constexpr unsigned int Engine_AActor_SetZoneSlot = 0x100162c0;

// R6Game.dll data @ 100162c4 : Engine.dll Engine_FSceneNode_Project import address word
constexpr unsigned int Engine_FSceneNode_ProjectSlot = 0x100162c4;

// R6Game.dll data @ 100162c8 : Engine.dll Engine_AActor_RenderEditorInfo import address word
constexpr unsigned int Engine_AActor_RenderEditorInfoSlot = 0x100162c8;

// R6Game.dll data @ 100162cc : Engine.dll Engine_APlayerController_IsNetRelevantFor import address word
constexpr unsigned int Engine_APlayerController_IsNetRelevantForSlot = 0x100162cc;

// R6Game.dll data @ 100162d0 : Engine.dll Engine_AActor_PlayerControlled import address word
constexpr unsigned int Engine_AActor_PlayerControlledSlot = 0x100162d0;

// R6Game.dll data @ 100162d4 : Engine.dll Engine_AActor_TickSpecial import address word
constexpr unsigned int Engine_AActor_TickSpecialSlot = 0x100162d4;

// R6Game.dll data @ 100162d8 : Engine.dll Engine_AActor_TickSimulated import address word
constexpr unsigned int Engine_AActor_TickSimulatedSlot = 0x100162d8;

// R6Game.dll data @ 100162dc : Engine.dll Engine_AActor_TickAuthoritative import address word
constexpr unsigned int Engine_AActor_TickAuthoritativeSlot = 0x100162dc;

// R6Game.dll data @ 100162e0 : Engine.dll Engine_AActor_CheckOwnerUpdated import address word
constexpr unsigned int Engine_AActor_CheckOwnerUpdatedSlot = 0x100162e0;

// R6Game.dll data @ 100162e4 : Engine.dll Engine_AActor_UpdateTimers import address word
constexpr unsigned int Engine_AActor_UpdateTimersSlot = 0x100162e4;

// R6Game.dll data @ 100162e8 : Engine.dll Engine_AController_CheckAnimFinished import address word
constexpr unsigned int Engine_AController_CheckAnimFinishedSlot = 0x100162e8;

// R6Game.dll data @ 100162ec : Engine.dll Engine_AController_StartAnimPoll import address word
constexpr unsigned int Engine_AController_StartAnimPollSlot = 0x100162ec;

// R6Game.dll data @ 100162f0 : Engine.dll Engine_AActor_UpdateAnimation import address word
constexpr unsigned int Engine_AActor_UpdateAnimationSlot = 0x100162f0;

// R6Game.dll data @ 100162f4 : Engine.dll Engine_AActor_NotifyAnimEnd import address word
constexpr unsigned int Engine_AActor_NotifyAnimEndSlot = 0x100162f4;

// R6Game.dll data @ 100162f8 : Engine.dll Engine_AActor_GetViewRotation import address word
constexpr unsigned int Engine_AActor_GetViewRotationSlot = 0x100162f8;

// R6Game.dll data @ 100162fc : Engine.dll Engine_AActor_SetBase import address word
constexpr unsigned int Engine_AActor_SetBaseSlot = 0x100162fc;

// R6Game.dll data @ 10016300 : Engine.dll Engine_AActor_NotifyBump import address word
constexpr unsigned int Engine_AActor_NotifyBumpSlot = 0x10016300;

// R6Game.dll data @ 10016304 : Engine.dll Engine_AActor_IsMovingBrush import address word
constexpr unsigned int Engine_AActor_IsMovingBrushSlot = 0x10016304;

// R6Game.dll data @ 10016308 : Engine.dll Engine_AActor_BeginTouch import address word
constexpr unsigned int Engine_AActor_BeginTouchSlot = 0x10016308;

// R6Game.dll data @ 1001630c : Engine.dll Engine_AActor_GetPrimitive import address word
constexpr unsigned int Engine_AActor_GetPrimitiveSlot = 0x1001630c;

// R6Game.dll data @ 10016310 : Engine.dll Engine_AActor_ShouldTrace import address word
constexpr unsigned int Engine_AActor_ShouldTraceSlot = 0x10016310;

// R6Game.dll data @ 10016314 : Engine.dll Engine_AActor_PostScriptDestroyed import address word
constexpr unsigned int Engine_AActor_PostScriptDestroyedSlot = 0x10016314;

// R6Game.dll data @ 10016318 : Engine.dll Engine_AActor_UpdateColBox import address word
constexpr unsigned int Engine_AActor_UpdateColBoxSlot = 0x10016318;

// R6Game.dll data @ 1001631c : Engine.dll Engine_AActor_WorldToLocal import address word
constexpr unsigned int Engine_AActor_WorldToLocalSlot = 0x1001631c;

// R6Game.dll data @ 10016320 : Engine.dll Engine_AActor_LocalToWorld import address word
constexpr unsigned int Engine_AActor_LocalToWorldSlot = 0x10016320;

// R6Game.dll data @ 10016324 : Engine.dll Engine_AActor_ToWorld import address word
constexpr unsigned int Engine_AActor_ToWorldSlot = 0x10016324;

// R6Game.dll data @ 10016328 : Engine.dll Engine_AActor_ToLocal import address word
constexpr unsigned int Engine_AActor_ToLocalSlot = 0x10016328;

// R6Game.dll data @ 1001632c : Engine.dll Engine_AActor_GetSkin import address word
constexpr unsigned int Engine_AActor_GetSkinSlot = 0x1001632c;

// R6Game.dll data @ 10016330 : Engine.dll Engine_AActor_PostNetReceiveLocation import address word
constexpr unsigned int Engine_AActor_PostNetReceiveLocationSlot = 0x10016330;

// R6Game.dll data @ 10016334 : Engine.dll Engine_APlayerController_PostNetReceive import address word
constexpr unsigned int Engine_APlayerController_PostNetReceiveSlot = 0x10016334;

// R6Game.dll data @ 10016338 : Engine.dll Engine_APlayerController_PreNetReceive import address word
constexpr unsigned int Engine_APlayerController_PreNetReceiveSlot = 0x10016338;

// R6Game.dll data @ 1001633c : Engine.dll Engine_AActor_Spawned import address word
constexpr unsigned int Engine_AActor_SpawnedSlot = 0x1001633c;

// R6Game.dll data @ 10016340 : Engine.dll Engine_AActor_PostRaytrace import address word
constexpr unsigned int Engine_AActor_PostRaytraceSlot = 0x10016340;

// R6Game.dll data @ 10016344 : Engine.dll Engine_AActor_PreRaytrace import address word
constexpr unsigned int Engine_AActor_PreRaytraceSlot = 0x10016344;

// R6Game.dll data @ 10016348 : Engine.dll Engine_AActor_PostEditLoad import address word
constexpr unsigned int Engine_AActor_PostEditLoadSlot = 0x10016348;

// R6Game.dll data @ 1001634c : Engine.dll Engine_AActor_PostEditMove import address word
constexpr unsigned int Engine_AActor_PostEditMoveSlot = 0x1001634c;

// R6Game.dll data @ 10016350 : Engine.dll Engine_APlayerController_Tick import address word
constexpr unsigned int Engine_APlayerController_TickSlot = 0x10016350;

// R6Game.dll data @ 10016354 : Engine.dll Engine_AActor_WorldLightRadius import address word
constexpr unsigned int Engine_AActor_WorldLightRadiusSlot = 0x10016354;

// R6Game.dll data @ 10016358 : Engine.dll Engine_AActor_GetNetPriority import address word
constexpr unsigned int Engine_AActor_GetNetPrioritySlot = 0x10016358;

// R6Game.dll data @ 1001635c : Engine.dll Engine_AActor_IsBlockedBy import address word
constexpr unsigned int Engine_AActor_IsBlockedBySlot = 0x1001635c;

// R6Game.dll data @ 10016360 : Engine.dll Engine_AActor_GetPawnOrColBoxOwner import address word
constexpr unsigned int Engine_AActor_GetPawnOrColBoxOwnerSlot = 0x10016360;

// R6Game.dll data @ 10016364 : Engine.dll Engine_AActor_GetPlayerPawn import address word
constexpr unsigned int Engine_AActor_GetPlayerPawnSlot = 0x10016364;

// R6Game.dll data @ 10016368 : Engine.dll Engine_APlayerController_GetOptimizedRepList import address word
constexpr unsigned int Engine_APlayerController_GetOptimizedRepListSlot = 0x10016368;

// R6Game.dll data @ 1001636c : Engine.dll Engine_AActor_NetDirty import address word
constexpr unsigned int Engine_AActor_NetDirtySlot = 0x1001636c;

// R6Game.dll data @ 10016370 : Engine.dll Engine_AActor_IsPendingDelete import address word
constexpr unsigned int Engine_AActor_IsPendingDeleteSlot = 0x10016370;

// R6Game.dll data @ 10016374 : Engine.dll Engine_AActor_PostEditChange import address word
constexpr unsigned int Engine_AActor_PostEditChangeSlot = 0x10016374;

// R6Game.dll data @ 10016378 : Engine.dll Engine_AActor_InitExecution import address word
constexpr unsigned int Engine_AActor_InitExecutionSlot = 0x10016378;

// R6Game.dll data @ 1001637c : Engine.dll Engine_AActor_IsPendingKill import address word
constexpr unsigned int Engine_AActor_IsPendingKillSlot = 0x1001637c;

// R6Game.dll data @ 10016380 : Engine.dll Engine_AActor_Serialize import address word
constexpr unsigned int Engine_AActor_SerializeSlot = 0x10016380;

// R6Game.dll data @ 10016384 : Engine.dll Engine_AActor_Destroy import address word
constexpr unsigned int Engine_AActor_DestroySlot = 0x10016384;

// R6Game.dll data @ 10016388 : Engine.dll Engine_AActor_PostLoad import address word
constexpr unsigned int Engine_AActor_PostLoadSlot = 0x10016388;

// R6Game.dll data @ 1001638c : Engine.dll Engine_AActor_ProcessRemoteFunction import address word
constexpr unsigned int Engine_AActor_ProcessRemoteFunctionSlot = 0x1001638c;

// R6Game.dll data @ 10016390 : Engine.dll Engine_AActor_ProcessState import address word
constexpr unsigned int Engine_AActor_ProcessStateSlot = 0x10016390;

// R6Game.dll data @ 10016394 : Engine.dll Engine_AActor_ProcessEvent import address word
constexpr unsigned int Engine_AActor_ProcessEventSlot = 0x10016394;

// R6Game.dll data @ 10016398 : Engine.dll Engine_APlayerController_Destructor import address word
constexpr unsigned int Engine_APlayerController_DestructorSlot = 0x10016398;

// R6Game.dll data @ 1001639c : Engine.dll Engine_APlayerController_Constructor_1001639c import address word
constexpr unsigned int Engine_APlayerController_DefaultConstructorSlot = 0x1001639c;

// R6Game.dll data @ 100163a0 : Engine.dll Engine_APlayerController_Constructor_100163a0 import address word
constexpr unsigned int Engine_APlayerController_CopyConstructorSlot = 0x100163a0;

// R6Game.dll data @ 100163a4 : Engine.dll Engine_APlayerController_OperatorAssign import address word
constexpr unsigned int Engine_APlayerController_OperatorAssignSlot = 0x100163a4;

// R6Game.dll data @ 100163a8 : Engine.dll Engine_AActor_IsNetRelevantFor import address word
constexpr unsigned int Engine_AActor_IsNetRelevantForSlot = 0x100163a8;

// R6Game.dll data @ 100163ac : Engine.dll Engine_AActor_CheckAnimFinished import address word
constexpr unsigned int Engine_AActor_CheckAnimFinishedSlot = 0x100163ac;

// R6Game.dll data @ 100163b0 : Engine.dll Engine_AActor_StartAnimPoll import address word
constexpr unsigned int Engine_AActor_StartAnimPollSlot = 0x100163b0;

// R6Game.dll data @ 100163b4 : Engine.dll Engine_AActor_PostNetReceive import address word
constexpr unsigned int Engine_AActor_PostNetReceiveSlot = 0x100163b4;

// R6Game.dll data @ 100163b8 : Engine.dll Engine_AActor_PreNetReceive import address word
constexpr unsigned int Engine_AActor_PreNetReceiveSlot = 0x100163b8;

// R6Game.dll data @ 100163bc : Engine.dll Engine_AActor_Tick import address word
constexpr unsigned int Engine_AActor_TickSlot = 0x100163bc;

// R6Game.dll data @ 100163c0 : Engine.dll Engine_AActor_GetOptimizedRepList import address word
constexpr unsigned int Engine_AActor_GetOptimizedRepListSlot = 0x100163c0;

// R6Game.dll data @ 100163c4 : Engine.dll Engine_AR6ActionPointAbstract_Destructor import address word
constexpr unsigned int Engine_AR6ActionPointAbstract_DestructorSlot = 0x100163c4;

// R6Game.dll data @ 100163c8 : Engine.dll Engine_AR6ActionPointAbstract_Constructor_100163c8 import address word
constexpr unsigned int Engine_AR6ActionPointAbstract_DefaultConstructorSlot = 0x100163c8;

// R6Game.dll data @ 100163cc : Engine.dll Engine_AR6ActionPointAbstract_Constructor_100163cc import address word
constexpr unsigned int Engine_AR6ActionPointAbstract_CopyConstructorSlot = 0x100163cc;

// R6Game.dll data @ 100163d0 : Engine.dll Engine_AR6ActionPointAbstract_OperatorAssign import address word
constexpr unsigned int Engine_AR6ActionPointAbstract_OperatorAssignSlot = 0x100163d0;

// R6Game.dll data @ 100163d4 : Engine.dll Engine_UR6AbstractGameManager_Destructor import address word
constexpr unsigned int Engine_UR6AbstractGameManager_DestructorSlot = 0x100163d4;

// R6Game.dll data @ 100163d8 : Engine.dll Engine_UR6AbstractGameManager_Vftable import address word
constexpr unsigned int Engine_UR6AbstractGameManager_VftableSlot = 0x100163d8;

// R6Game.dll data @ 100163dc : Engine.dll Engine_UR6AbstractGameManager_Constructor import address word
constexpr unsigned int Engine_UR6AbstractGameManager_ConstructorSlot = 0x100163dc;

// R6Game.dll data @ 100163e0 : Engine.dll Engine_UR6AbstractGameManager_OperatorAssign import address word
constexpr unsigned int Engine_UR6AbstractGameManager_OperatorAssignSlot = 0x100163e0;

// R6Game.dll data @ 100163e4 : Engine.dll Engine_UR6AbstractPlanningInfo_Destructor import address word
constexpr unsigned int Engine_UR6AbstractPlanningInfo_DestructorSlot = 0x100163e4;

// R6Game.dll data @ 100163e8 : Engine.dll Engine_UR6AbstractPlanningInfo_Constructor_100163e8 import address word
constexpr unsigned int Engine_UR6AbstractPlanningInfo_CopyConstructorSlot = 0x100163e8;

// R6Game.dll data @ 100163ec : Engine.dll Engine_UR6AbstractPlanningInfo_OperatorAssign import address word
constexpr unsigned int Engine_UR6AbstractPlanningInfo_OperatorAssignSlot = 0x100163ec;

// R6Game.dll data @ 100163f0 : Engine.dll Engine_UR6FileManager_FindFile import address word
constexpr unsigned int Engine_UR6FileManager_FindFileSlot = 0x100163f0;

// R6Game.dll data @ 100163f4 : Engine.dll Engine_UR6FileManager_GetNbFile import address word
constexpr unsigned int Engine_UR6FileManager_GetNbFileSlot = 0x100163f4;

// R6Game.dll data @ 100163f8 : Engine.dll Engine_UR6FileManager_GetFileName import address word
constexpr unsigned int Engine_UR6FileManager_GetFileNameSlot = 0x100163f8;

// R6Game.dll data @ 100163fc : Engine.dll Engine_UR6FileManager_Destructor import address word
constexpr unsigned int Engine_UR6FileManager_DestructorSlot = 0x100163fc;

// R6Game.dll data @ 10016400 : Engine.dll Engine_UR6FileManager_Constructor_10016400 import address word
constexpr unsigned int Engine_UR6FileManager_DefaultConstructorSlot = 0x10016400;

// R6Game.dll data @ 10016404 : Engine.dll Engine_UR6FileManager_Constructor_10016404 import address word
constexpr unsigned int Engine_UR6FileManager_CopyConstructorSlot = 0x10016404;

// R6Game.dll data @ 10016408 : Engine.dll Engine_UR6FileManager_OperatorAssign import address word
constexpr unsigned int Engine_UR6FileManager_OperatorAssignSlot = 0x10016408;

// R6Game.dll data @ 1001640c : Engine.dll Engine_g_pEngine import address word
constexpr unsigned int Engine_g_pEngineSlot = 0x1001640c;

// R6Game.dll data @ 10016410 : Engine.dll Engine_APlayerController_eventInitMultiPlayerOptions import address word
constexpr unsigned int Engine_APlayerController_eventInitMultiPlayerOptionsSlot = 0x10016410;

// R6Game.dll data @ 10016414 : Engine.dll Engine_APlayerController_eventInitInputSystem import address word
constexpr unsigned int Engine_APlayerController_eventInitInputSystemSlot = 0x10016414;

// R6Game.dll data @ 10016418 : Engine.dll Engine_UR6ModMgr_eventIsRavenShield import address word
constexpr unsigned int Engine_UR6ModMgr_eventIsRavenShieldSlot = 0x10016418;

// R6Game.dll data @ 1001641c : Engine.dll Engine_GModMgr import address word
constexpr unsigned int Engine_GModMgrSlot = 0x1001641c;

// R6Game.dll data @ 10016420 : Engine.dll Engine_APlayerController_eventIsPlayerPassiveSpectator import address word
constexpr unsigned int Engine_APlayerController_eventIsPlayerPassiveSpectatorSlot = 0x10016420;

// R6Game.dll data @ 10016424 : Engine.dll Engine_ABrush_InitPosRotScale import address word
constexpr unsigned int Engine_ABrush_InitPosRotScaleSlot = 0x10016424;

// R6Game.dll data @ 10016428 : Engine.dll Engine_ABrush_CopyPosRotScaleFrom import address word
constexpr unsigned int Engine_ABrush_CopyPosRotScaleFromSlot = 0x10016428;

// R6Game.dll data @ 1001642c : Engine.dll Engine_ABrush_CheckForErrors import address word
constexpr unsigned int Engine_ABrush_CheckForErrorsSlot = 0x1001642c;

// R6Game.dll data @ 10016430 : Engine.dll Engine_AVolume_PostBeginPlay import address word
constexpr unsigned int Engine_AVolume_PostBeginPlaySlot = 0x10016430;

// R6Game.dll data @ 10016434 : Engine.dll AVolume::SetVolumes() import address word
constexpr unsigned int Engine_AVolume_SetVolumesSlot = 0x10016434;

// R6Game.dll data @ 10016438 : Engine.dll AVolume::SetVolumes(const TArray<AVolume*>&) import address word
constexpr unsigned int Engine_AVolume_SetVolumesFromListSlot = 0x10016438;

// R6Game.dll data @ 1001643c : Engine.dll Engine_ABrush_GetPrimitive import address word
constexpr unsigned int Engine_ABrush_GetPrimitiveSlot = 0x1001643c;

// R6Game.dll data @ 10016440 : Engine.dll Engine_AVolume_ShouldTrace import address word
constexpr unsigned int Engine_AVolume_ShouldTraceSlot = 0x10016440;

// R6Game.dll data @ 10016444 : Engine.dll Engine_ABrush_ToWorld import address word
constexpr unsigned int Engine_ABrush_ToWorldSlot = 0x10016444;

// R6Game.dll data @ 10016448 : Engine.dll Engine_ABrush_ToLocal import address word
constexpr unsigned int Engine_ABrush_ToLocalSlot = 0x10016448;

// R6Game.dll data @ 1001644c : Engine.dll Engine_ABrush_PostEditChange import address word
constexpr unsigned int Engine_ABrush_PostEditChangeSlot = 0x1001644c;

// R6Game.dll data @ 10016450 : Engine.dll Engine_ABrush_PostLoad import address word
constexpr unsigned int Engine_ABrush_PostLoadSlot = 0x10016450;

// R6Game.dll data @ 10016454 : Engine.dll Engine_AVolume_Destructor import address word
constexpr unsigned int Engine_AVolume_DestructorSlot = 0x10016454;

// R6Game.dll data @ 10016458 : Engine.dll Engine_AVolume_OperatorAssign import address word
constexpr unsigned int Engine_AVolume_OperatorAssignSlot = 0x10016458;

// R6Game.dll data @ 1001645c : Engine.dll Engine_AVolume_Constructor_1001645c import address word
constexpr unsigned int Engine_AVolume_DefaultConstructorSlot = 0x1001645c;

// R6Game.dll data @ 10016460 : Engine.dll Engine_AVolume_Constructor_10016460 import address word
constexpr unsigned int Engine_AVolume_CopyConstructorSlot = 0x10016460;

// R6Game.dll data @ 10016464 : Engine.dll Engine_AHUD_DrawSpecificModeInfo import address word
constexpr unsigned int Engine_AHUD_DrawSpecificModeInfoSlot = 0x10016464;

// R6Game.dll data @ 10016468 : Engine.dll Engine_UR6AbstractPlanningInfo_Constructor_10016468 import address word
constexpr unsigned int Engine_UR6AbstractPlanningInfo_DefaultConstructorSlot = 0x10016468;

// R6Game.dll data @ 1001646c : Engine.dll Engine_AController_FindPath import address word
constexpr unsigned int Engine_AController_FindPathSlot = 0x1001646c;

// R6Game.dll data @ 10016470 : Engine.dll Engine_AR6TeamStartInfo_TransferFile import address word
constexpr unsigned int Engine_AR6TeamStartInfo_TransferFileSlot = 0x10016470;

// R6Game.dll data @ 10016474 : Engine.dll Engine_FCameraSceneNode_Destructor import address word
constexpr unsigned int Engine_FCameraSceneNode_DestructorSlot = 0x10016474;

// R6Game.dll data @ 10016478 : Engine.dll Engine_FCanvasUtil_Destructor import address word
constexpr unsigned int Engine_FCanvasUtil_DestructorSlot = 0x10016478;

// R6Game.dll data @ 1001647c : Engine.dll Engine_FSceneNode_Deproject import address word
constexpr unsigned int Engine_FSceneNode_DeprojectSlot = 0x1001647c;

// R6Game.dll data @ 10016480 : Engine.dll Engine_FCanvasUtil_Constructor import address word
constexpr unsigned int Engine_FCanvasUtil_ConstructorSlot = 0x10016480;

// R6Game.dll data @ 10016484 : Engine.dll Engine_FCameraSceneNode_Constructor import address word
constexpr unsigned int Engine_FCameraSceneNode_ConstructorSlot = 0x10016484;

// R6Game.dll data @ 10016488 : Engine.dll Engine_ATerrainInfo_LineCheck import address word
constexpr unsigned int Engine_ATerrainInfo_LineCheckSlot = 0x10016488;

// R6Game.dll data @ 1001648c : Engine.dll Engine_UModel_R6LineCheck import address word
constexpr unsigned int Engine_UModel_R6LineCheckSlot = 0x1001648c;

// R6Game.dll data @ 10016490 : Engine.dll Engine_AStaticMeshActor_PrivateStaticClass import address word
constexpr unsigned int Engine_AStaticMeshActor_PrivateStaticClassSlot = 0x10016490;

// R6Game.dll data @ 10016494 : Engine.dll Engine_AVolume_Encompasses import address word
constexpr unsigned int Engine_AVolume_EncompassesSlot = 0x10016494;

// R6Game.dll data @ 10016498 : Engine.dll Engine_APawn_walkReachable import address word
constexpr unsigned int Engine_APawn_walkReachableSlot = 0x10016498;

// R6Game.dll data @ 1001649c : Engine.dll Engine_UR6ModMgr_eventGetDefaultCampaignDir import address word
constexpr unsigned int Engine_UR6ModMgr_eventGetDefaultCampaignDirSlot = 0x1001649c;

// R6Game.dll data @ 100164a0 : Engine.dll Engine_UR6ModMgr_eventGetCampaignDir import address word
constexpr unsigned int Engine_UR6ModMgr_eventGetCampaignDirSlot = 0x100164a0;

// R6Game.dll data @ 100164a4 : Engine.dll Engine_AR6ActionPointAbstract_PrivateStaticClass import address word
constexpr unsigned int Engine_AR6ActionPointAbstract_PrivateStaticClassSlot = 0x100164a4;

// R6Game.dll data @ 100164a8 : Engine.dll Engine_APlayerController_PrivateStaticClass import address word
constexpr unsigned int Engine_APlayerController_PrivateStaticClassSlot = 0x100164a8;

// R6Game.dll data @ 100164ac : Engine.dll Engine_UR6AbstractPlanningInfo_PrivateStaticClass import address word
constexpr unsigned int Engine_UR6AbstractPlanningInfo_PrivateStaticClassSlot = 0x100164ac;

// R6Game.dll data @ 100164b0 : Engine.dll Engine_UR6FileManager_PrivateStaticClass import address word
constexpr unsigned int Engine_UR6FileManager_PrivateStaticClassSlot = 0x100164b0;

// R6Game.dll data @ 100164b4 : Engine.dll Engine_AVolume_PrivateStaticClass import address word
constexpr unsigned int Engine_AVolume_PrivateStaticClassSlot = 0x100164b4;

// R6Game.dll data @ 100164b8 : Engine.dll Engine_UR6AbstractGameManager_PrivateStaticClass import address word
constexpr unsigned int Engine_UR6AbstractGameManager_PrivateStaticClassSlot = 0x100164b8;

// R6Game.dll data @ 100164bc : Engine.dll Engine_UFinalBlend_PrivateStaticClass import address word
constexpr unsigned int Engine_UFinalBlend_PrivateStaticClassSlot = 0x100164bc;

// R6Game.dll data @ 100164c0 : Engine.dll Engine_UMaterial_PrivateStaticClass import address word
constexpr unsigned int Engine_UMaterial_PrivateStaticClassSlot = 0x100164c0;

// R6Game.dll data @ 100164c4 : Engine.dll Engine_AController_PrivateStaticClass import address word
constexpr unsigned int Engine_AController_PrivateStaticClassSlot = 0x100164c4;

// R6Game.dll data @ 100164c8 : Engine.dll Engine_APawn_PrivateStaticClass import address word
constexpr unsigned int Engine_APawn_PrivateStaticClassSlot = 0x100164c8;

// R6Game.dll data @ 100164cc : Engine.dll Engine_UTexture_PrivateStaticClass import address word
constexpr unsigned int Engine_UTexture_PrivateStaticClassSlot = 0x100164cc;

// R6Game.dll data @ 100164d0 : Engine.dll Engine_FCanvasUtil_Flush import address word
constexpr unsigned int Engine_FCanvasUtil_FlushSlot = 0x100164d0;

// R6Game.dll data @ 100164d4 : Engine.dll Engine_FCanvasUtil_DrawTile import address word
constexpr unsigned int Engine_FCanvasUtil_DrawTileSlot = 0x100164d4;

// R6Game.dll data @ 100164d8 : Engine.dll Engine_FColor_ConversionOperator import address word
constexpr unsigned int Engine_FColor_ConversionOperatorSlot = 0x100164d8;

// R6Game.dll data @ 100164dc : Engine.dll Engine_FCanvasUtil_DrawTileRotated import address word
constexpr unsigned int Engine_FCanvasUtil_DrawTileRotatedSlot = 0x100164dc;

// R6Game.dll data @ 100164e0 : Engine.dll Engine_GGlobalTempObjects import address word
constexpr unsigned int Engine_GGlobalTempObjectsSlot = 0x100164e0;

// R6Game.dll data @ 100164e4 : Engine.dll Engine_GR6GameManager import address word
constexpr unsigned int Engine_GR6GameManagerSlot = 0x100164e4;

// R6Game.dll data @ 100164e8 : Engine.dll null import delimiter
constexpr unsigned int Engine_ImportTerminatorSlot = 0x100164e8;

// R6Game.dll data @ 100164ec : MSVCR71.dll MSVCR71___CxxFrameHandler import address word
constexpr unsigned int MSVCR71___CxxFrameHandlerSlot = 0x100164ec;

// R6Game.dll data @ 100164f0 : MSVCR71.dll MSVCR71__CxxThrowException import address word
constexpr unsigned int MSVCR71__CxxThrowExceptionSlot = 0x100164f0;

// R6Game.dll data @ 100164f4 : MSVCR71.dll MSVCR71_type_info_Destructor import address word
constexpr unsigned int MSVCR71_type_info_DestructorSlot = 0x100164f4;

// R6Game.dll data @ 100164f8 : MSVCR71.dll MSVCR71_terminate import address word
constexpr unsigned int MSVCR71_terminateSlot = 0x100164f8;

// R6Game.dll data @ 100164fc : MSVCR71.dll MSVCR71__except_handler3 import address word
constexpr unsigned int MSVCR71__except_handler3Slot = 0x100164fc;

// R6Game.dll data @ 10016500 : MSVCR71.dll MSVCR71___dllonexit import address word
constexpr unsigned int MSVCR71___dllonexitSlot = 0x10016500;

// R6Game.dll data @ 10016504 : MSVCR71.dll MSVCR71__onexit import address word
constexpr unsigned int MSVCR71__onexitSlot = 0x10016504;

// R6Game.dll data @ 10016508 : MSVCR71.dll MSVCR71_free import address word
constexpr unsigned int MSVCR71_freeSlot = 0x10016508;

// R6Game.dll data @ 1001650c : MSVCR71.dll MSVCR71__initterm import address word
constexpr unsigned int MSVCR71__inittermSlot = 0x1001650c;

// R6Game.dll data @ 10016510 : MSVCR71.dll MSVCR71_malloc import address word
constexpr unsigned int MSVCR71_mallocSlot = 0x10016510;

// R6Game.dll data @ 10016514 : MSVCR71.dll MSVCR71__adjust_fdiv import address word
constexpr unsigned int MSVCR71__adjust_fdivSlot = 0x10016514;

// R6Game.dll data @ 10016518 : MSVCR71.dll MSVCR71___CppXcptFilter import address word
constexpr unsigned int MSVCR71___CppXcptFilterSlot = 0x10016518;

// R6Game.dll data @ 1001651c : MSVCR71.dll null import delimiter
constexpr unsigned int MSVCR71_ImportTerminatorSlot = 0x1001651c;

// R6Game.dll data @ 10016520 : R6Abstract.dll R6Abstract_AR6AbstractHUD_PrivateStaticClass import address word
constexpr unsigned int R6Abstract_AR6AbstractHUD_PrivateStaticClassSlot = 0x10016520;

// R6Game.dll data @ 10016524 : R6Abstract.dll R6Abstract_AR6AbstractGameInfo_PrivateStaticClass import address word
constexpr unsigned int R6Abstract_AR6AbstractGameInfo_PrivateStaticClassSlot = 0x10016524;

// R6Game.dll data @ 10016528 : R6Abstract.dll R6Abstract_AR6AbstractGameInfo_Constructor_10016528 import address word
constexpr unsigned int R6Abstract_AR6AbstractGameInfo_DefaultConstructorSlot = 0x10016528;

// R6Game.dll data @ 1001652c : R6Abstract.dll R6Abstract_AR6AbstractHUD_Constructor_1001652c import address word
constexpr unsigned int R6Abstract_AR6AbstractHUD_CopyConstructorSlot = 0x1001652c;

// R6Game.dll data @ 10016530 : R6Abstract.dll R6Abstract_UR6AbstractGameService_PrivateStaticClass import address word
constexpr unsigned int R6Abstract_UR6AbstractGameService_PrivateStaticClassSlot = 0x10016530;

// R6Game.dll data @ 10016534 : R6Abstract.dll R6Abstract_AR6AbstractGameInfo_OperatorAssign import address word
constexpr unsigned int R6Abstract_AR6AbstractGameInfo_OperatorAssignSlot = 0x10016534;

// R6Game.dll data @ 10016538 : R6Abstract.dll R6Abstract_AR6AbstractHUD_OperatorAssign import address word
constexpr unsigned int R6Abstract_AR6AbstractHUD_OperatorAssignSlot = 0x10016538;

// R6Game.dll data @ 1001653c : R6Abstract.dll R6Abstract_AR6AbstractGameInfo_Destructor import address word
constexpr unsigned int R6Abstract_AR6AbstractGameInfo_DestructorSlot = 0x1001653c;

// R6Game.dll data @ 10016540 : R6Abstract.dll R6Abstract_AR6AbstractGameInfo_Constructor_10016540 import address word
constexpr unsigned int R6Abstract_AR6AbstractGameInfo_CopyConstructorSlot = 0x10016540;

// R6Game.dll data @ 10016544 : R6Abstract.dll R6Abstract_AR6AbstractHUD_Destructor import address word
constexpr unsigned int R6Abstract_AR6AbstractHUD_DestructorSlot = 0x10016544;

// R6Game.dll data @ 10016548 : R6Abstract.dll R6Abstract_AR6AbstractHUD_Constructor_10016548 import address word
constexpr unsigned int R6Abstract_AR6AbstractHUD_DefaultConstructorSlot = 0x10016548;

// R6Game.dll data @ 1001654c : R6Abstract.dll null import delimiter
constexpr unsigned int R6Abstract_ImportTerminatorSlot = 0x1001654c;

// R6Game.dll data @ 10016550 : R6Engine.dll R6Engine_AR6PlayerController_eventClientNotifySendStartMatch import address word
constexpr unsigned int R6Engine_AR6PlayerController_eventClientNotifySendStartMatchSlot = 0x10016550;

// R6Game.dll data @ 10016554 : R6Engine.dll R6Engine_AR6PlayerController_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6PlayerController_PrivateStaticClassSlot = 0x10016554;

// R6Game.dll data @ 10016558 : R6Engine.dll R6Engine_AR6PlayerController_eventClientVoteSessionAbort import address word
constexpr unsigned int R6Engine_AR6PlayerController_eventClientVoteSessionAbortSlot = 0x10016558;

// R6Game.dll data @ 1001655c : R6Engine.dll R6Engine_AR6GameReplicationInfo_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6GameReplicationInfo_PrivateStaticClassSlot = 0x1001655c;

// R6Game.dll data @ 10016560 : R6Engine.dll R6Engine_AR6PlayerController_GetLocKeyNameByActionKey import address word
constexpr unsigned int R6Engine_AR6PlayerController_GetLocKeyNameByActionKeySlot = 0x10016560;

// R6Game.dll data @ 10016564 : R6Engine.dll R6Engine_AR6RainbowAI_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6RainbowAI_PrivateStaticClassSlot = 0x10016564;

// R6Game.dll data @ 10016568 : R6Engine.dll R6Engine_AR6Pawn_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6Pawn_PrivateStaticClassSlot = 0x10016568;

// R6Game.dll data @ 1001656c : R6Engine.dll R6Engine_AR6TeamMemberReplicationInfo_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6TeamMemberReplicationInfo_PrivateStaticClassSlot = 0x1001656c;

// R6Game.dll data @ 10016570 : R6Engine.dll R6Engine_AR6Rainbow_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6Rainbow_PrivateStaticClassSlot = 0x10016570;

// R6Game.dll data @ 10016574 : R6Engine.dll R6Engine_AR6StairVolume_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6StairVolume_PrivateStaticClassSlot = 0x10016574;

// R6Game.dll data @ 10016578 : R6Engine.dll R6Engine_AR6Stairs_PrivateStaticClass import address word
constexpr unsigned int R6Engine_AR6Stairs_PrivateStaticClassSlot = 0x10016578;

// R6Game.dll data @ 1001657c : R6Engine.dll R6Engine_AR6PlayerController_eventClientNotifySendMatchResults import address word
constexpr unsigned int R6Engine_AR6PlayerController_eventClientNotifySendMatchResultsSlot = 0x1001657c;

// R6Game.dll data @ 10016580 : R6Engine.dll R6Engine_AR6PlayerController_eventClientUpdateLadderStat import address word
constexpr unsigned int R6Engine_AR6PlayerController_eventClientUpdateLadderStatSlot = 0x10016580;

// R6Game.dll data @ 10016584 : R6Engine.dll null import delimiter
constexpr unsigned int R6Engine_ImportTerminatorSlot = 0x10016584;

// R6Game.dll data @ 10016588 : R6Weapons.dll R6Weapons_AR6Gadget_PrivateStaticClass import address word
constexpr unsigned int R6Weapons_AR6Gadget_PrivateStaticClassSlot = 0x10016588;

// R6Game.dll data @ 1001658c : R6Weapons.dll R6Weapons_AR6Weapons_PrivateStaticClass import address word
constexpr unsigned int R6Weapons_AR6Weapons_PrivateStaticClassSlot = 0x1001658c;

// R6Game.dll data @ 10016590 : R6Weapons.dll null import delimiter
constexpr unsigned int R6Weapons_ImportTerminatorSlot = 0x10016590;
}

class UClass;
using ImportedArrayElementConstructor = void (__thiscall *)(void*);

// Each address view performs one IAT load at its use site. Existing locals retain explicit capture lifetimes.
// Global pointer variables require their existing second dereference; GNatives and imported class objects do not.
// The static-constructor view forwards a raw native member-function address; it does not invent a host member pointer.
#define ImportedAControllerClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_AController_PrivateStaticClassSlot))
#define ImportedAPlayerControllerClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_APlayerController_PrivateStaticClassSlot))
#define ImportedAR6AbstractGameInfoClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Abstract_AR6AbstractGameInfo_PrivateStaticClassSlot))
#define ImportedAR6AbstractHUDClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Abstract_AR6AbstractHUD_PrivateStaticClassSlot))
#define ImportedAR6ActionPointAbstractClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_AR6ActionPointAbstract_PrivateStaticClassSlot))
#define ImportedAR6GameReplicationInfoClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6GameReplicationInfo_PrivateStaticClassSlot))
#define ImportedAR6PawnClass (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6Pawn_PrivateStaticClassSlot))
#define ImportedAR6PlayerControllerClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6PlayerController_PrivateStaticClassSlot))
#define ImportedAR6RainbowAIClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6RainbowAI_PrivateStaticClassSlot))
#define ImportedAR6StairVolumeClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6StairVolume_PrivateStaticClassSlot))
#define ImportedAR6StairsClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6Stairs_PrivateStaticClassSlot))
#define ImportedAR6TeamMemberReplicationInfoClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Engine_AR6TeamMemberReplicationInfo_PrivateStaticClassSlot))
#define ImportedAR6WeaponsClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Weapons_AR6Weapons_PrivateStaticClassSlot))
#define ImportedAVolumeClass (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_AVolume_PrivateStaticClassSlot))
#define ImportedFColorConstructor \
    (*reinterpret_cast<ImportedArrayElementConstructor const*>(R6GameImports::Engine_FColor_ConstructorSlot))
#define ImportedVectorZeroAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_FVector_FVector0Slot))
#define ImportedGErrorAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GErrorSlot))
#define ImportedGFileManagerAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GFileManagerSlot))
#define ImportedGGameOptionsAddress (*reinterpret_cast<void* const*>(R6GameImports::Engine_GGameOptionsSlot))
#define ImportedGGlobalTempObjectsAddress \
    (*reinterpret_cast<void* const*>(R6GameImports::Engine_GGlobalTempObjectsSlot))
#define ImportedGLogAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GLogSlot))
#define ImportedGMallocAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GMallocSlot))
#define ImportedGMathAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GMathSlot))
#define ImportedGModMgrAddress (*reinterpret_cast<void* const*>(R6GameImports::Engine_GModMgrSlot))
#define ImportedGNativesAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GNativesSlot))
#define ImportedGNullAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GNullSlot))
#define ImportedGPropAddrAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GPropAddrSlot))
#define ImportedGPropObjectAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GPropObjectSlot))
#define ImportedGPropertyAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GPropertySlot))
#define ImportedGR6GameManagerAddress (*reinterpret_cast<void* const*>(R6GameImports::Engine_GR6GameManagerSlot))
#define ImportedGSecondsPerCycleAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GSecondsPerCycleSlot))
#define ImportedGWarnAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_GWarnSlot))
#define ImportedMatrixIdentityAddress (*reinterpret_cast<void* const*>(R6GameImports::Core_FMatrix_IdentitySlot))
#define ImportedUClassClass (*reinterpret_cast<UClass* const*>(R6GameImports::Core_UClass_PrivateStaticClassSlot))
#define ImportedUFinalBlendClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UFinalBlend_PrivateStaticClassSlot))
#define ImportedUMaterialClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UMaterial_PrivateStaticClassSlot))
#define ImportedUObjectClass (*reinterpret_cast<UClass* const*>(R6GameImports::Core_UObject_PrivateStaticClassSlot))
#define ImportedUObjectStaticConstructorAddress \
    (*reinterpret_cast<void* const*>(R6GameImports::Core_UObject_StaticConstructorSlot))
#define ImportedUR6AbstractGameManagerClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UR6AbstractGameManager_PrivateStaticClassSlot))
#define ImportedUR6AbstractGameServiceClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::R6Abstract_UR6AbstractGameService_PrivateStaticClassSlot))
#define ImportedUR6AbstractPlanningInfoClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UR6AbstractPlanningInfo_PrivateStaticClassSlot))
#define ImportedUR6FileManagerClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UR6FileManager_PrivateStaticClassSlot))
#define ImportedUViewportClass \
    (*reinterpret_cast<UClass* const*>(R6GameImports::Engine_UViewport_PrivateStaticClassSlot))
#define Importedg_pEngineAddress (*reinterpret_cast<void* const*>(R6GameImports::Engine_g_pEngineSlot))
