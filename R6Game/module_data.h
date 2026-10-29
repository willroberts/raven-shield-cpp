#pragma once

// Shared native module data; DWORD metadata arrays preserve the selected 32-bit record layouts.
extern "C" unsigned short GPackage[7];
extern unsigned int VoidPointerTypeDescriptor[4];
extern unsigned int UnsignedShortPointerTypeDescriptor[4];
extern const unsigned int VoidPointerCatchableType[7];
extern const unsigned int UnsignedShortPointerCatchableType[7];
extern const unsigned int UnsignedShortPointerCatchableTypes[3];
extern const unsigned int UnsignedShortPointerThrowInfo[4];

// Class metadata backing memory has no implicit constructor; module startup constructs each UClass in place.
class UClass;
extern unsigned char AR6ActionPointClassMetadataStorage[0x508];
extern unsigned char AR6GameInfoClassMetadataStorage[0x508];
extern unsigned char AR6HUDClassMetadataStorage[0x508];
extern unsigned char AR6InstructionSoundVolumeClassMetadataStorage[0x508];
extern unsigned char AR6MultiPlayerGameInfoClassMetadataStorage[0x508];
extern unsigned char AR6PlanningCtrlClassMetadataStorage[0x508];
extern unsigned char AR6SoundVolumeClassMetadataStorage[0x508];
extern unsigned char AR6WaterVolumeClassMetadataStorage[0x508];
extern unsigned char UR6FileManagerCampaignClassMetadataStorage[0x508];
extern unsigned char UR6FileManagerPlanningClassMetadataStorage[0x508];
extern unsigned char UR6GameManagerClassMetadataStorage[0x508];
extern unsigned char UR6MissionRosterClassMetadataStorage[0x508];
extern unsigned char UR6OperativeClassMetadataStorage[0x508];
extern unsigned char UR6PlanningInfoClassMetadataStorage[0x508];
extern unsigned char UR6PlayerCampaignClassMetadataStorage[0x508];
extern unsigned char UR6PlayerCustomMissionClassMetadataStorage[0x508];

// Plain native data-export spellings bind selected pointers/words without recovering the original export mechanism.
extern "C" UClass* autoclassAR6ActionPoint;
extern "C" UClass* autoclassAR6GameInfo;
extern "C" UClass* autoclassAR6HUD;
extern "C" UClass* autoclassAR6InstructionSoundVolume;
extern "C" UClass* autoclassAR6MultiPlayerGameInfo;
extern "C" UClass* autoclassAR6PlanningCtrl;
extern "C" UClass* autoclassAR6SoundVolume;
extern "C" UClass* autoclassAR6WaterVolume;
extern "C" UClass* autoclassUR6FileManagerCampaign;
extern "C" UClass* autoclassUR6FileManagerPlanning;
extern "C" UClass* autoclassUR6GameManager;
extern "C" UClass* autoclassUR6MissionRoster;
extern "C" UClass* autoclassUR6Operative;
extern "C" UClass* autoclassUR6PlanningInfo;
extern "C" UClass* autoclassUR6PlayerCampaign;
extern "C" UClass* autoclassUR6PlayerCustomMission;
extern "C" unsigned int intAR6GameInfoexecGetSystemUserName;
extern "C" unsigned int intAR6GameInfoexecInitScoreSubmission;
extern "C" unsigned int intAR6GameInfoexecLogoutUpdatePlayersCtrlInfo;
extern "C" unsigned int intAR6GameInfoexecNativeLogout;
extern "C" unsigned int intAR6GameInfoexecSetController;
extern "C" unsigned int intAR6GameInfoexecSubmissionNotifySendStartMatch;
extern "C" unsigned int intAR6GameInfoexecSubmissionSrvRoundFinish;
extern "C" unsigned int intAR6GameInfoexecSubmissionSrvRoundStart;
extern "C" unsigned int intAR6GameInfoexecSubmissionUpdateLadderStat;
extern "C" unsigned int intAR6HUDexecDrawNativeHUD;
extern "C" unsigned int intAR6HUDexecHudStep;
extern "C" unsigned int intAR6InstructionSoundVolumeexecUseSound;
extern "C" unsigned int intAR6PlanningCtrlexecGetClickResult;
extern "C" unsigned int intAR6PlanningCtrlexecGetXYPoint;
extern "C" unsigned int intAR6PlanningCtrlexecPlanningTrace;
extern "C" unsigned int intUR6FileManagerCampaignexecLoadCampaign;
extern "C" unsigned int intUR6FileManagerCampaignexecSaveCampaign;
extern "C" unsigned int intUR6FileManagerPlanningexecGetNumberOfFiles;
extern "C" unsigned int intUR6FileManagerPlanningexecLoadPlanning;
extern "C" unsigned int intUR6FileManagerPlanningexecSavePlanning;
extern "C" unsigned int intUR6PlanningInfoexecAddToTeam;
extern "C" unsigned int intUR6PlanningInfoexecDeletePoint;
extern "C" unsigned int intUR6PlanningInfoexecFindPathToNextPoint;
extern "C" unsigned int intUR6PlanningInfoexecInsertToTeam;

// Shared native binary32 arithmetic constant at preferred VA 0x100170c0.
extern const float NativeFloatFive;

// Shared native binary32 arithmetic constant at preferred VA 0x1001822c.
extern const float NativeFloatFifty;
