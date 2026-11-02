#include "native_exported_data.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005509c : nativeTextAdjustPawnForDiagonalStrafing
extern const ushort nativeTextAdjustPawnForDiagonalStrafing[30];

// R6Engine.dll data @ 10054ba8 : nativeTextAnimFinished
extern const ushort nativeTextAnimFinished[13];

// R6Engine.dll data @ 10054d18 : nativeTextAttackTimer
extern const ushort nativeTextAttackTimer[12];

// R6Engine.dll data @ 10054d50 : nativeTextCanOpenDoor
extern const ushort nativeTextCanOpenDoor[12];

// R6Engine.dll data @ 100549ec : nativeTextClientNotifySendMatchResults
extern const ushort nativeTextClientNotifySendMatchResults[29];

// R6Engine.dll data @ 10054a88 : nativeTextClientNotifySendStartMatch
extern const ushort nativeTextClientNotifySendStartMatch[27];

// R6Engine.dll data @ 10054d84 : nativeTextClientPlayVoices
extern const ushort nativeTextClientPlayVoices[17];

// R6Engine.dll data @ 10054a58 : nativeTextClientUpdateLadderStat
extern const ushort nativeTextClientUpdateLadderStat[23];

// R6Engine.dll data @ 10054a28 : nativeTextClientVoteSessionAbort
extern const ushort nativeTextClientVoteSessionAbort[23];

// R6Engine.dll data @ 1005512c : nativeTextEndCrawl
extern const ushort nativeTextEndCrawl[9];

// R6Engine.dll data @ 10054fa4 : nativeTextEndOfGrenadeEffect
extern const ushort nativeTextEndOfGrenadeEffect[19];

// R6Engine.dll data @ 10055210 : nativeTextEndPeekingMode
extern const ushort nativeTextEndPeekingMode[15];

// R6Engine.dll data @ 10054eb8 : nativeTextFinishInitialization
extern const ushort nativeTextFinishInitialization[21];

// R6Engine.dll data @ 100552f8 : nativeTextGetFiringStartPoint
extern const ushort nativeTextGetFiringStartPoint[20];

// R6Engine.dll data @ 10055348 : nativeTextGetRoundTime
extern const ushort nativeTextGetRoundTime[13];

// R6Engine.dll data @ 10054fcc : nativeTextGetStanceReticuleModifier
extern const ushort nativeTextGetStanceReticuleModifier[26];

// R6Engine.dll data @ 10054da8 : nativeTextGetZoomMultiplyFactor
extern const ushort nativeTextGetZoomMultiplyFactor[22];

// R6Engine.dll data @ 10054e74 : nativeTextGotoCrouch
extern const ushort nativeTextGotoCrouch[11];

// R6Engine.dll data @ 10054e48 : nativeTextGotoFoetus
extern const ushort nativeTextGotoFoetus[11];

// R6Engine.dll data @ 10054e60 : nativeTextGotoKneel
extern const ushort nativeTextGotoKneel[10];

// R6Engine.dll data @ 10054cd8 : nativeTextGotoPointAndSearch
extern const ushort nativeTextGotoPointAndSearch[19];

// R6Engine.dll data @ 10054cb4 : nativeTextGotoPointToAttack
extern const ushort nativeTextGotoPointToAttack[18];

// R6Engine.dll data @ 10054e34 : nativeTextGotoProne
extern const ushort nativeTextGotoProne[10];

// R6Engine.dll data @ 10054e8c : nativeTextGotoStand
extern const ushort nativeTextGotoStand[10];

// R6Engine.dll data @ 10054c84 : nativeTextGotoStateEngageByThreat
extern const ushort nativeTextGotoStateEngageByThreat[24];

// R6Engine.dll data @ 10054f30 : nativeTextInitBiPodPosture
extern const ushort nativeTextInitBiPodPosture[17];

// R6Engine.dll data @ 100551ec : nativeTextIsFullPeekingOver
extern const ushort nativeTextIsFullPeekingOver[18];

// R6Engine.dll data @ 10055278 : nativeTextIsPeekingLeft
extern const ushort nativeTextIsPeekingLeft[14];

// R6Engine.dll data @ 10054b68 : nativeTextLoopSpecialAnim
extern const ushort nativeTextLoopSpecialAnim[16];

// R6Engine.dll data @ 10054d30 : nativeTextOpenDoorFailed
extern const ushort nativeTextOpenDoorFailed[15];

// R6Engine.dll data @ 1005517c : nativeTextPlayCrouchToProne
extern const ushort nativeTextPlayCrouchToProne[18];

// R6Engine.dll data @ 100551a0 : nativeTextPlayFluidPeekingAnim
extern const ushort nativeTextPlayFluidPeekingAnim[21];

// R6Engine.dll data @ 100551cc : nativeTextPlayPeekingAnim
extern const ushort nativeTextPlayPeekingAnim[16];

// R6Engine.dll data @ 10055158 : nativeTextPlayProneToCrouch
extern const ushort nativeTextPlayProneToCrouch[18];

// R6Engine.dll data @ 10054b88 : nativeTextPlaySpecialAnim
extern const ushort nativeTextPlaySpecialAnim[16];

// R6Engine.dll data @ 10054f70 : nativeTextPlaySpecialPendingAction
extern const ushort nativeTextPlaySpecialPendingAction[25];

// R6Engine.dll data @ 10055000 : nativeTextPlaySurfaceSwitch
extern const ushort nativeTextPlaySurfaceSwitch[18];

// R6Engine.dll data @ 10054dd4 : nativeTextPlayerTeamSelectionReceived
extern const ushort nativeTextPlayerTeamSelectionReceived[28];

// R6Engine.dll data @ 10055364 : nativeTextPostRender
extern const ushort nativeTextPostRender[11];

// R6Engine.dll data @ 10055108 : nativeTextPotentialOpenDoor
extern const ushort nativeTextPotentialOpenDoor[18];

// R6Engine.dll data @ 100549d0 : nativeTextR6EngineInit
extern const ushort nativeTextR6EngineInit[13];

// R6Engine.dll data @ 10055320 : nativeTextR6MakeMovementNoise
extern const ushort nativeTextR6MakeMovementNoise[20];

// R6Engine.dll data @ 10055024 : nativeTextR6ResetLookDirection
extern const ushort nativeTextR6ResetLookDirection[21];

// R6Engine.dll data @ 10054d68 : nativeTextR6SetMovement
extern const ushort nativeTextR6SetMovement[14];

// R6Engine.dll data @ 10054b24 : nativeTextReinitSimulation
extern const ushort nativeTextReinitSimulation[17];

// R6Engine.dll data @ 100550d8 : nativeTextRemovePotentialOpenDoor
extern const ushort nativeTextRemovePotentialOpenDoor[24];

// R6Engine.dll data @ 10054c08 : nativeTextRequestFormationChange
extern const ushort nativeTextRequestFormationChange[23];

// R6Engine.dll data @ 10054f0c : nativeTextResetBipodPosture
extern const ushort nativeTextResetBipodPosture[18];

// R6Engine.dll data @ 10055070 : nativeTextResetDiagonalStrafing
extern const ushort nativeTextResetDiagonalStrafing[22];

// R6Engine.dll data @ 10054be8 : nativeTextSequenceChanged
extern const ushort nativeTextSequenceChanged[16];

// R6Engine.dll data @ 10054bc4 : nativeTextSequenceFinished
extern const ushort nativeTextSequenceFinished[17];

// R6Engine.dll data @ 10054ea0 : nativeTextSetAnimInfo
extern const ushort nativeTextSetAnimInfo[12];

// R6Engine.dll data @ 10055294 : nativeTextSetCrouchBlend
extern const ushort nativeTextSetCrouchBlend[15];

// R6Engine.dll data @ 10054c60 : nativeTextSetNewDamageState
extern const ushort nativeTextSetNewDamageState[18];

// R6Engine.dll data @ 100552b4 : nativeTextSetPeekingInfo
extern const ushort nativeTextSetPeekingInfo[15];

// R6Engine.dll data @ 10054e0c : nativeTextSetPotentialClimber
extern const ushort nativeTextSetPotentialClimber[20];

// R6Engine.dll data @ 100552d4 : nativeTextSetRotationOffset
extern const ushort nativeTextSetRotationOffset[18];

// R6Engine.dll data @ 10054f54 : nativeTextSpawnRagDoll
extern const ushort nativeTextSpawnRagDoll[13];

// R6Engine.dll data @ 10055140 : nativeTextStartCrawl
extern const ushort nativeTextStartCrawl[11];

// R6Engine.dll data @ 10055254 : nativeTextStartFluidPeeking
extern const ushort nativeTextStartFluidPeeking[18];

// R6Engine.dll data @ 10055230 : nativeTextStartFullPeeking
extern const ushort nativeTextStartFullPeeking[17];

// R6Engine.dll data @ 10054ae4 : nativeTextStartSimulation
extern const ushort nativeTextStartSimulation[16];

// R6Engine.dll data @ 10054d00 : nativeTextStopAttack
extern const ushort nativeTextStopAttack[11];

// R6Engine.dll data @ 10054b04 : nativeTextStopSimulation
extern const ushort nativeTextStopSimulation[15];

// R6Engine.dll data @ 10054b48 : nativeTextStopSpecialAnim
extern const ushort nativeTextStopSpecialAnim[16];

// R6Engine.dll data @ 10055050 : nativeTextTurnToFaceActor
extern const ushort nativeTextTurnToFaceActor[16];

// R6Engine.dll data @ 10054ee4 : nativeTextUpdateBipodPosture
extern const ushort nativeTextUpdateBipodPosture[19];

// R6Engine.dll data @ 10054c38 : nativeTextUpdateTeamFormation
extern const ushort nativeTextUpdateTeamFormation[20];

// R6Engine.dll data @ 10054ac0 : nativeTextZDRSetDamageState
extern const ushort nativeTextZDRSetDamageState[18];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl EventNamesCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl EventNamesCatchPointer(void);

// R6Engine.dll data @ 1007d9f4 : eventNameRegistrationIdentity
// Address identity passed in ECX; the initializer returns it without reading or writing its payload.
byte eventNameRegistrationIdentity = 0;

// R6Engine.dll data @ 10077df8 : R6ENGINE_PostRender
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PostRender;

// R6Engine.dll data @ 100830b8 : R6ENGINE_GetRoundTime
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GetRoundTime;

// R6Engine.dll data @ 10078d38 : R6ENGINE_R6MakeMovementNoise
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_R6MakeMovementNoise;

// R6Engine.dll data @ 1007cfa4 : R6ENGINE_GetFiringStartPoint
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GetFiringStartPoint;

// R6Engine.dll data @ 1007df24 : R6ENGINE_SetRotationOffset
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetRotationOffset;

// R6Engine.dll data @ 1007ca8c : R6ENGINE_SetPeekingInfo
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetPeekingInfo;

// R6Engine.dll data @ 1007fdcc : R6ENGINE_SetCrouchBlend
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetCrouchBlend;

// R6Engine.dll data @ 1007a1bc : R6ENGINE_IsPeekingLeft
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_IsPeekingLeft;

// R6Engine.dll data @ 1007d4cc : R6ENGINE_StartFluidPeeking
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StartFluidPeeking;

// R6Engine.dll data @ 1007e954 : R6ENGINE_StartFullPeeking
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StartFullPeeking;

// R6Engine.dll data @ 1007df18 : R6ENGINE_EndPeekingMode
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_EndPeekingMode;

// R6Engine.dll data @ 1007e944 : R6ENGINE_IsFullPeekingOver
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_IsFullPeekingOver;

// R6Engine.dll data @ 10082694 : R6ENGINE_PlayPeekingAnim
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlayPeekingAnim;

// R6Engine.dll data @ 10078d3c : R6ENGINE_PlayFluidPeekingAnim
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlayFluidPeekingAnim;

// R6Engine.dll data @ 1007abf0 : R6ENGINE_PlayCrouchToProne
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlayCrouchToProne;

// R6Engine.dll data @ 1007c574 : R6ENGINE_PlayProneToCrouch
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlayProneToCrouch;

// R6Engine.dll data @ 100802f0 : R6ENGINE_StartCrawl
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StartCrawl;

// R6Engine.dll data @ 1007d9f0 : R6ENGINE_EndCrawl
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_EndCrawl;

// R6Engine.dll data @ 10081738 : R6ENGINE_PotentialOpenDoor
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PotentialOpenDoor;

// R6Engine.dll data @ 10076490 : R6ENGINE_RemovePotentialOpenDoor
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_RemovePotentialOpenDoor;

// R6Engine.dll data @ 10079258 : R6ENGINE_AdjustPawnForDiagonalStrafing
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_AdjustPawnForDiagonalStrafing;

// R6Engine.dll data @ 10081c50 : R6ENGINE_ResetDiagonalStrafing
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ResetDiagonalStrafing;

// R6Engine.dll data @ 1007a1a4 : R6ENGINE_TurnToFaceActor
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_TurnToFaceActor;

// R6Engine.dll data @ 1007b640 : R6ENGINE_R6ResetLookDirection
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_R6ResetLookDirection;

// R6Engine.dll data @ 10080808 : R6ENGINE_PlaySurfaceSwitch
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlaySurfaceSwitch;

// R6Engine.dll data @ 1007d4b8 : R6ENGINE_GetStanceReticuleModifier
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GetStanceReticuleModifier;

// R6Engine.dll data @ 1007ee74 : R6ENGINE_EndOfGrenadeEffect
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_EndOfGrenadeEffect;

// R6Engine.dll data @ 10078d40 : R6ENGINE_PlaySpecialPendingAction
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlaySpecialPendingAction;

// R6Engine.dll data @ 10082690 : R6ENGINE_SpawnRagDoll
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SpawnRagDoll;

// R6Engine.dll data @ 1007d9e8 : R6ENGINE_InitBiPodPosture
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_InitBiPodPosture;

// R6Engine.dll data @ 10082178 : R6ENGINE_ResetBipodPosture
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ResetBipodPosture;

// R6Engine.dll data @ 10077dfc : R6ENGINE_UpdateBipodPosture
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_UpdateBipodPosture;

// R6Engine.dll data @ 10081c48 : R6ENGINE_FinishInitialization
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_FinishInitialization;

// R6Engine.dll data @ 100769a4 : R6ENGINE_SetAnimInfo
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetAnimInfo;

// R6Engine.dll data @ 1007cfa0 : R6ENGINE_GotoStand
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoStand;

// R6Engine.dll data @ 1007a6d4 : R6ENGINE_GotoCrouch
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoCrouch;

// R6Engine.dll data @ 10078d48 : R6ENGINE_GotoKneel
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoKneel;

// R6Engine.dll data @ 1007ee68 : R6ENGINE_GotoFoetus
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoFoetus;

// R6Engine.dll data @ 1007b128 : R6ENGINE_GotoProne
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoProne;

// R6Engine.dll data @ 1007d4c8 : R6ENGINE_SetPotentialClimber
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetPotentialClimber;

// R6Engine.dll data @ 1007e940 : R6ENGINE_PlayerTeamSelectionReceived
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlayerTeamSelectionReceived;

// R6Engine.dll data @ 1007abec : R6ENGINE_GetZoomMultiplyFactor
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GetZoomMultiplyFactor;

// R6Engine.dll data @ 1007ac14 : R6ENGINE_ClientPlayVoices
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ClientPlayVoices;

// R6Engine.dll data @ 1007df1c : R6ENGINE_R6SetMovement
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_R6SetMovement;

// R6Engine.dll data @ 1007a194 : R6ENGINE_CanOpenDoor
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_CanOpenDoor;

// R6Engine.dll data @ 10082174 : R6ENGINE_OpenDoorFailed
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_OpenDoorFailed;

// R6Engine.dll data @ 100802d8 : R6ENGINE_AttackTimer
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_AttackTimer;

// R6Engine.dll data @ 10078318 : R6ENGINE_StopAttack
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StopAttack;

// R6Engine.dll data @ 1007c56c : R6ENGINE_GotoPointAndSearch
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoPointAndSearch;

// R6Engine.dll data @ 1007f388 : R6ENGINE_GotoPointToAttack
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoPointToAttack;

// R6Engine.dll data @ 1007da08 : R6ENGINE_GotoStateEngageByThreat
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_GotoStateEngageByThreat;

// R6Engine.dll data @ 10078d44 : R6ENGINE_SetNewDamageState
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SetNewDamageState;

// R6Engine.dll data @ 1007ac04 : R6ENGINE_UpdateTeamFormation
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_UpdateTeamFormation;

// R6Engine.dll data @ 1007e958 : R6ENGINE_RequestFormationChange
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_RequestFormationChange;

// R6Engine.dll data @ 10079770 : R6ENGINE_SequenceChanged
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SequenceChanged;

// R6Engine.dll data @ 1007abfc : R6ENGINE_SequenceFinished
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_SequenceFinished;

// R6Engine.dll data @ 1007a1b4 : R6ENGINE_AnimFinished
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_AnimFinished;

// R6Engine.dll data @ 100769a8 : R6ENGINE_PlaySpecialAnim
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_PlaySpecialAnim;

// R6Engine.dll data @ 1007c578 : R6ENGINE_LoopSpecialAnim
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_LoopSpecialAnim;

// R6Engine.dll data @ 1007e948 : R6ENGINE_StopSpecialAnim
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StopSpecialAnim;

// R6Engine.dll data @ 1008269c : R6ENGINE_ReinitSimulation
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ReinitSimulation;

// R6Engine.dll data @ 1007d4c0 : R6ENGINE_StopSimulation
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StopSimulation;

// R6Engine.dll data @ 1007abe8 : R6ENGINE_StartSimulation
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_StartSimulation;

// R6Engine.dll data @ 1007fdb8 : R6ENGINE_ZDRSetDamageState
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ZDRSetDamageState;

// R6Engine.dll data @ 1007fdc4 : R6ENGINE_ClientNotifySendStartMatch
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ClientNotifySendStartMatch;

// R6Engine.dll data @ 100773dc : R6ENGINE_ClientUpdateLadderStat
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ClientUpdateLadderStat;

// R6Engine.dll data @ 1007ee78 : R6ENGINE_ClientVoteSessionAbort
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ClientVoteSessionAbort;

// R6Engine.dll data @ 1007f38c : R6ENGINE_ClientNotifySendMatchResults
// Exported four-byte FName starts in loader zero-fill and receives the constructor-returned name word.
FName R6ENGINE_ClientNotifySendMatchResults;

// R6Engine.dll data @ 1005e414 : eventNamesUnwindMap
// Both states unwind to -1 with no cleanup action.
const NativeUnwindEntry eventNamesUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e424 : eventNamesCatchMap
// Two four-word handlers: unsigned-short pointer at EBP-0x1c, then catch-all.
const NativeCatchEntry eventNamesCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&EventNamesCatchPointer) },
    { 0, 0, 0, ((uint)&EventNamesCatchContext) }
};

// R6Engine.dll data @ 1005e444 : eventNamesTryMap
// Try state0, catch state1 and two handlers.
const NativeTryBlock eventNamesTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&eventNamesCatchMap) }
};

// R6Engine.dll data @ 1005e458 : eventNamesFuncInfo
// MSVC magic19930520, two states, one try block and no IP-state map.
const NativeFunctionInfoPrefix eventNamesFuncInfo = { 0x19930520, 0x2, ((uint)&eventNamesUnwindMap), 0x1,
    ((uint)&eventNamesTryMap), 0 };

// Routes initializer exceptions through its selected FuncInfo.
__declspec(naked) void __cdecl EventNamesExceptionHandler(void);

// R6Engine.dll @ 1003f7e0 : InitializeR6EngineEventNames
// Constructs all exported event names with mode2, preserving the receiver identity and native private EH frame.
__declspec(naked) void* __fastcall InitializeR6EngineEventNames(void* registrationIdentity)
{
    // EBP-0x18 is one reused four-byte FName; EBP-0x1c/-0x14 hold caught/forwarded pointer words.
    __asm {
        push ebp
        mov ebp,esp
        push -1
        push offset EventNamesExceptionHandler
        mov eax,dword ptr fs:[0]
        push eax
        mov dword ptr fs:[0],esp
        sub esp,0x10
        push ebx
        push esi
        mov esi,dword ptr [FNameConstructorImport] // Capture the imported FName constructor once.
        push edi
        mov dword ptr [ebp-0x10],esp // Saved ESP for native exception dispatch.
        push 0x2
        mov edi,ecx
        push offset nativeTextPostRender // L"PostRender".
        lea ecx,[ebp-0x18]
        mov dword ptr [ebp-0x4],0x0
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextGetRoundTime // L"GetRoundTime".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PostRender],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GetRoundTime],ecx
        push offset nativeTextR6MakeMovementNoise // L"R6MakeMovementNoise".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextGetFiringStartPoint // L"GetFiringStartPoint".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_R6MakeMovementNoise],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextSetRotationOffset // L"SetRotationOffset".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GetFiringStartPoint],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_SetRotationOffset],ecx
        push offset nativeTextSetPeekingInfo // L"SetPeekingInfo".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextSetCrouchBlend // L"SetCrouchBlend".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SetPeekingInfo],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextIsPeekingLeft // L"IsPeekingLeft".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SetCrouchBlend],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_IsPeekingLeft],ecx
        push offset nativeTextStartFluidPeeking // L"StartFluidPeeking".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextStartFullPeeking // L"StartFullPeeking".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_StartFluidPeeking],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextEndPeekingMode // L"EndPeekingMode".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_StartFullPeeking],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_EndPeekingMode],ecx
        push offset nativeTextIsFullPeekingOver // L"IsFullPeekingOver".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_IsFullPeekingOver],edx
        push offset nativeTextPlayPeekingAnim // L"PlayPeekingAnim".
        lea ecx,[ebp-0x18]
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextPlayFluidPeekingAnim // L"PlayFluidPeekingAnim".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlayPeekingAnim],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_PlayFluidPeekingAnim],ecx
        push offset nativeTextPlayCrouchToProne // L"PlayCrouchToProne".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextPlayProneToCrouch // L"PlayProneToCrouch".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlayCrouchToProne],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextStartCrawl // L"StartCrawl".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlayProneToCrouch],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_StartCrawl],ecx
        push offset nativeTextEndCrawl // L"EndCrawl".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextPotentialOpenDoor // L"PotentialOpenDoor".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_EndCrawl],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextRemovePotentialOpenDoor // L"RemovePotentialOpenDoor".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PotentialOpenDoor],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_RemovePotentialOpenDoor],ecx
        push offset nativeTextAdjustPawnForDiagonalStrafing // L"AdjustPawnForDiagonalStrafing".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextResetDiagonalStrafing // L"ResetDiagonalStrafing".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_AdjustPawnForDiagonalStrafing],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextTurnToFaceActor // L"TurnToFaceActor".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ResetDiagonalStrafing],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_TurnToFaceActor],ecx
        push offset nativeTextR6ResetLookDirection // L"R6ResetLookDirection".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextPlaySurfaceSwitch // L"PlaySurfaceSwitch".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_R6ResetLookDirection],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextGetStanceReticuleModifier // L"GetStanceReticuleModifier".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlaySurfaceSwitch],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GetStanceReticuleModifier],ecx
        push offset nativeTextEndOfGrenadeEffect // L"EndOfGrenadeEffect".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextPlaySpecialPendingAction // L"PlaySpecialPendingAction".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_EndOfGrenadeEffect],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextSpawnRagDoll // L"SpawnRagDoll".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlaySpecialPendingAction],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_SpawnRagDoll],ecx
        push offset nativeTextInitBiPodPosture // L"InitBiPodPosture".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextResetBipodPosture // L"ResetBipodPosture".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_InitBiPodPosture],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextUpdateBipodPosture // L"UpdateBipodPosture".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ResetBipodPosture],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_UpdateBipodPosture],ecx
        push offset nativeTextFinishInitialization // L"FinishInitialization".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextSetAnimInfo // L"SetAnimInfo".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_FinishInitialization],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextGotoStand // L"GotoStand".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SetAnimInfo],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GotoStand],ecx
        push offset nativeTextGotoCrouch // L"GotoCrouch".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextGotoKneel // L"GotoKneel".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GotoCrouch],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextGotoFoetus // L"GotoFoetus".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GotoKneel],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GotoFoetus],ecx
        push offset nativeTextGotoProne // L"GotoProne".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GotoProne],edx
        push offset nativeTextSetPotentialClimber // L"SetPotentialClimber".
        lea ecx,[ebp-0x18]
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextPlayerTeamSelectionReceived // L"PlayerTeamSelectionReceived".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SetPotentialClimber],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_PlayerTeamSelectionReceived],ecx
        push offset nativeTextGetZoomMultiplyFactor // L"GetZoomMultiplyFactor".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextClientPlayVoices // L"ClientPlayVoices".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GetZoomMultiplyFactor],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextR6SetMovement // L"R6SetMovement".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ClientPlayVoices],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_R6SetMovement],ecx
        push offset nativeTextCanOpenDoor // L"CanOpenDoor".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextOpenDoorFailed // L"OpenDoorFailed".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_CanOpenDoor],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextAttackTimer // L"AttackTimer".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_OpenDoorFailed],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_AttackTimer],ecx
        push offset nativeTextStopAttack // L"StopAttack".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextGotoPointAndSearch // L"GotoPointAndSearch".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_StopAttack],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextGotoPointToAttack // L"GotoPointToAttack".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GotoPointAndSearch],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_GotoPointToAttack],ecx
        push offset nativeTextGotoStateEngageByThreat // L"GotoStateEngageByThreat".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextSetNewDamageState // L"SetNewDamageState".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_GotoStateEngageByThreat],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextUpdateTeamFormation // L"UpdateTeamFormation".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SetNewDamageState],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_UpdateTeamFormation],ecx
        push offset nativeTextRequestFormationChange // L"RequestFormationChange".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextSequenceChanged // L"SequenceChanged".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_RequestFormationChange],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextSequenceFinished // L"SequenceFinished".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_SequenceChanged],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_SequenceFinished],ecx
        push offset nativeTextAnimFinished // L"AnimFinished".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextPlaySpecialAnim // L"PlaySpecialAnim".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_AnimFinished],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextLoopSpecialAnim // L"LoopSpecialAnim".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_PlaySpecialAnim],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_LoopSpecialAnim],ecx
        push offset nativeTextStopSpecialAnim // L"StopSpecialAnim".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextReinitSimulation // L"ReinitSimulation".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_StopSpecialAnim],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextStopSimulation // L"StopSimulation".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ReinitSimulation],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_StopSimulation],ecx
        push offset nativeTextStartSimulation // L"StartSimulation".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        push offset nativeTextZDRSetDamageState // L"ZDRSetDamageState".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_StartSimulation],edx
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextClientNotifySendStartMatch // L"ClientNotifySendStartMatch".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ZDRSetDamageState],eax
        call esi
        mov ecx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_ClientNotifySendStartMatch],ecx
        push offset nativeTextClientUpdateLadderStat // L"ClientUpdateLadderStat".
        lea ecx,[ebp-0x18]
        call esi
        mov edx,dword ptr [eax]
        push 0x2
        mov dword ptr [R6ENGINE_ClientUpdateLadderStat],edx
        push offset nativeTextClientVoteSessionAbort // L"ClientVoteSessionAbort".
        lea ecx,[ebp-0x18]
        call esi
        mov eax,dword ptr [eax]
        push 0x2
        push offset nativeTextClientNotifySendMatchResults // L"ClientNotifySendMatchResults".
        lea ecx,[ebp-0x18]
        mov dword ptr [R6ENGINE_ClientVoteSessionAbort],eax
        call esi
        mov ecx,dword ptr [eax]
        mov eax,edi
        pop edi
        mov dword ptr [R6ENGINE_ClientNotifySendMatchResults],ecx
        mov ecx,dword ptr [ebp-0xc]
        pop esi
        mov dword ptr fs:[0],ecx
        pop ebx
        mov esp,ebp
        pop ebp
        ret
    }
}

// R6Engine.dll @ 1003fd5c : EventNamesCatchPointer
// Rethrows the caught unsigned-short pointer by value through the inherited initializer frame.
__declspec(naked) __declspec(noreturn) void __cdecl EventNamesCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003fd70 : EventNamesCatchContext
// Reports the R6EngineInit context for other exceptions and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl EventNamesCatchContext(void)
{
    __asm {
        push offset nativeTextR6EngineInit // L"R6EngineInit".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100453f0 : EventNamesExceptionHandler
// Supplies the initializer's selected two-state FuncInfo to the shared C++ frame-handler gateway.
__declspec(naked) void __cdecl EventNamesExceptionHandler(void)
{
    __asm {
        mov eax,offset eventNamesFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047c80 : RegisterR6EngineEventNames
// Tail-enters event-name construction with the persistent registration identity in ECX.
__declspec(naked) void __cdecl RegisterR6EngineEventNames(void)
{
    __asm {
        mov ecx,offset eventNameRegistrationIdentity
        jmp InitializeR6EngineEventNames
    }
}
