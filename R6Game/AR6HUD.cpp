#include "native_addresses.h"

// R6Game.dll data @ 10018de8 : UTF-16 magazine-count prefix and signed-decimal format.
const unsigned short HudMagazineCountFormat[6] = {0x20, 0x78, 0x20, 0x25, 0x64, 0x0};

// R6Game.dll data @ 10018e00 : pooled rate-of-fire icon coordinate (descriptive name).
const float HudRateIconHeight = 20.0f;
// R6Game.dll data @ 10018dfc : pooled rate-of-fire icon coordinate (descriptive name).
const float HudRateIconBottom = 597.0f;
// R6Game.dll data @ 10018df8 : pooled rate-of-fire icon coordinate (descriptive name).
const float HudRateIconRight = 16.0f;
// R6Game.dll data @ 10018df4 : pooled rate-of-fire icon coordinate (descriptive name).
const float HudRateIconTop = 577.0f;

// R6Game.dll data @ 10018e9c : UTF-16 signed-decimal format used for native HUD bullet counts.
const unsigned short HudBulletCountFormat[3] = {0x25, 0x64, 0x0};

// R6Game.dll data @ 10018ea4 : UTF-16 separator between weapon and gadget short names.
const unsigned short HudWeaponNameSeparator[4] = {0x20, 0x2b, 0x20, 0x0};

// R6Game.dll data @ 10018eb8 : pooled weapon-icon coordinate (descriptive name).
const float HudWeaponIconBottom = 557.0f;
// R6Game.dll data @ 10018eb4 : pooled weapon-icon coordinate (descriptive name).
const float HudWeaponIconRight = 125.0f;
// R6Game.dll data @ 10018eb0 : pooled weapon-icon coordinate (descriptive name).
const float HudWeaponIconTop = 525.0f;
// R6Game.dll data @ 10018eac : pooled weapon-icon coordinate (descriptive name).
const float HudWeaponIconLeft = 25.0f;

// R6Game.dll data @ 10018ec8 : pooled weapon-panel bottom coordinate (descriptive name).
const float HudWeaponPanelBottom = 600.0f;
// R6Game.dll data @ 10018ec4 : pooled weapon-panel right edge coordinate (descriptive name).
const float HudWeaponPanelRight = 150.0f;
// R6Game.dll data @ 10018ec0 : pooled weapon-panel top coordinate (descriptive name).
const float HudWeaponPanelTop = 519.0f;
// R6Game.dll data @ 10018ebc : pooled weapon-panel outer right edge coordinate (descriptive name).
const float HudWeaponPanelOuterRight = 156.0f;

#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 1000f814 : inferred switch-table symbol for states 1..21; selected preferred VAs
const unsigned int HudTeamActionDispatchTargets[21] = {
    R6GameAddresses::HudTeamActionDispatchTargetsCase1, R6GameAddresses::HudTeamActionDispatchTargetsCase2, R6GameAddresses::HudTeamActionDispatchTargetsCase3, R6GameAddresses::HudTeamActionDispatchTargetsCase4, R6GameAddresses::HudTeamActionDispatchTargetsCase5, R6GameAddresses::HudTeamActionDispatchTargetsCase6, R6GameAddresses::HudTeamActionDispatchTargetsCase7,
    R6GameAddresses::HudTeamActionDispatchTargetsCase8, R6GameAddresses::HudTeamActionDispatchTargetsCase9, R6GameAddresses::HudTeamActionDispatchTargetsCase10, R6GameAddresses::HudTeamActionDispatchTargetsCase11, R6GameAddresses::HudTeamActionDispatchTargetsCase12, R6GameAddresses::HudTeamActionDispatchTargetsCase13, R6GameAddresses::HudTeamActionDispatchTargetsCase14,
    R6GameAddresses::HudTeamActionDispatchTargetsCase15, R6GameAddresses::HudTeamActionDispatchTargetsCase16, R6GameAddresses::HudTeamActionDispatchTargetsCase17, R6GameAddresses::HudTeamActionDispatchTargetsCase18, R6GameAddresses::HudTeamActionDispatchTargetsCase19, R6GameAddresses::HudTeamActionDispatchTargetsCase20, R6GameAddresses::HudTeamActionDispatchTargetsCase21
};

// R6Game.dll data @ 1000f868 : inferred go-code switch symbol; selected preferred VAs
const unsigned int HudWaitGoCodeDispatchTargets[4] = {
    R6GameAddresses::HudWaitGoCodeDispatchTargetsCase1, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase2, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase3, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase4
};

// R6Game.dll data @ 1000f878 : inferred go-code switch symbol; selected preferred VAs
const unsigned int HudSniperShortGoCodeDispatchTargets[4] = {
    R6GameAddresses::HudSniperShortGoCodeDispatchTargetsCase1, R6GameAddresses::HudSniperShortGoCodeDispatchTargetsCase2, R6GameAddresses::HudSniperShortGoCodeDispatchTargetsCase3, R6GameAddresses::HudSniperShortGoCodeDispatchTargetsCase4
};

// R6Game.dll data @ 1000f888 : inferred go-code switch symbol; selected preferred VAs
const unsigned int HudSniperFullGoCodeDispatchTargets[4] = {
    R6GameAddresses::HudWaitGoCodeDispatchTargetsCase1, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase2, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase3, R6GameAddresses::HudWaitGoCodeDispatchTargetsCase4
};

// R6Game.dll data @ 10018f30 : localized assault movement-mode key
const unsigned short HudMovementAssaultKey[13] = { // L"Mode_Assault"
    0x004d, 0x006f, 0x0064, 0x0065, 0x005f, 0x0041, 0x0073, 0x0073, 0x0061, 0x0075, 0x006c, 0x0074, 0x0000
};

// R6Game.dll data @ 10018f4c : localized infiltration movement-mode key
const unsigned short HudMovementInfiltrateKey[16] = { // L"Mode_Infiltrate"
    0x004d, 0x006f, 0x0064, 0x0065, 0x005f, 0x0049, 0x006e, 0x0066,
    0x0069, 0x006c, 0x0074, 0x0072, 0x0061, 0x0074, 0x0065, 0x0000
};

// R6Game.dll data @ 10018f6c : localized reconnaissance movement-mode key
const unsigned short HudMovementReconKey[11] = { // L"Mode_Recon"
    0x004d, 0x006f, 0x0064, 0x0065, 0x005f, 0x0052, 0x0065, 0x0063, 0x006f, 0x006e, 0x0000
};

// R6Game.dll data @ 10018f8c : native HUD horizontal scale per Canvas size unit
const float HudCanvasInverseReferenceWidth = 0.0012499999720603228f;

// R6Game.dll data @ 10018f88 : native HUD vertical scale per Canvas size unit
const float HudCanvasInverseReferenceHeight = 0.0016666667070239782f;

// R6Game.dll data @ 10018688 : pooled zero used by radar communication predicates
const float HudRadarZero = 0.0f;

// R6Game.dll data @ 10018f84 : radar upper-level marker threshold
const float HudRadarAboveLevelThreshold = 200.0f;

// R6Game.dll data @ 10018fb4 : radar lower-level marker threshold
const float HudRadarBelowLevelThreshold = -200.0f;

// R6Game.dll data @ 10018fbc : pooled float used for radar extent
const float HudRadarExtentFraction = 0.1666666716337204f;

// R6Game.dll data @ 10018fb8 : pooled float used for radar marker extent
const float HudRadarMarkerFraction = 0.0125f;

// R6Game.dll data @ 10018c40 : pooled float used for radar half extents
const float HudRadarHalf = 0.5f;

// R6Game.dll data @ 1000f898 : compiler switch targets for native HUD planning text
const unsigned int HudPlanningActionTargets[6] = {
    R6GameAddresses::HudPlanningActionTargetsCase1, R6GameAddresses::HudPlanningActionTargetsCase2, R6GameAddresses::HudPlanningActionTargetsCase3, R6GameAddresses::HudPlanningActionTargetsCase4, R6GameAddresses::HudPlanningActionTargetsCase5, R6GameAddresses::HudPlanningActionTargetsCase6
};

// R6Game.dll data @ 1000f8b0 : compiler switch targets for native HUD planning text
const unsigned int HudPlanningGoCodeTargets[4] = {
    R6GameAddresses::HudPlanningGoCodeTargetsCase1, R6GameAddresses::HudPlanningGoCodeTargetsCase2, R6GameAddresses::HudPlanningGoCodeTargetsCase3, R6GameAddresses::HudPlanningGoCodeTargetsCase4
};

// R6Game.dll data @ 1000f8c0 : compiler switch targets for native HUD planning text
const unsigned int HudPlanningPromptTargets[4] = {
    R6GameAddresses::HudPlanningPromptTargetsCase1, R6GameAddresses::HudPlanningPromptTargetsCase2, R6GameAddresses::HudPlanningPromptTargetsCase3, R6GameAddresses::HudPlanningPromptTargetsCase4
};

// R6Game.dll data @ 10018c24 : waypoint distance in integer meters
const unsigned short HudWaypointDistanceFormat[4] = {0x0025, 0x0064, 0x006d, 0x0000};

// R6Game.dll data @ 10018db0 : localized third-team name key
const unsigned short HudTeamThreeKey[] = {0x0054, 0x0045, 0x0041, 0x004d, 0x0033, 0x0000};

// R6Game.dll data @ 10018dbc : localized second-team name key
const unsigned short HudTeamTwoKey[] = {0x0054, 0x0045, 0x0041, 0x004d, 0x0032, 0x0000};

// R6Game.dll data @ 10018dc8 : team-name localization section
const unsigned short HudTeamNameSection[] = {0x0047, 0x0065, 0x0061, 0x0072, 0x0052, 0x006f, 0x006f, 0x006d, 0x0000};

// R6Game.dll data @ 10018ddc : localized first-team name key
const unsigned short HudTeamOneKey[] = {0x0054, 0x0045, 0x0041, 0x004d, 0x0031, 0x0000};

// R6Game.dll data @ 10018cd8 : planning/prompt UTF-16 literal ""
const unsigned short HudEmptyPlanningText[1] = {
    0x0000
};

// R6Game.dll data @ 10018cdc : planning/prompt UTF-16 literal "Planning_Wait"
const unsigned short HudPlanningWaitKey[14] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0057, 0x0061, 0x0069, 0x0074, 0x0000
};

// R6Game.dll data @ 10018cf8 : planning/prompt UTF-16 literal "Planning_Breach"
const unsigned short HudPlanningBreachKey[16] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0042, 0x0072, 0x0065, 0x0061, 0x0063,
    0x0068, 0x0000
};

// R6Game.dll data @ 10018d18 : planning/prompt UTF-16 literal "Planning_Snipe"
const unsigned short HudPlanningSnipeKey[15] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0053, 0x006e, 0x0069, 0x0070, 0x0065,
    0x0000
};

// R6Game.dll data @ 10018d38 : planning/prompt UTF-16 literal "Planning_Smoke"
const unsigned short HudPlanningSmokeKey[15] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0053, 0x006d, 0x006f, 0x006b, 0x0065,
    0x0000
};

// R6Game.dll data @ 10018d58 : planning/prompt UTF-16 literal "Planning_Gas"
const unsigned short HudPlanningGasKey[13] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0047, 0x0061, 0x0073, 0x0000
};

// R6Game.dll data @ 10018d74 : planning/prompt UTF-16 literal "Planning_Flash"
const unsigned short HudPlanningFlashKey[15] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0046, 0x006c, 0x0061, 0x0073, 0x0068,
    0x0000
};

// R6Game.dll data @ 10018d94 : planning/prompt UTF-16 literal "Planning_Frag"
const unsigned short HudPlanningFragKey[14] = {
    0x0050, 0x006c, 0x0061, 0x006e, 0x006e, 0x0069, 0x006e, 0x0067, 0x005f, 0x0046, 0x0072, 0x0061, 0x0067, 0x0000
};

// R6Game.dll data @ 10018c48 : planning/prompt UTF-16 literal "GoCodeZulu"
const unsigned short HudGoCodeZuluAction[11] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005a, 0x0075, 0x006c, 0x0075, 0x0000
};

// R6Game.dll data @ 10018c60 : planning/prompt UTF-16 literal "GoCodeCharlie"
const unsigned short HudGoCodeCharlieAction[14] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x0043, 0x0068, 0x0061, 0x0072, 0x006c, 0x0069, 0x0065, 0x0000
};

// R6Game.dll data @ 10018c7c : planning/prompt UTF-16 literal "GoCodeBravo"
const unsigned short HudGoCodeBravoAction[12] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x0042, 0x0072, 0x0061, 0x0076, 0x006f, 0x0000
};

// R6Game.dll data @ 10018cc0 : planning/prompt UTF-16 literal "GoCodeAlpha"
const unsigned short HudGoCodeAlphaAction[12] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x0041, 0x006c, 0x0070, 0x0068, 0x0061, 0x0000
};

// R6Game.dll data @ 10018c94 : planning/prompt UTF-16 literal "PressKeyToGiveCoCode"
const unsigned short HudPressGoCodeKey[21] = {
    0x0050, 0x0072, 0x0065, 0x0073, 0x0073, 0x004b, 0x0065, 0x0079, 0x0054, 0x006f, 0x0047, 0x0069, 0x0076, 0x0065,
    0x0043, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x0000
};

// R6Game.dll data @ 10018790 : native UTF-16 localization literal "---"
const unsigned short OtherTeamState21Text[4] = {
    0x002d, 0x002d, 0x002d, 0x0000
};

// R6Game.dll data @ 10018798 : native UTF-16 localization literal "Action_Breach"
const unsigned short OtherTeamActionBreach[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0042, 0x0072, 0x0065, 0x0061, 0x0063, 0x0068, 0x0000
};

// R6Game.dll data @ 100187b4 : native UTF-16 localization literal "Action_Orders"
const unsigned short OtherTeamActionOrders[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004f, 0x0072, 0x0064, 0x0065, 0x0072, 0x0073, 0x0000
};

// R6Game.dll data @ 100187d0 : native UTF-16 localization literal "Action_Ladder"
const unsigned short OtherTeamActionLadder[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004c, 0x0061, 0x0064, 0x0064, 0x0065, 0x0072, 0x0000
};

// R6Game.dll data @ 100187ec : native UTF-16 localization literal "Action_Arrest"
const unsigned short OtherTeamActionArrest[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0041, 0x0072, 0x0072, 0x0065, 0x0073, 0x0074, 0x0000
};

// R6Game.dll data @ 10018808 : native UTF-16 localization literal "Action_Device"
const unsigned short OtherTeamActionDevice[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0044, 0x0065, 0x0076, 0x0069, 0x0063, 0x0065, 0x0000
};

// R6Game.dll data @ 10018824 : native UTF-16 localization literal "Action_Bomb"
const unsigned short OtherTeamActionBomb[12] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0042, 0x006f, 0x006d, 0x0062, 0x0000
};

// R6Game.dll data @ 1001883c : native UTF-16 localization literal "Action_Grenade"
const unsigned short OtherTeamActionGrenade[15] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0047, 0x0072, 0x0065, 0x006e, 0x0061, 0x0064, 0x0065,
    0x0000
};

// R6Game.dll data @ 1001885c : native UTF-16 localization literal "Action_Clear"
const unsigned short OtherTeamActionClear[13] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0043, 0x006c, 0x0065, 0x0061, 0x0072, 0x0000
};

// R6Game.dll data @ 10018878 : native UTF-16 localization literal "Action_Close"
const unsigned short OtherTeamActionClose[13] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0043, 0x006c, 0x006f, 0x0073, 0x0065, 0x0000
};

// R6Game.dll data @ 10018894 : native UTF-16 localization literal "Action_Open"
const unsigned short OtherTeamActionOpen[12] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004f, 0x0070, 0x0065, 0x006e, 0x0000
};

// R6Game.dll data @ 100188ac : native UTF-16 localization literal "Action_CloseDoor"
const unsigned short OtherTeamActionCloseDoor[17] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0043, 0x006c, 0x006f, 0x0073, 0x0065, 0x0044, 0x006f,
    0x006f, 0x0072, 0x0000
};

// R6Game.dll data @ 100188d0 : native UTF-16 localization literal "Action_OpenDoor"
const unsigned short OtherTeamActionOpenDoor[16] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004f, 0x0070, 0x0065, 0x006e, 0x0044, 0x006f, 0x006f,
    0x0072, 0x0000
};

// R6Game.dll data @ 100188f0 : native UTF-16 localization literal "Action_LockPick"
const unsigned short OtherTeamActionLockPick[16] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004c, 0x006f, 0x0063, 0x006b, 0x0050, 0x0069, 0x0063,
    0x006b, 0x0000
};

// R6Game.dll data @ 10018910 : native UTF-16 localization literal "Action_Regroup"
const unsigned short OtherTeamActionRegroup[15] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0052, 0x0065, 0x0067, 0x0072, 0x006f, 0x0075, 0x0070,
    0x0000
};

// R6Game.dll data @ 10018930 : native UTF-16 localization literal "Action_Follow"
const unsigned short OtherTeamActionFollow[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0046, 0x006f, 0x006c, 0x006c, 0x006f, 0x0077, 0x0000
};

// R6Game.dll data @ 1001894c : native UTF-16 localization literal "GoCode_Alpha"
const unsigned short OtherTeamGoCodeAlpha[13] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0041, 0x006c, 0x0070, 0x0068, 0x0061, 0x0000
};

// R6Game.dll data @ 10018968 : native UTF-16 localization literal "Snipe_Hold"
const unsigned short OtherTeamSnipeHold[11] = {
    0x0053, 0x006e, 0x0069, 0x0070, 0x0065, 0x005f, 0x0048, 0x006f, 0x006c, 0x0064, 0x0000
};

// R6Game.dll data @ 10018980 : native UTF-16 localization literal "GoCode_Z"
const unsigned short OtherTeamGoCodeZ[9] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x005a, 0x0000
};

// R6Game.dll data @ 10018994 : native UTF-16 localization literal "GoCode_C"
const unsigned short OtherTeamGoCodeC[9] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0043, 0x0000
};

// R6Game.dll data @ 100189a8 : native UTF-16 localization literal "GoCode_B"
const unsigned short OtherTeamGoCodeB[9] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0042, 0x0000
};

// R6Game.dll data @ 100189bc : native UTF-16 localization literal "GoCode_A"
const unsigned short OtherTeamGoCodeA[9] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0041, 0x0000
};

// R6Game.dll data @ 100189d0 : native UTF-16 localization literal "Action_Sniping"
const unsigned short OtherTeamActionSniping[15] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0053, 0x006e, 0x0069, 0x0070, 0x0069, 0x006e, 0x0067,
    0x0000
};

// R6Game.dll data @ 100189f0 : native UTF-16 localization literal "Action_Engage"
const unsigned short OtherTeamActionEngage[14] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0045, 0x006e, 0x0067, 0x0061, 0x0067, 0x0065, 0x0000
};

// R6Game.dll data @ 10018a0c : native UTF-16 localization literal "Action_Move"
const unsigned short OtherTeamActionMove[12] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x004d, 0x006f, 0x0076, 0x0065, 0x0000
};

// R6Game.dll data @ 10018a24 : native UTF-16 localization literal "Action_Hold"
const unsigned short OtherTeamActionHold[12] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0048, 0x006f, 0x006c, 0x0064, 0x0000
};

// R6Game.dll data @ 10018a3c : native UTF-16 localization literal "GoCode_Zulu"
const unsigned short OtherTeamGoCodeZulu[12] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x005a, 0x0075, 0x006c, 0x0075, 0x0000
};

// R6Game.dll data @ 10018a54 : native UTF-16 localization literal "GoCode_Charlie"
const unsigned short OtherTeamGoCodeCharlie[15] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0043, 0x0068, 0x0061, 0x0072, 0x006c, 0x0069, 0x0065,
    0x0000
};

// R6Game.dll data @ 10018a74 : native UTF-16 localization literal "GoCode_Bravo"
const unsigned short OtherTeamGoCodeBravo[13] = {
    0x0047, 0x006f, 0x0043, 0x006f, 0x0064, 0x0065, 0x005f, 0x0042, 0x0072, 0x0061, 0x0076, 0x006f, 0x0000
};

// R6Game.dll data @ 10018a90 : native UTF-16 localization literal " - "
const unsigned short OtherTeamActionSeparator[4] = {
    0x0020, 0x002d, 0x0020, 0x0000
};

// R6Game.dll data @ 10018a98 : native UTF-16 localization literal "Order"
const unsigned short OtherTeamLocalizeSection[6] = {
    0x004f, 0x0072, 0x0064, 0x0065, 0x0072, 0x0000
};

// R6Game.dll data @ 10018aa4 : native UTF-16 localization literal "Action_Wait"
const unsigned short OtherTeamActionWait[12] = {
    0x0041, 0x0063, 0x0074, 0x0069, 0x006f, 0x006e, 0x005f, 0x0057, 0x0061, 0x0069, 0x0074, 0x0000
};

// R6Game.dll data @ 10018abc : native UTF-16 localization literal "R6Menu"
const unsigned short OtherTeamLocalizePackage[7] = {
    0x0052, 0x0036, 0x004d, 0x0065, 0x006e, 0x0075, 0x0000
};

// R6Game.dll data @ 1000cc00 : compiler-generated other-team case targets
const unsigned int OtherTeamStateCaseTargets[21] = {
    R6GameAddresses::OtherTeamStateCaseTargetsCase1, R6GameAddresses::OtherTeamStateCaseTargetsCase2, R6GameAddresses::OtherTeamStateCaseTargetsCase3, R6GameAddresses::OtherTeamStateCaseTargetsCase4, R6GameAddresses::OtherTeamStateCaseTargetsCase5, R6GameAddresses::OtherTeamStateCaseTargetsCase6, R6GameAddresses::OtherTeamStateCaseTargetsCase7, R6GameAddresses::OtherTeamStateCaseTargetsCase8, R6GameAddresses::OtherTeamStateCaseTargetsCase9,
    R6GameAddresses::OtherTeamStateCaseTargetsCase10, R6GameAddresses::OtherTeamStateCaseTargetsCase11, R6GameAddresses::OtherTeamStateCaseTargetsCase12, R6GameAddresses::OtherTeamStateCaseTargetsCase13, R6GameAddresses::OtherTeamStateCaseTargetsCase14, R6GameAddresses::OtherTeamStateCaseTargetsCase15, R6GameAddresses::OtherTeamStateCaseTargetsCase16, R6GameAddresses::OtherTeamStateCaseTargetsCase17, R6GameAddresses::OtherTeamStateCaseTargetsCase18,
    R6GameAddresses::OtherTeamStateCaseTargetsCase19, R6GameAddresses::OtherTeamStateCaseTargetsCase20, R6GameAddresses::OtherTeamStateCaseTargetsCase21
};

// R6Game.dll data @ 1000cc54 : compiler-generated other-team case targets
const unsigned int OtherTeamWaitGoCodeTargets[4] = {
    R6GameAddresses::OtherTeamWaitGoCodeTargetsCase1, R6GameAddresses::OtherTeamWaitGoCodeTargetsCase2, R6GameAddresses::OtherTeamWaitGoCodeTargetsCase3, R6GameAddresses::OtherTeamWaitGoCodeTargetsCase4
};

// R6Game.dll data @ 1000cc64 : compiler-generated other-team case targets
const unsigned int OtherTeamHoldGoCodeTargets[4] = {
    R6GameAddresses::OtherTeamHoldGoCodeTargetsCase1, R6GameAddresses::OtherTeamHoldGoCodeTargetsCase2, R6GameAddresses::OtherTeamHoldGoCodeTargetsCase3, R6GameAddresses::OtherTeamHoldGoCodeTargetsCase4
};

// R6Game.dll data @ 1000cc74 : compiler-generated other-team case targets
const unsigned int OtherTeamSnipingGoCodeTargets[4] = {
    R6GameAddresses::OtherTeamWaitGoCodeTargetsCase1, R6GameAddresses::OtherTeamSnipingGoCodeTargetsCase2, R6GameAddresses::OtherTeamSnipingGoCodeTargetsCase3, R6GameAddresses::OtherTeamWaitGoCodeTargetsCase4
};

// R6Game.dll data @ 10018acc : pooled float used by other-team panel geometry
const float HudOtherPanelInnerRight = 796.0f;

// R6Game.dll data @ 10018ad0 : pooled float used by other-team panel geometry
const float HudOtherPanelOuterLeft = 644.0f;

// R6Game.dll data @ 10018ad4 : pooled float used by other-team panel geometry
const float HudOtherPanelLeft = 650.0f;

// R6Game.dll data @ 10018ad8 : pooled float used by other-team panel geometry
const float HudOtherPanelRight = 800.0f;

// R6Game.dll data @ 10018750 : pooled float used by character-panel border geometry
const float HudCharacterPanelWidth = 175.0f;

// R6Game.dll data @ 1001874c : pooled float used by character-panel border geometry
const float HudCharacterPanelBorderInset = 1.0f;

// R6Game.dll data @ 10018700 : pooled float used by single-character name/health geometry
const float HudSingleNameOffsetX = 60.0f;

// R6Game.dll data @ 100186fc : pooled float used by single-character name/health geometry
const float HudSingleHealthBottomOffset = 17.0f;

// R6Game.dll data @ 100186f8 : pooled float used by single-character name/health geometry
const float HudSingleHealthRightOffset = 57.0f;

// R6Game.dll data @ 100186f4 : pooled float used by single-character name/health geometry
const float HudSingleHealthTopOffset = 9.0f;

// R6Game.dll data @ 100186f0 : pooled float used by single-character name/health geometry
const float HudSingleHealthLeftOffset = 49.0f;

// R6Game.dll data @ 10018714 : pooled float used by single-character panel geometry
const float HudSinglePanelHeight = 41.0f;

// R6Game.dll data @ 10018710 : pooled float used by single-character panel geometry
const float HudSinglePanelOuterOffset = 6.0f;

// R6Game.dll data @ 1001870c : pooled float used by single-character panel geometry
const float HudSinglePanelInnerOffset = 4.0f;

// R6Game.dll data @ 10018708 : pooled float used by single-character panel geometry
const float HudSingleStanceBottomOffset = 35.0f;

// R6Game.dll data @ 10018704 : pooled float used by single-character panel geometry
const float HudSingleStanceRightOffset = 42.0f;

// R6Game.dll data @ 1000af88 : compiler-generated box switch code-pointer table
const unsigned int HudStepBoxCaseTargets[11] = {
    R6GameAddresses::HudStepBoxCaseTargetsCase1, R6GameAddresses::HudStepBoxCaseTargetsCase2, R6GameAddresses::HudStepBoxCaseTargetsCase3, R6GameAddresses::HudStepBoxCaseTargetsCase4, R6GameAddresses::HudStepBoxCaseTargetsCase5, R6GameAddresses::HudStepBoxCaseTargetsCase6, R6GameAddresses::HudStepBoxCaseTargetsCase7, R6GameAddresses::HudStepBoxCaseTargetsCase8,
    R6GameAddresses::HudStepBoxCaseTargetsCase9, R6GameAddresses::HudStepBoxCaseTargetsCase10, R6GameAddresses::HudStepBoxCaseTargetsCase11
};

// R6Game.dll data @ 1000afb4 : compiler-generated box-to-case byte map
const unsigned char HudStepBoxCaseIndices[28] = {
    0x00, 0x01, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x0a, 0x0a, 0x0a, 0x0a
};

// R6Game.dll data @ 1000afd0 : compiler-generated steps4..8 code-pointer table
const unsigned int HudStepEarlyStepTargets[5] = {R6GameAddresses::HudStepEarlyStepTargetsCase1, R6GameAddresses::HudStepEarlyStepTargetsCase2, R6GameAddresses::HudStepEarlyStepTargetsCase3, R6GameAddresses::HudStepEarlyStepTargetsCase4, R6GameAddresses::HudStepEarlyStepTargetsCase5};

// R6Game.dll data @ 1000afe4 : compiler-generated steps11..14 code-pointer table
const unsigned int HudStepLateStepTargets[4] = {R6GameAddresses::HudStepLateStepTargetsCase1, R6GameAddresses::HudStepLateStepTargetsCase2, R6GameAddresses::HudStepLateStepTargetsCase3, R6GameAddresses::HudStepLateStepTargetsCase3};

// R6Game.dll data @ 10018620 : HUD clock bias
const double HudClockBias = 16777216.0;

// R6Game.dll data @ 10018628 : unsigned clock DWORD conversion range
const double HudClockUnsignedWordRange = 4294967296.0;

// R6Game.dll data @ 10018658 : HudStep flash deadline increment
const float HudStepFlashDuration = 4.5f;

// R6Game.dll data @ 10024180 : writable radar scale divisor
float HudRadarWorldUnitsPerPixel = 50.0f;

class UFinalBlend;

// R6Game.dll data @ 10028dac : HUD material cache pointer
UFinalBlend* HudWaypointArrowFinalBlend = nullptr;

// R6Game.dll data @ 10028db0 : HUD material cache pointer
UFinalBlend* HudWaypointFinalBlend = nullptr;

// R6Game.dll data @ 10028db4 : HUD material cache pointer
UFinalBlend* HudRadarFinalBlend = nullptr;

// R6Game.dll data @ 10024178 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6HUD::execDrawNativeHUD.
unsigned int intAR6HUDexecDrawNativeHUD = R6GameAddresses::AR6HUD_execDrawNativeHUD;

// R6Game.dll data @ 1002417c : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6HUD::execHudStep.
unsigned int intAR6HUDexecHudStep = R6GameAddresses::AR6HUD_execHudStep;

// R6Game.dll data @ 10028db8 : auto-class pointer
UClass* autoclassAR6HUD = nullptr;

// R6Game.dll data @ 10028dbc : native registration result byte
unsigned char AR6HUDexecHudStepRegistrationResult = 0;

// R6Game.dll data @ 10028dbd : native registration result byte
unsigned char AR6HUDexecDrawNativeHUDRegistrationResult = 0;

// R6Game.dll data @ 10028dc0 : class metadata storage
// Backing storage for AR6HUD::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6HUDClassMetadataStorage[0x508] = {};

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001a9d0 : native C++ unwind-state transitions
const unsigned int AR6HUD_DestructUnwindMap[18] = {
    0xffffffff, R6GameAddresses::AR6HUD_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6HUD_DestructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6HUD_DestructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6HUD_DestructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6HUD_DestructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6HUD_DestructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::AR6HUD_DestructUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::AR6HUD_DestructUnwind8, // State 8: previous state, cleanup action.
};

// R6Game.dll data @ 1001aa18 : native C++ exception function descriptor
const unsigned int AR6HUD_DestructExceptionInfo[7] = {
    0x19930520, 0x9, R6GameAddresses::AR6HUD_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001aa34 : native C++ unwind-state transitions
const unsigned int AR6HUD_ConstructUnwindMap[16] = {
    0xffffffff, R6GameAddresses::AR6HUD_ConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_ConstructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6HUD_ConstructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6HUD_ConstructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6HUD_ConstructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6HUD_ConstructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6HUD_ConstructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::AR6HUD_ConstructUnwind7, // State 7: previous state, cleanup action.
};

// R6Game.dll data @ 1001aa74 : native C++ exception function descriptor
const unsigned int AR6HUD_ConstructExceptionInfo[7] = {
    0x19930520, 0x8, R6GameAddresses::AR6HUD_ConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001aa90 : native C++ unwind-state transitions
const unsigned int AR6HUD_CopyConstructUnwindMap[12] = {
    0xffffffff, R6GameAddresses::AR6HUD_CopyConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_CopyConstructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6HUD_CopyConstructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6HUD_CopyConstructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6HUD_CopyConstructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6HUD_CopyConstructUnwind5, // State 5: previous state, cleanup action.
};

// R6Game.dll data @ 1001aac0 : native C++ exception function descriptor
const unsigned int AR6HUD_CopyConstructExceptionInfo[7] = {
    0x19930520, 0x6, R6GameAddresses::AR6HUD_CopyConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b69c : native C++ unwind-state transitions
const unsigned int AR6HUD_execHudStepUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b6ac : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execHudStepCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6HUD_execHudStepCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execHudStepCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b6cc : native C++ try-block ranges
const unsigned int AR6HUD_execHudStepTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6HUD_execHudStepCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b6e0 : native C++ exception function descriptor
const unsigned int AR6HUD_execHudStepExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6HUD_execHudStepUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_execHudStepTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b6fc : native C++ unwind-state transitions
const unsigned int AR6HUD_DestroyUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b70c : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DestroyCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6HUD_DestroyCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DestroyCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b72c : native C++ try-block ranges
const unsigned int AR6HUD_DestroyTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6HUD_DestroyCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b740 : native C++ exception function descriptor
const unsigned int AR6HUD_DestroyExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6HUD_DestroyUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DestroyTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b7a0 : native C++ unwind-state transitions
const unsigned int AR6HUD_SpawnedUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b7b0 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_SpawnedCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::AR6HUD_SpawnedCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_SpawnedCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b7d0 : native C++ try-block ranges
const unsigned int AR6HUD_SpawnedTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6HUD_SpawnedCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b7e4 : native C++ exception function descriptor
const unsigned int AR6HUD_SpawnedExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6HUD_SpawnedUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_SpawnedTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b800 : native C++ unwind-state transitions
const unsigned int AR6HUD_DrawSingleCharacterInfoUnwindMap[6] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoUnwind1, // State 1: previous state, cleanup action.
    0xffffffff, 0x0, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001b818 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DrawSingleCharacterInfoCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffdc, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b838 : native C++ try-block ranges
const unsigned int AR6HUD_DrawSingleCharacterInfoTryMap[5] = {
    0x0, 0x1, 0x2, 0x2, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b84c : native C++ exception function descriptor
const unsigned int AR6HUD_DrawSingleCharacterInfoExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DrawSingleCharacterInfoTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b868 : native C++ unwind-state transitions
const unsigned int AR6HUD_DrawCharacterInfoUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b878 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DrawCharacterInfoCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6HUD_DrawCharacterInfoCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DrawCharacterInfoCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b898 : native C++ try-block ranges
const unsigned int AR6HUD_DrawCharacterInfoTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6HUD_DrawCharacterInfoCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b8ac : native C++ exception function descriptor
const unsigned int AR6HUD_DrawCharacterInfoExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6HUD_DrawCharacterInfoUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DrawCharacterInfoTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b8c8 : native C++ unwind-state transitions
const unsigned int AR6HUD_DisplayOtherTeamInfoUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001b8d8 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DisplayOtherTeamInfoCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffd8, R6GameAddresses::AR6HUD_DisplayOtherTeamInfoCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DisplayOtherTeamInfoCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001b8f8 : native C++ try-block ranges
const unsigned int AR6HUD_DisplayOtherTeamInfoTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6HUD_DisplayOtherTeamInfoCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001b90c : native C++ exception function descriptor
const unsigned int AR6HUD_DisplayOtherTeamInfoExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6HUD_DisplayOtherTeamInfoUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DisplayOtherTeamInfoTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001b988 : native C++ unwind-state transitions
const unsigned int AR6HUD_execDrawNativeHUDUnwindMap[58] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind1, // State 1: previous state, cleanup action.
    0x1, 0x0, // State 2: previous state, cleanup action.
    0x1, 0x0, // State 3: previous state, cleanup action.
    0x1, 0x0, // State 4: previous state, cleanup action.
    0x4, 0x0, // State 5: previous state, cleanup action.
    0x4, 0x0, // State 6: previous state, cleanup action.
    0x4, 0x0, // State 7: previous state, cleanup action.
    0x7, 0x0, // State 8: previous state, cleanup action.
    0x7, 0x0, // State 9: previous state, cleanup action.
    0x7, 0x0, // State 10: previous state, cleanup action.
    0x7, 0x0, // State 11: previous state, cleanup action.
    0x4, 0x0, // State 12: previous state, cleanup action.
    0x1, 0x0, // State 13: previous state, cleanup action.
    0x1, 0x0, // State 14: previous state, cleanup action.
    0xe, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind15, // State 15: previous state, cleanup action.
    0xf, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind16, // State 16: previous state, cleanup action.
    0x10, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind17, // State 17: previous state, cleanup action.
    0x1, 0x0, // State 18: previous state, cleanup action.
    0x1, 0x0, // State 19: previous state, cleanup action.
    0x13, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind20, // State 20: previous state, cleanup action.
    0x13, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind21, // State 21: previous state, cleanup action.
    0x13, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind22, // State 22: previous state, cleanup action.
    0x13, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind23, // State 23: previous state, cleanup action.
    0x13, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind24, // State 24: previous state, cleanup action.
    0x18, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind25, // State 25: previous state, cleanup action.
    0x18, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwind26, // State 26: previous state, cleanup action.
    0x1, 0x0, // State 27: previous state, cleanup action.
    0xffffffff, 0x0, // State 28: previous state, cleanup action.
};

// R6Game.dll data @ 1001ba70 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers1[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffc4, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer1, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext1, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001ba90 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers2[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer2, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext2, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bab0 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers3[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff1c, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer3, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext3, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bad0 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers4[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff1c, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer4, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext4, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001baf0 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers5[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff44, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer5, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext5, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bb10 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers6[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffc4, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer6, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext6, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bb30 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers7[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff44, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer7, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext7, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bb50 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers8[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff44, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer8, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext8, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bb70 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_execDrawNativeHUDCatchHandlers9[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff18, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchPointer9, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchContext9, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bb90 : native C++ try-block ranges
const unsigned int AR6HUD_execDrawNativeHUDTryMap[45] = {
    0x2, 0x2, 0x3, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers1, // Try 0: low/high/catch-high state, count, handler array.
    0x5, 0x5, 0x6, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers2, // Try 1: low/high/catch-high state, count, handler array.
    0x8, 0x8, 0x9, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers3, // Try 2: low/high/catch-high state, count, handler array.
    0xa, 0xa, 0xb, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers4, // Try 3: low/high/catch-high state, count, handler array.
    0x7, 0xb, 0xc, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers5, // Try 4: low/high/catch-high state, count, handler array.
    0x4, 0xc, 0xd, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers6, // Try 5: low/high/catch-high state, count, handler array.
    0xe, 0x11, 0x12, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers7, // Try 6: low/high/catch-high state, count, handler array.
    0x13, 0x1a, 0x1b, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers8, // Try 7: low/high/catch-high state, count, handler array.
    0x0, 0x1b, 0x1c, 0x2, R6GameAddresses::AR6HUD_execDrawNativeHUDCatchHandlers9, // Try 8: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bc44 : native C++ exception function descriptor
const unsigned int AR6HUD_execDrawNativeHUDExceptionInfo[7] = {
    0x19930520, 0x1d, R6GameAddresses::AR6HUD_execDrawNativeHUDUnwindMap, // Magic, state count, unwind map.
    0x9, R6GameAddresses::AR6HUD_execDrawNativeHUDTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bc60 : native C++ unwind-state transitions
const unsigned int AR6HUD_DrawRadarUnwindMap[6] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DrawRadarUnwind1, // State 1: previous state, cleanup action.
    0xffffffff, 0x0, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 1001bc78 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DrawRadarCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffff7c, R6GameAddresses::AR6HUD_DrawRadarCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DrawRadarCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bc98 : native C++ try-block ranges
const unsigned int AR6HUD_DrawRadarTryMap[5] = {
    0x0, 0x1, 0x2, 0x2, R6GameAddresses::AR6HUD_DrawRadarCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bcac : native C++ exception function descriptor
const unsigned int AR6HUD_DrawRadarExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::AR6HUD_DrawRadarUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DrawRadarTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001bcc8 : native C++ unwind-state transitions
const unsigned int AR6HUD_DrawInGameMapUnwindMap[16] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DrawInGameMapUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6HUD_DrawInGameMapUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6HUD_DrawInGameMapUnwind3, // State 3: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DrawInGameMapUnwind4, // State 4: previous state, cleanup action.
    0x0, R6GameAddresses::AR6HUD_DrawInGameMapUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6HUD_DrawInGameMapUnwind6, // State 6: previous state, cleanup action.
    0xffffffff, 0x0, // State 7: previous state, cleanup action.
};

// R6Game.dll data @ 1001bd08 : native typed-pointer and catch-all handler pair
const unsigned int AR6HUD_DrawInGameMapCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xfffffe78, R6GameAddresses::AR6HUD_DrawInGameMapCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6HUD_DrawInGameMapCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001bd28 : native C++ try-block ranges
const unsigned int AR6HUD_DrawInGameMapTryMap[5] = {
    0x0, 0x6, 0x7, 0x2, R6GameAddresses::AR6HUD_DrawInGameMapCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001bd3c : native C++ exception function descriptor
const unsigned int AR6HUD_DrawInGameMapExceptionInfo[7] = {
    0x19930520, 0x8, R6GameAddresses::AR6HUD_DrawInGameMapUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6HUD_DrawInGameMapTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017ab0 : AR6HUD virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6HUD_vftable[100] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6HUD_VectorDeletingDestructor, // +0xc: AR6HUD::VectorDeletingDestructor
    R6GameAddresses::ForwardImported_AActor_ProcessEvent, // +0x10: AActor::ProcessEvent
    R6GameAddresses::ForwardImported_UObject_ProcessDelegate, // +0x14: UObject::ProcessDelegate
    R6GameAddresses::ForwardImported_AActor_ProcessState, // +0x18: AActor::ProcessState
    R6GameAddresses::ForwardImported_AActor_ProcessRemoteFunction, // +0x1c: AActor::ProcessRemoteFunction
    R6GameAddresses::ForwardImported_UObject_Modify, // +0x20: UObject::Modify
    R6GameAddresses::ForwardImported_AActor_PostLoad, // +0x24: AActor::PostLoad
    R6GameAddresses::AR6HUD_Destroy, // +0x28: Destroy
    R6GameAddresses::AR6HUD_Serialize, // +0x2c: Serialize
    R6GameAddresses::ForwardImported_AActor_IsPendingKill, // +0x30: AActor::IsPendingKill
    R6GameAddresses::ForwardImported_UObject_GotoState, // +0x34: UObject::GotoState
    R6GameAddresses::ForwardImported_UObject_GotoLabel, // +0x38: UObject::GotoLabel
    R6GameAddresses::ForwardImported_AActor_InitExecution, // +0x3c: AActor::InitExecution
    R6GameAddresses::ForwardImported_UObject_ShutdownAfterError, // +0x40: UObject::ShutdownAfterError
    R6GameAddresses::ForwardImported_AActor_PostEditChange, // +0x44: AActor::PostEditChange
    R6GameAddresses::ForwardImported_UObject_CallFunction, // +0x48: UObject::CallFunction
    R6GameAddresses::ForwardImported_UObject_ScriptConsoleExec, // +0x4c: UObject::ScriptConsoleExec
    R6GameAddresses::ForwardImported_UObject_Register, // +0x50: UObject::Register
    R6GameAddresses::ForwardImported_UObject_LanguageChange, // +0x54: UObject::LanguageChange
    R6GameAddresses::ForwardImported_AActor_IsPendingDelete, // +0x58: AActor::IsPendingDelete
    R6GameAddresses::ForwardImported_UObject_GetPropertiesSize, // +0x5c: UObject::GetPropertiesSize
    R6GameAddresses::ForwardImported_AActor_NetDirty, // +0x60: AActor::NetDirty
    R6GameAddresses::ForwardImported_AActor_GetOptimizedRepList, // +0x64: AActor::GetOptimizedRepList
    R6GameAddresses::ForwardImported_AActor_GetPlayerPawn, // +0x68: AActor::GetPlayerPawn
    R6GameAddresses::ForwardImported_AActor_GetPawnOrColBoxOwner, // +0x6c: AActor::GetPawnOrColBoxOwner
    R6GameAddresses::ForwardImported_AActor_IsBlockedBy, // +0x70: AActor::IsBlockedBy
    R6GameAddresses::ForwardImported_AActor_GetNetPriority, // +0x74: AActor::GetNetPriority
    R6GameAddresses::ForwardImported_AActor_WorldLightRadius, // +0x78: AActor::WorldLightRadius
    R6GameAddresses::ForwardImported_AActor_Tick, // +0x7c: AActor::Tick
    R6GameAddresses::ForwardImported_AActor_PostEditMove, // +0x80: AActor::PostEditMove
    R6GameAddresses::ForwardImported_AActor_PostEditLoad, // +0x84: AActor::PostEditLoad
    R6GameAddresses::ForwardImported_AActor_PreRaytrace, // +0x88: AActor::PreRaytrace
    R6GameAddresses::ForwardImported_AActor_PostRaytrace, // +0x8c: AActor::PostRaytrace
    R6GameAddresses::AR6HUD_Spawned, // +0x90: Spawned
    R6GameAddresses::ForwardImported_AActor_PreNetReceive, // +0x94: AActor::PreNetReceive
    R6GameAddresses::ForwardImported_AActor_PostNetReceive, // +0x98: AActor::PostNetReceive
    R6GameAddresses::ForwardImported_AActor_PostNetReceiveLocation, // +0x9c: AActor::PostNetReceiveLocation
    R6GameAddresses::ForwardImported_AActor_GetSkin, // +0xa0: AActor::GetSkin
    R6GameAddresses::ForwardImported_AActor_ToLocal, // +0xa4: AActor::ToLocal
    R6GameAddresses::ForwardImported_AActor_ToWorld, // +0xa8: AActor::ToWorld
    R6GameAddresses::ForwardImported_AActor_LocalToWorld, // +0xac: AActor::LocalToWorld
    R6GameAddresses::ForwardImported_AActor_WorldToLocal, // +0xb0: AActor::WorldToLocal
    R6GameAddresses::ForwardImported_AActor_UpdateColBox, // +0xb4: AActor::UpdateColBox
    R6GameAddresses::ForwardImported_AActor_PostScriptDestroyed, // +0xb8: AActor::PostScriptDestroyed
    R6GameAddresses::ForwardImported_AActor_ShouldTrace, // +0xbc: AActor::ShouldTrace
    R6GameAddresses::ForwardImported_AActor_GetPrimitive, // +0xc0: AActor::GetPrimitive
    R6GameAddresses::ForwardImported_AActor_BeginTouch, // +0xc4: AActor::BeginTouch
    R6GameAddresses::ForwardImported_AActor_IsMovingBrush, // +0xc8: AActor::IsMovingBrush
    R6GameAddresses::ForwardImported_AActor_NotifyBump, // +0xcc: AActor::NotifyBump
    R6GameAddresses::ForwardImported_AActor_SetBase, // +0xd0: AActor::SetBase
    R6GameAddresses::ForwardImported_AActor_GetViewRotation, // +0xd4: AActor::GetViewRotation
    R6GameAddresses::ForwardImported_AActor_NotifyAnimEnd, // +0xd8: AActor::NotifyAnimEnd
    R6GameAddresses::ForwardImported_AActor_UpdateAnimation, // +0xdc: AActor::UpdateAnimation
    R6GameAddresses::ForwardImported_AActor_StartAnimPoll, // +0xe0: AActor::StartAnimPoll
    R6GameAddresses::ForwardImported_AActor_CheckAnimFinished, // +0xe4: AActor::CheckAnimFinished
    R6GameAddresses::ForwardImported_AActor_UpdateTimers, // +0xe8: AActor::UpdateTimers
    R6GameAddresses::ForwardImported_AActor_CheckOwnerUpdated, // +0xec: AActor::CheckOwnerUpdated
    R6GameAddresses::ForwardImported_AActor_TickAuthoritative, // +0xf0: AActor::TickAuthoritative
    R6GameAddresses::ForwardImported_AActor_TickSimulated, // +0xf4: AActor::TickSimulated
    R6GameAddresses::ForwardImported_AActor_TickSpecial, // +0xf8: AActor::TickSpecial
    R6GameAddresses::ForwardImported_AActor_PlayerControlled, // +0xfc: AActor::PlayerControlled
    R6GameAddresses::ForwardImported_AActor_IsNetRelevantFor, // +0x100: AActor::IsNetRelevantFor
    R6GameAddresses::ForwardImported_AActor_RenderEditorInfo, // +0x104: AActor::RenderEditorInfo
    R6GameAddresses::ForwardImported_AActor_RenderEditorSelected, // +0x108: AActor::RenderEditorSelected
    R6GameAddresses::ForwardImported_AActor_SetZone, // +0x10c: AActor::SetZone
    R6GameAddresses::ForwardImported_AActor_SetVolumesFromList, // +0x110: AActor::SetVolumes
    R6GameAddresses::ForwardImported_AActor_SetVolumes, // +0x114: AActor::SetVolumes
    R6GameAddresses::ForwardImported_AActor_PostBeginPlay, // +0x118: AActor::PostBeginPlay
    R6GameAddresses::ForwardImported_AActor_setPhysics, // +0x11c: AActor::setPhysics
    R6GameAddresses::ForwardImported_AActor_performPhysics, // +0x120: AActor::performPhysics
    R6GameAddresses::ForwardImported_AActor_BoundProjectileVelocity, // +0x124: AActor::BoundProjectileVelocity
    R6GameAddresses::ForwardImported_AActor_processHitWall, // +0x128: AActor::processHitWall
    R6GameAddresses::ForwardImported_AActor_processLanded, // +0x12c: AActor::processLanded
    R6GameAddresses::ForwardImported_AActor_physFalling, // +0x130: AActor::physFalling
    R6GameAddresses::ForwardImported_AActor_FindSlopeRotation, // +0x134: AActor::FindSlopeRotation
    R6GameAddresses::ForwardImported_AActor_SmoothHitWall, // +0x138: AActor::SmoothHitWall
    R6GameAddresses::ForwardImported_AActor_stepUp, // +0x13c: AActor::stepUp
    R6GameAddresses::ForwardImported_AActor_getKModel, // +0x140: AActor::getKModel
    R6GameAddresses::ForwardImported_AActor_physKarma, // +0x144: AActor::physKarma
    R6GameAddresses::ForwardImported_AActor_preKarmaStep, // +0x148: AActor::preKarmaStep
    R6GameAddresses::ForwardImported_AActor_postKarmaStep, // +0x14c: AActor::postKarmaStep
    R6GameAddresses::ForwardImported_AActor_KMP2DynKarmaInterface, // +0x150: AActor::KMP2DynKarmaInterface
    R6GameAddresses::ForwardImported_AActor_AddMyMarker, // +0x154: AActor::AddMyMarker
    R6GameAddresses::ForwardImported_AActor_AssociatedLevelGeometry, // +0x158: AActor::AssociatedLevelGeometry
    R6GameAddresses::ForwardImported_AActor_HasAssociatedLevelGeometry, // +0x15c: AActor::HasAssociatedLevelGeometry
    R6GameAddresses::ForwardImported_AActor_PlayAnim, // +0x160: AActor::PlayAnim
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnRadar, // +0x164: AActor::IsRelevantToPawnRadar
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnHeatVision, // +0x168: AActor::IsRelevantToPawnHeatVision
    R6GameAddresses::ForwardImported_AActor_IsRelevantToPawnHeartBeat, // +0x16c: AActor::IsRelevantToPawnHeartBeat
    R6GameAddresses::ForwardImported_AActor_TickThisFrame, // +0x170: AActor::TickThisFrame
    R6GameAddresses::ForwardImported_AActor_CheckForErrors, // +0x174: AActor::CheckForErrors
    R6GameAddresses::ForwardImported_AActor_PrePath, // +0x178: AActor::PrePath
    R6GameAddresses::ForwardImported_AActor_PostPath, // +0x17c: AActor::PostPath
    R6GameAddresses::ForwardImported_AActor_GetProjectorBase, // +0x180: AActor::GetProjectorBase
    R6GameAddresses::AR6HUD_DrawRadar, // +0x184: DrawRadar
    R6GameAddresses::AR6HUD_DrawInGameMap, // +0x188: DrawInGameMap
    R6GameAddresses::ForwardImported_AHUD_DrawSpecificModeInfo, // +0x18c: AHUD::DrawSpecificModeInfo
};

// R6Game.dll @ 10002240 : return the AR6HUD class object
UClass* __cdecl AR6HUD::StaticClass(void)
{
    return (UClass*)AR6HUDClassMetadataStorage;
}

// R6Game.dll @ 10002250 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6HUD::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6HUDClassMetadataStorage, outer, objectName, objectFlags, nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10004940 : assign inherited state and members
// Assigns inherited state, member values, and owned resources.
AR6HUD * __thiscall AR6HUD::operator=(AR6HUD *this, const AR6HUD *source)
{
  uint *destinationFlags = (uint *)((byte *)this + 0x524);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x524);
  uint copiedFlags; // Individual merges preserve destination bits 20..31.

  AR6AbstractHUD::operator=((AR6AbstractHUD *)this, (const AR6AbstractHUD *)source);
  this->m_eLastMovementMode = source->m_eLastMovementMode; // +0x50c.
  this->m_eLastTeamState = source->m_eLastTeamState; // +0x50d.
  this->m_eLastOtherTeamState[0] = source->m_eLastOtherTeamState[0]; // +0x50e.
  this->m_eLastOtherTeamState[1] = source->m_eLastOtherTeamState[1]; // +0x50f.
  this->m_eLastPlayerAPAction = source->m_eLastPlayerAPAction; // +0x510.
  this->m_eLastGoCode = source->m_eLastGoCode; // +0x511.
  this->m_iBulletCount = source->m_iBulletCount; // +0x514.
  this->m_iMaxBulletCount = source->m_iMaxBulletCount; // +0x518.
  this->m_iMagCount = source->m_iMagCount; // +0x51c.
  this->m_iCurrentMag = source->m_iCurrentMag; // +0x520.
  copiedFlags = *destinationFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1; // m_bDrawHUDinScript.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bGMIsSinglePlayer.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bGMIsCoop.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bGMIsTeamAdverserial.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bShowCharacterInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bShowCurrentTeamInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bShowOtherTeamInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bShowWeaponInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bShowFPWeapon.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200; // m_bShowWaypointInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bShowActionIcon.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800; // m_bShowMPRadar.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000; // m_bShowTeamMatesNames.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000; // m_bUpdateHUDInTraining.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000; // m_bDisplayTimeBomb.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000; // m_bDisplayRemainingTime.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000; // m_bNoDeathCamera.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000; // m_bLastSniperHold.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000; // m_bShowPressGoCode.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000; // m_bPressGoCodeCanBlink.
  *destinationFlags = copiedFlags;
  this->m_fPosX = source->m_fPosX; // +0x528.
  this->m_fPosY = source->m_fPosY; // +0x52c.
  this->m_fScaleX = source->m_fScaleX; // +0x530.
  this->m_fScaleY = source->m_fScaleY; // +0x534.
  this->m_fScale = source->m_fScale; // +0x538.
  this->m_GameRepInfo = source->m_GameRepInfo; // +0x53c.
  this->m_PlayerOwner = source->m_PlayerOwner; // +0x540.
  this->m_FlashbangFlash = source->m_FlashbangFlash; // +0x544.
  this->m_TexNightVision = source->m_TexNightVision; // +0x548.
  this->m_TexHeatVision = source->m_TexHeatVision; // +0x54c.
  this->m_TexHeatVisionActor = source->m_TexHeatVisionActor; // +0x550.
  this->m_TexHUDElements = source->m_TexHUDElements; // +0x554.
  this->m_pCurrentMaterial = source->m_pCurrentMaterial; // +0x558.
  this->m_HeartBeatMaskMul = source->m_HeartBeatMaskMul; // +0x55c.
  this->m_HeartBeatMaskAdd = source->m_HeartBeatMaskAdd; // +0x560.
  this->m_Waypoint = source->m_Waypoint; // +0x564.
  this->m_WaypointArrow = source->m_WaypointArrow; // +0x568.
  this->m_InGamePlanningPawnIcon = source->m_InGamePlanningPawnIcon; // +0x56c.
  this->m_LoadingScreen = source->m_LoadingScreen; // +0x570.
  this->m_TexNoise = source->m_TexNoise; // +0x574.
  this->m_TexProneTrail = source->m_TexProneTrail; // +0x578.
  this->m_pAlphaBlend = source->m_pAlphaBlend; // +0x57c.
  this->m_pNextWayPoint = source->m_pNextWayPoint; // +0x580.
  this->m_TexRadarTextures[0] = source->m_TexRadarTextures[0]; // +0x584.
  this->m_TexRadarTextures[1] = source->m_TexRadarTextures[1]; // +0x588.
  this->m_TexRadarTextures[2] = source->m_TexRadarTextures[2]; // +0x58c.
  this->m_TexRadarTextures[3] = source->m_TexRadarTextures[3]; // +0x590.
  this->m_TexRadarTextures[4] = source->m_TexRadarTextures[4]; // +0x594.
  this->m_TexRadarTextures[5] = source->m_TexRadarTextures[5]; // +0x598.
  this->m_TexRadarTextures[6] = source->m_TexRadarTextures[6]; // +0x59c.
  this->m_TexRadarTextures[7] = source->m_TexRadarTextures[7]; // +0x5a0.
  this->m_TexRadarTextures[8] = source->m_TexRadarTextures[8]; // +0x5a4.
  this->m_TexRadarTextures[9] = source->m_TexRadarTextures[9]; // +0x5a8.
  this->m_pLastRainbowTeam = source->m_pLastRainbowTeam; // +0x5ac.
  AssignFourByteFArray((FArray *)&this->m_aIOBombs, (const FArray *)&source->m_aIOBombs);
  this->m_iCurrentTeamColor = source->m_iCurrentTeamColor; // +0x5bc.
  this->m_CharacterInfoBoxColor = source->m_CharacterInfoBoxColor; // +0x5c0.
  this->m_CharacterInfoOutlineColor = source->m_CharacterInfoOutlineColor; // +0x5c4.
  this->m_WeaponBoxColor = source->m_WeaponBoxColor; // +0x5c8.
  this->m_WeaponOutlineColor = source->m_WeaponOutlineColor; // +0x5cc.
  this->m_TeamBoxColor = source->m_TeamBoxColor; // +0x5d0.
  this->m_TeamBoxOutlineColor = source->m_TeamBoxOutlineColor; // +0x5d4.
  this->m_OtherTeamBoxColor = source->m_OtherTeamBoxColor; // +0x5d8.
  this->m_OtherTeamOutlineColor = source->m_OtherTeamOutlineColor; // +0x5dc.
  this->m_WPIconBox = source->m_WPIconBox; // +0x5e0.
  this->m_WPIconOutlineColor = source->m_WPIconOutlineColor; // +0x5e4.
  // Copy timestamp, display byte plus padding, and color in native word order for each twelve-byte record.
  for (int element = 0; element < 16; ++element) {
    ((uint*)&this->m_HUDElements[element])[0] = ((const uint*)&source->m_HUDElements[element])[0];
    ((uint*)&this->m_HUDElements[element])[1] = ((const uint*)&source->m_HUDElements[element])[1];
    ((uint*)&this->m_HUDElements[element])[2] = ((const uint*)&source->m_HUDElements[element])[2];
  }
  FStringNoInit::operator=((FStringNoInit *)&this->m_szMovementMode,
      (const FStringNoInit *)&source->m_szMovementMode); // +0x6a8.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szTeamState,
      (const FStringNoInit *)&source->m_szTeamState); // +0x6b4.
  for (int team = 0; team < 2; ++team)
    FStringNoInit::operator=((FStringNoInit*)&this->m_szOtherTeamState[team],
        (const FStringNoInit*)&source->m_szOtherTeamState[team]);
  for (int team = 0; team < 2; ++team)
    FStringNoInit::operator=((FStringNoInit*)&this->m_aszOtherTeamName[team],
        (const FStringNoInit*)&source->m_aszOtherTeamName[team]);
  FStringNoInit::operator=((FStringNoInit *)&this->m_szLastPlayerAPAction,
      (const FStringNoInit *)&source->m_szLastPlayerAPAction); // +0x6f0.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szPressGoCode,
      (const FStringNoInit *)&source->m_szPressGoCode); // +0x6fc.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szTeam,
      (const FStringNoInit *)&source->m_szTeam); // +0x708.
  return this;
}

// R6Game.dll @ 10005f10 : destroy owned resources and inherited state
// Runs conditional shutdown, destroys owned members in reverse order, and destroys the base.
void __thiscall AR6HUD::~AR6HUD(AR6HUD *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6HUDDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6HUD_vftable;
  // Native EBP-0x10 saves this for the nine-state reverse member cleanup map.
  exceptionRegistration.state = 8;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 7;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szTeam); // +0x708.
  *(byte*)&exceptionRegistration.state = 6;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szPressGoCode); // +0x6fc.
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szLastPlayerAPAction); // +0x6f0.
  auto destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  *(byte*)&exceptionRegistration.state = 4;
  _eh_vector_destructor_iterator_(this->m_aszOtherTeamName, 12, 2, destroyString); // +0x6d8.
  destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  *(byte*)&exceptionRegistration.state = 3;
  _eh_vector_destructor_iterator_(this->m_szOtherTeamState, 12, 2, destroyString); // +0x6c0.
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szTeamState); // +0x6b4.
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szMovementMode); // +0x6a8.
  *(byte*)&exceptionRegistration.state = 0;
  DestroyFourByteFArray((FArray *)&this->m_aIOBombs); // +0x5b0.
  exceptionRegistration.state = -1;
  AR6AbstractHUD::~AR6AbstractHUD((AR6AbstractHUD *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10006000 : construct the HUD base and its nine no-init strings
AR6HUD* __thiscall AR6HUD::AR6HUD(AR6HUD* this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6HUDConstructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  AR6AbstractHUD::AR6AbstractHUD((AR6AbstractHUD*)this);
  // Native EBP-0x10 saves this; the bomb-array header is not explicitly initialized here.
  exceptionRegistration.state = 0;
  *(const uint**)this = AR6HUD_vftable;
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMovementMode);
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szTeamState);
  auto destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  auto constructString = *(FStringNoInit* (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DefaultConstructorSlot;
  *(byte*)&exceptionRegistration.state = 3;
  _eh_vector_constructor_iterator_(this->m_szOtherTeamState, 12, 2, constructString, destroyString);
  destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  constructString = *(FStringNoInit* (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DefaultConstructorSlot;
  *(byte*)&exceptionRegistration.state = 4;
  _eh_vector_constructor_iterator_(this->m_aszOtherTeamName, 12, 2, constructString, destroyString);
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szLastPlayerAPAction);
  *(byte*)&exceptionRegistration.state = 6;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szPressGoCode);
  *(byte*)&exceptionRegistration.state = 7;
  FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szTeam);
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 100060e0 : copy-construct inherited state and members
// Copy-constructs inherited state, member values, and owned resources.
AR6HUD * __thiscall AR6HUD::AR6HUD(AR6HUD *this, const AR6HUD *source)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6HUDCopyExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  uint *destinationFlags = (uint *)((byte *)this + 0x524);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x524);
  uint copiedFlags; // Individual merges preserve destination bits 20..31.

  AR6AbstractHUD::AR6AbstractHUD((AR6AbstractHUD *)this, (const AR6AbstractHUD *)source);
  *(const uint**)this = AR6HUD_vftable;
  this->m_eLastMovementMode = source->m_eLastMovementMode; // +0x50c.
  this->m_eLastTeamState = source->m_eLastTeamState; // +0x50d.
  *(ushort*)(&this->m_eLastOtherTeamState[0]) = *(const ushort*)(&source->m_eLastOtherTeamState[0]); // +0x50e.
  this->m_eLastPlayerAPAction = source->m_eLastPlayerAPAction; // +0x510.
  this->m_eLastGoCode = source->m_eLastGoCode; // +0x511.
  this->m_iBulletCount = source->m_iBulletCount; // +0x514.
  this->m_iMaxBulletCount = source->m_iMaxBulletCount; // +0x518.
  auto copiedMagCount = source->m_iMagCount; // +0x51c.
  uint firstDestinationFlags = *destinationFlags;
  this->m_iMagCount = copiedMagCount;
  auto copiedCurrentMag = source->m_iCurrentMag; // +0x520.
  copiedFlags = *destinationFlags;
  this->m_iCurrentMag = copiedCurrentMag;
  copiedFlags ^= (*sourceFlags ^ firstDestinationFlags) & 0x1; // m_bDrawHUDinScript.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bGMIsSinglePlayer.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bGMIsCoop.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bGMIsTeamAdverserial.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bShowCharacterInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bShowCurrentTeamInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bShowOtherTeamInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bShowWeaponInfo.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bShowFPWeapon.
  *destinationFlags = copiedFlags;
  uint waypointFlagChange = (*sourceFlags ^ copiedFlags) & 0x200; // m_bShowWaypointInfo.
  exceptionRegistration.state = 0;
  copiedFlags ^= waypointFlagChange;
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bShowActionIcon.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800; // m_bShowMPRadar.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000; // m_bShowTeamMatesNames.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000; // m_bUpdateHUDInTraining.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000; // m_bDisplayTimeBomb.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000; // m_bDisplayRemainingTime.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000; // m_bNoDeathCamera.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000; // m_bLastSniperHold.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000; // m_bShowPressGoCode.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000; // m_bPressGoCodeCanBlink.
  *destinationFlags = copiedFlags;
  this->m_fPosX = source->m_fPosX; // +0x528.
  this->m_fPosY = source->m_fPosY; // +0x52c.
  this->m_fScaleX = source->m_fScaleX; // +0x530.
  this->m_fScaleY = source->m_fScaleY; // +0x534.
  this->m_fScale = source->m_fScale; // +0x538.
  this->m_GameRepInfo = source->m_GameRepInfo; // +0x53c.
  this->m_PlayerOwner = source->m_PlayerOwner; // +0x540.
  this->m_FlashbangFlash = source->m_FlashbangFlash; // +0x544.
  this->m_TexNightVision = source->m_TexNightVision; // +0x548.
  this->m_TexHeatVision = source->m_TexHeatVision; // +0x54c.
  this->m_TexHeatVisionActor = source->m_TexHeatVisionActor; // +0x550.
  this->m_TexHUDElements = source->m_TexHUDElements; // +0x554.
  this->m_pCurrentMaterial = source->m_pCurrentMaterial; // +0x558.
  this->m_HeartBeatMaskMul = source->m_HeartBeatMaskMul; // +0x55c.
  this->m_HeartBeatMaskAdd = source->m_HeartBeatMaskAdd; // +0x560.
  this->m_Waypoint = source->m_Waypoint; // +0x564.
  this->m_WaypointArrow = source->m_WaypointArrow; // +0x568.
  this->m_InGamePlanningPawnIcon = source->m_InGamePlanningPawnIcon; // +0x56c.
  this->m_LoadingScreen = source->m_LoadingScreen; // +0x570.
  this->m_TexNoise = source->m_TexNoise; // +0x574.
  this->m_TexProneTrail = source->m_TexProneTrail; // +0x578.
  this->m_pAlphaBlend = source->m_pAlphaBlend; // +0x57c.
  this->m_pNextWayPoint = source->m_pNextWayPoint; // +0x580.
  this->m_TexRadarTextures[0] = source->m_TexRadarTextures[0]; // +0x584.
  this->m_TexRadarTextures[1] = source->m_TexRadarTextures[1]; // +0x588.
  this->m_TexRadarTextures[2] = source->m_TexRadarTextures[2]; // +0x58c.
  this->m_TexRadarTextures[3] = source->m_TexRadarTextures[3]; // +0x590.
  this->m_TexRadarTextures[4] = source->m_TexRadarTextures[4]; // +0x594.
  this->m_TexRadarTextures[5] = source->m_TexRadarTextures[5]; // +0x598.
  this->m_TexRadarTextures[6] = source->m_TexRadarTextures[6]; // +0x59c.
  this->m_TexRadarTextures[7] = source->m_TexRadarTextures[7]; // +0x5a0.
  this->m_TexRadarTextures[8] = source->m_TexRadarTextures[8]; // +0x5a4.
  this->m_TexRadarTextures[9] = source->m_TexRadarTextures[9]; // +0x5a8.
  this->m_pLastRainbowTeam = source->m_pLastRainbowTeam; // +0x5ac.
  ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_aIOBombs, (const FArray *)&source->m_aIOBombs);
  this->m_iCurrentTeamColor = source->m_iCurrentTeamColor; // +0x5bc.
  this->m_CharacterInfoBoxColor = source->m_CharacterInfoBoxColor; // +0x5c0.
  this->m_CharacterInfoOutlineColor = source->m_CharacterInfoOutlineColor; // +0x5c4.
  this->m_WeaponBoxColor = source->m_WeaponBoxColor; // +0x5c8.
  this->m_WeaponOutlineColor = source->m_WeaponOutlineColor; // +0x5cc.
  this->m_TeamBoxColor = source->m_TeamBoxColor; // +0x5d0.
  this->m_TeamBoxOutlineColor = source->m_TeamBoxOutlineColor; // +0x5d4.
  this->m_OtherTeamBoxColor = source->m_OtherTeamBoxColor; // +0x5d8.
  this->m_OtherTeamOutlineColor = source->m_OtherTeamOutlineColor; // +0x5dc.
  this->m_WPIconBox = source->m_WPIconBox; // +0x5e0.
  this->m_WPIconOutlineColor = source->m_WPIconOutlineColor; // +0x5e4.
  // Copy timestamp, display byte plus padding, and color in native word order for each twelve-byte record.
  for (int element = 0; element < 16; ++element) {
    ((uint*)&this->m_HUDElements[element])[0] = ((const uint*)&source->m_HUDElements[element])[0];
    ((uint*)&this->m_HUDElements[element])[1] = ((const uint*)&source->m_HUDElements[element])[1];
    ((uint*)&this->m_HUDElements[element])[2] = ((const uint*)&source->m_HUDElements[element])[2];
  }
  *(byte*)&exceptionRegistration.state = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szMovementMode,
      (const FStringNoInit *)&source->m_szMovementMode); // +0x6a8.
  *(byte*)&exceptionRegistration.state = 2;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szTeamState,
      (const FStringNoInit *)&source->m_szTeamState); // +0x6b4.
  auto destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  auto copyString = *(FStringNoInit* (__thiscall**)(FStringNoInit*, const FStringNoInit*))R6GameImports::Core_FStringNoInit_CopyConstructorSlot;
  *(byte*)&exceptionRegistration.state = 3;
  _eh_vector_copy_constructor_iterator_(this->m_szOtherTeamState, source->m_szOtherTeamState,
      12, 2, copyString, destroyString);
  destroyString = *(void (__thiscall**)(FStringNoInit*))R6GameImports::Core_FStringNoInit_DestructorSlot;
  copyString = *(FStringNoInit* (__thiscall**)(FStringNoInit*, const FStringNoInit*))R6GameImports::Core_FStringNoInit_CopyConstructorSlot;
  _eh_vector_copy_constructor_iterator_(this->m_aszOtherTeamName, source->m_aszOtherTeamName,
      12, 2, copyString, destroyString);
  // Native state remains 3 through both fixed arrays and the following last-action string construction.
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szLastPlayerAPAction,
      (const FStringNoInit *)&source->m_szLastPlayerAPAction); // +0x6f0.
  *(byte*)&exceptionRegistration.state = 4;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szPressGoCode,
      (const FStringNoInit *)&source->m_szPressGoCode); // +0x6fc.
  *(byte*)&exceptionRegistration.state = 5;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szTeam,
      (const FStringNoInit *)&source->m_szTeam); // +0x708.
  __writefsdword(0, exceptionRegistration.previousAddress);
  return this;
}

// R6Game.dll @ 10006e40 : construct a HUD in supplied nonnull memory
void __cdecl AR6HUD::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6HUD::AR6HUD((AR6HUD*)objectMemory);
}

// R6Game.dll @ 1000ace0 : execHudStep
// Sets the HUD step display range and starts a flash when the requested step matches its box.
void __thiscall AR6HUD::execHudStep(AR6HUD* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_HudStepExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    FFrame* executionStack = stack;
    byte** codeCursor = (byte**)((byte*)executionStack + 0xc);
    byte* boxCode = *codeCursor;
    int iBox = 0;
    byte boxOpcode = *boxCode;
    *codeCursor = (byte*)((uint)boxCode + 1U);
    ScriptNative* boxNativeTable = (ScriptNative*)ImportedGNativesAddress;
    AR6HUD* hud = this;
    UObject* boxContext = *(UObject**)((byte*)executionStack + 8);
    exceptionRegistration.state = 0;
    boxNativeTable[boxOpcode](boxContext, executionStack, &iBox);
    byte* stepCode = *codeCursor;
    UObject* stepContext = *(UObject**)((byte*)executionStack + 8);
    int& iIDStep = *(int*)&stack; // Native reuses the retained frame's incoming DWORD.
    iIDStep = 0;
    byte stepOpcode = *stepCode;
    *codeCursor = (byte*)((uint)stepCode + 1U);
    ScriptNative* stepNativeTable = (ScriptNative*)ImportedGNativesAddress;
    stepNativeTable[stepOpcode](stepContext, executionStack, &iIDStep);
    byte* flashCode = *codeCursor;
    UObject* flashContext = *(UObject**)((byte*)executionStack + 8);
    uint bFlash = 1;
    byte flashOpcode = *flashCode;
    *codeCursor = (byte*)((uint)flashCode + 1U);
    ScriptNative* flashNativeTable = (ScriptNative*)ImportedGNativesAddress;
    flashNativeTable[flashOpcode](flashContext, executionStack, &bFlash);
    byte* debugCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = debugCode;
    if (*debugCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)executionStack + 8);
        *codeCursor = (byte*)((uint)debugCode + 1U);
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, executionStack, nullptr);
    }
    int lastDisplayed = 0;
    bool matchingStep = false;
    switch (iBox) {
    case 1:
        matchingStep = iIDStep == 1;
        break;
    case 2:
        if (iIDStep == 2) { lastDisplayed = 1; matchingStep = true; }
        break;
    case 3:
        lastDisplayed = iIDStep == 3 ? 2 : 1;
        matchingStep = iIDStep == 3;
        break;
    case 4: case 5: case 6: case 7:
        lastDisplayed = 2;
        break;
    case 8:
        lastDisplayed = 2;
        if (iIDStep >= 4 && iIDStep <= 8) { lastDisplayed = iIDStep - 1; matchingStep = true; }
        break;
    case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 19: case 20:
        lastDisplayed = 7;
        break;
    case 21:
        lastDisplayed = 7;
        if (iIDStep == 9 || iIDStep == 10) { lastDisplayed = iIDStep - 1; matchingStep = true; }
        break;
    case 22:
        lastDisplayed = 9;
        if (iIDStep == 11) { lastDisplayed = 10; matchingStep = true; }
        else if (iIDStep == 12) { lastDisplayed = 11; matchingStep = true; }
        else if (iIDStep == 13 || iIDStep == 14) { lastDisplayed = 13; matchingStep = true; }
        break;
    case 23:
        lastDisplayed = 13;
        break;
    case 24:
        lastDisplayed = iIDStep == 15 ? 14 : 13;
        matchingStep = iIDStep == 15;
        break;
    case 25: case 26: case 27: case 28:
        lastDisplayed = 14;
        break;
    }
    for (int index = 0; index < 16; ++index) {
        uint* displayWord = (uint*)((byte*)&hud->m_HUDElements[index] + 4);
        *displayWord = index > lastDisplayed || (iBox == 1 && iIDStep < 1) ? 1U : 0U;
    }
    if (bFlash != 0 && matchingStep) {
        uint clockLow, clockHigh;
        int integralClockLow;
        // Preserve the selected x87 conversion helper's ST0 input and EDX:EAX result contract.
        __asm {
            rdtsc
            mov clockLow,eax
            mov clockHigh,edx
            fild DWORD PTR clockHigh
            mov eax,clockHigh
            test eax,eax
            jge hudStepHighNonnegative
            fadd QWORD PTR HudClockUnsignedWordRange
        hudStepHighNonnegative:
            mov ecx,clockLow
            fmul QWORD PTR HudClockUnsignedWordRange
            test ecx,ecx
            fild DWORD PTR clockLow
            jge hudStepLowNonnegative
            fadd QWORD PTR HudClockUnsignedWordRange
        hudStepLowNonnegative:
            mov edx,DWORD PTR ds:R6GameAddresses::Core_GSecondsPerCycleSlot
            faddp st(1),st
            fmul QWORD PTR [edx]
            fadd QWORD PTR HudClockBias
            call ConvertX87ToSigned64
            mov integralClockLow,eax
        }
        byte* flashElement = (byte*)&hud->m_HUDElements[lastDisplayed];
        __asm {
            fild dword ptr integralClockLow
            mov eax,flashElement
            fadd dword ptr HudStepFlashDuration
            mov dword ptr [eax+0x4],0x3
            fstp dword ptr [eax]
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000af58 : rethrow HudStep's caught four-byte value
__declspec(naked) void AR6HUD_execHudStepCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x24]
        push eax
        mov dword ptr [ebp-0x24],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000af6c : report HudStep context and rethrow the active exception
__declspec(naked) void AR6HUD_execHudStepCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_execHudStepExceptionContext // L"AR6HUD::execHudStep"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000b000 : UpdateHUDColors
// Updates element flash visibility and derives the surrounding HUD box and outline colors.
void __thiscall AR6HUD::UpdateHUDColors(AR6HUD* this, FColor teamColor)
{
    this->m_iCurrentTeamColor = teamColor;
    for (int index = 0; index < 16; ++index) {
        auto* element = &this->m_HUDElements[index];
        uint* displayWord = (uint*)((byte*)element + 4);
        FColor hudWhite = this->Colors->HUDWhite;
        uint display = *displayWord;
        element->Color = hudWhite;
        if (display == 1) {
            element->Color.A = 0;
        } else if (display == 3) {
            unsigned long long firstCycles = __rdtsc();
            double firstClock = (double)((long double)firstCycles * *(double*)ImportedGSecondsPerCycleAddress
                + 16777216.0L);
            uint clockLow, clockHigh;
            int integralClockLow;
            const double twoTo32 = 4294967296.0;
            const double clockBias = 16777216.0;
            // Keep the second clock in ST0 through the selected signed-integer conversion helper.
            __asm {
                rdtsc
                mov clockLow,eax
                mov clockHigh,edx
                fild DWORD PTR clockHigh
                mov eax,clockHigh
                test eax,eax
                jge hudColorsHighNonnegative
                fadd QWORD PTR twoTo32
            hudColorsHighNonnegative:
                mov ecx,clockLow
                fmul QWORD PTR twoTo32
                test ecx,ecx
                fild DWORD PTR clockLow
                jge hudColorsLowNonnegative
                fadd QWORD PTR twoTo32
            hudColorsLowNonnegative:
                mov edx,DWORD PTR ds:R6GameAddresses::Core_GSecondsPerCycleSlot
                faddp st(1),st
                fmul QWORD PTR [edx]
                fadd QWORD PTR clockBias
                call ConvertX87ToSigned64
                mov integralClockLow,eax
            }
            long double phase = (long double)firstClock - (long double)integralClockLow;
            if (phase < 0.5L) {
                element->Color.A = 0;
            } else { // The native parity branch includes unordered phase comparisons.
                unsigned long long thirdCycles = __rdtsc();
                long double deadline = (long double)element->fTimeStamp;
                long double thirdClock = (long double)thirdCycles * *(double*)ImportedGSecondsPerCycleAddress
                    + 16777216.0L;
                if (thirdClock > deadline)
                    *displayWord = 0;
            }
        }
    }
    if (this->m_HUDElements[0].Color.A == 0 &&
        this->m_HUDElements[1].Color.A == 0 &&
        this->m_HUDElements[10].Color.A == 0) {
        this->m_CharacterInfoBoxColor = teamColor;
        this->m_CharacterInfoBoxColor.A = 0;
        this->m_CharacterInfoOutlineColor.A = 0;
    } else {
        this->m_CharacterInfoBoxColor = teamColor;
        this->m_CharacterInfoOutlineColor = this->Colors->HUDWhite;
    }
    if (this->m_HUDElements[3].Color.A == 0 &&
        this->m_HUDElements[5].Color.A == 0 &&
        this->m_HUDElements[6].Color.A == 0 &&
        this->m_HUDElements[7].Color.A == 0 &&
        this->m_HUDElements[4].Color.A == 0) {
        this->m_WeaponBoxColor = teamColor;
        this->m_WeaponBoxColor.A = 0;
        this->m_WeaponOutlineColor.A = 0;
    } else {
        this->m_WeaponBoxColor = teamColor;
        this->m_WeaponOutlineColor = this->Colors->HUDWhite;
    }
    if (this->m_HUDElements[8].Color.A == 0 &&
        this->m_HUDElements[9].Color.A == 0) {
        this->m_TeamBoxColor = teamColor;
        this->m_TeamBoxColor.A = 0;
        this->m_TeamBoxOutlineColor.A = 0;
    } else {
        this->m_TeamBoxColor = teamColor;
        this->m_TeamBoxOutlineColor = this->Colors->HUDWhite;
    }
    if (this->m_HUDElements[14].Color.A == 0) {
        this->m_OtherTeamBoxColor = teamColor;
        this->m_OtherTeamBoxColor.A = 0;
        this->m_OtherTeamOutlineColor.A = 0;
    } else {
        this->m_OtherTeamBoxColor = teamColor;
        this->m_OtherTeamOutlineColor = this->Colors->HUDWhite;
    }
    if (this->m_HUDElements[13].Color.A == 0) {
        this->m_WPIconBox = teamColor;
        this->m_WPIconBox.A = 0;
        this->m_WPIconOutlineColor.A = 0;
    } else {
        this->m_WPIconBox = teamColor;
        this->m_WPIconOutlineColor = this->Colors->HUDWhite;
    }
}

// R6Game.dll @ 1000b2c0 : clear the last-team reference and destroy HUD actor state
// Clears the cached last team before inherited actor destruction.
void __thiscall AR6HUD::Destroy(AR6HUD* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DestroyExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    this->m_pLastRainbowTeam = nullptr; // +0x5ac.
    AActor::Destroy((AActor*)this);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000b309 : rethrow HUD Destroy's caught four-byte value
__declspec(naked) void AR6HUD_DestroyCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000b31d : report HUD Destroy context and rethrow the active exception
__declspec(naked) void AR6HUD_DestroyCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DestroyExceptionContext // L"AR6HUD::Destroy"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000b810 : Spawned
// Creates the dynamic HUD blend material and initializes cached display selections.
void __thiscall AR6HUD::Spawned(AR6HUD* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_SpawnedExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UClass* blendClass = *(UClass**)R6GameImports::Engine_UFinalBlend_PrivateStaticClassSlot; // UFinalBlend::PrivateStaticClass.
    exceptionRegistration.state = 0;
    if (blendClass == nullptr)
        appFailAssert("Class->IsChildOf(T::StaticClass())",
            "d:\\ravenshield\\412\\core\\inc\\UnObjBas.h", 0x476);
    UPackage* outer = UObject::GetTransientPackage();
    FOutputDevice* errorOutput = *(FOutputDevice**)ImportedGErrorAddress;
    UFinalBlend* blend = (UFinalBlend*)UObject::StaticConstructObject(blendClass, (UObject*)outer,
        FName(0), 0, nullptr, errorOutput, 0);
    this->m_pAlphaBlend = blend;
    uint* materialFlags = (uint*)((byte*)blend + 0x34);
    *materialFlags |= 8U; // m_bDynamicMaterial.
    this->m_pAlphaBlend->FrameBufferBlending = 2;
    UFinalBlend* materialBlend = this->m_pAlphaBlend;
    UMaterial* materialTexture = (UMaterial*)this->m_TexHUDElements;
    materialBlend->Material = materialTexture;
    uint* depthFlags = (uint*)((byte*)this->m_pAlphaBlend + 0x60);
    *depthFlags &= ~1U; // ZWrite.
    depthFlags = (uint*)((byte*)this->m_pAlphaBlend + 0x60);
    *depthFlags &= ~2U; // ZTest.
    UMaterial* hudElements = (UMaterial*)this->m_TexHUDElements;
    this->m_eLastPlayerAPAction = 8;
    uint previousExceptionAddress = exceptionRegistration.previousAddress;
    this->m_pCurrentMaterial = hudElements;
    this->m_eLastMovementMode = 3;
    this->m_eLastTeamState = 0x16;
    this->m_eLastOtherTeamState[0] = 0x16;
    this->m_eLastOtherTeamState[1] = 0x16;
    this->m_eLastGoCode = 5;
    __writefsdword(0, previousExceptionAddress);
}

// R6Game.dll @ 1000b91f : rethrow HUD Spawned's caught four-byte value
__declspec(naked) void AR6HUD_SpawnedCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000b933 : report HUD Spawned context and rethrow the active exception
__declspec(naked) void AR6HUD_SpawnedCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_SpawnedExceptionContext // L"AR6HUD::Spawned"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000b950 : serialize HUD actor state and its nonpersistent alpha-blend reference
// Serializes the actor, then visits the alpha blend outside loading and saving.
void __thiscall AR6HUD::Serialize(AR6HUD* this, FArchive* archive)
{
    AActor::Serialize((AActor*)this, archive);
    if (*(int*)((byte*)archive + 0x14) == 0 && *(int*)((byte*)archive + 0x18) == 0) {
        auto transferReference = *(FArchive* (__thiscall**)(FArchive*, UObject**))(*(byte**)archive + 0x18);
        transferReference(archive, (UObject**)&this->m_pAlphaBlend); // +0x57c.
    }
}

// R6Game.dll @ 1000b980 : DrawSingleCharacterInfo
// Measures the character name and draws the expanding single-character panel, stance and optional name/health.
void __thiscall AR6HUD::DrawSingleCharacterInfo(AR6HUD* this, AR6Rainbow* rainbow, float x, float y,
    FColor* unusedColor, FCanvasUtil* canvas, UCanvas* textCanvas)
{
    using DrawTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor);
    using ColorPlaneCall = FPlane* (__thiscall *)(const FColor*, FPlane*);
    using DrawStringCall = int (__thiscall *)(UCanvas*, UFont*, int, int, const ushort*, FPlane, int, int, int);
    alignas(4) byte nameStorage[12], colorPlaneStorage[16];
    FString* characterName = (FString*)nameStorage;
    FPlane* textColor = (FPlane*)colorPlaneStorage;
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DrawSingleCharacterInfoExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    AR6HUD* hud = this;
    int panelWidth;
    exceptionRegistration.state = 0;
    panelWidth = 150;
    FString::FString(characterName);
    // m_bGMIsSinglePlayer is tested through its first byte before activating string cleanup.
    bool singlePlayer = (*(const byte*)((const byte*)hud + 0x524) & 2U) != 0;
    *(byte*)&exceptionRegistration.state = 1;
    if (singlePlayer) {
        AR6Rainbow* nameCharacter = rainbow;
        FString::operator=(characterName, &nameCharacter->m_CharacterName);
    } else {
        AR6Rainbow* nameCharacter = rainbow;
        AR6TeamMemberReplicationInfo* replication = nameCharacter->m_TeamMemberRepInfo;
        if (replication != nullptr)
            FString::operator=(characterName, &replication->m_CharacterName);
    }
    int nameCount = *(int*)((byte*)characterName + 4);
    if (nameCount != 0 && nameCount != 1) {
        UCanvas* measurementCanvas = textCanvas;
        measurementCanvas->Style = 0;
        FColor measurementColor;
        ((byte*)&measurementColor)[0] = 255;
        ((byte*)&measurementColor)[1] = 255;
        ((byte*)&measurementColor)[2] = 255;
        ((byte*)&measurementColor)[3] = 255;
        (*(ColorPlaneCall*)R6GameImports::Engine_FColor_ConversionOperatorSlot)(&measurementColor, textColor);
        const ushort* nameText = FString::operator*(characterName);
        byte* measurementVtable = *(byte**)measurementCanvas;
        UFont* measurementFont = hud->m_FontRainbow6_14pt;
        DrawStringCall drawString = *(DrawStringCall*)(measurementVtable + 0x78);
        int measuredWidth = drawString(measurementCanvas, measurementFont, 0, 0, nameText, *textColor, 0, 0, 0);
        int requestedWidth = (int)((uint)measuredWidth + 60U);
        panelWidth = 150;
        if (requestedWidth > 150)
            panelWidth = requestedWidth;
        measurementCanvas->Style = 5;
    }
    float bottom, innerLeft;
    float& right = *(float*)&panelWidth; // Native reuses the integer width DWORD after FILD.
    float& outerRight = *(float*)&canvas; // Native retains the canvas before reusing its incoming DWORD.
    float tileX1, tileY1, tileX2, tileY2;
    FCanvasUtil* panelCanvas;
    DrawTileCall drawTile;
    __asm {
        fld dword ptr y
    }
    FColor tileColor;
    *(uint*)&tileColor = *(uint*)&hud->m_CharacterInfoBoxColor;
    __asm {
        fadd dword ptr HudSinglePanelHeight
    }
    UMaterial* tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr bottom
        fild dword ptr panelWidth
    }
    panelCanvas = canvas;
    drawTile = *(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
    __asm {
        fadd dword ptr x
        fstp dword ptr right
    }
    __asm {
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr right
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        134.0f, 416.0f, 138.0f, 457.0f, 1.0f, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_CharacterInfoBoxColor;
    __asm {
        fld dword ptr right
        fadd dword ptr HudSinglePanelOuterOffset
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr outerRight
    }
    __asm {
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr right
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr outerRight
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        128.0f, 416.0f, 134.0f, 457.0f, 1.0f, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_CharacterInfoOutlineColor;
    __asm {
        fld dword ptr x
        fadd dword ptr HudSinglePanelInnerOffset
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr innerLeft
    }
    __asm {
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr right
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr innerLeft
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        134.0f, 457.0f, 138.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_CharacterInfoOutlineColor;
    __asm {
        fld dword ptr bottom
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr right
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr outerRight
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        128.0f, 457.0f, 134.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_CharacterInfoOutlineColor;
    __asm {
        fld dword ptr bottom
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr x
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr innerLeft
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        138.0f, 457.0f, 142.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    AR6Rainbow* stanceCharacter = rainbow;
    uint stanceFlags = *(uint*)((byte*)stanceCharacter + 0x3e0);
    float stanceU1, stanceU2;
    if ((stanceFlags & 0x20U) != 0) {
        stanceU1 = 180.0f;
        stanceU2 = 217.0f;
    } else if ((stanceFlags & 0x300U) == 0) {
        stanceU1 = 143.0f;
        stanceU2 = 179.0f;
    } else {
        stanceU1 = 217.0f;
        stanceU2 = 254.0f;
    }
    *(uint*)&tileColor = *(uint*)&hud->m_HUDElements[1].Color;
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fld dword ptr y
        fadd dword ptr HudSingleStanceBottomOffset
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr x
        fadd dword ptr HudSingleStanceRightOffset
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fadd dword ptr NativeFloatFive
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fadd dword ptr NativeFloatFive
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        stanceU1, 464.0f, stanceU2, 494.0f, 1.0f, tileMaterial, tileColor);
    FCanvasUtil::Flush(panelCanvas);
    nameCount = *(int*)((byte*)characterName + 4);
    if (nameCount != 0 && nameCount != 1) {
        canvas = (FCanvasUtil*)textColor; // The incoming canvas word now holds the outgoing plane address.
        (*(ColorPlaneCall*)R6GameImports::Engine_FColor_ConversionOperatorSlot)(&hud->m_HUDElements[0].Color, textColor);
        const ushort* nameText = FString::operator*(characterName);
        int textX, textY;
        __asm {
            fld dword ptr y
        }
        UCanvas* nameVtableCanvas = textCanvas;
        __asm {
            fadd dword ptr HudSinglePanelOuterOffset
        }
        byte* nameVtable = *(byte**)nameVtableCanvas;
        __asm {
            call ConvertX87ToSigned64
            mov textY,eax
            fld dword ptr x
            fadd dword ptr HudSingleNameOffsetX
            call ConvertX87ToSigned64
            mov textX,eax
        }
        UFont* nameFont = hud->m_FontRainbow6_14pt;
        UCanvas* nameCanvas = textCanvas;
        DrawStringCall nameDraw = *(DrawStringCall*)(nameVtable + 0x78);
        nameDraw(nameCanvas, nameFont, textX, textY, nameText, *textColor, 0, 0, 0);
        AR6Rainbow* healthCharacter = rainbow;
        uint health = *(const byte*)((const byte*)healthCharacter + 0x3a2); // m_eHealth.
        if (health > 2)
            health = 2;
        FColor healthColor;
        *(uint*)&healthColor = *(uint*)&hud->m_HUDElements[0].Color;
        UMaterial* healthMaterial = (UMaterial*)hud->m_pAlphaBlend;
        int atlasV1 = (int)(health << 3);
        int& healthV1Word = *(int*)&textCanvas;
        healthV1Word = atlasV1;
        int& healthV2Word = *(int*)&rainbow;
        healthV2Word = atlasV1 + 8;
        float healthV1, healthV2;
        __asm {
            fild dword ptr healthV2Word
            fstp dword ptr healthV2
            fild dword ptr healthV1Word
            fstp dword ptr healthV1
            fld dword ptr y
            fadd dword ptr HudSingleHealthBottomOffset
            mov eax,hud
            fmul dword ptr [eax+0x534]
            fstp dword ptr tileY2
            fld dword ptr x
            fadd dword ptr HudSingleHealthRightOffset
            fmul dword ptr [eax+0x530]
            fstp dword ptr tileX2
            fld dword ptr y
            fadd dword ptr HudSingleHealthTopOffset
            fmul dword ptr [eax+0x534]
            fstp dword ptr tileY1
            fld dword ptr x
            fadd dword ptr HudSingleHealthLeftOffset
            fmul dword ptr [eax+0x530]
            fstp dword ptr tileX1
        }
        (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
            tileX1, tileY1, tileX2, tileY2, 500.0f, healthV1, 508.0f, healthV2, 1.0f, healthMaterial, healthColor);
    }
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(characterName);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000be7c : rethrow DrawSingleCharacterInfo's caught four-byte value
__declspec(naked) void AR6HUD_DrawSingleCharacterInfoCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000be90 : report DrawSingleCharacterInfo context and rethrow the active exception
__declspec(naked) void AR6HUD_DrawSingleCharacterInfoCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawSingleCharacterInfoExceptionContext // L"AR6HUD::DrawSingleCharacterInfo"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000beb0 : DrawCharacterInfo
// Draws the character panel, stance icon, available character name and health icon.
void __thiscall AR6HUD::DrawCharacterInfo(AR6HUD* this, AR6Rainbow* rainbow, float x, float y,
    FColor* outlineColor, FCanvasUtil* canvas, UCanvas* textCanvas)
{
    using DrawTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DrawCharacterInfoExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    FColor* firstOutline = outlineColor;
    float bottom, right, tileX1, tileY1, tileX2, tileY2;
    __asm {
        fld dword ptr y
        fadd dword ptr HudSinglePanelHeight
        fstp dword ptr bottom
    }
    AR6HUD* hud = this;
    FColor firstColor;
    *(uint*)&firstColor = *(uint*)firstOutline;
    __asm {
        fld dword ptr x
        fadd dword ptr HudCharacterPanelWidth
    }
    UMaterial* firstMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr right
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
    }
    FCanvasUtil* panelCanvas = canvas;
    __asm {
        fld dword ptr right
    }
    DrawTileCall drawTile = *(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
    __asm {
        fsub dword ptr HudCharacterPanelBorderInset
    }
    exceptionRegistration.state = 0;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fadd dword ptr HudCharacterPanelBorderInset
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        134.0f, 416.0f, 138.0f, 457.0f, 1.0f, firstMaterial, firstColor);
    float& innerLeft = *(float*)&outlineColor; // Native reuses the incoming outline-pointer DWORD.
    float& innerRight = *(float*)&canvas; // The canvas was retained before its incoming DWORD is reused.
    auto* tileColors = hud->Colors;
    __asm {
        fld dword ptr x
        fadd dword ptr HudSinglePanelInnerOffset
    }
    FColor tileColor;
    *(uint*)&tileColor = *(uint*)&tileColors->HUDWhite;
    UMaterial* tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr innerLeft
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr innerLeft
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        142.0f, 457.0f, 138.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    tileColors = hud->Colors;
    __asm {
        fld dword ptr right
    }
    *(uint*)&tileColor = *(uint*)&tileColors->HUDWhite;
    __asm {
        fsub dword ptr HudSinglePanelInnerOffset
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr innerRight
        fld dword ptr bottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr innerRight
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr innerLeft
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        134.0f, 457.0f, 138.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    tileColors = hud->Colors;
    __asm {
        fld dword ptr bottom
    }
    *(uint*)&tileColor = *(uint*)&tileColors->HUDWhite;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr tileY2
        fld dword ptr innerRight
        mov eax,hud
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr right
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        142.0f, 457.0f, 138.0f, 498.0f, 1.0f, tileMaterial, tileColor);
    AR6Rainbow* stanceCharacter = rainbow;
    tileColors = hud->Colors;
    uint stanceFlags = *(uint*)((byte*)stanceCharacter + 0x3e0);
    *(uint*)&tileColor = *(uint*)&tileColors->HUDWhite;
    float stanceU1, stanceU2;
    if ((stanceFlags & 0x20U) != 0) { // bIsCrouched takes priority.
        tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
        stanceU1 = 180.0f;
        stanceU2 = 217.0f;
    } else if ((stanceFlags & 0x300U) == 0) { // Neither m_bWantsToProne nor m_bIsProne.
        tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
        stanceU1 = 142.0f;
        stanceU2 = 179.0f;
    } else {
        tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
        stanceU1 = 217.0f;
        stanceU2 = 254.0f;
    }
    __asm {
        fld dword ptr y
        fadd dword ptr HudSingleStanceBottomOffset
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr x
        fadd dword ptr HudSingleStanceRightOffset
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fadd dword ptr NativeFloatFive
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fadd dword ptr NativeFloatFive
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        stanceU1, 464.0f, stanceU2, 494.0f, 1.0f, tileMaterial, tileColor);
    FCanvasUtil::Flush(panelCanvas);
    bool singlePlayer = (*(const byte*)((const byte*)hud + 0x524) & 2U) != 0;
    bool drawName = singlePlayer;
    if (!drawName) {
        AR6Rainbow* nameCharacter = rainbow;
        drawName = nameCharacter->m_TeamMemberRepInfo != nullptr;
    }
    if (drawName) {
        alignas(4) byte textColorStorage[16];
        FPlane* textColor = (FPlane*)textColorStorage;
        outlineColor = (FColor*)textColor; // Native reuses the outline word for the outgoing plane address.
        using ColorPlaneCall = FPlane* (__thiscall *)(const FColor*, FPlane*);
        (*(ColorPlaneCall*)R6GameImports::Engine_FColor_ConversionOperatorSlot)(&hud->m_HUDElements[0].Color, textColor);
        FString* name;
        if (singlePlayer) {
            AR6Rainbow* nameCharacter = rainbow;
            name = &nameCharacter->m_CharacterName;
        } else {
            AR6Rainbow* nameCharacter = rainbow;
            AR6TeamMemberReplicationInfo* replication = nameCharacter->m_TeamMemberRepInfo;
            name = &replication->m_CharacterName;
        }
        const ushort* nameText = FString::operator*(name);
        int textX, textY;
        __asm {
            fld dword ptr y
        }
        UCanvas* nameVtableCanvas = textCanvas;
        __asm {
            fadd dword ptr HudSinglePanelOuterOffset
        }
        byte* nameVtable = *(byte**)nameVtableCanvas;
        __asm {
            call ConvertX87ToSigned64
            mov textY,eax
            fld dword ptr x
            fadd dword ptr HudSingleNameOffsetX
            call ConvertX87ToSigned64
            mov textX,eax
        }
        UFont* nameFont = hud->m_FontRainbow6_14pt;
        UCanvas* nameCanvas = textCanvas;
        using DrawStringCall = int (__thiscall *)(UCanvas*, UFont*, int, int, const ushort*, FPlane, int, int, int);
        DrawStringCall nameDraw = *(DrawStringCall*)(nameVtable + 0x78);
        nameDraw(nameCanvas, nameFont, textX, textY, nameText, *textColor, 0, 0, 0);
        drawTile = *(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
    }
    AR6Rainbow* healthCharacter = rainbow;
    uint health = *(const byte*)((const byte*)healthCharacter + 0x3a2); // m_eHealth.
    if (health > 2)
        health = 2;
    tileColors = hud->Colors;
    *(uint*)&tileColor = *(uint*)&tileColors->HUDWhite;
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    int atlasV1 = (int)(health << 3);
    int& healthV1Word = *(int*)&textCanvas;
    healthV1Word = atlasV1;
    int& healthV2Word = *(int*)&rainbow;
    healthV2Word = atlasV1 + 8;
    float healthV1, healthV2;
    __asm {
        fild dword ptr healthV2Word
        fstp dword ptr healthV2
        fild dword ptr healthV1Word
        fstp dword ptr healthV1
        fld dword ptr y
        fadd dword ptr HudSingleHealthBottomOffset
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr x
        fadd dword ptr HudSingleHealthRightOffset
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX2
        fld dword ptr y
        fadd dword ptr HudSingleHealthTopOffset
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr x
        fadd dword ptr HudSingleHealthLeftOffset
        fmul dword ptr [eax+0x530]
        fstp dword ptr tileX1
    }
    drawTile(panelCanvas, tileX1, tileY1, tileX2, tileY2,
        500.0f, healthV1, 508.0f, healthV2, 1.0f, tileMaterial, tileColor);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000c30a : rethrow DrawCharacterInfo's caught four-byte value
__declspec(naked) void AR6HUD_DrawCharacterInfoCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x1c]
        push eax
        mov dword ptr [ebp-0x1c],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000c31e : report DrawCharacterInfo context and rethrow the active exception
__declspec(naked) void AR6HUD_DrawCharacterInfoCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawCharacterInfoExceptionContext // L"AR6HUD::DrawCharacterInfo"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000c340 : DisplayOtherTeamInfo
// Draws another team's panel, health slots and cached localized action description.
void __thiscall AR6HUD::DisplayOtherTeamInfo(AR6HUD* this, FCanvasUtil* canvas, UCanvas* textCanvas,
    int otherTeamIndex, AR6RainbowTeam* team, FColor* teamColor, int forceUpdate)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DisplayOtherTeamInfoExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    int teamIndex = otherTeamIndex;
    AR6HUD* hud = this;
    byte panelAlpha = hud->m_OtherTeamBoxColor.A;
    FColor* firstTeamColor = teamColor;
    firstTeamColor->A = panelAlpha;
    uint selectedOffset = teamIndex != 0 ? 40U : 0U;
    int& panelBottomWord = *(int*)&otherTeamIndex;
    float& panelBottom = *(float*)&otherTeamIndex; // Native reuses the index DWORD after retaining its integer value.
    panelBottomWord = (int)(600U - selectedOffset);
    __asm {
        fild dword ptr panelBottomWord
    }
    int selectedTop = (int)(559U - selectedOffset);
    __asm {
        fstp dword ptr panelBottom
    }
    uint verticalOffset = selectedOffset;
    FColor tileColor;
    *(uint*)&tileColor = *(uint*)firstTeamColor;
    UMaterial* tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    int panelTopWord = selectedTop;
    float& panelTop = *(float*)&panelTopWord;
    __asm {
        fild dword ptr panelTopWord
    }
    FCanvasUtil* panelCanvas = canvas;
    float tileX1, tileY1, tileX2, tileY2;
    __asm {
        fstp dword ptr panelTop
        fld dword ptr panelBottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
    }
    exceptionRegistration.state = 0;
    __asm {
        fstp dword ptr tileY2
        mov eax,hud
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelRight
        fstp dword ptr tileX2
        fld dword ptr panelTop
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelLeft
        fstp dword ptr tileX1
    }
    using DrawTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor);
    (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
        tileX1, tileY1, tileX2, tileY2, 134, 416, 138, 457, 1, tileMaterial, tileColor);
    FColor* secondTeamColor = teamColor;
    __asm {
        fld dword ptr panelBottom
    }
    *(uint*)&tileColor = *(uint*)secondTeamColor;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fstp dword ptr tileY2
        mov eax,hud
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelLeft
        fstp dword ptr tileX2
        fld dword ptr panelTop
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelOuterLeft
        fstp dword ptr tileX1
    }
    (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
        tileX1, tileY1, tileX2, tileY2, 128, 416, 134, 457, 1, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_OtherTeamOutlineColor;
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        fld dword ptr panelBottom
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelInnerRight
        fstp dword ptr tileX2
        fld dword ptr panelTop
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelLeft
        fstp dword ptr tileX1
    }
    (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
        tileX1, tileY1, tileX2, tileY2, 134, 457, 138, 498, 1, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_OtherTeamOutlineColor;
    __asm {
        fld dword ptr panelBottom
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelLeft
        fstp dword ptr tileX2
        fld dword ptr panelTop
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelOuterLeft
        fstp dword ptr tileX1
    }
    (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
        tileX1, tileY1, tileX2, tileY2, 128, 457, 134, 498, 1, tileMaterial, tileColor);
    *(uint*)&tileColor = *(uint*)&hud->m_OtherTeamOutlineColor;
    __asm {
        fld dword ptr panelBottom
    }
    tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
    __asm {
        mov eax,hud
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY2
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelRight
        fstp dword ptr tileX2
        fld dword ptr panelTop
        fmul dword ptr [eax+0x534]
        fstp dword ptr tileY1
        fld dword ptr [eax+0x530]
        fmul dword ptr HudOtherPanelInnerRight
        fstp dword ptr tileX1
    }
    (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
        tileX1, tileY1, tileX2, tileY2, 138, 457, 142, 498, 1, tileMaterial, tileColor);
    using WrappedPrintfCall = void (__cdecl *)(UCanvas*, UFont*, int, const ushort*, ...);
    uint nameOffset = verticalOffset;
    UCanvas* nameSetupCanvas = textCanvas;
    int& nameYWord = *(int*)&teamColor; // Native reuses the color-pointer word for name Y, then health index.
    nameYWord = (int)(561U - nameOffset);
    __asm {
        fild dword ptr nameYWord
    }
    nameSetupCanvas->CurX = 650.0f;
    __asm {
        mov eax,nameSetupCanvas
        fstp dword ptr [eax+0x54]
    }
    FColor nameColor;
    *(uint*)&nameColor = *(uint*)&hud->m_HUDElements[14].Color;
    *(uint*)&nameSetupCanvas->DrawColor = *(uint*)&nameColor;
    const ushort* teamName = FString::operator*(&hud->m_aszOtherTeamName[teamIndex]);
    UCanvas* nameCanvas = textCanvas;
    byte* nameVtable = *(byte**)nameCanvas;
    UFont* nameFont = hud->m_FontRainbow6_14pt;
    WrappedPrintfCall wrappedPrint = *(WrappedPrintfCall*)(nameVtable + 0x84);
    wrappedPrint(nameCanvas, nameFont, 1, teamName);
    AR6RainbowTeam* healthTeam = team;
    int memberCount = healthTeam->m_iMemberCount;
    int membersLost = healthTeam->m_iMembersLost;
    int& healthSlotCount = otherTeamIndex; // The incoming index word now holds the signed loop bound.
    healthSlotCount = (int)((uint)memberCount + (uint)membersLost);
    int selectedHealthStartX = (int)(729U - (uint)((uint)memberCount + (uint)membersLost) * 8U);
    int& healthStartX = *(int*)&canvas;
    healthStartX = selectedHealthStartX;
    int currentHealthIndex = 0;
    int& healthIndex = *(int*)&teamColor;
    healthIndex = currentHealthIndex;
    int healthX, healthScratch;
    while (currentHealthIndex < healthSlotCount) {
        int health = healthTeam->m_iTeamHealth[currentHealthIndex];
        int selectedHealthX = (int)((uint)currentHealthIndex * 16U + (uint)healthStartX);
        healthX = selectedHealthX;
        if (health > 2)
            health = 2;
        *(uint*)&tileColor = *(uint*)&hud->m_HUDElements[14].Color;
        tileMaterial = (UMaterial*)hud->m_pAlphaBlend;
        int atlasV1 = (int)((uint)health << 3);
        healthScratch = atlasV1;
        int& healthV2Word = panelTopWord;
        healthV2Word = (int)((uint)atlasV1 + 8U);
        float healthV1, healthV2;
        __asm {
            fild dword ptr healthV2Word
        }
        int selectedHealthRight = (int)((uint)selectedHealthX + 8U);
        __asm {
            fstp dword ptr healthV2
            fild dword ptr healthScratch
        }
        uint iconVerticalOffset = verticalOffset;
        int selectedHealthBottom = (int)(583U - iconVerticalOffset);
        __asm {
            fstp dword ptr healthV1
        }
        healthScratch = selectedHealthBottom;
        __asm {
            fild dword ptr healthScratch
        }
        healthScratch = selectedHealthRight;
        __asm {
            mov eax,hud
            fmul dword ptr [eax+0x534]
        }
        int selectedHealthTop = (int)(575U - iconVerticalOffset);
        __asm {
            fstp dword ptr tileY2
            fild dword ptr healthScratch
        }
        healthScratch = selectedHealthTop;
        __asm {
            mov eax,hud
            fmul dword ptr [eax+0x530]
            fstp dword ptr tileX2
            fild dword ptr healthScratch
            fmul dword ptr [eax+0x534]
            fstp dword ptr tileY1
            fild dword ptr healthX
            fmul dword ptr [eax+0x530]
            fstp dword ptr tileX1
        }
        (*(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(panelCanvas,
            tileX1, tileY1, tileX2, tileY2, 500, healthV1, 508, healthV2, 1, tileMaterial, tileColor);
        int nextHealthIndex = healthIndex;
        healthTeam = team;
        currentHealthIndex = (int)((uint)nextHealthIndex + 1U);
        healthIndex = currentHealthIndex;
    }
    AR6RainbowTeam* stateTeam = healthTeam;
    bool refreshAction = forceUpdate != 0;
    if (!refreshAction) {
        byte cachedState = hud->m_eLastOtherTeamState[teamIndex];
        byte currentState = stateTeam->m_eTeamState;
        if (cachedState != currentState) {
            stateTeam = team;
            refreshAction = true;
        }
    }
    if (refreshAction) {
        byte state = stateTeam->m_eTeamState;
        hud->m_eLastOtherTeamState[teamIndex] = state;
        const ushort* normalGoCodeKeys[4] = {
            OtherTeamGoCodeAlpha, OtherTeamGoCodeBravo,
            OtherTeamGoCodeCharlie, OtherTeamGoCodeZulu
        };
        using LocalizeCall = const ushort* (__cdecl*)(const ushort*, const ushort*, const ushort*,
            const ushort*, int, int);
        if (state == 1) {
            LocalizeCall localize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
            const ushort* waitText = localize(OtherTeamLocalizeSection, OtherTeamActionWait,
                OtherTeamLocalizePackage, nullptr, 0, 0);
            FString* initialAction = &hud->m_szOtherTeamState[teamIndex];
            FString*& actionText = *(FString**)&teamColor; // Native retains this pointer in the incoming color word.
            actionText = initialAction;
            FStringNoInit::operator=((FStringNoInit*)initialAction, waitText);
            AR6RainbowTeam* goTeam = team;
            if (goTeam->m_eGoCode != 4)
                FString::operator+=(actionText, OtherTeamActionSeparator);
            goTeam = team;
            byte goCode = goTeam->m_eGoCode;
            if (goCode <= 3) {
                const ushort* codeText = localize(OtherTeamLocalizeSection, normalGoCodeKeys[goCode],
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                FString::operator+=(actionText, codeText);
            }
        } else if (state == 7) {
            LocalizeCall localize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
            const ushort* snipingText = localize(OtherTeamLocalizeSection, OtherTeamActionSniping,
                OtherTeamLocalizePackage, nullptr, 0, 0);
            FString* initialAction = &hud->m_szOtherTeamState[teamIndex];
            FString*& actionText = *(FString**)&teamColor;
            actionText = initialAction;
            FStringNoInit::operator=((FStringNoInit*)initialAction, snipingText);
            FString::operator+=(actionText, OtherTeamActionSeparator);
            AR6RainbowTeam* sniperTeam = team;
            bool sniperHold = (*(const uint*)((const byte*)sniperTeam + 0x3e8) & 0x80000U) != 0;
            byte goCode = sniperTeam->m_eGoCode;
            if (sniperHold) {
                const ushort* shortGoCodeKeys[4] = {
                    OtherTeamGoCodeA, OtherTeamGoCodeB,
                    OtherTeamGoCodeC, OtherTeamGoCodeZ
                };
                if (goCode <= 3) {
                    const ushort* codeText = localize(OtherTeamLocalizeSection, shortGoCodeKeys[goCode],
                        OtherTeamLocalizePackage, nullptr, 0, 0);
                    FString::operator+=(actionText, codeText);
                }
                FString::operator+=(actionText, OtherTeamActionSeparator);
                const ushort* holdText = localize(OtherTeamLocalizeSection, OtherTeamSnipeHold,
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                FString::operator+=(actionText, holdText);
            } else if (goCode <= 3) {
                const ushort* codeText = localize(OtherTeamLocalizeSection, normalGoCodeKeys[goCode],
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                FString::operator+=(actionText, codeText);
            }
        } else if (state >= 2 && state <= 20) {
            const ushort* actionKeys[20] = {
                OtherTeamActionWait,
                OtherTeamActionHold,
                OtherTeamActionMove,
                OtherTeamActionFollow,
                OtherTeamActionRegroup,
                OtherTeamActionEngage,
                OtherTeamActionSniping,
                OtherTeamActionLockPick,
                OtherTeamActionOpenDoor,
                OtherTeamActionCloseDoor,
                OtherTeamActionOpen,
                OtherTeamActionClose,
                OtherTeamActionClear,
                OtherTeamActionGrenade,
                OtherTeamActionBomb,
                OtherTeamActionDevice,
                OtherTeamActionArrest,
                OtherTeamActionLadder,
                OtherTeamActionOrders,
                OtherTeamActionBreach,
            };
            const ushort* localizedAction = Localize(OtherTeamLocalizeSection, actionKeys[state - 1],
                OtherTeamLocalizePackage, nullptr, 0, 0);
            FString* actionText = &hud->m_szOtherTeamState[teamIndex];
            FStringNoInit::operator=((FStringNoInit*)actionText, localizedAction);
        } else if (state == 21) {
            FString* actionText = &hud->m_szOtherTeamState[teamIndex];
            FStringNoInit::operator=((FStringNoInit*)actionText, OtherTeamState21Text);
        }
    }
    uint actionOffset = verticalOffset;
    UCanvas* actionCanvas = textCanvas;
    int& actionYWord = *(int*)&team; // Native reuses the incoming team pointer after action selection.
    actionYWord = (int)(584U - actionOffset);
    __asm {
        fild dword ptr actionYWord
    }
    actionCanvas->CurX = 650.0f;
    __asm {
        mov eax,actionCanvas
        fstp dword ptr [eax+0x54]
    }
    FColor actionColor;
    *(uint*)&actionColor = *(uint*)&hud->m_HUDElements[14].Color;
    *(uint*)&actionCanvas->DrawColor = *(uint*)&actionColor;
    const ushort* stateText = FString::operator*(&hud->m_szOtherTeamState[teamIndex]);
    UFont* actionFont = hud->m_FontRainbow6_14pt;
    byte* actionVtable = *(byte**)actionCanvas;
    WrappedPrintfCall actionPrint = *(WrappedPrintfCall*)(actionVtable + 0x84);
    actionPrint(actionCanvas, actionFont, 1, stateText);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000cbcf : rethrow the other-team panel's bound four-byte value
// Uses inherited EBP to copy the typed binding at -0x28 into a separate slot at -0x24.
__declspec(naked) void AR6HUD_DisplayOtherTeamInfoCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x28]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x24]
        push ecx
        mov dword ptr [ebp-0x24],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000cbe3 : report the other-team panel context and rethrow the active exception
__declspec(naked) void AR6HUD_DisplayOtherTeamInfoCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DisplayOtherTeamInfoExceptionContext // L"AR6HUD::DisplayOtherTeamInfo"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000ceb0 : execDrawNativeHUD
// Draws native character, team, weapon and waypoint information for the current Rainbow view target.
void __thiscall AR6HUD::execDrawNativeHUD(AR6HUD* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    using ClipCall = void (__thiscall *)(UCanvas*, int, int, int, int);
    using DrawTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor);
    using RotatedTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor, float);
    using ColorPlaneCall = FPlane* (__thiscall *)(const FColor*, FPlane*);
    using DrawStringCall = int (__thiscall *)(UCanvas*, UFont*, int, int, const ushort*, FPlane, int, int, int);
    using TextCall = void (__cdecl *)(UCanvas*, UFont*, int, const ushort*, ...);
    using MeasureCall = void (__cdecl *)(UCanvas*, UFont*, int*, int*, const ushort*, ...);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DrawNativeHUDExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native cleanup regions: canvas -0x1014, camera -0x36c, line batcher -0x10c and reused 12-byte strings.
    FFrame* hudStack = stack;
    byte** codeCursor = (byte**)((byte*)hudStack + 0xc);
    byte* canvasCode = *codeCursor;
    UCanvas* C = nullptr;
    byte canvasOpcode = *canvasCode;
    *codeCursor = canvasCode + 1;
    ScriptNative* canvasNativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* canvasContext = *(UObject**)((byte*)hudStack + 8);
    exceptionRegistration.state = 0;
    canvasNativeTable[canvasOpcode](canvasContext, hudStack, &C);
    byte* nextCode = *codeCursor + 1;
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)hudStack + 8);
        *codeCursor = nextCode + 1;
        ScriptNative* debugNativeTable = (ScriptNative*)ImportedGNativesAddress;
        debugNativeTable[0x42](debugContext, hudStack, nullptr);
    }
    APlayerController* initialOwner = this->PlayerOwner;
    if (initialOwner == nullptr)
        goto finished;
    AR6Rainbow* candidateRainbow = (AR6Rainbow*)initialOwner->ViewTarget;
    if (candidateRainbow != nullptr) {
        UClass* cursor = *(UClass**)((byte*)candidateRainbow + 0x24);
        UClass* rainbowClass = *(UClass**)R6GameImports::R6Engine_AR6Rainbow_PrivateStaticClassSlot;
        while (cursor != nullptr && cursor != rainbowClass)
            cursor = *(UClass**)((byte*)cursor + 0x2c);
        if (cursor != rainbowClass)
            candidateRainbow = nullptr;
    }
    ALevelInfo* planningLevel = this->Level;
    uint planningFlags = *(uint*)((byte*)planningLevel + 0x450);
    AR6PlayerController* cachedPlayerController = (AR6PlayerController*)this->PlayerOwner;
    AR6Rainbow* viewedRainbow = candidateRainbow;
    stack = (FFrame*)cachedPlayerController; // Native reuses the incoming frame word for its cached owner.
    bool planningActive = (planningFlags & 0x1000U) != 0;
    if (planningActive || this->m_iCycleHUDLayer == 3 || cachedPlayerController == nullptr ||
        viewedRainbow == nullptr || viewedRainbow->m_ePawnType != 1)
        goto finished;
    AR6RainbowTeam* newTeam = cachedPlayerController->m_TeamManager;
    uint changedTeam = this->m_pLastRainbowTeam != newTeam;
    this->m_pLastRainbowTeam = newTeam;
    uint forceRefresh = changedTeam;
    if (newTeam != nullptr) {
        uint teamFlags = *(uint*)((byte*)newTeam + 0x3e8);
        uint* hudFlags = (uint*)((byte*)this + 0x524);
        uint oldFlags = *hudFlags;
        forceRefresh |= ((teamFlags >> 2) ^ oldFlags) >> 17 & 1U;
        *hudFlags = oldFlags ^ (((teamFlags >> 2) ^ oldFlags) & 0x20000U);
    }
    UCanvas* scaleCanvas = C;
    // Initialize both scales before signed size reads, retaining one canvas through the raw SetClip packet.
    __asm {
        mov ecx,scaleCanvas
        mov edx,this
        mov dword ptr [edx+0x530],0x3f800000
        mov dword ptr [edx+0x534],0x3f800000
        fild dword ptr [ecx+0x6c]
        push 600
        push 800
        fmul dword ptr HudCanvasInverseReferenceWidth
        push 0
        push 0
        fstp dword ptr [edx+0x530]
        fild dword ptr [ecx+0x70]
        fmul dword ptr HudCanvasInverseReferenceHeight
        fstp dword ptr [edx+0x534]
        mov eax,dword ptr [ecx]
        call dword ptr [eax+0x88]
    }
    uint stretchYWord = *(uint*)&this->m_fScaleY;
    uint stretchXWord = *(uint*)&this->m_fScaleX;
    uint stretchSlotAddress = R6GameImports::Engine_UCanvas_SetStretchSlot;
    __asm {
        mov eax,stretchYWord
        push eax
        mov ecx,C
        mov edx,stretchXWord
        push edx
        mov eax,stretchSlotAddress
        call dword ptr [eax]
    }
    byte* whiteColors = (byte*)this->Colors;
    uint whiteColorWord = *(uint*)(whiteColors + 0x84);
    UCanvas* whiteCanvas = C;
    *(uint*)&whiteCanvas->DrawColor = whiteColorWord;
    AR6RainbowTeam* capturedTeam = this->m_pLastRainbowTeam;
    UR6AbstractPlanningInfo* capturedPlanning = nullptr;
    int memberSlots = 0;
    if (capturedTeam != nullptr) {
        UR6AbstractPlanningInfo* teamPlanning = capturedTeam->m_TeamPlanning;
        uint membersLost = (uint)capturedTeam->m_iMembersLost;
        capturedPlanning = teamPlanning;
        memberSlots = (int)(membersLost + (uint)capturedTeam->m_iMemberCount);
    }
    FColor teamColor;
    uint hudColorFlags = *(uint*)((byte*)this + 0x524);
    if ((hudColorFlags & 8U) != 0) {
        APlayerReplicationInfo* replication = viewedRainbow->PlayerReplicationInfo;
        if (replication == nullptr)
            goto finished;
        uint teamId = *(uint*)((byte*)replication + 0x3a0);
        byte* colors = (byte*)this->Colors;
        *(uint*)&teamColor = *(uint*)(colors + (teamId == 2 ? 0x7c : 0x78));
    } else if ((hudColorFlags & 2U) != 0) {
        uint teamName = (uint)capturedTeam->m_iRainbowTeamName;
        byte* colors = (byte*)this->Colors;
        *(uint*)&teamColor = *(uint*)(colors + 0x78U + teamName * 4U);
    } else {
        UR6GameOptions** optionStorage = (UR6GameOptions**)ImportedGGameOptionsAddress;
        UR6GameOptions* options = *optionStorage;
        *(uint*)&teamColor = *(uint*)&options->HUDMPColor;
    }
    UpdateHUDColors(this, teamColor);
    UCanvas* constructorCanvas = C;
    UViewport* constructorViewport = constructorCanvas->Viewport;
    FRenderInterface* constructorRenderInterface = *(FRenderInterface**)((byte*)constructorViewport + 0x164);
    FRenderInterface* initialRenderInterface;
    UViewport* initialViewport;
    alignas(4) byte canvasStorage[0xca8];
    FCanvasUtil* canvas = (FCanvasUtil*)canvasStorage;
    uint canvasConstructorSlotAddress = R6GameImports::Engine_FCanvasUtil_ConstructorSlot;
    __asm {
        mov eax,constructorViewport
        mov edx,constructorRenderInterface
        push 1
        push 0
        push edx
        mov initialRenderInterface,edx
        push eax
        lea ecx,canvasStorage
        mov initialViewport,eax
        mov edx,canvasConstructorSlotAddress
        call dword ptr [edx]
    }
    APlayerController* spectatorOwner = this->PlayerOwner;
    uint spectatorFlags = *(uint*)((byte*)spectatorOwner + 0x524);
    *(byte*)&exceptionRegistration.state = 2;
    bool drawCharacterGroup = (spectatorFlags & 0x4000U) != 0;
    if (drawCharacterGroup) {
        uint panelFlags = *(uint*)((byte*)this + 0x524);
        bool showTeam = (panelFlags & 0x20U) != 0;
        if (!showTeam) {
            AR6PlayerController* panelController = (AR6PlayerController*)stack;
            showTeam = (*(byte*)((byte*)panelController + 0x83c) & 0x20U) != 0;
        }
        if (showTeam) {
            AR6RainbowTeam* panelTeam = this->m_pLastRainbowTeam;
            drawCharacterGroup = panelTeam != nullptr && (panelFlags & 2U) != 0;
        } else {
            drawCharacterGroup = false;
        }
    }
    if (drawCharacterGroup) {
        float memberX = 0.0f;
        for (int memberIndex = 0; memberIndex < memberSlots;) {
            AR6Rainbow* member = this->m_pLastRainbowTeam->m_Team[memberIndex];
            if (member != nullptr) {
                FColor* rowColor = viewedRainbow == member ? &teamColor : &this->Colors->HUDGrey;
                // Pass the saved X word directly after the canvas/color words, without a float conversion.
                __asm {
                    mov eax,C
                    push eax
                    lea edx,canvasStorage
                    push edx
                    mov eax,rowColor
                    push eax
                    mov eax,dword ptr memberX
                    push 0
                    push eax
                    mov edx,member
                    push edx
                    mov ecx,this
                    call DrawCharacterInfo
                }
            }
            __asm { fld dword ptr memberX }
            memberIndex = (int)((uint)memberIndex + 1U);
            __asm {
                fadd dword ptr HudRadarAboveLevelThreshold
                fstp dword ptr memberX
            }
        }
    } else {
        bool showCharacter = (*(byte*)((byte*)this + 0x524) & 0x10U) != 0;
        if (!showCharacter) {
            AR6PlayerController* panelController = (AR6PlayerController*)stack;
            showCharacter = (*(byte*)((byte*)panelController + 0x83c) & 0x20U) != 0;
        }
        if (showCharacter) {
            __asm {
                mov edx,C
                push edx
                mov edx,viewedRainbow
                lea eax,canvasStorage
                push eax
                lea ecx,teamColor
                push ecx
                push 0
                push 0
                push edx
                mov ecx,this
                call DrawSingleCharacterInfo
            }
        }
    }
    AR6PlayerController* postPanelController = (AR6PlayerController*)stack;
    uint postPanelFlags = *(uint*)((byte*)postPanelController + 0x524);
    exceptionRegistration.state = 1;
    if ((postPanelFlags & 0x4000U) == 0) {
        using LocalizeCall = const ushort* (__cdecl *)(const ushort*, const ushort*, const ushort*,
            const ushort*, int, int);
        LocalizeCall teamLocalize;
        bool showMovement = (*(byte*)((byte*)this + 0x524) & 0x10U) != 0;
        if (!showMovement)
            showMovement = (*(byte*)((byte*)postPanelController + 0x83c) & 0x20U) != 0;
        AR6RainbowTeam* movementTeam;
        if (showMovement && memberSlots > 1 && (movementTeam = this->m_pLastRainbowTeam) != nullptr) {
            byte movementMode = *(byte*)((byte*)movementTeam + 0x399);
            byte cachedMovementMode = *(byte*)((byte*)this + 0x50c);
            *(byte*)&exceptionRegistration.state = 5;
            const ushort* movementKey = nullptr;
            if (cachedMovementMode != movementMode) {
                *(byte*)((byte*)this + 0x50c) = movementMode;
                movementKey = movementMode == 0 ? HudMovementAssaultKey :
                    movementMode == 1 ? HudMovementInfiltrateKey : movementMode == 2 ? HudMovementReconKey : nullptr;
            }
            if (movementKey != nullptr) {
                uint movementLocalizeSlotAddress = R6GameImports::Core_LocalizeSlot;
                uint movementAssignSlotAddress = R6GameImports::Core_FStringNoInit_AssignTextSlot;
                const ushort* movementPackage = OtherTeamLocalizePackage;
                const ushort* movementSection = OtherTeamLocalizeSection;
                FStringNoInit* movementString = (FStringNoInit*)&this->m_szMovementMode;
                // Capture Localize between the key and section pushes, retaining it after assignment.
                __asm {
                    push 0
                    push 0
                    push 0
                    mov eax,movementPackage
                    push eax
                    mov eax,movementKey
                    push eax
                    mov eax,movementLocalizeSlotAddress
                    mov esi,dword ptr [eax]
                    mov teamLocalize,esi
                    mov eax,movementSection
                    push eax
                    call esi
                    add esp,0x18
                    push eax
                    mov ecx,movementString
                    mov edx,movementAssignSlotAddress
                    call dword ptr [edx]
                }
            } else {
                teamLocalize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
            }
            uint movementPlaneAddress;
            int* movementUnwindState = &exceptionRegistration.state;
            uint movementColorSlotAddress = R6GameImports::Engine_FColor_ConversionOperatorSlot;
            uint movementDataSlotAddress = R6GameImports::Core_FString_OperatorMultiplySlot;
            // The color conversion writes directly into the outgoing DrawString plane, not a separate local copy.
            __asm {
                mov eax,C
                push 0
                push 0
                push 0
                sub esp,0x10
                mov ecx,esp
                mov movementPlaneAddress,esp
                push ecx
                mov ebx,this
                lea ecx,[ebx+0x668]
                mov edx,movementUnwindState
                mov dword ptr [edx],4
                mov byte ptr [eax+0x5c],5
                mov edx,movementColorSlotAddress
                call dword ptr [edx]
                lea ecx,[ebx+0x6a8]
                mov edx,movementDataSlotAddress
                call dword ptr [edx]
                mov ecx,C
                mov edx,dword ptr [ecx]
                push eax
                mov eax,dword ptr [ebx+0x3ec]
                push 21
                push 49
                push eax
                call dword ptr [edx+0x78]
            }
        } else {
            teamLocalize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
        }
        byte teamPanelFlags = *(byte*)((byte*)this + 0x524);
        *(byte*)&exceptionRegistration.state = 7;
        bool showTeamPanel = (teamPanelFlags & 0x20U) != 0;
        if (!showTeamPanel) {
            AR6PlayerController* teamPanelController = (AR6PlayerController*)stack;
            showTeamPanel = (*(byte*)((byte*)teamPanelController + 0x83c) & 0x20U) != 0;
        }
        int* savedMemberCount = &memberSlots; // Native reloads the count spill after ESI becomes the Localize target.
        if (showTeamPanel && *savedMemberCount > 1 && this->m_pLastRainbowTeam != nullptr) {
            uint teamTileSlotAddress = R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
            // Retain one DrawTile target; each packet refreshes its color/material/scales in native order.
            __asm {
                mov ebx,this
                mov edx,dword ptr [ebx+0x5d0]
                fld dword ptr [ebx+0x534]
                mov eax,dword ptr [ebx+0x57c]
                fmul dword ptr HudRadarZero
                push edx
                push eax
                push 0x3f800000
                push 0x43e48000
                mov eax,teamTileSlotAddress
                mov edi,dword ptr [eax]
                push 0x430a0000
                push 0x43d00000
                push 0x43060000
                sub esp,0x10
                fstp dword ptr [esp+0xc]
                lea ecx,canvasStorage
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelRight
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudSinglePanelHeight
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelLeft
                fstp dword ptr [esp]
                call edi
                mov ecx,dword ptr [ebx+0x5d0]
                fld dword ptr [ebx+0x534]
                mov edx,dword ptr [ebx+0x57c]
                fmul dword ptr HudRadarZero
                push ecx
                push edx
                push 0x3f800000
                push 0x43e48000
                push 0x43060000
                push 0x43d00000
                push 0x43000000
                sub esp,0x10
                fstp dword ptr [esp+0xc]
                lea ecx,canvasStorage
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelLeft
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudSinglePanelHeight
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelOuterLeft
                fstp dword ptr [esp]
                call edi
                mov eax,dword ptr [ebx+0x5d4]
                fld dword ptr [ebx+0x534]
                mov ecx,dword ptr [ebx+0x57c]
                fmul dword ptr HudRadarZero
                push eax
                push ecx
                push 0x3f800000
                push 0x43f90000
                push 0x430a0000
                push 0x43e48000
                push 0x43060000
                sub esp,0x10
                fstp dword ptr [esp+0xc]
                lea ecx,canvasStorage
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelInnerRight
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudSinglePanelHeight
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelLeft
                fstp dword ptr [esp]
                call edi
                mov edx,dword ptr [ebx+0x5d4]
                mov eax,dword ptr [ebx+0x57c]
                push edx
                push eax
                push 0x3f800000
                push 0x43f90000
                push 0x43060000
                push 0x43e48000
                fld dword ptr [ebx+0x534]
                push 0x43000000
                fmul dword ptr HudRadarZero
                sub esp,0x10
                lea ecx,canvasStorage
                fstp dword ptr [esp+0xc]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelLeft
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudSinglePanelHeight
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelOuterLeft
                fstp dword ptr [esp]
                call edi
                mov ecx,dword ptr [ebx+0x5d4]
                fld dword ptr [ebx+0x534]
                mov edx,dword ptr [ebx+0x57c]
                fmul dword ptr HudRadarZero
                push ecx
                push edx
                push 0x3f800000
                push 0x43f90000
                push 0x430e0000
                push 0x43e48000
                push 0x430a0000
                sub esp,0x10
                fstp dword ptr [esp+0xc]
                lea ecx,canvasStorage
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelRight
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudSinglePanelHeight
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudOtherPanelInnerRight
                fstp dword ptr [esp]
                call edi
            }
            uint healthMemberCount = (uint)*savedMemberCount;
            ALevelInfo* healthLevel = this->Level;
            int healthStartX = (int)(737U - healthMemberCount * 8U);
            int& healthLeftWord = *(int*)&teamColor; // Native reuses frame -0x54 for the unscaled left edge.
            int healthV1Word, healthPacketScratch; // Frame -0x58 and -0x20 have new integer roles.
            uint healthTileSlotAddress = R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
            // Builds the native health packet with signed integer loads and scratch-word reuse.
            auto drawTeamHealth = [&](int leftEdge, byte health) {
                uint cappedHealth = health > 2 ? 2U : (uint)health;
                __asm {
                    mov eax,cappedHealth
                    mov ecx,leftEdge
                    mov ebx,this
                    mov edx,dword ptr [ebx+0x650]
                    push edx
                    mov edx,dword ptr [ebx+0x57c]
                    shl eax,0x3
                    push edx
                    mov healthV1Word,eax
                    push 0x3f800000
                    push ecx
                    add eax,0x8
                    mov healthPacketScratch,eax
                    fild dword ptr healthPacketScratch
                    fstp dword ptr [esp]
                    push 0x43fe0000
                    fild dword ptr healthV1Word
                    push ecx
                    add ecx,0x8
                    mov healthPacketScratch,ecx
                    fstp dword ptr [esp]
                    push 0x43fa0000
                    fld dword ptr [ebx+0x534]
                    sub esp,0x10
                    fmul dword ptr HudSingleHealthBottomOffset
                    lea ecx,canvasStorage
                    fstp dword ptr [esp+0xc]
                    fild dword ptr healthPacketScratch
                    fmul dword ptr [ebx+0x530]
                    fstp dword ptr [esp+0x8]
                    fld dword ptr [ebx+0x534]
                    fmul dword ptr HudSingleHealthTopOffset
                    fstp dword ptr [esp+0x4]
                    fild dword ptr healthLeftWord
                    fmul dword ptr [ebx+0x530]
                    fstp dword ptr [esp]
                    mov eax,healthTileSlotAddress
                    call dword ptr [eax]
                }
            };
            byte teamHealthNetMode = *(byte*)((byte*)healthLevel + 0x425);
            *(byte*)&exceptionRegistration.state = 8;
            if (teamHealthNetMode == 0) {
                for (int memberIndex = 0; memberIndex < *savedMemberCount;
                    memberIndex = (int)((uint)memberIndex + 1U)) {
                    if (memberIndex == 0)
                        continue;
                    int capturedHealthStartX = healthStartX;
                    AR6RainbowTeam* healthTeam = this->m_pLastRainbowTeam;
                    int leftEdge = (int)((uint)capturedHealthStartX + (uint)memberIndex * 16U - 16U);
                    AR6Rainbow* member = healthTeam->m_Team[memberIndex];
                    healthLeftWord = leftEdge;
                    if (member != nullptr) {
                        byte health = *(byte*)((byte*)member + 0x3a2);
                        drawTeamHealth(leftEdge, health);
                    }
                }
            } else {
                AR6Rainbow* healthViewed = viewedRainbow;
                if (healthViewed != nullptr && healthViewed->m_TeamMemberRepInfo != nullptr) {
                    ULevel* initialActorLevel = this->XLevel;
                    int actorIndex = *(int*)((byte*)initialActorLevel + 0x104);
                    for (;; actorIndex = (int)((uint)*savedMemberCount + 1U)) {
                        ULevel* actorLevel = this->XLevel;
                        int actorCount = *(int*)((byte*)actorLevel + 0x34);
                        *savedMemberCount = actorIndex; // Native reuses the count spill before the signed end test.
                        if (actorIndex >= actorCount)
                            break;
                        AActor** actorData = *(AActor***)((byte*)actorLevel + 0x30);
                        AR6TeamMemberReplicationInfo* member =
                            (AR6TeamMemberReplicationInfo*)CastToAR6TeamMemberReplicationInfo((int)actorData[actorIndex]);
                        if (member == nullptr)
                            continue;
                        byte teamPosition = *(byte*)((byte*)member + 0x396);
                        if (teamPosition == 0)
                            continue;
                        int memberTeamId = *(int*)((byte*)member + 0x3a0);
                        if (memberTeamId == -1)
                            continue;
                        AR6Rainbow* currentViewed = viewedRainbow;
                        AR6TeamMemberReplicationInfo* localMember = currentViewed->m_TeamMemberRepInfo;
                        int localTeamId = *(int*)((byte*)localMember + 0x3a0);
                        if (memberTeamId == localTeamId) {
                            byte health = *(byte*)((byte*)member + 0x397);
                            int capturedHealthStartX = healthStartX;
                            int leftEdge = (int)((uint)capturedHealthStartX + (uint)teamPosition * 16U - 16U);
                            healthLeftWord = leftEdge;
                            drawTeamHealth(leftEdge, health);
                        }
                    }
                }
            }
            uint actionRefresh = forceRefresh;
            exceptionRegistration.state = 7;
            *(byte*)&exceptionRegistration.state = 10;
            bool teamStateChanged = actionRefresh != 0;
            if (!teamStateChanged) {
                AR6RainbowTeam* comparisonTeam = this->m_pLastRainbowTeam;
                byte cachedTeamState = *(byte*)((byte*)this + 0x50d);
                byte comparedTeamState = *(byte*)((byte*)comparisonTeam + 0x39e);
                teamStateChanged = cachedTeamState != comparedTeamState;
            }
            if (teamStateChanged) {
                AR6RainbowTeam* actionTeam = this->m_pLastRainbowTeam;
                byte teamState = *(byte*)((byte*)actionTeam + 0x39e);
                *(byte*)((byte*)this + 0x50d) = teamState;
                uint actionDispatchIndex = (uint)teamState - 1U;
                // Descriptive key lookup; native dispatch is through the compiler code-target table.
                static const ushort* actionKeys[20] = {
                    OtherTeamActionWait, OtherTeamActionHold, OtherTeamActionMove, OtherTeamActionFollow,
                    OtherTeamActionRegroup, OtherTeamActionEngage, OtherTeamActionSniping, OtherTeamActionLockPick,
                    OtherTeamActionOpenDoor, OtherTeamActionCloseDoor, OtherTeamActionOpen, OtherTeamActionClose,
                    OtherTeamActionClear, OtherTeamActionGrenade, OtherTeamActionBomb, OtherTeamActionDevice,
                    OtherTeamActionArrest, OtherTeamActionLadder, OtherTeamActionOrders, OtherTeamActionBreach
                };
                static const ushort* fullGoCodes[4] = {
                    OtherTeamGoCodeAlpha, OtherTeamGoCodeBravo, OtherTeamGoCodeCharlie, OtherTeamGoCodeZulu
                };
                static const ushort* shortGoCodes[4] = {
                    OtherTeamGoCodeA, OtherTeamGoCodeB, OtherTeamGoCodeC, OtherTeamGoCodeZ
                };
                // Pass the retained Localize target a raw six-word packet and keep its pointer result unchanged.
                auto localizeTeamAction = [&](const ushort* key) {
                    const ushort* section = OtherTeamLocalizeSection;
                    const ushort* package = OtherTeamLocalizePackage;
                    const ushort* localized;
                    __asm {
                        push 0
                        push 0
                        push 0
                        mov eax,package
                        push eax
                        mov eax,key
                        push eax
                        mov eax,section
                        push eax
                        mov esi,teamLocalize
                        call esi
                        add esp,0x18
                        mov localized,eax
                    }
                    return localized;
                };
                // Assign through the live import after pushing the returned text word.
                auto assignTeamAction = [&](const ushort* text) {
                    FStringNoInit* actionString = (FStringNoInit*)&this->m_szTeamState;
                    uint assignSlotAddress = R6GameImports::Core_FStringNoInit_AssignTextSlot;
                    __asm {
                        mov eax,text
                        push eax
                        mov ecx,actionString
                        mov edx,assignSlotAddress
                        call dword ptr [edx]
                    }
                };
                // Append through the live import; the member string remains owned by the HUD.
                auto appendTeamAction = [&](const ushort* text) {
                    FString* actionString = (FString*)&this->m_szTeamState;
                    uint appendSlotAddress = R6GameImports::Core_FString_OperatorAppendAssignTextSlot;
                    __asm {
                        mov eax,text
                        push eax
                        mov ecx,actionString
                        mov edx,appendSlotAddress
                        call dword ptr [edx]
                    }
                };
                if (actionDispatchIndex < 20U) {
                    const ushort* localized = localizeTeamAction(actionKeys[actionDispatchIndex]);
                    assignTeamAction(localized);
                    if (teamState == 1) {
                        AR6RainbowTeam* separatorTeam = this->m_pLastRainbowTeam;
                        byte separatorGoCode = *(byte*)((byte*)separatorTeam + 0x3a0);
                        if (separatorGoCode != 4)
                            appendTeamAction(OtherTeamActionSeparator);
                        AR6RainbowTeam* goCodeTeam = this->m_pLastRainbowTeam;
                        byte goCode = *(byte*)((byte*)goCodeTeam + 0x3a0);
                        if (goCode <= 3) {
                            localized = localizeTeamAction(fullGoCodes[goCode]);
                            appendTeamAction(localized);
                        }
                    } else if (teamState == 7) {
                        appendTeamAction(OtherTeamActionSeparator);
                        AR6RainbowTeam* sniperTeam = this->m_pLastRainbowTeam;
                        uint sniperFlags = *(uint*)((byte*)sniperTeam + 0x3e8);
                        byte goCode = *(byte*)((byte*)sniperTeam + 0x3a0);
                        bool sniperHold = (sniperFlags & 0x80000U) != 0;
                        if (sniperHold) {
                            if (goCode <= 3) {
                                localized = localizeTeamAction(shortGoCodes[goCode]);
                                appendTeamAction(localized);
                            }
                            appendTeamAction(OtherTeamActionSeparator);
                            localized = localizeTeamAction(OtherTeamSnipeHold);
                            appendTeamAction(localized);
                        } else if (goCode <= 3) {
                            localized = localizeTeamAction(fullGoCodes[goCode]);
                            appendTeamAction(localized);
                        }
                    }
                } else if (actionDispatchIndex == 20U) {
                    assignTeamAction(OtherTeamState21Text);
                }
            }
            exceptionRegistration.state = 7;
            FCanvasUtil::Flush(canvas);
            UCanvas* teamCurXCanvas = C;
            *(uint*)&teamCurXCanvas->CurX = 0x44228000;
            UCanvas* teamCurYCanvas = C;
            *(uint*)&teamCurYCanvas->CurY = 0x41a80000;
            uint teamTextColor = *(uint*)&this->m_HUDElements[9].Color;
            UCanvas* teamColorCanvas = C;
            *(uint*)&teamColorCanvas->DrawColor = teamTextColor;
            const ushort* stateText = FString::operator*((FString*)&this->m_szTeamState);
            UCanvas* teamTextCanvas = C;
            byte* teamTextVtable = *(byte**)teamTextCanvas;
            // WrappedPrintf is cdecl: canvas is a stack argument, and the caller removes all four words.
            __asm {
                mov eax,stateText
                push eax
                mov ebx,this
                mov eax,dword ptr [ebx+0x3ec]
                push 1
                push eax
                mov ecx,teamTextCanvas
                push ecx
                mov edx,teamTextVtable
                call dword ptr [edx+0x84]
                add esp,0x10
            }
        }
    }
    byte weaponPanelFlags = *(byte*)((byte*)this + 0x524);
    DrawTileCall drawWeaponTile = *(DrawTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
    exceptionRegistration.state = 1;
    *(byte*)&exceptionRegistration.state = 14;
    bool showWeaponInfo = (weaponPanelFlags & 0x80U) != 0;
    if (!showWeaponInfo) {
        AR6PlayerController* weaponPanelController = (AR6PlayerController*)stack;
        showWeaponInfo = (*(byte*)((byte*)weaponPanelController + 0x83c) & 0x20U) != 0;
    }
    if (showWeaponInfo) {
        // Draw two filled strips and three outlines with the retained target and live per-packet fields.
        // +530/+534 are scales; +57c is material; +5c8/+5cc are fill/outline colors.
        __asm {
            mov ebx,this
            mov esi,drawWeaponTile
            mov eax,dword ptr [ebx+0x5c8]
            fld dword ptr [ebx+0x534]
            mov ecx,dword ptr [ebx+0x57c]
            fmul dword ptr HudWeaponPanelBottom
            push eax
            push ecx
            push 0x3f800000
            push 0x43f88000
            push 0x42d80000
            push 0x43d00000
            push 0x42d00000
            sub esp,0x10
            fstp dword ptr [esp+0xc]
            lea ecx,canvasStorage
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelRight
            fstp dword ptr [esp+0x8]
            fld dword ptr [ebx+0x534]
            fmul dword ptr HudWeaponPanelTop
            fstp dword ptr [esp+0x4]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudRadarZero
            fstp dword ptr [esp]
            call esi
            mov edx,dword ptr [ebx+0x5c8]
            fld dword ptr [ebx+0x534]
            mov eax,dword ptr [ebx+0x57c]
            fmul dword ptr HudWeaponPanelBottom
            push edx
            push eax
            push 0x3f800000
            push 0x43f88000
            push 0x42e40000
            push 0x43d00000
            push 0x42d80000
            sub esp,0x10
            fstp dword ptr [esp+0xc]
            lea ecx,canvasStorage
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelOuterRight
            fstp dword ptr [esp+0x8]
            fld dword ptr [ebx+0x534]
            fmul dword ptr HudWeaponPanelTop
            fstp dword ptr [esp+0x4]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelRight
            fstp dword ptr [esp]
            call esi
            mov ecx,dword ptr [ebx+0x5cc]
            fld dword ptr [ebx+0x534]
            mov edx,dword ptr [ebx+0x57c]
            fmul dword ptr HudWeaponPanelBottom
            push ecx
            push edx
            push 0x3f800000
            push 0x43f88000
            push 0x42f40000
            push 0x43d00000
            push 0x42ec0000
            sub esp,0x10
            fstp dword ptr [esp+0xc]
            lea ecx,canvasStorage
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelRight
            fstp dword ptr [esp+0x8]
            fld dword ptr [ebx+0x534]
            fmul dword ptr HudWeaponPanelTop
            fstp dword ptr [esp+0x4]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudSinglePanelInnerOffset
            fstp dword ptr [esp]
            call esi
            mov eax,dword ptr [ebx+0x5cc]
            mov ecx,dword ptr [ebx+0x57c]
            push eax
            push ecx
            push 0x3f800000
            push 0x43f88000
            push 0x43000000
            push 0x43d00000
            push 0x42f40000
            fld dword ptr [ebx+0x534]
            sub esp,0x10
            fmul dword ptr HudWeaponPanelBottom
            lea ecx,canvasStorage
            fstp dword ptr [esp+0xc]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelOuterRight
            fstp dword ptr [esp+0x8]
            fld dword ptr [ebx+0x534]
            fmul dword ptr HudWeaponPanelTop
            fstp dword ptr [esp+0x4]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudWeaponPanelRight
            fstp dword ptr [esp]
            call esi
            mov edx,dword ptr [ebx+0x5cc]
            fld dword ptr [ebx+0x534]
            mov eax,dword ptr [ebx+0x57c]
            fmul dword ptr HudWeaponPanelBottom
            push edx
            push eax
            push 0x3f800000
            push 0x43f88000
            push 0x42ec0000
            push 0x43d00000
            push 0x42e40000
            sub esp,0x10
            fstp dword ptr [esp+0xc]
            lea ecx,canvasStorage
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudSinglePanelInnerOffset
            fstp dword ptr [esp+0x8]
            fld dword ptr [ebx+0x534]
            fmul dword ptr HudWeaponPanelTop
            fstp dword ptr [esp+0x4]
            fld dword ptr [ebx+0x530]
            fmul dword ptr HudRadarZero
            fstp dword ptr [esp]
            call esi
        }
        AR6Rainbow* weaponView = viewedRainbow;
        auto* engineWeapon = weaponView->EngineWeapon;
        AR6Weapons* weapon = (AR6Weapons*)CastToAR6Weapons((int)engineWeapon);
        bool showWeaponContents = false;
        if (weapon != nullptr) {
            byte weaponContentFlags = *(byte*)((byte*)this + 0x524);
            showWeaponContents = (weaponContentFlags & 0x80U) != 0;
            if (!showWeaponContents) {
                AR6PlayerController* weaponContentController = (AR6PlayerController*)stack;
                showWeaponContents = (*(byte*)((byte*)weaponContentController + 0x83c) & 0x20U) != 0;
            }
        }
        if (showWeaponContents) {
            int bulletCount = weapon->m_iNbBulletsInWeapon;
            this->m_iBulletCount = bulletCount;
            int clipCapacity = weapon->m_iClipCapacity;
            this->m_iMaxBulletCount = clipCapacity;
            int magazineCount = weapon->m_iCurrentNbOfClips;
            UMaterial* cachedWeaponMaterial = this->m_pCurrentMaterial;
            this->m_iMagCount = magazineCount;
            int currentMagazine = weapon->m_iCurrentClip;
            this->m_iCurrentMag = currentMagazine;
            UMaterial* weaponTexture = weapon->m_HUDTexture;
            if (cachedWeaponMaterial != weaponTexture) {
                FCanvasUtil::Flush(canvas);
                UMaterial* updatedWeaponTexture = weapon->m_HUDTexture;
                auto* weaponBlend = this->m_pAlphaBlend;
                weaponBlend->Material = updatedWeaponTexture;
                this->m_pCurrentMaterial = weapon->m_HUDTexture;
            }
            // Keep raw UV words and round each x87 sum/product directly into the outgoing tile packet.
            __asm {
                mov ebx,this
                mov edi,weapon
                mov esi,drawWeaponTile
                mov eax,dword ptr [ebx+0x614]
                fld dword ptr [edi+0x484]
                fadd dword ptr [edi+0x47c]
                mov ecx,dword ptr [ebx+0x57c]
                mov edx,dword ptr [edi+0x47c]
                push eax
                mov eax,dword ptr [edi+0x478]
                push ecx
                push 0x3f800000
                sub esp,0x8
                fstp dword ptr [esp+0x4]
                lea ecx,canvasStorage
                fld dword ptr [edi+0x480]
                fadd dword ptr [edi+0x478]
                fstp dword ptr [esp]
                push edx
                fld dword ptr [ebx+0x534]
                push eax
                fmul dword ptr HudWeaponIconBottom
                sub esp,0x10
                fstp dword ptr [esp+0xc]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudWeaponIconRight
                fstp dword ptr [esp+0x8]
                fld dword ptr [ebx+0x534]
                fmul dword ptr HudWeaponIconTop
                fstp dword ptr [esp+0x4]
                fld dword ptr [ebx+0x530]
                fmul dword ptr HudWeaponIconLeft
                fstp dword ptr [esp]
                call esi
            }
            UMaterial* materialAfterWeapon = this->m_pCurrentMaterial;
            UMaterial* hudElementsTexture = this->m_TexHUDElements;
            if (materialAfterWeapon != hudElementsTexture) {
                FCanvasUtil::Flush(canvas);
                auto* hudElementsBlend = this->m_pAlphaBlend;
                UMaterial* updatedHudElementsTexture = this->m_TexHUDElements;
                hudElementsBlend->Material = updatedHudElementsTexture;
                this->m_pCurrentMaterial = this->m_TexHUDElements;
            }
            alignas(4) byte nameStorage[12], separatorStorage[12], combinedStorage[12];
            FString* weaponName = (FString*)nameStorage;
            FString::FString(weaponName, (FString*)&weapon->m_WeaponShortName);
            auto* selectedGadget = weapon->m_SelectedWeaponGadget;
            *(byte*)&exceptionRegistration.state = 15;
            if (selectedGadget != nullptr) {
                FString* separator = (FString*)separatorStorage;
                FString* separatorValue = FString::FString(separator, (ushort*)HudWeaponNameSeparator);
                auto* nameGadget = weapon->m_SelectedWeaponGadget;
                // m_GadgetShortName is at +0x3bc; the reread gadget has no second null check.
                FString* gadgetName = (FString*)((uint)nameGadget + 0x3bcU);
                byte* nameUnwindState = (byte*)&exceptionRegistration.state;
                uint addNameSlot = R6GameImports::Core_FString_OperatorAddStringSlot;
                uint appendNameSlot = R6GameImports::Core_FString_OperatorAppendAssignStringSlot;
                uint destroyNameSlot = R6GameImports::Core_FString_DestructorSlot;
                // Register each temporary after its argument pushes; destroy frame storage, not returned aliases.
                __asm {
                    mov ecx,gadgetName
                    push ecx
                    lea edx,combinedStorage
                    push edx
                    mov ecx,separatorValue
                    mov edx,nameUnwindState
                    mov byte ptr [edx],0x10
                    mov edx,addNameSlot
                    call dword ptr [edx]
                    push eax
                    lea ecx,nameStorage
                    mov edx,nameUnwindState
                    mov byte ptr [edx],0x11
                    mov edx,appendNameSlot
                    call dword ptr [edx]
                    lea ecx,combinedStorage
                    mov edx,nameUnwindState
                    mov byte ptr [edx],0x10
                    mov edx,destroyNameSlot
                    call dword ptr [edx]
                    lea ecx,separatorStorage
                    mov edx,nameUnwindState
                    mov byte ptr [edx],0xf
                    mov edx,destroyNameSlot
                    call dword ptr [edx]
                }
            }
            FCanvasUtil::Flush(canvas);
            UCanvas* weaponNameXCanvas = C;
            *(uint*)&weaponNameXCanvas->CurX = 0x42960000;
            UCanvas* weaponNameYCanvas = C;
            *(uint*)&weaponNameYCanvas->CurY = 0x440b4000;
            UCanvas* weaponNameStyleCanvas = C;
            weaponNameStyleCanvas->Style = 5;
            UCanvas* weaponNameColorCanvas = C;
            uint weaponNameColor = *(uint*)&this->m_HUDElements[3].Color;
            uint weaponNameDataSlot = R6GameImports::Core_FString_OperatorMultiplySlot;
            // SetClip is thiscall; WrappedPrintf takes canvas/font/1/text on the stack with caller cleanup.
            __asm {
                push 32
                push 156
                mov ecx,weaponNameColorCanvas
                mov eax,weaponNameColor
                mov dword ptr [ecx+0x64],eax
                mov ecx,C
                mov edx,dword ptr [ecx]
                push 557
                push 0
                call dword ptr [edx+0x88]
                lea ecx,nameStorage
                mov edx,weaponNameDataSlot
                call dword ptr [edx]
                mov ecx,C
                mov edx,dword ptr [ecx]
                push eax
                mov ebx,this
                mov eax,dword ptr [ebx+0x3ec]
                push 1
                push eax
                push ecx
                call dword ptr [edx+0x84]
                mov ecx,C
                mov edx,dword ptr [ecx]
                add esp,0x10
                push 600
                push 800
                push 0
                push 0
                call dword ptr [edx+0x88]
            }
            byte weaponHUDFlags = *(byte*)((byte*)weapon + 0x3a0);
            if ((weaponHUDFlags & 1U) != 0) {
                uint bulletTextColor = *(uint*)&this->m_HUDElements[5].Color;
                UCanvas* bulletColorCanvas = C;
                int measuredWidth, measuredHeight;
                // Both variadic virtuals are cdecl; reload the canvas before removing their argument packets.
                __asm {
                    mov ebx,this
                    mov eax,bulletTextColor
                    mov ecx,bulletColorCanvas
                    xor esi,esi
                    mov dword ptr measuredWidth,esi
                    mov dword ptr measuredHeight,esi
                    mov dword ptr [ecx+0x64],eax
                    mov ecx,dword ptr [ebx+0x514]
                    mov eax,dword ptr C
                    mov edx,dword ptr [eax]
                    push ecx
                    push offset HudBulletCountFormat
                    lea ecx,measuredHeight
                    push ecx
                    lea ecx,measuredWidth
                    push ecx
                    mov ecx,dword ptr [ebx+0x3f8]
                    push ecx
                    push eax
                    call dword ptr [edx+0x80]
                    mov edx,dword ptr C
                    add esp,0x18
                    mov dword ptr [edx+0x50],0x42960000
                    mov eax,dword ptr C
                    push 0x258
                    push 0x96
                    mov dword ptr [eax+0x54],0x440b4000
                    mov ecx,dword ptr C
                    mov edx,dword ptr [ecx]
                    push 0x238
                    push esi
                    call dword ptr [edx+0x88]
                    mov edx,dword ptr [ebx+0x514]
                    mov eax,dword ptr C
                    mov ecx,dword ptr [eax]
                    push edx
                    mov edx,dword ptr [ebx+0x3f8]
                    push offset HudBulletCountFormat
                    push 0x1
                    push edx
                    push eax
                    call dword ptr [ecx+0x84]
                    mov ecx,dword ptr C
                    mov eax,dword ptr [ecx]
                    add esp,0x14
                    push 0x258
                    push 0x320
                    push esi
                    push esi
                    call dword ptr [eax+0x88]
                }
            } else {
                UClass* cursor = *(UClass**)((byte*)weapon + 0x24);
                UClass* gadgetClass = *(UClass**)R6GameImports::R6Weapons_AR6Gadget_PrivateStaticClassSlot;
                while (cursor != nullptr && cursor != gadgetClass)
                    cursor = *(UClass**)((byte*)cursor + 0x2c);
                bool gadgetClassMatched = cursor == gadgetClass;
                if (!gadgetClassMatched) {
                    byte rateOfFire = weapon->m_eRateOfFire;
                    uint rateRowWord = rateOfFire == 0 ? 24U : rateOfFire == 1 ? 44U : 64U;
                    // The native scratch word changes from an integer row into its single-precision UV coordinate.
                    __asm {
                        mov ebx,this
                        mov esi,drawWeaponTile
                        mov ecx,dword ptr [ebx+0x644]
                        fild dword ptr rateRowWord
                        mov edx,dword ptr [ebx+0x57c]
                        push ecx
                        fstp dword ptr rateRowWord
                        mov eax,dword ptr rateRowWord
                        fld dword ptr rateRowWord
                        push edx
                        fadd dword ptr HudRateIconHeight
                        push 0x3f800000
                        push ecx
                        lea ecx,canvasStorage
                        fstp dword ptr [esp]
                        push 0x43ff8000
                        fld dword ptr [ebx+0x534]
                        push eax
                        fmul dword ptr HudRateIconBottom
                        push 0x43fa0000
                        sub esp,0x10
                        fstp dword ptr [esp+0xc]
                        fld dword ptr [ebx+0x530]
                        fmul dword ptr HudRateIconRight
                        fstp dword ptr [esp+0x8]
                        fld dword ptr [ebx+0x534]
                        fmul dword ptr HudRateIconTop
                        fstp dword ptr [esp+0x4]
                        fld dword ptr [ebx+0x530]
                        fmul dword ptr NativeFloatFive
                        fstp dword ptr [esp]
                        call esi
                    }
                    // Native buffer starts at frame -0x18c; the 64-word reservation is inferred.
                    ushort countBuffer[64];
                    uint countPlaneAddress;
                    uint countFlushSlot = R6GameImports::Engine_FCanvasUtil_FlushSlot;
                    uint countFormatSlot = R6GameImports::Core_appSprintfSlot;
                    uint countColorSlot = R6GameImports::Engine_FColor_ConversionOperatorSlot;
                    // Convert each color directly into its outgoing plane; retain the first width for 82-width placement.
                    __asm {
                        mov ebx,this
                        lea ecx,canvasStorage
                        mov edx,countFlushSlot
                        call dword ptr [edx]
                        mov ecx,dword ptr [ebx+0x514]
                        push ecx
                        lea edx,countBuffer
                        push offset HudBulletCountFormat
                        push edx
                        mov edx,countFormatSlot
                        call dword ptr [edx]
                        mov eax,dword ptr C
                        add esp,0xc
                        push 0x0
                        push 0x0
                        push 0x0
                        sub esp,0x10
                        mov ecx,esp
                        mov dword ptr countPlaneAddress,esp
                        lea edi,[ebx+0x62c]
                        push ecx
                        mov ecx,edi
                        mov byte ptr [eax+0x5c],0x0
                        mov edx,countColorSlot
                        call dword ptr [edx]
                        mov ecx,dword ptr C
                        mov edx,dword ptr [ecx]
                        lea eax,countBuffer
                        push eax
                        mov eax,dword ptr [ebx+0x3f8]
                        push 0x0
                        push 0x0
                        push eax
                        call dword ptr [edx+0x78]
                        mov ecx,dword ptr C
                        push 0x0
                        push 0x0
                        push 0x0
                        sub esp,0x10
                        mov edx,esp
                        mov byte ptr [ecx+0x5c],0x5
                        mov dword ptr countPlaneAddress,esp
                        push edx
                        mov ecx,edi
                        mov esi,eax
                        mov edx,countColorSlot
                        call dword ptr [edx]
                        mov ecx,dword ptr C
                        mov eax,dword ptr [ecx]
                        lea edx,countBuffer
                        push edx
                        mov edx,0x52
                        sub edx,esi
                        push 0x239
                        push edx
                        mov edx,dword ptr [ebx+0x3f8]
                        push edx
                        call dword ptr [eax+0x78]
                        mov eax,dword ptr [ebx+0x51c]
                        push eax
                        lea ecx,countBuffer
                        push offset HudMagazineCountFormat
                        push ecx
                        mov edx,countFormatSlot
                        call dword ptr [edx]
                        add esp,0xc
                        push 0x0
                        push 0x0
                        push 0x0
                        sub esp,0x10
                        mov edx,esp
                        mov dword ptr countPlaneAddress,esp
                        push edx
                        lea ecx,[ebx+0x638]
                        mov edx,countColorSlot
                        call dword ptr [edx]
                        mov ecx,dword ptr C
                        mov eax,dword ptr [ecx]
                        lea edx,countBuffer
                        push edx
                        mov edx,dword ptr [ebx+0x3f4]
                        push 0x242
                        push 0x52
                        push edx
                        call dword ptr [eax+0x78]
                    }
                }
            }
            byte* weaponNameFinalState = (byte*)&exceptionRegistration.state;
            uint weaponNameDestroySlot = R6GameImports::Core_FString_DestructorSlot;
            // Drop name ownership before invoking its destructor on the original frame object.
            __asm {
                lea ecx,nameStorage
                mov edx,weaponNameFinalState
                mov byte ptr [edx],14
                mov edx,weaponNameDestroySlot
                call dword ptr [edx]
            }
        }
    }
    AR6RainbowTeam* otherGateTeam = this->m_pLastRainbowTeam;
    bool showOtherTeamPanel = false;
    if (otherGateTeam != nullptr) {
        auto* otherGateReplication = this->m_GameRepInfo;
        if (otherGateReplication != nullptr) {
            byte otherPanelFlags = *(byte*)((byte*)this + 0x524);
            bool otherPanelEnabled = (otherPanelFlags & 0x40U) != 0;
            if (!otherPanelEnabled) {
                AR6PlayerController* otherPanelController = (AR6PlayerController*)stack;
                otherPanelEnabled = (*(byte*)((byte*)otherPanelController + 0x83c) & 0x20U) != 0;
            }
            if (otherPanelEnabled) {
                uint otherPanelDisplay = *(uint*)&this->m_HUDElements[14].eDisplay;
                showOtherTeamPanel = otherPanelDisplay != 1;
            }
        }
    }
    if (showOtherTeamPanel) {
        alignas(4) byte otherColorsStorage[8];
        using OtherColorConstructor = void (__thiscall *)(void*);
        OtherColorConstructor otherColorConstructor =
            *(OtherColorConstructor*)R6GameImports::Engine_FColor_ConstructorSlot;
        ConstructArrayElements(otherColorsStorage, 4, 2, otherColorConstructor);
        FColor* otherColors = (FColor*)otherColorsStorage;
        AR6RainbowTeam* otherNameTeam = this->m_pLastRainbowTeam;
        int teamName = otherNameTeam->m_iRainbowTeamName;
        AR6RainbowTeam* firstOtherTeam;
        AR6RainbowTeam* secondOtherTeam;
        const ushort* firstTeamKey;
        const ushort* secondTeamKey;
        bool validTeamName = true;
        if (teamName == 0) {
            auto* otherSelectionReplication = this->m_GameRepInfo;
            auto* otherSelectionColors = this->Colors;
            firstOtherTeam = otherSelectionReplication->m_RainbowTeam[1];
            uint firstOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[1];
            *(uint*)&otherColors[0] = firstOtherColor;
            secondOtherTeam = otherSelectionReplication->m_RainbowTeam[2];
            uint secondOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[2];
            *(uint*)&otherColors[1] = secondOtherColor;
            firstTeamKey = HudTeamTwoKey;
            secondTeamKey = HudTeamThreeKey;
        } else if (teamName == 1) {
            auto* otherSelectionReplication = this->m_GameRepInfo;
            auto* otherSelectionColors = this->Colors;
            firstOtherTeam = otherSelectionReplication->m_RainbowTeam[0];
            uint firstOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[0];
            *(uint*)&otherColors[0] = firstOtherColor;
            secondOtherTeam = otherSelectionReplication->m_RainbowTeam[2];
            uint secondOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[2];
            *(uint*)&otherColors[1] = secondOtherColor;
            firstTeamKey = HudTeamOneKey;
            secondTeamKey = HudTeamThreeKey;
        } else if (teamName == 2) {
            auto* otherSelectionReplication = this->m_GameRepInfo;
            auto* otherSelectionColors = this->Colors;
            firstOtherTeam = otherSelectionReplication->m_RainbowTeam[0];
            uint firstOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[0];
            *(uint*)&otherColors[0] = firstOtherColor;
            secondOtherTeam = otherSelectionReplication->m_RainbowTeam[1];
            uint secondOtherColor = *(uint*)&otherSelectionColors->TeamHUDColor[1];
            *(uint*)&otherColors[1] = secondOtherColor;
            firstTeamKey = HudTeamOneKey;
            secondTeamKey = HudTeamTwoKey;
        } else {
            validTeamName = false;
        }
        if (validTeamName) {
            uint otherNameRefresh = forceRefresh;
            if (otherNameRefresh != 0) {
                using TeamLocalizeCall = const ushort* (__cdecl *)(const ushort*, const ushort*, const ushort*,
                    const ushort*, int, int);
                using TeamNameAssignCall = FStringNoInit& (__thiscall *)(FStringNoInit*, const ushort*);
                TeamLocalizeCall firstLocalize = *(TeamLocalizeCall*)R6GameImports::Core_LocalizeSlot;
                const ushort* localized = firstLocalize(HudTeamNameSection, firstTeamKey,
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                TeamNameAssignCall firstAssign =
                    *(TeamNameAssignCall*)R6GameImports::Core_FStringNoInit_AssignTextSlot;
                firstAssign((FStringNoInit*)&this->m_aszOtherTeamName[0], localized);
                TeamLocalizeCall secondLocalize = *(TeamLocalizeCall*)R6GameImports::Core_LocalizeSlot;
                localized = secondLocalize(HudTeamNameSection, secondTeamKey,
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                TeamNameAssignCall secondAssign =
                    *(TeamNameAssignCall*)R6GameImports::Core_FStringNoInit_AssignTextSlot;
                secondAssign((FStringNoInit*)&this->m_aszOtherTeamName[1], localized);
            }
            if (firstOtherTeam != nullptr) {
                uint firstPanelRefresh = forceRefresh;
                UCanvas* firstPanelCanvas = C;
                DisplayOtherTeamInfo(this, canvas, firstPanelCanvas, 0, firstOtherTeam, &otherColors[0], firstPanelRefresh);
            }
            if (secondOtherTeam != nullptr) {
                uint secondPanelRefresh = forceRefresh;
                UCanvas* secondPanelCanvas = C;
                DisplayOtherTeamInfo(this, canvas, secondPanelCanvas, 1, secondOtherTeam, &otherColors[1], secondPanelRefresh);
            }
        }
    }
    AR6RainbowTeam* waypointTeam = this->m_pLastRainbowTeam;
    exceptionRegistration.state = 1;
    byte* waypointState = (byte*)&exceptionRegistration.state;
    *waypointState = 19;
    if (waypointTeam == nullptr)
        goto destroyCanvas;
    uint waypointFlags = *(uint*)((byte*)this + 0x524);
    if ((waypointFlags & 0x200U) == 0) {
        byte waypointControllerFlags = *(byte*)((byte*)cachedPlayerController + 0x83c);
        if ((waypointControllerFlags & 0x20U) == 0)
            goto destroyCanvas;
    }
    if (capturedPlanning == nullptr)
        goto destroyCanvas;
    uint milestoneFlags = *(uint*)((byte*)cachedPlayerController + 0x838);
    if ((milestoneFlags & 0x400U) != 0) {
        C->CurX = 0.0f;
        C->CurY = 348.0f;
        C->DrawColor = this->m_HUDElements[11].Color;
        const ushort* message = FString::operator*((FString*)&cachedPlayerController->m_szMileStoneMessage);
        UCanvas* milestoneCanvas = C;
        TextCall milestoneText = *(TextCall*)(*(byte**)milestoneCanvas + 0x84);
        UFont* milestoneFont = this->m_FontRainbow6_22pt;
        milestoneText(milestoneCanvas, milestoneFont, 1, message);
    } else if (forceRefresh != 0 || this->m_eLastPlayerAPAction != waypointTeam->m_ePlayerAPAction ||
        this->m_eLastGoCode != waypointTeam->m_eGoCode) {
        byte action = waypointTeam->m_ePlayerAPAction;
        AR6RainbowTeam* actionCacheTeam = this->m_pLastRainbowTeam;
        this->m_eLastPlayerAPAction = action;
        this->m_eLastGoCode = actionCacheTeam->m_eGoCode;
        static const ushort* planningKeys[6] = {
            HudPlanningFragKey, HudPlanningFlashKey, HudPlanningGasKey,
            HudPlanningSmokeKey, HudPlanningSnipeKey, HudPlanningBreachKey
        };
        using LocalizeCall = const ushort* (__cdecl *)(const ushort*, const ushort*, const ushort*,
            const ushort*, int, int);
        LocalizeCall planningLocalize;
        const ushort* localized;
        FStringNoInit* planningActionText;
        if (action >= 1 && action <= 6) {
            planningLocalize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
            localized = planningLocalize(OtherTeamLocalizeSection, (ushort*)planningKeys[action - 1],
                OtherTeamLocalizePackage, nullptr, 0, 0);
            planningActionText = (FStringNoInit*)&this->m_szLastPlayerAPAction;
            FStringNoInit::operator=(planningActionText, localized);
            if (action == 5) {
                AR6RainbowTeam* sniperTeam = this->m_pLastRainbowTeam;
                uint sniperFlags = *(uint*)((byte*)sniperTeam + 0x3e8);
                if ((sniperFlags & 0x80000U) != 0) {
                    FString::operator+=((FString*)planningActionText, OtherTeamActionSeparator);
                    localized = planningLocalize(OtherTeamLocalizeSection, OtherTeamSnipeHold,
                        OtherTeamLocalizePackage, nullptr, 0, 0);
                    FString::operator+=((FString*)planningActionText, (ushort*)localized);
                }
            }
        } else if (this->m_pLastRainbowTeam->m_eGoCode != 4) {
            planningLocalize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
            localized = planningLocalize(OtherTeamLocalizeSection, HudPlanningWaitKey,
                OtherTeamLocalizePackage, nullptr, 0, 0);
            planningActionText = (FStringNoInit*)&this->m_szLastPlayerAPAction;
            FStringNoInit::operator=(planningActionText, localized);
        } else {
            planningActionText = (FStringNoInit*)&this->m_szLastPlayerAPAction;
            FStringNoInit::operator=(planningActionText, HudEmptyPlanningText);
            planningLocalize = *(LocalizeCall*)R6GameImports::Core_LocalizeSlot;
        }
        if (this->m_pLastRainbowTeam->m_eGoCode != 4)
            FString::operator+=((FString*)planningActionText, OtherTeamActionSeparator);
        byte goCode = this->m_pLastRainbowTeam->m_eGoCode;
        static const ushort* goCodeKeys[4] = {
            OtherTeamGoCodeAlpha, OtherTeamGoCodeBravo,
            OtherTeamGoCodeCharlie, OtherTeamGoCodeZulu
        };
        if (goCode <= 3) {
            localized = planningLocalize(OtherTeamLocalizeSection, (ushort*)goCodeKeys[goCode],
                OtherTeamLocalizePackage, nullptr, 0, 0);
            FString::operator+=((FString*)planningActionText, (ushort*)localized);
        }
        uint pressGoCodeFlags = *(uint*)((byte*)this + 0x524);
        if ((pressGoCodeFlags & 0x40000U) != 0) {
            ushort promptBuffer[64] = {};
            goCode = this->m_pLastRainbowTeam->m_eGoCode;
            if (goCode <= 3) {
                static const ushort* actionKeys[4] = {
                    HudGoCodeAlphaAction, HudGoCodeBravoAction,
                    HudGoCodeCharlieAction, HudGoCodeZuluAction
                };
                // Native buffers at EBP-2c/-64/-80/-74 bind states 20/21/22/23 respectively.
                alignas(4) byte keyNameStorage[4][12];
                using KeyNameCall = FString* (__thiscall *)(AR6PlayerController*, FString*, const ushort*);
                FString* keyName = (*(KeyNameCall*)R6GameImports::R6Engine_AR6PlayerController_GetLocKeyNameByActionKeySlot)(cachedPlayerController,
                    (FString*)keyNameStorage[goCode], actionKeys[goCode]);
                *waypointState = 20 + goCode;
                const ushort* keyText = FString::operator*(keyName);
                localized = planningLocalize(OtherTeamLocalizeSection, HudPressGoCodeKey,
                    OtherTeamLocalizePackage, nullptr, 0, 0);
                appSprintf(promptBuffer, (ushort*)localized, keyText);
                *waypointState = 19;
                FString::~FString((FString*)keyNameStorage[goCode]);
            }
            FStringNoInit::operator=((FStringNoInit*)&this->m_szPressGoCode, promptBuffer);
        } else {
            FStringNoInit::operator=((FStringNoInit*)&this->m_szPressGoCode, HudEmptyPlanningText);
        }
    }
    int waypointDistanceMeters = -1;
    if (this->m_pNextWayPoint != nullptr) {
        APawn* ownerPawn = cachedPlayerController->Pawn;
        bool drawWaypoint = ownerPawn != nullptr && ownerPawn->m_fDecrementalBlurValue < 150.0f;
        if (!drawWaypoint) {
            int promptCount = *(int*)((byte*)&this->m_szPressGoCode + 4);
            drawWaypoint = promptCount == 0 || (int)((uint)promptCount - 1U) == 0;
        }
        if (drawWaypoint) {
            float savedStretchX = C->m_fStretchX;
            float savedStretchY = C->m_fStretchY;
            C->m_fStretchX = 1.0f;
            C->m_fStretchY = 1.0f;
            alignas(4) byte sceneStorage[0x1e0];
            FCameraSceneNode* scene = (FCameraSceneNode*)sceneStorage;
            UViewport* sceneViewport = C->Viewport;
            float cameraFOV = ((AController*)sceneViewport->Actor)->FovAngle;
            FRotator cameraRotationAt1c4 = *(FRotator*)((byte*)sceneViewport + 0x1c4);
            FVector cameraLocationAt1b8 = *(FVector*)((byte*)sceneViewport + 0x1b8);
            FCameraSceneNode::FCameraSceneNode(scene, sceneViewport, sceneViewport->Actor,
                cameraLocationAt1b8, cameraRotationAt1c4, cameraFOV);
            sceneViewport = C->Viewport;
            FVector cameraOrigin = *(FVector*)((byte*)sceneViewport + 0x1b8);
            FVector cameraForward;
            using RotatorVectorCall = FVector* (__thiscall *)(FRotator*, FVector*);
            *waypointState = 24;
            (*(RotatorVectorCall*)R6GameImports::Core_FRotator_VectorSlot)((FRotator*)((byte*)sceneViewport + 0x1c4), &cameraForward);
            AActor* target = this->m_pNextWayPoint;
            FVector targetPoint;
            long double raisedTargetZ = (long double)target->Location.Z + NativeFloatFifty;
            targetPoint.Z = (float)raisedTargetZ;
            targetPoint.Y = target->Location.Y;
            targetPoint.X = target->Location.X;
            FVector towardTarget;
            towardTarget.Z = (float)(raisedTargetZ - cameraOrigin.Z);
            towardTarget.Y = (float)((long double)targetPoint.Y - cameraOrigin.Y);
            towardTarget.X = (float)((long double)targetPoint.X - cameraOrigin.X);
            float distance = (float)FVector::Size(&towardTarget);
            FVector::Normalize(&cameraForward);
            long double inverseDistance = 1.0L / distance;
            towardTarget.X = (float)((long double)towardTarget.X * inverseDistance);
            towardTarget.Y = (float)((long double)towardTarget.Y * inverseDistance);
            towardTarget.Z = (float)((long double)towardTarget.Z * inverseDistance);
            long double metersValue = (long double)distance * 0.009999999776482582f;
            __asm {
                fld metersValue
                call ConvertX87ToSigned64
                mov waypointDistanceMeters, eax
            }
            double halfFovRadians = (double)((long double)this->PlayerOwner->FovAngle * 0.5f *
                0.017453292519943295);
            using TrigCall = float10 (__cdecl *)(double);
            long double cosine = (*(TrigCall*)R6GameImports::Core_appCosSlot)(halfFovRadians);
            double cosineScratch = (double)cosine;
            long double viewDot = (long double)cameraForward.Z * towardTarget.Z;
            viewDot += (long double)cameraForward.Y * towardTarget.Y;
            viewDot += (long double)cameraForward.X * towardTarget.X;
            // Applies the selected canvas matrix to projected XYZ with W forced to one.
            auto canvasPoint = [&](const FPlane* projected) -> FPlane {
                FPlane input(projected->X, projected->Y, projected->Z, 1.0f);
                const float* components = (const float*)&input;
                const float* matrixAt14 = (const float*)((byte*)canvas + 0x14);
                FPlane output;
                float* outputComponents = (float*)&output;
                for (int column = 0; column < 4; ++column) {
                    long double value = (long double)components[0] * matrixAt14[column];
                    value += (long double)components[1] * matrixAt14[4 + column];
                    value += (long double)components[2] * matrixAt14[8 + column];
                    value += (long double)components[3] * matrixAt14[12 + column];
                    outputComponents[column] = (float)value;
                }
                return output;
            };
            // Creates a registered dynamic final blend once and sets the native depth/alpha flags.
            auto ensureWaypointBlend = [&](UFinalBlend** storage) {
                if (*storage == nullptr) {
                    *storage = ConstructCheckedFinalBlend((UClass*)ImportedUFinalBlendClass,
                        (UObject*)0xffffffff, (FName)0, 0);
                    UGlobalTempObjects::AddGlobalObject(*(UGlobalTempObjects**)ImportedGGlobalTempObjectsAddress,
                        (UObject**)storage);
                    UClass* cursor = *(UClass**)((byte*)*storage + 0x24);
                    UClass* materialClass = (UClass*)ImportedUMaterialClass;
                    while (cursor != nullptr && cursor != materialClass)
                        cursor = *(UClass**)((byte*)cursor + 0x2c);
                    if (cursor == materialClass) {
                        UMaterial* material = (UMaterial*)CastToUMaterial((int)*storage);
                        *(uint*)((byte*)material + 0x34) |= 8U;
                    }
                    (*storage)->FrameBufferBlending = 2;
                    *(uint*)((byte*)*storage + 0x60) &= ~1U;
                    *(uint*)((byte*)*storage + 0x60) &= ~2U;
                    *(uint*)((byte*)*storage + 0x60) &= ~4U;
                    *(uint*)((byte*)*storage + 0x60) |= 8U;
                }
            };
            using ProjectCall = FPlane* (__thiscall *)(FSceneNode*, FPlane*, FVector);
            if (viewDot > cosine) {
                if ((*(uint*)((byte*)initialViewport + 0x1e0) & 0x10U) != 0) {
                    alignas(4) byte lineStorage[0x24];
                    FLineBatcher* lineBatch = (FLineBatcher*)lineStorage;
                    FLineBatcher::FLineBatcher(lineBatch, initialRenderInterface, 0, 0);
                    AActor* arrowTarget = this->m_pNextWayPoint;
                    FRotator arrowRotation = arrowTarget->Rotation;
                    FVector arrowLocation = arrowTarget->Location;
                    *waypointState = 25;
                    FLineBatcher::DrawDirectionalArrow(lineBatch, arrowLocation, arrowRotation,
                        FColor(255, 255, 255, 255), 1.0f);
                    FLineBatcher::Flush(lineBatch, 0);
                    *waypointState = 24;
                    FLineBatcher::~FLineBatcher(lineBatch);
                }
                FPlane targetProjection;
                (*(ProjectCall*)R6GameImports::Engine_FSceneNode_ProjectSlot)((FSceneNode*)scene, &targetProjection, targetPoint);
                FPlane markerCenter = canvasPoint(&targetProjection);
                FVector headingDirectionStorage;
                FVector* headingDirection = (*(RotatorVectorCall*)R6GameImports::Core_FRotator_VectorSlot)(
                    &this->m_pNextWayPoint->Rotation, &headingDirectionStorage);
                float scaledHeadingY = (float)((long double)headingDirection->Y * 100.0f);
                float scaledHeadingX = (float)((long double)headingDirection->X * 100.0f);
                AActor* headingTarget = this->m_pNextWayPoint;
                FVector headingEnd;
                headingEnd.Z = (float)((long double)headingDirection->Z * 100.0f + headingTarget->Location.Z);
                headingEnd.Y = (float)((long double)scaledHeadingY + headingTarget->Location.Y);
                headingEnd.X = (float)((long double)scaledHeadingX + headingTarget->Location.X);
                FPlane headingProjectionStorage;
                FPlane* headingProjection = (*(ProjectCall*)R6GameImports::Engine_FSceneNode_ProjectSlot)((FSceneNode*)scene,
                    &headingProjectionStorage, headingEnd);
                FPlane headingProjectionValue = *headingProjection;
                FPlane headingScreen = canvasPoint(&headingProjectionValue);
                FVector baseLocation = this->m_pNextWayPoint->Location;
                FPlane baseProjectionStorage;
                FPlane* baseProjection = (*(ProjectCall*)R6GameImports::Engine_FSceneNode_ProjectSlot)((FSceneNode*)scene,
                    &baseProjectionStorage, baseLocation);
                FPlane baseProjectionValue = *baseProjection;
                FPlane baseScreen = canvasPoint(&baseProjectionValue);
                FVector screenHeading;
                screenHeading.Z = 0.0f;
                screenHeading.Y = (float)((long double)headingScreen.Y - baseScreen.Y);
                screenHeading.X = (float)((long double)headingScreen.X - baseScreen.X);
                FVector::Normalize(&screenHeading);
                long double iconAngle = (*(TrigCall*)R6GameImports::Core_appAcosSlot)((double)screenHeading.X);
                double angleScratch = (double)iconAngle;
                if (screenHeading.Y < 0.0f)
                    iconAngle = -iconAngle;
                float rotationAngle = (float)(iconAngle + 1.5707963705062866f);
                ensureWaypointBlend(&HudWaypointFinalBlend);
                HudWaypointFinalBlend->Material = this->m_Waypoint;
                RotatedTileCall drawRotatedTile = *(RotatedTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileRotatedSlot;
                drawRotatedTile(canvas,
                    (float)((long double)markerCenter.X - (long double)this->m_fScaleX * 16.0f),
                    (float)((long double)markerCenter.Y - (long double)this->m_fScaleY * 16.0f),
                    (float)((long double)markerCenter.X + (long double)this->m_fScaleX * 16.0f),
                    (float)((long double)this->m_fScaleY * 16.0f + markerCenter.Y),
                    0.0f, 0.0f, 31.0f, 31.0f, 1.0f, (UMaterial*)HudWaypointFinalBlend,
                    this->m_HUDElements[13].Color, rotationAngle);
                alignas(4) byte distanceStorage[12];
                FString* distanceText = (FString*)distanceStorage;
                using PrintfCall = FString* (__cdecl *)(FString*, const ushort*, ...);
                (*(PrintfCall*)R6GameImports::Core_FString_PrintfSlot)(distanceText,
                    HudWaypointDistanceFormat, waypointDistanceMeters);
                *waypointState = 26;
                C->Style = 0;
                FPlane distanceColor;
                (*(ColorPlaneCall*)R6GameImports::Engine_FColor_ConversionOperatorSlot)(&this->m_HUDElements[13].Color, &distanceColor);
                const ushort* text = FString::operator*(distanceText);
                int textWidth = (*(DrawStringCall*)(*(byte**)C + 0x78))(C, this->m_FontRainbow6_14pt,
                    0, 0, text, distanceColor, 0, 0, 0);
                FColor fadedColor = this->m_HUDElements[13].Color;
                long double alphaValue = (long double)(int)fadedColor.A * 0.4000000059604645f;
                uint alphaBits;
                __asm {
                    fld alphaValue
                    call ConvertX87ToSigned64
                    mov alphaBits, eax
                }
                fadedColor.A = (byte)alphaBits;
                C->Style = 5;
                (*(ColorPlaneCall*)R6GameImports::Engine_FColor_ConversionOperatorSlot)(&fadedColor, &distanceColor);
                text = FString::operator*(distanceText);
                DrawStringCall drawDistanceText = *(DrawStringCall*)(*(byte**)C + 0x78);
                long double textYValue = (long double)this->m_fScaleY * 16.0f + markerCenter.Y + 2.0f;
                int textX, textY;
                __asm {
                    fld textYValue
                    call ConvertX87ToSigned64
                    mov textY, eax
                }
                long double textXValue = (long double)markerCenter.X - (long double)textWidth * 0.5f;
                __asm {
                    fld textXValue
                    call ConvertX87ToSigned64
                    mov textX, eax
                }
                drawDistanceText(C, this->m_FontRainbow6_14pt, textX, textY, text, distanceColor, 0, 0, 0);
                *waypointState = 24;
                FString::~FString(distanceText);
            } else {
                AActor* edgeTarget = this->m_pNextWayPoint;
                FVector targetLocation = edgeTarget->Location;
                FVector forwardAnchor;
                float anchorScaledX = (float)((long double)cameraForward.X * 1000.0f);
                forwardAnchor.Z = (float)((long double)cameraOrigin.Z + (long double)cameraForward.Z * 1000.0f);
                forwardAnchor.Y = (float)((long double)cameraOrigin.Y + (long double)cameraForward.Y * 1000.0f);
                forwardAnchor.X = (float)((long double)anchorScaledX + cameraOrigin.X);
                FVector edgeDirection;
                edgeDirection.Z = (float)((long double)targetLocation.Z - forwardAnchor.Z);
                edgeDirection.Y = (float)((long double)targetLocation.Y - forwardAnchor.Y);
                edgeDirection.X = (float)((long double)targetLocation.X - forwardAnchor.X);
                FVector::Normalize(&edgeDirection);
                float scaledEdgeX = (float)((long double)edgeDirection.X * 256.0f);
                float scaledEdgeY = (float)((long double)edgeDirection.Y * 256.0f);
                long double scaledEdgeZ = (long double)edgeDirection.Z * 256.0f;
                edgeDirection.X = scaledEdgeX;
                edgeDirection.Y = scaledEdgeY;
                edgeDirection.Z = (float)scaledEdgeZ;
                FVector proxyPoint;
                proxyPoint.Z = (float)(scaledEdgeZ + forwardAnchor.Z);
                proxyPoint.Y = (float)((long double)scaledEdgeY + forwardAnchor.Y);
                proxyPoint.X = (float)((long double)scaledEdgeX + forwardAnchor.X);
                FPlane proxyProjection;
                (*(ProjectCall*)R6GameImports::Engine_FSceneNode_ProjectSlot)((FSceneNode*)scene, &proxyProjection, proxyPoint);
                FPlane proxyScreen = canvasPoint(&proxyProjection);
                UViewport* edgeViewport = C->Viewport;
                float centerY = (float)((long double)edgeViewport->SizeY * 0.5f);
                float centerX = (float)((long double)edgeViewport->SizeX * 0.5f);
                FVector screenDirection;
                screenDirection.Z = 0.0f;
                screenDirection.Y = (float)((long double)proxyScreen.Y - centerY);
                screenDirection.X = (float)((long double)proxyScreen.X - centerX);
                FVector::Normalize(&screenDirection);
                edgeViewport = C->Viewport;
                float edgeX = (float)((long double)edgeViewport->SizeX * 0.44999998807907104f *
                    screenDirection.X + centerX);
                float edgeY = (float)((long double)edgeViewport->SizeY * 0.44999998807907104f *
                    screenDirection.Y + centerY);
                long double iconAngle = (*(TrigCall*)R6GameImports::Core_appAcosSlot)((double)screenDirection.X);
                double angleScratch = (double)iconAngle;
                if (screenDirection.Y < 0.0f)
                    iconAngle = -iconAngle;
                float rotationAngle = (float)(iconAngle + 1.5707963705062866f);
                ensureWaypointBlend(&HudWaypointArrowFinalBlend);
                HudWaypointArrowFinalBlend->Material = this->m_WaypointArrow;
                RotatedTileCall drawRotatedTile = *(RotatedTileCall*)R6GameImports::Engine_FCanvasUtil_DrawTileRotatedSlot;
                drawRotatedTile(canvas,
                    (float)((long double)edgeX - (long double)this->m_fScaleX * 16.0f),
                    (float)((long double)edgeY - (long double)this->m_fScaleY * 16.0f),
                    (float)((long double)edgeX + (long double)this->m_fScaleX * 16.0f),
                    (float)((long double)edgeY + (long double)this->m_fScaleY * 16.0f),
                    0.0f, 0.0f, 31.0f, 31.0f, 1.0f, (UMaterial*)HudWaypointArrowFinalBlend,
                    this->m_HUDElements[13].Color, rotationAngle);
            }
            C->m_fStretchX = (float)(long double)savedStretchX;
            *waypointState = 19;
            C->m_fStretchY = (float)(long double)savedStretchY;
            FCameraSceneNode::~FCameraSceneNode(scene);
        }
    }
    uint finalMilestoneFlags = *(uint*)((byte*)cachedPlayerController + 0x838);
    if ((finalMilestoneFlags & 0x400U) == 0) {
        C->CurX = 0.0f;
        C->CurY = 348.0f;
        C->DrawColor = this->m_HUDElements[11].Color;
        const ushort* actionText = FString::operator*((FString*)&this->m_szLastPlayerAPAction);
        UCanvas* actionCanvas = C;
        TextCall drawActionText = *(TextCall*)(*(byte**)actionCanvas + 0x84);
        UFont* actionFont = this->m_FontRainbow6_22pt;
        drawActionText(actionCanvas, actionFont, 1, actionText);
        int promptCount = *(int*)((byte*)&this->m_szPressGoCode + 4);
        if (promptCount != 0 && (int)((uint)promptCount - 1U) != 0 &&
            *(uint*)&this->m_HUDElements[11].eDisplay != 1) {
            if (waypointDistanceMeters != -1) {
                if (waypointDistanceMeters > 5 && (*(uint*)((byte*)this + 0x524) & 0x80000U) != 0) {
                    *(uint*)&this->m_HUDElements[15].eDisplay = 3;
                    *(uint*)&this->m_HUDElements[15].fTimeStamp = 0x4e6e6b28;
                } else {
                    *(uint*)&this->m_HUDElements[15].eDisplay = 0;
                }
            }
            C->CurY = (float)((long double)C->CurY + 5.0f);
            C->DrawColor = this->m_HUDElements[15].Color;
            const ushort* promptText = FString::operator*((FString*)&this->m_szPressGoCode);
            UCanvas* promptCanvas = C;
            TextCall drawPromptText = *(TextCall*)(*(byte**)promptCanvas + 0x84);
            UFont* promptFont = this->m_FontRainbow6_14pt;
            drawPromptText(promptCanvas, promptFont, 1, promptText);
        }
    }
destroyCanvas:
    exceptionRegistration.state = 0;
    FCanvasUtil::~FCanvasUtil(canvas);
finished:
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000d2bd : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0xdc]
        mov dword ptr [ebp-0xdc],ecx
        push edx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000d2d7 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext2(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_MovementModeExceptionContext // L"AR6HUD::MovementMode"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000d7d6 : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer3(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xe4]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0xe0]
        mov dword ptr [ebp-0xe0],eax
        push ecx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000d7f3 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext3(void)
{
    __asm {
        push R6GameAddresses::R6HUD_ShowTeamMatesHealthExceptionContext // L"R6HUD::ShowTeamMatesHealth"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000e146 : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xe4]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0xcc]
        mov dword ptr [ebp-0xcc],ecx
        push edx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000e163 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext4(void)
{
    __asm {
        push R6GameAddresses::R6HUD_ShowTeamActionExceptionContext // L"R6HUD::ShowTeamAction"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000e16d : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xbc]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0xd0]
        mov dword ptr [ebp-0xd0],ecx
        push edx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000e18a : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext5(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_m_bShowCurrentTeamInfoExceptionContext // L"AR6HUD::m_bShowCurrentTeamInfo"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000e194 : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer6(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x3c]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0xd4]
        mov dword ptr [ebp-0xd4],eax
        push ecx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000e1ae : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext6(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawTeamInfoExceptionContext // L"AR6HUD::DrawTeamInfo"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000f778 : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xbc]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0xd8]
        mov dword ptr [ebp-0xd8],ecx
        push edx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000f795 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext8(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawPlayerTeamInfoExceptionContext // L"AR6HUD::DrawPlayerTeamInfo"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000f79c : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer7(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xbc]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0xc0]
        mov dword ptr [ebp-0xc0],eax
        push ecx
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000f7b6 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext7(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawWeaponInfoExceptionContext // L"AR6HUD::DrawWeaponInfo"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000f7bd : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer1(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x3c]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0xc4]
        mov dword ptr [ebp-0xc4],edx
        push eax
        jmp R6GameAddresses::NativeHudCaughtPointerThrowTail
    }
}

// R6Game.dll @ 1000f7d4 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext1(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawCharacterInfoExceptionContext1 // L"AR6HUD::DrawCharacterInfo"
        jmp R6GameAddresses::NativeHudReportAndThrowTail
    }
}

// R6Game.dll @ 1000f7db : rethrow the HUD scope's caught UTF-16 pointer value
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchPointer9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0xe8]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0xc8]
        push edx
        mov dword ptr [ebp-0xc8],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000f7f8 : report HUD scope context and rethrow the active exception
__declspec(naked) void AR6HUD_execDrawNativeHUDCatchContext9(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_execDrawNativeHUDExceptionContext // L"AR6HUD::execDrawNativeHUD"
        // Shared reporting tail: the context pointer is already on the stack.
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        add esp,0x8
        push 0x0
        push 0x0
        // Shared throw-call tail: both outgoing arguments are already on the stack.
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000f8d0 : DrawRadar
// Draws the radar layers and friendly replication markers with heading, height, pilot and communication cues.
void __thiscall AR6HUD::DrawRadar(AR6HUD* this, FCameraSceneNode* scene, UViewport* viewport)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DrawRadarExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    AR6HUD* radarHud = this;
    APlayerController* initialOwner = radarHud->PlayerOwner;
    uint initialOwnerFlags = *(uint*)((byte*)initialOwner + 0x524);
    exceptionRegistration.state = 0;
    if ((initialOwnerFlags & 0x4000U) != 0 || radarHud->m_iCycleHUDLayer == 3 || initialOwner == nullptr) {
        __writefsdword(0, exceptionRegistration.previousAddress);
        return;
    }
    for (int index = 0; index < 7; ++index) {
        if (radarHud->m_TexRadarTextures[index] == nullptr) {
            __writefsdword(0, exceptionRegistration.previousAddress);
            return;
        }
    }
    alignas(4) byte canvasStorage[0xca8];
    FCanvasUtil* canvas = (FCanvasUtil*)canvasStorage;
    UViewport* radarViewport = viewport;
    FRenderInterface* renderInterfaceAt164 = *(FRenderInterface**)((byte*)radarViewport + 0x164);
    using CanvasConstructor = FCanvasUtil* (__thiscall *)(FCanvasUtil*, UViewport*, FRenderInterface*, int, int);
    (*(CanvasConstructor*)R6GameImports::Engine_FCanvasUtil_ConstructorSlot)(canvas,
        radarViewport, renderInterfaceAt164, 0, 1);
    float radarWidth, radarHeight, left, top, centerX, centerY, halfMarkerX, halfMarkerY;
    uint hudFlags;
    int* radarUnwindState = &exceptionRegistration.state;
    // Retain signed dimensions and aspect on x87 through the native float-store order.
    __asm {
        mov edi,radarViewport
        fild dword ptr [edi+0xa8]
        fild dword ptr [edi+0xa4]
        mov esi,radarHud
        mov eax,dword ptr [esi+0x524]
        mov hudFlags,eax
        fld st(1)
        fdiv st,st(1)
        mov ecx,radarUnwindState
        mov byte ptr [ecx],1
        fld st(1)
        fmul dword ptr HudRadarExtentFraction
        fmul st,st(1)
        fstp dword ptr radarWidth
        fld st(2)
        fmul dword ptr HudRadarExtentFraction
        fstp dword ptr radarHeight
        fld st(1)
        fsub dword ptr radarWidth
        fsub dword ptr HudSinglePanelInnerOffset
        fstp dword ptr left
        fld st(2)
        fsub dword ptr radarHeight
        fsub dword ptr HudSinglePanelInnerOffset
        fstp dword ptr top
        fld dword ptr radarWidth
        fmul dword ptr HudRadarHalf
        fadd dword ptr left
        fstp dword ptr centerX
        fld dword ptr radarHeight
        fmul dword ptr HudRadarHalf
        fadd dword ptr top
        fstp dword ptr centerY
        fxch st(1)
        fmul dword ptr HudRadarMarkerFraction
        fmul st,st(1)
        fmul dword ptr HudRadarHalf
        fadd dword ptr HudCharacterPanelBorderInset
        fstp dword ptr halfMarkerX
        fstp st(0)
        fmul dword ptr HudRadarMarkerFraction
        fmul dword ptr HudRadarHalf
        fadd dword ptr HudCharacterPanelBorderInset
        fstp dword ptr halfMarkerY
    }
    FColor radarColor;
    if ((hudFlags & 8U) != 0) {
        APlayerController* colorOwner = radarHud->PlayerOwner;
        APlayerReplicationInfo* replication = colorOwner->PlayerReplicationInfo;
        uint teamId = *(uint*)((byte*)replication + 0x3a0);
        byte* colors = (byte*)radarHud->Colors;
        *(uint*)&radarColor = *(uint*)(colors + (teamId == 2 ? 0x7c : 0x78));
    } else if ((hudFlags & 2U) != 0) {
        AR6RainbowTeam* lastTeam = radarHud->m_pLastRainbowTeam;
        uint teamName = (uint)lastTeam->m_iRainbowTeamName;
        byte* colors = (byte*)radarHud->Colors;
        *(uint*)&radarColor = *(uint*)(colors + 0x78U + teamName * 4U);
    } else {
        UR6GameOptions** optionStorage = (UR6GameOptions**)ImportedGGameOptionsAddress;
        UR6GameOptions* options = *optionStorage;
        *(uint*)&radarColor = *(uint*)&options->HUDMPColor;
    }
    if (HudRadarFinalBlend == nullptr) {
        // The outgoing FName is one zero DWORD, without an owned name temporary.
        uint blendNameWord = 0;
        UClass* blendClass = (UClass*)ImportedUFinalBlendClass;
        using BlendConstructorCall = UFinalBlend* (__cdecl *)(UClass*, UObject*, uint, uint);
        HudRadarFinalBlend = ((BlendConstructorCall)&ConstructCheckedFinalBlend)(blendClass,
            (UObject*)0xffffffff, blendNameWord, 0);
        UGlobalTempObjects** tempObjectStorage = (UGlobalTempObjects**)ImportedGGlobalTempObjectsAddress;
        UGlobalTempObjects* tempObjects = *tempObjectStorage;
        UGlobalTempObjects::AddGlobalObject(tempObjects, (UObject**)&HudRadarFinalBlend);
        UFinalBlend* registeredBlend = HudRadarFinalBlend;
        UClass* cursor = *(UClass**)((byte*)registeredBlend + 0x24);
        UClass* materialClass = (UClass*)ImportedUMaterialClass;
        while (cursor != nullptr && cursor != materialClass)
            cursor = *(UClass**)((byte*)cursor + 0x2c);
        if (cursor == materialClass) {
            UMaterial* material = (UMaterial*)CastToUMaterial((int)registeredBlend);
            *(uint*)((byte*)material + 0x34) |= 8U;
            registeredBlend = HudRadarFinalBlend;
        }
        *(byte*)((byte*)registeredBlend + 0x5c) = 2; // FrameBufferBlending.
        *(uint*)((byte*)HudRadarFinalBlend + 0x60) &= ~1U; // ZWrite.
        *(uint*)((byte*)HudRadarFinalBlend + 0x60) &= ~2U; // ZTest.
        *(uint*)((byte*)HudRadarFinalBlend + 0x60) &= ~4U; // AlphaTest.
        *(uint*)((byte*)HudRadarFinalBlend + 0x60) |= 8U; // TwoSided.
    }
    using DrawTileCall = void (__thiscall *)(FCanvasUtil*, float, float, float, float,
        float, float, float, float, float, UMaterial*, FColor);
    using DrawTileWordsCall = void (__thiscall *)(FCanvasUtil*, uint, uint, uint, uint,
        uint, uint, uint, uint, uint, UMaterial*, uint);
    UMaterial* layerTexture = radarHud->m_TexRadarTextures[0];
    UFinalBlend* layerMaterialTarget;
    UMaterial* layerDrawMaterial;
    uint layerColorWord, layerLeftWord, layerTopWord, cachedRightWord, cachedBottomWord;
    float bottom;
    // The right spill reuses radarWidth; right/bottom words then stay cached across all three layers.
    __asm {
        fld dword ptr top
        mov eax,dword ptr HudRadarFinalBlend
        mov layerMaterialTarget,eax
        fadd dword ptr radarHeight
        mov eax,dword ptr radarColor
        mov layerColorWord,eax
        mov eax,dword ptr left
        mov layerLeftWord,eax
        fstp dword ptr bottom
        fld dword ptr left
        mov eax,dword ptr bottom
        mov cachedBottomWord,eax
        fadd dword ptr radarWidth
        mov edx,layerMaterialTarget
        mov eax,layerTexture
        mov dword ptr [edx+0x58],eax
        mov eax,dword ptr HudRadarFinalBlend
        mov layerDrawMaterial,eax
        mov eax,dword ptr top
        mov layerTopWord,eax
        fstp dword ptr radarWidth
        mov eax,dword ptr radarWidth
        mov cachedRightWord,eax
    }
    (*(DrawTileWordsCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(canvas,
        layerLeftWord, layerTopWord, cachedRightWord, cachedBottomWord,
        0, 0, 0x43000000, 0x43000000, 0x3f800000, layerDrawMaterial, layerColorWord);
    FCanvasUtil::Flush(canvas);
    layerTexture = radarHud->m_TexRadarTextures[1];
    layerMaterialTarget = HudRadarFinalBlend;
    layerColorWord = *(uint*)&radarColor;
    layerLeftWord = *(uint*)&left;
    layerMaterialTarget->Material = layerTexture;
    layerDrawMaterial = (UMaterial*)HudRadarFinalBlend;
    layerTopWord = *(uint*)&top;
    (*(DrawTileWordsCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(canvas,
        layerLeftWord, layerTopWord, cachedRightWord, cachedBottomWord,
        0, 0, 0x43000000, 0x43000000, 0x3f800000, layerDrawMaterial, layerColorWord);
    FCanvasUtil::Flush(canvas);
    layerTexture = radarHud->m_TexRadarTextures[2];
    layerMaterialTarget = HudRadarFinalBlend;
    layerMaterialTarget->Material = layerTexture;
    byte* layerColors = (byte*)radarHud->Colors;
    layerColorWord = *(uint*)(layerColors + 0x84); // HUDWhite.
    layerDrawMaterial = (UMaterial*)HudRadarFinalBlend;
    layerTopWord = *(uint*)&top;
    layerLeftWord = *(uint*)&left;
    (*(DrawTileWordsCall*)R6GameImports::Engine_FCanvasUtil_DrawTileSlot)(canvas,
        layerLeftWord, layerTopWord, cachedRightWord, cachedBottomWord,
        0, 0, 0x43000000, 0x43000000, 0x3f800000, layerDrawMaterial, layerColorWord);
    FCanvasUtil::Flush(canvas);
    alignas(4) byte coordsStorage[48], rotationStorage[12], matrixStorage[64];
    using MatrixCoordsCall = FCoords* (__thiscall *)(FMatrix*, FCoords*);
    FMatrix* viewMatrix = (FMatrix*)((byte*)scene + 0x10);
    MatrixCoordsCall getCoords = *(MatrixCoordsCall*)R6GameImports::Core_FMatrix_CoordsSlot;
    getCoords(viewMatrix, (FCoords*)coordsStorage);
    using OrthoRotationCall = FRotator* (__thiscall *)(const FCoords*, FRotator*);
    OrthoRotationCall getRotation = *(OrthoRotationCall*)R6GameImports::Core_FCoords_OrthoRotationSlot;
    getRotation((FCoords*)coordsStorage, (FRotator*)rotationStorage);
    uint* rotationWords = (uint*)rotationStorage;
    FMatrix* rotationDestination = (FMatrix*)matrixStorage;
    // Rewrite the fixed rotator and its outgoing copy in their native word order.
    __asm {
        mov edx,rotationWords
        mov eax,dword ptr [edx+0x4]
        sub esp,0xc
        mov edi,esp
        mov dword ptr [edi],0
        neg eax
        mov dword ptr [edx],0
        mov dword ptr [edi+0x4],eax
        mov ecx,rotationDestination
        mov dword ptr [edx+0x4],eax
        mov dword ptr [edx+0x8],0
        mov dword ptr [edi+0x8],0
        call BuildRotationMatrixFromAngles
    }
    float worldToRadarScale, radiusSquared, radius;
    double radiusDouble;
    uint viewportActorWord;
    uint sqrtSlotAddress = R6GameImports::Core_appSqrtSlot;
    // Keep the extended sqrt return across the viewport/actor captures and both independent spills.
    __asm {
        fld dword ptr HudCharacterPanelBorderInset
        fdiv dword ptr HudRadarWorldUnitsPerPixel
        sub esp,0x8
        fstp dword ptr worldToRadarScale
        fld dword ptr radarHeight
        fmul dword ptr HudRadarHalf
        fsub dword ptr halfMarkerX
        fld st(0)
        fmul st,st(1)
        fstp dword ptr radiusSquared
        fstp st(0)
        fld dword ptr radiusSquared
        fstp qword ptr [esp]
        mov eax,sqrtSlotAddress
        call dword ptr [eax]
        mov ecx,viewport
        fst qword ptr radiusDouble
        mov edx,dword ptr [ecx+0x34]
        mov viewportActorWord,edx
        fstp dword ptr radius
        add esp,0x8
    }
    AController* controller = (AController*)CastToAController((int)viewportActorWord);
    AR6Pawn* localPawn = (AR6Pawn*)CastToAR6Pawn((int)controller->Pawn);
    AR6HUD* markerScanHud = this;
    for (int actorIndex = 0;; actorIndex = (int)((uint)actorIndex + 1U)) {
        ULevel* level = markerScanHud->XLevel;
        int actorCount = *(int*)((byte*)level + 0x34);
        int savedActorIndex = actorIndex;
        if (actorIndex >= actorCount)
            break;
        AActor** actors = *(AActor***)((byte*)level + 0x30);
        AR6TeamMemberReplicationInfo* member =
            (AR6TeamMemberReplicationInfo*)CastToAR6TeamMemberReplicationInfo((int)actors[actorIndex]);
        if (member == nullptr)
            continue;
        AR6Pawn* filterPawn = localPawn;
        if (member == filterPawn->m_TeamMemberRepInfo || member->Instigator == filterPawn)
            continue;
        int memberTeam = member->m_iTeam;
        using FriendCall = int (__thiscall *)(APawn*, int);
        if ((*(FriendCall*)R6GameImports::Engine_APawn_IsFriendSlot)((APawn*)filterPawn, memberTeam) == 0)
            continue;
        uint* markerColorWord = (uint*)&viewport; // Native reuses the incoming viewport word for packed RGBA.
        ushort communicationStatus;
        __asm {
            mov ecx,member
            fld dword ptr [ecx+0x3a8]
            mov edx,markerColorWord
            mov byte ptr [edx],0xff
            fcomp dword ptr HudRadarZero
            mov byte ptr [edx+0x1],0xff
            mov byte ptr [edx+0x2],0xff
            mov byte ptr [edx+0x3],0xff
            fnstsw ax
            mov communicationStatus,ax
        }
        if ((communicationStatus & 0x4100U) == 0) {
            int blinkWord;
            __asm {
                mov ecx,member
                fld dword ptr [ecx+0x3a8]
                fadd st(0),st
                call ConvertX87ToSigned64
                mov blinkWord,eax
            }
            ((byte*)markerColorWord)[3] = (byte)(0x3f - ((blinkWord & 1) << 6));
        }
        const FVector* viewOrigin = (const FVector*)((byte*)scene + 0x190);
        FPlane relative;
        const float* components;
        const float* rotationMatrix;
        float transformed[4];
        // Retain Z/Y extended differences until X/Y/Z stores, then the native interleaved four-column multiply.
        __asm {
            mov eax,viewOrigin
            mov ebx,member
            fld dword ptr [ebx+0x3c0]
            fsub dword ptr [eax+0x8]
            lea edx,relative
            fld dword ptr [ebx+0x3bc]
            mov dword ptr [edx+0xc],0x3f800000
            fsub dword ptr [eax+0x4]
            mov components,edx
            fld dword ptr [ebx+0x3b8]
            fsub dword ptr [eax]
            lea eax,matrixStorage
            mov rotationMatrix,eax
            fstp dword ptr [edx]
            fstp dword ptr [edx+0x4]
            fstp dword ptr [edx+0x8]
            mov esi,components
            mov edx,rotationMatrix
            lea edi,transformed
            fld dword ptr [esi]
            fmul dword ptr [edx]
            fld dword ptr [esi]
            fmul dword ptr [edx+0x4]
            fld dword ptr [esi]
            fmul dword ptr [edx+0x8]
            fld dword ptr [esi]
            fmul dword ptr [edx+0xc]
            fld dword ptr [esi+0x4]
            fmul dword ptr [edx+0x10]
            fld dword ptr [esi+0x4]
            fmul dword ptr [edx+0x14]
            fld dword ptr [esi+0x4]
            fmul dword ptr [edx+0x18]
            fld dword ptr [esi+0x4]
            fmul dword ptr [edx+0x1c]
            fxch st(3)
            faddp st(7),st
            faddp st(4),st
            faddp st(4),st
            faddp st(1),st
            fld dword ptr [esi+0x8]
            fmul dword ptr [edx+0x20]
            fld dword ptr [esi+0x8]
            fmul dword ptr [edx+0x24]
            fld dword ptr [esi+0x8]
            fmul dword ptr [edx+0x28]
            fld dword ptr [esi+0x8]
            fmul dword ptr [edx+0x2c]
            fxch st(3)
            faddp st(7),st
            faddp st(4),st
            faddp st(4),st
            faddp st(1),st
            fld dword ptr [esi+0xc]
            fmul dword ptr [edx+0x30]
            fld dword ptr [esi+0xc]
            fmul dword ptr [edx+0x34]
            fld dword ptr [esi+0xc]
            fmul dword ptr [edx+0x38]
            fld dword ptr [esi+0xc]
            fmul dword ptr [edx+0x3c]
            fxch st(3)
            faddp st(7),st
            faddp st(4),st
            faddp st(4),st
            faddp st(1),st
            fxch st(3)
            fstp dword ptr [edi]
            fxch st(1)
            fstp dword ptr [edi+0x4]
            fstp dword ptr [edi+0x8]
            fstp dword ptr [edi+0xc]
        }
        FVector radarPosition;
        ushort planarStatus;
        __asm {
            lea esi,transformed
            lea edi,radarPosition
            mov ecx,dword ptr [esi]
            mov edx,dword ptr [esi+0x4]
            mov eax,dword ptr [esi+0x8]
            mov dword ptr [edi],ecx
            fld dword ptr [edi]
            fmul dword ptr worldToRadarScale
            mov dword ptr [edi+0x4],edx
            mov dword ptr [edi+0x8],eax
            push ecx
            fstp dword ptr [edi]
            fld dword ptr [edi+0x4]
            fmul dword ptr worldToRadarScale
            fstp dword ptr [edi+0x4]
            fld dword ptr [edi+0x8]
            fmul dword ptr worldToRadarScale
            fstp dword ptr [edi+0x8]
            fld dword ptr [edi+0x4]
            fmul dword ptr [edi+0x4]
            fld dword ptr [edi]
            fmul dword ptr [edi]
            faddp st(1),st
            fstp dword ptr [esp]
            call AbsFloat
            fcomp dword ptr radiusSquared
            add esp,0x4
            fnstsw ax
            mov planarStatus,ax
        }
        if ((planarStatus & 0x4100U) == 0) {
            FVector::Normalize(&radarPosition);
            __asm {
                lea eax,radarPosition
                fld dword ptr [eax]
                fmul dword ptr radius
                fstp dword ptr [eax]
                fld dword ptr [eax+0x4]
                fmul dword ptr radius
                fstp dword ptr [eax+0x4]
                fld dword ptr [eax+0x8]
                fmul dword ptr radius
                fstp dword ptr [eax+0x8]
            }
        }
        byte textureIndex = 4;
        byte markerHealth = *(byte*)((byte*)member + 0x397);
        if (markerHealth >= 2) {
            textureIndex = 3;
        } else {
            ushort heightStatus;
            __asm {
                mov ecx,member
                fld dword ptr [ecx+0x3c0]
                mov edx,scene
                fsub dword ptr [edx+0x198]
                fcom dword ptr HudRadarAboveLevelThreshold
                fnstsw ax
                mov heightStatus,ax
            }
            if ((heightStatus & 0x4100U) == 0) {
                __asm { fstp st(0) }
                textureIndex = 5;
            } else {
                __asm {
                    fcomp dword ptr HudRadarBelowLevelThreshold
                    fnstsw ax
                    mov heightStatus,ax
                }
                if ((heightStatus & 0x0500U) == 0x0100U)
                    textureIndex = 6;
            }
            if ((*(byte*)((byte*)member + 0x3a4) & 4U) != 0)
                textureIndex = (byte)(textureIndex + 3);
        }
        UMaterial* markerTexture = radarHud->m_TexRadarTextures[textureIndex];
        UFinalBlend* markerMaterialTarget = HudRadarFinalBlend;
        uint markerColorValue = *markerColorWord;
        float* markerPosition = (float*)&radarPosition;
        uint markerDrawSlotAddress = R6GameImports::Engine_FCanvasUtil_DrawTileSlot;
        // Capture color before Material changes, then store bottom/right/top/left directly into the outgoing packet.
        __asm {
            mov eax,markerColorValue
            push eax
            mov eax,markerMaterialTarget
            mov edx,markerTexture
            mov dword ptr [eax+0x58],edx
            mov edx,dword ptr HudRadarFinalBlend
            mov esi,markerPosition
            fld dword ptr [esi+0x4]
            push edx
            fadd dword ptr halfMarkerY
            push 0x3f800000
            push 0x42000000
            push 0x42000000
            fadd dword ptr centerY
            push 0
            push 0
            sub esp,0x10
            mov ecx,canvas
            fstp dword ptr [esp+0xc]
            fld dword ptr [esi]
            fadd dword ptr halfMarkerX
            fadd dword ptr centerX
            fstp dword ptr [esp+0x8]
            fld dword ptr [esi+0x4]
            fadd dword ptr centerY
            fsub dword ptr halfMarkerY
            fstp dword ptr [esp+0x4]
            fld dword ptr [esi]
            fadd dword ptr centerX
            fsub dword ptr halfMarkerX
            fstp dword ptr [esp]
            mov eax,markerDrawSlotAddress
            call dword ptr [eax]
        }
        FCanvasUtil::Flush(canvas);
        markerScanHud = radarHud;
        actorIndex = savedActorIndex;
    }
    *(byte*)&exceptionRegistration.state = 0;
    FCanvasUtil::~FCanvasUtil(canvas);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 1000ffe2 : rethrow DrawRadar's caught four-byte value
__declspec(naked) void AR6HUD_DrawRadarCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x84]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x60]
        push ecx
        mov dword ptr [ebp-0x60],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000fff9 : report DrawRadar context and rethrow the active exception
__declspec(naked) void AR6HUD_DrawRadarCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawRadarExceptionContext // L"AR6HUD::DrawRadar"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100100d0 : DrawInGameMap
// Draws cached pawn markers, remaining team routes and multiplayer member markers on the planning map.
void __thiscall AR6HUD::DrawInGameMap(AR6HUD* this, FCameraSceneNode* scene, UViewport* viewport)
{
    using ClipCall = void (__thiscall *)(UCanvas*, int, int, int, int);
    using RenderStateCall = void (__thiscall *)(FRenderInterface*);
    using RenderState24Call = void (__thiscall *)(FRenderInterface*, int, int, int, void*, int, FPlane);
    using RenderState2cCall = void (__thiscall *)(FRenderInterface*, uint, uint, uint, FColor);
    using TransformCall = void (__thiscall *)(FRenderInterface*, int, FMatrix);
    using LineCheckCall = int (__thiscall *)(ULevel*, FCheckResult*, AActor*, const FVector*,
        const FVector*, uint, FVector);
    using TextMeasureCall = void (__cdecl *)(UCanvas*, UFont*, int*, int*, const ushort*, ...);
    using TextCall = void (__cdecl *)(UCanvas*, UFont*, int, const ushort*, ...);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6HUD_DrawInGameMapExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Native cleanup regions: iterator -0x74, batchers -0x184/-0x144, canvas -0xe90.
    ULevel* initialLevel = viewport->Actor->XLevel;
    exceptionRegistration.state = 0;
    byte* mapState = (byte*)&exceptionRegistration.state;
    ALevelInfo* initialLevelInfo = ULevel::GetLevelInfo(initialLevel);
    uint initialPlanningFlags = *(uint*)((byte*)initialLevelInfo + 0x450);
    if ((initialPlanningFlags & 0x1000U) == 0) {
        __writefsdword(0, exceptionRegistration.previousAddress);
        return;
    }
    UCanvas* savedCanvas = viewport->Canvas;
    int savedStretchX, savedStretchY, savedOrgX, savedOrgY, savedClipX, savedClipY;
    __asm {
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x94]
        call ConvertX87ToSigned64
        mov savedStretchX, eax
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x98]
        call ConvertX87ToSigned64
        mov savedStretchY, eax
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x38]
        call ConvertX87ToSigned64
        mov savedOrgX, eax
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x3c]
        call ConvertX87ToSigned64
        mov savedOrgY, eax
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x40]
        call ConvertX87ToSigned64
        mov savedClipX, eax
        mov ecx, savedCanvas
        fld dword ptr [ecx + 0x44]
        call ConvertX87ToSigned64
        mov savedClipY, eax
    }
    savedCanvas->m_fStretchX = 1.0f;
    viewport->Canvas->m_fStretchY = 1.0f;
    long double clipWidth = (long double)viewport->SizeX;
    int clipHeight = viewport->SizeY;
    UCanvas* clipCanvas = viewport->Canvas;
    byte* clipVtable = *(byte**)clipCanvas;
    clipWidth += clipWidth;
    int doubledViewportWidth;
    __asm {
        fld clipWidth
        call ConvertX87ToSigned64
        mov doubledViewportWidth, eax
    }
    (*(ClipCall*)(clipVtable + 0x88))(clipCanvas, 0, 0, doubledViewportWidth, clipHeight);
    APawn* viewPawn = (APawn*)((APlayerController*)viewport->Actor)->ViewTarget;
    if (viewPawn == nullptr || UObject::IsA((UObject*)viewPawn, *(UClass**)R6GameImports::Engine_APawn_PrivateStaticClassSlot) == 0)
        viewPawn = nullptr;
    UObject* pawnIcon = UObject::StaticFindObject(*(UClass**)R6GameImports::Engine_UTexture_PrivateStaticClassSlot, (UObject*)0xffffffff,
        (ushort*)L"R6Planning.InGamePlanning.PawnIcon", 0);
    if (pawnIcon != nullptr && UObject::IsA(pawnIcon, *(UClass**)R6GameImports::Engine_UTexture_PrivateStaticClassSlot) != 0) {
        FRenderInterface* renderInterface = *(FRenderInterface**)((byte*)viewport + 0x164);
        (*(RenderStateCall*)*(byte**)renderInterface)(renderInterface);
        FVector renderPlaneXYZ = *(FVector*)ImportedVectorZeroAddress;
        renderInterface = *(FRenderInterface**)((byte*)viewport + 0x164);
        (*(RenderState24Call*)(*(byte**)renderInterface + 0x24))(renderInterface,
            0, 0, 0, nullptr, 0, FPlane(renderPlaneXYZ.X, renderPlaneXYZ.Y, renderPlaneXYZ.Z, 0.0f));
        FColor markerColor(0, 0, 0, 255);
        renderInterface = *(FRenderInterface**)((byte*)viewport + 0x164);
        (*(RenderState2cCall*)(*(byte**)renderInterface + 0x2c))(renderInterface, 0, 0, 0, markerColor);
        alignas(4) byte markerBatchStorage[0x24], routeBatchStorage[0x24], canvasStorage[0xca8];
        FLineBatcher* markerBatch = (FLineBatcher*)markerBatchStorage;
        FLineBatcher* routeBatch = (FLineBatcher*)routeBatchStorage;
        FCanvasUtil* canvasUtil = (FCanvasUtil*)canvasStorage;
        // Resets the current renderer's transform using the complete selected identity matrix.
        auto setIdentityTransform = [&]() {
            FRenderInterface* currentRI = *(FRenderInterface**)((byte*)viewport + 0x164);
            FMatrix identity = *(const FMatrix*)ImportedMatrixIdentityAddress;
            (*(TransformCall*)(*(byte**)currentRI + 0x34))(currentRI, 0, identity);
        };
        // Interprets the hit's selected terrain item, BSP node surface or actor floor.
        auto floorFromHit = [&](byte* hit, ALevelInfo* levelInfo, bool useInitialLevel) -> int {
            AActor* hitActor = *(AActor**)(hit + 4);
            if ((AActor*)levelInfo == hitActor) {
                int hitItem = *(int*)(hit + 0x28);
                if (hitItem == -1)
                    return -1;
                ULevel* modelLevel = useInitialLevel ? initialLevel : viewport->Actor->XLevel;
                UModel* model = *(UModel**)((byte*)modelLevel + 0x90);
                if (hitItem >= *(int*)((byte*)model + 0x60))
                    return -1;
                if (!useInitialLevel)
                    model = *(UModel**)((byte*)viewport->Actor->XLevel + 0x90);
                byte* nodeDataAt5c = *(byte**)((byte*)model + 0x5c);
                byte* node = (byte*)((uint)nodeDataAt5c + (uint)hitItem * 0x90U);
                uint surfaceIndex = *(uint*)(node + 0x34);
                byte* surfaceDataAt9c = *(byte**)((byte*)model + 0x9c);
                return *(int*)((uint)surfaceDataAt9c + surfaceIndex * 0x5cU + 0x48U);
            }
            UClass* cursor = *(UClass**)((byte*)hitActor + 0x24);
            UClass* terrainClass = *(UClass**)R6GameImports::Engine_ATerrainInfo_PrivateStaticClassSlot;
            while (cursor != nullptr && cursor != terrainClass)
                cursor = *(UClass**)((byte*)cursor + 0x2c);
            if (cursor == terrainClass)
                return *(int*)(hit + 0x28);
            return hitActor->m_iPlanningFloor_0;
        };
        // Projects a camera-up-offset label and draws a zoom-limited UTF-16 prefix above its marker.
        auto drawLabel = [&](FVector* markerLocation, FString* name, byte canvasState, byte batchState) {
            alignas(4) byte coordsStorage[48];
            FRotator* cameraRotationAt1d0 = (FRotator*)((byte*)scene + 0x1d0);
            using DivideCoordsCall = FCoords* (__thiscall *)(const FCoords*, FCoords*, const FRotator*);
            (*(DivideCoordsCall*)R6GameImports::Core_FCoords_OperatorDivideSlot)((FCoords*)((byte*)ImportedGMathAddress + 0x18),
                (FCoords*)coordsStorage, cameraRotationAt1d0);
            FVector* upAxisAt24 = (FVector*)((byte*)coordsStorage + 0x24);
            float scaledX = (float)((long double)upAxisAt24->X * 38.0f);
            FVector labelLocation;
            labelLocation.Z = (float)((long double)upAxisAt24->Z * 38.0f + markerLocation->Z);
            labelLocation.Y = (float)((long double)upAxisAt24->Y * 38.0f + markerLocation->Y);
            labelLocation.X = (float)((long double)scaledX + markerLocation->X);
            FCanvasUtil::FCanvasUtil(canvasUtil, viewport,
                *(FRenderInterface**)((byte*)viewport + 0x164), 1, 0);
            FVector flattened(labelLocation.X, labelLocation.Y, (float)((long double)labelLocation.Z * 0.0f));
            FPlane projectionStorage;
            using ProjectCall = FPlane* (__thiscall *)(FSceneNode*, FPlane*, FVector);
            *mapState = canvasState;
            (*(ProjectCall*)R6GameImports::Engine_FSceneNode_ProjectSlot)((FSceneNode*)scene, &projectionStorage, flattened);
            FPlane projectedInput(projectionStorage.X, projectionStorage.Y, projectionStorage.Z, 1.0f);
            const float* input = (const float*)&projectedInput;
            const float* matrixAt14 = (const float*)((byte*)canvasUtil + 0x14);
            float screen[4];
            for (int column = 0; column < 4; ++column) {
                long double component = (long double)input[0] * matrixAt14[column];
                component += (long double)input[1] * matrixAt14[4 + column];
                component += (long double)input[2] * matrixAt14[8 + column];
                component += (long double)input[3] * matrixAt14[12 + column];
                screen[column] = (float)component;
            }
            long double nameLimitValue = 8192.0L / initialLevelInfo->m_fInGamePlanningZoomDistance;
            int nameLimit;
            __asm {
                fld nameLimitValue
                call ConvertX87ToSigned64
                mov nameLimit, eax
            }
            if (nameLimit < 3)
                nameLimit = 3;
            else if (nameLimit >= 16)
                nameLimit = 16;
            ushort namePrefix[16];
            appMemset(namePrefix, 0, 32);
            const ushort* nameData = FString::operator*(name);
            CopyMemoryForward(namePrefix, nameData, nameLimit * 2);
            viewport->Canvas->Style = 5;
            viewport->Canvas->CurX = 0.0f;
            viewport->Canvas->CurY = 0.0f;
            UCanvas* textCanvas = viewport->Canvas;
            int measuredWidth, measuredHeight;
            (*(TextMeasureCall*)(*(byte**)textCanvas + 0x80))(textCanvas, textCanvas->SmallFont,
                &measuredWidth, &measuredHeight, namePrefix);
            viewport->Canvas->CurX = (float)((long double)screen[0] - (measuredWidth >> 1));
            viewport->Canvas->CurY = (float)((long double)screen[1] - measuredHeight);
            viewport->Canvas->DrawColor = FColor(255, 255, 255, 255);
            textCanvas = viewport->Canvas;
            (*(TextCall*)(*(byte**)textCanvas + 0x84))(textCanvas, textCanvas->SmallFont, 0, namePrefix);
            *mapState = batchState;
            FCanvasUtil::~FCanvasUtil(canvasUtil);
        };
        // Draws one route edge with float-spilled Z products and the planning object's live team color.
        auto drawRouteLine = [&](AActor* start, AActor* end, UR6AbstractPlanningInfo* planning) {
            FVector endLocation(end->Location.X, end->Location.Y, (float)((long double)end->Location.Z * 0.0f));
            FColor color = planning->m_TeamColor;
            FVector startLocation(start->Location.X, start->Location.Y,
                (float)((long double)start->Location.Z * 0.0f));
            FLineBatcher::DrawLine(routeBatch, startLocation, endLocation, color);
        };
        byte netMode = initialLevelInfo->NetMode;
        if (netMode == 0) {
            void* pawnMapAt101f8 = (byte*)initialLevel + 0x101f8;
            if (viewPawn != nullptr) {
                uint objectIndexAt20 = *(uint*)((byte*)viewPawn + 0x20);
                uint value[2] = {(uint)viewPawn, 0};
                UpsertHashMapEntry(pawnMapAt101f8, &objectIndexAt20, value);
            }
            alignas(4) uint iteratorWords[4] = {(uint)pawnMapAt101f8, (uint)pawnMapAt101f8, 0, 0};
            void* map = (void*)iteratorWords[1];
            int entryIndex = 0;
            *mapState = 1;
            while (entryIndex < *(int*)((byte*)map + 4)) {
                byte* entryValue = (byte*)(*(uint*)map + (uint)entryIndex * 16U + 8U);
                AR6Pawn* pawn = *(AR6Pawn**)entryValue;
                if (pawn == nullptr || UObject::IsA((UObject*)pawn, (UClass*)ImportedAR6PawnClass) == 0)
                    pawn = nullptr;
                float* entryAge = (float*)(entryValue + 4);
                UEngine* currentEngine = *(UEngine**)Importedg_pEngineAddress;
                long double updatedAge = (long double)*(float*)((byte*)currentEngine + 0x94) + *entryAge;
                *entryAge = (float)updatedAge;
                if (updatedAge > 4.0f) {
                    int removedIndex = entryIndex;
                    iteratorWords[2] = (uint)entryIndex - 1U;
                    RemoveHashMapEntriesChecked(map, removedIndex, 1);
                    iteratorWords[3] += 1U;
                    iteratorWords[2] += 1U;
                } else {
                    if ((APawn*)pawn != viewPawn) {
                        FVector traceStart = pawn->Location;
                        FVector traceEnd(traceStart.X, traceStart.Y, (float)((long double)traceStart.Z - 128.0f));
                        alignas(4) byte floorHit[48];
                        *(uint*)(floorHit + 0x2c) = 0;
                        ULevel* traceLevel = viewport->Actor->XLevel;
                        LineCheckCall lineCheck = *(LineCheckCall*)(*(byte**)traceLevel + 0xcc);
                        if (lineCheck(traceLevel, (FCheckResult*)floorHit, (AActor*)pawn,
                            &traceEnd, &traceStart, 0x1094, *(const FVector*)ImportedVectorZeroAddress) == 0) {
                            ALevelInfo* traceLevelInfo = ULevel::GetLevelInfo(viewport->Actor->XLevel);
                            int floor = floorFromHit(floorHit, traceLevelInfo, false);
                            if (floor != -1)
                                pawn->m_iCurrentFloor = floor;
                        }
                    }
                    if (pawn->m_iCurrentFloor == *(int*)((byte*)viewport + 0x1f4)) {
                        byte pawnType = pawn->m_ePawnType;
                        AR6RainbowTeam* team = nullptr;
                        if (pawnType == 1) {
                            if (pawn->m_bIsPlayer) {
                                AR6PlayerController* player = (AR6PlayerController*)CastToAR6PlayerController(
                                    (int)pawn->Controller);
                                if (player != nullptr)
                                    team = player->m_TeamManager;
                            } else {
                                AR6RainbowAI* ai = (AR6RainbowAI*)CastToAR6RainbowAI((int)pawn->Controller);
                                if (ai != nullptr)
                                    team = ai->m_TeamManager;
                            }
                        }
                        if (pawnType == 1) {
                            if (team != nullptr)
                                markerColor = team->Colors->TeamHUDColor[team->m_iRainbowTeamName];
                            else
                                markerColor = FColor(128, 128, 128, 255);
                        } else if (pawnType == 2) {
                            markerColor = FColor(255, 0, 255, 255);
                        } else if (pawnType == 3) {
                            markerColor = FColor(255, 255, 255, 255);
                        }
                        if (APawn::IsAlive((APawn*)pawn) == 0) {
                            markerColor.R >>= 1;
                            markerColor.G >>= 1;
                            markerColor.B >>= 1;
                        }
                        float fadeInput = (float)(((long double)*entryAge - 1.0f) * 0.3333333432674408f);
                        long double fade = ClampFloat(fadeInput, 0.0f, 1.0f);
                        long double alphaValue = 255.0L - fade * 255.0f;
                        uint alphaBits;
                        __asm {
                            fld alphaValue
                            call ConvertX87ToSigned64
                            mov alphaBits, eax
                        }
                        markerColor.A = (byte)alphaBits;
                        setIdentityTransform();
                        FLineBatcher::FLineBatcher(markerBatch,
                            *(FRenderInterface**)((byte*)viewport + 0x164), 0, 0);
                        FVector* markerLocation = &pawn->Location;
                        FVector circleLocation = *markerLocation;
                        *mapState = 2;
                        FLineBatcher::DrawCircle(markerBatch, circleLocation, FVector(1.0f, 0.0f, 0.0f),
                            FVector(0.0f, 1.0f, 0.0f), markerColor, 38.0f, 64);
                        FRotator heading(0, pawn->Rotation.Yaw, 0);
                        FVector headingStorage;
                        FVector* headingVector = FRotator::Vector(&heading, &headingStorage);
                        float scaledY = (float)((long double)headingVector->Y * 38.0f);
                        float scaledX = (float)((long double)headingVector->X * 38.0f);
                        FVector headingEnd;
                        headingEnd.Z = (float)((long double)headingVector->Z * 38.0f + markerLocation->Z);
                        headingEnd.Y = (float)((long double)scaledY + markerLocation->Y);
                        headingEnd.X = (float)((long double)scaledX + markerLocation->X);
                        FLineBatcher::DrawLine(markerBatch, *markerLocation, headingEnd, markerColor);
                        FLineBatcher::Flush(markerBatch, 0);
                        if (pawn->m_ePawnType == 1) {
                            markerColor = FColor(255, 255, 255, 255);
                            if (APawn::IsAlive((APawn*)pawn) == 0) {
                                markerColor.R >>= 1;
                                markerColor.G >>= 1;
                                markerColor.B >>= 1;
                            }
                            drawLabel(markerLocation, (FString*)&pawn->m_CharacterName, 3, 2);
                        }
                        *mapState = 1;
                        FLineBatcher::~FLineBatcher(markerBatch);
                    }
                    iteratorWords[2] += 1U;
                }
                entryIndex = (int)iteratorWords[2];
                map = (void*)iteratorWords[1];
            }
            *mapState = 0;
            ShrinkHashMapIfSparse(iteratorWords);
            for (int teamIndex = 0; teamIndex < 3; ++teamIndex) {
                UViewport* sceneViewport = *(UViewport**)((byte*)scene + 4);
                AR6StartGameInfo* startGameInfo = sceneViewport->InteractionMaster->m_StartGameInfo;
                UR6AbstractPlanningInfo* planning = startGameInfo->m_TeamInfo[teamIndex]->m_pPlanning;
                using LeaderCall = AActor* (__thiscall *)(UR6AbstractPlanningInfo*);
                AActor* leader = (*(LeaderCall*)(*(byte**)planning + 0x6c))(planning);
                sceneViewport = *(UViewport**)((byte*)scene + 4);
                FLineBatcher::FLineBatcher(routeBatch,
                    *(FRenderInterface**)((byte*)sceneViewport + 0x164), 0, 0);
                *mapState = 4;
                bool hasMembers = false;
                if (leader != nullptr) {
                    sceneViewport = *(UViewport**)((byte*)scene + 4);
                    startGameInfo = sceneViewport->InteractionMaster->m_StartGameInfo;
                    hasMembers = startGameInfo->m_TeamInfo[teamIndex]->m_iNumberOfMembers != 0;
                }
                if (hasMembers && planning->m_iCurrentNode != -1) {
                    int nextNodeIndex = planning->m_iCurrentNode;
                    AActor** nodeData = *(AActor***)&planning->m_NodeList;
                    AR6ActionPointAbstract* currentPoint = (AR6ActionPointAbstract*)CastToAR6ActionPointAbstract(
                        (int)nodeData[nextNodeIndex]);
                    int currentPathIndex = planning->m_iCurrentPathIndex;
                    if (currentPathIndex == -1) {
                        if (((APawn*)leader)->m_iCurrentFloor == *(int*)((byte*)viewport + 0x1f4))
                            drawRouteLine(leader, (AActor*)currentPoint, planning);
                    } else {
                        nextNodeIndex = (int)((uint)nextNodeIndex + 1U);
                        if (((APawn*)leader)->m_iCurrentFloor == *(int*)((byte*)viewport + 0x1f4)) {
                            AActor** pathData = *(AActor***)&currentPoint->m_PathToNextPoint;
                            drawRouteLine(leader, pathData[currentPathIndex], planning);
                        }
                        for (int pathIndex = planning->m_iCurrentPathIndex;
                            pathIndex < (int)((uint)*(int*)((byte*)&currentPoint->m_PathToNextPoint + 4) - 1U);
                            pathIndex = (int)((uint)pathIndex + 1U)) {
                            AActor** pathData = *(AActor***)&currentPoint->m_PathToNextPoint;
                            AActor* pathActor = pathData[pathIndex];
                            int viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                            if (pathActor->m_iPlanningFloor_0 == viewportFloor ||
                                pathActor->m_iPlanningFloor_1 == viewportFloor) {
                                pathData = *(AActor***)&currentPoint->m_PathToNextPoint;
                                AActor* end = pathData[(int)((uint)pathIndex + 1U)];
                                AActor* start = pathData[pathIndex];
                                drawRouteLine(start, end, planning);
                            }
                        }
                        if (nextNodeIndex != *(int*)((byte*)&planning->m_NodeList + 4)) {
                            nodeData = *(AActor***)&planning->m_NodeList;
                            AR6ActionPointAbstract* nextPoint = (AR6ActionPointAbstract*)CastToAR6ActionPointAbstract(
                                (int)nodeData[nextNodeIndex]);
                            int viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                            if (nextPoint->m_iPlanningFloor_0 == viewportFloor ||
                                nextPoint->m_iPlanningFloor_1 == viewportFloor) {
                                AActor** pathData = *(AActor***)&currentPoint->m_PathToNextPoint;
                                int lastPathIndex =
                                    (int)((uint)*(int*)((byte*)&currentPoint->m_PathToNextPoint + 4) - 1U);
                                drawRouteLine((AActor*)nextPoint, pathData[lastPathIndex], planning);
                            }
                        }
                    }
                    for (int nodeIndex = nextNodeIndex;
                        nodeIndex < *(int*)((byte*)&planning->m_NodeList + 4);
                        nodeIndex = (int)((uint)nodeIndex + 1U)) {
                        nodeData = *(AActor***)&planning->m_NodeList;
                        AActor* nodeActor = nodeData[nodeIndex];
                        UClass* classCursor = nodeActor == nullptr ? nullptr : *(UClass**)((byte*)nodeActor + 0x24);
                        UClass* pointClass = ImportedAR6ActionPointAbstractClass;
                        while (classCursor != nullptr && classCursor != pointClass)
                            classCursor = *(UClass**)((byte*)classCursor + 0x2c);
                        AR6ActionPointAbstract* point = classCursor == pointClass ?
                            (AR6ActionPointAbstract*)nodeActor : nullptr;
                        int pathCount = *(int*)((byte*)&point->m_PathToNextPoint + 4);
                        if (pathCount == 0) {
                            int lastNodeIndex = (int)((uint)*(int*)((byte*)&planning->m_NodeList + 4) - 1U);
                            if (nodeIndex != lastNodeIndex) {
                                nodeData = *(AActor***)&planning->m_NodeList;
                                AR6ActionPointAbstract* nextPoint =
                                    (AR6ActionPointAbstract*)CastToAR6ActionPointAbstract(
                                        (int)nodeData[(int)((uint)nodeIndex + 1U)]);
                                int viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                                if (nextPoint->m_iPlanningFloor_0 == viewportFloor ||
                                    nextPoint->m_iPlanningFloor_1 == viewportFloor)
                                    drawRouteLine((AActor*)point, (AActor*)nextPoint, planning);
                            }
                        } else {
                            int viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                            if (point->m_iPlanningFloor_0 == viewportFloor ||
                                point->m_iPlanningFloor_1 == viewportFloor) {
                                AActor* firstPathActor = **(AActor***)&point->m_PathToNextPoint;
                                drawRouteLine((AActor*)point, firstPathActor, planning);
                            }
                            for (int pathIndex = 0;
                                pathIndex < (int)((uint)*(int*)((byte*)&point->m_PathToNextPoint + 4) - 1U);
                                pathIndex = (int)((uint)pathIndex + 1U)) {
                                AActor** pathData = *(AActor***)&point->m_PathToNextPoint;
                                AActor* pathActor = pathData[pathIndex];
                                viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                                if (pathActor->m_iPlanningFloor_0 == viewportFloor ||
                                    pathActor->m_iPlanningFloor_1 == viewportFloor) {
                                    pathData = *(AActor***)&point->m_PathToNextPoint;
                                    AActor* end = pathData[(int)((uint)pathIndex + 1U)];
                                    AActor* start = pathData[pathIndex];
                                    drawRouteLine(start, end, planning);
                                }
                            }
                            int lastNodeIndex = (int)((uint)*(int*)((byte*)&planning->m_NodeList + 4) - 1U);
                            if (nodeIndex != lastNodeIndex) {
                                nodeData = *(AActor***)&planning->m_NodeList;
                                nodeActor = nodeData[(int)((uint)nodeIndex + 1U)];
                                classCursor = nodeActor == nullptr ? nullptr : *(UClass**)((byte*)nodeActor + 0x24);
                                UClass* nextPointClass = nodeActor == nullptr ? nullptr :
                                    ImportedAR6ActionPointAbstractClass;
                                while (classCursor != nullptr && classCursor != nextPointClass)
                                    classCursor = *(UClass**)((byte*)classCursor + 0x2c);
                                AR6ActionPointAbstract* nextPoint = classCursor == nextPointClass ?
                                    (AR6ActionPointAbstract*)nodeActor : nullptr;
                                viewportFloor = *(int*)((byte*)viewport + 0x1f4);
                                if (nextPoint->m_iPlanningFloor_0 == viewportFloor ||
                                    nextPoint->m_iPlanningFloor_1 == viewportFloor) {
                                    AActor** pathData = *(AActor***)&point->m_PathToNextPoint;
                                    int lastPathIndex = (int)((uint)*(int*)((byte*)&point->m_PathToNextPoint + 4) - 1U);
                                    drawRouteLine((AActor*)nextPoint, pathData[lastPathIndex], planning);
                                }
                            }
                        }
                    }
                }
                FLineBatcher::Flush(routeBatch, 0);
                *mapState = 0;
                FLineBatcher::~FLineBatcher(routeBatch);
            }
        } else if (netMode == 2 || netMode == 3) {
            AActor* viewportActor = viewport->Actor;
            AController* controller = (AController*)CastToAController((int)viewportActor);
            AR6Pawn* replicationViewPawn =
                (AR6Pawn*)CastToAR6Pawn((int)((APlayerController*)viewportActor)->ViewTarget);
            APlayerReplicationInfo* viewerReplication = replicationViewPawn != nullptr ?
                replicationViewPawn->PlayerReplicationInfo : controller->PlayerReplicationInfo;
            if (viewerReplication != nullptr) {
                int viewerTeam = viewerReplication->TeamID;
                bool showAllTeams = viewerTeam == 0 || viewerTeam == 4;
                if (showAllTeams)
                    viewerTeam = -1;
                for (int actorIndex = 0; actorIndex < *(int*)((byte*)initialLevel + 0x34);
                    actorIndex = (int)((uint)actorIndex + 1U)) {
                    AActor** actorData = *(AActor***)((byte*)initialLevel + 0x30);
                    AR6TeamMemberReplicationInfo* member =
                        (AR6TeamMemberReplicationInfo*)CastToAR6TeamMemberReplicationInfo((int)actorData[actorIndex]);
                    if (member == nullptr || (!showAllTeams && member->m_iTeam != viewerTeam))
                        continue;
                    if (replicationViewPawn != nullptr && replicationViewPawn->m_TeamMemberRepInfo != member) {
                        FVector traceStart = member->m_Location;
                        FVector traceEnd(traceStart.X, traceStart.Y, (float)((long double)traceStart.Z - 128.0f));
                        alignas(4) byte floorHit[48];
                        *(uint*)(floorHit + 0x2c) = 0;
                        ULevel* traceLevel = viewport->Actor->XLevel;
                        LineCheckCall lineCheck = *(LineCheckCall*)(*(byte**)traceLevel + 0xcc);
                        int memberFloor = -1;
                        if (lineCheck(traceLevel, (FCheckResult*)floorHit, nullptr,
                            &traceEnd, &traceStart, 0x1094, *(const FVector*)ImportedVectorZeroAddress) == 0) {
                            int floor = floorFromHit(floorHit, initialLevelInfo, true);
                            if (floor != -1)
                                memberFloor = floor;
                        }
                        if (memberFloor != *(int*)((byte*)viewport + 0x1f4))
                            continue;
                    }
                    FColor replicationColor(255, 255, 255, 255);
                    if (member->m_fLastCommunicationTime > 0.0f) {
                        long double blinkValue = (long double)member->m_fLastCommunicationTime * 2.0L;
                        uint blinkBits;
                        __asm {
                            fld blinkValue
                            call ConvertX87ToSigned64
                            mov blinkBits, eax
                        }
                        replicationColor.A = (byte)(63U - ((blinkBits & 1U) << 6));
                    }
                    if (member->m_eHealth >= 2)
                        replicationColor.R = replicationColor.G = replicationColor.B = 127;
                    setIdentityTransform();
                    FLineBatcher::FLineBatcher(markerBatch,
                        *(FRenderInterface**)((byte*)viewport + 0x164), 0, 0);
                    FVector* markerLocation = &member->m_Location;
                    FVector circleLocation = *markerLocation;
                    *mapState = 5;
                    FLineBatcher::DrawCircle(markerBatch, circleLocation, FVector(1.0f, 0.0f, 0.0f),
                        FVector(0.0f, 1.0f, 0.0f), replicationColor, 38.0f, 64);
                    FRotator heading(0, (uint)member->m_RotationYaw << 8, 0);
                    FVector headingStorage;
                    FVector* headingVector = FRotator::Vector(&heading, &headingStorage);
                    float scaledY = (float)((long double)headingVector->Y * 38.0f);
                    float scaledX = (float)((long double)headingVector->X * 38.0f);
                    FVector headingEnd;
                    headingEnd.Z = (float)((long double)headingVector->Z * 38.0f + markerLocation->Z);
                    headingEnd.Y = (float)((long double)scaledY + markerLocation->Y);
                    headingEnd.X = (float)((long double)scaledX + markerLocation->X);
                    FLineBatcher::DrawLine(markerBatch, *markerLocation, headingEnd, replicationColor);
                    FLineBatcher::Flush(markerBatch, 0);
                    replicationColor = FColor(255, 255, 255, 255);
                    if (member->m_eHealth >= 2)
                        replicationColor.R = 127; // The subsequent label uses Canvas.DrawColor instead.
                    drawLabel(markerLocation, (FString*)&member->m_CharacterName, 6, 5);
                    *mapState = 0;
                    FLineBatcher::~FLineBatcher(markerBatch);
                }
            }
        }
        renderInterface = *(FRenderInterface**)((byte*)viewport + 0x164);
        (*(RenderStateCall*)(*(byte**)renderInterface + 4))(renderInterface);
    }
    viewport->Canvas->m_fStretchX = (float)savedStretchX;
    viewport->Canvas->m_fStretchY = (float)savedStretchY;
    viewport->Canvas->OrgX = (float)savedOrgX;
    viewport->Canvas->OrgY = (float)savedOrgY;
    viewport->Canvas->ClipX = (float)savedClipX;
    viewport->Canvas->ClipY = (float)savedClipY;
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100119b7 : rethrow the planning-map catch's UTF-16 pointer value
__declspec(naked) void AR6HUD_DrawInGameMapCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x188]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x158]
        push ecx
        mov dword ptr [ebp-0x158],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 100119d4 : report planning-map context and rethrow the active exception
__declspec(naked) void AR6HUD_DrawInGameMapCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6HUD_DrawInGameMapExceptionContext // L"AR6HUD::DrawInGameMap"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100139e0 : destroy base while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractHUD_DestructorSlot // AR6AbstractHUD destructor.
    }
}

// R6Game.dll @ 100139e9 : destroy m_aIOBombs while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5b0 // m_aIOBombs.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 100139f7 : destroy m_szMovementMode while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6a8 // m_szMovementMode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013a06 : destroy m_szTeamState while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6b4 // m_szTeamState.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013a15 : destroy m_szOtherTeamState while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind4(void)
{
    __asm {
        mov eax,ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor callback.
        push eax
        push 0x2
        push 0xc
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6c0 // m_szOtherTeamState.
        push ecx
        call R6GameAddresses::eh_vector_destructor_iterator // Callee removes the four iterator arguments.
        ret
    }
}

// R6Game.dll @ 10013a2f : destroy m_aszOtherTeamName while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind5(void)
{
    __asm {
        mov eax,ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor callback.
        push eax
        push 0x2
        push 0xc
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6d8 // m_aszOtherTeamName.
        push ecx
        call R6GameAddresses::eh_vector_destructor_iterator // Callee removes the four iterator arguments.
        ret
    }
}

// R6Game.dll @ 10013a49 : destroy m_szLastPlayerAPAction while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6f0 // m_szLastPlayerAPAction.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013a58 : destroy m_szPressGoCode while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6fc // m_szPressGoCode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013a67 : destroy m_szTeam while unwinding the HUD destructor
__declspec(naked) void AR6HUD_DestructUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x708 // m_szTeam.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013a80 : destroy base while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractHUD_DestructorSlot // AR6AbstractHUD destructor.
    }
}

// R6Game.dll @ 10013a89 : destroy m_aIOBombs while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5b0 // m_aIOBombs.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013a97 : destroy m_szMovementMode while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6a8 // m_szMovementMode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013aa6 : destroy m_szTeamState while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6b4 // m_szTeamState.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013ab5 : destroy m_szOtherTeamState while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind4(void)
{
    __asm {
        mov eax,ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor callback.
        push eax
        push 0x2
        push 0xc
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6c0 // m_szOtherTeamState.
        push ecx
        call R6GameAddresses::eh_vector_destructor_iterator // Callee removes the four iterator arguments.
        ret
    }
}

// R6Game.dll @ 10013acf : destroy m_aszOtherTeamName while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind5(void)
{
    __asm {
        mov eax,ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor callback.
        push eax
        push 0x2
        push 0xc
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6d8 // m_aszOtherTeamName.
        push ecx
        call R6GameAddresses::eh_vector_destructor_iterator // Callee removes the four iterator arguments.
        ret
    }
}

// R6Game.dll @ 10013ae9 : destroy m_szLastPlayerAPAction while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6f0 // m_szLastPlayerAPAction.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013af8 : destroy m_szPressGoCode while unwinding the HUD default constructor
__declspec(naked) void AR6HUD_ConstructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6fc // m_szPressGoCode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013b20 : destroy base while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractHUD_DestructorSlot // AR6AbstractHUD destructor.
    }
}

// R6Game.dll @ 10013b29 : destroy m_aIOBombs while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5b0 // m_aIOBombs.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013b37 : destroy m_szMovementMode while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6a8 // m_szMovementMode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013b46 : destroy m_szTeamState while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6b4 // m_szTeamState.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013b55 : destroy m_szLastPlayerAPAction while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6f0 // m_szLastPlayerAPAction.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013b64 : destroy m_szPressGoCode while unwinding the HUD copy constructor
__declspec(naked) void AR6HUD_CopyConstructUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x6fc // m_szPressGoCode.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10014160 : destroy the single-character panel's owned name if drawing unwinds
__declspec(naked) void AR6HUD_DrawSingleCharacterInfoUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141b0 : destroy the HUD canvas while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x1014]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 100141bc : destroy the weapon name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind15(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141c5 : destroy the weapon-name separator while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind16(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141ce : destroy the combined gadget name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind17(void)
{
    __asm {
        lea ecx,[ebp-0x64]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141d7 : destroy the Alpha key name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind20(void)
{
    __asm {
        lea ecx,[ebp-0x2c]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141e0 : destroy the Bravo key name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind21(void)
{
    __asm {
        lea ecx,[ebp-0x64]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141e9 : destroy the Charlie key name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind22(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141f2 : destroy the Zulu key name while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind23(void)
{
    __asm {
        lea ecx,[ebp-0x74]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100141fb : destroy the waypoint camera while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind24(void)
{
    __asm {
        lea ecx,[ebp-0x36c]
        jmp dword ptr ds:R6GameAddresses::Engine_FCameraSceneNode_DestructorSlot // FCameraSceneNode destructor.
    }
}

// R6Game.dll @ 10014207 : destroy the waypoint arrow batch while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind25(void)
{
    __asm {
        lea ecx,[ebp-0x10c]
        jmp dword ptr ds:R6GameAddresses::Engine_FLineBatcher_DestructorSlot // FLineBatcher destructor.
    }
}

// R6Game.dll @ 10014213 : destroy the waypoint distance text while unwinding
__declspec(naked) void AR6HUD_execDrawNativeHUDUnwind26(void)
{
    __asm {
        lea ecx,[ebp-0x80]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10014230 : destroy the radar canvas if the active drawing scope unwinds
__declspec(naked) void AR6HUD_DrawRadarUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0xd9c]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 10014250 : shrink the cached-pawn map after iterator unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x74]
        jmp R6GameAddresses::ShrinkHashMapIfSparse // ShrinkHashMapIfSparse.
    }
}

// R6Game.dll @ 10014258 : destroy the single-player marker batch while unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x184]
        jmp dword ptr ds:R6GameAddresses::Engine_FLineBatcher_DestructorSlot // FLineBatcher destructor.
    }
}

// R6Game.dll @ 10014264 : destroy the single-player label canvas while unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0xe90]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 10014270 : destroy the team-route batch while unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x144]
        jmp dword ptr ds:R6GameAddresses::Engine_FLineBatcher_DestructorSlot // FLineBatcher destructor.
    }
}

// R6Game.dll @ 1001427c : destroy the multiplayer marker batch while unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind5(void)
{
    __asm {
        lea ecx,[ebp-0x184]
        jmp dword ptr ds:R6GameAddresses::Engine_FLineBatcher_DestructorSlot // FLineBatcher destructor.
    }
}

// R6Game.dll @ 10014288 : destroy the multiplayer label canvas while unwinding
__declspec(naked) void AR6HUD_DrawInGameMapUnwind6(void)
{
    __asm {
        lea ecx,[ebp-0xe90]
        jmp dword ptr ds:R6GameAddresses::Engine_FCanvasUtil_DestructorSlot // FCanvasUtil destructor.
    }
}

// R6Game.dll @ 10014fc0 : initialize HUD class metadata and register its cleanup
void InitializeAR6HUDClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  UClass* parentClass = (UClass*)ImportedAR6AbstractHUDClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6HUDClassMetadataStorage, 0, 0x714, 0, parentClass, withinClass, FGuid(0, 0, 0, 0),
      L"R6HUD", GPackage, configName, 0x4084004, AR6HUD::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6HUDClassMetadata);
}

// R6Game.dll @ 10015190 : destroy HUD class metadata
void DestroyAR6HUDClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6HUDClassMetadataStorage);
}

// R6Game.dll @ 10013a76 : dispatch the HUD exception states selected by FuncInfo 0x1001aa18
__declspec(naked) void AR6HUDDestructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DestructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013b07 : dispatch the HUD exception states selected by FuncInfo 0x1001aa74
__declspec(naked) void AR6HUDConstructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_ConstructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013b73 : dispatch the HUD exception states selected by FuncInfo 0x1001aac0
__declspec(naked) void AR6HUDCopyExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_CopyConstructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10015050 : bind the exported HUD auto-class pointer to its metadata
void InitializeAR6HUDAutoClassPointer(void)
{
  autoclassAR6HUD = (UClass*)AR6HUDClassMetadataStorage; // Exported slot 0x10028db8.
}

// R6Game.dll @ 100065f0 : destroy one HUD or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6HUD::VectorDeletingDestructor(AR6HUD* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x714, elementCount,
            (_func_void_void_ptr*)AR6HUD::~AR6HUD);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6HUD::~AR6HUD(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x714);
    return this;
}

// R6Game.dll @ 100140f0 : dispatch HUD Destroy's exception states
__declspec(naked) void AR6HUD_DestroyExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DestroyExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014150 : dispatch HUD Spawned's exception states
__declspec(naked) void AR6HUD_SpawnedExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_SpawnedExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100140e0 : dispatch HudStep's exception states
__declspec(naked) void AR6HUD_HudStepExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_execHudStepExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014169 : dispatch DrawSingleCharacterInfo's exception states
__declspec(naked) void AR6HUD_DrawSingleCharacterInfoExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DrawSingleCharacterInfoExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014180 : dispatch DrawCharacterInfo's exception states
__declspec(naked) void AR6HUD_DrawCharacterInfoExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DrawCharacterInfoExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014190 : dispatch the other-team panel's exception states
__declspec(naked) void AR6HUD_DisplayOtherTeamInfoExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DisplayOtherTeamInfoExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 1001423c : dispatch DrawRadar's canvas and catch states
__declspec(naked) void AR6HUD_DrawRadarExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DrawRadarExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10014294 : dispatch DrawInGameMap's iterator, drawing and catch states
__declspec(naked) void AR6HUD_DrawInGameMapExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_DrawInGameMapExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 1001421c : dispatch native HUD rendering's resource and nested catch states
__declspec(naked) void AR6HUD_DrawNativeHUDExceptionHandler(void)
{
  __asm { mov eax, offset AR6HUD_execDrawNativeHUDExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10015060 : register AR6HUD::execDrawNativeHUD at native index 1605
void InitializeAR6HUDNativeDrawNativeHUD(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6HUDexecDrawNativeHUD;
    byte& nativeRegistrationResult = AR6HUDexecDrawNativeHUDRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1605, nativeExecPointerWord);
}

// R6Game.dll @ 10015080 : register AR6HUD::execHudStep at native index 1609
void InitializeAR6HUDNativeHudStep(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6HUDexecHudStep;
    byte& nativeRegistrationResult = AR6HUDexecHudStepRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1609, nativeExecPointerWord);
}
